// Code generated by protoc-gen-go. DO NOT EDIT.
// source: vrf.proto

package halproto

import proto "github.com/golang/protobuf/proto"
import fmt "fmt"
import math "math"
import clientApi "github.com/pensando/sw/nic/delphi/gosdk/client_api"
import delphi "github.com/pensando/sw/nic/delphi/proto/delphi"

// Reference imports to suppress errors if they are not otherwise used.
var _ = proto.Marshal
var _ = fmt.Errorf
var _ = math.Inf

// VrfSpec captures all the vrf level configuration
type VrfSpec struct {
	Meta *delphi.ObjectMeta `protobuf:"bytes,1,opt,name=Meta" json:"Meta,omitempty"`
	// key_or_handle is vrf's unique identifier
	KeyOrHandle       *VrfKeyHandle             `protobuf:"bytes,2,opt,name=key_or_handle,json=keyOrHandle" json:"key_or_handle,omitempty"`
	SecurityKeyHandle *SecurityProfileKeyHandle `protobuf:"bytes,3,opt,name=security_key_handle,json=securityKeyHandle" json:"security_key_handle,omitempty"`
	VrfType           VrfType                   `protobuf:"varint,4,opt,name=vrf_type,json=vrfType,enum=types.VrfType" json:"vrf_type,omitempty"`
	MytepIp           *IPAddress                `protobuf:"bytes,5,opt,name=mytep_ip,json=mytepIp" json:"mytep_ip,omitempty"`
	GipoPrefix        *IPPrefix                 `protobuf:"bytes,6,opt,name=gipo_prefix,json=gipoPrefix" json:"gipo_prefix,omitempty"`
}

func (m *VrfSpec) GetDelphiMessage() proto.Message {
	return m
}

func (m *VrfSpec) GetDelphiMeta() *delphi.ObjectMeta {
	return m.Meta
}

func (m *VrfSpec) SetDelphiMeta(meta *delphi.ObjectMeta) {
	m.Meta = meta
}

func (m *VrfSpec) GetDelphiKey() string {
	return m.KeyOrHandle.String()
}

func (m *VrfSpec) GetDelphiKind() string {
	return "VrfSpec"
}

func (m *VrfSpec) GetDelphiPath() string {
	return fmt.Sprintf("%s|%s", m.GetDelphiKind(), m.GetDelphiKey())
}

func (m *VrfSpec) DelphiClone() clientApi.BaseObject {
	obj, _ := proto.Clone(m).(*VrfSpec)
	return obj
}

func VrfSpecMount(client clientApi.Client, mode delphi.MountMode) {
	client.MountKind("VrfSpec", mode)
}

func VrfSpecMountKey(client clientApi.Client, key *VrfKeyHandle, mode delphi.MountMode) {
	client.MountKindKey("VrfSpec", key.String(), mode)
}

func GetVrfSpec(client clientApi.Client, key *VrfKeyHandle) *VrfSpec {
	o := client.GetObject("VrfSpec", key.String())
	if o == nil {
		return nil
	}
	obj, ok := o.(*VrfSpec)
	if ok != true {
		panic("Cast failed")
	}
	return obj
}

func VrfSpecFactory(sdkClient clientApi.Client, data []byte) (clientApi.BaseObject, error) {
	var msg VrfSpec
	err := proto.Unmarshal(data, &msg)
	if err != nil {
		return nil, err
	}
	return &msg, nil
}

func VrfSpecWatch(client clientApi.Client, reactor VrfSpecReactor) {
	client.WatchKind("VrfSpec", reactor)
}
func VrfSpecList(client clientApi.Client) []*VrfSpec {
	bobjs := client.List("VrfSpec")
	objs := make([]*VrfSpec, 0)
	for _, bobj := range bobjs {
		obj, _ := bobj.(*VrfSpec)
		objs = append(objs, obj)
	}
	return objs
}
func (m *VrfSpec) TriggerEvent(sdkClient clientApi.Client, old clientApi.BaseObject, op delphi.ObjectOperation, rl []clientApi.BaseReactor) {
	for _, r := range rl {
		rctr, ok := r.(VrfSpecReactor)
		if ok == false {
			panic("Not a Reactor")
		}
		if op == delphi.ObjectOperation_SetOp {
			if old == nil {
				rctr.OnVrfSpecCreate(m)
			} else {
				oldObj, ok := old.(*VrfSpec)
				if ok == false {
					panic("Not an VrfSpec object")
				}
				rctr.OnVrfSpecUpdate(oldObj, m)
			}
		} else {
			rctr.OnVrfSpecDelete(m)
		}
	}
}

type VrfSpecReactor interface {
	OnVrfSpecCreate(obj *VrfSpec)
	OnVrfSpecUpdate(old *VrfSpec, obj *VrfSpec)
	OnVrfSpecDelete(obj *VrfSpec)
}

func (m *VrfSpec) Reset()                    { *m = VrfSpec{} }
func (m *VrfSpec) String() string            { return proto.CompactTextString(m) }
func (*VrfSpec) ProtoMessage()               {}
func (*VrfSpec) Descriptor() ([]byte, []int) { return fileDescriptor40, []int{0} }

func (m *VrfSpec) GetMeta() *delphi.ObjectMeta {
	if m != nil {
		return m.Meta
	}
	return nil
}

func (m *VrfSpec) GetKeyOrHandle() *VrfKeyHandle {
	if m != nil {
		return m.KeyOrHandle
	}
	return nil
}

func (m *VrfSpec) GetSecurityKeyHandle() *SecurityProfileKeyHandle {
	if m != nil {
		return m.SecurityKeyHandle
	}
	return nil
}

func (m *VrfSpec) GetVrfType() VrfType {
	if m != nil {
		return m.VrfType
	}
	return VrfType_VRF_TYPE_NONE
}

