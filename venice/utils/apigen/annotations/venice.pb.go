// Code generated by protoc-gen-gogo. DO NOT EDIT.
// source: venice.proto

/*
	Package venice is a generated protocol buffer package.

	It is generated from these files:
		venice.proto

	It has these top-level messages:
		ObjectRln
		RestEndpoint
*/
package venice

import proto "github.com/gogo/protobuf/proto"
import fmt "fmt"
import math "math"
import google_protobuf "github.com/gogo/protobuf/protoc-gen-gogo/descriptor"

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

type ObjectRln struct {
	// Type of reference one of [ NamedRef, SelectorRef, BackRef ]
	Type string `protobuf:"bytes,1,opt,name=Type,proto3" json:"Type,omitempty"`
	// Object being referred to.
	To string `protobuf:"bytes,2,opt,name=To,proto3" json:"To,omitempty"`
}

func (m *ObjectRln) Reset()                    { *m = ObjectRln{} }
func (m *ObjectRln) String() string            { return proto.CompactTextString(m) }
func (*ObjectRln) ProtoMessage()               {}
func (*ObjectRln) Descriptor() ([]byte, []int) { return fileDescriptorVenice, []int{0} }

func (m *ObjectRln) GetType() string {
	if m != nil {
		return m.Type
	}
	return ""
}

func (m *ObjectRln) GetTo() string {
	if m != nil {
		return m.To
	}
	return ""
}

// RestEndpoint is used by the venice.apiRestservice option to specify REST resources to be exposed.
type RestEndpoint struct {
	// Object for which the endpoint is being defined
	Object string `protobuf:"bytes,1,opt,name=Object,proto3" json:"Object,omitempty"`
	// Methods allowed on the resource
	Method []string `protobuf:"bytes,2,rep,name=Method" json:"Method,omitempty"`
	// Pattern for the URI
	Pattern string `protobuf:"bytes,3,opt,name=Pattern,proto3" json:"Pattern,omitempty"`
}

func (m *RestEndpoint) Reset()                    { *m = RestEndpoint{} }
func (m *RestEndpoint) String() string            { return proto.CompactTextString(m) }
func (*RestEndpoint) ProtoMessage()               {}
func (*RestEndpoint) Descriptor() ([]byte, []int) { return fileDescriptorVenice, []int{1} }

func (m *RestEndpoint) GetObject() string {
	if m != nil {
		return m.Object
	}
	return ""
}

func (m *RestEndpoint) GetMethod() []string {
	if m != nil {
		return m.Method
	}
	return nil
}

func (m *RestEndpoint) GetPattern() string {
	if m != nil {
		return m.Pattern
	}
	return ""
}

var E_FileGrpcDest = &proto.ExtensionDesc{
	ExtendedType:  (*google_protobuf.FileOptions)(nil),
	ExtensionType: (*string)(nil),
	Field:         51235,
	Name:          "venice.fileGrpcDest",
	Tag:           "bytes,51235,opt,name=fileGrpcDest",
	Filename:      "venice.proto",
}

var E_ApiVersion = &proto.ExtensionDesc{
	ExtendedType:  (*google_protobuf.ServiceOptions)(nil),
	ExtensionType: (*string)(nil),
	Field:         51250,
	Name:          "venice.apiVersion",
	Tag:           "bytes,51250,opt,name=apiVersion",
	Filename:      "venice.proto",
}

var E_ApiPrefix = &proto.ExtensionDesc{
	ExtendedType:  (*google_protobuf.ServiceOptions)(nil),
	ExtensionType: (*string)(nil),
	Field:         51251,
	Name:          "venice.apiPrefix",
	Tag:           "bytes,51251,opt,name=apiPrefix",
	Filename:      "venice.proto",
}

var E_ApiGrpcCrudService = &proto.ExtensionDesc{
	ExtendedType:  (*google_protobuf.ServiceOptions)(nil),
	ExtensionType: ([]string)(nil),
	Field:         51252,
	Name:          "venice.apiGrpcCrudService",
	Tag:           "bytes,51252,rep,name=apiGrpcCrudService",
	Filename:      "venice.proto",
}

var E_ApiRestService = &proto.ExtensionDesc{
	ExtendedType:  (*google_protobuf.ServiceOptions)(nil),
	ExtensionType: ([]*RestEndpoint)(nil),
	Field:         51253,
	Name:          "venice.apiRestService",
	Tag:           "bytes,51253,rep,name=apiRestService",
	Filename:      "venice.proto",
}

