
#include "common.h"

ULONG
ExceptionFilter(IN ULONG Code, IN PEXCEPTION_POINTERS ExceptPtrs)
{

    PEXCEPTION_RECORD ExceptRec;
    PCONTEXT Context;

    UNREFERENCED_PARAMETER(Code);

    __try {

        ExceptRec = ExceptPtrs->ExceptionRecord;

        Context = ExceptPtrs->ContextRecord;

        IoPrint("**** Exception Caught in Ionic64 Driver ****\n");

        IoPrint("\n\nPerform the following WnDbg Cmds:\n");
        IoPrint("\n\t.exr %p ;  .cxr %p ;  kb\n\n", ExceptRec, Context);

        IoPrint("**** Exception Complete from Ionic Driver ****\n");
    } __except (EXCEPTION_EXECUTE_HANDLER) {

        NOTHING;
    }

    return EXCEPTION_EXECUTE_HANDLER;
}

NDIS_STATUS
ReadRegParameters(struct ionic *Adapter)
{

    NDIS_STATUS ntStatus = NDIS_STATUS_SUCCESS;
    NDIS_CONFIGURATION_OBJECT stObjectParams;
    NDIS_HANDLE hConfig = NULL;
    PNDIS_CONFIGURATION_PARAMETER pParameters = NULL;
    NDIS_STRING uniSriovPreferredKeyword = NDIS_STRING_CONST("*SriovPreferred"),
                uniRssOrVmqPreferredKeyword =
                    NDIS_STRING_CONST("*RssOrVmqPreference"),
                uniSRIOVKeyword = NDIS_STRING_CONST("*SRIOV"),
                uniVMQKeyword = NDIS_STRING_CONST("*VMQ"),
                uniRSSKeyword = NDIS_STRING_CONST("*RSS"),
                uniVlanId = NDIS_STRING_CONST("VlanID"),
                uniVlanPriEnabled = NDIS_STRING_CONST("*PriorityVLANTag"),
                uniJumbo = NDIS_STRING_CONST("*JumboPacket"),
                uniFlowControl = NDIS_STRING_CONST("*FlowControl"),
                uniSpeedDuplex = NDIS_STRING_CONST("*SpeedDuplex"),
                uniLSOV1 = NDIS_STRING_CONST("*LsoV1IPv4"),
                uniLSOV2Ipv4 = NDIS_STRING_CONST("*LsoV2IPv4"),
                uniLSOV2Ipv6 = NDIS_STRING_CONST("*LsoV2IPv6"),
                uniIPChecksum = NDIS_STRING_CONST("*IPChecksumOffloadIPv4"),
                uniTCPChecksumIPv4 =
                    NDIS_STRING_CONST("*TCPChecksumOffloadIPv4"),
                uniTCPChecksumIPv6 =
                    NDIS_STRING_CONST("*TCPChecksumOffloadIPv6"),
                uniUDPChecksumIPv4 =
                    NDIS_STRING_CONST("*UDPChecksumOffloadIPv4"),
                uniUDPChecksumIPv6 =
                    NDIS_STRING_CONST("*UDPChecksumOffloadIPv6"),
                uniRxPoolSize =
                    NDIS_STRING_CONST("RxPoolSize"),
                uniTxFlushMode =
                    NDIS_STRING_CONST("TxFlushMode");
    void *pMacAddr = NULL;
    UINT ulMacAddrLen = 0;

    DbgTrace((TRACE_COMPONENT_INIT, TRACE_LEVEL_VERBOSE,
              "%s Entry for adapter %p\n", __FUNCTION__, Adapter));

    NdisZeroMemory(&stObjectParams, sizeof(NDIS_CONFIGURATION_OBJECT));

    stObjectParams.Header.Type = NDIS_OBJECT_TYPE_CONFIGURATION_OBJECT;
    stObjectParams.Header.Size = NDIS_SIZEOF_CONFIGURATION_OBJECT_REVISION_1;
    stObjectParams.Header.Revision = NDIS_CONFIGURATION_OBJECT_REVISION_1;

    stObjectParams.NdisHandle = Adapter->adapterhandle;
    stObjectParams.Flags = 0;

    ntStatus = NdisOpenConfigurationEx(&stObjectParams, &hConfig);

    if (ntStatus != NDIS_STATUS_SUCCESS) {
        DbgTrace(
            (TRACE_COMPONENT_INIT, TRACE_LEVEL_ERROR,
             "%s Failed to open config handle for adapter %p Error %08lX\n",
             __FUNCTION__, Adapter, ntStatus));
        goto cleanup;
    }

    NdisReadNetworkAddress(&ntStatus, &pMacAddr, &ulMacAddrLen, hConfig);
    if (ntStatus == NDIS_STATUS_SUCCESS && ulMacAddrLen >= ETH_ALEN &&
        pMacAddr != NULL) {

        //
        // Do not accept multi or broad cast addresses
        //

        if (!ETH_IS_MULTICAST(pMacAddr) && !ETH_IS_BROADCAST(pMacAddr)) {
            memcpy(Adapter->config_addr, pMacAddr, ETH_ALEN);

            DbgTrace((TRACE_COMPONENT_INIT, TRACE_LEVEL_VERBOSE,
                      "%s Read MAC addr %02lX:%02lX:%02lX:%02lX:%02lX:%02lX\n",
                      __FUNCTION__, Adapter->config_addr[0],
                      Adapter->config_addr[1], Adapter->config_addr[2],
                      Adapter->config_addr[3], Adapter->config_addr[4],
                      Adapter->config_addr[5]));
        } else {
            DbgTrace(
                (TRACE_COMPONENT_INIT, TRACE_LEVEL_ERROR,
                 "%s Invalid MAC addr %02lX:%02lX:%02lX:%02lX:%02lX:%02lX\n",
                 __FUNCTION__, Adapter->config_addr[0], Adapter->config_addr[1],
                 Adapter->config_addr[2], Adapter->config_addr[3],
                 Adapter->config_addr[4], Adapter->config_addr[5]));
        }
    }

    NdisReadConfiguration(&ntStatus, &pParameters, hConfig, &uniVlanPriEnabled,
                          NdisParameterInteger);

    if (ntStatus == NDIS_STATUS_SUCCESS &&
        pParameters->ParameterData.IntegerData != 0) {

        //
        // If 1 is enabled, they both need to be enabled
        //

        // if (pParameters->ParameterData.IntegerData == 1) {
        //	SetFlag( Adapter->ConfigStatus, IONIC_PRIORITY_ENABLED);
        //}
        // else if (pParameters->ParameterData.IntegerData == 2) {
        //	SetFlag( Adapter->ConfigStatus, IONIC_VLAN_ENABLED);
        //}
        // else if (pParameters->ParameterData.IntegerData == 3) {
        SetFlag(Adapter->ConfigStatus,
                (IONIC_PRIORITY_ENABLED | IONIC_VLAN_ENABLED));
        //}
    }

    DbgTrace((
        TRACE_COMPONENT_INIT, TRACE_LEVEL_VERBOSE,
        "%s Have Vlan %s Priority %s\n", __FUNCTION__,
        BooleanFlagOn(Adapter->ConfigStatus, IONIC_VLAN_ENABLED) ? "YES" : "NO",
        BooleanFlagOn(Adapter->ConfigStatus, IONIC_PRIORITY_ENABLED) ? "YES"
                                                                     : "NO"));

    if (BooleanFlagOn(Adapter->ConfigStatus, IONIC_VLAN_ENABLED)) {
        NdisReadConfiguration(&ntStatus, &pParameters, hConfig, &uniVlanId,
                              NdisParameterInteger);

        if (ntStatus == NDIS_STATUS_SUCCESS &&
            pParameters->ParameterData.IntegerData <= ETH_VLAN_ID_MAX) {
            Adapter->vlan_id =
                (unsigned short)pParameters->ParameterData.IntegerData;

            DbgTrace((TRACE_COMPONENT_INIT, TRACE_LEVEL_VERBOSE,
                      "%s Have VLan tag %d\n", __FUNCTION__, Adapter->vlan_id));
        }
    }

    Adapter->rx_pool_factor = IONIC_DEFAULT_RX_POOL_FACTOR;
    NdisReadConfiguration(&ntStatus, &pParameters, hConfig, &uniRxPoolSize,
                          NdisParameterInteger);

    if (ntStatus == NDIS_STATUS_SUCCESS &&
        pParameters->ParameterData.IntegerData != 0) {
        Adapter->rx_pool_factor = pParameters->ParameterData.IntegerData;
        if (Adapter->rx_pool_factor > IONIC_MAX_RX_POOL_FACTOR) {
            Adapter->rx_pool_factor = IONIC_DEFAULT_RX_POOL_FACTOR;
        }
    }

    Adapter->flow_control = IONIC_FC_TXRX_ENABLED;
    NdisReadConfiguration(&ntStatus, &pParameters, hConfig, &uniFlowControl,
                          NdisParameterInteger);

    if (ntStatus == NDIS_STATUS_SUCCESS) {
        Adapter->flow_control = pParameters->ParameterData.IntegerData;
        if (Adapter->flow_control > IONIC_FC_TXRX_ENABLED) {
            Adapter->flow_control = IONIC_FC_TXRX_ENABLED;
        }
    }

    Adapter->config_port_speed = 0; // auto negotiate if not specified
    NdisReadConfiguration(&ntStatus, &pParameters, hConfig, &uniSpeedDuplex,
                          NdisParameterInteger);

    if (ntStatus == NDIS_STATUS_SUCCESS) {
        Adapter->config_port_speed = pParameters->ParameterData.IntegerData;

        // Convert required NDIS SpeedDuplex enums 0..10 to Mbps (that we support)
        // https://docs.microsoft.com/en-us/windows-hardware/drivers/network/enumeration-keywords
        if (Adapter->config_port_speed == 7) {
            Adapter->config_port_speed = 10000;
        } else if (Adapter->config_port_speed == 9) {
            Adapter->config_port_speed = 40000;
        } else if (Adapter->config_port_speed == 10) {
            Adapter->config_port_speed = 100000;
        }

        if (Adapter->config_port_speed != IONIC_SPEED_1G &&
            Adapter->config_port_speed != IONIC_SPEED_10G &&
            Adapter->config_port_speed != IONIC_SPEED_25G &&
            Adapter->config_port_speed != IONIC_SPEED_40G &&
            Adapter->config_port_speed != IONIC_SPEED_50G &&
            Adapter->config_port_speed != IONIC_SPEED_100G) {

            DbgTrace((TRACE_COMPONENT_INIT, TRACE_LEVEL_ERROR,
                      "%s Invalid port speed %d Mbps\n",
                      __FUNCTION__, Adapter->config_port_speed));
            Adapter->config_port_speed = 0;
        }
    }

    NdisReadConfiguration(&ntStatus, &pParameters, hConfig, &uniTxFlushMode,
                          NdisParameterInteger);

    SetFlag( Adapter->ConfigStatus, IONIC_TX_MODE_DPC);

    if (ntStatus == NDIS_STATUS_SUCCESS &&
        pParameters->ParameterData.IntegerData != 0) {

        if (pParameters->ParameterData.IntegerData == 2) {
            ClearFlag( Adapter->ConfigStatus, IONIC_TX_MODE_DPC);
            SetFlag( Adapter->ConfigStatus, IONIC_TX_MODE_SEND);
        }
        else if( pParameters->ParameterData.IntegerData == 3) {
            SetFlag( Adapter->ConfigStatus, IONIC_TX_MODE_SEND);
        }
    }

    Adapter->frame_size = IONIC_FRAME_DEFAULT;
    NdisReadConfiguration(&ntStatus, &pParameters, hConfig, &uniJumbo,
                          NdisParameterInteger);

    if (ntStatus == NDIS_STATUS_SUCCESS) {

        Adapter->frame_size = pParameters->ParameterData.IntegerData;

        if( Adapter->frame_size < IONIC_FRAME_MIN ||
            Adapter->frame_size > IONIC_FRAME_MAX) {
            Adapter->frame_size = IONIC_FRAME_DEFAULT;
        }

        DbgTrace((TRACE_COMPONENT_INIT, TRACE_LEVEL_VERBOSE,
                  "%s Frame %\n", __FUNCTION__,
                  Adapter->frame_size));
    }

    // xsum and LSO offload
    Adapter->lsov1_state = NDIS_OFFLOAD_PARAMETERS_LSOV1_DISABLED;

    NdisReadConfiguration(&ntStatus, &pParameters, hConfig, &uniLSOV1,
                          NdisParameterInteger);

    if (ntStatus == NDIS_STATUS_SUCCESS &&
        pParameters->ParameterData.IntegerData == 1) {
        Adapter->lsov1_state = NDIS_OFFLOAD_PARAMETERS_LSOV1_ENABLED;
    }

    Adapter->lsov2ipv4_state = NDIS_OFFLOAD_PARAMETERS_LSOV2_ENABLED;

    NdisReadConfiguration(&ntStatus, &pParameters, hConfig, &uniLSOV2Ipv4,
                          NdisParameterInteger);

    if (ntStatus == NDIS_STATUS_SUCCESS &&
        pParameters->ParameterData.IntegerData == 0) {
        Adapter->lsov2ipv4_state = NDIS_OFFLOAD_PARAMETERS_LSOV2_DISABLED;
    }

    Adapter->lsov2ipv6_state = NDIS_OFFLOAD_PARAMETERS_LSOV2_ENABLED;

    NdisReadConfiguration(&ntStatus, &pParameters, hConfig, &uniLSOV2Ipv6,
                          NdisParameterInteger);

    if (ntStatus == NDIS_STATUS_SUCCESS &&
        pParameters->ParameterData.IntegerData == 0) {
        Adapter->lsov2ipv6_state = NDIS_OFFLOAD_PARAMETERS_LSOV2_DISABLED;
    }

    Adapter->ipv4_rx_state = NDIS_OFFLOAD_SET_ON;
    Adapter->ipv4_tx_state = NDIS_OFFLOAD_SET_ON;

    NdisReadConfiguration(&ntStatus, &pParameters, hConfig, &uniIPChecksum,
                          NdisParameterInteger);

    if (ntStatus == NDIS_STATUS_SUCCESS &&
        pParameters->ParameterData.IntegerData != 3) {

        if (pParameters->ParameterData.IntegerData == 2) {
            Adapter->ipv4_tx_state = NDIS_OFFLOAD_SET_OFF;
        } else if (pParameters->ParameterData.IntegerData == 1) {
            Adapter->ipv4_rx_state = NDIS_OFFLOAD_SET_OFF;
        } else {
            Adapter->ipv4_rx_state = NDIS_OFFLOAD_SET_OFF;
            Adapter->ipv4_tx_state = NDIS_OFFLOAD_SET_OFF;
        }
    }

    Adapter->tcpv4_rx_state = NDIS_OFFLOAD_SET_ON;
    Adapter->tcpv4_tx_state = NDIS_OFFLOAD_SET_ON;

    NdisReadConfiguration(&ntStatus, &pParameters, hConfig, &uniTCPChecksumIPv4,
                          NdisParameterInteger);

    if (ntStatus == NDIS_STATUS_SUCCESS &&
        pParameters->ParameterData.IntegerData != 3) {

        if (pParameters->ParameterData.IntegerData == 2) {
            Adapter->tcpv4_tx_state = NDIS_OFFLOAD_SET_OFF;
        } else if (pParameters->ParameterData.IntegerData == 1) {
            Adapter->tcpv4_rx_state = NDIS_OFFLOAD_SET_OFF;
        } else {
            Adapter->tcpv4_rx_state = NDIS_OFFLOAD_SET_OFF;
            Adapter->tcpv4_tx_state = NDIS_OFFLOAD_SET_OFF;
        }
    }

    Adapter->tcpv6_rx_state = NDIS_OFFLOAD_SET_ON;
    Adapter->tcpv6_tx_state = NDIS_OFFLOAD_SET_ON;

    NdisReadConfiguration(&ntStatus, &pParameters, hConfig, &uniTCPChecksumIPv6,
                          NdisParameterInteger);

    if (ntStatus == NDIS_STATUS_SUCCESS &&
        pParameters->ParameterData.IntegerData != 3) {

        if (pParameters->ParameterData.IntegerData == 2) {
            Adapter->tcpv6_tx_state = NDIS_OFFLOAD_SET_OFF;
        } else if (pParameters->ParameterData.IntegerData == 1) {
            Adapter->tcpv6_rx_state = NDIS_OFFLOAD_SET_OFF;
        } else {
            Adapter->tcpv6_rx_state = NDIS_OFFLOAD_SET_OFF;
            Adapter->tcpv6_tx_state = NDIS_OFFLOAD_SET_OFF;
        }
    }

    Adapter->udpv4_rx_state = NDIS_OFFLOAD_SET_ON;
    Adapter->udpv4_tx_state = NDIS_OFFLOAD_SET_ON;

    NdisReadConfiguration(&ntStatus, &pParameters, hConfig, &uniUDPChecksumIPv4,
                          NdisParameterInteger);

    if (ntStatus == NDIS_STATUS_SUCCESS &&
        pParameters->ParameterData.IntegerData != 3) {

        if (pParameters->ParameterData.IntegerData == 2) {
            Adapter->udpv4_tx_state = NDIS_OFFLOAD_SET_OFF;
        } else if (pParameters->ParameterData.IntegerData == 1) {
            Adapter->udpv4_rx_state = NDIS_OFFLOAD_SET_OFF;
        } else {
            Adapter->udpv4_rx_state = NDIS_OFFLOAD_SET_OFF;
            Adapter->udpv4_tx_state = NDIS_OFFLOAD_SET_OFF;
        }
    }

    Adapter->udpv6_rx_state = NDIS_OFFLOAD_SET_ON;
    Adapter->udpv6_tx_state = NDIS_OFFLOAD_SET_ON;

    NdisReadConfiguration(&ntStatus, &pParameters, hConfig, &uniUDPChecksumIPv6,
                          NdisParameterInteger);

    if (ntStatus == NDIS_STATUS_SUCCESS &&
        pParameters->ParameterData.IntegerData != 3) {

        if (pParameters->ParameterData.IntegerData == 2) {
            Adapter->udpv6_tx_state = NDIS_OFFLOAD_SET_OFF;
        } else if (pParameters->ParameterData.IntegerData == 1) {
            Adapter->udpv6_rx_state = NDIS_OFFLOAD_SET_OFF;
        } else {
            Adapter->udpv6_rx_state = NDIS_OFFLOAD_SET_OFF;
            Adapter->udpv6_tx_state = NDIS_OFFLOAD_SET_OFF;
        }
    }

    DbgTrace((TRACE_COMPONENT_INIT, TRACE_LEVEL_VERBOSE,
              "%s Offload support LSOv1 %s LSOv2Ipv4 %s LSOv2Ipv6 %s xsumipv4 "
              "tx %s rx %s xsumtcpv4 tx %s rx %s xsumtcpv6 tx %s rx %s "
              "xsumudpv4 tx %s rx %s xsumudpv6 tx %s rx %s\n",
              __FUNCTION__,
              Adapter->lsov1_state == NDIS_OFFLOAD_PARAMETERS_LSOV1_ENABLED
                  ? "Yes"
                  : "No",
              Adapter->lsov2ipv4_state == NDIS_OFFLOAD_PARAMETERS_LSOV2_ENABLED
                  ? "Yes"
                  : "No",
              Adapter->lsov2ipv6_state == NDIS_OFFLOAD_PARAMETERS_LSOV2_ENABLED
                  ? "Yes"
                  : "No",
              Adapter->ipv4_rx_state == NDIS_OFFLOAD_SET_ON ? "Yes" : "No",
              Adapter->ipv4_tx_state == NDIS_OFFLOAD_SET_ON ? "Yes" : "No",
              Adapter->tcpv4_rx_state == NDIS_OFFLOAD_SET_ON ? "Yes" : "No",
              Adapter->tcpv4_tx_state == NDIS_OFFLOAD_SET_ON ? "Yes" : "No",
              Adapter->tcpv6_rx_state == NDIS_OFFLOAD_SET_ON ? "Yes" : "No",
              Adapter->tcpv6_tx_state == NDIS_OFFLOAD_SET_ON ? "Yes" : "No",
              Adapter->udpv4_rx_state == NDIS_OFFLOAD_SET_ON ? "Yes" : "No",
              Adapter->udpv4_tx_state == NDIS_OFFLOAD_SET_ON ? "Yes" : "No",
              Adapter->udpv6_rx_state == NDIS_OFFLOAD_SET_ON ? "Yes" : "No",
              Adapter->udpv6_tx_state == NDIS_OFFLOAD_SET_ON ? "Yes" : "No"));

    NdisReadConfiguration(&ntStatus, &pParameters, hConfig,
                          &uniSriovPreferredKeyword, NdisParameterInteger);

    if (ntStatus == NDIS_STATUS_SUCCESS) {
        DbgTrace((TRACE_COMPONENT_INIT, TRACE_LEVEL_VERBOSE,
                  "%s SriovPreferred keyword status %08lX Value %08lX\n",
                  __FUNCTION__, ntStatus,
                  pParameters->ParameterData.IntegerData));
    } else {
        DbgTrace((TRACE_COMPONENT_INIT, TRACE_LEVEL_VERBOSE,
                  "%s SriovPreferred keyword status %08lX\n", __FUNCTION__,
                  ntStatus));
    }

    if (ntStatus == NDIS_STATUS_SUCCESS &&
        pParameters->ParameterData.IntegerData != 0) {

        NdisReadConfiguration(&ntStatus, &pParameters, hConfig,
                              &uniSRIOVKeyword, NdisParameterInteger);

        if (ntStatus == NDIS_STATUS_SUCCESS) {
            DbgTrace((TRACE_COMPONENT_INIT, TRACE_LEVEL_VERBOSE,
                      "%s Sriov keyword status %08lX Value %08lX\n",
                      __FUNCTION__, ntStatus,
                      pParameters->ParameterData.IntegerData));
        } else {
            DbgTrace((TRACE_COMPONENT_INIT, TRACE_LEVEL_VERBOSE,
                      "%s Sriov keyword status %08lX\n", __FUNCTION__,
                      ntStatus));
        }
        if (ntStatus == NDIS_STATUS_SUCCESS &&
            pParameters->ParameterData.IntegerData != 0) {
            SetFlag(Adapter->ConfigStatus, IONIC_SRIOV_ENABLED);

            DbgTrace((TRACE_COMPONENT_INIT, TRACE_LEVEL_VERBOSE,
                      "%s Enabling SRIOV on adapter %p\n", __FUNCTION__,
                      Adapter));

            SetFlag(Adapter->port_stats.flags, IONIC_PORT_FLAG_SRIOV);
        }
    }

    NdisReadConfiguration(&ntStatus, &pParameters, hConfig,
                          &uniRssOrVmqPreferredKeyword, NdisParameterInteger);

    if (ntStatus == NDIS_STATUS_SUCCESS) {
        DbgTrace((TRACE_COMPONENT_INIT, TRACE_LEVEL_VERBOSE,
                  "%s RssOrVmq keyword status %08lX Value %08lX\n",
                  __FUNCTION__, ntStatus,
                  pParameters->ParameterData.IntegerData));
    } else {
        DbgTrace((TRACE_COMPONENT_INIT, TRACE_LEVEL_VERBOSE,
                  "%s RssOrVmq keyword status %08lX\n", __FUNCTION__,
                  ntStatus));
    }

    if (ntStatus == NDIS_STATUS_SUCCESS &&
        pParameters->ParameterData.IntegerData != 0) {

        NdisReadConfiguration(&ntStatus, &pParameters, hConfig, &uniVMQKeyword,
                              NdisParameterInteger);

        if (ntStatus == NDIS_STATUS_SUCCESS) {
            DbgTrace((TRACE_COMPONENT_INIT, TRACE_LEVEL_VERBOSE,
                      "%s Vmq keyword status %08lX Value %08lX\n", __FUNCTION__,
                      ntStatus, pParameters->ParameterData.IntegerData));
        } else {
            DbgTrace((TRACE_COMPONENT_INIT, TRACE_LEVEL_VERBOSE,
                      "%s Vmq keyword status %08lX\n", __FUNCTION__, ntStatus));
        }

        if (ntStatus == NDIS_STATUS_SUCCESS &&
            pParameters->ParameterData.IntegerData != 0) {
            SetFlag(Adapter->ConfigStatus, IONIC_VMQ_ENABLED);

            DbgTrace((TRACE_COMPONENT_INIT, TRACE_LEVEL_VERBOSE,
                      "%s Enabling VMQ on adapter %p\n", __FUNCTION__,
                      Adapter));

            SetFlag(Adapter->port_stats.flags, IONIC_PORT_FLAG_VMQ);
        }
    }

    if (!BooleanFlagOn(Adapter->ConfigStatus, IONIC_SRIOV_ENABLED) &&
        !BooleanFlagOn(Adapter->ConfigStatus, IONIC_VMQ_ENABLED)) {

        NdisReadConfiguration(&ntStatus, &pParameters, hConfig, &uniRSSKeyword,
                              NdisParameterInteger);

        if (ntStatus == NDIS_STATUS_SUCCESS) {
            DbgTrace((TRACE_COMPONENT_INIT, TRACE_LEVEL_VERBOSE,
                      "%s RSS keyword status %08lX Value %08lX\n", __FUNCTION__,
                      ntStatus, pParameters->ParameterData.IntegerData));
        } else {
            DbgTrace((TRACE_COMPONENT_INIT, TRACE_LEVEL_VERBOSE,
                      "%s RSS keyword status %08lX\n", __FUNCTION__, ntStatus));
        }

        if (ntStatus == NDIS_STATUS_SUCCESS &&
            pParameters->ParameterData.IntegerData != 0) {
            SetFlag(Adapter->ConfigStatus, IONIC_RSS_ENABLED);

            DbgTrace((TRACE_COMPONENT_INIT, TRACE_LEVEL_VERBOSE,
                      "%s Enabling RSS on adapter %p\n", __FUNCTION__,
                      Adapter));

            SetFlag(Adapter->port_stats.flags, IONIC_PORT_FLAG_RSS);
        }
    }

    //
    // Go read in interface specific information
    //

    if (BooleanFlagOn(Adapter->ConfigStatus, IONIC_SRIOV_ENABLED)) {
        ReadSriovConfig(Adapter, hConfig);
    }

    if (BooleanFlagOn(Adapter->ConfigStatus, IONIC_VMQ_ENABLED)) {
        ReadVmqConfig(Adapter, hConfig);
    }

    if (BooleanFlagOn(Adapter->ConfigStatus, IONIC_RSS_ENABLED)) {
        ReadRssConfig(Adapter, hConfig);
    }
    else {
        Adapter->num_rss_queues = IONIC_DEFAULT_QUEUE_COUNT;
    }

    ntStatus = NDIS_STATUS_SUCCESS;

cleanup:

    if (hConfig != NULL) {
        NdisCloseConfiguration(hConfig);
    }

    return ntStatus;
}

