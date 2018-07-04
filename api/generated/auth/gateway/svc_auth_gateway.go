// Code generated by protoc-gen-grpc-pensando DO NOT EDIT.

/*
Package authGwService is a auto generated package.
Input file: svc_auth.proto
*/
package authGwService

import (
	"context"
	"net/http"
	"sync"
	"time"

	"github.com/pkg/errors"
	oldcontext "golang.org/x/net/context"
	"google.golang.org/grpc"

	"github.com/pensando/grpc-gateway/runtime"

	"github.com/pensando/sw/api"
	auth "github.com/pensando/sw/api/generated/auth"
	grpcclient "github.com/pensando/sw/api/generated/auth/grpc/client"
	"github.com/pensando/sw/venice/apigw"
	"github.com/pensando/sw/venice/apigw/pkg"
	"github.com/pensando/sw/venice/apiserver"
	"github.com/pensando/sw/venice/globals"
	"github.com/pensando/sw/venice/utils/balancer"
	"github.com/pensando/sw/venice/utils/log"
	"github.com/pensando/sw/venice/utils/resolver"
	"github.com/pensando/sw/venice/utils/rpckit"
)

// Dummy vars to suppress import errors
var _ api.TypeMeta

type sAuthV1GwService struct {
	logger     log.Logger
	defSvcProf apigw.ServiceProfile
	svcProf    map[string]apigw.ServiceProfile
}

type adapterAuthV1 struct {
	conn    *rpckit.RPCClient
	service auth.ServiceAuthV1Client
	gwSvc   *sAuthV1GwService
	gw      apigw.APIGateway
}

func (a adapterAuthV1) AutoAddAuthenticationPolicy(oldctx oldcontext.Context, t *auth.AuthenticationPolicy, options ...grpc.CallOption) (*auth.AuthenticationPolicy, error) {
	// Not using options for now. Will be passed through context as needed.
	ctx := context.Context(oldctx)
	prof, err := a.gwSvc.GetServiceProfile("AutoAddAuthenticationPolicy")
	if err != nil {
		return nil, errors.New("unknown service profile")
	}
	fn := func(ctx context.Context, i interface{}) (interface{}, error) {
		in := i.(*auth.AuthenticationPolicy)
		return a.service.AutoAddAuthenticationPolicy(ctx, in)
	}
	ret, err := a.gw.HandleRequest(ctx, t, prof, fn)
	if ret == nil {
		return nil, err
	}
	return ret.(*auth.AuthenticationPolicy), err
}

func (a adapterAuthV1) AutoAddRole(oldctx oldcontext.Context, t *auth.Role, options ...grpc.CallOption) (*auth.Role, error) {
	// Not using options for now. Will be passed through context as needed.
	ctx := context.Context(oldctx)
	prof, err := a.gwSvc.GetServiceProfile("AutoAddRole")
	if err != nil {
		return nil, errors.New("unknown service profile")
	}
	fn := func(ctx context.Context, i interface{}) (interface{}, error) {
		in := i.(*auth.Role)
		return a.service.AutoAddRole(ctx, in)
	}
	ret, err := a.gw.HandleRequest(ctx, t, prof, fn)
	if ret == nil {
		return nil, err
	}
	return ret.(*auth.Role), err
}

func (a adapterAuthV1) AutoAddRoleBinding(oldctx oldcontext.Context, t *auth.RoleBinding, options ...grpc.CallOption) (*auth.RoleBinding, error) {
	// Not using options for now. Will be passed through context as needed.
	ctx := context.Context(oldctx)
	prof, err := a.gwSvc.GetServiceProfile("AutoAddRoleBinding")
	if err != nil {
		return nil, errors.New("unknown service profile")
	}
	fn := func(ctx context.Context, i interface{}) (interface{}, error) {
		in := i.(*auth.RoleBinding)
		return a.service.AutoAddRoleBinding(ctx, in)
	}
	ret, err := a.gw.HandleRequest(ctx, t, prof, fn)
	if ret == nil {
		return nil, err
	}
	return ret.(*auth.RoleBinding), err
}

