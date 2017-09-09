// {C} Copyright 2017 Pensando Systems Inc. All rights reserved

#ifndef __HAL_STATE_HPP__
#define __HAL_STATE_HPP__

#include <slab.hpp>
#include <indexer.hpp>
#include <ht.hpp>
#include <bitmap.hpp>
#include <hal.hpp>

namespace hal {

using hal::utils::slab;
using hal::utils::indexer;
using hal::utils::ht;
using hal::utils::bitmap;

#define HAL_HANDLE_HT_SZ                             (16 << 10)
// TODO: this should be coming from catalogue or platform API
#define HAL_MAX_TM_PORTS                             12

typedef enum cfg_op_e {
    CFG_OP_NONE,
    CFG_OP_READ,
    CFG_OP_WRITE,
} cfg_op_t;
typedef uint32_t cfg_version_t;

// HAL config database
class hal_cfg_db {
public:
    static hal_cfg_db *factory(void);
    ~hal_cfg_db();

    ht *tenant_id_ht(void) const { return tenant_id_ht_; }
    ht *tenant_hal_handle_ht(void) const { return tenant_hal_handle_ht_; }

    ht *network_key_ht(void) const { return network_key_ht_; }
    ht *network_hal_handle_ht(void) const { return network_hal_handle_ht_; }

    ht *nwsec_profile_id_ht(void) const { return nwsec_profile_id_ht_; }
    ht *nwsec_profile_hal_handle_ht(void) const { return nwsec_profile_hal_handle_ht_ ; }

    ht *l2seg_id_ht(void) const { return l2seg_id_ht_; }
    ht *l2seg_hal_handle_ht(void) const { return l2seg_hal_handle_ht_; }

    ht *lif_id_ht(void) const { return lif_id_ht_; }
    ht *lif_hal_handle_ht(void) const { return lif_hal_handle_ht_; }

    ht *if_id_ht(void) const { return if_id_ht_; }
    ht *if_hal_handle_ht(void) const { return if_hal_handle_ht_; }

    // TODO: may have to create L2 and L3 HTs here !!
    ht *ep_hal_handle_ht(void) const { return ep_hal_handle_ht_; }

    ht *l4lb_ht(void) const { return l4lb_ht_; }
    ht *l4lb_hal_handle_ht(void) const { return l4lb_hal_handle_ht_; }

    ht *session_id_ht(void) const { return session_id_ht_; }
    ht *session_hal_handle_ht(void) const { return session_hal_handle_ht_; }

    ht *tlscb_id_ht(void) const { return tlscb_id_ht_; }
    ht *tlscb_hal_handle_ht(void) const { return tlscb_hal_handle_ht_; }

    ht *tcpcb_id_ht(void) const { return tcpcb_id_ht_; }
    ht *tcpcb_hal_handle_ht(void) const { return tcpcb_hal_handle_ht_; }

    ht *buf_pool_id_ht(void) const { return buf_pool_id_ht_; }
    ht *buf_pool_hal_handle_ht(void) const { return buf_pool_hal_handle_ht_; }

    ht *queue_id_ht(void) const { return queue_id_ht_; }
    ht *queue_hal_handle_ht(void) const { return queue_hal_handle_ht_; }

    ht *ingress_policer_id_ht(void) const { return ingress_policer_id_ht_; }
    ht *ingress_policer_hal_handle_ht(void) const { return ingress_policer_hal_handle_ht_; }
    ht *egress_policer_id_ht(void) const { return egress_policer_id_ht_; }
    ht *egress_policer_hal_handle_ht(void) const { return egress_policer_hal_handle_ht_; }

    ht *acl_id_ht(void) const { return acl_id_ht_; }
    ht *acl_hal_handle_ht(void) const { return acl_hal_handle_ht_; }

    ht *wring_id_ht(void) const { return wring_id_ht_; }
    ht *wring_hal_handle_ht(void) const { return wring_hal_handle_ht_; }

