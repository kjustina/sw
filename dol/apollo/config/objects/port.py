#! /usr/bin/python3
import pdb
import enum

from infra.common.logging import logger

from apollo.config.store import client as EzAccessStoreClient

from apollo.config.resmgr import client as ResmgrClient

import apollo.config.agent.api as api
import apollo.config.utils as utils
import apollo.config.topo as topo
import apollo.config.objects.base as base

class UplinkPorts(enum.IntEnum):
    # In DOL, it starts with 1
    UplinkPort0 = 1
    UplinkPort1 = 2

class PortObject(base.ConfigObjectBase):
    def __init__(self, node, port, mode, state='UP'):
        ################# PUBLIC ATTRIBUTES OF PORT OBJECT #####################
        self.Node = node
        self.PortId = next(ResmgrClient[node].PortIdAllocator)
        self.GID("Port ID:%s"%self.PortId)
        self.Port = port
        self.Mode = mode
        self.AdminState = state
        ################# PRIVATE ATTRIBUTES OF PORT OBJECT #####################
        self.Show()
        return

    def __repr__(self):
        return "PortId:%d|Port:%d|AdminState:%s|Mode:%s" % \
                (self.PortId, self.Port, self.AdminState, self.Mode)

    def Show(self):
        logger.info("PortObject:")
        logger.info("- %s" % repr(self))
        return

    def IsHostPort(self):
        return self.Mode == topo.PortTypes.HOST

    def IsSwitchPort(self):
        return self.Mode == topo.PortTypes.SWITCH

class PortObjectClient:
    def __init__(self):
        self.__objs = dict()
        return

    def Objects(self):
        return self.__objs.values()

    def GenerateObjects(self, node, topospec):
        def __get_port_mode(port, mode='auto'):
            if mode == 'switch':
                return topo.PortTypes.SWITCH
            elif mode == 'host':
                return topo.PortTypes.HOST
            if EzAccessStoreClient[node].IsHostMode():
                return topo.PortTypes.SWITCH
            elif EzAccessStoreClient[node].IsBitwMode():
                if port == UplinkPorts.UplinkPort0:
                    return topo.PortTypes.HOST
                elif port == UplinkPorts.UplinkPort1:
                    return topo.PortTypes.SWITCH
            return topo.PortTypes.NONE

        portlist = getattr(topospec, 'uplink', None)
        if portlist is None:
            return
        for spec in portlist:
            entryspec = spec.entry
            port = getattr(entryspec, 'port')
            mode = __get_port_mode(port, getattr(entryspec, 'mode', 'auto'))
            obj = PortObject(node, port, mode)
            self.__objs.update({obj.PortId: obj})
            if obj.IsHostPort():
                EzAccessStoreClient[node].SetHostPort(obj.Port)
            elif obj.IsSwitchPort():
                EzAccessStoreClient[node].SetSwitchPort(obj.Port)
        return

client = PortObjectClient()
def GetMatchingObjects(selectors):
    return client.Objects()

