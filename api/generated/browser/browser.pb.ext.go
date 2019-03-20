// Code generated by protoc-gen-grpc-pensando DO NOT EDIT.

/*
Package browser is a auto generated package.
Input file: browser.proto
*/
package browser

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
var validatorMapBrowser = make(map[string]map[string][]func(string, interface{}) error)

// MakeKey generates a KV store key for the object
func (m *BrowseRequest) MakeKey(prefix string) string {
	return fmt.Sprint(globals.ConfigRootPrefix, "/", prefix, "/", "BrowseRequest", "/Singleton")
}

func (m *BrowseRequest) MakeURI(cat, ver, prefix string) string {
	return fmt.Sprint("/", cat, "/", prefix, "/", ver, "/BrowseRequest")
}

// Clone clones the object into into or creates one of into is nil
func (m *BrowseRequest) Clone(into interface{}) (interface{}, error) {
	var out *BrowseRequest
	var ok bool
	if into == nil {
		out = &BrowseRequest{}
	} else {
		out, ok = into.(*BrowseRequest)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *BrowseRequest) Defaults(ver string) bool {
	var ret bool
	ret = true
	switch ver {
	default:
		m.MaxDepth = 1
		m.QueryType = "Dependencies"
	}
	return ret
}

// Clone clones the object into into or creates one of into is nil
func (m *BrowseResponse) Clone(into interface{}) (interface{}, error) {
	var out *BrowseResponse
	var ok bool
	if into == nil {
		out = &BrowseResponse{}
	} else {
		out, ok = into.(*BrowseResponse)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *BrowseResponse) Defaults(ver string) bool {
	var ret bool
	for k := range m.Objects {
		i := m.Objects[k]
		ret = i.Defaults(ver) || ret
	}
	return ret
}

// Clone clones the object into into or creates one of into is nil
func (m *Object) Clone(into interface{}) (interface{}, error) {
	var out *Object
	var ok bool
	if into == nil {
		out = &Object{}
	} else {
		out, ok = into.(*Object)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *Object) Defaults(ver string) bool {
	var ret bool
	for k := range m.Links {
		i := m.Links[k]
		ret = i.Defaults(ver) || ret
	}
	ret = true
	switch ver {
	default:
		m.QueryType = "Dependencies"
	}
	return ret
}

// Clone clones the object into into or creates one of into is nil
func (m *Object_URIs) Clone(into interface{}) (interface{}, error) {
	var out *Object_URIs
	var ok bool
	if into == nil {
		out = &Object_URIs{}
	} else {
		out, ok = into.(*Object_URIs)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *Object_URIs) Defaults(ver string) bool {
	return false
}

// Validators and Requirements

func (m *BrowseRequest) References(tenant string, path string, resp map[string]apiintf.ReferenceObj) {

}

func (m *BrowseRequest) Validate(ver, path string, ignoreStatus bool) []error {
	var ret []error
	if vs, ok := validatorMapBrowser["BrowseRequest"][ver]; ok {
		for _, v := range vs {
			if err := v(path, m); err != nil {
				ret = append(ret, err)
			}
		}
	} else if vs, ok := validatorMapBrowser["BrowseRequest"]["all"]; ok {
		for _, v := range vs {
			if err := v(path, m); err != nil {
				ret = append(ret, err)
			}
		}
	}
	return ret
}

func (m *BrowseResponse) References(tenant string, path string, resp map[string]apiintf.ReferenceObj) {

}

func (m *BrowseResponse) Validate(ver, path string, ignoreStatus bool) []error {
	var ret []error
	for k, v := range m.Objects {
		dlmtr := "."
		if path == "" {
			dlmtr = ""
		}
		npath := fmt.Sprintf("%s%sObjects[%v]", path, dlmtr, k)
		if errs := v.Validate(ver, npath, ignoreStatus); errs != nil {
			ret = append(ret, errs...)
		}
	}
	return ret
}

func (m *Object) References(tenant string, path string, resp map[string]apiintf.ReferenceObj) {

}

func (m *Object) Validate(ver, path string, ignoreStatus bool) []error {
	var ret []error
	for k, v := range m.Links {
		dlmtr := "."
		if path == "" {
			dlmtr = ""
		}
		npath := fmt.Sprintf("%s%sLinks[%v]", path, dlmtr, k)
		if errs := v.Validate(ver, npath, ignoreStatus); errs != nil {
			ret = append(ret, errs...)
		}
	}
	if vs, ok := validatorMapBrowser["Object"][ver]; ok {
		for _, v := range vs {
			if err := v(path, m); err != nil {
				ret = append(ret, err)
			}
		}
	} else if vs, ok := validatorMapBrowser["Object"]["all"]; ok {
		for _, v := range vs {
			if err := v(path, m); err != nil {
				ret = append(ret, err)
			}
		}
	}
	return ret
}

func (m *Object_URIs) References(tenant string, path string, resp map[string]apiintf.ReferenceObj) {

}

func (m *Object_URIs) Validate(ver, path string, ignoreStatus bool) []error {
	var ret []error
	return ret
}

// Transformers

func init() {
	scheme := runtime.GetDefaultScheme()
	scheme.AddKnownTypes(
		&BrowseRequest{},
	)

	validatorMapBrowser = make(map[string]map[string][]func(string, interface{}) error)

	validatorMapBrowser["BrowseRequest"] = make(map[string][]func(string, interface{}) error)
	validatorMapBrowser["BrowseRequest"]["all"] = append(validatorMapBrowser["BrowseRequest"]["all"], func(path string, i interface{}) error {
		m := i.(*BrowseRequest)

		if _, ok := QueryType_value[m.QueryType]; !ok {
			vals := []string{}
			for k1, _ := range QueryType_value {
				vals = append(vals, k1)
			}
			return fmt.Errorf("%v did not match allowed strings %v", path+"."+"QueryType", vals)
		}
		return nil
	})

	validatorMapBrowser["BrowseRequest"]["all"] = append(validatorMapBrowser["BrowseRequest"]["all"], func(path string, i interface{}) error {
		m := i.(*BrowseRequest)
		args := make([]string, 0)
		args = append(args, "2")
		args = append(args, "512")

		if !validators.StrLen(m.URI, args) {
			return fmt.Errorf("%v failed validation", path+"."+"URI")
		}
		return nil
	})

	validatorMapBrowser["Object"] = make(map[string][]func(string, interface{}) error)
	validatorMapBrowser["Object"]["all"] = append(validatorMapBrowser["Object"]["all"], func(path string, i interface{}) error {
		m := i.(*Object)

		if _, ok := QueryType_value[m.QueryType]; !ok {
			vals := []string{}
			for k1, _ := range QueryType_value {
				vals = append(vals, k1)
			}
			return fmt.Errorf("%v did not match allowed strings %v", path+"."+"QueryType", vals)
		}
		return nil
	})

	validatorMapBrowser["Object_URIs"] = make(map[string][]func(string, interface{}) error)
	validatorMapBrowser["Object_URIs"]["all"] = append(validatorMapBrowser["Object_URIs"]["all"], func(path string, i interface{}) error {
		m := i.(*Object_URIs)

		if _, ok := ReferenceTypes_value[m.RefType]; !ok {
			vals := []string{}
			for k1, _ := range ReferenceTypes_value {
				vals = append(vals, k1)
			}
			return fmt.Errorf("%v did not match allowed strings %v", path+"."+"RefType", vals)
		}
		return nil
	})

}
