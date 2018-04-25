// Code generated by protoc-gen-gogo. DO NOT EDIT.
// source: securitygroup.proto

package security

import proto "github.com/gogo/protobuf/proto"
import fmt "fmt"
import math "math"
import _ "github.com/pensando/grpc-gateway/third_party/googleapis/google/api"
import _ "github.com/pensando/sw/venice/utils/apigen/annotations"
import _ "github.com/gogo/protobuf/gogoproto"
import api "github.com/pensando/sw/api"
import labels "github.com/pensando/sw/api/labels"
import _ "github.com/pensando/sw/api/generated/cluster"

import io "io"

// Reference imports to suppress errors if they are not otherwise used.
var _ = proto.Marshal
var _ = fmt.Errorf
var _ = math.Inf

// security group configuration
type SecurityGroup struct {
	// Workload selector (list of labels)
	api.TypeMeta `protobuf:"bytes,1,opt,name=T,embedded=T" json:",inline"`
	// Service object selector
	api.ObjectMeta `protobuf:"bytes,2,opt,name=O,embedded=O" json:"meta,omitempty"`
	// list of CIDRs that are part of this security group
	Spec   SecurityGroupSpec   `protobuf:"bytes,3,opt,name=Spec" json:"spec,omitempty"`
	Status SecurityGroupStatus `protobuf:"bytes,4,opt,name=Status" json:"status,omitempty"`
}

func (m *SecurityGroup) Reset()                    { *m = SecurityGroup{} }
func (m *SecurityGroup) String() string            { return proto.CompactTextString(m) }
func (*SecurityGroup) ProtoMessage()               {}
func (*SecurityGroup) Descriptor() ([]byte, []int) { return fileDescriptorSecuritygroup, []int{0} }

func (m *SecurityGroup) GetSpec() SecurityGroupSpec {
	if m != nil {
		return m.Spec
	}
	return SecurityGroupSpec{}
}

func (m *SecurityGroup) GetStatus() SecurityGroupStatus {
	if m != nil {
		return m.Status
	}
	return SecurityGroupStatus{}
}

// security group status
type SecurityGroupSpec struct {
	// list of workloads that are part of this security group
	WorkloadSelector *labels.Selector `protobuf:"bytes,1,opt,name=WorkloadSelector" json:"workload-selector,omitempty"`
	// list of all policies attached to this security group
	ServiceSelector []string `protobuf:"bytes,2,rep,name=ServiceSelector" json:"service-labels,omitempty"`
	MatchPrefixes   []string `protobuf:"bytes,3,rep,name=MatchPrefixes" json:"match-prefixes,omitempty"`
}

func (m *SecurityGroupSpec) Reset()                    { *m = SecurityGroupSpec{} }
func (m *SecurityGroupSpec) String() string            { return proto.CompactTextString(m) }
func (*SecurityGroupSpec) ProtoMessage()               {}
func (*SecurityGroupSpec) Descriptor() ([]byte, []int) { return fileDescriptorSecuritygroup, []int{1} }

func (m *SecurityGroupSpec) GetWorkloadSelector() *labels.Selector {
	if m != nil {
		return m.WorkloadSelector
	}
	return nil
}

func (m *SecurityGroupSpec) GetServiceSelector() []string {
	if m != nil {
		return m.ServiceSelector
	}
	return nil
}

func (m *SecurityGroupSpec) GetMatchPrefixes() []string {
	if m != nil {
		return m.MatchPrefixes
	}
	return nil
}

// SecurityGroup represents a security zone or domain
type SecurityGroupStatus struct {
	Workloads []string `protobuf:"bytes,1,rep,name=Workloads" json:"workloads,omitempty"`
	Policies  []string `protobuf:"bytes,2,rep,name=Policies" json:"Policies,omitempty"`
}

