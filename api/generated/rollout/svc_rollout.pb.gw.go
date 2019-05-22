// Code generated by protoc-gen-grpc-gateway
// source: svc_rollout.proto
// DO NOT EDIT!

/*
Package rollout is a reverse proxy.

It translates gRPC into RESTful JSON APIs.
*/
package rollout

import (
	"bytes"
	"errors"
	"io"
	"net/http"

	"github.com/gogo/protobuf/proto"
	"github.com/gorilla/websocket"
	"github.com/pensando/grpc-gateway/runtime"
	"github.com/pensando/grpc-gateway/utilities"
	"golang.org/x/net/context"
	"google.golang.org/grpc"
	"google.golang.org/grpc/codes"
	"google.golang.org/grpc/grpclog"

	"github.com/pensando/sw/api"
	"github.com/pensando/sw/api/utils"
)

var _ codes.Code
var _ io.Reader
var _ = runtime.String
var _ = utilities.NewDoubleArray
var _ = apiutils.CtxKeyObjKind

var (
	filter_RolloutV1_AutoDeleteRollout_0 = &utilities.DoubleArray{Encoding: map[string]int{"O": 0, "Name": 1}, Base: []int{1, 1, 1, 0}, Check: []int{0, 1, 2, 3}}
)

func request_RolloutV1_AutoDeleteRollout_0(ctx context.Context, marshaler runtime.Marshaler, client RolloutV1Client, req *http.Request, pathParams map[string]string) (proto.Message, runtime.ServerMetadata, error) {
	protoReq := &Rollout{}
	var smetadata runtime.ServerMetadata

	ver := req.Header.Get("Grpc-Metadata-Req-Version")
	if ver == "" {
		ver = "all"
	}
	if req.ContentLength != 0 {
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
	} else {
		protoReq.Defaults(ver)
	}

	var (
		val   string
		ok    bool
		err   error
		_                       = err
		kvMap map[string]string = make(map[string]string)
	)

	val, ok = pathParams["O.Name"]
	if !ok {
		return nil, smetadata, grpc.Errorf(codes.InvalidArgument, "missing parameter %s", "O.Name")
	}

	err = runtime.PopulateFieldFromPath(protoReq, "O.Name", val)

	if err != nil {
		return nil, smetadata, err
	}

	ctx = runtime.PopulateContextKV(ctx, kvMap)

	if err := runtime.PopulateQueryParameters(protoReq, req.URL.Query(), filter_RolloutV1_AutoDeleteRollout_0); err != nil {
		return nil, smetadata, grpc.Errorf(codes.InvalidArgument, "%v", err)
	}

	msg, err := client.AutoDeleteRollout(ctx, protoReq, grpc.Header(&smetadata.HeaderMD), grpc.Trailer(&smetadata.TrailerMD))
	return msg, smetadata, err

}

var (
	filter_RolloutV1_AutoGetRollout_0 = &utilities.DoubleArray{Encoding: map[string]int{"O": 0, "Name": 1}, Base: []int{1, 1, 1, 0}, Check: []int{0, 1, 2, 3}}
)

func request_RolloutV1_AutoGetRollout_0(ctx context.Context, marshaler runtime.Marshaler, client RolloutV1Client, req *http.Request, pathParams map[string]string) (proto.Message, runtime.ServerMetadata, error) {
	protoReq := &Rollout{}
	var smetadata runtime.ServerMetadata

	ver := req.Header.Get("Grpc-Metadata-Req-Version")
	if ver == "" {
		ver = "all"
	}
	if req.ContentLength != 0 {
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
	} else {
		protoReq.Defaults(ver)
	}

	var (
		val   string
		ok    bool
		err   error
		_                       = err
		kvMap map[string]string = make(map[string]string)
	)

	val, ok = pathParams["O.Name"]
	if !ok {
		return nil, smetadata, grpc.Errorf(codes.InvalidArgument, "missing parameter %s", "O.Name")
	}

	err = runtime.PopulateFieldFromPath(protoReq, "O.Name", val)

	if err != nil {
		return nil, smetadata, err
	}

	ctx = runtime.PopulateContextKV(ctx, kvMap)

	if err := runtime.PopulateQueryParameters(protoReq, req.URL.Query(), filter_RolloutV1_AutoGetRollout_0); err != nil {
		return nil, smetadata, grpc.Errorf(codes.InvalidArgument, "%v", err)
	}

	msg, err := client.AutoGetRollout(ctx, protoReq, grpc.Header(&smetadata.HeaderMD), grpc.Trailer(&smetadata.TrailerMD))
	return msg, smetadata, err

}

