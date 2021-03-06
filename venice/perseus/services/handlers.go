package services

import (
	"context"
	"net"
	"sync"

	"github.com/pensando/sw/api/generated/apiclient"
	cmd "github.com/pensando/sw/api/generated/cluster"
	"github.com/pensando/sw/api/generated/network"
	pdstypes "github.com/pensando/sw/nic/apollo/agent/gen/pds"
	"github.com/pensando/sw/venice/globals"
	"github.com/pensando/sw/venice/perseus/env"
	"github.com/pensando/sw/venice/perseus/types"
	"github.com/pensando/sw/venice/utils/kvstore"
	"github.com/pensando/sw/venice/utils/log"
)

type snicT struct {
	name   string
	phase  string
	ip     string
	uuid   string
	pushed bool
}

// ServiceHandlers holds all the servies to be supported
type ServiceHandlers struct {
	sync.Mutex
	updated        bool
	pegasusURL     string
	cfgWatcherSvc  types.CfgWatcherService
	pegasusClient  pdstypes.BGPSvcClient
	ifClient       pdstypes.IfSvcClient
	routeSvc       pdstypes.CPRouteSvcClient
	apiclient      apiclient.Services
	snicMap        map[string]*snicT
	naplesTemplate *network.BGPNeighbor
}

// NewServiceHandlers returns a Service Handler
func NewServiceHandlers() *ServiceHandlers {
	m := ServiceHandlers{
		cfgWatcherSvc: env.CfgWatcherService,
	}
	m.cfgWatcherSvc.SetSmartNICEventHandler(m.HandleSmartNICEvent)
	m.cfgWatcherSvc.SetNetworkInterfaceEventHandler(m.HandleNetworkInterfaceEvent)
	m.cfgWatcherSvc.SetRoutingConfigEventHandler(m.HandleRoutingConfigEvent)
	m.cfgWatcherSvc.SetNodeConfigEventHandler(m.HandleNodeConfigEvent)
	m.snicMap = make(map[string]*snicT)
	m.pegasusURL = globals.Localhost + ":" + globals.PegasusGRPCPort
	m.connectToPegasus()
	m.setupLBIf()
	return &m
}

// CfgAsn is the ASN for the RR config
var CfgAsn uint32

func (m *ServiceHandlers) configurePeers() {
	for _, nic := range m.snicMap {
		m.configurePeer(nic, false)
	}
}

func (m *ServiceHandlers) configurePeer(nic *snicT, deleteOp bool) {
	log.Infof("configurePeer: delete [%v] - snic %+v CfgAsn %d", deleteOp, nic, CfgAsn)
	if nic.phase != "admitted" || nic.ip == "" || nic.uuid == "" || CfgAsn == 0 {
		// wait for all information to be right
		// might have to handle case where nic was admitted previously
		// TODO
		log.Infof("ignoring configure peer")
		return
	}
	keepalive, holdtime := cache.getTimers()
	uid := cache.getUUID()
	ctx := context.TODO()
	if deleteOp != true {
		// call grpc api to configure ms
		peerReq := pdstypes.BGPPeerRequest{}
		peer := pdstypes.BGPPeerSpec{
			Id:           uid,
			PeerAddr:     ip2PDSType(nic.ip),
			LocalAddr:    ip2PDSType(""),
			RemoteASN:    CfgAsn,
			State:        pdstypes.AdminState_ADMIN_STATE_ENABLE,
			SendComm:     true,
			SendExtComm:  true,
			ConnectRetry: 5,
			KeepAlive:    keepalive,
			HoldTime:     holdtime,
			RRClient:     pdstypes.BGPPeerRRClient_BGP_PEER_RR_CLIENT,
		}
		if m.naplesTemplate != nil {
			peer.Password = []byte(m.naplesTemplate.Password)
			peer.TTL = m.naplesTemplate.MultiHop
			if m.naplesTemplate.Shutdown {
				peer.State = pdstypes.AdminState_ADMIN_STATE_DISABLE
			} else {
				peer.State = pdstypes.AdminState_ADMIN_STATE_ENABLE
			}
		}
		log.Infof("Add create peer [%+v]", peer)
		peerReq.Request = append(peerReq.Request, &peer)
		if nic.pushed {
			presp, err := m.pegasusClient.BGPPeerUpdate(ctx, &peerReq)
			if err != nil || presp.ApiStatus != pdstypes.ApiStatus_API_STATUS_OK {
				log.Errorf("Peer update Request returned (%v)[%+v]", err, presp)
			}
		} else {
			presp, err := m.pegasusClient.BGPPeerCreate(ctx, &peerReq)
			if err != nil || presp.ApiStatus != pdstypes.ApiStatus_API_STATUS_OK {
				log.Errorf("Peer create Request returned (%v)[%+v]", err, presp)
			}
			nic.pushed = true
		}

	} else {
		if nic.pushed {
			unkLocal := &pdstypes.IPAddress{
				Af: pdstypes.IPAF_IP_AF_INET,
			}
			peerDReq := pdstypes.BGPPeerDeleteRequest{}
			peer := pdstypes.BGPPeerKeyHandle{
				IdOrKey: &pdstypes.BGPPeerKeyHandle_Key{Key: &pdstypes.BGPPeerKey{PeerAddr: ip2PDSType(nic.ip), LocalAddr: unkLocal}},
			}
			log.Infof("Add Delete peer [%+v]", peer)
			peerDReq.Request = append(peerDReq.Request, &peer)
			presp, err := m.pegasusClient.BGPPeerDelete(ctx, &peerDReq)
			if err != nil || presp.ApiStatus != pdstypes.ApiStatus_API_STATUS_OK {
				log.Errorf("Peer delete Request returned (%v)[%+v]", err, presp)
			} else {
				log.Infof("Peer delete request succeeded (%s)[%v]", err, presp.ApiStatus)
			}

			nic.pushed = false
		}
	}

	if !deleteOp {
		peerAfReq := pdstypes.BGPPeerAfRequest{
			Request: []*pdstypes.BGPPeerAfSpec{
				{
					Id:          uid,
					PeerAddr:    ip2PDSType(nic.ip),
					LocalAddr:   ip2PDSType(""),
					NexthopSelf: false,
					DefaultOrig: false,
					Afi:         pdstypes.BGPAfi_BGP_AFI_L2VPN,
					Safi:        pdstypes.BGPSafi_BGP_SAFI_EVPN,
				},
			},
		}
		presp, err := m.pegasusClient.BGPPeerAfCreate(ctx, &peerAfReq)
		if err != nil || presp.ApiStatus != pdstypes.ApiStatus_API_STATUS_OK {
			log.Errorf("Peer AF create Request returned (%v)[%+v]", err, presp)
		}
		nic.pushed = true
	}

	m.updated = true
}

