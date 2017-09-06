// Code generated by protoc-gen-grpc-pensando DO NOT EDIT.

/*
Package cmd is a auto generated package.
Input file: protos/cmd.proto
*/
package cmd

import (
	"context"
	"encoding/json"
	"net/http"

	"github.com/go-kit/kit/tracing/opentracing"
	grpctransport "github.com/go-kit/kit/transport/grpc"
	stdopentracing "github.com/opentracing/opentracing-go"
	oldcontext "golang.org/x/net/context"

	"github.com/pensando/sw/api"
	"github.com/pensando/sw/utils/log"
)

// Dummy definitions to suppress nonused warnings
var _ api.ObjectMeta

type grpcServerCmdV1 struct {
	Endpoints EndpointsCmdV1Server

	AutoAddClusterHdlr     grpctransport.Handler
	AutoAddNodeHdlr        grpctransport.Handler
	AutoAddSmartNICHdlr    grpctransport.Handler
	AutoDeleteClusterHdlr  grpctransport.Handler
	AutoDeleteNodeHdlr     grpctransport.Handler
	AutoDeleteSmartNICHdlr grpctransport.Handler
	AutoGetClusterHdlr     grpctransport.Handler
	AutoGetNodeHdlr        grpctransport.Handler
	AutoGetSmartNICHdlr    grpctransport.Handler
	AutoListClusterHdlr    grpctransport.Handler
	AutoListNodeHdlr       grpctransport.Handler
	AutoListSmartNICHdlr   grpctransport.Handler
	AutoUpdateClusterHdlr  grpctransport.Handler
	AutoUpdateNodeHdlr     grpctransport.Handler
	AutoUpdateSmartNICHdlr grpctransport.Handler
}

