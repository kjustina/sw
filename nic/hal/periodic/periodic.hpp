//------------------------------------------------------------------------------
// periodic thread manages few timer wheels and can carry our periodic tasks
// as background activities. Few examples include:
// - delay deleting memory resources to slabs or heap
// - flow table scan to age out sessions or detect dead flows
// - periodic stats collection and/or aggregation
//------------------------------------------------------------------------------
#ifndef __HAL_PERIODIC_HPP__
#define __HAL_PERIODIC_HPP__

#include "nic/include/base.h"
#include "sdk/twheel.hpp"
#include "nic/include/hal_mem.hpp"

namespace hal {
namespace periodic {

void *periodic_thread_init(void *ctxt);
void *periodic_thread_run(void *ctxt);
bool periodic_thread_is_running(void);

//------------------------------------------------------------------------------
// API invoked by other threads to trigger cb after timeout
// Returns the timer entry used to update/delete the timer
//------------------------------------------------------------------------------
void *
periodic_timer_schedule (uint32_t timer_id, uint64_t timeout, void *ctxt,
                         sdk::lib::twheel_cb_t cb, bool periodic);

//------------------------------------------------------------------------------
// API invoked by other threads to delete the scheduled timer
//------------------------------------------------------------------------------
void *periodic_timer_delete (void *timer);

// API to delay delete any slab objects
hal_ret_t delay_delete_to_slab(hal_slab_t slab_id,             // slab to free back to
                               void *elem);                    // element to free back

// callback invoked for delay deleting slab elements back to their respective
// blocks
void slab_delay_delete_cb(hal_slab_t slab_id, void *ctxt);

}    // namespace periodic
}    // namespace hal

#endif    // __HAL_PERIODIC_HPP__

