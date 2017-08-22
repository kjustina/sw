#! /usr/bin/python3
import pdb

from third_party.scapy import *
from third_party.scapy.all import *

class PAYLOAD(Packet):
    name = "PAYLOAD"
    fields_desc = [
        XShortField("sig", 0xDA1A),
        FieldLenField("len", None, length_of="data"),
        FieldListField("data", [], ByteField("", 0))
    ]

    def show(self, indent=3, lvl="", label_lvl=""):
        print("%s###[ PAYLOAD ]###" % label_lvl)
        print("%s  sig  = %X" % (label_lvl, self.sig))
        if self.len:
            print("%s  len  = %d" % (label_lvl, self.len))
        else:
            print("%s  len  = None" % label_lvl)
        print("%s  data = " % label_lvl, end='')
        PrintPayload(self.data, prefix=label_lvl + "         ")
        self.payload.show(indent, lvl, label_lvl)
        return


class PADDING(Packet):
    name = "PADDING"
    fields_desc = [
        StrLenField("data", "")
    ]


class CRC(Packet):
    name = "CRC"
    fields_desc = [
        XIntField("crc", 0)
    ]


class PENDOL(Packet):
    name = "PENDOL"
    fields_desc = [
        BitField("ts",          0,      32),
        BitField("id",          0,      32),
        BitField("opcode",      0,      8),
        BitField("step_id",     0,      8),
        BitField("log",         0,      1),
        BitField("log_on_drop", 0,      1),
        BitField("rsvd",        0,      14),
    ]

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
bind_layers(UDP, BTH, dport=4791)

class RDETH(Packet):
    name = "RDETH"
    fields_desc = [
        BitField("rsvd",        0,      8),
        BitField("eecnxt",      0,      24),
    ]


class DETH(Packet):
    name = "DETH"
    fields_desc = [
        BitField("qkey",        0,      32),
        BitField("rsvd",        0,      8),
        BitField("srcqp",       0,      24),
    ]


class RETH(Packet):
    name = "RETH"
    fields_desc = [
        BitField("va",          0,      64),
        BitField("r_key",       0,      32),
        BitField("dmalen",      0,      32),
    ]


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


class AETH(Packet):
    name = "AETH"
    fields_desc = [
        BitField("syndrome",    0,      8),
        BitField("msn",         0,      24),
    ]


class AtomicAckETH(Packet):
    name = "AtomicAckETH"
    fields_desc = [
        BitField("orig_remdt",  0,      64),
    ]


class ImmDT(Packet):
    name = "ImmDT"
    fields_desc = [
        BitField("immdt",       0,      32),
    ]


class IETH(Packet):
    name = "IETH"
    fields_desc = [
        BitField("r_key",       0,      32),
    ]


def PrintPayload(data, prefix=""):
    size = len(data)
    i = 0
    while i < size:
        if i != 0 and i % 16 == 0:
            print("\n%s" % prefix, end='')
        print("%02X " % data[i], end='')
        i += 1
    print("", flush=True)
    return


def PrintPacket(pkt):
    raw = bytes(pkt)
    size = len(raw)
    i = 0
    while i < size:
        if i % 16 == 0:
            if i != 0:
                print("")
            print("%04X " % i, end='')
        if i % 8 == 0:
            print(" ", end='')

        print("%02X " % raw[i], end='')
        i += 1
    print("", flush=True)

def PrintRawPacket(pkt):
    hexdump(pkt)
    return

def PrintHeaders(pkt):
    pkt.show(indent=0)
    return

def Parse(message):
    pkt = Ether(message)
    try:
        rawhdr = pkt[Raw]
    except:
        rawhdr = pkt[Padding]
    rawhdr.underlayer.remove_payload()

    pyld = PAYLOAD(bytes(rawhdr))
    data = pyld.data
    penbytes = bytes(data[pyld.len:])

    del data[pyld.len:]
    pyld.data = data

    try:
        pen = PENDOL(penbytes)
        crcbytes = bytes(pen[Raw])
        pen[PENDOL].remove_payload()
        crc = CRC(crcbytes)
    except:
        pkt = pkt / pyld
        return pkt

    pkt = pkt / pyld / pen / crc
    return pkt
