#! /usr/bin/python3
import pdb

from infra.common.logging import logger

from apollo.config.store import EzAccessStore

import apollo.config.resmgr as resmgr
import apollo.config.agent.api as api
import apollo.config.objects.base as base
import apollo.config.objects.lmapping as lmapping
import apollo.config.objects.mirror as mirror
from apollo.config.objects.meter  import client as MeterClient
from apollo.config.objects.policy import client as PolicyClient
import apollo.config.utils as utils
import apollo.config.topo as topo

import vnic_pb2 as vnic_pb2
import types_pb2 as types_pb2

class VnicStatus(base.StatusObjectBase):
    def __init__(self):
        super().__init__(api.ObjectTypes.VNIC)
        return

    def Update(self, status):
        self.HwId = status.HwId
        return

    def __repr__(self):
        return "HwID:%d" % (self.HwId)

    def Show(self):
        logger.info("- VNIC status object:")
        logger.info("  - %s" % repr(self))

class VnicObject(base.ConfigObjectBase):
    def __init__(self, node, parent, spec, rxmirror, txmirror):
        super().__init__(api.ObjectTypes.VNIC, node)
        parent.AddChild(self)
        if (EzAccessStore.IsDeviceLearningEnabled()):
            self.SetOrigin(topo.OriginTypes.DISCOVERED)
        ################# PUBLIC ATTRIBUTES OF VNIC OBJECT #####################
        if (hasattr(spec, 'id')):
            self.VnicId = spec.id
        else:
            self.VnicId = next(resmgr.VnicIdAllocator)
        self.GID('Vnic%d'%self.VnicId)
        self.SUBNET = parent
        if hasattr(spec, 'vmac'):
            self.MACAddr =  spec.vmac
        else:
            self.MACAddr =  resmgr.VnicMacAllocator.get()
        if utils.IsDol():
            self.VlanId = next(resmgr.VnicVlanIdAllocator)
        else:
            self.VlanId = 0
        self.MplsSlot = next(resmgr.VnicMplsSlotIdAllocator)
        if utils.IsDol():
            self.Vnid = next(resmgr.VxlanIdAllocator)
        else:
            self.Vnid = parent.Vnid
        self.SourceGuard = False
        c = getattr(spec, 'srcguard', None)
        if c != None:
            self.SourceGuard = c
        self.HostIfIdx = getattr(parent, 'HostIfIdx', None)
        self.RxMirror = rxmirror
        self.TxMirror = txmirror
        self.V4MeterId = MeterClient.GetV4MeterId(node, parent.VPC.VPCId)
        self.V6MeterId = MeterClient.GetV6MeterId(node, parent.VPC.VPCId)
        self.IngV4SecurityPolicyIds = []
        self.IngV6SecurityPolicyIds = []
        self.EgV4SecurityPolicyIds = []
        self.EgV6SecurityPolicyIds = []
        self.Status = VnicStatus()
        ################# PRIVATE ATTRIBUTES OF VNIC OBJECT #####################
        self.__attachpolicy = getattr(spec, 'policy', False) and utils.IsVnicPolicySupported()
        # get num of policies [0-5] in rrob order if needed
        self.__numpolicy = resmgr.NumVnicPolicyAllocator.rrnext() if self.__attachpolicy else 0
        self.dot1Qenabled = getattr(spec, 'tagged', True)
        self.DeriveOperInfo(node)
        self.Mutable = True if (utils.IsUpdateSupported() and self.IsOriginFixed()) else False
        self.Show()

        ############### CHILDREN OBJECT GENERATION
        # Generate MAPPING configuration
        lmapping.client.GenerateObjects(node, self, spec)

        return

    def __repr__(self):
        return "VnicID:%d|SubnetID:%d|VPCId:%d|Origin:%s" %\
               (self.VnicId, self.SUBNET.SubnetId, self.SUBNET.VPC.VPCId, self.Origin)

    def Show(self):
        logger.info("VNIC object:", self)
        logger.info("- %s" % repr(self))
        logger.info("- Vlan: %s %d|Mpls:%d|Vxlan:%d|MAC:%s|SourceGuard:%s"\
             % (self.dot1Qenabled, self.VlanId, self.MplsSlot, self.Vnid, self.MACAddr, str(self.SourceGuard)))
        logger.info("- RxMirror:", self.RxMirror)
        logger.info("- TxMirror:", self.TxMirror)
        logger.info("- V4MeterId:%d|V6MeterId:%d" %(self.V4MeterId, self.V6MeterId))
        hostif = self.SUBNET.HostIf
        if hostif:
            lif = hostif.lif
            lififindex = utils.LifId2LifIfIndex(lif.id)
            logger.info("- HostInterface:%s|%s|%s|%s" %\
                (hostif.Ifname, lif.GID(), lififindex, utils.GetUUID(lififindex)))
        if self.__attachpolicy:
            logger.info("- NumSecurityPolicies:", self.__numpolicy)
            logger.info("- Ing V4 Policies:", self.IngV4SecurityPolicyIds)
            logger.info("- Ing V6 Policies:", self.IngV6SecurityPolicyIds)
            logger.info("- Egr V4 Policies:", self.EgV4SecurityPolicyIds)
            logger.info("- Egr V6 Policies:", self.EgV6SecurityPolicyIds)
        self.Status.Show()
        return

    def UpdateAttributes(self):
        if self.dot1Qenabled:
            self.VlanId = next(resmgr.VnicVlanIdAllocator)
        return

    def RollbackAttributes(self):
        if self.dot1Qenabled:
            self.VlanId = self.GetPrecedent().VlanId
        return

    def PopulateKey(self, grpcmsg):
        grpcmsg.VnicId.append(str.encode(str(self.VnicId)))
        return

    def PopulateSpec(self, grpcmsg):
        spec = grpcmsg.Request.add()
        spec.VnicId = str.encode(str(self.VnicId))
        spec.SubnetId = str.encode(str(self.SUBNET.SubnetId))
        if self.dot1Qenabled:
            spec.VnicEncap.type = types_pb2.ENCAP_TYPE_DOT1Q
            spec.VnicEncap.value.VlanId = self.VlanId
        else:
            spec.VnicEncap.type = types_pb2.ENCAP_TYPE_NONE
        spec.MACAddress = self.MACAddr.getnum()
        spec.SourceGuardEnable = self.SourceGuard
        utils.GetRpcEncap(self.MplsSlot, self.Vnid, spec.FabricEncap)
        for rxmirror in self.RxMirror:
            spec.RxMirrorSessionId.append(int(rxmirror))
        for txmirror in self.TxMirror:
            spec.TxMirrorSessionId.append(int(txmirror))
        spec.V4MeterId = str.encode(str(self.V4MeterId))
        spec.V6MeterId = str.encode(str(self.V6MeterId))
        for policyid in self.IngV4SecurityPolicyIds:
            spec.IngV4SecurityPolicyId.append(str.encode(str(policyid)))
        for policyid in self.IngV6SecurityPolicyIds:
            spec.IngV6SecurityPolicyId.append(str.encode(str(policyid)))
        for policyid in self.EgV4SecurityPolicyIds:
            spec.EgV4SecurityPolicyId.append(str.encode(str(policyid)))
        for policyid in self.EgV6SecurityPolicyIds:
            spec.EgV6SecurityPolicyId.append(str.encode(str(policyid)))
        if utils.IsPipelineApulu():
            if self.SUBNET.HostIf:
                spec.HostIf = utils.GetUUID(utils.LifId2LifIfIndex(self.SUBNET.HostIf.lif.id))
            elif self.HostIfIdx:
                spec.HostIf = utils.GetUUID(self.HostIfIdx)
        return

    def ValidateSpec(self, spec):
        if int(spec.VnicId) != self.VnicId:
            return False
        # if int(spec.SubnetId) != self.SUBNET.SubnetId:
        #     return False
        if EzAccessStore.IsDeviceEncapTypeMPLS():
            if utils.ValidateTunnelEncap(self.MplsSlot, spec.FabricEncap) is False:
                return False
        else:
            if utils.ValidateTunnelEncap(self.Vnid, spec.FabricEncap) is False:
                return False
        if utils.IsPipelineApulu():
            if self.SUBNET.HostIf:
                if utils.GetIdfromUUID(spec.HostIf) != utils.LifId2LifIfIndex(self.SUBNET.HostIf.lif.id):
                    return False
        if spec.MACAddress != self.MACAddr.getnum():
            return False
        if spec.SourceGuardEnable != self.SourceGuard:
            return False
        if int(spec.V4MeterId) != self.V4MeterId:
            return False
        if int(spec.V6MeterId) != self.V6MeterId:
            return False
        # TODO: validate policyid, policer
        return True

    def ValidateYamlSpec(self, spec):
        if  utils.GetYamlSpecAttr(spec, 'vnicid') != self.VnicId:
            return False
        if utils.IsPipelineApulu():
            if self.SUBNET.HostIf:
                if utils.GetYamlSpecAttr(spec, 'hostif', True) != utils.LifId2LifIfIndex(self.SUBNET.HostIf.lif.id):
                    return False
        if spec['macaddress'] != self.MACAddr.getnum():
            return False
        if spec['sourceguardenable'] != self.SourceGuard:
            return False
        if utils.GetYamlSpecAttr(spec, 'v4meterid') != self.V4MeterId:
            return False
        if utils.GetYamlSpecAttr(spec, 'v6meterid') != self.V6MeterId:
            return False
        return True

    def GetStatus(self):
        return self.Status

    def Generate_vnic_security_policies(self):
        if self.__numpolicy == 0:
            return
        numpolicy = self.__numpolicy
        subnetobj = self.SUBNET
        self.IngV4SecurityPolicyIds = PolicyClient.GenerateVnicPolicies(numpolicy, subnetobj, 'ingress')
        self.EgV4SecurityPolicyIds = PolicyClient.GenerateVnicPolicies(numpolicy, subnetobj, 'egress')
        if self.SUBNET.VPC.IsV6Stack():
            self.IngV6SecurityPolicyIds = PolicyClient.GenerateVnicPolicies(numpolicy, subnetobj, 'ingress', True)
            self.EgV6SecurityPolicyIds = PolicyClient.GenerateVnicPolicies(numpolicy, subnetobj, 'egress', True)
        return

    def IsEncapTypeVLAN(self):
        return self.dot1Qenabled

    def GetDependees(self, node):
        """
        depender/dependent - vnic
        dependee - subnet, meter, mirror & policy
        """
        dependees = [ self.SUBNET ]
        meterids = [ self.V4MeterId, self.V6MeterId ]
        meterobjs = MeterClient.GetObjectsByKeys(node, meterids)
        dependees.extend(meterobjs)
        policyids = self.IngV4SecurityPolicyIds + self.IngV6SecurityPolicyIds
        policyids += self.EgV4SecurityPolicyIds + self.EgV6SecurityPolicyIds
        policyobjs = PolicyClient.GetObjectsByKeys(node, policyids)
        dependees.extend(policyobjs)
        mirrorobjs = list(self.RxMirrorObjs.values()) + list(self.TxMirrorObjs.values())
        dependees.extend(mirrorobjs)
        return dependees

    def DeriveOperInfo(self, node):
        self.RxMirrorObjs = dict()
        for rxmirrorid in self.RxMirror:
            rxmirrorobj = mirror.client.GetMirrorObject(node, rxmirrorid)
            self.RxMirrorObjs.update({rxmirrorid: rxmirrorobj})

        self.TxMirrorObjs = dict()
        for txmirrorid in self.TxMirror:
            txmirrorobj = mirror.client.GetMirrorObject(node, txmirrorid)
            self.TxMirrorObjs.update({txmirrorid: txmirrorobj})
        super().DeriveOperInfo()
        return


    def RestoreNotify(self, cObj):
        logger.info("Notify %s for %s creation" % (self, cObj))
        if not self.IsHwHabitant():
            logger.info(" - Skipping notification as %s already deleted" % self)
            return
        logger.info(" - Linking %s to %s " % (cObj, self))
        if cObj.ObjType == api.ObjectTypes.POLICY:
            policylist = None
            if cObj.IsV4():
                if cObj.IsIngressPolicy():
                    policylist = self.IngV4SecurityPolicyIds
                elif cObj.IsEgressPolicy():
                    policylist = self.EgV4SecurityPolicyIds
            elif cObj.IsV6():
                if cObj.IsIngressPolicy():
                    policylist = self.IngV6SecurityPolicyIds
                elif cObj.IsEgressPolicy():
                    policylist = self.EgV6SecurityPolicyIds
            if policylist is not None:
                policylist.append(cObj.PolicyId)
            else:
                logger.error(" - ERROR: %s not associated with %s" % \
                             (cObj, self))
                assert(0)
        elif cObj.ObjType == api.ObjectTypes.MIRROR:
            mirrorlist = None
            if cObj.Id in self.RxMirrorObjs:
                mirrorlist = self.RxMirror
            elif cObj.Id in self.TxMirrorObjs:
                mirrorlist = self.TxMirror
            if mirrorlist is not None:
                mirrorlist.append(cObj.Id)
            else:
                logger.error(" - ERROR: %s not associated with %s" % \
                             (cObj, self))
                assert(0)
        elif cObj.ObjType == api.ObjectTypes.METER:
            if cObj.IsV4():
                self.V4MeterId = cObj.MeterId
            elif cObj.IsV6():
                self.V6MeterId = cObj.MeterId
        else:
            logger.info("%s ignoring %s restoration" %\
                        (self.ObjType.name, cObj.ObjType))
            return
        # self.Update()
        return

    def UpdateNotify(self, dObj):
        logger.info("Notify %s for %s update" % (self, dObj))
        if dObj.ObjType == api.ObjectTypes.SUBNET:
            logger.info("Updating vnic hostIf since subnet is updated" % (self, dObj))
            self.Update()
        return

    def DeleteNotify(self, dObj):
        logger.info("Notify %s for %s deletion" % (self, dObj))
        if not self.IsHwHabitant():
            logger.info(" - Skipping notification as %s already deleted" % self)
            return
        logger.info(" - Unlinking %s from %s " % (dObj, self))
        if dObj.ObjType == api.ObjectTypes.POLICY:
            policylist = None
            if dObj.IsV4():
                if dObj.IsIngressPolicy():
                    policylist = self.IngV4SecurityPolicyIds
                elif dObj.IsEgressPolicy():
                    policylist = self.EgV4SecurityPolicyIds
            elif dObj.IsV6():
                if dObj.IsIngressPolicy():
                    policylist = self.IngV6SecurityPolicyIds
                elif dObj.IsEgressPolicy():
                    policylist = self.EgV6SecurityPolicyIds
            if policylist is not None:
                policylist.remove(dObj.PolicyId)
            else:
                logger.error(" - ERROR: %s not associated with %s" % \
                             (dObj, self))
                assert(0)
        elif dObj.ObjType == api.ObjectTypes.MIRROR:
            mirrorlist = None
            if dObj.Id in self.RxMirror:
                mirrorlist = self.RxMirror
            elif dObj.Id in self.TxMirror:
                mirrorlist = self.TxMirror
            if mirrorlist is not None:
                mirrorlist.remove(dObj.Id)
            else:
                logger.error(" - ERROR: %s not associated with %s" % \
                             (dObj, self))
                assert(0)
        elif dObj.ObjType == api.ObjectTypes.METER:
            if self.V4MeterId == dObj.MeterId:
                self.V4MeterId = 0
            elif self.V6MeterId == dObj.MeterId:
                self.V6MeterId = 0
            else:
                logger.error(" - ERROR: %s not associated with %s" % \
                             (dObj, self))
                assert(0)
        else:
            logger.info("%s ignoring %s deletion" %\
                        (self.ObjType.name, dObj.ObjType))
            return
        # self.Update()
        return

