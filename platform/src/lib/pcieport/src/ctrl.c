/*
 * Copyright (c) 2017-2018, Pensando Systems Inc.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
#include <inttypes.h>

#include "pci_ids.h"
#include "pal.h"
#include "pciehsys.h"
#include "pcieport.h"
#include "pcieport_impl.h"

static void
pcieport_mac_k_gen(pcieport_t *p)
{
    const int pn = p->port;
    u_int64_t gen;

    gen = pal_reg_rd64_safe(PXC_(CFG_C_MAC_K_GEN, pn));
    gen &= 0xffffffff00000000ULL;
    /* XXX check this for asic XXX */
    gen |= 0x80e20054; /* XXX replace hard-coded value? */

    switch (p->cap_gen) {
    case 1: gen |= (0x1 << 9); break;
    case 2: gen |= (0x3 << 9); break;
    case 3: gen |= (0x7 << 9); break;
    case 4: gen |= (0xf << 9); break;
    }

    switch (p->cap_width) {
    case 1: gen |= (0xf << 24); break;
    case 2: gen |= (0xe << 24); break;
    case 4: gen |= (0xc << 24); break;
    case 8: gen |= (0x8 << 24); break;
    case 16: /* 16 is default */ break;
    }

    pal_reg_wr64_safe(PXC_(CFG_C_MAC_K_GEN, pn), gen);
}

static void
pcieport_mac_k_pexconf(pcieport_t *p)
{
    const int pn = p->port;
    u_int32_t pexconf[12];

    pal_reg_rd32w(PXC_(CFG_C_MAC_K_PEXCONF, pn), pexconf, 12);
    pexconf[2] &= ~(0x3 << 10); /* claim ASPM L0s, L1 not supported */
    pal_reg_wr32w(PXC_(CFG_C_MAC_K_PEXCONF, pn), pexconf, 12);
}

static void
pcieport_mac_k_pciconf(pcieport_t *p)
{
    const int pn = p->port;
    u_int32_t val;
    extern int vga_support;

    /* class code */
    val = 0x06040000;
    pal_reg_wr32(PXC_(CFG_C_MAC_K_PCICONF, pn) + 4, 0x06040000);

    /* vga supported */
    val = pal_reg_rd32(PXC_(CFG_C_MAC_K_PCICONF, pn) + 0xc);
    val &= ~(1 << 4);
    val |= (vga_support << 4);
    pal_reg_wr32(PXC_(CFG_C_MAC_K_PCICONF, pn) + 0xc, val);
}

static void
pcieport_mac_k_rx_cred(pcieport_t *p)
{
    if (!pal_is_asic()) {
        u_int32_t val = 0x00200080;
        pal_reg_wr32(PXC_(CFG_C_MAC_K_RX_CRED, p->port), val);
    }
}

static void
pcieport_mac_set_ids(pcieport_t *p)
{
    const int pn = p->port;
    u_int32_t val;

    /* set subvendor/deviceid */
    val = (p->subdeviceid << 16) | p->subvendorid;
    pal_reg_wr32(PXC_(CFG_C_MAC_SSVID_CAP, pn), val);
}

/*
 * Select local or host as source for pcie refclk.
 * Hw default is local refclk.
 */
static void
pcieport_select_pcie_refclk(const int host_clock)
{
    if (host_clock) {
        pal_reg_wr32(PP_(CFG_PP_PCIE_PLL_REFCLK_SEL), 0xff);
        pal_reg_wr32(PP_(CFG_PP_PCIE_PLL_REFCLK_SOURCE_SEL), 0x3);
    } else {
        pal_reg_wr32(PP_(CFG_PP_PCIE_PLL_REFCLK_SEL), 0x00);
        pal_reg_wr32(PP_(CFG_PP_PCIE_PLL_REFCLK_SOURCE_SEL), 0x0);
    }
}

static void
pcieport_unreset(pcieport_t *p)
{
    u_int32_t val = pal_reg_rd32(PP_(CFG_PP_SW_RESET));
    val &= ~(0x3 << (p->port << 1));
    pal_reg_wr32(PP_(CFG_PP_SW_RESET), val);
}

