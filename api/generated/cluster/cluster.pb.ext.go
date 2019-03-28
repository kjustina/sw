// Code generated by protoc-gen-grpc-pensando DO NOT EDIT.

/*
Package cluster is a auto generated package.
Input file: cluster.proto
*/
package cluster

import (
	"context"
	"errors"
	fmt "fmt"
	"strings"

	listerwatcher "github.com/pensando/sw/api/listerwatcher"
	"github.com/pensando/sw/venice/utils/kvstore"
	"github.com/pensando/sw/venice/utils/log"

	"github.com/pensando/sw/api/interfaces"
	"github.com/pensando/sw/venice/globals"
	validators "github.com/pensando/sw/venice/utils/apigen/validators"
	"github.com/pensando/sw/venice/utils/runtime"
	"github.com/pensando/sw/venice/utils/transformers/storage"
)

// Dummy definitions to suppress nonused warnings
var _ kvstore.Interface
var _ log.Logger
var _ listerwatcher.WatcherClient

// MemInfo_MemType_normal is a map of normalized values for the enum
var MemInfo_MemType_normal = map[string]string{
	"DDR":     "DDR",
	"HBM":     "HBM",
	"UNKNOWN": "UNKNOWN",
	"ddr":     "DDR",
	"hbm":     "HBM",
	"unknown": "UNKNOWN",
}

// NodeCondition_ConditionType_normal is a map of normalized values for the enum
var NodeCondition_ConditionType_normal = map[string]string{
	"LEADER": "LEADER",
	"leader": "LEADER",
}

// NodeStatus_NodePhase_normal is a map of normalized values for the enum
var NodeStatus_NodePhase_normal = map[string]string{
	"FAILED":  "FAILED",
	"JOINED":  "JOINED",
	"PENDING": "PENDING",
	"UNKNOWN": "UNKNOWN",
	"failed":  "FAILED",
	"joined":  "JOINED",
	"pending": "PENDING",
	"unknown": "UNKNOWN",
}

// ConditionStatus_normal is a map of normalized values for the enum
var ConditionStatus_normal = map[string]string{
	"FALSE":   "FALSE",
	"TRUE":    "TRUE",
	"UNKNOWN": "UNKNOWN",
	"false":   "FALSE",
	"true":    "TRUE",
	"unknown": "UNKNOWN",
}

var _ validators.DummyVar
var validatorMapCluster = make(map[string]map[string][]func(string, interface{}) error)

var storageTransformersMapCluster = make(map[string][]func(ctx context.Context, i interface{}, toStorage bool) error)

// MakeKey generates a KV store key for the object
func (m *Cluster) MakeKey(prefix string) string {
	return fmt.Sprint(globals.ConfigRootPrefix, "/", prefix, "/", "cluster", "/Singleton")
}

func (m *Cluster) MakeURI(cat, ver, prefix string) string {
	return fmt.Sprint("/", cat, "/", prefix, "/", ver, "/cluster")
}

// MakeKey generates a KV store key for the object
func (m *ClusterAuthBootstrapRequest) MakeKey(prefix string) string {
	return fmt.Sprint(globals.ConfigRootPrefix, "/", prefix, "/", "cluster", "/Singleton")
}

func (m *ClusterAuthBootstrapRequest) MakeURI(cat, ver, prefix string) string {
	return fmt.Sprint("/", cat, "/", prefix, "/", ver, "/cluster")
}

// MakeKey generates a KV store key for the object
func (m *Host) MakeKey(prefix string) string {
	return fmt.Sprint(globals.ConfigRootPrefix, "/", prefix, "/", "hosts/", m.Name)
}

func (m *Host) MakeURI(cat, ver, prefix string) string {
	in := m
	return fmt.Sprint("/", cat, "/", prefix, "/", ver, "/hosts/", in.Name)
}

