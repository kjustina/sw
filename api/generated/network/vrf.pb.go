// Code generated by protoc-gen-gogo. DO NOT EDIT.
// source: vrf.proto

package network

import proto "github.com/gogo/protobuf/proto"
import fmt "fmt"
import math "math"
import _ "github.com/pensando/grpc-gateway/third_party/googleapis/google/api"
import _ "github.com/pensando/sw/venice/utils/apigen/annotations"
import _ "github.com/gogo/protobuf/gogoproto"
import api "github.com/pensando/sw/api"

import io "io"

// Reference imports to suppress errors if they are not otherwise used.
var _ = proto.Marshal
var _ = fmt.Errorf
var _ = math.Inf

//
type VirtualRouterSpec_VPCTypes int32

const (
	//
	VirtualRouterSpec_Unknown VirtualRouterSpec_VPCTypes = 0
	//
	VirtualRouterSpec_Tenant VirtualRouterSpec_VPCTypes = 1
	//
	VirtualRouterSpec_Infra VirtualRouterSpec_VPCTypes = 2
)

var VirtualRouterSpec_VPCTypes_name = map[int32]string{
	0: "Unknown",
	1: "Tenant",
	2: "Infra",
}
var VirtualRouterSpec_VPCTypes_value = map[string]int32{
	"Unknown": 0,
	"Tenant":  1,
	"Infra":   2,
}

func (VirtualRouterSpec_VPCTypes) EnumDescriptor() ([]byte, []int) {
	return fileDescriptorVrf, []int{1, 0}
}

// VirtualRouter - represents a forwarding instance. Could be multiple per tenant.
type VirtualRouter struct {
	//
	api.TypeMeta `protobuf:"bytes,1,opt,name=T,json=,inline,embedded=T" json:",inline"`
	//
	api.ObjectMeta `protobuf:"bytes,2,opt,name=O,json=meta,omitempty,embedded=O" json:"meta,omitempty"`
	//
	Spec VirtualRouterSpec `protobuf:"bytes,3,opt,name=Spec,json=spec,omitempty" json:"spec,omitempty"`
	//
	Status VirtualRouterStatus `protobuf:"bytes,4,opt,name=Status,json=status,omitempty" json:"status,omitempty"`
}

func (m *VirtualRouter) Reset()                    { *m = VirtualRouter{} }
func (m *VirtualRouter) String() string            { return proto.CompactTextString(m) }
func (*VirtualRouter) ProtoMessage()               {}
func (*VirtualRouter) Descriptor() ([]byte, []int) { return fileDescriptorVrf, []int{0} }

func (m *VirtualRouter) GetSpec() VirtualRouterSpec {
	if m != nil {
		return m.Spec
	}
	return VirtualRouterSpec{}
}

func (m *VirtualRouter) GetStatus() VirtualRouterStatus {
	if m != nil {
		return m.Status
	}
	return VirtualRouterStatus{}
}

//
type VirtualRouterSpec struct {
	//
	Type string `protobuf:"bytes,1,opt,name=Type,json=type,,proto3" json:"type,"`
	// Default Router MAC Address to use for this Virtual Router.
	RouterMACAddress string `protobuf:"bytes,2,opt,name=RouterMACAddress,json=router-mac-address,omitempty,proto3" json:"router-mac-address,omitempty"`
	// VxlAN VNI for the Virtual Router.
	VxLanVNI uint32 `protobuf:"varint,3,opt,name=VxLanVNI,json=vxlan-vni,omitempty,proto3" json:"vxlan-vni,omitempty"`
	// RouteImportExport specifies what routes will be imported to this Router and how routes are tagged when exported.
	RouteImportExport *RDSpec `protobuf:"bytes,4,opt,name=RouteImportExport,json=route-import-export,omitempty" json:"route-import-export,omitempty"`
	// Default IPAM policy for networks belonging to this Virtual Router. Any IPAM Policy specified in the Network overrides this.
	DefaultIPAMPolicy *IPAMPolicy `protobuf:"bytes,5,opt,name=DefaultIPAMPolicy,json=default-ipam-policy,omitempty" json:"default-ipam-policy,omitempty"`
}

func (m *VirtualRouterSpec) Reset()                    { *m = VirtualRouterSpec{} }
func (m *VirtualRouterSpec) String() string            { return proto.CompactTextString(m) }
func (*VirtualRouterSpec) ProtoMessage()               {}
func (*VirtualRouterSpec) Descriptor() ([]byte, []int) { return fileDescriptorVrf, []int{1} }

