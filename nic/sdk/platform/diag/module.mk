# {C} Copyright 2018 Pensando Systems Inc. All rights reserved
include ${MKDEFS}/pre.mk
MODULE_TARGET   = libdiag.so
MODULE_INCS     := ${MODULE_SRC_DIR}/../../ \
				   ${MODULE_SRC_DIR}/../../lib/pal/ \
				   ${MODULE_SRC_DIR}/../../lib/logger/ \
				   ${MODULE_SRC_DIR}/../../../nic/asic/capri/verif/apis/ \
				   ${MODULE_SRC_DIR}/../../../../platform/src/lib/sensor/
include ${MKDEFS}/post.mk
