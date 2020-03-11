// Code generated by protoc-gen-grpc-pensando DO NOT EDIT.

/*
Package orchestrationGwService is a auto generated package.
Input file: svc_orchestration.proto
*/
package orchestrationGwService

import (
	"context"
	"net/http"
	"strings"
	"sync"
	"time"

	"github.com/pkg/errors"
	oldcontext "golang.org/x/net/context"
	"google.golang.org/grpc"

	"github.com/pensando/grpc-gateway/runtime"

	"github.com/pensando/sw/api"
	orchestration "github.com/pensando/sw/api/generated/orchestration"
	grpcclient "github.com/pensando/sw/api/generated/orchestration/grpc/client"
	"github.com/pensando/sw/api/interfaces"
	"github.com/pensando/sw/api/utils"
	"github.com/pensando/sw/venice/apigw"
	"github.com/pensando/sw/venice/apigw/pkg"
	"github.com/pensando/sw/venice/apiserver"
	"github.com/pensando/sw/venice/globals"
	"github.com/pensando/sw/venice/utils/authz"
	"github.com/pensando/sw/venice/utils/balancer"
	hdr "github.com/pensando/sw/venice/utils/histogram"
	"github.com/pensando/sw/venice/utils/log"
	"github.com/pensando/sw/venice/utils/resolver"
	"github.com/pensando/sw/venice/utils/rpckit"
)

// Dummy vars to suppress import errors
var _ api.TypeMeta
var _ authz.Authorizer

type sOrchestratorV1GwService struct {
	logger     log.Logger
	defSvcProf apigw.ServiceProfile
	svcProf    map[string]apigw.ServiceProfile
}

type adapterOrchestratorV1 struct {
	conn    *rpckit.RPCClient
	service orchestration.ServiceOrchestratorV1Client
	gwSvc   *sOrchestratorV1GwService
	gw      apigw.APIGateway
}

func (a adapterOrchestratorV1) AutoAddOrchestrator(oldctx oldcontext.Context, t *orchestration.Orchestrator, options ...grpc.CallOption) (*orchestration.Orchestrator, error) {
	// Not using options for now. Will be passed through context as needed.
	trackTime := time.Now()
	defer func() {
		hdr.Record("apigw.OrchestratorV1AutoAddOrchestrator", time.Since(trackTime))
	}()
	ctx := context.Context(oldctx)
	prof, err := a.gwSvc.GetServiceProfile("AutoAddOrchestrator")
	if err != nil {
		return nil, errors.New("unknown service profile")
	}
	oper, kind, tenant, namespace, group, name, auditAction := apiintf.CreateOper, "Orchestrator", t.Tenant, t.Namespace, "orchestration", t.Name, strings.Title(string(apiintf.CreateOper))

	op := authz.NewAPIServerOperation(authz.NewResource(tenant, group, kind, namespace, name), oper, auditAction)
	ctx = apigwpkg.NewContextWithOperations(ctx, op)

	fn := func(ctx context.Context, i interface{}) (interface{}, error) {
		in := i.(*orchestration.Orchestrator)
		return a.service.AutoAddOrchestrator(ctx, in)
	}
	ret, err := a.gw.HandleRequest(ctx, t, prof, fn)
	if ret == nil {
		return nil, err
	}
	return ret.(*orchestration.Orchestrator), err
}

func (a adapterOrchestratorV1) AutoDeleteOrchestrator(oldctx oldcontext.Context, t *orchestration.Orchestrator, options ...grpc.CallOption) (*orchestration.Orchestrator, error) {
	// Not using options for now. Will be passed through context as needed.
	trackTime := time.Now()
	defer func() {
		hdr.Record("apigw.OrchestratorV1AutoDeleteOrchestrator", time.Since(trackTime))
	}()
	ctx := context.Context(oldctx)
	prof, err := a.gwSvc.GetServiceProfile("AutoDeleteOrchestrator")
	if err != nil {
		return nil, errors.New("unknown service profile")
	}
	oper, kind, tenant, namespace, group, name, auditAction := apiintf.DeleteOper, "Orchestrator", t.Tenant, t.Namespace, "orchestration", t.Name, strings.Title(string(apiintf.DeleteOper))

	op := authz.NewAPIServerOperation(authz.NewResource(tenant, group, kind, namespace, name), oper, auditAction)
	ctx = apigwpkg.NewContextWithOperations(ctx, op)

	fn := func(ctx context.Context, i interface{}) (interface{}, error) {
		in := i.(*orchestration.Orchestrator)
		return a.service.AutoDeleteOrchestrator(ctx, in)
	}
	ret, err := a.gw.HandleRequest(ctx, t, prof, fn)
	if ret == nil {
		return nil, err
	}
	return ret.(*orchestration.Orchestrator), err
}

