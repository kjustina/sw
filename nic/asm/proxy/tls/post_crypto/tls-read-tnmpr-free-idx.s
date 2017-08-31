/*
 *	Implements the read tnmpr free idx of the TxDMA P4+ tls  pipeline
 *  Also writes the freed object into the object ring slot
 */

#include "tls-phv.h"
#include "tls-shared-state.h"
#include "tls-macros.h"
#include "tls-table.h"
#include "ingress.h"
#include "INGRESS_p.h"

                
struct tx_table_s3_t2_k k                  ;
struct phv_ p	;
struct tx_table_s3_t2_read_tnmpr_free_pi_d d ;

%%
	
        .param          TNMPR_TABLE_BASE
	    .align
tls_free_tnmpr:

        CAPRI_CLEAR_TABLE2_VALID

	    addi		r3, r0, TNMPR_TABLE_BASE

        add         r4, d.tnmpr_free_pi, r0
        sll         r4, r4, TNMPR_TABLE_ENTRY_SIZE_SHFT
        add         r3, r3, r4
        memwr.wx    r3, k.{to_s3_ipage}.wx

        /* TBD memwr A.CI */
	    nop.e
	    nop

