/*
 * {C} Copyright 2018 Pensando Systems Inc.
 * All rights reserved.
 *
 */
#ifdef __FreeBSD__
#include <linux/netdevice.h>
#else
#include <netdevice.h>
#include <net.h>
#include <kernel.h>
#endif

#include "sonic_dev.h"
#include "sonic_lif.h"
#include "sonic_api_int.h"

#include "osal.h"
#include "pnso_api.h"

#include "pnso_utils.h"
#include "pnso_chain_params.h"
#include "pnso_seq_ops.h"
#include "pnso_cpdc.h"
#include "pnso_init.h"

/**
 * TODO-seq:
 *	- although chaining can be done generically for compression
 *	related chains, focus for now is comp+hash bring-up.
 *	- revisit layer violations
 *	- storage_seq_p4pd. vs utils.h
 *	- use cip_block_size to set  ccp_pad_boundary_shift
 *
 */
#ifdef NDEBUG
#define PPRINT_SEQUENCER_DESC(d)
#define PPRINT_SEQUENCER_INFO(sqi)
#define PPRINT_CPDC_CHAIN_PARAMS(cp)
#define PPRINT_CRYPTO_CHAIN_PARAMS(cp)
#else
#define PPRINT_SEQUENCER_DESC(d)	pprint_seq_desc(d)
#define PPRINT_SEQUENCER_INFO(sqi)					\
	do {								\
		OSAL_LOG_DEBUG("%.*s", 30, "=========================================");\
		pprint_seq_info(sqi);					\
	} while (0)
#define PPRINT_CPDC_CHAIN_PARAMS(cp)					\
	do {								\
		OSAL_LOG_DEBUG("%.*s", 30, "=========================================");\
		pprint_cpdc_chain_params(cp);				\
	} while (0)
#define PPRINT_CRYPTO_CHAIN_PARAMS(cp)					\
	do {								\
		OSAL_LOG_DEBUG("%.*s", 30, "=========================================");\
		pprint_crypto_chain_params(cp);				\
	} while (0)
#endif

static void __attribute__((unused))
pprint_seq_desc(const struct sequencer_desc *desc)
{
	if (!desc)
		return;

	OSAL_LOG_DEBUG("%30s: 0x" PRIx64, "seq_desc", (uint64_t) desc);
	OSAL_LOG_DEBUG("%30s: 0x" PRIx64, "seq_desc_pa",
			osal_virt_to_phy((void *) desc));

	OSAL_LOG_DEBUG("%30s: 0x" PRIx64, "sd_desc_addr", desc->sd_desc_addr);
	OSAL_LOG_DEBUG("%30s: 0x" PRIx64, "sd_pndx_addr", desc->sd_pndx_addr);
	OSAL_LOG_DEBUG("%30s: 0x" PRIx64, "sd_pndx_shadow_addr",
			desc->sd_pndx_shadow_addr);
	OSAL_LOG_DEBUG("%30s: 0x" PRIx64, "sd_ring_addr", desc->sd_ring_addr);

	OSAL_LOG_DEBUG("%30s: %d", "sd_desc_size", desc->sd_desc_size);
	OSAL_LOG_DEBUG("%30s: %d", "sd_pndx_size", desc->sd_pndx_size);
	OSAL_LOG_DEBUG("%30s: %d", "sd_ring_size", desc->sd_ring_size);
	OSAL_LOG_DEBUG("%30s: %d", "sd_batch_mode", desc->sd_batch_mode);
	OSAL_LOG_DEBUG("%30s: %d", "sd_batch_size", desc->sd_batch_size);
}

static void __attribute__((unused))
pprint_seq_info(const struct sequencer_info *seq_info)
{
	if (!seq_info)
		return;

	OSAL_LOG_DEBUG("%30s: %d", "sqi_ring_id", seq_info->sqi_ring_id);
	OSAL_LOG_DEBUG("%30s: %d", "sqi_qtype", seq_info->sqi_qtype);
	OSAL_LOG_DEBUG("%30s: %d", "sqi_status_qtype", seq_info->sqi_status_qtype);
	OSAL_LOG_DEBUG("%30s: %d", "sqi_index", seq_info->sqi_index);
	OSAL_LOG_DEBUG("%30s: %d", "sqi_batch_mode", seq_info->sqi_batch_mode);
	OSAL_LOG_DEBUG("%30s: %d", "sqi_batch_size", seq_info->sqi_batch_size);
	OSAL_LOG_DEBUG("%30s: 0x" PRIx64, "sqi_sqi_desc",
			(uint64_t) seq_info->sqi_desc);
	OSAL_LOG_DEBUG("%30s: 0x" PRIx64, "sqi_status_desc",
			(uint64_t) seq_info->sqi_status_desc);
}

