// Code generated by protoc-gen-grpc-pensando DO NOT EDIT.

/*
Package fwlogApiServer is a auto generated package.
Input file: svc_fwlog.proto
*/
package fwlog

import (
	"github.com/pensando/sw/api"
	"github.com/pensando/sw/venice/utils/runtime"
)

var typesMapSvc_fwlog = map[string]*api.Struct{}

var keyMapSvc_fwlog = map[string][]api.PathsMap{}

func init() {
	schema := runtime.GetDefaultScheme()
	schema.AddSchema(typesMapSvc_fwlog)
	schema.AddPaths(keyMapSvc_fwlog)
}