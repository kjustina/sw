#include <stdint.h>
#include <vector>
#include "nic/include/base.hpp"
#include "nic/sdk/lib/utils/utils.hpp"
#include "nic/apollo/api/include/athena/pds_vnic.h"
#include "nic/apollo/api/include/athena/pds_flow_cache.h"
#include "nic/apollo/api/include/athena/pds_flow_session_info.h"
#include "nic/apollo/api/include/athena//pds_flow_session_rewrite.h"

#include "athena_gtest.hpp"

static uint16_t    g_nat_vnic_id = VNIC_ID_NAT;
static uint32_t    g_h2s_nat_vlan = VLAN_ID_NAT;

/*
 * Normalized IPv4 key
 */
static uint32_t    g_h2s_sip = 0x02000001;
static uint32_t    g_h2s_dip = 0xc0000201;
static uint8_t     g_h2s_proto_udp = 0x11;
static uint8_t     g_h2s_proto_tcp = 0x6;
static uint8_t     g_h2s_proto_icmp = 0x01;
static uint16_t    g_h2s_sport = 0x03e8;
static uint16_t    g_h2s_dport = 0x2710;

static uint8_t      g_h2s_icmp_type = 0x08;
static uint8_t      g_h2s_icmp_code = 0x0;
static uint16_t     g_h2s_icmp_identifier = 0x1234;

static uint8_t      g_h2s_icmpv6_proto = 0x3A;
static uint8_t      g_h2s_icmpv6_type = 0x80;
static uint8_t      g_h2s_icmpv6_code = 0x0;
static uint16_t     g_h2s_icmpv6_identifier = 0x1234;

static uint32_t    g_h2s_nat_sip = 0x03000001;

/*
 * Normalized IPv6 key for UDP flow
 */
static ipv6_addr_t  g_h2s_sipv6 = 
                                {
                                    0x02, 0x00, 0x00, 0x00,
                                    0x00, 0x00, 0x00, 0x00,
                                    0x00, 0x00, 0x00, 0x00,
                                    0x00, 0x00, 0x00, 0x01,
                                };
static ipv6_addr_t  g_h2s_dipv6 = 
                                {
                                    0x0c, 0x00, 0x00, 0x00,
                                    0x00, 0x00, 0x00, 0x00,
                                    0x00, 0x00, 0x00, 0x00,
                                    0x00, 0x00, 0x02, 0x01,
                                };
static ipv6_addr_t  g_h2s_nat_sipv6 = 
                                {
                                    0x03, 0x00, 0x00, 0x00,
                                    0x00, 0x00, 0x00, 0x00,
                                    0x00, 0x00, 0x00, 0x00,
                                    0x00, 0x00, 0x00, 0x01,
                                };

/*
 * Session info rewrite - S2H
 */
static mac_addr_t  ep_smac = {0x00, 0x00, 0xF1, 0xD0, 0xD1, 0xD0};
static mac_addr_t  ep_dmac = {0x00, 0x00, 0x00, 0x40, 0x08, 0x01};

/*
 * Session into rewrite - H2S
 */
static mac_addr_t  substrate_smac = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05};
static mac_addr_t  substrate_dmac = {0x00, 0x06, 0x07, 0x08, 0x09, 0x0a};
static uint16_t    substrate_vlan = 0x02;
static uint32_t    substrate_sip = 0x04030201;
static uint32_t    substrate_dip = 0x01020304;
static uint32_t    mpls1_label = 0x12345;
static uint32_t    mpls2_label = MPLS_LABEL_NAT;

