#! /usr/bin/python3
import pdb

from third_party.scapy import *
from third_party.scapy.all import *

class PAYLOAD(Packet):
    name = "PAYLOAD"
    fields_desc = [
        FieldListField("data", [], ByteField("", 0))
    ]
    def show(self, indent=3, lvl="", label_lvl=""):
        print("%s###[ PAYLOAD ]###" % label_lvl)
        #print("%s  data      = " % label_lvl, end='')
        self.__print_payload(prefix=label_lvl + " ")
        self.payload.show(indent, lvl, label_lvl)
        return

    def __print_payload(self, prefix):
        size = len(self.data)
        i = 0
        print("%s" % prefix, end='')
        while i < size:
            if i != 0 and i % 16 == 0:
                print("\n%s" % prefix, end='')
            #if i and i % 16 and not i % 8:
            #    print(" ", end='')
            print("%02X " % self.data[i], end='')
            i += 1
        print("", flush=True)
        return

    def guess_payload_class(self, payload):
        if (self.haslayer(IP) and self.haslayer(UDP)):
            ip_payload_len = self.getlayer(IP).len - self.getlayer(IP).ihl << 2
            udp_payload_len = self.getlayer(UDP).len
            if (ip_payload_len > udp_payload_len):
                return (UDP_OPTIONS)
        return super().guess_payload_class()

    
class PADDING(Packet):
    name = "PADDING"
    fields_desc = [
        StrLenField("data", "")
    ]


class CRC(Packet):
    name = "CRC"
    fields_desc = [
        IntField("crc", 0)
    ]
    def show(self, indent=3, lvl="", label_lvl=""):
        print("%s###[ CRC ]###" % label_lvl)
        print("%s  crc      = 0x%x" % (label_lvl, self.crc))
        self.payload.show(indent, lvl, label_lvl)
        return

CRC_LENGTH = len(CRC())

PENDOL_SIGNATURE = 0x900D900D
class PENDOL(Packet):
    name = "PENDOL"
    fields_desc = [
        BitField("sig",         PENDOL_SIGNATURE,      32),
        BitField("ts",          0,      32),
        BitField("id",          0,      32),
        BitField("opcode",      0,      8),
        BitField("step_id",     0,      8),
        BitField("log",         0,      1),
        BitField("logdrop",     0,      1),
        BitField("rsvd",        0,      14),
    ]
    def show(self, indent=3, lvl="", label_lvl=""):
        print("%s###[ PENDOL ]###" % label_lvl)
        print("%s  sig      = 0x%X" % (label_lvl, self.sig))
        print("%s  ts       = %d" % (label_lvl, self.ts))
        print("%s  id       = %d" % (label_lvl, self.id))
        print("%s  opcode   = %d" % (label_lvl, self.opcode))
        print("%s  step_id  = %d" % (label_lvl, self.step_id))
        print("%s  log      = %d" % (label_lvl, self.log))
        print("%s  logdrop  = %d" % (label_lvl, self.logdrop))
        print("%s  rsvd     = %d" % (label_lvl, self.rsvd))
        self.payload.show(indent, lvl, label_lvl)
        return

PENDOL_LENGTH = len(PENDOL())

class IGMP(Packet):
    name = "IGMP"

    igmptypes = {0x11: "Group Membership Query",
                 0x12: "Version 1 - Membership Report",
                 0x16: "Version 2 - Membership Report",
                 0x17: "Leave Group"}

    fields_desc = [
        ByteEnumField("type", 0x11, igmptypes),
        ByteField("mrtime", 20),
        XShortField("chksum", None),
        IPField("gaddr", "0.0.0.0")]

    def post_build(self, p, pay):
        """Called implicitly before a packet is sent to compute and place IGMP checksum.

        Parameters:
          self    The instantiation of an IGMP class
          p       The IGMP message in hex in network byte order
          pay     Additional payload for the IGMP message
        """
        p += pay
        if self.chksum is None:
            ck = checksum(p[:2] + p[4:])
            p = p[:2] + ck.to_bytes(2, 'big') + p[4:]
        return p