func (m *VirtualRouterSpec) GetType() string {
	if m != nil {
		return m.Type
	}
	return ""
}

func (m *VirtualRouterSpec) GetRouterMACAddress() string {
	if m != nil {
		return m.RouterMACAddress
	}
	return ""
}

func (m *VirtualRouterSpec) GetVxLanVNI() uint32 {
	if m != nil {
		return m.VxLanVNI
	}
	return 0
}

func (m *VirtualRouterSpec) GetRouteImportExport() *RDSpec {
	if m != nil {
		return m.RouteImportExport
	}
	return nil
}

func (m *VirtualRouterSpec) GetDefaultIPAMPolicy() *IPAMPolicy {
	if m != nil {
		return m.DefaultIPAMPolicy
	}
	return nil
}

//
type VirtualRouterStatus struct {
	// Handle allocated in the system.
	Handle uint64 `protobuf:"varint,1,opt,name=Handle,json=id,omitempty,proto3" json:"id,omitempty"`
	//
	RouteTable string `protobuf:"bytes,2,opt,name=RouteTable,json=route-table,omitempty,proto3" json:"route-table,omitempty"`
	//
	RD *RouteDistinguisher `protobuf:"bytes,3,opt,name=RD,json=rd,omitempty" json:"rd,omitempty"`
}

func (m *VirtualRouterStatus) Reset()                    { *m = VirtualRouterStatus{} }
func (m *VirtualRouterStatus) String() string            { return proto.CompactTextString(m) }
func (*VirtualRouterStatus) ProtoMessage()               {}
func (*VirtualRouterStatus) Descriptor() ([]byte, []int) { return fileDescriptorVrf, []int{2} }

func (m *VirtualRouterStatus) GetHandle() uint64 {
	if m != nil {
		return m.Handle
	}
	return 0
}

func (m *VirtualRouterStatus) GetRouteTable() string {
	if m != nil {
		return m.RouteTable
	}
	return ""
}

func (m *VirtualRouterStatus) GetRD() *RouteDistinguisher {
	if m != nil {
		return m.RD
	}
	return nil
}

func init() {
	proto.RegisterType((*VirtualRouter)(nil), "network.VirtualRouter")
	proto.RegisterType((*VirtualRouterSpec)(nil), "network.VirtualRouterSpec")
	proto.RegisterType((*VirtualRouterStatus)(nil), "network.VirtualRouterStatus")
	proto.RegisterEnum("network.VirtualRouterSpec_VPCTypes", VirtualRouterSpec_VPCTypes_name, VirtualRouterSpec_VPCTypes_value)
}
func (m *VirtualRouter) Marshal() (dAtA []byte, err error) {
	size := m.Size()
	dAtA = make([]byte, size)
	n, err := m.MarshalTo(dAtA)
	if err != nil {
		return nil, err
	}
	return dAtA[:n], nil
}

func (m *VirtualRouter) MarshalTo(dAtA []byte) (int, error) {
	var i int
	_ = i
	var l int
	_ = l
	dAtA[i] = 0xa
	i++
	i = encodeVarintVrf(dAtA, i, uint64(m.TypeMeta.Size()))
	n1, err := m.TypeMeta.MarshalTo(dAtA[i:])
	if err != nil {
		return 0, err
	}
	i += n1
	dAtA[i] = 0x12
	i++
	i = encodeVarintVrf(dAtA, i, uint64(m.ObjectMeta.Size()))
	n2, err := m.ObjectMeta.MarshalTo(dAtA[i:])
	if err != nil {
		return 0, err
	}
	i += n2
	dAtA[i] = 0x1a
	i++
	i = encodeVarintVrf(dAtA, i, uint64(m.Spec.Size()))
	n3, err := m.Spec.MarshalTo(dAtA[i:])
	if err != nil {
		return 0, err
	}
	i += n3
	dAtA[i] = 0x22
	i++
	i = encodeVarintVrf(dAtA, i, uint64(m.Status.Size()))
	n4, err := m.Status.MarshalTo(dAtA[i:])
	if err != nil {
		return 0, err
	}
	i += n4
	return i, nil
}

