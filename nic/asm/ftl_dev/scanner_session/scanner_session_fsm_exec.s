#include "ftl_dev_shared_asm.h"

struct phv_                             p;
struct s1_tbl_k                         k;
struct s1_tbl_session_fsm_exec_d        d;

/*
 * Registers usage
 */
#define r_scan_id_next                  r1
#define r_total_entries_scanned         r2
#define r_expiry_scan_id_base           r3
#define r_expiry_map_entries_scanned    r4
#define r_session_info_addr             r5
#define r_num_scannables                r6
#define r_scratch                       r7

/*
 * Registers reuse (post expiry_scan_id_base computation)
 */
#define r_limit                         r_expiry_scan_id_base 
 
/*
 * Registers reuse (for _resume_summarize)
 */
#define r_stage                         r6
#define r_qstate_addr                   r7
 
%%
    .param          session_round0_session0
    .param          session_round0_session1
    .param          session_round0_session2
    .param          session_round0_session3
    .param          session_summarize
    .align

session_fsm_exec:

    // Here we clear all tableX_valid bits (except metrics table 3) on behalf
    // of other stage1 functions (session_norm_tmo_load and 
    // session_accel_tmo_load). This is due to the fact that the FSM is 
    // responsible for calculating which tables will be lanched for stage2.
    
    CLEAR_TABLE_RANGE(0, 2)
    sne         c1, d.cb_activate, SCANNER_SESSION_CB_ACTIVATE

    // Validate parameters
    seq         c2, d.scan_range_sz, r0
    slt         c3, d.scan_range_sz, d.total_entries_scanned
    slt         c4, d.scan_range_sz, d.expiry_map_entries_scanned
    bcf         [c1 | c2 | c3 | c4], _scanner_cb_cfg_discard
    
    add         r_total_entries_scanned, d.total_entries_scanned, r0 // delay slot
    add         r_expiry_map_entries_scanned, d.expiry_map_entries_scanned, r0
    add         r_expiry_scan_id_base, d.expiry_scan_id_base, r0
    phvwr       p.session_kivec0_session_table_addr, d.scan_addr_base

    add         r_scratch, d.fsm_state, r0
_switch0:    
  .brbegin
    br          r_scratch[1:0]
    add         r_scan_id_next, d.scan_id_next, r0      // delay slot

  .brcase SCANNER_STATE_RESTART_RANGE
  
    tblwr       d.scan_id_next, d.scan_id_base
    tblwr       d.total_entries_scanned, r0
    add         r_scan_id_next, d.scan_id_base, r0

    // No "fall through" with MPU assembly (unless # of
    // instructions is exactly a power of 2)
    
    b           _expiry_map_restart
    add         r_total_entries_scanned, r0, r0         // delay slot
    
  .brcase SCANNER_STATE_RESTART_EXPIRY_MAP
  
_expiry_map_restart:

    tblwr       d.expiry_map_entries_scanned, r0
    add         r_expiry_map_entries_scanned, r0, r0
    b           _reevaluate
    add         r_expiry_scan_id_base, r_scan_id_next, r0 // delay slot
    
  .brcase SCANNER_STATE_SCAN

    b           _reevaluate
    nop
    
  .brcase SCANNER_STATE_REEVALUATE

