// Code generated by protoc-gen-go. DO NOT EDIT.
// source: delphi/sgpolicy.proto

package dnetproto

import proto "github.com/golang/protobuf/proto"
import fmt "fmt"
import math "math"
import clientApi "github.com/pensando/sw/nic/delphi/gosdk/client_api"
import netproto7 "github.com/pensando/sw/nic/agent/protos/netproto"
import delphi "github.com/pensando/sw/nic/delphi/proto/delphi"

// Reference imports to suppress errors if they are not otherwise used.
var _ = proto.Marshal
var _ = fmt.Errorf
var _ = math.Inf

// NetworkSecurityPolicy object
type NetworkSecurityPolicy struct {
	Meta                  *delphi.ObjectMeta               `protobuf:"bytes,1,opt,name=Meta" json:"Meta,omitempty"`
	Key                   string                           `protobuf:"bytes,2,opt,name=Key" json:"Key,omitempty"`
	NetworkSecurityPolicy *netproto7.NetworkSecurityPolicy `protobuf:"bytes,3,opt,name=NetworkSecurityPolicy" json:"NetworkSecurityPolicy,omitempty"`
}

func (m *NetworkSecurityPolicy) GetDelphiMessage() proto.Message {
	return m
}

func (m *NetworkSecurityPolicy) GetDelphiMeta() *delphi.ObjectMeta {
	return m.Meta
}

func (m *NetworkSecurityPolicy) SetDelphiMeta(meta *delphi.ObjectMeta) {
	m.Meta = meta
}

func (m *NetworkSecurityPolicy) GetDelphiKey() string {
	return fmt.Sprintf("%v", m.Key)
}

func (m *NetworkSecurityPolicy) GetDelphiKind() string {
	return "NetworkSecurityPolicy"
}

func (m *NetworkSecurityPolicy) GetDelphiPath() string {
	return fmt.Sprintf("%s|%s", m.GetDelphiKind(), m.GetDelphiKey())
}

func (m *NetworkSecurityPolicy) DelphiClone() clientApi.BaseObject {
	obj, _ := proto.Clone(m).(*NetworkSecurityPolicy)
	return obj
}

func NetworkSecurityPolicyMount(client clientApi.Client, mode delphi.MountMode) {
	client.MountKind("NetworkSecurityPolicy", mode)
}

func NetworkSecurityPolicyMountKey(client clientApi.Client, key string, mode delphi.MountMode) {
	client.MountKindKey("NetworkSecurityPolicy", fmt.Sprintf("%v", key), mode)
}

func GetNetworkSecurityPolicy(client clientApi.Client, key string) *NetworkSecurityPolicy {
	o := client.GetObject("NetworkSecurityPolicy", fmt.Sprintf("%v", key))
	if o == nil {
		return nil
	}
	obj, ok := o.(*NetworkSecurityPolicy)
	if ok != true {
		panic("Cast failed")
	}
	return obj
}

func (m *NetworkSecurityPolicy) IsPersistent() bool {
	return false
}
func NetworkSecurityPolicyFactory(sdkClient clientApi.Client, data []byte) (clientApi.BaseObject, error) {
	var msg NetworkSecurityPolicy
	err := proto.Unmarshal(data, &msg)
	if err != nil {
		return nil, err
	}
	return &msg, nil
}

func NetworkSecurityPolicyWatch(client clientApi.Client, reactor NetworkSecurityPolicyReactor) {
	client.WatchKind("NetworkSecurityPolicy", reactor)
}
func NetworkSecurityPolicyList(client clientApi.Client) []*NetworkSecurityPolicy {
	bobjs := client.List("NetworkSecurityPolicy")
	objs := make([]*NetworkSecurityPolicy, 0)
	for _, bobj := range bobjs {
		obj, _ := bobj.(*NetworkSecurityPolicy)
		objs = append(objs, obj)
	}
	return objs
}
func (m *NetworkSecurityPolicy) TriggerEvent(sdkClient clientApi.Client, old clientApi.BaseObject, op delphi.ObjectOperation, rl []clientApi.BaseReactor) {
	for _, r := range rl {
		rctr, ok := r.(NetworkSecurityPolicyReactor)
		if ok == false {
			panic("Not a Reactor")
		}
		if op == delphi.ObjectOperation_SetOp {
			if old == nil {
				rctr.OnNetworkSecurityPolicyCreate(m)
			} else {
				oldObj, ok := old.(*NetworkSecurityPolicy)
				if ok == false {
					panic("Not an NetworkSecurityPolicy object")
				}
				rctr.OnNetworkSecurityPolicyUpdate(oldObj, m)
			}
		} else {
			rctr.OnNetworkSecurityPolicyDelete(m)
		}
	}
}

