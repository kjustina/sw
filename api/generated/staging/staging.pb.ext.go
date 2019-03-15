// Code generated by protoc-gen-grpc-pensando DO NOT EDIT.

/*
Package staging is a auto generated package.
Input file: staging.proto
*/
package staging

import (
	fmt "fmt"

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

var _ validators.DummyVar
var validatorMapStaging = make(map[string]map[string][]func(string, interface{}) error)

// MakeKey generates a KV store key for the object
func (m *Buffer) MakeKey(prefix string) string {
	return fmt.Sprint(globals.ConfigRootPrefix, "/", prefix, "/", "buffers/", m.Tenant, "/", m.Name)
}

func (m *Buffer) MakeURI(cat, ver, prefix string) string {
	in := m
	return fmt.Sprint("/", cat, "/", prefix, "/", ver, "/tenant/", in.Tenant, "/buffers/", in.Name)
}

// MakeKey generates a KV store key for the object
func (m *ClearAction) MakeKey(prefix string) string {
	return fmt.Sprint(globals.ConfigRootPrefix, "/", prefix, "/", "buffers/", m.Tenant, "/", m.Name)
}

func (m *ClearAction) MakeURI(cat, ver, prefix string) string {
	in := m
	return fmt.Sprint("/", cat, "/", prefix, "/", ver, "/tenant/", in.Tenant, "/buffers/", in.Name)
}

// MakeKey generates a KV store key for the object
func (m *CommitAction) MakeKey(prefix string) string {
	return fmt.Sprint(globals.ConfigRootPrefix, "/", prefix, "/", "buffers/", m.Tenant, "/", m.Name)
}

func (m *CommitAction) MakeURI(cat, ver, prefix string) string {
	in := m
	return fmt.Sprint("/", cat, "/", prefix, "/", ver, "/tenant/", in.Tenant, "/buffers/", in.Name)
}

// Clone clones the object into into or creates one of into is nil
func (m *Buffer) Clone(into interface{}) (interface{}, error) {
	var out *Buffer
	var ok bool
	if into == nil {
		out = &Buffer{}
	} else {
		out, ok = into.(*Buffer)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *Buffer) Defaults(ver string) bool {
	m.Kind = "Buffer"
	m.Tenant, m.Namespace = "default", "default"
	var ret bool
	ret = m.Status.Defaults(ver) || ret
	return ret
}

// Clone clones the object into into or creates one of into is nil
func (m *BufferSpec) Clone(into interface{}) (interface{}, error) {
	var out *BufferSpec
	var ok bool
	if into == nil {
		out = &BufferSpec{}
	} else {
		out, ok = into.(*BufferSpec)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *BufferSpec) Defaults(ver string) bool {
	return false
}

// Clone clones the object into into or creates one of into is nil
func (m *BufferStatus) Clone(into interface{}) (interface{}, error) {
	var out *BufferStatus
	var ok bool
	if into == nil {
		out = &BufferStatus{}
	} else {
		out, ok = into.(*BufferStatus)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *BufferStatus) Defaults(ver string) bool {
	var ret bool
	ret = true
	switch ver {
	default:
		m.ValidationResult = "SUCCESS"
	}
	return ret
}

// Clone clones the object into into or creates one of into is nil
func (m *ClearAction) Clone(into interface{}) (interface{}, error) {
	var out *ClearAction
	var ok bool
	if into == nil {
		out = &ClearAction{}
	} else {
		out, ok = into.(*ClearAction)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *ClearAction) Defaults(ver string) bool {
	m.Kind = "ClearAction"
	m.Tenant, m.Namespace = "default", "default"
	var ret bool
	ret = m.Status.Defaults(ver) || ret
	return ret
}

// Clone clones the object into into or creates one of into is nil
func (m *ClearActionSpec) Clone(into interface{}) (interface{}, error) {
	var out *ClearActionSpec
	var ok bool
	if into == nil {
		out = &ClearActionSpec{}
	} else {
		out, ok = into.(*ClearActionSpec)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *ClearActionSpec) Defaults(ver string) bool {
	return false
}

// Clone clones the object into into or creates one of into is nil
func (m *ClearActionStatus) Clone(into interface{}) (interface{}, error) {
	var out *ClearActionStatus
	var ok bool
	if into == nil {
		out = &ClearActionStatus{}
	} else {
		out, ok = into.(*ClearActionStatus)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *ClearActionStatus) Defaults(ver string) bool {
	var ret bool
	ret = true
	switch ver {
	default:
		m.Status = "SUCCESS"
	}
	return ret
}

// Clone clones the object into into or creates one of into is nil
func (m *CommitAction) Clone(into interface{}) (interface{}, error) {
	var out *CommitAction
	var ok bool
	if into == nil {
		out = &CommitAction{}
	} else {
		out, ok = into.(*CommitAction)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *CommitAction) Defaults(ver string) bool {
	m.Kind = "CommitAction"
	m.Tenant, m.Namespace = "default", "default"
	var ret bool
	ret = m.Status.Defaults(ver) || ret
	return ret
}

// Clone clones the object into into or creates one of into is nil
func (m *CommitActionSpec) Clone(into interface{}) (interface{}, error) {
	var out *CommitActionSpec
	var ok bool
	if into == nil {
		out = &CommitActionSpec{}
	} else {
		out, ok = into.(*CommitActionSpec)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *CommitActionSpec) Defaults(ver string) bool {
	return false
}

// Clone clones the object into into or creates one of into is nil
func (m *CommitActionStatus) Clone(into interface{}) (interface{}, error) {
	var out *CommitActionStatus
	var ok bool
	if into == nil {
		out = &CommitActionStatus{}
	} else {
		out, ok = into.(*CommitActionStatus)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *CommitActionStatus) Defaults(ver string) bool {
	var ret bool
	ret = true
	switch ver {
	default:
		m.Status = "SUCCESS"
	}
	return ret
}

// Clone clones the object into into or creates one of into is nil
func (m *Item) Clone(into interface{}) (interface{}, error) {
	var out *Item
	var ok bool
	if into == nil {
		out = &Item{}
	} else {
		out, ok = into.(*Item)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *Item) Defaults(ver string) bool {
	return false
}

// Clone clones the object into into or creates one of into is nil
func (m *ItemId) Clone(into interface{}) (interface{}, error) {
	var out *ItemId
	var ok bool
	if into == nil {
		out = &ItemId{}
	} else {
		out, ok = into.(*ItemId)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *ItemId) Defaults(ver string) bool {
	return false
}

// Clone clones the object into into or creates one of into is nil
func (m *ValidationError) Clone(into interface{}) (interface{}, error) {
	var out *ValidationError
	var ok bool
	if into == nil {
		out = &ValidationError{}
	} else {
		out, ok = into.(*ValidationError)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *ValidationError) Defaults(ver string) bool {
	return false
}

// Validators and Requirements

func (m *Buffer) References(tenant string, path string, resp map[string]apiintf.ReferenceObj) {

	tenant = m.Tenant

	{
		dlmtr := "."
		if path == "" {
			dlmtr = ""
		}
		tag := path + dlmtr + "meta.tenant"
		uref, ok := resp[tag]
		if !ok {
			uref = apiintf.ReferenceObj{
				RefType: apiintf.ReferenceType("NamedRef"),
			}
		}

		if m.Tenant != "" {
			uref.Refs = append(uref.Refs, globals.ConfigRootPrefix+"/cluster/"+"tenants/"+m.Tenant)
		}

		if len(uref.Refs) > 0 {
			resp[tag] = uref
		}
	}
}

func (m *Buffer) Validate(ver, path string, ignoreStatus bool) []error {
	var ret []error

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

func (m *BufferSpec) References(tenant string, path string, resp map[string]apiintf.ReferenceObj) {

}

func (m *BufferSpec) Validate(ver, path string, ignoreStatus bool) []error {
	var ret []error
	return ret
}

func (m *BufferStatus) References(tenant string, path string, resp map[string]apiintf.ReferenceObj) {

}

func (m *BufferStatus) Validate(ver, path string, ignoreStatus bool) []error {
	var ret []error
	if vs, ok := validatorMapStaging["BufferStatus"][ver]; ok {
		for _, v := range vs {
			if err := v(path, m); err != nil {
				ret = append(ret, err)
			}
		}
	} else if vs, ok := validatorMapStaging["BufferStatus"]["all"]; ok {
		for _, v := range vs {
			if err := v(path, m); err != nil {
				ret = append(ret, err)
			}
		}
	}
	return ret
}

func (m *ClearAction) References(tenant string, path string, resp map[string]apiintf.ReferenceObj) {

	tenant = m.Tenant

	{
		dlmtr := "."
		if path == "" {
			dlmtr = ""
		}
		tag := path + dlmtr + "meta.tenant"
		uref, ok := resp[tag]
		if !ok {
			uref = apiintf.ReferenceObj{
				RefType: apiintf.ReferenceType("NamedRef"),
			}
		}

		if m.Tenant != "" {
			uref.Refs = append(uref.Refs, globals.ConfigRootPrefix+"/cluster/"+"tenants/"+m.Tenant)
		}

		if len(uref.Refs) > 0 {
			resp[tag] = uref
		}
	}
}

func (m *ClearAction) Validate(ver, path string, ignoreStatus bool) []error {
	var ret []error

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

func (m *ClearActionSpec) References(tenant string, path string, resp map[string]apiintf.ReferenceObj) {

}

func (m *ClearActionSpec) Validate(ver, path string, ignoreStatus bool) []error {
	var ret []error
	return ret
}

func (m *ClearActionStatus) References(tenant string, path string, resp map[string]apiintf.ReferenceObj) {

}

func (m *ClearActionStatus) Validate(ver, path string, ignoreStatus bool) []error {
	var ret []error
	if vs, ok := validatorMapStaging["ClearActionStatus"][ver]; ok {
		for _, v := range vs {
			if err := v(path, m); err != nil {
				ret = append(ret, err)
			}
		}
	} else if vs, ok := validatorMapStaging["ClearActionStatus"]["all"]; ok {
		for _, v := range vs {
			if err := v(path, m); err != nil {
				ret = append(ret, err)
			}
		}
	}
	return ret
}

func (m *CommitAction) References(tenant string, path string, resp map[string]apiintf.ReferenceObj) {

	tenant = m.Tenant

	{
		dlmtr := "."
		if path == "" {
			dlmtr = ""
		}
		tag := path + dlmtr + "meta.tenant"
		uref, ok := resp[tag]
		if !ok {
			uref = apiintf.ReferenceObj{
				RefType: apiintf.ReferenceType("NamedRef"),
			}
		}

		if m.Tenant != "" {
			uref.Refs = append(uref.Refs, globals.ConfigRootPrefix+"/cluster/"+"tenants/"+m.Tenant)
		}

		if len(uref.Refs) > 0 {
			resp[tag] = uref
		}
	}
}

func (m *CommitAction) Validate(ver, path string, ignoreStatus bool) []error {
	var ret []error

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

func (m *CommitActionSpec) References(tenant string, path string, resp map[string]apiintf.ReferenceObj) {

}

func (m *CommitActionSpec) Validate(ver, path string, ignoreStatus bool) []error {
	var ret []error
	return ret
}

func (m *CommitActionStatus) References(tenant string, path string, resp map[string]apiintf.ReferenceObj) {

}

func (m *CommitActionStatus) Validate(ver, path string, ignoreStatus bool) []error {
	var ret []error
	if vs, ok := validatorMapStaging["CommitActionStatus"][ver]; ok {
		for _, v := range vs {
			if err := v(path, m); err != nil {
				ret = append(ret, err)
			}
		}
	} else if vs, ok := validatorMapStaging["CommitActionStatus"]["all"]; ok {
		for _, v := range vs {
			if err := v(path, m); err != nil {
				ret = append(ret, err)
			}
		}
	}
	return ret
}

func (m *Item) References(tenant string, path string, resp map[string]apiintf.ReferenceObj) {

}

func (m *Item) Validate(ver, path string, ignoreStatus bool) []error {
	var ret []error
	return ret
}

func (m *ItemId) References(tenant string, path string, resp map[string]apiintf.ReferenceObj) {

}

func (m *ItemId) Validate(ver, path string, ignoreStatus bool) []error {
	var ret []error
	return ret
}

func (m *ValidationError) References(tenant string, path string, resp map[string]apiintf.ReferenceObj) {

}

func (m *ValidationError) Validate(ver, path string, ignoreStatus bool) []error {
	var ret []error
	return ret
}

// Transformers

func init() {
	scheme := runtime.GetDefaultScheme()
	scheme.AddKnownTypes(
		&Buffer{},
		&ClearAction{},
		&CommitAction{},
	)

	validatorMapStaging = make(map[string]map[string][]func(string, interface{}) error)

	validatorMapStaging["BufferStatus"] = make(map[string][]func(string, interface{}) error)
	validatorMapStaging["BufferStatus"]["all"] = append(validatorMapStaging["BufferStatus"]["all"], func(path string, i interface{}) error {
		m := i.(*BufferStatus)

		if _, ok := BufferStatus_ValidationStatus_value[m.ValidationResult]; !ok {
			return fmt.Errorf("%v did not match allowed strings", path+"."+"ValidationResult")
		}
		return nil
	})

	validatorMapStaging["ClearActionStatus"] = make(map[string][]func(string, interface{}) error)
	validatorMapStaging["ClearActionStatus"]["all"] = append(validatorMapStaging["ClearActionStatus"]["all"], func(path string, i interface{}) error {
		m := i.(*ClearActionStatus)

		if _, ok := ClearActionStatus_ClearStatus_value[m.Status]; !ok {
			return fmt.Errorf("%v did not match allowed strings", path+"."+"Status")
		}
		return nil
	})

	validatorMapStaging["CommitActionStatus"] = make(map[string][]func(string, interface{}) error)
	validatorMapStaging["CommitActionStatus"]["all"] = append(validatorMapStaging["CommitActionStatus"]["all"], func(path string, i interface{}) error {
		m := i.(*CommitActionStatus)

		if _, ok := CommitActionStatus_CommitStatus_value[m.Status]; !ok {
			return fmt.Errorf("%v did not match allowed strings", path+"."+"Status")
		}
		return nil
	})

}
