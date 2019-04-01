//
// {C} Copyright 2018 Pensando Systems Inc. All rights reserved
//
//----------------------------------------------------------------------------
///
/// \file
/// This file captures PDS memory related helpers
///
//----------------------------------------------------------------------------

#ifndef __CORE_TRACE_HPP__
#define __CORE_TRACE_HPP__

#include "nic/sdk/lib/logger/logger.hpp"

extern sdk_logger::trace_cb_t    g_trace_cb;
static void inline
register_trace_cb(sdk_logger::trace_cb_t  trace_cb)
{
    g_trace_cb = trace_cb;
}

#define PDS_TRACE_ERR(fmt, ...)                                           \
{                                                                         \
    struct timespec    tp_;                                               \
    clock_gettime(CLOCK_MONOTONIC, &tp_);                                 \
    g_trace_cb(sdk::lib::SDK_TRACE_LEVEL_ERR, "E [%llu.%9lu] [%s:%d] "    \
               fmt, tp_.tv_sec, tp_.tv_nsec, __func__, __LINE__,          \
               ##__VA_ARGS__);                                            \
}

#define PDS_TRACE_WARN(fmt, ...)                                          \
{                                                                         \
    struct timespec    tp_;                                               \
    clock_gettime(CLOCK_MONOTONIC, &tp_);                                 \
    g_trace_cb(sdk::lib::SDK_TRACE_LEVEL_WARN, "W [%llu.%9lu] [%s:%d] "   \
               fmt, tp_.tv_sec, tp_.tv_nsec, __func__, __LINE__,          \
               ##__VA_ARGS__);                                            \
}

#define PDS_TRACE_INFO(fmt, ...)                                          \
{                                                                         \
    struct timespec    tp_;                                               \
    clock_gettime(CLOCK_MONOTONIC, &tp_);                                 \
    g_trace_cb(sdk::lib::SDK_TRACE_LEVEL_INFO, "I [%llu.%9lu] [%s:%d] "   \
               fmt, tp_.tv_sec, tp_.tv_nsec, __func__, __LINE__,          \
               ##__VA_ARGS__);                                            \
}

#define PDS_TRACE_DEBUG(fmt, ...)                                         \
{                                                                         \
    struct timespec    tp_;                                               \
    clock_gettime(CLOCK_MONOTONIC, &tp_);                                 \
    g_trace_cb(sdk::lib::SDK_TRACE_LEVEL_DEBUG, "D [%llu.%9lu] [%s:%d] "  \
               fmt, tp_.tv_sec, tp_.tv_nsec, __func__, __LINE__,          \
               ##__VA_ARGS__);                                            \
}

#define PDS_TRACE_DEBUG_NO_HEADER(fmt, ...)                               \
{                                                                         \
    g_trace_cb(sdk::lib::SDK_TRACE_LEVEL_DEBUG, fmt, ##__VA_ARGS__);      \
}

#define PDS_TRACE_VERBOSE(fmt, ...)                                       \
{                                                                         \
    struct timespec    tp_;                                               \
    clock_gettime(CLOCK_MONOTONIC, &tp_);                                 \
    g_trace_cb(sdk::lib::SDK_TRACE_LEVEL_VERBOSE, "V [%llu.%9lu] [%s:%d] "\
               fmt, tp_.tv_sec, tp_.tv_nsec, __func__, __LINE__,          \
               ##__VA_ARGS__);                                            \
}

#endif    // __CORE_TRACE_HPP__
