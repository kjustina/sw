// Code generated by protoc-gen-grpc-pensando DO NOT EDIT.

/*
Package netproto is a auto generated package.
Input file: nat.proto
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

// addNatPolicyAPIRoutes adds NatPolicy routes
func addNatPolicyAPIRoutes(r *mux.Router, srv *RestServer) {

	r.Methods("GET").Subrouter().HandleFunc("/", httputils.MakeHTTPHandler(srv.natpolicyListHandler))

	r.Methods("POST").Subrouter().HandleFunc("/", httputils.MakeHTTPHandler(srv.natpolicyPostHandler))

	r.Methods("PUT").Subrouter().HandleFunc("/{ObjectMeta.Tenant}/{ObjectMeta.NameSpace}/{ObjectMeta.Name}", httputils.MakeHTTPHandler(srv.natpolicyPutHandler))

	r.Methods("DELETE").Subrouter().HandleFunc("/{ObjectMeta.Tenant}/{ObjectMeta.NameSpace}/{ObjectMeta.Name}", httputils.MakeHTTPHandler(srv.natpolicyDeleteHandler))

}

func (s *RestServer) natpolicyListHandler(r *http.Request) (interface{}, error) {
	return s.agent.ListNatPolicy(), nil
}

func (s *RestServer) natpolicyPostHandler(r *http.Request) (interface{}, error) {
	var o netproto.NatPolicy
	b, _ := ioutil.ReadAll(r.Body)
	err := json.Unmarshal(b, &o)
	if err != nil {
		return nil, err
	}

	return nil, s.agent.CreateNatPolicy(&o)

}

func (s *RestServer) natpolicyPutHandler(r *http.Request) (interface{}, error) {
	var o netproto.NatPolicy
	b, _ := ioutil.ReadAll(r.Body)
	err := json.Unmarshal(b, &o)
	if err != nil {
		return nil, err
	}

	return nil, s.agent.UpdateNatPolicy(&o)

}

func (s *RestServer) natpolicyDeleteHandler(r *http.Request) (interface{}, error) {
	var o netproto.NatPolicy
	b, _ := ioutil.ReadAll(r.Body)
	err := json.Unmarshal(b, &o)
	if err != nil {
		return nil, err
	}

	return nil, s.agent.DeleteNatPolicy(&o)

}

// addNatPoolAPIRoutes adds NatPool routes
func addNatPoolAPIRoutes(r *mux.Router, srv *RestServer) {

	r.Methods("GET").Subrouter().HandleFunc("/", httputils.MakeHTTPHandler(srv.natpoolListHandler))

	r.Methods("POST").Subrouter().HandleFunc("/", httputils.MakeHTTPHandler(srv.natpoolPostHandler))

	r.Methods("PUT").Subrouter().HandleFunc("/{ObjectMeta.Tenant}/{ObjectMeta.NameSpace}/{ObjectMeta.Name}", httputils.MakeHTTPHandler(srv.natpoolPutHandler))

	r.Methods("DELETE").Subrouter().HandleFunc("/{ObjectMeta.Tenant}/{ObjectMeta.NameSpace}/{ObjectMeta.Name}", httputils.MakeHTTPHandler(srv.natpoolDeleteHandler))

}

func (s *RestServer) natpoolListHandler(r *http.Request) (interface{}, error) {
	return s.agent.ListNatPool(), nil
}

func (s *RestServer) natpoolPostHandler(r *http.Request) (interface{}, error) {
	var o netproto.NatPool
	b, _ := ioutil.ReadAll(r.Body)
	err := json.Unmarshal(b, &o)
	if err != nil {
		return nil, err
	}

	return nil, s.agent.CreateNatPool(&o)

}

func (s *RestServer) natpoolPutHandler(r *http.Request) (interface{}, error) {
	var o netproto.NatPool
	b, _ := ioutil.ReadAll(r.Body)
	err := json.Unmarshal(b, &o)
	if err != nil {
		return nil, err
	}

	return nil, s.agent.UpdateNatPool(&o)

}

func (s *RestServer) natpoolDeleteHandler(r *http.Request) (interface{}, error) {
	var o netproto.NatPool
	b, _ := ioutil.ReadAll(r.Body)
	err := json.Unmarshal(b, &o)
	if err != nil {
		return nil, err
	}

	return nil, s.agent.DeleteNatPool(&o)

}
