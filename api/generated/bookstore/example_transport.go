// Code generated by protoc-gen-grpc-pensando DO NOT EDIT.

/*
Package bookstore is a auto generated package.
Input file: protos/example.proto
*/
package bookstore

import (
	"bytes"
	"context"
	"encoding/json"
	"errors"
	"fmt"
	"io/ioutil"
	"net/http"

	"github.com/go-kit/kit/tracing/opentracing"
	grpctransport "github.com/go-kit/kit/transport/grpc"
	stdopentracing "github.com/opentracing/opentracing-go"
	oldcontext "golang.org/x/net/context"
	"google.golang.org/grpc/metadata"

	"github.com/pensando/sw/api"
	apiserver "github.com/pensando/sw/apiserver"
	"github.com/pensando/sw/utils/log"
)

var (
	errInconsistentIDs = errors.New("inconsistent IDs")
	errAlreadyExists   = errors.New("already exists")
	errNotFound        = errors.New("not found")
)

// Dummy definitions to suppress nonused warnings
var _ api.ObjectMeta

// FIXME: add HTTP handler here.
func recoverVersion(ctx context.Context, md metadata.MD) context.Context {
	var pairs []string
	xmd := md
	v, ok := xmd[apiserver.RequestParamVersion]
	if ok {
		pairs = append(pairs, apiserver.RequestParamVersion, v[0])
	}
	if v, ok = xmd["req-uri"]; ok {
		pairs = append(pairs, "req-uri", v[0])
	}
	if v, ok = xmd[apiserver.RequestParamMethod]; ok {
		pairs = append(pairs, apiserver.RequestParamMethod, v[0])
	}
	nmd := metadata.Pairs(pairs...)
	nmd = metadata.Join(nmd, md)
	ctx = metadata.NewContext(ctx, nmd)
	return ctx
}

type grpcServerBookstoreV1 struct {
	Endpoints EndpointsBookstoreV1Server

	AutoAddBookHdlr         grpctransport.Handler
	AutoAddOrderHdlr        grpctransport.Handler
	AutoAddPublisherHdlr    grpctransport.Handler
	AutoDeleteBookHdlr      grpctransport.Handler
	AutoDeleteOrderHdlr     grpctransport.Handler
	AutoDeletePublisherHdlr grpctransport.Handler
	AutoGetBookHdlr         grpctransport.Handler
	AutoGetOrderHdlr        grpctransport.Handler
	AutoGetPublisherHdlr    grpctransport.Handler
	AutoListBookHdlr        grpctransport.Handler
	AutoListOrderHdlr       grpctransport.Handler
	AutoListPublisherHdlr   grpctransport.Handler
	AutoUpdateBookHdlr      grpctransport.Handler
	AutoUpdateOrderHdlr     grpctransport.Handler
	AutoUpdatePublisherHdlr grpctransport.Handler
}

