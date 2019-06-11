
#include <cassert>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <boost/lexical_cast.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#include "nic/include/adminq.h"
#include "nic/include/edmaq.h"
#include "nic/include/eth_common.h"
#include "nic/include/notify.hpp"
#include "nic/sdk/lib/pal/pal.hpp"
#include "nic/sdk/lib/p4/p4_api.hpp"
#include "nic/sdk/lib/p4/p4_utils.hpp"
#include "lib/table/directmap/directmap.hpp"
#include "lib/table/common/table.hpp"
#include "platform/capri/capri_common.hpp"
#include "platform/src/lib/nicmgr/include/eth_if.h"
#include "platform/utils/mpartition.hpp"
#include "platform/capri/capri_tbl_rw.hpp"
#include "nic/sdk/platform/devapi/devapi_types.hpp"
#include "nic/sdk/platform/capri/capri_state.hpp"

#include "gen/platform/mem_regions.hpp"

#include "third-party/asic/capri/model/cap_top/cap_top_csr_defines.h"
#include "third-party/asic/capri/model/cap_top/csr_defines/cap_wa_c_hdr.h"
#include "third-party/asic/capri/model/cap_top/csr_defines/cap_pics_c_hdr.h"

#if defined(APOLLO)
#include "gen/p4gen/apollo_rxdma/include/apollo_rxdma_p4pd.h"
#include "gen/p4gen/apollo_rxdma/include/apollo_rxdma_p4pd_table.h"
#include "gen/p4gen/apollo_txdma/include/apollo_txdma_p4pd.h"
#include "gen/p4gen/apollo_txdma/include/apollo_txdma_p4pd_table.h"
#elif defined(ARTEMIS)
#include "gen/p4gen/artemis_rxdma/include/artemis_rxdma_p4pd.h"
#include "gen/p4gen/artemis_rxdma/include/artemis_rxdma_p4pd_table.h"
#include "gen/p4gen/artemis_txdma/include/artemis_txdma_p4pd.h"
#include "gen/p4gen/artemis_txdma/include/artemis_txdma_p4pd_table.h"
#else
#include "gen/platform/mem_regions.hpp"
#include "gen/p4gen/common_rxdma_actions/include/common_rxdma_actions_p4pd.h"
#include "gen/p4gen/common_rxdma_actions/include/common_rxdma_actions_p4pd_table.h"
#include "gen/p4gen/common_txdma_actions/include/common_txdma_actions_p4pd.h"
#include "gen/p4gen/common_txdma_actions/include/common_txdma_actions_p4pd_table.h"
#endif

#define ENTRY_TRACE_EN                      true

// Maximum number of queue per LIF
#define ETH_RSS_MAX_QUEUES                  (128)
// Number of entries in a LIF's indirection table
#define ETH_RSS_LIF_INDIR_TBL_LEN           ETH_RSS_MAX_QUEUES
// Size of each LIF indirection table entry
#define ETH_RSS_LIF_INDIR_TBL_ENTRY_SZ      (sizeof(eth_rx_rss_indir_eth_rx_rss_indir_t))
// Size of a LIF's indirection table
#define ETH_RSS_LIF_INDIR_TBL_SZ            (ETH_RSS_LIF_INDIR_TBL_LEN * ETH_RSS_LIF_INDIR_TBL_ENTRY_SZ)
// Max number of LIFs supported
#define MAX_LIFS                            (2048)
// Size of the entire LIF indirection table
#define ETH_RSS_INDIR_TBL_SZ                (MAX_LIFS * ETH_RSS_LIF_INDIR_TBL_SZ)
// Memory bar should be multiple of 8 MB
#define MEM_BARMAP_SIZE_SHIFT               (23)

directmap    **p4plus_rxdma_dm_tables_;
directmap    **p4plus_txdma_dm_tables_;

using namespace sdk::platform::capri;
using namespace sdk::platform::utils;

typedef struct {
    uint64_t base;
    uint32_t size;
    uint32_t length;
} queue_info_t;

static uint8_t *memrev(uint8_t *block, size_t elnum)
{
    uint8_t *s, *t, tmp;

    for (s = block, t = s + (elnum - 1); s < t; s++, t--) {
        tmp = *s;
        *s = *t;
        *t = tmp;
    }
    return block;
}

bool
get_lif_qstate(uint16_t lif, queue_info_t qinfo[8])
{
    uint32_t cnt[4] = {0};
    uint32_t size[8] = {0};
    uint32_t length[8] = {0};

    sdk::lib::pal_reg_read(CAP_ADDR_BASE_DB_WA_OFFSET +
                               CAP_WA_CSR_DHS_LIF_QSTATE_MAP_BYTE_ADDRESS + (16 * lif),
                           cnt, 4);

    // decode lif qstate table:
    uint8_t valid = CAP_WA_CSR_DHS_LIF_QSTATE_MAP_ENTRY_ENTRY_0_4_VLD_GET(cnt[0]);
    if (!valid) {
        printf("Invalid lif %u\n", lif);
        return false;
    }

    uint64_t base =
        (uint64_t)CAP_WA_CSR_DHS_LIF_QSTATE_MAP_ENTRY_ENTRY_0_4_QSTATE_BASE_GET(cnt[0]);
    // Qstate Size: 3 bit size is qstate size (32B/64B/128B)
    size[0] = CAP_WA_CSR_DHS_LIF_QSTATE_MAP_ENTRY_ENTRY_0_4_SIZE0_GET(cnt[0]);
    size[1] = CAP_WA_CSR_DHS_LIF_QSTATE_MAP_ENTRY_ENTRY_1_4_SIZE1_GET(cnt[1]);
    size[2] = CAP_WA_CSR_DHS_LIF_QSTATE_MAP_ENTRY_ENTRY_1_4_SIZE2_GET(cnt[1]);
    size[3] = CAP_WA_CSR_DHS_LIF_QSTATE_MAP_ENTRY_ENTRY_1_4_SIZE3_GET(cnt[1]);
    size[4] = CAP_WA_CSR_DHS_LIF_QSTATE_MAP_ENTRY_ENTRY_1_4_SIZE4_GET(cnt[1]);
    size[5] = CAP_WA_CSR_DHS_LIF_QSTATE_MAP_ENTRY_ENTRY_2_4_SIZE5_GET(cnt[2]);
    size[6] = CAP_WA_CSR_DHS_LIF_QSTATE_MAP_ENTRY_ENTRY_2_4_SIZE6_GET(cnt[2]);
    size[7] = CAP_WA_CSR_DHS_LIF_QSTATE_MAP_ENTRY_ENTRY_2_4_SIZE7_GET(cnt[2]);
    // log2(number_of_queues)
    length[0] = CAP_WA_CSR_DHS_LIF_QSTATE_MAP_ENTRY_ENTRY_0_4_LENGTH0_GET(cnt[0]);
    length[1] = CAP_WA_CSR_DHS_LIF_QSTATE_MAP_ENTRY_ENTRY_0_4_LENGTH1_0_0_GET(cnt[0]) |
                (CAP_WA_CSR_DHS_LIF_QSTATE_MAP_ENTRY_ENTRY_1_4_LENGTH1_4_1_GET(cnt[1]) << 1);
    length[2] = CAP_WA_CSR_DHS_LIF_QSTATE_MAP_ENTRY_ENTRY_1_4_LENGTH2_GET(cnt[1]);
    length[3] = CAP_WA_CSR_DHS_LIF_QSTATE_MAP_ENTRY_ENTRY_1_4_LENGTH3_GET(cnt[1]);
    length[4] = CAP_WA_CSR_DHS_LIF_QSTATE_MAP_ENTRY_ENTRY_1_4_LENGTH4_GET(cnt[1]);
    length[5] = CAP_WA_CSR_DHS_LIF_QSTATE_MAP_ENTRY_ENTRY_1_4_LENGTH5_0_0_GET(cnt[1]) |
                (CAP_WA_CSR_DHS_LIF_QSTATE_MAP_ENTRY_ENTRY_2_4_LENGTH5_4_1_GET(cnt[2]) << 1);
    length[6] = CAP_WA_CSR_DHS_LIF_QSTATE_MAP_ENTRY_ENTRY_2_4_LENGTH6_GET(cnt[2]);
    length[7] = CAP_WA_CSR_DHS_LIF_QSTATE_MAP_ENTRY_ENTRY_2_4_LENGTH7_GET(cnt[2]);

    base = base << 12;

    for (uint8_t qtype = 0; qtype < 8 && size[qtype] != 0; qtype++) {

        qinfo[qtype].base = base;
        qinfo[qtype].size = 32 * (1 << size[qtype]);
        qinfo[qtype].length = 1 << length[qtype];

        base += qinfo[qtype].size * qinfo[qtype].length;
    }

    return true;
}

#define NUM_POSTED(N, h, t) (h == t ? 0 : h > t ? h - t + 1 : ((N)-1) - (h - t + 1))

