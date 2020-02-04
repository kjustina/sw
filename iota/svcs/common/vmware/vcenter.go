package vmware

import (
	"context"
	"fmt"
	"net/url"

	"github.com/pkg/errors"
	"github.com/vmware/govmomi/find"
	"github.com/vmware/govmomi/object"
	"github.com/vmware/govmomi/vim25/mo"
	"github.com/vmware/govmomi/vim25/types"
)

//Vcenter instance
type Vcenter struct {
	Entity
	datacenters map[string]*DataCenter
}

//DataCenter instance
type DataCenter struct {
	name     string
	vc       *Vcenter
	ref      *object.Datacenter
	clusters map[string]*Cluster
}

//Cluster instance
type Cluster struct {
	dc    *DataCenter
	ref   *object.ClusterComputeResource
	hosts map[string]*VHost
}

// NewVcenter returns a new *Vcenter instance
func NewVcenter(ctx context.Context, name, username, password, license string) (*Vcenter, error) {
	if name == "" || username == "" || password == "" {
		return nil, errors.New("fields were blank during NewHost")
	}

	url, err := url.Parse(fmt.Sprintf("https://%s:%s@%s/sdk", username, password, name))
	if err != nil {
		return nil, errors.Wrap(err, "credentials are invalid")
	}

	vc := Vcenter{
		Entity: Entity{
			Name:    name,
			URL:     url,
			License: license,
		},
		datacenters: make(map[string]*DataCenter),
	}

	if err := vc.Reinit(ctx); err != nil {
		return nil, errors.Wrapf(err, "Connection failed")
	}
	go vc.monitorSession()

	return &vc, nil
}

//CreateDataCenter Creates a datacenter
func (vc *Vcenter) CreateDataCenter(name string) (*DataCenter, error) {
	vc.getClientWithRLock()
	defer vc.releaseClientRLock()
	f := object.NewRootFolder(vc.Client().Client)

	dc, err := f.CreateDatacenter(vc.Ctx(), name)
	if err != nil {
		return nil, err
	}

	finder := vc.Finder()
	dc, err = finder.Datacenter(vc.Ctx(), name)
	if err != nil {
		return nil, err
	}

	finder.SetDatacenter(dc)
	dcr := &DataCenter{
		name: name,
		ref:  dc, vc: vc,
		clusters: make(map[string]*Cluster)}

	vc.datacenters[name] = dcr

	return dcr, nil
}

//DisconnectHost disconnects hosts from vcenter
func (vc *Vcenter) DisconnectHost(ip string) error {
	vc.getClientWithRLock()
	defer vc.releaseClientRLock()
	finder := find.NewFinder(vc.Client().Client, false)

	dcList, err := finder.DatacenterList(vc.Ctx(), "*")
	if err != nil {
		return err
	}

	for _, dc := range dcList {
		finder.SetDatacenter(dc)
		hosts, err := finder.HostSystemList(vc.Ctx(), "*")
		if err == nil {
			for _, host := range hosts {
				if host.Name() == ip {
					var h mo.HostSystem
					err := host.Properties(vc.Ctx(), host.Reference(), []string{"parent"}, &h)
					if err != nil {
						return err
					}
					remove := host.Destroy
					if h.Parent.Type == "ComputeResource" {
						// Standalone host.  From the docs:
						// "Invoking remove on a HostSystem of standalone type throws a NotSupported fault.
						//  A standalone HostSystem can be removeed only by invoking remove on its parent ComputeResource."
						remove = object.NewComputeResource(host.Client(), *h.Parent).Destroy
					}

					task, err := host.Disconnect(vc.Ctx())
					if err != nil {
						return err
					}
					_, err = task.WaitForResult(vc.Ctx(), nil)
					if err != nil {
						return err
					}

					task, err = remove(vc.Ctx())
					if err != nil {
						return err
					}
					return nil
				}
			}
		}
	}

	//Did not fine the host, so return ok
	return nil
}

//SetupDataCenter setups existing dc
func (vc *Vcenter) SetupDataCenter(name string) (*DataCenter, error) {
	vc.getClientWithRLock()
	defer vc.releaseClientRLock()

	vc.ConnCtx.finder = find.NewFinder(vc.Client().Client, false)
	finder := vc.ConnCtx.finder
	dc, err := finder.Datacenter(vc.Ctx(), name)
	if err != nil {
		return nil, err
	}

	vc.ConnCtx.finder.SetDatacenter(dc)
	dcr := &DataCenter{ref: dc, vc: vc,
		clusters: make(map[string]*Cluster)}

	vc.datacenters[name] = dcr

	clusters, err := finder.ClusterComputeResourceList(vc.Ctx(), "*")
	if err == nil {
		for _, cluster := range clusters {
			cl := &Cluster{dc: dcr, ref: cluster, hosts: make(map[string]*VHost)}
			dcr.clusters[cluster.Name()] = cl
		}
	}

	for _, cluster := range dcr.clusters {
		hosts, err := finder.HostSystemList(vc.Ctx(), cluster.ref.InventoryPath+"/*")
		if err == nil {
			for _, host := range hosts {
				cluster.hosts[host.Name()] = NewVHost(vc.Ctx(), host, vc.ConnCtx.pc, finder)
			}
		}
	}

	return dcr, nil
}

