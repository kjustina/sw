// Code generated by protoc-gen-grpc-pensando DO NOT EDIT.

/*
Package eventsApiServer is a auto generated package.
Input file: protos/events.proto
*/
package eventsApiServer

import (
	"context"
	"fmt"
	"time"

	"github.com/gogo/protobuf/types"
	"github.com/pensando/sw/api"
	events "github.com/pensando/sw/api/generated/events"
	"github.com/pensando/sw/api/listerwatcher"
	"github.com/pensando/sw/venice/apiserver"
	"github.com/pensando/sw/venice/apiserver/pkg"
	"github.com/pensando/sw/venice/utils/kvstore"
	"github.com/pensando/sw/venice/utils/log"
	"github.com/pensando/sw/venice/utils/rpckit"
	"github.com/pensando/sw/venice/utils/runtime"
	"github.com/pkg/errors"
	"github.com/satori/go.uuid"
	"google.golang.org/grpc"
)

// dummy vars to suppress unused errors
var _ api.ObjectMeta
var _ listerwatcher.WatcherClient
var _ fmt.Stringer

type seventsEventsBackend struct {
	Services map[string]apiserver.Service
	Messages map[string]apiserver.Message

	endpointsEventPolicyV1 *eEventPolicyV1Endpoints
}

type eEventPolicyV1Endpoints struct {
	Svc seventsEventsBackend

	fnAutoAddEventPolicy    func(ctx context.Context, t interface{}) (interface{}, error)
	fnAutoDeleteEventPolicy func(ctx context.Context, t interface{}) (interface{}, error)
	fnAutoGetEventPolicy    func(ctx context.Context, t interface{}) (interface{}, error)
	fnAutoListEventPolicy   func(ctx context.Context, t interface{}) (interface{}, error)
	fnAutoUpdateEventPolicy func(ctx context.Context, t interface{}) (interface{}, error)

	fnAutoWatchEventPolicy func(in *api.ListWatchOptions, stream grpc.ServerStream, svcprefix string) error
}

