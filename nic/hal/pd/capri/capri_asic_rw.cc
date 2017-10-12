#include <unistd.h>
#include <errno.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <atomic>
#include "nic/hal/hal.hpp"
#include "nic/hal/pd/capri/capri.hpp"
#include "nic/include/asic_rw.hpp"
#include "nic/model_sim/include/lib_model_client.h"

namespace hal {

extern thread_local thread *t_curr_thread;

namespace pd {

// asic model's cfg port socket descriptor
static bool g_asic_rw_ready_;

#define HAL_ASIC_RW_Q_SIZE                           128
#define HAL_ASIC_RW_OPERATION_MEM_READ               0
#define HAL_ASIC_RW_OPERATION_MEM_WRITE              1
#define HAL_ASIC_RW_OPERATION_REG_READ               2
#define HAL_ASIC_RW_OPERATION_REG_WRITE              3

//------------------------------------------------------------------------------
// asic read-write entry, one such entry is added to the asic read/write
// thread's queue whenever asic read/write is attempted by any HAL thread
//------------------------------------------------------------------------------
typedef struct asic_rw_entry_ {
    uint8_t      opn:2;     // operation requested to perform
    uint8_t      done:1;    // TRUE if asic-rw thread performed operation
    hal_ret_t    status;    // result status of operation requested
    uint64_t     addr;      // address to write to or read from
    uint32_t     len;       // length of data to read or write
    uint8_t      *data;     // data to write or buffer to copy data to for mem read/write
    uint32_t      reg_data;     // data to write or buffer to copy data to for mem read/write
} asic_rw_entry_t;

//------------------------------------------------------------------------------
// asic read-write thread maintains one queue per HAL thread to serve
// read/write operations by HAL thread, thus avoiding locking altogether
//------------------------------------------------------------------------------
typedef struct asic_rw_queue_s {
    std::atomic<uint32_t>    nentries;    // no. of entries in the queue
    uint16_t                 pindx;       // producer index
    uint16_t                 cindx;       // consumer index
    asic_rw_entry_t          entries[HAL_ASIC_RW_Q_SIZE];    // entries
} asic_rw_queue_t;

// per producer read/write request queues
asic_rw_queue_t    g_asic_rw_workq[HAL_THREAD_ID_MAX];

//------------------------------------------------------------------------------
// return TRUE is asicrw thread is ready to do read/write operations
//------------------------------------------------------------------------------
bool
is_asic_rw_ready (void)
{
    return g_asic_rw_ready_;
}

//------------------------------------------------------------------------------
// read data from specified address in the memory to given buffer
// NOTE: this is always a blocking call and this API runs in the calling
//       thread's context
//------------------------------------------------------------------------------
static hal_ret_t
asic_do_read (uint8_t opn, uint64_t addr, uint8_t *data, uint32_t len)
{
    uint16_t           pindx;
    uint32_t           curr_tid = t_curr_thread->thread_id();
    asic_rw_entry_t    *rw_entry;

    if (!data) {
        return HAL_RET_INVALID_ARG;
    }

    if (g_asic_rw_workq[curr_tid].nentries >= HAL_ASIC_RW_Q_SIZE) {
        HAL_TRACE_ERR("ASIC rwq for thread {}, tid {} full, read failed",
                      t_curr_thread->name(), curr_tid);
        return HAL_RET_HW_PROG_ERR;
    }
    pindx = g_asic_rw_workq[curr_tid].pindx;
    rw_entry = &g_asic_rw_workq[curr_tid].entries[pindx];
    rw_entry->opn = opn;
    rw_entry->done = FALSE;
    rw_entry->status = HAL_RET_ERR;
    rw_entry->addr = addr;
    rw_entry->len = len;
    rw_entry->data = data;
    g_asic_rw_workq[curr_tid].nentries++;
    while (!rw_entry->done) {
        if (t_curr_thread->can_yield()) {
            pthread_yield();
        }
    }

    return rw_entry->status;
}

//------------------------------------------------------------------------------
// public API for register read operations
// NOTE: this is always a blocking call and this API runs in the calling
//       thread's context
//------------------------------------------------------------------------------
hal_ret_t
asic_reg_read (uint64_t addr, uint32_t *data)
{
    return asic_do_read(HAL_ASIC_RW_OPERATION_REG_READ, addr,
                        (uint8_t *)data, 0);
}

//------------------------------------------------------------------------------
// public API for memory read operations
// NOTE: this is always a blocking call and this API runs in the calling
//       thread's context
//------------------------------------------------------------------------------
hal_ret_t
asic_mem_read (uint64_t addr, uint8_t *data, uint32_t len)
{
    return asic_do_read(HAL_ASIC_RW_OPERATION_MEM_READ, addr, data, len);
}

//------------------------------------------------------------------------------
// write given data at specified address in the memory
// NOTE: this API runs in the calling thread's context and supports both
// blocking and non-blocking writes
//------------------------------------------------------------------------------
static hal_ret_t
asic_do_write (uint8_t opn, uint64_t addr, uint8_t *data,
               uint32_t len, bool blocking)
{
    hal_ret_t          ret;
    uint16_t           pindx;
    uint32_t           curr_tid = t_curr_thread->thread_id();
    asic_rw_entry_t    *rw_entry;

    if (g_asic_rw_workq[curr_tid].nentries >= HAL_ASIC_RW_Q_SIZE) {
        HAL_TRACE_ERR("ASIC rwq for thread {}, tid {} full, write failed",
                      t_curr_thread->name(), curr_tid);
        return HAL_RET_HW_PROG_ERR;
    }
    pindx = g_asic_rw_workq[curr_tid].pindx;
    rw_entry = &g_asic_rw_workq[curr_tid].entries[pindx];
    rw_entry->opn = opn;
    rw_entry->done = FALSE;
    rw_entry->status = HAL_RET_ERR;
    rw_entry->addr = addr;
    rw_entry->len = len;
    if (!len) {
        rw_entry->reg_data = *((uint32_t *)data);
    } else {
        rw_entry->data = data;
    }
    g_asic_rw_workq[curr_tid].nentries++;

    if (blocking) {
        while (!rw_entry->done) {
            if (t_curr_thread->can_yield()) {
                pthread_yield();
            }
        }
        ret = rw_entry->status;
    } else {
        // move the producer index to next slot
        g_asic_rw_workq[curr_tid].pindx++;
        if (g_asic_rw_workq[curr_tid].pindx >= HAL_ASIC_RW_Q_SIZE) {
            g_asic_rw_workq[curr_tid].pindx = 0;
        }
        ret = HAL_RET_OK;
    }

    return ret;
}

//------------------------------------------------------------------------------
// public API for register write operations
// NOTE: this API runs in the calling thread's context and supports both
// blocking and non-blocking writes
//------------------------------------------------------------------------------
hal_ret_t
asic_reg_write (uint64_t addr, uint32_t *data, bool blocking)
{
    return asic_do_write(HAL_ASIC_RW_OPERATION_REG_WRITE,
                         addr, (uint8_t *)data, 0, blocking);
}

//------------------------------------------------------------------------------
// public API for memory write operations
// NOTE: this API runs in the calling thread's context and supports both
// blocking and non-blocking writes
//------------------------------------------------------------------------------
hal_ret_t
asic_mem_write (uint64_t addr, uint8_t *data, uint32_t len, bool blocking)
{
    return asic_do_write(HAL_ASIC_RW_OPERATION_MEM_WRITE,
                         addr, data, len, blocking);
}

//------------------------------------------------------------------------------
// ASIC read-write thread's forever loop to server read and write requests from
// other HAL threads
//------------------------------------------------------------------------------
static void
asic_rw_loop (void)
{
    uint32_t           qid;
    uint16_t           cindx;
    bool               work_done, rv;
    asic_rw_entry_t    *rw_entry;
    uint32_t           regval;

    while (TRUE) {
        work_done = false;
        for (qid = 0; qid < HAL_THREAD_ID_MAX; qid++) {
            if (!g_asic_rw_workq[qid].nentries) {
                // no read/write requests
                continue;
            }

            // found a read/write request to serve
            cindx = g_asic_rw_workq[qid].cindx;
            rw_entry = &g_asic_rw_workq[qid].entries[cindx];
            switch (rw_entry->opn) {
            case HAL_ASIC_RW_OPERATION_MEM_READ:
                rv = read_mem(rw_entry->addr, rw_entry->data, rw_entry->len);
                break;

            case HAL_ASIC_RW_OPERATION_MEM_WRITE:
                rv = write_mem(rw_entry->addr, rw_entry->data, rw_entry->len);
                break;

            case HAL_ASIC_RW_OPERATION_REG_READ:
                rv = read_reg(rw_entry->addr, regval);
                if (rv) {
                    *(uint32_t *)rw_entry->data = regval;
                }
                break;

            case HAL_ASIC_RW_OPERATION_REG_WRITE:
                regval = rw_entry->reg_data;
                rv = write_reg(rw_entry->addr, regval);
                break;

            default:
                HAL_TRACE_ERR("Invalid operation {}", rw_entry->opn);
                rv = false;
                break;
            }

            // populate the results
            rw_entry->status =  rv ? HAL_RET_OK : HAL_RET_ERR;
            rw_entry->done = TRUE;

            // advance to next entry in the queue
            g_asic_rw_workq[qid].cindx++;
            if (g_asic_rw_workq[qid].cindx >= HAL_ASIC_RW_Q_SIZE) {
                g_asic_rw_workq[qid].cindx = 0;
            }
            g_asic_rw_workq[qid].nentries--;
            work_done = true;
        }

        // all queues scanned once, check if any work was found
        if (!work_done) {
            // didn't find any work, yield and give chance to other threads
            pthread_yield();
        }
    }
}

//------------------------------------------------------------------------------
// ASIC read/write thread's entry point
//------------------------------------------------------------------------------
void *
asic_rw_start (void *ctxt)
{
    HAL_THREAD_INIT();

    // announce asic-rw thread as ready
    g_asic_rw_ready_ = true;

    // keep polling the queue and serve the read/write requests
    asic_rw_loop();

    return NULL;
}

}    // namespace pd
}    // namespace hal

