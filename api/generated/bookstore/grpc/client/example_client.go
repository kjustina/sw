// Code generated by protoc-gen-grpc-pensando DO NOT EDIT.

package grpcclient

import (
	"context"
	"errors"
	oldlog "log"

	"github.com/go-kit/kit/endpoint"
	"github.com/go-kit/kit/tracing/opentracing"
	grpctransport "github.com/go-kit/kit/transport/grpc"
	stdopentracing "github.com/opentracing/opentracing-go"
	"google.golang.org/grpc"

	api "github.com/pensando/sw/api"
	bookstore "github.com/pensando/sw/api/generated/bookstore"
	listerwatcher "github.com/pensando/sw/api/listerwatcher"
	apiserver "github.com/pensando/sw/apiserver"
	"github.com/pensando/sw/utils/kvstore"
	"github.com/pensando/sw/utils/log"
)

// Dummy vars to suppress import errors
var _ api.TypeMeta
var _ listerwatcher.WatcherClient
var _ kvstore.Interface

// NewBookstoreV1 sets up a new client for BookstoreV1
func NewBookstoreV1(conn *grpc.ClientConn, logger log.Logger) bookstore.ServiceBookstoreV1Client {

	var lAutoAddBookEndpoint endpoint.Endpoint
	{
		lAutoAddBookEndpoint = grpctransport.NewClient(
			conn,
			"bookstore.BookstoreV1",
			"AutoAddBook",
			bookstore.EncodeGrpcReqBook,
			bookstore.DecodeGrpcRespBook,
			&bookstore.Book{},
			grpctransport.ClientBefore(opentracing.ToGRPCRequest(stdopentracing.GlobalTracer(), logger)),
			grpctransport.ClientBefore(dummyBefore),
		).Endpoint()
		lAutoAddBookEndpoint = opentracing.TraceClient(stdopentracing.GlobalTracer(), "BookstoreV1:AutoAddBook")(lAutoAddBookEndpoint)
	}
	var lAutoAddOrderEndpoint endpoint.Endpoint
	{
		lAutoAddOrderEndpoint = grpctransport.NewClient(
			conn,
			"bookstore.BookstoreV1",
			"AutoAddOrder",
			bookstore.EncodeGrpcReqOrder,
			bookstore.DecodeGrpcRespOrder,
			&bookstore.Order{},
			grpctransport.ClientBefore(opentracing.ToGRPCRequest(stdopentracing.GlobalTracer(), logger)),
			grpctransport.ClientBefore(dummyBefore),
		).Endpoint()
		lAutoAddOrderEndpoint = opentracing.TraceClient(stdopentracing.GlobalTracer(), "BookstoreV1:AutoAddOrder")(lAutoAddOrderEndpoint)
	}
	var lAutoAddPublisherEndpoint endpoint.Endpoint
	{
		lAutoAddPublisherEndpoint = grpctransport.NewClient(
			conn,
			"bookstore.BookstoreV1",
			"AutoAddPublisher",
			bookstore.EncodeGrpcReqPublisher,
			bookstore.DecodeGrpcRespPublisher,
			&bookstore.Publisher{},
			grpctransport.ClientBefore(opentracing.ToGRPCRequest(stdopentracing.GlobalTracer(), logger)),
			grpctransport.ClientBefore(dummyBefore),
		).Endpoint()
		lAutoAddPublisherEndpoint = opentracing.TraceClient(stdopentracing.GlobalTracer(), "BookstoreV1:AutoAddPublisher")(lAutoAddPublisherEndpoint)
	}
	var lAutoDeleteBookEndpoint endpoint.Endpoint
	{
		lAutoDeleteBookEndpoint = grpctransport.NewClient(
			conn,
			"bookstore.BookstoreV1",
			"AutoDeleteBook",
			bookstore.EncodeGrpcReqBook,
			bookstore.DecodeGrpcRespBook,
			&bookstore.Book{},
			grpctransport.ClientBefore(opentracing.ToGRPCRequest(stdopentracing.GlobalTracer(), logger)),
			grpctransport.ClientBefore(dummyBefore),
		).Endpoint()
		lAutoDeleteBookEndpoint = opentracing.TraceClient(stdopentracing.GlobalTracer(), "BookstoreV1:AutoDeleteBook")(lAutoDeleteBookEndpoint)
	}
	var lAutoDeleteOrderEndpoint endpoint.Endpoint
	{
		lAutoDeleteOrderEndpoint = grpctransport.NewClient(
			conn,
			"bookstore.BookstoreV1",
			"AutoDeleteOrder",
			bookstore.EncodeGrpcReqOrder,
			bookstore.DecodeGrpcRespOrder,
			&bookstore.Order{},
			grpctransport.ClientBefore(opentracing.ToGRPCRequest(stdopentracing.GlobalTracer(), logger)),
			grpctransport.ClientBefore(dummyBefore),
		).Endpoint()
		lAutoDeleteOrderEndpoint = opentracing.TraceClient(stdopentracing.GlobalTracer(), "BookstoreV1:AutoDeleteOrder")(lAutoDeleteOrderEndpoint)
	}
	var lAutoDeletePublisherEndpoint endpoint.Endpoint
	{
		lAutoDeletePublisherEndpoint = grpctransport.NewClient(
			conn,
			"bookstore.BookstoreV1",
			"AutoDeletePublisher",
			bookstore.EncodeGrpcReqPublisher,
			bookstore.DecodeGrpcRespPublisher,
			&bookstore.Publisher{},
			grpctransport.ClientBefore(opentracing.ToGRPCRequest(stdopentracing.GlobalTracer(), logger)),
			grpctransport.ClientBefore(dummyBefore),
		).Endpoint()
		lAutoDeletePublisherEndpoint = opentracing.TraceClient(stdopentracing.GlobalTracer(), "BookstoreV1:AutoDeletePublisher")(lAutoDeletePublisherEndpoint)
	}
	var lAutoGetBookEndpoint endpoint.Endpoint
	{
		lAutoGetBookEndpoint = grpctransport.NewClient(
			conn,
			"bookstore.BookstoreV1",
			"AutoGetBook",
			bookstore.EncodeGrpcReqBook,
			bookstore.DecodeGrpcRespBook,
			&bookstore.Book{},
			grpctransport.ClientBefore(opentracing.ToGRPCRequest(stdopentracing.GlobalTracer(), logger)),
			grpctransport.ClientBefore(dummyBefore),
		).Endpoint()
		lAutoGetBookEndpoint = opentracing.TraceClient(stdopentracing.GlobalTracer(), "BookstoreV1:AutoGetBook")(lAutoGetBookEndpoint)
	}
	var lAutoGetOrderEndpoint endpoint.Endpoint
	{
		lAutoGetOrderEndpoint = grpctransport.NewClient(
			conn,
			"bookstore.BookstoreV1",
			"AutoGetOrder",
			bookstore.EncodeGrpcReqOrder,
			bookstore.DecodeGrpcRespOrder,
			&bookstore.Order{},
			grpctransport.ClientBefore(opentracing.ToGRPCRequest(stdopentracing.GlobalTracer(), logger)),
			grpctransport.ClientBefore(dummyBefore),
		).Endpoint()
		lAutoGetOrderEndpoint = opentracing.TraceClient(stdopentracing.GlobalTracer(), "BookstoreV1:AutoGetOrder")(lAutoGetOrderEndpoint)
	}
	var lAutoGetPublisherEndpoint endpoint.Endpoint
	{
		lAutoGetPublisherEndpoint = grpctransport.NewClient(
			conn,
			"bookstore.BookstoreV1",
			"AutoGetPublisher",
			bookstore.EncodeGrpcReqPublisher,
			bookstore.DecodeGrpcRespPublisher,
			&bookstore.Publisher{},
			grpctransport.ClientBefore(opentracing.ToGRPCRequest(stdopentracing.GlobalTracer(), logger)),
			grpctransport.ClientBefore(dummyBefore),
		).Endpoint()
		lAutoGetPublisherEndpoint = opentracing.TraceClient(stdopentracing.GlobalTracer(), "BookstoreV1:AutoGetPublisher")(lAutoGetPublisherEndpoint)
	}
	var lAutoListBookEndpoint endpoint.Endpoint
	{
		lAutoListBookEndpoint = grpctransport.NewClient(
			conn,
			"bookstore.BookstoreV1",
			"AutoListBook",
			bookstore.EncodeGrpcReqListWatchOptions,
			bookstore.DecodeGrpcRespBookList,
			&bookstore.BookList{},
			grpctransport.ClientBefore(opentracing.ToGRPCRequest(stdopentracing.GlobalTracer(), logger)),
			grpctransport.ClientBefore(dummyBefore),
		).Endpoint()
		lAutoListBookEndpoint = opentracing.TraceClient(stdopentracing.GlobalTracer(), "BookstoreV1:AutoListBook")(lAutoListBookEndpoint)
	}
	var lAutoListOrderEndpoint endpoint.Endpoint
	{
		lAutoListOrderEndpoint = grpctransport.NewClient(
			conn,
			"bookstore.BookstoreV1",
			"AutoListOrder",
			bookstore.EncodeGrpcReqListWatchOptions,
			bookstore.DecodeGrpcRespOrderList,
			&bookstore.OrderList{},
			grpctransport.ClientBefore(opentracing.ToGRPCRequest(stdopentracing.GlobalTracer(), logger)),
			grpctransport.ClientBefore(dummyBefore),
		).Endpoint()
		lAutoListOrderEndpoint = opentracing.TraceClient(stdopentracing.GlobalTracer(), "BookstoreV1:AutoListOrder")(lAutoListOrderEndpoint)
	}
	var lAutoListPublisherEndpoint endpoint.Endpoint
	{
		lAutoListPublisherEndpoint = grpctransport.NewClient(
			conn,
			"bookstore.BookstoreV1",
			"AutoListPublisher",
			bookstore.EncodeGrpcReqListWatchOptions,
			bookstore.DecodeGrpcRespPublisherList,
			&bookstore.PublisherList{},
			grpctransport.ClientBefore(opentracing.ToGRPCRequest(stdopentracing.GlobalTracer(), logger)),
			grpctransport.ClientBefore(dummyBefore),
		).Endpoint()
		lAutoListPublisherEndpoint = opentracing.TraceClient(stdopentracing.GlobalTracer(), "BookstoreV1:AutoListPublisher")(lAutoListPublisherEndpoint)
	}
	var lAutoUpdateBookEndpoint endpoint.Endpoint
	{
		lAutoUpdateBookEndpoint = grpctransport.NewClient(
			conn,
			"bookstore.BookstoreV1",
			"AutoUpdateBook",
			bookstore.EncodeGrpcReqBook,
			bookstore.DecodeGrpcRespBook,
			&bookstore.Book{},
			grpctransport.ClientBefore(opentracing.ToGRPCRequest(stdopentracing.GlobalTracer(), logger)),
			grpctransport.ClientBefore(dummyBefore),
		).Endpoint()
		lAutoUpdateBookEndpoint = opentracing.TraceClient(stdopentracing.GlobalTracer(), "BookstoreV1:AutoUpdateBook")(lAutoUpdateBookEndpoint)
	}
	var lAutoUpdateOrderEndpoint endpoint.Endpoint
	{
		lAutoUpdateOrderEndpoint = grpctransport.NewClient(
			conn,
			"bookstore.BookstoreV1",
			"AutoUpdateOrder",
			bookstore.EncodeGrpcReqOrder,
			bookstore.DecodeGrpcRespOrder,
			&bookstore.Order{},
			grpctransport.ClientBefore(opentracing.ToGRPCRequest(stdopentracing.GlobalTracer(), logger)),
			grpctransport.ClientBefore(dummyBefore),
		).Endpoint()
		lAutoUpdateOrderEndpoint = opentracing.TraceClient(stdopentracing.GlobalTracer(), "BookstoreV1:AutoUpdateOrder")(lAutoUpdateOrderEndpoint)
	}
	var lAutoUpdatePublisherEndpoint endpoint.Endpoint
	{
		lAutoUpdatePublisherEndpoint = grpctransport.NewClient(
			conn,
			"bookstore.BookstoreV1",
			"AutoUpdatePublisher",
			bookstore.EncodeGrpcReqPublisher,
			bookstore.DecodeGrpcRespPublisher,
			&bookstore.Publisher{},
			grpctransport.ClientBefore(opentracing.ToGRPCRequest(stdopentracing.GlobalTracer(), logger)),
			grpctransport.ClientBefore(dummyBefore),
		).Endpoint()
		lAutoUpdatePublisherEndpoint = opentracing.TraceClient(stdopentracing.GlobalTracer(), "BookstoreV1:AutoUpdatePublisher")(lAutoUpdatePublisherEndpoint)
	}
	return bookstore.EndpointsBookstoreV1Client{
		Client: bookstore.NewBookstoreV1Client(conn),

		AutoAddBookEndpoint:         lAutoAddBookEndpoint,
		AutoAddOrderEndpoint:        lAutoAddOrderEndpoint,
		AutoAddPublisherEndpoint:    lAutoAddPublisherEndpoint,
		AutoDeleteBookEndpoint:      lAutoDeleteBookEndpoint,
		AutoDeleteOrderEndpoint:     lAutoDeleteOrderEndpoint,
		AutoDeletePublisherEndpoint: lAutoDeletePublisherEndpoint,
		AutoGetBookEndpoint:         lAutoGetBookEndpoint,
		AutoGetOrderEndpoint:        lAutoGetOrderEndpoint,
		AutoGetPublisherEndpoint:    lAutoGetPublisherEndpoint,
		AutoListBookEndpoint:        lAutoListBookEndpoint,
		AutoListOrderEndpoint:       lAutoListOrderEndpoint,
		AutoListPublisherEndpoint:   lAutoListPublisherEndpoint,
		AutoUpdateBookEndpoint:      lAutoUpdateBookEndpoint,
		AutoUpdateOrderEndpoint:     lAutoUpdateOrderEndpoint,
		AutoUpdatePublisherEndpoint: lAutoUpdatePublisherEndpoint,
	}
}

