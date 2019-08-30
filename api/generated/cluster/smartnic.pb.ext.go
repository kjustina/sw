// Code generated by protoc-gen-grpc-pensando DO NOT EDIT.

/*
Package cluster is a auto generated package.
Input file: smartnic.proto
*/
package cluster

import (
	"errors"
	fmt "fmt"
	"strings"

	listerwatcher "github.com/pensando/sw/api/listerwatcher"
	"github.com/pensando/sw/venice/utils/kvstore"
	"github.com/pensando/sw/venice/utils/log"
	"github.com/pensando/sw/venice/utils/ref"

	validators "github.com/pensando/sw/venice/utils/apigen/validators"

	"github.com/pensando/sw/api/interfaces"
	"github.com/pensando/sw/venice/globals"
	"github.com/pensando/sw/venice/utils/runtime"
)

// Dummy definitions to suppress nonused warnings
var _ kvstore.Interface
var _ log.Logger
var _ listerwatcher.WatcherClient

// DSCCondition_ConditionType_normal is a map of normalized values for the enum
var DSCCondition_ConditionType_normal = map[string]string{
	"healthy":            "healthy",
	"nic_health_unknown": "nic_health_unknown",
}

var DSCCondition_ConditionType_vname = map[int32]string{
	0: "healthy",
	1: "nic_health_unknown",
}

var DSCCondition_ConditionType_vvalue = map[string]int32{
	"healthy":            0,
	"nic_health_unknown": 1,
}

func (x DSCCondition_ConditionType) String() string {
	return DSCCondition_ConditionType_vname[int32(x)]
}

// DistributedServiceCardSpec_MgmtModes_normal is a map of normalized values for the enum
var DistributedServiceCardSpec_MgmtModes_normal = map[string]string{
	"host":    "host",
	"network": "network",
}

var DistributedServiceCardSpec_MgmtModes_vname = map[int32]string{
	0: "host",
	1: "network",
}

var DistributedServiceCardSpec_MgmtModes_vvalue = map[string]int32{
	"host":    0,
	"network": 1,
}

func (x DistributedServiceCardSpec_MgmtModes) String() string {
	return DistributedServiceCardSpec_MgmtModes_vname[int32(x)]
}

// DistributedServiceCardSpec_NetworkModes_normal is a map of normalized values for the enum
var DistributedServiceCardSpec_NetworkModes_normal = map[string]string{
	"inband": "inband",
	"oob":    "oob",
}

var DistributedServiceCardSpec_NetworkModes_vname = map[int32]string{
	0: "oob",
	1: "inband",
}

var DistributedServiceCardSpec_NetworkModes_vvalue = map[string]int32{
	"oob":    0,
	"inband": 1,
}

func (x DistributedServiceCardSpec_NetworkModes) String() string {
	return DistributedServiceCardSpec_NetworkModes_vname[int32(x)]
}

// DistributedServiceCardStatus_Phase_normal is a map of normalized values for the enum
var DistributedServiceCardStatus_Phase_normal = map[string]string{
	"admitted":       "admitted",
	"decommissioned": "decommissioned",
	"pending":        "pending",
	"registering":    "registering",
	"rejected":       "rejected",
	"unknown":        "unknown",
}

var DistributedServiceCardStatus_Phase_vname = map[int32]string{
	0: "unknown",
	1: "registering",
	2: "rejected",
	3: "pending",
	4: "admitted",
	5: "decommissioned",
}

var DistributedServiceCardStatus_Phase_vvalue = map[string]int32{
	"unknown":        0,
	"registering":    1,
	"rejected":       2,
	"pending":        3,
	"admitted":       4,
	"decommissioned": 5,
}

func (x DistributedServiceCardStatus_Phase) String() string {
	return DistributedServiceCardStatus_Phase_vname[int32(x)]
}

var _ validators.DummyVar
var validatorMapSmartnic = make(map[string]map[string][]func(string, interface{}) error)

// MakeKey generates a KV store key for the object
func (m *DistributedServiceCard) MakeKey(prefix string) string {
	return fmt.Sprint(globals.ConfigRootPrefix, "/", prefix, "/", "distributedservicecards/", m.Name)
}

func (m *DistributedServiceCard) MakeURI(cat, ver, prefix string) string {
	in := m
	return fmt.Sprint("/", cat, "/", prefix, "/", ver, "/distributedservicecards/", in.Name)
}

