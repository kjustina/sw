// Code generated by protoc-gen-grpc-pensando DO NOT EDIT.

/*
Package monitoringCliUtilsBackend is a auto generated package.
Input file: techsupport.proto
*/
package cli

import (
	"github.com/pensando/sw/api/generated/monitoring"
	"github.com/pensando/sw/venice/cli/gen"
)

// CreateTechSupportRequestFlags specifies flags for TechSupportRequest create operation
var CreateTechSupportRequestFlags = []gen.CliFlag{
	{
		ID:     "names",
		Type:   "StringSlice",
		Help:   "",
		Skip:   false,
		Insert: "",
	},
	{
		ID:     "verbosity",
		Type:   "Int",
		Help:   "",
		Skip:   false,
		Insert: "",
	},
}

func removeTechSupportRequestOper(obj interface{}) error {
	if v, ok := obj.(*monitoring.TechSupportRequest); ok {
		v.UUID = ""
		v.ResourceVersion = ""
		v.Status = monitoring.TechSupportRequestStatus{}
	}
	return nil
}

func init() {
	cl := gen.GetInfo()

	cl.AddCliInfo("monitoring.TechSupportRequest", "create", CreateTechSupportRequestFlags)
	cl.AddRemoveObjOperFunc("monitoring.TechSupportRequest", removeTechSupportRequestOper)

}
