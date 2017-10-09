// Code generated by protoc-gen-gogo. DO NOT EDIT.
// source: nic/proto/hal/descriptor_aol.proto

package halproto

import proto "github.com/golang/protobuf/proto"
import fmt "fmt"
import math "math"

import (
	context "golang.org/x/net/context"
	grpc "google.golang.org/grpc"
)

import io "io"

// Reference imports to suppress errors if they are not otherwise used.
var _ = proto.Marshal
var _ = fmt.Errorf
var _ = math.Inf

// Ignoring public import of ObjectMeta from nic/proto/types.proto

// Ignoring public import of EncapInfo from nic/proto/types.proto

// Ignoring public import of IPAddress from nic/proto/types.proto

// Ignoring public import of IPPrefix from nic/proto/types.proto

// Ignoring public import of L4PortRange from nic/proto/types.proto

// Ignoring public import of Empty from nic/proto/types.proto

// Ignoring public import of IPProtocol from nic/proto/types.proto

// Ignoring public import of ICMPMsgType from nic/proto/types.proto

// Ignoring public import of ApiStatus from nic/proto/types.proto

// Ignoring public import of L2SegmentType from nic/proto/types.proto

// Ignoring public import of encapType from nic/proto/types.proto

// Ignoring public import of IPAddressFamily from nic/proto/types.proto

// Ignoring public import of WRingType from nic/proto/types.proto

// Ignoring public import of ProxyType from nic/proto/types.proto

// Ignoring public import of CryptoKeyType from nic/proto/types.proto

type DescrAolRequest struct {
	Meta           *ObjectMeta `protobuf:"bytes,1,opt,name=meta" json:"meta,omitempty"`
	DescrAolHandle uint64      `protobuf:"fixed64,2,opt,name=descr_aol_handle,json=descrAolHandle,proto3" json:"descr_aol_handle,omitempty"`
}

func (m *DescrAolRequest) Reset()                    { *m = DescrAolRequest{} }
func (m *DescrAolRequest) String() string            { return proto.CompactTextString(m) }
func (*DescrAolRequest) ProtoMessage()               {}
func (*DescrAolRequest) Descriptor() ([]byte, []int) { return fileDescriptorDescriptorAol, []int{0} }

func (m *DescrAolRequest) GetMeta() *ObjectMeta {
	if m != nil {
		return m.Meta
	}
	return nil
}

func (m *DescrAolRequest) GetDescrAolHandle() uint64 {
	if m != nil {
		return m.DescrAolHandle
	}
	return 0
}

type DescrAolRequestMsg struct {
	Request []*DescrAolRequest `protobuf:"bytes,1,rep,name=request" json:"request,omitempty"`
}

func (m *DescrAolRequestMsg) Reset()                    { *m = DescrAolRequestMsg{} }
func (m *DescrAolRequestMsg) String() string            { return proto.CompactTextString(m) }
func (*DescrAolRequestMsg) ProtoMessage()               {}
func (*DescrAolRequestMsg) Descriptor() ([]byte, []int) { return fileDescriptorDescriptorAol, []int{1} }

func (m *DescrAolRequestMsg) GetRequest() []*DescrAolRequest {
	if m != nil {
		return m.Request
	}
	return nil
}

type DescrAolSpec struct {
	ApiStatus          ApiStatus   `protobuf:"varint,1,opt,name=api_status,json=apiStatus,proto3,enum=types.ApiStatus" json:"api_status,omitempty"`
	Meta               *ObjectMeta `protobuf:"bytes,2,opt,name=meta" json:"meta,omitempty"`
	DescrAolHandle     uint64      `protobuf:"fixed64,3,opt,name=descr_aol_handle,json=descrAolHandle,proto3" json:"descr_aol_handle,omitempty"`
	Address1           uint64      `protobuf:"fixed64,4,opt,name=Address1,proto3" json:"Address1,omitempty"`
	Offset1            uint32      `protobuf:"fixed32,5,opt,name=Offset1,proto3" json:"Offset1,omitempty"`
	Length1            uint32      `protobuf:"fixed32,6,opt,name=Length1,proto3" json:"Length1,omitempty"`
	Address2           uint64      `protobuf:"fixed64,7,opt,name=Address2,proto3" json:"Address2,omitempty"`
	Offset2            uint32      `protobuf:"fixed32,8,opt,name=Offset2,proto3" json:"Offset2,omitempty"`
	Length2            uint32      `protobuf:"fixed32,9,opt,name=Length2,proto3" json:"Length2,omitempty"`
	Address3           uint64      `protobuf:"fixed64,10,opt,name=Address3,proto3" json:"Address3,omitempty"`
	Offset3            uint32      `protobuf:"fixed32,11,opt,name=Offset3,proto3" json:"Offset3,omitempty"`
	Length3            uint32      `protobuf:"fixed32,12,opt,name=Length3,proto3" json:"Length3,omitempty"`
	NextDescrAolHandle uint64      `protobuf:"fixed64,13,opt,name=next_descr_aol_handle,json=nextDescrAolHandle,proto3" json:"next_descr_aol_handle,omitempty"`
}

