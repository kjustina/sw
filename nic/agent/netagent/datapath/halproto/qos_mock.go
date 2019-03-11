// Code generated by MockGen. DO NOT EDIT.
// Source: qos.pb.go

// Package halproto is a generated GoMock package.
package halproto

import (
	reflect "reflect"

	gomock "github.com/golang/mock/gomock"
	context "golang.org/x/net/context"
	grpc "google.golang.org/grpc"
)

// MockisPolicerSpec_PolicerType is a mock of isPolicerSpec_PolicerType interface
type MockisPolicerSpec_PolicerType struct {
	ctrl     *gomock.Controller
	recorder *MockisPolicerSpec_PolicerTypeMockRecorder
}

// MockisPolicerSpec_PolicerTypeMockRecorder is the mock recorder for MockisPolicerSpec_PolicerType
type MockisPolicerSpec_PolicerTypeMockRecorder struct {
	mock *MockisPolicerSpec_PolicerType
}

// NewMockisPolicerSpec_PolicerType creates a new mock instance
func NewMockisPolicerSpec_PolicerType(ctrl *gomock.Controller) *MockisPolicerSpec_PolicerType {
	mock := &MockisPolicerSpec_PolicerType{ctrl: ctrl}
	mock.recorder = &MockisPolicerSpec_PolicerTypeMockRecorder{mock}
	return mock
}

// EXPECT returns an object that allows the caller to indicate expected use
func (m *MockisPolicerSpec_PolicerType) EXPECT() *MockisPolicerSpec_PolicerTypeMockRecorder {
	return m.recorder
}

// isPolicerSpec_PolicerType mocks base method
func (m *MockisPolicerSpec_PolicerType) isPolicerSpec_PolicerType() {
	m.ctrl.Call(m, "isPolicerSpec_PolicerType")
}

// isPolicerSpec_PolicerType indicates an expected call of isPolicerSpec_PolicerType
func (mr *MockisPolicerSpec_PolicerTypeMockRecorder) isPolicerSpec_PolicerType() *gomock.Call {
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "isPolicerSpec_PolicerType", reflect.TypeOf((*MockisPolicerSpec_PolicerType)(nil).isPolicerSpec_PolicerType))
}

// MarshalTo mocks base method
func (m *MockisPolicerSpec_PolicerType) MarshalTo(arg0 []byte) (int, error) {
	ret := m.ctrl.Call(m, "MarshalTo", arg0)
	ret0, _ := ret[0].(int)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// MarshalTo indicates an expected call of MarshalTo
func (mr *MockisPolicerSpec_PolicerTypeMockRecorder) MarshalTo(arg0 interface{}) *gomock.Call {
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "MarshalTo", reflect.TypeOf((*MockisPolicerSpec_PolicerType)(nil).MarshalTo), arg0)
}

// Size mocks base method
func (m *MockisPolicerSpec_PolicerType) Size() int {
	ret := m.ctrl.Call(m, "Size")
	ret0, _ := ret[0].(int)
	return ret0
}

// Size indicates an expected call of Size
func (mr *MockisPolicerSpec_PolicerTypeMockRecorder) Size() *gomock.Call {
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "Size", reflect.TypeOf((*MockisPolicerSpec_PolicerType)(nil).Size))
}

// MockisQosSched_SchedType is a mock of isQosSched_SchedType interface
type MockisQosSched_SchedType struct {
	ctrl     *gomock.Controller
	recorder *MockisQosSched_SchedTypeMockRecorder
}

// MockisQosSched_SchedTypeMockRecorder is the mock recorder for MockisQosSched_SchedType
type MockisQosSched_SchedTypeMockRecorder struct {
	mock *MockisQosSched_SchedType
}

// NewMockisQosSched_SchedType creates a new mock instance
func NewMockisQosSched_SchedType(ctrl *gomock.Controller) *MockisQosSched_SchedType {
	mock := &MockisQosSched_SchedType{ctrl: ctrl}
	mock.recorder = &MockisQosSched_SchedTypeMockRecorder{mock}
	return mock
}

