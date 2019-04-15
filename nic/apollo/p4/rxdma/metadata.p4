#include "../../../p4/common-p4+/capri_dma_cmd.p4"
#include "../../../p4/common-p4+/capri_doorbell.p4"

header_type sacl_metadata_t {
    fields {
        pad0                        : 6;
        sport_table_addr            : 34;
        pad1                        : 6;
        ipv4_table_addr             : 34;
        pad2                        : 6;
        proto_dport_table_addr      : 34;
        pad3                        : 6;
        p1_table_addr               : 34;
        pad4                        : 6;
        p2_table_addr               : 34;
        proto_dport_class_id        : 8;
        proto_dport                 : 24;
        sport_class_id              : 7;
        ip_sport_class_id           : 17;
        p1_class_id                 : 10;
        pad5                        : 30;
        ip                          : 128;
        pad6                        : 6;
        ipv4_table_addr_next        : 34;
        pad7                        : 6;
        proto_dport_table_addr_next : 34;
        pad8                        : 8;
    }
}

header_type scratch_metadata_t {
    fields {
        in_packets      : 64;
        in_bytes        : 64;
        rule_id         : 10;
        class_id10      : 10;
        class_id16      : 16;
        class_id8       : 8;
        qid             : 24;
        dma_size        : 16;
        sacl_result     : 2;
        pad2            : 2;
        data510         : 510;
        data512         : 512;
        field16         : 16;
        field32         : 32;
        field64         : 64;
        field128        : 128;
        ipv4_addr       : 32;
        proto_dport     : 24;
    }
}

header_type udp_scratch_metadata_t {
    fields {
        entry_valid         : 1;
        udp_flow_hit        : 1;
        udp_queue_delete    : 1;
        udp_flow_lkp_result : 2;
        pad0                : 1;
        udp_q_counter       : 10;

        udp_flow_qid        : 8;
        qid_bitmap          : 64;
    }
}
header_type udp_flow_metadata_t {
    fields {
        zero                : 1;
        udp_flow_lkp_result : 2;
        pad0                : 1;
        udp_qid_tbl_idx     : 12;   // stg_id | udp_oflow_index[10:0]
        udp_flow_qid        : 8;
    }
}

header_type flow_key_t {
    fields {
        pad                 : 12;
        flow_ktype          : 4;
        flow_src            : 128;
        flow_dst            : 128;
        flow_proto          : 8;
        flow_dport          : 16;
        flow_sport          : 16;
    }
}

// PHV instantiation
@pragma dont_trim
metadata cap_phv_intr_global_t capri_intr;
@pragma dont_trim
metadata cap_phv_intr_p4_t capri_p4_intr;
@pragma dont_trim
metadata cap_phv_intr_rxdma_t capri_rxdma_intr;

@pragma dont_trim
metadata p4_2_p4plus_app_header_t app_header;
@pragma dont_trim
metadata p4_2_p4plus_ext_app_header_t ext_app_header;

@pragma dont_trim
@pragma pa_header_union ingress app_header
metadata p4_to_rxdma_header_t p4_to_rxdma_header;
@pragma dont_trim
@pragma pa_header_union ingress ext_app_header
metadata predicate_header_t predicate_header;

@pragma dont_trim
metadata p4plus_common_to_stage_t to_stage_0;
@pragma dont_trim
metadata p4plus_common_to_stage_t to_stage_1;
@pragma dont_trim
metadata p4plus_common_to_stage_t to_stage_2;
@pragma dont_trim
metadata p4plus_common_to_stage_t to_stage_3;
@pragma dont_trim
metadata p4plus_common_to_stage_t to_stage_4;
@pragma dont_trim
metadata p4plus_common_to_stage_t to_stage_5;
@pragma dont_trim
metadata p4plus_common_to_stage_t to_stage_6;
@pragma dont_trim
metadata p4plus_common_to_stage_t to_stage_7;

@pragma dont_trim
metadata p4plus_common_global_t common_global;
@pragma dont_trim
metadata p4plus_common_raw_table_engine_phv_t common_te0_phv;
@pragma dont_trim
metadata p4plus_common_s2s_t common_t0_s2s;
@pragma dont_trim
metadata p4plus_common_raw_table_engine_phv_t common_te1_phv;
@pragma dont_trim
metadata p4plus_common_s2s_t common_t1_s2s;
@pragma dont_trim
metadata p4plus_common_raw_table_engine_phv_t common_te2_phv;
@pragma dont_trim
metadata p4plus_common_s2s_t common_t2_s2s;
@pragma dont_trim
metadata p4plus_common_raw_table_engine_phv_t common_te3_phv;
@pragma dont_trim
metadata p4plus_common_s2s_t common_t3_s2s;

header_type rxdma_common_pad_t {
    fields {
        rxdma_common_pad : 96;
    }
}

@pragma dont_trim
metadata rxdma_common_pad_t     rxdma_common_pad;

@pragma dont_trim
metadata sacl_metadata_t        sacl_metadata;

@pragma dont_trim
@pragma scratch_metadata
metadata scratch_metadata_t     scratch_metadata;

@pragma dont_trim
@pragma scratch_metadata
metadata qstate_hdr_t           scratch_qstate_hdr;

@pragma dont_trim
@pragma scratch_metadata
metadata qstate_txdma_q_t       scratch_qstate_txdma_q;

@pragma dont_trim
@pragma scratch_metadata
metadata udp_scratch_metadata_t udp_scratch;

@pragma dont_trim
metadata udp_flow_metadata_t    udp_flow_metadata;

@pragma scratch_metadata
metadata flow_key_t             scratch_flow_key;

@pragma dont_trim
metadata doorbell_addr_t        doorbell_addr;
@pragma dont_trim
metadata doorbell_data_t        doorbell_data;

// DMA commands
@pragma pa_align 128
@pragma dont_trim
metadata dma_cmd_pkt2mem_t      payload_pkt2mem;
@pragma dont_trim
metadata dma_cmd_phv2mem_t      predicate_phv2mem;
@pragma dont_trim
metadata dma_cmd_phv2mem_t      doorbell_phv2mem;