// MakeGRPCServerBookstoreV1 creates a GRPC server for BookstoreV1 service
func MakeGRPCServerBookstoreV1(ctx context.Context, endpoints EndpointsBookstoreV1Server, logger log.Logger) BookstoreV1Server {
	options := []grpctransport.ServerOption{
		grpctransport.ServerErrorLogger(logger),
		grpctransport.ServerBefore(recoverVersion),
	}
	return &grpcServerBookstoreV1{
		Endpoints: endpoints,
		AutoAddBookHdlr: grpctransport.NewServer(
			endpoints.AutoAddBookEndpoint,
			DecodeGrpcReqBook,
			EncodeGrpcRespBook,
			append(options, grpctransport.ServerBefore(opentracing.FromGRPCRequest(stdopentracing.GlobalTracer(), "AutoAddBook", logger)))...,
		),

		AutoAddOrderHdlr: grpctransport.NewServer(
			endpoints.AutoAddOrderEndpoint,
			DecodeGrpcReqOrder,
			EncodeGrpcRespOrder,
			append(options, grpctransport.ServerBefore(opentracing.FromGRPCRequest(stdopentracing.GlobalTracer(), "AutoAddOrder", logger)))...,
		),

		AutoAddPublisherHdlr: grpctransport.NewServer(
			endpoints.AutoAddPublisherEndpoint,
			DecodeGrpcReqPublisher,
			EncodeGrpcRespPublisher,
			append(options, grpctransport.ServerBefore(opentracing.FromGRPCRequest(stdopentracing.GlobalTracer(), "AutoAddPublisher", logger)))...,
		),

		AutoDeleteBookHdlr: grpctransport.NewServer(
			endpoints.AutoDeleteBookEndpoint,
			DecodeGrpcReqBook,
			EncodeGrpcRespBook,
			append(options, grpctransport.ServerBefore(opentracing.FromGRPCRequest(stdopentracing.GlobalTracer(), "AutoDeleteBook", logger)))...,
		),

		AutoDeleteOrderHdlr: grpctransport.NewServer(
			endpoints.AutoDeleteOrderEndpoint,
			DecodeGrpcReqOrder,
			EncodeGrpcRespOrder,
			append(options, grpctransport.ServerBefore(opentracing.FromGRPCRequest(stdopentracing.GlobalTracer(), "AutoDeleteOrder", logger)))...,
		),

		AutoDeletePublisherHdlr: grpctransport.NewServer(
			endpoints.AutoDeletePublisherEndpoint,
			DecodeGrpcReqPublisher,
			EncodeGrpcRespPublisher,
			append(options, grpctransport.ServerBefore(opentracing.FromGRPCRequest(stdopentracing.GlobalTracer(), "AutoDeletePublisher", logger)))...,
		),

		AutoGetBookHdlr: grpctransport.NewServer(
			endpoints.AutoGetBookEndpoint,
			DecodeGrpcReqBook,
			EncodeGrpcRespBook,
			append(options, grpctransport.ServerBefore(opentracing.FromGRPCRequest(stdopentracing.GlobalTracer(), "AutoGetBook", logger)))...,
		),

		AutoGetOrderHdlr: grpctransport.NewServer(
			endpoints.AutoGetOrderEndpoint,
			DecodeGrpcReqOrder,
			EncodeGrpcRespOrder,
			append(options, grpctransport.ServerBefore(opentracing.FromGRPCRequest(stdopentracing.GlobalTracer(), "AutoGetOrder", logger)))...,
		),

		AutoGetPublisherHdlr: grpctransport.NewServer(
			endpoints.AutoGetPublisherEndpoint,
			DecodeGrpcReqPublisher,
			EncodeGrpcRespPublisher,
			append(options, grpctransport.ServerBefore(opentracing.FromGRPCRequest(stdopentracing.GlobalTracer(), "AutoGetPublisher", logger)))...,
		),

		AutoListBookHdlr: grpctransport.NewServer(
			endpoints.AutoListBookEndpoint,
			DecodeGrpcReqListWatchOptions,
			EncodeGrpcRespAutoMsgBookListHelper,
			append(options, grpctransport.ServerBefore(opentracing.FromGRPCRequest(stdopentracing.GlobalTracer(), "AutoListBook", logger)))...,
		),

		AutoListOrderHdlr: grpctransport.NewServer(
			endpoints.AutoListOrderEndpoint,
			DecodeGrpcReqListWatchOptions,
			EncodeGrpcRespAutoMsgOrderListHelper,
			append(options, grpctransport.ServerBefore(opentracing.FromGRPCRequest(stdopentracing.GlobalTracer(), "AutoListOrder", logger)))...,
		),

		AutoListPublisherHdlr: grpctransport.NewServer(
			endpoints.AutoListPublisherEndpoint,
			DecodeGrpcReqListWatchOptions,
			EncodeGrpcRespAutoMsgPublisherListHelper,
			append(options, grpctransport.ServerBefore(opentracing.FromGRPCRequest(stdopentracing.GlobalTracer(), "AutoListPublisher", logger)))...,
		),

		AutoUpdateBookHdlr: grpctransport.NewServer(
			endpoints.AutoUpdateBookEndpoint,
			DecodeGrpcReqBook,
			EncodeGrpcRespBook,
			append(options, grpctransport.ServerBefore(opentracing.FromGRPCRequest(stdopentracing.GlobalTracer(), "AutoUpdateBook", logger)))...,
		),

		AutoUpdateOrderHdlr: grpctransport.NewServer(
			endpoints.AutoUpdateOrderEndpoint,
			DecodeGrpcReqOrder,
			EncodeGrpcRespOrder,
			append(options, grpctransport.ServerBefore(opentracing.FromGRPCRequest(stdopentracing.GlobalTracer(), "AutoUpdateOrder", logger)))...,
		),

		AutoUpdatePublisherHdlr: grpctransport.NewServer(
			endpoints.AutoUpdatePublisherEndpoint,
			DecodeGrpcReqPublisher,
			EncodeGrpcRespPublisher,
			append(options, grpctransport.ServerBefore(opentracing.FromGRPCRequest(stdopentracing.GlobalTracer(), "AutoUpdatePublisher", logger)))...,
		),
	}
}

