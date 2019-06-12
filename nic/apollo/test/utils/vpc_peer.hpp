//
// {C} Copyright 2019 Pensando Systems Inc. All rights reserved
//
//----------------------------------------------------------------------------
///
/// \file
/// This file contains the vpc peer test utility routines
///
//----------------------------------------------------------------------------

#ifndef __TEST_UTILS_VPC_PEER_HPP__
#define __TEST_UTILS_VPC_PEER_HPP__

#include "nic/sdk/include/sdk/base.hpp"
#include "nic/apollo/api/include/pds_vpc.hpp"

namespace api_test {

// VPC peer test feeder class
class vpc_peer_feeder {
public:
    pds_vpc_peer_key_t key;
    pds_vpc_key_t vpc1;
    pds_vpc_key_t vpc2;
    uint32_t num_obj;

    // Constructor
    vpc_peer_feeder() { };
    vpc_peer_feeder(const vpc_peer_feeder& feeder) {
        init(feeder.key, feeder.vpc1, feeder.vpc2, feeder.num_obj);
    }

    // Initialize feeder with the base set of values
    void init(pds_vpc_peer_key_t key, pds_vpc_key_t vpc1, pds_vpc_key_t vpc2,
              uint32_t num_vpc_peer = 1);

    // Iterate helper routines
    void iter_init() { cur_iter_pos = 0; }
    bool iter_more() { return (cur_iter_pos < num_obj); }
    void iter_next(int width = 1);

    // Build routines
    void key_build(pds_vpc_peer_key_t *key);
    void spec_build(pds_vpc_peer_spec_t *spec);

    // Compare routines
    bool key_compare(pds_vpc_peer_key_t *key);
    bool spec_compare(pds_vpc_peer_spec_t *spec);
    sdk::sdk_ret_t info_compare(pds_vpc_peer_info_t *info);

private:
    uint32_t cur_iter_pos;
};

// Function prototypes
sdk::sdk_ret_t create(vpc_peer_feeder& feeder);
sdk::sdk_ret_t read(vpc_peer_feeder& feeder);
sdk::sdk_ret_t update(vpc_peer_feeder& feeder);
sdk::sdk_ret_t del(vpc_peer_feeder& feeder);

}    // namespace api_test

#endif    // __TEST_UTILS_VPC_PEER_HPP__