func (m *SecurityGroupStatus) Reset()                    { *m = SecurityGroupStatus{} }
func (m *SecurityGroupStatus) String() string            { return proto.CompactTextString(m) }
func (*SecurityGroupStatus) ProtoMessage()               {}
func (*SecurityGroupStatus) Descriptor() ([]byte, []int) { return fileDescriptorSecuritygroup, []int{2} }

func (m *SecurityGroupStatus) GetWorkloads() []string {
	if m != nil {
		return m.Workloads
	}
	return nil
}

func (m *SecurityGroupStatus) GetPolicies() []string {
	if m != nil {
		return m.Policies
	}
	return nil
}

func init() {
	proto.RegisterType((*SecurityGroup)(nil), "security.SecurityGroup")
	proto.RegisterType((*SecurityGroupSpec)(nil), "security.SecurityGroupSpec")
	proto.RegisterType((*SecurityGroupStatus)(nil), "security.SecurityGroupStatus")
}
func (m *SecurityGroup) Marshal() (dAtA []byte, err error) {
	size := m.Size()
	dAtA = make([]byte, size)
	n, err := m.MarshalTo(dAtA)
	if err != nil {
		return nil, err
	}
	return dAtA[:n], nil
}

func (m *SecurityGroup) MarshalTo(dAtA []byte) (int, error) {
	var i int
	_ = i
	var l int
	_ = l
	dAtA[i] = 0xa
	i++
	i = encodeVarintSecuritygroup(dAtA, i, uint64(m.TypeMeta.Size()))
	n1, err := m.TypeMeta.MarshalTo(dAtA[i:])
	if err != nil {
		return 0, err
	}
	i += n1
	dAtA[i] = 0x12
	i++
	i = encodeVarintSecuritygroup(dAtA, i, uint64(m.ObjectMeta.Size()))
	n2, err := m.ObjectMeta.MarshalTo(dAtA[i:])
	if err != nil {
		return 0, err
	}
	i += n2
	dAtA[i] = 0x1a
	i++
	i = encodeVarintSecuritygroup(dAtA, i, uint64(m.Spec.Size()))
	n3, err := m.Spec.MarshalTo(dAtA[i:])
	if err != nil {
		return 0, err
	}
	i += n3
	dAtA[i] = 0x22
	i++
	i = encodeVarintSecuritygroup(dAtA, i, uint64(m.Status.Size()))
	n4, err := m.Status.MarshalTo(dAtA[i:])
	if err != nil {
		return 0, err
	}
	i += n4
	return i, nil
}

func (m *SecurityGroupSpec) Marshal() (dAtA []byte, err error) {
	size := m.Size()
	dAtA = make([]byte, size)
	n, err := m.MarshalTo(dAtA)
	if err != nil {
		return nil, err
	}
	return dAtA[:n], nil
}

