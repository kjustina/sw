package impl

import (
	"context"
	"testing"

	"github.com/pensando/sw/api/generated/apiclient"

	apiintf "github.com/pensando/sw/api/interfaces"
	"github.com/pensando/sw/venice/utils/kvstore/store"
	"github.com/pensando/sw/venice/utils/runtime"

	"github.com/pensando/sw/api"
	"github.com/pensando/sw/venice/utils/log"

	"github.com/pensando/sw/api/generated/rollout"
)

const (
	rolloutName         = "e2e_rollout"
	rolloutParallelName = "e2e_rollout_parallel"
)

func TestRolloutActionPreCommitHooks(t *testing.T) {

	hooks := &rolloutHooks{
		//svc: apisrvpkg.MustGetAPIServer()
		l: log.SetConfig(log.GetDefaultConfig("Rollout-Precommit-Test")),
	}

	roa := rollout.RolloutAction{
		TypeMeta: api.TypeMeta{
			Kind: "RolloutAction",
		},
		ObjectMeta: api.ObjectMeta{
			Name: rolloutName,
		},
		Spec: rollout.RolloutSpec{
			Version:                     "2.8",
			ScheduledStartTime:          nil,
			Duration:                    "",
			Strategy:                    "LINEAR",
			MaxParallel:                 0,
			MaxNICFailuresBeforeAbort:   0,
			OrderConstraints:            nil,
			Suspend:                     false,
			SmartNICsOnly:               false,
			SmartNICMustMatchConstraint: true, // hence venice upgrade only
			UpgradeType:                 "Disruptive",
		},
		Status: rollout.RolloutActionStatus{
			OperationalState: "SUCCESS",
		},
	}
	req := rollout.Rollout{
		TypeMeta: api.TypeMeta{
			Kind: "Rollout",
		},
		ObjectMeta: api.ObjectMeta{
			Name: rolloutName,
		},
		Spec: rollout.RolloutSpec{
			Version:                     "2.8",
			ScheduledStartTime:          nil,
			Duration:                    "",
			Strategy:                    "LINEAR",
			MaxParallel:                 0,
			MaxNICFailuresBeforeAbort:   0,
			OrderConstraints:            nil,
			Suspend:                     false,
			SmartNICsOnly:               false,
			SmartNICMustMatchConstraint: true, // hence venice upgrade only
			UpgradeType:                 "Disruptive",
		},
	}

	rolloutCfg := store.Config{
		Type:    store.KVStoreTypeMemkv,
		Codec:   runtime.NewJSONCodec(runtime.NewScheme()),
		Servers: []string{t.Name()},
	}
	kvs, err := store.New(rolloutCfg)
	if err != nil {
		t.Fatalf("unable to create kvstore %s", err)
	}
	txn := kvs.NewTxn()
	key2 := req.MakeKey(string(apiclient.GroupRollout))
	err = kvs.Create(context.TODO(), key2, &req)

	ret, skip, err := hooks.doRolloutAction(context.TODO(), kvs, txn, key2, apiintf.CreateOper, false, req)

	if ret == nil || err != nil {
		t.Fatalf("failed exec commitAction [%v](%s)", ret, err)
	}
	if skip == false {
		t.Fatalf("kvwrite enabled on commit")
	}
	key := roa.MakeKey(string(apiclient.GroupRollout))
	err = kvs.Create(context.TODO(), key, &roa)

	req2 := rollout.Rollout{
		TypeMeta: api.TypeMeta{
			Kind: "Rollout",
		},
		ObjectMeta: api.ObjectMeta{
			Name: rolloutParallelName,
		},
		Spec: rollout.RolloutSpec{
			Version:                     "2.8",
			ScheduledStartTime:          nil,
			Duration:                    "",
			Strategy:                    "LINEAR",
			MaxParallel:                 0,
			MaxNICFailuresBeforeAbort:   0,
			OrderConstraints:            nil,
			Suspend:                     false,
			SmartNICsOnly:               false,
			SmartNICMustMatchConstraint: true, // hence venice upgrade only
			UpgradeType:                 "Disruptive",
		},
	}

	ret, skip, err = hooks.doRolloutAction(context.TODO(), kvs, txn, "", apiintf.CreateOper, false, req2)

	if ret == nil || err != nil {
		t.Fatalf("failed exec commitAction [%v](%s)", ret, err)
	}
	if skip == false {
		t.Fatalf("kvwrite enabled on commit")
	}

	ret, skip, err = hooks.stopRolloutAction(context.TODO(), kvs, txn, key2, apiintf.CreateOper, false, req)

	if ret == nil || err != nil {
		t.Fatalf("failed exec commitAction [%v](%s)", ret, err)
	}

	req4 := rollout.Rollout{
		TypeMeta: api.TypeMeta{
			Kind: "Rollout",
		},
		ObjectMeta: api.ObjectMeta{
			Name: rolloutName,
		},
		Spec: rollout.RolloutSpec{
			Version:                   "2.8",
			ScheduledStartTime:        nil,
			Duration:                  "",
			Strategy:                  "LINEAR",
			MaxParallel:               0,
			MaxNICFailuresBeforeAbort: 0,
			OrderConstraints:          nil,
			Suspend:                   false,
			SmartNICsOnly:             false,
			UpgradeType:               "Disruptive",
		},
	}

	ret, skip, err = hooks.modifyRolloutAction(context.TODO(), kvs, txn, key2, apiintf.CreateOper, false, req4)

	if ret == nil || err != nil {
		t.Fatalf("failed exec commitAction [%v](%s)", ret, err)
	}

}