// MakeKey generates a KV store key for the object
func (m *Node) MakeKey(prefix string) string {
	return fmt.Sprint(globals.ConfigRootPrefix, "/", prefix, "/", "nodes/", m.Name)
}

func (m *Node) MakeURI(cat, ver, prefix string) string {
	in := m
	return fmt.Sprint("/", cat, "/", prefix, "/", ver, "/nodes/", in.Name)
}

// MakeKey generates a KV store key for the object
func (m *UpdateTLSConfigRequest) MakeKey(prefix string) string {
	return fmt.Sprint(globals.ConfigRootPrefix, "/", prefix, "/", "cluster", "/Singleton")
}

func (m *UpdateTLSConfigRequest) MakeURI(cat, ver, prefix string) string {
	return fmt.Sprint("/", cat, "/", prefix, "/", ver, "/cluster")
}

// Clone clones the object into into or creates one of into is nil
func (m *CPUInfo) Clone(into interface{}) (interface{}, error) {
	var out *CPUInfo
	var ok bool
	if into == nil {
		out = &CPUInfo{}
	} else {
		out, ok = into.(*CPUInfo)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *CPUInfo) Defaults(ver string) bool {
	return false
}

// Clone clones the object into into or creates one of into is nil
func (m *Cluster) Clone(into interface{}) (interface{}, error) {
	var out *Cluster
	var ok bool
	if into == nil {
		out = &Cluster{}
	} else {
		out, ok = into.(*Cluster)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *Cluster) Defaults(ver string) bool {
	var ret bool
	m.Kind = "Cluster"
	ret = m.Tenant != "" || m.Namespace != ""
	if ret {
		m.Tenant, m.Namespace = "", ""
	}
	return ret
}

// Clone clones the object into into or creates one of into is nil
func (m *ClusterAuthBootstrapRequest) Clone(into interface{}) (interface{}, error) {
	var out *ClusterAuthBootstrapRequest
	var ok bool
	if into == nil {
		out = &ClusterAuthBootstrapRequest{}
	} else {
		out, ok = into.(*ClusterAuthBootstrapRequest)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *ClusterAuthBootstrapRequest) Defaults(ver string) bool {
	return false
}

// Clone clones the object into into or creates one of into is nil
func (m *ClusterSpec) Clone(into interface{}) (interface{}, error) {
	var out *ClusterSpec
	var ok bool
	if into == nil {
		out = &ClusterSpec{}
	} else {
		out, ok = into.(*ClusterSpec)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *ClusterSpec) Defaults(ver string) bool {
	return false
}

// Clone clones the object into into or creates one of into is nil
func (m *ClusterStatus) Clone(into interface{}) (interface{}, error) {
	var out *ClusterStatus
	var ok bool
	if into == nil {
		out = &ClusterStatus{}
	} else {
		out, ok = into.(*ClusterStatus)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *ClusterStatus) Defaults(ver string) bool {
	return false
}

// Clone clones the object into into or creates one of into is nil
func (m *DockerInfo) Clone(into interface{}) (interface{}, error) {
	var out *DockerInfo
	var ok bool
	if into == nil {
		out = &DockerInfo{}
	} else {
		out, ok = into.(*DockerInfo)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *DockerInfo) Defaults(ver string) bool {
	return false
}

// Clone clones the object into into or creates one of into is nil
func (m *Host) Clone(into interface{}) (interface{}, error) {
	var out *Host
	var ok bool
	if into == nil {
		out = &Host{}
	} else {
		out, ok = into.(*Host)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *Host) Defaults(ver string) bool {
	var ret bool
	m.Kind = "Host"
	ret = m.Tenant != "" || m.Namespace != ""
	if ret {
		m.Tenant, m.Namespace = "", ""
	}
	ret = m.Spec.Defaults(ver) || ret
	return ret
}

// Clone clones the object into into or creates one of into is nil
func (m *HostSpec) Clone(into interface{}) (interface{}, error) {
	var out *HostSpec
	var ok bool
	if into == nil {
		out = &HostSpec{}
	} else {
		out, ok = into.(*HostSpec)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *HostSpec) Defaults(ver string) bool {
	var ret bool
	for k := range m.SmartNICs {
		i := m.SmartNICs[k]
		ret = i.Defaults(ver) || ret
	}
	return ret
}

// Clone clones the object into into or creates one of into is nil
func (m *HostStatus) Clone(into interface{}) (interface{}, error) {
	var out *HostStatus
	var ok bool
	if into == nil {
		out = &HostStatus{}
	} else {
		out, ok = into.(*HostStatus)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *HostStatus) Defaults(ver string) bool {
	return false
}

// Clone clones the object into into or creates one of into is nil
func (m *InterfaceInfo) Clone(into interface{}) (interface{}, error) {
	var out *InterfaceInfo
	var ok bool
	if into == nil {
		out = &InterfaceInfo{}
	} else {
		out, ok = into.(*InterfaceInfo)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *InterfaceInfo) Defaults(ver string) bool {
	return false
}

// Clone clones the object into into or creates one of into is nil
func (m *MemInfo) Clone(into interface{}) (interface{}, error) {
	var out *MemInfo
	var ok bool
	if into == nil {
		out = &MemInfo{}
	} else {
		out, ok = into.(*MemInfo)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *MemInfo) Defaults(ver string) bool {
	var ret bool
	ret = true
	switch ver {
	default:
		m.Type = "UNKNOWN"
	}
	return ret
}

// Clone clones the object into into or creates one of into is nil
func (m *NetworkInfo) Clone(into interface{}) (interface{}, error) {
	var out *NetworkInfo
	var ok bool
	if into == nil {
		out = &NetworkInfo{}
	} else {
		out, ok = into.(*NetworkInfo)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *NetworkInfo) Defaults(ver string) bool {
	return false
}

// Clone clones the object into into or creates one of into is nil
func (m *Node) Clone(into interface{}) (interface{}, error) {
	var out *Node
	var ok bool
	if into == nil {
		out = &Node{}
	} else {
		out, ok = into.(*Node)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *Node) Defaults(ver string) bool {
	var ret bool
	m.Kind = "Node"
	ret = m.Tenant != "" || m.Namespace != ""
	if ret {
		m.Tenant, m.Namespace = "", ""
	}
	ret = m.Status.Defaults(ver) || ret
	return ret
}

// Clone clones the object into into or creates one of into is nil
func (m *NodeCondition) Clone(into interface{}) (interface{}, error) {
	var out *NodeCondition
	var ok bool
	if into == nil {
		out = &NodeCondition{}
	} else {
		out, ok = into.(*NodeCondition)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *NodeCondition) Defaults(ver string) bool {
	var ret bool
	ret = true
	switch ver {
	default:
		m.Status = "UNKNOWN"
		m.Type = "LEADER"
	}
	return ret
}

// Clone clones the object into into or creates one of into is nil
func (m *NodeInfo) Clone(into interface{}) (interface{}, error) {
	var out *NodeInfo
	var ok bool
	if into == nil {
		out = &NodeInfo{}
	} else {
		out, ok = into.(*NodeInfo)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *NodeInfo) Defaults(ver string) bool {
	var ret bool
	if m.MemoryInfo != nil {
		ret = m.MemoryInfo.Defaults(ver) || ret
	}
	return ret
}

// Clone clones the object into into or creates one of into is nil
func (m *NodeSpec) Clone(into interface{}) (interface{}, error) {
	var out *NodeSpec
	var ok bool
	if into == nil {
		out = &NodeSpec{}
	} else {
		out, ok = into.(*NodeSpec)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *NodeSpec) Defaults(ver string) bool {
	return false
}

// Clone clones the object into into or creates one of into is nil
func (m *NodeStatus) Clone(into interface{}) (interface{}, error) {
	var out *NodeStatus
	var ok bool
	if into == nil {
		out = &NodeStatus{}
	} else {
		out, ok = into.(*NodeStatus)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *NodeStatus) Defaults(ver string) bool {
	var ret bool
	for k := range m.Conditions {
		i := m.Conditions[k]
		ret = i.Defaults(ver) || ret
	}
	ret = true
	switch ver {
	default:
		m.Phase = "UNKNOWN"
	}
	return ret
}

// Clone clones the object into into or creates one of into is nil
func (m *OsInfo) Clone(into interface{}) (interface{}, error) {
	var out *OsInfo
	var ok bool
	if into == nil {
		out = &OsInfo{}
	} else {
		out, ok = into.(*OsInfo)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *OsInfo) Defaults(ver string) bool {
	return false
}

// Clone clones the object into into or creates one of into is nil
func (m *SmartNICID) Clone(into interface{}) (interface{}, error) {
	var out *SmartNICID
	var ok bool
	if into == nil {
		out = &SmartNICID{}
	} else {
		out, ok = into.(*SmartNICID)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *SmartNICID) Defaults(ver string) bool {
	var ret bool
	return ret
}

// Clone clones the object into into or creates one of into is nil
func (m *StorageDeviceInfo) Clone(into interface{}) (interface{}, error) {
	var out *StorageDeviceInfo
	var ok bool
	if into == nil {
		out = &StorageDeviceInfo{}
	} else {
		out, ok = into.(*StorageDeviceInfo)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *StorageDeviceInfo) Defaults(ver string) bool {
	return false
}

// Clone clones the object into into or creates one of into is nil
func (m *StorageInfo) Clone(into interface{}) (interface{}, error) {
	var out *StorageInfo
	var ok bool
	if into == nil {
		out = &StorageInfo{}
	} else {
		out, ok = into.(*StorageInfo)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *StorageInfo) Defaults(ver string) bool {
	return false
}

// Clone clones the object into into or creates one of into is nil
func (m *UpdateTLSConfigRequest) Clone(into interface{}) (interface{}, error) {
	var out *UpdateTLSConfigRequest
	var ok bool
	if into == nil {
		out = &UpdateTLSConfigRequest{}
	} else {
		out, ok = into.(*UpdateTLSConfigRequest)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *UpdateTLSConfigRequest) Defaults(ver string) bool {
	return false
}

// Validators and Requirements

func (m *CPUInfo) References(tenant string, path string, resp map[string]apiintf.ReferenceObj) {

}

func (m *CPUInfo) Validate(ver, path string, ignoreStatus bool) []error {
	var ret []error
	return ret
}

func (m *CPUInfo) Normalize() {

}

func (m *Cluster) References(tenant string, path string, resp map[string]apiintf.ReferenceObj) {

}

func (m *Cluster) Validate(ver, path string, ignoreStatus bool) []error {
	var ret []error

	if m.Tenant != "" {
		ret = append(ret, errors.New("Tenant not allowed for Cluster"))
	}
	if m.Namespace != "" {
		ret = append(ret, errors.New("Namespace not allowed for Cluster"))
	}

	{
		dlmtr := "."
		if path == "" {
			dlmtr = ""
		}
		npath := path + dlmtr + "ObjectMeta"
		if errs := m.ObjectMeta.Validate(ver, npath, ignoreStatus); errs != nil {
			ret = append(ret, errs...)
		}
	}
	return ret
}

func (m *Cluster) Normalize() {

	m.ObjectMeta.Normalize()

}

func (m *ClusterAuthBootstrapRequest) References(tenant string, path string, resp map[string]apiintf.ReferenceObj) {

}

func (m *ClusterAuthBootstrapRequest) Validate(ver, path string, ignoreStatus bool) []error {
	var ret []error
	return ret
}

func (m *ClusterAuthBootstrapRequest) Normalize() {

	m.ObjectMeta.Normalize()

}

func (m *ClusterSpec) References(tenant string, path string, resp map[string]apiintf.ReferenceObj) {

}

func (m *ClusterSpec) Validate(ver, path string, ignoreStatus bool) []error {
	var ret []error
	return ret
}

func (m *ClusterSpec) Normalize() {

}

func (m *ClusterStatus) References(tenant string, path string, resp map[string]apiintf.ReferenceObj) {

}

func (m *ClusterStatus) Validate(ver, path string, ignoreStatus bool) []error {
	var ret []error
	return ret
}

func (m *ClusterStatus) Normalize() {

}

func (m *DockerInfo) References(tenant string, path string, resp map[string]apiintf.ReferenceObj) {

}

func (m *DockerInfo) Validate(ver, path string, ignoreStatus bool) []error {
	var ret []error
	return ret
}

func (m *DockerInfo) Normalize() {

}

func (m *Host) References(tenant string, path string, resp map[string]apiintf.ReferenceObj) {

}

func (m *Host) Validate(ver, path string, ignoreStatus bool) []error {
	var ret []error

	if m.Tenant != "" {
		ret = append(ret, errors.New("Tenant not allowed for Host"))
	}
	if m.Namespace != "" {
		ret = append(ret, errors.New("Namespace not allowed for Host"))
	}

	{
		dlmtr := "."
		if path == "" {
			dlmtr = ""
		}
		npath := path + dlmtr + "ObjectMeta"
		if errs := m.ObjectMeta.Validate(ver, npath, ignoreStatus); errs != nil {
			ret = append(ret, errs...)
		}
	}

	{
		dlmtr := "."
		if path == "" {
			dlmtr = ""
		}
		npath := path + dlmtr + "Spec"
		if errs := m.Spec.Validate(ver, npath, ignoreStatus); errs != nil {
			ret = append(ret, errs...)
		}
	}
	return ret
}

func (m *Host) Normalize() {

	m.ObjectMeta.Normalize()

	m.Spec.Normalize()

}

func (m *HostSpec) References(tenant string, path string, resp map[string]apiintf.ReferenceObj) {

}

func (m *HostSpec) Validate(ver, path string, ignoreStatus bool) []error {
	var ret []error
	for k, v := range m.SmartNICs {
		dlmtr := "."
		if path == "" {
			dlmtr = ""
		}
		npath := fmt.Sprintf("%s%sSmartNICs[%v]", path, dlmtr, k)
		if errs := v.Validate(ver, npath, ignoreStatus); errs != nil {
			ret = append(ret, errs...)
		}
	}
	return ret
}

func (m *HostSpec) Normalize() {

	for _, v := range m.SmartNICs {
		v.Normalize()

	}

}

func (m *HostStatus) References(tenant string, path string, resp map[string]apiintf.ReferenceObj) {

}

func (m *HostStatus) Validate(ver, path string, ignoreStatus bool) []error {
	var ret []error
	return ret
}

func (m *HostStatus) Normalize() {

}

func (m *InterfaceInfo) References(tenant string, path string, resp map[string]apiintf.ReferenceObj) {

}

func (m *InterfaceInfo) Validate(ver, path string, ignoreStatus bool) []error {
	var ret []error
	return ret
}

func (m *InterfaceInfo) Normalize() {

}

func (m *MemInfo) References(tenant string, path string, resp map[string]apiintf.ReferenceObj) {

}

func (m *MemInfo) Validate(ver, path string, ignoreStatus bool) []error {
	var ret []error
	if vs, ok := validatorMapCluster["MemInfo"][ver]; ok {
		for _, v := range vs {
			if err := v(path, m); err != nil {
				ret = append(ret, err)
			}
		}
	} else if vs, ok := validatorMapCluster["MemInfo"]["all"]; ok {
		for _, v := range vs {
			if err := v(path, m); err != nil {
				ret = append(ret, err)
			}
		}
	}
	return ret
}

func (m *MemInfo) Normalize() {

	m.Type = MemInfo_MemType_normal[strings.ToLower(m.Type)]

}

func (m *NetworkInfo) References(tenant string, path string, resp map[string]apiintf.ReferenceObj) {

}

func (m *NetworkInfo) Validate(ver, path string, ignoreStatus bool) []error {
	var ret []error
	return ret
}

func (m *NetworkInfo) Normalize() {

}

func (m *Node) References(tenant string, path string, resp map[string]apiintf.ReferenceObj) {

}

func (m *Node) Validate(ver, path string, ignoreStatus bool) []error {
	var ret []error

	if m.Tenant != "" {
		ret = append(ret, errors.New("Tenant not allowed for Node"))
	}
	if m.Namespace != "" {
		ret = append(ret, errors.New("Namespace not allowed for Node"))
	}

	{
		dlmtr := "."
		if path == "" {
			dlmtr = ""
		}
		npath := path + dlmtr + "ObjectMeta"
		if errs := m.ObjectMeta.Validate(ver, npath, ignoreStatus); errs != nil {
			ret = append(ret, errs...)
		}
	}
	if !ignoreStatus {

		dlmtr := "."
		if path == "" {
			dlmtr = ""
		}
		npath := path + dlmtr + "Status"
		if errs := m.Status.Validate(ver, npath, ignoreStatus); errs != nil {
			ret = append(ret, errs...)
		}
	}
	return ret
}

func (m *Node) Normalize() {

	m.ObjectMeta.Normalize()

	m.Status.Normalize()

}

func (m *NodeCondition) References(tenant string, path string, resp map[string]apiintf.ReferenceObj) {

}

func (m *NodeCondition) Validate(ver, path string, ignoreStatus bool) []error {
	var ret []error
	if vs, ok := validatorMapCluster["NodeCondition"][ver]; ok {
		for _, v := range vs {
			if err := v(path, m); err != nil {
				ret = append(ret, err)
			}
		}
	} else if vs, ok := validatorMapCluster["NodeCondition"]["all"]; ok {
		for _, v := range vs {
			if err := v(path, m); err != nil {
				ret = append(ret, err)
			}
		}
	}
	return ret
}

func (m *NodeCondition) Normalize() {

	m.Status = ConditionStatus_normal[strings.ToLower(m.Status)]

	m.Type = NodeCondition_ConditionType_normal[strings.ToLower(m.Type)]

}

func (m *NodeInfo) References(tenant string, path string, resp map[string]apiintf.ReferenceObj) {

}

func (m *NodeInfo) Validate(ver, path string, ignoreStatus bool) []error {
	var ret []error
	if m.MemoryInfo != nil {
		{
			dlmtr := "."
			if path == "" {
				dlmtr = ""
			}
			npath := path + dlmtr + "MemoryInfo"
			if errs := m.MemoryInfo.Validate(ver, npath, ignoreStatus); errs != nil {
				ret = append(ret, errs...)
			}
		}
	}
	return ret
}

func (m *NodeInfo) Normalize() {

	if m.MemoryInfo != nil {
		m.MemoryInfo.Normalize()
	}

}

func (m *NodeSpec) References(tenant string, path string, resp map[string]apiintf.ReferenceObj) {

}

func (m *NodeSpec) Validate(ver, path string, ignoreStatus bool) []error {
	var ret []error
	return ret
}

func (m *NodeSpec) Normalize() {

}

func (m *NodeStatus) References(tenant string, path string, resp map[string]apiintf.ReferenceObj) {

}

func (m *NodeStatus) Validate(ver, path string, ignoreStatus bool) []error {
	var ret []error
	for k, v := range m.Conditions {
		dlmtr := "."
		if path == "" {
			dlmtr = ""
		}
		npath := fmt.Sprintf("%s%sConditions[%v]", path, dlmtr, k)
		if errs := v.Validate(ver, npath, ignoreStatus); errs != nil {
			ret = append(ret, errs...)
		}
	}
	if vs, ok := validatorMapCluster["NodeStatus"][ver]; ok {
		for _, v := range vs {
			if err := v(path, m); err != nil {
				ret = append(ret, err)
			}
		}
	} else if vs, ok := validatorMapCluster["NodeStatus"]["all"]; ok {
		for _, v := range vs {
			if err := v(path, m); err != nil {
				ret = append(ret, err)
			}
		}
	}
	return ret
}

func (m *NodeStatus) Normalize() {

	for _, v := range m.Conditions {
		v.Normalize()

	}

	m.Phase = NodeStatus_NodePhase_normal[strings.ToLower(m.Phase)]

}

func (m *OsInfo) References(tenant string, path string, resp map[string]apiintf.ReferenceObj) {

}

func (m *OsInfo) Validate(ver, path string, ignoreStatus bool) []error {
	var ret []error
	return ret
}

func (m *OsInfo) Normalize() {

}

func (m *SmartNICID) References(tenant string, path string, resp map[string]apiintf.ReferenceObj) {

}

func (m *SmartNICID) Validate(ver, path string, ignoreStatus bool) []error {
	var ret []error
	if vs, ok := validatorMapCluster["SmartNICID"][ver]; ok {
		for _, v := range vs {
			if err := v(path, m); err != nil {
				ret = append(ret, err)
			}
		}
	} else if vs, ok := validatorMapCluster["SmartNICID"]["all"]; ok {
		for _, v := range vs {
			if err := v(path, m); err != nil {
				ret = append(ret, err)
			}
		}
	}
	return ret
}

func (m *SmartNICID) Normalize() {

}

func (m *StorageDeviceInfo) References(tenant string, path string, resp map[string]apiintf.ReferenceObj) {

}

func (m *StorageDeviceInfo) Validate(ver, path string, ignoreStatus bool) []error {
	var ret []error
	return ret
}

func (m *StorageDeviceInfo) Normalize() {

}

func (m *StorageInfo) References(tenant string, path string, resp map[string]apiintf.ReferenceObj) {

}

func (m *StorageInfo) Validate(ver, path string, ignoreStatus bool) []error {
	var ret []error
	return ret
}

func (m *StorageInfo) Normalize() {

}

func (m *UpdateTLSConfigRequest) References(tenant string, path string, resp map[string]apiintf.ReferenceObj) {

}

func (m *UpdateTLSConfigRequest) Validate(ver, path string, ignoreStatus bool) []error {
	var ret []error
	return ret
}

func (m *UpdateTLSConfigRequest) Normalize() {

	m.ObjectMeta.Normalize()

}

// Transformers

func (m *Cluster) ApplyStorageTransformer(ctx context.Context, toStorage bool) error {
	if err := m.Spec.ApplyStorageTransformer(ctx, toStorage); err != nil {
		return err
	}
	return nil
}

type storageClusterTransformer struct{}

var StorageClusterTransformer storageClusterTransformer

func (st *storageClusterTransformer) TransformFromStorage(ctx context.Context, i interface{}) (interface{}, error) {
	r := i.(Cluster)
	err := r.ApplyStorageTransformer(ctx, false)
	if err != nil {
		return nil, err
	}
	return r, nil
}

func (st *storageClusterTransformer) TransformToStorage(ctx context.Context, i interface{}) (interface{}, error) {
	r := i.(Cluster)
	err := r.ApplyStorageTransformer(ctx, true)
	if err != nil {
		return nil, err
	}
	return r, nil
}

func (m *ClusterSpec) ApplyStorageTransformer(ctx context.Context, toStorage bool) error {
	if vs, ok := storageTransformersMapCluster["ClusterSpec"]; ok {
		for _, v := range vs {
			if err := v(ctx, m, toStorage); err != nil {
				return err
			}
		}
	}
	return nil
}

func init() {
	scheme := runtime.GetDefaultScheme()
	scheme.AddKnownTypes(
		&Cluster{},
		&ClusterAuthBootstrapRequest{},
		&Host{},
		&Node{},
		&UpdateTLSConfigRequest{},
	)

	validatorMapCluster = make(map[string]map[string][]func(string, interface{}) error)

	validatorMapCluster["MemInfo"] = make(map[string][]func(string, interface{}) error)
	validatorMapCluster["MemInfo"]["all"] = append(validatorMapCluster["MemInfo"]["all"], func(path string, i interface{}) error {
		m := i.(*MemInfo)

		if _, ok := MemInfo_MemType_value[m.Type]; !ok {
			vals := []string{}
			for k1, _ := range MemInfo_MemType_value {
				vals = append(vals, k1)
			}
			return fmt.Errorf("%v did not match allowed strings %v", path+"."+"Type", vals)
		}
		return nil
	})

	validatorMapCluster["NodeCondition"] = make(map[string][]func(string, interface{}) error)
	validatorMapCluster["NodeCondition"]["all"] = append(validatorMapCluster["NodeCondition"]["all"], func(path string, i interface{}) error {
		m := i.(*NodeCondition)

		if _, ok := ConditionStatus_value[m.Status]; !ok {
			vals := []string{}
			for k1, _ := range ConditionStatus_value {
				vals = append(vals, k1)
			}
			return fmt.Errorf("%v did not match allowed strings %v", path+"."+"Status", vals)
		}
		return nil
	})

	validatorMapCluster["NodeCondition"]["all"] = append(validatorMapCluster["NodeCondition"]["all"], func(path string, i interface{}) error {
		m := i.(*NodeCondition)

		if _, ok := NodeCondition_ConditionType_value[m.Type]; !ok {
			vals := []string{}
			for k1, _ := range NodeCondition_ConditionType_value {
				vals = append(vals, k1)
			}
			return fmt.Errorf("%v did not match allowed strings %v", path+"."+"Type", vals)
		}
		return nil
	})

	validatorMapCluster["NodeStatus"] = make(map[string][]func(string, interface{}) error)
	validatorMapCluster["NodeStatus"]["all"] = append(validatorMapCluster["NodeStatus"]["all"], func(path string, i interface{}) error {
		m := i.(*NodeStatus)

		if _, ok := NodeStatus_NodePhase_value[m.Phase]; !ok {
			vals := []string{}
			for k1, _ := range NodeStatus_NodePhase_value {
				vals = append(vals, k1)
			}
			return fmt.Errorf("%v did not match allowed strings %v", path+"."+"Phase", vals)
		}
		return nil
	})

	validatorMapCluster["SmartNICID"] = make(map[string][]func(string, interface{}) error)

	validatorMapCluster["SmartNICID"]["all"] = append(validatorMapCluster["SmartNICID"]["all"], func(path string, i interface{}) error {
		m := i.(*SmartNICID)
		if err := validators.EmptyOr(validators.MacAddr, m.MACAddress, nil); err != nil {
			return fmt.Errorf("%v failed validation: %s", path+"."+"MACAddress", err.Error())
		}
		return nil
	})

	{
		ClusterSpecKeyTx, err := storage.NewSecretValueTransformer()
		if err != nil {
			log.Fatalf("Error instantiating SecretStorageTransformer: %v", err)
		}
		storageTransformersMapCluster["ClusterSpec"] = append(storageTransformersMapCluster["ClusterSpec"],
			func(ctx context.Context, i interface{}, toStorage bool) error {
				var data []byte
				var err error
				m := i.(*ClusterSpec)

				if toStorage {
					data, err = ClusterSpecKeyTx.TransformToStorage(ctx, []byte(m.Key))
				} else {
					data, err = ClusterSpecKeyTx.TransformFromStorage(ctx, []byte(m.Key))
				}
				m.Key = string(data)

				return err
			})
	}

}