class VnicObjectClient(base.ConfigClientBase):
    def __init__(self):
        super().__init__(api.ObjectTypes.VNIC, resmgr.MAX_VNIC)
        return

    def GetVnicObject(self, node, vnicid):
        return self.GetObjectByKey(node, vnicid)

    def GetKeyfromSpec(self, spec, yaml=False):
        if yaml: return utils.GetYamlSpecAttr(spec, 'vnicid')
        return int(spec.VnicId)

    def AssociateObjects(self, node):
        # generate security policies and associate with vnic
        for vnic in self.Objects(node):
            vnic.Generate_vnic_security_policies()
        return

    def GenerateObjects(self, node, parent, subnet_spec_obj):
        if getattr(subnet_spec_obj, 'vnic', None) == None:
            return
        def __get_rxmirror(vnicspec):
            ms = []
            if hasattr(vnicspec, 'rxmirror'):
                if vnicspec.rxmirror is None:
                    return ms;
                for rxmirror in vnicspec.rxmirror:
                    ms.append(rxmirror.msid)
            return ms

        def __get_txmirror(vnicspec):
            ms = []
            if hasattr(vnicspec, 'txmirror'):
                if vnicspec.txmirror is None:
                    return ms;
                for txmirror in vnicspec.txmirror:
                    ms.append(txmirror.msid)
            return ms

        for vnic_spec_obj in subnet_spec_obj.vnic:
            for c in range(vnic_spec_obj.count):
                # Alternate src dst validations
                rxmirror = __get_rxmirror(vnic_spec_obj)
                txmirror = __get_txmirror(vnic_spec_obj)
                obj = VnicObject(node, parent, vnic_spec_obj, rxmirror, txmirror)
                self.Objs[node].update({obj.VnicId: obj})
        return

    def CreateObjects(self, node):
        super().CreateObjects(node)
        # Create Local Mapping Objects
        lmapping.client.CreateObjects(node)
        return

client = VnicObjectClient()

def GetMatchingObjects(selectors):
    return client.Objects()
