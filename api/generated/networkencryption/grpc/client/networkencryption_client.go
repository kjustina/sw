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
	networkencryption "github.com/pensando/sw/api/generated/networkencryption"
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

// NewTrafficEncryptionPolicyV1 sets up a new client for TrafficEncryptionPolicyV1
func NewTrafficEncryptionPolicyV1(conn *grpc.ClientConn, logger log.Logger) networkencryption.ServiceTrafficEncryptionPolicyV1Client {

	var lAutoAddTrafficEncryptionPolicyEndpoint endpoint.Endpoint
	{
		lAutoAddTrafficEncryptionPolicyEndpoint = grpctransport.NewClient(
			conn,
			"networkencryption.TrafficEncryptionPolicyV1",
			"AutoAddTrafficEncryptionPolicy",
			networkencryption.EncodeGrpcReqTrafficEncryptionPolicy,
			networkencryption.DecodeGrpcRespTrafficEncryptionPolicy,
			&networkencryption.TrafficEncryptionPolicy{},
			grpctransport.ClientBefore(trace.ToGRPCRequest(logger)),
			grpctransport.ClientBefore(dummyBefore),
		).Endpoint()
		lAutoAddTrafficEncryptionPolicyEndpoint = trace.ClientEndPoint("TrafficEncryptionPolicyV1:AutoAddTrafficEncryptionPolicy")(lAutoAddTrafficEncryptionPolicyEndpoint)
	}
	var lAutoDeleteTrafficEncryptionPolicyEndpoint endpoint.Endpoint
	{
		lAutoDeleteTrafficEncryptionPolicyEndpoint = grpctransport.NewClient(
			conn,
			"networkencryption.TrafficEncryptionPolicyV1",
			"AutoDeleteTrafficEncryptionPolicy",
			networkencryption.EncodeGrpcReqTrafficEncryptionPolicy,
			networkencryption.DecodeGrpcRespTrafficEncryptionPolicy,
			&networkencryption.TrafficEncryptionPolicy{},
			grpctransport.ClientBefore(trace.ToGRPCRequest(logger)),
			grpctransport.ClientBefore(dummyBefore),
		).Endpoint()
		lAutoDeleteTrafficEncryptionPolicyEndpoint = trace.ClientEndPoint("TrafficEncryptionPolicyV1:AutoDeleteTrafficEncryptionPolicy")(lAutoDeleteTrafficEncryptionPolicyEndpoint)
	}
	var lAutoGetTrafficEncryptionPolicyEndpoint endpoint.Endpoint
	{
		lAutoGetTrafficEncryptionPolicyEndpoint = grpctransport.NewClient(
			conn,
			"networkencryption.TrafficEncryptionPolicyV1",
			"AutoGetTrafficEncryptionPolicy",
			networkencryption.EncodeGrpcReqTrafficEncryptionPolicy,
			networkencryption.DecodeGrpcRespTrafficEncryptionPolicy,
			&networkencryption.TrafficEncryptionPolicy{},
			grpctransport.ClientBefore(trace.ToGRPCRequest(logger)),
			grpctransport.ClientBefore(dummyBefore),
		).Endpoint()
		lAutoGetTrafficEncryptionPolicyEndpoint = trace.ClientEndPoint("TrafficEncryptionPolicyV1:AutoGetTrafficEncryptionPolicy")(lAutoGetTrafficEncryptionPolicyEndpoint)
	}
	var lAutoListTrafficEncryptionPolicyEndpoint endpoint.Endpoint
	{
		lAutoListTrafficEncryptionPolicyEndpoint = grpctransport.NewClient(
			conn,
			"networkencryption.TrafficEncryptionPolicyV1",
			"AutoListTrafficEncryptionPolicy",
			networkencryption.EncodeGrpcReqListWatchOptions,
			networkencryption.DecodeGrpcRespTrafficEncryptionPolicyList,
			&networkencryption.TrafficEncryptionPolicyList{},
			grpctransport.ClientBefore(trace.ToGRPCRequest(logger)),
			grpctransport.ClientBefore(dummyBefore),
		).Endpoint()
		lAutoListTrafficEncryptionPolicyEndpoint = trace.ClientEndPoint("TrafficEncryptionPolicyV1:AutoListTrafficEncryptionPolicy")(lAutoListTrafficEncryptionPolicyEndpoint)
	}
	var lAutoUpdateTrafficEncryptionPolicyEndpoint endpoint.Endpoint
	{
		lAutoUpdateTrafficEncryptionPolicyEndpoint = grpctransport.NewClient(
			conn,
			"networkencryption.TrafficEncryptionPolicyV1",
			"AutoUpdateTrafficEncryptionPolicy",
			networkencryption.EncodeGrpcReqTrafficEncryptionPolicy,
			networkencryption.DecodeGrpcRespTrafficEncryptionPolicy,
			&networkencryption.TrafficEncryptionPolicy{},
			grpctransport.ClientBefore(trace.ToGRPCRequest(logger)),
			grpctransport.ClientBefore(dummyBefore),
		).Endpoint()
		lAutoUpdateTrafficEncryptionPolicyEndpoint = trace.ClientEndPoint("TrafficEncryptionPolicyV1:AutoUpdateTrafficEncryptionPolicy")(lAutoUpdateTrafficEncryptionPolicyEndpoint)
	}
	return networkencryption.EndpointsTrafficEncryptionPolicyV1Client{
		Client: networkencryption.NewTrafficEncryptionPolicyV1Client(conn),

		AutoAddTrafficEncryptionPolicyEndpoint:    lAutoAddTrafficEncryptionPolicyEndpoint,
		AutoDeleteTrafficEncryptionPolicyEndpoint: lAutoDeleteTrafficEncryptionPolicyEndpoint,
		AutoGetTrafficEncryptionPolicyEndpoint:    lAutoGetTrafficEncryptionPolicyEndpoint,
		AutoListTrafficEncryptionPolicyEndpoint:   lAutoListTrafficEncryptionPolicyEndpoint,
		AutoUpdateTrafficEncryptionPolicyEndpoint: lAutoUpdateTrafficEncryptionPolicyEndpoint,
	}
}

