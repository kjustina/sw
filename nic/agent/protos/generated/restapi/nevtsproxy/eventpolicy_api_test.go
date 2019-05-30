// Code generated by protoc-gen-grpc-pensando DO NOT EDIT.

/*
Package evtsmgrprotos is a auto generated package.
Input file: eventpolicy.proto
*/
package restapi_test

import (
	"fmt"
	"io/ioutil"
	"os"
	"reflect"
	"testing"
	"time"

	"github.com/pensando/sw/api"
	"github.com/pensando/sw/api/generated/monitoring"
	"github.com/pensando/sw/nic/agent/nevtsproxy/ctrlerif/restapi"
	evtsmgrprotos "github.com/pensando/sw/nic/agent/protos/evtprotos"
	"github.com/pensando/sw/venice/evtsproxy"
	"github.com/pensando/sw/venice/globals"
	"github.com/pensando/sw/venice/utils/emstore"
	"github.com/pensando/sw/venice/utils/events"
	"github.com/pensando/sw/venice/utils/events/policy"
	"github.com/pensando/sw/venice/utils/log"
	"github.com/pensando/sw/venice/utils/netutils"
	. "github.com/pensando/sw/venice/utils/testutils"
)

var (
	agentRestURL = "localhost:2337"
)

func setup(name string) (*evtsproxy.EventsProxy, *policy.Manager, string, string, log.Logger, error) {
	logger := log.GetNewLogger(log.GetDefaultConfig(name))
	proxyEventsStoreDir, err := ioutil.TempDir("", "")
	if err != nil {
		return nil, nil, "", "", nil, err
	}

	eps, err := evtsproxy.NewEventsProxy(name, globals.EvtsProxy, ":0",
		nil, 100*time.Second, time.Second, &events.StoreConfig{Dir: proxyEventsStoreDir}, logger)
	if err != nil {
		return nil, nil, "", "", nil, err
	}

	// create agent store
	storePath := fmt.Sprintf("/tmp/%s", name)
	agentStore, err := emstore.NewEmstore(emstore.MemStoreType, storePath)
	if err != nil {
		return nil, nil, "", "", nil, err
	}

	// start events policy manager
	policyMgr, err := policy.NewManager(eps, logger, policy.WithStore(agentStore))
	if err != nil {
		return nil, nil, "", "", nil, err
	}

	return eps, policyMgr, proxyEventsStoreDir, storePath, logger, err
}

func TestMain(m *testing.M) {
	name := "evtsproxy-api-test"

	// 1. setup
	eps, policyMgr, eventsProxyDir, agentStorePath, logger, err := setup(name)
	if err != nil {
		log.Fatalf("failed to setup test, err: %v", err)
	}

	restServer, err := restapi.NewRestServer(agentRestURL, policyMgr, logger)
	if err != nil {
		log.Fatalf("failed to setup test, err: %v", err)
	}

	// 2. run tests
	testCode := m.Run()

	// 3. teardown
	restServer.Stop()
	policyMgr.Stop()
	eps.Stop()
	os.RemoveAll(eventsProxyDir)
	os.Remove(agentStorePath)

	os.Exit(testCode)
}

// TestEventPolicyList tests LIST endpoint
func TestEventPolicyList(t *testing.T) {
	t.Parallel()
	var eventpolicyList []*evtsmgrprotos.EventPolicy
	err := netutils.HTTPGet("http://"+agentRestURL+"/api/eventpolicies/", &eventpolicyList)
	AssertOk(t, err, "error getting event policies from the REST Server")
}

// TestEventPolicyPost tests POST and GET endpoints
func TestEventPolicyPost(t *testing.T) {
	var resp restapi.Response
	var eventpolicyGet evtsmgrprotos.EventPolicy
	policy1 := &evtsmgrprotos.EventPolicy{
		TypeMeta: api.TypeMeta{Kind: "EventPolicy"},
		ObjectMeta: api.ObjectMeta{
			Tenant:    "default",
			Namespace: "default",
			Name:      "testPostEventPolicy",
		},
		Spec: monitoring.EventPolicySpec{
			Format: monitoring.MonitoringExportFormat_name[int32(monitoring.MonitoringExportFormat_SYSLOG_BSD)],
			Targets: []*monitoring.ExportConfig{
				{
					Destination: "10.1.1.0",
					Transport:   "udp/2055",
				},
				{
					Destination: "10.1.1.0",
					Transport:   "udp/2056",
				},
			},
		},
	}

	err := netutils.HTTPPost("http://"+agentRestURL+"/api/eventpolicies/", policy1, &resp)
	AssertOk(t, err, "error posting event policy to REST Server, err: %v", err)
	getErr := netutils.HTTPGet("http://"+agentRestURL+"/api/eventpolicies/default/default/"+"testPostEventPolicy/", &eventpolicyGet)
	AssertOk(t, getErr, "error getting event policies from the REST Server, err: %v", err)
	defer netutils.HTTPDelete("http://"+agentRestURL+"/api/eventpolicies/default/default/"+"testPostEventPolicy", policy1, &resp)
}