// MakeGRPCServerCmdV1 creates a GRPC server for CmdV1 service
func MakeGRPCServerCmdV1(ctx context.Context, endpoints EndpointsCmdV1Server, logger log.Logger) CmdV1Server {
	options := []grpctransport.ServerOption{
		grpctransport.ServerErrorLogger(logger),
		grpctransport.ServerBefore(recoverVersion),
	}
	return &grpcServerCmdV1{
		Endpoints: endpoints,
		AutoAddClusterHdlr: grpctransport.NewServer(
			endpoints.AutoAddClusterEndpoint,
			DecodeGrpcReqCluster,
			EncodeGrpcRespCluster,
			append(options, grpctransport.ServerBefore(opentracing.FromGRPCRequest(stdopentracing.GlobalTracer(), "AutoAddCluster", logger)))...,
		),

		AutoAddNodeHdlr: grpctransport.NewServer(
			endpoints.AutoAddNodeEndpoint,
			DecodeGrpcReqNode,
			EncodeGrpcRespNode,
			append(options, grpctransport.ServerBefore(opentracing.FromGRPCRequest(stdopentracing.GlobalTracer(), "AutoAddNode", logger)))...,
		),

		AutoAddSmartNICHdlr: grpctransport.NewServer(
			endpoints.AutoAddSmartNICEndpoint,
			DecodeGrpcReqSmartNIC,
			EncodeGrpcRespSmartNIC,
			append(options, grpctransport.ServerBefore(opentracing.FromGRPCRequest(stdopentracing.GlobalTracer(), "AutoAddSmartNIC", logger)))...,
		),

		AutoDeleteClusterHdlr: grpctransport.NewServer(
			endpoints.AutoDeleteClusterEndpoint,
			DecodeGrpcReqCluster,
			EncodeGrpcRespCluster,
			append(options, grpctransport.ServerBefore(opentracing.FromGRPCRequest(stdopentracing.GlobalTracer(), "AutoDeleteCluster", logger)))...,
		),

		AutoDeleteNodeHdlr: grpctransport.NewServer(
			endpoints.AutoDeleteNodeEndpoint,
			DecodeGrpcReqNode,
			EncodeGrpcRespNode,
			append(options, grpctransport.ServerBefore(opentracing.FromGRPCRequest(stdopentracing.GlobalTracer(), "AutoDeleteNode", logger)))...,
		),

		AutoDeleteSmartNICHdlr: grpctransport.NewServer(
			endpoints.AutoDeleteSmartNICEndpoint,
			DecodeGrpcReqSmartNIC,
			EncodeGrpcRespSmartNIC,
			append(options, grpctransport.ServerBefore(opentracing.FromGRPCRequest(stdopentracing.GlobalTracer(), "AutoDeleteSmartNIC", logger)))...,
		),

		AutoGetClusterHdlr: grpctransport.NewServer(
			endpoints.AutoGetClusterEndpoint,
			DecodeGrpcReqCluster,
			EncodeGrpcRespCluster,
			append(options, grpctransport.ServerBefore(opentracing.FromGRPCRequest(stdopentracing.GlobalTracer(), "AutoGetCluster", logger)))...,
		),

		AutoGetNodeHdlr: grpctransport.NewServer(
			endpoints.AutoGetNodeEndpoint,
			DecodeGrpcReqNode,
			EncodeGrpcRespNode,
			append(options, grpctransport.ServerBefore(opentracing.FromGRPCRequest(stdopentracing.GlobalTracer(), "AutoGetNode", logger)))...,
		),

		AutoGetSmartNICHdlr: grpctransport.NewServer(
			endpoints.AutoGetSmartNICEndpoint,
			DecodeGrpcReqSmartNIC,
			EncodeGrpcRespSmartNIC,
			append(options, grpctransport.ServerBefore(opentracing.FromGRPCRequest(stdopentracing.GlobalTracer(), "AutoGetSmartNIC", logger)))...,
		),

		AutoListClusterHdlr: grpctransport.NewServer(
			endpoints.AutoListClusterEndpoint,
			DecodeGrpcReqListWatchOptions,
			EncodeGrpcRespClusterList,
			append(options, grpctransport.ServerBefore(opentracing.FromGRPCRequest(stdopentracing.GlobalTracer(), "AutoListCluster", logger)))...,
		),

		AutoListNodeHdlr: grpctransport.NewServer(
			endpoints.AutoListNodeEndpoint,
			DecodeGrpcReqListWatchOptions,
			EncodeGrpcRespNodeList,
			append(options, grpctransport.ServerBefore(opentracing.FromGRPCRequest(stdopentracing.GlobalTracer(), "AutoListNode", logger)))...,
		),

		AutoListSmartNICHdlr: grpctransport.NewServer(
			endpoints.AutoListSmartNICEndpoint,
			DecodeGrpcReqListWatchOptions,
			EncodeGrpcRespSmartNICList,
			append(options, grpctransport.ServerBefore(opentracing.FromGRPCRequest(stdopentracing.GlobalTracer(), "AutoListSmartNIC", logger)))...,
		),

		AutoUpdateClusterHdlr: grpctransport.NewServer(
			endpoints.AutoUpdateClusterEndpoint,
			DecodeGrpcReqCluster,
			EncodeGrpcRespCluster,
			append(options, grpctransport.ServerBefore(opentracing.FromGRPCRequest(stdopentracing.GlobalTracer(), "AutoUpdateCluster", logger)))...,
		),

		AutoUpdateNodeHdlr: grpctransport.NewServer(
			endpoints.AutoUpdateNodeEndpoint,
			DecodeGrpcReqNode,
			EncodeGrpcRespNode,
			append(options, grpctransport.ServerBefore(opentracing.FromGRPCRequest(stdopentracing.GlobalTracer(), "AutoUpdateNode", logger)))...,
		),

		AutoUpdateSmartNICHdlr: grpctransport.NewServer(
			endpoints.AutoUpdateSmartNICEndpoint,
			DecodeGrpcReqSmartNIC,
			EncodeGrpcRespSmartNIC,
			append(options, grpctransport.ServerBefore(opentracing.FromGRPCRequest(stdopentracing.GlobalTracer(), "AutoUpdateSmartNIC", logger)))...,
		),
	}
}

func (s *grpcServerCmdV1) AutoAddCluster(ctx oldcontext.Context, req *Cluster) (*Cluster, error) {
	_, resp, err := s.AutoAddClusterHdlr.ServeGRPC(ctx, req)
	if err != nil {
		return nil, err
	}
	r := resp.(respCmdV1AutoAddCluster).V
	return &r, resp.(respCmdV1AutoAddCluster).Err
}

func decodeHTTPrespCmdV1AutoAddCluster(_ context.Context, r *http.Response) (interface{}, error) {
	if r.StatusCode != http.StatusOK {
		return nil, errorDecoder(r)
	}
	var resp Cluster
	err := json.NewDecoder(r.Body).Decode(&resp)
	return &resp, err
}

func (s *grpcServerCmdV1) AutoAddNode(ctx oldcontext.Context, req *Node) (*Node, error) {
	_, resp, err := s.AutoAddNodeHdlr.ServeGRPC(ctx, req)
	if err != nil {
		return nil, err
	}
	r := resp.(respCmdV1AutoAddNode).V
	return &r, resp.(respCmdV1AutoAddNode).Err
}

