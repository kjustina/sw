/*********************************************************************************
 * L7 Raw Chain (to next service TxDMA or to P4)
 *********************************************************************************/

#include "../common-p4+/common_txdma_dummy.p4"
#include "raw_redir_defines.h"

/*
 * L7 Raw Chain stage 0
 */
#define tx_table_s0_t0_action   start


/*
 * Table names
 */
#define tx_table_s0_t0          rawc_tx_start
#define tx_table_s1_t0          rawc_my_txq_entry
#define tx_table_s2_t0          rawc_desc_aol
#define tx_table_s2_t1          rawc_chain_txq_ring_indices
#define tx_table_s3_t0          rawc_meta_header

/*
 * L7 Raw Chain stage 1
 */
#define tx_table_s1_t0_action   consume

/*
 * L7 Raw Chain stage 2
 */
#define tx_table_s2_t0_action   pkt_txdma_prep
#define tx_table_s2_t1_action   desc_enqueue

/*
 * L7 Raw Chain stage 3
 */
#define tx_table_s3_t0_action   pkt_txdma_post

/*
 * L7 Raw Chain stage 4
 */

/*
 * L7 Raw Chain stage 5
 */

/*
 * L7 Raw Chain stage 6
 */

/*
 * L7 Raw Chain stage 7
 */

#include "../common-p4+/common_txdma.p4"


#define GENERATE_GLOBAL_K \
    modify_field(common_global_scratch.chain_txq_base, common_phv.chain_txq_base); \
    modify_field(common_global_scratch.chain_txq_ring_size_shift, common_phv.chain_txq_ring_size_shift); \
    modify_field(common_global_scratch.chain_txq_entry_size_shift, common_phv.chain_txq_entry_size_shift); \
    modify_field(common_global_scratch.chain_txq_lif, common_phv.chain_txq_lif); \
    modify_field(common_global_scratch.chain_txq_qtype, common_phv.chain_txq_qtype); \
    modify_field(common_global_scratch.chain_txq_qid, common_phv.chain_txq_qid); \
    modify_field(common_global_scratch.chain_txq_ring, common_phv.chain_txq_ring); \
    modify_field(common_global_scratch.next_service_chain_action, common_phv.next_service_chain_action); \
    modify_field(common_global_scratch.chain_txq_ring_full, common_phv.chain_txq_ring_full); \



/*
 * D-vectors
 */

/*
 * d for stage 0: 
 *    This is Raw Chain CB which is also its qstate. The relevant data
 *    contain info used for enqueuing packets to the next service in the chain
 *    or to P4. In other words, the data includes a pointer to the next service's
 *    TxQ ring which, if NULL, implies injecting to P4.
 */
header_type rawccb_t {
    fields {
        CAPRI_QSTATE_HEADER_COMMON
        CAPRI_QSTATE_HEADER_RING(0)

        /*
         * NOTE: cb is programmed by HAL and would work best when
         * fields are aligned on whole byte boundary.
         */
        my_txq_base                     : HBM_ADDRESS_WIDTH;
        my_txq_ring_size_shift          : 8;
        my_txq_entry_size_shift         : 8;
        
        /*
         * Next service chain TxQ info which, if chain_txq_base is NULL,
         * implies that arrival buffers should be DMA'ed to P4. Otherwise,
         * the packet descriptor should be enqueued to the given TxQ
         * and the corresponding doorbell rung.
         */     
        chain_txq_ring_size_shift       : 8;
        chain_txq_entry_size_shift      : 8;
        chain_txq_base                  : HBM_ADDRESS_WIDTH;
        chain_txq_ring_indices_addr     : HBM_ADDRESS_WIDTH;
        
        chain_txq_qid                   : 32;
        chain_txq_lif                   : 16;
        chain_txq_qtype                 : 8;
        chain_txq_ring                  : 8;
    }
}

// d for stage 1 table 0
header_type txq_desc_d_t {
    fields {
        desc                            : 64;
        pad                             : 448;
    }
}

