// {C} Copyright 2017 Pensando Systems Inc. All rights reserved.

package smartnic_test

import (
	"context"
	"fmt"
	"os"
	"strings"
	"testing"
	"time"

	"google.golang.org/grpc/grpclog"

	api "github.com/pensando/sw/api"
	apicache "github.com/pensando/sw/api/client"
	"github.com/pensando/sw/api/generated/apiclient"
	cmd "github.com/pensando/sw/api/generated/cluster"
	_ "github.com/pensando/sw/api/generated/exports/apiserver"
	"github.com/pensando/sw/api/generated/monitoring"
	nmd "github.com/pensando/sw/nic/agent/nmd"
	"github.com/pensando/sw/nic/agent/nmd/platform"
	proto "github.com/pensando/sw/nic/agent/nmd/protos"
	apiserver "github.com/pensando/sw/venice/apiserver"
	apiserverpkg "github.com/pensando/sw/venice/apiserver/pkg"
	cmdapi "github.com/pensando/sw/venice/cmd/apiclient"
	"github.com/pensando/sw/venice/cmd/cache"
	cmdenv "github.com/pensando/sw/venice/cmd/env"
	"github.com/pensando/sw/venice/cmd/grpc"
	. "github.com/pensando/sw/venice/cmd/grpc/server/smartnic"
	cmdsvc "github.com/pensando/sw/venice/cmd/services"
	"github.com/pensando/sw/venice/cmd/services/mock"
	"github.com/pensando/sw/venice/globals"
	"github.com/pensando/sw/venice/utils"
	"github.com/pensando/sw/venice/utils/events/recorder"
	store "github.com/pensando/sw/venice/utils/kvstore/store"
	"github.com/pensando/sw/venice/utils/log"
	"github.com/pensando/sw/venice/utils/resolver"
	"github.com/pensando/sw/venice/utils/rpckit"
	"github.com/pensando/sw/venice/utils/runtime"
	. "github.com/pensando/sw/venice/utils/testutils"
	ventrace "github.com/pensando/sw/venice/utils/trace"
	"github.com/pensando/sw/venice/utils/tsdb"
)

const (
	smartNICServerURL = "localhost:9199"
	resolverURLs      = ":" + globals.CMDResolverPort
	// TODO: This is a temporary way of testing invalid cert
	invalidCertSignature = "unknown-cert"
	healthInterval       = 1 * time.Second
	deadtimeInterval     = 3 * time.Second
)

type testInfo struct {
	l              log.Logger
	apiServerAddr  string
	apiServer      apiserver.Server
	apiClient      apiclient.Services
	rpcServer      *rpckit.RPCServer
	rpcClient      *rpckit.RPCClient
	smartNICServer *RPCServer
}

func (t testInfo) APIClient() cmd.ClusterV1Interface {
	return t.apiClient.ClusterV1()
}

var tInfo testInfo

// runRPCServer creates a smartNIC server for SmartNIC service.
func createRPCServer(url, certFile, keyFile, caFile string) (*rpckit.RPCServer, error) {

	// set cmd logger, statemgr & quorum nodes
	cmdenv.Logger = tInfo.l
	cmdenv.QuorumNodes = []string{"localhost"}
	cmdenv.StateMgr = cache.NewStatemgr()

	// Start CMD config watcher
	l := mock.NewLeaderService("testMaster")
	s := cmdsvc.NewSystemdService(cmdsvc.WithSysIfSystemdSvcOption(&mock.SystemdIf{}))
	cw := cmdapi.NewCfgWatcherService(tInfo.l, tInfo.apiServerAddr, cmdenv.StateMgr)
	cmdenv.MasterService = cmdsvc.NewMasterService(
		cmdsvc.WithLeaderSvcMasterOption(l),
		cmdsvc.WithSystemdSvcMasterOption(s),
		cmdsvc.WithConfigsMasterOption(&mock.Configs{}),
		cmdsvc.WithCfgWatcherMasterOption(cw))
	cw.Start()

	// create an RPC server.
	rpcServer, err := rpckit.NewRPCServer("smartNIC", url)
	if err != nil {
		fmt.Printf("Error creating RPC-server: %v", err)
		return nil, err
	}
	tInfo.rpcServer = rpcServer
	cmdenv.UnauthRPCServer = rpcServer

	// create and register the RPC handler for SmartNIC service
	tInfo.smartNICServer, err = NewRPCServer(tInfo, healthInterval, deadtimeInterval, getRESTPort(1), cmdenv.StateMgr)
	if err != nil {
		fmt.Printf("Error creating SmartNIC RPC server: %v", err)
		return nil, err
	}

	// Register self as rpc handler for both NIC registration and watch/updates on the server.
	// In reality, CMD uses two different servers because watches and updates APIs are
	// exposed over TLS, whereas NIC registration is not.
	grpc.RegisterSmartNICRegistrationServer(rpcServer.GrpcServer, tInfo.smartNICServer)
	grpc.RegisterSmartNICUpdatesServer(rpcServer.GrpcServer, tInfo.smartNICServer)
	rpcServer.Start()
	cmdenv.NICService = tInfo.smartNICServer

	// Launch go routine to monitor health updates of smartNIC objects and update status
	go func() {
		tInfo.smartNICServer.MonitorHealth()
	}()

	return rpcServer, nil
}

