/*
 * Copyright (c) 2018, Pensando Systems Inc.
 */

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <endian.h>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <sys/param.h>

#include "nic/include/edmaq.h"
#include "nic/p4/common/defines.h"
#include "nic/sdk/lib/thread/thread.hpp"
#include "nic/sdk/include/sdk/eth.hpp"
#include "nic/sdk/platform/intrutils/include/intrutils.h"
#include "nic/sdk/asic/pd/pd.hpp"
#include "nic/sdk/platform/misc/include/misc.h"
#include "nic/sdk/platform/pciemgr_if/include/pciemgr_if.hpp"
#include "gen/platform/mem_regions.hpp"

#include "nic/sdk/platform/devapi/devapi_types.hpp"

#include "adminq.hpp"
#include "edmaq.hpp"
#include "dev.hpp"
#include "eth_dev.hpp"
#include "eth_if.h"
#include "eth_lif.hpp"
#include "logger.hpp"
#include "pd_client.hpp"
#include "rdma_dev.hpp"

using namespace sdk::platform::capri;
using namespace sdk::platform::utils;

#define HOST_ADDR(lif, addr) ((1ULL << 63) | (lif << 52) | (addr))

sdk::lib::indexer *EthLif::fltr_allocator = sdk::lib::indexer::factory(4096);


const char *
EthLif::lif_state_to_str(enum eth_lif_state state)
{
    switch (state) {
        CASE(LIF_STATE_RESETTING);
        CASE(LIF_STATE_RESET);
        CASE(LIF_STATE_CREATING);
        CASE(LIF_STATE_CREATED);
        CASE(LIF_STATE_INITING);
        CASE(LIF_STATE_INIT);
        CASE(LIF_STATE_UP);
        CASE(LIF_STATE_DOWN);
    default:
        return "LIF_STATE_INVALID";
    }
}

const char *
EthLif::opcode_to_str(cmd_opcode_t opcode)
{
    switch (opcode) {
        CASE(IONIC_CMD_NOP);
        CASE(IONIC_CMD_LIF_IDENTIFY);
        CASE(IONIC_CMD_LIF_GETATTR);
        CASE(IONIC_CMD_LIF_SETATTR);
        CASE(IONIC_CMD_RX_MODE_SET);
        CASE(IONIC_CMD_RX_FILTER_ADD);
        CASE(IONIC_CMD_RX_FILTER_DEL);
        CASE(IONIC_CMD_Q_IDENTIFY);
        CASE(IONIC_CMD_Q_INIT);
        CASE(IONIC_CMD_Q_CONTROL);
        CASE(IONIC_CMD_RDMA_RESET_LIF);
        CASE(IONIC_CMD_RDMA_CREATE_EQ);
        CASE(IONIC_CMD_RDMA_CREATE_CQ);
        CASE(IONIC_CMD_RDMA_CREATE_ADMINQ);
        CASE(IONIC_CMD_FW_DOWNLOAD);
        CASE(IONIC_CMD_FW_CONTROL);
        default: return "UNKNOWN";
    }
}

EthLif::EthLif(Eth *dev, devapi *dev_api, void *dev_spec,
               PdClient *pd_client, eth_lif_res_t *res, EV_P)
{
    EthLif::dev = dev;
    EthLif::dev_api = dev_api;
    EthLif::spec = (struct eth_devspec *)dev_spec;
    EthLif::res = res;
    EthLif::pd = pd_client;
    EthLif::adminq = NULL;
    strncpy0(EthLif::name, spec->name.c_str(), sizeof(EthLif::name));
    EthLif::loop = loop;
    EthLif::host_lif_stats_addr = 0;
    EthLif::mtu = MTU_DEFAULT;
    EthLif::active_q_ref_cnt = 0;
    EthLif::notify_enabled = 0;
    EthLif::notify_ring_head = 0;
}

void
EthLif::Init(void) {
    // Create LIF
    state = LIF_STATE_CREATING;

    NIC_LOG_INFO("{}: Lif Init", spec->name);

    memset(&hal_lif_info_, 0, sizeof(lif_info_t));
    strncpy0(hal_lif_info_.name, name, sizeof(hal_lif_info_.name));
    hal_lif_info_.lif_id = res->lif_id;
    hal_lif_info_.type = (lif_type_t)Eth::ConvertDevTypeToLifType(spec->eth_type);
    hal_lif_info_.pinned_uplink_port_num = spec->uplink_port_num;
    hal_lif_info_.enable_rdma = spec->enable_rdma;
    hal_lif_info_.tx_sched_table_offset = INVALID_INDEXER_INDEX;
    hal_lif_info_.tx_sched_num_table_entries = 0;
    MAC_UINT64_TO_ADDR(hal_lif_info_.mac, spec->mac_addr);

    // For debugging: by default enables rdma sniffer on all host ifs
#if 0
    if (hal_lif_info_.type == sdk::platform::LIF_TYPE_HOST) {
        hal_lif_info_.rdma_sniff = true;
    }
#endif

    QinfoInit();

#ifdef __x86_64__
    pd->program_qstate((struct queue_info *)hal_lif_info_.queue_info, &hal_lif_info_, 0x0);
#endif

    NIC_LOG_INFO("{}: created lif_id {} mac {} uplink {}", spec->name, hal_lif_info_.lif_id,
                 mac2str(spec->mac_addr), spec->uplink_port_num);

    // Stats
    lif_stats_addr = pd->mp_->start_addr(MEM_REGION_LIF_STATS_NAME);
    if (lif_stats_addr == INVALID_MEM_ADDRESS || lif_stats_addr == 0) {
        NIC_LOG_ERR("{}: Failed to locate stats region", hal_lif_info_.name);
        throw;
    }
    lif_stats_addr += (hal_lif_info_.lif_id << LG2_LIF_STATS_SIZE);

    NIC_LOG_INFO("{}: lif_stats_addr: {:#x}", hal_lif_info_.name, lif_stats_addr);

    AddLifMetrics();
    LifConfigStatusMem(true);

    // init Queues and FW buffer memory
    LifQInit(true);
    FwBufferInit();

    if (dev_api != NULL) {
        Create();
    }

    StatsEnable();
}

void
EthLif::UpgradeGracefulInit(void) {
    // Create LIF
    state = LIF_STATE_CREATING;

    NIC_LOG_INFO("{}: Lif Upgrade graceful Init", spec->name);

    memset(&hal_lif_info_, 0, sizeof(lif_info_t));
    strncpy0(hal_lif_info_.name, name, sizeof(hal_lif_info_.name));
    hal_lif_info_.lif_id = res->lif_id;
    hal_lif_info_.type = (lif_type_t)Eth::ConvertDevTypeToLifType(spec->eth_type);
    hal_lif_info_.pinned_uplink_port_num = spec->uplink_port_num;
    hal_lif_info_.enable_rdma = spec->enable_rdma;
    hal_lif_info_.tx_sched_table_offset = INVALID_INDEXER_INDEX;
    hal_lif_info_.tx_sched_num_table_entries = 0;
    MAC_UINT64_TO_ADDR(hal_lif_info_.mac, spec->mac_addr);

    // For debugging: by default enables rdma sniffer on all host ifs
#if 0
    if (hal_lif_info_.type == sdk::platform::LIF_TYPE_HOST) {
        hal_lif_info_.rdma_sniff = true;
    }
#endif

    QinfoInit();

#ifdef __x86_64__
    pd->program_qstate((struct queue_info *)hal_lif_info_.queue_info, &hal_lif_info_, 0x0);
#endif

    NIC_LOG_INFO("{}: created lif_id {} mac {} uplink {}", spec->name, hal_lif_info_.lif_id,
                 mac2str(spec->mac_addr), spec->uplink_port_num);

    // Stats
    lif_stats_addr = pd->mp_->start_addr(MEM_REGION_LIF_STATS_NAME);
    if (lif_stats_addr == INVALID_MEM_ADDRESS || lif_stats_addr == 0) {
        NIC_LOG_ERR("{}: Failed to locate stats region", hal_lif_info_.name);
        throw;
    }
    lif_stats_addr += (hal_lif_info_.lif_id << LG2_LIF_STATS_SIZE);

    NIC_LOG_INFO("{}: lif_stats_addr: {:#x}", hal_lif_info_.name, lif_stats_addr);

    AddLifMetrics();
    LifConfigStatusMem(false);

    // init Queues and FW buffer memory
    LifQInit(false);
    FwBufferInit();

    if (dev_api != NULL) {
        Create();
    }

    StatsEnable();
}

void
EthLif::UpgradeHitlessInit(void) {
    // Create LIF
    state = LIF_STATE_CREATING;

    NIC_LOG_INFO("{}: Lif Upgrade Hitless Init", spec->name);

    memset(&hal_lif_info_, 0, sizeof(lif_info_t));
    strncpy0(hal_lif_info_.name, name, sizeof(hal_lif_info_.name));
    hal_lif_info_.lif_id = res->lif_id;
    hal_lif_info_.type = (lif_type_t)Eth::ConvertDevTypeToLifType(spec->eth_type);
    hal_lif_info_.pinned_uplink_port_num = spec->uplink_port_num;
    hal_lif_info_.enable_rdma = spec->enable_rdma;
    hal_lif_info_.tx_sched_table_offset = INVALID_INDEXER_INDEX;
    hal_lif_info_.tx_sched_num_table_entries = 0;
    MAC_UINT64_TO_ADDR(hal_lif_info_.mac, spec->mac_addr);

    // For debugging: by default enables rdma sniffer on all host ifs
#if 0
    if (hal_lif_info_.type == sdk::platform::LIF_TYPE_HOST) {
        hal_lif_info_.rdma_sniff = true;
    }
#endif

    QinfoInit();

    NIC_LOG_INFO("{}: created lif_id {} mac {} uplink {}", spec->name, hal_lif_info_.lif_id,
                 mac2str(spec->mac_addr), spec->uplink_port_num);

    // Stats
    lif_stats_addr = pd->mp_->start_addr(MEM_REGION_LIF_STATS_NAME);
    if (lif_stats_addr == INVALID_MEM_ADDRESS || lif_stats_addr == 0) {
        NIC_LOG_ERR("{}: Failed to locate stats region", hal_lif_info_.name);
        throw;
    }
    lif_stats_addr += (hal_lif_info_.lif_id << LG2_LIF_STATS_SIZE);

    NIC_LOG_INFO("{}: lif_stats_addr: {:#x}", hal_lif_info_.name, lif_stats_addr);

    AddLifMetrics();
    LifConfigStatusMem(false);

    // init Queues and FW buffer memory
    LifQInit(false);
    FwBufferInit();

    if (dev_api != NULL) {
        Create();
    }

    StatsEnable();
}

void
EthLif::QinfoInit(void) {

    memset(qinfo, 0, sizeof(qinfo));

    qinfo[ETH_HW_QTYPE_RX] = {
        .type_num = ETH_HW_QTYPE_RX,
        .size = 1,
        .entries = (uint32_t)log2(spec->rxq_count),
    };

    qinfo[ETH_HW_QTYPE_TX] = {
        .type_num = ETH_HW_QTYPE_TX,
        .size = 2,
        .entries = (uint32_t)log2(spec->txq_count),
    };

    qinfo[ETH_HW_QTYPE_ADMIN] = {
        .type_num = ETH_HW_QTYPE_ADMIN,
        .size = 2,
        .entries = (uint32_t)log2(spec->adminq_count + spec->rdma_aq_count),
    };

    qinfo[ETH_HW_QTYPE_SQ] = {
        .type_num = ETH_HW_QTYPE_SQ,
        .size = 4,
        .entries = (uint32_t)log2(spec->rdma_sq_count),
    };

    qinfo[ETH_HW_QTYPE_RQ] = {
        .type_num = ETH_HW_QTYPE_RQ,
        .size = 4,
        .entries = (uint32_t)log2(spec->rdma_rq_count),
    };

    qinfo[ETH_HW_QTYPE_CQ] = {
        .type_num = ETH_HW_QTYPE_CQ,
        .size = 1,
        .entries = (uint32_t)log2(spec->rdma_cq_count),
    };

    qinfo[ETH_HW_QTYPE_EQ] = {
        .type_num = ETH_HW_QTYPE_EQ,
        .size = 1,
        .entries = (uint32_t)log2(spec->rdma_eq_count),
    };

    qinfo[ETH_HW_QTYPE_SVC] = {
        .type_num = ETH_HW_QTYPE_SVC,
        .size = 2,
        .entries = 3,
    };

    memcpy(hal_lif_info_.queue_info, qinfo, sizeof(hal_lif_info_.queue_info));
}

void
EthLif::LifConfigStatusMem(bool mem_clr) {
    // Lif Config
    lif_config_addr = pd->nicmgr_mem_alloc(sizeof(union ionic_lif_config));
    host_lif_config_addr = 0;
    lif_config = (union ionic_lif_config *)MEM_MAP(lif_config_addr,
                                           sizeof(union ionic_lif_config), 0);
    if (lif_config == NULL) {
        NIC_LOG_ERR("{}: Failed to map lif config!", hal_lif_info_.name);
        throw;
    }

    if (mem_clr) {
        MEM_CLR(lif_config_addr, lif_config, sizeof(union ionic_lif_config));
    }

    NIC_LOG_INFO("{}: lif_config_addr {:#x}", hal_lif_info_.name, lif_config_addr);

    // Lif Status
    lif_status_addr = pd->nicmgr_mem_alloc(sizeof(struct ionic_lif_status));
    host_lif_status_addr = 0;
    lif_status = (struct ionic_lif_status *)MEM_MAP(lif_status_addr,
                                            sizeof(struct ionic_lif_status), 0);
    if (lif_status == NULL) {
        NIC_LOG_ERR("{}: Failed to map lif status!", hal_lif_info_.name);
        throw;
    }
    if (mem_clr) {
        MEM_CLR(lif_status_addr, lif_status, sizeof(struct ionic_lif_status));
    }

    NIC_LOG_INFO("{}: lif_status_addr {:#x}", hal_lif_info_.name, lif_status_addr);
}

void
EthLif::LifQInit(bool mem_clr) {
    // NotifyQ
    notify_ring_base =
        pd->nicmgr_mem_alloc(4096 + (sizeof(union ionic_notifyq_comp) *
                                     ETH_NOTIFYQ_RING_SIZE));
    if (notify_ring_base == 0) {
        NIC_LOG_ERR("{}: Failed to allocate notify ring!", hal_lif_info_.name);
        throw;
    }

    if (mem_clr) {
        MEM_CLR(notify_ring_base, 0, 4096 + (sizeof(union ionic_notifyq_comp) *
                                             ETH_NOTIFYQ_RING_SIZE));
    }

    NIC_LOG_INFO("{}: notify_ring_base {:#x}", hal_lif_info_.name, notify_ring_base);

    // EdmaQ
    edma_buf_addr = pd->nicmgr_mem_alloc(4096);
    if (edma_buf_addr == 0) {
        NIC_LOG_ERR("{}: Failed to allocate edma buffer!", hal_lif_info_.name);
        throw;
    }

    NIC_LOG_INFO("{}: edma_buf_addr {:#x}", hal_lif_info_.name, edma_buf_addr);

    edma_buf = (uint8_t *)MEM_MAP(edma_buf_addr, 4096, 0);
    if (edma_buf == NULL) {
        NIC_LOG_ERR("{}: Failed to map edma buffer", hal_lif_info_.name);
        throw;
    }

    edmaq = new EdmaQ(hal_lif_info_.name, pd, hal_lif_info_.lif_id,
                      ETH_EDMAQ_QTYPE, ETH_EDMAQ_QID,
                      ETH_EDMAQ_RING_SIZE, EV_A);

    edmaq_async = new EdmaQ(hal_lif_info_.name, pd, hal_lif_info_.lif_id,
                            ETH_EDMAQ_ASYNC_QTYPE, ETH_EDMAQ_ASYNC_QID,
                            ETH_EDMAQ_ASYNC_RING_SIZE, EV_A);

    // AdminQ
    adminq =
        new AdminQ(hal_lif_info_.name, pd, hal_lif_info_.lif_id, ETH_ADMINQ_REQ_QTYPE,
                   ETH_ADMINQ_REQ_QID, ETH_ADMINQ_REQ_RING_SIZE, ETH_ADMINQ_RESP_QTYPE,
                   ETH_ADMINQ_RESP_QID, ETH_ADMINQ_RESP_RING_SIZE, AdminCmdHandler, this, EV_A);
}

void
EthLif::FwBufferInit(void) {

    // Firmware Update
    fw_buf_addr = pd->mp_->start_addr(MEM_REGION_FWUPDATE_NAME);
    if (fw_buf_addr == INVALID_MEM_ADDRESS || fw_buf_addr == 0) {
        NIC_LOG_ERR("{}: Failed to locate fwupdate region base", hal_lif_info_.name);
        throw;
    }

    fw_buf_size = pd->mp_->size(MEM_REGION_FWUPDATE_NAME);
    if (fw_buf_size == 0) {
        NIC_LOG_ERR("{}: Failed to locate fwupdate region size", hal_lif_info_.name);
    };

    NIC_LOG_INFO("{}: fw_buf_addr {:#x} fw_buf_size {}", hal_lif_info_.name, fw_buf_addr,
                 fw_buf_size);

    fw_buf = (uint8_t *)MEM_MAP(fw_buf_addr, fw_buf_size, 0);
    if (fw_buf == NULL) {
        NIC_LOG_ERR("{}: Failed to map firmware buffer", hal_lif_info_.name);
        throw;
    };
}

void
EthLif::StatsEnable(void) {

    // Init stats timer
    ev_timer_init(&stats_timer, &EthLif::StatsUpdate, 0.0, 0.1);
    ev_timer_init(&sched_eval_timer, &EthLif::SchedBulkEvalHandler, 0.0, 0.02);

    stats_timer.data = this;
    sched_eval_timer.data = this;
}

void
EthLif::Create()
{
    sdk_ret_t rs;

    if (state != LIF_STATE_CREATING) {
        return;
    }

    hal_lif_info_.lif_state = ConvertEthLifStateToLifState(state);
    rs = dev_api->lif_create(&hal_lif_info_);
    if (rs != SDK_RET_OK) {
        NIC_LOG_ERR("{}: Failed to create LIF", hal_lif_info_.name);
        return;
    }

    NIC_LOG_INFO("{}: Created", hal_lif_info_.name);

    state = LIF_STATE_CREATED;
}

