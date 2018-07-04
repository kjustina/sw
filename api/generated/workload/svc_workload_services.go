// Code generated by protoc-gen-grpc-pensando DO NOT EDIT.

/*
Package workload is a auto generated package.
Input file: svc_workload.proto
*/
package workload

import (
	"context"

	"github.com/pensando/sw/api"
)

// Dummy definitions to suppress nonused warnings
var _ api.ObjectMeta

// ServiceWorkloadV1Client  is the client interface for the service.
type ServiceWorkloadV1Client interface {
	AutoWatchSvcWorkloadV1(ctx context.Context, in *api.ListWatchOptions) (WorkloadV1_AutoWatchSvcWorkloadV1Client, error)

	AutoAddEndpoint(ctx context.Context, t *Endpoint) (*Endpoint, error)
	AutoAddWorkload(ctx context.Context, t *Workload) (*Workload, error)
	AutoDeleteEndpoint(ctx context.Context, t *Endpoint) (*Endpoint, error)
	AutoDeleteWorkload(ctx context.Context, t *Workload) (*Workload, error)
	AutoGetEndpoint(ctx context.Context, t *Endpoint) (*Endpoint, error)
	AutoGetWorkload(ctx context.Context, t *Workload) (*Workload, error)
	AutoListEndpoint(ctx context.Context, t *api.ListWatchOptions) (*EndpointList, error)
	AutoListWorkload(ctx context.Context, t *api.ListWatchOptions) (*WorkloadList, error)
	AutoUpdateEndpoint(ctx context.Context, t *Endpoint) (*Endpoint, error)
	AutoUpdateWorkload(ctx context.Context, t *Workload) (*Workload, error)

	AutoWatchEndpoint(ctx context.Context, in *api.ListWatchOptions) (WorkloadV1_AutoWatchEndpointClient, error)
	AutoWatchWorkload(ctx context.Context, in *api.ListWatchOptions) (WorkloadV1_AutoWatchWorkloadClient, error)
}

// ServiceWorkloadV1Server is the server interface for the service.
type ServiceWorkloadV1Server interface {
	AutoWatchSvcWorkloadV1(in *api.ListWatchOptions, stream WorkloadV1_AutoWatchSvcWorkloadV1Server) error

	AutoAddEndpoint(ctx context.Context, t Endpoint) (Endpoint, error)
	AutoAddWorkload(ctx context.Context, t Workload) (Workload, error)
	AutoDeleteEndpoint(ctx context.Context, t Endpoint) (Endpoint, error)
	AutoDeleteWorkload(ctx context.Context, t Workload) (Workload, error)
	AutoGetEndpoint(ctx context.Context, t Endpoint) (Endpoint, error)
	AutoGetWorkload(ctx context.Context, t Workload) (Workload, error)
	AutoListEndpoint(ctx context.Context, t api.ListWatchOptions) (EndpointList, error)
	AutoListWorkload(ctx context.Context, t api.ListWatchOptions) (WorkloadList, error)
	AutoUpdateEndpoint(ctx context.Context, t Endpoint) (Endpoint, error)
	AutoUpdateWorkload(ctx context.Context, t Workload) (Workload, error)

	AutoWatchEndpoint(in *api.ListWatchOptions, stream WorkloadV1_AutoWatchEndpointServer) error
	AutoWatchWorkload(in *api.ListWatchOptions, stream WorkloadV1_AutoWatchWorkloadServer) error
}