// NewBookstoreV1Backend creates an instrumented client with middleware
func NewBookstoreV1Backend(conn *grpc.ClientConn, logger log.Logger) bookstore.ServiceBookstoreV1Client {
	cl := NewBookstoreV1(conn, logger)
	cl = bookstore.LoggingBookstoreV1MiddlewareClient(logger)(cl)
	return cl
}

type grpcObjBookstoreV1Order struct {
	logger log.Logger
	client bookstore.ServiceBookstoreV1Client
}

func (a *grpcObjBookstoreV1Order) Create(ctx context.Context, in *bookstore.Order) (*bookstore.Order, error) {
	a.logger.DebugLog("msg", "recieved call", "object", "Order", "oper", "create")
	if in == nil {
		return nil, errors.New("invalid input")
	}
	nctx := addVersion(ctx, "v1")
	return a.client.AutoAddOrder(nctx, in)
}

func (a *grpcObjBookstoreV1Order) Update(ctx context.Context, in *bookstore.Order) (*bookstore.Order, error) {
	a.logger.DebugLog("msg", "received call", "object", "Order", "oper", "update")
	if in == nil {
		return nil, errors.New("invalid input")
	}
	nctx := addVersion(ctx, "v1")
	return a.client.AutoUpdateOrder(nctx, in)
}

