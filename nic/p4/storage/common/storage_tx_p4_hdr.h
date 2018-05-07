/*****************************************************************************
 * storage_tx_p4_hdr.h: Defintions needed for storage_tx P4+ program
 *****************************************************************************/
 
#ifndef STORAGE_TX_P4_HDR_H
#define STORAGE_TX_P4_HDR_H

#include "storage_p4_hdr.h"


// Generic Queue State. Total size can be 64 bytes at most.
header_type q_state_t {
  fields {
    pc_offset	: 8;	// Program counter (relative offset)
    rsvd	: 8;	// Hardware reserved field
    cosA	: 4;	// Cos value A
    cosB	: 4;	// Cos value B
    cos_sel	: 8;	// Cos selector
    eval_last	: 8;	// Evaluator of "work ready" for ring
    total_rings	: 4;	// Total number of rings used by this qstate
    host_rings	: 4;	// Number of host facing rings used by this qstate
    pid		: 16;	// PID value to be compared with that from host
    p_ndx	: 16;	// Producer Index
    c_ndx	: 16;	// Consumer Index
    w_ndx	: 16;	// Working consumer index
    num_entries	: 16;	// Number of queue entries (power of 2 of this value)
    base_addr	: 64;	// Base address of queue entries
    entry_size	: 16;	// Size of each queue entry
    next_pc	: 28;	// Next program's PC
    dst_lif	: 11;	// Destination LIF number
    dst_qtype	: 3;	// Destination LIF type (within the LIF)
    dst_qid	: 24;	// Destination queue number (within the LIF)
    dst_qaddr	: 34;	// Destination queue state address
    vf_id	: 16;   // VF id (valid only for NVME LIF)
    sq_id	: 16;   // Submission queue id (valid only for NVME LIF)
    ssd_bm_addr	: 34;	// Pointer to bitmap which is used to save SSD commands
    ssd_q_num	: 16;	// Number of entries in the SSD priority queue
    ssd_q_size	: 16;	// Size of each queue state entry in SSD priority queue
    ssd_ci_addr	: 34;	// Address of the consumer index in the SSD qstate
    desc1_next_pc_valid: 1;
    desc1_next_pc: 28;	// desc bytes 64-127 next program's PC
    pad		: 43;	// Align to 64 bytes
  }
}

// Pririority Queue State. Total size can be 64 bytes at most.
header_type pri_q_state_t {
  fields {
    pc_offset	: 8;	// Program counter (relative offset)
    rsvd	: 8;	// Hardware reserved field
    cosA	: 4;	// Cos value A
    cosB	: 4;	// Cos value B
    cos_sel	: 8;	// Cos selector
    eval_last	: 8;	// Evaluator of "work ready" for ring
    host_rings	: 4;	// Number of host facing rings used by this qstate
    total_rings	: 4;	// Total number of rings used by this qstate
    pid		: 16;	// PID value to be compared with that from host
    p_ndx_hi	: 16;	// Producer Index (high priority)
    c_ndx_hi	: 16;	// Consumer Index (high priority)
    p_ndx_med	: 16;	// Producer Index (medium priority)
    c_ndx_med	: 16;	// Consumer Index (medium priority)
    p_ndx_lo	: 16;	// Producer Index (low priority)
    c_ndx_lo	: 16;	// Consumer Index (low priority)
    w_ndx_hi	: 16;	// Working consumer index (high priority)
    w_ndx_med	: 16;	// Working consumer index (medium priority)
    w_ndx_lo	: 16;	// Working consumer index (low priority)
    num_entries	: 16;	// Number of queue entries (power of 2 of this value)
    base_addr	: 64;	// Base address of queue entries
    entry_size	: 16;	// Size of each queue entry
    hi_weight	: 8;	// Weight of high pri queue
    med_weight	: 8;	// Weight of medium pri queue
    lo_weight	: 8;	// Weight of low pri queue
    hi_running	: 8;	// Number of commands running from high pri queue
    med_running	: 8;	// Number of commands running from medium pri queue
    lo_running	: 8;	// Number of commands running from low pri queue
    num_running	: 8;	// Total number of commands running
    max_cmds	: 8;	// Maximum number of commands than can be running
    next_pc	: 28;	// Next program's PC
    dst_lif	: 11;	// Destination LIF number
    dst_qtype	: 3;	// Destination LIF type (within the LIF)
    dst_qid	: 24;	// Destination queue number (within the LIF)
    dst_qaddr	: 34;	// Destination queue state address
    ssd_bm_addr	: 34;	// Pointer to bitmap which is used to save SSD commands
    pad		: 10;	// Align to 64 bytes
  }
}

