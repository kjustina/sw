//
// {C} Copyright 2019 Pensando Systems Inc. All rights reserved
//
//----------------------------------------------------------------------------
///
/// \file
/// athena pipeline utils implementation
///
//----------------------------------------------------------------------------

#ifndef __ATHENA_IMPL_UTILS_HPP__
#define __ATHENA_IMPL_UTILS_HPP__

#include "nic/sdk/include/sdk/types.hpp"
#include "nic/sdk/asic/pd/pd.hpp"
#include "gen/p4gen/athena/include/p4pd.h"
#include "gen/p4gen/p4plus_rxdma/include/p4plus_rxdma_p4pd.h"
#include "gen/p4gen/p4plus_txdma/include/p4plus_txdma_p4pd.h"

namespace api {
namespace impl {

/// \brief     P4 and HBM init of the pipeline
/// \param[in] p4pd config to be populated and used for init
/// \param[in] hw_init indicating whether to program HW or not
/// \return    #SDK_RET_OK on success, failure status code on error
static inline sdk_ret_t
pipeline_p4_hbm_init (p4pd_cfg_t *p4pd_cfg, bool hw_init = true)
{
    p4pd_error_t    p4pd_ret;
    sdk_ret_t       ret;

    SDK_ASSERT(p4pd_cfg->cfg_path);
    p4pd_cfg_t p4pd_rxdma_cfg = {
        .table_map_cfg_file  = "athena/rxdma_table_map.json",
        .p4pd_pgm_name       = "athena_p4",
        .p4pd_rxdma_pgm_name = "athena_rxdma",
        .p4pd_txdma_pgm_name = "athena_txdma",
        .cfg_path = p4pd_cfg->cfg_path
    };
    p4pd_cfg_t p4pd_txdma_cfg = {
        .table_map_cfg_file  = "athena/txdma_table_map.json",
        .p4pd_pgm_name       = "athena_p4",
        .p4pd_rxdma_pgm_name = "athena_rxdma",
        .p4pd_txdma_pgm_name = "athena_txdma",
        .cfg_path = p4pd_cfg->cfg_path
    };

    p4pd_cfg->table_map_cfg_file  = "athena/p4_table_map.json";
    p4pd_cfg->p4pd_pgm_name       = "athena_p4";
    p4pd_cfg->p4pd_rxdma_pgm_name = "athena_rxdma";
    p4pd_cfg->p4pd_txdma_pgm_name = "athena_txdma";

    p4pd_ret = p4pd_init(p4pd_cfg);
    SDK_ASSERT(p4pd_ret == P4PD_SUCCESS);
    p4pd_ret = p4pluspd_rxdma_init(&p4pd_rxdma_cfg);
    SDK_ASSERT(p4pd_ret == P4PD_SUCCESS);
    p4pd_ret = p4pluspd_txdma_init(&p4pd_txdma_cfg);
    SDK_ASSERT(p4pd_ret == P4PD_SUCCESS);

    if (hw_init) {
        ret = sdk::asic::pd::asicpd_program_hbm_table_base_addr();
    } else {
        ret = sdk::asic::pd::asicpd_set_hbm_table_base_addr();
    }
    return ret;
}

}    // namespace impl
}    // namespace api

#endif    //__ATHENA_IMPL_UTILS_HPP__
