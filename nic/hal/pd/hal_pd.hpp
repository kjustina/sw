#ifndef __HAL_PD_HPP__
#define __HAL_PD_HPP__

#include "nic/include/hal.hpp"
#include "nic/hal/pd/hal_pd_error.hpp"

namespace hal {
namespace pd {

extern hal_ret_t   hal_pd_init(hal::hal_cfg_t *hal_cfg);
extern hal_ret_t   hal_pd_mem_init(void);
extern hal_ret_t   hal_pd_mem_init_phase_2 (void);
extern hal_ret_t   hal_pd_pgm_def_entries (void);
extern hal_ret_t   hal_pd_pgm_def_p4plus_entries (void);
extern hal_ret_t   p4pd_table_defaults_init(void);
extern std::string hal_pd_csr_dump(char *csr_str);

}    // namespace pd
}    // namespace hal

#endif    // __HAL_PD_HPP__

