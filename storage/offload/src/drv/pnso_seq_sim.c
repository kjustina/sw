/*
 * {C} Copyright 2018 Pensando Systems Inc.
 * All rights reserved.
 *
 */
#include "osal.h"
#include "pnso_api.h"

#include "pnso_seq_ops.h"

static void *
__sim_setup_desc(uint32_t *pnso_qid, uint16_t *pnso_index,
		void *src_desc, size_t desc_size)
{
	return NULL;	/* EOPNOTSUPP */
}

static void
__sim_ring_db(uint32_t pnso_qid, uint16_t pnso_index)
{
	/* EOPNOTSUPP */
}

const struct sequencer_ops sim_seq_ops = {
	.setup_desc = __sim_setup_desc,
	.ring_db = __sim_ring_db,
};