// TestEventPolicyDelete tests DELETE endpoint
func TestEventPolicyDelete(t *testing.T) {
	var resp restapi.Response
	policy1 := &evtsmgrprotos.EventPolicy{
		TypeMeta: api.TypeMeta{Kind: "EventPolicy"},
		ObjectMeta: api.ObjectMeta{
			Tenant:    "default",
			Namespace: "default",
			Name:      "testDeleteEventPolicy",
		},
		Spec: monitoring.EventPolicySpec{
			Format: monitoring.MonitoringExportFormat_name[int32(monitoring.MonitoringExportFormat_SYSLOG_BSD)],
			Targets: []*monitoring.ExportConfig{
				{
					Destination: "10.1.1.0",
					Transport:   "udp/2055",
				},
				{
					Destination: "10.1.1.0",
					Transport:   "udp/2056",
				},
			},
		},
	}

	deleteMeta := evtsmgrprotos.EventPolicy{
		TypeMeta: api.TypeMeta{Kind: "EventPolicy"},
		ObjectMeta: api.ObjectMeta{
			Tenant:    "default",
			Namespace: "default",
			Name:      "testDeleteEventPolicy",
		},
	}
	err := netutils.HTTPPost("http://"+agentRestURL+"/api/eventpolicies/", policy1, &resp)
	AssertOk(t, err, "error posting event policy to REST Server, err: %v", err)
	delErr := netutils.HTTPDelete("http://"+agentRestURL+"/api/eventpolicies/default/default/"+"testDeleteEventPolicy", &deleteMeta, &resp)
	AssertOk(t, delErr, "error deleting event policies from the REST Server, err: %v", err)
}

// TestEventPolicyPut tests PUT endpoint
func TestEventPolicyPut(t *testing.T) {
	var resp restapi.Response
	var policyFromDb evtsmgrprotos.EventPolicy
	policy1 := &evtsmgrprotos.EventPolicy{
		TypeMeta: api.TypeMeta{Kind: "EventPolicy"},
		ObjectMeta: api.ObjectMeta{
			Tenant:    "default",
			Namespace: "default",
			Name:      "testPutEventPolicy",
		},
		Spec: monitoring.EventPolicySpec{
			Format: monitoring.MonitoringExportFormat_name[int32(monitoring.MonitoringExportFormat_SYSLOG_BSD)],
			Targets: []*monitoring.ExportConfig{
				{
					Destination: "10.1.1.0",
					Transport:   "udp/2055",
				},
				{
					Destination: "10.1.1.0",
					Transport:   "udp/2056",
				},
			},
		},
	}

	err := netutils.HTTPPost("http://"+agentRestURL+"/api/eventpolicies/", policy1, &resp)
	AssertOk(t, err, "error posting event policy to REST Server, err: %v", err)
	getErr := netutils.HTTPGet("http://"+agentRestURL+"/api/eventpolicies/default/default/"+"testPutEventPolicy", &policyFromDb)
	AssertOk(t, getErr, "error getting event policies from the REST Server, err: %v", err)
	Assert(t, reflect.DeepEqual(policy1.GetSpec(), policyFromDb.GetSpec()), "spec mismatched, expected: %v, got: %v", policy1.GetSpec(), policyFromDb.GetSpec())

	// update the policy
	policy1 = &policyFromDb
	policy1.Spec.Targets[0].Transport = "udp/2057"
	err = netutils.HTTPPut("http://"+agentRestURL+"/api/eventpolicies/default/default/"+"testPutEventPolicy", policy1, &resp)
	AssertOk(t, err, "error update event policy to REST Server, err: %v", err)

	getErr = netutils.HTTPGet("http://"+agentRestURL+"/api/eventpolicies/default/default/"+"testPutEventPolicy", &policyFromDb)
	AssertOk(t, getErr, "error getting event policies from the REST Server, err: %v", err)
	Assert(t, reflect.DeepEqual(policy1.GetSpec(), policyFromDb.GetSpec()), "spec mismatched, expected: %v, got: %v", policy1.GetSpec(), policyFromDb.GetSpec())
	defer netutils.HTTPDelete("http://"+agentRestURL+"/api/eventpolicies/default/default/"+"testPutEventPolicy", policy1, &resp)
}