// EXPECT returns an object that allows the caller to indicate expected use
func (m *MockisQosSched_SchedType) EXPECT() *MockisQosSched_SchedTypeMockRecorder {
	return m.recorder
}

// isQosSched_SchedType mocks base method
func (m *MockisQosSched_SchedType) isQosSched_SchedType() {
	m.ctrl.Call(m, "isQosSched_SchedType")
}

// isQosSched_SchedType indicates an expected call of isQosSched_SchedType
func (mr *MockisQosSched_SchedTypeMockRecorder) isQosSched_SchedType() *gomock.Call {
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "isQosSched_SchedType", reflect.TypeOf((*MockisQosSched_SchedType)(nil).isQosSched_SchedType))
}

// MarshalTo mocks base method
func (m *MockisQosSched_SchedType) MarshalTo(arg0 []byte) (int, error) {
	ret := m.ctrl.Call(m, "MarshalTo", arg0)
	ret0, _ := ret[0].(int)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// MarshalTo indicates an expected call of MarshalTo
func (mr *MockisQosSched_SchedTypeMockRecorder) MarshalTo(arg0 interface{}) *gomock.Call {
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "MarshalTo", reflect.TypeOf((*MockisQosSched_SchedType)(nil).MarshalTo), arg0)
}

// Size mocks base method
func (m *MockisQosSched_SchedType) Size() int {
	ret := m.ctrl.Call(m, "Size")
	ret0, _ := ret[0].(int)
	return ret0
}

// Size indicates an expected call of Size
func (mr *MockisQosSched_SchedTypeMockRecorder) Size() *gomock.Call {
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "Size", reflect.TypeOf((*MockisQosSched_SchedType)(nil).Size))
}

// MockisQosClassStatus_QosClassPdStatus is a mock of isQosClassStatus_QosClassPdStatus interface
type MockisQosClassStatus_QosClassPdStatus struct {
	ctrl     *gomock.Controller
	recorder *MockisQosClassStatus_QosClassPdStatusMockRecorder
}

// MockisQosClassStatus_QosClassPdStatusMockRecorder is the mock recorder for MockisQosClassStatus_QosClassPdStatus
type MockisQosClassStatus_QosClassPdStatusMockRecorder struct {
	mock *MockisQosClassStatus_QosClassPdStatus
}

// NewMockisQosClassStatus_QosClassPdStatus creates a new mock instance
func NewMockisQosClassStatus_QosClassPdStatus(ctrl *gomock.Controller) *MockisQosClassStatus_QosClassPdStatus {
	mock := &MockisQosClassStatus_QosClassPdStatus{ctrl: ctrl}
	mock.recorder = &MockisQosClassStatus_QosClassPdStatusMockRecorder{mock}
	return mock
}

// EXPECT returns an object that allows the caller to indicate expected use
func (m *MockisQosClassStatus_QosClassPdStatus) EXPECT() *MockisQosClassStatus_QosClassPdStatusMockRecorder {
	return m.recorder
}

// isQosClassStatus_QosClassPdStatus mocks base method
func (m *MockisQosClassStatus_QosClassPdStatus) isQosClassStatus_QosClassPdStatus() {
	m.ctrl.Call(m, "isQosClassStatus_QosClassPdStatus")
}

// isQosClassStatus_QosClassPdStatus indicates an expected call of isQosClassStatus_QosClassPdStatus
func (mr *MockisQosClassStatus_QosClassPdStatusMockRecorder) isQosClassStatus_QosClassPdStatus() *gomock.Call {
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "isQosClassStatus_QosClassPdStatus", reflect.TypeOf((*MockisQosClassStatus_QosClassPdStatus)(nil).isQosClassStatus_QosClassPdStatus))
}

