// Code generated by protoc-gen-grpc-pensando DO NOT EDIT.

/*
Package bulkeditApiServer is a auto generated package.
*/
package bulkedit

import (
	"sync"

	"github.com/pensando/sw/api"
)

var schema_init_once sync.Once

var local_schema map[string]*api.Struct

func init_schema_map() {
	local_schema = make(map[string]*api.Struct)
}

func GetLocalSchema() map[string]*api.Struct {
	return local_schema
}