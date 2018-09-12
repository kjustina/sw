// Code generated by protoc-gen-gogo. DO NOT EDIT.
// source: port.proto

package netproto

import proto "github.com/golang/protobuf/proto"
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

type PortSpec_PortSpeed int32

const (
	PortSpec_SPEED_NONE    PortSpec_PortSpeed = 0
	PortSpec_SPEED_1G      PortSpec_PortSpeed = 1
	PortSpec_SPEED_10G     PortSpec_PortSpeed = 2
	PortSpec_SPEED_25G     PortSpec_PortSpeed = 3
	PortSpec_SPEED_40G     PortSpec_PortSpeed = 4
	PortSpec_SPEED_50G     PortSpec_PortSpeed = 5
	PortSpec_SPEED_100G    PortSpec_PortSpeed = 6
	PortSpec_SPEED_AUTONEG PortSpec_PortSpeed = 7
)

var PortSpec_PortSpeed_name = map[int32]string{
	0: "SPEED_NONE",
	1: "SPEED_1G",
	2: "SPEED_10G",
	3: "SPEED_25G",
	4: "SPEED_40G",
	5: "SPEED_50G",
	6: "SPEED_100G",
	7: "SPEED_AUTONEG",
}
var PortSpec_PortSpeed_value = map[string]int32{
	"SPEED_NONE":    0,
	"SPEED_1G":      1,
	"SPEED_10G":     2,
	"SPEED_25G":     3,
	"SPEED_40G":     4,
	"SPEED_50G":     5,
	"SPEED_100G":    6,
	"SPEED_AUTONEG": 7,
}

func (x PortSpec_PortSpeed) String() string {
	return proto.EnumName(PortSpec_PortSpeed_name, int32(x))
}
func (PortSpec_PortSpeed) EnumDescriptor() ([]byte, []int) { return fileDescriptorPort, []int{1, 0} }

type PortSpec_PortBreakout int32

const (
	PortSpec_BREAKOUT_NONE  PortSpec_PortBreakout = 0
	PortSpec_BREAKOUT_4X25G PortSpec_PortBreakout = 1
	PortSpec_BREAKOUT_4X10G PortSpec_PortBreakout = 2
	PortSpec_BREAKOUT_2X50G PortSpec_PortBreakout = 3
)

var PortSpec_PortBreakout_name = map[int32]string{
	0: "BREAKOUT_NONE",
	1: "BREAKOUT_4X25G",
	2: "BREAKOUT_4X10G",
	3: "BREAKOUT_2X50G",
}
var PortSpec_PortBreakout_value = map[string]int32{
	"BREAKOUT_NONE":  0,
	"BREAKOUT_4X25G": 1,
	"BREAKOUT_4X10G": 2,
	"BREAKOUT_2X50G": 3,
}

func (x PortSpec_PortBreakout) String() string {
	return proto.EnumName(PortSpec_PortBreakout_name, int32(x))
}
func (PortSpec_PortBreakout) EnumDescriptor() ([]byte, []int) { return fileDescriptorPort, []int{1, 1} }

type PortSpec_IFStatus int32

const (
	PortSpec_NONE PortSpec_IFStatus = 0
	PortSpec_UP   PortSpec_IFStatus = 1
	PortSpec_DOWN PortSpec_IFStatus = 2
)

var PortSpec_IFStatus_name = map[int32]string{
	0: "NONE",
	1: "UP",
	2: "DOWN",
}
var PortSpec_IFStatus_value = map[string]int32{
	"NONE": 0,
	"UP":   1,
	"DOWN": 2,
}

func (x PortSpec_IFStatus) String() string {
	return proto.EnumName(PortSpec_IFStatus_name, int32(x))
}
func (PortSpec_IFStatus) EnumDescriptor() ([]byte, []int) { return fileDescriptorPort, []int{1, 2} }

// Port object
type Port struct {
	api.TypeMeta   `protobuf:"bytes,1,opt,name=TypeMeta,embedded=TypeMeta" json:",inline"`
	api.ObjectMeta `protobuf:"bytes,2,opt,name=ObjectMeta,embedded=ObjectMeta" json:"meta,omitempty"`
	Spec           PortSpec   `protobuf:"bytes,3,opt,name=Spec" json:"spec,omitempty"`
	Status         PortStatus `protobuf:"bytes,4,opt,name=Status" json:"status,omitempty"`
}

func (m *Port) Reset()                    { *m = Port{} }
func (m *Port) String() string            { return proto.CompactTextString(m) }
func (*Port) ProtoMessage()               {}
func (*Port) Descriptor() ([]byte, []int) { return fileDescriptorPort, []int{0} }

func (m *Port) GetSpec() PortSpec {
	if m != nil {
		return m.Spec
	}
	return PortSpec{}
}

func (m *Port) GetStatus() PortStatus {
	if m != nil {
		return m.Status
	}
	return PortStatus{}
}

// PortSpec captures all the port level configuration
type PortSpec struct {
	// Port Speed
	Speed string `protobuf:"bytes,1,opt,name=Speed,proto3" json:"speed,omitempty"`
	// Port Breakout Mode
	BreakoutMode string `protobuf:"bytes,2,opt,name=BreakoutMode,proto3" json:"breakout-mode,omitempty"`
	// AdminStatus of the overlay port.
	AdminStatus string `protobuf:"bytes,3,opt,name=AdminStatus,proto3" json:"admin-status,omitempty"`
}