void
nvme_qstate(uint16_t lif, uint8_t qtype, uint32_t qid)
{
    struct admin_qstate qstate_ethaq = {0};
    struct notify_qstate qstate_notifyq = {0};
    struct edma_qstate qstate_edmaq = {0};
    nicmgr_req_qstate_t qstate_req = {0};
    nicmgr_resp_qstate_t qstate_resp = {0};
    queue_info_t qinfo[8] = {0};

    if (!get_lif_qstate(lif, qinfo)) {
        printf("Failed to get qinfo for lif %u\n", lif);
        return;
    }

    if (qinfo[qtype].size == 0) {
        printf("Invalid type %u for lif %u\n", qtype, lif);
        return;
    }

    if (qid >= qinfo[qtype].length) {
        printf("Invalid qid %u for lif %u qtype %u\n", qid, lif, qtype);
        return;
    }

    uint64_t addr = qinfo[qtype].base + qid * qinfo[qtype].size;
    printf("\naddr: 0x%lx\n\n", addr);

    switch (qtype) {
    case 0:
        sdk::lib::pal_mem_read(addr, (uint8_t *)&qstate_ethaq, sizeof(qstate_ethaq));
        printf("pc_offset=0x%0x\n"
               "rsvd0=0x%0x\n"
               "cosA=0x%0x\ncosB=0x%0x\ncos_sel=0x%0x\n"
               "eval_last=0x%0x\n"
               "host=0x%0x\ntotal=0x%0x\n"
               "pid=0x%0x\n"
               "p_index0=0x%0x\nc_index0=0x%0x\n"
               "comp_index=0x%0x\nci_fetch=0x%0x\n"
               "color=0x%0x\n"
               "enable=0x%0x\nhost_queue=0x%0x\nintr_enable=0x%0x\ndebug=0x%0x\n"
               "ring_base=0x%0lx\nring_size=0x%0x\n"
               "cq_ring_base=0x%0lx\nintr_assert_index=0x%0x\n"
               "nicmgr_qstate_addr=0x%0lx\n",
               qstate_ethaq.pc_offset, qstate_ethaq.rsvd0, qstate_ethaq.cosA, qstate_ethaq.cosB,
               qstate_ethaq.cos_sel, qstate_ethaq.eval_last, qstate_ethaq.host, qstate_ethaq.total,
               qstate_ethaq.pid, qstate_ethaq.p_index0, qstate_ethaq.c_index0,
               qstate_ethaq.comp_index, qstate_ethaq.ci_fetch, qstate_ethaq.sta.color,
               qstate_ethaq.cfg.enable, qstate_ethaq.cfg.host_queue, qstate_ethaq.cfg.intr_enable,
               qstate_ethaq.cfg.debug,
               qstate_ethaq.ring_base, qstate_ethaq.ring_size, qstate_ethaq.cq_ring_base,
               qstate_ethaq.intr_assert_index, qstate_ethaq.nicmgr_qstate_addr);
       break; 
    case 1:
        sdk::lib::pal_mem_read(addr, (uint8_t *)&qstate_ethaq, sizeof(qstate_ethaq));
        printf("pc_offset=0x%0x\n"
               "rsvd0=0x%0x\n"
               "cosA=0x%0x\ncosB=0x%0x\ncos_sel=0x%0x\n"
               "eval_last=0x%0x\n"
               "host=0x%0x\ntotal=0x%0x\n"
               "pid=0x%0x\n"
               "p_index0=0x%0x\nc_index0=0x%0x\n"
               "comp_index=0x%0x\nci_fetch=0x%0x\n"
               "color=0x%0x\n"
               "enable=0x%0x\nhost_queue=0x%0x\nintr_enable=0x%0x\ndebug=0x%0x\n"
               "ring_base=0x%0lx\nring_size=0x%0x\n"
               "cq_ring_base=0x%0lx\nintr_assert_index=0x%0x\n"
               "nicmgr_qstate_addr=0x%0lx\n",
               qstate_ethaq.pc_offset, qstate_ethaq.rsvd0, qstate_ethaq.cosA, qstate_ethaq.cosB,
               qstate_ethaq.cos_sel, qstate_ethaq.eval_last, qstate_ethaq.host, qstate_ethaq.total,
               qstate_ethaq.pid, qstate_ethaq.p_index0, qstate_ethaq.c_index0,
               qstate_ethaq.comp_index, qstate_ethaq.ci_fetch, qstate_ethaq.sta.color,
               qstate_ethaq.cfg.enable, qstate_ethaq.cfg.host_queue, qstate_ethaq.cfg.intr_enable,
               qstate_ethaq.cfg.debug,
               qstate_ethaq.ring_base, qstate_ethaq.ring_size, qstate_ethaq.cq_ring_base,
               qstate_ethaq.intr_assert_index, qstate_ethaq.nicmgr_qstate_addr); 
       break;
    case 2:
        if (qid == 0) {
            sdk::lib::pal_mem_read(addr, (uint8_t *)&qstate_req, sizeof(qstate_req));
            printf("pc_offset=0x%0x\n"
                "rsvd0=0x%0x\n"
                "cosA=0x%0x\ncosB=0x%0x\ncos_sel=0x%0x\n"
                "eval_last=0x%0x\n"
                "host=0x%0x\ntotal=0x%0x\n"
                "pid=0x%0x\n"
                "p_index0=0x%0x\nc_index0=0x%0x\n"
                "comp_index=0x%0x\nci_fetch=0x%0x\n"
                "color=0x%0x\n"
                "enable=0x%0x\nintr_enable=0x%0x\ndebug=0x%0x\n"
                "ring_base=0x%0lx\nring_size=0x%0x\n"
                "cq_ring_base=0x%0lx\nintr_assert_index=0x%0x\n",
                qstate_req.pc_offset, qstate_req.rsvd0, qstate_req.cosA, qstate_req.cosB,
                qstate_req.cos_sel, qstate_req.eval_last, qstate_req.host, qstate_req.total,
                qstate_req.pid, qstate_req.p_index0, qstate_req.c_index0, qstate_req.comp_index,
                qstate_req.ci_fetch, qstate_req.sta.color, qstate_req.cfg.enable,
                qstate_req.cfg.intr_enable, qstate_req.cfg.debug,
                qstate_req.ring_base, qstate_req.ring_size,
                qstate_req.cq_ring_base, qstate_req.intr_assert_index);
        }
        if (qid == 1) {
            sdk::lib::pal_mem_read(addr, (uint8_t *)&qstate_resp, sizeof(qstate_resp));
            printf("pc_offset=0x%0x\n"
                "rsvd0=0x%0x\n"
                "cosA=0x%0x\ncosB=0x%0x\ncos_sel=0x%0x\n"
                "eval_last=0x%0x\n"
                "host=0x%0x\ntotal=0x%0x\n"
                "pid=0x%0x\n"
                "p_index0=0x%0x\nc_index0=0x%0x\n"
                "comp_index=0x%0x\nci_fetch=0x%0x\n"
                "color=0x%0x\n"
                "enable=0x%0x\nintr_enable=0x%0x\ndebug=0x%0x\n"
                "ring_base=0x%0lx\nring_size=0x%0x\n"
                "cq_ring_base=0x%0lx\nintr_assert_index=0x%0x\n",
                qstate_resp.pc_offset, qstate_resp.rsvd0, qstate_resp.cosA, qstate_resp.cosB,
                qstate_resp.cos_sel, qstate_resp.eval_last, qstate_resp.host, qstate_resp.total,
                qstate_resp.pid, qstate_resp.p_index0, qstate_resp.c_index0, qstate_resp.comp_index,
                qstate_resp.ci_fetch, qstate_resp.sta.color, qstate_resp.cfg.enable,
                qstate_resp.cfg.intr_enable, qstate_resp.cfg.debug,
                qstate_resp.ring_base, qstate_resp.ring_size,
                qstate_resp.cq_ring_base, qstate_resp.intr_assert_index);
        }
 
        if (qid == 2) {
            sdk::lib::pal_mem_read(addr, (uint8_t *)&qstate_notifyq, sizeof(qstate_notifyq));
            printf("pc_offset=0x%0x\n"
                   "rsvd0=0x%0x\n"
                   "cosA=0x%0x\ncosB=0x%0x\ncos_sel=0x%0x\n"
                   "eval_last=0x%0x\n"
                   "host=0x%0x\ntotal=0x%0x\n"
                   "pid=0x%0x\n"
                   "p_index0=0x%0x\nc_index0=0x%0x\nhost_pindex=0x%0x\n"
                   "enable=0x%0x\nhost_queue=0x%0x\nintr_enable=0x%0x\ndebug=0x%0x\n"
                   "ring_base=0x%0lx\nring_size=0x%0x\n"
                   "host_ring_base=0x%0lx\nhost_ring_size=0x%0x\nhost_intr_assert_index=0x%0x\n",
                   qstate_notifyq.pc_offset, qstate_notifyq.rsvd0, qstate_notifyq.cosA,
                   qstate_notifyq.cosB, qstate_notifyq.cos_sel, qstate_notifyq.eval_last,
                   qstate_notifyq.host, qstate_notifyq.total, qstate_notifyq.pid,
                   qstate_notifyq.p_index0, qstate_notifyq.c_index0, qstate_notifyq.host_pindex,
                   qstate_notifyq.cfg.enable, qstate_notifyq.cfg.host_queue,
                   qstate_notifyq.cfg.intr_enable, qstate_notifyq.cfg.debug,
                   qstate_notifyq.ring_base,
                   qstate_notifyq.ring_size, qstate_notifyq.host_ring_base,
                   qstate_notifyq.host_ring_size, qstate_notifyq.host_intr_assert_index);
        }
        if (qid == 3) {
            sdk::lib::pal_mem_read(addr, (uint8_t *)&qstate_edmaq, sizeof(qstate_edmaq));
            printf("pc_offset=0x%0x\n"
                   "rsvd0=0x%0x\n"
                   "cosA=0x%0x\ncosB=0x%0x\ncos_sel=0x%0x\n"
                   "eval_last=0x%0x\n"
                   "host=0x%0x\ntotal=0x%0x\n"
                   "pid=0x%0x\n"
                   "p_index0=0x%0x\nc_index0=0x%0x\ncomp_index=0x%0x\n"
                   "color=0x%0x\n"
                   "enable=0x%0x\nintr_enable=0x%0x\ndebug=0x%0x\n"
                   "ring_base=0x%0lx\nring_size=0x%0x\ncq_ring_base=0x%0lx\n"
                   "intr_assert_index=0x%0x\n",
                   qstate_edmaq.pc_offset, qstate_edmaq.rsvd0, qstate_edmaq.cosA,
                   qstate_edmaq.cosB, qstate_edmaq.cos_sel, qstate_edmaq.eval_last,
                   qstate_edmaq.host, qstate_edmaq.total, qstate_edmaq.pid, qstate_edmaq.p_index0,
                   qstate_edmaq.c_index0, qstate_edmaq.comp_index, qstate_edmaq.sta.color,
                   qstate_edmaq.cfg.enable, qstate_edmaq.cfg.intr_enable,
                   qstate_edmaq.cfg.debug,
                   qstate_edmaq.ring_base,
                   qstate_edmaq.ring_size, qstate_edmaq.cq_ring_base,
                   qstate_edmaq.intr_assert_index);
        }
       break;
    default:
        printf("Invalid qtype %u for lif %u\n", qtype, lif);
    }
}

