// Code generated by protoc-gen-grpc-pensando DO NOT EDIT.

/*
Package nimbus is a auto generated package.
Input file: namespace.proto
*/

package nimbus

import (
	"context"
	"sync"
	"time"

	"github.com/gogo/protobuf/types"
	"github.com/pensando/sw/api"
	"github.com/pensando/sw/nic/agent/netagent/state"
	"github.com/pensando/sw/nic/agent/protos/netproto"
	"github.com/pensando/sw/venice/utils/log"
	"google.golang.org/grpc/codes"
	"google.golang.org/grpc/connectivity"
	"google.golang.org/grpc/status"
)

type NamespaceReactor interface {
	CreateNamespace(namespaceObj *netproto.Namespace) error         // creates an Namespace
	FindNamespace(meta api.ObjectMeta) (*netproto.Namespace, error) // finds an Namespace
	ListNamespace() []*netproto.Namespace                           // lists all Namespaces
	UpdateNamespace(namespaceObj *netproto.Namespace) error         // updates an Namespace
	DeleteNamespace(namespaceObj, ns, name string) error            // deletes an Namespace
	GetWatchOptions(cts context.Context, kind string) api.ObjectMeta
}
type NamespaceOStream struct {
	sync.Mutex
	stream netproto.NamespaceApi_NamespaceOperUpdateClient
}

// WatchNamespaces runs Namespace watcher loop
func (client *NimbusClient) WatchNamespaces(ctx context.Context, reactor NamespaceReactor) {
	// setup wait group
	client.waitGrp.Add(1)
	defer client.waitGrp.Done()
	client.debugStats.AddInt("ActiveNamespaceWatch", 1)

	// make sure rpc client is good
	if client.rpcClient == nil || client.rpcClient.ClientConn == nil || client.rpcClient.ClientConn.GetState() != connectivity.Ready {
		log.Errorf("RPC client is disconnected. Exiting watch")
		return
	}

	// start the watch
	ometa := reactor.GetWatchOptions(ctx, "Namespace")
	namespaceRPCClient := netproto.NewNamespaceApiClient(client.rpcClient.ClientConn)
	stream, err := namespaceRPCClient.WatchNamespaces(ctx, &ometa)
	if err != nil {
		log.Errorf("Error watching Namespace. Err: %v", err)
		return
	}

	// start oper update stream
	opStream, err := namespaceRPCClient.NamespaceOperUpdate(ctx)
	if err != nil {
		log.Errorf("Error starting Namespace oper updates. Err: %v", err)
		return
	}

	ostream := &NamespaceOStream{stream: opStream}

	// get a list of objects
	objList, err := namespaceRPCClient.ListNamespaces(ctx, &ometa)
	if err != nil {
		st, ok := status.FromError(err)
		if !ok || st.Code() == codes.Unavailable {
			log.Errorf("Error getting Namespace list. Err: %v", err)
			return
		}
	} else {
		// perform a diff of the states
		client.diffNamespaces(objList, reactor, ostream)
	}

	// start grpc stream recv
	recvCh := make(chan *netproto.NamespaceEvent, evChanLength)
	go client.watchNamespaceRecvLoop(stream, recvCh)

	// loop till the end
	for {
		evtWork := func(evt *netproto.NamespaceEvent) {
			client.debugStats.AddInt("NamespaceWatchEvents", 1)
			log.Infof("Ctrlerif: agent %s got Namespace watch event: Type: {%+v} Namespace:{%+v}", client.clientName, evt.EventType, evt.Namespace.ObjectMeta)
			client.lockObject(evt.Namespace.GetObjectKind(), evt.Namespace.ObjectMeta)
			go client.processNamespaceEvent(*evt, reactor, ostream)
			//Give it some time to increment waitgrp
			time.Sleep(100 * time.Microsecond)
		}
		//Give priority to evnt work.
		select {
		case evt, ok := <-recvCh:
			if !ok {
				log.Warnf("Namespace Watch channel closed. Exisint NamespaceWatch")
				return
			}
			evtWork(evt)
		// periodic resync (Disabling as we have aggregate watch support)
		case <-time.After(resyncInterval):
			//Give priority to evt work
			//Wait for batch interval for inflight work
			time.Sleep(5 * DefaultWatchHoldInterval)
			select {
			case evt, ok := <-recvCh:
				if !ok {
					log.Warnf("Namespace Watch channel closed. Exisint NamespaceWatch")
					return
				}
				evtWork(evt)
				continue
			default:
			}
			// get a list of objects
			objList, err := namespaceRPCClient.ListNamespaces(ctx, &ometa)
			if err != nil {
				st, ok := status.FromError(err)
				if !ok || st.Code() == codes.Unavailable {
					log.Errorf("Error getting Namespace list. Err: %v", err)
					return
				}
			} else {
				client.debugStats.AddInt("NamespaceWatchResyncs", 1)
				// perform a diff of the states
				client.diffNamespaces(objList, reactor, ostream)
			}
		}
	}
}