func (a adapterAuthV1) AutoAddUser(oldctx oldcontext.Context, t *auth.User, options ...grpc.CallOption) (*auth.User, error) {
	// Not using options for now. Will be passed through context as needed.
	ctx := context.Context(oldctx)
	prof, err := a.gwSvc.GetServiceProfile("AutoAddUser")
	if err != nil {
		return nil, errors.New("unknown service profile")
	}
	fn := func(ctx context.Context, i interface{}) (interface{}, error) {
		in := i.(*auth.User)
		return a.service.AutoAddUser(ctx, in)
	}
	ret, err := a.gw.HandleRequest(ctx, t, prof, fn)
	if ret == nil {
		return nil, err
	}
	return ret.(*auth.User), err
}

func (a adapterAuthV1) AutoDeleteAuthenticationPolicy(oldctx oldcontext.Context, t *auth.AuthenticationPolicy, options ...grpc.CallOption) (*auth.AuthenticationPolicy, error) {
	// Not using options for now. Will be passed through context as needed.
	ctx := context.Context(oldctx)
	prof, err := a.gwSvc.GetServiceProfile("AutoDeleteAuthenticationPolicy")
	if err != nil {
		return nil, errors.New("unknown service profile")
	}
	fn := func(ctx context.Context, i interface{}) (interface{}, error) {
		in := i.(*auth.AuthenticationPolicy)
		return a.service.AutoDeleteAuthenticationPolicy(ctx, in)
	}
	ret, err := a.gw.HandleRequest(ctx, t, prof, fn)
	if ret == nil {
		return nil, err
	}
	return ret.(*auth.AuthenticationPolicy), err
}

func (a adapterAuthV1) AutoDeleteRole(oldctx oldcontext.Context, t *auth.Role, options ...grpc.CallOption) (*auth.Role, error) {
	// Not using options for now. Will be passed through context as needed.
	ctx := context.Context(oldctx)
	prof, err := a.gwSvc.GetServiceProfile("AutoDeleteRole")
	if err != nil {
		return nil, errors.New("unknown service profile")
	}
	fn := func(ctx context.Context, i interface{}) (interface{}, error) {
		in := i.(*auth.Role)
		return a.service.AutoDeleteRole(ctx, in)
	}
	ret, err := a.gw.HandleRequest(ctx, t, prof, fn)
	if ret == nil {
		return nil, err
	}
	return ret.(*auth.Role), err
}

func (a adapterAuthV1) AutoDeleteRoleBinding(oldctx oldcontext.Context, t *auth.RoleBinding, options ...grpc.CallOption) (*auth.RoleBinding, error) {
	// Not using options for now. Will be passed through context as needed.
	ctx := context.Context(oldctx)
	prof, err := a.gwSvc.GetServiceProfile("AutoDeleteRoleBinding")
	if err != nil {
		return nil, errors.New("unknown service profile")
	}
	fn := func(ctx context.Context, i interface{}) (interface{}, error) {
		in := i.(*auth.RoleBinding)
		return a.service.AutoDeleteRoleBinding(ctx, in)
	}
	ret, err := a.gw.HandleRequest(ctx, t, prof, fn)
	if ret == nil {
		return nil, err
	}
	return ret.(*auth.RoleBinding), err
}

func (a adapterAuthV1) AutoDeleteUser(oldctx oldcontext.Context, t *auth.User, options ...grpc.CallOption) (*auth.User, error) {
	// Not using options for now. Will be passed through context as needed.
	ctx := context.Context(oldctx)
	prof, err := a.gwSvc.GetServiceProfile("AutoDeleteUser")
	if err != nil {
		return nil, errors.New("unknown service profile")
	}
	fn := func(ctx context.Context, i interface{}) (interface{}, error) {
		in := i.(*auth.User)
		return a.service.AutoDeleteUser(ctx, in)
	}
	ret, err := a.gw.HandleRequest(ctx, t, prof, fn)
	if ret == nil {
		return nil, err
	}
	return ret.(*auth.User), err
}

func (a adapterAuthV1) AutoGetAuthenticationPolicy(oldctx oldcontext.Context, t *auth.AuthenticationPolicy, options ...grpc.CallOption) (*auth.AuthenticationPolicy, error) {
	// Not using options for now. Will be passed through context as needed.
	ctx := context.Context(oldctx)
	prof, err := a.gwSvc.GetServiceProfile("AutoGetAuthenticationPolicy")
	if err != nil {
		return nil, errors.New("unknown service profile")
	}
	fn := func(ctx context.Context, i interface{}) (interface{}, error) {
		in := i.(*auth.AuthenticationPolicy)
		return a.service.AutoGetAuthenticationPolicy(ctx, in)
	}
	ret, err := a.gw.HandleRequest(ctx, t, prof, fn)
	if ret == nil {
		return nil, err
	}
	return ret.(*auth.AuthenticationPolicy), err
}

