// Code generated by protoc-gen-gogo. DO NOT EDIT.
// source: tunnel.proto

package netproto

import proto "github.com/gogo/protobuf/proto"
import fmt "fmt"
import math "math"
import _ "google.golang.org/genproto/googleapis/api/annotations"
import _ "github.com/pensando/sw/venice/utils/apigen/annotations"
import _ "github.com/gogo/protobuf/gogoproto"
import api "github.com/pensando/sw/api"

import (
	context "golang.org/x/net/context"
	grpc "google.golang.org/grpc"
)

import io "io"

// Reference imports to suppress errors if they are not otherwise used.
var _ = proto.Marshal
var _ = fmt.Errorf
var _ = math.Inf

type TunnelSpec_Encap int32

const (
	TunnelSpec_NONE  TunnelSpec_Encap = 0
	TunnelSpec_VXLAN TunnelSpec_Encap = 1
	TunnelSpec_GRE   TunnelSpec_Encap = 2
)

var TunnelSpec_Encap_name = map[int32]string{
	0: "NONE",
	1: "VXLAN",
	2: "GRE",
}
var TunnelSpec_Encap_value = map[string]int32{
	"NONE":  0,
	"VXLAN": 1,
	"GRE":   2,
}

func (x TunnelSpec_Encap) String() string {
	return proto.EnumName(TunnelSpec_Encap_name, int32(x))
}
func (TunnelSpec_Encap) EnumDescriptor() ([]byte, []int) { return fileDescriptorTunnel, []int{1, 0} }

type TunnelStatus_IFStatus int32

const (
	TunnelStatus_NONE TunnelStatus_IFStatus = 0
	TunnelStatus_UP   TunnelStatus_IFStatus = 1
	TunnelStatus_DOWN TunnelStatus_IFStatus = 2
)

var TunnelStatus_IFStatus_name = map[int32]string{
	0: "NONE",
	1: "UP",
	2: "DOWN",
}
var TunnelStatus_IFStatus_value = map[string]int32{
	"NONE": 0,
	"UP":   1,
	"DOWN": 2,
}

func (x TunnelStatus_IFStatus) String() string {
	return proto.EnumName(TunnelStatus_IFStatus_name, int32(x))
}
func (TunnelStatus_IFStatus) EnumDescriptor() ([]byte, []int) {
	return fileDescriptorTunnel, []int{2, 0}
}

// Tunnel object
type Tunnel struct {
	api.TypeMeta   `protobuf:"bytes,1,opt,name=TypeMeta,embedded=TypeMeta" json:",inline"`
	api.ObjectMeta `protobuf:"bytes,2,opt,name=ObjectMeta,embedded=ObjectMeta" json:"meta,omitempty"`
	Spec           TunnelSpec   `protobuf:"bytes,3,opt,name=Spec" json:"spec,omitempty"`
	Status         TunnelStatus `protobuf:"bytes,4,opt,name=Status" json:"status,omitempty"`
}

func (m *Tunnel) Reset()                    { *m = Tunnel{} }
func (m *Tunnel) String() string            { return proto.CompactTextString(m) }
func (*Tunnel) ProtoMessage()               {}
func (*Tunnel) Descriptor() ([]byte, []int) { return fileDescriptorTunnel, []int{0} }

func (m *Tunnel) GetSpec() TunnelSpec {
	if m != nil {
		return m.Spec
	}
	return TunnelSpec{}
}

func (m *Tunnel) GetStatus() TunnelStatus {
	if m != nil {
		return m.Status
	}
	return TunnelStatus{}
}

// TunnelSpec captures all the tunnel level configuration
type TunnelSpec struct {
	// VrfName specifies the name of the VRF that the current Tunnel belongs to
	VrfName string `protobuf:"bytes,1,opt,name=VrfName,proto3" json:"vrf-name,omitempty"`
	// Overlay Tunnel Type. Required. Only VXLAN is currently supported
	Type string `protobuf:"bytes,2,opt,name=Type,proto3" json:"type,omitempty"`
	// AdminStatus of the overlay tunnel.
	AdminStatus string `protobuf:"bytes,3,opt,name=AdminStatus,proto3" json:"admin-status,omitempty"`
	// Local TEP IP Address
	Src string `protobuf:"bytes,4,opt,name=Src,proto3" json:"source,omitempty"`
	// Remote TEP IP Address
	Dst string `protobuf:"bytes,5,opt,name=Dst,proto3" json:"destination,omitempty"`
}

func (m *TunnelSpec) Reset()                    { *m = TunnelSpec{} }
func (m *TunnelSpec) String() string            { return proto.CompactTextString(m) }
func (*TunnelSpec) ProtoMessage()               {}
func (*TunnelSpec) Descriptor() ([]byte, []int) { return fileDescriptorTunnel, []int{1} }

func (m *TunnelSpec) GetVrfName() string {
	if m != nil {
		return m.VrfName
	}
	return ""
}

func (m *TunnelSpec) GetType() string {
	if m != nil {
		return m.Type
	}
	return ""
}

func (m *TunnelSpec) GetAdminStatus() string {
	if m != nil {
		return m.AdminStatus
	}
	return ""
}

func (m *TunnelSpec) GetSrc() string {
	if m != nil {
		return m.Src
	}
	return ""
}

func (m *TunnelSpec) GetDst() string {
	if m != nil {
		return m.Dst
	}
	return ""
}

// Tunnel Status
type TunnelStatus struct {
	OperStatus string `protobuf:"bytes,1,opt,name=OperStatus,proto3" json:"oper-status,omitempty"`
	// TunnelID in the datapath
	TunnelID uint64 `protobuf:"varint,2,opt,name=TunnelID,proto3" json:"id,omitempty"`
}

func (m *TunnelStatus) Reset()                    { *m = TunnelStatus{} }
func (m *TunnelStatus) String() string            { return proto.CompactTextString(m) }
func (*TunnelStatus) ProtoMessage()               {}
func (*TunnelStatus) Descriptor() ([]byte, []int) { return fileDescriptorTunnel, []int{2} }