void
eth_qpoll(uint16_t lif, uint8_t qtype)
{
    struct eth_rx_qstate qstate_ethrx = {0};
    struct eth_tx_qstate qstate_ethtx = {0};
    struct admin_qstate qstate_ethaq = {0};
    struct notify_qstate qstate_notifyq = {0};
    struct edma_qstate qstate_edmaq = {0};
    nicmgr_req_qstate_t qstate_req = {0};
    nicmgr_resp_qstate_t qstate_resp = {0};
    queue_info_t qinfo[8] = {0};

    if (!get_lif_qstate(lif, qinfo)) {
        printf("Failed to get qinfo for lif %u\n", lif);
        return;
    }

    if (qinfo[qtype].size == 0) {
        printf("Invalid type %u for lif %u\n", qtype, lif);
        return;
    }

    for (uint32_t qid = 0; qid < qinfo[qtype].length; qid++) {
        uint64_t addr = qinfo[qtype].base + qid * qinfo[qtype].size;
        uint32_t posted = 0;
        switch (qtype) {
        case 0:
            sdk::lib::pal_mem_read(addr, (uint8_t *)&qstate_ethrx, sizeof(qstate_ethrx));
            posted = NUM_POSTED(1 << qstate_ethrx.ring_size, qstate_ethrx.p_index0,
                                qstate_ethrx.c_index0);
            printf(" rx%3d: head %6u tail %6u posted %6d comp_index %6u color %d\n", qid,
                   qstate_ethrx.p_index0, qstate_ethrx.c_index0, posted, qstate_ethrx.comp_index,
                   qstate_ethrx.sta.color);
            break;
        case 1:
            sdk::lib::pal_mem_read(addr, (uint8_t *)&qstate_ethtx, sizeof(qstate_ethtx));
            posted = NUM_POSTED(1 << qstate_ethtx.ring_size, qstate_ethtx.p_index0,
                                qstate_ethtx.c_index0);
            printf(" tx%3d: head %6u tail %6u posted %6d comp_index %6u color %d\n", qid,
                   qstate_ethtx.p_index0, qstate_ethtx.c_index0, posted, qstate_ethtx.comp_index,
                   qstate_ethtx.sta.color);
            break;
        case 2:
            sdk::lib::pal_mem_read(addr, (uint8_t *)&qstate_ethaq, sizeof(qstate_ethaq));
            posted = NUM_POSTED(1 << qstate_ethaq.ring_size, qstate_ethaq.p_index0,
                                qstate_ethaq.c_index0);
            printf(" aq%3d: head %6u tail %6u posted %6d comp_index %6u color %d\n", qid,
                   qstate_ethaq.p_index0, qstate_ethaq.c_index0, posted, qstate_ethaq.comp_index,
                   qstate_ethaq.sta.color);
            break;
        case 7:
            if (qid == 0) {
                sdk::lib::pal_mem_read(addr, (uint8_t *)&qstate_notifyq, sizeof(qstate_notifyq));
                posted = NUM_POSTED(1 << qstate_notifyq.ring_size, qstate_notifyq.p_index0,
                                    qstate_notifyq.c_index0);
                printf(" nq%3d: head %6u tail %6u posted %6d host_pindex %6u\n", qid,
                        qstate_notifyq.p_index0, qstate_notifyq.c_index0, posted,
                        qstate_notifyq.host_pindex);
            }
            if (qid == 1) {
                sdk::lib::pal_mem_read(addr, (uint8_t *)&qstate_edmaq, sizeof(qstate_edmaq));
                posted = NUM_POSTED(1 << qstate_edmaq.ring_size, qstate_edmaq.p_index0,
                                    qstate_edmaq.c_index0);
                printf(" dq%3d: head %6u tail %6u posted %6d comp_index %6u color %d\n", qid,
                        qstate_edmaq.p_index0, qstate_edmaq.c_index0, posted,
                        qstate_edmaq.comp_index, qstate_edmaq.sta.color);
            }
            if (qid == 2) {
                sdk::lib::pal_mem_read(addr, (uint8_t *)&qstate_req, sizeof(qstate_req));
                posted =
                    NUM_POSTED(1 << qstate_req.ring_size, qstate_req.p_index0, qstate_req.c_index0);
                printf("req%3d: head %6u tail %6u posted %6d comp_index %6u color %d\n", qid,
                    qstate_req.p_index0, qstate_req.c_index0, posted, qstate_req.comp_index,
                    qstate_req.sta.color);
            }
            if (qid == 3) {
                sdk::lib::pal_mem_read(addr, (uint8_t *)&qstate_resp, sizeof(qstate_resp));
                posted =
                    NUM_POSTED(1 << qstate_resp.ring_size, qstate_resp.p_index0, qstate_resp.c_index0);
                printf("rsp%3d: head %6u tail %6u posted %6d comp_index %6u color %d\n", qid,
                    qstate_resp.p_index0, qstate_resp.c_index0, posted, qstate_resp.comp_index,
                    qstate_resp.sta.color);
            }
            break;
        default:
            printf("Invalid qtype %u for lif %u\n", qtype, lif);
        }
    }
}

void
eth_qstate(uint16_t lif, uint8_t qtype, uint32_t qid)
{
    struct eth_rx_qstate qstate_ethrx = {0};
    struct eth_tx_qstate qstate_ethtx = {0};
    struct admin_qstate qstate_ethaq = {0};
    struct notify_qstate qstate_notifyq = {0};
    struct edma_qstate qstate_edmaq = {0};
    nicmgr_req_qstate_t qstate_req = {0};
    nicmgr_resp_qstate_t qstate_resp = {0};
    queue_info_t qinfo[8] = {0};

    if (!get_lif_qstate(lif, qinfo)) {
        printf("Failed to get qinfo for lif %u\n", lif);
        return;
    }

    if (qinfo[qtype].size == 0) {
        printf("Invalid type %u for lif %u\n", qtype, lif);
        return;
    }

    if (qid >= qinfo[qtype].length) {
        printf("Invalid qid %u for lif %u qtype %u\n", qid, lif, qtype);
        return;
    }

    uint64_t addr = qinfo[qtype].base + qid * qinfo[qtype].size;
    printf("\naddr: 0x%lx\n\n", addr);

    switch (qtype) {
    case 0:
        sdk::lib::pal_mem_read(addr, (uint8_t *)&qstate_ethrx, sizeof(qstate_ethrx));
        printf("pc_offset=0x%0x\n"
               "rsvd0=0x%0x\n"
               "cosA=0x%0x\ncosB=0x%0x\ncos_sel=0x%0x\n"
               "eval_last=0x%0x\n"
               "host=0x%0x\ntotal=0x%0x\n"
               "pid=0x%0x\n"
               "p_index0=0x%0x\nc_index0=0x%0x\ncomp_index=0x%0x\n"
               "color=0x%0x\n"
               "enable=0x%0x\nhost_queue=0x%0x\ncpu_queue=0x%0x\nintr_enable=0x%0x\ndebug=0x%0x\n"
               "ring_base=0x%0lx\nring_size=0x%0x\n"
               "cq_ring_base=0x%0lx\nintr_assert_index=0x%0x\n"
               "sg_ring_base=0x%0lx\n",
               qstate_ethrx.pc_offset, qstate_ethrx.rsvd0, qstate_ethrx.cosA, qstate_ethrx.cosB,
               qstate_ethrx.cos_sel, qstate_ethrx.eval_last, qstate_ethrx.host, qstate_ethrx.total,
               qstate_ethrx.pid, qstate_ethrx.p_index0, qstate_ethrx.c_index0,
               qstate_ethrx.comp_index, qstate_ethrx.sta.color, qstate_ethrx.cfg.enable,
               qstate_ethrx.cfg.host_queue, qstate_ethrx.cfg.cpu_queue,
               qstate_ethrx.cfg.intr_enable, qstate_ethrx.cfg.debug,
               qstate_ethrx.ring_base,
               qstate_ethrx.ring_size, qstate_ethrx.cq_ring_base, qstate_ethrx.intr_assert_index,
               qstate_ethrx.sg_ring_base);
        break;
    case 1:
        sdk::lib::pal_mem_read(addr, (uint8_t *)&qstate_ethtx, sizeof(qstate_ethtx));
        printf("pc_offset=0x%0x\n"
               "rsvd0=0x%0x\n"
               "cosA=0x%0x\ncosB=0x%0x\ncos_sel=0x%0x\n"
               "eval_last=0x%0x\n"
               "host=0x%0x\ntotal=0x%0x\n"
               "pid=0x%0x\n"
               "p_index0=0x%0x\nc_index0=0x%0x\n"
               "comp_index=0x%0x\nci_fetch=0x%0x\nci_miss=0x%0x\n"
               "color=0x%0x\nspec_miss=0x%0x\n"
               "enable=0x%0x\nhost_queue=0x%0x\ncpu_queue=0x%0x\nintr_enable=0x%0x\ndebug=0x%0x\n"
               "ring_base=0x%0lx\nring_size=0x%0x\n"
               "cq_ring_base=0x%0lx\nintr_assert_index=0x%0x\n"
               "sg_ring_base=0x%0lx\n"
               "spurious_db_cnt=0x%lx\n",
               qstate_ethtx.pc_offset, qstate_ethtx.rsvd0, qstate_ethtx.cosA, qstate_ethtx.cosB,
               qstate_ethtx.cos_sel, qstate_ethtx.eval_last, qstate_ethtx.host, qstate_ethtx.total,
               qstate_ethtx.pid, qstate_ethtx.p_index0, qstate_ethtx.c_index0,
               qstate_ethtx.comp_index, qstate_ethtx.ci_fetch, qstate_ethtx.ci_miss,
               qstate_ethtx.sta.color, qstate_ethtx.sta.spec_miss, qstate_ethtx.cfg.enable,
               qstate_ethtx.cfg.host_queue, qstate_ethtx.cfg.cpu_queue,
               qstate_ethtx.cfg.intr_enable, qstate_ethtx.cfg.debug,
               qstate_ethtx.ring_base,
               qstate_ethtx.ring_size, qstate_ethtx.cq_ring_base, qstate_ethtx.intr_assert_index,
               qstate_ethtx.sg_ring_base, qstate_ethtx.spurious_db_cnt);
        break;
    case 2:
        sdk::lib::pal_mem_read(addr, (uint8_t *)&qstate_ethaq, sizeof(qstate_ethaq));
        printf("pc_offset=0x%0x\n"
               "rsvd0=0x%0x\n"
               "cosA=0x%0x\ncosB=0x%0x\ncos_sel=0x%0x\n"
               "eval_last=0x%0x\n"
               "host=0x%0x\ntotal=0x%0x\n"
               "pid=0x%0x\n"
               "p_index0=0x%0x\nc_index0=0x%0x\n"
               "comp_index=0x%0x\nci_fetch=0x%0x\n"
               "color=0x%0x\n"
               "enable=0x%0x\nhost_queue=0x%0x\nintr_enable=0x%0x\ndebug=0x%0x\n"
               "ring_base=0x%0lx\nring_size=0x%0x\n"
               "cq_ring_base=0x%0lx\nintr_assert_index=0x%0x\n"
               "nicmgr_qstate_addr=0x%0lx\n",
               qstate_ethaq.pc_offset, qstate_ethaq.rsvd0, qstate_ethaq.cosA, qstate_ethaq.cosB,
               qstate_ethaq.cos_sel, qstate_ethaq.eval_last, qstate_ethaq.host, qstate_ethaq.total,
               qstate_ethaq.pid, qstate_ethaq.p_index0, qstate_ethaq.c_index0,
               qstate_ethaq.comp_index, qstate_ethaq.ci_fetch, qstate_ethaq.sta.color,
               qstate_ethaq.cfg.enable, qstate_ethaq.cfg.host_queue, qstate_ethaq.cfg.intr_enable,
               qstate_ethaq.cfg.debug,
               qstate_ethaq.ring_base, qstate_ethaq.ring_size, qstate_ethaq.cq_ring_base,
               qstate_ethaq.intr_assert_index, qstate_ethaq.nicmgr_qstate_addr);
        break;
    case 7:
        if (qid == 0) {
            sdk::lib::pal_mem_read(addr, (uint8_t *)&qstate_notifyq, sizeof(qstate_notifyq));
            printf("pc_offset=0x%0x\n"
                   "rsvd0=0x%0x\n"
                   "cosA=0x%0x\ncosB=0x%0x\ncos_sel=0x%0x\n"
                   "eval_last=0x%0x\n"
                   "host=0x%0x\ntotal=0x%0x\n"
                   "pid=0x%0x\n"
                   "p_index0=0x%0x\nc_index0=0x%0x\nhost_pindex=0x%0x\n"
                   "enable=0x%0x\nhost_queue=0x%0x\nintr_enable=0x%0x\ndebug=0x%0x\n"
                   "ring_base=0x%0lx\nring_size=0x%0x\n"
                   "host_ring_base=0x%0lx\nhost_ring_size=0x%0x\nhost_intr_assert_index=0x%0x\n",
                   qstate_notifyq.pc_offset, qstate_notifyq.rsvd0, qstate_notifyq.cosA,
                   qstate_notifyq.cosB, qstate_notifyq.cos_sel, qstate_notifyq.eval_last,
                   qstate_notifyq.host, qstate_notifyq.total, qstate_notifyq.pid,
                   qstate_notifyq.p_index0, qstate_notifyq.c_index0, qstate_notifyq.host_pindex,
                   qstate_notifyq.cfg.enable, qstate_notifyq.cfg.host_queue,
                   qstate_notifyq.cfg.intr_enable, qstate_notifyq.cfg.debug,
                   qstate_notifyq.ring_base,
                   qstate_notifyq.ring_size, qstate_notifyq.host_ring_base,
                   qstate_notifyq.host_ring_size, qstate_notifyq.host_intr_assert_index);
        }
        if (qid == 1) {
            sdk::lib::pal_mem_read(addr, (uint8_t *)&qstate_edmaq, sizeof(qstate_edmaq));
            printf("pc_offset=0x%0x\n"
                   "rsvd0=0x%0x\n"
                   "cosA=0x%0x\ncosB=0x%0x\ncos_sel=0x%0x\n"
                   "eval_last=0x%0x\n"
                   "host=0x%0x\ntotal=0x%0x\n"
                   "pid=0x%0x\n"
                   "p_index0=0x%0x\nc_index0=0x%0x\ncomp_index=0x%0x\n"
                   "color=0x%0x\n"
                   "enable=0x%0x\nintr_enable=0x%0x\ndebug=0x%0x\n"
                   "ring_base=0x%0lx\nring_size=0x%0x\ncq_ring_base=0x%0lx\n"
                   "intr_assert_index=0x%0x\n",
                   qstate_edmaq.pc_offset, qstate_edmaq.rsvd0, qstate_edmaq.cosA,
                   qstate_edmaq.cosB, qstate_edmaq.cos_sel, qstate_edmaq.eval_last,
                   qstate_edmaq.host, qstate_edmaq.total, qstate_edmaq.pid, qstate_edmaq.p_index0,
                   qstate_edmaq.c_index0, qstate_edmaq.comp_index, qstate_edmaq.sta.color,
                   qstate_edmaq.cfg.enable, qstate_edmaq.cfg.intr_enable, qstate_edmaq.cfg.debug,
                   qstate_edmaq.ring_base, qstate_edmaq.ring_size, qstate_edmaq.cq_ring_base,
                   qstate_edmaq.intr_assert_index);
        }
        if (qid == 2) {
            sdk::lib::pal_mem_read(addr, (uint8_t *)&qstate_req, sizeof(qstate_req));
            printf("pc_offset=0x%0x\n"
                "rsvd0=0x%0x\n"
                "cosA=0x%0x\ncosB=0x%0x\ncos_sel=0x%0x\n"
                "eval_last=0x%0x\n"
                "host=0x%0x\ntotal=0x%0x\n"
                "pid=0x%0x\n"
                "p_index0=0x%0x\nc_index0=0x%0x\n"
                "comp_index=0x%0x\nci_fetch=0x%0x\n"
                "color=0x%0x\n"
                "enable=0x%0x\nintr_enable=0x%0x\ndebug=0x%0x\n"
                "ring_base=0x%0lx\nring_size=0x%0x\n"
                "cq_ring_base=0x%0lx\nintr_assert_index=0x%0x\n",
                qstate_req.pc_offset, qstate_req.rsvd0, qstate_req.cosA, qstate_req.cosB,
                qstate_req.cos_sel, qstate_req.eval_last, qstate_req.host, qstate_req.total,
                qstate_req.pid, qstate_req.p_index0, qstate_req.c_index0, qstate_req.comp_index,
                qstate_req.ci_fetch, qstate_req.sta.color, qstate_req.cfg.enable,
                qstate_req.cfg.intr_enable, qstate_req.cfg.debug,
                qstate_req.ring_base, qstate_req.ring_size,
                qstate_req.cq_ring_base, qstate_req.intr_assert_index);
        }
        if (qid == 3) {
            sdk::lib::pal_mem_read(addr, (uint8_t *)&qstate_resp, sizeof(qstate_resp));
            printf("pc_offset=0x%0x\n"
                "rsvd0=0x%0x\n"
                "cosA=0x%0x\ncosB=0x%0x\ncos_sel=0x%0x\n"
                "eval_last=0x%0x\n"
                "host=0x%0x\ntotal=0x%0x\n"
                "pid=0x%0x\n"
                "p_index0=0x%0x\nc_index0=0x%0x\n"
                "comp_index=0x%0x\nci_fetch=0x%0x\n"
                "color=0x%0x\n"
                "enable=0x%0x\nintr_enable=0x%0x\ndebug=0x%0x\n"
                "ring_base=0x%0lx\nring_size=0x%0x\n"
                "cq_ring_base=0x%0lx\nintr_assert_index=0x%0x\n",
                qstate_resp.pc_offset, qstate_resp.rsvd0, qstate_resp.cosA, qstate_resp.cosB,
                qstate_resp.cos_sel, qstate_resp.eval_last, qstate_resp.host, qstate_resp.total,
                qstate_resp.pid, qstate_resp.p_index0, qstate_resp.c_index0, qstate_resp.comp_index,
                qstate_resp.ci_fetch, qstate_resp.sta.color, qstate_resp.cfg.enable,
                qstate_resp.cfg.intr_enable, qstate_resp.cfg.debug,
                qstate_resp.ring_base, qstate_resp.ring_size,
                qstate_resp.cq_ring_base, qstate_resp.intr_assert_index);
        }
        break;
    default:
        printf("Invalid qtype %u for lif %u\n", qtype, lif);
    }
}

