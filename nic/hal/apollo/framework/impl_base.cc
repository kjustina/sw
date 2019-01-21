/**
 * Copyright (c) 2018 Pensando Systems, Inc.
 *
 * @file    impl_base.cc
 *
 * @brief   base object definition for all impl objects
 */

#include "nic/hal/apollo/framework/impl.hpp"
#include "nic/hal/apollo/framework/impl_base.hpp"
#include "nic/hal/apollo/include/api/oci_switchport.hpp"
#include "nic/hal/apollo/api/impl/switchport_impl.hpp"    // TODO: think how to accomodate a new impl
#include "nic/hal/apollo/api/impl/tep_impl.hpp"
#include "nic/hal/apollo/api/impl/vnic_impl.hpp"
#include "nic/hal/apollo/api/impl/mapping_impl.hpp"
#include "nic/hal/apollo/api/impl/route_impl.hpp"

namespace impl {

asic_impl_base *impl_base::asic_impl_  = NULL;
pipeline_impl_base *impl_base::pipeline_impl_  = NULL;

/**
 * @brief    one time init function that must be called during bring up
 * @param[in]    asic_cfg    asic configuration parameters
 * @return       SDK_RET_OK on success, failure status code on error
 */
sdk_ret_t
impl_base::init(asic_cfg_t *asic_cfg) {
    pipeline_cfg_t        pipeline_cfg;

    asic_impl_ = asic_impl_base::factory(asic_cfg);
    SDK_ASSERT(asic_impl_ != NULL);
    asic_impl_->asic_init();

    pipeline_cfg.name = "apollo";
    pipeline_impl_ = pipeline_impl_base::factory(&pipeline_cfg);
    SDK_ASSERT(pipeline_impl_ != NULL);
    pipeline_impl_->pipeline_init();

    return SDK_RET_OK;
}

/**
 * @brief    dump all the debug information to given file
 * @param[in] fp    file handle
 */
void
impl_base::debug_dump(FILE *fp) {
    asic_impl_->debug_dump(fp);
}

/**
 * @brief        factory method to instantiate an impl object
 * @param[in]    impl    object id
 * @param[in]    args    args (not interpreted by this class)
 */
impl_base *
impl_base::factory(impl_obj_id_t obj_id, void *args) {
    switch (obj_id) {
    case IMPL_OBJ_ID_SWITCHPORT:
        return switchport_impl::factory((oci_switchport_t *)args);

    case IMPL_OBJ_ID_TEP:
        return tep_impl::factory((oci_tep_t *)args);
        break;

    case IMPL_OBJ_ID_VNIC:
        return vnic_impl::factory((oci_vnic_t *)args);
        break;

    case IMPL_OBJ_ID_MAPPING:
        return mapping_impl::factory((oci_mapping_t *)args);
        break;

    case IMPL_OBJ_ID_ROUTE_TABLE:
        return route_table_impl::factory((oci_route_table_t *)args);
        break;

    default:
        break;
    }
    return NULL;
}

/**
 * @brief    release all the resources associated with this object
 *           and free the memory
 * @param[in] impl_obj    impl instance to be freed
 */
void
impl_base::destroy(impl_obj_id_t obj_id, impl_base *impl) {
    switch (obj_id) {
    case IMPL_OBJ_ID_SWITCHPORT:
        return switchport_impl::destroy((switchport_impl *)impl);

    case IMPL_OBJ_ID_TEP:
        return tep_impl::destroy((tep_impl *)impl);

    case IMPL_OBJ_ID_VNIC:
        return vnic_impl::destroy((vnic_impl *)impl);

    case IMPL_OBJ_ID_MAPPING:
        return mapping_impl::destroy((mapping_impl *)impl);

    case IMPL_OBJ_ID_ROUTE_TABLE:
        return route_table_impl::destroy((route_table_impl *)impl);

    default:
        break;
    }
}

}    // namespace impl