status_code_t
EthLif::CmdInit(void *req, void *req_data, void *resp, void *resp_data)
{
    sdk_ret_t rs = SDK_RET_OK;
    uint64_t addr;
    struct ionic_lif_init_cmd *cmd = (struct ionic_lif_init_cmd *)req;
    enum eth_lif_state pre_state;

    NIC_LOG_DEBUG("{}: LIF_INIT", hal_lif_info_.name);

    if (state == LIF_STATE_CREATING) {
        NIC_LOG_WARN("{}: {} + INIT => {}", hal_lif_info_.name, lif_state_to_str(state),
                     lif_state_to_str(state));
        return (IONIC_RC_EAGAIN);
    }

    if (IsLifInitialized()) {
        NIC_LOG_WARN("{}: {} + INIT => {}", hal_lif_info_.name, lif_state_to_str(state),
                     lif_state_to_str(state));
        return (IONIC_RC_EBUSY);
    }

    DEVAPI_CHECK

    pre_state = state;
    state = LIF_STATE_INITING;

    // first time, program txdma scheduler
    if (pre_state == LIF_STATE_CREATED) {
#ifndef __x86_64__
        //TODO: Revisit for Hitless Upgrade
        pd->program_qstate((struct queue_info *)hal_lif_info_.queue_info, &hal_lif_info_, 0x0);
#endif
        hal_lif_info_.lif_state = ConvertEthLifStateToLifState(state);
        rs = dev_api->lif_init(&hal_lif_info_);
        if (rs != SDK_RET_OK) {
            NIC_LOG_ERR("{}: Failed to init LIF", hal_lif_info_.name);
            return (IONIC_RC_ERROR);
        }

        cosA = 0;
        cosB = 0;
        dev_api->qos_get_txtc_cos(spec->qos_group, spec->uplink_port_num, &cosB);
        if (cosB < 0) {
            NIC_LOG_ERR("{}: Failed to get cosB for group {}, uplink {}", hal_lif_info_.name,
                        spec->qos_group, spec->uplink_port_num);
            return (IONIC_RC_ERROR);
        }

        admin_cosA = 1;
        admin_cosB = 1;

        if (spec->enable_rdma) {
            NIC_LOG_DEBUG("prefetch_count: {}", spec->prefetch_count);
            pd->rdma_lif_init(hal_lif_info_.lif_id, spec->key_count, spec->ah_count,
                              spec->pte_count, res->cmb_mem_addr, res->cmb_mem_size,
                              spec->prefetch_count);
            // TODO: Handle error
        }
    }

    int ret;
    // Reset RSS configuration
    rss_type = LIF_RSS_TYPE_NONE;
    memset(rss_key, 0x00, RSS_HASH_KEY_SIZE);
    memset(rss_indir, 0x00, RSS_IND_TBL_SIZE);
    ret = pd->eth_program_rss(hal_lif_info_.lif_id, rss_type, rss_key, rss_indir, spec->rxq_count);
    if (ret != 0) {
        NIC_LOG_DEBUG("{}: Unable to program hw for RSS HASH", ret);
        return (IONIC_RC_ERROR);
    }

    // Clear PC to drop all traffic
    for (uint32_t qid = 0; qid < spec->rxq_count; qid++) {
        addr = pd->lm_->get_lif_qstate_addr(hal_lif_info_.lif_id, ETH_HW_QTYPE_RX, qid);
        if (addr < 0) {
            NIC_LOG_ERR("{}: Failed to get qstate address for RX qid {}", hal_lif_info_.name, qid);
            return (IONIC_RC_ERROR);
        }
        MEM_SET(addr, 0, fldsiz(eth_rx_qstate_t, q.intr.pc_offset), 0);
        PAL_barrier();
        sdk::asic::pd::asicpd_p4plus_invalidate_cache(addr, sizeof(eth_rx_qstate_t), P4PLUS_CACHE_INVALIDATE_BOTH);
    }

    for (uint32_t qid = 0; qid < spec->txq_count; qid++) {
        addr = pd->lm_->get_lif_qstate_addr(hal_lif_info_.lif_id, ETH_HW_QTYPE_TX, qid);
        if (addr < 0) {
            NIC_LOG_ERR("{}: Failed to get qstate address for TX qid {}", hal_lif_info_.name, qid);
            return (IONIC_RC_ERROR);
        }
        MEM_SET(addr, 0, fldsiz(eth_tx_qstate_t, q.intr.pc_offset), 0);
        PAL_barrier();
        sdk::asic::pd::asicpd_p4plus_invalidate_cache(addr, sizeof(eth_tx_qstate_t), P4PLUS_CACHE_INVALIDATE_TXDMA);
    }

    active_q_ref_cnt = 0;

    for (uint32_t qid = 0; qid < spec->adminq_count; qid++) {
        addr = pd->lm_->get_lif_qstate_addr(hal_lif_info_.lif_id, ETH_HW_QTYPE_ADMIN, qid);
        if (addr < 0) {
            NIC_LOG_ERR("{}: Failed to get qstate address for ADMIN qid {}", hal_lif_info_.name,
                        qid);
            return (IONIC_RC_ERROR);
        }
        MEM_SET(addr, 0, fldsiz(admin_qstate_t, pc_offset), 0);
        PAL_barrier();
        sdk::asic::pd::asicpd_p4plus_invalidate_cache(addr, sizeof(admin_qstate_t), P4PLUS_CACHE_INVALIDATE_TXDMA);
    }

    mtu = MTU_DEFAULT;

    // Initialize NotifyQ
    notify_enabled = 0;
    notify_ring_head = 0;
    MEM_SET(notify_ring_base, 0, 4096 + (sizeof(union ionic_notifyq_comp) * ETH_NOTIFYQ_RING_SIZE), 0);

    // Initialize EDMA service
    if (!edmaq->Init(0, admin_cosA, admin_cosB)) {
        NIC_LOG_ERR("{}: Failed to initialize EdmaQ service", hal_lif_info_.name);
        return (IONIC_RC_ERROR);
    }

    if (!edmaq_async->Init(0, admin_cosA, admin_cosB)) {
        NIC_LOG_ERR("{}: Failed to initialize EdmaQ Async service", hal_lif_info_.name);
        return (IONIC_RC_ERROR);
    }

    // Initialize ADMINQ service
    if (!adminq->Init(0, admin_cosA, admin_cosB)) {
        NIC_LOG_ERR("{}: Failed to initialize AdminQ service", hal_lif_info_.name);
        return (IONIC_RC_ERROR);
    }

    if (cmd->info_pa) {
        NIC_LOG_INFO("{}: host_lif_info_addr {:#x}", hal_lif_info_.name, cmd->info_pa);

        host_lif_config_addr = cmd->info_pa + offsetof(struct ionic_lif_info, config);
        NIC_LOG_INFO("{}: host_lif_config_addr {:#x}", hal_lif_info_.name, host_lif_config_addr);

        host_lif_status_addr = cmd->info_pa + offsetof(struct ionic_lif_info, status);
        NIC_LOG_INFO("{}: host_lif_status_addr {:#x}", hal_lif_info_.name, host_lif_status_addr);

        host_lif_stats_addr = cmd->info_pa + offsetof(struct ionic_lif_info, stats);
        NIC_LOG_INFO("{}: host_lif_stats_addr {:#x}", hal_lif_info_.name, host_lif_stats_addr);

        // Start stats timer
        ev_timer_start(EV_A_ & stats_timer);
    }

    // Workaround for Capri Scheduler bug.
    // 1. Run a timer per lif in nicmgr for 20 ms.
    // 2. Read scheduler-table and issue Eval for all sched set RQs as part of timer callback.
    // Currently this is done only for RDMA RQs.
    if (spec->enable_rdma) {
        // Store HBM scheduler-table start addr of RQs of this LIF.
        // This will be used in SchedBulkEvalHandler for reading scheduler table and issue Bulk Eval
        // for all current active queues in datapath.
        // RQ qtype is 4. So find number of queues for qtypes 0-3 from eth lif spec to calculate base addr.
        // Also each row in scheduler table covers 8K queues (1KB), 1 bit per queue.
        hal_lif_info_.tx_sched_bulk_eval_start_addr = pd->mp_->start_addr(MEM_REGION_TX_SCHEDULER_NAME) +
                                                      (hal_lif_info_.tx_sched_table_offset * 1024) +
                                                      ((spec->rxq_count + spec->txq_count + spec->adminq_count +
                                                        spec->rdma_aq_count + spec->rdma_sq_count) / 8);
        // Start BulkEval timer for 20ms.
        ev_timer_start(EV_A_ & sched_eval_timer);
    }

    // Init the status block
    memset(lif_status, 0, sizeof(*lif_status));

    // Init the stats region
    MEM_SET(lif_stats_addr, 0, LIF_STATS_SIZE, 0);
    sdk::asic::pd::asicpd_p4plus_invalidate_cache(lif_stats_addr, sizeof(struct ionic_lif_stats),
                                                  P4PLUS_CACHE_INVALIDATE_BOTH);
    sdk::asic::pd::asicpd_p4_invalidate_cache(lif_stats_addr, sizeof(struct ionic_lif_stats),
                                              P4_TBL_CACHE_INGRESS);
    sdk::asic::pd::asicpd_p4_invalidate_cache(lif_stats_addr, sizeof(struct ionic_lif_stats),
                                              P4_TBL_CACHE_EGRESS);

    state = LIF_STATE_INIT;

    return (IONIC_RC_SUCCESS);
}

void
EthLif::FreeUpMacFilters()
{
    uint64_t filter_id;
    indexer::status rs;

    for (auto it = mac_addrs.cbegin(); it != mac_addrs.cend();) {
        filter_id = it->first;
        rs = fltr_allocator->free(filter_id);
        if (rs != indexer::SUCCESS) {
            NIC_LOG_ERR("Failed to free filter_id: {}, err: {}", filter_id, rs);
            // return (IONIC_RC_ERROR);
        }
        NIC_LOG_DEBUG("Freed filter_id: {}", filter_id);
        it = mac_addrs.erase(it);
    }
}

void
EthLif::FreeUpVlanFilters()
{
    uint64_t filter_id;
    indexer::status rs;

    for (auto it = vlans.cbegin(); it != vlans.cend();) {
        filter_id = it->first;
        rs = fltr_allocator->free(filter_id);
        if (rs != indexer::SUCCESS) {
            NIC_LOG_ERR("Failed to free filter_id: {}, err: {}", filter_id, rs);
            // return (IONIC_RC_ERROR);
        }
        NIC_LOG_DEBUG("Freed filter_id: {}", filter_id);
        it = vlans.erase(it);
    }
}

void
EthLif::FreeUpMacVlanFilters()
{
    uint64_t filter_id;
    indexer::status rs;

    for (auto it = mac_vlans.cbegin(); it != mac_vlans.cend();) {
        filter_id = it->first;
        rs = fltr_allocator->free(filter_id);
        if (rs != indexer::SUCCESS) {
            NIC_LOG_ERR("Failed to free filter_id: {}, err: {}", filter_id, rs);
            // return (IONIC_RC_ERROR);
        }
        NIC_LOG_DEBUG("Freed filter_id: {}", filter_id);
        it = mac_vlans.erase(it);
    }
}

status_code_t
EthLif::Reset()
{
    uint64_t addr;

    NIC_LOG_DEBUG("{}: LIF_RESET", hal_lif_info_.name);

    if (!IsLifInitialized()) {
        NIC_LOG_WARN("{}: {} + RESET => {}", hal_lif_info_.name, lif_state_to_str(state),
                     lif_state_to_str(state));
        return (IONIC_RC_SUCCESS);
    }

    DEVAPI_CHECK

    state = LIF_STATE_RESETTING;

    // Update name to the lif-id before doing a reset
    // to avoid name collisions during re-addition of the lifs
    // TODO: Lif delete has to be called here instead of just
    // doing an update
    dev_api->lif_upd_name(hal_lif_info_.lif_id, std::to_string(hal_lif_info_.lif_id));
    dev_api->lif_reset(hal_lif_info_.lif_id);
    FreeUpMacFilters();
    FreeUpVlanFilters();
    FreeUpMacVlanFilters();

    int ret;
    // Reset RSS configuration
    rss_type = LIF_RSS_TYPE_NONE;
    memset(rss_key, 0x00, RSS_HASH_KEY_SIZE);
    memset(rss_indir, 0x00, RSS_IND_TBL_SIZE);
    ret = pd->eth_program_rss(hal_lif_info_.lif_id, rss_type, rss_key, rss_indir, spec->rxq_count);
    if (ret != 0) {
        NIC_LOG_DEBUG("{}: Unable to program hw for RSS HASH", ret);
        return (IONIC_RC_ERROR);
    }

    // Clear PC to drop all traffic
    for (uint32_t qid = 0; qid < spec->rxq_count; qid++) {
        addr = pd->lm_->get_lif_qstate_addr(hal_lif_info_.lif_id, ETH_HW_QTYPE_RX, qid);
        if (addr < 0) {
            NIC_LOG_ERR("{}: Failed to get qstate address for RX qid {}", hal_lif_info_.name, qid);
            return (IONIC_RC_ERROR);
        }
        MEM_SET(addr, 0, fldsiz(eth_rx_qstate_t, q.intr.pc_offset), 0);
        PAL_barrier();
        sdk::asic::pd::asicpd_p4plus_invalidate_cache(addr, sizeof(eth_rx_qstate_t), P4PLUS_CACHE_INVALIDATE_BOTH);
    }

    for (uint32_t qid = 0; qid < spec->txq_count; qid++) {
        addr = pd->lm_->get_lif_qstate_addr(hal_lif_info_.lif_id, ETH_HW_QTYPE_TX, qid);
        if (addr < 0) {
            NIC_LOG_ERR("{}: Failed to get qstate address for TX qid {}", hal_lif_info_.name, qid);
            return (IONIC_RC_ERROR);
        }
        MEM_SET(addr, 0, fldsiz(eth_tx_qstate_t, q.intr.pc_offset), 0);
        PAL_barrier();
        sdk::asic::pd::asicpd_p4plus_invalidate_cache(addr, sizeof(eth_tx_qstate_t), P4PLUS_CACHE_INVALIDATE_TXDMA);
    }

    active_q_ref_cnt = 0;

    for (uint32_t qid = 0; qid < spec->adminq_count; qid++) {
        addr = pd->lm_->get_lif_qstate_addr(hal_lif_info_.lif_id, ETH_HW_QTYPE_ADMIN, qid);
        if (addr < 0) {
            NIC_LOG_ERR("{}: Failed to get qstate address for ADMIN qid {}", hal_lif_info_.name,
                        qid);
            return (IONIC_RC_ERROR);
        }
        MEM_SET(addr, 0, fldsiz(admin_qstate_t, pc_offset), 0);
        PAL_barrier();
        sdk::asic::pd::asicpd_p4plus_invalidate_cache(addr, sizeof(admin_qstate_t), P4PLUS_CACHE_INVALIDATE_TXDMA);
    }

    // Reset EDMA service
    edmaq->Reset();
    edmaq_async->Reset();

    // Reset NotifyQ service
    notify_enabled = 0;

    // Reset ADMINQ service
    adminq->Reset();

    // Disable Stats
    if (host_lif_stats_addr != 0) {
        host_lif_stats_addr = 0;
        ev_timer_stop(EV_A_ & stats_timer);
    }

    if (spec->enable_rdma) {
        ev_timer_stop(EV_A_ & sched_eval_timer);
    }

    state = LIF_STATE_RESET;

    return (IONIC_RC_SUCCESS);
}

bool
EthLif::IsLifQuiesced()
{
    if (!active_q_ref_cnt) {
        NIC_LOG_DEBUG("{}: Lif is quiesced!", spec->name);
        return true;
    }

    NIC_LOG_DEBUG("{}: Lif is not quiesced yet! active_q_cnt: {}",
            spec->name, active_q_ref_cnt);
    return false;
}


bool
EthLif::EdmaProxy(edma_opcode opcode, uint64_t from, uint64_t to, uint16_t size,
                  struct edmaq_ctx *ctx)
{
    return edmaq->Post(opcode, from, to, size, ctx);
}

bool
EthLif::EdmaAsyncProxy(edma_opcode opcode, uint64_t from, uint64_t to, uint16_t size,
                       struct edmaq_ctx *ctx)
{
    return edmaq_async->Post(opcode, from, to, size, ctx);
}

void
EthLif::AdminCmdHandler(void *obj, void *req, void *req_data, void *resp, void *resp_data)
{
    EthLif *lif = (EthLif *)obj;
    union ionic_dev_cmd *cmd = (union ionic_dev_cmd *)req;

    if (cmd->cmd.lif_index == lif->res->lif_index) {
        lif->CmdHandler(req, req_data, resp, resp_data);
    } else {
        NIC_LOG_DEBUG("{}: Proxying cmd {} with lif_index {}", lif->hal_lif_info_.name,
                      opcode_to_str((cmd_opcode_t)cmd->cmd.opcode), cmd->cmd.lif_index);
        lif->dev->CmdProxyHandler(req, req_data, resp, resp_data);
    }
}

status_code_t
EthLif::CmdHandler(void *req, void *req_data, void *resp, void *resp_data)
{
    union ionic_dev_cmd *cmd = (union ionic_dev_cmd *)req;
    union ionic_dev_cmd_comp *comp = (union ionic_dev_cmd_comp *)resp;
    status_code_t status = IONIC_RC_SUCCESS;

    if (cmd->cmd.lif_index != res->lif_index) {
        NIC_LOG_ERR("{}: Incorrect LIF with index {} for command with lif_index {}",
                    hal_lif_info_.name, res->lif_index, cmd->cmd.lif_index);
        status = IONIC_RC_EINVAL;
        goto out;
    }

    if ((cmd_opcode_t)cmd->cmd.opcode != IONIC_CMD_NOP) {
        NIC_LOG_DEBUG("{}: Handling cmd: {}", hal_lif_info_.name,
                      opcode_to_str((cmd_opcode_t)cmd->cmd.opcode));
    }

    switch ((cmd_opcode_t)cmd->cmd.opcode) {

    case IONIC_CMD_NOP:
        status = IONIC_RC_SUCCESS;
        break;

    case IONIC_CMD_LIF_GETATTR:
        status = _CmdGetAttr(req, req_data, resp, resp_data);
        break;

    case IONIC_CMD_LIF_SETATTR:
        status = _CmdSetAttr(req, req_data, resp, resp_data);
        break;

    case IONIC_CMD_RX_MODE_SET:
        status = _CmdRxSetMode(req, req_data, resp, resp_data);
        break;

    case IONIC_CMD_RX_FILTER_ADD:
        status = _CmdRxFilterAdd(req, req_data, resp, resp_data);
        break;

    case IONIC_CMD_RX_FILTER_DEL:
        status = _CmdRxFilterDel(req, req_data, resp, resp_data);
        break;

    case IONIC_CMD_Q_IDENTIFY:
        status = _CmdQIdentify(req, req_data, resp, resp_data);
        break;

    case IONIC_CMD_Q_INIT:
        status = _CmdQInit(req, req_data, resp, resp_data);
        break;

    case IONIC_CMD_Q_CONTROL:
        status = _CmdQControl(req, req_data, resp, resp_data);
        break;

    case IONIC_CMD_RDMA_RESET_LIF:
        status = _CmdRDMAResetLIF(req, req_data, resp, resp_data);
        break;

    case IONIC_CMD_RDMA_CREATE_EQ:
        status = _CmdRDMACreateEQ(req, req_data, resp, resp_data);
        break;

    case IONIC_CMD_RDMA_CREATE_CQ:
        status = _CmdRDMACreateCQ(req, req_data, resp, resp_data);
        break;

    case IONIC_CMD_RDMA_CREATE_ADMINQ:
        status = _CmdRDMACreateAdminQ(req, req_data, resp, resp_data);
        break;

    case IONIC_CMD_FW_DOWNLOAD:
        status = _CmdFwDownload(req, req_data, resp, resp_data);
        break;

    case IONIC_CMD_FW_CONTROL:
        status = _CmdFwControl(req, req_data, resp, resp_data);
        break;

    default:
        NIC_LOG_ERR("{}: Unknown Opcode {}", hal_lif_info_.name, cmd->cmd.opcode);
        status = IONIC_RC_EOPCODE;
        break;
    }

out:
    comp->comp.status = status;
    comp->comp.rsvd = 0xff;

    if ((cmd_opcode_t)cmd->cmd.opcode != IONIC_CMD_NOP) {
        NIC_LOG_DEBUG("{}: Done cmd: {}, status: {}", hal_lif_info_.name,
                      opcode_to_str((cmd_opcode_t)cmd->cmd.opcode), status);
    }

    return (status);
}

status_code_t
EthLif::CmdProxyHandler(void *req, void *req_data, void *resp, void *resp_data)
{
    // Allow all commands to be proxied for now
    return CmdHandler(req, req_data, resp, resp_data);
}

