#include "capri.h"
#include "resp_rx.h"
#include "rqcb.h"
#include "common_phv.h"

struct resp_rx_phv_t p;
struct resp_rx_key_process_k_t k;
#struct key_entry_t d;

#define KEY_P r7
#define BASE_VA r6
#define LEN r5
#define LOG_PAGE_SIZE r4
#define MY_PT_BASE_ADDR r2
#define LOG_PT_SEG_SIZE r1
#define PT_SEG_P r5
#define PT_OFFSET r6
#define RAW_TABLE_PC r3

#define DMA_CMD_BASE r1
#define TMP r3
#define DB_ADDR r4
#define DB_DATA r5
#define GLOBAL_FLAGS r6
#define RQCB1_ADDR r7
#define T2_ARG r5
#define T2_KEY r6

#define SEL_T0_OR_T1_S2S_DATA(_dst_r, _cf) \
    cmov        _dst_r, _cf, offsetof(struct resp_rx_phv_t, common.common_t0_s2s_s2s_data), offsetof(struct resp_rx_phv_t, common.common_t1_s2s_s2s_data);
#define SEL_T0_OR_T1_K(_dst_r, _cf) \
    cmov        _dst_r, _cf, offsetof(struct resp_rx_phv_t, common.common_te0_phv_table_addr), offsetof(struct resp_rx_phv_t, common.common_te1_phv_table_addr); \
    CAPRI_SET_TABLE_0_VALID_C(_cf, 1); \
    CAPRI_SET_TABLE_1_VALID_C(!_cf, 1); \

#define LKEY_TO_PT_INFO_T   struct resp_rx_lkey_to_pt_info_t
#define COMPL_R_INV_RKEY_INFO_T struct resp_rx_compl_or_inv_rkey_info_t

%%
    .param  resp_rx_ptseg_process
    .param  resp_rx_compl_or_inv_rkey_process

.align
resp_rx_rqlkey_process:

    // lkey_p = lkey_p + lkey_info_p->key_id;
    //big-endian
    sub         KEY_P, (HBM_NUM_KEY_ENTRIES_PER_CACHE_LINE - 1), k.args.key_id
    add         KEY_P, r0, KEY_P, LOG_SIZEOF_KEY_ENTRY_T_BITS

    // if (!(lkey_p->acc_ctrl & ACC_CTRL_LOCAL_WRITE)) {
    CAPRI_TABLE_GET_FIELD(r1, KEY_P, KEY_ENTRY_T, acc_ctrl)
    //ARE_ALL_FLAGS_SET_B(c1, r1, ACC_CTRL_LOCAL_WRITE)
    and         r1, r1, k.args.acc_ctrl
    seq         c1, r1, k.args.acc_ctrl
    bcf         [!c1], error_completion
    CAPRI_TABLE_GET_FIELD(BASE_VA, KEY_P, KEY_ENTRY_T, base_va) //BD Slot

    //  if ((lkey_info_p->sge_va < lkey_p->base_va) ||
    //  ((lkey_info_p->sge_va + lkey_info_p->sge_bytes) > (lkey_p->base_va + lkey_p->len))) {
    CAPRI_TABLE_GET_FIELD(LEN, KEY_P, KEY_ENTRY_T, len)
    CAPRI_TABLE_GET_FIELD(LOG_PAGE_SIZE, KEY_P, KEY_ENTRY_T, log_page_size)
    slt         c1, k.args.va, BASE_VA 
    add         r1, BASE_VA, LEN 
    add         r2, k.args.va, k.args.len
    slt         c2, r1, r2
    bcf         [c1 | c2], error_completion
    CAPRI_TABLE_GET_FIELD(r1, KEY_P, KEY_ENTRY_T, pt_base) //BD Slot
    
    // my_pt_base_addr = (void *)
    //     (hbm_addr_get(PHV_GLOBAL_PT_BASE_ADDR_GET()) +
    //         (lkey_p->pt_base * sizeof(u64)));

    PT_BASE_ADDR_GET(r2)
    add         MY_PT_BASE_ADDR, r2, r1, CAPRI_LOG_SIZEOF_U64
    // now r2 has my_pt_base_addr
    

    // pt_seg_size = HBM_NUM_PT_ENTRIES_PER_CACHE_LINE * phv_p->page_size;
    // i.e., log_pt_seg_size = LOG_HBM_NUM_PT_ENTRIES_PER_CACHELINE + LOG_PAGE_SIZE
    add         LOG_PT_SEG_SIZE, LOG_HBM_NUM_PT_ENTRIES_PER_CACHELINE, LOG_PAGE_SIZE
    // now r1 has log_pt_seg_size

    // transfer_offset = lkey_info_p->sge_va - lkey_p->base_va + lkey_p->base_va % pt_seg_size;
    add         r3, r0, BASE_VA
    // base_va % pt_seg_size
    mincr       r3, LOG_PT_SEG_SIZE, r0
    // add sge_va
    add         r3, r3, k.args.va
    // subtract base_va
    sub         r3, r3, BASE_VA
    // now r3 has transfer_offset

    // transfer_offset % pt_seg_size
    add         r7, r0, r3
    mincr       r7, LOG_PT_SEG_SIZE, r0
    // (transfer_offset % pt_seg_size) + transfer_bytes
    add         r7, r7, k.args.len
    // get absolute pt_seg_size
    sllv        r6, 1, LOG_PT_SEG_SIZE
    // pt_seg_size <= ((transfer_offset % pt_seg_size) + transfer_bytes)
    sle         c1, r6, r7
    bcf         [!c1], aligned_pt
    nop