func (m *VrfSpec) GetMytepIp() *IPAddress {
	if m != nil {
		return m.MytepIp
	}
	return nil
}

func (m *VrfSpec) GetGipoPrefix() *IPPrefix {
	if m != nil {
		return m.GipoPrefix
	}
	return nil
}

// VrfRequestMsg is batched add or modify vrf request
type VrfRequestMsg struct {
	Request []*VrfSpec `protobuf:"bytes,1,rep,name=request" json:"request,omitempty"`
}

func (m *VrfRequestMsg) Reset()                    { *m = VrfRequestMsg{} }
func (m *VrfRequestMsg) String() string            { return proto.CompactTextString(m) }
func (*VrfRequestMsg) ProtoMessage()               {}
func (*VrfRequestMsg) Descriptor() ([]byte, []int) { return fileDescriptor40, []int{1} }

func (m *VrfRequestMsg) GetRequest() []*VrfSpec {
	if m != nil {
		return m.Request
	}
	return nil
}

// Vrf oper state for enterprise pipeline
type VrfStatusEpd struct {
	HwVrfId       uint32 `protobuf:"varint,1,opt,name=hw_vrf_id,json=hwVrfId" json:"hw_vrf_id,omitempty"`
	VrfLookupId   uint32 `protobuf:"varint,2,opt,name=vrf_lookup_id,json=vrfLookupId" json:"vrf_lookup_id,omitempty"`
	VrfVlanIdCpu  uint32 `protobuf:"varint,3,opt,name=vrf_vlan_id_cpu,json=vrfVlanIdCpu" json:"vrf_vlan_id_cpu,omitempty"`
	InpPropCpuIdx uint32 `protobuf:"varint,4,opt,name=inp_prop_cpu_idx,json=inpPropCpuIdx" json:"inp_prop_cpu_idx,omitempty"`
	// for CPU TX packets with CPU injecting into a VRF
	GipoInpMapNatIdx []uint32 `protobuf:"varint,5,rep,packed,name=gipo_inp_map_nat_idx,json=gipoInpMapNatIdx" json:"gipo_inp_map_nat_idx,omitempty"`
	//  1. Inner IPv4, 2. Inner IPv6, 3. Inner MAC
	GipoInpMapTnlIdx []uint32 `protobuf:"varint,6,rep,packed,name=gipo_inp_map_tnl_idx,json=gipoInpMapTnlIdx" json:"gipo_inp_map_tnl_idx,omitempty"`
}

func (m *VrfStatusEpd) Reset()                    { *m = VrfStatusEpd{} }
func (m *VrfStatusEpd) String() string            { return proto.CompactTextString(m) }
func (*VrfStatusEpd) ProtoMessage()               {}
func (*VrfStatusEpd) Descriptor() ([]byte, []int) { return fileDescriptor40, []int{2} }

func (m *VrfStatusEpd) GetHwVrfId() uint32 {
	if m != nil {
		return m.HwVrfId
	}
	return 0
}

func (m *VrfStatusEpd) GetVrfLookupId() uint32 {
	if m != nil {
		return m.VrfLookupId
	}
	return 0
}

func (m *VrfStatusEpd) GetVrfVlanIdCpu() uint32 {
	if m != nil {
		return m.VrfVlanIdCpu
	}
	return 0
}

func (m *VrfStatusEpd) GetInpPropCpuIdx() uint32 {
	if m != nil {
		return m.InpPropCpuIdx
	}
	return 0
}

func (m *VrfStatusEpd) GetGipoInpMapNatIdx() []uint32 {
	if m != nil {
		return m.GipoInpMapNatIdx
	}
	return nil
}

func (m *VrfStatusEpd) GetGipoInpMapTnlIdx() []uint32 {
	if m != nil {
		return m.GipoInpMapTnlIdx
	}
	return nil
}

// Vrf oper state for cloud pipeline
type VrfStatusCpd struct {
}

func (m *VrfStatusCpd) Reset()                    { *m = VrfStatusCpd{} }
func (m *VrfStatusCpd) String() string            { return proto.CompactTextString(m) }
func (*VrfStatusCpd) ProtoMessage()               {}
func (*VrfStatusCpd) Descriptor() ([]byte, []int) { return fileDescriptor40, []int{3} }

// VrfStatus is the operational status of a given vrf
type VrfStatus struct {
	Meta        *delphi.ObjectMeta `protobuf:"bytes,1,opt,name=Meta" json:"Meta,omitempty"`
	KeyOrHandle *VrfKeyHandle      `protobuf:"bytes,2,opt,name=key_or_handle,json=keyOrHandle" json:"key_or_handle,omitempty"`
	// Types that are valid to be assigned to VrfPdStatus:
	//	*VrfStatus_EpdStatus
	//	*VrfStatus_CpdStatus
	VrfPdStatus isVrfStatus_VrfPdStatus `protobuf_oneof:"vrf_pd_status"`
}

func (m *VrfStatus) GetDelphiMessage() proto.Message {
	return m
}

func (m *VrfStatus) GetDelphiMeta() *delphi.ObjectMeta {
	return m.Meta
}

func (m *VrfStatus) SetDelphiMeta(meta *delphi.ObjectMeta) {
	m.Meta = meta
}

func (m *VrfStatus) GetDelphiKey() string {
	return m.KeyOrHandle.String()
}

func (m *VrfStatus) GetDelphiKind() string {
	return "VrfStatus"
}

func (m *VrfStatus) GetDelphiPath() string {
	return fmt.Sprintf("%s|%s", m.GetDelphiKind(), m.GetDelphiKey())
}

func (m *VrfStatus) DelphiClone() clientApi.BaseObject {
	obj, _ := proto.Clone(m).(*VrfStatus)
	return obj
}

