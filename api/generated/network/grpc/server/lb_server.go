// Code generated by protoc-gen-grpc-pensando DO NOT EDIT.

/*
Package networkApiServer is a auto generated package.
Input file: lb.proto
*/
package networkApiServer

import (
	"context"
	"fmt"
	"strconv"
	"time"

	"github.com/gogo/protobuf/types"
	"github.com/pkg/errors"
	"github.com/satori/go.uuid"

	"github.com/pensando/sw/api"
	"github.com/pensando/sw/api/cache"
	network "github.com/pensando/sw/api/generated/network"
	fieldhooks "github.com/pensando/sw/api/hooks/apiserver/fields"
	"github.com/pensando/sw/api/interfaces"
	"github.com/pensando/sw/api/listerwatcher"
	"github.com/pensando/sw/venice/apiserver"
	"github.com/pensando/sw/venice/apiserver/pkg"
	"github.com/pensando/sw/venice/utils/kvstore"
	"github.com/pensando/sw/venice/utils/log"
	"github.com/pensando/sw/venice/utils/rpckit"
	"github.com/pensando/sw/venice/utils/runtime"
)

// dummy vars to suppress unused errors
var _ api.ObjectMeta
var _ listerwatcher.WatcherClient
var _ fmt.Stringer
var _ fieldhooks.Dummy

type snetworkLbBackend struct {
	Services map[string]apiserver.Service
	Messages map[string]apiserver.Message
	logger   log.Logger
	scheme   *runtime.Scheme
}