func (s *grpcServerBookstoreV1) AutoAddBook(ctx oldcontext.Context, req *Book) (*Book, error) {
	_, resp, err := s.AutoAddBookHdlr.ServeGRPC(ctx, req)
	if err != nil {
		return nil, err
	}
	r := resp.(respBookstoreV1AutoAddBook).V
	return &r, resp.(respBookstoreV1AutoAddBook).Err
}

func decodeHTTPrespBookstoreV1AutoAddBook(_ context.Context, r *http.Response) (interface{}, error) {
	if r.StatusCode != http.StatusOK {
		return nil, errorDecoder(r)
	}
	var resp Book
	err := json.NewDecoder(r.Body).Decode(&resp)
	return &resp, err
}

func (s *grpcServerBookstoreV1) AutoAddOrder(ctx oldcontext.Context, req *Order) (*Order, error) {
	_, resp, err := s.AutoAddOrderHdlr.ServeGRPC(ctx, req)
	if err != nil {
		return nil, err
	}
	r := resp.(respBookstoreV1AutoAddOrder).V
	return &r, resp.(respBookstoreV1AutoAddOrder).Err
}

func decodeHTTPrespBookstoreV1AutoAddOrder(_ context.Context, r *http.Response) (interface{}, error) {
	if r.StatusCode != http.StatusOK {
		return nil, errorDecoder(r)
	}
	var resp Order
	err := json.NewDecoder(r.Body).Decode(&resp)
	return &resp, err
}

func (s *grpcServerBookstoreV1) AutoAddPublisher(ctx oldcontext.Context, req *Publisher) (*Publisher, error) {
	_, resp, err := s.AutoAddPublisherHdlr.ServeGRPC(ctx, req)
	if err != nil {
		return nil, err
	}
	r := resp.(respBookstoreV1AutoAddPublisher).V
	return &r, resp.(respBookstoreV1AutoAddPublisher).Err
}

func decodeHTTPrespBookstoreV1AutoAddPublisher(_ context.Context, r *http.Response) (interface{}, error) {
	if r.StatusCode != http.StatusOK {
		return nil, errorDecoder(r)
	}
	var resp Publisher
	err := json.NewDecoder(r.Body).Decode(&resp)
	return &resp, err
}

func (s *grpcServerBookstoreV1) AutoDeleteBook(ctx oldcontext.Context, req *Book) (*Book, error) {
	_, resp, err := s.AutoDeleteBookHdlr.ServeGRPC(ctx, req)
	if err != nil {
		return nil, err
	}
	r := resp.(respBookstoreV1AutoDeleteBook).V
	return &r, resp.(respBookstoreV1AutoDeleteBook).Err
}

func decodeHTTPrespBookstoreV1AutoDeleteBook(_ context.Context, r *http.Response) (interface{}, error) {
	if r.StatusCode != http.StatusOK {
		return nil, errorDecoder(r)
	}
	var resp Book
	err := json.NewDecoder(r.Body).Decode(&resp)
	return &resp, err
}

func (s *grpcServerBookstoreV1) AutoDeleteOrder(ctx oldcontext.Context, req *Order) (*Order, error) {
	_, resp, err := s.AutoDeleteOrderHdlr.ServeGRPC(ctx, req)
	if err != nil {
		return nil, err
	}
	r := resp.(respBookstoreV1AutoDeleteOrder).V
	return &r, resp.(respBookstoreV1AutoDeleteOrder).Err
}

func decodeHTTPrespBookstoreV1AutoDeleteOrder(_ context.Context, r *http.Response) (interface{}, error) {
	if r.StatusCode != http.StatusOK {
		return nil, errorDecoder(r)
	}
	var resp Order
	err := json.NewDecoder(r.Body).Decode(&resp)
	return &resp, err
}

func (s *grpcServerBookstoreV1) AutoDeletePublisher(ctx oldcontext.Context, req *Publisher) (*Publisher, error) {
	_, resp, err := s.AutoDeletePublisherHdlr.ServeGRPC(ctx, req)
	if err != nil {
		return nil, err
	}
	r := resp.(respBookstoreV1AutoDeletePublisher).V
	return &r, resp.(respBookstoreV1AutoDeletePublisher).Err
}

