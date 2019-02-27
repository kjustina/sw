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
#include "nic/apollo/include/api/pds_vcn.hpp"
#include "nic/apollo/include/api/pds_subnet.hpp"

namespace api_test {

/// Subnet test utility class
class subnet_util {
public:
    /// \brief constructor
    subnet_util(pds_vcn_id_t vcn_id, pds_subnet_id_t id, std::string cidr_str);

    /// \brief destructor
    ~subnet_util();

    /// Test params
    pds_subnet_id_t id;
    pds_vcn_key_t vcn;
    std::string cidr_str;
    pds_route_table_id_t v4_route_table;    /// Route table id
    pds_route_table_id_t v6_route_table;    /// Route table id

    /// \brief Create subnet
    ///
    /// \return #SDK_RET_OK on success, failure status code on error
    sdk_ret_t create();

    /// \brief Read subnet
    ///
    /// \param[in] vcn_id VCN id
    /// \param[in] subnet_id subnet id
    ///
    /// \return #SDK_RET_OK on success, failure status code on error
    sdk_ret_t read(pds_subnet_spec_t *spec, pds_subnet_status_t *status,
                   pds_subnet_stats_t *stats);

    /// \brief Delete subnet
    ///
    /// \return #SDK_RET_OK on success, failure status code on error
    sdk_ret_t del();

    /// \brief Delete subnet
    ///
    /// \param[in] vcn_id VCN id
    /// \param[in] subnet_id subnet id
    ///
    /// \return #SDK_RET_OK on success, failure status code on error
    static sdk_ret_t del(pds_vcn_id_t vcn_id, pds_subnet_id_t subnet_id);

    /// \brief Get a subnet from a VCN
    ///
    /// \param[in] vcn_id VCN id
    /// \param[in] subnet_id subnet id
    ///
    /// \return #SDK_RET_OK on success, failure status code on error
    static sdk_ret_t get(pds_vcn_id_t vcn_id, pds_subnet_id_t subnet_id);

    /// \brief Create many subnets
    ///
    /// \param[in] num_subnet number of subnets to create
    /// \param[in] vcn_id VCN id
    /// \param[in] pfxstr subnet prefix (cidr) in string form
    ///
    /// \return #SDK_RET_OK on success, failure status code on error
    static sdk_ret_t many_create(uint32_t num_subnet, pds_vcn_id_t vcn_id,
                                 std::string pfxstr);

    /// \brief Delete all subnets in a VCN
    ///
    /// \param[in] vcn_id VCN id
    ///
    /// \return #SDK_RET_OK on success, failure status code on error
    static sdk_ret_t all_delete(pds_vcn_id_t vcn_id);

    /// \brief Get all subnets in a VCN
    ///
    /// \param[in] vcn_id VCN id
    /// \param[out] count number of subnet objects
    /// \param[out] vcn list of subnet objects
    ///
    /// \return #SDK_RET_OK on success, failure status code on error
    static sdk_ret_t all_get(pds_vcn_id_t vcn_id, int *count,
                             pds_subnet_spec_t *subnets);
};

}    // namespace api_test

#endif    // __TEST_UTILS_SUBNET_HPP__