// createRPCServerClient creates rpc client and server for SmartNIC service
func createRPCServerClient() (*rpckit.RPCServer, *rpckit.RPCClient) {

	// start the rpc server
	rpcServer, err := createRPCServer(smartNICServerURL, "", "", "")
	if err != nil {
		fmt.Printf("Error connecting to grpc server. Err: %v", err)
		return nil, nil
	}

	// create a grpc client
	rpcClient, err := rpckit.NewRPCClient("smartNIC", smartNICServerURL)
	if err != nil {
		fmt.Printf("Error connecting to grpc server. Err: %v", err)
		rpcServer.Stop()
		return nil, nil
	}

	return rpcServer, rpcClient
}

// Create NMD and Agent
func createNMD(t *testing.T, dbPath, hostID, restURL string) (*nmd.Agent, error) {

	// create a platform agent
	pa, err := platform.NewNaplesPlatformAgent()
	if err != nil {
		log.Fatalf("Error creating platform agent. Err: %v", err)
	}

	r := resolver.New(&resolver.Config{Name: t.Name(), Servers: strings.Split(resolverURLs, ",")})
	// create the new NMD
	ag, err := nmd.NewAgent(pa,
		dbPath,
		hostID,
		hostID,
		smartNICServerURL,
		smartNICServerURL,
		restURL,
		"classic",
		globals.NicRegIntvl*time.Second,
		globals.NicUpdIntvl*time.Second,
		r)
	if err != nil {
		t.Errorf("Error creating NMD. Err: %v", err)
	}

	return ag, err
}

// stopAgent stops NMD server and deletes emDB file
func stopNMD(t *testing.T, ag *nmd.Agent, dbPath string) {

	ag.Stop()
	err := os.Remove(dbPath)
	if err != nil {
		log.Errorf("Error deleting emDB file: %s, err: %v", dbPath, err)
	}
}

func getHostID(index int) string {
	return fmt.Sprintf("44.44.44.44.%02x.%02x", index/256, index%256)
}

func getRESTPort(index int) string {
	return fmt.Sprintf("%d", 15000+index)
}

func getRESTUrl(index int) string {
	return fmt.Sprintf("localhost:%s", getRESTPort(index))
}

func getDBPath(index int) string {
	return fmt.Sprintf("/tmp/nmd-%d.db", index)
}