static sdk_ret_t
setup_flow_nat(void)
{
    sdk_ret_t       ret = SDK_RET_OK;
    mac_addr_t      host_mac;
    uint8_t         vnic_stats_mask[PDS_FLOW_STATS_MASK_LEN];
    uint32_t        s2h_session_rewrite_id, s2h_ipv6_session_rewrite_id;
    uint32_t        h2s_session_rewrite_id, h2s_ipv6_session_rewrite_id;
    uint32_t        ipv4_session_id, ipv6_session_id;

    // Setup VNIC Mappings
    ret = vlan_to_vnic_map(g_h2s_nat_vlan, g_nat_vnic_id);
    if (ret != SDK_RET_OK) {
        return ret;
    }

    // Setup VNIC Mappings
    ret = mpls_label_to_vnic_map(mpls2_label, g_nat_vnic_id);
    if (ret != SDK_RET_OK) {
        return ret;
    }

    /* TODO: DNAT mapping */

    s2h_session_rewrite_id = g_session_rewrite_index++;

    ret = create_s2h_session_rewrite_nat_ipv4(s2h_session_rewrite_id,
                    (mac_addr_t*)ep_dmac, (mac_addr_t*)ep_smac, g_h2s_nat_vlan,
                    REWRITE_NAT_TYPE_IPV4_DNAT, (ipv4_addr_t)g_h2s_sip);
    if (ret != SDK_RET_OK) {
        return ret;
    }

    h2s_session_rewrite_id = g_session_rewrite_index++;

    ret = create_h2s_session_rewrite_mplsoudp_nat_ipv4(h2s_session_rewrite_id,
        &substrate_dmac, &substrate_smac,
        substrate_vlan,
        substrate_sip, substrate_dip,
        mpls1_label, mpls2_label,
        REWRITE_NAT_TYPE_IPV4_SNAT, (ipv4_addr_t)g_h2s_nat_sip);
    if (ret != SDK_RET_OK) {
        return ret;
    }

    ipv4_session_id = g_session_index;
    g_session_index++;

    memset(&host_mac, 0, sizeof(host_mac));
    ret = create_session_info_all(ipv4_session_id, /*conntrack_id*/0,
                /*skip_flow_log*/ FALSE, /*host_mac*/ &host_mac,

                /*h2s_epoch_vnic*/ 0, /*h2s_epoch_vnic_id*/ 0,
                /*h2s_epoch_mapping*/0, /*h2s_epoch_mapping_id*/0,
                /*h2s_policer_bw1_id*/0, /*h2s_policer_bw2_id*/0,
                /*h2s_vnic_stats_id*/0, /*h2s_vnic_stats_mask*/ vnic_stats_mask,
                /*h2s_vnic_histogram_latency_id*/0, /*h2s_vnic_histogram_packet_len_id*/0,
                /*h2s_tcp_flags_bitmap*/0,
                /*h2s_session_rewrite_id*/ h2s_session_rewrite_id,
                /*h2s_allowed_flow_state_bitmask*/0,
                /*h2s_egress_action*/EGRESS_ACTION_NONE,

                /*s2h_epoch_vnic*/ 0, /*s2h_epoch_vnic_id*/ 0,
                /*s2h_epoch_mapping*/0, /*s2h_epoch_mapping_id*/0,
                /*s2h_policer_bw1_id*/0, /*s2h_policer_bw2_id*/0,
                /*s2h_vnic_stats_id*/0, /*s2h_vnic_stats_mask*/ vnic_stats_mask,
                /*s2h_vnic_histogram_latency_id*/0, /*s2h_vnic_histogram_packet_len_id*/0,
                /*s2h_tcp_flags_bitmap*/0,
                /*s2h_session_rewrite_id*/ s2h_session_rewrite_id,
                /*s2h_allowed_flow_state_bitmask*/0,
                /*s2h_egress_action*/EGRESS_ACTION_NONE
                );
    if (ret != SDK_RET_OK) {
        return ret;
    }

    // Setup Normalized UDP IPv4 Flow entry
    ret = create_flow_v4_tcp_udp(g_nat_vnic_id, g_h2s_sip, g_h2s_dip,
            g_h2s_proto_udp, g_h2s_sport, g_h2s_dport,
            PDS_FLOW_SPEC_INDEX_SESSION, ipv4_session_id);
    if (ret != SDK_RET_OK) {
        return ret;
    }

    /* IPV6 flow and associated session */
    /* TODO: DNAT mapping */

    s2h_ipv6_session_rewrite_id = g_session_rewrite_index++;

    ret = create_s2h_session_rewrite_nat_ipv6(s2h_ipv6_session_rewrite_id,
                    (mac_addr_t*)ep_dmac, (mac_addr_t*)ep_smac, g_h2s_nat_vlan,
                    REWRITE_NAT_TYPE_IPV6_DNAT, &g_h2s_sipv6);
    if (ret != SDK_RET_OK) {
        return ret;
    }

    h2s_ipv6_session_rewrite_id = g_session_rewrite_index++;

    ret = create_h2s_session_rewrite_mplsoudp_nat_ipv6(h2s_ipv6_session_rewrite_id,
        &substrate_dmac, &substrate_smac,
        substrate_vlan,
        substrate_sip, substrate_dip,
        mpls1_label, mpls2_label,
        REWRITE_NAT_TYPE_IPV6_SNAT, &g_h2s_nat_sipv6);
    if (ret != SDK_RET_OK) {
        return ret;
    }

    ipv6_session_id = g_session_index;
    g_session_index++;
    ret = create_session_info_all(ipv6_session_id, /*conntrack_id*/0,
                /*skip_flow_log*/ FALSE, /*host_mac*/ &host_mac,

                /*h2s_epoch_vnic*/ 0, /*h2s_epoch_vnic_id*/ 0,
                /*h2s_epoch_mapping*/0, /*h2s_epoch_mapping_id*/0,
                /*h2s_policer_bw1_id*/0, /*h2s_policer_bw2_id*/0,
                /*h2s_vnic_stats_id*/0, /*h2s_vnic_stats_mask*/ vnic_stats_mask,
                /*h2s_vnic_histogram_latency_id*/0, /*h2s_vnic_histogram_packet_len_id*/0,
                /*h2s_tcp_flags_bitmap*/0,
                /*h2s_session_rewrite_id*/ h2s_ipv6_session_rewrite_id,
                /*h2s_allowed_flow_state_bitmask*/0,
                /*h2s_egress_action*/EGRESS_ACTION_NONE,

                /*s2h_epoch_vnic*/ 0, /*s2h_epoch_vnic_id*/ 0,
                /*s2h_epoch_mapping*/0, /*s2h_epoch_mapping_id*/0,
                /*s2h_policer_bw1_id*/0, /*s2h_policer_bw2_id*/0,
                /*s2h_vnic_stats_id*/0, /*s2h_vnic_stats_mask*/ vnic_stats_mask,
                /*s2h_vnic_histogram_latency_id*/0, /*s2h_vnic_histogram_packet_len_id*/0,
                /*s2h_tcp_flags_bitmap*/0,
                /*s2h_session_rewrite_id*/ s2h_ipv6_session_rewrite_id,
                /*s2h_allowed_flow_state_bitmask*/0,
                /*s2h_egress_action*/EGRESS_ACTION_NONE
                );
    if (ret != SDK_RET_OK) {
        return ret;
    }

    // Setup Normalized UDP IPv6 Flow entry
    ret = create_flow_v6_tcp_udp (g_nat_vnic_id, &g_h2s_sipv6, &g_h2s_dipv6,
            g_h2s_proto_udp, g_h2s_sport, g_h2s_dport,
            PDS_FLOW_SPEC_INDEX_SESSION, ipv6_session_id);
    if (ret != SDK_RET_OK) {
        return ret;
    }

    // Setup Normalized TCP IPv4 Flow entry
    ret = create_flow_v4_tcp_udp(g_nat_vnic_id, g_h2s_sip, g_h2s_dip,
            g_h2s_proto_tcp, g_h2s_sport, g_h2s_dport,
            PDS_FLOW_SPEC_INDEX_SESSION, ipv4_session_id);
    if (ret != SDK_RET_OK) {
        return ret;
    }

    // Setup Normalized TCP IPv6 Flow entry
    ret = create_flow_v6_tcp_udp (g_nat_vnic_id, &g_h2s_sipv6, &g_h2s_dipv6,
            g_h2s_proto_tcp, g_h2s_sport, g_h2s_dport,
            PDS_FLOW_SPEC_INDEX_SESSION, ipv6_session_id);
    if (ret != SDK_RET_OK) {
        return ret;
    }

    // Setup Normalized ICMP Flow entry
    ret = create_flow_v4_icmp(g_nat_vnic_id, g_h2s_sip, g_h2s_dip,
        g_h2s_proto_icmp, g_h2s_icmp_type, g_h2s_icmp_code, g_h2s_icmp_identifier,
        PDS_FLOW_SPEC_INDEX_SESSION, ipv4_session_id);
    if (ret != SDK_RET_OK) {
        return ret;
    }

    // Setup Normalized ICMPv6 Flow entry
    ret = create_flow_v6_icmp(g_nat_vnic_id, &g_h2s_sipv6, &g_h2s_dipv6,
        g_h2s_icmpv6_proto, 
        g_h2s_icmpv6_type, g_h2s_icmpv6_code, g_h2s_icmpv6_identifier,
        PDS_FLOW_SPEC_INDEX_SESSION, ipv6_session_id);
    if (ret != SDK_RET_OK) {
        return ret;
    }

    return ret;
}