bind_layers(IP, IGMP, frag=0, proto=2)

class GRH(Packet):
    name = "GRH"
    fields_desc = [
        BitField("ipver",       0,      4),
        BitField("tclass",      0,      8),
        BitField("flowlabel",   0,      20),
        BitField("paylen",      0,      16),
        BitField("nxthdr",      0,      8),
        BitField("hoplmt",      0,      8),
        IP6Field("sgid",        "::"),
        IP6Field("dgid",        "::"),
    ]

class VXLAN(Packet):
    name = "VXLAN"
    fields_desc = [
        BitField("flags_r0",    0,      4),
        BitField("flag_i",      1,      1),
        BitField("flags_r1",    0,      3),
        BitField("rsvd0",       0,      24),
        BitField("vni",         0,      24),
        BitField("rsvd1",       0,      8),
    ]
bind_layers(UDP, VXLAN, dport=4789)
bind_layers(VXLAN, Ether, flag_i=1)
class RDETH(Packet):
    name = "RDETH"
    fields_desc = [
        BitField("rsvd",        0,      8),
        BitField("eecnxt",      0,      24),
    ]

class ImmDT(Packet):
    name = "ImmDT"
    fields_desc = [
        BitField("imm_data",    0,      32),
    ]


class DETH(Packet):
    name = "DETH"
    fields_desc = [
        BitField("qkey",        0,      32),
        BitField("rsvd",        0,      8),
        BitField("srcqp",       0,      24),
    ]
    next_hdr = { 101: ImmDT, #send-only-with-imm
    }

    def guess_payload_class(self, payload):
        if (self.next_hdr[self.underlayer.opcode]): 
            return self.next_hdr[self.underlayer.opcode]
        else:
            assert(0);
            return super().guess_payload_class()

class RETH(Packet):
    name = "RETH"
    fields_desc = [
        BitField("va",          0,      64),
        BitField("r_key",       0,      32),
        BitField("dma_len",     0,      32),
    ]

    next_hdr = { 6: Raw, #write-first
                 10: Raw, #write-only
                 11: ImmDT, #write-only-with-imm
                 12: Raw, #read-request
    }

    def guess_payload_class(self, payload):
        if (self.next_hdr[self.underlayer.opcode]): 
            return self.next_hdr[self.underlayer.opcode]
        else:
            assert(0);
            return super().guess_payload_class()

class AtomicETH(Packet):
    name = "AtomicETH"
    fields_desc = [
        BitField("va",          0,      64),
        BitField("r_key",       0,      32),
        BitField("swapdt",      0,      64),
        BitField("cmpdt",       0,      64),
    ]


class XRCETH(Packet):
    name = "XRCETH"
    fields_desc = [
        BitField("rsvd",        0,      8),
        BitField("xrcsrq",      0,      24),
    ]

class AtomicAckETH(Packet):
    name = "AtomicAckETH"
    fields_desc = [
        BitField("orig_remdt",  0,      64),
    ]

class AETH(Packet):
    name = "AETH"
    fields_desc = [
        BitField("syndrome",    0,      8),
        BitField("msn",         0,      24),
    ]
    next_hdr = {
                 13: Raw, #read-response-first
                 15: Raw, #read-response-last
                 16: Raw, #read-response-only
                 17: Raw, #ack
                 18: AtomicAckETH, #atomic-ack
    }
    def guess_payload_class(self, payload):
        if (self.next_hdr[self.underlayer.opcode]): 
            return self.next_hdr[self.underlayer.opcode]
        else:
            assert(0);
            return super().guess_payload_class()

class IETH(Packet):
    name = "IETH"
    fields_desc = [
        BitField("r_key",       0,      32),
    ]

