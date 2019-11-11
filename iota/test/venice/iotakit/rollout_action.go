// {C} Copyright 2019 Pensando Systems Inc. All rights reserved.

package iotakit

import (
	"bytes"
	"context"
	"crypto/tls"
	"fmt"
	"io/ioutil"
	"mime/multipart"
	"net/http"
	"os"
	"time"

	"github.com/pensando/sw/api"
	"github.com/pensando/sw/api/generated/rollout"
	loginctx "github.com/pensando/sw/api/login/context"

	//iota "github.com/pensando/sw/iota/protos/gogen"
	"github.com/pensando/sw/venice/utils/log"
)

// PerformImageUpload triggers image upgrade
func (act *ActionCtx) PerformImageUpload() error {

	rolloutFile := fmt.Sprintf("%s/src/github.com/pensando/sw/upgrade-bundle/bundle.tar", os.Getenv("GOPATH"))

	fileBuf, err := ioutil.ReadFile(rolloutFile)
	if err != nil {
		log.Infof("Error (%+v) reading file /go/src/github.com/pensando/sw/upgrade-bundle/bundle.tar", err)
		return fmt.Errorf("Error (%+v) reading file /go/src/github.com/pensando/sw/upgrade-bundle/bundle.tar", err)
	}
	bkCtx, cancelFunc := context.WithTimeout(context.Background(), 10*time.Minute)
	defer cancelFunc()
	ctx, err := act.model.VeniceLoggedInCtx(bkCtx)
	if err != nil {
		return err
	}
	_, err = act.UploadBundle(ctx, "bundle.tar", fileBuf)
	if err != nil {
		log.Infof("Error (%+v) uploading bundle.", err)
		return err
	}
	return nil
}

// UploadBundle performs a rollout in the cluster
func (act *ActionCtx) UploadBundle(ctx context.Context, filename string, content []byte) (int, error) {

	body := &bytes.Buffer{}
	writer := multipart.NewWriter(body)
	part, err := writer.CreateFormFile("file", filename)
	if err != nil {
		return 0, fmt.Errorf("CreateFormFile failed %v", err)
	}
	written, err := part.Write(content)
	if err != nil {
		return 0, fmt.Errorf("writing form %v", err)
	}

	err = writer.Close()
	if err != nil {
		return 0, fmt.Errorf("closing writer %v", err)
	}
	uri := fmt.Sprintf("https://%s/objstore/v1/uploads/images/", act.model.GetVeniceURL()[0])
	req, err := http.NewRequest("POST", uri, body)
	if err != nil {
		return 0, fmt.Errorf("http.newRequest failed %v", err)
	}
	authzHeader, ok := loginctx.AuthzHeaderFromContext(ctx)
	if !ok {
		return 0, fmt.Errorf("no authorization header in context")
	}
	req.Header.Set("Authorization", authzHeader)
	req.Header.Set("Content-Type", writer.FormDataContentType())
	transport := &http.Transport{TLSClientConfig: &tls.Config{InsecureSkipVerify: true}}
	client := &http.Client{Transport: transport}
	resp, err := client.Do(req)
	if err != nil {
		return 0, fmt.Errorf("Sending req %v", err)
	}
	defer resp.Body.Close()
	if resp.StatusCode != http.StatusOK {
		body, _ := ioutil.ReadAll(resp.Body)
		log.Errorf("Did not get a success on upload [%v]", string(body))
		return 0, fmt.Errorf("failed to get upload [%v][%v]", resp.Status, string(body))
	}
	return written, nil

}
var names []string

