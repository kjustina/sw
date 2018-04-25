// Code generated by protoc-gen-grpc-gateway
// source: mirror.proto
// DO NOT EDIT!

/*
Package monitoring is a reverse proxy.

It translates gRPC into RESTful JSON APIs.
*/
package monitoring

import (
	"bytes"
	"io"
	"net/http"

	"github.com/gogo/protobuf/proto"
	"github.com/pensando/grpc-gateway/runtime"
	"github.com/pensando/grpc-gateway/utilities"
	"golang.org/x/net/context"
	"google.golang.org/grpc"
	"google.golang.org/grpc/codes"
	"google.golang.org/grpc/grpclog"

	"github.com/pensando/sw/api"
)

var _ codes.Code
var _ io.Reader
var _ = runtime.String
var _ = utilities.NewDoubleArray

func request_MirrorSessionV1_AutoAddMirrorSession_0(ctx context.Context, marshaler runtime.Marshaler, client MirrorSessionV1Client, req *http.Request, pathParams map[string]string) (proto.Message, runtime.ServerMetadata, error) {
	protoReq := &MirrorSession{}
	var smetadata runtime.ServerMetadata

	ver := req.Header.Get("Grpc-Metadata-Req-Version")
	if ver == "" {
		ver = "all"
	}
	var buf bytes.Buffer
	tee := io.TeeReader(req.Body, &buf)
	if err := marshaler.NewDecoder(tee).Decode(protoReq); err != nil {
		return nil, smetadata, grpc.Errorf(codes.InvalidArgument, "%v", err)
	}
	changed := protoReq.Defaults(ver)
	if changed {
		if err := marshaler.NewDecoder(&buf).Decode(protoReq); err != nil {
			return nil, smetadata, grpc.Errorf(codes.InvalidArgument, "%v", err)
		}
	}

	var (
		val string
		ok  bool
		err error
		_   = err
	)

	val, ok = pathParams["O.Tenant"]
	if !ok {
		return nil, smetadata, grpc.Errorf(codes.InvalidArgument, "missing parameter %s", "O.Tenant")
	}

	err = runtime.PopulateFieldFromPath(protoReq, "O.Tenant", val)

	if err != nil {
		return nil, smetadata, err
	}

	msg, err := client.AutoAddMirrorSession(ctx, protoReq, grpc.Header(&smetadata.HeaderMD), grpc.Trailer(&smetadata.TrailerMD))
	return msg, smetadata, err

}

var (
	filter_MirrorSessionV1_AutoDeleteMirrorSession_0 = &utilities.DoubleArray{Encoding: map[string]int{"O": 0, "Tenant": 1, "Name": 2}, Base: []int{1, 1, 1, 2, 0, 0}, Check: []int{0, 1, 2, 2, 3, 4}}
)

func request_MirrorSessionV1_AutoDeleteMirrorSession_0(ctx context.Context, marshaler runtime.Marshaler, client MirrorSessionV1Client, req *http.Request, pathParams map[string]string) (proto.Message, runtime.ServerMetadata, error) {
	protoReq := &MirrorSession{}
	var smetadata runtime.ServerMetadata

	var (
		val string
		ok  bool
		err error
		_   = err
	)

	val, ok = pathParams["O.Tenant"]
	if !ok {
		return nil, smetadata, grpc.Errorf(codes.InvalidArgument, "missing parameter %s", "O.Tenant")
	}

	err = runtime.PopulateFieldFromPath(protoReq, "O.Tenant", val)

	if err != nil {
		return nil, smetadata, err
	}

	val, ok = pathParams["O.Name"]
	if !ok {
		return nil, smetadata, grpc.Errorf(codes.InvalidArgument, "missing parameter %s", "O.Name")
	}

	err = runtime.PopulateFieldFromPath(protoReq, "O.Name", val)

	if err != nil {
		return nil, smetadata, err
	}

	if err := runtime.PopulateQueryParameters(protoReq, req.URL.Query(), filter_MirrorSessionV1_AutoDeleteMirrorSession_0); err != nil {
		return nil, smetadata, grpc.Errorf(codes.InvalidArgument, "%v", err)
	}

	msg, err := client.AutoDeleteMirrorSession(ctx, protoReq, grpc.Header(&smetadata.HeaderMD), grpc.Trailer(&smetadata.TrailerMD))
	return msg, smetadata, err

}

