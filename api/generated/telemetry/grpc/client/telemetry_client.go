// Code generated by protoc-gen-grpc-pensando DO NOT EDIT.

package grpcclient

import (
	"context"
	"errors"
	oldlog "log"

	"github.com/go-kit/kit/endpoint"
	grpctransport "github.com/go-kit/kit/transport/grpc"
	"google.golang.org/grpc"

	api "github.com/pensando/sw/api"
	telemetry "github.com/pensando/sw/api/generated/telemetry"
	listerwatcher "github.com/pensando/sw/api/listerwatcher"
	apiserver "github.com/pensando/sw/venice/apiserver"
	"github.com/pensando/sw/venice/utils/kvstore"
	"github.com/pensando/sw/venice/utils/log"
	"github.com/pensando/sw/venice/utils/trace"
)

// Dummy vars to suppress import errors
var _ api.TypeMeta
var _ listerwatcher.WatcherClient
var _ kvstore.Interface

// NewFlowExportPolicyV1 sets up a new client for FlowExportPolicyV1
func NewFlowExportPolicyV1(conn *grpc.ClientConn, logger log.Logger) telemetry.ServiceFlowExportPolicyV1Client {

	var lAutoAddFlowExportPolicyEndpoint endpoint.Endpoint
	{
		lAutoAddFlowExportPolicyEndpoint = grpctransport.NewClient(
			conn,
			"telemetry.FlowExportPolicyV1",
			"AutoAddFlowExportPolicy",
			telemetry.EncodeGrpcReqFlowExportPolicy,
			telemetry.DecodeGrpcRespFlowExportPolicy,
			&telemetry.FlowExportPolicy{},
			grpctransport.ClientBefore(trace.ToGRPCRequest(logger)),
			grpctransport.ClientBefore(dummyBefore),
		).Endpoint()
		lAutoAddFlowExportPolicyEndpoint = trace.ClientEndPoint("FlowExportPolicyV1:AutoAddFlowExportPolicy")(lAutoAddFlowExportPolicyEndpoint)
	}
	var lAutoDeleteFlowExportPolicyEndpoint endpoint.Endpoint
	{
		lAutoDeleteFlowExportPolicyEndpoint = grpctransport.NewClient(
			conn,
			"telemetry.FlowExportPolicyV1",
			"AutoDeleteFlowExportPolicy",
			telemetry.EncodeGrpcReqFlowExportPolicy,
			telemetry.DecodeGrpcRespFlowExportPolicy,
			&telemetry.FlowExportPolicy{},
			grpctransport.ClientBefore(trace.ToGRPCRequest(logger)),
			grpctransport.ClientBefore(dummyBefore),
		).Endpoint()
		lAutoDeleteFlowExportPolicyEndpoint = trace.ClientEndPoint("FlowExportPolicyV1:AutoDeleteFlowExportPolicy")(lAutoDeleteFlowExportPolicyEndpoint)
	}
	var lAutoGetFlowExportPolicyEndpoint endpoint.Endpoint
	{
		lAutoGetFlowExportPolicyEndpoint = grpctransport.NewClient(
			conn,
			"telemetry.FlowExportPolicyV1",
			"AutoGetFlowExportPolicy",
			telemetry.EncodeGrpcReqFlowExportPolicy,
			telemetry.DecodeGrpcRespFlowExportPolicy,
			&telemetry.FlowExportPolicy{},
			grpctransport.ClientBefore(trace.ToGRPCRequest(logger)),
			grpctransport.ClientBefore(dummyBefore),
		).Endpoint()
		lAutoGetFlowExportPolicyEndpoint = trace.ClientEndPoint("FlowExportPolicyV1:AutoGetFlowExportPolicy")(lAutoGetFlowExportPolicyEndpoint)
	}
	var lAutoListFlowExportPolicyEndpoint endpoint.Endpoint
	{
		lAutoListFlowExportPolicyEndpoint = grpctransport.NewClient(
			conn,
			"telemetry.FlowExportPolicyV1",
			"AutoListFlowExportPolicy",
			telemetry.EncodeGrpcReqListWatchOptions,
			telemetry.DecodeGrpcRespFlowExportPolicyList,
			&telemetry.FlowExportPolicyList{},
			grpctransport.ClientBefore(trace.ToGRPCRequest(logger)),
			grpctransport.ClientBefore(dummyBefore),
		).Endpoint()
		lAutoListFlowExportPolicyEndpoint = trace.ClientEndPoint("FlowExportPolicyV1:AutoListFlowExportPolicy")(lAutoListFlowExportPolicyEndpoint)
	}
	var lAutoUpdateFlowExportPolicyEndpoint endpoint.Endpoint
	{
		lAutoUpdateFlowExportPolicyEndpoint = grpctransport.NewClient(
			conn,
			"telemetry.FlowExportPolicyV1",
			"AutoUpdateFlowExportPolicy",
			telemetry.EncodeGrpcReqFlowExportPolicy,
			telemetry.DecodeGrpcRespFlowExportPolicy,
			&telemetry.FlowExportPolicy{},
			grpctransport.ClientBefore(trace.ToGRPCRequest(logger)),
			grpctransport.ClientBefore(dummyBefore),
		).Endpoint()
		lAutoUpdateFlowExportPolicyEndpoint = trace.ClientEndPoint("FlowExportPolicyV1:AutoUpdateFlowExportPolicy")(lAutoUpdateFlowExportPolicyEndpoint)
	}
	return telemetry.EndpointsFlowExportPolicyV1Client{
		Client: telemetry.NewFlowExportPolicyV1Client(conn),

		AutoAddFlowExportPolicyEndpoint:    lAutoAddFlowExportPolicyEndpoint,
		AutoDeleteFlowExportPolicyEndpoint: lAutoDeleteFlowExportPolicyEndpoint,
		AutoGetFlowExportPolicyEndpoint:    lAutoGetFlowExportPolicyEndpoint,
		AutoListFlowExportPolicyEndpoint:   lAutoListFlowExportPolicyEndpoint,
		AutoUpdateFlowExportPolicyEndpoint: lAutoUpdateFlowExportPolicyEndpoint,
	}
}