// Queue State for access across the PCI bus - e.g. NVME driver, SSD, PVM. 
// Total size can be 64 bytes at most.
header_type pci_q_state_t {
  fields {
    pc_offset	: 8;	// Program counter (relative offset)
    rsvd	: 8;	// Hardware reserved field
    cosA	: 4;	// Cos value A
    cosB	: 4;	// Cos value B
    cos_sel	: 8;	// Cos selector
    eval_last	: 8;	// Evaluator of "work ready" for ring
    total_rings	: 4;	// Total number of rings used by this qstate
    host_rings	: 4;	// Number of host facing rings used by this qstate
    pid		: 16;	// PID value to be compared with that from host
    p_ndx	: 16;	// Producer Index
    c_ndx	: 16;	// Consumer Index
    w_ndx	: 16;	// Working consumer index
    num_entries	: 16;	// Number of queue entries (power of 2 of this value)
    base_addr	: 64;	// Base address of queue entries
    entry_size	: 16;	// Size of each queue entry
    push_addr	: 64;	// Address where the push data (pndx) is to be written
    intr_addr	: 64;	// Address where the MSI-X interrupt is to be raised
    intr_data	: 32;	// Preformed data for raising the MSI-X interrupt
    intr_en	:  1;	// 1 => Fire the MSI-X interrupt, 0 => don't fire
    pad		: 143;	// Align to 64 bytes
  }
}

// Barco ring 
header_type barco_ring_t {
  fields {
    p_ndx	: 32;	// Producer Index
  }
}


// Trailer in the PVM cmd containing source information
header_type pvm_cmd_trailer_t {
  fields {
    vf_id	: 16;	// VF number
    sq_id	: 16;	// Submission queue id
    num_prps	: 8;	// Number of additional PRPs
  }
}

// Trailer in the PVM status used to push the status back
header_type pvm_sta_trailer_t {
  fields {
    // Information passed back by PVM
    dst_lif	: 11;	// Destination LIF number
    dst_qtype	: 3;	// Destination LIF type (within the LIF)
    dst_qid	: 24;	// Destination queue number (within the LIF)
    dst_qaddr	: 34;	// Destination queue state address
  }
}

// Implemented as an array indexed by ROCE QP+1. QP0 is reserved for R2N SQ.
// Note: Total size is made 64 bytes to fit in the d-vector. With 64 such 
//       SQs planned for PVM use, there should not be a space constraint. 
//       This can be revisited to pack more entries in one d-vector if 
//       the number of queues need to be scaled much higher.
header_type roce_sq_xlate_entry_t {
  fields {
    next_pc	: 28;	// Next program's PC
    dst_lif	: 11;	// Destination LIF number
    dst_qtype	: 3;	// Destination LIF type (within the LIF)
    dst_qid	: 24;	// Destination queue number (within the LIF)
    dst_qaddr	: 34;	// Destination queue state address
    pad		: 412;	// Align to 64 byte boundary
  }
}

/********************************************************************
 *
 * R2N Buffer format (size of each entry in bytes indicated []):
 *
 * 1. roce_rq_wqe_t					[64]
 * 2. nvme_be_prp_list_t				[64]
 * 3. nvme_be_cmd_hdr_t + 376 bits pad + nvme_be_cmd_t	[128]
 * 4. nvme_be_sta_hdr_t + nvme_be_sta_t + 256 bits pad	[64]
 * 5. roce_sq_wqe_t (for sending write data over ROCE)	[64]
 * 6. roce_sq_wqe_t (for sending status over ROCE)	[64]
 *
 * Notes:
 *  a. nvme_be_cmd_t contains a ptr to the R2N buffer start.
 *  b. On the wire data from #3 to #6 is sent.
 *  c. ROCE gives ptr to #3 in its CQ WQE. R2N buffer ptr is derived.
 *  d. PVM gives ptr to #3 in its SQ WQE. R2N buffer ptr is derived.
 *  e. #1, #2, #5, #6 are not used by PVM for local commands.
 *
********************************************************************/

