// {C} Copyright 2020 Pensando Systems Inc. All rights reserved.

package controller

import (
	"context"
	"encoding/json"
	"fmt"
	"io/ioutil"
	"net"
	"net/http"
	"net/http/pprof"
	"strconv"
	"strings"
	"sync"
	"time"

	"github.com/gorilla/mux"
	"github.com/pkg/errors"

	"github.com/pensando/sw/api"
	"github.com/pensando/sw/nic/agent/dscagent/types"
	"github.com/pensando/sw/nic/agent/httputils"
	"github.com/pensando/sw/nic/agent/protos/generated/nimbus"
	"github.com/pensando/sw/nic/agent/protos/generated/restapi/netagent"
	"github.com/pensando/sw/nic/agent/protos/netproto"
	"github.com/pensando/sw/venice/utils/balancer"
	"github.com/pensando/sw/venice/utils/log"
	"github.com/pensando/sw/venice/utils/resolver"
	"github.com/pensando/sw/venice/utils/rpckit"
	"github.com/pensando/sw/venice/utils/tsdb"
)

// API Implements ControllerAPI
type API struct {
	sync.Mutex
	sync.WaitGroup
	tsmWG, tpmWG                    sync.WaitGroup // TODO Temporary WGs till TPM and TSM move to nimbus and agg watch
	WatchCtx                        context.Context
	PipelineAPI                     types.PipelineAPI
	InfraAPI                        types.InfraAPI
	ResolverClient                  resolver.Interface
	RestServer                      *http.Server
	npmClient, tsmClient, tpmClient *rpckit.RPCClient
	cancelWatcher                   context.CancelFunc
	factory                         *rpckit.RPCClientFactory
	npmURL, tpmURL, tsmURL          string
}

// RestServer implements REST APIs
type RestServer struct {
	Server      *http.Server
	PipelineAPI types.PipelineAPI
}

// NewControllerAPI returns a new Controller API Handler
func NewControllerAPI(p types.PipelineAPI, i types.InfraAPI, npmURL, tpmURL, tsmURL, restURL string) *API {
	c := &API{
		PipelineAPI: p,
		InfraAPI:    i,
		npmURL:      npmURL,
		tpmURL:      tpmURL,
		tsmURL:      tsmURL,
	}
	c.RestServer = c.newRestServer(restURL, c.PipelineAPI)
	return c
}

func (c *API) newRestServer(url string, pipelineAPI types.PipelineAPI) *http.Server {
	c.Lock()
	defer c.Unlock()
	if len(url) == 0 {
		url = types.DefaultAgentRestURL
	}
	listener, err := net.Listen("tcp", url)
	if err != nil {
		log.Error(errors.Wrapf(types.ErrRESTServerStart, "Controller API: %s", err))
		return nil
	}

	// create a http server
	router := mux.NewRouter()
	srv := &http.Server{Addr: url, Handler: router}
	go func() {
		if err := srv.Serve(listener); err != nil {
			log.Error(errors.Wrapf(types.ErrRESTServerStart, "Controller API: %s", err))
		}
	}()

	agServer, err := restapi.NewRestServer(pipelineAPI, url)
	if err != nil {
		log.Error(errors.Wrapf(types.ErrRESTServerCreate, "Controller API: %s", err))
	}
	// Register URLs
	prefixRoutes := map[string]types.SubRouterAddFunc{
		"/api/apps/":                  agServer.AddAppAPIRoutes,
		"/api/endpoints/":             agServer.AddEndpointAPIRoutes,
		"/api/interfaces/":            agServer.AddInterfaceAPIRoutes,
		"/api/networks/":              agServer.AddNetworkAPIRoutes,
		"/api/security/policies/":     agServer.AddNetworkSecurityPolicyAPIRoutes,
		"/api/tunnels/":               agServer.AddTunnelAPIRoutes,
		"/api/vrfs":                   agServer.AddVrfAPIRoutes,
		"/api/security/profiles/":     agServer.AddSecurityProfileAPIRoutes,
		"/api/mirror/sessions/":       agServer.AddMirrorSessionAPIRoutes,
		"/api/telemetry/flowexports/": agServer.AddFlowExportPolicyAPIRoutes,
		"/api/mode/":                  c.addVeniceCoordinateRoutes,
		"/api/debug/":                 c.addDebugRoutes,
		"/api/mapping/":               c.addAPIMappingRoutes,
	}

	for prefix, subRouter := range prefixRoutes {
		sub := router.PathPrefix(prefix).Subrouter().StrictSlash(true)
		subRouter(sub)
	}

	return srv
}

