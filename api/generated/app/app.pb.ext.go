// Code generated by protoc-gen-grpc-pensando DO NOT EDIT.

/*
Package app is a auto generated package.
Input file: protos/app.proto
*/
package app

import (
	fmt "fmt"

	listerwatcher "github.com/pensando/sw/api/listerwatcher"
	"github.com/pensando/sw/venice/utils/kvstore"
	"github.com/pensando/sw/venice/utils/log"

	"github.com/pensando/sw/venice/globals"
)

// Dummy definitions to suppress nonused warnings
var _ kvstore.Interface
var _ log.Logger
var _ listerwatcher.WatcherClient

// MakeKey generates a KV store key for the object
func (m *App) MakeKey(prefix string) string {
	return fmt.Sprint(globals.RootPrefix, "/", prefix, "/", "apps/", m.Name)
}

// MakeKey generates a KV store key for the object
func (m *AppUser) MakeKey(prefix string) string {
	return fmt.Sprint(globals.RootPrefix, "/", prefix, "/", "app-users/", m.Tenant, "/", m.Name)
}

// MakeKey generates a KV store key for the object
func (m *AppUserGrp) MakeKey(prefix string) string {
	return fmt.Sprint(globals.RootPrefix, "/", prefix, "/", "app-users-groups/", m.Tenant, "/", m.Name)
}

// MakeKey generates a KV store key for the object
func (m *AppList) MakeKey(prefix string) string {
	obj := App{}
	return obj.MakeKey(prefix)
}

// MakeKey generates a KV store key for the object
func (m *AppUserGrpList) MakeKey(prefix string) string {
	obj := AppUserGrp{}
	return obj.MakeKey(prefix)
}

// MakeKey generates a KV store key for the object
func (m *AppUserList) MakeKey(prefix string) string {
	obj := AppUser{}
	return obj.MakeKey(prefix)
}

// MakeKey generates a KV store key for the object
func (m *AutoMsgAppUserGrpWatchHelper) MakeKey(prefix string) string {
	obj := AppUserGrp{}
	return obj.MakeKey(prefix)
}

// MakeKey generates a KV store key for the object
func (m *AutoMsgAppUserWatchHelper) MakeKey(prefix string) string {
	obj := AppUser{}
	return obj.MakeKey(prefix)
}

// MakeKey generates a KV store key for the object
func (m *AutoMsgAppWatchHelper) MakeKey(prefix string) string {
	obj := App{}
	return obj.MakeKey(prefix)
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
	return false
}

