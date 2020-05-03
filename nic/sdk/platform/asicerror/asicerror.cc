/**
 * Copyright (c) 2019 Pensando Systems, Inc.
 *
 * @file    asicerror.cc
 *
 * @brief   This file handles and dumps interrupts
 */

#include "lib/pal/pal.hpp"
#include "interrupts.hpp"

static intr_cfg_t intr_cfg;

static void
walk_interrupts (intr_reg_t &reg,
                 intr_walk_cb_t intr_walk_cb,
                 void *ctxt)
{
    intr_field_t *field;

    for(int i=0; i < reg.field_count; i++) {
        field = &reg.fields[i];

        if (intr_walk_cb) {
            intr_walk_cb(&reg, field, ctxt);
        }
        if(field->next_ptr) {
            walk_interrupts(*field->next_ptr, intr_walk_cb, ctxt);
        }
    }
}

void
intr_dump_cb (intr_reg_t *reg, intr_field_t *field, void *ctxt)
{
    int fd = *(int *)ctxt;

    if (field->count == 0) {
        return;
    }

    std::string name = std::string(reg->name) + "_" + std::string(field->name);

    if (fd == -1) {
        SDK_TRACE_ERR("name %s, count %lu, severity %s, desc %s",
                      name.c_str(), field->count,
                      get_severity_str(field->severity).c_str(), field->desc);
    } else {
        dprintf(fd, "%-50s%-10lu%-9s%-11s\n",
                name.c_str(), field->count,
                get_severity_str(field->severity).c_str(), field->desc);
    }
}

static void
intr_clear_cb (intr_reg_t *reg,
               intr_field_t *field,
               void *ctxt)
{
    field->count = 0;
}

static void
handle_interrupt (intr_reg_t *reg, intr_field_t *field)
{
    if (intr_cfg.intr_event_cb) {
        intr_cfg.intr_event_cb(reg, field);
    }
}

static void
traverse_interrupts (intr_reg_t &reg)
{
    pal_ret_t ret;
    uint32_t data = 0x0;
    intr_reg_type_t reg_type = reg.reg_type;
    uint64_t reg_addr = reg.addr;
    uint16_t field_count = reg.field_count;
    intr_field_t *field;

#ifdef ELBA
    // TBD-ELBA-REBASE: PCIE/BX/MX all skipped - needs refinement: BX/MX have uncorrectable errors not being handled even in Capri
    switch (reg.id) {
    case 418 ... 461:
        // Skip PCIE blocks
    case 17 ... 18:
        // Skip BX block
    case 1 ... 6:
        //Skip MX blocks
        return;
    }
#else
    switch (reg.id) {
    case 137: // pp_pp_int_pp
    case 140:
    case 142:
    case 144:
    case 146:
    case 148:
    case 150:
    case 152:
    case 154:
    case 155 ... 178: // pp_pp_port_c_X_{int_c_mac,int_c_ecc,int_groups_intreg}
    case 362:
    case 363:
        // Skip BX block
    case 477 ... 482:
        //Skip MX blocks
        return;
    }
#endif

    if (reg_type == INTR_REG_TYPE_SRC) {
        // SDK_TRACE_ERR("Reading addr: 0x%x", reg_addr);
        ret = sdk::lib::pal_reg_read(reg_addr, &data, 1);
        if (ret != 0) {
        }
    }

    for(int i=0; i < field_count; i++) {
        field = &reg.fields[i];

        if (reg_type == INTR_REG_TYPE_SRC) {
            if (data & (1 << i)) {
                field->count += 1;
                switch (field->flags) {
                    case INTR_FLAGS_IGNORE_ALL:
                        continue;
                    case INTR_FLAGS_IGNORE_ONCE:
                        if (field->count == 1) {
                            continue;
                        }
                    case INTR_FLAGS_NONE:
                    default:
                        break;
                }
                handle_interrupt(&reg, field);
            }
        }
        if(field->next_ptr) {
            traverse_interrupts(*field->next_ptr);
        }
    }

    if (reg_type == INTR_REG_TYPE_SRC) {
        // clear interrupts
        // SDK_TRACE_ERR("Writing addr: 0x%x", reg_addr);
        ret = sdk::lib::pal_reg_write(reg_addr, &data, 1);
        if (ret != 0) {
        }
    }
}

int
intr_init (intr_cfg_t *cfg)
{
    intr_cfg = *cfg;
    return 0;
}

void
traverse_interrupts (void)
{
#ifdef ELBA
    traverse_interrupts(elb0);
#else
    traverse_interrupts(cap0);
#endif
    traverse_interrupts(all_csrs);
}

void
walk_interrupts (intr_walk_cb_t intr_walk_cb, void *ctxt)
{
#ifdef ELBA
    walk_interrupts(elb0, intr_walk_cb, ctxt);
#else
    walk_interrupts(cap0, intr_walk_cb, ctxt);
#endif
    walk_interrupts(all_csrs, intr_walk_cb, ctxt);
}

void
clear_interrupts (void)
{
    walk_interrupts(intr_clear_cb, NULL);
}
