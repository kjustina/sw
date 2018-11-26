// Code generated by protoc-gen-go. DO NOT EDIT.
// source: crypto_keys.proto

package halproto

import proto "github.com/golang/protobuf/proto"
import fmt "fmt"
import math "math"

// Reference imports to suppress errors if they are not otherwise used.
var _ = proto.Marshal
var _ = fmt.Errorf
var _ = math.Inf

type CryptoKeyCreateRequest struct {
}

func (m *CryptoKeyCreateRequest) Reset()                    { *m = CryptoKeyCreateRequest{} }
func (m *CryptoKeyCreateRequest) String() string            { return proto.CompactTextString(m) }
func (*CryptoKeyCreateRequest) ProtoMessage()               {}
func (*CryptoKeyCreateRequest) Descriptor() ([]byte, []int) { return fileDescriptor19, []int{0} }

type CryptoKeyCreateRequestMsg struct {
	Request []*CryptoKeyCreateRequest `protobuf:"bytes,1,rep,name=request" json:"request,omitempty"`
}

func (m *CryptoKeyCreateRequestMsg) Reset()                    { *m = CryptoKeyCreateRequestMsg{} }
func (m *CryptoKeyCreateRequestMsg) String() string            { return proto.CompactTextString(m) }
func (*CryptoKeyCreateRequestMsg) ProtoMessage()               {}
func (*CryptoKeyCreateRequestMsg) Descriptor() ([]byte, []int) { return fileDescriptor19, []int{1} }

func (m *CryptoKeyCreateRequestMsg) GetRequest() []*CryptoKeyCreateRequest {
	if m != nil {
		return m.Request
	}
	return nil
}

type CryptoKeyCreateResponse struct {
	ApiStatus ApiStatus `protobuf:"varint,1,opt,name=api_status,json=apiStatus,enum=types.ApiStatus" json:"api_status,omitempty"`
	Keyindex  uint32    `protobuf:"varint,2,opt,name=keyindex" json:"keyindex,omitempty"`
}

func (m *CryptoKeyCreateResponse) Reset()                    { *m = CryptoKeyCreateResponse{} }
func (m *CryptoKeyCreateResponse) String() string            { return proto.CompactTextString(m) }
func (*CryptoKeyCreateResponse) ProtoMessage()               {}
func (*CryptoKeyCreateResponse) Descriptor() ([]byte, []int) { return fileDescriptor19, []int{2} }

func (m *CryptoKeyCreateResponse) GetApiStatus() ApiStatus {
	if m != nil {
		return m.ApiStatus
	}
	return ApiStatus_API_STATUS_OK
}

func (m *CryptoKeyCreateResponse) GetKeyindex() uint32 {
	if m != nil {
		return m.Keyindex
	}
	return 0
}

type CryptoKeyCreateResponseMsg struct {
	Response []*CryptoKeyCreateResponse `protobuf:"bytes,1,rep,name=response" json:"response,omitempty"`
}

func (m *CryptoKeyCreateResponseMsg) Reset()                    { *m = CryptoKeyCreateResponseMsg{} }
func (m *CryptoKeyCreateResponseMsg) String() string            { return proto.CompactTextString(m) }
func (*CryptoKeyCreateResponseMsg) ProtoMessage()               {}
func (*CryptoKeyCreateResponseMsg) Descriptor() ([]byte, []int) { return fileDescriptor19, []int{3} }

func (m *CryptoKeyCreateResponseMsg) GetResponse() []*CryptoKeyCreateResponse {
	if m != nil {
		return m.Response
	}
	return nil
}

type CryptoKeyCreateWithIdRequest struct {
	Keyindex      uint32 `protobuf:"varint,1,opt,name=keyindex" json:"keyindex,omitempty"`
	AllowDupAlloc uint32 `protobuf:"varint,2,opt,name=allow_dup_alloc,json=allowDupAlloc" json:"allow_dup_alloc,omitempty"`
}

