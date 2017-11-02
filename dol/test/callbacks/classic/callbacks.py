#! /usr/bin/python3

import pdb

def GetTxExpectedPacket(tc, args = None):
    return tc.packets.Get(args.expktid)

def GetRxExpectedPacket(tc, args = None):
    return tc.packets.Get(args.expktid)

def GetTxExpectedPorts(tc, args = None):
    assert(tc.config.dst.endpoint.remote is True)
    return tc.config.src.intf.pinnedif.ports

def GetRxTriggerPorts(tc, args = None):
    assert(tc.config.src.endpoint.remote is True)
    return tc.config.dst.endpoint.pinintf.ports

def GetCpuPacket(tc, args = None):
    return tc.packets.Get(args.expktid)

def __get_ring_from_enic(enic, rtype, qid, rid):
    qt = enic.lif.queue_types.Get(rtype)
    queue = qt.queues.Get(qid)
    ring = queue.rings.Get(rid)
    return ring

def __get_enic(tc, args):
    if args is None:
        return None
    
    oiflist = tc.pvtdata.pruned_oiflist
    if len(oiflist) < args.idx:
        return None
    enic = oiflist[args.idx]
    return enic

def GetEncapVlanIdForMulticastCopy(tc, pkt, args = None):
    enic = __get_enic(tc, args)
    tc.info("MulticastCopy: Enic:%s EncapVlanId:%d" % (enic.GID(), enic.encap_vlan_id))
    return enic.encap_vlan_id

def GetRxCqRingForMulticastCopy(tc, args = None):
    enic = __get_enic(tc, args)
    ring = __get_ring_from_enic(enic, 'RX', 'Q0', 'R1')
    tc.info("MulticastCopy: Enic:%s RxCqRing:%s" % (enic.GID(), ring.GID()))
    return ring

def GetRxRingForMulticastCopy(tc, args = None):
    #assert(tc.config.src.endpoint.remote == False)
    #enic = tc.config.src.endpoint.intf
    enic = __get_enic(tc, args)
    ring = __get_ring_from_enic(enic, 'RX', 'Q0', 'R0')
    tc.info("MulticastCopy: Enic:%s RxCqRing:%s" % (enic.GID(), ring.GID()))
    return ring

def GetPortsForMulticastCopy(tc, args = None):
    if args is None:
        return None

    oiflist = tc.config.src.segment.floodlist.uplink_list
    if len(oiflist) < args.idx:
        return None
    
    upintf = oiflist[args.idx]
    tc.info("MulticastCopy: Returning Ports for %s" % upintf.GID())
    return oiflist[args.idx].ports
