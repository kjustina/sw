// Code generated by protoc-gen-grpc-pensando DO NOT EDIT.

/*
Package collectionApiServer is a auto generated package.
Input file: protos/collection.proto
*/
package collectionApiServer

import (
	"context"
	"fmt"
	"time"

	"github.com/gogo/protobuf/types"
	"github.com/pensando/sw/api"
	collection "github.com/pensando/sw/api/generated/collection"
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

type scollectionCollectionBackend struct {
	Services map[string]apiserver.Service
	Messages map[string]apiserver.Message

	endpointsCollectionPolicyV1 *eCollectionPolicyV1Endpoints
}

type eCollectionPolicyV1Endpoints struct {
	Svc scollectionCollectionBackend

	fnAutoAddCollectionPolicy    func(ctx context.Context, t interface{}) (interface{}, error)
	fnAutoDeleteCollectionPolicy func(ctx context.Context, t interface{}) (interface{}, error)
	fnAutoGetCollectionPolicy    func(ctx context.Context, t interface{}) (interface{}, error)
	fnAutoListCollectionPolicy   func(ctx context.Context, t interface{}) (interface{}, error)
	fnAutoUpdateCollectionPolicy func(ctx context.Context, t interface{}) (interface{}, error)

	fnAutoWatchCollectionPolicy func(in *api.ListWatchOptions, stream grpc.ServerStream, svcprefix string) error
}

func (s *scollectionCollectionBackend) CompleteRegistration(ctx context.Context, logger log.Logger,
	grpcserver *rpckit.RPCServer, scheme *runtime.Scheme) error {
	s.Messages = map[string]apiserver.Message{

		"collection.AutoMsgCollectionPolicyWatchHelper": apisrvpkg.NewMessage("collection.AutoMsgCollectionPolicyWatchHelper"),
		"collection.CollectionPolicy": apisrvpkg.NewMessage("collection.CollectionPolicy").WithKeyGenerator(func(i interface{}, prefix string) string {
			if i == nil {
				r := collection.CollectionPolicy{}
				return r.MakeKey(prefix)
			}
			r := i.(collection.CollectionPolicy)
			return r.MakeKey(prefix)
		}).WithObjectVersionWriter(func(i interface{}, version string) interface{} {
			r := i.(collection.CollectionPolicy)
			r.APIVersion = version
			return r
		}).WithKvUpdater(func(ctx context.Context, kvs kvstore.Interface, i interface{}, prefix string, create, ignoreStatus bool) (interface{}, error) {
			r := i.(collection.CollectionPolicy)
			key := r.MakeKey(prefix)
			r.Kind = "CollectionPolicy"
			var err error
			if create {
				err = kvs.Create(ctx, key, &r)
				err = errors.Wrap(err, "KV create failed")
			} else {
				if ignoreStatus {
					updateFunc := func(obj runtime.Object) (runtime.Object, error) {
						saved := obj.(*collection.CollectionPolicy)
						if r.ResourceVersion != "" && r.ResourceVersion != saved.ResourceVersion {
							return nil, fmt.Errorf("Resource Version specified does not match Object version")
						}
						r.Status = saved.Status
						return &r, nil
					}
					into := &collection.CollectionPolicy{}
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
			r := i.(collection.CollectionPolicy)
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
			r := i.(collection.CollectionPolicy)
			r.UUID = uuid.NewV4().String()
			return r, nil
		}).WithCreationTimeWriter(func(i interface{}) (interface{}, error) {
			r := i.(collection.CollectionPolicy)
			var err error
			ts, err := types.TimestampProto(time.Now())
			if err == nil {
				r.CreationTime.Timestamp = *ts
			}
			return r, err
		}).WithModTimeWriter(func(i interface{}) (interface{}, error) {
			r := i.(collection.CollectionPolicy)
			var err error
			ts, err := types.TimestampProto(time.Now())
			if err == nil {
				r.ModTime.Timestamp = *ts
			}
			return r, err
		}).WithKvGetter(func(ctx context.Context, kvs kvstore.Interface, key string) (interface{}, error) {
			r := collection.CollectionPolicy{}
			err := kvs.Get(ctx, key, &r)
			err = errors.Wrap(err, "KV get failed")
			return r, err
		}).WithKvDelFunc(func(ctx context.Context, kvs kvstore.Interface, key string) (interface{}, error) {
			r := collection.CollectionPolicy{}
			err := kvs.Delete(ctx, key, &r)
			return r, err
		}).WithKvTxnDelFunc(func(ctx context.Context, txn kvstore.Txn, key string) error {
			return txn.Delete(key)
		}).WithValidate(func(i interface{}, ver string, ignoreStatus bool) error {
			r := i.(collection.CollectionPolicy)
			if !r.Validate(ver, ignoreStatus) {
				return fmt.Errorf("Default Validation failed")
			}
			return nil
		}),
		"collection.CollectionPolicyList": apisrvpkg.NewMessage("collection.CollectionPolicyList").WithKvListFunc(func(ctx context.Context, kvs kvstore.Interface, options *api.ListWatchOptions, prefix string) (interface{}, error) {

			into := collection.CollectionPolicyList{}
			r := collection.CollectionPolicy{}
			key := r.MakeKey(prefix)
			err := kvs.List(ctx, key, &into)
			if err != nil {
				return nil, err
			}
			return into, nil
		}),
		"collection.CollectionPolicySpec":   apisrvpkg.NewMessage("collection.CollectionPolicySpec"),
		"collection.CollectionPolicyStatus": apisrvpkg.NewMessage("collection.CollectionPolicyStatus"),
		"collection.CollectionTrigger":      apisrvpkg.NewMessage("collection.CollectionTrigger"),
		// Add a message handler for ListWatch options
		"api.ListWatchOptions": apisrvpkg.NewMessage("api.ListWatchOptions"),
	}

	scheme.AddKnownTypes(
		&collection.CollectionPolicy{},
	)

	apisrv.RegisterMessages("collection", s.Messages)

	{
		srv := apisrvpkg.NewService("CollectionPolicyV1")

		s.endpointsCollectionPolicyV1.fnAutoAddCollectionPolicy = srv.AddMethod("AutoAddCollectionPolicy",
			apisrvpkg.NewMethod(s.Messages["collection.CollectionPolicy"], s.Messages["collection.CollectionPolicy"], "collectionPolicy", "AutoAddCollectionPolicy")).WithOper(apiserver.CreateOper).WithVersion("v1").HandleInvocation

		s.endpointsCollectionPolicyV1.fnAutoDeleteCollectionPolicy = srv.AddMethod("AutoDeleteCollectionPolicy",
			apisrvpkg.NewMethod(s.Messages["collection.CollectionPolicy"], s.Messages["collection.CollectionPolicy"], "collectionPolicy", "AutoDeleteCollectionPolicy")).WithOper(apiserver.DeleteOper).WithVersion("v1").HandleInvocation

		s.endpointsCollectionPolicyV1.fnAutoGetCollectionPolicy = srv.AddMethod("AutoGetCollectionPolicy",
			apisrvpkg.NewMethod(s.Messages["collection.CollectionPolicy"], s.Messages["collection.CollectionPolicy"], "collectionPolicy", "AutoGetCollectionPolicy")).WithOper(apiserver.GetOper).WithVersion("v1").HandleInvocation

		s.endpointsCollectionPolicyV1.fnAutoListCollectionPolicy = srv.AddMethod("AutoListCollectionPolicy",
			apisrvpkg.NewMethod(s.Messages["api.ListWatchOptions"], s.Messages["collection.CollectionPolicyList"], "collectionPolicy", "AutoListCollectionPolicy")).WithOper(apiserver.ListOper).WithVersion("v1").HandleInvocation

		s.endpointsCollectionPolicyV1.fnAutoUpdateCollectionPolicy = srv.AddMethod("AutoUpdateCollectionPolicy",
			apisrvpkg.NewMethod(s.Messages["collection.CollectionPolicy"], s.Messages["collection.CollectionPolicy"], "collectionPolicy", "AutoUpdateCollectionPolicy")).WithOper(apiserver.UpdateOper).WithVersion("v1").HandleInvocation

		s.endpointsCollectionPolicyV1.fnAutoWatchCollectionPolicy = s.Messages["collection.CollectionPolicy"].WatchFromKv

		s.Services = map[string]apiserver.Service{
			"collection.CollectionPolicyV1": srv,
		}
		apisrv.RegisterService("collection.CollectionPolicyV1", srv)
		endpoints := collection.MakeCollectionPolicyV1ServerEndpoints(s.endpointsCollectionPolicyV1, logger)
		server := collection.MakeGRPCServerCollectionPolicyV1(ctx, endpoints, logger)
		collection.RegisterCollectionPolicyV1Server(grpcserver.GrpcServer, server)
	}
	// Add Watchers
	{

		s.Messages["collection.CollectionPolicy"].WithKvWatchFunc(func(l log.Logger, options *api.ListWatchOptions, kvs kvstore.Interface, stream interface{}, txfn func(from, to string, i interface{}) (interface{}, error), version, svcprefix string) error {
			o := collection.CollectionPolicy{}
			key := o.MakeKey(svcprefix)
			wstream := stream.(collection.CollectionPolicyV1_AutoWatchCollectionPolicyServer)
			nctx, cancel := context.WithCancel(wstream.Context())
			defer cancel()
			if kvs == nil {
				return fmt.Errorf("Nil KVS")
			}
			watcher, err := kvs.PrefixWatch(nctx, key, options.ResourceVersion)
			if err != nil {
				l.ErrorLog("msg", "error starting Watch on KV", "error", err, "object", "CollectionPolicy")
				return err
			}
			for {
				select {
				case ev, ok := <-watcher.EventChan():
					if !ok {
						l.DebugLog("Channel closed for CollectionPolicy Watcher")
						return nil
					}
					in, ok := ev.Object.(*collection.CollectionPolicy)
					if !ok {
						status, ok := ev.Object.(*api.Status)
						if !ok {
							return errors.New("unknown error")
						}
						return fmt.Errorf("%v:(%s) %s", status.Code, status.Result, status.Message)
					}
					strEvent := collection.AutoMsgCollectionPolicyWatchHelper{
						Type:   string(ev.Type),
						Object: in,
					}
					l.DebugLog("msg", "recieved CollectionPolicy watch event from KV", "type", ev.Type)
					if version != in.APIVersion {
						i, err := txfn(in.APIVersion, version, in)
						if err != nil {
							l.ErrorLog("msg", "Failed to transform message", "type", "CollectionPolicy", "fromver", in.APIVersion, "tover", version)
							break
						}
						strEvent.Object = i.(*collection.CollectionPolicy)
					}
					l.DebugLog("msg", "writing to stream")
					if err := wstream.Send(&strEvent); err != nil {
						l.DebugLog("msg", "Stream send error'ed for CollectionPolicy", "error", err)
						return err
					}
				case <-nctx.Done():
					l.DebugLog("msg", "Context cancelled for CollectionPolicy Watcher")
					return wstream.Context().Err()
				}
			}
		})

	}

	return nil
}

func (e *eCollectionPolicyV1Endpoints) AutoAddCollectionPolicy(ctx context.Context, t collection.CollectionPolicy) (collection.CollectionPolicy, error) {
	r, err := e.fnAutoAddCollectionPolicy(ctx, t)
	if err == nil {
		return r.(collection.CollectionPolicy), err
	}
	return collection.CollectionPolicy{}, err

}
func (e *eCollectionPolicyV1Endpoints) AutoDeleteCollectionPolicy(ctx context.Context, t collection.CollectionPolicy) (collection.CollectionPolicy, error) {
	r, err := e.fnAutoDeleteCollectionPolicy(ctx, t)
	if err == nil {
		return r.(collection.CollectionPolicy), err
	}
	return collection.CollectionPolicy{}, err

}
func (e *eCollectionPolicyV1Endpoints) AutoGetCollectionPolicy(ctx context.Context, t collection.CollectionPolicy) (collection.CollectionPolicy, error) {
	r, err := e.fnAutoGetCollectionPolicy(ctx, t)
	if err == nil {
		return r.(collection.CollectionPolicy), err
	}
	return collection.CollectionPolicy{}, err

}
func (e *eCollectionPolicyV1Endpoints) AutoListCollectionPolicy(ctx context.Context, t api.ListWatchOptions) (collection.CollectionPolicyList, error) {
	r, err := e.fnAutoListCollectionPolicy(ctx, t)
	if err == nil {
		return r.(collection.CollectionPolicyList), err
	}
	return collection.CollectionPolicyList{}, err

}
func (e *eCollectionPolicyV1Endpoints) AutoUpdateCollectionPolicy(ctx context.Context, t collection.CollectionPolicy) (collection.CollectionPolicy, error) {
	r, err := e.fnAutoUpdateCollectionPolicy(ctx, t)
	if err == nil {
		return r.(collection.CollectionPolicy), err
	}
	return collection.CollectionPolicy{}, err

}

func (e *eCollectionPolicyV1Endpoints) AutoWatchCollectionPolicy(in *api.ListWatchOptions, stream collection.CollectionPolicyV1_AutoWatchCollectionPolicyServer) error {
	return e.fnAutoWatchCollectionPolicy(in, stream, "collectionPolicy")
}

func init() {
	apisrv = apisrvpkg.MustGetAPIServer()

	svc := scollectionCollectionBackend{}

	{
		e := eCollectionPolicyV1Endpoints{Svc: svc}
		svc.endpointsCollectionPolicyV1 = &e
	}
	apisrv.Register("collection.protos/collection.proto", &svc)
}