func (a *grpcObjBookstoreV1Order) Get(ctx context.Context, objMeta *api.ObjectMeta) (*bookstore.Order, error) {
	a.logger.DebugLog("msg", "received call", "object", "Order", "oper", "get")
	if objMeta == nil {
		return nil, errors.New("invalid input")
	}
	in := bookstore.Order{}
	in.ObjectMeta = *objMeta
	nctx := addVersion(ctx, "v1")
	return a.client.AutoGetOrder(nctx, &in)
}

func (a *grpcObjBookstoreV1Order) Delete(ctx context.Context, objMeta *api.ObjectMeta) (*bookstore.Order, error) {
	a.logger.DebugLog("msg", "received call", "object", "Order", "oper", "delete")
	if objMeta == nil {
		return nil, errors.New("invalid input")
	}
	in := bookstore.Order{}
	in.ObjectMeta = *objMeta
	nctx := addVersion(ctx, "v1")
	return a.client.AutoDeleteOrder(nctx, &in)
}

func (a *grpcObjBookstoreV1Order) List(ctx context.Context, options *api.ListWatchOptions) ([]*bookstore.Order, error) {
	a.logger.DebugLog("msg", "received call", "object", "Order", "oper", "list")
	if options == nil {
		return nil, errors.New("invalid input")
	}
	nctx := addVersion(ctx, "v1")
	r, err := a.client.AutoListOrder(nctx, options)
	if err == nil {
		return r.Items, nil
	}
	return nil, err
}