func (m *CryptoKeyCreateWithIdRequest) Reset()                    { *m = CryptoKeyCreateWithIdRequest{} }
func (m *CryptoKeyCreateWithIdRequest) String() string            { return proto.CompactTextString(m) }
func (*CryptoKeyCreateWithIdRequest) ProtoMessage()               {}
func (*CryptoKeyCreateWithIdRequest) Descriptor() ([]byte, []int) { return fileDescriptor19, []int{4} }

func (m *CryptoKeyCreateWithIdRequest) GetKeyindex() uint32 {
	if m != nil {
		return m.Keyindex
	}
	return 0
}

func (m *CryptoKeyCreateWithIdRequest) GetAllowDupAlloc() uint32 {
	if m != nil {
		return m.AllowDupAlloc
	}
	return 0
}

type CryptoKeyCreateWithIdRequestMsg struct {
	Request []*CryptoKeyCreateWithIdRequest `protobuf:"bytes,1,rep,name=request" json:"request,omitempty"`
}

func (m *CryptoKeyCreateWithIdRequestMsg) Reset()         { *m = CryptoKeyCreateWithIdRequestMsg{} }
func (m *CryptoKeyCreateWithIdRequestMsg) String() string { return proto.CompactTextString(m) }
func (*CryptoKeyCreateWithIdRequestMsg) ProtoMessage()    {}
func (*CryptoKeyCreateWithIdRequestMsg) Descriptor() ([]byte, []int) {
	return fileDescriptor19, []int{5}
}

func (m *CryptoKeyCreateWithIdRequestMsg) GetRequest() []*CryptoKeyCreateWithIdRequest {
	if m != nil {
		return m.Request
	}
	return nil
}

type CryptoKeyCreateWithIdResponse struct {
	ApiStatus ApiStatus `protobuf:"varint,1,opt,name=api_status,json=apiStatus,enum=types.ApiStatus" json:"api_status,omitempty"`
	Keyindex  uint32    `protobuf:"varint,2,opt,name=keyindex" json:"keyindex,omitempty"`
}

func (m *CryptoKeyCreateWithIdResponse) Reset()                    { *m = CryptoKeyCreateWithIdResponse{} }
func (m *CryptoKeyCreateWithIdResponse) String() string            { return proto.CompactTextString(m) }
func (*CryptoKeyCreateWithIdResponse) ProtoMessage()               {}
func (*CryptoKeyCreateWithIdResponse) Descriptor() ([]byte, []int) { return fileDescriptor19, []int{6} }

func (m *CryptoKeyCreateWithIdResponse) GetApiStatus() ApiStatus {
	if m != nil {
		return m.ApiStatus
	}
	return ApiStatus_API_STATUS_OK
}

func (m *CryptoKeyCreateWithIdResponse) GetKeyindex() uint32 {
	if m != nil {
		return m.Keyindex
	}
	return 0
}

type CryptoKeyCreateWithIdResponseMsg struct {
	Response []*CryptoKeyCreateWithIdResponse `protobuf:"bytes,1,rep,name=response" json:"response,omitempty"`
}

func (m *CryptoKeyCreateWithIdResponseMsg) Reset()         { *m = CryptoKeyCreateWithIdResponseMsg{} }
func (m *CryptoKeyCreateWithIdResponseMsg) String() string { return proto.CompactTextString(m) }
func (*CryptoKeyCreateWithIdResponseMsg) ProtoMessage()    {}
func (*CryptoKeyCreateWithIdResponseMsg) Descriptor() ([]byte, []int) {
	return fileDescriptor19, []int{7}
}

func (m *CryptoKeyCreateWithIdResponseMsg) GetResponse() []*CryptoKeyCreateWithIdResponse {
	if m != nil {
		return m.Response
	}
	return nil
}

