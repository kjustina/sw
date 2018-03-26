// Code generated by protoc-gen-gogo. DO NOT EDIT.
// source: evtsproxy.proto

/*
	Package evtsproxyproto is a generated protocol buffer package.

	It is generated from these files:
		evtsproxy.proto

	It has these top-level messages:
*/
package evtsproxyproto

import proto "github.com/gogo/protobuf/proto"
import fmt "fmt"
import math "math"
import _ "google.golang.org/genproto/googleapis/api/annotations"
import _ "github.com/pensando/sw/venice/utils/apigen/annotations"
import _ "github.com/gogo/protobuf/gogoproto"
import events "github.com/pensando/sw/api/generated/events"
import api2 "github.com/pensando/sw/api"
import evtsmgrproto "github.com/pensando/sw/venice/ctrler/evtsmgr/rpcserver/evtsmgrproto"

import (
	context "golang.org/x/net/context"
	grpc "google.golang.org/grpc"
)

// Reference imports to suppress errors if they are not otherwise used.
var _ = proto.Marshal
var _ = fmt.Errorf
var _ = math.Inf

// This is a compile-time assertion to ensure that this generated file
// is compatible with the proto package it is being compiled against.
// A compilation error at this line likely means your copy of the
// proto package needs to be updated.
const _ = proto.GoGoProtoPackageIsVersion2 // please upgrade the proto package

// Reference imports to suppress errors if they are not otherwise used.
var _ context.Context
var _ grpc.ClientConn

// This is a compile-time assertion to ensure that this generated file
// is compatible with the grpc package it is being compiled against.
const _ = grpc.SupportPackageIsVersion4

// Client API for EventsProxyAPI service

type EventsProxyAPIClient interface {
	// recorder will forward the event to proxy which will be channeled to the
	// dispatcher where the event gets deduped and distributed to the writers
	// (events manager, events exporter, etc.). event recorder connects only
	// with proxy; proxy handles rest of the workflow.
	ForwardEvent(ctx context.Context, in *events.Event, opts ...grpc.CallOption) (*api2.Empty, error)
	// recorder can buffer events when the proxy is unavailable and send
	// all of them at once when the proxy comes back online.
	ForwardEvents(ctx context.Context, in *evtsmgrproto.EventList, opts ...grpc.CallOption) (*api2.Empty, error)
	// event sources can call flush using the recorder to flush the pending/deduped
	// events from dispatcher to all the writers. This flushes only the events
	// belonging to the given source.
	Flush(ctx context.Context, in *events.EventSource, opts ...grpc.CallOption) (*api2.Empty, error)
}

type eventsProxyAPIClient struct {
	cc *grpc.ClientConn
}

func NewEventsProxyAPIClient(cc *grpc.ClientConn) EventsProxyAPIClient {
	return &eventsProxyAPIClient{cc}
}

func (c *eventsProxyAPIClient) ForwardEvent(ctx context.Context, in *events.Event, opts ...grpc.CallOption) (*api2.Empty, error) {
	out := new(api2.Empty)
	err := grpc.Invoke(ctx, "/evtsproxyproto.EventsProxyAPI/ForwardEvent", in, out, c.cc, opts...)
	if err != nil {
		return nil, err
	}
	return out, nil
}

func (c *eventsProxyAPIClient) ForwardEvents(ctx context.Context, in *evtsmgrproto.EventList, opts ...grpc.CallOption) (*api2.Empty, error) {
	out := new(api2.Empty)
	err := grpc.Invoke(ctx, "/evtsproxyproto.EventsProxyAPI/ForwardEvents", in, out, c.cc, opts...)
	if err != nil {
		return nil, err
	}
	return out, nil
}

func (c *eventsProxyAPIClient) Flush(ctx context.Context, in *events.EventSource, opts ...grpc.CallOption) (*api2.Empty, error) {
	out := new(api2.Empty)
	err := grpc.Invoke(ctx, "/evtsproxyproto.EventsProxyAPI/Flush", in, out, c.cc, opts...)
	if err != nil {
		return nil, err
	}
	return out, nil
}

// Server API for EventsProxyAPI service