func (m *DescrAolSpec) Reset()                    { *m = DescrAolSpec{} }
func (m *DescrAolSpec) String() string            { return proto.CompactTextString(m) }
func (*DescrAolSpec) ProtoMessage()               {}
func (*DescrAolSpec) Descriptor() ([]byte, []int) { return fileDescriptorDescriptorAol, []int{2} }

func (m *DescrAolSpec) GetApiStatus() ApiStatus {
	if m != nil {
		return m.ApiStatus
	}
	return ApiStatus_API_STATUS_OK
}

func (m *DescrAolSpec) GetMeta() *ObjectMeta {
	if m != nil {
		return m.Meta
	}
	return nil
}

func (m *DescrAolSpec) GetDescrAolHandle() uint64 {
	if m != nil {
		return m.DescrAolHandle
	}
	return 0
}

func (m *DescrAolSpec) GetAddress1() uint64 {
	if m != nil {
		return m.Address1
	}
	return 0
}

func (m *DescrAolSpec) GetOffset1() uint32 {
	if m != nil {
		return m.Offset1
	}
	return 0
}

func (m *DescrAolSpec) GetLength1() uint32 {
	if m != nil {
		return m.Length1
	}
	return 0
}

func (m *DescrAolSpec) GetAddress2() uint64 {
	if m != nil {
		return m.Address2
	}
	return 0
}

func (m *DescrAolSpec) GetOffset2() uint32 {
	if m != nil {
		return m.Offset2
	}
	return 0
}

func (m *DescrAolSpec) GetLength2() uint32 {
	if m != nil {
		return m.Length2
	}
	return 0
}

func (m *DescrAolSpec) GetAddress3() uint64 {
	if m != nil {
		return m.Address3
	}
	return 0
}

func (m *DescrAolSpec) GetOffset3() uint32 {
	if m != nil {
		return m.Offset3
	}
	return 0
}

func (m *DescrAolSpec) GetLength3() uint32 {
	if m != nil {
		return m.Length3
	}
	return 0
}

func (m *DescrAolSpec) GetNextDescrAolHandle() uint64 {
	if m != nil {
		return m.NextDescrAolHandle
	}
	return 0
}

type DescrAolResponseMsg struct {
	Response []*DescrAolSpec `protobuf:"bytes,1,rep,name=response" json:"response,omitempty"`
}

func (m *DescrAolResponseMsg) Reset()                    { *m = DescrAolResponseMsg{} }
func (m *DescrAolResponseMsg) String() string            { return proto.CompactTextString(m) }
func (*DescrAolResponseMsg) ProtoMessage()               {}
func (*DescrAolResponseMsg) Descriptor() ([]byte, []int) { return fileDescriptorDescriptorAol, []int{3} }

func (m *DescrAolResponseMsg) GetResponse() []*DescrAolSpec {
	if m != nil {
		return m.Response
	}
	return nil
}

func init() {
	proto.RegisterType((*DescrAolRequest)(nil), "descraol.DescrAolRequest")
	proto.RegisterType((*DescrAolRequestMsg)(nil), "descraol.DescrAolRequestMsg")
	proto.RegisterType((*DescrAolSpec)(nil), "descraol.DescrAolSpec")
	proto.RegisterType((*DescrAolResponseMsg)(nil), "descraol.DescrAolResponseMsg")
}

// Reference imports to suppress errors if they are not otherwise used.
var _ context.Context
var _ grpc.ClientConn

// This is a compile-time assertion to ensure that this generated file
// is compatible with the grpc package it is being compiled against.
const _ = grpc.SupportPackageIsVersion4

// Client API for DescrAol service

type DescrAolClient interface {
	DescrAolGet(ctx context.Context, in *DescrAolRequestMsg, opts ...grpc.CallOption) (*DescrAolResponseMsg, error)
}

type descrAolClient struct {
	cc *grpc.ClientConn
}

func NewDescrAolClient(cc *grpc.ClientConn) DescrAolClient {
	return &descrAolClient{cc}
}

func (c *descrAolClient) DescrAolGet(ctx context.Context, in *DescrAolRequestMsg, opts ...grpc.CallOption) (*DescrAolResponseMsg, error) {
	out := new(DescrAolResponseMsg)
	err := grpc.Invoke(ctx, "/descraol.DescrAol/DescrAolGet", in, out, c.cc, opts...)
	if err != nil {
		return nil, err
	}
	return out, nil
}

// Server API for DescrAol service

type DescrAolServer interface {
	DescrAolGet(context.Context, *DescrAolRequestMsg) (*DescrAolResponseMsg, error)
}

func RegisterDescrAolServer(s *grpc.Server, srv DescrAolServer) {
	s.RegisterService(&_DescrAol_serviceDesc, srv)
}

func _DescrAol_DescrAolGet_Handler(srv interface{}, ctx context.Context, dec func(interface{}) error, interceptor grpc.UnaryServerInterceptor) (interface{}, error) {
	in := new(DescrAolRequestMsg)
	if err := dec(in); err != nil {
		return nil, err
	}
	if interceptor == nil {
		return srv.(DescrAolServer).DescrAolGet(ctx, in)
	}
	info := &grpc.UnaryServerInfo{
		Server:     srv,
		FullMethod: "/descraol.DescrAol/DescrAolGet",
	}
	handler := func(ctx context.Context, req interface{}) (interface{}, error) {
		return srv.(DescrAolServer).DescrAolGet(ctx, req.(*DescrAolRequestMsg))
	}
	return interceptor(ctx, in, info, handler)
}

