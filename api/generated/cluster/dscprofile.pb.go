// Code generated by protoc-gen-gogo. DO NOT EDIT.
// source: dscprofile.proto

package cluster

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

// Profile
type DSCProfile struct {
	//
	api.TypeMeta `protobuf:"bytes,1,opt,name=T,json=,inline,embedded=T" json:",inline"`
	//
	api.ObjectMeta `protobuf:"bytes,2,opt,name=O,json=meta,omitempty,embedded=O" json:"meta,omitempty"`
	//
	Spec DSCProfileSpec `protobuf:"bytes,3,opt,name=Spec,json=spec,inline" json:"spec,inline"`
	//
	Status DSCProfileStatus `protobuf:"bytes,4,opt,name=Status,json=status,omitempty" json:"status,omitempty"`
}

func (m *DSCProfile) Reset()                    { *m = DSCProfile{} }
func (m *DSCProfile) String() string            { return proto.CompactTextString(m) }
func (*DSCProfile) ProtoMessage()               {}
func (*DSCProfile) Descriptor() ([]byte, []int) { return fileDescriptorDscprofile, []int{0} }

func (m *DSCProfile) GetSpec() DSCProfileSpec {
	if m != nil {
		return m.Spec
	}
	return DSCProfileSpec{}
}

func (m *DSCProfile) GetStatus() DSCProfileStatus {
	if m != nil {
		return m.Status
	}
	return DSCProfileStatus{}
}

// ProfileSpec - Spec applicable to DSC
type DSCProfileSpec struct {
	//
	Features FeatureSet `protobuf:"bytes,1,opt,name=Features,json=feature-set" json:"feature-set"`
}

func (m *DSCProfileSpec) Reset()                    { *m = DSCProfileSpec{} }
func (m *DSCProfileSpec) String() string            { return proto.CompactTextString(m) }
func (*DSCProfileSpec) ProtoMessage()               {}
func (*DSCProfileSpec) Descriptor() ([]byte, []int) { return fileDescriptorDscprofile, []int{1} }

func (m *DSCProfileSpec) GetFeatures() FeatureSet {
	if m != nil {
		return m.Features
	}
	return FeatureSet{}
}

//
type DSCProfileStatus struct {
	// The status of the configuration propagation to naples
	PropagationStatus PropagationStatus `protobuf:"bytes,1,opt,name=PropagationStatus,json=propagation-status" json:"propagation-status"`
}

func (m *DSCProfileStatus) Reset()                    { *m = DSCProfileStatus{} }
func (m *DSCProfileStatus) String() string            { return proto.CompactTextString(m) }
func (*DSCProfileStatus) ProtoMessage()               {}
func (*DSCProfileStatus) Descriptor() ([]byte, []int) { return fileDescriptorDscprofile, []int{2} }

func (m *DSCProfileStatus) GetPropagationStatus() PropagationStatus {
	if m != nil {
		return m.PropagationStatus
	}
	return PropagationStatus{}
}

//
type FeatureSet struct {
	// ui-hint: InterVMServices
	InterVMServices bool `protobuf:"varint,1,opt,name=InterVMServices,proto3" json:"InterVMServices,omitempty"`
	// ui-hint: FlowAware
	FlowAware bool `protobuf:"varint,2,opt,name=FlowAware,proto3" json:"FlowAware,omitempty"`
	// ui-hint: Firewall
	Firewall bool `protobuf:"varint,3,opt,name=Firewall,proto3" json:"Firewall,omitempty"`
}

func (m *FeatureSet) Reset()                    { *m = FeatureSet{} }
func (m *FeatureSet) String() string            { return proto.CompactTextString(m) }
func (*FeatureSet) ProtoMessage()               {}
func (*FeatureSet) Descriptor() ([]byte, []int) { return fileDescriptorDscprofile, []int{3} }

func (m *FeatureSet) GetInterVMServices() bool {
	if m != nil {
		return m.InterVMServices
	}
	return false
}

func (m *FeatureSet) GetFlowAware() bool {
	if m != nil {
		return m.FlowAware
	}
	return false
}