func (a adapterAuthV1) AutoGetRole(oldctx oldcontext.Context, t *auth.Role, options ...grpc.CallOption) (*auth.Role, error) {
	// Not using options for now. Will be passed through context as needed.
	ctx := context.Context(oldctx)
	prof, err := a.gwSvc.GetServiceProfile("AutoGetRole")
	if err != nil {
		return nil, errors.New("unknown service profile")
	}
	fn := func(ctx context.Context, i interface{}) (interface{}, error) {
		in := i.(*auth.Role)
		return a.service.AutoGetRole(ctx, in)
	}
	ret, err := a.gw.HandleRequest(ctx, t, prof, fn)
	if ret == nil {
		return nil, err
	}
	return ret.(*auth.Role), err
}

func (a adapterAuthV1) AutoGetRoleBinding(oldctx oldcontext.Context, t *auth.RoleBinding, options ...grpc.CallOption) (*auth.RoleBinding, error) {
	// Not using options for now. Will be passed through context as needed.
	ctx := context.Context(oldctx)
	prof, err := a.gwSvc.GetServiceProfile("AutoGetRoleBinding")
	if err != nil {
		return nil, errors.New("unknown service profile")
	}
	fn := func(ctx context.Context, i interface{}) (interface{}, error) {
		in := i.(*auth.RoleBinding)
		return a.service.AutoGetRoleBinding(ctx, in)
	}
	ret, err := a.gw.HandleRequest(ctx, t, prof, fn)
	if ret == nil {
		return nil, err
	}
	return ret.(*auth.RoleBinding), err
}

func (a adapterAuthV1) AutoGetUser(oldctx oldcontext.Context, t *auth.User, options ...grpc.CallOption) (*auth.User, error) {
	// Not using options for now. Will be passed through context as needed.
	ctx := context.Context(oldctx)
	prof, err := a.gwSvc.GetServiceProfile("AutoGetUser")
	if err != nil {
		return nil, errors.New("unknown service profile")
	}
	fn := func(ctx context.Context, i interface{}) (interface{}, error) {
		in := i.(*auth.User)
		return a.service.AutoGetUser(ctx, in)
	}
	ret, err := a.gw.HandleRequest(ctx, t, prof, fn)
	if ret == nil {
		return nil, err
	}
	return ret.(*auth.User), err
}

func (a adapterAuthV1) AutoListAuthenticationPolicy(oldctx oldcontext.Context, t *api.ListWatchOptions, options ...grpc.CallOption) (*auth.AuthenticationPolicyList, error) {
	// Not using options for now. Will be passed through context as needed.
	ctx := context.Context(oldctx)
	prof, err := a.gwSvc.GetServiceProfile("AutoListAuthenticationPolicy")
	if err != nil {
		return nil, errors.New("unknown service profile")
	}
	fn := func(ctx context.Context, i interface{}) (interface{}, error) {
		in := i.(*api.ListWatchOptions)
		return a.service.AutoListAuthenticationPolicy(ctx, in)
	}
	ret, err := a.gw.HandleRequest(ctx, t, prof, fn)
	if ret == nil {
		return nil, err
	}
	return ret.(*auth.AuthenticationPolicyList), err
}

func (a adapterAuthV1) AutoListRole(oldctx oldcontext.Context, t *api.ListWatchOptions, options ...grpc.CallOption) (*auth.RoleList, error) {
	// Not using options for now. Will be passed through context as needed.
	ctx := context.Context(oldctx)
	prof, err := a.gwSvc.GetServiceProfile("AutoListRole")
	if err != nil {
		return nil, errors.New("unknown service profile")
	}
	fn := func(ctx context.Context, i interface{}) (interface{}, error) {
		in := i.(*api.ListWatchOptions)
		return a.service.AutoListRole(ctx, in)
	}
	ret, err := a.gw.HandleRequest(ctx, t, prof, fn)
	if ret == nil {
		return nil, err
	}
	return ret.(*auth.RoleList), err
}

