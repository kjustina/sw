#! /usr/bin/python3

import pdb
import math
from infra.api.objects import PacketHeader
import infra.api.api as infra_api
from infra.common.logging       import logger
import infra.common.defs as defs
from infra.common.glopts import GlobalOptions
from test.callbacks.common.pktslicer import *
import binascii

def GetRqPreEpsn (tc, pkt):
    return tc.pvtdata.rq_pre_qstate.e_psn


def GetPktTxPsn (tc, pkt, args):
    return (tc.pvtdata.sq_pre_qstate.tx_psn + args.pkt_num)

def GetPktExpPsn (tc, pkt, args):
    return (tc.pvtdata.rq_pre_qstate.e_psn + args.pkt_num)

def GetLastSuccessMsn (tc, pkt, args):
    return (tc.pvtdata.rq_pre_qstate.msn + args.num_msgs)   # increment by number of msgs received

def GetVAfromSLAB (tc, pkt, args):
    if (GlobalOptions.dryrun): return 0
    return (tc.config.rdmasession.lqp.pd.ep.slabs.Get(args.slab_id).address + args.offset)

def GetCQExpColor (tc, desc, args = None):
    if tc.pvtdata.rq_cq_pre_qstate.p_index0 == 0:
       return (not tc.pvtdata.rq_cq_pre_qstate.color)
    else:
       return (tc.pvtdata.rq_cq_pre_qstate.color)

def GetReqRxCQExpColor (tc, desc, args = None):
    if tc.pvtdata.sq_cq_pre_qstate.p_index0 == 0:
       return (not tc.pvtdata.sq_cq_pre_qstate.color)
    else:
       return (tc.pvtdata.sq_cq_pre_qstate.color)
     
def GetPacketPayloadSize(tc, pkt, args):
    pmtu = 1 << tc.pvtdata.rq_pre_qstate.log_pmtu
    if ((args.pkt_num + 1) <= (args.msg_size / pmtu)):
        pkt_payload_size = pmtu 
    else: 
        pkt_payload_size = args.msg_size % pmtu
    return (pkt_payload_size)

def MSB( n ):
  ndx = 0
  while ( 1 < n ):
    n = ( n >> 1 )
    ndx += 1
  return ndx

def GetAckSyndrome(tc, pkt, args):
    # AETH_CODE_ACK << AETH_SYNDROME_CODE_SHIFT | CCCCC (credit count)
    # 8 bits: 3 ack/Nak code + 5 bits
    # 3 bits for ACK: 000
    # 5 bits for lsn(ciredits) = log2(rqwqes) * 2 . If no RQWQEs posted, set credits to zero: 00000
    credits = 0
    if (args.rqwqes == 0):
        credits = 0
    else:
        #credits = int(math.log(args.rqwqes, 2) + 1) * 2
        credits = MSB(args.rqwqes) * 2
    syndrome = ((0 << 5) | credits)
    return syndrome

def GetNakSyndrome(tc, pkt, args):
    # AETH_CODE_NAK << AETH_SYNDROME_CODE_SHIFT | nak_code
    syndrome = ((3 << 5) | args.nak_code) 
    return syndrome

def GetUDPacketPayload(tc, packet, args):
    srcpacket = tc.packets.Get(args.pktid) 
    slicer = PacketSlicer(srcpacket, args)
    slc = slicer.GetSlice()
    payload_size = getattr(args, 'pl_size', 64)
    payload = bytes([0x0]*payload_size)
    print('GetUDPacketPayload: %s ' % (binascii.hexlify(bytes(slc+payload))))
    return list(slc+payload)
    
def GetUDSMAC(tc, desc):
    return bytes(tc.config.rdmasession.session.initiator.ep.macaddr.getnum().to_bytes(6, 'big'))

def GetZeroMAC(tc, desc):
    return bytes([0x0]*6)