var (
	filter_RolloutV1_AutoListRollout_0 = &utilities.DoubleArray{Encoding: map[string]int{}, Base: []int(nil), Check: []int(nil)}
)

func request_RolloutV1_AutoListRollout_0(ctx context.Context, marshaler runtime.Marshaler, client RolloutV1Client, req *http.Request, pathParams map[string]string) (proto.Message, runtime.ServerMetadata, error) {
	protoReq := &api.ListWatchOptions{}
	var smetadata runtime.ServerMetadata

	ver := req.Header.Get("Grpc-Metadata-Req-Version")
	if ver == "" {
		ver = "all"
	}
	if req.ContentLength != 0 {
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
	} else {
		protoReq.Defaults(ver)
	}

	if err := runtime.PopulateQueryParameters(protoReq, req.URL.Query(), filter_RolloutV1_AutoListRollout_0); err != nil {
		return nil, smetadata, grpc.Errorf(codes.InvalidArgument, "%v", err)
	}

	msg, err := client.AutoListRollout(ctx, protoReq, grpc.Header(&smetadata.HeaderMD), grpc.Trailer(&smetadata.TrailerMD))
	return msg, smetadata, err

}

var (
	filter_RolloutV1_AutoWatchRollout_0 = &utilities.DoubleArray{Encoding: map[string]int{}, Base: []int(nil), Check: []int(nil)}
)

func request_RolloutV1_AutoWatchRollout_0(ctx context.Context, marshaler runtime.Marshaler, client RolloutV1Client, req *http.Request, pathParams map[string]string) (RolloutV1_AutoWatchRolloutClient, runtime.ServerMetadata, error) {
	protoReq := &api.ListWatchOptions{}
	var smetadata runtime.ServerMetadata

	ver := req.Header.Get("Grpc-Metadata-Req-Version")
	if ver == "" {
		ver = "all"
	}
	if req.ContentLength != 0 {
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
	} else {
		protoReq.Defaults(ver)
	}

	if err := runtime.PopulateQueryParameters(protoReq, req.URL.Query(), filter_RolloutV1_AutoWatchRollout_0); err != nil {
		return nil, smetadata, grpc.Errorf(codes.InvalidArgument, "%v", err)
	}

	stream, err := client.AutoWatchRollout(ctx, protoReq)
	if err != nil {
		return nil, smetadata, err
	}
	header, err := stream.Header()
	if err != nil {
		return nil, smetadata, err
	}
	smetadata.HeaderMD = header
	return stream, smetadata, nil

}

func request_RolloutV1_CreateRollout_0(ctx context.Context, marshaler runtime.Marshaler, client RolloutV1Client, req *http.Request, pathParams map[string]string) (proto.Message, runtime.ServerMetadata, error) {
	protoReq := &Rollout{}
	var smetadata runtime.ServerMetadata

	ver := req.Header.Get("Grpc-Metadata-Req-Version")
	if ver == "" {
		ver = "all"
	}
	if req.ContentLength != 0 {
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
	} else {
		protoReq.Defaults(ver)
	}

	msg, err := client.CreateRollout(ctx, protoReq, grpc.Header(&smetadata.HeaderMD), grpc.Trailer(&smetadata.TrailerMD))
	return msg, smetadata, err

}

func request_RolloutV1_StopRollout_0(ctx context.Context, marshaler runtime.Marshaler, client RolloutV1Client, req *http.Request, pathParams map[string]string) (proto.Message, runtime.ServerMetadata, error) {
	protoReq := &Rollout{}
	var smetadata runtime.ServerMetadata

	ver := req.Header.Get("Grpc-Metadata-Req-Version")
	if ver == "" {
		ver = "all"
	}
	if req.ContentLength != 0 {
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
	} else {
		protoReq.Defaults(ver)
	}

	msg, err := client.StopRollout(ctx, protoReq, grpc.Header(&smetadata.HeaderMD), grpc.Trailer(&smetadata.TrailerMD))
	return msg, smetadata, err

}

func request_RolloutV1_UpdateRollout_0(ctx context.Context, marshaler runtime.Marshaler, client RolloutV1Client, req *http.Request, pathParams map[string]string) (proto.Message, runtime.ServerMetadata, error) {
	protoReq := &Rollout{}
	var smetadata runtime.ServerMetadata

	ver := req.Header.Get("Grpc-Metadata-Req-Version")
	if ver == "" {
		ver = "all"
	}
	if req.ContentLength != 0 {
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
	} else {
		protoReq.Defaults(ver)
	}

	msg, err := client.UpdateRollout(ctx, protoReq, grpc.Header(&smetadata.HeaderMD), grpc.Trailer(&smetadata.TrailerMD))
	return msg, smetadata, err

}