func decodeHTTPrespCmdV1AutoAddNode(_ context.Context, r *http.Response) (interface{}, error) {
	if r.StatusCode != http.StatusOK {
		return nil, errorDecoder(r)
	}
	var resp Node
	err := json.NewDecoder(r.Body).Decode(&resp)
	return &resp, err
}

func (s *grpcServerCmdV1) AutoAddSmartNIC(ctx oldcontext.Context, req *SmartNIC) (*SmartNIC, error) {
	_, resp, err := s.AutoAddSmartNICHdlr.ServeGRPC(ctx, req)
	if err != nil {
		return nil, err
	}
	r := resp.(respCmdV1AutoAddSmartNIC).V
	return &r, resp.(respCmdV1AutoAddSmartNIC).Err
}

func decodeHTTPrespCmdV1AutoAddSmartNIC(_ context.Context, r *http.Response) (interface{}, error) {
	if r.StatusCode != http.StatusOK {
		return nil, errorDecoder(r)
	}
	var resp SmartNIC
	err := json.NewDecoder(r.Body).Decode(&resp)
	return &resp, err
}

func (s *grpcServerCmdV1) AutoDeleteCluster(ctx oldcontext.Context, req *Cluster) (*Cluster, error) {
	_, resp, err := s.AutoDeleteClusterHdlr.ServeGRPC(ctx, req)
	if err != nil {
		return nil, err
	}
	r := resp.(respCmdV1AutoDeleteCluster).V
	return &r, resp.(respCmdV1AutoDeleteCluster).Err
}

func decodeHTTPrespCmdV1AutoDeleteCluster(_ context.Context, r *http.Response) (interface{}, error) {
	if r.StatusCode != http.StatusOK {
		return nil, errorDecoder(r)
	}
	var resp Cluster
	err := json.NewDecoder(r.Body).Decode(&resp)
	return &resp, err
}

func (s *grpcServerCmdV1) AutoDeleteNode(ctx oldcontext.Context, req *Node) (*Node, error) {
	_, resp, err := s.AutoDeleteNodeHdlr.ServeGRPC(ctx, req)
	if err != nil {
		return nil, err
	}
	r := resp.(respCmdV1AutoDeleteNode).V
	return &r, resp.(respCmdV1AutoDeleteNode).Err
}

func decodeHTTPrespCmdV1AutoDeleteNode(_ context.Context, r *http.Response) (interface{}, error) {
	if r.StatusCode != http.StatusOK {
		return nil, errorDecoder(r)
	}
	var resp Node
	err := json.NewDecoder(r.Body).Decode(&resp)
	return &resp, err
}

func (s *grpcServerCmdV1) AutoDeleteSmartNIC(ctx oldcontext.Context, req *SmartNIC) (*SmartNIC, error) {
	_, resp, err := s.AutoDeleteSmartNICHdlr.ServeGRPC(ctx, req)
	if err != nil {
		return nil, err
	}
	r := resp.(respCmdV1AutoDeleteSmartNIC).V
	return &r, resp.(respCmdV1AutoDeleteSmartNIC).Err
}

func decodeHTTPrespCmdV1AutoDeleteSmartNIC(_ context.Context, r *http.Response) (interface{}, error) {
	if r.StatusCode != http.StatusOK {
		return nil, errorDecoder(r)
	}
	var resp SmartNIC
	err := json.NewDecoder(r.Body).Decode(&resp)
	return &resp, err
}

func (s *grpcServerCmdV1) AutoGetCluster(ctx oldcontext.Context, req *Cluster) (*Cluster, error) {
	_, resp, err := s.AutoGetClusterHdlr.ServeGRPC(ctx, req)
	if err != nil {
		return nil, err
	}
	r := resp.(respCmdV1AutoGetCluster).V
	return &r, resp.(respCmdV1AutoGetCluster).Err
}

func decodeHTTPrespCmdV1AutoGetCluster(_ context.Context, r *http.Response) (interface{}, error) {
	if r.StatusCode != http.StatusOK {
		return nil, errorDecoder(r)
	}
	var resp Cluster
	err := json.NewDecoder(r.Body).Decode(&resp)
	return &resp, err
}

func (s *grpcServerCmdV1) AutoGetNode(ctx oldcontext.Context, req *Node) (*Node, error) {
	_, resp, err := s.AutoGetNodeHdlr.ServeGRPC(ctx, req)
	if err != nil {
		return nil, err
	}
	r := resp.(respCmdV1AutoGetNode).V
	return &r, resp.(respCmdV1AutoGetNode).Err
}