// TestRegisterSmartNICByNaples tests RegisterNIC
// functionality initiated by User
func TestRegisterSmartNICByNaples(t *testing.T) {

	// Init required components
	testSetup()
	defer testTeardown()

	testCases := []struct {
		name        string
		mac         string
		autoAdmit   bool
		cert        []byte
		expected    string
		condition   cmd.SmartNICCondition
		approvedNIC string
		hostName    string
	}{
		{
			"TestAutoAdmitValidNIC",
			"4444.4444.0001",
			true,
			[]byte(ValidCertSignature),
			cmd.SmartNICSpec_ADMITTED.String(),
			cmd.SmartNICCondition{
				Type:               cmd.SmartNICCondition_HEALTHY.String(),
				Status:             cmd.ConditionStatus_TRUE.String(),
				LastTransitionTime: time.Now().Format(time.RFC3339),
			},
			"",
			"esx-001",
		},
		{
			"TestAutoAdmitInvalidNIC",
			"4444.4444.0002",
			true,
			[]byte(invalidCertSignature),
			cmd.SmartNICSpec_REJECTED.String(),
			cmd.SmartNICCondition{},
			"",
			"esx-002",
		},
		{
			"TestManualValidNIC",
			"4444.4444.0003",
			false,
			[]byte(ValidCertSignature),
			cmd.SmartNICSpec_PENDING.String(),
			cmd.SmartNICCondition{
				Type:               cmd.SmartNICCondition_HEALTHY.String(),
				Status:             cmd.ConditionStatus_FALSE.String(),
				LastTransitionTime: time.Now().Format(time.RFC3339),
			},
			"",
			"esx-003",
		},
		{
			"TestManualValidApprovedNIC",
			"4444.4444.0004",
			false,
			[]byte(ValidCertSignature),
			cmd.SmartNICSpec_PENDING.String(),
			cmd.SmartNICCondition{
				Type:               cmd.SmartNICCondition_HEALTHY.String(),
				Status:             cmd.ConditionStatus_TRUE.String(),
				LastTransitionTime: time.Now().Format(time.RFC3339),
			},
			"4444.4444.0004",
			"esx-004",
		},
		{
			"TestManualInvalidNIC",
			"4444.4444.0005",
			false,
			[]byte(invalidCertSignature),
			cmd.SmartNICSpec_REJECTED.String(),
			cmd.SmartNICCondition{},
			"",
			"esx-005",
		},
	}

	// Pre-create some Hosts to simulate the case of prior
	// Host creation by Orchestrator (VC-hub)
	hosts := []string{
		"esx-003",
	}
	for _, hostName := range hosts {
		ometa := api.ObjectMeta{
			Name: hostName,
		}
		_, err := tInfo.smartNICServer.CreateHost(ometa)
		AssertOk(t, err, "Error creating Host object")
	}

	// Execute the testcases
	for _, tc := range testCases {

		t.Run(tc.name, func(t *testing.T) {

			// create API clients
			smartNICRegistrationRPCClient := grpc.NewSmartNICRegistrationClient(tInfo.rpcClient.ClientConn)
			smartNICUpdatesRPCClient := grpc.NewSmartNICUpdatesClient(tInfo.rpcClient.ClientConn)

			// Set cluster admission mode to auto-admit or manual based on test input
			refObj, err := tInfo.smartNICServer.GetCluster()
			if err != nil {
				t.Fatalf("Error getting Cluster object, err: %v", err)
			}

			var clRef cmd.Cluster
			clRef.ObjectMeta.Name = "testCluster"
			clRef.ObjectMeta.ResourceVersion = refObj.ObjectMeta.ResourceVersion
			clRef.Spec.AutoAdmitNICs = tc.autoAdmit
			clObj, err := tInfo.apiClient.ClusterV1().Cluster().Update(context.Background(), &clRef)
			if err != nil || clObj == nil {
				t.Fatalf("Error updating cluster auto-admit status: %v %v", clObj, err)
			}

			// Construct SmartNIC object with valid cert/signature
			ometa := api.ObjectMeta{Name: tc.mac}
			nic := cmd.SmartNIC{
				TypeMeta:   api.TypeMeta{Kind: "SmartNIC"},
				ObjectMeta: ometa,
				Spec: cmd.SmartNICSpec{
					Phase:    cmd.SmartNICSpec_REGISTERING.String(),
					HostName: tc.hostName,
					MgmtIp:   "0.0.0.0",
				},
			}

			req := &grpc.RegisterNICRequest{
				Nic:  nic,
				Cert: tc.cert,
			}

			// register NIC call
			resp, err := smartNICRegistrationRPCClient.RegisterNIC(context.Background(), req)
			t.Logf("Testcase: %s MAC: %s expected: %v obtained: %v err: %v", tc.name, tc.mac, tc.expected, resp, err)

			AssertOk(t, err, "Error registering NIC")
			Assert(t, resp.Phase == tc.expected, "\nexpected:\n%v\nobtained:\n%v",
				tc.expected, resp.Phase)

			if tc.expected == cmd.SmartNICSpec_ADMITTED.String() || tc.expected == cmd.SmartNICSpec_PENDING.String() {

				// verify smartNIC is created
				f1 := func() (bool, interface{}) {
					nicObj, err := tInfo.smartNICServer.GetSmartNIC(ometa)
					if err != nil {
						t.Errorf("Error getting NIC object for mac:%s", tc.mac)
						return false, nil
					}
					if nicObj.ObjectMeta.Name != tc.mac {
						t.Errorf("Got incorrect smartNIC object, expected: %s obtained: %s",
							nicObj.ObjectMeta.Name, tc.mac)
						return false, nil
					}

					return true, nil
				}
				AssertEventually(t, f1, fmt.Sprintf("Failed to verify presence of smartNIC object"))

				// verify Host object is created
				f2 := func() (bool, interface{}) {
					ometa := api.ObjectMeta{Name: tc.hostName}
					hostObj, err := tInfo.smartNICServer.GetHost(ometa)
					if err != nil {
						t.Errorf("Error getting Host object for host:%s", tc.hostName)
						return false, nil
					}
					if hostObj.ObjectMeta.Name != tc.hostName {
						t.Errorf("Got incorrect Host object, expected: %s obtained: %s",
							hostObj.ObjectMeta.Name, tc.hostName)
						return false, nil
					}
					return true, nil
				}
				AssertEventually(t, f2, fmt.Sprintf("Failed to verify presence of Host object"))

				// verify watch api is invoked
				f3 := func() (bool, interface{}) {
					stream, err := smartNICUpdatesRPCClient.WatchNICs(context.Background(), &ometa)
					if err != nil {
						t.Errorf("Error watching smartNIC, mac: %s, err: %v", tc.mac, err)
						return false, nil
					}
					evt, err := stream.Recv()
					if err != nil {
						t.Errorf("Error receiving from stream, mac: %s err: %v", tc.mac, err)
						return false, nil
					}
					if evt.Nic.Name != tc.mac {
						t.Errorf("Got incorrect smartNIC watch event: %v expected: %s err: %v", evt, tc.mac, err)
						return false, nil
					}

					return true, nil
				}
				AssertEventually(t, f3, fmt.Sprintf("Failed to verify watch for smartNIC event"))

				// Verify UpdateNIC RPC
				f4 := func() (bool, interface{}) {
					var phase string
					if nic.ObjectMeta.Name == tc.approvedNIC {
						phase = cmd.SmartNICSpec_ADMITTED.String()
					}
					ometa = api.ObjectMeta{Name: tc.mac}
					nic = cmd.SmartNIC{
						TypeMeta:   api.TypeMeta{Kind: "SmartNIC"},
						ObjectMeta: ometa,
						Spec: cmd.SmartNICSpec{
							Phase: phase,
						},
						Status: cmd.SmartNICStatus{
							Conditions: []*cmd.SmartNICCondition{
								&tc.condition,
							},
						},
					}

					req := &grpc.UpdateNICRequest{
						Nic: nic,
					}

					resp, err := smartNICUpdatesRPCClient.UpdateNIC(context.Background(), req)
					if err != nil {
						t.Logf("Testcase: %s Failed to update NIC, mac: %s req: %+v resp: %+v", tc.name, tc.mac, req.Nic, resp.Nic)
						return false, nil
					}

					if resp.Nic.Status.Conditions[0].Type != tc.condition.Type || resp.Nic.Status.Conditions[0].Status != tc.condition.Status {
						t.Logf("Testcase: %s,  Condition expected:\n%+v\nobtained:%+v", tc.name, tc.condition, resp.Nic.Status.Conditions[0])
						return false, nil
					}

					if nic.ObjectMeta.Name == tc.approvedNIC {
						if resp.Nic.Spec.Phase != cmd.SmartNICSpec_ADMITTED.String() {
							t.Logf("Testcase: %s \nPhase expected:\n%+v\nobtained:\n%+v", tc.name, cmd.SmartNICSpec_ADMITTED.String(), resp.Nic.Spec.Phase)
							return false, nil
						}
					}

					return true, nil
				}
				AssertEventually(t, f4, fmt.Sprintf("Failed to verify update for smartNIC"))

				// Verify NIC health status goes to UNKNOWN after deadtimeInterval
				f5 := func() (bool, interface{}) {

					nicObj, err := tInfo.smartNICServer.GetSmartNIC(ometa)
					if err != nil {
						t.Errorf("Error getting NIC object for mac:%s", tc.mac)
						return false, nil
					}
					if nicObj.ObjectMeta.Name != tc.mac {
						t.Errorf("Got incorrect smartNIC object, expected: %s obtained: %s",
							nicObj.ObjectMeta.Name, tc.mac)
						return false, nil
					}

					if nicObj.Status.Conditions[0].Type != tc.condition.Type || nicObj.Status.Conditions[0].Status != cmd.ConditionStatus_UNKNOWN.String() {
						t.Logf("Testcase: %s,  Condition expected:\n%+v\nobtained:%+v", tc.name, cmd.ConditionStatus_UNKNOWN, nicObj.Status.Conditions[0])
						return false, nil
					}

					return true, nil
				}
				AssertEventually(t, f5, fmt.Sprintf("Failed to verify NIC health status going to UNKNOWN"))

				// Verify Host object has its status updated with list of registered NICs
				f6 := func() (bool, interface{}) {
					ometa = api.ObjectMeta{Name: tc.hostName}
					hostObj, err := tInfo.smartNICServer.GetHost(ometa)
					if err != nil {
						t.Errorf("Error getting Host object for host:%s", tc.hostName)
						return false, nil
					}
					intfs := hostObj.Spec.Interfaces
					t.Logf("\n++++++ Host mac list, host: %+v \nIntfs: %+v\n", hostObj, intfs)

					for mac, _ := range intfs {
						if mac == tc.mac {
							return true, nil
						}

					}
					return false, nil
				}
				AssertEventually(t, f6, fmt.Sprintf("Failed to verify that Host object is updated with registered nic"))

				// Verify Deletion of SmartNIC object
				f7 := func() (bool, interface{}) {
					ometa = api.ObjectMeta{Name: tc.mac}
					err = tInfo.smartNICServer.DeleteSmartNIC(ometa)
					if err != nil {
						return false, nil
					}
					return true, nil
				}
				AssertEventually(t, f7, fmt.Sprintf("Failed to verify deletion of smartNIC object"))

				if err != nil {
					t.Fatalf("Error deleteing SmartNIC object mac:%s err: %v", tc.mac, err)
				}

				// Verify Deletion of Host object
				f8 := func() (bool, interface{}) {
					ometa = api.ObjectMeta{Name: tc.hostName}
					err = tInfo.smartNICServer.DeleteHost(ometa)
					if err != nil {
						return false, nil
					}
					return true, nil
				}
				AssertEventually(t, f8, fmt.Sprintf("Failed to verify deletion of Host object"))

			} else {

				// Verify SmartNIC object is not created
				f1 := func() (bool, interface{}) {
					nicObj, err := tInfo.smartNICServer.GetSmartNIC(ometa)
					if err != nil || nicObj == nil {
						return true, nil
					}
					t.Errorf("SmartNIC object should not exist for mac:%s err:%v", tc.mac, err)
					return false, nil
				}
				AssertEventually(t, f1, fmt.Sprintf("Failed to verify absence of smartNIC object"))
			}

		})
	}
}