// watchNamespaceRecvLoop receives from stream and write it to a channel
func (client *NimbusClient) watchNamespaceRecvLoop(stream netproto.NamespaceApi_WatchNamespacesClient, recvch chan<- *netproto.NamespaceEvent) {
	defer close(recvch)
	client.waitGrp.Add(1)
	defer client.waitGrp.Done()

	// loop till the end
	for {
		// receive from stream
		objList, err := stream.Recv()
		if err != nil {
			log.Errorf("Error receiving from watch channel. Exiting Namespace watch. Err: %v", err)
			return
		}
		for _, evt := range objList.NamespaceEvents {
			recvch <- evt
		}
	}
}

// diffNamespace diffs local state with controller state
// FIXME: this is not handling deletes today
func (client *NimbusClient) diffNamespaces(objList *netproto.NamespaceList, reactor NamespaceReactor, ostream *NamespaceOStream) {
	// build a map of objects
	objmap := make(map[string]*netproto.Namespace)
	for _, obj := range objList.Namespaces {
		key := obj.ObjectMeta.GetKey()
		objmap[key] = obj
	}

	// see if we need to delete any locally found object
	localObjs := reactor.ListNamespace()
	for _, lobj := range localObjs {
		ctby, ok := lobj.ObjectMeta.Labels["CreatedBy"]
		if ok && ctby == "Venice" {
			key := lobj.ObjectMeta.GetKey()
			if _, ok := objmap[key]; !ok {
				evt := netproto.NamespaceEvent{
					EventType: api.EventType_DeleteEvent,
					Namespace: *lobj,
				}
				log.Infof("diffNamespaces(): Deleting object %+v", lobj.ObjectMeta)
				client.lockObject(evt.Namespace.GetObjectKind(), evt.Namespace.ObjectMeta)
				client.processNamespaceEvent(evt, reactor, ostream)
			}
		} else {
			log.Infof("Not deleting non-venice object %+v", lobj.ObjectMeta)
		}
	}

	// add/update all new objects
	for _, obj := range objList.Namespaces {
		evt := netproto.NamespaceEvent{
			EventType: api.EventType_UpdateEvent,
			Namespace: *obj,
		}
		client.lockObject(evt.Namespace.GetObjectKind(), evt.Namespace.ObjectMeta)
		client.processNamespaceEvent(evt, reactor, ostream)
	}
}