void
ReadSriovConfig(struct ionic *Adapter, NDIS_HANDLE Config)
{

    NDIS_STATUS ntStatus = NDIS_STATUS_SUCCESS;
    PNDIS_CONFIGURATION_PARAMETER pParameters = NULL;
    NDIS_STRING uniNumVFsKeyword = NDIS_STRING_CONST("*NUMVFs");

    NdisReadConfiguration(&ntStatus, &pParameters, Config, &uniNumVFsKeyword,
                          NdisParameterInteger);

    if (ntStatus == NDIS_STATUS_SUCCESS) {
        DbgTrace((TRACE_COMPONENT_INIT, TRACE_LEVEL_VERBOSE,
                  "%s uniNumVFsKeyword keyword status %08lX Value %08lX\n",
                  __FUNCTION__, ntStatus,
                  pParameters->ParameterData.IntegerData));
    } else {
        DbgTrace((TRACE_COMPONENT_INIT, TRACE_LEVEL_VERBOSE,
                  "%s uniNumVFsKeyword keyword status %08lX\n", __FUNCTION__,
                  ntStatus));
    }

    if (ntStatus == NDIS_STATUS_SUCCESS &&
        pParameters->ParameterData.IntegerData != 0) {
        Adapter->MaxNumberVFs = pParameters->ParameterData.IntegerData;
        Adapter->MaxNumVPorts = pParameters->ParameterData
                                    .IntegerData; // Set these the same for now
    }

    return;
}

