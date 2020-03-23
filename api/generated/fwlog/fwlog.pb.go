// Code generated by protoc-gen-gogo. DO NOT EDIT.
// source: fwlog.proto

/*
	Package fwlog is a generated protocol buffer package.

	Service name

	It is generated from these files:
		fwlog.proto

	It has these top-level messages:
		FwLog
		FwLogList
*/
package fwlog

import proto "github.com/gogo/protobuf/proto"
import fmt "fmt"
import math "math"
import _ "github.com/pensando/grpc-gateway/third_party/googleapis/google/api"
import _ "github.com/pensando/sw/venice/utils/apigen/annotations"
import _ "github.com/gogo/protobuf/gogoproto"
import api "github.com/pensando/sw/api"
import _ "github.com/pensando/sw/api/fields"

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

// Enums for the response
type FwLogActions int32

const (
	// ui-hint: Allow
	FwLogActions_allow FwLogActions = 0
	// ui-hint: Deny
	FwLogActions_deny FwLogActions = 1
	// ui-hint: Reject
	FwLogActions_reject FwLogActions = 2
	// ui-hint: Implicit-deny
	FwLogActions_implicit_deny FwLogActions = 3
)

var FwLogActions_name = map[int32]string{
	0: "allow",
	1: "deny",
	2: "reject",
	3: "implicit_deny",
}
var FwLogActions_value = map[string]int32{
	"allow":         0,
	"deny":          1,
	"reject":        2,
	"implicit_deny": 3,
}

func (FwLogActions) EnumDescriptor() ([]byte, []int) { return fileDescriptorFwlog, []int{0} }

//
type FwLogDirections int32

const (
	// ui-hint: From Host
	FwLogDirections_from_host FwLogDirections = 0
	// ui-hint: From Uplink
	FwLogDirections_from_uplink FwLogDirections = 1
)

var FwLogDirections_name = map[int32]string{
	0: "from_host",
	1: "from_uplink",
}
var FwLogDirections_value = map[string]int32{
	"from_host":   0,
	"from_uplink": 1,
}

func (FwLogDirections) EnumDescriptor() ([]byte, []int) { return fileDescriptorFwlog, []int{1} }

//
type FwLog struct {
	//
	api.TypeMeta `protobuf:"bytes,1,opt,name=T,json=,inline,embedded=T" json:",inline"`
	//
	api.ObjectMeta `protobuf:"bytes,2,opt,name=O,json=meta,omitempty,embedded=O" json:"meta,omitempty"`
	// Source VRF,
	SrcVRF uint64 `protobuf:"varint,3,opt,name=SrcVRF,json=source-vrf,omitempty,proto3" json:"source-vrf,omitempty"`
	// Destination VRF,
	DestVRF uint64 `protobuf:"varint,4,opt,name=DestVRF,json=destination-vrf,omitempty,proto3" json:"destination-vrf,omitempty"`
	// Source IP,
	SrcIP string `protobuf:"bytes,5,opt,name=SrcIP,json=source-ip,omitempty,proto3" json:"source-ip,omitempty"`
	// Destination IP
	DestIP string `protobuf:"bytes,6,opt,name=DestIP,json=destination-ip,omitempty,proto3" json:"destination-ip,omitempty"`
	// Source Port
	SrcPort uint32 `protobuf:"varint,7,opt,name=SrcPort,json=source-port,omitempty,proto3" json:"source-port,omitempty"`
	// Destination Port
	DestPort uint32 `protobuf:"varint,8,opt,name=DestPort,json=destination-port,omitempty,proto3" json:"destination-port,omitempty"`
	// Protocol,
	Protocol string `protobuf:"bytes,9,opt,name=Protocol,json=protocol,omitempty,proto3" json:"protocol,omitempty"`
	// Action
	Action string `protobuf:"bytes,10,opt,name=Action,json=action,omitempty,proto3" json:"action,omitempty"`
	// Flow Direction
	Direction string `protobuf:"bytes,11,opt,name=Direction,json=direction,omitempty,proto3" json:"direction,omitempty"`
	// Rule ID
	RuleID uint64 `protobuf:"varint,12,opt,name=RuleID,json=rule-id,omitempty,proto3" json:"rule-id,omitempty"`
	// Session ID
	SessionID uint64 `protobuf:"varint,13,opt,name=SessionID,json=session-id,omitempty,proto3" json:"session-id,omitempty"`
	// Session state
	SessionState string `protobuf:"bytes,14,opt,name=SessionState,json=session-state,omitempty,proto3" json:"session-state,omitempty"`
	// Application ID
	AppID string `protobuf:"bytes,15,opt,name=AppID,json=app-id,omitempty,proto3" json:"app-id,omitempty"`
	// policy name
	PolicyName string `protobuf:"bytes,16,opt,name=PolicyName,json=policy-name,omitempty,proto3" json:"policy-name,omitempty"`
	// Reporter ID
	ReporterID string `protobuf:"bytes,17,opt,name=ReporterID,json=reporter-id,omitempty,proto3" json:"reporter-id,omitempty"`
	// Flow action
	FlowAction string `protobuf:"bytes,18,opt,name=FlowAction,json=flow-action,omitempty,proto3" json:"flow-action,omitempty"`
	// icmp type
	IcmpType uint32 `protobuf:"varint,19,opt,name=IcmpType,json=icmp-type,omitempty,proto3" json:"icmp-type,omitempty"`
	// icmp code
	IcmpCode uint32 `protobuf:"varint,20,opt,name=IcmpCode,json=icmp-code,omitempty,proto3" json:"icmp-code,omitempty"`
	// icmp ID
	IcmpID uint32 `protobuf:"varint,21,opt,name=IcmpID,json=icmp-id,omitempty,proto3" json:"icmp-id,omitempty"`
}