// MarshalTo mocks base method
func (m *MockisQosClassStatus_QosClassPdStatus) MarshalTo(arg0 []byte) (int, error) {
	ret := m.ctrl.Call(m, "MarshalTo", arg0)
	ret0, _ := ret[0].(int)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// MarshalTo indicates an expected call of MarshalTo
func (mr *MockisQosClassStatus_QosClassPdStatusMockRecorder) MarshalTo(arg0 interface{}) *gomock.Call {
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "MarshalTo", reflect.TypeOf((*MockisQosClassStatus_QosClassPdStatus)(nil).MarshalTo), arg0)
}

// Size mocks base method
func (m *MockisQosClassStatus_QosClassPdStatus) Size() int {
	ret := m.ctrl.Call(m, "Size")
	ret0, _ := ret[0].(int)
	return ret0
}

// Size indicates an expected call of Size
func (mr *MockisQosClassStatus_QosClassPdStatusMockRecorder) Size() *gomock.Call {
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "Size", reflect.TypeOf((*MockisQosClassStatus_QosClassPdStatus)(nil).Size))
}

// MockisCoppStatus_QosClassPdStatus is a mock of isCoppStatus_QosClassPdStatus interface
type MockisCoppStatus_QosClassPdStatus struct {
	ctrl     *gomock.Controller
	recorder *MockisCoppStatus_QosClassPdStatusMockRecorder
}

// MockisCoppStatus_QosClassPdStatusMockRecorder is the mock recorder for MockisCoppStatus_QosClassPdStatus
type MockisCoppStatus_QosClassPdStatusMockRecorder struct {
	mock *MockisCoppStatus_QosClassPdStatus
}

// NewMockisCoppStatus_QosClassPdStatus creates a new mock instance
func NewMockisCoppStatus_QosClassPdStatus(ctrl *gomock.Controller) *MockisCoppStatus_QosClassPdStatus {
	mock := &MockisCoppStatus_QosClassPdStatus{ctrl: ctrl}
	mock.recorder = &MockisCoppStatus_QosClassPdStatusMockRecorder{mock}
	return mock
}

// EXPECT returns an object that allows the caller to indicate expected use
func (m *MockisCoppStatus_QosClassPdStatus) EXPECT() *MockisCoppStatus_QosClassPdStatusMockRecorder {
	return m.recorder
}

// isCoppStatus_QosClassPdStatus mocks base method
func (m *MockisCoppStatus_QosClassPdStatus) isCoppStatus_QosClassPdStatus() {
	m.ctrl.Call(m, "isCoppStatus_QosClassPdStatus")
}

// isCoppStatus_QosClassPdStatus indicates an expected call of isCoppStatus_QosClassPdStatus
func (mr *MockisCoppStatus_QosClassPdStatusMockRecorder) isCoppStatus_QosClassPdStatus() *gomock.Call {
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "isCoppStatus_QosClassPdStatus", reflect.TypeOf((*MockisCoppStatus_QosClassPdStatus)(nil).isCoppStatus_QosClassPdStatus))
}

// MarshalTo mocks base method
func (m *MockisCoppStatus_QosClassPdStatus) MarshalTo(arg0 []byte) (int, error) {
	ret := m.ctrl.Call(m, "MarshalTo", arg0)
	ret0, _ := ret[0].(int)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// MarshalTo indicates an expected call of MarshalTo
func (mr *MockisCoppStatus_QosClassPdStatusMockRecorder) MarshalTo(arg0 interface{}) *gomock.Call {
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "MarshalTo", reflect.TypeOf((*MockisCoppStatus_QosClassPdStatus)(nil).MarshalTo), arg0)
}

// Size mocks base method
func (m *MockisCoppStatus_QosClassPdStatus) Size() int {
	ret := m.ctrl.Call(m, "Size")
	ret0, _ := ret[0].(int)
	return ret0
}

// Size indicates an expected call of Size
func (mr *MockisCoppStatus_QosClassPdStatusMockRecorder) Size() *gomock.Call {
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "Size", reflect.TypeOf((*MockisCoppStatus_QosClassPdStatus)(nil).Size))
}

// MockQOSClient is a mock of QOSClient interface
type MockQOSClient struct {
	ctrl     *gomock.Controller
	recorder *MockQOSClientMockRecorder
}