void
ReadVmqConfig(struct ionic *Adapter, NDIS_HANDLE Config)
{

    NDIS_STATUS ntStatus = NDIS_STATUS_SUCCESS;
    PNDIS_CONFIGURATION_PARAMETER pParameters = NULL;
    NDIS_STRING uniVmqVLanFilteringKeyword =
        NDIS_STRING_CONST("*VMQVlanFiltering");

    NdisReadConfiguration(&ntStatus, &pParameters, Config,
                          &uniVmqVLanFilteringKeyword, NdisParameterInteger);

    if (ntStatus == NDIS_STATUS_SUCCESS) {
        DbgTrace(
            (TRACE_COMPONENT_INIT, TRACE_LEVEL_VERBOSE,
             "%s VmqVLanFilteringKeyword keyword status %08lX Value %08lX\n",
             __FUNCTION__, ntStatus, pParameters->ParameterData.IntegerData));
    } else {
        DbgTrace((TRACE_COMPONENT_INIT, TRACE_LEVEL_VERBOSE,
                  "%s VmqVLanFilteringKeyword keyword status %08lX\n",
                  __FUNCTION__, ntStatus));
    }

    if (ntStatus == NDIS_STATUS_SUCCESS &&
        pParameters->ParameterData.IntegerData != 0) {

        SetFlag(Adapter->ConfigStatus, IONIC_VMQ_VLAN_FILTERING_ENABLED);
    }

    return;
}

void
ReadRssConfig(struct ionic *Adapter, NDIS_HANDLE Config)
{

    NDIS_STATUS ntStatus = NDIS_STATUS_SUCCESS;
    PNDIS_CONFIGURATION_PARAMETER pParameters = NULL;
    NDIS_STRING uniNumRSSQueuesKeyword = NDIS_STRING_CONST("*NumRSSQueues");

    NdisReadConfiguration(&ntStatus, &pParameters, Config,
                          &uniNumRSSQueuesKeyword, NdisParameterInteger);

    if (ntStatus == NDIS_STATUS_SUCCESS) {
        DbgTrace((TRACE_COMPONENT_INIT, TRACE_LEVEL_VERBOSE,
                  "%s NumRSSQueues keyword status %08lX Value %08lX\n",
                  __FUNCTION__, ntStatus,
                  pParameters->ParameterData.IntegerData));
    } else {
        DbgTrace((TRACE_COMPONENT_INIT, TRACE_LEVEL_VERBOSE,
                  "%s NumRSSQueues keyword status %08lX\n", __FUNCTION__,
                  ntStatus));
    }

    if (ntStatus == NDIS_STATUS_SUCCESS &&
        pParameters->ParameterData.IntegerData != 0) {
        Adapter->num_rss_queues = pParameters->ParameterData.IntegerData;
    }

    return;
}

void *
AllocSharedMemory(struct ionic *Adapter, ULONG Length, ULONG64 *PhysAddr)
{

    void *pAddress = NULL;
    NDIS_PHYSICAL_ADDRESS physAddr = {0};

    NdisMAllocateSharedMemory(
        Adapter->adapterhandle, Length,
        TRUE /* ignored, always cached on Intel systems */, &pAddress,
        &physAddr);

    if (pAddress != NULL) {
        NdisZeroMemory(pAddress, Length);
        *PhysAddr = (ULONG64)physAddr.QuadPart;
    }

    return pAddress;
}

void
ReleaseSharedMemory(struct ionic *Adapter,
                    ULONG Length,
                    void *Address,
                    ULONG64 PhysAddr)
{

    NDIS_PHYSICAL_ADDRESS physAddr;

    physAddr.QuadPart = (ULONGLONG)PhysAddr;

    NdisMFreeSharedMemory(Adapter->adapterhandle, Length, TRUE, Address,
                          physAddr);

    return;
}

void *
AllocateSharedMemorySpecifyNuma( struct ionic *ionic,
								 ULONG length,
								 NDIS_HANDLE *alloc_handle,
								 dma_addr_t *phys_addr)
{

	NDIS_STATUS status = NDIS_STATUS_SUCCESS;
	NDIS_SHARED_MEMORY_PARAMETERS stParams;
	ULONG ulSGListNumElements = 0;
	ULONG ulSGListSize = 0;
	PSCATTER_GATHER_LIST pSGListBuffer = NULL;

    NdisZeroMemory(&stParams, sizeof(NDIS_SHARED_MEMORY_PARAMETERS));

    stParams.Header.Type = NDIS_OBJECT_TYPE_DEFAULT;
    stParams.Header.Revision = NDIS_SHARED_MEMORY_PARAMETERS_REVISION_2;
    stParams.Header.Size =
        NDIS_SIZEOF_SHARED_MEMORY_PARAMETERS_REVISION_2;

    stParams.Flags = 0; // NDIS_SHARED_MEM_PARAMETERS_CONTIGOUS;
    stParams.Usage = NdisSharedMemoryUsageOther;

    stParams.PreferredNode = ionic->numa_node; //MM_ANY_NODE_OK;
    stParams.Length = length;

    ulSGListNumElements = BYTES_TO_PAGES(stParams.Length);
    ulSGListSize =
        sizeof(SCATTER_GATHER_LIST) +
        (sizeof(SCATTER_GATHER_ELEMENT) * ulSGListNumElements);
    pSGListBuffer =
        (PSCATTER_GATHER_LIST)NdisAllocateMemoryWithTagPriority_internal(
            ionic->adapterhandle, ulSGListSize, IONIC_SG_LIST_TAG,
            NormalPoolPriority);

    if (pSGListBuffer == NULL) {
        goto exit;
    }

    NdisZeroMemory(pSGListBuffer, ulSGListSize);

    pSGListBuffer->NumberOfElements = ulSGListNumElements;

    stParams.SGListBufferLength = ulSGListSize;
    stParams.SGListBuffer = pSGListBuffer;

    status = NdisAllocateSharedMemory(
        ionic->adapterhandle, &stParams,
        alloc_handle);

    if (status != NDIS_STATUS_SUCCESS) {
        goto exit;
    }

    NdisZeroMemory(stParams.VirtualAddress,
                    length);

	ASSERT( pSGListBuffer->NumberOfElements == 1);

	*phys_addr = pSGListBuffer->Elements[ 0].Address.QuadPart;

exit:

	if( pSGListBuffer != NULL) {
		NdisFreeMemoryWithTagPriority_internal( ionic->adapterhandle, pSGListBuffer, IONIC_SG_LIST_TAG);
	}

	return stParams.VirtualAddress;
}

char *
ionic_dev_asic_name(u8 asic_type)
{
    switch (asic_type) {
    case ASIC_TYPE_CAPRI:
        return "Capri";
    default:
        return "Unknown";
    }
}

bool
is_power_of_2(unsigned int n)
{
    return (n != 0 && ((n & (n - 1)) == 0));
}

unsigned int
ilog2(unsigned int n)
{
    unsigned int log2 = 0;
    for (log2 = 0; n != 1; n >>= 1, log2++)
        ;
    return log2;
}

const char *
ionic_opcode_to_str(enum cmd_opcode opcode)
{
    switch (opcode) {
    case CMD_OPCODE_NOP:
        return "CMD_OPCODE_NOP";
    case CMD_OPCODE_INIT:
        return "CMD_OPCODE_INIT";
    case CMD_OPCODE_RESET:
        return "CMD_OPCODE_RESET";
    case CMD_OPCODE_IDENTIFY:
        return "CMD_OPCODE_IDENTIFY";
    case CMD_OPCODE_GETATTR:
        return "CMD_OPCODE_GETATTR";
    case CMD_OPCODE_SETATTR:
        return "CMD_OPCODE_SETATTR";
    case CMD_OPCODE_PORT_IDENTIFY:
        return "CMD_OPCODE_PORT_IDENTIFY";
    case CMD_OPCODE_PORT_INIT:
        return "CMD_OPCODE_PORT_INIT";
    case CMD_OPCODE_PORT_RESET:
        return "CMD_OPCODE_PORT_RESET";
    case CMD_OPCODE_PORT_GETATTR:
        return "CMD_OPCODE_PORT_GETATTR";
    case CMD_OPCODE_PORT_SETATTR:
        return "CMD_OPCODE_PORT_SETATTR";
    case CMD_OPCODE_LIF_INIT:
        return "CMD_OPCODE_LIF_INIT";
    case CMD_OPCODE_LIF_RESET:
        return "CMD_OPCODE_LIF_RESET";
    case CMD_OPCODE_LIF_IDENTIFY:
        return "CMD_OPCODE_LIF_IDENTIFY";
    case CMD_OPCODE_LIF_SETATTR:
        return "CMD_OPCODE_LIF_SETATTR";
    case CMD_OPCODE_LIF_GETATTR:
        return "CMD_OPCODE_LIF_GETATTR";
    case CMD_OPCODE_RX_MODE_SET:
        return "CMD_OPCODE_RX_MODE_SET";
    case CMD_OPCODE_RX_FILTER_ADD:
        return "CMD_OPCODE_RX_FILTER_ADD";
    case CMD_OPCODE_RX_FILTER_DEL:
        return "CMD_OPCODE_RX_FILTER_DEL";
    case CMD_OPCODE_Q_INIT:
        return "CMD_OPCODE_Q_INIT";
    case CMD_OPCODE_Q_CONTROL:
        return "CMD_OPCODE_Q_CONTROL";
    case CMD_OPCODE_RDMA_RESET_LIF:
        return "CMD_OPCODE_RDMA_RESET_LIF";
    case CMD_OPCODE_RDMA_CREATE_EQ:
        return "CMD_OPCODE_RDMA_CREATE_EQ";
    case CMD_OPCODE_RDMA_CREATE_CQ:
        return "CMD_OPCODE_RDMA_CREATE_CQ";
    case CMD_OPCODE_RDMA_CREATE_ADMINQ:
        return "CMD_OPCODE_RDMA_CREATE_ADMINQ";
    case CMD_OPCODE_FW_DOWNLOAD:
        return "CMD_OPCODE_FW_DOWNLOAD";
    case CMD_OPCODE_FW_CONTROL:
        return "CMD_OPCODE_FW_CONTROL";
    default:
        return "DEVCMD_UNKNOWN";
    }
}

const char *
ionic_error_to_str(enum status_code code)
{
    switch (code) {
    case IONIC_RC_SUCCESS:
        return "IONIC_RC_SUCCESS";
    case IONIC_RC_EVERSION:
        return "IONIC_RC_EVERSION";
    case IONIC_RC_EOPCODE:
        return "IONIC_RC_EOPCODE";
    case IONIC_RC_EIO:
        return "IONIC_RC_EIO";
    case IONIC_RC_EPERM:
        return "IONIC_RC_EPERM";
    case IONIC_RC_EQID:
        return "IONIC_RC_EQID";
    case IONIC_RC_EQTYPE:
        return "IONIC_RC_EQTYPE";
    case IONIC_RC_ENOENT:
        return "IONIC_RC_ENOENT";
    case IONIC_RC_EINTR:
        return "IONIC_RC_EINTR";
    case IONIC_RC_EAGAIN:
        return "IONIC_RC_EAGAIN";
    case IONIC_RC_ENOMEM:
        return "IONIC_RC_ENOMEM";
    case IONIC_RC_EFAULT:
        return "IONIC_RC_EFAULT";
    case IONIC_RC_EBUSY:
        return "IONIC_RC_EBUSY";
    case IONIC_RC_EEXIST:
        return "IONIC_RC_EEXIST";
    case IONIC_RC_EINVAL:
        return "IONIC_RC_EINVAL";
    case IONIC_RC_ENOSPC:
        return "IONIC_RC_ENOSPC";
    case IONIC_RC_ERANGE:
        return "IONIC_RC_ERANGE";
    case IONIC_RC_BAD_ADDR:
        return "IONIC_RC_BAD_ADDR";
    case IONIC_RC_DEV_CMD:
        return "IONIC_RC_DEV_CMD";
    case IONIC_RC_ERROR:
        return "IONIC_RC_ERROR";
    case IONIC_RC_ERDMA:
        return "IONIC_RC_ERDMA";
    default:
        return "IONIC_RC_UNKNOWN";
    }
}

