// {C} Copyright 2017 Pensando Systems Inc. All rights reserved.

package rpcserver

import (
	"context"
	"reflect"
	"testing"
	"time"

	"github.com/pensando/sw/api"
	"github.com/pensando/sw/api/generated/cluster"
	"github.com/pensando/sw/api/generated/network"
	"github.com/pensando/sw/api/generated/security"
	"github.com/pensando/sw/api/generated/workload"
	"github.com/pensando/sw/api/labels"
	"github.com/pensando/sw/nic/agent/netagent/protos/netproto"
	"github.com/pensando/sw/venice/ctrler/npm/statemgr"
	"github.com/pensando/sw/venice/utils/debug"
	"github.com/pensando/sw/venice/utils/rpckit"
	. "github.com/pensando/sw/venice/utils/testutils"
)

const testServerURL = "localhost:9099"

// dummy writer
type dummyWriter struct {
	// no fields
}

func (d *dummyWriter) WriteNetwork(nw *network.Network) error {
	return nil
}

func (d *dummyWriter) WriteEndpoint(ep *workload.Endpoint, update bool) error {
	return nil
}

func (d *dummyWriter) WriteSecurityGroup(sg *security.SecurityGroup) error {
	return nil
}

func (d *dummyWriter) WriteSGPolicy(sgp *security.SGPolicy) error {
	return nil
}

func (d *dummyWriter) WriteTenant(tn *cluster.Tenant) error {
	return nil
}

func (d *dummyWriter) WriteApp(tn *security.App) error {
	return nil
}

func (d *dummyWriter) Close() error {
	return nil
}

// createRPCServerClient creates rpc client and server
func createRPCServerClient(t *testing.T) (*statemgr.Statemgr, *RPCServer, *rpckit.RPCClient) {
	// create network state manager
	stateMgr, err := statemgr.NewStatemgr(&dummyWriter{})
	if err != nil {
		t.Fatalf("Could not create network manager. Err: %v", err)
	}

	// network params
	np := network.Network{
		TypeMeta: api.TypeMeta{Kind: "Network"},
		ObjectMeta: api.ObjectMeta{
			Name:      "default",
			Namespace: "",
			Tenant:    "default",
		},
		Spec: network.NetworkSpec{
			IPv4Subnet:  "10.1.1.0/24",
			IPv4Gateway: "10.1.1.254",
		},
		Status: network.NetworkStatus{},
	}

	tn := cluster.Tenant{
		TypeMeta: api.TypeMeta{Kind: "Tenant"},
		ObjectMeta: api.ObjectMeta{
			Tenant: "testTenant",
			Name:   "testTenant",
		},
	}

	// create a tenant
	err = stateMgr.CreateTenant(&tn)
	AssertOk(t, err, "Failed to create tenant")
	// create a dummy network
	err = stateMgr.CreateNetwork(&np)
	AssertOk(t, err, "Failed to create network")

	// start the rpc server
	rpcServer, err := NewRPCServer(testServerURL, stateMgr, debug.New(t.Name()).Build())
	if err != nil {
		t.Fatalf("Error creating RPC server. Err: %v", err)
	}
	Assert(t, (rpcServer != nil), "Failed to create rpc server")

	// create a grpc client
	rpcClient, err := rpckit.NewRPCClient("testServer", testServerURL)
	if err != nil {
		t.Fatalf("Error connecting to grpc server. Err: %v", err)
	}

	return stateMgr, rpcServer, rpcClient
}

