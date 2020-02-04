// Code generated by protoc-gen-go. DO NOT EDIT.
// source: delphi/app.proto

/*
Package dnetproto is a generated protocol buffer package.

It is generated from these files:
	delphi/app.proto
	delphi/endpoint.proto
	delphi/interface.proto
	delphi/ipam.proto
	delphi/network.proto
	delphi/profile.proto
	delphi/route.proto
	delphi/sgpolicy.proto
	delphi/secprofile.proto
	delphi/vrf.proto

It has these top-level messages:
	App
	Endpoint
	Interface
	IPAMPolicy
	Network
	Profile
	RoutingConfig
	NetworkSecurityPolicy
	SecurityProfile
	Vrf
*/
package dnetproto

import proto "github.com/golang/protobuf/proto"
import fmt "fmt"
import math "math"
import clientApi "github.com/pensando/sw/nic/delphi/gosdk/client_api"
import netproto1 "github.com/pensando/sw/nic/agent/protos/netproto"
import delphi "github.com/pensando/sw/nic/delphi/proto/delphi"

// Reference imports to suppress errors if they are not otherwise used.
var _ = proto.Marshal
var _ = fmt.Errorf
var _ = math.Inf

// This is a compile-time assertion to ensure that this generated file
// is compatible with the proto package it is being compiled against.
// A compilation error at this line likely means your copy of the
// proto package needs to be updated.
const _ = proto.ProtoPackageIsVersion2 // please upgrade the proto package

// app object
type App struct {
	Meta *delphi.ObjectMeta `protobuf:"bytes,1,opt,name=Meta" json:"Meta,omitempty"`
	Key  string             `protobuf:"bytes,2,opt,name=Key" json:"Key,omitempty"`
	App  *netproto1.App     `protobuf:"bytes,3,opt,name=App" json:"App,omitempty"`
}

func (m *App) GetDelphiMessage() proto.Message {
	return m
}

func (m *App) GetDelphiMeta() *delphi.ObjectMeta {
	return m.Meta
}

func (m *App) SetDelphiMeta(meta *delphi.ObjectMeta) {
	m.Meta = meta
}

func (m *App) GetDelphiKey() string {
	return fmt.Sprintf("%v", m.Key)
}

func (m *App) GetDelphiKind() string {
	return "App"
}

func (m *App) GetDelphiPath() string {
	return fmt.Sprintf("%s|%s", m.GetDelphiKind(), m.GetDelphiKey())
}

func (m *App) DelphiClone() clientApi.BaseObject {
	obj, _ := proto.Clone(m).(*App)
	return obj
}

func AppMount(client clientApi.Client, mode delphi.MountMode) {
	client.MountKind("App", mode)
}

func AppMountKey(client clientApi.Client, key string, mode delphi.MountMode) {
	client.MountKindKey("App", fmt.Sprintf("%v", key), mode)
}

func GetApp(client clientApi.Client, key string) *App {
	o := client.GetObject("App", fmt.Sprintf("%v", key))
	if o == nil {
		return nil
	}
	obj, ok := o.(*App)
	if ok != true {
		panic("Cast failed")
	}
	return obj
}

func (m *App) IsPersistent() bool {
	return false
}
func AppFactory(sdkClient clientApi.Client, data []byte) (clientApi.BaseObject, error) {
	var msg App
	err := proto.Unmarshal(data, &msg)
	if err != nil {
		return nil, err
	}
	return &msg, nil
}

func AppWatch(client clientApi.Client, reactor AppReactor) {
	client.WatchKind("App", reactor)
}
func AppList(client clientApi.Client) []*App {
	bobjs := client.List("App")
	objs := make([]*App, 0)
	for _, bobj := range bobjs {
		obj, _ := bobj.(*App)
		objs = append(objs, obj)
	}
	return objs
}
func (m *App) TriggerEvent(sdkClient clientApi.Client, old clientApi.BaseObject, op delphi.ObjectOperation, rl []clientApi.BaseReactor) {
	for _, r := range rl {
		rctr, ok := r.(AppReactor)
		if ok == false {
			panic("Not a Reactor")
		}
		if op == delphi.ObjectOperation_SetOp {
			if old == nil {
				rctr.OnAppCreate(m)
			} else {
				oldObj, ok := old.(*App)
				if ok == false {
					panic("Not an App object")
				}
				rctr.OnAppUpdate(oldObj, m)
			}
		} else {
			rctr.OnAppDelete(m)
		}
	}
}

