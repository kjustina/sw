// Code generated by protoc-gen-grpc-pensando DO NOT EDIT.

/*
Package audit is a auto generated package.
Input file: svc_audit.proto
*/
package audit

import (
	"context"
	"errors"
	"fmt"
	"net/http"
	"net/url"
	"strings"
	"time"

	"github.com/go-kit/kit/endpoint"
	"google.golang.org/grpc"

	"github.com/pensando/sw/api"
	"github.com/pensando/sw/api/listerwatcher"
	loginctx "github.com/pensando/sw/api/login/context"
	"github.com/pensando/sw/venice/utils/log"
	"github.com/pensando/sw/venice/utils/trace"
)

// Dummy definitions to suppress nonused warnings
var _ api.ObjectMeta
var _ grpc.ServerStream
var _ fmt.Formatter
var _ *listerwatcher.WatcherClient

// MiddlewareAuditV1Client add middleware to the client
type MiddlewareAuditV1Client func(ServiceAuditV1Client) ServiceAuditV1Client

// EndpointsAuditV1Client is the endpoints for the client
type EndpointsAuditV1Client struct {
	Client                      AuditV1Client
	AutoWatchSvcAuditV1Endpoint endpoint.Endpoint

	GetEventEndpoint endpoint.Endpoint
}

// EndpointsAuditV1RestClient is the REST client
type EndpointsAuditV1RestClient struct {
	logger   log.Logger
	client   *http.Client
	instance string
	bufferId string

	AutoWatchSvcAuditV1Endpoint endpoint.Endpoint
	GetEventEndpoint            endpoint.Endpoint
}

// MiddlewareAuditV1Server adds middle ware to the server
type MiddlewareAuditV1Server func(ServiceAuditV1Server) ServiceAuditV1Server

// EndpointsAuditV1Server is the server endpoints
type EndpointsAuditV1Server struct {
	svcWatchHandlerAuditV1 func(options *api.ListWatchOptions, stream grpc.ServerStream) error

	GetEventEndpoint endpoint.Endpoint
}

// GetEvent is endpoint for GetEvent
func (e EndpointsAuditV1Client) GetEvent(ctx context.Context, in *AuditEventRequest) (*AuditEvent, error) {
	resp, err := e.GetEventEndpoint(ctx, in)
	if err != nil {
		return &AuditEvent{}, err
	}
	return resp.(*AuditEvent), nil
}

type respAuditV1GetEvent struct {
	V   AuditEvent
	Err error
}

func (e EndpointsAuditV1Client) AutoWatchSvcAuditV1(ctx context.Context, in *api.ListWatchOptions) (AuditV1_AutoWatchSvcAuditV1Client, error) {
	return nil, errors.New("not implemented")
}

// GetEvent implementation on server Endpoint
func (e EndpointsAuditV1Server) GetEvent(ctx context.Context, in AuditEventRequest) (AuditEvent, error) {
	resp, err := e.GetEventEndpoint(ctx, in)
	if err != nil {
		return AuditEvent{}, err
	}
	return *resp.(*AuditEvent), nil
}

// MakeAuditV1GetEventEndpoint creates  GetEvent endpoints for the service
func MakeAuditV1GetEventEndpoint(s ServiceAuditV1Server, logger log.Logger) endpoint.Endpoint {
	f := func(ctx context.Context, request interface{}) (response interface{}, err error) {
		req := request.(*AuditEventRequest)
		v, err := s.GetEvent(ctx, *req)
		return respAuditV1GetEvent{
			V:   v,
			Err: err,
		}, nil
	}
	return trace.ServerEndpoint("AuditV1:GetEvent")(f)
}

// MakeAutoWatchSvcAuditV1Endpoint creates the Watch endpoint for the service
func MakeAutoWatchSvcAuditV1Endpoint(s ServiceAuditV1Server, logger log.Logger) func(options *api.ListWatchOptions, stream grpc.ServerStream) error {
	return func(options *api.ListWatchOptions, stream grpc.ServerStream) error {
		return errors.New("not implemented")
	}
}

// MakeAuditV1ServerEndpoints creates server endpoints
func MakeAuditV1ServerEndpoints(s ServiceAuditV1Server, logger log.Logger) EndpointsAuditV1Server {
	return EndpointsAuditV1Server{
		svcWatchHandlerAuditV1: MakeAutoWatchSvcAuditV1Endpoint(s, logger),

		GetEventEndpoint: MakeAuditV1GetEventEndpoint(s, logger),
	}
}

