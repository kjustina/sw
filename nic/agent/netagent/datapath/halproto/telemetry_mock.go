// Code generated by MockGen. DO NOT EDIT.
// Source: telemetry.pb.go

package halproto

import (
	reflect "reflect"

	gomock "github.com/golang/mock/gomock"
	context "golang.org/x/net/context"
	grpc "google.golang.org/grpc"
)

// MockisMirrorSessionSpec_Destination is a mock of isMirrorSessionSpec_Destination interface
type MockisMirrorSessionSpec_Destination struct {
	ctrl     *gomock.Controller
	recorder *MockisMirrorSessionSpec_DestinationMockRecorder
}

// MockisMirrorSessionSpec_DestinationMockRecorder is the mock recorder for MockisMirrorSessionSpec_Destination
type MockisMirrorSessionSpec_DestinationMockRecorder struct {
	mock *MockisMirrorSessionSpec_Destination
}

// NewMockisMirrorSessionSpec_Destination creates a new mock instance
func NewMockisMirrorSessionSpec_Destination(ctrl *gomock.Controller) *MockisMirrorSessionSpec_Destination {
	mock := &MockisMirrorSessionSpec_Destination{ctrl: ctrl}
	mock.recorder = &MockisMirrorSessionSpec_DestinationMockRecorder{mock}
	return mock
}

// EXPECT returns an object that allows the caller to indicate expected use
func (_m *MockisMirrorSessionSpec_Destination) EXPECT() *MockisMirrorSessionSpec_DestinationMockRecorder {
	return _m.recorder
}

// isMirrorSessionSpec_Destination mocks base method
func (_m *MockisMirrorSessionSpec_Destination) isMirrorSessionSpec_Destination() {
	_m.ctrl.Call(_m, "isMirrorSessionSpec_Destination")
}

// isMirrorSessionSpec_Destination indicates an expected call of isMirrorSessionSpec_Destination
func (_mr *MockisMirrorSessionSpec_DestinationMockRecorder) isMirrorSessionSpec_Destination() *gomock.Call {
	return _mr.mock.ctrl.RecordCallWithMethodType(_mr.mock, "isMirrorSessionSpec_Destination", reflect.TypeOf((*MockisMirrorSessionSpec_Destination)(nil).isMirrorSessionSpec_Destination))
}

