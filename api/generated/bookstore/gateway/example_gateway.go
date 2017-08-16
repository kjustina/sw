// Code generated by protoc-gen-grpc-pensando DO NOT EDIT.

/*
Package bookstoreGwService is a auto generated package.
Input file: protos/example.proto
*/
package bookstoreGwService

import (
	"context"
	"net/http"
	"time"

	"github.com/GeertJohan/go.rice"
	gogocodec "github.com/gogo/protobuf/codec"
	"github.com/pkg/errors"
	oldcontext "golang.org/x/net/context"
	"google.golang.org/grpc"

	"github.com/pensando/grpc-gateway/runtime"
	"github.com/pensando/sw/api"
	bookstore "github.com/pensando/sw/api/generated/bookstore"
	"github.com/pensando/sw/api/generated/bookstore/grpc/client"
	"github.com/pensando/sw/apigw/pkg"
	"github.com/pensando/sw/utils/log"
)

// Dummy vars to suppress import errors
var _ api.TypeMeta

const codecSize = 1024 * 1024

type sBookstoreV1GwService struct {
	logger log.Logger
}

type adapterBookstoreV1 struct {
	service bookstore.ServiceBookstoreV1Client
}

func (a adapterBookstoreV1) AutoAddBook(oldctx oldcontext.Context, t *bookstore.Book, options ...grpc.CallOption) (*bookstore.Book, error) {
	// Not using options for now. Will be passed through context as needed.
	ctx := context.Context(oldctx)
	return a.service.AutoAddBook(ctx, t)
}

func (a adapterBookstoreV1) AutoAddOrder(oldctx oldcontext.Context, t *bookstore.Order, options ...grpc.CallOption) (*bookstore.Order, error) {
	// Not using options for now. Will be passed through context as needed.
	ctx := context.Context(oldctx)
	return a.service.AutoAddOrder(ctx, t)
}

func (a adapterBookstoreV1) AutoAddPublisher(oldctx oldcontext.Context, t *bookstore.Publisher, options ...grpc.CallOption) (*bookstore.Publisher, error) {
	// Not using options for now. Will be passed through context as needed.
	ctx := context.Context(oldctx)
	return a.service.AutoAddPublisher(ctx, t)
}

func (a adapterBookstoreV1) AutoDeleteBook(oldctx oldcontext.Context, t *bookstore.Book, options ...grpc.CallOption) (*bookstore.Book, error) {
	// Not using options for now. Will be passed through context as needed.
	ctx := context.Context(oldctx)
	return a.service.AutoDeleteBook(ctx, t)
}

func (a adapterBookstoreV1) AutoDeleteOrder(oldctx oldcontext.Context, t *bookstore.Order, options ...grpc.CallOption) (*bookstore.Order, error) {
	// Not using options for now. Will be passed through context as needed.
	ctx := context.Context(oldctx)
	return a.service.AutoDeleteOrder(ctx, t)
}

func (a adapterBookstoreV1) AutoDeletePublisher(oldctx oldcontext.Context, t *bookstore.Publisher, options ...grpc.CallOption) (*bookstore.Publisher, error) {
	// Not using options for now. Will be passed through context as needed.
	ctx := context.Context(oldctx)
	return a.service.AutoDeletePublisher(ctx, t)
}

func (a adapterBookstoreV1) AutoGetBook(oldctx oldcontext.Context, t *bookstore.Book, options ...grpc.CallOption) (*bookstore.Book, error) {
	// Not using options for now. Will be passed through context as needed.
	ctx := context.Context(oldctx)
	return a.service.AutoGetBook(ctx, t)
}

func (a adapterBookstoreV1) AutoGetOrder(oldctx oldcontext.Context, t *bookstore.Order, options ...grpc.CallOption) (*bookstore.Order, error) {
	// Not using options for now. Will be passed through context as needed.
	ctx := context.Context(oldctx)
	return a.service.AutoGetOrder(ctx, t)
}

func (a adapterBookstoreV1) AutoGetPublisher(oldctx oldcontext.Context, t *bookstore.Publisher, options ...grpc.CallOption) (*bookstore.Publisher, error) {
	// Not using options for now. Will be passed through context as needed.
	ctx := context.Context(oldctx)
	return a.service.AutoGetPublisher(ctx, t)
}

func (a adapterBookstoreV1) AutoListBook(oldctx oldcontext.Context, t *api.ListWatchOptions, options ...grpc.CallOption) (*bookstore.AutoMsgBookListHelper, error) {
	// Not using options for now. Will be passed through context as needed.
	ctx := context.Context(oldctx)
	return a.service.AutoListBook(ctx, t)
}

func (a adapterBookstoreV1) AutoListOrder(oldctx oldcontext.Context, t *api.ListWatchOptions, options ...grpc.CallOption) (*bookstore.AutoMsgOrderListHelper, error) {
	// Not using options for now. Will be passed through context as needed.
	ctx := context.Context(oldctx)
	return a.service.AutoListOrder(ctx, t)
}

func (a adapterBookstoreV1) AutoListPublisher(oldctx oldcontext.Context, t *api.ListWatchOptions, options ...grpc.CallOption) (*bookstore.AutoMsgPublisherListHelper, error) {
	// Not using options for now. Will be passed through context as needed.
	ctx := context.Context(oldctx)
	return a.service.AutoListPublisher(ctx, t)
}