type AppReactor interface {
	OnAppCreate(obj *App)
	OnAppUpdate(old *App, obj *App)
	OnAppDelete(obj *App)
}

func (m *App) Reset()                    { *m = App{} }
func (m *App) String() string            { return proto.CompactTextString(m) }
func (*App) ProtoMessage()               {}
func (*App) Descriptor() ([]byte, []int) { return fileDescriptor0, []int{0} }

func (m *App) GetMeta() *delphi.ObjectMeta {
	if m != nil {
		return m.Meta
	}
	return nil
}

func (m *App) GetKey() string {
	if m != nil {
		return m.Key
	}
	return ""
}

func (m *App) GetApp() *netproto1.App {
	if m != nil {
		return m.App
	}
	return nil
}

func init() {
	clientApi.RegisterFactory("App", AppFactory)
	proto.RegisterType((*App)(nil), "dnetproto.App")
}

func init() { proto.RegisterFile("delphi/app.proto", fileDescriptor0) }

var fileDescriptor0 = []byte{
	// 181 bytes of a gzipped FileDescriptorProto
	0x1f, 0x8b, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xff, 0xe2, 0x12, 0x48, 0x49, 0xcd, 0x29,
	0xc8, 0xc8, 0xd4, 0x4f, 0x2c, 0x28, 0xd0, 0x2b, 0x28, 0xca, 0x2f, 0xc9, 0x17, 0xe2, 0x4c, 0xc9,
	0x4b, 0x2d, 0x01, 0x33, 0xa5, 0xac, 0xd2, 0x33, 0x4b, 0x32, 0x4a, 0x93, 0xf4, 0x92, 0xf3, 0x73,
	0xf5, 0x0b, 0x52, 0xf3, 0x8a, 0x13, 0xf3, 0x52, 0xf2, 0xf5, 0x8b, 0xcb, 0xf5, 0xf3, 0x32, 0x93,
	0xf5, 0x13, 0xd3, 0x53, 0xf3, 0x4a, 0xf4, 0xc1, 0xea, 0x8a, 0xf5, 0x61, 0x3a, 0x10, 0xc6, 0x48,
	0xf1, 0x40, 0x0c, 0x86, 0xf0, 0x94, 0xd2, 0xb8, 0x98, 0x1d, 0x0b, 0x0a, 0x84, 0xd4, 0xb8, 0x58,
	0x7c, 0x53, 0x4b, 0x12, 0x25, 0x18, 0x15, 0x18, 0x35, 0xb8, 0x8d, 0x84, 0xf4, 0xa0, 0x6a, 0xfc,
	0x93, 0xb2, 0x52, 0x93, 0x4b, 0x40, 0x32, 0x41, 0x60, 0x79, 0x21, 0x01, 0x2e, 0x66, 0xef, 0xd4,
	0x4a, 0x09, 0x26, 0x05, 0x46, 0x0d, 0xce, 0x20, 0x10, 0x53, 0x48, 0x1e, 0x6c, 0x80, 0x04, 0x33,
	0x58, 0x23, 0xaf, 0x1e, 0xcc, 0x42, 0x3d, 0xc7, 0x82, 0x82, 0x20, 0x90, 0x8c, 0x15, 0x4b, 0xc3,
	0x74, 0x25, 0xc6, 0x24, 0x36, 0xb0, 0xa8, 0x31, 0x20, 0x00, 0x00, 0xff, 0xff, 0x4b, 0x68, 0x12,
	0x8f, 0xd7, 0x00, 0x00, 0x00,
}