    ht *proxy_type_ht(void) const { return proxy_type_ht_; }
    ht *proxy_hal_handle_ht(void) const { return proxy_hal_handle_ht_; }

    ht *ipseccb_id_ht(void) const { return ipseccb_id_ht_; }
    ht *ipseccb_hal_handle_ht(void) const { return ipseccb_hal_handle_ht_; }

    ht *cpucb_id_ht(void) const { return cpucb_id_ht_; }
    ht *cpucb_hal_handle_ht(void) const { return cpucb_hal_handle_ht_; }

private:
    bool init(void);
    hal_cfg_db();

private:
    hal_spinlock_t    slock_;
    // tenant/vrf related config
    struct {
        ht         *tenant_id_ht_;
        ht         *tenant_hal_handle_ht_;
    } __PACK__;

    // network related config
    struct {
        ht         *network_key_ht_;
        ht         *network_hal_handle_ht_;
    } __PACK__;

    // security profile related config
    struct {
        ht         *nwsec_profile_id_ht_;
        ht         *nwsec_profile_hal_handle_ht_;
    } __PACK__;

    // l2segment related config
    struct {
        ht         *l2seg_id_ht_;
        ht         *l2seg_hal_handle_ht_;
    } __PACK__;

    // LIF related config
    struct {
        ht         *lif_id_ht_;
        ht         *lif_hal_handle_ht_;
    } __PACK__;

    // interface related config
    struct {
        ht         *if_id_ht_;
        ht         *if_hal_handle_ht_;
    } __PACK__;

    // endpoint related config
    struct {
        ht         *ep_hal_handle_ht_;
    } __PACK__;

    // flow/session related config
    struct {
        ht         *session_id_ht_;
        ht         *session_hal_handle_ht_;
    } __PACK__;

    // l4lb related config
    struct {
        ht         *l4lb_ht_;
        ht         *l4lb_hal_handle_ht_;
    } __PACK__;

    // buf-pool related config
    struct {
        ht         *buf_pool_id_ht_;
        ht         *buf_pool_hal_handle_ht_;
    } __PACK__;

    // TLS CB related config
    struct {
        ht         *tlscb_id_ht_;
        ht         *tlscb_hal_handle_ht_;
    } __PACK__;

    // TCP CB related config
    struct {
        ht         *tcpcb_id_ht_;
        ht         *tcpcb_hal_handle_ht_;
    } __PACK__;

    // queue related config
    struct {
        ht         *queue_id_ht_;
        ht         *queue_hal_handle_ht_;
    } __PACK__;

    // policer related config
    struct {
        ht         *ingress_policer_id_ht_;
        ht         *ingress_policer_hal_handle_ht_;
        ht         *egress_policer_id_ht_;
        ht         *egress_policer_hal_handle_ht_;
    } __PACK__;

    // WRing related config
    struct {
        ht         *wring_id_ht_;
        ht         *wring_hal_handle_ht_;
    } __PACK__;

    // Proxy related config
    struct {
        ht         *proxy_type_ht_;
        ht         *proxy_hal_handle_ht_;
    } __PACK__;

    // acl related config
    struct {
        ht         *acl_id_ht_;
        ht         *acl_hal_handle_ht_;
    } __PACK__;

    // IPSec CB related config
    struct {
        ht         *ipseccb_id_ht_;
        ht         *ipseccb_hal_handle_ht_;
    } __PACK__;

    // CPU CB related config
    struct {
        ht         *cpucb_id_ht_;
        ht         *cpucb_hal_handle_ht_;
    } __PACK__;
};

// HAL operational database
class hal_oper_db {
public:
    static hal_oper_db *factory(void);
    ~hal_oper_db();