sdk_ret_t
athena_gtest_setup_flows_nat(void)
{
    sdk_ret_t       ret = SDK_RET_OK;

    ret = setup_flow_nat();

    if (ret != SDK_RET_OK) {
        return ret;
    }

    return ret;

}

/*
 * Host to Switch UDP flow: Packet to be sent
 */
static uint8_t g_snd_pkt_ipv4_udp_h2s[] = {
    0x00, 0x00, 0xF1, 0xD0, 0xD1, 0xD0, 0x00, 0x00,
    0x00, 0x40, 0x08, 0x01, 0x81, 0x00, 0x00, 0x05,
    0x08, 0x00, 0x45, 0x00, 0x00, 0x50, 0x00, 0x01,
    0x00, 0x00, 0x40, 0x11, 0xB6, 0x9A, 0x02, 0x00,
    0x00, 0x01, 0xC0, 0x00, 0x02, 0x01, 0x03, 0xE8,
    0x27, 0x10, 0x00, 0x3C, 0x00, 0x00, 0x61, 0x62,
    0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6A,
    0x6C, 0x6B, 0x6D, 0x6E, 0x6F, 0x70, 0x71, 0x72,
    0x73, 0x74, 0x75, 0x76, 0x77, 0x7A, 0x78, 0x79,
    0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68,
    0x69, 0x6A, 0x6C, 0x6B, 0x6D, 0x6E, 0x6F, 0x70,
    0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x7A,
    0x78, 0x79
};