//DestroyDataCenter destroys datacenter
func (vc *Vcenter) DestroyDataCenter(name string) error {
	vc.getClientWithRLock()
	defer vc.releaseClientRLock()

	dc, ok := vc.datacenters[name]
	if !ok {
		//Try to find and delete any
		finder := find.NewFinder(vc.Client().Client, false)
		dc, err := finder.Datacenter(vc.Ctx(), name)
		if err == nil {
			task, err := dc.Destroy(vc.Ctx())
			if err == nil {
				return task.Wait(vc.Ctx())
			}
			return err
		}
		return fmt.Errorf("datacenter %v not found for delete", name)
	}

	delete(vc.datacenters, name)
	if dc.ref != nil {
		task, err := dc.ref.Destroy(dc.vc.Ctx())
		dc.ref = nil
		_, err = task.WaitForResult(dc.vc.Ctx(), nil)
		if err != nil {
			return err
		}

		return err
	}

	return nil
}

//CreateCluster Creates a cluster
func (dc *DataCenter) CreateCluster(name string) (*Cluster, error) {
	dc.getClientWithRLock()
	defer dc.releaseClientRLock()

	err := dc.setUpFinder()
	if err != nil {
		return nil, errors.Wrapf(err, "Error setup datacenter")
	}
	folders, err := dc.ref.Folders(dc.vc.Ctx())
	if err != nil {
		return nil, err
	}

	_, err = folders.HostFolder.CreateCluster(dc.vc.Ctx(),
		name, types.ClusterConfigSpecEx{})
	if err != nil {
		return nil, err
	}

	//Read again for cluster ref
	clusters, err := dc.Finder().ClusterComputeResourceList(dc.vc.Ctx(), "*")
	if err == nil {
		for _, cl := range clusters {
			if cl.Name() == name {
				cl := &Cluster{dc: dc, ref: cl, hosts: make(map[string]*VHost)}
				dc.clusters[name] = cl
				return cl, nil
			}
		}
	}

	return nil, errors.New("Cluster create failed")
}

func (dc *DataCenter) Finder() *find.Finder {
	return dc.vc.Finder()
}

func (dc *DataCenter) Ctx() context.Context {
	return dc.vc.Ctx()
}

//DestroyCluster destroys cluster
func (dc *DataCenter) DestroyCluster(name string) error {
	dc.getClientWithRLock()
	defer dc.releaseClientRLock()

	err := dc.setUpFinder()
	if err != nil {
		return errors.Wrapf(err, "Error setup datacenter")
	}
	cluster, ok := dc.clusters[name]
	if !ok {
		return fmt.Errorf("Cluster %v not found for delete", name)
	}

	delete(dc.clusters, name)
	if cluster.ref != nil {
		task, err := cluster.ref.Destroy(cluster.dc.vc.Ctx())
		if err == nil {
			task.Wait(cluster.dc.vc.Ctx())
		}
		cluster.ref = nil
		return err
	}

	return nil
}

//AddHost adds host to cluster
func (cl *Cluster) AddHost(ip, username, password string) error {
	cl.dc.getClientWithRLock()
	defer cl.dc.releaseClientRLock()

	err := cl.dc.setUpFinder()
	if err != nil {
		return errors.Wrapf(err, "Error setup datacenter")
	}
	spec := types.HostConnectSpec{HostName: ip,
		Password: password, UserName: username, Force: true}

	task, err := cl.ref.AddHost(cl.dc.vc.Ctx(), spec, true, &cl.dc.vc.Entity.License, nil)

	if err != nil {
		return err
	}

	_, err = task.WaitForResult(cl.dc.vc.Ctx(), nil)
	if err != nil {
		return err
	}

	hosts, err := cl.ref.Hosts(cl.dc.vc.Ctx())
	if err != nil || len(hosts) == 0 {
		return fmt.Errorf("Host  %v not found to add", ip)
	}

	var hostRef *object.HostSystem
	for _, host := range hosts {
		if host.Name() == ip {
			hostRef = host
			break
		}
	}

	if hostRef == nil {
		return fmt.Errorf("Host %v not found to add", ip)
	}

	vhost := NewVHost(cl.dc.vc.Ctx(), hostRef, cl.dc.vc.ConnCtx.pc, cl.dc.Finder())
	cl.hosts[ip] = vhost
	return nil
}

