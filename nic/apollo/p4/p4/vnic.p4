/******************************************************************************/
/* VNIC mapping table (by VLAN)                                               */
/******************************************************************************/
action local_vnic_info_common(local_vnic_tag, vcn_id, skip_src_dst_check,
                              resource_group_1, resource_group_2,
                              lpm_v4addr_1, lpm_v4addr_2,
                              lpm_v6addr_1, lpm_v6addr_2,
                              sacl_v4addr_1, sacl_v4addr_2,
                              sacl_v6addr_1, sacl_v6addr_2, epoch1, epoch2) {
    modify_field(scratch_metadata.local_vnic_tag, local_vnic_tag);
    modify_field(vnic_metadata.local_vnic_tag, scratch_metadata.local_vnic_tag);
    modify_field(scratch_metadata.vcn_id, vcn_id);
    modify_field(vnic_metadata.vcn_id, scratch_metadata.vcn_id);
    modify_field(vnic_metadata.skip_src_dst_check, skip_src_dst_check);
    if (service_header.valid == TRUE) {
        if (service_header.epoch == epoch1) {
            modify_field(scratch_metadata.use_epoch1, TRUE);
        } else {
            modify_field(scratch_metadata.use_epoch1, FALSE);
        }
    } else {
        if (epoch1 > epoch2) {
            modify_field(scratch_metadata.use_epoch1, TRUE);
        } else {
            modify_field(scratch_metadata.use_epoch1, FALSE);
        }
    }
    if (scratch_metadata.use_epoch1 == TRUE) {
        modify_field(policer_metadata.resource_group, resource_group_1);
        lpm_init(lpm_v4addr_1, lpm_v6addr_1);
        sacl_init(sacl_v4addr_1, sacl_v6addr_1);
        modify_field(service_header.epoch, epoch1);
    } else {
        modify_field(policer_metadata.resource_group, resource_group_2);
        lpm_init(lpm_v4addr_2, lpm_v6addr_2);
        sacl_init(sacl_v4addr_2, sacl_v6addr_2);
        modify_field(service_header.epoch, epoch2);
    }
}

action local_vnic_info_tx(local_vnic_tag, vcn_id, skip_src_dst_check,
                          resource_group_1, resource_group_2,
                          lpm_v4addr_1, lpm_v4addr_2,
                          lpm_v6addr_1, lpm_v6addr_2,
                          sacl_v4addr_1, sacl_v4addr_2,
                          sacl_v6addr_1, sacl_v6addr_2,
                          epoch1, epoch2, overlay_mac, src_slot_id) {
    // validate source mac
    if (ethernet_1.srcAddr == 0) {
        modify_field(control_metadata.p4i_drop_reason,
                     1 << P4I_DROP_SRC_MAC_ZERO);
        drop_packet();
    }
    if (ethernet_1.srcAddr != overlay_mac) {
        modify_field(control_metadata.p4i_drop_reason,
                     1 << P4I_DROP_SRC_MAC_MISMATCH);
        drop_packet();
    }

    modify_field(p4i_apollo_i2e.src_slot_id, src_slot_id);
    local_vnic_info_common(local_vnic_tag, vcn_id, skip_src_dst_check,
                           resource_group_1, resource_group_2,
                           lpm_v4addr_1, lpm_v4addr_2, lpm_v6addr_1,
                           lpm_v6addr_2, sacl_v4addr_1, sacl_v4addr_2,
                           sacl_v6addr_1, sacl_v6addr_2, epoch1, epoch2);

    // scratch metadata
    modify_field(scratch_metadata.overlay_mac, overlay_mac);
}

action local_vnic_info_rx(local_vnic_tag, vcn_id, skip_src_dst_check,
                          resource_group_1, resource_group_2,
                          sacl_v4addr_1, sacl_v4addr_2,
                          sacl_v6addr_1, sacl_v6addr_2, epoch1, epoch2) {
    // if c1 indicate miss, drop
    //  modify_field(control_metadata.p4i_drop_reason,
    //               1 << P4I_DROP_DST_SLOT_ID_MISS);

    // validate dst ip; mytep_ip is a table constant
    if (ipv4_1.dstAddr != scratch_metadata.mytep_ip) {
        modify_field(control_metadata.p4i_drop_reason,
                     1 << P4I_DROP_TEP_RX_DST_IP_MISMATCH);
        drop_packet();
    }

    modify_field(vnic_metadata.src_slot_id, mpls_src.label);
    local_vnic_info_common(local_vnic_tag, vcn_id, skip_src_dst_check,
                           resource_group_1, resource_group_2,
                           0, 0, 0, 0, sacl_v4addr_1, sacl_v4addr_2,
                           sacl_v6addr_1, sacl_v6addr_2, epoch1, epoch2);
}

