// Code generated by protoc-gen-go. DO NOT EDIT.
// source: agent.proto

/*
Package agentproto is a generated protocol buffer package.

It is generated from these files:
	agent.proto

It has these top-level messages:
	PingMessage
	Entity
	NodeConfig
	NodeConfigStatus
	AppConfig
	AppStatus
	Interface
	InterfaceStatus
	Command
	CommandStatus
	NaplesSimConfig
	NaplesStatus
	HntapConfig
*/
package agentproto

import proto "github.com/golang/protobuf/proto"
import fmt "fmt"
import math "math"

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
const _ = proto.ProtoPackageIsVersion2 // please upgrade the proto package

type ApiStatus int32

const (
	ApiStatus_API_STATUS_OK            ApiStatus = 0
	ApiStatus_API_STATUS_FAILED        ApiStatus = 1
	ApiStatus_API_STATUS_APP_NOT_FOUND ApiStatus = 2
)

var ApiStatus_name = map[int32]string{
	0: "API_STATUS_OK",
	1: "API_STATUS_FAILED",
	2: "API_STATUS_APP_NOT_FOUND",
}
var ApiStatus_value = map[string]int32{
	"API_STATUS_OK":            0,
	"API_STATUS_FAILED":        1,
	"API_STATUS_APP_NOT_FOUND": 2,
}

func (x ApiStatus) String() string {
	return proto.EnumName(ApiStatus_name, int32(x))
}
func (ApiStatus) EnumDescriptor() ([]byte, []int) { return fileDescriptor0, []int{0} }

type EntityType int32

const (
	EntityType_EntityNone      EntityType = 0
	EntityType_EntityNaples    EntityType = 1
	EntityType_EntityContainer EntityType = 2
	EntityType_EntityApp       EntityType = 3
	EntityType_EntitySwitch    EntityType = 4
	EntityType_EntityVM        EntityType = 5
)

var EntityType_name = map[int32]string{
	0: "EntityNone",
	1: "EntityNaples",
	2: "EntityContainer",
	3: "EntityApp",
	4: "EntitySwitch",
	5: "EntityVM",
}
var EntityType_value = map[string]int32{
	"EntityNone":      0,
	"EntityNaples":    1,
	"EntityContainer": 2,
	"EntityApp":       3,
	"EntitySwitch":    4,
	"EntityVM":        5,
}

func (x EntityType) String() string {
	return proto.EnumName(EntityType_name, int32(x))
}
func (EntityType) EnumDescriptor() ([]byte, []int) { return fileDescriptor0, []int{1} }

type PingMessage struct {
	Message string `protobuf:"bytes,1,opt,name=message" json:"message,omitempty"`
}

func (m *PingMessage) Reset()                    { *m = PingMessage{} }
func (m *PingMessage) String() string            { return proto.CompactTextString(m) }
func (*PingMessage) ProtoMessage()               {}
func (*PingMessage) Descriptor() ([]byte, []int) { return fileDescriptor0, []int{0} }

func (m *PingMessage) GetMessage() string {
	if m != nil {
		return m.Message
	}
	return ""
}

type Entity struct {
	Name string     `protobuf:"bytes,1,opt,name=name" json:"name,omitempty"`
	Type EntityType `protobuf:"varint,2,opt,name=type,enum=agentproto.EntityType" json:"type,omitempty"`
}

func (m *Entity) Reset()                    { *m = Entity{} }
func (m *Entity) String() string            { return proto.CompactTextString(m) }
func (*Entity) ProtoMessage()               {}
func (*Entity) Descriptor() ([]byte, []int) { return fileDescriptor0, []int{1} }

func (m *Entity) GetName() string {
	if m != nil {
		return m.Name
	}
	return ""
}

func (m *Entity) GetType() EntityType {
	if m != nil {
		return m.Type
	}
	return EntityType_EntityNone
}

type NodeConfig struct {
	Entity *Entity `protobuf:"bytes,1,opt,name=entity" json:"entity,omitempty"`
	Config string  `protobuf:"bytes,2,opt,name=config" json:"config,omitempty"`
}

func (m *NodeConfig) Reset()                    { *m = NodeConfig{} }
func (m *NodeConfig) String() string            { return proto.CompactTextString(m) }
func (*NodeConfig) ProtoMessage()               {}
func (*NodeConfig) Descriptor() ([]byte, []int) { return fileDescriptor0, []int{2} }

func (m *NodeConfig) GetEntity() *Entity {
	if m != nil {
		return m.Entity
	}
	return nil
}

func (m *NodeConfig) GetConfig() string {
	if m != nil {
		return m.Config
	}
	return ""
}

type NodeConfigStatus struct {
	Status   ApiStatus `protobuf:"varint,1,opt,name=status,enum=agentproto.ApiStatus" json:"status,omitempty"`
	Response string    `protobuf:"bytes,2,opt,name=response" json:"response,omitempty"`
}

func (m *NodeConfigStatus) Reset()                    { *m = NodeConfigStatus{} }
func (m *NodeConfigStatus) String() string            { return proto.CompactTextString(m) }
func (*NodeConfigStatus) ProtoMessage()               {}
func (*NodeConfigStatus) Descriptor() ([]byte, []int) { return fileDescriptor0, []int{3} }