//DeleteHost adds host to cluster
func (cl *Cluster) DeleteHost(ip string) error {
	cl.dc.getClientWithRLock()
	defer cl.dc.releaseClientRLock()

	err := cl.dc.setUpFinder()
	if err != nil {
		return errors.Wrapf(err, "Error setup datacenter")
	}
	host, err := cl.dc.findHost(cl.ref.Name(), ip)
	if err != nil {
		return nil
	}
	remove := host.Host.hs.Destroy

	/*
		if host.Host.hs. == "ComputeResource" {
			// Standalone host.  From the docs:
			// "Invoking remove on a HostSystem of standalone type throws a NotSupported fault.
			//  A standalone HostSystem can be removeed only by invoking remove on its parent ComputeResource."
			remove = object.NewComputeResource(host.Client(), *h.Parent).Destroy
		}*/

	task, err := host.hs.Disconnect(cl.dc.vc.Ctx())
	if err != nil {
		return err
	}
	_, err = task.WaitForResult(cl.dc.vc.Ctx(), nil)
	if err != nil {
		return err
	}

	task, err = remove(cl.dc.vc.Ctx())
	if err != nil {
		return err
	}

	_, err = task.WaitForResult(cl.dc.vc.Ctx(), nil)
	if err != nil {
		return err
	}

	delete(cl.hosts, ip)

	return nil
}

//Datastore new datastore
func (dc *DataCenter) Datastore(cluster, hostName string) (*Datastore, error) {
	var err error

	dc.getClientWithRLock()
	defer dc.releaseClientRLock()
	err = dc.setUpFinder()
	if err != nil {
		return nil, errors.Wrapf(err, "Error setup datacenter")
	}

	dsList, err := dc.Finder().DatastoreList(dc.Ctx(), "*")
	if err != nil {
		return nil, err
	}

	hs, err := dc.findHost(cluster, hostName)
	if err != nil {
		return nil, err
	}

	for _, ds := range dsList {
		hosts, err := ds.AttachedHosts(dc.Ctx())
		if err != nil {
			return nil, err
		}

		for _, h := range hosts {
			if h.Reference() == hs.hs.Reference() {
				return &Datastore{
					datastore:  ds,
					datacenter: dc.ref,
					Entity:     &dc.vc.Entity,
				}, nil
			}
		}

	}

	return nil, fmt.Errorf("Host %v did not find a datastore", hostName)
}

func (dc *DataCenter) findHost(clusterName string, hostname string) (*VHost, error) {
	dc.getClientWithRLock()
	defer dc.releaseClientRLock()
	cluster, ok := dc.clusters[clusterName]
	if !ok {
		return nil, fmt.Errorf("Cluster %v not found to deploy", clusterName)
	}

	if vhost, ok := cluster.hosts[hostname]; ok {
		//vhost.context = dc.vc.context
		vhost.Entity.ConnCtx = dc.vc.ConnCtx
		return vhost, nil
	}

	//Try to find

	var hostRef *object.HostSystem
	hosts, err := dc.Finder().HostSystemList(dc.vc.Ctx(), cluster.ref.InventoryPath+"/*")
	if err == nil {
		for _, host := range hosts {
			if host.Name() == hostname {
				hostRef = host
				break
			}
		}
	} else {
		return nil, fmt.Errorf("No hosts in the cluster for %v %v %v", clusterName, err.Error(), cluster.ref.InventoryPath+"/*")
	}

	if hostRef == nil {
		return nil, fmt.Errorf("Could not find host  %v in cluster %v", hostname, clusterName)
	}

	vhost := NewVHost(dc.vc.Ctx(), hostRef, dc.vc.ConnCtx.pc, dc.Finder())
	cluster.hosts[hostname] = vhost

	return vhost, nil
}

//findVM  Find VM on a host on a datacenter
func (dc *DataCenter) findVM(hostRef *object.HostSystem, vmName string) (*VM, error) {
	dc.getClientWithRLock()
	defer dc.releaseClientRLock()
	vms, err := dc.Finder().VirtualMachineList(dc.vc.Ctx(), hostRef.InventoryPath+"/*")
	if err != nil {
		return nil, fmt.Errorf("Did not find VM  %v", vmName)
	}

	for _, vm := range vms {
		if vm.Name() == vmName {
			return dc.vc.makeVM(vmName, vm), nil
		}
	}

	return nil, fmt.Errorf("Did not find VM  %v", vmName)
}

func (dc *DataCenter) setUpFinder() error {

	finder := find.NewFinder(dc.vc.Client().Client, false)
	dcr, err := finder.Datacenter(dc.vc.Ctx(), dc.ref.Name())
	if err != nil {
		return err
	}
	dc.vc.ConnCtx.finder = finder
	//dc.Finder().SetDatacenter(dcr)
	finder.SetDatacenter(dcr)
	return nil

}