func (m *PortSpec) Reset()                    { *m = PortSpec{} }
func (m *PortSpec) String() string            { return proto.CompactTextString(m) }
func (*PortSpec) ProtoMessage()               {}
func (*PortSpec) Descriptor() ([]byte, []int) { return fileDescriptorPort, []int{1} }

func (m *PortSpec) GetSpeed() string {
	if m != nil {
		return m.Speed
	}
	return ""
}

func (m *PortSpec) GetBreakoutMode() string {
	if m != nil {
		return m.BreakoutMode
	}
	return ""
}

func (m *PortSpec) GetAdminStatus() string {
	if m != nil {
		return m.AdminStatus
	}
	return ""
}

// Port Status
type PortStatus struct {
	// Operational Status
	OperStatus string `protobuf:"bytes,1,opt,name=OperStatus,proto3" json:"oper-status,omitempty"`
	// Operational Speed in case of AutoNeg
	OperSpeed string `protobuf:"bytes,2,opt,name=OperSpeed,proto3" json:"oper-status,omitempty"`
	// PortID in the datapath
	PortID uint64 `protobuf:"varint,3,opt,name=PortID,proto3" json:"id,omitempty"`
}

func (m *PortStatus) Reset()                    { *m = PortStatus{} }
func (m *PortStatus) String() string            { return proto.CompactTextString(m) }
func (*PortStatus) ProtoMessage()               {}
func (*PortStatus) Descriptor() ([]byte, []int) { return fileDescriptorPort, []int{2} }

func (m *PortStatus) GetOperStatus() string {
	if m != nil {
		return m.OperStatus
	}
	return ""
}

func (m *PortStatus) GetOperSpeed() string {
	if m != nil {
		return m.OperSpeed
	}
	return ""
}

func (m *PortStatus) GetPortID() uint64 {
	if m != nil {
		return m.PortID
	}
	return 0
}

type PortList struct {
	Ports []*Port `protobuf:"bytes,1,rep,name=ports" json:"ports,omitempty"`
}

func (m *PortList) Reset()                    { *m = PortList{} }
func (m *PortList) String() string            { return proto.CompactTextString(m) }
func (*PortList) ProtoMessage()               {}
func (*PortList) Descriptor() ([]byte, []int) { return fileDescriptorPort, []int{3} }

func (m *PortList) GetPorts() []*Port {
	if m != nil {
		return m.Ports
	}
	return nil
}

// port watch event
type PortEvent struct {
	EventType api.EventType `protobuf:"varint,1,opt,name=EventType,proto3,enum=api.EventType" json:"event-type,omitempty"`
	Port      Port          `protobuf:"bytes,2,opt,name=Port" json:"port,omitempty"`
}

func (m *PortEvent) Reset()                    { *m = PortEvent{} }
func (m *PortEvent) String() string            { return proto.CompactTextString(m) }
func (*PortEvent) ProtoMessage()               {}
func (*PortEvent) Descriptor() ([]byte, []int) { return fileDescriptorPort, []int{4} }

func (m *PortEvent) GetEventType() api.EventType {
	if m != nil {
		return m.EventType
	}
	return api.EventType_CreateEvent
}

func (m *PortEvent) GetPort() Port {
	if m != nil {
		return m.Port
	}
	return Port{}
}

func init() {
	proto.RegisterType((*Port)(nil), "netproto.Port")
	proto.RegisterType((*PortSpec)(nil), "netproto.PortSpec")
	proto.RegisterType((*PortStatus)(nil), "netproto.PortStatus")
	proto.RegisterType((*PortList)(nil), "netproto.PortList")
	proto.RegisterType((*PortEvent)(nil), "netproto.PortEvent")
	proto.RegisterEnum("netproto.PortSpec_PortSpeed", PortSpec_PortSpeed_name, PortSpec_PortSpeed_value)
	proto.RegisterEnum("netproto.PortSpec_PortBreakout", PortSpec_PortBreakout_name, PortSpec_PortBreakout_value)
	proto.RegisterEnum("netproto.PortSpec_IFStatus", PortSpec_IFStatus_name, PortSpec_IFStatus_value)
}

// Reference imports to suppress errors if they are not otherwise used.
var _ context.Context
var _ grpc.ClientConn

// This is a compile-time assertion to ensure that this generated file
// is compatible with the grpc package it is being compiled against.
const _ = grpc.SupportPackageIsVersion4

// Client API for PortApi service

type PortApiClient interface {
	GetPort(ctx context.Context, in *api.ObjectMeta, opts ...grpc.CallOption) (*Port, error)
	ListPorts(ctx context.Context, in *api.ObjectMeta, opts ...grpc.CallOption) (*PortList, error)
	WatchPorts(ctx context.Context, in *api.ObjectMeta, opts ...grpc.CallOption) (PortApi_WatchPortsClient, error)
}

type portApiClient struct {
	cc *grpc.ClientConn
}

func NewPortApiClient(cc *grpc.ClientConn) PortApiClient {
	return &portApiClient{cc}
}

func (c *portApiClient) GetPort(ctx context.Context, in *api.ObjectMeta, opts ...grpc.CallOption) (*Port, error) {
	out := new(Port)
	err := grpc.Invoke(ctx, "/netproto.PortApi/GetPort", in, out, c.cc, opts...)
	if err != nil {
		return nil, err
	}
	return out, nil
}