@pragma stage 0
table local_vnic_by_vlan_tx {
    reads {
        ctag_1.vid : exact;
    }
    actions {
        local_vnic_info_tx;
    }
    size : LOCAL_VNIC_BY_VLAN_TABLE_SIZE;
}

/******************************************************************************/
/* VNIC mapping table (by slot)                                               */
/******************************************************************************/
/* miss action : drop packet */
@pragma stage 0
table local_vnic_by_slot_rx {
    reads {
        vxlan_1.vni     : exact;
        mpls_dst.label  : exact;
    }
    actions {
        local_vnic_info_rx;
    }
    size : LOCAL_VNIC_BY_SLOT_TABLE_SIZE;
}

@pragma stage 0
@pragma overflow_table local_vnic_by_slot_rx
table local_vnic_by_slot_rx_otcam {
    reads {
        vxlan_1.vni     : ternary;
        mpls_dst.label  : ternary;
    }
    actions {
        local_vnic_info_rx;
    }
    size : LOCAL_VNIC_BY_SLOT_OTCAM_TABLE_SIZE;
}

control ingress_vnic_info {
    if (control_metadata.direction == TX_FROM_HOST) {
        apply(local_vnic_by_vlan_tx);
    } else {
        apply(local_vnic_by_slot_rx);
        apply(local_vnic_by_slot_rx_otcam);
    }
}

action egress_local_vnic_info_rx(vr_mac, overlay_mac, overlay_vlan_id,
                                 subnet_id) {
    // add header towards host
    if (ethernet_2.valid == 1) {
        copy_header(ethernet_0, ethernet_2);
    } else {
        add_header(ethernet_0);
        modify_field(ethernet_0.dstAddr, overlay_mac);
        if ((subnet_id == p4e_apollo_i2e.rvpath_subnet_id) and
            (p4e_apollo_i2e.rvpath_overlay_mac != 0)) {
            modify_field(ethernet_0.srcAddr, p4e_apollo_i2e.rvpath_overlay_mac);
        } else {
            modify_field(ethernet_0.srcAddr, vr_mac);
        }
    }

    if (overlay_vlan_id != 0) {
        add_header(ctag_0);
        modify_field(ctag_0.vid, overlay_vlan_id);
        if (ipv4_2.valid == TRUE) {
            modify_field(ctag_0.etherType, ETHERTYPE_IPV4);
        } else {
            if (ipv6_2.valid == TRUE) {
                modify_field(ctag_0.etherType, ETHERTYPE_IPV6);
            }
            // TODO: what happens to non-ip packets ?
        }
        modify_field(ethernet_0.etherType, ETHERTYPE_CTAG);
    } else {
        if (ipv4_2.valid == TRUE) {
            modify_field(ethernet_0.etherType, ETHERTYPE_IPV4);
        } else {
            if (ipv6_2.valid == TRUE) {
                modify_field(ethernet_0.etherType, ETHERTYPE_IPV6);
            }
            // TODO: what happens to non-ip packets ?
        }
    }

    // remove headers
    remove_header(ethernet_1);
    remove_header(ethernet_2);
    remove_header(ipv4_1);
    remove_header(ipv6_1);
    remove_header(gre_1);
    remove_header(vxlan_1);
    remove_header(mpls_src);
    remove_header(mpls_dst);

    // scratch metadata
    modify_field(scratch_metadata.subnet_id, subnet_id);
}

@pragma stage 0
@pragma index_table
table egress_local_vnic_info_rx {
    reads {
        p4e_apollo_i2e.local_vnic_tag   : exact;
    }
    actions {
        egress_local_vnic_info_rx;
    }
    size : EGRESS_LOCAL_VNIC_INFO_TABLE_SIZE;
}

control egress_vnic_info {
    if (control_metadata.direction == RX_FROM_SWITCH) {
        apply(egress_local_vnic_info_rx);
    }
}
