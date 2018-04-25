// Code generated by protoc-gen-gogo. DO NOT EDIT.
// source: network.proto

package network

import proto "github.com/gogo/protobuf/proto"
import fmt "fmt"
import math "math"
import _ "github.com/pensando/grpc-gateway/third_party/googleapis/google/api"
import _ "github.com/pensando/sw/venice/utils/apigen/annotations"
import _ "github.com/gogo/protobuf/gogoproto"
import api "github.com/pensando/sw/api"
import _ "github.com/pensando/sw/api/labels"
import _ "github.com/pensando/sw/api/generated/cluster"

import io "io"

// Reference imports to suppress errors if they are not otherwise used.
var _ = proto.Marshal
var _ = fmt.Errorf
var _ = math.Inf

// spec part of network object
type Network struct {
	// type of network. (vlan/vxlan/routed etc)
	api.TypeMeta `protobuf:"bytes,1,opt,name=T,embedded=T" json:",inline"`
	// IPv4 subnet CIDR
	api.ObjectMeta `protobuf:"bytes,2,opt,name=O,embedded=O" json:"meta,omitempty"`
	// IPv4 gateway for this subnet
	Spec NetworkSpec `protobuf:"bytes,3,opt,name=Spec" json:"spec,omitempty"`
	// IPv6 subnet CIDR
	Status NetworkStatus `protobuf:"bytes,4,opt,name=Status" json:"status,omitempty"`
}

func (m *Network) Reset()                    { *m = Network{} }
func (m *Network) String() string            { return proto.CompactTextString(m) }
func (*Network) ProtoMessage()               {}
func (*Network) Descriptor() ([]byte, []int) { return fileDescriptorNetwork, []int{0} }

func (m *Network) GetSpec() NetworkSpec {
	if m != nil {
		return m.Spec
	}
	return NetworkSpec{}
}

func (m *Network) GetStatus() NetworkStatus {
	if m != nil {
		return m.Status
	}
	return NetworkStatus{}
}

// status part of network object
type NetworkSpec struct {
	// list of all workloads in this network
	Type string `protobuf:"bytes,1,opt,name=Type,proto3" json:"type,omitempty"`
	// allocated IPv4 addresses (bitmap)
	IPv4Subnet  string `protobuf:"bytes,2,opt,name=IPv4Subnet,proto3" json:"ipv4-subnet,omitempty"`
	IPv4Gateway string `protobuf:"bytes,3,opt,name=IPv4Gateway,proto3" json:"ipv4-gateway,omitempty"`
	IPv6Subnet  string `protobuf:"bytes,4,opt,name=IPv6Subnet,proto3" json:"ipv6-subnet,omitempty"`
	IPv6Gateway string `protobuf:"bytes,5,opt,name=IPv6Gateway,proto3" json:"ipv6-gateway,omitempty"`
	VlanID      uint32 `protobuf:"varint,6,opt,name=VlanID,proto3" json:"vlan-id,omitempty"`
	VxlanVNI    uint32 `protobuf:"varint,7,opt,name=VxlanVNI,proto3" json:"vxlan-vni,omitempty"`
}

func (m *NetworkSpec) Reset()                    { *m = NetworkSpec{} }
func (m *NetworkSpec) String() string            { return proto.CompactTextString(m) }
func (*NetworkSpec) ProtoMessage()               {}
func (*NetworkSpec) Descriptor() ([]byte, []int) { return fileDescriptorNetwork, []int{1} }

func (m *NetworkSpec) GetType() string {
	if m != nil {
		return m.Type
	}
	return ""
}

func (m *NetworkSpec) GetIPv4Subnet() string {
	if m != nil {
		return m.IPv4Subnet
	}
	return ""
}

func (m *NetworkSpec) GetIPv4Gateway() string {
	if m != nil {
		return m.IPv4Gateway
	}
	return ""
}

func (m *NetworkSpec) GetIPv6Subnet() string {
	if m != nil {
		return m.IPv6Subnet
	}
	return ""
}