// NewTrafficEncryptionPolicyV1Backend creates an instrumented client with middleware
func NewTrafficEncryptionPolicyV1Backend(conn *grpc.ClientConn, logger log.Logger) networkencryption.ServiceTrafficEncryptionPolicyV1Client {
	cl := NewTrafficEncryptionPolicyV1(conn, logger)
	cl = networkencryption.LoggingTrafficEncryptionPolicyV1MiddlewareClient(logger)(cl)
	return cl
}

type grpcObjTrafficEncryptionPolicyV1TrafficEncryptionPolicy struct {
	logger log.Logger
	client networkencryption.ServiceTrafficEncryptionPolicyV1Client
}

func (a *grpcObjTrafficEncryptionPolicyV1TrafficEncryptionPolicy) Create(ctx context.Context, in *networkencryption.TrafficEncryptionPolicy) (*networkencryption.TrafficEncryptionPolicy, error) {
	a.logger.DebugLog("msg", "received call", "object", "TrafficEncryptionPolicy", "oper", "create")
	if in == nil {
		return nil, errors.New("invalid input")
	}
	nctx := addVersion(ctx, "v1")
	return a.client.AutoAddTrafficEncryptionPolicy(nctx, in)
}

func (a *grpcObjTrafficEncryptionPolicyV1TrafficEncryptionPolicy) Update(ctx context.Context, in *networkencryption.TrafficEncryptionPolicy) (*networkencryption.TrafficEncryptionPolicy, error) {
	a.logger.DebugLog("msg", "received call", "object", "TrafficEncryptionPolicy", "oper", "update")
	if in == nil {
		return nil, errors.New("invalid input")
	}
	nctx := addVersion(ctx, "v1")
	return a.client.AutoUpdateTrafficEncryptionPolicy(nctx, in)
}

