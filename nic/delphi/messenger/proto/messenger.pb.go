// Code generated by protoc-gen-go. DO NOT EDIT.
// source: messenger.proto

/*
Package delphi_messenger is a generated protocol buffer package.

It is generated from these files:
	messenger.proto

It has these top-level messages:
	ObjectData
	MountData
	MountReqMsg
	MountRespMsg
	Message
	TestKey
	TestObject
*/
package delphi_messenger

import proto "github.com/golang/protobuf/proto"
import fmt "fmt"
import math "math"
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

// message types
type MessageType int32

const (
	MessageType_Invalid    MessageType = 0
	MessageType_Notify     MessageType = 1
	MessageType_ChangeReq  MessageType = 2
	MessageType_StatusResp MessageType = 3
	MessageType_GetReq     MessageType = 4
	MessageType_GetResp    MessageType = 5
	MessageType_ListReq    MessageType = 6
	MessageType_ListResp   MessageType = 7
	MessageType_MountReq   MessageType = 8
	MessageType_MountResp  MessageType = 9
)

var MessageType_name = map[int32]string{
	0: "Invalid",
	1: "Notify",
	2: "ChangeReq",
	3: "StatusResp",
	4: "GetReq",
	5: "GetResp",
	6: "ListReq",
	7: "ListResp",
	8: "MountReq",
	9: "MountResp",
}
var MessageType_value = map[string]int32{
	"Invalid":    0,
	"Notify":     1,
	"ChangeReq":  2,
	"StatusResp": 3,
	"GetReq":     4,
	"GetResp":    5,
	"ListReq":    6,
	"ListResp":   7,
	"MountReq":   8,
	"MountResp":  9,
}

func (x MessageType) String() string {
	return proto.EnumName(MessageType_name, int32(x))
}
func (MessageType) EnumDescriptor() ([]byte, []int) { return fileDescriptor0, []int{0} }

// message container for one object
type ObjectData struct {
	Meta    *delphi.ObjectMeta     `protobuf:"bytes,1,opt,name=Meta" json:"Meta,omitempty"`
	Op      delphi.ObjectOperation `protobuf:"varint,2,opt,name=Op,enum=delphi.ObjectOperation" json:"Op,omitempty"`
	Data    []byte                 `protobuf:"bytes,3,opt,name=Data,proto3" json:"Data,omitempty"`
	Persist bool                   `protobuf:"varint,4,opt,name=Persist" json:"Persist,omitempty"`
}

func (m *ObjectData) Reset()                    { *m = ObjectData{} }
func (m *ObjectData) String() string            { return proto.CompactTextString(m) }
func (*ObjectData) ProtoMessage()               {}
func (*ObjectData) Descriptor() ([]byte, []int) { return fileDescriptor0, []int{0} }

func (m *ObjectData) GetMeta() *delphi.ObjectMeta {
	if m != nil {
		return m.Meta
	}
	return nil
}

func (m *ObjectData) GetOp() delphi.ObjectOperation {
	if m != nil {
		return m.Op
	}
	return delphi.ObjectOperation_InvalidOp
}

func (m *ObjectData) GetData() []byte {
	if m != nil {
		return m.Data
	}
	return nil
}

func (m *ObjectData) GetPersist() bool {
	if m != nil {
		return m.Persist
	}
	return false
}

// mount data
type MountData struct {
	Kind string           `protobuf:"bytes,1,opt,name=Kind" json:"Kind,omitempty"`
	Key  string           `protobuf:"bytes,2,opt,name=Key" json:"Key,omitempty"`
	Mode delphi.MountMode `protobuf:"varint,3,opt,name=Mode,enum=delphi.MountMode" json:"Mode,omitempty"`
}

func (m *MountData) Reset()                    { *m = MountData{} }
func (m *MountData) String() string            { return proto.CompactTextString(m) }
func (*MountData) ProtoMessage()               {}
func (*MountData) Descriptor() ([]byte, []int) { return fileDescriptor0, []int{1} }

