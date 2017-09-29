// Code generated by protoc-gen-grpc-pensando DO NOT EDIT.

/*
Package bookstoreApiServer is a auto generated package.
Input file: protos/example.proto
*/
package bookstoreApiServer

import (
	"context"
	"fmt"

	"github.com/pkg/errors"
	"google.golang.org/grpc"

	"github.com/pensando/sw/api"
	bookstore "github.com/pensando/sw/api/generated/bookstore"
	"github.com/pensando/sw/api/listerwatcher"
	"github.com/pensando/sw/venice/apiserver"
	"github.com/pensando/sw/venice/apiserver/pkg"
	"github.com/pensando/sw/venice/utils/kvstore"
	"github.com/pensando/sw/venice/utils/log"
	"github.com/pensando/sw/venice/utils/rpckit"
	"github.com/pensando/sw/venice/utils/runtime"
)

// dummy vars to suppress unused errors
var _ api.ObjectMeta
var _ listerwatcher.WatcherClient
var _ fmt.Stringer

type sbookstoreExampleBackend struct {
	Services map[string]apiserver.Service
	Messages map[string]apiserver.Message

	endpointsBookstoreV1 *eBookstoreV1Endpoints
}

type eBookstoreV1Endpoints struct {
	Svc sbookstoreExampleBackend

	fnAutoAddBook         func(ctx context.Context, t interface{}) (interface{}, error)
	fnAutoAddOrder        func(ctx context.Context, t interface{}) (interface{}, error)
	fnAutoAddPublisher    func(ctx context.Context, t interface{}) (interface{}, error)
	fnAutoDeleteBook      func(ctx context.Context, t interface{}) (interface{}, error)
	fnAutoDeleteOrder     func(ctx context.Context, t interface{}) (interface{}, error)
	fnAutoDeletePublisher func(ctx context.Context, t interface{}) (interface{}, error)
	fnAutoGetBook         func(ctx context.Context, t interface{}) (interface{}, error)
	fnAutoGetOrder        func(ctx context.Context, t interface{}) (interface{}, error)
	fnAutoGetPublisher    func(ctx context.Context, t interface{}) (interface{}, error)
	fnAutoListBook        func(ctx context.Context, t interface{}) (interface{}, error)
	fnAutoListOrder       func(ctx context.Context, t interface{}) (interface{}, error)
	fnAutoListPublisher   func(ctx context.Context, t interface{}) (interface{}, error)
	fnAutoUpdateBook      func(ctx context.Context, t interface{}) (interface{}, error)
	fnAutoUpdateOrder     func(ctx context.Context, t interface{}) (interface{}, error)
	fnAutoUpdatePublisher func(ctx context.Context, t interface{}) (interface{}, error)

	fnAutoWatchOrder     func(in *api.ListWatchOptions, stream grpc.ServerStream, svcprefix string) error
	fnAutoWatchBook      func(in *api.ListWatchOptions, stream grpc.ServerStream, svcprefix string) error
	fnAutoWatchPublisher func(in *api.ListWatchOptions, stream grpc.ServerStream, svcprefix string) error
}