// HandleVeniceCoordinates is the server side method for NetAgent to act on the mode switch and connect to Venice
func (c *API) HandleVeniceCoordinates(obj types.DistributedServiceCardStatus) error {
	c.Lock()
	defer c.Unlock()
	log.Infof("Controller API: %s | Obj: %v", types.InfoHandlingVeniceCoordinates, obj)
	c.InfraAPI.StoreConfig(obj)
	if strings.Contains(strings.ToLower(obj.DSCMode), "network") && len(obj.Controllers) != 0 {

		// Replay stored configs. This is a best-effort replay. Not marking errors as fatal since controllers will
		// eventually get the configs to a cluster-wide consistent state
		if err := c.PipelineAPI.ReplayConfigs(); err != nil {
			log.Error(err)
		}

		if c.ResolverClient == nil {
			c.ResolverClient = resolver.New(&resolver.Config{Name: types.Netagent, Servers: obj.Controllers})
		} else {
			log.Infof("Controller API: %s | Obj: %v", types.InfoUpdateVeniceCoordinates, obj.Controllers)
			c.ResolverClient.UpdateServers(obj.Controllers)
		}

		// Clean up older go-routines. This makes calls to Start idempotent
		if c.cancelWatcher != nil {
			log.Infof("Controller API: %s", types.InfoNPMWatcherReaped)
			if err := c.Stop(); err != nil {
				log.Error(errors.Wrapf(types.ErrControllerWatcherStop, "Controller API: %s", err))
			}
		}

		c.factory = rpckit.NewClientFactory(c.InfraAPI.GetDscName())
		log.Infof("Controller API: %s | Info: %s", c.factory, types.InfoRPClientFactoryInit)
		c.WatchCtx, c.cancelWatcher = context.WithCancel(context.Background())
		c.Add(1)
		// Start NPM Watcher Loop
		go func() {
			if err := c.Start(c.WatchCtx); err != nil {
				log.Error(errors.Wrapf(types.ErrNPMControllerStart, "Controller API: %s", err))
			}
		}()

		tsdb.Init(c.WatchCtx, &tsdb.Opts{
			ClientName:     types.Netagent,
			ResolverClient: c.ResolverClient})
	} else if strings.Contains(strings.ToLower(obj.DSCMode), "host") {
		if err := c.Stop(); err != nil {
			log.Error(errors.Wrapf(types.ErrControllerWatcherStop, "Controller API: %s", err))
		}

		if err := c.PipelineAPI.PurgeConfigs(); err != nil {
			log.Error(err)
		}
	}

	return nil
}