class BTH(Packet):
    name = "BTH"
    fields_desc = [
        BitField("opcode",      0,      8),
        BitField("se",          0,      1),
        BitField("m",           0,      1),
        BitField("padcnt",      0,      2),
        BitField("tver",        0,      4),
        BitField("p_key",       0,      16),
        BitField("f_r",         0,      1),
        BitField("b_r",         0,      1),
        BitField("rsvd",        0,      6),
        BitField("destqp",      0,      24),
        BitField("a",           0,      1),
        BitField("rsvd2",       0,      7),
        BitField("psn",         0,      24),
    ]

    next_hdr = { 0: Raw, #send-first
                 1: Raw, #send-middle
                 2: Raw, #send-last
                 3: ImmDT, #send-last-with-imm
                 4: Raw, #send-only
                 5: ImmDT, #send-only-with-imm
                 6: RETH, #write-first
                 7: Raw, #write-middle
                 8: Raw, #write-last
                 9: ImmDT, #write-last-with-imm
                 10: RETH, #write-only
                 11: RETH, #write-only-with-imm
                 12: RETH, #read-request
                 13: AETH, #read-response-first
                 14: Raw, #read-response-middle
                 15: AETH, #read-response-last
                 16: AETH, #read-response-only
                 17: AETH, #ack
                 18: AETH, #atomic-ack
                 19: AtomicETH, #compare-n-swap
                 20: AtomicETH, #fetch-add
                 21: Raw, #rsvd
                 22: IETH, #send-last-with-inv
                 23: IETH, #send-only-with-inv
                 100: DETH, #UD send-only
                 101: DETH, #UD send-only-with-imm
    }

    def guess_payload_class(self, payload):
        if (self.next_hdr[self.opcode]): 
            return self.next_hdr[self.opcode]
        else:
            assert(0);
            return super().guess_payload_class()

class UDP_OPTIONS(Packet):
    name = "UDP_Options"
    fields_desc = [
        UDPOptionsField("options", {})
    ]
UDP_OPTIONS_LENGTH = len(UDP_OPTIONS())                    

bind_layers(UDP, BTH, dport=4791)

bind_layers(UDP, TFTP, dport=65530)

class SUNRPC_4_PORTMAP_DUMP_REPLY_DATA(Packet):
   name = "SUNRPC_4_PORTMAP_DUMP_REPLY_DATA"
   fields_desc = [
       BitField("pgm",        0, 32),
       BitField("vers",       0, 32),
       FieldLenField("netid_len", 0, length_of="netid"),
       StrLenField("netid", "0", length_from=lambda pkt:pkt.netid_len),
       ConditionalField(StrLenField("opaque_data1", []), lambda pkt:len(pkt.netid)%4 != 0),
       FieldLenField("addr_len", 0, length_of="addr"),
       StrLenField("addr", "0", length_from=lambda pkt:pkt.addr_len),
       ConditionalField(StrLenField("opaque_data2", []), lambda pkt:len(pkt.addr)%4 != 0),
       FieldLenField("owner_len", 0, length_of="owner"),
       StrLenField("owner", "0", length_from=lambda pkt:pkt.owner_len),
       ConditionalField(StrLenField("opaque_data3", []), lambda pkt:len(pkt.owner)%4 != 0),
       BitField("ValFollows", 0, 32),
   ]

class SUNRPC_4_PORTMAP_DUMP_REPLY(Packet):
   name = "SUNRPC_4_PORTMAP_DUMP_REPLY"
   fields_desc = [
       BitField("ValFollows", 0, 32),
       ConditionalField(PacketListField("data", [], SUNRPC_4_PORTMAP_DUMP_REPLY_DATA, length_from=lambda x:None), lambda pkt:pkt.ValFollows == 1),
   ]

class SUNRPC_2_PORTMAP_GETPORT_CALL(Packet):
    name = "SUNRPC_2_PORTMAP_GETPORT_CALL"
    fields_desc = [
        BitField("pgm",      0,      32),
        BitField("vers",     0,      32),
        BitField("proto",    0,      32),
        BitField("port",     0,      32),
    ]

class SUNRPC_2_PORTMAP_GETPORT_REPLY(Packet):
   name = "SUNRPC_2_PORTMAP_GETPORT_REPLY"
   fields_desc = [
        BitField("port",      0,      32),
   ]
 
