// Code generated by protoc-gen-gogo. DO NOT EDIT.
// source: event.proto

package halproto

import proto "github.com/gogo/protobuf/proto"
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

// events that HAL generates and app(s) can listen to
type EventId int32

const (
	EventId_EVENT_ID_NONE            EventId = 0
	EventId_EVENT_ID_PORT_STATE      EventId = 1
	EventId_EVENT_ID_LIF_ADD_UPDATE  EventId = 2
	EventId_EVENT_ID_MICRO_SEG_STATE EventId = 3
)

var EventId_name = map[int32]string{
	0: "EVENT_ID_NONE",
	1: "EVENT_ID_PORT_STATE",
	2: "EVENT_ID_LIF_ADD_UPDATE",
	3: "EVENT_ID_MICRO_SEG_STATE",
}
var EventId_value = map[string]int32{
	"EVENT_ID_NONE":            0,
	"EVENT_ID_PORT_STATE":      1,
	"EVENT_ID_LIF_ADD_UPDATE":  2,
	"EVENT_ID_MICRO_SEG_STATE": 3,
}

func (x EventId) String() string {
	return proto.EnumName(EventId_name, int32(x))
}
func (EventId) EnumDescriptor() ([]byte, []int) { return fileDescriptorEvent, []int{0} }

type EventOp int32

const (
	EventOp_EVENT_OP_NONE        EventOp = 0
	EventOp_EVENT_OP_SUBSCRIBE   EventOp = 1
	EventOp_EVENT_OP_UNSUBSCRIBE EventOp = 2
)

var EventOp_name = map[int32]string{
	0: "EVENT_OP_NONE",
	1: "EVENT_OP_SUBSCRIBE",
	2: "EVENT_OP_UNSUBSCRIBE",
}
var EventOp_value = map[string]int32{
	"EVENT_OP_NONE":        0,
	"EVENT_OP_SUBSCRIBE":   1,
	"EVENT_OP_UNSUBSCRIBE": 2,
}

func (x EventOp) String() string {
	return proto.EnumName(EventOp_name, int32(x))
}
func (EventOp) EnumDescriptor() ([]byte, []int) { return fileDescriptorEvent, []int{1} }

// EventSpec captures the event of interest to the app
type EventRequest struct {
	EventId        EventId `protobuf:"varint,1,opt,name=event_id,json=eventId,proto3,enum=event.EventId" json:"event_id,omitempty"`
	EventOperation EventOp `protobuf:"varint,2,opt,name=event_operation,json=eventOperation,proto3,enum=event.EventOp" json:"event_operation,omitempty"`
}

func (m *EventRequest) Reset()                    { *m = EventRequest{} }
func (m *EventRequest) String() string            { return proto.CompactTextString(m) }
func (*EventRequest) ProtoMessage()               {}
func (*EventRequest) Descriptor() ([]byte, []int) { return fileDescriptorEvent, []int{0} }

func (m *EventRequest) GetEventId() EventId {
	if m != nil {
		return m.EventId
	}
	return EventId_EVENT_ID_NONE
}

func (m *EventRequest) GetEventOperation() EventOp {
	if m != nil {
		return m.EventOperation
	}
	return EventOp_EVENT_OP_NONE
}

type EventResponse struct {
	ApiStatus ApiStatus `protobuf:"varint,1,opt,name=api_status,json=apiStatus,proto3,enum=types.ApiStatus" json:"api_status,omitempty"`
	EventId   EventId   `protobuf:"varint,2,opt,name=event_id,json=eventId,proto3,enum=event.EventId" json:"event_id,omitempty"`
	// Types that are valid to be assigned to EventInfo:
	//	*EventResponse_LifEvent
	//	*EventResponse_PortEvent
	//	*EventResponse_MicroSegEvent
	EventInfo isEventResponse_EventInfo `protobuf_oneof:"event_info"`
}

func (m *EventResponse) Reset()                    { *m = EventResponse{} }
func (m *EventResponse) String() string            { return proto.CompactTextString(m) }
func (*EventResponse) ProtoMessage()               {}
func (*EventResponse) Descriptor() ([]byte, []int) { return fileDescriptorEvent, []int{1} }

