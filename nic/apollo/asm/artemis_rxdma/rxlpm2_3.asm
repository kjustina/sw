#include "../../p4/include/lpm_defines.h"

#include "artemis_rxdma.h"
#include "INGRESS_p.h"
#include "ingress.h"

struct phv_                p;
struct rxlpm2_3_k          k;
struct rxlpm2_3_d          d;

// Define Table Name and Action Names
#define table_name         rxlpm2_3
#define action_keys32b     match2_3_32b
#define action_keys128b    match2_3_128b
#define action_data16b     match2_3_16b_retrieve
#define action_data32b     match2_3_32b_retrieve

// Define table field names for the selected actions
#define keys16b(a)         d.u.match2_3_16b_d.key ## a
#define keys32b(a)         d.u.match2_3_32b_d.key ## a
#define keys128bhi(a)      d.u.match2_3_128b_d.key ## a[127:64]
#define keys128blo(a)      d.u.match2_3_128b_d.key ## a[63:0]
#define keys16b_(a)        d.u.match2_3_16b_retrieve_d.key ## a
#define data16b(a)         d.u.match2_3_16b_retrieve_d.data ## a
#define keys32b_(a)        d.u.match2_3_32b_retrieve_d.key ## a
#define data32b(a)         d.u.match2_3_32b_retrieve_d.data ## a

// Define key field names
#define key                k.lpm_metadata_lpm2_key
#define keylo              k.lpm_metadata_lpm2_key[63:0]
#define keyhi              k.lpm_metadata_lpm2_key[127:64]
#define base_addr          k.{lpm_metadata_lpm2_base_addr_sbit0_ebit1...\
                              lpm_metadata_lpm2_base_addr_sbit2_ebit33}
#define curr_addr          k.{lpm_metadata_lpm2_next_addr_sbit0_ebit1...\
                              lpm_metadata_lpm2_next_addr_sbit2_ebit33}

// Define PHV field names
#define next_addr          p.lpm_metadata_lpm2_next_addr

// Define result register and handler function names
#define res_reg            r7
#define result_handler16b  nop_res_handler
#define result_handler32b  nop_res_handler

%%

#include "../include/lpm.h"

nop_res_handler:
    nop.e
    nop