// Start starts the control loop for connecting to Venice
func (c *API) Start(ctx context.Context) error {
	defer c.Done()
	for {
		select {
		case <-ctx.Done():
			log.Infof("Controller API: %s", types.InfoNPMWatcherDone)
			return nil
		default:
		}

		// TODO unify this on Venice side to have a single config controller
		c.npmClient, _ = c.factory.NewRPCClient(
			c.InfraAPI.GetDscName(),
			c.npmURL,
			rpckit.WithBalancer(balancer.New(c.ResolverClient)),
			rpckit.WithRemoteServerName(types.Npm))

		c.tsmClient, _ = c.factory.NewRPCClient(
			c.InfraAPI.GetDscName(),
			c.tsmURL,
			rpckit.WithBalancer(balancer.New(c.ResolverClient)),
			rpckit.WithRemoteServerName(types.Tsm))

		c.tpmClient, _ = c.factory.NewRPCClient(
			c.InfraAPI.GetDscName(),
			c.tpmURL,
			rpckit.WithBalancer(balancer.New(c.ResolverClient)),
			rpckit.WithRemoteServerName(types.Tpm))

		if c.npmClient != nil && c.tpmClient != nil && c.tsmClient != nil {
			log.Infof("Controller API: %s", types.InfoConnectedToNPM)
			log.Infof("Controller API: %s", types.InfoConnectedToTSM)
			log.Infof("Controller API: %s", types.InfoConnectedToTPM)
			c.InfraAPI.NotifyVeniceConnection()
		} else {
			// Loop forever connect to all controllers NPM, TPM and TSM. Handle cascading closures to prevent leaks
			if c.npmClient != nil {
				if err := c.npmClient.Close(); err != nil {
					log.Error(errors.Wrapf(types.ErrNPMWatcherClose, "Controller API: %s", err))
				}
			}

			//TODO uncomment this once the TSM and TPM move to agg watch.
			//if c.tsmClient != nil {
			//	if err := c.npmClient.Close(); err != nil {
			//		log.Error(errors.Wrapf(types.ErrTSMWatcherClose, "Controller API: %s", err))
			//	}
			//}
			//
			//if c.tpmClient != nil {
			//	if err := c.npmClient.Close(); err != nil {
			//		log.Error(errors.Wrapf(types.ErrTPMWatcherClose, "Controller API: %s", err))
			//	}
			//}
			log.Infof("Controller API: %s", types.InfoControllerReconnecting)
			time.Sleep(types.ControllerWaitDelay)
			continue
		}

		opts := &tsdb.Opts{
			ClientName:              types.Netagent + c.InfraAPI.GetDscName(),
			ResolverClient:          c.ResolverClient,
			Collector:               types.Collector,
			DBName:                  "default",
			SendInterval:            types.StatsSendInterval,
			ConnectionRetryInterval: types.StatsRetryInterval,
		}

		tsdb.Init(c.WatchCtx, opts)
		log.Infof("Controller API: %s", types.InfoTSDBInitDone)

		nimbusClient, err := nimbus.NewNimbusClient(c.InfraAPI.GetDscName(), c.npmURL, c.npmClient)
		if err != nil {
			log.Error(errors.Wrapf(types.ErrNimbusClient, "Controller API: %s", err))
			time.Sleep(types.ControllerWaitDelay)
			continue
		}

		go func() {
			log.Infof("Controller API: %s", types.InfoAggWatchStarted)
			if err := nimbusClient.WatchAggregate(c.WatchCtx, []string{"App", "NetworkSecurityPolicy"}, c.PipelineAPI); err != nil {
				log.Error(errors.Wrapf(types.ErrAggregateWatch, "Controller API: %s", err))
			}
		}()

		go func() {
			if err := nimbusClient.WatchAggregate(c.WatchCtx, []string{"Network", "Endpoint"}, c.PipelineAPI); err != nil {
				log.Error(errors.Wrapf(types.ErrAggregateWatch, "Controller API: %s", err))
			}
		}()

		go func() {
			if err := nimbusClient.WatchAggregate(c.WatchCtx, []string{"SecurityProfile"}, c.PipelineAPI); err != nil {
				log.Error(errors.Wrapf(types.ErrAggregateWatch, "Controller API: %s", err))
			}

		}()

		go func() {
			if err := nimbusClient.WatchAggregate(c.WatchCtx, []string{"RoutingConfig"}, c.PipelineAPI); err != nil {
				log.Error(errors.Wrapf(types.ErrAggregateWatch, "Controller API: %s", err))
			}
		}()

		c.tsmWG.Add(1)
		tsmWatchCtx, tsmWatchCancel := context.WithCancel(c.WatchCtx)
		go func() {
			// TODO move this to AggWatch
			if err := c.runMirrorSessionWatcher(tsmWatchCtx); err != nil {
				log.Error(errors.Wrapf(types.ErrMirrorSessionWatch, "Controller API: %s", err))
			}
		}()

		c.tpmWG.Add(1)
		tpmWatchCtx, tpmWatchCancel := context.WithCancel(c.WatchCtx)
		go func() {
			// TODO move this to AggWatch
			if err := c.runFlowExportPolicyWatcher(tpmWatchCtx); err != nil {
				log.Error(errors.Wrapf(types.ErrFlowExportPolicyWatch, "Controller API: %s", err))
			}
		}()

		// TODO Watch for Mirror and NetflowSessions
		time.Sleep(time.Millisecond * 100)
		nimbusClient.Wait()
		tsmWatchCancel()
		tpmWatchCancel()
	}
}

// Stop cancels all watchers and closes all clients to venice controllers
func (c *API) Stop() error {
	if c.cancelWatcher != nil {
		c.cancelWatcher()
	}

	if c.npmClient != nil {
		if err := c.npmClient.Close(); err != nil {
			log.Error(errors.Wrapf(types.ErrNPMWatcherClose, "Controller API: %s", err))
		}
	}

	if c.tsmClient != nil {
		if err := c.tsmClient.Close(); err != nil {
			log.Error(errors.Wrapf(types.ErrTSMWatcherClose, "Controller API: %s", err))
		}
	}

	if c.tpmClient != nil {
		if err := c.tpmClient.Close(); err != nil {
			log.Error(errors.Wrapf(types.ErrTPMWatcherClose, "Controller API: %s", err))
		}
	}
	return nil
}

