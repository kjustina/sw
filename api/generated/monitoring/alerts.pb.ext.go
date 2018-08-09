// Code generated by protoc-gen-grpc-pensando DO NOT EDIT.

/*
Package monitoring is a auto generated package.
Input file: alerts.proto
*/
package monitoring

import (
	"errors"
	fmt "fmt"

	"github.com/pensando/sw/api/generated/events"
	listerwatcher "github.com/pensando/sw/api/listerwatcher"
	"github.com/pensando/sw/venice/utils/kvstore"
	"github.com/pensando/sw/venice/utils/log"
	"github.com/pensando/sw/venice/utils/runtime"

	validators "github.com/pensando/sw/venice/utils/apigen/validators"

	"github.com/pensando/sw/venice/globals"
)

// Dummy definitions to suppress nonused warnings
var _ kvstore.Interface
var _ log.Logger
var _ listerwatcher.WatcherClient

var _ validators.DummyVar
var validatorMapAlerts = make(map[string]map[string][]func(string, interface{}) error)

// MakeKey generates a KV store key for the object
func (m *Alert) MakeKey(prefix string) string {
	return fmt.Sprint(globals.ConfigRootPrefix, "/", prefix, "/", "alerts/", m.Tenant, "/", m.Name)
}

func (m *Alert) MakeURI(cat, ver, prefix string) string {
	in := m
	return fmt.Sprint("/", cat, "/", prefix, "/", ver, "/tenant/", in.Tenant, "/alerts/", in.Name)
}

// MakeKey generates a KV store key for the object
func (m *AlertDestination) MakeKey(prefix string) string {
	return fmt.Sprint(globals.ConfigRootPrefix, "/", prefix, "/", "alertDestinations/", m.Tenant, "/", m.Name)
}

func (m *AlertDestination) MakeURI(cat, ver, prefix string) string {
	in := m
	return fmt.Sprint("/", cat, "/", prefix, "/", ver, "/tenant/", in.Tenant, "/alertDestinations/", in.Name)
}

// MakeKey generates a KV store key for the object
func (m *AlertPolicy) MakeKey(prefix string) string {
	return fmt.Sprint(globals.ConfigRootPrefix, "/", prefix, "/", "alertPolicies/", m.Tenant, "/", m.Name)
}

func (m *AlertPolicy) MakeURI(cat, ver, prefix string) string {
	in := m
	return fmt.Sprint("/", cat, "/", prefix, "/", ver, "/tenant/", in.Tenant, "/alertPolicies/", in.Name)
}