var _DescrAol_serviceDesc = grpc.ServiceDesc{
	ServiceName: "descraol.DescrAol",
	HandlerType: (*DescrAolServer)(nil),
	Methods: []grpc.MethodDesc{
		{
			MethodName: "DescrAolGet",
			Handler:    _DescrAol_DescrAolGet_Handler,
		},
	},
	Streams:  []grpc.StreamDesc{},
	Metadata: "nic/proto/hal/descriptor_aol.proto",
}

func (m *DescrAolRequest) Marshal() (dAtA []byte, err error) {
	size := m.Size()
	dAtA = make([]byte, size)
	n, err := m.MarshalTo(dAtA)
	if err != nil {
		return nil, err
	}
	return dAtA[:n], nil
}

func (m *DescrAolRequest) MarshalTo(dAtA []byte) (int, error) {
	var i int
	_ = i
	var l int
	_ = l
	if m.Meta != nil {
		dAtA[i] = 0xa
		i++
		i = encodeVarintDescriptorAol(dAtA, i, uint64(m.Meta.Size()))
		n1, err := m.Meta.MarshalTo(dAtA[i:])
		if err != nil {
			return 0, err
		}
		i += n1
	}
	if m.DescrAolHandle != 0 {
		dAtA[i] = 0x11
		i++
		i = encodeFixed64DescriptorAol(dAtA, i, uint64(m.DescrAolHandle))
	}
	return i, nil
}

func (m *DescrAolRequestMsg) Marshal() (dAtA []byte, err error) {
	size := m.Size()
	dAtA = make([]byte, size)
	n, err := m.MarshalTo(dAtA)
	if err != nil {
		return nil, err
	}
	return dAtA[:n], nil
}

func (m *DescrAolRequestMsg) MarshalTo(dAtA []byte) (int, error) {
	var i int
	_ = i
	var l int
	_ = l
	if len(m.Request) > 0 {
		for _, msg := range m.Request {
			dAtA[i] = 0xa
			i++
			i = encodeVarintDescriptorAol(dAtA, i, uint64(msg.Size()))
			n, err := msg.MarshalTo(dAtA[i:])
			if err != nil {
				return 0, err
			}
			i += n
		}
	}
	return i, nil
}

func (m *DescrAolSpec) Marshal() (dAtA []byte, err error) {
	size := m.Size()
	dAtA = make([]byte, size)
	n, err := m.MarshalTo(dAtA)
	if err != nil {
		return nil, err
	}
	return dAtA[:n], nil
}

func (m *DescrAolSpec) MarshalTo(dAtA []byte) (int, error) {
	var i int
	_ = i
	var l int
	_ = l
	if m.ApiStatus != 0 {
		dAtA[i] = 0x8
		i++
		i = encodeVarintDescriptorAol(dAtA, i, uint64(m.ApiStatus))
	}
	if m.Meta != nil {
		dAtA[i] = 0x12
		i++
		i = encodeVarintDescriptorAol(dAtA, i, uint64(m.Meta.Size()))
		n2, err := m.Meta.MarshalTo(dAtA[i:])
		if err != nil {
			return 0, err
		}
		i += n2
	}
	if m.DescrAolHandle != 0 {
		dAtA[i] = 0x19
		i++
		i = encodeFixed64DescriptorAol(dAtA, i, uint64(m.DescrAolHandle))
	}
	if m.Address1 != 0 {
		dAtA[i] = 0x21
		i++
		i = encodeFixed64DescriptorAol(dAtA, i, uint64(m.Address1))
	}
	if m.Offset1 != 0 {
		dAtA[i] = 0x2d
		i++
		i = encodeFixed32DescriptorAol(dAtA, i, uint32(m.Offset1))
	}
	if m.Length1 != 0 {
		dAtA[i] = 0x35
		i++
		i = encodeFixed32DescriptorAol(dAtA, i, uint32(m.Length1))
	}
	if m.Address2 != 0 {
		dAtA[i] = 0x39
		i++
		i = encodeFixed64DescriptorAol(dAtA, i, uint64(m.Address2))
	}
	if m.Offset2 != 0 {
		dAtA[i] = 0x45
		i++
		i = encodeFixed32DescriptorAol(dAtA, i, uint32(m.Offset2))
	}
	if m.Length2 != 0 {
		dAtA[i] = 0x4d
		i++
		i = encodeFixed32DescriptorAol(dAtA, i, uint32(m.Length2))
	}
	if m.Address3 != 0 {
		dAtA[i] = 0x51
		i++
		i = encodeFixed64DescriptorAol(dAtA, i, uint64(m.Address3))
	}
	if m.Offset3 != 0 {
		dAtA[i] = 0x5d
		i++
		i = encodeFixed32DescriptorAol(dAtA, i, uint32(m.Offset3))
	}
	if m.Length3 != 0 {
		dAtA[i] = 0x65
		i++
		i = encodeFixed32DescriptorAol(dAtA, i, uint32(m.Length3))
	}
	if m.NextDescrAolHandle != 0 {
		dAtA[i] = 0x69
		i++
		i = encodeFixed64DescriptorAol(dAtA, i, uint64(m.NextDescrAolHandle))
	}
	return i, nil
}