func VrfStatusMount(client clientApi.Client, mode delphi.MountMode) {
	client.MountKind("VrfStatus", mode)
}

func VrfStatusMountKey(client clientApi.Client, key *VrfKeyHandle, mode delphi.MountMode) {
	client.MountKindKey("VrfStatus", key.String(), mode)
}

func GetVrfStatus(client clientApi.Client, key *VrfKeyHandle) *VrfStatus {
	o := client.GetObject("VrfStatus", key.String())
	if o == nil {
		return nil
	}
	obj, ok := o.(*VrfStatus)
	if ok != true {
		panic("Cast failed")
	}
	return obj
}

func VrfStatusFactory(sdkClient clientApi.Client, data []byte) (clientApi.BaseObject, error) {
	var msg VrfStatus
	err := proto.Unmarshal(data, &msg)
	if err != nil {
		return nil, err
	}
	return &msg, nil
}

func VrfStatusWatch(client clientApi.Client, reactor VrfStatusReactor) {
	client.WatchKind("VrfStatus", reactor)
}
func VrfStatusList(client clientApi.Client) []*VrfStatus {
	bobjs := client.List("VrfStatus")
	objs := make([]*VrfStatus, 0)
	for _, bobj := range bobjs {
		obj, _ := bobj.(*VrfStatus)
		objs = append(objs, obj)
	}
	return objs
}
func (m *VrfStatus) TriggerEvent(sdkClient clientApi.Client, old clientApi.BaseObject, op delphi.ObjectOperation, rl []clientApi.BaseReactor) {
	for _, r := range rl {
		rctr, ok := r.(VrfStatusReactor)
		if ok == false {
			panic("Not a Reactor")
		}
		if op == delphi.ObjectOperation_SetOp {
			if old == nil {
				rctr.OnVrfStatusCreate(m)
			} else {
				oldObj, ok := old.(*VrfStatus)
				if ok == false {
					panic("Not an VrfStatus object")
				}
				rctr.OnVrfStatusUpdate(oldObj, m)
			}
		} else {
			rctr.OnVrfStatusDelete(m)
		}
	}
}

type VrfStatusReactor interface {
	OnVrfStatusCreate(obj *VrfStatus)
	OnVrfStatusUpdate(old *VrfStatus, obj *VrfStatus)
	OnVrfStatusDelete(obj *VrfStatus)
}

func (m *VrfStatus) Reset()                    { *m = VrfStatus{} }
func (m *VrfStatus) String() string            { return proto.CompactTextString(m) }
func (*VrfStatus) ProtoMessage()               {}
func (*VrfStatus) Descriptor() ([]byte, []int) { return fileDescriptor40, []int{4} }

type isVrfStatus_VrfPdStatus interface{ isVrfStatus_VrfPdStatus() }

type VrfStatus_EpdStatus struct {
	EpdStatus *VrfStatusEpd `protobuf:"bytes,3,opt,name=epd_status,json=epdStatus,oneof"`
}
type VrfStatus_CpdStatus struct {
	CpdStatus *VrfStatusCpd `protobuf:"bytes,4,opt,name=cpd_status,json=cpdStatus,oneof"`
}

func (*VrfStatus_EpdStatus) isVrfStatus_VrfPdStatus() {}
func (*VrfStatus_CpdStatus) isVrfStatus_VrfPdStatus() {}

func (m *VrfStatus) GetVrfPdStatus() isVrfStatus_VrfPdStatus {
	if m != nil {
		return m.VrfPdStatus
	}
	return nil
}

func (m *VrfStatus) GetMeta() *delphi.ObjectMeta {
	if m != nil {
		return m.Meta
	}
	return nil
}

func (m *VrfStatus) GetKeyOrHandle() *VrfKeyHandle {
	if m != nil {
		return m.KeyOrHandle
	}
	return nil
}

func (m *VrfStatus) GetEpdStatus() *VrfStatusEpd {
	if x, ok := m.GetVrfPdStatus().(*VrfStatus_EpdStatus); ok {
		return x.EpdStatus
	}
	return nil
}

func (m *VrfStatus) GetCpdStatus() *VrfStatusCpd {
	if x, ok := m.GetVrfPdStatus().(*VrfStatus_CpdStatus); ok {
		return x.CpdStatus
	}
	return nil
}

// XXX_OneofFuncs is for the internal use of the proto package.
func (*VrfStatus) XXX_OneofFuncs() (func(msg proto.Message, b *proto.Buffer) error, func(msg proto.Message, tag, wire int, b *proto.Buffer) (bool, error), func(msg proto.Message) (n int), []interface{}) {
	return _VrfStatus_OneofMarshaler, _VrfStatus_OneofUnmarshaler, _VrfStatus_OneofSizer, []interface{}{
		(*VrfStatus_EpdStatus)(nil),
		(*VrfStatus_CpdStatus)(nil),
	}
}

func _VrfStatus_OneofMarshaler(msg proto.Message, b *proto.Buffer) error {
	m := msg.(*VrfStatus)
	// vrf_pd_status
	switch x := m.VrfPdStatus.(type) {
	case *VrfStatus_EpdStatus:
		b.EncodeVarint(3<<3 | proto.WireBytes)
		if err := b.EncodeMessage(x.EpdStatus); err != nil {
			return err
		}
	case *VrfStatus_CpdStatus:
		b.EncodeVarint(4<<3 | proto.WireBytes)
		if err := b.EncodeMessage(x.CpdStatus); err != nil {
			return err
		}
	case nil:
	default:
		return fmt.Errorf("VrfStatus.VrfPdStatus has unexpected type %T", x)
	}
	return nil
}

