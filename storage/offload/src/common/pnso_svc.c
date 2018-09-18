/*
 * {C} Copyright 2018 Pensando Systems Inc.
 * All rights reserved.
 *
 */
#include "osal.h"
#include "pnso_api.h"

#include "pnso_cpdc.h"
#include "pnso_cpdc_cmn.h"

static inline bool
is_cp_algo_type_valid(uint16_t algo_type)
{
	return (algo_type == PNSO_COMPRESSION_TYPE_LZRW1A) ? true : false;
}

static inline bool
is_cp_threshold_len_valid(uint16_t threshold_len)
{
	return (threshold_len > (MAX_CPDC_SRC_BUF_LEN -
			sizeof(struct pnso_compression_header))) ? false : true;
}

static inline bool
is_cp_flags_valid(uint16_t flags)
{
	/* no contracdicting flags to reject the desc, so skip any checks */
	return true;
}

bool
svc_is_cp_desc_valid(const struct pnso_compression_desc *desc)
{
	pnso_error_t err = EINVAL;

	if (!is_cp_algo_type_valid(desc->algo_type)) {
		OSAL_LOG_ERROR("invalid cp algo type specified! algo_type: %hu err: %d",
				desc->algo_type, err);
		return false;
	}

	if (!is_cp_threshold_len_valid(desc->threshold_len)) {
		OSAL_LOG_ERROR("invalid cp threshold len specified! threshold_len: %hu err: %d",
				desc->threshold_len, err);
		return false;
	}

	if (!is_cp_flags_valid(desc->flags)) {
		OSAL_LOG_ERROR("invalid cp flags specified! flags: %hu err: %d",
				desc->flags, err);
		return false;
	}

	OSAL_LOG_INFO("compression desc is valid algo_type: %hu threshold_len: %hu flags: %hu",
			desc->algo_type, desc->threshold_len, desc->flags);

	return true;
}

/* -------------------------------------------------------------------------- */
static inline bool
is_dc_algo_type_valid(uint16_t algo_type)
{
	return (algo_type == PNSO_COMPRESSION_TYPE_LZRW1A) ? true : false;
}

static inline bool
is_dc_flags_valid(uint16_t flags)
{
	/* no contracdicting flags to reject the desc, so skip any checks */
	return true;
}

bool
svc_is_dc_desc_valid(const struct pnso_decompression_desc *desc)
{
	pnso_error_t err = EINVAL;

	if (!is_dc_algo_type_valid(desc->algo_type)) {
		OSAL_LOG_ERROR("invalid dc algo type specified! algo_type: %hu err: %d",
				desc->algo_type, err);
		return false;
	}

	if (!is_dc_flags_valid(desc->flags)) {
		OSAL_LOG_ERROR("invalid dc flags specified! flags: %hu err: %d",
				desc->flags, err);
		return false;
	}

	OSAL_LOG_INFO("decompression desc is valid algo_type: %hu flags: %hu",
			desc->algo_type, desc->flags);

	return true;
}

/* -------------------------------------------------------------------------- */
static inline bool
is_hash_algo_type_valid(uint16_t algo_type)
{
	switch (algo_type) {
	case PNSO_HASH_TYPE_SHA2_512:
	case PNSO_HASH_TYPE_SHA2_256:
		return true;
	default:
		return false;
	}

	return false;
}

static inline bool
is_hash_flags_valid(uint16_t flags)
{
	/* no contracdicting flags to reject the desc, so skip any checks */
	return true;
}

bool
svc_is_hash_per_block_enabled(uint16_t flags)
{
	return (flags & PNSO_HASH_DFLAG_PER_BLOCK) ? true : false;
}

bool
svc_is_hash_desc_valid(const struct pnso_hash_desc *desc)
{
	pnso_error_t err = EINVAL;

	if (!is_hash_algo_type_valid(desc->algo_type)) {
		OSAL_LOG_ERROR("invalid hash algo type specified! algo_type: %hu err: %d",
				desc->algo_type, err);
		return false;
	}

	if (!is_hash_flags_valid(desc->flags)) {
		OSAL_LOG_ERROR("invalid hash flags specified! flags: %hu err: %d",
				desc->flags, err);
		return false;
	}

	OSAL_LOG_INFO("hash desc is valid algo_type: %hu flags: %hu",
			desc->algo_type, desc->flags);

	return true;
}

/* -------------------------------------------------------------------------- */
static inline bool
is_chksum_algo_type_valid(uint16_t algo_type)
{
	switch (algo_type) {
	case PNSO_CHKSUM_TYPE_MCRC64:
	case PNSO_CHKSUM_TYPE_CRC32C:
	case PNSO_CHKSUM_TYPE_ADLER32:
	case PNSO_CHKSUM_TYPE_MADLER32:
		return true;
	default:
		return false;
	}

	return false;
}

static inline bool
is_chksum_flags_valid(uint16_t flags)
{
	/* no contracdicting flags to reject the desc, so skip any checks */
	return true;
}

bool
svc_is_chksum_per_block_enabled(uint16_t flags)
{
	return (flags & PNSO_CHKSUM_DFLAG_PER_BLOCK) ? true : false;
}

bool
svc_is_chksum_desc_valid(const struct pnso_checksum_desc *desc)
{
	pnso_error_t err = EINVAL;

	if (!is_chksum_algo_type_valid(desc->algo_type)) {
		OSAL_LOG_ERROR("invalid chksum algo type specified! algo_type: %hu err: %d",
				desc->algo_type, err);
		return false;
	}

	if (!is_chksum_flags_valid(desc->flags)) {
		OSAL_LOG_ERROR("invalid chksum flags specified! flags: %hu err: %d",
				desc->flags, err);
		return false;
	}

	OSAL_LOG_INFO("chksum desc is valid algo_type: %hu flags: %hu",
			desc->algo_type, desc->flags);

	return true;
}