func (m *FwLog) Reset()                    { *m = FwLog{} }
func (m *FwLog) String() string            { return proto.CompactTextString(m) }
func (*FwLog) ProtoMessage()               {}
func (*FwLog) Descriptor() ([]byte, []int) { return fileDescriptorFwlog, []int{0} }

func (m *FwLog) GetSrcVRF() uint64 {
	if m != nil {
		return m.SrcVRF
	}
	return 0
}

func (m *FwLog) GetDestVRF() uint64 {
	if m != nil {
		return m.DestVRF
	}
	return 0
}

func (m *FwLog) GetSrcIP() string {
	if m != nil {
		return m.SrcIP
	}
	return ""
}

func (m *FwLog) GetDestIP() string {
	if m != nil {
		return m.DestIP
	}
	return ""
}

func (m *FwLog) GetSrcPort() uint32 {
	if m != nil {
		return m.SrcPort
	}
	return 0
}

func (m *FwLog) GetDestPort() uint32 {
	if m != nil {
		return m.DestPort
	}
	return 0
}

func (m *FwLog) GetProtocol() string {
	if m != nil {
		return m.Protocol
	}
	return ""
}

func (m *FwLog) GetAction() string {
	if m != nil {
		return m.Action
	}
	return ""
}

func (m *FwLog) GetDirection() string {
	if m != nil {
		return m.Direction
	}
	return ""
}

func (m *FwLog) GetRuleID() uint64 {
	if m != nil {
		return m.RuleID
	}
	return 0
}

func (m *FwLog) GetSessionID() uint64 {
	if m != nil {
		return m.SessionID
	}
	return 0
}

func (m *FwLog) GetSessionState() string {
	if m != nil {
		return m.SessionState
	}
	return ""
}

func (m *FwLog) GetAppID() string {
	if m != nil {
		return m.AppID
	}
	return ""
}

func (m *FwLog) GetPolicyName() string {
	if m != nil {
		return m.PolicyName
	}
	return ""
}

func (m *FwLog) GetReporterID() string {
	if m != nil {
		return m.ReporterID
	}
	return ""
}

func (m *FwLog) GetFlowAction() string {
	if m != nil {
		return m.FlowAction
	}
	return ""
}

func (m *FwLog) GetIcmpType() uint32 {
	if m != nil {
		return m.IcmpType
	}
	return 0
}

func (m *FwLog) GetIcmpCode() uint32 {
	if m != nil {
		return m.IcmpCode
	}
	return 0
}

func (m *FwLog) GetIcmpID() uint32 {
	if m != nil {
		return m.IcmpID
	}
	return 0
}

// list of fw logs
type FwLogList struct {
	//
	api.TypeMeta `protobuf:"bytes,1,opt,name=T,embedded=T" json:"T"`
	//
	api.ListMeta `protobuf:"bytes,2,opt,name=ListMeta,embedded=ListMeta" json:"ListMeta"`
	//
	Items []*FwLog `protobuf:"bytes,3,rep,name=Items,json=items,omitempty" json:"items,omitempty"`
}

func (m *FwLogList) Reset()                    { *m = FwLogList{} }
func (m *FwLogList) String() string            { return proto.CompactTextString(m) }
func (*FwLogList) ProtoMessage()               {}
func (*FwLogList) Descriptor() ([]byte, []int) { return fileDescriptorFwlog, []int{1} }

func (m *FwLogList) GetItems() []*FwLog {
	if m != nil {
		return m.Items
	}
	return nil
}

func init() {
	proto.RegisterType((*FwLog)(nil), "fwlog.FwLog")
	proto.RegisterType((*FwLogList)(nil), "fwlog.FwLogList")
	proto.RegisterEnum("fwlog.FwLogActions", FwLogActions_name, FwLogActions_value)
	proto.RegisterEnum("fwlog.FwLogDirections", FwLogDirections_name, FwLogDirections_value)
}
func (m *FwLog) Marshal() (dAtA []byte, err error) {
	size := m.Size()
	dAtA = make([]byte, size)
	n, err := m.MarshalTo(dAtA)
	if err != nil {
		return nil, err
	}
	return dAtA[:n], nil
}