// LoggingAuditV1MiddlewareClient adds middleware for the client
func LoggingAuditV1MiddlewareClient(logger log.Logger) MiddlewareAuditV1Client {
	return func(next ServiceAuditV1Client) ServiceAuditV1Client {
		return loggingAuditV1MiddlewareClient{
			logger: logger,
			next:   next,
		}
	}
}

type loggingAuditV1MiddlewareClient struct {
	logger log.Logger
	next   ServiceAuditV1Client
}

// LoggingAuditV1MiddlewareServer adds middleware for the client
func LoggingAuditV1MiddlewareServer(logger log.Logger) MiddlewareAuditV1Server {
	return func(next ServiceAuditV1Server) ServiceAuditV1Server {
		return loggingAuditV1MiddlewareServer{
			logger: logger,
			next:   next,
		}
	}
}

type loggingAuditV1MiddlewareServer struct {
	logger log.Logger
	next   ServiceAuditV1Server
}

func (m loggingAuditV1MiddlewareClient) GetEvent(ctx context.Context, in *AuditEventRequest) (resp *AuditEvent, err error) {
	defer func(begin time.Time) {
		var rslt string
		if err == nil {
			rslt = "Success"
		} else {
			rslt = err.Error()
		}
		m.logger.Audit(ctx, "service", "AuditV1", "method", "GetEvent", "result", rslt, "duration", time.Since(begin), "error", err)
	}(time.Now())
	resp, err = m.next.GetEvent(ctx, in)
	return
}

func (m loggingAuditV1MiddlewareClient) AutoWatchSvcAuditV1(ctx context.Context, in *api.ListWatchOptions) (AuditV1_AutoWatchSvcAuditV1Client, error) {
	return nil, errors.New("not implemented")
}

func (m loggingAuditV1MiddlewareServer) GetEvent(ctx context.Context, in AuditEventRequest) (resp AuditEvent, err error) {
	defer func(begin time.Time) {
		var rslt string
		if err == nil {
			rslt = "Success"
		} else {
			rslt = err.Error()
		}
		m.logger.Audit(ctx, "service", "AuditV1", "method", "GetEvent", "result", rslt, "duration", time.Since(begin))
	}(time.Now())
	resp, err = m.next.GetEvent(ctx, in)
	return
}

func (m loggingAuditV1MiddlewareServer) AutoWatchSvcAuditV1(in *api.ListWatchOptions, stream AuditV1_AutoWatchSvcAuditV1Server) error {
	return errors.New("Not implemented")
}

func (r *EndpointsAuditV1RestClient) updateHTTPHeader(ctx context.Context, header *http.Header) {
	val, ok := loginctx.AuthzHeaderFromContext(ctx)
	if ok {
		header.Add("Authorization", val)
	}
	val, ok = loginctx.ExtRequestIDHeaderFromContext(ctx)
	if ok {
		header.Add("Pensando-Psm-External-Request-Id", val)
	}
}
func (r *EndpointsAuditV1RestClient) getHTTPRequest(ctx context.Context, in interface{}, method, path string) (*http.Request, error) {
	target, err := url.Parse(r.instance)
	if err != nil {
		return nil, fmt.Errorf("invalid instance %s", r.instance)
	}
	target.Path = path
	req, err := http.NewRequest(method, target.String(), nil)
	if err != nil {
		return nil, fmt.Errorf("could not create request (%s)", err)
	}
	r.updateHTTPHeader(ctx, &req.Header)
	if err = encodeHTTPRequest(ctx, req, in); err != nil {
		return nil, fmt.Errorf("could not encode request (%s)", err)
	}
	return req, nil
}

//
func makeURIAuditV1AutoWatchSvcAuditV1WatchOper(in *api.ListWatchOptions) string {
	return ""

}

func (r *EndpointsAuditV1RestClient) AuditV1GetEventEndpoint(ctx context.Context, in *AuditEventRequest) (*AuditEvent, error) {
	return nil, errors.New("not allowed")
}

// MakeAuditV1RestClientEndpoints make REST client endpoints
func MakeAuditV1RestClientEndpoints(instance string, httpClient *http.Client) (EndpointsAuditV1RestClient, error) {
	if !strings.HasPrefix(instance, "https") {
		instance = "https://" + instance
	}

	return EndpointsAuditV1RestClient{
		instance: instance,
		client:   httpClient,
	}, nil

}

// MakeAuditV1StagedRestClientEndpoints makes staged REST client endpoints
func MakeAuditV1StagedRestClientEndpoints(instance string, bufferId string, httpClient *http.Client) (EndpointsAuditV1RestClient, error) {
	if !strings.HasPrefix(instance, "https") {
		instance = "https://" + instance
	}

	return EndpointsAuditV1RestClient{
		instance: instance,
		bufferId: bufferId,
		client:   httpClient,
	}, nil
}