status_code_t
EthLif::_CmdFwDownload(void *req, void *req_data, void *resp, void *resp_data)
{
    struct ionic_fw_download_cmd *cmd = (struct ionic_fw_download_cmd *)req;
    FILE *file;
    int err;
    status_code_t status = IONIC_RC_SUCCESS;
    uint32_t transfer_off = 0, transfer_sz = 0, buf_off = 0, write_off = 0;
    bool posted = false;
    struct edmaq_ctx ctx = {0};

    if (!DeviceManager::GetInstance()->IsHostManaged()) {
        NIC_LOG_ERR("{}: Firmware download not allowed, not host managed!", hal_lif_info_.name);
        return (IONIC_RC_EPERM);
    }
    if (spec->vf_dev) {
        NIC_LOG_ERR("{}: Firmware download not allowed on VF interface!", hal_lif_info_.name);
        return (IONIC_RC_EPERM);
    }

    NIC_LOG_INFO("{}: {} addr {:#x} offset {:#x} length {}", hal_lif_info_.name,
                 opcode_to_str((cmd_opcode_t)cmd->opcode), cmd->addr, cmd->offset, cmd->length);

    if (cmd->addr == 0) {
        NIC_LOG_ERR("{}: Invalid chunk address {:#x}!", hal_lif_info_.name, cmd->addr);
        return (IONIC_RC_EINVAL);
    }

    if (cmd->addr & ~BIT_MASK(52)) {
        NIC_LOG_ERR("{}: bad addr {:#x}", hal_lif_info_.name, cmd->addr);
        return (IONIC_RC_EINVAL);
    }

    if (cmd->offset + cmd->length > FW_MAX_SZ) {
        NIC_LOG_ERR("{}: Invalid chunk offset {} or length {}!", hal_lif_info_.name, cmd->offset,
                    cmd->length);
        return (IONIC_RC_EINVAL);
    }

    /* cleanup update partition before starting download */
    if (cmd->offset == 0) {
        system("rm -r /update/*");
    }

    file = fopen(FW_FILEPATH, "ab+");
    if (file == NULL) {
        NIC_LOG_ERR("{}: Failed to open firmware file", hal_lif_info_.name);
        status = IONIC_RC_EIO;
        goto err_out;
    }

    /* transfer from host buffer in chunks of max size allowed by edma */
    write_off = cmd->offset;
    while (transfer_off < cmd->length) {

        transfer_sz = min(cmd->length - transfer_off, EDMAQ_MAX_TRANSFER_SZ);

        /* if the local buffer does not have enough free space, then write it to file */
        if (buf_off + transfer_sz > fw_buf_size) {
            err = fseek(file, write_off, SEEK_SET);
            if (err) {
                NIC_LOG_ERR("{}: Failed to seek offset {}, {}", hal_lif_info_.name, write_off,
                            strerror(errno));
                status = IONIC_RC_EIO;
                goto err_out;
            }

            err = fwrite((const void *)fw_buf, sizeof(fw_buf[0]), buf_off, file);
            if (err != (int)buf_off) {
                NIC_LOG_ERR("{}: Failed to write chunk, {}", hal_lif_info_.name, strerror(errno));
                status = IONIC_RC_EIO;
                goto err_out;
            }

            write_off += buf_off;
            buf_off = 0;
        }

        /* try posting an edma request */
        posted =
            edmaq->Post(spec->host_dev ? EDMA_OPCODE_HOST_TO_LOCAL : EDMA_OPCODE_LOCAL_TO_LOCAL,
                        cmd->addr + transfer_off, fw_buf_addr + buf_off, transfer_sz, &ctx);

        if (posted) {
            // NIC_LOG_INFO("{}: Queued transfer offset {:#x} size {} src {:#x} dst {:#x}",
            //     hal_lif_info_.name, transfer_off, transfer_sz,
            //     cmd->addr + transfer_off, fw_buf_addr + transfer_off);
            transfer_off += transfer_sz;
            buf_off += transfer_sz;
        } else {
            NIC_LOG_INFO("{}: Waiting for transfers to complete ...", hal_lif_info_.name);
            usleep(1000);
        }
    }

    /* write the leftover data */
    if (buf_off > 0) {
        err = fseek(file, write_off, SEEK_SET);
        if (err) {
            NIC_LOG_ERR("{}: Failed to seek offset {}, {}", hal_lif_info_.name, write_off,
                        strerror(errno));
            status = IONIC_RC_EIO;
            goto err_out;
        }

        err = fwrite((const void *)fw_buf, sizeof(fw_buf[0]), buf_off, file);
        if (err != (int)buf_off) {
            NIC_LOG_ERR("{}: Failed to write chunk, {}", hal_lif_info_.name, strerror(errno));
            status = IONIC_RC_EIO;
            goto err_out;
        }
    }

err_out:
    fclose(file);

    return (status);
}

status_code_t
EthLif::_CmdFwControl(void *req, void *req_data, void *resp, void *resp_data)
{
    struct ionic_fw_control_cmd *cmd = (struct ionic_fw_control_cmd *)req;
    status_code_t status = IONIC_RC_SUCCESS;
    int err;
    char buf[512] = {0};

    if (!DeviceManager::GetInstance()->IsHostManaged()) {
        NIC_LOG_ERR("{}: Firmware control not allowed, not host managed!", hal_lif_info_.name);
        return (IONIC_RC_EPERM);
    }
    if (spec->vf_dev) {
        NIC_LOG_ERR("{}: Firmware control not allowed on VF interface!", hal_lif_info_.name);
        return (IONIC_RC_EPERM);
    }

    switch (cmd->oper) {

    case IONIC_FW_RESET:
        NIC_LOG_INFO("{}: IONIC_FW_RESET", hal_lif_info_.name);
        break;

    case IONIC_FW_INSTALL:
        NIC_LOG_INFO("{}: IONIC_FW_INSTALL starting", hal_lif_info_.name);
        snprintf(buf, sizeof(buf), "/nic/tools/fwupdate -p %s -i all", FW_FILEPATH);
        err = system(buf);
        if (err) {
            NIC_LOG_ERR("{}: Failed to install firmware", hal_lif_info_.name);
            status = IONIC_RC_ERROR;
        }
        // remove(FW_FILEPATH);
        NIC_LOG_INFO("{}: IONIC_FW_INSTALL done!", hal_lif_info_.name);
        break;

    case IONIC_FW_ACTIVATE:
        NIC_LOG_INFO("{}: IONIC_FW_ACTIVATE starting", hal_lif_info_.name);
        err = system("/nic/tools/fwupdate -s altfw");
        if (err) {
            NIC_LOG_ERR("{}: Failed to activate firmware", hal_lif_info_.name);
            status = IONIC_RC_ERROR;
        }
        NIC_LOG_INFO("{}: IONIC_FW_ACTIVATE done!", hal_lif_info_.name);
        break;

    default:
        NIC_LOG_ERR("{}: Unknown operation {}", hal_lif_info_.name, cmd->oper);
        status = IONIC_RC_EOPCODE;
        break;
    }

    return (status);
}

#if 0
status_code_t
EthLif::_CmdHangNotify(void *req, void *req_data, void *resp, void *resp_data)
{
    int64_t addr;
    eth_rx_qstate_t rx_qstate = {0};
    eth_tx_qstate_t tx_qstate = {0};
    admin_qstate_t aq_state;
    intr_state_t intr_st;

    NIC_LOG_DEBUG("{}: IONIC_CMD_HANG_NOTIFY", hal_lif_info_.name);

    if (!IsLifInitialized()) {
        NIC_LOG_ERR("{}: Lif is not initialized", hal_lif_info_.name);
        return (IONIC_RC_ERROR);
    }

    for (uint32_t qid = 0; qid < spec->rxq_count; qid++) {
        addr = pd->lm_->get_lif_qstate_addr(hal_lif_info_.lif_id, ETH_HW_QTYPE_RX, qid);
        if (addr < 0) {
            NIC_LOG_ERR("{}: Failed to get qstate address for RX qid {}",
                hal_lif_info_.name, qid);
            return (IONIC_RC_ERROR);
        }
        READ_MEM(addr, (uint8_t *)(&rx_qstate), sizeof(rx_qstate), 0);
        NIC_LOG_DEBUG("{}: rxq{}: p_index0 {:#x} c_index0 {:#x} comp {:#x} intr {}",
            hal_lif_info_.name, qid,
            rx_qstate.p_index0, rx_qstate.c_index0, rx_qstate.comp_index,
            rx_qstate.intr_assert_index);
    }

    for (uint32_t qid = 0; qid < spec->txq_count; qid++) {
        addr = pd->lm_->get_lif_qstate_addr(hal_lif_info_.lif_id, ETH_HW_QTYPE_TX, qid);
        if (addr < 0) {
            NIC_LOG_ERR("{}: Failed to get qstate address for TX qid {}",
                hal_lif_info_.name, qid);
            return (IONIC_RC_ERROR);
        }
        READ_MEM(addr, (uint8_t *)(&tx_qstate), sizeof(tx_qstate), 0);
        NIC_LOG_DEBUG("{}: txq{}: p_index0 {:#x} c_index0 {:#x} comp {:#x} intr {}",
            hal_lif_info_.name, qid,
            tx_qstate.p_index0, tx_qstate.c_index0, tx_qstate.comp_index,
            tx_qstate.intr_assert_index);
    }

    for (uint32_t qid = 0; qid < spec->adminq_count; qid++) {
        addr = pd->lm_->get_lif_qstate_addr(hal_lif_info_.lif_id, ETH_HW_QTYPE_ADMIN, qid);
        if (addr < 0) {
            NIC_LOG_ERR("{}: Failed to get qstate address for ADMIN qid {}",
                hal_lif_info_.name, qid);
            return (IONIC_RC_ERROR);
        }
        READ_MEM(addr, (uint8_t *)(&aq_state), sizeof(aq_state), 0);
        NIC_LOG_DEBUG("{}: adminq{}: p_index0 {:#x} c_index0 {:#x} comp {:#x} intr {}",
            hal_lif_info_.name, qid,
            aq_state.p_index0, aq_state.c_index0, aq_state.comp_index,
            aq_state.intr_assert_index);
    }

    for (uint32_t intr = 0; intr < spec->intr_count; intr++) {
        intr_state_get(res->intr_base + intr, &intr_st);
        NIC_LOG_DEBUG("{}: intr{}: fwcfg_lif {} fwcfg_function_mask {}"
            " drvcfg_mask {} drvcfg_int_credits {} drvcfg_mask_on_assert {}",
            hal_lif_info_.name, res->intr_base + intr,
            intr_st.fwcfg_lif, intr_st.fwcfg_function_mask,
            intr_st.drvcfg_mask, intr_st.drvcfg_int_credits,
            intr_st.drvcfg_mask_on_assert);
    }

    return (IONIC_RC_SUCCESS);
}
#endif

status_code_t
EthLif::_CmdQIdentify(void *req, void *req_data, void *resp, void *resp_data)
{
    status_code_t ret = IONIC_RC_ERROR;
    struct q_identify_cmd *cmd = (struct q_identify_cmd *)req;

    NIC_LOG_DEBUG("{}: {} lif_type {} qtype {} ver {}", spec->name, opcode_to_str(cmd->opcode),
                  cmd->lif_type, cmd->type, cmd->ver);

    switch (cmd->type) {
    case IONIC_QTYPE_ADMINQ:
        ret = AdminQIdentify(req, req_data, resp, resp_data);
        break;
    case IONIC_QTYPE_NOTIFYQ:
        ret = NotifyQIdentify(req, req_data, resp, resp_data);
        break;
    case IONIC_QTYPE_RXQ:
        ret = RxQIdentify(req, req_data, resp, resp_data);
        break;
    case IONIC_QTYPE_TXQ:
        ret = TxQIdentify(req, req_data, resp, resp_data);
        break;
    default:
        ret = IONIC_RC_EINVAL;
        NIC_LOG_ERR("{}: Invalid qtype {}", hal_lif_info_.name, cmd->type);
        break;
    }

    return ret;
}

status_code_t
EthLif::AdminQIdentify(void *req, void *req_data, void *resp, void *resp_data)
{
    union ionic_q_identity *ident = (union ionic_q_identity *)resp_data;
    // struct q_identify_cmd *cmd = (struct q_identify_cmd *)req;
    struct q_identify_comp *comp = (struct q_identify_comp *)resp;

    memset(ident, 0, sizeof(union ionic_q_identity));

    ident->version = 0;
    ident->supported = 1;
    ident->features = IONIC_QIDENT_F_CQ;
    ident->desc_sz = sizeof(struct ionic_admin_cmd);
    ident->comp_sz = sizeof(struct ionic_admin_comp);

    comp->ver = ident->version;

    return (IONIC_RC_SUCCESS);
}

status_code_t
EthLif::NotifyQIdentify(void *req, void *req_data, void *resp, void *resp_data)
{
    union ionic_q_identity *ident = (union ionic_q_identity *)resp_data;
    // struct q_identify_cmd *cmd = (struct q_identify_cmd *)req;
    struct q_identify_comp *comp = (struct q_identify_comp *)resp;

    memset(ident, 0, sizeof(union ionic_q_identity));

    ident->version = 0;
    ident->supported = 1;
    ident->features = 0;
    ident->desc_sz = sizeof(struct ionic_notifyq_event);

    comp->ver = ident->version;

    return (IONIC_RC_SUCCESS);
}

status_code_t
EthLif::RxQIdentify(void *req, void *req_data, void *resp, void *resp_data)
{
    union ionic_q_identity *ident = (union ionic_q_identity *)resp_data;
    struct q_identify_cmd *cmd = (struct q_identify_cmd *)req;
    struct q_identify_comp *comp = (struct q_identify_comp *)resp;

    memset(ident, 0, sizeof(union ionic_q_identity));

    ident->supported = 0x3;
    ident->features = IONIC_QIDENT_F_CQ | IONIC_QIDENT_F_SG;
    ident->desc_sz = sizeof(struct ionic_rxq_desc);
    ident->comp_sz = sizeof(struct ionic_rxq_comp);
    ident->sg_desc_sz = sizeof(struct ionic_rxq_sg_desc);
    ident->max_sg_elems = IONIC_RX_MAX_SG_ELEMS;
    ident->sg_desc_stride = IONIC_RX_MAX_SG_ELEMS;

    if (cmd->ver == 1) {
        ident->version = 1;
        ident->features |= IONIC_QIDENT_F_EQ;
    } else if (cmd->ver == 2) {
        ident->version = 2;
        ident->features |= (IONIC_QIDENT_F_EQ | IONIC_QIDENT_F_CMB);
    } else {
        ident->version = 0;
    }

    comp->ver = ident->version;

    return (IONIC_RC_SUCCESS);
}

status_code_t
EthLif::TxQIdentify(void *req, void *req_data, void *resp, void *resp_data)
{
    union ionic_q_identity *ident = (union ionic_q_identity *)resp_data;
    struct q_identify_cmd *cmd = (struct q_identify_cmd *)req;
    struct q_identify_comp *comp = (struct q_identify_comp *)resp;

    memset(ident, 0, sizeof(union ionic_q_identity));

    ident->supported = 0x7;
    ident->features = IONIC_QIDENT_F_CQ | IONIC_QIDENT_F_SG;
    ident->desc_sz = sizeof(struct ionic_txq_desc);
    ident->comp_sz = sizeof(struct ionic_txq_comp);

    if (cmd->ver == 1) {
        ident->version = 1;
        ident->sg_desc_sz = sizeof(struct ionic_txq_sg_desc_v1);
        ident->max_sg_elems = IONIC_TX_MAX_SG_ELEMS_V1;
        ident->sg_desc_stride = IONIC_TX_SG_DESC_STRIDE_V1;
    } else if (cmd->ver == 2) {
        ident->version = 2;
        ident->features |= IONIC_QIDENT_F_EQ;
        ident->sg_desc_sz = sizeof(struct ionic_txq_sg_desc_v1);
        ident->max_sg_elems = IONIC_TX_MAX_SG_ELEMS_V1;
        ident->sg_desc_stride = IONIC_TX_SG_DESC_STRIDE_V1;
    } else if (cmd->ver == 3) {
        ident->version = 3;
        ident->features |= (IONIC_QIDENT_F_EQ | IONIC_QIDENT_F_CMB);
        ident->sg_desc_sz = sizeof(struct ionic_txq_sg_desc_v1);
        ident->max_sg_elems = IONIC_TX_MAX_SG_ELEMS_V1;
        ident->sg_desc_stride = IONIC_TX_SG_DESC_STRIDE_V1;
    } else {
        ident->version = 0;
        ident->sg_desc_sz = sizeof(struct ionic_txq_sg_desc);
        ident->max_sg_elems = IONIC_TX_MAX_SG_ELEMS;
        ident->sg_desc_stride = IONIC_TX_SG_DESC_STRIDE;
    }

    comp->ver = ident->version;

    return (IONIC_RC_SUCCESS);
}

status_code_t
EthLif::_CmdQInit(void *req, void *req_data, void *resp, void *resp_data)
{
    status_code_t ret = IONIC_RC_ERROR;
    struct ionic_q_init_cmd *cmd = (struct ionic_q_init_cmd *)req;

    switch (cmd->type) {
    case IONIC_QTYPE_ADMINQ:
        ret = AdminQInit(req, req_data, resp, resp_data);
        break;
    case IONIC_QTYPE_NOTIFYQ:
        ret = NotifyQInit(req, req_data, resp, resp_data);
        break;
    case IONIC_QTYPE_RXQ:
        ret = RxQInit(req, req_data, resp, resp_data);
        break;
    case IONIC_QTYPE_TXQ:
        ret = TxQInit(req, req_data, resp, resp_data);
        break;
    case IONIC_QTYPE_EQ:
        ret = EQInit(req, req_data, resp, resp_data);
        break;
    default:
        ret = IONIC_RC_EINVAL;
        NIC_LOG_ERR("{}: Invalid qtype {} qid {}", hal_lif_info_.name, cmd->type, cmd->index);
        break;
    }

    return ret;
}