func (m *TunnelStatus) GetOperStatus() string {
	if m != nil {
		return m.OperStatus
	}
	return ""
}

func (m *TunnelStatus) GetTunnelID() uint64 {
	if m != nil {
		return m.TunnelID
	}
	return 0
}

type TunnelList struct {
	Tunnels []*Tunnel `protobuf:"bytes,1,rep,name=tunnels" json:"tunnels,omitempty"`
}

func (m *TunnelList) Reset()                    { *m = TunnelList{} }
func (m *TunnelList) String() string            { return proto.CompactTextString(m) }
func (*TunnelList) ProtoMessage()               {}
func (*TunnelList) Descriptor() ([]byte, []int) { return fileDescriptorTunnel, []int{3} }

func (m *TunnelList) GetTunnels() []*Tunnel {
	if m != nil {
		return m.Tunnels
	}
	return nil
}

// tunnel watch event
type TunnelEvent struct {
	EventType api.EventType `protobuf:"varint,1,opt,name=EventType,proto3,enum=api.EventType" json:"event-type,omitempty"`
	Tunnel    Tunnel        `protobuf:"bytes,2,opt,name=Tunnel" json:"tunnel,omitempty"`
}

func (m *TunnelEvent) Reset()                    { *m = TunnelEvent{} }
func (m *TunnelEvent) String() string            { return proto.CompactTextString(m) }
func (*TunnelEvent) ProtoMessage()               {}
func (*TunnelEvent) Descriptor() ([]byte, []int) { return fileDescriptorTunnel, []int{4} }

func (m *TunnelEvent) GetEventType() api.EventType {
	if m != nil {
		return m.EventType
	}
	return api.EventType_CreateEvent
}

func (m *TunnelEvent) GetTunnel() Tunnel {
	if m != nil {
		return m.Tunnel
	}
	return Tunnel{}
}

// tunnel watch events batched
type TunnelEventList struct {
	TunnelEvents []*TunnelEvent `protobuf:"bytes,1,rep,name=TunnelEvents" json:"TunnelEvents,omitempty"`
}

func (m *TunnelEventList) Reset()                    { *m = TunnelEventList{} }
func (m *TunnelEventList) String() string            { return proto.CompactTextString(m) }
func (*TunnelEventList) ProtoMessage()               {}
func (*TunnelEventList) Descriptor() ([]byte, []int) { return fileDescriptorTunnel, []int{5} }

func (m *TunnelEventList) GetTunnelEvents() []*TunnelEvent {
	if m != nil {
		return m.TunnelEvents
	}
	return nil
}

func init() {
	proto.RegisterType((*Tunnel)(nil), "netproto.Tunnel")
	proto.RegisterType((*TunnelSpec)(nil), "netproto.TunnelSpec")
	proto.RegisterType((*TunnelStatus)(nil), "netproto.TunnelStatus")
	proto.RegisterType((*TunnelList)(nil), "netproto.TunnelList")
	proto.RegisterType((*TunnelEvent)(nil), "netproto.TunnelEvent")
	proto.RegisterType((*TunnelEventList)(nil), "netproto.TunnelEventList")
	proto.RegisterEnum("netproto.TunnelSpec_Encap", TunnelSpec_Encap_name, TunnelSpec_Encap_value)
	proto.RegisterEnum("netproto.TunnelStatus_IFStatus", TunnelStatus_IFStatus_name, TunnelStatus_IFStatus_value)
}

// Reference imports to suppress errors if they are not otherwise used.
var _ context.Context
var _ grpc.ClientConn

// This is a compile-time assertion to ensure that this generated file
// is compatible with the grpc package it is being compiled against.
const _ = grpc.SupportPackageIsVersion4

// Client API for TunnelApiV1 service

type TunnelApiV1Client interface {
}

type tunnelApiV1Client struct {
	cc *grpc.ClientConn
}

func NewTunnelApiV1Client(cc *grpc.ClientConn) TunnelApiV1Client {
	return &tunnelApiV1Client{cc}
}

// Server API for TunnelApiV1 service

type TunnelApiV1Server interface {
}

func RegisterTunnelApiV1Server(s *grpc.Server, srv TunnelApiV1Server) {
	s.RegisterService(&_TunnelApiV1_serviceDesc, srv)
}

var _TunnelApiV1_serviceDesc = grpc.ServiceDesc{
	ServiceName: "netproto.TunnelApiV1",
	HandlerType: (*TunnelApiV1Server)(nil),
	Methods:     []grpc.MethodDesc{},
	Streams:     []grpc.StreamDesc{},
	Metadata:    "tunnel.proto",
}

func (m *Tunnel) Marshal() (dAtA []byte, err error) {
	size := m.Size()
	dAtA = make([]byte, size)
	n, err := m.MarshalTo(dAtA)
	if err != nil {
		return nil, err
	}
	return dAtA[:n], nil
}

func (m *Tunnel) MarshalTo(dAtA []byte) (int, error) {
	var i int
	_ = i
	var l int
	_ = l
	dAtA[i] = 0xa
	i++
	i = encodeVarintTunnel(dAtA, i, uint64(m.TypeMeta.Size()))
	n1, err := m.TypeMeta.MarshalTo(dAtA[i:])
	if err != nil {
		return 0, err
	}
	i += n1
	dAtA[i] = 0x12
	i++
	i = encodeVarintTunnel(dAtA, i, uint64(m.ObjectMeta.Size()))
	n2, err := m.ObjectMeta.MarshalTo(dAtA[i:])
	if err != nil {
		return 0, err
	}
	i += n2
	dAtA[i] = 0x1a
	i++
	i = encodeVarintTunnel(dAtA, i, uint64(m.Spec.Size()))
	n3, err := m.Spec.MarshalTo(dAtA[i:])
	if err != nil {
		return 0, err
	}
	i += n3
	dAtA[i] = 0x22
	i++
	i = encodeVarintTunnel(dAtA, i, uint64(m.Status.Size()))
	n4, err := m.Status.MarshalTo(dAtA[i:])
	if err != nil {
		return 0, err
	}
	i += n4
	return i, nil
}

