// Code generated by protoc-gen-grpc-pensando DO NOT EDIT.

/*
Package ctkit is a auto generated package.
Input file: svc_rollout.proto
*/
package ctkit

import (
	"context"
	"fmt"
	"sync"
	"time"

	"github.com/pensando/sw/api"
	"github.com/pensando/sw/api/generated/apiclient"
	"github.com/pensando/sw/api/generated/rollout"
	"github.com/pensando/sw/venice/utils/kvstore"
	"github.com/pensando/sw/venice/utils/log"
	"github.com/pensando/sw/venice/utils/ref"
	"github.com/pensando/sw/venice/utils/rpckit"
)

// Rollout is a wrapper object that implements additional functionality
type Rollout struct {
	sync.Mutex
	rollout.Rollout
	HandlerCtx interface{} // additional state handlers can store
	ctrler     *ctrlerCtx  // reference back to the controller instance
}

func (obj *Rollout) Write() error {
	// if there is no API server to connect to, we are done
	if (obj.ctrler == nil) || (obj.ctrler.resolver == nil) || obj.ctrler.apisrvURL == "" {
		return nil
	}

	apicl, err := obj.ctrler.apiClient()
	if err != nil {
		log.Errorf("Error creating API server clent. Err: %v", err)
		return err
	}

	// write to api server
	if obj.ObjectMeta.ResourceVersion != "" {
		nobj := *obj
		// FIXME: clear the resource version till we figure out CAS semantics
		nobj.ObjectMeta.ResourceVersion = ""

		// update it
		_, err = apicl.RolloutV1().Rollout().Update(context.Background(), &nobj.Rollout)
	} else {
		//  create
		_, err = apicl.RolloutV1().Rollout().Create(context.Background(), &obj.Rollout)
	}

	return nil
}

// RolloutHandler is the event handler for Rollout object
type RolloutHandler interface {
	OnRolloutCreate(obj *Rollout) error
	OnRolloutUpdate(obj *Rollout) error
	OnRolloutDelete(obj *Rollout) error
}

// handleRolloutEvent handles Rollout events from watcher
func (ct *ctrlerCtx) handleRolloutEvent(evt *kvstore.WatchEvent) error {
	switch tp := evt.Object.(type) {
	case *rollout.Rollout:
		eobj := evt.Object.(*rollout.Rollout)
		kind := "Rollout"

		log.Infof("Watcher: Got %s watch event(%s): {%+v}", kind, evt.Type, eobj)

		handler, ok := ct.handlers[kind]
		if !ok {
			log.Fatalf("Cant find the handler for %s", kind)
		}
		rolloutHandler := handler.(RolloutHandler)
		// handle based on event type
		switch evt.Type {
		case kvstore.Created:
			fallthrough
		case kvstore.Updated:
			fobj, err := ct.findObject(kind, eobj.GetKey())
			if err != nil {
				obj := &Rollout{
					Rollout:    *eobj,
					HandlerCtx: nil,
					ctrler:     ct,
				}
				ct.addObject(kind, obj.GetKey(), obj)
				// call the event handler
				obj.Lock()
				err = rolloutHandler.OnRolloutCreate(obj)
				obj.Unlock()
				if err != nil {
					log.Errorf("Error creating %s %+v. Err: %v", kind, obj, err)
					ct.delObject(kind, eobj.GetKey())
					return err
				}
			} else {
				obj := fobj.(*Rollout)
				obj.ObjectMeta = eobj.ObjectMeta

				// see if it changed
				if _, ok := ref.ObjDiff(obj.Spec, eobj.Spec); ok {
					obj.Spec = eobj.Spec
					// call the event handler
					obj.Lock()
					err = rolloutHandler.OnRolloutUpdate(obj)
					obj.Unlock()
					if err != nil {
						log.Errorf("Error creating %s %+v. Err: %v", kind, obj, err)
						return err
					}
				}
			}
		case kvstore.Deleted:
			fobj, err := ct.findObject(kind, eobj.GetKey())
			if err != nil {
				log.Errorf("Object %s/%s not found durng delete. Err: %v", kind, eobj.GetKey(), err)
				return err
			}

			obj := fobj.(*Rollout)

			// Call the event reactor
			obj.Lock()
			err = rolloutHandler.OnRolloutDelete(obj)
			obj.Unlock()
			if err != nil {
				log.Errorf("Error deleting %s: %+v. Err: %v", kind, obj, err)
				return err
			}

			ct.delObject(kind, eobj.GetKey())
		}
	default:
		log.Fatalf("API watcher Found object of invalid type: %v on Rollout watch channel", tp)
	}

	return nil
}

