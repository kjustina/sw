#include "req_rx.h"
#include "sqcb.h"

struct req_rx_phv_t p;
struct sqcb1_t d;
struct common_p4plus_stage0_app_header_table_k k;

#define TO_S1_P to_s1_to_stage

%%

.align
req_rx_sqcb1_process_ext:

    // global fields
    add            r1, r0, offsetof(struct phv_, common_global_global_data)

    // qstate addr is available as instrinsic data
    CAPRI_SET_FIELD(r1, PHV_GLOBAL_COMMON_T, cb_addr, CAPRI_RXDMA_INTRINSIC_QSTATE_ADDR_WITH_SHIFT(RQCB_ADDR_SHIFT))
    CAPRI_SET_FIELD(r1, PHV_GLOBAL_COMMON_T, lif, CAPRI_RXDMA_INTRINSIC_LIF)
    CAPRI_SET_FIELD_RANGE(r1, PHV_GLOBAL_COMMON_T, qid, qtype, CAPRI_RXDMA_INTRINSIC_QID_QTYPE)
    CAPRI_SET_FIELD(r1, PHV_GLOBAL_COMMON_T, flags, CAPRI_APP_DATA_RAW_FLAGS)

    // set DMA CMD ptr
    RXDMA_DMA_CMD_PTR_SET(REQ_RX_DMA_CMD_START_FLIT_ID)

    CAPRI_SET_FIELD2(TO_S1_P, msn, CAPRI_APP_DATA_AETH_MSN)
    CAPRI_SET_FIELD2(TO_S1_P, bth_psn, CAPRI_APP_DATA_BTH_PSN)
    CAPRI_SET_FIELD2(TO_S1_P, syndrome, CAPRI_APP_DATA_AETH_SYNDROME)

    nop.e
    nop