// TestNetworkRPC tests network rpcs
func TestNetworkRPC(t *testing.T) {
	// create rpc server and client
	stateMgr, rpcServer, rpcClient := createRPCServerClient(t)
	Assert(t, ((stateMgr != nil) && (rpcServer != nil) && (rpcClient != nil)), "Err creating rpc server")

	// create API client
	networkRPCClient := netproto.NewNetworkApiClient(rpcClient.ClientConn)

	// make an RPC call
	ometa := api.ObjectMeta{Name: "default", Tenant: "default"}
	ns, err := networkRPCClient.GetNetwork(context.Background(), &ometa)
	AssertOk(t, err, "Could not perform network get RPC call")
	Assert(t, (ns.Spec.IPv4Subnet == "10.1.1.0/24"), "Got incorrect subnet ip", ns)

	// verify getting non-existing network returns an error
	ometa = api.ObjectMeta{Name: "invalid", Tenant: "default"}
	_, err = networkRPCClient.GetNetwork(context.Background(), &ometa)
	Assert(t, (err != nil), "Getting non-existing network didnt return error")

	// verify list api works
	nets, err := networkRPCClient.ListNetworks(context.Background(), &ometa)
	AssertOk(t, err, "Error getting network list")
	Assert(t, (len(nets.Networks) == 1), "Received incorrect number of networks", nets)
	Assert(t, (nets.Networks[0].Spec.IPv4Subnet == "10.1.1.0/24"), "Got incorrect subnet ip", ns)

	// verify watch API
	stream, err := networkRPCClient.WatchNetworks(context.Background(), &ometa)
	AssertOk(t, err, "Error watching network")
	evt, err := stream.Recv()
	AssertOk(t, err, "Error receiving network")
	Assert(t, (evt.NetworkEvents[0].Network.Spec.IPv4Subnet == "10.1.1.0/24"), "Received invalid network", evt)

	// create second network and verify we receive a watch event
	np := network.Network{
		TypeMeta: api.TypeMeta{Kind: "Network"},
		ObjectMeta: api.ObjectMeta{
			Name:   "net2",
			Tenant: "default",
		},
		Spec: network.NetworkSpec{
			IPv4Subnet:  "20.2.2.0/24",
			IPv4Gateway: "20.2.2.254",
		},
	}
	err = stateMgr.CreateNetwork(&np)
	AssertOk(t, err, "Failed to create network")

	// verify we receive a watch event
	evt, err = stream.Recv()
	AssertOk(t, err, "Error receiving network")
	Assert(t, (evt.NetworkEvents[0].EventType == api.EventType_CreateEvent), "Invalid event type", evt)
	Assert(t, (evt.NetworkEvents[0].Network.Name == "net2"), "Received invalid network", evt)
	Assert(t, (evt.NetworkEvents[0].Network.Spec.IPv4Subnet == "20.2.2.0/24"), "Received invalid network", evt)

	// delete the network
	err = stateMgr.DeleteNetwork(np.Tenant, np.Name)
	AssertOk(t, err, "Failed to delete network")

	// verify we receive an delete event
	evt, err = stream.Recv()
	AssertOk(t, err, "Error receiving from stream")
	Assert(t, (evt.NetworkEvents[0].EventType == api.EventType_DeleteEvent), "Invalid event type", evt)

	rpcClient.Close()
	rpcServer.Stop()
	time.Sleep(time.Millisecond * 10)
}