static void __attribute__((unused))
pprint_cpdc_chain_params(const struct cpdc_chain_params *chain_params)
{
	const struct sequencer_spec *spec;
	const struct ring_spec *ring_spec;
	const struct cpdc_chain_params_command *cmd;

	if (!chain_params)
		return;

	OSAL_LOG_DEBUG("%30s: 0x" PRIx64, "cpdc_chain_params",
			(uint64_t) chain_params);

	spec = &chain_params->ccp_seq_spec;
	OSAL_LOG_DEBUG("%30s: 0x" PRIx64, "sequencer_spec", (uint64_t) spec);
	OSAL_LOG_DEBUG("%30s: 0x" PRIx64, "sqs_seq_q",
			(uint64_t)spec->sqs_seq_q);
	OSAL_LOG_DEBUG("%30s: 0x" PRIx64, "sqs_seq_status_q",
			(uint64_t)spec->sqs_seq_status_q);
	OSAL_LOG_DEBUG("%30s: 0x" PRIx64, "sqs_seq_next_q",
			spec->sqs_seq_next_q);
	OSAL_LOG_DEBUG("%30s: 0x" PRIx64, "sqs_seq_next_status_q",
			spec->sqs_seq_next_status_q);
	OSAL_LOG_DEBUG("%30s: 0x" PRIx64, "sqs_ret_doorbell_addr",
			spec->sqs_ret_doorbell_addr);
	OSAL_LOG_DEBUG("%30s: 0x" PRIx64, "sqs_ret_doorbell_data",
			spec->sqs_ret_doorbell_data);
	OSAL_LOG_DEBUG("%30s: %d", "sqs_ret_seq_status_index",
			spec->sqs_ret_seq_status_index);

	ring_spec = &chain_params->ccp_ring_spec;
	OSAL_LOG_DEBUG("%30s: 0x" PRIx64, "ring_spec", (uint64_t) ring_spec);
	OSAL_LOG_DEBUG("%30s: 0x" PRIx64, "rs_ring_addr",
			ring_spec->rs_ring_addr);
	OSAL_LOG_DEBUG("%30s: 0x" PRIx64, "rs_pndx_addr",
			ring_spec->rs_pndx_addr);
	OSAL_LOG_DEBUG("%30s: 0x" PRIx64, "rs_pndx_shadow_addr",
			ring_spec->rs_pndx_shadow_addr);
	OSAL_LOG_DEBUG("%30s: 0x" PRIx64, "rs_desc_addr",
			ring_spec->rs_desc_addr);
	OSAL_LOG_DEBUG("%30s: %d", "rs_desc_size",
			ring_spec->rs_desc_size);
	OSAL_LOG_DEBUG("%30s: %d", "rs_pndx_size",
			ring_spec->rs_pndx_size);
	OSAL_LOG_DEBUG("%30s: %d", "rs_ring_size",
			ring_spec->rs_ring_size);
	OSAL_LOG_DEBUG("%30s: %d", "rs_num_descs",
			ring_spec->rs_num_descs);

	OSAL_LOG_DEBUG("%30s: 0x" PRIx64, "ccp_status_addr_0",
			chain_params->ccp_status_addr_0);
	OSAL_LOG_DEBUG("%30s: 0x" PRIx64, "ccp_status_addr_1",
			chain_params->ccp_status_addr_1);
	OSAL_LOG_DEBUG("%30s: 0x" PRIx64, "ccp_comp_buf_addr",
			chain_params->ccp_comp_buf_addr);
	OSAL_LOG_DEBUG("%30s: 0x" PRIx64, "ccp_alt_buf_addr",
			chain_params->ccp_alt_buf_addr);

	OSAL_LOG_DEBUG("%30s: 0x" PRIx64, "ccp_aol_src_vec_addr",
			chain_params->ccp_aol_src_vec_addr);
	OSAL_LOG_DEBUG("%30s: 0x" PRIx64, "ccp_aol_dst_vec_addr",
			chain_params->ccp_aol_dst_vec_addr);
	OSAL_LOG_DEBUG("%30s: 0x" PRIx64, "ccp_sgl_vec_addr",
			chain_params->ccp_sgl_vec_addr);
	OSAL_LOG_DEBUG("%30s: 0x" PRIx64, "ccp_pad_buf_addr",
			chain_params->ccp_pad_buf_addr);

	OSAL_LOG_DEBUG("%30s: 0x" PRIx64, "ccp_intr_addr",
			chain_params->ccp_intr_addr);
	OSAL_LOG_DEBUG("%30s: %d", "ccp_intr_data",
			chain_params->ccp_intr_data);
	OSAL_LOG_DEBUG("%30s: %d", "ccp_status_len",
			chain_params->ccp_status_len);
	OSAL_LOG_DEBUG("%30s: %d", "ccp_data_len",
			chain_params->ccp_data_len);

	OSAL_LOG_DEBUG("%30s: %d", "ccp_status_offset_0",
			chain_params->ccp_status_offset_0);
	OSAL_LOG_DEBUG("%30s: %d", "ccp_pad_boundary_shift",
			chain_params->ccp_pad_boundary_shift);

	cmd = &chain_params->ccp_cmd;
	OSAL_LOG_DEBUG("%30s: %d", "ccpc_data_len_from_desc",
			cmd->ccpc_data_len_from_desc);
	OSAL_LOG_DEBUG("%30s: %d", "ccpc_status_dma_en",
			cmd->ccpc_status_dma_en);
	OSAL_LOG_DEBUG("%30s: %d", "ccpc_next_doorbell_en",
			cmd->ccpc_next_doorbell_en);
	OSAL_LOG_DEBUG("%30s: %d", "ccpc_intr_en",
			cmd->ccpc_intr_en);
	OSAL_LOG_DEBUG("%30s: %d", "ccpc_next_db_action_ring_push",
			cmd->ccpc_next_db_action_ring_push);
	OSAL_LOG_DEBUG("%30s: %d", "ccpc_stop_chain_on_error",
			cmd->ccpc_stop_chain_on_error);
	OSAL_LOG_DEBUG("%30s: %d", "ccpc_chain_alt_desc_on_error",
			cmd->ccpc_chain_alt_desc_on_error);
	OSAL_LOG_DEBUG("%30s: %d", "ccpc_aol_pad_en",
			cmd->ccpc_aol_pad_en);
	OSAL_LOG_DEBUG("%30s: %d", "ccpc_sgl_pad_en",
			cmd->ccpc_sgl_pad_en);
	OSAL_LOG_DEBUG("%30s: %d", "ccpc_sgl_sparse_format_en",
			cmd->ccpc_sgl_sparse_format_en);
	OSAL_LOG_DEBUG("%30s: %d", "ccpc_sgl_pdma_en",
			cmd->ccpc_sgl_pdma_en);
	OSAL_LOG_DEBUG("%30s: %d", "ccpc_sgl_pdma_pad_only",
			cmd->ccpc_sgl_pdma_pad_only);
	OSAL_LOG_DEBUG("%30s: %d", "ccpc_sgl_pdma_alt_src_on_error",
			cmd->ccpc_sgl_pdma_alt_src_on_error);
	OSAL_LOG_DEBUG("%30s: %d", "ccpc_desc_vec_push_en",
			cmd->ccpc_desc_vec_push_en);
}

