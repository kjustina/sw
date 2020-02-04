// Code generated by protoc-gen-grpc-pensando DO NOT EDIT.

/*
Package netprotoApiServer is a auto generated package.
Input file: vrf.proto
*/
package netproto

import (
	"reflect"

	"github.com/pensando/sw/api"
	"github.com/pensando/sw/venice/utils/runtime"
)

var typesMapVrf = map[string]*api.Struct{

	"netproto.Vrf": &api.Struct{
		Kind: "", APIGroup: "", Scopes: []string{}, GetTypeFn: func() reflect.Type { return reflect.TypeOf(Vrf{}) },
		Fields: map[string]api.Field{
			"TypeMeta": api.Field{Name: "TypeMeta", CLITag: api.CLIInfo{ID: "TypeMeta", Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "", Pointer: false, Slice: false, Mutable: true, Map: false, Inline: true, FromInline: false, KeyType: "", Type: "api.TypeMeta"},

			"ObjectMeta": api.Field{Name: "ObjectMeta", CLITag: api.CLIInfo{ID: "meta", Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "meta", Pointer: false, Slice: false, Mutable: true, Map: false, Inline: false, FromInline: false, KeyType: "", Type: "api.ObjectMeta"},

			"Spec": api.Field{Name: "Spec", CLITag: api.CLIInfo{ID: "spec", Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "spec", Pointer: false, Slice: false, Mutable: true, Map: false, Inline: false, FromInline: false, KeyType: "", Type: "netproto.VrfSpec"},

			"Status": api.Field{Name: "Status", CLITag: api.CLIInfo{ID: "status", Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "status", Pointer: false, Slice: false, Mutable: true, Map: false, Inline: false, FromInline: false, KeyType: "", Type: "netproto.VrfStatus"},

			"Kind": api.Field{Name: "Kind", CLITag: api.CLIInfo{ID: "kind", Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "kind", Pointer: false, Slice: false, Mutable: true, Map: false, Inline: false, FromInline: true, KeyType: "", Type: "TYPE_STRING"},

			"APIVersion": api.Field{Name: "APIVersion", CLITag: api.CLIInfo{ID: "api-version", Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "api-version", Pointer: false, Slice: false, Mutable: true, Map: false, Inline: false, FromInline: true, KeyType: "", Type: "TYPE_STRING"},

			"Name": api.Field{Name: "Name", CLITag: api.CLIInfo{ID: "name", Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "name", Pointer: false, Slice: false, Mutable: true, Map: false, Inline: false, FromInline: true, KeyType: "", Type: "TYPE_STRING"},

			"Tenant": api.Field{Name: "Tenant", CLITag: api.CLIInfo{ID: "tenant", Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "tenant", Pointer: false, Slice: false, Mutable: true, Map: false, Inline: false, FromInline: true, KeyType: "", Type: "TYPE_STRING"},

			"Namespace": api.Field{Name: "Namespace", CLITag: api.CLIInfo{ID: "namespace", Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "namespace", Pointer: false, Slice: false, Mutable: true, Map: false, Inline: false, FromInline: true, KeyType: "", Type: "TYPE_STRING"},

			"GenerationID": api.Field{Name: "GenerationID", CLITag: api.CLIInfo{ID: "generation-id", Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "generation-id", Pointer: false, Slice: false, Mutable: true, Map: false, Inline: false, FromInline: true, KeyType: "", Type: "TYPE_STRING"},

			"ResourceVersion": api.Field{Name: "ResourceVersion", CLITag: api.CLIInfo{ID: "resource-version", Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "resource-version", Pointer: false, Slice: false, Mutable: true, Map: false, Inline: false, FromInline: true, KeyType: "", Type: "TYPE_STRING"},

			"UUID": api.Field{Name: "UUID", CLITag: api.CLIInfo{ID: "uuid", Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "uuid", Pointer: false, Slice: false, Mutable: true, Map: false, Inline: false, FromInline: true, KeyType: "", Type: "TYPE_STRING"},

			"Labels": api.Field{Name: "Labels", CLITag: api.CLIInfo{ID: "labels", Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "labels", Pointer: true, Slice: false, Mutable: true, Map: true, Inline: false, FromInline: true, KeyType: "TYPE_STRING", Type: "TYPE_STRING"},

			"CreationTime": api.Field{Name: "CreationTime", CLITag: api.CLIInfo{ID: "creation-time", Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "creation-time", Pointer: false, Slice: false, Mutable: true, Map: false, Inline: false, FromInline: true, KeyType: "", Type: "api.Timestamp"},

			"ModTime": api.Field{Name: "ModTime", CLITag: api.CLIInfo{ID: "mod-time", Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "mod-time", Pointer: false, Slice: false, Mutable: true, Map: false, Inline: false, FromInline: true, KeyType: "", Type: "api.Timestamp"},

			"SelfLink": api.Field{Name: "SelfLink", CLITag: api.CLIInfo{ID: "self-link", Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "self-link", Pointer: false, Slice: false, Mutable: true, Map: false, Inline: false, FromInline: true, KeyType: "", Type: "TYPE_STRING"},
		},

		CLITags: map[string]api.CLIInfo{
			"api-version":       api.CLIInfo{Path: "APIVersion", Skip: false, Insert: "", Help: ""},
			"generation-id":     api.CLIInfo{Path: "GenerationID", Skip: false, Insert: "", Help: ""},
			"ipam-policy":       api.CLIInfo{Path: "Spec.IPAMPolicy", Skip: false, Insert: "", Help: ""},
			"kind":              api.CLIInfo{Path: "Kind", Skip: false, Insert: "", Help: ""},
			"labels":            api.CLIInfo{Path: "Labels", Skip: false, Insert: "", Help: ""},
			"name":              api.CLIInfo{Path: "Name", Skip: false, Insert: "", Help: ""},
			"namespace":         api.CLIInfo{Path: "Namespace", Skip: false, Insert: "", Help: ""},
			"resource-version":  api.CLIInfo{Path: "ResourceVersion", Skip: false, Insert: "", Help: ""},
			"router-mac":        api.CLIInfo{Path: "Spec.RouterMAC", Skip: false, Insert: "", Help: ""},
			"self-link":         api.CLIInfo{Path: "SelfLink", Skip: false, Insert: "", Help: ""},
			"tenant":            api.CLIInfo{Path: "Tenant", Skip: false, Insert: "", Help: ""},
			"uuid":              api.CLIInfo{Path: "UUID", Skip: false, Insert: "", Help: ""},
			"v4-route-table-id": api.CLIInfo{Path: "Spec.V4RouteTableID", Skip: false, Insert: "", Help: ""},
			"v6-route-table-id": api.CLIInfo{Path: "Spec.V6RouteTableID", Skip: false, Insert: "", Help: ""},
			"vrf-id":            api.CLIInfo{Path: "Status.VrfID", Skip: false, Insert: "", Help: ""},
			"vrf-type":          api.CLIInfo{Path: "Spec.VrfType", Skip: false, Insert: "", Help: ""},
			"vxlan-vni":         api.CLIInfo{Path: "Spec.VxLANVNI", Skip: false, Insert: "", Help: ""},
		},
	},
	"netproto.VrfEvent": &api.Struct{
		Kind: "", APIGroup: "", Scopes: []string{}, GetTypeFn: func() reflect.Type { return reflect.TypeOf(VrfEvent{}) },
		Fields: map[string]api.Field{
			"EventType": api.Field{Name: "EventType", CLITag: api.CLIInfo{ID: "event-type", Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "event-type", Pointer: false, Slice: false, Mutable: true, Map: false, Inline: false, FromInline: false, KeyType: "", Type: "TYPE_ENUM"},

			"Vrf": api.Field{Name: "Vrf", CLITag: api.CLIInfo{ID: "vrf", Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "vrf", Pointer: false, Slice: false, Mutable: true, Map: false, Inline: false, FromInline: false, KeyType: "", Type: "netproto.Vrf"},
		},
	},
	"netproto.VrfEventList": &api.Struct{
		Kind: "", APIGroup: "", Scopes: []string{}, GetTypeFn: func() reflect.Type { return reflect.TypeOf(VrfEventList{}) },
		Fields: map[string]api.Field{
			"VrfEvents": api.Field{Name: "VrfEvents", CLITag: api.CLIInfo{ID: "VrfEvents", Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "", Pointer: true, Slice: true, Mutable: true, Map: false, Inline: false, FromInline: false, KeyType: "", Type: "netproto.VrfEvent"},
		},
	},
	"netproto.VrfList": &api.Struct{
		Kind: "", APIGroup: "", Scopes: []string{}, GetTypeFn: func() reflect.Type { return reflect.TypeOf(VrfList{}) },
		Fields: map[string]api.Field{
			"vrfs": api.Field{Name: "vrfs", CLITag: api.CLIInfo{ID: "vrfs", Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "", Pointer: true, Slice: true, Mutable: true, Map: false, Inline: false, FromInline: false, KeyType: "", Type: "netproto.Vrf"},
		},
	},
	"netproto.VrfSpec": &api.Struct{
		Kind: "", APIGroup: "", Scopes: []string{}, GetTypeFn: func() reflect.Type { return reflect.TypeOf(VrfSpec{}) },
		Fields: map[string]api.Field{
			"VrfType": api.Field{Name: "VrfType", CLITag: api.CLIInfo{ID: "vrf-type", Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "vrf-type", Pointer: true, Slice: false, Mutable: true, Map: false, Inline: false, FromInline: false, KeyType: "", Type: "TYPE_STRING"},

			"V4RouteTableID": api.Field{Name: "V4RouteTableID", CLITag: api.CLIInfo{ID: "v4-route-table-id", Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "v4-route-table-id", Pointer: false, Slice: false, Mutable: true, Map: false, Inline: false, FromInline: false, KeyType: "", Type: "TYPE_UINT32"},

			"V6RouteTableID": api.Field{Name: "V6RouteTableID", CLITag: api.CLIInfo{ID: "v6-route-table-id", Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "v6-route-table-id", Pointer: false, Slice: false, Mutable: true, Map: false, Inline: false, FromInline: false, KeyType: "", Type: "TYPE_UINT32"},

			"RouterMAC": api.Field{Name: "RouterMAC", CLITag: api.CLIInfo{ID: "router-mac", Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "router-mac", Pointer: false, Slice: false, Mutable: true, Map: false, Inline: false, FromInline: false, KeyType: "", Type: "TYPE_STRING"},

			"VxLANVNI": api.Field{Name: "VxLANVNI", CLITag: api.CLIInfo{ID: "vxlan-vni", Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "vxlan-vni", Pointer: false, Slice: false, Mutable: true, Map: false, Inline: false, FromInline: false, KeyType: "", Type: "TYPE_UINT32"},

			"IPAMPolicy": api.Field{Name: "IPAMPolicy", CLITag: api.CLIInfo{ID: "ipam-policy", Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "ipam-policy", Pointer: false, Slice: false, Mutable: true, Map: false, Inline: false, FromInline: false, KeyType: "", Type: "TYPE_STRING"},

			"RouteImportExport": api.Field{Name: "RouteImportExport", CLITag: api.CLIInfo{ID: "route-import-export", Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "route-import-export", Pointer: true, Slice: false, Mutable: true, Map: false, Inline: false, FromInline: false, KeyType: "", Type: "netproto.RDSpec"},
		},
	},
	"netproto.VrfStatus": &api.Struct{
		Kind: "", APIGroup: "", Scopes: []string{}, GetTypeFn: func() reflect.Type { return reflect.TypeOf(VrfStatus{}) },
		Fields: map[string]api.Field{
			"VrfID": api.Field{Name: "VrfID", CLITag: api.CLIInfo{ID: "vrf-id", Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "vrf-id", Pointer: false, Slice: false, Mutable: true, Map: false, Inline: false, FromInline: false, KeyType: "", Type: "TYPE_UINT64"},
		},
	},
}

var keyMapVrf = map[string][]api.PathsMap{}

func init() {
	schema := runtime.GetDefaultScheme()
	schema.AddSchema(typesMapVrf)
	schema.AddPaths(keyMapVrf)
}
