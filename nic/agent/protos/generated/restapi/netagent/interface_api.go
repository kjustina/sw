// Code generated by protoc-gen-grpc-pensando DO NOT EDIT.

/*
Package netproto is a auto generated package.
Input file: interface.proto
*/
package restapi

import (
	"net/http"

	"github.com/gorilla/mux"

	"github.com/pensando/sw/api"
	"github.com/pensando/sw/nic/agent/dscagent/types"
	"github.com/pensando/sw/nic/agent/httputils"
	"github.com/pensando/sw/nic/agent/protos/netproto"
)

// AddInterfaceAPIRoutes adds Interface routes
func (s *RestServer) AddInterfaceAPIRoutes(r *mux.Router) {

	r.Methods("GET").Subrouter().HandleFunc("/", httputils.MakeHTTPHandler(s.listInterfaceHandler))

}

func (s *RestServer) listInterfaceHandler(r *http.Request) (interface{}, error) {
	o := netproto.Interface{
		TypeMeta: api.TypeMeta{Kind: "Interface"},
	}

	return s.pipelineAPI.HandleInterface(types.List, o)
}