func (m *NodeConfigStatus) GetStatus() ApiStatus {
	if m != nil {
		return m.Status
	}
	return ApiStatus_API_STATUS_OK
}

func (m *NodeConfigStatus) GetResponse() string {
	if m != nil {
		return m.Response
	}
	return ""
}

type AppConfig struct {
	Name     string `protobuf:"bytes,1,opt,name=name" json:"name,omitempty"`
	Registry string `protobuf:"bytes,2,opt,name=registry" json:"registry,omitempty"`
}

func (m *AppConfig) Reset()                    { *m = AppConfig{} }
func (m *AppConfig) String() string            { return proto.CompactTextString(m) }
func (*AppConfig) ProtoMessage()               {}
func (*AppConfig) Descriptor() ([]byte, []int) { return fileDescriptor0, []int{4} }

func (m *AppConfig) GetName() string {
	if m != nil {
		return m.Name
	}
	return ""
}

func (m *AppConfig) GetRegistry() string {
	if m != nil {
		return m.Registry
	}
	return ""
}

type AppStatus struct {
	Status   ApiStatus `protobuf:"varint,1,opt,name=status,enum=agentproto.ApiStatus" json:"status,omitempty"`
	Response string    `protobuf:"bytes,2,opt,name=response" json:"response,omitempty"`
}

func (m *AppStatus) Reset()                    { *m = AppStatus{} }
func (m *AppStatus) String() string            { return proto.CompactTextString(m) }
func (*AppStatus) ProtoMessage()               {}
func (*AppStatus) Descriptor() ([]byte, []int) { return fileDescriptor0, []int{5} }

func (m *AppStatus) GetStatus() ApiStatus {
	if m != nil {
		return m.Status
	}
	return ApiStatus_API_STATUS_OK
}

func (m *AppStatus) GetResponse() string {
	if m != nil {
		return m.Response
	}
	return ""
}

type Interface struct {
	App        string `protobuf:"bytes,1,opt,name=app" json:"app,omitempty"`
	Name       string `protobuf:"bytes,2,opt,name=name" json:"name,omitempty"`
	MacAddress string `protobuf:"bytes,3,opt,name=macAddress" json:"macAddress,omitempty"`
	Vlan       uint32 `protobuf:"varint,4,opt,name=vlan" json:"vlan,omitempty"`
	IpAddress  string `protobuf:"bytes,5,opt,name=ipAddress" json:"ipAddress,omitempty"`
	PrefixLen  uint32 `protobuf:"varint,6,opt,name=prefixLen" json:"prefixLen,omitempty"`
}

func (m *Interface) Reset()                    { *m = Interface{} }
func (m *Interface) String() string            { return proto.CompactTextString(m) }
func (*Interface) ProtoMessage()               {}
func (*Interface) Descriptor() ([]byte, []int) { return fileDescriptor0, []int{6} }

func (m *Interface) GetApp() string {
	if m != nil {
		return m.App
	}
	return ""
}

func (m *Interface) GetName() string {
	if m != nil {
		return m.Name
	}
	return ""
}

func (m *Interface) GetMacAddress() string {
	if m != nil {
		return m.MacAddress
	}
	return ""
}

func (m *Interface) GetVlan() uint32 {
	if m != nil {
		return m.Vlan
	}
	return 0
}

func (m *Interface) GetIpAddress() string {
	if m != nil {
		return m.IpAddress
	}
	return ""
}

func (m *Interface) GetPrefixLen() uint32 {
	if m != nil {
		return m.PrefixLen
	}
	return 0
}

type InterfaceStatus struct {
	Status   ApiStatus `protobuf:"varint,1,opt,name=status,enum=agentproto.ApiStatus" json:"status,omitempty"`
	Response string    `protobuf:"bytes,2,opt,name=response" json:"response,omitempty"`
}

func (m *InterfaceStatus) Reset()                    { *m = InterfaceStatus{} }
func (m *InterfaceStatus) String() string            { return proto.CompactTextString(m) }
func (*InterfaceStatus) ProtoMessage()               {}
func (*InterfaceStatus) Descriptor() ([]byte, []int) { return fileDescriptor0, []int{7} }

func (m *InterfaceStatus) GetStatus() ApiStatus {
	if m != nil {
		return m.Status
	}
	return ApiStatus_API_STATUS_OK
}

func (m *InterfaceStatus) GetResponse() string {
	if m != nil {
		return m.Response
	}
	return ""
}

type Command struct {
	App        string `protobuf:"bytes,1,opt,name=app" json:"app,omitempty"`
	Cmd        string `protobuf:"bytes,2,opt,name=cmd" json:"cmd,omitempty"`
	Background bool   `protobuf:"varint,3,opt,name=background" json:"background,omitempty"`
	Timeout    uint32 `protobuf:"varint,4,opt,name=timeout" json:"timeout,omitempty"`
}

func (m *Command) Reset()                    { *m = Command{} }
func (m *Command) String() string            { return proto.CompactTextString(m) }
func (*Command) ProtoMessage()               {}
func (*Command) Descriptor() ([]byte, []int) { return fileDescriptor0, []int{8} }

func (m *Command) GetApp() string {
	if m != nil {
		return m.App
	}
	return ""
}

func (m *Command) GetCmd() string {
	if m != nil {
		return m.Cmd
	}
	return ""
}