func (c *API) runMirrorSessionWatcher(ctx context.Context) error {
	defer c.tsmWG.Done()
	for {
		select {
		case <-ctx.Done():
			log.Infof("Controller API: %s", types.InfoTSMWatcherDone)
			return nil
		default:
		}

		mirrorClient := netproto.NewMirrorSessionApiV1Client(c.tsmClient.ClientConn)
		if c.tsmClient == nil || mirrorClient == nil {
			log.Error(errors.Wrapf(types.ErrTSMUnavailable, "Controller API: %v", c))
			return errors.Wrapf(types.ErrTSMUnavailable, "Controller API: %v", c)
		}
		fmt.Println("BALERION: ", mirrorClient)
		stream, err := mirrorClient.WatchMirrorSessions(c.WatchCtx, &api.ObjectMeta{})
		if err != nil || stream == nil {
			log.Error(errors.Wrapf(types.ErrMirrorSessionStream, "Controller API: %s", err))
			return errors.Wrapf(types.ErrMirrorSessionStream, "Controller API: %s", err)
		}

		mc := make(chan *netproto.MirrorSessionEventList)
		go func() {
			defer close(mc)
			for {
				evtList, err := stream.Recv()
				if err != nil {
					log.Errorf("Error receiving from watch channel. Exiting trouble shooting watch. Err: %v", err)
					return
				}
				mc <- evtList
			}
		}()

	loop:
		for {
			select {
			case evtList, ok := <-mc:
				if !ok { // channel closed
					log.Errorf("exit processing mirror policy")
					time.Sleep(time.Second)
					break loop
				}
				for _, evt := range evtList.MirrorSessionEvents {
					func() {
						log.Infof("Got Mirror Session Event. Evt: %v | Info: %s ", evt, types.InfoMirrorSessionEvt)
						// Retry hardcoded
						for iter := 0; iter < 3; iter++ {
							var err error
							var oper types.Operation

							switch evt.EventType {
							case api.EventType_CreateEvent:
								oper = types.Create
							case api.EventType_UpdateEvent:
								oper = types.Update
							case api.EventType_DeleteEvent:
								oper = types.Delete
							default:
								log.Errorf("Invalid mirror event type: {%+v}", evt.EventType)
								return
							}

							if _, err = c.PipelineAPI.HandleMirrorSession(oper, *evt.MirrorSession); err != nil {
								log.Error(errors.Wrapf(types.ErrMirrorSessionControllerHandle, "Controller API: Oper: %s | Err: %s", oper.String(), err))
							}

							if err == nil { // return on success
								return
							}

							log.Errorf("failed to apply %v %v, error: %v", evt.MirrorSession.GetName(), evt.EventType, err)
							time.Sleep(time.Second * 5)
						}

						//recorder.Event(eventtypes.CONFIG_FAIL, fmt.Sprintf("Failed to %v %v %v",
						//	strings.Split(strings.ToLower(evt.EventType.String()), "-event")[0], evt.MirrorSession.Kind, evt.MirrorSession.Name), evt.MirrorSession)
					}()
				}
				// Resyncs are going to go away once mirror moves to agg watch
				//case <-time.After(types.SyncInterval):
				//	eventList, err := mirrorClient.ListMirrorSessions(ctx, &api.ObjectMeta{})
				//	if err == nil {
				//		ctrlMs := map[string]*netproto.MirrorSession{}
				//		for i := range eventList.MirrorSessionEvents {
				//			ev := eventList.MirrorSessionEvents[i]
				//			ctrlMs[ev.MirrorSession.GetKey()] = ev.MirrorSession
				//		}
				//
				//		// read policy from agent
				//		agMs := client.tsagent.ListMirrorSession()
				//		for _, pol := range agMs {
				//			if _, ok := ctrlMs[pol.GetKey()]; !ok {
				//				log.Infof("sync deleting mirror session %v", pol.GetKey())
				//				if err := client.tsagent.DeleteMirrorSession(pol); err != nil {
				//					log.Errorf("failed to delete %v, err: %v", pol.GetKey(), err)
				//				}
				//			}
				//		}
				//	}
			}
		}
	}
}

