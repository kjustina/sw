# {C} Copyright 2018 Pensando Systems Inc. All rights reserved
include ${MKDEFS}/pre.mk
MODULE_TARGET   = hello_p4.p4bin
MODULE_SRCS     = ${MODULE_SRC_DIR}/hello.p4
MODULE_PIPELINE = hello
ifeq ($(ASIC),elba)
MODULE_NCC_OPTS = --asm-out --gen-dir ${BLD_P4GEN_DIR} --asic elba \
                  --cfg-dir ${BLD_PGMBIN_DIR}/hello_p4 \
                  --i2e-user --fe-flags="-DELBA -I${TOPDIR} -I${SDKDIR}"
else
MODULE_NCC_OPTS = --asm-out --gen-dir ${BLD_P4GEN_DIR} \
                  --cfg-dir ${BLD_PGMBIN_DIR}/hello_p4 \
                  --i2e-user --fe-flags="-I${TOPDIR} -I${SDKDIR}"
endif
MODULE_DEPS     = $(shell find ${MODULE_DIR} -name '*.p4' -o -name '*.h') \
                  $(shell find ${MODULE_DIR}/../include -name '*.p4' -o -name '*.h') \
                  $(shell find ${TOPDIR}/nic/p4/include -name '*')
MODULE_POSTGEN_MK = module_p4pd.mk
include ${MKDEFS}/post.mk