func decodeHTTPrespCmdV1AutoGetNode(_ context.Context, r *http.Response) (interface{}, error) {
	if r.StatusCode != http.StatusOK {
		return nil, errorDecoder(r)
	}
	var resp Node
	err := json.NewDecoder(r.Body).Decode(&resp)
	return &resp, err
}

func (s *grpcServerCmdV1) AutoGetSmartNIC(ctx oldcontext.Context, req *SmartNIC) (*SmartNIC, error) {
	_, resp, err := s.AutoGetSmartNICHdlr.ServeGRPC(ctx, req)
	if err != nil {
		return nil, err
	}
	r := resp.(respCmdV1AutoGetSmartNIC).V
	return &r, resp.(respCmdV1AutoGetSmartNIC).Err
}

func decodeHTTPrespCmdV1AutoGetSmartNIC(_ context.Context, r *http.Response) (interface{}, error) {
	if r.StatusCode != http.StatusOK {
		return nil, errorDecoder(r)
	}
	var resp SmartNIC
	err := json.NewDecoder(r.Body).Decode(&resp)
	return &resp, err
}

func (s *grpcServerCmdV1) AutoListCluster(ctx oldcontext.Context, req *api.ListWatchOptions) (*ClusterList, error) {
	_, resp, err := s.AutoListClusterHdlr.ServeGRPC(ctx, req)
	if err != nil {
		return nil, err
	}
	r := resp.(respCmdV1AutoListCluster).V
	return &r, resp.(respCmdV1AutoListCluster).Err
}

func decodeHTTPrespCmdV1AutoListCluster(_ context.Context, r *http.Response) (interface{}, error) {
	if r.StatusCode != http.StatusOK {
		return nil, errorDecoder(r)
	}
	var resp ClusterList
	err := json.NewDecoder(r.Body).Decode(&resp)
	return &resp, err
}

func (s *grpcServerCmdV1) AutoListNode(ctx oldcontext.Context, req *api.ListWatchOptions) (*NodeList, error) {
	_, resp, err := s.AutoListNodeHdlr.ServeGRPC(ctx, req)
	if err != nil {
		return nil, err
	}
	r := resp.(respCmdV1AutoListNode).V
	return &r, resp.(respCmdV1AutoListNode).Err
}

func decodeHTTPrespCmdV1AutoListNode(_ context.Context, r *http.Response) (interface{}, error) {
	if r.StatusCode != http.StatusOK {
		return nil, errorDecoder(r)
	}
	var resp NodeList
	err := json.NewDecoder(r.Body).Decode(&resp)
	return &resp, err
}

func (s *grpcServerCmdV1) AutoListSmartNIC(ctx oldcontext.Context, req *api.ListWatchOptions) (*SmartNICList, error) {
	_, resp, err := s.AutoListSmartNICHdlr.ServeGRPC(ctx, req)
	if err != nil {
		return nil, err
	}
	r := resp.(respCmdV1AutoListSmartNIC).V
	return &r, resp.(respCmdV1AutoListSmartNIC).Err
}

func decodeHTTPrespCmdV1AutoListSmartNIC(_ context.Context, r *http.Response) (interface{}, error) {
	if r.StatusCode != http.StatusOK {
		return nil, errorDecoder(r)
	}
	var resp SmartNICList
	err := json.NewDecoder(r.Body).Decode(&resp)
	return &resp, err
}

func (s *grpcServerCmdV1) AutoUpdateCluster(ctx oldcontext.Context, req *Cluster) (*Cluster, error) {
	_, resp, err := s.AutoUpdateClusterHdlr.ServeGRPC(ctx, req)
	if err != nil {
		return nil, err
	}
	r := resp.(respCmdV1AutoUpdateCluster).V
	return &r, resp.(respCmdV1AutoUpdateCluster).Err
}

func decodeHTTPrespCmdV1AutoUpdateCluster(_ context.Context, r *http.Response) (interface{}, error) {
	if r.StatusCode != http.StatusOK {
		return nil, errorDecoder(r)
	}
	var resp Cluster
	err := json.NewDecoder(r.Body).Decode(&resp)
	return &resp, err
}

func (s *grpcServerCmdV1) AutoUpdateNode(ctx oldcontext.Context, req *Node) (*Node, error) {
	_, resp, err := s.AutoUpdateNodeHdlr.ServeGRPC(ctx, req)
	if err != nil {
		return nil, err
	}
	r := resp.(respCmdV1AutoUpdateNode).V
	return &r, resp.(respCmdV1AutoUpdateNode).Err
}

