/*
 * {C} Copyright 2018 Pensando Systems Inc.
 * All rights reserved.
 *
 */
#ifndef __PNSO_API_H__
#define __PNSO_API_H__

#include <stdint.h>

/*
 * WORK_IN_PROGRESS/TODO:
 *	add signature template with 
 *		in/out/pre/post/returns/align/pack/ownership/etc.
 *	add official license boilerplate
 *	adjust terminology and comments
 *	identify and emphasize required min/max values for params
 *
 */

/**
 * Pensando offloaders for storage and security
 *
 * Pensando hardware accelerators can boost the storage and security
 * performance.  By offloading compute-intensive workloads from the CPU
 * core to Pensando hardware accelerators, performance and efficiency of
 * the applications the applications can significantly be increased.
 *
 * This file contain declarations and functions that are necessary for
 * applications to integrate Pensando hardware acceleration services.
 *
 */

/* Different types of accelerator services */
enum pnso_service_type {
	PNSO_SVC_TYPE_NONE		= 0,
	PNSO_SVC_TYPE_ENCRYPT		= 1,
	PNSO_SVC_TYPE_DECRYPT		= 2,
	PNSO_SVC_TYPE_COMPRESS		= 3,
	PNSO_SVC_TYPE_DECOMPRESS	= 4,
	PNSO_SVC_TYPE_HASH		= 5,
	PNSO_SVC_TYPE_CHKSUM		= 6,
	PNSO_SVC_TYPE_PAD		= 7,
	PNSO_SVC_TYPE_DECOMPACT		= 8,
	PNSO_SVC_TYPE_MAX
};

/**
 * Pensando accelerators can be exercised by submitting one request at a time
 * or a batch of requests.
 *
 * Following constants enable to distinguish the mode of request submission.
 * When requests are submitted in batch mode, the beginning and ending phase
 * is indicated by start/continue/end markers.
 *
 */
enum pnso_batch_request {
	PNSO_BATCH_REQ_NONE		= 0,
	PNSO_BATCH_REQ_FLUSH		= PNSO_BATCH_REQ_NONE,
	PNSO_BATCH_REQ_CONTINUE		= 1,
	PNSO_BATCH_REQ_MAX
};

/* Algorithms for compression/decompression */
enum pnso_compressor_type {
	PNSO_COMPRESSOR_TYPE_NONE	= 0,
	PNSO_COMPRESSOR_TYPE_LZRW1A	= 1,	/* TODO: Get value for the
						   algorithm from Netapp */
	PNSO_COMPRESSOR_TYPE_MAX
};

/* Algorithms for checksum */
enum pnso_chksum_type {
	PNSO_CHKSUM_TYPE_NONE		= 0,
	PNSO_CHKSUM_TYPE_MCRC64		= 1,
	PNSO_CHKSUM_TYPE_CRC32C		= 2,
	PNSO_CHKSUM_TYPE_ADLER32	= 3,
	PNSO_CHKSUM_TYPE_MADLER32	= 4,
	PNSO_CHKSUM_TYPE_MAX
};

/* Algorithms for deduplication hash */
enum pnso_hash_type {
	PNSO_HASH_TYPE_NONE		= 0,
	PNSO_HASH_TYPE_SHA2_512		= 1,
	PNSO_HASH_TYPE_SHA2_256		= 2,
	PNSO_HASH_TYPE_MAX
};

#define PNSO_MAX_SESSIONS 24
#define PNSO_MAX_SERVICE_CHAIN 8
#define PNSO_DEFAULT_BLOCK_SZ (4 * 1024)
#define PNSO_MAX_BUFFER_LEN (64 * 1024)

typedef int32_t pnso_error_t;

/* Generic error codes */
#define PNSO_OK 				0

/* Error codes for compression/decompression */
#define PNSO_ERR_CPDC_AXI_TIMEOUT		20001
#define PNSO_ERR_CPDC_AXI_DATA_ERROR		20002
#define PNSO_ERR_CPDC_AXI_ADDR_ERROR		20003
#define PNSO_ERR_CPDC_COMPRESSION_FAILED	20004
#define PNSO_ERR_CPDC_DATA_TOO_LONG		20005
#define PNSO_ERR_CPDC_CHECKSUM_FAILED		20006
#define PNSO_ERR_CPDC_SGL_DESC_ERROR		20007

/* Error codes for encryption/decryption */
#define PNSO_ERR_XTS_KEY_INDEX_OUT_OF_RANG	30001
#define PNSO_ERR_XTS_WRONG_KEY_TYPE		30002
#define PNSO_ERR_XTS_AXI_ERROR			30003
#define PNSO_ERR_XTS_AXI_STATUS_ERROR		30004
#define PNSO_ERR_XTS_AOL_DESC_ERROR		30005

/* Error codes for hash/chksum */
#define PNSO_ERR_HASH_BAD_PARAM                 40001
#define PNSO_ERR_HASH_BAD_INPUT                 40002
#define PNSO_ERR_HASH_UNSUPPORTED               40003

