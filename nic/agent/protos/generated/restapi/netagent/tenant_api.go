// Code generated by protoc-gen-grpc-pensando DO NOT EDIT.

/*
Package netproto is a auto generated package.
Input file: tenant.proto
*/
package restapi

import (
	"encoding/json"
	"fmt"
	"io/ioutil"
	"net/http"
	"time"

	"github.com/gogo/protobuf/types"
	"github.com/gorilla/mux"

	"github.com/pensando/sw/api"
	"github.com/pensando/sw/nic/agent/httputils"
	agentTypes "github.com/pensando/sw/nic/agent/netagent/state/types"
	"github.com/pensando/sw/nic/agent/protos/netproto"
)

// AddTenantAPIRoutes adds Tenant routes
func (s *RestServer) AddTenantAPIRoutes(r *mux.Router) {

	r.Methods("GET").Subrouter().HandleFunc("/", httputils.MakeHTTPHandler(s.listTenantHandler))

	r.Methods("POST").Subrouter().HandleFunc("/", httputils.MakeHTTPHandler(s.postTenantHandler))

	r.Methods("DELETE").Subrouter().HandleFunc("/{ObjectMeta.Name}", httputils.MakeHTTPHandler(s.deleteTenantHandler))

	r.Methods("PUT").Subrouter().HandleFunc("/{ObjectMeta.Name}", httputils.MakeHTTPHandler(s.putTenantHandler))

}

func (s *RestServer) listTenantHandler(r *http.Request) (interface{}, error) {
	return s.agent.ListTenant(), nil
}

func (s *RestServer) postTenantHandler(r *http.Request) (interface{}, error) {
	var res Response

	var o netproto.Tenant
	b, _ := ioutil.ReadAll(r.Body)
	err := json.Unmarshal(b, &o)
	if err != nil {
		return nil, err
	}
	c, _ := types.TimestampProto(time.Now())
	o.CreationTime = api.Timestamp{
		Timestamp: *c,
	}
	o.ModTime = api.Timestamp{
		Timestamp: *c,
	}

	err = s.agent.CreateTenant(&o)

	res.References = []string{fmt.Sprintf("%s%s", r.RequestURI, o.Name)}

	if err != nil {
		res.StatusCode = http.StatusInternalServerError
		res.Error = err.Error()

		return res, err
	}

	res.StatusCode = http.StatusOK
	return res, err
}

func (s *RestServer) deleteTenantHandler(r *http.Request) (interface{}, error) {
	var res Response

	name, _ := mux.Vars(r)["ObjectMeta.Name"]
	err := s.agent.DeleteTenant(name, name, name)

	res.References = []string{r.RequestURI}

	if err != nil {
		res.StatusCode = http.StatusInternalServerError
		res.Error = err.Error()

		// check if its a cannot delete type err
		delErr, ok := err.(*agentTypes.ErrCannotDelete)
		if ok {
			res.References = delErr.References
		}

		return res, err
	}

	res.StatusCode = http.StatusOK
	return res, err
}

func (s *RestServer) putTenantHandler(r *http.Request) (interface{}, error) {
	var res Response

	var o netproto.Tenant
	b, _ := ioutil.ReadAll(r.Body)
	err := json.Unmarshal(b, &o)
	if err != nil {
		return nil, err
	}
	m, _ := types.TimestampProto(time.Now())
	o.ModTime = api.Timestamp{
		Timestamp: *m,
	}
	err = s.agent.UpdateTenant(&o)

	res.References = []string{r.RequestURI}

	if err != nil {
		res.StatusCode = http.StatusInternalServerError
		res.Error = err.Error()

		return res, err
	}

	res.StatusCode = http.StatusOK
	return res, err
}
