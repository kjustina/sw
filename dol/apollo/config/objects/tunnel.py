#! /usr/bin/python3
import pdb

from infra.common.logging import logger

from apollo.config.store import EzAccessStore

import apollo.config.resmgr as resmgr
import apollo.config.utils as utils
import apollo.config.topo as topo
import apollo.config.agent.api as api
import apollo.config.objects.base as base

import tunnel_pb2 as tunnel_pb2

class TunnelObject(base.ConfigObjectBase):
    def __init__(self, parent, spec, local):
        super().__init__(api.ObjectTypes.TUNNEL)
        self.__spec = spec
        self.Id = next(resmgr.TunnelIdAllocator)
        self.GID("Tunnel%d"%self.Id)
        self.DEVICE = parent
        self.__nhtype = topo.NhType.NONE
        ################# PUBLIC ATTRIBUTES OF TUNNEL OBJECT #####################
        self.LocalIPAddr = self.DEVICE.IPAddr
        self.EncapValue = 0
        self.Nat = False
        self.NexthopId = 0
        self.NEXTHOP = None
        self.NexthopGroupId = 0
        self.NEXTHOPGROUP = None
        if (hasattr(spec, 'nat')):
            self.Nat = spec.nat
        if local == True:
            self.RemoteIPAddr = self.LocalIPAddr
            self.Type = tunnel_pb2.TUNNEL_TYPE_NONE
        else:
            self.Type = utils.GetTunnelType(spec.type)
            if self.Type == tunnel_pb2.TUNNEL_TYPE_WORKLOAD:
                self.RemoteIPAddr = next(resmgr.TepIpAddressAllocator)
                self.RemoteVnicMplsSlotIdAllocator = resmgr.CreateRemoteVnicMplsSlotAllocator()
                self.RemoteVnicVxlanIdAllocator = resmgr.CreateRemoteVnicVxlanIdAllocator()
            elif self.Type == tunnel_pb2.TUNNEL_TYPE_IGW:
                self.RemoteIPAddr = next(resmgr.TepIpAddressAllocator)
                if self.DEVICE.IsEncapTypeMPLS():
                    self.EncapValue = next(resmgr.IGWMplsSlotIdAllocator)
                else:
                    self.EncapValue = next(resmgr.IGWVxlanIdAllocator)
            elif self.Type == tunnel_pb2.TUNNEL_TYPE_SERVICE:
                self.RemoteIPAddr = next(resmgr.TepIpv6AddressAllocator)
                if hasattr(spec, "remote") and spec.remote is True:
                    self.Remote = True
                    self.RemoteServicePublicIP = next(resmgr.RemoteSvcTunIPv4Addr)
                    self.RemoteServiceEncap = next(resmgr.IGWVxlanIdAllocator)
                else:
                    self.Remote = False
                self.EncapValue = next(resmgr.IGWVxlanIdAllocator)
            else:
                if utils.IsV4Stack(self.DEVICE.stack):
                    self.RemoteIPAddr = next(resmgr.TepIpAddressAllocator)
                else:
                    self.RemoteIPAddr = next(resmgr.TepIpv6AddressAllocator)
                # nexthop / nh_group association happens later
                if spec.type == 'underlay':
                    self.__nhtype = topo.NhType.UNDERLAY
                elif spec.type == 'underlay-ecmp':
                    self.__nhtype = topo.NhType.UNDERLAY_ECMP
        self.RemoteIP = str(self.RemoteIPAddr) # for testspec
        self.MACAddr = resmgr.TepMacAllocator.get()
        self.Mutable = utils.IsUpdateSupported()

        ################# PRIVATE ATTRIBUTES OF TUNNEL OBJECT #####################
        self.DeriveOperInfo()
        self.Show()
        return

    def __repr__(self):
        remote = ""
        if hasattr(self, "Remote") and self.Remote is True:
            remote = " Remote:%s"% (self.Remote)
        return "Tunnel%d|LocalIPAddr:%s|RemoteIPAddr:%s|TunnelType:%s%s|" \
               "EncapValue:%d|Nat:%s|Mac:%s|NhType:%s" % \
               (self.Id,self.LocalIPAddr, self.RemoteIPAddr,
               utils.GetTunnelTypeString(self.Type), remote, self.EncapValue,
               self.Nat, self.MACAddr, self.__nhtype)

    def Show(self):
        logger.info("Tunnel Object: %s" % self)
        logger.info("- %s" % repr(self))
        return

    def UpdateAttributes(self):
        if self.LocalIPAddr != self.RemoteIPAddr:
            if self.Type == tunnel_pb2.TUNNEL_TYPE_WORKLOAD:
                self.RemoteIPAddr = next(resmgr.TepIpAddressAllocator)
            elif self.Type == tunnel_pb2.TUNNEL_TYPE_IGW:
                self.RemoteIPAddr = next(resmgr.TepIpAddressAllocator)
            else:
                if utils.IsV4Stack(self.DEVICE.stack):
                    self.RemoteIPAddr = next(resmgr.TepIpAddressAllocator)
                else:
                    self.RemoteIPAddr = next(resmgr.TepIpv6AddressAllocator)
            if self.IsUnderlay():
                self.NEXTHOP = resmgr.UnderlayNHAllocator.rrnext()
            elif self.IsUnderlayEcmp():
                self.NEXTHOPGROUP = resmgr.UnderlayNhGroupAllocator.rrnext()
        self.RemoteIP = str(self.RemoteIPAddr) # for testspec
        self.MACAddr = resmgr.TepMacAllocator.get()
        return

    def RollbackAttributes(self):
        attrlist = ["RemoteIPAddr", "NEXTHOP", "NEXTHOPGROUP", "RemoteIP", "MACAddr"]
        self.RollbackMany(attrlist)
        return

    def PopulateKey(self, grpcmsg):
        grpcmsg.Id.append(str.encode(str(self.Id)))
        return

    def PopulateSpec(self, grpcmsg):
        spec = grpcmsg.Request.add()
        spec.Id = str.encode(str(self.Id))
        spec.VPCId = str.encode(str(0)) # TODO: Create Underlay VPC
        utils.GetRpcEncap(self.EncapValue, self.EncapValue, spec.Encap)
        spec.Type = self.Type
        utils.GetRpcIPAddr(self.LocalIPAddr, spec.LocalIP)
        utils.GetRpcIPAddr(self.RemoteIPAddr, spec.RemoteIP)
        spec.Nat = self.Nat
        # TODO: Fix mac addr in testspec
        if not utils.IsPipelineApollo():
            spec.MACAddress = self.MACAddr.getnum()
        if utils.IsServiceTunnelSupported():
            if self.Type is tunnel_pb2.TUNNEL_TYPE_SERVICE and self.Remote is True:
                spec.RemoteService = self.Remote
                utils.GetRpcIPAddr(self.RemoteServicePublicIP, spec.RemoteServicePublicIP)
                utils.GetRpcEncap(self.RemoteServiceEncap, self.RemoteServiceEncap, spec.RemoteServiceEncap)
        if self.IsUnderlay():
            spec.NexthopId = str.encode(str(self.NexthopId))
        elif self.IsUnderlayEcmp():
            spec.NexthopGroupId = str.encode(str(self.NexthopGroupId))
        return

    def ValidateSpec(self, spec):
        if int(spec.Id) != self.Id:
            return False
        if utils.ValidateTunnelEncap(self.EncapValue, spec.Encap) == False:
            return False
        if utils.ValidateRpcIPAddr(self.LocalIPAddr, spec.LocalIP) == False:
            return False
        if utils.ValidateRpcIPAddr(self.RemoteIPAddr, spec.RemoteIP) == False:
            return False
        if spec.Type != self.Type:
            return False
        if spec.Nat != self.Nat:
            return False
        if not utils.IsPipelineApollo():
            if spec.MACAddress != self.MACAddr.getnum():
                return False
        if utils.IsServiceTunnelSupported():
            if self.Type is tunnel_pb2.TUNNEL_TYPE_SERVICE and self.Remote is True:
                if spec.RemoteService != self.Remote:
                    return False
                if utils.ValidateRpcIPAddr(self.RemoteServicePublicIP, spec.RemoteServicePublicIP) == False:
                    return False
                if utils.ValidateTunnelEncap(self.RemoteServiceEncap, spec.RemoteServiceEncap) == False:
                    return False
        return True

    def ValidateYamlSpec(self, spec):
        if  utils.GetYamlSpecAttr(spec, 'id') != self.Id:
            return False
        return True

    def GetDependees(self):
        """
        depender/dependent - tunnel
        dependee - nexthop, & nexthop_group
        """
        # TODO: nh & nhg will be linked later
        dependees = [ ]
        if self.NEXTHOP:
            dependees.append(self.NEXTHOP)
        if self.NEXTHOPGROUP:
            dependees.append(self.NEXTHOPGROUP)
        return dependees

    def RestoreNotify(self, cObj):
        logger.info("Notify %s for %s creation" % (self, cObj))
        if not self.IsHwHabitant():
            logger.info(" - Skipping notification as %s already deleted" % self)
            return
        logger.info(" - Linking %s to %s " % (cObj, self))
        if cObj.ObjType == api.ObjectTypes.NEXTHOP:
            self.NexthopId = cObj.NexthopId
        elif cObj.ObjType == api.ObjectTypes.NEXTHOPGROUP:
            self.NexthopGroupId = cObj.Id
        else:
            logger.error(" - ERROR: %s not handling %s restoration" %\
                         (self.ObjType.name, cObj.ObjType))
            assert(0)
        # self.Update()
        return

    def DeleteNotify(self, dObj):
        logger.info("Notify %s for %s deletion" % (self, dObj))
        if not self.IsHwHabitant():
            logger.info(" - Skipping notification as %s already deleted" % self)
            return
        logger.info(" - Unlinking %s from %s " % (dObj, self))
        if dObj.ObjType == api.ObjectTypes.NEXTHOP:
            self.NexthopId = 0
        elif dObj.ObjType == api.ObjectTypes.NEXTHOPGROUP:
            self.NexthopGroupId = 0
        else:
            logger.error(" - ERROR: %s not handling %s deletion" %\
                         (self.ObjType.name, dObj.ObjType))
            assert(0)
        # self.Update()
        return

    def IsWorkload(self):
        if self.Type == tunnel_pb2.TUNNEL_TYPE_WORKLOAD:
            return True
        return False

    def IsIgw(self):
        if self.Type == tunnel_pb2.TUNNEL_TYPE_IGW:
            return True
        return False

    def IsSvc(self):
        if self.Type == tunnel_pb2.TUNNEL_TYPE_SERVICE:
            return True
        return False

    def IsNat(self):
        if self.Nat is True:
            return True
        return False

    def IsUnderlay(self):
        if self.__nhtype == topo.NhType.UNDERLAY:
            return True
        return False

    def IsUnderlayEcmp(self):
        if self.__nhtype == topo.NhType.UNDERLAY_ECMP:
            return True
        return False

