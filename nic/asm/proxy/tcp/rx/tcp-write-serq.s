/*
 *    Implements the RX stage of the RxDMA P4+ pipeline
 */

#include "tcp-constants.h"
#include "tcp-phv.h"
#include "tcp-shared-state.h"
#include "tcp-macros.h"
#include "tcp-table.h"
#include "ingress.h"
#include "INGRESS_p.h"

struct phv_ p;
struct tcp_rx_write_serq_k k;
struct tcp_rx_write_serq_write_serq_d d;

%%
    .param          tcp_rx_stats_stage7_start
    .align

    /*
     * Global conditional variables
     */
tcp_rx_write_serq_stage6_start:
    CAPRI_CLEAR_TABLE0_VALID
    CAPRI_OPERAND_DEBUG(k.s6_s2s_debug_stage0_3_thread)
    CAPRI_OPERAND_DEBUG(k.s6_s2s_debug_stage4_7_thread)
    tblwr       d.debug_stage0_3_thread, k.s6_s2s_debug_stage0_3_thread
    tblwr       d.debug_stage4_7_thread, k.s6_s2s_debug_stage4_7_thread
    sne         c1, k.common_phv_write_arq, r0
    seq         c2, k.to_s6_payload_len, r0
    setcf       c3, [!c1 & c2]
    phvwri.c3   p.p4_intr_global_drop, 1
    phvwri.c3   p.p4_intr_no_data, 0
    bcf         [c1 | c2], flow_write_serq_process_done
    nop

    /* r4 is loaded at the beginning of the stage with current timestamp value */
    tblwr       d.curr_ts, r4
    /* if (k.write_serq) is set in a previous stage , trigger writes to serq slot */
    sne         c1, k.common_phv_write_serq, r0
    bcf         [!c1], flow_write_serq_process_done
    nop

dma_cmd_data:
    phvwri      p.p4_rxdma_intr_dma_cmd_ptr, TCP_PHV_RXDMA_COMMANDS_START

    /* Set the DMA_WRITE CMD for data */
    add         r1, k.to_s6_page, k.s6_s2s_ooo_offset
    addi        r3, r1, (NIC_PAGE_HDR_SIZE + NIC_PAGE_HEADROOM)

    /*
     * TODO : for SACK case, to_s6_payload_len constitutes the total
     * accumulated payload len. We need to pass only the current
     * packet length. For now the DMA works if we pass a larger length
     */
    CAPRI_DMA_CMD_PKT2MEM_SETUP(dma_cmd0_dma_cmd, r3, k.to_s6_payload_len)
    sne         c1, k.common_phv_ooo_rcv, r0
    bcf         [c1], dma_ooo_process

dma_cmd_descr:
    /* Set the DMA_WRITE CMD for descr */
    add         r5, k.to_s6_descr, r0
    addi        r1, r5, NIC_DESC_ENTRY_0_OFFSET

    phvwr       p.aol_A0, k.{to_s6_page}.dx
    addi        r3, r0, (NIC_PAGE_HDR_SIZE + NIC_PAGE_HEADROOM)
    phvwr       p.aol_O0, r3.wx
    phvwr       p.aol_L0, k.{to_s6_payload_len}.wx
    phvwr       p.aol_A1, r0
    phvwr       p.aol_O1, r0
    phvwr       p.aol_L1, r0
    phvwr       p.aol_A2, r0
    phvwr       p.aol_O2, r0
    phvwr       p.aol_L2, r0
    phvwr       p.aol_next_addr, r0

    CAPRI_DMA_CMD_PHV2MEM_SETUP(dma_cmd1_dma_cmd, r1, aol_A0, aol_next_pkt)
    addi        r7, r0, 1

    smeqb       c1, k.common_phv_debug_dol, TCP_DDOL_DONT_QUEUE_TO_SERQ, TCP_DDOL_DONT_QUEUE_TO_SERQ
    bcf         [c1], dma_cmd_write_rx2tx_shared
    nop