func TestUpdateSmartNIC(t *testing.T) {

	// Init required components
	testSetup()
	defer testTeardown()

	// Verify create nic
	nic := cmd.SmartNIC{
		TypeMeta:   api.TypeMeta{Kind: "SmartNIC"},
		ObjectMeta: api.ObjectMeta{Name: "2222.2222.2222"},
		Spec: cmd.SmartNICSpec{
			Phase:  "UNKNOWN",
			MgmtIp: "10.1.1.1",
		},
	}
	nicObj, err := tInfo.smartNICServer.UpdateSmartNIC(&nic)
	AssertOk(t, err, "Failed to create nic object, 2222.2222.222")

	// Verify update nic
	nic = cmd.SmartNIC{
		TypeMeta:   nicObj.TypeMeta,
		ObjectMeta: nicObj.ObjectMeta,
		Status: cmd.SmartNICStatus{
			Conditions: []*cmd.SmartNICCondition{
				{
					Type:   cmd.SmartNICCondition_HEALTHY.String(),
					Status: cmd.ConditionStatus_FALSE.String(),
				},
			},
		},
	}
	nicObj, err = tInfo.smartNICServer.UpdateSmartNIC(&nic)
	AssertOk(t, err, "Failed to update nic object, 2222.2222.222")

	// delete nic
	err = tInfo.smartNICServer.DeleteSmartNIC(nic.ObjectMeta)
	AssertOk(t, err, "Failed to delete nic object, 2222.2222.222")
}

