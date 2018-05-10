// Code generated by protoc-gen-grpc-pensando DO NOT EDIT.

/*
Package netproto is a auto generated package.
Input file: security.proto
*/
package restapi

import (
	"encoding/json"
	"fmt"
	"io/ioutil"
	"net/http"

	"github.com/gorilla/mux"

	"github.com/pensando/sw/nic/agent/httputils"
	"github.com/pensando/sw/venice/ctrler/npm/rpcserver/netproto"
)

// addSecurityGroupAPIRoutes adds SecurityGroup routes
func addSecurityGroupAPIRoutes(r *mux.Router, srv *RestServer) {

	r.Methods("GET").Subrouter().HandleFunc("/", httputils.MakeHTTPHandler(srv.listSecurityGroupHandler))

	r.Methods("POST").Subrouter().HandleFunc("/", httputils.MakeHTTPHandler(srv.postSecurityGroupHandler))

	r.Methods("PUT").Subrouter().HandleFunc("/{ObjectMeta.Tenant}/{ObjectMeta.Namespace}/{ObjectMeta.Name}", httputils.MakeHTTPHandler(srv.putSecurityGroupHandler))

	r.Methods("DELETE").Subrouter().HandleFunc("/{ObjectMeta.Tenant}/{ObjectMeta.Namespace}/{ObjectMeta.Name}", httputils.MakeHTTPHandler(srv.deleteSecurityGroupHandler))

}

func (s *RestServer) listSecurityGroupHandler(r *http.Request) (interface{}, error) {
	return s.agent.ListSecurityGroup(), nil
}

func (s *RestServer) postSecurityGroupHandler(r *http.Request) (interface{}, error) {
	var res Response
	var o netproto.SecurityGroup
	b, _ := ioutil.ReadAll(r.Body)
	err := json.Unmarshal(b, &o)
	if err != nil {
		return nil, err
	}

	err = s.agent.CreateSecurityGroup(&o)

	if err != nil {
		res.StatusCode = http.StatusInternalServerError
		res.Error = err.Error()
		return res, err
	}

	res.SelfLink = fmt.Sprintf("%s%s/%s/%s", r.RequestURI, o.Tenant, o.Namespace, o.Name)

	res.StatusCode = http.StatusOK
	return res, err
}

func (s *RestServer) putSecurityGroupHandler(r *http.Request) (interface{}, error) {
	var res Response
	var o netproto.SecurityGroup
	b, _ := ioutil.ReadAll(r.Body)
	err := json.Unmarshal(b, &o)
	if err != nil {
		return nil, err
	}

	err = s.agent.UpdateSecurityGroup(&o)

	if err != nil {
		res.StatusCode = http.StatusInternalServerError
		res.Error = err.Error()
		return res, err
	}

	res.SelfLink = r.RequestURI

	res.StatusCode = http.StatusOK
	return res, err
}

func (s *RestServer) deleteSecurityGroupHandler(r *http.Request) (interface{}, error) {
	var res Response
	var o netproto.SecurityGroup
	b, _ := ioutil.ReadAll(r.Body)
	err := json.Unmarshal(b, &o)
	if err != nil {
		return nil, err
	}

	err = s.agent.DeleteSecurityGroup(&o)

	if err != nil {
		res.StatusCode = http.StatusInternalServerError
		res.Error = err.Error()
		return res, err
	}

	res.SelfLink = r.RequestURI

	res.StatusCode = http.StatusOK
	return res, err
}