func (a adapterOrchestratorV1) AutoGetOrchestrator(oldctx oldcontext.Context, t *orchestration.Orchestrator, options ...grpc.CallOption) (*orchestration.Orchestrator, error) {
	// Not using options for now. Will be passed through context as needed.
	trackTime := time.Now()
	defer func() {
		hdr.Record("apigw.OrchestratorV1AutoGetOrchestrator", time.Since(trackTime))
	}()
	ctx := context.Context(oldctx)
	prof, err := a.gwSvc.GetServiceProfile("AutoGetOrchestrator")
	if err != nil {
		return nil, errors.New("unknown service profile")
	}
	oper, kind, tenant, namespace, group, name, auditAction := apiintf.GetOper, "Orchestrator", t.Tenant, t.Namespace, "orchestration", t.Name, strings.Title(string(apiintf.GetOper))

	op := authz.NewAPIServerOperation(authz.NewResource(tenant, group, kind, namespace, name), oper, auditAction)
	ctx = apigwpkg.NewContextWithOperations(ctx, op)

	fn := func(ctx context.Context, i interface{}) (interface{}, error) {
		in := i.(*orchestration.Orchestrator)
		return a.service.AutoGetOrchestrator(ctx, in)
	}
	ret, err := a.gw.HandleRequest(ctx, t, prof, fn)
	if ret == nil {
		return nil, err
	}
	return ret.(*orchestration.Orchestrator), err
}

func (a adapterOrchestratorV1) AutoLabelOrchestrator(oldctx oldcontext.Context, t *api.Label, options ...grpc.CallOption) (*orchestration.Orchestrator, error) {
	// Not using options for now. Will be passed through context as needed.
	trackTime := time.Now()
	defer func() {
		hdr.Record("apigw.OrchestratorV1AutoLabelOrchestrator", time.Since(trackTime))
	}()
	ctx := context.Context(oldctx)
	prof, err := a.gwSvc.GetServiceProfile("AutoLabelOrchestrator")
	if err != nil {
		return nil, errors.New("unknown service profile")
	}
	oper, kind, tenant, namespace, group, name, auditAction := apiintf.UpdateOper, "Orchestrator", t.Tenant, t.Namespace, "orchestration", t.Name, strings.Title(string(apiintf.LabelOper))

	op := authz.NewAPIServerOperation(authz.NewResource(tenant, group, kind, namespace, name), oper, auditAction)
	ctx = apigwpkg.NewContextWithOperations(ctx, op)

	fn := func(ctx context.Context, i interface{}) (interface{}, error) {
		in := i.(*api.Label)
		return a.service.AutoLabelOrchestrator(ctx, in)
	}
	ret, err := a.gw.HandleRequest(ctx, t, prof, fn)
	if ret == nil {
		return nil, err
	}
	return ret.(*orchestration.Orchestrator), err
}

func (a adapterOrchestratorV1) AutoListOrchestrator(oldctx oldcontext.Context, t *api.ListWatchOptions, options ...grpc.CallOption) (*orchestration.OrchestratorList, error) {
	// Not using options for now. Will be passed through context as needed.
	trackTime := time.Now()
	defer func() {
		hdr.Record("apigw.OrchestratorV1AutoListOrchestrator", time.Since(trackTime))
	}()
	ctx := context.Context(oldctx)
	prof, err := a.gwSvc.GetServiceProfile("AutoListOrchestrator")
	if err != nil {
		return nil, errors.New("unknown service profile")
	}

	t.Tenant = ""
	t.Namespace = ""
	oper, kind, tenant, namespace, group, name, auditAction := apiintf.ListOper, "Orchestrator", t.Tenant, t.Namespace, "orchestration", "", strings.Title(string(apiintf.ListOper))

	op := authz.NewAPIServerOperation(authz.NewResource(tenant, group, kind, namespace, name), oper, auditAction)
	ctx = apigwpkg.NewContextWithOperations(ctx, op)

	fn := func(ctx context.Context, i interface{}) (interface{}, error) {
		in := i.(*api.ListWatchOptions)
		return a.service.AutoListOrchestrator(ctx, in)
	}
	ret, err := a.gw.HandleRequest(ctx, t, prof, fn)
	if ret == nil {
		return nil, err
	}
	return ret.(*orchestration.OrchestratorList), err
}

