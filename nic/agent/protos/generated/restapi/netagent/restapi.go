// Code generated by protoc-gen-grpc-pensando DO NOT EDIT.

/*
Package netproto is a auto generated package.
*/
package restapi

import (
	"github.com/pensando/sw/nic/agent/dscagent/types"
)

// this package contains the REST API provided by the agent

// RestServer is the REST api server
type RestServer struct {
	listenURL   string            // URL where http server is listening
	pipelineAPI types.PipelineAPI // net Agent API
}

// Response captures the HTTP Response sent by Agent REST Server
type Response struct {
	StatusCode int      `json:"status-code,omitempty"`
	Error      string   `json:"error,omitempty"`
	References []string `json:"references,omitempty"`
}

// MakeErrorResponse generates error response for MakeHTTPHandler() API
func MakeErrorResponse(code int, err error) (*Response, error) {
	res := &Response{
		StatusCode: code,
	}

	if err != nil {
		res.Error = err.Error()
	}

	return res, err
}

// NewRestServer creates a new HTTP server servicg REST api
func NewRestServer(pipelineAPI types.PipelineAPI, listenURL string) (*RestServer, error) {
	// create server instance
	srv := RestServer{
		listenURL:   listenURL,
		pipelineAPI: pipelineAPI,
	}

	return &srv, nil
}
