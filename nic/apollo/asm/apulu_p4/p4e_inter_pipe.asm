#include "apulu.h"
#include "egress.h"
#include "EGRESS_p.h"
#include "EGRESS_p4e_inter_pipe_k.h"

struct p4e_inter_pipe_k_    k;
struct phv_                 p;

%%

p4e_inter_pipe:
    phvwr           p.capri_txdma_intrinsic_valid, 0
    sne             c1, k.capri_intrinsic_tm_oq, TM_P4_RECIRC_QUEUE
    phvwr.c1        p.capri_intrinsic_tm_iq, k.capri_intrinsic_tm_oq
    phvwr.!c1       p.capri_intrinsic_tm_oq, k.capri_intrinsic_tm_iq
    seq             c1, k.egress_recirc_mapping_done, FALSE
    bcf             [c1], egress_recirc
    phvwrmi.!c1     p.{p4e_i2e_valid, \
                        p4e_to_arm_valid, \
                        txdma_to_p4e_valid, \
                        egress_recirc_valid}, 0x0, 0xB
    seq             c1, k.capri_intrinsic_tm_oport, TM_PORT_DMA
    nop.!c1.e

egress_to_rxdma:
    // r7 actual packet len
    // c7 ctag_1 valid
    add             r7, r0, k.capri_p4_intrinsic_packet_len
    seq             c7, k.ctag_1_valid, TRUE
    phvwr           p.capri_rxdma_intrinsic_valid, TRUE
    phvwr           p.{p4e_to_p4plus_classic_nic_ip_valid, \
                        p4e_to_p4plus_classic_nic_valid}, 0x3
    seq             c1, k.p4e_to_arm_valid, TRUE
    bcf             [c1], egress_to_rxdma_arm
    add             r6, r0, r7
    seq             c1, k.control_metadata_rx_packet, TRUE
    phvwr.c1        p.capri_intrinsic_tm_span_session, k.p4e_i2e_mirror_session

    seq             c1, k.rewrite_metadata_vlan_strip_en, TRUE
    bcf             ![c1&c7], egress_to_rxdma_common
    nop
    phvwr           p.p4e_to_p4plus_classic_nic_vlan_valid, TRUE
    phvwr           p.ethernet_1_etherType, k.ctag_1_etherType
    phvwr           p.{p4e_to_p4plus_classic_nic_vlan_pcp, \
                        p4e_to_p4plus_classic_nic_vlan_dei, \
                        p4e_to_p4plus_classic_nic_vlan_vid}, \
                        k.{ctag_1_pcp,ctag_1_dei,ctag_1_vid}
    phvwr           p.ctag_1_valid, FALSE
    sub             r7, r7, 4
    sub             r6, r6, 6
    b               egress_to_rxdma_common
    sne             c7, r0, r0

egress_to_rxdma_arm:
    add             r6, r6, APULU_P4_TO_ARM_HDR_SZ
    phvwr           p.capri_p4_intrinsic_packet_len, r6
    phvwr           p.p4e_to_arm_rx_packet, k.control_metadata_rx_packet
    phvwr           p.p4e_to_arm_egress_bd_id, k.{vnic_metadata_egress_bd_id}.hx
    phvwr           p.{p4e_to_arm_sacl_action,p4e_to_arm_sacl_root}, \
                        k.{txdma_to_p4e_sacl_action,txdma_to_p4e_sacl_root_num}
    phvwr           p.p4e_to_arm_drop, k.txdma_to_p4e_drop
    phvwr           p.{p4e_to_arm_snat_type,p4e_to_arm_dnat_en}, \
                        k.{txdma_to_p4e_snat_type,txdma_to_p4e_dnat_en}
    phvwr           p.p4e_to_arm_dnat_id, k.{txdma_to_p4e_dnat_idx}.hx

egress_to_rxdma_common:
    phvwr           p.p4e_to_p4plus_classic_nic_packet_len, r6
    phvwr           p.p4e_to_p4plus_classic_nic_p4plus_app_id, \
                        P4PLUS_APPTYPE_CLASSIC_NIC
    phvwr           p.capri_rxdma_intrinsic_rx_splitter_offset, \
                        (CAPRI_GLOBAL_INTRINSIC_HDR_SZ + \
                         CAPRI_RXDMA_INTRINSIC_HDR_SZ + \
                         P4PLUS_CLASSIC_NIC_HDR_SZ)

    // l2 checksum computation
    phvwr           p.p4e_to_p4plus_classic_nic_l2csum, TRUE
    phvwr.c7        p.ctag_1_l2csum, TRUE
    phvwrpair.!c7   p.ipv4_1_l2csum, k.ipv4_1_valid, \
                        p.ipv6_1_l2csum, k.ipv6_1_valid
    sub             r6, r7, 14
    phvwr           p.capri_deparser_len_l2_checksum_len, r6

    seq             c1, k.ipv4_1_valid, TRUE
    bcf             [c1], egress_to_rxdma_ipv4
    seq             c1, k.ipv6_1_valid, TRUE
    nop.!c1.e
egress_to_rxdma_ipv6:
    seq             c1, k.ipv6_1_nextHdr, IP_PROTO_TCP
    phvwr.c1.e      p.p4e_to_p4plus_classic_nic_pkt_type, \
                        CLASSIC_NIC_PKT_TYPE_IPV6_TCP
    seq             c1, k.ipv6_1_nextHdr, IP_PROTO_UDP
    phvwr.c1.e      p.p4e_to_p4plus_classic_nic_pkt_type, \
                        CLASSIC_NIC_PKT_TYPE_IPV6_UDP
    nop.e
    phvwr.f         p.p4e_to_p4plus_classic_nic_pkt_type, \
                        CLASSIC_NIC_PKT_TYPE_IPV6
egress_to_rxdma_ipv4:
    phvwr           p.key_metadata_src, k.ipv4_1_srcAddr
    phvwr           p.key_metadata_dst, k.ipv4_1_dstAddr
    seq             c1, k.ipv4_1_protocol, IP_PROTO_TCP
    phvwr.c1.e      p.p4e_to_p4plus_classic_nic_pkt_type, \
                        CLASSIC_NIC_PKT_TYPE_IPV4_TCP
    seq             c1, k.ipv4_1_protocol, IP_PROTO_UDP
    phvwr.c1.e      p.p4e_to_p4plus_classic_nic_pkt_type, \
                        CLASSIC_NIC_PKT_TYPE_IPV4_UDP
    phvwr.f         p.p4e_to_p4plus_classic_nic_pkt_type, \
                        CLASSIC_NIC_PKT_TYPE_IPV4

egress_recirc:
    phvwr           p.egress_recirc_p4_to_arm_valid, k.p4e_to_arm_valid
    phvwr.e         p.egress_recirc_valid, TRUE
    phvwr.f         p.capri_intrinsic_tm_oport, TM_PORT_EGRESS

/*****************************************************************************/
/* error function                                                            */
/*****************************************************************************/
.align
.assert $ < ASM_INSTRUCTION_OFFSET_MAX
p4e_inter_pipe_error:
    phvwr           p.capri_intrinsic_drop, 1
    sne.e           c1, k.capri_intrinsic_tm_oq, TM_P4_RECIRC_QUEUE
    phvwr.c1        p.capri_intrinsic_tm_iq, k.capri_intrinsic_tm_oq