// NewFlowExportPolicyV1Backend creates an instrumented client with middleware
func NewFlowExportPolicyV1Backend(conn *grpc.ClientConn, logger log.Logger) telemetry.ServiceFlowExportPolicyV1Client {
	cl := NewFlowExportPolicyV1(conn, logger)
	cl = telemetry.LoggingFlowExportPolicyV1MiddlewareClient(logger)(cl)
	return cl
}

// NewFwlogPolicyV1 sets up a new client for FwlogPolicyV1
func NewFwlogPolicyV1(conn *grpc.ClientConn, logger log.Logger) telemetry.ServiceFwlogPolicyV1Client {

	var lAutoAddFwlogPolicyEndpoint endpoint.Endpoint
	{
		lAutoAddFwlogPolicyEndpoint = grpctransport.NewClient(
			conn,
			"telemetry.FwlogPolicyV1",
			"AutoAddFwlogPolicy",
			telemetry.EncodeGrpcReqFwlogPolicy,
			telemetry.DecodeGrpcRespFwlogPolicy,
			&telemetry.FwlogPolicy{},
			grpctransport.ClientBefore(trace.ToGRPCRequest(logger)),
			grpctransport.ClientBefore(dummyBefore),
		).Endpoint()
		lAutoAddFwlogPolicyEndpoint = trace.ClientEndPoint("FwlogPolicyV1:AutoAddFwlogPolicy")(lAutoAddFwlogPolicyEndpoint)
	}
	var lAutoDeleteFwlogPolicyEndpoint endpoint.Endpoint
	{
		lAutoDeleteFwlogPolicyEndpoint = grpctransport.NewClient(
			conn,
			"telemetry.FwlogPolicyV1",
			"AutoDeleteFwlogPolicy",
			telemetry.EncodeGrpcReqFwlogPolicy,
			telemetry.DecodeGrpcRespFwlogPolicy,
			&telemetry.FwlogPolicy{},
			grpctransport.ClientBefore(trace.ToGRPCRequest(logger)),
			grpctransport.ClientBefore(dummyBefore),
		).Endpoint()
		lAutoDeleteFwlogPolicyEndpoint = trace.ClientEndPoint("FwlogPolicyV1:AutoDeleteFwlogPolicy")(lAutoDeleteFwlogPolicyEndpoint)
	}
	var lAutoGetFwlogPolicyEndpoint endpoint.Endpoint
	{
		lAutoGetFwlogPolicyEndpoint = grpctransport.NewClient(
			conn,
			"telemetry.FwlogPolicyV1",
			"AutoGetFwlogPolicy",
			telemetry.EncodeGrpcReqFwlogPolicy,
			telemetry.DecodeGrpcRespFwlogPolicy,
			&telemetry.FwlogPolicy{},
			grpctransport.ClientBefore(trace.ToGRPCRequest(logger)),
			grpctransport.ClientBefore(dummyBefore),
		).Endpoint()
		lAutoGetFwlogPolicyEndpoint = trace.ClientEndPoint("FwlogPolicyV1:AutoGetFwlogPolicy")(lAutoGetFwlogPolicyEndpoint)
	}
	var lAutoListFwlogPolicyEndpoint endpoint.Endpoint
	{
		lAutoListFwlogPolicyEndpoint = grpctransport.NewClient(
			conn,
			"telemetry.FwlogPolicyV1",
			"AutoListFwlogPolicy",
			telemetry.EncodeGrpcReqListWatchOptions,
			telemetry.DecodeGrpcRespFwlogPolicyList,
			&telemetry.FwlogPolicyList{},
			grpctransport.ClientBefore(trace.ToGRPCRequest(logger)),
			grpctransport.ClientBefore(dummyBefore),
		).Endpoint()
		lAutoListFwlogPolicyEndpoint = trace.ClientEndPoint("FwlogPolicyV1:AutoListFwlogPolicy")(lAutoListFwlogPolicyEndpoint)
	}
	var lAutoUpdateFwlogPolicyEndpoint endpoint.Endpoint
	{
		lAutoUpdateFwlogPolicyEndpoint = grpctransport.NewClient(
			conn,
			"telemetry.FwlogPolicyV1",
			"AutoUpdateFwlogPolicy",
			telemetry.EncodeGrpcReqFwlogPolicy,
			telemetry.DecodeGrpcRespFwlogPolicy,
			&telemetry.FwlogPolicy{},
			grpctransport.ClientBefore(trace.ToGRPCRequest(logger)),
			grpctransport.ClientBefore(dummyBefore),
		).Endpoint()
		lAutoUpdateFwlogPolicyEndpoint = trace.ClientEndPoint("FwlogPolicyV1:AutoUpdateFwlogPolicy")(lAutoUpdateFwlogPolicyEndpoint)
	}
	return telemetry.EndpointsFwlogPolicyV1Client{
		Client: telemetry.NewFwlogPolicyV1Client(conn),

		AutoAddFwlogPolicyEndpoint:    lAutoAddFwlogPolicyEndpoint,
		AutoDeleteFwlogPolicyEndpoint: lAutoDeleteFwlogPolicyEndpoint,
		AutoGetFwlogPolicyEndpoint:    lAutoGetFwlogPolicyEndpoint,
		AutoListFwlogPolicyEndpoint:   lAutoListFwlogPolicyEndpoint,
		AutoUpdateFwlogPolicyEndpoint: lAutoUpdateFwlogPolicyEndpoint,
	}
}

