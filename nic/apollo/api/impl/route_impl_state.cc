/**
 * Copyright (c) 2018 Pensando Systems, Inc.
 *
 * @file    route_impl_state.cc
 *
 * @brief   This file contains route table datapath database handling
 */

#include "nic/apollo/api/include/pds_route.hpp"
#include "nic/apollo/api/impl/route_impl_state.hpp"

namespace api {
namespace impl {

/**
 * @defgroup PDS_ROUTE_TABLE_IMPL_STATE - route table database functionality
 * @ingroup PDS_ROUTE
 * @{
 */

/**
 * @brief    constructor
 */
route_table_impl_state::route_table_impl_state(pds_state *state) {
    /**
     * we need max + 1 blocks, extra 1 block for processing updates for
     * routing table (with the assumption that more than one routing table
     * is not updated in any given batch
     */
    v4_idxr_ = indexer::factory(PDS_MAX_ROUTE_TABLE + 1);
    SDK_ASSERT(v4_idxr_ != NULL);
    v6_idxr_ = indexer::factory(PDS_MAX_ROUTE_TABLE + 1);
    SDK_ASSERT(v6_idxr_ != NULL);
    v4_region_addr_ = state->mempartition()->start_addr("lpm_v4");
    v4_table_size_ = state->mempartition()->block_size("lpm_v4");
    v4_max_routes_ = state->mempartition()->max_elements("lpm_v4") - 1;
    v6_region_addr_ = state->mempartition()->start_addr("lpm_v6");
    v6_table_size_ = state->mempartition()->block_size("lpm_v6");
    v6_max_routes_ = state->mempartition()->max_elements("lpm_v6") - 1;
}

/**
 * @brief    destructor
 */
route_table_impl_state::~route_table_impl_state() {
    indexer::destroy(v4_idxr_);
    indexer::destroy(v6_idxr_);
}

/**
 * @brief    API to initiate transaction over all the table manamgement
 *           library instances
 * @return    SDK_RET_OK on success, failure status code on error
 */
sdk_ret_t
route_table_impl_state::table_transaction_begin(void) {
    //v4_idxr_->txn_start();
    //v6_idxr_->txn_start();
    return SDK_RET_OK;
}

/**
 * @brief    API to end transaction over all the table manamgement
 *           library instances
 * @return    SDK_RET_OK on success, failure status code on error
 */
sdk_ret_t
route_table_impl_state::table_transaction_end(void) {
    //v4_idxr_->txn_end();
    //v6_idxr_->txn_end();
    return SDK_RET_OK;
}

/** @} */    // end of PDS_ROUTE_TABLE_IMPL_STATE

}    // namespace impl
}    // namespace api
