/**
 * Copyright (c) 2018 Pensando Systems, Inc.
 *
 * @file    route_impl_state.hpp
 *
 * @brief   route table implementation state
 */
#if !defined (__ROUTE_IMPL_STATE_HPP__)
#define __ROUTE_IMPL_STATEHPP__

#include "nic/sdk/lib/table/directmap/directmap.hpp"
#include "nic/sdk/lib/table/hash/hash.hpp"
#include "nic/apollo/framework/api_base.hpp"
#include "nic/apollo/api/pds_state.hpp"

namespace api {
namespace impl {

/**
 * @defgroup PDS_ROUTE_TABLE_IMPL_STATE - route table impl state functionality
 * @ingroup PDS_ROUTE
 * @{
 */

 /**< forward declaration */
class route_table_impl;

/**
 * @brief    state maintained for route tables
 */
class route_table_impl_state : public obj_base {
public:
    /**< @brief    constructor */
    route_table_impl_state(pds_state *state);

    /**< @brief    destructor */
    ~route_table_impl_state();

    /**< @brief    return LPM region's base/start address in memory */
    mem_addr_t lpm_region_addr(void) const { return lpm_region_addr_; }

    /**< @brief    return per LPM table's size */
    mem_addr_t lpm_table_size(void) const { return lpm_table_size_; }

private:
    indexer *route_table_idxr(void) { return route_table_idxr_; }
    friend class route_table_impl;

private:
    /**< datapath tables for route table */
    indexer       *route_table_idxr_;    /**< indexer to allocate lpm mem block */
    mem_addr_t    lpm_region_addr_;      /**< base address for the LPM region */
    uint32_t      lpm_table_size_;       /**< size of each LPM table */
};

/** * @} */    // end of PDS_ROUTE_TABLE_IMPL_STATE

}    // namespace impl
}    // namespace api

#endif    /** __ROUTE_IMPL_STATE_HPP__ */
