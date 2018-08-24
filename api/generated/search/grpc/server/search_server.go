// Code generated by protoc-gen-grpc-pensando DO NOT EDIT.

/*
Package searchApiServer is a auto generated package.
Input file: search.proto
*/
package searchApiServer

import (
	"context"
	"fmt"

	"github.com/pensando/sw/api"
	"github.com/pensando/sw/api/listerwatcher"
	"github.com/pensando/sw/venice/apiserver"
	"github.com/pensando/sw/venice/apiserver/pkg"
	"github.com/pensando/sw/venice/utils/log"
	"github.com/pensando/sw/venice/utils/rpckit"
	"github.com/pensando/sw/venice/utils/runtime"
)

// dummy vars to suppress unused errors
var _ api.ObjectMeta
var _ listerwatcher.WatcherClient
var _ fmt.Stringer

type ssearchSearchBackend struct {
	Services map[string]apiserver.Service
	Messages map[string]apiserver.Message
	logger   log.Logger
	scheme   *runtime.Scheme
}

func (s *ssearchSearchBackend) regMsgsFunc(l log.Logger, scheme *runtime.Scheme) {
	l.Infof("registering message for ssearchSearchBackend")
	s.Messages = map[string]apiserver.Message{

		"search.Category":             apisrvpkg.NewMessage("search.Category"),
		"search.CategoryAggregation":  apisrvpkg.NewMessage("search.CategoryAggregation"),
		"search.CategoryPreview":      apisrvpkg.NewMessage("search.CategoryPreview"),
		"search.ConfigEntry":          apisrvpkg.NewMessage("search.ConfigEntry"),
		"search.Entry":                apisrvpkg.NewMessage("search.Entry"),
		"search.EntryList":            apisrvpkg.NewMessage("search.EntryList"),
		"search.Error":                apisrvpkg.NewMessage("search.Error"),
		"search.Kind":                 apisrvpkg.NewMessage("search.Kind"),
		"search.KindAggregation":      apisrvpkg.NewMessage("search.KindAggregation"),
		"search.KindPreview":          apisrvpkg.NewMessage("search.KindPreview"),
		"search.PolicyMatchEntry":     apisrvpkg.NewMessage("search.PolicyMatchEntry"),
		"search.PolicySearchRequest":  apisrvpkg.NewMessage("search.PolicySearchRequest"),
		"search.PolicySearchResponse": apisrvpkg.NewMessage("search.PolicySearchResponse"),
		"search.SearchQuery":          apisrvpkg.NewMessage("search.SearchQuery"),
		"search.SearchRequest":        apisrvpkg.NewMessage("search.SearchRequest"),
		"search.SearchResponse":       apisrvpkg.NewMessage("search.SearchResponse"),
		"search.TenantAggregation":    apisrvpkg.NewMessage("search.TenantAggregation"),
		"search.TenantPreview":        apisrvpkg.NewMessage("search.TenantPreview"),
		"search.TextRequirement":      apisrvpkg.NewMessage("search.TextRequirement"),
		// Add a message handler for ListWatch options
		"api.ListWatchOptions": apisrvpkg.NewMessage("api.ListWatchOptions"),
	}

	apisrv.RegisterMessages("search", s.Messages)
	// add messages to package.
	if pkgMessages == nil {
		pkgMessages = make(map[string]apiserver.Message)
	}
	for k, v := range s.Messages {
		pkgMessages[k] = v
	}
}

func (s *ssearchSearchBackend) regSvcsFunc(ctx context.Context, logger log.Logger, grpcserver *rpckit.RPCServer, scheme *runtime.Scheme) {

}

func (s *ssearchSearchBackend) regWatchersFunc(ctx context.Context, logger log.Logger, grpcserver *rpckit.RPCServer, scheme *runtime.Scheme) {

}

func (s *ssearchSearchBackend) CompleteRegistration(ctx context.Context, logger log.Logger,
	grpcserver *rpckit.RPCServer, scheme *runtime.Scheme) error {
	// register all messages in the package if not done already
	s.logger = logger
	s.scheme = scheme
	registerMessages(logger, scheme)
	registerServices(ctx, logger, grpcserver, scheme)
	registerWatchers(ctx, logger, grpcserver, scheme)
	return nil
}

func (s *ssearchSearchBackend) Reset() {
	cleanupRegistration()
}

func init() {
	apisrv = apisrvpkg.MustGetAPIServer()

	svc := ssearchSearchBackend{}
	addMsgRegFunc(svc.regMsgsFunc)
	addSvcRegFunc(svc.regSvcsFunc)
	addWatcherRegFunc(svc.regWatchersFunc)

	apisrv.Register("search.search.proto", &svc)
}
