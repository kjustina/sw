// Code generated by protoc-gen-grpc-pensando DO NOT EDIT.

/*
Package networkencryption is a auto generated package.
Input file: protos/networkencryption.proto
*/
package networkencryption

import (
	fmt "fmt"
	listerwatcher "github.com/pensando/sw/api/listerwatcher"
	"github.com/pensando/sw/utils/kvstore"
	"github.com/pensando/sw/utils/log"
)

// Dummy definitions to suppress nonused warnings
var _ kvstore.Interface
var _ log.Logger
var _ listerwatcher.WatcherClient

// MakeKey generates a KV store key for the object
func (m *TrafficEncryptionPolicy) MakeKey(prefix string) string {
	return fmt.Sprint("/venice/", prefix, "/", "trafficEncryptionPolicy/", m.Name)
}

// MakeKey generates a KV store key for the object
func (m *AutoMsgTrafficEncryptionPolicyListHelper) MakeKey(prefix string) string {
	obj := TrafficEncryptionPolicy{}
	return obj.MakeKey(prefix)
}

// MakeKey generates a KV store key for the object
func (m *AutoMsgTrafficEncryptionPolicyWatchHelper) MakeKey(prefix string) string {
	obj := TrafficEncryptionPolicy{}
	return obj.MakeKey(prefix)
}
