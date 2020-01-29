#ifndef __FTL_DEV_SHARED_ASM_H
#define __FTL_DEV_SHARED_ASM_H

#include "INGRESS_p.h"
#include "ingress.h"
#include "capri-macros.h"
#include "ftl_dev_shared.h"

#define BITS_PER_BYTE                           8
#define SIZE_IN_BITS(bytes)                     ((bytes) * BITS_PER_BYTE)
#define SIZE_IN_BYTES(bits)                     ((bits) / BITS_PER_BYTE)

/*
 * Intrinsic fields
 */
#ifndef HW_MPU_INTRINSIC_LIF
#define HW_MPU_INTRINSIC_LIF                                                    \
        k.{p4_intr_global_lif_sbit0_ebit2...p4_intr_global_lif_sbit3_ebit10}
#endif

#ifndef HW_MPU_TXDMA_INTRINSIC_QTYPE
#define HW_MPU_TXDMA_INTRINSIC_QTYPE            k.{p4_txdma_intr_qtype}
#endif
#ifndef HW_MPU_TXDMA_INTRINSIC_QID
#define HW_MPU_TXDMA_INTRINSIC_QID              k.{p4_txdma_intr_qid}
#endif
#ifndef HW_MPU_TXDMA_INTRINSIC_QSTATE_ADDR
#define HW_MPU_TXDMA_INTRINSIC_QSTATE_ADDR                                      \
        k.{p4_txdma_intr_qstate_addr_sbit0_ebit1...p4_txdma_intr_qstate_addr_sbit2_ebit33}
#endif

/*
 * Bit selections in spr_mpuid register
 */
#ifndef HW_MPU_SPR_MPUID_MPU_SELECT
#define HW_MPU_SPR_MPUID_MPU_SELECT             1:0
#define HW_MPU_SPR_MPUID_STAGE_SELECT           4:2
#endif
 
/*
 * Table engine operations
 */
#define CLEAR_TABLE_X(_tbl)                                                     \
    phvwri      p.app_header_table##_tbl##_valid, 0;                            \
    
#define CLEAR_TABLE_X_e(_tbl)                                                   \
    phvwri.e    p.app_header_table##_tbl##_valid, 0;                            \
    nop;                                                                        \
    