// processNamespaceEvent handles Namespace event
func (client *NimbusClient) processNamespaceEvent(evt netproto.NamespaceEvent, reactor NamespaceReactor, ostream *NamespaceOStream) error {
	var err error
	client.waitGrp.Add(1)
	defer client.waitGrp.Done()

	// add venice label to the object
	evt.Namespace.ObjectMeta.Labels = make(map[string]string)
	evt.Namespace.ObjectMeta.Labels["CreatedBy"] = "Venice"

	// unlock the object once we are done
	defer client.unlockObject(evt.Namespace.GetObjectKind(), evt.Namespace.ObjectMeta)

	// retry till successful
	for iter := 0; iter < maxOpretry; iter++ {
		switch evt.EventType {
		case api.EventType_CreateEvent:
			fallthrough
		case api.EventType_UpdateEvent:
			_, err = reactor.FindNamespace(evt.Namespace.ObjectMeta)
			if err != nil {
				// create the Namespace
				err = reactor.CreateNamespace(&evt.Namespace)
				if err != nil {
					log.Errorf("Error creating the Namespace {%+v}. Err: %v", evt.Namespace.ObjectMeta, err)
					client.debugStats.AddInt("CreateNamespaceError", 1)
				} else {
					client.debugStats.AddInt("CreateNamespace", 1)
				}
			} else {
				// update the Namespace
				err = reactor.UpdateNamespace(&evt.Namespace)
				if err != nil {
					log.Errorf("Error updating the Namespace {%+v}. Err: %v", evt.Namespace.GetKey(), err)
					client.debugStats.AddInt("UpdateNamespaceError", 1)
				} else {
					client.debugStats.AddInt("UpdateNamespace", 1)
				}
			}

		case api.EventType_DeleteEvent:
			// delete the object
			err = reactor.DeleteNamespace(evt.Namespace.Tenant, evt.Namespace.Namespace, evt.Namespace.Name)
			if err == state.ErrObjectNotFound { // give idempotency to caller
				log.Debugf("Namespace {%+v} not found", evt.Namespace.ObjectMeta)
				err = nil
			}
			if err != nil {
				log.Errorf("Error deleting the Namespace {%+v}. Err: %v", evt.Namespace.ObjectMeta, err)
				client.debugStats.AddInt("DeleteNamespaceError", 1)
			} else {
				client.debugStats.AddInt("DeleteNamespace", 1)
			}
		}

		if ostream == nil {
			return err
		}
		// send oper status and return if there is no error
		if err == nil {
			robj := netproto.NamespaceEvent{
				EventType: evt.EventType,
				Namespace: netproto.Namespace{
					TypeMeta:   evt.Namespace.TypeMeta,
					ObjectMeta: evt.Namespace.ObjectMeta,
					Status:     evt.Namespace.Status,
				},
			}

			// send oper status
			ostream.Lock()
			modificationTime, _ := types.TimestampProto(time.Now())
			robj.Namespace.ObjectMeta.ModTime = api.Timestamp{Timestamp: *modificationTime}
			err := ostream.stream.Send(&robj)
			if err != nil {
				log.Errorf("failed to send Namespace oper Status, %s", err)
				client.debugStats.AddInt("NamespaceOperSendError", 1)
			} else {
				client.debugStats.AddInt("NamespaceOperSent", 1)
			}
			ostream.Unlock()

			return err
		}

		// else, retry after some time, with backoff
		time.Sleep(time.Second * time.Duration(2*iter))
	}

	return nil
}

func (client *NimbusClient) processNamespaceDynamic(evt api.EventType,
	object *netproto.Namespace, reactor NamespaceReactor) error {

	namespaceEvt := netproto.NamespaceEvent{
		EventType: evt,
		Namespace: *object,
	}

	// add venice label to the object
	namespaceEvt.Namespace.ObjectMeta.Labels = make(map[string]string)
	namespaceEvt.Namespace.ObjectMeta.Labels["CreatedBy"] = "Venice"

	client.lockObject(namespaceEvt.Namespace.GetObjectKind(), namespaceEvt.Namespace.ObjectMeta)

	err := client.processNamespaceEvent(namespaceEvt, reactor, nil)
	modificationTime, _ := types.TimestampProto(time.Now())
	object.ObjectMeta.ModTime = api.Timestamp{Timestamp: *modificationTime}

	return err
}