func decodeHTTPrespCmdV1AutoUpdateNode(_ context.Context, r *http.Response) (interface{}, error) {
	if r.StatusCode != http.StatusOK {
		return nil, errorDecoder(r)
	}
	var resp Node
	err := json.NewDecoder(r.Body).Decode(&resp)
	return &resp, err
}

func (s *grpcServerCmdV1) AutoUpdateSmartNIC(ctx oldcontext.Context, req *SmartNIC) (*SmartNIC, error) {
	_, resp, err := s.AutoUpdateSmartNICHdlr.ServeGRPC(ctx, req)
	if err != nil {
		return nil, err
	}
	r := resp.(respCmdV1AutoUpdateSmartNIC).V
	return &r, resp.(respCmdV1AutoUpdateSmartNIC).Err
}

func decodeHTTPrespCmdV1AutoUpdateSmartNIC(_ context.Context, r *http.Response) (interface{}, error) {
	if r.StatusCode != http.StatusOK {
		return nil, errorDecoder(r)
	}
	var resp SmartNIC
	err := json.NewDecoder(r.Body).Decode(&resp)
	return &resp, err
}

func (s *grpcServerCmdV1) AutoWatchCluster(in *api.ListWatchOptions, stream CmdV1_AutoWatchClusterServer) error {
	return s.Endpoints.AutoWatchCluster(in, stream)
}

func (s *grpcServerCmdV1) AutoWatchNode(in *api.ListWatchOptions, stream CmdV1_AutoWatchNodeServer) error {
	return s.Endpoints.AutoWatchNode(in, stream)
}

func (s *grpcServerCmdV1) AutoWatchSmartNIC(in *api.ListWatchOptions, stream CmdV1_AutoWatchSmartNICServer) error {
	return s.Endpoints.AutoWatchSmartNIC(in, stream)
}

func encodeHTTPCluster(ctx context.Context, req *http.Request, request interface{}) error {
	return encodeHTTPRequest(ctx, req, request)
}

func decodeHTTPCluster(_ context.Context, r *http.Request) (interface{}, error) {
	var req Cluster
	if e := json.NewDecoder(r.Body).Decode(&req); e != nil {
		return nil, e
	}
	return req, nil
}

// EncodeGrpcReqCluster encodes GRPC request
func EncodeGrpcReqCluster(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*Cluster)
	return req, nil
}

// DecodeGrpcReqCluster decodes GRPC request
func DecodeGrpcReqCluster(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*Cluster)
	return req, nil
}

// EncodeGrpcRespCluster encodes GRC response
func EncodeGrpcRespCluster(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}

// DecodeGrpcRespCluster decodes GRPC response
func DecodeGrpcRespCluster(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}

func encodeHTTPClusterList(ctx context.Context, req *http.Request, request interface{}) error {
	return encodeHTTPRequest(ctx, req, request)
}

func decodeHTTPClusterList(_ context.Context, r *http.Request) (interface{}, error) {
	var req ClusterList
	if e := json.NewDecoder(r.Body).Decode(&req); e != nil {
		return nil, e
	}
	return req, nil
}

// EncodeGrpcReqClusterList encodes GRPC request
func EncodeGrpcReqClusterList(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*ClusterList)
	return req, nil
}

// DecodeGrpcReqClusterList decodes GRPC request
func DecodeGrpcReqClusterList(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*ClusterList)
	return req, nil
}

// EncodeGrpcRespClusterList endodes the GRPC response
func EncodeGrpcRespClusterList(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}

// DecodeGrpcRespClusterList decodes the GRPC response
func DecodeGrpcRespClusterList(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}

func encodeHTTPClusterSpec(ctx context.Context, req *http.Request, request interface{}) error {
	return encodeHTTPRequest(ctx, req, request)
}

func decodeHTTPClusterSpec(_ context.Context, r *http.Request) (interface{}, error) {
	var req ClusterSpec
	if e := json.NewDecoder(r.Body).Decode(&req); e != nil {
		return nil, e
	}
	return req, nil
}

// EncodeGrpcReqClusterSpec encodes GRPC request
func EncodeGrpcReqClusterSpec(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*ClusterSpec)
	return req, nil
}

// DecodeGrpcReqClusterSpec decodes GRPC request
func DecodeGrpcReqClusterSpec(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*ClusterSpec)
	return req, nil
}