func (a adapterOrchestratorV1) AutoUpdateOrchestrator(oldctx oldcontext.Context, t *orchestration.Orchestrator, options ...grpc.CallOption) (*orchestration.Orchestrator, error) {
	// Not using options for now. Will be passed through context as needed.
	trackTime := time.Now()
	defer func() {
		hdr.Record("apigw.OrchestratorV1AutoUpdateOrchestrator", time.Since(trackTime))
	}()
	ctx := context.Context(oldctx)
	prof, err := a.gwSvc.GetServiceProfile("AutoUpdateOrchestrator")
	if err != nil {
		return nil, errors.New("unknown service profile")
	}
	oper, kind, tenant, namespace, group, name, auditAction := apiintf.UpdateOper, "Orchestrator", t.Tenant, t.Namespace, "orchestration", t.Name, strings.Title(string(apiintf.UpdateOper))

	op := authz.NewAPIServerOperation(authz.NewResource(tenant, group, kind, namespace, name), oper, auditAction)
	ctx = apigwpkg.NewContextWithOperations(ctx, op)

	fn := func(ctx context.Context, i interface{}) (interface{}, error) {
		in := i.(*orchestration.Orchestrator)
		return a.service.AutoUpdateOrchestrator(ctx, in)
	}
	ret, err := a.gw.HandleRequest(ctx, t, prof, fn)
	if ret == nil {
		return nil, err
	}
	return ret.(*orchestration.Orchestrator), err
}

func (a adapterOrchestratorV1) AutoWatchSvcOrchestratorV1(oldctx oldcontext.Context, in *api.ListWatchOptions, options ...grpc.CallOption) (orchestration.OrchestratorV1_AutoWatchSvcOrchestratorV1Client, error) {
	ctx := context.Context(oldctx)
	prof, err := a.gwSvc.GetServiceProfile("AutoWatchSvcOrchestratorV1")
	if err != nil {
		return nil, errors.New("unknown service profile")
	}
	oper, kind, tenant, namespace, group := apiintf.WatchOper, "", in.Tenant, in.Namespace, "orchestration"
	op := authz.NewAPIServerOperation(authz.NewResource(tenant, group, kind, namespace, ""), oper, strings.Title(string(oper)))
	ctx = apigwpkg.NewContextWithOperations(ctx, op)
	fn := func(ctx context.Context, i interface{}) (interface{}, error) {
		in := i.(*api.ListWatchOptions)
		iws, ok := apiutils.GetVar(ctx, apiutils.CtxKeyAPIGwWebSocketWatch)
		if ok && iws.(bool) {
			nctx, cancel := context.WithCancel(ctx)
			ir, ok := apiutils.GetVar(ctx, apiutils.CtxKeyAPIGwHTTPReq)
			if !ok {
				return nil, errors.New("unable to retrieve request")
			}
			iw, ok := apiutils.GetVar(ctx, apiutils.CtxKeyAPIGwHTTPWriter)
			if !ok {
				return nil, errors.New("unable to retrieve writer")
			}
			conn, err := wsUpgrader.Upgrade(iw.(http.ResponseWriter), ir.(*http.Request), nil)
			if err != nil {
				log.Errorf("WebSocket Upgrade failed (%s)", err)
				return nil, err
			}
			ctx = apiutils.SetVar(nctx, apiutils.CtxKeyAPIGwWebSocketConn, conn)
			conn.SetCloseHandler(func(code int, text string) error {
				cancel()
				log.Infof("received close notification on websocket [AutoWatchOrchestratorV1] (%v/%v)", code, text)
				return nil
			})
			// start a dummy reciever
			go func() {
				for {
					_, _, err := conn.ReadMessage()
					if err != nil {
						log.Errorf("received error on websocket receive (%s)", err)
						cancel()
						return
					}
				}
			}()
		}
		return a.service.AutoWatchSvcOrchestratorV1(ctx, in)
	}
	ret, err := a.gw.HandleRequest(ctx, in, prof, fn)
	if ret == nil {
		return nil, err
	}
	return ret.(orchestration.OrchestratorV1_AutoWatchSvcOrchestratorV1Client), err
}

