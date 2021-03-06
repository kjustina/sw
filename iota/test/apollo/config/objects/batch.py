#! /usr/bin/python3
import enum
import pdb
import infra.config.base as base
import iota.test.apollo.config.resmgr as resmgr
import iota.test.apollo.config.agent.api as api
import batch_pb2 as batch_pb2
import types_pb2 as types_pb2

from infra.common.logging import logger
from iota.test.apollo.config.store import Store

class BatchObject(base.ConfigObjectBase):
    def __init__(self):
        super().__init__()
        self.GID('Batch')
        self.epoch = next(resmgr.EpochAllocator)
        return

    def __repr__(self):
        return "Batch/epoch:%d" % self.epoch

    def GetBatchSpec(self):
        batchspec = batch_pb2.BatchSpec()
        batchspec.epoch = self.epoch
        return batchspec

    def SetNextEpoch(self):
        self.epoch += 1
        return

    def Show(self):
        logger.info("Batch Object:", self)
        logger.info("- %s" % repr(self))
        return

class BatchObjectClient:
    def __init__(self, client):
        self.__obj = None
        self.__client = client
        return

    def Objects(self):
        return self.__obj

    def GenerateObjects(self,  topospec):
        self.__obj = BatchObject()
        self.__obj.Show()
        return

    def Start(self):
        self.__obj.SetNextEpoch()
        self.__client.Start(api.ObjectTypes.BATCH, self.__obj.GetBatchSpec())
        return

    def Commit(self):
        self.__client.Commit(api.ObjectTypes.BATCH, self.__obj.GetBatchSpec())
        return
