// Code generated by protoc-gen-grpc-pensando DO NOT EDIT.

/*
Package monitoringApiServer is a auto generated package.
Input file: svc_monitoring.proto
*/
package monitoring

import (
	"reflect"

	"github.com/pensando/sw/api"
	"github.com/pensando/sw/venice/utils/runtime"
)

var typesMapSvc_monitoring = map[string]*api.Struct{

	"monitoring.AlertDestinationList": &api.Struct{
		Kind: "", APIGroup: "", GetTypeFn: func() reflect.Type { return reflect.TypeOf(AlertDestinationList{}) },
		Fields: map[string]api.Field{
			"TypeMeta": api.Field{Name: "TypeMeta", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "", Pointer: false, Slice: false, Map: false, Inline: true, FromInline: false, KeyType: "", Type: "api.TypeMeta"},

			"ListMeta": api.Field{Name: "ListMeta", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "list-meta", Pointer: false, Slice: false, Map: false, Inline: true, FromInline: false, KeyType: "", Type: "api.ListMeta"},

			"Items": api.Field{Name: "Items", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "items", Pointer: true, Slice: true, Map: false, Inline: false, FromInline: false, KeyType: "", Type: "monitoring.AlertDestination"},

			"Kind": api.Field{Name: "Kind", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "kind", Pointer: false, Slice: false, Map: false, Inline: false, FromInline: true, KeyType: "", Type: "TYPE_STRING"},

			"APIVersion": api.Field{Name: "APIVersion", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "api-version", Pointer: false, Slice: false, Map: false, Inline: false, FromInline: true, KeyType: "", Type: "TYPE_STRING"},

			"ResourceVersion": api.Field{Name: "ResourceVersion", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "resource-version", Pointer: false, Slice: false, Map: false, Inline: false, FromInline: true, KeyType: "", Type: "TYPE_STRING"},
		},
	},
	"monitoring.AlertList": &api.Struct{
		Kind: "", APIGroup: "", GetTypeFn: func() reflect.Type { return reflect.TypeOf(AlertList{}) },
		Fields: map[string]api.Field{
			"TypeMeta": api.Field{Name: "TypeMeta", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "", Pointer: false, Slice: false, Map: false, Inline: true, FromInline: false, KeyType: "", Type: "api.TypeMeta"},

			"ListMeta": api.Field{Name: "ListMeta", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "list-meta", Pointer: false, Slice: false, Map: false, Inline: true, FromInline: false, KeyType: "", Type: "api.ListMeta"},

			"Items": api.Field{Name: "Items", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "items", Pointer: true, Slice: true, Map: false, Inline: false, FromInline: false, KeyType: "", Type: "monitoring.Alert"},

			"Kind": api.Field{Name: "Kind", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "kind", Pointer: false, Slice: false, Map: false, Inline: false, FromInline: true, KeyType: "", Type: "TYPE_STRING"},

			"APIVersion": api.Field{Name: "APIVersion", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "api-version", Pointer: false, Slice: false, Map: false, Inline: false, FromInline: true, KeyType: "", Type: "TYPE_STRING"},

			"ResourceVersion": api.Field{Name: "ResourceVersion", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "resource-version", Pointer: false, Slice: false, Map: false, Inline: false, FromInline: true, KeyType: "", Type: "TYPE_STRING"},
		},
	},
	"monitoring.AlertPolicyList": &api.Struct{
		Kind: "", APIGroup: "", GetTypeFn: func() reflect.Type { return reflect.TypeOf(AlertPolicyList{}) },
		Fields: map[string]api.Field{
			"TypeMeta": api.Field{Name: "TypeMeta", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "", Pointer: false, Slice: false, Map: false, Inline: true, FromInline: false, KeyType: "", Type: "api.TypeMeta"},

			"ListMeta": api.Field{Name: "ListMeta", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "list-meta", Pointer: false, Slice: false, Map: false, Inline: true, FromInline: false, KeyType: "", Type: "api.ListMeta"},

			"Items": api.Field{Name: "Items", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "items", Pointer: true, Slice: true, Map: false, Inline: false, FromInline: false, KeyType: "", Type: "monitoring.AlertPolicy"},

			"Kind": api.Field{Name: "Kind", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "kind", Pointer: false, Slice: false, Map: false, Inline: false, FromInline: true, KeyType: "", Type: "TYPE_STRING"},

			"APIVersion": api.Field{Name: "APIVersion", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "api-version", Pointer: false, Slice: false, Map: false, Inline: false, FromInline: true, KeyType: "", Type: "TYPE_STRING"},

			"ResourceVersion": api.Field{Name: "ResourceVersion", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "resource-version", Pointer: false, Slice: false, Map: false, Inline: false, FromInline: true, KeyType: "", Type: "TYPE_STRING"},
		},
	},
	"monitoring.AutoMsgAlertDestinationWatchHelper": &api.Struct{
		Kind: "", APIGroup: "", GetTypeFn: func() reflect.Type { return reflect.TypeOf(AutoMsgAlertDestinationWatchHelper{}) },
		Fields: map[string]api.Field{
			"Events": api.Field{Name: "Events", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "events", Pointer: true, Slice: true, Map: false, Inline: false, FromInline: false, KeyType: "", Type: "monitoring.AutoMsgAlertDestinationWatchHelper.WatchEvent"},
		},
	},
	"monitoring.AutoMsgAlertDestinationWatchHelper.WatchEvent": &api.Struct{
		Kind: "", APIGroup: "", GetTypeFn: func() reflect.Type { return reflect.TypeOf(AutoMsgAlertDestinationWatchHelper_WatchEvent{}) },
		Fields: map[string]api.Field{
			"Type": api.Field{Name: "Type", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "type", Pointer: false, Slice: false, Map: false, Inline: false, FromInline: false, KeyType: "", Type: "TYPE_STRING"},

			"Object": api.Field{Name: "Object", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "object", Pointer: true, Slice: false, Map: false, Inline: false, FromInline: false, KeyType: "", Type: "monitoring.AlertDestination"},
		},
	},
	"monitoring.AutoMsgAlertPolicyWatchHelper": &api.Struct{
		Kind: "", APIGroup: "", GetTypeFn: func() reflect.Type { return reflect.TypeOf(AutoMsgAlertPolicyWatchHelper{}) },
		Fields: map[string]api.Field{
			"Events": api.Field{Name: "Events", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "events", Pointer: true, Slice: true, Map: false, Inline: false, FromInline: false, KeyType: "", Type: "monitoring.AutoMsgAlertPolicyWatchHelper.WatchEvent"},
		},
	},
	"monitoring.AutoMsgAlertPolicyWatchHelper.WatchEvent": &api.Struct{
		Kind: "", APIGroup: "", GetTypeFn: func() reflect.Type { return reflect.TypeOf(AutoMsgAlertPolicyWatchHelper_WatchEvent{}) },
		Fields: map[string]api.Field{
			"Type": api.Field{Name: "Type", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "type", Pointer: false, Slice: false, Map: false, Inline: false, FromInline: false, KeyType: "", Type: "TYPE_STRING"},

			"Object": api.Field{Name: "Object", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "object", Pointer: true, Slice: false, Map: false, Inline: false, FromInline: false, KeyType: "", Type: "monitoring.AlertPolicy"},
		},
	},
	"monitoring.AutoMsgAlertWatchHelper": &api.Struct{
		Kind: "", APIGroup: "", GetTypeFn: func() reflect.Type { return reflect.TypeOf(AutoMsgAlertWatchHelper{}) },
		Fields: map[string]api.Field{
			"Events": api.Field{Name: "Events", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "events", Pointer: true, Slice: true, Map: false, Inline: false, FromInline: false, KeyType: "", Type: "monitoring.AutoMsgAlertWatchHelper.WatchEvent"},
		},
	},
	"monitoring.AutoMsgAlertWatchHelper.WatchEvent": &api.Struct{
		Kind: "", APIGroup: "", GetTypeFn: func() reflect.Type { return reflect.TypeOf(AutoMsgAlertWatchHelper_WatchEvent{}) },
		Fields: map[string]api.Field{
			"Type": api.Field{Name: "Type", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "type", Pointer: false, Slice: false, Map: false, Inline: false, FromInline: false, KeyType: "", Type: "TYPE_STRING"},

			"Object": api.Field{Name: "Object", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "object", Pointer: true, Slice: false, Map: false, Inline: false, FromInline: false, KeyType: "", Type: "monitoring.Alert"},
		},
	},
	"monitoring.AutoMsgEventPolicyWatchHelper": &api.Struct{
		Kind: "", APIGroup: "", GetTypeFn: func() reflect.Type { return reflect.TypeOf(AutoMsgEventPolicyWatchHelper{}) },
		Fields: map[string]api.Field{
			"Events": api.Field{Name: "Events", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "events", Pointer: true, Slice: true, Map: false, Inline: false, FromInline: false, KeyType: "", Type: "monitoring.AutoMsgEventPolicyWatchHelper.WatchEvent"},
		},
	},
	"monitoring.AutoMsgEventPolicyWatchHelper.WatchEvent": &api.Struct{
		Kind: "", APIGroup: "", GetTypeFn: func() reflect.Type { return reflect.TypeOf(AutoMsgEventPolicyWatchHelper_WatchEvent{}) },
		Fields: map[string]api.Field{
			"Type": api.Field{Name: "Type", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "type", Pointer: false, Slice: false, Map: false, Inline: false, FromInline: false, KeyType: "", Type: "TYPE_STRING"},

			"Object": api.Field{Name: "Object", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "object", Pointer: true, Slice: false, Map: false, Inline: false, FromInline: false, KeyType: "", Type: "monitoring.EventPolicy"},
		},
	},
	"monitoring.AutoMsgFlowExportPolicyWatchHelper": &api.Struct{
		Kind: "", APIGroup: "", GetTypeFn: func() reflect.Type { return reflect.TypeOf(AutoMsgFlowExportPolicyWatchHelper{}) },
		Fields: map[string]api.Field{
			"Events": api.Field{Name: "Events", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "events", Pointer: true, Slice: true, Map: false, Inline: false, FromInline: false, KeyType: "", Type: "monitoring.AutoMsgFlowExportPolicyWatchHelper.WatchEvent"},
		},
	},
	"monitoring.AutoMsgFlowExportPolicyWatchHelper.WatchEvent": &api.Struct{
		Kind: "", APIGroup: "", GetTypeFn: func() reflect.Type { return reflect.TypeOf(AutoMsgFlowExportPolicyWatchHelper_WatchEvent{}) },
		Fields: map[string]api.Field{
			"Type": api.Field{Name: "Type", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "type", Pointer: false, Slice: false, Map: false, Inline: false, FromInline: false, KeyType: "", Type: "TYPE_STRING"},

			"Object": api.Field{Name: "Object", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "object", Pointer: true, Slice: false, Map: false, Inline: false, FromInline: false, KeyType: "", Type: "monitoring.FlowExportPolicy"},
		},
	},
	"monitoring.AutoMsgFwlogPolicyWatchHelper": &api.Struct{
		Kind: "", APIGroup: "", GetTypeFn: func() reflect.Type { return reflect.TypeOf(AutoMsgFwlogPolicyWatchHelper{}) },
		Fields: map[string]api.Field{
			"Events": api.Field{Name: "Events", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "events", Pointer: true, Slice: true, Map: false, Inline: false, FromInline: false, KeyType: "", Type: "monitoring.AutoMsgFwlogPolicyWatchHelper.WatchEvent"},
		},
	},
	"monitoring.AutoMsgFwlogPolicyWatchHelper.WatchEvent": &api.Struct{
		Kind: "", APIGroup: "", GetTypeFn: func() reflect.Type { return reflect.TypeOf(AutoMsgFwlogPolicyWatchHelper_WatchEvent{}) },
		Fields: map[string]api.Field{
			"Type": api.Field{Name: "Type", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "type", Pointer: false, Slice: false, Map: false, Inline: false, FromInline: false, KeyType: "", Type: "TYPE_STRING"},

			"Object": api.Field{Name: "Object", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "object", Pointer: true, Slice: false, Map: false, Inline: false, FromInline: false, KeyType: "", Type: "monitoring.FwlogPolicy"},
		},
	},
	"monitoring.AutoMsgMirrorSessionWatchHelper": &api.Struct{
		Kind: "", APIGroup: "", GetTypeFn: func() reflect.Type { return reflect.TypeOf(AutoMsgMirrorSessionWatchHelper{}) },
		Fields: map[string]api.Field{
			"Events": api.Field{Name: "Events", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "events", Pointer: true, Slice: true, Map: false, Inline: false, FromInline: false, KeyType: "", Type: "monitoring.AutoMsgMirrorSessionWatchHelper.WatchEvent"},
		},
	},
	"monitoring.AutoMsgMirrorSessionWatchHelper.WatchEvent": &api.Struct{
		Kind: "", APIGroup: "", GetTypeFn: func() reflect.Type { return reflect.TypeOf(AutoMsgMirrorSessionWatchHelper_WatchEvent{}) },
		Fields: map[string]api.Field{
			"Type": api.Field{Name: "Type", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "type", Pointer: false, Slice: false, Map: false, Inline: false, FromInline: false, KeyType: "", Type: "TYPE_STRING"},

			"Object": api.Field{Name: "Object", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "object", Pointer: true, Slice: false, Map: false, Inline: false, FromInline: false, KeyType: "", Type: "monitoring.MirrorSession"},
		},
	},
	"monitoring.AutoMsgStatsPolicyWatchHelper": &api.Struct{
		Kind: "", APIGroup: "", GetTypeFn: func() reflect.Type { return reflect.TypeOf(AutoMsgStatsPolicyWatchHelper{}) },
		Fields: map[string]api.Field{
			"Events": api.Field{Name: "Events", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "events", Pointer: true, Slice: true, Map: false, Inline: false, FromInline: false, KeyType: "", Type: "monitoring.AutoMsgStatsPolicyWatchHelper.WatchEvent"},
		},
	},
	"monitoring.AutoMsgStatsPolicyWatchHelper.WatchEvent": &api.Struct{
		Kind: "", APIGroup: "", GetTypeFn: func() reflect.Type { return reflect.TypeOf(AutoMsgStatsPolicyWatchHelper_WatchEvent{}) },
		Fields: map[string]api.Field{
			"Type": api.Field{Name: "Type", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "type", Pointer: false, Slice: false, Map: false, Inline: false, FromInline: false, KeyType: "", Type: "TYPE_STRING"},

			"Object": api.Field{Name: "Object", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "object", Pointer: true, Slice: false, Map: false, Inline: false, FromInline: false, KeyType: "", Type: "monitoring.StatsPolicy"},
		},
	},
	"monitoring.AutoMsgTroubleshootingSessionWatchHelper": &api.Struct{
		Kind: "", APIGroup: "", GetTypeFn: func() reflect.Type { return reflect.TypeOf(AutoMsgTroubleshootingSessionWatchHelper{}) },
		Fields: map[string]api.Field{
			"Events": api.Field{Name: "Events", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "events", Pointer: true, Slice: true, Map: false, Inline: false, FromInline: false, KeyType: "", Type: "monitoring.AutoMsgTroubleshootingSessionWatchHelper.WatchEvent"},
		},
	},
	"monitoring.AutoMsgTroubleshootingSessionWatchHelper.WatchEvent": &api.Struct{
		Kind: "", APIGroup: "", GetTypeFn: func() reflect.Type { return reflect.TypeOf(AutoMsgTroubleshootingSessionWatchHelper_WatchEvent{}) },
		Fields: map[string]api.Field{
			"Type": api.Field{Name: "Type", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "type", Pointer: false, Slice: false, Map: false, Inline: false, FromInline: false, KeyType: "", Type: "TYPE_STRING"},

			"Object": api.Field{Name: "Object", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "object", Pointer: true, Slice: false, Map: false, Inline: false, FromInline: false, KeyType: "", Type: "monitoring.TroubleshootingSession"},
		},
	},
	"monitoring.EventPolicyList": &api.Struct{
		Kind: "", APIGroup: "", GetTypeFn: func() reflect.Type { return reflect.TypeOf(EventPolicyList{}) },
		Fields: map[string]api.Field{
			"TypeMeta": api.Field{Name: "TypeMeta", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "", Pointer: false, Slice: false, Map: false, Inline: true, FromInline: false, KeyType: "", Type: "api.TypeMeta"},

			"ListMeta": api.Field{Name: "ListMeta", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "list-meta", Pointer: false, Slice: false, Map: false, Inline: true, FromInline: false, KeyType: "", Type: "api.ListMeta"},

			"Items": api.Field{Name: "Items", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "items", Pointer: true, Slice: true, Map: false, Inline: false, FromInline: false, KeyType: "", Type: "monitoring.EventPolicy"},

			"Kind": api.Field{Name: "Kind", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "kind", Pointer: false, Slice: false, Map: false, Inline: false, FromInline: true, KeyType: "", Type: "TYPE_STRING"},

			"APIVersion": api.Field{Name: "APIVersion", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "api-version", Pointer: false, Slice: false, Map: false, Inline: false, FromInline: true, KeyType: "", Type: "TYPE_STRING"},

			"ResourceVersion": api.Field{Name: "ResourceVersion", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "resource-version", Pointer: false, Slice: false, Map: false, Inline: false, FromInline: true, KeyType: "", Type: "TYPE_STRING"},
		},
	},
	"monitoring.FlowExportPolicyList": &api.Struct{
		Kind: "", APIGroup: "", GetTypeFn: func() reflect.Type { return reflect.TypeOf(FlowExportPolicyList{}) },
		Fields: map[string]api.Field{
			"TypeMeta": api.Field{Name: "TypeMeta", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "", Pointer: false, Slice: false, Map: false, Inline: true, FromInline: false, KeyType: "", Type: "api.TypeMeta"},

			"ListMeta": api.Field{Name: "ListMeta", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "list-meta", Pointer: false, Slice: false, Map: false, Inline: true, FromInline: false, KeyType: "", Type: "api.ListMeta"},

			"Items": api.Field{Name: "Items", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "items", Pointer: true, Slice: true, Map: false, Inline: false, FromInline: false, KeyType: "", Type: "monitoring.FlowExportPolicy"},

			"Kind": api.Field{Name: "Kind", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "kind", Pointer: false, Slice: false, Map: false, Inline: false, FromInline: true, KeyType: "", Type: "TYPE_STRING"},

			"APIVersion": api.Field{Name: "APIVersion", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "api-version", Pointer: false, Slice: false, Map: false, Inline: false, FromInline: true, KeyType: "", Type: "TYPE_STRING"},

			"ResourceVersion": api.Field{Name: "ResourceVersion", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "resource-version", Pointer: false, Slice: false, Map: false, Inline: false, FromInline: true, KeyType: "", Type: "TYPE_STRING"},
		},
	},
	"monitoring.FwlogPolicyList": &api.Struct{
		Kind: "", APIGroup: "", GetTypeFn: func() reflect.Type { return reflect.TypeOf(FwlogPolicyList{}) },
		Fields: map[string]api.Field{
			"TypeMeta": api.Field{Name: "TypeMeta", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "", Pointer: false, Slice: false, Map: false, Inline: true, FromInline: false, KeyType: "", Type: "api.TypeMeta"},

			"ListMeta": api.Field{Name: "ListMeta", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "list-meta", Pointer: false, Slice: false, Map: false, Inline: true, FromInline: false, KeyType: "", Type: "api.ListMeta"},

			"Items": api.Field{Name: "Items", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "items", Pointer: true, Slice: true, Map: false, Inline: false, FromInline: false, KeyType: "", Type: "monitoring.FwlogPolicy"},

			"Kind": api.Field{Name: "Kind", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "kind", Pointer: false, Slice: false, Map: false, Inline: false, FromInline: true, KeyType: "", Type: "TYPE_STRING"},

			"APIVersion": api.Field{Name: "APIVersion", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "api-version", Pointer: false, Slice: false, Map: false, Inline: false, FromInline: true, KeyType: "", Type: "TYPE_STRING"},

			"ResourceVersion": api.Field{Name: "ResourceVersion", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "resource-version", Pointer: false, Slice: false, Map: false, Inline: false, FromInline: true, KeyType: "", Type: "TYPE_STRING"},
		},
	},
	"monitoring.MirrorSessionList": &api.Struct{
		Kind: "", APIGroup: "", GetTypeFn: func() reflect.Type { return reflect.TypeOf(MirrorSessionList{}) },
		Fields: map[string]api.Field{
			"TypeMeta": api.Field{Name: "TypeMeta", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "", Pointer: false, Slice: false, Map: false, Inline: true, FromInline: false, KeyType: "", Type: "api.TypeMeta"},

			"ListMeta": api.Field{Name: "ListMeta", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "list-meta", Pointer: false, Slice: false, Map: false, Inline: true, FromInline: false, KeyType: "", Type: "api.ListMeta"},

			"Items": api.Field{Name: "Items", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "items", Pointer: true, Slice: true, Map: false, Inline: false, FromInline: false, KeyType: "", Type: "monitoring.MirrorSession"},

			"Kind": api.Field{Name: "Kind", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "kind", Pointer: false, Slice: false, Map: false, Inline: false, FromInline: true, KeyType: "", Type: "TYPE_STRING"},

			"APIVersion": api.Field{Name: "APIVersion", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "api-version", Pointer: false, Slice: false, Map: false, Inline: false, FromInline: true, KeyType: "", Type: "TYPE_STRING"},

			"ResourceVersion": api.Field{Name: "ResourceVersion", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "resource-version", Pointer: false, Slice: false, Map: false, Inline: false, FromInline: true, KeyType: "", Type: "TYPE_STRING"},
		},
	},
	"monitoring.StatsPolicyList": &api.Struct{
		Kind: "", APIGroup: "", GetTypeFn: func() reflect.Type { return reflect.TypeOf(StatsPolicyList{}) },
		Fields: map[string]api.Field{
			"TypeMeta": api.Field{Name: "TypeMeta", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "", Pointer: false, Slice: false, Map: false, Inline: true, FromInline: false, KeyType: "", Type: "api.TypeMeta"},

			"ListMeta": api.Field{Name: "ListMeta", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "list-meta", Pointer: false, Slice: false, Map: false, Inline: true, FromInline: false, KeyType: "", Type: "api.ListMeta"},

			"Items": api.Field{Name: "Items", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "items", Pointer: true, Slice: true, Map: false, Inline: false, FromInline: false, KeyType: "", Type: "monitoring.StatsPolicy"},

			"Kind": api.Field{Name: "Kind", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "kind", Pointer: false, Slice: false, Map: false, Inline: false, FromInline: true, KeyType: "", Type: "TYPE_STRING"},

			"APIVersion": api.Field{Name: "APIVersion", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "api-version", Pointer: false, Slice: false, Map: false, Inline: false, FromInline: true, KeyType: "", Type: "TYPE_STRING"},

			"ResourceVersion": api.Field{Name: "ResourceVersion", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "resource-version", Pointer: false, Slice: false, Map: false, Inline: false, FromInline: true, KeyType: "", Type: "TYPE_STRING"},
		},
	},
	"monitoring.TroubleshootingSessionList": &api.Struct{
		Kind: "", APIGroup: "", GetTypeFn: func() reflect.Type { return reflect.TypeOf(TroubleshootingSessionList{}) },
		Fields: map[string]api.Field{
			"TypeMeta": api.Field{Name: "TypeMeta", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "", Pointer: false, Slice: false, Map: false, Inline: true, FromInline: false, KeyType: "", Type: "api.TypeMeta"},

			"ListMeta": api.Field{Name: "ListMeta", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "list-meta", Pointer: false, Slice: false, Map: false, Inline: true, FromInline: false, KeyType: "", Type: "api.ListMeta"},

			"Items": api.Field{Name: "Items", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "items", Pointer: true, Slice: true, Map: false, Inline: false, FromInline: false, KeyType: "", Type: "monitoring.TroubleshootingSession"},

			"Kind": api.Field{Name: "Kind", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "kind", Pointer: false, Slice: false, Map: false, Inline: false, FromInline: true, KeyType: "", Type: "TYPE_STRING"},

			"APIVersion": api.Field{Name: "APIVersion", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "api-version", Pointer: false, Slice: false, Map: false, Inline: false, FromInline: true, KeyType: "", Type: "TYPE_STRING"},

			"ResourceVersion": api.Field{Name: "ResourceVersion", CLITag: api.CLIInfo{Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "resource-version", Pointer: false, Slice: false, Map: false, Inline: false, FromInline: true, KeyType: "", Type: "TYPE_STRING"},
		},
	},
}

func init() {
	schema := runtime.GetDefaultScheme()
	schema.AddSchema(typesMapSvc_monitoring)
}