//DeployVM deploys vm on data center
func (dc *DataCenter) DeployVM(clusterName string, hostname string,
	name string, ncpus uint, memory uint, networks []string, ovfDir string) (*VMInfo, error) {

	dc.getClientWithRLock()
	defer dc.releaseClientRLock()
	err := dc.setUpFinder()
	if err != nil {
		return nil, errors.Wrapf(err, "Error setting up datacenter")
	}

	hostRef, err := dc.findHost(clusterName, hostname)
	if err != nil {
		return nil, err
	}

	ds, err := dc.Datastore(clusterName, hostname)
	if err != nil {
		return nil, errors.Wrapf(err, "Data store find failed")
	}

	return dc.vc.DeployVMOnDataStore(ds, hostRef.hs, name, ncpus, memory, networks, ovfDir)
}

//DeleteHost deletes hosts from cluster
func (dc *DataCenter) DeleteHost(cluster string, ip string) error {
	dc.getClientWithRLock()
	defer dc.releaseClientRLock()

	err := dc.setUpFinder()
	if err != nil {
		return errors.Wrapf(err, "Error setup datacenter")
	}
	host, err := dc.findHost(cluster, ip)
	if err != nil {
		return nil
	}
	remove := host.Host.hs.Destroy

	/*
		if host.Host.hs. == "ComputeResource" {
			// Standalone host.  From the docs:
			// "Invoking remove on a HostSystem of standalone type throws a NotSupported fault.
			//  A standalone HostSystem can be removeed only by invoking remove on its parent ComputeResource."
			remove = object.NewComputeResource(host.Client(), *h.Parent).Destroy
		}*/

	task, err := host.hs.Disconnect(dc.vc.Ctx())
	if err != nil {
		return err
	}
	_, err = task.WaitForResult(dc.vc.Ctx(), nil)
	if err != nil {
		return err
	}

	task, err = remove(dc.vc.Ctx())
	if err != nil {
		return err
	}

	_, err = task.WaitForResult(dc.vc.Ctx(), nil)
	if err != nil {
		return err
	}

	return nil
}

//AddVswitch add a vswitch to host
func (dc *DataCenter) AddVswitch(cluster, host string, vspec VswitchSpec) error {

	dc.getClientWithRLock()
	defer dc.releaseClientRLock()
	err := dc.setUpFinder()
	if err != nil {
		return errors.Wrapf(err, "Error setting up datacenter")
	}
	vhost, err := dc.findHost(cluster, host)
	if err != nil {
		return errors.Wrap(err, "Error finding host")
	}

	return vhost.AddVswitch(vspec)
}

//AddKernelNic add a vswitch to host
func (dc *DataCenter) AddKernelNic(cluster, host string, pgName string, enableVmotion bool) error {

	dc.getClientWithRLock()
	defer dc.releaseClientRLock()
	err := dc.setUpFinder()
	if err != nil {
		return errors.Wrapf(err, "Error setting up datacenter")
	}
	vhost, err := dc.findHost(cluster, host)
	if err != nil {
		return errors.Wrap(err, "Error finding host")
	}

	return vhost.AddKernelNic(cluster, host, pgName, enableVmotion)
}

//RemoveKernelNic add a vswitch to host
func (dc *DataCenter) RemoveKernelNic(cluster, host string, pgName string) error {

	dc.getClientWithRLock()
	defer dc.releaseClientRLock()
	err := dc.setUpFinder()
	if err != nil {
		return errors.Wrapf(err, "Error setting up datacenter")
	}
	vhost, err := dc.findHost(cluster, host)
	if err != nil {
		return errors.Wrap(err, "Error finding host")
	}

	return vhost.RemoveKernelNic(cluster, host, pgName)
}

//AddNetworks add a vswitch to host
func (dc *DataCenter) AddNetworks(cluster, host string, specs []NWSpec, vsSpec VswitchSpec) error {

	dc.getClientWithRLock()
	defer dc.releaseClientRLock()
	err := dc.setUpFinder()
	if err != nil {
		return errors.Wrapf(err, "Error setting up datacenter")
	}
	vhost, err := dc.findHost(cluster, host)
	if err != nil {
		return errors.Wrap(err, "Error finding host")
	}

	return vhost.AddNetworks(specs, vsSpec)
}

//RemoveNetworks removes networks
func (dc *DataCenter) RemoveNetworks(cluster, host string, specs []NWSpec) error {

	dc.getClientWithRLock()
	defer dc.releaseClientRLock()
	err := dc.setUpFinder()
	if err != nil {
		return errors.Wrapf(err, "Error setting up datacenter")
	}
	vhost, err := dc.findHost(cluster, host)
	if err != nil {
		return errors.Wrap(err, "Error finding host")
	}

	return vhost.RemoveNetworks(specs)
}

