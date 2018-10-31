#include "INGRESS_p.h"
#include "ingress.h"
#include "ipsec_asm_defines.h"
#include "capri-macros.h"

struct tx_table_s4_t0_k k;
struct tx_table_s4_t0_tx_table_s4_t0_cfg_action_d d;
struct phv_ p;

%%
        .param IPSEC_IP_HDR_BASE
        .align
esp_ipv4_tunnel_h2n_txdma2_ipsec_build_encap_packet:
    phvwri p.{app_header_table0_valid...app_header_table3_valid}, 0
    // Outer-IP  
    add r1, k.ipsec_to_stage4_ipsec_cb_addr, IPSEC_IP_HDR_OFFSET+ETH_FIXED_HDR_SIZE
    blti r1, CAPRI_HBM_BASE, esp_ipv4_tunnel_h2n_txdma2_ipsec_build_encap_packet_illegal_dma
    phvwr  p.ip_hdr_dma_cmd_addr, r1 
    seq c1, k.ipsec_to_stage4_is_v6, 1
    cmov r6, c1, IPV6_HDR_SIZE, IPV4_HDR_SIZE 
    seq c3, k.ipsec_to_stage4_is_nat_t, 1
    addi.c3 r6, r6, UDP_FIXED_HDR_SIZE 
    phvwr  p.ip_hdr_dma_cmd_size, r6 
    // P4PLUS_TO_P4_FLAGS_UPDATE_UDP_LEN | P4PLUS_TO_P4_FLAGS_UPDATE_IP_LEN | P4PLUS_TO_P4_FLAGS_COMP_OUTER_CSUM 
    phvwri.c3 p.p4plus2p4_hdr_flags, 0x2a 
    //ESP Header with IV
    add r4, r0, k.t0_s2s_in_page_addr
    blti r4, CAPRI_HBM_BASE, esp_ipv4_tunnel_h2n_txdma2_ipsec_build_encap_packet_illegal_dma
    phvwr p.esp_iv_hdr_dma_cmd_addr, k.t0_s2s_in_page_addr 
    add r2, k.txdma2_global_iv_size, ESP_FIXED_HDR_SIZE 
    phvwr p.esp_iv_hdr_dma_cmd_size, r2
    // Payload
    add r4, k.t0_s2s_out_page_addr, ESP_FIXED_HDR_SIZE 
    blti r4, CAPRI_HBM_BASE, esp_ipv4_tunnel_h2n_txdma2_ipsec_build_encap_packet_illegal_dma
    phvwr p.enc_pay_load_dma_cmd_addr, r4 
    add r3, k.txdma2_global_payload_size, k.txdma2_global_pad_size
    addi r3, r3, 2
    phvwr p.enc_pay_load_dma_cmd_size, r3
    //ICV
    phvwr p.icv_header_dma_cmd_size, k.txdma2_global_icv_size
    add r1, k.t0_s2s_out_page_addr, ESP_FIXED_HDR_SIZE+2 
    blti r1, CAPRI_HBM_BASE, esp_ipv4_tunnel_h2n_txdma2_ipsec_build_encap_packet_illegal_dma
    add r1, r1, k.txdma2_global_pad_size
    add r1, r1, k.t0_s2s_tailroom_offset
    phvwr.e p.icv_header_dma_cmd_addr, r1
    nop 

esp_ipv4_tunnel_h2n_txdma2_ipsec_build_encap_packet_illegal_dma:
    phvwri p.p4_intr_global_drop, 1
    CAPRI_CLEAR_TABLE0_VALID
    CAPRI_CLEAR_TABLE1_VALID
    CAPRI_CLEAR_TABLE2_VALID
    CAPRI_CLEAR_TABLE3_VALID
    nop.e
    nop

