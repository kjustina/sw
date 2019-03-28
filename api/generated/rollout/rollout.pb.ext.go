// Code generated by protoc-gen-grpc-pensando DO NOT EDIT.

/*
Package rollout is a auto generated package.
Input file: rollout.proto
*/
package rollout

import (
	"errors"
	fmt "fmt"
	"strings"

	listerwatcher "github.com/pensando/sw/api/listerwatcher"
	"github.com/pensando/sw/venice/utils/kvstore"
	"github.com/pensando/sw/venice/utils/log"

	validators "github.com/pensando/sw/venice/utils/apigen/validators"

	"github.com/pensando/sw/api/interfaces"
	"github.com/pensando/sw/venice/globals"
	"github.com/pensando/sw/venice/utils/runtime"
)

// Dummy definitions to suppress nonused warnings
var _ kvstore.Interface
var _ log.Logger
var _ listerwatcher.WatcherClient

// RolloutPhase_Phases_normal is a map of normalized values for the enum
var RolloutPhase_Phases_normal = map[string]string{
	"COMPLETE":           "COMPLETE",
	"DEPENDENCIES_CHECK": "DEPENDENCIES_CHECK",
	"FAIL":               "FAIL",
	"PRE_CHECK":          "PRE_CHECK",
	"PROGRESSING":        "PROGRESSING",
	"WAITING_FOR_TURN":   "WAITING_FOR_TURN",
	"complete":           "COMPLETE",
	"dependencies_check": "DEPENDENCIES_CHECK",
	"fail":               "FAIL",
	"pre_check":          "PRE_CHECK",
	"progressing":        "PROGRESSING",
	"waiting_for_turn":   "WAITING_FOR_TURN",
}

// RolloutSpec_StrategyType_normal is a map of normalized values for the enum
var RolloutSpec_StrategyType_normal = map[string]string{
	"EXPONENTIAL": "EXPONENTIAL",
	"LINEAR":      "LINEAR",
	"exponential": "EXPONENTIAL",
	"linear":      "LINEAR",
}

// RolloutSpec_SmartNICUpgradeType_normal is a map of normalized values for the enum
var RolloutSpec_SmartNICUpgradeType_normal = map[string]string{
	"Disruptive":       "Disruptive",
	"OnNextHostReboot": "OnNextHostReboot",
	"disruptive":       "Disruptive",
	"onnexthostreboot": "OnNextHostReboot",
}

// RolloutStatus_RolloutOperationalState_normal is a map of normalized values for the enum
var RolloutStatus_RolloutOperationalState_normal = map[string]string{
	"DEADLINE_EXCEEDED":   "DEADLINE_EXCEEDED",
	"FAILURE":             "FAILURE",
	"PROGRESSING":         "PROGRESSING",
	"SCHEDULED":           "SCHEDULED",
	"SUCCESS":             "SUCCESS",
	"SUSPENDED":           "SUSPENDED",
	"SUSPEND_IN_PROGRESS": "SUSPEND_IN_PROGRESS",
	"deadline_exceeded":   "DEADLINE_EXCEEDED",
	"failure":             "FAILURE",
	"progressing":         "PROGRESSING",
	"scheduled":           "SCHEDULED",
	"success":             "SUCCESS",
	"suspend_in_progress": "SUSPEND_IN_PROGRESS",
	"suspended":           "SUSPENDED",
}

var _ validators.DummyVar
var validatorMapRollout = make(map[string]map[string][]func(string, interface{}) error)

// MakeKey generates a KV store key for the object
func (m *Rollout) MakeKey(prefix string) string {
	return fmt.Sprint(globals.ConfigRootPrefix, "/", prefix, "/", "rollout/", m.Name)
}

func (m *Rollout) MakeURI(cat, ver, prefix string) string {
	in := m
	return fmt.Sprint("/", cat, "/", prefix, "/", ver, "/rollout/", in.Name)
}

