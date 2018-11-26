// Code generated by protoc-gen-go. DO NOT EDIT.
// source: dos.proto

package halproto

import proto "github.com/golang/protobuf/proto"
import fmt "fmt"
import math "math"

// Reference imports to suppress errors if they are not otherwise used.
var _ = proto.Marshal
var _ = fmt.Errorf
var _ = math.Inf

type ICMPMsg struct {
	Type ICMPMsgType `protobuf:"varint,1,opt,name=type,enum=types.ICMPMsgType" json:"type,omitempty"`
	Code uint32      `protobuf:"varint,2,opt,name=code" json:"code,omitempty"`
}

func (m *ICMPMsg) Reset()                    { *m = ICMPMsg{} }
func (m *ICMPMsg) String() string            { return proto.CompactTextString(m) }
func (*ICMPMsg) ProtoMessage()               {}
func (*ICMPMsg) Descriptor() ([]byte, []int) { return fileDescriptor31, []int{0} }

func (m *ICMPMsg) GetType() ICMPMsgType {
	if m != nil {
		return m.Type
	}
	return ICMPMsgType_ICMP_MSG_TYPE_NONE
}

func (m *ICMPMsg) GetCode() uint32 {
	if m != nil {
		return m.Code
	}
	return 0
}

type DoSService struct {
	IpProtocol IPProtocol `protobuf:"varint,1,opt,name=ip_protocol,json=ipProtocol,enum=types.IPProtocol" json:"ip_protocol,omitempty"`
	// Types that are valid to be assigned to L4Info:
	//	*DoSService_DstPort
	//	*DoSService_IcmpMsg
	L4Info isDoSService_L4Info `protobuf_oneof:"l4_info"`
}

func (m *DoSService) Reset()                    { *m = DoSService{} }
func (m *DoSService) String() string            { return proto.CompactTextString(m) }
func (*DoSService) ProtoMessage()               {}
func (*DoSService) Descriptor() ([]byte, []int) { return fileDescriptor31, []int{1} }

type isDoSService_L4Info interface{ isDoSService_L4Info() }

type DoSService_DstPort struct {
	DstPort uint32 `protobuf:"varint,2,opt,name=dst_port,json=dstPort,oneof"`
}
type DoSService_IcmpMsg struct {
	IcmpMsg *ICMPMsg `protobuf:"bytes,3,opt,name=icmp_msg,json=icmpMsg,oneof"`
}

func (*DoSService_DstPort) isDoSService_L4Info() {}
func (*DoSService_IcmpMsg) isDoSService_L4Info() {}

func (m *DoSService) GetL4Info() isDoSService_L4Info {
	if m != nil {
		return m.L4Info
	}
	return nil
}

func (m *DoSService) GetIpProtocol() IPProtocol {
	if m != nil {
		return m.IpProtocol
	}
	return IPProtocol_IPPROTO_NONE
}

func (m *DoSService) GetDstPort() uint32 {
	if x, ok := m.GetL4Info().(*DoSService_DstPort); ok {
		return x.DstPort
	}
	return 0
}

func (m *DoSService) GetIcmpMsg() *ICMPMsg {
	if x, ok := m.GetL4Info().(*DoSService_IcmpMsg); ok {
		return x.IcmpMsg
	}
	return nil
}

// XXX_OneofFuncs is for the internal use of the proto package.
func (*DoSService) XXX_OneofFuncs() (func(msg proto.Message, b *proto.Buffer) error, func(msg proto.Message, tag, wire int, b *proto.Buffer) (bool, error), func(msg proto.Message) (n int), []interface{}) {
	return _DoSService_OneofMarshaler, _DoSService_OneofUnmarshaler, _DoSService_OneofSizer, []interface{}{
		(*DoSService_DstPort)(nil),
		(*DoSService_IcmpMsg)(nil),
	}
}

func _DoSService_OneofMarshaler(msg proto.Message, b *proto.Buffer) error {
	m := msg.(*DoSService)
	// l4_info
	switch x := m.L4Info.(type) {
	case *DoSService_DstPort:
		b.EncodeVarint(2<<3 | proto.WireVarint)
		b.EncodeVarint(uint64(x.DstPort))
	case *DoSService_IcmpMsg:
		b.EncodeVarint(3<<3 | proto.WireBytes)
		if err := b.EncodeMessage(x.IcmpMsg); err != nil {
			return err
		}
	case nil:
	default:
		return fmt.Errorf("DoSService.L4Info has unexpected type %T", x)
	}
	return nil
}

func _DoSService_OneofUnmarshaler(msg proto.Message, tag, wire int, b *proto.Buffer) (bool, error) {
	m := msg.(*DoSService)
	switch tag {
	case 2: // l4_info.dst_port
		if wire != proto.WireVarint {
			return true, proto.ErrInternalBadWireType
		}
		x, err := b.DecodeVarint()
		m.L4Info = &DoSService_DstPort{uint32(x)}
		return true, err
	case 3: // l4_info.icmp_msg
		if wire != proto.WireBytes {
			return true, proto.ErrInternalBadWireType
		}
		msg := new(ICMPMsg)
		err := b.DecodeMessage(msg)
		m.L4Info = &DoSService_IcmpMsg{msg}
		return true, err
	default:
		return false, nil
	}
}

func _DoSService_OneofSizer(msg proto.Message) (n int) {
	m := msg.(*DoSService)
	// l4_info
	switch x := m.L4Info.(type) {
	case *DoSService_DstPort:
		n += proto.SizeVarint(2<<3 | proto.WireVarint)
		n += proto.SizeVarint(uint64(x.DstPort))
	case *DoSService_IcmpMsg:
		s := proto.Size(x.IcmpMsg)
		n += proto.SizeVarint(3<<3 | proto.WireBytes)
		n += proto.SizeVarint(uint64(s))
		n += s
	case nil:
	default:
		panic(fmt.Sprintf("proto: unexpected type %T in oneof", x))
	}
	return n
}

// DoSSessionLimits captures the session limits to be enforced on a security
// group
type DoSSessionLimits struct {
	MaxSessions     uint32 `protobuf:"varint,1,opt,name=max_sessions,json=maxSessions" json:"max_sessions,omitempty"`
	BlockingTimeout uint32 `protobuf:"varint,2,opt,name=blocking_timeout,json=blockingTimeout" json:"blocking_timeout,omitempty"`
}