// d for stage 2 table 0 is pkt_descr_aol_t


// d for stage 2 table 1
header_type chain_txq_ring_indices_d_t {
    fields {
        CAPRI_QSTATE_HEADER_RING(curr)
        pad                             : 480;
    }
}

// d for stage 3 table 0 is p4_to_p4plus_cpu_pkt_t


/*
 * Global PHV definitions
 */
header_type common_global_phv_t {
    fields {
        // p4plus_common_global_t (max is GLOBAL_WIDTH or 128)
        chain_txq_base                  : HBM_ADDRESS_WIDTH;
        chain_txq_ring_size_shift       : 8;
        chain_txq_entry_size_shift      : 8;
        
        chain_txq_lif                   : 11;
        chain_txq_qtype                 : 3;
        chain_txq_qid                   : 24;
        chain_txq_ring                  : 3;
        
        next_service_chain_action       : 1;
        chain_txq_ring_full             : 1;
    }
}

header_type dma_phv_pad_448_t {
    fields {
        dma_pad                         : 448;    
    }    
}

header_type dma_phv_pad_384_t {
    fields {
        dma_pad                         : 384;
    }    
}

header_type dma_phv_pad_16_t {
    fields {
        dma_pad                         : 16;    
    }    
}

/*
 * to_stage PHV definitions
 */

header_type to_stage_1_phv_t {
    fields {
        // (max 128 bits)
        chain_txq_ring_indices_addr     : HBM_ADDRESS_WIDTH;
        my_txq_ci_curr                  : 16;
        my_txq_ring_size_shift          : 8;
        my_txq_qid                      : 24;
        my_txq_lif                      : 11;
        my_txq_qtype                    : 3;
    }
}

header_type to_stage_2_phv_t {
    fields {
        // (max 128 bits)
        my_txq_desc                     : 64;
    }
}

/*
 * Header unions for d-vector
 */
@pragma scratch_metadata
metadata rawccb_t                       rawccb_d;

@pragma scratch_metadata
metadata txq_desc_d_t                   my_txq_desc_d;

@pragma scratch_metadata
metadata pkt_descr_aol_t                txq_desc_aol_d;

@pragma scratch_metadata
metadata chain_txq_ring_indices_d_t     chain_txq_ring_indices_d;

@pragma scratch_metadata
metadata cpu_to_p4_header_t             cpu_to_p4_header_d;

/*
 * Stage to stage PHV definitions
 */
header_type s2_t0_s2s_phv_t {
    fields {
        // (max is STAGE_2_STAGE_WIDTH or 160 bits)
        aol_A0                  : 52;
        aol_A1                  : 52;
        aol_A2                  : 52;
        aol_A0_valid            : 1;
        aol_A1_valid            : 1;
        aol_A2_valid            : 1;
    }
}

/*
 * Header unions for PHV layout
 */
@pragma pa_header_union ingress         common_global
metadata common_global_phv_t            common_phv;
@pragma scratch_metadata
metadata common_global_phv_t            common_global_scratch;

@pragma pa_header_union ingress         app_header
metadata p4plus_to_p4_header_t          rawc_app_header;
@pragma scratch_metadata
metadata p4plus_to_p4_header_t          rawc_scratch_app;

@pragma pa_header_union ingress         to_stage_1
metadata to_stage_1_phv_t               to_s1;
@pragma scratch_metadata
metadata to_stage_1_phv_t               to_s1_scratch;

@pragma pa_header_union ingress         to_stage_2
metadata to_stage_2_phv_t               to_s2;
@pragma scratch_metadata
metadata to_stage_2_phv_t               to_s2_scratch;

@pragma pa_header_union ingress         common_t0_s2s
metadata s2_t0_s2s_phv_t                s2_t0_s2s;
@pragma scratch_metadata
metadata s2_t0_s2s_phv_t                s2_t0_s2s_scratch;


/*
 * PHV following k (for app DMA etc.)
 */
