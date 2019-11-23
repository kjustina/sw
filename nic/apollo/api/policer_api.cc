//
// {C} Copyright 2019 Pensando Systems Inc. All rights reserved
//
//----------------------------------------------------------------------------
///
/// \file
/// This file implements policer CRUD APIs
///
//----------------------------------------------------------------------------

#include "nic/apollo/framework/api_base.hpp"
#include "nic/apollo/framework/api_msg.hpp"
#include "nic/apollo/framework/api_engine.hpp"
#include "nic/apollo/framework/api_params.hpp"
#include "nic/apollo/api/obj_api.hpp"
#include "nic/apollo/api/pds_state.hpp"
#include "nic/apollo/api/policer.hpp"
#include "nic/apollo/api/policer_state.hpp"

static sdk::sdk_ret_t
pds_policer_api_handle (pds_batch_ctxt_t bctxt, api_op_t op,
                       pds_policer_key_t *key, pds_policer_spec_t *spec)
{
    sdk_ret_t rv;
    api_ctxt_t *api_ctxt;

    if ((rv = pds_obj_api_validate(op, key, spec)) != sdk::SDK_RET_OK)
        return rv;

    // allocate API context
    api_ctxt = api::api_ctxt_alloc(OBJ_ID_SUBNET, op);
    if (likely(api_ctxt != NULL)) {
        if (op == API_OP_DELETE) {
            api_ctxt->api_params->policer_key = *key;
        } else {
            api_ctxt->api_params->policer_spec = *spec;
        }
        return process_api(bctxt, api_ctxt);
    }
    return SDK_RET_OOM;
}

static inline sdk::sdk_ret_t
pds_policer_stats_fill (pds_policer_stats_t *stats, policer_entry *entry)
{
    return SDK_RET_INVALID_OP;
}

static inline sdk::sdk_ret_t
pds_policer_status_fill (pds_policer_status_t *status, policer_entry *entry)
{
    return SDK_RET_INVALID_OP;
}

static inline sdk::sdk_ret_t
pds_policer_spec_fill (pds_policer_spec_t *spec, policer_entry *entry)
{
    return SDK_RET_INVALID_OP;
}

static inline policer_entry *
pds_policer_entry_find (pds_policer_key_t *key)
{
    return (policer_db()->find(key));
}

//----------------------------------------------------------------------------
// policer API entry point implementation
//----------------------------------------------------------------------------

sdk::sdk_ret_t
pds_policer_create (_In_ pds_policer_spec_t *spec, _In_ pds_batch_ctxt_t bctxt)
{
    return pds_policer_api_handle(bctxt, API_OP_CREATE, NULL, spec);
}

sdk::sdk_ret_t
pds_policer_read (pds_policer_key_t *key, pds_policer_info_t *info)
{
    sdk::sdk_ret_t rv;
    policer_entry *entry = NULL;

    if (key == NULL || info == NULL) {
        return sdk::SDK_RET_INVALID_ARG;
    }

    if ((entry = pds_policer_entry_find(key)) == NULL) {
        return sdk::SDK_RET_ENTRY_NOT_FOUND;
    }

    if ((rv = pds_policer_spec_fill(&info->spec, entry)) != sdk::SDK_RET_OK) {
        return rv;
    }

    info->spec.key = *key;
    if ((rv = pds_policer_status_fill(&info->status, entry)) !=
            sdk::SDK_RET_OK) {
        return rv;
    }

    if ((rv = pds_policer_stats_fill(&info->stats, entry)) != sdk::SDK_RET_OK) {
        return rv;
    }

    if ((rv = entry->read(key, info)) != sdk::SDK_RET_OK) {
        return rv;
    }

    return sdk::SDK_RET_OK;
}

sdk::sdk_ret_t
pds_policer_update (_In_ pds_policer_spec_t *spec, _In_ pds_batch_ctxt_t bctxt)
{
    return pds_policer_api_handle(bctxt, API_OP_UPDATE, NULL, spec);
}

sdk::sdk_ret_t
pds_policer_delete (_In_ pds_policer_key_t *key, _In_ pds_batch_ctxt_t bctxt)
{
    return pds_policer_api_handle(bctxt, API_OP_DELETE, key, NULL);
}