NDIS_STATUS
ionic_error_to_errno(enum status_code code)
{
    switch (code) {
    case IONIC_RC_SUCCESS:
        return NDIS_STATUS_SUCCESS;
    case IONIC_RC_EVERSION:
    case IONIC_RC_EQTYPE:
    case IONIC_RC_EQID:
    case IONIC_RC_EINVAL:
        return NDIS_STATUS_INVALID_DATA;
    case IONIC_RC_EPERM:
        return NDIS_STATUS_FAILURE;
    case IONIC_RC_ENOENT:
        return NDIS_STATUS_NOT_SUPPORTED;
    case IONIC_RC_EAGAIN:
        return NDIS_STATUS_RESOURCES;
    case IONIC_RC_ENOMEM:
        return NDIS_STATUS_RESOURCES;
    case IONIC_RC_EFAULT:
        return NDIS_STATUS_FAILURE;
    case IONIC_RC_EBUSY:
        return NDIS_STATUS_FAILURE;
    case IONIC_RC_EEXIST:
        return NDIS_STATUS_FAILURE;
    case IONIC_RC_ENOSPC:
        return NDIS_STATUS_RESOURCES;
    case IONIC_RC_ERANGE:
        return NDIS_STATUS_RESOURCES;
    case IONIC_RC_BAD_ADDR:
        return NDIS_STATUS_INVALID_ADDRESS;
    case IONIC_RC_EOPCODE:
    case IONIC_RC_EINTR:
    case IONIC_RC_DEV_CMD:
    case IONIC_RC_ERROR:
    case IONIC_RC_ERDMA:
    case IONIC_RC_EIO:
    default:
        return NDIS_STATUS_FAILURE;
    }
}

/* Devcmd Interface */
int
ionic_heartbeat_check(struct ionic *ionic)
{
    struct ionic_dev *idev = &ionic->idev;
    u32 fw_status;
    LARGE_INTEGER current_time;
    LARGE_INTEGER delta_time;
    u32 hb = 0;

    KeQuerySystemTime(&current_time);

    if (idev->last_hb_time == 0) {
        idev->last_hb_time = current_time.QuadPart;
        return 0;
    }

    delta_time.QuadPart = current_time.QuadPart - idev->last_hb_time;

    if (delta_time.QuadPart <= 10000000) {
        return 0;
    }

    /* don't check heartbeat on the internal platform device */
    // if (ionic->pfdev)
    //	return 0;

    /* wait at least one second before testing again */
    // hb_time = jiffies;
    // if (time_before(hb_time, (idev->last_hb_time + HZ)))
    //	return 0;

    /* firmware is useful only if fw_status is non-zero */
    fw_status = ioread32(&idev->dev_info_regs->fw_status);
    if (fw_status == 0xFF || !fw_status)
        return NDIS_STATUS_FAILURE;

    /* early FW has no heartbeat, else FW will return non-zero */
    hb = ioread32(&idev->dev_info_regs->fw_heartbeat);
    if (!hb)
        return 0;

    /* are we stalled? */
    if (hb == idev->last_hb) {
        /* only complain once for each stall seen */
        if (idev->last_hb_time != 1) {
            DbgTrace((TRACE_COMPONENT_DEVICE, TRACE_LEVEL_ERROR,
                      "%s FW heartbeat stalled at %d\n", __FUNCTION__,
                      idev->last_hb));
            idev->last_hb_time = 1;
        } else {
            DbgTrace((TRACE_COMPONENT_DEVICE, TRACE_LEVEL_ERROR,
                      "%s Stalled detection\n", __FUNCTION__));
            return NDIS_STATUS_FAILURE;
        }
    }

    if (idev->last_hb_time == 1)
        DbgTrace((TRACE_COMPONENT_DEVICE, TRACE_LEVEL_WARNING,
                  "%s FW heartbeat restored at %d\n", __FUNCTION__, hb));

    idev->last_hb = hb;
    idev->last_hb_time = current_time.QuadPart;

    return 0;
}

void
ionic_watchdog_cb(void *SystemContext,
                  void *FunctionContext,
                  void *Context1,
                  void *Context2)
{

    UNREFERENCED_PARAMETER(SystemContext);
    UNREFERENCED_PARAMETER(Context1);
    UNREFERENCED_PARAMETER(Context2);

    ionic_flush((struct ionic *)FunctionContext);

#ifdef TRACK_MEMORY_BUFFER_ALLOC
    validate_memory();
#endif

    return;
}

void
_dump_message_table(PIO_INTERRUPT_MESSAGE_INFO int_msg_info)
{
    PIO_INTERRUPT_MESSAGE_INFO_ENTRY msg_info_entry =
        &int_msg_info->MessageInfo[0];

    DbgTrace((TRACE_COMPONENT_DEVICE, TRACE_LEVEL_VERBOSE, "Message Count %d\n",
              int_msg_info->MessageCount));
    DbgTrace(
        (TRACE_COMPONENT_DEVICE, TRACE_LEVEL_VERBOSE,
         "============================================================\n"));
    for (unsigned int i = 0; i < int_msg_info->MessageCount; i++) {

        DbgTrace(
            (TRACE_COMPONENT_DEVICE, TRACE_LEVEL_VERBOSE,
             "|Mode = %s | Vector %d |"
             " Message Address %p | Message Data %d | Processor Set %p |\n",
             (msg_info_entry->Mode ? "Latched" : "LevelSensitive"),
             msg_info_entry->Vector, msg_info_entry->MessageAddress,
             msg_info_entry->MessageData, msg_info_entry->TargetProcessorSet));

        msg_info_entry++;
    }
    DbgTrace(
        (TRACE_COMPONENT_DEVICE, TRACE_LEVEL_VERBOSE,
         "============================================================\n"));

    return;
}

static inline bool
ionic_is_mnic(struct ionic *ionic)
{
    return (ionic->pci_config.DeviceID ==
            PCI_DEVICE_ID_PENSANDO_IONIC_ETH_MGMT);
}

static __le64
ionic_netdev_features_to_nic(netdev_features_t features)
{
    u64 wanted = 0;

    if (features & NETIF_F_HW_VLAN_CTAG_TX)
        wanted |= ETH_HW_VLAN_TX_TAG;
    if (features & NETIF_F_HW_VLAN_CTAG_RX)
        wanted |= ETH_HW_VLAN_RX_STRIP;
    if (features & NETIF_F_HW_VLAN_CTAG_FILTER)
        wanted |= ETH_HW_VLAN_RX_FILTER;
    if (features & NETIF_F_RXHASH)
        wanted |= ETH_HW_RX_HASH;
    if (features & NETIF_F_RXCSUM)
        wanted |= ETH_HW_RX_CSUM;
    if (features & NETIF_F_SG)
        wanted |= ETH_HW_TX_SG;
    if (features & NETIF_F_HW_CSUM)
        wanted |= ETH_HW_TX_CSUM;
    if (features & NETIF_F_TSO)
        wanted |= ETH_HW_TSO;
    if (features & NETIF_F_TSO6)
        wanted |= ETH_HW_TSO_IPV6;
    if (features & NETIF_F_TSO_ECN)
        wanted |= ETH_HW_TSO_ECN;
    if (features & NETIF_F_GSO_GRE)
        wanted |= ETH_HW_TSO_GRE;
    if (features & NETIF_F_GSO_GRE_CSUM)
        wanted |= ETH_HW_TSO_GRE_CSUM;
#ifdef NETIF_F_GSO_IPXIP4
    if (features & NETIF_F_GSO_IPXIP4)
        wanted |= ETH_HW_TSO_IPXIP4;
#endif
#ifdef NETIF_F_GSO_IPXIP6
    if (features & NETIF_F_GSO_IPXIP6)
        wanted |= ETH_HW_TSO_IPXIP6;
#endif
    if (features & NETIF_F_GSO_UDP_TUNNEL)
        wanted |= ETH_HW_TSO_UDP;
    if (features & NETIF_F_GSO_UDP_TUNNEL_CSUM)
        wanted |= ETH_HW_TSO_UDP_CSUM;

    return cpu_to_le64(wanted);
}

static NDIS_STATUS
ionic_set_nic_features(struct lif *lif, netdev_features_t features)
{

    NDIS_STATUS status = NDIS_STATUS_SUCCESS;
    struct ionic_admin_ctx ctx = {0};

    ctx.cmd.lif_setattr.opcode = CMD_OPCODE_LIF_SETATTR;
    ctx.cmd.lif_setattr.index = (__le16)cpu_to_le16(lif->index);
    ctx.cmd.lif_setattr.attr = IONIC_LIF_ATTR_FEATURES;

    u64 vlan_flags =
        ETH_HW_VLAN_TX_TAG | ETH_HW_VLAN_RX_STRIP | ETH_HW_VLAN_RX_FILTER;

    ctx.cmd.lif_setattr.features = ionic_netdev_features_to_nic(features);

    status = ionic_adminq_post_wait(lif, &ctx);
    if (status != NDIS_STATUS_SUCCESS)
        return status;

    lif->hw_features = le64_to_cpu(ctx.cmd.lif_setattr.features &
                                   ctx.comp.lif_setattr.features);

    if ((vlan_flags & features) &&
        !(vlan_flags & le64_to_cpu(ctx.comp.lif_setattr.features)))
        DbgTrace((
            TRACE_COMPONENT_INIT, TRACE_LEVEL_VERBOSE,
            "\tNIC is not supporting vlan offload, likely in SmartNIC mode\n"));

    if (lif->hw_features & ETH_HW_VLAN_TX_TAG)
        DbgTrace((TRACE_COMPONENT_INIT, TRACE_LEVEL_VERBOSE,
                  "\tfeature ETH_HW_VLAN_TX_TAG\n"));
    if (lif->hw_features & ETH_HW_VLAN_RX_STRIP)
        DbgTrace((TRACE_COMPONENT_INIT, TRACE_LEVEL_VERBOSE,
                  "\tfeature ETH_HW_VLAN_RX_STRIP\n"));
    if (lif->hw_features & ETH_HW_VLAN_RX_FILTER)
        DbgTrace((TRACE_COMPONENT_INIT, TRACE_LEVEL_VERBOSE,
                  "\tfeature ETH_HW_VLAN_RX_FILTER\n"));
    if (lif->hw_features & ETH_HW_RX_HASH)
        DbgTrace((TRACE_COMPONENT_INIT, TRACE_LEVEL_VERBOSE,
                  "\tfeature ETH_HW_RX_HASH\n"));
    if (lif->hw_features & ETH_HW_TX_SG)
        DbgTrace((TRACE_COMPONENT_INIT, TRACE_LEVEL_VERBOSE,
                  "\tfeature ETH_HW_TX_SG\n"));
    if (lif->hw_features & ETH_HW_TX_CSUM)
        DbgTrace((TRACE_COMPONENT_INIT, TRACE_LEVEL_VERBOSE,
                  "\tfeature ETH_HW_TX_CSUM\n"));
    if (lif->hw_features & ETH_HW_RX_CSUM)
        DbgTrace((TRACE_COMPONENT_INIT, TRACE_LEVEL_VERBOSE,
                  "\tfeature ETH_HW_RX_CSUM\n"));
    if (lif->hw_features & ETH_HW_TSO)
        DbgTrace((TRACE_COMPONENT_INIT, TRACE_LEVEL_VERBOSE,
                  "\tfeature ETH_HW_TSO\n"));
    if (lif->hw_features & ETH_HW_TSO_IPV6)
        DbgTrace((TRACE_COMPONENT_INIT, TRACE_LEVEL_VERBOSE,
                  "\tfeature ETH_HW_TSO_IPV6\n"));
    if (lif->hw_features & ETH_HW_TSO_ECN)
        DbgTrace((TRACE_COMPONENT_INIT, TRACE_LEVEL_VERBOSE,
                  "\tfeature ETH_HW_TSO_ECN\n"));
    if (lif->hw_features & ETH_HW_TSO_GRE)
        DbgTrace((TRACE_COMPONENT_INIT, TRACE_LEVEL_VERBOSE,
                  "\tfeature ETH_HW_TSO_GRE\n"));
    if (lif->hw_features & ETH_HW_TSO_GRE_CSUM)
        DbgTrace((TRACE_COMPONENT_INIT, TRACE_LEVEL_VERBOSE,
                  "\tfeature ETH_HW_TSO_GRE_CSUM\n"));
    if (lif->hw_features & ETH_HW_TSO_IPXIP4)
        DbgTrace((TRACE_COMPONENT_INIT, TRACE_LEVEL_VERBOSE,
                  "\tfeature ETH_HW_TSO_IPXIP4\n"));
    if (lif->hw_features & ETH_HW_TSO_IPXIP6)
        DbgTrace((TRACE_COMPONENT_INIT, TRACE_LEVEL_VERBOSE,
                  "\tfeature ETH_HW_TSO_IPXIP6\n"));
    if (lif->hw_features & ETH_HW_TSO_UDP)
        DbgTrace((TRACE_COMPONENT_INIT, TRACE_LEVEL_VERBOSE,
                  "\tfeature ETH_HW_TSO_UDP\n"));
    if (lif->hw_features & ETH_HW_TSO_UDP_CSUM)
        DbgTrace((TRACE_COMPONENT_INIT, TRACE_LEVEL_VERBOSE,
                  "\tfeature ETH_HW_TSO_UDP_CSUM\n"));

    return NDIS_STATUS_SUCCESS;
}

