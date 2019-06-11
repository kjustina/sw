//
// {C} Copyright 2019 Pensando Systems Inc. All rights reserved
//
//----------------------------------------------------------------------------
///
/// \file
/// This file contains the subnet test utility routines
///
//----------------------------------------------------------------------------

#ifndef __TEST_UTILS_SUBNET_HPP__
#define __TEST_UTILS_SUBNET_HPP__

#include "nic/sdk/include/sdk/base.hpp"
#include "nic/apollo/api/include/pds_vpc.hpp"
#include "nic/apollo/api/include/pds_subnet.hpp"

namespace api_test {

// Subnet test feeder class
class subnet_feeder {
public:
    pds_subnet_key_t key;
    pds_vpc_key_t vpc;
    std::string cidr_str;
    ip_prefix_t pfx;
    std::string vr_ip;
    std::string vr_mac;
    pds_route_table_key_t v4_route_table;
    pds_route_table_key_t v6_route_table;
    pds_policy_key_t ing_v4_policy;
    pds_policy_key_t ing_v6_policy;
    pds_policy_key_t egr_v4_policy;
    pds_policy_key_t egr_v6_policy;
    uint32_t num_obj;

    // Constructor
    subnet_feeder() { };
    subnet_feeder(const subnet_feeder& feeder) {
        init(feeder.key, feeder.vpc, feeder.cidr_str, feeder.num_obj);
    }

    // Initialize feeder with the base set of values
    void init(pds_subnet_key_t key, pds_vpc_key_t vpc_key,
              std::string cidr_str, int num_subnet = 1);

    // Iterate helper routines
    void iter_init() { cur_iter_pos = 0; }
    bool iter_more() { return (cur_iter_pos < num_obj); }
    void iter_next(int width = 1);

    // Build routines
    void key_build(pds_subnet_key_t *key);
    void spec_build(pds_subnet_spec_t *spec);

    // Compare routines
    bool key_compare(pds_subnet_key_t *key);
    bool spec_compare(pds_subnet_spec_t *spec);
    sdk::sdk_ret_t info_compare(pds_subnet_info_t *info);

private:
    uint32_t cur_iter_pos;
};

// Export variables
extern pds_subnet_key_t k_subnet_key;

// Function prototypes
sdk::sdk_ret_t create(subnet_feeder& feeder);
sdk::sdk_ret_t read(subnet_feeder& feeder);
sdk::sdk_ret_t update(subnet_feeder& feeder);
sdk::sdk_ret_t del(subnet_feeder& feeder);

void sample_subnet_setup();
void sample_subnet_teardown();

}    // namespace api_test

#endif    // __TEST_UTILS_SUBNET_HPP__
