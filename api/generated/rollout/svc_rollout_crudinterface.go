// Code generated by protoc-gen-grpc-pensando DO NOT EDIT.

package rollout

import (
	"context"

	api "github.com/pensando/sw/api"
	"github.com/pensando/sw/api/interfaces"
	"github.com/pensando/sw/venice/utils/kvstore"
)

// Dummy vars to suppress unused imports message
var _ context.Context
var _ api.ObjectMeta
var _ kvstore.Interface

// RolloutV1RolloutInterface exposes the CRUD methods for Rollout
type RolloutV1RolloutInterface interface {
	Create(ctx context.Context, in *Rollout) (*Rollout, error)
	Update(ctx context.Context, in *Rollout) (*Rollout, error)
	UpdateStatus(ctx context.Context, in *Rollout) (*Rollout, error)
	Get(ctx context.Context, objMeta *api.ObjectMeta) (*Rollout, error)
	Delete(ctx context.Context, objMeta *api.ObjectMeta) (*Rollout, error)
	List(ctx context.Context, options *api.ListWatchOptions) ([]*Rollout, error)
	Watch(ctx context.Context, options *api.ListWatchOptions) (kvstore.Watcher, error)
	Allowed(oper apiintf.APIOperType) bool
	CreateRollout(ctx context.Context, in *Rollout) (*Rollout, error)
	UpdateRollout(ctx context.Context, in *Rollout) (*Rollout, error)
	StopRollout(ctx context.Context, in *Rollout) (*Rollout, error)
}

// RolloutV1RolloutActionInterface exposes the CRUD methods for RolloutAction
type RolloutV1RolloutActionInterface interface {
	Create(ctx context.Context, in *RolloutAction) (*RolloutAction, error)
	Update(ctx context.Context, in *RolloutAction) (*RolloutAction, error)
	UpdateStatus(ctx context.Context, in *RolloutAction) (*RolloutAction, error)
	Get(ctx context.Context, objMeta *api.ObjectMeta) (*RolloutAction, error)
	Delete(ctx context.Context, objMeta *api.ObjectMeta) (*RolloutAction, error)
	List(ctx context.Context, options *api.ListWatchOptions) ([]*RolloutAction, error)
	Watch(ctx context.Context, options *api.ListWatchOptions) (kvstore.Watcher, error)
	Allowed(oper apiintf.APIOperType) bool
}

// RolloutV1Interface exposes objects with CRUD operations allowed by the service
type RolloutV1Interface interface {
	Rollout() RolloutV1RolloutInterface
	RolloutAction() RolloutV1RolloutActionInterface
	Watch(ctx context.Context, options *api.ListWatchOptions) (kvstore.Watcher, error)
}