func (a adapterOrchestratorV1) AutoWatchOrchestrator(oldctx oldcontext.Context, in *api.ListWatchOptions, options ...grpc.CallOption) (orchestration.OrchestratorV1_AutoWatchOrchestratorClient, error) {
	ctx := context.Context(oldctx)
	prof, err := a.gwSvc.GetServiceProfile("AutoWatchOrchestrator")
	if err != nil {
		return nil, errors.New("unknown service profile")
	}

	in.Tenant = ""
	in.Namespace = ""
	oper, kind, tenant, namespace, group := apiintf.WatchOper, "Orchestrator", in.Tenant, in.Namespace, "orchestration"
	op := authz.NewAPIServerOperation(authz.NewResource(tenant, group, kind, namespace, ""), oper, strings.Title(string(oper)))
	ctx = apigwpkg.NewContextWithOperations(ctx, op)
	fn := func(ctx context.Context, i interface{}) (interface{}, error) {
		in := i.(*api.ListWatchOptions)
		iws, ok := apiutils.GetVar(ctx, apiutils.CtxKeyAPIGwWebSocketWatch)
		if ok && iws.(bool) {
			nctx, cancel := context.WithCancel(ctx)
			ir, ok := apiutils.GetVar(ctx, apiutils.CtxKeyAPIGwHTTPReq)
			if !ok {
				return nil, errors.New("unable to retrieve request")
			}
			iw, ok := apiutils.GetVar(ctx, apiutils.CtxKeyAPIGwHTTPWriter)
			if !ok {
				return nil, errors.New("unable to retrieve writer")
			}
			conn, err := wsUpgrader.Upgrade(iw.(http.ResponseWriter), ir.(*http.Request), nil)
			if err != nil {
				log.Errorf("WebSocket Upgrade failed (%s)", err)
				return nil, err
			}
			ctx = apiutils.SetVar(nctx, apiutils.CtxKeyAPIGwWebSocketConn, conn)
			conn.SetCloseHandler(func(code int, text string) error {
				cancel()
				log.Infof("received close notification on websocket [AutoWatchOrchestrator] (%v/%v)", code, text)
				return nil
			})
			// start a dummy reciever
			go func() {
				for {
					_, _, err := conn.ReadMessage()
					if err != nil {
						log.Errorf("received error on websocket receive (%s)", err)
						cancel()
						return
					}
				}
			}()
		}
		return a.service.AutoWatchOrchestrator(ctx, in)
	}
	ret, err := a.gw.HandleRequest(ctx, in, prof, fn)
	if ret == nil {
		return nil, err
	}
	return ret.(orchestration.OrchestratorV1_AutoWatchOrchestratorClient), err
}

func (e *sOrchestratorV1GwService) setupSvcProfile() {
	e.defSvcProf = apigwpkg.NewServiceProfile(nil, "", "orchestration", apiintf.UnknownOper)
	e.defSvcProf.SetDefaults()
	e.svcProf = make(map[string]apigw.ServiceProfile)

	e.svcProf["AutoAddOrchestrator"] = apigwpkg.NewServiceProfile(e.defSvcProf, "Orchestrator", "orchestration", apiintf.CreateOper)

	e.svcProf["AutoDeleteOrchestrator"] = apigwpkg.NewServiceProfile(e.defSvcProf, "Orchestrator", "orchestration", apiintf.DeleteOper)

	e.svcProf["AutoGetOrchestrator"] = apigwpkg.NewServiceProfile(e.defSvcProf, "Orchestrator", "orchestration", apiintf.GetOper)

	e.svcProf["AutoLabelOrchestrator"] = apigwpkg.NewServiceProfile(e.defSvcProf, "Orchestrator", "orchestration", apiintf.CreateOper)

	e.svcProf["AutoListOrchestrator"] = apigwpkg.NewServiceProfile(e.defSvcProf, "OrchestratorList", "orchestration", apiintf.ListOper)

	e.svcProf["AutoUpdateOrchestrator"] = apigwpkg.NewServiceProfile(e.defSvcProf, "Orchestrator", "orchestration", apiintf.UpdateOper)

	e.svcProf["AutoWatchOrchestrator"] = apigwpkg.NewServiceProfile(e.defSvcProf, "AutoMsgOrchestratorWatchHelper", "orchestration", apiintf.WatchOper)
}