class SUNRPC_REPLY_HDR(Packet):
    name = "SUNRPC_REPLY_HDR"
    fields_desc = [
        BitField("reply_state",   0,      32),
        BitField("verif_len",     0,      32),
        BitField("verif",         0,      32),
        BitField("acc_state",     0,      32),
    ]

    next_hdr = {
                1122334455: SUNRPC_2_PORTMAP_GETPORT_REPLY, #RPC Portmapper GETPORT REPLY
                1122334466: SUNRPC_4_PORTMAP_DUMP_REPLY, #RPC Portmapper DUMP Reply
    }

    def guess_payload_class(self, payload):
        if (self.next_hdr[self.underlayer.xid]):
            return self.next_hdr[self.underlayer.xid]
        else:
            assert(0);
            return super().guess_payload_class()

class SUNRPC_CALL_HDR(Packet):
    name = "SUNRPC_CALL_HDR"
    fields_desc = [
        BitField("rpcvers",       0,      32),
        BitField("pgm",           0,      32),
        BitField("pgmvers",       0,      32),
        BitField("proc",          0,      32),
        BitField("cred_len",      0,      32),
        BitField("cred",          0,      32),
        BitField("verif_len",     0,      32),
        BitField("verif",         0,      32),
    ]

    next_hdr = { 
                (100000, 2, 3): SUNRPC_2_PORTMAP_GETPORT_CALL, #RPC Portmapper GETPORT
                (100000, 4, 4): PAYLOAD,
    }

    def guess_payload_class(self, payload):
        if (self.next_hdr[(self.pgm, self.pgmvers, self.proc)]):
            return self.next_hdr[(self.pgm, self.pgmvers, self.proc)]


class SUNRPC(Packet):
    name = "SUNRPC"
    fields_desc = [
        BitField("xid",           0,      32),
        BitField("msg_type",      0,      32),
    ]

    next_hdr = { 0: SUNRPC_CALL_HDR,  #Call-hdr
                 1: SUNRPC_REPLY_HDR, #Reply-hdr
    }

    def guess_payload_class(self, payload):
        if (self.next_hdr[self.msg_type]):
            return self.next_hdr[self.msg_type]
        else:
            assert(0);
            return super().guess_payload_class()

class SUNRPC_RCRD_MARKING(Packet):
    name = "SUNRPC_RCRD_MARKING"
    fields_desc = [
        BitField("frag_hdr",           0,      32),
    ]

bind_layers(UDP, SUNRPC, dport=111)
bind_layers(UDP, SUNRPC, dport=65529)
bind_layers(UDP, ESP, dport=4500)
bind_layers(TCP, SUNRPC_RCRD_MARKING, dport=111)
bind_layers(TCP, SUNRPC_RCRD_MARKING, dport=65529)
bind_layers(SUNRPC_RCRD_MARKING, SUNRPC)
bind_layers(SUNRPC, SUNRPC_CALL_HDR, msg_type=0)
bind_layers(SUNRPC, SUNRPC_REPLY_HDR, msg_type=1)

class ERSPAN(Packet):
    name = "ERSPAN"
    fields_desc = [
        BitField("ver",         0,      4),
        BitField("vlan",        0,      12),
        BitField("cos",         0,      3),
        BitField("bso",         0,      2),
        BitField("t",           0,      1),
        BitField("sessionid",   0,      10),
        BitField("timestamp",   0,      32),
        BitField("sgt",         0,      16),
        BitField("p",           0,      1),
        BitField("ft",          0,      5),
        BitField("hwid",        0,      6),
        BitField("d",           0,      1),
        BitField("gra",         0,      2),
        BitField("o",           0,      1),
    ]

bind_layers(GRE, ERSPAN, proto=0x22eb)

class _IpfixIpv4Fields(Packet):
    name = "IpfixIpv4Fields"
    fields_desc = [
        BitField("len",         0,      16),
        BitField("vrf",         0,      32),
        IPField("ip_sa",        "0.0.0.0"),
        IPField("ip_da",        "0.0.0.0"),
        BitField("proto",       0,      8),
        BitField("sport",       0,      16),
        BitField("dport",       0,      16),
    ]