func (c *portApiClient) ListPorts(ctx context.Context, in *api.ObjectMeta, opts ...grpc.CallOption) (*PortList, error) {
	out := new(PortList)
	err := grpc.Invoke(ctx, "/netproto.PortApi/ListPorts", in, out, c.cc, opts...)
	if err != nil {
		return nil, err
	}
	return out, nil
}

func (c *portApiClient) WatchPorts(ctx context.Context, in *api.ObjectMeta, opts ...grpc.CallOption) (PortApi_WatchPortsClient, error) {
	stream, err := grpc.NewClientStream(ctx, &_PortApi_serviceDesc.Streams[0], c.cc, "/netproto.PortApi/WatchPorts", opts...)
	if err != nil {
		return nil, err
	}
	x := &portApiWatchPortsClient{stream}
	if err := x.ClientStream.SendMsg(in); err != nil {
		return nil, err
	}
	if err := x.ClientStream.CloseSend(); err != nil {
		return nil, err
	}
	return x, nil
}

type PortApi_WatchPortsClient interface {
	Recv() (*PortEvent, error)
	grpc.ClientStream
}

type portApiWatchPortsClient struct {
	grpc.ClientStream
}

func (x *portApiWatchPortsClient) Recv() (*PortEvent, error) {
	m := new(PortEvent)
	if err := x.ClientStream.RecvMsg(m); err != nil {
		return nil, err
	}
	return m, nil
}

// Server API for PortApi service

type PortApiServer interface {
	GetPort(context.Context, *api.ObjectMeta) (*Port, error)
	ListPorts(context.Context, *api.ObjectMeta) (*PortList, error)
	WatchPorts(*api.ObjectMeta, PortApi_WatchPortsServer) error
}

func RegisterPortApiServer(s *grpc.Server, srv PortApiServer) {
	s.RegisterService(&_PortApi_serviceDesc, srv)
}

func _PortApi_GetPort_Handler(srv interface{}, ctx context.Context, dec func(interface{}) error, interceptor grpc.UnaryServerInterceptor) (interface{}, error) {
	in := new(api.ObjectMeta)
	if err := dec(in); err != nil {
		return nil, err
	}
	if interceptor == nil {
		return srv.(PortApiServer).GetPort(ctx, in)
	}
	info := &grpc.UnaryServerInfo{
		Server:     srv,
		FullMethod: "/netproto.PortApi/GetPort",
	}
	handler := func(ctx context.Context, req interface{}) (interface{}, error) {
		return srv.(PortApiServer).GetPort(ctx, req.(*api.ObjectMeta))
	}
	return interceptor(ctx, in, info, handler)
}

func _PortApi_ListPorts_Handler(srv interface{}, ctx context.Context, dec func(interface{}) error, interceptor grpc.UnaryServerInterceptor) (interface{}, error) {
	in := new(api.ObjectMeta)
	if err := dec(in); err != nil {
		return nil, err
	}
	if interceptor == nil {
		return srv.(PortApiServer).ListPorts(ctx, in)
	}
	info := &grpc.UnaryServerInfo{
		Server:     srv,
		FullMethod: "/netproto.PortApi/ListPorts",
	}
	handler := func(ctx context.Context, req interface{}) (interface{}, error) {
		return srv.(PortApiServer).ListPorts(ctx, req.(*api.ObjectMeta))
	}
	return interceptor(ctx, in, info, handler)
}

func _PortApi_WatchPorts_Handler(srv interface{}, stream grpc.ServerStream) error {
	m := new(api.ObjectMeta)
	if err := stream.RecvMsg(m); err != nil {
		return err
	}
	return srv.(PortApiServer).WatchPorts(m, &portApiWatchPortsServer{stream})
}

type PortApi_WatchPortsServer interface {
	Send(*PortEvent) error
	grpc.ServerStream
}

type portApiWatchPortsServer struct {
	grpc.ServerStream
}

func (x *portApiWatchPortsServer) Send(m *PortEvent) error {
	return x.ServerStream.SendMsg(m)
}

var _PortApi_serviceDesc = grpc.ServiceDesc{
	ServiceName: "netproto.PortApi",
	HandlerType: (*PortApiServer)(nil),
	Methods: []grpc.MethodDesc{
		{
			MethodName: "GetPort",
			Handler:    _PortApi_GetPort_Handler,
		},
		{
			MethodName: "ListPorts",
			Handler:    _PortApi_ListPorts_Handler,
		},
	},
	Streams: []grpc.StreamDesc{
		{
			StreamName:    "WatchPorts",
			Handler:       _PortApi_WatchPorts_Handler,
			ServerStreams: true,
		},
	},
	Metadata: "port.proto",
}

func (m *Port) Marshal() (dAtA []byte, err error) {
	size := m.Size()
	dAtA = make([]byte, size)
	n, err := m.MarshalTo(dAtA)
	if err != nil {
		return nil, err
	}
	return dAtA[:n], nil
}

