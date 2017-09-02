#include <base.h>
#include <eth.h>
#include <hal.hpp>
#include <hal_state.hpp>
#include <acl_svc.hpp>
#include <acl.hpp>
#include <pd.hpp>
#include <pd_api.hpp>
#include <acl.pb.h>

namespace hal {

void *
acl_get_key_func (void *entry)
{
    HAL_ASSERT(entry != NULL);
    return (void *)&(((acl_t *)entry)->acl_id);
}

uint32_t
acl_compute_hash_func (void *key, uint32_t ht_size)
{
    return utils::hash_algo::fnv_hash(key, sizeof(acl_id_t)) % ht_size;
}

bool
acl_compare_key_func (void *key1, void *key2)
{
    HAL_ASSERT((key1 != NULL) && (key2 != NULL));
    if (*(acl_id_t *)key1 == *(acl_id_t *)key2) {
        return true;
    }
    return false;
}

void *
acl_get_handle_key_func(void *entry)
{
    HAL_ASSERT(entry != NULL);
    return (void *)&(((acl_t *)entry)->hal_handle);
}

uint32_t
acl_compute_handle_hash_func (void *key, uint32_t ht_size)
{
    return utils::hash_algo::fnv_hash(key, sizeof(hal_handle_t)) % ht_size;
}

bool
acl_compare_handle_key_func (void *key1, void *key2)
{
    HAL_ASSERT((key1 != NULL) && (key2 != NULL));
    if (*(hal_handle_t *)key1 == *(hal_handle_t *)key2) {
        return true;
    }
    return false;
}

//------------------------------------------------------------------------------
// insert this acl in all meta data structures
//------------------------------------------------------------------------------
static inline hal_ret_t
add_acl_to_db (acl_t *acl)
{
    g_hal_state->acl_id_ht()->insert(acl, &acl->ht_ctxt);
    g_hal_state->acl_hal_handle_ht()->insert(acl, &acl->hal_handle_ht_ctxt);
    return HAL_RET_OK;
}

static hal_ret_t
validate_acl_create (AclSpec& spec,
                     AclResponse *rsp)
{
    if (!spec.has_key_or_handle()) {
        HAL_TRACE_ERR("PI-ACL:{}: ACL id not provided",
                      __func__);
        rsp->set_api_status(types::API_STATUS_ACL_ID_INVALID);
        return HAL_RET_INVALID_ARG;
    }

    if (spec.key_or_handle().key_or_handle_case() !=
        acl::AclKeyHandle::kAclId) {
        HAL_TRACE_ERR("PI-ACL:{}: ACL id not provided",
                      __func__);
        rsp->set_api_status(types::API_STATUS_ACL_ID_INVALID);
        return HAL_RET_INVALID_ARG;
    }

    return HAL_RET_OK;
}

static hal_ret_t
validate_l4port_range(uint16_t port_start, uint16_t port_end, 
                      uint16_t *key_p, uint16_t *mask_p)
{
    uint16_t key, mask;

    if (port_end < port_start) {
        return HAL_RET_INVALID_ARG;
    }

    /* The range of ports should be maskable */
    mask = ~(port_start^port_end);
    key = port_start & mask;

    if ((key < port_start) ||
        (((key | ~mask) & 0xffff) > port_end)) {
        return HAL_RET_INVALID_ARG;
    }

    *key_p = key;
    *mask_p = mask;

    return HAL_RET_OK;
}

static hal_ret_t
extract_ip_common (acl_type_e acl_type,
                   acl_ip_match_spec_t *ip_key,
                   acl_ip_match_spec_t *ip_mask,
                   const acl::IPSelector& ip_sel,
                   AclResponse *rsp)
{
    hal_ret_t   ret = HAL_RET_OK;
    uint8_t     tcp_flags_mask = 0;
    uint8_t     tcp_flags = 0;
    uint16_t    port_start, port_end;

    switch(ip_sel.l4_selectors_case()) {
        case acl::IPSelector::kIpProtocol:
            ip_key->ip_proto = ip_sel.ip_protocol();
            ip_mask->ip_proto = 0xff;
            break;
        case acl::IPSelector::kIcmpSelector:
            if (acl_type == ACL_TYPE_IPv6) {
                ip_key->ip_proto = IP_PROTO_ICMPV6;
                ip_mask->ip_proto = 0xff;
            } else {
                ip_key->ip_proto = IP_PROTO_ICMP;
                ip_mask->ip_proto = 0xff;
            }

            ip_key->u.icmp.icmp_code = ip_sel.icmp_selector().icmp_code();
            ip_mask->u.icmp.icmp_code = ip_sel.icmp_selector().icmp_code_mask();

            ip_key->u.icmp.icmp_type = ip_sel.icmp_selector().icmp_type();
            ip_mask->u.icmp.icmp_type = ip_sel.icmp_selector().icmp_type_mask();
            break;
        case acl::IPSelector::kUdpSelector:
            ip_key->ip_proto = IP_PROTO_UDP;
            ip_mask->ip_proto = 0xff;

            if (ip_sel.udp_selector().has_src_port_range()) {
                port_start = ip_sel.udp_selector().src_port_range().port_low();
                port_end = ip_sel.udp_selector().src_port_range().port_high();

                ret = validate_l4port_range(port_start, port_end, 
                                            &ip_key->u.udp.sport,
                                            &ip_mask->u.udp.sport);
                if (ret != HAL_RET_OK) {
                    HAL_TRACE_ERR("PI-ACL:{}: UDP sport range {} to {} cannot be supported"
                                  " Only maskable ranges are supported",
                                  __func__, port_start, port_end);
                    rsp->set_api_status(types::API_STATUS_INVALID_ARG);
                    ret = HAL_RET_INVALID_ARG;
                    goto end;
                }
            }
            if (ip_sel.udp_selector().has_dst_port_range()) {
                port_start = ip_sel.udp_selector().dst_port_range().port_low();
                port_end = ip_sel.udp_selector().dst_port_range().port_high();

                ret = validate_l4port_range(port_start, port_end, 
                                            &ip_key->u.udp.dport,
                                            &ip_mask->u.udp.dport);
                if (ret != HAL_RET_OK) {
                    HAL_TRACE_ERR("PI-ACL:{}: UDP dport range {} to {} cannot be supported"
                                  " Only maskable ranges are supported",
                                  __func__, port_start, port_end);
                    rsp->set_api_status(types::API_STATUS_INVALID_ARG);
                    ret = HAL_RET_INVALID_ARG;
                    goto end;
                }
            }
            break;
        case acl::IPSelector::kTcpSelector:
            ip_key->ip_proto = IP_PROTO_TCP;
            ip_mask->ip_proto = 0xff;

            if (ip_sel.tcp_selector().has_src_port_range()) {

                port_start = ip_sel.tcp_selector().src_port_range().port_low();
                port_end = ip_sel.tcp_selector().src_port_range().port_high();

                ret = validate_l4port_range(port_start, port_end, 
                                            &ip_key->u.tcp.sport,
                                            &ip_mask->u.tcp.sport);
                if (ret != HAL_RET_OK) {
                    HAL_TRACE_ERR("PI-ACL:{}: TCP sport range {} to {} cannot be supported"
                                  " Only maskable ranges are supported",
                                  __func__, port_start, port_end);
                    rsp->set_api_status(types::API_STATUS_INVALID_ARG);
                    ret = HAL_RET_INVALID_ARG;
                    goto end;
                }
                
            }
            if (ip_sel.tcp_selector().has_dst_port_range()) {
                port_start = ip_sel.tcp_selector().dst_port_range().port_low();
                port_end = ip_sel.tcp_selector().dst_port_range().port_high();

                ret = validate_l4port_range(port_start, port_end, 
                                            &ip_key->u.tcp.dport,
                                            &ip_mask->u.tcp.dport);
                if (ret != HAL_RET_OK) {
                    HAL_TRACE_ERR("PI-ACL:{}: TCP dport range {} to {} cannot be supported"
                                  " Only maskable ranges are supported",
                                  __func__, port_start, port_end);
                    rsp->set_api_status(types::API_STATUS_INVALID_ARG);
                    ret = HAL_RET_INVALID_ARG;
                    goto end;
                }
            }

            switch(ip_sel.tcp_selector().tcp_syn_case()) {
                case acl::TCPSelector::kTcpSynSet:
                    tcp_flags |= TCP_FLAG_SYN;
                    tcp_flags_mask |= TCP_FLAG_SYN;
                    break;
                case acl::TCPSelector::kTcpSynClear:
                    tcp_flags_mask |= TCP_FLAG_SYN;
                    break;
                case acl::TCPSelector::TCP_SYN_NOT_SET:
                    break;
            }

            switch(ip_sel.tcp_selector().tcp_ack_case()) {
                case acl::TCPSelector::kTcpAckSet:
                    tcp_flags |= TCP_FLAG_ACK;
                    tcp_flags_mask |= TCP_FLAG_ACK;
                    break;
                case acl::TCPSelector::kTcpAckClear:
                    tcp_flags_mask |= TCP_FLAG_ACK;
                    break;
                case acl::TCPSelector::TCP_ACK_NOT_SET:
                    break;
            }

            switch(ip_sel.tcp_selector().tcp_fin_case()) {
                case acl::TCPSelector::kTcpFinSet:
                    tcp_flags |= TCP_FLAG_FIN;
                    tcp_flags_mask |= TCP_FLAG_FIN;
                    break;
                case acl::TCPSelector::kTcpFinClear:
                    tcp_flags_mask |= TCP_FLAG_FIN;
                    break;
                case acl::TCPSelector::TCP_FIN_NOT_SET:
                    break;
            }

            switch(ip_sel.tcp_selector().tcp_rst_case()) {
                case acl::TCPSelector::kTcpRstSet:
                    tcp_flags |= TCP_FLAG_RST;
                    tcp_flags_mask |= TCP_FLAG_RST;
                    break;
                case acl::TCPSelector::kTcpRstClear:
                    tcp_flags_mask |= TCP_FLAG_RST;
                    break;
                case acl::TCPSelector::TCP_RST_NOT_SET:
                    break;
            }

            switch(ip_sel.tcp_selector().tcp_urg_case()) {
                case acl::TCPSelector::kTcpUrgSet:
                    tcp_flags |= TCP_FLAG_URG;
                    tcp_flags_mask |= TCP_FLAG_URG;
                    break;
                case acl::TCPSelector::kTcpUrgClear:
                    tcp_flags_mask |= TCP_FLAG_URG;
                    break;
                case acl::TCPSelector::TCP_URG_NOT_SET:
                    break;
            }

            ip_key->u.tcp.tcp_flags = tcp_flags;
            ip_mask->u.tcp.tcp_flags = tcp_flags_mask;

            break;
        default:
            break;
    }
end:
    return ret;
}

static acl_type_e
get_acl_type (const acl::AclSelector &sel)
{
    acl_type_e acl_type           = ACL_TYPE_INVALID;
    types::IPAddressFamily src_af = types::IP_AF_NONE;
    types::IPAddressFamily dst_af = types::IP_AF_NONE;
    types::IPAddressFamily ip_af  = types::IP_AF_NONE;

    switch(sel.pkt_selector_case()) {
        case acl::AclSelector::kEthSelector:
            acl_type = ACL_TYPE_ETH;
            break;
        case acl::AclSelector::kIpSelector:

            ip_af = sel.ip_selector().ip_af();

            if (sel.ip_selector().has_src_prefix()) {
                src_af = sel.ip_selector().src_prefix().address().ip_af();
            }
            if (sel.ip_selector().has_dst_prefix()) {
                dst_af = sel.ip_selector().dst_prefix().address().ip_af();
            }

            if (ip_af == types::IP_AF_NONE) {
                if ((src_af != types::IP_AF_NONE) ||
                    (dst_af != types::IP_AF_NONE)) {
                    acl_type = ACL_TYPE_INVALID;
                } else {
                    acl_type = ACL_TYPE_IP;
                }
            } else if (ip_af == types::IP_AF_INET) {
                if ((src_af == types::IP_AF_INET6) ||
                    (dst_af == types::IP_AF_INET6)) {
                    acl_type = ACL_TYPE_INVALID;
                } else {
                    acl_type = ACL_TYPE_IPv4;
                }
            } else if (ip_af == types::IP_AF_INET6) {
                if ((src_af == types::IP_AF_INET) ||
                    (dst_af == types::IP_AF_INET)) {
                    acl_type = ACL_TYPE_INVALID;
                } else {
                    acl_type = ACL_TYPE_IPv6;
                }
            }
            break;
        default:
            acl_type = ACL_TYPE_NONE;
            break;
    }
    return acl_type;
}

static hal_ret_t
extract_match_spec (acl_match_spec_t *ms,
                    const acl::AclSelector &sel,
                    AclResponse *rsp)
{
    hal_ret_t            ret = HAL_RET_OK;
    if_t                 *src_if = NULL;
    if_id_t              src_if_id;
    hal_handle_t         src_if_handle = 0;
    if_t                 *dest_if = NULL;
    if_id_t              dest_if_id;
    hal_handle_t         dest_if_handle = 0;
    l2seg_t              *l2seg = NULL;
    l2seg_id_t           l2seg_id;
    hal_handle_t         l2seg_handle = 0;
    acl_eth_match_spec_t *eth_key;
    acl_eth_match_spec_t *eth_mask;
    acl_ip_match_spec_t  *ip_key;
    acl_ip_match_spec_t  *ip_mask;

    eth_key = &ms->key.eth;
    eth_mask = &ms->mask.eth;
    ip_key = &ms->key.ip;
    ip_mask = &ms->mask.ip;

    if (sel.has_src_if_key_handle()) {
        ms->src_if_match = true;

        auto src_if_kh = sel.src_if_key_handle();
        if (src_if_kh.key_or_handle_case() == intf::InterfaceKeyHandle::kInterfaceId) {
            src_if_id = src_if_kh.interface_id();
            src_if = find_if_by_id(src_if_id);
        } else {
            src_if_handle = src_if_kh.if_handle();
            src_if = find_if_by_handle(src_if_handle);
        }

        if(src_if == NULL) {
            HAL_TRACE_ERR("PI-ACL:{}: Source interface not found",
                          __func__);
            rsp->set_api_status(types::API_STATUS_INTERFACE_NOT_FOUND);
            ret = HAL_RET_IF_NOT_FOUND;
            goto end;
        } else {
            ms->src_if_handle = src_if->hal_handle;
        }
    }

    if (sel.has_dst_if_key_handle()) {
        ms->dest_if_match = true;

        auto dest_if_kh = sel.dst_if_key_handle();
        if (dest_if_kh.key_or_handle_case() == intf::InterfaceKeyHandle::kInterfaceId) {
            dest_if_id = dest_if_kh.interface_id();
            dest_if = find_if_by_id(dest_if_id);
        } else {
            dest_if_handle = dest_if_kh.if_handle();
            dest_if = find_if_by_handle(dest_if_handle);
        }

        if(dest_if == NULL) {
            HAL_TRACE_ERR("PI-ACL:{}: Destination interface not found",
                          __func__);
            rsp->set_api_status(types::API_STATUS_INTERFACE_NOT_FOUND);
            ret = HAL_RET_IF_NOT_FOUND;
            goto end;
        } else {
            ms->dest_if_handle = dest_if->hal_handle;
        }
    }

    if (sel.has_l2segment_key_handle()) {
        ms->l2seg_match = true;

        auto l2seg_kh = sel.l2segment_key_handle();
        if (l2seg_kh.key_or_handle_case() == l2segment::L2SegmentKeyHandle::kSegmentId) {
            l2seg_id = l2seg_kh.segment_id();
            l2seg = find_l2seg_by_id(l2seg_id);
        } else {
            l2seg_handle = l2seg_kh.l2segment_handle();
            l2seg = find_l2seg_by_handle(l2seg_handle);
        }

        if(l2seg == NULL) {
            HAL_TRACE_ERR("PI-ACL:{}: L2 segment not found",
                          __func__);
            rsp->set_api_status(types::API_STATUS_L2_SEGMENT_NOT_FOUND);
            ret = HAL_RET_L2SEG_NOT_FOUND;
            goto end;
        } else {
            ms->l2seg_handle = l2seg->hal_handle;
        }
    }

    // Figure out the acl-type
    ms->acl_type = get_acl_type(sel);

    switch(ms->acl_type) {
        case ACL_TYPE_NONE:
            // Nothing to do
            break;
        case ACL_TYPE_ETH:
            eth_key->ether_type = sel.eth_selector().eth_type();
            eth_mask->ether_type = sel.eth_selector().eth_type_mask(); 

            MAC_UINT64_TO_ADDR(eth_key->mac_sa, sel.eth_selector().src_mac());
            MAC_UINT64_TO_ADDR(eth_mask->mac_sa, sel.eth_selector().src_mac_mask());

            MAC_UINT64_TO_ADDR(eth_key->mac_da, sel.eth_selector().dst_mac());
            MAC_UINT64_TO_ADDR(eth_mask->mac_da, sel.eth_selector().dst_mac_mask());
            break;
        case ACL_TYPE_IP:
            ret = extract_ip_common(ms->acl_type, ip_key, ip_mask, 
                                    sel.ip_selector(), rsp);
            break;
        case ACL_TYPE_IPv4:
            if (sel.ip_selector().has_src_prefix()) {
                ip_key->sip.addr.v4_addr = sel.ip_selector().src_prefix().address().v4_addr();
                // Convert prefix len to mask
                ip_mask->sip.addr.v4_addr = ipv4_prefix_len_to_mask(
                    sel.ip_selector().src_prefix().prefix_len());
            }

            if (sel.ip_selector().has_dst_prefix()) {
                ip_key->dip.addr.v4_addr = sel.ip_selector().dst_prefix().address().v4_addr();
                // Convert prefix len to mask
                ip_mask->dip.addr.v4_addr = ipv4_prefix_len_to_mask(
                    sel.ip_selector().dst_prefix().prefix_len());
            }

            ret = extract_ip_common(ms->acl_type, ip_key, ip_mask, 
                                    sel.ip_selector(), rsp);
            break;
        case ACL_TYPE_IPv6:
            if (sel.ip_selector().has_src_prefix()) {
                memcpy(ip_key->sip.addr.v6_addr.addr8,
                       sel.ip_selector().src_prefix().address().v6_addr().c_str(),
                       IP6_ADDR8_LEN);
                // Convert prefix len to mask
                ipv6_prefix_len_to_mask(&ip_mask->sip.addr.v6_addr,
                                        sel.ip_selector().src_prefix().prefix_len());
            }

            if (sel.ip_selector().has_dst_prefix()) {
                memcpy(ip_key->dip.addr.v6_addr.addr8,
                       sel.ip_selector().dst_prefix().address().v6_addr().c_str(),
                       IP6_ADDR8_LEN);
                // Convert prefix len to mask
                ipv6_prefix_len_to_mask(&ip_mask->dip.addr.v6_addr,
                                        sel.ip_selector().dst_prefix().prefix_len());
            }

            ret = extract_ip_common(ms->acl_type, ip_key, ip_mask, 
                                    sel.ip_selector(), rsp);
            break;
        case ACL_TYPE_INVALID:
            HAL_TRACE_ERR("PI-ACL:{}: ACL Type invalid",
                          __func__);
            rsp->set_api_status(types::API_STATUS_INVALID_ARG);
            ret = HAL_RET_INVALID_ARG;
            break;
    }

end:
    return ret;
}

static hal_ret_t
extract_action_spec (acl_action_spec_t *as,
                    const acl::AclActionInfo &ainfo,
                    AclResponse *rsp)
{
    hal_ret_t ret = HAL_RET_OK;

    as->action = ainfo.action();
    as->ing_mirror_en = ainfo.ing_mirror_en();
    as->ing_mirror_session_handle = ainfo.ing_mirror_session_handle();
    as->egr_mirror_en = ainfo.egr_mirror_en();;
    as->egr_mirror_session_handle = ainfo.egr_mirror_session_handle();
    as->copp_policer_handle = ainfo.copp_policer_handle();
    return ret;
}

hal_ret_t
acl_create (AclSpec& spec,
            AclResponse *rsp)
{
    hal_ret_t             ret = HAL_RET_OK;
    acl_t             *acl;
    pd::pd_acl_args_t pd_acl_args;

    HAL_TRACE_DEBUG("--------------------- API Start ------------------------");
    HAL_TRACE_DEBUG("PI-ACL:{}: Acl create ", __func__);

    ret = validate_acl_create(spec, rsp);
    if (ret != HAL_RET_OK) {
        HAL_TRACE_ERR("PI-ACL:{}: Acl create request validation failed."
                      " Err: {}",
                      __func__, HAL_RET_INVALID_ARG);
        return ret;
    }

    HAL_TRACE_DEBUG("PI-ACL:{}: Acl create for id {}",
                    __func__, spec.key_or_handle().acl_id());

    // allocate a acl instance
    acl = acl_alloc_init();
    if (acl == NULL) {
        HAL_TRACE_ERR("PI-ACL:{}: Out of Memory. Err: {}",
                      __func__, HAL_RET_OOM);
        rsp->set_api_status(types::API_STATUS_OUT_OF_MEM);
        ret = HAL_RET_OOM;
        goto end;
    }

    // save the configs from the spec
    acl->acl_id = spec.key_or_handle().acl_id();
    acl->hal_handle = hal_alloc_handle();

    acl->priority = spec.priority();
    ret = extract_match_spec(&acl->match_spec, spec.match(), rsp);
    if (ret != HAL_RET_OK) {
        HAL_TRACE_ERR("PI-ACL:{}: Acl create request match parsing failed."
                      " Err: {}",
                      __func__, ret);
        goto end;
    }

    ret = extract_action_spec(&acl->action_spec, spec.action(), rsp);
    if (ret != HAL_RET_OK) {
        HAL_TRACE_ERR("PI-ACL:{}: Acl create request action parsing failed."
                      " Err: {}",
                      __func__, ret);
        goto end;
    }

    // allocate PD resources and program hardware
    pd::pd_acl_args_init(&pd_acl_args);
    pd_acl_args.acl = acl;
    ret = pd::pd_acl_create(&pd_acl_args);
    if (ret != HAL_RET_OK) {
        HAL_TRACE_ERR("PD acl create failure, err : {}", ret);
        rsp->set_api_status(types::API_STATUS_HW_PROG_ERR);
        goto end;
    }

    // add this acl to the db
    add_acl_to_db(acl);
    rsp->set_api_status(types::API_STATUS_OK);
    rsp->mutable_status()->mutable_acl_handle()->set_handle(acl->hal_handle);

end:

    if (ret != HAL_RET_OK && acl != NULL) {
        acl_free(acl);
    }
    HAL_TRACE_DEBUG("----------------------- API End ------------------------");
    return ret;
}

hal_ret_t
acl_update (AclSpec& spec,
            AclResponse *rsp)
{
    return HAL_RET_OK;
}

}    // namespace hal