var (
	filter_MirrorSessionV1_AutoGetMirrorSession_0 = &utilities.DoubleArray{Encoding: map[string]int{"O": 0, "Tenant": 1, "Name": 2}, Base: []int{1, 1, 1, 2, 0, 0}, Check: []int{0, 1, 2, 2, 3, 4}}
)

func request_MirrorSessionV1_AutoGetMirrorSession_0(ctx context.Context, marshaler runtime.Marshaler, client MirrorSessionV1Client, req *http.Request, pathParams map[string]string) (proto.Message, runtime.ServerMetadata, error) {
	protoReq := &MirrorSession{}
	var smetadata runtime.ServerMetadata

	var (
		val string
		ok  bool
		err error
		_   = err
	)

	val, ok = pathParams["O.Tenant"]
	if !ok {
		return nil, smetadata, grpc.Errorf(codes.InvalidArgument, "missing parameter %s", "O.Tenant")
	}

	err = runtime.PopulateFieldFromPath(protoReq, "O.Tenant", val)

	if err != nil {
		return nil, smetadata, err
	}

	val, ok = pathParams["O.Name"]
	if !ok {
		return nil, smetadata, grpc.Errorf(codes.InvalidArgument, "missing parameter %s", "O.Name")
	}

	err = runtime.PopulateFieldFromPath(protoReq, "O.Name", val)

	if err != nil {
		return nil, smetadata, err
	}

	if err := runtime.PopulateQueryParameters(protoReq, req.URL.Query(), filter_MirrorSessionV1_AutoGetMirrorSession_0); err != nil {
		return nil, smetadata, grpc.Errorf(codes.InvalidArgument, "%v", err)
	}

	msg, err := client.AutoGetMirrorSession(ctx, protoReq, grpc.Header(&smetadata.HeaderMD), grpc.Trailer(&smetadata.TrailerMD))
	return msg, smetadata, err

}

var (
	filter_MirrorSessionV1_AutoListMirrorSession_0 = &utilities.DoubleArray{Encoding: map[string]int{"O": 0, "Tenant": 1}, Base: []int{1, 1, 1, 0}, Check: []int{0, 1, 2, 3}}
)

func request_MirrorSessionV1_AutoListMirrorSession_0(ctx context.Context, marshaler runtime.Marshaler, client MirrorSessionV1Client, req *http.Request, pathParams map[string]string) (proto.Message, runtime.ServerMetadata, error) {
	protoReq := &api.ListWatchOptions{}
	var smetadata runtime.ServerMetadata

	var (
		val string
		ok  bool
		err error
		_   = err
	)

	val, ok = pathParams["O.Tenant"]
	if !ok {
		return nil, smetadata, grpc.Errorf(codes.InvalidArgument, "missing parameter %s", "O.Tenant")
	}

	err = runtime.PopulateFieldFromPath(protoReq, "O.Tenant", val)

	if err != nil {
		return nil, smetadata, err
	}

	if err := runtime.PopulateQueryParameters(protoReq, req.URL.Query(), filter_MirrorSessionV1_AutoListMirrorSession_0); err != nil {
		return nil, smetadata, grpc.Errorf(codes.InvalidArgument, "%v", err)
	}

	msg, err := client.AutoListMirrorSession(ctx, protoReq, grpc.Header(&smetadata.HeaderMD), grpc.Trailer(&smetadata.TrailerMD))
	return msg, smetadata, err

}