func (m *SecurityGroupSpec) MarshalTo(dAtA []byte) (int, error) {
	var i int
	_ = i
	var l int
	_ = l
	if m.WorkloadSelector != nil {
		dAtA[i] = 0xa
		i++
		i = encodeVarintSecuritygroup(dAtA, i, uint64(m.WorkloadSelector.Size()))
		n5, err := m.WorkloadSelector.MarshalTo(dAtA[i:])
		if err != nil {
			return 0, err
		}
		i += n5
	}
	if len(m.ServiceSelector) > 0 {
		for _, s := range m.ServiceSelector {
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
	if len(m.MatchPrefixes) > 0 {
		for _, s := range m.MatchPrefixes {
			dAtA[i] = 0x1a
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
	return i, nil
}

func (m *SecurityGroupStatus) Marshal() (dAtA []byte, err error) {
	size := m.Size()
	dAtA = make([]byte, size)
	n, err := m.MarshalTo(dAtA)
	if err != nil {
		return nil, err
	}
	return dAtA[:n], nil
}

func (m *SecurityGroupStatus) MarshalTo(dAtA []byte) (int, error) {
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
	if len(m.Policies) > 0 {
		for _, s := range m.Policies {
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
	return i, nil
}

func encodeVarintSecuritygroup(dAtA []byte, offset int, v uint64) int {
	for v >= 1<<7 {
		dAtA[offset] = uint8(v&0x7f | 0x80)
		v >>= 7
		offset++
	}
	dAtA[offset] = uint8(v)
	return offset + 1
}
func (m *SecurityGroup) Size() (n int) {
	var l int
	_ = l
	l = m.TypeMeta.Size()
	n += 1 + l + sovSecuritygroup(uint64(l))
	l = m.ObjectMeta.Size()
	n += 1 + l + sovSecuritygroup(uint64(l))
	l = m.Spec.Size()
	n += 1 + l + sovSecuritygroup(uint64(l))
	l = m.Status.Size()
	n += 1 + l + sovSecuritygroup(uint64(l))
	return n
}

func (m *SecurityGroupSpec) Size() (n int) {
	var l int
	_ = l
	if m.WorkloadSelector != nil {
		l = m.WorkloadSelector.Size()
		n += 1 + l + sovSecuritygroup(uint64(l))
	}
	if len(m.ServiceSelector) > 0 {
		for _, s := range m.ServiceSelector {
			l = len(s)
			n += 1 + l + sovSecuritygroup(uint64(l))
		}
	}
	if len(m.MatchPrefixes) > 0 {
		for _, s := range m.MatchPrefixes {
			l = len(s)
			n += 1 + l + sovSecuritygroup(uint64(l))
		}
	}
	return n
}

func (m *SecurityGroupStatus) Size() (n int) {
	var l int
	_ = l
	if len(m.Workloads) > 0 {
		for _, s := range m.Workloads {
			l = len(s)
			n += 1 + l + sovSecuritygroup(uint64(l))
		}
	}
	if len(m.Policies) > 0 {
		for _, s := range m.Policies {
			l = len(s)
			n += 1 + l + sovSecuritygroup(uint64(l))
		}
	}
	return n
}

func sovSecuritygroup(x uint64) (n int) {
	for {
		n++
		x >>= 7
		if x == 0 {
			break
		}
	}
	return n
}
func sozSecuritygroup(x uint64) (n int) {
	return sovSecuritygroup(uint64((x << 1) ^ uint64((int64(x) >> 63))))
}
func (m *SecurityGroup) Unmarshal(dAtA []byte) error {
	l := len(dAtA)
	iNdEx := 0
	for iNdEx < l {
		preIndex := iNdEx
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return ErrIntOverflowSecuritygroup
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
			return fmt.Errorf("proto: SecurityGroup: wiretype end group for non-group")
		}
		if fieldNum <= 0 {
			return fmt.Errorf("proto: SecurityGroup: illegal tag %d (wire type %d)", fieldNum, wire)
		}
		switch fieldNum {
		case 1:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field TypeMeta", wireType)
			}
			var msglen int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowSecuritygroup
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
				return ErrInvalidLengthSecuritygroup
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
					return ErrIntOverflowSecuritygroup
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
				return ErrInvalidLengthSecuritygroup
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
					return ErrIntOverflowSecuritygroup
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
				return ErrInvalidLengthSecuritygroup
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
					return ErrIntOverflowSecuritygroup
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
				return ErrInvalidLengthSecuritygroup
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
			skippy, err := skipSecuritygroup(dAtA[iNdEx:])
			if err != nil {
				return err
			}
			if skippy < 0 {
				return ErrInvalidLengthSecuritygroup
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
func (m *SecurityGroupSpec) Unmarshal(dAtA []byte) error {
	l := len(dAtA)
	iNdEx := 0
	for iNdEx < l {
		preIndex := iNdEx
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return ErrIntOverflowSecuritygroup
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
			return fmt.Errorf("proto: SecurityGroupSpec: wiretype end group for non-group")
		}
		if fieldNum <= 0 {
			return fmt.Errorf("proto: SecurityGroupSpec: illegal tag %d (wire type %d)", fieldNum, wire)
		}
		switch fieldNum {
		case 1:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field WorkloadSelector", wireType)
			}
			var msglen int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowSecuritygroup
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
				return ErrInvalidLengthSecuritygroup
			}
			postIndex := iNdEx + msglen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			if m.WorkloadSelector == nil {
				m.WorkloadSelector = &labels.Selector{}
			}
			if err := m.WorkloadSelector.Unmarshal(dAtA[iNdEx:postIndex]); err != nil {
				return err
			}
			iNdEx = postIndex
		case 2:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field ServiceSelector", wireType)
			}
			var stringLen uint64
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowSecuritygroup
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
				return ErrInvalidLengthSecuritygroup
			}
			postIndex := iNdEx + intStringLen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.ServiceSelector = append(m.ServiceSelector, string(dAtA[iNdEx:postIndex]))
			iNdEx = postIndex
		case 3:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field MatchPrefixes", wireType)
			}
			var stringLen uint64
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowSecuritygroup
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
				return ErrInvalidLengthSecuritygroup
			}
			postIndex := iNdEx + intStringLen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.MatchPrefixes = append(m.MatchPrefixes, string(dAtA[iNdEx:postIndex]))
			iNdEx = postIndex
		default:
			iNdEx = preIndex
			skippy, err := skipSecuritygroup(dAtA[iNdEx:])
			if err != nil {
				return err
			}
			if skippy < 0 {
				return ErrInvalidLengthSecuritygroup
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
func (m *SecurityGroupStatus) Unmarshal(dAtA []byte) error {
	l := len(dAtA)
	iNdEx := 0
	for iNdEx < l {
		preIndex := iNdEx
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return ErrIntOverflowSecuritygroup
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
			return fmt.Errorf("proto: SecurityGroupStatus: wiretype end group for non-group")
		}
		if fieldNum <= 0 {
			return fmt.Errorf("proto: SecurityGroupStatus: illegal tag %d (wire type %d)", fieldNum, wire)
		}
		switch fieldNum {
		case 1:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field Workloads", wireType)
			}
			var stringLen uint64
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowSecuritygroup
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
				return ErrInvalidLengthSecuritygroup
			}
			postIndex := iNdEx + intStringLen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.Workloads = append(m.Workloads, string(dAtA[iNdEx:postIndex]))
			iNdEx = postIndex
		case 2:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field Policies", wireType)
			}
			var stringLen uint64
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowSecuritygroup
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
				return ErrInvalidLengthSecuritygroup
			}
			postIndex := iNdEx + intStringLen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.Policies = append(m.Policies, string(dAtA[iNdEx:postIndex]))
			iNdEx = postIndex
		default:
			iNdEx = preIndex
			skippy, err := skipSecuritygroup(dAtA[iNdEx:])
			if err != nil {
				return err
			}
			if skippy < 0 {
				return ErrInvalidLengthSecuritygroup
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
func skipSecuritygroup(dAtA []byte) (n int, err error) {
	l := len(dAtA)
	iNdEx := 0
	for iNdEx < l {
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return 0, ErrIntOverflowSecuritygroup
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
					return 0, ErrIntOverflowSecuritygroup
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
					return 0, ErrIntOverflowSecuritygroup
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
				return 0, ErrInvalidLengthSecuritygroup
			}
			return iNdEx, nil
		case 3:
			for {
				var innerWire uint64
				var start int = iNdEx
				for shift := uint(0); ; shift += 7 {
					if shift >= 64 {
						return 0, ErrIntOverflowSecuritygroup
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
				next, err := skipSecuritygroup(dAtA[start:])
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
	ErrInvalidLengthSecuritygroup = fmt.Errorf("proto: negative length found during unmarshaling")
	ErrIntOverflowSecuritygroup   = fmt.Errorf("proto: integer overflow")
)

func init() { proto.RegisterFile("securitygroup.proto", fileDescriptorSecuritygroup) }

var fileDescriptorSecuritygroup = []byte{
	// 538 bytes of a gzipped FileDescriptorProto
	0x1f, 0x8b, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xff, 0x7c, 0x92, 0xcd, 0x6e, 0xd3, 0x40,
	0x10, 0xc7, 0xd9, 0xa4, 0x2a, 0xed, 0x96, 0x90, 0xe0, 0x48, 0xc8, 0x24, 0x25, 0x8e, 0x22, 0x21,
	0xf5, 0xd0, 0x78, 0x2b, 0x38, 0x95, 0xa3, 0x25, 0xda, 0x53, 0x95, 0x28, 0x89, 0xc4, 0x89, 0xc3,
	0x66, 0x33, 0x75, 0x17, 0x9c, 0x5d, 0xcb, 0xbb, 0x6e, 0x89, 0x10, 0x17, 0x24, 0x5e, 0x8a, 0x27,
	0xc8, 0xb1, 0xe2, 0x01, 0x22, 0x94, 0x63, 0x9e, 0x02, 0x79, 0xbd, 0x2e, 0x2e, 0xfd, 0xb8, 0x79,
	0x66, 0xfe, 0xff, 0x9f, 0xe7, 0x63, 0x71, 0x53, 0x01, 0x4b, 0x13, 0xae, 0x17, 0x61, 0x22, 0xd3,
	0xd8, 0x8f, 0x13, 0xa9, 0xa5, 0xb3, 0x53, 0x24, 0x5b, 0xfb, 0xa1, 0x94, 0x61, 0x04, 0x84, 0xc6,
	0x9c, 0x50, 0x21, 0xa4, 0xa6, 0x9a, 0x4b, 0xa1, 0x72, 0x5d, 0xeb, 0x43, 0xc8, 0xf5, 0x45, 0x3a,
	0xf5, 0x99, 0x9c, 0x93, 0x18, 0x84, 0xa2, 0x62, 0x26, 0x89, 0xba, 0x22, 0x97, 0x20, 0x38, 0x03,
	0x92, 0x6a, 0x1e, 0xa9, 0xcc, 0x1a, 0x82, 0x28, 0xbb, 0x09, 0x17, 0x2c, 0x4a, 0x67, 0x50, 0x60,
	0xfa, 0x25, 0x4c, 0x28, 0x43, 0x49, 0x4c, 0x7a, 0x9a, 0x9e, 0x9b, 0xc8, 0x04, 0xe6, 0xcb, 0xca,
	0xdf, 0x3c, 0xf0, 0xd7, 0xac, 0xc7, 0x39, 0x68, 0x6a, 0x65, 0x47, 0x8f, 0xc8, 0x22, 0x3a, 0x85,
	0x48, 0x11, 0x05, 0x11, 0x30, 0x2d, 0x13, 0xeb, 0xf0, 0x1f, 0x71, 0x18, 0x85, 0x22, 0x1a, 0x04,
	0x15, 0x3a, 0xd7, 0xf7, 0x7e, 0x55, 0x70, 0x6d, 0x6c, 0x37, 0x75, 0x9a, 0xad, 0xcf, 0x39, 0xc2,
	0x68, 0xe2, 0xa2, 0x2e, 0x3a, 0xd8, 0x7b, 0x5b, 0xf3, 0x69, 0xcc, 0xfd, 0xc9, 0x22, 0x86, 0x33,
	0xd0, 0x34, 0x68, 0x2e, 0x57, 0xde, 0x93, 0xeb, 0x95, 0x87, 0x36, 0x2b, 0xef, 0xe9, 0x21, 0x17,
	0x11, 0x17, 0x30, 0x42, 0x13, 0xe7, 0x18, 0xa3, 0x81, 0x5b, 0x31, 0x8e, 0xba, 0x71, 0x0c, 0xa6,
	0x9f, 0x81, 0x69, 0xe3, 0x69, 0x95, 0x3c, 0xcf, 0xb3, 0xc9, 0x0e, 0xe5, 0x9c, 0x6b, 0x98, 0xc7,
	0x7a, 0x31, 0x42, 0x03, 0xe7, 0x14, 0x6f, 0x8d, 0x63, 0x60, 0x6e, 0xd5, 0xb8, 0xdb, 0x7e, 0x71,
	0x34, 0xff, 0x56, 0x4f, 0x99, 0x24, 0x78, 0x99, 0x91, 0x32, 0x8a, 0x8a, 0x81, 0x95, 0x28, 0x06,
	0xe0, 0x0c, 0xf0, 0xf6, 0x58, 0x53, 0x9d, 0x2a, 0x77, 0xcb, 0xa0, 0x5e, 0x3f, 0x84, 0x32, 0xa2,
	0xc0, 0xb5, 0xb0, 0x86, 0x32, 0x71, 0x09, 0x67, 0x31, 0xef, 0x7b, 0xbf, 0x7f, 0xbe, 0xea, 0xe0,
	0x3d, 0xf2, 0x6d, 0xe0, 0x4f, 0xcc, 0xc2, 0xbe, 0x3b, 0xf5, 0x02, 0xd9, 0x37, 0x0f, 0x4d, 0xf5,
	0x7e, 0x54, 0xf0, 0x8b, 0x3b, 0x8d, 0x3a, 0x9f, 0x70, 0xe3, 0xa3, 0x4c, 0xbe, 0x44, 0x92, 0xce,
	0xc6, 0xf6, 0x38, 0x76, 0x9f, 0x0d, 0x3f, 0x3f, 0x9a, 0x5f, 0xe4, 0x03, 0x6f, 0xb3, 0xf2, 0xda,
	0x57, 0x56, 0xdd, 0x2f, 0x6e, 0x59, 0x6a, 0xe7, 0x0e, 0xca, 0x39, 0xc1, 0xf5, 0x31, 0x24, 0x97,
	0x9c, 0xc1, 0x0d, 0xbd, 0xd2, 0xad, 0x1e, 0xec, 0x06, 0xfb, 0x9b, 0x95, 0xe7, 0xaa, 0xbc, 0xd4,
	0xcf, 0x7f, 0x54, 0x02, 0xfd, 0x6f, 0x72, 0x4e, 0x70, 0xed, 0x8c, 0x6a, 0x76, 0x31, 0x4c, 0xe0,
	0x9c, 0x7f, 0x05, 0xe5, 0x56, 0x0d, 0xa5, 0xbb, 0xcc, 0x8f, 0xe5, 0xce, 0xb3, 0x62, 0x3f, 0xb6,
	0xd5, 0x12, 0xe9, 0xb6, 0xad, 0x17, 0xe1, 0xe6, 0x3d, 0x1b, 0x76, 0x8e, 0xf1, 0x6e, 0xd1, 0xba,
	0x72, 0x91, 0x41, 0xb7, 0x2d, 0xba, 0x59, 0x0c, 0x5c, 0xa6, 0xfe, 0x53, 0x3b, 0x2d, 0xbc, 0x33,
	0x94, 0x11, 0x67, 0x1c, 0x54, 0x3e, 0xda, 0xe8, 0x26, 0x0e, 0x9e, 0x2d, 0xd7, 0x1d, 0x74, 0xbd,
	0xee, 0xa0, 0x3f, 0xeb, 0x0e, 0x1a, 0xa2, 0xe9, 0xb6, 0x79, 0xc6, 0xef, 0xfe, 0x06, 0x00, 0x00,
	0xff, 0xff, 0x74, 0xe3, 0x29, 0xb6, 0x04, 0x04, 0x00, 0x00,
}
