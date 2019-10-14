// Code generated by protoc-gen-grpc-pensando DO NOT EDIT.

/*
Package networkCliUtilsBackend is a auto generated package.
Input file: networkinterface.proto
*/
package cli

import (
	"github.com/pensando/sw/api"
	"github.com/pensando/sw/api/generated/network"
	"github.com/pensando/sw/venice/cli/gen"
)

// CreateNetworkInterfaceFlags specifies flags for NetworkInterface create operation
var CreateNetworkInterfaceFlags = []gen.CliFlag{
	{
		ID:     "admin-status",
		Type:   "String",
		Help:   "",
		Skip:   false,
		Insert: "",
	},
	{
		ID:     "mtu",
		Type:   "String",
		Help:   "",
		Skip:   false,
		Insert: "",
	},
	{
		ID:     "rx-pause-enabled",
		Type:   "Bool",
		Help:   "",
		Skip:   false,
		Insert: "",
	},
	{
		ID:     "speed",
		Type:   "String",
		Help:   "",
		Skip:   false,
		Insert: "",
	},
	{
		ID:     "tx-pause-enabled",
		Type:   "Bool",
		Help:   "",
		Skip:   false,
		Insert: "",
	},
}

func removeNetworkInterfaceOper(obj interface{}) error {
	if v, ok := obj.(*network.NetworkInterface); ok {
		v.UUID = ""
		v.ResourceVersion = ""
		v.CreationTime = api.Timestamp{}
		v.ModTime = api.Timestamp{}
		v.Status = network.NetworkInterfaceStatus{}
	}
	return nil
}

func init() {
	cl := gen.GetInfo()

	cl.AddCliInfo("network.NetworkInterface", "create", CreateNetworkInterfaceFlags)
	cl.AddRemoveObjOperFunc("network.NetworkInterface", removeNetworkInterfaceOper)

}