// WQE format of R2N layer. Used by:
// 1. R2N's SQ/CQ with local PVM for local target.
// 2. NVME backend's priority SQ/CQ with R2N.
// 3. R2N's HQ with local PVM for ROCE buf posting
header_type r2n_wqe_t {
  fields {
    // Note: These fields are set in the WQE from PVM and the WQE from ROCE
    handle		: 64;	// Pointer to R2N buffer (or) NVME BE command 
    data_size		: 32;	// Size pointed to by handle
    opcode		: 16;	// Each use case has a distinct opcode
    status		: 16;	// Success/failure status

    // Note: These fields are set in the WQE from PVM for ringing an additional
    //       doorbell on the response handling from the SSD on a per WQE basis.
    //
    // 1. Set in the WQE from PVM when sequencer is used for local target
    // 2. Only when db_enable is set to 1, the other db_* fields are valid.
    //    Also db_enable needs to be 2 bits for byte boundary alignment.
    // 3. The status is sent to PVM's R2N CQ and is not governed by db_enable.
    db_enable		: 2;	// Whether doorbell needs to be rung 
    db_lif		: 11;	// Doorbell LIF number
    db_qtype		: 3;	// Doorbell LIF type (within the LIF)
    db_qid		: 24;	// Doorbell queue number (within the LIF)
    db_index		: 16;	// Doorbell pindex

    // Note: This field is set to 0 in the WQE sent by PVM and set to 1 in the 
    //       WQE sent by ROCE CQ handler
    is_remote		: 8;	// Is the command from local or remote PVM	

    // Note: These fields are set in the WQE from PVM or ROCE path to provide
    //       a destination after complete processing of the R2N WQE.
    //
    // 1. When these fields are set in the WQE from ROCE, they point to the 
    //    PVM's ROCE SQ queue state structure and its doorbell. The is_remote
    //    flag is set to 1 in this path. These fields are looked up in the 
    //    response handler to determine the destination queue.
    //
    // 2. When these fields are set in the WQE from PVM, they point to the 
    //    ROCE RQ to post the R2N buffer. The is_remote flag is set to 0 
    //    in this path.
    dst_lif		: 11;	// LIF number used for response
    dst_qtype		: 3;	// LIF type (within the LIF) used for response
    dst_qid		: 24;	// Queue number (within the LIF) used for response
    dst_qaddr		: 34;	// Queue state address used for response

    // Note: These fields are not set in the WQE from PVM or the WQE from ROCE. 
    //       These are internally set and used by R2N module.
    src_queue_id	: 32;	// ROCE source queue id
    ssd_handle		: 16;	// SSD handle to select NVME backend
    io_priority		: 8;	// I/O priority to select ring with the queue
    is_read		: 8;	// If NVME command is a read
    r2n_buf_handle	: 64;	// Back pointer to the R2N buffer
    nvme_cmd_cid	: 16;	// Command identifier
    pri_qaddr		: 34;	// Priority queue state address for status
    iob_addr		: 34;	// IO buffer address from initiator
    pad			: 4;	// Align to byte boundary
    // Note: The total size of this cannot exceed 64 bytes
  }
}


// Bitmap of the list of outstanding commands sent to the SSD.
// Assumes a max of 64 outstanding per SSD.
header_type ssd_cmds_t {
  fields {
    bitmap	: 64;	// Max 64 outstanding commands per SSD
  }
}

// SSD's consumder index value stored in PHV for DMA
header_type ssd_ci_t {
  fields {
    c_ndx	: 16;	// SSD's Consumer index value
  }
}


// Sequencer metadata for PDMA
header_type seq_pdma_entry_t {
  fields {
    next_db_addr	: 64;	// 64 bit address of the next doorbell to ring
    next_db_data	: 64;	// 64 bit data of the next doorbell to ring
    src_addr		: 64;	// Source memory address for PDMA (HBM or Host)
    dst_addr		: 64;	// Destination memory address for PDMA (HBM or Host)
    data_size		: 32;	// Data size to be transferred 
    src_lif_override	: 1;	// Override the source LIF in the PDMA
    src_lif		: 11;	// Source LIF id used to override
    dst_lif_override	: 1;	// Override the source LIF in the PDMA
    dst_lif		: 11;	// Destination LIF id used to override
    intr_addr		: 64;	// Address where the MSI-X interrupt is to be raised
    intr_data		: 32;	// Preformed data for raising the MSI-X interrupt
    next_db_en		:  1;	// 1 => Ring next sequencer doorbell, 0 => don't ring
    intr_en		:  1;	// 1 => Fire the MSI-X interrupt, 0 => don't fire
				// NOTE: Don't enable intr_en and next_db_en together
				//       as only one will be serviced
				// Order of evaluation: 1. next_db_en 2. intr_en
  }
}