static void __attribute__((unused))
pprint_crypto_chain_params(const struct crypto_chain_params *chain_params)
{
	const struct sequencer_spec *spec;
	const struct ring_spec *ring_spec;
	const struct crypto_chain_params_command *cmd;

	if (!chain_params)
		return;

	OSAL_LOG_DEBUG("%30s: 0x" PRIx64, "crypto_chain_params",
			(uint64_t) chain_params);

	spec = &chain_params->ccp_seq_spec;
	OSAL_LOG_DEBUG("%30s: 0x" PRIx64, "sequencer_spec", (uint64_t) spec);
	OSAL_LOG_DEBUG("%30s: 0x" PRIx64, "sqs_seq_q",
			(uint64_t)spec->sqs_seq_q);
	OSAL_LOG_DEBUG("%30s: 0x" PRIx64, "sqs_seq_status_q",
			(uint64_t)spec->sqs_seq_status_q);
	OSAL_LOG_DEBUG("%30s: 0x" PRIx64, "sqs_seq_next_q",
			spec->sqs_seq_next_q);
	OSAL_LOG_DEBUG("%30s: 0x" PRIx64, "sqs_seq_next_status_q",
			spec->sqs_seq_next_status_q);
	OSAL_LOG_DEBUG("%30s: 0x" PRIx64, "sqs_ret_doorbell_addr",
			spec->sqs_ret_doorbell_addr);
	OSAL_LOG_DEBUG("%30s: 0x" PRIx64, "sqs_ret_doorbell_data",
			spec->sqs_ret_doorbell_data);
	OSAL_LOG_DEBUG("%30s: %d", "sqs_ret_seq_status_index",
			spec->sqs_ret_seq_status_index);

	ring_spec = &chain_params->ccp_ring_spec;
	OSAL_LOG_DEBUG("%30s: 0x" PRIx64, "ring_spec", (uint64_t) ring_spec);
	OSAL_LOG_DEBUG("%30s: 0x" PRIx64, "rs_ring_addr",
			ring_spec->rs_ring_addr);
	OSAL_LOG_DEBUG("%30s: 0x" PRIx64, "rs_pndx_addr",
			ring_spec->rs_pndx_addr);
	OSAL_LOG_DEBUG("%30s: 0x" PRIx64, "rs_pndx_shadow_addr",
			ring_spec->rs_pndx_shadow_addr);
	OSAL_LOG_DEBUG("%30s: 0x" PRIx64, "rs_desc_addr",
			ring_spec->rs_desc_addr);
	OSAL_LOG_DEBUG("%30s: %d", "rs_desc_size",
			ring_spec->rs_desc_size);
	OSAL_LOG_DEBUG("%30s: %d", "rs_pndx_size",
			ring_spec->rs_pndx_size);
	OSAL_LOG_DEBUG("%30s: %d", "rs_ring_size",
			ring_spec->rs_ring_size);
	OSAL_LOG_DEBUG("%30s: %d", "rs_num_descs",
			ring_spec->rs_num_descs);

	OSAL_LOG_DEBUG("%30s: 0x" PRIx64, "ccp_status_addr_0",
			chain_params->ccp_status_addr_0);
	OSAL_LOG_DEBUG("%30s: 0x" PRIx64, "ccp_status_addr_1",
			chain_params->ccp_status_addr_1);
	OSAL_LOG_DEBUG("%30s: 0x" PRIx64, "ccp_crypto_buf_addr",
			chain_params->ccp_crypto_buf_addr);
	OSAL_LOG_DEBUG("%30s: 0x" PRIx64, "ccp_comp_sgl_src_addr",
			chain_params->ccp_comp_sgl_src_addr);
	OSAL_LOG_DEBUG("%30s: 0x" PRIx64, "ccp_sgl_pdma_dst_addr",
			chain_params->ccp_sgl_pdma_dst_addr);

	OSAL_LOG_DEBUG("%30s: 0x" PRIx64, "ccp_intr_addr",
			chain_params->ccp_intr_addr);
	OSAL_LOG_DEBUG("%30s: %d", "ccp_intr_data",
			chain_params->ccp_intr_data);

	OSAL_LOG_DEBUG("%30s: %d", "ccp_status_offset_0",
			chain_params->ccp_status_offset_0);
	OSAL_LOG_DEBUG("%30s: %d", "ccp_status_len",
			chain_params->ccp_status_len);
	OSAL_LOG_DEBUG("%30s: %d", "ccp_blk_boundary_shift",
			chain_params->ccp_blk_boundary_shift);
	OSAL_LOG_DEBUG("%30s: %d", "ccp_data_len",
			chain_params->ccp_data_len);

	cmd = &chain_params->ccp_cmd;
	OSAL_LOG_DEBUG("%30s: %d", "ccpc_status_dma_en",
			cmd->ccpc_status_dma_en);
	OSAL_LOG_DEBUG("%30s: %d", "ccpc_next_doorbell_en",
			cmd->ccpc_next_doorbell_en);
	OSAL_LOG_DEBUG("%30s: %d", "ccpc_intr_en",
			cmd->ccpc_intr_en);
	OSAL_LOG_DEBUG("%30s: %d", "ccpc_next_db_action_ring_push",
			cmd->ccpc_next_db_action_ring_push);
	OSAL_LOG_DEBUG("%30s: %d", "ccpc_stop_chain_on_error",
			cmd->ccpc_stop_chain_on_error);
	OSAL_LOG_DEBUG("%30s: %d", "ccpc_comp_len_update_en",
			cmd->ccpc_comp_len_update_en);
	OSAL_LOG_DEBUG("%30s: %d", "ccpc_comp_sgl_src_en",
			cmd->ccpc_comp_sgl_src_en);
	OSAL_LOG_DEBUG("%30s: %d", "ccpc_comp_sgl_src_vec_en",
			cmd->ccpc_comp_sgl_src_vec_en);
	OSAL_LOG_DEBUG("%30s: %d", "ccpc_sgl_sparse_format_en",
			cmd->ccpc_sgl_sparse_format_en);
	OSAL_LOG_DEBUG("%30s: %d", "ccpc_sgl_pdma_en",
			cmd->ccpc_sgl_pdma_en);
	OSAL_LOG_DEBUG("%30s: %d", "ccpc_sgl_pdma_len_from_desc",
			cmd->ccpc_sgl_pdma_len_from_desc);
	OSAL_LOG_DEBUG("%30s: %d", "ccpc_desc_vec_push_en",
			cmd->ccpc_desc_vec_push_en);
}