// Clone clones the object into into or creates one of into is nil
func (m *BiosInfo) Clone(into interface{}) (interface{}, error) {
	var out *BiosInfo
	var ok bool
	if into == nil {
		out = &BiosInfo{}
	} else {
		out, ok = into.(*BiosInfo)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *(ref.DeepCopy(m).(*BiosInfo))
	return out, nil
}

// Default sets up the defaults for the object
func (m *BiosInfo) Defaults(ver string) bool {
	return false
}

// Clone clones the object into into or creates one of into is nil
func (m *DSCCondition) Clone(into interface{}) (interface{}, error) {
	var out *DSCCondition
	var ok bool
	if into == nil {
		out = &DSCCondition{}
	} else {
		out, ok = into.(*DSCCondition)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *(ref.DeepCopy(m).(*DSCCondition))
	return out, nil
}

// Default sets up the defaults for the object
func (m *DSCCondition) Defaults(ver string) bool {
	var ret bool
	ret = true
	switch ver {
	default:
		m.Status = "unknown"
		m.Type = "healthy"
	}
	return ret
}

// Clone clones the object into into or creates one of into is nil
func (m *DSCInfo) Clone(into interface{}) (interface{}, error) {
	var out *DSCInfo
	var ok bool
	if into == nil {
		out = &DSCInfo{}
	} else {
		out, ok = into.(*DSCInfo)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *(ref.DeepCopy(m).(*DSCInfo))
	return out, nil
}

// Default sets up the defaults for the object
func (m *DSCInfo) Defaults(ver string) bool {
	return false
}

// Clone clones the object into into or creates one of into is nil
func (m *DistributedServiceCard) Clone(into interface{}) (interface{}, error) {
	var out *DistributedServiceCard
	var ok bool
	if into == nil {
		out = &DistributedServiceCard{}
	} else {
		out, ok = into.(*DistributedServiceCard)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *(ref.DeepCopy(m).(*DistributedServiceCard))
	return out, nil
}

// Default sets up the defaults for the object
func (m *DistributedServiceCard) Defaults(ver string) bool {
	var ret bool
	m.Kind = "DistributedServiceCard"
	ret = m.Tenant != "" || m.Namespace != ""
	if ret {
		m.Tenant, m.Namespace = "", ""
	}
	ret = m.Spec.Defaults(ver) || ret
	ret = m.Status.Defaults(ver) || ret
	return ret
}

// Clone clones the object into into or creates one of into is nil
func (m *DistributedServiceCardSpec) Clone(into interface{}) (interface{}, error) {
	var out *DistributedServiceCardSpec
	var ok bool
	if into == nil {
		out = &DistributedServiceCardSpec{}
	} else {
		out, ok = into.(*DistributedServiceCardSpec)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *(ref.DeepCopy(m).(*DistributedServiceCardSpec))
	return out, nil
}

// Default sets up the defaults for the object
func (m *DistributedServiceCardSpec) Defaults(ver string) bool {
	var ret bool
	ret = true
	switch ver {
	default:
		m.MgmtMode = "host"
		m.NetworkMode = "oob"
	}
	return ret
}

// Clone clones the object into into or creates one of into is nil
func (m *DistributedServiceCardStatus) Clone(into interface{}) (interface{}, error) {
	var out *DistributedServiceCardStatus
	var ok bool
	if into == nil {
		out = &DistributedServiceCardStatus{}
	} else {
		out, ok = into.(*DistributedServiceCardStatus)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *(ref.DeepCopy(m).(*DistributedServiceCardStatus))
	return out, nil
}

// Default sets up the defaults for the object
func (m *DistributedServiceCardStatus) Defaults(ver string) bool {
	var ret bool
	for k := range m.Conditions {
		i := m.Conditions[k]
		ret = i.Defaults(ver) || ret
	}
	ret = true
	switch ver {
	default:
		m.AdmissionPhase = "unknown"
	}
	return ret
}

// Clone clones the object into into or creates one of into is nil
func (m *IPConfig) Clone(into interface{}) (interface{}, error) {
	var out *IPConfig
	var ok bool
	if into == nil {
		out = &IPConfig{}
	} else {
		out, ok = into.(*IPConfig)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *(ref.DeepCopy(m).(*IPConfig))
	return out, nil
}

// Default sets up the defaults for the object
func (m *IPConfig) Defaults(ver string) bool {
	return false
}

// Clone clones the object into into or creates one of into is nil
func (m *MacRange) Clone(into interface{}) (interface{}, error) {
	var out *MacRange
	var ok bool
	if into == nil {
		out = &MacRange{}
	} else {
		out, ok = into.(*MacRange)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *(ref.DeepCopy(m).(*MacRange))
	return out, nil
}

// Default sets up the defaults for the object
func (m *MacRange) Defaults(ver string) bool {
	var ret bool
	return ret
}

// Validators and Requirements

func (m *BiosInfo) References(tenant string, path string, resp map[string]apiintf.ReferenceObj) {

}

func (m *BiosInfo) Validate(ver, path string, ignoreStatus bool, ignoreSpec bool) []error {
	var ret []error
	return ret
}

func (m *BiosInfo) Normalize() {

}

func (m *DSCCondition) References(tenant string, path string, resp map[string]apiintf.ReferenceObj) {

}

func (m *DSCCondition) Validate(ver, path string, ignoreStatus bool, ignoreSpec bool) []error {
	var ret []error
	if vs, ok := validatorMapSmartnic["DSCCondition"][ver]; ok {
		for _, v := range vs {
			if err := v(path, m); err != nil {
				ret = append(ret, err)
			}
		}
	} else if vs, ok := validatorMapSmartnic["DSCCondition"]["all"]; ok {
		for _, v := range vs {
			if err := v(path, m); err != nil {
				ret = append(ret, err)
			}
		}
	}
	return ret
}

func (m *DSCCondition) Normalize() {

	m.Status = ConditionStatus_normal[strings.ToLower(m.Status)]

	m.Type = DSCCondition_ConditionType_normal[strings.ToLower(m.Type)]

}

func (m *DSCInfo) References(tenant string, path string, resp map[string]apiintf.ReferenceObj) {

}

func (m *DSCInfo) Validate(ver, path string, ignoreStatus bool, ignoreSpec bool) []error {
	var ret []error

	if m.MemoryInfo != nil {
		{
			dlmtr := "."
			if path == "" {
				dlmtr = ""
			}
			npath := path + dlmtr + "MemoryInfo"
			if errs := m.MemoryInfo.Validate(ver, npath, ignoreStatus, ignoreSpec); errs != nil {
				ret = append(ret, errs...)
			}
		}
	}
	return ret
}

func (m *DSCInfo) Normalize() {

	if m.MemoryInfo != nil {
		m.MemoryInfo.Normalize()
	}

}

func (m *DistributedServiceCard) References(tenant string, path string, resp map[string]apiintf.ReferenceObj) {

}

func (m *DistributedServiceCard) Validate(ver, path string, ignoreStatus bool, ignoreSpec bool) []error {
	var ret []error

	if m.Tenant != "" {
		ret = append(ret, errors.New("Tenant not allowed for DistributedServiceCard"))
	}
	if m.Namespace != "" {
		ret = append(ret, errors.New("Namespace not allowed for DistributedServiceCard"))
	}

	{
		dlmtr := "."
		if path == "" {
			dlmtr = ""
		}
		npath := path + dlmtr + "ObjectMeta"
		if errs := m.ObjectMeta.Validate(ver, npath, ignoreStatus, ignoreSpec); errs != nil {
			ret = append(ret, errs...)
		}
	}

	if !ignoreSpec {

		dlmtr := "."
		if path == "" {
			dlmtr = ""
		}
		npath := path + dlmtr + "Spec"
		if errs := m.Spec.Validate(ver, npath, ignoreStatus, ignoreSpec); errs != nil {
			ret = append(ret, errs...)
		}
	}

	{
		dlmtr := "."
		if path == "" {
			dlmtr = ""
		}
		npath := path + dlmtr + "Spec"
		if errs := m.Spec.Validate(ver, npath, ignoreStatus, ignoreSpec); errs != nil {
			ret = append(ret, errs...)
		}
	}

	if !ignoreStatus {

		dlmtr := "."
		if path == "" {
			dlmtr = ""
		}
		npath := path + dlmtr + "Status"
		if errs := m.Status.Validate(ver, npath, ignoreStatus, ignoreSpec); errs != nil {
			ret = append(ret, errs...)
		}
	}
	return ret
}

func (m *DistributedServiceCard) Normalize() {

	m.ObjectMeta.Normalize()

	m.Spec.Normalize()

	m.Status.Normalize()

}

func (m *DistributedServiceCardSpec) References(tenant string, path string, resp map[string]apiintf.ReferenceObj) {

}

func (m *DistributedServiceCardSpec) Validate(ver, path string, ignoreStatus bool, ignoreSpec bool) []error {
	var ret []error
	if vs, ok := validatorMapSmartnic["DistributedServiceCardSpec"][ver]; ok {
		for _, v := range vs {
			if err := v(path, m); err != nil {
				ret = append(ret, err)
			}
		}
	} else if vs, ok := validatorMapSmartnic["DistributedServiceCardSpec"]["all"]; ok {
		for _, v := range vs {
			if err := v(path, m); err != nil {
				ret = append(ret, err)
			}
		}
	}
	return ret
}

func (m *DistributedServiceCardSpec) Normalize() {

	m.MgmtMode = DistributedServiceCardSpec_MgmtModes_normal[strings.ToLower(m.MgmtMode)]

	m.NetworkMode = DistributedServiceCardSpec_NetworkModes_normal[strings.ToLower(m.NetworkMode)]

}

func (m *DistributedServiceCardStatus) References(tenant string, path string, resp map[string]apiintf.ReferenceObj) {

}

func (m *DistributedServiceCardStatus) Validate(ver, path string, ignoreStatus bool, ignoreSpec bool) []error {
	var ret []error
	for k, v := range m.Conditions {
		dlmtr := "."
		if path == "" {
			dlmtr = ""
		}
		npath := fmt.Sprintf("%s%sConditions[%v]", path, dlmtr, k)
		if errs := v.Validate(ver, npath, ignoreStatus, ignoreSpec); errs != nil {
			ret = append(ret, errs...)
		}
	}

	if m.SystemInfo != nil {
		{
			dlmtr := "."
			if path == "" {
				dlmtr = ""
			}
			npath := path + dlmtr + "SystemInfo"
			if errs := m.SystemInfo.Validate(ver, npath, ignoreStatus, ignoreSpec); errs != nil {
				ret = append(ret, errs...)
			}
		}
	}
	if vs, ok := validatorMapSmartnic["DistributedServiceCardStatus"][ver]; ok {
		for _, v := range vs {
			if err := v(path, m); err != nil {
				ret = append(ret, err)
			}
		}
	} else if vs, ok := validatorMapSmartnic["DistributedServiceCardStatus"]["all"]; ok {
		for _, v := range vs {
			if err := v(path, m); err != nil {
				ret = append(ret, err)
			}
		}
	}
	return ret
}

func (m *DistributedServiceCardStatus) Normalize() {

	m.AdmissionPhase = DistributedServiceCardStatus_Phase_normal[strings.ToLower(m.AdmissionPhase)]

	for k, v := range m.Conditions {
		v.Normalize()
		m.Conditions[k] = v

	}

	if m.SystemInfo != nil {
		m.SystemInfo.Normalize()
	}

}

func (m *IPConfig) References(tenant string, path string, resp map[string]apiintf.ReferenceObj) {

}

func (m *IPConfig) Validate(ver, path string, ignoreStatus bool, ignoreSpec bool) []error {
	var ret []error
	return ret
}

func (m *IPConfig) Normalize() {

}

func (m *MacRange) References(tenant string, path string, resp map[string]apiintf.ReferenceObj) {

}

func (m *MacRange) Validate(ver, path string, ignoreStatus bool, ignoreSpec bool) []error {
	var ret []error
	if vs, ok := validatorMapSmartnic["MacRange"][ver]; ok {
		for _, v := range vs {
			if err := v(path, m); err != nil {
				ret = append(ret, err)
			}
		}
	} else if vs, ok := validatorMapSmartnic["MacRange"]["all"]; ok {
		for _, v := range vs {
			if err := v(path, m); err != nil {
				ret = append(ret, err)
			}
		}
	}
	return ret
}

func (m *MacRange) Normalize() {

}

// Transformers

func init() {
	scheme := runtime.GetDefaultScheme()
	scheme.AddKnownTypes(
		&DistributedServiceCard{},
	)

	validatorMapSmartnic = make(map[string]map[string][]func(string, interface{}) error)

	validatorMapSmartnic["DSCCondition"] = make(map[string][]func(string, interface{}) error)
	validatorMapSmartnic["DSCCondition"]["all"] = append(validatorMapSmartnic["DSCCondition"]["all"], func(path string, i interface{}) error {
		m := i.(*DSCCondition)

		if _, ok := ConditionStatus_vvalue[m.Status]; !ok {
			vals := []string{}
			for k1, _ := range ConditionStatus_vvalue {
				vals = append(vals, k1)
			}
			return fmt.Errorf("%v did not match allowed strings %v", path+"."+"Status", vals)
		}
		return nil
	})

	validatorMapSmartnic["DSCCondition"]["all"] = append(validatorMapSmartnic["DSCCondition"]["all"], func(path string, i interface{}) error {
		m := i.(*DSCCondition)

		if _, ok := DSCCondition_ConditionType_vvalue[m.Type]; !ok {
			vals := []string{}
			for k1, _ := range DSCCondition_ConditionType_vvalue {
				vals = append(vals, k1)
			}
			return fmt.Errorf("%v did not match allowed strings %v", path+"."+"Type", vals)
		}
		return nil
	})

	validatorMapSmartnic["DistributedServiceCardSpec"] = make(map[string][]func(string, interface{}) error)
	validatorMapSmartnic["DistributedServiceCardSpec"]["all"] = append(validatorMapSmartnic["DistributedServiceCardSpec"]["all"], func(path string, i interface{}) error {
		m := i.(*DistributedServiceCardSpec)

		if _, ok := DistributedServiceCardSpec_MgmtModes_vvalue[m.MgmtMode]; !ok {
			vals := []string{}
			for k1, _ := range DistributedServiceCardSpec_MgmtModes_vvalue {
				vals = append(vals, k1)
			}
			return fmt.Errorf("%v did not match allowed strings %v", path+"."+"MgmtMode", vals)
		}
		return nil
	})

	validatorMapSmartnic["DistributedServiceCardSpec"]["all"] = append(validatorMapSmartnic["DistributedServiceCardSpec"]["all"], func(path string, i interface{}) error {
		m := i.(*DistributedServiceCardSpec)
		args := make([]string, 0)
		args = append(args, "0")
		args = append(args, "4095")

		if err := validators.IntRange(m.MgmtVlan, args); err != nil {
			return fmt.Errorf("%v failed validation: %s", path+"."+"MgmtVlan", err.Error())
		}
		return nil
	})

	validatorMapSmartnic["DistributedServiceCardSpec"]["all"] = append(validatorMapSmartnic["DistributedServiceCardSpec"]["all"], func(path string, i interface{}) error {
		m := i.(*DistributedServiceCardSpec)

		if _, ok := DistributedServiceCardSpec_NetworkModes_vvalue[m.NetworkMode]; !ok {
			vals := []string{}
			for k1, _ := range DistributedServiceCardSpec_NetworkModes_vvalue {
				vals = append(vals, k1)
			}
			return fmt.Errorf("%v did not match allowed strings %v", path+"."+"NetworkMode", vals)
		}
		return nil
	})

	validatorMapSmartnic["DistributedServiceCardStatus"] = make(map[string][]func(string, interface{}) error)
	validatorMapSmartnic["DistributedServiceCardStatus"]["all"] = append(validatorMapSmartnic["DistributedServiceCardStatus"]["all"], func(path string, i interface{}) error {
		m := i.(*DistributedServiceCardStatus)

		if _, ok := DistributedServiceCardStatus_Phase_vvalue[m.AdmissionPhase]; !ok {
			vals := []string{}
			for k1, _ := range DistributedServiceCardStatus_Phase_vvalue {
				vals = append(vals, k1)
			}
			return fmt.Errorf("%v did not match allowed strings %v", path+"."+"AdmissionPhase", vals)
		}
		return nil
	})

	validatorMapSmartnic["DistributedServiceCardStatus"]["all"] = append(validatorMapSmartnic["DistributedServiceCardStatus"]["all"], func(path string, i interface{}) error {
		m := i.(*DistributedServiceCardStatus)
		if err := validators.EmptyOr(validators.MacAddr, m.PrimaryMAC, nil); err != nil {
			return fmt.Errorf("%v failed validation: %s", path+"."+"PrimaryMAC", err.Error())
		}
		return nil
	})

	validatorMapSmartnic["MacRange"] = make(map[string][]func(string, interface{}) error)

	validatorMapSmartnic["MacRange"]["all"] = append(validatorMapSmartnic["MacRange"]["all"], func(path string, i interface{}) error {
		m := i.(*MacRange)
		if err := validators.EmptyOr(validators.MacAddr, m.End, nil); err != nil {
			return fmt.Errorf("%v failed validation: %s", path+"."+"End", err.Error())
		}
		return nil
	})

	validatorMapSmartnic["MacRange"]["all"] = append(validatorMapSmartnic["MacRange"]["all"], func(path string, i interface{}) error {
		m := i.(*MacRange)
		if err := validators.EmptyOr(validators.MacAddr, m.Start, nil); err != nil {
			return fmt.Errorf("%v failed validation: %s", path+"."+"Start", err.Error())
		}
		return nil
	})

}
