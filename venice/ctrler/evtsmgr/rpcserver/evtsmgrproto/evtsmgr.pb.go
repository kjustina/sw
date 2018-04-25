// Code generated by protoc-gen-gogo. DO NOT EDIT.
// source: evtsmgr.proto

/*
	Package evtsmgrproto is a generated protocol buffer package.

	It is generated from these files:
		evtsmgr.proto

	It has these top-level messages:
		Empty
		EventList
*/
package evtsmgrproto

import proto "github.com/gogo/protobuf/proto"
import fmt "fmt"
import math "math"
import _ "google.golang.org/genproto/googleapis/api/annotations"
import api "github.com/pensando/sw/api"
import _ "github.com/pensando/sw/venice/utils/apigen/annotations"
import _ "github.com/gogo/protobuf/gogoproto"
import monitoring "github.com/pensando/sw/api/generated/monitoring"

import (
	context "golang.org/x/net/context"
	grpc "google.golang.org/grpc"
)

import io "io"

// Reference imports to suppress errors if they are not otherwise used.
var _ = proto.Marshal
var _ = fmt.Errorf
var _ = math.Inf

// This is a compile-time assertion to ensure that this generated file
// is compatible with the proto package it is being compiled against.
// A compilation error at this line likely means your copy of the
// proto package needs to be updated.
const _ = proto.GoGoProtoPackageIsVersion2 // please upgrade the proto package

type Empty struct {
}

func (m *Empty) Reset()                    { *m = Empty{} }
func (m *Empty) String() string            { return proto.CompactTextString(m) }
func (*Empty) ProtoMessage()               {}
func (*Empty) Descriptor() ([]byte, []int) { return fileDescriptorEvtsmgr, []int{0} }

type EventList struct {
	Events []monitoring.Event `protobuf:"bytes,1,rep,name=Events" json:"Events"`
}

func (m *EventList) Reset()                    { *m = EventList{} }
func (m *EventList) String() string            { return proto.CompactTextString(m) }
func (*EventList) ProtoMessage()               {}
func (*EventList) Descriptor() ([]byte, []int) { return fileDescriptorEvtsmgr, []int{1} }

func (m *EventList) GetEvents() []monitoring.Event {
	if m != nil {
		return m.Events
	}
	return nil
}

func init() {
	proto.RegisterType((*Empty)(nil), "evtsmgrproto.Empty")
	proto.RegisterType((*EventList)(nil), "evtsmgrproto.EventList")
}

// Reference imports to suppress errors if they are not otherwise used.
var _ context.Context
var _ grpc.ClientConn

// This is a compile-time assertion to ensure that this generated file
// is compatible with the grpc package it is being compiled against.
const _ = grpc.SupportPackageIsVersion4

// Client API for EvtsMgrAPI service

type EvtsMgrAPIClient interface {
	// any component can use this method to generate an event
	SendEvents(ctx context.Context, in *monitoring.EventsList, opts ...grpc.CallOption) (*api.Empty, error)
}

type evtsMgrAPIClient struct {
	cc *grpc.ClientConn
}

func NewEvtsMgrAPIClient(cc *grpc.ClientConn) EvtsMgrAPIClient {
	return &evtsMgrAPIClient{cc}
}

func (c *evtsMgrAPIClient) SendEvents(ctx context.Context, in *monitoring.EventsList, opts ...grpc.CallOption) (*api.Empty, error) {
	out := new(api.Empty)
	err := grpc.Invoke(ctx, "/evtsmgrproto.EvtsMgrAPI/SendEvents", in, out, c.cc, opts...)
	if err != nil {
		return nil, err
	}
	return out, nil
}

// Server API for EvtsMgrAPI service

type EvtsMgrAPIServer interface {
	// any component can use this method to generate an event
	SendEvents(context.Context, *monitoring.EventsList) (*api.Empty, error)
}

func RegisterEvtsMgrAPIServer(s *grpc.Server, srv EvtsMgrAPIServer) {
	s.RegisterService(&_EvtsMgrAPI_serviceDesc, srv)
}

func _EvtsMgrAPI_SendEvents_Handler(srv interface{}, ctx context.Context, dec func(interface{}) error, interceptor grpc.UnaryServerInterceptor) (interface{}, error) {
	in := new(monitoring.EventsList)
	if err := dec(in); err != nil {
		return nil, err
	}
	if interceptor == nil {
		return srv.(EvtsMgrAPIServer).SendEvents(ctx, in)
	}
	info := &grpc.UnaryServerInfo{
		Server:     srv,
		FullMethod: "/evtsmgrproto.EvtsMgrAPI/SendEvents",
	}
	handler := func(ctx context.Context, req interface{}) (interface{}, error) {
		return srv.(EvtsMgrAPIServer).SendEvents(ctx, req.(*monitoring.EventsList))
	}
	return interceptor(ctx, in, info, handler)
}