static void
__write_bit_(uint8_t *p, unsigned int bit_off, bool val)
{
	unsigned int start_byte = bit_off >> 3;
	uint8_t mask = 1 << (7 - (bit_off & 7));

	if (val)
		p[start_byte] |= mask;
	else
		p[start_byte] &= ~mask;
}

static void
write_bit_fields(void *ptr, unsigned int start_bit_offset,
		unsigned int size_in_bits, uint64_t value)
{
	uint8_t *p = (uint8_t *)ptr;
	int bit_no;
	int off;

	for (off = 0, bit_no = (size_in_bits - 1);
			bit_no >= 0; bit_no--, off++) {
		__write_bit_(p, start_bit_offset + off,
				value & (1ull << bit_no));
	}
}


static struct queue *
get_seq_q(const struct service_info *svc_info, bool status_q)
{
	struct queue *q = NULL;
	struct per_core_resource *pc_res;

	/* TODO-seq: remove using hard-coded 0th status queue */
	pc_res = svc_info->si_pc_res;

	switch (svc_info->si_type) {
	case PNSO_SVC_TYPE_ENCRYPT:
		q = status_q ? &pc_res->crypto_seq_status_qs[0] :
			&pc_res->crypto_enc_seq_q;
		break;
	case PNSO_SVC_TYPE_DECRYPT:
		q = status_q ? &pc_res->crypto_seq_status_qs[0] :
			&pc_res->crypto_dec_seq_q;
		break;
	case PNSO_SVC_TYPE_COMPRESS:
	case PNSO_SVC_TYPE_HASH:
	case PNSO_SVC_TYPE_CHKSUM:
		q = status_q ? &pc_res->cpdc_seq_status_qs[0] :
			&pc_res->cp_seq_q;
		break;
	case PNSO_SVC_TYPE_DECOMPRESS:
		q = status_q ? &pc_res->cpdc_seq_status_qs[0] :
			&pc_res->dc_seq_q;
		break;
	case PNSO_SVC_TYPE_DECOMPACT:
	default:
		OSAL_ASSERT(0);
		break;
	}

	return q;
}