// diffRollout does a diff of Rollout objects between local cache and API server
func (ct *ctrlerCtx) diffRollout(apicl apiclient.Services) {
	opts := api.ListWatchOptions{}

	// get a list of all objects from API server
	objlist, err := apicl.RolloutV1().Rollout().List(context.Background(), &opts)
	if err != nil {
		log.Errorf("Error getting a list of objects. Err: %v", err)
		return
	}

	// build an object map
	objmap := make(map[string]*rollout.Rollout)
	for _, obj := range objlist {
		objmap[obj.GetKey()] = obj
	}

	// if an object is in our local cache and not in API server, trigger delete for it
	for _, obj := range ct.Rollout().List() {
		_, ok := objmap[obj.GetKey()]
		if !ok {
			evt := kvstore.WatchEvent{
				Type:   kvstore.Deleted,
				Key:    obj.GetKey(),
				Object: &obj.Rollout,
			}
			ct.handleRolloutEvent(&evt)
		}
	}

	// trigger create event for all others
	for _, obj := range objlist {
		evt := kvstore.WatchEvent{
			Type:   kvstore.Created,
			Key:    obj.GetKey(),
			Object: obj,
		}
		ct.handleRolloutEvent(&evt)
	}
}

func (ct *ctrlerCtx) runRolloutWatcher() {
	kind := "Rollout"

	// if there is no API server to connect to, we are done
	if (ct.resolver == nil) || ct.apisrvURL == "" {
		return
	}

	// create context
	ctx, cancel := context.WithCancel(context.Background())
	ct.Lock()
	ct.watchCancel[kind] = cancel
	ct.Unlock()
	opts := api.ListWatchOptions{}

	// setup wait group
	ct.waitGrp.Add(1)
	defer ct.waitGrp.Done()

	// loop forever
	for {
		// create a grpc client
		apicl, err := apiclient.NewGrpcAPIClient(ct.name, ct.apisrvURL, ct.logger, rpckit.WithBalancer(ct.balancer))
		if err != nil {
			log.Warnf("Failed to connect to gRPC server [%s]\n", ct.apisrvURL)
		} else {
			log.Infof("API client connected {%+v}", apicl)

			// Rollout object watcher
			wt, werr := apicl.RolloutV1().Rollout().Watch(ctx, &opts)
			if werr != nil {
				log.Errorf("Failed to start %s watch (%s)\n", kind, werr)
				return
			}
			ct.Lock()
			ct.watchers[kind] = wt
			ct.Unlock()

			// perform a diff with API server and local cache
			time.Sleep(time.Millisecond * 100)
			ct.diffRollout(apicl)

			// handle api server watch events
		innerLoop:
			for {
				// wait for events
				select {
				case evt, ok := <-wt.EventChan():
					if !ok {
						log.Error("Error receiving from apisrv watcher")
						break innerLoop
					}

					// handle event
					ct.handleRolloutEvent(evt)
				}
			}
			apicl.Close()
		}

		// if stop flag is set, we are done
		if ct.stoped {
			log.Infof("Exiting API server watcher")
			return
		}

		// wait for a second and retry connecting to api server
		time.Sleep(time.Second)
	}
}

// WatchRollout starts watch on Rollout object
func (ct *ctrlerCtx) WatchRollout(handler RolloutHandler) error {
	kind := "Rollout"

	ct.Lock()
	defer ct.Unlock()

	// see if we already have a watcher
	_, ok := ct.watchers[kind]
	if ok {
		return fmt.Errorf("Rollout watcher already exists")
	}

	// save handler
	ct.handlers[kind] = handler

	// run Rollout watcher in a go routine
	go ct.runRolloutWatcher()

	return nil
}

// RolloutAPI returns
type RolloutAPI interface {
	Create(obj *rollout.Rollout) error
	Update(obj *rollout.Rollout) error
	Delete(obj *rollout.Rollout) error
	List() []*Rollout
	Watch(handler RolloutHandler) error
}

// dummy struct that implements RolloutAPI
type rolloutAPI struct {
	ct *ctrlerCtx
}

// Create creates Rollout object
func (api *rolloutAPI) Create(obj *rollout.Rollout) error {
	return api.ct.handleRolloutEvent(&kvstore.WatchEvent{Object: obj, Type: kvstore.Created})
}

// Update triggers update on Rollout object
func (api *rolloutAPI) Update(obj *rollout.Rollout) error {
	return api.ct.handleRolloutEvent(&kvstore.WatchEvent{Object: obj, Type: kvstore.Updated})
}

// Delete deletes Rollout object
func (api *rolloutAPI) Delete(obj *rollout.Rollout) error {
	return api.ct.handleRolloutEvent(&kvstore.WatchEvent{Object: obj, Type: kvstore.Deleted})
}

// List returns a list of all Rollout objects
func (api *rolloutAPI) List() []*Rollout {
	var objlist []*Rollout

	objs := api.ct.ListObjects("Rollout")
	for _, obj := range objs {
		switch tp := obj.(type) {
		case *Rollout:
			eobj := obj.(*Rollout)
			objlist = append(objlist, eobj)
		default:
			log.Fatalf("Got invalid object type %v while looking for Rollout", tp)
		}
	}

	return objlist
}

// Watch sets up a event handlers for Rollout object
func (api *rolloutAPI) Watch(handler RolloutHandler) error {
	return api.ct.WatchRollout(handler)
}

// Rollout returns RolloutAPI
func (ct *ctrlerCtx) Rollout() RolloutAPI {
	return &rolloutAPI{ct: ct}
}
