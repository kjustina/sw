// {C} Copyright 2017 Pensando Systems Inc. All rights reserved.

package state

import (
	"context"
	"errors"
	"fmt"
	"strings"
	"time"

	gogoproto "github.com/gogo/protobuf/types"

	"github.com/pensando/sw/api"
	"github.com/pensando/sw/nic/agent/netagent/state/dependencies"
	"github.com/pensando/sw/nic/agent/netagent/state/types"
	"github.com/pensando/sw/nic/agent/protos/netproto"
	clientApi "github.com/pensando/sw/nic/delphi/gosdk/client_api"
	"github.com/pensando/sw/venice/utils/emstore"
	"github.com/pensando/sw/venice/utils/log"
)

// Nagent is an instance of network agent.
type Nagent types.NetAgent

// ErrObjectNotFound is returned when object is not found
var ErrObjectNotFound = errors.New("object not found")

// NewNetAgent creates a new network agent
func NewNetAgent(dp types.NetDatapathAPI, dbPath string, delphiClient clientApi.Client) (*Nagent, error) {
	var na Nagent
	var emdb emstore.Emstore
	var err error

	if dbPath == "" {
		emdb, err = emstore.NewEmstore(emstore.MemStoreType, "")
	} else {
		emdb, err = emstore.NewEmstore(emstore.BoltDBType, dbPath)
	}
	if err != nil {
		log.Errorf("Error opening the embedded db. Err: %v", err)
		return nil, err
	}

	na.init(emdb, dp)
	na.Mode = "host-managed"
	na.DelphiClient = delphiClient

	tn := netproto.Tenant{
		TypeMeta: api.TypeMeta{Kind: "Tenant"},
		ObjectMeta: api.ObjectMeta{
			Name: "default",
		},
	}

	_, err = emdb.Read(&tn)

	// Blank slate. Persist config and do init stuff
	if err != nil {
		// We need to create a default tenant and default namespace at startup.
		err = na.createDefaultTenant()
		if err != nil {
			log.Errorf("Failed to create default tenant. Err: %v", err)
			emdb.Close()
			return nil, err
		}
		// We need to create a default vrf in the datapath at startup
		err = na.createDefaultVrf()
		if err != nil {
			emdb.Close()
			return nil, err
		}
	} else {
		// update netagent state. This is a temporary fix till we decide on flash perf implications of a full config replay
		if err := na.replayConfigs(); err != nil {
			log.Errorf("Failed to replay configs from boltDB. Err: %v", err)
		}
	}

	err = na.GetUUID()
	err = na.GetHwInterfaces()
	if err != nil {
		return nil, err
	}

	err = dp.SetAgent(&na)
	if err != nil {
		// cleanup emstore and return
		emdb.Close()
		return nil, err
	}

	return &na, nil

}

// RegisterCtrlerIf registers a controller object
func (na *Nagent) RegisterCtrlerIf(ctrlerif types.CtrlerAPI) error {
	// ensure two controller plugins dont register
	if na.Ctrlerif != nil {
		log.Fatalf("Multiple controllers registers to netagent.")
	}

	// add it to controller list
	na.Ctrlerif = ctrlerif

	return nil
}

// Stop stops the netagent
func (na *Nagent) Stop() error {
	return na.Store.Close()
}

// GetAgentID returns UUID of the agent
func (na *Nagent) GetAgentID() string {
	return na.NodeUUID
}

func (na *Nagent) createDefaultTenant() error {
	c, _ := gogoproto.TimestampProto(time.Now())

	tn := netproto.Tenant{
		TypeMeta: api.TypeMeta{Kind: "Tenant"},
		ObjectMeta: api.ObjectMeta{
			Name: "default",
			CreationTime: api.Timestamp{
				Timestamp: *c,
			},
			ModTime: api.Timestamp{
				Timestamp: *c,
			},
		},
	}
	return na.CreateTenant(&tn)
}

func (na *Nagent) createDefaultVrf() error {
	c, _ := gogoproto.TimestampProto(time.Now())
	defVrf := netproto.Vrf{
		TypeMeta: api.TypeMeta{Kind: "Vrf"},
		ObjectMeta: api.ObjectMeta{
			Tenant:    "default",
			Namespace: "default",
			Name:      "default",
			CreationTime: api.Timestamp{
				Timestamp: *c,
			},
			ModTime: api.Timestamp{
				Timestamp: *c,
			},
		},
		Spec: netproto.VrfSpec{
			VrfType: "CUSTOMER",
		},
	}
	err := na.CreateVrf(&defVrf)
	return err
}