// NewFwlogPolicyV1Backend creates an instrumented client with middleware
func NewFwlogPolicyV1Backend(conn *grpc.ClientConn, logger log.Logger) telemetry.ServiceFwlogPolicyV1Client {
	cl := NewFwlogPolicyV1(conn, logger)
	cl = telemetry.LoggingFwlogPolicyV1MiddlewareClient(logger)(cl)
	return cl
}

// NewStatsPolicyV1 sets up a new client for StatsPolicyV1
func NewStatsPolicyV1(conn *grpc.ClientConn, logger log.Logger) telemetry.ServiceStatsPolicyV1Client {

	var lAutoAddStatsPolicyEndpoint endpoint.Endpoint
	{
		lAutoAddStatsPolicyEndpoint = grpctransport.NewClient(
			conn,
			"telemetry.StatsPolicyV1",
			"AutoAddStatsPolicy",
			telemetry.EncodeGrpcReqStatsPolicy,
			telemetry.DecodeGrpcRespStatsPolicy,
			&telemetry.StatsPolicy{},
			grpctransport.ClientBefore(trace.ToGRPCRequest(logger)),
			grpctransport.ClientBefore(dummyBefore),
		).Endpoint()
		lAutoAddStatsPolicyEndpoint = trace.ClientEndPoint("StatsPolicyV1:AutoAddStatsPolicy")(lAutoAddStatsPolicyEndpoint)
	}
	var lAutoDeleteStatsPolicyEndpoint endpoint.Endpoint
	{
		lAutoDeleteStatsPolicyEndpoint = grpctransport.NewClient(
			conn,
			"telemetry.StatsPolicyV1",
			"AutoDeleteStatsPolicy",
			telemetry.EncodeGrpcReqStatsPolicy,
			telemetry.DecodeGrpcRespStatsPolicy,
			&telemetry.StatsPolicy{},
			grpctransport.ClientBefore(trace.ToGRPCRequest(logger)),
			grpctransport.ClientBefore(dummyBefore),
		).Endpoint()
		lAutoDeleteStatsPolicyEndpoint = trace.ClientEndPoint("StatsPolicyV1:AutoDeleteStatsPolicy")(lAutoDeleteStatsPolicyEndpoint)
	}
	var lAutoGetStatsPolicyEndpoint endpoint.Endpoint
	{
		lAutoGetStatsPolicyEndpoint = grpctransport.NewClient(
			conn,
			"telemetry.StatsPolicyV1",
			"AutoGetStatsPolicy",
			telemetry.EncodeGrpcReqStatsPolicy,
			telemetry.DecodeGrpcRespStatsPolicy,
			&telemetry.StatsPolicy{},
			grpctransport.ClientBefore(trace.ToGRPCRequest(logger)),
			grpctransport.ClientBefore(dummyBefore),
		).Endpoint()
		lAutoGetStatsPolicyEndpoint = trace.ClientEndPoint("StatsPolicyV1:AutoGetStatsPolicy")(lAutoGetStatsPolicyEndpoint)
	}
	var lAutoListStatsPolicyEndpoint endpoint.Endpoint
	{
		lAutoListStatsPolicyEndpoint = grpctransport.NewClient(
			conn,
			"telemetry.StatsPolicyV1",
			"AutoListStatsPolicy",
			telemetry.EncodeGrpcReqListWatchOptions,
			telemetry.DecodeGrpcRespStatsPolicyList,
			&telemetry.StatsPolicyList{},
			grpctransport.ClientBefore(trace.ToGRPCRequest(logger)),
			grpctransport.ClientBefore(dummyBefore),
		).Endpoint()
		lAutoListStatsPolicyEndpoint = trace.ClientEndPoint("StatsPolicyV1:AutoListStatsPolicy")(lAutoListStatsPolicyEndpoint)
	}
	var lAutoUpdateStatsPolicyEndpoint endpoint.Endpoint
	{
		lAutoUpdateStatsPolicyEndpoint = grpctransport.NewClient(
			conn,
			"telemetry.StatsPolicyV1",
			"AutoUpdateStatsPolicy",
			telemetry.EncodeGrpcReqStatsPolicy,
			telemetry.DecodeGrpcRespStatsPolicy,
			&telemetry.StatsPolicy{},
			grpctransport.ClientBefore(trace.ToGRPCRequest(logger)),
			grpctransport.ClientBefore(dummyBefore),
		).Endpoint()
		lAutoUpdateStatsPolicyEndpoint = trace.ClientEndPoint("StatsPolicyV1:AutoUpdateStatsPolicy")(lAutoUpdateStatsPolicyEndpoint)
	}
	return telemetry.EndpointsStatsPolicyV1Client{
		Client: telemetry.NewStatsPolicyV1Client(conn),

		AutoAddStatsPolicyEndpoint:    lAutoAddStatsPolicyEndpoint,
		AutoDeleteStatsPolicyEndpoint: lAutoDeleteStatsPolicyEndpoint,
		AutoGetStatsPolicyEndpoint:    lAutoGetStatsPolicyEndpoint,
		AutoListStatsPolicyEndpoint:   lAutoListStatsPolicyEndpoint,
		AutoUpdateStatsPolicyEndpoint: lAutoUpdateStatsPolicyEndpoint,
	}
}