// TestEndpointRPC tests endpoint rpc calls
func TestEndpointRPC(t *testing.T) {
	// create rpc server and client
	stateMgr, rpcServer, rpcClient := createRPCServerClient(t)
	Assert(t, ((stateMgr != nil) && (rpcServer != nil) && (rpcClient != nil)), "Err creating rpc server")
	defer rpcServer.Stop()

	// create API client
	endpointRPRClient := netproto.NewEndpointApiClient(rpcClient.ClientConn)

	// endpoint params
	epinfo := netproto.Endpoint{
		TypeMeta: api.TypeMeta{Kind: "Endpoint"},
		ObjectMeta: api.ObjectMeta{
			Name:   "testEndpoint",
			Tenant: "default",
		},
		Spec: netproto.EndpointSpec{
			EndpointUUID:   "testEndpointUUID",
			WorkloadUUID:   "testContainerUUID",
			WorkloadName:   "testContainerName",
			NetworkName:    "default",
			HomingHostAddr: "192.168.1.1",
			HomingHostName: "testHost",
		},
	}

	// make create endpoint call
	eps, err := endpointRPRClient.CreateEndpoint(context.Background(), &epinfo)
	AssertOk(t, err, "Error creating endpoint")
	Assert(t, (eps.Spec.IPv4Address == "10.1.1.1/24"), "Endpoint address was incorrect", eps)

	// verify we can get the sg
	ometa := api.ObjectMeta{Name: "testEndpoint", Tenant: "default"}
	epo, err := endpointRPRClient.GetEndpoint(context.Background(), &ometa)
	AssertOk(t, err, "Error getting endpoint")
	Assert(t, reflect.DeepEqual(&epo.ObjectMeta, &eps.ObjectMeta), "Got invalid endpoint params", epo)

	// verify list endpoint
	endpoints, err := endpointRPRClient.ListEndpoints(context.Background(), &ometa)
	AssertOk(t, err, "Error listing endpoint")
	Assert(t, (len(endpoints.Endpoints) == 1), "Received invalid number of endpoints", endpoints)
	Assert(t, (endpoints.Endpoints[0].Name == epinfo.Name), "Invalid endpoint params", endpoints)

	// verify watch api
	stream, err := endpointRPRClient.WatchEndpoints(context.Background(), &ometa)
	AssertOk(t, err, "Error watching endpoint")
	evt, err := stream.Recv()
	AssertOk(t, err, "Error receiving from stream")
	Assert(t, (evt.Endpoint.Name == epinfo.Name), "Invalid endpoint params", evt)

	// create second endpoint
	ep2 := netproto.Endpoint{
		TypeMeta: api.TypeMeta{Kind: "Endpoint"},
		ObjectMeta: api.ObjectMeta{
			Name:      "testEndpoint2",
			Namespace: "",
			Tenant:    "default",
		},
		Spec: netproto.EndpointSpec{
			EndpointUUID:   "testEndpointUUID2",
			WorkloadUUID:   "testContainerUUID2",
			WorkloadName:   "testContainerName2",
			NetworkName:    "default",
			HomingHostAddr: "192.168.1.1",
			HomingHostName: "testHost",
		},
	}
	_, err = endpointRPRClient.CreateEndpoint(context.Background(), &ep2)
	AssertOk(t, err, "Error creating endpoint")

	// verify we receive a watch event
	evt, err = stream.Recv()
	AssertOk(t, err, "Error receiving from stream")
	Assert(t, (evt.EventType == api.EventType_CreateEvent), "Invalid event type", evt)
	Assert(t, (evt.Endpoint.Name == ep2.Name), "Invalid endpoint params", evt)

	// delete the endpoint
	_, err = endpointRPRClient.DeleteEndpoint(context.Background(), &epinfo)
	AssertOk(t, err, "Error deleting the endpoint")

	// verify we receive a delete event
	evt, err = stream.Recv()
	AssertOk(t, err, "Error receiving from stream")
	Assert(t, (evt.EventType == api.EventType_DeleteEvent), "Invalid event type", evt)

	// stop the rpc server
	rpcClient.Close()
	rpcServer.Stop()
	time.Sleep(time.Millisecond * 10)
}

