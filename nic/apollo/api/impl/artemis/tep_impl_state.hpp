//
// {C} Copyright 2019 Pensando Systems Inc. All rights reserved
//
//----------------------------------------------------------------------------
///
/// \file
/// TEP implementation state
///
//----------------------------------------------------------------------------

#ifndef __TEP_IMPL_STATE_HPP__
#define __TEP_IMPL_STATE_HPP__

#include "nic/sdk/lib/indexer/indexer.hpp"
#include "nic/sdk/lib/table/sltcam/sltcam.hpp"
#include "nic/apollo/framework/api_base.hpp"
#include "nic/apollo/framework/state_base.hpp"
#include "nic/apollo/api/pds_state.hpp"

namespace api {
namespace impl {

/// \defgroup PDS_TEP_IMPL_STATE - TEP state functionality
/// \ingroup PDS_TEP
/// \@{

// forward declaration
class tep_impl;
class mapping_impl;

/// \brief state maintained for TEPs
class tep_impl_state : public state_base {
public:
    /// \brief constructor
    tep_impl_state(pds_state *state);

    /// \brief destructor
    ~tep_impl_state();

    /// \brief  API to initiate transaction over all the table manamgement
    ///         library instances
    /// \return SDK_RET_OK on success, failure status code on error
    sdk_ret_t table_transaction_begin(void);

    /// \brief API to end transaction over all the table manamgement
    ///        library instances
    /// return SDK_RET_OK on success, failure status code on error
    sdk_ret_t table_transaction_end(void);

private:
    indexer *remote_46_tep_idxr(void) { return remote_46_tep_idxr_; }
    sltcam *tep1_rx_tbl(void) { return tep1_rx_tbl_; }
    friend class vpc_impl;   ///< vpc_impl class is friend of vpc_impl_state
    friend class tep_impl;   ///< tep_impl, friend of tep_impl_state

private:
    indexer   *remote_46_tep_idxr_;    ///< indexer to allocate hw id for TEPs
    sltcam    *tep1_rx_tbl_;           ///< tcam table for TEP1_RX
};

///   \@}

}    // namespace impl
}    // namespace api

#endif    // __TEP_IMPL_STATE_HPP__