func (a adapterAuthV1) AutoListRoleBinding(oldctx oldcontext.Context, t *api.ListWatchOptions, options ...grpc.CallOption) (*auth.RoleBindingList, error) {
	// Not using options for now. Will be passed through context as needed.
	ctx := context.Context(oldctx)
	prof, err := a.gwSvc.GetServiceProfile("AutoListRoleBinding")
	if err != nil {
		return nil, errors.New("unknown service profile")
	}
	fn := func(ctx context.Context, i interface{}) (interface{}, error) {
		in := i.(*api.ListWatchOptions)
		return a.service.AutoListRoleBinding(ctx, in)
	}
	ret, err := a.gw.HandleRequest(ctx, t, prof, fn)
	if ret == nil {
		return nil, err
	}
	return ret.(*auth.RoleBindingList), err
}

func (a adapterAuthV1) AutoListUser(oldctx oldcontext.Context, t *api.ListWatchOptions, options ...grpc.CallOption) (*auth.UserList, error) {
	// Not using options for now. Will be passed through context as needed.
	ctx := context.Context(oldctx)
	prof, err := a.gwSvc.GetServiceProfile("AutoListUser")
	if err != nil {
		return nil, errors.New("unknown service profile")
	}
	fn := func(ctx context.Context, i interface{}) (interface{}, error) {
		in := i.(*api.ListWatchOptions)
		return a.service.AutoListUser(ctx, in)
	}
	ret, err := a.gw.HandleRequest(ctx, t, prof, fn)
	if ret == nil {
		return nil, err
	}
	return ret.(*auth.UserList), err
}

func (a adapterAuthV1) AutoUpdateAuthenticationPolicy(oldctx oldcontext.Context, t *auth.AuthenticationPolicy, options ...grpc.CallOption) (*auth.AuthenticationPolicy, error) {
	// Not using options for now. Will be passed through context as needed.
	ctx := context.Context(oldctx)
	prof, err := a.gwSvc.GetServiceProfile("AutoUpdateAuthenticationPolicy")
	if err != nil {
		return nil, errors.New("unknown service profile")
	}
	fn := func(ctx context.Context, i interface{}) (interface{}, error) {
		in := i.(*auth.AuthenticationPolicy)
		return a.service.AutoUpdateAuthenticationPolicy(ctx, in)
	}
	ret, err := a.gw.HandleRequest(ctx, t, prof, fn)
	if ret == nil {
		return nil, err
	}
	return ret.(*auth.AuthenticationPolicy), err
}

func (a adapterAuthV1) AutoUpdateRole(oldctx oldcontext.Context, t *auth.Role, options ...grpc.CallOption) (*auth.Role, error) {
	// Not using options for now. Will be passed through context as needed.
	ctx := context.Context(oldctx)
	prof, err := a.gwSvc.GetServiceProfile("AutoUpdateRole")
	if err != nil {
		return nil, errors.New("unknown service profile")
	}
	fn := func(ctx context.Context, i interface{}) (interface{}, error) {
		in := i.(*auth.Role)
		return a.service.AutoUpdateRole(ctx, in)
	}
	ret, err := a.gw.HandleRequest(ctx, t, prof, fn)
	if ret == nil {
		return nil, err
	}
	return ret.(*auth.Role), err
}

func (a adapterAuthV1) AutoUpdateRoleBinding(oldctx oldcontext.Context, t *auth.RoleBinding, options ...grpc.CallOption) (*auth.RoleBinding, error) {
	// Not using options for now. Will be passed through context as needed.
	ctx := context.Context(oldctx)
	prof, err := a.gwSvc.GetServiceProfile("AutoUpdateRoleBinding")
	if err != nil {
		return nil, errors.New("unknown service profile")
	}
	fn := func(ctx context.Context, i interface{}) (interface{}, error) {
		in := i.(*auth.RoleBinding)
		return a.service.AutoUpdateRoleBinding(ctx, in)
	}
	ret, err := a.gw.HandleRequest(ctx, t, prof, fn)
	if ret == nil {
		return nil, err
	}
	return ret.(*auth.RoleBinding), err
}

func (a adapterAuthV1) AutoUpdateUser(oldctx oldcontext.Context, t *auth.User, options ...grpc.CallOption) (*auth.User, error) {
	// Not using options for now. Will be passed through context as needed.
	ctx := context.Context(oldctx)
	prof, err := a.gwSvc.GetServiceProfile("AutoUpdateUser")
	if err != nil {
		return nil, errors.New("unknown service profile")
	}
	fn := func(ctx context.Context, i interface{}) (interface{}, error) {
		in := i.(*auth.User)
		return a.service.AutoUpdateUser(ctx, in)
	}
	ret, err := a.gw.HandleRequest(ctx, t, prof, fn)
	if ret == nil {
		return nil, err
	}
	return ret.(*auth.User), err
}