// Sequencer metadata for pushing Barco descriptor
header_type seq_barco_entry_t {
  fields {
    barco_desc_addr	: 64;	// Address of the descriptor to push
    barco_pndx_addr	: 34;	// 64 bit address of the doorbell to ring
    barco_pndx_shadow_addr: 34;
    barco_desc_size	:  4;	// Size of the descriptor to push
    barco_pndx_size	:  3;	// Size of the ring state to be loaded
    barco_ring_size	:  5;	// log2(ring_size)
    barco_ring_addr	: 34;	// Address of the ring

    // special test batch mode: pndx value is given in entry
    barco_batch_pndx: 16;
    barco_batch_mode: 1;
    barco_batch_last: 1;
  }
}

// Sequencer metadata compression status entry
header_type seq_comp_status_desc0_t {
  fields {
    next_db_addr	: 64;	// 64 bit address of the next doorbell to ring
    next_db_data	: 64;	// 64 bit data of the next doorbell to ring,
    	                    // also represents barco_desc_addr when next_db_action_barco_push is set
    barco_pndx_addr	: 34;	// producer index address
    barco_pndx_shadow_addr: 34;
    barco_desc_size	:  4;	// descriptor size (power of 2 exponent)
    barco_pndx_size	:  3;	// producer index size (power of 2 exponent)
    barco_ring_size	:  5;	// log2(ring_size)
    status_hbm_addr	: 64;	// Address where compression status will be placed
    status_host_addr    : 64;	// Address where compression status will be placed
    intr_addr		: 64;	// Address where interrupt needs to be written
    intr_data		: 32;	// Data that needs to be written for interrupt
    status_len		: 16;	// Length of the compression status
    status_dma_en	:  1;	// 1 => DMA status, 0 => don't DMA 
    next_db_en		:  1;	// 1 => Ring next sequencer doorbell, 0 => don't ring
    intr_en		:  1;	// 1 => Fire the MSI-X interrupt, 0 => don't fire
				// NOTE: Don't enable intr_en and next_db_en together
				//       as only one will be serviced
				// Order of evaluation: 1. next_db_en 2. intr_en
    next_db_action_barco_push: 1; // next_db action is actually Barco push
  }
}

header_type seq_comp_status_desc1_t {
  fields {
    src_hbm_pa		: 64;
    dst_hbm_pa		: 64;
    sgl_pdma_in_pa	: 64;	// SGL in/out addresses for PDMA
    sgl_pdma_out_pa	: 64;
    sgl_vec_pa	    : 64;   // SGL vector for multi-block hash
    pad_buf_pa	    : 64;   // pad buffer address
    data_len		: 16;	// Length of the compression data
    pad_len_shift	:  5;	// Padding length (power of 2)
    stop_chain_on_error	:  1; // 1: don't ring next DB on error
    data_len_from_desc	:  1;	// 1 => Use the data length in the descriptor, 
				// 0 => Use the data lenghth in the status
    aol_pad_en     :  1;
    sgl_pad_hash_en:  1;
    sgl_pdma_en         :  1;
    copy_src_dst_on_error: 1;
  }
}

// Compression destination SGL metadata
header_type seq_comp_sgl_t {
  fields {
    addr0		: 64;	// SGL data buffer 0 address
    addr1		: 64;	// SGL data buffer 1 address
    addr2		: 64;	// SGL data buffer 2 address
    addr3		: 64;	// SGL data buffer 3 address
    len0		: 16;	// SGL data buffer 0 length
    len1		: 16;	// SGL data buffer 1 length
    len2		: 16;	// SGL data buffer 2 length
    len3		: 16;	// SGL data buffer 3 length
  }
}

// Compression status metadata
header_type seq_comp_status_t {
  fields {
    status		: 16;	// Valid bit and error status
    output_data_len	: 16;	// Output bits
    rsvd		: 32;	// Reserved
  }
}

