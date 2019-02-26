// Code generated by protoc-gen-go. DO NOT EDIT.
// source: hal.proto

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

// ------------------------------------------------------------------------------
// HalStatus captures various states it is goes through while the system is
// coming up or going down (e.g., during upgrade)
// ------------------------------------------------------------------------------
type HalState int32

const (
	HalState_HAL_STATE_NONE                    HalState = 0
	HalState_HAL_STATE_ASIC_INIT_DONE          HalState = 1
	HalState_HAL_STATE_MEM_INIT_DONE           HalState = 2
	HalState_HAL_STATE_PACKET_BUFFER_INIT_DONE HalState = 3
	HalState_HAL_STATE_DATA_PLANE_INIT_DONE    HalState = 4
	HalState_HAL_STATE_SCHEDULER_INIT_DONE     HalState = 5
	HalState_HAL_STATE_INIT_ERR                HalState = 6
	HalState_HAL_STATE_UP                      HalState = 7
)

var HalState_name = map[int32]string{
	0: "HAL_STATE_NONE",
	1: "HAL_STATE_ASIC_INIT_DONE",
	2: "HAL_STATE_MEM_INIT_DONE",
	3: "HAL_STATE_PACKET_BUFFER_INIT_DONE",
	4: "HAL_STATE_DATA_PLANE_INIT_DONE",
	5: "HAL_STATE_SCHEDULER_INIT_DONE",
	6: "HAL_STATE_INIT_ERR",
	7: "HAL_STATE_UP",
}
var HalState_value = map[string]int32{
	"HAL_STATE_NONE":                    0,
	"HAL_STATE_ASIC_INIT_DONE":          1,
	"HAL_STATE_MEM_INIT_DONE":           2,
	"HAL_STATE_PACKET_BUFFER_INIT_DONE": 3,
	"HAL_STATE_DATA_PLANE_INIT_DONE":    4,
	"HAL_STATE_SCHEDULER_INIT_DONE":     5,
	"HAL_STATE_INIT_ERR":                6,
	"HAL_STATE_UP":                      7,
}

func (x HalState) String() string {
	return proto.EnumName(HalState_name, int32(x))
}
func (HalState) EnumDescriptor() ([]byte, []int) { return fileDescriptor10, []int{0} }

type HalStatus struct {
	Meta  *delphi.ObjectMeta `protobuf:"bytes,1,opt,name=Meta" json:"Meta,omitempty"`
	State HalState           `protobuf:"varint,2,opt,name=state,enum=hal.HalState" json:"state,omitempty"`
}

func (m *HalStatus) GetDelphiMessage() proto.Message {
	return m
}

func (m *HalStatus) GetDelphiMeta() *delphi.ObjectMeta {
	return m.Meta
}

func (m *HalStatus) SetDelphiMeta(meta *delphi.ObjectMeta) {
	m.Meta = meta
}

func (m *HalStatus) GetDelphiKey() string {
	return "default"
}

func (m *HalStatus) GetDelphiKind() string {
	return "HalStatus"
}

func (m *HalStatus) GetDelphiPath() string {
	return fmt.Sprintf("%s|%s", m.GetDelphiKind(), m.GetDelphiKey())
}

func (m *HalStatus) DelphiClone() clientApi.BaseObject {
	obj, _ := proto.Clone(m).(*HalStatus)
	return obj
}

func HalStatusMount(client clientApi.Client, mode delphi.MountMode) {
	client.MountKind("HalStatus", mode)
}

func GetHalStatus(client clientApi.Client) *HalStatus {
	o := client.GetObject("HalStatus", "default")
	if o == nil {
		return nil
	}
	obj, ok := o.(*HalStatus)
	if ok != true {
		panic("Cast failed")
	}
	return obj
}

func HalStatusFactory(sdkClient clientApi.Client, data []byte) (clientApi.BaseObject, error) {
	var msg HalStatus
	err := proto.Unmarshal(data, &msg)
	if err != nil {
		return nil, err
	}
	return &msg, nil
}

func HalStatusWatch(client clientApi.Client, reactor HalStatusReactor) {
	client.WatchKind("HalStatus", reactor)
}
func HalStatusList(client clientApi.Client) []*HalStatus {
	bobjs := client.List("HalStatus")
	objs := make([]*HalStatus, 0)
	for _, bobj := range bobjs {
		obj, _ := bobj.(*HalStatus)
		objs = append(objs, obj)
	}
	return objs
}
func (m *HalStatus) TriggerEvent(sdkClient clientApi.Client, old clientApi.BaseObject, op delphi.ObjectOperation, rl []clientApi.BaseReactor) {
	for _, r := range rl {
		rctr, ok := r.(HalStatusReactor)
		if ok == false {
			panic("Not a Reactor")
		}
		if op == delphi.ObjectOperation_SetOp {
			if old == nil {
				rctr.OnHalStatusCreate(m)
			} else {
				oldObj, ok := old.(*HalStatus)
				if ok == false {
					panic("Not an HalStatus object")
				}
				rctr.OnHalStatusUpdate(oldObj, m)
			}
		} else {
			rctr.OnHalStatusDelete(m)
		}
	}
}

