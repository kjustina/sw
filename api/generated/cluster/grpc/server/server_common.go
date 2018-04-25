// Code generated by protoc-gen-grpc-pensando DO NOT EDIT.

/*
Package clusterApiServer is a auto generated package.
Input file: cmd.proto
*/
package clusterApiServer

import (
	"context"
	"sync"

	"github.com/pensando/sw/venice/apiserver"
	"github.com/pensando/sw/venice/utils/log"
	"github.com/pensando/sw/venice/utils/rpckit"
	"github.com/pensando/sw/venice/utils/runtime"
)

var apisrv apiserver.Server
var regMsgDoneMutex sync.Mutex
var regMsgDone bool
var pkgMessages map[string]apiserver.Message

var regSvcDoneMutex sync.Mutex
var regSvcDone bool

var regWatcherDoneMutex sync.Mutex
var regWatcherDone bool

var regMsgFuncs []func(l log.Logger, scheme *runtime.Scheme)

func addMsgRegFunc(fn func(l log.Logger, scheme *runtime.Scheme)) {
	regMsgFuncs = append(regMsgFuncs, fn)
}

var regSvcFuncs []func(ctx context.Context, l log.Logger, grpcserver *rpckit.RPCServer, scheme *runtime.Scheme)

func addSvcRegFunc(fn func(ctx context.Context, l log.Logger, grpcserver *rpckit.RPCServer, scheme *runtime.Scheme)) {
	regSvcFuncs = append(regSvcFuncs, fn)
}

var regWatcherFuncs []func(ctx context.Context, l log.Logger, grpcserver *rpckit.RPCServer, scheme *runtime.Scheme)

func addWatcherRegFunc(fn func(ctx context.Context, l log.Logger, grpcserver *rpckit.RPCServer, scheme *runtime.Scheme)) {
	regWatcherFuncs = append(regWatcherFuncs, fn)
}

func registerMessages(l log.Logger, scheme *runtime.Scheme) {
	defer regMsgDoneMutex.Unlock()
	regMsgDoneMutex.Lock()
	if regMsgDone {
		return
	}
	regMsgDone = true
	for i := range regMsgFuncs {
		regMsgFuncs[i](l, scheme)
	}
}

func registerServices(ctx context.Context, l log.Logger, grpcserver *rpckit.RPCServer, scheme *runtime.Scheme) {
	defer regSvcDoneMutex.Unlock()
	regSvcDoneMutex.Lock()
	if regSvcDone {
		return
	}
	regSvcDone = true
	for i := range regSvcFuncs {
		regSvcFuncs[i](ctx, l, grpcserver, scheme)
	}
}

func registerWatchers(ctx context.Context, l log.Logger, grpcserver *rpckit.RPCServer, scheme *runtime.Scheme) {
	defer regWatcherDoneMutex.Unlock()
	regWatcherDoneMutex.Lock()
	if regWatcherDone {
		return
	}
	regWatcherDone = true
	for i := range regWatcherFuncs {
		regWatcherFuncs[i](ctx, l, grpcserver, scheme)
	}
}

func cleanupRegistration() {
	regWatcherDoneMutex.Lock()
	regWatcherDone = false
	regWatcherDoneMutex.Unlock()

	regSvcDoneMutex.Lock()
	regSvcDone = false
	regSvcDoneMutex.Unlock()

	regMsgDoneMutex.Lock()
	regMsgDone = false
	regMsgDoneMutex.Unlock()
}
