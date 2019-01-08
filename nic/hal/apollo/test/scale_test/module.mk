# {C} Copyright 2018 Pensando Systems Inc. All rights reserved

include ${MKDEFS}/pre.mk
MODULE_TARGET   = apollo_scale_test.gtest
MODULE_PIPELINE = apollo
MODULE_ARCH     = x86_64
MODULE_SOLIBS   = pal ociframework ocicore ociapi ociapi_impl ocitestutils \
                  ${NIC_${PIPELINE}_P4PD_SOLIBS} \
                  ${NIC_SDK_SOLIBS} \
                  sdkp4 sdkp4utils sdkcapri_csrint sdkcapri_asicrw_if sdkcapri \
				  sdkplatformutils sdkxcvrdriver \
                  p4pd_common_p4plus_rxdma p4pd_common_p4plus_txdma \
                  asicpd pdcapri bm_allocator hal_mock mtrack
MODULE_LDLIBS   =  ${NIC_COMMON_LDLIBS} \
				   ${NIC_CAPSIM_LDLIBS} \
				   ${NIC_THIRDPARTY_GOOGLE_LDLIBS} \
				   ${NIC_THIRDPARTY_SSL_LDLIBS}
MODULE_INCS     = ${NIC_CSR_INCS}
MODULE_FLAGS    = ${NIC_CSR_FLAGS}
MODULE_DEFS     = -DCAPRI_SW ${NIC_CSR_DEFINES}
include ${MKDEFS}/post.mk
