//-----------------------------------------------------------------------------
// {C} Copyright 2019 Pensando Systems Inc. All rights reserved
//-----------------------------------------------------------------------------
#ifndef __MEM_HASH_TYPES_HPP__
#define __MEM_HASH_TYPES_HPP__

#include "include/sdk/base.hpp"
#include "include/sdk/table.hpp"
#include "lib/p4/p4_api.hpp"

#include "mem_hash.hpp"
#include "mem_hash_stats.hpp"
#include "mem_hash_txn.hpp"
#include "mem_hash_utils.hpp"

#define MEMHASH_MAX_SW_KEY_LEN 128
#define MEMHASH_MAX_SW_DATA_LEN 128
#define MEMHASH_MAX_HW_KEY_LEN 64
#define MEMHASH_MAX_HW_DATA_LEN 64

using sdk::table::sdk_table_factory_params_t;
using sdk::table::mem_hash_properties_t;
using sdk::table::mem_hash_txn;

namespace sdk {
namespace table {
namespace memhash {

typedef union mem_hash_handle_ {
    struct {
        uint32_t is_hint:1;
        uint32_t index:28;
        uint32_t hint:24;
        uint32_t valid:1;
        uint32_t spare:10;
    };
    uint64_t value;
} __attribute__((__packed__)) mem_hash_handle_t;

#define MEM_HASH_HANDLE_SET_HINT(_ctx, _hint) { \
        ((_ctx)->handle)->hint = (_hint); \
        ((_ctx)->handle)->is_hint = true; \
        ((_ctx)->handle)->valid = true; \
}
#define MEM_HASH_HANDLE_SET_INDEX(_ctx, _index) {\
        ((_ctx)->handle)->index = (_index); \
        ((_ctx)->handle)->valid = true; \
}

#define HINT_SLOT_IS_INVALID(_slot) \
        ((_slot) == mem_hash_api_context::hint_slot::HINT_SLOT_INVALID)
#define HINT_SLOT_IS_VALID(_slot) \
        ((_slot) != mem_hash_api_context::hint_slot::HINT_SLOT_INVALID)
#define HINT_SLOT_SET_INVALID(_slot) \
        ((_slot) = mem_hash_api_context::hint_slot::HINT_SLOT_INVALID)
#define HINT_SLOT_IS_MORE(_slot) \
        ((_slot) == mem_hash_api_context::hint_slot::HINT_SLOT_MORE)
#define HINT_SLOT_SET_MORE(_slot) \
        ((_slot) = mem_hash_api_context::hint_slot::HINT_SLOT_MORE)
#define HINT_SLOT_IS_MATCH(_ctx) \
        (HINT_SLOT_IS_FREE((_ctx)->hint_slot) &&\
         HINT_SLOT_IS_MORE((_ctx)->hint_slot))
#define HINT_IS_VALID(_hint) \
        ((_hint) != mem_hash_api_context::hint_index::HINT_INDEX_INVALID)
#define HINT_SET_INVALID(_hint) \
        ((_hint) = mem_hash_api_context::hint_index::HINT_INDEX_INVALID)

#define PRINT_API_CTX(_name, _ctx) {\
    MEMHASH_TRACE_DEBUG("%s: %s, [%s]", _name, (_ctx)->idstr(), (_ctx)->metastr()); \
}

class mem_hash_api_context {
public:
    enum match_type{
        MATCH_TYPE_NONE     = 0,
        MATCH_TYPE_EXM      = 1,
        MATCH_TYPE_HINT     = 2,
    };

    enum hint_index {
        // Hint index 0 is reserved
        HINT_INDEX_INVALID = 0,
    };

    enum hint_slot {
        // Slot 0 is invalid. NCC always generates from Slot 1-to-N.
        HINT_SLOT_INVALID  = 0,

        // Slot 1
        // ....
        // Slot N are all valid slots, auto-generated by NCC.

        // Slot 0xFF is reserved for MoreHints.
        HINT_SLOT_MORE  = 0xFF,
    };

private:
    static uint32_t numctx_;
    static mem_hash_api_context* alloc_();
public:
    // Operation
    sdk_table_api_op_t op;

    // Input params
    void *in_key;
    void *in_appdata;
    uint32_t in_action_id;
    bool in_hash_valid;
    uint32_t in_hash_32b;

    uint32_t sw_key_len;
    uint32_t sw_data_len;
    uint32_t sw_appdata_len;
    bytes2str_t key2str;
    bytes2str_t appdata2str;
    iterate_t itercb;
    void *cbdata; // Callback data for iteration

    // Derived fields from input
    uint32_t hash_msbits;

