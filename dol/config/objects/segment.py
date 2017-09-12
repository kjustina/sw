#! /usr/bin/python3
import pdb
import infra.common.defs        as defs
import infra.common.objects     as objects
import infra.config.base        as base

import config.resmgr            as resmgr
import config.objects.endpoint  as endpoint
import config.objects.enic      as enic
import config.objects.network   as nw

import config.hal.api            as halapi
import config.hal.defs           as haldefs

from infra.common.logging       import cfglogger
from config.store               import Store

class SegmentObject(base.ConfigObjectBase):
    def __init__(self):
        super().__init__()
        self.Clone(Store.templates.Get('SEGMENT'))
        return

    def Init(self, tenant, spec):
        self.id = resmgr.SegIdAllocator.get()
        self.GID("Seg%04d" % self.id)

        self.spec       = spec
        self.tenant     = tenant
        self.type       = spec.type.upper()
        self.native     = spec.native
        self.l4lb       = getattr(spec, 'l4lb', False)
        self.blackhole  = getattr(spec, 'blackhole', False)

        if self.blackhole:
            self.vlan_id    = resmgr.BlackHoleSegVlanAllocator.get()
            self.vxlan_id   = resmgr.BlackHoleSegVxlanAllocator.get()
        else:
            self.vlan_id    = resmgr.SegVlanAllocator.get()
            self.vxlan_id   = resmgr.SegVxlanAllocator.get()

        self.macaddr    = resmgr.RouterMacAllocator.get()
        if self.IsInfraSegment():
            self.subnet     = resmgr.TepIpSubnetAllocator.get()
            self.subnet6    = resmgr.TepIpv6SubnetAllocator.get()
        else:
            self.subnet     = resmgr.IpSubnetAllocator.get()
            self.subnet6    = resmgr.Ipv6SubnetAllocator.get()

        self.ipv4_pool  = resmgr.CreateIpv4AddrPool(self.subnet.get())
        self.ipv6_pool  = resmgr.CreateIpv6AddrPool(self.subnet6.get())
        
        if self.l4lb:
            self.bend_subnet = resmgr.L4LbBackendIpSubnetAllocator.get()
            self.bend_subnet6 = resmgr.L4LbBackendIpv6SubnetAllocator.get()
            self.bend_ipv4_pool = resmgr.CreateIpv4AddrPool(self.bend_subnet.get())
            self.bend_ipv6_pool = resmgr.CreateIpv6AddrPool(self.bend_subnet6.get())

        policy = "BROADCAST_FWD_POLICY_" + spec.broadcast.upper()
        self.broadcast_policy = haldefs.segment.BroadcastFwdPolicy.Value(policy)

        policy = "MULTICAST_FWD_POLICY_" + spec.multicast.upper()
        self.multicast_policy = haldefs.segment.MulticastFwdPolicy.Value(policy)
        
        self.obj_helper_ep = endpoint.EndpointObjectHelper()
        self.obj_helper_enic = enic.EnicObjectHelper()
        self.obj_helper_nw = nw.NetworkObjectHelper()   

        self.hal_handle = None

        self.Show()
        self.obj_helper_nw.Generate(self)

        self.obj_helper_enic.Generate(self, self.spec.endpoints)
        self.obj_helper_ep.Generate(self, self.spec.endpoints)
        self.Show(detail = True)
        return

    def AllocIpv4Address(self, backend):
        if backend:
            assert(self.l4lb)
            return self.bend_ipv4_pool.get()
        return self.ipv4_pool.get()
    def AllocIpv6Address(self, backend):
        if backend:
            assert(self.l4lb)
            return self.bend_ipv6_pool.get()
        return self.ipv6_pool.get()

    def IsTenantSegment(self):
        return self.type == 'TENANT'
    def IsInfraSegment(self):
        return self.type == 'INFRA'
    def IsSpanSegment(self):
        return self.type == 'SPAN'

    def Show(self, detail = False):
        cfglogger.info("- Segment = %s(%d)" % (self.GID(), self.id))
        cfglogger.info("  - VLAN       = %d" % self.vlan_id)

        if not self.IsInfraSegment():
            cfglogger.info("  - VXLAN      = %s" % self.vxlan_id)
        cfglogger.info("  - Native     = %s" % self.native)
        if self.blackhole:
            cfglogger.info("  - BlackHole  = %s" % self.blackhole)
        cfglogger.info("  - MAC        = %s" % self.macaddr.get())
        cfglogger.info("  - Subnet     = %s" % self.subnet.get())
        cfglogger.info("  - Subnet6    = %s" % self.subnet6.get())
        cfglogger.info("  - Broadcast  = %s" % self.spec.broadcast)
        cfglogger.info("  - Multicast  = %s" % self.spec.multicast)

        if detail == False: return
        self.obj_helper_ep.Show()
        self.obj_helper_enic.Show()
        return

    def Summary(self):
        summary = ''
        summary += 'GID:%s' % self.GID()
        summary += '/ID:%s' % self.id
        summary += '/Native:%s' % (self.native)
        summary += '/Rmac:%s' % (self.macaddr.get())
        summary += '/AccEnc:%d' % (self.vlan_id)
        if self.tenant.IsOverlayVxlan():
            summary += '/FabEnc:0x%x' % self.vxlan_id
        else:
            summary += '/FabEnc:%d' % self.vlan_id
        return summary

    def GetDirectEnics(self, backend = False):
        if backend:
            return self.obj_helper_enic.backend_direct
        return self.obj_helper_enic.direct
    def GetPvlanEnics(self, backend = False):
        if backend:
            return self.obj_helper_enic.backend_pvlan
        return self.obj_helper_enic.pvlan
    def GetUsegEnics(self, backend = False):
        if backend:
            return self.obj_helper_enic.backend_useg
        return self.obj_helper_enic.useg
    def GetEps(self, backend = False):
        if backend:
            return self.obj_helper_ep.backend_eps
        return self.obj_helper_ep.eps
    def GetLocalEps(self, backend = False):
        if backend:
            return self.obj_helper_ep.backend_local
        return self.obj_helper_ep.local
    def GetRemoteEps(self, backend = False):
        if backend:
            return self.obj_helper_ep.backend_remote
        return self.obj_helper_ep.remote

    def ConfigureEndpoints(self):
        return self.obj_helper_ep.Configure()

    def ConfigureEnics(self):
        return self.obj_helper_enic.Configure()

    def ConfigureNetworks(self):
        return self.obj_helper_nw.Configure()

    def ConfigureChildren(self):
        self.ConfigureEnics()
        self.ConfigureEndpoints()
        return

    def PrepareHALRequestSpec(self, req_spec):
        req_spec.meta.tenant_id = self.tenant.id
        req_spec.key_or_handle.segment_id = self.id
        if self.IsTenantSegment() or self.IsSpanSegment():
            req_spec.segment_type = haldefs.common.L2_SEGMENT_TYPE_TENANT
        elif self.IsInfraSegment():
            req_spec.segment_type = haldefs.common.L2_SEGMENT_TYPE_INFRA
        else:
            assert(0)
        req_spec.access_encap.encap_type    = haldefs.common.ENCAP_TYPE_DOT1Q
        req_spec.access_encap.encap_value   = self.vlan_id
        if self.tenant.IsOverlayVxlan():
            req_spec.fabric_encap.encap_type    = haldefs.common.ENCAP_TYPE_VXLAN
            req_spec.fabric_encap.encap_value   = self.vxlan_id
        else:
            req_spec.fabric_encap.encap_type    = haldefs.common.ENCAP_TYPE_DOT1Q
            req_spec.fabric_encap.encap_value   = self.vlan_id
        req_spec.mcast_fwd_policy = self.multicast_policy
        req_spec.bcast_fwd_policy = self.broadcast_policy

        for nw in self.obj_helper_nw.nws:
            if nw.hal_handle:
                req_spec.network_handle.append(nw.hal_handle)
        return

    def ProcessHALResponse(self, req_spec, resp_spec):
        cfglogger.info("- Segment %s = %s" %\
                       (self.GID(), haldefs.common.ApiStatus.Name(resp_spec.api_status)))
        self.hal_handle = resp_spec.l2segment_status.l2segment_handle
        return
    
    def IsFilterMatch(self, spec):
        return super().IsFilterMatch(spec.filters)