func (m *DescrAolResponseMsg) Marshal() (dAtA []byte, err error) {
	size := m.Size()
	dAtA = make([]byte, size)
	n, err := m.MarshalTo(dAtA)
	if err != nil {
		return nil, err
	}
	return dAtA[:n], nil
}

func (m *DescrAolResponseMsg) MarshalTo(dAtA []byte) (int, error) {
	var i int
	_ = i
	var l int
	_ = l
	if len(m.Response) > 0 {
		for _, msg := range m.Response {
			dAtA[i] = 0xa
			i++
			i = encodeVarintDescriptorAol(dAtA, i, uint64(msg.Size()))
			n, err := msg.MarshalTo(dAtA[i:])
			if err != nil {
				return 0, err
			}
			i += n
		}
	}
	return i, nil
}

func encodeFixed64DescriptorAol(dAtA []byte, offset int, v uint64) int {
	dAtA[offset] = uint8(v)
	dAtA[offset+1] = uint8(v >> 8)
	dAtA[offset+2] = uint8(v >> 16)
	dAtA[offset+3] = uint8(v >> 24)
	dAtA[offset+4] = uint8(v >> 32)
	dAtA[offset+5] = uint8(v >> 40)
	dAtA[offset+6] = uint8(v >> 48)
	dAtA[offset+7] = uint8(v >> 56)
	return offset + 8
}
func encodeFixed32DescriptorAol(dAtA []byte, offset int, v uint32) int {
	dAtA[offset] = uint8(v)
	dAtA[offset+1] = uint8(v >> 8)
	dAtA[offset+2] = uint8(v >> 16)
	dAtA[offset+3] = uint8(v >> 24)
	return offset + 4
}
func encodeVarintDescriptorAol(dAtA []byte, offset int, v uint64) int {
	for v >= 1<<7 {
		dAtA[offset] = uint8(v&0x7f | 0x80)
		v >>= 7
		offset++
	}
	dAtA[offset] = uint8(v)
	return offset + 1
}
func (m *DescrAolRequest) Size() (n int) {
	var l int
	_ = l
	if m.Meta != nil {
		l = m.Meta.Size()
		n += 1 + l + sovDescriptorAol(uint64(l))
	}
	if m.DescrAolHandle != 0 {
		n += 9
	}
	return n
}

func (m *DescrAolRequestMsg) Size() (n int) {
	var l int
	_ = l
	if len(m.Request) > 0 {
		for _, e := range m.Request {
			l = e.Size()
			n += 1 + l + sovDescriptorAol(uint64(l))
		}
	}
	return n
}

func (m *DescrAolSpec) Size() (n int) {
	var l int
	_ = l
	if m.ApiStatus != 0 {
		n += 1 + sovDescriptorAol(uint64(m.ApiStatus))
	}
	if m.Meta != nil {
		l = m.Meta.Size()
		n += 1 + l + sovDescriptorAol(uint64(l))
	}
	if m.DescrAolHandle != 0 {
		n += 9
	}
	if m.Address1 != 0 {
		n += 9
	}
	if m.Offset1 != 0 {
		n += 5
	}
	if m.Length1 != 0 {
		n += 5
	}
	if m.Address2 != 0 {
		n += 9
	}
	if m.Offset2 != 0 {
		n += 5
	}
	if m.Length2 != 0 {
		n += 5
	}
	if m.Address3 != 0 {
		n += 9
	}
	if m.Offset3 != 0 {
		n += 5
	}
	if m.Length3 != 0 {
		n += 5
	}
	if m.NextDescrAolHandle != 0 {
		n += 9
	}
	return n
}

func (m *DescrAolResponseMsg) Size() (n int) {
	var l int
	_ = l
	if len(m.Response) > 0 {
		for _, e := range m.Response {
			l = e.Size()
			n += 1 + l + sovDescriptorAol(uint64(l))
		}
	}
	return n
}