func (na *Nagent) validateMeta(kind string, oMeta api.ObjectMeta) error {
	if len(oMeta.Name) == 0 {
		return fmt.Errorf("%s name can't be empty", kind)
	}
	return nil
}

func (na *Nagent) init(emdb emstore.Emstore, dp types.NetDatapathAPI) {
	na.Store = emdb
	na.Datapath = dp
	na.NetworkDB = make(map[string]*netproto.Network)
	na.EndpointDB = make(map[string]*netproto.Endpoint)
	na.SecgroupDB = make(map[string]*netproto.SecurityGroup)
	na.TenantDB = make(map[string]*netproto.Tenant)
	na.NamespaceDB = make(map[string]*netproto.Namespace)
	na.EnicDB = make(map[string]*netproto.Interface)
	na.NatPoolDB = make(map[string]*netproto.NatPool)
	na.NatPoolLUT = make(map[string]*types.NatPoolRef)
	na.NatPolicyDB = make(map[string]*netproto.NatPolicy)
	na.NatBindingDB = make(map[string]*netproto.NatBinding)
	na.HwIfDB = make(map[string]*netproto.Interface)
	na.RouteDB = make(map[string]*netproto.Route)
	na.IPSecPolicyDB = make(map[string]*netproto.IPSecPolicy)
	na.IPSecSAEncryptDB = make(map[string]*netproto.IPSecSAEncrypt)
	na.IPSecSADecryptDB = make(map[string]*netproto.IPSecSADecrypt)
	na.IPSecPolicyLUT = make(map[string]*types.IPSecRuleRef)
	na.SGPolicyDB = make(map[string]*netproto.SGPolicy)
	na.TunnelDB = make(map[string]*netproto.Tunnel)
	na.TCPProxyPolicyDB = make(map[string]*netproto.TCPProxyPolicy)
	na.PortDB = make(map[string]*netproto.Port)
	na.SecurityProfileDB = make(map[string]*netproto.SecurityProfile)
	na.AppDB = make(map[string]*netproto.App)
	na.VrfDB = make(map[string]*netproto.Vrf)
	na.Solver = dependencies.NewDepSolver()
	na.ArpCache = types.ArpCache{
		DoneCache: make(map[string]context.CancelFunc),
	}
}

// GetUUID gets the naples uuid from the datapath
func (na *Nagent) GetUUID() error {

	uuid, err := na.Datapath.GetUUID()
	if err != nil {
		log.Errorf("HAL System GetUUID failed. %v", err)
		return fmt.Errorf("hal get fru uuid failed. %v", err)
	}

	na.NodeUUID = uuid
	log.Infof("Got UUID:. %v", na.NodeUUID)
	return nil
}

// PurgeConfigs deletes all netagent configs. This is called during decommission workflow where the NAPLES is moved to host managed mode
func (na *Nagent) PurgeConfigs() error {
	// Perform ordered deletes of venice objects
	// Apps, SGPolicies, Endpoints,  Networks
	for _, app := range na.ListApp() {
		if err := na.DeleteApp(app.Tenant, app.Namespace, app.Name); err != nil {
			log.Errorf("Failed to delete the App. Err: %v", err)
		}
	}

	for _, sgp := range na.ListSGPolicy() {
		if err := na.DeleteSGPolicy(sgp.Tenant, sgp.Namespace, sgp.Name); err != nil {
			log.Errorf("Failed to delete the SG Policy. Err: %v", err)
		}
	}

	for _, ep := range na.ListEndpoint() {
		if strings.Contains(ep.Name, "_internal") {
			continue
		}
		if err := na.DeleteEndpoint(ep.Tenant, ep.Namespace, ep.Name); err != nil {
			log.Errorf("Failed to delete the endpoint. Err: %v", err)
		}
	}

	for _, nw := range na.ListNetwork() {
		if strings.Contains(nw.Name, "_internal") {
			continue
		}
		if err := na.DeleteNetwork(nw.Tenant, nw.Namespace, nw.Name); err != nil {
			log.Errorf("Failed to delete the network. Err: %v", err)
		}
	}

	return nil
}