func (m *MountData) GetKind() string {
	if m != nil {
		return m.Kind
	}
	return ""
}

func (m *MountData) GetKey() string {
	if m != nil {
		return m.Key
	}
	return ""
}

func (m *MountData) GetMode() delphi.MountMode {
	if m != nil {
		return m.Mode
	}
	return delphi.MountMode_InvalidMode
}

// mount request
type MountReqMsg struct {
	ServiceName string       `protobuf:"bytes,1,opt,name=ServiceName" json:"ServiceName,omitempty"`
	ServiceID   uint32       `protobuf:"varint,2,opt,name=ServiceID" json:"ServiceID,omitempty"`
	Mounts      []*MountData `protobuf:"bytes,3,rep,name=Mounts" json:"Mounts,omitempty"`
}

func (m *MountReqMsg) Reset()                    { *m = MountReqMsg{} }
func (m *MountReqMsg) String() string            { return proto.CompactTextString(m) }
func (*MountReqMsg) ProtoMessage()               {}
func (*MountReqMsg) Descriptor() ([]byte, []int) { return fileDescriptor0, []int{2} }

func (m *MountReqMsg) GetServiceName() string {
	if m != nil {
		return m.ServiceName
	}
	return ""
}

func (m *MountReqMsg) GetServiceID() uint32 {
	if m != nil {
		return m.ServiceID
	}
	return 0
}

func (m *MountReqMsg) GetMounts() []*MountData {
	if m != nil {
		return m.Mounts
	}
	return nil
}

// mount response
type MountRespMsg struct {
	ServiceName string        `protobuf:"bytes,1,opt,name=ServiceName" json:"ServiceName,omitempty"`
	ServiceID   uint32        `protobuf:"varint,2,opt,name=ServiceID" json:"ServiceID,omitempty"`
	Objects     []*ObjectData `protobuf:"bytes,6,rep,name=Objects" json:"Objects,omitempty"`
}

func (m *MountRespMsg) Reset()                    { *m = MountRespMsg{} }
func (m *MountRespMsg) String() string            { return proto.CompactTextString(m) }
func (*MountRespMsg) ProtoMessage()               {}
func (*MountRespMsg) Descriptor() ([]byte, []int) { return fileDescriptor0, []int{3} }

func (m *MountRespMsg) GetServiceName() string {
	if m != nil {
		return m.ServiceName
	}
	return ""
}

func (m *MountRespMsg) GetServiceID() uint32 {
	if m != nil {
		return m.ServiceID
	}
	return 0
}

func (m *MountRespMsg) GetObjects() []*ObjectData {
	if m != nil {
		return m.Objects
	}
	return nil
}

// all messages exchanged by delphi components are in this format
type Message struct {
	Type       MessageType   `protobuf:"varint,1,opt,name=Type,enum=delphi.messenger.MessageType" json:"Type,omitempty"`
	MessageId  uint64        `protobuf:"varint,2,opt,name=MessageId" json:"MessageId,omitempty"`
	ResponseTo uint64        `protobuf:"varint,3,opt,name=ResponseTo" json:"ResponseTo,omitempty"`
	Status     string        `protobuf:"bytes,4,opt,name=Status" json:"Status,omitempty"`
	Objects    []*ObjectData `protobuf:"bytes,6,rep,name=Objects" json:"Objects,omitempty"`
}

func (m *Message) Reset()                    { *m = Message{} }
func (m *Message) String() string            { return proto.CompactTextString(m) }
func (*Message) ProtoMessage()               {}
func (*Message) Descriptor() ([]byte, []int) { return fileDescriptor0, []int{4} }

func (m *Message) GetType() MessageType {
	if m != nil {
		return m.Type
	}
	return MessageType_Invalid
}

func (m *Message) GetMessageId() uint64 {
	if m != nil {
		return m.MessageId
	}
	return 0
}