dma_cmd_serq_slot:
    CAPRI_OPERAND_DEBUG(d.{serq_pidx}.hx)
    sll         r5, d.{serq_pidx}.hx, NIC_SERQ_ENTRY_SIZE_SHIFT
    /* Set the DMA_WRITE CMD for SERQ slot */
    add         r1, r5, k.to_s6_xrq_base
    // increment serq pi as a part of ringing dorrbell

    phvwr       p.ring_entry_descr_addr, k.to_s6_descr
    CAPRI_DMA_CMD_PHV2MEM_SETUP(dma_cmd2_dma_cmd, r1, ring_entry_descr_addr, ring_entry_descr_addr)
    addi        r7, r7, 1
dma_cmd_write_rx2tx_shared:
    /* Set the DMA_WRITE CMD for copying rx2tx shared data from phv to mem */
    seq         c1, k.common_phv_pending_txdma, 1
    bcf         [!c1], tcp_serq_produce
    nop
    add         r5, TCP_TCB_RX2TX_SHARED_WRITE_OFFSET, k.common_phv_qstate_addr
    CAPRI_DMA_CMD_PHV2MEM_SETUP(dma_cmd3_dma_cmd, r5, rx2tx_snd_una, rx2tx_pad1_rx2tx)
    addi        r7, r7, 1

dma_cmd_write_rx2tx_extra_shared:
    /* Set the DMA_WRITE CMD for copying rx2tx extra shared data from phv to mem */
    add         r5, TCP_TCB_RX2TX_SHARED_EXTRA_OFFSET, k.common_phv_qstate_addr
    CAPRI_DMA_CMD_PHV2MEM_SETUP(dma_cmd4_dma_cmd, r5, rx2tx_extra_ato_deadline, rx2tx_extra__padding)
    addi        r7, r7, 1

    smeqb       c1, k.common_phv_debug_dol, TCP_DDOL_DEL_ACK_TIMER, TCP_DDOL_DEL_ACK_TIMER
    seq         c2, k.common_phv_pending_del_ack_send, 1
    bcf         [c1 | c2], dma_cmd_start_del_ack_timer
    nop

dma_cmd_ring_tcp_tx_doorbell:
    smeqb       c1, k.common_phv_debug_dol, TCP_DDOL_DONT_RING_TX_DOORBELL, TCP_DDOL_DONT_RING_TX_DOORBELL
    bcf         [c1], tcp_serq_produce

    CAPRI_DMA_CMD_RING_DOORBELL2(dma_cmd5_dma_cmd, LIF_TCP, 0,k.common_phv_fid, TCP_SCHED_RING_PENDING,
                                 0, db_data2_pid, db_data2_index)

    addi        r7, r7, 1
    b           tcp_serq_produce
    nop

dma_cmd_start_del_ack_timer:
    tbladd      d.ft_pi, 1
    phvwri      p.dma_cmd5_dma_cmd_addr, CAPRI_FAST_TIMER_ADDR(LIF_TCP)
    // result will be in r3
    CAPRI_OPERAND_DEBUG(k.s6_s2s_ato)
    CAPRI_TIMER_DATA(0, k.common_phv_fid, TCP_SCHED_RING_FT, k.s6_s2s_ato)
    phvwr       p.{db_data2_pid...db_data2_index}, r3.dx
    phvwri      p.dma_cmd5_dma_cmd_phv_start_addr, CAPRI_PHV_START_OFFSET(db_data2_pid)
    phvwri      p.dma_cmd5_dma_cmd_phv_end_addr, CAPRI_PHV_END_OFFSET(db_data2_index)
    phvwri      p.dma_cmd5_dma_cmd_type, CAPRI_DMA_COMMAND_PHV_TO_MEM
    phvwr       p.rx2tx_ft_pi, d.ft_pi

tcp_serq_produce:
    smeqb       c1, k.common_phv_debug_dol, TCP_DDOL_PKT_TO_SERQ, TCP_DDOL_PKT_TO_SERQ
    smeqb       c2, k.common_phv_debug_dol, TCP_DDOL_DONT_QUEUE_TO_SERQ, TCP_DDOL_DONT_QUEUE_TO_SERQ
    bcf         [!c1 & !c2], ring_doorbell
    smeqb       c1, k.common_phv_debug_dol, TCP_DDOL_DEL_ACK_TIMER, TCP_DDOL_DEL_ACK_TIMER
    smeqb       c2, k.common_phv_debug_dol, TCP_DDOL_DONT_RING_TX_DOORBELL, TCP_DDOL_DONT_RING_TX_DOORBELL
    setcf       c3, [!c1 & c2]
    phvwri.c3   p.dma_cmd4_dma_cmd_eop, 1
    CAPRI_DMA_CMD_STOP_FENCE(dma_cmd5_dma_cmd)
    b           flow_write_serq_process_done
    nop
