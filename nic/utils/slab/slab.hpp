// {C} Copyright 2017 Pensando Systems Inc. All rights reserved

#ifndef __SLAB_HPP__
#define __SLAB_HPP__

#include <base.h>
#include <hal_lock.hpp>
#include <hal_mem.hpp>
#include <list.hpp>

namespace hal {
namespace utils {

#define SLAB_NAME_MAX_LEN        16

typedef struct slab_block_s slab_block_t;
struct slab_block_s {
    slab_block_t    *prev_;         // previous block pointer
    slab_block_t    *next_;         // next block pointer
    void            *free_head_;    // pointer to free element in block
    uint32_t        num_in_use_;    // no. of elements in use in this block
    uint8_t         elems_[0];      // memory for block elements
} __PACK__;

class slab {
public:
    static slab *factory(const char *name, hal_slab_t slab_id, uint32_t elem_sz,
                         uint32_t elems_per_block, bool thread_safe=false,
                         bool grow_on_demand=true, bool delay_delete=false,
                         bool zero_on_alloc=false);
    ~slab();
    void *alloc(void);
    void free(void *elem);
    uint32_t num_in_use(void) const { return num_in_use_; }
    uint32_t num_allocs(void) const { return num_allocs_; }
    uint32_t num_frees(void) const { return num_frees_; }
    uint32_t num_alloc_fails(void) const { return num_alloc_fails_; }
    uint32_t num_blocks(void) const { return num_blocks_; }

    friend hal_ret_t hal::free_to_slab(hal_slab_t slab_id, void *elem);
    friend hal_ret_t hal::pd::free_to_slab(hal_slab_t slab_id, void *elem);
private:
    hal_spinlock_t    slock_;
    char              name_[SLAB_NAME_MAX_LEN];
    hal_slab_t        slab_id_;
    uint32_t          elem_sz_;
    uint32_t          elems_per_block_;
    uint32_t          raw_block_sz_;
    bool              thread_safe_;
    bool              grow_on_demand_;
    bool              delay_delete_;
    bool              zero_on_alloc_;

    // statistics
    uint32_t          num_in_use_;
    uint32_t          num_allocs_;
    uint32_t          num_frees_;
    uint32_t          num_alloc_fails_;
    uint32_t          num_blocks_;

    // meta data
    slab_block_t      *block_head_;

private:
    slab() {};
    int init(const char *name, hal_slab_t slab_id, uint32_t elem_sz,
             uint32_t elems_per_block, bool thread_safe, bool grow_on_demand,
             bool delay_delete, bool zero_on_alloc);
    void delay_delete_cb(uint32_t timer_id, void *ctxt);
    void free_(void *elem);
    slab_block_t *alloc_block_(void);
};

}    // namespace hal
}    // namespace utils

#endif  // __SLAB_HPP__