func _VrfStatus_OneofUnmarshaler(msg proto.Message, tag, wire int, b *proto.Buffer) (bool, error) {
	m := msg.(*VrfStatus)
	switch tag {
	case 3: // vrf_pd_status.epd_status
		if wire != proto.WireBytes {
			return true, proto.ErrInternalBadWireType
		}
		msg := new(VrfStatusEpd)
		err := b.DecodeMessage(msg)
		m.VrfPdStatus = &VrfStatus_EpdStatus{msg}
		return true, err
	case 4: // vrf_pd_status.cpd_status
		if wire != proto.WireBytes {
			return true, proto.ErrInternalBadWireType
		}
		msg := new(VrfStatusCpd)
		err := b.DecodeMessage(msg)
		m.VrfPdStatus = &VrfStatus_CpdStatus{msg}
		return true, err
	default:
		return false, nil
	}
}

func _VrfStatus_OneofSizer(msg proto.Message) (n int) {
	m := msg.(*VrfStatus)
	// vrf_pd_status
	switch x := m.VrfPdStatus.(type) {
	case *VrfStatus_EpdStatus:
		s := proto.Size(x.EpdStatus)
		n += proto.SizeVarint(3<<3 | proto.WireBytes)
		n += proto.SizeVarint(uint64(s))
		n += s
	case *VrfStatus_CpdStatus:
		s := proto.Size(x.CpdStatus)
		n += proto.SizeVarint(4<<3 | proto.WireBytes)
		n += proto.SizeVarint(uint64(s))
		n += s
	case nil:
	default:
		panic(fmt.Sprintf("proto: unexpected type %T in oneof", x))
	}
	return n
}

// VrfResponse is response to VrfSpec
type VrfResponse struct {
	ApiStatus ApiStatus  `protobuf:"varint,1,opt,name=api_status,json=apiStatus,enum=types.ApiStatus" json:"api_status,omitempty"`
	VrfStatus *VrfStatus `protobuf:"bytes,2,opt,name=vrf_status,json=vrfStatus" json:"vrf_status,omitempty"`
}

func (m *VrfResponse) Reset()                    { *m = VrfResponse{} }
func (m *VrfResponse) String() string            { return proto.CompactTextString(m) }
func (*VrfResponse) ProtoMessage()               {}
func (*VrfResponse) Descriptor() ([]byte, []int) { return fileDescriptor40, []int{5} }

func (m *VrfResponse) GetApiStatus() ApiStatus {
	if m != nil {
		return m.ApiStatus
	}
	return ApiStatus_API_STATUS_OK
}

func (m *VrfResponse) GetVrfStatus() *VrfStatus {
	if m != nil {
		return m.VrfStatus
	}
	return nil
}

// VrfResponseMsg is batched response to VrfRequestMsg
type VrfResponseMsg struct {
	Response []*VrfResponse `protobuf:"bytes,1,rep,name=response" json:"response,omitempty"`
}

func (m *VrfResponseMsg) Reset()                    { *m = VrfResponseMsg{} }
func (m *VrfResponseMsg) String() string            { return proto.CompactTextString(m) }
func (*VrfResponseMsg) ProtoMessage()               {}
func (*VrfResponseMsg) Descriptor() ([]byte, []int) { return fileDescriptor40, []int{6} }

func (m *VrfResponseMsg) GetResponse() []*VrfResponse {
	if m != nil {
		return m.Response
	}
	return nil
}

// VrfDeleteRequest is used to delete a vrf
type VrfDeleteRequest struct {
	// key_or_handle is vrf's unique identifier
	KeyOrHandle *VrfKeyHandle `protobuf:"bytes,1,opt,name=key_or_handle,json=keyOrHandle" json:"key_or_handle,omitempty"`
}

func (m *VrfDeleteRequest) Reset()                    { *m = VrfDeleteRequest{} }
func (m *VrfDeleteRequest) String() string            { return proto.CompactTextString(m) }
func (*VrfDeleteRequest) ProtoMessage()               {}
func (*VrfDeleteRequest) Descriptor() ([]byte, []int) { return fileDescriptor40, []int{7} }

func (m *VrfDeleteRequest) GetKeyOrHandle() *VrfKeyHandle {
	if m != nil {
		return m.KeyOrHandle
	}
	return nil
}

// VrfDeleteResponse is response to VrfDeleteRequest
type VrfDeleteResponse struct {
	ApiStatus   ApiStatus     `protobuf:"varint,1,opt,name=api_status,json=apiStatus,enum=types.ApiStatus" json:"api_status,omitempty"`
	KeyOrHandle *VrfKeyHandle `protobuf:"bytes,2,opt,name=key_or_handle,json=keyOrHandle" json:"key_or_handle,omitempty"`
}

func (m *VrfDeleteResponse) Reset()                    { *m = VrfDeleteResponse{} }
func (m *VrfDeleteResponse) String() string            { return proto.CompactTextString(m) }
func (*VrfDeleteResponse) ProtoMessage()               {}
func (*VrfDeleteResponse) Descriptor() ([]byte, []int) { return fileDescriptor40, []int{8} }

func (m *VrfDeleteResponse) GetApiStatus() ApiStatus {
	if m != nil {
		return m.ApiStatus
	}
	return ApiStatus_API_STATUS_OK
}

func (m *VrfDeleteResponse) GetKeyOrHandle() *VrfKeyHandle {
	if m != nil {
		return m.KeyOrHandle
	}
	return nil
}

// VrfDeleteRequestMsg is used to delete a batch of vrfs
type VrfDeleteRequestMsg struct {
	Request []*VrfDeleteRequest `protobuf:"bytes,1,rep,name=request" json:"request,omitempty"`
}

func (m *VrfDeleteRequestMsg) Reset()                    { *m = VrfDeleteRequestMsg{} }
func (m *VrfDeleteRequestMsg) String() string            { return proto.CompactTextString(m) }
func (*VrfDeleteRequestMsg) ProtoMessage()               {}
func (*VrfDeleteRequestMsg) Descriptor() ([]byte, []int) { return fileDescriptor40, []int{9} }