func decodeHTTPrespBookstoreV1AutoDeletePublisher(_ context.Context, r *http.Response) (interface{}, error) {
	if r.StatusCode != http.StatusOK {
		return nil, errorDecoder(r)
	}
	var resp Publisher
	err := json.NewDecoder(r.Body).Decode(&resp)
	return &resp, err
}

func (s *grpcServerBookstoreV1) AutoGetBook(ctx oldcontext.Context, req *Book) (*Book, error) {
	_, resp, err := s.AutoGetBookHdlr.ServeGRPC(ctx, req)
	if err != nil {
		return nil, err
	}
	r := resp.(respBookstoreV1AutoGetBook).V
	return &r, resp.(respBookstoreV1AutoGetBook).Err
}

func decodeHTTPrespBookstoreV1AutoGetBook(_ context.Context, r *http.Response) (interface{}, error) {
	if r.StatusCode != http.StatusOK {
		return nil, errorDecoder(r)
	}
	var resp Book
	err := json.NewDecoder(r.Body).Decode(&resp)
	return &resp, err
}

func (s *grpcServerBookstoreV1) AutoGetOrder(ctx oldcontext.Context, req *Order) (*Order, error) {
	_, resp, err := s.AutoGetOrderHdlr.ServeGRPC(ctx, req)
	if err != nil {
		return nil, err
	}
	r := resp.(respBookstoreV1AutoGetOrder).V
	return &r, resp.(respBookstoreV1AutoGetOrder).Err
}

func decodeHTTPrespBookstoreV1AutoGetOrder(_ context.Context, r *http.Response) (interface{}, error) {
	if r.StatusCode != http.StatusOK {
		return nil, errorDecoder(r)
	}
	var resp Order
	err := json.NewDecoder(r.Body).Decode(&resp)
	return &resp, err
}

func (s *grpcServerBookstoreV1) AutoGetPublisher(ctx oldcontext.Context, req *Publisher) (*Publisher, error) {
	_, resp, err := s.AutoGetPublisherHdlr.ServeGRPC(ctx, req)
	if err != nil {
		return nil, err
	}
	r := resp.(respBookstoreV1AutoGetPublisher).V
	return &r, resp.(respBookstoreV1AutoGetPublisher).Err
}

func decodeHTTPrespBookstoreV1AutoGetPublisher(_ context.Context, r *http.Response) (interface{}, error) {
	if r.StatusCode != http.StatusOK {
		return nil, errorDecoder(r)
	}
	var resp Publisher
	err := json.NewDecoder(r.Body).Decode(&resp)
	return &resp, err
}

func (s *grpcServerBookstoreV1) AutoListBook(ctx oldcontext.Context, req *api.ListWatchOptions) (*AutoMsgBookListHelper, error) {
	_, resp, err := s.AutoListBookHdlr.ServeGRPC(ctx, req)
	if err != nil {
		return nil, err
	}
	r := resp.(respBookstoreV1AutoListBook).V
	return &r, resp.(respBookstoreV1AutoListBook).Err
}

func decodeHTTPrespBookstoreV1AutoListBook(_ context.Context, r *http.Response) (interface{}, error) {
	if r.StatusCode != http.StatusOK {
		return nil, errorDecoder(r)
	}
	var resp AutoMsgBookListHelper
	err := json.NewDecoder(r.Body).Decode(&resp)
	return &resp, err
}

func (s *grpcServerBookstoreV1) AutoListOrder(ctx oldcontext.Context, req *api.ListWatchOptions) (*AutoMsgOrderListHelper, error) {
	_, resp, err := s.AutoListOrderHdlr.ServeGRPC(ctx, req)
	if err != nil {
		return nil, err
	}
	r := resp.(respBookstoreV1AutoListOrder).V
	return &r, resp.(respBookstoreV1AutoListOrder).Err
}

func decodeHTTPrespBookstoreV1AutoListOrder(_ context.Context, r *http.Response) (interface{}, error) {
	if r.StatusCode != http.StatusOK {
		return nil, errorDecoder(r)
	}
	var resp AutoMsgOrderListHelper
	err := json.NewDecoder(r.Body).Decode(&resp)
	return &resp, err
}

func (s *grpcServerBookstoreV1) AutoListPublisher(ctx oldcontext.Context, req *api.ListWatchOptions) (*AutoMsgPublisherListHelper, error) {
	_, resp, err := s.AutoListPublisherHdlr.ServeGRPC(ctx, req)
	if err != nil {
		return nil, err
	}
	r := resp.(respBookstoreV1AutoListPublisher).V
	return &r, resp.(respBookstoreV1AutoListPublisher).Err
}

