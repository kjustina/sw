// Code generated by protoc-gen-grpc-pensando DO NOT EDIT.

/*
Package securityApiServer is a auto generated package.
Input file: app.proto
*/
package security

import (
	"reflect"

	"github.com/pensando/sw/api"
	"github.com/pensando/sw/venice/utils/runtime"
)

var typesMapApp = map[string]*api.Struct{

	"security.ALG": &api.Struct{
		Kind: "", APIGroup: "", Scopes: []string{}, GetTypeFn: func() reflect.Type { return reflect.TypeOf(ALG{}) },
		Fields: map[string]api.Field{
			"Type": api.Field{Name: "Type", CLITag: api.CLIInfo{ID: "Type", Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "", Pointer: false, Slice: false, Map: false, Inline: false, FromInline: false, KeyType: "", Type: "TYPE_STRING"},

			"IcmpAlg": api.Field{Name: "IcmpAlg", CLITag: api.CLIInfo{ID: "icmp", Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "icmp", Pointer: true, Slice: false, Map: false, Inline: false, FromInline: false, KeyType: "", Type: "security.IcmpAlg"},

			"DnsAlg": api.Field{Name: "DnsAlg", CLITag: api.CLIInfo{ID: "dns", Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "dns", Pointer: true, Slice: false, Map: false, Inline: false, FromInline: false, KeyType: "", Type: "security.DnsAlg"},

			"FtpAlg": api.Field{Name: "FtpAlg", CLITag: api.CLIInfo{ID: "ftp", Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "ftp", Pointer: true, Slice: false, Map: false, Inline: false, FromInline: false, KeyType: "", Type: "security.FtpAlg"},

			"SunrpcAlg": api.Field{Name: "SunrpcAlg", CLITag: api.CLIInfo{ID: "sunrpc", Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "sunrpc", Pointer: true, Slice: false, Map: false, Inline: false, FromInline: false, KeyType: "", Type: "security.SunrpcAlg"},

			"MsrpcAlg": api.Field{Name: "MsrpcAlg", CLITag: api.CLIInfo{ID: "msrpc", Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "msrpc", Pointer: true, Slice: false, Map: false, Inline: false, FromInline: false, KeyType: "", Type: "security.MsrpcAlg"},
		},
	},
	"security.App": &api.Struct{
		Kind: "App", APIGroup: "security", Scopes: []string{"Tenant"}, GetTypeFn: func() reflect.Type { return reflect.TypeOf(App{}) },
		Fields: map[string]api.Field{
			"TypeMeta": api.Field{Name: "TypeMeta", CLITag: api.CLIInfo{ID: "T", Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "", Pointer: false, Slice: false, Map: false, Inline: true, FromInline: false, KeyType: "", Type: "api.TypeMeta"},

			"ObjectMeta": api.Field{Name: "ObjectMeta", CLITag: api.CLIInfo{ID: "meta", Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "meta", Pointer: false, Slice: false, Map: false, Inline: false, FromInline: false, KeyType: "", Type: "api.ObjectMeta"},

			"Spec": api.Field{Name: "Spec", CLITag: api.CLIInfo{ID: "spec", Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "spec", Pointer: false, Slice: false, Map: false, Inline: false, FromInline: false, KeyType: "", Type: "security.AppSpec"},

			"Status": api.Field{Name: "Status", CLITag: api.CLIInfo{ID: "status", Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "status", Pointer: false, Slice: false, Map: false, Inline: false, FromInline: false, KeyType: "", Type: "security.AppStatus"},

			"Kind": api.Field{Name: "Kind", CLITag: api.CLIInfo{ID: "kind", Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "kind", Pointer: false, Slice: false, Map: false, Inline: false, FromInline: true, KeyType: "", Type: "TYPE_STRING"},

			"APIVersion": api.Field{Name: "APIVersion", CLITag: api.CLIInfo{ID: "api-version", Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "api-version", Pointer: false, Slice: false, Map: false, Inline: false, FromInline: true, KeyType: "", Type: "TYPE_STRING"},

			"Name": api.Field{Name: "Name", CLITag: api.CLIInfo{ID: "name", Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "name", Pointer: false, Slice: false, Map: false, Inline: false, FromInline: true, KeyType: "", Type: "TYPE_STRING"},

			"Tenant": api.Field{Name: "Tenant", CLITag: api.CLIInfo{ID: "tenant", Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "tenant", Pointer: false, Slice: false, Map: false, Inline: false, FromInline: true, KeyType: "", Type: "TYPE_STRING"},

			"Namespace": api.Field{Name: "Namespace", CLITag: api.CLIInfo{ID: "namespace", Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "namespace", Pointer: false, Slice: false, Map: false, Inline: false, FromInline: true, KeyType: "", Type: "TYPE_STRING"},

			"GenerationID": api.Field{Name: "GenerationID", CLITag: api.CLIInfo{ID: "generation-id", Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "generation-id", Pointer: false, Slice: false, Map: false, Inline: false, FromInline: true, KeyType: "", Type: "TYPE_STRING"},

			"ResourceVersion": api.Field{Name: "ResourceVersion", CLITag: api.CLIInfo{ID: "resource-version", Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "resource-version", Pointer: false, Slice: false, Map: false, Inline: false, FromInline: true, KeyType: "", Type: "TYPE_STRING"},

			"UUID": api.Field{Name: "UUID", CLITag: api.CLIInfo{ID: "uuid", Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "uuid", Pointer: false, Slice: false, Map: false, Inline: false, FromInline: true, KeyType: "", Type: "TYPE_STRING"},

			"Labels": api.Field{Name: "Labels", CLITag: api.CLIInfo{ID: "labels", Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "labels", Pointer: true, Slice: false, Map: true, Inline: false, FromInline: true, KeyType: "TYPE_STRING", Type: "TYPE_STRING"},

			"CreationTime": api.Field{Name: "CreationTime", CLITag: api.CLIInfo{ID: "creation-time", Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "creation-time", Pointer: false, Slice: false, Map: false, Inline: false, FromInline: true, KeyType: "", Type: "api.Timestamp"},

			"ModTime": api.Field{Name: "ModTime", CLITag: api.CLIInfo{ID: "mod-time", Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "mod-time", Pointer: false, Slice: false, Map: false, Inline: false, FromInline: true, KeyType: "", Type: "api.Timestamp"},

			"SelfLink": api.Field{Name: "SelfLink", CLITag: api.CLIInfo{ID: "self-link", Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "self-link", Pointer: false, Slice: false, Map: false, Inline: false, FromInline: true, KeyType: "", Type: "TYPE_STRING"},
		},

		CLITags: map[string]api.CLIInfo{
			"Type":                           api.CLIInfo{Path: "Spec.ALG.Type", Skip: false, Insert: "", Help: ""},
			"allow-mismatch-ip-address":      api.CLIInfo{Path: "Spec.ALG.FtpAlg.AllowMismatchIPAddress", Skip: false, Insert: "", Help: ""},
			"api-version":                    api.CLIInfo{Path: "APIVersion", Skip: false, Insert: "", Help: ""},
			"attached-policies":              api.CLIInfo{Path: "Status.AttachedPolicies", Skip: false, Insert: "", Help: ""},
			"code":                           api.CLIInfo{Path: "Spec.ALG.IcmpAlg.Code", Skip: false, Insert: "", Help: ""},
			"drop-large-domain-name-packets": api.CLIInfo{Path: "Spec.ALG.DnsAlg.DropLargeDomainNamePackets", Skip: false, Insert: "", Help: ""},
			"drop-long-label-packets":        api.CLIInfo{Path: "Spec.ALG.DnsAlg.DropLongLabelPackets", Skip: false, Insert: "", Help: ""},
			"drop-multi-question-packets":    api.CLIInfo{Path: "Spec.ALG.DnsAlg.DropMultiQuestionPackets", Skip: false, Insert: "", Help: ""},
			"drop-multi-zone-packets":        api.CLIInfo{Path: "Spec.ALG.DnsAlg.DropMultiZonePackets", Skip: false, Insert: "", Help: ""},
			"generation-id":                  api.CLIInfo{Path: "GenerationID", Skip: false, Insert: "", Help: ""},
			"kind":                           api.CLIInfo{Path: "Kind", Skip: false, Insert: "", Help: ""},
			"labels":                         api.CLIInfo{Path: "Labels", Skip: false, Insert: "", Help: ""},
			"max-message-length":             api.CLIInfo{Path: "Spec.ALG.DnsAlg.MaxMessageLength", Skip: false, Insert: "", Help: ""},
			"name":                           api.CLIInfo{Path: "Name", Skip: false, Insert: "", Help: ""},
			"namespace":                      api.CLIInfo{Path: "Namespace", Skip: false, Insert: "", Help: ""},
			"program-id":                     api.CLIInfo{Path: "Spec.ALG.SunrpcAlg.ProgramID", Skip: false, Insert: "", Help: ""},
			"program-uuid":                   api.CLIInfo{Path: "Spec.ALG.MsrpcAlg.ProgramUUID", Skip: false, Insert: "", Help: ""},
			"query-response-timeout":         api.CLIInfo{Path: "Spec.ALG.DnsAlg.QueryResponseTimeout", Skip: false, Insert: "", Help: ""},
			"resource-version":               api.CLIInfo{Path: "ResourceVersion", Skip: false, Insert: "", Help: ""},
			"self-link":                      api.CLIInfo{Path: "SelfLink", Skip: false, Insert: "", Help: ""},
			"tenant":                         api.CLIInfo{Path: "Tenant", Skip: false, Insert: "", Help: ""},
			"timeout":                        api.CLIInfo{Path: "Spec.Timeout", Skip: false, Insert: "", Help: ""},
			"type":                           api.CLIInfo{Path: "Spec.ALG.IcmpAlg.Type", Skip: false, Insert: "", Help: ""},
			"uuid":                           api.CLIInfo{Path: "UUID", Skip: false, Insert: "", Help: ""},
		},
	},
	"security.AppSpec": &api.Struct{
		Kind: "", APIGroup: "", Scopes: []string{}, GetTypeFn: func() reflect.Type { return reflect.TypeOf(AppSpec{}) },
		Fields: map[string]api.Field{
			"ProtoPorts": api.Field{Name: "ProtoPorts", CLITag: api.CLIInfo{ID: "proto-ports", Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "proto-ports", Pointer: false, Slice: true, Map: false, Inline: false, FromInline: false, KeyType: "", Type: "security.ProtoPort"},

			"Timeout": api.Field{Name: "Timeout", CLITag: api.CLIInfo{ID: "timeout", Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "timeout", Pointer: false, Slice: false, Map: false, Inline: false, FromInline: false, KeyType: "", Type: "TYPE_STRING"},

			"ALG": api.Field{Name: "ALG", CLITag: api.CLIInfo{ID: "alg", Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "alg", Pointer: true, Slice: false, Map: false, Inline: false, FromInline: false, KeyType: "", Type: "security.ALG"},
		},
	},
	"security.AppStatus": &api.Struct{
		Kind: "", APIGroup: "", Scopes: []string{}, GetTypeFn: func() reflect.Type { return reflect.TypeOf(AppStatus{}) },
		Fields: map[string]api.Field{
			"AttachedPolicies": api.Field{Name: "AttachedPolicies", CLITag: api.CLIInfo{ID: "attached-policies", Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "attached-policies", Pointer: false, Slice: true, Map: false, Inline: false, FromInline: false, KeyType: "", Type: "TYPE_STRING"},
		},
	},
	"security.DnsAlg": &api.Struct{
		Kind: "", APIGroup: "", Scopes: []string{}, GetTypeFn: func() reflect.Type { return reflect.TypeOf(DnsAlg{}) },
		Fields: map[string]api.Field{
			"DropMultiQuestionPackets": api.Field{Name: "DropMultiQuestionPackets", CLITag: api.CLIInfo{ID: "drop-multi-question-packets", Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "drop-multi-question-packets", Pointer: false, Slice: false, Map: false, Inline: false, FromInline: false, KeyType: "", Type: "TYPE_BOOL"},

			"DropLargeDomainNamePackets": api.Field{Name: "DropLargeDomainNamePackets", CLITag: api.CLIInfo{ID: "drop-large-domain-name-packets", Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "drop-large-domain-name-packets", Pointer: false, Slice: false, Map: false, Inline: false, FromInline: false, KeyType: "", Type: "TYPE_BOOL"},

			"DropLongLabelPackets": api.Field{Name: "DropLongLabelPackets", CLITag: api.CLIInfo{ID: "drop-long-label-packets", Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "drop-long-label-packets", Pointer: false, Slice: false, Map: false, Inline: false, FromInline: false, KeyType: "", Type: "TYPE_BOOL"},

			"DropMultiZonePackets": api.Field{Name: "DropMultiZonePackets", CLITag: api.CLIInfo{ID: "drop-multi-zone-packets", Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "drop-multi-zone-packets", Pointer: false, Slice: false, Map: false, Inline: false, FromInline: false, KeyType: "", Type: "TYPE_BOOL"},

			"MaxMessageLength": api.Field{Name: "MaxMessageLength", CLITag: api.CLIInfo{ID: "max-message-length", Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "max-message-length", Pointer: false, Slice: false, Map: false, Inline: false, FromInline: false, KeyType: "", Type: "TYPE_UINT32"},

			"QueryResponseTimeout": api.Field{Name: "QueryResponseTimeout", CLITag: api.CLIInfo{ID: "query-response-timeout", Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "query-response-timeout", Pointer: false, Slice: false, Map: false, Inline: false, FromInline: false, KeyType: "", Type: "TYPE_STRING"},
		},
	},
	"security.FtpAlg": &api.Struct{
		Kind: "", APIGroup: "", Scopes: []string{}, GetTypeFn: func() reflect.Type { return reflect.TypeOf(FtpAlg{}) },
		Fields: map[string]api.Field{
			"AllowMismatchIPAddress": api.Field{Name: "AllowMismatchIPAddress", CLITag: api.CLIInfo{ID: "allow-mismatch-ip-address", Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "allow-mismatch-ip-address", Pointer: false, Slice: false, Map: false, Inline: false, FromInline: false, KeyType: "", Type: "TYPE_BOOL"},
		},
	},
	"security.IcmpAlg": &api.Struct{
		Kind: "", APIGroup: "", Scopes: []string{}, GetTypeFn: func() reflect.Type { return reflect.TypeOf(IcmpAlg{}) },
		Fields: map[string]api.Field{
			"Type": api.Field{Name: "Type", CLITag: api.CLIInfo{ID: "type", Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "type", Pointer: false, Slice: false, Map: false, Inline: false, FromInline: false, KeyType: "", Type: "TYPE_STRING"},

			"Code": api.Field{Name: "Code", CLITag: api.CLIInfo{ID: "code", Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "code", Pointer: false, Slice: false, Map: false, Inline: false, FromInline: false, KeyType: "", Type: "TYPE_STRING"},
		},
	},
	"security.MsrpcAlg": &api.Struct{
		Kind: "", APIGroup: "", Scopes: []string{}, GetTypeFn: func() reflect.Type { return reflect.TypeOf(MsrpcAlg{}) },
		Fields: map[string]api.Field{
			"ProgramUUID": api.Field{Name: "ProgramUUID", CLITag: api.CLIInfo{ID: "program-uuid", Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "program-uuid", Pointer: false, Slice: false, Map: false, Inline: false, FromInline: false, KeyType: "", Type: "TYPE_STRING"},
		},
	},
	"security.SunrpcAlg": &api.Struct{
		Kind: "", APIGroup: "", Scopes: []string{}, GetTypeFn: func() reflect.Type { return reflect.TypeOf(SunrpcAlg{}) },
		Fields: map[string]api.Field{
			"ProgramID": api.Field{Name: "ProgramID", CLITag: api.CLIInfo{ID: "program-id", Path: "", Skip: false, Insert: "", Help: ""}, JSONTag: "program-id", Pointer: false, Slice: false, Map: false, Inline: false, FromInline: false, KeyType: "", Type: "TYPE_STRING"},
		},
	},
}

func init() {
	schema := runtime.GetDefaultScheme()
	schema.AddSchema(typesMapApp)
}