func (s *sbookstoreExampleBackend) CompleteRegistration(ctx context.Context, logger log.Logger,
	grpcserver *rpckit.RPCServer, scheme *runtime.Scheme) error {
	s.Messages = map[string]apiserver.Message{

		"bookstore.AutoMsgBookWatchHelper":      apisrvpkg.NewMessage("bookstore.AutoMsgBookWatchHelper"),
		"bookstore.AutoMsgOrderWatchHelper":     apisrvpkg.NewMessage("bookstore.AutoMsgOrderWatchHelper"),
		"bookstore.AutoMsgPublisherWatchHelper": apisrvpkg.NewMessage("bookstore.AutoMsgPublisherWatchHelper"),
		"bookstore.Book": apisrvpkg.NewMessage("bookstore.Book").WithKeyGenerator(func(i interface{}, prefix string) string {
			if i == nil {
				r := bookstore.Book{}
				return r.MakeKey(prefix)
			}
			r := i.(bookstore.Book)
			return r.MakeKey(prefix)
		}).WithObjectVersionWriter(func(i interface{}, version string) interface{} {
			r := i.(bookstore.Book)
			r.APIVersion = version
			return r
		}).WithKvUpdater(func(ctx context.Context, kvs kvstore.Interface, i interface{}, prefix string, create, ignoreStatus bool) (interface{}, error) {
			r := i.(bookstore.Book)
			key := r.MakeKey(prefix)
			r.Kind = "Book"
			var err error
			if create {
				err = kvs.Create(ctx, key, &r)
				err = errors.Wrap(err, "KV create failed")
			} else {
				if ignoreStatus {
					updateFunc := func(obj runtime.Object) (runtime.Object, error) {
						saved := obj.(*bookstore.Book)
						if r.ResourceVersion != "" && r.ResourceVersion != saved.ResourceVersion {
							return nil, fmt.Errorf("Resource Version specified does not match Object version")
						}
						r.Status = saved.Status
						return &r, nil
					}
					into := &bookstore.Book{}
					err = kvs.ConsistentUpdate(ctx, key, into, updateFunc)
				} else {
					if r.ResourceVersion != "" {
						logger.Infof("resource version is specified %s\n", r.ResourceVersion)
						err = kvs.Update(ctx, key, &r, kvstore.Compare(kvstore.WithVersion(key), "=", r.ResourceVersion))
					} else {
						err = kvs.Update(ctx, key, &r)
					}
					err = errors.Wrap(err, "KV update failed")
				}
			}
			return r, err
		}).WithKvTxnUpdater(func(ctx context.Context, txn kvstore.Txn, i interface{}, prefix string, create bool) error {
			r := i.(bookstore.Book)
			key := r.MakeKey(prefix)
			var err error
			if create {
				err = txn.Create(key, &r)
				err = errors.Wrap(err, "KV transaction create failed")
			} else {
				err = txn.Update(key, &r)
				err = errors.Wrap(err, "KV transaction update failed")
			}
			return err
		}).WithKvGetter(func(ctx context.Context, kvs kvstore.Interface, key string) (interface{}, error) {
			r := bookstore.Book{}
			err := kvs.Get(ctx, key, &r)
			err = errors.Wrap(err, "KV get failed")
			return r, err
		}).WithKvDelFunc(func(ctx context.Context, kvs kvstore.Interface, key string) (interface{}, error) {
			r := bookstore.Book{}
			err := kvs.Delete(ctx, key, &r)
			return r, err
		}).WithKvTxnDelFunc(func(ctx context.Context, txn kvstore.Txn, key string) error {
			return txn.Delete(key)
		}).WithValidate(func(i interface{}, ver string, ignoreStatus bool) error {
			r := i.(bookstore.Book)
			if !r.Validate(ver, ignoreStatus) {
				return fmt.Errorf("Default Validation failed")
			}
			return nil
		}),
		"bookstore.BookList": apisrvpkg.NewMessage("bookstore.BookList").WithKvListFunc(func(ctx context.Context, kvs kvstore.Interface, options *api.ListWatchOptions, prefix string) (interface{}, error) {

			into := bookstore.BookList{}
			r := bookstore.Book{}
			key := r.MakeKey(prefix)
			err := kvs.List(ctx, key, &into)
			if err != nil {
				return nil, err
			}
			return into, nil
		}),
		"bookstore.BookSpec":   apisrvpkg.NewMessage("bookstore.BookSpec"),
		"bookstore.BookStatus": apisrvpkg.NewMessage("bookstore.BookStatus"),
		"bookstore.Order": apisrvpkg.NewMessage("bookstore.Order").WithKeyGenerator(func(i interface{}, prefix string) string {
			if i == nil {
				r := bookstore.Order{}
				return r.MakeKey(prefix)
			}
			r := i.(bookstore.Order)
			return r.MakeKey(prefix)
		}).WithObjectVersionWriter(func(i interface{}, version string) interface{} {
			r := i.(bookstore.Order)
			r.APIVersion = version
			return r
		}).WithKvUpdater(func(ctx context.Context, kvs kvstore.Interface, i interface{}, prefix string, create, ignoreStatus bool) (interface{}, error) {
			r := i.(bookstore.Order)
			key := r.MakeKey(prefix)
			r.Kind = "Order"
			var err error
			if create {
				err = kvs.Create(ctx, key, &r)
				err = errors.Wrap(err, "KV create failed")
			} else {
				if ignoreStatus {
					updateFunc := func(obj runtime.Object) (runtime.Object, error) {
						saved := obj.(*bookstore.Order)
						if r.ResourceVersion != "" && r.ResourceVersion != saved.ResourceVersion {
							return nil, fmt.Errorf("Resource Version specified does not match Object version")
						}
						r.Status = saved.Status
						return &r, nil
					}
					into := &bookstore.Order{}
					err = kvs.ConsistentUpdate(ctx, key, into, updateFunc)
				} else {
					if r.ResourceVersion != "" {
						logger.Infof("resource version is specified %s\n", r.ResourceVersion)
						err = kvs.Update(ctx, key, &r, kvstore.Compare(kvstore.WithVersion(key), "=", r.ResourceVersion))
					} else {
						err = kvs.Update(ctx, key, &r)
					}
					err = errors.Wrap(err, "KV update failed")
				}
			}
			return r, err
		}).WithKvTxnUpdater(func(ctx context.Context, txn kvstore.Txn, i interface{}, prefix string, create bool) error {
			r := i.(bookstore.Order)
			key := r.MakeKey(prefix)
			var err error
			if create {
				err = txn.Create(key, &r)
				err = errors.Wrap(err, "KV transaction create failed")
			} else {
				err = txn.Update(key, &r)
				err = errors.Wrap(err, "KV transaction update failed")
			}
			return err
		}).WithKvGetter(func(ctx context.Context, kvs kvstore.Interface, key string) (interface{}, error) {
			r := bookstore.Order{}
			err := kvs.Get(ctx, key, &r)
			err = errors.Wrap(err, "KV get failed")
			return r, err
		}).WithKvDelFunc(func(ctx context.Context, kvs kvstore.Interface, key string) (interface{}, error) {
			r := bookstore.Order{}
			err := kvs.Delete(ctx, key, &r)
			return r, err
		}).WithKvTxnDelFunc(func(ctx context.Context, txn kvstore.Txn, key string) error {
			return txn.Delete(key)
		}).WithValidate(func(i interface{}, ver string, ignoreStatus bool) error {
			r := i.(bookstore.Order)
			if !r.Validate(ver, ignoreStatus) {
				return fmt.Errorf("Default Validation failed")
			}
			return nil
		}),
		"bookstore.OrderItem": apisrvpkg.NewMessage("bookstore.OrderItem"),
		"bookstore.OrderList": apisrvpkg.NewMessage("bookstore.OrderList").WithKvListFunc(func(ctx context.Context, kvs kvstore.Interface, options *api.ListWatchOptions, prefix string) (interface{}, error) {

			into := bookstore.OrderList{}
			r := bookstore.Order{}
			key := r.MakeKey(prefix)
			err := kvs.List(ctx, key, &into)
			if err != nil {
				return nil, err
			}
			return into, nil
		}),
		"bookstore.OrderSpec":   apisrvpkg.NewMessage("bookstore.OrderSpec"),
		"bookstore.OrderStatus": apisrvpkg.NewMessage("bookstore.OrderStatus"),
		"bookstore.Publisher": apisrvpkg.NewMessage("bookstore.Publisher").WithKeyGenerator(func(i interface{}, prefix string) string {
			if i == nil {
				r := bookstore.Publisher{}
				return r.MakeKey(prefix)
			}
			r := i.(bookstore.Publisher)
			return r.MakeKey(prefix)
		}).WithObjectVersionWriter(func(i interface{}, version string) interface{} {
			r := i.(bookstore.Publisher)
			r.APIVersion = version
			return r
		}).WithKvUpdater(func(ctx context.Context, kvs kvstore.Interface, i interface{}, prefix string, create, ignoreStatus bool) (interface{}, error) {
			r := i.(bookstore.Publisher)
			key := r.MakeKey(prefix)
			r.Kind = "Publisher"
			var err error
			if create {
				err = kvs.Create(ctx, key, &r)
				err = errors.Wrap(err, "KV create failed")
			} else {
				if r.ResourceVersion != "" {
					logger.Infof("resource version is specified %s\n", r.ResourceVersion)
					err = kvs.Update(ctx, key, &r, kvstore.Compare(kvstore.WithVersion(key), "=", r.ResourceVersion))
				} else {
					err = kvs.Update(ctx, key, &r)
				}
				err = errors.Wrap(err, "KV update failed")
			}
			return r, err
		}).WithKvTxnUpdater(func(ctx context.Context, txn kvstore.Txn, i interface{}, prefix string, create bool) error {
			r := i.(bookstore.Publisher)
			key := r.MakeKey(prefix)
			var err error
			if create {
				err = txn.Create(key, &r)
				err = errors.Wrap(err, "KV transaction create failed")
			} else {
				err = txn.Update(key, &r)
				err = errors.Wrap(err, "KV transaction update failed")
			}
			return err
		}).WithKvGetter(func(ctx context.Context, kvs kvstore.Interface, key string) (interface{}, error) {
			r := bookstore.Publisher{}
			err := kvs.Get(ctx, key, &r)
			err = errors.Wrap(err, "KV get failed")
			return r, err
		}).WithKvDelFunc(func(ctx context.Context, kvs kvstore.Interface, key string) (interface{}, error) {
			r := bookstore.Publisher{}
			err := kvs.Delete(ctx, key, &r)
			return r, err
		}).WithKvTxnDelFunc(func(ctx context.Context, txn kvstore.Txn, key string) error {
			return txn.Delete(key)
		}).WithValidate(func(i interface{}, ver string, ignoreStatus bool) error {
			r := i.(bookstore.Publisher)
			if !r.Validate(ver, ignoreStatus) {
				return fmt.Errorf("Default Validation failed")
			}
			return nil
		}),
		"bookstore.PublisherList": apisrvpkg.NewMessage("bookstore.PublisherList").WithKvListFunc(func(ctx context.Context, kvs kvstore.Interface, options *api.ListWatchOptions, prefix string) (interface{}, error) {

			into := bookstore.PublisherList{}
			r := bookstore.Publisher{}
			key := r.MakeKey(prefix)
			err := kvs.List(ctx, key, &into)
			if err != nil {
				return nil, err
			}
			return into, nil
		}),
		"bookstore.PublisherSpec": apisrvpkg.NewMessage("bookstore.PublisherSpec"),
		// Add a message handler for ListWatch options
		"api.ListWatchOptions": apisrvpkg.NewMessage("api.ListWatchOptions"),
	}

	scheme.AddKnownTypes(
		&bookstore.Book{},
		&bookstore.Order{},
		&bookstore.Publisher{},
	)

	apisrv.RegisterMessages("bookstore", s.Messages)

	{
		srv := apisrvpkg.NewService("BookstoreV1")

		s.endpointsBookstoreV1.fnAutoAddBook = srv.AddMethod("AutoAddBook",
			apisrvpkg.NewMethod(s.Messages["bookstore.Book"], s.Messages["bookstore.Book"], "bookstore", "AutoAddBook")).WithOper(apiserver.CreateOper).WithVersion("v1").HandleInvocation

		s.endpointsBookstoreV1.fnAutoAddOrder = srv.AddMethod("AutoAddOrder",
			apisrvpkg.NewMethod(s.Messages["bookstore.Order"], s.Messages["bookstore.Order"], "bookstore", "AutoAddOrder")).WithOper(apiserver.CreateOper).WithVersion("v1").HandleInvocation

		s.endpointsBookstoreV1.fnAutoAddPublisher = srv.AddMethod("AutoAddPublisher",
			apisrvpkg.NewMethod(s.Messages["bookstore.Publisher"], s.Messages["bookstore.Publisher"], "bookstore", "AutoAddPublisher")).WithOper(apiserver.CreateOper).WithVersion("v1").HandleInvocation

		s.endpointsBookstoreV1.fnAutoDeleteBook = srv.AddMethod("AutoDeleteBook",
			apisrvpkg.NewMethod(s.Messages["bookstore.Book"], s.Messages["bookstore.Book"], "bookstore", "AutoDeleteBook")).WithOper(apiserver.DeleteOper).WithVersion("v1").HandleInvocation

		s.endpointsBookstoreV1.fnAutoDeleteOrder = srv.AddMethod("AutoDeleteOrder",
			apisrvpkg.NewMethod(s.Messages["bookstore.Order"], s.Messages["bookstore.Order"], "bookstore", "AutoDeleteOrder")).WithOper(apiserver.DeleteOper).WithVersion("v1").HandleInvocation

		s.endpointsBookstoreV1.fnAutoDeletePublisher = srv.AddMethod("AutoDeletePublisher",
			apisrvpkg.NewMethod(s.Messages["bookstore.Publisher"], s.Messages["bookstore.Publisher"], "bookstore", "AutoDeletePublisher")).WithOper(apiserver.DeleteOper).WithVersion("v1").HandleInvocation

		s.endpointsBookstoreV1.fnAutoGetBook = srv.AddMethod("AutoGetBook",
			apisrvpkg.NewMethod(s.Messages["bookstore.Book"], s.Messages["bookstore.Book"], "bookstore", "AutoGetBook")).WithOper(apiserver.GetOper).WithVersion("v1").HandleInvocation

		s.endpointsBookstoreV1.fnAutoGetOrder = srv.AddMethod("AutoGetOrder",
			apisrvpkg.NewMethod(s.Messages["bookstore.Order"], s.Messages["bookstore.Order"], "bookstore", "AutoGetOrder")).WithOper(apiserver.GetOper).WithVersion("v1").HandleInvocation

		s.endpointsBookstoreV1.fnAutoGetPublisher = srv.AddMethod("AutoGetPublisher",
			apisrvpkg.NewMethod(s.Messages["bookstore.Publisher"], s.Messages["bookstore.Publisher"], "bookstore", "AutoGetPublisher")).WithOper(apiserver.GetOper).WithVersion("v1").HandleInvocation

		s.endpointsBookstoreV1.fnAutoListBook = srv.AddMethod("AutoListBook",
			apisrvpkg.NewMethod(s.Messages["api.ListWatchOptions"], s.Messages["bookstore.BookList"], "bookstore", "AutoListBook")).WithOper(apiserver.ListOper).WithVersion("v1").HandleInvocation

		s.endpointsBookstoreV1.fnAutoListOrder = srv.AddMethod("AutoListOrder",
			apisrvpkg.NewMethod(s.Messages["api.ListWatchOptions"], s.Messages["bookstore.OrderList"], "bookstore", "AutoListOrder")).WithOper(apiserver.ListOper).WithVersion("v1").HandleInvocation

		s.endpointsBookstoreV1.fnAutoListPublisher = srv.AddMethod("AutoListPublisher",
			apisrvpkg.NewMethod(s.Messages["api.ListWatchOptions"], s.Messages["bookstore.PublisherList"], "bookstore", "AutoListPublisher")).WithOper(apiserver.ListOper).WithVersion("v1").HandleInvocation

		s.endpointsBookstoreV1.fnAutoUpdateBook = srv.AddMethod("AutoUpdateBook",
			apisrvpkg.NewMethod(s.Messages["bookstore.Book"], s.Messages["bookstore.Book"], "bookstore", "AutoUpdateBook")).WithOper(apiserver.UpdateOper).WithVersion("v1").HandleInvocation

		s.endpointsBookstoreV1.fnAutoUpdateOrder = srv.AddMethod("AutoUpdateOrder",
			apisrvpkg.NewMethod(s.Messages["bookstore.Order"], s.Messages["bookstore.Order"], "bookstore", "AutoUpdateOrder")).WithOper(apiserver.UpdateOper).WithVersion("v1").HandleInvocation

		s.endpointsBookstoreV1.fnAutoUpdatePublisher = srv.AddMethod("AutoUpdatePublisher",
			apisrvpkg.NewMethod(s.Messages["bookstore.Publisher"], s.Messages["bookstore.Publisher"], "bookstore", "AutoUpdatePublisher")).WithOper(apiserver.UpdateOper).WithVersion("v1").HandleInvocation

		s.endpointsBookstoreV1.fnAutoWatchOrder = s.Messages["bookstore.Order"].WatchFromKv

		s.endpointsBookstoreV1.fnAutoWatchBook = s.Messages["bookstore.Book"].WatchFromKv

		s.endpointsBookstoreV1.fnAutoWatchPublisher = s.Messages["bookstore.Publisher"].WatchFromKv

		s.Services = map[string]apiserver.Service{
			"bookstore.BookstoreV1": srv,
		}
		apisrv.RegisterService("bookstore.BookstoreV1", srv)
		endpoints := bookstore.MakeBookstoreV1ServerEndpoints(s.endpointsBookstoreV1, logger)
		server := bookstore.MakeGRPCServerBookstoreV1(ctx, endpoints, logger)
		bookstore.RegisterBookstoreV1Server(grpcserver.GrpcServer, server)
	}
	// Add Watchers
	{

		s.Messages["bookstore.Order"].WithKvWatchFunc(func(l log.Logger, options *api.ListWatchOptions, kvs kvstore.Interface, stream interface{}, txfn func(from, to string, i interface{}) (interface{}, error), version, svcprefix string) error {
			o := bookstore.Order{}
			key := o.MakeKey(svcprefix)
			wstream := stream.(bookstore.BookstoreV1_AutoWatchOrderServer)
			nctx, cancel := context.WithCancel(wstream.Context())
			defer cancel()
			watcher, err := kvs.PrefixWatch(nctx, key, options.ResourceVersion)
			if err != nil {
				l.ErrorLog("msg", "error starting Watch on KV", "error", err, "object", "Order")
				return err
			}
			for {
				select {
				case ev, ok := <-watcher.EventChan():
					if !ok {
						l.DebugLog("Channel closed for Order Watcher")
						return nil
					}
					in, ok := ev.Object.(*bookstore.Order)
					if !ok {
						status, ok := ev.Object.(*api.Status)
						if !ok {
							return errors.New("unknown error")
						}
						return fmt.Errorf("%v:(%s) %s", status.Code, status.Result, status.Message)
					}
					strEvent := bookstore.AutoMsgOrderWatchHelper{
						Type:   string(ev.Type),
						Object: in,
					}
					l.DebugLog("msg", "recieved Order watch event from KV", "type", ev.Type)
					if version != in.APIVersion {
						i, err := txfn(in.APIVersion, version, in)
						if err != nil {
							l.ErrorLog("msg", "Failed to transform message", "type", "Order", "fromver", in.APIVersion, "tover", version)
							break
						}
						strEvent.Object = i.(*bookstore.Order)
					}
					l.DebugLog("msg", "writing to stream")
					if err := wstream.Send(&strEvent); err != nil {
						l.DebugLog("msg", "Stream send error'ed for Order", "error", err)
						return err
					}
				case <-nctx.Done():
					l.DebugLog("msg", "Context cancelled for Order Watcher")
					return wstream.Context().Err()
				}
			}
		})

		s.Messages["bookstore.Book"].WithKvWatchFunc(func(l log.Logger, options *api.ListWatchOptions, kvs kvstore.Interface, stream interface{}, txfn func(from, to string, i interface{}) (interface{}, error), version, svcprefix string) error {
			o := bookstore.Book{}
			key := o.MakeKey(svcprefix)
			wstream := stream.(bookstore.BookstoreV1_AutoWatchBookServer)
			nctx, cancel := context.WithCancel(wstream.Context())
			defer cancel()
			watcher, err := kvs.PrefixWatch(nctx, key, options.ResourceVersion)
			if err != nil {
				l.ErrorLog("msg", "error starting Watch on KV", "error", err, "object", "Book")
				return err
			}
			for {
				select {
				case ev, ok := <-watcher.EventChan():
					if !ok {
						l.DebugLog("Channel closed for Book Watcher")
						return nil
					}
					in, ok := ev.Object.(*bookstore.Book)
					if !ok {
						status, ok := ev.Object.(*api.Status)
						if !ok {
							return errors.New("unknown error")
						}
						return fmt.Errorf("%v:(%s) %s", status.Code, status.Result, status.Message)
					}
					strEvent := bookstore.AutoMsgBookWatchHelper{
						Type:   string(ev.Type),
						Object: in,
					}
					l.DebugLog("msg", "recieved Book watch event from KV", "type", ev.Type)
					if version != in.APIVersion {
						i, err := txfn(in.APIVersion, version, in)
						if err != nil {
							l.ErrorLog("msg", "Failed to transform message", "type", "Book", "fromver", in.APIVersion, "tover", version)
							break
						}
						strEvent.Object = i.(*bookstore.Book)
					}
					l.DebugLog("msg", "writing to stream")
					if err := wstream.Send(&strEvent); err != nil {
						l.DebugLog("msg", "Stream send error'ed for Book", "error", err)
						return err
					}
				case <-nctx.Done():
					l.DebugLog("msg", "Context cancelled for Book Watcher")
					return wstream.Context().Err()
				}
			}
		})

		s.Messages["bookstore.Publisher"].WithKvWatchFunc(func(l log.Logger, options *api.ListWatchOptions, kvs kvstore.Interface, stream interface{}, txfn func(from, to string, i interface{}) (interface{}, error), version, svcprefix string) error {
			o := bookstore.Publisher{}
			key := o.MakeKey(svcprefix)
			wstream := stream.(bookstore.BookstoreV1_AutoWatchPublisherServer)
			nctx, cancel := context.WithCancel(wstream.Context())
			defer cancel()
			watcher, err := kvs.PrefixWatch(nctx, key, options.ResourceVersion)
			if err != nil {
				l.ErrorLog("msg", "error starting Watch on KV", "error", err, "object", "Publisher")
				return err
			}
			for {
				select {
				case ev, ok := <-watcher.EventChan():
					if !ok {
						l.DebugLog("Channel closed for Publisher Watcher")
						return nil
					}
					in, ok := ev.Object.(*bookstore.Publisher)
					if !ok {
						status, ok := ev.Object.(*api.Status)
						if !ok {
							return errors.New("unknown error")
						}
						return fmt.Errorf("%v:(%s) %s", status.Code, status.Result, status.Message)
					}
					strEvent := bookstore.AutoMsgPublisherWatchHelper{
						Type:   string(ev.Type),
						Object: in,
					}
					l.DebugLog("msg", "recieved Publisher watch event from KV", "type", ev.Type)
					if version != in.APIVersion {
						i, err := txfn(in.APIVersion, version, in)
						if err != nil {
							l.ErrorLog("msg", "Failed to transform message", "type", "Publisher", "fromver", in.APIVersion, "tover", version)
							break
						}
						strEvent.Object = i.(*bookstore.Publisher)
					}
					l.DebugLog("msg", "writing to stream")
					if err := wstream.Send(&strEvent); err != nil {
						l.DebugLog("msg", "Stream send error'ed for Publisher", "error", err)
						return err
					}
				case <-nctx.Done():
					l.DebugLog("msg", "Context cancelled for Publisher Watcher")
					return wstream.Context().Err()
				}
			}
		})

	}

	return nil
}