// Sequencer metadata XTS status entry
header_type seq_xts_status_desc_t {
  fields {
    next_db_addr	: 64;	// 64 bit address of the next doorbell to ring
    next_db_data	: 64;	// 64 bit data of the next doorbell to ring
                            // also represents barco_desc_addr when next_db_action_barco_push is set
    barco_pndx_addr	: 34;	// producer index address
    barco_pndx_shadow_addr: 34;
    barco_desc_size	:  4;	// descriptor size (power of 2 exponent)
    barco_pndx_size	:  3;	// producer index size (power of 2 exponent)
    barco_ring_size	:  5;	// log2(ring_size)
    status_hbm_addr	: 64;	// Address where HW compression status was placed
    status_host_addr    : 64;	// Address where a copy of above status can be made
    intr_addr		: 64;	// Address where interrupt needs to be written
    intr_data		: 32;	// Data that needs to be written for interrupt
    status_len		: 16;	// Length of the compression status
    status_dma_en	:  1;	// 1 => DMA status, 0 => don't DMA 
    next_db_en		:  1;	// 1 => Ring next sequencer doorbell, 0 => don't ring
    intr_en		:  1;	// 1 => Fire the MSI-X interrupt, 0 => don't fire
				// NOTE: Don't enable intr_en and next_db_en together
				//       as only one will be serviced
				// Order of evaluation: 1. next_db_en 2. intr_en
    next_db_action_barco_push: 1; // next_db action is actually Barco push
    stop_chain_on_error :  1;   // 1: don't ring next DB on error
  }
}

// XTS status metadata
header_type seq_xts_status_t {
  fields {
    err			: 64;	// Error status (0: success: >0: failure)
  }
}

// Barco AOL (used by XTS)
header_type barco_aol_t {
  fields {
    A0              : 64;
    O0              : 32;
    L0              : 32;
    A1              : 64;
    O1              : 32;
    L1              : 32;
    A2              : 64;
    O2              : 32;
    L2              : 32;
    next_addr       : 64;
    rsvd            : 64;
  }
}

// Barco SGL (used by comp/decomp engines)
header_type barco_sgl_t {
  fields {
    addr0		: 64;	// SGL data buffer 0 address
    len0		: 32;	// SGL data buffer 0 length
    rsvd0		: 32;
    addr1		: 64;	// SGL data buffer 1 address
    len1		: 32;	// SGL data buffer 1 length
    rsvd1		: 32;
    addr2		: 64;	// SGL data buffer 2 address
    len2		: 32;	// SGL data buffer 2 length
    rsvd2		: 32;
    link        : 64;
    rsvd        : 64;
  }
}

#define BARCO_SGL_DESC_SIZE         64
#define BARCO_SGL_DESC_SIZE_SHIFT   6

// Accelerator chaining state structure:
// these fields are grouped together to make it easier to
// overlay the structure over other structs
header_type acc_chain_state_t {
  fields {
    pad_buf_addr    : 64;
    data_len        : 32;
    pad_len         : 32;
    total_len       : 32;
  }
}

// Storage K+I vectors

// kivec0: header union with stage_2_stage for table 0 (160 bits max)
header_type storage_kivec0_t {
  fields {
    w_ndx		: 16;	// Working consumer index
    dst_lif		: 11;	// Destination LIF number
    dst_qtype		: 3;	// Destination LIF type (within the LIF)
    dst_qid		: 24;	// Destination queue number (within the LIF)
    dst_qaddr		: 34;	// Destination queue state address
    prp_assist		: 1;	// Download additional PRP entries (upto 16)
    is_q0		: 1;	// Is queue id 0 (admin queue) ?
    io_priority		: 8;	// I/O priority to select ring with the queue
    ssd_bm_addr		: 34;	// Pointer to bitmap used to save SSD commands
    cmd_index		: 8;	// Index into bitmap of saved SSD commands
    ssd_handle		: 16;	// SSD handle to select NVME backend
    is_remote		: 1;	// Is the command from local or remote PVM	
    is_read		: 1;	// If NVME command is a read
  }
}

// kivec1: header union with global (128 bits max)
header_type storage_kivec1_t {
  fields {
    src_lif		: 11;	// Source LIF number
    src_qtype		: 3;	// Source LIF type (within the LIF)
    src_qid		: 24;	// Source queue number (within the LIF)
    src_qaddr		: 34;	// Source queue state address
    device_addr		: 34;	// Address of the consumer index in the SSD qstate (OR)
				// Barco ring address
				// ROCE RQ base address
    roce_cq_new_cmd	: 1;	// If ROCE CQ entry is a new commmand
    roce_post_buf	: 1;	// Whether a buffer needs to be posted back on ACK
  }
}

// kivec2: header union with to_stage_2  (128 bits max)
header_type storage_kivec2_t {
  fields {
    ssd_q_num	: 16;	// Number of entries in the SSD priority queue
    ssd_q_size	: 16;	// Size of each queue state entry in SSD priority queue
  }
}

// kivec2acc: header union with to_stage_2, used by acclerator chaining (128 bits max)
header_type storage_kivec2acc_t {
  fields {
    sgl_pdma_out_addr: 64;	// SGL address where data will be placed for PDMA
    sgl_vec_addr    : 64;	// address of SGL vector for hash after compression
  }
}

