#! /usr/bin/python3

from iris.test.rdma.utils import *
from infra.common.glopts import GlobalOptions
from infra.common.logging import logger as logger
def Setup(infra, module):
    return

def Teardown(infra, module):
    return

def TestCaseSetup(tc):
    logger.info("RDMA TestCaseSetup() Implementation.")
    PopulatePreQStates(tc)
    return

def TestCaseTrigger(tc):
    logger.info("RDMA TestCaseTrigger() Implementation.")
    return

def TestCaseStepVerify(tc, step):
    if (GlobalOptions.dryrun): return True
    logger.info("RDMA TestCaseVerify() Implementation.")
    PopulatePostQStates(tc)

    rs = tc.config.rdmasession
    ring0_mask = (rs.lqp.num_rq_wqes - 1)

    if step.step_id == 0:
    
        ############     RQ VALIDATIONS #################
        # verify that e_psn is NOT incremented
        if not VerifyFieldModify(tc, tc.pvtdata.rq_pre_qstate, tc.pvtdata.rq_post_qstate, 'e_psn', 0):
            return False
    
        # verify that proxy_cindex is NOT incremented
        if not VerifyFieldMaskModify(tc, tc.pvtdata.rq_pre_qstate, tc.pvtdata.rq_post_qstate, 'proxy_cindex', ring0_mask, 0):
            return False
    
        # verify that token_id is incremented by 1
        if not VerifyFieldModify(tc, tc.pvtdata.rq_pre_qstate, tc.pvtdata.rq_post_qstate, 'token_id', 1):
            return False
    
        # verify that nxt_to_go_token_id is NOT incremented
        if not VerifyFieldModify(tc, tc.pvtdata.rq_pre_qstate, tc.pvtdata.rq_post_qstate, 'nxt_to_go_token_id', 0):
            return False
    
        # verify that state is now moved to ERR (2)
        if not VerifyErrQState(tc):
            return False

        ############     STATS VALIDATIONS #################
        #verify that qp_err_disabled is set to 1
        if not VerifyFieldModify(tc, tc.pvtdata.rq_pre_qstate, tc.pvtdata.rq_post_qstate, 'qp_err_disabled', 1):
            return False

        #verify that lkey_va_error is set to 1
        if not VerifyFieldModify(tc, tc.pvtdata.rq_pre_qstate, tc.pvtdata.rq_post_qstate, 'qp_err_dis_key_va_err', 1):
            return False

    elif step.step_id == 1:

        if not ValidatePostSyncCQChecks(tc):
            return False 

    return True

def TestCaseTeardown(tc):
    if (GlobalOptions.dryrun): return
    logger.info("RDMA TestCaseTeardown() Implementation.")
    ResetErrQState(tc)
    return
