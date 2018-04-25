// Code generated by protoc-gen-grpc-pensando DO NOT EDIT.

/*
Package monitoring is a auto generated package.
Input file: svc_monitoring.proto
*/
package monitoring

import (
	fmt "fmt"

	listerwatcher "github.com/pensando/sw/api/listerwatcher"
	"github.com/pensando/sw/venice/utils/kvstore"
	"github.com/pensando/sw/venice/utils/log"
)

// Dummy definitions to suppress nonused warnings
var _ kvstore.Interface
var _ log.Logger
var _ listerwatcher.WatcherClient

// MakeKey generates a KV store key for the object
func (m *AlertDestinationList) MakeKey(prefix string) string {
	obj := AlertDestination{}
	return obj.MakeKey(prefix)
}

// MakeKey generates a KV store key for the object
func (m *AlertList) MakeKey(prefix string) string {
	obj := Alert{}
	return obj.MakeKey(prefix)
}

// MakeKey generates a KV store key for the object
func (m *AlertPolicyList) MakeKey(prefix string) string {
	obj := AlertPolicy{}
	return obj.MakeKey(prefix)
}

// MakeKey generates a KV store key for the object
func (m *EventList) MakeKey(prefix string) string {
	obj := Event{}
	return obj.MakeKey(prefix)
}

// MakeKey generates a KV store key for the object
func (m *EventPolicyList) MakeKey(prefix string) string {
	obj := EventPolicy{}
	return obj.MakeKey(prefix)
}

// MakeKey generates a KV store key for the object
func (m *FlowExportPolicyList) MakeKey(prefix string) string {
	obj := FlowExportPolicy{}
	return obj.MakeKey(prefix)
}

// MakeKey generates a KV store key for the object
func (m *FwlogPolicyList) MakeKey(prefix string) string {
	obj := FwlogPolicy{}
	return obj.MakeKey(prefix)
}

// MakeKey generates a KV store key for the object
func (m *StatsPolicyList) MakeKey(prefix string) string {
	obj := StatsPolicy{}
	return obj.MakeKey(prefix)
}

// MakeKey generates a KV store key for the object
func (m *AutoMsgAlertDestinationWatchHelper) MakeKey(prefix string) string {
	obj := AlertDestination{}
	return obj.MakeKey(prefix)
}

// MakeKey generates a KV store key for the object
func (m *AutoMsgAlertPolicyWatchHelper) MakeKey(prefix string) string {
	obj := AlertPolicy{}
	return obj.MakeKey(prefix)
}

// MakeKey generates a KV store key for the object
func (m *AutoMsgAlertWatchHelper) MakeKey(prefix string) string {
	obj := Alert{}
	return obj.MakeKey(prefix)
}

// MakeKey generates a KV store key for the object
func (m *AutoMsgEventPolicyWatchHelper) MakeKey(prefix string) string {
	obj := EventPolicy{}
	return obj.MakeKey(prefix)
}

// MakeKey generates a KV store key for the object
func (m *AutoMsgEventWatchHelper) MakeKey(prefix string) string {
	obj := Event{}
	return obj.MakeKey(prefix)
}

// MakeKey generates a KV store key for the object
func (m *AutoMsgFlowExportPolicyWatchHelper) MakeKey(prefix string) string {
	obj := FlowExportPolicy{}
	return obj.MakeKey(prefix)
}

// MakeKey generates a KV store key for the object
func (m *AutoMsgFwlogPolicyWatchHelper) MakeKey(prefix string) string {
	obj := FwlogPolicy{}
	return obj.MakeKey(prefix)
}

// MakeKey generates a KV store key for the object
func (m *AutoMsgStatsPolicyWatchHelper) MakeKey(prefix string) string {
	obj := StatsPolicy{}
	return obj.MakeKey(prefix)
}

