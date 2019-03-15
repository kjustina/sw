// Code generated by protoc-gen-grpc-pensando DO NOT EDIT.

/*
Package security is a auto generated package.
Input file: fwprofile.proto
*/
package security

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
var validatorMapFwprofile = make(map[string]map[string][]func(string, interface{}) error)

// MakeKey generates a KV store key for the object
func (m *FirewallProfile) MakeKey(prefix string) string {
	return fmt.Sprint(globals.ConfigRootPrefix, "/", prefix, "/", "firewallprofiles/", m.Tenant, "/", m.Name)
}

func (m *FirewallProfile) MakeURI(cat, ver, prefix string) string {
	in := m
	return fmt.Sprint("/", cat, "/", prefix, "/", ver, "/tenant/", in.Tenant, "/firewallprofiles/", in.Name)
}

// Clone clones the object into into or creates one of into is nil
func (m *FirewallProfile) Clone(into interface{}) (interface{}, error) {
	var out *FirewallProfile
	var ok bool
	if into == nil {
		out = &FirewallProfile{}
	} else {
		out, ok = into.(*FirewallProfile)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *FirewallProfile) Defaults(ver string) bool {
	m.Kind = "FirewallProfile"
	m.Tenant, m.Namespace = "default", "default"
	var ret bool
	ret = m.Spec.Defaults(ver) || ret
	return ret
}

// Clone clones the object into into or creates one of into is nil
func (m *FirewallProfileSpec) Clone(into interface{}) (interface{}, error) {
	var out *FirewallProfileSpec
	var ok bool
	if into == nil {
		out = &FirewallProfileSpec{}
	} else {
		out, ok = into.(*FirewallProfileSpec)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *FirewallProfileSpec) Defaults(ver string) bool {
	var ret bool
	ret = true
	switch ver {
	default:
		m.DropTimeout = "60s"
		m.ICMPDropTimeout = "60s"
		m.IcmpTimeout = "6s"
		m.SessionIdleTimeout = "90s"
		m.TCPCloseTimeout = "15s"
		m.TCPConnectionSetupTimeout = "30s"
		m.TCPDropTimeout = "90s"
		m.TCPHalfClosedTimeout = "120s"
		m.TcpTimeout = "3600s"
		m.UDPDropTimeout = "60s"
		m.UdpTimeout = "30s"
	}
	return ret
}

// Clone clones the object into into or creates one of into is nil
func (m *FirewallProfileStatus) Clone(into interface{}) (interface{}, error) {
	var out *FirewallProfileStatus
	var ok bool
	if into == nil {
		out = &FirewallProfileStatus{}
	} else {
		out, ok = into.(*FirewallProfileStatus)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *FirewallProfileStatus) Defaults(ver string) bool {
	return false
}

// Validators and Requirements

func (m *FirewallProfile) References(tenant string, path string, resp map[string]apiintf.ReferenceObj) {

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

func (m *FirewallProfile) Validate(ver, path string, ignoreStatus bool) []error {
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

func (m *FirewallProfileSpec) References(tenant string, path string, resp map[string]apiintf.ReferenceObj) {

}

func (m *FirewallProfileSpec) Validate(ver, path string, ignoreStatus bool) []error {
	var ret []error
	if vs, ok := validatorMapFwprofile["FirewallProfileSpec"][ver]; ok {
		for _, v := range vs {
			if err := v(path, m); err != nil {
				ret = append(ret, err)
			}
		}
	} else if vs, ok := validatorMapFwprofile["FirewallProfileSpec"]["all"]; ok {
		for _, v := range vs {
			if err := v(path, m); err != nil {
				ret = append(ret, err)
			}
		}
	}
	return ret
}

func (m *FirewallProfileStatus) References(tenant string, path string, resp map[string]apiintf.ReferenceObj) {

}

func (m *FirewallProfileStatus) Validate(ver, path string, ignoreStatus bool) []error {
	var ret []error
	return ret
}

// Transformers

func init() {
	scheme := runtime.GetDefaultScheme()
	scheme.AddKnownTypes(
		&FirewallProfile{},
	)

	validatorMapFwprofile = make(map[string]map[string][]func(string, interface{}) error)

	validatorMapFwprofile["FirewallProfileSpec"] = make(map[string][]func(string, interface{}) error)
	validatorMapFwprofile["FirewallProfileSpec"]["all"] = append(validatorMapFwprofile["FirewallProfileSpec"]["all"], func(path string, i interface{}) error {
		m := i.(*FirewallProfileSpec)
		args := make([]string, 0)
		args = append(args, "0")
		args = append(args, "0")

		if !validators.Duration(m.DropTimeout, args) {
			return fmt.Errorf("%v failed validation", path+"."+"DropTimeout")
		}
		return nil
	})

	validatorMapFwprofile["FirewallProfileSpec"]["all"] = append(validatorMapFwprofile["FirewallProfileSpec"]["all"], func(path string, i interface{}) error {
		m := i.(*FirewallProfileSpec)
		args := make([]string, 0)
		args = append(args, "0")
		args = append(args, "0")

		if !validators.Duration(m.ICMPDropTimeout, args) {
			return fmt.Errorf("%v failed validation", path+"."+"ICMPDropTimeout")
		}
		return nil
	})

	validatorMapFwprofile["FirewallProfileSpec"]["all"] = append(validatorMapFwprofile["FirewallProfileSpec"]["all"], func(path string, i interface{}) error {
		m := i.(*FirewallProfileSpec)
		args := make([]string, 0)
		args = append(args, "0")
		args = append(args, "0")

		if !validators.Duration(m.IcmpTimeout, args) {
			return fmt.Errorf("%v failed validation", path+"."+"IcmpTimeout")
		}
		return nil
	})

	validatorMapFwprofile["FirewallProfileSpec"]["all"] = append(validatorMapFwprofile["FirewallProfileSpec"]["all"], func(path string, i interface{}) error {
		m := i.(*FirewallProfileSpec)
		args := make([]string, 0)
		args = append(args, "0")
		args = append(args, "0")

		if !validators.Duration(m.SessionIdleTimeout, args) {
			return fmt.Errorf("%v failed validation", path+"."+"SessionIdleTimeout")
		}
		return nil
	})

	validatorMapFwprofile["FirewallProfileSpec"]["all"] = append(validatorMapFwprofile["FirewallProfileSpec"]["all"], func(path string, i interface{}) error {
		m := i.(*FirewallProfileSpec)
		args := make([]string, 0)
		args = append(args, "0")
		args = append(args, "0")

		if !validators.Duration(m.TCPCloseTimeout, args) {
			return fmt.Errorf("%v failed validation", path+"."+"TCPCloseTimeout")
		}
		return nil
	})

	validatorMapFwprofile["FirewallProfileSpec"]["all"] = append(validatorMapFwprofile["FirewallProfileSpec"]["all"], func(path string, i interface{}) error {
		m := i.(*FirewallProfileSpec)
		args := make([]string, 0)
		args = append(args, "0")
		args = append(args, "0")

		if !validators.Duration(m.TCPConnectionSetupTimeout, args) {
			return fmt.Errorf("%v failed validation", path+"."+"TCPConnectionSetupTimeout")
		}
		return nil
	})

	validatorMapFwprofile["FirewallProfileSpec"]["all"] = append(validatorMapFwprofile["FirewallProfileSpec"]["all"], func(path string, i interface{}) error {
		m := i.(*FirewallProfileSpec)
		args := make([]string, 0)
		args = append(args, "0")
		args = append(args, "0")

		if !validators.Duration(m.TCPDropTimeout, args) {
			return fmt.Errorf("%v failed validation", path+"."+"TCPDropTimeout")
		}
		return nil
	})

	validatorMapFwprofile["FirewallProfileSpec"]["all"] = append(validatorMapFwprofile["FirewallProfileSpec"]["all"], func(path string, i interface{}) error {
		m := i.(*FirewallProfileSpec)
		args := make([]string, 0)
		args = append(args, "0")
		args = append(args, "0")

		if !validators.Duration(m.TCPHalfClosedTimeout, args) {
			return fmt.Errorf("%v failed validation", path+"."+"TCPHalfClosedTimeout")
		}
		return nil
	})

	validatorMapFwprofile["FirewallProfileSpec"]["all"] = append(validatorMapFwprofile["FirewallProfileSpec"]["all"], func(path string, i interface{}) error {
		m := i.(*FirewallProfileSpec)
		args := make([]string, 0)
		args = append(args, "0")
		args = append(args, "0")

		if !validators.Duration(m.TcpTimeout, args) {
			return fmt.Errorf("%v failed validation", path+"."+"TcpTimeout")
		}
		return nil
	})

	validatorMapFwprofile["FirewallProfileSpec"]["all"] = append(validatorMapFwprofile["FirewallProfileSpec"]["all"], func(path string, i interface{}) error {
		m := i.(*FirewallProfileSpec)
		args := make([]string, 0)
		args = append(args, "0")
		args = append(args, "0")

		if !validators.Duration(m.UDPDropTimeout, args) {
			return fmt.Errorf("%v failed validation", path+"."+"UDPDropTimeout")
		}
		return nil
	})

	validatorMapFwprofile["FirewallProfileSpec"]["all"] = append(validatorMapFwprofile["FirewallProfileSpec"]["all"], func(path string, i interface{}) error {
		m := i.(*FirewallProfileSpec)
		args := make([]string, 0)
		args = append(args, "0")
		args = append(args, "0")

		if !validators.Duration(m.UdpTimeout, args) {
			return fmt.Errorf("%v failed validation", path+"."+"UdpTimeout")
		}
		return nil
	})

}
