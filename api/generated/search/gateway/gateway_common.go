// Code generated by protoc-gen-grpc-pensando DO NOT EDIT.

/*
Package searchGwService is a auto generated package.
Input file: search.proto
*/
package searchGwService

import (
	"net/http"
	"sync"

	"github.com/GeertJohan/go.rice"
	"github.com/pkg/errors"

	"github.com/pensando/grpc-gateway/runtime"

	"github.com/pensando/sw/venice/utils/log"
)

var muxMutex sync.Mutex
var mux *runtime.ServeMux
var fileCount int

const codecSize = 1024 * 1024

func registerSwaggerDef(m *http.ServeMux, logger log.Logger) error {
	box, err := rice.FindBox("../../../../api/protos/../generated/search/swagger")
	if err != nil {
		err = errors.Wrap(err, "error opening rice.Box")
		return err
	}
	content, err := box.Bytes("search.swagger.json")
	if err != nil {
		err = errors.Wrap(err, "error opening rice.File")
		return err
	}
	m.HandleFunc("/swagger/search/", func(w http.ResponseWriter, r *http.Request) {
		w.Write(content)
	})
	return nil
}
