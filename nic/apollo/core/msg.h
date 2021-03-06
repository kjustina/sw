// {C} Copyright 2019 Pensando Systems Inc. All rights reserved
//
//----------------------------------------------------------------------------
///
/// \file
/// This file contains common message headers, types etc. that are global across
/// threads and processes
/// WARNING: this must be a C file, not C++
//----------------------------------------------------------------------------

#ifndef __CORE_MSG_H__
#define __CORE_MSG_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "nic/apollo/framework/api.h"
#include "nic/apollo/include/globals.hpp"

/// message types
typedef enum pds_msg_type_s {
    PDS_MSG_TYPE_NONE = (SDK_IPC_MSG_ID_MAX + 1),
    PDS_MSG_TYPE_CFG,                                   ///< config type message
    PDS_MSG_TYPE_CMD,                                   ///< any CLI commands
    PDS_MSG_TYPE_EVENT,                                 ///< event type message

    PDS_MSG_TYPE_MAX
} pds_msg_type_t;

/// unique message identifiers
typedef enum pds_msg_id_s {
    PDS_MSG_ID_NONE,
    PDS_MSG_ID_MIN = PDS_MSG_ID_NONE,

    /// config/policy message identifiers
    PDS_CFG_MSG_ID_NONE,
    /// any device/global configuration
    PDS_CFG_MSG_ID_DEVICE,
    /// vpc related configuration
    PDS_CFG_MSG_ID_VPC,
    /// vnic related configuration
    PDS_CFG_MSG_ID_VNIC,
    /// subnet related configuration
    PDS_CFG_MSG_ID_SUBNET,
    /// NAT port block configuration
    PDS_CFG_MSG_ID_NAT_PORT_BLOCK,
    /// DHCP (suppresion) policy configuration
    PDS_CFG_MSG_ID_DHCP_POLICY,
    /// security profile configuration
    PDS_CFG_MSG_ID_SECURITY_PROFILE,

    // TODO: should we punt event/alerts to shm directly
    PDS_CMD_MSG_ID_NONE,
    PDS_CMD_MSG_FLOW_CLEAR,
    /// NAT port block configuration get
    PDS_CMD_MSG_ID_NAT_PORT_BLOCK_GET,
    PDS_CMD_MSG_VNIC_STATS_GET,
    PDS_MSG_ID_MAX,
} pds_msg_id_t;

#ifdef __cplusplus
}
#endif

#endif    // __CORE_MSG_H__