func (m *Command) GetBackground() bool {
	if m != nil {
		return m.Background
	}
	return false
}

func (m *Command) GetTimeout() uint32 {
	if m != nil {
		return m.Timeout
	}
	return 0
}

type CommandStatus struct {
	Status  ApiStatus `protobuf:"varint,1,opt,name=status,enum=agentproto.ApiStatus" json:"status,omitempty"`
	RetCode int32     `protobuf:"varint,2,opt,name=retCode" json:"retCode,omitempty"`
	Stdout  string    `protobuf:"bytes,3,opt,name=stdout" json:"stdout,omitempty"`
	Stderr  string    `protobuf:"bytes,4,opt,name=stderr" json:"stderr,omitempty"`
}

func (m *CommandStatus) Reset()                    { *m = CommandStatus{} }
func (m *CommandStatus) String() string            { return proto.CompactTextString(m) }
func (*CommandStatus) ProtoMessage()               {}
func (*CommandStatus) Descriptor() ([]byte, []int) { return fileDescriptor0, []int{9} }

func (m *CommandStatus) GetStatus() ApiStatus {
	if m != nil {
		return m.Status
	}
	return ApiStatus_API_STATUS_OK
}

func (m *CommandStatus) GetRetCode() int32 {
	if m != nil {
		return m.RetCode
	}
	return 0
}

func (m *CommandStatus) GetStdout() string {
	if m != nil {
		return m.Stdout
	}
	return ""
}

func (m *CommandStatus) GetStderr() string {
	if m != nil {
		return m.Stderr
	}
	return ""
}

type NaplesSimConfig struct {
	Name            string `protobuf:"bytes,1,opt,name=name" json:"name,omitempty"`
	NodeID          uint32 `protobuf:"varint,2,opt,name=nodeID" json:"nodeID,omitempty"`
	CtrlNwIpRange   string `protobuf:"bytes,3,opt,name=ctrlNwIpRange" json:"ctrlNwIpRange,omitempty"`
	TunnelIpStart   string `protobuf:"bytes,4,opt,name=tunnelIpStart" json:"tunnelIpStart,omitempty"`
	TunnelInterface string `protobuf:"bytes,5,opt,name=tunnelInterface" json:"tunnelInterface,omitempty"`
	TunnelIpAddress string `protobuf:"bytes,6,opt,name=tunnelIpAddress" json:"tunnelIpAddress,omitempty"`
}

func (m *NaplesSimConfig) Reset()                    { *m = NaplesSimConfig{} }
func (m *NaplesSimConfig) String() string            { return proto.CompactTextString(m) }
func (*NaplesSimConfig) ProtoMessage()               {}
func (*NaplesSimConfig) Descriptor() ([]byte, []int) { return fileDescriptor0, []int{10} }

func (m *NaplesSimConfig) GetName() string {
	if m != nil {
		return m.Name
	}
	return ""
}

func (m *NaplesSimConfig) GetNodeID() uint32 {
	if m != nil {
		return m.NodeID
	}
	return 0
}

func (m *NaplesSimConfig) GetCtrlNwIpRange() string {
	if m != nil {
		return m.CtrlNwIpRange
	}
	return ""
}

func (m *NaplesSimConfig) GetTunnelIpStart() string {
	if m != nil {
		return m.TunnelIpStart
	}
	return ""
}

func (m *NaplesSimConfig) GetTunnelInterface() string {
	if m != nil {
		return m.TunnelInterface
	}
	return ""
}

func (m *NaplesSimConfig) GetTunnelIpAddress() string {
	if m != nil {
		return m.TunnelIpAddress
	}
	return ""
}

type NaplesStatus struct {
	Status   ApiStatus `protobuf:"varint,1,opt,name=status,enum=agentproto.ApiStatus" json:"status,omitempty"`
	Response string    `protobuf:"bytes,2,opt,name=response" json:"response,omitempty"`
}

func (m *NaplesStatus) Reset()                    { *m = NaplesStatus{} }
func (m *NaplesStatus) String() string            { return proto.CompactTextString(m) }
func (*NaplesStatus) ProtoMessage()               {}
func (*NaplesStatus) Descriptor() ([]byte, []int) { return fileDescriptor0, []int{11} }

func (m *NaplesStatus) GetStatus() ApiStatus {
	if m != nil {
		return m.Status
	}
	return ApiStatus_API_STATUS_OK
}

func (m *NaplesStatus) GetResponse() string {
	if m != nil {
		return m.Response
	}
	return ""
}

type HntapConfig struct {
	Config string `protobuf:"bytes,1,opt,name=config" json:"config,omitempty"`
}

func (m *HntapConfig) Reset()                    { *m = HntapConfig{} }
func (m *HntapConfig) String() string            { return proto.CompactTextString(m) }
func (*HntapConfig) ProtoMessage()               {}
func (*HntapConfig) Descriptor() ([]byte, []int) { return fileDescriptor0, []int{12} }

func (m *HntapConfig) GetConfig() string {
	if m != nil {
		return m.Config
	}
	return ""
}