status_code_t
EthLif::EQInit(void *req, void *req_data, void *resp, void *resp_data)
{
    int64_t addr;
    struct ionic_q_init_cmd *cmd = (struct ionic_q_init_cmd *)req;
    struct ionic_q_init_comp *comp = (struct ionic_q_init_comp *)resp;
    eth_eq_qstate_t qstate = {0};

    NIC_LOG_DEBUG("{}: {}: "
                  "type {} index {} cos {} "
                  "ring_base {:#x} cq_ring_base {:#x} ring_size {} "
                  "intr_index {} flags {}{}",
                  hal_lif_info_.name, opcode_to_str((cmd_opcode_t)cmd->opcode), cmd->type,
                  cmd->index, cmd->cos, cmd->ring_base, cmd->cq_ring_base, cmd->ring_size,
                  cmd->intr_index, (cmd->flags & IONIC_QINIT_F_IRQ) ? 'I' : '-',
                  (cmd->flags & IONIC_QINIT_F_ENA) ? 'E' : '-');

    if (!IsLifInitialized()) {
        NIC_LOG_ERR("{}: Lif is not initialized", hal_lif_info_.name);
        return (IONIC_RC_ERROR);
    }

    if (cmd->index >= spec->eq_count) {
        NIC_LOG_ERR("{}: Bad EQ qid {}", hal_lif_info_.name, cmd->index);
        return (IONIC_RC_EQID);
    }

    if ((cmd->flags & IONIC_QINIT_F_IRQ) && (cmd->intr_index >= spec->intr_count)) {
        NIC_LOG_ERR("{}: bad intr {}", hal_lif_info_.name, cmd->intr_index);
        return (IONIC_RC_ERROR);
    }

    if (cmd->ring_size < 2 || cmd->ring_size > 16) {
        NIC_LOG_ERR("{}: bad ring_size {}", hal_lif_info_.name, cmd->ring_size);
        return (IONIC_RC_ERROR);
    }

    if (cmd->ring_base == 0 || cmd->ring_base & ~BIT_MASK(52)) {
        NIC_LOG_ERR("{}: bad RX EQ ring base {:#x}", hal_lif_info_.name, cmd->ring_base);
        return (IONIC_RC_EINVAL);
    }

    if (cmd->cq_ring_base == 0 || cmd->cq_ring_base & ~BIT_MASK(52)) {
        NIC_LOG_ERR("{}: bad TX EQ ring base {:#x}", hal_lif_info_.name, cmd->cq_ring_base);
        return (IONIC_RC_EINVAL);
    }

    /* common values for rx and tx eq */
    qstate.eq_ring_size = cmd->ring_size;
    qstate.eq_gen = 1;
    if (cmd->flags & IONIC_QINIT_F_ENA) {
        qstate.cfg.eq_enable = 1;
    }
    if (cmd->flags & IONIC_QINIT_F_IRQ) {
        qstate.cfg.intr_enable = 1;
        qstate.intr_index = res->intr_base + cmd->intr_index;
    }

    /* init rx eq */
    if (spec->host_dev) {
        qstate.eq_ring_base = HOST_ADDR(hal_lif_info_.lif_id, cmd->ring_base);
    } else {
        qstate.eq_ring_base = cmd->ring_base;
    }
    addr = res->rx_eq_base + cmd->index * sizeof(qstate);
    WRITE_MEM(addr, (uint8_t *)&qstate, sizeof(qstate), 0);
    PAL_barrier();
    sdk::asic::pd::asicpd_p4plus_invalidate_cache(addr, sizeof(qstate), P4PLUS_CACHE_INVALIDATE_RXDMA);

    /* init tx eq */
    if (spec->host_dev) {
        qstate.eq_ring_base = HOST_ADDR(hal_lif_info_.lif_id, cmd->cq_ring_base);
    } else {
        qstate.eq_ring_base = cmd->ring_base;
    }
    addr = res->tx_eq_base + cmd->index * sizeof(qstate);
    WRITE_MEM(addr, (uint8_t *)&qstate, sizeof(qstate), 0);
    PAL_barrier();
    sdk::asic::pd::asicpd_p4plus_invalidate_cache(addr, sizeof(qstate), P4PLUS_CACHE_INVALIDATE_TXDMA);

    comp->hw_index = cmd->index;
    comp->hw_type = ETH_HW_QTYPE_NONE;

    NIC_LOG_DEBUG("{}: qid {} qtype {}", hal_lif_info_.name, comp->hw_index, comp->hw_type);
    return (IONIC_RC_SUCCESS);
}

status_code_t
EthLif::TxQInit(void *req, void *req_data, void *resp, void *resp_data)
{
    int64_t addr;
    struct ionic_q_init_cmd *cmd = (struct ionic_q_init_cmd *)req;
    struct ionic_q_init_comp *comp = (struct ionic_q_init_comp *)resp;
    eth_tx_co_qstate_t qstate = {0};

    NIC_LOG_DEBUG(
        "{}: {}: "
        "type {} ver {} index {} cos {} "
        "ring_base {:#x} cq_ring_base {:#x} sg_ring_base {:#x} ring_size {} "
        "intr_index {} flags {}{}{}{}{}{}",
        hal_lif_info_.name, opcode_to_str((cmd_opcode_t)cmd->opcode), cmd->type, cmd->ver,
        cmd->index, cmd->cos, cmd->ring_base, cmd->cq_ring_base, cmd->sg_ring_base, cmd->ring_size,
        cmd->intr_index, (cmd->flags & IONIC_QINIT_F_SG) ? 'S' : '-',
        (cmd->flags & IONIC_QINIT_F_IRQ) ? 'I' : '-', (cmd->flags & IONIC_QINIT_F_EQ) ? 'Q' : '-',
        (cmd->flags & IONIC_QINIT_F_DEBUG) ? 'D' : '-',
        (cmd->flags & IONIC_QINIT_F_CMB) ? 'C' : '-',
        (cmd->flags & IONIC_QINIT_F_ENA) ? 'E' : '-');

    if (!IsLifInitialized()) {
        NIC_LOG_ERR("{}: Lif is not initialized", hal_lif_info_.name);
        return (IONIC_RC_ERROR);
    }

    if (cmd->ver > 3) {
        NIC_LOG_ERR("{}: bad ver {}", hal_lif_info_.name, cmd->ver);
        return (IONIC_RC_ENOSUPP);
    }

    if (cmd->index >= spec->txq_count) {
        NIC_LOG_ERR("{}: bad qid {}", hal_lif_info_.name, cmd->index);
        return (IONIC_RC_EQID);
    }

    if ((cmd->ver < 2) && (cmd->flags & IONIC_QINIT_F_EQ)) {
        NIC_LOG_ERR("{}: bad ver {} invalid flag IONIC_QINIT_F_EQ", hal_lif_info_.name, cmd->ver);
        return (IONIC_RC_ENOSUPP);
    }

    if (cmd->flags & IONIC_QINIT_F_EQ) {
        if (cmd->flags & IONIC_QINIT_F_IRQ) {
            NIC_LOG_ERR("{}: bad combination of EQ and IRQ flags");
            return (IONIC_RC_EQID);
        }
        if (cmd->intr_index >= spec->eq_count) {
            NIC_LOG_ERR("{}: bad EQ qid {}", hal_lif_info_.name, cmd->intr_index);
            return (IONIC_RC_EQID);
        }
        if (cmd->ring_size > 15) {
            NIC_LOG_ERR("{}: bad ring size {} for TX eq", hal_lif_info_.name, cmd->ring_size);
            return (IONIC_RC_EINVAL);
        }
    } else if (cmd->flags & IONIC_QINIT_F_IRQ) {
        if (cmd->intr_index >= spec->intr_count) {
            NIC_LOG_ERR("{}: bad intr {}", hal_lif_info_.name, cmd->intr_index);
            return (IONIC_RC_ERROR);
        }
    }

    if (cmd->ring_size < 2 || cmd->ring_size > 16) {
        NIC_LOG_ERR("{}: bad ring_size {}", hal_lif_info_.name, cmd->ring_size);
        return (IONIC_RC_ERROR);
    }

    if ((cmd->ver < 2) && (cmd->flags & IONIC_QINIT_F_CMB)) {
        NIC_LOG_ERR("{}: bad ver {} invalid flag IONIC_QINIT_F_CMB", hal_lif_info_.name, cmd->ver);
        return (IONIC_RC_ENOSUPP);
    }

    if ((cmd->ver > 1) && (cmd->flags & IONIC_QINIT_F_CMB)) {
        if ((cmd->ring_base + (1 << cmd->ring_size)) > res->cmb_mem_size) {
            NIC_LOG_ERR("{}: bad ring base {:#x} size {}", hal_lif_info_.name, cmd->ring_base,
                        cmd->ring_size);
            return (IONIC_RC_EINVAL);
        }
    } else {
        if (cmd->ring_base == 0 || cmd->ring_base & ~BIT_MASK(52)) {
            NIC_LOG_ERR("{}: bad ring base {:#x}", hal_lif_info_.name, cmd->ring_base);
            return (IONIC_RC_EINVAL);
        }
    }

    if (cmd->cq_ring_base == 0 || cmd->cq_ring_base & ~BIT_MASK(52)) {
        NIC_LOG_ERR("{}: bad cq ring base {:#x}", hal_lif_info_.name, cmd->cq_ring_base);
        return (IONIC_RC_EINVAL);
    }

    if ((cmd->flags & IONIC_QINIT_F_SG) &&
        (cmd->sg_ring_base == 0 || cmd->sg_ring_base & ~BIT_MASK(52))) {
        NIC_LOG_ERR("{}: bad sg ring base {:#x}", hal_lif_info_.name, cmd->sg_ring_base);
        return (IONIC_RC_EINVAL);
    }

    addr = pd->lm_->get_lif_qstate_addr(hal_lif_info_.lif_id, ETH_HW_QTYPE_TX, cmd->index);
    if (addr < 0) {
        NIC_LOG_ERR("{}: Failed to get qstate address for TX qid {}", hal_lif_info_.name,
                    cmd->index);
        return (IONIC_RC_ERROR);
    }

    uint8_t off;
    if (pd->get_pc_offset("txdma_stage0.bin", "eth_tx_stage0", &off, NULL) < 0) {
        NIC_LOG_ERR("Failed to get PC offset of program: txdma_stage0.bin label: eth_tx_stage0");
        return (IONIC_RC_ERROR);
    }

    qstate.tx.q.intr.pc_offset = off;
    qstate.tx.q.intr.cosA = cosA;
    if (spec->eth_type == ETH_HOST_MGMT ||
        spec->eth_type == ETH_MNIC_OOB_MGMT ||
        spec->eth_type == ETH_MNIC_INTERNAL_MGMT ||
        spec->eth_type == ETH_MNIC_INBAND_MGMT) {
        qstate.tx.q.intr.cosB = cosB;
    } else {
        qstate.tx.q.intr.cosB = pd->get_iq(cmd->cos, hal_lif_info_.pinned_uplink_port_num);
    }
    qstate.tx.q.intr.host = (cmd->flags & IONIC_QINIT_F_EQ) ? 2 : 1;
    qstate.tx.q.intr.total = 3;
    qstate.tx.q.intr.pid = cmd->pid;

    qstate.tx.q.ring[1].p_index = 0xffff;
    qstate.tx.q.ring[1].c_index = 0xffff;

    qstate.tx.q.cfg.enable = (cmd->flags & IONIC_QINIT_F_ENA) ? 1 : 0;
    qstate.tx.q.cfg.debug = (cmd->flags & IONIC_QINIT_F_DEBUG) ? 1 : 0;
    qstate.tx.q.cfg.cpu_queue = IsLifTypeCpu();

    qstate.tx.q.ring_size = cmd->ring_size;
    qstate.tx.q.lif_index = cmd->lif_index;

    qstate.tx.sta.color = 1;

    qstate.tx.lg2_desc_sz = log2(sizeof(struct ionic_txq_desc));
    qstate.tx.lg2_cq_desc_sz = log2(sizeof(struct ionic_txq_comp));
    if (cmd->ver == 0) {
        qstate.tx.lg2_sg_desc_sz = log2(sizeof(struct ionic_txq_sg_desc));
    } else {
        qstate.tx.lg2_sg_desc_sz = log2(sizeof(struct ionic_txq_sg_desc_v1));
    }

    if (spec->host_dev) {
        qstate.tx.q.cfg.host_queue = 1;
        if (cmd->flags & IONIC_QINIT_F_CMB)
            qstate.tx.ring_base = res->cmb_mem_addr + cmd->ring_base;
        else
            qstate.tx.ring_base = HOST_ADDR(hal_lif_info_.lif_id, cmd->ring_base);
        qstate.tx.cq_ring_base = HOST_ADDR(hal_lif_info_.lif_id, cmd->cq_ring_base);
        if (cmd->flags & IONIC_QINIT_F_SG) {
            qstate.tx.sg_ring_base = HOST_ADDR(hal_lif_info_.lif_id, cmd->sg_ring_base);
        }
    } else {
        qstate.tx.ring_base = cmd->ring_base;
        qstate.tx.cq_ring_base = cmd->cq_ring_base;
        if (cmd->flags & IONIC_QINIT_F_SG) {
            qstate.tx.sg_ring_base = cmd->sg_ring_base;
        }
    }

    if (cmd->flags & IONIC_QINIT_F_EQ) {
        qstate.tx.q.cfg.eq_enable = 1;
        qstate.tx.intr_index_or_eq_addr =
            res->tx_eq_base + cmd->intr_index * sizeof(eth_eq_qstate_t);
    } else if (cmd->flags & IONIC_QINIT_F_IRQ) {
        qstate.tx.q.cfg.intr_enable = 1;
        qstate.tx.intr_index_or_eq_addr = res->intr_base + cmd->intr_index;
    }

    WRITE_MEM(addr, (uint8_t *)&qstate, sizeof(qstate), 0);

    PAL_barrier();
    sdk::asic::pd::asicpd_p4plus_invalidate_cache(addr, sizeof(qstate), P4PLUS_CACHE_INVALIDATE_TXDMA);

    comp->hw_index = cmd->index;
    comp->hw_type = ETH_HW_QTYPE_TX;

    NIC_LOG_DEBUG("{}: qid {} qtype {}", hal_lif_info_.name, comp->hw_index, comp->hw_type);
    return (IONIC_RC_SUCCESS);
}

status_code_t
EthLif::RxQInit(void *req, void *req_data, void *resp, void *resp_data)
{
    int64_t addr;
    struct ionic_q_init_cmd *cmd = (struct ionic_q_init_cmd *)req;
    struct ionic_q_init_comp *comp = (struct ionic_q_init_comp *)resp;
    eth_rx_qstate_t qstate = {0};

    NIC_LOG_DEBUG(
        "{}: {}: "
        "type {} ver {} index {} cos {} "
        "ring_base {:#x} cq_ring_base {:#x} sg_ring_base {:#x} ring_size {}"
        " intr_index {} flags {}{}{}{}{}{}",
        hal_lif_info_.name, opcode_to_str((cmd_opcode_t)cmd->opcode), cmd->type, cmd->ver,
        cmd->index, cmd->cos, cmd->ring_base, cmd->cq_ring_base, cmd->sg_ring_base, cmd->ring_size,
        cmd->intr_index, (cmd->flags & IONIC_QINIT_F_SG) ? 'S' : '-',
        (cmd->flags & IONIC_QINIT_F_IRQ) ? 'I' : '-', (cmd->flags & IONIC_QINIT_F_EQ) ? 'Q' : '-',
        (cmd->flags & IONIC_QINIT_F_DEBUG) ? 'D' : '-',
        (cmd->flags & IONIC_QINIT_F_CMB) ? 'C' : '-',
        (cmd->flags & IONIC_QINIT_F_ENA) ? 'E' : '-');

    if (!IsLifInitialized()) {
        NIC_LOG_ERR("{}: Lif is not initialized", hal_lif_info_.name);
        return (IONIC_RC_ERROR);
    }

    if (cmd->ver > 2) {
        NIC_LOG_ERR("{}: bad ver {}", hal_lif_info_.name, cmd->ver);
        return (IONIC_RC_ENOSUPP);
    }

    if (cmd->index >= spec->rxq_count) {
        NIC_LOG_ERR("{}: bad qid {}", hal_lif_info_.name, cmd->index);
        return (IONIC_RC_EQID);
    }

    if ((cmd->ver < 1) && (cmd->flags & IONIC_QINIT_F_EQ)) {
        NIC_LOG_ERR("{}: bad ver {} invalid flag IONIC_QINIT_F_EQ", hal_lif_info_.name, cmd->ver);
        return (IONIC_RC_ENOSUPP);
    }

    if (cmd->flags & IONIC_QINIT_F_EQ) {
        if (cmd->flags & IONIC_QINIT_F_IRQ) {
            NIC_LOG_ERR("{}: bad combination of EQ and IRQ flags");
            return (IONIC_RC_EQID);
        }
        if (cmd->intr_index >= spec->eq_count) {
            NIC_LOG_ERR("{}: bad EQ qid {}", hal_lif_info_.name, cmd->intr_index);
            return (IONIC_RC_EQID);
        }
        if (cmd->ring_size > 15) {
            NIC_LOG_ERR("{}: bad ring size {} for RX eq", hal_lif_info_.name, cmd->ring_size);
            return (IONIC_RC_EINVAL);
        }
    } else if (cmd->flags & IONIC_QINIT_F_IRQ) {
        if (cmd->intr_index >= spec->intr_count) {
            NIC_LOG_ERR("{}: bad intr {}", hal_lif_info_.name, cmd->intr_index);
            return (IONIC_RC_ERROR);
        }
    }

    if (cmd->ring_size < 2 || cmd->ring_size > 16) {
        NIC_LOG_ERR("{}: bad ring_size {}", hal_lif_info_.name, cmd->ring_size);
        return (IONIC_RC_ERROR);
    }

    if ((cmd->ver < 2) && (cmd->flags & IONIC_QINIT_F_CMB)) {
        NIC_LOG_ERR("{}: bad ver {} invalid flag IONIC_QINIT_F_CMB", hal_lif_info_.name, cmd->ver);
        return (IONIC_RC_ENOSUPP);
    }

    if ((cmd->ver > 1) && (cmd->flags & IONIC_QINIT_F_CMB)) {
        if ((cmd->ring_base + (1 << cmd->ring_size)) > res->cmb_mem_size) {
            NIC_LOG_ERR("{}: bad ring base {:#x} size {}", hal_lif_info_.name, cmd->ring_base,
                        cmd->ring_size);
            return (IONIC_RC_EINVAL);
        }
    } else {
        if (cmd->ring_base == 0 || cmd->ring_base & ~BIT_MASK(52)) {
            NIC_LOG_ERR("{}: bad ring base {:#x}", hal_lif_info_.name, cmd->ring_base);
            return (IONIC_RC_EINVAL);
        }
    }

    if ((cmd->flags & IONIC_QINIT_F_SG) &&
        (cmd->sg_ring_base == 0 || cmd->sg_ring_base & ~BIT_MASK(52))) {
        NIC_LOG_ERR("{}: bad sg ring base {:#x}", hal_lif_info_.name, cmd->sg_ring_base);
        return (IONIC_RC_EINVAL);
    }

    addr = pd->lm_->get_lif_qstate_addr(hal_lif_info_.lif_id, ETH_HW_QTYPE_RX, cmd->index);
    if (addr < 0) {
        NIC_LOG_ERR("{}: Failed to get qstate address for RX qid {}", hal_lif_info_.name,
                    cmd->index);
        return (IONIC_RC_ERROR);
    }

    uint8_t off;
    if (pd->get_pc_offset("rxdma_stage0.bin", "eth_rx_stage0", &off, NULL) < 0) {
        NIC_LOG_ERR("Failed to get PC offset of program: rxdma_stage0.bin label: eth_rx_stage0");
        return (IONIC_RC_ERROR);
    }

    qstate.q.intr.pc_offset = off;
    qstate.q.intr.cosA = cosA;
    qstate.q.intr.cosB = pd->get_iq(cmd->cos, hal_lif_info_.pinned_uplink_port_num);
    qstate.q.intr.host = (cmd->flags & IONIC_QINIT_F_EQ) ? 2 : 1;
    qstate.q.intr.total = 3;
    qstate.q.intr.pid = cmd->pid;

    qstate.q.ring[1].p_index = 0xffff;
    qstate.q.ring[1].c_index = 0xffff;

    qstate.q.cfg.enable = (cmd->flags & IONIC_QINIT_F_ENA) ? 1 : 0;
    qstate.q.cfg.debug = (cmd->flags & IONIC_QINIT_F_DEBUG) ? 1 : 0;
    qstate.q.cfg.cpu_queue = IsLifTypeCpu();

    qstate.q.ring_size = cmd->ring_size;
    qstate.q.lif_index = cmd->lif_index;

    qstate.sta.color = 1;

    if (features & (
        IONIC_ETH_HW_RX_CSUM_GENEVE
        | IONIC_ETH_HW_TX_CSUM_GENEVE
        | IONIC_ETH_HW_TSO_GENEVE))
    {
        qstate.features.encap_offload = 1;
    }

    if (spec->host_dev) {
        qstate.q.cfg.host_queue = 1;
        if (cmd->flags & IONIC_QINIT_F_CMB)
            qstate.ring_base = res->cmb_mem_addr + cmd->ring_base;
        else
            qstate.ring_base = HOST_ADDR(hal_lif_info_.lif_id, cmd->ring_base);
        qstate.cq_ring_base = HOST_ADDR(hal_lif_info_.lif_id, cmd->cq_ring_base);
        if (cmd->flags & IONIC_QINIT_F_SG)
            qstate.sg_ring_base = HOST_ADDR(hal_lif_info_.lif_id, cmd->sg_ring_base);
    } else {
        qstate.ring_base = cmd->ring_base;
        qstate.cq_ring_base = cmd->cq_ring_base;
        if (cmd->flags & IONIC_QINIT_F_SG)
            qstate.sg_ring_base = cmd->sg_ring_base;
    }

    if (cmd->flags & IONIC_QINIT_F_EQ) {
        qstate.q.cfg.eq_enable = 1;
        qstate.intr_index_or_eq_addr = res->rx_eq_base + cmd->intr_index * sizeof(eth_eq_qstate_t);
    } else if (cmd->flags & IONIC_QINIT_F_IRQ) {
        qstate.q.cfg.intr_enable = 1;
        qstate.intr_index_or_eq_addr = res->intr_base + cmd->intr_index;
    }

    qstate.lg2_desc_sz = log2(sizeof(struct ionic_rxq_desc));
    qstate.lg2_cq_desc_sz = log2(sizeof(struct ionic_rxq_comp));
    qstate.lg2_sg_desc_sz = log2(sizeof(struct ionic_rxq_sg_desc));
    qstate.sg_max_elems = IONIC_RX_MAX_SG_ELEMS;

    WRITE_MEM(addr, (uint8_t *)&qstate, sizeof(qstate), 0);

    PAL_barrier();
    sdk::asic::pd::asicpd_p4plus_invalidate_cache(addr, sizeof(qstate), P4PLUS_CACHE_INVALIDATE_BOTH);

    comp->hw_index = cmd->index;
    comp->hw_type = ETH_HW_QTYPE_RX;

    NIC_LOG_DEBUG("{}: qid {} qtype {}", hal_lif_info_.name, comp->hw_index, comp->hw_type);
    return (IONIC_RC_SUCCESS);
}