    // SW Key and Data
    bool sw_valid;
    uint8_t sw_key[MEMHASH_MAX_SW_KEY_LEN];
    uint8_t sw_data[MEMHASH_MAX_SW_DATA_LEN];
    uint8_t sw_appdata[MEMHASH_MAX_SW_DATA_LEN];

    // HW Key and Data
    uint32_t hw_key_len;
    uint32_t hw_data_len;
    uint8_t hw_key[MEMHASH_MAX_HW_KEY_LEN];
    uint8_t hw_data[MEMHASH_MAX_HW_DATA_LEN];

    // NOTE NOTE NOTE:
    // Some of the below fields are re-used by main table and hint table
    // DO NOT USE these to pass info between tables.
    uint8_t level;          // Chaining level
    uint8_t num_hints;
    uint8_t max_recircs;
    uint8_t table_id;
    uint32_t table_index;
    uint8_t hint_slot;
    uint32_t hint;
    bool more_hashs;
    bool write_pending;
    uint32_t match_type;
    void *bucket;
    char str[256];
    char str2[64];

    // Properties of this table
    mem_hash_properties_t *props;

    // Parent API Context: used for context nesting.
    // 1st level HintTable: pctx = MainTable context.
    // 2nd level HintTable: pctx = 1st level HintTable context.
    // and so on...
    mem_hash_api_context *pctx;

    // Handle to the entry
    mem_hash_handle_t *handle;

    // Table stats
    mem_hash_table_stats *table_stats;

    // API transaction
    mem_hash_txn *txn;

public:
    static mem_hash_api_context* factory(mem_hash_api_context *pctx);
    static mem_hash_api_context* factory(uint32_t op, sdk_table_api_params_t *params,
                                         mem_hash_properties_t *props,
                                         mem_hash_table_stats *table_stats,
                                         mem_hash_txn *txn);
    static void destroy(mem_hash_api_context* ctx);
    char* sw_data2str();
    void print_sw_data();
    void print_input();
    void print_handle();

    // Constructor
    mem_hash_api_context() {
        sw_key_len     = 0;
        sw_data_len    = 0;
        sw_appdata_len = 0;
        key2str        = NULL;
        appdata2str    = NULL;
        itercb         = NULL;
        cbdata         = NULL;
        hash_msbits    = 0;
        sw_valid       = false;
        hw_key_len     = 0;
        hw_data_len    = 0;
        level          = 0;
        num_hints      = 0;
        max_recircs    = 0;
        table_id       = 0;
        table_index    = 0;
        hint_slot      = 0;
        hint           = 0;
        more_hashs     = false;
        write_pending  = false;
        match_type     = 0;
        bucket         = NULL;
        pctx           = NULL;
        handle         = NULL;
        table_stats    = NULL;
        txn            = NULL;
    }

    // Destructor
    ~mem_hash_api_context() {
    }

    bool is_exact_match() {
        SDK_ASSERT(match_type != MATCH_TYPE_NONE);
        return match_type == MATCH_TYPE_EXM;
    }

    bool is_hint_match() {
        SDK_ASSERT(match_type != MATCH_TYPE_NONE);
        return match_type == MATCH_TYPE_HINT;
    }

    void set_exact_match() {
        match_type = MATCH_TYPE_EXM;
        return;
    }

    void set_hint_match() {
        match_type = MATCH_TYPE_HINT;
        return;
    }

    bool is_hint_valid() {
        return hint != HINT_INDEX_INVALID;
    }

    char* inputstr() {
        snprintf(str, sizeof(str),
                 "key:%p,data:%p,hash_valid:%d,hash_32b:%#x,cbdata:%p",
                 in_key, in_appdata, in_hash_valid, in_hash_32b, cbdata);
        return str;
    }

    // Debug string
    char* metastr() {
        snprintf(str, sizeof(str),
                 "id:%d,idx:%d,slot:%d,hint:%d,"
                 "more:%d,pending:%d,hash_msbits:%#x,match_type:%d",
                 table_id, table_index, hint_slot,
                 hint, more_hashs, write_pending, hash_msbits, match_type);
        return str;
    }

    bool is_main() {
        return (level == 0);
    }

    const char* idstr() {
        snprintf(str2, sizeof(str2), 
                 "%s%d-L%d", is_main() ? "M" : "H", table_index, level);
        return str2;
    }

    static uint32_t count() {
        return numctx_;
    }

    bool is_max_recircs() {
        return (level >= max_recircs);
    }

    bool is_reserve() {
        return (op == SDK_TABLE_API_RESERVE);
    }

    bool is_release() {
        return (op == SDK_TABLE_API_RELEASE);
    }

    bool is_handle_valid() {
        return handle->value != 0;
    }
};

} // namespace memhash
} // namespace table
} // namespace sdk

#endif // __MEM_HASH_TYPES_HPP__
