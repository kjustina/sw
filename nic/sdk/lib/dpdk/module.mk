# {C} Copyright 2019 Pensando Systems Inc. All rights reserved

include ${MKDEFS}/pre.mk
MODULE_TARGET   = libdpdk_device.lib
MODULE_PREREQS  = dpdk.submake
MODULE_LDLIBS   = dpdk
MODULE_INCS     = ${SDKDIR}/dpdk/build/include
ifeq ($(ARCH), x86_64)
MODULE_FLAGS  = -march=native
endif
include ${MKDEFS}/post.mk
