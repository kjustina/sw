// Code generated by protoc-gen-grpc-pensando DO NOT EDIT.

/*
Package netproto is a auto generated package.
Input file: mirror.proto
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

// AddMirrorSessionAPIRoutes adds MirrorSession routes
func (s *RestServer) AddMirrorSessionAPIRoutes(r *mux.Router) {

	r.Methods("GET").Subrouter().HandleFunc("/", httputils.MakeHTTPHandler(s.listMirrorSessionHandler))

	r.Methods("GET").Subrouter().HandleFunc("/{ObjectMeta.Tenant}/{ObjectMeta.Namespace}/{ObjectMeta.Name}", httputils.MakeHTTPHandler(s.getMirrorSessionHandler))

	r.Methods("POST").Subrouter().HandleFunc("/", httputils.MakeHTTPHandler(s.postMirrorSessionHandler))

	r.Methods("DELETE").Subrouter().HandleFunc("/{ObjectMeta.Tenant}/{ObjectMeta.Namespace}/{ObjectMeta.Name}", httputils.MakeHTTPHandler(s.deleteMirrorSessionHandler))

	r.Methods("PUT").Subrouter().HandleFunc("/{ObjectMeta.Tenant}/{ObjectMeta.Namespace}/{ObjectMeta.Name}", httputils.MakeHTTPHandler(s.putMirrorSessionHandler))

}

func (s *RestServer) listMirrorSessionHandler(r *http.Request) (interface{}, error) {
	o := netproto.MirrorSession{
		TypeMeta: api.TypeMeta{Kind: "MirrorSession"},
	}

	return s.pipelineAPI.HandleMirrorSession(types.List, o)
}

func (s *RestServer) getMirrorSessionHandler(r *http.Request) (interface{}, error) {
	tenant, _ := mux.Vars(r)["ObjectMeta.Tenant"]
	namespace, _ := mux.Vars(r)["ObjectMeta.Namespace"]
	name, _ := mux.Vars(r)["ObjectMeta.Name"]
	o := netproto.MirrorSession{
		TypeMeta: api.TypeMeta{Kind: "MirrorSession"},
		ObjectMeta: api.ObjectMeta{
			Tenant:    tenant,
			Namespace: namespace,
			Name:      name,
		},
	}

	data, err := s.pipelineAPI.HandleMirrorSession(types.Get, o)
	if err != nil {
		return Response{
			StatusCode: http.StatusInternalServerError,
		}, err
	}
	return data, nil

}

func (s *RestServer) postMirrorSessionHandler(r *http.Request) (interface{}, error) {
	var o netproto.MirrorSession
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

	_, err = s.pipelineAPI.HandleMirrorSession(types.Create, o)

	if err != nil {
		return Response{
			StatusCode: http.StatusInternalServerError,
		}, err
	}
	return Response{
		StatusCode: http.StatusOK,
	}, nil
}

func (s *RestServer) deleteMirrorSessionHandler(r *http.Request) (interface{}, error) {
	tenant, _ := mux.Vars(r)["ObjectMeta.Tenant"]
	namespace, _ := mux.Vars(r)["ObjectMeta.Namespace"]
	name, _ := mux.Vars(r)["ObjectMeta.Name"]
	o := netproto.MirrorSession{
		TypeMeta: api.TypeMeta{Kind: "MirrorSession"},
		ObjectMeta: api.ObjectMeta{
			Tenant:    tenant,
			Namespace: namespace,
			Name:      name,
		},
	}

	_, err := s.pipelineAPI.HandleMirrorSession(types.Delete, o)
	if err != nil {
		return Response{
			StatusCode: http.StatusInternalServerError,
		}, err
	}
	return Response{
		StatusCode: http.StatusOK,
	}, nil
}

func (s *RestServer) putMirrorSessionHandler(r *http.Request) (interface{}, error) {
	var o netproto.MirrorSession
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

	_, err = s.pipelineAPI.HandleMirrorSession(types.Update, o)
	if err != nil {
		return Response{
			StatusCode: http.StatusInternalServerError,
		}, err
	}
	return Response{
		StatusCode: http.StatusOK,
	}, nil
}
