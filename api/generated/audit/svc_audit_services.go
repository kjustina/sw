// Code generated by protoc-gen-grpc-pensando DO NOT EDIT.

/*
Package audit is a auto generated package.
Input file: svc_audit.proto
*/
package audit

import (
	"context"

	"github.com/pensando/sw/api"
)

// Dummy definitions to suppress nonused warnings
var _ api.ObjectMeta

// ServiceAuditV1Client  is the client interface for the service.
type ServiceAuditV1Client interface {
	AutoWatchSvcAuditV1(ctx context.Context, in *api.ListWatchOptions) (AuditV1_AutoWatchSvcAuditV1Client, error)

	GetEvent(ctx context.Context, t *EventRequest) (*Event, error)
}

// ServiceAuditV1Server is the server interface for the service.
type ServiceAuditV1Server interface {
	AutoWatchSvcAuditV1(in *api.ListWatchOptions, stream AuditV1_AutoWatchSvcAuditV1Server) error

	GetEvent(ctx context.Context, t EventRequest) (Event, error)
}