/* Error codes for decompaction */
#define PNSO_ERR_DECOMPACT_BAD_PARAM            50001
#define PNSO_ERR_DECOMPACT_BAD_INPUT            50002

/**
 * struct pnso_flat_buffer - describes a buffer with 'address and length'
 * @buf: contains the physical address of a buffer
 * @rsvd: specifies a 'reserved' field meant to be used by Pensando.
 * @len: contains the length of the buffer in bytes.  Pensando accelerators
 * can handle only a maximum of 64KB in a buffer.
 *
 */
struct pnso_flat_buffer {
	uint64_t buf;
	uint32_t rsvd;
	uint32_t len;
};

/**
 * struct pnso_buffer_list - describes a scatter/gather buffer list.
 * @rsvd: specifies a 'reserved' field meant to be used by Pensando.
 * @count: specifies the number of buffers in the list
 * @buffers: specifies an unbounded array of flat buffers as defined by
 * 'count'.
 *
 * This structure is typically used to represent a collection of physical
 * memory buffers that are not contiguous.
 *
 */
struct pnso_buffer_list {
	uint32_t rsvd;
	uint32_t count;
	struct pnso_flat_buffer buffers[0];
};

/**
 * struct pnso_compression_header - represents the result of compression and
 * decompression operation
 * @chksum: specifies the data integrity field, i.e. the checksum calculation
 * on input data before compression.
 * @data_len: specifies the compressed length
 * @version: specifies the version of the checksum algorithm 
 *
 * Compression operation will insert a 8-byte header (populating the compressed
 * length, the checksum and the version number) at the beginning of the
 * compressed buffer.
 *
 * Decompression operation will extract the 'checksum' and remove the header.
 * The 'data_len' does not include the length of the header.
 *
 */
struct pnso_compression_header {
	uint32_t chksum;
	uint16_t data_len;
	uint16_t version;
};

/**
 * struct pnso_crypto_desc - represents the descriptor for encryption or
 * decryption operation
 * @key_desc_idx: specifies the key index in the descriptor table.
 * @rsvd: specifies a 'reserved' field meant to be used by Pensando.
 * @iv_addr: specifies the physical address of the buffer.
 *
 */
struct pnso_crypto_desc {
	uint32_t key_desc_idx;
	uint32_t rsvd;
	uint64_t iv_addr;
};

/**
 * struct pnso_compression_desc - represents the descriptor for compression
 * service 
 * @rsvd_1: specifies a 'reserved' field meant to be used by Pensando.
 * @threshold_len: specifies the expected compressed buffer length in bytes.
 * This is to instruct the compression operation, upon its completion, to
 * compress the buffer to a length that must be less than or equal to
 * 'threshold_len'.
 * @rsvd_2: specifies a 'reserved' field meant to be used by Pensando.
 *
 */
struct pnso_compression_desc {
	uint8_t do_pad;
	uint8_t header_len;
	uint16_t threshold_len;
	uint32_t rsvd_2;
}; 

/**
 * struct pnso_decompression_desc - represents the descriptor for decompression
 * operation
 *
 */
struct pnso_decompression_desc {
	uint8_t rsvd_1;
	uint8_t header_len;
	uint16_t rsvd_2;
	uint32_t rsvd_3;
}; 

/**
 * struct pnso_hash_desc - represents the descriptor for data deduplication
 * operation
 *
 */
struct pnso_hash_desc {
};

/**
 * struct pnso_checksum_desc - represents the descriptor for checksum
 * operation
 *
 */
struct pnso_checksum_desc {
};

/**
 * struct pnso_pad_desc - represents the descriptor for 'padding' operation
 *
 */
struct pnso_pad_desc {
};

/**
 * TODO: This input (i.e. header) has to come from Netapp.
 *
 * struct pnso_decompaction_desc - represents the descriptor for decompaction
 * operation
 * @key:
 * @hdr_offset:
 * @rsvd: 
 *
 */
struct pnso_decompaction_desc {
	uint64_t key:48;
	uint64_t is_uncompressed:1;
	uint64_t rsvd:15;
};

/*
 * SHA512 and SHA256 hash need 64 and 32 bytes respectively.  Checksum need a
 * maximum of 4 bytes.
 *
 * Pensando accelerator supports a maximum of 64KB in one request, which
 * accounts to 16 4KB blocks, requiring to produce 16 64-byte hashes for every
 * 4KB block, and 16 4-byte checksums for every 4KB block.
 *
 * NOTE: Netapp will specify a max of 32KB buffer per request, so will require
 * space for only 8 hashes.
 *
 */
#define PNSO_HASH_OR_CHKSUM_TAG_LEN 64

/**
 * struct pnso_hash_or_chksum_tag -  represents the SHA or checksum tag
 * @hash_or_chksum: specifies an array of either a hash and checksum.
 *
 */
struct pnso_hash_or_chksum_tag {
	uint8_t hash_or_chksum[PNSO_HASH_OR_CHKSUM_TAG_LEN];
};

