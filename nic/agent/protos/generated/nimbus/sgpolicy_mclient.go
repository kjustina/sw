// Code generated by protoc-gen-grpc-pensando DO NOT EDIT.

/*
Package nimbus is a auto generated package.
Input file: sgpolicy.proto
*/

package nimbus

import (
	"context"
	"time"

	"github.com/pensando/sw/api"
	"github.com/pensando/sw/nic/agent/netagent/state"
	"github.com/pensando/sw/nic/agent/protos/netproto"
	"github.com/pensando/sw/venice/utils/log"
	"google.golang.org/grpc/connectivity"
)

type SGPolicyReactor interface {
	CreateSGPolicy(sgpolicyObj *netproto.SGPolicy) error          // creates an SGPolicy
	FindSGPolicy(meta api.ObjectMeta) (*netproto.SGPolicy, error) // finds an SGPolicy
	ListSGPolicy() []*netproto.SGPolicy                           // lists all SGPolicys
	UpdateSGPolicy(sgpolicyObj *netproto.SGPolicy) error          // updates an SGPolicy
	DeleteSGPolicy(sgpolicyObj, ns, name string) error            // deletes an SGPolicy
}

// WatchSGPolicys runs SGPolicy watcher loop
func (client *NimbusClient) WatchSGPolicys(ctx context.Context, reactor SGPolicyReactor) {
	// setup wait group
	client.waitGrp.Add(1)
	defer client.waitGrp.Done()
	client.debugStats.AddInt("ActiveSGPolicyWatch", 1)

	// make sure rpc client is good
	if client.rpcClient == nil || client.rpcClient.ClientConn == nil || client.rpcClient.ClientConn.GetState() != connectivity.Ready {
		log.Errorf("RPC client is disconnected. Exiting watch")
		return
	}

	// start the watch
	sgpolicyRPCClient := netproto.NewSGPolicyApiClient(client.rpcClient.ClientConn)
	stream, err := sgpolicyRPCClient.WatchSGPolicys(ctx, &api.ObjectMeta{})
	if err != nil {
		log.Errorf("Error watching SGPolicy. Err: %v", err)
		return
	}

	// start oper update stream
	ostream, err := sgpolicyRPCClient.SGPolicyOperUpdate(ctx)
	if err != nil {
		log.Errorf("Error starting SGPolicy oper updates. Err: %v", err)
		return
	}

	// get a list of objects
	objList, err := sgpolicyRPCClient.ListSGPolicys(ctx, &api.ObjectMeta{})
	if err != nil {
		log.Errorf("Error getting SGPolicy list. Err: %v", err)
		return
	}

	// perform a diff of the states
	client.diffSGPolicys(objList, reactor, ostream)

	// start grpc stream recv
	recvCh := make(chan *netproto.SGPolicyEvent, evChanLength)
	go client.watchSGPolicyRecvLoop(stream, recvCh)

	// loop till the end
	for {
		select {
		case evt, ok := <-recvCh:
			if !ok {
				log.Warnf("SGPolicy Watch channel closed. Exisint SGPolicyWatch")
				return
			}
			client.debugStats.AddInt("SGPolicyWatchEvents", 1)

			log.Infof("Ctrlerif: agent %s got SGPolicy watch event: Type: {%+v} SGPolicy:{%+v}", client.clientName, evt.EventType, evt.SGPolicy.ObjectMeta)

			client.lockObject(evt.SGPolicy.GetObjectKind(), evt.SGPolicy.ObjectMeta)
			go client.processSGPolicyEvent(*evt, reactor, ostream)
			//Give it some time to increment waitgrp
			time.Sleep(100 * time.Millisecond)
		// periodic resync
		case <-time.After(resyncInterval):
			// get a list of objects
			objList, err := sgpolicyRPCClient.ListSGPolicys(ctx, &api.ObjectMeta{})
			if err != nil {
				log.Errorf("Error getting SGPolicy list. Err: %v", err)
				return
			}
			client.debugStats.AddInt("SGPolicyWatchResyncs", 1)

			// perform a diff of the states
			client.diffSGPolicys(objList, reactor, ostream)
		}
	}
}

// watchSGPolicyRecvLoop receives from stream and write it to a channel
func (client *NimbusClient) watchSGPolicyRecvLoop(stream netproto.SGPolicyApi_WatchSGPolicysClient, recvch chan<- *netproto.SGPolicyEvent) {
	defer close(recvch)
	client.waitGrp.Add(1)
	defer client.waitGrp.Done()

	// loop till the end
	for {
		// receive from stream
		evt, err := stream.Recv()
		if err != nil {
			log.Errorf("Error receiving from watch channel. Exiting SGPolicy watch. Err: %v", err)
			return
		}

		recvch <- evt
	}
}