status_code_t
EthLif::NotifyQInit(void *req, void *req_data, void *resp, void *resp_data)
{
    int64_t addr;
    struct ionic_q_init_cmd *cmd = (struct ionic_q_init_cmd *)req;
    struct ionic_q_init_comp *comp = (struct ionic_q_init_comp *)resp;

    NIC_LOG_INFO("{}: {}: "
                 "type {} ver {} index {} ring_base {:#x} ring_size {} intr_index {} "
                 "flags {}{}{}",
                 hal_lif_info_.name, opcode_to_str((cmd_opcode_t)cmd->opcode), cmd->type, cmd->ver,
                 cmd->index, cmd->ring_base, cmd->ring_size, cmd->intr_index,
                 (cmd->flags & IONIC_QINIT_F_IRQ) ? 'I' : '-',
                 (cmd->flags & IONIC_QINIT_F_DEBUG) ? 'D' : '-',
                 (cmd->flags & IONIC_QINIT_F_ENA) ? 'E' : '-');

    if (!IsLifInitialized()) {
        NIC_LOG_ERR("{}: Lif is not initialized", hal_lif_info_.name);
        return (IONIC_RC_ERROR);
    }

    if (cmd->ver != 0) {
        NIC_LOG_ERR("{}: bad ver {}", hal_lif_info_.name, cmd->ver);
        return (IONIC_RC_ENOSUPP);
    }

    if (cmd->index >= 1) {
        NIC_LOG_ERR("{}: bad qid {}", hal_lif_info_.name, cmd->index);
        return (IONIC_RC_EQID);
    }

    if ((cmd->flags & IONIC_QINIT_F_IRQ) && cmd->intr_index >= spec->intr_count) {
        NIC_LOG_ERR("{}: bad intr {}", hal_lif_info_.name, cmd->intr_index);
        return (IONIC_RC_ERROR);
    }

    if (cmd->ring_size < 2 || cmd->ring_size > 16) {
        NIC_LOG_ERR("{}: bad ring_size {}", hal_lif_info_.name, cmd->ring_size);
        return (IONIC_RC_ERROR);
    }

    if (cmd->ring_base == 0 || cmd->ring_base & ~BIT_MASK(52)) {
        NIC_LOG_ERR("{}: bad ring base {:#x}", hal_lif_info_.name, cmd->ring_base);
        return (IONIC_RC_EINVAL);
    }

    addr = pd->lm_->get_lif_qstate_addr(hal_lif_info_.lif_id, ETH_NOTIFYQ_QTYPE, cmd->index);
    if (addr < 0) {
        NIC_LOG_ERR("{}: Failed to get qstate address for NOTIFYQ qid {}", hal_lif_info_.name,
                    cmd->index);
        return (IONIC_RC_ERROR);
    }

    uint8_t off;
    uint64_t host_ring_base;
    notify_qstate_t qstate = {0};
    if (pd->get_pc_offset("txdma_stage0.bin", "notify_stage0", &off, NULL) < 0) {
        NIC_LOG_ERR("Failed to resolve program: txdma_stage0.bin label: notify_stage0");
        return (IONIC_RC_ERROR);
    }
    qstate.pc_offset = off;
    qstate.cos_sel = 0;
    qstate.cosA = admin_cosA;
    qstate.cosB = admin_cosB;
    qstate.host = 0;
    qstate.total = 1;
    qstate.pid = cmd->pid;
    qstate.p_index0 = 0;
    qstate.c_index0 = 0;
    qstate.host_pindex = 0;
    qstate.sta = {0};
    qstate.cfg.debug = (cmd->flags & IONIC_QINIT_F_DEBUG) ? 1 : 0;
    qstate.cfg.enable = (cmd->flags & IONIC_QINIT_F_ENA) ? 1 : 0;
    qstate.cfg.intr_enable = (cmd->flags & IONIC_QINIT_F_IRQ) ? 1 : 0;
    qstate.cfg.host_queue = spec->host_dev;
    qstate.ring_base = notify_ring_base;
    qstate.ring_size = LG2_ETH_NOTIFYQ_RING_SIZE;
    if (spec->host_dev)
        host_ring_base = HOST_ADDR(hal_lif_info_.lif_id, cmd->ring_base);
    else
        host_ring_base = cmd->ring_base;
    qstate.host_ring_base =
        roundup(host_ring_base + (sizeof(union ionic_notifyq_comp) << cmd->ring_size), 4096);
    qstate.host_ring_size = cmd->ring_size;
    if (cmd->flags & IONIC_QINIT_F_IRQ)
        qstate.host_intr_assert_index = res->intr_base + cmd->intr_index;

    WRITE_MEM(addr, (uint8_t *)&qstate, sizeof(qstate), 0);

    PAL_barrier();
    sdk::asic::pd::asicpd_p4plus_invalidate_cache(addr, sizeof(qstate), P4PLUS_CACHE_INVALIDATE_TXDMA);

    comp->hw_index = cmd->index;
    comp->hw_type = ETH_HW_QTYPE_SVC;

    NIC_LOG_INFO("{}: qid {} qtype {}", hal_lif_info_.name, comp->hw_index, comp->hw_type);

    // Enable notifications
    notify_enabled = 1;

    return (IONIC_RC_SUCCESS);
}

status_code_t
EthLif::AdminQInit(void *req, void *req_data, void *resp, void *resp_data)
{
    int64_t addr, nicmgr_qstate_addr;
    struct ionic_q_init_cmd *cmd = (struct ionic_q_init_cmd *)req;
    struct ionic_q_init_comp *comp = (struct ionic_q_init_comp *)resp;

    NIC_LOG_DEBUG("{}: {}: "
                  "type {} ver {} index {} ring_base {:#x} ring_size {} intr_index {} "
                  "flags {}{}{}",
                  hal_lif_info_.name, opcode_to_str((cmd_opcode_t)cmd->opcode), cmd->type,
                  cmd->ver, cmd->index, cmd->ring_base, cmd->ring_size, cmd->intr_index,
                  (cmd->flags & IONIC_QINIT_F_IRQ) ? 'I' : '-',
                  (cmd->flags & IONIC_QINIT_F_DEBUG) ? 'D' : '-',
                  (cmd->flags & IONIC_QINIT_F_ENA) ? 'E' : '-');

    if (!IsLifInitialized()) {
        NIC_LOG_ERR("{}: Lif is not initialized", hal_lif_info_.name);
        return (IONIC_RC_ERROR);
    }

    if (cmd->ver != 0) {
        NIC_LOG_ERR("{}: bad ver {}", hal_lif_info_.name, cmd->ver);
        return (IONIC_RC_ENOSUPP);
    }

    if (cmd->index >= spec->adminq_count) {
        NIC_LOG_ERR("{}: bad qid {}", hal_lif_info_.name, cmd->index);
        return (IONIC_RC_EQID);
    }

    if ((cmd->flags & IONIC_QINIT_F_IRQ) && cmd->intr_index >= spec->intr_count) {
        NIC_LOG_ERR("{}: bad intr {}", hal_lif_info_.name, cmd->intr_index);
        return (IONIC_RC_ERROR);
    }

    if (cmd->ring_size < 2 || cmd->ring_size > 16) {
        NIC_LOG_ERR("{}: bad ring size {}", hal_lif_info_.name, cmd->ring_size);
        return (IONIC_RC_ERROR);
    }

    if (cmd->ring_base == 0 || cmd->ring_base & ~BIT_MASK(52)) {
        NIC_LOG_ERR("{}: bad ring base {:#x}", hal_lif_info_.name, cmd->ring_base);
        return (IONIC_RC_EINVAL);
    }

    if (cmd->cq_ring_base == 0 || cmd->cq_ring_base & ~BIT_MASK(52)) {
        NIC_LOG_ERR("{}: bad cq ring base {:#x}", hal_lif_info_.name, cmd->cq_ring_base);
        return (IONIC_RC_EINVAL);
    }

    addr = pd->lm_->get_lif_qstate_addr(hal_lif_info_.lif_id, ETH_HW_QTYPE_ADMIN, cmd->index);
    if (addr < 0) {
        NIC_LOG_ERR("{}: Failed to get qstate address for ADMIN qid {}", hal_lif_info_.name,
                    cmd->index);
        return (IONIC_RC_ERROR);
    }

    nicmgr_qstate_addr = pd->lm_->get_lif_qstate_addr(hal_lif_info_.lif_id, ETH_ADMINQ_REQ_QTYPE,
                                                      ETH_ADMINQ_REQ_QID);
    if (nicmgr_qstate_addr < 0) {
        NIC_LOG_ERR("{}: Failed to get request qstate address for ADMIN qid {}",
                    hal_lif_info_.name, cmd->index);
        return (IONIC_RC_ERROR);
    }

    uint8_t off;
    admin_qstate_t qstate = {0};
    if (pd->get_pc_offset("txdma_stage0.bin", "adminq_stage0", &off, NULL) < 0) {
        NIC_LOG_ERR("Failed to get PC offset of program: txdma_stage0.bin label: adminq_stage0");
        return (IONIC_RC_ERROR);
    }
    qstate.pc_offset = off;
    qstate.cos_sel = 0;
    qstate.cosA = admin_cosA;
    qstate.cosB = admin_cosB;
    qstate.host = 1;
    qstate.total = 1;
    qstate.pid = cmd->pid;
    qstate.p_index0 = 0;
    qstate.c_index0 = 0;
    qstate.comp_index = 0;
    qstate.ci_fetch = 0;
    qstate.sta.color = 1;
    qstate.cfg.debug = (cmd->flags & IONIC_QINIT_F_DEBUG) ? 1 : 0;
    qstate.cfg.enable = (cmd->flags & IONIC_QINIT_F_ENA) ? 1 : 0;
    qstate.cfg.intr_enable = (cmd->flags & IONIC_QINIT_F_IRQ) ? 1 : 0;
    qstate.cfg.host_queue = spec->host_dev;
    if (spec->host_dev) {
        qstate.ring_base = HOST_ADDR(hal_lif_info_.lif_id, cmd->ring_base);
        qstate.cq_ring_base = HOST_ADDR(hal_lif_info_.lif_id, cmd->cq_ring_base);
    } else {
        qstate.ring_base = cmd->ring_base;
        qstate.cq_ring_base = cmd->cq_ring_base;
    }
    qstate.ring_size = cmd->ring_size;
    if (cmd->flags & IONIC_QINIT_F_IRQ)
        qstate.intr_assert_index = res->intr_base + cmd->intr_index;
    qstate.nicmgr_qstate_addr = nicmgr_qstate_addr;

    WRITE_MEM(addr, (uint8_t *)&qstate, sizeof(qstate), 0);

    PAL_barrier();
    sdk::asic::pd::asicpd_p4plus_invalidate_cache(addr, sizeof(qstate), P4PLUS_CACHE_INVALIDATE_TXDMA);

    comp->hw_index = cmd->index;
    comp->hw_type = ETH_HW_QTYPE_ADMIN;

    NIC_LOG_DEBUG("{}: qid {} qtype {}", hal_lif_info_.name, comp->hw_index, comp->hw_type);

    return (IONIC_RC_SUCCESS);
}

status_code_t
EthLif::SetFeatures(void *req, void *req_data, void *resp, void *resp_data)
{
    struct ionic_lif_setattr_cmd *cmd = (struct ionic_lif_setattr_cmd *)req;
    struct ionic_lif_setattr_comp *comp = (struct ionic_lif_setattr_comp *)resp;
    sdk_ret_t ret = SDK_RET_OK;

    NIC_LOG_DEBUG(
        "{}: wanted "
        "vlan_strip {} vlan_insert {} rx_csum {} tx_csum {} rx_hash {} tx_sg {} rx_sg {}"
        "rx_csum_geneve {} tx_csum_geneve {} tso_geneve {}",
        hal_lif_info_.name,
        (cmd->features & IONIC_ETH_HW_VLAN_RX_STRIP) ? 1 : 0,
        (cmd->features & IONIC_ETH_HW_VLAN_TX_TAG) ? 1 : 0,
        (cmd->features & IONIC_ETH_HW_RX_CSUM) ? 1 : 0,
        (cmd->features & IONIC_ETH_HW_TX_CSUM) ? 1 : 0,
        (cmd->features & IONIC_ETH_HW_RX_HASH) ? 1 : 0,
        (cmd->features & IONIC_ETH_HW_TX_SG) ? 1 : 0,
        (cmd->features & IONIC_ETH_HW_RX_CSUM_GENEVE) ? 1 : 0,
        (cmd->features & IONIC_ETH_HW_TX_CSUM_GENEVE) ? 1 : 0,
        (cmd->features & IONIC_ETH_HW_TSO_GENEVE) ? 1 : 0);

    if (!IsLifInitialized()) {
        NIC_LOG_ERR("{}: Lif is not initialized", hal_lif_info_.name);
        return (IONIC_RC_ERROR);
    }

    DEVAPI_CHECK

    comp->status = 0;
    comp->features = (IONIC_ETH_HW_VLAN_RX_STRIP |
                      IONIC_ETH_HW_VLAN_TX_TAG |
                      IONIC_ETH_HW_VLAN_RX_FILTER |
                      IONIC_ETH_HW_RX_CSUM |
                      IONIC_ETH_HW_TX_CSUM |
                      IONIC_ETH_HW_RX_HASH |
                      IONIC_ETH_HW_TX_SG |
                      IONIC_ETH_HW_RX_SG |
                      IONIC_ETH_HW_TSO |
                      IONIC_ETH_HW_TSO_IPV6 |
                      IONIC_ETH_HW_RX_CSUM_GENEVE |
                      IONIC_ETH_HW_TX_CSUM_GENEVE |
                      IONIC_ETH_HW_TSO_GENEVE);

    this->features = (cmd->features & comp->features);

    bool vlan_strip = cmd->features & comp->features & IONIC_ETH_HW_VLAN_RX_STRIP;
    bool vlan_insert = cmd->features & comp->features & IONIC_ETH_HW_VLAN_TX_TAG;

    ret = dev_api->lif_upd_vlan_offload(hal_lif_info_.lif_id, vlan_strip, vlan_insert);
    if (ret != SDK_RET_OK) {
        NIC_LOG_ERR("{}: Failed to update Vlan offload", hal_lif_info_.name);
        return (IONIC_RC_ERROR);
    }

    NIC_LOG_INFO("{}: vlan_strip {} vlan_insert {}", hal_lif_info_.name, vlan_strip, vlan_insert);

    NIC_LOG_DEBUG("{}: supported {}", hal_lif_info_.name, comp->features);

    return UpdateQFeatures();
}

status_code_t
EthLif::UpdateQFeatures()
{
    uint64_t addr, off;
    eth_rx_features_t features;

    for (uint32_t qid = 0; qid < spec->rxq_count; qid++) {
        addr = pd->lm_->get_lif_qstate_addr(hal_lif_info_.lif_id,
                    ETH_HW_QTYPE_RX, qid);
        off = offsetof(eth_rx_qstate_t, features);
        if (addr < 0) {
            NIC_LOG_ERR("{}: Failed to get qstate address for RX qid {}",
                hal_lif_info_.name, qid);
            return (IONIC_RC_ERROR);
        }
        READ_MEM(addr + off, (uint8_t *)&features, sizeof(features), 0);
        if (this->features & (
            IONIC_ETH_HW_RX_CSUM_GENEVE
            | IONIC_ETH_HW_TX_CSUM_GENEVE
            | IONIC_ETH_HW_TSO_GENEVE))
        {
            features.encap_offload = 1;
        } else {
            features.encap_offload = 0;
        }
        WRITE_MEM(addr + off, (uint8_t *)&features, sizeof(features), 0);
        PAL_barrier();
        sdk::asic::pd::asicpd_p4plus_invalidate_cache(addr,
            sizeof(eth_rx_qstate_t),
            P4PLUS_CACHE_INVALIDATE_BOTH);
    }

    return (IONIC_RC_SUCCESS);
}

status_code_t
EthLif::_CmdGetAttr(void *req, void *req_data, void *resp, void *resp_data)
{
    struct ionic_lif_getattr_cmd *cmd = (struct ionic_lif_getattr_cmd *)req;
    struct ionic_lif_getattr_comp *comp = (struct ionic_lif_getattr_comp *)resp;
    uint64_t mac_addr;

    NIC_LOG_DEBUG("{}: {}: attr {}", hal_lif_info_.name, opcode_to_str((cmd_opcode_t)cmd->opcode),
                  cmd->attr);

    if (!IsLifInitialized()) {
        NIC_LOG_ERR("{}: Lif is not initialized", hal_lif_info_.name);
        return (IONIC_RC_ERROR);
    }

    DEVAPI_CHECK

    switch (cmd->attr) {
    case IONIC_LIF_ATTR_STATE:
        break;
    case IONIC_LIF_ATTR_NAME:
        break;
    case IONIC_LIF_ATTR_MTU:
        comp->mtu = mtu;
        break;
    case IONIC_LIF_ATTR_MAC:
        mac_addr =
            be64toh(spec->mac_addr) >> (8 * sizeof(spec->mac_addr) - 8 * sizeof(uint8_t[6]));
        memcpy((uint8_t *)comp->mac, (uint8_t *)&mac_addr, sizeof(comp->mac));
        NIC_LOG_DEBUG("{}: station mac address {}", hal_lif_info_.name, mac2str(mac_addr));
        break;
    case IONIC_LIF_ATTR_FEATURES:
        break;
    default:
        NIC_LOG_ERR("{}: UNKNOWN ATTR {}", hal_lif_info_.name, cmd->attr);
        return (IONIC_RC_ERROR);
    }

    return (IONIC_RC_SUCCESS);
}