# Helper Class to Generate/Configure/Manage Segment Objects.
class SegmentObjectHelper:
    def __init__(self):
        self.segs = []
        self.bhseg = None
        self.backend_eps = None
        self.backend_remote_eps = None
        return

    def Configure(self):
        cfglogger.info("Configuring %d Segments." % len(self.segs)) 
        for seg in self.segs:
            seg.ConfigureNetworks()
        halapi.ConfigureSegments(self.segs)
        return

    def ConfigurePhase2(self):
        for seg in self.segs:
            seg.ConfigureChildren()
        return

    def Generate(self, tenant, spec, count):
        cfglogger.info("Creating %d Segments for Tenant = %s" %\
                       (count, tenant.GID()))
        for s in range(count):
            seg = SegmentObject()
            seg.Init(tenant, spec)
            self.segs.append(seg)
            if seg.blackhole:
                assert(self.bhseg is None)
                self.bhseg = seg
        return

    def AddToStore(self):
        Store.objects.SetAll(self.segs)
        return

    def GetEps(self, backend = False):
        eps = []
        for seg in self.segs:
            eps += seg.GetEps(backend)
        return eps

    def GetLocalEps(self, backend = False):
        eps = []
        for seg in self.segs:
            eps += seg.GetLocalEps(backend)
        return eps

    def GetRemoteEps(self, backend = False):
        eps = []
        for seg in self.segs:
            eps += seg.GetRemoteEps(backend)
        return eps

    def __get_backend_eps(self, remote):
        if self.backend_remote_eps: return
        self.backend_remote_eps = self.GetRemoteEps(backend = True)
        cfglogger.info("Remote L4LB Backend Pool:")
        for bend in self.backend_remote_eps:
            cfglogger.info("- Backend: %s" % bend.GID())

        self.backend_eps = self.GetLocalEps(backend = True)
        cfglogger.info("L4LB Backend Pool:")
        for bend in self.backend_eps:
            cfglogger.info("- Backend: %s" % bend.GID())
        return

    def AllocL4LbBackend(self, remote):
        self.__get_backend_eps(remote)
        if remote:
            eplist = self.backend_remote_eps
        else:
            eplist = self.backend_eps

        obj = eplist[0]
        del eplist[0]
        return obj

    def GetBlackholeSegment(self):
        return self.bhseg
