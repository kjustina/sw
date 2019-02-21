/**
 * Copyright (c) 2018 Pensando Systems, Inc.
 *
 * @file    core.cc
 *
 * @brief   This file contains core helper functions
 */

#if !defined (__OCI_CORE_HPP__)
#define __OCI_CORE_HPP__

#include <signal.h>
#include "nic/sdk/include/sdk/base.hpp"
#include "nic/apollo/api/oci_state.hpp"

namespace core {

enum {
    THREAD_ID_NONE       = 0,
    THREAD_ID_CONTROL    = 1,
    THREAD_ID_PERIODIC   = 2,
    THREAD_ID_DATA_START = 16,
    THREAD_ID_DATA_END   = 47,
    THREAD_ID_MAX        = 38
};

enum {
    TIMER_ID_NONE          = 0,
    TIMER_ID_SESSION_AGE   = 1,
    TIMER_ID_SYSTEM_SCAN   = 2,
};

sdk_ret_t thread_spawn(oci_state *state);
sdk_ret_t parse_global_config(string pipeline, string cfg_file, oci_state *state);
sdk_ret_t parse_pipeline_config(string pipeline, oci_state *state);

typedef void (*sig_handler_t)(int sig, siginfo_t *info, void *ptr);
sdk_ret_t sig_init(int signal, sig_handler_t sig_handler);
sdk_ret_t schedule_timers(void);

}    // namespace core

#endif    /** __OCI_CORE_HPP__ */