func (e *eBookstoreV1Endpoints) AutoAddBook(ctx context.Context, t bookstore.Book) (bookstore.Book, error) {
	r, err := e.fnAutoAddBook(ctx, t)
	if err == nil {
		return r.(bookstore.Book), err
	}
	return bookstore.Book{}, err

}
func (e *eBookstoreV1Endpoints) AutoAddOrder(ctx context.Context, t bookstore.Order) (bookstore.Order, error) {
	r, err := e.fnAutoAddOrder(ctx, t)
	if err == nil {
		return r.(bookstore.Order), err
	}
	return bookstore.Order{}, err

}
func (e *eBookstoreV1Endpoints) AutoAddPublisher(ctx context.Context, t bookstore.Publisher) (bookstore.Publisher, error) {
	r, err := e.fnAutoAddPublisher(ctx, t)
	if err == nil {
		return r.(bookstore.Publisher), err
	}
	return bookstore.Publisher{}, err

}
func (e *eBookstoreV1Endpoints) AutoDeleteBook(ctx context.Context, t bookstore.Book) (bookstore.Book, error) {
	r, err := e.fnAutoDeleteBook(ctx, t)
	if err == nil {
		return r.(bookstore.Book), err
	}
	return bookstore.Book{}, err

}
func (e *eBookstoreV1Endpoints) AutoDeleteOrder(ctx context.Context, t bookstore.Order) (bookstore.Order, error) {
	r, err := e.fnAutoDeleteOrder(ctx, t)
	if err == nil {
		return r.(bookstore.Order), err
	}
	return bookstore.Order{}, err

}
func (e *eBookstoreV1Endpoints) AutoDeletePublisher(ctx context.Context, t bookstore.Publisher) (bookstore.Publisher, error) {
	r, err := e.fnAutoDeletePublisher(ctx, t)
	if err == nil {
		return r.(bookstore.Publisher), err
	}
	return bookstore.Publisher{}, err

}
func (e *eBookstoreV1Endpoints) AutoGetBook(ctx context.Context, t bookstore.Book) (bookstore.Book, error) {
	r, err := e.fnAutoGetBook(ctx, t)
	if err == nil {
		return r.(bookstore.Book), err
	}
	return bookstore.Book{}, err

}
func (e *eBookstoreV1Endpoints) AutoGetOrder(ctx context.Context, t bookstore.Order) (bookstore.Order, error) {
	r, err := e.fnAutoGetOrder(ctx, t)
	if err == nil {
		return r.(bookstore.Order), err
	}
	return bookstore.Order{}, err

}
func (e *eBookstoreV1Endpoints) AutoGetPublisher(ctx context.Context, t bookstore.Publisher) (bookstore.Publisher, error) {
	r, err := e.fnAutoGetPublisher(ctx, t)
	if err == nil {
		return r.(bookstore.Publisher), err
	}
	return bookstore.Publisher{}, err

}
func (e *eBookstoreV1Endpoints) AutoListBook(ctx context.Context, t api.ListWatchOptions) (bookstore.BookList, error) {
	r, err := e.fnAutoListBook(ctx, t)
	if err == nil {
		return r.(bookstore.BookList), err
	}
	return bookstore.BookList{}, err

}
func (e *eBookstoreV1Endpoints) AutoListOrder(ctx context.Context, t api.ListWatchOptions) (bookstore.OrderList, error) {
	r, err := e.fnAutoListOrder(ctx, t)
	if err == nil {
		return r.(bookstore.OrderList), err
	}
	return bookstore.OrderList{}, err

}
func (e *eBookstoreV1Endpoints) AutoListPublisher(ctx context.Context, t api.ListWatchOptions) (bookstore.PublisherList, error) {
	r, err := e.fnAutoListPublisher(ctx, t)
	if err == nil {
		return r.(bookstore.PublisherList), err
	}
	return bookstore.PublisherList{}, err

}
func (e *eBookstoreV1Endpoints) AutoUpdateBook(ctx context.Context, t bookstore.Book) (bookstore.Book, error) {
	r, err := e.fnAutoUpdateBook(ctx, t)
	if err == nil {
		return r.(bookstore.Book), err
	}
	return bookstore.Book{}, err

}
func (e *eBookstoreV1Endpoints) AutoUpdateOrder(ctx context.Context, t bookstore.Order) (bookstore.Order, error) {
	r, err := e.fnAutoUpdateOrder(ctx, t)
	if err == nil {
		return r.(bookstore.Order), err
	}
	return bookstore.Order{}, err

}
func (e *eBookstoreV1Endpoints) AutoUpdatePublisher(ctx context.Context, t bookstore.Publisher) (bookstore.Publisher, error) {
	r, err := e.fnAutoUpdatePublisher(ctx, t)
	if err == nil {
		return r.(bookstore.Publisher), err
	}
	return bookstore.Publisher{}, err

}

func (e *eBookstoreV1Endpoints) AutoWatchOrder(in *api.ListWatchOptions, stream bookstore.BookstoreV1_AutoWatchOrderServer) error {
	return e.fnAutoWatchOrder(in, stream, "bookstore")
}
func (e *eBookstoreV1Endpoints) AutoWatchBook(in *api.ListWatchOptions, stream bookstore.BookstoreV1_AutoWatchBookServer) error {
	return e.fnAutoWatchBook(in, stream, "bookstore")
}
func (e *eBookstoreV1Endpoints) AutoWatchPublisher(in *api.ListWatchOptions, stream bookstore.BookstoreV1_AutoWatchPublisherServer) error {
	return e.fnAutoWatchPublisher(in, stream, "bookstore")
}

func init() {
	apisrv = apisrvpkg.MustGetAPIServer()

	svc := sbookstoreExampleBackend{}

	{
		e := eBookstoreV1Endpoints{Svc: svc}
		svc.endpointsBookstoreV1 = &e
	}
	apisrv.Register("bookstore.protos/example.proto", &svc)
}