func (m *DoSSessionLimits) Reset()                    { *m = DoSSessionLimits{} }
func (m *DoSSessionLimits) String() string            { return proto.CompactTextString(m) }
func (*DoSSessionLimits) ProtoMessage()               {}
func (*DoSSessionLimits) Descriptor() ([]byte, []int) { return fileDescriptor31, []int{2} }

func (m *DoSSessionLimits) GetMaxSessions() uint32 {
	if m != nil {
		return m.MaxSessions
	}
	return 0
}

func (m *DoSSessionLimits) GetBlockingTimeout() uint32 {
	if m != nil {
		return m.BlockingTimeout
	}
	return 0
}

// DoSPolicer is aggregate DoS policer object
type DoSPolicer struct {
	BytesPerSecond uint32 `protobuf:"varint,1,opt,name=bytes_per_second,json=bytesPerSecond" json:"bytes_per_second,omitempty"`
	PeakRate       uint32 `protobuf:"varint,2,opt,name=peak_rate,json=peakRate" json:"peak_rate,omitempty"`
	BurstSize      uint32 `protobuf:"varint,3,opt,name=burst_size,json=burstSize" json:"burst_size,omitempty"`
}

func (m *DoSPolicer) Reset()                    { *m = DoSPolicer{} }
func (m *DoSPolicer) String() string            { return proto.CompactTextString(m) }
func (*DoSPolicer) ProtoMessage()               {}
func (*DoSPolicer) Descriptor() ([]byte, []int) { return fileDescriptor31, []int{3} }

func (m *DoSPolicer) GetBytesPerSecond() uint32 {
	if m != nil {
		return m.BytesPerSecond
	}
	return 0
}

func (m *DoSPolicer) GetPeakRate() uint32 {
	if m != nil {
		return m.PeakRate
	}
	return 0
}

func (m *DoSPolicer) GetBurstSize() uint32 {
	if m != nil {
		return m.BurstSize
	}
	return 0
}

// DoSFloodLimits object captures the flood limits configuration
type DoSFloodLimits struct {
	RestrictLimits *DoSFloodLimits_RestrictLimits `protobuf:"bytes,1,opt,name=restrict_limits,json=restrictLimits" json:"restrict_limits,omitempty"`
	ProtectLimits  *DoSFloodLimits_ProtectLimits  `protobuf:"bytes,2,opt,name=protect_limits,json=protectLimits" json:"protect_limits,omitempty"`
}

func (m *DoSFloodLimits) Reset()                    { *m = DoSFloodLimits{} }
func (m *DoSFloodLimits) String() string            { return proto.CompactTextString(m) }
func (*DoSFloodLimits) ProtoMessage()               {}
func (*DoSFloodLimits) Descriptor() ([]byte, []int) { return fileDescriptor31, []int{4} }

func (m *DoSFloodLimits) GetRestrictLimits() *DoSFloodLimits_RestrictLimits {
	if m != nil {
		return m.RestrictLimits
	}
	return nil
}

func (m *DoSFloodLimits) GetProtectLimits() *DoSFloodLimits_ProtectLimits {
	if m != nil {
		return m.ProtectLimits
	}
	return nil
}

// default and only action in restrict phase is Random Early Drop (RED)
type DoSFloodLimits_RestrictLimits struct {
	Pps      uint32 `protobuf:"varint,1,opt,name=pps" json:"pps,omitempty"`
	BurstPps uint32 `protobuf:"varint,2,opt,name=burst_pps,json=burstPps" json:"burst_pps,omitempty"`
	Duration uint32 `protobuf:"varint,3,opt,name=duration" json:"duration,omitempty"`
}

func (m *DoSFloodLimits_RestrictLimits) Reset()         { *m = DoSFloodLimits_RestrictLimits{} }
func (m *DoSFloodLimits_RestrictLimits) String() string { return proto.CompactTextString(m) }
func (*DoSFloodLimits_RestrictLimits) ProtoMessage()    {}
func (*DoSFloodLimits_RestrictLimits) Descriptor() ([]byte, []int) {
	return fileDescriptor31, []int{4, 0}
}

func (m *DoSFloodLimits_RestrictLimits) GetPps() uint32 {
	if m != nil {
		return m.Pps
	}
	return 0
}

func (m *DoSFloodLimits_RestrictLimits) GetBurstPps() uint32 {
	if m != nil {
		return m.BurstPps
	}
	return 0
}

func (m *DoSFloodLimits_RestrictLimits) GetDuration() uint32 {
	if m != nil {
		return m.Duration
	}
	return 0
}

// default and only action in protection phase is drop
type DoSFloodLimits_ProtectLimits struct {
	Pps      uint32 `protobuf:"varint,1,opt,name=pps" json:"pps,omitempty"`
	BurstPps uint32 `protobuf:"varint,2,opt,name=burst_pps,json=burstPps" json:"burst_pps,omitempty"`
	Duration uint32 `protobuf:"varint,3,opt,name=duration" json:"duration,omitempty"`
}

func (m *DoSFloodLimits_ProtectLimits) Reset()         { *m = DoSFloodLimits_ProtectLimits{} }
func (m *DoSFloodLimits_ProtectLimits) String() string { return proto.CompactTextString(m) }
func (*DoSFloodLimits_ProtectLimits) ProtoMessage()    {}
func (*DoSFloodLimits_ProtectLimits) Descriptor() ([]byte, []int) {
	return fileDescriptor31, []int{4, 1}
}

func (m *DoSFloodLimits_ProtectLimits) GetPps() uint32 {
	if m != nil {
		return m.Pps
	}
	return 0
}

func (m *DoSFloodLimits_ProtectLimits) GetBurstPps() uint32 {
	if m != nil {
		return m.BurstPps
	}
	return 0
}

func (m *DoSFloodLimits_ProtectLimits) GetDuration() uint32 {
	if m != nil {
		return m.Duration
	}
	return 0
}