static int
pcieport_mac_unreset(pcieport_t *p)
{
    u_int16_t phystatus;
    int perstn;
    const int maxpolls = 2000; /* 2 seconds */
    int polls = 0;

    do {
        usleep(1000);
        phystatus = pcieport_get_phystatus(p);
        perstn = pcieport_get_perstn(p);
    } while (phystatus && perstn && ++polls < maxpolls);

    p->phypolllast = polls;
    if (polls > p->phypollmax) {
        p->phypollmax = polls;
    }

    if (!perstn) {
        /*
         * perstn went away - we went back into reset
         */
        p->phypollperstn++;
        return -1;
    }

    if (phystatus != 0) {
        /*
         * PHY didn't come out of reset as expected?
         */
        p->phypollfail++;
        return -1;
    }

    pcieport_set_mac_reset(p, 0); /* mac unreset */
    return 0;
}

static void
pcieport_system(const char *path)
{
    int r;

    pciehsys_log("running %s:\n", path);
    r = system(path);
    if (r) pciehsys_error("%s: failed %d\n", path, r);
}

static void
pcieport_run_script(const char *name, const int port)
{
    char path[80];

#ifdef __aarch64__
    snprintf(path, sizeof(path), "/mnt/%s", name);
    if (access(path, X_OK) == 0) pcieport_system(path);

    snprintf(path, sizeof(path), "/mnt/%s-%d", name, port);
    if (access(path, X_OK) == 0) pcieport_system(path);

    snprintf(path, sizeof(path), "/tmp/%s", name);
    if (access(path, X_OK) == 0) pcieport_system(path);

    snprintf(path, sizeof(path), "/tmp/%s-%d", name, port);
    if (access(path, X_OK) == 0) pcieport_system(path);
#else
    snprintf(path, sizeof(path), "./%s", name);
    if (access(path, X_OK) == 0) pcieport_system(path);

    snprintf(path, sizeof(path), "./%s-%d", name, port);
    if (access(path, X_OK) == 0) pcieport_system(path);
#endif
}

static void
pcieport_poweron_script(pcieport_t *p)
{
    pcieport_run_script("pcie-poweron", p->port);
}

static int
pcieport_hostconfig(pcieport_t *p)
{
    int otrace;

    otrace = pal_reg_trace_control(getenv("PCIEPORT_INIT_TRACE") != NULL);
    pal_reg_trace("================ pcieport_hostconfig %d start\n", p->port);

    if (!pal_is_asic()) {
        /* toggle these resets */
        pcieport_set_serdes_reset(p, 1);
        pcieport_set_pcs_reset(p, 1);
        pcieport_set_serdes_reset(p, 0);
        pcieport_set_pcs_reset(p, 0);
    } else {
        static int done_once;

        if (!done_once) {
            int host_clock = 1;
            char *env = getenv("PCIEPORT_HOST_CLOCK");

            if (env) {
                host_clock = strtoul(env, NULL, 0);
                pciehsys_log("host_clock override %d\n", host_clock);
            }

            pcieport_select_pcie_refclk(host_clock);
            pcieport_serdes_init();
            done_once = 1;
        }
        pcieport_set_pcs_reset(p, 1);
        pcieport_set_pcs_reset(p, 0);
    }

    pcieport_unreset(p);

    pcieport_mac_k_gen(p);
    pcieport_mac_k_rx_cred(p);
    pcieport_mac_k_pexconf(p);
    pcieport_mac_k_pciconf(p);
    pcieport_mac_set_ids(p);

    pcieport_poweron_script(p);

    /* now ready to unreset mac */
    if (pcieport_mac_unreset(p) < 0) {
        return -1;
    }

    if (!pal_is_asic()) {
        /* reduce clock frequency for fpga */
        pcieport_set_clock_freq(p, 8);
    }

    pcieport_set_ltssm_en(p, 1);  /* ready for ltssm */
    pal_reg_trace("================ pcieport_hostconfig %d end\n", p->port);
    pal_reg_trace_control(otrace);
    return 0;
}

static int
pcieport_rcconfig(pcieport_t *p)
{
    /* XXX */
    assert(0);
    return 0;
}

int
pcieport_config(pcieport_t *p)
{
    int r;

    if (!p->config) return -1;

    if (p->host) {
        r = pcieport_hostconfig(p);
    } else {
        r = pcieport_rcconfig(p);
    }
    return r;
}

