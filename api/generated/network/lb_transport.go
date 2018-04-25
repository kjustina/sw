// Code generated by protoc-gen-grpc-pensando DO NOT EDIT.

/*
Package network is a auto generated package.
Input file: lb.proto
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

func encodeHTTPHealthCheckSpec(ctx context.Context, req *http.Request, request interface{}) error {
	return encodeHTTPRequest(ctx, req, request)
}

func decodeHTTPHealthCheckSpec(_ context.Context, r *http.Request) (interface{}, error) {
	var req HealthCheckSpec
	if e := json.NewDecoder(r.Body).Decode(&req); e != nil {
		return nil, e
	}
	return req, nil
}

// EncodeGrpcReqHealthCheckSpec encodes GRPC request
func EncodeGrpcReqHealthCheckSpec(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*HealthCheckSpec)
	return req, nil
}

// DecodeGrpcReqHealthCheckSpec decodes GRPC request
func DecodeGrpcReqHealthCheckSpec(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*HealthCheckSpec)
	return req, nil
}

// EncodeGrpcRespHealthCheckSpec encodes GRC response
func EncodeGrpcRespHealthCheckSpec(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}

// DecodeGrpcRespHealthCheckSpec decodes GRPC response
func DecodeGrpcRespHealthCheckSpec(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}

func encodeHTTPLbPolicy(ctx context.Context, req *http.Request, request interface{}) error {
	return encodeHTTPRequest(ctx, req, request)
}

func decodeHTTPLbPolicy(_ context.Context, r *http.Request) (interface{}, error) {
	var req LbPolicy
	if e := json.NewDecoder(r.Body).Decode(&req); e != nil {
		return nil, e
	}
	return req, nil
}

// EncodeGrpcReqLbPolicy encodes GRPC request
func EncodeGrpcReqLbPolicy(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*LbPolicy)
	return req, nil
}

// DecodeGrpcReqLbPolicy decodes GRPC request
func DecodeGrpcReqLbPolicy(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*LbPolicy)
	return req, nil
}

// EncodeGrpcRespLbPolicy encodes GRC response
func EncodeGrpcRespLbPolicy(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}

// DecodeGrpcRespLbPolicy decodes GRPC response
func DecodeGrpcRespLbPolicy(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}

func encodeHTTPLbPolicySpec(ctx context.Context, req *http.Request, request interface{}) error {
	return encodeHTTPRequest(ctx, req, request)
}

func decodeHTTPLbPolicySpec(_ context.Context, r *http.Request) (interface{}, error) {
	var req LbPolicySpec
	if e := json.NewDecoder(r.Body).Decode(&req); e != nil {
		return nil, e
	}
	return req, nil
}

// EncodeGrpcReqLbPolicySpec encodes GRPC request
func EncodeGrpcReqLbPolicySpec(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*LbPolicySpec)
	return req, nil
}

// DecodeGrpcReqLbPolicySpec decodes GRPC request
func DecodeGrpcReqLbPolicySpec(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*LbPolicySpec)
	return req, nil
}

// EncodeGrpcRespLbPolicySpec encodes GRC response
func EncodeGrpcRespLbPolicySpec(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}

// DecodeGrpcRespLbPolicySpec decodes GRPC response
func DecodeGrpcRespLbPolicySpec(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}

func encodeHTTPLbPolicyStatus(ctx context.Context, req *http.Request, request interface{}) error {
	return encodeHTTPRequest(ctx, req, request)
}

func decodeHTTPLbPolicyStatus(_ context.Context, r *http.Request) (interface{}, error) {
	var req LbPolicyStatus
	if e := json.NewDecoder(r.Body).Decode(&req); e != nil {
		return nil, e
	}
	return req, nil
}

// EncodeGrpcReqLbPolicyStatus encodes GRPC request
func EncodeGrpcReqLbPolicyStatus(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*LbPolicyStatus)
	return req, nil
}

// DecodeGrpcReqLbPolicyStatus decodes GRPC request
func DecodeGrpcReqLbPolicyStatus(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*LbPolicyStatus)
	return req, nil
}

// EncodeGrpcRespLbPolicyStatus encodes GRC response
func EncodeGrpcRespLbPolicyStatus(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}

// DecodeGrpcRespLbPolicyStatus decodes GRPC response
func DecodeGrpcRespLbPolicyStatus(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}