int
ionic_init_nic_features(struct lif *lif)
{

    //	struct net_device *netdev = lif->netdev;
    netdev_features_t features;
    int err;

    /* set up what we expect to support by default */
    features = NETIF_F_HW_VLAN_CTAG_TX | NETIF_F_HW_VLAN_CTAG_RX |
               NETIF_F_HW_VLAN_CTAG_FILTER | NETIF_F_SG | NETIF_F_HW_CSUM |
               NETIF_F_RXCSUM | NETIF_F_TSO | NETIF_F_TSO6 | NETIF_F_TSO_ECN;

    if (!ionic_is_mnic(lif->ionic))
        features |= NETIF_F_RXHASH;

    err = ionic_set_nic_features(lif, features);
    if (err)
        return err;

    if (!is_master_lif(lif))
        return 0;

#if 0
	/* tell the netdev what we actually can support */
	netdev->features |= NETIF_F_HIGHDMA;

	if (lif->hw_features & ETH_HW_VLAN_TX_TAG)
		netdev->hw_features |= NETIF_F_HW_VLAN_CTAG_TX;
	if (lif->hw_features & ETH_HW_VLAN_RX_STRIP)
		netdev->hw_features |= NETIF_F_HW_VLAN_CTAG_RX;
	if (lif->hw_features & ETH_HW_VLAN_RX_FILTER)
		netdev->hw_features |= NETIF_F_HW_VLAN_CTAG_FILTER;
	if (lif->hw_features & ETH_HW_RX_HASH)
		netdev->hw_features |= NETIF_F_RXHASH;
	if (lif->hw_features & ETH_HW_TX_SG)
		netdev->hw_features |= NETIF_F_SG;

	if (lif->hw_features & ETH_HW_TX_CSUM)
		netdev->hw_enc_features |= NETIF_F_HW_CSUM;
	if (lif->hw_features & ETH_HW_RX_CSUM)
		netdev->hw_enc_features |= NETIF_F_RXCSUM;
	if (lif->hw_features & ETH_HW_TSO)
		netdev->hw_enc_features |= NETIF_F_TSO;
	if (lif->hw_features & ETH_HW_TSO_IPV6)
		netdev->hw_enc_features |= NETIF_F_TSO6;
	if (lif->hw_features & ETH_HW_TSO_ECN)
		netdev->hw_enc_features |= NETIF_F_TSO_ECN;
	if (lif->hw_features & ETH_HW_TSO_GRE)
		netdev->hw_enc_features |= NETIF_F_GSO_GRE;
	if (lif->hw_features & ETH_HW_TSO_GRE_CSUM)
		netdev->hw_enc_features |= NETIF_F_GSO_GRE_CSUM;
#ifdef NETIF_F_GSO_IPXIP4
	if (lif->hw_features & ETH_HW_TSO_IPXIP4)
		netdev->hw_enc_features |= NETIF_F_GSO_IPXIP4;
#endif
#ifdef NETIF_F_GSO_IPXIP6
	if (lif->hw_features & ETH_HW_TSO_IPXIP6)
		netdev->hw_enc_features |= NETIF_F_GSO_IPXIP6;
#endif
	if (lif->hw_features & ETH_HW_TSO_UDP)
		netdev->hw_enc_features |= NETIF_F_GSO_UDP_TUNNEL;
	if (lif->hw_features & ETH_HW_TSO_UDP_CSUM)
		netdev->hw_enc_features |= NETIF_F_GSO_UDP_TUNNEL_CSUM;

	netdev->hw_features |= netdev->hw_enc_features;
	netdev->features |= netdev->hw_features;

	/* some earlier kernels complain if the vlan device inherits
	 * the NETIF_F_HW_VLAN... flags, so strip them out
	 */
	netdev->vlan_features |= netdev->features & ~(NETIF_F_HW_VLAN_CTAG_TX |
						      NETIF_F_HW_VLAN_CTAG_RX |
						   NETIF_F_HW_VLAN_CTAG_FILTER);

	/* Leave L2FW_OFFLOAD out of netdev->features so it will
	 * be disabled by default, but the user can enable later.
	 */
	if (lif->ionic->nslaves)
		netdev->hw_features |= NETIF_F_HW_L2FW_DOFFLOAD;

	netdev->priv_flags |= IFF_UNICAST_FLT;
#endif

    return 0;
}

void
ionic_indicate_status(struct ionic *ionic,
                      NDIS_STATUS code,
                      PVOID StatusBuffer,
                      ULONG StatusBufferSize)
{
    NDIS_STATUS_INDICATION status;

    NdisZeroMemory(&status, sizeof(NDIS_STATUS_INDICATION));
    status.Header.Type = NDIS_OBJECT_TYPE_STATUS_INDICATION;
    status.Header.Revision = NDIS_STATUS_INDICATION_REVISION_1;
    status.Header.Size = NDIS_SIZEOF_STATUS_INDICATION_REVISION_1;
    status.StatusCode = code;
    status.SourceHandle = ionic->adapterhandle;
    status.StatusBuffer = StatusBuffer;
    status.StatusBufferSize = StatusBufferSize;
    NdisMIndicateStatusEx(ionic->adapterhandle, &status);
}

void
ionic_link_up(struct ionic *ionic)
{
    NDIS_LINK_STATE LinkState;
    ULONGLONG link_spd = 0;

    DbgTrace((TRACE_COMPONENT_LINK, TRACE_LEVEL_VERBOSE, "%s Setting link UP\n",
              __FUNCTION__));

    NdisZeroMemory(&LinkState, sizeof(NDIS_LINK_STATE));

    LinkState.Header.Revision = NDIS_LINK_STATE_REVISION_1;
    LinkState.Header.Type = NDIS_OBJECT_TYPE_DEFAULT;
    LinkState.Header.Size =
        NDIS_SIZEOF_STATUS_INDICATION_REVISION_1;
    LinkState.MediaConnectState = MediaConnectStateConnected;
    LinkState.MediaDuplexState = MediaDuplexStateFull;

    link_spd =  le32_to_cpu(ionic->master_lif->info->status.link_speed);
    link_spd *= MEGABITS_PER_SECOND;

    LinkState.XmitLinkSpeed = LinkState.RcvLinkSpeed = link_spd;

    LinkState.AutoNegotiationFlags = NDIS_LINK_STATE_XMIT_LINK_SPEED_AUTO_NEGOTIATED |
                                            NDIS_LINK_STATE_RCV_LINK_SPEED_AUTO_NEGOTIATED;

    // Set flow control attributes
    if( ionic->flow_control == IONIC_FC_DISABLED) {
        LinkState.PauseFunctions = NdisPauseFunctionsUnsupported;
    }
    else if (ionic->flow_control == IONIC_FC_RX_ENABLED) {
        LinkState.PauseFunctions = NdisPauseFunctionsReceiveOnly;
    }
    else if (ionic->flow_control == IONIC_FC_TX_ENABLED) {
        LinkState.PauseFunctions = NdisPauseFunctionsSendOnly;
    }
    else if (ionic->flow_control == IONIC_FC_TXRX_ENABLED) {
        LinkState.PauseFunctions = NdisPauseFunctionsSendAndReceive;
    }

    ionic_indicate_status(ionic, NDIS_STATUS_LINK_STATE, (PVOID)&LinkState,
                          sizeof(LinkState));

    ionic->port_stats.link_up++;
}

void
ionic_link_down(struct ionic *ionic)
{
    NDIS_LINK_STATE LinkState;

    DbgTrace((TRACE_COMPONENT_LINK, TRACE_LEVEL_VERBOSE,
              "%s Setting link DOWN\n", __FUNCTION__));

    NdisZeroMemory(&LinkState, sizeof(NDIS_LINK_STATE));

    LinkState.Header.Revision = NDIS_LINK_STATE_REVISION_1;
    LinkState.Header.Type = NDIS_OBJECT_TYPE_DEFAULT;
    LinkState.Header.Size =
        NDIS_SIZEOF_STATUS_INDICATION_REVISION_1; // sizeof(NDIS_LINK_STATE);
    LinkState.MediaConnectState = MediaConnectStateDisconnected;
    LinkState.MediaDuplexState = MediaDuplexStateUnknown;
    LinkState.XmitLinkSpeed = LinkState.RcvLinkSpeed = NDIS_LINK_SPEED_UNKNOWN;
    LinkState.PauseFunctions = NdisPauseFunctionsUnknown;

    ionic_indicate_status(ionic, NDIS_STATUS_LINK_STATE, (PVOID)&LinkState,
                          sizeof(LinkState));

    ionic->port_stats.link_dn++;
}

void
ionic_link_status_check(struct lif *lif, u16 link_status)
{

    NTSTATUS status = STATUS_SUCCESS;
    bool link_up;
    LARGE_INTEGER time_out;
    BOOLEAN set_event = FALSE;

    if( link_status == PORT_OPER_STATUS_NONE) {
        link_status = le16_to_cpu(lif->info->status.link_status);
    }
    link_up = link_status == PORT_OPER_STATUS_UP;

    time_out.QuadPart = -(IONIC_ONE_SEC_WAIT * 10);
    status = KeWaitForSingleObject(&lif->state_change, Executive, KernelMode,
                                   FALSE, &time_out);

    if (status != STATUS_SUCCESS) {
        goto cleanup;
    }
    set_event = TRUE;

    RtlClearBit(&lif->state, LIF_LINK_CHECK_NEEDED);

    if (link_up) {
        DbgTrace((TRACE_COMPONENT_LINK, TRACE_LEVEL_VERBOSE,
                  "%s Link up - %d Gbps\n", __FUNCTION__,
                  le32_to_cpu(lif->info->status.link_speed) / 1000));

        if (!RtlCheckBit(&lif->state, LIF_UP)) {
            status = ionic_start(lif->ionic);
            if( status == NDIS_STATUS_SUCCESS) {
                ionic_link_up(lif->ionic);
            }
        }
    } else {
        DbgTrace((TRACE_COMPONENT_LINK, TRACE_LEVEL_VERBOSE, "%s Link down\n",
                  __FUNCTION__));

        if (RtlCheckBit(&lif->state, LIF_UP)) {
            ionic_stop(lif->ionic);
            ionic_link_down(lif->ionic);
        }
    }

cleanup:
    if (set_event) {
        KeSetEvent(&lif->state_change, 0, FALSE);
    }

    return;
}

int
is_multicast_ether_addr(const u8 *addr)
{
    return addr[0] & 0x01;
}

unsigned int
hash_32_generic(u32 val)
{
    return val * GOLDEN_RATIO_32;
}

unsigned int
hash_32(u32 val, unsigned int bits)
{

    return hash_32_generic(val) >> (32 - bits);
}

int
is_zero_ether_addr(const u8 *addr)
{
    return !(addr[0] | addr[1] | addr[2] | addr[3] | addr[4] | addr[5]);
}

int
_isascii(u8 c)
{

    if (c >= 0x00 && c <= 0x7F)
        return 1;

    return 0;
}

static void
hex_dump_to_buffer(const void *buf,
                   size_t len,
                   int rowsize,
                   int groupsize,
                   unsigned char *linebuf,
                   size_t linebuflen,
                   bool ascii)
{
    const u8 *ptr = (const u8 *)buf;
    u8 ch;
    int j, lx = 0;
    int ascii_column;

    if (rowsize != 16 && rowsize != 32)
        rowsize = 16;

    if (!len)
        goto nil;
    if (len > rowsize) /* limit to one line at a time */
        len = rowsize;
    if ((len % groupsize) != 0) /* no mixed size output */
        groupsize = 1;

    switch (groupsize) {
    case 8: {
        const u64 *ptr8 = (const u64 *)buf;
        int ngroups = (int)(len / groupsize);

        for (j = 0; j < ngroups; j++)
            lx += sprintf_s((char *)(linebuf + lx), linebuflen - lx,
                            "%s%16.16llx", j ? " " : "",
                            (unsigned long long)*(ptr8 + j));
        ascii_column = 17 * ngroups + 2;
        break;
    }

    case 4: {
        const u32 *ptr4 = (const u32 *)buf;
        int ngroups = (int)(len / groupsize);

        for (j = 0; j < ngroups; j++)
            lx += sprintf_s((char *)(linebuf + lx), linebuflen - lx, "%s%8.8x",
                            j ? " " : "", *(ptr4 + j));
        ascii_column = 9 * ngroups + 2;
        break;
    }

    case 2: {
        const u16 *ptr2 = (const u16 *)buf;
        int ngroups = (int)(len / groupsize);

        for (j = 0; j < ngroups; j++)
            lx += sprintf_s((char *)(linebuf + lx), linebuflen - lx, "%s%4.4x",
                            j ? " " : "", *(ptr2 + j));
        ascii_column = 5 * ngroups + 2;
        break;
    }

    default:
        for (j = 0; (j < len) && (lx + 3) <= linebuflen; j++) {
            ch = ptr[j];
            linebuf[lx++] = hex_asc(ch >> 4);
            linebuf[lx++] = hex_asc(ch & 0x0f);
            linebuf[lx++] = ' ';
        }
        if (j)
            lx--;

        ascii_column = 3 * rowsize + 2;
        break;
    }
    if (!ascii)
        goto nil;

    while (lx < (linebuflen - 1) && lx < (ascii_column - 1))
        linebuf[lx++] = ' ';
    for (j = 0; (j < len) && (lx + 2) < linebuflen; j++)
        linebuf[lx++] = (_isascii(ptr[j]) && isprint(ptr[j])) ? ptr[j] : '.';
nil:
    linebuf[lx++] = '\0';
}

