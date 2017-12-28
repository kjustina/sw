// {C} Copyright 2017 Pensando Systems Inc. All rights reserved

#ifndef __HAL_MEM_HPP__
#define __HAL_MEM_HPP__

#include "nic/include/base.h"
#include "nic/include/mtrack.hpp"

namespace hal {

// HAL memory slabs
typedef enum hal_slab_e {
    HAL_SLAB_NONE,
    HAL_SLAB_HANDLE,
    HAL_SLAB_HANDLE_HT_ENTRY,
    HAL_SLAB_HANDLE_LIST_ENTRY,
    HAL_SLAB_HANDLE_ID_HT_ENTRY,
    HAL_SLAB_HANDLE_ID_LIST_ENTRY,
    HAL_SLAB_VRF,
    HAL_SLAB_NETWORK,
    HAL_SLAB_L2SEG,
    HAL_SLAB_MC_ENTRY,
    HAL_SLAB_LIF,
    HAL_SLAB_IF,
    HAL_SLAB_ENIC_L2SEG_ENTRY,
    HAL_SLAB_PORT,
    HAL_SLAB_EP,
    HAL_SLAB_EP_IP_ENTRY,
    HAL_SLAB_EP_L3_ENTRY,
    HAL_SLAB_FLOW,
    HAL_SLAB_SESSION,
    HAL_SLAB_SECURITY_PROFILE,
    HAL_SLAB_TLSCB,
    HAL_SLAB_TCPCB,
    HAL_SLAB_QOS_CLASS,
    HAL_SLAB_ACL,
    HAL_SLAB_WRING,
    HAL_SLAB_PROXY,
    HAL_SLAB_PROXY_FLOW_INFO,
    HAL_SLAB_IPSECCB,
    HAL_SLAB_L4LB,
    HAL_SLAB_CPUCB,
    HAL_SLAB_RAWRCB,
    HAL_SLAB_RAWCCB,
    HAL_SLAB_PROXYRCB,
    HAL_SLAB_PROXYCCB,
    HAL_SLAB_NWSEC_POLICY,
    HAL_SLAB_NWSEC_GROUP,
    HAL_SLAB_NWSEC_POLICY_RULES,
    HAL_SLAB_NWSEC_POLICY_CFG,
    HAL_SLAB_NWSEC_POLICY_SVC,
    HAL_SLAB_NWSEC_POLICY_APPID,
    HAL_SLAB_NWSEC_POLICY_EP_INFO,
    HAL_SLAB_DOS_POLICY,
    HAL_SLAB_DOS_POLICY_SG_LIST,
    HAL_SLAB_LKLSHIM_FLOWDB,
    HAL_SLAB_LKLSHIM_LSOCKDB,
    HAL_SLAB_LKLSHIM_LSOCKS,
    HAL_SLAB_ARP_LEARN,
    HAL_SLAB_DHCP_LEARN,
    HAL_SLAB_EVENT_MAP,
    HAL_SLAB_EVENT_MAP_LISTENER,
    HAL_SLAB_EVENT_LISTENER,
    HAL_SLAB_FTP_ALG_APPSESS,
    HAL_SLAB_FTP_ALG_L4SESS,
    HAL_SLAB_FTP_ALG_FTPINFO,
    HAL_SLAB_COPP,
    HAL_SLAB_TFTP_ALG_APPSESS,
    HAL_SLAB_TFTP_ALG_L4SESS,
    HAL_SLAB_TFTP_ALG_TFTPINFO,
    HAL_SLAB_RPC_ALG_APPSESS,
    HAL_SLAB_RPC_ALG_L4SESS,
    HAL_SLAB_RPC_ALG_RPCINFO,
    HAL_SLAB_PI_MAX,  // NOTE: MUST be last PI slab id

    // PD Slabs
    HAL_SLAB_VRF_PD,
    HAL_SLAB_L2SEG_PD,
    HAL_SLAB_MC_ENTRY_PD,
    HAL_SLAB_LIF_PD,
    HAL_SLAB_UPLINKIF_PD,
    HAL_SLAB_UPLINKPC_PD,
    HAL_SLAB_ENICIF_PD,
    HAL_SLAB_IF_L2SEG_PD,
    HAL_SLAB_TUNNELIF_PD,
    HAL_SLAB_CPUIF_PD,
    HAL_SLAB_DOS_POLICY_PD,
    HAL_SLAB_SECURITY_PROFILE_PD,
    HAL_SLAB_EP_PD,
    HAL_SLAB_EP_IP_ENTRY_PD,
    HAL_SLAB_SESSION_PD,
    HAL_SLAB_TLSCB_PD,
    HAL_SLAB_TCPCB_PD,
    HAL_SLAB_QOS_CLASS_PD,
    HAL_SLAB_ACL_PD,
    HAL_SLAB_WRING_PD,
    HAL_SLAB_IPSECCB_PD,
    HAL_SLAB_IPSECCB_DECRYPT_PD,
    HAL_SLAB_L4LB_PD,
    HAL_SLAB_RW_PD,
    HAL_SLAB_TUNNEL_RW_PD,
    HAL_SLAB_CPUCB_PD,
    HAL_SLAB_CPUPKT_PD,
    HAL_SLAB_RAWRCB_PD,
    HAL_SLAB_RAWCCB_PD,
    HAL_SLAB_PROXYRCB_PD,
    HAL_SLAB_PROXYCCB_PD,
    HAL_SLAB_CPUPKT_QINST_INFO_PD,
    HAL_SLAB_DIRECTMAP_ENTRY,
    HAL_SLAB_DIRECTMAP_DATA,
    HAL_SLAB_PORT_PD,
    HAL_SLAB_COPP_PD,
    HAL_SLAB_PD_MAX,                 // NOTE: MUST be last PD slab id

    HAL_SLAB_RSVD,  // all non-delay delete slabs can use this

    HAL_SLAB_MAX,
    HAL_SLAB_ALL = 0xFFFFFFFF,     // reserved and shouldn't be used
} hal_slab_t;

enum {
    HAL_MEM_ALLOC_NONE,
    HAL_MEM_ALLOC_INFRA,
    HAL_MEM_ALLOC_LIB_HT,
    HAL_MEM_ALLOC_LIB_SLAB,
    HAL_MEM_ALLOC_LIB_BITMAP,
    HAL_MEM_ALLOC_LIB_TWHEEL,
    HAL_MEM_ALLOC_LIB_THREAD,
    HAL_MEM_ALOC_LIB_PT,
    HAL_MEM_ALLOC_LIB_INDEXER,
    HAL_MEM_ALLOC_IF,
    HAL_MEM_ALLOC_L2,
    HAL_MEM_ALLOC_L3,
    HAL_MEM_ALLOC_EP,
    HAL_MEM_ALLOC_SFW,
    HAL_MEM_ALLOC_L4LB,
    HAL_MEM_ALLOC_FLOW,
    HAL_MEM_ALLOC_PD,
    HAL_MEM_ALLOC_LIB_ACL_TCAM,
    HAL_MEM_ALLOC_DLLIST,
    HAL_MEM_ALLOC_EVENT_MGR,
    HAL_MEM_ALLOC_CATALOG,
    HAL_MEM_ALLOC_DEBUG_CLI,
    HAL_MEM_ALLOC_ALG,
    HAL_MEM_ALLOC_APPID_INFO,
    HAL_MEM_ALLOC_PLUGIN_MANAGER,
    HAL_MEM_ALLOC_FTE,
    HAL_MEM_ALLOC_BLOCK_LIST,
    HAL_MEM_ALLOC_BLOCK_LIST_NODE,
    HAL_MEM_ALLOC_DIRECT_MAP,
    HAL_MEM_ALLOC_DIRECT_MAP_DATA,
    HAL_MEM_ALLOC_DIRECT_MAP_SW_DATA,
    HAL_MEM_ALLOC_DIRECT_MAP_HW_DATA,
    HAL_MEM_ALLOC_DIRECT_MAP_INDEXER,
    HAL_MEM_ALLOC_DIRECT_MAP_STATS,
    HAL_MEM_ALLOC_TCAM_ENTRY,
    HAL_MEM_ALLOC_TCAM,
    HAL_MEM_ALLOC_TCAM_INDEXER,
    HAL_MEM_ALLOC_TCAM_STATS,
    HAL_MEM_ALLOC_ACL_TCAM_STATS,
    HAL_MEM_ALLOC_HASH_ENTRY,
    HAL_MEM_ALLOC_HASH_ENTRY_KEY,
    HAL_MEM_ALLOC_HASH_ENTRY_DATA,
    HAL_MEM_ALLOC_HASH_HW_KEY_INS,
    HAL_MEM_ALLOC_HASH_SW_KEY_MASK_INS,
    HAL_MEM_ALLOC_HASH_HW_KEY_UPD,
    HAL_MEM_ALLOC_HASH_HW_KEY_DEPGM,
    HAL_MEM_ALLOC_HASH,
    HAL_MEM_ALLOC_HASH_STATS,
    HAL_MEM_ALLOC_MET_REPL_ENTRY,
    HAL_MEM_ALLOC_MET_REPL_ENTRY_DATA,
    HAL_MEM_ALLOC_MET_REPL_TABLE_ENTRY,
    HAL_MEM_ALLOC_MET_REPL_LIST,
    HAL_MEM_ALLOC_MET,
    HAL_MEM_ALLOC_MET_REPL_TABLE_INDEXER,
    HAL_MEM_ALLOC_MET_STATS,
    HAL_MEM_ALLOC_FLOW_ENTRY,
    HAL_MEM_ALLOC_FLOW_ENTRY_KEY,
    HAL_MEM_ALLOC_FLOW_ENTRY_DATA,
    HAL_MEM_ALLOC_FLOW_ENTRY_HW_KEY,
    HAL_MEM_ALLOC_FLOW_SPINE_ENTRY,
    HAL_MEM_ALLOC_FLOW_SPINE_ENTRY_SW_KEY,
    HAL_MEM_ALLOC_FLOW_SPINE_ENTRY_HW_KEY,
    HAL_MEM_ALLOC_FLOW_HINT_GROUP,
    HAL_MEM_ALLOC_FLOW_TABLE_ENTRY,
    HAL_MEM_ALLOC_FLOW_COLL_INDEXER,
    HAL_MEM_ALLOC_FLOW_ENTRY_INDEXER,
    HAL_MEM_ALLOC_FLOW_STATS,
    HAL_MEM_ALLOC_FLOW_HW_KEY,
    HAL_MEM_ALLOC_INP_PROP_KEY_MASK,
    HAL_MEM_ALLOC_OTHER,
    HAL_MEM_ALLOC_ALL = 0xFFFFFFFF,    // reserved and shouldn't be used
};

//------------------------------------------------------------------------------
// use these memory allocation and free macros when one off allocation is
// needed, otherwise use slabs
//------------------------------------------------------------------------------
#define HAL_MALLOC(alloc_id, size)    (hal::utils::g_hal_mem_mgr.mtrack_alloc(static_cast<uint32_t>(alloc_id), false, size, __FUNCTION__, __LINE__))
#define HAL_CALLOC(alloc_id, size)    (hal::utils::g_hal_mem_mgr.mtrack_alloc(static_cast<uint32_t>(alloc_id), true, size, __FUNCTION__, __LINE__))
#define HAL_FREE(alloc_id, ptr)       (hal::utils::g_hal_mem_mgr.mtrack_free(static_cast<uint32_t>(alloc_id), ptr, __FUNCTION__, __LINE__))

hal_ret_t free_to_slab(hal_slab_t slab_id, void *elem);

namespace pd {

hal_ret_t free_to_slab(hal_slab_t slab_id, void *elem);

}    // namespace pd

}    // namespace hal

#endif    // __HAL_MEM_HPP__

