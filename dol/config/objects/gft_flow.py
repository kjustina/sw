#! /usr/bin/python3

import infra.common.defs        as defs
import infra.config.base        as base
import config.resmgr            as resmgr

import config.hal.api           as halapi
import config.hal.defs          as haldefs

import config.objects.session   as session

from infra.common.glopts        import GlobalOptions
from infra.common.logging       import cfglogger
from config.store               import Store

class GftFlowObject(base.ConfigObjectBase):
    def __init__(self):
        super().__init__()
        self.Clone(Store.templates.Get('GFT_FLOW'))
        self.id = resmgr.GftFlowIdAllocator.get()
        self.GID("GFT_FLOW_%d" % self.id)
        return

    def Init(self, flow):
        self.flow = flow
        self.Show()
        return

    def PrepareHALRequestSpec(self, req_spec):
        req_spec.key_or_handle.flow_entry_id = self.id
        req_spec.exact_match_profile.profile_id = 3

        req_spec.add_in_activated_state = False
        req_spec.rdma_flow = False
        req_spec.redirect_to_vport_ingress_queue = False
        req_spec.redirect_to_vport_egress_queue = False
        req_spec.redirect_to_vport_ingress_queue_if_ttl_is_one = False
        req_spec.redirect_to_vport_egress_queue_if_ttl_is_one = False
        req_spec.copy_all_packets = False
        req_spec.copy_first_packet = False
        req_spec.copy_when_tcp_flag_set = False
        req_spec.custom_action_present = False
        req_spec.meta_action_before_transposition = False
        req_spec.copy_after_tcp_fin_flag_set = False
        req_spec.copy_after_tcp_rst_flag_set = False

        req_spec.table_id = 0
        req_spec.vport_id = 0
        req_spec.redirect_vport_id = 0
        req_spec.ttl_one_redirect_vport_id = 0

        exm = req_spec.exact_matches.add()
        exm.headers.ethernet_header = True
        exm.headers.ethernet_header = True
        exm.headers.ipv4_header = True
        exm.headers.udp_header = True

        exm.match_fields.dst_mac_addr = True
        exm.match_fields.src_mac_addr = True
        #exm.match_fields.eth_type = True
        exm.match_fields.customer_vlan_id = True
        exm.match_fields.src_ip_addr = True
        exm.match_fields.dst_ip_addr = True
        exm.match_fields.ip_protocol = True
        exm.match_fields.src_port = True
        exm.match_fields.dst_port = True

        exm.eth_fields.dst_mac_addr = self.flow.dmac.getnum()
        exm.eth_fields.src_mac_addr = self.flow.smac.getnum()
        #exm.eth_fields.eth_type = self.flow.ethertype
        exm.eth_fields.customer_vlan_id = self.flow.GetSrcSegmentVlanid()
        exm.src_ip_addr.ip_af = haldefs.common.IP_AF_INET
        exm.src_ip_addr.v4_addr = self.flow.sip.getnum()
        exm.dst_ip_addr.ip_af = haldefs.common.IP_AF_INET
        exm.dst_ip_addr.v4_addr = self.flow.dip.getnum()
        exm.ip_protocol = defs.ipprotos.id(self.flow.proto)
        exm.encap_or_transport.udp_fields.sport = self.flow.sport
        exm.encap_or_transport.udp_fields.dport = self.flow.dport

        trsp = req_spec.transpositions.add()
        trsp.action = haldefs.gft.GftHeaderGroupTranspostionAction.Value('TRANSPOSITION_ACTION_MODIFY')
        trsp.headers.ethernet_header = True
        trsp.header_fields.customer_vlan_id = True
        trsp.eth_fields.customer_vlan_id = 100
        return

    def ProcessHALResponse(self, req_spec, resp_spec):
        return

    def Show(self):
        cfglogger.info("GFT Flow: %s" % self.GID())
        cfglogger.info("- Match Fields:")
        cfglogger.info("  - Eth Header  : Smac:%s/Dmac:%s/Etype:%#x" %\
                       (self.flow.smac.get(), self.flow.dmac.get(), 0x800))
        cfglogger.info("  - IPv4 Header : Sip:%s/Dip:%s/Proto:%s" %\
                       (self.flow.sip.get(), self.flow.dip.get(), self.flow.proto))
        cfglogger.info("  - UDP Header  : Sport:%d/Dport:%d" %\
                       (self.flow.sport, self.flow.dport))
        return


class GftFlowObjectHelper:
    def __init__(self):
        self.objlist = []
        return

    def Configure(self):
        cfglogger.info("Configuring %d GFT Flows." % len(self.objlist))
        halapi.ConfigureGftFlows(self.objlist)
        return

    def Generate(self):
        ssns = Store.objects.GetAllByClass(session.SessionObject)
        for ssn in ssns:
            gft_iflow = GftFlowObject()
            gft_iflow.Init(ssn.iflow)
            self.objlist.append(gft_iflow)

            gft_rflow = GftFlowObject()
            gft_rflow.Init(ssn.rflow)
            self.objlist.append(gft_rflow)
        return

    def main(self):
        if not GlobalOptions.gft:
            return
        self.Generate()
        self.Configure()
        cfglogger.info("Adding %d GFT Flows to Store." % len(self.objlist))
        if len(self.objlist) == 0: return
        Store.objects.SetAll(self.objlist)
        return

    def GetAll(self):
        return self.objlist

GftFlowHelper = GftFlowObjectHelper()