// EncodeGrpcRespClusterSpec encodes GRC response
func EncodeGrpcRespClusterSpec(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}

// DecodeGrpcRespClusterSpec decodes GRPC response
func DecodeGrpcRespClusterSpec(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}

func encodeHTTPClusterStatus(ctx context.Context, req *http.Request, request interface{}) error {
	return encodeHTTPRequest(ctx, req, request)
}

func decodeHTTPClusterStatus(_ context.Context, r *http.Request) (interface{}, error) {
	var req ClusterStatus
	if e := json.NewDecoder(r.Body).Decode(&req); e != nil {
		return nil, e
	}
	return req, nil
}

// EncodeGrpcReqClusterStatus encodes GRPC request
func EncodeGrpcReqClusterStatus(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*ClusterStatus)
	return req, nil
}

// DecodeGrpcReqClusterStatus decodes GRPC request
func DecodeGrpcReqClusterStatus(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*ClusterStatus)
	return req, nil
}

// EncodeGrpcRespClusterStatus encodes GRC response
func EncodeGrpcRespClusterStatus(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}

// DecodeGrpcRespClusterStatus decodes GRPC response
func DecodeGrpcRespClusterStatus(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}

func encodeHTTPNode(ctx context.Context, req *http.Request, request interface{}) error {
	return encodeHTTPRequest(ctx, req, request)
}

func decodeHTTPNode(_ context.Context, r *http.Request) (interface{}, error) {
	var req Node
	if e := json.NewDecoder(r.Body).Decode(&req); e != nil {
		return nil, e
	}
	return req, nil
}

// EncodeGrpcReqNode encodes GRPC request
func EncodeGrpcReqNode(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*Node)
	return req, nil
}

// DecodeGrpcReqNode decodes GRPC request
func DecodeGrpcReqNode(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*Node)
	return req, nil
}

// EncodeGrpcRespNode encodes GRC response
func EncodeGrpcRespNode(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}

// DecodeGrpcRespNode decodes GRPC response
func DecodeGrpcRespNode(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}

func encodeHTTPNodeCondition(ctx context.Context, req *http.Request, request interface{}) error {
	return encodeHTTPRequest(ctx, req, request)
}

func decodeHTTPNodeCondition(_ context.Context, r *http.Request) (interface{}, error) {
	var req NodeCondition
	if e := json.NewDecoder(r.Body).Decode(&req); e != nil {
		return nil, e
	}
	return req, nil
}

// EncodeGrpcReqNodeCondition encodes GRPC request
func EncodeGrpcReqNodeCondition(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*NodeCondition)
	return req, nil
}

// DecodeGrpcReqNodeCondition decodes GRPC request
func DecodeGrpcReqNodeCondition(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*NodeCondition)
	return req, nil
}

// EncodeGrpcRespNodeCondition encodes GRC response
func EncodeGrpcRespNodeCondition(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}

// DecodeGrpcRespNodeCondition decodes GRPC response
func DecodeGrpcRespNodeCondition(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}

func encodeHTTPNodeList(ctx context.Context, req *http.Request, request interface{}) error {
	return encodeHTTPRequest(ctx, req, request)
}

func decodeHTTPNodeList(_ context.Context, r *http.Request) (interface{}, error) {
	var req NodeList
	if e := json.NewDecoder(r.Body).Decode(&req); e != nil {
		return nil, e
	}
	return req, nil
}

// EncodeGrpcReqNodeList encodes GRPC request
func EncodeGrpcReqNodeList(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*NodeList)
	return req, nil
}

// DecodeGrpcReqNodeList decodes GRPC request
func DecodeGrpcReqNodeList(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*NodeList)
	return req, nil
}

// EncodeGrpcRespNodeList endodes the GRPC response
func EncodeGrpcRespNodeList(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}

// DecodeGrpcRespNodeList decodes the GRPC response
func DecodeGrpcRespNodeList(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}

func encodeHTTPNodeSpec(ctx context.Context, req *http.Request, request interface{}) error {
	return encodeHTTPRequest(ctx, req, request)
}

func decodeHTTPNodeSpec(_ context.Context, r *http.Request) (interface{}, error) {
	var req NodeSpec
	if e := json.NewDecoder(r.Body).Decode(&req); e != nil {
		return nil, e
	}
	return req, nil
}

// EncodeGrpcReqNodeSpec encodes GRPC request
func EncodeGrpcReqNodeSpec(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*NodeSpec)
	return req, nil
}

// DecodeGrpcReqNodeSpec decodes GRPC request
func DecodeGrpcReqNodeSpec(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*NodeSpec)
	return req, nil
}