func (c *API) runFlowExportPolicyWatcher(ctx context.Context) error {
	defer c.tpmWG.Done()
	for {
		select {
		case <-ctx.Done():
			log.Infof("Controller API: %s", types.InfoTPMWatcherDone)
			return nil
		default:
		}

		if c.tpmClient == nil {
			log.Error(errors.Wrapf(types.ErrTPMUnavailable, "Controller API: %v", c))
			return errors.Wrapf(types.ErrTPMUnavailable, "Controller API: %v", c)
		}

		netflowClient := netproto.NewFlowExportPolicyApiV1Client(c.tpmClient.ClientConn)
		stream, err := netflowClient.WatchFlowExportPolicy(c.WatchCtx, &api.ObjectMeta{})
		if err != nil || stream == nil {
			log.Error(errors.Wrapf(types.ErrFlowExportPolicyStream, "Controller API: %s", err))
			return errors.Wrapf(types.ErrFlowExportPolicyStream, "Controller API: %s", err)
		}

		mc := make(chan *netproto.FlowExportPolicyEventList)
		go func() {
			defer close(mc)
			for {
				evtList, err := stream.Recv()
				if err != nil {
					log.Errorf("Error receiving from watch channel. Exiting trouble shooting watch. Err: %v", err)
					return
				}
				mc <- evtList
			}
		}()

	loop:
		for {
			select {
			case evtList, ok := <-mc:
				if !ok { // channel closed
					log.Errorf("exit processing netflow policy")
					time.Sleep(time.Second)
					break loop
				}
				for _, evt := range evtList.FlowExportPolicyEvents {
					func() {
						log.Infof("Got Mirror Session Event. Evt: %v | Info: %s ", evt, types.InfoFlowExportPolicyEvt)
						// Retry hardcoded
						for iter := 0; iter < 3; iter++ {
							var err error
							var oper types.Operation

							switch evt.EventType {
							case api.EventType_CreateEvent:
								oper = types.Create
							case api.EventType_UpdateEvent:
								oper = types.Update
							case api.EventType_DeleteEvent:
								oper = types.Delete
							default:
								log.Errorf("Invalid netflow event type: {%+v}", evt.EventType)
								return
							}

							if _, err = c.PipelineAPI.HandleFlowExportPolicy(oper, *evt.Policy); err != nil {
								log.Error(errors.Wrapf(types.ErrFlowExportPolicyControllerHandle, "Controller API: Oper: %s | Err: %s", oper.String(), err))
							}

							if err == nil { // return on success
								return
							}

							log.Errorf("failed to apply %v %v, error: %v", evt.Policy.GetName(), evt.EventType, err)
							time.Sleep(time.Second * 5)
						}

						//recorder.Event(eventtypes.CONFIG_FAIL, fmt.Sprintf("Failed to %v %v %v",
						//	strings.Split(strings.ToLower(evt.EventType.String()), "-event")[0], evt.Policy.Kind, evt.Policy.Name), evt.Policy)
					}()
				}
				// Resyncs are going to go away once netflow moves to agg watch
				//case <-time.After(types.SyncInterval):
				//	eventList, err := netflowClient.ListFlowExportPolicys(ctx, &api.ObjectMeta{})
				//	if err == nil {
				//		ctrlMs := map[string]*netproto.FlowExportPolicy{}
				//		for i := range eventList.FlowExportPolicyEvents {
				//			ev := eventList.FlowExportPolicyEvents[i]
				//			ctrlMs[ev.FlowExportPolicy.GetKey()] = ev.FlowExportPolicy
				//		}
				//
				//		// read policy from agent
				//		agMs := client.tsagent.ListFlowExportPolicy()
				//		for _, pol := range agMs {
				//			if _, ok := ctrlMs[pol.GetKey()]; !ok {
				//				log.Infof("sync deleting netflow session %v", pol.GetKey())
				//				if err := client.tsagent.DeleteFlowExportPolicy(pol); err != nil {
				//					log.Errorf("failed to delete %v, err: %v", pol.GetKey(), err)
				//				}
				//			}
				//		}
				//	}
			}
		}
	}
}

