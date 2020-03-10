// Code generated by protoc-gen-grpc-pensando DO NOT EDIT.

/*
Package search is a auto generated package.
Input file: svc_search.proto
*/
package search

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

// MiddlewareSearchV1Client add middleware to the client
type MiddlewareSearchV1Client func(ServiceSearchV1Client) ServiceSearchV1Client

// EndpointsSearchV1Client is the endpoints for the client
type EndpointsSearchV1Client struct {
	Client                       SearchV1Client
	AutoWatchSvcSearchV1Endpoint endpoint.Endpoint

	PolicyQueryEndpoint endpoint.Endpoint
	QueryEndpoint       endpoint.Endpoint
}

// EndpointsSearchV1RestClient is the REST client
type EndpointsSearchV1RestClient struct {
	logger   log.Logger
	client   *http.Client
	instance string
	bufferId string

	AutoWatchSvcSearchV1Endpoint endpoint.Endpoint
	PolicyQueryEndpoint          endpoint.Endpoint
	QueryEndpoint                endpoint.Endpoint
}

// MiddlewareSearchV1Server adds middle ware to the server
type MiddlewareSearchV1Server func(ServiceSearchV1Server) ServiceSearchV1Server

// EndpointsSearchV1Server is the server endpoints
type EndpointsSearchV1Server struct {
	svcWatchHandlerSearchV1 func(options *api.ListWatchOptions, stream grpc.ServerStream) error

	PolicyQueryEndpoint endpoint.Endpoint
	QueryEndpoint       endpoint.Endpoint
}

// PolicyQuery is endpoint for PolicyQuery
func (e EndpointsSearchV1Client) PolicyQuery(ctx context.Context, in *PolicySearchRequest) (*PolicySearchResponse, error) {
	resp, err := e.PolicyQueryEndpoint(ctx, in)
	if err != nil {
		return &PolicySearchResponse{}, err
	}
	return resp.(*PolicySearchResponse), nil
}

type respSearchV1PolicyQuery struct {
	V   PolicySearchResponse
	Err error
}

// Query is endpoint for Query
func (e EndpointsSearchV1Client) Query(ctx context.Context, in *SearchRequest) (*SearchResponse, error) {
	resp, err := e.QueryEndpoint(ctx, in)
	if err != nil {
		return &SearchResponse{}, err
	}
	return resp.(*SearchResponse), nil
}

type respSearchV1Query struct {
	V   SearchResponse
	Err error
}

func (e EndpointsSearchV1Client) AutoWatchSvcSearchV1(ctx context.Context, in *api.ListWatchOptions) (SearchV1_AutoWatchSvcSearchV1Client, error) {
	return nil, errors.New("not implemented")
}

// PolicyQuery implementation on server Endpoint
func (e EndpointsSearchV1Server) PolicyQuery(ctx context.Context, in PolicySearchRequest) (PolicySearchResponse, error) {
	resp, err := e.PolicyQueryEndpoint(ctx, in)
	if err != nil {
		return PolicySearchResponse{}, err
	}
	return *resp.(*PolicySearchResponse), nil
}

// MakeSearchV1PolicyQueryEndpoint creates  PolicyQuery endpoints for the service
func MakeSearchV1PolicyQueryEndpoint(s ServiceSearchV1Server, logger log.Logger) endpoint.Endpoint {
	f := func(ctx context.Context, request interface{}) (response interface{}, err error) {
		req := request.(*PolicySearchRequest)
		v, err := s.PolicyQuery(ctx, *req)
		return respSearchV1PolicyQuery{
			V:   v,
			Err: err,
		}, nil
	}
	return trace.ServerEndpoint("SearchV1:PolicyQuery")(f)
}

// Query implementation on server Endpoint
func (e EndpointsSearchV1Server) Query(ctx context.Context, in SearchRequest) (SearchResponse, error) {
	resp, err := e.QueryEndpoint(ctx, in)
	if err != nil {
		return SearchResponse{}, err
	}
	return *resp.(*SearchResponse), nil
}

// MakeSearchV1QueryEndpoint creates  Query endpoints for the service
func MakeSearchV1QueryEndpoint(s ServiceSearchV1Server, logger log.Logger) endpoint.Endpoint {
	f := func(ctx context.Context, request interface{}) (response interface{}, err error) {
		req := request.(*SearchRequest)
		v, err := s.Query(ctx, *req)
		return respSearchV1Query{
			V:   v,
			Err: err,
		}, nil
	}
	return trace.ServerEndpoint("SearchV1:Query")(f)
}

// MakeAutoWatchSvcSearchV1Endpoint creates the Watch endpoint for the service
func MakeAutoWatchSvcSearchV1Endpoint(s ServiceSearchV1Server, logger log.Logger) func(options *api.ListWatchOptions, stream grpc.ServerStream) error {
	return func(options *api.ListWatchOptions, stream grpc.ServerStream) error {
		return errors.New("not implemented")
	}
}

// MakeSearchV1ServerEndpoints creates server endpoints
func MakeSearchV1ServerEndpoints(s ServiceSearchV1Server, logger log.Logger) EndpointsSearchV1Server {
	return EndpointsSearchV1Server{
		svcWatchHandlerSearchV1: MakeAutoWatchSvcSearchV1Endpoint(s, logger),

		PolicyQueryEndpoint: MakeSearchV1PolicyQueryEndpoint(s, logger),
		QueryEndpoint:       MakeSearchV1QueryEndpoint(s, logger),
	}
}

