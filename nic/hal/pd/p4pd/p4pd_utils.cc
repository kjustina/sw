// {C} Copyright 2017 Pensando Systems Inc. All rights reserved

#include "boost/foreach.hpp"
#include "boost/optional.hpp"
#include "boost/property_tree/ptree.hpp"
#include "boost/property_tree/json_parser.hpp"
#include "nic/hal/pd/p4pd_api.hpp"
#include "nic/gen/include/p4pd_table.h"

#define P4PD_CALLOC  calloc
#define P4PD_FREE    free

// key strings used in table packing json file
#define JSON_KEY_TABLES             "tables"
#define JSON_KEY_TABLE_NAME         "name"
#define JSON_KEY_MATCH_TYPE         "match_type"
#define JSON_KEY_DIRECTION          "direction"
#define JSON_KEY_REGION             "region"
#define JSON_KEY_STAGE              "stage"
#define JSON_KEY_STAGE_TBL_ID       "stage_table_id"
#define JSON_KEY_NUM_ENTRIES        "num_entries"
#define JSON_KEY_TCAM               "tcam"
#define JSON_KEY_SRAM               "sram"
#define JSON_KEY_HBM                "hbm"
#define JSON_KEY_OVERFLOW           "overflow"
#define JSON_KEY_OVERFLOW_PARENT    "overflow_parent"
#define JSON_KEY_ENTRY_WIDTH        "entry_width"
#define JSON_KEY_ENTRY_WIDTH_BITS   "entry_width_bits"
#define JSON_KEY_ENTRY_START_INDEX  "entry_start_index"
#define JSON_KEY_ENTRY_END_INDEX    "entry_end_index"
#define JSON_KEY_TOP_LEFT_X         "layout.top_left.x"
#define JSON_KEY_TOP_LEFT_Y         "layout.top_left.y"
#define JSON_KEY_TOP_LEFT_BLOCK     "layout.top_left.block"
#define JSON_KEY_BTM_RIGHT_X        "layout.bottom_right.x"
#define JSON_KEY_BTM_RIGHT_Y        "layout.bottom_right.y"
#define JSON_KEY_BTM_RIGHT_BLOCK    "layout.bottom_right.block"
#define JSON_KEY_HASH_TYPE          "hash_type"
#define JSON_KEY_NUM_BUCKETS        "num_buckets"

#if 0
// TODO: we need declarations for these in common files
extern void p4pd_prep_p4tbl_sw_struct_sizes(void);
extern void p4pd_prep_p4tbl_names(void);
extern char p4pd_tbl_names[P4TBL_ID_TBLMAX][P4TBL_NAME_MAX_LEN];
extern uint16_t p4pd_tbl_swkey_size[P4TBL_ID_TBLMAX];
extern uint16_t p4pd_tbl_sw_action_data_size[P4TBL_ID_TBLMAX];
#endif

static p4pd_table_properties_t *_p4tbls;
namespace pt = boost::property_tree;

static uint16_t
p4pd_get_tableid_from_tablename (const char *tablename)
{
    for (int i = P4TBL_ID_TBLMIN; i < P4TBL_ID_TBLMAX; i++) {
        if (!strcmp(p4pd_tbl_names[i], tablename)) {
            return i;
        }
    }
    return -1;
}

static p4pd_table_dir_en
p4pd_get_table_direction (const char *direction)
{
    if (!strcmp(direction, "ingress")) {
        return(P4_GRESS_INGRESS);
    }
    if (!strcmp(direction, "egress")) {
        return(P4_GRESS_EGRESS);
    }
    return P4_GRESS_INVALID;
}

static p4pd_table_type_en
p4pd_get_table_type (const char *match_type)
{
    if (!strcmp(match_type, "hash")) {
        return(P4_TBL_TYPE_HASH);
    }
    if (!strcmp(match_type, "hash_tcam")) {
        return(P4_TBL_TYPE_HASHTCAM);
    }
    if (!strcmp(match_type, "tcam_sram")) {
        return(P4_TBL_TYPE_TCAM);
    }
    if (!strcmp(match_type, "indexed")) {
        return(P4_TBL_TYPE_INDEX);
    }
    if (!strcmp(match_type, "mpu")) {
        return(P4_TBL_TYPE_MPU);
    }
    return P4_TBL_TYPE_INVALID;
}