    void *infra_l2seg(void) { return infra_l2seg_; }
    void set_infra_l2seg(void *infra_l2seg) { infra_l2seg_ = infra_l2seg; }
    ht *if_hwid_ht(void) const { return if_hwid_ht_; }
    ht *ep_l2_ht(void) const { return ep_l2_ht_; }
    ht *ep_l3_entry_ht(void) const { return ep_l3_entry_ht_; }
    ht *flow_ht(void) const { return flow_ht_; }
    bitmap *buf_pool_cos_usage_bmp(uint32_t port_num) const {
        return cos_in_use_bmp_[port_num];
    }

private:
    bool init(void);
    hal_oper_db();

private:
    void      *infra_l2seg_;  // l2seg_t *
    ht        *if_hwid_ht_;
    ht        *ep_l2_ht_;
    ht        *ep_l3_entry_ht_;
    ht        *flow_ht_;
    // bitmap indicating if the cos is already assigned to a buffer pool
    bitmap    *cos_in_use_bmp_[HAL_MAX_TM_PORTS];
};

// HAL memory slabs and any other memory manager state
class hal_mem_db {
public:
    static hal_mem_db *factory(void);
    ~hal_mem_db();

    slab *tenant_slab(void) const { return tenant_slab_; }
    slab *network_slab(void) const { return network_slab_; }
    slab *nwsec_profile_slab(void) const { return nwsec_profile_slab_; }
    slab *l2seg_slab(void) const { return l2seg_slab_; }
    slab *lif_slab(void) const { return lif_slab_; }
    slab *if_slab(void) const { return if_slab_; }
    slab *ep_slab(void) const { return ep_slab_; }
    slab *ep_ip_entry_slab(void) const { return ep_ip_entry_slab_; }
    slab *ep_l3_entry_slab(void) const { return ep_l3_entry_slab_; }
    slab *l4lb_slab(void) const { return l4lb_slab_; }
    slab *flow_slab(void) const { return flow_slab_; }
    slab *session_slab(void) const { return session_slab_; }
    slab *tlscb_slab(void) const { return tlscb_slab_; }
    slab *tcpcb_slab(void) const { return tcpcb_slab_; }
    slab *buf_pool_slab(void) const { return buf_pool_slab_; }
    slab *queue_slab(void) const { return queue_slab_; }
    slab *policer_slab(void) const { return policer_slab_; }
    slab *acl_slab(void) const { return acl_slab_; }
    slab *wring_slab(void) const { return wring_slab_; }
    slab *proxy_slab(void) const { return proxy_slab_; }
    slab *ipseccb_slab(void) const { return ipseccb_slab_; }
    slab *cpucb_slab(void) const { return cpucb_slab_; }

private:
    bool init(void);
    hal_mem_db();

private:
    slab    *tenant_slab_;
    slab    *network_slab_;
    slab    *nwsec_profile_slab_;
    slab    *l2seg_slab_;
    slab    *lif_slab_;
    slab    *if_slab_;
    slab    *ep_slab_;
    slab    *ep_ip_entry_slab_;
    slab    *ep_l3_entry_slab_;
    slab    *flow_slab_;
    slab    *session_slab_;
    slab    *l4lb_slab_;
    slab    *tlscb_slab_;
    slab    *tcpcb_slab_;
    slab    *buf_pool_slab_;
    slab    *queue_slab_;
    slab    *policer_slab_;
    slab    *wring_slab_;
    slab    *proxy_slab_;
    slab    *acl_slab_;
    slab    *ipseccb_slab_;
    slab    *cpucb_slab_;
};

//------------------------------------------------------------------------------
// Whole of HAL state including both config & oper
// NOTE: any HAL state put outside this is not under warranty
//
// TODO: rename hstate back to hal_state once all state is re-organized
//------------------------------------------------------------------------------
class hstate {
public:
    static hstate *factory(void);
    ~hstate();

    // get APIs for tenant related state
    slab *tenant_slab(void) const { return mem_db_->tenant_slab(); }
    ht *tenant_id_ht(void) const { return cfg_db_->tenant_id_ht(); }
    ht *tenant_hal_handle_ht(void) const { return cfg_db_->tenant_hal_handle_ht(); }

    // get APIs for network related state
    slab *network_slab(void) const { return mem_db_->network_slab(); }
    ht *network_key_ht(void) const { return cfg_db_->network_key_ht(); }
    ht *network_hal_handle_ht(void) const { return cfg_db_->network_hal_handle_ht(); }