/*
 * Host to Switch UDP flow: Expected Packet
 */
static uint8_t g_rcv_pkt_ipv4_udp_h2s[] = {
    0x00, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x00, 0x01,
    0x02, 0x03, 0x04, 0x05, 0x81, 0x00, 0x00, 0x02,
    0x08, 0x00, 0x45, 0x00, 0x00, 0x74, 0x00, 0x00,
    0x00, 0x00, 0x40, 0x11, 0x70, 0x70, 0x04, 0x03,
    0x02, 0x01, 0x01, 0x02, 0x03, 0x04, 0x6e, 0xc2,
    0x19, 0xeb, 0x00, 0x60, 0x00, 0x00, 0x12, 0x34,
    0x50, 0x40, 0x67, 0x89, 0xe1, 0x40, 0x45, 0x00,
    0x00, 0x50, 0x00, 0x01, 0x00, 0x00, 0x40, 0x11,
    0xb5, 0x9a, 0x03, 0x00, 0x00, 0x01, 0xc0, 0x00,
    0x02, 0x01, 0x03, 0xe8, 0x27, 0x10, 0x00, 0x3c,
    0xf2, 0x44, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66,
    0x67, 0x68, 0x69, 0x6a, 0x6c, 0x6b, 0x6d, 0x6e,
    0x6f, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76,
    0x77, 0x7a, 0x78, 0x79, 0x61, 0x62, 0x63, 0x64,
    0x65, 0x66, 0x67, 0x68, 0x69, 0x6a, 0x6c, 0x6b,
    0x6d, 0x6e, 0x6f, 0x70, 0x71, 0x72, 0x73, 0x74,
    0x75, 0x76, 0x77, 0x7a, 0x78, 0x79
};





/*
 * Host to Switch IPv6 UDP flow: Packet to be sent
 */
static uint8_t g_snd_pkt_ipv6_udp_h2s[] = {
    0x00, 0x00, 0xF1, 0xD0, 0xD1, 0xD0, 0x00, 0x00,
    0x00, 0x40, 0x08, 0x01, 0x81, 0x00, 0x00, 0x05,
    0x86, 0xDD, 0x60, 0x00, 0x00, 0x00, 0x00, 0x3C,
    0x11, 0x40, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x01, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x02, 0x01, 0x03, 0xE8, 0x27, 0x10, 0x00, 0x3C,
    0xA7, 0x45, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66,
    0x67, 0x68, 0x69, 0x6A, 0x6C, 0x6B, 0x6D, 0x6E,
    0x6F, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76,
    0x77, 0x7A, 0x78, 0x79, 0x61, 0x62, 0x63, 0x64,
    0x65, 0x66, 0x67, 0x68, 0x69, 0x6A, 0x6C, 0x6B,
    0x6D, 0x6E, 0x6F, 0x70, 0x71, 0x72, 0x73, 0x74,
    0x75, 0x76, 0x77, 0x7A, 0x78, 0x79
};
/*
 * Host to Switch IPv6 UDP flow: Expected Packet
 */
