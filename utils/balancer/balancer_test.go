package balancer

import (
	"fmt"
	"testing"
	"time"

	"google.golang.org/grpc"

	"github.com/pensando/sw/utils/resolver/mock"
	"golang.org/x/net/context"

	"github.com/pensando/sw/api"
	"github.com/pensando/sw/cmd/types"
)

func TestBalancer(t *testing.T) {
	rc := mock.New()
	b := New(rc)
	if _, _, err := b.Get(context.Background(), grpc.BalancerGetOptions{}); err != grpc.ErrClientConnClosing {
		t.Fatalf("Did not get conn closing error before Start, got %v", err)
	}
	if err := b.Close(); err != nil {
		t.Fatalf("Close failed before Start with error: %v", err)
	}
	if err := b.Start("testService", grpc.BalancerConfig{}); err != nil {
		t.Fatalf("Start failed with error: %v", err)
	}
	notifyCh := b.Notify()
	si1 := types.ServiceInstance{
		TypeMeta: api.TypeMeta{
			Kind: "ServiceInstance",
		},
		ObjectMeta: api.ObjectMeta{
			Name: "inst1",
		},
		Service: "testService",
		Node:    "node1",
	}
	// Add instance1.
	rc.AddServiceInstance(&si1)
	select {
	case addrs := <-notifyCh:
		if len(addrs) != 1 {
			t.Fatalf("Expected 1 addr, got %v", len(addrs))
		}
		if addrs[0].Addr != "node1" {
			t.Fatalf("Expected node1, got %v", addrs[0].Addr)
		}
	case <-time.After(time.Second):
		t.Fatalf("Timed out waiting for resolver notification")
	}
	si2 := si1
	si2.Name = "inst2"
	si2.Node = "node2"
	// Add instance2.
	rc.AddServiceInstance(&si2)
	select {
	case addrs := <-notifyCh:
		if len(addrs) != 2 {
			t.Fatalf("Expected 2 addrs, got %v", len(addrs))
		}
		for ii := range addrs {
			if addrs[ii].Addr != "node1" && addrs[ii].Addr != "node2" {
				t.Fatalf("Expected node1/node2, got %v", addrs[ii].Addr)
			}
		}
	case <-time.After(time.Second):
		t.Fatalf("Timed out waiting for resolver notification")
	}

	// Both instances are still down.
	if addr, _, err := b.Get(context.Background(), grpc.BalancerGetOptions{}); err == nil {
		t.Fatalf("Did not get unavailable error")
	} else if addr.Addr != "" {
		t.Fatalf("Expected empty Get, got %v", addr.Addr)
	}

	// Mark instance1 up.
	b.Up(grpc.Address{Addr: "node1"})
	if addr, _, err := b.Get(context.Background(), grpc.BalancerGetOptions{}); err != nil {
		t.Fatalf("Failed to get with error: %v", err)
	} else if addr.Addr != "node1" {
		t.Fatalf("Expected to get node1, got %v", addr.Addr)
	}

	// Mark instance2 up.
	downFn := b.Up(grpc.Address{Addr: "node2"})
	if addr, _, err := b.Get(context.Background(), grpc.BalancerGetOptions{}); err != nil {
		t.Fatalf("Failed to get with error: %v", err)
	} else if addr.Addr != "node1" && addr.Addr != "node2" {
		t.Fatalf("Expected to get node1/node2, got %v", addr.Addr)
	}

	// Mark instance2 down.
	downFn(fmt.Errorf("Test down"))
	if addr, _, err := b.Get(context.Background(), grpc.BalancerGetOptions{}); err != nil {
		t.Fatalf("Failed to get with error: %v", err)
	} else if addr.Addr != "node1" {
		t.Fatalf("Expected to get node1, got %v", addr.Addr)
	}

	// Delete instance2.
	rc.DeleteServiceInstance(&si2)
	select {
	case addrs := <-notifyCh:
		if len(addrs) != 1 {
			t.Fatalf("Expected 1 addr, got %v", len(addrs))
		}
		if addrs[0].Addr != "node1" {
			t.Fatalf("Expected node1, got %v", addrs[0].Addr)
		}
	case <-time.After(time.Second):
		t.Fatalf("Timed out waiting for resolver notification")
	}
	b.Close()
}