func (m *VrfDeleteRequestMsg) GetRequest() []*VrfDeleteRequest {
	if m != nil {
		return m.Request
	}
	return nil
}

// VrfDeleteResponseMsg is batched response to VrfDeleteRequestMsg
type VrfDeleteResponseMsg struct {
	Response []*VrfDeleteResponse `protobuf:"bytes,1,rep,name=response" json:"response,omitempty"`
}

func (m *VrfDeleteResponseMsg) Reset()                    { *m = VrfDeleteResponseMsg{} }
func (m *VrfDeleteResponseMsg) String() string            { return proto.CompactTextString(m) }
func (*VrfDeleteResponseMsg) ProtoMessage()               {}
func (*VrfDeleteResponseMsg) Descriptor() ([]byte, []int) { return fileDescriptor40, []int{10} }

func (m *VrfDeleteResponseMsg) GetResponse() []*VrfDeleteResponse {
	if m != nil {
		return m.Response
	}
	return nil
}

// VrfGetRequest is used to get information about a vrf
type VrfGetRequest struct {
	KeyOrHandle *VrfKeyHandle `protobuf:"bytes,1,opt,name=key_or_handle,json=keyOrHandle" json:"key_or_handle,omitempty"`
}

func (m *VrfGetRequest) Reset()                    { *m = VrfGetRequest{} }
func (m *VrfGetRequest) String() string            { return proto.CompactTextString(m) }
func (*VrfGetRequest) ProtoMessage()               {}
func (*VrfGetRequest) Descriptor() ([]byte, []int) { return fileDescriptor40, []int{11} }

func (m *VrfGetRequest) GetKeyOrHandle() *VrfKeyHandle {
	if m != nil {
		return m.KeyOrHandle
	}
	return nil
}

// VrfGetRequestMsg is batched GET requests for vrfs
type VrfGetRequestMsg struct {
	Request []*VrfGetRequest `protobuf:"bytes,1,rep,name=request" json:"request,omitempty"`
}

func (m *VrfGetRequestMsg) Reset()                    { *m = VrfGetRequestMsg{} }
func (m *VrfGetRequestMsg) String() string            { return proto.CompactTextString(m) }
func (*VrfGetRequestMsg) ProtoMessage()               {}
func (*VrfGetRequestMsg) Descriptor() ([]byte, []int) { return fileDescriptor40, []int{12} }

func (m *VrfGetRequestMsg) GetRequest() []*VrfGetRequest {
	if m != nil {
		return m.Request
	}
	return nil
}

// VrfStats is the statistics object for each vrf
type VrfStats struct {
	NumL2Segments     uint32 `protobuf:"varint,1,opt,name=num_l2_segments,json=numL2Segments" json:"num_l2_segments,omitempty"`
	NumSecurityGroups uint32 `protobuf:"varint,2,opt,name=num_security_groups,json=numSecurityGroups" json:"num_security_groups,omitempty"`
	NumL4LbServices   uint32 `protobuf:"varint,3,opt,name=num_l4lb_services,json=numL4lbServices" json:"num_l4lb_services,omitempty"`
	NumEndpoints      uint32 `protobuf:"varint,4,opt,name=num_endpoints,json=numEndpoints" json:"num_endpoints,omitempty"`
	NumAcls           uint32 `protobuf:"varint,5,opt,name=num_acls,json=numAcls" json:"num_acls,omitempty"`
}

func (m *VrfStats) Reset()                    { *m = VrfStats{} }
func (m *VrfStats) String() string            { return proto.CompactTextString(m) }
func (*VrfStats) ProtoMessage()               {}
func (*VrfStats) Descriptor() ([]byte, []int) { return fileDescriptor40, []int{13} }

func (m *VrfStats) GetNumL2Segments() uint32 {
	if m != nil {
		return m.NumL2Segments
	}
	return 0
}

func (m *VrfStats) GetNumSecurityGroups() uint32 {
	if m != nil {
		return m.NumSecurityGroups
	}
	return 0
}

func (m *VrfStats) GetNumL4LbServices() uint32 {
	if m != nil {
		return m.NumL4LbServices
	}
	return 0
}

func (m *VrfStats) GetNumEndpoints() uint32 {
	if m != nil {
		return m.NumEndpoints
	}
	return 0
}

func (m *VrfStats) GetNumAcls() uint32 {
	if m != nil {
		return m.NumAcls
	}
	return 0
}

// VrfGetResponse captures all the information about a vrf
// only if api_status indicates success, other fields are valid
type VrfGetResponse struct {
	ApiStatus ApiStatus  `protobuf:"varint,1,opt,name=api_status,json=apiStatus,enum=types.ApiStatus" json:"api_status,omitempty"`
	Spec      *VrfSpec   `protobuf:"bytes,2,opt,name=spec" json:"spec,omitempty"`
	Status    *VrfStatus `protobuf:"bytes,3,opt,name=status" json:"status,omitempty"`
	Stats     *VrfStats  `protobuf:"bytes,4,opt,name=stats" json:"stats,omitempty"`
}

func (m *VrfGetResponse) Reset()                    { *m = VrfGetResponse{} }
func (m *VrfGetResponse) String() string            { return proto.CompactTextString(m) }
func (*VrfGetResponse) ProtoMessage()               {}
func (*VrfGetResponse) Descriptor() ([]byte, []int) { return fileDescriptor40, []int{14} }

func (m *VrfGetResponse) GetApiStatus() ApiStatus {
	if m != nil {
		return m.ApiStatus
	}
	return ApiStatus_API_STATUS_OK
}

func (m *VrfGetResponse) GetSpec() *VrfSpec {
	if m != nil {
		return m.Spec
	}
	return nil
}