status_code_t
EthLif::_CmdSetAttr(void *req, void *req_data, void *resp, void *resp_data)
{
    struct ionic_lif_setattr_cmd *cmd = (struct ionic_lif_setattr_cmd *)req;
    union {
        eth_qstate_cfg_t eth;
    } cfg = {0};
    uint64_t addr, off;
    asic_db_addr_t db_addr = { 0 };

    NIC_LOG_DEBUG("{}: {}: attr {}", hal_lif_info_.name, opcode_to_str(cmd->opcode), cmd->attr);

    if (!IsLifInitialized()) {
        NIC_LOG_ERR("{}: Lif is not initialized", hal_lif_info_.name);
        return (IONIC_RC_ERROR);
    }

    DEVAPI_CHECK

    switch (cmd->attr) {
    case IONIC_LIF_ATTR_STATE:
        for (uint32_t qid = 0; qid < spec->rxq_count; qid++) {
            addr = pd->lm_->get_lif_qstate_addr(hal_lif_info_.lif_id, ETH_HW_QTYPE_RX, qid);
            off = offsetof(eth_rx_qstate_t, q.cfg);
            if (addr < 0) {
                NIC_LOG_ERR("{}: Failed to get qstate address for RX qid {}",
                    hal_lif_info_.name, qid);
                return (IONIC_RC_ERROR);
            }
            READ_MEM(addr + off, (uint8_t *)&cfg.eth, sizeof(cfg.eth), 0);
            if (!cfg.eth.enable && cmd->state == IONIC_LIF_ENABLE) {
                cfg.eth.enable = 0x1;
                active_q_ref_cnt++;
            } else if (cfg.eth.enable && cmd->state == IONIC_LIF_DISABLE) {
                cfg.eth.enable = 0x0;
                active_q_ref_cnt--;
            }
            WRITE_MEM(addr + off, (uint8_t *)&cfg.eth, sizeof(cfg.eth), 0);
            PAL_barrier();
            sdk::asic::pd::asicpd_p4plus_invalidate_cache(addr, sizeof(eth_rx_qstate_t), P4PLUS_CACHE_INVALIDATE_BOTH);
        }
        for (uint32_t qid = 0; qid < spec->txq_count; qid++) {
            addr = pd->lm_->get_lif_qstate_addr(hal_lif_info_.lif_id, ETH_HW_QTYPE_TX, qid);
            off = offsetof(eth_tx_qstate_t, q.cfg);
            if (addr < 0) {
                NIC_LOG_ERR("{}: Failed to get qstate address for TX qid {}",
                    hal_lif_info_.name, qid);
                return (IONIC_RC_ERROR);
            }
            READ_MEM(addr + off, (uint8_t *)&cfg.eth, sizeof(cfg.eth), 0);
            if (!cfg.eth.enable && cmd->state == IONIC_LIF_ENABLE) {
                cfg.eth.enable = 0x1;
                active_q_ref_cnt++;
            } else if (cfg.eth.enable && cmd->state == IONIC_LIF_DISABLE) {
                cfg.eth.enable = 0x0;
                active_q_ref_cnt--;
            }
            WRITE_MEM(addr + off, (uint8_t *)&cfg.eth, sizeof(cfg.eth), 0);
            PAL_barrier();
            sdk::asic::pd::asicpd_p4plus_invalidate_cache(addr, sizeof(eth_tx_qstate_t), P4PLUS_CACHE_INVALIDATE_TXDMA);
            /* wake up the queue */
            if (cmd->state == IONIC_LIF_ENABLE) {
                db_addr.lif_id = hal_lif_info_.lif_id;
                db_addr.q_type = ETH_HW_QTYPE_TX;
                db_addr.upd = ASIC_DB_ADDR_UPD_FILL(ASIC_DB_UPD_SCHED_EVAL,
                                                    ASIC_DB_UPD_INDEX_UPDATE_NONE,
                                                    false);
                PAL_barrier();
                sdk::asic::pd::asic_ring_db(&db_addr, (uint64_t)(qid << 24));
            }
        }
        /* TODO: Need to implement queue flushing */
        if (cmd->state == IONIC_LIF_DISABLE)
            ev_sleep(RXDMA_LIF_QUIESCE_WAIT_S);
        break;
    case IONIC_LIF_ATTR_NAME:
        strncpy0(name, cmd->name, sizeof(name));
        strncpy0(hal_lif_info_.name, cmd->name, sizeof(hal_lif_info_.name));
        DEVAPI_CHECK
        dev_api->lif_upd_name(hal_lif_info_.lif_id, name);
        break;
    case IONIC_LIF_ATTR_MTU:
        if (cmd->mtu != mtu) {
            if (spec->eth_type == ETH_HOST_MGMT || spec->eth_type == ETH_MNIC_INTERNAL_MGMT) {
                NIC_LOG_ERR("{}: Change MTU not permitted on host/internal management interfaces");
                return (IONIC_RC_EINVAL);
            }
            if (cmd->mtu > MTU_MAX) {
                NIC_LOG_ERR("{}: Requested MTU {} greater than max {}",
                            hal_lif_info_.name, cmd->mtu, MTU_MAX);
                return (IONIC_RC_EINVAL);
            }
            if (cmd->mtu < MTU_MIN) {
                NIC_LOG_ERR("{}: Requested MTU {} less than min {}",
                            hal_lif_info_.name, cmd->mtu, MTU_MIN);
                return (IONIC_RC_EINVAL);
            }
            // This is saved for _CmdGetAttr, but has no other effect.
            mtu = cmd->mtu;
        }
        break;
    case IONIC_LIF_ATTR_MAC:
        break;
    case IONIC_LIF_ATTR_FEATURES:
        return SetFeatures(req, req_data, resp, resp_data);
    case IONIC_LIF_ATTR_RSS:
        return RssConfig(req, req_data, resp, resp_data);
    case IONIC_LIF_ATTR_STATS_CTRL:
        switch (cmd->stats_ctl) {
        case IONIC_STATS_CTL_RESET:
            MEM_SET(lif_stats_addr, 0, LIF_STATS_SIZE, 0);
            sdk::asic::pd::asicpd_p4plus_invalidate_cache(lif_stats_addr, sizeof(struct ionic_lif_stats),
                                                          P4PLUS_CACHE_INVALIDATE_BOTH);
            sdk::asic::pd::asicpd_p4_invalidate_cache(lif_stats_addr, sizeof(struct ionic_lif_stats),
                                                      P4_TBL_CACHE_INGRESS);
            sdk::asic::pd::asicpd_p4_invalidate_cache(lif_stats_addr, sizeof(struct ionic_lif_stats),
                                                      P4_TBL_CACHE_EGRESS);
            break;
        default:
            NIC_LOG_ERR("{}: UNKNOWN COMMAND {} FOR IONIC_LIF_ATTR_STATS_CTRL", hal_lif_info_.name,
                        cmd->stats_ctl);
            return (IONIC_RC_ENOSUPP);
        }
        break;
    default:
        NIC_LOG_ERR("{}: UNKNOWN ATTR {}", hal_lif_info_.name, cmd->attr);
        return (IONIC_RC_ENOSUPP);
    }

    return (IONIC_RC_SUCCESS);
}

status_code_t
EthLif::AdminQControl(uint32_t qid, bool enable)
{
    int64_t addr;
    struct admin_cfg_qstate admin_cfg = {0};

    NIC_FUNC_DEBUG("{}: qid: {} enable: {}" , hal_lif_info_.name, qid, enable);

    if (qid >= spec->adminq_count) {
        NIC_LOG_ERR("{}: bad qid {}", hal_lif_info_.name, qid);
        return (IONIC_RC_EQID);
    }
    addr = pd->lm_->get_lif_qstate_addr(hal_lif_info_.lif_id,
                                        ETH_HW_QTYPE_ADMIN, qid);
    if (addr < 0) {
        NIC_LOG_ERR("{}: Failed to get qstate address for ADMIN qid {}",
                    hal_lif_info_.name, qid);
        return (IONIC_RC_ERROR);
    }

    READ_MEM(addr + offsetof(admin_qstate_t, cfg), (uint8_t *)&admin_cfg,
             sizeof(admin_cfg), 0);
    if (enable)
        admin_cfg.enable = 0x1;
    else if (!enable)
        admin_cfg.enable = 0x0;

    WRITE_MEM(addr + offsetof(admin_qstate_t, cfg), (uint8_t *)&admin_cfg,
              sizeof(admin_cfg), 0);
    PAL_barrier();
    sdk::asic::pd::asicpd_p4plus_invalidate_cache(addr, sizeof(admin_qstate_t),
                                                  P4PLUS_CACHE_INVALIDATE_TXDMA);

    return (IONIC_RC_SUCCESS);
}

status_code_t
EthLif::EdmaQControl(uint32_t qid, bool enable)
{
    status_code_t st = IONIC_RC_SUCCESS;
    int64_t addr, off;
    union {
        eth_qstate_cfg_t eth;
        eth_eq_qstate_cfg_t eq;
    } cfg = {0};

    if (qid >= spec->eq_count) {
        NIC_LOG_ERR("{}: Bad EQ qid {}", hal_lif_info_.name, qid);
        return (IONIC_RC_EQID);
    }

    off = offsetof(eth_eq_qstate_t, cfg);

    addr = res->rx_eq_base + qid * sizeof(eth_eq_qstate_t);
    READ_MEM(addr + off, (uint8_t *)&cfg.eq, sizeof(cfg.eq), 0);
    if (!cfg.eth.enable && enable) {
        cfg.eq.eq_enable = 0x1;
    } else if (cfg.eth.enable && !enable) {
        cfg.eq.eq_enable = 0x0;
    }
    WRITE_MEM(addr + off, (uint8_t *)&cfg.eq, sizeof(cfg.eq), 0);
    PAL_barrier();
    sdk::asic::pd::asicpd_p4plus_invalidate_cache(addr, sizeof(eth_eq_qstate_t), P4PLUS_CACHE_INVALIDATE_RXDMA);

    addr = res->tx_eq_base + qid * sizeof(eth_eq_qstate_t);
    READ_MEM(addr + off, (uint8_t *)&cfg.eq, sizeof(cfg.eq), 0);
    if (!cfg.eth.enable && enable) {
        cfg.eq.eq_enable = 0x1;
    } else if (cfg.eth.enable && !enable) {
        cfg.eq.eq_enable = 0x0;
    }
    WRITE_MEM(addr + off, (uint8_t *)&cfg.eq, sizeof(cfg.eq), 0);
    PAL_barrier();
    sdk::asic::pd::asicpd_p4plus_invalidate_cache(addr, sizeof(eth_eq_qstate_t), P4PLUS_CACHE_INVALIDATE_TXDMA);

    return st;
}

status_code_t
EthLif::NotifyQControl(uint32_t qid, bool enable)
{
    status_code_t st = IONIC_RC_SUCCESS;
    int64_t addr;
    struct notify_cfg_qstate notify_cfg = {0};

    if (qid >= 1) {
        NIC_LOG_ERR("{}: bad qid {}", hal_lif_info_.name, qid);
        return (IONIC_RC_EQID);
    }

    addr = pd->lm_->get_lif_qstate_addr(hal_lif_info_.lif_id,
                                        ETH_NOTIFYQ_QTYPE, qid);
    if (addr < 0) {
        NIC_LOG_ERR("{}: Failed to get qstate address for NOTIFYQ qid {}",
                    hal_lif_info_.name, qid);
        return (IONIC_RC_ERROR);
    }

    READ_MEM(addr + offsetof(notify_qstate_t, cfg), (uint8_t *)&notify_cfg,
             sizeof(notify_cfg), 0);
    if (enable) {
        notify_cfg.enable = 0x1;
    } else if (!enable) {
        notify_cfg.enable = 0x0;
    }
    WRITE_MEM(addr + offsetof(notify_qstate_t, cfg), (uint8_t *)&notify_cfg,
              sizeof(notify_cfg), 0);
    PAL_barrier();
    sdk::asic::pd::asicpd_p4plus_invalidate_cache(addr, sizeof(notify_qstate_t),
                                                  P4PLUS_CACHE_INVALIDATE_TXDMA);

    return st;
}

status_code_t
EthLif::_CmdQControl(void *req, void *req_data, void *resp, void *resp_data)
{
    status_code_t st = IONIC_RC_SUCCESS;
    int64_t addr, off;
    struct ionic_q_control_cmd *cmd = (struct ionic_q_control_cmd *)req;
    // q_enable_comp *comp = (q_enable_comp *)resp;
    union {
        eth_qstate_cfg_t eth;
        eth_eq_qstate_cfg_t eq;
    } cfg = {0};
    asic_db_addr_t db_addr = { 0 };

    NIC_LOG_DEBUG("{}: {}: type {} index {} oper {}", hal_lif_info_.name,
                  opcode_to_str((cmd_opcode_t)cmd->opcode), cmd->type, cmd->index, cmd->oper);

    if (!IsLifInitialized()) {
        NIC_LOG_ERR("{}: Lif is not initialized", hal_lif_info_.name);
        return (IONIC_RC_ERROR);
    }

    if (cmd->type >= 8) {
        NIC_LOG_ERR("{}: bad qtype {}", hal_lif_info_.name, cmd->type);
        return (IONIC_RC_EQTYPE);
    }

    switch (cmd->type) {
    case IONIC_QTYPE_RXQ:
        if (cmd->index >= spec->rxq_count) {
            NIC_LOG_ERR("{}: bad qid {}", hal_lif_info_.name, cmd->index);
            return (IONIC_RC_EQID);
        }
        addr = pd->lm_->get_lif_qstate_addr(hal_lif_info_.lif_id, ETH_HW_QTYPE_RX, cmd->index);
        if (addr < 0) {
            NIC_LOG_ERR("{}: Failed to get qstate address for RX qid {}", hal_lif_info_.name,
                        cmd->index);
            return (IONIC_RC_ERROR);
        }
        off = offsetof(eth_rx_qstate_t, q.cfg);
        READ_MEM(addr + off, (uint8_t *)&cfg.eth, sizeof(cfg.eth), 0);
        if (!cfg.eth.enable && cmd->oper == IONIC_Q_ENABLE) {
            cfg.eth.enable = 0x1;
            active_q_ref_cnt++;
        } else if (cfg.eth.enable && cmd->oper == IONIC_Q_DISABLE) {
            cfg.eth.enable = 0x0;
            active_q_ref_cnt--;
        }
        WRITE_MEM(addr + off, (uint8_t *)&cfg.eth, sizeof(cfg.eth), 0);
        PAL_barrier();
        sdk::asic::pd::asicpd_p4plus_invalidate_cache(addr, sizeof(eth_rx_qstate_t), P4PLUS_CACHE_INVALIDATE_BOTH);
        /* TODO: Need to implement queue flushing */
        if (cmd->oper == IONIC_Q_DISABLE)
            ev_sleep(RXDMA_Q_QUIESCE_WAIT_S);
        break;
    case IONIC_QTYPE_TXQ:
        if (cmd->index >= spec->txq_count) {
            NIC_LOG_ERR("{}: bad qid {}", hal_lif_info_.name, cmd->index);
            return (IONIC_RC_EQID);
        }
        addr = pd->lm_->get_lif_qstate_addr(hal_lif_info_.lif_id, ETH_HW_QTYPE_TX, cmd->index);
        if (addr < 0) {
            NIC_LOG_ERR("{}: Failed to get qstate address for TX qid {}", hal_lif_info_.name,
                        cmd->index);
            return (IONIC_RC_ERROR);
        }
        off = offsetof(eth_tx_qstate_t, q.cfg);
        READ_MEM(addr + off, (uint8_t *)&cfg.eth, sizeof(cfg.eth), 0);
        if (!cfg.eth.enable && cmd->oper == IONIC_Q_ENABLE) {
            cfg.eth.enable = 0x1;
            active_q_ref_cnt++;
        } else if (cfg.eth.enable && cmd->oper == IONIC_Q_DISABLE) {
            cfg.eth.enable = 0x0;
            active_q_ref_cnt--;
        }
        WRITE_MEM(addr + off, (uint8_t *)&cfg.eth, sizeof(cfg.eth), 0);
        PAL_barrier();
        sdk::asic::pd::asicpd_p4plus_invalidate_cache(addr, sizeof(eth_tx_qstate_t), P4PLUS_CACHE_INVALIDATE_TXDMA);
        /* wake up the queue */
        if (cmd->oper == IONIC_Q_ENABLE) {
            db_addr.lif_id = hal_lif_info_.lif_id;
            db_addr.q_type = ETH_HW_QTYPE_TX;
            db_addr.upd = ASIC_DB_ADDR_UPD_FILL(ASIC_DB_UPD_SCHED_EVAL,
                                                ASIC_DB_UPD_INDEX_UPDATE_NONE,
                                                false);
            PAL_barrier();
            sdk::asic::pd::asic_ring_db(&db_addr, (uint64_t)(cmd->index << 24));
        }
        break;
    case IONIC_QTYPE_EQ:
        st = EdmaQControl(cmd->index, cmd->oper);
        break;
    case IONIC_QTYPE_ADMINQ:
        st = AdminQControl(cmd->index, cmd->oper);
        break;
    case IONIC_QTYPE_NOTIFYQ:
        st = NotifyQControl(cmd->index, cmd->oper);
        break;
    default:
        NIC_LOG_ERR("{}: invalid qtype {}", hal_lif_info_.name, cmd->type);
        return (IONIC_RC_ERROR);
        break;
    }

    return st;
}

status_code_t
EthLif::_CmdRxSetMode(void *req, void *req_data, void *resp, void *resp_data)
{
    struct ionic_rx_mode_set_cmd *cmd = (struct ionic_rx_mode_set_cmd *)req;
    // rx_mode_set_comp *comp = (rx_mode_set_comp *)resp;
    sdk_ret_t ret = SDK_RET_OK;

    NIC_LOG_DEBUG("{}: {}: rx_mode {} {}{}{}{}{}{}", hal_lif_info_.name,
                  opcode_to_str((cmd_opcode_t)cmd->opcode), cmd->rx_mode,
                  cmd->rx_mode & IONIC_RX_MODE_F_UNICAST ? 'u' : '-',
                  cmd->rx_mode & IONIC_RX_MODE_F_MULTICAST ? 'm' : '-',
                  cmd->rx_mode & IONIC_RX_MODE_F_BROADCAST ? 'b' : '-',
                  cmd->rx_mode & IONIC_RX_MODE_F_PROMISC ? 'p' : '-',
                  cmd->rx_mode & IONIC_RX_MODE_F_ALLMULTI ? 'a' : '-',
                  cmd->rx_mode & IONIC_RX_MODE_F_RDMA_SNIFFER ? 'r' : '-');

    if (!IsLifInitialized()) {
        NIC_LOG_ERR("{}: Lif is not initialized", hal_lif_info_.name);
        return (IONIC_RC_ERROR);
    }

    // TODO: Check for unsupported flags

    DEVAPI_CHECK

    bool broadcast = cmd->rx_mode & IONIC_RX_MODE_F_BROADCAST;
    bool all_multicast = cmd->rx_mode & IONIC_RX_MODE_F_ALLMULTI;
    bool promiscuous = cmd->rx_mode & IONIC_RX_MODE_F_PROMISC;

    ret = dev_api->lif_upd_rx_mode(hal_lif_info_.lif_id, broadcast, all_multicast, promiscuous);
    if (ret != SDK_RET_OK) {
        NIC_LOG_ERR("{}: Failed to update rx mode", hal_lif_info_.name);
        return (IONIC_RC_ERROR);
    }

    bool rdma_sniffer_en = cmd->rx_mode & IONIC_RX_MODE_F_RDMA_SNIFFER;
    ret = dev_api->lif_upd_rdma_sniff(hal_lif_info_.lif_id, rdma_sniffer_en);
    if (ret != SDK_RET_OK) {
        NIC_LOG_ERR("{}: Failed to update rdma sniffer mode", hal_lif_info_.name);
        return (IONIC_RC_ERROR);
    }

    return (IONIC_RC_SUCCESS);
}