void
eth_qdump(uint16_t lif, uint8_t qtype, uint32_t qid, uint8_t ring)
{
    queue_info_t qinfo[8] = {0};

    if (!get_lif_qstate(lif, qinfo)) {
        printf("Failed to get qinfo for lif %u\n", lif);
        return;
    }

    if (qinfo[qtype].size == 0) {
        printf("Invalid type %u for lif %u\n", qtype, lif);
        return;
    }

    if (qid >= qinfo[qtype].length) {
        printf("Invalid qid %u for lif %u qtype %u\n", qid, lif, qtype);
        return;
    }

    uint64_t addr = qinfo[qtype].base + qid * qinfo[qtype].size;

    switch (qtype) {
    case 7:
        if (qid == 0) {
            struct notify_qstate qstate = {0};
            sdk::lib::pal_mem_read(addr, (uint8_t *)&qstate, sizeof(qstate));
            if (ring == 0) {
                uint64_t desc_addr = qstate.ring_base;
                struct notify_desc desc = {0};
                for (uint16_t i = 0; i < (1 << qstate.ring_size); i++) {
                    sdk::lib::pal_mem_read(desc_addr, (uint8_t *)&desc, sizeof(desc));
                    printf("[%5d] eid = %lu ecode = %d data = ", i, desc.eid, desc.ecode);
                    for (uint16_t j = 0; j < sizeof(desc.data); j++) {
                        printf(" %02x", desc.data[j]);
                    }
                    printf("\n");
                    desc_addr += sizeof(desc);
                }
            }
        }
        if (qid == 1) {
            struct edma_qstate qstate = {0};
            sdk::lib::pal_mem_read(addr, (uint8_t *)&qstate, sizeof(qstate));
            if (ring == 0) {
                uint64_t desc_addr = qstate.ring_base;
                struct edma_cmd_desc desc = {0};
                for (uint16_t i = 0; i < (1 << qstate.ring_size); i++) {
                    sdk::lib::pal_mem_read(desc_addr, (uint8_t *)&desc, sizeof(desc));
                    printf("[%5d] opcode = %3d len = %5d slif = %4d saddr 0x%013lx dlif = %4d daddr = 0x%013lx\n",
                        i, desc.opcode, desc.len,
                        desc.src_lif, desc.src_addr, desc.dst_lif, desc.dst_addr);
                    desc_addr += sizeof(desc);
                }
            }
            if (ring == 1) {
                uint64_t desc_addr = qstate.cq_ring_base;
                struct edma_comp_desc desc = {0};
                for (uint16_t i = 0; i < (1 << qstate.ring_size); i++) {
                    sdk::lib::pal_mem_read(desc_addr, (uint8_t *)&desc, sizeof(desc));
                    printf("[%5d] status = %3d comp_index = %5d color = %d\n",
                        i, desc.status, desc.comp_index, desc.color);
                    desc_addr += sizeof(desc);
                }
            }
        }
        if (qid == 2) {
            struct admin_nicmgr_qstate qstate = {0};
            sdk::lib::pal_mem_read(addr, (uint8_t *)&qstate, sizeof(qstate));
            if (ring == 0) {
                uint64_t desc_addr = qstate.ring_base;
                struct nicmgr_req_desc desc = {0};
                for (uint16_t i = 0; i < (1 << qstate.ring_size); i++) {
                    sdk::lib::pal_mem_read(desc_addr, (uint8_t *)&desc, sizeof(desc));
                    uint8_t *data = (uint8_t *)&desc.cmd;
                    printf("[%5d] lif = %d qtype = %d qid = %d comp = %d data = ",
                        i, desc.lif, desc.qtype, desc.qid, desc.comp_index);
                    for (uint16_t j = 0; j < sizeof(desc.cmd); j++) {
                        printf(" %02x", data[j]);
                    }
                    printf("\n");
                    desc_addr += sizeof(desc);
                }
            }
            if (ring == 1) {
                uint64_t desc_addr = qstate.cq_ring_base;
                struct nicmgr_req_comp_desc desc = {0};
                for (uint16_t i = 0; i < (1 << qstate.ring_size); i++) {
                    sdk::lib::pal_mem_read(desc_addr, (uint8_t *)&desc, sizeof(desc));
                    printf("[%5d] color %d\n", i, desc.color);
                    desc_addr += sizeof(desc);
                }
            }
        }
        if (qid == 3) {
            struct admin_nicmgr_qstate qstate = {0};
            sdk::lib::pal_mem_read(addr, (uint8_t *)&qstate, sizeof(qstate));
            if (ring == 0) {
                uint64_t desc_addr = qstate.ring_base;
                struct nicmgr_resp_desc desc = {0};
                for (uint16_t i = 0; i < (1 << qstate.ring_size); i++) {
                    sdk::lib::pal_mem_read(desc_addr, (uint8_t *)&desc, sizeof(desc));
                    uint8_t *data = (uint8_t *)&desc.comp;
                    printf("[%5d] lif = %d qtype = %d qid = %d comp = %d data = ",
                        i, desc.lif, desc.qtype, desc.qid, desc.comp_index);
                    for (uint16_t j = 0; j < sizeof(desc.comp); j++) {
                        printf(" %02x", data[j]);
                    }
                    printf("\n");
                    desc_addr += sizeof(desc);
                }
            }
            if (ring == 1) {
                uint64_t desc_addr = qstate.cq_ring_base;
                struct nicmgr_resp_comp_desc desc = {0};
                for (uint16_t i = 0; i < (1 << qstate.ring_size); i++) {
                    sdk::lib::pal_mem_read(desc_addr, (uint8_t *)&desc, sizeof(desc));
                    printf("[%5d] color %d\n", i, desc.color);
                    desc_addr += sizeof(desc);
                }
            }
        }
        break;
    }
}