//ListVswitches lists all vswitces
func (dc *DataCenter) ListVswitches(cluster, host string) ([]VswitchSpec, error) {

	dc.getClientWithRLock()
	defer dc.releaseClientRLock()
	err := dc.setUpFinder()
	if err != nil {
		return nil, errors.Wrapf(err, "Error setup datacenter")
	}
	vhost, err := dc.findHost(cluster, host)
	if err != nil {
		return nil, errors.Wrap(err, "Error finding host")
	}

	return vhost.ListVswitchs()
}

type DVSwitchHostSpec struct {
	Name  string
	Pnics []string
}

type DvsPortGroup struct {
	Name         string
	Ports        int32
	Type         string
	VlanOverride bool
	Vlan         int32
}

// VswitchSpec specifies a virtual switch
type DVSwitchSpec struct {
	Name       string
	Cluster    string
	Hosts      []DVSwitchHostSpec
	MaxPorts   int32
	Pvlans     []DvsPvlanPair
	PortGroups []DvsPortGroup
}

type DvsPvlanPair struct {
	Primary   int32
	Secondary int32
	Type      string
}

func (dc *DataCenter) findDvs(name string) (*object.DistributedVirtualSwitch, error) {
	dc.getClientWithRLock()
	defer dc.releaseClientRLock()
	net, err := dc.Finder().Network(dc.vc.Ctx(), name)
	if err != nil {
		return nil, err
	}

	dvs, ok := net.(*object.DistributedVirtualSwitch)
	if !ok {
		return nil, errors.New("cannot find dvs")
	}

	return dvs, nil
}

// AddHostsToDvs add hosts to dvs
func (dc *DataCenter) AddHostsToDvs(vspec DVSwitchSpec) error {

	dc.getClientWithRLock()
	defer dc.releaseClientRLock()
	dvs, err := dc.findDvs(vspec.Name)
	if err != nil {
		return errors.Wrap(err, "Dvs not found")
	}

	if len(vspec.Hosts) == 0 {
		fmt.Printf("no hosts added 1 \n")
		return nil
	}
	var s mo.DistributedVirtualSwitch
	err = dvs.Properties(dc.Ctx(), dvs.Reference(), []string{"config"}, &s)
	if err != nil {
		return err
	}

	existing := make(map[string]bool)
	// TODO: host.pnic.info command
	for _, member := range s.Config.GetDVSConfigInfo().Host {
		existing[member.Config.Host.Value] = true
	}

	config := &types.DVSConfigSpec{
		ConfigVersion: s.Config.GetDVSConfigInfo().ConfigVersion,
	}
	backing := new(types.DistributedVirtualSwitchHostMemberPnicBacking)

	for _, host := range vspec.Hosts {

		hostRef, err := dc.findHost(vspec.Cluster, host.Name)
		if err != nil {
			return err
		}

		ref := hostRef.Host.hs.Reference()
		if existing[ref.Value] {
			//fmt.Fprintf(os.Stderr, "%s is already a member of %s\n", host.InventoryPath, dvs.InventoryPath)
			fmt.Printf("no already added \n")
			continue
		}

		hostConfig := types.DistributedVirtualSwitchHostMemberConfigSpec{
			Host:      hostRef.Host.hs.Reference(),
			Operation: string(types.ConfigSpecOperationAdd),
		}
		for _, pnic := range host.Pnics {
			backing.PnicSpec = append(backing.PnicSpec,
				types.DistributedVirtualSwitchHostMemberPnicSpec{PnicDevice: pnic})
		}
		hostConfig.Backing = backing
		config.Host = append(config.Host, hostConfig)
	}

	if len(config.Host) == 0 {
		return nil
	}

	task, err := dvs.Reconfigure(dc.Ctx(), config)
	if err != nil {
		return err
	}

	_, err = task.WaitForResult(dc.Ctx())
	return err
}

// DisconnectAllHostFromDvs add hosts to dvs
func (dc *DataCenter) DisconnectAllHostFromDvs(vspec DVSwitchSpec) error {

	dc.getClientWithRLock()
	defer dc.releaseClientRLock()
	dvs, err := dc.findDvs(vspec.Name)
	if err != nil {
		//DVs not found return
		return nil
	}

	var s mo.DistributedVirtualSwitch
	err = dvs.Properties(dc.Ctx(), dvs.Reference(), []string{"config"}, &s)
	if err != nil {
		return err
	}

	existing := make(map[string]bool)
	// TODO: host.pnic.info command
	for _, member := range s.Config.GetDVSConfigInfo().Host {
		existing[member.Config.Host.Value] = true
	}

	config := &types.DVSConfigSpec{
		ConfigVersion: s.Config.GetDVSConfigInfo().ConfigVersion,
	}

	for value, exist := range existing {

		if exist {
			hostConfig := types.DistributedVirtualSwitchHostMemberConfigSpec{
				Host:      types.ManagedObjectReference{Value: value, Type: "HostSystem"},
				Operation: string(types.ConfigSpecOperationRemove),
			}
			config.Host = append(config.Host, hostConfig)
		}

	}

	if len(config.Host) == 0 {
		return nil
	}

	task, err := dvs.Reconfigure(dc.Ctx(), config)
	if err != nil {
		return err
	}

	_, err = task.WaitForResult(dc.Ctx())
	return err
}