// GetDefaultServiceProfile returns the default fallback service profile for this service
func (e *sOrchestratorV1GwService) GetDefaultServiceProfile() (apigw.ServiceProfile, error) {
	if e.defSvcProf == nil {
		return nil, errors.New("not found")
	}
	return e.defSvcProf, nil
}

// GetServiceProfile returns the service profile for a given method in this service
func (e *sOrchestratorV1GwService) GetServiceProfile(method string) (apigw.ServiceProfile, error) {
	if ret, ok := e.svcProf[method]; ok {
		return ret, nil
	}
	return nil, errors.New("not found")
}

// GetCrudServiceProfile returns the service profile for a auto generated crud operation
func (e *sOrchestratorV1GwService) GetCrudServiceProfile(obj string, oper apiintf.APIOperType) (apigw.ServiceProfile, error) {
	name := apiserver.GetCrudServiceName(obj, oper)
	if name != "" {
		return e.GetServiceProfile(name)
	}
	return nil, errors.New("not found")
}

// GetProxyServiceProfile returns the service Profile for a reverse proxy path
func (e *sOrchestratorV1GwService) GetProxyServiceProfile(path string) (apigw.ServiceProfile, error) {
	name := "_RProxy_" + path
	return e.GetServiceProfile(name)
}

func (e *sOrchestratorV1GwService) CompleteRegistration(ctx context.Context,
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
		logger.ErrorLog("msg", "failed to register swagger spec", "service", "orchestration.OrchestratorV1", "err", err)
	}
	wg.Add(1)
	go func() {
		defer func() {
			muxMutex.Lock()
			mux = nil
			muxMutex.Unlock()
		}()
		defer wg.Done()
		for {
			nctx, cancel := context.WithCancel(ctx)
			cl, err := e.newClient(nctx, grpcaddr, rslvr, apigw.GetDevMode())
			if err == nil {
				muxMutex.Lock()
				err = orchestration.RegisterOrchestratorV1HandlerWithClient(ctx, mux, cl)
				muxMutex.Unlock()
				if err == nil {
					logger.InfoLog("msg", "registered service orchestration.OrchestratorV1")
					m.Handle("/configs/orchestration/v1/", http.StripPrefix("/configs/orchestration/v1", mux))
					return
				} else {
					err = errors.Wrap(err, "failed to register")
				}
			} else {
				err = errors.Wrap(err, "failed to create client")
			}
			cancel()
			logger.ErrorLog("msg", "failed to register", "service", "orchestration.OrchestratorV1", "err", err)
			select {
			case <-ctx.Done():
				return
			case <-time.After(5 * time.Second):
			}
		}
	}()
	return nil
}

func (e *sOrchestratorV1GwService) newClient(ctx context.Context, grpcAddr string, rslvr resolver.Interface, devmode bool) (*adapterOrchestratorV1, error) {
	var opts []rpckit.Option
	opts = append(opts, rpckit.WithTLSClientIdentity(globals.APIGw))
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
				e.logger.ErrorLog("msg", "Failed to close conn on Done()", "addr", grpcAddr, "err", cerr)
			}
		}()
	}()

	cl := &adapterOrchestratorV1{conn: client, gw: apigwpkg.MustGetAPIGateway(), gwSvc: e, service: grpcclient.NewOrchestratorV1Backend(client.ClientConn, e.logger)}
	return cl, nil
}

func init() {

	apigw := apigwpkg.MustGetAPIGateway()

	svcOrchestratorV1 := sOrchestratorV1GwService{}
	apigw.Register("orchestration.OrchestratorV1", "orchestration/", &svcOrchestratorV1)
}