unaligned_pt:
    // pt_offset = transfer_offset % lkey_info_p->page_size;
    // pt_seg_p = (u64 *)my_pt_base_addr + (transfer_offset / lkey_info_p->page_size);

    // x = transfer_offset/log_page_size
    srlv        r5, r3, LOG_PAGE_SIZE
    // transfer_offset%log_page_size 
    add         r6, r0, r3
    mincr       PT_OFFSET, LOG_PAGE_SIZE, r0
    // now r6 has pt_offset
    add         PT_SEG_P, MY_PT_BASE_ADDR, r5, CAPRI_LOG_SIZEOF_U64
    // now r5 has pt_seg_p
    b           invoke_pt
    nop
aligned_pt:
    // pt_offset = transfer_offset % pt_seg_size;
    // pt_seg_p = (u64 *)my_pt_base_addr + ((transfer_offset / phv_p->page_size) / HBM_NUM_PT_ENTRIES_PER_CACHE_LINE);
    srlv        r5, r3, LOG_PT_SEG_SIZE
    add         r6, r0, r3
    mincr       PT_OFFSET, LOG_PT_SEG_SIZE, r0
    add         PT_SEG_P, MY_PT_BASE_ADDR, r5, CAPRI_LOG_SIZEOF_U64

invoke_pt:
    seq         c1, k.args.tbl_id, 0
    SEL_T0_OR_T1_K(r7, c1)
    CAPRI_SET_RAW_TABLE_PC(RAW_TABLE_PC, resp_rx_ptseg_process)
    CAPRI_NEXT_TABLE_I_READ(r7, CAPRI_TABLE_LOCK_DIS, CAPRI_TABLE_SIZE_512_BITS, RAW_TABLE_PC, PT_SEG_P)
    SEL_T0_OR_T1_S2S_DATA(r7, c1)
    CAPRI_SET_FIELD(r7, LKEY_TO_PT_INFO_T, pt_offset, PT_OFFSET)
    CAPRI_SET_FIELD(r7, LKEY_TO_PT_INFO_T, pt_bytes, k.args.len)
    CAPRI_SET_FIELD(r7, LKEY_TO_PT_INFO_T, dma_cmd_start_index, k.args.dma_cmd_start_index)
    CAPRI_SET_FIELD(r7, LKEY_TO_PT_INFO_T, sge_index, k.args.tbl_id)
    CAPRI_SET_FIELD(r7, LKEY_TO_PT_INFO_T, log_page_size, LOG_PAGE_SIZE)
    //CAPRI_SET_FIELD(r7, LKEY_TO_PT_INFO_T, dma_cmdeop, 0)
    
    seq         c3, k.args.dma_cmdeop, 1
    bcf         [!c3], exit
    add         GLOBAL_FLAGS, r0, k.global.flags // BD Slot

    IS_ANY_FLAG_SET(c2, GLOBAL_FLAGS, RESP_RX_FLAG_INV_RKEY | RESP_RX_FLAG_COMPLETION | RESP_RX_FLAG_RING_DBELL)

    bcf         [!c2], exit
    CAPRI_SET_FIELD_C(r7, LKEY_TO_PT_INFO_T, dma_cmdeop, 1, !c2) //BD Slot
    
    CAPRI_GET_TABLE_2_ARG(resp_rx_phv_t, T2_ARG)
    CAPRI_GET_TABLE_2_K(resp_rx_phv_t, T2_KEY)

    CAPRI_SET_FIELD(T2_ARG, COMPL_R_INV_RKEY_INFO_T, r_key, k.args.inv_r_key)
    CAPRI_SET_FIELD(T2_ARG, COMPL_R_INV_RKEY_INFO_T, dma_cmd_index, RESP_RX_DMA_CMD_CQ)
    CAPRI_SET_FIELD(T2_ARG, COMPL_R_INV_RKEY_INFO_T, tbl_id, TABLE_2)

    RQCB1_ADDR_GET(RQCB1_ADDR)
    CAPRI_SET_RAW_TABLE_PC(RAW_TABLE_PC, resp_rx_compl_or_inv_rkey_process)
    CAPRI_NEXT_TABLE_I_READ(T2_KEY, CAPRI_TABLE_LOCK_DIS, CAPRI_TABLE_SIZE_512_BITS, RAW_TABLE_PC, RQCB1_ADDR)