// kivec3: header union with to_stage_3  (128 bits max)
header_type storage_kivec3_t {
  fields {
    roce_msn	: 32;	// ROCE message sequence number 
    data_addr	: 64;
  }
}

// kivec4: header union with stage_2_stage for table 0 (160 bits max)
header_type storage_kivec4_t {
  fields {
    barco_ring_addr : 34;
    barco_pndx_addr	: 34;
    barco_pndx_shadow_addr: 34;
    barco_desc_size	: 4;
    barco_pndx_size	: 3;
    barco_ring_size	: 5;
    barco_num_descs	: 5;
    w_ndx		    : 16;	// Working consumer index
  }
}

// kivec5: header union with global (128 bits max)
header_type storage_kivec5_t {
  fields {
    intr_addr		: 64;
    data_len		: 16;	// Length of compression data (either from descriptor or 
				// from the compression status)
    pad_len_shift       : 5;
    status_dma_en	:  1;	// 1 => DMA status, 0 => don't DMA status
    next_db_en          :  1;
    intr_en	        :  1;
    next_db_action_barco_push: 1; // next_db action is actually Barco push
    stop_chain_on_error :  1;
    data_len_from_desc	:  1;	// 1 => Use the data length in the descriptor, 
                                // 0 => Use the data lenghth in the status
    aol_pad_en          :  1;
    sgl_pad_hash_en     :  1;
    sgl_pdma_en         :  1;
    copy_src_dst_on_error: 1;
  }
}

#define Q_STATE_COPY_INTRINSIC(q_state)			\
  modify_field(q_state.pc_offset, pc_offset);		\
  modify_field(q_state.rsvd, rsvd);			\
  modify_field(q_state.cosA, cosA);			\
  modify_field(q_state.cosB, cosB);			\
  modify_field(q_state.cos_sel, cos_sel);		\
  modify_field(q_state.eval_last, eval_last);		\
  modify_field(q_state.total_rings, total_rings);	\
  modify_field(q_state.host_rings, host_rings);		\
  modify_field(q_state.pid, pid);			\

#define Q_STATE_COPY_STAGE0(q_state)			\
  Q_STATE_COPY_INTRINSIC(q_state)			\
  modify_field(q_state.p_ndx, p_ndx);			\
  modify_field(q_state.c_ndx, c_ndx);			\
  modify_field(q_state.w_ndx, w_ndx);			\
  modify_field(q_state.num_entries, num_entries);   \
  modify_field(q_state.base_addr, base_addr);		\
  modify_field(q_state.entry_size, entry_size);		\
  modify_field(q_state.next_pc, next_pc);		\
  modify_field(q_state.dst_lif, dst_lif);		\
  modify_field(q_state.dst_qtype, dst_qtype);	        \
  modify_field(q_state.dst_qid, dst_qid);		\
  modify_field(q_state.dst_qaddr, dst_qaddr);		\
  modify_field(q_state.vf_id, vf_id);			\
  modify_field(q_state.sq_id, sq_id);			\
  modify_field(q_state.ssd_bm_addr, ssd_bm_addr);	\
  modify_field(q_state.ssd_q_num, ssd_q_num);		\
  modify_field(q_state.ssd_q_size, ssd_q_size);		\
  modify_field(q_state.ssd_ci_addr, ssd_ci_addr);	\
  modify_field(q_state.desc1_next_pc_valid, desc1_next_pc_valid);\
  modify_field(q_state.desc1_next_pc, desc1_next_pc);\

#define Q_STATE_COPY(q_state)				\
  Q_STATE_COPY_STAGE0(q_state)				\
  modify_field(q_state.pad, pad);			\

