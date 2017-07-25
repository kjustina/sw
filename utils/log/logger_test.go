package log

import (
	"bytes"
	"context"
	"io/ioutil"
	"os"
	"strings"
	"testing"
)

func TestLoggerToFile(t *testing.T) {
	t.Parallel()
	file := "/tmp/test.log"
	config := &Config{
		Module:      "LogTester",
		Format:      LogFmt,
		Debug:       false,
		LogToStdout: false,
		LogToFile:   true,
		FileCfg: FileConfig{
			Filename:   file,
			MaxSize:    10,
			MaxBackups: 3,
			MaxAge:     7,
		},
	}

	l := GetNewLogger(config)
	l.Log("msg", "testmsg")

	data, err := ioutil.ReadFile(file)
	if err != nil {
		t.Errorf("Error opening file: %s err: %v", file, err)
	}

	str := string(data)
	if !strings.Contains(str, "msg=testmsg") {
		t.Errorf("Expecting [%s] got:[%s]", "msg=testmsg", str)
	}

	err = os.Remove(file)
	if err != nil {
		t.Errorf("Error removing file: %s err: %v", file, err)
	}
}

func TestLevels(t *testing.T) {
	t.Parallel()
	buf := &bytes.Buffer{}

	// Debug
	config := GetDefaultConfig("TestLogger")
	l := GetNewLogger(config).SetOutput(buf)
	l.Printf("testmsg")
	if !strings.Contains(buf.String(), "msg=testmsg") || !strings.Contains(buf.String(), "level=debug") {
		t.Errorf("Expecting [%s] got:[%s]", "[msg=testmsg[] and [level=debug]", buf.String())
	}

	buf.Reset()
	l.Print("testmsg1")
	if !strings.Contains(buf.String(), "msg=testmsg1") || !strings.Contains(buf.String(), "level=debug") {
		t.Errorf("Expecting [%s] got:[%s]", "[msg=testmsg[] and [level=debug]", buf.String())
	}

	buf.Reset()
	l.DebugLog("msg", "testmsg1", "error", "TestError")
	if !strings.Contains(buf.String(), "msg=testmsg1") || !strings.Contains(buf.String(), "level=debug") ||
		!strings.Contains(buf.String(), "error=TestError") {
		t.Errorf("Expecting [%s] got:[%s]", "[msg=testmsg[] and [level=debug]", buf.String())
	}

	buf.Reset()
	l.Println("testmsg1")
	if !strings.Contains(buf.String(), "msg=testmsg1") || !strings.Contains(buf.String(), "level=debug") {
		t.Errorf("Expecting [%s] got:[%s]", "[msg=testmsg[] and [level=debug]", buf.String())
	}

	buf.Reset()
	l.Debug("testmsg1")
	if !strings.Contains(buf.String(), "msg=testmsg1") || !strings.Contains(buf.String(), "level=debug") {
		t.Errorf("Expecting [%s] got:[%s]", "[msg=testmsg[] and [level=debug]", buf.String())
	}

	buf.Reset()
	l.Debugf("testmsg1")
	if !strings.Contains(buf.String(), "msg=testmsg1") || !strings.Contains(buf.String(), "level=debug") {
		t.Errorf("Expecting [%s] got:[%s]", "[msg=testmsg[] and [level=debug]", buf.String())
	}

	buf.Reset()
	l.Debugln("testmsg1")
	if !strings.Contains(buf.String(), "msg=testmsg1") || !strings.Contains(buf.String(), "level=debug") {
		t.Errorf("Expecting [%s] got:[%s]", "[msg=testmsg[] and [level=debug]", buf.String())
	}

	// info
	buf.Reset()
	l.Infof("testmsg1")
	if !strings.Contains(buf.String(), "msg=testmsg1") || !strings.Contains(buf.String(), "level=info") {
		t.Errorf("Expecting [%s] got:[%s]", "[msg=testmsg[] and [level=info]", buf.String())
	}

	buf.Reset()
	l.Infoln("testmsg1")
	if !strings.Contains(buf.String(), "msg=testmsg1") || !strings.Contains(buf.String(), "level=info") {
		t.Errorf("Expecting [%s] got:[%s]", "[msg=testmsg[] and [level=info]", buf.String())
	}

	buf.Reset()
	l.InfoLog("msg", "testmsg1", "error", "TestError")
	if !strings.Contains(buf.String(), "msg=testmsg1") || !strings.Contains(buf.String(), "level=info") ||
		!strings.Contains(buf.String(), "error=TestError") {
		t.Errorf("Expecting [%s] got:[%s]", "[msg=testmsg[] and [level=info]", buf.String())
	}

	// Error
	buf.Reset()
	l.Errorf("testmsg1")
	if !strings.Contains(buf.String(), "msg=testmsg1") || !strings.Contains(buf.String(), "level=error") {
		t.Errorf("Expecting [%s] got:[%s]", "[msg=testmsg[] and [level=error]", buf.String())
	}

	buf.Reset()
	l.Errorln("testmsg1")
	if !strings.Contains(buf.String(), "msg=testmsg1") || !strings.Contains(buf.String(), "level=error") {
		t.Errorf("Expecting [%s] got:[%s]", "[msg=testmsg[] and [level=error]", buf.String())
	}

	buf.Reset()
	l.ErrorLog("msg", "testmsg1", "error", "testerror")
	if !strings.Contains(buf.String(), "msg=testmsg1") || !strings.Contains(buf.String(), "level=error") ||
		!strings.Contains(buf.String(), "error=testerror") {
		t.Errorf("Expecting [%s] got:[%s]", "[msg=testmsg[] and [level=error]", buf.String())
	}
}