func TestDeleteSmartNIC(t *testing.T) {

	testSetup()
	defer testTeardown()

	// Verify Delete SmartNIC object
	ometa := api.ObjectMeta{Name: "1111.1111.1111"}
	err := tInfo.smartNICServer.DeleteSmartNIC(ometa)
	Assert(t, err != nil, "SmartNIC object - 1111.1111.1111 - should not exist")
}

// TestSmartNICConfigByUser tests the following scenario & actions
// - SmartNIC config by user with Mgmt-IP
// - CMD would post naples config via REST to initiate nic registration
//   in managed mode
// - NMD would next do NIC registration
// - CMD would validate NIC and admit NIC into cluster.
func TestSmartNICConfigByUser(t *testing.T) {

	// Init required components
	testSetup()
	defer testTeardown()

	hostID := getHostID(1)
	dbPath := getDBPath(1)
	restURL := getRESTUrl(1)

	// Cleanup any prior DB files
	os.Remove(dbPath)

	// create Agent and NMD
	ag, err := createNMD(t, dbPath, hostID, restURL)
	defer stopNMD(t, ag, dbPath)
	Assert(t, (err == nil && ag != nil), "Failed to create agent", err)

	nm := ag.GetNMD()

	// Validate default classic mode
	f1 := func() (bool, interface{}) {

		cfg := nm.GetNaplesConfig()
		if cfg.Spec.Mode == proto.NaplesMode_CLASSIC_MODE && nm.GetListenURL() != "" &&
			nm.GetUpdStatus() == false && nm.GetRegStatus() == false && nm.GetRestServerStatus() == true {
			return true, nil
		}
		return false, nil
	}
	AssertEventually(t, f1, "Failed to verify mode is in Classic")

	// Create SmartNIC object in Venice
	nic := cmd.SmartNIC{
		TypeMeta: api.TypeMeta{Kind: "SmartNIC"},
		ObjectMeta: api.ObjectMeta{
			Name: hostID,
		},
		Spec: cmd.SmartNICSpec{
			MgmtIp:   "localhost",
			Phase:    "UNKNOWN",
			HostName: hostID,
		},
	}

	_, err = tInfo.apiClient.ClusterV1().SmartNIC().Create(context.Background(), &nic)
	if err != nil {
		t.Errorf("Failed to created smartnic: %+v, err: %v", nic, err)
	}

	// Verify the Naples received the config and switched to Managed Mode
	f4 := func() (bool, interface{}) {

		// validate the mode is managed
		cfg := nm.GetNaplesConfig()
		log.Infof("NaplesConfig: %v", cfg)
		if cfg.Spec.Mode != proto.NaplesMode_MANAGED_MODE {
			log.Errorf("Failed to switch to managed mode")
			return false, nil
		}

		// Fetch smartnic object
		nic, err := nm.GetSmartNIC()
		if nic == nil || err != nil {
			log.Errorf("NIC not found in nicDB, mac:%s", hostID)
			return false, nil
		}

		// Verify NIC is admitted
		if nic.Spec.Phase != cmd.SmartNICSpec_ADMITTED.String() {
			log.Errorf("NIC is not admitted")
			return false, nil
		}

		// Verify Update NIC task is running
		if nm.GetUpdStatus() == false {
			log.Errorf("Update NIC is not in progress")
			return false, nil
		}

		// Verify REST server is not up
		if nm.GetRestServerStatus() == true {
			log.Errorf("REST server is still up")
			return false, nil
		}
		return true, nil
	}
	AssertEventually(t, f4, "Failed to verify mode is in Managed Mode", string("1s"), string("60s"))

	// Validate SmartNIC object state is updated on Venice
	f5 := func() (bool, interface{}) {

		meta := api.ObjectMeta{
			Name: hostID,
		}
		nicObj, err := tInfo.apiClient.ClusterV1().SmartNIC().Get(context.Background(), &meta)
		if err != nil || nicObj == nil || nicObj.Spec.Phase != cmd.SmartNICSpec_ADMITTED.String() {
			log.Errorf("Failed to validate phase of SmartNIC object, mac:%s, phase: %s err: %v",
				hostID, nicObj.Spec.Phase, err)
			return false, nil
		}

		return true, nil
	}
	AssertEventually(t, f5, "Failed to verify creation of required SmartNIC object", string("10ms"), string("30s"))

	// Validate Host object is created
	f6 := func() (bool, interface{}) {

		meta := api.ObjectMeta{
			Name: hostID,
		}
		hostObj, err := tInfo.apiClient.ClusterV1().Host().Get(context.Background(), &meta)
		if err != nil || hostObj == nil {
			log.Errorf("Failed to GET Host object, mac:%s, %v", hostID, err)
			return false, nil
		}

		return true, nil
	}
	AssertEventually(t, f6, "Failed to verify creation of required Host object", string("10ms"), string("30s"))

	// Verify Deletion of SmartNIC object
	f7 := func() (bool, interface{}) {
		ometa := api.ObjectMeta{Name: hostID}
		err = tInfo.smartNICServer.DeleteSmartNIC(ometa)
		if err != nil {
			return false, nil
		}
		return true, nil
	}
	AssertEventually(t, f7, fmt.Sprintf("Failed to verify deletion of smartNIC object"))

	// Verify Deletion of Host object
	f8 := func() (bool, interface{}) {
		ometa := api.ObjectMeta{Name: hostID}
		err = tInfo.smartNICServer.DeleteHost(ometa)
		if err != nil {
			return false, nil
		}
		return true, nil
	}
	AssertEventually(t, f8, fmt.Sprintf("Failed to verify deletion of Host object"))
}

