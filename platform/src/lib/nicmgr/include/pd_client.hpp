/*
* Copyright (c) 2018, Pensando Systems Inc.
*/

#ifndef __PD_CLIENT_HPP__
#define __PD_CLIENT_HPP__

#include "hal_client.hpp"
#include "nic/sdk/include/sdk/platform/capri/capri_lif_manager.hpp"
#include "nic/sdk/include/sdk/platform/utils/mpartition.hpp"
#include "nic/sdk/include/sdk/directmap.hpp"
#include "common_rxdma_actions_p4pd.h"
#include "common_txdma_actions_p4pd.h"
#include "capri_hbm.hpp"

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

class PdClient {
public:
    static PdClient* factory(platform_t platform);
    void destroy(PdClient *pdc);

    string hal_cfg_path_;
    string gen_dir_path_;
    platform_t platform_;
    sdk::platform::utils::program_info *pinfo_;
    sdk::platform::utils::mpartition *mp_;
    sdk::platform::capri::LIFManager *lm_;
    directmap    **p4plus_rxdma_dm_tables_;
    directmap    **p4plus_txdma_dm_tables_;

    int lif_qstate_map_init(uint64_t hw_lif_id,
                            struct queue_info* queue_info,
                            uint8_t coses);

    int lif_qstate_init(uint64_t hw_lif_id, struct queue_info* queue_info);

    int program_qstate(struct queue_info* queue_info,
                       struct lif_info *lif_info,
                       uint8_t coses);


    int create_dirs();
    int p4plus_rxdma_init_tables();
    int p4plus_txdma_init_tables();    
    int pd_state_init();

    int p4pd_common_p4plus_rxdma_rss_params_table_entry_add(
            uint32_t hw_lif_id, uint8_t rss_type, uint8_t *rss_key);
    int p4pd_common_p4plus_rxdma_rdma_params_table_entry_get(
            uint32_t hw_lif_id, eth_rx_rss_params_actiondata *data);

    int p4pd_common_p4plus_rxdma_rss_indir_table_entry_add(
            uint32_t hw_lif_id, uint8_t index, uint8_t enable, uint8_t qid);
    int p4pd_common_p4plus_rxdma_rss_indir_table_entry_get(
            uint32_t hw_lif_id, uint8_t index, eth_rx_rss_indir_actiondata *data);

    int p4pd_common_p4plus_rxdma_rss_params_table_entry_get(
            uint32_t hw_lif_id, eth_rx_rss_params_actiondata *data);

    int eth_program_rss(uint32_t hw_lif_id, uint16_t rss_type,
                        uint8_t *rss_key, uint8_t *rss_indir,
                        uint16_t num_queues);

    sdk::platform::utils::mem_addr_t mem_start_addr(const char *region);

/* RDMA routines */
    int rdma_lif_init(uint32_t lif, uint32_t max_keys,
                      uint32_t max_ahs, uint32_t max_ptes,
                      uint64_t *hbm_bar_address, uint32_t *hbm_bar_size);

    int p4pd_common_p4plus_rxdma_stage0_rdma_params_table_entry_add(
        uint32_t idx,
        uint8_t rdma_en_qtype_mask,
        uint32_t pt_base_addr_page_id,
        uint8_t log_num_pt_entries,
        uint32_t cqcb_base_addr_hi,
        uint32_t sqcb_base_addr_hi,
        uint32_t rqcb_base_addr_hi,
        uint8_t log_num_cq_entries,
        uint32_t prefetch_pool_base_addr_page_id,
        uint8_t log_num_prefetch_pool_entries,
        uint8_t sq_qtype,
        uint8_t rq_qtype,
        uint8_t aq_qtype);
    int p4pd_common_p4plus_txdma_stage0_rdma_params_table_entry_add(
        uint32_t idx,
        uint8_t rdma_en_qtype_mask,
        uint32_t pt_base_addr_page_id,
        uint32_t ah_base_addr_page_id,
        uint8_t log_num_pt_entries,
        uint32_t rrq_base_addr_page_id,
        uint32_t rsq_base_addr_page_id,
        uint32_t cqcb_base_addr_hi,
        uint32_t sqcb_base_addr_hi,
        uint32_t rqcb_base_addr_hi,
        uint8_t log_num_cq_entries,
        uint32_t prefetch_pool_base_addr_page_id,
        uint8_t log_num_prefetch_pool_entries,
        uint8_t sq_qtype,
        uint8_t rq_qtype,
        uint8_t aq_qtype,
        uint64_t barmap_base_addr,
        uint32_t barmap_size);
    void rdma_manager_init(void);
    uint64_t RdmaHbmAlloc(uint32_t size);
    uint64_t RdmaHbmBarAlloc(uint32_t size);

    uint64_t rdma_get_pt_base_addr(uint32_t lif);
    uint64_t rdma_get_kt_base_addr(uint32_t lif);
    uint64_t rdma_get_ah_base_addr(uint32_t lif);

private:
    PdClient(){}
    ~PdClient(){}

    std::unique_ptr<hal::BMAllocator> rdma_hbm_allocator_;
    std::unique_ptr<hal::BMAllocator> rdma_hbm_bar_allocator_;
    uint64_t rdma_hbm_base_;
    uint64_t rdma_hbm_bar_base_;
    std::map<uint64_t, uint64_t> rdma_allocation_sizes_;
    std::map<uint64_t, uint64_t> rdma_bar_allocation_sizes_;

    int p4pd_common_p4plus_rxdma_stage0_rdma_params_table_entry_get(
        uint32_t idx, rx_stage0_load_rdma_params_actiondata *data);
    int p4pd_common_p4plus_txdma_stage0_rdma_params_table_entry_get(
        uint32_t idx, tx_stage0_lif_params_table_actiondata *data);

};


#endif //__PD_CLIENT_HPP__