func (m *Message) GetResponseTo() uint64 {
	if m != nil {
		return m.ResponseTo
	}
	return 0
}

func (m *Message) GetStatus() string {
	if m != nil {
		return m.Status
	}
	return ""
}

func (m *Message) GetObjects() []*ObjectData {
	if m != nil {
		return m.Objects
	}
	return nil
}

type TestKey struct {
	Idx uint32 `protobuf:"varint,1,opt,name=Idx" json:"Idx,omitempty"`
}

func (m *TestKey) Reset()                    { *m = TestKey{} }
func (m *TestKey) String() string            { return proto.CompactTextString(m) }
func (*TestKey) ProtoMessage()               {}
func (*TestKey) Descriptor() ([]byte, []int) { return fileDescriptor0, []int{5} }

func (m *TestKey) GetIdx() uint32 {
	if m != nil {
		return m.Idx
	}
	return 0
}

type TestObject struct {
	Meta      *delphi.ObjectMeta `protobuf:"bytes,1,opt,name=Meta" json:"Meta,omitempty"`
	Key       *TestKey           `protobuf:"bytes,2,opt,name=Key" json:"Key,omitempty"`
	TestData1 string             `protobuf:"bytes,3,opt,name=TestData1" json:"TestData1,omitempty"`
	TestData2 string             `protobuf:"bytes,4,opt,name=TestData2" json:"TestData2,omitempty"`
	TestData3 string             `protobuf:"bytes,5,opt,name=TestData3" json:"TestData3,omitempty"`
	TestData4 string             `protobuf:"bytes,6,opt,name=TestData4" json:"TestData4,omitempty"`
	TestData5 string             `protobuf:"bytes,7,opt,name=TestData5" json:"TestData5,omitempty"`
}

func (m *TestObject) Reset()                    { *m = TestObject{} }
func (m *TestObject) String() string            { return proto.CompactTextString(m) }
func (*TestObject) ProtoMessage()               {}
func (*TestObject) Descriptor() ([]byte, []int) { return fileDescriptor0, []int{6} }

func (m *TestObject) GetMeta() *delphi.ObjectMeta {
	if m != nil {
		return m.Meta
	}
	return nil
}

func (m *TestObject) GetKey() *TestKey {
	if m != nil {
		return m.Key
	}
	return nil
}

func (m *TestObject) GetTestData1() string {
	if m != nil {
		return m.TestData1
	}
	return ""
}

func (m *TestObject) GetTestData2() string {
	if m != nil {
		return m.TestData2
	}
	return ""
}

func (m *TestObject) GetTestData3() string {
	if m != nil {
		return m.TestData3
	}
	return ""
}

func (m *TestObject) GetTestData4() string {
	if m != nil {
		return m.TestData4
	}
	return ""
}

func (m *TestObject) GetTestData5() string {
	if m != nil {
		return m.TestData5
	}
	return ""
}

func init() {
	proto.RegisterType((*ObjectData)(nil), "delphi.messenger.ObjectData")
	proto.RegisterType((*MountData)(nil), "delphi.messenger.MountData")
	proto.RegisterType((*MountReqMsg)(nil), "delphi.messenger.MountReqMsg")
	proto.RegisterType((*MountRespMsg)(nil), "delphi.messenger.MountRespMsg")
	proto.RegisterType((*Message)(nil), "delphi.messenger.Message")
	proto.RegisterType((*TestKey)(nil), "delphi.messenger.TestKey")
	proto.RegisterType((*TestObject)(nil), "delphi.messenger.TestObject")
	proto.RegisterEnum("delphi.messenger.MessageType", MessageType_name, MessageType_value)
}

func init() { proto.RegisterFile("messenger.proto", fileDescriptor0) }

