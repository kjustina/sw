//----------------------------------------------------------------------------
//
// {C} Copyright 2019 Pensando Systems Inc. All rights reserved
//
//----------------------------------------------------------------------------

#include <gtest/gtest.h>
#include "nic/apollo/test/scale/test.hpp"
#include "nic/apollo/test/scale/pkt.hpp"
#include "nic/apollo/test/utils/base.hpp"
#include "nic/apollo/api/include/pds_batch.hpp"
#include "nic/apollo/api/include/pds_device.hpp"
#include "nic/sdk/platform/capri/capri_p4.hpp"
#include "nic/sdk/model_sim/include/lib_model_client.h"

// this packet is supposed to hit a LPM route
// Encap with LPM
uint8_t g_snd_pkt1[] = {
    0x00, 0x00, 0xF1, 0xD0, 0xD1, 0xD0, 0x00, 0x00,
    0x00, 0x40, 0x08, 0x01, 0x81, 0x00, 0x00, 0x01,
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

uint8_t g_rcv_pkt1[] = {
    0x00, 0x02, 0x0B, 0x0A, 0x0D, 0x0E, 0x00, 0x02,
    0x01, 0x00, 0x00, 0x01, 0x08, 0x00, 0x45, 0x00,
    0x00, 0x74, 0x00, 0x00, 0x00, 0x00, 0x40, 0x11,
    0x78, 0x73, 0x01, 0x00, 0x00, 0x02, 0x01, 0x00,
    0x00, 0x05, 0xC6, 0xEF, 0x19, 0xEB, 0x00, 0x60,
    0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00,
    0x01, 0x00, 0x45, 0x00, 0x00, 0x50, 0x00, 0x01,
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

// this is double tagged MPLS packet to be injected from fabric port
// Decap with LPM
uint8_t g_snd_pkt2[] = {
    0x00, 0x02, 0x01, 0x00, 0x00, 0x01, 0x00, 0x02,
    0x0B, 0x0A, 0x0D, 0x0E, 0x08, 0x00, 0x45, 0x00,
    0x00, 0x74, 0x00, 0x00, 0x00, 0x00, 0x40, 0x11,
    0x00, 0x00, 0x01, 0x00, 0x00, 0x03, 0x01, 0x00,
    0x00, 0x02, 0x92, 0xBA, 0x19, 0xEB, 0x00, 0x60,
    0x00, 0x00, 0x00, 0x40, 0x10, 0x00, 0x00, 0x00,
    0x11, 0x00, 0x45, 0x00, 0x00, 0x50, 0x00, 0x01,
    0x00, 0x00, 0x40, 0x11, 0x76, 0x9A, 0x02, 0x00,
    0x00, 0x02, 0x02, 0x00, 0x00, 0x01, 0x27, 0x10,
    0x03, 0xE8, 0x00, 0x3C, 0x00, 0x00, 0x61, 0x62,
    0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6A,
    0x6C, 0x6B, 0x6D, 0x6E, 0x6F, 0x70, 0x71, 0x72,
    0x73, 0x74, 0x75, 0x76, 0x77, 0x7A, 0x78, 0x79,
    0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68,
    0x69, 0x6A, 0x6C, 0x6B, 0x6D, 0x6E, 0x6F, 0x70,
    0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x7A,
    0x78, 0x79
};

uint8_t g_rcv_pkt2[] = {
    0x00, 0x00, 0x00, 0x40, 0x08, 0x01, 0x00, 0x00,
    0x00, 0x40, 0x09, 0x01, 0x81, 0x00, 0x00, 0x01,
    0x08, 0x00, 0x45, 0x00, 0x00, 0x50, 0x00, 0x01,
    0x00, 0x00, 0x40, 0x11, 0x76, 0x9A, 0x02, 0x00,
    0x00, 0x02, 0x02, 0x00, 0x00, 0x01, 0x27, 0x10,
    0x03, 0xE8, 0x00, 0x3C, 0x00, 0x00, 0x61, 0x62,
    0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6A,
    0x6C, 0x6B, 0x6D, 0x6E, 0x6F, 0x70, 0x71, 0x72,
    0x73, 0x74, 0x75, 0x76, 0x77, 0x7A, 0x78, 0x79,
    0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68,
    0x69, 0x6A, 0x6C, 0x6B, 0x6D, 0x6E, 0x6F, 0x70,
    0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x7A,
    0x78, 0x79
};

// Host to network without LPM
uint8_t g_snd_pkt3[] = {
    0x00, 0x00, 0xF1, 0xD0, 0xD1, 0xD0, 0x00, 0x00,
    0x00, 0x40, 0x08, 0x01, 0x81, 0x00, 0x00, 0x01,
    0x08, 0x00, 0x45, 0x00, 0x00, 0x50, 0x00, 0x01,
    0x00, 0x00, 0x40, 0x11, 0x56, 0x9B, 0x02, 0x00,
    0x00, 0x01, 0x02, 0x00, 0x20, 0x01, 0x03, 0xE8,
    0x27, 0x10, 0x00, 0x3C, 0x00, 0x00, 0x61, 0x62,
    0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6A,
    0x6C, 0x6B, 0x6D, 0x6E, 0x6F, 0x70, 0x71, 0x72,
    0x73, 0x74, 0x75, 0x76, 0x77, 0x7A, 0x78, 0x79,
    0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68,
    0x69, 0x6A, 0x6C, 0x6B, 0x6D, 0x6E, 0x6F, 0x70,
    0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x7A,
    0x78, 0x79
};

uint8_t g_rcv_pkt3[] = {
    0x00, 0x02, 0x0B, 0x0A, 0x0D, 0x0E, 0x00, 0x02,
    0x01, 0x00, 0x00, 0x01, 0x08, 0x00, 0x45, 0x00,
    0x00, 0x74, 0x00, 0x00, 0x00, 0x00, 0x40, 0x11,
    0x78, 0x75, 0x01, 0x00, 0x00, 0x02, 0x01, 0x00,
    0x00, 0x03, 0xF6, 0x8B, 0x19, 0xEB, 0x00, 0x60,
    0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x40,
    0x11, 0x00, 0x45, 0x00, 0x00, 0x50, 0x00, 0x01,
    0x00, 0x00, 0x40, 0x11, 0x56, 0x9B, 0x02, 0x00,
    0x00, 0x01, 0x02, 0x00, 0x20, 0x01, 0x03, 0xE8,
    0x27, 0x10, 0x00, 0x3C, 0x00, 0x00, 0x61, 0x62,
    0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6A,
    0x6C, 0x6B, 0x6D, 0x6E, 0x6F, 0x70, 0x71, 0x72,
    0x73, 0x74, 0x75, 0x76, 0x77, 0x7A, 0x78, 0x79,
    0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68,
    0x69, 0x6A, 0x6C, 0x6B, 0x6D, 0x6E, 0x6F, 0x70,
    0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x7A,
    0x78, 0x79
};

// IPV6 with LPM
uint8_t g_snd_pkt4[] = {
    0x00, 0x00, 0xF1, 0xD0, 0xD1, 0xD0, 0x00, 0x00,
    0x00, 0x40, 0x08, 0x01, 0x81, 0x00, 0x00, 0x01,
    0x86, 0xDD, 0x60, 0x00, 0x00, 0x00, 0x00, 0x3C,
    0x11, 0x40, 0x20, 0x19, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00,
    0x00, 0x01, 0x20, 0x21, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xF1, 0xD0, 0xD1, 0xD0, 0xC0, 0x00,
    0x02, 0x01, 0x03, 0xE8, 0x27, 0x10, 0x00, 0x3C,
    0x00, 0x00, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66,
    0x67, 0x68, 0x69, 0x6A, 0x6C, 0x6B, 0x6D, 0x6E,
    0x6F, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76,
    0x77, 0x7A, 0x78, 0x79, 0x61, 0x62, 0x63, 0x64,
    0x65, 0x66, 0x67, 0x68, 0x69, 0x6A, 0x6C, 0x6B,
    0x6D, 0x6E, 0x6F, 0x70, 0x71, 0x72, 0x73, 0x74,
    0x75, 0x76, 0x77, 0x7A, 0x78, 0x79
};

uint8_t g_rcv_pkt4[] = {
    0x00, 0x02, 0x0B, 0x0A, 0x0D, 0x0E, 0x00, 0x02,
    0x01, 0x00, 0x00, 0x01, 0x08, 0x00, 0x45, 0x00,
    0x00, 0x88, 0x00, 0x00, 0x00, 0x00, 0x40, 0x11,
    0x78, 0x5F, 0x01, 0x00, 0x00, 0x02, 0x01, 0x00,
    0x00, 0x05, 0xD9, 0x6F, 0x19, 0xEB, 0x00, 0x74,
    0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00,
    0x01, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x3C,
    0x11, 0x40, 0x20, 0x19, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00,
    0x00, 0x01, 0x20, 0x21, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xF1, 0xD0, 0xD1, 0xD0, 0xC0, 0x00,
    0x02, 0x01, 0x03, 0xE8, 0x27, 0x10, 0x00, 0x3C,
    0x00, 0x00, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66,
    0x67, 0x68, 0x69, 0x6A, 0x6C, 0x6B, 0x6D, 0x6E,
    0x6F, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76,
    0x77, 0x7A, 0x78, 0x79, 0x61, 0x62, 0x63, 0x64,
    0x65, 0x66, 0x67, 0x68, 0x69, 0x6A, 0x6C, 0x6B,
    0x6D, 0x6E, 0x6F, 0x70, 0x71, 0x72, 0x73, 0x74,
    0x75, 0x76, 0x77, 0x7A, 0x78, 0x79
};


// Vxlan decap : vnid 100
uint8_t g_snd_pkt5[] = {
    0x00, 0x02, 0x01, 0x00, 0x00, 0x01, 0x00, 0x02,
    0x0B, 0x0A, 0x0D, 0x0E, 0x08, 0x00, 0x45, 0x00,
    0x00, 0x4E, 0x00, 0x01, 0x00, 0x00, 0x40, 0x11,
    0x78, 0x9A, 0x01, 0x00, 0x00, 0x03, 0x01, 0x00,
    0x00, 0x02, 0x7B, 0xF3, 0x12, 0xB5, 0x00, 0x3A,
    0x51, 0x82, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x64, 0x00, 0x00, 0x00, 0x00, 0x40, 0x08, 0x01,
    0x00, 0x00, 0x00, 0x40, 0x08, 0x02, 0x08, 0x00,
    0x45, 0x00, 0x00, 0x1C, 0x00, 0x01, 0x00, 0x00,
    0x40, 0x11, 0x76, 0xAF, 0x02, 0x00, 0x00, 0x21,
    0x02, 0x00, 0x00, 0x01, 0x00, 0x64, 0x00, 0x64,
    0x00, 0x08, 0xFA, 0xF4, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xFE, 0xED, 0xBE, 0xEF, 0x00, 0x00,
    0x00, 0x00
};

uint8_t g_rcv_pkt5[] = {
    0x00, 0x00, 0x00, 0x40, 0x08, 0x01, 0x00, 0x00,
    0x02, 0x00, 0x00, 0x00, 0x81, 0x00, 0x00, 0x64,
    0x08, 0x00, 0x45, 0x00, 0x00, 0x1c, 0x00, 0x01,
    0x00, 0x00, 0x40, 0x11, 0x76, 0xaf, 0x02, 0x00,
    0x00, 0x21, 0x02, 0x00, 0x00, 0x01, 0x00, 0x64,
    0x00, 0x64, 0x00, 0x08, 0xfa, 0xf4, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xfe, 0xed, 0xbe, 0xef,
    0x00, 0x00, 0x00, 0x00
};

uint8_t g_snd_vnic_tx_untagged[] = {
    0x00, 0x00, 0x00, 0x40, 0x08, 0x02, 0x00, 0x00,
    0x00, 0x40, 0x08, 0x01, 0x08, 0x00, 0x45, 0x00,
    0x00, 0x32, 0x00, 0x00, 0x00, 0x00, 0x40, 0x11,
    0x76, 0xb2, 0x02, 0x00, 0x00, 0x01, 0x02, 0x00,
    0x00, 0x09, 0x00, 0x64, 0x00, 0x64, 0x00, 0x1e,
    0x8c, 0x67, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05,
    0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d,
    0x0e, 0x0f, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15
};

#ifdef SIM
void
send_packet (void)
{
    uint32_t port = 0;
    uint32_t cos = 0;
    std::vector<uint8_t> ipkt;
    std::vector<uint8_t> opkt;
    std::vector<uint8_t> epkt;
    uint32_t i = 0;
    uint32_t tcscale = 1;
    int tcid = 0;
    int tcid_filter = 0;
    char *tep_encap_env;
    bool vxlan_encap = false;

    if (getenv("TCSCALE")) {
        tcscale = atoi(getenv("TCSCALE"));
    }

    if (getenv("TCID")) {
        tcid_filter = atoi(getenv("TCID"));
        printf("TCID given: %d\n", tcid_filter);
    }

    if (getenv("APOLLO_TEST_TEP_ENCAP")) {
        tep_encap_env = getenv("APOLLO_TEST_TEP_ENCAP");
        printf("TEP encap env var: %s\n", tep_encap_env);
        if (!strcmp(tep_encap_env, "vxlan")) {
            vxlan_encap = true;
        } else {
            vxlan_encap = false;
        }
        printf("VXLAN Encap: %s\n", vxlan_encap ? "yes" : "no");
    }

    tcid++;
    if (!vxlan_encap) {
        if (tcid_filter == 0 || tcid == tcid_filter) {
            printf("Test with Pkt1\n");
            ipkt.resize(sizeof(g_snd_pkt1));
            memcpy(ipkt.data(), g_snd_pkt1, sizeof(g_snd_pkt1));
            epkt.resize(sizeof(g_rcv_pkt1));
            memcpy(epkt.data(), g_rcv_pkt1, sizeof(g_rcv_pkt1));
            std::cout << "Testing Host to Switch" << std::endl;
            for (i = 0; i < tcscale; i++) {
                testcase_begin(tcid, i + 1);
                step_network_pkt(ipkt, TM_PORT_UPLINK_0);
                if (!getenv("SKIP_VERIFY")) {
                    get_next_pkt(opkt, port, cos);
                    EXPECT_TRUE(opkt == epkt);
                    EXPECT_TRUE(port == TM_PORT_UPLINK_1);
                }
                testcase_end(tcid, i + 1);
            }
        }
    }

    tcid++;
    if (!vxlan_encap) {
        if (tcid_filter == 0 || tcid == tcid_filter) {
            ipkt.resize(sizeof(g_snd_pkt2));
            memcpy(ipkt.data(), g_snd_pkt2, sizeof(g_snd_pkt2));
            epkt.resize(sizeof(g_rcv_pkt2));
            memcpy(epkt.data(), g_rcv_pkt2, sizeof(g_rcv_pkt2));
            std::cout << "Testing Switch to Host" << std::endl;
            for (i = 0; i < tcscale; i++) {
                testcase_begin(tcid, i+1);
                step_network_pkt(ipkt, TM_PORT_UPLINK_1);
                if (!getenv("SKIP_VERIFY")) {
                    get_next_pkt(opkt, port, cos);
                    EXPECT_TRUE(opkt == epkt);
                    EXPECT_TRUE(port == TM_PORT_UPLINK_0);
                }
                testcase_end(tcid, i+1);
            }
        }
    }

    tcid++;
    if (!vxlan_encap) {
        if (tcid_filter == 0 || tcid == tcid_filter) {
            ipkt.resize(sizeof(g_snd_pkt3));
            memcpy(ipkt.data(), g_snd_pkt3, sizeof(g_snd_pkt3));
            epkt.resize(sizeof(g_rcv_pkt3));
            memcpy(epkt.data(), g_rcv_pkt3, sizeof(g_rcv_pkt3));
            std::cout << "Testing Host to Switch" << std::endl;
            for (i = 0; i < tcscale; i++) {
                testcase_begin(tcid, i + 1);
                step_network_pkt(ipkt, TM_PORT_UPLINK_0);
                if (!getenv("SKIP_VERIFY")) {
                    get_next_pkt(opkt, port, cos);
                    EXPECT_TRUE(opkt == epkt);
                    EXPECT_TRUE(port == TM_PORT_UPLINK_1);
                }
                testcase_end(tcid, i + 1);
            }
        }
    }

    // Start V6
    tcid++;
    if (!vxlan_encap) {
        if (tcid_filter == 0 || tcid == tcid_filter) {
            ipkt.resize(sizeof(g_snd_pkt4));
            memcpy(ipkt.data(), g_snd_pkt4, sizeof(g_snd_pkt4));
            epkt.resize(sizeof(g_rcv_pkt4));
            memcpy(epkt.data(), g_rcv_pkt4, sizeof(g_rcv_pkt4));
            std::cout << "Testing Host to Switch" << std::endl;
            for (i = 0; i < tcscale; i++) {
                testcase_begin(tcid, i + 1);
                step_network_pkt(ipkt, TM_PORT_UPLINK_0);
                if (!getenv("SKIP_VERIFY")) {
                    get_next_pkt(opkt, port, cos);
                    EXPECT_TRUE(opkt == epkt);
                    EXPECT_TRUE(port == TM_PORT_UPLINK_1);
                }
                testcase_end(tcid, i + 1);
            }
        }
    }

    // VxLAN
    tcid++;
    if (vxlan_encap) {
        if (tcid_filter == 0 || tcid == tcid_filter) {
            ipkt.resize(sizeof(g_snd_pkt5));
            memcpy(ipkt.data(), g_snd_pkt5, sizeof(g_snd_pkt5));
            epkt.resize(sizeof(g_rcv_pkt5));
            memcpy(epkt.data(), g_rcv_pkt5, sizeof(g_rcv_pkt5));
            std::cout << "Testing Switch to Host" << std::endl;
            for (i = 0; i < tcscale; i++) {
                testcase_begin(tcid, i + 1);
                step_network_pkt(ipkt, TM_PORT_UPLINK_1);
                if (!getenv("SKIP_VERIFY")) {
                    get_next_pkt(opkt, port, cos);
                    EXPECT_TRUE(opkt == epkt);
                    EXPECT_TRUE(port == TM_PORT_UPLINK_0);
                }
                testcase_end(tcid, i + 1);
            }
        }
    }

    // VxLAN
    tcid++;
    if (vxlan_encap) {
        if (tcid_filter == 0 || tcid == tcid_filter) {
            ipkt.resize(sizeof(g_snd_vnic_tx_untagged));
            memcpy(ipkt.data(), g_snd_vnic_tx_untagged,
                    sizeof(g_snd_vnic_tx_untagged));
            epkt.resize(sizeof(g_rcv_pkt5));
            memcpy(epkt.data(), g_rcv_pkt5, sizeof(g_rcv_pkt5));
            std::cout << "Testing Switch to Host" << std::endl;
            for (i = 0; i < tcscale; i++) {
                testcase_begin(tcid, i + 1);
                step_network_pkt(ipkt, TM_PORT_UPLINK_1);
                if (!getenv("SKIP_VERIFY")) {
                    get_next_pkt(opkt, port, cos);
                    EXPECT_TRUE(opkt == epkt);
                    EXPECT_TRUE(port == TM_PORT_UPLINK_0);
                }
                testcase_end(tcid, i + 1);
            }
        }
    }

    exit_simulation();
}
#endif