func (a *grpcObjTrafficEncryptionPolicyV1TrafficEncryptionPolicy) Get(ctx context.Context, objMeta *api.ObjectMeta) (*networkencryption.TrafficEncryptionPolicy, error) {
	a.logger.DebugLog("msg", "received call", "object", "TrafficEncryptionPolicy", "oper", "get")
	if objMeta == nil {
		return nil, errors.New("invalid input")
	}
	in := networkencryption.TrafficEncryptionPolicy{}
	in.ObjectMeta = *objMeta
	nctx := addVersion(ctx, "v1")
	return a.client.AutoGetTrafficEncryptionPolicy(nctx, &in)
}

func (a *grpcObjTrafficEncryptionPolicyV1TrafficEncryptionPolicy) Delete(ctx context.Context, objMeta *api.ObjectMeta) (*networkencryption.TrafficEncryptionPolicy, error) {
	a.logger.DebugLog("msg", "received call", "object", "TrafficEncryptionPolicy", "oper", "delete")
	if objMeta == nil {
		return nil, errors.New("invalid input")
	}
	in := networkencryption.TrafficEncryptionPolicy{}
	in.ObjectMeta = *objMeta
	nctx := addVersion(ctx, "v1")
	return a.client.AutoDeleteTrafficEncryptionPolicy(nctx, &in)
}

func (a *grpcObjTrafficEncryptionPolicyV1TrafficEncryptionPolicy) List(ctx context.Context, options *api.ListWatchOptions) ([]*networkencryption.TrafficEncryptionPolicy, error) {
	a.logger.DebugLog("msg", "received call", "object", "TrafficEncryptionPolicy", "oper", "list")
	if options == nil {
		return nil, errors.New("invalid input")
	}
	nctx := addVersion(ctx, "v1")
	r, err := a.client.AutoListTrafficEncryptionPolicy(nctx, options)
	if err == nil {
		return r.Items, nil
	}
	return nil, err
}