func (m *Port) MarshalTo(dAtA []byte) (int, error) {
	var i int
	_ = i
	var l int
	_ = l
	dAtA[i] = 0xa
	i++
	i = encodeVarintPort(dAtA, i, uint64(m.TypeMeta.Size()))
	n1, err := m.TypeMeta.MarshalTo(dAtA[i:])
	if err != nil {
		return 0, err
	}
	i += n1
	dAtA[i] = 0x12
	i++
	i = encodeVarintPort(dAtA, i, uint64(m.ObjectMeta.Size()))
	n2, err := m.ObjectMeta.MarshalTo(dAtA[i:])
	if err != nil {
		return 0, err
	}
	i += n2
	dAtA[i] = 0x1a
	i++
	i = encodeVarintPort(dAtA, i, uint64(m.Spec.Size()))
	n3, err := m.Spec.MarshalTo(dAtA[i:])
	if err != nil {
		return 0, err
	}
	i += n3
	dAtA[i] = 0x22
	i++
	i = encodeVarintPort(dAtA, i, uint64(m.Status.Size()))
	n4, err := m.Status.MarshalTo(dAtA[i:])
	if err != nil {
		return 0, err
	}
	i += n4
	return i, nil
}

func (m *PortSpec) Marshal() (dAtA []byte, err error) {
	size := m.Size()
	dAtA = make([]byte, size)
	n, err := m.MarshalTo(dAtA)
	if err != nil {
		return nil, err
	}
	return dAtA[:n], nil
}

func (m *PortSpec) MarshalTo(dAtA []byte) (int, error) {
	var i int
	_ = i
	var l int
	_ = l
	if len(m.Speed) > 0 {
		dAtA[i] = 0xa
		i++
		i = encodeVarintPort(dAtA, i, uint64(len(m.Speed)))
		i += copy(dAtA[i:], m.Speed)
	}
	if len(m.BreakoutMode) > 0 {
		dAtA[i] = 0x12
		i++
		i = encodeVarintPort(dAtA, i, uint64(len(m.BreakoutMode)))
		i += copy(dAtA[i:], m.BreakoutMode)
	}
	if len(m.AdminStatus) > 0 {
		dAtA[i] = 0x1a
		i++
		i = encodeVarintPort(dAtA, i, uint64(len(m.AdminStatus)))
		i += copy(dAtA[i:], m.AdminStatus)
	}
	return i, nil
}

func (m *PortStatus) Marshal() (dAtA []byte, err error) {
	size := m.Size()
	dAtA = make([]byte, size)
	n, err := m.MarshalTo(dAtA)
	if err != nil {
		return nil, err
	}
	return dAtA[:n], nil
}

func (m *PortStatus) MarshalTo(dAtA []byte) (int, error) {
	var i int
	_ = i
	var l int
	_ = l
	if len(m.OperStatus) > 0 {
		dAtA[i] = 0xa
		i++
		i = encodeVarintPort(dAtA, i, uint64(len(m.OperStatus)))
		i += copy(dAtA[i:], m.OperStatus)
	}
	if len(m.OperSpeed) > 0 {
		dAtA[i] = 0x12
		i++
		i = encodeVarintPort(dAtA, i, uint64(len(m.OperSpeed)))
		i += copy(dAtA[i:], m.OperSpeed)
	}
	if m.PortID != 0 {
		dAtA[i] = 0x18
		i++
		i = encodeVarintPort(dAtA, i, uint64(m.PortID))
	}
	return i, nil
}

func (m *PortList) Marshal() (dAtA []byte, err error) {
	size := m.Size()
	dAtA = make([]byte, size)
	n, err := m.MarshalTo(dAtA)
	if err != nil {
		return nil, err
	}
	return dAtA[:n], nil
}

func (m *PortList) MarshalTo(dAtA []byte) (int, error) {
	var i int
	_ = i
	var l int
	_ = l
	if len(m.Ports) > 0 {
		for _, msg := range m.Ports {
			dAtA[i] = 0xa
			i++
			i = encodeVarintPort(dAtA, i, uint64(msg.Size()))
			n, err := msg.MarshalTo(dAtA[i:])
			if err != nil {
				return 0, err
			}
			i += n
		}
	}
	return i, nil
}

func (m *PortEvent) Marshal() (dAtA []byte, err error) {
	size := m.Size()
	dAtA = make([]byte, size)
	n, err := m.MarshalTo(dAtA)
	if err != nil {
		return nil, err
	}
	return dAtA[:n], nil
}

func (m *PortEvent) MarshalTo(dAtA []byte) (int, error) {
	var i int
	_ = i
	var l int
	_ = l
	if m.EventType != 0 {
		dAtA[i] = 0x8
		i++
		i = encodeVarintPort(dAtA, i, uint64(m.EventType))
	}
	dAtA[i] = 0x12
	i++
	i = encodeVarintPort(dAtA, i, uint64(m.Port.Size()))
	n5, err := m.Port.MarshalTo(dAtA[i:])
	if err != nil {
		return 0, err
	}
	i += n5
	return i, nil
}

func encodeVarintPort(dAtA []byte, offset int, v uint64) int {
	for v >= 1<<7 {
		dAtA[offset] = uint8(v&0x7f | 0x80)
		v >>= 7
		offset++
	}
	dAtA[offset] = uint8(v)
	return offset + 1
}
func (m *Port) Size() (n int) {
	var l int
	_ = l
	l = m.TypeMeta.Size()
	n += 1 + l + sovPort(uint64(l))
	l = m.ObjectMeta.Size()
	n += 1 + l + sovPort(uint64(l))
	l = m.Spec.Size()
	n += 1 + l + sovPort(uint64(l))
	l = m.Status.Size()
	n += 1 + l + sovPort(uint64(l))
	return n
}