type CryptoKeySpec struct {
	Keyindex uint32        `protobuf:"varint,1,opt,name=keyindex" json:"keyindex,omitempty"`
	KeyType  CryptoKeyType `protobuf:"varint,2,opt,name=key_type,json=keyType,enum=types.CryptoKeyType" json:"key_type,omitempty"`
	KeySize  uint32        `protobuf:"varint,3,opt,name=key_size,json=keySize" json:"key_size,omitempty"`
	Key      []byte        `protobuf:"bytes,4,opt,name=key,proto3" json:"key,omitempty"`
}

func (m *CryptoKeySpec) Reset()                    { *m = CryptoKeySpec{} }
func (m *CryptoKeySpec) String() string            { return proto.CompactTextString(m) }
func (*CryptoKeySpec) ProtoMessage()               {}
func (*CryptoKeySpec) Descriptor() ([]byte, []int) { return fileDescriptor19, []int{8} }

func (m *CryptoKeySpec) GetKeyindex() uint32 {
	if m != nil {
		return m.Keyindex
	}
	return 0
}

func (m *CryptoKeySpec) GetKeyType() CryptoKeyType {
	if m != nil {
		return m.KeyType
	}
	return CryptoKeyType_CRYPTO_KEY_TYPE_AES128
}

func (m *CryptoKeySpec) GetKeySize() uint32 {
	if m != nil {
		return m.KeySize
	}
	return 0
}

func (m *CryptoKeySpec) GetKey() []byte {
	if m != nil {
		return m.Key
	}
	return nil
}

type CryptoKeyReadRequest struct {
	Keyindex uint32 `protobuf:"varint,1,opt,name=keyindex" json:"keyindex,omitempty"`
}

func (m *CryptoKeyReadRequest) Reset()                    { *m = CryptoKeyReadRequest{} }
func (m *CryptoKeyReadRequest) String() string            { return proto.CompactTextString(m) }
func (*CryptoKeyReadRequest) ProtoMessage()               {}
func (*CryptoKeyReadRequest) Descriptor() ([]byte, []int) { return fileDescriptor19, []int{9} }

func (m *CryptoKeyReadRequest) GetKeyindex() uint32 {
	if m != nil {
		return m.Keyindex
	}
	return 0
}

type CryptoKeyReadRequestMsg struct {
	Request []*CryptoKeyReadRequest `protobuf:"bytes,1,rep,name=request" json:"request,omitempty"`
}

func (m *CryptoKeyReadRequestMsg) Reset()                    { *m = CryptoKeyReadRequestMsg{} }
func (m *CryptoKeyReadRequestMsg) String() string            { return proto.CompactTextString(m) }
func (*CryptoKeyReadRequestMsg) ProtoMessage()               {}
func (*CryptoKeyReadRequestMsg) Descriptor() ([]byte, []int) { return fileDescriptor19, []int{10} }

func (m *CryptoKeyReadRequestMsg) GetRequest() []*CryptoKeyReadRequest {
	if m != nil {
		return m.Request
	}
	return nil
}

type CryptoKeyReadResponse struct {
	ApiStatus ApiStatus      `protobuf:"varint,1,opt,name=api_status,json=apiStatus,enum=types.ApiStatus" json:"api_status,omitempty"`
	Key       *CryptoKeySpec `protobuf:"bytes,2,opt,name=key" json:"key,omitempty"`
}

func (m *CryptoKeyReadResponse) Reset()                    { *m = CryptoKeyReadResponse{} }
func (m *CryptoKeyReadResponse) String() string            { return proto.CompactTextString(m) }
func (*CryptoKeyReadResponse) ProtoMessage()               {}
func (*CryptoKeyReadResponse) Descriptor() ([]byte, []int) { return fileDescriptor19, []int{11} }

func (m *CryptoKeyReadResponse) GetApiStatus() ApiStatus {
	if m != nil {
		return m.ApiStatus
	}
	return ApiStatus_API_STATUS_OK
}

func (m *CryptoKeyReadResponse) GetKey() *CryptoKeySpec {
	if m != nil {
		return m.Key
	}
	return nil
}