func (s *seventsEventsBackend) CompleteRegistration(ctx context.Context, logger log.Logger,
	grpcserver *rpckit.RPCServer, scheme *runtime.Scheme) error {
	s.Messages = map[string]apiserver.Message{

		"events.AutoMsgEventPolicyWatchHelper": apisrvpkg.NewMessage("events.AutoMsgEventPolicyWatchHelper"),
		"events.Event":                         apisrvpkg.NewMessage("events.Event"),
		"events.EventAttributes":               apisrvpkg.NewMessage("events.EventAttributes"),
		"events.EventPolicy": apisrvpkg.NewMessage("events.EventPolicy").WithKeyGenerator(func(i interface{}, prefix string) string {
			if i == nil {
				r := events.EventPolicy{}
				return r.MakeKey(prefix)
			}
			r := i.(events.EventPolicy)
			return r.MakeKey(prefix)
		}).WithObjectVersionWriter(func(i interface{}, version string) interface{} {
			r := i.(events.EventPolicy)
			r.APIVersion = version
			return r
		}).WithKvUpdater(func(ctx context.Context, kvs kvstore.Interface, i interface{}, prefix string, create, ignoreStatus bool) (interface{}, error) {
			r := i.(events.EventPolicy)
			key := r.MakeKey(prefix)
			r.Kind = "EventPolicy"
			var err error
			if create {
				err = kvs.Create(ctx, key, &r)
				err = errors.Wrap(err, "KV create failed")
			} else {
				if ignoreStatus {
					updateFunc := func(obj runtime.Object) (runtime.Object, error) {
						saved := obj.(*events.EventPolicy)
						if r.ResourceVersion != "" && r.ResourceVersion != saved.ResourceVersion {
							return nil, fmt.Errorf("Resource Version specified does not match Object version")
						}
						r.Status = saved.Status
						return &r, nil
					}
					into := &events.EventPolicy{}
					err = kvs.ConsistentUpdate(ctx, key, into, updateFunc)
				} else {
					if r.ResourceVersion != "" {
						logger.Infof("resource version is specified %s\n", r.ResourceVersion)
						err = kvs.Update(ctx, key, &r, kvstore.Compare(kvstore.WithVersion(key), "=", r.ResourceVersion))
					} else {
						err = kvs.Update(ctx, key, &r)
					}
					err = errors.Wrap(err, "KV update failed")
				}
			}
			return r, err
		}).WithKvTxnUpdater(func(ctx context.Context, txn kvstore.Txn, i interface{}, prefix string, create bool) error {
			r := i.(events.EventPolicy)
			key := r.MakeKey(prefix)
			var err error
			if create {
				err = txn.Create(key, &r)
				err = errors.Wrap(err, "KV transaction create failed")
			} else {
				err = txn.Update(key, &r)
				err = errors.Wrap(err, "KV transaction update failed")
			}
			return err
		}).WithUUIDWriter(func(i interface{}) (interface{}, error) {
			r := i.(events.EventPolicy)
			r.UUID = uuid.NewV4().String()
			return r, nil
		}).WithCreationTimeWriter(func(i interface{}) (interface{}, error) {
			r := i.(events.EventPolicy)
			var err error
			ts, err := types.TimestampProto(time.Now())
			if err == nil {
				r.CreationTime.Timestamp = *ts
			}
			return r, err
		}).WithModTimeWriter(func(i interface{}) (interface{}, error) {
			r := i.(events.EventPolicy)
			var err error
			ts, err := types.TimestampProto(time.Now())
			if err == nil {
				r.ModTime.Timestamp = *ts
			}
			return r, err
		}).WithKvGetter(func(ctx context.Context, kvs kvstore.Interface, key string) (interface{}, error) {
			r := events.EventPolicy{}
			err := kvs.Get(ctx, key, &r)
			err = errors.Wrap(err, "KV get failed")
			return r, err
		}).WithKvDelFunc(func(ctx context.Context, kvs kvstore.Interface, key string) (interface{}, error) {
			r := events.EventPolicy{}
			err := kvs.Delete(ctx, key, &r)
			return r, err
		}).WithKvTxnDelFunc(func(ctx context.Context, txn kvstore.Txn, key string) error {
			return txn.Delete(key)
		}).WithValidate(func(i interface{}, ver string, ignoreStatus bool) error {
			r := i.(events.EventPolicy)
			if !r.Validate(ver, ignoreStatus) {
				return fmt.Errorf("Default Validation failed")
			}
			return nil
		}),
		"events.EventPolicyList": apisrvpkg.NewMessage("events.EventPolicyList").WithKvListFunc(func(ctx context.Context, kvs kvstore.Interface, options *api.ListWatchOptions, prefix string) (interface{}, error) {

			into := events.EventPolicyList{}
			r := events.EventPolicy{}
			key := r.MakeKey(prefix)
			err := kvs.List(ctx, key, &into)
			if err != nil {
				return nil, err
			}
			return into, nil
		}),
		"events.EventPolicySpec":   apisrvpkg.NewMessage("events.EventPolicySpec"),
		"events.EventPolicyStatus": apisrvpkg.NewMessage("events.EventPolicyStatus"),
		"events.EventSource":       apisrvpkg.NewMessage("events.EventSource"),
		// Add a message handler for ListWatch options
		"api.ListWatchOptions": apisrvpkg.NewMessage("api.ListWatchOptions"),
	}

	scheme.AddKnownTypes(
		&events.EventPolicy{},
	)

	apisrv.RegisterMessages("events", s.Messages)

	{
		srv := apisrvpkg.NewService("EventPolicyV1")

		s.endpointsEventPolicyV1.fnAutoAddEventPolicy = srv.AddMethod("AutoAddEventPolicy",
			apisrvpkg.NewMethod(s.Messages["events.EventPolicy"], s.Messages["events.EventPolicy"], "eventPolicy", "AutoAddEventPolicy")).WithOper(apiserver.CreateOper).WithVersion("v1").HandleInvocation

		s.endpointsEventPolicyV1.fnAutoDeleteEventPolicy = srv.AddMethod("AutoDeleteEventPolicy",
			apisrvpkg.NewMethod(s.Messages["events.EventPolicy"], s.Messages["events.EventPolicy"], "eventPolicy", "AutoDeleteEventPolicy")).WithOper(apiserver.DeleteOper).WithVersion("v1").HandleInvocation

		s.endpointsEventPolicyV1.fnAutoGetEventPolicy = srv.AddMethod("AutoGetEventPolicy",
			apisrvpkg.NewMethod(s.Messages["events.EventPolicy"], s.Messages["events.EventPolicy"], "eventPolicy", "AutoGetEventPolicy")).WithOper(apiserver.GetOper).WithVersion("v1").HandleInvocation

		s.endpointsEventPolicyV1.fnAutoListEventPolicy = srv.AddMethod("AutoListEventPolicy",
			apisrvpkg.NewMethod(s.Messages["api.ListWatchOptions"], s.Messages["events.EventPolicyList"], "eventPolicy", "AutoListEventPolicy")).WithOper(apiserver.ListOper).WithVersion("v1").HandleInvocation

		s.endpointsEventPolicyV1.fnAutoUpdateEventPolicy = srv.AddMethod("AutoUpdateEventPolicy",
			apisrvpkg.NewMethod(s.Messages["events.EventPolicy"], s.Messages["events.EventPolicy"], "eventPolicy", "AutoUpdateEventPolicy")).WithOper(apiserver.UpdateOper).WithVersion("v1").HandleInvocation

		s.endpointsEventPolicyV1.fnAutoWatchEventPolicy = s.Messages["events.EventPolicy"].WatchFromKv

		s.Services = map[string]apiserver.Service{
			"events.EventPolicyV1": srv,
		}
		apisrv.RegisterService("events.EventPolicyV1", srv)
		endpoints := events.MakeEventPolicyV1ServerEndpoints(s.endpointsEventPolicyV1, logger)
		server := events.MakeGRPCServerEventPolicyV1(ctx, endpoints, logger)
		events.RegisterEventPolicyV1Server(grpcserver.GrpcServer, server)
	}
	// Add Watchers
	{

		s.Messages["events.EventPolicy"].WithKvWatchFunc(func(l log.Logger, options *api.ListWatchOptions, kvs kvstore.Interface, stream interface{}, txfn func(from, to string, i interface{}) (interface{}, error), version, svcprefix string) error {
			o := events.EventPolicy{}
			key := o.MakeKey(svcprefix)
			wstream := stream.(events.EventPolicyV1_AutoWatchEventPolicyServer)
			nctx, cancel := context.WithCancel(wstream.Context())
			defer cancel()
			if kvs == nil {
				return fmt.Errorf("Nil KVS")
			}
			watcher, err := kvs.PrefixWatch(nctx, key, options.ResourceVersion)
			if err != nil {
				l.ErrorLog("msg", "error starting Watch on KV", "error", err, "object", "EventPolicy")
				return err
			}
			for {
				select {
				case ev, ok := <-watcher.EventChan():
					if !ok {
						l.DebugLog("Channel closed for EventPolicy Watcher")
						return nil
					}
					in, ok := ev.Object.(*events.EventPolicy)
					if !ok {
						status, ok := ev.Object.(*api.Status)
						if !ok {
							return errors.New("unknown error")
						}
						return fmt.Errorf("%v:(%s) %s", status.Code, status.Result, status.Message)
					}
					strEvent := events.AutoMsgEventPolicyWatchHelper{
						Type:   string(ev.Type),
						Object: in,
					}
					l.DebugLog("msg", "received EventPolicy watch event from KV", "type", ev.Type)
					if version != in.APIVersion {
						i, err := txfn(in.APIVersion, version, in)
						if err != nil {
							l.ErrorLog("msg", "Failed to transform message", "type", "EventPolicy", "fromver", in.APIVersion, "tover", version)
							break
						}
						strEvent.Object = i.(*events.EventPolicy)
					}
					l.DebugLog("msg", "writing to stream")
					if err := wstream.Send(&strEvent); err != nil {
						l.DebugLog("msg", "Stream send error'ed for EventPolicy", "error", err)
						return err
					}
				case <-nctx.Done():
					l.DebugLog("msg", "Context cancelled for EventPolicy Watcher")
					return wstream.Context().Err()
				}
			}
		})

	}

	return nil
}