// DoSProtectionSpec defines DoS protection policy for a security group
type DoSProtectionSpec struct {
	Svc *DoSService `protobuf:"bytes,1,opt,name=svc" json:"svc,omitempty"`
	// service for which rest of
	// the DoS config to be
	// applied on
	SessionSetupRate  uint32            `protobuf:"varint,2,opt,name=session_setup_rate,json=sessionSetupRate" json:"session_setup_rate,omitempty"`
	SessionLimits     *DoSSessionLimits `protobuf:"bytes,3,opt,name=session_limits,json=sessionLimits" json:"session_limits,omitempty"`
	Policer           *DoSPolicer       `protobuf:"bytes,4,opt,name=policer" json:"policer,omitempty"`
	TcpSynFloodLimits *DoSFloodLimits   `protobuf:"bytes,5,opt,name=tcp_syn_flood_limits,json=tcpSynFloodLimits" json:"tcp_syn_flood_limits,omitempty"`
	UdpFloodLimits    *DoSFloodLimits   `protobuf:"bytes,6,opt,name=udp_flood_limits,json=udpFloodLimits" json:"udp_flood_limits,omitempty"`
	IcmpFloodLimits   *DoSFloodLimits   `protobuf:"bytes,7,opt,name=icmp_flood_limits,json=icmpFloodLimits" json:"icmp_flood_limits,omitempty"`
	OtherFloodLimits  *DoSFloodLimits   `protobuf:"bytes,8,opt,name=other_flood_limits,json=otherFloodLimits" json:"other_flood_limits,omitempty"`
	// traffic (IP and non-IP)
	PeerSgHandle uint64 `protobuf:"varint,9,opt,name=peer_sg_handle,json=peerSgHandle" json:"peer_sg_handle,omitempty"`
}

func (m *DoSProtectionSpec) Reset()                    { *m = DoSProtectionSpec{} }
func (m *DoSProtectionSpec) String() string            { return proto.CompactTextString(m) }
func (*DoSProtectionSpec) ProtoMessage()               {}
func (*DoSProtectionSpec) Descriptor() ([]byte, []int) { return fileDescriptor31, []int{5} }

func (m *DoSProtectionSpec) GetSvc() *DoSService {
	if m != nil {
		return m.Svc
	}
	return nil
}

func (m *DoSProtectionSpec) GetSessionSetupRate() uint32 {
	if m != nil {
		return m.SessionSetupRate
	}
	return 0
}

func (m *DoSProtectionSpec) GetSessionLimits() *DoSSessionLimits {
	if m != nil {
		return m.SessionLimits
	}
	return nil
}

func (m *DoSProtectionSpec) GetPolicer() *DoSPolicer {
	if m != nil {
		return m.Policer
	}
	return nil
}

func (m *DoSProtectionSpec) GetTcpSynFloodLimits() *DoSFloodLimits {
	if m != nil {
		return m.TcpSynFloodLimits
	}
	return nil
}

func (m *DoSProtectionSpec) GetUdpFloodLimits() *DoSFloodLimits {
	if m != nil {
		return m.UdpFloodLimits
	}
	return nil
}

func (m *DoSProtectionSpec) GetIcmpFloodLimits() *DoSFloodLimits {
	if m != nil {
		return m.IcmpFloodLimits
	}
	return nil
}

func (m *DoSProtectionSpec) GetOtherFloodLimits() *DoSFloodLimits {
	if m != nil {
		return m.OtherFloodLimits
	}
	return nil
}

func (m *DoSProtectionSpec) GetPeerSgHandle() uint64 {
	if m != nil {
		return m.PeerSgHandle
	}
	return 0
}

// ingress policy for DoS
type IngressDoSPolicy struct {
	DosProtection *DoSProtectionSpec `protobuf:"bytes,1,opt,name=dos_protection,json=dosProtection" json:"dos_protection,omitempty"`
}

func (m *IngressDoSPolicy) Reset()                    { *m = IngressDoSPolicy{} }
func (m *IngressDoSPolicy) String() string            { return proto.CompactTextString(m) }
func (*IngressDoSPolicy) ProtoMessage()               {}
func (*IngressDoSPolicy) Descriptor() ([]byte, []int) { return fileDescriptor31, []int{6} }

func (m *IngressDoSPolicy) GetDosProtection() *DoSProtectionSpec {
	if m != nil {
		return m.DosProtection
	}
	return nil
}

// egress policy for DoS
type EgressDoSPolicy struct {
	DosProtection *DoSProtectionSpec `protobuf:"bytes,1,opt,name=dos_protection,json=dosProtection" json:"dos_protection,omitempty"`
}

func (m *EgressDoSPolicy) Reset()                    { *m = EgressDoSPolicy{} }
func (m *EgressDoSPolicy) String() string            { return proto.CompactTextString(m) }
func (*EgressDoSPolicy) ProtoMessage()               {}
func (*EgressDoSPolicy) Descriptor() ([]byte, []int) { return fileDescriptor31, []int{7} }

func (m *EgressDoSPolicy) GetDosProtection() *DoSProtectionSpec {
	if m != nil {
		return m.DosProtection
	}
	return nil
}

// DoSPolicySpec that has the ingressDosPolicy and EgressDoSPolicy,
// Spec is identified by the handle. HAL will assign a unique handle for each
// DoSPolicy object and the clients are expected to pass the handle for
// Get/Modify/Delete calls. Note that there is no identifier for this object
type DoSPolicySpec struct {
	VrfKeyHandle  *VrfKeyHandle     `protobuf:"bytes,1,opt,name=vrf_key_handle,json=vrfKeyHandle" json:"vrf_key_handle,omitempty"`
	IngressPolicy *IngressDoSPolicy `protobuf:"bytes,2,opt,name=ingress_policy,json=ingressPolicy" json:"ingress_policy,omitempty"`
	EgressPolicy  *EgressDoSPolicy  `protobuf:"bytes,3,opt,name=egress_policy,json=egressPolicy" json:"egress_policy,omitempty"`
	DosHandle     uint64            `protobuf:"fixed64,4,opt,name=dos_handle,json=dosHandle" json:"dos_handle,omitempty"`
	SgHandle      []uint64          `protobuf:"varint,5,rep,packed,name=sg_handle,json=sgHandle" json:"sg_handle,omitempty"`
}

func (m *DoSPolicySpec) Reset()                    { *m = DoSPolicySpec{} }
func (m *DoSPolicySpec) String() string            { return proto.CompactTextString(m) }
func (*DoSPolicySpec) ProtoMessage()               {}
func (*DoSPolicySpec) Descriptor() ([]byte, []int) { return fileDescriptor31, []int{8} }

