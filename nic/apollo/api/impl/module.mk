# {C} Copyright 2018 Pensando Systems Inc. All rights reserved

include ${MKDEFS}/pre.mk
MODULE_TARGET   = libpdsapi_impl.lib
MODULE_SRCS     = $(wildcard ${MODULE_SRC_DIR}/*.cc) $(wildcard ${MODULE_SRC_DIR}/${PIPELINE}/*.cc)
MODULE_PIPELINE = apollo artemis apulu athena
MODULE_INCS     = ${SDKDIR}/dpdk/build/include/ ${SDK_THIRD_PARTY_OMAPI_INCLUDES} ${MODULE_GEN_DIR}
MODULE_SOLIBS   = ${NIC_${PIPELINE}_PDSAPI_IMPL_SOLIBS}
MODULE_DEFS     = -DCAPRI_SW ${NIC_CSR_DEFINES} -DRTE_FORCE_INTRINSICS
MODULE_FLAGS    = ${NIC_CSR_FLAGS}
MODULE_PREREQS  = dpdk.submake hal.memrgns
MODULE_LDLIBS   = ${SDK_THIRD_PARTY_OMAPI_LIBS}

include ${MKDEFS}/post.mk