// TODO Start netif worker here. Start handling continuous updates and not just once. This may not be needed since interface_mclient is already doing this
//// createNpmNetIfs creates network-interface object in npm to reflect the interface status to the user
//func (c *API) netifWorker() {
//
//	netIfRPCClient := netproto.NewInterfaceApiClient(c.npmClient.ClientConn)
//	idPrefix := c.InfraAPI.GetDscName()
//
//	// fetch interfaes discovered by hw and populate them in npm
//	intf := &netproto.Interface{
//		TypeMeta: api.TypeMeta{Kind: "Interface"},
//	}
//	interfaces, _ := c.PipelineAPI.HandleInterface(types.List, intf)
//	for _, i := range interfaces {
//		netif := *i
//		netif.ObjectMeta.Name = idPrefix + "-" + netif.ObjectMeta.Name
//		if _, err := netIfRPCClient.CreateInterface(context.Background(), &netif); err != nil {
//			log.Errorf("Error resp from netctrler for netif create {%+v}. Err: %v", netif, err)
//			continue
//		}
//	}
//}

// addVeniceCoordinateRoutes responds to mode change request
func (c *API) addVeniceCoordinateRoutes(r *mux.Router) {

	r.Methods("GET").Subrouter().HandleFunc("/", httputils.MakeHTTPHandler(c.getConfigHandler))

	r.Methods("POST").Subrouter().HandleFunc("/", httputils.MakeHTTPHandler(c.postConfigHandler))
}

func (c *API) addDebugRoutes(r *mux.Router) {
	r.Methods("GET").Subrouter().HandleFunc("/", pprof.Index)
	r.Methods("GET").Subrouter().HandleFunc("/cmdline", pprof.Cmdline)
	r.Methods("GET").Subrouter().HandleFunc("/profile", pprof.Profile)
	r.Methods("GET").Subrouter().HandleFunc("/symbol", pprof.Symbol)
	r.Methods("GET").Subrouter().HandleFunc("/trace", pprof.Trace)
	r.Methods("GET").Subrouter().HandleFunc("/allocs", pprof.Handler("allocs").ServeHTTP)
	r.Methods("GET").Subrouter().HandleFunc("/block", pprof.Handler("block").ServeHTTP)
	r.Methods("GET").Subrouter().HandleFunc("/heap", pprof.Handler("heap").ServeHTTP)
	r.Methods("GET").Subrouter().HandleFunc("/mutex", pprof.Handler("mutex").ServeHTTP)
	r.Methods("GET").Subrouter().HandleFunc("/goroutine", pprof.Handler("goroutine").ServeHTTP)
	r.Methods("GET").Subrouter().HandleFunc("/threadcreate", pprof.Handler("threadcreate").ServeHTTP)

}

func (c *API) addAPIMappingRoutes(r *mux.Router) {
	r.Methods("GET").Subrouter().HandleFunc("/interfaces/{id}", httputils.MakeHTTPHandler(c.getMappingHandler))
}

func (c *API) getConfigHandler(r *http.Request) (interface{}, error) {
	return c.InfraAPI.GetConfig(), nil
}

func (c *API) postConfigHandler(r *http.Request) (interface{}, error) {
	var o types.DistributedServiceCardStatus
	b, _ := ioutil.ReadAll(r.Body)
	err := json.Unmarshal(b, &o)
	if err != nil {
		return nil, err
	}
	var resp restapi.Response
	err = c.HandleVeniceCoordinates(o)
	if err != nil {
		resp.StatusCode = http.StatusInternalServerError
		resp.Error = err.Error()
	} else {
		resp.StatusCode = http.StatusOK
	}

	return nil, err
}

func (c *API) getMappingHandler(r *http.Request) (interface{}, error) {
	var resp restapi.Response
	o := netproto.Interface{
		TypeMeta: api.TypeMeta{Kind: "Interface"},
	}

	id, _ := mux.Vars(r)["id"]
	intfID, err := strconv.ParseInt(id, 10, 64)
	if err != nil {
		resp.StatusCode = http.StatusBadRequest
		resp.Error = err.Error()
		return resp, err
	}
	intfs, err := c.PipelineAPI.HandleInterface(types.List, o)
	if err != nil {
		resp.StatusCode = http.StatusNotFound
		resp.Error = err.Error()
		return resp, err
	}

	for _, i := range intfs {
		if i.Status.InterfaceID == uint64(intfID) {
			resp.StatusCode = http.StatusOK
			return i, nil
		}
	}

	resp.StatusCode = http.StatusNotFound
	resp.Error = fmt.Sprintf("Interface: %d not found", intfID)
	return resp, err
}
