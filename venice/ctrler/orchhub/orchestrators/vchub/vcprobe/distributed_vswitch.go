package vcprobe

import (
	"errors"

	"github.com/vmware/govmomi/find"
	"github.com/vmware/govmomi/object"
	"github.com/vmware/govmomi/vim25/mo"
	"github.com/vmware/govmomi/vim25/types"
)

// PenDVSPortSettings represents a group of DVS port settings
// The key of this map represents the key of port on a DVS
// The value of this map represents the new setting of this port
type PenDVSPortSettings map[string]types.BaseVmwareDistributedVirtualSwitchVlanSpec

// AddPenDVS adds a new PenDVS to the given vcprobe instance
func (v *VCProbe) AddPenDVS(dcName string, dvsCreateSpec *types.DVSCreateSpec, retry int) error {
	fn := func() (interface{}, error) {
		dvsName := dvsCreateSpec.ConfigSpec.GetDVSConfigSpec().Name
		client := v.GetClientWithRLock()
		finder := v.CreateFinder(client)
		defer v.ReleaseClientsRLock()

		// Check if it exists first
		var task *object.Task
		var err error
		if dvsObj, err := v.getPenDVS(dcName, dvsName, finder); err == nil {
			var dvs mo.DistributedVirtualSwitch
			err = dvsObj.Properties(v.ClientCtx, dvsObj.Reference(), []string{"config"}, &dvs)
			if err != nil {
				v.Log.Errorf("Failed at getting dvs properties, err: %s", err)
				return nil, err
			}

			dvsCreateSpec.ConfigSpec.GetDVSConfigSpec().ConfigVersion = dvs.Config.GetDVSConfigInfo().ConfigVersion
			v.Log.Infof("DC: %s - DVS already exists, reconfiguring...", dcName)
			task, err = dvsObj.Reconfigure(v.ClientCtx, dvsCreateSpec.ConfigSpec.GetDVSConfigSpec())
		} else {
			dc, err := finder.Datacenter(v.ClientCtx, dcName)
			if err != nil {
				v.Log.Errorf("Datacenter: %s doesn't exist, err: %s", dcName, err)
				return nil, err
			}

			finder.SetDatacenter(dc)

			folders, err := dc.Folders(v.ClientCtx)
			if err != nil {
				return nil, err
			}

			task, err = folders.NetworkFolder.CreateDVS(v.ClientCtx, *dvsCreateSpec)
		}

		if err != nil {
			v.Log.Errorf("Failed at creating dvs: %s, err: %s", dvsName, err)
			return nil, err
		}

		_, err = task.WaitForResult(v.ClientCtx, nil)
		if err != nil {
			v.Log.Errorf("Failed at waiting results of creating dvs: %s, err: %s", dvsName, err)
			return nil, err
		}

		return nil, nil
	}
	_, err := v.withRetry(fn, retry)
	return err
}

// GetPenDVS returns the DVS if it exists or an error
func (v *VCProbe) GetPenDVS(dcName, dvsName string, retry int) (*object.DistributedVirtualSwitch, error) {
	fn := func() (interface{}, error) {
		client := v.GetClientWithRLock()
		finder := v.CreateFinder(client)
		defer v.ReleaseClientsRLock()
		return v.getPenDVS(dcName, dvsName, finder)
	}
	ret, err := v.withRetry(fn, retry)
	if ret == nil {
		return nil, err
	}
	return ret.(*object.DistributedVirtualSwitch), err
}

func (v *VCProbe) getPenDVS(dcName, dvsName string, finder *find.Finder) (*object.DistributedVirtualSwitch, error) {
	dc, err := finder.Datacenter(v.ClientCtx, dcName)
	if err != nil {
		v.Log.Errorf("Datacenter: %s doesn't exist, err: %s", dcName, err)
		return nil, err
	}

	finder.SetDatacenter(dc)

	net, err := finder.Network(v.ClientCtx, dvsName)
	if err != nil {
		v.Log.Errorf("Failed at finding network: %s, err: %s", dvsName, err)
		return nil, err
	}

	objDvs, ok := net.(*object.DistributedVirtualSwitch)
	if !ok {
		v.Log.Errorf("Failed at getting DVS object")
		return nil, errors.New("Failed at getting DVS object")
	}
	return objDvs, nil
}

