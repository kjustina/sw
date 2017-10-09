// Code generated by MockGen. DO NOT EDIT.
// Source: l4lb.pb.go

// Package halproto is a generated GoMock package.
package halproto

import (
	gomock "github.com/golang/mock/gomock"
	context "golang.org/x/net/context"
	grpc "google.golang.org/grpc"
	reflect "reflect"
)

// MockisL4LbServiceKeyHandle_KeyOrHandle is a mock of isL4LbServiceKeyHandle_KeyOrHandle interface
type MockisL4LbServiceKeyHandle_KeyOrHandle struct {
	ctrl     *gomock.Controller
	recorder *MockisL4LbServiceKeyHandle_KeyOrHandleMockRecorder
}

// MockisL4LbServiceKeyHandle_KeyOrHandleMockRecorder is the mock recorder for MockisL4LbServiceKeyHandle_KeyOrHandle
type MockisL4LbServiceKeyHandle_KeyOrHandleMockRecorder struct {
	mock *MockisL4LbServiceKeyHandle_KeyOrHandle
}

// NewMockisL4LbServiceKeyHandle_KeyOrHandle creates a new mock instance
func NewMockisL4LbServiceKeyHandle_KeyOrHandle(ctrl *gomock.Controller) *MockisL4LbServiceKeyHandle_KeyOrHandle {
	mock := &MockisL4LbServiceKeyHandle_KeyOrHandle{ctrl: ctrl}
	mock.recorder = &MockisL4LbServiceKeyHandle_KeyOrHandleMockRecorder{mock}
	return mock
}

// EXPECT returns an object that allows the caller to indicate expected use
func (m *MockisL4LbServiceKeyHandle_KeyOrHandle) EXPECT() *MockisL4LbServiceKeyHandle_KeyOrHandleMockRecorder {
	return m.recorder
}

// isL4LbServiceKeyHandle_KeyOrHandle mocks base method
func (m *MockisL4LbServiceKeyHandle_KeyOrHandle) isL4LbServiceKeyHandle_KeyOrHandle() {
	m.ctrl.Call(m, "isL4LbServiceKeyHandle_KeyOrHandle")
}

// isL4LbServiceKeyHandle_KeyOrHandle indicates an expected call of isL4LbServiceKeyHandle_KeyOrHandle
func (mr *MockisL4LbServiceKeyHandle_KeyOrHandleMockRecorder) isL4LbServiceKeyHandle_KeyOrHandle() *gomock.Call {
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "isL4LbServiceKeyHandle_KeyOrHandle", reflect.TypeOf((*MockisL4LbServiceKeyHandle_KeyOrHandle)(nil).isL4LbServiceKeyHandle_KeyOrHandle))
}

// MarshalTo mocks base method
func (m *MockisL4LbServiceKeyHandle_KeyOrHandle) MarshalTo(arg0 []byte) (int, error) {
	ret := m.ctrl.Call(m, "MarshalTo", arg0)
	ret0, _ := ret[0].(int)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// MarshalTo indicates an expected call of MarshalTo
func (mr *MockisL4LbServiceKeyHandle_KeyOrHandleMockRecorder) MarshalTo(arg0 interface{}) *gomock.Call {
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "MarshalTo", reflect.TypeOf((*MockisL4LbServiceKeyHandle_KeyOrHandle)(nil).MarshalTo), arg0)
}

// Size mocks base method
func (m *MockisL4LbServiceKeyHandle_KeyOrHandle) Size() int {
	ret := m.ctrl.Call(m, "Size")
	ret0, _ := ret[0].(int)
	return ret0
}

// Size indicates an expected call of Size
func (mr *MockisL4LbServiceKeyHandle_KeyOrHandleMockRecorder) Size() *gomock.Call {
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "Size", reflect.TypeOf((*MockisL4LbServiceKeyHandle_KeyOrHandle)(nil).Size))
}

// MockisL4LbBackendKeyHandle_KeyOrHandle is a mock of isL4LbBackendKeyHandle_KeyOrHandle interface
type MockisL4LbBackendKeyHandle_KeyOrHandle struct {
	ctrl     *gomock.Controller
	recorder *MockisL4LbBackendKeyHandle_KeyOrHandleMockRecorder
}

// MockisL4LbBackendKeyHandle_KeyOrHandleMockRecorder is the mock recorder for MockisL4LbBackendKeyHandle_KeyOrHandle
type MockisL4LbBackendKeyHandle_KeyOrHandleMockRecorder struct {
	mock *MockisL4LbBackendKeyHandle_KeyOrHandle
}

