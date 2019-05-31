package state

import (
	"context"
	"errors"
	"fmt"
	"net"
	"time"

	"github.com/pensando/sw/nic/agent/netagent/state/types"

	"github.com/mdlayher/arp"
	"github.com/vishvananda/netlink"

	"github.com/pensando/sw/api"
	"github.com/pensando/sw/nic/agent/protos/netproto"
	"github.com/pensando/sw/venice/utils/log"
)

const (
	inbandIntf           = "bond0"
	oobIntf              = "oob_mnic0"
	refreshDuration      = time.Duration(time.Minute * 1)
	arpResolutionTimeout = time.Duration(time.Millisecond * 500)
)

// CreateLateralNetAgentObjects creates the backing objects to ensure that telemetry works.
// It runs an arp client in the background to ensure that appropriate destEP is created.
// TODO clean this up. Currently this is in NetAgent as there is no control plane which does this.
func (na *Nagent) CreateLateralNetAgentObjects(mgmtIP, destIP string, tunnelOp bool) error {
	log.Infof("Creating Lateral NetAgent objects. MgmtIP: %v DestIP: %v TunnelOp: %v", mgmtIP, destIP, tunnelOp)
	var epIfType, epIf string
	var objectName = fmt.Sprintf("_internal-%s", destIP)

	if na.isCollectorKnown(objectName, mgmtIP, destIP, tunnelOp) {
		log.Infof("The collector %s is known.", destIP)
		return nil
	}

	var dMAC string
	epIP := destIP
	mgmtLink := getMgmtLink(mgmtIP)
	if mgmtLink == nil {
		log.Errorf("Failed to get the mgmt interface")
		return nil
	}
	log.Infof("Management Link: %v", mgmtLink.Attrs().Name)
	mgmtIntf, _ := net.InterfaceByName(mgmtLink.Attrs().Name)
	log.Infof("Management Inft: %v", mgmtIntf.Name)

	client, err := arp.Dial(mgmtIntf)
	if err != nil {
		log.Errorf("Failed to initiate an ARP client. Err: %v", err)
		return err
	}
	na.ArpClient = client

	log.Infof("Resolving for: %s", destIP)
	routes, err := netlink.RouteGet(net.ParseIP(destIP))
	if err != nil || len(routes) == 0 {
		log.Errorf("No routes found for the dest IP %s. Err: %v", destIP, err)
		err = fmt.Errorf("no routes found for the dest IP %s. Err: %v", destIP, err)
	}

	// Pick the first route. Dest IP in not in the local subnet. Use GW IP as the destIP for ARP'ing
	if routes[0].Gw != nil {
		destIP = routes[0].Gw.String()
	}

	// Set the correct dIP
	dIP := net.ParseIP(destIP)

	log.Infof("Starting refresh loop for %s", dIP.String())

	//// Cache the handler for outer done. This needs to be called during the object deletes
	refreshCtx, done := context.WithCancel(context.Background())
	na.ArpCache.DoneCache[dIP.String()] = done

	go na.startRefreshLoop(refreshCtx, dIP)

	time.Sleep(time.Second * 3)

	for i := 0; i < 3; i++ {
		d, ok := na.ArpCache.Cache.Load(destIP)
		if !ok {
			continue
		}
		dMAC = d.(string)
	}

	// Bail out if the arp resolution fails.
	if len(dMAC) == 0 {
		log.Errorf("Failed to find resolve MAC for %s", destIP)
		return fmt.Errorf("failed to find resolve MAC for %s", destIP)
	}

	nw := &netproto.Network{
		TypeMeta: api.TypeMeta{Kind: "Network"},
		ObjectMeta: api.ObjectMeta{
			Tenant:    "default",
			Namespace: "default",
			Name:      objectName,
		},
		Spec: netproto.NetworkSpec{
			VlanID: types.UntaggedVLAN, // Untagged
		},
	}

	if mgmtLink.Attrs().Name == types.OOBManagementInterface {
		epIf = types.ManagementUplink
		epIfType = "uplink"
	}

	ep := &netproto.Endpoint{
		TypeMeta: api.TypeMeta{Kind: "Endpoint"},
		ObjectMeta: api.ObjectMeta{
			Tenant:    "default",
			Namespace: "default",
			Name:      objectName,
		},
		Spec: netproto.EndpointSpec{
			NetworkName:   objectName,
			NodeUUID:      "REMOTE",
			IPv4Address:   fmt.Sprintf("%s/32", epIP),
			MacAddress:    dMAC,
			InterfaceType: epIfType,
			Interface:     epIf,
		},
	}

	tun := &netproto.Tunnel{
		TypeMeta: api.TypeMeta{Kind: "Tunnel"},
		ObjectMeta: api.ObjectMeta{
			Tenant:    "default",
			Namespace: "default",
			Name:      objectName,
		},
		Spec: netproto.TunnelSpec{
			Type:        "GRE",
			AdminStatus: "UP",
			Src:         mgmtIP,
			Dst:         epIP,
		},
	}

	log.Infof("Creating internal network %v", nw)

	if err := na.CreateNetwork(nw); err != nil {
		log.Errorf("Failed to create an untagged network. Err: %v", err)
		return err
	}

	log.Infof("Creating internal endpoint %v", ep)
	if err := na.CreateEndpoint(ep); err != nil {
		log.Errorf("Failed to create TEP EP. Err: %v", err)
		return err
	}

	if tunnelOp {
		log.Infof("Creating internal tunnel %v", tun)
		if err := na.CreateTunnel(tun); err != nil {
			log.Errorf("Failed to create tunnel. Err: %v", err)
			return err
		}
	}

	return nil
}