void
eth_debug(uint16_t lif, uint8_t qtype, uint32_t qid, uint8_t enable)
{
    struct eth_rx_cfg_qstate qstate_ethrx = {0};
    struct eth_tx_cfg_qstate qstate_ethtx = {0};
    struct admin_cfg_qstate qstate_aq = {0};
    struct edma_cfg_qstate qstate_edmaq = {0};
    struct notify_cfg_qstate qstate_notifyq = {0};
    struct admin_nicmgr_cfg_qstate qstate_req = {0};
    struct admin_nicmgr_cfg_qstate qstate_resp = {0};
    queue_info_t qinfo[8] = {0};

    if (!get_lif_qstate(lif, qinfo)) {
        printf("Failed to get qinfo for lif %u\n", lif);
        return;
    }

    if (qinfo[qtype].size == 0) {
        printf("Invalid type %u for lif %u\n", qtype, lif);
        return;
    }

    if (qid >= qinfo[qtype].length) {
        printf("Invalid qid %u for lif %u qtype %u\n", qid, lif, qtype);
        return;
    }

    uint64_t addr = qinfo[qtype].base + qid * qinfo[qtype].size;

    switch (qtype) {
        case 0:
            sdk::lib::pal_mem_read(addr + offsetof(eth_rx_qstate_t, cfg),
                (uint8_t *)&qstate_ethrx, sizeof(qstate_ethrx));
            qstate_ethrx.debug = enable;
            sdk::lib::pal_mem_write(addr + offsetof(eth_rx_qstate_t, cfg),
                (uint8_t *)&qstate_ethrx, sizeof(qstate_ethrx));
            break;
        case 1:
            sdk::lib::pal_mem_read(addr + offsetof(eth_tx_qstate_t, cfg),
                (uint8_t *)&qstate_ethtx, sizeof(qstate_ethtx));
            qstate_ethtx.debug = enable;
            sdk::lib::pal_mem_write(addr + offsetof(eth_tx_qstate_t, cfg),
                (uint8_t *)&qstate_ethtx, sizeof(qstate_ethtx));
            break;
        case 2:
            sdk::lib::pal_mem_read(addr + offsetof(admin_qstate_t, cfg),
                (uint8_t *)&qstate_aq, sizeof(qstate_aq));
            qstate_aq.debug = enable;
            sdk::lib::pal_mem_write(addr + offsetof(admin_qstate_t, cfg),
                (uint8_t *)&qstate_aq, sizeof(qstate_aq));
            break;
        case 7:
        if (qid == 0) {
            sdk::lib::pal_mem_read(addr + offsetof(struct notify_qstate, cfg),
                (uint8_t *)&qstate_notifyq, sizeof(qstate_notifyq));
            qstate_notifyq.debug = enable;
            sdk::lib::pal_mem_write(addr + offsetof(struct notify_qstate, cfg),
                (uint8_t *)&qstate_notifyq, sizeof(qstate_notifyq));
        }
        if (qid == 1) {
            sdk::lib::pal_mem_read(addr + offsetof(struct edma_qstate, cfg),
                (uint8_t *)&qstate_edmaq, sizeof(qstate_edmaq));
            qstate_edmaq.debug = enable;
            sdk::lib::pal_mem_write(addr + offsetof(struct edma_qstate, cfg),
                (uint8_t *)&qstate_edmaq, sizeof(qstate_edmaq));
        }
        if (qid == 2) {
            sdk::lib::pal_mem_read(addr + offsetof(nicmgr_req_qstate_t, cfg),
                (uint8_t *)&qstate_req, sizeof(qstate_req));
            qstate_req.debug = enable;
            sdk::lib::pal_mem_write(addr + offsetof(nicmgr_req_qstate_t, cfg),
                (uint8_t *)&qstate_req, sizeof(qstate_req));
        }
        if (qid == 3) {
            sdk::lib::pal_mem_read(addr + offsetof(nicmgr_resp_qstate_t, cfg),
                (uint8_t *)&qstate_resp, sizeof(qstate_resp));
            qstate_resp.debug = enable;
            sdk::lib::pal_mem_write(addr + offsetof(nicmgr_resp_qstate_t, cfg),
                (uint8_t *)&qstate_resp, sizeof(qstate_resp));
        }
    }

    uint32_t val = 0x1;
    sdk::lib::pal_reg_write(CAP_ADDR_BASE_RPC_PICS_OFFSET + \
        CAP_PICS_CSR_PICC_BYTE_OFFSET + \
        CAP_PICC_CSR_DHS_CACHE_INVALIDATE_BYTE_OFFSET, &val, 1);
    sdk::lib::pal_reg_write(CAP_ADDR_BASE_TPC_PICS_OFFSET + \
        CAP_PICS_CSR_PICC_BYTE_OFFSET + \
        CAP_PICC_CSR_DHS_CACHE_INVALIDATE_BYTE_OFFSET, &val, 1);

    eth_qstate(lif, qtype, qid);
}

std::string
hal_cfg_path()
{
    std::string hal_cfg_path_;
    if (std::getenv("HAL_CONFIG_PATH") == NULL) {
        hal_cfg_path_ = "/nic/conf";
    } else {
        hal_cfg_path_ = std::string(std::getenv("HAL_CONFIG_PATH"));
    }

    return hal_cfg_path_;
}

std::string
fwd_mode()
{
    boost::property_tree::ptree spec;
    boost::property_tree::read_json("/sysconfig/config0/device.conf", spec);

    return spec.get<std::string>("forwarding-mode");
}

std::string
mpart_cfg_path()
{
    std::string hal_cfg_path_ = hal_cfg_path();
    std::string mpart_json;

#if defined(APOLLO)
    mpart_json = hal_cfg_path_ + "/apollo/hbm_mem.json";
#elif defined(ARTEMIS)
    mpart_json = hal_cfg_path_ + "/artemis/hbm_mem.json";
#else
    mpart_json = (fwd_mode() == "FORWARDING_MODE_CLASSIC") ?
            hal_cfg_path_ + "/iris/hbm_classic_mem.json" :
            hal_cfg_path_ + "/iris/hbm_mem.json";
#endif

    return mpart_json;
}