func (m *VirtualRouterSpec) Marshal() (dAtA []byte, err error) {
	size := m.Size()
	dAtA = make([]byte, size)
	n, err := m.MarshalTo(dAtA)
	if err != nil {
		return nil, err
	}
	return dAtA[:n], nil
}

func (m *VirtualRouterSpec) MarshalTo(dAtA []byte) (int, error) {
	var i int
	_ = i
	var l int
	_ = l
	if len(m.Type) > 0 {
		dAtA[i] = 0xa
		i++
		i = encodeVarintVrf(dAtA, i, uint64(len(m.Type)))
		i += copy(dAtA[i:], m.Type)
	}
	if len(m.RouterMACAddress) > 0 {
		dAtA[i] = 0x12
		i++
		i = encodeVarintVrf(dAtA, i, uint64(len(m.RouterMACAddress)))
		i += copy(dAtA[i:], m.RouterMACAddress)
	}
	if m.VxLanVNI != 0 {
		dAtA[i] = 0x18
		i++
		i = encodeVarintVrf(dAtA, i, uint64(m.VxLanVNI))
	}
	if m.RouteImportExport != nil {
		dAtA[i] = 0x22
		i++
		i = encodeVarintVrf(dAtA, i, uint64(m.RouteImportExport.Size()))
		n5, err := m.RouteImportExport.MarshalTo(dAtA[i:])
		if err != nil {
			return 0, err
		}
		i += n5
	}
	if m.DefaultIPAMPolicy != nil {
		dAtA[i] = 0x2a
		i++
		i = encodeVarintVrf(dAtA, i, uint64(m.DefaultIPAMPolicy.Size()))
		n6, err := m.DefaultIPAMPolicy.MarshalTo(dAtA[i:])
		if err != nil {
			return 0, err
		}
		i += n6
	}
	return i, nil
}

func (m *VirtualRouterStatus) Marshal() (dAtA []byte, err error) {
	size := m.Size()
	dAtA = make([]byte, size)
	n, err := m.MarshalTo(dAtA)
	if err != nil {
		return nil, err
	}
	return dAtA[:n], nil
}

func (m *VirtualRouterStatus) MarshalTo(dAtA []byte) (int, error) {
	var i int
	_ = i
	var l int
	_ = l
	if m.Handle != 0 {
		dAtA[i] = 0x8
		i++
		i = encodeVarintVrf(dAtA, i, uint64(m.Handle))
	}
	if len(m.RouteTable) > 0 {
		dAtA[i] = 0x12
		i++
		i = encodeVarintVrf(dAtA, i, uint64(len(m.RouteTable)))
		i += copy(dAtA[i:], m.RouteTable)
	}
	if m.RD != nil {
		dAtA[i] = 0x1a
		i++
		i = encodeVarintVrf(dAtA, i, uint64(m.RD.Size()))
		n7, err := m.RD.MarshalTo(dAtA[i:])
		if err != nil {
			return 0, err
		}
		i += n7
	}
	return i, nil
}

func encodeVarintVrf(dAtA []byte, offset int, v uint64) int {
	for v >= 1<<7 {
		dAtA[offset] = uint8(v&0x7f | 0x80)
		v >>= 7
		offset++
	}
	dAtA[offset] = uint8(v)
	return offset + 1
}
func (m *VirtualRouter) Size() (n int) {
	var l int
	_ = l
	l = m.TypeMeta.Size()
	n += 1 + l + sovVrf(uint64(l))
	l = m.ObjectMeta.Size()
	n += 1 + l + sovVrf(uint64(l))
	l = m.Spec.Size()
	n += 1 + l + sovVrf(uint64(l))
	l = m.Status.Size()
	n += 1 + l + sovVrf(uint64(l))
	return n
}

func (m *VirtualRouterSpec) Size() (n int) {
	var l int
	_ = l
	l = len(m.Type)
	if l > 0 {
		n += 1 + l + sovVrf(uint64(l))
	}
	l = len(m.RouterMACAddress)
	if l > 0 {
		n += 1 + l + sovVrf(uint64(l))
	}
	if m.VxLanVNI != 0 {
		n += 1 + sovVrf(uint64(m.VxLanVNI))
	}
	if m.RouteImportExport != nil {
		l = m.RouteImportExport.Size()
		n += 1 + l + sovVrf(uint64(l))
	}
	if m.DefaultIPAMPolicy != nil {
		l = m.DefaultIPAMPolicy.Size()
		n += 1 + l + sovVrf(uint64(l))
	}
	return n
}