func (m *DoSPolicySpec) GetVrfKeyHandle() *VrfKeyHandle {
	if m != nil {
		return m.VrfKeyHandle
	}
	return nil
}

func (m *DoSPolicySpec) GetIngressPolicy() *IngressDoSPolicy {
	if m != nil {
		return m.IngressPolicy
	}
	return nil
}

func (m *DoSPolicySpec) GetEgressPolicy() *EgressDoSPolicy {
	if m != nil {
		return m.EgressPolicy
	}
	return nil
}

func (m *DoSPolicySpec) GetDosHandle() uint64 {
	if m != nil {
		return m.DosHandle
	}
	return 0
}

func (m *DoSPolicySpec) GetSgHandle() []uint64 {
	if m != nil {
		return m.SgHandle
	}
	return nil
}

// DoSPolicyRequestMsg is batched add or modify DoS request
type DoSPolicyRequestMsg struct {
	Request []*DoSPolicySpec `protobuf:"bytes,1,rep,name=request" json:"request,omitempty"`
}

func (m *DoSPolicyRequestMsg) Reset()                    { *m = DoSPolicyRequestMsg{} }
func (m *DoSPolicyRequestMsg) String() string            { return proto.CompactTextString(m) }
func (*DoSPolicyRequestMsg) ProtoMessage()               {}
func (*DoSPolicyRequestMsg) Descriptor() ([]byte, []int) { return fileDescriptor31, []int{9} }

func (m *DoSPolicyRequestMsg) GetRequest() []*DoSPolicySpec {
	if m != nil {
		return m.Request
	}
	return nil
}

// DoS operational status
type DoSPolicyStatus struct {
	DosHandle uint64 `protobuf:"fixed64,1,opt,name=dos_handle,json=dosHandle" json:"dos_handle,omitempty"`
}

func (m *DoSPolicyStatus) Reset()                    { *m = DoSPolicyStatus{} }
func (m *DoSPolicyStatus) String() string            { return proto.CompactTextString(m) }
func (*DoSPolicyStatus) ProtoMessage()               {}
func (*DoSPolicyStatus) Descriptor() ([]byte, []int) { return fileDescriptor31, []int{10} }

func (m *DoSPolicyStatus) GetDosHandle() uint64 {
	if m != nil {
		return m.DosHandle
	}
	return 0
}

// DoSResponse is the response to DoSPolicySpec
type DoSPolicyResponse struct {
	ApiStatus ApiStatus        `protobuf:"varint,1,opt,name=api_status,json=apiStatus,enum=types.ApiStatus" json:"api_status,omitempty"`
	Status    *DoSPolicyStatus `protobuf:"bytes,2,opt,name=status" json:"status,omitempty"`
}

func (m *DoSPolicyResponse) Reset()                    { *m = DoSPolicyResponse{} }
func (m *DoSPolicyResponse) String() string            { return proto.CompactTextString(m) }
func (*DoSPolicyResponse) ProtoMessage()               {}
func (*DoSPolicyResponse) Descriptor() ([]byte, []int) { return fileDescriptor31, []int{11} }

func (m *DoSPolicyResponse) GetApiStatus() ApiStatus {
	if m != nil {
		return m.ApiStatus
	}
	return ApiStatus_API_STATUS_OK
}

func (m *DoSPolicyResponse) GetStatus() *DoSPolicyStatus {
	if m != nil {
		return m.Status
	}
	return nil
}

// DoSPolicyResponseMsg is batched response to DoSPolicyRequestMsg
type DoSPolicyResponseMsg struct {
	Response []*DoSPolicyResponse `protobuf:"bytes,1,rep,name=response" json:"response,omitempty"`
}

func (m *DoSPolicyResponseMsg) Reset()                    { *m = DoSPolicyResponseMsg{} }
func (m *DoSPolicyResponseMsg) String() string            { return proto.CompactTextString(m) }
func (*DoSPolicyResponseMsg) ProtoMessage()               {}
func (*DoSPolicyResponseMsg) Descriptor() ([]byte, []int) { return fileDescriptor31, []int{12} }

func (m *DoSPolicyResponseMsg) GetResponse() []*DoSPolicyResponse {
	if m != nil {
		return m.Response
	}
	return nil
}

// DoSRequest is used to delete a DoS
type DoSPolicyDeleteRequest struct {
	DosHandle uint64 `protobuf:"fixed64,1,opt,name=dos_handle,json=dosHandle" json:"dos_handle,omitempty"`
}

func (m *DoSPolicyDeleteRequest) Reset()                    { *m = DoSPolicyDeleteRequest{} }
func (m *DoSPolicyDeleteRequest) String() string            { return proto.CompactTextString(m) }
func (*DoSPolicyDeleteRequest) ProtoMessage()               {}
func (*DoSPolicyDeleteRequest) Descriptor() ([]byte, []int) { return fileDescriptor31, []int{13} }

func (m *DoSPolicyDeleteRequest) GetDosHandle() uint64 {
	if m != nil {
		return m.DosHandle
	}
	return 0
}

// DoSPolicyDeleteRequestMsg is used to delete a batch of security groups
type DoSPolicyDeleteRequestMsg struct {
	Request []*DoSPolicyDeleteRequest `protobuf:"bytes,1,rep,name=request" json:"request,omitempty"`
}

func (m *DoSPolicyDeleteRequestMsg) Reset()                    { *m = DoSPolicyDeleteRequestMsg{} }
func (m *DoSPolicyDeleteRequestMsg) String() string            { return proto.CompactTextString(m) }
func (*DoSPolicyDeleteRequestMsg) ProtoMessage()               {}
func (*DoSPolicyDeleteRequestMsg) Descriptor() ([]byte, []int) { return fileDescriptor31, []int{14} }

func (m *DoSPolicyDeleteRequestMsg) GetRequest() []*DoSPolicyDeleteRequest {
	if m != nil {
		return m.Request
	}
	return nil
}

type DoSPolicyDeleteResponse struct {
	ApiStatus ApiStatus `protobuf:"varint,1,opt,name=api_status,json=apiStatus,enum=types.ApiStatus" json:"api_status,omitempty"`
}

