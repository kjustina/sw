#include "athena.h"
#include "egress.h"
#include "EGRESS_p.h"

struct nacl_d   d;
struct phv_     p;

%%

nacl_permit:
    phvwr.!c1       p.capri_intrinsic_drop, 1
    nop.e
    nop

.align
nacl_redirect:
    phvwr.!c1.e     p.capri_intrinsic_drop, 1
    phvwr           p.control_metadata_redir_type, d.u.nacl_redirect_d.redir_type
    
    phvwr           p.control_metadata_redir_oport, d.u.nacl_redirect_d.oport
    phvwr           p.control_metadata_redir_lif, d.u.nacl_redirect_d.lif
    phvwr           p.control_metadata_redir_qtype, d.u.nacl_redirect_d.qtype
    phvwr           p.control_metadata_redir_qid, d.u.nacl_redirect_d.qid
    phvwr           p.control_metadata_redir_app_id, d.u.nacl_redirect_d.app_id
#if 1
    /* FIXME: Improve mechanism to relay stats reason */
    seq             c1, d.u.nacl_redirect_d.redir_type, PACKET_ACTION_REDIR_RXDMA
    phvwr.c1        p.control_metadata_p4e_stats_flag, P4E_STATS_FLAG_TX_TO_ARM

    /* Uplink */
    seq.!c1         c2, d.u.nacl_redirect_d.oport, UPLINK_HOST
    phvwr.c2        p.control_metadata_p4e_stats_flag, P4E_STATS_FLAG_TX_TO_HOST
    seq.!c1         c2, d.u.nacl_redirect_d.oport, UPLINK_SWITCH
    phvwr.c2        p.control_metadata_p4e_stats_flag, P4E_STATS_FLAG_TX_TO_SWITCH
#endif
    phvwr.e         p.capri_intrinsic_drop, 0
    phvwr           p.control_metadata_p4i_drop_reason, 0

.align
nacl_drop:
    phvwr.e         p.capri_intrinsic_drop, 1
    phvwr           p.control_metadata_p4i_drop_reason[P4I_DROP_NACL], 1

/*****************************************************************************/
/* error function                                                            */
/*****************************************************************************/
.align
.assert $ < ASM_INSTRUCTION_OFFSET_MAX
nacl_error:
    phvwr.e         p.capri_intrinsic_drop, 1
    nop