static void
fill_cpdc_seq_status_desc(struct cpdc_chain_params *chain_params,
		uint8_t *seq_status_desc)
{
	struct next_db_spec *next_db_spec;
	struct ring_spec *ring_spec;
	struct cpdc_chain_params_command *cmd;

	ring_spec = &chain_params->ccp_ring_spec;
	next_db_spec = &chain_params->ccp_next_db_spec;
	cmd = &chain_params->ccp_cmd;

	memset(seq_status_desc, 0, SONIC_SEQ_STATUS_Q_DESC_SIZE);
	// desc bytes 0-63
	if (cmd->ccpc_next_db_action_ring_push) {
		write_bit_fields(seq_status_desc, 0, 64,
				ring_spec->rs_ring_addr);
		write_bit_fields(seq_status_desc, 64, 64,
				ring_spec->rs_desc_addr);
		write_bit_fields(seq_status_desc, 128, 34,
				ring_spec->rs_pndx_addr);
		write_bit_fields(seq_status_desc, 162, 34,
				ring_spec->rs_pndx_shadow_addr);
		write_bit_fields(seq_status_desc, 196, 4,
				ring_spec->rs_desc_size);
		write_bit_fields(seq_status_desc, 200, 3,
				ring_spec->rs_pndx_size);
		write_bit_fields(seq_status_desc, 203, 5,
				ring_spec->rs_ring_size);
		write_bit_fields(seq_status_desc, 208, 10,
				ring_spec->rs_num_descs);
	} else {
		write_bit_fields(seq_status_desc, 0, 64,
				next_db_spec->nds_addr);
		write_bit_fields(seq_status_desc, 64, 64,
				next_db_spec->nds_data);
	}

	write_bit_fields(seq_status_desc, 218, 64,
			chain_params->ccp_status_addr_0);
	write_bit_fields(seq_status_desc, 282, 64,
			chain_params->ccp_status_addr_1);
	write_bit_fields(seq_status_desc, 346, 64,
			chain_params->ccp_intr_addr);
	write_bit_fields(seq_status_desc, 410, 32,
			chain_params->ccp_intr_data);
	write_bit_fields(seq_status_desc, 442, 16,
			chain_params->ccp_status_len);
	write_bit_fields(seq_status_desc, 458, 7,
			chain_params->ccp_status_offset_0);
	write_bit_fields(seq_status_desc, 465, 1,
			cmd->ccpc_status_dma_en);
	write_bit_fields(seq_status_desc, 466, 1,
			cmd->ccpc_next_doorbell_en);
	write_bit_fields(seq_status_desc, 467, 1,
			cmd->ccpc_intr_en);
	write_bit_fields(seq_status_desc, 468, 1,
			cmd->ccpc_next_db_action_ring_push);

	// desc bytes 64-127
	write_bit_fields(seq_status_desc, 512 + 0, 64, 0);
	write_bit_fields(seq_status_desc, 512 + 64, 64,
			chain_params->ccp_comp_buf_addr);
	write_bit_fields(seq_status_desc, 512 + 128, 64,
			chain_params->ccp_aol_src_vec_addr);
	write_bit_fields(seq_status_desc, 512 + 192, 64,
			chain_params->ccp_aol_dst_vec_addr);
	write_bit_fields(seq_status_desc, 512 + 256, 64,
			chain_params->ccp_sgl_vec_addr);
	write_bit_fields(seq_status_desc, 512 + 320, 64,
			chain_params->ccp_pad_buf_addr);
	write_bit_fields(seq_status_desc, 512 + 384, 64,
			chain_params->ccp_alt_buf_addr);
	write_bit_fields(seq_status_desc, 512 + 448, 16,
			chain_params->ccp_data_len);

	write_bit_fields(seq_status_desc, 512 + 464, 5,
			chain_params->ccp_pad_boundary_shift);

	write_bit_fields(seq_status_desc, 512 + 469, 1,
			cmd->ccpc_stop_chain_on_error);
	write_bit_fields(seq_status_desc, 512 + 470, 1,
			cmd->ccpc_data_len_from_desc);
	write_bit_fields(seq_status_desc, 512 + 471, 1,
			cmd->ccpc_aol_pad_en);
	write_bit_fields(seq_status_desc, 512 + 472, 1,
			cmd->ccpc_sgl_pad_en);
	write_bit_fields(seq_status_desc, 512 + 473, 1,
			cmd->ccpc_sgl_sparse_format_en);
	write_bit_fields(seq_status_desc, 512 + 474, 1,
			cmd->ccpc_sgl_pdma_en);
	write_bit_fields(seq_status_desc, 512 + 475, 1,
			cmd->ccpc_sgl_pdma_pad_only);
	write_bit_fields(seq_status_desc, 512 + 476, 1,
			cmd->ccpc_sgl_pdma_alt_src_on_error);
	write_bit_fields(seq_status_desc, 512 + 477, 1,
			cmd->ccpc_desc_vec_push_en);
	write_bit_fields(seq_status_desc, 512 + 478, 1,
			cmd->ccpc_chain_alt_desc_on_error);
}

