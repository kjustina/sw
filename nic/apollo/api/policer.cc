//
// {C} Copyright 2019 Pensando Systems Inc. All rights reserved
//
//----------------------------------------------------------------------------
///
/// \file
/// policer handling
///
//----------------------------------------------------------------------------

#include "nic/sdk/include/sdk/base.hpp"
#include "nic/apollo/core/trace.hpp"
#include "nic/apollo/core/mem.hpp"
#include "nic/apollo/framework/api_base.hpp"
#include "nic/apollo/framework/api_engine.hpp"
#include "nic/apollo/framework/api_params.hpp"
#include "nic/apollo/api/policer.hpp"
#include "nic/apollo/api/pds_state.hpp"

namespace api {

typedef struct policer_update_ctxt_s {
    policer_entry *policer;
    api_obj_ctxt_t *obj_ctxt;
    uint64_t upd_bmap;
} __PACK__ policer_update_ctxt_t;

policer_entry::policer_entry() {
    ht_ctxt_.reset();
    impl_ = NULL;
}

policer_entry *
policer_entry::factory(pds_policer_spec_t *spec) {
    policer_entry *policer;

    ///< create policer with defaults, if any
    policer = policer_db()->alloc();
    if (policer) {
        new (policer) policer_entry();
        policer->impl_ = impl_base::factory(impl::IMPL_OBJ_ID_POLICER, spec);
        if (policer->impl_ == NULL) {
            policer_entry::destroy(policer);
            return NULL;
        }
    }
    return policer;
}

policer_entry::~policer_entry() {
}

void
policer_entry::destroy(policer_entry *policer) {
    policer->nuke_resources_();
    if (policer->impl_) {
        impl_base::destroy(impl::IMPL_OBJ_ID_POLICER, policer->impl_);
    }
    policer->~policer_entry();
    policer_db()->free(policer);
}

api_base *
policer_entry::clone(api_ctxt_t *api_ctxt) {
    policer_entry *cloned_policer;

    cloned_policer = policer_db()->alloc();
    if (cloned_policer) {
        new (cloned_policer) policer_entry();
        if (cloned_policer->init_config(api_ctxt) != SDK_RET_OK) {
            goto error;
        }
        cloned_policer->impl_ = impl_->clone();
        if (unlikely(cloned_policer->impl_ == NULL)) {
            PDS_TRACE_ERR("Failed to clone policer %s impl", key2str().c_str());
            goto error;
        }
    }
    return cloned_policer;

error:

    cloned_policer->~policer_entry();
    policer_db()->free(cloned_policer);
    return NULL;
}

sdk_ret_t
policer_entry::free(policer_entry *policer) {
    if (policer->impl_) {
        impl_base::free(impl::IMPL_OBJ_ID_POLICER, policer->impl_);
    }
    policer->~policer_entry();
    policer_db()->free(policer);
    return SDK_RET_OK;
}

sdk_ret_t
policer_entry::reserve_resources(api_base *orig_obj, api_obj_ctxt_t *obj_ctxt) {
    return impl_->reserve_resources(this, orig_obj, obj_ctxt);
}

sdk_ret_t
policer_entry::release_resources(void) {
    return impl_->release_resources(this);
}

sdk_ret_t
policer_entry::nuke_resources_(void) {
    return impl_->nuke_resources(this);
}

sdk_ret_t
policer_entry::init_config(api_ctxt_t *api_ctxt) {
    pds_policer_spec_t *spec = &api_ctxt->api_params->policer_spec;

    memcpy(&this->key_, &spec->key, sizeof(key_));
    dir_ = spec->dir;
    return SDK_RET_OK;
}

sdk_ret_t
policer_entry::compute_update(api_obj_ctxt_t *obj_ctxt) {
    pds_policer_spec_t *spec = &obj_ctxt->api_params->policer_spec;

    if (dir_ != spec->dir) {
        PDS_TRACE_ERR("Attempt to modify immutable attr \"direction\" "
                      "from %u to %u on policer %s", dir_, spec->dir,
                       key2str().c_str());
        return SDK_RET_INVALID_ARG;
    }
    return SDK_RET_OK;
}

sdk_ret_t
policer_entry::activate_config(pds_epoch_t epoch, api_op_t api_op,
                               api_base *orig_obj, api_obj_ctxt_t *obj_ctxt) {
    return impl_->activate_hw(this, orig_obj, epoch, api_op, obj_ctxt);
}

sdk_ret_t
policer_entry::reprogram_config(api_obj_ctxt_t *obj_ctxt) {
    return SDK_RET_ERR;
}

sdk_ret_t
policer_entry::reactivate_config(pds_epoch_t epoch, api_obj_ctxt_t *obj_ctxt) {
    return sdk::SDK_RET_INVALID_OP;
}

void
policer_entry::fill_spec_(pds_policer_spec_t *spec) {
    memcpy(&spec->key, &key_, sizeof(pds_obj_key_t));
    spec->dir = dir_;
}

sdk_ret_t
policer_entry::read(pds_policer_info_t *info) {
    fill_spec_(&info->spec);
    return impl_->read_hw(this, (impl::obj_key_t *)(&info->spec.key),
                          (impl::obj_info_t *)info);
}

sdk_ret_t
policer_entry::add_to_db(void) {
    return policer_db()->insert(this);
}

sdk_ret_t
policer_entry::del_from_db(void) {
    if (policer_db()->remove(this)) {
        return SDK_RET_OK;
    }
    return SDK_RET_ENTRY_NOT_FOUND;
}

sdk_ret_t
policer_entry::update_db(api_base *orig_obj, api_obj_ctxt_t *obj_ctxt) {
    if (policer_db()->remove((policer_entry *)orig_obj)) {
        return policer_db()->insert(this);
    }
    return SDK_RET_ENTRY_NOT_FOUND;
}

sdk_ret_t
policer_entry::delay_delete(void) {
    return delay_delete_to_slab(PDS_SLAB_ID_POLICER, this);
}

#if 0
static bool
vnic_upd_walk_cb_ (void *api_obj, void *ctxt)
{
    vnic_entry *vnic;
    policer_update_ctxt_t *upd_ctxt = (policer_update_ctxt_t *)ctxt;

    vnic = (vnic_entry *)api_framework_obj((api_base *)api_obj);
    if ((vnic->policer(PDS_POLICER_DIR_INGRESS) == upd_ctxt->policer->key()) ||
        (vnic->policer(PDS_POLICER_DIR_EGRESS) == upd_ctxt->policer->key())) {
        api_obj_add_to_deps(upd_ctxt->obj_ctxt->api_op,
                            OBJ_ID_POLICER, upd_ctxt->policer,
                            OBJ_ID_VNIC, (api_base *)api_obj,
                            upd_ctxt->upd_bmap);
    }
    return false;
}
#endif

sdk_ret_t
policer_entry::add_deps(api_obj_ctxt_t *obj_ctxt) {
#if 0
    policer_update_ctxt_t upd_ctxt = { 0 };

    upd_ctxt.policer = this;
    upd_ctxt.obj_ctxt = obj_ctxt;
    upd_ctxt.upd_bmap = PDS_VNIC_UPD_POLICER;
    return vnic_db()->walk(vnic_upd_walk_cb_, &upd_ctxt);
#endif
    return SDK_RET_OK;
}


}    // namespace api
