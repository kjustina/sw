package store

import (
	"fmt"

	"github.com/pensando/sw/utils/kvstore"
	"github.com/pensando/sw/utils/kvstore/etcd"
	"github.com/pensando/sw/utils/runtime"
)

// exported constants
const (
	KVStoreTypeEtcd = "etcd"
)

// Config contains configuration to create a KV storage client.
type Config struct {
	// Type of KV storage backend, e.g. "etcd"
	Type string
	// Servers is the list of servers to connect to.
	Servers []string
	// Codec is the codec to use for serializing/deserializing objects.
	Codec runtime.Codec
}

// New creates a new KVStore based on provided configuration.
func New(c Config) (kvstore.Interface, error) {
	switch c.Type {
	case KVStoreTypeEtcd:
		return etcd.NewEtcdStore(c.Servers, c.Codec)
	}
	return nil, fmt.Errorf("Unknown kv store type: %v", c.Type)
}