type isEventResponse_EventInfo interface {
	isEventResponse_EventInfo()
	MarshalTo([]byte) (int, error)
	Size() int
}

type EventResponse_LifEvent struct {
	LifEvent *LifGetResponse `protobuf:"bytes,3,opt,name=lif_event,json=lifEvent,oneof"`
}
type EventResponse_PortEvent struct {
	PortEvent *PortResponse `protobuf:"bytes,4,opt,name=port_event,json=portEvent,oneof"`
}
type EventResponse_MicroSegEvent struct {
	MicroSegEvent *MicroSegEvent `protobuf:"bytes,5,opt,name=micro_seg_event,json=microSegEvent,oneof"`
}

func (*EventResponse_LifEvent) isEventResponse_EventInfo()      {}
func (*EventResponse_PortEvent) isEventResponse_EventInfo()     {}
func (*EventResponse_MicroSegEvent) isEventResponse_EventInfo() {}

func (m *EventResponse) GetEventInfo() isEventResponse_EventInfo {
	if m != nil {
		return m.EventInfo
	}
	return nil
}

func (m *EventResponse) GetApiStatus() ApiStatus {
	if m != nil {
		return m.ApiStatus
	}
	return ApiStatus_API_STATUS_OK
}

func (m *EventResponse) GetEventId() EventId {
	if m != nil {
		return m.EventId
	}
	return EventId_EVENT_ID_NONE
}

func (m *EventResponse) GetLifEvent() *LifGetResponse {
	if x, ok := m.GetEventInfo().(*EventResponse_LifEvent); ok {
		return x.LifEvent
	}
	return nil
}

func (m *EventResponse) GetPortEvent() *PortResponse {
	if x, ok := m.GetEventInfo().(*EventResponse_PortEvent); ok {
		return x.PortEvent
	}
	return nil
}

func (m *EventResponse) GetMicroSegEvent() *MicroSegEvent {
	if x, ok := m.GetEventInfo().(*EventResponse_MicroSegEvent); ok {
		return x.MicroSegEvent
	}
	return nil
}

// XXX_OneofFuncs is for the internal use of the proto package.
func (*EventResponse) XXX_OneofFuncs() (func(msg proto.Message, b *proto.Buffer) error, func(msg proto.Message, tag, wire int, b *proto.Buffer) (bool, error), func(msg proto.Message) (n int), []interface{}) {
	return _EventResponse_OneofMarshaler, _EventResponse_OneofUnmarshaler, _EventResponse_OneofSizer, []interface{}{
		(*EventResponse_LifEvent)(nil),
		(*EventResponse_PortEvent)(nil),
		(*EventResponse_MicroSegEvent)(nil),
	}
}

func _EventResponse_OneofMarshaler(msg proto.Message, b *proto.Buffer) error {
	m := msg.(*EventResponse)
	// event_info
	switch x := m.EventInfo.(type) {
	case *EventResponse_LifEvent:
		_ = b.EncodeVarint(3<<3 | proto.WireBytes)
		if err := b.EncodeMessage(x.LifEvent); err != nil {
			return err
		}
	case *EventResponse_PortEvent:
		_ = b.EncodeVarint(4<<3 | proto.WireBytes)
		if err := b.EncodeMessage(x.PortEvent); err != nil {
			return err
		}
	case *EventResponse_MicroSegEvent:
		_ = b.EncodeVarint(5<<3 | proto.WireBytes)
		if err := b.EncodeMessage(x.MicroSegEvent); err != nil {
			return err
		}
	case nil:
	default:
		return fmt.Errorf("EventResponse.EventInfo has unexpected type %T", x)
	}
	return nil
}

func _EventResponse_OneofUnmarshaler(msg proto.Message, tag, wire int, b *proto.Buffer) (bool, error) {
	m := msg.(*EventResponse)
	switch tag {
	case 3: // event_info.lif_event
		if wire != proto.WireBytes {
			return true, proto.ErrInternalBadWireType
		}
		msg := new(LifGetResponse)
		err := b.DecodeMessage(msg)
		m.EventInfo = &EventResponse_LifEvent{msg}
		return true, err
	case 4: // event_info.port_event
		if wire != proto.WireBytes {
			return true, proto.ErrInternalBadWireType
		}
		msg := new(PortResponse)
		err := b.DecodeMessage(msg)
		m.EventInfo = &EventResponse_PortEvent{msg}
		return true, err
	case 5: // event_info.micro_seg_event
		if wire != proto.WireBytes {
			return true, proto.ErrInternalBadWireType
		}
		msg := new(MicroSegEvent)
		err := b.DecodeMessage(msg)
		m.EventInfo = &EventResponse_MicroSegEvent{msg}
		return true, err
	default:
		return false, nil
	}
}