ring_doorbell:
    tbladd      d.{serq_pidx}.hx, 1

    CAPRI_DMA_CMD_RING_DOORBELL2(dma_cmd6_dma_cmd, LIF_TLS, 0, k.common_phv_fid, 0,
                                 k.to_s6_xrq_pidx, db_data_pid, db_data_index)

    CAPRI_DMA_CMD_STOP_FENCE(dma_cmd6_dma_cmd)
    addi        r7, r7, 1

flow_write_serq_process_done:
stats:

    smeqb       c1, k.common_phv_debug_dol, TCP_DDOL_TEST_ATOMIC_STATS, TCP_DDOL_TEST_ATOMIC_STATS
    bcf         [!c1], pkts_rcvd_stats_update_start
    nop
    // Debug: Force increment of atomic stats
debug_pkts_rcvd_stats_update_start:
    phvwr       p.to_s7_pkts_rcvd, 1
    phvwr       p.to_s7_pages_alloced, 1
    phvwr       p.to_s7_desc_alloced, 1
    phvwr       p.to_s7_debug_num_phv_to_mem, r7
    phvwr       p.to_s7_debug_num_pkt_to_mem, 1
    // End debug stats increment, skip regular stats update
    b           tcp_write_serq_stats_end
    nop

    // Non-debug stats increment
pkts_rcvd_stats_update_start:
    CAPRI_STATS_INC(pkts_rcvd, 8, 1, d.pkts_rcvd)
pkts_rcvd_stats_update:
    CAPRI_STATS_INC_UPDATE(1, d.pkts_rcvd, p.to_s7_pkts_rcvd)
pkts_rcvd_stats_update_end:

    sne         c1, k.common_phv_ooo_in_rx_q, r0
    bcf         [c1], debug_num_phv_to_mem_stats_update_start
pages_alloced_stats_update_start:
    CAPRI_STATS_INC(pages_alloced, 8, 1, d.pages_alloced)
pages_alloced_stats_update:
    CAPRI_STATS_INC_UPDATE(1, d.pages_alloced, p.to_s7_pages_alloced)
pages_alloced_stats_update_end:

desc_alloced_stats_update_start:
    CAPRI_STATS_INC(desc_alloced, 8, 1, d.desc_alloced)
desc_alloced_stats_update:
    CAPRI_STATS_INC_UPDATE(1, d.desc_alloced, p.to_s7_desc_alloced)
desc_alloced_stats_update_end:

debug_num_phv_to_mem_stats_update_start:
    CAPRI_STATS_INC(debug_num_phv_to_mem, 8, r7, d.debug_num_phv_to_mem)
debug_num_phv_to_mem_stats_update:
    CAPRI_STATS_INC_UPDATE(r7, d.debug_num_phv_to_mem, p.to_s7_debug_num_phv_to_mem)
debug_num_phv_to_mem_stats_update_end:

debug_num_pkt_to_mem_stats_update_start:
    CAPRI_STATS_INC(debug_num_pkt_to_mem, 8, 1, d.debug_num_pkt_to_mem)
debug_num_pkt_to_mem_stats_update:
    CAPRI_STATS_INC_UPDATE(1, d.debug_num_pkt_to_mem, p.to_s7_debug_num_pkt_to_mem)
debug_num_pkt_to_mem_stats_update_end:
tcp_write_serq_stats_end:

    CAPRI_NEXT_TABLE0_READ_NO_TABLE_LKUP(tcp_rx_stats_stage7_start)
    nop.e
    nop

dma_ooo_process:
    b           stats
    phvwr       p.dma_cmd0_dma_cmd_eop, 1
    // TODO: need to send ack