static uint8_t g_rcv_pkt_ipv6_udp_h2s[] = {
    0x00, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x00, 0x01,
    0x02, 0x03, 0x04, 0x05, 0x81, 0x00, 0x00, 0x02,
    0x08, 0x00, 0x45, 0x00, 0x00, 0x88, 0x00, 0x00,
    0x00, 0x00, 0x40, 0x11, 0x70, 0x5c, 0x04, 0x03,
    0x02, 0x01, 0x01, 0x02, 0x03, 0x04, 0x7f, 0x59,
    0x19, 0xeb, 0x00, 0x74, 0x00, 0x00, 0x12, 0x34,
    0x50, 0x40, 0x67, 0x89, 0xe1, 0x40, 0x60, 0x00,
    0x00, 0x00, 0x00, 0x3c, 0x11, 0x40, 0x03, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x0c, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x02, 0x01, 0x03, 0xe8,
    0x27, 0x10, 0x00, 0x3c, 0xa6, 0x45, 0x61, 0x62,
    0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6a,
    0x6c, 0x6b, 0x6d, 0x6e, 0x6f, 0x70, 0x71, 0x72,
    0x73, 0x74, 0x75, 0x76, 0x77, 0x7a, 0x78, 0x79,
    0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68,
    0x69, 0x6a, 0x6c, 0x6b, 0x6d, 0x6e, 0x6f, 0x70,
    0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x7a,
    0x78, 0x79
};

/*
 * Host to Switch TCP flow: Packet to be sent
 */
static uint8_t g_snd_pkt_ipv4_tcp_h2s[] = {
    0x00, 0x00, 0xF1, 0xD0, 0xD1, 0xD0, 0x00, 0x00,
    0x00, 0x40, 0x08, 0x01, 0x81, 0x00, 0x00, 0x05,
    0x08, 0x00, 0x45, 0x00, 0x00, 0x5C, 0x00, 0x00,
    0x00, 0x00, 0x40, 0x06, 0xB6, 0x9A, 0x02, 0x00,
    0x00, 0x01, 0xC0, 0x00, 0x02, 0x01, 0x03, 0xE8,
    0x27, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x50, 0x02, 0x20, 0x00, 0x83, 0x7D,
    0x00, 0x00, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66,
    0x67, 0x68, 0x69, 0x6A, 0x6C, 0x6B, 0x6D, 0x6E,
    0x6F, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76,
    0x77, 0x7A, 0x78, 0x79, 0x61, 0x62, 0x63, 0x64,
    0x65, 0x66, 0x67, 0x68, 0x69, 0x6A, 0x6C, 0x6B,
    0x6D, 0x6E, 0x6F, 0x70, 0x71, 0x72, 0x73, 0x74,
    0x75, 0x76, 0x77, 0x7A, 0x78, 0x79
};
/*
 * Host to Switch TCP flow: Expected Packet
 */

static uint8_t g_rcv_pkt_ipv4_tcp_h2s[] = {
    0x00, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x00, 0x01,
    0x02, 0x03, 0x04, 0x05, 0x81, 0x00, 0x00, 0x02,
    0x08, 0x00, 0x45, 0x00, 0x00, 0x80, 0x00, 0x00,
    0x00, 0x00, 0x40, 0x11, 0x70, 0x64, 0x04, 0x03,
    0x02, 0x01, 0x01, 0x02, 0x03, 0x04, 0x90, 0xef,
    0x19, 0xeb, 0x00, 0x6c, 0x00, 0x00, 0x12, 0x34,
    0x50, 0x40, 0x67, 0x89, 0xe1, 0x40, 0x45, 0x00,
    0x00, 0x5c, 0x00, 0x00, 0x00, 0x00, 0x40, 0x06,
    0xb5, 0x9a, 0x03, 0x00, 0x00, 0x01, 0xc0, 0x00,
    0x02, 0x01, 0x03, 0xe8, 0x27, 0x10, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x50, 0x02,
    0x20, 0x00, 0x82, 0x7d, 0x00, 0x00, 0x61, 0x62,
    0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6a,
    0x6c, 0x6b, 0x6d, 0x6e, 0x6f, 0x70, 0x71, 0x72,
    0x73, 0x74, 0x75, 0x76, 0x77, 0x7a, 0x78, 0x79,
    0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68,
    0x69, 0x6a, 0x6c, 0x6b, 0x6d, 0x6e, 0x6f, 0x70,
    0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x7a,
    0x78, 0x79
};

/*
 * Host to Switch IPv6 TCP flow: Packet to be sent
 */
