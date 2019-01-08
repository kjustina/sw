# {C} Copyright 2018 Pensando Systems Inc. All rights reserved

include ${MKDEFS}/pre.mk
MODULE_TARGET   = libdelphishm.a
MODULE_PIPELINE = iris gft
MODULE_ARLIBS   = delphiutils delphiproto 
MODULE_SOLIBS   = sdkpal logger
MODULE_SKIP_COVERAGE = 1
ALL_CC_FILES = $(wildcard ${MODULE_SRC_DIR}/*.cc)
ALL_TEST_FILES = $(wildcard ${MODULE_SRC_DIR}/*_test.cc)
MODULE_SRCS = $(filter-out $(ALL_TEST_FILES), $(ALL_CC_FILES))
include ${MKDEFS}/post.mk