// MockQOSClientMockRecorder is the mock recorder for MockQOSClient
type MockQOSClientMockRecorder struct {
	mock *MockQOSClient
}

// NewMockQOSClient creates a new mock instance
func NewMockQOSClient(ctrl *gomock.Controller) *MockQOSClient {
	mock := &MockQOSClient{ctrl: ctrl}
	mock.recorder = &MockQOSClientMockRecorder{mock}
	return mock
}

// EXPECT returns an object that allows the caller to indicate expected use
func (m *MockQOSClient) EXPECT() *MockQOSClientMockRecorder {
	return m.recorder
}

// QosClassCreate mocks base method
func (m *MockQOSClient) QosClassCreate(ctx context.Context, in *QosClassRequestMsg, opts ...grpc.CallOption) (*QosClassResponseMsg, error) {
	varargs := []interface{}{ctx, in}
	for _, a := range opts {
		varargs = append(varargs, a)
	}
	ret := m.ctrl.Call(m, "QosClassCreate", varargs...)
	ret0, _ := ret[0].(*QosClassResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// QosClassCreate indicates an expected call of QosClassCreate
func (mr *MockQOSClientMockRecorder) QosClassCreate(ctx, in interface{}, opts ...interface{}) *gomock.Call {
	varargs := append([]interface{}{ctx, in}, opts...)
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "QosClassCreate", reflect.TypeOf((*MockQOSClient)(nil).QosClassCreate), varargs...)
}

// QosClassUpdate mocks base method
func (m *MockQOSClient) QosClassUpdate(ctx context.Context, in *QosClassRequestMsg, opts ...grpc.CallOption) (*QosClassResponseMsg, error) {
	varargs := []interface{}{ctx, in}
	for _, a := range opts {
		varargs = append(varargs, a)
	}
	ret := m.ctrl.Call(m, "QosClassUpdate", varargs...)
	ret0, _ := ret[0].(*QosClassResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// QosClassUpdate indicates an expected call of QosClassUpdate
func (mr *MockQOSClientMockRecorder) QosClassUpdate(ctx, in interface{}, opts ...interface{}) *gomock.Call {
	varargs := append([]interface{}{ctx, in}, opts...)
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "QosClassUpdate", reflect.TypeOf((*MockQOSClient)(nil).QosClassUpdate), varargs...)
}

// QosClassDelete mocks base method
func (m *MockQOSClient) QosClassDelete(ctx context.Context, in *QosClassDeleteRequestMsg, opts ...grpc.CallOption) (*QosClassDeleteResponseMsg, error) {
	varargs := []interface{}{ctx, in}
	for _, a := range opts {
		varargs = append(varargs, a)
	}
	ret := m.ctrl.Call(m, "QosClassDelete", varargs...)
	ret0, _ := ret[0].(*QosClassDeleteResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// QosClassDelete indicates an expected call of QosClassDelete
func (mr *MockQOSClientMockRecorder) QosClassDelete(ctx, in interface{}, opts ...interface{}) *gomock.Call {
	varargs := append([]interface{}{ctx, in}, opts...)
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "QosClassDelete", reflect.TypeOf((*MockQOSClient)(nil).QosClassDelete), varargs...)
}

// QosClassGet mocks base method
func (m *MockQOSClient) QosClassGet(ctx context.Context, in *QosClassGetRequestMsg, opts ...grpc.CallOption) (*QosClassGetResponseMsg, error) {
	varargs := []interface{}{ctx, in}
	for _, a := range opts {
		varargs = append(varargs, a)
	}
	ret := m.ctrl.Call(m, "QosClassGet", varargs...)
	ret0, _ := ret[0].(*QosClassGetResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// QosClassGet indicates an expected call of QosClassGet
func (mr *MockQOSClientMockRecorder) QosClassGet(ctx, in interface{}, opts ...interface{}) *gomock.Call {
	varargs := append([]interface{}{ctx, in}, opts...)
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "QosClassGet", reflect.TypeOf((*MockQOSClient)(nil).QosClassGet), varargs...)
}

// QosClassThresholdsGet mocks base method
func (m *MockQOSClient) QosClassThresholdsGet(ctx context.Context, in *QosClassThresholdsGetRequestMsg, opts ...grpc.CallOption) (*QosClassThresholdsGetResponseMsg, error) {
	varargs := []interface{}{ctx, in}
	for _, a := range opts {
		varargs = append(varargs, a)
	}
	ret := m.ctrl.Call(m, "QosClassThresholdsGet", varargs...)
	ret0, _ := ret[0].(*QosClassThresholdsGetResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// QosClassThresholdsGet indicates an expected call of QosClassThresholdsGet
func (mr *MockQOSClientMockRecorder) QosClassThresholdsGet(ctx, in interface{}, opts ...interface{}) *gomock.Call {
	varargs := append([]interface{}{ctx, in}, opts...)
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "QosClassThresholdsGet", reflect.TypeOf((*MockQOSClient)(nil).QosClassThresholdsGet), varargs...)
}

// CoppUpdate mocks base method
func (m *MockQOSClient) CoppUpdate(ctx context.Context, in *CoppRequestMsg, opts ...grpc.CallOption) (*CoppResponseMsg, error) {
	varargs := []interface{}{ctx, in}
	for _, a := range opts {
		varargs = append(varargs, a)
	}
	ret := m.ctrl.Call(m, "CoppUpdate", varargs...)
	ret0, _ := ret[0].(*CoppResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// CoppUpdate indicates an expected call of CoppUpdate
func (mr *MockQOSClientMockRecorder) CoppUpdate(ctx, in interface{}, opts ...interface{}) *gomock.Call {
	varargs := append([]interface{}{ctx, in}, opts...)
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "CoppUpdate", reflect.TypeOf((*MockQOSClient)(nil).CoppUpdate), varargs...)
}

// CoppGet mocks base method
func (m *MockQOSClient) CoppGet(ctx context.Context, in *CoppGetRequestMsg, opts ...grpc.CallOption) (*CoppGetResponseMsg, error) {
	varargs := []interface{}{ctx, in}
	for _, a := range opts {
		varargs = append(varargs, a)
	}
	ret := m.ctrl.Call(m, "CoppGet", varargs...)
	ret0, _ := ret[0].(*CoppGetResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// CoppGet indicates an expected call of CoppGet
func (mr *MockQOSClientMockRecorder) CoppGet(ctx, in interface{}, opts ...interface{}) *gomock.Call {
	varargs := append([]interface{}{ctx, in}, opts...)
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "CoppGet", reflect.TypeOf((*MockQOSClient)(nil).CoppGet), varargs...)
}

// MockQOSServer is a mock of QOSServer interface
type MockQOSServer struct {
	ctrl     *gomock.Controller
	recorder *MockQOSServerMockRecorder
}

// MockQOSServerMockRecorder is the mock recorder for MockQOSServer
type MockQOSServerMockRecorder struct {
	mock *MockQOSServer
}

// NewMockQOSServer creates a new mock instance
func NewMockQOSServer(ctrl *gomock.Controller) *MockQOSServer {
	mock := &MockQOSServer{ctrl: ctrl}
	mock.recorder = &MockQOSServerMockRecorder{mock}
	return mock
}

// EXPECT returns an object that allows the caller to indicate expected use
func (m *MockQOSServer) EXPECT() *MockQOSServerMockRecorder {
	return m.recorder
}

// QosClassCreate mocks base method
func (m *MockQOSServer) QosClassCreate(arg0 context.Context, arg1 *QosClassRequestMsg) (*QosClassResponseMsg, error) {
	ret := m.ctrl.Call(m, "QosClassCreate", arg0, arg1)
	ret0, _ := ret[0].(*QosClassResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// QosClassCreate indicates an expected call of QosClassCreate
func (mr *MockQOSServerMockRecorder) QosClassCreate(arg0, arg1 interface{}) *gomock.Call {
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "QosClassCreate", reflect.TypeOf((*MockQOSServer)(nil).QosClassCreate), arg0, arg1)
}

// QosClassUpdate mocks base method
func (m *MockQOSServer) QosClassUpdate(arg0 context.Context, arg1 *QosClassRequestMsg) (*QosClassResponseMsg, error) {
	ret := m.ctrl.Call(m, "QosClassUpdate", arg0, arg1)
	ret0, _ := ret[0].(*QosClassResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// QosClassUpdate indicates an expected call of QosClassUpdate
func (mr *MockQOSServerMockRecorder) QosClassUpdate(arg0, arg1 interface{}) *gomock.Call {
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "QosClassUpdate", reflect.TypeOf((*MockQOSServer)(nil).QosClassUpdate), arg0, arg1)
}

// QosClassDelete mocks base method
func (m *MockQOSServer) QosClassDelete(arg0 context.Context, arg1 *QosClassDeleteRequestMsg) (*QosClassDeleteResponseMsg, error) {
	ret := m.ctrl.Call(m, "QosClassDelete", arg0, arg1)
	ret0, _ := ret[0].(*QosClassDeleteResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// QosClassDelete indicates an expected call of QosClassDelete
func (mr *MockQOSServerMockRecorder) QosClassDelete(arg0, arg1 interface{}) *gomock.Call {
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "QosClassDelete", reflect.TypeOf((*MockQOSServer)(nil).QosClassDelete), arg0, arg1)
}

// QosClassGet mocks base method
func (m *MockQOSServer) QosClassGet(arg0 context.Context, arg1 *QosClassGetRequestMsg) (*QosClassGetResponseMsg, error) {
	ret := m.ctrl.Call(m, "QosClassGet", arg0, arg1)
	ret0, _ := ret[0].(*QosClassGetResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// QosClassGet indicates an expected call of QosClassGet
func (mr *MockQOSServerMockRecorder) QosClassGet(arg0, arg1 interface{}) *gomock.Call {
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "QosClassGet", reflect.TypeOf((*MockQOSServer)(nil).QosClassGet), arg0, arg1)
}

// QosClassThresholdsGet mocks base method
func (m *MockQOSServer) QosClassThresholdsGet(arg0 context.Context, arg1 *QosClassThresholdsGetRequestMsg) (*QosClassThresholdsGetResponseMsg, error) {
	ret := m.ctrl.Call(m, "QosClassThresholdsGet", arg0, arg1)
	ret0, _ := ret[0].(*QosClassThresholdsGetResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// QosClassThresholdsGet indicates an expected call of QosClassThresholdsGet
func (mr *MockQOSServerMockRecorder) QosClassThresholdsGet(arg0, arg1 interface{}) *gomock.Call {
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "QosClassThresholdsGet", reflect.TypeOf((*MockQOSServer)(nil).QosClassThresholdsGet), arg0, arg1)
}

// CoppUpdate mocks base method
func (m *MockQOSServer) CoppUpdate(arg0 context.Context, arg1 *CoppRequestMsg) (*CoppResponseMsg, error) {
	ret := m.ctrl.Call(m, "CoppUpdate", arg0, arg1)
	ret0, _ := ret[0].(*CoppResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// CoppUpdate indicates an expected call of CoppUpdate
func (mr *MockQOSServerMockRecorder) CoppUpdate(arg0, arg1 interface{}) *gomock.Call {
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "CoppUpdate", reflect.TypeOf((*MockQOSServer)(nil).CoppUpdate), arg0, arg1)
}

// CoppGet mocks base method
func (m *MockQOSServer) CoppGet(arg0 context.Context, arg1 *CoppGetRequestMsg) (*CoppGetResponseMsg, error) {
	ret := m.ctrl.Call(m, "CoppGet", arg0, arg1)
	ret0, _ := ret[0].(*CoppGetResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// CoppGet indicates an expected call of CoppGet
func (mr *MockQOSServerMockRecorder) CoppGet(arg0, arg1 interface{}) *gomock.Call {
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "CoppGet", reflect.TypeOf((*MockQOSServer)(nil).CoppGet), arg0, arg1)
}