void
print_hex_dump(const char *prefix_str,
               int prefix_type,
               int rowsize,
               int groupsize,
               const void *buf,
               size_t len,
               bool ascii)
{
    const u8 *ptr = (const u8 *)buf;
    int i, linelen, remaining = (int)len;
    unsigned char linebuf[200];

    UNREFERENCED_PARAMETER(prefix_str);

    if (rowsize != 16 && rowsize != 32)
        rowsize = 16;

    for (i = 0; i < len; i += rowsize) {
        linelen = min(remaining, rowsize);
        remaining -= rowsize;
        hex_dump_to_buffer(ptr + i, linelen, rowsize, groupsize, linebuf,
                           sizeof(linebuf), ascii);

        switch (prefix_type) {
        case DUMP_PREFIX_ADDRESS:
            DbgTrace((TRACE_COMPONENT_GENERAL, TRACE_LEVEL_VERBOSE,
                      "%s%*p: %s\n", prefix_str, (int)(2 * sizeof(void *)),
                      ptr + i, linebuf));
            break;
        case DUMP_PREFIX_OFFSET:
            DbgTrace((TRACE_COMPONENT_GENERAL, TRACE_LEVEL_VERBOSE,
                      "%s%.8x: %s\n", prefix_str, i, linebuf));
            break;
        default:
            DbgTrace((TRACE_COMPONENT_GENERAL, TRACE_LEVEL_VERBOSE, "%s%s\n",
                      prefix_str, linebuf));
            break;
        }
    }
}

void
IoPrint(IN char *Format, ...)
{
    va_list vaArgPtr;

    va_start(vaArgPtr, Format);

    vDbgPrintEx(DPFLTR_IHVDRIVER_ID, DPFLTR_INFO_LEVEL, Format, vaArgPtr);

    va_end(vaArgPtr);

    return;
}

NDIS_STATUS
UpdateRegistryParameter(IN PUNICODE_STRING ValueName,
                        IN ULONG ValueType,
                        IN void *ValueData,
                        IN ULONG ValueDataLength)
{

    NDIS_STATUS ndisStatus = NDIS_STATUS_SUCCESS;
    NDIS_CONFIGURATION_OBJECT stConfig;
    NDIS_CONFIGURATION_PARAMETER stConfigParam;
    NDIS_HANDLE hConfig = NULL;

    UNREFERENCED_PARAMETER(ValueType);
    UNREFERENCED_PARAMETER(ValueDataLength);

    //
    // Open a handle to the configuration space in the registry for the miniport
    // driver.
    //

    stConfig.Header.Type = NDIS_OBJECT_TYPE_CONFIGURATION_OBJECT;
    stConfig.Header.Revision = NDIS_CONFIGURATION_OBJECT_REVISION_1;
    stConfig.Header.Size = NDIS_SIZEOF_CONFIGURATION_OBJECT_REVISION_1;

    stConfig.NdisHandle = IonicDriver;

    stConfig.Flags = 0;

    ndisStatus = NdisOpenConfigurationEx(&stConfig, &hConfig);

    if (ndisStatus != NDIS_STATUS_SUCCESS) {

        DbgTrace((TRACE_COMPONENT_GENERAL, TRACE_LEVEL_ERROR,
                  "%s Failed to open config space Status %08lX\n", __FUNCTION__,
                  ndisStatus));
        goto cleanup;
    }

    stConfigParam.ParameterType = NdisParameterInteger;
    stConfigParam.ParameterData.IntegerData = *((PULONG)ValueData);

    NdisWriteConfiguration(&ndisStatus, hConfig, ValueName, &stConfigParam);

cleanup:

    if (hConfig != NULL) {
        NdisCloseConfiguration(hConfig);
    }

    return ndisStatus;
}

NDIS_STATUS
ReadConfigParams()
{

    NDIS_STATUS ndisStatus = NDIS_STATUS_SUCCESS;
    NDIS_CONFIGURATION_OBJECT stConfig;
    NDIS_STRING uniValue;
    PNDIS_CONFIGURATION_PARAMETER pConfigParam = NULL;
    NDIS_HANDLE hConfig = NULL;

    //
    // Open a handle to the configuration space in the registry for the miniport
    // driver.
    //

    stConfig.Header.Type = NDIS_OBJECT_TYPE_CONFIGURATION_OBJECT;
    stConfig.Header.Revision = NDIS_CONFIGURATION_OBJECT_REVISION_1;
    stConfig.Header.Size = NDIS_SIZEOF_CONFIGURATION_OBJECT_REVISION_1;

    stConfig.NdisHandle = IonicDriver;

    stConfig.Flags = 0;

    ndisStatus = NdisOpenConfigurationEx(&stConfig, &hConfig);

    if (ndisStatus != NDIS_STATUS_SUCCESS) {

        DbgTrace((TRACE_COMPONENT_GENERAL, TRACE_LEVEL_ERROR,
                  "%s Failed to open config space Status %08lX\n", __FUNCTION__,
                  ndisStatus));
        goto cleanup;
    }

    NdisInitUnicodeString(&uniValue, REG_TRACE_FLAGS);

    NdisReadConfiguration(&ndisStatus, &pConfigParam, hConfig, &uniValue,
                          NdisParameterInteger);

    if (ndisStatus == NDIS_STATUS_SUCCESS) {
        TraceFlags = pConfigParam->ParameterData.IntegerData;
    }

#ifdef DBG
    if (TraceFlags == 0) {
        //TraceFlags = 1;
    }
#endif

    NdisInitUnicodeString(&uniValue, REG_TRACE_COMPONENT);

    NdisReadConfiguration(&ndisStatus, &pConfigParam, hConfig, &uniValue,
                          NdisParameterInteger);

    if (ndisStatus == NDIS_STATUS_SUCCESS) {
        TraceComponent = pConfigParam->ParameterData.IntegerData;
    }

#ifdef DBG
    if (TraceComponent == 0) {
        TraceComponent = 0xFFFFFFFF;
    }
#endif

    NdisInitUnicodeString(&uniValue, REG_TRACE_BUFFER_LENGTH);

    NdisReadConfiguration(&ndisStatus, &pConfigParam, hConfig, &uniValue,
                          NdisParameterInteger);

    if (ndisStatus == NDIS_STATUS_SUCCESS) {
        TraceBufferLength = pConfigParam->ParameterData.IntegerData;
        if (TraceBufferLength > MAXIMUM_TRACE_BUFFER_SIZE) {
            TraceBufferLength = MAXIMUM_TRACE_BUFFER_SIZE;
        }
        TraceBufferLength *= 1024;
    }

#ifdef DBG
    if (TraceBufferLength == 0) {
        //TraceBufferLength = (5 * 1024);
    }
#endif

    NdisInitUnicodeString(&uniValue, REG_TRACE_LEVEL);

    NdisReadConfiguration(&ndisStatus, &pConfigParam, hConfig, &uniValue,
                          NdisParameterInteger);

    if (ndisStatus == NDIS_STATUS_SUCCESS) {

        TraceLevel = pConfigParam->ParameterData.IntegerData;

        if (TraceLevel > TRACE_LEVEL_MAXIMUM) {
            TraceLevel = TRACE_LEVEL_MAXIMUM;
        }
    }

#ifdef DBG
    if (TraceLevel == 0) {
        TraceLevel = TRACE_LEVEL_ERROR;
    }
#endif

    NdisInitUnicodeString(&uniValue, REG_RX_BUDGET);

    NdisReadConfiguration(&ndisStatus, &pConfigParam, hConfig, &uniValue,
                          NdisParameterInteger);

    if (ndisStatus == NDIS_STATUS_SUCCESS) {
        RxBudget = pConfigParam->ParameterData.IntegerData;
    }

    ndisStatus = NDIS_STATUS_SUCCESS;

cleanup:

    if (hConfig != NULL) {
        NdisCloseConfiguration(hConfig);
    }

    return ndisStatus;
}

char *
GetHyperVPartitionTypeString(ULONG PartitionType)
{

    char *pName = "NdisHypervisorPartitionTypeUnknown";

    switch (PartitionType) {

    case NdisHypervisorPartitionTypeMsHvParent: {
        pName = "NdisHypervisorPartitionTypeMsHvParent";
        break;
    }

    case NdisHypervisorPartitionMsHvChild: {
        pName = "NdisHypervisorPartitionMsHvChild";
        break;
    }
    }

    return pName;
}

BOOLEAN
ValidateGroupAffinity(PGROUP_AFFINITY GroupAffinity)
{
    BOOLEAN bValid = TRUE;
    UCHAR ucProcessorNumber =
        RtlFindLeastSignificantBit((ULONGLONG)GroupAffinity->Mask);
    ULONG ulActiveProcessors =
        KeQueryActiveProcessorCountEx(GroupAffinity->Group);

    if (ulActiveProcessors == 0) {
        bValid = FALSE;
    } else if (ucProcessorNumber == -1) {
        bValid = FALSE;
    } else if (ucProcessorNumber >= (UCHAR)ulActiveProcessors) {
        bValid = FALSE;
    }

    return bValid;
}

u32
GetNextProcIndex(ULONG_PTR Mask, ULONG_PTR MaskIndex)
{

    ULONG_PTR procIndex = 0;
    ULONG proc = (ULONG)MaskIndex;

    procIndex = (ULONG_PTR)1 << MaskIndex;

    while ((procIndex & Mask) == 0) {
        MaskIndex++;
        procIndex = ((ULONG_PTR)1 << MaskIndex);

        proc++;

        if (proc == 64) {
            proc = INVALID_PROCESSOR_INDEX;
            break;
        }
    }

    return proc;
}

void *
LockBuffer(void *Buffer, ULONG BufferLength, MDL **Mdl)
{

    void *pSystemBuffer = NULL;
    MDL *pMdl = NULL;

    pMdl = IoAllocateMdl(Buffer, BufferLength, FALSE, FALSE, NULL);

    if (pMdl == NULL) {
        goto cleanup;
    }

    __try {
        MmProbeAndLockPages(pMdl, KernelMode, IoWriteAccess);

        pSystemBuffer = MmGetSystemAddressForMdlSafe(pMdl, NormalPagePriority);

        if (pSystemBuffer == NULL) {
            IoFreeMdl(pMdl);
        } else {
            *Mdl = pMdl;
        }
    } __except (EXCEPTION_EXECUTE_HANDLER) {
        IoFreeMdl(pMdl);
    }

cleanup:

    return pSystemBuffer;
}

static inline unsigned short int
csum_tcpudp_magic(unsigned long saddr,
                  unsigned long daddr,
                  unsigned short len,
                  unsigned short proto,
                  unsigned int sum)
{
    return csum_fold(csum_tcpudp_nofold(saddr, daddr, len, proto, sum));
}

void
ionic_tx_tcp_pseudo_csum(unsigned char *IpHdr,
                         unsigned char *TcpHdr,
                         ULONG IpVersion)
{

    struct ipv4hdr *pIpHdr_v4 = NULL;
    struct ipv6hdr *pIpHdr_v6 = NULL;
    struct tcphdr *pTcpHdr = NULL;

    if (IpVersion == NDIS_TCP_LARGE_SEND_OFFLOAD_IPv4) {

        pIpHdr_v4 = (struct ipv4hdr *)IpHdr;
        pTcpHdr = (struct tcphdr *)TcpHdr;

        pIpHdr_v4->check = 0;
        pTcpHdr->check = ~csum_tcpudp_magic(pIpHdr_v4->saddr, pIpHdr_v4->daddr,
                                            0, IPPROTO_TCP, 0);
    } else {

        pIpHdr_v6 = (struct ipv6hdr *)IpHdr;
        pTcpHdr = (struct tcphdr *)TcpHdr;

        pTcpHdr->check = ~csum_ipv6_magic(&pIpHdr_v6->saddr, &pIpHdr_v6->daddr,
                                          0, IPPROTO_TCP, 0);
    }

    return;
}

USHORT
GetDescriptorCount(NET_BUFFER *NetBuffer, ULONG MSS)
{

    USHORT usCount = 0;
    ULONG packet_len = 0;
    MDL *pMdl = NULL;

    //
    // We need 1 tx descriptor per MSS sized piece of data. The first descriptor
    // will contain the header and up to 1 MSS sized piece of data. Then the
    // rest of teh descriptors will have up to MSS sized piece of data.
    //

    packet_len = NET_BUFFER_DATA_LENGTH(NetBuffer);

    pMdl = NET_BUFFER_CURRENT_MDL(NetBuffer);

    if (packet_len <= (pMdl->ByteCount - NetBuffer->CurrentMdlOffset) + MSS) {
        usCount = 1;
    } else {
        packet_len -= ((pMdl->ByteCount - NetBuffer->CurrentMdlOffset) + MSS);

        usCount = (USHORT)(packet_len / MSS);

        if ((packet_len % MSS) != 0) {
            usCount++;
        }

        usCount++; // for the header and first MSS size of data
    }

    return usCount;
}

