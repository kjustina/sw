package diagnostics

import (
	"context"

	"google.golang.org/grpc"

	diagapi "github.com/pensando/sw/api/generated/diagnostics"
	"github.com/pensando/sw/venice/globals"
	"github.com/pensando/sw/venice/utils/diagnostics/protos"
	"github.com/pensando/sw/venice/utils/rpckit"
)

type client struct {
	rpcClient         *rpckit.RPCClient
	diagnosticsClient protos.DiagnosticsClient
	router            Router
}

func (c *client) Debug(ctx context.Context, in *diagapi.DiagnosticsRequest, opts ...grpc.CallOption) (*diagapi.DiagnosticsResponse, error) {
	return c.diagnosticsClient.Debug(ctx, in, opts...)
}

func (c *client) Close() {
	c.rpcClient.Close()
}

// apigwClient to handle API Gateway Debug requests
type apigwClient struct {
	service Service
}

func (ac *apigwClient) Debug(ctx context.Context, in *diagapi.DiagnosticsRequest, opts ...grpc.CallOption) (*diagapi.DiagnosticsResponse, error) {
	return ac.service.Debug(ctx, in)
}

func (ac *apigwClient) Close() {}

// NewClientGetter returns an implementation of ClientGetter
func NewClientGetter(name string, diagRequest *diagapi.DiagnosticsRequest, router Router, diagSvc Service) (ClientGetter, error) {
	var clgetter ClientGetterFunc
	svcURL, remoteServer, err := router.GetRoute(diagRequest)
	if err != nil {
		return nil, err
	}
	switch remoteServer {
	case globals.APIGw:
		clgetter = func() (Client, error) {
			return &apigwClient{service: diagSvc}, nil
		}
	default:
		clgetter = func() (Client, error) {
			svccl, err := rpckit.NewRPCClient(name, svcURL, rpckit.WithRemoteServerName(remoteServer))
			if err != nil {
				return nil, err
			}
			return &client{
				rpcClient:         svccl,
				diagnosticsClient: protos.NewDiagnosticsClient(svccl.ClientConn),
			}, nil
		}
	}
	return clgetter, nil
}
