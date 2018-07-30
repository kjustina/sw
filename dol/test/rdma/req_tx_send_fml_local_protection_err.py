#! /usr/bin/python3

from test.rdma.utils import *
import pdb
import copy
from infra.common.glopts import GlobalOptions
from infra.common.logging import logger as logger
from config.objects.rdma.keytable import *
import infra.common.objects as objects

def Setup(infra, module):
    return

def Teardown(infra, module):
    return

def TestCaseSetup(tc):
    logger.info("RDMA TestCaseSetup() Implementation.")
    rs = tc.config.rdmasession
    rs.lqp.sq.qstate.Read()
    tc.pvtdata.sq_pre_qstate = copy.deepcopy(rs.lqp.sq.qstate.data)
    # TODO: WRID check in cqcb is disabled for this testcase by setting it to 0.
    # For multi-packet messages wrid needs to be stored in cqcb for posting out-of-order completions.
    # Alternate proposal is to update sq-cindex in this field. Will be revisited next-commit.
    tc.pvtdata.wrid = 0x0

    # Read CQ pre state
    rs.lqp.sq_cq.qstate.Read()
    tc.pvtdata.sq_cq_pre_qstate = rs.lqp.sq_cq.qstate.data

    return

def TestCasePreTrigger(tc):
    if (GlobalOptions.dryrun): return
    rs = tc.config.rdmasession
    slab_id = tc.buffers.Get('BUF3').slab_id
    tc.pvtdata.l_key = tc.config.rdmasession.lqp.pd.mrs.Get('MR-' + slab_id.GID()).lkey
    kt_entry = RdmaKeyTableEntryObject(rs.lqp.pd.ep.intf.lif, tc.pvtdata.l_key)
    logger.info("RDMA TestCaseSetup(): Lkey state/pd for SLAB of hw_lif %d qp %s lkey: %d state: %d pd: %d" %
            (rs.lqp.pd.ep.intf.lif.hw_lif_id, rs.lqp.GID(), tc.pvtdata.l_key, kt_entry.data.state, kt_entry.data.pd))
    # Make sure that lkey is valid before the test
    assert (kt_entry.data.state == 2) # KEY_STATE_VALID = 2

    # Set PD to invalid to simulate local-protection-error
    kt_entry.data.pd = 0xFFFFFFFF
    kt_entry.WriteWithDelay()

    logger.info("RDMA TestCasePreTrigger() Implementation.")
    return

def TestCaseTrigger(tc):
    logger.info("RDMA TestCaseTrigger() Implementation.")
    return


def TestCaseVerify(tc):
    logger.info("RDMA TestCaseVerify() Implementation.")
    return True

def TestCaseStepVerify(tc, step):
    if (GlobalOptions.dryrun): return True
    logger.info("RDMA TestCaseVerify() Implementation.")
    rs = tc.config.rdmasession
    rs.lqp.sq.qstate.Read()
    ring0_mask = (rs.lqp.num_sq_wqes - 1)
    tc.pvtdata.sq_post_qstate = rs.lqp.sq.qstate.data

    if step.step_id == 0:
        # verify that tx_psn is incremented by 2
        if not VerifyFieldModify(tc, tc.pvtdata.sq_pre_qstate, tc.pvtdata.sq_post_qstate, 'tx_psn', 2):
            return False

        # verify that p_index is incremented by 1
        if not VerifyFieldMaskModify(tc, tc.pvtdata.sq_pre_qstate, tc.pvtdata.sq_post_qstate, 'p_index0', ring0_mask,  1):
            return False

        # verify that c_index is incremented by 1
        if not VerifyFieldMaskModify(tc, tc.pvtdata.sq_pre_qstate, tc.pvtdata.sq_post_qstate, 'c_index0', ring0_mask, 1):
            return False

        # verify that ssn is not incremented
        if not VerifyFieldModify(tc, tc.pvtdata.sq_pre_qstate, tc.pvtdata.sq_post_qstate, 'ssn', 0):
            return False

        # verify that lsn is not incremented
        if not VerifyFieldModify(tc, tc.pvtdata.sq_pre_qstate, tc.pvtdata.sq_post_qstate, 'lsn', 0):
            return False

        # verify that busy is 1 when error occured.
        if not VerifyFieldAbsolute(tc, tc.pvtdata.sq_post_qstate, 'busy', 1):
            return False

        # verify that in_progress is 1 when error occured.
        if not VerifyFieldAbsolute(tc, tc.pvtdata.sq_post_qstate, 'in_progress', 1):
            return False

        # validate cqcb pindex and color
        if not ValidateReqRxCQChecks(tc, 'EXP_CQ_DESC'):
            return False

        #TODO: Check for error disable of QP.

    elif step.step_id == 1:
        if not ValidatePostSyncCQChecks(tc):
            return False

    return True

def TestCaseTeardown(tc):
    logger.info("RDMA TestCaseTeardown() Implementation.")
    # Reset busy/in_progress flags for further tests.
    rs = tc.config.rdmasession
    rs.lqp.sq.qstate.Read()
    rs.lqp.sq.qstate.data.busy = 0;
    rs.lqp.sq.qstate.data.cb1_busy = 0;
    rs.lqp.sq.qstate.data.in_progress = 0;

    rs.lqp.sq.qstate.data.state = 4 # QP_STATE_RTS
    rs.lqp.sq.qstate.data.p_index1 = ((rs.lqp.sq.qstate.data.p_index1 - 1) & 0xffff)
    #rs.lqp.sq.qstate.data.c_index0 = ((rs.lqp.sq.qstate.data.c_index0 + 1) & ring0_mask)
    #rs.lqp.sq.qstate.data.sq_cindex = ((rs.ssp.sq.qstate.data.sq_cindex + 1) & ring0_mask)

    rs.lqp.sq.qstate.WriteWithDelay()
    return