func (m *FeatureSet) GetFirewall() bool {
	if m != nil {
		return m.Firewall
	}
	return false
}

// ------------------------------------- Profile Object ---------------------------
type PropagationStatus struct {
	// The Generation ID this status is for
	GenerationID string `protobuf:"bytes,1,opt,name=GenerationID,json=generation-id,proto3" json:"generation-id"`
	// The number of Naples that this version has already been pushed to
	Updated int32 `protobuf:"varint,2,opt,name=Updated,json=updated,proto3" json:"updated"`
	// Number of Naples pending. If this is 0 it can be assumed that everything is up to date.
	Pending int32 `protobuf:"varint,3,opt,name=Pending,json=pending,proto3" json:"pending"`
	// The Version running on the slowest Naples
	MinVersion string `protobuf:"bytes,4,opt,name=MinVersion,json=min-version,proto3" json:"min-version"`
	// Textual description of propagation status
	Status string `protobuf:"bytes,5,opt,name=Status,json=status,proto3" json:"status"`
	// list of DSCs where propagation did not complete
	PendingNaples []string `protobuf:"bytes,6,rep,name=PendingNaples,json=pending-dscs" json:"pending-dscs"`
}

func (m *PropagationStatus) Reset()                    { *m = PropagationStatus{} }
func (m *PropagationStatus) String() string            { return proto.CompactTextString(m) }
func (*PropagationStatus) ProtoMessage()               {}
func (*PropagationStatus) Descriptor() ([]byte, []int) { return fileDescriptorDscprofile, []int{4} }

func (m *PropagationStatus) GetGenerationID() string {
	if m != nil {
		return m.GenerationID
	}
	return ""
}

func (m *PropagationStatus) GetUpdated() int32 {
	if m != nil {
		return m.Updated
	}
	return 0
}

func (m *PropagationStatus) GetPending() int32 {
	if m != nil {
		return m.Pending
	}
	return 0
}

func (m *PropagationStatus) GetMinVersion() string {
	if m != nil {
		return m.MinVersion
	}
	return ""
}

func (m *PropagationStatus) GetStatus() string {
	if m != nil {
		return m.Status
	}
	return ""
}

func (m *PropagationStatus) GetPendingNaples() []string {
	if m != nil {
		return m.PendingNaples
	}
	return nil
}

func init() {
	proto.RegisterType((*DSCProfile)(nil), "cluster.DSCProfile")
	proto.RegisterType((*DSCProfileSpec)(nil), "cluster.DSCProfileSpec")
	proto.RegisterType((*DSCProfileStatus)(nil), "cluster.DSCProfileStatus")
	proto.RegisterType((*FeatureSet)(nil), "cluster.FeatureSet")
	proto.RegisterType((*PropagationStatus)(nil), "cluster.PropagationStatus")
}
func (m *DSCProfile) Marshal() (dAtA []byte, err error) {
	size := m.Size()
	dAtA = make([]byte, size)
	n, err := m.MarshalTo(dAtA)
	if err != nil {
		return nil, err
	}
	return dAtA[:n], nil
}

func (m *DSCProfile) MarshalTo(dAtA []byte) (int, error) {
	var i int
	_ = i
	var l int
	_ = l
	dAtA[i] = 0xa
	i++
	i = encodeVarintDscprofile(dAtA, i, uint64(m.TypeMeta.Size()))
	n1, err := m.TypeMeta.MarshalTo(dAtA[i:])
	if err != nil {
		return 0, err
	}
	i += n1
	dAtA[i] = 0x12
	i++
	i = encodeVarintDscprofile(dAtA, i, uint64(m.ObjectMeta.Size()))
	n2, err := m.ObjectMeta.MarshalTo(dAtA[i:])
	if err != nil {
		return 0, err
	}
	i += n2
	dAtA[i] = 0x1a
	i++
	i = encodeVarintDscprofile(dAtA, i, uint64(m.Spec.Size()))
	n3, err := m.Spec.MarshalTo(dAtA[i:])
	if err != nil {
		return 0, err
	}
	i += n3
	dAtA[i] = 0x22
	i++
	i = encodeVarintDscprofile(dAtA, i, uint64(m.Status.Size()))
	n4, err := m.Status.MarshalTo(dAtA[i:])
	if err != nil {
		return 0, err
	}
	i += n4
	return i, nil
}