func decodeHTTPrespBookstoreV1AutoListPublisher(_ context.Context, r *http.Response) (interface{}, error) {
	if r.StatusCode != http.StatusOK {
		return nil, errorDecoder(r)
	}
	var resp AutoMsgPublisherListHelper
	err := json.NewDecoder(r.Body).Decode(&resp)
	return &resp, err
}

func (s *grpcServerBookstoreV1) AutoUpdateBook(ctx oldcontext.Context, req *Book) (*Book, error) {
	_, resp, err := s.AutoUpdateBookHdlr.ServeGRPC(ctx, req)
	if err != nil {
		return nil, err
	}
	r := resp.(respBookstoreV1AutoUpdateBook).V
	return &r, resp.(respBookstoreV1AutoUpdateBook).Err
}

func decodeHTTPrespBookstoreV1AutoUpdateBook(_ context.Context, r *http.Response) (interface{}, error) {
	if r.StatusCode != http.StatusOK {
		return nil, errorDecoder(r)
	}
	var resp Book
	err := json.NewDecoder(r.Body).Decode(&resp)
	return &resp, err
}

func (s *grpcServerBookstoreV1) AutoUpdateOrder(ctx oldcontext.Context, req *Order) (*Order, error) {
	_, resp, err := s.AutoUpdateOrderHdlr.ServeGRPC(ctx, req)
	if err != nil {
		return nil, err
	}
	r := resp.(respBookstoreV1AutoUpdateOrder).V
	return &r, resp.(respBookstoreV1AutoUpdateOrder).Err
}

func decodeHTTPrespBookstoreV1AutoUpdateOrder(_ context.Context, r *http.Response) (interface{}, error) {
	if r.StatusCode != http.StatusOK {
		return nil, errorDecoder(r)
	}
	var resp Order
	err := json.NewDecoder(r.Body).Decode(&resp)
	return &resp, err
}

func (s *grpcServerBookstoreV1) AutoUpdatePublisher(ctx oldcontext.Context, req *Publisher) (*Publisher, error) {
	_, resp, err := s.AutoUpdatePublisherHdlr.ServeGRPC(ctx, req)
	if err != nil {
		return nil, err
	}
	r := resp.(respBookstoreV1AutoUpdatePublisher).V
	return &r, resp.(respBookstoreV1AutoUpdatePublisher).Err
}

func decodeHTTPrespBookstoreV1AutoUpdatePublisher(_ context.Context, r *http.Response) (interface{}, error) {
	if r.StatusCode != http.StatusOK {
		return nil, errorDecoder(r)
	}
	var resp Publisher
	err := json.NewDecoder(r.Body).Decode(&resp)
	return &resp, err
}

func (s *grpcServerBookstoreV1) AutoWatchOrder(in *api.ListWatchOptions, stream BookstoreV1_AutoWatchOrderServer) error {
	return s.Endpoints.AutoWatchOrder(in, stream)
}

func (s *grpcServerBookstoreV1) AutoWatchBook(in *api.ListWatchOptions, stream BookstoreV1_AutoWatchBookServer) error {
	return s.Endpoints.AutoWatchBook(in, stream)
}

func (s *grpcServerBookstoreV1) AutoWatchPublisher(in *api.ListWatchOptions, stream BookstoreV1_AutoWatchPublisherServer) error {
	return s.Endpoints.AutoWatchPublisher(in, stream)
}

func encodeHTTPAutoMsgBookListHelper(ctx context.Context, req *http.Request, request interface{}) error {
	return encodeHTTPRequest(ctx, req, request)
}

func decodeHTTPAutoMsgBookListHelper(_ context.Context, r *http.Request) (interface{}, error) {
	var req AutoMsgBookListHelper
	if e := json.NewDecoder(r.Body).Decode(&req); e != nil {
		return nil, e
	}
	return req, nil
}

// EncodeGrpcReqAutoMsgBookListHelper encodes GRPC request
func EncodeGrpcReqAutoMsgBookListHelper(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*AutoMsgBookListHelper)
	return req, nil
}

// DecodeGrpcReqAutoMsgBookListHelper decodes GRPC request
func DecodeGrpcReqAutoMsgBookListHelper(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*AutoMsgBookListHelper)
	return req, nil
}

// EncodeGrpcRespAutoMsgBookListHelper endodes the GRPC response
func EncodeGrpcRespAutoMsgBookListHelper(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}

// DecodeGrpcRespAutoMsgBookListHelper decodes the GRPC response
func DecodeGrpcRespAutoMsgBookListHelper(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}

