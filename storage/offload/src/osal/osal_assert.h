/*
 * {C} Copyright 2018 Pensando Systems Inc.
 * All rights reserved.
 *
 */
#ifndef __OSAL_ASSERT_H__
#define __OSAL_ASSERT_H__

#ifndef __KERNEL__
#include <assert.h>
#define OSAL_ASSERT(x) assert(x)
#elif __KERNEL__
#define OSAL_ASSERT(x) BUG_ON(x)
#elif _KERNEL
#define OSAL_ASSERT(x) BUG_ON(x)
#else
#error "Invalid build!!"
#endif

#endif	/* __OSAL_ASSERT_H__ */