@pragma dont_trim
metadata ring_entry_t                   chain_txq_desc_addr; 

@pragma dont_trim
metadata doorbell_data_raw_t            chain_txq_db_data; 

@pragma dont_trim
metadata dma_phv_pad_384_t              dma_phv_pad_384_t;

/*
 * DMA descriptors for injecting packet data to P4
 */
@pragma dont_trim
metadata dma_cmd_phv2pkt_t              dma_intr_global;
@pragma dont_trim
metadata dma_cmd_phv2pkt_t              dma_intr_txdma;
@pragma dont_trim
metadata dma_cmd_mem2pkt_t              dma_pkt0;
@pragma dont_trim
metadata dma_cmd_mem2pkt_t              dma_pkt1;
@pragma dont_trim
metadata dma_cmd_mem2pkt_t              dma_pkt2;

/*
 * DMA descriptors for enqueuing to next service TxQ
 */
@pragma dont_trim
metadata dma_cmd_phv2mem_t              dma_chain;
@pragma dont_trim
metadata dma_cmd_phv2mem_t              dma_doorbell;

@pragma dont_trim
metadata dma_phv_pad_16_t               dma_pad_16;



/*
 * Action functions to generate k_struct and d_struct
 *
 * These action functions are currently only to generate the k+i and d structs
 * and do not implement any pseudo code
 */

/*
 * Stage 0 table 0 action
 */
action start(rsvd, cosA, cosB, cos_sel, 
             eval_last, host, total, pid,
             pi_0, ci_0,
             my_txq_base, my_txq_ring_size_shift, my_txq_entry_size_shift,
             chain_txq_ring_size_shift, chain_txq_entry_size_shift,
             chain_txq_base, chain_txq_ring_indices_addr,
             chain_txq_qid, chain_txq_lif, chain_txq_qtype, chain_txq_ring) {

    // k + i for stage 0

    // from intrinsic
    modify_field(p4_intr_global_scratch.lif, p4_intr_global.lif);
    modify_field(p4_intr_global_scratch.tm_iq, p4_intr_global.tm_iq);
    modify_field(p4_intr_global_scratch.tm_oq, p4_intr_global.tm_oq);
    modify_field(p4_txdma_intr_scratch.qid, p4_txdma_intr.qid);
    modify_field(p4_txdma_intr_scratch.qtype, p4_txdma_intr.qtype);
    modify_field(p4_txdma_intr_scratch.qstate_addr, p4_txdma_intr.qstate_addr);

    // from p4plus_to_p4_header_t
    modify_field(rawc_scratch_app.p4plus_app_id, rawc_app_header.p4plus_app_id);
    modify_field(rawc_scratch_app.flags, rawc_app_header.flags);
    modify_field(rawc_scratch_app.ip_id_delta, rawc_app_header.ip_id_delta);
    modify_field(rawc_scratch_app.tcp_seq_delta, rawc_app_header.tcp_seq_delta);
    modify_field(rawc_scratch_app.vlan_tag, rawc_app_header.vlan_tag);
    
    // d for stage 0
    
    //modify_field(rawccb_d.pc, pc);
    modify_field(rawccb_d.rsvd, rsvd);
    modify_field(rawccb_d.cosA, cosA);
    modify_field(rawccb_d.cosB, cosB);
    modify_field(rawccb_d.cos_sel, cos_sel);
    modify_field(rawccb_d.eval_last, eval_last);
    modify_field(rawccb_d.host, host);
    modify_field(rawccb_d.total, total);
    modify_field(rawccb_d.pid, pid);
    modify_field(rawccb_d.pi_0, pi_0);
    modify_field(rawccb_d.ci_0, ci_0);
    
    modify_field(rawccb_d.my_txq_base, my_txq_base);
    modify_field(rawccb_d.my_txq_ring_size_shift, my_txq_ring_size_shift);
    modify_field(rawccb_d.my_txq_entry_size_shift, my_txq_entry_size_shift);
    modify_field(rawccb_d.chain_txq_base, chain_txq_base);
    modify_field(rawccb_d.chain_txq_ring_indices_addr, chain_txq_ring_indices_addr);
    modify_field(rawccb_d.chain_txq_ring_size_shift, chain_txq_ring_size_shift);
    modify_field(rawccb_d.chain_txq_entry_size_shift, chain_txq_entry_size_shift);
    modify_field(rawccb_d.chain_txq_lif, chain_txq_lif);
    modify_field(rawccb_d.chain_txq_qtype, chain_txq_qtype);
    modify_field(rawccb_d.chain_txq_qid, chain_txq_qid);
    modify_field(rawccb_d.chain_txq_ring, chain_txq_ring);
}