#define CLEAR_TABLE_RANGE(_first, _last)                                        \
    phvwr       p.{app_header_table##_first##_valid...                          \
                   app_header_table##_last##_valid}, r0;                        \
    
#define CLEAR_TABLE_RANGE_e(_first, _last)                                      \
    phvwr.e     p.{app_header_table##_first##_valid...                          \
                   app_header_table##_last##_valid}, r0;                        \
    nop;                                                                        \
                   
#define CLEAR_TABLE_ALL                                                         \
    CLEAR_TABLE_RANGE(0, 3)                                                     \
    
#define CLEAR_TABLE_ALL_e                                                       \
    CLEAR_TABLE_RANGE_e(0, 3)                                                   \
    
#define CLEAR_TABLE0                                                            \
    CLEAR_TABLE_X(0)                                                            \

#define CLEAR_TABLE0_e                                                          \
    CLEAR_TABLE_X_e(0)                                                          \

#define CLEAR_TABLE1                                                            \
    CLEAR_TABLE_X(1)                                                            \

#define CLEAR_TABLE1_e                                                          \
    CLEAR_TABLE_X_e(1)                                                          \

#define CLEAR_TABLE2                                                            \
    CLEAR_TABLE_X(2)                                                            \

#define CLEAR_TABLE2_e                                                          \
    CLEAR_TABLE_X_e(2)                                                          \

#define CLEAR_TABLE3                                                            \
    CLEAR_TABLE_X(3)                                                            \

#define CLEAR_TABLE3_e                                                          \
    CLEAR_TABLE_X_e(3)                                                          \

#define LOAD_TABLE_FOR_ADDR(_tbl, _lock_en, _tbl_addr, _tbl_sz, _pc)            \
    phvwrpair  p.{common_te##_tbl##_phv_table_lock_en...                        \
                  common_te##_tbl##_phv_table_raw_table_size},                  \
               ((_lock_en) << 3 ) | (_tbl_sz),                                  \
               p.common_te##_tbl##_phv_table_addr, _tbl_addr;                   \
    phvwri     p.common_te##_tbl##_phv_table_pc, _pc[33:6];                     \
    phvwr      p.app_header_table##_tbl##_valid, 1;                             \
                            
#define LOAD_TABLE_FOR_ADDR_e(_tbl, _lock_en, _tbl_addr, _tbl_sz, _pc)          \
    phvwrpair  p.{common_te##_tbl##_phv_table_lock_en...                        \
                  common_te##_tbl##_phv_table_raw_table_size},                  \
               ((_lock_en) << 3) | (_tbl_sz),                                   \
               p.common_te##_tbl##_phv_table_addr, _tbl_addr;                   \
    phvwri.e   p.common_te##_tbl##_phv_table_pc, _pc[33:6];                     \
    phvwr      p.app_header_table##_tbl##_valid, 1;                             \
    
#define LOAD_TABLE_FOR_ADDR64(_tbl, _lock_en, _tbl_addr, _tbl_sz, _pc)          \
    phvwr      p.{common_te##_tbl##_phv_table_lock_en...                        \
                  common_te##_tbl##_phv_table_raw_table_size},                  \
               ((_lock_en) << 3 ) | (_tbl_sz);                                  \
    phvwri     p.common_te##_tbl##_phv_table_pc, _pc[33:6];                     \
    phvwr      p.common_te##_tbl##_phv_table_addr, _tbl_addr;                   \
    phvwr      p.app_header_table##_tbl##_valid, 1;                             \
                            
#define LOAD_TABLE_FOR_ADDR64_e(_tbl, _lock_en, _tbl_addr, _tbl_sz, _pc)        \
    phvwr      p.{common_te##_tbl##_phv_table_lock_en...                        \
                  common_te##_tbl##_phv_table_raw_table_size},                  \
               ((_lock_en) << 3 ) | (_tbl_sz);                                  \
    phvwri     p.common_te##_tbl##_phv_table_pc, _pc[33:6];                     \
    phvwr.e    p.common_te##_tbl##_phv_table_addr, _tbl_addr;                   \
    phvwr      p.app_header_table##_tbl##_valid, 1;                             \
                            
#define LOAD_TABLE_NO_ADDR(_tbl, _pc)                                           \
    phvwrpair  p.{common_te##_tbl##_phv_table_lock_en...                        \
                  common_te##_tbl##_phv_table_raw_table_size},                  \
               ((TABLE_LOCK_DIS) << 3) | (TABLE_SIZE_0_BITS),                   \
               p.common_te##_tbl##_phv_table_addr, r0;                          \
    phvwri     p.common_te##_tbl##_phv_table_pc, _pc[33:6];                     \
    phvwr      p.app_header_table##_tbl##_valid, 1;                             \
                            
#define LOAD_TABLE_NO_ADDR_e(_tbl, _pc)                                         \
    phvwrpair  p.{common_te##_tbl##_phv_table_lock_en...                        \
                  common_te##_tbl##_phv_table_raw_table_size},                  \
               ((TABLE_LOCK_DIS) << 3) | (TABLE_SIZE_0_BITS),                   \
               p.common_te##_tbl##_phv_table_addr, r0;                          \
    phvwri.e   p.common_te##_tbl##_phv_table_pc, _pc[33:6];                     \
    phvwr      p.app_header_table##_tbl##_valid, 1;                             \

/*
 * DMA command pointer init
 */
#define DMA_CMD_PTR_INIT(_dma_cmd)                                              \
    phvwri     p.p4_txdma_intr_dma_cmd_ptr,                                     \
               CAPRI_PHV_START_OFFSET(_dma_cmd##_dma_cmd_type) / 16             \
 
/*
 * Structure offsets:
 *   Struct fields in d-vec are arranged by NCC in big endian so the 1st field
 *   is the highest order field at the largest bit offset 512. Hence, we make 
 *   adjustment here to re-orientate the fields to get the expected "C" like
 *   offsets.
 */
#define SCANNER_STRUCT_BIT_OFFS(_struct_name, _field)                           \
    (512 - (offsetof(struct _struct_name, _field) +                             \
            sizeof(struct _struct_name._field)))                                \
    
#define SCANNER_STRUCT_BYTE_OFFS(_struct_name, _field)                          \
    SIZE_IN_BYTES(SCANNER_STRUCT_BIT_OFFS(_struct_name, _field))                \
            
/*
 * With 4 table engines, we can scan up to 4 flow sessions per stage;
 * below is how many rounds (i.e., stages) are dedicated for session scanning.
 */
#define SESSION_ROUND0                          0
#define SESSION_ROUND1                          1
#define SESSION_ROUND2                          2
#define SESSION_ROUND3                          3
#define SESSION_ROUNDS_MAX                      4

#define SESSION_MPU_TABLES_MAX                  (CAPRI_MPU_TABLE_3 + 1)
#define SESSION_MPU_TABLES_TOTAL                (SESSION_ROUNDS_MAX *           \
                                                 SESSION_MPU_TABLES_MAX)
/*
 * Stage specific actions
 */
#define SESSION_SUMMARIZE_STAGE                 HW_MPU_STAGE_6
#define SESSION_POLLER_POST_STAGE               HW_MPU_STAGE_7
#define SESSION_METRICS_STAGE                   HW_MPU_STAGE_7

/*
 * K+I vectors
 */
#define SESSION_KIVEC0_QSTATE_ADDR                                              \
    k.{session_kivec0_qstate_addr_sbit0_ebit31...session_kivec0_qstate_addr_sbit32_ebit33}
#define SESSION_KIVEC0_SESSION_TABLE_ADDR                                       \
    k.{session_kivec0_session_table_addr_sbit0_ebit5...session_kivec0_session_table_addr_sbit30_ebit33}
#define SESSION_KIVEC0_SESSION_ID_CURR                                          \
    k.{session_kivec0_session_id_curr_sbit0_ebit3...session_kivec0_session_id_curr_sbit28_ebit31}
#define SESSION_KIVEC0_NUM_SCANNABLES                                           \
    k.{session_kivec0_num_scannables_sbit0_ebit3...session_kivec0_num_scannables_sbit4_ebit4}
#define SESSION_KIVEC0_CB_CFG_DISCARD                                           \
    k.{session_kivec0_cb_cfg_discard}
    
#define SESSION_KIVEC_ICMP_TMO(_vec)                                            \
    k.{session_kivec##_vec##_icmp_tmo_sbit0_ebit7...session_kivec##_vec##_icmp_tmo_sbit8_ebit12}
#define SESSION_KIVEC_UDP_TMO(_vec)                                             \
    k.{session_kivec##_vec##_udp_tmo_sbit0_ebit2...session_kivec##_vec##_udp_tmo_sbit11_ebit13}
#define SESSION_KIVEC_UDP_EST_TMO(_vec)                                         \
    k.{session_kivec##_vec##_udp_est_tmo_sbit0_ebit4...session_kivec##_vec##_udp_est_tmo_sbit13_ebit13}
#define SESSION_KIVEC_TCP_SYN_TMO(_vec)                                         \
    k.{session_kivec##_vec##_tcp_syn_tmo_sbit0_ebit6...session_kivec##_vec##_tcp_syn_tmo_sbit7_ebit12}
#define SESSION_KIVEC_TCP_EST_TMO(_vec)                                         \
    k.{session_kivec##_vec##_tcp_est_tmo_sbit0_ebit1...session_kivec##_vec##_tcp_est_tmo_sbit10_ebit16}
#define SESSION_KIVEC_TCP_FIN_TMO(_vec)                                         \
    k.{session_kivec##_vec##_tcp_fin_tmo_sbit0_ebit0...session_kivec##_vec##_tcp_fin_tmo_sbit9_ebit12}
#define SESSION_KIVEC_TCP_TIMEWAIT_TMO(_vec)                                    \
    k.{session_kivec##_vec##_tcp_timewait_tmo_sbit0_ebit3...session_kivec##_vec##_tcp_timewait_tmo_sbit12_ebit12}
#define SESSION_KIVEC_TCP_RST_TMO(_vec)                                         \
    k.{session_kivec##_vec##_tcp_rst_tmo_sbit0_ebit6...session_kivec##_vec##_tcp_rst_tmo_sbit7_ebit12}
#define SESSION_KIVEC_OTHER_TMO(_vec)                                           \
    k.{session_kivec##_vec##_other_tmo_sbit0_ebit1...session_kivec##_vec##_other_tmo_sbit10_ebit12}
    
#define SESSION_KIVEC2_ICMP_TMO                                                 \
    SESSION_KIVEC_ICMP_TMO(2)
#define SESSION_KIVEC2_UDP_TMO                                                  \
    SESSION_KIVEC_UDP_TMO(2)
#define SESSION_KIVEC2_UDP_EST_TMO                                              \
    SESSION_KIVEC_UDP_EST_TMO(2)
#define SESSION_KIVEC2_TCP_SYN_TMO                                              \
    SESSION_KIVEC_TCP_SYN_TMO(2)
#define SESSION_KIVEC2_TCP_EST_TMO                                              \
    SESSION_KIVEC_TCP_EST_TMO(2)
#define SESSION_KIVEC2_TCP_FIN_TMO                                              \
    SESSION_KIVEC_TCP_FIN_TMO(2)
#define SESSION_KIVEC2_TCP_TIMEWAIT_TMO                                         \
    SESSION_KIVEC_TCP_TIMEWAIT_TMO(2)
#define SESSION_KIVEC2_TCP_RST_TMO                                              \
    SESSION_KIVEC_TCP_RST_TMO(2)
#define SESSION_KIVEC2_OTHER_TMO                                                \
    SESSION_KIVEC_OTHER_TMO(2)
    
#define SESSION_KIVEC3_ICMP_TMO                                                 \
    SESSION_KIVEC_ICMP_TMO(3)
#define SESSION_KIVEC3_UDP_TMO                                                  \
    SESSION_KIVEC_UDP_TMO(3)
#define SESSION_KIVEC3_UDP_EST_TMO                                              \
    SESSION_KIVEC_UDP_EST_TMO(3)
#define SESSION_KIVEC3_TCP_SYN_TMO                                              \
    SESSION_KIVEC_TCP_SYN_TMO(3)
#define SESSION_KIVEC3_TCP_EST_TMO                                              \
    SESSION_KIVEC_TCP_EST_TMO(3)
#define SESSION_KIVEC3_TCP_FIN_TMO                                              \
    SESSION_KIVEC_TCP_FIN_TMO(3)
#define SESSION_KIVEC3_TCP_TIMEWAIT_TMO                                         \
    SESSION_KIVEC_TCP_TIMEWAIT_TMO(3)
#define SESSION_KIVEC3_TCP_RST_TMO                                              \
    SESSION_KIVEC_TCP_RST_TMO(3)
#define SESSION_KIVEC3_OTHER_TMO                                                \
    SESSION_KIVEC_OTHER_TMO(3)
    
#define SESSION_KIVEC4_ICMP_TMO                                                 \
    SESSION_KIVEC_ICMP_TMO(4)
#define SESSION_KIVEC4_UDP_TMO                                                  \
    SESSION_KIVEC_UDP_TMO(4)
#define SESSION_KIVEC4_UDP_EST_TMO                                              \
    SESSION_KIVEC_UDP_EST_TMO(4)
#define SESSION_KIVEC4_TCP_SYN_TMO                                              \
    SESSION_KIVEC_TCP_SYN_TMO(4)
#define SESSION_KIVEC4_TCP_EST_TMO                                              \
    SESSION_KIVEC_TCP_EST_TMO(4)
#define SESSION_KIVEC4_TCP_FIN_TMO                                              \
    SESSION_KIVEC_TCP_FIN_TMO(4)
#define SESSION_KIVEC4_TCP_TIMEWAIT_TMO                                         \
    SESSION_KIVEC_TCP_TIMEWAIT_TMO(4)
#define SESSION_KIVEC4_TCP_RST_TMO                                              \
    SESSION_KIVEC_TCP_RST_TMO(4)
#define SESSION_KIVEC4_OTHER_TMO                                                \
    SESSION_KIVEC_OTHER_TMO(4)
    
#define SESSION_KIVEC5_ICMP_TMO                                                 \
    SESSION_KIVEC_ICMP_TMO(5)
#define SESSION_KIVEC5_UDP_TMO                                                  \
    SESSION_KIVEC_UDP_TMO(5)
#define SESSION_KIVEC5_UDP_EST_TMO                                              \
    SESSION_KIVEC_UDP_EST_TMO(5)
#define SESSION_KIVEC5_TCP_SYN_TMO                                              \
    SESSION_KIVEC_TCP_SYN_TMO(5)
#define SESSION_KIVEC5_TCP_EST_TMO                                              \
    SESSION_KIVEC_TCP_EST_TMO(5)
#define SESSION_KIVEC5_TCP_FIN_TMO                                              \
    SESSION_KIVEC_TCP_FIN_TMO(5)
#define SESSION_KIVEC5_TCP_TIMEWAIT_TMO                                         \
    SESSION_KIVEC_TCP_TIMEWAIT_TMO(5)
#define SESSION_KIVEC5_TCP_RST_TMO                                              \
    SESSION_KIVEC_TCP_RST_TMO(5)
#define SESSION_KIVEC5_OTHER_TMO                                                \
    SESSION_KIVEC_OTHER_TMO(5)
    
#define SESSION_KIVEC7_LIF                                                      \
    k.{session_kivec7_lif_sbit0_ebit7...session_kivec7_lif_sbit8_ebit10}
#define SESSION_KIVEC7_QTYPE                                                    \
    k.{session_kivec7_qtype}
#define SESSION_KIVEC7_POLLER_QSTATE_ADDR                                       \
    k.{session_kivec7_poller_qstate_addr_sbit0_ebit1...session_kivec7_poller_qstate_addr_sbit58_ebit63}
    
#define SESSION_KIVEC8_EXPIRY_SESSION_ID_BASE                                   \
    k.{session_kivec8_expiry_session_id_base}
#define SESSION_KIVEC8_SESSION_RANGE_FULL                                       \
    k.{session_kivec8_session_range_full}
#define SESSION_KIVEC8_SESSION_BURST_FULL                                       \
    k.{session_kivec8_session_burst_full}
#define SESSION_KIVEC8_EXPIRY_MAPS_FULL                                         \
    k.{session_kivec8_expiry_maps_full}
 
#define SESSION_KIVEC9_CB_CFG_DISCARDS                                          \
    k.{session_kivec9_cb_cfg_discards}
#define SESSION_KIVEC9_SCAN_INVOCATIONS                                         \
    k.{session_kivec9_scan_invocations}
#define SESSION_KIVEC9_EXPIRED_ENTRIES                                          \
    k.{session_kivec9_expired_entries_sbit0_ebit4...session_kivec9_expired_entries_sbit5_ebit7}
#define SESSION_KIVEC9_METRICS0_RANGE                                           \
    k.{session_kivec9_metrics0_start...session_kivec9_metrics0_end}

/*
 * Load an initial to_stageN kivec from d-vector.
 * Note: This involves bit truncation so neither phvwrpair nor phvwr with range
 * can be used.
 */
#define SESSION_KIVEC_AGE_TMO_LOAD_e(_dst)                                      \
    phvwr       p.{session_kivec##_dst##_icmp_tmo}, d.icmp_tmo;                 \
    phvwr       p.{session_kivec##_dst##_udp_tmo}, d.udp_tmo;                   \
    phvwr       p.{session_kivec##_dst##_udp_est_tmo}, d.udp_est_tmo;           \
    phvwr       p.{session_kivec##_dst##_tcp_syn_tmo}, d.tcp_syn_tmo;           \
    phvwr       p.{session_kivec##_dst##_tcp_est_tmo}, d.tcp_est_tmo;           \
    phvwr       p.{session_kivec##_dst##_tcp_fin_tmo}, d.tcp_fin_tmo;           \
    phvwr       p.{session_kivec##_dst##_tcp_timewait_tmo}, d.tcp_timewait_tmo; \
    phvwr.e     p.{session_kivec##_dst##_tcp_rst_tmo}, d.tcp_rst_tmo;           \
    phvwr       p.{session_kivec##_dst##_other_tmo}, d.other_tmo;               \

#define SESSION_KIVEC_AGE_TMO_DFLT_LOAD_e(_dst)                                 \
    phvwrpair   p.session_kivec2_icmp_tmo, SCANNER_ICMP_TMO_DFLT,               \
                p.session_kivec2_tcp_syn_tmo, SCANNER_TCP_SYN_TMO_DFLT;         \
    phvwrpair   p.session_kivec2_udp_tmo, SCANNER_UDP_TMO_DFLT,                 \
                p.session_kivec2_udp_est_tmo, SCANNER_UDP_EST_TMO_DFLT;         \
    phvwrpair   p.session_kivec2_tcp_fin_tmo, SCANNER_TCP_FIN_TMO_DFLT,         \
                p.session_kivec2_tcp_timewait_tmo, SCANNER_TCP_TIMEWAIT_TMO_DFLT;\
    phvwrpair.e p.session_kivec2_tcp_rst_tmo, SCANNER_TCP_RST_TMO_DFLT,         \
                p.session_kivec2_other_tmo, SCANNER_OTHER_TMO_DFLT;             \
    phvwr       p.session_kivec2_tcp_est_tmo, SCANNER_TCP_EST_TMO_DFLT;         \

/*
 * Propagate a to_stageN kivec to another
 */
#define SESSION_KIVEC_AGE_TMO_PROPAGATE(_dst, _src)                             \
    phvwr       p.{session_kivec##_dst##_icmp_tmo...                            \
                   session_kivec##_dst##_other_tmo},                            \
                k.{session_kivec##_src##_icmp_tmo_sbit0_ebit7...                \
                   session_kivec##_src##_other_tmo_sbit10_ebit12};              \

/*
 * Timestamp is in clock ticks with clock speed of 833Mhz, or
 * (833 * 1M) ticks per second, i.e., 1.2ns per tick. To conserve k-vec size,
 * the preferred unit is seconds which would require a division. And to reduce
 * MPU stalls, the division result will be referenced as late as possible.
 *
 * Reference Capri Clock spreadsheet
 * (https://docs.google.com/spreadsheets/d/1LNUhA67uG3bOdQh8Z3XaKZ_b_CRh9j_bm88uMkpCOqg/edit?ts=5e0b93ee#gi)
 * Timestamp bits 47:23 give interval of 1.01E-02 (which is very close to 1/100 s)
 */
#define SCANNER_TS_CALC(_timestamp_data)                                        \
    sub         r_timestamp, r_timestamp, _timestamp_data;                      \
    add         r_timestamp, r0, r_timestamp[47:23];                            \
    divi        r_timestamp, r_timestamp, 100;                                  \

#define SESSION_BRCASE_LKUP_TYPE(_lkup_type, _exp_bit, _tmo, _break_label)      \
  .brcase _lkup_type;                                                           \
    slt         c1, _tmo, r_timestamp;                                          \
    b           _break_label;                                                   \
    phvwri.c1   p.session_kivec0_##_exp_bit##_expired, 1;                       \

#define SESSION_BRCASE_LKUP_TYPE_UNUSED(_unused_type, _break_label)             \
  .brcase _unused_type;                                                         \
    b           _break_label;                                                   \
    nop;                                                                        \
    
#define SESSION_EXPIRY_CHECK_ALL_LKUP_TYPES(_exp_bit, _break_label,             \
                                            _icmp_tmo, _udp_tmo, udp_est_tmo,   \
                                            _tcp_syn_tmo, _tcp_est_tmo,         \
                                            _tcp_fin_tmo, _tcp_wait_tmo,        \
                                            _tcp_rst_tmo, _other_tmo)           \
  .brbegin;                                                                     \
    br          r_lkp_type[3:0];                                                \
    nop;                                                                        \
    SESSION_BRCASE_LKUP_TYPE(SCANNER_LKP_TYPE_ICMP, _exp_bit,                   \
                             _icmp_tmo, _break_label)                           \
    SESSION_BRCASE_LKUP_TYPE(SCANNER_LKP_TYPE_UDP, _exp_bit,                    \
                             _udp_tmo, _break_label)                            \
    SESSION_BRCASE_LKUP_TYPE(SCANNER_LKP_TYPE_UDP_EST, _exp_bit,                \
                             _udp_est_tmo, _break_label)                        \
    SESSION_BRCASE_LKUP_TYPE(SCANNER_LKP_TYPE_OTHER, _exp_bit,                  \
                             _other_tmo, _break_label)                          \
    SESSION_BRCASE_LKUP_TYPE(SCANNER_LKP_TYPE_TCP_SYN, _exp_bit,                \
                             _tcp_syn_tmo, _break_label)                        \
    SESSION_BRCASE_LKUP_TYPE(SCANNER_LKP_TYPE_TCP_EST, _exp_bit,                \
                             _tcp_est_tmo, _break_label)                        \
    SESSION_BRCASE_LKUP_TYPE(SCANNER_LKP_TYPE_TCP_FIN, _exp_bit,                \
                             _tcp_fin_tmo, _break_label)                        \
    SESSION_BRCASE_LKUP_TYPE(SCANNER_LKP_TYPE_TCP_TIMEWAIT, _exp_bit,           \
                             _tcp_wait_tmo, _break_label)                       \
    SESSION_BRCASE_LKUP_TYPE(SCANNER_LKP_TYPE_TCP_RST, _exp_bit,                \
                             _tcp_rst_tmo, _break_label)                        \
    SESSION_BRCASE_LKUP_TYPE_UNUSED(SCANNER_LKP_TYPE_UNUSED0, _break_label)     \
    SESSION_BRCASE_LKUP_TYPE_UNUSED(SCANNER_LKP_TYPE_UNUSED1, _break_label)     \
    SESSION_BRCASE_LKUP_TYPE_UNUSED(SCANNER_LKP_TYPE_UNUSED2, _break_label)     \
    SESSION_BRCASE_LKUP_TYPE_UNUSED(SCANNER_LKP_TYPE_UNUSED3, _break_label)     \
    SESSION_BRCASE_LKUP_TYPE_UNUSED(SCANNER_LKP_TYPE_UNUSED4, _break_label)     \
    SESSION_BRCASE_LKUP_TYPE_UNUSED(SCANNER_LKP_TYPE_UNUSED5, _break_label)     \
    SESSION_BRCASE_LKUP_TYPE_UNUSED(SCANNER_LKP_TYPE_UNUSED6, _break_label)     \
  .brend;                                                                       \
  
#define SESSION_BRCASE_LKUP_TYPE_e(_lkup_type, _exp_bit, _tmo)                  \
  .brcase _lkup_type;                                                           \
    slt.e       c1, _tmo, r_timestamp;                                          \
    phvwri.c1   p.session_kivec0_##_exp_bit##_expired, 1;                       \

#define SESSION_BRCASE_LKUP_TYPE_UNUSED_e(_unused_type)                         \
  .brcase _unused_type;                                                         \
    nop.e;                                                                      \
    nop;                                                                        \
    
#define SESSION_EXPIRY_CHECK_ALL_LKUP_TYPES_e(_exp_bit, _icmp_tmo,              \
                                              _udp_tmo, udp_est_tmo,            \
                                              _tcp_syn_tmo, _tcp_est_tmo,       \
                                              _tcp_fin_tmo, _tcp_wait_tmo,      \
                                              _tcp_rst_tmo, _other_tmo)         \
  .brbegin;                                                                     \
    br          r_lkp_type[3:0];                                                \
    nop;                                                                        \
    SESSION_BRCASE_LKUP_TYPE_e(SCANNER_LKP_TYPE_ICMP, _exp_bit, _icmp_tmo)      \
    SESSION_BRCASE_LKUP_TYPE_e(SCANNER_LKP_TYPE_UDP, _exp_bit, _udp_tmo)        \
    SESSION_BRCASE_LKUP_TYPE_e(SCANNER_LKP_TYPE_UDP_EST, _exp_bit, udp_est_tmo) \
    SESSION_BRCASE_LKUP_TYPE_e(SCANNER_LKP_TYPE_OTHER, _exp_bit, _other_tmo)    \
    SESSION_BRCASE_LKUP_TYPE_e(SCANNER_LKP_TYPE_TCP_SYN, _exp_bit, _tcp_syn_tmo)\
    SESSION_BRCASE_LKUP_TYPE_e(SCANNER_LKP_TYPE_TCP_EST, _exp_bit, _tcp_est_tmo)\
    SESSION_BRCASE_LKUP_TYPE_e(SCANNER_LKP_TYPE_TCP_FIN, _exp_bit, _tcp_fin_tmo)\
    SESSION_BRCASE_LKUP_TYPE_e(SCANNER_LKP_TYPE_TCP_TIMEWAIT, _exp_bit,         \
                               _tcp_wait_tmo)                                   \
    SESSION_BRCASE_LKUP_TYPE_e(SCANNER_LKP_TYPE_TCP_RST, _exp_bit, _tcp_rst_tmo)\
    SESSION_BRCASE_LKUP_TYPE_UNUSED_e(SCANNER_LKP_TYPE_UNUSED0)                 \
    SESSION_BRCASE_LKUP_TYPE_UNUSED_e(SCANNER_LKP_TYPE_UNUSED1)                 \
    SESSION_BRCASE_LKUP_TYPE_UNUSED_e(SCANNER_LKP_TYPE_UNUSED2)                 \
    SESSION_BRCASE_LKUP_TYPE_UNUSED_e(SCANNER_LKP_TYPE_UNUSED3)                 \
    SESSION_BRCASE_LKUP_TYPE_UNUSED_e(SCANNER_LKP_TYPE_UNUSED4)                 \
    SESSION_BRCASE_LKUP_TYPE_UNUSED_e(SCANNER_LKP_TYPE_UNUSED5)                 \
    SESSION_BRCASE_LKUP_TYPE_UNUSED_e(SCANNER_LKP_TYPE_UNUSED6)                 \
  .brend;                                                                       \

/*
 * Issue a session_info scan for _tbl per the given _round, provided the scan
 * falls within the given _num_scannables. The session to read is given
 * by r_session_info_addr, after which, it will be incremented to point
 * to the next adjacent session.
 */
#define SESSION_INFO_POSSIBLE_SCAN_INCR(_tbl, _round, _num_scannables,          \
                                        _pc, _break_label)                      \
    sle         c1, ((_round) * SESSION_MPU_TABLES_MAX) + ((_tbl) + 1),         \
                _num_scannables;                                                \
    bcf         [!c1], _break_label;                                            \
    nop;                                                                        \
    LOAD_TABLE_FOR_ADDR(_tbl, TABLE_LOCK_DIS, r_session_info_addr,              \
                        TABLE_SIZE_512_BITS, _pc)                               \
    add         r_session_info_addr, r_session_info_addr, SESSION_INFO_BYTES;   \

/*
 * The following 2 macros are similar to SESSION_INFO_POSSIBLE_SCAN_INCR(),
 * but with the following differences:
 * - There are 2 macros to allow the caller to reduce MPU stalls in
 *   between usage of the SCANNER_MS_CALC() macro and SESSION_EXPIRY_CHECK_ALL_LKUP_TYPES().
 * - The session_info to read is calculated using SESSION_KIVEC0_SESSION_ID_CURR
 *   together with _round and _tbl.
 */
#define SESSION_INFO_NUM_SCANNABLES_CHECK_CF(_cf, _tbl, _round,                 \
                                             _num_scannables)                   \
    sle         _cf, ((_round) * SESSION_MPU_TABLES_MAX) + ((_tbl) + 1),        \
                _num_scannables;                                                \
    add         r_session_id, SESSION_KIVEC0_SESSION_ID_CURR,                   \
                ((_round) * SESSION_MPU_TABLES_MAX) + (_tbl);                   \
    add         r_session_info_addr, SESSION_KIVEC0_SESSION_TABLE_ADDR,         \
                r_session_id, SESSION_INFO_BYTES_SHFT;                          \
    
#define SESSION_INFO_POSSIBLE_SCAN_CHECK_CF(_cf, _tbl, _pc, _break_label)       \
    bcf         [!_cf], _break_label;                                           \
    nop;                                                                        \
    LOAD_TABLE_FOR_ADDR(_tbl, TABLE_LOCK_DIS, r_session_info_addr,              \
                        TABLE_SIZE_512_BITS, _pc)                               \
                
/*
 * When there is no more session scanning to launch for session 0 (i.e., table 0),
 * the following is the alternative launch.
 */
#define SESSION_NO_MORE_SESSION0_ALT()                                          \
    SESSION_SUMMARIZE_LAUNCH(0, SESSION_KIVEC0_QSTATE_ADDR, session_summarize)  \
 
/*
 * When there is no more session scanning to launch for session 1 or 2 
 * (i.e., table 1 or 2), the following is the alternative launch.
 */
#define SESSION_NO_MORE_SESSION1_2_ALT()                                        \
    nop;                                                                        \

/*
 * When there is no more session scanning to launch for session 3 (i.e., table 3),
 * the following is the alternative launch.
 */
#define SESSION_NO_MORE_SESSION3_ALT()                                          \
    SESSION_METRICS0_TABLE3_COMMIT_LAUNCH(SESSION_KIVEC0_QSTATE_ADDR)           \

/*
 * Launch session_summarize for its designated stage, i.e., use lock if launching
 * from SESSION_SUMMARIZE_STAGE minus 1.
 */
#define SESSION_SUMMARIZE_LAUNCH(_tbl, _src_qaddr, _pc)                         \
    add         r_qstate_addr, _src_qaddr,                                      \
                SCANNER_SESSION_CB_TABLE_SUMMARIZE_OFFSET;                      \
    LOAD_TABLE_NO_ADDR(_tbl, _pc)                                               \
    mfspr       r_stage, spr_mpuid;                                             \
    slt         c1, r_stage[HW_MPU_SPR_MPUID_STAGE_SELECT],                     \
                SESSION_SUMMARIZE_STAGE - 1;                                    \
    phvwrpair.!c1 p.{common_te##_tbl##_phv_table_lock_en...                     \
                     common_te##_tbl##_phv_table_raw_table_size},               \
                  (TABLE_LOCK_EN << 3) | (TABLE_SIZE_512_BITS),                 \
                  p.common_te##_tbl##_phv_table_addr, r_qstate_addr;            \

#define SESSION_SUMMARIZE_LAUNCH_e(_tbl, _src_qaddr, _pc)                       \
    add         r_qstate_addr, _src_qaddr,                                      \
                SCANNER_SESSION_CB_TABLE_SUMMARIZE_OFFSET;                      \
    LOAD_TABLE_NO_ADDR(_tbl, _pc)                                               \
    mfspr       r_stage, spr_mpuid;                                             \
    slt.e       c1, r_stage[HW_MPU_SPR_MPUID_STAGE_SELECT],                     \
                SESSION_SUMMARIZE_STAGE - 1;                                    \
    phvwrpair.!c1 p.{common_te##_tbl##_phv_table_lock_en...                     \
                     common_te##_tbl##_phv_table_raw_table_size},               \
                  (TABLE_LOCK_EN << 3) | (TABLE_SIZE_512_BITS),                 \
                  p.common_te##_tbl##_phv_table_addr, r_qstate_addr;            \

/*
 * Load 64-bit immediate
 */
#define SCANNER_IMM64_LOAD(_reg, _imm64)                                        \
    addi        _reg, r0,  loword(_imm64);                                      \
    addui       _reg, reg, hiword(_imm64);                                      \
    
#define SCANNER_IMM64_LOAD_c(_cf, _reg, _imm64)                                 \
    addi._cf    _reg, r0,  loword(_imm64);                                      \
    addui._cf   _reg, reg, hiword(_imm64);                                      \

/*
 * Doorbell related
 */
#define SCANNER_DB_DATA_WITH_RING_INDEX(_index, _ring, _qid, _pid)              \
    add         r_db_data, _index, _ring, DB_RING_SHFT;                         \
    add         r_db_data, r_db_data, _qid, DB_QID_SHFT;                        \
    add         r_db_data, r_db_data, _pid, DB_PID_SHFT;                        \

#define SCANNER_DB_DATA(_qid)                                                   \
    add         r_db_data, r0, _qid, DB_QID_SHFT;                               \

#define SCANNER_DB_ADDR(_lif, _qtype, _sched_wr, _upd)                          \
    addi        r_db_addr, r0, DB_ADDR_BASE +                                   \
                               (((_upd) | (_sched_wr)) << DB_UPD_SHFT);         \
    add         r_db_addr, r_db_addr, _qtype, DB_TYPE_SHFT;                     \
    add         r_db_addr, r_db_addr, _lif, DB_LIF_SHFT;                        \

#define SCANNER_DB_ADDR_SCHED_EVAL(_lif, _qtype)                                \
    SCANNER_DB_ADDR(_lif, _qtype, DB_SCHED_UPD_EVAL, DB_IDX_UPD_NOP)            \

#define SCANNER_DB_ADDR_SCHED_RESET(_lif, _qtype)                               \
    SCANNER_DB_ADDR(_lif, _qtype, DB_SCHED_UPD_CLEAR, DB_IDX_UPD_NOP)           \

#define SCANNER_DB_ADDR_SCHED_PIDX_INC(_lif, _qtype)                            \
    SCANNER_DB_ADDR(_lif, _qtype, DB_SCHED_UPD_SET, DB_IDX_UPD_PIDX_INC)        \

/*
 * Timer related
 */
#ifndef TIMER_ADDR_LIF_SHFT
#define TIMER_ADDR_LIF_SHFT                     3
#endif

#define SCANNER_DB_ADDR_FAST_TIMER(_lif)                                        \
    addi        r_db_addr, r0, CAPRI_MEM_FAST_TIMER_START;                      \
    add         r_db_addr, r_db_addr, _lif, TIMER_ADDR_LIF_SHFT;                \

#define SCANNER_DB_ADDR_SLOW_TIMER(_lif)                                        \
    addi        r_db_addr, r0, CAPRI_MEM_SLOW_TIMER_START;                      \
    add         r_db_addr, r_db_addr, _lif, TIMER_ADDR_LIF_SHFT;                \

#define SCANNER_DB_DATA_TIMER_WITH_RING(_type, _qid, _ring, _delta_time)        \
    add         r_db_data, _type, _qid, TIMER_QID_SHFT;                         \
    or          r_db_data, r_db_data, _ring, TIMER_RING_SHFT;                   \
    or          r_db_data, r_db_data, _delta_time, TIMER_DELTA_TIME_SHFT;       \
        
#define SCANNER_DB_DATA_TIMER(_qid, _delta_time)                                \
    add         r_db_data, r0, _qid, TIMER_QID_SHFT;                            \
    or          r_db_data, r_db_data, _delta_time, TIMER_DELTA_TIME_SHFT;       \
   
/*
 * Metrics related
 */
#define SCANNER_METRICS_SET_V(_kivec_metrics, _val)                             \
    phvwr       p._kivec_metrics, _val;                                         \
  
#define SCANNER_METRICS_SET_V_c(_cf, _kivec_metrics, _val)                      \
    phvwr._cf   p._kivec_metrics, _val;                                         \
   
#define SCANNER_METRICS_TBLADD(_metrics, _key)                                  \
    sne         c1, _key, r0;                                                   \
    tbladd.c1   d._metrics, _key;                                               \

#define SCANNER_METRICS_TBLADD_e(_metrics, _key)                                \
    sne.e       c1, _key, r0;                                                   \
    tbladd.c1   d._metrics, _key;                                               \
    
#define SESSION_METRICS_SET(_metrics)                                           \
    SCANNER_METRICS_SET_V(session_kivec9_##_metrics, 1)                         \

#define SESSION_METRICS_SET_c(_cf, _metrics)                                    \
    SCANNER_METRICS_SET_V_c(_cf, session_kivec9_##_metrics, 1)                  \

#define SESSION_METRICS_CLR(_metrics)                                           \
    SCANNER_METRICS_SET_V(session_kivec9_##_metrics, 0)                         \

#define SESSION_METRICS_VAL_SET(_metrics, _val)                                 \
    SCANNER_METRICS_SET_V(session_kivec9_##_metrics, _val)                      \
  
#define SESSION_METRICS_PARAMS()                                                \
    .param      session_metrics0_commit;                                        \

/*
 * Launch metrics0 for its designated, i.e., use lock if launching from
 * SESSION_METRICS_STAGE minus 1.
 */
#define SESSION_METRICS0_TABLE3_COMMIT_LAUNCH(_src_qaddr)                       \
    add         r_qstate_addr, _src_qaddr,                                      \
                SCANNER_SESSION_CB_TABLE_METRICS0_OFFSET;                       \
    LOAD_TABLE_FOR_ADDR(3, TABLE_LOCK_EN, r_qstate_addr,                        \
                        TABLE_SIZE_512_BITS, session_metrics0_commit)           \
    mfspr       r_stage, spr_mpuid;                                             \
    slt         c1, r_stage[HW_MPU_SPR_MPUID_STAGE_SELECT],                     \
                SESSION_METRICS_STAGE - 1;                                      \
    phvwrpair.c1 p.{common_te3_phv_table_lock_en...                             \
                    common_te3_phv_table_raw_table_size},                       \
                 ((TABLE_LOCK_DIS) << 3) | (TABLE_SIZE_0_BITS),                 \
                 p.common_te3_phv_table_addr, r0;                               \
                  
#define SESSION_METRICS0_TABLE3_COMMIT_LAUNCH_e(_src_qaddr)                     \
    add         r_qstate_addr, _src_qaddr,                                      \
                SCANNER_SESSION_CB_TABLE_METRICS0_OFFSET;                       \
    LOAD_TABLE_FOR_ADDR(3, TABLE_LOCK_EN, r_qstate_addr,                        \
                        TABLE_SIZE_512_BITS, session_metrics0_commit)           \
    mfspr       r_stage, spr_mpuid;                                             \
    slt.e       c1, r_stage[HW_MPU_SPR_MPUID_STAGE_SELECT],                     \
                SESSION_METRICS_STAGE - 1;                                      \
    phvwrpair.c1 p.{common_te3_phv_table_lock_en...                             \
                    common_te3_phv_table_raw_table_size},                       \
                 ((TABLE_LOCK_DIS) << 3) | (TABLE_SIZE_0_BITS),                 \
                 p.common_te3_phv_table_addr, r0;                               \

#endif //__FTL_DEV_SHARED_ASM_H