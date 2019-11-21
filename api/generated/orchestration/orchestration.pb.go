// Code generated by protoc-gen-gogo. DO NOT EDIT.
// source: orchestration.proto

/*
	Package orchestration is a generated protocol buffer package.

	Service name

	It is generated from these files:
		orchestration.proto
		svc_orchestration.proto

	It has these top-level messages:
		Orchestrator
		OrchestratorSpec
		OrchestratorStatus
		AutoMsgOrchestratorWatchHelper
		OrchestratorList
*/
package orchestration

import proto "github.com/gogo/protobuf/proto"
import fmt "fmt"
import math "math"
import _ "github.com/pensando/grpc-gateway/third_party/googleapis/google/api"
import _ "github.com/pensando/sw/venice/utils/apigen/annotations"
import _ "github.com/gogo/protobuf/gogoproto"
import api "github.com/pensando/sw/api"
import monitoring "github.com/pensando/sw/api/generated/monitoring"

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

//
type OrchestratorSpec_OrchestratorType int32

const (
	// ui-hint: vcenter
	OrchestratorSpec_VCenter OrchestratorSpec_OrchestratorType = 0
)

var OrchestratorSpec_OrchestratorType_name = map[int32]string{
	0: "VCenter",
}
var OrchestratorSpec_OrchestratorType_value = map[string]int32{
	"VCenter": 0,
}

func (OrchestratorSpec_OrchestratorType) EnumDescriptor() ([]byte, []int) {
	return fileDescriptorOrchestration, []int{1, 0}
}

//
type OrchestratorStatus_ConnectionStatus int32

const (
	// ui-hint: Unknown
	OrchestratorStatus_Unknown OrchestratorStatus_ConnectionStatus = 0
	// ui-hint: Success
	OrchestratorStatus_Success OrchestratorStatus_ConnectionStatus = 1
	// ui-hint: Failure
	OrchestratorStatus_Failure OrchestratorStatus_ConnectionStatus = 2
)

var OrchestratorStatus_ConnectionStatus_name = map[int32]string{
	0: "Unknown",
	1: "Success",
	2: "Failure",
}
var OrchestratorStatus_ConnectionStatus_value = map[string]int32{
	"Unknown": 0,
	"Success": 1,
	"Failure": 2,
}

func (OrchestratorStatus_ConnectionStatus) EnumDescriptor() ([]byte, []int) {
	return fileDescriptorOrchestration, []int{2, 0}
}

// --------------------------------- ORCHESTRATOR ---------------------------------------------
//
// Orchestrator represents the config object which allows Venice to connect to the appropriate orchestrator
//
//
type Orchestrator struct {
	//
	api.TypeMeta `protobuf:"bytes,1,opt,name=T,json=,inline,embedded=T" json:",inline"`
	//
	api.ObjectMeta `protobuf:"bytes,2,opt,name=O,json=meta,omitempty,embedded=O" json:"meta,omitempty"`
	// Spec contains the configuration of the vcenter.
	Spec OrchestratorSpec `protobuf:"bytes,3,opt,name=Spec,json=spec,omitempty" json:"spec,omitempty"`
	// Status contains the current state of the cluster.
	Status OrchestratorStatus `protobuf:"bytes,4,opt,name=Status,json=status,omitempty" json:"status,omitempty"`
}

func (m *Orchestrator) Reset()                    { *m = Orchestrator{} }
func (m *Orchestrator) String() string            { return proto.CompactTextString(m) }
func (*Orchestrator) ProtoMessage()               {}
func (*Orchestrator) Descriptor() ([]byte, []int) { return fileDescriptorOrchestration, []int{0} }

func (m *Orchestrator) GetSpec() OrchestratorSpec {
	if m != nil {
		return m.Spec
	}
	return OrchestratorSpec{}
}

func (m *Orchestrator) GetStatus() OrchestratorStatus {
	if m != nil {
		return m.Status
	}
	return OrchestratorStatus{}
}

// OrchestratorSpec contains the configuration of the cluster.
type OrchestratorSpec struct {
	//
	Type string `protobuf:"bytes,1,opt,name=Type,json=type,proto3" json:"type"`
	//
	URI string `protobuf:"bytes,2,opt,name=URI,json=uri,proto3" json:"uri"`
	//
	Credentials *monitoring.ExternalCred `protobuf:"bytes,3,opt,name=Credentials,json=credentials,omitempty" json:"credentials,omitempty"`
	//
	LoginData map[string]string `protobuf:"bytes,4,rep,name=LoginData,json=login-data,omitempty" json:"login-data,omitempty" protobuf_key:"bytes,1,opt,name=key,proto3" protobuf_val:"bytes,2,opt,name=value,proto3"`
}

