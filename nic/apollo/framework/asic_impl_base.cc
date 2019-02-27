/**
 * Copyright (c) 2018 Pensando Systems, Inc.
 *
 * @file    asic_impl_base.cc
 *
 * @brief   implementation of asic impl methods
 */

#include "nic/apollo/framework/asic_impl_base.hpp"
#include "nic/apollo/api/impl/capri_impl.hpp"

namespace api {
namespace impl {

/**
 * @defgroup PDS_ASIC_IMPL - asic wrapper implementation
 * @ingroup PDS_ASIC
 * @{
 */

/**
 * @brief    factory method to asic impl instance
 * @param[in] asic_cfg    asic information
 * @return    new instance of asic impl or NULL, in case of error
 */
asic_impl_base *
asic_impl_base::factory(asic_cfg_t *asic_cfg) {
    switch (asic_cfg->asic_type) {
        case asic_type_t::SDK_ASIC_TYPE_CAPRI:
        return capri_impl::factory(asic_cfg);

    default:
        break;
    }
    return NULL;
}

/** @} */    // end of PDS_ASIC_IMPL

}    // namespace impl
}    // namespace api