func (m *NetworkSpec) GetIPv6Gateway() string {
	if m != nil {
		return m.IPv6Gateway
	}
	return ""
}

func (m *NetworkSpec) GetVlanID() uint32 {
	if m != nil {
		return m.VlanID
	}
	return 0
}

func (m *NetworkSpec) GetVxlanVNI() uint32 {
	if m != nil {
		return m.VxlanVNI
	}
	return 0
}

// Network represents a subnet
type NetworkStatus struct {
	Workloads          []string `protobuf:"bytes,1,rep,name=Workloads" json:"workloads,omitempty"`
	AllocatedIPv4Addrs []byte   `protobuf:"bytes,2,opt,name=AllocatedIPv4Addrs,proto3" json:"allocated-ipv4-addrs,omitempty" venice:"sskip"`
}

func (m *NetworkStatus) Reset()                    { *m = NetworkStatus{} }
func (m *NetworkStatus) String() string            { return proto.CompactTextString(m) }
func (*NetworkStatus) ProtoMessage()               {}
func (*NetworkStatus) Descriptor() ([]byte, []int) { return fileDescriptorNetwork, []int{2} }

func (m *NetworkStatus) GetWorkloads() []string {
	if m != nil {
		return m.Workloads
	}
	return nil
}

func (m *NetworkStatus) GetAllocatedIPv4Addrs() []byte {
	if m != nil {
		return m.AllocatedIPv4Addrs
	}
	return nil
}

func init() {
	proto.RegisterType((*Network)(nil), "network.Network")
	proto.RegisterType((*NetworkSpec)(nil), "network.NetworkSpec")
	proto.RegisterType((*NetworkStatus)(nil), "network.NetworkStatus")
}
func (m *Network) Marshal() (dAtA []byte, err error) {
	size := m.Size()
	dAtA = make([]byte, size)
	n, err := m.MarshalTo(dAtA)
	if err != nil {
		return nil, err
	}
	return dAtA[:n], nil
}

func (m *Network) MarshalTo(dAtA []byte) (int, error) {
	var i int
	_ = i
	var l int
	_ = l
	dAtA[i] = 0xa
	i++
	i = encodeVarintNetwork(dAtA, i, uint64(m.TypeMeta.Size()))
	n1, err := m.TypeMeta.MarshalTo(dAtA[i:])
	if err != nil {
		return 0, err
	}
	i += n1
	dAtA[i] = 0x12
	i++
	i = encodeVarintNetwork(dAtA, i, uint64(m.ObjectMeta.Size()))
	n2, err := m.ObjectMeta.MarshalTo(dAtA[i:])
	if err != nil {
		return 0, err
	}
	i += n2
	dAtA[i] = 0x1a
	i++
	i = encodeVarintNetwork(dAtA, i, uint64(m.Spec.Size()))
	n3, err := m.Spec.MarshalTo(dAtA[i:])
	if err != nil {
		return 0, err
	}
	i += n3
	dAtA[i] = 0x22
	i++
	i = encodeVarintNetwork(dAtA, i, uint64(m.Status.Size()))
	n4, err := m.Status.MarshalTo(dAtA[i:])
	if err != nil {
		return 0, err
	}
	i += n4
	return i, nil
}

func (m *NetworkSpec) Marshal() (dAtA []byte, err error) {
	size := m.Size()
	dAtA = make([]byte, size)
	n, err := m.MarshalTo(dAtA)
	if err != nil {
		return nil, err
	}
	return dAtA[:n], nil
}