func (a adapterBookstoreV1) AutoUpdateBook(oldctx oldcontext.Context, t *bookstore.Book, options ...grpc.CallOption) (*bookstore.Book, error) {
	// Not using options for now. Will be passed through context as needed.
	ctx := context.Context(oldctx)
	return a.service.AutoUpdateBook(ctx, t)
}

func (a adapterBookstoreV1) AutoUpdateOrder(oldctx oldcontext.Context, t *bookstore.Order, options ...grpc.CallOption) (*bookstore.Order, error) {
	// Not using options for now. Will be passed through context as needed.
	ctx := context.Context(oldctx)
	return a.service.AutoUpdateOrder(ctx, t)
}

func (a adapterBookstoreV1) AutoUpdatePublisher(oldctx oldcontext.Context, t *bookstore.Publisher, options ...grpc.CallOption) (*bookstore.Publisher, error) {
	// Not using options for now. Will be passed through context as needed.
	ctx := context.Context(oldctx)
	return a.service.AutoUpdatePublisher(ctx, t)
}

func (a adapterBookstoreV1) AutoWatchOrder(oldctx oldcontext.Context, in *api.ListWatchOptions, options ...grpc.CallOption) (bookstore.BookstoreV1_AutoWatchOrderClient, error) {
	ctx := context.Context(oldctx)
	return a.service.AutoWatchOrder(ctx, in)
}

func (a adapterBookstoreV1) AutoWatchBook(oldctx oldcontext.Context, in *api.ListWatchOptions, options ...grpc.CallOption) (bookstore.BookstoreV1_AutoWatchBookClient, error) {
	ctx := context.Context(oldctx)
	return a.service.AutoWatchBook(ctx, in)
}

func (a adapterBookstoreV1) AutoWatchPublisher(oldctx oldcontext.Context, in *api.ListWatchOptions, options ...grpc.CallOption) (bookstore.BookstoreV1_AutoWatchPublisherClient, error) {
	ctx := context.Context(oldctx)
	return a.service.AutoWatchPublisher(ctx, in)
}

func (e *sBookstoreV1GwService) CompleteRegistration(ctx context.Context,
	logger log.Logger,
	grpcserver *grpc.Server,
	m *http.ServeMux) error {
	apigw := apigwpkg.MustGetAPIGateway()
	// IP:port destination or service discovery key.

	grpcaddr := "localhost:8082"
	grpcaddr = apigw.GetAPIServerAddr(grpcaddr)
	e.logger = logger
	codec := gogocodec.New(codecSize)
	cl, err := e.newClient(ctx, grpcaddr, grpc.WithInsecure(), grpc.WithTimeout(time.Second), grpc.WithCodec(codec))
	if cl == nil || err != nil {
		err = errors.Wrap(err, "could not create client")
		return err
	}
	marshaller := runtime.JSONBuiltin{}
	opts := runtime.WithMarshalerOption("*", &marshaller)
	mux := runtime.NewServeMux(opts)
	err = bookstore.RegisterBookstoreV1HandlerWithClient(ctx, mux, cl)
	if err != nil {
		err = errors.Wrap(err, "service registration failed")
		return err
	}
	logger.InfoLog("msg", "registered service bookstore.BookstoreV1")
	m.Handle("/v1/bookstore/", http.StripPrefix("/v1/bookstore", mux))
	err = registerSwaggerDef(m, logger)
	return err
}

func (e *sBookstoreV1GwService) newClient(ctx context.Context, grpcAddr string, opts ...grpc.DialOption) (bookstore.BookstoreV1Client, error) {
	conn, err := grpc.Dial(grpcAddr, opts...)
	if err != nil {
		err = errors.Wrap(err, "dial failed")
		if cerr := conn.Close(); cerr != nil {
			e.logger.ErrorLog("msg", "Failed to close conn", "addr", grpcAddr, "error", cerr)
		}
		return nil, err
	}
	e.logger.Infof("Connected to GRPC Server %s", grpcAddr)
	defer func() {
		go func() {
			<-ctx.Done()
			if cerr := conn.Close(); cerr != nil {
				e.logger.ErrorLog("msg", "Failed to close conn on Done()", "addr", grpcAddr, "error", cerr)
			}
		}()
	}()

	cl := adapterBookstoreV1{grpcclient.NewBookstoreV1Backend(conn, e.logger)}
	return cl, nil
}

func registerSwaggerDef(m *http.ServeMux, logger log.Logger) error {
	box, err := rice.FindBox("../../../../../sw/api/generated/bookstore/swagger")
	if err != nil {
		err = errors.Wrap(err, "error opening rice.Box")
		return err
	}
	content, err := box.Bytes("example.swagger.json")
	if err != nil {
		err = errors.Wrap(err, "error opening rice.File")
		return err
	}
	m.HandleFunc("/swagger/bookstore/", func(w http.ResponseWriter, r *http.Request) {
		w.Write(content)
	})
	return nil
}

func init() {
	apigw := apigwpkg.MustGetAPIGateway()

	svcBookstoreV1 := sBookstoreV1GwService{}
	apigw.Register("bookstore.BookstoreV1", "bookstore/", &svcBookstoreV1)
}