func (e *eEventPolicyV1Endpoints) AutoAddEventPolicy(ctx context.Context, t events.EventPolicy) (events.EventPolicy, error) {
	r, err := e.fnAutoAddEventPolicy(ctx, t)
	if err == nil {
		return r.(events.EventPolicy), err
	}
	return events.EventPolicy{}, err

}
func (e *eEventPolicyV1Endpoints) AutoDeleteEventPolicy(ctx context.Context, t events.EventPolicy) (events.EventPolicy, error) {
	r, err := e.fnAutoDeleteEventPolicy(ctx, t)
	if err == nil {
		return r.(events.EventPolicy), err
	}
	return events.EventPolicy{}, err

}
func (e *eEventPolicyV1Endpoints) AutoGetEventPolicy(ctx context.Context, t events.EventPolicy) (events.EventPolicy, error) {
	r, err := e.fnAutoGetEventPolicy(ctx, t)
	if err == nil {
		return r.(events.EventPolicy), err
	}
	return events.EventPolicy{}, err

}
func (e *eEventPolicyV1Endpoints) AutoListEventPolicy(ctx context.Context, t api.ListWatchOptions) (events.EventPolicyList, error) {
	r, err := e.fnAutoListEventPolicy(ctx, t)
	if err == nil {
		return r.(events.EventPolicyList), err
	}
	return events.EventPolicyList{}, err

}
func (e *eEventPolicyV1Endpoints) AutoUpdateEventPolicy(ctx context.Context, t events.EventPolicy) (events.EventPolicy, error) {
	r, err := e.fnAutoUpdateEventPolicy(ctx, t)
	if err == nil {
		return r.(events.EventPolicy), err
	}
	return events.EventPolicy{}, err

}

func (e *eEventPolicyV1Endpoints) AutoWatchEventPolicy(in *api.ListWatchOptions, stream events.EventPolicyV1_AutoWatchEventPolicyServer) error {
	return e.fnAutoWatchEventPolicy(in, stream, "eventPolicy")
}

func init() {
	apisrv = apisrvpkg.MustGetAPIServer()

	svc := seventsEventsBackend{}

	{
		e := eEventPolicyV1Endpoints{Svc: svc}
		svc.endpointsEventPolicyV1 = &e
	}
	apisrv.Register("events.protos/events.proto", &svc)
}