#define PRI_Q_STATE_COPY_STAGE0(q_state)		\
  Q_STATE_COPY_INTRINSIC(q_state)			\
  modify_field(q_state.p_ndx_hi, p_ndx_hi);		\
  modify_field(q_state.c_ndx_hi, c_ndx_hi);		\
  modify_field(q_state.p_ndx_med, p_ndx_med);		\
  modify_field(q_state.c_ndx_med, c_ndx_med);		\
  modify_field(q_state.p_ndx_lo, p_ndx_lo);		\
  modify_field(q_state.c_ndx_lo, c_ndx_lo);		\
  modify_field(q_state.w_ndx_hi, w_ndx_hi);		\
  modify_field(q_state.w_ndx_med, w_ndx_med);		\
  modify_field(q_state.w_ndx_lo, w_ndx_lo);		\
  modify_field(q_state.num_entries, num_entries);	\
  modify_field(q_state.base_addr, base_addr);		\
  modify_field(q_state.entry_size, entry_size);		\
  modify_field(q_state.hi_weight, hi_weight);		\
  modify_field(q_state.med_weight, med_weight);		\
  modify_field(q_state.lo_weight, lo_weight);		\
  modify_field(q_state.hi_running, hi_running);		\
  modify_field(q_state.med_running, med_running);	\
  modify_field(q_state.lo_running, lo_running);		\
  modify_field(q_state.num_running, num_running);	\
  modify_field(q_state.max_cmds, max_cmds);		\
  modify_field(q_state.next_pc, next_pc);		\
  modify_field(q_state.dst_lif, dst_lif);		\
  modify_field(q_state.dst_qtype, dst_qtype);		\
  modify_field(q_state.dst_qid, dst_qid);		\
  modify_field(q_state.dst_qaddr, dst_qaddr);		\
  modify_field(q_state.ssd_bm_addr, ssd_bm_addr);	\

#define PRI_Q_STATE_COPY(q_state)			\
  PRI_Q_STATE_COPY_STAGE0(q_state)			\
  modify_field(q_state.pad, pad);			\

#define PCI_Q_STATE_COPY_STAGE0(q_state)		\
  Q_STATE_COPY_INTRINSIC(q_state)			\
  modify_field(q_state.p_ndx, p_ndx);			\
  modify_field(q_state.c_ndx, c_ndx);			\
  modify_field(q_state.w_ndx, w_ndx);			\
  modify_field(q_state.num_entries, num_entries);	\
  modify_field(q_state.base_addr, base_addr);		\
  modify_field(q_state.entry_size, entry_size);		\
  modify_field(q_state.push_addr, push_addr);		\
  modify_field(q_state.intr_addr, intr_addr);		\
  modify_field(q_state.intr_data, intr_data);		\
  modify_field(q_state.intr_en, intr_en);		\

#define PCI_Q_STATE_COPY(q_state)			\
  PCI_Q_STATE_COPY_STAGE0(q_state)			\
  modify_field(q_state.pad, pad);			\

// Copy the full R2N WQE - base from PVM + NVME backend header +
// additional fields saved before sending the NVME command to SSD

#define R2N_WQE_FULL_COPY(wqe)					\
  R2N_WQE_BASE_COPY(wqe)					\
  NVME_BE_CMD_HDR_COPY(wqe)					\
  modify_field(wqe.nvme_cmd_cid, nvme_cmd_cid);			\
  modify_field(wqe.pri_qaddr, pri_qaddr);			\
  modify_field(wqe.iob_addr, iob_addr);			        \
  modify_field(wqe.pad, pad);					\


#define ROCE_XLATE_ENTRY_COPY(entry)			\
  modify_field(entry.next_pc, next_pc);			\
  modify_field(entry.dst_lif, dst_lif);			\
  modify_field(entry.dst_qtype, dst_qtype);		\
  modify_field(entry.dst_qid, dst_qid);			\
  modify_field(entry.dst_qaddr, dst_qaddr);		\
  modify_field(entry.pad, pad);				\
  

#define STORAGE_KIVEC0_USE(scratch, kivec)				\
  modify_field(scratch.w_ndx, kivec.w_ndx);				\
  modify_field(scratch.dst_lif, kivec.dst_lif);				\
  modify_field(scratch.dst_qtype, kivec.dst_qtype);			\
  modify_field(scratch.dst_qid, kivec.dst_qid);				\
  modify_field(scratch.dst_qaddr, kivec.dst_qaddr);			\
  modify_field(scratch.prp_assist, kivec.prp_assist);			\
  modify_field(scratch.is_q0, kivec.is_q0);				\
  modify_field(scratch.io_priority, kivec.io_priority);			\
  modify_field(scratch.ssd_bm_addr, kivec.ssd_bm_addr);			\
  modify_field(scratch.cmd_index, kivec.cmd_index);			\
  modify_field(scratch.ssd_handle, kivec.ssd_handle);			\
  modify_field(scratch.is_remote, kivec.is_remote);			\
  modify_field(scratch.is_read, kivec.is_read);				\