    // get APIs for security profile related state
    slab *nwsec_profile_slab(void) const { return mem_db_->nwsec_profile_slab(); }
    ht *nwsec_profile_id_ht(void) const { return cfg_db_->nwsec_profile_id_ht(); }
    ht *nwsec_profile_hal_handle_ht(void) const { return cfg_db_->nwsec_profile_hal_handle_ht(); }

    // get APIs for L2 segment state
    slab *l2seg_slab(void) const { return mem_db_->l2seg_slab(); }
    ht *l2seg_id_ht(void) const { return cfg_db_->l2seg_id_ht(); }
    ht *l2seg_hal_handle_ht(void) const { return cfg_db_->l2seg_hal_handle_ht(); }

    // get APIs for LIF state
    slab *lif_slab(void) const { return mem_db_->lif_slab(); }
    ht *lif_id_ht(void) const { return cfg_db_->lif_id_ht(); }
    ht *lif_hal_handle_ht(void) const { return cfg_db_->lif_hal_handle_ht(); }

    // get APIs for interface state
    slab *if_slab(void) const { return mem_db_->if_slab(); }
    ht *if_id_ht(void) const { return cfg_db_->if_id_ht(); }
    ht *if_hal_handle_ht(void) const { return cfg_db_->if_hal_handle_ht(); }
    ht *if_hwid_ht(void) const { return oper_db_->if_hwid_ht(); }

    // get APIs for endpoint state
    slab *ep_slab(void) const { return mem_db_->ep_slab(); }
    slab *ep_ip_entry_slab(void) const { return mem_db_->ep_ip_entry_slab(); }
    slab *ep_l3_entry_slab(void) const { return mem_db_->ep_l3_entry_slab(); }
    ht *ep_l2_ht(void) const { return oper_db_->ep_l2_ht(); }
    ht *ep_l3_entry_ht(void) const { return oper_db_->ep_l3_entry_ht(); }
    ht *ep_hal_handle_ht(void) const { return cfg_db_->ep_hal_handle_ht(); }

    // get APIs for l4lb state
    slab *l4lb_slab(void) const { return mem_db_->l4lb_slab(); }
    ht *l4lb_ht(void) const { return cfg_db_->l4lb_ht(); }
    ht *l4lb_hal_handle_ht(void) const { return cfg_db_->l4lb_hal_handle_ht(); }

    // get APIs for flow/session state
    slab *flow_slab(void) const { return mem_db_->flow_slab(); }
    slab *session_slab(void) const { return mem_db_->session_slab(); }
    ht *session_id_ht(void) const { return cfg_db_->session_id_ht(); }
    ht *session_hal_handle_ht(void) const { return cfg_db_->session_hal_handle_ht(); }

    // get APIs for TLS CB state
    slab *tlscb_slab(void) const { return mem_db_->tlscb_slab(); }
    ht *tlscb_id_ht(void) const { return cfg_db_->tlscb_id_ht(); }
    ht *tlscb_hal_handle_ht(void) const { return cfg_db_->tlscb_hal_handle_ht(); }

    // get APIs for TCP CB state
    slab *tcpcb_slab(void) const { return mem_db_->tcpcb_slab(); }
    ht *tcpcb_id_ht(void) const { return cfg_db_->tcpcb_id_ht(); }
    ht *tcpcb_hal_handle_ht(void) const { return cfg_db_->tcpcb_hal_handle_ht(); }

    // get APIs for buf-pool state
    slab *buf_pool_slab(void) const { return mem_db_->buf_pool_slab(); }
    ht *buf_pool_id_ht(void) const { return cfg_db_->buf_pool_id_ht(); }
    ht *buf_pool_hal_handle_ht(void) const { return cfg_db_->buf_pool_hal_handle_ht(); }
    bitmap *buf_pool_cos_usage_bmp(uint32_t port_num) const {
        return oper_db_->buf_pool_cos_usage_bmp(port_num);
    }

