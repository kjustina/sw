
#include "INGRESS_p.h"
#include "ingress.h"
#include "INGRESS_eth_rx_rss_params_k.h"

#include "../../asm/eth/rx/defines.h"

struct phv_ p;
struct eth_rx_rss_params_k k;
struct eth_rx_rss_params_eth_rx_rss_params_d d;

%%

.align
eth_rx_rss_params:

  and               r1, d.rss_type, k.p4_to_p4plus_pkt_type
  beq               r1, r0, eth_rx_rss_params_skip
  nop

  phvwr.e           p.{toeplitz_key0_data, toeplitz_key1_data}, d.rss_key[319:64]
  phvwr             p.toeplitz_key2_data[127:64], d.rss_key[63:0]

eth_rx_rss_params_skip:
  nop.e
  nop