// NewStatsPolicyV1Backend creates an instrumented client with middleware
func NewStatsPolicyV1Backend(conn *grpc.ClientConn, logger log.Logger) telemetry.ServiceStatsPolicyV1Client {
	cl := NewStatsPolicyV1(conn, logger)
	cl = telemetry.LoggingStatsPolicyV1MiddlewareClient(logger)(cl)
	return cl
}

type grpcObjFlowExportPolicyV1FlowExportPolicy struct {
	logger log.Logger
	client telemetry.ServiceFlowExportPolicyV1Client
}

func (a *grpcObjFlowExportPolicyV1FlowExportPolicy) Create(ctx context.Context, in *telemetry.FlowExportPolicy) (*telemetry.FlowExportPolicy, error) {
	a.logger.DebugLog("msg", "received call", "object", "FlowExportPolicy", "oper", "create")
	if in == nil {
		return nil, errors.New("invalid input")
	}
	nctx := addVersion(ctx, "v1")
	return a.client.AutoAddFlowExportPolicy(nctx, in)
}

func (a *grpcObjFlowExportPolicyV1FlowExportPolicy) Update(ctx context.Context, in *telemetry.FlowExportPolicy) (*telemetry.FlowExportPolicy, error) {
	a.logger.DebugLog("msg", "received call", "object", "FlowExportPolicy", "oper", "update")
	if in == nil {
		return nil, errors.New("invalid input")
	}
	nctx := addVersion(ctx, "v1")
	return a.client.AutoUpdateFlowExportPolicy(nctx, in)
}

func (a *grpcObjFlowExportPolicyV1FlowExportPolicy) Get(ctx context.Context, objMeta *api.ObjectMeta) (*telemetry.FlowExportPolicy, error) {
	a.logger.DebugLog("msg", "received call", "object", "FlowExportPolicy", "oper", "get")
	if objMeta == nil {
		return nil, errors.New("invalid input")
	}
	in := telemetry.FlowExportPolicy{}
	in.ObjectMeta = *objMeta
	nctx := addVersion(ctx, "v1")
	return a.client.AutoGetFlowExportPolicy(nctx, &in)
}

func (a *grpcObjFlowExportPolicyV1FlowExportPolicy) Delete(ctx context.Context, objMeta *api.ObjectMeta) (*telemetry.FlowExportPolicy, error) {
	a.logger.DebugLog("msg", "received call", "object", "FlowExportPolicy", "oper", "delete")
	if objMeta == nil {
		return nil, errors.New("invalid input")
	}
	in := telemetry.FlowExportPolicy{}
	in.ObjectMeta = *objMeta
	nctx := addVersion(ctx, "v1")
	return a.client.AutoDeleteFlowExportPolicy(nctx, &in)
}

func (a *grpcObjFlowExportPolicyV1FlowExportPolicy) List(ctx context.Context, options *api.ListWatchOptions) ([]*telemetry.FlowExportPolicy, error) {
	a.logger.DebugLog("msg", "received call", "object", "FlowExportPolicy", "oper", "list")
	if options == nil {
		return nil, errors.New("invalid input")
	}
	nctx := addVersion(ctx, "v1")
	r, err := a.client.AutoListFlowExportPolicy(nctx, options)
	if err == nil {
		return r.Items, nil
	}
	return nil, err
}

func (a *grpcObjFlowExportPolicyV1FlowExportPolicy) Watch(ctx context.Context, options *api.ListWatchOptions) (kvstore.Watcher, error) {
	a.logger.DebugLog("msg", "received call", "object", "FlowExportPolicy", "oper", "WatchOper")
	nctx := addVersion(ctx, "v1")
	if options == nil {
		return nil, errors.New("invalid input")
	}
	stream, err := a.client.AutoWatchFlowExportPolicy(nctx, options)
	if err != nil {
		return nil, err
	}
	wstream := stream.(telemetry.FlowExportPolicyV1_AutoWatchFlowExportPolicyClient)
	bridgefn := func(lw *listerwatcher.WatcherClient) {
		for {
			r, err := wstream.Recv()
			if err != nil {
				a.logger.ErrorLog("msg", "error on receive", "error", err)
				close(lw.OutCh)
				return
			}
			ev := kvstore.WatchEvent{
				Type:   kvstore.WatchEventType(r.Type),
				Object: r.Object,
			}
			select {
			case lw.OutCh <- &ev:
			case <-wstream.Context().Done():
				close(lw.OutCh)
				return
			}
		}
	}
	lw := listerwatcher.NewWatcherClient(wstream, bridgefn)
	lw.Run()
	return lw, nil
}

func (a *grpcObjFlowExportPolicyV1FlowExportPolicy) Allowed(oper apiserver.APIOperType) bool {
	return true
}

type restObjFlowExportPolicyV1FlowExportPolicy struct {
	endpoints telemetry.EndpointsFlowExportPolicyV1RestClient
	instance  string
}