// RegisterRolloutV1HandlerFromEndpoint is same as RegisterRolloutV1Handler but
// automatically dials to "endpoint" and closes the connection when "ctx" gets done.
func RegisterRolloutV1HandlerFromEndpoint(ctx context.Context, mux *runtime.ServeMux, endpoint string, opts []grpc.DialOption) (err error) {
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

	return RegisterRolloutV1Handler(ctx, mux, conn)
}

// RegisterRolloutV1Handler registers the http handlers for service RolloutV1 to "mux".
// The handlers forward requests to the grpc endpoint over "conn".
func RegisterRolloutV1Handler(ctx context.Context, mux *runtime.ServeMux, conn *grpc.ClientConn) error {
	client := NewRolloutV1Client(conn)
	return RegisterRolloutV1HandlerWithClient(ctx, mux, client)
}

// RegisterRolloutV1HandlerClient registers the http handlers for service RolloutV1 to "mux".
// The handlers forward requests to the grpc endpoint using client provided.
func RegisterRolloutV1HandlerWithClient(ctx context.Context, mux *runtime.ServeMux, client RolloutV1Client) error {

	mux.Handle("DELETE", pattern_RolloutV1_AutoDeleteRollout_0, func(w http.ResponseWriter, req *http.Request, pathParams map[string]string) {
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
		resp, md, err := request_RolloutV1_AutoDeleteRollout_0(rctx, inboundMarshaler, client, req, pathParams)
		ctx = runtime.NewServerMetadataContext(ctx, md)
		if err != nil {
			runtime.HTTPError(ctx, outboundMarshaler, w, req, err)
			return
		}

		forward_RolloutV1_AutoDeleteRollout_0(ctx, outboundMarshaler, w, req, resp, mux.GetForwardResponseOptions()...)

	})

	mux.Handle("GET", pattern_RolloutV1_AutoGetRollout_0, func(w http.ResponseWriter, req *http.Request, pathParams map[string]string) {
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
		resp, md, err := request_RolloutV1_AutoGetRollout_0(rctx, inboundMarshaler, client, req, pathParams)
		ctx = runtime.NewServerMetadataContext(ctx, md)
		if err != nil {
			runtime.HTTPError(ctx, outboundMarshaler, w, req, err)
			return
		}

		forward_RolloutV1_AutoGetRollout_0(ctx, outboundMarshaler, w, req, resp, mux.GetForwardResponseOptions()...)

	})

	mux.Handle("GET", pattern_RolloutV1_AutoListRollout_0, func(w http.ResponseWriter, req *http.Request, pathParams map[string]string) {
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
		resp, md, err := request_RolloutV1_AutoListRollout_0(rctx, inboundMarshaler, client, req, pathParams)
		ctx = runtime.NewServerMetadataContext(ctx, md)
		if err != nil {
			runtime.HTTPError(ctx, outboundMarshaler, w, req, err)
			return
		}

		forward_RolloutV1_AutoListRollout_0(ctx, outboundMarshaler, w, req, resp, mux.GetForwardResponseOptions()...)

	})

	mux.Handle("GET", pattern_RolloutV1_AutoWatchRollout_0, func(w http.ResponseWriter, req *http.Request, pathParams map[string]string) {
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
		ws := false
		rctx = apiutils.SetVar(rctx, apiutils.CtxKeyAPIGwBinStreamReq, false)
		if websocket.IsWebSocketUpgrade(req) {
			ws = true
			rctx = apiutils.SetVar(rctx, apiutils.CtxKeyAPIGwHTTPReq, req)
			apiutils.SetVar(rctx, apiutils.CtxKeyAPIGwHTTPWriter, w)
			apiutils.SetVar(rctx, apiutils.CtxKeyAPIGwWebSocketWatch, true)
		}
		resp, md, err := request_RolloutV1_AutoWatchRollout_0(rctx, inboundMarshaler, client, req, pathParams)
		ctx = runtime.NewServerMetadataContext(ctx, md)
		if err != nil {
			runtime.HTTPError(ctx, outboundMarshaler, w, req, err)
			return
		}

		if ws {
			ic, ok := apiutils.GetVar(rctx, apiutils.CtxKeyAPIGwWebSocketConn)
			if !ok {
				runtime.HTTPError(ctx, outboundMarshaler, w, req, errors.New("error recovering we socket"))
				return
			}
			conn := ic.(*websocket.Conn)
			runtime.FowardResponseStreamToWebSocket(ctx, outboundMarshaler, w, req, conn, func() (proto.Message, error) { return resp.Recv() }, mux.GetForwardResponseOptions()...)
		} else {
			bs, ok := apiutils.GetVar(rctx, apiutils.CtxKeyAPIGwBinStreamReq)
			if !ok {
				runtime.HTTPError(ctx, outboundMarshaler, w, req, errors.New("error recovering binary stream information"))
				return
			}
			if bs.(bool) {
				runtime.ForwardBinaryResponseStream(ctx, outboundMarshaler, w, req, func() (proto.Message, error) { return resp.Recv() }, mux.GetForwardResponseOptions()...)
			} else {
				forward_RolloutV1_AutoWatchRollout_0(ctx, outboundMarshaler, w, req, func() (proto.Message, error) { return resp.Recv() }, mux.GetForwardResponseOptions()...)
			}
		}

	})

	mux.Handle("POST", pattern_RolloutV1_CreateRollout_0, func(w http.ResponseWriter, req *http.Request, pathParams map[string]string) {
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
		resp, md, err := request_RolloutV1_CreateRollout_0(rctx, inboundMarshaler, client, req, pathParams)
		ctx = runtime.NewServerMetadataContext(ctx, md)
		if err != nil {
			runtime.HTTPError(ctx, outboundMarshaler, w, req, err)
			return
		}

		forward_RolloutV1_CreateRollout_0(ctx, outboundMarshaler, w, req, resp, mux.GetForwardResponseOptions()...)

	})

	mux.Handle("POST", pattern_RolloutV1_StopRollout_0, func(w http.ResponseWriter, req *http.Request, pathParams map[string]string) {
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
		resp, md, err := request_RolloutV1_StopRollout_0(rctx, inboundMarshaler, client, req, pathParams)
		ctx = runtime.NewServerMetadataContext(ctx, md)
		if err != nil {
			runtime.HTTPError(ctx, outboundMarshaler, w, req, err)
			return
		}

		forward_RolloutV1_StopRollout_0(ctx, outboundMarshaler, w, req, resp, mux.GetForwardResponseOptions()...)

	})

	mux.Handle("POST", pattern_RolloutV1_UpdateRollout_0, func(w http.ResponseWriter, req *http.Request, pathParams map[string]string) {
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
		resp, md, err := request_RolloutV1_UpdateRollout_0(rctx, inboundMarshaler, client, req, pathParams)
		ctx = runtime.NewServerMetadataContext(ctx, md)
		if err != nil {
			runtime.HTTPError(ctx, outboundMarshaler, w, req, err)
			return
		}

		forward_RolloutV1_UpdateRollout_0(ctx, outboundMarshaler, w, req, resp, mux.GetForwardResponseOptions()...)

	})

	return nil
}