// Clone clones the object into into or creates one of into is nil
func (m *Rollout) Clone(into interface{}) (interface{}, error) {
	var out *Rollout
	var ok bool
	if into == nil {
		out = &Rollout{}
	} else {
		out, ok = into.(*Rollout)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *Rollout) Defaults(ver string) bool {
	var ret bool
	m.Kind = "Rollout"
	ret = m.Tenant != "" || m.Namespace != ""
	if ret {
		m.Tenant, m.Namespace = "", ""
	}
	ret = m.Spec.Defaults(ver) || ret
	ret = m.Status.Defaults(ver) || ret
	return ret
}

// Clone clones the object into into or creates one of into is nil
func (m *RolloutPhase) Clone(into interface{}) (interface{}, error) {
	var out *RolloutPhase
	var ok bool
	if into == nil {
		out = &RolloutPhase{}
	} else {
		out, ok = into.(*RolloutPhase)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *RolloutPhase) Defaults(ver string) bool {
	var ret bool
	ret = true
	switch ver {
	default:
		m.Phase = "PRE_CHECK"
	}
	return ret
}

// Clone clones the object into into or creates one of into is nil
func (m *RolloutSpec) Clone(into interface{}) (interface{}, error) {
	var out *RolloutSpec
	var ok bool
	if into == nil {
		out = &RolloutSpec{}
	} else {
		out, ok = into.(*RolloutSpec)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *RolloutSpec) Defaults(ver string) bool {
	var ret bool
	ret = true
	switch ver {
	default:
		m.Strategy = "LINEAR"
		m.UpgradeType = "Disruptive"
	}
	return ret
}

// Clone clones the object into into or creates one of into is nil
func (m *RolloutStatus) Clone(into interface{}) (interface{}, error) {
	var out *RolloutStatus
	var ok bool
	if into == nil {
		out = &RolloutStatus{}
	} else {
		out, ok = into.(*RolloutStatus)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *RolloutStatus) Defaults(ver string) bool {
	var ret bool
	for k := range m.ControllerNodesStatus {
		if m.ControllerNodesStatus[k] != nil {
			i := m.ControllerNodesStatus[k]
			ret = i.Defaults(ver) || ret
		}
	}
	for k := range m.ControllerServicesStatus {
		if m.ControllerServicesStatus[k] != nil {
			i := m.ControllerServicesStatus[k]
			ret = i.Defaults(ver) || ret
		}
	}
	for k := range m.SmartNICsStatus {
		if m.SmartNICsStatus[k] != nil {
			i := m.SmartNICsStatus[k]
			ret = i.Defaults(ver) || ret
		}
	}
	ret = true
	switch ver {
	default:
		m.OperationalState = "PROGRESSING"
	}
	return ret
}

// Validators and Requirements

func (m *Rollout) References(tenant string, path string, resp map[string]apiintf.ReferenceObj) {

}

func (m *Rollout) Validate(ver, path string, ignoreStatus bool) []error {
	var ret []error

	if m.Tenant != "" {
		ret = append(ret, errors.New("Tenant not allowed for Rollout"))
	}
	if m.Namespace != "" {
		ret = append(ret, errors.New("Namespace not allowed for Rollout"))
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

func (m *Rollout) Normalize() {

	m.ObjectMeta.Normalize()

	m.Spec.Normalize()

	m.Status.Normalize()

}

func (m *RolloutPhase) References(tenant string, path string, resp map[string]apiintf.ReferenceObj) {

}

func (m *RolloutPhase) Validate(ver, path string, ignoreStatus bool) []error {
	var ret []error
	if vs, ok := validatorMapRollout["RolloutPhase"][ver]; ok {
		for _, v := range vs {
			if err := v(path, m); err != nil {
				ret = append(ret, err)
			}
		}
	} else if vs, ok := validatorMapRollout["RolloutPhase"]["all"]; ok {
		for _, v := range vs {
			if err := v(path, m); err != nil {
				ret = append(ret, err)
			}
		}
	}
	return ret
}

func (m *RolloutPhase) Normalize() {

	m.Phase = RolloutPhase_Phases_normal[strings.ToLower(m.Phase)]

}

func (m *RolloutSpec) References(tenant string, path string, resp map[string]apiintf.ReferenceObj) {

}

func (m *RolloutSpec) Validate(ver, path string, ignoreStatus bool) []error {
	var ret []error
	for k, v := range m.OrderConstraints {
		dlmtr := "."
		if path == "" {
			dlmtr = ""
		}
		npath := fmt.Sprintf("%s%sOrderConstraints[%v]", path, dlmtr, k)
		if errs := v.Validate(ver, npath, ignoreStatus); errs != nil {
			ret = append(ret, errs...)
		}
	}
	if vs, ok := validatorMapRollout["RolloutSpec"][ver]; ok {
		for _, v := range vs {
			if err := v(path, m); err != nil {
				ret = append(ret, err)
			}
		}
	} else if vs, ok := validatorMapRollout["RolloutSpec"]["all"]; ok {
		for _, v := range vs {
			if err := v(path, m); err != nil {
				ret = append(ret, err)
			}
		}
	}
	return ret
}

func (m *RolloutSpec) Normalize() {

	for _, v := range m.OrderConstraints {
		if v != nil {
			v.Normalize()
		}
	}

	m.Strategy = RolloutSpec_StrategyType_normal[strings.ToLower(m.Strategy)]

	m.UpgradeType = RolloutSpec_SmartNICUpgradeType_normal[strings.ToLower(m.UpgradeType)]

}

func (m *RolloutStatus) References(tenant string, path string, resp map[string]apiintf.ReferenceObj) {

}

func (m *RolloutStatus) Validate(ver, path string, ignoreStatus bool) []error {
	var ret []error
	for k, v := range m.ControllerNodesStatus {
		dlmtr := "."
		if path == "" {
			dlmtr = ""
		}
		npath := fmt.Sprintf("%s%sControllerNodesStatus[%v]", path, dlmtr, k)
		if errs := v.Validate(ver, npath, ignoreStatus); errs != nil {
			ret = append(ret, errs...)
		}
	}
	for k, v := range m.ControllerServicesStatus {
		dlmtr := "."
		if path == "" {
			dlmtr = ""
		}
		npath := fmt.Sprintf("%s%sControllerServicesStatus[%v]", path, dlmtr, k)
		if errs := v.Validate(ver, npath, ignoreStatus); errs != nil {
			ret = append(ret, errs...)
		}
	}
	for k, v := range m.SmartNICsStatus {
		dlmtr := "."
		if path == "" {
			dlmtr = ""
		}
		npath := fmt.Sprintf("%s%sSmartNICsStatus[%v]", path, dlmtr, k)
		if errs := v.Validate(ver, npath, ignoreStatus); errs != nil {
			ret = append(ret, errs...)
		}
	}
	if vs, ok := validatorMapRollout["RolloutStatus"][ver]; ok {
		for _, v := range vs {
			if err := v(path, m); err != nil {
				ret = append(ret, err)
			}
		}
	} else if vs, ok := validatorMapRollout["RolloutStatus"]["all"]; ok {
		for _, v := range vs {
			if err := v(path, m); err != nil {
				ret = append(ret, err)
			}
		}
	}
	return ret
}

func (m *RolloutStatus) Normalize() {

	for _, v := range m.ControllerNodesStatus {
		if v != nil {
			v.Normalize()
		}
	}

	for _, v := range m.ControllerServicesStatus {
		if v != nil {
			v.Normalize()
		}
	}

	m.OperationalState = RolloutStatus_RolloutOperationalState_normal[strings.ToLower(m.OperationalState)]

	for _, v := range m.SmartNICsStatus {
		if v != nil {
			v.Normalize()
		}
	}

}

// Transformers

func init() {
	scheme := runtime.GetDefaultScheme()
	scheme.AddKnownTypes(
		&Rollout{},
	)

	validatorMapRollout = make(map[string]map[string][]func(string, interface{}) error)

	validatorMapRollout["RolloutPhase"] = make(map[string][]func(string, interface{}) error)
	validatorMapRollout["RolloutPhase"]["all"] = append(validatorMapRollout["RolloutPhase"]["all"], func(path string, i interface{}) error {
		m := i.(*RolloutPhase)

		if _, ok := RolloutPhase_Phases_value[m.Phase]; !ok {
			vals := []string{}
			for k1, _ := range RolloutPhase_Phases_value {
				vals = append(vals, k1)
			}
			return fmt.Errorf("%v did not match allowed strings %v", path+"."+"Phase", vals)
		}
		return nil
	})

	validatorMapRollout["RolloutSpec"] = make(map[string][]func(string, interface{}) error)
	validatorMapRollout["RolloutSpec"]["all"] = append(validatorMapRollout["RolloutSpec"]["all"], func(path string, i interface{}) error {
		m := i.(*RolloutSpec)
		args := make([]string, 0)
		args = append(args, "0")
		args = append(args, "0")

		if err := validators.EmptyOr(validators.Duration, m.Duration, args); err != nil {
			return fmt.Errorf("%v failed validation: %s", path+"."+"Duration", err.Error())
		}
		return nil
	})

	validatorMapRollout["RolloutSpec"]["all"] = append(validatorMapRollout["RolloutSpec"]["all"], func(path string, i interface{}) error {
		m := i.(*RolloutSpec)

		if _, ok := RolloutSpec_StrategyType_value[m.Strategy]; !ok {
			vals := []string{}
			for k1, _ := range RolloutSpec_StrategyType_value {
				vals = append(vals, k1)
			}
			return fmt.Errorf("%v did not match allowed strings %v", path+"."+"Strategy", vals)
		}
		return nil
	})

	validatorMapRollout["RolloutSpec"]["all"] = append(validatorMapRollout["RolloutSpec"]["all"], func(path string, i interface{}) error {
		m := i.(*RolloutSpec)

		if _, ok := RolloutSpec_SmartNICUpgradeType_value[m.UpgradeType]; !ok {
			vals := []string{}
			for k1, _ := range RolloutSpec_SmartNICUpgradeType_value {
				vals = append(vals, k1)
			}
			return fmt.Errorf("%v did not match allowed strings %v", path+"."+"UpgradeType", vals)
		}
		return nil
	})

	validatorMapRollout["RolloutStatus"] = make(map[string][]func(string, interface{}) error)
	validatorMapRollout["RolloutStatus"]["all"] = append(validatorMapRollout["RolloutStatus"]["all"], func(path string, i interface{}) error {
		m := i.(*RolloutStatus)

		if _, ok := RolloutStatus_RolloutOperationalState_value[m.OperationalState]; !ok {
			vals := []string{}
			for k1, _ := range RolloutStatus_RolloutOperationalState_value {
				vals = append(vals, k1)
			}
			return fmt.Errorf("%v did not match allowed strings %v", path+"."+"OperationalState", vals)
		}
		return nil
	})

}
