/*****************************************************************************
 *  roce_cq_cb_pop : Check the ROCE CQ QPCB and see if there's anything to be
 *                   popped. If so increment the working index and load the
 *                   queue entry.
 *****************************************************************************/

#include "storage_asm_defines.h"
#include "ingress.h"
#include "INGRESS_p.h"


struct s0_tbl_k k;
// Use q_state_push d-vector as the stage 0 d-vector has space for action-pc
struct s5_tbl_roce_cq_cb_push_d d;
struct phv_ p;

%%

storage_tx_roce_cq_cb_pop_start:
   // If queue is empty, exit
   //QUEUE_EMPTY(d.p_ndx, d.c_ndx, clear_doorbell)
   // HACK: Until little pragma is avaialble in NCC
   QUEUE_EMPTY(d.{p_ndx}.hx, d.c_ndx, clear_doorbell)

   // Pop the entry from the queue. Note: The working consumer index is updated
   // in the pop operation to ensure that 2 consumers don't pop the same entry.
   // The update of the consumer index happens via DMA write to c_ndx only after 
   // the popped entry has been fully consumed in subsequent stages. Also, the
   // w_ndx to be used is saved in GPR r6 for use later as the tblmincr alters 
   // the d-vector.
   add		r6, r0, d.w_ndx
   QUEUE_POP(d.w_ndx, d.num_entries)

   // Store fields needed in the K+I vector into the PHV
   phvwr	p.storage_kivec0_w_ndx, d.w_ndx
   phvwr	p.storage_kivec0_dst_qaddr, d.xlate_addr
   phvwr	p.storage_kivec1_src_qaddr, STAGE0_KIVEC_QADDR
   phvwr	p.storage_kivec1_src_lif, STAGE0_KIVEC_LIF
   phvwr	p.storage_kivec1_src_qtype, STAGE0_KIVEC_QTYPE
   phvwr	p.storage_kivec1_src_qid, STAGE0_KIVEC_QID
   
   // HACK: This is because RDMA base address is only 32 bits and we are 
   //       passing a host based queue here
   // TODO: Fix this and remove hack after we resolve this with RDMA folks
   addi		r7, r0, 1
   sll		r7, r7, 63
   add		r7, r7, d.base_addr
   

   // Set the table and program address for the next stage to process
   // the popped entry (based on the working consumer index in GPR r6).
   LOAD_TABLE_FOR_INDEX(r7, r6, d.entry_size, d.entry_size,
                        d.next_pc)
clear_doorbell:
   // Update the queue doorbell to clear the scheduler bit
   QUEUE_POP_DOORBELL_CLEAR

   // Setup the start and end DMA pointers to the doorbell pop
   DMA_PTR_SETUP(dma_p2m_0_dma_cmd_pad, dma_p2m_0_dma_cmd_eop,
                 p4_txdma_intr_dma_cmd_ptr)

   // Nothing more to process in subsequent stages
   LOAD_NO_TABLES