func (m *OrchestratorSpec) Reset()                    { *m = OrchestratorSpec{} }
func (m *OrchestratorSpec) String() string            { return proto.CompactTextString(m) }
func (*OrchestratorSpec) ProtoMessage()               {}
func (*OrchestratorSpec) Descriptor() ([]byte, []int) { return fileDescriptorOrchestration, []int{1} }

func (m *OrchestratorSpec) GetType() string {
	if m != nil {
		return m.Type
	}
	return ""
}

func (m *OrchestratorSpec) GetURI() string {
	if m != nil {
		return m.URI
	}
	return ""
}

func (m *OrchestratorSpec) GetCredentials() *monitoring.ExternalCred {
	if m != nil {
		return m.Credentials
	}
	return nil
}

func (m *OrchestratorSpec) GetLoginData() map[string]string {
	if m != nil {
		return m.LoginData
	}
	return nil
}

// OrchestratorStatus contains the current state of connection with the orchestrator.
type OrchestratorStatus struct {
	//
	Status string `protobuf:"bytes,1,opt,name=Status,json=connection-status,proto3" json:"connection-status"`
	//
	LastConnected *api.Timestamp `protobuf:"bytes,2,opt,name=LastConnected,json=last-connected,omitempty" json:"last-connected,omitempty"`
	//
	LastSync *api.Timestamp `protobuf:"bytes,3,opt,name=LastSync,json=last-sync,omitempty" json:"last-sync,omitempty"`
	//
	SessionID string `protobuf:"bytes,4,opt,name=SessionID,json=session-id,omitempty,proto3" json:"session-id,omitempty"`
}

func (m *OrchestratorStatus) Reset()                    { *m = OrchestratorStatus{} }
func (m *OrchestratorStatus) String() string            { return proto.CompactTextString(m) }
func (*OrchestratorStatus) ProtoMessage()               {}
func (*OrchestratorStatus) Descriptor() ([]byte, []int) { return fileDescriptorOrchestration, []int{2} }

func (m *OrchestratorStatus) GetStatus() string {
	if m != nil {
		return m.Status
	}
	return ""
}

func (m *OrchestratorStatus) GetLastConnected() *api.Timestamp {
	if m != nil {
		return m.LastConnected
	}
	return nil
}

func (m *OrchestratorStatus) GetLastSync() *api.Timestamp {
	if m != nil {
		return m.LastSync
	}
	return nil
}

func (m *OrchestratorStatus) GetSessionID() string {
	if m != nil {
		return m.SessionID
	}
	return ""
}

func init() {
	proto.RegisterType((*Orchestrator)(nil), "orchestration.Orchestrator")
	proto.RegisterType((*OrchestratorSpec)(nil), "orchestration.OrchestratorSpec")
	proto.RegisterType((*OrchestratorStatus)(nil), "orchestration.OrchestratorStatus")
	proto.RegisterEnum("orchestration.OrchestratorSpec_OrchestratorType", OrchestratorSpec_OrchestratorType_name, OrchestratorSpec_OrchestratorType_value)
	proto.RegisterEnum("orchestration.OrchestratorStatus_ConnectionStatus", OrchestratorStatus_ConnectionStatus_name, OrchestratorStatus_ConnectionStatus_value)
}
func (m *Orchestrator) Marshal() (dAtA []byte, err error) {
	size := m.Size()
	dAtA = make([]byte, size)
	n, err := m.MarshalTo(dAtA)
	if err != nil {
		return nil, err
	}
	return dAtA[:n], nil
}