func request_MirrorSessionV1_AutoUpdateMirrorSession_0(ctx context.Context, marshaler runtime.Marshaler, client MirrorSessionV1Client, req *http.Request, pathParams map[string]string) (proto.Message, runtime.ServerMetadata, error) {
	protoReq := &MirrorSession{}
	var smetadata runtime.ServerMetadata

	ver := req.Header.Get("Grpc-Metadata-Req-Version")
	if ver == "" {
		ver = "all"
	}
	var buf bytes.Buffer
	tee := io.TeeReader(req.Body, &buf)
	if err := marshaler.NewDecoder(tee).Decode(protoReq); err != nil {
		return nil, smetadata, grpc.Errorf(codes.InvalidArgument, "%v", err)
	}
	changed := protoReq.Defaults(ver)
	if changed {
		if err := marshaler.NewDecoder(&buf).Decode(protoReq); err != nil {
			return nil, smetadata, grpc.Errorf(codes.InvalidArgument, "%v", err)
		}
	}

	var (
		val string
		ok  bool
		err error
		_   = err
	)

	val, ok = pathParams["O.Tenant"]
	if !ok {
		return nil, smetadata, grpc.Errorf(codes.InvalidArgument, "missing parameter %s", "O.Tenant")
	}

	err = runtime.PopulateFieldFromPath(protoReq, "O.Tenant", val)

	if err != nil {
		return nil, smetadata, err
	}

	val, ok = pathParams["O.Name"]
	if !ok {
		return nil, smetadata, grpc.Errorf(codes.InvalidArgument, "missing parameter %s", "O.Name")
	}

	err = runtime.PopulateFieldFromPath(protoReq, "O.Name", val)

	if err != nil {
		return nil, smetadata, err
	}

	msg, err := client.AutoUpdateMirrorSession(ctx, protoReq, grpc.Header(&smetadata.HeaderMD), grpc.Trailer(&smetadata.TrailerMD))
	return msg, smetadata, err

}

// RegisterMirrorSessionV1HandlerFromEndpoint is same as RegisterMirrorSessionV1Handler but
// automatically dials to "endpoint" and closes the connection when "ctx" gets done.
func RegisterMirrorSessionV1HandlerFromEndpoint(ctx context.Context, mux *runtime.ServeMux, endpoint string, opts []grpc.DialOption) (err error) {
	conn, err := grpc.Dial(endpoint, opts...)
	if err != nil {
		return err
	}
	defer func() {
		if err != nil {
			if cerr := conn.Close(); cerr != nil {
				grpclog.Printf("Failed to close conn to %s: %v", endpoint, cerr)
			}
			return
		}
		go func() {
			<-ctx.Done()
			if cerr := conn.Close(); cerr != nil {
				grpclog.Printf("Failed to close conn to %s: %v", endpoint, cerr)
			}
		}()
	}()

	return RegisterMirrorSessionV1Handler(ctx, mux, conn)
}

// RegisterMirrorSessionV1Handler registers the http handlers for service MirrorSessionV1 to "mux".
// The handlers forward requests to the grpc endpoint over "conn".
func RegisterMirrorSessionV1Handler(ctx context.Context, mux *runtime.ServeMux, conn *grpc.ClientConn) error {
	client := NewMirrorSessionV1Client(conn)
	return RegisterMirrorSessionV1HandlerWithClient(ctx, mux, client)
}

