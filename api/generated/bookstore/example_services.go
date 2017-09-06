// Code generated by protoc-gen-grpc-pensando DO NOT EDIT.

/*
Package bookstore is a auto generated package.
Input file: protos/example.proto
*/
package bookstore

import (
	"context"
	"github.com/pensando/sw/api"
)

// Dummy definitions to suppress nonused warnings
var _ api.ObjectMeta

// ServiceBookstoreV1Client  is the client interface for the service.
type ServiceBookstoreV1Client interface {
	AutoAddBook(ctx context.Context, t *Book) (*Book, error)
	AutoAddOrder(ctx context.Context, t *Order) (*Order, error)
	AutoAddPublisher(ctx context.Context, t *Publisher) (*Publisher, error)
	AutoDeleteBook(ctx context.Context, t *Book) (*Book, error)
	AutoDeleteOrder(ctx context.Context, t *Order) (*Order, error)
	AutoDeletePublisher(ctx context.Context, t *Publisher) (*Publisher, error)
	AutoGetBook(ctx context.Context, t *Book) (*Book, error)
	AutoGetOrder(ctx context.Context, t *Order) (*Order, error)
	AutoGetPublisher(ctx context.Context, t *Publisher) (*Publisher, error)
	AutoListBook(ctx context.Context, t *api.ListWatchOptions) (*BookList, error)
	AutoListOrder(ctx context.Context, t *api.ListWatchOptions) (*OrderList, error)
	AutoListPublisher(ctx context.Context, t *api.ListWatchOptions) (*PublisherList, error)
	AutoUpdateBook(ctx context.Context, t *Book) (*Book, error)
	AutoUpdateOrder(ctx context.Context, t *Order) (*Order, error)
	AutoUpdatePublisher(ctx context.Context, t *Publisher) (*Publisher, error)

	AutoWatchOrder(ctx context.Context, in *api.ListWatchOptions) (BookstoreV1_AutoWatchOrderClient, error)
	AutoWatchBook(ctx context.Context, in *api.ListWatchOptions) (BookstoreV1_AutoWatchBookClient, error)
	AutoWatchPublisher(ctx context.Context, in *api.ListWatchOptions) (BookstoreV1_AutoWatchPublisherClient, error)
}

// ServiceBookstoreV1Server is the server interface for the service.
type ServiceBookstoreV1Server interface {
	AutoAddBook(ctx context.Context, t Book) (Book, error)
	AutoAddOrder(ctx context.Context, t Order) (Order, error)
	AutoAddPublisher(ctx context.Context, t Publisher) (Publisher, error)
	AutoDeleteBook(ctx context.Context, t Book) (Book, error)
	AutoDeleteOrder(ctx context.Context, t Order) (Order, error)
	AutoDeletePublisher(ctx context.Context, t Publisher) (Publisher, error)
	AutoGetBook(ctx context.Context, t Book) (Book, error)
	AutoGetOrder(ctx context.Context, t Order) (Order, error)
	AutoGetPublisher(ctx context.Context, t Publisher) (Publisher, error)
	AutoListBook(ctx context.Context, t api.ListWatchOptions) (BookList, error)
	AutoListOrder(ctx context.Context, t api.ListWatchOptions) (OrderList, error)
	AutoListPublisher(ctx context.Context, t api.ListWatchOptions) (PublisherList, error)
	AutoUpdateBook(ctx context.Context, t Book) (Book, error)
	AutoUpdateOrder(ctx context.Context, t Order) (Order, error)
	AutoUpdatePublisher(ctx context.Context, t Publisher) (Publisher, error)

	AutoWatchOrder(in *api.ListWatchOptions, stream BookstoreV1_AutoWatchOrderServer) error
	AutoWatchBook(in *api.ListWatchOptions, stream BookstoreV1_AutoWatchBookServer) error
	AutoWatchPublisher(in *api.ListWatchOptions, stream BookstoreV1_AutoWatchPublisherServer) error
}
