// Code generated by protoc-gen-grpc-pensando DO NOT EDIT.

/*
Package monitoring is a auto generated package.
Input file: protos/mirror.proto
*/
package monitoring

import (
	fmt "fmt"

	listerwatcher "github.com/pensando/sw/api/listerwatcher"
	"github.com/pensando/sw/venice/utils/kvstore"
	"github.com/pensando/sw/venice/utils/log"

	validators "github.com/pensando/sw/venice/utils/apigen/validators"

	"github.com/pensando/sw/venice/globals"
)

// Dummy definitions to suppress nonused warnings
var _ kvstore.Interface
var _ log.Logger
var _ listerwatcher.WatcherClient

var _ validators.DummyVar
var validatorMapMirror = make(map[string]map[string][]func(interface{}) bool)

// MakeKey generates a KV store key for the object
func (m *MirrorSession) MakeKey(prefix string) string {
	return fmt.Sprint(globals.RootPrefix, "/", prefix, "/", "MirrorSession/", m.Tenant, "/", m.Name)
}

// MakeKey generates a KV store key for the object
func (m *MirrorSessionList) MakeKey(prefix string) string {
	obj := MirrorSession{}
	return obj.MakeKey(prefix)
}

// MakeKey generates a KV store key for the object
func (m *AutoMsgMirrorSessionWatchHelper) MakeKey(prefix string) string {
	obj := MirrorSession{}
	return obj.MakeKey(prefix)
}