func encodeHTTPAutoMsgOrderListHelper(ctx context.Context, req *http.Request, request interface{}) error {
	return encodeHTTPRequest(ctx, req, request)
}

func decodeHTTPAutoMsgOrderListHelper(_ context.Context, r *http.Request) (interface{}, error) {
	var req AutoMsgOrderListHelper
	if e := json.NewDecoder(r.Body).Decode(&req); e != nil {
		return nil, e
	}
	return req, nil
}

// EncodeGrpcReqAutoMsgOrderListHelper encodes GRPC request
func EncodeGrpcReqAutoMsgOrderListHelper(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*AutoMsgOrderListHelper)
	return req, nil
}

// DecodeGrpcReqAutoMsgOrderListHelper decodes GRPC request
func DecodeGrpcReqAutoMsgOrderListHelper(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*AutoMsgOrderListHelper)
	return req, nil
}

// EncodeGrpcRespAutoMsgOrderListHelper endodes the GRPC response
func EncodeGrpcRespAutoMsgOrderListHelper(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}

// DecodeGrpcRespAutoMsgOrderListHelper decodes the GRPC response
func DecodeGrpcRespAutoMsgOrderListHelper(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}

func encodeHTTPAutoMsgPublisherListHelper(ctx context.Context, req *http.Request, request interface{}) error {
	return encodeHTTPRequest(ctx, req, request)
}

func decodeHTTPAutoMsgPublisherListHelper(_ context.Context, r *http.Request) (interface{}, error) {
	var req AutoMsgPublisherListHelper
	if e := json.NewDecoder(r.Body).Decode(&req); e != nil {
		return nil, e
	}
	return req, nil
}

// EncodeGrpcReqAutoMsgPublisherListHelper encodes GRPC request
func EncodeGrpcReqAutoMsgPublisherListHelper(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*AutoMsgPublisherListHelper)
	return req, nil
}

// DecodeGrpcReqAutoMsgPublisherListHelper decodes GRPC request
func DecodeGrpcReqAutoMsgPublisherListHelper(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*AutoMsgPublisherListHelper)
	return req, nil
}

// EncodeGrpcRespAutoMsgPublisherListHelper endodes the GRPC response
func EncodeGrpcRespAutoMsgPublisherListHelper(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}

// DecodeGrpcRespAutoMsgPublisherListHelper decodes the GRPC response
func DecodeGrpcRespAutoMsgPublisherListHelper(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}

func encodeHTTPBook(ctx context.Context, req *http.Request, request interface{}) error {
	return encodeHTTPRequest(ctx, req, request)
}

func decodeHTTPBook(_ context.Context, r *http.Request) (interface{}, error) {
	var req Book
	if e := json.NewDecoder(r.Body).Decode(&req); e != nil {
		return nil, e
	}
	return req, nil
}

// EncodeGrpcReqBook encodes GRPC request
func EncodeGrpcReqBook(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*Book)
	return req, nil
}

// DecodeGrpcReqBook decodes GRPC request
func DecodeGrpcReqBook(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*Book)
	return req, nil
}

// EncodeGrpcRespBook encodes GRC response
func EncodeGrpcRespBook(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}

// DecodeGrpcRespBook decodes GRPC response
func DecodeGrpcRespBook(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}

func encodeHTTPBookSpec(ctx context.Context, req *http.Request, request interface{}) error {
	return encodeHTTPRequest(ctx, req, request)
}

func decodeHTTPBookSpec(_ context.Context, r *http.Request) (interface{}, error) {
	var req BookSpec
	if e := json.NewDecoder(r.Body).Decode(&req); e != nil {
		return nil, e
	}
	return req, nil
}

// EncodeGrpcReqBookSpec encodes GRPC request
func EncodeGrpcReqBookSpec(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*BookSpec)
	return req, nil
}

// DecodeGrpcReqBookSpec decodes GRPC request
func DecodeGrpcReqBookSpec(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*BookSpec)
	return req, nil
}

// EncodeGrpcRespBookSpec encodes GRC response
func EncodeGrpcRespBookSpec(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}

// DecodeGrpcRespBookSpec decodes GRPC response
func DecodeGrpcRespBookSpec(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}

func encodeHTTPBookStatus(ctx context.Context, req *http.Request, request interface{}) error {
	return encodeHTTPRequest(ctx, req, request)
}