// RegisterMirrorSessionV1HandlerClient registers the http handlers for service MirrorSessionV1 to "mux".
// The handlers forward requests to the grpc endpoint using client provided.
func RegisterMirrorSessionV1HandlerWithClient(ctx context.Context, mux *runtime.ServeMux, client MirrorSessionV1Client) error {

	mux.Handle("POST", pattern_MirrorSessionV1_AutoAddMirrorSession_0, func(w http.ResponseWriter, req *http.Request, pathParams map[string]string) {
		ctx, cancel := context.WithCancel(req.Context())
		defer cancel()
		if cn, ok := w.(http.CloseNotifier); ok {
			go func(done <-chan struct{}, closed <-chan bool) {
				select {
				case <-done:
				case <-closed:
					cancel()
				}
			}(ctx.Done(), cn.CloseNotify())
		}
		inboundMarshaler, outboundMarshaler := runtime.MarshalerForRequest(mux, req)
		rctx, err := runtime.AnnotateContext(ctx, req)
		if err != nil {
			runtime.HTTPError(ctx, outboundMarshaler, w, req, err)
		}
		resp, md, err := request_MirrorSessionV1_AutoAddMirrorSession_0(rctx, inboundMarshaler, client, req, pathParams)
		ctx = runtime.NewServerMetadataContext(ctx, md)
		if err != nil {
			runtime.HTTPError(ctx, outboundMarshaler, w, req, err)
			return
		}

		forward_MirrorSessionV1_AutoAddMirrorSession_0(ctx, outboundMarshaler, w, req, resp, mux.GetForwardResponseOptions()...)

	})

	mux.Handle("DELETE", pattern_MirrorSessionV1_AutoDeleteMirrorSession_0, func(w http.ResponseWriter, req *http.Request, pathParams map[string]string) {
		ctx, cancel := context.WithCancel(req.Context())
		defer cancel()
		if cn, ok := w.(http.CloseNotifier); ok {
			go func(done <-chan struct{}, closed <-chan bool) {
				select {
				case <-done:
				case <-closed:
					cancel()
				}
			}(ctx.Done(), cn.CloseNotify())
		}
		inboundMarshaler, outboundMarshaler := runtime.MarshalerForRequest(mux, req)
		rctx, err := runtime.AnnotateContext(ctx, req)
		if err != nil {
			runtime.HTTPError(ctx, outboundMarshaler, w, req, err)
		}
		resp, md, err := request_MirrorSessionV1_AutoDeleteMirrorSession_0(rctx, inboundMarshaler, client, req, pathParams)
		ctx = runtime.NewServerMetadataContext(ctx, md)
		if err != nil {
			runtime.HTTPError(ctx, outboundMarshaler, w, req, err)
			return
		}

		forward_MirrorSessionV1_AutoDeleteMirrorSession_0(ctx, outboundMarshaler, w, req, resp, mux.GetForwardResponseOptions()...)

	})

	mux.Handle("GET", pattern_MirrorSessionV1_AutoGetMirrorSession_0, func(w http.ResponseWriter, req *http.Request, pathParams map[string]string) {
		ctx, cancel := context.WithCancel(req.Context())
		defer cancel()
		if cn, ok := w.(http.CloseNotifier); ok {
			go func(done <-chan struct{}, closed <-chan bool) {
				select {
				case <-done:
				case <-closed:
					cancel()
				}
			}(ctx.Done(), cn.CloseNotify())
		}
		inboundMarshaler, outboundMarshaler := runtime.MarshalerForRequest(mux, req)
		rctx, err := runtime.AnnotateContext(ctx, req)
		if err != nil {
			runtime.HTTPError(ctx, outboundMarshaler, w, req, err)
		}
		resp, md, err := request_MirrorSessionV1_AutoGetMirrorSession_0(rctx, inboundMarshaler, client, req, pathParams)
		ctx = runtime.NewServerMetadataContext(ctx, md)
		if err != nil {
			runtime.HTTPError(ctx, outboundMarshaler, w, req, err)
			return
		}

		forward_MirrorSessionV1_AutoGetMirrorSession_0(ctx, outboundMarshaler, w, req, resp, mux.GetForwardResponseOptions()...)

	})

	mux.Handle("GET", pattern_MirrorSessionV1_AutoListMirrorSession_0, func(w http.ResponseWriter, req *http.Request, pathParams map[string]string) {
		ctx, cancel := context.WithCancel(req.Context())
		defer cancel()
		if cn, ok := w.(http.CloseNotifier); ok {
			go func(done <-chan struct{}, closed <-chan bool) {
				select {
				case <-done:
				case <-closed:
					cancel()
				}
			}(ctx.Done(), cn.CloseNotify())
		}
		inboundMarshaler, outboundMarshaler := runtime.MarshalerForRequest(mux, req)
		rctx, err := runtime.AnnotateContext(ctx, req)
		if err != nil {
			runtime.HTTPError(ctx, outboundMarshaler, w, req, err)
		}
		resp, md, err := request_MirrorSessionV1_AutoListMirrorSession_0(rctx, inboundMarshaler, client, req, pathParams)
		ctx = runtime.NewServerMetadataContext(ctx, md)
		if err != nil {
			runtime.HTTPError(ctx, outboundMarshaler, w, req, err)
			return
		}

		forward_MirrorSessionV1_AutoListMirrorSession_0(ctx, outboundMarshaler, w, req, resp, mux.GetForwardResponseOptions()...)

	})

	mux.Handle("PUT", pattern_MirrorSessionV1_AutoUpdateMirrorSession_0, func(w http.ResponseWriter, req *http.Request, pathParams map[string]string) {
		ctx, cancel := context.WithCancel(req.Context())
		defer cancel()
		if cn, ok := w.(http.CloseNotifier); ok {
			go func(done <-chan struct{}, closed <-chan bool) {
				select {
				case <-done:
				case <-closed:
					cancel()
				}
			}(ctx.Done(), cn.CloseNotify())
		}
		inboundMarshaler, outboundMarshaler := runtime.MarshalerForRequest(mux, req)
		rctx, err := runtime.AnnotateContext(ctx, req)
		if err != nil {
			runtime.HTTPError(ctx, outboundMarshaler, w, req, err)
		}
		resp, md, err := request_MirrorSessionV1_AutoUpdateMirrorSession_0(rctx, inboundMarshaler, client, req, pathParams)
		ctx = runtime.NewServerMetadataContext(ctx, md)
		if err != nil {
			runtime.HTTPError(ctx, outboundMarshaler, w, req, err)
			return
		}

		forward_MirrorSessionV1_AutoUpdateMirrorSession_0(ctx, outboundMarshaler, w, req, resp, mux.GetForwardResponseOptions()...)

	})

	return nil
}