func (m *NetworkSpec) MarshalTo(dAtA []byte) (int, error) {
	var i int
	_ = i
	var l int
	_ = l
	if len(m.Type) > 0 {
		dAtA[i] = 0xa
		i++
		i = encodeVarintNetwork(dAtA, i, uint64(len(m.Type)))
		i += copy(dAtA[i:], m.Type)
	}
	if len(m.IPv4Subnet) > 0 {
		dAtA[i] = 0x12
		i++
		i = encodeVarintNetwork(dAtA, i, uint64(len(m.IPv4Subnet)))
		i += copy(dAtA[i:], m.IPv4Subnet)
	}
	if len(m.IPv4Gateway) > 0 {
		dAtA[i] = 0x1a
		i++
		i = encodeVarintNetwork(dAtA, i, uint64(len(m.IPv4Gateway)))
		i += copy(dAtA[i:], m.IPv4Gateway)
	}
	if len(m.IPv6Subnet) > 0 {
		dAtA[i] = 0x22
		i++
		i = encodeVarintNetwork(dAtA, i, uint64(len(m.IPv6Subnet)))
		i += copy(dAtA[i:], m.IPv6Subnet)
	}
	if len(m.IPv6Gateway) > 0 {
		dAtA[i] = 0x2a
		i++
		i = encodeVarintNetwork(dAtA, i, uint64(len(m.IPv6Gateway)))
		i += copy(dAtA[i:], m.IPv6Gateway)
	}
	if m.VlanID != 0 {
		dAtA[i] = 0x30
		i++
		i = encodeVarintNetwork(dAtA, i, uint64(m.VlanID))
	}
	if m.VxlanVNI != 0 {
		dAtA[i] = 0x38
		i++
		i = encodeVarintNetwork(dAtA, i, uint64(m.VxlanVNI))
	}
	return i, nil
}

func (m *NetworkStatus) Marshal() (dAtA []byte, err error) {
	size := m.Size()
	dAtA = make([]byte, size)
	n, err := m.MarshalTo(dAtA)
	if err != nil {
		return nil, err
	}
	return dAtA[:n], nil
}