// Clone clones the object into into or creates one of into is nil
func (m *Alert) Clone(into interface{}) (interface{}, error) {
	var out *Alert
	var ok bool
	if into == nil {
		out = &Alert{}
	} else {
		out, ok = into.(*Alert)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *Alert) Defaults(ver string) bool {
	m.Kind = "Alert"
	var ret bool
	ret = m.Spec.Defaults(ver) || ret
	ret = m.Status.Defaults(ver) || ret
	return ret
}

// Clone clones the object into into or creates one of into is nil
func (m *AlertDestination) Clone(into interface{}) (interface{}, error) {
	var out *AlertDestination
	var ok bool
	if into == nil {
		out = &AlertDestination{}
	} else {
		out, ok = into.(*AlertDestination)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *AlertDestination) Defaults(ver string) bool {
	m.Kind = "AlertDestination"
	var ret bool
	ret = m.Spec.Defaults(ver) || ret
	return ret
}

// Clone clones the object into into or creates one of into is nil
func (m *AlertDestinationSpec) Clone(into interface{}) (interface{}, error) {
	var out *AlertDestinationSpec
	var ok bool
	if into == nil {
		out = &AlertDestinationSpec{}
	} else {
		out, ok = into.(*AlertDestinationSpec)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *AlertDestinationSpec) Defaults(ver string) bool {
	var ret bool
	for k := range m.SNMPTrapServers {
		if m.SNMPTrapServers[k] != nil {
			i := m.SNMPTrapServers[k]
			ret = i.Defaults(ver) || ret
		}
	}
	return ret
}

// Clone clones the object into into or creates one of into is nil
func (m *AlertDestinationStatus) Clone(into interface{}) (interface{}, error) {
	var out *AlertDestinationStatus
	var ok bool
	if into == nil {
		out = &AlertDestinationStatus{}
	} else {
		out, ok = into.(*AlertDestinationStatus)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *AlertDestinationStatus) Defaults(ver string) bool {
	return false
}

// Clone clones the object into into or creates one of into is nil
func (m *AlertPolicy) Clone(into interface{}) (interface{}, error) {
	var out *AlertPolicy
	var ok bool
	if into == nil {
		out = &AlertPolicy{}
	} else {
		out, ok = into.(*AlertPolicy)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *AlertPolicy) Defaults(ver string) bool {
	m.Kind = "AlertPolicy"
	var ret bool
	ret = m.Spec.Defaults(ver) || ret
	return ret
}

// Clone clones the object into into or creates one of into is nil
func (m *AlertPolicySpec) Clone(into interface{}) (interface{}, error) {
	var out *AlertPolicySpec
	var ok bool
	if into == nil {
		out = &AlertPolicySpec{}
	} else {
		out, ok = into.(*AlertPolicySpec)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *AlertPolicySpec) Defaults(ver string) bool {
	var ret bool
	ret = true
	switch ver {
	default:
		m.Severity = "INFO"
	}
	return ret
}

// Clone clones the object into into or creates one of into is nil
func (m *AlertPolicyStatus) Clone(into interface{}) (interface{}, error) {
	var out *AlertPolicyStatus
	var ok bool
	if into == nil {
		out = &AlertPolicyStatus{}
	} else {
		out, ok = into.(*AlertPolicyStatus)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *AlertPolicyStatus) Defaults(ver string) bool {
	return false
}

// Clone clones the object into into or creates one of into is nil
func (m *AlertReason) Clone(into interface{}) (interface{}, error) {
	var out *AlertReason
	var ok bool
	if into == nil {
		out = &AlertReason{}
	} else {
		out, ok = into.(*AlertReason)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *AlertReason) Defaults(ver string) bool {
	return false
}

// Clone clones the object into into or creates one of into is nil
func (m *AlertSource) Clone(into interface{}) (interface{}, error) {
	var out *AlertSource
	var ok bool
	if into == nil {
		out = &AlertSource{}
	} else {
		out, ok = into.(*AlertSource)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *AlertSource) Defaults(ver string) bool {
	return false
}

// Clone clones the object into into or creates one of into is nil
func (m *AlertSpec) Clone(into interface{}) (interface{}, error) {
	var out *AlertSpec
	var ok bool
	if into == nil {
		out = &AlertSpec{}
	} else {
		out, ok = into.(*AlertSpec)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *AlertSpec) Defaults(ver string) bool {
	var ret bool
	ret = true
	switch ver {
	default:
		m.State = "OPEN"
	}
	return ret
}

// Clone clones the object into into or creates one of into is nil
func (m *AlertStatus) Clone(into interface{}) (interface{}, error) {
	var out *AlertStatus
	var ok bool
	if into == nil {
		out = &AlertStatus{}
	} else {
		out, ok = into.(*AlertStatus)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *AlertStatus) Defaults(ver string) bool {
	var ret bool
	ret = true
	switch ver {
	default:
		m.Severity = "INFO"
	}
	return ret
}

// Clone clones the object into into or creates one of into is nil
func (m *AuditInfo) Clone(into interface{}) (interface{}, error) {
	var out *AuditInfo
	var ok bool
	if into == nil {
		out = &AuditInfo{}
	} else {
		out, ok = into.(*AuditInfo)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *AuditInfo) Defaults(ver string) bool {
	return false
}

// Clone clones the object into into or creates one of into is nil
func (m *AuthConfig) Clone(into interface{}) (interface{}, error) {
	var out *AuthConfig
	var ok bool
	if into == nil {
		out = &AuthConfig{}
	} else {
		out, ok = into.(*AuthConfig)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *AuthConfig) Defaults(ver string) bool {
	var ret bool
	ret = true
	switch ver {
	default:
		m.Algo = "MD5"
	}
	return ret
}

// Clone clones the object into into or creates one of into is nil
func (m *MatchedRequirement) Clone(into interface{}) (interface{}, error) {
	var out *MatchedRequirement
	var ok bool
	if into == nil {
		out = &MatchedRequirement{}
	} else {
		out, ok = into.(*MatchedRequirement)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *MatchedRequirement) Defaults(ver string) bool {
	return false
}

// Clone clones the object into into or creates one of into is nil
func (m *PrivacyConfig) Clone(into interface{}) (interface{}, error) {
	var out *PrivacyConfig
	var ok bool
	if into == nil {
		out = &PrivacyConfig{}
	} else {
		out, ok = into.(*PrivacyConfig)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *PrivacyConfig) Defaults(ver string) bool {
	var ret bool
	ret = true
	switch ver {
	default:
		m.Algo = "DES56"
	}
	return ret
}

// Clone clones the object into into or creates one of into is nil
func (m *SNMPTrapServer) Clone(into interface{}) (interface{}, error) {
	var out *SNMPTrapServer
	var ok bool
	if into == nil {
		out = &SNMPTrapServer{}
	} else {
		out, ok = into.(*SNMPTrapServer)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *SNMPTrapServer) Defaults(ver string) bool {
	var ret bool
	if m.AuthConfig != nil {
		ret = m.AuthConfig.Defaults(ver) || ret
	}
	if m.PrivacyConfig != nil {
		ret = m.PrivacyConfig.Defaults(ver) || ret
	}
	ret = true
	switch ver {
	default:
		m.Version = "V2C"
	}
	return ret
}

// Validators

func (m *Alert) Validate(ver, path string, ignoreStatus bool) []error {
	var ret []error

	dlmtr := "."
	if path == "" {
		dlmtr = ""
	}
	npath := path + dlmtr + "Spec"
	if errs := m.Spec.Validate(ver, npath, ignoreStatus); errs != nil {
		ret = append(ret, errs...)
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

func (m *AlertDestination) Validate(ver, path string, ignoreStatus bool) []error {
	var ret []error

	dlmtr := "."
	if path == "" {
		dlmtr = ""
	}
	npath := path + dlmtr + "Spec"
	if errs := m.Spec.Validate(ver, npath, ignoreStatus); errs != nil {
		ret = append(ret, errs...)
	}
	return ret
}

func (m *AlertDestinationSpec) Validate(ver, path string, ignoreStatus bool) []error {
	var ret []error
	for k, v := range m.SNMPTrapServers {
		dlmtr := "."
		if path == "" {
			dlmtr = ""
		}
		npath := fmt.Sprintf("%s%sSNMPTrapServers[%d]", path, dlmtr, k)
		if errs := v.Validate(ver, npath, ignoreStatus); errs != nil {
			ret = append(ret, errs...)
		}
	}
	return ret
}

func (m *AlertDestinationStatus) Validate(ver, path string, ignoreStatus bool) []error {
	var ret []error
	return ret
}

func (m *AlertPolicy) Validate(ver, path string, ignoreStatus bool) []error {
	var ret []error

	dlmtr := "."
	if path == "" {
		dlmtr = ""
	}
	npath := path + dlmtr + "Spec"
	if errs := m.Spec.Validate(ver, npath, ignoreStatus); errs != nil {
		ret = append(ret, errs...)
	}
	return ret
}

func (m *AlertPolicySpec) Validate(ver, path string, ignoreStatus bool) []error {
	var ret []error
	for k, v := range m.Requirements {
		dlmtr := "."
		if path == "" {
			dlmtr = ""
		}
		npath := fmt.Sprintf("%s%sRequirements[%d]", path, dlmtr, k)
		if errs := v.Validate(ver, npath, ignoreStatus); errs != nil {
			ret = append(ret, errs...)
		}
	}
	if vs, ok := validatorMapAlerts["AlertPolicySpec"][ver]; ok {
		for _, v := range vs {
			if err := v(path, m); err != nil {
				ret = append(ret, err)
			}
		}
	} else if vs, ok := validatorMapAlerts["AlertPolicySpec"]["all"]; ok {
		for _, v := range vs {
			if err := v(path, m); err != nil {
				ret = append(ret, err)
			}
		}
	}
	return ret
}

func (m *AlertPolicyStatus) Validate(ver, path string, ignoreStatus bool) []error {
	var ret []error
	return ret
}

func (m *AlertReason) Validate(ver, path string, ignoreStatus bool) []error {
	var ret []error
	for k, v := range m.MatchedRequirements {
		dlmtr := "."
		if path == "" {
			dlmtr = ""
		}
		npath := fmt.Sprintf("%s%sMatchedRequirements[%d]", path, dlmtr, k)
		if errs := v.Validate(ver, npath, ignoreStatus); errs != nil {
			ret = append(ret, errs...)
		}
	}
	return ret
}

func (m *AlertSource) Validate(ver, path string, ignoreStatus bool) []error {
	var ret []error
	return ret
}

func (m *AlertSpec) Validate(ver, path string, ignoreStatus bool) []error {
	var ret []error
	if vs, ok := validatorMapAlerts["AlertSpec"][ver]; ok {
		for _, v := range vs {
			if err := v(path, m); err != nil {
				ret = append(ret, err)
			}
		}
	} else if vs, ok := validatorMapAlerts["AlertSpec"]["all"]; ok {
		for _, v := range vs {
			if err := v(path, m); err != nil {
				ret = append(ret, err)
			}
		}
	}
	return ret
}

func (m *AlertStatus) Validate(ver, path string, ignoreStatus bool) []error {
	var ret []error

	dlmtr := "."
	if path == "" {
		dlmtr = ""
	}
	npath := path + dlmtr + "Reason"
	if errs := m.Reason.Validate(ver, npath, ignoreStatus); errs != nil {
		ret = append(ret, errs...)
	}
	if vs, ok := validatorMapAlerts["AlertStatus"][ver]; ok {
		for _, v := range vs {
			if err := v(path, m); err != nil {
				ret = append(ret, err)
			}
		}
	} else if vs, ok := validatorMapAlerts["AlertStatus"]["all"]; ok {
		for _, v := range vs {
			if err := v(path, m); err != nil {
				ret = append(ret, err)
			}
		}
	}
	return ret
}

func (m *AuditInfo) Validate(ver, path string, ignoreStatus bool) []error {
	var ret []error
	return ret
}

func (m *AuthConfig) Validate(ver, path string, ignoreStatus bool) []error {
	var ret []error
	if vs, ok := validatorMapAlerts["AuthConfig"][ver]; ok {
		for _, v := range vs {
			if err := v(path, m); err != nil {
				ret = append(ret, err)
			}
		}
	} else if vs, ok := validatorMapAlerts["AuthConfig"]["all"]; ok {
		for _, v := range vs {
			if err := v(path, m); err != nil {
				ret = append(ret, err)
			}
		}
	}
	return ret
}

func (m *MatchedRequirement) Validate(ver, path string, ignoreStatus bool) []error {
	var ret []error
	if m.Requirement != nil {
		dlmtr := "."
		if path == "" {
			dlmtr = ""
		}
		npath := path + dlmtr + "Requirement"
		if errs := m.Requirement.Validate(ver, npath, ignoreStatus); errs != nil {
			ret = append(ret, errs...)
		}
	}
	return ret
}

func (m *PrivacyConfig) Validate(ver, path string, ignoreStatus bool) []error {
	var ret []error
	if vs, ok := validatorMapAlerts["PrivacyConfig"][ver]; ok {
		for _, v := range vs {
			if err := v(path, m); err != nil {
				ret = append(ret, err)
			}
		}
	} else if vs, ok := validatorMapAlerts["PrivacyConfig"]["all"]; ok {
		for _, v := range vs {
			if err := v(path, m); err != nil {
				ret = append(ret, err)
			}
		}
	}
	return ret
}

func (m *SNMPTrapServer) Validate(ver, path string, ignoreStatus bool) []error {
	var ret []error
	if m.AuthConfig != nil {
		dlmtr := "."
		if path == "" {
			dlmtr = ""
		}
		npath := path + dlmtr + "AuthConfig"
		if errs := m.AuthConfig.Validate(ver, npath, ignoreStatus); errs != nil {
			ret = append(ret, errs...)
		}
	}
	if m.PrivacyConfig != nil {
		dlmtr := "."
		if path == "" {
			dlmtr = ""
		}
		npath := path + dlmtr + "PrivacyConfig"
		if errs := m.PrivacyConfig.Validate(ver, npath, ignoreStatus); errs != nil {
			ret = append(ret, errs...)
		}
	}
	if vs, ok := validatorMapAlerts["SNMPTrapServer"][ver]; ok {
		for _, v := range vs {
			if err := v(path, m); err != nil {
				ret = append(ret, err)
			}
		}
	} else if vs, ok := validatorMapAlerts["SNMPTrapServer"]["all"]; ok {
		for _, v := range vs {
			if err := v(path, m); err != nil {
				ret = append(ret, err)
			}
		}
	}
	return ret
}

// Transformers

func init() {
	scheme := runtime.GetDefaultScheme()
	scheme.AddKnownTypes(
		&Alert{},
		&AlertDestination{},
		&AlertPolicy{},
	)

	validatorMapAlerts = make(map[string]map[string][]func(string, interface{}) error)

	validatorMapAlerts["AlertPolicySpec"] = make(map[string][]func(string, interface{}) error)
	validatorMapAlerts["AlertPolicySpec"]["all"] = append(validatorMapAlerts["AlertPolicySpec"]["all"], func(path string, i interface{}) error {
		m := i.(*AlertPolicySpec)

		if _, ok := events.SeverityLevel_value[m.Severity]; !ok {
			return errors.New("AlertPolicySpec.Severity did not match allowed strings")
		}
		return nil
	})

	validatorMapAlerts["AlertSpec"] = make(map[string][]func(string, interface{}) error)
	validatorMapAlerts["AlertSpec"]["all"] = append(validatorMapAlerts["AlertSpec"]["all"], func(path string, i interface{}) error {
		m := i.(*AlertSpec)

		if _, ok := AlertSpec_AlertState_value[m.State]; !ok {
			return errors.New("AlertSpec.State did not match allowed strings")
		}
		return nil
	})

	validatorMapAlerts["AlertStatus"] = make(map[string][]func(string, interface{}) error)
	validatorMapAlerts["AlertStatus"]["all"] = append(validatorMapAlerts["AlertStatus"]["all"], func(path string, i interface{}) error {
		m := i.(*AlertStatus)

		if _, ok := events.SeverityLevel_value[m.Severity]; !ok {
			return errors.New("AlertStatus.Severity did not match allowed strings")
		}
		return nil
	})

	validatorMapAlerts["AuthConfig"] = make(map[string][]func(string, interface{}) error)
	validatorMapAlerts["AuthConfig"]["all"] = append(validatorMapAlerts["AuthConfig"]["all"], func(path string, i interface{}) error {
		m := i.(*AuthConfig)

		if _, ok := AuthConfig_Algos_value[m.Algo]; !ok {
			return errors.New("AuthConfig.Algo did not match allowed strings")
		}
		return nil
	})

	validatorMapAlerts["PrivacyConfig"] = make(map[string][]func(string, interface{}) error)
	validatorMapAlerts["PrivacyConfig"]["all"] = append(validatorMapAlerts["PrivacyConfig"]["all"], func(path string, i interface{}) error {
		m := i.(*PrivacyConfig)

		if _, ok := PrivacyConfig_Algos_value[m.Algo]; !ok {
			return errors.New("PrivacyConfig.Algo did not match allowed strings")
		}
		return nil
	})

	validatorMapAlerts["SNMPTrapServer"] = make(map[string][]func(string, interface{}) error)
	validatorMapAlerts["SNMPTrapServer"]["all"] = append(validatorMapAlerts["SNMPTrapServer"]["all"], func(path string, i interface{}) error {
		m := i.(*SNMPTrapServer)

		if _, ok := SNMPTrapServer_SNMPVersions_value[m.Version]; !ok {
			return errors.New("SNMPTrapServer.Version did not match allowed strings")
		}
		return nil
	})

}