static p4pd_error_t
p4pd_tbl_packing_json_parse (p4pd_cfg_t *p4pd_cfg)
{
    pt::ptree                  json_pt;
    p4pd_table_properties_t    *tbl;
    std::string                full_path;
    int                        tableid, num_tables = P4TBL_ID_TBLMAX;
    char                       *cfg_path;

    // TODO: man, this logic shouldn't be in this lib ...
    cfg_path = std::getenv("HAL_CONFIG_PATH");
    if (cfg_path) {
         full_path =  std::string(cfg_path) + "/" + p4pd_cfg->table_map_cfg_file;
     } else {
         printf("Please specify HAL_CONFIG_PATH env. variable ... ");
         exit(0);
     }

    std::ifstream tbl_json(full_path.c_str());
    read_json(tbl_json, json_pt);
    boost::optional<pt::ptree&>table_pt =
        json_pt.get_child_optional(JSON_KEY_TABLES);
    if (!table_pt) {
        return P4PD_FAIL;
    }
    _p4tbls =
        (p4pd_table_properties_t *)P4PD_CALLOC(num_tables,
                                               sizeof(p4pd_table_properties_t));
    if (!_p4tbls) {
        return P4PD_FAIL;
    }

    // iterator over all p4 tables packing data and build book keeping data
    // structures used to read/write to device.
    BOOST_FOREACH(pt::ptree::value_type &p4_tbl, json_pt.get_child(JSON_KEY_TABLES)) {
        std::string tablename = p4_tbl.second.get<std::string>(JSON_KEY_TABLE_NAME);
        std::string match_type = p4_tbl.second.get<std::string>(JSON_KEY_MATCH_TYPE);
        std::string direction = p4_tbl.second.get<std::string>(JSON_KEY_DIRECTION); 
        std::string overflow  = p4_tbl.second.get<std::string>(JSON_KEY_OVERFLOW); 
        std::string overflow_parent  = p4_tbl.second.get<std::string>(JSON_KEY_OVERFLOW_PARENT); 

        tableid = p4pd_get_tableid_from_tablename(tablename.c_str());
        if (tableid == -1) {
            return P4PD_FAIL;
        }

        tbl = _p4tbls + tableid;
        tbl->key_struct_size = p4pd_tbl_swkey_size[tableid];
        tbl->actiondata_struct_size = p4pd_tbl_sw_action_data_size[tableid];

        if (strlen(overflow.c_str())) {
            tbl->has_oflow_table = true;
            tbl->oflow_table_id =
                p4pd_get_tableid_from_tablename(overflow.c_str());
        } else {
            tbl->has_oflow_table = false;
        }
        if (strlen(overflow_parent.c_str())) {
            tbl->is_oflow_table = true;
            tbl->oflow_parent_table_id =
                p4pd_get_tableid_from_tablename(overflow_parent.c_str());
        } else {
            tbl->is_oflow_table = false;
        }

        tbl->tablename = (char*)p4pd_tbl_names[tableid];
        tbl->tableid = tableid;

        tbl->table_type = p4pd_get_table_type(match_type.c_str());
        tbl->gress = p4pd_get_table_direction(direction.c_str());
        tbl->hash_type = p4_tbl.second.get<int>(JSON_KEY_HASH_TYPE); 
        tbl->stage = p4_tbl.second.get<int>(JSON_KEY_STAGE); 
        tbl->stage_tableid = p4_tbl.second.get<int>(JSON_KEY_STAGE_TBL_ID); 
        tbl->tabledepth = p4_tbl.second.get<int>(JSON_KEY_NUM_ENTRIES); 

        // memory units used by the table
        boost::optional<pt::ptree&>_tcam = p4_tbl.second.get_child_optional(JSON_KEY_TCAM);
        if (_tcam) {
            tbl->tcam_layout.entry_width = _tcam.get().get<int>(JSON_KEY_ENTRY_WIDTH);
            tbl->tcam_layout.entry_width_bits = _tcam.get().get<int>(JSON_KEY_ENTRY_WIDTH_BITS);
            tbl->tcam_layout.start_index = _tcam.get().get<int>(JSON_KEY_ENTRY_START_INDEX);
            tbl->tcam_layout.end_index = _tcam.get().get<int>(JSON_KEY_ENTRY_END_INDEX);
            tbl->tcam_layout.top_left_x = _tcam.get().get<int>(JSON_KEY_TOP_LEFT_X);
            tbl->tcam_layout.top_left_y = _tcam.get().get<int>(JSON_KEY_TOP_LEFT_Y);
            tbl->tcam_layout.top_left_block = _tcam.get().get<int>(JSON_KEY_TOP_LEFT_BLOCK);
            tbl->tcam_layout.btm_right_x = _tcam.get().get<int>(JSON_KEY_BTM_RIGHT_X);
            tbl->tcam_layout.btm_right_y = _tcam.get().get<int>(JSON_KEY_BTM_RIGHT_Y);
            tbl->tcam_layout.btm_right_block = _tcam.get().get<int>(JSON_KEY_BTM_RIGHT_BLOCK);
            tbl->tcam_layout.num_buckets = _tcam.get().get<int>(JSON_KEY_NUM_BUCKETS);
        }
        boost::optional<pt::ptree&>_sram = p4_tbl.second.get_child_optional(JSON_KEY_SRAM);
        if (_sram) {
            tbl->sram_layout.entry_width = _sram.get().get<int>(JSON_KEY_ENTRY_WIDTH);
            tbl->sram_layout.entry_width_bits = _sram.get().get<int>(JSON_KEY_ENTRY_WIDTH_BITS);
            tbl->sram_layout.start_index = _sram.get().get<int>(JSON_KEY_ENTRY_START_INDEX);
            tbl->sram_layout.end_index = _sram.get().get<int>(JSON_KEY_ENTRY_END_INDEX);
            tbl->sram_layout.top_left_x = _sram.get().get<int>(JSON_KEY_TOP_LEFT_X);
            tbl->sram_layout.top_left_y = _sram.get().get<int>(JSON_KEY_TOP_LEFT_Y);
            tbl->sram_layout.top_left_block = _sram.get().get<int>(JSON_KEY_TOP_LEFT_BLOCK);
            tbl->sram_layout.btm_right_x = _sram.get().get<int>(JSON_KEY_BTM_RIGHT_X);
            tbl->sram_layout.btm_right_y = _sram.get().get<int>(JSON_KEY_BTM_RIGHT_Y);
            tbl->sram_layout.btm_right_block = _sram.get().get<int>(JSON_KEY_BTM_RIGHT_BLOCK);
            tbl->sram_layout.num_buckets = _sram.get().get<int>(JSON_KEY_NUM_BUCKETS);
        }
        boost::optional<pt::ptree&>_hbm = p4_tbl.second.get_child_optional(JSON_KEY_HBM);
        if (_hbm) {
            tbl->table_location = P4_TBL_LOCATION_HBM;
            tbl->hbm_layout.entry_width = _hbm.get().get<int>(JSON_KEY_ENTRY_WIDTH);
            tbl->hbm_layout.start_index = _hbm.get().get<int>(JSON_KEY_ENTRY_START_INDEX);
            tbl->hbm_layout.end_index = _hbm.get().get<int>(JSON_KEY_ENTRY_END_INDEX);
        } else {
            tbl->table_location = P4_TBL_LOCATION_PIPE;
        }
    }
    return P4PD_SUCCESS;
}