func (m *NetworkStatus) MarshalTo(dAtA []byte) (int, error) {
	var i int
	_ = i
	var l int
	_ = l
	if len(m.Workloads) > 0 {
		for _, s := range m.Workloads {
			dAtA[i] = 0xa
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
	if len(m.AllocatedIPv4Addrs) > 0 {
		dAtA[i] = 0x12
		i++
		i = encodeVarintNetwork(dAtA, i, uint64(len(m.AllocatedIPv4Addrs)))
		i += copy(dAtA[i:], m.AllocatedIPv4Addrs)
	}
	return i, nil
}

func encodeVarintNetwork(dAtA []byte, offset int, v uint64) int {
	for v >= 1<<7 {
		dAtA[offset] = uint8(v&0x7f | 0x80)
		v >>= 7
		offset++
	}
	dAtA[offset] = uint8(v)
	return offset + 1
}
func (m *Network) Size() (n int) {
	var l int
	_ = l
	l = m.TypeMeta.Size()
	n += 1 + l + sovNetwork(uint64(l))
	l = m.ObjectMeta.Size()
	n += 1 + l + sovNetwork(uint64(l))
	l = m.Spec.Size()
	n += 1 + l + sovNetwork(uint64(l))
	l = m.Status.Size()
	n += 1 + l + sovNetwork(uint64(l))
	return n
}

func (m *NetworkSpec) Size() (n int) {
	var l int
	_ = l
	l = len(m.Type)
	if l > 0 {
		n += 1 + l + sovNetwork(uint64(l))
	}
	l = len(m.IPv4Subnet)
	if l > 0 {
		n += 1 + l + sovNetwork(uint64(l))
	}
	l = len(m.IPv4Gateway)
	if l > 0 {
		n += 1 + l + sovNetwork(uint64(l))
	}
	l = len(m.IPv6Subnet)
	if l > 0 {
		n += 1 + l + sovNetwork(uint64(l))
	}
	l = len(m.IPv6Gateway)
	if l > 0 {
		n += 1 + l + sovNetwork(uint64(l))
	}
	if m.VlanID != 0 {
		n += 1 + sovNetwork(uint64(m.VlanID))
	}
	if m.VxlanVNI != 0 {
		n += 1 + sovNetwork(uint64(m.VxlanVNI))
	}
	return n
}

func (m *NetworkStatus) Size() (n int) {
	var l int
	_ = l
	if len(m.Workloads) > 0 {
		for _, s := range m.Workloads {
			l = len(s)
			n += 1 + l + sovNetwork(uint64(l))
		}
	}
	l = len(m.AllocatedIPv4Addrs)
	if l > 0 {
		n += 1 + l + sovNetwork(uint64(l))
	}
	return n
}

func sovNetwork(x uint64) (n int) {
	for {
		n++
		x >>= 7
		if x == 0 {
			break
		}
	}
	return n
}
func sozNetwork(x uint64) (n int) {
	return sovNetwork(uint64((x << 1) ^ uint64((int64(x) >> 63))))
}
func (m *Network) Unmarshal(dAtA []byte) error {
	l := len(dAtA)
	iNdEx := 0
	for iNdEx < l {
		preIndex := iNdEx
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return ErrIntOverflowNetwork
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
			return fmt.Errorf("proto: Network: wiretype end group for non-group")
		}
		if fieldNum <= 0 {
			return fmt.Errorf("proto: Network: illegal tag %d (wire type %d)", fieldNum, wire)
		}
		switch fieldNum {
		case 1:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field TypeMeta", wireType)
			}
			var msglen int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowNetwork
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
				return ErrInvalidLengthNetwork
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
					return ErrIntOverflowNetwork
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
				return ErrInvalidLengthNetwork
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
					return ErrIntOverflowNetwork
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
				return ErrInvalidLengthNetwork
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
					return ErrIntOverflowNetwork
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
				return ErrInvalidLengthNetwork
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
			skippy, err := skipNetwork(dAtA[iNdEx:])
			if err != nil {
				return err
			}
			if skippy < 0 {
				return ErrInvalidLengthNetwork
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
func (m *NetworkSpec) Unmarshal(dAtA []byte) error {
	l := len(dAtA)
	iNdEx := 0
	for iNdEx < l {
		preIndex := iNdEx
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return ErrIntOverflowNetwork
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
			return fmt.Errorf("proto: NetworkSpec: wiretype end group for non-group")
		}
		if fieldNum <= 0 {
			return fmt.Errorf("proto: NetworkSpec: illegal tag %d (wire type %d)", fieldNum, wire)
		}
		switch fieldNum {
		case 1:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field Type", wireType)
			}
			var stringLen uint64
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowNetwork
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
				return ErrInvalidLengthNetwork
			}
			postIndex := iNdEx + intStringLen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.Type = string(dAtA[iNdEx:postIndex])
			iNdEx = postIndex
		case 2:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field IPv4Subnet", wireType)
			}
			var stringLen uint64
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowNetwork
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
				return ErrInvalidLengthNetwork
			}
			postIndex := iNdEx + intStringLen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.IPv4Subnet = string(dAtA[iNdEx:postIndex])
			iNdEx = postIndex
		case 3:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field IPv4Gateway", wireType)
			}
			var stringLen uint64
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowNetwork
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
				return ErrInvalidLengthNetwork
			}
			postIndex := iNdEx + intStringLen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.IPv4Gateway = string(dAtA[iNdEx:postIndex])
			iNdEx = postIndex
		case 4:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field IPv6Subnet", wireType)
			}
			var stringLen uint64
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowNetwork
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
				return ErrInvalidLengthNetwork
			}
			postIndex := iNdEx + intStringLen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.IPv6Subnet = string(dAtA[iNdEx:postIndex])
			iNdEx = postIndex
		case 5:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field IPv6Gateway", wireType)
			}
			var stringLen uint64
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowNetwork
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
				return ErrInvalidLengthNetwork
			}
			postIndex := iNdEx + intStringLen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.IPv6Gateway = string(dAtA[iNdEx:postIndex])
			iNdEx = postIndex
		case 6:
			if wireType != 0 {
				return fmt.Errorf("proto: wrong wireType = %d for field VlanID", wireType)
			}
			m.VlanID = 0
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowNetwork
				}
				if iNdEx >= l {
					return io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				m.VlanID |= (uint32(b) & 0x7F) << shift
				if b < 0x80 {
					break
				}
			}
		case 7:
			if wireType != 0 {
				return fmt.Errorf("proto: wrong wireType = %d for field VxlanVNI", wireType)
			}
			m.VxlanVNI = 0
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowNetwork
				}
				if iNdEx >= l {
					return io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				m.VxlanVNI |= (uint32(b) & 0x7F) << shift
				if b < 0x80 {
					break
				}
			}
		default:
			iNdEx = preIndex
			skippy, err := skipNetwork(dAtA[iNdEx:])
			if err != nil {
				return err
			}
			if skippy < 0 {
				return ErrInvalidLengthNetwork
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
func (m *NetworkStatus) Unmarshal(dAtA []byte) error {
	l := len(dAtA)
	iNdEx := 0
	for iNdEx < l {
		preIndex := iNdEx
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return ErrIntOverflowNetwork
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
			return fmt.Errorf("proto: NetworkStatus: wiretype end group for non-group")
		}
		if fieldNum <= 0 {
			return fmt.Errorf("proto: NetworkStatus: illegal tag %d (wire type %d)", fieldNum, wire)
		}
		switch fieldNum {
		case 1:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field Workloads", wireType)
			}
			var stringLen uint64
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowNetwork
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
				return ErrInvalidLengthNetwork
			}
			postIndex := iNdEx + intStringLen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.Workloads = append(m.Workloads, string(dAtA[iNdEx:postIndex]))
			iNdEx = postIndex
		case 2:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field AllocatedIPv4Addrs", wireType)
			}
			var byteLen int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowNetwork
				}
				if iNdEx >= l {
					return io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				byteLen |= (int(b) & 0x7F) << shift
				if b < 0x80 {
					break
				}
			}
			if byteLen < 0 {
				return ErrInvalidLengthNetwork
			}
			postIndex := iNdEx + byteLen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.AllocatedIPv4Addrs = append(m.AllocatedIPv4Addrs[:0], dAtA[iNdEx:postIndex]...)
			if m.AllocatedIPv4Addrs == nil {
				m.AllocatedIPv4Addrs = []byte{}
			}
			iNdEx = postIndex
		default:
			iNdEx = preIndex
			skippy, err := skipNetwork(dAtA[iNdEx:])
			if err != nil {
				return err
			}
			if skippy < 0 {
				return ErrInvalidLengthNetwork
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
func skipNetwork(dAtA []byte) (n int, err error) {
	l := len(dAtA)
	iNdEx := 0
	for iNdEx < l {
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return 0, ErrIntOverflowNetwork
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
					return 0, ErrIntOverflowNetwork
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
					return 0, ErrIntOverflowNetwork
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
				return 0, ErrInvalidLengthNetwork
			}
			return iNdEx, nil
		case 3:
			for {
				var innerWire uint64
				var start int = iNdEx
				for shift := uint(0); ; shift += 7 {
					if shift >= 64 {
						return 0, ErrIntOverflowNetwork
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
				next, err := skipNetwork(dAtA[start:])
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
	ErrInvalidLengthNetwork = fmt.Errorf("proto: negative length found during unmarshaling")
	ErrIntOverflowNetwork   = fmt.Errorf("proto: integer overflow")
)

func init() { proto.RegisterFile("network.proto", fileDescriptorNetwork) }

var fileDescriptorNetwork = []byte{
	// 630 bytes of a gzipped FileDescriptorProto
	0x1f, 0x8b, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xff, 0x7c, 0x94, 0x4f, 0x4f, 0x13, 0x41,
	0x18, 0xc6, 0x1d, 0xa8, 0x2d, 0x9d, 0x52, 0xd4, 0x41, 0x61, 0x01, 0x6d, 0x49, 0x13, 0x13, 0x62,
	0xe8, 0x2e, 0x2a, 0x56, 0x25, 0x31, 0x81, 0x8d, 0x46, 0x39, 0x48, 0x09, 0x34, 0x78, 0x9e, 0xee,
	0x8e, 0xcb, 0xc8, 0x74, 0x66, 0xd3, 0x99, 0xb6, 0x36, 0xc6, 0xa3, 0x9f, 0xc3, 0xa3, 0x57, 0x3f,
	0x06, 0x47, 0xe2, 0x07, 0x68, 0x0c, 0x47, 0x8f, 0x7e, 0x02, 0x33, 0xd3, 0x59, 0x19, 0xc2, 0x9f,
	0xdb, 0xbe, 0xf3, 0x3e, 0xbf, 0x67, 0x9f, 0x79, 0xdf, 0xec, 0xc2, 0x32, 0x27, 0x6a, 0x20, 0xba,
	0x47, 0x7e, 0xda, 0x15, 0x4a, 0xa0, 0x82, 0x2d, 0x17, 0xef, 0x27, 0x42, 0x24, 0x8c, 0x04, 0x38,
	0xa5, 0x01, 0xe6, 0x5c, 0x28, 0xac, 0xa8, 0xe0, 0x72, 0x2c, 0x5b, 0x7c, 0x93, 0x50, 0x75, 0xd8,
	0x6b, 0xfb, 0x91, 0xe8, 0x04, 0x29, 0xe1, 0x12, 0xf3, 0x58, 0x04, 0x72, 0x10, 0xf4, 0x09, 0xa7,
	0x11, 0x09, 0x7a, 0x8a, 0x32, 0xa9, 0xd1, 0x84, 0x70, 0x97, 0x0e, 0x28, 0x8f, 0x58, 0x2f, 0x26,
	0x99, 0x4d, 0xdd, 0xb1, 0x49, 0x44, 0x22, 0x02, 0x73, 0xdc, 0xee, 0x7d, 0x34, 0x95, 0x29, 0xcc,
	0x93, 0x95, 0x3f, 0xbc, 0xe2, 0xad, 0x3a, 0x63, 0x87, 0x28, 0x6c, 0x65, 0x6b, 0xd7, 0xc8, 0x18,
	0x6e, 0x13, 0x26, 0x03, 0x49, 0x18, 0x89, 0x94, 0xe8, 0x5a, 0xc2, 0xbf, 0x86, 0x30, 0x0a, 0x19,
	0x28, 0xc2, 0x31, 0x57, 0x63, 0x7d, 0xed, 0xfb, 0x04, 0x2c, 0xec, 0x8c, 0x07, 0x85, 0xd6, 0x20,
	0x68, 0x79, 0x60, 0x19, 0xac, 0x94, 0x9e, 0x94, 0x7d, 0x9c, 0x52, 0xbf, 0x35, 0x4c, 0xc9, 0x7b,
	0xa2, 0x70, 0x38, 0x7b, 0x3c, 0xaa, 0xde, 0x38, 0x19, 0x55, 0xc1, 0x9f, 0x51, 0xb5, 0xb0, 0x4a,
	0x39, 0xa3, 0x9c, 0xec, 0x81, 0x16, 0x7a, 0x09, 0x41, 0xd3, 0x9b, 0x30, 0xc4, 0x2d, 0x43, 0x34,
	0xdb, 0x9f, 0x48, 0xa4, 0x0c, 0xb3, 0xe8, 0x30, 0x33, 0xfa, 0x4e, 0xab, 0xa2, 0x43, 0x15, 0xe9,
	0xa4, 0x6a, 0xb8, 0x07, 0x9a, 0x68, 0x13, 0xe6, 0xf6, 0x53, 0x12, 0x79, 0x93, 0x86, 0xbe, 0xeb,
	0x67, 0xcb, 0xb3, 0x61, 0x74, 0x2f, 0x9c, 0xd3, 0x16, 0x1a, 0x97, 0x29, 0x89, 0x1c, 0xdc, 0x90,
	0xe8, 0x1d, 0xcc, 0xef, 0x2b, 0xac, 0x7a, 0xd2, 0xcb, 0x19, 0x8f, 0xb9, 0x0b, 0x1e, 0xa6, 0x1b,
	0x7a, 0xd6, 0xe5, 0xb6, 0x34, 0xb5, 0xe3, 0x63, 0xf9, 0x8d, 0xa5, 0x5f, 0xdf, 0x16, 0xe6, 0x61,
	0x29, 0xf8, 0xd2, 0xf4, 0x5b, 0x66, 0x38, 0x5f, 0xd1, 0x94, 0xf5, 0x92, 0xb5, 0x1f, 0x93, 0xb0,
	0xe4, 0x84, 0x42, 0x8f, 0x60, 0x4e, 0xcf, 0xc5, 0x0c, 0xaa, 0x68, 0x22, 0x9a, 0x1b, 0xaa, 0x61,
	0x4a, 0xdc, 0x88, 0x5a, 0x83, 0x5e, 0x41, 0xb8, 0xbd, 0xdb, 0x5f, 0xdf, 0xef, 0xb5, 0x39, 0x51,
	0x66, 0x50, 0xc5, 0xf0, 0x81, 0x25, 0xee, 0xd1, 0xb4, 0xbf, 0x5e, 0x97, 0xa6, 0xe5, 0x80, 0x0e,
	0x80, 0x36, 0x61, 0x49, 0x57, 0x6f, 0xb1, 0x22, 0x03, 0x3c, 0x34, 0xa3, 0x2a, 0x86, 0x15, 0xcb,
	0xcf, 0x19, 0x3e, 0x19, 0xf7, 0x1c, 0x03, 0x17, 0xb1, 0x01, 0x1a, 0x36, 0x40, 0xee, 0x42, 0x80,
	0xc6, 0xe5, 0x01, 0x1a, 0xe7, 0x02, 0x34, 0xb2, 0x00, 0x37, 0x2f, 0x04, 0x68, 0x5c, 0x11, 0x20,
	0x43, 0xd0, 0x63, 0x98, 0x3f, 0x60, 0x98, 0x6f, 0xbf, 0xf6, 0xf2, 0xcb, 0x60, 0xa5, 0x1c, 0x2e,
	0x58, 0xf8, 0x4e, 0x9f, 0x61, 0x5e, 0xa7, 0xb1, 0xbb, 0x8d, 0xb1, 0x10, 0x3d, 0x87, 0x53, 0x07,
	0x9f, 0x19, 0xe6, 0x07, 0x3b, 0xdb, 0x5e, 0xc1, 0x40, 0x4b, 0x16, 0x9a, 0xed, 0xeb, 0xf3, 0x7a,
	0x9f, 0x53, 0x07, 0xfb, 0x2f, 0xae, 0xfd, 0x04, 0xb0, 0x7c, 0x6e, 0xf5, 0xe8, 0x19, 0x2c, 0x7e,
	0x10, 0xdd, 0x23, 0x26, 0x70, 0x2c, 0x3d, 0xb0, 0x3c, 0xb9, 0x52, 0x0c, 0xe7, 0xb5, 0xcf, 0x20,
	0x3b, 0x74, 0x7c, 0xce, 0x94, 0xe8, 0x10, 0xa2, 0x2d, 0xc6, 0x44, 0x84, 0x15, 0x89, 0xf5, 0x34,
	0xb7, 0xe2, 0xb8, 0x2b, 0xcd, 0xfa, 0xa6, 0xc3, 0x17, 0x36, 0x4b, 0x05, 0x67, 0x8a, 0xba, 0x59,
	0x04, 0xd6, 0x9a, 0x33, 0xbb, 0xbf, 0xa3, 0xea, 0xcc, 0xf8, 0x17, 0xb2, 0x51, 0x93, 0xf2, 0x88,
	0xa6, 0xb5, 0xbd, 0x4b, 0x3c, 0xc3, 0xe9, 0xe3, 0xd3, 0x0a, 0x38, 0x39, 0xad, 0x80, 0xdf, 0xa7,
	0x15, 0xb0, 0x0b, 0xda, 0x79, 0xf3, 0x55, 0x3e, 0xfd, 0x17, 0x00, 0x00, 0xff, 0xff, 0xb4, 0x27,
	0xab, 0xf8, 0xcc, 0x04, 0x00, 0x00,
}
