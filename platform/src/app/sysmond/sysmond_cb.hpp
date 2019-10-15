// {C} Copyright 201 Pensando Systems Inc. All rights reserved.

#ifndef _SYSMOND_CB_H_
#define _SYSMOND_CB_H_

#include "platform/sysmon/sysmon.hpp"
#include "platform/asicerror/interrupts.hpp"
#include "nic/sdk/platform/sensor/sensor.hpp"

void event_cb_init(void);
void frequency_change_event_cb(uint32_t frequency);
void cattrip_event_cb(void);
void power_event_cb(sdk::platform::sensor::system_power_t *power);
void temp_event_cb(sdk::platform::sensor::system_temperature_t *temperature,
                   sysmond_hbm_threshold_event_t hbm_event);
void memory_event_cb(uint64_t total_mem, uint64_t available_mem,
                     uint64_t free_mem);
void intr_event_cb(const intr_reg_t *reg, const intr_field_t *field);

#endif    // _SYSMOND_CB_H_