type CryptoKeyReadResponseMsg struct {
	Response []*CryptoKeyReadResponse `protobuf:"bytes,1,rep,name=response" json:"response,omitempty"`
}

func (m *CryptoKeyReadResponseMsg) Reset()                    { *m = CryptoKeyReadResponseMsg{} }
func (m *CryptoKeyReadResponseMsg) String() string            { return proto.CompactTextString(m) }
func (*CryptoKeyReadResponseMsg) ProtoMessage()               {}
func (*CryptoKeyReadResponseMsg) Descriptor() ([]byte, []int) { return fileDescriptor19, []int{12} }

func (m *CryptoKeyReadResponseMsg) GetResponse() []*CryptoKeyReadResponse {
	if m != nil {
		return m.Response
	}
	return nil
}

type CryptoKeyUpdateRequest struct {
	Key *CryptoKeySpec `protobuf:"bytes,1,opt,name=key" json:"key,omitempty"`
}

func (m *CryptoKeyUpdateRequest) Reset()                    { *m = CryptoKeyUpdateRequest{} }
func (m *CryptoKeyUpdateRequest) String() string            { return proto.CompactTextString(m) }
func (*CryptoKeyUpdateRequest) ProtoMessage()               {}
func (*CryptoKeyUpdateRequest) Descriptor() ([]byte, []int) { return fileDescriptor19, []int{13} }

func (m *CryptoKeyUpdateRequest) GetKey() *CryptoKeySpec {
	if m != nil {
		return m.Key
	}
	return nil
}

type CryptoKeyUpdateRequestMsg struct {
	Request []*CryptoKeyUpdateRequest `protobuf:"bytes,1,rep,name=request" json:"request,omitempty"`
}

func (m *CryptoKeyUpdateRequestMsg) Reset()                    { *m = CryptoKeyUpdateRequestMsg{} }
func (m *CryptoKeyUpdateRequestMsg) String() string            { return proto.CompactTextString(m) }
func (*CryptoKeyUpdateRequestMsg) ProtoMessage()               {}
func (*CryptoKeyUpdateRequestMsg) Descriptor() ([]byte, []int) { return fileDescriptor19, []int{14} }

func (m *CryptoKeyUpdateRequestMsg) GetRequest() []*CryptoKeyUpdateRequest {
	if m != nil {
		return m.Request
	}
	return nil
}

type CryptoKeyUpdateResponse struct {
	ApiStatus ApiStatus `protobuf:"varint,1,opt,name=api_status,json=apiStatus,enum=types.ApiStatus" json:"api_status,omitempty"`
	Keyindex  uint32    `protobuf:"varint,2,opt,name=keyindex" json:"keyindex,omitempty"`
}

func (m *CryptoKeyUpdateResponse) Reset()                    { *m = CryptoKeyUpdateResponse{} }
func (m *CryptoKeyUpdateResponse) String() string            { return proto.CompactTextString(m) }
func (*CryptoKeyUpdateResponse) ProtoMessage()               {}
func (*CryptoKeyUpdateResponse) Descriptor() ([]byte, []int) { return fileDescriptor19, []int{15} }

func (m *CryptoKeyUpdateResponse) GetApiStatus() ApiStatus {
	if m != nil {
		return m.ApiStatus
	}
	return ApiStatus_API_STATUS_OK
}

func (m *CryptoKeyUpdateResponse) GetKeyindex() uint32 {
	if m != nil {
		return m.Keyindex
	}
	return 0
}

type CryptoKeyUpdateResponseMsg struct {
	Response []*CryptoKeyUpdateResponse `protobuf:"bytes,1,rep,name=response" json:"response,omitempty"`
}