// AddPvlanPairsToDvs adds pvlan to dvs
func (dc *DataCenter) AddPvlanPairsToDvs(name string, pairs []DvsPvlanPair) error {

	dvs, err := dc.findDvs(name)
	if err != nil {
		return errors.Wrap(err, "Dvs not found")
	}

	var s mo.DistributedVirtualSwitch
	err = dvs.Properties(dc.Ctx(), dvs.Reference(), []string{"config"}, &s)
	if err != nil {
		return err
	}

	config := &types.VMwareDVSConfigSpec{
		PvlanConfigSpec: []types.VMwareDVSPvlanConfigSpec{},
		DVSConfigSpec: types.DVSConfigSpec{
			ConfigVersion: s.Config.GetDVSConfigInfo().ConfigVersion,
		},
	}

	for _, pair := range pairs {
		config.PvlanConfigSpec = append(config.PvlanConfigSpec,
			types.VMwareDVSPvlanConfigSpec{
				PvlanEntry: types.VMwareDVSPvlanMapEntry{
					PrimaryVlanId:   pair.Primary,
					PvlanType:       pair.Type,
					SecondaryVlanId: pair.Secondary,
				},
				Operation: string(types.ConfigSpecOperationAdd),
			})
	}
	task, err := dvs.Reconfigure(dc.Ctx(), config)
	if err != nil {
		return err
	}

	_, err = task.WaitForResult(dc.Ctx())
	return err
}

//VlanType pvlan/trunk
type VlanType int

const (
	//DvsVlanID ID
	DvsVlanID VlanType = iota
	// DvsVlanTrunk trunk
	DvsVlanTrunk
	//DvsPvlan trunk
	DvsPvlan
)

//DvsMatchCriteria
type DvsPGMatchCriteria struct {
	VlanID int32
	Type   VlanType
	Uplink bool
}

//FindDvsPortGroup find dvs matching criteria
func (dc *DataCenter) FindDvsPortGroup(name string, mcriteria DvsPGMatchCriteria) (string, error) {

	err := dc.setUpFinder()
	if err != nil {
		return "", errors.Wrapf(err, "Error setup datacenter")
	}

	dvs, err := dc.findDvs(name)
	if err != nil {
		return "", errors.Wrap(err, "Dvs not found")
	}

	getNwName := func(uuid, key string) (string, error) {
		netList, err := dc.Finder().NetworkList(dc.vc.Ctx(), "*")
		if err != nil {
			return "", errors.Wrap(err, "Failed Fetch networks")
		}

		for _, net := range netList {
			nwRef, err := net.EthernetCardBackingInfo(dc.Ctx())
			if err != nil {
				continue
			}
			switch nw := nwRef.(type) {
			case *types.VirtualEthernetCardDistributedVirtualPortBackingInfo:
				if nw.Port.SwitchUuid == uuid && nw.Port.PortgroupKey == key {
					return net.GetInventoryPath(), nil
				}
			}

		}
		return "", errors.Wrap(err, "Failed Fetch networks")
	}
	// Set base search criteria
	criteria := types.DistributedVirtualSwitchPortCriteria{
		UplinkPort: &mcriteria.Uplink,

		//Connected: types.NewBool(true),

		//Active:     types.NewBool(cmd.active),
		//UplinkPort: types.NewBool(cmd.uplinkPort),
		//Inside:     types.NewBool(cmd.inside),
	}
	res, err := dvs.FetchDVPorts(dc.vc.Ctx(), &criteria)
	if err != nil {
		return "", err
	}

	for _, port := range res {
		var vlanID int32
		setting := port.Config.Setting.(*types.VMwareDVSPortSetting)

		switch vlan := setting.Vlan.(type) {
		case *types.VmwareDistributedVirtualSwitchVlanIdSpec:
			if mcriteria.Type == DvsVlanID && vlan.VlanId == mcriteria.VlanID {
				return getNwName(port.DvsUuid, port.PortgroupKey)
			}
			vlanID = vlan.VlanId
		case *types.VmwareDistributedVirtualSwitchTrunkVlanSpec:
			if mcriteria.Type == DvsVlanTrunk {
				for _, vlan := range vlan.VlanId {
					if vlan.Start >= mcriteria.VlanID && vlan.End <= mcriteria.VlanID {
						return getNwName(port.DvsUuid, port.PortgroupKey)
					}
				}
			}
		case *types.VmwareDistributedVirtualSwitchPvlanSpec:
			vlanID = vlan.PvlanId
			if mcriteria.Type == DvsVlanTrunk && vlanID == mcriteria.VlanID {
				return getNwName(port.DvsUuid, port.PortgroupKey)
			}
		}

	}

	return "", errors.New("Portgroup not found")
}