    // get APIs for queue state
    slab *queue_slab(void) const { return mem_db_->queue_slab(); }
    ht *queue_id_ht(void) const { return cfg_db_->queue_id_ht(); }
    ht *queue_hal_handle_ht(void) const { return cfg_db_->queue_hal_handle_ht(); }

    // get APIs for policer state
    slab *policer_slab(void) const { return mem_db_->policer_slab(); }
    ht *ingress_policer_id_ht(void) const { return cfg_db_->ingress_policer_id_ht(); }
    ht *ingress_policer_hal_handle_ht(void) const { return cfg_db_->ingress_policer_hal_handle_ht(); }
    ht *egress_policer_id_ht(void) const { return cfg_db_->egress_policer_id_ht(); }
    ht *egress_policer_hal_handle_ht(void) const { return cfg_db_->egress_policer_hal_handle_ht(); }

    // get APIs for acl state
    slab *acl_slab(void) const { return mem_db_->acl_slab(); }
    ht *acl_id_ht(void) const { return cfg_db_->acl_id_ht(); }
    ht *acl_hal_handle_ht(void) const { return cfg_db_->acl_hal_handle_ht(); }

    // get APIs for WRing state
    slab *wring_slab(void) const { return mem_db_->wring_slab(); }
    ht *wring_id_ht(void) const { return cfg_db_->wring_id_ht(); }
    ht *wring_hal_handle_ht(void) const { return cfg_db_->wring_hal_handle_ht(); }

    // get APIs for Proxy state
    slab *proxy_slab(void) const { return mem_db_->proxy_slab(); }
    ht *proxy_type_ht(void) const { return cfg_db_->proxy_type_ht(); }
    ht *proxy_hal_handle_ht(void) const { return cfg_db_->proxy_hal_handle_ht(); }

    // get API for infra l2seg
    void *infra_l2seg(void) { return oper_db_->infra_l2seg(); }
    void set_infra_l2seg(void *infra_l2seg) { oper_db_->set_infra_l2seg(infra_l2seg); }

    // get APIs for IPSEC CB state
    slab *ipseccb_slab(void) const { return mem_db_->ipseccb_slab(); }
    ht *ipseccb_id_ht(void) const { return cfg_db_->ipseccb_id_ht(); }
    ht *ipseccb_hal_handle_ht(void) const { return cfg_db_->ipseccb_hal_handle_ht(); }

    // get APIs for CPU CB state
    slab *cpucb_slab(void) const { return mem_db_->cpucb_slab(); }
    ht *cpucb_id_ht(void) const { return cfg_db_->cpucb_id_ht(); }
    ht *cpucb_hal_handle_ht(void) const { return cfg_db_->cpucb_hal_handle_ht(); }

private:
    bool init(void);
    hstate();

private:
    hal_cfg_db     *cfg_db_;
    hal_oper_db    *oper_db_;
    hal_mem_db     *mem_db_;
};

//------------------------------------------------------------------------------
// hal_state class contains all the HAL state (well, most of it) including all
// the slab memory instances, hash tables, indexers etc. used inside HAL,
// potentially across threads, and is instantiated during init time.
//
// TODO:
// 1. add hal_handle_ht here !!
// 2. add APIs to dump info about everything inside this, for debugging
// 3. add tenant HT by tenant id
// 4. add tenant HT by tenant hwid
//------------------------------------------------------------------------------
class hal_state {
public:
    static hal_state *factory(void);
    ~hal_state();

    // API to call before processing any packet by FTE, any operation by config
    hal_ret_t cfg_db_open(cfg_op_t cfg_op);
    // API to call after processing any packet by FTE, any operation by config
    // thread or periodic thread etc.
    hal_ret_t cfg_db_close(void);

#if 0
    // try to make given version valid
    hal_ret_t cfg_db_version_commit(cfg_version_t version);

    // invalidate a specific version of the cfg db; this api is useful in case a
    // modify operation failed and we need to mark all updated objects as
    // invalid in one shot
    uint32_t cfg_db_version_invalidate(cfg_version_t cfg_db_ver);
#endif