// TestEndpointRPCParams tests invalid params
func TestEndpointRPCParams(t *testing.T) {
	// create rpc server and client
	stateMgr, rpcServer, rpcClient := createRPCServerClient(t)
	Assert(t, ((stateMgr != nil) && (rpcServer != nil) && (rpcClient != nil)), "Err creating rpc server")
	defer rpcServer.Stop()

	// create API client
	endpointRPRClient := netproto.NewEndpointApiClient(rpcClient.ClientConn)

	// endpoint params with invalid params
	badEp := netproto.Endpoint{
		ObjectMeta: api.ObjectMeta{
			Name:   "invalidEndpoint",
			Tenant: "default",
		},
		Spec: netproto.EndpointSpec{
			NetworkName: "invalid",
		},
	}

	// verify creating endpoint on non-existing network returns error
	_, err := endpointRPRClient.CreateEndpoint(context.Background(), &badEp)
	Assert(t, (err != nil), "Invalid endpoint creating succeeded", badEp)

	// verify deleting invalid endpoint fails
	_, err = endpointRPRClient.DeleteEndpoint(context.Background(), &badEp)
	Assert(t, (err != nil), "Invalid endpoint creating succeeded", badEp)

	// verify we can get the sg
	ometa := api.ObjectMeta{Name: "invalid", Tenant: "default"}
	_, err = endpointRPRClient.GetEndpoint(context.Background(), &ometa)
	Assert(t, (err != nil), "Getting non-extisting endpoint succeeded")

	// stop the rpc server
	rpcClient.Close()
	rpcServer.Stop()
	time.Sleep(time.Millisecond * 10)
}

// TestSecurityGroupRPC tests security group rpcs
func TestSecurityGroupRPC(t *testing.T) {
	// create rpc server and client
	stateMgr, rpcServer, rpcClient := createRPCServerClient(t)
	Assert(t, ((stateMgr != nil) && (rpcServer != nil) && (rpcClient != nil)), "Err creating rpc server")
	defer rpcServer.Stop()

	// create API client
	sgRPCClient := netproto.NewSecurityApiClient(rpcClient.ClientConn)

	// sg params
	sgp := security.SecurityGroup{
		TypeMeta: api.TypeMeta{Kind: "SecurityGroup"},
		ObjectMeta: api.ObjectMeta{
			Tenant: "default",
			Name:   "testsg",
		},
		Spec: security.SecurityGroupSpec{
			WorkloadSelector: labels.SelectorFromSet(labels.Set{"env": "production", "app": "procurement"}),
		},
	}
	// create an sg in statemgr
	err := stateMgr.CreateSecurityGroup(&sgp)
	AssertOk(t, err, "Error creating sg")

	// verify we can get the sg
	ometa := api.ObjectMeta{Name: "testsg", Tenant: "default"}
	sgo, err := sgRPCClient.GetSecurityGroup(context.Background(), &ometa)
	AssertOk(t, err, "Error getting sg")
	Assert(t, reflect.DeepEqual(&sgo.ObjectMeta, &sgp.ObjectMeta), "Got invalid sg params", sgo)

	// verify list works
	sgl, err := sgRPCClient.ListSecurityGroups(context.Background(), &ometa)
	AssertOk(t, err, "Error listing security groups")
	Assert(t, (len(sgl.SecurityGroups) == 1), "Invalid number of security groups in list", sgl)
	Assert(t, reflect.DeepEqual(&sgl.SecurityGroups[0].ObjectMeta, &sgp.ObjectMeta), "Invalid sg params", sgl.SecurityGroups[0])

	// verify getting non-existing security group returns an error
	ometa = api.ObjectMeta{Name: "invalid", Tenant: "default"}
	_, err = sgRPCClient.GetSecurityGroup(context.Background(), &ometa)
	Assert(t, (err != nil), "Getting non-existing security group didnt return error")

	// verify watch API
	stream, err := sgRPCClient.WatchSecurityGroups(context.Background(), &ometa)
	AssertOk(t, err, "Error watching sg")
	evt, err := stream.Recv()
	AssertOk(t, err, "Error receiving sg")
	Assert(t, reflect.DeepEqual(&evt.SecurityGroup.ObjectMeta, &sgp.ObjectMeta), "Received invalid sg", evt.SecurityGroup)

	// create a sgpolicy
	pol := security.SGPolicy{
		TypeMeta: api.TypeMeta{Kind: "SGPolicy"},
		ObjectMeta: api.ObjectMeta{
			Tenant: "default",
			Name:   "pol1",
		},
		Spec: security.SGPolicySpec{
			AttachGroups: []string{"testsg"},
			Rules: []security.SGRule{
				{
					ProtoPorts: []security.ProtoPort{
						{
							Protocol: "tcp",
							Ports:    "80",
						},
					},
					Action: "PERMIT",
				},
			},
		},
	}
	err = stateMgr.CreateSgpolicy(&pol)
	AssertOk(t, err, "Error creating sg policy")

	// verify we get a update event
	evt, err = stream.Recv()
	AssertOk(t, err, "Error receiving sg")
	Assert(t, (evt.EventType == api.EventType_UpdateEvent), "Received invalid event type", evt)
	//Assert(t, (len(evt.SecurityGroup.Spec.Rules) == 2), "Invalid rules in sg", evt.SecurityGroup)

	// create second network and verify we receive a watch event
	sgp2 := security.SecurityGroup{
		TypeMeta: api.TypeMeta{Kind: "SecurityGroup"},
		ObjectMeta: api.ObjectMeta{
			Name:   "testsg2",
			Tenant: "default",
		},
		Spec: security.SecurityGroupSpec{
			WorkloadSelector: labels.SelectorFromSet(labels.Set{"env": "production", "app": "procurement"}),
		},
	}
	err = stateMgr.CreateSecurityGroup(&sgp2)
	AssertOk(t, err, "Failed to create sg")

	// verify we receive a watch event
	evt, err = stream.Recv()
	AssertOk(t, err, "Error receiving sg")
	Assert(t, (evt.EventType == api.EventType_CreateEvent), "Invalid event type", evt)
	Assert(t, reflect.DeepEqual(&evt.SecurityGroup.ObjectMeta, &sgp2.ObjectMeta), "Received invalid sg", evt.SecurityGroup)

	// delete the sg policy
	err = stateMgr.DeleteSgpolicy("default", "pol1")
	AssertOk(t, err, "Error deleting sg policy")

	// verify we receive a watch event
	evt, err = stream.Recv()
	AssertOk(t, err, "Error receiving sg")
	Assert(t, (evt.EventType == api.EventType_UpdateEvent), "Invalid event type", evt)

	// delete the sg
	err = stateMgr.DeleteSecurityGroup(sgp.Tenant, sgp.Name)
	AssertOk(t, err, "Failed to delete sg")

	// verify we receive a delete event
	evt, err = stream.Recv()
	AssertOk(t, err, "Error receiving from stream")
	Assert(t, (evt.EventType == api.EventType_DeleteEvent), "Invalid event type", evt)

	// stop the rpc server
	rpcClient.Close()
	rpcServer.Stop()
	time.Sleep(time.Millisecond * 10)
}