func _EventResponse_OneofSizer(msg proto.Message) (n int) {
	m := msg.(*EventResponse)
	// event_info
	switch x := m.EventInfo.(type) {
	case *EventResponse_LifEvent:
		s := proto.Size(x.LifEvent)
		n += proto.SizeVarint(3<<3 | proto.WireBytes)
		n += proto.SizeVarint(uint64(s))
		n += s
	case *EventResponse_PortEvent:
		s := proto.Size(x.PortEvent)
		n += proto.SizeVarint(4<<3 | proto.WireBytes)
		n += proto.SizeVarint(uint64(s))
		n += s
	case *EventResponse_MicroSegEvent:
		s := proto.Size(x.MicroSegEvent)
		n += proto.SizeVarint(5<<3 | proto.WireBytes)
		n += proto.SizeVarint(uint64(s))
		n += s
	case nil:
	default:
		panic(fmt.Sprintf("proto: unexpected type %T in oneof", x))
	}
	return n
}

func init() {
	proto.RegisterType((*EventRequest)(nil), "event.EventRequest")
	proto.RegisterType((*EventResponse)(nil), "event.EventResponse")
	proto.RegisterEnum("event.EventId", EventId_name, EventId_value)
	proto.RegisterEnum("event.EventOp", EventOp_name, EventOp_value)
}

// Reference imports to suppress errors if they are not otherwise used.
var _ context.Context
var _ grpc.ClientConn

// This is a compile-time assertion to ensure that this generated file
// is compatible with the grpc package it is being compiled against.
const _ = grpc.SupportPackageIsVersion4

// Client API for Event service

type EventClient interface {
	// TODO: rename this API - with bidir streaming, this name doesn't make sense
	EventListen(ctx context.Context, in *EventRequest, opts ...grpc.CallOption) (Event_EventListenClient, error)
}

type eventClient struct {
	cc *grpc.ClientConn
}

func NewEventClient(cc *grpc.ClientConn) EventClient {
	return &eventClient{cc}
}

func (c *eventClient) EventListen(ctx context.Context, in *EventRequest, opts ...grpc.CallOption) (Event_EventListenClient, error) {
	stream, err := grpc.NewClientStream(ctx, &_Event_serviceDesc.Streams[0], c.cc, "/event.Event/EventListen", opts...)
	if err != nil {
		return nil, err
	}
	x := &eventEventListenClient{stream}
	if err := x.ClientStream.SendMsg(in); err != nil {
		return nil, err
	}
	if err := x.ClientStream.CloseSend(); err != nil {
		return nil, err
	}
	return x, nil
}

type Event_EventListenClient interface {
	Recv() (*EventResponse, error)
	grpc.ClientStream
}

type eventEventListenClient struct {
	grpc.ClientStream
}

func (x *eventEventListenClient) Recv() (*EventResponse, error) {
	m := new(EventResponse)
	if err := x.ClientStream.RecvMsg(m); err != nil {
		return nil, err
	}
	return m, nil
}

// Server API for Event service

type EventServer interface {
	// TODO: rename this API - with bidir streaming, this name doesn't make sense
	EventListen(*EventRequest, Event_EventListenServer) error
}

func RegisterEventServer(s *grpc.Server, srv EventServer) {
	s.RegisterService(&_Event_serviceDesc, srv)
}

func _Event_EventListen_Handler(srv interface{}, stream grpc.ServerStream) error {
	m := new(EventRequest)
	if err := stream.RecvMsg(m); err != nil {
		return err
	}
	return srv.(EventServer).EventListen(m, &eventEventListenServer{stream})
}

type Event_EventListenServer interface {
	Send(*EventResponse) error
	grpc.ServerStream
}

type eventEventListenServer struct {
	grpc.ServerStream
}

