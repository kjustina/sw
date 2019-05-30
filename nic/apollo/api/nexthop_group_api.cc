//
// {C} Copyright 2019 Pensando Systems Inc. All rights reserved
//
//----------------------------------------------------------------------------
///
/// \file
/// This file implements nexthop CRUD APIs
///
//----------------------------------------------------------------------------

#include "nic/apollo/framework/api_ctxt.hpp"
#include "nic/apollo/framework/api_engine.hpp"
#include "nic/apollo/api/obj_api.hpp"
#include "nic/apollo/api/pds_state.hpp"
#include "nic/apollo/api/nexthop.hpp"
#include "nic/apollo/api/nexthop_group_state.hpp"

static sdk_ret_t
pds_nexthop_group_api_handle (api::api_op_t op, pds_nexthop_group_key_t *key,
                              pds_nexthop_group_spec_t *spec)
{
    sdk_ret_t rv;
    api_ctxt_t api_ctxt;

    if ((rv = pds_obj_api_validate(op, key, spec)) != SDK_RET_OK) {
        return rv;
    }

    api_ctxt.api_params = api::api_params_alloc(api::OBJ_ID_NEXTHOP, op);
    if (likely(api_ctxt.api_params != NULL)) {
        api_ctxt.api_op = op;
        api_ctxt.obj_id = api::OBJ_ID_NEXTHOP;
        if (op == api::API_OP_DELETE) {
            api_ctxt.api_params->nexthop_group_key = *key;
        } else {
            api_ctxt.api_params->nexthop_group_spec = *spec;
        }
        return (api::g_api_engine.process_api(&api_ctxt));
    }
    return SDK_RET_OOM;
}

static inline sdk_ret_t
pds_nexthop_group_stats_fill (nexthop_group *entry,
                              pds_nexthop_group_stats_t *stats)
{
    return SDK_RET_OK;
}

static inline sdk_ret_t
pds_nexthop_group_status_fill (nexthop_group *entry,
                               pds_nexthop_group_status_t *status)
{
    return SDK_RET_OK;
}

static inline sdk_ret_t
pds_nexthop_group_spec_fill (nexthop_group *entry,
                             pds_nexthop_group_spec_t *spec)
{
    return SDK_RET_OK;
}

static inline nexthop_group *
pds_nexthop_group_find (pds_nexthop_group_key_t *key)
{
    return (nexthop_group_db()->find(key));
}

//----------------------------------------------------------------------------
// nexthop API entry point implementation
//----------------------------------------------------------------------------

sdk_ret_t
pds_nexthop_group_create (pds_nexthop_group_spec_t *spec)
{
    return (pds_nexthop_group_api_handle(api::API_OP_CREATE, NULL, spec));
}

sdk_ret_t
pds_nexthop_group_read (pds_nexthop_group_key_t *key,
                        pds_nexthop_group_info_t *info)
{
    sdk_ret_t rv;
    nexthop_group *entry = NULL;

    if (key == NULL || info == NULL) {
        return SDK_RET_INVALID_ARG;
    }

    if ((entry = pds_nexthop_group_find(key)) == NULL) {
        return SDK_RET_ENTRY_NOT_FOUND;
    }

    if ((rv = pds_nexthop_group_spec_fill(entry, &info->spec)) != SDK_RET_OK) {
        return rv;
    }

    if ((rv = pds_nexthop_group_status_fill(entry, &info->status)) !=
             SDK_RET_OK) {
        return rv;
    }

    if ((rv = pds_nexthop_group_stats_fill(entry, &info->stats)) !=
             SDK_RET_OK) {
        return rv;
    }

    return SDK_RET_OK;
}

sdk_ret_t
pds_nexthop_group_update (pds_nexthop_group_spec_t *spec)
{
    return (pds_nexthop_group_api_handle(api::API_OP_UPDATE, NULL, spec));
}

sdk_ret_t
pds_nexthop_group_delete (pds_nexthop_group_key_t *key)
{
    return (pds_nexthop_group_api_handle(api::API_OP_DELETE, key, NULL));
}