// TestSGPolicyRPC tests sg policy rpcs
func TestSGPolicyRPC(t *testing.T) {
	rpckit.SetDefaultClientFactory(rpckit.NewClientFactory("testnode"))
	// create rpc server and client
	stateMgr, rpcServer, rpcClient := createRPCServerClient(t)
	Assert(t, ((stateMgr != nil) && (rpcServer != nil) && (rpcClient != nil)), "Err creating rpc server")
	defer rpcServer.Stop()

	// create API client
	sgRPCClient := netproto.NewSGPolicyApiClient(rpcClient.ClientConn)

	// sg params
	sgp := security.SGPolicy{
		TypeMeta: api.TypeMeta{Kind: "SGPolicy"},
		ObjectMeta: api.ObjectMeta{
			Tenant:       "default",
			Namespace:    "default",
			Name:         "testSGPolicy",
			GenerationID: "1",
		},
		Spec: security.SGPolicySpec{
			AttachTenant: true,
			Rules: []security.SGRule{
				{
					ProtoPorts: []security.ProtoPort{
						{
							Protocol: "tcp",
							Ports:    "80",
						},
					},
					Action:          "PERMIT",
					FromIPAddresses: []string{"10.0.0.1/16"},
					ToIPAddresses:   []string{"192.168.1.1/16"},
				},
			},
		},
	}
	// create an sg in statemgr
	err := stateMgr.CreateSgpolicy(&sgp)
	AssertOk(t, err, "Error creating sg policy")

	// verify we can get the sg
	ometa := api.ObjectMeta{Name: "testSGPolicy", Tenant: "default"}
	sgo, err := sgRPCClient.GetSGPolicy(context.Background(), &ometa)
	AssertOk(t, err, "Error getting sg policy")
	Assert(t, reflect.DeepEqual(&sgo.ObjectMeta, &sgp.ObjectMeta), "Got invalid sg policy params", sgo)

	// verify list works
	sgl, err := sgRPCClient.ListSGPolicys(context.Background(), &ometa)
	AssertOk(t, err, "Error listing sg policies")
	Assert(t, (len(sgl.Sgpolicies) == 1), "Invalid number of sg policiess in list", sgl)
	Assert(t, reflect.DeepEqual(&sgl.Sgpolicies[0].ObjectMeta, &sgp.ObjectMeta), "Invalid sg policy params", sgl.Sgpolicies[0])

	// verify getting non-existing security group returns an error
	ometa = api.ObjectMeta{Name: "invalid", Tenant: "default"}
	_, err = sgRPCClient.GetSGPolicy(context.Background(), &ometa)
	Assert(t, (err != nil), "Getting non-existing sg policy didn't return error")

	// verify watch API
	stream, err := sgRPCClient.WatchSGPolicys(context.Background(), &ometa)
	AssertOk(t, err, "Error watching sg policy")
	evt, err := stream.Recv()
	AssertOk(t, err, "Error receiving sg policy")
	Assert(t, reflect.DeepEqual(&evt.SGPolicy.ObjectMeta, &sgp.ObjectMeta), "Received invalid sg policy", evt.SGPolicy)

	// create backing sg
	sg := security.SecurityGroup{
		TypeMeta: api.TypeMeta{Kind: "SecurityGroup"},
		ObjectMeta: api.ObjectMeta{
			Tenant: "default",
			Name:   "testsg",
		},
		Spec: security.SecurityGroupSpec{
			WorkloadSelector: labels.SelectorFromSet(labels.Set{"env": "production", "app": "procurement"}),
		},
	}
	// create an sg in statemgr
	err = stateMgr.CreateSecurityGroup(&sg)
	AssertOk(t, err, "Error creating sg")
	// create a sgpolicy
	pol := security.SGPolicy{
		TypeMeta: api.TypeMeta{Kind: "SGPolicy"},
		ObjectMeta: api.ObjectMeta{
			Tenant:       "default",
			Namespace:    "default",
			Name:         "testSGPolicy",
			GenerationID: "1",
		},
		Spec: security.SGPolicySpec{
			AttachGroups: []string{"testsg"},
			Rules: []security.SGRule{
				{
					ProtoPorts: []security.ProtoPort{
						{
							Protocol: "tcp",
							Ports:    "80",
						},
					},
					Action: "PERMIT",
				},
			},
		},
	}
	err = stateMgr.CreateSgpolicy(&pol)
	AssertOk(t, err, "Error creating sg policy")

	// verify we get a update event
	evt, err = stream.Recv()
	AssertOk(t, err, "Error receiving sg")
	Assert(t, evt.EventType == api.EventType_UpdateEvent, "Received invalid event type", evt)

	// update the status
	_, err = sgRPCClient.UpdateSGPolicyStatus(context.Background(), &evt.SGPolicy)

	stateSgp, err := stateMgr.FindSgpolicy("default", "testSGPolicy")
	Assert(t, stateSgp.NodeVersions["testnode"] == "1", "Nodes didn't update", stateSgp.NodeVersions)

	// delete the sg policy
	err = stateMgr.DeleteSgpolicy("default", "testSGPolicy")
	AssertOk(t, err, "Error deleting sg policy")

	// verify we receive a delete event
	evt, err = stream.Recv()
	AssertOk(t, err, "Error receiving from stream")
	Assert(t, evt.EventType == api.EventType_DeleteEvent, "Invalid event type", evt)

	// stop the rpc server
	rpcClient.Close()
	rpcServer.Stop()
	time.Sleep(time.Millisecond * 10)
}