func (m *FwLog) MarshalTo(dAtA []byte) (int, error) {
	var i int
	_ = i
	var l int
	_ = l
	dAtA[i] = 0xa
	i++
	i = encodeVarintFwlog(dAtA, i, uint64(m.TypeMeta.Size()))
	n1, err := m.TypeMeta.MarshalTo(dAtA[i:])
	if err != nil {
		return 0, err
	}
	i += n1
	dAtA[i] = 0x12
	i++
	i = encodeVarintFwlog(dAtA, i, uint64(m.ObjectMeta.Size()))
	n2, err := m.ObjectMeta.MarshalTo(dAtA[i:])
	if err != nil {
		return 0, err
	}
	i += n2
	if m.SrcVRF != 0 {
		dAtA[i] = 0x18
		i++
		i = encodeVarintFwlog(dAtA, i, uint64(m.SrcVRF))
	}
	if m.DestVRF != 0 {
		dAtA[i] = 0x20
		i++
		i = encodeVarintFwlog(dAtA, i, uint64(m.DestVRF))
	}
	if len(m.SrcIP) > 0 {
		dAtA[i] = 0x2a
		i++
		i = encodeVarintFwlog(dAtA, i, uint64(len(m.SrcIP)))
		i += copy(dAtA[i:], m.SrcIP)
	}
	if len(m.DestIP) > 0 {
		dAtA[i] = 0x32
		i++
		i = encodeVarintFwlog(dAtA, i, uint64(len(m.DestIP)))
		i += copy(dAtA[i:], m.DestIP)
	}
	if m.SrcPort != 0 {
		dAtA[i] = 0x38
		i++
		i = encodeVarintFwlog(dAtA, i, uint64(m.SrcPort))
	}
	if m.DestPort != 0 {
		dAtA[i] = 0x40
		i++
		i = encodeVarintFwlog(dAtA, i, uint64(m.DestPort))
	}
	if len(m.Protocol) > 0 {
		dAtA[i] = 0x4a
		i++
		i = encodeVarintFwlog(dAtA, i, uint64(len(m.Protocol)))
		i += copy(dAtA[i:], m.Protocol)
	}
	if len(m.Action) > 0 {
		dAtA[i] = 0x52
		i++
		i = encodeVarintFwlog(dAtA, i, uint64(len(m.Action)))
		i += copy(dAtA[i:], m.Action)
	}
	if len(m.Direction) > 0 {
		dAtA[i] = 0x5a
		i++
		i = encodeVarintFwlog(dAtA, i, uint64(len(m.Direction)))
		i += copy(dAtA[i:], m.Direction)
	}
	if m.RuleID != 0 {
		dAtA[i] = 0x60
		i++
		i = encodeVarintFwlog(dAtA, i, uint64(m.RuleID))
	}
	if m.SessionID != 0 {
		dAtA[i] = 0x68
		i++
		i = encodeVarintFwlog(dAtA, i, uint64(m.SessionID))
	}
	if len(m.SessionState) > 0 {
		dAtA[i] = 0x72
		i++
		i = encodeVarintFwlog(dAtA, i, uint64(len(m.SessionState)))
		i += copy(dAtA[i:], m.SessionState)
	}
	if len(m.AppID) > 0 {
		dAtA[i] = 0x7a
		i++
		i = encodeVarintFwlog(dAtA, i, uint64(len(m.AppID)))
		i += copy(dAtA[i:], m.AppID)
	}
	if len(m.PolicyName) > 0 {
		dAtA[i] = 0x82
		i++
		dAtA[i] = 0x1
		i++
		i = encodeVarintFwlog(dAtA, i, uint64(len(m.PolicyName)))
		i += copy(dAtA[i:], m.PolicyName)
	}
	if len(m.ReporterID) > 0 {
		dAtA[i] = 0x8a
		i++
		dAtA[i] = 0x1
		i++
		i = encodeVarintFwlog(dAtA, i, uint64(len(m.ReporterID)))
		i += copy(dAtA[i:], m.ReporterID)
	}
	if len(m.FlowAction) > 0 {
		dAtA[i] = 0x92
		i++
		dAtA[i] = 0x1
		i++
		i = encodeVarintFwlog(dAtA, i, uint64(len(m.FlowAction)))
		i += copy(dAtA[i:], m.FlowAction)
	}
	if m.IcmpType != 0 {
		dAtA[i] = 0x98
		i++
		dAtA[i] = 0x1
		i++
		i = encodeVarintFwlog(dAtA, i, uint64(m.IcmpType))
	}
	if m.IcmpCode != 0 {
		dAtA[i] = 0xa0
		i++
		dAtA[i] = 0x1
		i++
		i = encodeVarintFwlog(dAtA, i, uint64(m.IcmpCode))
	}
	if m.IcmpID != 0 {
		dAtA[i] = 0xa8
		i++
		dAtA[i] = 0x1
		i++
		i = encodeVarintFwlog(dAtA, i, uint64(m.IcmpID))
	}
	return i, nil
}

func (m *FwLogList) Marshal() (dAtA []byte, err error) {
	size := m.Size()
	dAtA = make([]byte, size)
	n, err := m.MarshalTo(dAtA)
	if err != nil {
		return nil, err
	}
	return dAtA[:n], nil
}

func (m *FwLogList) MarshalTo(dAtA []byte) (int, error) {
	var i int
	_ = i
	var l int
	_ = l
	dAtA[i] = 0xa
	i++
	i = encodeVarintFwlog(dAtA, i, uint64(m.TypeMeta.Size()))
	n3, err := m.TypeMeta.MarshalTo(dAtA[i:])
	if err != nil {
		return 0, err
	}
	i += n3
	dAtA[i] = 0x12
	i++
	i = encodeVarintFwlog(dAtA, i, uint64(m.ListMeta.Size()))
	n4, err := m.ListMeta.MarshalTo(dAtA[i:])
	if err != nil {
		return 0, err
	}
	i += n4
	if len(m.Items) > 0 {
		for _, msg := range m.Items {
			dAtA[i] = 0x1a
			i++
			i = encodeVarintFwlog(dAtA, i, uint64(msg.Size()))
			n, err := msg.MarshalTo(dAtA[i:])
			if err != nil {
				return 0, err
			}
			i += n
		}
	}
	return i, nil
}