// NewMockisL4LbBackendKeyHandle_KeyOrHandle creates a new mock instance
func NewMockisL4LbBackendKeyHandle_KeyOrHandle(ctrl *gomock.Controller) *MockisL4LbBackendKeyHandle_KeyOrHandle {
	mock := &MockisL4LbBackendKeyHandle_KeyOrHandle{ctrl: ctrl}
	mock.recorder = &MockisL4LbBackendKeyHandle_KeyOrHandleMockRecorder{mock}
	return mock
}

// EXPECT returns an object that allows the caller to indicate expected use
func (m *MockisL4LbBackendKeyHandle_KeyOrHandle) EXPECT() *MockisL4LbBackendKeyHandle_KeyOrHandleMockRecorder {
	return m.recorder
}

// isL4LbBackendKeyHandle_KeyOrHandle mocks base method
func (m *MockisL4LbBackendKeyHandle_KeyOrHandle) isL4LbBackendKeyHandle_KeyOrHandle() {
	m.ctrl.Call(m, "isL4LbBackendKeyHandle_KeyOrHandle")
}

// isL4LbBackendKeyHandle_KeyOrHandle indicates an expected call of isL4LbBackendKeyHandle_KeyOrHandle
func (mr *MockisL4LbBackendKeyHandle_KeyOrHandleMockRecorder) isL4LbBackendKeyHandle_KeyOrHandle() *gomock.Call {
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "isL4LbBackendKeyHandle_KeyOrHandle", reflect.TypeOf((*MockisL4LbBackendKeyHandle_KeyOrHandle)(nil).isL4LbBackendKeyHandle_KeyOrHandle))
}

// MarshalTo mocks base method
func (m *MockisL4LbBackendKeyHandle_KeyOrHandle) MarshalTo(arg0 []byte) (int, error) {
	ret := m.ctrl.Call(m, "MarshalTo", arg0)
	ret0, _ := ret[0].(int)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// MarshalTo indicates an expected call of MarshalTo
func (mr *MockisL4LbBackendKeyHandle_KeyOrHandleMockRecorder) MarshalTo(arg0 interface{}) *gomock.Call {
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "MarshalTo", reflect.TypeOf((*MockisL4LbBackendKeyHandle_KeyOrHandle)(nil).MarshalTo), arg0)
}

// Size mocks base method
func (m *MockisL4LbBackendKeyHandle_KeyOrHandle) Size() int {
	ret := m.ctrl.Call(m, "Size")
	ret0, _ := ret[0].(int)
	return ret0
}

// Size indicates an expected call of Size
func (mr *MockisL4LbBackendKeyHandle_KeyOrHandleMockRecorder) Size() *gomock.Call {
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "Size", reflect.TypeOf((*MockisL4LbBackendKeyHandle_KeyOrHandle)(nil).Size))
}

// MockL4LbClient is a mock of L4LbClient interface
type MockL4LbClient struct {
	ctrl     *gomock.Controller
	recorder *MockL4LbClientMockRecorder
}

// MockL4LbClientMockRecorder is the mock recorder for MockL4LbClient
type MockL4LbClientMockRecorder struct {
	mock *MockL4LbClient
}

// NewMockL4LbClient creates a new mock instance
func NewMockL4LbClient(ctrl *gomock.Controller) *MockL4LbClient {
	mock := &MockL4LbClient{ctrl: ctrl}
	mock.recorder = &MockL4LbClientMockRecorder{mock}
	return mock
}

// EXPECT returns an object that allows the caller to indicate expected use
func (m *MockL4LbClient) EXPECT() *MockL4LbClientMockRecorder {
	return m.recorder
}