// DeleteLateralNetAgentObjects deletes the backing objects to ensure that telemetry works.
// TODO clean this up. Currently this is in NetAgent as there is no control plane which does this.
func (na *Nagent) DeleteLateralNetAgentObjects(mgmtIP, destIP string, tunnelOp bool) error {
	log.Infof("Deleting Lateral NetAgent objects. MgmtIP: %v DestIP: %v TunnelOp: %v", mgmtIP, destIP, tunnelOp)
	var tunnelKnown bool
	var objectName = fmt.Sprintf("_internal-%s", destIP)

	// This will keep it symmetric to CreateLateralNetAgentObjects. This is valid only on real NAPLES
	mgmtLink := getMgmtLink(mgmtIP)
	if mgmtLink == nil {
		log.Errorf("Failed to get the mgmt interface")
		return nil
	}

	for _, t := range na.ListTunnel() {
		if t.Name == objectName {
			tunnelKnown = true
		}
	}

	if tunnelOp && tunnelKnown {
		// Attempt deletion and error out only if the tunnel is known
		err := na.DeleteTunnel("default", "default", objectName)
		if err != nil && err != errors.New("tunnel not found") {
			log.Errorf("Failed to delete the tunnel %v. Err: %v", objectName, err)
			return fmt.Errorf("failed to delete the tunnel %v. Err: %v", objectName, err)
		}
	}

	for _, ep := range na.ListEndpoint() {
		if ep.Spec.IPv4Address == fmt.Sprintf("%s/32", destIP) && ep.Name == objectName {
			// Lateral objects and not created by Venice
			if ep.Spec.NetworkName == objectName {
				log.Infof("Deleting Endpoint: %v", objectName)
				if err := na.DeleteEndpoint("default", "default", objectName); err != nil {
					log.Errorf("Failed to delete the endpoint %v. Err: %v", objectName, err)
				}

				log.Infof("Deleting Network: %v", objectName)
				if err := na.DeleteNetwork("default", "default", objectName); err != nil {
					log.Errorf("Failed to delete the network %v. Err: %v", objectName, err)
				}
			}

		}
	}

	// Stop the existing ARP Refresh loop if the lateral objects are successfully deleted
	cancel, ok := na.ArpCache.DoneCache[destIP]
	if !ok {
		log.Error("Failed to get the delete handler for ARP Loop refresh")
		return errors.New("failed to get the delete handler for ARP Loop refresh")
	}
	cancel()

	return nil
}
func getMgmtLink(mgmtIP string) (mgmtLink netlink.Link) {
	links, err := netlink.LinkList()
	if err != nil {
		log.Errorf("Failed to list the available links. Err: %v", err)
		return
	}

	for _, l := range links {
		addrs, _ := netlink.AddrList(l, netlink.FAMILY_V4)
		for _, a := range addrs {
			if a.IP.String() == mgmtIP {
				mgmtLink = l
				return
			}
		}
	}
	return
}

