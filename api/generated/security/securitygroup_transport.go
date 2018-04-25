// Code generated by protoc-gen-grpc-pensando DO NOT EDIT.

/*
Package security is a auto generated package.
Input file: securitygroup.proto
*/
package security

import (
	"context"
	"encoding/json"
	"net/http"

	"github.com/pensando/sw/api"
)

// Dummy definitions to suppress nonused warnings
var _ api.ObjectMeta

func encodeHTTPSecurityGroup(ctx context.Context, req *http.Request, request interface{}) error {
	return encodeHTTPRequest(ctx, req, request)
}

func decodeHTTPSecurityGroup(_ context.Context, r *http.Request) (interface{}, error) {
	var req SecurityGroup
	if e := json.NewDecoder(r.Body).Decode(&req); e != nil {
		return nil, e
	}
	return req, nil
}

// EncodeGrpcReqSecurityGroup encodes GRPC request
func EncodeGrpcReqSecurityGroup(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*SecurityGroup)
	return req, nil
}

// DecodeGrpcReqSecurityGroup decodes GRPC request
func DecodeGrpcReqSecurityGroup(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*SecurityGroup)
	return req, nil
}

// EncodeGrpcRespSecurityGroup encodes GRC response
func EncodeGrpcRespSecurityGroup(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}

// DecodeGrpcRespSecurityGroup decodes GRPC response
func DecodeGrpcRespSecurityGroup(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}

func encodeHTTPSecurityGroupSpec(ctx context.Context, req *http.Request, request interface{}) error {
	return encodeHTTPRequest(ctx, req, request)
}

func decodeHTTPSecurityGroupSpec(_ context.Context, r *http.Request) (interface{}, error) {
	var req SecurityGroupSpec
	if e := json.NewDecoder(r.Body).Decode(&req); e != nil {
		return nil, e
	}
	return req, nil
}

// EncodeGrpcReqSecurityGroupSpec encodes GRPC request
func EncodeGrpcReqSecurityGroupSpec(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*SecurityGroupSpec)
	return req, nil
}

// DecodeGrpcReqSecurityGroupSpec decodes GRPC request
func DecodeGrpcReqSecurityGroupSpec(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*SecurityGroupSpec)
	return req, nil
}

// EncodeGrpcRespSecurityGroupSpec encodes GRC response
func EncodeGrpcRespSecurityGroupSpec(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}

// DecodeGrpcRespSecurityGroupSpec decodes GRPC response
func DecodeGrpcRespSecurityGroupSpec(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}

func encodeHTTPSecurityGroupStatus(ctx context.Context, req *http.Request, request interface{}) error {
	return encodeHTTPRequest(ctx, req, request)
}

func decodeHTTPSecurityGroupStatus(_ context.Context, r *http.Request) (interface{}, error) {
	var req SecurityGroupStatus
	if e := json.NewDecoder(r.Body).Decode(&req); e != nil {
		return nil, e
	}
	return req, nil
}

// EncodeGrpcReqSecurityGroupStatus encodes GRPC request
func EncodeGrpcReqSecurityGroupStatus(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*SecurityGroupStatus)
	return req, nil
}

// DecodeGrpcReqSecurityGroupStatus decodes GRPC request
func DecodeGrpcReqSecurityGroupStatus(ctx context.Context, request interface{}) (interface{}, error) {
	req := request.(*SecurityGroupStatus)
	return req, nil
}

// EncodeGrpcRespSecurityGroupStatus encodes GRC response
func EncodeGrpcRespSecurityGroupStatus(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}

// DecodeGrpcRespSecurityGroupStatus decodes GRPC response
func DecodeGrpcRespSecurityGroupStatus(ctx context.Context, response interface{}) (interface{}, error) {
	return response, nil
}