func (m *CryptoKeyUpdateResponseMsg) Reset()                    { *m = CryptoKeyUpdateResponseMsg{} }
func (m *CryptoKeyUpdateResponseMsg) String() string            { return proto.CompactTextString(m) }
func (*CryptoKeyUpdateResponseMsg) ProtoMessage()               {}
func (*CryptoKeyUpdateResponseMsg) Descriptor() ([]byte, []int) { return fileDescriptor19, []int{16} }

func (m *CryptoKeyUpdateResponseMsg) GetResponse() []*CryptoKeyUpdateResponse {
	if m != nil {
		return m.Response
	}
	return nil
}

type CryptoKeyDeleteRequest struct {
	Keyindex uint32 `protobuf:"varint,1,opt,name=keyindex" json:"keyindex,omitempty"`
}

func (m *CryptoKeyDeleteRequest) Reset()                    { *m = CryptoKeyDeleteRequest{} }
func (m *CryptoKeyDeleteRequest) String() string            { return proto.CompactTextString(m) }
func (*CryptoKeyDeleteRequest) ProtoMessage()               {}
func (*CryptoKeyDeleteRequest) Descriptor() ([]byte, []int) { return fileDescriptor19, []int{17} }

func (m *CryptoKeyDeleteRequest) GetKeyindex() uint32 {
	if m != nil {
		return m.Keyindex
	}
	return 0
}

type CryptoKeyDeleteRequestMsg struct {
	Request []*CryptoKeyDeleteRequest `protobuf:"bytes,1,rep,name=request" json:"request,omitempty"`
}

func (m *CryptoKeyDeleteRequestMsg) Reset()                    { *m = CryptoKeyDeleteRequestMsg{} }
func (m *CryptoKeyDeleteRequestMsg) String() string            { return proto.CompactTextString(m) }
func (*CryptoKeyDeleteRequestMsg) ProtoMessage()               {}
func (*CryptoKeyDeleteRequestMsg) Descriptor() ([]byte, []int) { return fileDescriptor19, []int{18} }

func (m *CryptoKeyDeleteRequestMsg) GetRequest() []*CryptoKeyDeleteRequest {
	if m != nil {
		return m.Request
	}
	return nil
}

type CryptoKeyDeleteResponse struct {
	ApiStatus ApiStatus `protobuf:"varint,1,opt,name=api_status,json=apiStatus,enum=types.ApiStatus" json:"api_status,omitempty"`
	Keyindex  uint32    `protobuf:"varint,2,opt,name=keyindex" json:"keyindex,omitempty"`
}

func (m *CryptoKeyDeleteResponse) Reset()                    { *m = CryptoKeyDeleteResponse{} }
func (m *CryptoKeyDeleteResponse) String() string            { return proto.CompactTextString(m) }
func (*CryptoKeyDeleteResponse) ProtoMessage()               {}
func (*CryptoKeyDeleteResponse) Descriptor() ([]byte, []int) { return fileDescriptor19, []int{19} }

func (m *CryptoKeyDeleteResponse) GetApiStatus() ApiStatus {
	if m != nil {
		return m.ApiStatus
	}
	return ApiStatus_API_STATUS_OK
}

func (m *CryptoKeyDeleteResponse) GetKeyindex() uint32 {
	if m != nil {
		return m.Keyindex
	}
	return 0
}

type CryptoKeyDeleteResponseMsg struct {
	Response []*CryptoKeyDeleteResponse `protobuf:"bytes,1,rep,name=response" json:"response,omitempty"`
}

func (m *CryptoKeyDeleteResponseMsg) Reset()                    { *m = CryptoKeyDeleteResponseMsg{} }
func (m *CryptoKeyDeleteResponseMsg) String() string            { return proto.CompactTextString(m) }
func (*CryptoKeyDeleteResponseMsg) ProtoMessage()               {}
func (*CryptoKeyDeleteResponseMsg) Descriptor() ([]byte, []int) { return fileDescriptor19, []int{20} }

func (m *CryptoKeyDeleteResponseMsg) GetResponse() []*CryptoKeyDeleteResponse {
	if m != nil {
		return m.Response
	}
	return nil
}