func (a *grpcObjBookstoreV1Order) Watch(ctx context.Context, options *api.ListWatchOptions) (kvstore.Watcher, error) {
	a.logger.DebugLog("msg", "received call", "object", "Order", "oper", "WatchOper")
	nctx := addVersion(ctx, "v1")
	if options == nil {
		return nil, errors.New("invalid input")
	}
	stream, err := a.client.AutoWatchOrder(nctx, options)
	if err != nil {
		return nil, err
	}
	wstream := stream.(bookstore.BookstoreV1_AutoWatchOrderClient)
	bridgefn := func(lw *listerwatcher.WatcherClient) {
		for {
			r, err := wstream.Recv()
			if err != nil {
				a.logger.ErrorLog("msg", "error on recieve", "error", err)
				close(lw.OutCh)
				return
			}
			ev := kvstore.WatchEvent{
				Type:   kvstore.WatchEventType(r.Type),
				Object: r.Object,
			}
			lw.OutCh <- &ev
		}
	}
	lw := listerwatcher.NewWatcherClient(wstream, bridgefn)
	lw.Run()
	return lw, nil
}

func (a *grpcObjBookstoreV1Order) Allowed(oper apiserver.APIOperType) bool {
	return true
}

type restObjBookstoreV1Order struct {
	endpoints bookstore.EndpointsBookstoreV1RestClient
	instance  string
}

