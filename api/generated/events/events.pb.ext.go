// Code generated by protoc-gen-grpc-pensando DO NOT EDIT.

/*
Package events is a auto generated package.
Input file: protos/events.proto
*/
package events

import (
	fmt "fmt"

	listerwatcher "github.com/pensando/sw/api/listerwatcher"
	"github.com/pensando/sw/venice/utils/kvstore"
	"github.com/pensando/sw/venice/utils/log"

	"github.com/pensando/sw/venice/globals"
	validators "github.com/pensando/sw/venice/utils/apigen/validators"
)

// Dummy definitions to suppress nonused warnings
var _ kvstore.Interface
var _ log.Logger
var _ listerwatcher.WatcherClient

var _ validators.DummyVar
var funcMapEvents = make(map[string]map[string][]func(interface{}) bool)

// MakeKey generates a KV store key for the object
func (m *Event) MakeKey(prefix string) string {
	return fmt.Sprint(globals.RootPrefix, "/", prefix, "/", "events/", m.Tenant, "/", m.Name)
}

// MakeKey generates a KV store key for the object
func (m *EventPolicy) MakeKey(prefix string) string {
	return fmt.Sprint(globals.RootPrefix, "/", prefix, "/", "eventPolicy/", m.Tenant, "/", m.Name)
}

// MakeKey generates a KV store key for the object
func (m *EventPolicyList) MakeKey(prefix string) string {
	obj := EventPolicy{}
	return obj.MakeKey(prefix)
}

// MakeKey generates a KV store key for the object
func (m *AutoMsgEventPolicyWatchHelper) MakeKey(prefix string) string {
	obj := EventPolicy{}
	return obj.MakeKey(prefix)
}