func TestSmartNICConfigByUserErrorCases(t *testing.T) {

	// Init required components
	testSetup()
	defer testTeardown()

	hostID := getHostID(1)
	dbPath := getDBPath(1)
	restURL := getRESTUrl(1)

	// Cleanup any prior DB files
	os.Remove(dbPath)

	// create Agent and NMD
	ag, err := createNMD(t, dbPath, hostID, restURL)
	defer stopNMD(t, ag, dbPath)
	Assert(t, (err == nil && ag != nil), "Failed to create agent", err)

	nm := ag.GetNMD()

	// Validate default classic mode
	f1 := func() (bool, interface{}) {

		cfg := nm.GetNaplesConfig()
		if cfg.Spec.Mode == proto.NaplesMode_CLASSIC_MODE && nm.GetListenURL() != "" &&
			nm.GetUpdStatus() == false && nm.GetRegStatus() == false && nm.GetRestServerStatus() == true {
			return true, nil
		}
		return false, nil
	}
	AssertEventually(t, f1, "Failed to verify mode is in Classic")

	// Create SmartNIC object in Venice
	nic := cmd.SmartNIC{
		TypeMeta: api.TypeMeta{Kind: "SmartNIC"},
		ObjectMeta: api.ObjectMeta{
			Name: hostID,
		},
		Spec: cmd.SmartNICSpec{
			MgmtIp:   "remotehost", // unreachable hostname for testing error case
			Phase:    "UNKNOWN",
			HostName: hostID,
		},
	}

	_, err = tInfo.apiClient.ClusterV1().SmartNIC().Create(context.Background(), &nic)
	if err != nil {
		t.Errorf("Failed to created smartnic: %+v, err: %v", nic, err)
	}

	// Verify SmartNIC object has UNREACHABLE condition
	f2 := func() (bool, interface{}) {

		meta := api.ObjectMeta{
			Name: hostID,
		}
		nicObj, err := tInfo.apiClient.ClusterV1().SmartNIC().Get(context.Background(), &meta)
		if err != nil || nicObj == nil || len(nicObj.Status.Conditions) == 0 ||
			nicObj.Status.Conditions[0].Type != cmd.SmartNICCondition_UNREACHABLE.String() ||
			nicObj.Status.Conditions[0].Status != cmd.ConditionStatus_TRUE.String() {
			log.Errorf("Failed to validate SmartNIC condition, nicObj: %+v, err: %v",
				nicObj, err)
			return false, nil
		}

		return true, nil
	}
	AssertEventually(t, f2, "Failed to verify SmartNIC object has UNREACHABLE condition set",
		string("10ms"), string("30s"))

	// Verify Deletion of SmartNIC object
	f3 := func() (bool, interface{}) {
		ometa := api.ObjectMeta{Name: hostID}
		err = tInfo.smartNICServer.DeleteSmartNIC(ometa)
		if err != nil {
			return false, nil
		}
		return true, nil
	}
	AssertEventually(t, f3, fmt.Sprintf("Failed to verify deletion of smartNIC object"))
}