static int
pcieport_validate_hostconfig(pcieport_t *p)
{
    switch (p->cap_gen) {
    case 1:
    case 2:
    case 3:
    case 4:
        /* all good */
        break;
    default:
        pciehsys_error("port %d unsupported gen%d\n", p->port, p->cap_gen);
        return -EFAULT;
    }

    switch (p->cap_width) {
    case 1: /* x1 uses 2 lanes */
    case 2:
        /* XXX verify peer isn't also configured to use our lanes */
        break;
    case 4:
        /* odd ports don't support x4 */
        if (p->port & 0x1) {
            goto bad_width;
        }
        /* XXX verify peer isn't also configured to use our lanes */
        break;
    case 8:
        /* only ports 0,4 can support x8 */
        if (p->port != 0 && p->port != 4) {
            goto bad_width;
        }
        break;
    case 16:
        /* only port 0 can use all 16 lanes */
        if (p->port != 0) {
            goto bad_width;
        }
        break;
    default:
        pciehsys_error("port %d unsupported x%d\n", p->port, p->cap_width);
        return -ERANGE;
    }
    return 0;

 bad_width:
    pciehsys_error("port %d doesn't support x%d\n", p->port, p->cap_width);
    return -EINVAL;
}

static int
pcieport_parse_cap(char *cap, int *gen, int *width)
{
    if (sscanf(cap, "gen%dx%d", gen, width) == 2) {
        if (*gen >= 1 && *gen <= 4 &&
            *width >= 1 && *width <= 16) {
            return 1;
        }
    }
    return 0;
}

static int
pcieport_getenv_cap(int port, int *gen, int *width)
{
    char envar[40];
    char *env;

    snprintf(envar, sizeof(envar), "PCIEPORT%d_CAP", port);
    env = getenv(envar);
    if (env && pcieport_parse_cap(env, gen, width)) {
        return 1;
    }

    snprintf(envar, sizeof(envar), "PCIEPORT_CAP");
    env = getenv(envar);
    if (env && pcieport_parse_cap(env, gen, width)) {
        return 1;
    }

    return 0;
}

static void
pcieport_default_cap(pcieport_t *p, int *gen, int *width)
{
    /* check envar for override */
    if (!pcieport_getenv_cap(p->port, gen, width)) {
        /* no envar, provide defaults */
        *gen = pal_is_asic() ? 4 : 1;
        *width = pal_is_asic() ? 16 : 4;
    }
}

static int
pcieport_cmd_hostconfig(pcieport_t *p, void *arg)
{
    pcieport_hostconfig_t *pcfg = arg;
    int r, default_gen, default_width;

    pcieport_default_cap(p, &default_gen, &default_width);

    /*
     * Use caller's param defaults if provided.
     */
    if (pcfg) {
        p->cap_gen = pcfg->gen;
        p->cap_width = pcfg->width;
        p->subvendorid = pcfg->subvendorid;
        p->subdeviceid = pcfg->subdeviceid;
    }

    /*
     * Provide default params for any unspecified.
     */
    if (p->cap_gen == 0) {
        p->cap_gen = default_gen;
    }
    if (p->cap_width == 0) {
        p->cap_width = default_width;
    }
    if (p->subvendorid == 0) {
        p->subvendorid = PCI_VENDOR_ID_PENSANDO;
    }
    if (p->subdeviceid == 0) {
        p->subdeviceid = PCI_SUBDEVICE_ID_PENSANDO_NAPLES100;
    }

    /*
     * Verify the requested config is valid.
     */
    if ((r = pcieport_validate_hostconfig(p)) < 0) {
        return r;
    }

    switch (p->cap_width) {
    case  1: /* x1 uses 2 lanes */
    case  2: p->lanemask = 0x0003 << (p->port << 0); break;
    case  4: p->lanemask = 0x000f << (p->port << 1); break;
    case  8: p->lanemask = 0x00ff << (p->port << 2); break;
    case 16: p->lanemask = 0xffff << (p->port << 4); break;
    }

    p->host = 1;
    p->config = 1;

    return 0;
}

static int
pcieport_cmd_crs(pcieport_t *p, void *arg)
{
    int on = *(int *)arg;

    if (!p->config) return -EBADF;
    if (!p->host)   return -EINVAL;
    p->crs = on;
    pcieport_set_crs(p, p->crs);
    return 0;
}

int
pcieport_ctrl(pcieport_t *p, const pcieport_cmd_t cmd, void *arg)
{
    int r = 0;

    if (!p->open) {
        return -EBADF;
    }

    switch (cmd) {
    case PCIEPORT_CMD_HOSTCONFIG:
        r = pcieport_cmd_hostconfig(p, arg);
        break;
    case PCIEPORT_CMD_CRS:
        r = pcieport_cmd_crs(p, arg);
        break;
    default:
        pciehsys_error("pcieport_ctrl: unknown cmd %d\n", cmd);
        r = -EINVAL;
        break;
    }
    return r;
}