#define STORAGE_KIVEC1_USE(scratch, kivec)				\
  modify_field(scratch.src_lif, kivec.src_lif);				\
  modify_field(scratch.src_qtype, kivec.src_qtype);			\
  modify_field(scratch.src_qid, kivec.src_qid);				\
  modify_field(scratch.src_qaddr, kivec.src_qaddr);			\
  modify_field(scratch.device_addr, kivec.device_addr);			\
  modify_field(scratch.roce_cq_new_cmd, kivec.roce_cq_new_cmd);		\
  modify_field(scratch.roce_post_buf, kivec.roce_post_buf);	        \

#define STORAGE_KIVEC2_USE(scratch, kivec)				\
  modify_field(scratch.ssd_q_num, kivec.ssd_q_num);			\
  modify_field(scratch.ssd_q_size, kivec.ssd_q_size);			\

#define STORAGE_KIVEC2ACC_USE(scratch, kivec)				\
  modify_field(scratch.sgl_pdma_out_addr, kivec.sgl_pdma_out_addr);\
  modify_field(scratch.sgl_vec_addr, kivec.sgl_vec_addr);			\

#define STORAGE_KIVEC3_USE(scratch, kivec)				\
  modify_field(scratch.roce_msn, kivec.roce_msn);			\
  modify_field(scratch.data_addr, kivec.data_addr);			\

#define STORAGE_KIVEC4_USE(scratch, kivec)				\
  modify_field(scratch.barco_pndx_addr, kivec.barco_pndx_addr);			\
  modify_field(scratch.barco_pndx_shadow_addr, kivec.barco_pndx_shadow_addr);\
  modify_field(scratch.barco_desc_size, kivec.barco_desc_size);			\
  modify_field(scratch.barco_pndx_size, kivec.barco_pndx_size);			\
  modify_field(scratch.barco_ring_size, kivec.barco_ring_size);			\
  modify_field(scratch.barco_ring_addr, kivec.barco_ring_addr);			\
  modify_field(scratch.barco_num_descs, kivec.barco_num_descs);			\
  modify_field(scratch.w_ndx, kivec.w_ndx);				\

#define STORAGE_KIVEC5_USE(scratch, kivec)				\
  modify_field(scratch.intr_addr, kivec.intr_addr);			\
  modify_field(scratch.data_len, kivec.data_len);		        \
  modify_field(scratch.pad_len_shift, kivec.pad_len_shift);		\
  modify_field(scratch.status_dma_en, kivec.status_dma_en);	        \
  modify_field(scratch.next_db_en, kivec.next_db_en);	                \
  modify_field(scratch.intr_en, kivec.intr_en);	                        \
  modify_field(scratch.next_db_action_barco_push, kivec.next_db_action_barco_push);\
  modify_field(scratch.stop_chain_on_error, kivec.stop_chain_on_error); \
  modify_field(scratch.data_len_from_desc, kivec.data_len_from_desc);	\
  modify_field(scratch.aol_pad_en, kivec.aol_pad_en);	        \
  modify_field(scratch.sgl_pad_hash_en, kivec.sgl_pad_hash_en);	        \
  modify_field(scratch.sgl_pdma_en, kivec.sgl_pdma_en);                 \
  modify_field(scratch.copy_src_dst_on_error, kivec.copy_src_dst_on_error);\


// Macros for ASM param addresses (hardcoded in P4)
#define q_state_push_start		0x80000000
#define pci_q_state_push_start		0x80001000
#define seq_q_state_push_start		0x80002000
#define pri_q_state_push_start		0x80003000
#define pri_q_state_incr_start		0x80004000
#define pri_q_state_decr_start		0x80005000
#define nvme_be_wqe_prep_start		0x80006000
#define nvme_be_wqe_save_start		0x80007000
#define nvme_be_wqe_release_start	0x80008000
#define nvme_be_wqe_handler_start	0x80009000
#define nvme_be_cmd_handler_start	0x8000A000
#define seq_barco_ring_push_start	0x8000B000
#define roce_sq_xlate_start		0x8000C000
#define roce_r2n_wqe_prep_start		0x8000D000
#define pvm_roce_sq_cb_update_start	0x8000E000
#define roce_rq_push_start		0x8000F000
#define pvm_roce_sq_cb_push_start	0x80010000
#define seq_pvm_roce_sq_cb_push_start	0x80020000
#define seq_comp_status_handler_start	0x80030000
#define seq_comp_sgl_handler_start	0x80040000
#define seq_xts_status_handler_start	0x80050000
#define seq_barco_ring_pndx_read_start	0x80060000
#define nvme_be_save_iob_addr_start	0x80070000


#endif     // STORAGE_TX_P4_HDR_H