func (m *Orchestrator) MarshalTo(dAtA []byte) (int, error) {
	var i int
	_ = i
	var l int
	_ = l
	dAtA[i] = 0xa
	i++
	i = encodeVarintOrchestration(dAtA, i, uint64(m.TypeMeta.Size()))
	n1, err := m.TypeMeta.MarshalTo(dAtA[i:])
	if err != nil {
		return 0, err
	}
	i += n1
	dAtA[i] = 0x12
	i++
	i = encodeVarintOrchestration(dAtA, i, uint64(m.ObjectMeta.Size()))
	n2, err := m.ObjectMeta.MarshalTo(dAtA[i:])
	if err != nil {
		return 0, err
	}
	i += n2
	dAtA[i] = 0x1a
	i++
	i = encodeVarintOrchestration(dAtA, i, uint64(m.Spec.Size()))
	n3, err := m.Spec.MarshalTo(dAtA[i:])
	if err != nil {
		return 0, err
	}
	i += n3
	dAtA[i] = 0x22
	i++
	i = encodeVarintOrchestration(dAtA, i, uint64(m.Status.Size()))
	n4, err := m.Status.MarshalTo(dAtA[i:])
	if err != nil {
		return 0, err
	}
	i += n4
	return i, nil
}

func (m *OrchestratorSpec) Marshal() (dAtA []byte, err error) {
	size := m.Size()
	dAtA = make([]byte, size)
	n, err := m.MarshalTo(dAtA)
	if err != nil {
		return nil, err
	}
	return dAtA[:n], nil
}

func (m *OrchestratorSpec) MarshalTo(dAtA []byte) (int, error) {
	var i int
	_ = i
	var l int
	_ = l
	if len(m.Type) > 0 {
		dAtA[i] = 0xa
		i++
		i = encodeVarintOrchestration(dAtA, i, uint64(len(m.Type)))
		i += copy(dAtA[i:], m.Type)
	}
	if len(m.URI) > 0 {
		dAtA[i] = 0x12
		i++
		i = encodeVarintOrchestration(dAtA, i, uint64(len(m.URI)))
		i += copy(dAtA[i:], m.URI)
	}
	if m.Credentials != nil {
		dAtA[i] = 0x1a
		i++
		i = encodeVarintOrchestration(dAtA, i, uint64(m.Credentials.Size()))
		n5, err := m.Credentials.MarshalTo(dAtA[i:])
		if err != nil {
			return 0, err
		}
		i += n5
	}
	if len(m.LoginData) > 0 {
		for k, _ := range m.LoginData {
			dAtA[i] = 0x22
			i++
			v := m.LoginData[k]
			mapSize := 1 + len(k) + sovOrchestration(uint64(len(k))) + 1 + len(v) + sovOrchestration(uint64(len(v)))
			i = encodeVarintOrchestration(dAtA, i, uint64(mapSize))
			dAtA[i] = 0xa
			i++
			i = encodeVarintOrchestration(dAtA, i, uint64(len(k)))
			i += copy(dAtA[i:], k)
			dAtA[i] = 0x12
			i++
			i = encodeVarintOrchestration(dAtA, i, uint64(len(v)))
			i += copy(dAtA[i:], v)
		}
	}
	return i, nil
}

func (m *OrchestratorStatus) Marshal() (dAtA []byte, err error) {
	size := m.Size()
	dAtA = make([]byte, size)
	n, err := m.MarshalTo(dAtA)
	if err != nil {
		return nil, err
	}
	return dAtA[:n], nil
}

func (m *OrchestratorStatus) MarshalTo(dAtA []byte) (int, error) {
	var i int
	_ = i
	var l int
	_ = l
	if len(m.Status) > 0 {
		dAtA[i] = 0xa
		i++
		i = encodeVarintOrchestration(dAtA, i, uint64(len(m.Status)))
		i += copy(dAtA[i:], m.Status)
	}
	if m.LastConnected != nil {
		dAtA[i] = 0x12
		i++
		i = encodeVarintOrchestration(dAtA, i, uint64(m.LastConnected.Size()))
		n6, err := m.LastConnected.MarshalTo(dAtA[i:])
		if err != nil {
			return 0, err
		}
		i += n6
	}
	if m.LastSync != nil {
		dAtA[i] = 0x1a
		i++
		i = encodeVarintOrchestration(dAtA, i, uint64(m.LastSync.Size()))
		n7, err := m.LastSync.MarshalTo(dAtA[i:])
		if err != nil {
			return 0, err
		}
		i += n7
	}
	if len(m.SessionID) > 0 {
		dAtA[i] = 0x22
		i++
		i = encodeVarintOrchestration(dAtA, i, uint64(len(m.SessionID)))
		i += copy(dAtA[i:], m.SessionID)
	}
	return i, nil
}