func (a adapterAuthV1) AutoWatchSvcAuthV1(oldctx oldcontext.Context, in *api.ListWatchOptions, options ...grpc.CallOption) (auth.AuthV1_AutoWatchSvcAuthV1Client, error) {
	ctx := context.Context(oldctx)
	return a.service.AutoWatchSvcAuthV1(ctx, in)
}

func (a adapterAuthV1) AutoWatchUser(oldctx oldcontext.Context, in *api.ListWatchOptions, options ...grpc.CallOption) (auth.AuthV1_AutoWatchUserClient, error) {
	ctx := context.Context(oldctx)
	return a.service.AutoWatchUser(ctx, in)
}

func (a adapterAuthV1) AutoWatchAuthenticationPolicy(oldctx oldcontext.Context, in *api.ListWatchOptions, options ...grpc.CallOption) (auth.AuthV1_AutoWatchAuthenticationPolicyClient, error) {
	ctx := context.Context(oldctx)
	return a.service.AutoWatchAuthenticationPolicy(ctx, in)
}

func (a adapterAuthV1) AutoWatchRole(oldctx oldcontext.Context, in *api.ListWatchOptions, options ...grpc.CallOption) (auth.AuthV1_AutoWatchRoleClient, error) {
	ctx := context.Context(oldctx)
	return a.service.AutoWatchRole(ctx, in)
}

func (a adapterAuthV1) AutoWatchRoleBinding(oldctx oldcontext.Context, in *api.ListWatchOptions, options ...grpc.CallOption) (auth.AuthV1_AutoWatchRoleBindingClient, error) {
	ctx := context.Context(oldctx)
	return a.service.AutoWatchRoleBinding(ctx, in)
}

func (e *sAuthV1GwService) setupSvcProfile() {
	e.defSvcProf = apigwpkg.NewServiceProfile(nil)
	e.defSvcProf.SetDefaults()
	e.svcProf = make(map[string]apigw.ServiceProfile)

	e.svcProf["AutoAddAuthenticationPolicy"] = apigwpkg.NewServiceProfile(e.defSvcProf)
	e.svcProf["AutoAddRole"] = apigwpkg.NewServiceProfile(e.defSvcProf)
	e.svcProf["AutoAddRoleBinding"] = apigwpkg.NewServiceProfile(e.defSvcProf)
	e.svcProf["AutoAddUser"] = apigwpkg.NewServiceProfile(e.defSvcProf)
	e.svcProf["AutoDeleteAuthenticationPolicy"] = apigwpkg.NewServiceProfile(e.defSvcProf)
	e.svcProf["AutoDeleteRole"] = apigwpkg.NewServiceProfile(e.defSvcProf)
	e.svcProf["AutoDeleteRoleBinding"] = apigwpkg.NewServiceProfile(e.defSvcProf)
	e.svcProf["AutoDeleteUser"] = apigwpkg.NewServiceProfile(e.defSvcProf)
	e.svcProf["AutoGetAuthenticationPolicy"] = apigwpkg.NewServiceProfile(e.defSvcProf)
	e.svcProf["AutoGetRole"] = apigwpkg.NewServiceProfile(e.defSvcProf)
	e.svcProf["AutoGetRoleBinding"] = apigwpkg.NewServiceProfile(e.defSvcProf)
	e.svcProf["AutoGetUser"] = apigwpkg.NewServiceProfile(e.defSvcProf)
	e.svcProf["AutoListRole"] = apigwpkg.NewServiceProfile(e.defSvcProf)
	e.svcProf["AutoListRoleBinding"] = apigwpkg.NewServiceProfile(e.defSvcProf)
	e.svcProf["AutoListUser"] = apigwpkg.NewServiceProfile(e.defSvcProf)
	e.svcProf["AutoUpdateAuthenticationPolicy"] = apigwpkg.NewServiceProfile(e.defSvcProf)
	e.svcProf["AutoUpdateRole"] = apigwpkg.NewServiceProfile(e.defSvcProf)
	e.svcProf["AutoUpdateRoleBinding"] = apigwpkg.NewServiceProfile(e.defSvcProf)
	e.svcProf["AutoUpdateUser"] = apigwpkg.NewServiceProfile(e.defSvcProf)
}