func sovDescriptorAol(x uint64) (n int) {
	for {
		n++
		x >>= 7
		if x == 0 {
			break
		}
	}
	return n
}
func sozDescriptorAol(x uint64) (n int) {
	return sovDescriptorAol(uint64((x << 1) ^ uint64((int64(x) >> 63))))
}
func (m *DescrAolRequest) Unmarshal(dAtA []byte) error {
	l := len(dAtA)
	iNdEx := 0
	for iNdEx < l {
		preIndex := iNdEx
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return ErrIntOverflowDescriptorAol
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
			return fmt.Errorf("proto: DescrAolRequest: wiretype end group for non-group")
		}
		if fieldNum <= 0 {
			return fmt.Errorf("proto: DescrAolRequest: illegal tag %d (wire type %d)", fieldNum, wire)
		}
		switch fieldNum {
		case 1:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field Meta", wireType)
			}
			var msglen int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowDescriptorAol
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
				return ErrInvalidLengthDescriptorAol
			}
			postIndex := iNdEx + msglen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			if m.Meta == nil {
				m.Meta = &ObjectMeta{}
			}
			if err := m.Meta.Unmarshal(dAtA[iNdEx:postIndex]); err != nil {
				return err
			}
			iNdEx = postIndex
		case 2:
			if wireType != 1 {
				return fmt.Errorf("proto: wrong wireType = %d for field DescrAolHandle", wireType)
			}
			m.DescrAolHandle = 0
			if (iNdEx + 8) > l {
				return io.ErrUnexpectedEOF
			}
			iNdEx += 8
			m.DescrAolHandle = uint64(dAtA[iNdEx-8])
			m.DescrAolHandle |= uint64(dAtA[iNdEx-7]) << 8
			m.DescrAolHandle |= uint64(dAtA[iNdEx-6]) << 16
			m.DescrAolHandle |= uint64(dAtA[iNdEx-5]) << 24
			m.DescrAolHandle |= uint64(dAtA[iNdEx-4]) << 32
			m.DescrAolHandle |= uint64(dAtA[iNdEx-3]) << 40
			m.DescrAolHandle |= uint64(dAtA[iNdEx-2]) << 48
			m.DescrAolHandle |= uint64(dAtA[iNdEx-1]) << 56
		default:
			iNdEx = preIndex
			skippy, err := skipDescriptorAol(dAtA[iNdEx:])
			if err != nil {
				return err
			}
			if skippy < 0 {
				return ErrInvalidLengthDescriptorAol
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
func (m *DescrAolRequestMsg) Unmarshal(dAtA []byte) error {
	l := len(dAtA)
	iNdEx := 0
	for iNdEx < l {
		preIndex := iNdEx
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return ErrIntOverflowDescriptorAol
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
			return fmt.Errorf("proto: DescrAolRequestMsg: wiretype end group for non-group")
		}
		if fieldNum <= 0 {
			return fmt.Errorf("proto: DescrAolRequestMsg: illegal tag %d (wire type %d)", fieldNum, wire)
		}
		switch fieldNum {
		case 1:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field Request", wireType)
			}
			var msglen int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowDescriptorAol
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
				return ErrInvalidLengthDescriptorAol
			}
			postIndex := iNdEx + msglen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.Request = append(m.Request, &DescrAolRequest{})
			if err := m.Request[len(m.Request)-1].Unmarshal(dAtA[iNdEx:postIndex]); err != nil {
				return err
			}
			iNdEx = postIndex
		default:
			iNdEx = preIndex
			skippy, err := skipDescriptorAol(dAtA[iNdEx:])
			if err != nil {
				return err
			}
			if skippy < 0 {
				return ErrInvalidLengthDescriptorAol
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
func (m *DescrAolSpec) Unmarshal(dAtA []byte) error {
	l := len(dAtA)
	iNdEx := 0
	for iNdEx < l {
		preIndex := iNdEx
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return ErrIntOverflowDescriptorAol
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
			return fmt.Errorf("proto: DescrAolSpec: wiretype end group for non-group")
		}
		if fieldNum <= 0 {
			return fmt.Errorf("proto: DescrAolSpec: illegal tag %d (wire type %d)", fieldNum, wire)
		}
		switch fieldNum {
		case 1:
			if wireType != 0 {
				return fmt.Errorf("proto: wrong wireType = %d for field ApiStatus", wireType)
			}
			m.ApiStatus = 0
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowDescriptorAol
				}
				if iNdEx >= l {
					return io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				m.ApiStatus |= (ApiStatus(b) & 0x7F) << shift
				if b < 0x80 {
					break
				}
			}
		case 2:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field Meta", wireType)
			}
			var msglen int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowDescriptorAol
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
				return ErrInvalidLengthDescriptorAol
			}
			postIndex := iNdEx + msglen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			if m.Meta == nil {
				m.Meta = &ObjectMeta{}
			}
			if err := m.Meta.Unmarshal(dAtA[iNdEx:postIndex]); err != nil {
				return err
			}
			iNdEx = postIndex
		case 3:
			if wireType != 1 {
				return fmt.Errorf("proto: wrong wireType = %d for field DescrAolHandle", wireType)
			}
			m.DescrAolHandle = 0
			if (iNdEx + 8) > l {
				return io.ErrUnexpectedEOF
			}
			iNdEx += 8
			m.DescrAolHandle = uint64(dAtA[iNdEx-8])
			m.DescrAolHandle |= uint64(dAtA[iNdEx-7]) << 8
			m.DescrAolHandle |= uint64(dAtA[iNdEx-6]) << 16
			m.DescrAolHandle |= uint64(dAtA[iNdEx-5]) << 24
			m.DescrAolHandle |= uint64(dAtA[iNdEx-4]) << 32
			m.DescrAolHandle |= uint64(dAtA[iNdEx-3]) << 40
			m.DescrAolHandle |= uint64(dAtA[iNdEx-2]) << 48
			m.DescrAolHandle |= uint64(dAtA[iNdEx-1]) << 56
		case 4:
			if wireType != 1 {
				return fmt.Errorf("proto: wrong wireType = %d for field Address1", wireType)
			}
			m.Address1 = 0
			if (iNdEx + 8) > l {
				return io.ErrUnexpectedEOF
			}
			iNdEx += 8
			m.Address1 = uint64(dAtA[iNdEx-8])
			m.Address1 |= uint64(dAtA[iNdEx-7]) << 8
			m.Address1 |= uint64(dAtA[iNdEx-6]) << 16
			m.Address1 |= uint64(dAtA[iNdEx-5]) << 24
			m.Address1 |= uint64(dAtA[iNdEx-4]) << 32
			m.Address1 |= uint64(dAtA[iNdEx-3]) << 40
			m.Address1 |= uint64(dAtA[iNdEx-2]) << 48
			m.Address1 |= uint64(dAtA[iNdEx-1]) << 56
		case 5:
			if wireType != 5 {
				return fmt.Errorf("proto: wrong wireType = %d for field Offset1", wireType)
			}
			m.Offset1 = 0
			if (iNdEx + 4) > l {
				return io.ErrUnexpectedEOF
			}
			iNdEx += 4
			m.Offset1 = uint32(dAtA[iNdEx-4])
			m.Offset1 |= uint32(dAtA[iNdEx-3]) << 8
			m.Offset1 |= uint32(dAtA[iNdEx-2]) << 16
			m.Offset1 |= uint32(dAtA[iNdEx-1]) << 24
		case 6:
			if wireType != 5 {
				return fmt.Errorf("proto: wrong wireType = %d for field Length1", wireType)
			}
			m.Length1 = 0
			if (iNdEx + 4) > l {
				return io.ErrUnexpectedEOF
			}
			iNdEx += 4
			m.Length1 = uint32(dAtA[iNdEx-4])
			m.Length1 |= uint32(dAtA[iNdEx-3]) << 8
			m.Length1 |= uint32(dAtA[iNdEx-2]) << 16
			m.Length1 |= uint32(dAtA[iNdEx-1]) << 24
		case 7:
			if wireType != 1 {
				return fmt.Errorf("proto: wrong wireType = %d for field Address2", wireType)
			}
			m.Address2 = 0
			if (iNdEx + 8) > l {
				return io.ErrUnexpectedEOF
			}
			iNdEx += 8
			m.Address2 = uint64(dAtA[iNdEx-8])
			m.Address2 |= uint64(dAtA[iNdEx-7]) << 8
			m.Address2 |= uint64(dAtA[iNdEx-6]) << 16
			m.Address2 |= uint64(dAtA[iNdEx-5]) << 24
			m.Address2 |= uint64(dAtA[iNdEx-4]) << 32
			m.Address2 |= uint64(dAtA[iNdEx-3]) << 40
			m.Address2 |= uint64(dAtA[iNdEx-2]) << 48
			m.Address2 |= uint64(dAtA[iNdEx-1]) << 56
		case 8:
			if wireType != 5 {
				return fmt.Errorf("proto: wrong wireType = %d for field Offset2", wireType)
			}
			m.Offset2 = 0
			if (iNdEx + 4) > l {
				return io.ErrUnexpectedEOF
			}
			iNdEx += 4
			m.Offset2 = uint32(dAtA[iNdEx-4])
			m.Offset2 |= uint32(dAtA[iNdEx-3]) << 8
			m.Offset2 |= uint32(dAtA[iNdEx-2]) << 16
			m.Offset2 |= uint32(dAtA[iNdEx-1]) << 24
		case 9:
			if wireType != 5 {
				return fmt.Errorf("proto: wrong wireType = %d for field Length2", wireType)
			}
			m.Length2 = 0
			if (iNdEx + 4) > l {
				return io.ErrUnexpectedEOF
			}
			iNdEx += 4
			m.Length2 = uint32(dAtA[iNdEx-4])
			m.Length2 |= uint32(dAtA[iNdEx-3]) << 8
			m.Length2 |= uint32(dAtA[iNdEx-2]) << 16
			m.Length2 |= uint32(dAtA[iNdEx-1]) << 24
		case 10:
			if wireType != 1 {
				return fmt.Errorf("proto: wrong wireType = %d for field Address3", wireType)
			}
			m.Address3 = 0
			if (iNdEx + 8) > l {
				return io.ErrUnexpectedEOF
			}
			iNdEx += 8
			m.Address3 = uint64(dAtA[iNdEx-8])
			m.Address3 |= uint64(dAtA[iNdEx-7]) << 8
			m.Address3 |= uint64(dAtA[iNdEx-6]) << 16
			m.Address3 |= uint64(dAtA[iNdEx-5]) << 24
			m.Address3 |= uint64(dAtA[iNdEx-4]) << 32
			m.Address3 |= uint64(dAtA[iNdEx-3]) << 40
			m.Address3 |= uint64(dAtA[iNdEx-2]) << 48
			m.Address3 |= uint64(dAtA[iNdEx-1]) << 56
		case 11:
			if wireType != 5 {
				return fmt.Errorf("proto: wrong wireType = %d for field Offset3", wireType)
			}
			m.Offset3 = 0
			if (iNdEx + 4) > l {
				return io.ErrUnexpectedEOF
			}
			iNdEx += 4
			m.Offset3 = uint32(dAtA[iNdEx-4])
			m.Offset3 |= uint32(dAtA[iNdEx-3]) << 8
			m.Offset3 |= uint32(dAtA[iNdEx-2]) << 16
			m.Offset3 |= uint32(dAtA[iNdEx-1]) << 24
		case 12:
			if wireType != 5 {
				return fmt.Errorf("proto: wrong wireType = %d for field Length3", wireType)
			}
			m.Length3 = 0
			if (iNdEx + 4) > l {
				return io.ErrUnexpectedEOF
			}
			iNdEx += 4
			m.Length3 = uint32(dAtA[iNdEx-4])
			m.Length3 |= uint32(dAtA[iNdEx-3]) << 8
			m.Length3 |= uint32(dAtA[iNdEx-2]) << 16
			m.Length3 |= uint32(dAtA[iNdEx-1]) << 24
		case 13:
			if wireType != 1 {
				return fmt.Errorf("proto: wrong wireType = %d for field NextDescrAolHandle", wireType)
			}
			m.NextDescrAolHandle = 0
			if (iNdEx + 8) > l {
				return io.ErrUnexpectedEOF
			}
			iNdEx += 8
			m.NextDescrAolHandle = uint64(dAtA[iNdEx-8])
			m.NextDescrAolHandle |= uint64(dAtA[iNdEx-7]) << 8
			m.NextDescrAolHandle |= uint64(dAtA[iNdEx-6]) << 16
			m.NextDescrAolHandle |= uint64(dAtA[iNdEx-5]) << 24
			m.NextDescrAolHandle |= uint64(dAtA[iNdEx-4]) << 32
			m.NextDescrAolHandle |= uint64(dAtA[iNdEx-3]) << 40
			m.NextDescrAolHandle |= uint64(dAtA[iNdEx-2]) << 48
			m.NextDescrAolHandle |= uint64(dAtA[iNdEx-1]) << 56
		default:
			iNdEx = preIndex
			skippy, err := skipDescriptorAol(dAtA[iNdEx:])
			if err != nil {
				return err
			}
			if skippy < 0 {
				return ErrInvalidLengthDescriptorAol
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
func (m *DescrAolResponseMsg) Unmarshal(dAtA []byte) error {
	l := len(dAtA)
	iNdEx := 0
	for iNdEx < l {
		preIndex := iNdEx
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return ErrIntOverflowDescriptorAol
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
			return fmt.Errorf("proto: DescrAolResponseMsg: wiretype end group for non-group")
		}
		if fieldNum <= 0 {
			return fmt.Errorf("proto: DescrAolResponseMsg: illegal tag %d (wire type %d)", fieldNum, wire)
		}
		switch fieldNum {
		case 1:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field Response", wireType)
			}
			var msglen int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowDescriptorAol
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
				return ErrInvalidLengthDescriptorAol
			}
			postIndex := iNdEx + msglen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.Response = append(m.Response, &DescrAolSpec{})
			if err := m.Response[len(m.Response)-1].Unmarshal(dAtA[iNdEx:postIndex]); err != nil {
				return err
			}
			iNdEx = postIndex
		default:
			iNdEx = preIndex
			skippy, err := skipDescriptorAol(dAtA[iNdEx:])
			if err != nil {
				return err
			}
			if skippy < 0 {
				return ErrInvalidLengthDescriptorAol
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
func skipDescriptorAol(dAtA []byte) (n int, err error) {
	l := len(dAtA)
	iNdEx := 0
	for iNdEx < l {
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return 0, ErrIntOverflowDescriptorAol
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
					return 0, ErrIntOverflowDescriptorAol
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
					return 0, ErrIntOverflowDescriptorAol
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
				return 0, ErrInvalidLengthDescriptorAol
			}
			return iNdEx, nil
		case 3:
			for {
				var innerWire uint64
				var start int = iNdEx
				for shift := uint(0); ; shift += 7 {
					if shift >= 64 {
						return 0, ErrIntOverflowDescriptorAol
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
				next, err := skipDescriptorAol(dAtA[start:])
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
	ErrInvalidLengthDescriptorAol = fmt.Errorf("proto: negative length found during unmarshaling")
	ErrIntOverflowDescriptorAol   = fmt.Errorf("proto: integer overflow")
)

func init() { proto.RegisterFile("nic/proto/hal/descriptor_aol.proto", fileDescriptorDescriptorAol) }

var fileDescriptorDescriptorAol = []byte{
	// 436 bytes of a gzipped FileDescriptorProto
	0x1f, 0x8b, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xff, 0x94, 0x93, 0xdf, 0x6a, 0xd4, 0x40,
	0x14, 0xc6, 0x77, 0xba, 0x75, 0x37, 0x3d, 0x5b, 0x6b, 0x1d, 0xa9, 0x8c, 0x8b, 0x86, 0x10, 0x10,
	0x72, 0x95, 0x90, 0x99, 0x27, 0x58, 0x29, 0xa8, 0xd0, 0xa5, 0x92, 0xde, 0x88, 0x37, 0x61, 0x36,
	0x99, 0x6e, 0x22, 0x31, 0x89, 0x99, 0x29, 0xe8, 0x9b, 0xf8, 0x1e, 0xbe, 0x84, 0x97, 0x3e, 0x82,
	0xac, 0x2f, 0x22, 0x99, 0xfc, 0xed, 0xb6, 0x5e, 0xf4, 0x6e, 0xce, 0xf9, 0x3e, 0x7e, 0x73, 0x4e,
	0xe6, 0x0b, 0xd8, 0x79, 0x1a, 0x79, 0x65, 0x55, 0xa8, 0xc2, 0x4b, 0x78, 0xe6, 0xc5, 0x42, 0x46,
	0x55, 0x5a, 0xaa, 0xa2, 0x0a, 0x79, 0x91, 0xb9, 0x5a, 0xc0, 0x86, 0xee, 0xf2, 0x22, 0x5b, 0x9e,
	0x0d, 0x6e, 0xf5, 0xbd, 0x14, 0xb2, 0x31, 0xd8, 0x1b, 0x78, 0x72, 0x5e, 0x5b, 0x56, 0x45, 0x16,
	0x88, 0xaf, 0x37, 0x42, 0x2a, 0xfc, 0x1a, 0x0e, 0xbf, 0x08, 0xc5, 0x09, 0xb2, 0x90, 0xb3, 0xa0,
	0x4f, 0xdd, 0xc6, 0x7e, 0xb9, 0xf9, 0x2c, 0x22, 0xb5, 0x16, 0x8a, 0x07, 0x5a, 0xc6, 0x0e, 0x9c,
	0x6a, 0x78, 0x7d, 0x5b, 0x98, 0xf0, 0x3c, 0xce, 0x04, 0x39, 0xb0, 0x90, 0x33, 0x0b, 0x4e, 0xe2,
	0x96, 0xf8, 0x4e, 0x77, 0xed, 0xf7, 0x80, 0xf7, 0xee, 0x58, 0xcb, 0x2d, 0x66, 0x30, 0xaf, 0x9a,
	0x8a, 0x20, 0x6b, 0xea, 0x2c, 0xe8, 0x0b, 0xb7, 0x1b, 0xd6, 0xdd, 0xb3, 0x07, 0x9d, 0xd3, 0xfe,
	0x39, 0x85, 0xe3, 0x4e, 0xbc, 0x2a, 0x45, 0x84, 0x3d, 0x00, 0x5e, 0xa6, 0xa1, 0x54, 0x5c, 0xdd,
	0x48, 0x3d, 0xf2, 0x09, 0x3d, 0x6d, 0x47, 0x5e, 0x95, 0xe9, 0x95, 0xee, 0x07, 0x47, 0xbc, 0x3b,
	0xf6, 0xdb, 0x1d, 0x3c, 0x7c, 0xbb, 0xe9, 0x7d, 0xdb, 0xe1, 0x25, 0x18, 0xab, 0x38, 0xae, 0x84,
	0x94, 0x3e, 0x39, 0xd4, 0x8e, 0xbe, 0xc6, 0x04, 0xe6, 0x97, 0xd7, 0xd7, 0x52, 0x28, 0x9f, 0x3c,
	0xb2, 0x90, 0x33, 0x0f, 0xba, 0xb2, 0x56, 0x2e, 0x44, 0xbe, 0x55, 0x89, 0x4f, 0x66, 0x8d, 0xd2,
	0x96, 0x23, 0x1e, 0x25, 0xf3, 0x5b, 0x3c, 0x3a, 0xf0, 0x28, 0x31, 0xc6, 0x3c, 0x3a, 0xf0, 0x28,
	0x39, 0x1a, 0xf3, 0xe8, 0x88, 0xc7, 0x08, 0xdc, 0xe2, 0xb1, 0x81, 0xc7, 0xc8, 0x62, 0xcc, 0x63,
	0x03, 0x8f, 0x91, 0xe3, 0x31, 0x8f, 0x61, 0x1f, 0xce, 0x72, 0xf1, 0x4d, 0x85, 0x77, 0x3e, 0xcf,
	0x63, 0x0d, 0xc7, 0xb5, 0x78, 0xbe, 0x1f, 0x80, 0x67, 0xc3, 0x8b, 0xca, 0xb2, 0xc8, 0xa5, 0xa8,
	0x13, 0x40, 0xc1, 0xa8, 0xda, 0xb2, 0x8d, 0xc0, 0xf3, 0xbb, 0x11, 0xa8, 0x5f, 0x39, 0xe8, 0x7d,
	0xf4, 0x23, 0x18, 0x9d, 0x82, 0x2f, 0x60, 0xd1, 0x9d, 0xdf, 0x0a, 0x85, 0x5f, 0xfe, 0x37, 0x3f,
	0x6b, 0xb9, 0x5d, 0xbe, 0xba, 0x4f, 0xed, 0x67, 0xb1, 0x27, 0x6f, 0x96, 0xbf, 0x76, 0x26, 0xfa,
	0xbd, 0x33, 0xd1, 0x9f, 0x9d, 0x89, 0x7e, 0xfc, 0x35, 0x27, 0x9f, 0x8c, 0x84, 0x67, 0xfa, 0x2f,
	0xf9, 0x30, 0xd9, 0xcc, 0xf4, 0x81, 0xfd, 0x0b, 0x00, 0x00, 0xff, 0xff, 0x9c, 0x10, 0x0e, 0x87,
	0x75, 0x03, 0x00, 0x00,
}