// TestFirewallProfileRPC tests firewall profile rpc calls
func TestFirewallProfileRPC(t *testing.T) {
	// create rpc server and client
	stateMgr, rpcServer, rpcClient := createRPCServerClient(t)
	Assert(t, ((stateMgr != nil) && (rpcServer != nil) && (rpcClient != nil)), "Err creating rpc server")
	defer rpcServer.Stop()

	// create API client
	fwpRPRClient := netproto.NewSecurityProfileApiClient(rpcClient.ClientConn)

	// firewall profile
	fwp := security.FirewallProfile{
		TypeMeta: api.TypeMeta{Kind: "FirewallProfile"},
		ObjectMeta: api.ObjectMeta{
			Name:      "testProfile",
			Namespace: "",
			Tenant:    "default",
		},
		Spec: security.FirewallProfileSpec{
			SessionIdleTimeout:    "3m",
			IPNormalizationEnable: true,
		},
	}
	err := stateMgr.FirewallProfileReactor().CreateFirewallProfile(fwp)
	AssertOk(t, err, "Error creating firewall profile")

	// verify we can get the firewall profile
	ometa := api.ObjectMeta{Name: "testProfile", Tenant: "default"}
	fpo, err := fwpRPRClient.GetSecurityProfile(context.Background(), &ometa)
	AssertOk(t, err, "Error getting fw profile")
	Assert(t, reflect.DeepEqual(&fpo.ObjectMeta, &fwp.ObjectMeta), "Got invalid firewall profile params", fpo)

	// verify list fw profile
	fwps, err := fwpRPRClient.ListSecurityProfiles(context.Background(), &ometa)
	AssertOk(t, err, "Error listing fw profile")
	Assert(t, (len(fwps.Profiles) == 1), "Received invalid number of fw profiles", fwps)
	Assert(t, (fwps.Profiles[0].Name == fwp.Name), "Invalid endpoint params", fwps)

	// verify watch api
	stream, err := fwpRPRClient.WatchSecurityProfiles(context.Background(), &ometa)
	AssertOk(t, err, "Error watching fw profile")
	evt, err := stream.Recv()
	AssertOk(t, err, "Error receiving from stream")
	Assert(t, (evt.SecurityProfile.Name == fwp.Name), "Invalid fw profile params", evt)

	// create second fw profile
	fwp2 := security.FirewallProfile{
		TypeMeta: api.TypeMeta{Kind: "FirewallProfile"},
		ObjectMeta: api.ObjectMeta{
			Name:      "testProfile2",
			Namespace: "",
			Tenant:    "default",
		},
		Spec: security.FirewallProfileSpec{
			SessionIdleTimeout:    "3m",
			IPNormalizationEnable: true,
		},
	}
	err = stateMgr.FirewallProfileReactor().CreateFirewallProfile(fwp2)
	AssertOk(t, err, "Error creating firewall profile")

	// verify we receive a watch event
	evt, err = stream.Recv()
	AssertOk(t, err, "Error receiving from stream")
	Assert(t, (evt.EventType == api.EventType_CreateEvent), "Invalid event type", evt)
	Assert(t, (evt.SecurityProfile.Name == fwp2.Name), "Invalid fw profile params", evt)

	// delete the fw profile
	err = stateMgr.FirewallProfileReactor().DeleteFirewallProfile(fwp)
	AssertOk(t, err, "Error deleting the firewall profile")

	// verify we receive a delete event
	evt, err = stream.Recv()
	AssertOk(t, err, "Error receiving from stream")
	Assert(t, (evt.EventType == api.EventType_DeleteEvent), "Invalid event type", evt)

	// stop the rpc server
	rpcClient.Close()
	rpcServer.Stop()
	time.Sleep(time.Millisecond * 10)
}