func init() {
	proto.RegisterType((*PingMessage)(nil), "agentproto.PingMessage")
	proto.RegisterType((*Entity)(nil), "agentproto.Entity")
	proto.RegisterType((*NodeConfig)(nil), "agentproto.NodeConfig")
	proto.RegisterType((*NodeConfigStatus)(nil), "agentproto.NodeConfigStatus")
	proto.RegisterType((*AppConfig)(nil), "agentproto.AppConfig")
	proto.RegisterType((*AppStatus)(nil), "agentproto.AppStatus")
	proto.RegisterType((*Interface)(nil), "agentproto.Interface")
	proto.RegisterType((*InterfaceStatus)(nil), "agentproto.InterfaceStatus")
	proto.RegisterType((*Command)(nil), "agentproto.Command")
	proto.RegisterType((*CommandStatus)(nil), "agentproto.CommandStatus")
	proto.RegisterType((*NaplesSimConfig)(nil), "agentproto.NaplesSimConfig")
	proto.RegisterType((*NaplesStatus)(nil), "agentproto.NaplesStatus")
	proto.RegisterType((*HntapConfig)(nil), "agentproto.HntapConfig")
	proto.RegisterEnum("agentproto.ApiStatus", ApiStatus_name, ApiStatus_value)
	proto.RegisterEnum("agentproto.EntityType", EntityType_name, EntityType_value)
}

// Reference imports to suppress errors if they are not otherwise used.
var _ context.Context
var _ grpc.ClientConn

// This is a compile-time assertion to ensure that this generated file
// is compatible with the grpc package it is being compiled against.
const _ = grpc.SupportPackageIsVersion4

// Client API for Agent service

type AgentClient interface {
}

type agentClient struct {
	cc *grpc.ClientConn
}

func NewAgentClient(cc *grpc.ClientConn) AgentClient {
	return &agentClient{cc}
}

// Server API for Agent service

type AgentServer interface {
}

func RegisterAgentServer(s *grpc.Server, srv AgentServer) {
	s.RegisterService(&_Agent_serviceDesc, srv)
}

var _Agent_serviceDesc = grpc.ServiceDesc{
	ServiceName: "agentproto.Agent",
	HandlerType: (*AgentServer)(nil),
	Methods:     []grpc.MethodDesc{},
	Streams:     []grpc.StreamDesc{},
	Metadata:    "agent.proto",
}

// Client API for AppAgent service

type AppAgentClient interface {
	BringUp(ctx context.Context, in *AppConfig, opts ...grpc.CallOption) (*AppStatus, error)
	Teardown(ctx context.Context, in *AppConfig, opts ...grpc.CallOption) (*AppStatus, error)
	AttachInterface(ctx context.Context, in *Interface, opts ...grpc.CallOption) (*InterfaceStatus, error)
	RunCommand(ctx context.Context, in *Command, opts ...grpc.CallOption) (*CommandStatus, error)
}

type appAgentClient struct {
	cc *grpc.ClientConn
}

func NewAppAgentClient(cc *grpc.ClientConn) AppAgentClient {
	return &appAgentClient{cc}
}

func (c *appAgentClient) BringUp(ctx context.Context, in *AppConfig, opts ...grpc.CallOption) (*AppStatus, error) {
	out := new(AppStatus)
	err := grpc.Invoke(ctx, "/agentproto.AppAgent/BringUp", in, out, c.cc, opts...)
	if err != nil {
		return nil, err
	}
	return out, nil
}

func (c *appAgentClient) Teardown(ctx context.Context, in *AppConfig, opts ...grpc.CallOption) (*AppStatus, error) {
	out := new(AppStatus)
	err := grpc.Invoke(ctx, "/agentproto.AppAgent/Teardown", in, out, c.cc, opts...)
	if err != nil {
		return nil, err
	}
	return out, nil
}

func (c *appAgentClient) AttachInterface(ctx context.Context, in *Interface, opts ...grpc.CallOption) (*InterfaceStatus, error) {
	out := new(InterfaceStatus)
	err := grpc.Invoke(ctx, "/agentproto.AppAgent/AttachInterface", in, out, c.cc, opts...)
	if err != nil {
		return nil, err
	}
	return out, nil
}

func (c *appAgentClient) RunCommand(ctx context.Context, in *Command, opts ...grpc.CallOption) (*CommandStatus, error) {
	out := new(CommandStatus)
	err := grpc.Invoke(ctx, "/agentproto.AppAgent/RunCommand", in, out, c.cc, opts...)
	if err != nil {
		return nil, err
	}
	return out, nil
}

// Server API for AppAgent service

type AppAgentServer interface {
	BringUp(context.Context, *AppConfig) (*AppStatus, error)
	Teardown(context.Context, *AppConfig) (*AppStatus, error)
	AttachInterface(context.Context, *Interface) (*InterfaceStatus, error)
	RunCommand(context.Context, *Command) (*CommandStatus, error)
}

func RegisterAppAgentServer(s *grpc.Server, srv AppAgentServer) {
	s.RegisterService(&_AppAgent_serviceDesc, srv)
}