func (a *restObjFlowExportPolicyV1FlowExportPolicy) Create(ctx context.Context, in *telemetry.FlowExportPolicy) (*telemetry.FlowExportPolicy, error) {
	if in == nil {
		return nil, errors.New("invalid input")
	}
	return a.endpoints.AutoAddFlowExportPolicy(ctx, in)
}

func (a *restObjFlowExportPolicyV1FlowExportPolicy) Update(ctx context.Context, in *telemetry.FlowExportPolicy) (*telemetry.FlowExportPolicy, error) {
	if in == nil {
		return nil, errors.New("invalid input")
	}
	return a.endpoints.AutoUpdateFlowExportPolicy(ctx, in)
}

func (a *restObjFlowExportPolicyV1FlowExportPolicy) Get(ctx context.Context, objMeta *api.ObjectMeta) (*telemetry.FlowExportPolicy, error) {
	if objMeta == nil {
		return nil, errors.New("invalid input")
	}
	in := telemetry.FlowExportPolicy{}
	in.ObjectMeta = *objMeta
	return a.endpoints.AutoGetFlowExportPolicy(ctx, &in)
}

func (a *restObjFlowExportPolicyV1FlowExportPolicy) Delete(ctx context.Context, objMeta *api.ObjectMeta) (*telemetry.FlowExportPolicy, error) {
	if objMeta == nil {
		return nil, errors.New("invalid input")
	}
	in := telemetry.FlowExportPolicy{}
	in.ObjectMeta = *objMeta
	return a.endpoints.AutoDeleteFlowExportPolicy(ctx, &in)
}

func (a *restObjFlowExportPolicyV1FlowExportPolicy) List(ctx context.Context, options *api.ListWatchOptions) ([]*telemetry.FlowExportPolicy, error) {
	if options == nil {
		return nil, errors.New("invalid input")
	}
	r, err := a.endpoints.AutoListFlowExportPolicy(ctx, options)
	if err == nil {
		return r.Items, nil
	}
	return nil, err
}

func (a *restObjFlowExportPolicyV1FlowExportPolicy) Watch(ctx context.Context, options *api.ListWatchOptions) (kvstore.Watcher, error) {
	return nil, errors.New("not allowed")
}

func (a *restObjFlowExportPolicyV1FlowExportPolicy) Allowed(oper apiserver.APIOperType) bool {
	switch oper {
	case apiserver.CreateOper:
		return true
	case apiserver.UpdateOper:
		return true
	case apiserver.GetOper:
		return true
	case apiserver.DeleteOper:
		return true
	case apiserver.ListOper:
		return true
	case apiserver.WatchOper:
		return false
	default:
		return false
	}
}

type grpcObjFwlogPolicyV1FwlogPolicy struct {
	logger log.Logger
	client telemetry.ServiceFwlogPolicyV1Client
}

func (a *grpcObjFwlogPolicyV1FwlogPolicy) Create(ctx context.Context, in *telemetry.FwlogPolicy) (*telemetry.FwlogPolicy, error) {
	a.logger.DebugLog("msg", "received call", "object", "FwlogPolicy", "oper", "create")
	if in == nil {
		return nil, errors.New("invalid input")
	}
	nctx := addVersion(ctx, "v1")
	return a.client.AutoAddFwlogPolicy(nctx, in)
}

func (a *grpcObjFwlogPolicyV1FwlogPolicy) Update(ctx context.Context, in *telemetry.FwlogPolicy) (*telemetry.FwlogPolicy, error) {
	a.logger.DebugLog("msg", "received call", "object", "FwlogPolicy", "oper", "update")
	if in == nil {
		return nil, errors.New("invalid input")
	}
	nctx := addVersion(ctx, "v1")
	return a.client.AutoUpdateFwlogPolicy(nctx, in)
}

func (a *grpcObjFwlogPolicyV1FwlogPolicy) Get(ctx context.Context, objMeta *api.ObjectMeta) (*telemetry.FwlogPolicy, error) {
	a.logger.DebugLog("msg", "received call", "object", "FwlogPolicy", "oper", "get")
	if objMeta == nil {
		return nil, errors.New("invalid input")
	}
	in := telemetry.FwlogPolicy{}
	in.ObjectMeta = *objMeta
	nctx := addVersion(ctx, "v1")
	return a.client.AutoGetFwlogPolicy(nctx, &in)
}

func (a *grpcObjFwlogPolicyV1FwlogPolicy) Delete(ctx context.Context, objMeta *api.ObjectMeta) (*telemetry.FwlogPolicy, error) {
	a.logger.DebugLog("msg", "received call", "object", "FwlogPolicy", "oper", "delete")
	if objMeta == nil {
		return nil, errors.New("invalid input")
	}
	in := telemetry.FwlogPolicy{}
	in.ObjectMeta = *objMeta
	nctx := addVersion(ctx, "v1")
	return a.client.AutoDeleteFwlogPolicy(nctx, &in)
}

func (a *grpcObjFwlogPolicyV1FwlogPolicy) List(ctx context.Context, options *api.ListWatchOptions) ([]*telemetry.FwlogPolicy, error) {
	a.logger.DebugLog("msg", "received call", "object", "FwlogPolicy", "oper", "list")
	if options == nil {
		return nil, errors.New("invalid input")
	}
	nctx := addVersion(ctx, "v1")
	r, err := a.client.AutoListFwlogPolicy(nctx, options)
	if err == nil {
		return r.Items, nil
	}
	return nil, err
}

