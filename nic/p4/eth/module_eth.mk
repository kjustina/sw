# {C} Copyright 2018 Pensando Systems Inc. All rights reserved
include ${MKDEFS}/pre.mk
MODULE_TARGET   = eth.p4bin
MODULE_PIPELINE = iris gft apollo artemis apulu athena
MODULE_SRCS     = ${MODULE_SRC_DIR}/eth_rxdma_actions.p4 \
                  ${MODULE_SRC_DIR}/eth_txdma_actions.p4
MODULE_NCC_OPTS = --p4-plus --pd-gen --asm-out --no-ohi \
                  --two-byte-profile \
                  --fe-flags="-I${TOPDIR} -I${SDKDIR} ${${PIPELINE}_DEFS}" \
                  --gen-dir ${BLD_P4GEN_DIR}
MODULE_DEPS     = $(shell find ${MODULE_DIR} -name '*.p4' -o -name '*.h') \
                  $(shell find ${MODULE_DIR}/../include -name '*') \
				  $(shell find ${MODULE_DIR}/../common-p4+ -name '*.p4')
include ${MKDEFS}/post.mk
