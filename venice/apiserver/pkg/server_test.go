package apisrvpkg

import (
	"bytes"
	"context"
	"errors"
	"strings"
	"testing"
	"time"

	apisrv "github.com/pensando/sw/venice/apiserver"
	"github.com/pensando/sw/venice/utils/kvstore/store"
	"github.com/pensando/sw/venice/utils/log"
	"github.com/pensando/sw/venice/utils/rpckit"
	"github.com/pensando/sw/venice/utils/runtime"
)

type testAPISrvBackend struct {
	regevents int
}

func (t *testAPISrvBackend) CompleteRegistration(ctx context.Context,
	logger log.Logger, grpcserver *rpckit.RPCServer, scheme *runtime.Scheme) error {
	t.regevents = t.regevents + 1
	return nil
}

type testAPISrvService struct {
	hookcbCalled int
}

func (t *testAPISrvService) hooksCb(srv apisrv.Service, logger log.Logger) {
	t.hookcbCalled++
}

func (t *testAPISrvService) Enable()                          {}
func (t *testAPISrvService) Disable()                         {}
func (t *testAPISrvService) GetMethod(n string) apisrv.Method { return nil }
func (t *testAPISrvService) GetCrudService(in string, oper apisrv.APIOperType) apisrv.Method {
	return nil
}
func (t *testAPISrvService) AddMethod(n string, m apisrv.Method) apisrv.Method { return nil }

func TestRegistration(t *testing.T) {
	// Parallel is not needed since init happens in a single thread.
	// Make sure to initialize the singleton.
	_ = MustGetAPIServer()
	a := &singletonAPISrv
	s := testAPISrvBackend{}
	s1 := testAPISrvBackend{}
	a.Register("register-test1", &s)
	a.Register("register-test2", &s1)
	if len(a.svcmap) != 2 {
		t.Errorf("Mismatched number of registered services Want 2 found [%v]", len(a.svcmap))
	}

	for name := range a.svcmap {
		if name != "register-test1" && name != "register-test2" {
			t.Errorf("invalid name %s", name)
		}
	}

	srv1 := testAPISrvService{}
	a.RegisterService("test-service", &srv1)
	s2 := a.GetService("test-service")
	if s2 == nil || s2 != &srv1 {
		t.Errorf("could not retrieve registered service")
	}

	m1 := newFakeMessage("", true)
	m2 := newFakeMessage("", true)
	msgs := make(map[string]apisrv.Message)
	msgs["msg1"] = m1
	msgs["msg2"] = m2
	a.RegisterMessages("test-service", msgs)
	if len(a.messages) != 2 {
		t.Errorf("incorrect number of messages expected[2] found [%d]", len(a.messages))
	}

}

func TestDupRegistration(t *testing.T) {
	// Make sure to initialize the singleton.
	_ = MustGetAPIServer()
	a := &singletonAPISrv
	s := testAPISrvBackend{}
	defer func() {
		if r := recover(); r == nil {
			t.Errorf("Expecting panic but did not")
		}
	}()
	a.Register("dup-test1", &s)
	a.Register("dup-test1", &s)
}

func TestDupPathRegistration(t *testing.T) {
	// Make sure to initialize the singleton.
	_ = MustGetAPIServer()
	a := &singletonAPISrv
	s := testAPISrvBackend{}

	// This is allowed and should not panic
	a.Register("duppath-test1", &s)
	a.Register("duppath-test2", &s)
}

// TestInitOnce
// Tests that multiple MustGetAPIServer initializes the singleton only once.
func TestInitOnce(t *testing.T) {
	srv := MustGetAPIServer().(*apiSrv)
	s := testAPISrvBackend{}

	singletonAPISrv.svcmap["Testsvc"] = &s

	srv1 := MustGetAPIServer().(*apiSrv)
	if _, ok := srv1.svcmap["Testsvc"]; !ok {
		t.Errorf("Did not find service in new API server")
	}
	delete(srv.svcmap, "Testsvc")
}

// TestRunApiSrv
// Test the Run function of API Server to ensure it exits on failure.
func TestRunApiSrv(t *testing.T) {
	buf := &bytes.Buffer{}

	logConfig := log.GetDefaultConfig("TestApiServer")
	l := log.GetNewLogger(logConfig).SetOutput(buf)
	config := apisrv.Config{
		GrpcServerPort: ":0",
		DebugMode:      true,
		Logger:         l,
		Version:        "v1",
		Scheme:         runtime.NewScheme(),
		Kvstore: store.Config{
			Type:  store.KVStoreTypeMemkv,
			Codec: runtime.NewJSONCodec(runtime.NewScheme()),
		},
	}

	_ = MustGetAPIServer()
	a := &singletonAPISrv
	a.runstate.running = false
	s1 := testAPISrvService{}
	a.RegisterService("test-service1", &s1)
	a.RegisterService("test-service2", &s1)
	a.RegisterHooksCb("test-service1", s1.hooksCb)
	a.RegisterHooksCb("test-service2", s1.hooksCb)
	// Add a dummy service hook without the service.
	a.RegisterHooksCb("dumm-service2", s1.hooksCb)
	if len(a.hookregs) != 3 {
		t.Errorf("Was expecting [2] hooks found [%d]", len(a.hookregs))
	}
	go a.Run(config)
	a.WaitRunning()
	_, err := a.GetAddr()
	if err != nil {
		t.Fatalf("failed to get API gateway address")
	}
	// Try again
	doneCh := make(chan bool)
	go func() {
		a.WaitRunning()
		_, err = a.GetAddr()
		if err != nil {
			t.Fatalf("failed to get API gateway address")
		}
		doneCh <- true
	}()
	select {
	case <-doneCh:
		// Good
	case <-time.After(100 * time.Millisecond):
		t.Fatal("Timeout waiting on lock")
	}

	c := a.getKvConn()
	if c == nil {
		t.Fatalf("Connction is nil")
	}
	// Add a few more connections
	err = a.addKvConnToPool()
	if err != nil {
		t.Errorf("Got error adding connection to pool")
	}

	err = errors.New("Testing Exit for Api Server")
	a.Stop()
	time.Sleep(100 * time.Millisecond)
	if !strings.Contains(buf.String(), "Stop called by user") {
		t.Errorf("APIServer Run did not close on error")
	}
	if s1.hookcbCalled != 2 {
		t.Errorf("Was expecting [2] hooks invocation found [%d]", s1.hookcbCalled)
	}
}