// Clone clones the object into into or creates one of into is nil
func (m *AlertDestinationList) Clone(into interface{}) (interface{}, error) {
	var out *AlertDestinationList
	var ok bool
	if into == nil {
		out = &AlertDestinationList{}
	} else {
		out, ok = into.(*AlertDestinationList)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *AlertDestinationList) Defaults(ver string) bool {
	return false
}

// Clone clones the object into into or creates one of into is nil
func (m *AlertList) Clone(into interface{}) (interface{}, error) {
	var out *AlertList
	var ok bool
	if into == nil {
		out = &AlertList{}
	} else {
		out, ok = into.(*AlertList)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *AlertList) Defaults(ver string) bool {
	return false
}

// Clone clones the object into into or creates one of into is nil
func (m *AlertPolicyList) Clone(into interface{}) (interface{}, error) {
	var out *AlertPolicyList
	var ok bool
	if into == nil {
		out = &AlertPolicyList{}
	} else {
		out, ok = into.(*AlertPolicyList)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *AlertPolicyList) Defaults(ver string) bool {
	return false
}

// Clone clones the object into into or creates one of into is nil
func (m *AutoMsgAlertDestinationWatchHelper) Clone(into interface{}) (interface{}, error) {
	var out *AutoMsgAlertDestinationWatchHelper
	var ok bool
	if into == nil {
		out = &AutoMsgAlertDestinationWatchHelper{}
	} else {
		out, ok = into.(*AutoMsgAlertDestinationWatchHelper)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *AutoMsgAlertDestinationWatchHelper) Defaults(ver string) bool {
	return false
}

// Clone clones the object into into or creates one of into is nil
func (m *AutoMsgAlertPolicyWatchHelper) Clone(into interface{}) (interface{}, error) {
	var out *AutoMsgAlertPolicyWatchHelper
	var ok bool
	if into == nil {
		out = &AutoMsgAlertPolicyWatchHelper{}
	} else {
		out, ok = into.(*AutoMsgAlertPolicyWatchHelper)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *AutoMsgAlertPolicyWatchHelper) Defaults(ver string) bool {
	return false
}

// Clone clones the object into into or creates one of into is nil
func (m *AutoMsgAlertWatchHelper) Clone(into interface{}) (interface{}, error) {
	var out *AutoMsgAlertWatchHelper
	var ok bool
	if into == nil {
		out = &AutoMsgAlertWatchHelper{}
	} else {
		out, ok = into.(*AutoMsgAlertWatchHelper)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *AutoMsgAlertWatchHelper) Defaults(ver string) bool {
	return false
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
	return false
}

// Clone clones the object into into or creates one of into is nil
func (m *AutoMsgEventWatchHelper) Clone(into interface{}) (interface{}, error) {
	var out *AutoMsgEventWatchHelper
	var ok bool
	if into == nil {
		out = &AutoMsgEventWatchHelper{}
	} else {
		out, ok = into.(*AutoMsgEventWatchHelper)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *AutoMsgEventWatchHelper) Defaults(ver string) bool {
	return false
}

// Clone clones the object into into or creates one of into is nil
func (m *AutoMsgFlowExportPolicyWatchHelper) Clone(into interface{}) (interface{}, error) {
	var out *AutoMsgFlowExportPolicyWatchHelper
	var ok bool
	if into == nil {
		out = &AutoMsgFlowExportPolicyWatchHelper{}
	} else {
		out, ok = into.(*AutoMsgFlowExportPolicyWatchHelper)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *AutoMsgFlowExportPolicyWatchHelper) Defaults(ver string) bool {
	return false
}

// Clone clones the object into into or creates one of into is nil
func (m *AutoMsgFwlogPolicyWatchHelper) Clone(into interface{}) (interface{}, error) {
	var out *AutoMsgFwlogPolicyWatchHelper
	var ok bool
	if into == nil {
		out = &AutoMsgFwlogPolicyWatchHelper{}
	} else {
		out, ok = into.(*AutoMsgFwlogPolicyWatchHelper)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *AutoMsgFwlogPolicyWatchHelper) Defaults(ver string) bool {
	return false
}

// Clone clones the object into into or creates one of into is nil
func (m *AutoMsgStatsPolicyWatchHelper) Clone(into interface{}) (interface{}, error) {
	var out *AutoMsgStatsPolicyWatchHelper
	var ok bool
	if into == nil {
		out = &AutoMsgStatsPolicyWatchHelper{}
	} else {
		out, ok = into.(*AutoMsgStatsPolicyWatchHelper)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *AutoMsgStatsPolicyWatchHelper) Defaults(ver string) bool {
	return false
}

// Clone clones the object into into or creates one of into is nil
func (m *EventList) Clone(into interface{}) (interface{}, error) {
	var out *EventList
	var ok bool
	if into == nil {
		out = &EventList{}
	} else {
		out, ok = into.(*EventList)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *EventList) Defaults(ver string) bool {
	return false
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
	return false
}

// Clone clones the object into into or creates one of into is nil
func (m *FlowExportPolicyList) Clone(into interface{}) (interface{}, error) {
	var out *FlowExportPolicyList
	var ok bool
	if into == nil {
		out = &FlowExportPolicyList{}
	} else {
		out, ok = into.(*FlowExportPolicyList)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *FlowExportPolicyList) Defaults(ver string) bool {
	return false
}

// Clone clones the object into into or creates one of into is nil
func (m *FwlogPolicyList) Clone(into interface{}) (interface{}, error) {
	var out *FwlogPolicyList
	var ok bool
	if into == nil {
		out = &FwlogPolicyList{}
	} else {
		out, ok = into.(*FwlogPolicyList)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *FwlogPolicyList) Defaults(ver string) bool {
	return false
}

// Clone clones the object into into or creates one of into is nil
func (m *StatsPolicyList) Clone(into interface{}) (interface{}, error) {
	var out *StatsPolicyList
	var ok bool
	if into == nil {
		out = &StatsPolicyList{}
	} else {
		out, ok = into.(*StatsPolicyList)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *StatsPolicyList) Defaults(ver string) bool {
	return false
}

// Validators

func (m *AlertDestinationList) Validate(ver string, ignoreStatus bool) bool {
	for _, v := range m.Items {
		if !v.Validate(ver, ignoreStatus) {
			return false
		}
	}
	return true
}

func (m *AlertList) Validate(ver string, ignoreStatus bool) bool {
	for _, v := range m.Items {
		if !v.Validate(ver, ignoreStatus) {
			return false
		}
	}
	return true
}

func (m *AlertPolicyList) Validate(ver string, ignoreStatus bool) bool {
	for _, v := range m.Items {
		if !v.Validate(ver, ignoreStatus) {
			return false
		}
	}
	return true
}

func (m *AutoMsgAlertDestinationWatchHelper) Validate(ver string, ignoreStatus bool) bool {
	if m.Object != nil && !m.Object.Validate(ver, ignoreStatus) {
		return false
	}
	return true
}

func (m *AutoMsgAlertPolicyWatchHelper) Validate(ver string, ignoreStatus bool) bool {
	if m.Object != nil && !m.Object.Validate(ver, ignoreStatus) {
		return false
	}
	return true
}

func (m *AutoMsgAlertWatchHelper) Validate(ver string, ignoreStatus bool) bool {
	if m.Object != nil && !m.Object.Validate(ver, ignoreStatus) {
		return false
	}
	return true
}

func (m *AutoMsgEventPolicyWatchHelper) Validate(ver string, ignoreStatus bool) bool {
	if m.Object != nil && !m.Object.Validate(ver, ignoreStatus) {
		return false
	}
	return true
}

func (m *AutoMsgEventWatchHelper) Validate(ver string, ignoreStatus bool) bool {
	if m.Object != nil && !m.Object.Validate(ver, ignoreStatus) {
		return false
	}
	return true
}

func (m *AutoMsgFlowExportPolicyWatchHelper) Validate(ver string, ignoreStatus bool) bool {
	if m.Object != nil && !m.Object.Validate(ver, ignoreStatus) {
		return false
	}
	return true
}

func (m *AutoMsgFwlogPolicyWatchHelper) Validate(ver string, ignoreStatus bool) bool {
	if m.Object != nil && !m.Object.Validate(ver, ignoreStatus) {
		return false
	}
	return true
}

func (m *AutoMsgStatsPolicyWatchHelper) Validate(ver string, ignoreStatus bool) bool {
	return true
}

func (m *EventList) Validate(ver string, ignoreStatus bool) bool {
	for _, v := range m.Items {
		if !v.Validate(ver, ignoreStatus) {
			return false
		}
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

func (m *FlowExportPolicyList) Validate(ver string, ignoreStatus bool) bool {
	for _, v := range m.Items {
		if !v.Validate(ver, ignoreStatus) {
			return false
		}
	}
	return true
}

func (m *FwlogPolicyList) Validate(ver string, ignoreStatus bool) bool {
	for _, v := range m.Items {
		if !v.Validate(ver, ignoreStatus) {
			return false
		}
	}
	return true
}

func (m *StatsPolicyList) Validate(ver string, ignoreStatus bool) bool {
	return true
}

func init() {

}