func (m *DoSPolicyDeleteResponse) Reset()                    { *m = DoSPolicyDeleteResponse{} }
func (m *DoSPolicyDeleteResponse) String() string            { return proto.CompactTextString(m) }
func (*DoSPolicyDeleteResponse) ProtoMessage()               {}
func (*DoSPolicyDeleteResponse) Descriptor() ([]byte, []int) { return fileDescriptor31, []int{15} }

func (m *DoSPolicyDeleteResponse) GetApiStatus() ApiStatus {
	if m != nil {
		return m.ApiStatus
	}
	return ApiStatus_API_STATUS_OK
}

// DoSPolicyDeleteResponseMsg is batched response to
// DoSPolicyDeleteRequestMsg
type DoSPolicyDeleteResponseMsg struct {
	Response []*DoSPolicyDeleteResponse `protobuf:"bytes,1,rep,name=response" json:"response,omitempty"`
}

func (m *DoSPolicyDeleteResponseMsg) Reset()                    { *m = DoSPolicyDeleteResponseMsg{} }
func (m *DoSPolicyDeleteResponseMsg) String() string            { return proto.CompactTextString(m) }
func (*DoSPolicyDeleteResponseMsg) ProtoMessage()               {}
func (*DoSPolicyDeleteResponseMsg) Descriptor() ([]byte, []int) { return fileDescriptor31, []int{16} }

func (m *DoSPolicyDeleteResponseMsg) GetResponse() []*DoSPolicyDeleteResponse {
	if m != nil {
		return m.Response
	}
	return nil
}

// DoSGetRequest is used to get information about a DoS
type DoSPolicyGetRequest struct {
	DosHandle uint64 `protobuf:"fixed64,1,opt,name=dos_handle,json=dosHandle" json:"dos_handle,omitempty"`
}

func (m *DoSPolicyGetRequest) Reset()                    { *m = DoSPolicyGetRequest{} }
func (m *DoSPolicyGetRequest) String() string            { return proto.CompactTextString(m) }
func (*DoSPolicyGetRequest) ProtoMessage()               {}
func (*DoSPolicyGetRequest) Descriptor() ([]byte, []int) { return fileDescriptor31, []int{17} }

func (m *DoSPolicyGetRequest) GetDosHandle() uint64 {
	if m != nil {
		return m.DosHandle
	}
	return 0
}

// DoSPolicyGetRequestMsg is batched GET request for DoS
type DoSPolicyGetRequestMsg struct {
	Request []*DoSPolicyGetRequest `protobuf:"bytes,1,rep,name=request" json:"request,omitempty"`
}

func (m *DoSPolicyGetRequestMsg) Reset()                    { *m = DoSPolicyGetRequestMsg{} }
func (m *DoSPolicyGetRequestMsg) String() string            { return proto.CompactTextString(m) }
func (*DoSPolicyGetRequestMsg) ProtoMessage()               {}
func (*DoSPolicyGetRequestMsg) Descriptor() ([]byte, []int) { return fileDescriptor31, []int{18} }

func (m *DoSPolicyGetRequestMsg) GetRequest() []*DoSPolicyGetRequest {
	if m != nil {
		return m.Request
	}
	return nil
}

// DoSPolicyStats is the statistics object for a security group
type DoSPolicyStats struct {
}

func (m *DoSPolicyStats) Reset()                    { *m = DoSPolicyStats{} }
func (m *DoSPolicyStats) String() string            { return proto.CompactTextString(m) }
func (*DoSPolicyStats) ProtoMessage()               {}
func (*DoSPolicyStats) Descriptor() ([]byte, []int) { return fileDescriptor31, []int{19} }

// DoSGetResponse captures all the information about a security group
type DoSPolicyGetResponse struct {
	ApiStatus ApiStatus        `protobuf:"varint,1,opt,name=api_status,json=apiStatus,enum=types.ApiStatus" json:"api_status,omitempty"`
	Spec      *DoSPolicySpec   `protobuf:"bytes,2,opt,name=spec" json:"spec,omitempty"`
	Status    *DoSPolicyStatus `protobuf:"bytes,3,opt,name=status" json:"status,omitempty"`
	Stats     *DoSPolicyStats  `protobuf:"bytes,4,opt,name=stats" json:"stats,omitempty"`
}

func (m *DoSPolicyGetResponse) Reset()                    { *m = DoSPolicyGetResponse{} }
func (m *DoSPolicyGetResponse) String() string            { return proto.CompactTextString(m) }
func (*DoSPolicyGetResponse) ProtoMessage()               {}
func (*DoSPolicyGetResponse) Descriptor() ([]byte, []int) { return fileDescriptor31, []int{20} }

func (m *DoSPolicyGetResponse) GetApiStatus() ApiStatus {
	if m != nil {
		return m.ApiStatus
	}
	return ApiStatus_API_STATUS_OK
}

func (m *DoSPolicyGetResponse) GetSpec() *DoSPolicySpec {
	if m != nil {
		return m.Spec
	}
	return nil
}

func (m *DoSPolicyGetResponse) GetStatus() *DoSPolicyStatus {
	if m != nil {
		return m.Status
	}
	return nil
}

func (m *DoSPolicyGetResponse) GetStats() *DoSPolicyStats {
	if m != nil {
		return m.Stats
	}
	return nil
}

// DoSPolicyGetResponseMsg is batched response to DoSPolicyGetRequestMsg
type DoSPolicyGetResponseMsg struct {
	Response []*DoSPolicyGetResponse `protobuf:"bytes,1,rep,name=response" json:"response,omitempty"`
}

func (m *DoSPolicyGetResponseMsg) Reset()                    { *m = DoSPolicyGetResponseMsg{} }
func (m *DoSPolicyGetResponseMsg) String() string            { return proto.CompactTextString(m) }
func (*DoSPolicyGetResponseMsg) ProtoMessage()               {}
func (*DoSPolicyGetResponseMsg) Descriptor() ([]byte, []int) { return fileDescriptor31, []int{21} }

func (m *DoSPolicyGetResponseMsg) GetResponse() []*DoSPolicyGetResponse {
	if m != nil {
		return m.Response
	}
	return nil
}

