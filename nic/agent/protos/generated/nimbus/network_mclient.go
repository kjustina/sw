// Code generated by protoc-gen-grpc-pensando DO NOT EDIT.

/*
Package nimbus is a auto generated package.
Input file: network.proto
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

type NetworkReactor interface {
	CreateNetwork(network *netproto.Network) error              // creates an Network
	FindNetwork(meta api.ObjectMeta) (*netproto.Network, error) // finds an Network
	ListNetwork() []*netproto.Network                           // lists all Networks
	UpdateNetwork(network *netproto.Network) error              // updates an Network
	DeleteNetwork(network, ns, name string) error               // deletes an Network
}

// WatchNetworks runs Network watcher loop
func (client *NimbusClient) WatchNetworks(ctx context.Context, reactor NetworkReactor) {
	// setup wait group
	client.waitGrp.Add(1)
	defer client.waitGrp.Done()
	client.debugStats.AddInt("ActiveNetworkWatch", 1)

	// make sure rpc client is good
	if client.rpcClient == nil || client.rpcClient.ClientConn == nil || client.rpcClient.ClientConn.GetState() != connectivity.Ready {
		log.Errorf("RPC client is disconnected. Exiting watch")
		return
	}

	// start the watch
	networkRPCClient := netproto.NewNetworkApiClient(client.rpcClient.ClientConn)
	stream, err := networkRPCClient.WatchNetworks(ctx, &api.ObjectMeta{})
	if err != nil {
		log.Errorf("Error watching Network. Err: %v", err)
		return
	}

	// get a list of objects
	objList, err := networkRPCClient.ListNetworks(ctx, &api.ObjectMeta{})
	if err != nil {
		log.Errorf("Error getting Network list. Err: %v", err)
		return
	}

	// perform a diff of the states
	client.diffNetworks(objList, reactor)

	// start grpc stream recv
	recvCh := make(chan *netproto.NetworkEvent, evChanLength)
	go client.watchNetworkRecvLoop(stream, recvCh)

	// loop till the end
	for {
		select {
		case evt, ok := <-recvCh:
			if !ok {
				log.Warnf("Network Watch channel closed. Exisint NetworkWatch")
				return
			}
			client.debugStats.AddInt("NetworkWatchEvents", 1)

			log.Infof("Ctrlerif: agent %s got Network watch event: Type: {%+v} Network:{%+v}", client.clientName, evt.EventType, evt.Network)

			client.lockObject(evt.Network.GetObjectKind(), evt.Network.ObjectMeta)
			client.processNetworkEvent(*evt, reactor)
		// periodic resync
		case <-time.After(resyncInterval):
			// get a list of objects
			objList, err := networkRPCClient.ListNetworks(ctx, &api.ObjectMeta{})
			if err != nil {
				log.Errorf("Error getting Network list. Err: %v", err)
				return
			}
			client.debugStats.AddInt("NetworkWatchResyncs", 1)

			// perform a diff of the states
			client.diffNetworks(objList, reactor)
		}
	}
}

// watchNetworkRecvLoop receives from stream and write it to a channel
func (client *NimbusClient) watchNetworkRecvLoop(stream netproto.NetworkApi_WatchNetworksClient, recvch chan<- *netproto.NetworkEvent) {
	defer close(recvch)
	client.waitGrp.Add(1)
	defer client.waitGrp.Done()

	// loop till the end
	for {
		// receive from stream
		evt, err := stream.Recv()
		if err != nil {
			log.Errorf("Error receiving from watch channel. Exiting Network watch. Err: %v", err)
			return
		}

		recvch <- evt
	}
}

// diffNetwork diffs local state with controller state
// FIXME: this is not handling deletes today
func (client *NimbusClient) diffNetworks(objList *netproto.NetworkList, reactor NetworkReactor) {
	// build a map of objects
	objmap := make(map[string]*netproto.Network)
	for _, obj := range objList.Networks {
		key := obj.ObjectMeta.GetKey()
		objmap[key] = obj
	}

	// see if we need to delete any locally found object
	localObjs := reactor.ListNetwork()
	for _, lobj := range localObjs {
		key := lobj.ObjectMeta.GetKey()
		if _, ok := objmap[key]; !ok {
			evt := netproto.NetworkEvent{
				EventType: api.EventType_DeleteEvent,
				Network:   *lobj,
			}
			client.lockObject(evt.Network.GetObjectKind(), evt.Network.ObjectMeta)
			client.processNetworkEvent(evt, reactor)
		}
	}

	// add/update all new objects
	for _, obj := range objList.Networks {
		evt := netproto.NetworkEvent{
			EventType: api.EventType_CreateEvent,
			Network:   *obj,
		}
		client.lockObject(evt.Network.GetObjectKind(), evt.Network.ObjectMeta)
		client.processNetworkEvent(evt, reactor)
	}
}

// processNetworkEvent handles Network event
func (client *NimbusClient) processNetworkEvent(evt netproto.NetworkEvent, reactor NetworkReactor) {
	var err error
	client.waitGrp.Add(1)
	defer client.waitGrp.Done()

	// unlock the object once we are done
	defer client.unlockObject(evt.Network.GetObjectKind(), evt.Network.ObjectMeta)

	// retry till successful
	for iter := 0; iter < maxOpretry; iter++ {
		switch evt.EventType {
		case api.EventType_CreateEvent:
			fallthrough
		case api.EventType_UpdateEvent:
			_, err = reactor.FindNetwork(evt.Network.ObjectMeta)
			if err != nil {
				// create the Network
				err = reactor.CreateNetwork(&evt.Network)
				if err != nil {
					log.Errorf("Error creating the Network {%+v}. Err: %v", evt.Network, err)
					client.debugStats.AddInt("CreateNetworkError", 1)
				} else {
					client.debugStats.AddInt("CreateNetwork", 1)
				}
			} else {
				// update the Network
				err = reactor.UpdateNetwork(&evt.Network)
				if err != nil {
					log.Errorf("Error updating the Network {%+v}. Err: %v", evt.Network, err)
					client.debugStats.AddInt("UpdateNetworkError", 1)
				} else {
					client.debugStats.AddInt("UpdateNetwork", 1)
				}
			}

		case api.EventType_DeleteEvent:
			// delete the object
			err = reactor.DeleteNetwork(evt.Network.Tenant, evt.Network.Namespace, evt.Network.Name)
			if err == state.ErrObjectNotFound { // give idempotency to caller
				log.Debugf("Network {%+v} not found", evt.Network.ObjectMeta)
				err = nil
			}
			if err != nil {
				log.Errorf("Error deleting the Network {%+v}. Err: %v", evt.Network.ObjectMeta, err)
				client.debugStats.AddInt("DeleteNetworkError", 1)
			} else {
				client.debugStats.AddInt("DeleteNetwork", 1)
			}
		}

		// return if there is no error
		if err == nil {
			if evt.EventType == api.EventType_CreateEvent || evt.EventType == api.EventType_UpdateEvent {
				robj := netproto.Network{
					TypeMeta:   evt.Network.TypeMeta,
					ObjectMeta: evt.Network.ObjectMeta,
					Status:     evt.Network.Status,
				}
				client.updateNetworkStatus(&robj)
			}
			return
		}

		// else, retry after some time, with backoff
		time.Sleep(time.Second * time.Duration(2*iter))
	}
}

// updateNetworkStatus sends status back to the controller
func (client *NimbusClient) updateNetworkStatus(resp *netproto.Network) {
	if client.rpcClient != nil && client.rpcClient.ClientConn != nil && client.rpcClient.ClientConn.GetState() == connectivity.Ready {
		networkRPCClient := netproto.NewNetworkApiClient(client.rpcClient.ClientConn)
		ctx, _ := context.WithTimeout(context.Background(), DefaultRPCTimeout)
		_, err := networkRPCClient.UpdateNetwork(ctx, resp)
		if err != nil {
			log.Errorf("failed to send Network Status, %s", err)
			client.debugStats.AddInt("NetworkStatusSendError", 1)
		} else {
			client.debugStats.AddInt("NetworkStatusSent", 1)
		}

	}
}