func (m *PortSpec) Size() (n int) {
	var l int
	_ = l
	l = len(m.Speed)
	if l > 0 {
		n += 1 + l + sovPort(uint64(l))
	}
	l = len(m.BreakoutMode)
	if l > 0 {
		n += 1 + l + sovPort(uint64(l))
	}
	l = len(m.AdminStatus)
	if l > 0 {
		n += 1 + l + sovPort(uint64(l))
	}
	return n
}

func (m *PortStatus) Size() (n int) {
	var l int
	_ = l
	l = len(m.OperStatus)
	if l > 0 {
		n += 1 + l + sovPort(uint64(l))
	}
	l = len(m.OperSpeed)
	if l > 0 {
		n += 1 + l + sovPort(uint64(l))
	}
	if m.PortID != 0 {
		n += 1 + sovPort(uint64(m.PortID))
	}
	return n
}

func (m *PortList) Size() (n int) {
	var l int
	_ = l
	if len(m.Ports) > 0 {
		for _, e := range m.Ports {
			l = e.Size()
			n += 1 + l + sovPort(uint64(l))
		}
	}
	return n
}

func (m *PortEvent) Size() (n int) {
	var l int
	_ = l
	if m.EventType != 0 {
		n += 1 + sovPort(uint64(m.EventType))
	}
	l = m.Port.Size()
	n += 1 + l + sovPort(uint64(l))
	return n
}