func init() {
	proto.RegisterType((*CryptoKeyCreateRequest)(nil), "halproto.CryptoKeyCreateRequest")
	proto.RegisterType((*CryptoKeyCreateRequestMsg)(nil), "halproto.CryptoKeyCreateRequestMsg")
	proto.RegisterType((*CryptoKeyCreateResponse)(nil), "halproto.CryptoKeyCreateResponse")
	proto.RegisterType((*CryptoKeyCreateResponseMsg)(nil), "halproto.CryptoKeyCreateResponseMsg")
	proto.RegisterType((*CryptoKeyCreateWithIdRequest)(nil), "halproto.CryptoKeyCreateWithIdRequest")
	proto.RegisterType((*CryptoKeyCreateWithIdRequestMsg)(nil), "halproto.CryptoKeyCreateWithIdRequestMsg")
	proto.RegisterType((*CryptoKeyCreateWithIdResponse)(nil), "halproto.CryptoKeyCreateWithIdResponse")
	proto.RegisterType((*CryptoKeyCreateWithIdResponseMsg)(nil), "halproto.CryptoKeyCreateWithIdResponseMsg")
	proto.RegisterType((*CryptoKeySpec)(nil), "halproto.CryptoKeySpec")
	proto.RegisterType((*CryptoKeyReadRequest)(nil), "halproto.CryptoKeyReadRequest")
	proto.RegisterType((*CryptoKeyReadRequestMsg)(nil), "halproto.CryptoKeyReadRequestMsg")
	proto.RegisterType((*CryptoKeyReadResponse)(nil), "halproto.CryptoKeyReadResponse")
	proto.RegisterType((*CryptoKeyReadResponseMsg)(nil), "halproto.CryptoKeyReadResponseMsg")
	proto.RegisterType((*CryptoKeyUpdateRequest)(nil), "halproto.CryptoKeyUpdateRequest")
	proto.RegisterType((*CryptoKeyUpdateRequestMsg)(nil), "halproto.CryptoKeyUpdateRequestMsg")
	proto.RegisterType((*CryptoKeyUpdateResponse)(nil), "halproto.CryptoKeyUpdateResponse")
	proto.RegisterType((*CryptoKeyUpdateResponseMsg)(nil), "halproto.CryptoKeyUpdateResponseMsg")
	proto.RegisterType((*CryptoKeyDeleteRequest)(nil), "halproto.CryptoKeyDeleteRequest")
	proto.RegisterType((*CryptoKeyDeleteRequestMsg)(nil), "halproto.CryptoKeyDeleteRequestMsg")
	proto.RegisterType((*CryptoKeyDeleteResponse)(nil), "halproto.CryptoKeyDeleteResponse")
	proto.RegisterType((*CryptoKeyDeleteResponseMsg)(nil), "halproto.CryptoKeyDeleteResponseMsg")
}

func init() { proto.RegisterFile("crypto_keys.proto", fileDescriptor19) }