func init() {
	proto.RegisterType((*ICMPMsg)(nil), "halproto.ICMPMsg")
	proto.RegisterType((*DoSService)(nil), "halproto.DoSService")
	proto.RegisterType((*DoSSessionLimits)(nil), "halproto.DoSSessionLimits")
	proto.RegisterType((*DoSPolicer)(nil), "halproto.DoSPolicer")
	proto.RegisterType((*DoSFloodLimits)(nil), "halproto.DoSFloodLimits")
	proto.RegisterType((*DoSFloodLimits_RestrictLimits)(nil), "halproto.DoSFloodLimits.RestrictLimits")
	proto.RegisterType((*DoSFloodLimits_ProtectLimits)(nil), "halproto.DoSFloodLimits.ProtectLimits")
	proto.RegisterType((*DoSProtectionSpec)(nil), "halproto.DoSProtectionSpec")
	proto.RegisterType((*IngressDoSPolicy)(nil), "halproto.IngressDoSPolicy")
	proto.RegisterType((*EgressDoSPolicy)(nil), "halproto.EgressDoSPolicy")
	proto.RegisterType((*DoSPolicySpec)(nil), "halproto.DoSPolicySpec")
	proto.RegisterType((*DoSPolicyRequestMsg)(nil), "halproto.DoSPolicyRequestMsg")
	proto.RegisterType((*DoSPolicyStatus)(nil), "halproto.DoSPolicyStatus")
	proto.RegisterType((*DoSPolicyResponse)(nil), "halproto.DoSPolicyResponse")
	proto.RegisterType((*DoSPolicyResponseMsg)(nil), "halproto.DoSPolicyResponseMsg")
	proto.RegisterType((*DoSPolicyDeleteRequest)(nil), "halproto.DoSPolicyDeleteRequest")
	proto.RegisterType((*DoSPolicyDeleteRequestMsg)(nil), "halproto.DoSPolicyDeleteRequestMsg")
	proto.RegisterType((*DoSPolicyDeleteResponse)(nil), "halproto.DoSPolicyDeleteResponse")
	proto.RegisterType((*DoSPolicyDeleteResponseMsg)(nil), "halproto.DoSPolicyDeleteResponseMsg")
	proto.RegisterType((*DoSPolicyGetRequest)(nil), "halproto.DoSPolicyGetRequest")
	proto.RegisterType((*DoSPolicyGetRequestMsg)(nil), "halproto.DoSPolicyGetRequestMsg")
	proto.RegisterType((*DoSPolicyStats)(nil), "halproto.DoSPolicyStats")
	proto.RegisterType((*DoSPolicyGetResponse)(nil), "halproto.DoSPolicyGetResponse")
	proto.RegisterType((*DoSPolicyGetResponseMsg)(nil), "halproto.DoSPolicyGetResponseMsg")
}

func init() { proto.RegisterFile("dos.proto", fileDescriptor31) }