// diffSGPolicy diffs local state with controller state
// FIXME: this is not handling deletes today
func (client *NimbusClient) diffSGPolicys(objList *netproto.SGPolicyList, reactor SGPolicyReactor, ostream netproto.SGPolicyApi_SGPolicyOperUpdateClient) {
	// build a map of objects
	objmap := make(map[string]*netproto.SGPolicy)
	for _, obj := range objList.SGPolicys {
		key := obj.ObjectMeta.GetKey()
		objmap[key] = obj
	}

	// see if we need to delete any locally found object
	localObjs := reactor.ListSGPolicy()
	for _, lobj := range localObjs {
		ctby, ok := lobj.ObjectMeta.Labels["CreatedBy"]
		if ok && ctby == "Venice" {
			key := lobj.ObjectMeta.GetKey()
			if _, ok := objmap[key]; !ok {
				evt := netproto.SGPolicyEvent{
					EventType: api.EventType_DeleteEvent,
					SGPolicy:  *lobj,
				}
				log.Infof("diffSGPolicys(): Deleting object %+v", lobj.ObjectMeta)
				client.lockObject(evt.SGPolicy.GetObjectKind(), evt.SGPolicy.ObjectMeta)
				client.processSGPolicyEvent(evt, reactor, ostream)
			}
		} else {
			log.Infof("Not deleting non-venice object %+v", lobj.ObjectMeta)
		}
	}

	// add/update all new objects
	for _, obj := range objList.SGPolicys {
		evt := netproto.SGPolicyEvent{
			EventType: api.EventType_CreateEvent,
			SGPolicy:  *obj,
		}
		client.lockObject(evt.SGPolicy.GetObjectKind(), evt.SGPolicy.ObjectMeta)
		client.processSGPolicyEvent(evt, reactor, ostream)
	}
}

// processSGPolicyEvent handles SGPolicy event
func (client *NimbusClient) processSGPolicyEvent(evt netproto.SGPolicyEvent, reactor SGPolicyReactor, ostream netproto.SGPolicyApi_SGPolicyOperUpdateClient) {
	var err error
	client.waitGrp.Add(1)
	defer client.waitGrp.Done()

	// add venice label to the object
	evt.SGPolicy.ObjectMeta.Labels = make(map[string]string)
	evt.SGPolicy.ObjectMeta.Labels["CreatedBy"] = "Venice"

	// unlock the object once we are done
	defer client.unlockObject(evt.SGPolicy.GetObjectKind(), evt.SGPolicy.ObjectMeta)

	// retry till successful
	for iter := 0; iter < maxOpretry; iter++ {
		switch evt.EventType {
		case api.EventType_CreateEvent:
			fallthrough
		case api.EventType_UpdateEvent:
			_, err = reactor.FindSGPolicy(evt.SGPolicy.ObjectMeta)
			if err != nil {
				// create the SGPolicy
				err = reactor.CreateSGPolicy(&evt.SGPolicy)
				if err != nil {
					log.Errorf("Error creating the SGPolicy {%+v}. Err: %v", evt.SGPolicy.ObjectMeta, err)
					client.debugStats.AddInt("CreateSGPolicyError", 1)
				} else {
					client.debugStats.AddInt("CreateSGPolicy", 1)
				}
			} else {
				// update the SGPolicy
				err = reactor.UpdateSGPolicy(&evt.SGPolicy)
				if err != nil {
					log.Errorf("Error updating the SGPolicy {%+v}. Err: %v", evt.SGPolicy, err)
					client.debugStats.AddInt("UpdateSGPolicyError", 1)
				} else {
					client.debugStats.AddInt("UpdateSGPolicy", 1)
				}
			}

		case api.EventType_DeleteEvent:
			// delete the object
			err = reactor.DeleteSGPolicy(evt.SGPolicy.Tenant, evt.SGPolicy.Namespace, evt.SGPolicy.Name)
			if err == state.ErrObjectNotFound { // give idempotency to caller
				log.Debugf("SGPolicy {%+v} not found", evt.SGPolicy.ObjectMeta)
				err = nil
			}
			if err != nil {
				log.Errorf("Error deleting the SGPolicy {%+v}. Err: %v", evt.SGPolicy.ObjectMeta, err)
				client.debugStats.AddInt("DeleteSGPolicyError", 1)
			} else {
				client.debugStats.AddInt("DeleteSGPolicy", 1)
			}
		}

		// send oper status and return if there is no error
		if err == nil {
			robj := netproto.SGPolicyEvent{
				EventType: evt.EventType,
				SGPolicy: netproto.SGPolicy{
					TypeMeta:   evt.SGPolicy.TypeMeta,
					ObjectMeta: evt.SGPolicy.ObjectMeta,
					Status:     evt.SGPolicy.Status,
				},
			}

			// send oper status
			err := ostream.Send(&robj)
			if err != nil {
				log.Errorf("failed to send SGPolicy oper Status, %s", err)
				client.debugStats.AddInt("SGPolicyOperSendError", 1)
			} else {
				client.debugStats.AddInt("SGPolicyOperSent", 1)
			}

			return
		}

		// else, retry after some time, with backoff
		time.Sleep(time.Second * time.Duration(2*iter))
	}
}