class TunnelObjectClient(base.ConfigClientBase):
    def __init__(self):
        super().__init__(api.ObjectTypes.TUNNEL, resmgr.MAX_TUNNEL)
        return

    def GetKeyfromSpec(self, spec, yaml=False):
        if yaml: return utils.GetYamlSpecAttr(spec, 'id')
        return int(spec.Id)

    def GetTunnelObject(self, tunnelid):
        return self.GetObjectByKey(tunnelid)

    def AssociateObjects(self):
        logger.info("Filling nexthops")
        for tun in self.Objects():
            if tun.IsUnderlay():
                nhObj = resmgr.UnderlayNHAllocator.rrnext()
                tun.NEXTHOP = nhObj
                tun.NexthopId = nhObj.NexthopId
                logger.info("Linking %s - %s" % (tun, nhObj))
                nhObj.AddDependent(tun)
        return

    def FillUnderlayNhGroups(self):
        logger.info("Filling nexthop groups")
        for tun in self.Objects():
            if tun.IsUnderlayEcmp():
                nhGroupObj = resmgr.UnderlayNhGroupAllocator.rrnext()
                tun.NEXTHOPGROUP = nhGroupObj
                tun.NexthopGroupId = nhGroupObj.Id
                logger.info("Linking %s - %s" % (tun, nhGroupObj))
                nhGroupObj.AddDependent(tun)
        return


    def GenerateObjects(self, parent, tunnelspec):
        def __isTunFeatureSupported(tunnel_type):
            if tunnel_type == 'service':
                return utils.IsServiceTunnelSupported()
            elif tunnel_type == 'underlay' or tunnel_type == 'underlay-ecmp':
                return utils.IsUnderlayTunnelSupported()
            elif tunnel_type == 'internet-gateway':
                return utils.IsIGWTunnelSupported()
            elif tunnel_type == 'workload':
                return utils.IsWorkloadTunnelSupported()
            return False

        # Generate Remote Tunnel object
        for t in tunnelspec:
            if not __isTunFeatureSupported(t.type):
                continue
            for c in range(t.count):
                obj = TunnelObject(parent, t, False)
                self.Objs.update({obj.Id: obj})
        EzAccessStore.SetTunnels(self.Objects())
        resmgr.CreateInternetTunnels()
        resmgr.CreateVnicTunnels()
        resmgr.CollectSvcTunnels()
        resmgr.CreateUnderlayTunnels()
        return

client = TunnelObjectClient()

def GetMatchingObjects(selectors):
    return client.Objects()