static void
fill_crypto_seq_status_desc(struct crypto_chain_params *chain_params,
		uint8_t *seq_status_desc)
{
	struct next_db_spec *next_db_spec;
	struct ring_spec *ring_spec;
	struct crypto_chain_params_command *cmd;

	ring_spec = &chain_params->ccp_ring_spec;
	next_db_spec = &chain_params->ccp_next_db_spec;
	cmd = &chain_params->ccp_cmd;

	memset(seq_status_desc, 0, SONIC_SEQ_STATUS_Q_DESC_SIZE);
	// desc bytes 0-63
	if (cmd->ccpc_next_db_action_ring_push) {
		write_bit_fields(seq_status_desc, 0, 64,
				ring_spec->rs_ring_addr);
		write_bit_fields(seq_status_desc, 64, 64,
				ring_spec->rs_desc_addr);
		write_bit_fields(seq_status_desc, 128, 34,
				ring_spec->rs_pndx_addr);
		write_bit_fields(seq_status_desc, 162, 34,
				ring_spec->rs_pndx_shadow_addr);
		write_bit_fields(seq_status_desc, 196, 4,
				ring_spec->rs_desc_size);
		write_bit_fields(seq_status_desc, 200, 3,
				ring_spec->rs_pndx_size);
		write_bit_fields(seq_status_desc, 203, 5,
				ring_spec->rs_ring_size);
		write_bit_fields(seq_status_desc, 208, 10,
				ring_spec->rs_num_descs);
	} else {
		write_bit_fields(seq_status_desc, 0, 64,
				next_db_spec->nds_addr);
		write_bit_fields(seq_status_desc, 64, 64,
				next_db_spec->nds_data);
	}

	write_bit_fields(seq_status_desc, 218, 64,
			chain_params->ccp_status_addr_0);
	write_bit_fields(seq_status_desc, 282, 64,
			chain_params->ccp_status_addr_1);
	write_bit_fields(seq_status_desc, 346, 64,
			chain_params->ccp_intr_addr);
	write_bit_fields(seq_status_desc, 410, 32,
			chain_params->ccp_intr_data);
	write_bit_fields(seq_status_desc, 442, 16,
			chain_params->ccp_status_len);
	write_bit_fields(seq_status_desc, 458, 7,
			chain_params->ccp_status_offset_0);
	write_bit_fields(seq_status_desc, 465, 1,
			cmd->ccpc_status_dma_en);
	write_bit_fields(seq_status_desc, 466, 1,
			cmd->ccpc_next_doorbell_en);
	write_bit_fields(seq_status_desc, 467, 1,
			cmd->ccpc_intr_en);
	write_bit_fields(seq_status_desc, 468, 1,
			cmd->ccpc_next_db_action_ring_push);

	// desc bytes 64-127
	write_bit_fields(seq_status_desc, 512 + 0, 64,
			chain_params->ccp_comp_sgl_src_addr);
	write_bit_fields(seq_status_desc, 512 + 64, 64,
			chain_params->ccp_sgl_pdma_dst_addr);
	write_bit_fields(seq_status_desc, 512 + 128, 64,
			chain_params->ccp_crypto_buf_addr);
	write_bit_fields(seq_status_desc, 512 + 192, 16,
			chain_params->ccp_data_len);
	write_bit_fields(seq_status_desc, 512 + 208, 5,
			chain_params->ccp_blk_boundary_shift);
	write_bit_fields(seq_status_desc, 512 + 213, 1,
			cmd->ccpc_stop_chain_on_error);
	write_bit_fields(seq_status_desc, 512 + 214, 1,
			cmd->ccpc_comp_len_update_en);
	write_bit_fields(seq_status_desc, 512 + 215, 1,
			cmd->ccpc_comp_sgl_src_en);
	write_bit_fields(seq_status_desc, 512 + 216, 1,
			cmd->ccpc_comp_sgl_src_vec_en);
	write_bit_fields(seq_status_desc, 512 + 217, 1,
			cmd->ccpc_sgl_sparse_format_en);
	write_bit_fields(seq_status_desc, 512 + 218, 1,
			cmd->ccpc_sgl_pdma_en);
	write_bit_fields(seq_status_desc, 512 + 219, 1,
			cmd->ccpc_sgl_pdma_len_from_desc);
	write_bit_fields(seq_status_desc, 512 + 220, 1,
			cmd->ccpc_desc_vec_push_en);
}

static void *
hw_setup_desc(struct service_info *svc_info, const void *src_desc,
		size_t desc_size)
{
	pnso_error_t err = EINVAL;
	struct accel_ring *ring;
	struct lif *lif;
	struct queue *q;
	struct sequencer_desc *seq_desc;
	uint32_t ring_id, index;
	uint16_t qtype;

	OSAL_LOG_DEBUG("enter ...");

	ring_id = svc_info->si_seq_info.sqi_ring_id;
	qtype = svc_info->si_seq_info.sqi_qtype;
	svc_info->si_seq_info.sqi_index = 0;

	ring = sonic_get_accel_ring(ring_id);
	if (!ring) {
		OSAL_ASSERT(ring);
		goto out;
	}

	lif = sonic_get_lif();
	if (!lif) {
		OSAL_ASSERT(lif);
		goto out;
	}

	err = sonic_get_seq_sq(lif, qtype, &q);
	if (err) {
		OSAL_ASSERT(err);
		goto out;
	}

	seq_desc = (struct sequencer_desc *) sonic_q_consume_entry(q, &index);
	if (!seq_desc) {
		err = EINVAL;
		OSAL_LOG_ERROR("failed to obtain sequencer desc! err: %d", err);
		OSAL_ASSERT(seq_desc);
		goto out;
	}
	svc_info->si_seq_info.sqi_index = index;

	memset(seq_desc, 0, sizeof(*seq_desc));
	seq_desc->sd_desc_addr =
		cpu_to_be64(sonic_virt_to_phy((void *) src_desc));
	seq_desc->sd_pndx_addr = cpu_to_be64(ring->ring_pndx_pa);
	seq_desc->sd_pndx_shadow_addr = cpu_to_be64(ring->ring_shadow_pndx_pa);
	seq_desc->sd_ring_addr = cpu_to_be64(ring->ring_base_pa);
	seq_desc->sd_desc_size = (uint8_t) ilog2(ring->ring_desc_size);
	seq_desc->sd_pndx_size = (uint8_t) ilog2(ring->ring_pndx_size);
	seq_desc->sd_ring_size = (uint8_t) ilog2(ring->ring_size);
	if (svc_info->si_seq_info.sqi_batch_mode) {
		seq_desc->sd_batch_mode = true;
		seq_desc->sd_batch_size =
			cpu_to_be16(svc_info->si_seq_info.sqi_batch_size);
	}

	OSAL_LOG_INFO("ring_id: %u index: %u src_desc: 0x" PRIx64 "  desc_size: %lu batch_mode: %d batch_size: %d",
			ring_id, index, (uint64_t) src_desc, desc_size,
			svc_info->si_seq_info.sqi_batch_mode,
			svc_info->si_seq_info.sqi_batch_size);
	PPRINT_SEQUENCER_DESC(seq_desc);

	OSAL_LOG_DEBUG("exit!");
	return seq_desc;

out:
	OSAL_LOG_ERROR("exit! err: %d", err);
	return NULL;
}