func (a *grpcObjTrafficEncryptionPolicyV1TrafficEncryptionPolicy) Watch(ctx context.Context, options *api.ListWatchOptions) (kvstore.Watcher, error) {
	a.logger.DebugLog("msg", "received call", "object", "TrafficEncryptionPolicy", "oper", "WatchOper")
	nctx := addVersion(ctx, "v1")
	if options == nil {
		return nil, errors.New("invalid input")
	}
	stream, err := a.client.AutoWatchTrafficEncryptionPolicy(nctx, options)
	if err != nil {
		return nil, err
	}
	wstream := stream.(networkencryption.TrafficEncryptionPolicyV1_AutoWatchTrafficEncryptionPolicyClient)
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

func (a *grpcObjTrafficEncryptionPolicyV1TrafficEncryptionPolicy) Allowed(oper apiserver.APIOperType) bool {
	return true
}

type restObjTrafficEncryptionPolicyV1TrafficEncryptionPolicy struct {
	endpoints networkencryption.EndpointsTrafficEncryptionPolicyV1RestClient
	instance  string
}

func (a *restObjTrafficEncryptionPolicyV1TrafficEncryptionPolicy) Create(ctx context.Context, in *networkencryption.TrafficEncryptionPolicy) (*networkencryption.TrafficEncryptionPolicy, error) {
	if in == nil {
		return nil, errors.New("invalid input")
	}
	return a.endpoints.AutoAddTrafficEncryptionPolicy(ctx, in)
}

func (a *restObjTrafficEncryptionPolicyV1TrafficEncryptionPolicy) Update(ctx context.Context, in *networkencryption.TrafficEncryptionPolicy) (*networkencryption.TrafficEncryptionPolicy, error) {
	if in == nil {
		return nil, errors.New("invalid input")
	}
	return a.endpoints.AutoUpdateTrafficEncryptionPolicy(ctx, in)
}

func (a *restObjTrafficEncryptionPolicyV1TrafficEncryptionPolicy) Get(ctx context.Context, objMeta *api.ObjectMeta) (*networkencryption.TrafficEncryptionPolicy, error) {
	if objMeta == nil {
		return nil, errors.New("invalid input")
	}
	in := networkencryption.TrafficEncryptionPolicy{}
	in.ObjectMeta = *objMeta
	return a.endpoints.AutoGetTrafficEncryptionPolicy(ctx, &in)
}

func (a *restObjTrafficEncryptionPolicyV1TrafficEncryptionPolicy) Delete(ctx context.Context, objMeta *api.ObjectMeta) (*networkencryption.TrafficEncryptionPolicy, error) {
	if objMeta == nil {
		return nil, errors.New("invalid input")
	}
	in := networkencryption.TrafficEncryptionPolicy{}
	in.ObjectMeta = *objMeta
	return a.endpoints.AutoDeleteTrafficEncryptionPolicy(ctx, &in)
}

func (a *restObjTrafficEncryptionPolicyV1TrafficEncryptionPolicy) List(ctx context.Context, options *api.ListWatchOptions) ([]*networkencryption.TrafficEncryptionPolicy, error) {
	if options == nil {
		return nil, errors.New("invalid input")
	}
	r, err := a.endpoints.AutoListTrafficEncryptionPolicy(ctx, options)
	if err == nil {
		return r.Items, nil
	}
	return nil, err
}

func (a *restObjTrafficEncryptionPolicyV1TrafficEncryptionPolicy) Watch(ctx context.Context, options *api.ListWatchOptions) (kvstore.Watcher, error) {
	return nil, errors.New("not allowed")
}

func (a *restObjTrafficEncryptionPolicyV1TrafficEncryptionPolicy) Allowed(oper apiserver.APIOperType) bool {
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
		return false
	case apiserver.WatchOper:
		return false
	default:
		return false
	}
}

type crudClientTrafficEncryptionPolicyV1 struct {
	grpcTrafficEncryptionPolicy networkencryption.TrafficEncryptionPolicyInterface
}

// NewGrpcCrudClientTrafficEncryptionPolicyV1 creates a GRPC client for the service
func NewGrpcCrudClientTrafficEncryptionPolicyV1(conn *grpc.ClientConn, logger log.Logger) networkencryption.TrafficEncryptionPolicyV1Interface {
	client := NewTrafficEncryptionPolicyV1Backend(conn, logger)
	return &crudClientTrafficEncryptionPolicyV1{

		grpcTrafficEncryptionPolicy: &grpcObjTrafficEncryptionPolicyV1TrafficEncryptionPolicy{client: client, logger: logger},
	}
}

func (a *crudClientTrafficEncryptionPolicyV1) TrafficEncryptionPolicy() networkencryption.TrafficEncryptionPolicyInterface {
	return a.grpcTrafficEncryptionPolicy
}

type crudRestClientTrafficEncryptionPolicyV1 struct {
	restTrafficEncryptionPolicy networkencryption.TrafficEncryptionPolicyInterface
}

// NewRestCrudClientTrafficEncryptionPolicyV1 creates a REST client for the service.
func NewRestCrudClientTrafficEncryptionPolicyV1(url string) networkencryption.TrafficEncryptionPolicyV1Interface {
	endpoints, err := networkencryption.MakeTrafficEncryptionPolicyV1RestClientEndpoints(url)
	if err != nil {
		oldlog.Fatal("failed to create client")
	}
	return &crudRestClientTrafficEncryptionPolicyV1{

		restTrafficEncryptionPolicy: &restObjTrafficEncryptionPolicyV1TrafficEncryptionPolicy{endpoints: endpoints, instance: url},
	}
}

func (a *crudRestClientTrafficEncryptionPolicyV1) TrafficEncryptionPolicy() networkencryption.TrafficEncryptionPolicyInterface {
	return a.restTrafficEncryptionPolicy
}