// LoggingSearchV1MiddlewareClient adds middleware for the client
func LoggingSearchV1MiddlewareClient(logger log.Logger) MiddlewareSearchV1Client {
	return func(next ServiceSearchV1Client) ServiceSearchV1Client {
		return loggingSearchV1MiddlewareClient{
			logger: logger,
			next:   next,
		}
	}
}

type loggingSearchV1MiddlewareClient struct {
	logger log.Logger
	next   ServiceSearchV1Client
}

// LoggingSearchV1MiddlewareServer adds middleware for the client
func LoggingSearchV1MiddlewareServer(logger log.Logger) MiddlewareSearchV1Server {
	return func(next ServiceSearchV1Server) ServiceSearchV1Server {
		return loggingSearchV1MiddlewareServer{
			logger: logger,
			next:   next,
		}
	}
}

type loggingSearchV1MiddlewareServer struct {
	logger log.Logger
	next   ServiceSearchV1Server
}

func (m loggingSearchV1MiddlewareClient) PolicyQuery(ctx context.Context, in *PolicySearchRequest) (resp *PolicySearchResponse, err error) {
	defer func(begin time.Time) {
		var rslt string
		if err == nil {
			rslt = "Success"
		} else {
			rslt = err.Error()
		}
		m.logger.Audit(ctx, "service", "SearchV1", "method", "PolicyQuery", "result", rslt, "duration", time.Since(begin), "error", err)
	}(time.Now())
	resp, err = m.next.PolicyQuery(ctx, in)
	return
}
func (m loggingSearchV1MiddlewareClient) Query(ctx context.Context, in *SearchRequest) (resp *SearchResponse, err error) {
	defer func(begin time.Time) {
		var rslt string
		if err == nil {
			rslt = "Success"
		} else {
			rslt = err.Error()
		}
		m.logger.Audit(ctx, "service", "SearchV1", "method", "Query", "result", rslt, "duration", time.Since(begin), "error", err)
	}(time.Now())
	resp, err = m.next.Query(ctx, in)
	return
}

func (m loggingSearchV1MiddlewareClient) AutoWatchSvcSearchV1(ctx context.Context, in *api.ListWatchOptions) (SearchV1_AutoWatchSvcSearchV1Client, error) {
	return nil, errors.New("not implemented")
}

func (m loggingSearchV1MiddlewareServer) PolicyQuery(ctx context.Context, in PolicySearchRequest) (resp PolicySearchResponse, err error) {
	defer func(begin time.Time) {
		var rslt string
		if err == nil {
			rslt = "Success"
		} else {
			rslt = err.Error()
		}
		m.logger.Audit(ctx, "service", "SearchV1", "method", "PolicyQuery", "result", rslt, "duration", time.Since(begin))
	}(time.Now())
	resp, err = m.next.PolicyQuery(ctx, in)
	return
}
func (m loggingSearchV1MiddlewareServer) Query(ctx context.Context, in SearchRequest) (resp SearchResponse, err error) {
	defer func(begin time.Time) {
		var rslt string
		if err == nil {
			rslt = "Success"
		} else {
			rslt = err.Error()
		}
		m.logger.Audit(ctx, "service", "SearchV1", "method", "Query", "result", rslt, "duration", time.Since(begin))
	}(time.Now())
	resp, err = m.next.Query(ctx, in)
	return
}

func (m loggingSearchV1MiddlewareServer) AutoWatchSvcSearchV1(in *api.ListWatchOptions, stream SearchV1_AutoWatchSvcSearchV1Server) error {
	return errors.New("Not implemented")
}

func (r *EndpointsSearchV1RestClient) updateHTTPHeader(ctx context.Context, header *http.Header) {
	val, ok := loginctx.AuthzHeaderFromContext(ctx)
	if ok {
		header.Add("Authorization", val)
	}
	val, ok = loginctx.ExtRequestIDHeaderFromContext(ctx)
	if ok {
		header.Add("Pensando-Psm-External-Request-Id", val)
	}
}
func (r *EndpointsSearchV1RestClient) getHTTPRequest(ctx context.Context, in interface{}, method, path string) (*http.Request, error) {
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
func makeURISearchV1AutoWatchSvcSearchV1WatchOper(in *api.ListWatchOptions) string {
	return ""

}

func (r *EndpointsSearchV1RestClient) SearchV1PolicyQueryEndpoint(ctx context.Context, in *PolicySearchRequest) (*PolicySearchResponse, error) {
	return nil, errors.New("not allowed")
}

func (r *EndpointsSearchV1RestClient) SearchV1QueryEndpoint(ctx context.Context, in *SearchRequest) (*SearchResponse, error) {
	return nil, errors.New("not allowed")
}

// MakeSearchV1RestClientEndpoints make REST client endpoints
func MakeSearchV1RestClientEndpoints(instance string, httpClient *http.Client) (EndpointsSearchV1RestClient, error) {
	if !strings.HasPrefix(instance, "https") {
		instance = "https://" + instance
	}

	return EndpointsSearchV1RestClient{
		instance: instance,
		client:   httpClient,
	}, nil

}

// MakeSearchV1StagedRestClientEndpoints makes staged REST client endpoints
func MakeSearchV1StagedRestClientEndpoints(instance string, bufferId string, httpClient *http.Client) (EndpointsSearchV1RestClient, error) {
	if !strings.HasPrefix(instance, "https") {
		instance = "https://" + instance
	}

	return EndpointsSearchV1RestClient{
		instance: instance,
		bufferId: bufferId,
		client:   httpClient,
	}, nil
}