void
DumpCompDesc(struct txq_comp *comp)
{
    ULONG count = 0;
    u8 *stream = (u8 *)comp;

    while (count < sizeof(struct txq_comp)) {

        IoPrint("%02lX ", *stream);

        stream++;
        count++;
    }

    IoPrint("\n");

    return;
}

void
DumpDesc(struct txq_desc *desc,
         struct txq_sg_desc *sg_desc,
         u32 sg_count,
         bool start,
         bool done)
{
    ULONG count = 0;
    u8 *stream = (u8 *)desc;

    if (start)
        IoPrint("\tstart\n");

    while (count < sizeof(struct txq_desc)) {

        IoPrint("%02lX ", *stream);

        stream++;
        count++;
    }

    if (sg_count != 0) {

        IoPrint("\n sg desc\n");

        stream = (u8 *)sg_desc;

        count = 0;
        while (count < sg_count * sizeof(struct txq_sg_elem)) {

            IoPrint("%02lX ", *stream);

            stream++;
            count++;
        }

        IoPrint("\n sg desc done\n");
    }

    IoPrint("\n");

    if (done)
        IoPrint("\tdone\n");

    return;
}

NDIS_STATUS
oid_set_interrupt_moderation(struct ionic *ionic,
                             void *info_buffer,
                             ULONG info_buffer_length,
                             ULONG *bytes_read)
{

    NDIS_STATUS ntStatus = NDIS_STATUS_SUCCESS;
    NDIS_INTERRUPT_MODERATION_PARAMETERS *pParams =
        (NDIS_INTERRUPT_MODERATION_PARAMETERS *)info_buffer;
    BOOLEAN bEnable = FALSE;

    DbgTrace((TRACE_COMPONENT_INIT, TRACE_LEVEL_VERBOSE,
              "%s Flags 0x%08lX State 0x%08lX\n", __FUNCTION__, pParams->Flags,
              pParams->InterruptModeration));

    *bytes_read = info_buffer_length;

    if (pParams->InterruptModeration == NdisInterruptModerationEnabled) {
        SetFlag(ionic->ConfigStatus, IONIC_INTERRUPT_MOD_ENABLED);
        bEnable = TRUE;
    } else {
        ClearFlag(ionic->ConfigStatus, IONIC_INTERRUPT_MOD_ENABLED);
    }

    ntStatus = ionic_set_coalesce(ionic, bEnable);

    return ntStatus;
}

BOOLEAN
IsValidAffinity(struct ionic *ionic, GROUP_AFFINITY ProcessorAffinity)
{

    BOOLEAN bValid = FALSE;
    PROCESSOR_NUMBER procNumber;
    u32 procMaskIndex = 0;
    u32 procIndex = 0;

    UNREFERENCED_PARAMETER(ionic);

    if (ProcessorAffinity.Mask == 0) {
        goto cleanup;
    }

    procMaskIndex = GetNextProcIndex(ProcessorAffinity.Mask, procMaskIndex);
    procIndex = 0;

    if (procMaskIndex == INVALID_PROCESSOR_INDEX) {
        goto cleanup;
    }

    procNumber.Reserved = 0;
    procNumber.Group = ProcessorAffinity.Group;
    procNumber.Number = (UCHAR)procMaskIndex;

    procIndex = KeGetProcessorIndexFromNumber(&procNumber);

    if (procIndex == INVALID_PROCESSOR_INDEX) {
        goto cleanup;
    }

    bValid = TRUE;

cleanup:

    return bValid;
}

NDIS_STATUS
oid_query_isolation_info(struct ionic *ionic,
                         void *info_buffer,
                         ULONG info_buffer_length,
                         ULONG *bytes_written)
{

    NDIS_STATUS ntStatus = NDIS_STATUS_SUCCESS;
    // NDIS_ISOLATION_PARAMETERS *pParams = (NDIS_ISOLATION_PARAMETERS
    // *)info_buffer;

    UNREFERENCED_PARAMETER(info_buffer);
    UNREFERENCED_PARAMETER(info_buffer_length);
    UNREFERENCED_PARAMETER(ionic);

    *bytes_written = 0;

    return ntStatus;
}

ULONG
get_frame_type(void *hdr_buffer)
{

    struct ethhdr *hdr = (struct ethhdr *)hdr_buffer;

    if (ETH_IS_BROADCAST(hdr->h_dest)) {
        return NDIS_PACKET_TYPE_BROADCAST;
    } else if (ETH_IS_MULTICAST(hdr->h_dest)) {
        return NDIS_PACKET_TYPE_MULTICAST;
    } else {
        return NDIS_PACKET_TYPE_DIRECTED;
    }
}

NDIS_STATUS
oid_set_vlan(struct ionic *ionic,
             void *info_buffer,
             ULONG info_buffer_length,
             ULONG *bytes_needed,
             ULONG *bytes_read)
{

    NDIS_STATUS ntStatus = NDIS_STATUS_SUCCESS;
    USHORT vlan_id = 0;

    DbgTrace((TRACE_COMPONENT_INIT, TRACE_LEVEL_VERBOSE,
              "%s Adapter %p Entry\n", __FUNCTION__, ionic));

    if (info_buffer_length != sizeof(ULONG)) {
        ntStatus = NDIS_STATUS_INVALID_LENGTH;
        *bytes_needed = sizeof(ULONG);
        goto cleanup;
    }

    vlan_id = (unsigned short)(*(ULONG *)info_buffer &
                               0xFFF); // least sig 12 bits are valid

    DbgTrace((TRACE_COMPONENT_INIT, TRACE_LEVEL_VERBOSE,
              "%s Adapter Vlan %d Value %d Current Id %d\n", __FUNCTION__,
              vlan_id, *(ULONG *)info_buffer, ionic->vlan_id));

    if (vlan_id != 0 &&
        ionic->master_lif->vlan_id != vlan_id) {

        // if( ionic->vlan_id != 0) {
        ntStatus = ionic_lif_vlan(ionic->master_lif, ionic->master_lif->vlan_id,
                                  false);
        if (ntStatus != NDIS_STATUS_SUCCESS) {
            DbgTrace((TRACE_COMPONENT_INIT, TRACE_LEVEL_ERROR,
                      "%s ionic_lif_vlan (remove) for %d failed %08lX \n",
                      __FUNCTION__, ionic, ionic->master_lif->vlan_id,
                      ntStatus));
            goto cleanup;
        }
        //}

        // if( vlan_id != 0) {
        ntStatus = ionic_lif_vlan(ionic->master_lif, vlan_id, true);
        if (ntStatus != NDIS_STATUS_SUCCESS) {
            DbgTrace((TRACE_COMPONENT_INIT, TRACE_LEVEL_ERROR,
                      "%s ionic_lif_vlan (add) for %d failed %08lX \n",
                      __FUNCTION__, ionic, vlan_id, ntStatus));
            goto cleanup;
        }
        //}

        ionic->master_lif->vlan_id = vlan_id;

        DbgTrace((TRACE_COMPONENT_INIT, TRACE_LEVEL_VERBOSE,
                  "%s Updated lif %d to vlan %d\n", __FUNCTION__,
                  ionic->master_lif->index, vlan_id));
    }

    *bytes_read = (ULONG)sizeof(ULONG);
    *bytes_needed = 0;

cleanup:

    DbgTrace((TRACE_COMPONENT_INIT, TRACE_LEVEL_VERBOSE,
              "%s Adapter %p Complete status 0x%08lX\n", __FUNCTION__, ionic,
              ntStatus));

    return ntStatus;
}

NTSTATUS
ConfigureRxBudget(IN ULONG Budget)
{

    NTSTATUS ntStatus = STATUS_SUCCESS;
    UNICODE_STRING uniString;
    BOOLEAN bUpdateBudget = FALSE;

    //
    // Go update the registry with the new entries
    //

    if (Budget != RxBudget) {
        RxBudget = Budget;
        bUpdateBudget = TRUE;
    }

    if (bUpdateBudget) {

        RtlInitUnicodeString(&uniString, REG_RX_BUDGET);

        ntStatus = UpdateRegistryParameter(&uniString, REG_DWORD, &Budget,
                                           sizeof(ULONG));

        if (!NT_SUCCESS(ntStatus)) {
            IoPrint("%s Failed to set RxBudget in registry Status %08lX\n",
                    ntStatus);
        }
    }

    return ntStatus;
}

NDIS_STATUS
queue_workitem(struct ionic *ionic,
    ULONG WorkItem,
    void *Context)
{

    NDIS_STATUS     status = NDIS_STATUS_SUCCESS;
    NDIS_HANDLE     work_handle = NULL;
    struct _WORK_ITEM  *work_item = NULL;

    work_item = (struct _WORK_ITEM *)NdisAllocateMemoryWithTagPriority_internal( ionic->adapterhandle,
                                                                        sizeof( struct _WORK_ITEM),
                                                                        IONIC_WORK_ITEM_TAG,
                                                                        NormalPoolPriority);
    if (work_item == NULL) {
        status = NDIS_STATUS_RESOURCES;
        goto cleanup;
    }

    NdisZeroMemory( work_item,
                    sizeof( struct _WORK_ITEM));

    DbgTrace((TRACE_COMPONENT_MEMORY, TRACE_LEVEL_VERBOSE,
                  "%s Allocated 0x%p len %08lX\n",
                  __FUNCTION__,
                  work_item, sizeof( struct _WORK_ITEM)));
    
    work_handle = NdisAllocateIoWorkItem( ionic->adapterhandle);

    if (work_handle == NULL) {
        status = NDIS_STATUS_RESOURCES;
        goto cleanup;
    }

    work_item->ionic = ionic;
    work_item->work_item_id = WorkItem;
    work_item->context = Context;

    ref_request( ionic);

    NdisQueueIoWorkItem( work_handle,
                         process_work_item,
                         work_item);

cleanup:

    if (status != NDIS_STATUS_SUCCESS) {
        if (work_item != NULL) {
            NdisFreeMemoryWithTagPriority_internal( ionic->adapterhandle,
                                           work_item,
                                           IONIC_WORK_ITEM_TAG);
        }
    }

    return status;
}

void
process_work_item(PVOID   WorkItemContext,
    NDIS_HANDLE  work_handle)
{
   
    struct _WORK_ITEM  *work_item = ( struct _WORK_ITEM  *)WorkItemContext;
    struct ionic *ionic = work_item->ionic;
    
    switch (work_item->work_item_id) {
    case 0: {
        break;
    }

    default:
        break;
    }

    NdisFreeMemoryWithTagPriority_internal( ionic->adapterhandle,
                                   work_item,
                                   IONIC_WORK_ITEM_TAG);
    NdisFreeIoWorkItem( work_handle);

    deref_request( ionic, 1);

    return;
}