var fileDescriptor0 = []byte{
	// 559 bytes of a gzipped FileDescriptorProto
	0x1f, 0x8b, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xff, 0xac, 0x54, 0xc1, 0x6e, 0xd3, 0x40,
	0x10, 0x65, 0x63, 0xd7, 0xae, 0xc7, 0x49, 0x58, 0xf6, 0x00, 0x86, 0x06, 0x64, 0x59, 0x02, 0x22,
	0x90, 0x22, 0xd5, 0x69, 0x39, 0x70, 0xa5, 0x12, 0x8a, 0x4a, 0x1a, 0xb4, 0xcd, 0x81, 0xab, 0x5b,
	0x0f, 0xa9, 0x51, 0x6b, 0xbb, 0x5e, 0xb7, 0x22, 0x37, 0xc4, 0x81, 0x0b, 0x77, 0xf8, 0x27, 0xfe,
	0x09, 0x09, 0xed, 0xd8, 0x89, 0x1d, 0xca, 0x01, 0x21, 0x6e, 0x33, 0xef, 0x3d, 0xcd, 0xbc, 0xf1,
	0xcc, 0x1a, 0x6e, 0x5f, 0xa0, 0x52, 0x98, 0x2e, 0xb0, 0x18, 0xe5, 0x45, 0x56, 0x66, 0x82, 0xc7,
	0x78, 0x9e, 0x9f, 0x25, 0xa3, 0x35, 0xfe, 0xa0, 0x5b, 0x23, 0xc4, 0x07, 0x5f, 0x19, 0xc0, 0xec,
	0xe4, 0x03, 0x9e, 0x96, 0x07, 0x51, 0x19, 0x89, 0x27, 0x60, 0x4e, 0xb1, 0x8c, 0x3c, 0xe6, 0xb3,
	0xa1, 0x1b, 0x8a, 0x51, 0xad, 0xad, 0x14, 0x9a, 0x91, 0xc4, 0x8b, 0xa7, 0xd0, 0x99, 0xe5, 0x5e,
	0xc7, 0x67, 0xc3, 0x7e, 0x78, 0x6f, 0x53, 0x35, 0xcb, 0xb1, 0x88, 0xca, 0x24, 0x4b, 0x65, 0x67,
	0x96, 0x0b, 0x01, 0xa6, 0x2e, 0xec, 0x19, 0x3e, 0x1b, 0x76, 0x25, 0xc5, 0xc2, 0x03, 0xfb, 0x2d,
	0x16, 0x2a, 0x51, 0xa5, 0x67, 0xfa, 0x6c, 0xb8, 0x2d, 0x57, 0x69, 0xf0, 0x0e, 0x9c, 0x69, 0x76,
	0x95, 0x56, 0x5e, 0x04, 0x98, 0x87, 0x49, 0x1a, 0x93, 0x17, 0x47, 0x52, 0x2c, 0x38, 0x18, 0x87,
	0xb8, 0xa4, 0xc6, 0x8e, 0xd4, 0xa1, 0x78, 0x0c, 0xe6, 0x34, 0x8b, 0x91, 0x1a, 0xf4, 0xc3, 0x3b,
	0x2b, 0x2f, 0x54, 0x46, 0x13, 0x92, 0xe8, 0xe0, 0x33, 0x03, 0x97, 0x30, 0x89, 0x97, 0x53, 0xb5,
	0x10, 0x3e, 0xb8, 0xc7, 0x58, 0x5c, 0x27, 0xa7, 0x78, 0x14, 0x5d, 0x60, 0xdd, 0xa3, 0x0d, 0x89,
	0x01, 0x38, 0x75, 0x3a, 0x39, 0xa0, 0x86, 0x3d, 0xd9, 0x00, 0x62, 0x0c, 0x16, 0x95, 0x53, 0x9e,
	0xe1, 0x1b, 0x43, 0x37, 0xdc, 0x19, 0xfd, 0xfe, 0xa1, 0x47, 0xeb, 0x49, 0x64, 0x2d, 0x0d, 0xbe,
	0x30, 0xe8, 0xd6, 0x26, 0x54, 0xfe, 0x3f, 0x5c, 0xbc, 0x00, 0xbb, 0xfa, 0xe8, 0xca, 0xb3, 0xc8,
	0xc6, 0xe0, 0xa6, 0x8d, 0x66, 0xbb, 0x72, 0x25, 0x0e, 0x7e, 0x30, 0xb0, 0xa7, 0xa8, 0x54, 0xb4,
	0x40, 0xb1, 0x0b, 0xe6, 0x7c, 0x99, 0x57, 0xcd, 0xfb, 0xe1, 0xc3, 0x3f, 0xcc, 0x51, 0x09, 0xb5,
	0x48, 0x92, 0x54, 0x9b, 0xaa, 0xc1, 0x49, 0x4c, 0xa6, 0x4c, 0xd9, 0x00, 0xe2, 0x11, 0x80, 0x9e,
	0x2f, 0x4b, 0x15, 0xce, 0x33, 0xda, 0x8b, 0x29, 0x5b, 0x88, 0xb8, 0x0b, 0xd6, 0x71, 0x19, 0x95,
	0x57, 0x8a, 0xb6, 0xef, 0xc8, 0x3a, 0xfb, 0xe7, 0x61, 0x76, 0xc0, 0x9e, 0xa3, 0x2a, 0xf5, 0x31,
	0x70, 0x30, 0x26, 0xf1, 0x47, 0x1a, 0xa5, 0x27, 0x75, 0x18, 0xfc, 0x64, 0x00, 0x9a, 0xad, 0xc4,
	0x7f, 0x7d, 0xdf, 0xcf, 0x9b, 0x3b, 0x73, 0xc3, 0xfb, 0x37, 0x7d, 0xd4, 0x0d, 0xab, 0x13, 0x1c,
	0x80, 0xa3, 0x73, 0xed, 0x6a, 0x97, 0xe6, 0x75, 0x64, 0x03, 0xb4, 0xd9, 0xb0, 0x9e, 0xb8, 0x01,
	0xda, 0xec, 0xd8, 0xdb, 0xda, 0x64, 0xc7, 0x6d, 0x76, 0xcf, 0xb3, 0x36, 0xd9, 0xbd, 0x36, 0xbb,
	0xef, 0xd9, 0x9b, 0xec, 0xfe, 0x4b, 0xf3, 0xd3, 0xf7, 0x80, 0x3d, 0xfb, 0xa6, 0xef, 0xbe, 0x59,
	0xa0, 0x70, 0xc1, 0x9e, 0xa4, 0xd7, 0xd1, 0x79, 0x12, 0xf3, 0x5b, 0x02, 0xc0, 0x3a, 0xca, 0xca,
	0xe4, 0xfd, 0x92, 0x33, 0xd1, 0x03, 0xe7, 0xd5, 0x59, 0x94, 0x2e, 0x50, 0xe2, 0x25, 0xef, 0x88,
	0x3e, 0x40, 0xb5, 0x16, 0xbd, 0x38, 0x6e, 0x68, 0xe9, 0x6b, 0xd4, 0x8f, 0x87, 0x9b, 0xba, 0x06,
	0xc5, 0x2a, 0xe7, 0x5b, 0x3a, 0x79, 0x93, 0x28, 0x62, 0x2c, 0xd1, 0x85, 0xed, 0x2a, 0x51, 0x39,
	0xb7, 0x75, 0xb6, 0x7a, 0x72, 0x7c, 0x5b, 0x37, 0x58, 0xdf, 0x3e, 0x77, 0x4e, 0x2c, 0xfa, 0xff,
	0x8c, 0x7f, 0x05, 0x00, 0x00, 0xff, 0xff, 0xad, 0x38, 0xe9, 0xc7, 0xb2, 0x04, 0x00, 0x00,
}