static void
hw_ring_db(const struct service_info *svc_info)
{
	struct queue *seq_q;
	uint16_t index;

	OSAL_LOG_DEBUG("enter ... ");

	seq_q = get_seq_q(svc_info, false);
	if (!seq_q) {
		OSAL_LOG_ERROR("failed to get sequencer q!");
		OSAL_ASSERT(seq_q);
		goto out;
	}

	index = svc_info->si_seq_info.sqi_index;
	sonic_q_ringdb(seq_q, index);

out:
	OSAL_LOG_DEBUG("exit!");
}

static pnso_error_t
hw_setup_cp_chain_params(struct chain_entry *centry,
		struct service_info *svc_info,
		struct cpdc_desc *cp_desc,
		struct cpdc_status_desc *status_desc)
{
	pnso_error_t err = EINVAL;
	struct service_chain *svc_chain;
	struct cpdc_chain_params *chain_params;
	struct sequencer_info *seq_info;
	struct sequencer_spec *seq_spec;
	uint32_t ring_id, index;
	uint16_t qtype;
	uint8_t *seq_status_desc;

	struct accel_ring *ring;
	struct lif *lif;
	struct queue *q, *status_q;

	OSAL_LOG_DEBUG("enter ...");

	svc_chain = centry->ce_chain_head;
	chain_params = &svc_info->si_cpdc_chain;
	seq_spec = &chain_params->ccp_seq_spec;

	seq_info = &svc_info->si_seq_info;
	ring_id = seq_info->sqi_ring_id;
	qtype = seq_info->sqi_qtype;
	seq_info->sqi_index = 0;
	PPRINT_SEQUENCER_INFO(seq_info);

	ring = sonic_get_accel_ring(ring_id);
	if (!ring) {
		OSAL_ASSERT(ring);
		goto out;
	}

	lif = sonic_get_lif();
	if (!lif) {
		OSAL_ASSERT(lif);
		goto out;
	}

	err = sonic_get_seq_sq(lif, qtype, &q);
	if (err) {
		OSAL_ASSERT(err);
		goto out;
	}

	err = sonic_get_seq_statusq(lif, SONIC_QTYPE_CPDC_STATUS, &status_q);
	if (err) {
		OSAL_ASSERT(err);
		goto out;
	}

	seq_status_desc = (uint8_t *) sonic_q_consume_entry(status_q, &index);
	if (!seq_status_desc) {
		err = EINVAL;
		OSAL_LOG_ERROR("failed to obtain sequencer statusq desc! err: %d",
				err);
		OSAL_ASSERT(seq_status_desc);
		goto out;
	}
	seq_info->sqi_index = index;
	seq_info->sqi_status_desc = seq_status_desc;

	seq_spec->sqs_seq_q = q;
	seq_spec->sqs_seq_status_q = status_q;
	/* skip sqs_seq_next_q/sqs_seq_next_status_q not needed for comp+hash */

	cp_desc->cd_db_addr = sonic_get_lif_local_dbaddr();
	cp_desc->cd_db_data = sonic_q_ringdb_data(status_q, index);
	cp_desc->u.cd_bits.cc_db_on = 1;

	chain_params->ccp_cmd.ccpc_next_doorbell_en = 1;
	chain_params->ccp_cmd.ccpc_next_db_action_ring_push = 1;
	chain_params->ccp_cmd.ccpc_stop_chain_on_error = 1;
	chain_params->ccp_cmd.ccpc_sgl_pdma_en = 1;

	chain_params->ccp_status_addr_0 =
		sonic_virt_to_phy((void *) status_desc);
	chain_params->ccp_pad_buf_addr = pad_buffer;
	chain_params->ccp_pad_boundary_shift =
		(uint8_t) ilog2(PNSO_MEM_ALIGN_PAGE);

	chain_params->ccp_cmd.ccpc_sgl_pdma_pad_only = 1;
	chain_params->ccp_sgl_vec_addr = cp_desc->cd_dst;

	OSAL_LOG_INFO("ring_id: %u index: %u src_desc: 0x" PRIx64 " status_desc: 0x" PRIx64 "",
			ring_id, index, (uint64_t) cp_desc,
			(uint64_t) status_desc);

	PPRINT_SEQUENCER_INFO(seq_info);

	err = PNSO_OK;
	OSAL_LOG_DEBUG("exit!");
	return err;

out:
	OSAL_LOG_ERROR("exit! err: %d", err);
	return err;
}