// MarshalTo mocks base method
func (_m *MockisMirrorSessionSpec_Destination) MarshalTo(_param0 []byte) (int, error) {
	ret := _m.ctrl.Call(_m, "MarshalTo", _param0)
	ret0, _ := ret[0].(int)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// MarshalTo indicates an expected call of MarshalTo
func (_mr *MockisMirrorSessionSpec_DestinationMockRecorder) MarshalTo(arg0 interface{}) *gomock.Call {
	return _mr.mock.ctrl.RecordCallWithMethodType(_mr.mock, "MarshalTo", reflect.TypeOf((*MockisMirrorSessionSpec_Destination)(nil).MarshalTo), arg0)
}

// Size mocks base method
func (_m *MockisMirrorSessionSpec_Destination) Size() int {
	ret := _m.ctrl.Call(_m, "Size")
	ret0, _ := ret[0].(int)
	return ret0
}

// Size indicates an expected call of Size
func (_mr *MockisMirrorSessionSpec_DestinationMockRecorder) Size() *gomock.Call {
	return _mr.mock.ctrl.RecordCallWithMethodType(_mr.mock, "Size", reflect.TypeOf((*MockisMirrorSessionSpec_Destination)(nil).Size))
}

// MockTelemetryClient is a mock of TelemetryClient interface
type MockTelemetryClient struct {
	ctrl     *gomock.Controller
	recorder *MockTelemetryClientMockRecorder
}

// MockTelemetryClientMockRecorder is the mock recorder for MockTelemetryClient
type MockTelemetryClientMockRecorder struct {
	mock *MockTelemetryClient
}

// NewMockTelemetryClient creates a new mock instance
func NewMockTelemetryClient(ctrl *gomock.Controller) *MockTelemetryClient {
	mock := &MockTelemetryClient{ctrl: ctrl}
	mock.recorder = &MockTelemetryClientMockRecorder{mock}
	return mock
}

// EXPECT returns an object that allows the caller to indicate expected use
func (_m *MockTelemetryClient) EXPECT() *MockTelemetryClientMockRecorder {
	return _m.recorder
}

// CollectorCreate mocks base method
func (_m *MockTelemetryClient) CollectorCreate(ctx context.Context, in *CollectorRequestMsg, opts ...grpc.CallOption) (*CollectorResponseMsg, error) {
	_s := []interface{}{ctx, in}
	for _, _x := range opts {
		_s = append(_s, _x)
	}
	ret := _m.ctrl.Call(_m, "CollectorCreate", _s...)
	ret0, _ := ret[0].(*CollectorResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// CollectorCreate indicates an expected call of CollectorCreate
func (_mr *MockTelemetryClientMockRecorder) CollectorCreate(arg0, arg1 interface{}, arg2 ...interface{}) *gomock.Call {
	_s := append([]interface{}{arg0, arg1}, arg2...)
	return _mr.mock.ctrl.RecordCallWithMethodType(_mr.mock, "CollectorCreate", reflect.TypeOf((*MockTelemetryClient)(nil).CollectorCreate), _s...)
}

// CollectorUpdate mocks base method
func (_m *MockTelemetryClient) CollectorUpdate(ctx context.Context, in *CollectorRequestMsg, opts ...grpc.CallOption) (*CollectorResponseMsg, error) {
	_s := []interface{}{ctx, in}
	for _, _x := range opts {
		_s = append(_s, _x)
	}
	ret := _m.ctrl.Call(_m, "CollectorUpdate", _s...)
	ret0, _ := ret[0].(*CollectorResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// CollectorUpdate indicates an expected call of CollectorUpdate
func (_mr *MockTelemetryClientMockRecorder) CollectorUpdate(arg0, arg1 interface{}, arg2 ...interface{}) *gomock.Call {
	_s := append([]interface{}{arg0, arg1}, arg2...)
	return _mr.mock.ctrl.RecordCallWithMethodType(_mr.mock, "CollectorUpdate", reflect.TypeOf((*MockTelemetryClient)(nil).CollectorUpdate), _s...)
}

// CollectorDelete mocks base method
func (_m *MockTelemetryClient) CollectorDelete(ctx context.Context, in *CollectorDeleteRequestMsg, opts ...grpc.CallOption) (*CollectorDeleteResponseMsg, error) {
	_s := []interface{}{ctx, in}
	for _, _x := range opts {
		_s = append(_s, _x)
	}
	ret := _m.ctrl.Call(_m, "CollectorDelete", _s...)
	ret0, _ := ret[0].(*CollectorDeleteResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// CollectorDelete indicates an expected call of CollectorDelete
func (_mr *MockTelemetryClientMockRecorder) CollectorDelete(arg0, arg1 interface{}, arg2 ...interface{}) *gomock.Call {
	_s := append([]interface{}{arg0, arg1}, arg2...)
	return _mr.mock.ctrl.RecordCallWithMethodType(_mr.mock, "CollectorDelete", reflect.TypeOf((*MockTelemetryClient)(nil).CollectorDelete), _s...)
}

// CollectorGet mocks base method
func (_m *MockTelemetryClient) CollectorGet(ctx context.Context, in *CollectorGetRequestMsg, opts ...grpc.CallOption) (*CollectorGetResponseMsg, error) {
	_s := []interface{}{ctx, in}
	for _, _x := range opts {
		_s = append(_s, _x)
	}
	ret := _m.ctrl.Call(_m, "CollectorGet", _s...)
	ret0, _ := ret[0].(*CollectorGetResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// CollectorGet indicates an expected call of CollectorGet
func (_mr *MockTelemetryClientMockRecorder) CollectorGet(arg0, arg1 interface{}, arg2 ...interface{}) *gomock.Call {
	_s := append([]interface{}{arg0, arg1}, arg2...)
	return _mr.mock.ctrl.RecordCallWithMethodType(_mr.mock, "CollectorGet", reflect.TypeOf((*MockTelemetryClient)(nil).CollectorGet), _s...)
}

// ExportControlCreate mocks base method
func (_m *MockTelemetryClient) ExportControlCreate(ctx context.Context, in *ExportControlRequestMsg, opts ...grpc.CallOption) (*ExportControlResponseMsg, error) {
	_s := []interface{}{ctx, in}
	for _, _x := range opts {
		_s = append(_s, _x)
	}
	ret := _m.ctrl.Call(_m, "ExportControlCreate", _s...)
	ret0, _ := ret[0].(*ExportControlResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// ExportControlCreate indicates an expected call of ExportControlCreate
func (_mr *MockTelemetryClientMockRecorder) ExportControlCreate(arg0, arg1 interface{}, arg2 ...interface{}) *gomock.Call {
	_s := append([]interface{}{arg0, arg1}, arg2...)
	return _mr.mock.ctrl.RecordCallWithMethodType(_mr.mock, "ExportControlCreate", reflect.TypeOf((*MockTelemetryClient)(nil).ExportControlCreate), _s...)
}

// ExportControlUpdate mocks base method
func (_m *MockTelemetryClient) ExportControlUpdate(ctx context.Context, in *ExportControlRequestMsg, opts ...grpc.CallOption) (*ExportControlResponseMsg, error) {
	_s := []interface{}{ctx, in}
	for _, _x := range opts {
		_s = append(_s, _x)
	}
	ret := _m.ctrl.Call(_m, "ExportControlUpdate", _s...)
	ret0, _ := ret[0].(*ExportControlResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// ExportControlUpdate indicates an expected call of ExportControlUpdate
func (_mr *MockTelemetryClientMockRecorder) ExportControlUpdate(arg0, arg1 interface{}, arg2 ...interface{}) *gomock.Call {
	_s := append([]interface{}{arg0, arg1}, arg2...)
	return _mr.mock.ctrl.RecordCallWithMethodType(_mr.mock, "ExportControlUpdate", reflect.TypeOf((*MockTelemetryClient)(nil).ExportControlUpdate), _s...)
}

// ExportControlDelete mocks base method
func (_m *MockTelemetryClient) ExportControlDelete(ctx context.Context, in *ExportControlDeleteRequestMsg, opts ...grpc.CallOption) (*ExportControlDeleteResponseMsg, error) {
	_s := []interface{}{ctx, in}
	for _, _x := range opts {
		_s = append(_s, _x)
	}
	ret := _m.ctrl.Call(_m, "ExportControlDelete", _s...)
	ret0, _ := ret[0].(*ExportControlDeleteResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// ExportControlDelete indicates an expected call of ExportControlDelete
func (_mr *MockTelemetryClientMockRecorder) ExportControlDelete(arg0, arg1 interface{}, arg2 ...interface{}) *gomock.Call {
	_s := append([]interface{}{arg0, arg1}, arg2...)
	return _mr.mock.ctrl.RecordCallWithMethodType(_mr.mock, "ExportControlDelete", reflect.TypeOf((*MockTelemetryClient)(nil).ExportControlDelete), _s...)
}

// ExportControlGet mocks base method
func (_m *MockTelemetryClient) ExportControlGet(ctx context.Context, in *ExportControlGetRequestMsg, opts ...grpc.CallOption) (*ExportControlGetResponseMsg, error) {
	_s := []interface{}{ctx, in}
	for _, _x := range opts {
		_s = append(_s, _x)
	}
	ret := _m.ctrl.Call(_m, "ExportControlGet", _s...)
	ret0, _ := ret[0].(*ExportControlGetResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// ExportControlGet indicates an expected call of ExportControlGet
func (_mr *MockTelemetryClientMockRecorder) ExportControlGet(arg0, arg1 interface{}, arg2 ...interface{}) *gomock.Call {
	_s := append([]interface{}{arg0, arg1}, arg2...)
	return _mr.mock.ctrl.RecordCallWithMethodType(_mr.mock, "ExportControlGet", reflect.TypeOf((*MockTelemetryClient)(nil).ExportControlGet), _s...)
}

// FlowMonitorRuleCreate mocks base method
func (_m *MockTelemetryClient) FlowMonitorRuleCreate(ctx context.Context, in *FlowMonitorRuleRequestMsg, opts ...grpc.CallOption) (*FlowMonitorRuleResponseMsg, error) {
	_s := []interface{}{ctx, in}
	for _, _x := range opts {
		_s = append(_s, _x)
	}
	ret := _m.ctrl.Call(_m, "FlowMonitorRuleCreate", _s...)
	ret0, _ := ret[0].(*FlowMonitorRuleResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// FlowMonitorRuleCreate indicates an expected call of FlowMonitorRuleCreate
func (_mr *MockTelemetryClientMockRecorder) FlowMonitorRuleCreate(arg0, arg1 interface{}, arg2 ...interface{}) *gomock.Call {
	_s := append([]interface{}{arg0, arg1}, arg2...)
	return _mr.mock.ctrl.RecordCallWithMethodType(_mr.mock, "FlowMonitorRuleCreate", reflect.TypeOf((*MockTelemetryClient)(nil).FlowMonitorRuleCreate), _s...)
}

// FlowMonitorRuleUpdate mocks base method
func (_m *MockTelemetryClient) FlowMonitorRuleUpdate(ctx context.Context, in *FlowMonitorRuleRequestMsg, opts ...grpc.CallOption) (*FlowMonitorRuleResponseMsg, error) {
	_s := []interface{}{ctx, in}
	for _, _x := range opts {
		_s = append(_s, _x)
	}
	ret := _m.ctrl.Call(_m, "FlowMonitorRuleUpdate", _s...)
	ret0, _ := ret[0].(*FlowMonitorRuleResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// FlowMonitorRuleUpdate indicates an expected call of FlowMonitorRuleUpdate
func (_mr *MockTelemetryClientMockRecorder) FlowMonitorRuleUpdate(arg0, arg1 interface{}, arg2 ...interface{}) *gomock.Call {
	_s := append([]interface{}{arg0, arg1}, arg2...)
	return _mr.mock.ctrl.RecordCallWithMethodType(_mr.mock, "FlowMonitorRuleUpdate", reflect.TypeOf((*MockTelemetryClient)(nil).FlowMonitorRuleUpdate), _s...)
}

// FlowMonitorRuleDelete mocks base method
func (_m *MockTelemetryClient) FlowMonitorRuleDelete(ctx context.Context, in *FlowMonitorRuleDeleteRequestMsg, opts ...grpc.CallOption) (*FlowMonitorRuleDeleteResponseMsg, error) {
	_s := []interface{}{ctx, in}
	for _, _x := range opts {
		_s = append(_s, _x)
	}
	ret := _m.ctrl.Call(_m, "FlowMonitorRuleDelete", _s...)
	ret0, _ := ret[0].(*FlowMonitorRuleDeleteResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// FlowMonitorRuleDelete indicates an expected call of FlowMonitorRuleDelete
func (_mr *MockTelemetryClientMockRecorder) FlowMonitorRuleDelete(arg0, arg1 interface{}, arg2 ...interface{}) *gomock.Call {
	_s := append([]interface{}{arg0, arg1}, arg2...)
	return _mr.mock.ctrl.RecordCallWithMethodType(_mr.mock, "FlowMonitorRuleDelete", reflect.TypeOf((*MockTelemetryClient)(nil).FlowMonitorRuleDelete), _s...)
}

// FlowMonitorRuleGet mocks base method
func (_m *MockTelemetryClient) FlowMonitorRuleGet(ctx context.Context, in *FlowMonitorRuleGetRequestMsg, opts ...grpc.CallOption) (*FlowMonitorRuleGetResponseMsg, error) {
	_s := []interface{}{ctx, in}
	for _, _x := range opts {
		_s = append(_s, _x)
	}
	ret := _m.ctrl.Call(_m, "FlowMonitorRuleGet", _s...)
	ret0, _ := ret[0].(*FlowMonitorRuleGetResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// FlowMonitorRuleGet indicates an expected call of FlowMonitorRuleGet
func (_mr *MockTelemetryClientMockRecorder) FlowMonitorRuleGet(arg0, arg1 interface{}, arg2 ...interface{}) *gomock.Call {
	_s := append([]interface{}{arg0, arg1}, arg2...)
	return _mr.mock.ctrl.RecordCallWithMethodType(_mr.mock, "FlowMonitorRuleGet", reflect.TypeOf((*MockTelemetryClient)(nil).FlowMonitorRuleGet), _s...)
}

// DropMonitorRuleCreate mocks base method
func (_m *MockTelemetryClient) DropMonitorRuleCreate(ctx context.Context, in *DropMonitorRuleRequestMsg, opts ...grpc.CallOption) (*DropMonitorRuleResponseMsg, error) {
	_s := []interface{}{ctx, in}
	for _, _x := range opts {
		_s = append(_s, _x)
	}
	ret := _m.ctrl.Call(_m, "DropMonitorRuleCreate", _s...)
	ret0, _ := ret[0].(*DropMonitorRuleResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// DropMonitorRuleCreate indicates an expected call of DropMonitorRuleCreate
func (_mr *MockTelemetryClientMockRecorder) DropMonitorRuleCreate(arg0, arg1 interface{}, arg2 ...interface{}) *gomock.Call {
	_s := append([]interface{}{arg0, arg1}, arg2...)
	return _mr.mock.ctrl.RecordCallWithMethodType(_mr.mock, "DropMonitorRuleCreate", reflect.TypeOf((*MockTelemetryClient)(nil).DropMonitorRuleCreate), _s...)
}

// DropMonitorRuleUpdate mocks base method
func (_m *MockTelemetryClient) DropMonitorRuleUpdate(ctx context.Context, in *DropMonitorRuleRequestMsg, opts ...grpc.CallOption) (*DropMonitorRuleResponseMsg, error) {
	_s := []interface{}{ctx, in}
	for _, _x := range opts {
		_s = append(_s, _x)
	}
	ret := _m.ctrl.Call(_m, "DropMonitorRuleUpdate", _s...)
	ret0, _ := ret[0].(*DropMonitorRuleResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// DropMonitorRuleUpdate indicates an expected call of DropMonitorRuleUpdate
func (_mr *MockTelemetryClientMockRecorder) DropMonitorRuleUpdate(arg0, arg1 interface{}, arg2 ...interface{}) *gomock.Call {
	_s := append([]interface{}{arg0, arg1}, arg2...)
	return _mr.mock.ctrl.RecordCallWithMethodType(_mr.mock, "DropMonitorRuleUpdate", reflect.TypeOf((*MockTelemetryClient)(nil).DropMonitorRuleUpdate), _s...)
}

// DropMonitorRuleDelete mocks base method
func (_m *MockTelemetryClient) DropMonitorRuleDelete(ctx context.Context, in *DropMonitorRuleDeleteRequestMsg, opts ...grpc.CallOption) (*DropMonitorRuleDeleteResponseMsg, error) {
	_s := []interface{}{ctx, in}
	for _, _x := range opts {
		_s = append(_s, _x)
	}
	ret := _m.ctrl.Call(_m, "DropMonitorRuleDelete", _s...)
	ret0, _ := ret[0].(*DropMonitorRuleDeleteResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// DropMonitorRuleDelete indicates an expected call of DropMonitorRuleDelete
func (_mr *MockTelemetryClientMockRecorder) DropMonitorRuleDelete(arg0, arg1 interface{}, arg2 ...interface{}) *gomock.Call {
	_s := append([]interface{}{arg0, arg1}, arg2...)
	return _mr.mock.ctrl.RecordCallWithMethodType(_mr.mock, "DropMonitorRuleDelete", reflect.TypeOf((*MockTelemetryClient)(nil).DropMonitorRuleDelete), _s...)
}

// DropMonitorRuleGet mocks base method
func (_m *MockTelemetryClient) DropMonitorRuleGet(ctx context.Context, in *DropMonitorRuleGetRequestMsg, opts ...grpc.CallOption) (*DropMonitorRuleGetResponseMsg, error) {
	_s := []interface{}{ctx, in}
	for _, _x := range opts {
		_s = append(_s, _x)
	}
	ret := _m.ctrl.Call(_m, "DropMonitorRuleGet", _s...)
	ret0, _ := ret[0].(*DropMonitorRuleGetResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// DropMonitorRuleGet indicates an expected call of DropMonitorRuleGet
func (_mr *MockTelemetryClientMockRecorder) DropMonitorRuleGet(arg0, arg1 interface{}, arg2 ...interface{}) *gomock.Call {
	_s := append([]interface{}{arg0, arg1}, arg2...)
	return _mr.mock.ctrl.RecordCallWithMethodType(_mr.mock, "DropMonitorRuleGet", reflect.TypeOf((*MockTelemetryClient)(nil).DropMonitorRuleGet), _s...)
}

// MirrorSessionCreate mocks base method
func (_m *MockTelemetryClient) MirrorSessionCreate(ctx context.Context, in *MirrorSessionRequestMsg, opts ...grpc.CallOption) (*MirrorSessionResponseMsg, error) {
	_s := []interface{}{ctx, in}
	for _, _x := range opts {
		_s = append(_s, _x)
	}
	ret := _m.ctrl.Call(_m, "MirrorSessionCreate", _s...)
	ret0, _ := ret[0].(*MirrorSessionResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// MirrorSessionCreate indicates an expected call of MirrorSessionCreate
func (_mr *MockTelemetryClientMockRecorder) MirrorSessionCreate(arg0, arg1 interface{}, arg2 ...interface{}) *gomock.Call {
	_s := append([]interface{}{arg0, arg1}, arg2...)
	return _mr.mock.ctrl.RecordCallWithMethodType(_mr.mock, "MirrorSessionCreate", reflect.TypeOf((*MockTelemetryClient)(nil).MirrorSessionCreate), _s...)
}

// MirrorSessionUpdate mocks base method
func (_m *MockTelemetryClient) MirrorSessionUpdate(ctx context.Context, in *MirrorSessionRequestMsg, opts ...grpc.CallOption) (*MirrorSessionResponseMsg, error) {
	_s := []interface{}{ctx, in}
	for _, _x := range opts {
		_s = append(_s, _x)
	}
	ret := _m.ctrl.Call(_m, "MirrorSessionUpdate", _s...)
	ret0, _ := ret[0].(*MirrorSessionResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// MirrorSessionUpdate indicates an expected call of MirrorSessionUpdate
func (_mr *MockTelemetryClientMockRecorder) MirrorSessionUpdate(arg0, arg1 interface{}, arg2 ...interface{}) *gomock.Call {
	_s := append([]interface{}{arg0, arg1}, arg2...)
	return _mr.mock.ctrl.RecordCallWithMethodType(_mr.mock, "MirrorSessionUpdate", reflect.TypeOf((*MockTelemetryClient)(nil).MirrorSessionUpdate), _s...)
}

// MirrorSessionDelete mocks base method
func (_m *MockTelemetryClient) MirrorSessionDelete(ctx context.Context, in *MirrorSessionDeleteRequestMsg, opts ...grpc.CallOption) (*MirrorSessionDeleteResponseMsg, error) {
	_s := []interface{}{ctx, in}
	for _, _x := range opts {
		_s = append(_s, _x)
	}
	ret := _m.ctrl.Call(_m, "MirrorSessionDelete", _s...)
	ret0, _ := ret[0].(*MirrorSessionDeleteResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// MirrorSessionDelete indicates an expected call of MirrorSessionDelete
func (_mr *MockTelemetryClientMockRecorder) MirrorSessionDelete(arg0, arg1 interface{}, arg2 ...interface{}) *gomock.Call {
	_s := append([]interface{}{arg0, arg1}, arg2...)
	return _mr.mock.ctrl.RecordCallWithMethodType(_mr.mock, "MirrorSessionDelete", reflect.TypeOf((*MockTelemetryClient)(nil).MirrorSessionDelete), _s...)
}

// MirrorSessionGet mocks base method
func (_m *MockTelemetryClient) MirrorSessionGet(ctx context.Context, in *MirrorSessionGetRequestMsg, opts ...grpc.CallOption) (*MirrorSessionGetResponseMsg, error) {
	_s := []interface{}{ctx, in}
	for _, _x := range opts {
		_s = append(_s, _x)
	}
	ret := _m.ctrl.Call(_m, "MirrorSessionGet", _s...)
	ret0, _ := ret[0].(*MirrorSessionGetResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// MirrorSessionGet indicates an expected call of MirrorSessionGet
func (_mr *MockTelemetryClientMockRecorder) MirrorSessionGet(arg0, arg1 interface{}, arg2 ...interface{}) *gomock.Call {
	_s := append([]interface{}{arg0, arg1}, arg2...)
	return _mr.mock.ctrl.RecordCallWithMethodType(_mr.mock, "MirrorSessionGet", reflect.TypeOf((*MockTelemetryClient)(nil).MirrorSessionGet), _s...)
}

// MockTelemetryServer is a mock of TelemetryServer interface
type MockTelemetryServer struct {
	ctrl     *gomock.Controller
	recorder *MockTelemetryServerMockRecorder
}

// MockTelemetryServerMockRecorder is the mock recorder for MockTelemetryServer
type MockTelemetryServerMockRecorder struct {
	mock *MockTelemetryServer
}

// NewMockTelemetryServer creates a new mock instance
func NewMockTelemetryServer(ctrl *gomock.Controller) *MockTelemetryServer {
	mock := &MockTelemetryServer{ctrl: ctrl}
	mock.recorder = &MockTelemetryServerMockRecorder{mock}
	return mock
}

// EXPECT returns an object that allows the caller to indicate expected use
func (_m *MockTelemetryServer) EXPECT() *MockTelemetryServerMockRecorder {
	return _m.recorder
}

// CollectorCreate mocks base method
func (_m *MockTelemetryServer) CollectorCreate(_param0 context.Context, _param1 *CollectorRequestMsg) (*CollectorResponseMsg, error) {
	ret := _m.ctrl.Call(_m, "CollectorCreate", _param0, _param1)
	ret0, _ := ret[0].(*CollectorResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// CollectorCreate indicates an expected call of CollectorCreate
func (_mr *MockTelemetryServerMockRecorder) CollectorCreate(arg0, arg1 interface{}) *gomock.Call {
	return _mr.mock.ctrl.RecordCallWithMethodType(_mr.mock, "CollectorCreate", reflect.TypeOf((*MockTelemetryServer)(nil).CollectorCreate), arg0, arg1)
}

// CollectorUpdate mocks base method
func (_m *MockTelemetryServer) CollectorUpdate(_param0 context.Context, _param1 *CollectorRequestMsg) (*CollectorResponseMsg, error) {
	ret := _m.ctrl.Call(_m, "CollectorUpdate", _param0, _param1)
	ret0, _ := ret[0].(*CollectorResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// CollectorUpdate indicates an expected call of CollectorUpdate
func (_mr *MockTelemetryServerMockRecorder) CollectorUpdate(arg0, arg1 interface{}) *gomock.Call {
	return _mr.mock.ctrl.RecordCallWithMethodType(_mr.mock, "CollectorUpdate", reflect.TypeOf((*MockTelemetryServer)(nil).CollectorUpdate), arg0, arg1)
}

// CollectorDelete mocks base method
func (_m *MockTelemetryServer) CollectorDelete(_param0 context.Context, _param1 *CollectorDeleteRequestMsg) (*CollectorDeleteResponseMsg, error) {
	ret := _m.ctrl.Call(_m, "CollectorDelete", _param0, _param1)
	ret0, _ := ret[0].(*CollectorDeleteResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// CollectorDelete indicates an expected call of CollectorDelete
func (_mr *MockTelemetryServerMockRecorder) CollectorDelete(arg0, arg1 interface{}) *gomock.Call {
	return _mr.mock.ctrl.RecordCallWithMethodType(_mr.mock, "CollectorDelete", reflect.TypeOf((*MockTelemetryServer)(nil).CollectorDelete), arg0, arg1)
}

// CollectorGet mocks base method
func (_m *MockTelemetryServer) CollectorGet(_param0 context.Context, _param1 *CollectorGetRequestMsg) (*CollectorGetResponseMsg, error) {
	ret := _m.ctrl.Call(_m, "CollectorGet", _param0, _param1)
	ret0, _ := ret[0].(*CollectorGetResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// CollectorGet indicates an expected call of CollectorGet
func (_mr *MockTelemetryServerMockRecorder) CollectorGet(arg0, arg1 interface{}) *gomock.Call {
	return _mr.mock.ctrl.RecordCallWithMethodType(_mr.mock, "CollectorGet", reflect.TypeOf((*MockTelemetryServer)(nil).CollectorGet), arg0, arg1)
}

// ExportControlCreate mocks base method
func (_m *MockTelemetryServer) ExportControlCreate(_param0 context.Context, _param1 *ExportControlRequestMsg) (*ExportControlResponseMsg, error) {
	ret := _m.ctrl.Call(_m, "ExportControlCreate", _param0, _param1)
	ret0, _ := ret[0].(*ExportControlResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// ExportControlCreate indicates an expected call of ExportControlCreate
func (_mr *MockTelemetryServerMockRecorder) ExportControlCreate(arg0, arg1 interface{}) *gomock.Call {
	return _mr.mock.ctrl.RecordCallWithMethodType(_mr.mock, "ExportControlCreate", reflect.TypeOf((*MockTelemetryServer)(nil).ExportControlCreate), arg0, arg1)
}

// ExportControlUpdate mocks base method
func (_m *MockTelemetryServer) ExportControlUpdate(_param0 context.Context, _param1 *ExportControlRequestMsg) (*ExportControlResponseMsg, error) {
	ret := _m.ctrl.Call(_m, "ExportControlUpdate", _param0, _param1)
	ret0, _ := ret[0].(*ExportControlResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// ExportControlUpdate indicates an expected call of ExportControlUpdate
func (_mr *MockTelemetryServerMockRecorder) ExportControlUpdate(arg0, arg1 interface{}) *gomock.Call {
	return _mr.mock.ctrl.RecordCallWithMethodType(_mr.mock, "ExportControlUpdate", reflect.TypeOf((*MockTelemetryServer)(nil).ExportControlUpdate), arg0, arg1)
}

// ExportControlDelete mocks base method
func (_m *MockTelemetryServer) ExportControlDelete(_param0 context.Context, _param1 *ExportControlDeleteRequestMsg) (*ExportControlDeleteResponseMsg, error) {
	ret := _m.ctrl.Call(_m, "ExportControlDelete", _param0, _param1)
	ret0, _ := ret[0].(*ExportControlDeleteResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// ExportControlDelete indicates an expected call of ExportControlDelete
func (_mr *MockTelemetryServerMockRecorder) ExportControlDelete(arg0, arg1 interface{}) *gomock.Call {
	return _mr.mock.ctrl.RecordCallWithMethodType(_mr.mock, "ExportControlDelete", reflect.TypeOf((*MockTelemetryServer)(nil).ExportControlDelete), arg0, arg1)
}

// ExportControlGet mocks base method
func (_m *MockTelemetryServer) ExportControlGet(_param0 context.Context, _param1 *ExportControlGetRequestMsg) (*ExportControlGetResponseMsg, error) {
	ret := _m.ctrl.Call(_m, "ExportControlGet", _param0, _param1)
	ret0, _ := ret[0].(*ExportControlGetResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// ExportControlGet indicates an expected call of ExportControlGet
func (_mr *MockTelemetryServerMockRecorder) ExportControlGet(arg0, arg1 interface{}) *gomock.Call {
	return _mr.mock.ctrl.RecordCallWithMethodType(_mr.mock, "ExportControlGet", reflect.TypeOf((*MockTelemetryServer)(nil).ExportControlGet), arg0, arg1)
}

// FlowMonitorRuleCreate mocks base method
func (_m *MockTelemetryServer) FlowMonitorRuleCreate(_param0 context.Context, _param1 *FlowMonitorRuleRequestMsg) (*FlowMonitorRuleResponseMsg, error) {
	ret := _m.ctrl.Call(_m, "FlowMonitorRuleCreate", _param0, _param1)
	ret0, _ := ret[0].(*FlowMonitorRuleResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// FlowMonitorRuleCreate indicates an expected call of FlowMonitorRuleCreate
func (_mr *MockTelemetryServerMockRecorder) FlowMonitorRuleCreate(arg0, arg1 interface{}) *gomock.Call {
	return _mr.mock.ctrl.RecordCallWithMethodType(_mr.mock, "FlowMonitorRuleCreate", reflect.TypeOf((*MockTelemetryServer)(nil).FlowMonitorRuleCreate), arg0, arg1)
}

// FlowMonitorRuleUpdate mocks base method
func (_m *MockTelemetryServer) FlowMonitorRuleUpdate(_param0 context.Context, _param1 *FlowMonitorRuleRequestMsg) (*FlowMonitorRuleResponseMsg, error) {
	ret := _m.ctrl.Call(_m, "FlowMonitorRuleUpdate", _param0, _param1)
	ret0, _ := ret[0].(*FlowMonitorRuleResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// FlowMonitorRuleUpdate indicates an expected call of FlowMonitorRuleUpdate
func (_mr *MockTelemetryServerMockRecorder) FlowMonitorRuleUpdate(arg0, arg1 interface{}) *gomock.Call {
	return _mr.mock.ctrl.RecordCallWithMethodType(_mr.mock, "FlowMonitorRuleUpdate", reflect.TypeOf((*MockTelemetryServer)(nil).FlowMonitorRuleUpdate), arg0, arg1)
}

// FlowMonitorRuleDelete mocks base method
func (_m *MockTelemetryServer) FlowMonitorRuleDelete(_param0 context.Context, _param1 *FlowMonitorRuleDeleteRequestMsg) (*FlowMonitorRuleDeleteResponseMsg, error) {
	ret := _m.ctrl.Call(_m, "FlowMonitorRuleDelete", _param0, _param1)
	ret0, _ := ret[0].(*FlowMonitorRuleDeleteResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// FlowMonitorRuleDelete indicates an expected call of FlowMonitorRuleDelete
func (_mr *MockTelemetryServerMockRecorder) FlowMonitorRuleDelete(arg0, arg1 interface{}) *gomock.Call {
	return _mr.mock.ctrl.RecordCallWithMethodType(_mr.mock, "FlowMonitorRuleDelete", reflect.TypeOf((*MockTelemetryServer)(nil).FlowMonitorRuleDelete), arg0, arg1)
}

// FlowMonitorRuleGet mocks base method
func (_m *MockTelemetryServer) FlowMonitorRuleGet(_param0 context.Context, _param1 *FlowMonitorRuleGetRequestMsg) (*FlowMonitorRuleGetResponseMsg, error) {
	ret := _m.ctrl.Call(_m, "FlowMonitorRuleGet", _param0, _param1)
	ret0, _ := ret[0].(*FlowMonitorRuleGetResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// FlowMonitorRuleGet indicates an expected call of FlowMonitorRuleGet
func (_mr *MockTelemetryServerMockRecorder) FlowMonitorRuleGet(arg0, arg1 interface{}) *gomock.Call {
	return _mr.mock.ctrl.RecordCallWithMethodType(_mr.mock, "FlowMonitorRuleGet", reflect.TypeOf((*MockTelemetryServer)(nil).FlowMonitorRuleGet), arg0, arg1)
}

// DropMonitorRuleCreate mocks base method
func (_m *MockTelemetryServer) DropMonitorRuleCreate(_param0 context.Context, _param1 *DropMonitorRuleRequestMsg) (*DropMonitorRuleResponseMsg, error) {
	ret := _m.ctrl.Call(_m, "DropMonitorRuleCreate", _param0, _param1)
	ret0, _ := ret[0].(*DropMonitorRuleResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// DropMonitorRuleCreate indicates an expected call of DropMonitorRuleCreate
func (_mr *MockTelemetryServerMockRecorder) DropMonitorRuleCreate(arg0, arg1 interface{}) *gomock.Call {
	return _mr.mock.ctrl.RecordCallWithMethodType(_mr.mock, "DropMonitorRuleCreate", reflect.TypeOf((*MockTelemetryServer)(nil).DropMonitorRuleCreate), arg0, arg1)
}

// DropMonitorRuleUpdate mocks base method
func (_m *MockTelemetryServer) DropMonitorRuleUpdate(_param0 context.Context, _param1 *DropMonitorRuleRequestMsg) (*DropMonitorRuleResponseMsg, error) {
	ret := _m.ctrl.Call(_m, "DropMonitorRuleUpdate", _param0, _param1)
	ret0, _ := ret[0].(*DropMonitorRuleResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// DropMonitorRuleUpdate indicates an expected call of DropMonitorRuleUpdate
func (_mr *MockTelemetryServerMockRecorder) DropMonitorRuleUpdate(arg0, arg1 interface{}) *gomock.Call {
	return _mr.mock.ctrl.RecordCallWithMethodType(_mr.mock, "DropMonitorRuleUpdate", reflect.TypeOf((*MockTelemetryServer)(nil).DropMonitorRuleUpdate), arg0, arg1)
}

// DropMonitorRuleDelete mocks base method
func (_m *MockTelemetryServer) DropMonitorRuleDelete(_param0 context.Context, _param1 *DropMonitorRuleDeleteRequestMsg) (*DropMonitorRuleDeleteResponseMsg, error) {
	ret := _m.ctrl.Call(_m, "DropMonitorRuleDelete", _param0, _param1)
	ret0, _ := ret[0].(*DropMonitorRuleDeleteResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// DropMonitorRuleDelete indicates an expected call of DropMonitorRuleDelete
func (_mr *MockTelemetryServerMockRecorder) DropMonitorRuleDelete(arg0, arg1 interface{}) *gomock.Call {
	return _mr.mock.ctrl.RecordCallWithMethodType(_mr.mock, "DropMonitorRuleDelete", reflect.TypeOf((*MockTelemetryServer)(nil).DropMonitorRuleDelete), arg0, arg1)
}

// DropMonitorRuleGet mocks base method
func (_m *MockTelemetryServer) DropMonitorRuleGet(_param0 context.Context, _param1 *DropMonitorRuleGetRequestMsg) (*DropMonitorRuleGetResponseMsg, error) {
	ret := _m.ctrl.Call(_m, "DropMonitorRuleGet", _param0, _param1)
	ret0, _ := ret[0].(*DropMonitorRuleGetResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// DropMonitorRuleGet indicates an expected call of DropMonitorRuleGet
func (_mr *MockTelemetryServerMockRecorder) DropMonitorRuleGet(arg0, arg1 interface{}) *gomock.Call {
	return _mr.mock.ctrl.RecordCallWithMethodType(_mr.mock, "DropMonitorRuleGet", reflect.TypeOf((*MockTelemetryServer)(nil).DropMonitorRuleGet), arg0, arg1)
}

// MirrorSessionCreate mocks base method
func (_m *MockTelemetryServer) MirrorSessionCreate(_param0 context.Context, _param1 *MirrorSessionRequestMsg) (*MirrorSessionResponseMsg, error) {
	ret := _m.ctrl.Call(_m, "MirrorSessionCreate", _param0, _param1)
	ret0, _ := ret[0].(*MirrorSessionResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// MirrorSessionCreate indicates an expected call of MirrorSessionCreate
func (_mr *MockTelemetryServerMockRecorder) MirrorSessionCreate(arg0, arg1 interface{}) *gomock.Call {
	return _mr.mock.ctrl.RecordCallWithMethodType(_mr.mock, "MirrorSessionCreate", reflect.TypeOf((*MockTelemetryServer)(nil).MirrorSessionCreate), arg0, arg1)
}

// MirrorSessionUpdate mocks base method
func (_m *MockTelemetryServer) MirrorSessionUpdate(_param0 context.Context, _param1 *MirrorSessionRequestMsg) (*MirrorSessionResponseMsg, error) {
	ret := _m.ctrl.Call(_m, "MirrorSessionUpdate", _param0, _param1)
	ret0, _ := ret[0].(*MirrorSessionResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// MirrorSessionUpdate indicates an expected call of MirrorSessionUpdate
func (_mr *MockTelemetryServerMockRecorder) MirrorSessionUpdate(arg0, arg1 interface{}) *gomock.Call {
	return _mr.mock.ctrl.RecordCallWithMethodType(_mr.mock, "MirrorSessionUpdate", reflect.TypeOf((*MockTelemetryServer)(nil).MirrorSessionUpdate), arg0, arg1)
}

// MirrorSessionDelete mocks base method
func (_m *MockTelemetryServer) MirrorSessionDelete(_param0 context.Context, _param1 *MirrorSessionDeleteRequestMsg) (*MirrorSessionDeleteResponseMsg, error) {
	ret := _m.ctrl.Call(_m, "MirrorSessionDelete", _param0, _param1)
	ret0, _ := ret[0].(*MirrorSessionDeleteResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// MirrorSessionDelete indicates an expected call of MirrorSessionDelete
func (_mr *MockTelemetryServerMockRecorder) MirrorSessionDelete(arg0, arg1 interface{}) *gomock.Call {
	return _mr.mock.ctrl.RecordCallWithMethodType(_mr.mock, "MirrorSessionDelete", reflect.TypeOf((*MockTelemetryServer)(nil).MirrorSessionDelete), arg0, arg1)
}

// MirrorSessionGet mocks base method
func (_m *MockTelemetryServer) MirrorSessionGet(_param0 context.Context, _param1 *MirrorSessionGetRequestMsg) (*MirrorSessionGetResponseMsg, error) {
	ret := _m.ctrl.Call(_m, "MirrorSessionGet", _param0, _param1)
	ret0, _ := ret[0].(*MirrorSessionGetResponseMsg)
	ret1, _ := ret[1].(error)
	return ret0, ret1
}

// MirrorSessionGet indicates an expected call of MirrorSessionGet
func (_mr *MockTelemetryServerMockRecorder) MirrorSessionGet(arg0, arg1 interface{}) *gomock.Call {
	return _mr.mock.ctrl.RecordCallWithMethodType(_mr.mock, "MirrorSessionGet", reflect.TypeOf((*MockTelemetryServer)(nil).MirrorSessionGet), arg0, arg1)
}
