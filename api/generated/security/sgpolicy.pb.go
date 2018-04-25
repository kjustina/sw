// Code generated by protoc-gen-gogo. DO NOT EDIT.
// source: sgpolicy.proto

package security

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

type SGRule struct {
	// match ports for the rule
	Ports string `protobuf:"bytes,1,opt,name=Ports,proto3" json:"ports,omitempty"`
	// Rule action (allow/deny/log/train)
	Action string `protobuf:"bytes,2,opt,name=Action,proto3" json:"action,omitempty"`
	// Peer group for the rule (from/to group depending on direction)
	PeerGroup string `protobuf:"bytes,3,opt,name=PeerGroup,proto3" json:"peer-group,omitempty"`
	// List of Apps to match for the rule
	Apps []string `protobuf:"bytes,4,rep,name=Apps" json:"apps,omitempty"`
	// AppUser or AppUserGroup to match for the rule
	// AppUser is derived from application payload such as database login or
	// other application authentication mechanisms
	// FIXME: oneof does not translate well in golang - will enforce via validation
	// Used when policy is applied on a single user
	AppUser string `protobuf:"bytes,5,opt,name=AppUser,proto3" json:"app-user,omitempty"`
	// Used when policy is applied on a group of users
	AppUserGrp string `protobuf:"bytes,6,opt,name=AppUserGrp,proto3" json:"app-user-group,omitempty"`
}

func (m *SGRule) Reset()                    { *m = SGRule{} }
func (m *SGRule) String() string            { return proto.CompactTextString(m) }
func (*SGRule) ProtoMessage()               {}
func (*SGRule) Descriptor() ([]byte, []int) { return fileDescriptorSgpolicy, []int{0} }

func (m *SGRule) GetPorts() string {
	if m != nil {
		return m.Ports
	}
	return ""
}

func (m *SGRule) GetAction() string {
	if m != nil {
		return m.Action
	}
	return ""
}

func (m *SGRule) GetPeerGroup() string {
	if m != nil {
		return m.PeerGroup
	}
	return ""
}

func (m *SGRule) GetApps() []string {
	if m != nil {
		return m.Apps
	}
	return nil
}

func (m *SGRule) GetAppUser() string {
	if m != nil {
		return m.AppUser
	}
	return ""
}

func (m *SGRule) GetAppUserGrp() string {
	if m != nil {
		return m.AppUserGrp
	}
	return ""
}

type Sgpolicy struct {
	// list of security groups this policy is attached to
	api.TypeMeta `protobuf:"bytes,1,opt,name=T,embedded=T" json:",inline"`
	// Incoming rules
	api.ObjectMeta `protobuf:"bytes,2,opt,name=O,embedded=O" json:"meta,omitempty"`
	// Outgoing rules
	Spec   SgpolicySpec   `protobuf:"bytes,3,opt,name=Spec" json:"spec,omitempty"`
	Status SgpolicyStatus `protobuf:"bytes,4,opt,name=Status" json:"status,omitempty"`
}

func (m *Sgpolicy) Reset()                    { *m = Sgpolicy{} }
func (m *Sgpolicy) String() string            { return proto.CompactTextString(m) }
func (*Sgpolicy) ProtoMessage()               {}
func (*Sgpolicy) Descriptor() ([]byte, []int) { return fileDescriptorSgpolicy, []int{1} }

func (m *Sgpolicy) GetSpec() SgpolicySpec {
	if m != nil {
		return m.Spec
	}
	return SgpolicySpec{}
}

func (m *Sgpolicy) GetStatus() SgpolicyStatus {
	if m != nil {
		return m.Status
	}
	return SgpolicyStatus{}
}

type SgpolicySpec struct {
	// list of workloads in this group
	AttachGroups []string `protobuf:"bytes,1,rep,name=AttachGroups" json:"attach-groups,omitempty"`
	InRules      []SGRule `protobuf:"bytes,2,rep,name=InRules" json:"in-rules,omitempty"`
	OutRules     []SGRule `protobuf:"bytes,3,rep,name=OutRules" json:"out-rules,omitempty"`
}

func (m *SgpolicySpec) Reset()                    { *m = SgpolicySpec{} }
func (m *SgpolicySpec) String() string            { return proto.CompactTextString(m) }
func (*SgpolicySpec) ProtoMessage()               {}
func (*SgpolicySpec) Descriptor() ([]byte, []int) { return fileDescriptorSgpolicy, []int{2} }