status_code_t
EthLif::_CmdRxFilterAdd(void *req, void *req_data, void *resp, void *resp_data)
{
    // int status;
    uint64_t mac_addr;
    uint16_t vlan;
    uint32_t filter_id = 0;
    struct ionic_rx_filter_add_cmd *cmd = (struct ionic_rx_filter_add_cmd *)req;
    struct ionic_rx_filter_add_comp *comp = (struct ionic_rx_filter_add_comp *)resp;
    sdk_ret_t ret = SDK_RET_OK;

    if (!IsLifInitialized()) {
        NIC_LOG_ERR("{}: Lif is not initialized", hal_lif_info_.name);
        return (IONIC_RC_ERROR);
    }

    DEVAPI_CHECK

    if (cmd->match == IONIC_RX_FILTER_MATCH_MAC) {

        memcpy((uint8_t *)&mac_addr, (uint8_t *)&cmd->mac.addr, sizeof(cmd->mac.addr));
        mac_addr = be64toh(mac_addr) >> (8 * sizeof(mac_addr) - 8 * sizeof(cmd->mac.addr));

        NIC_LOG_DEBUG("{}: Add RX_FILTER_MATCH_MAC mac {}", hal_lif_info_.name, mac2str(mac_addr));

        ret = dev_api->lif_add_mac(hal_lif_info_.lif_id, mac_addr);
        if (ret != SDK_RET_OK) {
            NIC_LOG_WARN("{}: Failed Add Mac:{} ret: {}", hal_lif_info_.name, mac2str(mac_addr),
                         ret);
            if (ret == sdk::SDK_RET_ENTRY_EXISTS)
                return (IONIC_RC_EEXIST);
            else
                return (IONIC_RC_ERROR);
        }

        // Store filter
        if (fltr_allocator->alloc(&filter_id) != sdk::lib::indexer::SUCCESS) {
            NIC_LOG_ERR("Failed to allocate MAC address filter");
            return (IONIC_RC_ERROR);
        }
        mac_addrs[filter_id] = mac_addr;
    } else if (cmd->match == IONIC_RX_FILTER_MATCH_VLAN) {
        vlan = cmd->vlan.vlan;

        NIC_LOG_DEBUG("{}: Add RX_FILTER_MATCH_VLAN vlan {}", hal_lif_info_.name, vlan);

        ret = dev_api->lif_add_vlan(hal_lif_info_.lif_id, vlan);
        if (ret != SDK_RET_OK) {
            NIC_LOG_WARN("{}: Failed Add Vlan:{}. ret: {}", hal_lif_info_.name, vlan, ret);
            if (ret == sdk::SDK_RET_ENTRY_EXISTS)
                return (IONIC_RC_EEXIST);
            else
                return (IONIC_RC_ERROR);
        }

        // Store filter
        if (fltr_allocator->alloc(&filter_id) != sdk::lib::indexer::SUCCESS) {
            NIC_LOG_ERR("Failed to allocate VLAN filter");
            return (IONIC_RC_ERROR);
        }
        vlans[filter_id] = vlan;
    } else {
        memcpy((uint8_t *)&mac_addr, (uint8_t *)&cmd->mac_vlan.addr, sizeof(cmd->mac_vlan.addr));
        mac_addr = be64toh(mac_addr) >> (8 * sizeof(mac_addr) - 8 * sizeof(cmd->mac_vlan.addr));
        vlan = cmd->mac_vlan.vlan;

        NIC_LOG_DEBUG("{}: Add RX_FILTER_MATCH_MAC_VLAN mac {} vlan {}", hal_lif_info_.name,
                      mac2str(mac_addr), vlan);

        ret = dev_api->lif_add_macvlan(hal_lif_info_.lif_id, mac_addr, vlan);
        if (ret != SDK_RET_OK) {
            NIC_LOG_WARN("{}: Failed Add Mac-Vlan:{}-{}. ret: {}", hal_lif_info_.name,
                         mac2str(mac_addr), vlan, ret);
            if (ret == sdk::SDK_RET_ENTRY_EXISTS)
                return (IONIC_RC_EEXIST);
            else
                return (IONIC_RC_ERROR);
        }

        // Store filter
        if (fltr_allocator->alloc(&filter_id) != sdk::lib::indexer::SUCCESS) {
            NIC_LOG_ERR("Failed to allocate VLAN filter");
            return (IONIC_RC_ERROR);
        }
        mac_vlans[filter_id] = std::make_tuple(mac_addr, vlan);
    }

    comp->filter_id = filter_id;
    NIC_LOG_DEBUG("{}: filter_id {}", hal_lif_info_.name, comp->filter_id);
    return (IONIC_RC_SUCCESS);
}

status_code_t
EthLif::_CmdRxFilterDel(void *req, void *req_data, void *resp, void *resp_data)
{
    // int status;
    sdk_ret_t ret;
    uint64_t mac_addr;
    uint16_t vlan;
    struct ionic_rx_filter_del_cmd *cmd = (struct ionic_rx_filter_del_cmd *)req;
    // struct rx_filter_del_comp *comp = (struct rx_filter_del_comp *)resp;
    indexer::status rs;

    if (!IsLifInitialized()) {
        NIC_LOG_ERR("{}: Lif is not initialized", hal_lif_info_.name);
        return (IONIC_RC_ERROR);
    }

    DEVAPI_CHECK

    if (mac_addrs.find(cmd->filter_id) != mac_addrs.end()) {
        mac_addr = mac_addrs[cmd->filter_id];
        NIC_LOG_DEBUG("{}: Del RX_FILTER_MATCH_MAC mac {}", hal_lif_info_.name, mac2str(mac_addr));
        ret = dev_api->lif_del_mac(hal_lif_info_.lif_id, mac_addr);
        mac_addrs.erase(cmd->filter_id);
    } else if (vlans.find(cmd->filter_id) != vlans.end()) {
        vlan = vlans[cmd->filter_id];
        NIC_LOG_DEBUG("{}: Del RX_FILTER_MATCH_VLAN vlan {}", hal_lif_info_.name, vlan);
        ret = dev_api->lif_del_vlan(hal_lif_info_.lif_id, vlan);
        vlans.erase(cmd->filter_id);
    } else if (mac_vlans.find(cmd->filter_id) != mac_vlans.end()) {
        auto mac_vlan = mac_vlans[cmd->filter_id];
        mac_addr = std::get<0>(mac_vlan);
        vlan = std::get<1>(mac_vlan);
        NIC_LOG_DEBUG("{}: Del RX_FILTER_MATCH_MAC_VLAN mac {} vlan {}", hal_lif_info_.name,
                      mac2str(mac_addr), vlan);
        ret = dev_api->lif_del_macvlan(hal_lif_info_.lif_id, mac_addr, vlan);
        mac_vlans.erase(cmd->filter_id);
    } else {
        NIC_LOG_ERR("Invalid filter(Non-exist) id {}", cmd->filter_id);
        return (IONIC_RC_ENOENT);
    }

    rs = fltr_allocator->free(cmd->filter_id);
    if (rs != indexer::SUCCESS) {
        NIC_LOG_ERR("Failed to free filter_id: {}, err: {}", cmd->filter_id, rs);
        return (IONIC_RC_ERROR);
    }
    NIC_LOG_DEBUG("Freed filter_id: {}", cmd->filter_id);

    if (ret == sdk::SDK_RET_ENTRY_NOT_FOUND) {
        return (IONIC_RC_ENOENT);
    }
    return (IONIC_RC_SUCCESS);
}

status_code_t
EthLif::RssConfig(void *req, void *req_data, void *resp, void *resp_data)
{
    struct ionic_lif_setattr_cmd *cmd = (struct ionic_lif_setattr_cmd *)req;
    // struct ionic_lif_setattr_comp *comp = (struct ionic_lif_setattr_comp *)resp;z
    bool posted;

    if (!IsLifInitialized()) {
        NIC_LOG_ERR("{}: Lif is not initialized", hal_lif_info_.name);
        return (IONIC_RC_ERROR);
    }

    rss_type = cmd->rss.types;
    memcpy(rss_key, cmd->rss.key, IONIC_RSS_HASH_KEY_SIZE);

    // Get indirection table from host
    posted = edmaq->Post(spec->host_dev ? EDMA_OPCODE_HOST_TO_LOCAL : EDMA_OPCODE_LOCAL_TO_LOCAL,
                         cmd->rss.addr, edma_buf_addr, RSS_IND_TBL_SIZE, NULL);

    if (!posted) {
        NIC_LOG_ERR("{}: EDMA queue busy", hal_lif_info_.name);
        return (IONIC_RC_EAGAIN);
    }

#ifndef __aarch64__
    READ_MEM(edma_buf_addr, rss_indir, RSS_IND_TBL_SIZE, 0);
#else
    memcpy(rss_indir, edma_buf, RSS_IND_TBL_SIZE);
#endif
    auto to_hexstr = [](const uint8_t *ba, const int len, char *str) {
        int i = 0;
        for (i = 0; i < len; i++) {
            sprintf(str + i * 3, "%02x ", ba[i]);
        }
        str[i * 3] = 0;
    };

    char rss_key_str[RSS_HASH_KEY_SIZE * 3 + 1] = {0};
    char rss_ind_str[RSS_IND_TBL_SIZE * 3 + 1] = {0};

    to_hexstr(rss_key, RSS_HASH_KEY_SIZE, rss_key_str);
    to_hexstr(rss_indir, RSS_IND_TBL_SIZE, rss_ind_str);

    NIC_LOG_DEBUG("{}: {}: rss type {:#x} addr {:#x} key {} table {}", hal_lif_info_.name,
                  opcode_to_str((cmd_opcode_t)cmd->opcode), rss_type, cmd->rss.addr, rss_key_str,
                  rss_ind_str);

    // Validate indirection table entries
    for (int i = 0; i < RSS_IND_TBL_SIZE; i++) {
        if (rss_indir[i] >= spec->rxq_count) {
            NIC_LOG_ERR("{}: Invalid indirection table entry index {} qid {}", hal_lif_info_.name,
                        i, rss_indir[i]);
            return (IONIC_RC_ERROR);
        }
    }

    int ret;
    ret = pd->eth_program_rss(hal_lif_info_.lif_id, rss_type, rss_key, rss_indir, spec->rxq_count);
    if (ret != 0) {
        NIC_LOG_DEBUG("{}: Unable to program hw for RSS HASH", ret);
        return (IONIC_RC_ERROR);
    }

    return IONIC_RC_SUCCESS;
}

/*
 * RDMA Commands
 */
status_code_t
EthLif::_CmdRDMAResetLIF(void *req, void *req_data, void *resp, void *resp_data)
{
    uint64_t addr;
    struct ionic_rdma_queue_cmd *cmd = (struct ionic_rdma_queue_cmd *)req;
    uint64_t lif_id = hal_lif_info_.lif_id + cmd->lif_index;

    NIC_LOG_DEBUG("{}: {}: lif {} ", hal_lif_info_.name, opcode_to_str((cmd_opcode_t)cmd->opcode),
                  lif_id);

    // Clear PC and state of all SQ
    for (uint64_t qid = 0; qid < spec->rdma_sq_count; qid++) {
        addr = pd->lm_->get_lif_qstate_addr(lif_id, ETH_HW_QTYPE_SQ, qid);
        if (addr < 0) {
            NIC_LOG_ERR("{}: Failed to get qstate address for RDMA SQ qid {}", hal_lif_info_.name,
                        qid);
            return (IONIC_RC_ERROR);
        }
        MEM_SET(addr, 0, 1, 0);
        PAL_barrier();
        sdk::asic::pd::asicpd_p4plus_invalidate_cache(addr, sizeof(cqcb_t), P4PLUS_CACHE_INVALIDATE_BOTH);

        addr += sizeof(cqcb_t);
        MEM_SET(addr, 0, 1, 0);
        PAL_barrier();
        sdk::asic::pd::asicpd_p4plus_invalidate_cache(addr, sizeof(cqcb_t), P4PLUS_CACHE_INVALIDATE_BOTH);
    }

    for (uint64_t qid = 0; qid < spec->rdma_rq_count; qid++) {
        addr = pd->lm_->get_lif_qstate_addr(lif_id, ETH_HW_QTYPE_RQ, qid);
        if (addr < 0) {
            NIC_LOG_ERR("{}: Failed to get qstate address for RDMA RQ qid {}", hal_lif_info_.name,
                        qid);
            return (IONIC_RC_ERROR);
        }
        MEM_SET(addr, 0, 1, 0);
        PAL_barrier();
        sdk::asic::pd::asicpd_p4plus_invalidate_cache(addr, sizeof(cqcb_t), P4PLUS_CACHE_INVALIDATE_BOTH);

        addr += sizeof(cqcb_t);
        MEM_SET(addr, 0, 1, 0);
        PAL_barrier();
        sdk::asic::pd::asicpd_p4plus_invalidate_cache(addr, sizeof(cqcb_t), P4PLUS_CACHE_INVALIDATE_BOTH);
    }

    for (uint64_t qid = 0; qid < spec->rdma_cq_count; qid++) {
        addr = pd->lm_->get_lif_qstate_addr(lif_id, ETH_HW_QTYPE_CQ, qid);
        if (addr < 0) {
            NIC_LOG_ERR("{}: Failed to get qstate address for RDMA CQ qid {}", hal_lif_info_.name,
                        qid);
            return (IONIC_RC_ERROR);
        }
        MEM_SET(addr, 0, 1, 0);
        PAL_barrier();
        sdk::asic::pd::asicpd_p4plus_invalidate_cache(addr, sizeof(cqcb_t), P4PLUS_CACHE_INVALIDATE_BOTH);
    }

    for (uint32_t qid = spec->adminq_count; qid < spec->adminq_count + spec->rdma_aq_count;
         qid++) {
        addr = pd->lm_->get_lif_qstate_addr(lif_id, ETH_HW_QTYPE_ADMIN, qid);
        if (addr < 0) {
            NIC_LOG_ERR("{}: Failed to get qstate address for RDMA ADMIN qid {}",
                        hal_lif_info_.name, qid);
            return (IONIC_RC_ERROR);
        }
        MEM_SET(addr, 0, 1, 0);
        PAL_barrier();
        sdk::asic::pd::asicpd_p4plus_invalidate_cache(addr, sizeof(aqcb_t), P4PLUS_CACHE_INVALIDATE_BOTH);
    }

    addr = pd->rdma_get_kt_base_addr(lif_id);
    MEM_SET(addr, 0, spec->key_count * sizeof(key_entry_t), 0);
    PAL_barrier();
    sdk::asic::pd::asicpd_p4plus_invalidate_cache(addr, spec->key_count * sizeof(key_entry_t),
                            P4PLUS_CACHE_INVALIDATE_BOTH);

    return (IONIC_RC_SUCCESS);
}

status_code_t
EthLif::_CmdRDMACreateEQ(void *req, void *req_data, void *resp, void *resp_data)
{
    struct ionic_rdma_queue_cmd *cmd = (struct ionic_rdma_queue_cmd *)req;
    eqcb_t eqcb;
    int64_t addr;
    uint64_t lif_id = hal_lif_info_.lif_id + cmd->lif_index;

    NIC_LOG_DEBUG("{}: {}: lif {} "
                  "qid {} depth_log2 {} stride_log2 {} dma_addr {} "
                  "cid {}",
                  hal_lif_info_.name, opcode_to_str((cmd_opcode_t)cmd->opcode), lif_id,
                  cmd->qid_ver, 1u << cmd->depth_log2, 1u << cmd->stride_log2, cmd->dma_addr,
                  cmd->cid);

    memset(&eqcb, 0, sizeof(eqcb_t));
    // EQ does not need scheduling, so set one less (meaning #rings as zero)
    eqcb.ring_header.total_rings = MAX_EQ_RINGS - 1;
    eqcb.eqe_base_addr = cmd->dma_addr | (1UL << 63) | (lif_id << 52);
    eqcb.log_wqe_size = cmd->stride_log2;
    eqcb.log_num_wqes = cmd->depth_log2;
    eqcb.int_enabled = 1;
    // eqcb.int_num = spec.int_num();
    eqcb.eq_id = cmd->cid;
    eqcb.color = 0;

    eqcb.int_assert_addr = intr_assert_addr(res->intr_base + cmd->cid);

    memrev((uint8_t *)&eqcb, sizeof(eqcb_t));

    addr = pd->lm_->get_lif_qstate_addr(lif_id, ETH_HW_QTYPE_EQ, cmd->qid_ver);
    if (addr < 0) {
        NIC_LOG_ERR("{}: Failed to get qstate address for EQ qid {}", lif_id, cmd->qid_ver);
        return (IONIC_RC_ERROR);
    }
    WRITE_MEM(addr, (uint8_t *)&eqcb, sizeof(eqcb), 0);
    sdk::asic::pd::asicpd_p4plus_invalidate_cache(addr, sizeof(eqcb_t), P4PLUS_CACHE_INVALIDATE_BOTH);

    return (IONIC_RC_SUCCESS);
}

status_code_t
EthLif::_CmdRDMACreateCQ(void *req, void *req_data, void *resp, void *resp_data)
{
    struct ionic_rdma_queue_cmd *cmd = (struct ionic_rdma_queue_cmd *)req;
    uint32_t num_cq_wqes, cqwqe_size;
    cqcb_t cqcb;
    uint8_t offset;
    int ret;
    int64_t addr;
    uint64_t lif_id = hal_lif_info_.lif_id + cmd->lif_index;

    NIC_LOG_DEBUG("{}: {} lif {} cq_num {} cq_wqe_size {} num_cq_wqes {} "
                  "eq_id {} hostmem_pg_size {} ",
                  hal_lif_info_.name, opcode_to_str((cmd_opcode_t)cmd->opcode), lif_id,
                  cmd->qid_ver, 1u << cmd->stride_log2, 1u << cmd->depth_log2, cmd->cid,
                  1ull << (cmd->stride_log2 + cmd->depth_log2));

    cqwqe_size = 1u << cmd->stride_log2;
    num_cq_wqes = 1u << cmd->depth_log2;

    NIC_LOG_DEBUG("cqwqe_size: {} num_cq_wqes: {}", cqwqe_size, num_cq_wqes);

    memset(&cqcb, 0, sizeof(cqcb_t));
    cqcb.ring_header.total_rings = MAX_CQ_RINGS;
    cqcb.ring_header.host_rings = MAX_CQ_HOST_RINGS;

    cqcb.log_cq_page_size = cmd->stride_log2 + cmd->depth_log2;
    cqcb.log_wqe_size = log2(cqwqe_size);
    cqcb.log_num_wqes = log2(num_cq_wqes);
    cqcb.cq_id = cmd->qid_ver;
    cqcb.eq_id = cmd->cid;
    cqcb.host_addr = 1;

    cqcb.pt_pa = cmd->dma_addr;
    if (cqcb.host_addr) {
        cqcb.pt_pa |= ((1UL << 63) | lif_id << 52);
    }

    cqcb.pt_pg_index = 0;
    cqcb.pt_next_pg_index = 0x1FF;

    int log_num_pages = cqcb.log_num_wqes + cqcb.log_wqe_size - cqcb.log_cq_page_size;
    NIC_LOG_DEBUG("{}: pt_pa: {:#x}: pt_next_pa: {:#x}: pt_pa_index: {}: pt_next_pa_index: {}: "
                  "log_num_pages: {}",
                  lif_id, cqcb.pt_pa, cqcb.pt_next_pa, cqcb.pt_pg_index, cqcb.pt_next_pg_index,
                  log_num_pages);

    /* store  pt_pa & pt_next_pa in little endian. So need an extra memrev */
    memrev((uint8_t *)&cqcb.pt_pa, sizeof(uint64_t));

    ret = pd->get_pc_offset("rxdma_stage0.bin", "rdma_cq_rx_stage0", &offset, NULL);
    if (ret < 0) {
        NIC_LOG_ERR("Failed to get PC offset : {} for prog: {}, label: {}", ret,
                    "rxdma_stage0.bin", "rdma_cq_rx_stage0");
        return (IONIC_RC_ERROR);
    }

    cqcb.ring_header.pc = offset;

    // write to hardware
    NIC_LOG_DEBUG("{}: Writing initial CQCB State, "
                  "CQCB->PT: {:#x} cqcb_size: {}",
                  lif_id, cqcb.pt_pa, sizeof(cqcb_t));
    // Convert data before writing to HBM
    memrev((uint8_t *)&cqcb, sizeof(cqcb_t));

    addr = pd->lm_->get_lif_qstate_addr(lif_id, ETH_HW_QTYPE_CQ, cmd->qid_ver);
    if (addr < 0) {
        NIC_LOG_ERR("{}: Failed to get qstate address for CQ qid {}", lif_id, cmd->qid_ver);
        return IONIC_RC_ERROR;
    }
    WRITE_MEM(addr, (uint8_t *)&cqcb, sizeof(cqcb), 0);

    return (IONIC_RC_SUCCESS);
}