func decodeHTTPBookStatus(_ context.Context, r *http.Request) (interface{}, error) {
	var req BookStatus
	if e := json.NewDecoder(r.Body).Decode(&req); e != nil {
		return nil, e
	}
	return req, nil
}

// EncodeGrpcReqBookStatus encodes GRPC request
func EncodeGrpcReqBookStatus(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*BookStatus)
	return req, nil
}

// DecodeGrpcReqBookStatus decodes GRPC request
func DecodeGrpcReqBookStatus(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*BookStatus)
	return req, nil
}

// EncodeGrpcRespBookStatus encodes GRC response
func EncodeGrpcRespBookStatus(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}

// DecodeGrpcRespBookStatus decodes GRPC response
func DecodeGrpcRespBookStatus(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}

func encodeHTTPOrder(ctx context.Context, req *http.Request, request interface{}) error {
	return encodeHTTPRequest(ctx, req, request)
}

func decodeHTTPOrder(_ context.Context, r *http.Request) (interface{}, error) {
	var req Order
	if e := json.NewDecoder(r.Body).Decode(&req); e != nil {
		return nil, e
	}
	return req, nil
}

// EncodeGrpcReqOrder encodes GRPC request
func EncodeGrpcReqOrder(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*Order)
	return req, nil
}

// DecodeGrpcReqOrder decodes GRPC request
func DecodeGrpcReqOrder(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*Order)
	return req, nil
}

// EncodeGrpcRespOrder encodes GRC response
func EncodeGrpcRespOrder(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}

// DecodeGrpcRespOrder decodes GRPC response
func DecodeGrpcRespOrder(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}

func encodeHTTPOrderItem(ctx context.Context, req *http.Request, request interface{}) error {
	return encodeHTTPRequest(ctx, req, request)
}

func decodeHTTPOrderItem(_ context.Context, r *http.Request) (interface{}, error) {
	var req OrderItem
	if e := json.NewDecoder(r.Body).Decode(&req); e != nil {
		return nil, e
	}
	return req, nil
}

// EncodeGrpcReqOrderItem encodes GRPC request
func EncodeGrpcReqOrderItem(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*OrderItem)
	return req, nil
}

// DecodeGrpcReqOrderItem decodes GRPC request
func DecodeGrpcReqOrderItem(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*OrderItem)
	return req, nil
}

// EncodeGrpcRespOrderItem encodes GRC response
func EncodeGrpcRespOrderItem(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}

// DecodeGrpcRespOrderItem decodes GRPC response
func DecodeGrpcRespOrderItem(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}

func encodeHTTPOrderSpec(ctx context.Context, req *http.Request, request interface{}) error {
	return encodeHTTPRequest(ctx, req, request)
}

func decodeHTTPOrderSpec(_ context.Context, r *http.Request) (interface{}, error) {
	var req OrderSpec
	if e := json.NewDecoder(r.Body).Decode(&req); e != nil {
		return nil, e
	}
	return req, nil
}

// EncodeGrpcReqOrderSpec encodes GRPC request
func EncodeGrpcReqOrderSpec(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*OrderSpec)
	return req, nil
}

// DecodeGrpcReqOrderSpec decodes GRPC request
func DecodeGrpcReqOrderSpec(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*OrderSpec)
	return req, nil
}

// EncodeGrpcRespOrderSpec encodes GRC response
func EncodeGrpcRespOrderSpec(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}

// DecodeGrpcRespOrderSpec decodes GRPC response
func DecodeGrpcRespOrderSpec(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}

func encodeHTTPOrderStatus(ctx context.Context, req *http.Request, request interface{}) error {
	return encodeHTTPRequest(ctx, req, request)
}

func decodeHTTPOrderStatus(_ context.Context, r *http.Request) (interface{}, error) {
	var req OrderStatus
	if e := json.NewDecoder(r.Body).Decode(&req); e != nil {
		return nil, e
	}
	return req, nil
}

// EncodeGrpcReqOrderStatus encodes GRPC request
func EncodeGrpcReqOrderStatus(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*OrderStatus)
	return req, nil
}

// DecodeGrpcReqOrderStatus decodes GRPC request
func DecodeGrpcReqOrderStatus(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*OrderStatus)
	return req, nil
}

// EncodeGrpcRespOrderStatus encodes GRC response
func EncodeGrpcRespOrderStatus(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}

// DecodeGrpcRespOrderStatus decodes GRPC response
func DecodeGrpcRespOrderStatus(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}

func encodeHTTPPublisher(ctx context.Context, req *http.Request, request interface{}) error {
	return encodeHTTPRequest(ctx, req, request)
}

