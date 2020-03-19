/*
 * Copyright (c) 2020, Pensando Systems Inc.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <getopt.h>
#include <cinttypes>

#include "cap_top_csr_defines.h"
#include "cap_pp_c_hdr.h"

#include "platform/pal/include/pal.h"
#include "nic/sdk/platform/pciemgr/include/pciemgr.h"
#include "nic/sdk/platform/pcieport/include/pcieport.h"
#include "nic/sdk/platform/pcieport/include/portcfg.h"

#include "cmd.h"
#include "utils.hpp"

static void
healthdetails(int argc, char *argv[])
{
    int opt, port;

    port = default_pcieport();
    optind = 0;
    while ((opt = getopt(argc, argv, "p:")) != -1) {
        switch (opt) {
        case 'p':
            port = strtoul(optarg, NULL, 0);
            break;
        default:
            return;
        }
    }

    if (!pcieport_is_accessible(port)) {
        fprintf(stderr, "port%d not accessible\n", port);
        return;
    }

    const uint16_t port_lanes = pal_reg_rd32(PP_(PORT_P_STA_P_PORT_LANES_7_0));
    printf("port_lanes.detected: 0x%02x\n", port_lanes & 0xff);
    printf("port_lanes.active:   0x%02x\n", (port_lanes >> 8) & 0xff);

    // check mac gen/width if uboot misconfigured
    const uint64_t kgen = pal_reg_rd64_safe(PXC_(CFG_C_MAC_K_GEN, port));
    printf("port%d mac_k_gen 0x%" PRIx64 "\n", port, kgen);

    const uint16_t lnksta2 = portcfg_readw(port, PORTCFG_CAP_PCIE + 0x32);
    printf("port%d lnksta2: 0x%04x", port, lnksta2);
#define PRBIT(v, pos, name) \
    printf(" %s%c", #name, (v) & (1 << (pos)) ? '+' : '-')
    PRBIT(lnksta2,  0, Deemph);
    PRBIT(lnksta2,  1, EqualCmp);
    PRBIT(lnksta2,  2, EqualPh1);
    PRBIT(lnksta2,  3, EqualPh2);
    PRBIT(lnksta2,  4, EqualPh3);
    PRBIT(lnksta2,  5, EqualReq);
    PRBIT(lnksta2,  6, Retimer);
    PRBIT(lnksta2,  7, Retimer2);
    PRBIT(lnksta2, 15, DRSMsg);
    printf("\n");
}
CMDFUNC(healthdetails,
"pcie link health details",
"healthdetails [-p <port>\n"
"    -p <port>  show port <port> (default port 0)\n");

//
// Dump health data. This command is used by pcie_healthlog.sh script
// when a pcie link health check triggers a full log event.
//
static void
healthdump(int argc, char *argv[])
{
    static const char *cmdlist[] = {
        "pcieutil counters",
        "pcieutil port -p %d",
        "pcieutil portstats -p %d",
        "pcieutil stats -p %d",
        "pcieutil portaer -p %d",
        "pcieutil portcfg -p %d -xxxx",
        "pcieutil healthdetails -p %d",
        "pcieutil aximst -p %d",
        "pcieutil serdesfw",
        NULL
    };
    int opt, port;

    port = default_pcieport();
    optind = 0;
    while ((opt = getopt(argc, argv, "p:")) != -1) {
        switch (opt) {
        case 'p':
            port = strtoul(optarg, NULL, 0);
            break;
        default:
            return;
        }
    }

    for (const char **cmd = cmdlist; *cmd; cmd++) {
        // make a local copy for cmd_runstr to edit
        char cmdstr[80];
        snprintf(cmdstr, sizeof(cmdstr), *cmd, port);

        printf("================\n"
               "%s\n"
               "----------------\n", cmdstr);
        cmd_runstr(cmdstr);
    }
}
CMDFUNC(healthdump,
"pcie link health dump",
"healthdump [-p <port>\n"
"    -p <port>  show port <port> (default port 0)\n");