// replay configs replays the persisted configs from bolt DB
func (na *Nagent) replayConfigs() error {

	// Replay Tenant Object
	if objs, err := na.Store.List(&netproto.Tenant{
		TypeMeta: api.TypeMeta{Kind: "Tenant"},
	}); err == nil {
		for _, o := range objs {
			tenant := o.(*netproto.Tenant)
			if err := na.CreateTenant(tenant); err != nil {
				log.Errorf("Failed to recreate tenant objects. Err: %v", err)
				return fmt.Errorf("failed to recreate tenant objects. Err: %v", err)
			}
		}
	}

	// Replay Namespace Object
	if objs, err := na.Store.List(&netproto.Namespace{
		TypeMeta: api.TypeMeta{Kind: "Namespace"},
	}); err == nil {
		for _, o := range objs {
			namespace := o.(*netproto.Namespace)
			if err := na.CreateNamespace(namespace); err != nil {
				log.Errorf("Failed to recreate namespace objects. Err: %v", err)
				return fmt.Errorf("failed to recreate namespace objects. Err: %v", err)
			}
		}
	}

	// Replay Vrf Object
	if objs, err := na.Store.List(&netproto.Vrf{
		TypeMeta: api.TypeMeta{Kind: "Vrf"},
	}); err == nil {
		for _, o := range objs {
			vrf := o.(*netproto.Vrf)
			if err := na.CreateVrf(vrf); err != nil {
				log.Errorf("Failed to recreate vrf objects. Err: %v", err)
				return fmt.Errorf("failed to recreate vrf objects. Err: %v", err)
			}
		}
	}

	// Replay Network Object
	if objs, err := na.Store.List(&netproto.Network{
		TypeMeta: api.TypeMeta{Kind: "Network"},
	}); err == nil {
		for _, o := range objs {
			network := o.(*netproto.Network)
			if err := na.CreateNetwork(network); err != nil {
				log.Errorf("Failed to recreate network objects. Err: %v", err)
				return fmt.Errorf("failed to recreate network objects. Err: %v", err)
			}
		}
	}

	// Replay Endpoint Object
	if objs, err := na.Store.List(&netproto.Endpoint{
		TypeMeta: api.TypeMeta{Kind: "Endpoint"},
	}); err == nil {
		for _, o := range objs {
			endpoint := o.(*netproto.Endpoint)
			if err := na.CreateEndpoint(endpoint); err != nil {
				log.Errorf("Failed to recreate endpoint objects. Err: %v", err)
				return fmt.Errorf("failed to recreate endpoint objects. Err: %v", err)
			}
		}
	}

	// Replay Tunnel Object
	if objs, err := na.Store.List(&netproto.Tunnel{
		TypeMeta: api.TypeMeta{Kind: "Tunnel"},
	}); err == nil {
		for _, o := range objs {
			tunnel := o.(*netproto.Tunnel)
			if err := na.CreateTunnel(tunnel); err != nil {
				log.Errorf("Failed to recreate tunnel objects. Err: %v", err)
				return fmt.Errorf("failed to recreate tunnel objects. Err: %v", err)
			}
		}
	}

	// Replay App Object
	if objs, err := na.Store.List(&netproto.App{
		TypeMeta: api.TypeMeta{Kind: "App"},
	}); err == nil {
		for _, o := range objs {
			app := o.(*netproto.App)
			if err := na.CreateApp(app); err != nil {
				log.Errorf("Failed to recreate app objects. Err: %v", err)
				return fmt.Errorf("failed to recreate app objects. Err: %v", err)
			}
		}
	}

	// Replay SGPolicy Object
	if objs, err := na.Store.List(&netproto.SGPolicy{
		TypeMeta: api.TypeMeta{Kind: "SGPolicy"},
	}); err == nil {
		for _, o := range objs {
			sgPolicy := o.(*netproto.SGPolicy)
			if err := na.CreateSGPolicy(sgPolicy); err != nil {
				log.Errorf("Failed to recreate sgPolicy objects. Err: %v", err)
				return fmt.Errorf("failed to recreate sgPolicy objects. Err: %v", err)
			}
		}
	}
	return nil
}
