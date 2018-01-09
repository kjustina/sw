#include "app_redir_common.h"

struct phv_                     p;
struct rawc_tx_start_k          k;
struct rawc_tx_start_start_d    d;

/*
 * Registers usage
 */
#define r_ci                        r1  // my_txq onsumer index
#define r_pi                        r2  // my_txq producer index
#define r_return                    r3
#define r_scratch                   r4
#define r_qstate_addr               r5

%%
    .param          rawc_s1_my_txq_entry_consume
    .param          rawc_err_stats_inc
    
    .align

rawc_s0_tx_start:
        
    /*
     * Stage 0 table engine always fetches the qstate (in d-vector)
     * for processing by the stage 0 MPUs.
     * 
     * In addition, 
     * R1 = table lookup hash value
     * R2 = packet size
     * R3 = random number
     * R4 = current time
     * R5 = programmable table constant
     * R6 = phv timestamp
     * R7 = qstate ring_not_empty
     */
     
    CAPRI_CLEAR_TABLE0_VALID
    phvwr       p.common_phv_qstate_addr, CAPRI_TXDMA_INTRINSIC_QSTATE_ADDR
    
    /*
     * qid is our flow ID context
     */
    phvwr       p.to_s1_my_txq_lif, CAPRI_INTRINSIC_LIF     // delay slot
    phvwr       p.to_s1_my_txq_qtype, CAPRI_TXDMA_INTRINSIC_QTYPE
    phvwr       p.to_s1_my_txq_qid, CAPRI_TXDMA_INTRINSIC_QID

    phvwr       p.common_phv_chain_txq_base, d.{chain_txq_base}.dx
    phvwr       p.common_phv_chain_txq_ring_size_shift, d.chain_txq_ring_size_shift
    phvwr       p.common_phv_chain_txq_entry_size_shift, d.chain_txq_entry_size_shift
    phvwr       p.t0_s2s_chain_txq_lif, d.{chain_txq_lif}.hx
    phvwr       p.t0_s2s_chain_txq_qtype, d.chain_txq_qtype
    phvwr       p.t0_s2s_chain_txq_qid, d.{chain_txq_qid}.wx
    phvwr       p.t0_s2s_chain_txq_ring, d.chain_txq_ring
    
    phvwr       p.to_s1_chain_txq_ring_indices_addr, d.{chain_txq_ring_indices_addr}.dx
    phvwr       p.to_s1_my_txq_ring_size_shift, d.my_txq_ring_size_shift

    /*
     * Two sentinels surround the programming of CB byte sequence:
     * rawccb_deactivate must be false and rawccb_activate must
     * be true to indicate readiness.
     */
    sne         c1, d.rawccb_deactivate, RAWCCB_DEACTIVATE
    seq.c1      c1, d.rawccb_activate, RAWCCB_ACTIVATE
    bal.!c1     r_return, _rawccb_not_ready
    phvwr       p.common_phv_rawccb_flags, d.{rawccb_flags}.hx // delay slot
    
    /*
     * PI assumed to have been incremented by doorbell write by a producer program;
     * double check for queue not empty in case we somehow got erroneously scheduled.
     */
    add         r_ci, r0, d.{ci_0}.hx   // delay slot
    mincr       r_ci, d.my_txq_ring_size_shift, r0
    add         r_pi, r0, d.{pi_0}.hx
    mincr       r_pi, d.my_txq_ring_size_shift, r0
    beq         r_ci, r_pi, _my_txq_ring_empty
    phvwr       p.to_s1_my_txq_ci_curr, r_ci        // delay slot

    /*
     * Launch read of descriptor at current CI.
     * Note that my_txq_base and corresponding CI/PI, once programmed,
     * are never cleared (because doing so can cause Tx scheduler lockup).
     * What can get altered are the rawccb_deactivated and rawccb_activated
     * flags which would tell this program to properly consume and free
     * the descriptor along with any pages embedded within.
     */    
    add         r_scratch, r0, d.my_txq_entry_size_shift
    sllv        r_ci, r_ci, r_scratch
    add         r_ci, r_ci, d.{my_txq_base}.dx
    CAPRI_NEXT_TABLE_READ(0,
                          TABLE_LOCK_DIS,
                          rawc_s1_my_txq_entry_consume,
                          r_ci,
                          TABLE_SIZE_64_BITS)
    nop.e
    nop    

    
/*
 * CB has been de-activated or never made ready
 */
_rawccb_not_ready:
 
    RAWCCB_ERR_STAT_INC_LAUNCH(3, r_qstate_addr,
                               CAPRI_TXDMA_INTRINSIC_QSTATE_ADDR,
                               p.t3_s2s_inc_stat_cb_not_ready)
    jr          r_return
    phvwri      p.common_phv_do_cleanup_discard, TRUE   // delay slot
     
 
/*
 * Early exit: my TxQ ring actually empty when entered
 */
_my_txq_ring_empty:

    RAWCCB_ERR_STAT_INC_LAUNCH(3, r_qstate_addr,
                               CAPRI_TXDMA_INTRINSIC_QSTATE_ADDR,
                               p.t3_s2s_inc_stat_my_txq_empty)
    nop.e
    nop    