func (a *grpcObjFwlogPolicyV1FwlogPolicy) Watch(ctx context.Context, options *api.ListWatchOptions) (kvstore.Watcher, error) {
	a.logger.DebugLog("msg", "received call", "object", "FwlogPolicy", "oper", "WatchOper")
	nctx := addVersion(ctx, "v1")
	if options == nil {
		return nil, errors.New("invalid input")
	}
	stream, err := a.client.AutoWatchFwlogPolicy(nctx, options)
	if err != nil {
		return nil, err
	}
	wstream := stream.(telemetry.FwlogPolicyV1_AutoWatchFwlogPolicyClient)
	bridgefn := func(lw *listerwatcher.WatcherClient) {
		for {
			r, err := wstream.Recv()
			if err != nil {
				a.logger.ErrorLog("msg", "error on receive", "error", err)
				close(lw.OutCh)
				return
			}
			ev := kvstore.WatchEvent{
				Type:   kvstore.WatchEventType(r.Type),
				Object: r.Object,
			}
			select {
			case lw.OutCh <- &ev:
			case <-wstream.Context().Done():
				close(lw.OutCh)
				return
			}
		}
	}
	lw := listerwatcher.NewWatcherClient(wstream, bridgefn)
	lw.Run()
	return lw, nil
}

func (a *grpcObjFwlogPolicyV1FwlogPolicy) Allowed(oper apiserver.APIOperType) bool {
	return true
}

type restObjFwlogPolicyV1FwlogPolicy struct {
	endpoints telemetry.EndpointsFwlogPolicyV1RestClient
	instance  string
}

func (a *restObjFwlogPolicyV1FwlogPolicy) Create(ctx context.Context, in *telemetry.FwlogPolicy) (*telemetry.FwlogPolicy, error) {
	if in == nil {
		return nil, errors.New("invalid input")
	}
	return a.endpoints.AutoAddFwlogPolicy(ctx, in)
}

func (a *restObjFwlogPolicyV1FwlogPolicy) Update(ctx context.Context, in *telemetry.FwlogPolicy) (*telemetry.FwlogPolicy, error) {
	if in == nil {
		return nil, errors.New("invalid input")
	}
	return a.endpoints.AutoUpdateFwlogPolicy(ctx, in)
}

func (a *restObjFwlogPolicyV1FwlogPolicy) Get(ctx context.Context, objMeta *api.ObjectMeta) (*telemetry.FwlogPolicy, error) {
	if objMeta == nil {
		return nil, errors.New("invalid input")
	}
	in := telemetry.FwlogPolicy{}
	in.ObjectMeta = *objMeta
	return a.endpoints.AutoGetFwlogPolicy(ctx, &in)
}

func (a *restObjFwlogPolicyV1FwlogPolicy) Delete(ctx context.Context, objMeta *api.ObjectMeta) (*telemetry.FwlogPolicy, error) {
	if objMeta == nil {
		return nil, errors.New("invalid input")
	}
	in := telemetry.FwlogPolicy{}
	in.ObjectMeta = *objMeta
	return a.endpoints.AutoDeleteFwlogPolicy(ctx, &in)
}

func (a *restObjFwlogPolicyV1FwlogPolicy) List(ctx context.Context, options *api.ListWatchOptions) ([]*telemetry.FwlogPolicy, error) {
	if options == nil {
		return nil, errors.New("invalid input")
	}
	r, err := a.endpoints.AutoListFwlogPolicy(ctx, options)
	if err == nil {
		return r.Items, nil
	}
	return nil, err
}

func (a *restObjFwlogPolicyV1FwlogPolicy) Watch(ctx context.Context, options *api.ListWatchOptions) (kvstore.Watcher, error) {
	return nil, errors.New("not allowed")
}

func (a *restObjFwlogPolicyV1FwlogPolicy) Allowed(oper apiserver.APIOperType) bool {
	switch oper {
	case apiserver.CreateOper:
		return false
	case apiserver.UpdateOper:
		return true
	case apiserver.GetOper:
		return true
	case apiserver.DeleteOper:
		return false
	case apiserver.ListOper:
		return true
	case apiserver.WatchOper:
		return false
	default:
		return false
	}
}

type grpcObjStatsPolicyV1StatsPolicy struct {
	logger log.Logger
	client telemetry.ServiceStatsPolicyV1Client
}

func (a *grpcObjStatsPolicyV1StatsPolicy) Create(ctx context.Context, in *telemetry.StatsPolicy) (*telemetry.StatsPolicy, error) {
	a.logger.DebugLog("msg", "received call", "object", "StatsPolicy", "oper", "create")
	if in == nil {
		return nil, errors.New("invalid input")
	}
	nctx := addVersion(ctx, "v1")
	return a.client.AutoAddStatsPolicy(nctx, in)
}

func (a *grpcObjStatsPolicyV1StatsPolicy) Update(ctx context.Context, in *telemetry.StatsPolicy) (*telemetry.StatsPolicy, error) {
	a.logger.DebugLog("msg", "received call", "object", "StatsPolicy", "oper", "update")
	if in == nil {
		return nil, errors.New("invalid input")
	}
	nctx := addVersion(ctx, "v1")
	return a.client.AutoUpdateStatsPolicy(nctx, in)
}