/*
 * Stage 1 table 0 action
 */
action consume(desc) {

    // from to_stage
    modify_field(to_s1_scratch.chain_txq_ring_indices_addr, to_s1.chain_txq_ring_indices_addr);
    modify_field(to_s1_scratch.my_txq_ci_curr, to_s1.my_txq_ci_curr);
    modify_field(to_s1_scratch.my_txq_ring_size_shift, to_s1.my_txq_ring_size_shift);
    modify_field(to_s1_scratch.my_txq_lif, to_s1.my_txq_lif);
    modify_field(to_s1_scratch.my_txq_qtype, to_s1.my_txq_qtype);
    modify_field(to_s1_scratch.my_txq_qid, to_s1.my_txq_qid);
    
    // from ki global
    GENERATE_GLOBAL_K
    
    // d for stage and table
    modify_field(my_txq_desc_d.desc, desc);
}


/*
 * Stage 2 table 0 action
 */
action pkt_txdma_prep(A0, O0, L0,
                      A1, O1, L1,
                      A2, O2, L2) {

    // from to_stage
    
    // from ki global
    GENERATE_GLOBAL_K
    
    // from stage to stage
    modify_field(s2_t0_s2s_scratch.aol_A0, s2_t0_s2s.aol_A0);
    modify_field(s2_t0_s2s_scratch.aol_A1, s2_t0_s2s.aol_A1);
    modify_field(s2_t0_s2s_scratch.aol_A2, s2_t0_s2s.aol_A2);
    modify_field(s2_t0_s2s_scratch.aol_A0_valid, s2_t0_s2s.aol_A0_valid);
    modify_field(s2_t0_s2s_scratch.aol_A1_valid, s2_t0_s2s.aol_A1_valid);
    modify_field(s2_t0_s2s_scratch.aol_A2_valid, s2_t0_s2s.aol_A2_valid);
    
    // d for stage and table
    modify_field(txq_desc_aol_d.A0, A0);
    modify_field(txq_desc_aol_d.O0, O0);
    modify_field(txq_desc_aol_d.L0, L0);
    modify_field(txq_desc_aol_d.A1, A1);
    modify_field(txq_desc_aol_d.O1, O1);
    modify_field(txq_desc_aol_d.L1, L1);
    modify_field(txq_desc_aol_d.A2, A2);
    modify_field(txq_desc_aol_d.O2, O2);
    modify_field(txq_desc_aol_d.L2, L2);
}


/*
 * Stage 2 table 1 action
 */
action desc_enqueue(pi_curr, ci_curr) {

    // from to_stage
    modify_field(to_s2_scratch.my_txq_desc, to_s2.my_txq_desc);
    
    // from ki global
    GENERATE_GLOBAL_K
    
    // d for stage and table
    modify_field(chain_txq_ring_indices_d.pi_curr, pi_curr);
    modify_field(chain_txq_ring_indices_d.ci_curr, ci_curr);
}


/*
 * Stage 3 table 0 action
 */
action pkt_txdma_post(src_lif) {

    // from to_stage
    
    // from ki global
    GENERATE_GLOBAL_K
    
    // from stage to stage
    
    // d for stage and table
    modify_field(cpu_to_p4_header_d.src_lif, src_lif);
}