func (a *restObjBookstoreV1Order) Create(ctx context.Context, in *bookstore.Order) (*bookstore.Order, error) {
	if in == nil {
		return nil, errors.New("invalid input")
	}
	return a.endpoints.AutoAddOrder(ctx, in)
}

func (a *restObjBookstoreV1Order) Update(ctx context.Context, in *bookstore.Order) (*bookstore.Order, error) {
	if in == nil {
		return nil, errors.New("invalid input")
	}
	return a.endpoints.AutoUpdateOrder(ctx, in)
}

func (a *restObjBookstoreV1Order) Get(ctx context.Context, objMeta *api.ObjectMeta) (*bookstore.Order, error) {
	if objMeta == nil {
		return nil, errors.New("invalid input")
	}
	in := bookstore.Order{}
	in.ObjectMeta = *objMeta
	return a.endpoints.AutoGetOrder(ctx, &in)
}

func (a *restObjBookstoreV1Order) Delete(ctx context.Context, objMeta *api.ObjectMeta) (*bookstore.Order, error) {
	if objMeta == nil {
		return nil, errors.New("invalid input")
	}
	in := bookstore.Order{}
	in.ObjectMeta = *objMeta
	return a.endpoints.AutoDeleteOrder(ctx, &in)
}

func (a *restObjBookstoreV1Order) List(ctx context.Context, options *api.ListWatchOptions) ([]*bookstore.Order, error) {
	if options == nil {
		return nil, errors.New("invalid input")
	}
	r, err := a.endpoints.AutoListOrder(ctx, options)
	if err == nil {
		return r.Items, nil
	}
	return nil, err
}

func (a *restObjBookstoreV1Order) Watch(ctx context.Context, options *api.ListWatchOptions) (kvstore.Watcher, error) {
	return nil, errors.New("not allowed")
}

func (a *restObjBookstoreV1Order) Allowed(oper apiserver.APIOperType) bool {
	switch oper {
	case apiserver.CreateOper:
		return true
	case apiserver.UpdateOper:
		return true
	case apiserver.GetOper:
		return true
	case apiserver.DeleteOper:
		return true
	case apiserver.ListOper:
		return true
	case apiserver.WatchOper:
		return false
	default:
		return false
	}
}

type grpcObjBookstoreV1Book struct {
	logger log.Logger
	client bookstore.ServiceBookstoreV1Client
}

func (a *grpcObjBookstoreV1Book) Create(ctx context.Context, in *bookstore.Book) (*bookstore.Book, error) {
	a.logger.DebugLog("msg", "recieved call", "object", "Book", "oper", "create")
	if in == nil {
		return nil, errors.New("invalid input")
	}
	nctx := addVersion(ctx, "v1")
	return a.client.AutoAddBook(nctx, in)
}

func (a *grpcObjBookstoreV1Book) Update(ctx context.Context, in *bookstore.Book) (*bookstore.Book, error) {
	a.logger.DebugLog("msg", "received call", "object", "Book", "oper", "update")
	if in == nil {
		return nil, errors.New("invalid input")
	}
	nctx := addVersion(ctx, "v1")
	return a.client.AutoUpdateBook(nctx, in)
}

func (a *grpcObjBookstoreV1Book) Get(ctx context.Context, objMeta *api.ObjectMeta) (*bookstore.Book, error) {
	a.logger.DebugLog("msg", "received call", "object", "Book", "oper", "get")
	if objMeta == nil {
		return nil, errors.New("invalid input")
	}
	in := bookstore.Book{}
	in.ObjectMeta = *objMeta
	nctx := addVersion(ctx, "v1")
	return a.client.AutoGetBook(nctx, &in)
}