func decodeHTTPPublisher(_ context.Context, r *http.Request) (interface{}, error) {
	var req Publisher
	if e := json.NewDecoder(r.Body).Decode(&req); e != nil {
		return nil, e
	}
	return req, nil
}

// EncodeGrpcReqPublisher encodes GRPC request
func EncodeGrpcReqPublisher(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*Publisher)
	return req, nil
}

// DecodeGrpcReqPublisher decodes GRPC request
func DecodeGrpcReqPublisher(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*Publisher)
	return req, nil
}

// EncodeGrpcRespPublisher encodes GRC response
func EncodeGrpcRespPublisher(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}

// DecodeGrpcRespPublisher decodes GRPC response
func DecodeGrpcRespPublisher(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}

func encodeHTTPPublisherSpec(ctx context.Context, req *http.Request, request interface{}) error {
	return encodeHTTPRequest(ctx, req, request)
}

func decodeHTTPPublisherSpec(_ context.Context, r *http.Request) (interface{}, error) {
	var req PublisherSpec
	if e := json.NewDecoder(r.Body).Decode(&req); e != nil {
		return nil, e
	}
	return req, nil
}

// EncodeGrpcReqPublisherSpec encodes GRPC request
func EncodeGrpcReqPublisherSpec(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*PublisherSpec)
	return req, nil
}

// DecodeGrpcReqPublisherSpec decodes GRPC request
func DecodeGrpcReqPublisherSpec(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*PublisherSpec)
	return req, nil
}

// EncodeGrpcRespPublisherSpec encodes GRC response
func EncodeGrpcRespPublisherSpec(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}

// DecodeGrpcRespPublisherSpec decodes GRPC response
func DecodeGrpcRespPublisherSpec(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}

func encodeHTTPListWatchOptions(ctx context.Context, req *http.Request, request interface{}) error {
	return encodeHTTPRequest(ctx, req, request)
}

func decodeHTTPListWatchOptions(_ context.Context, r *http.Request) (interface{}, error) {
	var req api.ListWatchOptions
	if e := json.NewDecoder(r.Body).Decode(&req); e != nil {
		return nil, e
	}
	return req, nil
}

// EncodeGrpcReqListWatchOptions encodes ListWatchOptions
func EncodeGrpcReqListWatchOptions(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*api.ListWatchOptions)
	return req, nil
}

// DecodeGrpcReqListWatchOptions encodes ListWatchOptions
func DecodeGrpcReqListWatchOptions(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*(api.ListWatchOptions))
	return req, nil
}

// EncodeGrpcRespListWatchOptions encodes response
func EncodeGrpcRespListWatchOptions(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}

// DecodeGrpcRespListWatchOptions decodes response
func DecodeGrpcRespListWatchOptions(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}

func encodeHTTPResponse(ctx context.Context, w http.ResponseWriter, response interface{}) error {
	if e, ok := response.(errorer); ok && e.error() != nil {
		// Not a Go kit transport error, but a business-logic error.
		// Provide those as HTTP errors.
		encodeError(ctx, e.error(), w)
		return nil
	}
	w.Header().Set("Content-Type", "application/json; charset=utf-8")
	return json.NewEncoder(w).Encode(response)
}

func encodeHTTPRequest(_ context.Context, req *http.Request, request interface{}) error {
	var buf bytes.Buffer
	err := json.NewEncoder(&buf).Encode(request)
	if err != nil {
		return err
	}
	req.Body = ioutil.NopCloser(&buf)
	return nil
}

type errorer interface {
	error() error
}

func encodeError(_ context.Context, err error, w http.ResponseWriter) {
	if err == nil {
		panic("encodeError with nil error")
	}
	w.Header().Set("Content-Type", "application/json; charset=utf-8")
	w.WriteHeader(codeFrom(err))
	json.NewEncoder(w).Encode(map[string]interface{}{
		"error": err.Error(),
	})
}

func errorDecoder(r *http.Response) error {
	var w errorWrapper
	if err := json.NewDecoder(r.Body).Decode(&w); err != nil {
		return err
	}
	return fmt.Errorf("Status:(%v) Reason:(%s)", r.StatusCode, w.Error)
}

type errorWrapper struct {
	Error string `json:"error"`
}

func codeFrom(err error) int {
	switch err {
	case errNotFound:
		return http.StatusNotFound
	case errAlreadyExists, errInconsistentIDs:
		return http.StatusBadRequest
	default:
		return http.StatusInternalServerError
	}
}