func (m *ServiceHandlers) handleCreateUpdateSmartNICObject(evtNIC *cmd.DistributedServiceCard) {
	snic, ok := m.snicMap[evtNIC.ObjectMeta.Name]
	if !ok {
		snic = &snicT{}
	}
	snic.name = evtNIC.ObjectMeta.Name
	snic.phase = evtNIC.Status.AdmissionPhase
	snic.uuid = evtNIC.UUID
	snic.pushed = false
	m.snicMap[evtNIC.ObjectMeta.Name] = snic
	m.configurePeer(snic, false)
}

func (m *ServiceHandlers) handleDeleteSmartNICObject(evtNIC *cmd.DistributedServiceCard) {
}

func (m *ServiceHandlers) handleCreateUpdateNetIntfObject(evtIntf *network.NetworkInterface) {
	snic, ok := m.snicMap[evtIntf.Status.DSC]
	if !ok {
		snic = &snicT{}
	}
	snic.name = evtIntf.Status.DSC
	oldip := snic.ip
	if evtIntf.Spec.IPConfig != nil {
		ip, _, err := net.ParseCIDR(evtIntf.Spec.IPConfig.IPAddress)
		if err != nil {
			log.Errorf("could not parse IP CIDR (%s)", err)
			return
		}
		if ip.IsUnspecified() {
			log.Infof("IP is unspecified [%v]", ip.String())
			snic.ip = ""
		} else {
			log.Infof("IP is [%v]", ip.String())
			snic.ip = ip.String()
		}
	} else {
		snic.ip = ""
	}
	if oldip != "" && oldip != snic.ip {
		ip := snic.ip
		snic.ip = oldip
		m.configurePeer(snic, true)
		snic.ip = ip
	}
	m.snicMap[evtIntf.Status.DSC] = snic
	m.configurePeer(snic, false)
}

func (m *ServiceHandlers) handleBGPConfigChange() {
	for _, nic := range m.snicMap {
		m.configurePeer(nic, false)
	}
}

func (m *ServiceHandlers) handleBGPConfigDelete() {
	for _, nic := range m.snicMap {
		m.configurePeer(nic, true)
	}
}

func (m *ServiceHandlers) handleDeleteNetIntfObject(evtIntf *network.NetworkInterface) {
	snic := m.snicMap[evtIntf.Status.DSC]
	if snic.pushed == true {
		m.configurePeer(snic, true)
	}
}

func isEvtTypeCreatedupdated(et kvstore.WatchEventType) bool {
	if et == "Created" || et == "Updated" {
		return true
	}
	return false
}

func isEvtTypeDeleted(et kvstore.WatchEventType) bool {
	if et == "Deleted" {
		return true
	}
	return false
}

// HandleSmartNICEvent handles SmartNIC updates
func (m *ServiceHandlers) HandleSmartNICEvent(et kvstore.WatchEventType, evtNIC *cmd.DistributedServiceCard) {
	log.Infof("HandleSmartNICEvent called: NIC: %+v event type: %v\n", *evtNIC, et)
	if isEvtTypeCreatedupdated(et) {
		m.handleCreateUpdateSmartNICObject(evtNIC)
	} else if isEvtTypeDeleted(et) {
		m.handleDeleteSmartNICObject(evtNIC)
	} else {
		log.Fatalf("unexpected event received")
	}
	return
}

// HandleNetworkInterfaceEvent handles SmartNIC updates
func (m *ServiceHandlers) HandleNetworkInterfaceEvent(et kvstore.WatchEventType, evtIntf *network.NetworkInterface) {
	log.Infof("HandleNetworkInterfaceEvent called: Intf: %+v event type: %v\n", *evtIntf, et)
	if isEvtTypeCreatedupdated(et) {
		m.handleCreateUpdateNetIntfObject(evtIntf)
	} else if isEvtTypeDeleted(et) {
		m.handleDeleteNetIntfObject(evtIntf)
	} else {
		log.Fatalf("unexpected event received")
	}
	return
}