static uint8_t g_snd_pkt_ipv6_tcp_h2s[] = {
    0x00, 0x00, 0xF1, 0xD0, 0xD1, 0xD0, 0x00, 0x00,
    0x00, 0x40, 0x08, 0x01, 0x81, 0x00, 0x00, 0x05,
    0x86, 0xDD, 0x60, 0x00, 0x00, 0x00, 0x00, 0x48,
    0x06, 0x40, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x01, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x02, 0x01, 0x03, 0xE8, 0x27, 0x10, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x50, 0x02,
    0x20, 0x00, 0x37, 0x7E, 0x00, 0x00, 0x61, 0x62,
    0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6A,
    0x6C, 0x6B, 0x6D, 0x6E, 0x6F, 0x70, 0x71, 0x72,
    0x73, 0x74, 0x75, 0x76, 0x77, 0x7A, 0x78, 0x79,
    0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68,
    0x69, 0x6A, 0x6C, 0x6B, 0x6D, 0x6E, 0x6F, 0x70,
    0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x7A,
    0x78, 0x79
};
/*
 * Host to Switch IPv6 TCP flow: Expected Packet
 */
static uint8_t g_rcv_pkt_ipv6_tcp_h2s[] {
    0x00, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x00, 0x01,
    0x02, 0x03, 0x04, 0x05, 0x81, 0x00, 0x00, 0x02,
    0x08, 0x00, 0x45, 0x00, 0x00, 0x94, 0x00, 0x00,
    0x00, 0x00, 0x40, 0x11, 0x70, 0x50, 0x04, 0x03,
    0x02, 0x01, 0x01, 0x02, 0x03, 0x04, 0x81, 0x74,
    0x19, 0xeb, 0x00, 0x80, 0x00, 0x00, 0x12, 0x34,
    0x50, 0x40, 0x67, 0x89, 0xe1, 0x40, 0x60, 0x00,
    0x00, 0x00, 0x00, 0x48, 0x06, 0x40, 0x03, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x0c, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x02, 0x01, 0x03, 0xe8,
    0x27, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x50, 0x02, 0x20, 0x00, 0x36, 0x7e,
    0x00, 0x00, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66,
    0x67, 0x68, 0x69, 0x6a, 0x6c, 0x6b, 0x6d, 0x6e,
    0x6f, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76,
    0x77, 0x7a, 0x78, 0x79, 0x61, 0x62, 0x63, 0x64,
    0x65, 0x66, 0x67, 0x68, 0x69, 0x6a, 0x6c, 0x6b,
    0x6d, 0x6e, 0x6f, 0x70, 0x71, 0x72, 0x73, 0x74,
    0x75, 0x76, 0x77, 0x7a, 0x78, 0x79
};



/*
 * Host to Switch ICMP flow: Packet to be sent
 */
static uint8_t g_snd_pkt_ipv4_icmp_h2s[] = {
    0x00, 0x00, 0xF1, 0xD0, 0xD1, 0xD0, 0x00, 0x00,
    0x00, 0x40, 0x08, 0x01, 0x81, 0x00, 0x00, 0x05,
    0x08, 0x00, 0x45, 0x00, 0x00, 0x50, 0x00, 0x00,
    0x00, 0x00, 0x40, 0x01, 0xB6, 0xAB, 0x02, 0x00,
    0x00, 0x01, 0xC0, 0x00, 0x02, 0x01, 0x08, 0x00,
    0xC8, 0x94, 0x12, 0x34, 0x00, 0x00, 0x61, 0x62,
    0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6A,
    0x6C, 0x6B, 0x6D, 0x6E, 0x6F, 0x70, 0x71, 0x72,
    0x73, 0x74, 0x75, 0x76, 0x77, 0x7A, 0x78, 0x79,
    0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68,
    0x69, 0x6A, 0x6C, 0x6B, 0x6D, 0x6E, 0x6F, 0x70,
    0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x7A,
    0x78, 0x79
};


/*
 * Host to Switch ICMP flow: Expected Packet
 */
