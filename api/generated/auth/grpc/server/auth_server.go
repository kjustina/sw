// Code generated by protoc-gen-grpc-pensando DO NOT EDIT.

/*
Package authApiServer is a auto generated package.
Input file: protos/auth.proto
*/
package authApiServer

import (
	"context"
	"fmt"
	"time"

	"github.com/gogo/protobuf/types"
	"github.com/pensando/sw/api"
	auth "github.com/pensando/sw/api/generated/auth"
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

type sauthAuthBackend struct {
	Services map[string]apiserver.Service
	Messages map[string]apiserver.Message

	endpointsAuthV1 *eAuthV1Endpoints
}

type eAuthV1Endpoints struct {
	Svc sauthAuthBackend

	fnAutoAddAuthenticationPolicy    func(ctx context.Context, t interface{}) (interface{}, error)
	fnAutoAddUser                    func(ctx context.Context, t interface{}) (interface{}, error)
	fnAutoDeleteAuthenticationPolicy func(ctx context.Context, t interface{}) (interface{}, error)
	fnAutoDeleteUser                 func(ctx context.Context, t interface{}) (interface{}, error)
	fnAutoGetAuthenticationPolicy    func(ctx context.Context, t interface{}) (interface{}, error)
	fnAutoGetUser                    func(ctx context.Context, t interface{}) (interface{}, error)
	fnAutoListAuthenticationPolicy   func(ctx context.Context, t interface{}) (interface{}, error)
	fnAutoListUser                   func(ctx context.Context, t interface{}) (interface{}, error)
	fnAutoUpdateAuthenticationPolicy func(ctx context.Context, t interface{}) (interface{}, error)
	fnAutoUpdateUser                 func(ctx context.Context, t interface{}) (interface{}, error)

	fnAutoWatchUser                 func(in *api.ListWatchOptions, stream grpc.ServerStream, svcprefix string) error
	fnAutoWatchAuthenticationPolicy func(in *api.ListWatchOptions, stream grpc.ServerStream, svcprefix string) error
}

func (s *sauthAuthBackend) CompleteRegistration(ctx context.Context, logger log.Logger,
	grpcserver *rpckit.RPCServer, scheme *runtime.Scheme) error {
	s.Messages = map[string]apiserver.Message{

		"auth.AuthenticationPolicy": apisrvpkg.NewMessage("auth.AuthenticationPolicy").WithKeyGenerator(func(i interface{}, prefix string) string {
			if i == nil {
				r := auth.AuthenticationPolicy{}
				return r.MakeKey(prefix)
			}
			r := i.(auth.AuthenticationPolicy)
			return r.MakeKey(prefix)
		}).WithObjectVersionWriter(func(i interface{}, version string) interface{} {
			r := i.(auth.AuthenticationPolicy)
			r.APIVersion = version
			return r
		}).WithKvUpdater(func(ctx context.Context, kvs kvstore.Interface, i interface{}, prefix string, create, ignoreStatus bool) (interface{}, error) {
			r := i.(auth.AuthenticationPolicy)
			key := r.MakeKey(prefix)
			r.Kind = "AuthenticationPolicy"
			var err error
			if create {
				err = kvs.Create(ctx, key, &r)
				err = errors.Wrap(err, "KV create failed")
			} else {
				if ignoreStatus {
					updateFunc := func(obj runtime.Object) (runtime.Object, error) {
						saved := obj.(*auth.AuthenticationPolicy)
						if r.ResourceVersion != "" && r.ResourceVersion != saved.ResourceVersion {
							return nil, fmt.Errorf("Resource Version specified does not match Object version")
						}
						r.Status = saved.Status
						return &r, nil
					}
					into := &auth.AuthenticationPolicy{}
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
			r := i.(auth.AuthenticationPolicy)
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
			r := i.(auth.AuthenticationPolicy)
			r.UUID = uuid.NewV4().String()
			return r, nil
		}).WithCreationTimeWriter(func(i interface{}) (interface{}, error) {
			r := i.(auth.AuthenticationPolicy)
			var err error
			ts, err := types.TimestampProto(time.Now())
			if err == nil {
				r.CreationTime.Timestamp = *ts
			}
			return r, err
		}).WithModTimeWriter(func(i interface{}) (interface{}, error) {
			r := i.(auth.AuthenticationPolicy)
			var err error
			ts, err := types.TimestampProto(time.Now())
			if err == nil {
				r.ModTime.Timestamp = *ts
			}
			return r, err
		}).WithKvGetter(func(ctx context.Context, kvs kvstore.Interface, key string) (interface{}, error) {
			r := auth.AuthenticationPolicy{}
			err := kvs.Get(ctx, key, &r)
			err = errors.Wrap(err, "KV get failed")
			return r, err
		}).WithKvDelFunc(func(ctx context.Context, kvs kvstore.Interface, key string) (interface{}, error) {
			r := auth.AuthenticationPolicy{}
			err := kvs.Delete(ctx, key, &r)
			return r, err
		}).WithKvTxnDelFunc(func(ctx context.Context, txn kvstore.Txn, key string) error {
			return txn.Delete(key)
		}).WithValidate(func(i interface{}, ver string, ignoreStatus bool) error {
			r := i.(auth.AuthenticationPolicy)
			if !r.Validate(ver, ignoreStatus) {
				return fmt.Errorf("Default Validation failed")
			}
			return nil
		}),
		"auth.AuthenticationPolicyList": apisrvpkg.NewMessage("auth.AuthenticationPolicyList").WithKvListFunc(func(ctx context.Context, kvs kvstore.Interface, options *api.ListWatchOptions, prefix string) (interface{}, error) {

			into := auth.AuthenticationPolicyList{}
			r := auth.AuthenticationPolicy{}
			key := r.MakeKey(prefix)
			err := kvs.List(ctx, key, &into)
			if err != nil {
				return nil, err
			}
			return into, nil
		}),
		"auth.AuthenticationPolicySpec":               apisrvpkg.NewMessage("auth.AuthenticationPolicySpec"),
		"auth.AuthenticationPolicyStatus":             apisrvpkg.NewMessage("auth.AuthenticationPolicyStatus"),
		"auth.Authenticators":                         apisrvpkg.NewMessage("auth.Authenticators"),
		"auth.AutoMsgAuthenticationPolicyWatchHelper": apisrvpkg.NewMessage("auth.AutoMsgAuthenticationPolicyWatchHelper"),
		"auth.AutoMsgUserWatchHelper":                 apisrvpkg.NewMessage("auth.AutoMsgUserWatchHelper"),
		"auth.Ldap":                                   apisrvpkg.NewMessage("auth.Ldap"),
		"auth.LdapAttributeMapping":                   apisrvpkg.NewMessage("auth.LdapAttributeMapping"),
		"auth.Local":                                  apisrvpkg.NewMessage("auth.Local"),
		"auth.Radius":                                 apisrvpkg.NewMessage("auth.Radius"),
		"auth.TLSOptions":                             apisrvpkg.NewMessage("auth.TLSOptions"),
		"auth.User": apisrvpkg.NewMessage("auth.User").WithKeyGenerator(func(i interface{}, prefix string) string {
			if i == nil {
				r := auth.User{}
				return r.MakeKey(prefix)
			}
			r := i.(auth.User)
			return r.MakeKey(prefix)
		}).WithObjectVersionWriter(func(i interface{}, version string) interface{} {
			r := i.(auth.User)
			r.APIVersion = version
			return r
		}).WithKvUpdater(func(ctx context.Context, kvs kvstore.Interface, i interface{}, prefix string, create, ignoreStatus bool) (interface{}, error) {
			r := i.(auth.User)
			key := r.MakeKey(prefix)
			r.Kind = "User"
			var err error
			if create {
				err = kvs.Create(ctx, key, &r)
				err = errors.Wrap(err, "KV create failed")
			} else {
				if ignoreStatus {
					updateFunc := func(obj runtime.Object) (runtime.Object, error) {
						saved := obj.(*auth.User)
						if r.ResourceVersion != "" && r.ResourceVersion != saved.ResourceVersion {
							return nil, fmt.Errorf("Resource Version specified does not match Object version")
						}
						r.Status = saved.Status
						return &r, nil
					}
					into := &auth.User{}
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
			r := i.(auth.User)
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
			r := i.(auth.User)
			r.UUID = uuid.NewV4().String()
			return r, nil
		}).WithCreationTimeWriter(func(i interface{}) (interface{}, error) {
			r := i.(auth.User)
			var err error
			ts, err := types.TimestampProto(time.Now())
			if err == nil {
				r.CreationTime.Timestamp = *ts
			}
			return r, err
		}).WithModTimeWriter(func(i interface{}) (interface{}, error) {
			r := i.(auth.User)
			var err error
			ts, err := types.TimestampProto(time.Now())
			if err == nil {
				r.ModTime.Timestamp = *ts
			}
			return r, err
		}).WithKvGetter(func(ctx context.Context, kvs kvstore.Interface, key string) (interface{}, error) {
			r := auth.User{}
			err := kvs.Get(ctx, key, &r)
			err = errors.Wrap(err, "KV get failed")
			return r, err
		}).WithKvDelFunc(func(ctx context.Context, kvs kvstore.Interface, key string) (interface{}, error) {
			r := auth.User{}
			err := kvs.Delete(ctx, key, &r)
			return r, err
		}).WithKvTxnDelFunc(func(ctx context.Context, txn kvstore.Txn, key string) error {
			return txn.Delete(key)
		}).WithValidate(func(i interface{}, ver string, ignoreStatus bool) error {
			r := i.(auth.User)
			if !r.Validate(ver, ignoreStatus) {
				return fmt.Errorf("Default Validation failed")
			}
			return nil
		}),
		"auth.UserList": apisrvpkg.NewMessage("auth.UserList").WithKvListFunc(func(ctx context.Context, kvs kvstore.Interface, options *api.ListWatchOptions, prefix string) (interface{}, error) {

			into := auth.UserList{}
			r := auth.User{}
			key := r.MakeKey(prefix)
			err := kvs.List(ctx, key, &into)
			if err != nil {
				return nil, err
			}
			return into, nil
		}),
		"auth.UserSpec":   apisrvpkg.NewMessage("auth.UserSpec"),
		"auth.UserStatus": apisrvpkg.NewMessage("auth.UserStatus"),
		// Add a message handler for ListWatch options
		"api.ListWatchOptions": apisrvpkg.NewMessage("api.ListWatchOptions"),
	}

	scheme.AddKnownTypes(
		&auth.AuthenticationPolicy{},
		&auth.User{},
	)

	apisrv.RegisterMessages("auth", s.Messages)

	{
		srv := apisrvpkg.NewService("AuthV1")

		s.endpointsAuthV1.fnAutoAddAuthenticationPolicy = srv.AddMethod("AutoAddAuthenticationPolicy",
			apisrvpkg.NewMethod(s.Messages["auth.AuthenticationPolicy"], s.Messages["auth.AuthenticationPolicy"], "auth", "AutoAddAuthenticationPolicy")).WithOper(apiserver.CreateOper).WithVersion("v1").HandleInvocation

		s.endpointsAuthV1.fnAutoAddUser = srv.AddMethod("AutoAddUser",
			apisrvpkg.NewMethod(s.Messages["auth.User"], s.Messages["auth.User"], "auth", "AutoAddUser")).WithOper(apiserver.CreateOper).WithVersion("v1").HandleInvocation

		s.endpointsAuthV1.fnAutoDeleteAuthenticationPolicy = srv.AddMethod("AutoDeleteAuthenticationPolicy",
			apisrvpkg.NewMethod(s.Messages["auth.AuthenticationPolicy"], s.Messages["auth.AuthenticationPolicy"], "auth", "AutoDeleteAuthenticationPolicy")).WithOper(apiserver.DeleteOper).WithVersion("v1").HandleInvocation

		s.endpointsAuthV1.fnAutoDeleteUser = srv.AddMethod("AutoDeleteUser",
			apisrvpkg.NewMethod(s.Messages["auth.User"], s.Messages["auth.User"], "auth", "AutoDeleteUser")).WithOper(apiserver.DeleteOper).WithVersion("v1").HandleInvocation

		s.endpointsAuthV1.fnAutoGetAuthenticationPolicy = srv.AddMethod("AutoGetAuthenticationPolicy",
			apisrvpkg.NewMethod(s.Messages["auth.AuthenticationPolicy"], s.Messages["auth.AuthenticationPolicy"], "auth", "AutoGetAuthenticationPolicy")).WithOper(apiserver.GetOper).WithVersion("v1").HandleInvocation

		s.endpointsAuthV1.fnAutoGetUser = srv.AddMethod("AutoGetUser",
			apisrvpkg.NewMethod(s.Messages["auth.User"], s.Messages["auth.User"], "auth", "AutoGetUser")).WithOper(apiserver.GetOper).WithVersion("v1").HandleInvocation

		s.endpointsAuthV1.fnAutoListAuthenticationPolicy = srv.AddMethod("AutoListAuthenticationPolicy",
			apisrvpkg.NewMethod(s.Messages["api.ListWatchOptions"], s.Messages["auth.AuthenticationPolicyList"], "auth", "AutoListAuthenticationPolicy")).WithOper(apiserver.ListOper).WithVersion("v1").HandleInvocation

		s.endpointsAuthV1.fnAutoListUser = srv.AddMethod("AutoListUser",
			apisrvpkg.NewMethod(s.Messages["api.ListWatchOptions"], s.Messages["auth.UserList"], "auth", "AutoListUser")).WithOper(apiserver.ListOper).WithVersion("v1").HandleInvocation

		s.endpointsAuthV1.fnAutoUpdateAuthenticationPolicy = srv.AddMethod("AutoUpdateAuthenticationPolicy",
			apisrvpkg.NewMethod(s.Messages["auth.AuthenticationPolicy"], s.Messages["auth.AuthenticationPolicy"], "auth", "AutoUpdateAuthenticationPolicy")).WithOper(apiserver.UpdateOper).WithVersion("v1").HandleInvocation

		s.endpointsAuthV1.fnAutoUpdateUser = srv.AddMethod("AutoUpdateUser",
			apisrvpkg.NewMethod(s.Messages["auth.User"], s.Messages["auth.User"], "auth", "AutoUpdateUser")).WithOper(apiserver.UpdateOper).WithVersion("v1").HandleInvocation

		s.endpointsAuthV1.fnAutoWatchUser = s.Messages["auth.User"].WatchFromKv

		s.endpointsAuthV1.fnAutoWatchAuthenticationPolicy = s.Messages["auth.AuthenticationPolicy"].WatchFromKv

		s.Services = map[string]apiserver.Service{
			"auth.AuthV1": srv,
		}
		apisrv.RegisterService("auth.AuthV1", srv)
		endpoints := auth.MakeAuthV1ServerEndpoints(s.endpointsAuthV1, logger)
		server := auth.MakeGRPCServerAuthV1(ctx, endpoints, logger)
		auth.RegisterAuthV1Server(grpcserver.GrpcServer, server)
	}
	// Add Watchers
	{

		s.Messages["auth.User"].WithKvWatchFunc(func(l log.Logger, options *api.ListWatchOptions, kvs kvstore.Interface, stream interface{}, txfn func(from, to string, i interface{}) (interface{}, error), version, svcprefix string) error {
			o := auth.User{}
			key := o.MakeKey(svcprefix)
			wstream := stream.(auth.AuthV1_AutoWatchUserServer)
			nctx, cancel := context.WithCancel(wstream.Context())
			defer cancel()
			if kvs == nil {
				return fmt.Errorf("Nil KVS")
			}
			watcher, err := kvs.PrefixWatch(nctx, key, options.ResourceVersion)
			if err != nil {
				l.ErrorLog("msg", "error starting Watch on KV", "error", err, "object", "User")
				return err
			}
			for {
				select {
				case ev, ok := <-watcher.EventChan():
					if !ok {
						l.DebugLog("Channel closed for User Watcher")
						return nil
					}
					in, ok := ev.Object.(*auth.User)
					if !ok {
						status, ok := ev.Object.(*api.Status)
						if !ok {
							return errors.New("unknown error")
						}
						return fmt.Errorf("%v:(%s) %s", status.Code, status.Result, status.Message)
					}
					strEvent := auth.AutoMsgUserWatchHelper{
						Type:   string(ev.Type),
						Object: in,
					}
					l.DebugLog("msg", "received User watch event from KV", "type", ev.Type)
					if version != in.APIVersion {
						i, err := txfn(in.APIVersion, version, in)
						if err != nil {
							l.ErrorLog("msg", "Failed to transform message", "type", "User", "fromver", in.APIVersion, "tover", version)
							break
						}
						strEvent.Object = i.(*auth.User)
					}
					l.DebugLog("msg", "writing to stream")
					if err := wstream.Send(&strEvent); err != nil {
						l.DebugLog("msg", "Stream send error'ed for User", "error", err)
						return err
					}
				case <-nctx.Done():
					l.DebugLog("msg", "Context cancelled for User Watcher")
					return wstream.Context().Err()
				}
			}
		})

		s.Messages["auth.AuthenticationPolicy"].WithKvWatchFunc(func(l log.Logger, options *api.ListWatchOptions, kvs kvstore.Interface, stream interface{}, txfn func(from, to string, i interface{}) (interface{}, error), version, svcprefix string) error {
			o := auth.AuthenticationPolicy{}
			key := o.MakeKey(svcprefix)
			wstream := stream.(auth.AuthV1_AutoWatchAuthenticationPolicyServer)
			nctx, cancel := context.WithCancel(wstream.Context())
			defer cancel()
			if kvs == nil {
				return fmt.Errorf("Nil KVS")
			}
			watcher, err := kvs.PrefixWatch(nctx, key, options.ResourceVersion)
			if err != nil {
				l.ErrorLog("msg", "error starting Watch on KV", "error", err, "object", "AuthenticationPolicy")
				return err
			}
			for {
				select {
				case ev, ok := <-watcher.EventChan():
					if !ok {
						l.DebugLog("Channel closed for AuthenticationPolicy Watcher")
						return nil
					}
					in, ok := ev.Object.(*auth.AuthenticationPolicy)
					if !ok {
						status, ok := ev.Object.(*api.Status)
						if !ok {
							return errors.New("unknown error")
						}
						return fmt.Errorf("%v:(%s) %s", status.Code, status.Result, status.Message)
					}
					strEvent := auth.AutoMsgAuthenticationPolicyWatchHelper{
						Type:   string(ev.Type),
						Object: in,
					}
					l.DebugLog("msg", "received AuthenticationPolicy watch event from KV", "type", ev.Type)
					if version != in.APIVersion {
						i, err := txfn(in.APIVersion, version, in)
						if err != nil {
							l.ErrorLog("msg", "Failed to transform message", "type", "AuthenticationPolicy", "fromver", in.APIVersion, "tover", version)
							break
						}
						strEvent.Object = i.(*auth.AuthenticationPolicy)
					}
					l.DebugLog("msg", "writing to stream")
					if err := wstream.Send(&strEvent); err != nil {
						l.DebugLog("msg", "Stream send error'ed for AuthenticationPolicy", "error", err)
						return err
					}
				case <-nctx.Done():
					l.DebugLog("msg", "Context cancelled for AuthenticationPolicy Watcher")
					return wstream.Context().Err()
				}
			}
		})

	}

	return nil
}

func (e *eAuthV1Endpoints) AutoAddAuthenticationPolicy(ctx context.Context, t auth.AuthenticationPolicy) (auth.AuthenticationPolicy, error) {
	r, err := e.fnAutoAddAuthenticationPolicy(ctx, t)
	if err == nil {
		return r.(auth.AuthenticationPolicy), err
	}
	return auth.AuthenticationPolicy{}, err

}
func (e *eAuthV1Endpoints) AutoAddUser(ctx context.Context, t auth.User) (auth.User, error) {
	r, err := e.fnAutoAddUser(ctx, t)
	if err == nil {
		return r.(auth.User), err
	}
	return auth.User{}, err

}
func (e *eAuthV1Endpoints) AutoDeleteAuthenticationPolicy(ctx context.Context, t auth.AuthenticationPolicy) (auth.AuthenticationPolicy, error) {
	r, err := e.fnAutoDeleteAuthenticationPolicy(ctx, t)
	if err == nil {
		return r.(auth.AuthenticationPolicy), err
	}
	return auth.AuthenticationPolicy{}, err

}
func (e *eAuthV1Endpoints) AutoDeleteUser(ctx context.Context, t auth.User) (auth.User, error) {
	r, err := e.fnAutoDeleteUser(ctx, t)
	if err == nil {
		return r.(auth.User), err
	}
	return auth.User{}, err

}
func (e *eAuthV1Endpoints) AutoGetAuthenticationPolicy(ctx context.Context, t auth.AuthenticationPolicy) (auth.AuthenticationPolicy, error) {
	r, err := e.fnAutoGetAuthenticationPolicy(ctx, t)
	if err == nil {
		return r.(auth.AuthenticationPolicy), err
	}
	return auth.AuthenticationPolicy{}, err

}
func (e *eAuthV1Endpoints) AutoGetUser(ctx context.Context, t auth.User) (auth.User, error) {
	r, err := e.fnAutoGetUser(ctx, t)
	if err == nil {
		return r.(auth.User), err
	}
	return auth.User{}, err

}
func (e *eAuthV1Endpoints) AutoListAuthenticationPolicy(ctx context.Context, t api.ListWatchOptions) (auth.AuthenticationPolicyList, error) {
	r, err := e.fnAutoListAuthenticationPolicy(ctx, t)
	if err == nil {
		return r.(auth.AuthenticationPolicyList), err
	}
	return auth.AuthenticationPolicyList{}, err

}
func (e *eAuthV1Endpoints) AutoListUser(ctx context.Context, t api.ListWatchOptions) (auth.UserList, error) {
	r, err := e.fnAutoListUser(ctx, t)
	if err == nil {
		return r.(auth.UserList), err
	}
	return auth.UserList{}, err

}
func (e *eAuthV1Endpoints) AutoUpdateAuthenticationPolicy(ctx context.Context, t auth.AuthenticationPolicy) (auth.AuthenticationPolicy, error) {
	r, err := e.fnAutoUpdateAuthenticationPolicy(ctx, t)
	if err == nil {
		return r.(auth.AuthenticationPolicy), err
	}
	return auth.AuthenticationPolicy{}, err

}
func (e *eAuthV1Endpoints) AutoUpdateUser(ctx context.Context, t auth.User) (auth.User, error) {
	r, err := e.fnAutoUpdateUser(ctx, t)
	if err == nil {
		return r.(auth.User), err
	}
	return auth.User{}, err

}

func (e *eAuthV1Endpoints) AutoWatchUser(in *api.ListWatchOptions, stream auth.AuthV1_AutoWatchUserServer) error {
	return e.fnAutoWatchUser(in, stream, "auth")
}
func (e *eAuthV1Endpoints) AutoWatchAuthenticationPolicy(in *api.ListWatchOptions, stream auth.AuthV1_AutoWatchAuthenticationPolicyServer) error {
	return e.fnAutoWatchAuthenticationPolicy(in, stream, "auth")
}

func init() {
	apisrv = apisrvpkg.MustGetAPIServer()

	svc := sauthAuthBackend{}

	{
		e := eAuthV1Endpoints{Svc: svc}
		svc.endpointsAuthV1 = &e
	}
	apisrv.Register("auth.protos/auth.proto", &svc)
}
