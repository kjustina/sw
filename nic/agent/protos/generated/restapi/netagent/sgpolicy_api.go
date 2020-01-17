// Code generated by protoc-gen-grpc-pensando DO NOT EDIT.

/*
Package netproto is a auto generated package.
Input file: sgpolicy.proto
*/
package restapi

import (
	"encoding/json"
	"io/ioutil"
	"net/http"
	"time"

	protoTypes "github.com/gogo/protobuf/types"
	"github.com/gorilla/mux"

	"github.com/pensando/sw/api"
	"github.com/pensando/sw/nic/agent/dscagent/types"
	"github.com/pensando/sw/nic/agent/httputils"
	"github.com/pensando/sw/nic/agent/protos/netproto"
)

// AddNetworkSecurityPolicyAPIRoutes adds NetworkSecurityPolicy routes
func (s *RestServer) AddNetworkSecurityPolicyAPIRoutes(r *mux.Router) {

	r.Methods("GET").Subrouter().HandleFunc("/", httputils.MakeHTTPHandler(s.listNetworkSecurityPolicyHandler))

	r.Methods("GET").Subrouter().HandleFunc("/{ObjectMeta.Tenant}/{ObjectMeta.Namespace}/{ObjectMeta.Name}", httputils.MakeHTTPHandler(s.getNetworkSecurityPolicyHandler))

	r.Methods("POST").Subrouter().HandleFunc("/", httputils.MakeHTTPHandler(s.postNetworkSecurityPolicyHandler))

	r.Methods("DELETE").Subrouter().HandleFunc("/{ObjectMeta.Tenant}/{ObjectMeta.Namespace}/{ObjectMeta.Name}", httputils.MakeHTTPHandler(s.deleteNetworkSecurityPolicyHandler))

	r.Methods("PUT").Subrouter().HandleFunc("/{ObjectMeta.Tenant}/{ObjectMeta.Namespace}/{ObjectMeta.Name}", httputils.MakeHTTPHandler(s.putNetworkSecurityPolicyHandler))

}

func (s *RestServer) listNetworkSecurityPolicyHandler(r *http.Request) (interface{}, error) {
	o := netproto.NetworkSecurityPolicy{
		TypeMeta: api.TypeMeta{Kind: "NetworkSecurityPolicy"},
	}

	return s.pipelineAPI.HandleNetworkSecurityPolicy(types.List, o)
}

func (s *RestServer) getNetworkSecurityPolicyHandler(r *http.Request) (interface{}, error) {
	tenant, _ := mux.Vars(r)["ObjectMeta.Tenant"]
	namespace, _ := mux.Vars(r)["ObjectMeta.Namespace"]
	name, _ := mux.Vars(r)["ObjectMeta.Name"]
	o := netproto.NetworkSecurityPolicy{
		TypeMeta: api.TypeMeta{Kind: "NetworkSecurityPolicy"},
		ObjectMeta: api.ObjectMeta{
			Tenant:    tenant,
			Namespace: namespace,
			Name:      name,
		},
	}

	data, err := s.pipelineAPI.HandleNetworkSecurityPolicy(types.Get, o)
	if err != nil {
		return Response{
			StatusCode: http.StatusInternalServerError,
		}, err
	}
	return data, nil

}

func (s *RestServer) postNetworkSecurityPolicyHandler(r *http.Request) (interface{}, error) {
	var o netproto.NetworkSecurityPolicy
	b, _ := ioutil.ReadAll(r.Body)
	err := json.Unmarshal(b, &o)
	if err != nil {
		return nil, err
	}
	c, _ := protoTypes.TimestampProto(time.Now())
	o.CreationTime = api.Timestamp{
		Timestamp: *c,
	}
	o.ModTime = api.Timestamp{
		Timestamp: *c,
	}

	_, err = s.pipelineAPI.HandleNetworkSecurityPolicy(types.Create, o)

	if err != nil {
		return Response{
			StatusCode: http.StatusInternalServerError,
		}, err
	}
	return Response{
		StatusCode: http.StatusOK,
	}, nil
}

func (s *RestServer) deleteNetworkSecurityPolicyHandler(r *http.Request) (interface{}, error) {
	tenant, _ := mux.Vars(r)["ObjectMeta.Tenant"]
	namespace, _ := mux.Vars(r)["ObjectMeta.Namespace"]
	name, _ := mux.Vars(r)["ObjectMeta.Name"]
	o := netproto.NetworkSecurityPolicy{
		TypeMeta: api.TypeMeta{Kind: "NetworkSecurityPolicy"},
		ObjectMeta: api.ObjectMeta{
			Tenant:    tenant,
			Namespace: namespace,
			Name:      name,
		},
	}

	_, err := s.pipelineAPI.HandleNetworkSecurityPolicy(types.Delete, o)
	if err != nil {
		return Response{
			StatusCode: http.StatusInternalServerError,
		}, err
	}
	return Response{
		StatusCode: http.StatusOK,
	}, nil
}

func (s *RestServer) putNetworkSecurityPolicyHandler(r *http.Request) (interface{}, error) {
	var o netproto.NetworkSecurityPolicy
	b, _ := ioutil.ReadAll(r.Body)
	err := json.Unmarshal(b, &o)
	if err != nil {
		return nil, err
	}
	c, _ := protoTypes.TimestampProto(time.Now())
	o.CreationTime = api.Timestamp{
		Timestamp: *c,
	}
	o.ModTime = api.Timestamp{
		Timestamp: *c,
	}

	_, err = s.pipelineAPI.HandleNetworkSecurityPolicy(types.Update, o)
	if err != nil {
		return Response{
			StatusCode: http.StatusInternalServerError,
		}, err
	}
	return Response{
		StatusCode: http.StatusOK,
	}, nil
}
