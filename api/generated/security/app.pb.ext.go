// Code generated by protoc-gen-grpc-pensando DO NOT EDIT.

/*
Package security is a auto generated package.
Input file: app.proto
*/
package security

import (
	"errors"
	fmt "fmt"

	listerwatcher "github.com/pensando/sw/api/listerwatcher"
	"github.com/pensando/sw/venice/utils/kvstore"
	"github.com/pensando/sw/venice/utils/log"

	validators "github.com/pensando/sw/venice/utils/apigen/validators"

	"github.com/pensando/sw/venice/globals"
	"github.com/pensando/sw/venice/utils/runtime"
)

// Dummy definitions to suppress nonused warnings
var _ kvstore.Interface
var _ log.Logger
var _ listerwatcher.WatcherClient

var _ validators.DummyVar
var validatorMapApp = make(map[string]map[string][]func(string, interface{}) error)

// MakeKey generates a KV store key for the object
func (m *App) MakeKey(prefix string) string {
	return fmt.Sprint(globals.ConfigRootPrefix, "/", prefix, "/", "apps/", m.Tenant, "/", m.Name)
}

func (m *App) MakeURI(cat, ver, prefix string) string {
	in := m
	return fmt.Sprint("/", cat, "/", prefix, "/", ver, "/tenant/", in.Tenant, "/apps/", in.Name)
}