// Clone clones the object into into or creates one of into is nil
func (m *AutoMsgEventPolicyWatchHelper) Clone(into interface{}) (interface{}, error) {
	var out *AutoMsgEventPolicyWatchHelper
	var ok bool
	if into == nil {
		out = &AutoMsgEventPolicyWatchHelper{}
	} else {
		out, ok = into.(*AutoMsgEventPolicyWatchHelper)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *AutoMsgEventPolicyWatchHelper) Defaults(ver string) bool {
	var ret bool
	for m.Object != nil {
		ret = ret || m.Object.Defaults(ver)
	}
	return ret
}

// Clone clones the object into into or creates one of into is nil
func (m *Event) Clone(into interface{}) (interface{}, error) {
	var out *Event
	var ok bool
	if into == nil {
		out = &Event{}
	} else {
		out, ok = into.(*Event)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *Event) Defaults(ver string) bool {
	var ret bool
	ret = ret || m.EventAttributes.Defaults(ver)
	return ret
}

// Clone clones the object into into or creates one of into is nil
func (m *EventAttributes) Clone(into interface{}) (interface{}, error) {
	var out *EventAttributes
	var ok bool
	if into == nil {
		out = &EventAttributes{}
	} else {
		out, ok = into.(*EventAttributes)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *EventAttributes) Defaults(ver string) bool {
	var ret bool
	ret = true
	switch ver {
	default:
		m.Severity = SeverityLevel_name[0]
	}
	return ret
}

// Clone clones the object into into or creates one of into is nil
func (m *EventExport) Clone(into interface{}) (interface{}, error) {
	var out *EventExport
	var ok bool
	if into == nil {
		out = &EventExport{}
	} else {
		out, ok = into.(*EventExport)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *EventExport) Defaults(ver string) bool {
	var ret bool
	ret = true
	switch ver {
	default:
		m.Format = EventExportFormat_name[0]
	}
	return ret
}

// Clone clones the object into into or creates one of into is nil
func (m *EventPolicy) Clone(into interface{}) (interface{}, error) {
	var out *EventPolicy
	var ok bool
	if into == nil {
		out = &EventPolicy{}
	} else {
		out, ok = into.(*EventPolicy)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *EventPolicy) Defaults(ver string) bool {
	var ret bool
	ret = ret || m.Spec.Defaults(ver)
	return ret
}

// Clone clones the object into into or creates one of into is nil
func (m *EventPolicyList) Clone(into interface{}) (interface{}, error) {
	var out *EventPolicyList
	var ok bool
	if into == nil {
		out = &EventPolicyList{}
	} else {
		out, ok = into.(*EventPolicyList)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *EventPolicyList) Defaults(ver string) bool {
	var ret bool
	for k := range m.Items {
		if m.Items[k] != nil {
			ret = ret || m.Items[k].Defaults(ver)
		}
	}
	return ret
}

// Clone clones the object into into or creates one of into is nil
func (m *EventPolicySpec) Clone(into interface{}) (interface{}, error) {
	var out *EventPolicySpec
	var ok bool
	if into == nil {
		out = &EventPolicySpec{}
	} else {
		out, ok = into.(*EventPolicySpec)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *EventPolicySpec) Defaults(ver string) bool {
	var ret bool
	for k := range m.Exports {
		if m.Exports[k] != nil {
			ret = ret || m.Exports[k].Defaults(ver)
		}
	}
	return ret
}

// Clone clones the object into into or creates one of into is nil
func (m *EventPolicyStatus) Clone(into interface{}) (interface{}, error) {
	var out *EventPolicyStatus
	var ok bool
	if into == nil {
		out = &EventPolicyStatus{}
	} else {
		out, ok = into.(*EventPolicyStatus)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *EventPolicyStatus) Defaults(ver string) bool {
	return false
}

// Clone clones the object into into or creates one of into is nil
func (m *EventSource) Clone(into interface{}) (interface{}, error) {
	var out *EventSource
	var ok bool
	if into == nil {
		out = &EventSource{}
	} else {
		out, ok = into.(*EventSource)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *EventSource) Defaults(ver string) bool {
	return false
}

// Validators

func (m *AutoMsgEventPolicyWatchHelper) Validate(ver string, ignoreStatus bool) bool {
	if m.Object != nil && !m.Object.Validate(ver, ignoreStatus) {
		return false
	}
	return true
}

func (m *Event) Validate(ver string, ignoreStatus bool) bool {
	if !m.EventAttributes.Validate(ver, ignoreStatus) {
		return false
	}
	return true
}

func (m *EventAttributes) Validate(ver string, ignoreStatus bool) bool {
	if vs, ok := funcMapEvents["EventAttributes"][ver]; ok {
		for _, v := range vs {
			if !v(m) {
				return false
			}
		}
	} else if vs, ok := funcMapEvents["EventAttributes"]["all"]; ok {
		for _, v := range vs {
			if !v(m) {
				return false
			}
		}
	}
	return true
}

func (m *EventExport) Validate(ver string, ignoreStatus bool) bool {
	if m.Selector != nil && !m.Selector.Validate(ver, ignoreStatus) {
		return false
	}
	if vs, ok := funcMapEvents["EventExport"][ver]; ok {
		for _, v := range vs {
			if !v(m) {
				return false
			}
		}
	} else if vs, ok := funcMapEvents["EventExport"]["all"]; ok {
		for _, v := range vs {
			if !v(m) {
				return false
			}
		}
	}
	return true
}

func (m *EventPolicy) Validate(ver string, ignoreStatus bool) bool {
	if !m.Spec.Validate(ver, ignoreStatus) {
		return false
	}
	return true
}

func (m *EventPolicyList) Validate(ver string, ignoreStatus bool) bool {
	for _, v := range m.Items {
		if !v.Validate(ver, ignoreStatus) {
			return false
		}
	}
	return true
}

func (m *EventPolicySpec) Validate(ver string, ignoreStatus bool) bool {
	for _, v := range m.Exports {
		if !v.Validate(ver, ignoreStatus) {
			return false
		}
	}
	return true
}

func (m *EventPolicyStatus) Validate(ver string, ignoreStatus bool) bool {
	return true
}

func (m *EventSource) Validate(ver string, ignoreStatus bool) bool {
	return true
}

func init() {
	funcMapEvents = make(map[string]map[string][]func(interface{}) bool)

	funcMapEvents["EventAttributes"] = make(map[string][]func(interface{}) bool)
	funcMapEvents["EventAttributes"]["all"] = append(funcMapEvents["EventAttributes"]["all"], func(i interface{}) bool {
		m := i.(*EventAttributes)

		if _, ok := SeverityLevel_value[m.Severity]; !ok {
			return false
		}
		return true
	})

	funcMapEvents["EventExport"] = make(map[string][]func(interface{}) bool)
	funcMapEvents["EventExport"]["all"] = append(funcMapEvents["EventExport"]["all"], func(i interface{}) bool {
		m := i.(*EventExport)

		if _, ok := EventExportFormat_value[m.Format]; !ok {
			return false
		}
		return true
	})

}