func (a *grpcObjBookstoreV1Book) Delete(ctx context.Context, objMeta *api.ObjectMeta) (*bookstore.Book, error) {
	a.logger.DebugLog("msg", "received call", "object", "Book", "oper", "delete")
	if objMeta == nil {
		return nil, errors.New("invalid input")
	}
	in := bookstore.Book{}
	in.ObjectMeta = *objMeta
	nctx := addVersion(ctx, "v1")
	return a.client.AutoDeleteBook(nctx, &in)
}

func (a *grpcObjBookstoreV1Book) List(ctx context.Context, options *api.ListWatchOptions) ([]*bookstore.Book, error) {
	a.logger.DebugLog("msg", "received call", "object", "Book", "oper", "list")
	if options == nil {
		return nil, errors.New("invalid input")
	}
	nctx := addVersion(ctx, "v1")
	r, err := a.client.AutoListBook(nctx, options)
	if err == nil {
		return r.Items, nil
	}
	return nil, err
}

func (a *grpcObjBookstoreV1Book) Watch(ctx context.Context, options *api.ListWatchOptions) (kvstore.Watcher, error) {
	a.logger.DebugLog("msg", "received call", "object", "Book", "oper", "WatchOper")
	nctx := addVersion(ctx, "v1")
	if options == nil {
		return nil, errors.New("invalid input")
	}
	stream, err := a.client.AutoWatchBook(nctx, options)
	if err != nil {
		return nil, err
	}
	wstream := stream.(bookstore.BookstoreV1_AutoWatchBookClient)
	bridgefn := func(lw *listerwatcher.WatcherClient) {
		for {
			r, err := wstream.Recv()
			if err != nil {
				a.logger.ErrorLog("msg", "error on recieve", "error", err)
				close(lw.OutCh)
				return
			}
			ev := kvstore.WatchEvent{
				Type:   kvstore.WatchEventType(r.Type),
				Object: r.Object,
			}
			lw.OutCh <- &ev
		}
	}
	lw := listerwatcher.NewWatcherClient(wstream, bridgefn)
	lw.Run()
	return lw, nil
}

func (a *grpcObjBookstoreV1Book) Allowed(oper apiserver.APIOperType) bool {
	return true
}

type restObjBookstoreV1Book struct {
	endpoints bookstore.EndpointsBookstoreV1RestClient
	instance  string
}

func (a *restObjBookstoreV1Book) Create(ctx context.Context, in *bookstore.Book) (*bookstore.Book, error) {
	if in == nil {
		return nil, errors.New("invalid input")
	}
	return a.endpoints.AutoAddBook(ctx, in)
}

func (a *restObjBookstoreV1Book) Update(ctx context.Context, in *bookstore.Book) (*bookstore.Book, error) {
	if in == nil {
		return nil, errors.New("invalid input")
	}
	return a.endpoints.AutoUpdateBook(ctx, in)
}

func (a *restObjBookstoreV1Book) Get(ctx context.Context, objMeta *api.ObjectMeta) (*bookstore.Book, error) {
	if objMeta == nil {
		return nil, errors.New("invalid input")
	}
	in := bookstore.Book{}
	in.ObjectMeta = *objMeta
	return a.endpoints.AutoGetBook(ctx, &in)
}

func (a *restObjBookstoreV1Book) Delete(ctx context.Context, objMeta *api.ObjectMeta) (*bookstore.Book, error) {
	if objMeta == nil {
		return nil, errors.New("invalid input")
	}
	in := bookstore.Book{}
	in.ObjectMeta = *objMeta
	return a.endpoints.AutoDeleteBook(ctx, &in)
}

func (a *restObjBookstoreV1Book) List(ctx context.Context, options *api.ListWatchOptions) ([]*bookstore.Book, error) {
	if options == nil {
		return nil, errors.New("invalid input")
	}
	r, err := a.endpoints.AutoListBook(ctx, options)
	if err == nil {
		return r.Items, nil
	}
	return nil, err
}

func (a *restObjBookstoreV1Book) Watch(ctx context.Context, options *api.ListWatchOptions) (kvstore.Watcher, error) {
	return nil, errors.New("not allowed")
}