func _AppAgent_BringUp_Handler(srv interface{}, ctx context.Context, dec func(interface{}) error, interceptor grpc.UnaryServerInterceptor) (interface{}, error) {
	in := new(AppConfig)
	if err := dec(in); err != nil {
		return nil, err
	}
	if interceptor == nil {
		return srv.(AppAgentServer).BringUp(ctx, in)
	}
	info := &grpc.UnaryServerInfo{
		Server:     srv,
		FullMethod: "/agentproto.AppAgent/BringUp",
	}
	handler := func(ctx context.Context, req interface{}) (interface{}, error) {
		return srv.(AppAgentServer).BringUp(ctx, req.(*AppConfig))
	}
	return interceptor(ctx, in, info, handler)
}

func _AppAgent_Teardown_Handler(srv interface{}, ctx context.Context, dec func(interface{}) error, interceptor grpc.UnaryServerInterceptor) (interface{}, error) {
	in := new(AppConfig)
	if err := dec(in); err != nil {
		return nil, err
	}
	if interceptor == nil {
		return srv.(AppAgentServer).Teardown(ctx, in)
	}
	info := &grpc.UnaryServerInfo{
		Server:     srv,
		FullMethod: "/agentproto.AppAgent/Teardown",
	}
	handler := func(ctx context.Context, req interface{}) (interface{}, error) {
		return srv.(AppAgentServer).Teardown(ctx, req.(*AppConfig))
	}
	return interceptor(ctx, in, info, handler)
}

func _AppAgent_AttachInterface_Handler(srv interface{}, ctx context.Context, dec func(interface{}) error, interceptor grpc.UnaryServerInterceptor) (interface{}, error) {
	in := new(Interface)
	if err := dec(in); err != nil {
		return nil, err
	}
	if interceptor == nil {
		return srv.(AppAgentServer).AttachInterface(ctx, in)
	}
	info := &grpc.UnaryServerInfo{
		Server:     srv,
		FullMethod: "/agentproto.AppAgent/AttachInterface",
	}
	handler := func(ctx context.Context, req interface{}) (interface{}, error) {
		return srv.(AppAgentServer).AttachInterface(ctx, req.(*Interface))
	}
	return interceptor(ctx, in, info, handler)
}

func _AppAgent_RunCommand_Handler(srv interface{}, ctx context.Context, dec func(interface{}) error, interceptor grpc.UnaryServerInterceptor) (interface{}, error) {
	in := new(Command)
	if err := dec(in); err != nil {
		return nil, err
	}
	if interceptor == nil {
		return srv.(AppAgentServer).RunCommand(ctx, in)
	}
	info := &grpc.UnaryServerInfo{
		Server:     srv,
		FullMethod: "/agentproto.AppAgent/RunCommand",
	}
	handler := func(ctx context.Context, req interface{}) (interface{}, error) {
		return srv.(AppAgentServer).RunCommand(ctx, req.(*Command))
	}
	return interceptor(ctx, in, info, handler)
}

var _AppAgent_serviceDesc = grpc.ServiceDesc{
	ServiceName: "agentproto.AppAgent",
	HandlerType: (*AppAgentServer)(nil),
	Methods: []grpc.MethodDesc{
		{
			MethodName: "BringUp",
			Handler:    _AppAgent_BringUp_Handler,
		},
		{
			MethodName: "Teardown",
			Handler:    _AppAgent_Teardown_Handler,
		},
		{
			MethodName: "AttachInterface",
			Handler:    _AppAgent_AttachInterface_Handler,
		},
		{
			MethodName: "RunCommand",
			Handler:    _AppAgent_RunCommand_Handler,
		},
	},
	Streams:  []grpc.StreamDesc{},
	Metadata: "agent.proto",
}

// Client API for NaplesSim service

type NaplesSimClient interface {
	BringUp(ctx context.Context, in *NaplesSimConfig, opts ...grpc.CallOption) (*NaplesStatus, error)
	Teardown(ctx context.Context, in *NaplesSimConfig, opts ...grpc.CallOption) (*NaplesStatus, error)
	ConfigureHntap(ctx context.Context, in *HntapConfig, opts ...grpc.CallOption) (*NaplesStatus, error)
	RunCommand(ctx context.Context, in *Command, opts ...grpc.CallOption) (*CommandStatus, error)
}

type naplesSimClient struct {
	cc *grpc.ClientConn
}

func NewNaplesSimClient(cc *grpc.ClientConn) NaplesSimClient {
	return &naplesSimClient{cc}
}

func (c *naplesSimClient) BringUp(ctx context.Context, in *NaplesSimConfig, opts ...grpc.CallOption) (*NaplesStatus, error) {
	out := new(NaplesStatus)
	err := grpc.Invoke(ctx, "/agentproto.NaplesSim/BringUp", in, out, c.cc, opts...)
	if err != nil {
		return nil, err
	}
	return out, nil
}

func (c *naplesSimClient) Teardown(ctx context.Context, in *NaplesSimConfig, opts ...grpc.CallOption) (*NaplesStatus, error) {
	out := new(NaplesStatus)
	err := grpc.Invoke(ctx, "/agentproto.NaplesSim/Teardown", in, out, c.cc, opts...)
	if err != nil {
		return nil, err
	}
	return out, nil
}

func (c *naplesSimClient) ConfigureHntap(ctx context.Context, in *HntapConfig, opts ...grpc.CallOption) (*NaplesStatus, error) {
	out := new(NaplesStatus)
	err := grpc.Invoke(ctx, "/agentproto.NaplesSim/ConfigureHntap", in, out, c.cc, opts...)
	if err != nil {
		return nil, err
	}
	return out, nil
}