var E_MethodOper = &proto.ExtensionDesc{
	ExtendedType:  (*google_protobuf.MethodOptions)(nil),
	ExtensionType: (*string)(nil),
	Field:         51270,
	Name:          "venice.methodOper",
	Tag:           "bytes,51270,opt,name=methodOper",
	Filename:      "venice.proto",
}

var E_MethodAutoGen = &proto.ExtensionDesc{
	ExtendedType:  (*google_protobuf.MethodOptions)(nil),
	ExtensionType: (*bool)(nil),
	Field:         41291,
	Name:          "venice.methodAutoGen",
	Tag:           "varint,41291,opt,name=methodAutoGen",
	Filename:      "venice.proto",
}

var E_ObjectPrefix = &proto.ExtensionDesc{
	ExtendedType:  (*google_protobuf.MessageOptions)(nil),
	ExtensionType: (*string)(nil),
	Field:         51290,
	Name:          "venice.objectPrefix",
	Tag:           "bytes,51290,opt,name=objectPrefix",
	Filename:      "venice.proto",
}

var E_ObjectAutoGen = &proto.ExtensionDesc{
	ExtendedType:  (*google_protobuf.MessageOptions)(nil),
	ExtensionType: (*string)(nil),
	Field:         41291,
	Name:          "venice.objectAutoGen",
	Tag:           "bytes,41291,opt,name=objectAutoGen",
	Filename:      "venice.proto",
}

var E_ObjRelation = &proto.ExtensionDesc{
	ExtendedType:  (*google_protobuf.FieldOptions)(nil),
	ExtensionType: (*ObjectRln)(nil),
	Field:         51300,
	Name:          "venice.objRelation",
	Tag:           "bytes,51300,opt,name=objRelation",
	Filename:      "venice.proto",
}

var E_Check = &proto.ExtensionDesc{
	ExtendedType:  (*google_protobuf.FieldOptions)(nil),
	ExtensionType: ([]string)(nil),
	Field:         51301,
	Name:          "venice.check",
	Tag:           "bytes,51301,rep,name=check",
	Filename:      "venice.proto",
}

func init() {
	proto.RegisterType((*ObjectRln)(nil), "venice.ObjectRln")
	proto.RegisterType((*RestEndpoint)(nil), "venice.RestEndpoint")
	proto.RegisterExtension(E_FileGrpcDest)
	proto.RegisterExtension(E_ApiVersion)
	proto.RegisterExtension(E_ApiPrefix)
	proto.RegisterExtension(E_ApiGrpcCrudService)
	proto.RegisterExtension(E_ApiRestService)
	proto.RegisterExtension(E_MethodOper)
	proto.RegisterExtension(E_MethodAutoGen)
	proto.RegisterExtension(E_ObjectPrefix)
	proto.RegisterExtension(E_ObjectAutoGen)
	proto.RegisterExtension(E_ObjRelation)
	proto.RegisterExtension(E_Check)
}
func (m *ObjectRln) Marshal() (dAtA []byte, err error) {
	size := m.Size()
	dAtA = make([]byte, size)
	n, err := m.MarshalTo(dAtA)
	if err != nil {
		return nil, err
	}
	return dAtA[:n], nil
}

func (m *ObjectRln) MarshalTo(dAtA []byte) (int, error) {
	var i int
	_ = i
	var l int
	_ = l
	if len(m.Type) > 0 {
		dAtA[i] = 0xa
		i++
		i = encodeVarintVenice(dAtA, i, uint64(len(m.Type)))
		i += copy(dAtA[i:], m.Type)
	}
	if len(m.To) > 0 {
		dAtA[i] = 0x12
		i++
		i = encodeVarintVenice(dAtA, i, uint64(len(m.To)))
		i += copy(dAtA[i:], m.To)
	}
	return i, nil
}

func (m *RestEndpoint) Marshal() (dAtA []byte, err error) {
	size := m.Size()
	dAtA = make([]byte, size)
	n, err := m.MarshalTo(dAtA)
	if err != nil {
		return nil, err
	}
	return dAtA[:n], nil
}