type NetworkSecurityPolicyReactor interface {
	OnNetworkSecurityPolicyCreate(obj *NetworkSecurityPolicy)
	OnNetworkSecurityPolicyUpdate(old *NetworkSecurityPolicy, obj *NetworkSecurityPolicy)
	OnNetworkSecurityPolicyDelete(obj *NetworkSecurityPolicy)
}

func (m *NetworkSecurityPolicy) Reset()                    { *m = NetworkSecurityPolicy{} }
func (m *NetworkSecurityPolicy) String() string            { return proto.CompactTextString(m) }
func (*NetworkSecurityPolicy) ProtoMessage()               {}
func (*NetworkSecurityPolicy) Descriptor() ([]byte, []int) { return fileDescriptor6, []int{0} }

func (m *NetworkSecurityPolicy) GetMeta() *delphi.ObjectMeta {
	if m != nil {
		return m.Meta
	}
	return nil
}

func (m *NetworkSecurityPolicy) GetKey() string {
	if m != nil {
		return m.Key
	}
	return ""
}

func (m *NetworkSecurityPolicy) GetNetworkSecurityPolicy() *netproto7.NetworkSecurityPolicy {
	if m != nil {
		return m.NetworkSecurityPolicy
	}
	return nil
}

func init() {
	clientApi.RegisterFactory("NetworkSecurityPolicy", NetworkSecurityPolicyFactory)
	proto.RegisterType((*NetworkSecurityPolicy)(nil), "dnetproto.NetworkSecurityPolicy")
}

func init() { proto.RegisterFile("delphi/sgpolicy.proto", fileDescriptor6) }

var fileDescriptor6 = []byte{
	// 203 bytes of a gzipped FileDescriptorProto
	0x1f, 0x8b, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xff, 0xe2, 0x12, 0x4d, 0x49, 0xcd, 0x29,
	0xc8, 0xc8, 0xd4, 0x2f, 0x4e, 0x2f, 0xc8, 0xcf, 0xc9, 0x4c, 0xae, 0xd4, 0x2b, 0x28, 0xca, 0x2f,
	0xc9, 0x17, 0xe2, 0x4c, 0xc9, 0x4b, 0x2d, 0x01, 0x33, 0xa5, 0xec, 0xd3, 0x33, 0x4b, 0x32, 0x4a,
	0x93, 0xf4, 0x92, 0xf3, 0x73, 0xf5, 0x0b, 0x52, 0xf3, 0x8a, 0x13, 0xf3, 0x52, 0xf2, 0xf5, 0x8b,
	0xcb, 0xf5, 0xf3, 0x32, 0x93, 0xf5, 0x13, 0xd3, 0x53, 0xf3, 0x4a, 0xf4, 0xc1, 0xea, 0x8a, 0xf5,
	0x61, 0x3a, 0xd0, 0xcc, 0x92, 0xe2, 0x81, 0x58, 0x01, 0xe1, 0x29, 0xad, 0x63, 0xe4, 0x12, 0xf5,
	0x4b, 0x2d, 0x29, 0xcf, 0x2f, 0xca, 0x0e, 0x4e, 0x4d, 0x2e, 0x2d, 0xca, 0x2c, 0xa9, 0x0c, 0x00,
	0xab, 0x16, 0x52, 0xe3, 0x62, 0xf1, 0x4d, 0x2d, 0x49, 0x94, 0x60, 0x54, 0x60, 0xd4, 0xe0, 0x36,
	0x12, 0xd2, 0x83, 0x6a, 0xf3, 0x4f, 0xca, 0x4a, 0x4d, 0x2e, 0x01, 0xc9, 0x04, 0x81, 0xe5, 0x85,
	0x04, 0xb8, 0x98, 0xbd, 0x53, 0x2b, 0x25, 0x98, 0x14, 0x18, 0x35, 0x38, 0x83, 0x40, 0x4c, 0xa1,
	0x50, 0x1c, 0x46, 0x4a, 0x30, 0x83, 0x8d, 0x92, 0xd7, 0x83, 0x39, 0x4d, 0x0f, 0xab, 0xb2, 0x20,
	0xec, 0xba, 0xad, 0x58, 0x1a, 0xa6, 0x2b, 0x31, 0x26, 0xb1, 0x81, 0x75, 0x1a, 0x03, 0x02, 0x00,
	0x00, 0xff, 0xff, 0xa3, 0x4d, 0xbe, 0x1a, 0x2a, 0x01, 0x00, 0x00,
}
