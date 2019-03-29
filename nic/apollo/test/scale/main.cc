//
// {C} Copyright 2019 Pensando Systems Inc. All rights reserved
//
//----------------------------------------------------------------------------
///
/// \file
/// This file contains the base class implementation of test classes
///
//----------------------------------------------------------------------------

#include <gtest/gtest.h>
#include "nic/apollo/test/scale/test.hpp"
#include "nic/apollo/test/utils/base.hpp"
#include "nic/apollo/api/include/pds_batch.hpp"
#include "nic/apollo/api/include/pds_device.hpp"
#include "nic/sdk/platform/capri/capri_p4.hpp"
#include "nic/sdk/model_sim/include/lib_model_client.h"

char *g_input_cfg_file = NULL;
char *g_cfg_file = NULL;
bool g_daemon_mode = false;
string g_profile;

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
    0x00, 0x05, 0x0B, 0xE7, 0x19, 0xEB, 0x00, 0x60,
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
    0x00, 0x03, 0x2C, 0x3B, 0x19, 0xEB, 0x00, 0x60,
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
    0x00, 0x05, 0x9D, 0xDE, 0x19, 0xEB, 0x00, 0x74,
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

// Vxlan decap
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

class scale_test : public pds_test_base {
protected:
    scale_test() {}
    virtual ~scale_test() {}
    /**< called immediately after the constructor before each test */
    virtual void SetUp() {}
    /**< called immediately after each test before the destructor */
    virtual void TearDown() {}
    /**< called at the beginning of all test cases in this class */
    static void SetUpTestCase() {
        /**< call base class function */
        test_case_params_t params;
        params.cfg_file = g_cfg_file;
        params.enable_fte = false;
        params.profile = g_profile;
        pds_test_base::SetUpTestCase(params);
    }
};

#ifdef SIM
static void
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
    }

    tcid++;
    if (!vxlan_encap) {
        if (tcid_filter == 0 || tcid == tcid_filter) {
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

    exit_simulation();
}
#endif

/// \defgroup Scale
/// @{

/// Scale test
TEST_F(scale_test, scale_test_create)
{
    sdk_ret_t rv;
    pds_batch_params_t batch_params = {0};

    batch_params.epoch = 1;
    rv = pds_batch_start(&batch_params);
    ASSERT_TRUE(rv == SDK_RET_OK);
    rv = create_objects();
    ASSERT_TRUE(rv == SDK_RET_OK);
    rv = pds_batch_commit();
    ASSERT_TRUE(rv == SDK_RET_OK);

#ifdef SIM
    send_packet();
#endif
    printf("DONE pushing configs!\n");

    if (g_daemon_mode) {
        printf("Entering forever loop ...\n");
        fflush(stdout);
        while (1)
            ;
    }
}

/// @}

// print help message showing usage of this gtest
static void inline print_usage(char **argv)
{
    fprintf(stdout, "Usage : %s -c <hal.json> -i <test-config.json>\n",
            argv[0]);
}

int
main (int argc, char **argv)
{
    int oc;
    struct option longopts[] = {
        {"config",  required_argument, NULL, 'c'},
        {"daemon",  required_argument, NULL, 'd'},
        {"profile", required_argument, NULL, 'p'},
        {"help", no_argument, NULL, 'h'},
        {0, 0, 0, 0}
    };

    // parse CLI options
    while ((oc = getopt_long(argc, argv, ":hdc:i:p:W;", longopts, NULL)) != -1) {
        switch (oc) {
        case 'c':
            g_cfg_file = optarg;
            if (!g_cfg_file) {
                fprintf(stderr, "HAL config file is not specified\n");
                print_usage(argv);
                exit(1);
            }
            break;

        case 'p':
            if (optarg) {
                g_profile = std::string(optarg);
            } else {
                fprintf(stderr, "profile is not specified\n");
                print_usage(argv);
                exit(1);
            }
            break;

        case 'd':
            g_daemon_mode = true;
            break;

        case 'i':
            g_input_cfg_file = optarg;
            if (!g_input_cfg_file) {
                fprintf(stderr, "test config file is not specified\n");
                print_usage(argv);
                exit(1);
            }
            break;

        default:
            // ignore all other options
            break;
        }
    }

    // make sure cfg files exist
    if (access(g_input_cfg_file, R_OK) < 0) {
        fprintf(stderr, "Config file %s doesn't exist or not accessible\n",
                g_input_cfg_file);
        exit(1);
    }

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