status_code_t
EthLif::_CmdRDMACreateAdminQ(void *req, void *req_data, void *resp, void *resp_data)
{
    struct ionic_rdma_queue_cmd *cmd = (struct ionic_rdma_queue_cmd *)req;
    int ret;
    aqcb_t aqcb;
    uint8_t offset;
    int64_t addr;
    uint64_t lif_id = hal_lif_info_.lif_id + cmd->lif_index;

    NIC_LOG_DEBUG("{}: {}: lif: {} aq_num: {} aq_log_wqe_size: {} "
                  "aq_log_num_wqes: {} "
                  "cq_num: {} phy_base_addr: {}",
                  hal_lif_info_.name, opcode_to_str((cmd_opcode_t)cmd->opcode), lif_id,
                  cmd->qid_ver, cmd->stride_log2, cmd->depth_log2, cmd->cid, cmd->dma_addr);

    memset(&aqcb, 0, sizeof(aqcb_t));
    aqcb.aqcb0.ring_header.total_rings = MAX_AQ_RINGS;
    aqcb.aqcb0.ring_header.host_rings = MAX_AQ_HOST_RINGS;
    aqcb.aqcb0.ring_header.cosA = 1;
    aqcb.aqcb0.ring_header.cosB = 1;

    aqcb.aqcb0.log_wqe_size = cmd->stride_log2;
    aqcb.aqcb0.log_num_wqes = cmd->depth_log2;
    aqcb.aqcb0.uplink_num = hal_lif_info_.pinned_uplink_port_num;
    aqcb.aqcb0.aq_id = cmd->qid_ver;
    aqcb.aqcb0.phy_base_addr = cmd->dma_addr | (1UL << 63) | (lif_id << 52);
    aqcb.aqcb0.cq_id = cmd->cid;
    addr = pd->lm_->get_lif_qstate_addr(lif_id, ETH_HW_QTYPE_CQ, cmd->cid);
    if (addr < 0) {
        NIC_LOG_ERR("{}: Failed to get qstate address for CQ qid {}", lif_id, cmd->cid);
        return IONIC_RC_ERROR;
    }
    aqcb.aqcb0.cqcb_addr = addr;

    aqcb.aqcb0.first_pass = 1;

    ret = pd->get_pc_offset("txdma_stage0.bin", "rdma_aq_tx_stage0", &offset, NULL);
    if (ret < 0) {
        NIC_LOG_ERR("Failed to get PC offset : {} for prog: {}, label: {}", ret,
                    "txdma_stage0.bin", "rdma_aq_tx_stage0");
        return IONIC_RC_ERROR;
    }

    aqcb.aqcb0.ring_header.pc = offset;

    // write to hardware
    NIC_LOG_DEBUG("{}: Writing initial AQCB State, "
                  "AQCB->phy_addr: {:#x} "
                  "aqcb_size: {}",
                  lif_id, aqcb.aqcb0.phy_base_addr, sizeof(aqcb_t));

    // Convert data before writing to HBM
    memrev((uint8_t *)&aqcb.aqcb0, sizeof(aqcb0_t));
    memrev((uint8_t *)&aqcb.aqcb1, sizeof(aqcb1_t));

    addr = pd->lm_->get_lif_qstate_addr(lif_id, ETH_HW_QTYPE_ADMIN, cmd->qid_ver);
    if (addr < 0) {
        NIC_LOG_ERR("{}: Failed to get qstate address for AQ qid {}", lif_id, cmd->qid_ver);
        return IONIC_RC_ERROR;
    }
    WRITE_MEM(addr, (uint8_t *)&aqcb, sizeof(aqcb), 0);

    return (IONIC_RC_SUCCESS);
}

/*
 * Event Handlers
 */

void
EthLif::HalEventHandler(bool status)
{
    if (status) {
        Create();
    } else {
        dev_api = NULL;
    }
}

void
EthLif::DelphiMountEventHandler(bool mounted)
{
    if (!mounted) {
        return;
    }
}

void
EthLif::UpdateQStatus(bool enable)
{
    status_code_t st;

    // queue control for adminq
    for (uint32_t i = 0; i < spec->adminq_count; i++) {
        st = AdminQControl(i, enable);
        if (st != IONIC_RC_SUCCESS) {
            NIC_LOG_ERR("{}: Admin Queue control failed ctrl: {} adminq cnt: {}, qid: {}",
                hal_lif_info_.name, enable, spec->adminq_count, i);
        }
        if (!enable) {
            adminq->Flush();
        }
    }

    // queue control for EDMAQ
    for (uint32_t i = 0; i < spec->eq_count; i++) {
        st = EdmaQControl(i, enable);
        if (st != IONIC_RC_SUCCESS) {
            NIC_LOG_ERR("{}: Edma Queue control failed ctrl: {} eq cnt : {}, qid: {}",
                hal_lif_info_.name, enable, spec->eq_count, i);
        }

        if(!enable) {
            edmaq->Flush();
        }
    }

    // queue control for notifyQ
    if (notify_enabled == 1) {
        st = NotifyQControl(0, enable);
        if (st != IONIC_RC_SUCCESS) {
            NIC_LOG_ERR("{}: notify Queue control failed ctrl: {}",
                hal_lif_info_.name, enable);
        }
    }

    return;
}

void
EthLif::LinkEventHandler(port_status_t *evd)
{
    if (spec->uplink_port_num != evd->id) {
        return;
    }

    // drop the event if the lif is not initialized
    if (!IsLifInitialized()) {
        NIC_LOG_INFO("{}: {} + {} => {} dropping event", hal_lif_info_.name, lif_state_to_str(state),
                     (evd->status == IONIC_PORT_OPER_STATUS_UP) ? "LINK_UP" : "LINK_DN",
                     lif_state_to_str(state));
        return;
    }

    enum eth_lif_state next_state =
        (evd->status == IONIC_PORT_OPER_STATUS_UP) ? LIF_STATE_UP : LIF_STATE_DOWN;

    // Update local lif status
    lif_status->link_status = evd->status;
    lif_status->link_speed = evd->speed;
    ++lif_status->eid;
    if (state == LIF_STATE_UP && next_state == LIF_STATE_DOWN)
        ++lif_status->link_down_count;
    WRITE_MEM(lif_status_addr, (uint8_t *)lif_status, sizeof(struct ionic_lif_status), 0);

    NIC_FUNC_DEBUG("{}: state: {} eid: {} link status: {} link speed: {} linkdn cnt: {}",
                     hal_lif_info_.name, lif_state_to_str(state), lif_status->eid,
                     lif_status->link_status, lif_status->link_speed, lif_status->link_down_count);

    // Update host lif status
    if (host_lif_status_addr != 0) {
        edmaq->Post(spec->host_dev ? EDMA_OPCODE_LOCAL_TO_HOST : EDMA_OPCODE_LOCAL_TO_LOCAL,
                    lif_status_addr, host_lif_status_addr, sizeof(struct ionic_lif_status), NULL);
    }

    NIC_LOG_INFO("{}: {} + {} => {}", hal_lif_info_.name, lif_state_to_str(state),
                 (evd->status == IONIC_PORT_OPER_STATUS_UP) ? "LINK_UP" : "LINK_DN",
                 lif_state_to_str(next_state));

    state = next_state;
    // Notify HAL
    dev_api->lif_upd_state(hal_lif_info_.lif_id, (lif_state_t)ConvertEthLifStateToLifState(state));

    if (notify_enabled == 0) {
        return;
    }

    uint64_t addr;
    uint64_t db_data;
    asic_db_addr_t db_addr = { 0 };

    // Send the link event notification
    struct ionic_link_change_event msg = {
        .eid = lif_status->eid,
        .ecode = IONIC_EVENT_LINK_CHANGE,
        .link_status = evd->status,
        .link_speed = evd->speed,
    };

    addr = notify_ring_base + notify_ring_head * sizeof(union ionic_notifyq_comp);
    WRITE_MEM(addr, (uint8_t *)&msg, sizeof(union ionic_notifyq_comp), 0);

    db_addr.lif_id = hal_lif_info_.lif_id;
    db_addr.q_type = ETH_NOTIFYQ_QTYPE;
    db_addr.upd = ASIC_DB_ADDR_UPD_FILL(ASIC_DB_UPD_SCHED_SET,
                    ASIC_DB_UPD_INDEX_SET_PINDEX, false);

    NIC_FUNC_DEBUG("{}: Sending notify event, eid {} notify_idx {} notify_desc_addr {:#x}",
         hal_lif_info_.lif_id, lif_status->eid, notify_ring_head, addr);
    notify_ring_head = (notify_ring_head + 1) % ETH_NOTIFYQ_RING_SIZE;
    PAL_barrier();

    db_data = (ETH_NOTIFYQ_QID << 24) | notify_ring_head;
    sdk::asic::pd::asic_ring_db(&db_addr, db_data);

    // FIXME: Wait for completion
}

void
EthLif::XcvrEventHandler(port_status_t *evd)
{
    if (spec->uplink_port_num != evd->id) {
        return;
    }

    // drop the event if the lif is not initialized
    if (state != LIF_STATE_INIT && state != LIF_STATE_UP && state != LIF_STATE_DOWN) {
        NIC_LOG_INFO("{}: {} + XCVR_EVENT => {} dropping event", hal_lif_info_.name, lif_state_to_str(state),
                     lif_state_to_str(state));
        return;
    }

    NIC_LOG_INFO("{}: {} + XCVR_EVENT => {}", hal_lif_info_.name, lif_state_to_str(state),
                     lif_state_to_str(state));

    if (notify_enabled == 0) {
        return;
    }

    uint64_t addr;
    uint64_t db_data;
    asic_db_addr_t db_addr = { 0 };

    ++lif_status->eid;

    // Send the xcvr notification
    struct ionic_xcvr_event msg = {
        .eid = lif_status->eid,
        .ecode = IONIC_EVENT_XCVR,
    };

    addr = notify_ring_base + notify_ring_head * sizeof(union ionic_notifyq_comp);
    WRITE_MEM(addr, (uint8_t *)&msg, sizeof(union ionic_notifyq_comp), 0);

    db_addr.lif_id = hal_lif_info_.lif_id;
    db_addr.q_type = ETH_NOTIFYQ_QTYPE;
    db_addr.upd = ASIC_DB_ADDR_UPD_FILL(ASIC_DB_UPD_SCHED_SET,
                    ASIC_DB_UPD_INDEX_SET_PINDEX, false);

    NIC_FUNC_DEBUG("{}: Sending notify event, eid {} notify_idx {} notify_desc_addr {:#x}",
         hal_lif_info_.lif_id, lif_status->eid, notify_ring_head, addr);
    notify_ring_head = (notify_ring_head + 1) % ETH_NOTIFYQ_RING_SIZE;
    PAL_barrier();

    db_data = (ETH_NOTIFYQ_QID << 24) | notify_ring_head;
    sdk::asic::pd::asic_ring_db(&db_addr, db_data);

    // FIXME: Wait for completion
}

void
EthLif::SendDeviceReset(void) {
    uint64_t addr;
    uint64_t db_data;
    asic_db_addr_t db_addr = { 0 };

    if (!IsLifInitialized()) {
        NIC_LOG_WARN("{}: state: {} Cannot send RESET event when lif is not initialized!",
                     hal_lif_info_.name, lif_state_to_str(state));
        return;
    }

    // Update local lif status
    lif_status->link_status = 0;
    lif_status->link_speed = 0;
    ++lif_status->eid;
    WRITE_MEM(lif_status_addr, (uint8_t *)lif_status, sizeof(struct ionic_lif_status), 0);

    NIC_FUNC_DEBUG("{}: state: {} eid: {} link status: {} link speed: {}",
                     hal_lif_info_.name, lif_state_to_str(state), lif_status->eid,
                     lif_status->link_status, lif_status->link_speed);

    // Update host lif status
    if (host_lif_status_addr != 0) {
        edmaq->Post(spec->host_dev ? EDMA_OPCODE_LOCAL_TO_HOST : EDMA_OPCODE_LOCAL_TO_LOCAL,
                    lif_status_addr, host_lif_status_addr, sizeof(struct ionic_lif_status), NULL);
    }

    if (notify_enabled == 0) {
        return;
    }

    // Send the link event notification
    struct ionic_reset_event msg = {
        .eid = lif_status->eid,
        .ecode = IONIC_EVENT_RESET,
        .reset_code = 0, // FIXME: not sure what to program here
        .state = 1,      // reset complete
    };

    addr = notify_ring_base + notify_ring_head * sizeof(union ionic_notifyq_comp);
    WRITE_MEM(addr, (uint8_t *)&msg, sizeof(union ionic_notifyq_comp), 0);

    db_addr.lif_id = hal_lif_info_.lif_id;
    db_addr.q_type = ETH_NOTIFYQ_QTYPE;
    db_addr.upd = ASIC_DB_ADDR_UPD_FILL(ASIC_DB_UPD_SCHED_SET,
                    ASIC_DB_UPD_INDEX_SET_PINDEX, false);

    notify_ring_head = (notify_ring_head + 1) % ETH_NOTIFYQ_RING_SIZE;
    PAL_barrier();

    db_data = (ETH_NOTIFYQ_QID << 24) | notify_ring_head;
    sdk::asic::pd::asic_ring_db(&db_addr, db_data);

    NIC_FUNC_DEBUG("{}: Sending notify event, eid {} notify_idx {} notify_desc_addr {:#x}",
         hal_lif_info_.lif_id, msg.eid, notify_ring_head, addr);

    // FIXME: Wait for completion
    NIC_LOG_INFO("{}: {} + {} => {}", hal_lif_info_.name,
                 lif_state_to_str(state), "RESET",
                 lif_state_to_str(state));
}

void
EthLif::SetHalClient(devapi *dapi)
{
    dev_api = dapi;
}

/*
 * Callbacks
 */

void
EthLif::StatsUpdate(EV_P_ ev_timer *w, int events)
{
    EthLif *eth = (EthLif *)w->data;
    struct edmaq_ctx ctx = { .cb = NULL, .obj = NULL };

    if (eth->lif_stats_addr != 0 && eth->host_lif_stats_addr != 0) {
        eth->edmaq_async->Post(eth->spec->host_dev ? EDMA_OPCODE_LOCAL_TO_HOST : EDMA_OPCODE_LOCAL_TO_LOCAL,
                                eth->lif_stats_addr, eth->host_lif_stats_addr,
                                sizeof(struct ionic_lif_stats), &ctx);
    }
}


void
EthLif::SchedBulkEvalHandler(EV_P_ ev_timer *w, int events)
{
    EthLif *eth = (EthLif *)w->data;
    uint64_t iter = 0;
    uint8_t  cos = 0;
    asic_db_addr_t db_addr =  { 0 };

    // HBM scheduler table base-addr for RQ
    uint64_t addr = eth->hal_lif_info_.tx_sched_bulk_eval_start_addr;
    char     sched_map[1024] = {0};
    uint32_t num_entries_per_cos = (eth->hal_lif_info_.tx_sched_num_table_entries /
                                        eth->hal_lif_info_.tx_sched_num_coses);

    // Scheduler table is indexed by (lif,cos).
    // Read scheduler table for all RQs for each cos lif participates in.
    // Issue eval doorbell for all set queues.
    for (cos = 0; cos < eth->hal_lif_info_.tx_sched_num_coses; cos ++) {
        sdk::asic::asic_mem_read(addr, (uint8_t *)sched_map, ((eth->spec->rdma_rq_count) / 8));
        for (iter = 0; iter < eth->spec->rdma_rq_count; iter++) {
            if ((sched_map[iter / 8]) & (1 << (iter % 8))) {
                //Ring doorbell to eval RQ
//                NIC_LOG_DEBUG("Eval db lif: {} qid: {} ",eth->hal_lif_info_.lif_id, iter);
                db_addr.lif_id = eth->hal_lif_info_.lif_id;
                db_addr.q_type =  4 /*RDMA_QTYPE_RQ*/;
                db_addr.upd = ASIC_DB_ADDR_UPD_FILL(ASIC_DB_UPD_SCHED_EVAL,
                                                    ASIC_DB_UPD_INDEX_UPDATE_NONE,
                                                    false);
                PAL_barrier();
                sdk::asic::pd::asic_ring_db(&db_addr, (iter << 24));
            }
        }
        addr += (num_entries_per_cos * 1024);
    }
    return;
}

int
EthLif::GenerateQstateInfoJson(pt::ptree &lifs)
{
    pt::ptree lif;
    pt::ptree qstates;

    NIC_LOG_DEBUG("{}: Qstate Info to Json", hal_lif_info_.name);

    lif.put("lif_id", hal_lif_info_.lif_id);

    for (int j = 0; j < NUM_QUEUE_TYPES; j++) {
        pt::ptree qs;
        char numbuf[32];

        if (qinfo[j].size < 1)
            continue;

        qs.put("qtype", qinfo[j].type_num);
        qs.put("qsize", qinfo[j].size);
        qs.put("qaddr", hal_lif_info_.qstate_addr[qinfo[j].type_num]);
        snprintf(numbuf, sizeof(numbuf), "0x%lx", hal_lif_info_.qstate_addr[qinfo[j].type_num]);
        qs.put("qaddr_hex", numbuf);
        qstates.push_back(std::make_pair("", qs));
        qs.clear();
    }

    lif.add_child("qstates", qstates);
    lifs.push_back(std::make_pair("", lif));
    qstates.clear();
    lif.clear();
    return 0;
}

lif_state_t
EthLif::ConvertEthLifStateToLifState(enum eth_lif_state lif_state)
{
    switch (lif_state) {
    case LIF_STATE_UP:
        return sdk::types::LIF_STATE_UP;
    default:
        return sdk::types::LIF_STATE_DOWN;
    }
}

bool
EthLif::IsLifTypeCpu()
{
    switch (hal_lif_info_.type) {
    case sdk::platform::lif_type_t::LIF_TYPE_MNIC_CPU:
    case sdk::platform::lif_type_t::LIF_TYPE_LEARN:
        return true;
    default:
        return false;
    }
}

bool
EthLif::IsLifInitialized()
{
    return state >= LIF_STATE_INIT;
}