// VerifyRolloutStatus verifies status of rollout in the iota cluster
func (act *ActionCtx) VerifyRolloutStatus(rolloutName string) error {
	var numRetries int
	bkCtx, cancelFunc := context.WithTimeout(context.Background(), 60*time.Minute)
	defer cancelFunc()
	ctx, err := act.model.VeniceLoggedInCtx(bkCtx)

	if err != nil {
		return err
	}

	restcls, err := act.model.VeniceRestClient()
	if err != nil {
		return err
	}

	for numRetries = 0; numRetries < 24; numRetries++ {
		obj := api.ObjectMeta{Name: rolloutName, Tenant: "default"}
		r1, err := restcls[0].RolloutV1().Rollout().Get(ctx, &obj)
		if err != nil || r1.Name != rolloutName {
			log.Errorf("ts:%s Rollout GET failed for [%s] err: %+v r1: %+v", time.Now().String(), rolloutName, err, r1)
			time.Sleep(time.Second)
			continue
		}
		log.Infof("ts:%s Rollout GET validated for [%s]", time.Now().String(), rolloutName)
		numRetries = 0
		break
	}

	if numRetries != 0 {
		return fmt.Errorf("Failed to create rollout object")
	}

	// Verify pre-install rollout Node status
	for numRetries = 0; numRetries < 60; numRetries++ {
		obj := api.ObjectMeta{Name: rolloutName, Tenant: "default"}
		r1, err := restcls[0].RolloutV1().Rollout().Get(ctx, &obj)
		if err != nil {
			log.Errorf("ts:%s Rollout GET failed for status check, err: %+v rollouts: %+v", time.Now().String(), err, r1)
			time.Sleep(time.Second * 5)
			continue
		}
		if r1.Spec.DSCsOnly {
			break
		}
		status := r1.Status.GetControllerNodesStatus()
		if len(status) == 0 {
			log.Errorf("ts:%s Pre-install in progress", time.Now().String())
			time.Sleep(time.Second * 5)
			continue
		}
		log.Infof("ts:%s Pre-install completed for : %d nodes", time.Now().String(), len(status))
		numRetries = 0
		break
	}
	if numRetries != 0 {
		return fmt.Errorf("rollout pre-check failed")
	}

	// Verify pre-install Node status
	for numRetries = 0; numRetries < 60; numRetries++ {
		obj := api.ObjectMeta{Name: rolloutName, Tenant: "default"}
		r1, err := restcls[0].RolloutV1().Rollout().Get(ctx, &obj)
		if err != nil {
			log.Errorf("ts:%s Rollout GET failed for status check, err: %+v rollouts: %+v", time.Now().String(), err, r1)
			time.Sleep(time.Second * 5)
			continue
		}
		var numNodes int
		if r1.Spec.DSCsOnly {
			break
		}
		status := r1.Status.GetControllerNodesStatus()
		if len(status) == 0 {
			log.Errorf("ts:%s Pre-install in progress", time.Now().String())
			time.Sleep(time.Second * 5)
			continue
		}

		for i := 0; i < len(status); i++ {
			log.Errorf("ts:%s Controller node status %+v", time.Now().String(), status[i])
			if status[i].Phase == rollout.RolloutPhase_PROGRESSING.String() {
				log.Errorf("ts:%s Controller node Pre-install Complete", time.Now().String())
				numNodes = len(act.model.VeniceNodes().nodes)
				break
			}
			if status[i].Phase == rollout.RolloutPhase_WAITING_FOR_TURN.String() {
				numNodes++
				continue
			}
		}

		if numNodes != len(act.model.VeniceNodes().nodes) {
			log.Errorf("ts:%s Pre-install completed for : %d nodes", time.Now().String(), numNodes)
			time.Sleep(time.Second * 5)
			continue
		}
		log.Infof("ts:%s Pre-install Status: Complete", time.Now().String())
		numRetries = 0
		break
	}
	if numRetries != 0 {
		return fmt.Errorf("rollout pre-check not completed for all nodes")
	}

	// Verify pre-install of Naples
outerLoop:
	for numRetries = 0; numRetries < 60; numRetries++ {
		obj := api.ObjectMeta{Name: rolloutName, Tenant: "default"}
		r1, err := restcls[0].RolloutV1().Rollout().Get(ctx, &obj)
		if err != nil {
			log.Errorf("ts:%s Rollout GET failed for status check, err: %+v rollouts: %+v", time.Now().String(), err, r1)
			time.Sleep(time.Second * 5)
			continue
		}
		status := r1.Status.GetDSCsStatus()
		log.Infof("ts:%s Precheck smartNIC status len %d: status:  %+v", time.Now().String(), len(status), status)
		var numNodes int
		if len(status) == 0 || r1.Status.OperationalState == rollout.RolloutStatus_SCHEDULED_FOR_RETRY.String(){
			log.Infof("ts:%s Precheck smartNIC in progress", time.Now().String())
			time.Sleep(time.Second * 5)
			continue
		}
		if r1.Status.OperationalState == rollout.RolloutStatus_PROGRESSING.String() ||
					r1.Status.OperationalState == rollout.RolloutStatus_FAILURE.String() ||
					r1.Status.OperationalState == rollout.RolloutStatus_SUCCESS.String() {
			log.Infof("ts:%s Overall Rollout status: %s", time.Now().String(), r1.Status.OperationalState)
	        numRetries = 0
		    break
	    }

		for i := 0; i < len(status); i++ {
			log.Errorf("ts:%s. Naples Pre Install %+v", time.Now().String(), status[i])
			if status[i].Phase == rollout.RolloutPhase_WAITING_FOR_TURN.String() {
				numNodes++
			}
		}

		if numNodes < len(act.model.Naples().nodes) {
			log.Errorf("ts:%s Pre-install completed for : %d naples", time.Now().String(), numNodes)
			time.Sleep(time.Second * 5)
			continue
		}
		log.Infof("ts:%s Naples Pre-install Status: Complete", time.Now().String())
		numRetries = 0
		break outerLoop
	}

	if numRetries != 0 {
		return fmt.Errorf("rollout pre-check failed")
	}

	// Verify Start Time of rollout object
	for numRetries = 0; numRetries < 20; numRetries++ {
		obj := api.ObjectMeta{Name: rolloutName, Tenant: "default"}
		r1, err := restcls[0].RolloutV1().Rollout().Get(ctx, &obj)
		if err != nil || r1.Name != rolloutName {
			log.Infof("ts:%s Rollout GET failed for [%s] err: %+v r1: %+v", time.Now().String(), rolloutName, err, r1)
			time.Sleep(time.Second * 5)
			continue
		}
		if r1.Status.StartTime == nil || r1.Spec.ScheduledStartTime.Seconds > r1.Status.StartTime.Seconds {
			log.Infof("ts:%s Waiting for pre-install to complete and to schedule rollout : %s status %+v", time.Now().String(), rolloutName, r1.Status)
			time.Sleep(time.Second * 5)
			continue
		}
		log.Infof("ts:%s Rollout successfully started at [%+v] for [%s]", time.Now().String(), time.Unix(r1.Status.StartTime.Seconds, 0), rolloutName)
		numRetries = 0
		break
	}
	if numRetries != 0 {
		return fmt.Errorf("rollout failed to trigger")
	}

	// Verify rollout Node status
	for numRetries = 0; numRetries < 120; numRetries++ {
		obj := api.ObjectMeta{Name: rolloutName, Tenant: "default"}
		r1, err := restcls[0].RolloutV1().Rollout().Get(ctx, &obj)
		if err != nil {
			log.Infof("ts:%s Rollout GET failed for status check, err: %+v rollouts: %+v", time.Now().String(), err, r1)
			time.Sleep(time.Second * 5)
			continue
		}
		if r1.Spec.DSCsOnly {
			break
		}

		status := r1.Status.GetControllerNodesStatus()
		var numNodes int
		if len(status) == 0 {
			log.Infof("ts:%s Rollout controller node status: not found", time.Now().String())
			time.Sleep(time.Second * 5)
			continue
		}

		for i := 0; i < len(status); i++ {
			if status[i].Phase == rollout.RolloutPhase_COMPLETE.String() {
				numNodes++
			}
		}
		if numNodes != len(status) {
			log.Infof("ts:%s Rollout completed for : %d nodes", time.Now().String(), numNodes)
			time.Sleep(time.Second * 5)
			continue
		}
		log.Infof("ts:%s Rollout Node Status: Complete", time.Now().String())
		numRetries = 0
		break
	}
	if numRetries != 0 {
		return fmt.Errorf("rollout controller node failed")
	}

	// Verify rollout service status
	for numRetries = 0; numRetries < 180; numRetries++ {
		obj := api.ObjectMeta{Name: rolloutName, Tenant: "default"}
		r1, err := restcls[0].RolloutV1().Rollout().Get(ctx, &obj)
		if err != nil {
			log.Infof("ts:%s Rollout LIST failed for status check, err: %+v rollouts: %+v", time.Now().String(), err, r1)
			time.Sleep(time.Second * 5)
			continue
		}
		if r1.Spec.DSCsOnly {
			break
		}
		status := r1.Status.GetControllerServicesStatus()
		if len(status) == 0 {
			log.Infof("ts:%s Rollout controller services status: Not Found", time.Now().String())
			time.Sleep(time.Second * 5)
			continue
		}
		if status[0].Phase != rollout.RolloutPhase_COMPLETE.String() {
			log.Infof("ts:%s Rollout controller services status: : %+v", time.Now().String(), status[0].Phase)
			time.Sleep(time.Second * 5)
			continue
		}
		numRetries = 0
		log.Infof("ts:%s Rollout Controller Services Status: Complete", time.Now().String())
		break
	}
	if numRetries != 0 {
		return fmt.Errorf("rollout services failed on some nodes")
	}

	// Verify rollout smartNIC status
	for numRetries = 0; numRetries < 180; numRetries++ {
		restcls, err := act.model.VeniceRestClient()
		if err != nil {
			log.Infof("ts:%s Failed to get restclient err %+v", time.Now().String(), err)
			time.Sleep(time.Second * 5)
			continue
		}
		obj := api.ObjectMeta{Name: rolloutName, Tenant: "default"}
		r1, err := restcls[0].RolloutV1().Rollout().Get(ctx, &obj)
		if err != nil {
			log.Infof("ts:%s Rollout LIST failed for status check, err: %+v rollouts: %+v", time.Now().String(), err, r1)
			time.Sleep(time.Second * 5)
			continue
		}
		status := r1.Status.GetDSCsStatus()
		log.Infof("ts:%s Rollout smartNIC status len %d: status:  %+v", time.Now().String(), len(status), status)
		var numNodes int
		if len(status) == 0 {
			log.Infof("ts:%s Rollout smartNIC status: not found", time.Now().String())
			time.Sleep(time.Second * 5)
			continue
		}

		for i := 0; i < len(status); i++ {
			log.Infof("ts:%s SmartNIC Rollout status %s", time.Now().String(), status[i].Phase)
			if status[i].Phase == rollout.RolloutPhase_COMPLETE.String() {
				numNodes++
			}
		}

		if r1.Status.OperationalState != rollout.RolloutStatus_PROGRESSING.String() {
			log.Infof("ts:%s Overall Rollout status: %s", time.Now().String(), r1.Status.OperationalState)
			numRetries = 0
			break
		}

		if numNodes != len(status) {
			log.Infof("ts:%s SmartNIC Rollout completed for : %d nodes", time.Now().String(), numNodes)
			time.Sleep(time.Second * 5)
			continue
		}
		log.Infof("ts:%s Rollout Smart NIC Status: %s", time.Now().String(), r1.Status.OperationalState)
		numRetries = 0
		break
	}
	if numRetries != 0 {
		return fmt.Errorf("rollout smartNIC node failed")
	}
	var opState string
	// Verify rollout in retry states status
	for numRetries = 0; numRetries < 60; numRetries++ {
		obj := api.ObjectMeta{Name: rolloutName, Tenant: "default"}
		r1, err := restcls[0].RolloutV1().Rollout().Get(ctx, &obj)
		if err != nil {
			log.Infof("ts:%s Rollout LIST failed for status check, err: %+v rollouts: %+v", time.Now().String(), err, r1)
			time.Sleep(time.Second * 5)
			continue
		}
		opState = r1.Status.OperationalState

		if opState == rollout.RolloutStatus_PROGRESSING.String() {
			log.Infof("ts:%s Overall Rollout status: %s", time.Now().String(), r1.Status.OperationalState)
			time.Sleep(time.Second * 5)
			continue
		}
		if opState == rollout.RolloutStatus_SCHEDULED_FOR_RETRY.String() {
			log.Infof("ts:%s Overall Rollout status: %s", time.Now().String(), r1.Status.OperationalState)
			break
		}
		if opState == rollout.RolloutStatus_FAILURE.String() || opState == rollout.RolloutStatus_SUSPENDED.String() {
			log.Infof("ts:%s Overall Rollout status: %s", time.Now().String(), r1.Status.OperationalState)
			break
		}
	}

	if opState == rollout.RolloutStatus_SCHEDULED_FOR_RETRY.String() {

		go func() {
			if err := act.model.AddNaplesNodes(names); err != nil {
				log.Errorf("Failed to add naples nodes %v error %v", names, err)
			}
		}()

		log.Infof("Rollout is scheduled for retry.. Going to precheck SmartNIC")
		time.Sleep(5*time.Minute)//wait for rollout to trigger retry
		goto outerLoop
	}
	// Verify rollout overall status
	for numRetries = 0; numRetries < 60; numRetries++ {
		obj := api.ObjectMeta{Name: rolloutName, Tenant: "default"}
		r1, err := restcls[0].RolloutV1().Rollout().Get(ctx, &obj)
		if err != nil {
			log.Infof("ts:%s Rollout LIST failed for status check, err: %+v rollouts: %+v", time.Now().String(), err, r1)
			time.Sleep(time.Second * 5)
			continue
		}
		opState := r1.Status.OperationalState

		if opState == rollout.RolloutStatus_PROGRESSING.String() || opState == rollout.RolloutStatus_SUSPEND_IN_PROGRESS.String() {
			log.Infof("ts:%s Overall Rollout status: %s", time.Now().String(), r1.Status.OperationalState)
			time.Sleep(time.Second * 5)
			continue
		}

		if opState == rollout.RolloutStatus_FAILURE.String() || opState == rollout.RolloutStatus_DEADLINE_EXCEEDED.String() {
			log.Infof("ts:%s Overall Rollout status: %s", time.Now().String(), r1.Status.OperationalState)
			return fmt.Errorf("rollout smartNIC node failed")
		}

		if opState == rollout.RolloutStatus_SUCCESS.String() || opState == rollout.RolloutStatus_SUSPENDED.String() {
			log.Infof("ts:%s Overall Rollout status: %s", time.Now().String(), r1.Status.OperationalState)
			break
		}

		log.Infof("ts:%s Overall Rollout Status: %s", time.Now().String(), opState)
		numRetries = 0
		break
	}

	// Verify delete on rollout object
	for numRetries = 0; numRetries < 25; numRetries++ {
		obj := api.ObjectMeta{Name: rolloutName, Tenant: "default"}
		r1, err := restcls[0].RolloutV1().Rollout().Get(ctx, &obj)
		if err != nil {
			log.Infof("ts:%s Rollout LIST failed during delete, err: %+v rollouts: %+v", time.Now().String(), err, r1)
			time.Sleep(time.Second * 5)
			continue
		}
		r1, err = restcls[0].RolloutV1().Rollout().RemoveRollout(ctx, r1)
		if err != nil || r1.Name != rolloutName {
			time.Sleep(time.Second)
			continue
		}
		log.Infof("ts:%s Rollout DELETE validated for [%s]", time.Now().String(), rolloutName)
		numRetries = 0
		break
	}
	if numRetries != 0 {
		return fmt.Errorf("rollout delete object failed")
	}

	// Verify GET for all rollout objects (LIST) returns empty
	for numRetries = 0; numRetries < 25; numRetries++ {
		ometa := api.ObjectMeta{Tenant: "default"}
		rollouts, err := restcls[0].RolloutV1().Rollout().List(ctx, &api.ListWatchOptions{ObjectMeta: ometa})
		if err != nil || len(rollouts) != 0 {
			log.Infof("ts:%s Rollout LIST has unexpected objects, err: %+v rollouts: %+v", time.Now().String(), err, rollouts)
			time.Sleep(time.Second)
			continue
		}
		numRetries = 0
		break
	}
	if numRetries != 0 {
		return fmt.Errorf("Error: rollout list returned objects")
	}
	return nil
}

// PerformRollout performs a rollout in the cluster
func (act *ActionCtx) PerformRollout(rollout *rollout.Rollout) error {
	bkCtx, cancelFunc := context.WithTimeout(context.Background(), 15*time.Minute)
	defer cancelFunc()
	ctx, err := act.model.VeniceLoggedInCtx(bkCtx)
	if err != nil {
		return err
	}

	restcls, err := act.model.VeniceRestClient()
	if err != nil {
		return err
	}
	//cleanup the existing rollout object with the same name
	//fetch the image and upload
	err = act.PerformImageUpload()
	if err != nil {
		log.Infof("Errored PerformImageUpload")
		return err
	}
	names = make([]string, 0)
	for _, obj := range act.model.Naples().nodes {
		names = append(names, obj.iotaNode.Name)
		//just add one naples to simulate intent based rollout
		break
	}

	/*if err := act.model.DeleteNaplesNodes(names); err != nil {
		log.Errorf("Failed to delete naples nodes %v", names)
		return err
	}*/
	//create the rollout object
	r1, err := restcls[0].RolloutV1().Rollout().CreateRollout(ctx, rollout)
	if err != nil || r1.Name != rollout.Name {
		return err
	}

	return nil
}