var _EvtsMgrAPI_serviceDesc = grpc.ServiceDesc{
	ServiceName: "evtsmgrproto.EvtsMgrAPI",
	HandlerType: (*EvtsMgrAPIServer)(nil),
	Methods: []grpc.MethodDesc{
		{
			MethodName: "SendEvents",
			Handler:    _EvtsMgrAPI_SendEvents_Handler,
		},
	},
	Streams:  []grpc.StreamDesc{},
	Metadata: "evtsmgr.proto",
}

func (m *Empty) Marshal() (dAtA []byte, err error) {
	size := m.Size()
	dAtA = make([]byte, size)
	n, err := m.MarshalTo(dAtA)
	if err != nil {
		return nil, err
	}
	return dAtA[:n], nil
}

func (m *Empty) MarshalTo(dAtA []byte) (int, error) {
	var i int
	_ = i
	var l int
	_ = l
	return i, nil
}

func (m *EventList) Marshal() (dAtA []byte, err error) {
	size := m.Size()
	dAtA = make([]byte, size)
	n, err := m.MarshalTo(dAtA)
	if err != nil {
		return nil, err
	}
	return dAtA[:n], nil
}

func (m *EventList) MarshalTo(dAtA []byte) (int, error) {
	var i int
	_ = i
	var l int
	_ = l
	if len(m.Events) > 0 {
		for _, msg := range m.Events {
			dAtA[i] = 0xa
			i++
			i = encodeVarintEvtsmgr(dAtA, i, uint64(msg.Size()))
			n, err := msg.MarshalTo(dAtA[i:])
			if err != nil {
				return 0, err
			}
			i += n
		}
	}
	return i, nil
}

func encodeVarintEvtsmgr(dAtA []byte, offset int, v uint64) int {
	for v >= 1<<7 {
		dAtA[offset] = uint8(v&0x7f | 0x80)
		v >>= 7
		offset++
	}
	dAtA[offset] = uint8(v)
	return offset + 1
}
func (m *Empty) Size() (n int) {
	var l int
	_ = l
	return n
}

func (m *EventList) Size() (n int) {
	var l int
	_ = l
	if len(m.Events) > 0 {
		for _, e := range m.Events {
			l = e.Size()
			n += 1 + l + sovEvtsmgr(uint64(l))
		}
	}
	return n
}

