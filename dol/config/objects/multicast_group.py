# /usr/bin/python3
import pdb

import infra.config.base        as base
import config.resmgr            as resmgr
import infra.common.objects     as objects
import config.hal.api           as halapi
import config.hal.defs          as haldefs

from config.store               import Store
from infra.common.logging       import cfglogger

MAX_ENICS_PER_GROUP = 2
class MulticastGroupObject(base.ConfigObjectBase):
    def __init__(self):
        super().__init__()
        self.Clone(Store.templates.Get('MULTICAST_GROUP'))
        return

    def Init(self, segment, spec):
        self.id = resmgr.MulticastGroupIdAllocator.get()
        self.GID("McGroup%04d" % self.id)

        self.type = spec.type.upper()
        self.group = spec.group.get()
        self.source = spec.source.get()
        self.l3type = spec.l3type.upper()
        self.gip = spec.gip.get()
        self.segment = segment
        self.pinnedif = segment.pinnedif

        self.session_spec = spec.session

        self.oifs = objects.ObjectDatabase(cfglogger)
        self.enic_list = []
        self.uplink_list = []
        return

    def GetOifList(self):
        return self.oifs.GetAllInList()

    def GetEnicOifList(self):
        return self.enic_list

    def GetUplinkOifList(self):
        return self.uplink_list

    def GetTxQosCos(self):
        return self.pinnedif.GetTxQosCos()

    def GetRxQosCos(self):
        return self.pinnedif.GetRxQosCos()

    def GetTxQosDscp(self):
        return self.pinnedif.GetTxQosDscp()

    def GetRxQosDscp(self):
        return self.pinnedif.GetRxQosDscp()

    def Show(self):
        cfglogger.info("Multicast Group:%s NumOifs:%d" %\
                       (self.GID(), len(self.oifs)))
        cfglogger.info("- type  : %s" % self.type)
        cfglogger.info("- group : %s" % self.group)
        cfglogger.info("- l3type: %s" % self.l3type)
        cfglogger.info("- gip   : %s" % self.gip)
        cfglogger.info("- OIFs  :")
        for intf in self.oifs.GetAllInList():
            cfglogger.info("  - Oif: %s" % (intf.Summary()))
        cfglogger.info("- ENICs  :")
        for intf in self.enic_list:
            cfglogger.info("  - Oif: %s" % (intf.Summary()))

        return

    def Summary(self):
        string = '%s/#Oifs:%d' % (self.GID(), len(self.oifs))
        string += '/Type:%s' % self.type
        string += '/Group:%s' % self.group.get()
        string += '/L3Type:%s' % self.l3type
        string += '/GIP:%s' % self.gip
        return string

    def IsMacGroup(self):
        return self.type == 'MAC'
    def IsIpv4Group(self):
        return self.type == 'IPV4'
    def IsIpv6Group(self):
        return self.type == 'IPV6'
    def IsIpGroup(self):
        return self.IsIpv4Group() or self.IsIpv6Group()
    def IsL3TypeIpv4(self):
        return self.l3type == 'IPV4'
    def IsL3TypeIpv6(self):
        return self.l3type == 'IPV6'

    def AddOif(self, oif, remote):
        for int in self.oifs.GetAllInList():
            if int == oif:
                return
        if remote:
            self.uplink_list.append(oif)
            self.oifs.Add(oif)
            return
        
        if oif.IsAllMulticast():
            cfglogger.info("Adding ALL MULTICAST oif:%s to enic list only." % oif.GID())
            self.enic_list.append(oif)
            return

        if len(self.enic_list) >= MAX_ENICS_PER_GROUP:
            cfglogger.info("Reached MAX_ENICS_PER_GROUP. Not adding OIF:%s" % (oif.GID()))
            return
        self.enic_list.append(oif)
        self.oifs.Add(oif)
        return

    def PrepareHALRequestSpec(self, req_spec):
        req_spec.meta.vrf_id = self.segment.tenant.id
        
        req_spec.key_or_handle.key.l2_segment_handle = self.segment.hal_handle
        if self.IsMacGroup():
            req_spec.key_or_handle.key.mac.group = self.group.getnum()
        elif self.IsIpv4Group():
            req_spec.key_or_handle.key.ip.source.ip_af = haldefs.common.IP_AF_INET
            req_spec.key_or_handle.key.ip.source.v4_addr = self.source.getnum()
            req_spec.key_or_handle.key.ip.group.ip_af = haldefs.common.IP_AF_INET
            req_spec.key_or_handle.key.ip.group.v4_addr = self.group.getnum()
        elif self.IsIpv6Group():
            req_spec.key_or_handle.key.ip.source.ip_af = haldefs.common.IP_AF_INET
            req_spec.key_or_handle.key.ip.source.v6_addr = self.source.getnum().to_bytes(16, 'big')
            req_spec.key_or_handle.key.ip.group.ip_af = haldefs.common.IP_AF_INET
            req_spec.key_or_handle.key.ip.group.v6_addr = self.group.getnum().to_bytes(16, 'big')

        for intf in self.oifs.GetAllInList():
            req_spec.oif_handles.append(intf.hal_handle)

        return

    def ProcessHALResponse(self, req_spec, resp_spec):
        cfglogger.info("- MulticastGroup: %s Status = %s" %\
                       (self.GID(),
                        haldefs.common.ApiStatus.Name(resp_spec.api_status)))
        self.hal_handle = resp_spec.entry_status.multicast_handle
        return

# Helper Class to Generate/Configure/Manage OifList Objects.
class MulticastGroupObjectHelper:
    def __init__(self):
        self.groups = []
        return

    def __add_local_eps(self, group, segment, spec):
        for endpoint in segment.GetLocalEps():
            group.AddOif(endpoint.GetInterface(), False)
        return

    def __add_remote_eps(self, group, segment, spec):
        for endpoint in segment.GetLocalEps():
            if segment.pinnedif is not None and\
               segment.pinnedif != endpoint.GetInterface():
                continue
            group.AddOif(endpoint.GetInterface(), False)
            if segment.pinnedif is not None and segment.IsFabEncapVxlan():
                oiflist.addOif(segment.pinnedif, True)
        return

    def Generate(self, segment): 
        groupspec = getattr(segment.spec, 'groups', None)
        if groupspec is None: return
        groupspec = groupspec.Get(Store)
        for gsp in groupspec.entries:
            group = MulticastGroupObject()
            group.Init(segment, gsp.entry)
            self.__add_local_eps(group, segment, gsp.entry)
            self.__add_remote_eps(group, segment, gsp.entry)
            group.Show()
            self.groups.append(group)
        Store.objects.SetAll(self.groups)
        return

    def Configure(self):
        cfglogger.info("Configuring %d Multicast Groups." % len(self.groups))
        halapi.ConfigureMulticastGroups(self.groups)
        return
