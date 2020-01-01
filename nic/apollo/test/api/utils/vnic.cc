//
// {C} Copyright 2019 Pensando Systems Inc. All rights reserved
//
//----------------------------------------------------------------------------

#include "nic/sdk/include/sdk/ip.hpp"
#include "nic/sdk/include/sdk/if.hpp"
#include "nic/apollo/api/utils.hpp"
#include "nic/apollo/test/api/utils/vnic.hpp"

#define HOST_LIF_ID_MIN 71
#define HOST_LIF_ID_MAX 78

namespace test {
namespace api {

const uint64_t k_feeder_mac = 0x101000000000;
// artemis - one is reserved, hence max is MAX_VNIC - 1
const uint32_t k_max_vnic = ::apollo() ? 64 : PDS_MAX_VNIC - 1;

static inline void
vnic_feeder_encap_init (uint32_t id, pds_encap_type_t encap_type,
                        pds_encap_t *encap)
{
    encap->type = encap_type;
    // update encap value to seed base
    switch (encap_type) {
    case PDS_ENCAP_TYPE_DOT1Q:
        encap->val.vlan_tag = id;
        break;
    case PDS_ENCAP_TYPE_QINQ:
        encap->val.qinq_tag.c_tag = id;
        encap->val.qinq_tag.s_tag = id + 4096;
        break;
    case PDS_ENCAP_TYPE_MPLSoUDP:
        encap->val.mpls_tag = id;
        break;
    case PDS_ENCAP_TYPE_VXLAN:
        encap->val.vnid = id;
        break;
    default:
        encap->val.value = id;
        break;
    }
}


static inline void
vnic_feeder_encap_next (pds_encap_t *encap, int width = 1)
{
    switch (encap->type) {
    case PDS_ENCAP_TYPE_DOT1Q:
        encap->val.vlan_tag += width;
        break;
    case PDS_ENCAP_TYPE_QINQ:
        encap->val.qinq_tag.c_tag += width;
        encap->val.qinq_tag.s_tag += width;
        break;
    case PDS_ENCAP_TYPE_MPLSoUDP:
        encap->val.mpls_tag += width;
        break;
    case PDS_ENCAP_TYPE_VXLAN:
        encap->val.vnid += width;
        break;
    default:
        encap->val.value += width;
        break;
    }
}

//----------------------------------------------------------------------------
// VNIC feeder class routines
//----------------------------------------------------------------------------

void
vnic_feeder::init(uint32_t id, uint32_t num_vnic, uint64_t mac,
                  pds_encap_type_t vnic_encap_type,
                  pds_encap_type_t fabric_encap_type,
                  bool src_dst_check, bool configure_policy) {
    this->id = id;
    this->vpc_id = 1;
    this->subnet_id = 1;
    this->mac_u64 = mac | (id << 24);
    vnic_feeder_encap_init(id, vnic_encap_type, &vnic_encap);
    vnic_feeder_encap_init(id, fabric_encap_type, &fabric_encap);
    this->src_dst_check = src_dst_check;
    this->tx_mirror_session_bmap = 0;
    this->rx_mirror_session_bmap = 0;
    this->configure_policy = configure_policy;
    num_obj = num_vnic;
}

void
vnic_feeder::iter_next(int width) {
    id += width;
    vnic_feeder_encap_next(&vnic_encap);
    if (apollo()) {
        vnic_feeder_encap_next(&fabric_encap);
        tx_mirror_session_bmap += width;
        rx_mirror_session_bmap += width;
    }
    mac_u64 += width;
    cur_iter_pos++;
}

void
vnic_feeder::key_build(pds_vnic_key_t *key) const {
    memset(key, 0, sizeof(pds_vnic_key_t));
    key->id = this->id;
}

static void
fill_policy_ids (pds_policy_key_t *pol_arr,
                 pds_policy_id_t start_key, uint8_t num_policy)
{
    for (int i = 0; i < num_policy; i++) {
        pol_arr[i].id = start_key++;
    }
}

static void
increment_num (uint8_t *num)
{
    (*num)++;
    if (*num > PDS_MAX_VNIC_POLICY) {
        *num = 0;
    }
}

void
vnic_feeder::spec_build(pds_vnic_spec_t *spec) const {
    static uint8_t num_policy = 0;
    //static uint32_t lif_id = HOST_LIF_ID_MIN;

    memset(spec, 0, sizeof(pds_vnic_spec_t));
    this->key_build(&spec->key);

    spec->subnet.id = subnet_id;
    spec->vnic_encap = vnic_encap;
    spec->fabric_encap = fabric_encap;
    MAC_UINT64_TO_ADDR(spec->mac_addr, mac_u64);
    spec->src_dst_check = src_dst_check;
    spec->tx_mirror_session_bmap = tx_mirror_session_bmap;
    spec->rx_mirror_session_bmap = rx_mirror_session_bmap;

#if 0
    // TODO: this should be under platform == HW check
    spec->host_ifindex = LIF_IFINDEX(lif_id++);
    if (lif_id > HOST_LIF_ID_MAX) {
        lif_id = HOST_LIF_ID_MIN;
    }
#endif

    if (this->configure_policy) {
        increment_num(&num_policy);
        spec->num_ing_v4_policy = num_policy;
        fill_policy_ids(spec->ing_v4_policy, 1, num_policy);
        increment_num(&num_policy);
        spec->num_ing_v6_policy = num_policy;
        fill_policy_ids(spec->ing_v6_policy, 6, num_policy);
        increment_num(&num_policy);
        spec->num_egr_v4_policy = num_policy;
        fill_policy_ids(spec->egr_v4_policy, 11, num_policy);
        increment_num(&num_policy);
        spec->num_egr_v6_policy = num_policy;
        fill_policy_ids(spec->egr_v6_policy, 16, num_policy);
    }
}

bool
vnic_feeder::key_compare(const pds_vnic_key_t *key) const {
    if (id != key->id)
        return false;
    return true;
}

bool
vnic_feeder::spec_compare(const pds_vnic_spec_t *spec) const {
    mac_addr_t mac = {0};

    if (!test::pdsencap_isequal(&vnic_encap, &spec->vnic_encap))
        return false;

    if (apollo()) {
        if (!test::pdsencap_isequal(&fabric_encap, &spec->fabric_encap))
            return false;

        if (src_dst_check != spec->src_dst_check)
            return false;

        if (tx_mirror_session_bmap != spec->tx_mirror_session_bmap)
            return false;

        if (rx_mirror_session_bmap != spec->rx_mirror_session_bmap)
            return false;
    }

    MAC_UINT64_TO_ADDR(mac, mac_u64);
    if (memcmp(mac, &spec->mac_addr, sizeof(mac)))
        return false;

    return true;
}

static vnic_feeder k_vnic_feeder;

void sample_vnic_setup(pds_batch_ctxt_t bctxt) {
    // setup and teardown parameters should be in sync
    k_vnic_feeder.init(1);
    many_create(bctxt, k_vnic_feeder);
}

void sample_vnic_teardown(pds_batch_ctxt_t bctxt) {
    // setup and teardown parameters should be in sync
    k_vnic_feeder.init(1);
    many_delete(bctxt, k_vnic_feeder);
}

}    // namespace api
}    // namespace test
