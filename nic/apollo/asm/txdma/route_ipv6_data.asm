#include "../../p4/include/lpm_defines.h"

#include "apollo_txdma.h"
#include "INGRESS_p.h"
#include "ingress.h"

struct phv_                p;
struct route_ipv6_data_k   k;
struct route_ipv6_data_d   d;

#define action_name        search_retrieve
#define key                k.p4_to_txdma_header_lpm_dst
#define keys(a)            d.search_retrieve_d.key ## a
#define data(a)            d.search_retrieve_d.data ## a
#define res_field          p.txdma_to_p4e_header_nexthop_index
#define res_handler        route_ipv6_handler

%%

#include "../include/lpm64b_data.h"

res_handler:
    phvwr.e         res_field, r7
    nop

/*****************************************************************************/
/* error function                                                            */
/*****************************************************************************/
.align
.assert $ < ASM_INSTRUCTION_OFFSET_MAX
error_handler(action_name):
    phvwr.e    p.capri_intr_drop, 1
    nop
