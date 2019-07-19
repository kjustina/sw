// Code generated by protoc-gen-grpc-pensando DO NOT EDIT.

/*
Package nimbus is a auto generated package.
Input file: security.proto
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

type SecurityGroupReactor interface {
	CreateSecurityGroup(securitygroupObj *netproto.SecurityGroup) error     // creates an SecurityGroup
	FindSecurityGroup(meta api.ObjectMeta) (*netproto.SecurityGroup, error) // finds an SecurityGroup
	ListSecurityGroup() []*netproto.SecurityGroup                           // lists all SecurityGroups
	UpdateSecurityGroup(securitygroupObj *netproto.SecurityGroup) error     // updates an SecurityGroup
	DeleteSecurityGroup(securitygroupObj, ns, name string) error            // deletes an SecurityGroup
}

// WatchSecurityGroups runs SecurityGroup watcher loop
func (client *NimbusClient) WatchSecurityGroups(ctx context.Context, reactor SecurityGroupReactor) {
	// setup wait group
	client.waitGrp.Add(1)
	defer client.waitGrp.Done()
	client.debugStats.AddInt("ActiveSecurityGroupWatch", 1)

	// make sure rpc client is good
	if client.rpcClient == nil || client.rpcClient.ClientConn == nil || client.rpcClient.ClientConn.GetState() != connectivity.Ready {
		log.Errorf("RPC client is disconnected. Exiting watch")
		return
	}

	// start the watch
	securitygroupRPCClient := netproto.NewSecurityGroupApiClient(client.rpcClient.ClientConn)
	stream, err := securitygroupRPCClient.WatchSecurityGroups(ctx, &api.ObjectMeta{})
	if err != nil {
		log.Errorf("Error watching SecurityGroup. Err: %v", err)
		return
	}

	// start oper update stream
	ostream, err := securitygroupRPCClient.SecurityGroupOperUpdate(ctx)
	if err != nil {
		log.Errorf("Error starting SecurityGroup oper updates. Err: %v", err)
		return
	}

	// get a list of objects
	objList, err := securitygroupRPCClient.ListSecurityGroups(ctx, &api.ObjectMeta{})
	if err != nil {
		log.Errorf("Error getting SecurityGroup list. Err: %v", err)
		return
	}

	// perform a diff of the states
	client.diffSecurityGroups(objList, reactor, ostream)

	// start grpc stream recv
	recvCh := make(chan *netproto.SecurityGroupEvent, evChanLength)
	go client.watchSecurityGroupRecvLoop(stream, recvCh)

	// loop till the end
	for {
		select {
		case evt, ok := <-recvCh:
			if !ok {
				log.Warnf("SecurityGroup Watch channel closed. Exisint SecurityGroupWatch")
				return
			}
			client.debugStats.AddInt("SecurityGroupWatchEvents", 1)

			log.Infof("Ctrlerif: agent %s got SecurityGroup watch event: Type: {%+v} SecurityGroup:{%+v}", client.clientName, evt.EventType, evt.SecurityGroup.ObjectMeta)

			client.lockObject(evt.SecurityGroup.GetObjectKind(), evt.SecurityGroup.ObjectMeta)
			go client.processSecurityGroupEvent(*evt, reactor, ostream)
			//Give it some time to increment waitgrp
			time.Sleep(100 * time.Millisecond)
		// periodic resync
		case <-time.After(resyncInterval):
			// get a list of objects
			objList, err := securitygroupRPCClient.ListSecurityGroups(ctx, &api.ObjectMeta{})
			if err != nil {
				log.Errorf("Error getting SecurityGroup list. Err: %v", err)
				return
			}
			client.debugStats.AddInt("SecurityGroupWatchResyncs", 1)

			// perform a diff of the states
			client.diffSecurityGroups(objList, reactor, ostream)
		}
	}
}

// watchSecurityGroupRecvLoop receives from stream and write it to a channel
func (client *NimbusClient) watchSecurityGroupRecvLoop(stream netproto.SecurityGroupApi_WatchSecurityGroupsClient, recvch chan<- *netproto.SecurityGroupEvent) {
	defer close(recvch)
	client.waitGrp.Add(1)
	defer client.waitGrp.Done()

	// loop till the end
	for {
		// receive from stream
		evt, err := stream.Recv()
		if err != nil {
			log.Errorf("Error receiving from watch channel. Exiting SecurityGroup watch. Err: %v", err)
			return
		}

		recvch <- evt
	}
}

// diffSecurityGroup diffs local state with controller state
// FIXME: this is not handling deletes today
func (client *NimbusClient) diffSecurityGroups(objList *netproto.SecurityGroupList, reactor SecurityGroupReactor, ostream netproto.SecurityGroupApi_SecurityGroupOperUpdateClient) {
	// build a map of objects
	objmap := make(map[string]*netproto.SecurityGroup)
	for _, obj := range objList.SecurityGroups {
		key := obj.ObjectMeta.GetKey()
		objmap[key] = obj
	}

	// see if we need to delete any locally found object
	localObjs := reactor.ListSecurityGroup()
	for _, lobj := range localObjs {
		ctby, ok := lobj.ObjectMeta.Labels["CreatedBy"]
		if ok && ctby == "Venice" {
			key := lobj.ObjectMeta.GetKey()
			if _, ok := objmap[key]; !ok {
				evt := netproto.SecurityGroupEvent{
					EventType:     api.EventType_DeleteEvent,
					SecurityGroup: *lobj,
				}
				log.Infof("diffSecurityGroups(): Deleting object %+v", lobj.ObjectMeta)
				client.lockObject(evt.SecurityGroup.GetObjectKind(), evt.SecurityGroup.ObjectMeta)
				client.processSecurityGroupEvent(evt, reactor, ostream)
			}
		} else {
			log.Infof("Not deleting non-venice object %+v", lobj.ObjectMeta)
		}
	}

	// add/update all new objects
	for _, obj := range objList.SecurityGroups {
		evt := netproto.SecurityGroupEvent{
			EventType:     api.EventType_CreateEvent,
			SecurityGroup: *obj,
		}
		client.lockObject(evt.SecurityGroup.GetObjectKind(), evt.SecurityGroup.ObjectMeta)
		client.processSecurityGroupEvent(evt, reactor, ostream)
	}
}

// processSecurityGroupEvent handles SecurityGroup event
func (client *NimbusClient) processSecurityGroupEvent(evt netproto.SecurityGroupEvent, reactor SecurityGroupReactor, ostream netproto.SecurityGroupApi_SecurityGroupOperUpdateClient) {
	var err error
	client.waitGrp.Add(1)
	defer client.waitGrp.Done()

	// add venice label to the object
	evt.SecurityGroup.ObjectMeta.Labels = make(map[string]string)
	evt.SecurityGroup.ObjectMeta.Labels["CreatedBy"] = "Venice"

	// unlock the object once we are done
	defer client.unlockObject(evt.SecurityGroup.GetObjectKind(), evt.SecurityGroup.ObjectMeta)

	// retry till successful
	for iter := 0; iter < maxOpretry; iter++ {
		switch evt.EventType {
		case api.EventType_CreateEvent:
			fallthrough
		case api.EventType_UpdateEvent:
			_, err = reactor.FindSecurityGroup(evt.SecurityGroup.ObjectMeta)
			if err != nil {
				// create the SecurityGroup
				err = reactor.CreateSecurityGroup(&evt.SecurityGroup)
				if err != nil {
					log.Errorf("Error creating the SecurityGroup {%+v}. Err: %v", evt.SecurityGroup.ObjectMeta, err)
					client.debugStats.AddInt("CreateSecurityGroupError", 1)
				} else {
					client.debugStats.AddInt("CreateSecurityGroup", 1)
				}
			} else {
				// update the SecurityGroup
				err = reactor.UpdateSecurityGroup(&evt.SecurityGroup)
				if err != nil {
					log.Errorf("Error updating the SecurityGroup {%+v}. Err: %v", evt.SecurityGroup, err)
					client.debugStats.AddInt("UpdateSecurityGroupError", 1)
				} else {
					client.debugStats.AddInt("UpdateSecurityGroup", 1)
				}
			}

		case api.EventType_DeleteEvent:
			// delete the object
			err = reactor.DeleteSecurityGroup(evt.SecurityGroup.Tenant, evt.SecurityGroup.Namespace, evt.SecurityGroup.Name)
			if err == state.ErrObjectNotFound { // give idempotency to caller
				log.Debugf("SecurityGroup {%+v} not found", evt.SecurityGroup.ObjectMeta)
				err = nil
			}
			if err != nil {
				log.Errorf("Error deleting the SecurityGroup {%+v}. Err: %v", evt.SecurityGroup.ObjectMeta, err)
				client.debugStats.AddInt("DeleteSecurityGroupError", 1)
			} else {
				client.debugStats.AddInt("DeleteSecurityGroup", 1)
			}
		}

		// send oper status and return if there is no error
		if err == nil {
			robj := netproto.SecurityGroupEvent{
				EventType: evt.EventType,
				SecurityGroup: netproto.SecurityGroup{
					TypeMeta:   evt.SecurityGroup.TypeMeta,
					ObjectMeta: evt.SecurityGroup.ObjectMeta,
					Status:     evt.SecurityGroup.Status,
				},
			}

			// send oper status
			err := ostream.Send(&robj)
			if err != nil {
				log.Errorf("failed to send SecurityGroup oper Status, %s", err)
				client.debugStats.AddInt("SecurityGroupOperSendError", 1)
			} else {
				client.debugStats.AddInt("SecurityGroupOperSent", 1)
			}

			return
		}

		// else, retry after some time, with backoff
		time.Sleep(time.Second * time.Duration(2*iter))
	}
}
