package vchub

import (
	"context"
	"fmt"
	"net"
	"net/url"
	"os"
	"testing"

	"github.com/vmware/govmomi/vim25/types"

	"github.com/pensando/sw/api"
	"github.com/pensando/sw/api/generated/network"
	"github.com/pensando/sw/venice/ctrler/orchhub/orchestrators/vchub/sim"
	"github.com/pensando/sw/venice/ctrler/orchhub/orchestrators/vchub/testutils"
	"github.com/pensando/sw/venice/ctrler/orchhub/orchestrators/vchub/vcprobe"
	"github.com/pensando/sw/venice/ctrler/orchhub/orchestrators/vchub/vcprobe/mock"
	smmock "github.com/pensando/sw/venice/ctrler/orchhub/statemgr"
	"github.com/pensando/sw/venice/globals"
	"github.com/pensando/sw/venice/utils/log"
	conv "github.com/pensando/sw/venice/utils/strconv"
	. "github.com/pensando/sw/venice/utils/testutils"
)

func TestVmotion(t *testing.T) {
	err := testutils.ValidateParams(defaultTestParams)
	if err != nil {
		t.Fatalf("Failed at validating test parameters")
	}

	// SETTING UP LOGGER
	config := log.GetDefaultConfig("vmotion_test")
	config.LogToStdout = true
	config.Filter = log.AllowAllFilter
	logger := log.SetConfig(config)

	// SETTING UP STATE MANAGER
	sm, _, err := smmock.NewMockStateManager()
	if err != nil {
		t.Fatalf("Failed to create state manager. Err : %v", err)
		return
	}

	// CREATING ORCH CONFIG
	orchConfig := smmock.GetOrchestratorConfig(defaultTestParams.TestHostName, defaultTestParams.TestUser, defaultTestParams.TestPassword)

	err = sm.Controller().Orchestrator().Create(orchConfig)

	// SETTING UP VCSIM
	vcURL := &url.URL{
		Scheme: "http",
		Host:   defaultTestParams.TestHostName,
		Path:   "/sdk",
	}
	vcURL.User = url.UserPassword(defaultTestParams.TestUser, defaultTestParams.TestPassword)

	s, err := sim.NewVcSim(sim.Config{Addr: vcURL.String()})
	AssertOk(t, err, "Failed to create vcsim")
	defer s.Destroy()
	// SETTING UP MOCK
	// Real probe that will be used by mock probe when possible
	vchub := setupVCHub(vcURL, sm, orchConfig, logger)
	vcp := vcprobe.NewVCProbe(vchub.vcReadCh, vchub.State)
	mockProbe := mock.NewProbeMock(vcp)
	vchub.probe = mockProbe
	mockProbe.Start()
	AssertEventually(t, func() (bool, interface{}) {
		if !mockProbe.IsSessionReady() {
			return false, fmt.Errorf("Session not ready")
		}
		return true, nil
	}, "Session is not Ready", "1s", "10s")
	defer vchub.Destroy()

	// Add DC
	dc, err := s.AddDC(defaultTestParams.TestDCName)
	AssertOk(t, err, "failed dc create")
	// Add it using vcHub so mockProbe gets the needed info ???
	// This will also create PenDVS
	logger.Infof("Creating PenDC for %s\n", dc.Obj.Reference().Value)
	_, err = vchub.NewPenDC(defaultTestParams.TestDCName, dc.Obj.Self.Value)
	// Add DVS
	dvsName := createDVSName(defaultTestParams.TestDCName)
	dvs, ok := dc.GetDVS(dvsName)
	if !ok {
		logger.Info("GetDVS Failed")
		os.Exit(1)
	}
	Assert(t, ok, "failed dvs create")

	orchInfo1 := []*network.OrchestratorInfo{
		{
			Name:      orchConfig.Name,
			Namespace: defaultTestParams.TestDCName,
		},
	}
	// Create one PG for vmkNic
	pgConfigSpec := []types.DVPortgroupConfigSpec{
		types.DVPortgroupConfigSpec{
			Name:     createPGName("vMotion_PG"),
			NumPorts: 8,
			DefaultPortConfig: &types.VMwareDVSPortSetting{
				Vlan: &types.VmwareDistributedVirtualSwitchPvlanSpec{
					PvlanId: int32(100),
				},
			},
		},
	}

	smmock.CreateNetwork(sm, "default", "vMotion_PG", "11.1.1.0/24", "11.1.1.1", 500, nil, orchInfo1)
	// Add PG to mockProbe (this is weird, this should be part of sim)
	// vcHub should provide this function ??
	mockProbe.AddPenPG(defaultTestParams.TestDCName, dvsName, &pgConfigSpec[0])
	pg, err := mockProbe.GetPenPG(defaultTestParams.TestDCName, createPGName("vMotion_PG"))
	AssertOk(t, err, "failed to add portgroup")

	logger.Infof("===== Pre-Sync Initial config =====")
	vchub.sync()
	// Create Host1 (pensando)
	penHost1, err := dc.AddHost("host1")
	AssertOk(t, err, "failed to add Host to DC")
	err = dvs.AddHost(penHost1)
	AssertOk(t, err, "failed to add Host to DVS")

	// Create Host2 (pensndo)
	penHost2, err := dc.AddHost("host2")
	AssertOk(t, err, "failed to add Host to DC")
	err = dvs.AddHost(penHost2)
	AssertOk(t, err, "failed to add Host to DVS")

	pNicMac := net.HardwareAddr{}
	pNicMac = append(pNicMac, globals.PensandoOUI[0])
	pNicMac = append(pNicMac, globals.PensandoOUI[1])
	pNicMac = append(pNicMac, globals.PensandoOUI[2])
	pNicMac = append(pNicMac, 0xbb)
	pNicMac = append(pNicMac, 0x00)
	pNicMac = append(pNicMac, 0x00)
	// Make it Pensando host
	err = penHost1.AddNic("vmnic0", conv.MacString(pNicMac))
	AssertOk(t, err, "failed to add pNic")

	pNicMac2 := net.HardwareAddr{}
	pNicMac2 = append(pNicMac2, globals.PensandoOUI[0])
	pNicMac2 = append(pNicMac2, globals.PensandoOUI[1])
	pNicMac2 = append(pNicMac2, globals.PensandoOUI[2])
	pNicMac2 = append(pNicMac2, 0xcc)
	pNicMac2 = append(pNicMac2, 0x00)
	pNicMac2 = append(pNicMac2, 0x00)
	// Make it Pensando host
	err = penHost2.AddNic("vmnic0", conv.MacString(pNicMac2))
	AssertOk(t, err, "failed to add pNic")

	penHost1.ClearVmkNics()
	penHost2.ClearVmkNics()

	// Create a VM on host1
	vm1, err := dc.AddVM("vm1", "host1", []sim.VNIC{
		sim.VNIC{
			MacAddress:   "aaaa.bbbb.ddde",
			PortgroupKey: pg.Reference().Value,
			PortKey:      "11",
		},
	})
	AssertOk(t, err, "Failed to create vm1")

	logger.Infof("===== Sync Initial config =====")
	vchub.sync()

	// Verify that VM is on host1 by getting workload for the vm

	testWorkloads := map[string]string{} // [workload] = host

	vmName := createVMWorkloadName(orchInfo1[0].Name, dc.Obj.Self.Value, vm1.Reference().Value)
	host1Name := createHostName(orchInfo1[0].Name, dc.Obj.Self.Value, penHost1.Obj.Self.Value)
	testWorkloads[vmName] = host1Name

	// Add Validations
	// Check that workload for the host with its vmknics as EPs is created
	verifyVMWorkloads := func(testWls map[string]string, errMsg string) {
		AssertEventually(t, func() (bool, interface{}) {
			opts := api.ListWatchOptions{}
			wls, err := sm.Controller().Workload().List(context.Background(), &opts)
			if err != nil {
				logger.Infof("Cannot get workloads - err %s", err)
				return false, nil
			}
			if len(wls) != len(testWls) {
				logger.Infof("Got %d workloads, Expected %d", len(wls), len(testWls))
				return false, nil
			}
			for testVMName := range testWls {
				meta := &api.ObjectMeta{
					Name:      testVMName,
					Tenant:    "default",
					Namespace: "default",
				}
				_, err := sm.Controller().Workload().Find(meta)
				if err != nil {
					return false, nil
				}
			}
			return true, nil
		}, errMsg, "1s", "10s")
	}
	verifyVMWorkloads(testWorkloads, "VM not found on host1")

	// move VM to host2 - build the event and all event receiver directly ??
	logger.Infof("===== Move VM to host2 =====")
	err = dc.UpdateVMHost(vm1, "host2")
	AssertOk(t, err, "VM host update failed")
	// Verify that VM is on host2 by getting workload for the vm
	vchub.Wg.Add(1)
	go vchub.startEventsListener()
	vmEvent := types.VmBeingRelocatedEvent{
		VmRelocateSpecEvent: types.VmRelocateSpecEvent{
			VmEvent: types.VmEvent{
				Event: types.Event{
					Key: 1,
					Vm: &types.VmEventArgument{
						Vm: vm1.Reference(),
					},
				},
			},
		},
		DestHost: types.HostEventArgument{
			Host: penHost2.Obj.Reference(),
		},
	}
	vchub.probe.TestReceiveEvents(dc.Obj.Reference(), []types.BaseEvent{&vmEvent})
	host2Name := createHostName(orchInfo1[0].Name, dc.Obj.Self.Value, penHost2.Obj.Self.Value)
	testWorkloads[vmName] = host2Name
	verifyVMWorkloads(testWorkloads, "VM not found on host2")

	// VcSim BUG:
	// In vcsim there is some problem in setting up the pnics for host.. all hosts are getting
	// affected as pnics are added to any one host. That makes host3 also pensdo host.
	// for now remove pensando nic from host to run this test further

	// Create Host3 (non-pensndo)
	host3, err := dc.AddHost("host3")
	AssertOk(t, err, "failed to add Host to DC")
	err = dvs.AddHost(host3)
	AssertOk(t, err, "failed to add Host to DVS")

	pNicMac3 := net.HardwareAddr{}
	pNicMac3 = append(pNicMac3, 0x00)
	pNicMac3 = append(pNicMac3, 0x01)
	pNicMac3 = append(pNicMac3, 0x02)
	pNicMac3 = append(pNicMac3, 0xcc)
	pNicMac3 = append(pNicMac3, 0x00)
	pNicMac3 = append(pNicMac3, 0x00)

	penHost1.ClearNics()
	penHost2.ClearNics()
	host3.ClearNics()

	err = host3.AddNic("vmnic0", conv.MacString(pNicMac3))
	AssertOk(t, err, "failed to add pNic")

	// move VM to host3, non-pensando host
	logger.Infof("===== Move VM to host3 =====")
	err = dc.UpdateVMHost(vm1, "host3")
	AssertOk(t, err, "VM host update failed")
	vmEvent = types.VmBeingRelocatedEvent{
		VmRelocateSpecEvent: types.VmRelocateSpecEvent{
			VmEvent: types.VmEvent{
				Event: types.Event{
					Key: 2,
					Vm: &types.VmEventArgument{
						Vm: vm1.Reference(),
					},
				},
			},
		},
		DestHost: types.HostEventArgument{
			Host: host3.Obj.Reference(),
		},
	}
	vchub.probe.TestReceiveEvents(dc.Obj.Reference(), []types.BaseEvent{&vmEvent})
	delete(testWorkloads, vmName)
	vchub.sync()
	verifyVMWorkloads(testWorkloads, "VM not removed")
}