func (c *naplesSimClient) RunCommand(ctx context.Context, in *Command, opts ...grpc.CallOption) (*CommandStatus, error) {
	out := new(CommandStatus)
	err := grpc.Invoke(ctx, "/agentproto.NaplesSim/RunCommand", in, out, c.cc, opts...)
	if err != nil {
		return nil, err
	}
	return out, nil
}

// Server API for NaplesSim service

type NaplesSimServer interface {
	BringUp(context.Context, *NaplesSimConfig) (*NaplesStatus, error)
	Teardown(context.Context, *NaplesSimConfig) (*NaplesStatus, error)
	ConfigureHntap(context.Context, *HntapConfig) (*NaplesStatus, error)
	RunCommand(context.Context, *Command) (*CommandStatus, error)
}

func RegisterNaplesSimServer(s *grpc.Server, srv NaplesSimServer) {
	s.RegisterService(&_NaplesSim_serviceDesc, srv)
}

func _NaplesSim_BringUp_Handler(srv interface{}, ctx context.Context, dec func(interface{}) error, interceptor grpc.UnaryServerInterceptor) (interface{}, error) {
	in := new(NaplesSimConfig)
	if err := dec(in); err != nil {
		return nil, err
	}
	if interceptor == nil {
		return srv.(NaplesSimServer).BringUp(ctx, in)
	}
	info := &grpc.UnaryServerInfo{
		Server:     srv,
		FullMethod: "/agentproto.NaplesSim/BringUp",
	}
	handler := func(ctx context.Context, req interface{}) (interface{}, error) {
		return srv.(NaplesSimServer).BringUp(ctx, req.(*NaplesSimConfig))
	}
	return interceptor(ctx, in, info, handler)
}

func _NaplesSim_Teardown_Handler(srv interface{}, ctx context.Context, dec func(interface{}) error, interceptor grpc.UnaryServerInterceptor) (interface{}, error) {
	in := new(NaplesSimConfig)
	if err := dec(in); err != nil {
		return nil, err
	}
	if interceptor == nil {
		return srv.(NaplesSimServer).Teardown(ctx, in)
	}
	info := &grpc.UnaryServerInfo{
		Server:     srv,
		FullMethod: "/agentproto.NaplesSim/Teardown",
	}
	handler := func(ctx context.Context, req interface{}) (interface{}, error) {
		return srv.(NaplesSimServer).Teardown(ctx, req.(*NaplesSimConfig))
	}
	return interceptor(ctx, in, info, handler)
}

func _NaplesSim_ConfigureHntap_Handler(srv interface{}, ctx context.Context, dec func(interface{}) error, interceptor grpc.UnaryServerInterceptor) (interface{}, error) {
	in := new(HntapConfig)
	if err := dec(in); err != nil {
		return nil, err
	}
	if interceptor == nil {
		return srv.(NaplesSimServer).ConfigureHntap(ctx, in)
	}
	info := &grpc.UnaryServerInfo{
		Server:     srv,
		FullMethod: "/agentproto.NaplesSim/ConfigureHntap",
	}
	handler := func(ctx context.Context, req interface{}) (interface{}, error) {
		return srv.(NaplesSimServer).ConfigureHntap(ctx, req.(*HntapConfig))
	}
	return interceptor(ctx, in, info, handler)
}

func _NaplesSim_RunCommand_Handler(srv interface{}, ctx context.Context, dec func(interface{}) error, interceptor grpc.UnaryServerInterceptor) (interface{}, error) {
	in := new(Command)
	if err := dec(in); err != nil {
		return nil, err
	}
	if interceptor == nil {
		return srv.(NaplesSimServer).RunCommand(ctx, in)
	}
	info := &grpc.UnaryServerInfo{
		Server:     srv,
		FullMethod: "/agentproto.NaplesSim/RunCommand",
	}
	handler := func(ctx context.Context, req interface{}) (interface{}, error) {
		return srv.(NaplesSimServer).RunCommand(ctx, req.(*Command))
	}
	return interceptor(ctx, in, info, handler)
}

var _NaplesSim_serviceDesc = grpc.ServiceDesc{
	ServiceName: "agentproto.NaplesSim",
	HandlerType: (*NaplesSimServer)(nil),
	Methods: []grpc.MethodDesc{
		{
			MethodName: "BringUp",
			Handler:    _NaplesSim_BringUp_Handler,
		},
		{
			MethodName: "Teardown",
			Handler:    _NaplesSim_Teardown_Handler,
		},
		{
			MethodName: "ConfigureHntap",
			Handler:    _NaplesSim_ConfigureHntap_Handler,
		},
		{
			MethodName: "RunCommand",
			Handler:    _NaplesSim_RunCommand_Handler,
		},
	},
	Streams:  []grpc.StreamDesc{},
	Metadata: "agent.proto",
}

func init() { proto.RegisterFile("agent.proto", fileDescriptor0) }