/**
 * struct pnso_service_result - represents the result of the request upon
 * completion of a service within the service request 
 * @svc_type: specifies one of the enumerated values for the accelerator
 * service type.
 * @err: specifies the error code of the service within the service request 
 * @output_data_len: specifies the length of the output buffer processed in
 * bytes.
 * @num_tags: specifies number of SHAs or checksums.
 * @tag: specifies an array of hashes or checksums.
 *
 */
struct pnso_service_status {
	uint8_t svc_type;
	pnso_error_t err;
	uint32_t output_data_len;
	uint16_t num_tags;
	struct pnso_hash_or_chksum_tag *tags;
};
struct pnso_service_result {
	pnso_error_t err;
	uint32_t num_services;
	struct pnso_service_status status[0];
};


/**
 * struct pnso_service - describes various parameters of the service chosen
 * for acceleration
 * @svc_type: specifies one of the enumerated values for the accelerator
 * service type.
 * @algo_type: specifies one of the enumerated values of the compressor or
 * dedupe or chksum algorithm (i.e. enum pnso_compressor_type/pnso_chksum_type/
 * pnso_hash_type) based on the chosen accelerator service type.
 * @crypto_desc: specifies the descriptor for encryption/decryption service.
 * @cp_desc: specifies the descriptor for compression service.
 * @dc_desc: specifies the descriptor for decompression service.
 * @hash_desc: specifies the descriptor for deduplication service.
 * @chksum_desc: specifies the descriptor for checksum service.
 * @pad_desc: specifies the descriptor for padding service.
 * @decompact_desc: specifies the descriptor for decompaction service.
 *
 */
struct pnso_service {
	uint8_t svc_type;
	uint8_t algo_type;
	union {
		struct pnso_crypto_desc crypto_desc;
		struct pnso_compression_desc cp_desc;
		struct pnso_decompression_desc dc_desc;
		struct pnso_hash_desc hash_desc;
		struct pnso_checksum_desc chksum_desc;
		struct pnso_pad_desc pad_desc;
		struct pnso_decompaction_desc decompact_desc;
	} req;
};

/**
 * struct pnso_service_request - represents an array of services that are to be
 * handled in a request.
 * @src_buf: specifies input buffer on which the request will operate on.
 * @dst_buf: specifies output buffer on which the request will operate on.
 * @num_services: specifies the number of services in the input service
 * request.
 * @svc: specifies the information about each service within the service
 * request.
 *
 */
struct pnso_service_request {
	struct pnso_buffer_list *src_buf;
	struct pnso_buffer_list *dst_buf;
	uint32_t num_services;
	struct pnso_service svc[0];
};

/**
 * completion_t: caller-supplied completion callback 
 * @cb_ctx: specifies the callback args for the caller-supplied callback
 * routine.
 * @err: specifies the overall success or failure of the service request.
 * @num_results: specifies the number of services in the results.
 * @svc_res: specifies an array of service result structures to report the
 * status of each service request upon its completion.
 *
 */
typedef void (*completion_t)(void *cb_ctx,
		struct pnso_service_result *svc_res);

/**
 * pnso_poll_fn: the caller to use this polling function to detect
 * completion of a request
 * @sess_id: the session on which the request was submitted
 * @pnso_poll_ctx: specifies the context passed as arg to the polling function
 *
 * Return:
 *	bool
 */
typedef bool (*poller_t)(uint32_t sess_id, void *poll_ctx);

/**
 * pnso_submit_request() - routine that accepts one or more service(s) as a
 * request, and batches two or more such requests internally.
 * @sess_id: session id, should be unique per thread or core
 * @batch_req: specifies whether the request is independent or belongs to a 
 * group of requests.
 * @num_services: specifies the number of services in the request.
 * @svc_req: specifies an array of service requests that to be used
 * to complete the services within the request.
 * @svc_res: specifies an array of service result structures to report the
 * status of each service request upon its completion.
 * @cb: specifies the caller-supplied completion callback routine.
 * @cb_ctx: specifies the caller-supplied context information.
 * @pnso_poll_fn: specifies the polling function, which the caller will use to
 * poll for completion of the request.
 * @pnso_poll_ctx: specifies the context for the polling function.
 *
 * Return:
 *	EINVAL
 *
 */
pnso_error_t pnso_submit_request(uint32_t sess_id,
		enum pnso_batch_request batch_req,
		struct pnso_service_request *svc_req,
		struct pnso_service_result *svc_res,
		completion_t cb,
		void *cb_ctx,
		poller_t *poll_fn,
		void **poll_ctx);

/**
 * pnso_set_key_desc_idx() - sets the key descriptor index
 * @key1: specifies the key that was used to encrypt the data
 * @key2: specifies the key that was used to encrypt initialization vector
 * @key_size: specifies the size of the key in bytes -- 16 and 32 bytes for
 * AES128 and AES256 respectively.
 * @key_idx: specifies the key index in the descriptor table.
 *
 * Return:
 *	EINVAL
 *
 */
pnso_error_t pnso_set_key_desc_idx(const void *key1,
		const void *key2,
		uint32_t key_size,
		uint32_t key_idx);

#endif /* __PNSO_API_H__ */
