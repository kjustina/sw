/**
 * Copyright (c) 2018 Pensando Systems, Inc.
 *
 * @file    impl_base.hpp
 *
 * @brief   base object definition for all impl objects
 */

#if !defined (__IMPL_BASE_HPP__)
#define __IMPL_BASE_HPP__

#include "nic/sdk/include/sdk/base.hpp"
#include "nic/hal/apollo/framework/api.hpp"
#include "nic/hal/apollo/framework/obj_base.hpp"
#include "nic/hal/apollo/framework/api_base.hpp"
#include "nic/hal/apollo/framework/impl.hpp"

namespace impl {

/**
 * @brief    base class for all impl objects
 */
class impl_base : public obj_base {
public:
    /**< @brief    constructor */
    impl_base() {}

    /**< @brief    destructor */
    ~impl_base() {}

    /**
     * @brief        factory method to instantiate an impl object
     * @param[in]    impl    object id
     * @param[in]    args    args (not interpreted by this class)
     */
    static impl_base *factory(impl_obj_id_t obj_id, void *args);

    /**
     * @brief    release all the resources associated with this object
     *           and free the memory
     * @param[in] impl_obj    impl instance to be freed
     */
    static void destroy(impl_obj_id_t obj_id, impl_base *impl_obj);

    /**
     * @brief    allocate/reserve h/w resources for this object
     * @return    SDK_RET_OK on success, failure status code on error
     */
    virtual sdk_ret_t alloc_resources(api_base *api_obj) {
        return sdk::SDK_RET_INVALID_OP;
    }

    /**
     * @brief     free h/w resources used by this object, if any
     * @return    SDK_RET_OK on success, failure status code on error
     */
    virtual sdk_ret_t free_resources(api_base *api_obj) {
        return sdk::SDK_RET_INVALID_OP;
    }

    /**
     * @brief    program all h/w tables relevant to this object except stage 0
     *           table(s), if any
     * @param[in] obj_ctxt    transient state associated with this API
     * @return   SDK_RET_OK on success, failure status code on error
     */
    virtual sdk_ret_t program_hw(api_base *api_obj,
                                 obj_ctxt_t *obj_ctxt) {
        return sdk::SDK_RET_INVALID_OP;
    }

    /**
     * @brief    cleanup all h/w tables relevant to this object except stage 0
     *           table(s), if any, by updating packed entries with latest epoch#
     * @param[in] obj_ctxt    transient state associated with this API
     * @return   SDK_RET_OK on success, failure status code on error
     */
    virtual sdk_ret_t cleanup_hw(api_base *api_obj,
                                 obj_ctxt_t *obj_ctxt) {
        return sdk::SDK_RET_INVALID_OP;
    }

    /**
     * @brief    update all h/w tables relevant to this object except stage 0
     *           table(s), if any, by updating packed entries with latest epoch#
     * @param[in] orig_obj    old version of the unmodified object
     * @param[in] curr_obj    cloned and updated version of the object
     * @param[in] obj_ctxt    transient state associated with this API
     * @return   SDK_RET_OK on success, failure status code on error
     */
    virtual sdk_ret_t update_hw(api_base *orig_obj, api_base *curr_obj,
                                obj_ctxt_t *obj_ctxt) {
        return sdk::SDK_RET_INVALID_OP;
    }

    /**
     * @brief    activate the epoch in the dataplane by programming stage 0
     *           tables, if any
     * @param[in] epoch       epoch being activated
     * @param[in] api_op      api operation
     * @param[in] obj_ctxt    transient state associated with this API
     * @return   SDK_RET_OK on success, failure status code on error
     */
    virtual sdk_ret_t activate_hw(api_base *api_obj,
                                  oci_epoch_t epoch,
                                  api_op_t api_op,
                                  obj_ctxt_t *obj_ctxt) {
        return sdk::SDK_RET_INVALID_OP;
    }
};

}    // namespace impl

using impl::impl_base;
 
#endif    /** __IMPL_BASE_HPP__ */