    // get APIs for HAL handle related state
    slab *hal_handle_slab(void) const { return hal_handle_slab_; }

    // get APIs for tenant related state
    slab *tenant_slab(void) const { return tenant_slab_; }
    ht *tenant_id_ht(void) const { return tenant_id_ht_; }
    ht *tenant_hal_handle_ht(void) const { return tenant_hal_handle_ht_; }

    // get APIs for network related state
    slab *network_slab(void) const { return network_slab_; }
    ht *network_key_ht(void) const { return network_key_ht_; }
    ht *network_hal_handle_ht(void) const { return network_hal_handle_ht_; }

    // get APIs for security profile related state
    slab *nwsec_profile_slab(void) const { return nwsec_profile_slab_; }
    ht *nwsec_profile_id_ht(void) const { return nwsec_profile_id_ht_; }
    ht *nwsec_profile_hal_handle_ht(void) const { return nwsec_profile_hal_handle_ht_ ; }

    // get APIs for L2 segment state
    slab *l2seg_slab(void) const { return l2seg_slab_; }
    ht *l2seg_id_ht(void) const { return l2seg_id_ht_; }
    ht *l2seg_hal_handle_ht(void) const { return l2seg_hal_handle_ht_; }

    // get APIs for LIF state
    slab *lif_slab(void) const { return lif_slab_; }
    ht *lif_id_ht(void) const { return lif_id_ht_; }
    ht *lif_hal_handle_ht(void) const { return lif_hal_handle_ht_; }

    // get APIs for interface state
    slab *if_slab(void) const { return if_slab_; }
    ht *if_id_ht(void) const { return if_id_ht_; }
    ht *if_hwid_ht(void) const { return if_hwid_ht_; }
    ht *if_hal_handle_ht(void) const { return if_hal_handle_ht_; }

    // get APIs for endpoint state
    slab *ep_slab(void) const { return ep_slab_; }
    slab *ep_ip_entry_slab(void) const { return ep_ip_entry_slab_; }
    slab *ep_l3_entry_slab(void) const { return ep_l3_entry_slab_; }
    ht *ep_l2_ht(void) const { return ep_l2_ht_; }
    ht *ep_l3_entry_ht(void) const { return ep_l3_entry_ht_; }
    ht *ep_hal_handle_ht(void) const { return ep_hal_handle_ht_; }

    // get APIs for l4lb state
    slab *l4lb_slab(void) const { return l4lb_slab_; }
    ht *l4lb_ht(void) const { return l4lb_ht_; }
    ht *l4lb_hal_handle_ht(void) const { return l4lb_hal_handle_ht_; }

    // get APIs for flow/session state
    slab *flow_slab(void) const { return flow_slab_; }
    slab *session_slab(void) const { return session_slab_; }
    ht *session_id_ht(void) const { return session_id_ht_; }
    ht *session_hal_handle_ht(void) const { return session_hal_handle_ht_; }

    // get APIs for TLS CB state
    slab *tlscb_slab(void) const { return tlscb_slab_; }
    ht *tlscb_id_ht(void) const { return tlscb_id_ht_; }
    ht *tlscb_hal_handle_ht(void) const { return tlscb_hal_handle_ht_; }

    // get APIs for TCP CB state
    slab *tcpcb_slab(void) const { return tcpcb_slab_; }
    ht *tcpcb_id_ht(void) const { return tcpcb_id_ht_; }
    ht *tcpcb_hal_handle_ht(void) const { return tcpcb_hal_handle_ht_; }

    // get APIs for buf-pool state
    slab *buf_pool_slab(void) const { return buf_pool_slab_; }
    ht *buf_pool_id_ht(void) const { return buf_pool_id_ht_; }
    ht *buf_pool_hal_handle_ht(void) const { return buf_pool_hal_handle_ht_; }
    bitmap *buf_pool_cos_usage_bmp(uint32_t port_num) const { return cos_in_use_bmp_[port_num]; }