func TestDebugMode(t *testing.T) {
	t.Parallel()
	buf := &bytes.Buffer{}

	config := GetDefaultConfig("TestLogger")
	config.Debug = true
	l := GetNewLogger(config).SetOutput(buf)
	l.InfoLog("msg", "testmsg1", "error", "TestError")
	if !strings.Contains(buf.String(), "msg=testmsg1") || !strings.Contains(buf.String(), "level=info") ||
		!strings.Contains(buf.String(), "error=TestError") || !strings.Contains(buf.String(), "caller=\"[ [") {
		t.Errorf("Expecting [%s] got:[%s]", "[msg=testmsg[] and [level=info]", buf.String())
	}
}

func TestWithContext(t *testing.T) {
	t.Parallel()
	buf := &bytes.Buffer{}

	config := GetDefaultConfig("TestLogger")
	config.Debug = true
	l := GetNewLogger(config).SetOutput(buf).WithContext("Tag1", "ONE", "tag2", "TWO")
	l.InfoLog("msg", "testmsg1", "error", "TestError")
	if !strings.Contains(buf.String(), "msg=testmsg1") || !strings.Contains(buf.String(), "level=info") ||
		!strings.Contains(buf.String(), "Tag1=ONE") || !strings.Contains(buf.String(), "tag2=TWO") {
		t.Errorf("Expecting [%s] got:[%s]", "[msg=testmsg[] and [level=info]", buf.String())
	}
}

func TestFatalf(t *testing.T) {
	t.Parallel()
	buf := &bytes.Buffer{}

	config := GetDefaultConfig("TestLogger")
	l := GetNewLogger(config).SetOutput(buf)
	defer func() {
		if r := recover(); r == nil {
			t.Errorf("Expecting panic but did not")
		}
		if !strings.Contains(buf.String(), "Testing Panic") {
			t.Errorf("Did not see expected log expected: [%s] got:[%s]", "Testing Panic", buf.String())
		}
	}()
	l.Fatalf("Testing Panic")
}

func TestFatal(t *testing.T) {
	t.Parallel()
	buf := &bytes.Buffer{}

	config := GetDefaultConfig("TestLogger")
	l := GetNewLogger(config).SetOutput(buf)
	defer func() {
		if r := recover(); r == nil {
			t.Errorf("Expecting panic but did not")
		}
		if !strings.Contains(buf.String(), "Testing Panic") {
			t.Errorf("Did not see expected log expected: [%s] got:[%s]", "Testing Panic", buf.String())
		}
	}()
	l.Fatal("Testing Panic")
}

func TestFatalln(t *testing.T) {
	t.Parallel()
	buf := &bytes.Buffer{}

	config := GetDefaultConfig("TestLogger")
	l := GetNewLogger(config).SetOutput(buf)
	defer func() {
		if r := recover(); r == nil {
			t.Errorf("Expecting panic but did not")
		}
		if !strings.Contains(buf.String(), "Testing Panic") {
			t.Errorf("Did not see expected log expected: [%s] got:[%s]", "Testing Panic", buf.String())
		}
	}()
	l.Fatalln("Testing Panic")
}

func TestAuditLog(t *testing.T) {
	t.Parallel()
	buf := &bytes.Buffer{}

	config := GetDefaultConfig("TestLogger")
	l := GetNewLogger(config).SetOutput(buf)
	var ctx = context.Background()
	ctx = context.WithValue(ctx, PensandoTenant, "TestTenant")
	ctx = context.WithValue(ctx, PensandoUserID, "TestUser")
	ctx = context.WithValue(ctx, PensandoTxnID, "TestTxnId")

	l.Audit(ctx, "msg", "TestMsg")
	if !strings.Contains(buf.String(), "user=TestUser") || !strings.Contains(buf.String(), "tenant=TestTenant") ||
		!strings.Contains(buf.String(), "txnId=TestTxnId") || !strings.Contains(buf.String(), "msg=TestMsg") ||
		!strings.Contains(buf.String(), "level=audit") {
		t.Errorf("Expecting [%s] got:[%s]", "[user=TestUser][tenant=TestTenant][txnId=TestTxnIdr][msg=TestMsg][level=audit]",
			buf.String())
	}

	// This is to test when all auditlog fields are not available in the context
	buf.Reset()
	ctx = context.Background()
	ctx1 := context.WithValue(ctx, PensandoTenant, "TestTenant")
	l.Audit(ctx1, "msg", "TestMsg")
	if strings.Contains(buf.String(), "user=") || !strings.Contains(buf.String(), "tenant=TestTenant") ||
		strings.Contains(buf.String(), "txnId=") || !strings.Contains(buf.String(), "msg=TestMsg") ||
		!strings.Contains(buf.String(), "level=audit") {
		t.Errorf("Expecting [%s] got:[%s]", "[tenant=TestTenant][msg=TestMsg][level=audit]",
			buf.String())
	}
}