func (m *TunnelSpec) Marshal() (dAtA []byte, err error) {
	size := m.Size()
	dAtA = make([]byte, size)
	n, err := m.MarshalTo(dAtA)
	if err != nil {
		return nil, err
	}
	return dAtA[:n], nil
}

func (m *TunnelSpec) MarshalTo(dAtA []byte) (int, error) {
	var i int
	_ = i
	var l int
	_ = l
	if len(m.VrfName) > 0 {
		dAtA[i] = 0xa
		i++
		i = encodeVarintTunnel(dAtA, i, uint64(len(m.VrfName)))
		i += copy(dAtA[i:], m.VrfName)
	}
	if len(m.Type) > 0 {
		dAtA[i] = 0x12
		i++
		i = encodeVarintTunnel(dAtA, i, uint64(len(m.Type)))
		i += copy(dAtA[i:], m.Type)
	}
	if len(m.AdminStatus) > 0 {
		dAtA[i] = 0x1a
		i++
		i = encodeVarintTunnel(dAtA, i, uint64(len(m.AdminStatus)))
		i += copy(dAtA[i:], m.AdminStatus)
	}
	if len(m.Src) > 0 {
		dAtA[i] = 0x22
		i++
		i = encodeVarintTunnel(dAtA, i, uint64(len(m.Src)))
		i += copy(dAtA[i:], m.Src)
	}
	if len(m.Dst) > 0 {
		dAtA[i] = 0x2a
		i++
		i = encodeVarintTunnel(dAtA, i, uint64(len(m.Dst)))
		i += copy(dAtA[i:], m.Dst)
	}
	return i, nil
}

func (m *TunnelStatus) Marshal() (dAtA []byte, err error) {
	size := m.Size()
	dAtA = make([]byte, size)
	n, err := m.MarshalTo(dAtA)
	if err != nil {
		return nil, err
	}
	return dAtA[:n], nil
}

func (m *TunnelStatus) MarshalTo(dAtA []byte) (int, error) {
	var i int
	_ = i
	var l int
	_ = l
	if len(m.OperStatus) > 0 {
		dAtA[i] = 0xa
		i++
		i = encodeVarintTunnel(dAtA, i, uint64(len(m.OperStatus)))
		i += copy(dAtA[i:], m.OperStatus)
	}
	if m.TunnelID != 0 {
		dAtA[i] = 0x10
		i++
		i = encodeVarintTunnel(dAtA, i, uint64(m.TunnelID))
	}
	return i, nil
}

func (m *TunnelList) Marshal() (dAtA []byte, err error) {
	size := m.Size()
	dAtA = make([]byte, size)
	n, err := m.MarshalTo(dAtA)
	if err != nil {
		return nil, err
	}
	return dAtA[:n], nil
}

func (m *TunnelList) MarshalTo(dAtA []byte) (int, error) {
	var i int
	_ = i
	var l int
	_ = l
	if len(m.Tunnels) > 0 {
		for _, msg := range m.Tunnels {
			dAtA[i] = 0xa
			i++
			i = encodeVarintTunnel(dAtA, i, uint64(msg.Size()))
			n, err := msg.MarshalTo(dAtA[i:])
			if err != nil {
				return 0, err
			}
			i += n
		}
	}
	return i, nil
}

func (m *TunnelEvent) Marshal() (dAtA []byte, err error) {
	size := m.Size()
	dAtA = make([]byte, size)
	n, err := m.MarshalTo(dAtA)
	if err != nil {
		return nil, err
	}
	return dAtA[:n], nil
}

func (m *TunnelEvent) MarshalTo(dAtA []byte) (int, error) {
	var i int
	_ = i
	var l int
	_ = l
	if m.EventType != 0 {
		dAtA[i] = 0x8
		i++
		i = encodeVarintTunnel(dAtA, i, uint64(m.EventType))
	}
	dAtA[i] = 0x12
	i++
	i = encodeVarintTunnel(dAtA, i, uint64(m.Tunnel.Size()))
	n5, err := m.Tunnel.MarshalTo(dAtA[i:])
	if err != nil {
		return 0, err
	}
	i += n5
	return i, nil
}

func (m *TunnelEventList) Marshal() (dAtA []byte, err error) {
	size := m.Size()
	dAtA = make([]byte, size)
	n, err := m.MarshalTo(dAtA)
	if err != nil {
		return nil, err
	}
	return dAtA[:n], nil
}

func (m *TunnelEventList) MarshalTo(dAtA []byte) (int, error) {
	var i int
	_ = i
	var l int
	_ = l
	if len(m.TunnelEvents) > 0 {
		for _, msg := range m.TunnelEvents {
			dAtA[i] = 0xa
			i++
			i = encodeVarintTunnel(dAtA, i, uint64(msg.Size()))
			n, err := msg.MarshalTo(dAtA[i:])
			if err != nil {
				return 0, err
			}
			i += n
		}
	}
	return i, nil
}

func encodeVarintTunnel(dAtA []byte, offset int, v uint64) int {
	for v >= 1<<7 {
		dAtA[offset] = uint8(v&0x7f | 0x80)
		v >>= 7
		offset++
	}
	dAtA[offset] = uint8(v)
	return offset + 1
}
func (m *Tunnel) Size() (n int) {
	var l int
	_ = l
	l = m.TypeMeta.Size()
	n += 1 + l + sovTunnel(uint64(l))
	l = m.ObjectMeta.Size()
	n += 1 + l + sovTunnel(uint64(l))
	l = m.Spec.Size()
	n += 1 + l + sovTunnel(uint64(l))
	l = m.Status.Size()
	n += 1 + l + sovTunnel(uint64(l))
	return n
}

func (m *TunnelSpec) Size() (n int) {
	var l int
	_ = l
	l = len(m.VrfName)
	if l > 0 {
		n += 1 + l + sovTunnel(uint64(l))
	}
	l = len(m.Type)
	if l > 0 {
		n += 1 + l + sovTunnel(uint64(l))
	}
	l = len(m.AdminStatus)
	if l > 0 {
		n += 1 + l + sovTunnel(uint64(l))
	}
	l = len(m.Src)
	if l > 0 {
		n += 1 + l + sovTunnel(uint64(l))
	}
	l = len(m.Dst)
	if l > 0 {
		n += 1 + l + sovTunnel(uint64(l))
	}
	return n
}

