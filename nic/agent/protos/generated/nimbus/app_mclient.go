// Code generated by protoc-gen-grpc-pensando DO NOT EDIT.

/*
Package nimbus is a auto generated package.
Input file: app.proto
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

type AppReactor interface {
	CreateApp(app *netproto.App) error                  // creates an App
	FindApp(meta api.ObjectMeta) (*netproto.App, error) // finds an App
	ListApp() []*netproto.App                           // lists all Apps
	UpdateApp(app *netproto.App) error                  // updates an App
	DeleteApp(app, ns, name string) error               // deletes an App
}

// WatchApps runs App watcher loop
func (client *NimbusClient) WatchApps(ctx context.Context, reactor AppReactor) {
	// setup wait group
	client.waitGrp.Add(1)
	defer client.waitGrp.Done()
	client.debugStats.AddInt("ActiveAppWatch", 1)

	// make sure rpc client is good
	if client.rpcClient == nil || client.rpcClient.ClientConn == nil || client.rpcClient.ClientConn.GetState() != connectivity.Ready {
		log.Errorf("RPC client is disconnected. Exiting watch")
		return
	}

	// start the watch
	appRPCClient := netproto.NewAppApiClient(client.rpcClient.ClientConn)
	stream, err := appRPCClient.WatchApps(ctx, &api.ObjectMeta{})
	if err != nil {
		log.Errorf("Error watching App. Err: %v", err)
		return
	}

	// get a list of objects
	objList, err := appRPCClient.ListApps(ctx, &api.ObjectMeta{})
	if err != nil {
		log.Errorf("Error getting App list. Err: %v", err)
		return
	}

	// perform a diff of the states
	client.diffApps(objList, reactor)

	// start grpc stream recv
	recvCh := make(chan *netproto.AppEvent, evChanLength)
	go client.watchAppRecvLoop(stream, recvCh)

	// loop till the end
	for {
		select {
		case evt, ok := <-recvCh:
			if !ok {
				log.Warnf("App Watch channel closed. Exisint AppWatch")
				return
			}
			client.debugStats.AddInt("AppWatchEvents", 1)

			log.Infof("Ctrlerif: agent %s got App watch event: Type: {%+v} App:{%+v}", client.clientName, evt.EventType, evt.App)

			client.lockObject(evt.App.GetObjectKind(), evt.App.ObjectMeta)
			client.processAppEvent(*evt, reactor)
		// periodic resync
		case <-time.After(resyncInterval):
			// get a list of objects
			objList, err := appRPCClient.ListApps(ctx, &api.ObjectMeta{})
			if err != nil {
				log.Errorf("Error getting App list. Err: %v", err)
				return
			}
			client.debugStats.AddInt("AppWatchResyncs", 1)

			// perform a diff of the states
			client.diffApps(objList, reactor)
		}
	}
}

// watchAppRecvLoop receives from stream and write it to a channel
func (client *NimbusClient) watchAppRecvLoop(stream netproto.AppApi_WatchAppsClient, recvch chan<- *netproto.AppEvent) {
	defer close(recvch)
	client.waitGrp.Add(1)
	defer client.waitGrp.Done()

	// loop till the end
	for {
		// receive from stream
		evt, err := stream.Recv()
		if err != nil {
			log.Errorf("Error receiving from watch channel. Exiting App watch. Err: %v", err)
			return
		}

		recvch <- evt
	}
}

// diffApp diffs local state with controller state
// FIXME: this is not handling deletes today
func (client *NimbusClient) diffApps(objList *netproto.AppList, reactor AppReactor) {
	// build a map of objects
	objmap := make(map[string]*netproto.App)
	for _, obj := range objList.Apps {
		key := obj.ObjectMeta.GetKey()
		objmap[key] = obj
	}

	// see if we need to delete any locally found object
	localObjs := reactor.ListApp()
	for _, lobj := range localObjs {
		key := lobj.ObjectMeta.GetKey()
		if _, ok := objmap[key]; !ok {
			evt := netproto.AppEvent{
				EventType: api.EventType_DeleteEvent,
				App:       *lobj,
			}
			client.lockObject(evt.App.GetObjectKind(), evt.App.ObjectMeta)
			client.processAppEvent(evt, reactor)
		}
	}

	// add/update all new objects
	for _, obj := range objList.Apps {
		evt := netproto.AppEvent{
			EventType: api.EventType_CreateEvent,
			App:       *obj,
		}
		client.lockObject(evt.App.GetObjectKind(), evt.App.ObjectMeta)
		client.processAppEvent(evt, reactor)
	}
}

// processAppEvent handles App event
func (client *NimbusClient) processAppEvent(evt netproto.AppEvent, reactor AppReactor) {
	var err error
	client.waitGrp.Add(1)
	defer client.waitGrp.Done()

	// unlock the object once we are done
	defer client.unlockObject(evt.App.GetObjectKind(), evt.App.ObjectMeta)

	// retry till successful
	for iter := 0; iter < maxOpretry; iter++ {
		switch evt.EventType {
		case api.EventType_CreateEvent:
			fallthrough
		case api.EventType_UpdateEvent:
			_, err = reactor.FindApp(evt.App.ObjectMeta)
			if err != nil {
				// create the App
				err = reactor.CreateApp(&evt.App)
				if err != nil {
					log.Errorf("Error creating the App {%+v}. Err: %v", evt.App, err)
					client.debugStats.AddInt("CreateAppError", 1)
				} else {
					client.debugStats.AddInt("CreateApp", 1)
				}
			} else {
				// update the App
				err = reactor.UpdateApp(&evt.App)
				if err != nil {
					log.Errorf("Error updating the App {%+v}. Err: %v", evt.App, err)
					client.debugStats.AddInt("UpdateAppError", 1)
				} else {
					client.debugStats.AddInt("UpdateApp", 1)
				}
			}

		case api.EventType_DeleteEvent:
			// delete the object
			err = reactor.DeleteApp(evt.App.Tenant, evt.App.Namespace, evt.App.Name)
			if err == state.ErrObjectNotFound { // give idempotency to caller
				log.Debugf("App {%+v} not found", evt.App.ObjectMeta)
				err = nil
			}
			if err != nil {
				log.Errorf("Error deleting the App {%+v}. Err: %v", evt.App.ObjectMeta, err)
				client.debugStats.AddInt("DeleteAppError", 1)
			} else {
				client.debugStats.AddInt("DeleteApp", 1)
			}
		}

		// return if there is no error
		if err == nil {
			if evt.EventType == api.EventType_CreateEvent || evt.EventType == api.EventType_UpdateEvent {
				robj := netproto.App{
					TypeMeta:   evt.App.TypeMeta,
					ObjectMeta: evt.App.ObjectMeta,
					Status:     evt.App.Status,
				}
				client.updateAppStatus(&robj)
			}
			return
		}

		// else, retry after some time, with backoff
		time.Sleep(time.Second * time.Duration(2*iter))
	}
}

// updateAppStatus sends status back to the controller
func (client *NimbusClient) updateAppStatus(resp *netproto.App) {
	if client.rpcClient != nil && client.rpcClient.ClientConn != nil && client.rpcClient.ClientConn.GetState() == connectivity.Ready {
		appRPCClient := netproto.NewAppApiClient(client.rpcClient.ClientConn)
		ctx, _ := context.WithTimeout(context.Background(), DefaultRPCTimeout)
		_, err := appRPCClient.UpdateApp(ctx, resp)
		if err != nil {
			log.Errorf("failed to send App Status, %s", err)
			client.debugStats.AddInt("AppStatusSendError", 1)
		} else {
			client.debugStats.AddInt("AppStatusSent", 1)
		}

	}
}
