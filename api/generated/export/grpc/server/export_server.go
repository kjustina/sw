// Code generated by protoc-gen-grpc-pensando DO NOT EDIT.

/*
Package exportApiServer is a auto generated package.
Input file: protos/export.proto
*/
package exportApiServer

import (
	"context"
	"fmt"
	"time"

	"github.com/gogo/protobuf/types"
	"github.com/pensando/sw/api"
	export "github.com/pensando/sw/api/generated/export"
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

type sexportExportBackend struct {
	Services map[string]apiserver.Service
	Messages map[string]apiserver.Message

	endpointsExportPolicyV1 *eExportPolicyV1Endpoints
}

type eExportPolicyV1Endpoints struct {
	Svc sexportExportBackend

	fnAutoAddExportPolicy    func(ctx context.Context, t interface{}) (interface{}, error)
	fnAutoDeleteExportPolicy func(ctx context.Context, t interface{}) (interface{}, error)
	fnAutoGetExportPolicy    func(ctx context.Context, t interface{}) (interface{}, error)
	fnAutoListExportPolicy   func(ctx context.Context, t interface{}) (interface{}, error)
	fnAutoUpdateExportPolicy func(ctx context.Context, t interface{}) (interface{}, error)

	fnAutoWatchExportPolicy func(in *api.ListWatchOptions, stream grpc.ServerStream, svcprefix string) error
}

func (s *sexportExportBackend) CompleteRegistration(ctx context.Context, logger log.Logger,
	grpcserver *rpckit.RPCServer, scheme *runtime.Scheme) error {
	s.Messages = map[string]apiserver.Message{

		"export.AutoMsgExportPolicyWatchHelper": apisrvpkg.NewMessage("export.AutoMsgExportPolicyWatchHelper"),
		"export.ExportPolicy": apisrvpkg.NewMessage("export.ExportPolicy").WithKeyGenerator(func(i interface{}, prefix string) string {
			if i == nil {
				r := export.ExportPolicy{}
				return r.MakeKey(prefix)
			}
			r := i.(export.ExportPolicy)
			return r.MakeKey(prefix)
		}).WithObjectVersionWriter(func(i interface{}, version string) interface{} {
			r := i.(export.ExportPolicy)
			r.APIVersion = version
			return r
		}).WithKvUpdater(func(ctx context.Context, kvs kvstore.Interface, i interface{}, prefix string, create, ignoreStatus bool) (interface{}, error) {
			r := i.(export.ExportPolicy)
			key := r.MakeKey(prefix)
			r.Kind = "ExportPolicy"
			var err error
			if create {
				err = kvs.Create(ctx, key, &r)
				err = errors.Wrap(err, "KV create failed")
			} else {
				if ignoreStatus {
					updateFunc := func(obj runtime.Object) (runtime.Object, error) {
						saved := obj.(*export.ExportPolicy)
						if r.ResourceVersion != "" && r.ResourceVersion != saved.ResourceVersion {
							return nil, fmt.Errorf("Resource Version specified does not match Object version")
						}
						r.Status = saved.Status
						return &r, nil
					}
					into := &export.ExportPolicy{}
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
			r := i.(export.ExportPolicy)
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
			r := i.(export.ExportPolicy)
			r.UUID = uuid.NewV4().String()
			return r, nil
		}).WithCreationTimeWriter(func(i interface{}) (interface{}, error) {
			r := i.(export.ExportPolicy)
			var err error
			ts, err := types.TimestampProto(time.Now())
			if err == nil {
				r.CreationTime.Timestamp = *ts
			}
			return r, err
		}).WithModTimeWriter(func(i interface{}) (interface{}, error) {
			r := i.(export.ExportPolicy)
			var err error
			ts, err := types.TimestampProto(time.Now())
			if err == nil {
				r.ModTime.Timestamp = *ts
			}
			return r, err
		}).WithKvGetter(func(ctx context.Context, kvs kvstore.Interface, key string) (interface{}, error) {
			r := export.ExportPolicy{}
			err := kvs.Get(ctx, key, &r)
			err = errors.Wrap(err, "KV get failed")
			return r, err
		}).WithKvDelFunc(func(ctx context.Context, kvs kvstore.Interface, key string) (interface{}, error) {
			r := export.ExportPolicy{}
			err := kvs.Delete(ctx, key, &r)
			return r, err
		}).WithKvTxnDelFunc(func(ctx context.Context, txn kvstore.Txn, key string) error {
			return txn.Delete(key)
		}).WithValidate(func(i interface{}, ver string, ignoreStatus bool) error {
			r := i.(export.ExportPolicy)
			if !r.Validate(ver, ignoreStatus) {
				return fmt.Errorf("Default Validation failed")
			}
			return nil
		}),
		"export.ExportPolicyList": apisrvpkg.NewMessage("export.ExportPolicyList").WithKvListFunc(func(ctx context.Context, kvs kvstore.Interface, options *api.ListWatchOptions, prefix string) (interface{}, error) {

			into := export.ExportPolicyList{}
			r := export.ExportPolicy{}
			key := r.MakeKey(prefix)
			err := kvs.List(ctx, key, &into)
			if err != nil {
				return nil, err
			}
			return into, nil
		}),
		"export.ExportPolicySpec":   apisrvpkg.NewMessage("export.ExportPolicySpec"),
		"export.ExportPolicyStatus": apisrvpkg.NewMessage("export.ExportPolicyStatus"),
		"export.ExternalCred":       apisrvpkg.NewMessage("export.ExternalCred"),
		// Add a message handler for ListWatch options
		"api.ListWatchOptions": apisrvpkg.NewMessage("api.ListWatchOptions"),
	}

	scheme.AddKnownTypes(
		&export.ExportPolicy{},
	)

	apisrv.RegisterMessages("export", s.Messages)

	{
		srv := apisrvpkg.NewService("ExportPolicyV1")

		s.endpointsExportPolicyV1.fnAutoAddExportPolicy = srv.AddMethod("AutoAddExportPolicy",
			apisrvpkg.NewMethod(s.Messages["export.ExportPolicy"], s.Messages["export.ExportPolicy"], "exportPolicy", "AutoAddExportPolicy")).WithOper(apiserver.CreateOper).WithVersion("v1").HandleInvocation

		s.endpointsExportPolicyV1.fnAutoDeleteExportPolicy = srv.AddMethod("AutoDeleteExportPolicy",
			apisrvpkg.NewMethod(s.Messages["export.ExportPolicy"], s.Messages["export.ExportPolicy"], "exportPolicy", "AutoDeleteExportPolicy")).WithOper(apiserver.DeleteOper).WithVersion("v1").HandleInvocation

		s.endpointsExportPolicyV1.fnAutoGetExportPolicy = srv.AddMethod("AutoGetExportPolicy",
			apisrvpkg.NewMethod(s.Messages["export.ExportPolicy"], s.Messages["export.ExportPolicy"], "exportPolicy", "AutoGetExportPolicy")).WithOper(apiserver.GetOper).WithVersion("v1").HandleInvocation

		s.endpointsExportPolicyV1.fnAutoListExportPolicy = srv.AddMethod("AutoListExportPolicy",
			apisrvpkg.NewMethod(s.Messages["api.ListWatchOptions"], s.Messages["export.ExportPolicyList"], "exportPolicy", "AutoListExportPolicy")).WithOper(apiserver.ListOper).WithVersion("v1").HandleInvocation

		s.endpointsExportPolicyV1.fnAutoUpdateExportPolicy = srv.AddMethod("AutoUpdateExportPolicy",
			apisrvpkg.NewMethod(s.Messages["export.ExportPolicy"], s.Messages["export.ExportPolicy"], "exportPolicy", "AutoUpdateExportPolicy")).WithOper(apiserver.UpdateOper).WithVersion("v1").HandleInvocation

		s.endpointsExportPolicyV1.fnAutoWatchExportPolicy = s.Messages["export.ExportPolicy"].WatchFromKv

		s.Services = map[string]apiserver.Service{
			"export.ExportPolicyV1": srv,
		}
		apisrv.RegisterService("export.ExportPolicyV1", srv)
		endpoints := export.MakeExportPolicyV1ServerEndpoints(s.endpointsExportPolicyV1, logger)
		server := export.MakeGRPCServerExportPolicyV1(ctx, endpoints, logger)
		export.RegisterExportPolicyV1Server(grpcserver.GrpcServer, server)
	}
	// Add Watchers
	{

		s.Messages["export.ExportPolicy"].WithKvWatchFunc(func(l log.Logger, options *api.ListWatchOptions, kvs kvstore.Interface, stream interface{}, txfn func(from, to string, i interface{}) (interface{}, error), version, svcprefix string) error {
			o := export.ExportPolicy{}
			key := o.MakeKey(svcprefix)
			wstream := stream.(export.ExportPolicyV1_AutoWatchExportPolicyServer)
			nctx, cancel := context.WithCancel(wstream.Context())
			defer cancel()
			if kvs == nil {
				return fmt.Errorf("Nil KVS")
			}
			watcher, err := kvs.PrefixWatch(nctx, key, options.ResourceVersion)
			if err != nil {
				l.ErrorLog("msg", "error starting Watch on KV", "error", err, "object", "ExportPolicy")
				return err
			}
			for {
				select {
				case ev, ok := <-watcher.EventChan():
					if !ok {
						l.DebugLog("Channel closed for ExportPolicy Watcher")
						return nil
					}
					in, ok := ev.Object.(*export.ExportPolicy)
					if !ok {
						status, ok := ev.Object.(*api.Status)
						if !ok {
							return errors.New("unknown error")
						}
						return fmt.Errorf("%v:(%s) %s", status.Code, status.Result, status.Message)
					}
					strEvent := export.AutoMsgExportPolicyWatchHelper{
						Type:   string(ev.Type),
						Object: in,
					}
					l.DebugLog("msg", "recieved ExportPolicy watch event from KV", "type", ev.Type)
					if version != in.APIVersion {
						i, err := txfn(in.APIVersion, version, in)
						if err != nil {
							l.ErrorLog("msg", "Failed to transform message", "type", "ExportPolicy", "fromver", in.APIVersion, "tover", version)
							break
						}
						strEvent.Object = i.(*export.ExportPolicy)
					}
					l.DebugLog("msg", "writing to stream")
					if err := wstream.Send(&strEvent); err != nil {
						l.DebugLog("msg", "Stream send error'ed for ExportPolicy", "error", err)
						return err
					}
				case <-nctx.Done():
					l.DebugLog("msg", "Context cancelled for ExportPolicy Watcher")
					return wstream.Context().Err()
				}
			}
		})

	}

	return nil
}

func (e *eExportPolicyV1Endpoints) AutoAddExportPolicy(ctx context.Context, t export.ExportPolicy) (export.ExportPolicy, error) {
	r, err := e.fnAutoAddExportPolicy(ctx, t)
	if err == nil {
		return r.(export.ExportPolicy), err
	}
	return export.ExportPolicy{}, err

}
func (e *eExportPolicyV1Endpoints) AutoDeleteExportPolicy(ctx context.Context, t export.ExportPolicy) (export.ExportPolicy, error) {
	r, err := e.fnAutoDeleteExportPolicy(ctx, t)
	if err == nil {
		return r.(export.ExportPolicy), err
	}
	return export.ExportPolicy{}, err

}
func (e *eExportPolicyV1Endpoints) AutoGetExportPolicy(ctx context.Context, t export.ExportPolicy) (export.ExportPolicy, error) {
	r, err := e.fnAutoGetExportPolicy(ctx, t)
	if err == nil {
		return r.(export.ExportPolicy), err
	}
	return export.ExportPolicy{}, err

}
func (e *eExportPolicyV1Endpoints) AutoListExportPolicy(ctx context.Context, t api.ListWatchOptions) (export.ExportPolicyList, error) {
	r, err := e.fnAutoListExportPolicy(ctx, t)
	if err == nil {
		return r.(export.ExportPolicyList), err
	}
	return export.ExportPolicyList{}, err

}
func (e *eExportPolicyV1Endpoints) AutoUpdateExportPolicy(ctx context.Context, t export.ExportPolicy) (export.ExportPolicy, error) {
	r, err := e.fnAutoUpdateExportPolicy(ctx, t)
	if err == nil {
		return r.(export.ExportPolicy), err
	}
	return export.ExportPolicy{}, err

}

func (e *eExportPolicyV1Endpoints) AutoWatchExportPolicy(in *api.ListWatchOptions, stream export.ExportPolicyV1_AutoWatchExportPolicyServer) error {
	return e.fnAutoWatchExportPolicy(in, stream, "exportPolicy")
}

func init() {
	apisrv = apisrvpkg.MustGetAPIServer()

	svc := sexportExportBackend{}

	{
		e := eExportPolicyV1Endpoints{Svc: svc}
		svc.endpointsExportPolicyV1 = &e
	}
	apisrv.Register("export.protos/export.proto", &svc)
}