NDIS_STATUS
get_perfmon_stats(struct _PERF_MON_CB **perfmon_stats, ULONG *len)
{

    NDIS_STATUS status = NDIS_STATUS_SUCCESS;
    ULONG   buffer_len = 0;
    ULONG   lut_len = 0;
    struct ionic *ionic = NULL;
    ULONG port_index = 0;
    ULONG queue_cnt = 0;
    LIST_ENTRY *list_entry = NULL;
    struct lif *lif = NULL;
    struct _PERF_MON_CB *stats = NULL;
    struct _PERF_MON_ADAPTER_STATS *adapter_stats = NULL;
    struct _PERF_MON_LIF_STATS *lif_stats = NULL;
    struct _PERF_MON_TX_QUEUE_STATS *tx_stats = NULL;
    struct _PERF_MON_RX_QUEUE_STATS *rx_stats = NULL;
    PVOID *lut = NULL;
    ULONG lut_index;
    LARGE_INTEGER perf_frequ;
    ULONG nb_count = 0;
    ULONGLONG sp_to_comp = 0;
    ULONGLONG queue_to_comp = 0;

    status = KeWaitForSingleObject(&perfmon_event,
                                   Executive,
                                   KernelMode,
                                   FALSE,
                                   NULL);

    if (status != STATUS_SUCCESS) {
        goto exit;
    }

    KeQueryPerformanceCounter( &perf_frequ);

    buffer_len = sizeof( struct _PERF_MON_CB);

    ionic = (struct ionic *)AdapterList.Flink;

    while (port_index < (ULONG)port_count) {

        buffer_len += sizeof( struct _PERF_MON_ADAPTER_STATS);

        lut_len += sizeof(PVOID); // direct pointer to adapter struct

        if (ionic->total_lif_count != 0) {

            list_entry = ionic->lifs.Flink;

            do {
                lif = CONTAINING_RECORD(list_entry, struct lif, list);

                buffer_len += sizeof( struct _PERF_MON_LIF_STATS);
                lut_len += sizeof(PVOID); // direct pointer to lif struct
                buffer_len += lif->ntxqs * sizeof( struct _PERF_MON_TX_QUEUE_STATS);
                if (lif->ntxqs != 0) {
                    lut_len += sizeof(PVOID); // direct pointer to tx queue structs
                }
                buffer_len += lif->nrxqs * sizeof( struct _PERF_MON_RX_QUEUE_STATS);
                if (lif->nrxqs != 0) {
                    lut_len += sizeof(PVOID); // direct pointer to rx queue structs
                }

                list_entry = list_entry->Flink;
            } while (list_entry != &ionic->lifs);
        }

        ionic = (struct ionic *)ionic->list_entry.Flink;
        port_index++;
    }

    stats = (struct _PERF_MON_CB *)NdisAllocateMemoryWithTagPriority_internal( IonicDriver,
                                                                      buffer_len + lut_len,
                                                                      IONIC_STATS_TAG,
                                                                      NormalPoolPriority);

    if (stats == NULL) {
        KeSetEvent( &perfmon_event, 0, FALSE);
        status = NDIS_STATUS_RESOURCES;
        goto exit;
    }

    DbgTrace((TRACE_COMPONENT_MEMORY, TRACE_LEVEL_VERBOSE,
                  "%s Allocated 0x%p len %08lX\n",
                  __FUNCTION__,
                  stats, buffer_len + lut_len));

    *len = (buffer_len + lut_len);
    *perfmon_stats = stats;

    NdisZeroMemory( stats,
                    buffer_len + lut_len);

    lut = (PVOID *)((ULONG_PTR)stats + buffer_len);

    stats->lookup_table = lut;
    lut_index = 0;

    adapter_stats = (struct _PERF_MON_ADAPTER_STATS *)((char *)stats + sizeof( struct _PERF_MON_CB));

    ionic = (struct ionic *)AdapterList.Flink;
    port_index = 0;

    while (port_index < (ULONG)port_count) {

        if (ionic->total_lif_count != 0) {
            // we are only returning lif/q stats for adapters with non-zero lif counts
            stats->adapter_count++;
            lut[lut_index++] = adapter_stats;

            adapter_stats->lif_count = ionic->total_lif_count;
            NdisMoveMemory( adapter_stats->name,
                            ionic->name.Buffer,
                            min( ionic->name.Length, ADAPTER_NAME_MAX_SZ));
            adapter_stats->core_redirection_count = InterlockedExchange( &ionic->core_redirect_count,
                                                                         0);
            if (ionic->pci_config.DeviceID == PCI_DEVICE_ID_PENSANDO_IONIC_ETH_MGMT) {
                adapter_stats->mgmt_device = TRUE;
            }

            list_entry = ionic->lifs.Flink;

            lif_stats = (struct _PERF_MON_LIF_STATS *)((char *)adapter_stats + sizeof( struct _PERF_MON_ADAPTER_STATS));

            do {
                lif = CONTAINING_RECORD(list_entry, struct lif, list);

                lut[lut_index++] = lif_stats;

                NdisMoveMemory( lif_stats->name,
                                lif->name,
                                LIF_NAME_MAX_SZ);

                lif_stats->rx_queue_count = lif->nrxqs;
                lif_stats->tx_queue_count = lif->ntxqs;

                rx_stats = (struct _PERF_MON_RX_QUEUE_STATS *)((char *)lif_stats + sizeof( struct _PERF_MON_LIF_STATS));

                if (lif->nrxqs != 0) {
                    lut[lut_index++] = rx_stats;
                }

                for (queue_cnt = 0; queue_cnt < lif->nrxqs; queue_cnt++) {

                    if (lif->rxqcqs[queue_cnt].qcq == NULL) {
                        continue;
                    }

                    if( lif->rxqcqs[ queue_cnt].qcq->rx_stats->pool_sample_count != 0) {
                        rx_stats->rx_pool_count = InterlockedExchange( (LONG *)&lif->rxqcqs[ queue_cnt].qcq->rx_stats->pool_packet_count,
                                                                       0);
                        rx_stats->rx_pool_count /= InterlockedExchange( (LONG *)&lif->rxqcqs[ queue_cnt].qcq->rx_stats->pool_sample_count,
                                                                       0);
                    }

                    rx_stats = (struct _PERF_MON_RX_QUEUE_STATS *)((char *)rx_stats + sizeof( struct _PERF_MON_RX_QUEUE_STATS));
                }

                tx_stats = (struct _PERF_MON_TX_QUEUE_STATS *)rx_stats;

                if (lif->ntxqs != 0) {
                    lut[lut_index++] = tx_stats;
                }

                for (queue_cnt = 0; queue_cnt < lif->ntxqs; queue_cnt++) {

                    if (lif->txqcqs[queue_cnt].qcq == NULL) {
                        continue;
                    }

                    tx_stats->max_queue_len = lif->txqcqs[ queue_cnt].qcq->tx_stats->descriptor_max;
                    lif->txqcqs[ queue_cnt].qcq->tx_stats->descriptor_max = 0;

                    if( lif->txqcqs[ queue_cnt].qcq->tx_stats->descriptor_sample != 0) {
                        tx_stats->queue_len = InterlockedExchange( (LONG *)&lif->txqcqs[ queue_cnt].qcq->tx_stats->descriptor_count,
                                                                     0) /
                                                InterlockedExchange( (LONG *)&lif->txqcqs[ queue_cnt].qcq->tx_stats->descriptor_sample,
                                                                     0);
                    }

                    if( lif->txqcqs[ queue_cnt].qcq->tx_stats->nbl_tick_total != 0) {
                        tx_stats->nbl_per_sec = (ULONG)((InterlockedExchange( (LONG *)&lif->txqcqs[ queue_cnt].qcq->tx_stats->nbl_count,
                                                                     0) * perf_frequ.QuadPart) /
                                                InterlockedExchange64( (LONGLONG *)&lif->txqcqs[ queue_cnt].qcq->tx_stats->nbl_tick_total,
                                                                     0));
                    }

                    nb_count = InterlockedExchange( (LONG *)&lif->txqcqs[ queue_cnt].qcq->tx_stats->nb_count,
                                                    0);

                    sp_to_comp = InterlockedExchange( (LONG *)&lif->txqcqs[ queue_cnt].qcq->tx_stats->nb_sp_to_comp_tick,
                                                    0);

                    queue_to_comp = InterlockedExchange( (LONG *)&lif->txqcqs[ queue_cnt].qcq->tx_stats->nb_queue_to_comp_tick,
                                                    0);

                    if( sp_to_comp != 0) {
                        tx_stats->nb_per_sec = (ULONG)((nb_count * perf_frequ.QuadPart) / sp_to_comp);
    
                        if( sp_to_comp != queue_to_comp) {
                            tx_stats->nb_time_to_queue = (ULONG)((nb_count * perf_frequ.QuadPart) / (sp_to_comp - queue_to_comp));
                        }
                    }

                    if( queue_to_comp != 0) {
                        tx_stats->nb_time_queue_to_comp = (ULONG)((nb_count * perf_frequ.QuadPart) / queue_to_comp);
                    }

                    tx_stats->pending_nbl_count = InterlockedExchange( (LONG *)&lif->txqcqs[ queue_cnt].qcq->tx_stats->pending_nbl_count,
                                                    0);

                    tx_stats->pending_nb_count = InterlockedExchange( (LONG *)&lif->txqcqs[ queue_cnt].qcq->tx_stats->pending_nb_count,
                                                    0);

                    tx_stats = (struct _PERF_MON_TX_QUEUE_STATS *)((char *)tx_stats + sizeof( struct _PERF_MON_TX_QUEUE_STATS));
                }

                lif_stats = (struct _PERF_MON_LIF_STATS *)tx_stats;

                list_entry = list_entry->Flink;
            } while (list_entry != &ionic->lifs);

            adapter_stats = (struct _PERF_MON_ADAPTER_STATS *)lif_stats;
        }

        ionic = (struct ionic *)ionic->list_entry.Flink;
        port_index++;
    }

    KeSetEvent( &perfmon_event, 0, FALSE);

exit:

    return status;
}

void
ref_request(struct ionic *ionic)
{
    if (InterlockedIncrement(&ionic->outstanding_request_count) == 1) {
        KeClearEvent( &ionic->outstanding_complete_event);
    }

    return;
}

void
deref_request(struct ionic *ionic, LONG count)
{

    ASSERT( ionic->outstanding_request_count != 0);

    if (InterlockedAdd(&ionic->outstanding_request_count, -count) == 0) {
        KeSetEvent( &ionic->outstanding_complete_event, 0, FALSE);
    }

    return;
}

void
wait_on_requests(struct ionic *ionic)
{
    NTSTATUS status = STATUS_SUCCESS;
    LARGE_INTEGER time_out;

    time_out.QuadPart = -(30 * IONIC_ONE_SEC_WAIT);

    status = KeWaitForSingleObject( &ionic->outstanding_complete_event,
                                    Executive,
                                    KernelMode,
                                    FALSE,
                                    &time_out);

    ASSERT( status == STATUS_SUCCESS);

    return;
}

void *
NdisAllocateMemoryWithTagPriority_internal(NDIS_HANDLE      NdisHandle,
    UINT             Length,
    ULONG            Tag,
    EX_POOL_PRIORITY Priority)
{
    void *buffer = NULL;

#ifdef TRACK_MEMORY_BUFFER_ALLOC
    struct memory_track_cb *pMem = NULL;

    pMem = (struct memory_track_cb *)NdisAllocateMemoryWithTagPriority( NdisHandle,
                                       sizeof( struct memory_track_cb),
                                       IONIC_MEMORY_TRACK_TAG,
                                       NormalPoolPriority);

    if (pMem == NULL) {
        goto exit;
    }

    NdisZeroMemory( pMem, sizeof( struct memory_track_cb));

    pMem->length = Length;

    pMem->buffer = NdisAllocateMemoryWithTagPriority( NdisHandle,
                                       Length + (2 * sizeof( ULONG)),
                                       Tag,
                                       Priority);

    if (pMem->buffer == NULL) {
        goto exit;
    }

    pMem->return_buffer = (void *)((char *)pMem->buffer + sizeof( ULONG));

    *((ULONG *)pMem->buffer) = 0x12121212;
    *((ULONG *)((char *)pMem->buffer + sizeof( ULONG) + Length)) = 0x13131313;

    NdisAcquireSpinLock( &memory_block_lock);

    InsertTailList( &memory_block_list, &pMem->list);
    
    NdisReleaseSpinLock( &memory_block_lock);

    buffer = pMem->return_buffer;

exit:

    if (pMem != NULL && pMem->buffer == NULL) {
        NdisFreeMemoryWithTagPriority( NdisHandle, pMem, IONIC_MEMORY_TRACK_TAG);
    }
#else
    buffer = NdisAllocateMemoryWithTagPriority( NdisHandle,
                                       Length,
                                       Tag,
                                       Priority);
#endif

    return buffer;
}

void
NdisFreeMemoryWithTagPriority_internal(NDIS_HANDLE NdisHandle,
    PVOID       VirtualAddress,
    ULONG       Tag)
{
#ifdef TRACK_MEMORY_BUFFER_ALLOC
    struct memory_track_cb *pMem = NULL;
    LIST_ENTRY *list_entry;
    BOOLEAN found = FALSE;

    NdisAcquireSpinLock( &memory_block_lock);

    list_entry = memory_block_list.Flink;

    do {
        pMem = CONTAINING_RECORD(list_entry, struct memory_track_cb, list);

        if (pMem->return_buffer == VirtualAddress) {
            RemoveEntryList( &pMem->list);
            found = TRUE;
            break;
        }

        list_entry = list_entry->Flink;
    } while (list_entry != &memory_block_list);
   
    NdisReleaseSpinLock( &memory_block_lock);

    if (!found) {
        IoPrint("Failed to locate memory block for %p\n", VirtualAddress);
        ASSERT(FALSE);
        goto exit;
    }

    if (*((ULONG *)pMem->buffer) != 0x12121212) {
        IoPrint("********* Possible corruption at VA Start %p ***********\n", VirtualAddress);
        DbgBreakPoint();
    }

    if (*((ULONG *)((char *)pMem->buffer + sizeof( ULONG) + pMem->length)) != 0x13131313) {
        IoPrint("********* Possible corruption at VA End %p Len %08lX ***********\n", VirtualAddress, pMem->length);
        DbgBreakPoint();
    }

    NdisFreeMemoryWithTagPriority( NdisHandle,
                                   pMem->buffer,
                                   Tag);

    NdisFreeMemoryWithTagPriority( NdisHandle,
                                   pMem,
                                   IONIC_MEMORY_TRACK_TAG);

exit:
#else
    NdisFreeMemoryWithTagPriority( NdisHandle,
                                   VirtualAddress,
                                   Tag);
#endif

    return;
}

void
validate_memory()
{

    struct memory_track_cb *pMem = NULL;
    LIST_ENTRY *list_entry;

    NdisAcquireSpinLock( &memory_block_lock);

    list_entry = memory_block_list.Flink;

    do {
        pMem = CONTAINING_RECORD(list_entry, struct memory_track_cb, list);

        if (*((ULONG *)pMem->buffer) != 0x12121212) {
            IoPrint("********* Possible corruption at VA Start %p ***********\n", pMem->return_buffer);
            DbgBreakPoint();
        }

        if (*((ULONG *)((char *)pMem->buffer + sizeof( ULONG) + pMem->length)) != 0x13131313) {
            IoPrint("********* Possible corruption at VA End %p Len %08lX ***********\n", pMem->return_buffer, pMem->length);
            DbgBreakPoint();
        }

        list_entry = list_entry->Flink;
    } while (list_entry != &memory_block_list);
   
    NdisReleaseSpinLock( &memory_block_lock);

    return;
}