func (a *restObjBookstoreV1Book) Allowed(oper apiserver.APIOperType) bool {
	switch oper {
	case apiserver.CreateOper:
		return false
	case apiserver.UpdateOper:
		return false
	case apiserver.GetOper:
		return true
	case apiserver.DeleteOper:
		return false
	case apiserver.ListOper:
		return false
	case apiserver.WatchOper:
		return false
	default:
		return false
	}
}

type grpcObjBookstoreV1Publisher struct {
	logger log.Logger
	client bookstore.ServiceBookstoreV1Client
}

func (a *grpcObjBookstoreV1Publisher) Create(ctx context.Context, in *bookstore.Publisher) (*bookstore.Publisher, error) {
	a.logger.DebugLog("msg", "recieved call", "object", "Publisher", "oper", "create")
	if in == nil {
		return nil, errors.New("invalid input")
	}
	nctx := addVersion(ctx, "v1")
	return a.client.AutoAddPublisher(nctx, in)
}

func (a *grpcObjBookstoreV1Publisher) Update(ctx context.Context, in *bookstore.Publisher) (*bookstore.Publisher, error) {
	a.logger.DebugLog("msg", "received call", "object", "Publisher", "oper", "update")
	if in == nil {
		return nil, errors.New("invalid input")
	}
	nctx := addVersion(ctx, "v1")
	return a.client.AutoUpdatePublisher(nctx, in)
}

func (a *grpcObjBookstoreV1Publisher) Get(ctx context.Context, objMeta *api.ObjectMeta) (*bookstore.Publisher, error) {
	a.logger.DebugLog("msg", "received call", "object", "Publisher", "oper", "get")
	if objMeta == nil {
		return nil, errors.New("invalid input")
	}
	in := bookstore.Publisher{}
	in.ObjectMeta = *objMeta
	nctx := addVersion(ctx, "v1")
	return a.client.AutoGetPublisher(nctx, &in)
}

func (a *grpcObjBookstoreV1Publisher) Delete(ctx context.Context, objMeta *api.ObjectMeta) (*bookstore.Publisher, error) {
	a.logger.DebugLog("msg", "received call", "object", "Publisher", "oper", "delete")
	if objMeta == nil {
		return nil, errors.New("invalid input")
	}
	in := bookstore.Publisher{}
	in.ObjectMeta = *objMeta
	nctx := addVersion(ctx, "v1")
	return a.client.AutoDeletePublisher(nctx, &in)
}

func (a *grpcObjBookstoreV1Publisher) List(ctx context.Context, options *api.ListWatchOptions) ([]*bookstore.Publisher, error) {
	a.logger.DebugLog("msg", "received call", "object", "Publisher", "oper", "list")
	if options == nil {
		return nil, errors.New("invalid input")
	}
	nctx := addVersion(ctx, "v1")
	r, err := a.client.AutoListPublisher(nctx, options)
	if err == nil {
		return r.Items, nil
	}
	return nil, err
}

func (a *grpcObjBookstoreV1Publisher) Watch(ctx context.Context, options *api.ListWatchOptions) (kvstore.Watcher, error) {
	a.logger.DebugLog("msg", "received call", "object", "Publisher", "oper", "WatchOper")
	nctx := addVersion(ctx, "v1")
	if options == nil {
		return nil, errors.New("invalid input")
	}
	stream, err := a.client.AutoWatchPublisher(nctx, options)
	if err != nil {
		return nil, err
	}
	wstream := stream.(bookstore.BookstoreV1_AutoWatchPublisherClient)
	bridgefn := func(lw *listerwatcher.WatcherClient) {
		for {
			r, err := wstream.Recv()
			if err != nil {
				a.logger.ErrorLog("msg", "error on recieve", "error", err)
				close(lw.OutCh)
				return
			}
			ev := kvstore.WatchEvent{
				Type:   kvstore.WatchEventType(r.Type),
				Object: r.Object,
			}
			lw.OutCh <- &ev
		}
	}
	lw := listerwatcher.NewWatcherClient(wstream, bridgefn)
	lw.Run()
	return lw, nil
}

func (a *grpcObjBookstoreV1Publisher) Allowed(oper apiserver.APIOperType) bool {
	return true
}

type restObjBookstoreV1Publisher struct {
	endpoints bookstore.EndpointsBookstoreV1RestClient
	instance  string
}

func (a *restObjBookstoreV1Publisher) Create(ctx context.Context, in *bookstore.Publisher) (*bookstore.Publisher, error) {
	if in == nil {
		return nil, errors.New("invalid input")
	}
	return a.endpoints.AutoAddPublisher(ctx, in)
}