class _IpfixIpv6Fields(Packet):
    name = "IpfixIpv4Fields"
    fields_desc = [
        BitField("len",         0,      16),
        BitField("vrf",         0,      32),
        IP6Field("ip_sa",       "::"),
        IP6Field("ip_da",       "::"),
        BitField("proto",       0,      8),
        BitField("sport",       0,      16),
        BitField("dport",       0,      16),
        BitField("pad",         0,      8),
    ]

class _IpfixNonIpFields(Packet):
    name = "IpfixNonIpFields"
    fields_desc = [
        BitField("len",         0,      16),
        MACField("mac_sa",      "00:00:00:00:00:00"),
        MACField("mac_da",      "00:00:00:00:00:00"),
        BitField("ether_type",  0,      16),
    ]

class _IpfixIpFields(Packet):
    name = "IpfixIpFields"
    fields_desc = [
        BitField("flow_state_index",        0,      24),
        BitField("role",                    0,      8),
        BitField("ttl",                     0,      8),
        BitField("icmp_type_code",          0,      16),
        BitField("tcp_seq_num",             0,      32),
        BitField("tcp_ack_num",             0,      32),
        BitField("tcp_win_sz",              0,      16),
        BitField("tcp_win_scale",           0,      8),
        BitField("tcp_state",               0,      8),
        BitField("tcp_win_mss",             0,      16),
        BitField("tcp_exceptions",          0,      32),
        BitField("flit_pad1",               0,      16),
        BitField("tcp_rtt",                 0,      32),
    ]

class _IpfixCommonFields(Packet):
    name = "IpfixIpFields"
    fields_desc = [
        BitField("flow_id",                 0,      32),
        BitField("egress_interface",        0,      16),
        BitField("egress_interface_type",   0,      16),
        BitField("permit_packets",          0,      64),
        BitField("permit_bytes",            0,      64),
        BitField("delta_permit_packets",    0,      32),
        BitField("delta_permit_bytes",      0,      32),
        BitField("drop_packets",            0,      64),
        BitField("drop_bytes",              0,      64),
        BitField("delta_drop_packets",      0,      32),
        BitField("delta_drop_bytes",        0,      32),
        BitField("flit_pad2",               0,      32),
        BitField("start_timestamp",         0,      64),
        BitField("last_seen_timestamp",     0,      64),
        BitField("drop_vector",             0,      64),
    ]

class _IpfixRecordBase(Packet):
    fields_desc = [
        BitField("set_id",      0,      16),
    ]
class IpfixRecord(Packet):
    fields_desc = [ _IpfixRecordBase ]

class IpfixRecordIpv4Data(Packet):
    name = 'IpfixRecordIpv4Data'
    holds_packet = True
    fields_desc = [ 
        _IpfixIpv4Fields,
        _IpfixIpFields,
        _IpfixCommonFields
    ]
    def guess_payload_class(self, payload):
        return IpfixRecord


class IpfixRecordIpv6Data(Packet):
    name = 'IpfixRecordIpv6Data'
    holds_packet = True
    fields_desc = [ 
        _IpfixIpv6Fields,
        _IpfixIpFields,
        _IpfixCommonFields
    ]
    def guess_payload_class(self, payload):
        return IpfixRecord

class IpfixRecordNonIpData(Packet):
    name = 'IpfixRecordNonIpData'
    holds_packet = True
    fields_desc = [ 
        _IpfixNonIpFields,
        _IpfixCommonFields
    ]
    def guess_payload_class(self, payload):
        return IpfixRecord

bind_layers(IpfixRecord, IpfixRecordIpv4Data, set_id=257)
bind_layers(IpfixRecord, IpfixRecordIpv6Data, set_id=258)
bind_layers(IpfixRecord, IpfixRecordNonIpData, set_id=259)

class Ipfix(Packet):
    holds_packet = 1
    name = "Ipfix"
    fields_desc = [
        BitField("version",     0,      16),
        BitField("len",         0,      16),
        BitField("export_time", 0,      32),
        BitField("seq_num",     0,      32),
        BitField("domain_id",   0,      32),
        PacketListField("records", [], IpfixRecord)
    ]

bind_layers(UDP, Ipfix, dport=4739)
