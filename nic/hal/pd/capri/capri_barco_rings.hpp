#ifndef __CAPRI_BARCO_RINGS_H__
#define __CAPRI_BARCO_RINGS_H__

namespace hal {
namespace pd {
/* Asymmetric engine related definitions */

typedef struct barco_asym_descriptor_s {
    uint64_t                input_list_addr;
    uint64_t                output_list_addr;
    uint8_t                 key_descr_idx_lo;
    uint16_t                key_descr_idx_hi;
    uint64_t                status_addr;
    uint32_t                opaque_tag_value;
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
    uint8_t                 opage_tag_wr_en:1;
    uint8_t                 flag_a:1;
    uint8_t                 flag_b:1;
    uint8_t                 rsvd:5;
#else
    uint8_t                 rsvd:5;
    uint8_t                 flag_b:1;
    uint8_t                 flag_a:1;
    uint8_t                 opage_tag_wr_en:1;
#endif
} __attribute__((__packed__)) barco_asym_descriptor_t;



typedef struct barco_asym_dma_descriptor_s {
    uint64_t                address;
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
    uint64_t                stop:1;
    uint64_t                rsvd0:1;
    uint64_t                next:62;

    uint32_t                int_en:1;
    uint32_t                discard:1;
    uint32_t                realign:1;
    uint32_t                cst_addr:1;
    uint32_t                length:28;
#else
    uint32_t                length:28;
    uint32_t                cst_addr:1;
    uint32_t                realign:1;
    uint32_t                discard:1;
    uint32_t                int_en:1;

    uint64_t                next:62;
    uint64_t                rsvd0:1;
    uint64_t                stop:1;
#endif
    uint32_t                tag;
} __attribute__((__packed__)) barco_asym_dma_descriptor_t;

typedef struct barco_mpp_req_descriptor_s {
    uint64_t                input_list_addr;
    uint64_t                output_list_addr;
    uint32_t                command;
    uint32_t                key_descr_idx;
    uint64_t                iv_address;
    uint64_t                auth_tag_addr;
    uint32_t                header_size;
    uint64_t                status_addr;
    uint32_t                opaque_tag_value;
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
    uint32_t                opaque_tag_wr_en:1;
    uint32_t                rsvd:31;
#else
    uint32_t                rsvd:31;
    uint32_t                opaque_tag_wr_en:1;
#endif
    uint16_t                sector_size;
    uint16_t                application_tag;
    uint32_t                sector_num;
    uint64_t                doorbell_addr;
    uint64_t                doorbell_data;
    uint8_t                 reserved[44];
}  __attribute__((__packed__)) barco_mpp_req_descriptor_t;

typedef struct barco_sym_msg_descriptor_s {
    uint64_t   A0_addr;
    uint32_t   O0_addr_offset;
    uint32_t   L0_data_length;
    uint64_t   A1_addr;
    uint32_t   O1_addr_offset;
    uint32_t   L1_data_length;
    uint64_t   A2_addr;
    uint32_t   O2_addr_offset;
    uint32_t   L2_data_length;
    uint64_t   next_address;
    uint64_t   reserved;
}  __attribute__((__packed__)) barco_sym_msg_descriptor_t;

/* Barco Asym DMA Descriptor allocator */

hal_ret_t pd_crypto_asym_dma_descr_alloc(uint64_t *asym_dma_descr);
hal_ret_t pd_crypto_asym_dma_descr_free(uint64_t asym_dma_descr);
hal_ret_t pd_crypto_asym_dma_descr_init(void);

typedef hal_ret_t (*barco_ring_init_t) (struct capri_barco_ring_s *);
typedef bool (*barco_ring_poller_t) (struct capri_barco_ring_s *, uint32_t);
typedef hal_ret_t (*barco_ring_queue_request) (struct capri_barco_ring_s *, void *, uint32_t *);

typedef struct capri_barco_ring_s {
    char                ring_name[32];      /*  Friendly name for logging       */
    char                hbm_region[32];     /*  HBM region name                 */
    uint64_t            ring_base;          /*  Address to the ring memory      */
    uint64_t            ring_alignment;     /*  Alignment of the ring elements  */
    uint16_t            ring_size;          /*  number of entries               */
    uint16_t            descriptor_size;    /*  in bytes                        */
    uint16_t            producer_idx;       /*  S/W Write Ptr                   */
    uint16_t            consumer_idx;       /*  S/W Read ptr                    */
    uint64_t            opaque_tag_addr;    /*  Location of opa tag             */
    uint32_t            opaqe_tag_value;    /*  Running counter for the opa tag */
    /* TBD lock/spinlock for ring access */
    barco_ring_init_t   init;               /* Ring initialization fn           */
    barco_ring_poller_t poller;             /* Ring poller fn                   */
    barco_ring_queue_request    queue_request;  /* Request queue support        */

#if 0
    /*
     * User context blocks for asynchronous response handling (TBD).
     */
     capri_barco_user_cb_t user_cb[CAPRI_MAX_BARCO_RING_SIZE];
#endif
} capri_barco_ring_t;

//#define BARCO_RING_XTS_STR(id)  "Barco XTS" ## #id
#define BARCO_RING_GCM_STR(id)  "Barco GCM" ## #id
#define BARCO_RING_MPP_BASE_STR "Barco MPP"
#define BARCO_RING_MPP_STR(id)  "Barco MPP" ## #id
#define BARCO_RING_ASYM_STR     "Barco Asym"
#define BARCO_RING_XTS_STR      "Barco XTS"
#define BARCO_RING_MPP0_STR     "Barco MPP0"


hal_ret_t capri_barco_ring_queue_request(types::BarcoRings barco_ring_type, void *req, uint32_t *req_tag);
bool capri_barco_ring_poll(types::BarcoRings barco_ring_type, uint32_t req_tag);

typedef int (*barco_response_cb)(void *user_ctx, void *response);

#define CAPRI_MAX_BARCO_RING_SIZE 1024

/*
 * User context block for asynchronous response handling.
 */
typedef struct capri_barco_user_cb_t_ {
    void               *user_ctx;     /* Opaque context specific to user */
    barco_response_cb  resp_handler;  /* User callback for response processing */
} capri_barco_user_cb_t;

#if 0
/*
 * Enqueue user request in a shadow ring to track for asynchronous response.
 */
static inline void
capri_barco_req_enqueue (capri_barco_ring_t *barco_ring,
			 void *user_ctx, barco_response_cb cb)
{
    barco_ring->user_cb[barco_ring->producer_idx].user_ctx = user_ctx;
    barco_ring->user_cb[barco_ring->producer_idx].resp_handler = cb;
}

/*
 * Handle asynchronous response from barco to dispatch to user.
 */
static inline void
capri_barco_resp_dispatch (capri_barco_ring_t *barco_ring)
{
    barco_response_cb cb;

    cb = barco_ring->user_cb[barco_ring->consumer_idx].resp_handler;
    (*cb)(barco_ring->user_cb[barco_ring->consumer_idx].user_ctx, NULL); // 2nd Param to be fixed

    barco_ring->user_cb[barco_ring->consumer_idx].user_ctx = NULL;
    barco_ring->user_cb[barco_ring->consumer_idx].resp_handler = NULL;
}
#endif

}    // namespace pd
}    // namespace hal

#endif /* __CAPRI_BARCO_RINGS_H__ */
