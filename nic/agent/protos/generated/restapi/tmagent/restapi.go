// Code generated by protoc-gen-grpc-pensando DO NOT EDIT.

/*
This is a auto generated package.
*/
package restapi

import (
	"sync"

	"github.com/gorilla/mux"

	"github.com/pensando/sw/api"
	tpa "github.com/pensando/sw/nic/agent/tpa/state/types"
	"github.com/pensando/sw/venice/globals"
	"github.com/pensando/sw/venice/utils/ntranslate"
	"github.com/pensando/sw/venice/utils/tsdb"
)

// this package contains the REST API provided by the agent

const (
	agentRestURL = "localhost:1337"
)

// RestServer is the REST api server
type RestServer struct {
	sync.Mutex
	listenURL         string                   // URL where http server is listening
	TpAgent           tpa.CtrlerIntf           // telemetry policy agent
	nodeUUID          string                   // smart nic name for default meta
	keyTranslator     *ntranslate.Translator   // key to objMeta translator
	PrefixRoutes      map[string]routeAddFunc  // REST API route add functions
	GetPointsFuncList map[string]getPointsFunc // Get metrics points
}

type routeAddFunc func(*mux.Router)
type getPointsFunc func() ([]*tsdb.Point, error)

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
func NewRestServer(tpAgent tpa.CtrlerIntf, keyTranslator *ntranslate.Translator, listenURL string) (*RestServer, error) {
	// create server instance
	srv := RestServer{
		listenURL:     listenURL,
		TpAgent:       tpAgent,
		keyTranslator: keyTranslator,
	}

	return &srv, nil
}

// getTagsFromMeta returns tags to store in Venice TSDB
func (s *RestServer) getTagsFromMeta(meta *api.ObjectMeta) map[string]string {
	return map[string]string{
		"tenant":    meta.Tenant,
		"namespace": meta.Namespace,
		"name":      meta.Name,
	}
}

// GetObjectMeta is a wrapper around  translate function to set default meta
func (s *RestServer) GetObjectMeta(kind string, key interface{}) *api.ObjectMeta {
	meta := s.keyTranslator.GetObjectMeta(kind, key)
	if meta == nil {
		meta = &api.ObjectMeta{
			Name:      s.GetNodeUUID(),
			Tenant:    globals.DefaultTenant,
			Namespace: globals.DefaultNamespace,
		}
	}
	return meta
}

// SetNodeUUID sets node UUID from naple status
func (s *RestServer) SetNodeUUID(name string) {
	s.Lock()
	defer s.Unlock()
	s.nodeUUID = name

}

// GetUUID gets node UUID
func (s *RestServer) GetNodeUUID() string {
	s.Lock()
	defer s.Unlock()
	return s.nodeUUID
}