func (m *RestEndpoint) MarshalTo(dAtA []byte) (int, error) {
	var i int
	_ = i
	var l int
	_ = l
	if len(m.Object) > 0 {
		dAtA[i] = 0xa
		i++
		i = encodeVarintVenice(dAtA, i, uint64(len(m.Object)))
		i += copy(dAtA[i:], m.Object)
	}
	if len(m.Method) > 0 {
		for _, s := range m.Method {
			dAtA[i] = 0x12
			i++
			l = len(s)
			for l >= 1<<7 {
				dAtA[i] = uint8(uint64(l)&0x7f | 0x80)
				l >>= 7
				i++
			}
			dAtA[i] = uint8(l)
			i++
			i += copy(dAtA[i:], s)
		}
	}
	if len(m.Pattern) > 0 {
		dAtA[i] = 0x1a
		i++
		i = encodeVarintVenice(dAtA, i, uint64(len(m.Pattern)))
		i += copy(dAtA[i:], m.Pattern)
	}
	return i, nil
}

func encodeFixed64Venice(dAtA []byte, offset int, v uint64) int {
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
func encodeFixed32Venice(dAtA []byte, offset int, v uint32) int {
	dAtA[offset] = uint8(v)
	dAtA[offset+1] = uint8(v >> 8)
	dAtA[offset+2] = uint8(v >> 16)
	dAtA[offset+3] = uint8(v >> 24)
	return offset + 4
}
func encodeVarintVenice(dAtA []byte, offset int, v uint64) int {
	for v >= 1<<7 {
		dAtA[offset] = uint8(v&0x7f | 0x80)
		v >>= 7
		offset++
	}
	dAtA[offset] = uint8(v)
	return offset + 1
}
func (m *ObjectRln) Size() (n int) {
	var l int
	_ = l
	l = len(m.Type)
	if l > 0 {
		n += 1 + l + sovVenice(uint64(l))
	}
	l = len(m.To)
	if l > 0 {
		n += 1 + l + sovVenice(uint64(l))
	}
	return n
}

func (m *RestEndpoint) Size() (n int) {
	var l int
	_ = l
	l = len(m.Object)
	if l > 0 {
		n += 1 + l + sovVenice(uint64(l))
	}
	if len(m.Method) > 0 {
		for _, s := range m.Method {
			l = len(s)
			n += 1 + l + sovVenice(uint64(l))
		}
	}
	l = len(m.Pattern)
	if l > 0 {
		n += 1 + l + sovVenice(uint64(l))
	}
	return n
}

func sovVenice(x uint64) (n int) {
	for {
		n++
		x >>= 7
		if x == 0 {
			break
		}
	}
	return n
}
func sozVenice(x uint64) (n int) {
	return sovVenice(uint64((x << 1) ^ uint64((int64(x) >> 63))))
}
func (m *ObjectRln) Unmarshal(dAtA []byte) error {
	l := len(dAtA)
	iNdEx := 0
	for iNdEx < l {
		preIndex := iNdEx
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return ErrIntOverflowVenice
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
			return fmt.Errorf("proto: ObjectRln: wiretype end group for non-group")
		}
		if fieldNum <= 0 {
			return fmt.Errorf("proto: ObjectRln: illegal tag %d (wire type %d)", fieldNum, wire)
		}
		switch fieldNum {
		case 1:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field Type", wireType)
			}
			var stringLen uint64
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowVenice
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
				return ErrInvalidLengthVenice
			}
			postIndex := iNdEx + intStringLen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.Type = string(dAtA[iNdEx:postIndex])
			iNdEx = postIndex
		case 2:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field To", wireType)
			}
			var stringLen uint64
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowVenice
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
				return ErrInvalidLengthVenice
			}
			postIndex := iNdEx + intStringLen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.To = string(dAtA[iNdEx:postIndex])
			iNdEx = postIndex
		default:
			iNdEx = preIndex
			skippy, err := skipVenice(dAtA[iNdEx:])
			if err != nil {
				return err
			}
			if skippy < 0 {
				return ErrInvalidLengthVenice
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
func (m *RestEndpoint) Unmarshal(dAtA []byte) error {
	l := len(dAtA)
	iNdEx := 0
	for iNdEx < l {
		preIndex := iNdEx
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return ErrIntOverflowVenice
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
			return fmt.Errorf("proto: RestEndpoint: wiretype end group for non-group")
		}
		if fieldNum <= 0 {
			return fmt.Errorf("proto: RestEndpoint: illegal tag %d (wire type %d)", fieldNum, wire)
		}
		switch fieldNum {
		case 1:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field Object", wireType)
			}
			var stringLen uint64
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowVenice
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
				return ErrInvalidLengthVenice
			}
			postIndex := iNdEx + intStringLen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.Object = string(dAtA[iNdEx:postIndex])
			iNdEx = postIndex
		case 2:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field Method", wireType)
			}
			var stringLen uint64
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowVenice
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
				return ErrInvalidLengthVenice
			}
			postIndex := iNdEx + intStringLen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.Method = append(m.Method, string(dAtA[iNdEx:postIndex]))
			iNdEx = postIndex
		case 3:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field Pattern", wireType)
			}
			var stringLen uint64
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowVenice
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
				return ErrInvalidLengthVenice
			}
			postIndex := iNdEx + intStringLen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.Pattern = string(dAtA[iNdEx:postIndex])
			iNdEx = postIndex
		default:
			iNdEx = preIndex
			skippy, err := skipVenice(dAtA[iNdEx:])
			if err != nil {
				return err
			}
			if skippy < 0 {
				return ErrInvalidLengthVenice
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
func skipVenice(dAtA []byte) (n int, err error) {
	l := len(dAtA)
	iNdEx := 0
	for iNdEx < l {
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return 0, ErrIntOverflowVenice
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
					return 0, ErrIntOverflowVenice
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
					return 0, ErrIntOverflowVenice
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
				return 0, ErrInvalidLengthVenice
			}
			return iNdEx, nil
		case 3:
			for {
				var innerWire uint64
				var start int = iNdEx
				for shift := uint(0); ; shift += 7 {
					if shift >= 64 {
						return 0, ErrIntOverflowVenice
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
				next, err := skipVenice(dAtA[start:])
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
	ErrInvalidLengthVenice = fmt.Errorf("proto: negative length found during unmarshaling")
	ErrIntOverflowVenice   = fmt.Errorf("proto: integer overflow")
)

func init() { proto.RegisterFile("venice.proto", fileDescriptorVenice) }

var fileDescriptorVenice = []byte{
	// 470 bytes of a gzipped FileDescriptorProto
	0x1f, 0x8b, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xff, 0x8c, 0x93, 0xbd, 0x6e, 0x13, 0x41,
	0x10, 0x80, 0x39, 0x1b, 0x0c, 0x1e, 0x3b, 0x11, 0xac, 0x10, 0x3a, 0x21, 0x38, 0xac, 0x54, 0x54,
	0x67, 0x29, 0x88, 0x66, 0x1b, 0x48, 0x20, 0x71, 0x65, 0x39, 0x2c, 0x16, 0xa2, 0x43, 0xe7, 0xf3,
	0xd8, 0xd9, 0x70, 0xec, 0xae, 0xf6, 0xd6, 0x11, 0xbc, 0x45, 0x4a, 0x7a, 0xde, 0x80, 0x9f, 0x17,
	0xa0, 0x40, 0x48, 0x34, 0xd4, 0x54, 0xc8, 0xc0, 0x7b, 0xa0, 0xdb, 0xdd, 0x73, 0x6c, 0x62, 0x74,
	0xe9, 0x3c, 0xe3, 0xf9, 0x3e, 0xcd, 0xce, 0xcc, 0x41, 0xfb, 0x18, 0x05, 0x4f, 0x31, 0x56, 0x5a,
	0x1a, 0x49, 0x1a, 0x2e, 0xba, 0xd9, 0x99, 0x4a, 0x39, 0xcd, 0xb0, 0x6b, 0xb3, 0xa3, 0xd9, 0xa4,
	0x3b, 0xc6, 0x3c, 0xd5, 0x5c, 0x19, 0xa9, 0x5d, 0xe5, 0x56, 0x17, 0x9a, 0x83, 0xd1, 0x11, 0xa6,
	0x86, 0x65, 0x82, 0x10, 0xb8, 0x38, 0x7c, 0xa3, 0x30, 0x0c, 0x3a, 0xc1, 0xdd, 0x26, 0xb3, 0xbf,
	0xc9, 0x26, 0xd4, 0x86, 0x32, 0xac, 0xd9, 0x4c, 0x6d, 0x28, 0xb7, 0x9e, 0x43, 0x9b, 0x61, 0x6e,
	0xf6, 0xc4, 0x58, 0x49, 0x2e, 0x0c, 0xb9, 0x01, 0x0d, 0x27, 0xf0, 0x94, 0x8f, 0x8a, 0x7c, 0x1f,
	0xcd, 0xa1, 0x1c, 0x87, 0xb5, 0x4e, 0xbd, 0xc8, 0xbb, 0x88, 0x84, 0x70, 0xf9, 0x20, 0x31, 0x06,
	0xb5, 0x08, 0xeb, 0x16, 0x28, 0x43, 0xba, 0x0b, 0xed, 0x09, 0xcf, 0xb0, 0xa7, 0x55, 0xfa, 0x18,
	0x73, 0x43, 0x6e, 0xc5, 0xae, 0xfb, 0xb8, 0xec, 0x3e, 0xde, 0xe7, 0x19, 0x0e, 0x94, 0xe1, 0x52,
	0xe4, 0xe1, 0xbb, 0x13, 0x87, 0xaf, 0x30, 0x74, 0x07, 0x20, 0x51, 0xfc, 0x19, 0xea, 0x9c, 0x4b,
	0x41, 0xee, 0x9c, 0x31, 0x3c, 0x45, 0x7d, 0xcc, 0xd3, 0x85, 0xe4, 0xbd, 0x97, 0x2c, 0x41, 0xf4,
	0x01, 0x34, 0x13, 0xc5, 0x0f, 0x34, 0x4e, 0xf8, 0xeb, 0x6a, 0xc3, 0x07, 0x6f, 0x38, 0x65, 0xe8,
	0x13, 0x20, 0x89, 0xe2, 0x45, 0x4b, 0x8f, 0xf4, 0x6c, 0xec, 0xeb, 0xab, 0x4d, 0x1f, 0x4f, 0xea,
	0x76, 0x50, 0x6b, 0x60, 0xfa, 0x02, 0x36, 0x13, 0xc5, 0x8b, 0xb9, 0x9f, 0x5b, 0xf7, 0xc9, 0xea,
	0x5a, 0xdb, 0xd7, 0x63, 0x7f, 0x19, 0xcb, 0x5b, 0x63, 0xff, 0xe8, 0xe8, 0x43, 0x80, 0x57, 0x76,
	0x3f, 0x03, 0x85, 0x9a, 0x44, 0x67, 0xe4, 0x7d, 0xff, 0xa7, 0x73, 0x7f, 0x29, 0xc7, 0x76, 0xca,
	0xd0, 0x7d, 0xd8, 0x70, 0xd1, 0xce, 0xcc, 0xc8, 0x1e, 0x8a, 0x4a, 0xc9, 0xb7, 0xcf, 0xc5, 0x51,
	0x5d, 0x61, 0xab, 0x18, 0xdd, 0x83, 0xb6, 0xb4, 0x17, 0xf4, 0xdf, 0x0d, 0xf4, 0x31, 0xcf, 0x93,
	0xe9, 0xe2, 0xa1, 0x3f, 0xca, 0x43, 0x58, 0xc6, 0x68, 0x0f, 0x36, 0x5c, 0x5c, 0xb6, 0x53, 0xe9,
	0x71, 0xfd, 0x34, 0xd9, 0x2a, 0x47, 0x87, 0xd0, 0x92, 0xa3, 0x23, 0x86, 0x59, 0x52, 0x94, 0x91,
	0xdb, 0x6b, 0x8e, 0x12, 0xb3, 0xc5, 0xa3, 0x7e, 0xdb, 0x66, 0x5a, 0xdb, 0xd7, 0xca, 0xa9, 0x2f,
	0x3e, 0x2e, 0xb6, 0xac, 0xa1, 0xf7, 0xe1, 0x52, 0x7a, 0x88, 0xe9, 0xcb, 0x2a, 0xdf, 0x1f, 0x7f,
	0x14, 0xae, 0x7a, 0xf7, 0xea, 0xd7, 0x79, 0x14, 0x7c, 0x9f, 0x47, 0xc1, 0xcf, 0x79, 0x14, 0xbc,
	0xfd, 0x15, 0x5d, 0x18, 0x35, 0x2c, 0x77, 0xef, 0x6f, 0x00, 0x00, 0x00, 0xff, 0xff, 0x11, 0x3f,
	0xae, 0x2d, 0x00, 0x04, 0x00, 0x00,
}