func (s *snetworkLbBackend) regMsgsFunc(l log.Logger, scheme *runtime.Scheme) {
	l.Infof("registering message for snetworkLbBackend")
	s.Messages = map[string]apiserver.Message{

		"network.HealthCheckSpec": apisrvpkg.NewMessage("network.HealthCheckSpec"),
		"network.LbPolicy": apisrvpkg.NewMessage("network.LbPolicy").WithKeyGenerator(func(i interface{}, prefix string) string {
			if i == nil {
				r := network.LbPolicy{}
				return r.MakeKey(prefix)
			}
			r := i.(network.LbPolicy)
			return r.MakeKey(prefix)
		}).WithObjectVersionWriter(func(i interface{}, version string) interface{} {
			r := i.(network.LbPolicy)
			r.Kind = "LbPolicy"
			r.APIVersion = version
			return r
		}).WithKvUpdater(func(ctx context.Context, kvs kvstore.Interface, i interface{}, prefix string, create bool, updateFn kvstore.UpdateFunc) (interface{}, error) {
			r := i.(network.LbPolicy)
			key := r.MakeKey(prefix)
			r.Kind = "LbPolicy"
			var err error
			if create {
				if updateFn != nil {
					upd := &network.LbPolicy{}
					n, err := updateFn(upd)
					if err != nil {
						l.ErrorLog("msg", "could not create new object", "error", err)
						return nil, err
					}
					new := n.(*network.LbPolicy)
					new.TypeMeta = r.TypeMeta
					new.GenerationID = "1"
					new.UUID = r.UUID
					new.CreationTime = r.CreationTime
					new.SelfLink = r.SelfLink
					r = *new
				} else {
					r.GenerationID = "1"
				}
				err = kvs.Create(ctx, key, &r)
				if err != nil {
					l.ErrorLog("msg", "KV create failed", "key", key, "error", err)
				}
			} else {
				if updateFn != nil {
					into := &network.LbPolicy{}
					err = kvs.ConsistentUpdate(ctx, key, into, updateFn)
					if err != nil {
						l.ErrorLog("msg", "Consistent update failed", "error", err)
					}
					r = *into
				} else {
					var cur network.LbPolicy
					err = kvs.Get(ctx, key, &cur)
					if err != nil {
						l.ErrorLog("msg", "trying to update an object that does not exist", "key", key, "error", err)
						return nil, err
					}
					r.UUID = cur.UUID
					r.CreationTime = cur.CreationTime
					if r.ResourceVersion != "" {
						l.Infof("resource version is specified %s\n", r.ResourceVersion)
						err = kvs.Update(ctx, key, &r, kvstore.Compare(kvstore.WithVersion(key), "=", r.ResourceVersion))
					} else {
						err = kvs.Update(ctx, key, &r)
					}
					if err != nil {
						l.ErrorLog("msg", "KV update failed", "key", key, "error", err)
					}
				}

			}
			return r, err
		}).WithKvTxnUpdater(func(ctx context.Context, kvs kvstore.Interface, txn kvstore.Txn, i interface{}, prefix string, create bool, updatefn kvstore.UpdateFunc) error {
			r := i.(network.LbPolicy)
			key := r.MakeKey(prefix)
			var err error
			if create {
				if updatefn != nil {
					upd := &network.LbPolicy{}
					n, err := updatefn(upd)
					if err != nil {
						l.ErrorLog("msg", "could not create new object", "error", err)
						return err
					}
					new := n.(*network.LbPolicy)
					new.TypeMeta = r.TypeMeta
					new.GenerationID = "1"
					new.UUID = r.UUID
					new.CreationTime = r.CreationTime
					new.SelfLink = r.SelfLink
					r = *new
				} else {
					r.GenerationID = "1"
				}
				err = txn.Create(key, &r)
				if err != nil {
					l.ErrorLog("msg", "KV transaction create failed", "key", key, "error", err)
				}
			} else {
				if updatefn != nil {
					var cur network.LbPolicy
					err = kvs.Get(ctx, key, &cur)
					if err != nil {
						l.ErrorLog("msg", "trying to update an object that does not exist", "key", key, "error", err)
						return err
					}
					robj, err := updatefn(&cur)
					if err != nil {
						l.ErrorLog("msg", "unable to update current object", "key", key, "error", err)
						return err
					}
					r = *robj.(*network.LbPolicy)
					txn.AddComparator(kvstore.Compare(kvstore.WithVersion(key), "=", r.ResourceVersion))
				} else {
					var cur network.LbPolicy
					err = kvs.Get(ctx, key, &cur)
					if err != nil {
						l.ErrorLog("msg", "trying to update an object that does not exist", "key", key, "error", err)
						return err
					}
					r.UUID = cur.UUID
					r.CreationTime = cur.CreationTime
					if _, err := strconv.ParseUint(r.GenerationID, 10, 64); err != nil {
						r.GenerationID = cur.GenerationID
						_, err := strconv.ParseUint(cur.GenerationID, 10, 64)
						if err != nil {
							// Cant recover ID!!, reset ID
							r.GenerationID = "2"
						}
					}
				}
				err = txn.Update(key, &r)
				if err != nil {
					l.ErrorLog("msg", "KV transaction update failed", "key", key, "error", err)
				}
			}
			return err
		}).WithUUIDWriter(func(i interface{}) (interface{}, error) {
			r := i.(network.LbPolicy)
			r.UUID = uuid.NewV4().String()
			return r, nil
		}).WithCreationTimeWriter(func(i interface{}) (interface{}, error) {
			r := i.(network.LbPolicy)
			var err error
			ts, err := types.TimestampProto(time.Now())
			if err == nil {
				r.CreationTime.Timestamp = *ts
			}
			return r, err
		}).WithModTimeWriter(func(i interface{}) (interface{}, error) {
			r := i.(network.LbPolicy)
			var err error
			ts, err := types.TimestampProto(time.Now())
			if err == nil {
				r.ModTime.Timestamp = *ts
			}
			return r, err
		}).WithSelfLinkWriter(func(path, ver, prefix string, i interface{}) (interface{}, error) {
			r := i.(network.LbPolicy)
			r.SelfLink = path
			return r, nil
		}).WithKvGetter(func(ctx context.Context, kvs kvstore.Interface, key string) (interface{}, error) {
			r := network.LbPolicy{}
			err := kvs.Get(ctx, key, &r)
			if err != nil {
				l.ErrorLog("msg", "Object get failed", "key", key, "error", err)
			}
			return r, err
		}).WithKvDelFunc(func(ctx context.Context, kvs kvstore.Interface, key string) (interface{}, error) {
			r := network.LbPolicy{}
			err := kvs.Delete(ctx, key, &r)
			if err != nil {
				l.ErrorLog("msg", "Object delete failed", "key", key, "error", err)
			}
			return r, err
		}).WithKvTxnDelFunc(func(ctx context.Context, txn kvstore.Txn, key string) error {
			err := txn.Delete(key)
			if err != nil {
				l.ErrorLog("msg", "Object Txn delete failed", "key", key, "error", err)
			}
			return err
		}).WithGetRuntimeObject(func(i interface{}) runtime.Object {
			r := i.(network.LbPolicy)
			return &r
		}).WithValidate(func(i interface{}, ver string, ignoreStatus bool) []error {
			r := i.(network.LbPolicy)
			return r.Validate(ver, "", ignoreStatus)
		}).WithReferencesGetter(func(i interface{}) (map[string]apiintf.ReferenceObj, error) {
			ret := make(map[string]apiintf.ReferenceObj)
			r := i.(network.LbPolicy)

			tenant := r.Tenant
			r.References(tenant, "", ret)
			return ret, nil
		}).WithUpdateMetaFunction(func(ctx context.Context, i interface{}, create bool) kvstore.UpdateFunc {
			var n *network.LbPolicy
			if v, ok := i.(network.LbPolicy); ok {
				n = &v
			} else if v, ok := i.(*network.LbPolicy); ok {
				n = v
			} else {
				return nil
			}
			return func(oldObj runtime.Object) (runtime.Object, error) {
				if create {
					n.UUID = uuid.NewV4().String()
					ts, err := types.TimestampProto(time.Now())
					if err != nil {
						return nil, err
					}
					n.CreationTime.Timestamp = *ts
					n.ModTime.Timestamp = *ts
					n.GenerationID = "1"
					return n, nil
				}
				if oldObj == nil {
					return nil, errors.New("nil object")
				}
				o := oldObj.(*network.LbPolicy)
				n.UUID, n.CreationTime, n.Namespace, n.GenerationID = o.UUID, o.CreationTime, o.Namespace, o.GenerationID
				ts, err := types.TimestampProto(time.Now())
				if err != nil {
					return nil, err
				}
				n.ModTime.Timestamp = *ts
				return n, nil
			}
		}).WithReplaceSpecFunction(func(ctx context.Context, i interface{}) kvstore.UpdateFunc {
			var n *network.LbPolicy
			if v, ok := i.(network.LbPolicy); ok {
				n = &v
			} else if v, ok := i.(*network.LbPolicy); ok {
				n = v
			} else {
				return nil
			}
			dryRun := cache.IsDryRun(ctx)
			return func(oldObj runtime.Object) (runtime.Object, error) {
				if oldObj == nil {
					rete := &network.LbPolicy{}
					rete.TypeMeta, rete.ObjectMeta, rete.Spec = n.TypeMeta, n.ObjectMeta, n.Spec
					rete.GenerationID = "1"
					return rete, nil
				}
				if ret, ok := oldObj.(*network.LbPolicy); ok {
					ret.Name, ret.Tenant, ret.Namespace, ret.Labels, ret.ModTime, ret.SelfLink = n.Name, n.Tenant, n.Namespace, n.Labels, n.ModTime, n.SelfLink
					if !dryRun {
						gen, err := strconv.ParseUint(ret.GenerationID, 10, 64)
						if err != nil {
							l.ErrorLog("msg", "invalid GenerationID, reset gen ID", "generation", ret.GenerationID, "error", err)
							ret.GenerationID = "2"
						} else {
							ret.GenerationID = fmt.Sprintf("%d", gen+1)
						}
					}
					ret.Spec = n.Spec
					return ret, nil
				}
				return nil, errors.New("invalid object")
			}
		}).WithReplaceStatusFunction(func(i interface{}) kvstore.UpdateFunc {
			var n *network.LbPolicy
			if v, ok := i.(network.LbPolicy); ok {
				n = &v
			} else if v, ok := i.(*network.LbPolicy); ok {
				n = v
			} else {
				return nil
			}
			return func(oldObj runtime.Object) (runtime.Object, error) {
				if ret, ok := oldObj.(*network.LbPolicy); ok {
					ret.Status = n.Status
					return ret, nil
				}
				return nil, errors.New("invalid object")
			}
		}),

		"network.LbPolicySpec":   apisrvpkg.NewMessage("network.LbPolicySpec"),
		"network.LbPolicyStatus": apisrvpkg.NewMessage("network.LbPolicyStatus"),
		// Add a message handler for ListWatch options
		"api.ListWatchOptions": apisrvpkg.NewMessage("api.ListWatchOptions"),
	}

	apisrv.RegisterMessages("network", s.Messages)
	// add messages to package.
	if pkgMessages == nil {
		pkgMessages = make(map[string]apiserver.Message)
	}
	for k, v := range s.Messages {
		pkgMessages[k] = v
	}
}

func (s *snetworkLbBackend) regSvcsFunc(ctx context.Context, logger log.Logger, grpcserver *rpckit.RPCServer, scheme *runtime.Scheme) {

}

func (s *snetworkLbBackend) regWatchersFunc(ctx context.Context, logger log.Logger, grpcserver *rpckit.RPCServer, scheme *runtime.Scheme) {

}

func (s *snetworkLbBackend) CompleteRegistration(ctx context.Context, logger log.Logger,
	grpcserver *rpckit.RPCServer, scheme *runtime.Scheme) error {
	// register all messages in the package if not done already
	s.logger = logger
	s.scheme = scheme
	registerMessages(logger, scheme)
	registerServices(ctx, logger, grpcserver, scheme)
	registerWatchers(ctx, logger, grpcserver, scheme)
	return nil
}

func (s *snetworkLbBackend) Reset() {
	cleanupRegistration()
}

func init() {
	apisrv = apisrvpkg.MustGetAPIServer()

	svc := snetworkLbBackend{}
	addMsgRegFunc(svc.regMsgsFunc)
	addSvcRegFunc(svc.regSvcsFunc)
	addWatcherRegFunc(svc.regWatchersFunc)

	apisrv.Register("network.lb.proto", &svc)
}