// GetDefaultServiceProfile returns the default fallback service profile for this service
func (e *sAuthV1GwService) GetDefaultServiceProfile() (apigw.ServiceProfile, error) {
	if e.defSvcProf == nil {
		return nil, errors.New("not found")
	}
	return e.defSvcProf, nil
}

// GetServiceProfile returns the service profile for a given method in this service
func (e *sAuthV1GwService) GetServiceProfile(method string) (apigw.ServiceProfile, error) {
	if ret, ok := e.svcProf[method]; ok {
		return ret, nil
	}
	return nil, errors.New("not found")
}

// GetCrudServiceProfile returns the service profile for a auto generated crud operation
func (e *sAuthV1GwService) GetCrudServiceProfile(obj string, oper apiserver.APIOperType) (apigw.ServiceProfile, error) {
	name := apiserver.GetCrudServiceName(obj, oper)
	if name != "" {
		return e.GetServiceProfile(name)
	}
	return nil, errors.New("not found")
}

func (e *sAuthV1GwService) CompleteRegistration(ctx context.Context,
	logger log.Logger,
	grpcserver *grpc.Server,
	m *http.ServeMux,
	rslvr resolver.Interface,
	wg *sync.WaitGroup) error {
	apigw := apigwpkg.MustGetAPIGateway()
	// IP:port destination or service discovery key.
	grpcaddr := "pen-apiserver"
	grpcaddr = apigw.GetAPIServerAddr(grpcaddr)
	e.logger = logger

	marshaller := runtime.JSONBuiltin{}
	opts := runtime.WithMarshalerOption("*", &marshaller)
	muxMutex.Lock()
	if mux == nil {
		mux = runtime.NewServeMux(opts)
	}
	muxMutex.Unlock()
	e.setupSvcProfile()

	err := registerSwaggerDef(m, logger)
	if err != nil {
		logger.ErrorLog("msg", "failed to register swagger spec", "service", "auth.AuthV1", "error", err)
	}
	wg.Add(1)
	go func() {
		defer wg.Done()
		for {
			nctx, cancel := context.WithCancel(ctx)
			cl, err := e.newClient(nctx, grpcaddr, rslvr, apigw.GetDevMode())
			if err == nil {
				muxMutex.Lock()
				err = auth.RegisterAuthV1HandlerWithClient(ctx, mux, cl)
				muxMutex.Unlock()
				if err == nil {
					logger.InfoLog("msg", "registered service auth.AuthV1")
					m.Handle("/v1/auth/", http.StripPrefix("/v1/auth", mux))
					return
				} else {
					err = errors.Wrap(err, "failed to register")
				}
			} else {
				err = errors.Wrap(err, "failed to create client")
			}
			cancel()
			logger.ErrorLog("msg", "failed to register", "service", "auth.AuthV1", "error", err)
			select {
			case <-ctx.Done():
				return
			case <-time.After(5 * time.Second):
			}
		}
	}()
	return nil
}

func (e *sAuthV1GwService) newClient(ctx context.Context, grpcAddr string, rslvr resolver.Interface, devmode bool) (*adapterAuthV1, error) {
	var opts []rpckit.Option
	if rslvr != nil {
		opts = append(opts, rpckit.WithBalancer(balancer.New(rslvr)))
	} else {
		opts = append(opts, rpckit.WithRemoteServerName("pen-apiserver"))
	}

	if !devmode {
		opts = append(opts, rpckit.WithTracerEnabled(false))
		opts = append(opts, rpckit.WithLoggerEnabled(false))
		opts = append(opts, rpckit.WithStatsEnabled(false))
	}

	client, err := rpckit.NewRPCClient(globals.APIGw, grpcAddr, opts...)
	if err != nil {
		return nil, errors.Wrap(err, "create rpc client")
	}

	e.logger.Infof("Connected to GRPC Server %s", grpcAddr)
	defer func() {
		go func() {
			<-ctx.Done()
			if cerr := client.Close(); cerr != nil {
				e.logger.ErrorLog("msg", "Failed to close conn on Done()", "addr", grpcAddr, "error", cerr)
			}
		}()
	}()

	cl := &adapterAuthV1{conn: client, gw: apigwpkg.MustGetAPIGateway(), gwSvc: e, service: grpcclient.NewAuthV1Backend(client.ClientConn, e.logger)}
	return cl, nil
}

func init() {

	apigw := apigwpkg.MustGetAPIGateway()

	svcAuthV1 := sAuthV1GwService{}
	apigw.Register("auth.AuthV1", "auth/", &svcAuthV1)
}