static uint8_t g_rcv_pkt_ipv4_icmp_h2s[] = {
    0x00, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x00, 0x01,
    0x02, 0x03, 0x04, 0x05, 0x81, 0x00, 0x00, 0x02,
    0x08, 0x00, 0x45, 0x00, 0x00, 0x74, 0x00, 0x00,
    0x00, 0x00, 0x40, 0x11, 0x70, 0x70, 0x04, 0x03,
    0x02, 0x01, 0x01, 0x02, 0x03, 0x04, 0xaa, 0xa1,
    0x19, 0xeb, 0x00, 0x60, 0x00, 0x00, 0x12, 0x34,
    0x50, 0x40, 0x67, 0x89, 0xe1, 0x40, 0x45, 0x00,
    0x00, 0x50, 0x00, 0x00, 0x00, 0x00, 0x40, 0x01,
    0xb5, 0xab, 0x03, 0x00, 0x00, 0x01, 0xc0, 0x00,
    0x02, 0x01, 0x08, 0x00, 0xc8, 0x94, 0x12, 0x34,
    0x00, 0x00, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66,
    0x67, 0x68, 0x69, 0x6a, 0x6c, 0x6b, 0x6d, 0x6e,
    0x6f, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76,
    0x77, 0x7a, 0x78, 0x79, 0x61, 0x62, 0x63, 0x64,
    0x65, 0x66, 0x67, 0x68, 0x69, 0x6a, 0x6c, 0x6b,
    0x6d, 0x6e, 0x6f, 0x70, 0x71, 0x72, 0x73, 0x74,
    0x75, 0x76, 0x77, 0x7a, 0x78, 0x79
};

/*
 * Host to Switch IPv6 ICMP flow: Packet to be sent
 */
static uint8_t g_snd_pkt_ipv6_icmp_h2s[] = {
    0x00, 0x00, 0xF1, 0xD0, 0xD1, 0xD0, 0x00, 0x00,
    0x00, 0x40, 0x08, 0x01, 0x81, 0x00, 0x00, 0x05,
    0x86, 0xDD, 0x60, 0x00, 0x00, 0x00, 0x00, 0x40,
    0x3A, 0x40, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x01, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x02, 0x01, 0x80, 0x00, 0x40, 0x18, 0x12, 0x34,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x61, 0x62,
    0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6A,
    0x6C, 0x6B, 0x6D, 0x6E, 0x6F, 0x70, 0x71, 0x72,
    0x73, 0x74, 0x75, 0x76, 0x77, 0x7A, 0x78, 0x79,
    0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68,
    0x69, 0x6A, 0x6C, 0x6B, 0x6D, 0x6E, 0x6F, 0x70,
    0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x7A,
    0x78, 0x79
};

/*
 * Host to Switch IPv6 ICMP flow: Expected Packet
 */
static uint8_t g_rcv_pkt_ipv6_icmp_h2s[] = {
    0x00, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x00, 0x01,
    0x02, 0x03, 0x04, 0x05, 0x81, 0x00, 0x00, 0x02,
    0x08, 0x00, 0x45, 0x00, 0x00, 0x8c, 0x00, 0x00,
    0x00, 0x00, 0x40, 0x11, 0x70, 0x58, 0x04, 0x03,
    0x02, 0x01, 0x01, 0x02, 0x03, 0x04, 0x86, 0x1e,
    0x19, 0xeb, 0x00, 0x78, 0x00, 0x00, 0x12, 0x34,
    0x50, 0x40, 0x67, 0x89, 0xe1, 0x40, 0x60, 0x00,
    0x00, 0x00, 0x00, 0x40, 0x3a, 0x40, 0x03, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x0c, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x02, 0x01, 0x80, 0x00,
    0x3f, 0x18, 0x12, 0x34, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66,
    0x67, 0x68, 0x69, 0x6a, 0x6c, 0x6b, 0x6d, 0x6e,
    0x6f, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76,
    0x77, 0x7a, 0x78, 0x79, 0x61, 0x62, 0x63, 0x64,
    0x65, 0x66, 0x67, 0x68, 0x69, 0x6a, 0x6c, 0x6b,
    0x6d, 0x6e, 0x6f, 0x70, 0x71, 0x72, 0x73, 0x74,
    0x75, 0x76, 0x77, 0x7a, 0x78, 0x79
};