func encodeVarintFwlog(dAtA []byte, offset int, v uint64) int {
	for v >= 1<<7 {
		dAtA[offset] = uint8(v&0x7f | 0x80)
		v >>= 7
		offset++
	}
	dAtA[offset] = uint8(v)
	return offset + 1
}
func (m *FwLog) Size() (n int) {
	var l int
	_ = l
	l = m.TypeMeta.Size()
	n += 1 + l + sovFwlog(uint64(l))
	l = m.ObjectMeta.Size()
	n += 1 + l + sovFwlog(uint64(l))
	if m.SrcVRF != 0 {
		n += 1 + sovFwlog(uint64(m.SrcVRF))
	}
	if m.DestVRF != 0 {
		n += 1 + sovFwlog(uint64(m.DestVRF))
	}
	l = len(m.SrcIP)
	if l > 0 {
		n += 1 + l + sovFwlog(uint64(l))
	}
	l = len(m.DestIP)
	if l > 0 {
		n += 1 + l + sovFwlog(uint64(l))
	}
	if m.SrcPort != 0 {
		n += 1 + sovFwlog(uint64(m.SrcPort))
	}
	if m.DestPort != 0 {
		n += 1 + sovFwlog(uint64(m.DestPort))
	}
	l = len(m.Protocol)
	if l > 0 {
		n += 1 + l + sovFwlog(uint64(l))
	}
	l = len(m.Action)
	if l > 0 {
		n += 1 + l + sovFwlog(uint64(l))
	}
	l = len(m.Direction)
	if l > 0 {
		n += 1 + l + sovFwlog(uint64(l))
	}
	if m.RuleID != 0 {
		n += 1 + sovFwlog(uint64(m.RuleID))
	}
	if m.SessionID != 0 {
		n += 1 + sovFwlog(uint64(m.SessionID))
	}
	l = len(m.SessionState)
	if l > 0 {
		n += 1 + l + sovFwlog(uint64(l))
	}
	l = len(m.AppID)
	if l > 0 {
		n += 1 + l + sovFwlog(uint64(l))
	}
	l = len(m.PolicyName)
	if l > 0 {
		n += 2 + l + sovFwlog(uint64(l))
	}
	l = len(m.ReporterID)
	if l > 0 {
		n += 2 + l + sovFwlog(uint64(l))
	}
	l = len(m.FlowAction)
	if l > 0 {
		n += 2 + l + sovFwlog(uint64(l))
	}
	if m.IcmpType != 0 {
		n += 2 + sovFwlog(uint64(m.IcmpType))
	}
	if m.IcmpCode != 0 {
		n += 2 + sovFwlog(uint64(m.IcmpCode))
	}
	if m.IcmpID != 0 {
		n += 2 + sovFwlog(uint64(m.IcmpID))
	}
	return n
}

func (m *FwLogList) Size() (n int) {
	var l int
	_ = l
	l = m.TypeMeta.Size()
	n += 1 + l + sovFwlog(uint64(l))
	l = m.ListMeta.Size()
	n += 1 + l + sovFwlog(uint64(l))
	if len(m.Items) > 0 {
		for _, e := range m.Items {
			l = e.Size()
			n += 1 + l + sovFwlog(uint64(l))
		}
	}
	return n
}