func (na *Nagent) startRefreshLoop(refreshCtx context.Context, IP net.IP) {
	log.Infof("Starting ARP refresh loop for %v", IP)

	defer func() {
		if err := recover(); err != nil {
			log.Errorf("Refresh control loop exited. Err: %v", err)
			log.Infof("Restarting refresh loop...")
			go na.startRefreshLoop(refreshCtx, IP)
		}
	}()

	ticker := time.NewTicker(refreshDuration)
	go func(refreshCtx context.Context, IP net.IP) {
		mac := na.resolveWithDeadline(refreshCtx, IP)
		log.Infof("Resolved MAC 1st Tick: %s", mac)
		for {
			select {
			case <-ticker.C:
				mac := na.resolveWithDeadline(refreshCtx, IP)
				fmt.Println("Resolved Mac: ", mac)
			case <-refreshCtx.Done():
				fmt.Println("Cancelling ARP refresh loop for ", IP)
				return
			}
		}
	}(refreshCtx, IP)
}

func (na *Nagent) resolveWithDeadline(ctx context.Context, IP net.IP) string {
	resolveCtx, cancel := context.WithCancel(ctx)
	defer cancel()
	arpChan := make(chan string, 1)

	go func(arpChan chan string, IP net.IP) {
		fmt.Println("Resolving IP. ", IP)
		mac, err := na.ArpClient.Resolve(IP)
		if err != nil {
			log.Errorf("Failed to resolve MAC for %v", err)
		}
		log.Infof("FOUND MAC: %v", mac)
		// Populate the ARPCache.
		na.ArpCache.Cache.LoadOrStore(IP.String(), mac.String())
		arpChan <- mac.String()
	}(arpChan, IP)

	select {
	case <-time.After(arpResolutionTimeout):
		cancel()
		return resolveCtx.Err().Error()
	case mac := <-arpChan:
		return mac
	}
}

func (na *Nagent) isCollectorKnown(lateralObjName, mgmtIP, destIP string, createTunnel bool) bool {
	// Find EP
	log.Infof("Testing for known collector with Name: %v MgmtIP: %v DestIP: %v, TunnelOp: %v", lateralObjName, mgmtIP, destIP, createTunnel)
	var existingEPName string
	var tunnelKnown bool

	for _, ep := range na.ListEndpoint() {
		epIP, _, _ := net.ParseCIDR(ep.Spec.IPv4Address)
		if epIP.String() == destIP {
			existingEPName = ep.Name
		}
	}

	for _, t := range na.ListTunnel() {
		if t.Spec.Dst == destIP {
			tunnelKnown = true
		}
	}

	tun := &netproto.Tunnel{
		TypeMeta: api.TypeMeta{Kind: "Tunnel"},
		ObjectMeta: api.ObjectMeta{
			Tenant:    "default",
			Namespace: "default",
			Name:      lateralObjName,
		},
		Spec: netproto.TunnelSpec{
			Type:        "GRE",
			AdminStatus: "UP",
			Src:         mgmtIP,
			Dst:         destIP,
		},
	}

	switch existingEPName {
	default:
		// NetAgent Laterally created ep
		if !tunnelKnown && createTunnel {
			// Create the backing tunnel
			log.Infof("NetAgent created lateral EP, but tunnel missing. Creating it instead. Tunnel: %v", tun)
			if err := na.CreateTunnel(tun); err != nil {
				log.Errorf("Failed to create tunnel. Err: %v", err)
				return false
			}
		}
		return true
	case "":
		// Mark the collector unknown
		return false
	}
}