    // get APIs for queue state
    slab *queue_slab(void) const { return queue_slab_; }
    ht *queue_id_ht(void) const { return queue_id_ht_; }
    ht *queue_hal_handle_ht(void) const { return queue_hal_handle_ht_; }

    // get APIs for policer state
    slab *policer_slab(void) const { return policer_slab_; }
    ht *ingress_policer_id_ht(void) const { return ingress_policer_id_ht_; }
    ht *ingress_policer_hal_handle_ht(void) const { return ingress_policer_hal_handle_ht_; }
    ht *egress_policer_id_ht(void) const { return egress_policer_id_ht_; }
    ht *egress_policer_hal_handle_ht(void) const { return egress_policer_hal_handle_ht_; }

    // get APIs for acl state
    slab *acl_slab(void) const { return acl_slab_; }
    ht *acl_id_ht(void) const { return acl_id_ht_; }
    ht *acl_hal_handle_ht(void) const { return acl_hal_handle_ht_; }

    // get APIs for WRing state
    slab *wring_slab(void) const { return wring_slab_; }
    ht *wring_id_ht(void) const { return wring_id_ht_; }
    ht *wring_hal_handle_ht(void) const { return wring_hal_handle_ht_; }

    // get APIs for Proxy state
    slab *proxy_slab(void) const { return proxy_slab_; }
    ht *proxy_type_ht(void) const { return proxy_type_ht_; }
    ht *proxy_hal_handle_ht(void) const { return proxy_hal_handle_ht_; }

    // get API for infra l2seg
    void *infra_l2seg(void) { return infra_l2seg_; } 
    void set_infra_l2seg(void *infra_l2seg) { infra_l2seg_ = infra_l2seg; }

    // get APIs for IPSEC CB state
    slab *ipseccb_slab(void) const { return ipseccb_slab_; }
    ht *ipseccb_id_ht(void) const { return ipseccb_id_ht_; }
    ht *ipseccb_hal_handle_ht(void) const { return ipseccb_hal_handle_ht_; }

    // get APIs for CPU CB state
    slab *cpucb_slab(void) const { return cpucb_slab_; }
    ht *cpucb_id_ht(void) const { return cpucb_id_ht_; }
    ht *cpucb_hal_handle_ht(void) const { return cpucb_hal_handle_ht_; }

private:
    bool init(void);
    hal_state();
    cfg_version_t cfg_db_get_current_version(void);
    cfg_version_t cfg_db_reserve_version(void);
    hal_ret_t cfg_db_release_version_in_use(cfg_version_t ver);

private:
    // HAL internal state
    struct {
        slab       *hal_handle_slab_;
    } __PACK__;

    // tenant/vrf related state
    struct {
        slab       *tenant_slab_;
        ht         *tenant_id_ht_;
        ht         *tenant_hal_handle_ht_;
    } __PACK__;

    // network related state
    struct {
        slab       *network_slab_;
        ht         *network_key_ht_;
        ht         *network_hal_handle_ht_;
    } __PACK__;

    // security profile related state
    struct {
        slab       *nwsec_profile_slab_;
        ht         *nwsec_profile_id_ht_;
        ht         *nwsec_profile_hal_handle_ht_;
    } __PACK__;

    // l2segment related state
    struct {
        slab       *l2seg_slab_;
        ht         *l2seg_id_ht_;
        ht         *l2seg_hal_handle_ht_;
    } __PACK__;

    // LIF related state
    struct {
        slab       *lif_slab_;
        ht         *lif_id_ht_;
        ht         *lif_hal_handle_ht_;
    } __PACK__;

    // interface related state
    struct {
        slab       *if_slab_;
        ht         *if_id_ht_;
        ht         *if_hwid_ht_;
        ht         *if_hal_handle_ht_;
    } __PACK__;

    // endpoint related state
    struct {
        slab       *ep_slab_;
        slab       *ep_ip_entry_slab_;
        slab       *ep_l3_entry_slab_;
        ht         *ep_l2_ht_;
        ht         *ep_l3_entry_ht_;
        ht         *ep_hal_handle_ht_;
    } __PACK__;

