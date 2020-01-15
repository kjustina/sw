// Code generated by MockGen. DO NOT EDIT.
// Source: ncsi.pb.go

// Package halproto is a generated GoMock package.
package halproto

import (
	reflect "reflect"

	gomock "github.com/golang/mock/gomock"
	context "golang.org/x/net/context"
	grpc "google.golang.org/grpc"
)

// MockNcsiClient is a mock of NcsiClient interface
type MockNcsiClient struct {
	ctrl     *gomock.Controller
	recorder *MockNcsiClientMockRecorder
}

// MockNcsiClientMockRecorder is the mock recorder for MockNcsiClient
type MockNcsiClientMockRecorder struct {
	mock *MockNcsiClient
}

// NewMockNcsiClient creates a new mock instance
func NewMockNcsiClient(ctrl *gomock.Controller) *MockNcsiClient {
	mock := &MockNcsiClient{ctrl: ctrl}
	mock.recorder = &MockNcsiClientMockRecorder{mock}
	return mock
}

// EXPECT returns an object that allows the caller to indicate expected use
func (m *MockNcsiClient) EXPECT() *MockNcsiClientMockRecorder {
	return m.recorder
}

// VlanFilterCreate mocks base method
func (m *MockNcsiClient) VlanFilterCreate(ctx context.Context, in *VlanFilterRequestMsg, opts ...grpc.CallOption) (*VlanFilterResponseMsg, error) {
	varargs := []interface{}{ctx, in}
	for _, a := range opts {
		varargs = append(varargs, a)
	}
	ret := m.ctrl.Call(m, "VlanFilterCreate", varargs...)
	ret0, _ := ret[0].(*VlanFilterResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// VlanFilterCreate indicates an expected call of VlanFilterCreate
func (mr *MockNcsiClientMockRecorder) VlanFilterCreate(ctx, in interface{}, opts ...interface{}) *gomock.Call {
	varargs := append([]interface{}{ctx, in}, opts...)
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "VlanFilterCreate", reflect.TypeOf((*MockNcsiClient)(nil).VlanFilterCreate), varargs...)
}

// VlanFilterDelete mocks base method
func (m *MockNcsiClient) VlanFilterDelete(ctx context.Context, in *VlanFilterRequestMsg, opts ...grpc.CallOption) (*VlanFilterResponseMsg, error) {
	varargs := []interface{}{ctx, in}
	for _, a := range opts {
		varargs = append(varargs, a)
	}
	ret := m.ctrl.Call(m, "VlanFilterDelete", varargs...)
	ret0, _ := ret[0].(*VlanFilterResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// VlanFilterDelete indicates an expected call of VlanFilterDelete
func (mr *MockNcsiClientMockRecorder) VlanFilterDelete(ctx, in interface{}, opts ...interface{}) *gomock.Call {
	varargs := append([]interface{}{ctx, in}, opts...)
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "VlanFilterDelete", reflect.TypeOf((*MockNcsiClient)(nil).VlanFilterDelete), varargs...)
}

// VlanFilterGet mocks base method
func (m *MockNcsiClient) VlanFilterGet(ctx context.Context, in *VlanFilterGetRequestMsg, opts ...grpc.CallOption) (*VlanFilterGetResponseMsg, error) {
	varargs := []interface{}{ctx, in}
	for _, a := range opts {
		varargs = append(varargs, a)
	}
	ret := m.ctrl.Call(m, "VlanFilterGet", varargs...)
	ret0, _ := ret[0].(*VlanFilterGetResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// VlanFilterGet indicates an expected call of VlanFilterGet
func (mr *MockNcsiClientMockRecorder) VlanFilterGet(ctx, in interface{}, opts ...interface{}) *gomock.Call {
	varargs := append([]interface{}{ctx, in}, opts...)
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "VlanFilterGet", reflect.TypeOf((*MockNcsiClient)(nil).VlanFilterGet), varargs...)
}

// MacFilterCreate mocks base method
func (m *MockNcsiClient) MacFilterCreate(ctx context.Context, in *MacFilterRequestMsg, opts ...grpc.CallOption) (*MacFilterResponseMsg, error) {
	varargs := []interface{}{ctx, in}
	for _, a := range opts {
		varargs = append(varargs, a)
	}
	ret := m.ctrl.Call(m, "MacFilterCreate", varargs...)
	ret0, _ := ret[0].(*MacFilterResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// MacFilterCreate indicates an expected call of MacFilterCreate
func (mr *MockNcsiClientMockRecorder) MacFilterCreate(ctx, in interface{}, opts ...interface{}) *gomock.Call {
	varargs := append([]interface{}{ctx, in}, opts...)
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "MacFilterCreate", reflect.TypeOf((*MockNcsiClient)(nil).MacFilterCreate), varargs...)
}

// MacFilterDelete mocks base method
func (m *MockNcsiClient) MacFilterDelete(ctx context.Context, in *MacFilterRequestMsg, opts ...grpc.CallOption) (*MacFilterResponseMsg, error) {
	varargs := []interface{}{ctx, in}
	for _, a := range opts {
		varargs = append(varargs, a)
	}
	ret := m.ctrl.Call(m, "MacFilterDelete", varargs...)
	ret0, _ := ret[0].(*MacFilterResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// MacFilterDelete indicates an expected call of MacFilterDelete
func (mr *MockNcsiClientMockRecorder) MacFilterDelete(ctx, in interface{}, opts ...interface{}) *gomock.Call {
	varargs := append([]interface{}{ctx, in}, opts...)
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "MacFilterDelete", reflect.TypeOf((*MockNcsiClient)(nil).MacFilterDelete), varargs...)
}

// MacFilterGet mocks base method
func (m *MockNcsiClient) MacFilterGet(ctx context.Context, in *MacFilterGetRequestMsg, opts ...grpc.CallOption) (*MacFilterGetResponseMsg, error) {
	varargs := []interface{}{ctx, in}
	for _, a := range opts {
		varargs = append(varargs, a)
	}
	ret := m.ctrl.Call(m, "MacFilterGet", varargs...)
	ret0, _ := ret[0].(*MacFilterGetResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// MacFilterGet indicates an expected call of MacFilterGet
func (mr *MockNcsiClientMockRecorder) MacFilterGet(ctx, in interface{}, opts ...interface{}) *gomock.Call {
	varargs := append([]interface{}{ctx, in}, opts...)
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "MacFilterGet", reflect.TypeOf((*MockNcsiClient)(nil).MacFilterGet), varargs...)
}

// BcastFilterCreate mocks base method
func (m *MockNcsiClient) BcastFilterCreate(ctx context.Context, in *BcastFilterRequestMsg, opts ...grpc.CallOption) (*BcastFilterResponseMsg, error) {
	varargs := []interface{}{ctx, in}
	for _, a := range opts {
		varargs = append(varargs, a)
	}
	ret := m.ctrl.Call(m, "BcastFilterCreate", varargs...)
	ret0, _ := ret[0].(*BcastFilterResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// BcastFilterCreate indicates an expected call of BcastFilterCreate
func (mr *MockNcsiClientMockRecorder) BcastFilterCreate(ctx, in interface{}, opts ...interface{}) *gomock.Call {
	varargs := append([]interface{}{ctx, in}, opts...)
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "BcastFilterCreate", reflect.TypeOf((*MockNcsiClient)(nil).BcastFilterCreate), varargs...)
}

// BcastFilterUpdate mocks base method
func (m *MockNcsiClient) BcastFilterUpdate(ctx context.Context, in *BcastFilterRequestMsg, opts ...grpc.CallOption) (*BcastFilterResponseMsg, error) {
	varargs := []interface{}{ctx, in}
	for _, a := range opts {
		varargs = append(varargs, a)
	}
	ret := m.ctrl.Call(m, "BcastFilterUpdate", varargs...)
	ret0, _ := ret[0].(*BcastFilterResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// BcastFilterUpdate indicates an expected call of BcastFilterUpdate
func (mr *MockNcsiClientMockRecorder) BcastFilterUpdate(ctx, in interface{}, opts ...interface{}) *gomock.Call {
	varargs := append([]interface{}{ctx, in}, opts...)
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "BcastFilterUpdate", reflect.TypeOf((*MockNcsiClient)(nil).BcastFilterUpdate), varargs...)
}

// BcastFilterDelete mocks base method
func (m *MockNcsiClient) BcastFilterDelete(ctx context.Context, in *BcastFilterDeleteRequestMsg, opts ...grpc.CallOption) (*BcastFilterDeleteResponseMsg, error) {
	varargs := []interface{}{ctx, in}
	for _, a := range opts {
		varargs = append(varargs, a)
	}
	ret := m.ctrl.Call(m, "BcastFilterDelete", varargs...)
	ret0, _ := ret[0].(*BcastFilterDeleteResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// BcastFilterDelete indicates an expected call of BcastFilterDelete
func (mr *MockNcsiClientMockRecorder) BcastFilterDelete(ctx, in interface{}, opts ...interface{}) *gomock.Call {
	varargs := append([]interface{}{ctx, in}, opts...)
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "BcastFilterDelete", reflect.TypeOf((*MockNcsiClient)(nil).BcastFilterDelete), varargs...)
}

// BcastFilterGet mocks base method
func (m *MockNcsiClient) BcastFilterGet(ctx context.Context, in *BcastFilterGetRequestMsg, opts ...grpc.CallOption) (*BcastFilterGetResponseMsg, error) {
	varargs := []interface{}{ctx, in}
	for _, a := range opts {
		varargs = append(varargs, a)
	}
	ret := m.ctrl.Call(m, "BcastFilterGet", varargs...)
	ret0, _ := ret[0].(*BcastFilterGetResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// BcastFilterGet indicates an expected call of BcastFilterGet
func (mr *MockNcsiClientMockRecorder) BcastFilterGet(ctx, in interface{}, opts ...interface{}) *gomock.Call {
	varargs := append([]interface{}{ctx, in}, opts...)
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "BcastFilterGet", reflect.TypeOf((*MockNcsiClient)(nil).BcastFilterGet), varargs...)
}

// McastFilterCreate mocks base method
func (m *MockNcsiClient) McastFilterCreate(ctx context.Context, in *McastFilterRequestMsg, opts ...grpc.CallOption) (*McastFilterResponseMsg, error) {
	varargs := []interface{}{ctx, in}
	for _, a := range opts {
		varargs = append(varargs, a)
	}
	ret := m.ctrl.Call(m, "McastFilterCreate", varargs...)
	ret0, _ := ret[0].(*McastFilterResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// McastFilterCreate indicates an expected call of McastFilterCreate
func (mr *MockNcsiClientMockRecorder) McastFilterCreate(ctx, in interface{}, opts ...interface{}) *gomock.Call {
	varargs := append([]interface{}{ctx, in}, opts...)
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "McastFilterCreate", reflect.TypeOf((*MockNcsiClient)(nil).McastFilterCreate), varargs...)
}

// McastFilterUpdate mocks base method
func (m *MockNcsiClient) McastFilterUpdate(ctx context.Context, in *McastFilterRequestMsg, opts ...grpc.CallOption) (*McastFilterResponseMsg, error) {
	varargs := []interface{}{ctx, in}
	for _, a := range opts {
		varargs = append(varargs, a)
	}
	ret := m.ctrl.Call(m, "McastFilterUpdate", varargs...)
	ret0, _ := ret[0].(*McastFilterResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// McastFilterUpdate indicates an expected call of McastFilterUpdate
func (mr *MockNcsiClientMockRecorder) McastFilterUpdate(ctx, in interface{}, opts ...interface{}) *gomock.Call {
	varargs := append([]interface{}{ctx, in}, opts...)
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "McastFilterUpdate", reflect.TypeOf((*MockNcsiClient)(nil).McastFilterUpdate), varargs...)
}

// McastFilterDelete mocks base method
func (m *MockNcsiClient) McastFilterDelete(ctx context.Context, in *McastFilterDeleteRequestMsg, opts ...grpc.CallOption) (*McastFilterDeleteResponseMsg, error) {
	varargs := []interface{}{ctx, in}
	for _, a := range opts {
		varargs = append(varargs, a)
	}
	ret := m.ctrl.Call(m, "McastFilterDelete", varargs...)
	ret0, _ := ret[0].(*McastFilterDeleteResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// McastFilterDelete indicates an expected call of McastFilterDelete
func (mr *MockNcsiClientMockRecorder) McastFilterDelete(ctx, in interface{}, opts ...interface{}) *gomock.Call {
	varargs := append([]interface{}{ctx, in}, opts...)
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "McastFilterDelete", reflect.TypeOf((*MockNcsiClient)(nil).McastFilterDelete), varargs...)
}

// McastFilterGet mocks base method
func (m *MockNcsiClient) McastFilterGet(ctx context.Context, in *McastFilterGetRequestMsg, opts ...grpc.CallOption) (*McastFilterGetResponseMsg, error) {
	varargs := []interface{}{ctx, in}
	for _, a := range opts {
		varargs = append(varargs, a)
	}
	ret := m.ctrl.Call(m, "McastFilterGet", varargs...)
	ret0, _ := ret[0].(*McastFilterGetResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// McastFilterGet indicates an expected call of McastFilterGet
func (mr *MockNcsiClientMockRecorder) McastFilterGet(ctx, in interface{}, opts ...interface{}) *gomock.Call {
	varargs := append([]interface{}{ctx, in}, opts...)
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "McastFilterGet", reflect.TypeOf((*MockNcsiClient)(nil).McastFilterGet), varargs...)
}

// VlanModeCreate mocks base method
func (m *MockNcsiClient) VlanModeCreate(ctx context.Context, in *VlanModeRequestMsg, opts ...grpc.CallOption) (*VlanModeResponseMsg, error) {
	varargs := []interface{}{ctx, in}
	for _, a := range opts {
		varargs = append(varargs, a)
	}
	ret := m.ctrl.Call(m, "VlanModeCreate", varargs...)
	ret0, _ := ret[0].(*VlanModeResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// VlanModeCreate indicates an expected call of VlanModeCreate
func (mr *MockNcsiClientMockRecorder) VlanModeCreate(ctx, in interface{}, opts ...interface{}) *gomock.Call {
	varargs := append([]interface{}{ctx, in}, opts...)
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "VlanModeCreate", reflect.TypeOf((*MockNcsiClient)(nil).VlanModeCreate), varargs...)
}

// VlanModeUpdate mocks base method
func (m *MockNcsiClient) VlanModeUpdate(ctx context.Context, in *VlanModeRequestMsg, opts ...grpc.CallOption) (*VlanModeResponseMsg, error) {
	varargs := []interface{}{ctx, in}
	for _, a := range opts {
		varargs = append(varargs, a)
	}
	ret := m.ctrl.Call(m, "VlanModeUpdate", varargs...)
	ret0, _ := ret[0].(*VlanModeResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// VlanModeUpdate indicates an expected call of VlanModeUpdate
func (mr *MockNcsiClientMockRecorder) VlanModeUpdate(ctx, in interface{}, opts ...interface{}) *gomock.Call {
	varargs := append([]interface{}{ctx, in}, opts...)
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "VlanModeUpdate", reflect.TypeOf((*MockNcsiClient)(nil).VlanModeUpdate), varargs...)
}

// VlanModeDelete mocks base method
func (m *MockNcsiClient) VlanModeDelete(ctx context.Context, in *VlanModeRequestMsg, opts ...grpc.CallOption) (*VlanModeResponseMsg, error) {
	varargs := []interface{}{ctx, in}
	for _, a := range opts {
		varargs = append(varargs, a)
	}
	ret := m.ctrl.Call(m, "VlanModeDelete", varargs...)
	ret0, _ := ret[0].(*VlanModeResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// VlanModeDelete indicates an expected call of VlanModeDelete
func (mr *MockNcsiClientMockRecorder) VlanModeDelete(ctx, in interface{}, opts ...interface{}) *gomock.Call {
	varargs := append([]interface{}{ctx, in}, opts...)
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "VlanModeDelete", reflect.TypeOf((*MockNcsiClient)(nil).VlanModeDelete), varargs...)
}

// VlanModeGet mocks base method
func (m *MockNcsiClient) VlanModeGet(ctx context.Context, in *VlanModeGetRequestMsg, opts ...grpc.CallOption) (*VlanModeGetResponseMsg, error) {
	varargs := []interface{}{ctx, in}
	for _, a := range opts {
		varargs = append(varargs, a)
	}
	ret := m.ctrl.Call(m, "VlanModeGet", varargs...)
	ret0, _ := ret[0].(*VlanModeGetResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// VlanModeGet indicates an expected call of VlanModeGet
func (mr *MockNcsiClientMockRecorder) VlanModeGet(ctx, in interface{}, opts ...interface{}) *gomock.Call {
	varargs := append([]interface{}{ctx, in}, opts...)
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "VlanModeGet", reflect.TypeOf((*MockNcsiClient)(nil).VlanModeGet), varargs...)
}

// ChannelCreate mocks base method
func (m *MockNcsiClient) ChannelCreate(ctx context.Context, in *ChannelRequestMsg, opts ...grpc.CallOption) (*ChannelResponseMsg, error) {
	varargs := []interface{}{ctx, in}
	for _, a := range opts {
		varargs = append(varargs, a)
	}
	ret := m.ctrl.Call(m, "ChannelCreate", varargs...)
	ret0, _ := ret[0].(*ChannelResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// ChannelCreate indicates an expected call of ChannelCreate
func (mr *MockNcsiClientMockRecorder) ChannelCreate(ctx, in interface{}, opts ...interface{}) *gomock.Call {
	varargs := append([]interface{}{ctx, in}, opts...)
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "ChannelCreate", reflect.TypeOf((*MockNcsiClient)(nil).ChannelCreate), varargs...)
}

// ChannelUpdate mocks base method
func (m *MockNcsiClient) ChannelUpdate(ctx context.Context, in *ChannelRequestMsg, opts ...grpc.CallOption) (*ChannelResponseMsg, error) {
	varargs := []interface{}{ctx, in}
	for _, a := range opts {
		varargs = append(varargs, a)
	}
	ret := m.ctrl.Call(m, "ChannelUpdate", varargs...)
	ret0, _ := ret[0].(*ChannelResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// ChannelUpdate indicates an expected call of ChannelUpdate
func (mr *MockNcsiClientMockRecorder) ChannelUpdate(ctx, in interface{}, opts ...interface{}) *gomock.Call {
	varargs := append([]interface{}{ctx, in}, opts...)
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "ChannelUpdate", reflect.TypeOf((*MockNcsiClient)(nil).ChannelUpdate), varargs...)
}

// ChannelDelete mocks base method
func (m *MockNcsiClient) ChannelDelete(ctx context.Context, in *ChannelRequestMsg, opts ...grpc.CallOption) (*ChannelResponseMsg, error) {
	varargs := []interface{}{ctx, in}
	for _, a := range opts {
		varargs = append(varargs, a)
	}
	ret := m.ctrl.Call(m, "ChannelDelete", varargs...)
	ret0, _ := ret[0].(*ChannelResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// ChannelDelete indicates an expected call of ChannelDelete
func (mr *MockNcsiClientMockRecorder) ChannelDelete(ctx, in interface{}, opts ...interface{}) *gomock.Call {
	varargs := append([]interface{}{ctx, in}, opts...)
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "ChannelDelete", reflect.TypeOf((*MockNcsiClient)(nil).ChannelDelete), varargs...)
}

// ChannelGet mocks base method
func (m *MockNcsiClient) ChannelGet(ctx context.Context, in *ChannelGetRequestMsg, opts ...grpc.CallOption) (*ChannelGetResponseMsg, error) {
	varargs := []interface{}{ctx, in}
	for _, a := range opts {
		varargs = append(varargs, a)
	}
	ret := m.ctrl.Call(m, "ChannelGet", varargs...)
	ret0, _ := ret[0].(*ChannelGetResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// ChannelGet indicates an expected call of ChannelGet
func (mr *MockNcsiClientMockRecorder) ChannelGet(ctx, in interface{}, opts ...interface{}) *gomock.Call {
	varargs := append([]interface{}{ctx, in}, opts...)
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "ChannelGet", reflect.TypeOf((*MockNcsiClient)(nil).ChannelGet), varargs...)
}

// MockNcsiServer is a mock of NcsiServer interface
type MockNcsiServer struct {
	ctrl     *gomock.Controller
	recorder *MockNcsiServerMockRecorder
}

// MockNcsiServerMockRecorder is the mock recorder for MockNcsiServer
type MockNcsiServerMockRecorder struct {
	mock *MockNcsiServer
}

// NewMockNcsiServer creates a new mock instance
func NewMockNcsiServer(ctrl *gomock.Controller) *MockNcsiServer {
	mock := &MockNcsiServer{ctrl: ctrl}
	mock.recorder = &MockNcsiServerMockRecorder{mock}
	return mock
}

// EXPECT returns an object that allows the caller to indicate expected use
func (m *MockNcsiServer) EXPECT() *MockNcsiServerMockRecorder {
	return m.recorder
}

// VlanFilterCreate mocks base method
func (m *MockNcsiServer) VlanFilterCreate(arg0 context.Context, arg1 *VlanFilterRequestMsg) (*VlanFilterResponseMsg, error) {
	ret := m.ctrl.Call(m, "VlanFilterCreate", arg0, arg1)
	ret0, _ := ret[0].(*VlanFilterResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// VlanFilterCreate indicates an expected call of VlanFilterCreate
func (mr *MockNcsiServerMockRecorder) VlanFilterCreate(arg0, arg1 interface{}) *gomock.Call {
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "VlanFilterCreate", reflect.TypeOf((*MockNcsiServer)(nil).VlanFilterCreate), arg0, arg1)
}

// VlanFilterDelete mocks base method
func (m *MockNcsiServer) VlanFilterDelete(arg0 context.Context, arg1 *VlanFilterRequestMsg) (*VlanFilterResponseMsg, error) {
	ret := m.ctrl.Call(m, "VlanFilterDelete", arg0, arg1)
	ret0, _ := ret[0].(*VlanFilterResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// VlanFilterDelete indicates an expected call of VlanFilterDelete
func (mr *MockNcsiServerMockRecorder) VlanFilterDelete(arg0, arg1 interface{}) *gomock.Call {
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "VlanFilterDelete", reflect.TypeOf((*MockNcsiServer)(nil).VlanFilterDelete), arg0, arg1)
}

// VlanFilterGet mocks base method
func (m *MockNcsiServer) VlanFilterGet(arg0 context.Context, arg1 *VlanFilterGetRequestMsg) (*VlanFilterGetResponseMsg, error) {
	ret := m.ctrl.Call(m, "VlanFilterGet", arg0, arg1)
	ret0, _ := ret[0].(*VlanFilterGetResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// VlanFilterGet indicates an expected call of VlanFilterGet
func (mr *MockNcsiServerMockRecorder) VlanFilterGet(arg0, arg1 interface{}) *gomock.Call {
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "VlanFilterGet", reflect.TypeOf((*MockNcsiServer)(nil).VlanFilterGet), arg0, arg1)
}

// MacFilterCreate mocks base method
func (m *MockNcsiServer) MacFilterCreate(arg0 context.Context, arg1 *MacFilterRequestMsg) (*MacFilterResponseMsg, error) {
	ret := m.ctrl.Call(m, "MacFilterCreate", arg0, arg1)
	ret0, _ := ret[0].(*MacFilterResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// MacFilterCreate indicates an expected call of MacFilterCreate
func (mr *MockNcsiServerMockRecorder) MacFilterCreate(arg0, arg1 interface{}) *gomock.Call {
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "MacFilterCreate", reflect.TypeOf((*MockNcsiServer)(nil).MacFilterCreate), arg0, arg1)
}

// MacFilterDelete mocks base method
func (m *MockNcsiServer) MacFilterDelete(arg0 context.Context, arg1 *MacFilterRequestMsg) (*MacFilterResponseMsg, error) {
	ret := m.ctrl.Call(m, "MacFilterDelete", arg0, arg1)
	ret0, _ := ret[0].(*MacFilterResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// MacFilterDelete indicates an expected call of MacFilterDelete
func (mr *MockNcsiServerMockRecorder) MacFilterDelete(arg0, arg1 interface{}) *gomock.Call {
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "MacFilterDelete", reflect.TypeOf((*MockNcsiServer)(nil).MacFilterDelete), arg0, arg1)
}

// MacFilterGet mocks base method
func (m *MockNcsiServer) MacFilterGet(arg0 context.Context, arg1 *MacFilterGetRequestMsg) (*MacFilterGetResponseMsg, error) {
	ret := m.ctrl.Call(m, "MacFilterGet", arg0, arg1)
	ret0, _ := ret[0].(*MacFilterGetResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// MacFilterGet indicates an expected call of MacFilterGet
func (mr *MockNcsiServerMockRecorder) MacFilterGet(arg0, arg1 interface{}) *gomock.Call {
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "MacFilterGet", reflect.TypeOf((*MockNcsiServer)(nil).MacFilterGet), arg0, arg1)
}

// BcastFilterCreate mocks base method
func (m *MockNcsiServer) BcastFilterCreate(arg0 context.Context, arg1 *BcastFilterRequestMsg) (*BcastFilterResponseMsg, error) {
	ret := m.ctrl.Call(m, "BcastFilterCreate", arg0, arg1)
	ret0, _ := ret[0].(*BcastFilterResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// BcastFilterCreate indicates an expected call of BcastFilterCreate
func (mr *MockNcsiServerMockRecorder) BcastFilterCreate(arg0, arg1 interface{}) *gomock.Call {
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "BcastFilterCreate", reflect.TypeOf((*MockNcsiServer)(nil).BcastFilterCreate), arg0, arg1)
}

// BcastFilterUpdate mocks base method
func (m *MockNcsiServer) BcastFilterUpdate(arg0 context.Context, arg1 *BcastFilterRequestMsg) (*BcastFilterResponseMsg, error) {
	ret := m.ctrl.Call(m, "BcastFilterUpdate", arg0, arg1)
	ret0, _ := ret[0].(*BcastFilterResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// BcastFilterUpdate indicates an expected call of BcastFilterUpdate
func (mr *MockNcsiServerMockRecorder) BcastFilterUpdate(arg0, arg1 interface{}) *gomock.Call {
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "BcastFilterUpdate", reflect.TypeOf((*MockNcsiServer)(nil).BcastFilterUpdate), arg0, arg1)
}

// BcastFilterDelete mocks base method
func (m *MockNcsiServer) BcastFilterDelete(arg0 context.Context, arg1 *BcastFilterDeleteRequestMsg) (*BcastFilterDeleteResponseMsg, error) {
	ret := m.ctrl.Call(m, "BcastFilterDelete", arg0, arg1)
	ret0, _ := ret[0].(*BcastFilterDeleteResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// BcastFilterDelete indicates an expected call of BcastFilterDelete
func (mr *MockNcsiServerMockRecorder) BcastFilterDelete(arg0, arg1 interface{}) *gomock.Call {
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "BcastFilterDelete", reflect.TypeOf((*MockNcsiServer)(nil).BcastFilterDelete), arg0, arg1)
}

// BcastFilterGet mocks base method
func (m *MockNcsiServer) BcastFilterGet(arg0 context.Context, arg1 *BcastFilterGetRequestMsg) (*BcastFilterGetResponseMsg, error) {
	ret := m.ctrl.Call(m, "BcastFilterGet", arg0, arg1)
	ret0, _ := ret[0].(*BcastFilterGetResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// BcastFilterGet indicates an expected call of BcastFilterGet
func (mr *MockNcsiServerMockRecorder) BcastFilterGet(arg0, arg1 interface{}) *gomock.Call {
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "BcastFilterGet", reflect.TypeOf((*MockNcsiServer)(nil).BcastFilterGet), arg0, arg1)
}

// McastFilterCreate mocks base method
func (m *MockNcsiServer) McastFilterCreate(arg0 context.Context, arg1 *McastFilterRequestMsg) (*McastFilterResponseMsg, error) {
	ret := m.ctrl.Call(m, "McastFilterCreate", arg0, arg1)
	ret0, _ := ret[0].(*McastFilterResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// McastFilterCreate indicates an expected call of McastFilterCreate
func (mr *MockNcsiServerMockRecorder) McastFilterCreate(arg0, arg1 interface{}) *gomock.Call {
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "McastFilterCreate", reflect.TypeOf((*MockNcsiServer)(nil).McastFilterCreate), arg0, arg1)
}

// McastFilterUpdate mocks base method
func (m *MockNcsiServer) McastFilterUpdate(arg0 context.Context, arg1 *McastFilterRequestMsg) (*McastFilterResponseMsg, error) {
	ret := m.ctrl.Call(m, "McastFilterUpdate", arg0, arg1)
	ret0, _ := ret[0].(*McastFilterResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// McastFilterUpdate indicates an expected call of McastFilterUpdate
func (mr *MockNcsiServerMockRecorder) McastFilterUpdate(arg0, arg1 interface{}) *gomock.Call {
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "McastFilterUpdate", reflect.TypeOf((*MockNcsiServer)(nil).McastFilterUpdate), arg0, arg1)
}

// McastFilterDelete mocks base method
func (m *MockNcsiServer) McastFilterDelete(arg0 context.Context, arg1 *McastFilterDeleteRequestMsg) (*McastFilterDeleteResponseMsg, error) {
	ret := m.ctrl.Call(m, "McastFilterDelete", arg0, arg1)
	ret0, _ := ret[0].(*McastFilterDeleteResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// McastFilterDelete indicates an expected call of McastFilterDelete
func (mr *MockNcsiServerMockRecorder) McastFilterDelete(arg0, arg1 interface{}) *gomock.Call {
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "McastFilterDelete", reflect.TypeOf((*MockNcsiServer)(nil).McastFilterDelete), arg0, arg1)
}

// McastFilterGet mocks base method
func (m *MockNcsiServer) McastFilterGet(arg0 context.Context, arg1 *McastFilterGetRequestMsg) (*McastFilterGetResponseMsg, error) {
	ret := m.ctrl.Call(m, "McastFilterGet", arg0, arg1)
	ret0, _ := ret[0].(*McastFilterGetResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// McastFilterGet indicates an expected call of McastFilterGet
func (mr *MockNcsiServerMockRecorder) McastFilterGet(arg0, arg1 interface{}) *gomock.Call {
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "McastFilterGet", reflect.TypeOf((*MockNcsiServer)(nil).McastFilterGet), arg0, arg1)
}

// VlanModeCreate mocks base method
func (m *MockNcsiServer) VlanModeCreate(arg0 context.Context, arg1 *VlanModeRequestMsg) (*VlanModeResponseMsg, error) {
	ret := m.ctrl.Call(m, "VlanModeCreate", arg0, arg1)
	ret0, _ := ret[0].(*VlanModeResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// VlanModeCreate indicates an expected call of VlanModeCreate
func (mr *MockNcsiServerMockRecorder) VlanModeCreate(arg0, arg1 interface{}) *gomock.Call {
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "VlanModeCreate", reflect.TypeOf((*MockNcsiServer)(nil).VlanModeCreate), arg0, arg1)
}

// VlanModeUpdate mocks base method
func (m *MockNcsiServer) VlanModeUpdate(arg0 context.Context, arg1 *VlanModeRequestMsg) (*VlanModeResponseMsg, error) {
	ret := m.ctrl.Call(m, "VlanModeUpdate", arg0, arg1)
	ret0, _ := ret[0].(*VlanModeResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// VlanModeUpdate indicates an expected call of VlanModeUpdate
func (mr *MockNcsiServerMockRecorder) VlanModeUpdate(arg0, arg1 interface{}) *gomock.Call {
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "VlanModeUpdate", reflect.TypeOf((*MockNcsiServer)(nil).VlanModeUpdate), arg0, arg1)
}

// VlanModeDelete mocks base method
func (m *MockNcsiServer) VlanModeDelete(arg0 context.Context, arg1 *VlanModeRequestMsg) (*VlanModeResponseMsg, error) {
	ret := m.ctrl.Call(m, "VlanModeDelete", arg0, arg1)
	ret0, _ := ret[0].(*VlanModeResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// VlanModeDelete indicates an expected call of VlanModeDelete
func (mr *MockNcsiServerMockRecorder) VlanModeDelete(arg0, arg1 interface{}) *gomock.Call {
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "VlanModeDelete", reflect.TypeOf((*MockNcsiServer)(nil).VlanModeDelete), arg0, arg1)
}

// VlanModeGet mocks base method
func (m *MockNcsiServer) VlanModeGet(arg0 context.Context, arg1 *VlanModeGetRequestMsg) (*VlanModeGetResponseMsg, error) {
	ret := m.ctrl.Call(m, "VlanModeGet", arg0, arg1)
	ret0, _ := ret[0].(*VlanModeGetResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// VlanModeGet indicates an expected call of VlanModeGet
func (mr *MockNcsiServerMockRecorder) VlanModeGet(arg0, arg1 interface{}) *gomock.Call {
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "VlanModeGet", reflect.TypeOf((*MockNcsiServer)(nil).VlanModeGet), arg0, arg1)
}

// ChannelCreate mocks base method
func (m *MockNcsiServer) ChannelCreate(arg0 context.Context, arg1 *ChannelRequestMsg) (*ChannelResponseMsg, error) {
	ret := m.ctrl.Call(m, "ChannelCreate", arg0, arg1)
	ret0, _ := ret[0].(*ChannelResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// ChannelCreate indicates an expected call of ChannelCreate
func (mr *MockNcsiServerMockRecorder) ChannelCreate(arg0, arg1 interface{}) *gomock.Call {
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "ChannelCreate", reflect.TypeOf((*MockNcsiServer)(nil).ChannelCreate), arg0, arg1)
}

// ChannelUpdate mocks base method
func (m *MockNcsiServer) ChannelUpdate(arg0 context.Context, arg1 *ChannelRequestMsg) (*ChannelResponseMsg, error) {
	ret := m.ctrl.Call(m, "ChannelUpdate", arg0, arg1)
	ret0, _ := ret[0].(*ChannelResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// ChannelUpdate indicates an expected call of ChannelUpdate
func (mr *MockNcsiServerMockRecorder) ChannelUpdate(arg0, arg1 interface{}) *gomock.Call {
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "ChannelUpdate", reflect.TypeOf((*MockNcsiServer)(nil).ChannelUpdate), arg0, arg1)
}

// ChannelDelete mocks base method
func (m *MockNcsiServer) ChannelDelete(arg0 context.Context, arg1 *ChannelRequestMsg) (*ChannelResponseMsg, error) {
	ret := m.ctrl.Call(m, "ChannelDelete", arg0, arg1)
	ret0, _ := ret[0].(*ChannelResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// ChannelDelete indicates an expected call of ChannelDelete
func (mr *MockNcsiServerMockRecorder) ChannelDelete(arg0, arg1 interface{}) *gomock.Call {
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "ChannelDelete", reflect.TypeOf((*MockNcsiServer)(nil).ChannelDelete), arg0, arg1)
}

// ChannelGet mocks base method
func (m *MockNcsiServer) ChannelGet(arg0 context.Context, arg1 *ChannelGetRequestMsg) (*ChannelGetResponseMsg, error) {
	ret := m.ctrl.Call(m, "ChannelGet", arg0, arg1)
	ret0, _ := ret[0].(*ChannelGetResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// ChannelGet indicates an expected call of ChannelGet
func (mr *MockNcsiServerMockRecorder) ChannelGet(arg0, arg1 interface{}) *gomock.Call {
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "ChannelGet", reflect.TypeOf((*MockNcsiServer)(nil).ChannelGet), arg0, arg1)
}
