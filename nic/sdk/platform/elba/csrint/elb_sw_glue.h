/*
 * Copyright (c) 2018, Pensando Systems Inc.
 */

#ifndef __ELB_SW_GLUE_H__
#define __ELB_SW_GLUE_H__

/*
 * Glue file between elb_xxx.c ASIC API files and our application.
 */

#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <sys/types.h>
#include "nic/sdk/lib/pal/pal.hpp"

//#define SLEEP(t) usleep(t)
#define sleep(t) usleep(t)

static inline void elb_sw_writereg(uint64_t addr, uint32_t data)
{
    sdk::lib::pal_reg_write(addr, &data, 1);
}

static inline uint32_t elb_sw_readreg(uint64_t addr)
{
    uint32_t data = 0x0;
    sdk::lib::pal_reg_read(addr, &data, 1);
    return data;
}

void elb_pp_sbus_write(int chip_id, int rcvr_addr, int data_addr, unsigned int data);

static inline void
*romfile_open(void *rom_info)
{
    return NULL;
}

static inline int
romfile_read(void *f, unsigned int *datap)
{
    return 0;
}

static inline void
romfile_close(void *f)
{
    return;
}

#endif /* __ELB_SW_GLUE_H__ */