//-----------------------------------------------------------------------------
// cleanup function for p4pd meta
//-----------------------------------------------------------------------------
void
p4pd_cleanup (void)
{
    P4PD_FREE(_p4tbls);
}

//-----------------------------------------------------------------------------
// do common initialization
//-----------------------------------------------------------------------------
p4pd_error_t
p4pd_init (p4pd_cfg_t *p4pd_cfg)
{
    p4pd_prep_p4tbl_names();
    p4pd_prep_p4tbl_sw_struct_sizes();
    if (p4pd_tbl_packing_json_parse(p4pd_cfg) != P4PD_SUCCESS) {
        p4pd_cleanup();
        return P4PD_FAIL;
    }
    return P4PD_SUCCESS;
}

//-----------------------------------------------------------------------------
// P4PD API that uses tableID to return table properties that app
// layer can use to construct, initialize P4 tables in local memory.
//
// Arguments: 
//
//  IN  : uint32_t          tableid    : Table Id that identifies
//                                       P4 table. This id is obtained
//                                       from p4pd_table_id_enum.
//  OUT : p4pd_table_ctx_t *table_ctx  : Returns a structure of data
//                                       that contains table properties. 
// Return Value: 
//  P4PD_SUCCESS                       : Table properties copied into tbl_ctx
//                                       Memory for tbl_ctx is provided by
//                                       API caller.
//
//  P4PD_FAIL                          : If tableid is not valid
//-----------------------------------------------------------------------------
p4pd_error_t
p4pd_table_properties_get (uint32_t tableid, p4pd_table_properties_t *tbl_ctx)
{
    if (tableid >= P4TBL_ID_TBLMAX || !_p4tbls) {
        return P4PD_FAIL;
    }
    memcpy(tbl_ctx, _p4tbls + tableid, sizeof(p4pd_table_properties_t));
    return P4PD_SUCCESS;
}