// TestAppRPC tests app rpc calls
func TestAppRPC(t *testing.T) {
	// create rpc server and client
	stateMgr, rpcServer, rpcClient := createRPCServerClient(t)
	Assert(t, ((stateMgr != nil) && (rpcServer != nil) && (rpcClient != nil)), "Err creating rpc server")
	defer rpcServer.Stop()

	// create API client
	appRPRClient := netproto.NewAppApiClient(rpcClient.ClientConn)

	// app
	app := security.App{
		TypeMeta: api.TypeMeta{Kind: "App"},
		ObjectMeta: api.ObjectMeta{
			Name:      "testApp",
			Namespace: "",
			Tenant:    "default",
		},
		Spec: security.AppSpec{
			ProtoPorts: []security.ProtoPort{
				{
					Protocol: "tcp",
					Ports:    "21",
				},
			},
			Timeout: "5m",
			ALG: &security.ALG{
				Type: "FTP",
				FtpAlg: &security.FtpAlg{
					AllowMismatchIPAddress: true,
				},
			},
		},
	}
	err := stateMgr.AppReactor().CreateApp(app)
	AssertOk(t, err, "Error creating app")

	// verify we can get the firewall profile
	ometa := api.ObjectMeta{Name: "testApp", Tenant: "default"}
	apo, err := appRPRClient.GetApp(context.Background(), &ometa)
	AssertOk(t, err, "Error getting app")
	Assert(t, reflect.DeepEqual(&apo.ObjectMeta, &app.ObjectMeta), "Got invalid firewall profile params", apo)

	// verify list app
	apps, err := appRPRClient.ListApps(context.Background(), &ometa)
	AssertOk(t, err, "Error listing app")
	Assert(t, (len(apps.Apps) == 1), "Received invalid number of apps", apps)
	Assert(t, (apps.Apps[0].Name == app.Name), "Invalid app params", apps)

	// verify watch api
	stream, err := appRPRClient.WatchApps(context.Background(), &ometa)
	AssertOk(t, err, "Error watching app")
	evt, err := stream.Recv()
	AssertOk(t, err, "Error receiving from stream")
	Assert(t, (evt.App.Name == app.Name), "Invalid app params", evt)

	// create second app
	app2 := security.App{
		TypeMeta: api.TypeMeta{Kind: "App"},
		ObjectMeta: api.ObjectMeta{
			Name:      "testApp2",
			Namespace: "",
			Tenant:    "testTenant",
		},
		Spec: security.AppSpec{
			ProtoPorts: []security.ProtoPort{
				{
					Protocol: "tcp",
					Ports:    "21",
				},
			},
			Timeout: "5m",
			ALG: &security.ALG{
				Type: "FTP",
				FtpAlg: &security.FtpAlg{
					AllowMismatchIPAddress: true,
				},
			},
		},
	}
	err = stateMgr.AppReactor().CreateApp(app2)
	AssertOk(t, err, "Error creating app")

	// verify we receive a watch event
	evt, err = stream.Recv()
	AssertOk(t, err, "Error receiving from stream")
	Assert(t, (evt.EventType == api.EventType_CreateEvent), "Invalid event type", evt)
	Assert(t, (evt.App.Name == app2.Name), "Invalid app params", evt)

	// delete the endpoint
	err = stateMgr.AppReactor().DeleteApp(app)
	AssertOk(t, err, "Error deleting the app")

	// verify we receive a delete event
	evt, err = stream.Recv()
	AssertOk(t, err, "Error receiving from stream")
	Assert(t, (evt.EventType == api.EventType_DeleteEvent), "Invalid event type", evt)

	// stop the rpc server
	rpcClient.Close()
	rpcServer.Stop()
	time.Sleep(time.Millisecond * 10)
}