func (m *VirtualRouterStatus) Size() (n int) {
	var l int
	_ = l
	if m.Handle != 0 {
		n += 1 + sovVrf(uint64(m.Handle))
	}
	l = len(m.RouteTable)
	if l > 0 {
		n += 1 + l + sovVrf(uint64(l))
	}
	if m.RD != nil {
		l = m.RD.Size()
		n += 1 + l + sovVrf(uint64(l))
	}
	return n
}

func sovVrf(x uint64) (n int) {
	for {
		n++
		x >>= 7
		if x == 0 {
			break
		}
	}
	return n
}
func sozVrf(x uint64) (n int) {
	return sovVrf(uint64((x << 1) ^ uint64((int64(x) >> 63))))
}
func (m *VirtualRouter) Unmarshal(dAtA []byte) error {
	l := len(dAtA)
	iNdEx := 0
	for iNdEx < l {
		preIndex := iNdEx
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return ErrIntOverflowVrf
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
			return fmt.Errorf("proto: VirtualRouter: wiretype end group for non-group")
		}
		if fieldNum <= 0 {
			return fmt.Errorf("proto: VirtualRouter: illegal tag %d (wire type %d)", fieldNum, wire)
		}
		switch fieldNum {
		case 1:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field TypeMeta", wireType)
			}
			var msglen int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowVrf
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
				return ErrInvalidLengthVrf
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
					return ErrIntOverflowVrf
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
				return ErrInvalidLengthVrf
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
					return ErrIntOverflowVrf
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
				return ErrInvalidLengthVrf
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
					return ErrIntOverflowVrf
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
				return ErrInvalidLengthVrf
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
			skippy, err := skipVrf(dAtA[iNdEx:])
			if err != nil {
				return err
			}
			if skippy < 0 {
				return ErrInvalidLengthVrf
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
func (m *VirtualRouterSpec) Unmarshal(dAtA []byte) error {
	l := len(dAtA)
	iNdEx := 0
	for iNdEx < l {
		preIndex := iNdEx
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return ErrIntOverflowVrf
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
			return fmt.Errorf("proto: VirtualRouterSpec: wiretype end group for non-group")
		}
		if fieldNum <= 0 {
			return fmt.Errorf("proto: VirtualRouterSpec: illegal tag %d (wire type %d)", fieldNum, wire)
		}
		switch fieldNum {
		case 1:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field Type", wireType)
			}
			var stringLen uint64
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowVrf
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
				return ErrInvalidLengthVrf
			}
			postIndex := iNdEx + intStringLen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.Type = string(dAtA[iNdEx:postIndex])
			iNdEx = postIndex
		case 2:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field RouterMACAddress", wireType)
			}
			var stringLen uint64
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowVrf
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
				return ErrInvalidLengthVrf
			}
			postIndex := iNdEx + intStringLen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.RouterMACAddress = string(dAtA[iNdEx:postIndex])
			iNdEx = postIndex
		case 3:
			if wireType != 0 {
				return fmt.Errorf("proto: wrong wireType = %d for field VxLanVNI", wireType)
			}
			m.VxLanVNI = 0
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowVrf
				}
				if iNdEx >= l {
					return io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				m.VxLanVNI |= (uint32(b) & 0x7F) << shift
				if b < 0x80 {
					break
				}
			}
		case 4:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field RouteImportExport", wireType)
			}
			var msglen int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowVrf
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
				return ErrInvalidLengthVrf
			}
			postIndex := iNdEx + msglen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			if m.RouteImportExport == nil {
				m.RouteImportExport = &RDSpec{}
			}
			if err := m.RouteImportExport.Unmarshal(dAtA[iNdEx:postIndex]); err != nil {
				return err
			}
			iNdEx = postIndex
		case 5:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field DefaultIPAMPolicy", wireType)
			}
			var msglen int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowVrf
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
				return ErrInvalidLengthVrf
			}
			postIndex := iNdEx + msglen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			if m.DefaultIPAMPolicy == nil {
				m.DefaultIPAMPolicy = &IPAMPolicy{}
			}
			if err := m.DefaultIPAMPolicy.Unmarshal(dAtA[iNdEx:postIndex]); err != nil {
				return err
			}
			iNdEx = postIndex
		default:
			iNdEx = preIndex
			skippy, err := skipVrf(dAtA[iNdEx:])
			if err != nil {
				return err
			}
			if skippy < 0 {
				return ErrInvalidLengthVrf
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
func (m *VirtualRouterStatus) Unmarshal(dAtA []byte) error {
	l := len(dAtA)
	iNdEx := 0
	for iNdEx < l {
		preIndex := iNdEx
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return ErrIntOverflowVrf
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
			return fmt.Errorf("proto: VirtualRouterStatus: wiretype end group for non-group")
		}
		if fieldNum <= 0 {
			return fmt.Errorf("proto: VirtualRouterStatus: illegal tag %d (wire type %d)", fieldNum, wire)
		}
		switch fieldNum {
		case 1:
			if wireType != 0 {
				return fmt.Errorf("proto: wrong wireType = %d for field Handle", wireType)
			}
			m.Handle = 0
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowVrf
				}
				if iNdEx >= l {
					return io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				m.Handle |= (uint64(b) & 0x7F) << shift
				if b < 0x80 {
					break
				}
			}
		case 2:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field RouteTable", wireType)
			}
			var stringLen uint64
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowVrf
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
				return ErrInvalidLengthVrf
			}
			postIndex := iNdEx + intStringLen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.RouteTable = string(dAtA[iNdEx:postIndex])
			iNdEx = postIndex
		case 3:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field RD", wireType)
			}
			var msglen int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowVrf
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
				return ErrInvalidLengthVrf
			}
			postIndex := iNdEx + msglen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			if m.RD == nil {
				m.RD = &RouteDistinguisher{}
			}
			if err := m.RD.Unmarshal(dAtA[iNdEx:postIndex]); err != nil {
				return err
			}
			iNdEx = postIndex
		default:
			iNdEx = preIndex
			skippy, err := skipVrf(dAtA[iNdEx:])
			if err != nil {
				return err
			}
			if skippy < 0 {
				return ErrInvalidLengthVrf
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
func skipVrf(dAtA []byte) (n int, err error) {
	l := len(dAtA)
	iNdEx := 0
	for iNdEx < l {
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return 0, ErrIntOverflowVrf
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
					return 0, ErrIntOverflowVrf
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
					return 0, ErrIntOverflowVrf
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
				return 0, ErrInvalidLengthVrf
			}
			return iNdEx, nil
		case 3:
			for {
				var innerWire uint64
				var start int = iNdEx
				for shift := uint(0); ; shift += 7 {
					if shift >= 64 {
						return 0, ErrIntOverflowVrf
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
				next, err := skipVrf(dAtA[start:])
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
	ErrInvalidLengthVrf = fmt.Errorf("proto: negative length found during unmarshaling")
	ErrIntOverflowVrf   = fmt.Errorf("proto: integer overflow")
)

func init() { proto.RegisterFile("vrf.proto", fileDescriptorVrf) }

var fileDescriptorVrf = []byte{
	// 717 bytes of a gzipped FileDescriptorProto
	0x1f, 0x8b, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xff, 0x7c, 0x54, 0xcd, 0x4e, 0xdb, 0x4c,
	0x14, 0xc5, 0xf9, 0x42, 0x20, 0x93, 0x0f, 0x08, 0x13, 0xb5, 0x0a, 0x01, 0x62, 0x48, 0x55, 0x89,
	0x4a, 0xd8, 0xae, 0x5a, 0xa9, 0x8b, 0x76, 0x85, 0x49, 0xda, 0x46, 0x2a, 0x10, 0x85, 0x34, 0x62,
	0x3b, 0xb1, 0x27, 0x61, 0x8a, 0x3d, 0x63, 0xd9, 0xe3, 0x40, 0x54, 0x75, 0x59, 0xd4, 0xe7, 0xe8,
	0xb2, 0x4f, 0xc2, 0x12, 0xf5, 0x01, 0xac, 0x2a, 0xab, 0x2a, 0x0f, 0xd0, 0x75, 0xe5, 0x19, 0x03,
	0x4e, 0xf9, 0xd9, 0x24, 0x73, 0xe6, 0x9e, 0x7b, 0xee, 0xf1, 0x9c, 0xb1, 0x41, 0x7e, 0xe8, 0xf7,
	0x75, 0xcf, 0x67, 0x9c, 0xc1, 0x39, 0x8a, 0xf9, 0x29, 0xf3, 0x4f, 0x2a, 0x6b, 0x03, 0xc6, 0x06,
	0x0e, 0x36, 0x90, 0x47, 0x0c, 0x44, 0x29, 0xe3, 0x88, 0x13, 0x46, 0x03, 0x49, 0xab, 0x34, 0x06,
	0x84, 0x1f, 0x87, 0x3d, 0xdd, 0x62, 0xae, 0xe1, 0x61, 0x1a, 0x20, 0x6a, 0x33, 0x23, 0x38, 0x35,
	0x86, 0x98, 0x12, 0x0b, 0x1b, 0x21, 0x27, 0x4e, 0x10, 0xb7, 0x0e, 0x30, 0x4d, 0x77, 0x1b, 0x84,
	0x5a, 0x4e, 0x68, 0xe3, 0x2b, 0x19, 0x2d, 0x25, 0x33, 0x60, 0x03, 0x66, 0x88, 0xed, 0x5e, 0xd8,
	0x17, 0x48, 0x00, 0xb1, 0x4a, 0xe8, 0x4f, 0xef, 0x99, 0x1a, 0x7b, 0x74, 0x31, 0x47, 0x09, 0xad,
	0xe0, 0xb3, 0x90, 0xe3, 0x04, 0x00, 0xe2, 0x21, 0x57, 0xae, 0x6b, 0x51, 0x06, 0x2c, 0x74, 0x89,
	0xcf, 0x43, 0xe4, 0xb4, 0x63, 0x8a, 0x0f, 0x5f, 0x01, 0xa5, 0x53, 0x56, 0x36, 0x94, 0xad, 0xc2,
	0x8b, 0x05, 0x1d, 0x79, 0x44, 0xef, 0x8c, 0x3c, 0xbc, 0x87, 0x39, 0x32, 0x4b, 0x17, 0x91, 0x3a,
	0x73, 0x19, 0xa9, 0xca, 0x24, 0x52, 0xe7, 0xb6, 0x09, 0x75, 0x08, 0xc5, 0xed, 0xab, 0x05, 0x7c,
	0x0b, 0x94, 0x83, 0x72, 0x46, 0xf4, 0x2d, 0x89, 0xbe, 0x83, 0xde, 0x27, 0x6c, 0x71, 0xd1, 0x59,
	0x49, 0x75, 0x2e, 0xc6, 0xb6, 0xb6, 0x99, 0x4b, 0x38, 0x76, 0x3d, 0x3e, 0x6a, 0xff, 0x83, 0x61,
	0x0b, 0x64, 0x0f, 0x3d, 0x6c, 0x95, 0xff, 0x13, 0x52, 0x15, 0x3d, 0x39, 0x7d, 0x7d, 0xca, 0x65,
	0xcc, 0x30, 0x1f, 0xc7, 0xaa, 0xb1, 0x62, 0xe0, 0x61, 0x2b, 0xad, 0x38, 0x8d, 0xe1, 0x11, 0xc8,
	0x1d, 0x72, 0xc4, 0xc3, 0xa0, 0x9c, 0x15, 0x9a, 0x6b, 0xf7, 0x68, 0x0a, 0x8e, 0x59, 0x4e, 0x54,
	0x8b, 0x81, 0xc0, 0x29, 0xdd, 0x5b, 0x3b, 0xaf, 0x37, 0x7f, 0x7e, 0x5d, 0x59, 0x07, 0x05, 0xe3,
	0xf3, 0x81, 0xde, 0xc1, 0x14, 0x51, 0xfe, 0x05, 0x2e, 0x0e, 0xa5, 0xa6, 0x38, 0x70, 0x3f, 0xa8,
	0x7d, 0xcb, 0x82, 0xe5, 0x5b, 0xd6, 0x61, 0x03, 0x64, 0xe3, 0x63, 0x15, 0xe7, 0x9c, 0x37, 0x9f,
	0xff, 0x38, 0x5f, 0x79, 0x72, 0xc8, 0xfd, 0x06, 0x0d, 0xdd, 0xad, 0x5b, 0x64, 0xbd, 0xdb, 0xda,
	0x8d, 0xc9, 0xc1, 0xb3, 0x49, 0xa4, 0xce, 0xf2, 0x91, 0x87, 0xb7, 0xdb, 0xf2, 0x0f, 0x1e, 0x81,
	0xa2, 0xe4, 0xed, 0xed, 0xec, 0xee, 0xd8, 0xb6, 0x8f, 0x83, 0x40, 0x44, 0x90, 0x37, 0x37, 0x26,
	0x91, 0xba, 0x26, 0x3d, 0x68, 0x2e, 0xb2, 0x34, 0x24, 0xab, 0xa9, 0xa7, 0x79, 0xb0, 0x0a, 0x4d,
	0x30, 0xdf, 0x3d, 0xfb, 0x80, 0x68, 0x77, 0xbf, 0x29, 0x92, 0x58, 0x30, 0x57, 0x2f, 0x64, 0x7e,
	0xa5, 0xe1, 0x99, 0x83, 0xa8, 0x36, 0xa4, 0x24, 0x25, 0x76, 0xd7, 0x26, 0x74, 0xc0, 0xb2, 0x70,
	0xd7, 0x74, 0x3d, 0xe6, 0xf3, 0xc6, 0x59, 0xfc, 0x9b, 0x44, 0xb0, 0x74, 0x1d, 0x41, 0xbb, 0x2e,
	0xb2, 0xdc, 0x9c, 0x44, 0xea, 0xba, 0x70, 0xa4, 0x11, 0x41, 0xd7, 0xb0, 0xe0, 0xa7, 0x66, 0x3c,
	0x5c, 0x86, 0x1e, 0x58, 0xae, 0xe3, 0x3e, 0x0a, 0x1d, 0xde, 0x6c, 0xed, 0xec, 0xb5, 0x98, 0x43,
	0xac, 0x51, 0x79, 0x56, 0x4c, 0x2b, 0x5d, 0x4f, 0xbb, 0x29, 0xc9, 0x89, 0xb6, 0xec, 0xd0, 0xe2,
	0x37, 0x42, 0xf3, 0x44, 0x21, 0x3d, 0xf1, 0xc1, 0x72, 0x4d, 0x07, 0xf3, 0x57, 0xd1, 0xc0, 0x02,
	0x98, 0xfb, 0x48, 0x4f, 0x28, 0x3b, 0xa5, 0xc5, 0x19, 0x08, 0x40, 0x4e, 0x5e, 0x87, 0xa2, 0x02,
	0xf3, 0x60, 0xb6, 0x49, 0xfb, 0x3e, 0x2a, 0x66, 0x6a, 0x7f, 0x14, 0x50, 0xba, 0xe3, 0xc6, 0x41,
	0x1d, 0xe4, 0xde, 0x23, 0x6a, 0x3b, 0xf2, 0x3a, 0x64, 0xcd, 0xe2, 0x24, 0x52, 0xff, 0x27, 0x76,
	0xca, 0xc8, 0x14, 0x82, 0x7d, 0x00, 0x44, 0x7f, 0x07, 0xf5, 0x1c, 0x9c, 0xe4, 0xfd, 0xe6, 0xfb,
	0xf9, 0x4a, 0x15, 0xcc, 0xef, 0x23, 0x17, 0xdb, 0x6d, 0xdc, 0x87, 0x30, 0x79, 0x62, 0xe3, 0x86,
	0x39, 0x89, 0xd4, 0x47, 0xf2, 0x08, 0x79, 0x0c, 0x53, 0xf2, 0x77, 0x6f, 0xc3, 0x77, 0x20, 0xd3,
	0xae, 0x27, 0xef, 0xe1, 0xea, 0x4d, 0x60, 0x31, 0xb7, 0x4e, 0x02, 0x4e, 0xe8, 0x20, 0x24, 0xc1,
	0x31, 0xf6, 0xa5, 0x61, 0x7f, 0xca, 0x70, 0x1a, 0x99, 0xc5, 0x8b, 0x71, 0x55, 0xb9, 0x1c, 0x57,
	0x95, 0x5f, 0xe3, 0xaa, 0xf2, 0x7b, 0x5c, 0x9d, 0x69, 0x29, 0xbd, 0x9c, 0xf8, 0xfe, 0xbc, 0xfc,
	0x1b, 0x00, 0x00, 0xff, 0xff, 0xf0, 0xe4, 0x5e, 0xb9, 0x69, 0x05, 0x00, 0x00,
}