func (m *SgpolicySpec) GetAttachGroups() []string {
	if m != nil {
		return m.AttachGroups
	}
	return nil
}

func (m *SgpolicySpec) GetInRules() []SGRule {
	if m != nil {
		return m.InRules
	}
	return nil
}

func (m *SgpolicySpec) GetOutRules() []SGRule {
	if m != nil {
		return m.OutRules
	}
	return nil
}

// Sgpolicy represents a security policy for security groups
type SgpolicyStatus struct {
	Workloads []string `protobuf:"bytes,1,rep,name=Workloads" json:"workloads,omitempty"`
}

func (m *SgpolicyStatus) Reset()                    { *m = SgpolicyStatus{} }
func (m *SgpolicyStatus) String() string            { return proto.CompactTextString(m) }
func (*SgpolicyStatus) ProtoMessage()               {}
func (*SgpolicyStatus) Descriptor() ([]byte, []int) { return fileDescriptorSgpolicy, []int{3} }

func (m *SgpolicyStatus) GetWorkloads() []string {
	if m != nil {
		return m.Workloads
	}
	return nil
}

func init() {
	proto.RegisterType((*SGRule)(nil), "security.SGRule")
	proto.RegisterType((*Sgpolicy)(nil), "security.Sgpolicy")
	proto.RegisterType((*SgpolicySpec)(nil), "security.SgpolicySpec")
	proto.RegisterType((*SgpolicyStatus)(nil), "security.SgpolicyStatus")
}
func (m *SGRule) Marshal() (dAtA []byte, err error) {
	size := m.Size()
	dAtA = make([]byte, size)
	n, err := m.MarshalTo(dAtA)
	if err != nil {
		return nil, err
	}
	return dAtA[:n], nil
}