// Clone clones the object into into or creates one of into is nil
func (m *ALG) Clone(into interface{}) (interface{}, error) {
	var out *ALG
	var ok bool
	if into == nil {
		out = &ALG{}
	} else {
		out, ok = into.(*ALG)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *ALG) Defaults(ver string) bool {
	var ret bool
	ret = true
	switch ver {
	default:
		m.Type = "ICMP"
	}
	return ret
}

// Clone clones the object into into or creates one of into is nil
func (m *App) Clone(into interface{}) (interface{}, error) {
	var out *App
	var ok bool
	if into == nil {
		out = &App{}
	} else {
		out, ok = into.(*App)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *App) Defaults(ver string) bool {
	m.Kind = "App"
	m.Tenant, m.Namespace = "default", "default"
	var ret bool
	ret = m.Spec.Defaults(ver) || ret
	return ret
}

// Clone clones the object into into or creates one of into is nil
func (m *AppSpec) Clone(into interface{}) (interface{}, error) {
	var out *AppSpec
	var ok bool
	if into == nil {
		out = &AppSpec{}
	} else {
		out, ok = into.(*AppSpec)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *AppSpec) Defaults(ver string) bool {
	var ret bool
	if m.ALG != nil {
		ret = m.ALG.Defaults(ver) || ret
	}
	return ret
}

// Clone clones the object into into or creates one of into is nil
func (m *AppStatus) Clone(into interface{}) (interface{}, error) {
	var out *AppStatus
	var ok bool
	if into == nil {
		out = &AppStatus{}
	} else {
		out, ok = into.(*AppStatus)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *AppStatus) Defaults(ver string) bool {
	return false
}

// Clone clones the object into into or creates one of into is nil
func (m *DnsAlg) Clone(into interface{}) (interface{}, error) {
	var out *DnsAlg
	var ok bool
	if into == nil {
		out = &DnsAlg{}
	} else {
		out, ok = into.(*DnsAlg)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *DnsAlg) Defaults(ver string) bool {
	return false
}

// Clone clones the object into into or creates one of into is nil
func (m *FtpAlg) Clone(into interface{}) (interface{}, error) {
	var out *FtpAlg
	var ok bool
	if into == nil {
		out = &FtpAlg{}
	} else {
		out, ok = into.(*FtpAlg)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *FtpAlg) Defaults(ver string) bool {
	return false
}

// Clone clones the object into into or creates one of into is nil
func (m *IcmpAlg) Clone(into interface{}) (interface{}, error) {
	var out *IcmpAlg
	var ok bool
	if into == nil {
		out = &IcmpAlg{}
	} else {
		out, ok = into.(*IcmpAlg)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *IcmpAlg) Defaults(ver string) bool {
	return false
}

// Clone clones the object into into or creates one of into is nil
func (m *MsrpcAlg) Clone(into interface{}) (interface{}, error) {
	var out *MsrpcAlg
	var ok bool
	if into == nil {
		out = &MsrpcAlg{}
	} else {
		out, ok = into.(*MsrpcAlg)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *MsrpcAlg) Defaults(ver string) bool {
	return false
}

// Clone clones the object into into or creates one of into is nil
func (m *SunrpcAlg) Clone(into interface{}) (interface{}, error) {
	var out *SunrpcAlg
	var ok bool
	if into == nil {
		out = &SunrpcAlg{}
	} else {
		out, ok = into.(*SunrpcAlg)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *SunrpcAlg) Defaults(ver string) bool {
	return false
}

// Validators

func (m *ALG) Validate(ver, path string, ignoreStatus bool) []error {
	var ret []error
	if vs, ok := validatorMapApp["ALG"][ver]; ok {
		for _, v := range vs {
			if err := v(path, m); err != nil {
				ret = append(ret, err)
			}
		}
	} else if vs, ok := validatorMapApp["ALG"]["all"]; ok {
		for _, v := range vs {
			if err := v(path, m); err != nil {
				ret = append(ret, err)
			}
		}
	}
	return ret
}

func (m *App) Validate(ver, path string, ignoreStatus bool) []error {
	var ret []error
	{
		dlmtr := "."
		if path == "" {
			dlmtr = ""
		}
		ret = m.ObjectMeta.Validate(ver, path+dlmtr+"ObjectMeta", ignoreStatus)
	}

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

func (m *AppSpec) Validate(ver, path string, ignoreStatus bool) []error {
	var ret []error
	if m.ALG != nil {
		dlmtr := "."
		if path == "" {
			dlmtr = ""
		}
		npath := path + dlmtr + "ALG"
		if errs := m.ALG.Validate(ver, npath, ignoreStatus); errs != nil {
			ret = append(ret, errs...)
		}
	}
	if vs, ok := validatorMapApp["AppSpec"][ver]; ok {
		for _, v := range vs {
			if err := v(path, m); err != nil {
				ret = append(ret, err)
			}
		}
	} else if vs, ok := validatorMapApp["AppSpec"]["all"]; ok {
		for _, v := range vs {
			if err := v(path, m); err != nil {
				ret = append(ret, err)
			}
		}
	}
	return ret
}

func (m *AppStatus) Validate(ver, path string, ignoreStatus bool) []error {
	var ret []error
	return ret
}

func (m *DnsAlg) Validate(ver, path string, ignoreStatus bool) []error {
	var ret []error
	return ret
}

func (m *FtpAlg) Validate(ver, path string, ignoreStatus bool) []error {
	var ret []error
	return ret
}

func (m *IcmpAlg) Validate(ver, path string, ignoreStatus bool) []error {
	var ret []error
	return ret
}

func (m *MsrpcAlg) Validate(ver, path string, ignoreStatus bool) []error {
	var ret []error
	return ret
}

func (m *SunrpcAlg) Validate(ver, path string, ignoreStatus bool) []error {
	var ret []error
	return ret
}

// Transformers

func init() {
	scheme := runtime.GetDefaultScheme()
	scheme.AddKnownTypes(
		&App{},
	)

	validatorMapApp = make(map[string]map[string][]func(string, interface{}) error)

	validatorMapApp["ALG"] = make(map[string][]func(string, interface{}) error)
	validatorMapApp["ALG"]["all"] = append(validatorMapApp["ALG"]["all"], func(path string, i interface{}) error {
		m := i.(*ALG)

		if _, ok := ALG_ALGType_value[m.Type]; !ok {
			return errors.New("ALG.Type did not match allowed strings")
		}
		return nil
	})

	validatorMapApp["AppSpec"] = make(map[string][]func(string, interface{}) error)

	validatorMapApp["AppSpec"]["all"] = append(validatorMapApp["AppSpec"]["all"], func(path string, i interface{}) error {
		m := i.(*AppSpec)
		if !validators.Duration(m.Timeout) {
			return fmt.Errorf("%v validation failed", path+"."+"Timeout")
		}
		return nil
	})

}