var (
	pattern_MirrorSessionV1_AutoAddMirrorSession_0 = runtime.MustPattern(runtime.NewPattern(1, []int{1, 0, 4, 1, 5, 0, 2, 1}, []string{"O.Tenant", "MirrorSession"}, ""))

	pattern_MirrorSessionV1_AutoDeleteMirrorSession_0 = runtime.MustPattern(runtime.NewPattern(1, []int{1, 0, 4, 1, 5, 0, 2, 1, 1, 0, 4, 1, 5, 2}, []string{"O.Tenant", "MirrorSession", "O.Name"}, ""))

	pattern_MirrorSessionV1_AutoGetMirrorSession_0 = runtime.MustPattern(runtime.NewPattern(1, []int{1, 0, 4, 1, 5, 0, 2, 1, 1, 0, 4, 1, 5, 2}, []string{"O.Tenant", "MirrorSession", "O.Name"}, ""))

	pattern_MirrorSessionV1_AutoListMirrorSession_0 = runtime.MustPattern(runtime.NewPattern(1, []int{1, 0, 4, 1, 5, 0, 2, 1}, []string{"O.Tenant", "MirrorSession"}, ""))

	pattern_MirrorSessionV1_AutoUpdateMirrorSession_0 = runtime.MustPattern(runtime.NewPattern(1, []int{1, 0, 4, 1, 5, 0, 2, 1, 1, 0, 4, 1, 5, 2}, []string{"O.Tenant", "MirrorSession", "O.Name"}, ""))
)

var (
	forward_MirrorSessionV1_AutoAddMirrorSession_0 = runtime.ForwardResponseMessage

	forward_MirrorSessionV1_AutoDeleteMirrorSession_0 = runtime.ForwardResponseMessage

	forward_MirrorSessionV1_AutoGetMirrorSession_0 = runtime.ForwardResponseMessage

	forward_MirrorSessionV1_AutoListMirrorSession_0 = runtime.ForwardResponseMessage

	forward_MirrorSessionV1_AutoUpdateMirrorSession_0 = runtime.ForwardResponseMessage
)