var fileDescriptor0 = []byte{
	// 771 bytes of a gzipped FileDescriptorProto
	0x1f, 0x8b, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xff, 0xac, 0x54, 0xdf, 0x6e, 0xfb, 0x34,
	0x18, 0x5d, 0xfa, 0x27, 0x6d, 0xbf, 0xae, 0x6d, 0xe6, 0x69, 0x23, 0x94, 0x09, 0x4d, 0x11, 0x88,
	0xaa, 0x12, 0xbb, 0x28, 0x57, 0x80, 0x84, 0x94, 0x75, 0x1b, 0xab, 0xd8, 0xba, 0x2a, 0xed, 0x26,
	0x21, 0x81, 0x2a, 0x2f, 0xf1, 0xb2, 0x88, 0xc6, 0xb1, 0x1c, 0x97, 0xd1, 0x37, 0x40, 0xbc, 0x02,
	0x57, 0x3c, 0x18, 0xef, 0x82, 0xe2, 0x38, 0x4d, 0x5a, 0xaa, 0x49, 0xbf, 0xfd, 0x76, 0xe7, 0x73,
	0x72, 0xce, 0xf7, 0x2f, 0x9f, 0x0d, 0x4d, 0xec, 0x13, 0x2a, 0xce, 0x18, 0x8f, 0x44, 0x84, 0x40,
	0x02, 0x79, 0xb6, 0xbe, 0x82, 0xe6, 0x24, 0xa0, 0xfe, 0x2d, 0x89, 0x63, 0xec, 0x13, 0x64, 0x42,
	0x2d, 0x4c, 0x8f, 0xa6, 0x76, 0xaa, 0xf5, 0x1a, 0x4e, 0x06, 0xad, 0x6b, 0xd0, 0x2f, 0xa9, 0x08,
	0xc4, 0x0a, 0x21, 0xa8, 0x50, 0x1c, 0x66, 0x02, 0x79, 0x46, 0x7d, 0xa8, 0x88, 0x15, 0x23, 0x66,
	0xe9, 0x54, 0xeb, 0xb5, 0x07, 0xc7, 0x67, 0x79, 0x86, 0xb3, 0xd4, 0x35, 0x5b, 0x31, 0xe2, 0x48,
	0x8d, 0x35, 0x01, 0x18, 0x47, 0x1e, 0x19, 0x46, 0xf4, 0x29, 0xf0, 0x51, 0x1f, 0x74, 0x22, 0x15,
	0x32, 0x5e, 0x73, 0x80, 0xfe, 0xef, 0x75, 0x94, 0x02, 0x1d, 0x83, 0xee, 0x4a, 0x97, 0xcc, 0xd3,
	0x70, 0x14, 0xb2, 0x7e, 0x05, 0x23, 0x8f, 0x38, 0x15, 0x58, 0x2c, 0x63, 0xf4, 0x35, 0xe8, 0xb1,
	0x3c, 0xc9, 0xb8, 0xed, 0xc1, 0x51, 0x31, 0xae, 0xcd, 0x82, 0x54, 0xe6, 0x28, 0x11, 0xea, 0x42,
	0x9d, 0x93, 0x98, 0x45, 0x34, 0x26, 0x2a, 0xf8, 0x1a, 0x5b, 0xdf, 0x43, 0xc3, 0x66, 0x4c, 0xd5,
	0xbb, 0xab, 0x7b, 0x69, 0xf6, 0x83, 0x58, 0xf0, 0x55, 0x6e, 0x4e, 0xb1, 0xf5, 0x20, 0xcd, 0xef,
	0x5f, 0xd4, 0x3f, 0x1a, 0x34, 0x46, 0x54, 0x10, 0xfe, 0x84, 0x5d, 0x82, 0x0c, 0x28, 0x63, 0xc6,
	0x54, 0x51, 0xc9, 0x71, 0x5d, 0x67, 0xa9, 0x50, 0xe7, 0xe7, 0x00, 0x21, 0x76, 0x6d, 0xcf, 0xe3,
	0x24, 0x8e, 0xcd, 0xb2, 0xfc, 0x52, 0x60, 0x12, 0xcf, 0xef, 0x0b, 0x4c, 0xcd, 0xca, 0xa9, 0xd6,
	0x6b, 0x39, 0xf2, 0x8c, 0x4e, 0xa0, 0x11, 0xb0, 0xcc, 0x52, 0x95, 0x96, 0x9c, 0x48, 0xbe, 0x32,
	0x4e, 0x9e, 0x82, 0x3f, 0x6e, 0x08, 0x35, 0x75, 0x69, 0xcb, 0x09, 0xeb, 0x17, 0xe8, 0xac, 0x4b,
	0x7c, 0xff, 0x09, 0xf8, 0x50, 0x1b, 0x46, 0x61, 0x88, 0xa9, 0xb7, 0xa3, 0x7d, 0x03, 0xca, 0x6e,
	0xe8, 0x29, 0x4f, 0x72, 0x4c, 0x9a, 0x7f, 0xc4, 0xee, 0x6f, 0x3e, 0x8f, 0x96, 0xd4, 0x93, 0xcd,
	0xd7, 0x9d, 0x02, 0x93, 0xac, 0xbe, 0x08, 0x42, 0x12, 0x2d, 0x85, 0xea, 0x3f, 0x83, 0xd6, 0x9f,
	0x1a, 0xb4, 0x54, 0xa6, 0xb7, 0x75, 0x61, 0x42, 0x8d, 0x13, 0x31, 0x8c, 0xbc, 0xb4, 0x89, 0xaa,
	0x93, 0xc1, 0x64, 0xa3, 0x63, 0xe1, 0x25, 0x39, 0xd3, 0xbf, 0xa1, 0x90, 0xe2, 0x09, 0xe7, 0xb2,
	0x96, 0x94, 0x27, 0x9c, 0x5b, 0xff, 0x6a, 0xd0, 0x19, 0x63, 0xb6, 0x20, 0xf1, 0x34, 0x08, 0x5f,
	0xd9, 0xc8, 0x63, 0xd0, 0x69, 0xe4, 0x91, 0xd1, 0x85, 0x4c, 0xd8, 0x72, 0x14, 0x42, 0x5f, 0x40,
	0xcb, 0x15, 0x7c, 0x31, 0x7e, 0x19, 0x31, 0x07, 0x53, 0x9f, 0xa8, 0xb4, 0x9b, 0x64, 0xa2, 0x12,
	0x4b, 0x4a, 0xc9, 0x62, 0x94, 0x2c, 0x2e, 0x17, 0xaa, 0x88, 0x4d, 0x12, 0xf5, 0xa0, 0xa3, 0x88,
	0xec, 0x1f, 0xab, 0xfd, 0xd8, 0xa6, 0x0b, 0xca, 0xf5, 0x26, 0xe9, 0x1b, 0xca, 0x8c, 0xb6, 0x7e,
	0x86, 0x7d, 0xd5, 0xde, 0xbb, 0xaf, 0xcb, 0x97, 0xd0, 0xbc, 0xa6, 0x02, 0x67, 0xf7, 0x38, 0x7f,
	0x4b, 0xb4, 0xe2, 0x5b, 0xd2, 0x9f, 0x26, 0xf7, 0x55, 0xc5, 0x45, 0x07, 0xd0, 0xb2, 0x27, 0xa3,
	0xf9, 0x74, 0x66, 0xcf, 0xee, 0xa7, 0xf3, 0xbb, 0x9f, 0x8c, 0x3d, 0x74, 0x04, 0x07, 0x05, 0xea,
	0xca, 0x1e, 0xdd, 0x5c, 0x5e, 0x18, 0x1a, 0x3a, 0x01, 0xb3, 0x40, 0xdb, 0x93, 0xc9, 0x7c, 0x7c,
	0x37, 0x9b, 0x5f, 0xdd, 0xdd, 0x8f, 0x2f, 0x8c, 0x52, 0x9f, 0x03, 0xe4, 0xcf, 0x20, 0x6a, 0x67,
	0x68, 0x1c, 0x51, 0x62, 0xec, 0x21, 0x03, 0xf6, 0x15, 0x96, 0xad, 0x1b, 0x1a, 0x3a, 0x84, 0x4e,
	0xca, 0x0c, 0x23, 0x2a, 0x70, 0x40, 0x09, 0x37, 0x4a, 0xa8, 0x05, 0x8d, 0x94, 0xb4, 0x19, 0x33,
	0xca, 0xb9, 0x6b, 0xfa, 0x12, 0x08, 0xf7, 0xd9, 0xa8, 0xa0, 0x7d, 0xa8, 0xa7, 0xcc, 0xc3, 0xad,
	0x51, 0x1d, 0xd4, 0xa0, 0x6a, 0x27, 0xb3, 0x1a, 0xfc, 0x55, 0x82, 0xba, 0xcd, 0x98, 0x04, 0xe8,
	0x5b, 0xa8, 0x9d, 0xf3, 0x80, 0xfa, 0xf7, 0x0c, 0x6d, 0xcd, 0x52, 0x0d, 0xa6, 0xbb, 0x4d, 0xa7,
	0xa3, 0xb0, 0xf6, 0xd0, 0x77, 0x50, 0x9f, 0x11, 0xcc, 0xbd, 0xe8, 0x85, 0x7e, 0xb0, 0xf7, 0x47,
	0xe8, 0xd8, 0x42, 0x60, 0xf7, 0x39, 0x5f, 0x8a, 0x0d, 0xed, 0x9a, 0xee, 0x7e, 0xb6, 0x93, 0x5e,
	0x07, 0xfa, 0x01, 0xc0, 0x59, 0xd2, 0xec, 0xde, 0x1f, 0x16, 0xc5, 0x8a, 0xec, 0x7e, 0xba, 0x83,
	0xcc, 0xfc, 0x83, 0xbf, 0x4b, 0xd0, 0x58, 0x5f, 0x20, 0x74, 0x9e, 0x4f, 0x63, 0x23, 0xef, 0xd6,
	0x15, 0xeb, 0x9a, 0x3b, 0x3e, 0x66, 0x15, 0x0d, 0x0b, 0x63, 0x79, 0x73, 0x90, 0x4b, 0x68, 0xa7,
	0xaa, 0x25, 0x27, 0x72, 0x4b, 0xd1, 0x27, 0x45, 0x75, 0x61, 0x71, 0x5f, 0x0d, 0xf3, 0x91, 0xd3,
	0x79, 0xd4, 0x25, 0xfd, 0xcd, 0x7f, 0x01, 0x00, 0x00, 0xff, 0xff, 0xc2, 0xa2, 0x16, 0x16, 0x2f,
	0x08, 0x00, 0x00,
}