func (m *DSCProfileSpec) Marshal() (dAtA []byte, err error) {
	size := m.Size()
	dAtA = make([]byte, size)
	n, err := m.MarshalTo(dAtA)
	if err != nil {
		return nil, err
	}
	return dAtA[:n], nil
}

func (m *DSCProfileSpec) MarshalTo(dAtA []byte) (int, error) {
	var i int
	_ = i
	var l int
	_ = l
	dAtA[i] = 0xa
	i++
	i = encodeVarintDscprofile(dAtA, i, uint64(m.Features.Size()))
	n5, err := m.Features.MarshalTo(dAtA[i:])
	if err != nil {
		return 0, err
	}
	i += n5
	return i, nil
}

func (m *DSCProfileStatus) Marshal() (dAtA []byte, err error) {
	size := m.Size()
	dAtA = make([]byte, size)
	n, err := m.MarshalTo(dAtA)
	if err != nil {
		return nil, err
	}
	return dAtA[:n], nil
}

func (m *DSCProfileStatus) MarshalTo(dAtA []byte) (int, error) {
	var i int
	_ = i
	var l int
	_ = l
	dAtA[i] = 0xa
	i++
	i = encodeVarintDscprofile(dAtA, i, uint64(m.PropagationStatus.Size()))
	n6, err := m.PropagationStatus.MarshalTo(dAtA[i:])
	if err != nil {
		return 0, err
	}
	i += n6
	return i, nil
}

func (m *FeatureSet) Marshal() (dAtA []byte, err error) {
	size := m.Size()
	dAtA = make([]byte, size)
	n, err := m.MarshalTo(dAtA)
	if err != nil {
		return nil, err
	}
	return dAtA[:n], nil
}

func (m *FeatureSet) MarshalTo(dAtA []byte) (int, error) {
	var i int
	_ = i
	var l int
	_ = l
	if m.InterVMServices {
		dAtA[i] = 0x8
		i++
		if m.InterVMServices {
			dAtA[i] = 1
		} else {
			dAtA[i] = 0
		}
		i++
	}
	if m.FlowAware {
		dAtA[i] = 0x10
		i++
		if m.FlowAware {
			dAtA[i] = 1
		} else {
			dAtA[i] = 0
		}
		i++
	}
	if m.Firewall {
		dAtA[i] = 0x18
		i++
		if m.Firewall {
			dAtA[i] = 1
		} else {
			dAtA[i] = 0
		}
		i++
	}
	return i, nil
}

func (m *PropagationStatus) Marshal() (dAtA []byte, err error) {
	size := m.Size()
	dAtA = make([]byte, size)
	n, err := m.MarshalTo(dAtA)
	if err != nil {
		return nil, err
	}
	return dAtA[:n], nil
}