// Clone clones the object into into or creates one of into is nil
func (m *AppList) Clone(into interface{}) (interface{}, error) {
	var out *AppList
	var ok bool
	if into == nil {
		out = &AppList{}
	} else {
		out, ok = into.(*AppList)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *AppList) Defaults(ver string) bool {
	return false
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
	return false
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
func (m *AppUser) Clone(into interface{}) (interface{}, error) {
	var out *AppUser
	var ok bool
	if into == nil {
		out = &AppUser{}
	} else {
		out, ok = into.(*AppUser)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *AppUser) Defaults(ver string) bool {
	return false
}

// Clone clones the object into into or creates one of into is nil
func (m *AppUserGrp) Clone(into interface{}) (interface{}, error) {
	var out *AppUserGrp
	var ok bool
	if into == nil {
		out = &AppUserGrp{}
	} else {
		out, ok = into.(*AppUserGrp)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *AppUserGrp) Defaults(ver string) bool {
	return false
}

// Clone clones the object into into or creates one of into is nil
func (m *AppUserGrpList) Clone(into interface{}) (interface{}, error) {
	var out *AppUserGrpList
	var ok bool
	if into == nil {
		out = &AppUserGrpList{}
	} else {
		out, ok = into.(*AppUserGrpList)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *AppUserGrpList) Defaults(ver string) bool {
	return false
}

// Clone clones the object into into or creates one of into is nil
func (m *AppUserGrpSpec) Clone(into interface{}) (interface{}, error) {
	var out *AppUserGrpSpec
	var ok bool
	if into == nil {
		out = &AppUserGrpSpec{}
	} else {
		out, ok = into.(*AppUserGrpSpec)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *AppUserGrpSpec) Defaults(ver string) bool {
	return false
}

// Clone clones the object into into or creates one of into is nil
func (m *AppUserGrpStatus) Clone(into interface{}) (interface{}, error) {
	var out *AppUserGrpStatus
	var ok bool
	if into == nil {
		out = &AppUserGrpStatus{}
	} else {
		out, ok = into.(*AppUserGrpStatus)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *AppUserGrpStatus) Defaults(ver string) bool {
	return false
}

// Clone clones the object into into or creates one of into is nil
func (m *AppUserList) Clone(into interface{}) (interface{}, error) {
	var out *AppUserList
	var ok bool
	if into == nil {
		out = &AppUserList{}
	} else {
		out, ok = into.(*AppUserList)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *AppUserList) Defaults(ver string) bool {
	return false
}

// Clone clones the object into into or creates one of into is nil
func (m *AppUserSpec) Clone(into interface{}) (interface{}, error) {
	var out *AppUserSpec
	var ok bool
	if into == nil {
		out = &AppUserSpec{}
	} else {
		out, ok = into.(*AppUserSpec)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *AppUserSpec) Defaults(ver string) bool {
	return false
}

// Clone clones the object into into or creates one of into is nil
func (m *AppUserStatus) Clone(into interface{}) (interface{}, error) {
	var out *AppUserStatus
	var ok bool
	if into == nil {
		out = &AppUserStatus{}
	} else {
		out, ok = into.(*AppUserStatus)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *AppUserStatus) Defaults(ver string) bool {
	return false
}

// Clone clones the object into into or creates one of into is nil
func (m *AutoMsgAppUserGrpWatchHelper) Clone(into interface{}) (interface{}, error) {
	var out *AutoMsgAppUserGrpWatchHelper
	var ok bool
	if into == nil {
		out = &AutoMsgAppUserGrpWatchHelper{}
	} else {
		out, ok = into.(*AutoMsgAppUserGrpWatchHelper)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *AutoMsgAppUserGrpWatchHelper) Defaults(ver string) bool {
	return false
}

// Clone clones the object into into or creates one of into is nil
func (m *AutoMsgAppUserWatchHelper) Clone(into interface{}) (interface{}, error) {
	var out *AutoMsgAppUserWatchHelper
	var ok bool
	if into == nil {
		out = &AutoMsgAppUserWatchHelper{}
	} else {
		out, ok = into.(*AutoMsgAppUserWatchHelper)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *AutoMsgAppUserWatchHelper) Defaults(ver string) bool {
	return false
}

// Clone clones the object into into or creates one of into is nil
func (m *AutoMsgAppWatchHelper) Clone(into interface{}) (interface{}, error) {
	var out *AutoMsgAppWatchHelper
	var ok bool
	if into == nil {
		out = &AutoMsgAppWatchHelper{}
	} else {
		out, ok = into.(*AutoMsgAppWatchHelper)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}

// Default sets up the defaults for the object
func (m *AutoMsgAppWatchHelper) Defaults(ver string) bool {
	return false
}

// Validators

func (m *App) Validate(ver string, ignoreStatus bool) bool {
	return true
}

func (m *AppList) Validate(ver string, ignoreStatus bool) bool {
	return true
}

func (m *AppSpec) Validate(ver string, ignoreStatus bool) bool {
	return true
}

func (m *AppStatus) Validate(ver string, ignoreStatus bool) bool {
	return true
}

func (m *AppUser) Validate(ver string, ignoreStatus bool) bool {
	return true
}

func (m *AppUserGrp) Validate(ver string, ignoreStatus bool) bool {
	return true
}

func (m *AppUserGrpList) Validate(ver string, ignoreStatus bool) bool {
	return true
}

func (m *AppUserGrpSpec) Validate(ver string, ignoreStatus bool) bool {
	return true
}

func (m *AppUserGrpStatus) Validate(ver string, ignoreStatus bool) bool {
	return true
}

func (m *AppUserList) Validate(ver string, ignoreStatus bool) bool {
	return true
}

func (m *AppUserSpec) Validate(ver string, ignoreStatus bool) bool {
	return true
}

func (m *AppUserStatus) Validate(ver string, ignoreStatus bool) bool {
	return true
}

func (m *AutoMsgAppUserGrpWatchHelper) Validate(ver string, ignoreStatus bool) bool {
	return true
}

func (m *AutoMsgAppUserWatchHelper) Validate(ver string, ignoreStatus bool) bool {
	return true
}

func (m *AutoMsgAppWatchHelper) Validate(ver string, ignoreStatus bool) bool {
	return true
}

func init() {
}