type HalStatusReactor interface {
	OnHalStatusCreate(obj *HalStatus)
	OnHalStatusUpdate(old *HalStatus, obj *HalStatus)
	OnHalStatusDelete(obj *HalStatus)
}

func (m *HalStatus) Reset()                    { *m = HalStatus{} }
func (m *HalStatus) String() string            { return proto.CompactTextString(m) }
func (*HalStatus) ProtoMessage()               {}
func (*HalStatus) Descriptor() ([]byte, []int) { return fileDescriptor10, []int{0} }

func (m *HalStatus) GetMeta() *delphi.ObjectMeta {
	if m != nil {
		return m.Meta
	}
	return nil
}

func (m *HalStatus) GetState() HalState {
	if m != nil {
		return m.State
	}
	return HalState_HAL_STATE_NONE
}

func init() {
	clientApi.RegisterFactory("HalStatus", HalStatusFactory)
	proto.RegisterType((*HalStatus)(nil), "hal.HalStatus")
	proto.RegisterEnum("hal.HalState", HalState_name, HalState_value)
}

func init() { proto.RegisterFile("hal.proto", fileDescriptor10) }

var fileDescriptor10 = []byte{
	// 271 bytes of a gzipped FileDescriptorProto
	0x1f, 0x8b, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xff, 0x54, 0xd0, 0xcb, 0x4a, 0xfb, 0x40,
	0x14, 0xc7, 0xf1, 0xff, 0xf4, 0xf6, 0x6f, 0x8f, 0xb5, 0x84, 0xb3, 0xd0, 0xe0, 0x8d, 0x36, 0xa2,
	0x14, 0x17, 0x59, 0xd4, 0x9d, 0xbb, 0x31, 0x99, 0x92, 0x60, 0x92, 0x86, 0x5c, 0xd6, 0xc3, 0x44,
	0x07, 0xa2, 0x04, 0x5a, 0xec, 0xb8, 0x77, 0xe9, 0x1b, 0xf4, 0x39, 0x7d, 0x03, 0x49, 0x5a, 0x99,
	0xb8, 0xfd, 0x7d, 0xbe, 0x9c, 0x81, 0x81, 0x51, 0x29, 0x2a, 0x7b, 0xf3, 0xbe, 0x56, 0x6b, 0xec,
	0x96, 0xa2, 0x3a, 0x1b, 0xbf, 0xc8, 0x6a, 0x53, 0xbe, 0xee, 0x27, 0xab, 0x80, 0x91, 0x27, 0xaa,
	0x54, 0x09, 0xf5, 0xb1, 0xc5, 0x5b, 0xe8, 0x85, 0x52, 0x09, 0x93, 0x4c, 0xc9, 0xfc, 0x68, 0x81,
	0xf6, 0xa1, 0x5c, 0x15, 0x6f, 0xf2, 0x59, 0xd5, 0x92, 0x34, 0x8e, 0xd7, 0xd0, 0xdf, 0x2a, 0xa1,
	0xa4, 0xd9, 0x99, 0x92, 0xf9, 0x64, 0x71, 0x6c, 0xd7, 0x4f, 0x1c, 0xce, 0xc8, 0x64, 0x6f, 0x0f,
	0xc3, 0xcf, 0x9d, 0x45, 0xbe, 0x76, 0x16, 0xb9, 0xfb, 0x26, 0x30, 0xfc, 0x55, 0x44, 0x98, 0x78,
	0x34, 0xe0, 0x69, 0x46, 0x33, 0xc6, 0xa3, 0x55, 0xc4, 0x8c, 0x7f, 0x78, 0x01, 0xa6, 0xde, 0x68,
	0xea, 0x3b, 0xdc, 0x8f, 0xfc, 0x8c, 0xbb, 0xb5, 0x12, 0x3c, 0x87, 0x53, 0xad, 0x21, 0x0b, 0x5b,
	0xd8, 0xc1, 0x1b, 0x98, 0x69, 0x8c, 0xa9, 0xf3, 0xc4, 0x32, 0xfe, 0x98, 0x2f, 0x97, 0x2c, 0x69,
	0x65, 0x5d, 0xb4, 0xe0, 0x4a, 0x67, 0x2e, 0xcd, 0x28, 0x8f, 0x03, 0x1a, 0xb1, 0x56, 0xd3, 0xc3,
	0x19, 0x5c, 0xea, 0x26, 0x75, 0x3c, 0xe6, 0xe6, 0xc1, 0x9f, 0x33, 0x7d, 0x3c, 0x01, 0xd4, 0x49,
	0x03, 0x2c, 0x49, 0x8c, 0x01, 0x1a, 0x30, 0xd6, 0x7b, 0x1e, 0x1b, 0xff, 0x8b, 0x41, 0xf3, 0xbd,
	0xf7, 0x3f, 0x01, 0x00, 0x00, 0xff, 0xff, 0x2d, 0xce, 0x18, 0xad, 0x7e, 0x01, 0x00, 0x00,
}
