#! /usr/bin/python3
import pdb

import model_sim.src.model_wrap as model_wrap

from infra.common.glopts import GlobalOptions

class ModelRxPacket:
    def __init__(self, rawpkt, port, cos):
        self.rawpkt = rawpkt
        self.port   = port
        self.cos    = cos
        return

class ModelConnectorObject:
    def __init__(self):
        self.__connected = False
        self.Connect()
        return

    def Connect(self):
        if GlobalOptions.dryrun: return
        if self.__connected is False:
            self.__connected = True
            model_wrap.zmq_connect()
        return

    def Transmit(self, rawpkt, port):
        if GlobalOptions.dryrun: return
        model_wrap.step_network_pkt(rawpkt, port)
        return

    def __recv_uplink_packets(self, rxpkts):
        while True:
            pkt, port, cos = model_wrap.get_next_pkt()
            if len(pkt) == 0: break
            rxpkt = ModelRxPacket(pkt, port, cos)
            rxpkts.append(rxpkt)
        return
      
    def __recv_cpu_packets(self, rxpkts):
        while True:
            pkt = model_wrap.get_next_cpu_pkt()
            if len(pkt) == 0: break
            rxpkt = ModelRxPacket(pkt, 128, 0)
            rxpkts.append(rxpkt)
        return

    def Receive(self):
        if GlobalOptions.dryrun: return []
        rxpkts = []
        self.__recv_uplink_packets(rxpkts)
        self.__recv_cpu_packets(rxpkts)
        return rxpkts

ModelConnector = ModelConnectorObject()
