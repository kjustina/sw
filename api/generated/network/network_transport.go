// Code generated by protoc-gen-grpc-pensando DO NOT EDIT.

/*
Package network is a auto generated package.
Input file: network.proto
*/
package network

import (
	"context"
	"encoding/json"
	"net/http"

	"github.com/pensando/sw/api"
)

// Dummy definitions to suppress nonused warnings
var _ api.ObjectMeta

func encodeHTTPNetwork(ctx context.Context, req *http.Request, request interface{}) error {
	return encodeHTTPRequest(ctx, req, request)
}

func decodeHTTPNetwork(_ context.Context, r *http.Request) (interface{}, error) {
	var req Network
	if e := json.NewDecoder(r.Body).Decode(&req); e != nil {
		return nil, e
	}
	return req, nil
}

// EncodeGrpcReqNetwork encodes GRPC request
func EncodeGrpcReqNetwork(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*Network)
	return req, nil
}

// DecodeGrpcReqNetwork decodes GRPC request
func DecodeGrpcReqNetwork(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*Network)
	return req, nil
}

// EncodeGrpcRespNetwork encodes GRC response
func EncodeGrpcRespNetwork(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}

// DecodeGrpcRespNetwork decodes GRPC response
func DecodeGrpcRespNetwork(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}

func encodeHTTPNetworkSpec(ctx context.Context, req *http.Request, request interface{}) error {
	return encodeHTTPRequest(ctx, req, request)
}

func decodeHTTPNetworkSpec(_ context.Context, r *http.Request) (interface{}, error) {
	var req NetworkSpec
	if e := json.NewDecoder(r.Body).Decode(&req); e != nil {
		return nil, e
	}
	return req, nil
}

// EncodeGrpcReqNetworkSpec encodes GRPC request
func EncodeGrpcReqNetworkSpec(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*NetworkSpec)
	return req, nil
}

// DecodeGrpcReqNetworkSpec decodes GRPC request
func DecodeGrpcReqNetworkSpec(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*NetworkSpec)
	return req, nil
}

// EncodeGrpcRespNetworkSpec encodes GRC response
func EncodeGrpcRespNetworkSpec(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}

// DecodeGrpcRespNetworkSpec decodes GRPC response
func DecodeGrpcRespNetworkSpec(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}

func encodeHTTPNetworkStatus(ctx context.Context, req *http.Request, request interface{}) error {
	return encodeHTTPRequest(ctx, req, request)
}

func decodeHTTPNetworkStatus(_ context.Context, r *http.Request) (interface{}, error) {
	var req NetworkStatus
	if e := json.NewDecoder(r.Body).Decode(&req); e != nil {
		return nil, e
	}
	return req, nil
}

// EncodeGrpcReqNetworkStatus encodes GRPC request
func EncodeGrpcReqNetworkStatus(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*NetworkStatus)
	return req, nil
}

// DecodeGrpcReqNetworkStatus decodes GRPC request
func DecodeGrpcReqNetworkStatus(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*NetworkStatus)
	return req, nil
}

// EncodeGrpcRespNetworkStatus encodes GRC response
func EncodeGrpcRespNetworkStatus(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}

// DecodeGrpcRespNetworkStatus decodes GRPC response
func DecodeGrpcRespNetworkStatus(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}