func (m *VrfGetResponse) GetStatus() *VrfStatus {
	if m != nil {
		return m.Status
	}
	return nil
}

func (m *VrfGetResponse) GetStats() *VrfStats {
	if m != nil {
		return m.Stats
	}
	return nil
}

// VrfGetResponseMsg is batched response to VrfGetRequestMsg
type VrfGetResponseMsg struct {
	Response []*VrfGetResponse `protobuf:"bytes,1,rep,name=response" json:"response,omitempty"`
}

func (m *VrfGetResponseMsg) Reset()                    { *m = VrfGetResponseMsg{} }
func (m *VrfGetResponseMsg) String() string            { return proto.CompactTextString(m) }
func (*VrfGetResponseMsg) ProtoMessage()               {}
func (*VrfGetResponseMsg) Descriptor() ([]byte, []int) { return fileDescriptor40, []int{15} }

func (m *VrfGetResponseMsg) GetResponse() []*VrfGetResponse {
	if m != nil {
		return m.Response
	}
	return nil
}

func init() {
	clientApi.RegisterFactory("VrfSpec", VrfSpecFactory)
	proto.RegisterType((*VrfSpec)(nil), "halproto.VrfSpec")
	proto.RegisterType((*VrfRequestMsg)(nil), "halproto.VrfRequestMsg")
	proto.RegisterType((*VrfStatusEpd)(nil), "halproto.VrfStatusEpd")
	proto.RegisterType((*VrfStatusCpd)(nil), "halproto.VrfStatusCpd")
	clientApi.RegisterFactory("VrfStatus", VrfStatusFactory)
	proto.RegisterType((*VrfStatus)(nil), "halproto.VrfStatus")
	proto.RegisterType((*VrfResponse)(nil), "halproto.VrfResponse")
	proto.RegisterType((*VrfResponseMsg)(nil), "halproto.VrfResponseMsg")
	proto.RegisterType((*VrfDeleteRequest)(nil), "halproto.VrfDeleteRequest")
	proto.RegisterType((*VrfDeleteResponse)(nil), "halproto.VrfDeleteResponse")
	proto.RegisterType((*VrfDeleteRequestMsg)(nil), "halproto.VrfDeleteRequestMsg")
	proto.RegisterType((*VrfDeleteResponseMsg)(nil), "halproto.VrfDeleteResponseMsg")
	proto.RegisterType((*VrfGetRequest)(nil), "halproto.VrfGetRequest")
	proto.RegisterType((*VrfGetRequestMsg)(nil), "halproto.VrfGetRequestMsg")
	proto.RegisterType((*VrfStats)(nil), "halproto.VrfStats")
	proto.RegisterType((*VrfGetResponse)(nil), "halproto.VrfGetResponse")
	proto.RegisterType((*VrfGetResponseMsg)(nil), "halproto.VrfGetResponseMsg")
}

func init() { proto.RegisterFile("vrf.proto", fileDescriptor40) }

