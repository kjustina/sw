#include "ingress.h"
#include "INGRESS_p.h"
#include "../../p4/nw/include/defines.h"
#include "nw.h"

struct validate_packet_k k;
struct phv_              p;

%%

validate_packet:
  K_DBG_WR(0x90)
  DBG_WR(0x98, 0x98)
  seq         c1, k.capri_p4_intrinsic_parser_err, TRUE
  balcf       r7, [c1], f_check_parser_errors
  seq         c1, k.tunnel_metadata_tunnel_terminate, TRUE
  bcf         [c1], validate_tunneled_packet

validate_native_packet:
  DBG_WR(0x99, 0x99)
  seq         c1, k.ethernet_srcAddr, r0
  seq         c2, k.ethernet_dstAddr, r0
  seq         c3, k.ethernet_srcAddr[40], 1
  sub         r1, r0, 1
  seq         c4, k.ethernet_srcAddr, r1[47:0]
  bcf         [c1|c2|c3|c4], malformed_packet
  seq         c1, k.ipv4_valid, TRUE
  seq         c2, k.ipv6_valid, TRUE

  .csbegin
  cswitch [c2,c1]
  nop
  .cscase 0
  nop.e
  nop
  .cscase 1
  sne         c1, k.ipv4_version, 4
  seq.!c1     c1, k.ipv4_ttl, 0
  nop.!c1.e
  phvwr.c1.e  p.control_metadata_drop_reason[DROP_MALFORMED_PKT], 1
  phvwr       p.capri_intrinsic_drop, 1
  .cscase 2
  sne         c1, k.ipv6_version, 6
  seq.!c1     c1, k.ipv6_hopLimit, 0
  nop.!c1.e
  phvwr.c1.e  p.control_metadata_drop_reason[DROP_MALFORMED_PKT], 1
  phvwr       p.capri_intrinsic_drop, 1
  .cscase 3
  nop.e
  nop
  .csend

validate_tunneled_packet:
  DBG_WR(0x9a, 0x9a)
  seq         c1, k.ethernet_srcAddr, r0
  seq.!c1     c1, k.ethernet_dstAddr, r0
  seq.!c1     c1, k.ethernet_srcAddr[40], 1
  sub         r1, r0, 1
  seq.!c1     c1, k.ethernet_srcAddr, r1[47:0]
  seq.!c1     c1, k.inner_ethernet_srcAddr, r0
  seq.!c1     c1, k.inner_ethernet_dstAddr, r0
  seq.!c1     c1, k.inner_ethernet_srcAddr[40], 1
  seq.!c1     c1, k.inner_ethernet_srcAddr, r1[47:0]
  b.c1        malformed_packet
  seq         c1, k.inner_ipv4_valid, TRUE
  seq         c2, k.inner_ipv6_valid, TRUE

  .csbegin
  cswitch [c2,c1]
  nop
  .cscase 0
  nop.e
  nop
  .cscase 1
  sne         c1, k.inner_ipv4_version, 4
  seq.!c1     c1, k.inner_ipv4_ttl, 0
  nop.!c1.e
  phvwr.c1.e  p.control_metadata_drop_reason[DROP_MALFORMED_PKT], 1
  phvwr       p.capri_intrinsic_drop, 1
  .cscase 2
  sne        c1, k.inner_ipv6_version, 6
  seq.!c1    c1, k.inner_ipv6_hopLimit, 0
  nop.!c1.e
  phvwr.c1.e  p.control_metadata_drop_reason[DROP_MALFORMED_PKT], 1
  phvwr       p.capri_intrinsic_drop, 1
  .cscase 3
  nop.e
  nop
  .csend

f_check_parser_errors:
  DBG_WR(0x9b, k.capri_p4_intrinsic_len_err)
  // do not use c1 register in this function
  bbeq        k.control_metadata_uplink, TRUE, check_parser_errors_uplink
  seq         c2, k.capri_p4_intrinsic_len_err, 0
  smneb.!c2   c2, k.{p4plus_to_p4_update_udp_len...p4plus_to_p4_update_ip_len},\
                0x5, 0
  jrcf        [c2], r7
  phvwr.!c2.e p.control_metadata_drop_reason[DROP_PARSER_LEN_ERR], 1
  phvwr       p.capri_intrinsic_drop, 1

check_parser_errors_uplink:
  phvwr       p.control_metadata_checksum_results, k.capri_intrinsic_csum_err
  seq         c3, k.capri_p4_intrinsic_crc_err, 0
  jrcf        [c2 & c3], r7
  phvwr.!c2   p.control_metadata_drop_reason[DROP_PARSER_LEN_ERR], 1
  phvwr.!c3   p.control_metadata_drop_reason[DROP_PARSER_ICRC_ERR], 1
  phvwr.e     p.capri_intrinsic_drop, 1
  nop

malformed_packet:
  DBG_WR(0x9c, 0x9c)
  phvwr.e     p.control_metadata_drop_reason[DROP_MALFORMED_PKT], 1
  phvwr       p.capri_intrinsic_drop, 1

/*****************************************************************************/
/* error function                                                            */
/*****************************************************************************/
.align
.assert $ < ASM_INSTRUCTION_OFFSET_MAX
validate_packet_error:
  nop.e
  nop