void
eth_stats(uint16_t lif)
{
    struct lif_stats stats;

    std::string mpart_json = mpart_cfg_path();
    sdk::platform::utils::mpartition *mp_ = mpartition::factory(mpart_json.c_str());
    assert(mp_);

    uint64_t addr = mp_->start_addr(MEM_REGION_LIF_STATS_NAME) + (lif << 10);

    printf("\naddr: 0x%lx\n\n", addr);
    sdk::lib::pal_mem_read(addr, (uint8_t *)&stats, sizeof(struct lif_stats));

    printf("rx_ucast_bytes              : %lu\n", stats.rx_ucast_bytes);
    printf("rx_ucast_packets            : %lu\n", stats.rx_ucast_packets);
    printf("rx_mcast_bytes              : %lu\n", stats.rx_mcast_bytes);
    printf("rx_mcast_packets            : %lu\n", stats.rx_mcast_packets);
    printf("rx_bcast_bytes              : %lu\n", stats.rx_bcast_bytes);
    printf("rx_bcast_packets            : %lu\n", stats.rx_bcast_packets);

    printf("rx_ucast_drop_bytes         : %lu\n", stats.rx_ucast_drop_bytes);
    printf("rx_ucast_drop_packets       : %lu\n", stats.rx_ucast_drop_packets);
    printf("rx_mcast_drop_bytes         : %lu\n", stats.rx_mcast_drop_bytes);
    printf("rx_mcast_drop_packets       : %lu\n", stats.rx_mcast_drop_packets);
    printf("rx_bcast_drop_bytes         : %lu\n", stats.rx_bcast_drop_bytes);
    printf("rx_bcast_drop_packets       : %lu\n", stats.rx_bcast_drop_packets);
    printf("rx_dma_error                : %lu\n", stats.rx_dma_error);

    printf("tx_ucast_bytes              : %lu\n", stats.tx_ucast_bytes);
    printf("tx_ucast_packets            : %lu\n", stats.tx_ucast_packets);
    printf("tx_mcast_bytes              : %lu\n", stats.tx_mcast_bytes);
    printf("tx_mcast_packets            : %lu\n", stats.tx_mcast_packets);
    printf("tx_bcast_bytes              : %lu\n", stats.tx_bcast_bytes);
    printf("tx_bcast_packets            : %lu\n", stats.tx_bcast_packets);

    printf("tx_ucast_drop_bytes         : %lu\n", stats.tx_ucast_drop_bytes);
    printf("tx_ucast_drop_packets       : %lu\n", stats.tx_ucast_drop_packets);
    printf("tx_mcast_drop_bytes         : %lu\n", stats.tx_mcast_drop_bytes);
    printf("tx_mcast_drop_packets       : %lu\n", stats.tx_mcast_drop_packets);
    printf("tx_bcast_drop_bytes         : %lu\n", stats.tx_bcast_drop_bytes);
    printf("tx_bcast_drop_packets       : %lu\n", stats.tx_bcast_drop_packets);
    printf("tx_dma_error                : %lu\n", stats.tx_dma_error);

    printf("rx_queue_disabled           : %lu\n", stats.rx_queue_disabled);
    printf("rx_queue_empty              : %lu\n", stats.rx_queue_empty);
    printf("rx_queue_error              : %lu\n", stats.rx_queue_error);
    printf("rx_desc_fetch_error         : %lu\n", stats.rx_desc_fetch_error);
    printf("rx_desc_data_error          : %lu\n", stats.rx_desc_data_error);

    printf("tx_queue_disabled           : %lu\n", stats.tx_queue_disabled);
    printf("tx_queue_error              : %lu\n", stats.tx_queue_error);
    printf("tx_desc_fetch_error         : %lu\n", stats.tx_desc_fetch_error);
    printf("tx_desc_data_error          : %lu\n", stats.tx_desc_data_error);

    printf("tx_ucast_drop_bytes         : %lu\n", stats.tx_ucast_drop_bytes);
    printf("tx_ucast_drop_packets       : %lu\n", stats.tx_ucast_drop_packets);
    printf("tx_mcast_drop_bytes         : %lu\n", stats.tx_mcast_drop_bytes);
    printf("tx_mcast_drop_packets       : %lu\n", stats.tx_mcast_drop_packets);
    printf("tx_bcast_drop_bytes         : %lu\n", stats.tx_bcast_drop_bytes);
    printf("tx_bcast_drop_packets       : %lu\n", stats.tx_bcast_drop_packets);
    printf("tx_dma_error                : %lu\n", stats.tx_dma_error);

    printf("tx_rdma_ucast_bytes         : %lu\n", stats.tx_rdma_ucast_bytes);
    printf("tx_rdma_ucast_packets       : %lu\n", stats.tx_rdma_ucast_packets);
    printf("tx_rdma_mcast_bytes         : %lu\n", stats.tx_rdma_mcast_bytes);
    printf("tx_rdma_mcast_packets       : %lu\n", stats.tx_rdma_mcast_packets);
    printf("tx_rdma_cnp_packets         : %lu\n", stats.tx_rdma_cnp_packets);

    printf("rx_rdma_ucast_bytes         : %lu\n", stats.rx_rdma_ucast_bytes);
    printf("rx_rdma_ucast_packets       : %lu\n", stats.rx_rdma_ucast_packets);
    printf("rx_rdma_mcast_bytes         : %lu\n", stats.rx_rdma_mcast_bytes);
    printf("rx_rdma_mcast_packets       : %lu\n", stats.rx_rdma_mcast_packets);
    printf("rx_rdma_cnp_packets         : %lu\n", stats.rx_rdma_cnp_packets);
    printf("rx_rdma_ecn_packets         : %lu\n", stats.rx_rdma_ecn_packets);

    printf("rdma_packet_seq_err         : %lu\n", stats.rdma_req_rx_pkt_seq_err);
    printf("rdma_req_rnr_retry_err      : %lu\n", stats.rdma_req_rx_rnr_retry_err);
    printf("rdma_req_remote_access_err  : %lu\n", stats.rdma_req_rx_remote_access_err);
    printf("rdma_req_remote_inv_req_err : %lu\n", stats.rdma_req_rx_remote_inv_req_err);
    printf("rdma_req_remote_oper_err    : %lu\n", stats.rdma_req_rx_remote_oper_err);
    printf("rdma_implied_nak_seq_err    : %lu\n", stats.rdma_req_rx_implied_nak_seq_err);
    printf("rdma_req_cqe_err            : %lu\n", stats.rdma_req_rx_cqe_err);
    printf("rdma_req_cqe_flush_err      : %lu\n", stats.rdma_req_rx_cqe_flush_err);

    printf("rdma_duplicate_responses    : %lu\n", stats.rdma_req_rx_dup_responses);
    printf("rdma_req_invalid_packets    : %lu\n", stats.rdma_req_rx_invalid_packets);
    printf("rdma_req_local_access_err   : %lu\n", stats.rdma_req_tx_local_access_err);
    printf("rdma_req_local_oper_err     : %lu\n", stats.rdma_req_tx_local_oper_err);
    printf("rdma_req_memory_mgmt_err    : %lu\n", stats.rdma_req_tx_memory_mgmt_err);

    printf("rdma_duplicate_request      : %lu\n", stats.rdma_resp_rx_dup_requests);
    printf("rdma_out_of_buffer          : %lu\n", stats.rdma_resp_rx_out_of_buffer);
    printf("rdma_out_of_sequence        : %lu\n", stats.rdma_resp_rx_out_of_seq_pkts);
    printf("rdma_resp_cqe_err           : %lu\n", stats.rdma_resp_rx_cqe_err);
    printf("rdma_resp_cqe_flush_err     : %lu\n", stats.rdma_resp_rx_cqe_flush_err);
    printf("rdma_resp_local_len_err     : %lu\n", stats.rdma_resp_rx_local_len_err);
    printf("rdma_resp_inv_request_err   : %lu\n", stats.rdma_resp_rx_inv_request_err);
    printf("rdma_resp_local_qp_oper_err : %lu\n", stats.rdma_resp_rx_local_qp_oper_err);

    printf("rdma_out_of_atomic_resource : %lu\n", stats.rdma_resp_rx_out_of_atomic_resource);

    printf("rdma_resp_pkt_seq_err       : %lu\n", stats.rdma_resp_tx_pkt_seq_err);
    printf("rdma_resp_remote_inv_req_err: %lu\n", stats.rdma_resp_tx_remote_inv_req_err);
    printf("rdma_resp_remote_access_err : %lu\n", stats.rdma_resp_tx_remote_access_err);
    printf("rdma_resp_remote_oper_err   : %lu\n", stats.rdma_resp_tx_remote_oper_err);
    printf("rdma_resp_rnr_retry_err     : %lu\n", stats.rdma_resp_tx_rnr_retry_err);

}

void
eth_stats_reset(uint16_t lif)
{
    std::string mpart_json = mpart_cfg_path();
    sdk::platform::utils::mpartition *mp_ = mpartition::factory(mpart_json.c_str());
    assert(mp_);

    uint64_t addr = mp_->start_addr(MEM_REGION_LIF_STATS_NAME) + (lif << 10);

    printf("\naddr: 0x%lx\n\n", addr);
    sdk::lib::pal_mem_set(addr, 0, sizeof(struct lif_stats), 0);
}

void
port_config(uint64_t addr)
{
    uint8_t *buf = (uint8_t *)calloc(1, sizeof(union port_config));
    assert(buf != NULL);
    sdk::lib::pal_mem_read(addr, buf, sizeof(union port_config));
    union port_config *config = (union port_config *)buf;

    printf("\n");
    printf("port_config:\n");
    printf("  speed: %u\n", config->speed);
    printf("  mtu: %u\n", config->mtu);
    printf("  state: %u\n", config->state);
    printf("  an_enable: %u\n", config->an_enable);
    printf("  fec_type: %u\n", config->fec_type);
    printf("  pause_type: %u\n", config->pause_type);
    printf("  loopback_mode: %u\n", config->loopback_mode);
    printf("\n");

    free(buf);
}

void
port_status(uint64_t addr)
{
    uint8_t *buf = (uint8_t *)calloc(1, sizeof(struct port_status));
    assert(buf != NULL);
    sdk::lib::pal_mem_read(addr, buf, sizeof(struct port_status));
    struct port_status *status = (struct port_status *)buf;

    printf("\n");
    printf("port_status:\n");
    printf("  speed: %u\n", status->speed);
    printf("  id: %u\n", status->id);
    printf("  status: %u\n", status->status);
    printf("  xcvr:\n");
    printf("    state: %u\n", status->xcvr.state);
    printf("    phy: %u\n", status->xcvr.phy);
    printf("    pid: %u\n", status->xcvr.pid);
    printf("    sprom:\n");
    for (uint32_t i = 0; i < sizeof(status->xcvr.sprom) / 16; i++) {
        printf("      ");
        for (uint32_t j = 0; j < 16; j++) {
            printf("%02x ", status->xcvr.sprom[(i * 16) + j]);
        }
        printf("\n");
    }

    printf("\n");

    free(buf);
}

void
lif_status(uint64_t addr)
{
    uint8_t *buf = (uint8_t *)calloc(1, sizeof(struct lif_status));
    assert(buf != NULL);
    sdk::lib::pal_mem_read(addr, buf, sizeof(struct lif_status));
    struct lif_status *status = (struct lif_status *)buf;

    printf("\n");
    printf("lif_status:\n");
    printf("  eid: %lu\n", status->eid);
    printf("  port_num: %u\n", status->port_num);
    printf("  link_status: %u\n", status->link_status);
    printf("  link_speed: %u\n", status->link_speed);
    printf("  link_down_count: %u\n", status->link_down_count);
    printf("\n");

    free(buf);
}

#if defined(APOLLO)
#define P4_COMMON_RXDMA_ACTIONS_TBL_ID_INDEX_MIN P4_APOLLO_RXDMA_TBL_ID_INDEX_MIN
#define P4_COMMON_RXDMA_ACTIONS_TBL_ID_INDEX_MAX P4_APOLLO_RXDMA_TBL_ID_INDEX_MAX
#define P4_COMMON_TXDMA_ACTIONS_TBL_ID_INDEX_MIN P4_APOLLO_TXDMA_TBL_ID_INDEX_MIN
#define P4_COMMON_TXDMA_ACTIONS_TBL_ID_INDEX_MAX P4_APOLLO_TXDMA_TBL_ID_INDEX_MAX
#define P4_COMMON_RXDMA_ACTIONS_TBL_ID_TBLMIN P4_APOLLO_RXDMA_TBL_ID_TBLMIN
#define P4_COMMON_RXDMA_ACTIONS_TBL_ID_TBLMAX P4_APOLLO_RXDMA_TBL_ID_TBLMAX
#define P4_COMMON_TXDMA_ACTIONS_TBL_ID_TBLMIN P4_APOLLO_TXDMA_TBL_ID_TBLMIN
#define P4_COMMON_TXDMA_ACTIONS_TBL_ID_TBLMAX P4_APOLLO_TXDMA_TBL_ID_TBLMAX
#define P4_COMMON_RXDMA_ACTIONS_TBL_ID_ETH_RX_RSS_PARAMS P4_APOLLO_RXDMA_TBL_ID_ETH_RX_RSS_PARAMS
#elif defined(ARTEMIS)
#define P4_COMMON_RXDMA_ACTIONS_TBL_ID_INDEX_MIN P4_ARTEMIS_RXDMA_TBL_ID_INDEX_MIN
#define P4_COMMON_RXDMA_ACTIONS_TBL_ID_INDEX_MAX P4_ARTEMIS_RXDMA_TBL_ID_INDEX_MAX
#define P4_COMMON_TXDMA_ACTIONS_TBL_ID_INDEX_MIN P4_ARTEMIS_TXDMA_TBL_ID_INDEX_MIN
#define P4_COMMON_TXDMA_ACTIONS_TBL_ID_INDEX_MAX P4_ARTEMIS_TXDMA_TBL_ID_INDEX_MAX
#define P4_COMMON_RXDMA_ACTIONS_TBL_ID_TBLMIN P4_ARTEMIS_RXDMA_TBL_ID_TBLMIN
#define P4_COMMON_RXDMA_ACTIONS_TBL_ID_TBLMAX P4_ARTEMIS_RXDMA_TBL_ID_TBLMAX
#define P4_COMMON_TXDMA_ACTIONS_TBL_ID_TBLMIN P4_ARTEMIS_TXDMA_TBL_ID_TBLMIN
#define P4_COMMON_TXDMA_ACTIONS_TBL_ID_TBLMAX P4_ARTEMIS_TXDMA_TBL_ID_TBLMAX
#define P4_COMMON_RXDMA_ACTIONS_TBL_ID_ETH_RX_RSS_PARAMS P4_ARTEMIS_RXDMA_TBL_ID_ETH_RX_RSS_PARAMS
#endif