func sovPort(x uint64) (n int) {
	for {
		n++
		x >>= 7
		if x == 0 {
			break
		}
	}
	return n
}
func sozPort(x uint64) (n int) {
	return sovPort(uint64((x << 1) ^ uint64((int64(x) >> 63))))
}
func (m *Port) Unmarshal(dAtA []byte) error {
	l := len(dAtA)
	iNdEx := 0
	for iNdEx < l {
		preIndex := iNdEx
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return ErrIntOverflowPort
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
			return fmt.Errorf("proto: Port: wiretype end group for non-group")
		}
		if fieldNum <= 0 {
			return fmt.Errorf("proto: Port: illegal tag %d (wire type %d)", fieldNum, wire)
		}
		switch fieldNum {
		case 1:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field TypeMeta", wireType)
			}
			var msglen int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowPort
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
				return ErrInvalidLengthPort
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
					return ErrIntOverflowPort
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
				return ErrInvalidLengthPort
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
					return ErrIntOverflowPort
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
				return ErrInvalidLengthPort
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
					return ErrIntOverflowPort
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
				return ErrInvalidLengthPort
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
			skippy, err := skipPort(dAtA[iNdEx:])
			if err != nil {
				return err
			}
			if skippy < 0 {
				return ErrInvalidLengthPort
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
func (m *PortSpec) Unmarshal(dAtA []byte) error {
	l := len(dAtA)
	iNdEx := 0
	for iNdEx < l {
		preIndex := iNdEx
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return ErrIntOverflowPort
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
			return fmt.Errorf("proto: PortSpec: wiretype end group for non-group")
		}
		if fieldNum <= 0 {
			return fmt.Errorf("proto: PortSpec: illegal tag %d (wire type %d)", fieldNum, wire)
		}
		switch fieldNum {
		case 1:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field Speed", wireType)
			}
			var stringLen uint64
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowPort
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
				return ErrInvalidLengthPort
			}
			postIndex := iNdEx + intStringLen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.Speed = string(dAtA[iNdEx:postIndex])
			iNdEx = postIndex
		case 2:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field BreakoutMode", wireType)
			}
			var stringLen uint64
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowPort
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
				return ErrInvalidLengthPort
			}
			postIndex := iNdEx + intStringLen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.BreakoutMode = string(dAtA[iNdEx:postIndex])
			iNdEx = postIndex
		case 3:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field AdminStatus", wireType)
			}
			var stringLen uint64
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowPort
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
				return ErrInvalidLengthPort
			}
			postIndex := iNdEx + intStringLen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.AdminStatus = string(dAtA[iNdEx:postIndex])
			iNdEx = postIndex
		default:
			iNdEx = preIndex
			skippy, err := skipPort(dAtA[iNdEx:])
			if err != nil {
				return err
			}
			if skippy < 0 {
				return ErrInvalidLengthPort
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
func (m *PortStatus) Unmarshal(dAtA []byte) error {
	l := len(dAtA)
	iNdEx := 0
	for iNdEx < l {
		preIndex := iNdEx
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return ErrIntOverflowPort
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
			return fmt.Errorf("proto: PortStatus: wiretype end group for non-group")
		}
		if fieldNum <= 0 {
			return fmt.Errorf("proto: PortStatus: illegal tag %d (wire type %d)", fieldNum, wire)
		}
		switch fieldNum {
		case 1:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field OperStatus", wireType)
			}
			var stringLen uint64
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowPort
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
				return ErrInvalidLengthPort
			}
			postIndex := iNdEx + intStringLen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.OperStatus = string(dAtA[iNdEx:postIndex])
			iNdEx = postIndex
		case 2:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field OperSpeed", wireType)
			}
			var stringLen uint64
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowPort
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
				return ErrInvalidLengthPort
			}
			postIndex := iNdEx + intStringLen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.OperSpeed = string(dAtA[iNdEx:postIndex])
			iNdEx = postIndex
		case 3:
			if wireType != 0 {
				return fmt.Errorf("proto: wrong wireType = %d for field PortID", wireType)
			}
			m.PortID = 0
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowPort
				}
				if iNdEx >= l {
					return io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				m.PortID |= (uint64(b) & 0x7F) << shift
				if b < 0x80 {
					break
				}
			}
		default:
			iNdEx = preIndex
			skippy, err := skipPort(dAtA[iNdEx:])
			if err != nil {
				return err
			}
			if skippy < 0 {
				return ErrInvalidLengthPort
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
func (m *PortList) Unmarshal(dAtA []byte) error {
	l := len(dAtA)
	iNdEx := 0
	for iNdEx < l {
		preIndex := iNdEx
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return ErrIntOverflowPort
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
			return fmt.Errorf("proto: PortList: wiretype end group for non-group")
		}
		if fieldNum <= 0 {
			return fmt.Errorf("proto: PortList: illegal tag %d (wire type %d)", fieldNum, wire)
		}
		switch fieldNum {
		case 1:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field Ports", wireType)
			}
			var msglen int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowPort
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
				return ErrInvalidLengthPort
			}
			postIndex := iNdEx + msglen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.Ports = append(m.Ports, &Port{})
			if err := m.Ports[len(m.Ports)-1].Unmarshal(dAtA[iNdEx:postIndex]); err != nil {
				return err
			}
			iNdEx = postIndex
		default:
			iNdEx = preIndex
			skippy, err := skipPort(dAtA[iNdEx:])
			if err != nil {
				return err
			}
			if skippy < 0 {
				return ErrInvalidLengthPort
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
func (m *PortEvent) Unmarshal(dAtA []byte) error {
	l := len(dAtA)
	iNdEx := 0
	for iNdEx < l {
		preIndex := iNdEx
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return ErrIntOverflowPort
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
			return fmt.Errorf("proto: PortEvent: wiretype end group for non-group")
		}
		if fieldNum <= 0 {
			return fmt.Errorf("proto: PortEvent: illegal tag %d (wire type %d)", fieldNum, wire)
		}
		switch fieldNum {
		case 1:
			if wireType != 0 {
				return fmt.Errorf("proto: wrong wireType = %d for field EventType", wireType)
			}
			m.EventType = 0
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowPort
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
				return fmt.Errorf("proto: wrong wireType = %d for field Port", wireType)
			}
			var msglen int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowPort
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
				return ErrInvalidLengthPort
			}
			postIndex := iNdEx + msglen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			if err := m.Port.Unmarshal(dAtA[iNdEx:postIndex]); err != nil {
				return err
			}
			iNdEx = postIndex
		default:
			iNdEx = preIndex
			skippy, err := skipPort(dAtA[iNdEx:])
			if err != nil {
				return err
			}
			if skippy < 0 {
				return ErrInvalidLengthPort
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
func skipPort(dAtA []byte) (n int, err error) {
	l := len(dAtA)
	iNdEx := 0
	for iNdEx < l {
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return 0, ErrIntOverflowPort
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
					return 0, ErrIntOverflowPort
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
					return 0, ErrIntOverflowPort
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
				return 0, ErrInvalidLengthPort
			}
			return iNdEx, nil
		case 3:
			for {
				var innerWire uint64
				var start int = iNdEx
				for shift := uint(0); ; shift += 7 {
					if shift >= 64 {
						return 0, ErrIntOverflowPort
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
				next, err := skipPort(dAtA[start:])
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
	ErrInvalidLengthPort = fmt.Errorf("proto: negative length found during unmarshaling")
	ErrIntOverflowPort   = fmt.Errorf("proto: integer overflow")
)

func init() { proto.RegisterFile("port.proto", fileDescriptorPort) }

var fileDescriptorPort = []byte{
	// 886 bytes of a gzipped FileDescriptorProto
	0x1f, 0x8b, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xff, 0x7c, 0x95, 0x41, 0x6f, 0x1b, 0x45,
	0x14, 0xc7, 0xbd, 0xf6, 0xc6, 0xb1, 0x5f, 0x12, 0x77, 0x99, 0x96, 0x62, 0x9b, 0x12, 0xa3, 0x15,
	0xa0, 0x20, 0x25, 0x5e, 0xc7, 0xb4, 0x80, 0x2a, 0xa8, 0x94, 0x55, 0x9c, 0x55, 0x55, 0x6a, 0x47,
	0x71, 0x42, 0x7a, 0x00, 0xc1, 0xda, 0x7e, 0xb8, 0x0b, 0xde, 0x9d, 0x91, 0x77, 0x5c, 0x14, 0xa1,
	0x9e, 0x90, 0x22, 0x6e, 0x48, 0x9c, 0x90, 0x38, 0x73, 0xc9, 0x91, 0x4f, 0xd1, 0x63, 0x3f, 0x81,
	0x85, 0xc2, 0x01, 0xc9, 0x9f, 0x02, 0xcd, 0xec, 0x6e, 0x76, 0x6c, 0x27, 0xdc, 0xde, 0x7b, 0xf3,
	0xde, 0x6f, 0xde, 0xfc, 0xfd, 0xf6, 0x19, 0x80, 0xd1, 0x31, 0xaf, 0xb3, 0x31, 0xe5, 0x94, 0x14,
	0x02, 0xe4, 0xd2, 0xaa, 0xde, 0x1b, 0x52, 0x3a, 0x1c, 0xa1, 0xe5, 0x32, 0xcf, 0x72, 0x83, 0x80,
	0x72, 0x97, 0x7b, 0x34, 0x08, 0xa3, 0xbc, 0x6a, 0x6b, 0xe8, 0xf1, 0xe7, 0x93, 0x5e, 0xbd, 0x4f,
	0x7d, 0x8b, 0x61, 0x10, 0xba, 0xc1, 0x80, 0x5a, 0xe1, 0x8f, 0xd6, 0x0b, 0x0c, 0xbc, 0x3e, 0x5a,
	0x13, 0xee, 0x8d, 0x42, 0x51, 0x3a, 0xc4, 0x40, 0xad, 0xb6, 0xbc, 0xa0, 0x3f, 0x9a, 0x0c, 0x30,
	0xc1, 0xec, 0x28, 0x98, 0x21, 0x1d, 0x52, 0x4b, 0x86, 0x7b, 0x93, 0xef, 0xa4, 0x27, 0x1d, 0x69,
	0xc5, 0xe9, 0xef, 0xdf, 0x70, 0xab, 0xe8, 0xd1, 0x47, 0xee, 0x46, 0x69, 0xe6, 0x1f, 0x59, 0xd0,
	0x0f, 0xe9, 0x98, 0x93, 0x47, 0x50, 0x38, 0x3e, 0x63, 0xf8, 0x14, 0xb9, 0x5b, 0xd6, 0xde, 0xd5,
	0xb6, 0xd6, 0x9a, 0x1b, 0x75, 0x97, 0x79, 0xf5, 0x24, 0x68, 0xdf, 0x7e, 0x35, 0xad, 0x65, 0x5e,
	0x4f, 0x6b, 0xda, 0x6c, 0x5a, 0x5b, 0xdd, 0xf6, 0x82, 0x91, 0x17, 0xe0, 0xd1, 0x55, 0x0d, 0x79,
	0x02, 0xd0, 0xe9, 0x7d, 0x8f, 0x7d, 0x2e, 0x09, 0x59, 0x49, 0xb8, 0x25, 0x09, 0x69, 0xd8, 0xae,
	0x2a, 0x8c, 0x92, 0xe8, 0x62, 0x9b, 0xfa, 0x1e, 0x47, 0x9f, 0xf1, 0xb3, 0x23, 0xa5, 0x9c, 0x3c,
	0x02, 0xbd, 0xcb, 0xb0, 0x5f, 0xce, 0x49, 0x0c, 0xa9, 0x27, 0x4a, 0xd7, 0x45, 0xab, 0xe2, 0xc4,
	0xbe, 0x2b, 0x48, 0x82, 0x12, 0x32, 0xec, 0x2b, 0x14, 0x59, 0x47, 0x0e, 0x20, 0xdf, 0xe5, 0x2e,
	0x9f, 0x84, 0x65, 0x5d, 0x12, 0xee, 0x2c, 0x10, 0xe4, 0x99, 0x5d, 0x8e, 0x19, 0x46, 0x28, 0x7d,
	0x85, 0x12, 0x57, 0x9b, 0x7f, 0xea, 0x50, 0x48, 0xae, 0x24, 0x0e, 0xac, 0x74, 0x19, 0xe2, 0x40,
	0xca, 0x53, 0xb4, 0x77, 0x2f, 0xce, 0x2b, 0xd5, 0x2e, 0x1f, 0xb7, 0x82, 0x89, 0xbf, 0x95, 0x24,
	0x25, 0x0d, 0xe2, 0x60, 0x36, 0xad, 0xdd, 0x0a, 0x85, 0xa1, 0x60, 0xa3, 0x7a, 0xf2, 0x2d, 0xac,
	0xdb, 0x63, 0x74, 0x7f, 0xa0, 0x13, 0xfe, 0x94, 0x0e, 0x50, 0x8a, 0x55, 0xb4, 0x3f, 0xbb, 0x38,
	0xaf, 0xbc, 0x73, 0x2d, 0x2f, 0x49, 0x9e, 0x4d, 0x6b, 0x6f, 0xf5, 0x62, 0x7b, 0xc7, 0xa7, 0x03,
	0x54, 0xd0, 0x73, 0x44, 0xf2, 0x15, 0xac, 0xed, 0x0d, 0x7c, 0x2f, 0x88, 0x45, 0xc8, 0xc9, 0x0b,
	0x1e, 0x5e, 0x9c, 0x57, 0xee, 0xcd, 0x5d, 0x20, 0x4f, 0xeb, 0x8f, 0x0f, 0x22, 0xe3, 0xc3, 0xd9,
	0xb4, 0x76, 0xd7, 0x15, 0x65, 0x3b, 0x4b, 0x82, 0xa8, 0x38, 0xf3, 0x17, 0x0d, 0x8a, 0x57, 0xef,
	0x24, 0x25, 0x80, 0xee, 0x61, 0xab, 0xb5, 0xff, 0x4d, 0xbb, 0xd3, 0x6e, 0x19, 0x19, 0xb2, 0x0e,
	0x85, 0xc8, 0xdf, 0x75, 0x0c, 0x8d, 0x6c, 0x40, 0x31, 0xf6, 0x1a, 0x8e, 0x91, 0x4d, 0xdd, 0xe6,
	0x03, 0xc7, 0xc8, 0xa5, 0xee, 0xfd, 0x86, 0x63, 0xe8, 0xa9, 0xfb, 0xa0, 0xe1, 0x18, 0x2b, 0x29,
	0x79, 0xb7, 0xd1, 0x70, 0x8c, 0x3c, 0x79, 0x03, 0x36, 0x22, 0x7f, 0xef, 0xe4, 0xb8, 0xd3, 0x6e,
	0x39, 0xc6, 0xaa, 0xf9, 0x35, 0xac, 0xab, 0x0a, 0x89, 0x14, 0xfb, 0xa8, 0xb5, 0xf7, 0xa4, 0x73,
	0x72, 0x9c, 0xf4, 0x43, 0xa0, 0x74, 0x15, 0xba, 0xff, 0x4c, 0xdc, 0xab, 0x2d, 0xc4, 0xa2, 0xd6,
	0xd4, 0x58, 0xf3, 0x99, 0xe8, 0x20, 0x67, 0x7e, 0x00, 0x85, 0x44, 0x1d, 0x52, 0x00, 0x3d, 0x26,
	0xe6, 0x21, 0x7b, 0x72, 0x68, 0x68, 0x22, 0xb2, 0xdf, 0x39, 0x6d, 0x1b, 0x59, 0xf3, 0x5f, 0x0d,
	0x20, 0x55, 0x94, 0x9c, 0x02, 0x74, 0x18, 0x8e, 0x63, 0xf5, 0xa3, 0x71, 0xf9, 0xe4, 0xda, 0x71,
	0x51, 0xb5, 0x7f, 0x93, 0x32, 0x1c, 0x2f, 0x4b, 0xaf, 0xa0, 0xc8, 0x97, 0x50, 0x94, 0x9e, 0x1c,
	0xc3, 0x68, 0x6c, 0x3e, 0xbd, 0x38, 0xaf, 0xbc, 0x7d, 0xf3, 0x18, 0xfe, 0x0f, 0x38, 0x45, 0x91,
	0x2d, 0xc8, 0x8b, 0x8a, 0xc7, 0xfb, 0x72, 0x54, 0x74, 0xdb, 0x98, 0x4d, 0x6b, 0xeb, 0x9e, 0x3a,
	0xba, 0xf1, 0xb9, 0xd9, 0x88, 0x3e, 0x88, 0x2f, 0xbc, 0x90, 0x93, 0xf7, 0x60, 0x45, 0xac, 0x43,
	0xf1, 0xc2, 0xdc, 0xd6, 0x5a, 0xb3, 0x34, 0xff, 0x91, 0x1d, 0x45, 0x87, 0xe6, 0xaf, 0xf1, 0xb4,
	0xb4, 0x5e, 0x60, 0xc0, 0xc9, 0x01, 0x14, 0xa5, 0x21, 0xf6, 0x86, 0x54, 0xa6, 0xd4, 0x2c, 0xc9,
	0x2d, 0x71, 0x15, 0xb5, 0xcb, 0xb3, 0x69, 0xed, 0x0e, 0x0a, 0x77, 0x87, 0x9f, 0x31, 0x75, 0xc8,
	0xd3, 0x52, 0xf2, 0x30, 0x5a, 0x5b, 0xf1, 0xa2, 0x59, 0xb8, 0x3a, 0xdd, 0x0e, 0xa2, 0x05, 0x75,
	0x3b, 0x88, 0xd3, 0xe6, 0x6f, 0x59, 0x58, 0x15, 0xc6, 0x1e, 0xf3, 0xc8, 0x36, 0xac, 0x3a, 0xc8,
	0xe5, 0x06, 0x5c, 0xdc, 0x56, 0xd5, 0x05, 0xaa, 0x99, 0x21, 0x4d, 0x28, 0x8a, 0x97, 0x0b, 0x2f,
	0x5c, 0xce, 0x5f, 0xd8, 0x53, 0x22, 0xd3, 0xcc, 0x90, 0x8f, 0x01, 0x4e, 0x5d, 0xde, 0x7f, 0x7e,
	0x43, 0xd1, 0xed, 0xf9, 0x22, 0xf9, 0x42, 0x33, 0xd3, 0xd0, 0xaa, 0xfe, 0x5f, 0x3f, 0x57, 0xbc,
	0x78, 0x39, 0xeb, 0x23, 0xa1, 0xb7, 0xce, 0x68, 0xc8, 0x49, 0x7e, 0x80, 0x23, 0xe4, 0x48, 0x72,
	0x6c, 0xc2, 0xab, 0x9f, 0x5b, 0x3f, 0xa5, 0xac, 0xfa, 0x31, 0x06, 0x6e, 0xc0, 0x5f, 0xce, 0xc5,
	0xda, 0xae, 0x8f, 0x21, 0x73, 0xfb, 0xb8, 0x1c, 0x7e, 0x69, 0x16, 0xc5, 0xbf, 0x81, 0xfc, 0x99,
	0x6c, 0xe3, 0xd5, 0xe5, 0xa6, 0xf6, 0xfa, 0x72, 0x53, 0xfb, 0xfb, 0x72, 0x53, 0xfb, 0xfd, 0x9f,
	0xcd, 0xcc, 0xa1, 0xd6, 0xcb, 0xcb, 0xbe, 0x3e, 0xfa, 0x2f, 0x00, 0x00, 0xff, 0xff, 0x69, 0xe7,
	0x9a, 0xee, 0xf6, 0x06, 0x00, 0x00,
}
