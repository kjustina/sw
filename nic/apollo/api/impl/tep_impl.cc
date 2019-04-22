/**
 * Copyright (c) 2018 Pensando Systems, Inc.
 *
 * @file    tep_impl.cc
 *
 * @brief   datapath implementation of tep
 */

#include "nic/sdk/lib/utils/utils.hpp"
#include "nic/apollo/core/mem.hpp"
#include "nic/apollo/core/trace.hpp"
#include "nic/apollo/framework/api_engine.hpp"
#include "nic/apollo/api/tep.hpp"
#include "nic/apollo/api/impl/tep_impl.hpp"
#include "nic/apollo/api/impl/pds_impl_state.hpp"

namespace api {
namespace impl {

/// \defgroup PDS_TEP_IMPL - tep entry datapath implementation
/// \ingroup PDS_TEP
/// @{

#define tep_tx_mpls_udp_action    action_u.tep_tx_mpls_udp_tep_tx
#define tep_tx_vxlan_action       action_u.tep_tx_vxlan_tep_tx
#define nh_tx_action              action_u.nexthop_tx_nexthop_info

tep_impl *
tep_impl::factory(pds_tep_spec_t *pds_tep) {
    tep_impl *impl;

    // TODO: move to slab later
    impl = (tep_impl *)SDK_CALLOC(SDK_MEM_ALLOC_PDS_TEP_IMPL,
                                  sizeof(tep_impl));
    new (impl) tep_impl();
    return impl;
}

void
tep_impl::destroy(tep_impl *impl) {
    impl->~tep_impl();
    SDK_FREE(SDK_MEM_ALLOC_PDS_TEP_IMPL, impl);
}

sdk_ret_t
tep_impl::reserve_resources(api_base *orig_obj, obj_ctxt_t *obj_ctxt) {
    sdk_ret_t ret;
    uint32_t idx;

    // reserve an entry in TEP_TX table
    ret = tep_impl_db()->tep_tx_tbl()->reserve(&idx);
    if (ret != SDK_RET_OK) {
        PDS_TRACE_ERR("Failed to reserve entry in TEP_TX table, err %u", ret);
        return ret;
    }
    hw_id_ = idx & 0xFFFF;

    // reserve an entry in NH_TX table
    ret = tep_impl_db()->nh_tx_tbl()->reserve(&idx);
    if (ret != SDK_RET_OK) {
        PDS_TRACE_ERR("Failed to reserve entry in NH_TX table, err %u", ret);

        return ret;
    }
    nh_id_ = idx & 0xFFFF;
    return SDK_RET_OK;
}

sdk_ret_t
tep_impl::release_resources(api_base *api_obj) {
    if (hw_id_ != 0xFFFF) {
        tep_impl_db()->tep_tx_tbl()->release(hw_id_);
        hw_id_ = 0xFFFF;
    }
    if (nh_id_ != 0xFFFF) {
        tep_impl_db()->nh_tx_tbl()->release(nh_id_);
        nh_id_ = 0xFFFF;
    }
    return SDK_RET_OK;
}

sdk_ret_t
tep_impl::nuke_resources(api_base *api_obj) {
    if (hw_id_ != 0xFFFF) {
        tep_impl_db()->tep_tx_tbl()->remove(hw_id_);
        hw_id_ = 0xFFFF;
    }
    if (nh_id_ != 0xFFFF) {
        tep_impl_db()->nh_tx_tbl()->remove(nh_id_);
        nh_id_ = 0xFFFF;
    }
    return SDK_RET_OK;
}

sdk_ret_t
tep_impl::program_hw(api_base *api_obj, obj_ctxt_t *obj_ctxt) {
    sdk_ret_t                  ret;
    pds_tep_spec_t             *tep_spec;
    tep_tx_actiondata_t        tep_tx_data = { 0 };
    nexthop_tx_actiondata_t    nh_tx_data = { 0 };

    // program TEP Tx table
    tep_spec = &obj_ctxt->api_params->tep_spec;
    switch (tep_spec->encap.type) {
    case PDS_ENCAP_TYPE_MPLSoUDP:
        tep_tx_data.action_id = TEP_TX_MPLS_UDP_TEP_TX_ID;
        tep_tx_data.tep_tx_mpls_udp_action.dipo = tep_spec->key.ip_addr;
        memcpy(tep_tx_data.tep_tx_mpls_udp_action.dmac, mac_, ETH_ADDR_LEN);
        break;

    case PDS_ENCAP_TYPE_VXLAN:
        tep_tx_data.action_id = TEP_TX_VXLAN_TEP_TX_ID;
        tep_tx_data.tep_tx_vxlan_action.dipo = tep_spec->key.ip_addr;
        memcpy(tep_tx_data.tep_tx_vxlan_action.dmac, mac_, ETH_ADDR_LEN);
        break;

    default:
        ret = SDK_RET_INVALID_ARG;
        break;
    }
    ret = tep_impl_db()->tep_tx_tbl()->insert_atid(&tep_tx_data, hw_id_);
    if (unlikely(ret != SDK_RET_OK)) {
        PDS_TRACE_ERR("TEP Tx table programming failed for TEP %s, "
                      "TEP hw id %u, err %u", api_obj->key2str().c_str(),
                      hw_id_, ret);
        return ret;
    }

    // program nexthop table
    nh_tx_data.action_id = NEXTHOP_TX_NEXTHOP_INFO_ID;
    nh_tx_data.action_u.nexthop_tx_nexthop_info.tep_index = hw_id_;
    if (tep_spec->nat) {
        nh_tx_data.nh_tx_action.snat_required = 1;
    }
    switch (tep_spec->type) {
    case PDS_TEP_TYPE_IGW:
        nh_tx_data.nh_tx_action.encap_type = GW_ENCAP;
        break;
    case PDS_TEP_TYPE_WORKLOAD:
        nh_tx_data.nh_tx_action.encap_type = VNIC_ENCAP;
        break;
    default:
        break;
    }
    if (tep_spec->encap.type != PDS_ENCAP_TYPE_NONE) {
        nh_tx_data.action_u.nexthop_tx_nexthop_info.dst_slot_id =
            tep_spec->encap.val.value;
    }
    ret = tep_impl_db()->nh_tx_tbl()->insert_atid(&nh_tx_data, nh_id_);
    if (unlikely(ret != SDK_RET_OK)) {
        PDS_TRACE_ERR("Nexthop Tx table programming failed for TEP %s, "
                      "nexthop hw id %u, err %u", api_obj->key2str().c_str(),
                      nh_id_, ret);
    }
    PDS_TRACE_DEBUG("Programmed TEP %s, MAC 0x%lx, hw id %u, nexthop id %u",
                    ipv4addr2str(tep_spec->key.ip_addr),
                    PDS_REMOTE_TEP_MAC, hw_id_, nh_id_);
    return ret;
}

sdk_ret_t
tep_impl::cleanup_hw(api_base *api_obj, obj_ctxt_t *obj_ctxt) {
    //TODO: need to update these entries or entries that are pointing to these
    // entries with new epoch and valid bit set to FALSE
    //if (hw_id_ != 0xFFFF) {
    //      tep_impl_db()->tep_tx_tbl()->remove(hw_id_);
    //}
    //if (nh_id_ != 0xFFFF) {
    //    tep_impl_db()->nh_tx_tbl()->remove(nh_id_);
    //}
    return sdk::SDK_RET_OK;
}

sdk_ret_t
tep_impl::update_hw(api_base *orig_obj, api_base *curr_obj,
                    obj_ctxt_t *obj_ctxt) {
    return sdk::SDK_RET_INVALID_OP;
}

void
tep_impl::fill_status_(tep_tx_actiondata_t *tep_tx_data,
                       pds_tep_status_t *status)
{
    status->nh_id = nh_id_;
    status->hw_id = hw_id_;

    switch (tep_tx_data->action_id) {
    case TEP_TX_GRE_TEP_TX_ID:
        sdk::lib::memrev(status->dmac,
                         tep_tx_data->action_u.tep_tx_gre_tep_tx.dmac,
                         ETH_ADDR_LEN);
        break;
    case TEP_TX_MPLS_UDP_TEP_TX_ID:
        sdk::lib::memrev(status->dmac,
                         tep_tx_data->action_u.tep_tx_mpls_udp_tep_tx.dmac,
                         ETH_ADDR_LEN);
        break;
    case TEP_TX_VXLAN_TEP_TX_ID:
        sdk::lib::memrev(status->dmac,
                         tep_tx_data->action_u.tep_tx_vxlan_tep_tx.dmac,
                         ETH_ADDR_LEN);
        break;
    }
}

void
tep_impl::fill_spec_(nexthop_tx_actiondata_t *nh_tx_data,
                     tep_tx_actiondata_t *tep_tx_data, pds_tep_spec_t *spec)
{
    if (tep_tx_data->action_id == TEP_TX_MPLS_UDP_TEP_TX_ID) {
        spec->encap.type = PDS_ENCAP_TYPE_MPLSoUDP;
        spec->key.ip_addr = tep_tx_data->tep_tx_mpls_udp_action.dipo;
        switch (nh_tx_data->nh_tx_action.encap_type) {
        case GW_ENCAP:
            spec->type = PDS_TEP_TYPE_IGW;
            break;
        case VNIC_ENCAP:
            spec->type = PDS_TEP_TYPE_WORKLOAD;
            break;
        }
        spec->encap.val.mpls_tag =
            nh_tx_data->action_u.nexthop_tx_nexthop_info.dst_slot_id;
    } else if (tep_tx_data->action_id == TEP_TX_VXLAN_TEP_TX_ID) {
        spec->encap.type = PDS_ENCAP_TYPE_VXLAN;
        spec->encap.val.vnid =
            nh_tx_data->action_u.nexthop_tx_nexthop_info.dst_slot_id;
        spec->key.ip_addr = tep_tx_data->tep_tx_vxlan_action.dipo;
    }
    spec->nat = nh_tx_data->action_u.nexthop_tx_nexthop_info.snat_required;
}

sdk_ret_t
tep_impl::read_hw(pds_tep_info_t *info) {
    nexthop_tx_actiondata_t nh_tx_data;
    tep_tx_actiondata_t tep_tx_data;

    if (tep_impl_db()->nh_tx_tbl()->retrieve(nh_id_,
                                             &nh_tx_data) != SDK_RET_OK) {
        return sdk::SDK_RET_ENTRY_NOT_FOUND;
    }
    if (tep_impl_db()->tep_tx_tbl()->retrieve(hw_id_,
                                              &tep_tx_data) != SDK_RET_OK) {
        return sdk::SDK_RET_ENTRY_NOT_FOUND;
    }

    fill_spec_(&nh_tx_data, &tep_tx_data, &info->spec);
    fill_status_(&tep_tx_data, &info->status);

    return sdk::SDK_RET_OK;
}

/// \@}    // end of PDS_TEP_IMPL

}    // namespace impl
}    // namespace api