// AddPortGroupToDvs adds port group to dvs
func (dc *DataCenter) AddPortGroupToDvs(name string, pairs []DvsPortGroup) error {

	if len(pairs) == 0 {
		return nil
	}

	dvs, err := dc.findDvs(name)
	if err != nil {
		return errors.Wrap(err, "Dvs not found")
	}

	var s mo.DistributedVirtualSwitch
	err = dvs.Properties(dc.Ctx(), dvs.Reference(), []string{"config"}, &s)
	if err != nil {
		return err
	}

	pgSpec := []types.DVPortgroupConfigSpec{}
	for _, pair := range pairs {

		pgSpec = append(pgSpec, types.DVPortgroupConfigSpec{
			Name:     pair.Name,
			NumPorts: pair.Ports,
			Type:     pair.Type,
			Policy: &types.VMwareDVSPortgroupPolicy{
				DVPortgroupPolicy: types.DVPortgroupPolicy{
					//BlockOverrideAllowed:               true,
					//ShapingOverrideAllowed:             false,
					VendorConfigOverrideAllowed: false,
					LivePortMovingAllowed:       true,
					PortConfigResetAtDisconnect: true,
					//NetworkResourcePoolOverrideAllowed: types.NewBool(false),
					//TrafficFilterOverrideAllowed:       types.NewBool(false),
				},
				VlanOverrideAllowed: pair.VlanOverride,
				//UplinkTeamingOverrideAllowed:  false,
				//SecurityPolicyOverrideAllowed: false,
			},
			DefaultPortConfig: &types.VMwareDVSPortSetting{
				Vlan: &types.VmwareDistributedVirtualSwitchVlanIdSpec{
					VlanId: pair.Vlan,
				},
			},
		})

	}
	task, err := dvs.AddPortgroup(dc.Ctx(), pgSpec)
	if err != nil {
		return err
	}
	_, err = task.WaitForResult(dc.Ctx())
	return err
}

// RemoveHostsFromDvs remove hosts from dvs
func (dc *DataCenter) RemoveHostsFromDvs(vspec DVSwitchSpec) error {

	if len(vspec.Hosts) == 0 {
		return nil
	}

	dvs, err := dc.findDvs(vspec.Name)
	if err != nil {
		return errors.Wrap(err, "Dvs not found")
	}

	var s mo.DistributedVirtualSwitch
	err = dvs.Properties(dc.Ctx(), dvs.Reference(), []string{"config"}, &s)
	if err != nil {
		return err
	}

	existing := make(map[string]bool)
	for _, member := range s.Config.GetDVSConfigInfo().Host {
		existing[member.Config.Host.Value] = true
	}

	config := &types.DVSConfigSpec{
		ConfigVersion: s.Config.GetDVSConfigInfo().ConfigVersion,
	}

	for _, host := range vspec.Hosts {
		hostRef, err := dc.findHost(vspec.Cluster, host.Name)
		if err != nil {
			return err
		}
		ref := hostRef.Host.hs.Reference()
		if !existing[ref.Value] {
			continue
		}
		hostConfig := types.DistributedVirtualSwitchHostMemberConfigSpec{
			Host:      hostRef.Host.hs.Reference(),
			Operation: string(types.ConfigSpecOperationRemove),
		}
		config.Host = append(config.Host, hostConfig)
	}

	if len(config.Host) == 0 {
		return nil
	}

	task, err := dvs.Reconfigure(dc.Ctx(), config)
	if err != nil {
		return err
	}

	_, err = task.WaitForResult(dc.Ctx())
	return err
}