func sovFwlog(x uint64) (n int) {
	for {
		n++
		x >>= 7
		if x == 0 {
			break
		}
	}
	return n
}
func sozFwlog(x uint64) (n int) {
	return sovFwlog(uint64((x << 1) ^ uint64((int64(x) >> 63))))
}
func (m *FwLog) Unmarshal(dAtA []byte) error {
	l := len(dAtA)
	iNdEx := 0
	for iNdEx < l {
		preIndex := iNdEx
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return ErrIntOverflowFwlog
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
			return fmt.Errorf("proto: FwLog: wiretype end group for non-group")
		}
		if fieldNum <= 0 {
			return fmt.Errorf("proto: FwLog: illegal tag %d (wire type %d)", fieldNum, wire)
		}
		switch fieldNum {
		case 1:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field TypeMeta", wireType)
			}
			var msglen int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowFwlog
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
				return ErrInvalidLengthFwlog
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
					return ErrIntOverflowFwlog
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
				return ErrInvalidLengthFwlog
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
			if wireType != 0 {
				return fmt.Errorf("proto: wrong wireType = %d for field SrcVRF", wireType)
			}
			m.SrcVRF = 0
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowFwlog
				}
				if iNdEx >= l {
					return io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				m.SrcVRF |= (uint64(b) & 0x7F) << shift
				if b < 0x80 {
					break
				}
			}
		case 4:
			if wireType != 0 {
				return fmt.Errorf("proto: wrong wireType = %d for field DestVRF", wireType)
			}
			m.DestVRF = 0
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowFwlog
				}
				if iNdEx >= l {
					return io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				m.DestVRF |= (uint64(b) & 0x7F) << shift
				if b < 0x80 {
					break
				}
			}
		case 5:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field SrcIP", wireType)
			}
			var stringLen uint64
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowFwlog
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
				return ErrInvalidLengthFwlog
			}
			postIndex := iNdEx + intStringLen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.SrcIP = string(dAtA[iNdEx:postIndex])
			iNdEx = postIndex
		case 6:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field DestIP", wireType)
			}
			var stringLen uint64
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowFwlog
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
				return ErrInvalidLengthFwlog
			}
			postIndex := iNdEx + intStringLen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.DestIP = string(dAtA[iNdEx:postIndex])
			iNdEx = postIndex
		case 7:
			if wireType != 0 {
				return fmt.Errorf("proto: wrong wireType = %d for field SrcPort", wireType)
			}
			m.SrcPort = 0
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowFwlog
				}
				if iNdEx >= l {
					return io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				m.SrcPort |= (uint32(b) & 0x7F) << shift
				if b < 0x80 {
					break
				}
			}
		case 8:
			if wireType != 0 {
				return fmt.Errorf("proto: wrong wireType = %d for field DestPort", wireType)
			}
			m.DestPort = 0
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowFwlog
				}
				if iNdEx >= l {
					return io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				m.DestPort |= (uint32(b) & 0x7F) << shift
				if b < 0x80 {
					break
				}
			}
		case 9:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field Protocol", wireType)
			}
			var stringLen uint64
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowFwlog
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
				return ErrInvalidLengthFwlog
			}
			postIndex := iNdEx + intStringLen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.Protocol = string(dAtA[iNdEx:postIndex])
			iNdEx = postIndex
		case 10:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field Action", wireType)
			}
			var stringLen uint64
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowFwlog
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
				return ErrInvalidLengthFwlog
			}
			postIndex := iNdEx + intStringLen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.Action = string(dAtA[iNdEx:postIndex])
			iNdEx = postIndex
		case 11:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field Direction", wireType)
			}
			var stringLen uint64
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowFwlog
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
				return ErrInvalidLengthFwlog
			}
			postIndex := iNdEx + intStringLen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.Direction = string(dAtA[iNdEx:postIndex])
			iNdEx = postIndex
		case 12:
			if wireType != 0 {
				return fmt.Errorf("proto: wrong wireType = %d for field RuleID", wireType)
			}
			m.RuleID = 0
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowFwlog
				}
				if iNdEx >= l {
					return io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				m.RuleID |= (uint64(b) & 0x7F) << shift
				if b < 0x80 {
					break
				}
			}
		case 13:
			if wireType != 0 {
				return fmt.Errorf("proto: wrong wireType = %d for field SessionID", wireType)
			}
			m.SessionID = 0
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowFwlog
				}
				if iNdEx >= l {
					return io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				m.SessionID |= (uint64(b) & 0x7F) << shift
				if b < 0x80 {
					break
				}
			}
		case 14:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field SessionState", wireType)
			}
			var stringLen uint64
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowFwlog
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
				return ErrInvalidLengthFwlog
			}
			postIndex := iNdEx + intStringLen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.SessionState = string(dAtA[iNdEx:postIndex])
			iNdEx = postIndex
		case 15:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field AppID", wireType)
			}
			var stringLen uint64
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowFwlog
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
				return ErrInvalidLengthFwlog
			}
			postIndex := iNdEx + intStringLen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.AppID = string(dAtA[iNdEx:postIndex])
			iNdEx = postIndex
		case 16:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field PolicyName", wireType)
			}
			var stringLen uint64
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowFwlog
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
				return ErrInvalidLengthFwlog
			}
			postIndex := iNdEx + intStringLen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.PolicyName = string(dAtA[iNdEx:postIndex])
			iNdEx = postIndex
		case 17:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field ReporterID", wireType)
			}
			var stringLen uint64
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowFwlog
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
				return ErrInvalidLengthFwlog
			}
			postIndex := iNdEx + intStringLen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.ReporterID = string(dAtA[iNdEx:postIndex])
			iNdEx = postIndex
		case 18:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field FlowAction", wireType)
			}
			var stringLen uint64
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowFwlog
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
				return ErrInvalidLengthFwlog
			}
			postIndex := iNdEx + intStringLen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.FlowAction = string(dAtA[iNdEx:postIndex])
			iNdEx = postIndex
		case 19:
			if wireType != 0 {
				return fmt.Errorf("proto: wrong wireType = %d for field IcmpType", wireType)
			}
			m.IcmpType = 0
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowFwlog
				}
				if iNdEx >= l {
					return io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				m.IcmpType |= (uint32(b) & 0x7F) << shift
				if b < 0x80 {
					break
				}
			}
		case 20:
			if wireType != 0 {
				return fmt.Errorf("proto: wrong wireType = %d for field IcmpCode", wireType)
			}
			m.IcmpCode = 0
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowFwlog
				}
				if iNdEx >= l {
					return io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				m.IcmpCode |= (uint32(b) & 0x7F) << shift
				if b < 0x80 {
					break
				}
			}
		case 21:
			if wireType != 0 {
				return fmt.Errorf("proto: wrong wireType = %d for field IcmpID", wireType)
			}
			m.IcmpID = 0
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowFwlog
				}
				if iNdEx >= l {
					return io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				m.IcmpID |= (uint32(b) & 0x7F) << shift
				if b < 0x80 {
					break
				}
			}
		default:
			iNdEx = preIndex
			skippy, err := skipFwlog(dAtA[iNdEx:])
			if err != nil {
				return err
			}
			if skippy < 0 {
				return ErrInvalidLengthFwlog
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
func (m *FwLogList) Unmarshal(dAtA []byte) error {
	l := len(dAtA)
	iNdEx := 0
	for iNdEx < l {
		preIndex := iNdEx
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return ErrIntOverflowFwlog
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
			return fmt.Errorf("proto: FwLogList: wiretype end group for non-group")
		}
		if fieldNum <= 0 {
			return fmt.Errorf("proto: FwLogList: illegal tag %d (wire type %d)", fieldNum, wire)
		}
		switch fieldNum {
		case 1:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field TypeMeta", wireType)
			}
			var msglen int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowFwlog
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
				return ErrInvalidLengthFwlog
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
				return fmt.Errorf("proto: wrong wireType = %d for field ListMeta", wireType)
			}
			var msglen int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowFwlog
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
				return ErrInvalidLengthFwlog
			}
			postIndex := iNdEx + msglen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			if err := m.ListMeta.Unmarshal(dAtA[iNdEx:postIndex]); err != nil {
				return err
			}
			iNdEx = postIndex
		case 3:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field Items", wireType)
			}
			var msglen int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowFwlog
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
				return ErrInvalidLengthFwlog
			}
			postIndex := iNdEx + msglen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.Items = append(m.Items, &FwLog{})
			if err := m.Items[len(m.Items)-1].Unmarshal(dAtA[iNdEx:postIndex]); err != nil {
				return err
			}
			iNdEx = postIndex
		default:
			iNdEx = preIndex
			skippy, err := skipFwlog(dAtA[iNdEx:])
			if err != nil {
				return err
			}
			if skippy < 0 {
				return ErrInvalidLengthFwlog
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
func skipFwlog(dAtA []byte) (n int, err error) {
	l := len(dAtA)
	iNdEx := 0
	for iNdEx < l {
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return 0, ErrIntOverflowFwlog
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
					return 0, ErrIntOverflowFwlog
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
					return 0, ErrIntOverflowFwlog
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
				return 0, ErrInvalidLengthFwlog
			}
			return iNdEx, nil
		case 3:
			for {
				var innerWire uint64
				var start int = iNdEx
				for shift := uint(0); ; shift += 7 {
					if shift >= 64 {
						return 0, ErrIntOverflowFwlog
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
				next, err := skipFwlog(dAtA[start:])
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
	ErrInvalidLengthFwlog = fmt.Errorf("proto: negative length found during unmarshaling")
	ErrIntOverflowFwlog   = fmt.Errorf("proto: integer overflow")
)

func init() { proto.RegisterFile("fwlog.proto", fileDescriptorFwlog) }

var fileDescriptorFwlog = []byte{
	// 916 bytes of a gzipped FileDescriptorProto
	0x1f, 0x8b, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xff, 0x7c, 0x95, 0xd1, 0x6e, 0x1a, 0x47,
	0x14, 0x86, 0xbd, 0xb1, 0xc1, 0x30, 0x98, 0x80, 0xc7, 0x76, 0x3d, 0x50, 0x97, 0x45, 0x91, 0x22,
	0xd1, 0x28, 0x40, 0x15, 0xab, 0x55, 0xa5, 0x56, 0x91, 0x4c, 0x31, 0xd2, 0x56, 0x6e, 0x4d, 0xc1,
	0xea, 0x4d, 0x2f, 0xa2, 0xf5, 0x32, 0x90, 0x69, 0x77, 0x77, 0x46, 0xbb, 0x43, 0x10, 0x2f, 0x10,
	0xe5, 0x31, 0x7a, 0x9d, 0x8b, 0x3e, 0x87, 0x2f, 0xf3, 0x04, 0xab, 0x8a, 0xab, 0x6a, 0x9f, 0xa2,
	0x9a, 0xc3, 0x92, 0x0c, 0xb0, 0xe4, 0x6e, 0xe7, 0x3b, 0xe7, 0xff, 0xcf, 0x59, 0x38, 0x73, 0x16,
	0x15, 0xc6, 0x33, 0x97, 0x4f, 0x5a, 0x22, 0xe0, 0x92, 0xe3, 0x0c, 0x1c, 0xaa, 0x17, 0x13, 0xce,
	0x27, 0x2e, 0x6d, 0xdb, 0x82, 0xb5, 0x6d, 0xdf, 0xe7, 0xd2, 0x96, 0x8c, 0xfb, 0xe1, 0x32, 0xa9,
	0x7a, 0x3d, 0x61, 0xf2, 0xf5, 0xf4, 0xbe, 0xe5, 0x70, 0xaf, 0x2d, 0xa8, 0x1f, 0xda, 0xfe, 0x88,
	0xb7, 0xc3, 0x59, 0xfb, 0x0d, 0xf5, 0x99, 0x43, 0xdb, 0x53, 0xc9, 0xdc, 0x50, 0x49, 0x27, 0xd4,
	0xd7, 0xd5, 0x6d, 0xe6, 0x3b, 0xee, 0x74, 0x44, 0x57, 0x36, 0x4d, 0xcd, 0x66, 0xc2, 0x27, 0xbc,
	0x0d, 0xf8, 0x7e, 0x3a, 0x86, 0x13, 0x1c, 0xe0, 0x29, 0x49, 0x7f, 0xba, 0xa3, 0xaa, 0xea, 0xd1,
	0xa3, 0xd2, 0x4e, 0xd2, 0xbe, 0xf9, 0x4c, 0xda, 0x98, 0x51, 0x77, 0x14, 0xb6, 0x43, 0xea, 0x52,
	0x47, 0xf2, 0x60, 0xa9, 0x78, 0xf2, 0x77, 0x01, 0x65, 0x7a, 0xb3, 0x1b, 0x3e, 0xc1, 0xdf, 0x21,
	0xe3, 0x8e, 0x18, 0x75, 0xa3, 0x51, 0x78, 0x51, 0x6c, 0xd9, 0x82, 0xb5, 0xee, 0xe6, 0x82, 0xfe,
	0x42, 0xa5, 0xdd, 0x39, 0x79, 0x88, 0xcc, 0xbd, 0x0f, 0x91, 0x69, 0xc4, 0x91, 0x79, 0xf8, 0x9c,
	0xf9, 0x2e, 0xf3, 0xe9, 0x60, 0xf5, 0x80, 0x7b, 0xc8, 0xb8, 0x25, 0x8f, 0x40, 0x57, 0x02, 0xdd,
	0xed, 0xfd, 0x9f, 0xd4, 0x91, 0xa0, 0xac, 0x6a, 0xca, 0xc7, 0xaa, 0xcf, 0xe7, 0xdc, 0x63, 0x92,
	0x7a, 0x42, 0xce, 0x07, 0x1b, 0x67, 0xfc, 0x12, 0x65, 0x87, 0x81, 0xf3, 0xfb, 0xa0, 0x47, 0xf6,
	0xeb, 0x46, 0xe3, 0xa0, 0x43, 0xe2, 0xc8, 0x3c, 0x0d, 0xf9, 0x34, 0x70, 0x68, 0xf3, 0x4d, 0x30,
	0xd6, 0x94, 0xa9, 0x14, 0x5b, 0xe8, 0xb0, 0x4b, 0x43, 0xa9, 0x0c, 0x0e, 0xc0, 0xe0, 0xab, 0x38,
	0x32, 0x2b, 0x23, 0x1a, 0x4a, 0xe6, 0xc3, 0x7f, 0xb0, 0xe1, 0xb2, 0x3b, 0x84, 0x7f, 0x40, 0x99,
	0x61, 0xe0, 0x58, 0x7d, 0x92, 0xa9, 0x1b, 0x8d, 0x7c, 0xe7, 0x3c, 0x8e, 0xcc, 0x93, 0xa4, 0x26,
	0x13, 0x9a, 0x45, 0x1a, 0xc4, 0x3d, 0x94, 0x55, 0x7d, 0x58, 0x7d, 0x92, 0x05, 0xf5, 0x45, 0x1c,
	0x99, 0x44, 0xaf, 0xb5, 0x66, 0xb1, 0x33, 0x82, 0xaf, 0xd0, 0xe1, 0x30, 0x70, 0xfa, 0x3c, 0x90,
	0xe4, 0xb0, 0x6e, 0x34, 0x8a, 0x9d, 0x4a, 0x1c, 0x99, 0x67, 0x49, 0x45, 0xc1, 0x03, 0xa9, 0xb9,
	0xa4, 0x63, 0x7c, 0x83, 0x72, 0xaa, 0x15, 0xf0, 0xc8, 0x81, 0x47, 0x2d, 0x8e, 0xcc, 0xaa, 0x5e,
	0x72, 0xc3, 0xe8, 0x33, 0x31, 0xfc, 0x23, 0xca, 0xf5, 0xd5, 0xcc, 0x38, 0xdc, 0x25, 0x79, 0x78,
	0xb5, 0x2f, 0xe2, 0xc8, 0xc4, 0x22, 0x61, 0x9a, 0x4b, 0x0a, 0xc3, 0xb7, 0x28, 0x7b, 0xe5, 0x28,
	0x5b, 0x82, 0x40, 0xdb, 0x7c, 0xff, 0xb6, 0x72, 0x36, 0x94, 0xc1, 0xb5, 0x3f, 0xf5, 0x1a, 0x30,
	0x81, 0xcb, 0x70, 0xf8, 0x75, 0x1c, 0x99, 0x65, 0x1b, 0x9e, 0x35, 0xcb, 0x2d, 0x82, 0xff, 0x40,
	0xf9, 0x2e, 0x0b, 0xe8, 0xd2, 0xb3, 0x00, 0x9e, 0x97, 0xef, 0xdf, 0x56, 0xc8, 0x9a, 0xe7, 0xc7,
	0x0c, 0xb0, 0x3d, 0x19, 0xad, 0x8e, 0xfa, 0x9f, 0x98, 0x02, 0xf1, 0xf7, 0x28, 0x3b, 0x98, 0xba,
	0xd4, 0xea, 0x92, 0x23, 0x98, 0xa5, 0xb3, 0x38, 0x32, 0x8f, 0x83, 0xa9, 0x4b, 0x9b, 0x6c, 0xa4,
	0x69, 0xb7, 0x11, 0xbe, 0x42, 0xf9, 0x21, 0x0d, 0x43, 0xc6, 0x7d, 0xab, 0x4b, 0x8a, 0xda, 0x24,
	0x2f, 0xe1, 0xba, 0x3e, 0x95, 0xe2, 0x9f, 0xd1, 0x51, 0x62, 0x31, 0x94, 0xb6, 0xa4, 0xe4, 0x31,
	0xbc, 0xdc, 0x97, 0x71, 0x64, 0x9e, 0xaf, 0xf2, 0x43, 0x15, 0xd0, 0x8c, 0x76, 0x05, 0xf0, 0xb7,
	0x28, 0x73, 0x25, 0x84, 0xd5, 0x25, 0x25, 0x30, 0x39, 0x85, 0x1f, 0x57, 0x88, 0xf5, 0x36, 0xb6,
	0x08, 0xee, 0x22, 0xd4, 0xe7, 0x2e, 0x73, 0xe6, 0xbf, 0xda, 0x1e, 0x25, 0x65, 0xd0, 0xc2, 0xfc,
	0x09, 0xa0, 0x4d, 0xdf, 0xf6, 0xf4, 0xf2, 0xe9, 0x58, 0xb9, 0x0c, 0xa8, 0x9a, 0x22, 0x1a, 0x58,
	0x5d, 0x72, 0xfc, 0xc9, 0x25, 0x48, 0xe8, 0x7a, 0x1b, 0xe9, 0x58, 0xb9, 0xf4, 0x5c, 0x3e, 0x4b,
	0xa6, 0x07, 0x7f, 0x72, 0x19, 0xbb, 0x7c, 0xd6, 0xdc, 0x9a, 0x94, 0x74, 0x8c, 0x5f, 0xa2, 0x9c,
	0xe5, 0x78, 0x42, 0x2d, 0x35, 0x72, 0x02, 0x77, 0x01, 0xae, 0x35, 0x73, 0x3c, 0xd1, 0x94, 0x73,
	0xa1, 0xbf, 0x4d, 0x1a, 0x5c, 0xe9, 0x7f, 0xe2, 0x23, 0x4a, 0x4e, 0x37, 0xf4, 0x0e, 0x1f, 0x6d,
	0xeb, 0xd7, 0xa1, 0x9a, 0x28, 0xa5, 0xb7, 0xba, 0xe4, 0x0c, 0xd4, 0x30, 0x51, 0x90, 0xb8, 0x3e,
	0x51, 0x5b, 0xe8, 0xc9, 0x3f, 0x06, 0xca, 0xc3, 0x30, 0xdf, 0xb0, 0x50, 0xe2, 0xa7, 0x3b, 0xd7,
	0x74, 0x6e, 0xb5, 0x6c, 0x07, 0xc6, 0x1d, 0xbe, 0x44, 0x39, 0x95, 0xae, 0x02, 0xc9, 0x72, 0x5e,
	0x66, 0xaf, 0xa0, 0x96, 0xfd, 0x31, 0x11, 0x5f, 0xa3, 0x8c, 0x25, 0xa9, 0x17, 0x92, 0xfd, 0xfa,
	0x7e, 0xa3, 0xf0, 0xe2, 0xa8, 0xb5, 0xfc, 0x3a, 0x42, 0xf1, 0xce, 0xf9, 0xc3, 0x72, 0x8f, 0x97,
	0x54, 0x5f, 0xa1, 0xd6, 0xf2, 0x26, 0x78, 0xd6, 0x41, 0x47, 0xfa, 0x85, 0xc6, 0x79, 0x94, 0xb1,
	0x5d, 0x97, 0xcf, 0xca, 0x7b, 0x38, 0x87, 0x0e, 0x46, 0xd4, 0x9f, 0x97, 0x0d, 0x8c, 0x50, 0x36,
	0xa0, 0xea, 0x43, 0x51, 0x7e, 0x84, 0x8f, 0x51, 0x91, 0x79, 0xc2, 0x65, 0x0e, 0x93, 0xaf, 0x20,
	0xbc, 0xff, 0xec, 0x37, 0x54, 0xda, 0xb8, 0xc0, 0xf8, 0x02, 0xe5, 0xc7, 0x01, 0xf7, 0x5e, 0xbd,
	0xe6, 0xa1, 0x2c, 0xef, 0x55, 0x8b, 0x8b, 0x77, 0x15, 0x00, 0x4d, 0x05, 0x70, 0x1d, 0x15, 0x20,
	0x3a, 0x15, 0x2e, 0xf3, 0xff, 0x2a, 0x1b, 0xd5, 0xd2, 0xe2, 0x5d, 0x05, 0x50, 0x73, 0x89, 0x3a,
	0xe5, 0x87, 0x45, 0xcd, 0xf8, 0xb0, 0xa8, 0x19, 0xff, 0x2e, 0x6a, 0xc6, 0x7f, 0x8b, 0xda, 0x5e,
	0xdf, 0xb8, 0xcf, 0xc2, 0xa6, 0xba, 0xfc, 0x3f, 0x00, 0x00, 0xff, 0xff, 0x9f, 0xe3, 0x8f, 0xfb,
	0x08, 0x08, 0x00, 0x00,
}