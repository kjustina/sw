
#include "INGRESS_p.h"
#include "ingress.h"
#include "INGRESS_common_p4plus_stage0_app_header_table_k.h"

#include "defines.h"

struct phv_ p;
struct common_p4plus_stage0_app_header_table_k k;
struct common_p4plus_stage0_app_header_table_eth_rx_app_header_d d;

%%

.param  eth_rx_rss_skip

.align
eth_rx_app_header:

  tblwr.l.f       d.rsvd1, 0
  // !!! No table updates after this point !!!

  // Save all required information from APP header
  phvwr           p.eth_rx_global_qstate_addr, k.{p4_rxdma_intr_qstate_addr_sbit0_ebit1, p4_rxdma_intr_qstate_addr_sbit2_ebit33}
  phvwr           p.eth_rx_t0_s2s_packet_len, k.p4_to_p4plus_packet_len

  // Build completion entry in the PHV
  sne             c1, k.p4_to_p4plus_pkt_type, PKT_TYPE_NON_IP
  phvwr.c1        p.eth_rx_cq_desc_csum_calc, 1
  xor.c1          r1, k.p4_to_p4plus_csum, -1
  phvwr.c1        p.eth_rx_cq_desc_csum, r1
  phvwr           p.{eth_rx_cq_desc_csum_ip_bad...eth_rx_cq_desc_csum_tcp_ok}, k.{p4_to_p4plus_csum_ip_bad...p4_to_p4plus_csum_tcp_ok}
  phvwr           p.eth_rx_cq_desc_vlan_strip, k.p4_to_p4plus_vlan_valid
  phvwr           p.eth_rx_cq_desc_vlan_tci, k.{p4_to_p4plus_vlan_pcp...p4_to_p4plus_vlan_vid_sbit4_ebit11}.hx
  phvwr           p.eth_rx_cq_desc_len_lo, k.p4_to_p4plus_packet_len[7:0]
  phvwr           p.eth_rx_cq_desc_len_hi, k.p4_to_p4plus_packet_len[13:8]

// Write RSS input to PHV
eth_rx_rss_input:
  and             r1, d.{rss_type}.hx, k.p4_to_p4plus_pkt_type

  indexb          r7, r1, [RSS_IPV4_UDP, RSS_IPV4_TCP, RSS_IPV4, RSS_NONE], 0
  indexb          r7, r1, [RSS_IPV6_UDP, RSS_IPV6_TCP, RSS_IPV6], 1

.brbegin
  br              r7[2:0]
  phvwr           p.eth_rx_cq_desc_rss_type, r7

  .brcase 0
    b             eth_rx_rss_none
    phvwri        p.{app_header_table0_valid...app_header_table3_valid}, (1 << 3)

  // Clear all table valid bits so the topelitz table can launch in next stage
  .brcase 1
    b             eth_rx_rss_ipv4
    phvwri        p.{app_header_table0_valid...app_header_table3_valid}, 0

  .brcase 2
    b             eth_rx_rss_ipv4_l4
    phvwri        p.{app_header_table0_valid...app_header_table3_valid}, 0

  .brcase 3
    b             eth_rx_rss_ipv4_l4
    phvwri        p.{app_header_table0_valid...app_header_table3_valid}, 0

  .brcase 4
    b             eth_rx_rss_ipv6
    phvwri        p.{app_header_table0_valid...app_header_table3_valid}, 0

  .brcase 5
    b             eth_rx_rss_ipv6_l4
    phvwri        p.{app_header_table0_valid...app_header_table3_valid}, 0

  .brcase 6
    b             eth_rx_rss_ipv6_l4
    phvwri        p.{app_header_table0_valid...app_header_table3_valid}, 0

  .brcase 7
    b             eth_rx_rss_none
    phvwri        p.{app_header_table0_valid...app_header_table3_valid}, (1 << 3)

.brend

eth_rx_rss_none:
  phvwri.e            p.common_te0_phv_table_pc, eth_rx_rss_skip[38:6]
  phvwri.f            p.common_te0_phv_table_raw_table_size, CAPRI_RAW_TABLE_SIZE_MPU_ONLY

eth_rx_rss_ipv4_l4:
  phvwr               p.toeplitz_input0_data[63:32], k.{p4_to_p4plus_l4_sport, p4_to_p4plus_l4_dport}
eth_rx_rss_ipv4:
  phvwr               p.toeplitz_input0_data[127:88], k.p4_to_p4plus_ip_sa_sbit0_ebit71[39:0]
  phvwr.e             p.toeplitz_input0_data[87:64], k.p4_to_p4plus_ip_sa_sbit72_ebit127[55:32]
  phvwr.f             p.toeplitz_key2_data[33:0], k.{p4_rxdma_intr_qstate_addr_sbit0_ebit1, p4_rxdma_intr_qstate_addr_sbit2_ebit33}

eth_rx_rss_ipv6_l4:
  phvwr               p.toeplitz_input2_data, k.{p4_to_p4plus_l4_sport, p4_to_p4plus_l4_dport}
eth_rx_rss_ipv6:
  phvwr               p.toeplitz_input0_data[127:56], k.p4_to_p4plus_ip_sa_sbit0_ebit71
  phvwr               p.toeplitz_input0_data[55:0], k.p4_to_p4plus_ip_sa_sbit72_ebit127
  phvwr.e             p.toeplitz_input1_data, k.{p4_to_p4plus_ip_da_sbit0_ebit87, p4_to_p4plus_ip_da_sbit88_ebit127}
  phvwr.f             p.toeplitz_key2_data[33:0], k.{p4_rxdma_intr_qstate_addr_sbit0_ebit1, p4_rxdma_intr_qstate_addr_sbit2_ebit33}