var fileDescriptor40 = []byte{
	// 1027 bytes of a gzipped FileDescriptorProto
	0x1f, 0x8b, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xff, 0xbc, 0x56, 0x4b, 0x6f, 0xe3, 0x54,
	0x14, 0x1e, 0x4f, 0xda, 0x26, 0x3d, 0x89, 0xd3, 0xe4, 0x66, 0x3a, 0xca, 0x54, 0x48, 0x0d, 0x1e,
	0x4d, 0xa9, 0x60, 0x08, 0x28, 0x54, 0x20, 0x66, 0x81, 0x68, 0xd2, 0x79, 0x04, 0x5a, 0x26, 0x72,
	0x67, 0x22, 0x84, 0x90, 0x2c, 0xc7, 0xbe, 0x4e, 0x4c, 0xfc, 0xb8, 0xdc, 0x6b, 0x67, 0x9a, 0x1d,
	0x0b, 0x96, 0x6c, 0x58, 0xf1, 0x93, 0xd8, 0xf1, 0x13, 0xfa, 0x23, 0x2a, 0x16, 0xac, 0x10, 0xba,
	0x0f, 0xe7, 0xbd, 0x00, 0x54, 0xcd, 0x2a, 0xf6, 0x39, 0xdf, 0xf9, 0x7c, 0xcf, 0x39, 0xdf, 0x39,
	0x37, 0xb0, 0x3b, 0xa1, 0x5e, 0x93, 0xd0, 0x38, 0x89, 0x51, 0x6e, 0x42, 0xbd, 0x83, 0x62, 0x32,
	0x25, 0x98, 0x49, 0xcb, 0x41, 0x61, 0x3c, 0x52, 0x4f, 0x25, 0x17, 0x07, 0x64, 0xe4, 0xcb, 0x37,
	0xe3, 0x97, 0x1c, 0xe4, 0xfb, 0xd4, 0xbb, 0x24, 0xd8, 0x41, 0x47, 0xb0, 0x75, 0x81, 0x13, 0xbb,
	0xae, 0x35, 0xb4, 0xe3, 0x62, 0x0b, 0x35, 0x15, 0xf0, 0xe5, 0xe0, 0x07, 0xec, 0x24, 0xdc, 0x63,
	0x0a, 0x3f, 0x3a, 0x03, 0x7d, 0x8c, 0xa7, 0x56, 0x4c, 0xad, 0x91, 0x1d, 0xb9, 0x01, 0xae, 0xdf,
	0x15, 0x01, 0x95, 0xe6, 0x78, 0xd4, 0xec, 0x53, 0xef, 0x6b, 0x3c, 0x7d, 0x21, 0xec, 0xed, 0xf2,
	0xcd, 0xf5, 0x21, 0x4c, 0x70, 0xe4, 0x3b, 0xf8, 0xc9, 0x18, 0x4f, 0xcd, 0xe2, 0x18, 0x4f, 0x5f,
	0x52, 0xe9, 0x44, 0xdf, 0x43, 0x8d, 0x61, 0x27, 0xa5, 0x7e, 0x32, 0xb5, 0x38, 0x9d, 0xe2, 0xca,
	0x09, 0xae, 0x77, 0x38, 0xd7, 0xa5, 0x72, 0xf7, 0x68, 0xec, 0xf9, 0x01, 0xde, 0xcc, 0x4b, 0xb1,
	0x67, 0x56, 0x33, 0xa2, 0x19, 0x04, 0xf5, 0xa0, 0x30, 0xa1, 0x9e, 0xc5, 0x4b, 0x50, 0xdf, 0x6a,
	0x68, 0xc7, 0xe5, 0x56, 0xb9, 0x29, 0xeb, 0xd1, 0xa7, 0xde, 0xab, 0x29, 0xc1, 0xed, 0x47, 0x37,
	0xd7, 0x87, 0xef, 0x2a, 0x12, 0x3f, 0x0c, 0xd3, 0xc4, 0x1e, 0x04, 0xf8, 0xb1, 0x32, 0x84, 0x76,
	0xe4, 0xda, 0x49, 0x4c, 0xa7, 0x66, 0x7e, 0x22, 0xf1, 0xe8, 0x03, 0x28, 0x84, 0xd3, 0x04, 0x13,
	0xcb, 0x27, 0xf5, 0x6d, 0x95, 0xb0, 0x64, 0xec, 0xf6, 0x4e, 0x5d, 0x97, 0x62, 0xc6, 0xcc, 0xbc,
	0x40, 0x74, 0x09, 0xfa, 0x18, 0x8a, 0x43, 0x9f, 0xc4, 0x16, 0xa1, 0xd8, 0xf3, 0xaf, 0xea, 0x3b,
	0x02, 0xbf, 0x37, 0xc3, 0xf7, 0x84, 0xd9, 0x04, 0x8e, 0x91, 0xcf, 0x4f, 0xb6, 0x7e, 0xfa, 0xcd,
	0xd0, 0x8c, 0xcf, 0x40, 0xef, 0x53, 0xcf, 0xc4, 0x3f, 0xa6, 0x98, 0x25, 0x17, 0x6c, 0x88, 0x8e,
	0x20, 0x4f, 0xe5, 0x5b, 0x5d, 0x6b, 0xe4, 0x8e, 0x8b, 0xad, 0x52, 0x93, 0xb7, 0x59, 0xb5, 0xcc,
	0xcc, 0x9c, 0xc6, 0xdf, 0x1a, 0x94, 0xb8, 0x31, 0xb1, 0x93, 0x94, 0x3d, 0x25, 0x2e, 0x3a, 0x80,
	0xdd, 0xd1, 0x1b, 0x8b, 0xd7, 0xc0, 0x77, 0x45, 0x47, 0x75, 0x33, 0x3f, 0x7a, 0xd3, 0xa7, 0x5e,
	0xd7, 0x45, 0x06, 0xe8, 0xdc, 0x11, 0xc4, 0xf1, 0x38, 0x25, 0xdc, 0x7f, 0x57, 0xf8, 0x8b, 0x13,
	0xea, 0x9d, 0x0b, 0x5b, 0xd7, 0x45, 0x8f, 0x60, 0x8f, 0x63, 0x26, 0x81, 0x1d, 0x59, 0xbe, 0x6b,
	0x39, 0x24, 0x15, 0xad, 0xd1, 0xcd, 0xd2, 0x84, 0x7a, 0xfd, 0xc0, 0x8e, 0xba, 0x6e, 0x87, 0xa4,
	0xe8, 0x3d, 0xa8, 0xf8, 0x11, 0xb1, 0x08, 0x8d, 0x09, 0xc7, 0x58, 0xbe, 0x7b, 0x25, 0xea, 0xad,
	0x9b, 0xba, 0x1f, 0x91, 0x1e, 0x8d, 0x49, 0x87, 0xa4, 0x5d, 0xf7, 0x0a, 0x35, 0xe1, 0x9e, 0xa8,
	0x08, 0x47, 0x87, 0x36, 0xb1, 0x22, 0x3b, 0x11, 0xe0, 0xed, 0x46, 0xee, 0x58, 0x37, 0x2b, 0xdc,
	0xd7, 0x8d, 0xc8, 0x85, 0x4d, 0xbe, 0xb1, 0x93, 0x4d, 0xf8, 0x24, 0x0a, 0x04, 0x7e, 0x67, 0x15,
	0xff, 0x2a, 0x0a, 0xba, 0xee, 0x95, 0x51, 0x5e, 0xc8, 0xbf, 0x43, 0x5c, 0xe3, 0x2f, 0x0d, 0x76,
	0x67, 0x86, 0xb7, 0x2c, 0xed, 0x16, 0x00, 0x26, 0xae, 0xc5, 0xc4, 0xb7, 0x95, 0xa2, 0xab, 0xb3,
	0xbe, 0x65, 0x2d, 0x7a, 0x71, 0xc7, 0xdc, 0xc5, 0xc4, 0x55, 0x27, 0x6c, 0x01, 0x38, 0xf3, 0x98,
	0xad, 0x4d, 0x31, 0x1d, 0x19, 0xe3, 0x64, 0x31, 0x52, 0x33, 0xed, 0x3d, 0xd9, 0xcd, 0x59, 0xb0,
	0xf1, 0xb3, 0x06, 0x45, 0xa1, 0x22, 0x46, 0xe2, 0x88, 0x61, 0xf4, 0x0c, 0xc0, 0x26, 0x7e, 0x46,
	0xad, 0x89, 0x69, 0xc8, 0xb4, 0x7b, 0x4a, 0x7c, 0x49, 0xd6, 0xde, 0xbf, 0xb9, 0x3e, 0xac, 0xaa,
	0x8c, 0xe6, 0x70, 0x73, 0xd7, 0xce, 0x10, 0xe8, 0x43, 0x00, 0xfe, 0x21, 0xc5, 0x23, 0x2b, 0x53,
	0x5e, 0x3e, 0xa2, 0xc9, 0x97, 0x90, 0x7c, 0x34, 0xbe, 0x80, 0xf2, 0xc2, 0x29, 0xb8, 0x98, 0x1f,
	0x43, 0x81, 0xaa, 0x57, 0xa5, 0xe6, 0x4a, 0x16, 0x9e, 0xc1, 0xcc, 0x19, 0xc2, 0xf8, 0x16, 0x2a,
	0x7d, 0xea, 0x9d, 0xe1, 0x00, 0x27, 0x58, 0x4d, 0xc4, 0x7a, 0x7f, 0xb4, 0xff, 0xd1, 0x1f, 0xe3,
	0x57, 0x0d, 0xaa, 0x0b, 0xd4, 0xb7, 0x5c, 0xa6, 0x93, 0x7f, 0xa9, 0xa1, 0xe5, 0x33, 0x3d, 0x83,
	0xda, 0x6a, 0xb6, 0xbc, 0x64, 0x1f, 0xad, 0xce, 0xff, 0x7e, 0x56, 0xb1, 0x25, 0xe8, 0x7c, 0x11,
	0x7c, 0x05, 0xf7, 0xd6, 0x52, 0xe3, 0x44, 0xad, 0xb5, 0xda, 0xdf, 0x5f, 0x65, 0x5a, 0xeb, 0xc0,
	0x6b, 0xb1, 0x8d, 0x9e, 0xe3, 0xe4, 0x76, 0xcb, 0xff, 0xa5, 0x68, 0xec, 0x9c, 0x56, 0x4a, 0x63,
	0x25, 0x4f, 0x94, 0x9d, 0x6e, 0x8e, 0x9b, 0x27, 0xf9, 0x87, 0x06, 0x05, 0xa5, 0x39, 0x3e, 0xdb,
	0x7b, 0x51, 0x1a, 0x5a, 0x41, 0xcb, 0x62, 0x78, 0x18, 0xe2, 0x28, 0x61, 0x6a, 0xdf, 0xe9, 0x51,
	0x1a, 0x9e, 0xb7, 0x2e, 0x95, 0x11, 0x35, 0xa1, 0xc6, 0x71, 0xb3, 0x4b, 0x67, 0x48, 0xe3, 0x94,
	0x30, 0xb5, 0xfb, 0xaa, 0x51, 0x1a, 0x66, 0xf7, 0xcd, 0x73, 0xe1, 0x40, 0xef, 0x43, 0x55, 0xf0,
	0x9e, 0x04, 0x03, 0x8b, 0x61, 0x3a, 0xf1, 0x1d, 0xcc, 0xd4, 0x0e, 0xe4, 0x1f, 0x3c, 0x3f, 0x09,
	0x06, 0x97, 0xca, 0x8c, 0x1e, 0x02, 0xff, 0x98, 0x85, 0x23, 0x97, 0xc4, 0x3e, 0x3f, 0x81, 0xdc,
	0x81, 0xa5, 0x28, 0x0d, 0x9f, 0x66, 0x36, 0xf4, 0x00, 0x0a, 0x1c, 0x64, 0x3b, 0x01, 0x13, 0x37,
	0x88, 0x6e, 0xe6, 0xa3, 0x34, 0x3c, 0x75, 0x02, 0x66, 0xfc, 0xae, 0x89, 0x61, 0x11, 0xb9, 0xde,
	0xb2, 0x1c, 0x1b, 0xb0, 0xc5, 0x08, 0x76, 0x94, 0x0a, 0x97, 0xaf, 0x0f, 0xe1, 0x41, 0x47, 0xb0,
	0xb3, 0xb4, 0xaa, 0x56, 0x67, 0x5a, 0x79, 0xd1, 0x43, 0xd8, 0xe6, 0x4f, 0xd9, 0x76, 0xd2, 0x17,
	0x61, 0xcc, 0x94, 0x3e, 0xe3, 0x4c, 0x8c, 0xd6, 0x42, 0x22, 0x52, 0xc5, 0xab, 0xe2, 0xab, 0x2d,
	0xb5, 0x77, 0x55, 0x79, 0xad, 0x3f, 0x35, 0xc8, 0xf5, 0xa9, 0x87, 0x3e, 0x15, 0x4b, 0xbc, 0x43,
	0xb1, 0x9d, 0x60, 0x84, 0xe6, 0xcb, 0x22, 0xd3, 0xcd, 0x41, 0x6d, 0x75, 0x81, 0x5c, 0xb0, 0xa1,
	0x71, 0x47, 0xc5, 0xbd, 0x26, 0xee, 0x7f, 0x8c, 0x6b, 0x8b, 0x38, 0x39, 0x10, 0xa8, 0xbe, 0x71,
	0xd4, 0x78, 0xf4, 0x83, 0xcd, 0xa3, 0x23, 0x39, 0x3e, 0x87, 0x1d, 0x99, 0x17, 0xda, 0x5f, 0xd7,
	0x30, 0x8f, 0xbe, 0xbf, 0x21, 0x77, 0x11, 0xda, 0x86, 0xef, 0x0a, 0x23, 0x3b, 0x10, 0xff, 0xcc,
	0x06, 0x3b, 0xe2, 0xe7, 0x93, 0x7f, 0x02, 0x00, 0x00, 0xff, 0xff, 0x31, 0xec, 0xea, 0xc0, 0xd7,
	0x09, 0x00, 0x00,
}
