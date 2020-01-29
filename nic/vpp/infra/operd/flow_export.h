//
// {C} Copyright 2020 Pensando Systems Inc. All rights reserved
//

#ifndef __VPP_INFRA_OPERD_FLOW_EXPORT_H__
#define __VPP_INFRA_OPERD_FLOW_EXPORT_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

void pds_operd_export_flow_ip4(uint32_t sip,
                               uint32_t dip,
                               uint8_t ip_proto,
                               uint16_t src_port,
                               uint16_t dst_port,
                               uint16_t lookup_id,
                               uint8_t add,
                               uint8_t allow);

void pds_operd_export_flow_ip6(uint8_t *sip,
                               uint8_t *dip,
                               uint8_t ip_proto,
                               uint16_t src_port,
                               uint16_t dst_port,
                               uint16_t lookup_id,
                               uint8_t add,
                               uint8_t allow);

void pds_operd_export_flow_l2(uint8_t *smac,
                              uint8_t *dmac,
                              uint8_t proto,
                              uint16_t bd_id,
                              uint8_t add,
                              uint8_t allow);

#ifdef __cplusplus
}
#endif

#endif  // __VPP_INFRA_OPERD_FLOW_EXPORT_H__