var (
	pattern_RolloutV1_AutoDeleteRollout_0 = runtime.MustPattern(runtime.NewPattern(1, []int{2, 0, 1, 0, 4, 1, 5, 1}, []string{"rollout", "O.Name"}, ""))

	pattern_RolloutV1_AutoGetRollout_0 = runtime.MustPattern(runtime.NewPattern(1, []int{2, 0, 1, 0, 4, 1, 5, 1}, []string{"rollout", "O.Name"}, ""))

	pattern_RolloutV1_AutoListRollout_0 = runtime.MustPattern(runtime.NewPattern(1, []int{2, 0}, []string{"rollout"}, ""))

	pattern_RolloutV1_AutoWatchRollout_0 = runtime.MustPattern(runtime.NewPattern(1, []int{2, 0, 2, 1}, []string{"watch", "rollout"}, ""))

	pattern_RolloutV1_CreateRollout_0 = runtime.MustPattern(runtime.NewPattern(1, []int{2, 0, 2, 1}, []string{"rollout", "CreateRollout"}, ""))

	pattern_RolloutV1_StopRollout_0 = runtime.MustPattern(runtime.NewPattern(1, []int{2, 0, 2, 1}, []string{"rollout", "StopRollout"}, ""))

	pattern_RolloutV1_UpdateRollout_0 = runtime.MustPattern(runtime.NewPattern(1, []int{2, 0, 2, 1}, []string{"rollout", "UpdateRollout"}, ""))
)

var (
	forward_RolloutV1_AutoDeleteRollout_0 = runtime.ForwardResponseMessage

	forward_RolloutV1_AutoGetRollout_0 = runtime.ForwardResponseMessage

	forward_RolloutV1_AutoListRollout_0 = runtime.ForwardResponseMessage

	forward_RolloutV1_AutoWatchRollout_0 = runtime.ForwardResponseStream

	forward_RolloutV1_CreateRollout_0 = runtime.ForwardResponseMessage

	forward_RolloutV1_StopRollout_0 = runtime.ForwardResponseMessage

	forward_RolloutV1_UpdateRollout_0 = runtime.ForwardResponseMessage
)