static pnso_error_t
hw_setup_hash_chain_params(struct cpdc_chain_params *chain_params,
		struct service_info *svc_info,
		struct cpdc_desc *hash_desc, struct cpdc_sgl *sgl,
		uint32_t num_hash_blks)
{
	pnso_error_t err = EINVAL;
	struct accel_ring *ring;
	uint32_t ring_id;

	struct sequencer_info *seq_info;
	struct ring_spec *ring_spec;

	OSAL_LOG_DEBUG("enter ...");

	ring_spec = &chain_params->ccp_ring_spec;

	seq_info = &svc_info->si_seq_info;
	ring_id = seq_info->sqi_ring_id;
	PPRINT_SEQUENCER_INFO(seq_info);

	ring = sonic_get_accel_ring(ring_id);
	if (!ring) {
		OSAL_ASSERT(0);
		goto out;
	}

	ring_spec->rs_ring_addr = ring->ring_base_pa;
	ring_spec->rs_pndx_addr = ring->ring_pndx_pa;
	ring_spec->rs_pndx_shadow_addr = ring->ring_shadow_pndx_pa;
	ring_spec->rs_desc_addr = sonic_virt_to_phy((void *) hash_desc);
	ring_spec->rs_desc_size = (uint8_t) ilog2(ring->ring_desc_size);
	ring_spec->rs_pndx_size = (uint8_t) ilog2(ring->ring_pndx_size);
	ring_spec->rs_ring_size = (uint8_t) ilog2(ring->ring_size);
	ring_spec->rs_num_descs = num_hash_blks;

	chain_params->ccp_sgl_vec_addr = sonic_virt_to_phy((void *) sgl);
	chain_params->ccp_cmd.ccpc_sgl_pad_en = 1;
	chain_params->ccp_cmd.ccpc_sgl_sparse_format_en = 1;
	/*
	 * hash executes multiple requests, one per block; hence, indicate to
	 * P4+ to push a vector of descriptors
	 */
	chain_params->ccp_cmd.ccpc_desc_vec_push_en = 1;

	PPRINT_SEQUENCER_INFO(seq_info);

	err = PNSO_OK;
	OSAL_LOG_DEBUG("exit!");
	return err;
out:
	OSAL_LOG_ERROR("exit! err: %d", err);
	return err;
}

static void *
hw_setup_cpdc_chain_desc(struct chain_entry *centry,
		struct service_info *svc_info,
		const void *src_desc, size_t desc_size)
{
	pnso_error_t err = EINVAL;
	struct service_chain *svc_chain;
	struct cpdc_chain_params *chain_params;
	struct sequencer_info *seq_info;
	struct sequencer_desc *seq_desc;

	OSAL_LOG_DEBUG("enter ...");

	svc_chain = centry->ce_chain_head;
	chain_params = &svc_info->si_cpdc_chain;
	seq_info = &svc_info->si_seq_info;
	PPRINT_SEQUENCER_INFO(seq_info);

	fill_cpdc_seq_status_desc(chain_params, seq_info->sqi_status_desc);
	PPRINT_CPDC_CHAIN_PARAMS(chain_params);

	seq_desc = hw_setup_desc(svc_info, src_desc, desc_size);
	if (!seq_desc) {
		OSAL_ASSERT(seq_desc);
		OSAL_LOG_ERROR("failed to setup seq desc! err: %d", err);
		goto out;
	}

	PPRINT_SEQUENCER_INFO(seq_info);

	OSAL_LOG_DEBUG("exit!");
	return seq_desc;

out:
	OSAL_LOG_ERROR("exit! err: %d", err);
	return NULL;
}

static void
hw_cleanup_cpdc_chain(const struct service_info *svc_info)
{
	const struct cpdc_chain_params *cpdc_chain = &svc_info->si_cpdc_chain;

	if (cpdc_chain->ccp_seq_spec.sqs_seq_status_q)
		sonic_put_seq_statusq(cpdc_chain->ccp_seq_spec.sqs_seq_status_q);
}

static pnso_error_t
hw_setup_crypto_chain(struct service_info *svc_info,
		      struct crypto_desc *desc)
{
	struct sequencer_info *seq_info;
	struct sequencer_spec *seq_spec;
	struct lif *lif;
	uint32_t statusq_index;
	pnso_error_t err;

	seq_spec = &svc_info->si_crypto_chain.ccp_seq_spec;
	seq_info = &svc_info->si_seq_info;
	lif = sonic_get_lif();
	if (!lif) {
		OSAL_LOG_ERROR("failed to obtain LIF");
		return EPERM;
	}

	err = sonic_get_seq_statusq(lif, seq_info->sqi_status_qtype,
				    &seq_spec->sqs_seq_status_q);
	if (err) {
		return err;
	}

	seq_info->sqi_status_desc =
		(uint8_t *)sonic_q_consume_entry(seq_spec->sqs_seq_status_q,
						 &statusq_index);
	if (!seq_info->sqi_status_desc) {
		OSAL_LOG_ERROR("failed to obtain crypto sequencer statusq desc");
		return EPERM;
	}
	desc->cd_db_addr = sonic_get_lif_local_dbaddr();
	desc->cd_db_data = sonic_q_ringdb_data(seq_spec->sqs_seq_status_q, statusq_index);

	OSAL_LOG_DEBUG("ring_id: %u index: %u desc: 0x"PRIx64,
		       seq_info->sqi_ring_id, statusq_index, (uint64_t)desc);
	fill_crypto_seq_status_desc(&svc_info->si_crypto_chain,
				    seq_info->sqi_status_desc);
	PPRINT_SEQUENCER_INFO(seq_info);
	return PNSO_OK;
}

static void
hw_cleanup_crypto_chain(const struct service_info *svc_info)
{
	const struct crypto_chain_params *crypto_chain = &svc_info->si_crypto_chain;

	if (crypto_chain->ccp_seq_spec.sqs_seq_status_q)
		sonic_put_seq_statusq(crypto_chain->ccp_seq_spec.sqs_seq_status_q);
}

const struct sequencer_ops hw_seq_ops = {
	.setup_desc = hw_setup_desc,
	.ring_db = hw_ring_db,
	.setup_cp_chain_params = hw_setup_cp_chain_params,
	.setup_hash_chain_params = hw_setup_hash_chain_params,
	.setup_cpdc_chain_desc = hw_setup_cpdc_chain_desc,
	.cleanup_cpdc_chain = hw_cleanup_cpdc_chain,
	.setup_crypto_chain = hw_setup_crypto_chain,
	.cleanup_crypto_chain = hw_cleanup_crypto_chain,
};