func (m *SGRule) MarshalTo(dAtA []byte) (int, error) {
	var i int
	_ = i
	var l int
	_ = l
	if len(m.Ports) > 0 {
		dAtA[i] = 0xa
		i++
		i = encodeVarintSgpolicy(dAtA, i, uint64(len(m.Ports)))
		i += copy(dAtA[i:], m.Ports)
	}
	if len(m.Action) > 0 {
		dAtA[i] = 0x12
		i++
		i = encodeVarintSgpolicy(dAtA, i, uint64(len(m.Action)))
		i += copy(dAtA[i:], m.Action)
	}
	if len(m.PeerGroup) > 0 {
		dAtA[i] = 0x1a
		i++
		i = encodeVarintSgpolicy(dAtA, i, uint64(len(m.PeerGroup)))
		i += copy(dAtA[i:], m.PeerGroup)
	}
	if len(m.Apps) > 0 {
		for _, s := range m.Apps {
			dAtA[i] = 0x22
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
	if len(m.AppUser) > 0 {
		dAtA[i] = 0x2a
		i++
		i = encodeVarintSgpolicy(dAtA, i, uint64(len(m.AppUser)))
		i += copy(dAtA[i:], m.AppUser)
	}
	if len(m.AppUserGrp) > 0 {
		dAtA[i] = 0x32
		i++
		i = encodeVarintSgpolicy(dAtA, i, uint64(len(m.AppUserGrp)))
		i += copy(dAtA[i:], m.AppUserGrp)
	}
	return i, nil
}

func (m *Sgpolicy) Marshal() (dAtA []byte, err error) {
	size := m.Size()
	dAtA = make([]byte, size)
	n, err := m.MarshalTo(dAtA)
	if err != nil {
		return nil, err
	}
	return dAtA[:n], nil
}

func (m *Sgpolicy) MarshalTo(dAtA []byte) (int, error) {
	var i int
	_ = i
	var l int
	_ = l
	dAtA[i] = 0xa
	i++
	i = encodeVarintSgpolicy(dAtA, i, uint64(m.TypeMeta.Size()))
	n1, err := m.TypeMeta.MarshalTo(dAtA[i:])
	if err != nil {
		return 0, err
	}
	i += n1
	dAtA[i] = 0x12
	i++
	i = encodeVarintSgpolicy(dAtA, i, uint64(m.ObjectMeta.Size()))
	n2, err := m.ObjectMeta.MarshalTo(dAtA[i:])
	if err != nil {
		return 0, err
	}
	i += n2
	dAtA[i] = 0x1a
	i++
	i = encodeVarintSgpolicy(dAtA, i, uint64(m.Spec.Size()))
	n3, err := m.Spec.MarshalTo(dAtA[i:])
	if err != nil {
		return 0, err
	}
	i += n3
	dAtA[i] = 0x22
	i++
	i = encodeVarintSgpolicy(dAtA, i, uint64(m.Status.Size()))
	n4, err := m.Status.MarshalTo(dAtA[i:])
	if err != nil {
		return 0, err
	}
	i += n4
	return i, nil
}

func (m *SgpolicySpec) Marshal() (dAtA []byte, err error) {
	size := m.Size()
	dAtA = make([]byte, size)
	n, err := m.MarshalTo(dAtA)
	if err != nil {
		return nil, err
	}
	return dAtA[:n], nil
}

func (m *SgpolicySpec) MarshalTo(dAtA []byte) (int, error) {
	var i int
	_ = i
	var l int
	_ = l
	if len(m.AttachGroups) > 0 {
		for _, s := range m.AttachGroups {
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
	if len(m.InRules) > 0 {
		for _, msg := range m.InRules {
			dAtA[i] = 0x12
			i++
			i = encodeVarintSgpolicy(dAtA, i, uint64(msg.Size()))
			n, err := msg.MarshalTo(dAtA[i:])
			if err != nil {
				return 0, err
			}
			i += n
		}
	}
	if len(m.OutRules) > 0 {
		for _, msg := range m.OutRules {
			dAtA[i] = 0x1a
			i++
			i = encodeVarintSgpolicy(dAtA, i, uint64(msg.Size()))
			n, err := msg.MarshalTo(dAtA[i:])
			if err != nil {
				return 0, err
			}
			i += n
		}
	}
	return i, nil
}

func (m *SgpolicyStatus) Marshal() (dAtA []byte, err error) {
	size := m.Size()
	dAtA = make([]byte, size)
	n, err := m.MarshalTo(dAtA)
	if err != nil {
		return nil, err
	}
	return dAtA[:n], nil
}

func (m *SgpolicyStatus) MarshalTo(dAtA []byte) (int, error) {
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
	return i, nil
}

func encodeVarintSgpolicy(dAtA []byte, offset int, v uint64) int {
	for v >= 1<<7 {
		dAtA[offset] = uint8(v&0x7f | 0x80)
		v >>= 7
		offset++
	}
	dAtA[offset] = uint8(v)
	return offset + 1
}
func (m *SGRule) Size() (n int) {
	var l int
	_ = l
	l = len(m.Ports)
	if l > 0 {
		n += 1 + l + sovSgpolicy(uint64(l))
	}
	l = len(m.Action)
	if l > 0 {
		n += 1 + l + sovSgpolicy(uint64(l))
	}
	l = len(m.PeerGroup)
	if l > 0 {
		n += 1 + l + sovSgpolicy(uint64(l))
	}
	if len(m.Apps) > 0 {
		for _, s := range m.Apps {
			l = len(s)
			n += 1 + l + sovSgpolicy(uint64(l))
		}
	}
	l = len(m.AppUser)
	if l > 0 {
		n += 1 + l + sovSgpolicy(uint64(l))
	}
	l = len(m.AppUserGrp)
	if l > 0 {
		n += 1 + l + sovSgpolicy(uint64(l))
	}
	return n
}

func (m *Sgpolicy) Size() (n int) {
	var l int
	_ = l
	l = m.TypeMeta.Size()
	n += 1 + l + sovSgpolicy(uint64(l))
	l = m.ObjectMeta.Size()
	n += 1 + l + sovSgpolicy(uint64(l))
	l = m.Spec.Size()
	n += 1 + l + sovSgpolicy(uint64(l))
	l = m.Status.Size()
	n += 1 + l + sovSgpolicy(uint64(l))
	return n
}

func (m *SgpolicySpec) Size() (n int) {
	var l int
	_ = l
	if len(m.AttachGroups) > 0 {
		for _, s := range m.AttachGroups {
			l = len(s)
			n += 1 + l + sovSgpolicy(uint64(l))
		}
	}
	if len(m.InRules) > 0 {
		for _, e := range m.InRules {
			l = e.Size()
			n += 1 + l + sovSgpolicy(uint64(l))
		}
	}
	if len(m.OutRules) > 0 {
		for _, e := range m.OutRules {
			l = e.Size()
			n += 1 + l + sovSgpolicy(uint64(l))
		}
	}
	return n
}

func (m *SgpolicyStatus) Size() (n int) {
	var l int
	_ = l
	if len(m.Workloads) > 0 {
		for _, s := range m.Workloads {
			l = len(s)
			n += 1 + l + sovSgpolicy(uint64(l))
		}
	}
	return n
}

func sovSgpolicy(x uint64) (n int) {
	for {
		n++
		x >>= 7
		if x == 0 {
			break
		}
	}
	return n
}
func sozSgpolicy(x uint64) (n int) {
	return sovSgpolicy(uint64((x << 1) ^ uint64((int64(x) >> 63))))
}
func (m *SGRule) Unmarshal(dAtA []byte) error {
	l := len(dAtA)
	iNdEx := 0
	for iNdEx < l {
		preIndex := iNdEx
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return ErrIntOverflowSgpolicy
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
			return fmt.Errorf("proto: SGRule: wiretype end group for non-group")
		}
		if fieldNum <= 0 {
			return fmt.Errorf("proto: SGRule: illegal tag %d (wire type %d)", fieldNum, wire)
		}
		switch fieldNum {
		case 1:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field Ports", wireType)
			}
			var stringLen uint64
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowSgpolicy
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
				return ErrInvalidLengthSgpolicy
			}
			postIndex := iNdEx + intStringLen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.Ports = string(dAtA[iNdEx:postIndex])
			iNdEx = postIndex
		case 2:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field Action", wireType)
			}
			var stringLen uint64
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowSgpolicy
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
				return ErrInvalidLengthSgpolicy
			}
			postIndex := iNdEx + intStringLen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.Action = string(dAtA[iNdEx:postIndex])
			iNdEx = postIndex
		case 3:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field PeerGroup", wireType)
			}
			var stringLen uint64
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowSgpolicy
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
				return ErrInvalidLengthSgpolicy
			}
			postIndex := iNdEx + intStringLen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.PeerGroup = string(dAtA[iNdEx:postIndex])
			iNdEx = postIndex
		case 4:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field Apps", wireType)
			}
			var stringLen uint64
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowSgpolicy
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
				return ErrInvalidLengthSgpolicy
			}
			postIndex := iNdEx + intStringLen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.Apps = append(m.Apps, string(dAtA[iNdEx:postIndex]))
			iNdEx = postIndex
		case 5:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field AppUser", wireType)
			}
			var stringLen uint64
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowSgpolicy
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
				return ErrInvalidLengthSgpolicy
			}
			postIndex := iNdEx + intStringLen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.AppUser = string(dAtA[iNdEx:postIndex])
			iNdEx = postIndex
		case 6:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field AppUserGrp", wireType)
			}
			var stringLen uint64
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowSgpolicy
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
				return ErrInvalidLengthSgpolicy
			}
			postIndex := iNdEx + intStringLen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.AppUserGrp = string(dAtA[iNdEx:postIndex])
			iNdEx = postIndex
		default:
			iNdEx = preIndex
			skippy, err := skipSgpolicy(dAtA[iNdEx:])
			if err != nil {
				return err
			}
			if skippy < 0 {
				return ErrInvalidLengthSgpolicy
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
func (m *Sgpolicy) Unmarshal(dAtA []byte) error {
	l := len(dAtA)
	iNdEx := 0
	for iNdEx < l {
		preIndex := iNdEx
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return ErrIntOverflowSgpolicy
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
			return fmt.Errorf("proto: Sgpolicy: wiretype end group for non-group")
		}
		if fieldNum <= 0 {
			return fmt.Errorf("proto: Sgpolicy: illegal tag %d (wire type %d)", fieldNum, wire)
		}
		switch fieldNum {
		case 1:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field TypeMeta", wireType)
			}
			var msglen int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowSgpolicy
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
				return ErrInvalidLengthSgpolicy
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
					return ErrIntOverflowSgpolicy
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
				return ErrInvalidLengthSgpolicy
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
					return ErrIntOverflowSgpolicy
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
				return ErrInvalidLengthSgpolicy
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
					return ErrIntOverflowSgpolicy
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
				return ErrInvalidLengthSgpolicy
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
			skippy, err := skipSgpolicy(dAtA[iNdEx:])
			if err != nil {
				return err
			}
			if skippy < 0 {
				return ErrInvalidLengthSgpolicy
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
func (m *SgpolicySpec) Unmarshal(dAtA []byte) error {
	l := len(dAtA)
	iNdEx := 0
	for iNdEx < l {
		preIndex := iNdEx
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return ErrIntOverflowSgpolicy
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
			return fmt.Errorf("proto: SgpolicySpec: wiretype end group for non-group")
		}
		if fieldNum <= 0 {
			return fmt.Errorf("proto: SgpolicySpec: illegal tag %d (wire type %d)", fieldNum, wire)
		}
		switch fieldNum {
		case 1:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field AttachGroups", wireType)
			}
			var stringLen uint64
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowSgpolicy
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
				return ErrInvalidLengthSgpolicy
			}
			postIndex := iNdEx + intStringLen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.AttachGroups = append(m.AttachGroups, string(dAtA[iNdEx:postIndex]))
			iNdEx = postIndex
		case 2:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field InRules", wireType)
			}
			var msglen int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowSgpolicy
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
				return ErrInvalidLengthSgpolicy
			}
			postIndex := iNdEx + msglen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.InRules = append(m.InRules, SGRule{})
			if err := m.InRules[len(m.InRules)-1].Unmarshal(dAtA[iNdEx:postIndex]); err != nil {
				return err
			}
			iNdEx = postIndex
		case 3:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field OutRules", wireType)
			}
			var msglen int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowSgpolicy
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
				return ErrInvalidLengthSgpolicy
			}
			postIndex := iNdEx + msglen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.OutRules = append(m.OutRules, SGRule{})
			if err := m.OutRules[len(m.OutRules)-1].Unmarshal(dAtA[iNdEx:postIndex]); err != nil {
				return err
			}
			iNdEx = postIndex
		default:
			iNdEx = preIndex
			skippy, err := skipSgpolicy(dAtA[iNdEx:])
			if err != nil {
				return err
			}
			if skippy < 0 {
				return ErrInvalidLengthSgpolicy
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
func (m *SgpolicyStatus) Unmarshal(dAtA []byte) error {
	l := len(dAtA)
	iNdEx := 0
	for iNdEx < l {
		preIndex := iNdEx
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return ErrIntOverflowSgpolicy
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
			return fmt.Errorf("proto: SgpolicyStatus: wiretype end group for non-group")
		}
		if fieldNum <= 0 {
			return fmt.Errorf("proto: SgpolicyStatus: illegal tag %d (wire type %d)", fieldNum, wire)
		}
		switch fieldNum {
		case 1:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field Workloads", wireType)
			}
			var stringLen uint64
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowSgpolicy
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
				return ErrInvalidLengthSgpolicy
			}
			postIndex := iNdEx + intStringLen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.Workloads = append(m.Workloads, string(dAtA[iNdEx:postIndex]))
			iNdEx = postIndex
		default:
			iNdEx = preIndex
			skippy, err := skipSgpolicy(dAtA[iNdEx:])
			if err != nil {
				return err
			}
			if skippy < 0 {
				return ErrInvalidLengthSgpolicy
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
func skipSgpolicy(dAtA []byte) (n int, err error) {
	l := len(dAtA)
	iNdEx := 0
	for iNdEx < l {
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return 0, ErrIntOverflowSgpolicy
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
					return 0, ErrIntOverflowSgpolicy
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
					return 0, ErrIntOverflowSgpolicy
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
				return 0, ErrInvalidLengthSgpolicy
			}
			return iNdEx, nil
		case 3:
			for {
				var innerWire uint64
				var start int = iNdEx
				for shift := uint(0); ; shift += 7 {
					if shift >= 64 {
						return 0, ErrIntOverflowSgpolicy
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
				next, err := skipSgpolicy(dAtA[start:])
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
	ErrInvalidLengthSgpolicy = fmt.Errorf("proto: negative length found during unmarshaling")
	ErrIntOverflowSgpolicy   = fmt.Errorf("proto: integer overflow")
)

func init() { proto.RegisterFile("sgpolicy.proto", fileDescriptorSgpolicy) }

var fileDescriptorSgpolicy = []byte{
	// 661 bytes of a gzipped FileDescriptorProto
	0x1f, 0x8b, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xff, 0x7c, 0x93, 0xd1, 0x4e, 0xdb, 0x3a,
	0x18, 0xc7, 0x4f, 0x5a, 0x28, 0xad, 0xcb, 0x29, 0xc8, 0x45, 0x90, 0x03, 0x88, 0xa0, 0x4a, 0xe7,
	0x88, 0x23, 0xd1, 0x04, 0x75, 0xd2, 0x24, 0xa6, 0xdd, 0x34, 0xd3, 0x86, 0xd8, 0x34, 0x15, 0xd1,
	0x4e, 0xbb, 0x76, 0xc3, 0xb7, 0x90, 0x2d, 0xb5, 0xad, 0xd8, 0x19, 0xaa, 0xa6, 0x5d, 0xee, 0x4d,
	0xf6, 0x02, 0x7b, 0x0b, 0x2e, 0xd1, 0x1e, 0x20, 0x9a, 0xb8, 0xd8, 0x45, 0x9e, 0x62, 0xb2, 0x93,
	0x30, 0x23, 0x06, 0x77, 0xb1, 0xbf, 0xdf, 0xff, 0x9f, 0xcf, 0x9f, 0xff, 0x46, 0x1d, 0x11, 0x72,
	0x16, 0x47, 0xc1, 0xdc, 0xe5, 0x09, 0x93, 0x0c, 0x37, 0x05, 0x04, 0x69, 0x12, 0xc9, 0xf9, 0xe6,
	0x76, 0xc8, 0x58, 0x18, 0x83, 0x47, 0x78, 0xe4, 0x11, 0x4a, 0x99, 0x24, 0x32, 0x62, 0x54, 0x14,
	0xdc, 0xe6, 0xf3, 0x30, 0x92, 0xe7, 0xe9, 0xd4, 0x0d, 0xd8, 0xcc, 0xe3, 0x40, 0x05, 0xa1, 0x67,
	0xcc, 0x13, 0x17, 0xde, 0x47, 0xa0, 0x51, 0x00, 0x5e, 0x2a, 0xa3, 0x58, 0x28, 0x69, 0x08, 0xd4,
	0x54, 0x7b, 0x11, 0x0d, 0xe2, 0xf4, 0x0c, 0x2a, 0x9b, 0xbe, 0x61, 0x13, 0xb2, 0x90, 0x79, 0x7a,
	0x7b, 0x9a, 0xbe, 0xd3, 0x2b, 0xbd, 0xd0, 0x5f, 0x25, 0xfe, 0xef, 0x3d, 0x7f, 0x55, 0x3d, 0xce,
	0x40, 0x92, 0x12, 0x3b, 0x78, 0x00, 0x8b, 0xc9, 0x14, 0x62, 0xe1, 0x09, 0x88, 0x21, 0x90, 0x2c,
	0x29, 0x15, 0xee, 0x03, 0x0a, 0x4d, 0x08, 0x4f, 0x02, 0x25, 0x54, 0x16, 0x7c, 0xef, 0x5b, 0x0d,
	0x35, 0xc6, 0x47, 0xa7, 0x69, 0x0c, 0xf8, 0x7f, 0xb4, 0x78, 0xc2, 0x12, 0x29, 0x6c, 0x6b, 0xd7,
	0xda, 0x6b, 0xf9, 0xdd, 0x3c, 0x73, 0x56, 0xb8, 0xda, 0xd8, 0x67, 0xb3, 0x48, 0xc2, 0x8c, 0xcb,
	0xf9, 0x69, 0x41, 0xe0, 0x7d, 0xd4, 0x18, 0x06, 0x6a, 0x0e, 0x76, 0x4d, 0xb3, 0x6b, 0x79, 0xe6,
	0xac, 0x12, 0xbd, 0x63, 0xc0, 0x25, 0x83, 0x1f, 0xa3, 0xd6, 0x09, 0x40, 0x72, 0x94, 0xb0, 0x94,
	0xdb, 0x75, 0x2d, 0xb0, 0xf3, 0xcc, 0x59, 0xe3, 0x00, 0x49, 0x3f, 0x54, 0xbb, 0x86, 0xe8, 0x37,
	0x8a, 0xff, 0x43, 0x0b, 0x43, 0xce, 0x85, 0xbd, 0xb0, 0x5b, 0xdf, 0x6b, 0xf9, 0x38, 0xcf, 0x9c,
	0x0e, 0xe1, 0xdc, 0x6c, 0x47, 0xd7, 0xf1, 0x01, 0x5a, 0x1a, 0x72, 0xfe, 0x46, 0x40, 0x62, 0x2f,
	0x6a, 0xf7, 0xf5, 0x3c, 0x73, 0x30, 0xe1, 0xbc, 0x9f, 0x0a, 0x48, 0x0c, 0xbc, 0xc2, 0xf0, 0x53,
	0x84, 0xca, 0xcf, 0xa3, 0x84, 0xdb, 0x0d, 0x2d, 0xda, 0xce, 0x33, 0xc7, 0xae, 0x44, 0x77, 0xda,
	0x32, 0xf8, 0xde, 0xd7, 0x1a, 0x6a, 0x8e, 0xcb, 0xb4, 0xe1, 0x03, 0x64, 0x4d, 0xf4, 0xc4, 0xda,
	0x83, 0xbf, 0x5d, 0xc2, 0x23, 0x77, 0x32, 0xe7, 0xf0, 0x1a, 0x24, 0xf1, 0xbb, 0x97, 0x99, 0xf3,
	0xd7, 0x55, 0xe6, 0x58, 0x79, 0xe6, 0x2c, 0xed, 0x47, 0x34, 0x8e, 0x28, 0x9c, 0x5a, 0x13, 0x7c,
	0x88, 0xac, 0x91, 0x9e, 0x5b, 0x7b, 0xb0, 0xa2, 0x15, 0xa3, 0xe9, 0x7b, 0x08, 0xa4, 0xd6, 0x6c,
	0x1a, 0x9a, 0x8e, 0x0a, 0x82, 0xd1, 0x82, 0x35, 0xc2, 0x3e, 0x5a, 0x18, 0x73, 0x08, 0xf4, 0x10,
	0xdb, 0x83, 0x75, 0xb7, 0xca, 0xb8, 0x5b, 0xb5, 0xa3, 0xaa, 0xfe, 0xba, 0x32, 0x51, 0x06, 0x82,
	0x43, 0x60, 0x4e, 0x4b, 0x55, 0xf1, 0x4b, 0xd4, 0x18, 0x4b, 0x22, 0x53, 0x35, 0x57, 0xe5, 0x62,
	0xff, 0xc1, 0x45, 0xd7, 0x7d, 0xbb, 0xf4, 0x59, 0x15, 0x7a, 0x6d, 0xde, 0x6c, 0x41, 0x3c, 0xd9,
	0xfa, 0xfe, 0xe5, 0x9f, 0x0d, 0xd4, 0xf6, 0x3e, 0x8d, 0xdc, 0x89, 0x4e, 0xd5, 0x67, 0xdc, 0xac,
	0xde, 0x61, 0xef, 0xa7, 0x85, 0x96, 0xcd, 0xbe, 0xf0, 0x33, 0xb4, 0x3c, 0x94, 0x92, 0x04, 0xe7,
	0xfa, 0x7a, 0x55, 0xce, 0xd4, 0xbd, 0x3a, 0x97, 0xc5, 0x71, 0x37, 0x88, 0xae, 0x15, 0x93, 0x37,
	0x7f, 0x76, 0x4b, 0x84, 0x5f, 0xa0, 0xa5, 0x63, 0xaa, 0xf2, 0x2a, 0xec, 0xda, 0x6e, 0x7d, 0xaf,
	0x3d, 0x58, 0x35, 0xfa, 0xd7, 0x41, 0x2e, 0x86, 0xa8, 0x22, 0x10, 0xd1, 0x7e, 0xa2, 0x48, 0x33,
	0x02, 0xa5, 0x18, 0x1f, 0xa3, 0xe6, 0x28, 0x95, 0x85, 0x51, 0xfd, 0x1e, 0xa3, 0xad, 0xd2, 0xa8,
	0xcb, 0x52, 0x79, 0xc7, 0xe9, 0x46, 0xde, 0x7b, 0x85, 0x3a, 0xb7, 0x27, 0x87, 0x0f, 0x51, 0xeb,
	0x2d, 0x4b, 0x3e, 0xc4, 0x8c, 0x9c, 0x55, 0xc7, 0xdc, 0x2a, 0x8f, 0xd9, 0xbd, 0xa8, 0x0a, 0x66,
	0xe8, 0x6f, 0x68, 0x7f, 0xf9, 0xf2, 0x7a, 0xc7, 0xba, 0xba, 0xde, 0xb1, 0x7e, 0x5c, 0xef, 0x58,
	0x27, 0xd6, 0xb4, 0xa1, 0xdf, 0xe9, 0xa3, 0x5f, 0x01, 0x00, 0x00, 0xff, 0xff, 0x38, 0xd0, 0xe0,
	0x16, 0xe0, 0x04, 0x00, 0x00,
}