func (a *grpcObjStatsPolicyV1StatsPolicy) Get(ctx context.Context, objMeta *api.ObjectMeta) (*telemetry.StatsPolicy, error) {
	a.logger.DebugLog("msg", "received call", "object", "StatsPolicy", "oper", "get")
	if objMeta == nil {
		return nil, errors.New("invalid input")
	}
	in := telemetry.StatsPolicy{}
	in.ObjectMeta = *objMeta
	nctx := addVersion(ctx, "v1")
	return a.client.AutoGetStatsPolicy(nctx, &in)
}

func (a *grpcObjStatsPolicyV1StatsPolicy) Delete(ctx context.Context, objMeta *api.ObjectMeta) (*telemetry.StatsPolicy, error) {
	a.logger.DebugLog("msg", "received call", "object", "StatsPolicy", "oper", "delete")
	if objMeta == nil {
		return nil, errors.New("invalid input")
	}
	in := telemetry.StatsPolicy{}
	in.ObjectMeta = *objMeta
	nctx := addVersion(ctx, "v1")
	return a.client.AutoDeleteStatsPolicy(nctx, &in)
}

func (a *grpcObjStatsPolicyV1StatsPolicy) List(ctx context.Context, options *api.ListWatchOptions) ([]*telemetry.StatsPolicy, error) {
	a.logger.DebugLog("msg", "received call", "object", "StatsPolicy", "oper", "list")
	if options == nil {
		return nil, errors.New("invalid input")
	}
	nctx := addVersion(ctx, "v1")
	r, err := a.client.AutoListStatsPolicy(nctx, options)
	if err == nil {
		return r.Items, nil
	}
	return nil, err
}

func (a *grpcObjStatsPolicyV1StatsPolicy) Watch(ctx context.Context, options *api.ListWatchOptions) (kvstore.Watcher, error) {
	a.logger.DebugLog("msg", "received call", "object", "StatsPolicy", "oper", "WatchOper")
	nctx := addVersion(ctx, "v1")
	if options == nil {
		return nil, errors.New("invalid input")
	}
	stream, err := a.client.AutoWatchStatsPolicy(nctx, options)
	if err != nil {
		return nil, err
	}
	wstream := stream.(telemetry.StatsPolicyV1_AutoWatchStatsPolicyClient)
	bridgefn := func(lw *listerwatcher.WatcherClient) {
		for {
			r, err := wstream.Recv()
			if err != nil {
				a.logger.ErrorLog("msg", "error on receive", "error", err)
				close(lw.OutCh)
				return
			}
			ev := kvstore.WatchEvent{
				Type:   kvstore.WatchEventType(r.Type),
				Object: r.Object,
			}
			select {
			case lw.OutCh <- &ev:
			case <-wstream.Context().Done():
				close(lw.OutCh)
				return
			}
		}
	}
	lw := listerwatcher.NewWatcherClient(wstream, bridgefn)
	lw.Run()
	return lw, nil
}

func (a *grpcObjStatsPolicyV1StatsPolicy) Allowed(oper apiserver.APIOperType) bool {
	return true
}

type restObjStatsPolicyV1StatsPolicy struct {
	endpoints telemetry.EndpointsStatsPolicyV1RestClient
	instance  string
}

func (a *restObjStatsPolicyV1StatsPolicy) Create(ctx context.Context, in *telemetry.StatsPolicy) (*telemetry.StatsPolicy, error) {
	if in == nil {
		return nil, errors.New("invalid input")
	}
	return a.endpoints.AutoAddStatsPolicy(ctx, in)
}

func (a *restObjStatsPolicyV1StatsPolicy) Update(ctx context.Context, in *telemetry.StatsPolicy) (*telemetry.StatsPolicy, error) {
	if in == nil {
		return nil, errors.New("invalid input")
	}
	return a.endpoints.AutoUpdateStatsPolicy(ctx, in)
}

func (a *restObjStatsPolicyV1StatsPolicy) Get(ctx context.Context, objMeta *api.ObjectMeta) (*telemetry.StatsPolicy, error) {
	if objMeta == nil {
		return nil, errors.New("invalid input")
	}
	in := telemetry.StatsPolicy{}
	in.ObjectMeta = *objMeta
	return a.endpoints.AutoGetStatsPolicy(ctx, &in)
}

func (a *restObjStatsPolicyV1StatsPolicy) Delete(ctx context.Context, objMeta *api.ObjectMeta) (*telemetry.StatsPolicy, error) {
	if objMeta == nil {
		return nil, errors.New("invalid input")
	}
	in := telemetry.StatsPolicy{}
	in.ObjectMeta = *objMeta
	return a.endpoints.AutoDeleteStatsPolicy(ctx, &in)
}

func (a *restObjStatsPolicyV1StatsPolicy) List(ctx context.Context, options *api.ListWatchOptions) ([]*telemetry.StatsPolicy, error) {
	if options == nil {
		return nil, errors.New("invalid input")
	}
	r, err := a.endpoints.AutoListStatsPolicy(ctx, options)
	if err == nil {
		return r.Items, nil
	}
	return nil, err
}

func (a *restObjStatsPolicyV1StatsPolicy) Watch(ctx context.Context, options *api.ListWatchOptions) (kvstore.Watcher, error) {
	return nil, errors.New("not allowed")
}