_reevaluate:

    // Calculate # of sessions that are readable across the usable stages
    // and the 4 table engines.

    // IMPORTANT NOTE: evaluation of session_range_full, expiry_maps_full,
    // and session_burst_full must always take place to ensure we correctly
    // pick up from where we last left off (in the case of resumption due
    // to a previous poller queue full condition).
    //
    // Upon qfull resumption, one or more of the following conditions should be in effect:
    // - range_full:  in other words, d.total_entries_scanned 
    //                should still be >= d.scan_range_sz this time around, and
    //                r_num_scannables will evaluate to 0.
    //                
    // - expiry_maps_full: in other words, d.expiry_map_entries_scanned 
    //                should still be >= SCANNER_EXPIRY_MAP_ENTRIES_TOTAL_BITS
    //                this time around, and r_num_scannables will also
    //                evaluate to 0.
    // Plus, for either of the above:
    //   d.expiry_scan_id_base and d.expiry_map0..N should contain the
    //   same values where previously left off.
        
    phvwr       p.session_kivec0_session_id_curr, r_scan_id_next
    tblwr       d.expiry_scan_id_base, r_expiry_scan_id_base
    phvwr       p.session_kivec8_expiry_session_id_base, r_expiry_scan_id_base

    sub         r_num_scannables, d.scan_range_sz, r_total_entries_scanned
    sle         c1, SESSION_MPU_TABLES_TOTAL, r_num_scannables
    add.c1      r_num_scannables, r0, SESSION_MPU_TABLES_TOTAL

    // Hard limit # of scans to the expiry maps limit
    sub         r_limit, SCANNER_EXPIRY_MAP_ENTRIES_TOTAL_BITS, \
                r_expiry_map_entries_scanned
    sle         c2, r_limit, r_num_scannables
    add.c2      r_num_scannables, r0, r_limit
    
    // Limit # of scans to the burst limit;
    // Note this is a soft limit so it can just be calculated from
    // the current session ID without keeping any more state info.
_if2:    
    seq         c3, d.scan_burst_sz, r0
    bcf         [c3], _endif2
    add         r_limit, r_scan_id_next, r0          // delay slot
    mincr       r_limit, d.scan_burst_sz_shft, r0
    sub         r_limit, d.scan_burst_sz, r_limit
    sle         c3, r_limit, r_num_scannables
    add.c3      r_num_scannables, r0, r_limit
    phvwr.c3    p.session_kivec8_session_burst_full, 1
_endif2:
    
    // Update certain state info for next PHV resumption
    add         r_total_entries_scanned, r_total_entries_scanned, \
                r_num_scannables
    sle         c4, d.scan_range_sz, r_total_entries_scanned
    phvwr.c4    p.session_kivec8_session_range_full, 1
    tblwr       d.total_entries_scanned, r_total_entries_scanned
    
    add         r_expiry_map_entries_scanned, r_expiry_map_entries_scanned, \
                r_num_scannables
    sle         c5, SCANNER_EXPIRY_MAP_ENTRIES_TOTAL_BITS, \
                r_expiry_map_entries_scanned
    phvwr.c5    p.session_kivec8_expiry_maps_full, 1
    tblwr       d.expiry_map_entries_scanned, r_expiry_map_entries_scanned
    
    // Issue session info read scans
    beq         r_num_scannables, r0, _resume_summarize
    add         r_session_info_addr, d.scan_addr_base, \
                r_scan_id_next, SESSION_INFO_BYTES_SHFT      // delay slot
    SESSION_INFO_POSSIBLE_SCAN_INCR(0, SESSION_ROUND0,
                                    r_num_scannables, session_round0_session0, 
                                    _scan_break)
    SESSION_INFO_POSSIBLE_SCAN_INCR(1, SESSION_ROUND0,
                                    r_num_scannables, session_round0_session1,
                                    _scan_break)
    SESSION_INFO_POSSIBLE_SCAN_INCR(2, SESSION_ROUND0,
                                    r_num_scannables, session_round0_session2,
                                    _scan_break)
    SESSION_INFO_POSSIBLE_SCAN_INCR(3, SESSION_ROUND0,
                                    r_num_scannables, session_round0_session3,
                                    _scan_break)
_scan_break:
    phvwr.e     p.session_kivec0_num_scannables, r_num_scannables
    tbladd.f    d.scan_id_next, r_num_scannables

  .brend
_endsw0:

/*
 * Discard due to control block configuration
 */
_scanner_cb_cfg_discard:
 
    SESSION_METRICS_SET(cb_cfg_discards)
    phvwr       p.session_kivec0_cb_cfg_discard, 1
    
/*
 * Possible reasons to have reached this point are:
 * - Poller queue full detected during completion processing in the
 *   previously scheduled scan
 * - CB config errors (see above)
 */
_resume_summarize:

    //
    // Here we will attempt to resume from the summarize step. See also
    // "IMPORTANT NOTE" above regarding the re-evaluation of various
    // state such as session_range_full, expiry_maps_full, etc.
         
    SESSION_SUMMARIZE_LAUNCH_e(0, SESSION_KIVEC0_QSTATE_ADDR, session_summarize)