void table_health_monitor(uint32_t table_id,
                          char *name,
                          table_health_state_t curr_state,
                          uint32_t capacity,
                          uint32_t usage,
                          table_health_state_t *new_state)
{
    printf("table id: %d, name: %s, capacity: %d, "
            "usage: %d, curr state: %d, new state: %d",
            table_id, name, capacity, usage, curr_state, *new_state);
}

int
p4plus_rxdma_init_tables()
{
    uint32_t                   tid;
    p4pd_table_properties_t    tinfo;
    p4pd_error_t               rc;
    std::string hal_cfg_path_ = hal_cfg_path();

#if defined(APOLLO)
    p4pd_cfg_t                 p4pd_cfg = {
            .table_map_cfg_file  = "apollo/capri_rxdma_table_map.json",
            .p4pd_pgm_name       = "apollo",
            .p4pd_rxdma_pgm_name = "p4plus",
            .p4pd_txdma_pgm_name = "p4plus",
            .cfg_path            = hal_cfg_path_.c_str(),
    };
#elif defined(ARTEMIS)
    p4pd_cfg_t                 p4pd_cfg = {
            .table_map_cfg_file  = "artemis/capri_rxdma_table_map.json",
            .p4pd_pgm_name       = "artemis",
            .p4pd_rxdma_pgm_name = "p4plus",
            .p4pd_txdma_pgm_name = "p4plus",
            .cfg_path            = hal_cfg_path_.c_str(),
    };
#else
    p4pd_cfg_t                 p4pd_cfg = {
            .table_map_cfg_file  = "iris/capri_p4_rxdma_table_map.json",
            .p4pd_pgm_name       = "iris",
            .p4pd_rxdma_pgm_name = "p4plus",
            .p4pd_txdma_pgm_name = "p4plus",
            .cfg_path            = hal_cfg_path_.c_str(),
    };
#endif

    memset(&tinfo, 0, sizeof(tinfo));

    // parse the NCC generated table info file for p4+ tables
    rc = p4pluspd_rxdma_init(&p4pd_cfg);
    assert(rc == P4PD_SUCCESS);

    // start instantiating tables based on the parsed information
    p4plus_rxdma_dm_tables_ =
            (directmap **)calloc(sizeof(directmap *),
            (P4_COMMON_RXDMA_ACTIONS_TBL_ID_INDEX_MAX -
             P4_COMMON_RXDMA_ACTIONS_TBL_ID_INDEX_MIN + 1));
    assert(p4plus_rxdma_dm_tables_ != NULL);

    // TODO:
    // 1. take care of instantiating flow_table_, acl_table_ and met_table_
    // 2. When tables are instantiated proper names are not passed today,
    // waiting for an API from Mahesh that gives table name given table id

    for (tid = P4_COMMON_RXDMA_ACTIONS_TBL_ID_TBLMIN;
         tid < P4_COMMON_RXDMA_ACTIONS_TBL_ID_TBLMAX; tid++) {
        rc = p4pluspd_rxdma_table_properties_get(tid, &tinfo);
        assert(rc == P4PD_SUCCESS);

        switch (tinfo.table_type) {
            case P4_TBL_TYPE_INDEX:
                if (tinfo.tabledepth) {
                    p4plus_rxdma_dm_tables_[tid - P4_COMMON_RXDMA_ACTIONS_TBL_ID_INDEX_MIN] =
                        directmap::factory(tinfo.tablename, tid, tinfo.tabledepth, tinfo.actiondata_struct_size,
                                           false, ENTRY_TRACE_EN, table_health_monitor);
                    assert(p4plus_rxdma_dm_tables_
                           [tid - P4_COMMON_RXDMA_ACTIONS_TBL_ID_INDEX_MIN] != NULL);
                }
                break;

            case P4_TBL_TYPE_MPU:
            default:
                break;
        }
    }

    return 0;
}

int
p4plus_txdma_init_tables()
{
    uint32_t                   tid;
    p4pd_table_properties_t    tinfo;
    p4pd_error_t               rc;
    std::string hal_cfg_path_ = hal_cfg_path();

#if defined(APOLLO)
    p4pd_cfg_t                 p4pd_cfg = {
        .table_map_cfg_file  = "apollo/capri_txdma_table_map.json",
        .p4pd_pgm_name       = "apollo",
        .p4pd_rxdma_pgm_name = "p4plus",
        .p4pd_txdma_pgm_name = "p4plus",
        .cfg_path            = hal_cfg_path_.c_str(),
    };
#elif defined(ARTEMIS)
    p4pd_cfg_t                 p4pd_cfg = {
        .table_map_cfg_file  = "artemis/capri_txdma_table_map.json",
        .p4pd_pgm_name       = "artemis",
        .p4pd_rxdma_pgm_name = "p4plus",
        .p4pd_txdma_pgm_name = "p4plus",
        .cfg_path            = hal_cfg_path_.c_str(),
    };
#else
    p4pd_cfg_t                 p4pd_cfg = {
        .table_map_cfg_file  = "iris/capri_p4_txdma_table_map.json",
        .p4pd_pgm_name       = "iris",
        .p4pd_rxdma_pgm_name = "p4plus",
        .p4pd_txdma_pgm_name = "p4plus",
        .cfg_path            = hal_cfg_path_.c_str(),
    };
#endif

    memset(&tinfo, 0, sizeof(tinfo));

    // parse the NCC generated table info file for p4+ tables
    rc = p4pluspd_txdma_init(&p4pd_cfg);
    assert(rc == P4PD_SUCCESS);

    // start instantiating tables based on the parsed information
    p4plus_txdma_dm_tables_ =
        (directmap **)calloc(sizeof(directmap *),
                             (P4_COMMON_TXDMA_ACTIONS_TBL_ID_INDEX_MAX -
                              P4_COMMON_TXDMA_ACTIONS_TBL_ID_INDEX_MIN + 1));
    SDK_ASSERT(p4plus_txdma_dm_tables_ != NULL);

    // TODO:
    // 1. take care of instantiating flow_table_, acl_table_ and met_table_
    // 2. When tables are instantiated proper names are not passed today,
    // waiting for an API from Mahesh that gives table name given table id

    for (tid = P4_COMMON_TXDMA_ACTIONS_TBL_ID_TBLMIN;
         tid < P4_COMMON_TXDMA_ACTIONS_TBL_ID_TBLMAX; tid++) {
        rc = p4pluspd_txdma_table_properties_get(tid, &tinfo);
        SDK_ASSERT(rc == P4PD_SUCCESS);

        switch (tinfo.table_type) {
        case P4_TBL_TYPE_INDEX:
            if (tinfo.tabledepth) {
                p4plus_txdma_dm_tables_[tid - P4_COMMON_TXDMA_ACTIONS_TBL_ID_INDEX_MIN] =
                    directmap::factory(tinfo.tablename, tid, tinfo.tabledepth, tinfo.actiondata_struct_size,
                                       false, ENTRY_TRACE_EN, table_health_monitor);
                assert(p4plus_txdma_dm_tables_[tid - P4_COMMON_TXDMA_ACTIONS_TBL_ID_INDEX_MIN] != NULL);
            }
            break;

        case P4_TBL_TYPE_MPU:
        default:
            break;
        }
    }

    return 0;
}

void
pd_init()
{
    int ret;
    sdk::platform::capri::capri_state_pd_init(NULL);

    ret = p4plus_rxdma_init_tables();
    assert(ret == 0);
    ret = p4plus_txdma_init_tables();
    assert(ret == 0);

#if !defined(APOLLO) || !defined(ARTEMIS)
    ret = capri_p4plus_table_rw_init();
    assert(ret == 0);
#endif
}

int
p4pd_common_p4plus_rxdma_rss_params_table_entry_get(uint32_t hw_lif_id,
    eth_rx_rss_params_actiondata_t *data)
{
    p4pd_error_t        pd_err;

    assert(hw_lif_id < MAX_LIFS);

    pd_init();

    pd_err = p4pd_global_entry_read(P4_COMMON_RXDMA_ACTIONS_TBL_ID_ETH_RX_RSS_PARAMS,
                                    hw_lif_id, NULL, NULL, data);
    if (pd_err != P4PD_SUCCESS) {
        assert(0);
    }

    return 0;
}

void
p4pd_common_p4plus_rxdma_rss_params_table_entry_show(uint32_t hw_lif_id)
{
    eth_rx_rss_params_actiondata_t data = { 0 };

    p4pd_common_p4plus_rxdma_rss_params_table_entry_get(hw_lif_id, &data);

    memrev((uint8_t *)&data.action_u.eth_rx_rss_params_eth_rx_rss_params.rss_key,
           sizeof(data.action_u.eth_rx_rss_params_eth_rx_rss_params.rss_key));

    printf("type:  %x\n", data.action_u.eth_rx_rss_params_eth_rx_rss_params.rss_type);
    printf("key:   ");
    for (uint16_t i = 0; i < sizeof(data.action_u.eth_rx_rss_params_eth_rx_rss_params.rss_key); i++) {
        if (i != 0)
            printf(":");
        printf("%02x", data.action_u.eth_rx_rss_params_eth_rx_rss_params.rss_key[i]);
    }
    printf("\n");
    printf("debug: %x\n", data.action_u.eth_rx_rss_params_eth_rx_rss_params.debug);
}

int
p4pd_common_p4plus_rxdma_rss_params_table_entry_add(uint32_t hw_lif_id,
    uint8_t debug)
{
    p4pd_error_t        pd_err;
    eth_rx_rss_params_actiondata_t data = { 0 };

    assert(hw_lif_id < MAX_LIFS);

    p4pd_common_p4plus_rxdma_rss_params_table_entry_get(hw_lif_id, &data);

    data.action_u.eth_rx_rss_params_eth_rx_rss_params.debug = debug;

    pd_err = p4pd_global_entry_write(P4_COMMON_RXDMA_ACTIONS_TBL_ID_ETH_RX_RSS_PARAMS,
                                     hw_lif_id, NULL, NULL, &data);
    if (pd_err != P4PD_SUCCESS) {
        assert(0);
    }

    return 0;
}

int
p4pd_common_p4plus_rxdma_rss_indir_table_entry_show(uint32_t hw_lif_id)
{
    uint64_t tbl_base;
    uint64_t tbl_index;
    uint64_t addr;
    uint8_t index;
    eth_rx_rss_indir_actiondata_t data;

    std::string mpart_json = mpart_cfg_path();
    sdk::platform::utils::mpartition *mp_ = mpartition::factory(mpart_json.c_str());
    assert(mp_);

    if (hw_lif_id >= MAX_LIFS) {
        printf("Invalid lif %d\n", hw_lif_id);
        return -1;
    };

    tbl_base = mp_->start_addr(MEM_REGION_RSS_INDIR_TABLE_NAME);
    tbl_base = (tbl_base + ETH_RSS_INDIR_TBL_SZ) & ~(ETH_RSS_INDIR_TBL_SZ - 1);
    tbl_base += (hw_lif_id * ETH_RSS_LIF_INDIR_TBL_SZ);

    printf("ind_table: 0x%lx\n\t", tbl_base);
    for (index = 0; index < ETH_RSS_MAX_QUEUES; index++) {
        tbl_index = (index * ETH_RSS_LIF_INDIR_TBL_ENTRY_SZ);
        addr = tbl_base + tbl_index;
        sdk::lib::pal_mem_read(addr, (uint8_t *)&data.action_u,
                        sizeof(data.action_u), 0);
        printf("[%3d] %3d ", index,
            data.action_u.eth_rx_rss_indir_eth_rx_rss_indir.qid);
        if ((index + 1) % 8 == 0)
            printf("\n\t");
    }

    return 0;
}

