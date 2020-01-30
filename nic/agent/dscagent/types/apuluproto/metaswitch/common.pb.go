// Code generated by protoc-gen-gogo. DO NOT EDIT.
// source: common.proto

/*
Package pds is a generated protocol buffer package.

It is generated from these files:
	common.proto
	cp_route.proto

It has these top-level messages:
	CPRouteSpec
	CPRouteSpecRequest
	CPRouteResponse
	CPRouteSpecResponse
	CPStaticRouteSpec
	CPStaticRouteRequest
	CPStaticRouteResponse
*/
package pds

import proto "github.com/gogo/protobuf/proto"
import fmt "fmt"
import math "math"

// Reference imports to suppress errors if they are not otherwise used.
var _ = proto.Marshal
var _ = fmt.Errorf
var _ = math.Inf

// This is a compile-time assertion to ensure that this generated file
// is compatible with the proto package it is being compiled against.
// A compilation error at this line likely means your copy of the
// proto package needs to be updated.
const _ = proto.GoGoProtoPackageIsVersion2 // please upgrade the proto package

// Admin Status
type AdminSt int32

const (
	AdminSt_ADMIN_NONE AdminSt = 0
	AdminSt_ADMIN_UP   AdminSt = 1
	AdminSt_ADMIN_DOWN AdminSt = 2
)

var AdminSt_name = map[int32]string{
	0: "ADMIN_NONE",
	1: "ADMIN_UP",
	2: "ADMIN_DOWN",
}
var AdminSt_value = map[string]int32{
	"ADMIN_NONE": 0,
	"ADMIN_UP":   1,
	"ADMIN_DOWN": 2,
}

func (x AdminSt) String() string {
	return proto.EnumName(AdminSt_name, int32(x))
}
func (AdminSt) EnumDescriptor() ([]byte, []int) { return fileDescriptorCommon, []int{0} }

// AMB Bool
type AMBBool int32

const (
	AMBBool_BOOL_NONE  AMBBool = 0
	AMBBool_BOOL_TRUE  AMBBool = 1
	AMBBool_BOOL_FALSE AMBBool = 2
)

var AMBBool_name = map[int32]string{
	0: "BOOL_NONE",
	1: "BOOL_TRUE",
	2: "BOOL_FALSE",
}
var AMBBool_value = map[string]int32{
	"BOOL_NONE":  0,
	"BOOL_TRUE":  1,
	"BOOL_FALSE": 2,
}

func (x AMBBool) String() string {
	return proto.EnumName(AMBBool_name, int32(x))
}
func (AMBBool) EnumDescriptor() ([]byte, []int) { return fileDescriptorCommon, []int{1} }

func init() {
	proto.RegisterEnum("pds.AdminSt", AdminSt_name, AdminSt_value)
	proto.RegisterEnum("pds.AMBBool", AMBBool_name, AMBBool_value)
}

func init() { proto.RegisterFile("common.proto", fileDescriptorCommon) }

var fileDescriptorCommon = []byte{
	// 142 bytes of a gzipped FileDescriptorProto
	0x1f, 0x8b, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xff, 0xe2, 0xe2, 0x49, 0xce, 0xcf, 0xcd,
	0xcd, 0xcf, 0xd3, 0x2b, 0x28, 0xca, 0x2f, 0xc9, 0x17, 0x62, 0x2e, 0x48, 0x29, 0xd6, 0x32, 0xe7,
	0x62, 0x77, 0x4c, 0xc9, 0xcd, 0xcc, 0x0b, 0x2e, 0x11, 0xe2, 0xe3, 0xe2, 0x72, 0x74, 0xf1, 0xf5,
	0xf4, 0x8b, 0xf7, 0xf3, 0xf7, 0x73, 0x15, 0x60, 0x10, 0xe2, 0xe1, 0xe2, 0x80, 0xf0, 0x43, 0x03,
	0x04, 0x18, 0x11, 0xb2, 0x2e, 0xfe, 0xe1, 0x7e, 0x02, 0x4c, 0x60, 0x8d, 0xbe, 0x4e, 0x4e, 0xf9,
	0xf9, 0x39, 0x42, 0xbc, 0x5c, 0x9c, 0x4e, 0xfe, 0xfe, 0x3e, 0x30, 0x7d, 0x30, 0x6e, 0x48, 0x50,
	0xa8, 0x2b, 0x44, 0x23, 0x98, 0xeb, 0xe6, 0xe8, 0x13, 0xec, 0x2a, 0xc0, 0xe4, 0xc4, 0x73, 0xe2,
	0x91, 0x1c, 0xe3, 0x85, 0x47, 0x72, 0x8c, 0x0f, 0x1e, 0xc9, 0x31, 0x26, 0xb1, 0x81, 0xdd, 0x62,
	0x0c, 0x08, 0x00, 0x00, 0xff, 0xff, 0xbb, 0x56, 0xce, 0x60, 0x9b, 0x00, 0x00, 0x00,
}