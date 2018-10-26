# {C} Copyright 2018 Pensando Systems Inc. All rights reserved
include ${MKDEFS}/pre.mk
MODULE_TARGET       = _libp4_p4pdcli.so
MODULE_PIPELINE     = iris
MODULE_PREREQS      = p4pd.swigcli
MODULE_SRC_DIR      = ${BLD_P4GEN_DIR}/p4
MODULE_SRCS         = $(wildcard ${MODULE_SRC_DIR}/src/*p4pd_cli_backend.cc) \
                      $(wildcard ${MODULE_SRC_DIR}/src/*entry_packing.cc) \
                      $(wildcard ${MODULE_SRC_DIR}/cli/*.cc)
MODULE_INCS         = ${BLD_P4GEN_DIR}/common_rxdma_actions/cli \
                      ${CLI_P4PD_INCS} 
MODULE_FLAGS        = ${CLI_P4PD_FLAGS}
MODULE_LDLIBS       = ${CLI_P4PD_LDLIBS}
MODULE_SOLIBS       = ${CLI_P4PD_SOLIBS}

include ${MKDEFS}/post.mk