exit:
    nop.e
    nop

error_completion:
    add         GLOBAL_FLAGS, r0, k.global.flags
    IS_ANY_FLAG_SET(c1, GLOBAL_FLAGS, RESP_RX_FLAG_SEND | RESP_RX_FLAG_COMPLETION)

    phvwr       p.ack_info.aeth.syndrome, k.args.nak_code
    phvwr       p.cqwqe.status, CQ_STATUS_LOCAL_ACC_ERR

    // set error disable flag such that ptseg code wouldn't enqueue
    // DMA commands
    or          GLOBAL_FLAGS, GLOBAL_FLAGS, RESP_RX_FLAG_ERR_DIS_QP
    // if it is send and error is encourntered, even first/middle packets
    // should generate completion queue error.
    // for write, only last/only packet will checkout a descriptor and only 
    // in that case COMPLETION flag is set. In case of first/middle, we don't 
    // need to generate completion queue entry.
    or.c1       GLOBAL_FLAGS, GLOBAL_FLAGS, RESP_RX_FLAG_COMPLETION
    
    add r3, r0, offsetof(struct phv_, common_global_global_data)
    CAPRI_SET_FIELD(r3, PHV_GLOBAL_COMMON_T, flags, GLOBAL_FLAGS)

    RQCB1_ADDR_GET(RQCB1_ADDR)
    DMA_CMD_STATIC_BASE_GET(DMA_CMD_BASE, RESP_RX_DMA_CMD_START_FLIT_ID, RESP_RX_DMA_CMD_ACK)

    // prepare for NAK
    RESP_RX_POST_ACK_INFO_TO_TXDMA(DMA_CMD_BASE, RQCB1_ADDR, TMP, \
                                   k.global.lif,
                                   k.global.qtype,
                                   k.global.qid,
                                   DB_ADDR, DB_DATA)
    
    bcf     [!c1],  exit
    DMA_SET_END_OF_CMDS_C(DMA_CMD_PHV2MEM_T, DMA_CMD_BASE, !c1) //BD Slot

    
    CAPRI_GET_TABLE_2_ARG(resp_rx_phv_t, T2_ARG)
    CAPRI_GET_TABLE_2_K(resp_rx_phv_t, T2_KEY)

    CAPRI_SET_FIELD(T2_ARG, COMPL_R_INV_RKEY_INFO_T, dma_cmd_index, RESP_RX_DMA_CMD_CQ)
    CAPRI_SET_FIELD(T2_ARG, COMPL_R_INV_RKEY_INFO_T, tbl_id, TABLE_2)

    CAPRI_SET_RAW_TABLE_PC(RAW_TABLE_PC, resp_rx_compl_or_inv_rkey_process)
    CAPRI_NEXT_TABLE_I_READ(T2_KEY, CAPRI_TABLE_LOCK_DIS, CAPRI_TABLE_SIZE_512_BITS, RAW_TABLE_PC, RQCB1_ADDR)

    //clear both lkey0 and lkey1 table valid bits
    CAPRI_SET_TABLE_0_VALID(0)
    CAPRI_SET_TABLE_1_VALID(0)
    
    nop.e
    nop