// Clone clones the object into into or creates one of into is nil
func (m *AppProtoSelector) Clone(into interface{}) (interface{}, error) {
	var out *AppProtoSelector
	var ok bool
	if into == nil {
		out = &AppProtoSelector{}
	} else {
		out, ok = into.(*AppProtoSelector)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *AppProtoSelector) Defaults(ver string) bool {
	return false
}

// Clone clones the object into into or creates one of into is nil
func (m *AutoMsgMirrorSessionWatchHelper) Clone(into interface{}) (interface{}, error) {
	var out *AutoMsgMirrorSessionWatchHelper
	var ok bool
	if into == nil {
		out = &AutoMsgMirrorSessionWatchHelper{}
	} else {
		out, ok = into.(*AutoMsgMirrorSessionWatchHelper)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *AutoMsgMirrorSessionWatchHelper) Defaults(ver string) bool {
	var ret bool
	if m.Object != nil {
		ret = ret || m.Object.Defaults(ver)
	}
	return ret
}

// Clone clones the object into into or creates one of into is nil
func (m *MatchRule) Clone(into interface{}) (interface{}, error) {
	var out *MatchRule
	var ok bool
	if into == nil {
		out = &MatchRule{}
	} else {
		out, ok = into.(*MatchRule)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *MatchRule) Defaults(ver string) bool {
	return false
}

// Clone clones the object into into or creates one of into is nil
func (m *MatchSelector) Clone(into interface{}) (interface{}, error) {
	var out *MatchSelector
	var ok bool
	if into == nil {
		out = &MatchSelector{}
	} else {
		out, ok = into.(*MatchSelector)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *MatchSelector) Defaults(ver string) bool {
	return false
}

// Clone clones the object into into or creates one of into is nil
func (m *MirrorCollector) Clone(into interface{}) (interface{}, error) {
	var out *MirrorCollector
	var ok bool
	if into == nil {
		out = &MirrorCollector{}
	} else {
		out, ok = into.(*MirrorCollector)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *MirrorCollector) Defaults(ver string) bool {
	var ret bool
	ret = true
	switch ver {
	default:
		m.Type = MirrorCollector_PacketCollectorType_name[0]
	}
	return ret
}

// Clone clones the object into into or creates one of into is nil
func (m *MirrorSession) Clone(into interface{}) (interface{}, error) {
	var out *MirrorSession
	var ok bool
	if into == nil {
		out = &MirrorSession{}
	} else {
		out, ok = into.(*MirrorSession)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *MirrorSession) Defaults(ver string) bool {
	var ret bool
	ret = ret || m.Spec.Defaults(ver)
	ret = ret || m.Status.Defaults(ver)
	return ret
}

// Clone clones the object into into or creates one of into is nil
func (m *MirrorSessionList) Clone(into interface{}) (interface{}, error) {
	var out *MirrorSessionList
	var ok bool
	if into == nil {
		out = &MirrorSessionList{}
	} else {
		out, ok = into.(*MirrorSessionList)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *MirrorSessionList) Defaults(ver string) bool {
	var ret bool
	for k := range m.Items {
		if m.Items[k] != nil {
			ret = ret || m.Items[k].Defaults(ver)
		}
	}
	return ret
}

// Clone clones the object into into or creates one of into is nil
func (m *MirrorSessionSpec) Clone(into interface{}) (interface{}, error) {
	var out *MirrorSessionSpec
	var ok bool
	if into == nil {
		out = &MirrorSessionSpec{}
	} else {
		out, ok = into.(*MirrorSessionSpec)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *MirrorSessionSpec) Defaults(ver string) bool {
	var ret bool
	for k := range m.Collectors {
		ret = ret || m.Collectors[k].Defaults(ver)
	}
	ret = true
	switch ver {
	default:
		for k := range m.PacketFilters {
			m.PacketFilters[k] = MirrorSessionSpec_MirrorPacketFilter_name[0]
		}
	}
	return ret
}

// Clone clones the object into into or creates one of into is nil
func (m *MirrorSessionStatus) Clone(into interface{}) (interface{}, error) {
	var out *MirrorSessionStatus
	var ok bool
	if into == nil {
		out = &MirrorSessionStatus{}
	} else {
		out, ok = into.(*MirrorSessionStatus)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *MirrorSessionStatus) Defaults(ver string) bool {
	var ret bool
	ret = true
	switch ver {
	default:
		m.State = MirrorSessionState_name[0]
	}
	return ret
}

// Clone clones the object into into or creates one of into is nil
func (m *MirrorStartConditions) Clone(into interface{}) (interface{}, error) {
	var out *MirrorStartConditions
	var ok bool
	if into == nil {
		out = &MirrorStartConditions{}
	} else {
		out, ok = into.(*MirrorStartConditions)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *MirrorStartConditions) Defaults(ver string) bool {
	return false
}

// Clone clones the object into into or creates one of into is nil
func (m *MirrorStopConditions) Clone(into interface{}) (interface{}, error) {
	var out *MirrorStopConditions
	var ok bool
	if into == nil {
		out = &MirrorStopConditions{}
	} else {
		out, ok = into.(*MirrorStopConditions)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *MirrorStopConditions) Defaults(ver string) bool {
	return false
}

// Clone clones the object into into or creates one of into is nil
func (m *SmartNICMirrorSessionStatus) Clone(into interface{}) (interface{}, error) {
	var out *SmartNICMirrorSessionStatus
	var ok bool
	if into == nil {
		out = &SmartNICMirrorSessionStatus{}
	} else {
		out, ok = into.(*SmartNICMirrorSessionStatus)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *SmartNICMirrorSessionStatus) Defaults(ver string) bool {
	return false
}

// Validators

func (m *AppProtoSelector) Validate(ver string, ignoreStatus bool) bool {
	return true
}

func (m *AutoMsgMirrorSessionWatchHelper) Validate(ver string, ignoreStatus bool) bool {
	if m.Object != nil && !m.Object.Validate(ver, ignoreStatus) {
		return false
	}
	return true
}

func (m *MatchRule) Validate(ver string, ignoreStatus bool) bool {
	return true
}

func (m *MatchSelector) Validate(ver string, ignoreStatus bool) bool {
	return true
}

func (m *MirrorCollector) Validate(ver string, ignoreStatus bool) bool {
	if vs, ok := validatorMapMirror["MirrorCollector"][ver]; ok {
		for _, v := range vs {
			if !v(m) {
				return false
			}
		}
	} else if vs, ok := validatorMapMirror["MirrorCollector"]["all"]; ok {
		for _, v := range vs {
			if !v(m) {
				return false
			}
		}
	}
	return true
}

func (m *MirrorSession) Validate(ver string, ignoreStatus bool) bool {
	if !m.Spec.Validate(ver, ignoreStatus) {
		return false
	}
	if !ignoreStatus {
		if !m.Status.Validate(ver, ignoreStatus) {
			return false
		}
	}
	return true
}

func (m *MirrorSessionList) Validate(ver string, ignoreStatus bool) bool {
	for _, v := range m.Items {
		if !v.Validate(ver, ignoreStatus) {
			return false
		}
	}
	return true
}

func (m *MirrorSessionSpec) Validate(ver string, ignoreStatus bool) bool {
	for _, v := range m.Collectors {
		if !v.Validate(ver, ignoreStatus) {
			return false
		}
	}
	if vs, ok := validatorMapMirror["MirrorSessionSpec"][ver]; ok {
		for _, v := range vs {
			if !v(m) {
				return false
			}
		}
	} else if vs, ok := validatorMapMirror["MirrorSessionSpec"]["all"]; ok {
		for _, v := range vs {
			if !v(m) {
				return false
			}
		}
	}
	return true
}

func (m *MirrorSessionStatus) Validate(ver string, ignoreStatus bool) bool {
	if vs, ok := validatorMapMirror["MirrorSessionStatus"][ver]; ok {
		for _, v := range vs {
			if !v(m) {
				return false
			}
		}
	} else if vs, ok := validatorMapMirror["MirrorSessionStatus"]["all"]; ok {
		for _, v := range vs {
			if !v(m) {
				return false
			}
		}
	}
	return true
}

func (m *MirrorStartConditions) Validate(ver string, ignoreStatus bool) bool {
	return true
}

func (m *MirrorStopConditions) Validate(ver string, ignoreStatus bool) bool {
	return true
}

func (m *SmartNICMirrorSessionStatus) Validate(ver string, ignoreStatus bool) bool {
	return true
}

func init() {

	validatorMapMirror = make(map[string]map[string][]func(interface{}) bool)

	validatorMapMirror["MirrorCollector"] = make(map[string][]func(interface{}) bool)
	validatorMapMirror["MirrorCollector"]["all"] = append(validatorMapMirror["MirrorCollector"]["all"], func(i interface{}) bool {
		m := i.(*MirrorCollector)

		if _, ok := MirrorCollector_PacketCollectorType_value[m.Type]; !ok {
			return false
		}
		return true
	})

	validatorMapMirror["MirrorSessionSpec"] = make(map[string][]func(interface{}) bool)
	validatorMapMirror["MirrorSessionSpec"]["all"] = append(validatorMapMirror["MirrorSessionSpec"]["all"], func(i interface{}) bool {
		m := i.(*MirrorSessionSpec)

		for _, v := range m.PacketFilters {
			if _, ok := MirrorSessionSpec_MirrorPacketFilter_value[v]; !ok {
				return false
			}
		}
		return true
	})

	validatorMapMirror["MirrorSessionStatus"] = make(map[string][]func(interface{}) bool)
	validatorMapMirror["MirrorSessionStatus"]["all"] = append(validatorMapMirror["MirrorSessionStatus"]["all"], func(i interface{}) bool {
		m := i.(*MirrorSessionStatus)

		if _, ok := MirrorSessionState_value[m.State]; !ok {
			return false
		}
		return true
	})

}