void
qinfo(uint16_t lif)
{
    queue_info_t qinfo[8] = {0};

    if (!get_lif_qstate(lif, qinfo)) {
        printf("Failed to get qinfo for lif %u\n", lif);
        return;
    }

    for (int qtype = 0; qtype < 8; qtype++) {
        printf("qtype: %d    base: %12lx    size: %6u    count: %6u\n", qtype,
                qinfo[qtype].base, qinfo[qtype].size, qinfo[qtype].length);
    }
}

int
debug_logger(sdk_trace_level_e trace_level, const char *format, ...)
{
    return 0;
}

void
usage()
{
    printf("Usage:\n");
    printf("   qinfo          <lif>\n");
    printf("   qstate         <lif> <qtype> <qid>\n");
    printf("   qdump          <lif> <qtype> <qid> <ring>\n");
    printf("   debug          <lif> <qtype> <qid> <enable>\n");
    printf("   nvme_qstate    <lif> <qtype> <qid>\n");
    printf("   qpoll          <lif> <qtype>\n");
    printf("   stats          <lif>\n");
    printf("   stats_reset    <lif>\n");
    printf("   memrd          <addr> <size_in_bytes>\n");
    printf("   memwr          <addr> <size_in_bytes> <bytes> ...\n");
    printf("   memdump        <addr> <size_in_bytes>\n");
    printf("   bzero          <addr> <size_in_bytes>\n");
    printf("   find           <addr> <size_in_bytes> <pattern>\n");
    printf("   nfind          <addr> <size_in_bytes> <pattern>\n");
    printf("   port_config    <addr>\n");
    printf("   port_status    <addr>\n");
    printf("   lif_status     <addr>\n");
    printf("   rss            <lif>\n");
    printf("   rss_debug      <lif> <enable>\n");
    exit(1);
}

int
main(int argc, char **argv)
{
    if (argc < 2) {
        usage();
    }

    sdk::lib::logger::init(&debug_logger);

#ifdef __x86_64__
    assert(sdk::lib::pal_init(platform_type_t::PLATFORM_TYPE_SIM) ==
           sdk::lib::PAL_RET_OK);
#elif __aarch64__
    assert(sdk::lib::pal_init(platform_type_t::PLATFORM_TYPE_HW) ==
           sdk::lib::PAL_RET_OK);
#endif

    if (strcmp(argv[1], "qinfo") == 0) {
        if (argc != 3) {
            usage();
        }
        uint16_t lif = std::strtoul(argv[2], NULL, 0);
        qinfo(lif);
    } else if (strcmp(argv[1], "qstate") == 0) {
        if (argc != 5) {
            usage();
        }
        uint16_t lif = std::strtoul(argv[2], NULL, 0);
        uint8_t qtype = std::strtoul(argv[3], NULL, 0);
        uint32_t qid = std::strtoul(argv[4], NULL, 0);
        eth_qstate(lif, qtype, qid);
    } else if (strcmp(argv[1], "qdump") == 0) {
        if (argc != 6) {
            usage();
        }
        uint16_t lif = std::strtoul(argv[2], NULL, 0);
        uint8_t qtype = std::strtoul(argv[3], NULL, 0);
        uint32_t qid = std::strtoul(argv[4], NULL, 0);
        uint8_t ring = std::strtoul(argv[5], NULL, 0);
        eth_qdump(lif, qtype, qid, ring);
    } else if (strcmp(argv[1], "debug") == 0) {
        if (argc != 6) {
            usage();
        }
        uint16_t lif = std::strtoul(argv[2], NULL, 0);
        uint8_t qtype = std::strtoul(argv[3], NULL, 0);
        uint32_t qid = std::strtoul(argv[4], NULL, 0);
        uint8_t enable = std::strtoul(argv[5], NULL, 0);
        eth_debug(lif, qtype, qid, enable);
    } else if (strcmp(argv[1], "nvme_qstate") == 0) {
        if (argc != 5) {
            usage();
        }
        uint16_t lif = std::strtoul(argv[2], NULL, 0);
        uint8_t qtype = std::strtoul(argv[3], NULL, 0);
        uint32_t qid = std::strtoul(argv[4], NULL, 0);
        nvme_qstate(lif, qtype, qid); 
    } else if (strcmp(argv[1], "qpoll") == 0) {
        if (argc != 4) {
            usage();
        }
        uint16_t lif = std::strtoul(argv[2], NULL, 0);
        uint8_t qtype = std::strtoul(argv[3], NULL, 0);
        eth_qpoll(lif, qtype);
    } else if (strcmp(argv[1], "stats") == 0) {
        if (argc != 3) {
            usage();
        }
        uint16_t lif = std::strtoul(argv[2], NULL, 0);
        eth_stats(lif);
    } else if (strcmp(argv[1], "stats_reset") == 0) {
        if (argc != 3) {
            usage();
        }
        uint16_t lif = std::strtoul(argv[2], NULL, 0);
        eth_stats_reset(lif);
        eth_stats(lif);
    } else if (strcmp(argv[1], "memrd") == 0) {
        if (argc != 4) {
            usage();
        }
        uint64_t addr = strtoul(argv[2], NULL, 16);
        uint32_t size = strtoul(argv[3], NULL, 0);
        uint8_t *buf = (uint8_t *)calloc(1, size);
        assert(buf != NULL);
        sdk::lib::pal_mem_read(addr, buf, size);
        for (uint32_t i = 0; i < size / 16; i++) {
            printf("%0lx : ", addr + (i * 16));
            for (uint32_t j = 0; j < 16; j++) {
                printf("%02x ", buf[(i * 16) + j]);
            }
            printf("\n");
        }
        printf("\n");
        free(buf);
    } else if (strcmp(argv[1], "memwr") == 0) {
        if (argc <= 4) {
            usage();
        }
        uint64_t addr = strtoul(argv[2], NULL, 16);
        uint32_t size = strtoul(argv[3], NULL, 0);
        if (argc == (int)(3 + size)) {
            printf("Not enough bytes to write\n");
            usage();
        }
        uint8_t *buf = (uint8_t *)calloc(1, size);
        assert(buf != NULL);
        for (uint32_t i = 0; i < size; i++) {
            buf[i] = strtoul(argv[4 + i], NULL, 16);
        }
        sdk::lib::pal_mem_write(addr, buf, size);
        free(buf);
    } else if (strcmp(argv[1], "memdump") == 0) {
        if (argc != 5) {
            usage();
        }
        uint64_t addr = strtoul(argv[2], NULL, 16);
        uint32_t size = strtoul(argv[3], NULL, 0);
        uint8_t *buf = (uint8_t *)calloc(1, size);
        assert(buf != NULL);
        sdk::lib::pal_mem_read(addr, buf, size);
        FILE *fp = fopen(argv[4], "wb");
        assert(fp != NULL);
        fwrite(buf, sizeof(buf[0]), size, fp);
        fclose(fp);
    } else if (strcmp(argv[1], "bzero") == 0) {
        if (argc != 4) {
            usage();
        }
        uint64_t addr = strtoul(argv[2], NULL, 16);
        uint32_t size = strtoul(argv[3], NULL, 0);
        uint8_t *buf = (uint8_t *)calloc(1, size);
        assert(buf != NULL);
        sdk::lib::pal_mem_write(addr, buf, size);
        free(buf);
    } else if (strcmp(argv[1], "find") == 0) {
        if (argc != 5) {
            usage();
        }
        uint64_t addr = strtoul(argv[2], NULL, 16);
        uint32_t size = strtoul(argv[3], NULL, 0);
        uint32_t pattern = strtoul(argv[4], NULL, 0);
        uint32_t val;
        for (uint32_t i = 0; i < size / 4; i++) {
            sdk::lib::pal_mem_read(addr + i * 4, (uint8_t *)&val, sizeof(val));
            if (val == pattern) {
                printf("0x%lx\n", addr + i * 4);
                return 0;
            }
        }
        printf("Pattern 0x%x not found in region 0x%lx - 0x%lx\n", pattern, addr, addr + size);
        return -1;
    } else if (strcmp(argv[1], "nfind") == 0) {
        if (argc != 5) {
            usage();
        }
        uint64_t addr = strtoul(argv[2], NULL, 16);
        uint32_t size = strtoul(argv[3], NULL, 0);
        uint32_t pattern = strtoul(argv[4], NULL, 0);
        uint32_t val;
        for (uint32_t i = 0; i < size / 4; i++) {
            sdk::lib::pal_mem_read(addr + i * 4, (uint8_t *)&val, sizeof(val));
            if (val != pattern) {
                printf("0x%lx\n", addr + i * 4);
                return 0;
            }
        }
        printf("Pattern 0x%x not found in region 0x%lx - 0x%lx\n", pattern, addr, addr + size);
        return -1;
    } else if (strcmp(argv[1], "port_config") == 0) {
        if (argc != 3) {
            usage();
        }
        uint64_t addr = strtoul(argv[2], NULL, 16);
        port_config(addr);
    } else if (strcmp(argv[1], "port_status") == 0) {
        if (argc != 3) {
            usage();
        }
        uint64_t addr = strtoul(argv[2], NULL, 16);
        port_status(addr);
    } else if (strcmp(argv[1], "lif_status") == 0) {
        if (argc != 3) {
            usage();
        }
        uint64_t addr = strtoul(argv[2], NULL, 16);
        lif_status(addr);
    } else if (strcmp(argv[1], "rss") == 0) {
        if (argc != 3) {
            usage();
        }
        uint16_t lif_id = strtoul(argv[2], NULL, 0);
        printf("\n");
        p4pd_common_p4plus_rxdma_rss_params_table_entry_show(lif_id);
        p4pd_common_p4plus_rxdma_rss_indir_table_entry_show(lif_id);
        printf("\n");
    } else if (strcmp(argv[1], "rss_debug") == 0) {
        if (argc != 4) {
            usage();
        }
        uint16_t lif_id = strtoul(argv[2], NULL, 0);
        uint8_t enable = std::strtoul(argv[3], NULL, 0);
        p4pd_common_p4plus_rxdma_rss_params_table_entry_add(lif_id, enable);
        printf("\n");
        p4pd_common_p4plus_rxdma_rss_params_table_entry_show(lif_id);
        p4pd_common_p4plus_rxdma_rss_indir_table_entry_show(lif_id);
        printf("\n");
    } else {
        usage();
    }

    return 0;
}