// EncodeGrpcRespNodeSpec encodes GRC response
func EncodeGrpcRespNodeSpec(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}

// DecodeGrpcRespNodeSpec decodes GRPC response
func DecodeGrpcRespNodeSpec(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}

func encodeHTTPNodeStatus(ctx context.Context, req *http.Request, request interface{}) error {
	return encodeHTTPRequest(ctx, req, request)
}

func decodeHTTPNodeStatus(_ context.Context, r *http.Request) (interface{}, error) {
	var req NodeStatus
	if e := json.NewDecoder(r.Body).Decode(&req); e != nil {
		return nil, e
	}
	return req, nil
}

// EncodeGrpcReqNodeStatus encodes GRPC request
func EncodeGrpcReqNodeStatus(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*NodeStatus)
	return req, nil
}

// DecodeGrpcReqNodeStatus decodes GRPC request
func DecodeGrpcReqNodeStatus(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*NodeStatus)
	return req, nil
}

// EncodeGrpcRespNodeStatus encodes GRC response
func EncodeGrpcRespNodeStatus(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}

// DecodeGrpcRespNodeStatus decodes GRPC response
func DecodeGrpcRespNodeStatus(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}

func encodeHTTPPortCondition(ctx context.Context, req *http.Request, request interface{}) error {
	return encodeHTTPRequest(ctx, req, request)
}

func decodeHTTPPortCondition(_ context.Context, r *http.Request) (interface{}, error) {
	var req PortCondition
	if e := json.NewDecoder(r.Body).Decode(&req); e != nil {
		return nil, e
	}
	return req, nil
}

// EncodeGrpcReqPortCondition encodes GRPC request
func EncodeGrpcReqPortCondition(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*PortCondition)
	return req, nil
}

// DecodeGrpcReqPortCondition decodes GRPC request
func DecodeGrpcReqPortCondition(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*PortCondition)
	return req, nil
}

// EncodeGrpcRespPortCondition encodes GRC response
func EncodeGrpcRespPortCondition(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}

// DecodeGrpcRespPortCondition decodes GRPC response
func DecodeGrpcRespPortCondition(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}

func encodeHTTPPortSpec(ctx context.Context, req *http.Request, request interface{}) error {
	return encodeHTTPRequest(ctx, req, request)
}

func decodeHTTPPortSpec(_ context.Context, r *http.Request) (interface{}, error) {
	var req PortSpec
	if e := json.NewDecoder(r.Body).Decode(&req); e != nil {
		return nil, e
	}
	return req, nil
}

// EncodeGrpcReqPortSpec encodes GRPC request
func EncodeGrpcReqPortSpec(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*PortSpec)
	return req, nil
}

// DecodeGrpcReqPortSpec decodes GRPC request
func DecodeGrpcReqPortSpec(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*PortSpec)
	return req, nil
}

// EncodeGrpcRespPortSpec encodes GRC response
func EncodeGrpcRespPortSpec(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}

// DecodeGrpcRespPortSpec decodes GRPC response
func DecodeGrpcRespPortSpec(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}

func encodeHTTPPortStatus(ctx context.Context, req *http.Request, request interface{}) error {
	return encodeHTTPRequest(ctx, req, request)
}

func decodeHTTPPortStatus(_ context.Context, r *http.Request) (interface{}, error) {
	var req PortStatus
	if e := json.NewDecoder(r.Body).Decode(&req); e != nil {
		return nil, e
	}
	return req, nil
}

// EncodeGrpcReqPortStatus encodes GRPC request
func EncodeGrpcReqPortStatus(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*PortStatus)
	return req, nil
}

// DecodeGrpcReqPortStatus decodes GRPC request
func DecodeGrpcReqPortStatus(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*PortStatus)
	return req, nil
}

// EncodeGrpcRespPortStatus encodes GRC response
func EncodeGrpcRespPortStatus(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}

// DecodeGrpcRespPortStatus decodes GRPC response
func DecodeGrpcRespPortStatus(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}

func encodeHTTPSmartNIC(ctx context.Context, req *http.Request, request interface{}) error {
	return encodeHTTPRequest(ctx, req, request)
}

func decodeHTTPSmartNIC(_ context.Context, r *http.Request) (interface{}, error) {
	var req SmartNIC
	if e := json.NewDecoder(r.Body).Decode(&req); e != nil {
		return nil, e
	}
	return req, nil
}

