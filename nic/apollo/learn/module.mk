# {C} Copyright 2019 Pensando Systems Inc. All rights reserved

include ${MKDEFS}/pre.mk
MODULE_TARGET   = libpdslearn.so
MODULE_PIPELINE = apollo artemis apulu athena
MODULE_SRCS	= $(wildcard ${MODULE_SRC_DIR}/*.cc)
ifneq ($(PIPELINE), apulu)
MODULE_SRCS	+= $(wildcard ${MODULE_SRC_DIR}/impl/stub/*.cc)
else
MODULE_SRCS	+= $(wildcard ${MODULE_SRC_DIR}/impl/${PIPELINE}/*.cc)
endif
MODULE_SOLIBS   = dpdk_device
ifneq ($(PIPELINE), apulu)
MODULE_INCS     = ${MODULE_DIR}/impl/stub
else
MODULE_INCS     = ${MODULE_DIR}/impl/$(PIPELINE)
endif
include ${MKDEFS}/post.mk