func encodeVarintOrchestration(dAtA []byte, offset int, v uint64) int {
	for v >= 1<<7 {
		dAtA[offset] = uint8(v&0x7f | 0x80)
		v >>= 7
		offset++
	}
	dAtA[offset] = uint8(v)
	return offset + 1
}
func (m *Orchestrator) Size() (n int) {
	var l int
	_ = l
	l = m.TypeMeta.Size()
	n += 1 + l + sovOrchestration(uint64(l))
	l = m.ObjectMeta.Size()
	n += 1 + l + sovOrchestration(uint64(l))
	l = m.Spec.Size()
	n += 1 + l + sovOrchestration(uint64(l))
	l = m.Status.Size()
	n += 1 + l + sovOrchestration(uint64(l))
	return n
}

func (m *OrchestratorSpec) Size() (n int) {
	var l int
	_ = l
	l = len(m.Type)
	if l > 0 {
		n += 1 + l + sovOrchestration(uint64(l))
	}
	l = len(m.URI)
	if l > 0 {
		n += 1 + l + sovOrchestration(uint64(l))
	}
	if m.Credentials != nil {
		l = m.Credentials.Size()
		n += 1 + l + sovOrchestration(uint64(l))
	}
	if len(m.LoginData) > 0 {
		for k, v := range m.LoginData {
			_ = k
			_ = v
			mapEntrySize := 1 + len(k) + sovOrchestration(uint64(len(k))) + 1 + len(v) + sovOrchestration(uint64(len(v)))
			n += mapEntrySize + 1 + sovOrchestration(uint64(mapEntrySize))
		}
	}
	return n
}

func (m *OrchestratorStatus) Size() (n int) {
	var l int
	_ = l
	l = len(m.Status)
	if l > 0 {
		n += 1 + l + sovOrchestration(uint64(l))
	}
	if m.LastConnected != nil {
		l = m.LastConnected.Size()
		n += 1 + l + sovOrchestration(uint64(l))
	}
	if m.LastSync != nil {
		l = m.LastSync.Size()
		n += 1 + l + sovOrchestration(uint64(l))
	}
	l = len(m.SessionID)
	if l > 0 {
		n += 1 + l + sovOrchestration(uint64(l))
	}
	return n
}