func (x *eventEventListenServer) Send(m *EventResponse) error {
	return x.ServerStream.SendMsg(m)
}

var _Event_serviceDesc = grpc.ServiceDesc{
	ServiceName: "event.Event",
	HandlerType: (*EventServer)(nil),
	Methods:     []grpc.MethodDesc{},
	Streams: []grpc.StreamDesc{
		{
			StreamName:    "EventListen",
			Handler:       _Event_EventListen_Handler,
			ServerStreams: true,
		},
	},
	Metadata: "event.proto",
}

func (m *EventRequest) Marshal() (dAtA []byte, err error) {
	size := m.Size()
	dAtA = make([]byte, size)
	n, err := m.MarshalTo(dAtA)
	if err != nil {
		return nil, err
	}
	return dAtA[:n], nil
}

func (m *EventRequest) MarshalTo(dAtA []byte) (int, error) {
	var i int
	_ = i
	var l int
	_ = l
	if m.EventId != 0 {
		dAtA[i] = 0x8
		i++
		i = encodeVarintEvent(dAtA, i, uint64(m.EventId))
	}
	if m.EventOperation != 0 {
		dAtA[i] = 0x10
		i++
		i = encodeVarintEvent(dAtA, i, uint64(m.EventOperation))
	}
	return i, nil
}

func (m *EventResponse) Marshal() (dAtA []byte, err error) {
	size := m.Size()
	dAtA = make([]byte, size)
	n, err := m.MarshalTo(dAtA)
	if err != nil {
		return nil, err
	}
	return dAtA[:n], nil
}

func (m *EventResponse) MarshalTo(dAtA []byte) (int, error) {
	var i int
	_ = i
	var l int
	_ = l
	if m.ApiStatus != 0 {
		dAtA[i] = 0x8
		i++
		i = encodeVarintEvent(dAtA, i, uint64(m.ApiStatus))
	}
	if m.EventId != 0 {
		dAtA[i] = 0x10
		i++
		i = encodeVarintEvent(dAtA, i, uint64(m.EventId))
	}
	if m.EventInfo != nil {
		nn1, err := m.EventInfo.MarshalTo(dAtA[i:])
		if err != nil {
			return 0, err
		}
		i += nn1
	}
	return i, nil
}

func (m *EventResponse_LifEvent) MarshalTo(dAtA []byte) (int, error) {
	i := 0
	if m.LifEvent != nil {
		dAtA[i] = 0x1a
		i++
		i = encodeVarintEvent(dAtA, i, uint64(m.LifEvent.Size()))
		n2, err := m.LifEvent.MarshalTo(dAtA[i:])
		if err != nil {
			return 0, err
		}
		i += n2
	}
	return i, nil
}
func (m *EventResponse_PortEvent) MarshalTo(dAtA []byte) (int, error) {
	i := 0
	if m.PortEvent != nil {
		dAtA[i] = 0x22
		i++
		i = encodeVarintEvent(dAtA, i, uint64(m.PortEvent.Size()))
		n3, err := m.PortEvent.MarshalTo(dAtA[i:])
		if err != nil {
			return 0, err
		}
		i += n3
	}
	return i, nil
}
func (m *EventResponse_MicroSegEvent) MarshalTo(dAtA []byte) (int, error) {
	i := 0
	if m.MicroSegEvent != nil {
		dAtA[i] = 0x2a
		i++
		i = encodeVarintEvent(dAtA, i, uint64(m.MicroSegEvent.Size()))
		n4, err := m.MicroSegEvent.MarshalTo(dAtA[i:])
		if err != nil {
			return 0, err
		}
		i += n4
	}
	return i, nil
}
func encodeVarintEvent(dAtA []byte, offset int, v uint64) int {
	for v >= 1<<7 {
		dAtA[offset] = uint8(v&0x7f | 0x80)
		v >>= 7
		offset++
	}
	dAtA[offset] = uint8(v)
	return offset + 1
}
func (m *EventRequest) Size() (n int) {
	var l int
	_ = l
	if m.EventId != 0 {
		n += 1 + sovEvent(uint64(m.EventId))
	}
	if m.EventOperation != 0 {
		n += 1 + sovEvent(uint64(m.EventOperation))
	}
	return n
}

