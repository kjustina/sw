# {C} Copyright 2018 Pensando Systems Inc. All rights reserved
include ${MKDEFS}/pre.mk
MODULE_TARGET = libagent_api.so
MODULE_PIPELINE = iris gft apollo
MODULE_SOLIBS = ipc
include ${MKDEFS}/post.mk