sdk_ret_t
athena_gtest_test_flows_nat(void)
{
    sdk_ret_t           ret = SDK_RET_OK;

    ret = send_packet("NAT-UDP-IPv4: h2s pkt", g_snd_pkt_ipv4_udp_h2s,
            sizeof(g_snd_pkt_ipv4_udp_h2s), g_h_port,
            g_rcv_pkt_ipv4_udp_h2s, sizeof(g_rcv_pkt_ipv4_udp_h2s), g_s_port);
    if (ret != SDK_RET_OK) {
        return ret;
    }
#if 0
    ret = send_packet("NAT-UDP-IPv4: s2h pkt", g_snd_pkt_ipv4_udp_s2h,
            sizeof(g_snd_pkt_ipv4_udp_s2h), g_s_port,
            g_rcv_pkt_ipv4_udp_s2h, sizeof(g_rcv_pkt_ipv4_udp_s2h), g_h_port);
    if (ret != SDK_RET_OK) {
        return ret;
    }
#endif
    ret = send_packet("NAT-UDP-IPv6: h2s pkt", g_snd_pkt_ipv6_udp_h2s,
            sizeof(g_snd_pkt_ipv6_udp_h2s), g_h_port,
            g_rcv_pkt_ipv6_udp_h2s, sizeof(g_rcv_pkt_ipv6_udp_h2s), g_s_port);
    if (ret != SDK_RET_OK) {
        return ret;
    }
#if 0
    ret = send_packet("NAT-UDP-IPv6: s2h pkt", g_snd_pkt_ipv6_udp_s2h,
            sizeof(g_snd_pkt_ipv6_udp_s2h), g_s_port,
            g_rcv_pkt_ipv6_udp_s2h, sizeof(g_rcv_pkt_ipv6_udp_s2h), g_h_port);
    if (ret != SDK_RET_OK) {
        return ret;
    }
#endif

    ret = send_packet("NAT-TCP-IPv4: h2s pkt", g_snd_pkt_ipv4_tcp_h2s,
            sizeof(g_snd_pkt_ipv4_tcp_h2s), g_h_port,
            g_rcv_pkt_ipv4_tcp_h2s, sizeof(g_rcv_pkt_ipv4_tcp_h2s), g_s_port);
    if (ret != SDK_RET_OK) {
        return ret;
    }
#if 0
    ret = send_packet("NAT-TCP-IPv4: s2h pkt", g_snd_pkt_ipv4_tcp_s2h,
            sizeof(g_snd_pkt_ipv4_tcp_s2h), g_s_port,
            g_rcv_pkt_ipv4_tcp_s2h, sizeof(g_rcv_pkt_ipv4_tcp_s2h), g_h_port);
    if (ret != SDK_RET_OK) {
        return ret;
    }
#endif

    ret = send_packet("NAT-TCP-IPv6: h2s pkt", g_snd_pkt_ipv6_tcp_h2s,
            sizeof(g_snd_pkt_ipv6_tcp_h2s), g_h_port,
            g_rcv_pkt_ipv6_tcp_h2s, sizeof(g_rcv_pkt_ipv6_tcp_h2s), g_s_port);
    if (ret != SDK_RET_OK) {
        return ret;
    }
#if 0
    ret = send_packet("NAT-TCP-IPv6: s2h pkt", g_snd_pkt_ipv6_tcp_s2h,
            sizeof(g_snd_pkt_ipv6_tcp_s2h), g_s_port,
            g_rcv_pkt_ipv6_tcp_s2h, sizeof(g_rcv_pkt_ipv6_tcp_s2h), g_h_port);
    if (ret != SDK_RET_OK) {
        return ret;
    }
#endif

    ret = send_packet("NAT-ICMP-IPv4: h2s pkt", g_snd_pkt_ipv4_icmp_h2s,
            sizeof(g_snd_pkt_ipv4_icmp_h2s), g_h_port,
            g_rcv_pkt_ipv4_icmp_h2s, sizeof(g_rcv_pkt_ipv4_icmp_h2s), g_s_port);
    if (ret != SDK_RET_OK) {
        return ret;
    }
#if 0
    ret = send_packet("NAT-ICMP-IPv4: s2h pkt", g_snd_pkt_ipv4_icmp_s2h,
            sizeof(g_snd_pkt_ipv4_icmp_s2h), g_s_port,
            g_rcv_pkt_ipv4_icmp_s2h, sizeof(g_rcv_pkt_ipv4_icmp_s2h), g_h_port);
    if (ret != SDK_RET_OK) {
        return ret;
    }
#endif
    ret = send_packet("NAT-ICMP-IPv6: h2s pkt", g_snd_pkt_ipv6_icmp_h2s,
            sizeof(g_snd_pkt_ipv6_icmp_h2s), g_h_port,
            g_rcv_pkt_ipv6_icmp_h2s, sizeof(g_rcv_pkt_ipv6_icmp_h2s), g_s_port);
    if (ret != SDK_RET_OK) {
        return ret;
    }

#if 0
    ret = send_packet("NAT-ICMP-IPv6: s2h pkt", g_snd_pkt_ipv6_icmp_s2h,
            sizeof(g_snd_pkt_ipv6_icmp_s2h), g_s_port,
            g_rcv_pkt_ipv6_icmp_s2h, sizeof(g_rcv_pkt_ipv6_icmp_s2h), g_h_port);
    if (ret != SDK_RET_OK) {
        return ret;
    }
#endif

    return ret;
}