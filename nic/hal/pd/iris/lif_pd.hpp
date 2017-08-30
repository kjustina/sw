#ifndef __HAL_LIF_PD_HPP__
#define __HAL_LIF_PD_HPP__

#include <base.h>
#include <pd.hpp>
#include <pd_api.hpp>


namespace hal {
namespace pd {

struct pd_lif_s {
    uint32_t    hw_lif_id;
    uint32_t    dummy;
    uint32_t    lif_lport_id;

    // pi ptr
    void        *pi_lif;
} __PACK__;


pd_lif_t *lif_pd_alloc ();
pd_lif_t *lif_pd_init (pd_lif_t *lif);
pd_lif_t *lif_pd_alloc_init ();
hal_ret_t lif_pd_free (pd_lif_t *lif);
hal_ret_t lif_pd_alloc_res(pd_lif_t *pd_lif, pd_lif_args_t *args);
hal_ret_t lif_pd_program_hw(pd_lif_t *pd_lif);
hal_ret_t lif_pd_pgm_output_mapping_tbl(pd_lif_t *pd_lif);
void link_pi_pd(pd_lif_t *pd_lif, lif_t *pi_lif);
void unlink_pi_pd(pd_lif_t *pd_lif, lif_t *pi_lif);

}   // namespace pd
}   // namespace hal

#endif    // __HAL_LIF_PD_HPP__