var fileDescriptor31 = []byte{
	// 1147 bytes of a gzipped FileDescriptorProto
	0x1f, 0x8b, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xff, 0xac, 0x57, 0xdd, 0x6e, 0x1a, 0x47,
	0x14, 0x0e, 0x86, 0x18, 0x38, 0xc0, 0xb2, 0x9e, 0x24, 0x2e, 0xc6, 0x49, 0x83, 0x57, 0x55, 0x84,
	0x25, 0x0b, 0x55, 0x34, 0xfd, 0x55, 0xa3, 0x2a, 0xb6, 0x93, 0x3a, 0x75, 0x2c, 0xd1, 0xc1, 0xcd,
	0x45, 0x7a, 0xb1, 0x5d, 0xef, 0x8e, 0xf1, 0xca, 0xb0, 0x33, 0xdd, 0x19, 0xac, 0x90, 0x37, 0xe8,
	0x75, 0x5f, 0xa7, 0xcf, 0xd2, 0xf6, 0x19, 0x7a, 0x9d, 0x8b, 0x6a, 0x7e, 0x96, 0xdd, 0xc5, 0x90,
	0x54, 0xaa, 0xaf, 0x3c, 0x73, 0x7e, 0xbe, 0x39, 0xe7, 0x3b, 0xdf, 0x30, 0x6b, 0xa8, 0x06, 0x94,
	0xf7, 0x58, 0x4c, 0x05, 0x45, 0xc5, 0x80, 0xf2, 0x76, 0x4d, 0xcc, 0x18, 0x31, 0x96, 0x76, 0xe5,
	0xf2, 0x42, 0xaf, 0x9c, 0x67, 0x50, 0x7e, 0x71, 0x70, 0x32, 0x38, 0xe1, 0x23, 0xf4, 0x08, 0x4a,
	0x32, 0xa6, 0x55, 0xe8, 0x14, 0xba, 0x56, 0x1f, 0xf5, 0x74, 0x82, 0xf1, 0x9e, 0xce, 0x18, 0xc1,
	0xca, 0x8f, 0x10, 0x94, 0x7c, 0x1a, 0x90, 0xd6, 0x5a, 0xa7, 0xd0, 0x6d, 0x60, 0xb5, 0x76, 0x7e,
	0x2f, 0x00, 0x1c, 0xd2, 0xe1, 0x90, 0xc4, 0x57, 0xa1, 0x4f, 0x50, 0x1f, 0x6a, 0x21, 0x73, 0xd5,
	0x09, 0x3e, 0x1d, 0x1b, 0xc4, 0x8d, 0x04, 0x71, 0x30, 0x30, 0x0e, 0x0c, 0x21, 0x4b, 0xd6, 0x68,
	0x1b, 0x2a, 0x01, 0x17, 0x2e, 0xa3, 0xb1, 0xd0, 0xd0, 0x47, 0xb7, 0x70, 0x39, 0xe0, 0x62, 0x40,
	0x63, 0x81, 0x76, 0xa1, 0x12, 0xfa, 0x13, 0xe6, 0x4e, 0xf8, 0xa8, 0x55, 0xec, 0x14, 0xba, 0xb5,
	0x7e, 0xbd, 0x27, 0x1b, 0x34, 0xd5, 0xc9, 0x50, 0xe9, 0x3f, 0xe1, 0xa3, 0xfd, 0x2a, 0x94, 0xc7,
	0x8f, 0xdd, 0x30, 0x3a, 0xa7, 0xce, 0x2f, 0x60, 0xab, 0xa2, 0x38, 0x0f, 0x69, 0xf4, 0x32, 0x9c,
	0x84, 0x82, 0xa3, 0x1d, 0xa8, 0x4f, 0xbc, 0x37, 0x2e, 0xd7, 0x46, 0xae, 0x6a, 0x6b, 0xe0, 0xda,
	0xc4, 0x7b, 0x63, 0xe2, 0x38, 0xda, 0x05, 0xfb, 0x6c, 0x4c, 0xfd, 0xcb, 0x30, 0x1a, 0xb9, 0x22,
	0x9c, 0x10, 0x3a, 0x35, 0x15, 0xe1, 0x66, 0x62, 0x3f, 0xd5, 0x66, 0x27, 0x56, 0x6d, 0x0f, 0xe8,
	0x38, 0xf4, 0x49, 0x8c, 0xba, 0x60, 0x9f, 0xcd, 0x04, 0xe1, 0x2e, 0x23, 0xb1, 0xcb, 0x89, 0x4f,
	0xa3, 0xc0, 0xe0, 0x5b, 0xca, 0x3e, 0x20, 0xf1, 0x50, 0x59, 0xd1, 0x36, 0x54, 0x19, 0xf1, 0x2e,
	0xdd, 0xd8, 0x13, 0x09, 0x91, 0x15, 0x69, 0xc0, 0x9e, 0x20, 0xe8, 0x01, 0xc0, 0xd9, 0x34, 0xe6,
	0xc2, 0xe5, 0xe1, 0x5b, 0xa2, 0xda, 0x6d, 0xe0, 0xaa, 0xb2, 0x0c, 0xc3, 0xb7, 0xc4, 0xf9, 0x7b,
	0x0d, 0xac, 0x43, 0x3a, 0x7c, 0x3e, 0xa6, 0x34, 0x30, 0x4d, 0x1d, 0x43, 0x33, 0x26, 0x5c, 0xc4,
	0xa1, 0x2f, 0xdc, 0xb1, 0x32, 0xa9, 0x73, 0x6b, 0x7d, 0x47, 0xb1, 0x94, 0x8f, 0xee, 0x61, 0x13,
	0xaa, 0xb7, 0xd8, 0x8a, 0x73, 0x7b, 0x74, 0x04, 0x96, 0x9c, 0x1c, 0x49, 0xb1, 0xd6, 0x14, 0xd6,
	0xce, 0x32, 0xac, 0x81, 0x8e, 0x34, 0x50, 0x0d, 0x96, 0xdd, 0xb6, 0x7f, 0x06, 0x2b, 0x7f, 0x16,
	0xb2, 0xa1, 0xc8, 0x58, 0x42, 0xba, 0x5c, 0x4a, 0x26, 0x74, 0xb3, 0xd2, 0x6e, 0x98, 0x50, 0x86,
	0x01, 0xe3, 0xa8, 0x0d, 0x95, 0x60, 0x1a, 0x7b, 0x22, 0xa4, 0x91, 0xe1, 0x61, 0xbe, 0x6f, 0xbf,
	0x86, 0x46, 0xee, 0xf0, 0x1b, 0xc4, 0x76, 0xde, 0x15, 0x61, 0x43, 0xce, 0x55, 0xe3, 0x87, 0x34,
	0x1a, 0x32, 0xe2, 0xa3, 0x1d, 0x28, 0xf2, 0x2b, 0xdf, 0x30, 0xdb, 0x4c, 0xd8, 0x30, 0x9a, 0xc7,
	0xd2, 0x87, 0xf6, 0x00, 0x19, 0x65, 0xb9, 0x9c, 0x88, 0x29, 0xcb, 0x0e, 0xd8, 0x36, 0x9e, 0xa1,
	0x74, 0xa8, 0x41, 0x7f, 0x0b, 0x56, 0x12, 0x6d, 0x98, 0xd6, 0xda, 0xbe, 0x97, 0x62, 0x67, 0xa4,
	0x8b, 0x1b, 0x3c, 0xa7, 0xe4, 0x5d, 0x28, 0x33, 0x2d, 0xbc, 0x56, 0x29, 0x5f, 0x92, 0xd1, 0x23,
	0x4e, 0xfc, 0xe8, 0x10, 0xee, 0x0a, 0x9f, 0xb9, 0x7c, 0x16, 0xb9, 0xe7, 0x72, 0x78, 0xc9, 0x71,
	0xb7, 0x55, 0xde, 0x9d, 0x25, 0x83, 0xc5, 0x1b, 0xc2, 0x67, 0xc3, 0x59, 0x94, 0x55, 0xd9, 0x13,
	0xb0, 0xa7, 0x01, 0xcb, 0x23, 0xac, 0xaf, 0x46, 0xb0, 0xa6, 0x01, 0xcb, 0xa6, 0x7f, 0x07, 0x1b,
	0xea, 0x0e, 0xe7, 0xf2, 0xcb, 0xab, 0xf3, 0x9b, 0x32, 0x3a, 0x0b, 0xf0, 0x14, 0x10, 0x15, 0x17,
	0x24, 0xce, 0x23, 0x54, 0x56, 0x23, 0xd8, 0x2a, 0x3c, 0x0b, 0xf1, 0x09, 0x58, 0x8c, 0xc8, 0xcb,
	0x39, 0x72, 0x2f, 0xbc, 0x28, 0x18, 0x93, 0x56, 0xb5, 0x53, 0xe8, 0x96, 0x70, 0x5d, 0x5a, 0x87,
	0xa3, 0x23, 0x65, 0x73, 0x7e, 0x04, 0xfb, 0x45, 0x34, 0x8a, 0x09, 0xe7, 0x09, 0x99, 0x33, 0xf4,
	0x04, 0xac, 0x80, 0x72, 0x97, 0xcd, 0x25, 0x61, 0x74, 0xb0, 0x39, 0x27, 0x3d, 0x27, 0x16, 0xdc,
	0x08, 0x28, 0x4f, 0x4d, 0xce, 0x00, 0x9a, 0xcf, 0x6e, 0x16, 0xf1, 0x5d, 0x01, 0x1a, 0x73, 0x30,
	0xa5, 0xcf, 0x2f, 0xc0, 0xba, 0x8a, 0xcf, 0xdd, 0x4b, 0x32, 0x4b, 0x9a, 0xd3, 0x80, 0x76, 0xef,
	0xf2, 0xa2, 0xf7, 0x2a, 0x3e, 0x3f, 0x26, 0x33, 0xdd, 0x20, 0xae, 0x5f, 0x65, 0x76, 0x52, 0x86,
	0xa1, 0x6e, 0xd7, 0x55, 0x82, 0x99, 0x99, 0x0b, 0xaf, 0x65, 0xb8, 0xc8, 0x04, 0x6e, 0x98, 0x60,
	0xd3, 0xc6, 0xd7, 0xd0, 0x20, 0xb9, 0x64, 0xad, 0xe1, 0xbb, 0x2a, 0x79, 0xa1, 0x67, 0x5c, 0x27,
	0xd9, 0xd4, 0x07, 0x00, 0x92, 0x01, 0x53, 0xac, 0x14, 0xf1, 0x3a, 0x96, 0xef, 0x96, 0xa9, 0x6b,
	0x1b, 0xaa, 0xe9, 0x9c, 0x6e, 0x77, 0x8a, 0xdd, 0x12, 0xae, 0xf0, 0x64, 0x46, 0x07, 0x70, 0x27,
	0x85, 0x25, 0xbf, 0x4e, 0x09, 0x17, 0xf2, 0x11, 0xdb, 0x83, 0x72, 0xac, 0x77, 0xad, 0x42, 0xa7,
	0xd8, 0xad, 0xf5, 0x51, 0xee, 0x52, 0x28, 0xa2, 0x70, 0x12, 0xe2, 0x7c, 0x0a, 0xcd, 0xd4, 0x23,
	0x3c, 0x31, 0xe5, 0x0b, 0x35, 0x15, 0x16, 0x6a, 0x72, 0x7e, 0x2b, 0xe8, 0x5f, 0x06, 0x73, 0x2e,
	0x67, 0x34, 0xe2, 0x04, 0x3d, 0x07, 0xf0, 0x58, 0xe8, 0x72, 0x05, 0x61, 0x9e, 0x3b, 0xdb, 0x3c,
	0x77, 0x4f, 0x59, 0xa8, 0xa1, 0xf7, 0xef, 0xfd, 0xf3, 0xe7, 0xc3, 0x8d, 0x2b, 0x12, 0x85, 0x3e,
	0xf9, 0x26, 0x0d, 0xc7, 0x55, 0x2f, 0x89, 0x40, 0x7b, 0xb0, 0x6e, 0x30, 0xd6, 0x32, 0x24, 0x2e,
	0x94, 0x88, 0x4d, 0x8c, 0xf3, 0x03, 0xdc, 0xbd, 0x56, 0x8a, 0xe4, 0xa0, 0x0f, 0x95, 0xd8, 0x6c,
	0x0d, 0x09, 0x9b, 0x79, 0x9c, 0x24, 0x18, 0xcf, 0xe3, 0x9c, 0x2f, 0x61, 0x73, 0xee, 0x3e, 0x24,
	0x63, 0x22, 0x88, 0x21, 0xf5, 0x43, 0x84, 0x60, 0xd8, 0x5a, 0x9e, 0x28, 0x2b, 0xf9, 0x7c, 0x71,
	0x1a, 0xdb, 0xf9, 0x42, 0x72, 0x09, 0xe9, 0x58, 0x3c, 0xf8, 0xe8, 0x5a, 0xc8, 0xcd, 0x32, 0xed,
	0xbc, 0x82, 0xf6, 0x8a, 0x23, 0x64, 0xdd, 0x5f, 0x5d, 0x63, 0xf0, 0xfe, 0xf2, 0xc2, 0xaf, 0xf1,
	0xf8, 0x38, 0x23, 0xcb, 0xef, 0x89, 0xf8, 0x8f, 0x24, 0xbe, 0xcc, 0xb0, 0x9f, 0x66, 0xe9, 0x59,
	0x2e, 0x30, 0xd8, 0xca, 0x17, 0x92, 0x46, 0xa7, 0xf4, 0xd9, 0xea, 0xfb, 0x20, 0x95, 0x0c, 0x77,
	0xfe, 0x2a, 0x64, 0xa4, 0xa2, 0x52, 0x6e, 0x58, 0xb8, 0x8f, 0xa0, 0xc4, 0x19, 0xf1, 0x8d, 0x6c,
	0x97, 0xdd, 0x39, 0xe5, 0xcf, 0x08, 0xbc, 0xf8, 0x61, 0x81, 0xa3, 0x5d, 0xb8, 0x2d, 0x57, 0xdc,
	0xbc, 0x6f, 0x77, 0xae, 0x07, 0x73, 0xac, 0x23, 0x9c, 0x41, 0x46, 0x32, 0x99, 0x06, 0xb5, 0x08,
	0x17, 0x87, 0xb9, 0xb5, 0x84, 0xc3, 0xc5, 0x49, 0xf6, 0xff, 0x58, 0x83, 0xe2, 0x21, 0x95, 0x9f,
	0x43, 0xe9, 0x6f, 0xc4, 0x41, 0x4c, 0xe4, 0xbb, 0xdd, 0x5a, 0xbc, 0x4e, 0xc9, 0xb8, 0xda, 0x5b,
	0xcb, 0x2f, 0xda, 0x09, 0x1f, 0x39, 0xb7, 0x72, 0x48, 0x3f, 0xb1, 0xe0, 0x7f, 0x20, 0x9d, 0x66,
	0x90, 0xb4, 0x14, 0xd1, 0xc7, 0xef, 0xb9, 0x59, 0x12, 0xef, 0xe1, 0xfb, 0x04, 0xac, 0x51, 0x8f,
	0xa1, 0x9e, 0xe5, 0x04, 0x6d, 0xaf, 0x92, 0x9a, 0xc4, 0xbb, 0xbf, 0x92, 0x43, 0x05, 0xb6, 0x0f,
	0xaf, 0x2b, 0x17, 0xde, 0x58, 0xfd, 0x0b, 0x70, 0xb6, 0xae, 0xfe, 0x7c, 0xf6, 0x6f, 0x00, 0x00,
	0x00, 0xff, 0xff, 0xd5, 0x6d, 0x16, 0xfb, 0x94, 0x0c, 0x00, 0x00,
}