type EventsProxyAPIServer interface {
	// recorder will forward the event to proxy which will be channeled to the
	// dispatcher where the event gets deduped and distributed to the writers
	// (events manager, events exporter, etc.). event recorder connects only
	// with proxy; proxy handles rest of the workflow.
	ForwardEvent(context.Context, *events.Event) (*api2.Empty, error)
	// recorder can buffer events when the proxy is unavailable and send
	// all of them at once when the proxy comes back online.
	ForwardEvents(context.Context, *evtsmgrproto.EventList) (*api2.Empty, error)
	// event sources can call flush using the recorder to flush the pending/deduped
	// events from dispatcher to all the writers. This flushes only the events
	// belonging to the given source.
	Flush(context.Context, *events.EventSource) (*api2.Empty, error)
}

func RegisterEventsProxyAPIServer(s *grpc.Server, srv EventsProxyAPIServer) {
	s.RegisterService(&_EventsProxyAPI_serviceDesc, srv)
}

func _EventsProxyAPI_ForwardEvent_Handler(srv interface{}, ctx context.Context, dec func(interface{}) error, interceptor grpc.UnaryServerInterceptor) (interface{}, error) {
	in := new(events.Event)
	if err := dec(in); err != nil {
		return nil, err
	}
	if interceptor == nil {
		return srv.(EventsProxyAPIServer).ForwardEvent(ctx, in)
	}
	info := &grpc.UnaryServerInfo{
		Server:     srv,
		FullMethod: "/evtsproxyproto.EventsProxyAPI/ForwardEvent",
	}
	handler := func(ctx context.Context, req interface{}) (interface{}, error) {
		return srv.(EventsProxyAPIServer).ForwardEvent(ctx, req.(*events.Event))
	}
	return interceptor(ctx, in, info, handler)
}

func _EventsProxyAPI_ForwardEvents_Handler(srv interface{}, ctx context.Context, dec func(interface{}) error, interceptor grpc.UnaryServerInterceptor) (interface{}, error) {
	in := new(evtsmgrproto.EventList)
	if err := dec(in); err != nil {
		return nil, err
	}
	if interceptor == nil {
		return srv.(EventsProxyAPIServer).ForwardEvents(ctx, in)
	}
	info := &grpc.UnaryServerInfo{
		Server:     srv,
		FullMethod: "/evtsproxyproto.EventsProxyAPI/ForwardEvents",
	}
	handler := func(ctx context.Context, req interface{}) (interface{}, error) {
		return srv.(EventsProxyAPIServer).ForwardEvents(ctx, req.(*evtsmgrproto.EventList))
	}
	return interceptor(ctx, in, info, handler)
}

func _EventsProxyAPI_Flush_Handler(srv interface{}, ctx context.Context, dec func(interface{}) error, interceptor grpc.UnaryServerInterceptor) (interface{}, error) {
	in := new(events.EventSource)
	if err := dec(in); err != nil {
		return nil, err
	}
	if interceptor == nil {
		return srv.(EventsProxyAPIServer).Flush(ctx, in)
	}
	info := &grpc.UnaryServerInfo{
		Server:     srv,
		FullMethod: "/evtsproxyproto.EventsProxyAPI/Flush",
	}
	handler := func(ctx context.Context, req interface{}) (interface{}, error) {
		return srv.(EventsProxyAPIServer).Flush(ctx, req.(*events.EventSource))
	}
	return interceptor(ctx, in, info, handler)
}

var _EventsProxyAPI_serviceDesc = grpc.ServiceDesc{
	ServiceName: "evtsproxyproto.EventsProxyAPI",
	HandlerType: (*EventsProxyAPIServer)(nil),
	Methods: []grpc.MethodDesc{
		{
			MethodName: "ForwardEvent",
			Handler:    _EventsProxyAPI_ForwardEvent_Handler,
		},
		{
			MethodName: "ForwardEvents",
			Handler:    _EventsProxyAPI_ForwardEvents_Handler,
		},
		{
			MethodName: "Flush",
			Handler:    _EventsProxyAPI_Flush_Handler,
		},
	},
	Streams:  []grpc.StreamDesc{},
	Metadata: "evtsproxy.proto",
}

func init() { proto.RegisterFile("evtsproxy.proto", fileDescriptorEvtsproxy) }