func (m *TunnelStatus) Size() (n int) {
	var l int
	_ = l
	l = len(m.OperStatus)
	if l > 0 {
		n += 1 + l + sovTunnel(uint64(l))
	}
	if m.TunnelID != 0 {
		n += 1 + sovTunnel(uint64(m.TunnelID))
	}
	return n
}

func (m *TunnelList) Size() (n int) {
	var l int
	_ = l
	if len(m.Tunnels) > 0 {
		for _, e := range m.Tunnels {
			l = e.Size()
			n += 1 + l + sovTunnel(uint64(l))
		}
	}
	return n
}

func (m *TunnelEvent) Size() (n int) {
	var l int
	_ = l
	if m.EventType != 0 {
		n += 1 + sovTunnel(uint64(m.EventType))
	}
	l = m.Tunnel.Size()
	n += 1 + l + sovTunnel(uint64(l))
	return n
}

func (m *TunnelEventList) Size() (n int) {
	var l int
	_ = l
	if len(m.TunnelEvents) > 0 {
		for _, e := range m.TunnelEvents {
			l = e.Size()
			n += 1 + l + sovTunnel(uint64(l))
		}
	}
	return n
}

func sovTunnel(x uint64) (n int) {
	for {
		n++
		x >>= 7
		if x == 0 {
			break
		}
	}
	return n
}
func sozTunnel(x uint64) (n int) {
	return sovTunnel(uint64((x << 1) ^ uint64((int64(x) >> 63))))
}
func (m *Tunnel) Unmarshal(dAtA []byte) error {
	l := len(dAtA)
	iNdEx := 0
	for iNdEx < l {
		preIndex := iNdEx
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return ErrIntOverflowTunnel
			}
			if iNdEx >= l {
				return io.ErrUnexpectedEOF
			}
			b := dAtA[iNdEx]
			iNdEx++
			wire |= (uint64(b) & 0x7F) << shift
			if b < 0x80 {
				break
			}
		}
		fieldNum := int32(wire >> 3)
		wireType := int(wire & 0x7)
		if wireType == 4 {
			return fmt.Errorf("proto: Tunnel: wiretype end group for non-group")
		}
		if fieldNum <= 0 {
			return fmt.Errorf("proto: Tunnel: illegal tag %d (wire type %d)", fieldNum, wire)
		}
		switch fieldNum {
		case 1:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field TypeMeta", wireType)
			}
			var msglen int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowTunnel
				}
				if iNdEx >= l {
					return io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				msglen |= (int(b) & 0x7F) << shift
				if b < 0x80 {
					break
				}
			}
			if msglen < 0 {
				return ErrInvalidLengthTunnel
			}
			postIndex := iNdEx + msglen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			if err := m.TypeMeta.Unmarshal(dAtA[iNdEx:postIndex]); err != nil {
				return err
			}
			iNdEx = postIndex
		case 2:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field ObjectMeta", wireType)
			}
			var msglen int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowTunnel
				}
				if iNdEx >= l {
					return io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				msglen |= (int(b) & 0x7F) << shift
				if b < 0x80 {
					break
				}
			}
			if msglen < 0 {
				return ErrInvalidLengthTunnel
			}
			postIndex := iNdEx + msglen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			if err := m.ObjectMeta.Unmarshal(dAtA[iNdEx:postIndex]); err != nil {
				return err
			}
			iNdEx = postIndex
		case 3:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field Spec", wireType)
			}
			var msglen int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowTunnel
				}
				if iNdEx >= l {
					return io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				msglen |= (int(b) & 0x7F) << shift
				if b < 0x80 {
					break
				}
			}
			if msglen < 0 {
				return ErrInvalidLengthTunnel
			}
			postIndex := iNdEx + msglen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			if err := m.Spec.Unmarshal(dAtA[iNdEx:postIndex]); err != nil {
				return err
			}
			iNdEx = postIndex
		case 4:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field Status", wireType)
			}
			var msglen int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowTunnel
				}
				if iNdEx >= l {
					return io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				msglen |= (int(b) & 0x7F) << shift
				if b < 0x80 {
					break
				}
			}
			if msglen < 0 {
				return ErrInvalidLengthTunnel
			}
			postIndex := iNdEx + msglen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			if err := m.Status.Unmarshal(dAtA[iNdEx:postIndex]); err != nil {
				return err
			}
			iNdEx = postIndex
		default:
			iNdEx = preIndex
			skippy, err := skipTunnel(dAtA[iNdEx:])
			if err != nil {
				return err
			}
			if skippy < 0 {
				return ErrInvalidLengthTunnel
			}
			if (iNdEx + skippy) > l {
				return io.ErrUnexpectedEOF
			}
			iNdEx += skippy
		}
	}

	if iNdEx > l {
		return io.ErrUnexpectedEOF
	}
	return nil
}
func (m *TunnelSpec) Unmarshal(dAtA []byte) error {
	l := len(dAtA)
	iNdEx := 0
	for iNdEx < l {
		preIndex := iNdEx
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return ErrIntOverflowTunnel
			}
			if iNdEx >= l {
				return io.ErrUnexpectedEOF
			}
			b := dAtA[iNdEx]
			iNdEx++
			wire |= (uint64(b) & 0x7F) << shift
			if b < 0x80 {
				break
			}
		}
		fieldNum := int32(wire >> 3)
		wireType := int(wire & 0x7)
		if wireType == 4 {
			return fmt.Errorf("proto: TunnelSpec: wiretype end group for non-group")
		}
		if fieldNum <= 0 {
			return fmt.Errorf("proto: TunnelSpec: illegal tag %d (wire type %d)", fieldNum, wire)
		}
		switch fieldNum {
		case 1:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field VrfName", wireType)
			}
			var stringLen uint64
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowTunnel
				}
				if iNdEx >= l {
					return io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				stringLen |= (uint64(b) & 0x7F) << shift
				if b < 0x80 {
					break
				}
			}
			intStringLen := int(stringLen)
			if intStringLen < 0 {
				return ErrInvalidLengthTunnel
			}
			postIndex := iNdEx + intStringLen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.VrfName = string(dAtA[iNdEx:postIndex])
			iNdEx = postIndex
		case 2:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field Type", wireType)
			}
			var stringLen uint64
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowTunnel
				}
				if iNdEx >= l {
					return io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				stringLen |= (uint64(b) & 0x7F) << shift
				if b < 0x80 {
					break
				}
			}
			intStringLen := int(stringLen)
			if intStringLen < 0 {
				return ErrInvalidLengthTunnel
			}
			postIndex := iNdEx + intStringLen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.Type = string(dAtA[iNdEx:postIndex])
			iNdEx = postIndex
		case 3:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field AdminStatus", wireType)
			}
			var stringLen uint64
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowTunnel
				}
				if iNdEx >= l {
					return io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				stringLen |= (uint64(b) & 0x7F) << shift
				if b < 0x80 {
					break
				}
			}
			intStringLen := int(stringLen)
			if intStringLen < 0 {
				return ErrInvalidLengthTunnel
			}
			postIndex := iNdEx + intStringLen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.AdminStatus = string(dAtA[iNdEx:postIndex])
			iNdEx = postIndex
		case 4:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field Src", wireType)
			}
			var stringLen uint64
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowTunnel
				}
				if iNdEx >= l {
					return io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				stringLen |= (uint64(b) & 0x7F) << shift
				if b < 0x80 {
					break
				}
			}
			intStringLen := int(stringLen)
			if intStringLen < 0 {
				return ErrInvalidLengthTunnel
			}
			postIndex := iNdEx + intStringLen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.Src = string(dAtA[iNdEx:postIndex])
			iNdEx = postIndex
		case 5:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field Dst", wireType)
			}
			var stringLen uint64
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowTunnel
				}
				if iNdEx >= l {
					return io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				stringLen |= (uint64(b) & 0x7F) << shift
				if b < 0x80 {
					break
				}
			}
			intStringLen := int(stringLen)
			if intStringLen < 0 {
				return ErrInvalidLengthTunnel
			}
			postIndex := iNdEx + intStringLen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.Dst = string(dAtA[iNdEx:postIndex])
			iNdEx = postIndex
		default:
			iNdEx = preIndex
			skippy, err := skipTunnel(dAtA[iNdEx:])
			if err != nil {
				return err
			}
			if skippy < 0 {
				return ErrInvalidLengthTunnel
			}
			if (iNdEx + skippy) > l {
				return io.ErrUnexpectedEOF
			}
			iNdEx += skippy
		}
	}

	if iNdEx > l {
		return io.ErrUnexpectedEOF
	}
	return nil
}
func (m *TunnelStatus) Unmarshal(dAtA []byte) error {
	l := len(dAtA)
	iNdEx := 0
	for iNdEx < l {
		preIndex := iNdEx
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return ErrIntOverflowTunnel
			}
			if iNdEx >= l {
				return io.ErrUnexpectedEOF
			}
			b := dAtA[iNdEx]
			iNdEx++
			wire |= (uint64(b) & 0x7F) << shift
			if b < 0x80 {
				break
			}
		}
		fieldNum := int32(wire >> 3)
		wireType := int(wire & 0x7)
		if wireType == 4 {
			return fmt.Errorf("proto: TunnelStatus: wiretype end group for non-group")
		}
		if fieldNum <= 0 {
			return fmt.Errorf("proto: TunnelStatus: illegal tag %d (wire type %d)", fieldNum, wire)
		}
		switch fieldNum {
		case 1:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field OperStatus", wireType)
			}
			var stringLen uint64
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowTunnel
				}
				if iNdEx >= l {
					return io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				stringLen |= (uint64(b) & 0x7F) << shift
				if b < 0x80 {
					break
				}
			}
			intStringLen := int(stringLen)
			if intStringLen < 0 {
				return ErrInvalidLengthTunnel
			}
			postIndex := iNdEx + intStringLen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.OperStatus = string(dAtA[iNdEx:postIndex])
			iNdEx = postIndex
		case 2:
			if wireType != 0 {
				return fmt.Errorf("proto: wrong wireType = %d for field TunnelID", wireType)
			}
			m.TunnelID = 0
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowTunnel
				}
				if iNdEx >= l {
					return io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				m.TunnelID |= (uint64(b) & 0x7F) << shift
				if b < 0x80 {
					break
				}
			}
		default:
			iNdEx = preIndex
			skippy, err := skipTunnel(dAtA[iNdEx:])
			if err != nil {
				return err
			}
			if skippy < 0 {
				return ErrInvalidLengthTunnel
			}
			if (iNdEx + skippy) > l {
				return io.ErrUnexpectedEOF
			}
			iNdEx += skippy
		}
	}

	if iNdEx > l {
		return io.ErrUnexpectedEOF
	}
	return nil
}
func (m *TunnelList) Unmarshal(dAtA []byte) error {
	l := len(dAtA)
	iNdEx := 0
	for iNdEx < l {
		preIndex := iNdEx
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return ErrIntOverflowTunnel
			}
			if iNdEx >= l {
				return io.ErrUnexpectedEOF
			}
			b := dAtA[iNdEx]
			iNdEx++
			wire |= (uint64(b) & 0x7F) << shift
			if b < 0x80 {
				break
			}
		}
		fieldNum := int32(wire >> 3)
		wireType := int(wire & 0x7)
		if wireType == 4 {
			return fmt.Errorf("proto: TunnelList: wiretype end group for non-group")
		}
		if fieldNum <= 0 {
			return fmt.Errorf("proto: TunnelList: illegal tag %d (wire type %d)", fieldNum, wire)
		}
		switch fieldNum {
		case 1:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field Tunnels", wireType)
			}
			var msglen int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowTunnel
				}
				if iNdEx >= l {
					return io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				msglen |= (int(b) & 0x7F) << shift
				if b < 0x80 {
					break
				}
			}
			if msglen < 0 {
				return ErrInvalidLengthTunnel
			}
			postIndex := iNdEx + msglen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.Tunnels = append(m.Tunnels, &Tunnel{})
			if err := m.Tunnels[len(m.Tunnels)-1].Unmarshal(dAtA[iNdEx:postIndex]); err != nil {
				return err
			}
			iNdEx = postIndex
		default:
			iNdEx = preIndex
			skippy, err := skipTunnel(dAtA[iNdEx:])
			if err != nil {
				return err
			}
			if skippy < 0 {
				return ErrInvalidLengthTunnel
			}
			if (iNdEx + skippy) > l {
				return io.ErrUnexpectedEOF
			}
			iNdEx += skippy
		}
	}

	if iNdEx > l {
		return io.ErrUnexpectedEOF
	}
	return nil
}
func (m *TunnelEvent) Unmarshal(dAtA []byte) error {
	l := len(dAtA)
	iNdEx := 0
	for iNdEx < l {
		preIndex := iNdEx
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return ErrIntOverflowTunnel
			}
			if iNdEx >= l {
				return io.ErrUnexpectedEOF
			}
			b := dAtA[iNdEx]
			iNdEx++
			wire |= (uint64(b) & 0x7F) << shift
			if b < 0x80 {
				break
			}
		}
		fieldNum := int32(wire >> 3)
		wireType := int(wire & 0x7)
		if wireType == 4 {
			return fmt.Errorf("proto: TunnelEvent: wiretype end group for non-group")
		}
		if fieldNum <= 0 {
			return fmt.Errorf("proto: TunnelEvent: illegal tag %d (wire type %d)", fieldNum, wire)
		}
		switch fieldNum {
		case 1:
			if wireType != 0 {
				return fmt.Errorf("proto: wrong wireType = %d for field EventType", wireType)
			}
			m.EventType = 0
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowTunnel
				}
				if iNdEx >= l {
					return io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				m.EventType |= (api.EventType(b) & 0x7F) << shift
				if b < 0x80 {
					break
				}
			}
		case 2:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field Tunnel", wireType)
			}
			var msglen int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowTunnel
				}
				if iNdEx >= l {
					return io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				msglen |= (int(b) & 0x7F) << shift
				if b < 0x80 {
					break
				}
			}
			if msglen < 0 {
				return ErrInvalidLengthTunnel
			}
			postIndex := iNdEx + msglen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			if err := m.Tunnel.Unmarshal(dAtA[iNdEx:postIndex]); err != nil {
				return err
			}
			iNdEx = postIndex
		default:
			iNdEx = preIndex
			skippy, err := skipTunnel(dAtA[iNdEx:])
			if err != nil {
				return err
			}
			if skippy < 0 {
				return ErrInvalidLengthTunnel
			}
			if (iNdEx + skippy) > l {
				return io.ErrUnexpectedEOF
			}
			iNdEx += skippy
		}
	}

	if iNdEx > l {
		return io.ErrUnexpectedEOF
	}
	return nil
}
func (m *TunnelEventList) Unmarshal(dAtA []byte) error {
	l := len(dAtA)
	iNdEx := 0
	for iNdEx < l {
		preIndex := iNdEx
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return ErrIntOverflowTunnel
			}
			if iNdEx >= l {
				return io.ErrUnexpectedEOF
			}
			b := dAtA[iNdEx]
			iNdEx++
			wire |= (uint64(b) & 0x7F) << shift
			if b < 0x80 {
				break
			}
		}
		fieldNum := int32(wire >> 3)
		wireType := int(wire & 0x7)
		if wireType == 4 {
			return fmt.Errorf("proto: TunnelEventList: wiretype end group for non-group")
		}
		if fieldNum <= 0 {
			return fmt.Errorf("proto: TunnelEventList: illegal tag %d (wire type %d)", fieldNum, wire)
		}
		switch fieldNum {
		case 1:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field TunnelEvents", wireType)
			}
			var msglen int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowTunnel
				}
				if iNdEx >= l {
					return io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				msglen |= (int(b) & 0x7F) << shift
				if b < 0x80 {
					break
				}
			}
			if msglen < 0 {
				return ErrInvalidLengthTunnel
			}
			postIndex := iNdEx + msglen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.TunnelEvents = append(m.TunnelEvents, &TunnelEvent{})
			if err := m.TunnelEvents[len(m.TunnelEvents)-1].Unmarshal(dAtA[iNdEx:postIndex]); err != nil {
				return err
			}
			iNdEx = postIndex
		default:
			iNdEx = preIndex
			skippy, err := skipTunnel(dAtA[iNdEx:])
			if err != nil {
				return err
			}
			if skippy < 0 {
				return ErrInvalidLengthTunnel
			}
			if (iNdEx + skippy) > l {
				return io.ErrUnexpectedEOF
			}
			iNdEx += skippy
		}
	}

	if iNdEx > l {
		return io.ErrUnexpectedEOF
	}
	return nil
}
func skipTunnel(dAtA []byte) (n int, err error) {
	l := len(dAtA)
	iNdEx := 0
	for iNdEx < l {
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return 0, ErrIntOverflowTunnel
			}
			if iNdEx >= l {
				return 0, io.ErrUnexpectedEOF
			}
			b := dAtA[iNdEx]
			iNdEx++
			wire |= (uint64(b) & 0x7F) << shift
			if b < 0x80 {
				break
			}
		}
		wireType := int(wire & 0x7)
		switch wireType {
		case 0:
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return 0, ErrIntOverflowTunnel
				}
				if iNdEx >= l {
					return 0, io.ErrUnexpectedEOF
				}
				iNdEx++
				if dAtA[iNdEx-1] < 0x80 {
					break
				}
			}
			return iNdEx, nil
		case 1:
			iNdEx += 8
			return iNdEx, nil
		case 2:
			var length int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return 0, ErrIntOverflowTunnel
				}
				if iNdEx >= l {
					return 0, io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				length |= (int(b) & 0x7F) << shift
				if b < 0x80 {
					break
				}
			}
			iNdEx += length
			if length < 0 {
				return 0, ErrInvalidLengthTunnel
			}
			return iNdEx, nil
		case 3:
			for {
				var innerWire uint64
				var start int = iNdEx
				for shift := uint(0); ; shift += 7 {
					if shift >= 64 {
						return 0, ErrIntOverflowTunnel
					}
					if iNdEx >= l {
						return 0, io.ErrUnexpectedEOF
					}
					b := dAtA[iNdEx]
					iNdEx++
					innerWire |= (uint64(b) & 0x7F) << shift
					if b < 0x80 {
						break
					}
				}
				innerWireType := int(innerWire & 0x7)
				if innerWireType == 4 {
					break
				}
				next, err := skipTunnel(dAtA[start:])
				if err != nil {
					return 0, err
				}
				iNdEx = start + next
			}
			return iNdEx, nil
		case 4:
			return iNdEx, nil
		case 5:
			iNdEx += 4
			return iNdEx, nil
		default:
			return 0, fmt.Errorf("proto: illegal wireType %d", wireType)
		}
	}
	panic("unreachable")
}