func (a *restObjBookstoreV1Publisher) Update(ctx context.Context, in *bookstore.Publisher) (*bookstore.Publisher, error) {
	if in == nil {
		return nil, errors.New("invalid input")
	}
	return a.endpoints.AutoUpdatePublisher(ctx, in)
}

func (a *restObjBookstoreV1Publisher) Get(ctx context.Context, objMeta *api.ObjectMeta) (*bookstore.Publisher, error) {
	if objMeta == nil {
		return nil, errors.New("invalid input")
	}
	in := bookstore.Publisher{}
	in.ObjectMeta = *objMeta
	return a.endpoints.AutoGetPublisher(ctx, &in)
}

func (a *restObjBookstoreV1Publisher) Delete(ctx context.Context, objMeta *api.ObjectMeta) (*bookstore.Publisher, error) {
	if objMeta == nil {
		return nil, errors.New("invalid input")
	}
	in := bookstore.Publisher{}
	in.ObjectMeta = *objMeta
	return a.endpoints.AutoDeletePublisher(ctx, &in)
}

func (a *restObjBookstoreV1Publisher) List(ctx context.Context, options *api.ListWatchOptions) ([]*bookstore.Publisher, error) {
	if options == nil {
		return nil, errors.New("invalid input")
	}
	r, err := a.endpoints.AutoListPublisher(ctx, options)
	if err == nil {
		return r.Items, nil
	}
	return nil, err
}

func (a *restObjBookstoreV1Publisher) Watch(ctx context.Context, options *api.ListWatchOptions) (kvstore.Watcher, error) {
	return nil, errors.New("not allowed")
}

func (a *restObjBookstoreV1Publisher) Allowed(oper apiserver.APIOperType) bool {
	switch oper {
	case apiserver.CreateOper:
		return false
	case apiserver.UpdateOper:
		return false
	case apiserver.GetOper:
		return false
	case apiserver.DeleteOper:
		return false
	case apiserver.ListOper:
		return false
	case apiserver.WatchOper:
		return false
	default:
		return false
	}
}

type crudClientBookstoreV1 struct {
	grpcOrder     bookstore.OrderInterface
	grpcBook      bookstore.BookInterface
	grpcPublisher bookstore.PublisherInterface
}

// NewGrpcCrudClientBookstoreV1 creates a GRPC client for the service
func NewGrpcCrudClientBookstoreV1(conn *grpc.ClientConn, logger log.Logger) bookstore.BookstoreV1Interface {
	client := NewBookstoreV1Backend(conn, logger)
	return &crudClientBookstoreV1{

		grpcOrder:     &grpcObjBookstoreV1Order{client: client, logger: logger},
		grpcBook:      &grpcObjBookstoreV1Book{client: client, logger: logger},
		grpcPublisher: &grpcObjBookstoreV1Publisher{client: client, logger: logger},
	}
}

func (a *crudClientBookstoreV1) Order() bookstore.OrderInterface {
	return a.grpcOrder
}

func (a *crudClientBookstoreV1) Book() bookstore.BookInterface {
	return a.grpcBook
}

func (a *crudClientBookstoreV1) Publisher() bookstore.PublisherInterface {
	return a.grpcPublisher
}

type crudRestClientBookstoreV1 struct {
	restOrder     bookstore.OrderInterface
	restBook      bookstore.BookInterface
	restPublisher bookstore.PublisherInterface
}

// NewRestCrudClientBookstoreV1 creates a REST client for the service.
func NewRestCrudClientBookstoreV1(url string) bookstore.BookstoreV1Interface {
	endpoints, err := bookstore.MakeBookstoreV1RestClientEndpoints(url)
	if err != nil {
		oldlog.Fatal("failed to create client")
	}
	return &crudRestClientBookstoreV1{

		restOrder:     &restObjBookstoreV1Order{endpoints: endpoints, instance: url},
		restBook:      &restObjBookstoreV1Book{endpoints: endpoints, instance: url},
		restPublisher: &restObjBookstoreV1Publisher{endpoints: endpoints, instance: url},
	}
}

func (a *crudRestClientBookstoreV1) Order() bookstore.OrderInterface {
	return a.restOrder
}

func (a *crudRestClientBookstoreV1) Book() bookstore.BookInterface {
	return a.restBook
}

func (a *crudRestClientBookstoreV1) Publisher() bookstore.PublisherInterface {
	return a.restPublisher
}