// L4LbServiceCreate mocks base method
func (m *MockL4LbClient) L4LbServiceCreate(ctx context.Context, in *L4LbServiceRequestMsg, opts ...grpc.CallOption) (*L4LbServiceResponseMsg, error) {
	varargs := []interface{}{ctx, in}
	for _, a := range opts {
		varargs = append(varargs, a)
	}
	ret := m.ctrl.Call(m, "L4LbServiceCreate", varargs...)
	ret0, _ := ret[0].(*L4LbServiceResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// L4LbServiceCreate indicates an expected call of L4LbServiceCreate
func (mr *MockL4LbClientMockRecorder) L4LbServiceCreate(ctx, in interface{}, opts ...interface{}) *gomock.Call {
	varargs := append([]interface{}{ctx, in}, opts...)
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "L4LbServiceCreate", reflect.TypeOf((*MockL4LbClient)(nil).L4LbServiceCreate), varargs...)
}

// L4LbServiceUpdate mocks base method
func (m *MockL4LbClient) L4LbServiceUpdate(ctx context.Context, in *L4LbServiceRequestMsg, opts ...grpc.CallOption) (*L4LbServiceResponseMsg, error) {
	varargs := []interface{}{ctx, in}
	for _, a := range opts {
		varargs = append(varargs, a)
	}
	ret := m.ctrl.Call(m, "L4LbServiceUpdate", varargs...)
	ret0, _ := ret[0].(*L4LbServiceResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// L4LbServiceUpdate indicates an expected call of L4LbServiceUpdate
func (mr *MockL4LbClientMockRecorder) L4LbServiceUpdate(ctx, in interface{}, opts ...interface{}) *gomock.Call {
	varargs := append([]interface{}{ctx, in}, opts...)
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "L4LbServiceUpdate", reflect.TypeOf((*MockL4LbClient)(nil).L4LbServiceUpdate), varargs...)
}

// L4LbServiceDelete mocks base method
func (m *MockL4LbClient) L4LbServiceDelete(ctx context.Context, in *L4LbServiceDeleteRequestMsg, opts ...grpc.CallOption) (*L4LbServiceDeleteResponseMsg, error) {
	varargs := []interface{}{ctx, in}
	for _, a := range opts {
		varargs = append(varargs, a)
	}
	ret := m.ctrl.Call(m, "L4LbServiceDelete", varargs...)
	ret0, _ := ret[0].(*L4LbServiceDeleteResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// L4LbServiceDelete indicates an expected call of L4LbServiceDelete
func (mr *MockL4LbClientMockRecorder) L4LbServiceDelete(ctx, in interface{}, opts ...interface{}) *gomock.Call {
	varargs := append([]interface{}{ctx, in}, opts...)
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "L4LbServiceDelete", reflect.TypeOf((*MockL4LbClient)(nil).L4LbServiceDelete), varargs...)
}

// L4LbServiceGet mocks base method
func (m *MockL4LbClient) L4LbServiceGet(ctx context.Context, in *L4LbServiceGetRequestMsg, opts ...grpc.CallOption) (*L4LbServiceGetResponseMsg, error) {
	varargs := []interface{}{ctx, in}
	for _, a := range opts {
		varargs = append(varargs, a)
	}
	ret := m.ctrl.Call(m, "L4LbServiceGet", varargs...)
	ret0, _ := ret[0].(*L4LbServiceGetResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// L4LbServiceGet indicates an expected call of L4LbServiceGet
func (mr *MockL4LbClientMockRecorder) L4LbServiceGet(ctx, in interface{}, opts ...interface{}) *gomock.Call {
	varargs := append([]interface{}{ctx, in}, opts...)
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "L4LbServiceGet", reflect.TypeOf((*MockL4LbClient)(nil).L4LbServiceGet), varargs...)
}

// L4LbBackendCreate mocks base method
func (m *MockL4LbClient) L4LbBackendCreate(ctx context.Context, in *L4LbBackendRequestMsg, opts ...grpc.CallOption) (*L4LbBackendResponseMsg, error) {
	varargs := []interface{}{ctx, in}
	for _, a := range opts {
		varargs = append(varargs, a)
	}
	ret := m.ctrl.Call(m, "L4LbBackendCreate", varargs...)
	ret0, _ := ret[0].(*L4LbBackendResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// L4LbBackendCreate indicates an expected call of L4LbBackendCreate
func (mr *MockL4LbClientMockRecorder) L4LbBackendCreate(ctx, in interface{}, opts ...interface{}) *gomock.Call {
	varargs := append([]interface{}{ctx, in}, opts...)
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "L4LbBackendCreate", reflect.TypeOf((*MockL4LbClient)(nil).L4LbBackendCreate), varargs...)
}

// L4LbBackendUpdate mocks base method
func (m *MockL4LbClient) L4LbBackendUpdate(ctx context.Context, in *L4LbBackendRequestMsg, opts ...grpc.CallOption) (*L4LbBackendResponseMsg, error) {
	varargs := []interface{}{ctx, in}
	for _, a := range opts {
		varargs = append(varargs, a)
	}
	ret := m.ctrl.Call(m, "L4LbBackendUpdate", varargs...)
	ret0, _ := ret[0].(*L4LbBackendResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// L4LbBackendUpdate indicates an expected call of L4LbBackendUpdate
func (mr *MockL4LbClientMockRecorder) L4LbBackendUpdate(ctx, in interface{}, opts ...interface{}) *gomock.Call {
	varargs := append([]interface{}{ctx, in}, opts...)
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "L4LbBackendUpdate", reflect.TypeOf((*MockL4LbClient)(nil).L4LbBackendUpdate), varargs...)
}

// L4LbBackendDelete mocks base method
func (m *MockL4LbClient) L4LbBackendDelete(ctx context.Context, in *L4LbBackendDeleteRequestMsg, opts ...grpc.CallOption) (*L4LbBackendDeleteResponseMsg, error) {
	varargs := []interface{}{ctx, in}
	for _, a := range opts {
		varargs = append(varargs, a)
	}
	ret := m.ctrl.Call(m, "L4LbBackendDelete", varargs...)
	ret0, _ := ret[0].(*L4LbBackendDeleteResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// L4LbBackendDelete indicates an expected call of L4LbBackendDelete
func (mr *MockL4LbClientMockRecorder) L4LbBackendDelete(ctx, in interface{}, opts ...interface{}) *gomock.Call {
	varargs := append([]interface{}{ctx, in}, opts...)
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "L4LbBackendDelete", reflect.TypeOf((*MockL4LbClient)(nil).L4LbBackendDelete), varargs...)
}

// L4LbBackendGet mocks base method
func (m *MockL4LbClient) L4LbBackendGet(ctx context.Context, in *L4LbBackendGetRequestMsg, opts ...grpc.CallOption) (*L4LbBackendGetResponseMsg, error) {
	varargs := []interface{}{ctx, in}
	for _, a := range opts {
		varargs = append(varargs, a)
	}
	ret := m.ctrl.Call(m, "L4LbBackendGet", varargs...)
	ret0, _ := ret[0].(*L4LbBackendGetResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// L4LbBackendGet indicates an expected call of L4LbBackendGet
func (mr *MockL4LbClientMockRecorder) L4LbBackendGet(ctx, in interface{}, opts ...interface{}) *gomock.Call {
	varargs := append([]interface{}{ctx, in}, opts...)
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "L4LbBackendGet", reflect.TypeOf((*MockL4LbClient)(nil).L4LbBackendGet), varargs...)
}

// MockL4LbServer is a mock of L4LbServer interface
type MockL4LbServer struct {
	ctrl     *gomock.Controller
	recorder *MockL4LbServerMockRecorder
}

// MockL4LbServerMockRecorder is the mock recorder for MockL4LbServer
type MockL4LbServerMockRecorder struct {
	mock *MockL4LbServer
}

// NewMockL4LbServer creates a new mock instance
func NewMockL4LbServer(ctrl *gomock.Controller) *MockL4LbServer {
	mock := &MockL4LbServer{ctrl: ctrl}
	mock.recorder = &MockL4LbServerMockRecorder{mock}
	return mock
}

// EXPECT returns an object that allows the caller to indicate expected use
func (m *MockL4LbServer) EXPECT() *MockL4LbServerMockRecorder {
	return m.recorder
}

// L4LbServiceCreate mocks base method
func (m *MockL4LbServer) L4LbServiceCreate(arg0 context.Context, arg1 *L4LbServiceRequestMsg) (*L4LbServiceResponseMsg, error) {
	ret := m.ctrl.Call(m, "L4LbServiceCreate", arg0, arg1)
	ret0, _ := ret[0].(*L4LbServiceResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// L4LbServiceCreate indicates an expected call of L4LbServiceCreate
func (mr *MockL4LbServerMockRecorder) L4LbServiceCreate(arg0, arg1 interface{}) *gomock.Call {
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "L4LbServiceCreate", reflect.TypeOf((*MockL4LbServer)(nil).L4LbServiceCreate), arg0, arg1)
}

// L4LbServiceUpdate mocks base method
func (m *MockL4LbServer) L4LbServiceUpdate(arg0 context.Context, arg1 *L4LbServiceRequestMsg) (*L4LbServiceResponseMsg, error) {
	ret := m.ctrl.Call(m, "L4LbServiceUpdate", arg0, arg1)
	ret0, _ := ret[0].(*L4LbServiceResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// L4LbServiceUpdate indicates an expected call of L4LbServiceUpdate
func (mr *MockL4LbServerMockRecorder) L4LbServiceUpdate(arg0, arg1 interface{}) *gomock.Call {
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "L4LbServiceUpdate", reflect.TypeOf((*MockL4LbServer)(nil).L4LbServiceUpdate), arg0, arg1)
}

// L4LbServiceDelete mocks base method
func (m *MockL4LbServer) L4LbServiceDelete(arg0 context.Context, arg1 *L4LbServiceDeleteRequestMsg) (*L4LbServiceDeleteResponseMsg, error) {
	ret := m.ctrl.Call(m, "L4LbServiceDelete", arg0, arg1)
	ret0, _ := ret[0].(*L4LbServiceDeleteResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// L4LbServiceDelete indicates an expected call of L4LbServiceDelete
func (mr *MockL4LbServerMockRecorder) L4LbServiceDelete(arg0, arg1 interface{}) *gomock.Call {
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "L4LbServiceDelete", reflect.TypeOf((*MockL4LbServer)(nil).L4LbServiceDelete), arg0, arg1)
}

// L4LbServiceGet mocks base method
func (m *MockL4LbServer) L4LbServiceGet(arg0 context.Context, arg1 *L4LbServiceGetRequestMsg) (*L4LbServiceGetResponseMsg, error) {
	ret := m.ctrl.Call(m, "L4LbServiceGet", arg0, arg1)
	ret0, _ := ret[0].(*L4LbServiceGetResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// L4LbServiceGet indicates an expected call of L4LbServiceGet
func (mr *MockL4LbServerMockRecorder) L4LbServiceGet(arg0, arg1 interface{}) *gomock.Call {
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "L4LbServiceGet", reflect.TypeOf((*MockL4LbServer)(nil).L4LbServiceGet), arg0, arg1)
}

// L4LbBackendCreate mocks base method
func (m *MockL4LbServer) L4LbBackendCreate(arg0 context.Context, arg1 *L4LbBackendRequestMsg) (*L4LbBackendResponseMsg, error) {
	ret := m.ctrl.Call(m, "L4LbBackendCreate", arg0, arg1)
	ret0, _ := ret[0].(*L4LbBackendResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// L4LbBackendCreate indicates an expected call of L4LbBackendCreate
func (mr *MockL4LbServerMockRecorder) L4LbBackendCreate(arg0, arg1 interface{}) *gomock.Call {
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "L4LbBackendCreate", reflect.TypeOf((*MockL4LbServer)(nil).L4LbBackendCreate), arg0, arg1)
}

// L4LbBackendUpdate mocks base method
func (m *MockL4LbServer) L4LbBackendUpdate(arg0 context.Context, arg1 *L4LbBackendRequestMsg) (*L4LbBackendResponseMsg, error) {
	ret := m.ctrl.Call(m, "L4LbBackendUpdate", arg0, arg1)
	ret0, _ := ret[0].(*L4LbBackendResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// L4LbBackendUpdate indicates an expected call of L4LbBackendUpdate
func (mr *MockL4LbServerMockRecorder) L4LbBackendUpdate(arg0, arg1 interface{}) *gomock.Call {
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "L4LbBackendUpdate", reflect.TypeOf((*MockL4LbServer)(nil).L4LbBackendUpdate), arg0, arg1)
}

// L4LbBackendDelete mocks base method
func (m *MockL4LbServer) L4LbBackendDelete(arg0 context.Context, arg1 *L4LbBackendDeleteRequestMsg) (*L4LbBackendDeleteResponseMsg, error) {
	ret := m.ctrl.Call(m, "L4LbBackendDelete", arg0, arg1)
	ret0, _ := ret[0].(*L4LbBackendDeleteResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// L4LbBackendDelete indicates an expected call of L4LbBackendDelete
func (mr *MockL4LbServerMockRecorder) L4LbBackendDelete(arg0, arg1 interface{}) *gomock.Call {
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "L4LbBackendDelete", reflect.TypeOf((*MockL4LbServer)(nil).L4LbBackendDelete), arg0, arg1)
}

// L4LbBackendGet mocks base method
func (m *MockL4LbServer) L4LbBackendGet(arg0 context.Context, arg1 *L4LbBackendGetRequestMsg) (*L4LbBackendGetResponseMsg, error) {
	ret := m.ctrl.Call(m, "L4LbBackendGet", arg0, arg1)
	ret0, _ := ret[0].(*L4LbBackendGetResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// L4LbBackendGet indicates an expected call of L4LbBackendGet
func (mr *MockL4LbServerMockRecorder) L4LbBackendGet(arg0, arg1 interface{}) *gomock.Call {
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "L4LbBackendGet", reflect.TypeOf((*MockL4LbServer)(nil).L4LbBackendGet), arg0, arg1)
}
