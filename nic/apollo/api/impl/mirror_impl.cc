//
// {C} Copyright 2019 Pensando Systems Inc. All rights reserved
//
//----------------------------------------------------------------------------
///
/// \file
/// datapath implementation of mirror APIs
///
//----------------------------------------------------------------------------

#include "nic/apollo/core/mem.hpp"
#include "nic/apollo/core/trace.hpp"
#include "nic/apollo/framework/api_engine.hpp"
#include "nic/apollo/api/impl/tep_impl.hpp"
#include "nic/apollo/api/impl/mapping_impl.hpp"
#include "nic/apollo/api/impl/mirror_impl.hpp"
#include "nic/apollo/api/impl/pds_impl_state.hpp"
#include "nic/apollo/api/pds_state.hpp"
#include "nic/sdk/lib/p4/p4_api.hpp"

namespace api {
namespace impl {

/// \defgroup PDS_MIRROR_IMPL - mirror entry datapath implementation
/// \ingroup PDS_MIRROR
/// \@{

mirror_impl *
mirror_impl::factory(pds_mirror_session_spec_t *spec) {
    mirror_impl *impl;

    impl = mirror_impl_db()->alloc();
    new (impl) mirror_impl();
    return impl;
}

void
mirror_impl::soft_delete(mirror_impl *impl) {
    impl->~mirror_impl();
    mirror_impl_db()->free(impl);
}

mirror_impl *
mirror_impl::build(pds_mirror_session_key_t *key) {
    mirror_impl *impl;
    p4pd_error_t p4pd_ret;
    uint32_t hw_id = key->id - 1;
    mirror_actiondata_t mirror_data = { 0 };

    if (hw_id > (PDS_MAX_MIRROR_SESSION - 1)) {
        return NULL;
    }
    p4pd_ret = p4pd_global_entry_read(P4TBL_ID_MIRROR, hw_id, NULL, NULL,
                                       &mirror_data);
    if (p4pd_ret != P4PD_SUCCESS) {
        PDS_TRACE_ERR("Failed to read mirror session %u at idx %u",
                      key->id, hw_id);
        return NULL;
    }

    impl = mirror_impl_db()->alloc();
    if (unlikely(impl == NULL)) {
        return NULL;
    }
    new (impl) mirror_impl();
    impl->hw_id_ = hw_id;
    return impl;
}

void
mirror_impl::destroy(mirror_impl *impl) {
    mirror_impl::soft_delete(impl);
}

sdk_ret_t
mirror_impl::reserve_resources(api_base *orig_obj, obj_ctxt_t *obj_ctxt) {
    pds_mirror_session_spec_t *spec;

    // allocate hw id for this session
    spec = &obj_ctxt->api_params->mirror_session_spec;
    return mirror_impl_db()->alloc_hw_id(&spec->key, &hw_id_);
}

sdk_ret_t
mirror_impl::nuke_resources(api_base *api_obj) {
    if (hw_id_ != 0xFFFF) {
        return mirror_impl_db()->free_hw_id(hw_id_);
    }
    return SDK_RET_OK;
}

sdk_ret_t
mirror_impl::release_resources(api_base *api_obj) {
    if (hw_id_ != 0xFFFF) {
        return mirror_impl_db()->free_hw_id(hw_id_);
    }
    return SDK_RET_OK;
}

#define rspan_action     action_u.mirror_rspan
#define erspan_action    action_u.mirror_erspan
sdk_ret_t
mirror_impl::program_hw(api_base *api_obj, obj_ctxt_t *obj_ctxt) {
    vpc_entry *vpc;
    tep_entry *tep;
    mac_addr_t mac;
    pds_tep_key_t tep_key;
    p4pd_error_t p4pd_ret;
    mapping_entry *mapping;
    pds_mapping_key_t mapping_key;
    pds_mirror_session_spec_t *spec;
    mirror_actiondata_t mirror_data = { 0 };

    spec = &obj_ctxt->api_params->mirror_session_spec;
    switch (spec->type) {
    case PDS_MIRROR_SESSION_TYPE_RSPAN:
        mirror_data.action_id = MIRROR_RSPAN_ID;
        mirror_data.rspan_action.tm_oport =
            g_pds_state.catalogue()->ifindex_to_tm_port(spec->rspan_spec.interface);
        mirror_data.rspan_action.ctag = spec->rspan_spec.encap.val.vlan_tag;
        mirror_data.rspan_action.truncate_len = spec->snap_len;
        break;

    case PDS_MIRROR_SESSION_TYPE_ERSPAN:
        mirror_data.action_id = MIRROR_ERSPAN_ID;
        vpc = vpc_db()->find(&spec->erspan_spec.vpc);

        // if the vpc is substrate VPC, dst IP must be a known TEP
        if (vpc->type() == PDS_VPC_TYPE_SUBSTRATE) {
            tep_key.ip_addr = spec->erspan_spec.dst_ip.addr.v4_addr;
            if ((tep = tep_db()->find(&tep_key)) == NULL) {
                PDS_TRACE_ERR("Unknown TEP IP %s", ipv4addr2str(tep_key.ip_addr));
                return SDK_RET_INVALID_ARG;
            }
            // TODO: what if this TEP is local TEP itself ?
            mirror_data.erspan_action.tm_oport = TM_PORT_UPLINK_1;
            mirror_data.erspan_action.ctag = 0;
            memcpy(mirror_data.erspan_action.dmac,
                   ((tep_impl *)(tep->impl()))->mac(), ETH_ADDR_LEN);
            memcpy(mirror_data.erspan_action.smac,
                   device_db()->find()->mac(), ETH_ADDR_LEN);
            mirror_data.erspan_action.sip = spec->erspan_spec.src_ip.addr.v4_addr;
            mirror_data.erspan_action.dip = spec->erspan_spec.dst_ip.addr.v4_addr;
            mirror_data.erspan_action.truncate_len = spec->snap_len;
        } else {
#if 0
            mapping_key.vpc = spec->erspan_spec.vpc;
            mapping_key.ip_addr = spec->erspan_spec.dst_ip;
            mapping = mapping_entry::build(&mapping_key);
            if (mapping == NULL) {
                PDS_TRACE_ERR("Failed to find mapping entry for (%u, %s)",
                              mapping_key.vpc.id, ipaddr2str(&mapping_key.ip_addr));
                return SDK_RET_INVALID_ARG;
            }


            if (((mapping_impl *)(mapping->impl()))->is_local()) {
                mirror_data.erspan_action.tm_oport = TM_PORT_UPLINK_0;
                mirror_data.erspan_action.ctag =
                    spec->erspan_spec.encap.val.vlan_tag;
            } else {
                mirror_data.erspan_action.tm_oport = TM_PORT_UPLINK_1;
                // substrate VLAN tag is 0, hence outer VLAN is 0 when going on the
                // network (both MPLSoUDP and VxLAN cases) port towards the remote
                // mapping
                mirror_data.erspan_action.ctag = 0;
                // get the TEP this mapping is behind and use its MAC address
                mirror_data.erspan_action.dmac = ;
            }
            mirror_data.erspan_action.truncate_len = spec->snap_len;
            //mirror_data.erspan_action.smac = ;
            //mirror_data.erspan_action.sip = ;
            //mirror_data.erspan_action.dip = ;
#endif
        }
        break;

    default:
        return SDK_RET_INVALID_ARG;
    }

    p4pd_ret = p4pd_global_entry_write(P4TBL_ID_MIRROR, hw_id_, NULL, NULL,
                                       &mirror_data);
    if (p4pd_ret != P4PD_SUCCESS) {
        PDS_TRACE_ERR("Failed to program mirror session %u at idx %u",
                      spec->key.id, hw_id_);
        return sdk::SDK_RET_HW_PROGRAM_ERR;
    }
    return SDK_RET_OK;
}

sdk_ret_t
mirror_impl::cleanup_hw(api_base *api_obj, obj_ctxt_t *obj_ctxt) {
    return SDK_RET_OK;
}

sdk_ret_t
mirror_impl::update_hw(api_base *orig_obj, api_base *curr_obj,
                       obj_ctxt_t *obj_ctxt) {
    return sdk::SDK_RET_INVALID_OP;
}

sdk_ret_t
mirror_impl::activate_hw(api_base *api_obj, pds_epoch_t epoch,
                         api_op_t api_op, obj_ctxt_t *obj_ctxt) {
    return SDK_RET_OK;
}

sdk_ret_t
mirror_impl::read_hw(pds_mirror_session_key_t *key,
                     pds_mirror_session_info_t *info) {
    p4pd_error_t p4pd_ret;
    mirror_actiondata_t mirror_data;
    uint16_t hw_id;

    hw_id = key->id-1;
    if ((mirror_impl_db()->session_bmap_ & (1 << hw_id)) == 0) {
        return sdk::SDK_RET_ENTRY_NOT_FOUND;
    }
    p4pd_ret = p4pd_global_entry_read(P4TBL_ID_MIRROR, hw_id, NULL, NULL,
                                      &mirror_data);
    if (p4pd_ret != P4PD_SUCCESS) {
        PDS_TRACE_ERR("Failed to read mirror session %u at idx %u", key->id);
        return sdk::SDK_RET_HW_PROGRAM_ERR;
    }
    info->spec.key.id = key->id;
    switch (mirror_data.action_id) {
    case MIRROR_RSPAN_ID:
        info->spec.type = PDS_MIRROR_SESSION_TYPE_RSPAN;
        info->spec.snap_len = mirror_data.rspan_action.truncate_len;
        info->spec.rspan_spec.interface =
            g_pds_state.catalogue()->tm_port_to_ifindex(mirror_data.rspan_action.tm_oport);
        info->spec.rspan_spec.encap.type = PDS_ENCAP_TYPE_DOT1Q;
        info->spec.rspan_spec.encap.val.vlan_tag =
            mirror_data.rspan_action.ctag;
        break;

    case MIRROR_ERSPAN_ID:
        info->spec.type = PDS_MIRROR_SESSION_TYPE_ERSPAN;
        info->spec.snap_len = mirror_data.erspan_action.truncate_len;
        info->spec.erspan_spec.src_ip.addr.v4_addr = mirror_data.erspan_action.sip;
        info->spec.erspan_spec.dst_ip.addr.v4_addr = mirror_data.erspan_action.dip;
        break;

    default:
        PDS_TRACE_ERR("mirror read operation not supported");
        return sdk::SDK_RET_INVALID_OP;
    }
    return SDK_RET_OK;
}

/// \@}    // end of PDS_MIRROR_IMPL

}    // namespace impl
}    // namespace api