// AddDvs adds vswitch to target host
func (dc *DataCenter) AddDvs(vspec DVSwitchSpec) error {

	_, err := dc.findDvs(vspec.Name)
	if err != nil {

		pvlanConfigSpec := []types.VMwareDVSPvlanConfigSpec{}
		for _, pair := range vspec.Pvlans {
			pvlanConfigSpec = append(pvlanConfigSpec,
				types.VMwareDVSPvlanConfigSpec{
					PvlanEntry: types.VMwareDVSPvlanMapEntry{
						PrimaryVlanId:   pair.Primary,
						PvlanType:       pair.Type,
						SecondaryVlanId: pair.Secondary,
					},
					Operation: "add",
				})
		}

		spec := types.DVSCreateSpec{
			ConfigSpec: &types.VMwareDVSConfigSpec{
				DVSConfigSpec: types.DVSConfigSpec{
					Name:               vspec.Name,
					NumStandalonePorts: vspec.MaxPorts,
				},
				PvlanConfigSpec: pvlanConfigSpec,
			},
		}

		folders, _ := dc.ref.Folders(dc.Ctx())

		dtask, err := folders.NetworkFolder.CreateDVS(dc.Ctx(), spec)
		if err != nil {
			return err
		}

		_, err = dtask.WaitForResult(dc.Ctx(), nil)
		if err != nil {
			return err
		}
	}

	err = dc.AddPortGroupToDvs(vspec.Name, vspec.PortGroups)
	if err != nil {
		return err
	}
	return dc.AddHostsToDvs(vspec)
}

//DeleteAllHosts delete all hosts from datacenter
func (dc *DataCenter) DeleteAllHosts() error {

	hosts, err := dc.Finder().HostSystemList(dc.vc.Ctx(), "*")
	if err == nil {
		for _, host := range hosts {
			remove := host.Destroy

			task, err := host.Disconnect(dc.vc.Ctx())
			if err != nil {
				return err
			}
			_, err = task.WaitForResult(dc.vc.Ctx(), nil)
			if err != nil {
				return err
			}
			task, err = remove(dc.vc.Ctx())
			if err != nil {
				return err
			}

			_, err = task.WaitForResult(dc.vc.Ctx(), nil)
			if err != nil {
				return err
			}

		}
	}
	return nil
}

//DeleteAllVMs delete all VMS from datacenter
func (dc *DataCenter) DeleteAllVMs() error {

	vms, err := dc.Finder().VirtualMachineList(dc.vc.Ctx(), "*")
	if err == nil {
		for _, vm := range vms {
			task, err := vm.PowerOff(dc.Ctx())
			if err == nil {
				task.WaitForResult(dc.Ctx())
			}
			task, err = vm.Destroy(dc.Ctx())
			if err == nil {
				task.WaitForResult(dc.Ctx())
			}
		}
	}
	return nil
}

func (dc *DataCenter) getDatastoreRefForHost(hostName string) (*types.ManagedObjectReference, error) {

	dc.getClientWithRLock()
	defer dc.releaseClientRLock()

	var hosts []mo.HostSystem
	cView, err := dc.vc.ConnCtx.viewMgr.CreateContainerView(dc.vc.Ctx(), dc.ref.Reference(), []string{}, true)
	if err != nil {
		return nil, err
	}
	err = cView.Retrieve(dc.vc.Ctx(), []string{string("HostSystem")}, []string{"config", "name", "datastore"}, &hosts)
	if err != nil {
		return nil, err
	}

	for _, host := range hosts {
		if host.Name == hostName {
			for _, ds := range host.Datastore {
				ref := ds.Reference()
				return &ref, nil
			}

		}
	}

	return nil, fmt.Errorf("Host storage not found %v", hostName)

}

//LiveMigrate migrates live VM on data center
func (dc *DataCenter) LiveMigrate(vmName, srcHostName, dstHostName, clusterName string) error {

	dc.getClientWithRLock()
	defer dc.releaseClientRLock()
	err := dc.setUpFinder()
	if err != nil {
		return errors.Wrapf(err, "Error setting up datacenter")
	}

	srcHostRef, err := dc.findHost(clusterName, srcHostName)
	if err != nil {
		return err
	}

	dstHostRef, err := dc.findHost(clusterName, dstHostName)
	if err != nil {
		return err
	}

	vmInst, err := dc.findVM(srcHostRef.Host.hs, vmName)
	if err != nil {
		return err
	}

	dstHostDatastoreRef, err := dc.getDatastoreRefForHost(dstHostName)
	if err != nil {
		return err
	}

	return vmInst.Migrate(&dstHostRef.Host, dstHostDatastoreRef)
}

func (dc *DataCenter) BootVM(name string) (*VMInfo, error) {

	dc.getClientWithRLock()
	defer dc.releaseClientRLock()

	return dc.vc.BootVM(name)
}

func (dc *DataCenter) DestoryVM(name string) error {

	dc.getClientWithRLock()
	defer dc.releaseClientRLock()

	return dc.vc.DestoryVM(name)
}

func (dc *DataCenter) NewVM(name string) (*VM, error) {
	dc.getClientWithRLock()
	defer dc.releaseClientRLock()

	return dc.vc.NewVM(name)
}

func (dc *DataCenter) VMExists(name string) bool {
	dc.getClientWithRLock()
	defer dc.releaseClientRLock()

	return dc.vc.VMExists(name)
}