func sovOrchestration(x uint64) (n int) {
	for {
		n++
		x >>= 7
		if x == 0 {
			break
		}
	}
	return n
}
func sozOrchestration(x uint64) (n int) {
	return sovOrchestration(uint64((x << 1) ^ uint64((int64(x) >> 63))))
}
func (m *Orchestrator) Unmarshal(dAtA []byte) error {
	l := len(dAtA)
	iNdEx := 0
	for iNdEx < l {
		preIndex := iNdEx
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return ErrIntOverflowOrchestration
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
			return fmt.Errorf("proto: Orchestrator: wiretype end group for non-group")
		}
		if fieldNum <= 0 {
			return fmt.Errorf("proto: Orchestrator: illegal tag %d (wire type %d)", fieldNum, wire)
		}
		switch fieldNum {
		case 1:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field TypeMeta", wireType)
			}
			var msglen int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowOrchestration
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
				return ErrInvalidLengthOrchestration
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
					return ErrIntOverflowOrchestration
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
				return ErrInvalidLengthOrchestration
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
					return ErrIntOverflowOrchestration
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
				return ErrInvalidLengthOrchestration
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
					return ErrIntOverflowOrchestration
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
				return ErrInvalidLengthOrchestration
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
			skippy, err := skipOrchestration(dAtA[iNdEx:])
			if err != nil {
				return err
			}
			if skippy < 0 {
				return ErrInvalidLengthOrchestration
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
func (m *OrchestratorSpec) Unmarshal(dAtA []byte) error {
	l := len(dAtA)
	iNdEx := 0
	for iNdEx < l {
		preIndex := iNdEx
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return ErrIntOverflowOrchestration
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
			return fmt.Errorf("proto: OrchestratorSpec: wiretype end group for non-group")
		}
		if fieldNum <= 0 {
			return fmt.Errorf("proto: OrchestratorSpec: illegal tag %d (wire type %d)", fieldNum, wire)
		}
		switch fieldNum {
		case 1:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field Type", wireType)
			}
			var stringLen uint64
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowOrchestration
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
				return ErrInvalidLengthOrchestration
			}
			postIndex := iNdEx + intStringLen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.Type = string(dAtA[iNdEx:postIndex])
			iNdEx = postIndex
		case 2:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field URI", wireType)
			}
			var stringLen uint64
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowOrchestration
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
				return ErrInvalidLengthOrchestration
			}
			postIndex := iNdEx + intStringLen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.URI = string(dAtA[iNdEx:postIndex])
			iNdEx = postIndex
		case 3:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field Credentials", wireType)
			}
			var msglen int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowOrchestration
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
				return ErrInvalidLengthOrchestration
			}
			postIndex := iNdEx + msglen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			if m.Credentials == nil {
				m.Credentials = &monitoring.ExternalCred{}
			}
			if err := m.Credentials.Unmarshal(dAtA[iNdEx:postIndex]); err != nil {
				return err
			}
			iNdEx = postIndex
		case 4:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field LoginData", wireType)
			}
			var msglen int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowOrchestration
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
				return ErrInvalidLengthOrchestration
			}
			postIndex := iNdEx + msglen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			if m.LoginData == nil {
				m.LoginData = make(map[string]string)
			}
			var mapkey string
			var mapvalue string
			for iNdEx < postIndex {
				entryPreIndex := iNdEx
				var wire uint64
				for shift := uint(0); ; shift += 7 {
					if shift >= 64 {
						return ErrIntOverflowOrchestration
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
				if fieldNum == 1 {
					var stringLenmapkey uint64
					for shift := uint(0); ; shift += 7 {
						if shift >= 64 {
							return ErrIntOverflowOrchestration
						}
						if iNdEx >= l {
							return io.ErrUnexpectedEOF
						}
						b := dAtA[iNdEx]
						iNdEx++
						stringLenmapkey |= (uint64(b) & 0x7F) << shift
						if b < 0x80 {
							break
						}
					}
					intStringLenmapkey := int(stringLenmapkey)
					if intStringLenmapkey < 0 {
						return ErrInvalidLengthOrchestration
					}
					postStringIndexmapkey := iNdEx + intStringLenmapkey
					if postStringIndexmapkey > l {
						return io.ErrUnexpectedEOF
					}
					mapkey = string(dAtA[iNdEx:postStringIndexmapkey])
					iNdEx = postStringIndexmapkey
				} else if fieldNum == 2 {
					var stringLenmapvalue uint64
					for shift := uint(0); ; shift += 7 {
						if shift >= 64 {
							return ErrIntOverflowOrchestration
						}
						if iNdEx >= l {
							return io.ErrUnexpectedEOF
						}
						b := dAtA[iNdEx]
						iNdEx++
						stringLenmapvalue |= (uint64(b) & 0x7F) << shift
						if b < 0x80 {
							break
						}
					}
					intStringLenmapvalue := int(stringLenmapvalue)
					if intStringLenmapvalue < 0 {
						return ErrInvalidLengthOrchestration
					}
					postStringIndexmapvalue := iNdEx + intStringLenmapvalue
					if postStringIndexmapvalue > l {
						return io.ErrUnexpectedEOF
					}
					mapvalue = string(dAtA[iNdEx:postStringIndexmapvalue])
					iNdEx = postStringIndexmapvalue
				} else {
					iNdEx = entryPreIndex
					skippy, err := skipOrchestration(dAtA[iNdEx:])
					if err != nil {
						return err
					}
					if skippy < 0 {
						return ErrInvalidLengthOrchestration
					}
					if (iNdEx + skippy) > postIndex {
						return io.ErrUnexpectedEOF
					}
					iNdEx += skippy
				}
			}
			m.LoginData[mapkey] = mapvalue
			iNdEx = postIndex
		default:
			iNdEx = preIndex
			skippy, err := skipOrchestration(dAtA[iNdEx:])
			if err != nil {
				return err
			}
			if skippy < 0 {
				return ErrInvalidLengthOrchestration
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
func (m *OrchestratorStatus) Unmarshal(dAtA []byte) error {
	l := len(dAtA)
	iNdEx := 0
	for iNdEx < l {
		preIndex := iNdEx
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return ErrIntOverflowOrchestration
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
			return fmt.Errorf("proto: OrchestratorStatus: wiretype end group for non-group")
		}
		if fieldNum <= 0 {
			return fmt.Errorf("proto: OrchestratorStatus: illegal tag %d (wire type %d)", fieldNum, wire)
		}
		switch fieldNum {
		case 1:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field Status", wireType)
			}
			var stringLen uint64
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowOrchestration
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
				return ErrInvalidLengthOrchestration
			}
			postIndex := iNdEx + intStringLen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.Status = string(dAtA[iNdEx:postIndex])
			iNdEx = postIndex
		case 2:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field LastConnected", wireType)
			}
			var msglen int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowOrchestration
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
				return ErrInvalidLengthOrchestration
			}
			postIndex := iNdEx + msglen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			if m.LastConnected == nil {
				m.LastConnected = &api.Timestamp{}
			}
			if err := m.LastConnected.Unmarshal(dAtA[iNdEx:postIndex]); err != nil {
				return err
			}
			iNdEx = postIndex
		case 3:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field LastSync", wireType)
			}
			var msglen int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowOrchestration
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
				return ErrInvalidLengthOrchestration
			}
			postIndex := iNdEx + msglen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			if m.LastSync == nil {
				m.LastSync = &api.Timestamp{}
			}
			if err := m.LastSync.Unmarshal(dAtA[iNdEx:postIndex]); err != nil {
				return err
			}
			iNdEx = postIndex
		case 4:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field SessionID", wireType)
			}
			var stringLen uint64
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowOrchestration
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
				return ErrInvalidLengthOrchestration
			}
			postIndex := iNdEx + intStringLen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.SessionID = string(dAtA[iNdEx:postIndex])
			iNdEx = postIndex
		default:
			iNdEx = preIndex
			skippy, err := skipOrchestration(dAtA[iNdEx:])
			if err != nil {
				return err
			}
			if skippy < 0 {
				return ErrInvalidLengthOrchestration
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
func skipOrchestration(dAtA []byte) (n int, err error) {
	l := len(dAtA)
	iNdEx := 0
	for iNdEx < l {
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return 0, ErrIntOverflowOrchestration
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
					return 0, ErrIntOverflowOrchestration
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
					return 0, ErrIntOverflowOrchestration
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
				return 0, ErrInvalidLengthOrchestration
			}
			return iNdEx, nil
		case 3:
			for {
				var innerWire uint64
				var start int = iNdEx
				for shift := uint(0); ; shift += 7 {
					if shift >= 64 {
						return 0, ErrIntOverflowOrchestration
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
				next, err := skipOrchestration(dAtA[start:])
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
	ErrInvalidLengthOrchestration = fmt.Errorf("proto: negative length found during unmarshaling")
	ErrIntOverflowOrchestration   = fmt.Errorf("proto: integer overflow")
)

func init() { proto.RegisterFile("orchestration.proto", fileDescriptorOrchestration) }

var fileDescriptorOrchestration = []byte{
	// 749 bytes of a gzipped FileDescriptorProto
	0x1f, 0x8b, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xff, 0x84, 0x54, 0xc1, 0x6e, 0xeb, 0x44,
	0x14, 0xad, 0x93, 0xf0, 0x42, 0x26, 0x6d, 0x30, 0xd3, 0x82, 0x9c, 0xf0, 0x14, 0x97, 0x48, 0x48,
	0x05, 0x25, 0xb6, 0xf4, 0x90, 0x9e, 0xd0, 0x13, 0x2b, 0xb7, 0xa9, 0x54, 0x54, 0x54, 0xe4, 0xb4,
	0xec, 0x10, 0x4c, 0x9c, 0xa9, 0x3b, 0xd4, 0x9e, 0x31, 0x9e, 0x71, 0xdb, 0x7c, 0x00, 0x15, 0xdf,
	0xd2, 0x3f, 0xe0, 0x0f, 0xba, 0xac, 0x58, 0xb1, 0xb2, 0x50, 0x56, 0x28, 0x5f, 0x81, 0x66, 0xc6,
	0x09, 0x4e, 0x9a, 0xc2, 0xc6, 0x9a, 0x73, 0xee, 0xbd, 0xc7, 0xd7, 0xe7, 0xce, 0x35, 0xd8, 0x65,
	0x69, 0x70, 0x85, 0xb9, 0x48, 0x91, 0x20, 0x8c, 0x3a, 0x49, 0xca, 0x04, 0x83, 0x3b, 0x2b, 0x64,
	0xe7, 0x75, 0xc8, 0x58, 0x18, 0x61, 0x17, 0x25, 0xc4, 0x45, 0x94, 0x32, 0xa1, 0x68, 0xae, 0x93,
	0x3b, 0xc3, 0x90, 0x88, 0xab, 0x6c, 0xec, 0x04, 0x2c, 0x76, 0x13, 0x4c, 0x39, 0xa2, 0x13, 0xe6,
	0xf2, 0x5b, 0xf7, 0x06, 0x53, 0x12, 0x60, 0x37, 0x13, 0x24, 0xe2, 0xb2, 0x34, 0xc4, 0xb4, 0x5c,
	0xed, 0x12, 0x1a, 0x44, 0xd9, 0x04, 0x2f, 0x64, 0x06, 0x25, 0x99, 0x90, 0x85, 0xcc, 0x55, 0xf4,
	0x38, 0xbb, 0x54, 0x48, 0x01, 0x75, 0x2a, 0xd2, 0x3f, 0x7b, 0xe1, 0xad, 0xb2, 0xc7, 0x18, 0x0b,
	0x54, 0xa4, 0x6d, 0xe3, 0xbb, 0x84, 0xa5, 0x42, 0xa3, 0xde, 0x9f, 0x15, 0xb0, 0x7d, 0xb6, 0xfc,
	0x34, 0x96, 0xc2, 0xb7, 0xc0, 0x38, 0xb7, 0x8c, 0x7d, 0xe3, 0xa0, 0xf9, 0x66, 0xc7, 0x41, 0x09,
	0x71, 0xce, 0xa7, 0x09, 0xfe, 0x16, 0x0b, 0xe4, 0xed, 0x3e, 0xe6, 0xf6, 0xd6, 0x53, 0x6e, 0x1b,
	0xf3, 0xdc, 0xae, 0xf7, 0x09, 0x8d, 0x08, 0xc5, 0xfe, 0xe2, 0x00, 0x8f, 0x81, 0x71, 0x66, 0x55,
	0x54, 0xdd, 0x07, 0xaa, 0xee, 0x6c, 0xfc, 0x33, 0x0e, 0x84, 0xaa, 0xec, 0x94, 0x2a, 0x5b, 0xb2,
	0x95, 0x3e, 0x8b, 0x89, 0xc0, 0x71, 0x22, 0xa6, 0xfe, 0x1a, 0x86, 0x17, 0xa0, 0x36, 0x4a, 0x70,
	0x60, 0x55, 0x95, 0x94, 0xed, 0xac, 0x0e, 0xa3, 0xdc, 0xaa, 0x4c, 0xf3, 0x3e, 0x96, 0xd2, 0x52,
	0x96, 0x27, 0x38, 0x28, 0xcb, 0xae, 0x62, 0xf8, 0x03, 0x78, 0x35, 0x12, 0x48, 0x64, 0xdc, 0xaa,
	0x29, 0xe1, 0x4f, 0xff, 0x4b, 0x58, 0x25, 0x7a, 0x56, 0x21, 0x6d, 0x72, 0x85, 0x4b, 0xe2, 0xcf,
	0x98, 0x77, 0xf0, 0x8f, 0x5f, 0xdb, 0x2d, 0xb8, 0xcd, 0x4a, 0x2a, 0xbd, 0xdf, 0xab, 0xc0, 0x5c,
	0xef, 0x17, 0x7e, 0x03, 0x6a, 0xd2, 0x50, 0xe5, 0x70, 0xc3, 0x7b, 0xfb, 0x70, 0xdf, 0xfe, 0x62,
	0x24, 0xd2, 0x21, 0xcd, 0xe2, 0x83, 0xf5, 0xdc, 0x95, 0x9e, 0x64, 0xd1, 0xe7, 0xf3, 0xdc, 0xae,
	0x89, 0x69, 0x82, 0x7d, 0xf5, 0x84, 0x6d, 0x50, 0xbd, 0xf0, 0x4f, 0x94, 0xe9, 0x0d, 0xaf, 0x3e,
	0xcf, 0xed, 0x6a, 0x96, 0x12, 0x5f, 0x3e, 0xe0, 0x8f, 0xa0, 0x79, 0x98, 0xe2, 0x09, 0xa6, 0x82,
	0xa0, 0x88, 0x17, 0x66, 0x5a, 0x4e, 0xcc, 0x28, 0x11, 0x2c, 0x25, 0x34, 0x74, 0x86, 0x77, 0x02,
	0xa7, 0x14, 0x45, 0x32, 0xcd, 0x6b, 0xcf, 0x73, 0xfb, 0xa3, 0xe0, 0xdf, 0x82, 0xd2, 0xb7, 0x6e,
	0xa6, 0xe1, 0x2f, 0xa0, 0x71, 0xca, 0x42, 0x42, 0x8f, 0x90, 0x40, 0x56, 0x6d, 0xbf, 0x7a, 0xd0,
	0x7c, 0xe3, 0xfc, 0xcf, 0xac, 0x9c, 0x65, 0xc1, 0x90, 0x8a, 0x74, 0xea, 0x59, 0xf3, 0xdc, 0xde,
	0x8b, 0x24, 0x37, 0x98, 0xa0, 0x95, 0x3b, 0xb1, 0x91, 0xed, 0x7c, 0x0d, 0x5a, 0xab, 0x0a, 0xd0,
	0x04, 0xd5, 0x6b, 0x3c, 0xd5, 0x5e, 0xfa, 0xf2, 0x08, 0xf7, 0xc0, 0x7b, 0x37, 0x28, 0xca, 0xb0,
	0x36, 0xc5, 0xd7, 0xe0, 0x5d, 0xe5, 0x2b, 0xa3, 0xd7, 0x5f, 0x1d, 0x86, 0xf4, 0x13, 0x5a, 0xa0,
	0xfe, 0xfd, 0x21, 0xa6, 0x02, 0xa7, 0xe6, 0x56, 0xa7, 0x39, 0xfb, 0xad, 0x5d, 0xbf, 0x09, 0x14,
	0xec, 0xe5, 0x55, 0x00, 0x9f, 0x5f, 0x09, 0x78, 0xb5, 0xbc, 0x45, 0x7a, 0x7e, 0xc3, 0x87, 0xfb,
	0x76, 0x7f, 0xe3, 0xfc, 0x54, 0x96, 0x73, 0xc8, 0x28, 0xc5, 0x81, 0x74, 0x43, 0x13, 0x72, 0x82,
	0x1f, 0x06, 0x4b, 0x72, 0xa0, 0xef, 0x91, 0xff, 0x9c, 0x82, 0x08, 0xec, 0x9c, 0x22, 0x2e, 0x0a,
	0x01, 0x3c, 0x29, 0x56, 0xab, 0xa5, 0x57, 0x92, 0xc4, 0x98, 0x0b, 0x14, 0x27, 0xde, 0xfe, 0xa3,
	0xde, 0x2a, 0x2b, 0x42, 0x5c, 0x0c, 0x82, 0x45, 0x76, 0xc9, 0xcb, 0x17, 0x23, 0xd0, 0x07, 0xef,
	0xcb, 0x57, 0x8c, 0xa6, 0x74, 0xb1, 0x6d, 0xeb, 0xea, 0x9f, 0x14, 0xea, 0xbb, 0x4a, 0x83, 0x4f,
	0x69, 0x79, 0xc3, 0x36, 0x91, 0x70, 0x08, 0x1a, 0x23, 0xcc, 0x39, 0x61, 0xf4, 0xe4, 0x48, 0x6d,
	0x5a, 0xc3, 0x7b, 0x5d, 0x88, 0xec, 0x71, 0x1d, 0x18, 0x90, 0x72, 0x7b, 0x1b, 0xd9, 0xde, 0x4f,
	0xc0, 0x5c, 0xb7, 0x4e, 0x0e, 0xeb, 0x82, 0x5e, 0x53, 0x76, 0x4b, 0x17, 0xc3, 0xca, 0x34, 0x94,
	0x91, 0x51, 0x16, 0x04, 0x98, 0x73, 0xd3, 0xd0, 0x11, 0xae, 0xa1, 0x8c, 0x1c, 0x23, 0x12, 0x65,
	0x29, 0x36, 0x2b, 0x3a, 0x72, 0xa9, 0xa1, 0x67, 0x3e, 0xce, 0xba, 0xc6, 0xd3, 0xac, 0x6b, 0xfc,
	0x35, 0xeb, 0x1a, 0x7f, 0xcf, 0xba, 0x5b, 0xdf, 0x19, 0xe3, 0x57, 0xea, 0x97, 0xf8, 0xe5, 0x3f,
	0x01, 0x00, 0x00, 0xff, 0xff, 0x24, 0x1b, 0xca, 0xed, 0x01, 0x06, 0x00, 0x00,
}