func testSetup() {

	// Disable open trace
	ventrace.DisableOpenTrace()
	tsdb.Init(tsdb.DummyTransmitter{}, tsdb.Options{})

	// Create api server
	apiServerAddress := ":0"
	l := log.WithContext("module", "CrudOpsTest")
	tInfo.l = l
	scheme := runtime.GetDefaultScheme()
	srvConfig := apiserver.Config{
		GrpcServerPort: apiServerAddress,
		DebugMode:      false,
		Logger:         l,
		Version:        "v1",
		Scheme:         scheme,
		Kvstore: store.Config{
			Type:  store.KVStoreTypeMemkv,
			Codec: runtime.NewJSONCodec(scheme),
		},
	}
	grpclog.SetLogger(l)
	tInfo.apiServer = apiserverpkg.MustGetAPIServer()
	go tInfo.apiServer.Run(srvConfig)
	tInfo.apiServer.WaitRunning()
	addr, err := tInfo.apiServer.GetAddr()
	if err != nil {
		os.Exit(-1)
	}

	// Create api client
	tInfo.apiServerAddr = addr
	apiCl, err := apicache.NewGrpcUpstream("smartnic_test", tInfo.apiServerAddr, tInfo.l)
	if err != nil {
		fmt.Printf("Cannot create gRPC client - %v", err)
		os.Exit(-1)
	}
	tInfo.apiClient = apiCl

	// create gRPC server for smartNIC service and gRPC client
	tInfo.rpcServer, tInfo.rpcClient = createRPCServerClient()
	if tInfo.rpcServer == nil || tInfo.rpcClient == nil {
		fmt.Printf("Err creating rpc server & client")
		os.Exit(-1)
	}

	// Check if no cluster exists to start with - negative test
	_, err = tInfo.smartNICServer.GetCluster()
	if err == nil {
		fmt.Printf("Unexpected cluster object found, err: %s", err)
		os.Exit(-1)
	}

	// Create test cluster object
	clRef := &cmd.Cluster{
		ObjectMeta: api.ObjectMeta{
			Name: "testCluster",
		},
		Spec: cmd.ClusterSpec{
			AutoAdmitNICs: true,
		},
	}
	_, err = tInfo.apiClient.ClusterV1().Cluster().Create(context.Background(), clRef)
	if err != nil {
		fmt.Printf("Error creating Cluster object, %v", err)
		os.Exit(-1)
	}
}

func testTeardown() {

	// delete cluster object
	clRef := &cmd.Cluster{
		ObjectMeta: api.ObjectMeta{
			Name: "testCluster",
		},
	}
	_, err := tInfo.apiClient.ClusterV1().Cluster().Delete(context.Background(), &clRef.ObjectMeta)
	if err != nil {
		fmt.Printf("Error deleting Cluster object, %v", err)
		os.Exit(-1)
	}

	// stop the rpc client and server
	tInfo.rpcClient.Close()
	tInfo.rpcServer.Stop()

	// stop the apiServer
	tInfo.apiServer.Stop()
}

func TestMain(m *testing.M) {
	// create events recorder
	_, _ = recorder.NewRecorder(
		&monitoring.EventSource{NodeName: utils.GetHostname(), Component: "nmd-state-test"},
		cmd.GetEventTypes(), "", "/tmp")

	// Run tests
	rcode := m.Run()

	os.Exit(rcode)
}
