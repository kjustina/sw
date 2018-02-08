/******************************************************************************/
/* Rx pipeline                                                                */
/******************************************************************************/
action rx_vport(vport, rdma_enabled) {
    modify_field(capri_p4_intrinsic.packet_len,
                 capri_p4_intrinsic.frame_size - CAPRI_GLOBAL_INTRINSIC_HDR_SZ);

    modify_field(capri_intrinsic.tm_iq, capri_intrinsic.tm_oq);
    modify_field(capri_intrinsic.tm_oport, TM_PORT_DMA);

    if (capri_p4_intrinsic.parser_err == TRUE) {
        if (capri_p4_intrinsic.len_err != 0) {
            drop_packet();
        }
        // any csum error other than ocs error, drop the packet
        if (capri_intrinsic.csum_err & ~(1 << CSUM_HDR_UDP_OPT_OCS) == 0) {
            drop_packet();
        }
        if (capri_p4_intrinsic.crc_err != 0) {
            drop_packet();
        }
    }

    // if (capri_register.c1)
    modify_field(capri_intrinsic.lif, vport);
    modify_field(roce_metadata.rdma_enabled, rdma_enabled);

    // if (not capri_register.c1)
    modify_field(capri_intrinsic.lif, EXCEPTION_VPORT);
}

@pragma stage 1
table rx_vport {
    reads {
        ethernet_1.valid               : ternary;
        ethernet_2.valid               : ternary;
        ethernet_1.dstAddr             : ternary;
        ethernet_2.dstAddr             : ternary;
    }
    actions {
        rx_vport;
    }
    size : VPORT_TABLE_SIZE;
}

control rx_vport {
    apply(rx_vport);
}

/******************************************************************************/
/* Tx pipeline                                                                */
/******************************************************************************/
action tx_vport(port) {
    modify_field(capri_intrinsic.tm_iq, capri_intrinsic.tm_oq);
    modify_field(capri_intrinsic.tm_oport, port);
}

@pragma stage 5
table tx_vport {
    reads {
        flow_action_metadata.tx_ethernet_dst : ternary;
    }
    actions {
        tx_vport;
    }
    size : VPORT_TABLE_SIZE;
}

control tx_vport {
    apply(tx_vport);
}