func (a *restObjStatsPolicyV1StatsPolicy) Allowed(oper apiserver.APIOperType) bool {
	switch oper {
	case apiserver.CreateOper:
		return false
	case apiserver.UpdateOper:
		return true
	case apiserver.GetOper:
		return true
	case apiserver.DeleteOper:
		return false
	case apiserver.ListOper:
		return true
	case apiserver.WatchOper:
		return false
	default:
		return false
	}
}

type crudClientFlowExportPolicyV1 struct {
	grpcFlowExportPolicy telemetry.FlowExportPolicyV1FlowExportPolicyInterface
}

// NewGrpcCrudClientFlowExportPolicyV1 creates a GRPC client for the service
func NewGrpcCrudClientFlowExportPolicyV1(conn *grpc.ClientConn, logger log.Logger) telemetry.FlowExportPolicyV1Interface {
	client := NewFlowExportPolicyV1Backend(conn, logger)
	return &crudClientFlowExportPolicyV1{

		grpcFlowExportPolicy: &grpcObjFlowExportPolicyV1FlowExportPolicy{client: client, logger: logger},
	}
}

func (a *crudClientFlowExportPolicyV1) FlowExportPolicy() telemetry.FlowExportPolicyV1FlowExportPolicyInterface {
	return a.grpcFlowExportPolicy
}

type crudRestClientFlowExportPolicyV1 struct {
	restFlowExportPolicy telemetry.FlowExportPolicyV1FlowExportPolicyInterface
}

// NewRestCrudClientFlowExportPolicyV1 creates a REST client for the service.
func NewRestCrudClientFlowExportPolicyV1(url string) telemetry.FlowExportPolicyV1Interface {
	endpoints, err := telemetry.MakeFlowExportPolicyV1RestClientEndpoints(url)
	if err != nil {
		oldlog.Fatal("failed to create client")
	}
	return &crudRestClientFlowExportPolicyV1{

		restFlowExportPolicy: &restObjFlowExportPolicyV1FlowExportPolicy{endpoints: endpoints, instance: url},
	}
}

func (a *crudRestClientFlowExportPolicyV1) FlowExportPolicy() telemetry.FlowExportPolicyV1FlowExportPolicyInterface {
	return a.restFlowExportPolicy
}

type crudClientFwlogPolicyV1 struct {
	grpcFwlogPolicy telemetry.FwlogPolicyV1FwlogPolicyInterface
}

// NewGrpcCrudClientFwlogPolicyV1 creates a GRPC client for the service
func NewGrpcCrudClientFwlogPolicyV1(conn *grpc.ClientConn, logger log.Logger) telemetry.FwlogPolicyV1Interface {
	client := NewFwlogPolicyV1Backend(conn, logger)
	return &crudClientFwlogPolicyV1{

		grpcFwlogPolicy: &grpcObjFwlogPolicyV1FwlogPolicy{client: client, logger: logger},
	}
}

func (a *crudClientFwlogPolicyV1) FwlogPolicy() telemetry.FwlogPolicyV1FwlogPolicyInterface {
	return a.grpcFwlogPolicy
}

type crudRestClientFwlogPolicyV1 struct {
	restFwlogPolicy telemetry.FwlogPolicyV1FwlogPolicyInterface
}

// NewRestCrudClientFwlogPolicyV1 creates a REST client for the service.
func NewRestCrudClientFwlogPolicyV1(url string) telemetry.FwlogPolicyV1Interface {
	endpoints, err := telemetry.MakeFwlogPolicyV1RestClientEndpoints(url)
	if err != nil {
		oldlog.Fatal("failed to create client")
	}
	return &crudRestClientFwlogPolicyV1{

		restFwlogPolicy: &restObjFwlogPolicyV1FwlogPolicy{endpoints: endpoints, instance: url},
	}
}

func (a *crudRestClientFwlogPolicyV1) FwlogPolicy() telemetry.FwlogPolicyV1FwlogPolicyInterface {
	return a.restFwlogPolicy
}

type crudClientStatsPolicyV1 struct {
	grpcStatsPolicy telemetry.StatsPolicyV1StatsPolicyInterface
}

// NewGrpcCrudClientStatsPolicyV1 creates a GRPC client for the service
func NewGrpcCrudClientStatsPolicyV1(conn *grpc.ClientConn, logger log.Logger) telemetry.StatsPolicyV1Interface {
	client := NewStatsPolicyV1Backend(conn, logger)
	return &crudClientStatsPolicyV1{

		grpcStatsPolicy: &grpcObjStatsPolicyV1StatsPolicy{client: client, logger: logger},
	}
}

func (a *crudClientStatsPolicyV1) StatsPolicy() telemetry.StatsPolicyV1StatsPolicyInterface {
	return a.grpcStatsPolicy
}

type crudRestClientStatsPolicyV1 struct {
	restStatsPolicy telemetry.StatsPolicyV1StatsPolicyInterface
}

// NewRestCrudClientStatsPolicyV1 creates a REST client for the service.
func NewRestCrudClientStatsPolicyV1(url string) telemetry.StatsPolicyV1Interface {
	endpoints, err := telemetry.MakeStatsPolicyV1RestClientEndpoints(url)
	if err != nil {
		oldlog.Fatal("failed to create client")
	}
	return &crudRestClientStatsPolicyV1{

		restStatsPolicy: &restObjStatsPolicyV1StatsPolicy{endpoints: endpoints, instance: url},
	}
}

func (a *crudRestClientStatsPolicyV1) StatsPolicy() telemetry.StatsPolicyV1StatsPolicyInterface {
	return a.restStatsPolicy
}
