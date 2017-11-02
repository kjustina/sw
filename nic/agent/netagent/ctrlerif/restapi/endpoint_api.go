// Code generated by protoc-gen-grpc-pensando DO NOT EDIT.

/*
Package netproto is a auto generated package.
Input file: endpoint.proto
*/
package restapi

import (
	"encoding/json"
	"io/ioutil"
	"net/http"

	"github.com/gorilla/mux"

	"github.com/pensando/sw/nic/agent/httputils"
	"github.com/pensando/sw/venice/ctrler/npm/rpcserver/netproto"
)

// addEndpointAPIRoutes adds Endpoint routes
func addEndpointAPIRoutes(r *mux.Router, srv *RestServer) {

	r.Methods("GET").Subrouter().HandleFunc("/", httputils.MakeHTTPHandler(srv.endpointListHandler))

	r.Methods("POST").Subrouter().HandleFunc("/", httputils.MakeHTTPHandler(srv.endpointPostHandler))

	r.Methods("PUT").Subrouter().HandleFunc("/{ObjectMeta.Tenant}/{ObjectMeta.Name}", httputils.MakeHTTPHandler(srv.endpointPutHandler))

	r.Methods("DELETE").Subrouter().HandleFunc("/{ObjectMeta.Tenant}/{ObjectMeta.Name}", httputils.MakeHTTPHandler(srv.endpointDeleteHandler))

}

func (s *RestServer) endpointListHandler(r *http.Request) (interface{}, error) {
	return s.agent.ListEndpoint(), nil
}

func (s *RestServer) endpointPostHandler(r *http.Request) (interface{}, error) {
	var o netproto.Endpoint
	b, _ := ioutil.ReadAll(r.Body)
	err := json.Unmarshal(b, &o)
	if err != nil {
		return nil, err
	}
	_, err = s.agent.CreateEndpoint(&o)
	return nil, err
}

func (s *RestServer) endpointPutHandler(r *http.Request) (interface{}, error) {
	var o netproto.Endpoint
	b, _ := ioutil.ReadAll(r.Body)
	err := json.Unmarshal(b, &o)
	if err != nil {
		return nil, err
	}

	return nil, s.agent.UpdateEndpoint(&o)

}

func (s *RestServer) endpointDeleteHandler(r *http.Request) (interface{}, error) {
	var o netproto.Endpoint
	b, _ := ioutil.ReadAll(r.Body)
	err := json.Unmarshal(b, &o)
	if err != nil {
		return nil, err
	}

	return nil, s.agent.DeleteEndpoint(&o)

}