var (
	ErrInvalidLengthTunnel = fmt.Errorf("proto: negative length found during unmarshaling")
	ErrIntOverflowTunnel   = fmt.Errorf("proto: integer overflow")
)

func init() { proto.RegisterFile("tunnel.proto", fileDescriptorTunnel) }

var fileDescriptorTunnel = []byte{
	// 775 bytes of a gzipped FileDescriptorProto
	0x1f, 0x8b, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xff, 0x8c, 0x94, 0xdd, 0x6e, 0xe2, 0x46,
	0x14, 0xc7, 0x63, 0x4c, 0xf8, 0x18, 0x68, 0x62, 0x4d, 0x13, 0x04, 0xa8, 0x82, 0xca, 0x52, 0xa2,
	0xb4, 0x0d, 0x76, 0x4b, 0x6f, 0x5a, 0xf5, 0x43, 0x8d, 0x0b, 0x69, 0xa3, 0xa6, 0x10, 0x41, 0x9a,
	0x56, 0xaa, 0x54, 0xc9, 0x98, 0x09, 0xf5, 0x0a, 0x8f, 0x47, 0xf6, 0x98, 0x55, 0xb4, 0xca, 0xd5,
	0x6a, 0xf3, 0x0e, 0x7b, 0xb9, 0xb7, 0xb9, 0xdc, 0x37, 0xd8, 0xbb, 0x5c, 0xe6, 0x09, 0xd8, 0x55,
	0x2e, 0x79, 0x8a, 0xd5, 0x1c, 0x63, 0x98, 0x80, 0x56, 0xda, 0xbb, 0x99, 0x33, 0xff, 0xf3, 0xf3,
	0xf9, 0x1f, 0x9f, 0x19, 0x54, 0xe4, 0x11, 0xa5, 0x64, 0x6c, 0xb0, 0xc0, 0xe7, 0x3e, 0xce, 0x51,
	0xc2, 0x61, 0x55, 0xfd, 0x6c, 0xe4, 0xfb, 0xa3, 0x31, 0x31, 0x6d, 0xe6, 0x9a, 0x36, 0xa5, 0x3e,
	0xb7, 0xb9, 0xeb, 0xd3, 0x30, 0xd6, 0x55, 0xdb, 0x23, 0x97, 0xff, 0x1f, 0x0d, 0x0c, 0xc7, 0xf7,
	0x4c, 0x46, 0x68, 0x68, 0xd3, 0xa1, 0x6f, 0x86, 0x4f, 0xcd, 0x09, 0xa1, 0xae, 0x43, 0xcc, 0x88,
	0xbb, 0xe3, 0x50, 0xa4, 0x8e, 0x08, 0x95, 0xb3, 0x4d, 0x97, 0x3a, 0xe3, 0x68, 0x48, 0x12, 0x4c,
	0x43, 0xc2, 0x8c, 0xfc, 0x91, 0x6f, 0x42, 0x78, 0x10, 0x5d, 0xc2, 0x0e, 0x36, 0xb0, 0x9a, 0xcb,
	0xf7, 0x3e, 0xf0, 0x55, 0x51, 0xa3, 0x47, 0xb8, 0x1d, 0xcb, 0xf4, 0x57, 0x29, 0x94, 0x39, 0x07,
	0x57, 0xf8, 0x67, 0x94, 0x3b, 0xbf, 0x62, 0xe4, 0x4f, 0xc2, 0xed, 0xb2, 0xf2, 0xb9, 0x72, 0x50,
	0x68, 0x7e, 0x62, 0xd8, 0xcc, 0x35, 0x92, 0xa0, 0xf5, 0xe9, 0xdd, 0xb4, 0xbe, 0x71, 0x3f, 0xad,
	0x2b, 0xb3, 0x69, 0x3d, 0x7b, 0xe8, 0xd2, 0xb1, 0x4b, 0x49, 0x6f, 0x91, 0x83, 0xff, 0x40, 0xa8,
	0x3b, 0x78, 0x42, 0x1c, 0x0e, 0x84, 0x14, 0x10, 0xb6, 0x81, 0xb0, 0x0c, 0x5b, 0x55, 0x89, 0xb1,
	0x25, 0xea, 0x38, 0xf4, 0x3d, 0x97, 0x13, 0x8f, 0xf1, 0xab, 0x9e, 0x94, 0x8e, 0x7f, 0x41, 0xe9,
	0x3e, 0x23, 0x4e, 0x59, 0x05, 0xcc, 0x8e, 0x91, 0xf4, 0xda, 0x88, 0x8b, 0x15, 0x67, 0x56, 0x49,
	0xb0, 0x04, 0x27, 0x64, 0xc4, 0x91, 0x38, 0x90, 0x89, 0x7f, 0x47, 0x99, 0x3e, 0xb7, 0x79, 0x14,
	0x96, 0xd3, 0xc0, 0x28, 0xad, 0x31, 0xe0, 0xd4, 0x2a, 0xcf, 0x29, 0x5a, 0x08, 0x7b, 0x89, 0x33,
	0xcf, 0xd7, 0xdf, 0xa6, 0x10, 0x5a, 0x7e, 0x16, 0x7f, 0x8d, 0xb2, 0x17, 0xc1, 0x65, 0xc7, 0xf6,
	0x08, 0xb4, 0x29, 0x6f, 0x95, 0x66, 0xd3, 0x3a, 0x9e, 0x04, 0x97, 0x0d, 0x6a, 0x7b, 0x44, 0xca,
	0x4f, 0x64, 0xf8, 0x57, 0x94, 0x16, 0x5d, 0x82, 0x9e, 0xe4, 0x2d, 0xf3, 0xf6, 0xa6, 0x52, 0xe9,
	0xf3, 0xa0, 0x4d, 0x23, 0xef, 0x60, 0xc9, 0x35, 0xda, 0xd4, 0xb1, 0xd9, 0x17, 0xc2, 0x0f, 0xbf,
	0x62, 0x32, 0x07, 0x92, 0xf1, 0x7f, 0xa8, 0x70, 0x34, 0xf4, 0x5c, 0x3a, 0x37, 0xa5, 0x02, 0xeb,
	0xc7, 0xdb, 0x9b, 0x4a, 0x6d, 0x85, 0x05, 0xe7, 0xc6, 0xc9, 0x71, 0xbc, 0x10, 0xc0, 0x92, 0x2d,
	0x12, 0x1b, 0x6b, 0x06, 0x65, 0x20, 0xde, 0x47, 0x6a, 0x3f, 0x70, 0xa0, 0x59, 0x79, 0x6b, 0x07,
	0x1a, 0xe2, 0x47, 0x81, 0x23, 0x17, 0x22, 0x04, 0xf8, 0x2b, 0xa4, 0xb6, 0x42, 0x5e, 0xde, 0x04,
	0x5d, 0x65, 0x36, 0xad, 0xef, 0x0e, 0x49, 0xc8, 0x5d, 0x0a, 0x53, 0x2b, 0x8b, 0x5b, 0x21, 0xd7,
	0xf7, 0xd0, 0x26, 0xd8, 0xc2, 0x39, 0x94, 0xee, 0x74, 0x3b, 0x6d, 0x6d, 0x03, 0xe7, 0xd1, 0xe6,
	0xc5, 0x3f, 0xa7, 0x47, 0x1d, 0x4d, 0xc1, 0x59, 0xa4, 0xfe, 0xd6, 0x6b, 0x6b, 0x29, 0xfd, 0x8d,
	0x82, 0x8a, 0x72, 0xf5, 0xf8, 0x5f, 0x84, 0xba, 0x8c, 0x04, 0x73, 0xaf, 0x71, 0x9b, 0x7f, 0xf8,
	0x28, 0xaf, 0xbb, 0x3e, 0x23, 0xc1, 0xba, 0x55, 0x09, 0x87, 0x0f, 0x51, 0x2e, 0x4e, 0x3f, 0x69,
	0xc1, 0x2f, 0x49, 0x5b, 0xda, 0x6c, 0x5a, 0x2f, 0xba, 0x43, 0x49, 0xbf, 0x50, 0xe8, 0xfb, 0x28,
	0x97, 0xf0, 0x25, 0x17, 0x19, 0x94, 0xfa, 0xeb, 0x4c, 0x53, 0x44, 0xa4, 0xd5, 0xfd, 0xbb, 0xa3,
	0xa5, 0xf4, 0xef, 0x92, 0x21, 0x39, 0x75, 0x43, 0x8e, 0xbf, 0x44, 0xd9, 0xf8, 0xb1, 0x10, 0xd5,
	0xab, 0x07, 0x85, 0xa6, 0xb6, 0x3a, 0x7e, 0xbd, 0x44, 0xa0, 0xbf, 0x54, 0x50, 0x21, 0x8e, 0xb5,
	0x27, 0x84, 0x72, 0x7c, 0x8c, 0xf2, 0xb0, 0x80, 0x99, 0x11, 0xde, 0xb7, 0x9a, 0x5b, 0x70, 0x8f,
	0x16, 0x51, 0xab, 0x3c, 0x9b, 0xd6, 0x77, 0x88, 0xd8, 0x36, 0x56, 0x86, 0x65, 0x99, 0x8a, 0xad,
	0xe4, 0x6a, 0xcf, 0x2f, 0xe3, 0x5a, 0x09, 0xcb, 0xd9, 0x8f, 0x4b, 0x91, 0x67, 0x3f, 0x56, 0xe8,
	0xa7, 0x68, 0x5b, 0x2a, 0x0d, 0xac, 0x7d, 0x9f, 0xfc, 0x2b, 0x08, 0x25, 0xfe, 0x76, 0x57, 0xe1,
	0x70, 0xda, 0x7b, 0x24, 0x6d, 0xbe, 0x58, 0x38, 0x3d, 0x62, 0xee, 0xc5, 0x37, 0xd5, 0xc9, 0xeb,
	0xe7, 0x95, 0x60, 0xf1, 0x00, 0xa5, 0xc7, 0x02, 0xaf, 0x8e, 0x08, 0xc7, 0x69, 0xe6, 0x87, 0x1c,
	0x67, 0x86, 0x64, 0x4c, 0x38, 0xc1, 0x2a, 0x8b, 0x78, 0xf5, 0x27, 0xf3, 0xd9, 0xf2, 0x7d, 0x30,
	0xce, 0x09, 0xb5, 0x29, 0xbf, 0x7e, 0x14, 0x13, 0x77, 0x2d, 0x64, 0xb6, 0x43, 0xd6, 0xc3, 0xd7,
	0x7a, 0x41, 0x3c, 0x7c, 0xf3, 0x8e, 0x5b, 0xc5, 0xbb, 0x87, 0x9a, 0x72, 0xff, 0x50, 0x53, 0xde,
	0x3d, 0xd4, 0x94, 0x33, 0x65, 0x90, 0x81, 0xc2, 0xbf, 0x7d, 0x1f, 0x00, 0x00, 0xff, 0xff, 0xf4,
	0x6b, 0xf2, 0xda, 0xe1, 0x05, 0x00, 0x00,
}