// EncodeGrpcReqSmartNIC encodes GRPC request
func EncodeGrpcReqSmartNIC(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*SmartNIC)
	return req, nil
}

// DecodeGrpcReqSmartNIC decodes GRPC request
func DecodeGrpcReqSmartNIC(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*SmartNIC)
	return req, nil
}

// EncodeGrpcRespSmartNIC encodes GRC response
func EncodeGrpcRespSmartNIC(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}

// DecodeGrpcRespSmartNIC decodes GRPC response
func DecodeGrpcRespSmartNIC(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}

func encodeHTTPSmartNICCondition(ctx context.Context, req *http.Request, request interface{}) error {
	return encodeHTTPRequest(ctx, req, request)
}

func decodeHTTPSmartNICCondition(_ context.Context, r *http.Request) (interface{}, error) {
	var req SmartNICCondition
	if e := json.NewDecoder(r.Body).Decode(&req); e != nil {
		return nil, e
	}
	return req, nil
}

// EncodeGrpcReqSmartNICCondition encodes GRPC request
func EncodeGrpcReqSmartNICCondition(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*SmartNICCondition)
	return req, nil
}

// DecodeGrpcReqSmartNICCondition decodes GRPC request
func DecodeGrpcReqSmartNICCondition(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*SmartNICCondition)
	return req, nil
}

// EncodeGrpcRespSmartNICCondition encodes GRC response
func EncodeGrpcRespSmartNICCondition(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}

// DecodeGrpcRespSmartNICCondition decodes GRPC response
func DecodeGrpcRespSmartNICCondition(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}

func encodeHTTPSmartNICList(ctx context.Context, req *http.Request, request interface{}) error {
	return encodeHTTPRequest(ctx, req, request)
}

func decodeHTTPSmartNICList(_ context.Context, r *http.Request) (interface{}, error) {
	var req SmartNICList
	if e := json.NewDecoder(r.Body).Decode(&req); e != nil {
		return nil, e
	}
	return req, nil
}

// EncodeGrpcReqSmartNICList encodes GRPC request
func EncodeGrpcReqSmartNICList(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*SmartNICList)
	return req, nil
}

// DecodeGrpcReqSmartNICList decodes GRPC request
func DecodeGrpcReqSmartNICList(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*SmartNICList)
	return req, nil
}

// EncodeGrpcRespSmartNICList endodes the GRPC response
func EncodeGrpcRespSmartNICList(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}

// DecodeGrpcRespSmartNICList decodes the GRPC response
func DecodeGrpcRespSmartNICList(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}

func encodeHTTPSmartNICSpec(ctx context.Context, req *http.Request, request interface{}) error {
	return encodeHTTPRequest(ctx, req, request)
}

func decodeHTTPSmartNICSpec(_ context.Context, r *http.Request) (interface{}, error) {
	var req SmartNICSpec
	if e := json.NewDecoder(r.Body).Decode(&req); e != nil {
		return nil, e
	}
	return req, nil
}

// EncodeGrpcReqSmartNICSpec encodes GRPC request
func EncodeGrpcReqSmartNICSpec(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*SmartNICSpec)
	return req, nil
}

// DecodeGrpcReqSmartNICSpec decodes GRPC request
func DecodeGrpcReqSmartNICSpec(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*SmartNICSpec)
	return req, nil
}

// EncodeGrpcRespSmartNICSpec encodes GRC response
func EncodeGrpcRespSmartNICSpec(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}

// DecodeGrpcRespSmartNICSpec decodes GRPC response
func DecodeGrpcRespSmartNICSpec(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}

func encodeHTTPSmartNICStatus(ctx context.Context, req *http.Request, request interface{}) error {
	return encodeHTTPRequest(ctx, req, request)
}

func decodeHTTPSmartNICStatus(_ context.Context, r *http.Request) (interface{}, error) {
	var req SmartNICStatus
	if e := json.NewDecoder(r.Body).Decode(&req); e != nil {
		return nil, e
	}
	return req, nil
}

// EncodeGrpcReqSmartNICStatus encodes GRPC request
func EncodeGrpcReqSmartNICStatus(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*SmartNICStatus)
	return req, nil
}

// DecodeGrpcReqSmartNICStatus decodes GRPC request
func DecodeGrpcReqSmartNICStatus(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*SmartNICStatus)
	return req, nil
}

// EncodeGrpcRespSmartNICStatus encodes GRC response
func EncodeGrpcRespSmartNICStatus(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}

// DecodeGrpcRespSmartNICStatus decodes GRPC response
func DecodeGrpcRespSmartNICStatus(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}