var fileDescriptor19 = []byte{
	// 617 bytes of a gzipped FileDescriptorProto
	0x1f, 0x8b, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xff, 0xb4, 0x56, 0xdf, 0x6f, 0xd3, 0x3c,
	0x14, 0x5d, 0xbe, 0x4e, 0xdf, 0xda, 0x5b, 0xba, 0x0d, 0x6b, 0x40, 0x5a, 0x81, 0x16, 0xcc, 0xaf,
	0x6a, 0x48, 0x9d, 0x14, 0x78, 0x41, 0x20, 0xa4, 0xb2, 0xbe, 0x20, 0xd4, 0x97, 0x74, 0x88, 0x69,
	0x42, 0x2a, 0x59, 0x6b, 0xda, 0xa8, 0xd5, 0x6a, 0xe2, 0x54, 0x90, 0xbd, 0xf1, 0xc8, 0x7f, 0x8d,
	0x1c, 0xa7, 0xa9, 0x9d, 0xb8, 0x49, 0x86, 0xd4, 0xa7, 0x3a, 0xf6, 0xbd, 0x3e, 0xf7, 0x9c, 0x6b,
	0x1f, 0x17, 0xee, 0x8e, 0xfc, 0x90, 0x06, 0x8b, 0xe1, 0x8c, 0x84, 0xac, 0x43, 0xfd, 0x45, 0xb0,
	0x40, 0x35, 0x31, 0x35, 0x23, 0x61, 0xab, 0x1e, 0x84, 0x94, 0xc4, 0xf3, 0xd8, 0x84, 0xfb, 0x67,
	0xd1, 0xca, 0x27, 0x12, 0x9e, 0xf9, 0xc4, 0x0d, 0x88, 0x43, 0x7e, 0x2c, 0x09, 0x0b, 0xf0, 0x05,
	0x34, 0xf5, 0x2b, 0x7d, 0x36, 0x41, 0x6f, 0x61, 0xcf, 0x17, 0x5f, 0xa6, 0x61, 0x55, 0xda, 0x75,
	0xfb, 0x71, 0x27, 0x01, 0xe8, 0xe8, 0xd3, 0x9c, 0x55, 0x06, 0xfe, 0x0e, 0x0f, 0x32, 0x21, 0x8c,
	0x2e, 0xae, 0x19, 0x41, 0xa7, 0x00, 0x2e, 0xf5, 0x86, 0x2c, 0x70, 0x83, 0x25, 0x33, 0x0d, 0xcb,
	0x68, 0xef, 0xdb, 0x87, 0x1d, 0x51, 0x70, 0x97, 0x7a, 0x83, 0x68, 0xde, 0xa9, 0xb9, 0xab, 0x21,
	0x6a, 0x41, 0x75, 0x46, 0x42, 0xef, 0x7a, 0x4c, 0x7e, 0x99, 0xff, 0x59, 0x46, 0xbb, 0xe1, 0x24,
	0xdf, 0xf8, 0x2b, 0xb4, 0x36, 0xe0, 0x70, 0x0a, 0xef, 0xa1, 0xea, 0xc7, 0x9f, 0x31, 0x07, 0x9c,
	0xc7, 0x41, 0x44, 0x3a, 0x49, 0x0e, 0xbe, 0x82, 0x87, 0xa9, 0xa0, 0x2f, 0x5e, 0x30, 0xfd, 0x38,
	0x8e, 0xe9, 0x2a, 0x95, 0x19, 0x6a, 0x65, 0xe8, 0x39, 0x1c, 0xb8, 0xf3, 0xf9, 0xe2, 0xe7, 0x70,
	0xbc, 0xa4, 0x43, 0x3e, 0x1a, 0xc5, 0xc5, 0x37, 0xa2, 0xe9, 0xde, 0x92, 0x76, 0xf9, 0x24, 0x1e,
	0xc3, 0x71, 0x1e, 0x06, 0xa7, 0xd1, 0x4d, 0x77, 0xe2, 0xc5, 0x66, 0x16, 0x4a, 0xf2, 0xba, 0x1f,
	0x73, 0x78, 0xb4, 0x21, 0x70, 0x1b, 0x5d, 0x99, 0x82, 0x95, 0x8b, 0xc6, 0x49, 0xf5, 0x32, 0xbd,
	0x69, 0x17, 0xb3, 0xca, 0x74, 0xe8, 0x8f, 0x01, 0x8d, 0x24, 0x76, 0x40, 0xc9, 0x28, 0xb7, 0x27,
	0xa7, 0xd1, 0xda, 0x90, 0xb3, 0x8a, 0x6a, 0xde, 0xb7, 0x8f, 0x62, 0x8a, 0xc9, 0x1e, 0xe7, 0x21,
	0x25, 0xce, 0xde, 0x4c, 0x0c, 0x50, 0x53, 0x24, 0x30, 0xef, 0x86, 0x98, 0x95, 0x68, 0x33, 0xbe,
	0x34, 0xf0, 0x6e, 0x08, 0x3a, 0x84, 0xca, 0x8c, 0x84, 0xe6, 0xae, 0x65, 0xb4, 0xef, 0x38, 0x7c,
	0x88, 0x6d, 0x38, 0x4a, 0xb6, 0x71, 0x88, 0x5b, 0xe6, 0x94, 0xe0, 0x73, 0xe9, 0x9e, 0x48, 0x39,
	0x5c, 0xa0, 0x37, 0xe9, 0xae, 0x1f, 0xeb, 0xf4, 0x91, 0x92, 0xd6, 0xdd, 0x0e, 0xe0, 0x5e, 0x2a,
	0xe0, 0x5f, 0xbb, 0x7c, 0x22, 0x58, 0x72, 0xb1, 0xea, 0xb6, 0xa9, 0x2b, 0x80, 0x8b, 0x2e, 0xf8,
	0x5f, 0x80, 0xa9, 0x45, 0xe5, 0x64, 0xde, 0x65, 0xba, 0x6d, 0x6d, 0x66, 0x93, 0xe9, 0x72, 0x4f,
	0x72, 0xb0, 0xcf, 0x74, 0xbc, 0x36, 0x9c, 0x55, 0x7d, 0x46, 0xb9, 0xfa, 0x9a, 0xfa, 0x5d, 0xca,
	0xbb, 0x9d, 0x92, 0xa6, 0x77, 0xbb, 0x55, 0xc8, 0xb6, 0xdd, 0x4e, 0xc5, 0xb9, 0x85, 0xdb, 0xa9,
	0x89, 0x92, 0xca, 0xaf, 0x25, 0x95, 0x7b, 0x64, 0x4e, 0xd6, 0x2a, 0xe7, 0x9d, 0x60, 0x59, 0x55,
	0x25, 0xab, 0xbc, 0xaa, 0x4a, 0x9a, 0x5e, 0xd5, 0x55, 0xc8, 0xb6, 0x55, 0x55, 0x71, 0x6e, 0xa1,
	0xaa, 0x9a, 0xb8, 0x56, 0xd5, 0xfe, 0xbd, 0x0b, 0xb5, 0x24, 0x0a, 0x7d, 0x83, 0x83, 0x94, 0xb5,
	0xa1, 0xa7, 0x85, 0xcf, 0x6a, 0x9f, 0x4d, 0x5a, 0xcf, 0x8a, 0x1f, 0xae, 0x3e, 0x9b, 0xe0, 0x1d,
	0xe4, 0x4b, 0x77, 0x5f, 0x36, 0x4f, 0x74, 0x52, 0xf2, 0xd1, 0xe0, 0x68, 0x2f, 0xcb, 0x5a, 0xb1,
	0xc0, 0xbc, 0x94, 0x4c, 0x98, 0x5f, 0x61, 0x84, 0x0b, 0xac, 0x8a, 0x63, 0x3c, 0x29, 0x32, 0x00,
	0xb1, 0xb7, 0xac, 0x98, 0x38, 0xba, 0x7a, 0xc5, 0xd2, 0x37, 0x5a, 0xaf, 0x58, 0xe6, 0xd6, 0xa4,
	0x10, 0x44, 0x1b, 0xf5, 0x08, 0xe9, 0xd3, 0xad, 0x47, 0xc8, 0x9c, 0x20, 0xbc, 0xf3, 0x01, 0x2e,
	0xab, 0x53, 0x77, 0x1e, 0xfd, 0x1b, 0xbb, 0xfa, 0x3f, 0xfa, 0x79, 0xf5, 0x37, 0x00, 0x00, 0xff,
	0xff, 0x16, 0xab, 0x7a, 0xd6, 0xc1, 0x09, 0x00, 0x00,
}