var fileDescriptorEvtsproxy = []byte{
	// 309 bytes of a gzipped FileDescriptorProto
	0x1f, 0x8b, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xff, 0x7c, 0x90, 0xcf, 0x4a, 0x33, 0x31,
	0x14, 0xc5, 0x3b, 0x8b, 0xef, 0x5b, 0x04, 0x5b, 0x25, 0x2e, 0x84, 0x22, 0xb3, 0x70, 0x23, 0x28,
	0x26, 0xa0, 0xe0, 0x5e, 0xa1, 0x05, 0xc1, 0x45, 0xc5, 0x27, 0x48, 0xd3, 0x6b, 0x1a, 0x98, 0xc9,
	0x0d, 0xf9, 0x33, 0xb5, 0x6f, 0xe2, 0xd6, 0xb7, 0x71, 0xe9, 0x23, 0xc8, 0xf8, 0x22, 0x32, 0x99,
	0xa9, 0x4e, 0x05, 0xbb, 0x9b, 0x73, 0xe7, 0x77, 0xce, 0x3d, 0xb9, 0x64, 0x1f, 0xaa, 0xe0, 0xad,
	0xc3, 0xe7, 0x35, 0xb3, 0x0e, 0x03, 0xd2, 0xd1, 0xf7, 0x20, 0xe9, 0xf1, 0xb1, 0x42, 0x54, 0x05,
	0x70, 0x61, 0x35, 0x17, 0xc6, 0x60, 0x10, 0x41, 0xa3, 0xf1, 0x2d, 0x3d, 0x9e, 0x28, 0x1d, 0x96,
	0x71, 0xce, 0x24, 0x96, 0xdc, 0x82, 0xf1, 0xc2, 0x2c, 0x90, 0xfb, 0x15, 0xaf, 0xc0, 0x68, 0x09,
	0x3c, 0x06, 0x5d, 0xf8, 0xc6, 0xaa, 0xc0, 0xf4, 0xdd, 0x5c, 0x1b, 0x59, 0xc4, 0x05, 0x6c, 0x62,
	0x2e, 0x7a, 0x31, 0x0a, 0x15, 0xf2, 0x34, 0x9e, 0xc7, 0xa7, 0xa4, 0x92, 0x48, 0x5f, 0x1d, 0xce,
	0xfe, 0xd8, 0xda, 0x74, 0x4c, 0x84, 0xe7, 0x50, 0x81, 0x09, 0x9b, 0xf8, 0xd3, 0x1d, 0xbc, 0xc4,
	0xb2, 0x44, 0xd3, 0x81, 0x0f, 0xbb, 0x9f, 0x23, 0x83, 0x2b, 0xc0, 0xf1, 0xe6, 0x42, 0xa5, 0x72,
	0xdc, 0x59, 0xe9, 0xc1, 0x55, 0x3f, 0x93, 0xb6, 0x68, 0x27, 0xda, 0xc8, 0xcb, 0xd7, 0x8c, 0x8c,
	0x26, 0xa9, 0xcc, 0xac, 0x39, 0xea, 0xcd, 0xec, 0x8e, 0x9e, 0x93, 0xbd, 0x29, 0xba, 0x95, 0x70,
	0x8b, 0xf4, 0x83, 0x0e, 0x59, 0xd7, 0x36, 0xc9, 0x31, 0x61, 0xc2, 0x6a, 0x36, 0x29, 0x6d, 0x58,
	0x9f, 0x0c, 0xe8, 0x35, 0x19, 0xf6, 0x61, 0x4f, 0x8f, 0x58, 0x7f, 0x5b, 0xeb, 0xb9, 0xd7, 0xfe,
	0xb7, 0xef, 0x8c, 0xfc, 0x9b, 0x16, 0xd1, 0x2f, 0xe9, 0xe1, 0x56, 0xfa, 0x23, 0x46, 0x27, 0x61,
	0x9b, 0xbd, 0x3d, 0x78, 0xab, 0xf3, 0xec, 0xbd, 0xce, 0xb3, 0x8f, 0x3a, 0xcf, 0x5e, 0x3e, 0xf3,
	0xc1, 0x2c, 0x9b, 0xff, 0x4f, 0xf1, 0x57, 0x5f, 0x01, 0x00, 0x00, 0xff, 0xff, 0x57, 0xe7, 0x6b,
	0xc4, 0x21, 0x02, 0x00, 0x00,
}