    // l4lb related state
    struct {
        slab       *l4lb_slab_;
        ht         *l4lb_ht_;
        ht         *l4lb_hal_handle_ht_;
    } __PACK__;

    // flow/session related state
    struct {
        slab       *flow_slab_;
        slab       *session_slab_;
        ht         *flow_ht_;
        ht         *session_id_ht_;
        ht         *session_hal_handle_ht_;
    } __PACK__;
    
    // TLS CB related state
    struct {
        slab       *tlscb_slab_;
        ht         *tlscb_id_ht_;
        ht         *tlscb_hal_handle_ht_;
    } __PACK__;

    // TCP CB related state
    struct {
        slab       *tcpcb_slab_;
        ht         *tcpcb_id_ht_;
        ht         *tcpcb_hal_handle_ht_;
    } __PACK__;

    // buf-pool related state
    struct {
        slab       *buf_pool_slab_;
        ht         *buf_pool_id_ht_;
        ht         *buf_pool_hal_handle_ht_;
        bitmap     *cos_in_use_bmp_[HAL_MAX_TM_PORTS];
                    // bitmap indicating if the cos is already assigned to a
                    // buffer pool
    } __PACK__;

    // queue related state
    struct {
        slab       *queue_slab_;
        ht         *queue_id_ht_;
        ht         *queue_hal_handle_ht_;
    } __PACK__;

    // policer related state
    struct {
        slab       *policer_slab_;
        ht         *ingress_policer_id_ht_;
        ht         *ingress_policer_hal_handle_ht_;
        ht         *egress_policer_id_ht_;
        ht         *egress_policer_hal_handle_ht_;
    } __PACK__;
    
    // WRing related state
    struct {
        slab       *wring_slab_;
        ht         *wring_id_ht_;
        ht         *wring_hal_handle_ht_;
    } __PACK__;
    
    // Proxy related state
    struct {
        slab       *proxy_slab_;
        ht         *proxy_type_ht_;
        ht         *proxy_hal_handle_ht_;
    } __PACK__;

    // acl related state
    struct {
        slab       *acl_slab_;
        ht         *acl_id_ht_;
        ht         *acl_hal_handle_ht_;
    } __PACK__;

    // assumption is there will be only one infra vlan
    struct {
        void        *infra_l2seg_;  // l2seg_t *
    } __PACK__;
    
    // IPSec CB related state
    struct {
        slab       *ipseccb_slab_;
        ht         *ipseccb_id_ht_;
        ht         *ipseccb_hal_handle_ht_;
    } __PACK__;
    
    // CPU CB related state
    struct {
        slab       *cpucb_slab_;
        ht         *cpucb_id_ht_;
        ht         *cpucb_hal_handle_ht_;
    } __PACK__;

    typedef struct cfg_ver_in_use_info_ {
        cfg_version_t    ver;          // version number
        uint16_t         usecnt:15;    // number of users of this version
        uint16_t         valid:1;      // entry valid or not
    } __PACK__ cfg_ver_in_use_info_t;

    typedef struct cfg_version_rsvd_info_ {
        cfg_version_t    ver;          // version number
        uint8_t          valid:1;      // entry valid or not
    } __PACK__ cfg_version_rsvd_info_t;

    hal_spinlock_t             slock_;                                 // lock to protect cfg db meta
    cfg_version_t              cfg_db_ver_;                            // cfg db current version
    cfg_version_t              max_rsvd_ver_;                          // max. reserved version
    cfg_ver_in_use_info_t      cfg_ver_in_use_[HAL_THREAD_ID_MAX];     // versions in use for read
    cfg_version_rsvd_info_t    cfg_ver_rsvd_[HAL_THREAD_ID_MAX];       // versions reserved for write
};

extern class hal_state    *g_hal_state;

}    // namespace hal

#endif    // __HAL_STATE_HPP__

