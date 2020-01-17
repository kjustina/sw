// Code generated by protoc-gen-go. DO NOT EDIT.
// source: delphi/network.proto

package dnetproto

import proto "github.com/golang/protobuf/proto"
import fmt "fmt"
import math "math"
import clientApi "github.com/pensando/sw/nic/delphi/gosdk/client_api"
import netproto5 "github.com/pensando/sw/nic/agent/protos/netproto"
import delphi "github.com/pensando/sw/nic/delphi/proto/delphi"

// Reference imports to suppress errors if they are not otherwise used.
var _ = proto.Marshal
var _ = fmt.Errorf
var _ = math.Inf

// network object
type Network struct {
	Meta    *delphi.ObjectMeta `protobuf:"bytes,1,opt,name=Meta" json:"Meta,omitempty"`
	Key     string             `protobuf:"bytes,2,opt,name=Key" json:"Key,omitempty"`
	Network *netproto5.Network `protobuf:"bytes,3,opt,name=Network" json:"Network,omitempty"`
}

func (m *Network) GetDelphiMessage() proto.Message {
	return m
}

func (m *Network) GetDelphiMeta() *delphi.ObjectMeta {
	return m.Meta
}

func (m *Network) SetDelphiMeta(meta *delphi.ObjectMeta) {
	m.Meta = meta
}

func (m *Network) GetDelphiKey() string {
	return fmt.Sprintf("%v", m.Key)
}

func (m *Network) GetDelphiKind() string {
	return "Network"
}

func (m *Network) GetDelphiPath() string {
	return fmt.Sprintf("%s|%s", m.GetDelphiKind(), m.GetDelphiKey())
}

func (m *Network) DelphiClone() clientApi.BaseObject {
	obj, _ := proto.Clone(m).(*Network)
	return obj
}

func NetworkMount(client clientApi.Client, mode delphi.MountMode) {
	client.MountKind("Network", mode)
}

func NetworkMountKey(client clientApi.Client, key string, mode delphi.MountMode) {
	client.MountKindKey("Network", fmt.Sprintf("%v", key), mode)
}

func GetNetwork(client clientApi.Client, key string) *Network {
	o := client.GetObject("Network", fmt.Sprintf("%v", key))
	if o == nil {
		return nil
	}
	obj, ok := o.(*Network)
	if ok != true {
		panic("Cast failed")
	}
	return obj
}

func (m *Network) IsPersistent() bool {
	return false
}
func NetworkFactory(sdkClient clientApi.Client, data []byte) (clientApi.BaseObject, error) {
	var msg Network
	err := proto.Unmarshal(data, &msg)
	if err != nil {
		return nil, err
	}
	return &msg, nil
}

func NetworkWatch(client clientApi.Client, reactor NetworkReactor) {
	client.WatchKind("Network", reactor)
}
func NetworkList(client clientApi.Client) []*Network {
	bobjs := client.List("Network")
	objs := make([]*Network, 0)
	for _, bobj := range bobjs {
		obj, _ := bobj.(*Network)
		objs = append(objs, obj)
	}
	return objs
}
func (m *Network) TriggerEvent(sdkClient clientApi.Client, old clientApi.BaseObject, op delphi.ObjectOperation, rl []clientApi.BaseReactor) {
	for _, r := range rl {
		rctr, ok := r.(NetworkReactor)
		if ok == false {
			panic("Not a Reactor")
		}
		if op == delphi.ObjectOperation_SetOp {
			if old == nil {
				rctr.OnNetworkCreate(m)
			} else {
				oldObj, ok := old.(*Network)
				if ok == false {
					panic("Not an Network object")
				}
				rctr.OnNetworkUpdate(oldObj, m)
			}
		} else {
			rctr.OnNetworkDelete(m)
		}
	}
}

type NetworkReactor interface {
	OnNetworkCreate(obj *Network)
	OnNetworkUpdate(old *Network, obj *Network)
	OnNetworkDelete(obj *Network)
}

func (m *Network) Reset()                    { *m = Network{} }
func (m *Network) String() string            { return proto.CompactTextString(m) }
func (*Network) ProtoMessage()               {}
func (*Network) Descriptor() ([]byte, []int) { return fileDescriptor4, []int{0} }

func (m *Network) GetMeta() *delphi.ObjectMeta {
	if m != nil {
		return m.Meta
	}
	return nil
}

func (m *Network) GetKey() string {
	if m != nil {
		return m.Key
	}
	return ""
}

func (m *Network) GetNetwork() *netproto5.Network {
	if m != nil {
		return m.Network
	}
	return nil
}

func init() {
	clientApi.RegisterFactory("Network", NetworkFactory)
	proto.RegisterType((*Network)(nil), "dnetproto.Network")
}

func init() { proto.RegisterFile("delphi/network.proto", fileDescriptor4) }

var fileDescriptor4 = []byte{
	// 184 bytes of a gzipped FileDescriptorProto
	0x1f, 0x8b, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xff, 0xe2, 0x12, 0x49, 0x49, 0xcd, 0x29,
	0xc8, 0xc8, 0xd4, 0xcf, 0x4b, 0x2d, 0x29, 0xcf, 0x2f, 0xca, 0xd6, 0x2b, 0x28, 0xca, 0x2f, 0xc9,
	0x17, 0xe2, 0x4c, 0xc9, 0x4b, 0x2d, 0x01, 0x33, 0xa5, 0xec, 0xd2, 0x33, 0x4b, 0x32, 0x4a, 0x93,
	0xf4, 0x92, 0xf3, 0x73, 0xf5, 0x0b, 0x52, 0xf3, 0x8a, 0x13, 0xf3, 0x52, 0xf2, 0xf5, 0x8b, 0xcb,
	0xf5, 0xf3, 0x32, 0x93, 0xf5, 0x13, 0xd3, 0x53, 0xf3, 0x4a, 0xf4, 0xc1, 0xea, 0x8a, 0xf5, 0x61,
	0x3a, 0x50, 0x8d, 0x92, 0xe2, 0x81, 0x58, 0x00, 0xe1, 0x29, 0x95, 0x71, 0xb1, 0xfb, 0x41, 0xa4,
	0x85, 0xd4, 0xb8, 0x58, 0x7c, 0x53, 0x4b, 0x12, 0x25, 0x18, 0x15, 0x18, 0x35, 0xb8, 0x8d, 0x84,
	0xf4, 0xa0, 0xea, 0xfc, 0x93, 0xb2, 0x52, 0x93, 0x4b, 0x40, 0x32, 0x41, 0x60, 0x79, 0x21, 0x01,
	0x2e, 0x66, 0xef, 0xd4, 0x4a, 0x09, 0x26, 0x05, 0x46, 0x0d, 0xce, 0x20, 0x10, 0x53, 0x48, 0x1b,
	0x6e, 0x88, 0x04, 0x33, 0x58, 0xb3, 0xa0, 0x1e, 0xcc, 0x72, 0x3d, 0xa8, 0x44, 0x10, 0x4c, 0x85,
	0x15, 0x4b, 0xc3, 0x74, 0x25, 0xc6, 0x24, 0x36, 0xb0, 0xac, 0x31, 0x20, 0x00, 0x00, 0xff, 0xff,
	0x4e, 0xde, 0xcc, 0x2b, 0xef, 0x00, 0x00, 0x00,
}