func (m *EventResponse) Size() (n int) {
	var l int
	_ = l
	if m.ApiStatus != 0 {
		n += 1 + sovEvent(uint64(m.ApiStatus))
	}
	if m.EventId != 0 {
		n += 1 + sovEvent(uint64(m.EventId))
	}
	if m.EventInfo != nil {
		n += m.EventInfo.Size()
	}
	return n
}

func (m *EventResponse_LifEvent) Size() (n int) {
	var l int
	_ = l
	if m.LifEvent != nil {
		l = m.LifEvent.Size()
		n += 1 + l + sovEvent(uint64(l))
	}
	return n
}
func (m *EventResponse_PortEvent) Size() (n int) {
	var l int
	_ = l
	if m.PortEvent != nil {
		l = m.PortEvent.Size()
		n += 1 + l + sovEvent(uint64(l))
	}
	return n
}
func (m *EventResponse_MicroSegEvent) Size() (n int) {
	var l int
	_ = l
	if m.MicroSegEvent != nil {
		l = m.MicroSegEvent.Size()
		n += 1 + l + sovEvent(uint64(l))
	}
	return n
}

func sovEvent(x uint64) (n int) {
	for {
		n++
		x >>= 7
		if x == 0 {
			break
		}
	}
	return n
}
func sozEvent(x uint64) (n int) {
	return sovEvent(uint64((x << 1) ^ uint64((int64(x) >> 63))))
}
func (m *EventRequest) Unmarshal(dAtA []byte) error {
	l := len(dAtA)
	iNdEx := 0
	for iNdEx < l {
		preIndex := iNdEx
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return ErrIntOverflowEvent
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
			return fmt.Errorf("proto: EventRequest: wiretype end group for non-group")
		}
		if fieldNum <= 0 {
			return fmt.Errorf("proto: EventRequest: illegal tag %d (wire type %d)", fieldNum, wire)
		}
		switch fieldNum {
		case 1:
			if wireType != 0 {
				return fmt.Errorf("proto: wrong wireType = %d for field EventId", wireType)
			}
			m.EventId = 0
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowEvent
				}
				if iNdEx >= l {
					return io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				m.EventId |= (EventId(b) & 0x7F) << shift
				if b < 0x80 {
					break
				}
			}
		case 2:
			if wireType != 0 {
				return fmt.Errorf("proto: wrong wireType = %d for field EventOperation", wireType)
			}
			m.EventOperation = 0
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowEvent
				}
				if iNdEx >= l {
					return io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				m.EventOperation |= (EventOp(b) & 0x7F) << shift
				if b < 0x80 {
					break
				}
			}
		default:
			iNdEx = preIndex
			skippy, err := skipEvent(dAtA[iNdEx:])
			if err != nil {
				return err
			}
			if skippy < 0 {
				return ErrInvalidLengthEvent
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
func (m *EventResponse) Unmarshal(dAtA []byte) error {
	l := len(dAtA)
	iNdEx := 0
	for iNdEx < l {
		preIndex := iNdEx
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return ErrIntOverflowEvent
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
			return fmt.Errorf("proto: EventResponse: wiretype end group for non-group")
		}
		if fieldNum <= 0 {
			return fmt.Errorf("proto: EventResponse: illegal tag %d (wire type %d)", fieldNum, wire)
		}
		switch fieldNum {
		case 1:
			if wireType != 0 {
				return fmt.Errorf("proto: wrong wireType = %d for field ApiStatus", wireType)
			}
			m.ApiStatus = 0
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowEvent
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
			if wireType != 0 {
				return fmt.Errorf("proto: wrong wireType = %d for field EventId", wireType)
			}
			m.EventId = 0
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowEvent
				}
				if iNdEx >= l {
					return io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				m.EventId |= (EventId(b) & 0x7F) << shift
				if b < 0x80 {
					break
				}
			}
		case 3:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field LifEvent", wireType)
			}
			var msglen int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowEvent
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
				return ErrInvalidLengthEvent
			}
			postIndex := iNdEx + msglen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			v := &LifGetResponse{}
			if err := v.Unmarshal(dAtA[iNdEx:postIndex]); err != nil {
				return err
			}
			m.EventInfo = &EventResponse_LifEvent{v}
			iNdEx = postIndex
		case 4:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field PortEvent", wireType)
			}
			var msglen int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowEvent
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
				return ErrInvalidLengthEvent
			}
			postIndex := iNdEx + msglen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			v := &PortResponse{}
			if err := v.Unmarshal(dAtA[iNdEx:postIndex]); err != nil {
				return err
			}
			m.EventInfo = &EventResponse_PortEvent{v}
			iNdEx = postIndex
		case 5:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field MicroSegEvent", wireType)
			}
			var msglen int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowEvent
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
				return ErrInvalidLengthEvent
			}
			postIndex := iNdEx + msglen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			v := &MicroSegEvent{}
			if err := v.Unmarshal(dAtA[iNdEx:postIndex]); err != nil {
				return err
			}
			m.EventInfo = &EventResponse_MicroSegEvent{v}
			iNdEx = postIndex
		default:
			iNdEx = preIndex
			skippy, err := skipEvent(dAtA[iNdEx:])
			if err != nil {
				return err
			}
			if skippy < 0 {
				return ErrInvalidLengthEvent
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
func skipEvent(dAtA []byte) (n int, err error) {
	l := len(dAtA)
	iNdEx := 0
	for iNdEx < l {
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return 0, ErrIntOverflowEvent
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
					return 0, ErrIntOverflowEvent
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
					return 0, ErrIntOverflowEvent
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
				return 0, ErrInvalidLengthEvent
			}
			return iNdEx, nil
		case 3:
			for {
				var innerWire uint64
				var start int = iNdEx
				for shift := uint(0); ; shift += 7 {
					if shift >= 64 {
						return 0, ErrIntOverflowEvent
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
				next, err := skipEvent(dAtA[start:])
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
	ErrInvalidLengthEvent = fmt.Errorf("proto: negative length found during unmarshaling")
	ErrIntOverflowEvent   = fmt.Errorf("proto: integer overflow")
)

func init() { proto.RegisterFile("event.proto", fileDescriptorEvent) }

var fileDescriptorEvent = []byte{
	// 461 bytes of a gzipped FileDescriptorProto
	0x1f, 0x8b, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xff, 0x7c, 0x92, 0xcf, 0x6e, 0xd3, 0x40,
	0x10, 0xc6, 0x63, 0x97, 0xd0, 0x64, 0xf2, 0x97, 0x6d, 0xd4, 0x5a, 0x01, 0x45, 0x55, 0x4e, 0xa5,
	0x07, 0x83, 0x92, 0x03, 0x17, 0x2e, 0x49, 0x63, 0x5a, 0x4b, 0xa9, 0x1d, 0xd9, 0x09, 0x07, 0x2e,
	0x2b, 0xd3, 0xae, 0xcb, 0x4a, 0x89, 0x77, 0xf1, 0x6e, 0x91, 0xf2, 0x38, 0xbc, 0x0d, 0x47, 0x1e,
	0x01, 0xe5, 0x49, 0x90, 0x77, 0x37, 0x6e, 0x2a, 0x24, 0x4e, 0x9e, 0xfd, 0x66, 0x7e, 0xfb, 0xcd,
	0x8c, 0x17, 0x1a, 0xe4, 0x07, 0xc9, 0xa4, 0xcb, 0x73, 0x26, 0x19, 0xaa, 0xaa, 0x43, 0xbf, 0x21,
	0xb7, 0x9c, 0x08, 0xad, 0xf5, 0x3b, 0x34, 0x93, 0x24, 0x4f, 0x93, 0x3b, 0x62, 0x04, 0xe0, 0x2c,
	0x37, 0x40, 0xbf, 0x29, 0xb6, 0x42, 0x92, 0x8d, 0x3e, 0x0d, 0x73, 0x68, 0x7a, 0xc5, 0x05, 0x11,
	0xf9, 0xfe, 0x48, 0x84, 0x44, 0x6f, 0xa1, 0xa6, 0x2e, 0xc4, 0xf4, 0xde, 0xb1, 0xce, 0xad, 0x8b,
	0xf6, 0xa8, 0xed, 0x6a, 0x3b, 0x55, 0xe6, 0xdf, 0x47, 0xc7, 0x44, 0x07, 0xe8, 0x03, 0x74, 0x74,
	0x29, 0xe3, 0x24, 0x4f, 0x24, 0x65, 0x99, 0x63, 0xff, 0x4b, 0x84, 0x3c, 0x6a, 0x13, 0x1d, 0x98,
	0xaa, 0xe1, 0x4f, 0x1b, 0x5a, 0xc6, 0x54, 0x70, 0x96, 0x09, 0x82, 0xde, 0x01, 0x24, 0x9c, 0x62,
	0x21, 0x13, 0xf9, 0x28, 0x8c, 0x6f, 0xd7, 0xd5, 0x23, 0x4d, 0x38, 0x8d, 0x95, 0x1e, 0xd5, 0x93,
	0x7d, 0xf8, 0xac, 0x4d, 0xfb, 0xff, 0x6d, 0x8e, 0xa1, 0xbe, 0xa6, 0x29, 0x56, 0x47, 0xe7, 0xe8,
	0xdc, 0xba, 0x68, 0x8c, 0x7a, 0x2e, 0xcd, 0x64, 0xea, 0xce, 0x69, 0x7a, 0x4d, 0xca, 0x26, 0x6e,
	0x2a, 0x51, 0x6d, 0x4d, 0x53, 0xc5, 0xa3, 0x31, 0xa8, 0x95, 0x19, 0xea, 0x85, 0xa2, 0x90, 0xab,
	0xb6, 0xb8, 0x60, 0xf9, 0x21, 0x53, 0x2f, 0x44, 0x0d, 0x7d, 0x84, 0xce, 0x86, 0xde, 0xe5, 0x0c,
	0x0b, 0xf2, 0x60, 0xc8, 0xaa, 0x21, 0xc5, 0x56, 0xb8, 0xb7, 0x45, 0x2e, 0x26, 0x0f, 0xaa, 0xf8,
	0xa6, 0x12, 0xb5, 0x36, 0x87, 0xc2, 0xb4, 0x09, 0x60, 0x46, 0xca, 0x52, 0x76, 0xc9, 0xe1, 0xd8,
	0x4c, 0x82, 0x5e, 0x41, 0xcb, 0xfb, 0xec, 0x05, 0x4b, 0xec, 0xcf, 0x70, 0x10, 0x06, 0x5e, 0xb7,
	0x82, 0xce, 0xe0, 0xa4, 0x94, 0x16, 0x61, 0xb4, 0xc4, 0xf1, 0x72, 0xb2, 0xf4, 0xba, 0x16, 0x7a,
	0x0d, 0x67, 0x65, 0x62, 0xee, 0x7f, 0xc2, 0x93, 0xd9, 0x0c, 0xaf, 0x16, 0xb3, 0x22, 0x69, 0xa3,
	0x37, 0xe0, 0x94, 0xc9, 0x5b, 0xff, 0x2a, 0x0a, 0x71, 0xec, 0x5d, 0x1b, 0xf4, 0xe8, 0x32, 0x30,
	0x8e, 0x21, 0x7f, 0x72, 0x0c, 0x17, 0x7b, 0xc7, 0x53, 0x40, 0xa5, 0x14, 0xaf, 0xa6, 0xf1, 0x55,
	0xe4, 0x4f, 0x0b, 0x43, 0x07, 0x7a, 0xa5, 0xbe, 0x0a, 0x9e, 0x32, 0xf6, 0xc8, 0x83, 0xea, 0x7e,
	0x2d, 0x0d, 0x15, 0xcc, 0xa9, 0x90, 0x24, 0x43, 0x27, 0x87, 0x3f, 0xca, 0x3c, 0xbb, 0x7e, 0xef,
	0xb9, 0xa8, 0xb7, 0x3b, 0xac, 0xbc, 0xb7, 0xa6, 0xa7, 0xbf, 0x76, 0x03, 0xeb, 0xf7, 0x6e, 0x60,
	0xfd, 0xd9, 0x0d, 0xac, 0x2f, 0xb5, 0x6f, 0xc9, 0x5a, 0x3d, 0xdc, 0xaf, 0x2f, 0xd5, 0x67, 0xfc,
	0x37, 0x00, 0x00, 0xff, 0xff, 0xc7, 0x85, 0x20, 0x0c, 0x0d, 0x03, 0x00, 0x00,
}