func sovEvtsmgr(x uint64) (n int) {
	for {
		n++
		x >>= 7
		if x == 0 {
			break
		}
	}
	return n
}
func sozEvtsmgr(x uint64) (n int) {
	return sovEvtsmgr(uint64((x << 1) ^ uint64((int64(x) >> 63))))
}
func (m *Empty) Unmarshal(dAtA []byte) error {
	l := len(dAtA)
	iNdEx := 0
	for iNdEx < l {
		preIndex := iNdEx
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return ErrIntOverflowEvtsmgr
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
			return fmt.Errorf("proto: Empty: wiretype end group for non-group")
		}
		if fieldNum <= 0 {
			return fmt.Errorf("proto: Empty: illegal tag %d (wire type %d)", fieldNum, wire)
		}
		switch fieldNum {
		default:
			iNdEx = preIndex
			skippy, err := skipEvtsmgr(dAtA[iNdEx:])
			if err != nil {
				return err
			}
			if skippy < 0 {
				return ErrInvalidLengthEvtsmgr
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
func (m *EventList) Unmarshal(dAtA []byte) error {
	l := len(dAtA)
	iNdEx := 0
	for iNdEx < l {
		preIndex := iNdEx
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return ErrIntOverflowEvtsmgr
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
			return fmt.Errorf("proto: EventList: wiretype end group for non-group")
		}
		if fieldNum <= 0 {
			return fmt.Errorf("proto: EventList: illegal tag %d (wire type %d)", fieldNum, wire)
		}
		switch fieldNum {
		case 1:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field Events", wireType)
			}
			var msglen int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowEvtsmgr
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
				return ErrInvalidLengthEvtsmgr
			}
			postIndex := iNdEx + msglen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.Events = append(m.Events, monitoring.Event{})
			if err := m.Events[len(m.Events)-1].Unmarshal(dAtA[iNdEx:postIndex]); err != nil {
				return err
			}
			iNdEx = postIndex
		default:
			iNdEx = preIndex
			skippy, err := skipEvtsmgr(dAtA[iNdEx:])
			if err != nil {
				return err
			}
			if skippy < 0 {
				return ErrInvalidLengthEvtsmgr
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
func skipEvtsmgr(dAtA []byte) (n int, err error) {
	l := len(dAtA)
	iNdEx := 0
	for iNdEx < l {
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return 0, ErrIntOverflowEvtsmgr
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
					return 0, ErrIntOverflowEvtsmgr
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
					return 0, ErrIntOverflowEvtsmgr
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
				return 0, ErrInvalidLengthEvtsmgr
			}
			return iNdEx, nil
		case 3:
			for {
				var innerWire uint64
				var start int = iNdEx
				for shift := uint(0); ; shift += 7 {
					if shift >= 64 {
						return 0, ErrIntOverflowEvtsmgr
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
				next, err := skipEvtsmgr(dAtA[start:])
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
	ErrInvalidLengthEvtsmgr = fmt.Errorf("proto: negative length found during unmarshaling")
	ErrIntOverflowEvtsmgr   = fmt.Errorf("proto: integer overflow")
)

func init() { proto.RegisterFile("evtsmgr.proto", fileDescriptorEvtsmgr) }

var fileDescriptorEvtsmgr = []byte{
	// 285 bytes of a gzipped FileDescriptorProto
	0x1f, 0x8b, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xff, 0x7c, 0x8e, 0xcd, 0x4a, 0xc4, 0x30,
	0x10, 0xc7, 0xb7, 0x7e, 0xac, 0x18, 0x15, 0xb4, 0x07, 0x91, 0x22, 0x55, 0xf6, 0xa2, 0x17, 0x13,
	0xa8, 0x57, 0x0f, 0xba, 0xd0, 0x83, 0xa0, 0xb0, 0xe8, 0x13, 0xf4, 0x23, 0xc6, 0x40, 0x33, 0x53,
	0x9a, 0x69, 0xc5, 0x37, 0xf1, 0x91, 0xf6, 0xe8, 0x13, 0x88, 0xd4, 0x17, 0x91, 0xa6, 0x11, 0x16,
	0x44, 0x6f, 0xf9, 0xe5, 0xff, 0x9b, 0xf9, 0x0f, 0xdb, 0x93, 0x1d, 0x59, 0xa3, 0x1a, 0x5e, 0x37,
	0x48, 0x18, 0xee, 0x7a, 0x74, 0x14, 0x1d, 0x2b, 0x44, 0x55, 0x49, 0x91, 0xd5, 0x5a, 0x64, 0x00,
	0x48, 0x19, 0x69, 0x04, 0x3b, 0xba, 0xd1, 0x99, 0xd2, 0xf4, 0xdc, 0xe6, 0xbc, 0x40, 0x23, 0x6a,
	0x09, 0x36, 0x83, 0x12, 0x85, 0x7d, 0x71, 0x76, 0x81, 0xc6, 0x20, 0x78, 0x31, 0xfd, 0x43, 0xec,
	0x24, 0xe8, 0x42, 0x8a, 0x96, 0x74, 0x65, 0x87, 0x29, 0x25, 0x61, 0xb5, 0x46, 0x68, 0x28, 0xaa,
	0xb6, 0x94, 0x3f, 0x7d, 0x17, 0x2b, 0x6b, 0x14, 0x2a, 0x14, 0xee, 0x3b, 0x6f, 0x9f, 0x1c, 0x39,
	0x70, 0x2f, 0xaf, 0xf3, 0x7f, 0xce, 0x73, 0x86, 0x15, 0xb2, 0x93, 0x40, 0x7e, 0xfd, 0x6c, 0x8b,
	0x6d, 0xa6, 0xa6, 0xa6, 0xd7, 0xd9, 0x15, 0xdb, 0x4e, 0x87, 0xe0, 0x4e, 0x5b, 0x0a, 0x05, 0x9b,
	0x3a, 0xb0, 0x47, 0xc1, 0xe9, 0xfa, 0xf9, 0x4e, 0x72, 0xc0, 0x0d, 0x82, 0x26, 0x6c, 0x34, 0x28,
	0xee, 0x92, 0xf9, 0xc6, 0xf2, 0xe3, 0x64, 0xf2, 0xe0, 0xb5, 0xe4, 0x9a, 0xb1, 0xb4, 0x23, 0x7b,
	0xaf, 0x9a, 0x9b, 0xc5, 0x6d, 0x98, 0x30, 0xf6, 0x28, 0xa1, 0x1c, 0xb3, 0xf0, 0xf0, 0xd7, 0xb0,
	0x1d, 0x4a, 0x22, 0xc6, 0xb3, 0x5a, 0xf3, 0xb1, 0x7d, 0x32, 0xdf, 0x5f, 0xf6, 0x71, 0xf0, 0xde,
	0xc7, 0xc1, 0x67, 0x1f, 0x07, 0x6f, 0x5f, 0xf1, 0x64, 0xb1, 0x96, 0x4f, 0xdd, 0x8d, 0x97, 0xdf,
	0x01, 0x00, 0x00, 0xff, 0xff, 0x23, 0x75, 0x60, 0xc3, 0xaf, 0x01, 0x00, 0x00,
}
