//------------------------------------------------------------------------------
// {C} Copyright 2019 Pensando Systems Inc. All rights reserved
// -----------------------------------------------------------------------------

#include "nic/apollo/agent/core/state.hpp"
#include "nic/apollo/agent/core/vpc.hpp"
#include "nic/apollo/agent/trace.hpp"

namespace core {

static inline sdk_ret_t
vpc_create_validate (pds_vcn_spec_t *spec)
{
    switch (spec->type) {
    case PDS_VCN_TYPE_SUBSTRATE:
        if (agent_state::state()->substrate_vpc_id() != PDS_VCN_ID_INVALID) {
            PDS_TRACE_ERR("Failed to create vpc %u, only one subtrate vpc allowed", spec->key.id);
            return SDK_RET_ENTRY_EXISTS;
        }
        break;
    case PDS_VCN_TYPE_TENANT:
        break;
    default:
        PDS_TRACE_ERR("Failed to create vpc %u, invalid type %u", spec->key.id, spec->type);
        return SDK_RET_INVALID_ARG; 
    }
    return SDK_RET_OK;
}

sdk_ret_t
vpc_create (pds_vcn_key_t *key, pds_vcn_spec_t *spec)
{
    sdk_ret_t ret;

    if (agent_state::state()->find_in_vpc_db(key) != NULL) {
        PDS_TRACE_ERR("Failed to create vpc %u, vpc exists already", spec->key.id);
        return SDK_RET_ENTRY_EXISTS;
    }
    if ((ret = vpc_create_validate(spec)) != SDK_RET_OK) {
        PDS_TRACE_ERR("Failed to create vpc %u, err %u", spec->key.id, ret);
        return ret;
    }
    if (!agent_state::state()->pds_mock_mode()) {
        if ((ret = pds_vcn_create(spec)) != SDK_RET_OK) {
            PDS_TRACE_ERR("Failed to create vpc %u, err %u", spec->key.id, ret);
            return ret;
        }
    }
    if ((ret = agent_state::state()->add_to_vpc_db(key, spec)) != SDK_RET_OK) {
        PDS_TRACE_ERR("Failed to add vpc %u to db, err %u", spec->key.id, ret);
        return ret;
    }
    if (spec->type == PDS_VCN_TYPE_SUBSTRATE) {
        agent_state::state()->substrate_vpc_id_set(spec->key.id);
    }
    return SDK_RET_OK;
}

sdk_ret_t
vpc_delete (pds_vcn_key_t *key)
{
    sdk_ret_t ret;
    pds_vcn_spec_t *spec;

    if ((spec = agent_state::state()->find_in_vpc_db(key)) == NULL) {
        PDS_TRACE_ERR("Failed to delete vpc %u, vpc not found", key->id);
        return SDK_RET_ENTRY_NOT_FOUND;
    }
    if (!agent_state::state()->pds_mock_mode()) {
        if ((ret = pds_vcn_delete(key)) != SDK_RET_OK) {
            PDS_TRACE_ERR("Failed to delete vpc %u, err %u", key->id, ret);
            return ret;
        }
    }
    if (spec->type == PDS_VCN_TYPE_SUBSTRATE) {
        agent_state::state()->substrate_vpc_id_reset();
    }
    if (agent_state::state()->del_from_vpc_db(key) == false) {
        PDS_TRACE_ERR("Failed to delete vpc %u from db", key->id);
        return SDK_RET_ERR;
    }
    return SDK_RET_OK;
}

sdk_ret_t
vpc_get (pds_vcn_key_t *key, pds_vcn_info_t *info)
{
    sdk_ret_t ret;
    pds_vcn_spec_t *spec;

    spec = agent_state::state()->find_in_vpc_db(key);
    if (spec == NULL) {
        PDS_TRACE_ERR("Failed to find vpc %u in db", key->id);
        return SDK_RET_ENTRY_NOT_FOUND;
    }

    memcpy(&info->spec, spec, sizeof(pds_vcn_spec_t));
    if (!agent_state::state()->pds_mock_mode()) {
        ret = pds_vcn_read(key, info);
    }
    return ret;
}

static inline sdk_ret_t
vpc_get_all_cb (pds_vcn_spec_t *spec, void *ctxt)
{
    sdk_ret_t ret;
    pds_vcn_info_t info;
    vpc_db_cb_ctxt_t *cb_ctxt = (vpc_db_cb_ctxt_t *)ctxt;

    memcpy(&info.spec, spec, sizeof(pds_vcn_spec_t));
    if (!agent_state::state()->pds_mock_mode()) {
        ret = pds_vcn_read(&spec->key, &info);
    }
    if (ret == SDK_RET_OK) {
        cb_ctxt->cb(&info, cb_ctxt->ctxt);
    }
    return ret;
}

sdk_ret_t
vpc_get_all (vpc_get_cb_t vpc_get_cb, void *ctxt)
{
    vpc_db_cb_ctxt_t cb_ctxt;

    cb_ctxt.cb = vpc_get_cb;
    cb_ctxt.ctxt = ctxt;

    return agent_state::state()->vpc_db_walk(vpc_get_all_cb, &cb_ctxt);
}

}    // namespace core