func (m *PropagationStatus) MarshalTo(dAtA []byte) (int, error) {
	var i int
	_ = i
	var l int
	_ = l
	if len(m.GenerationID) > 0 {
		dAtA[i] = 0xa
		i++
		i = encodeVarintDscprofile(dAtA, i, uint64(len(m.GenerationID)))
		i += copy(dAtA[i:], m.GenerationID)
	}
	if m.Updated != 0 {
		dAtA[i] = 0x10
		i++
		i = encodeVarintDscprofile(dAtA, i, uint64(m.Updated))
	}
	if m.Pending != 0 {
		dAtA[i] = 0x18
		i++
		i = encodeVarintDscprofile(dAtA, i, uint64(m.Pending))
	}
	if len(m.MinVersion) > 0 {
		dAtA[i] = 0x22
		i++
		i = encodeVarintDscprofile(dAtA, i, uint64(len(m.MinVersion)))
		i += copy(dAtA[i:], m.MinVersion)
	}
	if len(m.Status) > 0 {
		dAtA[i] = 0x2a
		i++
		i = encodeVarintDscprofile(dAtA, i, uint64(len(m.Status)))
		i += copy(dAtA[i:], m.Status)
	}
	if len(m.PendingNaples) > 0 {
		for _, s := range m.PendingNaples {
			dAtA[i] = 0x32
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

func encodeVarintDscprofile(dAtA []byte, offset int, v uint64) int {
	for v >= 1<<7 {
		dAtA[offset] = uint8(v&0x7f | 0x80)
		v >>= 7
		offset++
	}
	dAtA[offset] = uint8(v)
	return offset + 1
}
func (m *DSCProfile) Size() (n int) {
	var l int
	_ = l
	l = m.TypeMeta.Size()
	n += 1 + l + sovDscprofile(uint64(l))
	l = m.ObjectMeta.Size()
	n += 1 + l + sovDscprofile(uint64(l))
	l = m.Spec.Size()
	n += 1 + l + sovDscprofile(uint64(l))
	l = m.Status.Size()
	n += 1 + l + sovDscprofile(uint64(l))
	return n
}

func (m *DSCProfileSpec) Size() (n int) {
	var l int
	_ = l
	l = m.Features.Size()
	n += 1 + l + sovDscprofile(uint64(l))
	return n
}

func (m *DSCProfileStatus) Size() (n int) {
	var l int
	_ = l
	l = m.PropagationStatus.Size()
	n += 1 + l + sovDscprofile(uint64(l))
	return n
}

func (m *FeatureSet) Size() (n int) {
	var l int
	_ = l
	if m.InterVMServices {
		n += 2
	}
	if m.FlowAware {
		n += 2
	}
	if m.Firewall {
		n += 2
	}
	return n
}

func (m *PropagationStatus) Size() (n int) {
	var l int
	_ = l
	l = len(m.GenerationID)
	if l > 0 {
		n += 1 + l + sovDscprofile(uint64(l))
	}
	if m.Updated != 0 {
		n += 1 + sovDscprofile(uint64(m.Updated))
	}
	if m.Pending != 0 {
		n += 1 + sovDscprofile(uint64(m.Pending))
	}
	l = len(m.MinVersion)
	if l > 0 {
		n += 1 + l + sovDscprofile(uint64(l))
	}
	l = len(m.Status)
	if l > 0 {
		n += 1 + l + sovDscprofile(uint64(l))
	}
	if len(m.PendingNaples) > 0 {
		for _, s := range m.PendingNaples {
			l = len(s)
			n += 1 + l + sovDscprofile(uint64(l))
		}
	}
	return n
}

func sovDscprofile(x uint64) (n int) {
	for {
		n++
		x >>= 7
		if x == 0 {
			break
		}
	}
	return n
}
func sozDscprofile(x uint64) (n int) {
	return sovDscprofile(uint64((x << 1) ^ uint64((int64(x) >> 63))))
}
func (m *DSCProfile) Unmarshal(dAtA []byte) error {
	l := len(dAtA)
	iNdEx := 0
	for iNdEx < l {
		preIndex := iNdEx
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return ErrIntOverflowDscprofile
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
			return fmt.Errorf("proto: DSCProfile: wiretype end group for non-group")
		}
		if fieldNum <= 0 {
			return fmt.Errorf("proto: DSCProfile: illegal tag %d (wire type %d)", fieldNum, wire)
		}
		switch fieldNum {
		case 1:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field TypeMeta", wireType)
			}
			var msglen int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowDscprofile
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
				return ErrInvalidLengthDscprofile
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
					return ErrIntOverflowDscprofile
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
				return ErrInvalidLengthDscprofile
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
					return ErrIntOverflowDscprofile
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
				return ErrInvalidLengthDscprofile
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
					return ErrIntOverflowDscprofile
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
				return ErrInvalidLengthDscprofile
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
			skippy, err := skipDscprofile(dAtA[iNdEx:])
			if err != nil {
				return err
			}
			if skippy < 0 {
				return ErrInvalidLengthDscprofile
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
func (m *DSCProfileSpec) Unmarshal(dAtA []byte) error {
	l := len(dAtA)
	iNdEx := 0
	for iNdEx < l {
		preIndex := iNdEx
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return ErrIntOverflowDscprofile
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
			return fmt.Errorf("proto: DSCProfileSpec: wiretype end group for non-group")
		}
		if fieldNum <= 0 {
			return fmt.Errorf("proto: DSCProfileSpec: illegal tag %d (wire type %d)", fieldNum, wire)
		}
		switch fieldNum {
		case 1:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field Features", wireType)
			}
			var msglen int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowDscprofile
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
				return ErrInvalidLengthDscprofile
			}
			postIndex := iNdEx + msglen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			if err := m.Features.Unmarshal(dAtA[iNdEx:postIndex]); err != nil {
				return err
			}
			iNdEx = postIndex
		default:
			iNdEx = preIndex
			skippy, err := skipDscprofile(dAtA[iNdEx:])
			if err != nil {
				return err
			}
			if skippy < 0 {
				return ErrInvalidLengthDscprofile
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
func (m *DSCProfileStatus) Unmarshal(dAtA []byte) error {
	l := len(dAtA)
	iNdEx := 0
	for iNdEx < l {
		preIndex := iNdEx
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return ErrIntOverflowDscprofile
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
			return fmt.Errorf("proto: DSCProfileStatus: wiretype end group for non-group")
		}
		if fieldNum <= 0 {
			return fmt.Errorf("proto: DSCProfileStatus: illegal tag %d (wire type %d)", fieldNum, wire)
		}
		switch fieldNum {
		case 1:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field PropagationStatus", wireType)
			}
			var msglen int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowDscprofile
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
				return ErrInvalidLengthDscprofile
			}
			postIndex := iNdEx + msglen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			if err := m.PropagationStatus.Unmarshal(dAtA[iNdEx:postIndex]); err != nil {
				return err
			}
			iNdEx = postIndex
		default:
			iNdEx = preIndex
			skippy, err := skipDscprofile(dAtA[iNdEx:])
			if err != nil {
				return err
			}
			if skippy < 0 {
				return ErrInvalidLengthDscprofile
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
func (m *FeatureSet) Unmarshal(dAtA []byte) error {
	l := len(dAtA)
	iNdEx := 0
	for iNdEx < l {
		preIndex := iNdEx
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return ErrIntOverflowDscprofile
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
			return fmt.Errorf("proto: FeatureSet: wiretype end group for non-group")
		}
		if fieldNum <= 0 {
			return fmt.Errorf("proto: FeatureSet: illegal tag %d (wire type %d)", fieldNum, wire)
		}
		switch fieldNum {
		case 1:
			if wireType != 0 {
				return fmt.Errorf("proto: wrong wireType = %d for field InterVMServices", wireType)
			}
			var v int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowDscprofile
				}
				if iNdEx >= l {
					return io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				v |= (int(b) & 0x7F) << shift
				if b < 0x80 {
					break
				}
			}
			m.InterVMServices = bool(v != 0)
		case 2:
			if wireType != 0 {
				return fmt.Errorf("proto: wrong wireType = %d for field FlowAware", wireType)
			}
			var v int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowDscprofile
				}
				if iNdEx >= l {
					return io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				v |= (int(b) & 0x7F) << shift
				if b < 0x80 {
					break
				}
			}
			m.FlowAware = bool(v != 0)
		case 3:
			if wireType != 0 {
				return fmt.Errorf("proto: wrong wireType = %d for field Firewall", wireType)
			}
			var v int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowDscprofile
				}
				if iNdEx >= l {
					return io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				v |= (int(b) & 0x7F) << shift
				if b < 0x80 {
					break
				}
			}
			m.Firewall = bool(v != 0)
		default:
			iNdEx = preIndex
			skippy, err := skipDscprofile(dAtA[iNdEx:])
			if err != nil {
				return err
			}
			if skippy < 0 {
				return ErrInvalidLengthDscprofile
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
func (m *PropagationStatus) Unmarshal(dAtA []byte) error {
	l := len(dAtA)
	iNdEx := 0
	for iNdEx < l {
		preIndex := iNdEx
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return ErrIntOverflowDscprofile
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
			return fmt.Errorf("proto: PropagationStatus: wiretype end group for non-group")
		}
		if fieldNum <= 0 {
			return fmt.Errorf("proto: PropagationStatus: illegal tag %d (wire type %d)", fieldNum, wire)
		}
		switch fieldNum {
		case 1:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field GenerationID", wireType)
			}
			var stringLen uint64
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowDscprofile
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
				return ErrInvalidLengthDscprofile
			}
			postIndex := iNdEx + intStringLen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.GenerationID = string(dAtA[iNdEx:postIndex])
			iNdEx = postIndex
		case 2:
			if wireType != 0 {
				return fmt.Errorf("proto: wrong wireType = %d for field Updated", wireType)
			}
			m.Updated = 0
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowDscprofile
				}
				if iNdEx >= l {
					return io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				m.Updated |= (int32(b) & 0x7F) << shift
				if b < 0x80 {
					break
				}
			}
		case 3:
			if wireType != 0 {
				return fmt.Errorf("proto: wrong wireType = %d for field Pending", wireType)
			}
			m.Pending = 0
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowDscprofile
				}
				if iNdEx >= l {
					return io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				m.Pending |= (int32(b) & 0x7F) << shift
				if b < 0x80 {
					break
				}
			}
		case 4:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field MinVersion", wireType)
			}
			var stringLen uint64
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowDscprofile
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
				return ErrInvalidLengthDscprofile
			}
			postIndex := iNdEx + intStringLen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.MinVersion = string(dAtA[iNdEx:postIndex])
			iNdEx = postIndex
		case 5:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field Status", wireType)
			}
			var stringLen uint64
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowDscprofile
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
				return ErrInvalidLengthDscprofile
			}
			postIndex := iNdEx + intStringLen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.Status = string(dAtA[iNdEx:postIndex])
			iNdEx = postIndex
		case 6:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field PendingNaples", wireType)
			}
			var stringLen uint64
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowDscprofile
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
				return ErrInvalidLengthDscprofile
			}
			postIndex := iNdEx + intStringLen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.PendingNaples = append(m.PendingNaples, string(dAtA[iNdEx:postIndex]))
			iNdEx = postIndex
		default:
			iNdEx = preIndex
			skippy, err := skipDscprofile(dAtA[iNdEx:])
			if err != nil {
				return err
			}
			if skippy < 0 {
				return ErrInvalidLengthDscprofile
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
func skipDscprofile(dAtA []byte) (n int, err error) {
	l := len(dAtA)
	iNdEx := 0
	for iNdEx < l {
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return 0, ErrIntOverflowDscprofile
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
					return 0, ErrIntOverflowDscprofile
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
					return 0, ErrIntOverflowDscprofile
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
				return 0, ErrInvalidLengthDscprofile
			}
			return iNdEx, nil
		case 3:
			for {
				var innerWire uint64
				var start int = iNdEx
				for shift := uint(0); ; shift += 7 {
					if shift >= 64 {
						return 0, ErrIntOverflowDscprofile
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
				next, err := skipDscprofile(dAtA[start:])
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
	ErrInvalidLengthDscprofile = fmt.Errorf("proto: negative length found during unmarshaling")
	ErrIntOverflowDscprofile   = fmt.Errorf("proto: integer overflow")
)

func init() { proto.RegisterFile("dscprofile.proto", fileDescriptorDscprofile) }

var fileDescriptorDscprofile = []byte{
	// 627 bytes of a gzipped FileDescriptorProto
	0x1f, 0x8b, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xff, 0x74, 0x53, 0xcf, 0x4e, 0xdb, 0x4e,
	0x10, 0xc6, 0xfc, 0x09, 0xc9, 0x86, 0x40, 0x58, 0x0e, 0xbf, 0x10, 0xa1, 0x18, 0x45, 0x42, 0xe2,
	0x40, 0xe2, 0x9f, 0x5a, 0x95, 0x43, 0x6f, 0x75, 0x69, 0x10, 0x07, 0x4a, 0xe4, 0x00, 0x52, 0x8f,
	0x1b, 0x7b, 0x70, 0xb7, 0x72, 0x76, 0x57, 0xde, 0x35, 0x11, 0x0f, 0xd0, 0x57, 0xe9, 0x6b, 0xf4,
	0xca, 0x11, 0xf5, 0x01, 0xac, 0x2a, 0xa7, 0x2a, 0x4f, 0x51, 0x79, 0xbd, 0x49, 0x0c, 0xa4, 0x27,
	0xcf, 0xf7, 0xed, 0xcc, 0x7c, 0xdf, 0xec, 0x8e, 0x51, 0x3d, 0x90, 0xbe, 0x88, 0xf9, 0x1d, 0x8d,
	0xa0, 0x2b, 0x62, 0xae, 0x38, 0xde, 0xf4, 0xa3, 0x44, 0x2a, 0x88, 0x9b, 0x07, 0x21, 0xe7, 0x61,
	0x04, 0x0e, 0x11, 0xd4, 0x21, 0x8c, 0x71, 0x45, 0x14, 0xe5, 0x4c, 0xe6, 0x69, 0xcd, 0x4f, 0x21,
	0x55, 0x5f, 0x93, 0x61, 0xd7, 0xe7, 0x23, 0x47, 0x00, 0x93, 0x84, 0x05, 0xdc, 0x91, 0x63, 0xe7,
	0x1e, 0x18, 0xf5, 0xc1, 0x49, 0x14, 0x8d, 0x64, 0x56, 0x1a, 0x02, 0x2b, 0x56, 0x3b, 0x94, 0xf9,
	0x51, 0x12, 0xc0, 0xac, 0x4d, 0xa7, 0xd0, 0x26, 0xe4, 0x21, 0x77, 0x34, 0x3d, 0x4c, 0xee, 0x34,
	0xd2, 0x40, 0x47, 0x26, 0xfd, 0xe8, 0x1f, 0xaa, 0x99, 0xc7, 0x11, 0x28, 0x92, 0xa7, 0xb5, 0x7f,
	0xae, 0x22, 0x74, 0x36, 0xf8, 0xd8, 0xcf, 0x07, 0xc3, 0xa7, 0xc8, 0xba, 0x6e, 0x58, 0x87, 0xd6,
	0x71, 0xf5, 0x4d, 0xad, 0x4b, 0x04, 0xed, 0x5e, 0x3f, 0x08, 0xb8, 0x04, 0x45, 0xdc, 0xbd, 0xc7,
	0xd4, 0x5e, 0x79, 0x4a, 0x6d, 0x6b, 0x9a, 0xda, 0x9b, 0x27, 0x94, 0x45, 0x94, 0x81, 0x37, 0x0b,
	0x70, 0x0f, 0x59, 0x57, 0x8d, 0x55, 0x5d, 0xb7, 0xa3, 0xeb, 0xae, 0x86, 0xdf, 0xc0, 0x57, 0xba,
	0xb2, 0x59, 0xa8, 0xdc, 0xce, 0xa4, 0x4f, 0xf8, 0x88, 0x2a, 0x18, 0x09, 0xf5, 0xe0, 0xbd, 0xc0,
	0xf8, 0x1c, 0xad, 0x0f, 0x04, 0xf8, 0x8d, 0x35, 0xdd, 0xea, 0xbf, 0xae, 0xb9, 0xe1, 0xee, 0xc2,
	0x62, 0x76, 0x9c, 0x9b, 0x99, 0xa6, 0x76, 0x55, 0x0a, 0xf0, 0x67, 0x66, 0x8a, 0x00, 0xdf, 0xa0,
	0xd2, 0x40, 0x11, 0x95, 0xc8, 0xc6, 0xba, 0x6e, 0xb5, 0xbf, 0xac, 0x95, 0x4e, 0x70, 0x1b, 0xa6,
	0x59, 0x5d, 0x6a, 0x5c, 0x70, 0xf7, 0x8a, 0x79, 0xbf, 0xfb, 0xeb, 0xfb, 0x7e, 0x0d, 0x57, 0x17,
	0xab, 0x20, 0xdb, 0x5f, 0xd0, 0xf6, 0x73, 0x77, 0xf8, 0x1c, 0x95, 0x7b, 0x40, 0x54, 0x12, 0x83,
	0x34, 0x77, 0xb9, 0x37, 0x57, 0x37, 0x07, 0x03, 0x50, 0x8b, 0x21, 0xee, 0x72, 0xae, 0x23, 0x41,
	0x79, 0x45, 0xd0, 0x7e, 0x40, 0xf5, 0x97, 0x6e, 0x31, 0xa0, 0xdd, 0x7e, 0xcc, 0x05, 0x09, 0xf5,
	0x96, 0x98, 0x19, 0x73, 0x95, 0xe6, 0x5c, 0xe5, 0x55, 0x46, 0xfe, 0x08, 0xd3, 0xd4, 0xc6, 0x62,
	0x71, 0xd4, 0xc9, 0xc7, 0xf3, 0x96, 0x70, 0x6d, 0x81, 0xd0, 0xc2, 0x2a, 0x3e, 0x46, 0x3b, 0x17,
	0x4c, 0x41, 0x7c, 0x7b, 0x39, 0x80, 0xf8, 0x9e, 0xfa, 0x66, 0xb0, 0xb2, 0xf7, 0x92, 0xc6, 0x07,
	0xa8, 0xd2, 0x8b, 0xf8, 0xf8, 0xc3, 0x98, 0xc4, 0xa0, 0x17, 0xa2, 0xec, 0x2d, 0x08, 0xdc, 0x44,
	0xe5, 0x1e, 0x8d, 0x61, 0x4c, 0xa2, 0x48, 0x3f, 0x71, 0xd9, 0x9b, 0xe3, 0xf6, 0x8f, 0xd5, 0x25,
	0x93, 0xe1, 0x53, 0xb4, 0x75, 0x0e, 0x0c, 0x62, 0xcd, 0x5d, 0x9c, 0x69, 0xd9, 0x8a, 0xbb, 0x3b,
	0x4d, 0xed, 0x5a, 0x38, 0xe7, 0x3b, 0x34, 0xf0, 0x9e, 0x43, 0x7c, 0x84, 0x36, 0x6f, 0x44, 0x40,
	0x14, 0x04, 0xda, 0xc5, 0x86, 0x5b, 0xcd, 0xf6, 0x36, 0xc9, 0x29, 0x6f, 0x16, 0x64, 0x69, 0x7d,
	0x60, 0x01, 0x65, 0xa1, 0xf6, 0x63, 0xd2, 0x44, 0x4e, 0x79, 0xb3, 0x00, 0xff, 0x8f, 0xd0, 0x25,
	0x65, 0xb7, 0x10, 0x4b, 0xca, 0x99, 0xde, 0xa8, 0x8a, 0xbb, 0x93, 0x3d, 0xdd, 0x88, 0xb2, 0xce,
	0x7d, 0x4e, 0x7b, 0x45, 0x80, 0xdb, 0xf3, 0xfd, 0xdb, 0xd0, 0xd9, 0x68, 0x9a, 0xda, 0x25, 0x73,
	0xdf, 0xe6, 0x8b, 0xdf, 0xa1, 0x9a, 0x11, 0xff, 0x4c, 0x44, 0x04, 0xb2, 0x51, 0x3a, 0x5c, 0x3b,
	0xae, 0xb8, 0xf5, 0x69, 0x6a, 0x6f, 0x19, 0xe5, 0x4e, 0x20, 0x7d, 0xe9, 0x3d, 0x43, 0x6e, 0xfd,
	0x71, 0xd2, 0xb2, 0x9e, 0x26, 0x2d, 0xeb, 0xf7, 0xa4, 0x65, 0xfd, 0x99, 0xb4, 0x56, 0xfa, 0xd6,
	0xb0, 0xa4, 0xff, 0xe6, 0xb7, 0x7f, 0x03, 0x00, 0x00, 0xff, 0xff, 0xf2, 0x0c, 0x45, 0xe8, 0xa5,
	0x04, 0x00, 0x00,
}