// RemovePenDVS removes the DVS
func (v *VCProbe) RemovePenDVS(dcName, dvsName string, retry int) error {
	fn := func() (interface{}, error) {
		client := v.GetClientWithRLock()
		finder := v.CreateFinder(client)
		defer v.ReleaseClientsRLock()

		objDvs, err := v.getPenDVS(dcName, dvsName, finder)
		if err != nil {
			return nil, err
		}

		task, err := objDvs.Destroy(v.ClientCtx)
		if err != nil {
			v.Log.Errorf("Failed at destroying DVS: %s from datacenter: %s, err: %s", dvsName, dcName, err)
			return nil, err
		}

		err = task.Wait(v.ClientCtx)
		if err != nil {
			v.Log.Errorf("Failed at destroying DVS: %s from datacenter: %s, err: %s", dvsName, dcName, err)
			return nil, err
		}

		return nil, nil
	}
	_, err := v.withRetry(fn, retry)
	return err
}

// GetPenDVSPorts returns the port configuration of the given dvs
func (v *VCProbe) GetPenDVSPorts(dcName, dvsName string, criteria *types.DistributedVirtualSwitchPortCriteria, retry int) ([]types.DistributedVirtualPort, error) {
	fn := func() (interface{}, error) {
		client := v.GetClientWithRLock()
		finder := v.CreateFinder(client)
		defer v.ReleaseClientsRLock()
		return v.getPenDVSPorts(dcName, dvsName, criteria, finder)
	}
	ret, err := v.withRetry(fn, retry)
	if ret == nil {
		return nil, err
	}
	return ret.([]types.DistributedVirtualPort), err
}

func (v *VCProbe) getPenDVSPorts(dcName, dvsName string, criteria *types.DistributedVirtualSwitchPortCriteria, finder *find.Finder) ([]types.DistributedVirtualPort, error) {

	dvsObj, err := v.getPenDVS(dcName, dvsName, finder)
	if err != nil {
		return nil, err
	}
	ret, err := dvsObj.FetchDVPorts(v.ClientCtx, criteria)
	if err != nil {
		v.Log.Errorf("Can't find ports, err: %s", err)
		return nil, err
	}
	return ret, nil
}

// UpdateDVSPortsVlan updates the port settings
func (v *VCProbe) UpdateDVSPortsVlan(dcName, dvsName string, portsSetting PenDVSPortSettings, retry int) error {
	v.Log.Debugf("UpdateDVSPortsVlan called with %s %s %v", dcName, dvsName, portsSetting)

	fn := func() (interface{}, error) {
		numPorts := len(portsSetting)
		if numPorts == 0 {
			// Nothing to do
			return nil, nil
		}

		portKeys := make([]string, numPorts)
		portSpecs := make([]types.DVPortConfigSpec, numPorts)

		client := v.GetClientWithRLock()
		finder := v.CreateFinder(client)
		defer v.ReleaseClientsRLock()

		dvsObj, err := v.getPenDVS(dcName, dvsName, finder)
		if err != nil {
			return nil, err
		}

		for k := range portsSetting {
			portKeys = append(portKeys, k)
		}

		criteria := &types.DistributedVirtualSwitchPortCriteria{
			PortKey: portKeys,
		}

		ports, err := v.getPenDVSPorts(dcName, dvsName, criteria, finder)
		if err != nil {
			return nil, err
		}

		for i := 0; i < numPorts; i++ {
			portSpecs[i].ConfigVersion = ports[i].Config.ConfigVersion
			portSpecs[i].Key = ports[i].Key
			portSpecs[i].Operation = string("edit")
			portSpecs[i].Scope = ports[i].Config.Scope
			setting, ok := portSpecs[i].Setting.(*types.VMwareDVSPortSetting)
			if !ok {
				setting = &types.VMwareDVSPortSetting{}
			}
			setting.Vlan = portsSetting[ports[i].Key]
			portSpecs[i].Setting = setting
		}

		task, err := dvsObj.ReconfigureDVPort(v.ClientCtx, portSpecs)
		if err != nil {
			v.Log.Errorf("Failed at reconfig DVS ports, err: %s", err)
			return nil, err
		}

		_, err = task.WaitForResult(v.ClientCtx, nil)
		if err != nil {
			v.Log.Errorf("Failed at modifying DVS ports, err: %s", err)
			return nil, err
		}

		return nil, nil
	}
	_, err := v.withRetry(fn, retry)
	return err
}
