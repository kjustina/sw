#include <base.h>
#include <arpa/inet.h>
#include <hal_lock.hpp>
#include <pd_api.hpp>
#include <tcpcb_pd.hpp>
#include <p4pd_tcp_proxy_api.h>
#include <capri_loader.h>
#include <capri_hbm.hpp>
#include <wring_pd.hpp>
#include <proxy.hpp>
#include <hal.hpp>
#include <lif_manager.hpp>

namespace hal {
namespace pd {

void *
tcpcb_pd_get_hw_key_func (void *entry)
{
    HAL_ASSERT(entry != NULL);
    return (void *)&(((pd_tcpcb_t *)entry)->hw_id);
}

uint32_t
tcpcb_pd_compute_hw_hash_func (void *key, uint32_t ht_size)
{
    return hal::utils::hash_algo::fnv_hash(key, sizeof(tcpcb_hw_id_t)) % ht_size;
}

bool
tcpcb_pd_compare_hw_key_func (void *key1, void *key2)
{
    HAL_ASSERT((key1 != NULL) && (key2 != NULL));
    if (*(tcpcb_hw_id_t *)key1 == *(tcpcb_hw_id_t *)key2) {
        return true;
    }
    return false;
}

/********************************************
 * RxDMA
 * ******************************************/

hal_ret_t
p4pd_get_tcp_rx_stage0_prog_addr(uint64_t* offset)
{
    char progname[] = "rxdma_stage0.bin";
    char labelname[]= "tcp_rx_stage0";

    int ret = capri_program_label_to_offset("p4plus",
                                            progname,
                                            labelname,
                                            offset);
    if(ret < 0) {
        return HAL_RET_HW_FAIL;
    }
    *offset >>= MPU_PC_ADDR_SHIFT;
    return HAL_RET_OK;
}

static hal_ret_t 
p4pd_add_or_del_tcp_rx_read_tx2rx_entry(pd_tcpcb_t* tcpcb_pd, bool del)
{
    tcp_rx_read_tx2rx_d             data = {0};
    hal_ret_t                       ret = HAL_RET_OK;
    //uint64_t                        pc_offset;

    // hardware index for this entry
    tcpcb_hw_id_t hwid = tcpcb_pd->hw_id + 
        (P4PD_TCPCB_STAGE_ENTRY_OFFSET * P4PD_HWID_TCP_RX_READ_TX2RX);

    if(!del) {
        uint64_t pc_offset;
        // get pc address
        if(p4pd_get_tcp_rx_stage0_prog_addr(&pc_offset) != HAL_RET_OK) {
            HAL_TRACE_ERR("Failed to get pc address");
            ret = HAL_RET_HW_FAIL;
        }
        HAL_TRACE_DEBUG("Received pc address 0x{0:x}", pc_offset);
        data.action_id = pc_offset;
        data.u.read_tx2rx_d.snd_nxt = tcpcb_pd->tcpcb->snd_nxt;
        data.u.read_tx2rx_d.prr_out = 0xFEEDBABA;
        HAL_TRACE_DEBUG("TCPCB snd_nxt: 0x{0:x}", data.u.read_tx2rx_d.snd_nxt);
    }
    HAL_TRACE_DEBUG("Programming tx2rx at hw-id: 0x{0:x}", hwid); 
    if(!p4plus_hbm_write(hwid,  (uint8_t *)&data, sizeof(data))){
        HAL_TRACE_ERR("Failed to create rx: read_tx2rx entry for TCP CB");
        ret = HAL_RET_HW_FAIL;
    }
    return ret;
}

hal_ret_t 
p4pd_add_or_del_tcp_rx_tcp_rx_entry(pd_tcpcb_t* tcpcb_pd, bool del)
{
    tcp_rx_tcp_rx_d             data = {0};
    hal_ret_t                   ret = HAL_RET_OK;

    // hardware index for this entry
    tcpcb_hw_id_t hwid = tcpcb_pd->hw_id + 
        (P4PD_TCPCB_STAGE_ENTRY_OFFSET * P4PD_HWID_TCP_RX_TCP_RX);

    if(!del) {
        data.u.tcp_rx_d.rcv_nxt = tcpcb_pd->tcpcb->rcv_nxt;
        data.u.tcp_rx_d.snd_una = tcpcb_pd->tcpcb->snd_una;
        data.u.tcp_rx_d.rcv_tsval = tcpcb_pd->tcpcb->rcv_tsval;
        data.u.tcp_rx_d.ts_recent = tcpcb_pd->tcpcb->ts_recent;
        if (tcpcb_pd->tcpcb->debug_dol) {
            data.u.tcp_rx_d.debug_dol = 0x1;
        }
        HAL_TRACE_DEBUG("TCPCB rcv_nxt: 0x{0:x}", data.u.tcp_rx_d.rcv_nxt);
        HAL_TRACE_DEBUG("TCPCB snd_una: 0x{0:x}", data.u.tcp_rx_d.snd_una);
        HAL_TRACE_DEBUG("TCPCB rcv_tsval: 0x{0:x}", data.u.tcp_rx_d.rcv_tsval);
        HAL_TRACE_DEBUG("TCPCB ts_recent: 0x{0:x}", data.u.tcp_rx_d.ts_recent);
        HAL_TRACE_DEBUG("TCPCB _debug_dol: 0x{0:x}", data.u.tcp_rx_d.debug_dol);
        // Get Serq address
        wring_hw_id_t  serq_base;
        ret = wring_pd_get_base_addr(types::WRING_TYPE_SERQ,
                                     tcpcb_pd->tcpcb->cb_id,
                                     &serq_base);
        if(ret != HAL_RET_OK) {
            HAL_TRACE_ERR("Failed to receive serq base for tcp cb: {}", 
                        tcpcb_pd->tcpcb->cb_id);
        } else {
            HAL_TRACE_DEBUG("Serq base: 0x{0:x}", serq_base);
            data.u.tcp_rx_d.serq_base = htonl(serq_base);    
        }
    }
    int size = sizeof(tcp_rx_tcp_rx_d);
    HAL_TRACE_DEBUG("Programming tcp_rx at hw-id: 0x{0:x}", hwid);
    HAL_TRACE_DEBUG("Programming tcp_rx at size: 0x{0:x}", size);
    
    if(!p4plus_hbm_write(hwid, (uint8_t *)&data, size)) {
        HAL_TRACE_ERR("Failed to create rx: tcp_rx entry for TCP CB");
        ret = HAL_RET_HW_FAIL;
    }
    return ret;
}

hal_ret_t 
p4pd_add_or_del_tcp_rx_tcp_rtt_entry(pd_tcpcb_t* tcpcb_pd, bool del)
{
    tcp_rx_tcp_rtt_d   data = {0};
    hal_ret_t          ret = HAL_RET_OK;

    // hardware index for this entry
    tcpcb_hw_id_t hwid = tcpcb_pd->hw_id + 
        (P4PD_TCPCB_STAGE_ENTRY_OFFSET * P4PD_HWID_TCP_RX_RTT);

    if(!del) {
        data.u.tcp_rtt_d.rto = 0x30;
        data.u.tcp_rtt_d.srtt_us = 0x80;
        data.u.tcp_rtt_d.seq_rtt_us = 0x10;
        data.u.tcp_rtt_d.ca_rtt_us = 0x10;
        data.u.tcp_rtt_d.curr_ts = 0xf0;
        data.u.tcp_rtt_d.rtt_min = 0x1;
        data.u.tcp_rtt_d.rttvar_us = 0x20;
        data.u.tcp_rtt_d.mdev_us = 0x20;
        data.u.tcp_rtt_d.mdev_max_us = 0;
        data.u.tcp_rtt_d.rtt_seq = 0x20;
    }
    
    if(!p4plus_hbm_write(hwid,  (uint8_t *)&data, sizeof(data))){
        HAL_TRACE_ERR("Failed to create rx: tcp_rtt entry for TCP CB");
        ret = HAL_RET_HW_FAIL;
    }
    return ret;
}


hal_ret_t 
p4pd_add_or_del_tcp_rx_tcp_fra_entry(pd_tcpcb_t* tcpcb_pd, bool del)
{
    tcp_rx_tcp_fra_d   data = {0};
    hal_ret_t                   ret = HAL_RET_OK;
    
    // hardware index for this entry
    tcpcb_hw_id_t hwid = tcpcb_pd->hw_id + 
        (P4PD_TCPCB_STAGE_ENTRY_OFFSET * P4PD_HWID_TCP_RX_TCP_FRA);

    if(!del) {
        data.u.tcp_fra_d.ca_state = 0x2;
        data.u.tcp_fra_d.high_seq = 0xEFEFEFEF;
    }
    
    if(!p4plus_hbm_write(hwid,  (uint8_t *)&data, sizeof(data))){
        HAL_TRACE_ERR("Failed to create rx: tcp_fra entry for TCP CB");
        ret = HAL_RET_HW_FAIL;
    }
    return ret;
}


hal_ret_t 
p4pd_add_or_del_tcp_rx_tcp_cc_entry(pd_tcpcb_t* tcpcb_pd, bool del)
{
    tcp_rx_tcp_cc_d   data = {0};
    hal_ret_t                  ret = HAL_RET_OK;

    // hardware index for this entry
    tcpcb_hw_id_t hwid = tcpcb_pd->hw_id + 
        (P4PD_TCPCB_STAGE_ENTRY_OFFSET * P4PD_HWID_TCP_RX_TCP_CC);

    if(!del) {
        data.u.tcp_cc_d.snd_cwnd = 0x10;
        data.u.tcp_cc_d.max_packets_out = 0x07;
        data.u.tcp_cc_d.is_cwnd_limited = 0x00;
        data.u.tcp_cc_d.last_max_cwnd = 0x16;
    }
    
    if(!p4plus_hbm_write(hwid,  (uint8_t *)&data, sizeof(data))){
        HAL_TRACE_ERR("Failed to create rx: tcp_cc entry for TCP CB");
        ret = HAL_RET_HW_FAIL;
    }
    return ret;
}

hal_ret_t 
p4pd_add_or_del_tcp_rx_tcp_fc_entry(pd_tcpcb_t* tcpcb_pd, bool del)
{
    tcp_rx_tcp_fc_d   data = {0};
    hal_ret_t                  ret = HAL_RET_OK;

    // hardware index for this entry
    tcpcb_hw_id_t hwid = tcpcb_pd->hw_id + 
        (P4PD_TCPCB_STAGE_ENTRY_OFFSET * P4PD_HWID_TCP_RX_TCP_FC);

    if(!del) {
        data.u.tcp_fc_d.page_cnt = 0x1000;
    }
    
    if(!p4plus_hbm_write(hwid,  (uint8_t *)&data, sizeof(data))){
        HAL_TRACE_ERR("Failed to create rx: tcp_cc entry for TCP CB");
        ret = HAL_RET_HW_FAIL;
    }
    return ret;
}



hal_ret_t 
p4pd_add_or_del_tcpcb_rxdma_entry(pd_tcpcb_t* tcpcb_pd, bool del)
{
    hal_ret_t   ret = HAL_RET_OK;

    ret = p4pd_add_or_del_tcp_rx_read_tx2rx_entry(tcpcb_pd, del);
    if(ret != HAL_RET_OK) {
        goto cleanup;
    }

    ret = p4pd_add_or_del_tcp_rx_tcp_rx_entry(tcpcb_pd, del);
    if(ret != HAL_RET_OK) {
        goto cleanup;
    }

    ret = p4pd_add_or_del_tcp_rx_tcp_rtt_entry(tcpcb_pd, del);
    if(ret != HAL_RET_OK) {
        goto cleanup;
    }
    
    ret = p4pd_add_or_del_tcp_rx_tcp_fra_entry(tcpcb_pd, del);
    if(ret != HAL_RET_OK) {
        goto cleanup;
    }
 
    ret = p4pd_add_or_del_tcp_rx_tcp_cc_entry(tcpcb_pd, del);
    if(ret != HAL_RET_OK) {
        goto cleanup;
    }

    ret = p4pd_add_or_del_tcp_rx_tcp_fc_entry(tcpcb_pd, del);
    if(ret != HAL_RET_OK) {
        goto cleanup;
    }


    return HAL_RET_OK;
cleanup:
    /* TODO: CLEANUP */
    return ret;
}

hal_ret_t 
p4pd_get_tcp_rx_tcp_rx_entry(pd_tcpcb_t* tcpcb_pd)
{
    tcp_rx_tcp_rx_d    data = {0};

    // hardware index for this entry
    tcpcb_hw_id_t hwid = tcpcb_pd->hw_id + 
        (P4PD_TCPCB_STAGE_ENTRY_OFFSET * P4PD_HWID_TCP_RX_TCP_RX);

    if(!p4plus_hbm_read(hwid,  (uint8_t *)&data, sizeof(data))){
        HAL_TRACE_ERR("Failed to get rx: tcp_rx entry for TCP CB");
        return HAL_RET_HW_FAIL;
    }
    tcpcb_pd->tcpcb->rcv_nxt = data.u.tcp_rx_d.rcv_nxt;
    tcpcb_pd->tcpcb->snd_una = data.u.tcp_rx_d.snd_una;
    tcpcb_pd->tcpcb->rcv_tsval = data.u.tcp_rx_d.rcv_tsval;
    tcpcb_pd->tcpcb->ts_recent = data.u.tcp_rx_d.ts_recent;
    tcpcb_pd->tcpcb->serq_base = data.u.tcp_rx_d.serq_base;
    tcpcb_pd->tcpcb->debug_dol = data.u.tcp_rx_d.debug_dol;

    HAL_TRACE_DEBUG("Received serq_base: 0x{0:x}", tcpcb_pd->tcpcb->serq_base);

    return HAL_RET_OK;
}

hal_ret_t 
p4pd_get_tcpcb_rxdma_entry(pd_tcpcb_t* tcpcb_pd)
{
    hal_ret_t   ret = HAL_RET_OK;
    
    ret = p4pd_get_tcp_rx_tcp_rx_entry(tcpcb_pd);
    if(ret != HAL_RET_OK) {
        HAL_TRACE_ERR("Failed to get tcp_rx entry");
        goto cleanup;
    }
    return HAL_RET_OK;
cleanup:
    /* TODO: CLEANUP */
    return ret;
}

/********************************************
 * TxDMA
 * ******************************************/

hal_ret_t
p4pd_get_tcp_tx_stage0_prog_addr(uint64_t* offset)
{
    char progname[] = "txdma_stage0.bin";
    char labelname[]= "tcp_tx_stage0";

    int ret = capri_program_label_to_offset("p4plus",
                                            progname,
                                            labelname,
                                            offset);
    if(ret < 0) {
        return HAL_RET_HW_FAIL;
    }
    *offset >>= MPU_PC_ADDR_SHIFT;
    return HAL_RET_OK;
}

hal_ret_t 
p4pd_add_or_del_tcp_tx_read_rx2tx_entry(pd_tcpcb_t* tcpcb_pd, bool del)
{
    tcp_tx_read_rx2tx_d   data = {0};
    hal_ret_t                      ret = HAL_RET_OK;

    // hardware index for this entry
    tcpcb_hw_id_t hwid = tcpcb_pd->hw_id + 
        (P4PD_TCPCB_STAGE_ENTRY_OFFSET * P4PD_HWID_TCP_TX_READ_RX2TX);
    
    if(!del) {
        uint64_t pc_offset;
        // get pc address
        if(p4pd_get_tcp_tx_stage0_prog_addr(&pc_offset) != HAL_RET_OK) {
            HAL_TRACE_ERR("Failed to get pc address");
            // ret = HAL_RET_HW_FAIL;
        }
        HAL_TRACE_DEBUG("Received pc address 0x{0:x}", pc_offset);
        data.action_id = pc_offset;
        data.u.read_rx2tx_d.total = 1;

        // get sesq address
        wring_hw_id_t   sesq_base;
        ret = wring_pd_get_base_addr(types::WRING_TYPE_SESQ,
                                     tcpcb_pd->tcpcb->cb_id,
                                     &sesq_base);
        if(ret != HAL_RET_OK) {
            HAL_TRACE_ERR("Failed to receive sesq base for tcp cb: {}", 
                        tcpcb_pd->tcpcb->cb_id);
        } else {
            HAL_TRACE_DEBUG("Sesq base: 0x{0:x}", sesq_base);
            data.u.read_rx2tx_d.sesq_base = sesq_base;
        }

    }
    if(!p4plus_hbm_write(hwid,  (uint8_t *)&data, P4PD_TCPCB_STAGE_ENTRY_OFFSET)){
        HAL_TRACE_ERR("Failed to create tx: read_rx2tx entry for TCP CB");
        ret = HAL_RET_HW_FAIL;
    }
    return ret;
}

hal_ret_t 
p4pd_add_or_del_tcp_tx_read_rx2tx_extra_entry(pd_tcpcb_t* tcpcb_pd, bool del)
{
    tcp_tx_read_rx2tx_extra_d      data = {0};
    hal_ret_t                               ret = HAL_RET_OK;

    // hardware index for this entry
    tcpcb_hw_id_t hwid = tcpcb_pd->hw_id + 
        (P4PD_TCPCB_STAGE_ENTRY_OFFSET * P4PD_HWID_TCP_TX_READ_RX2TX_EXTRA);
    
    if(!del) {
    }
    if(!p4plus_hbm_write(hwid,  (uint8_t *)&data, P4PD_TCPCB_STAGE_ENTRY_OFFSET)){
        HAL_TRACE_ERR("Failed to create tx: read_rx2tx entry for TCP CB");
        ret = HAL_RET_HW_FAIL;
    }
    return ret;
}


hal_ret_t 
p4pd_add_or_del_tcp_tx_tcp_tx_entry(pd_tcpcb_t* tcpcb_pd, bool del)
{
    tcp_tx_tcp_tx_d                     data = {0};
    hal_ret_t                           ret = HAL_RET_OK;

    // hardware index for this entry
    tcpcb_hw_id_t hwid = tcpcb_pd->hw_id + 
        (P4PD_TCPCB_STAGE_ENTRY_OFFSET * P4PD_HWID_TCP_TX_TCP_TX);
    
    if(!del) {
    }
    if(!p4plus_hbm_write(hwid,  (uint8_t *)&data, P4PD_TCPCB_STAGE_ENTRY_OFFSET)){
        HAL_TRACE_ERR("Failed to create tx: read_rx2tx entry for TCP CB");
        ret = HAL_RET_HW_FAIL;
    }
    return ret;
}

#define __MAX(a, b) ((a) > (b) ? (a) : (b))

hal_ret_t 
p4pd_add_or_del_tcp_tx_header_template_entry(pd_tcpcb_t* tcpcb_pd, bool del)
{
    uint8_t                             data[64];
    hal_ret_t                           ret = HAL_RET_OK;

    // hardware index for this entry
    tcpcb_hw_id_t hwid = tcpcb_pd->hw_id + 
        (P4PD_TCPCB_STAGE_ENTRY_OFFSET * P4PD_HWID_TCP_TX_HEADER_TEMPLATE);
    
    if(!del) {
#if 1
		// TODO UNHACK this
//INFO:     16:     eeff00000300
//INFO:     24: eeff0000028100e0
//INFO:     32: 0208004507007c00
//INFO:     40: 0100004006fa7140
//INFO:     48: 00000140000002b8
//INFO:     56: a90050babababaef
//INFO:     64: efefef50002000d3
//INFO:     72: a00000da1a004001
		uint8_t hdr[] = {
			0x00, 0xee, 0xff, 0x00, 0x00, 0x03,  // dmac
			0x00, 0xee, 0xff, 0x00, 0x00, 0x02, // smac
			0x08, 0x00,
			// ip header
			0x45, 0x08, 0x00, 0x7c, 0x00, 0x01, 0x00, 0x00,
			0x40, 0x06, 0xfa, 0x71, 0x40, 0x00, 0x00, 0x01,
			0x40, 0x00, 0x00, 0x02,
			// tcp header
			0xb8, 0xa9, 0x00, 0x50, 0xba, 0xba, 0xba, 0xba,
			0xef, 0xef, 0xef, 0xef, 0x50, 0x00, 0x20, 0x00,
			0xd3, 0xa0, 0x00, 0x00,
		};
		memcpy(data, hdr, MAX(sizeof(data), sizeof(hdr)));
#endif
    }
    if(!p4plus_hbm_write(hwid,  (uint8_t *)&data, P4PD_TCPCB_STAGE_ENTRY_OFFSET)){
        HAL_TRACE_ERR("Failed to create tx: read_rx2tx entry for TCP CB");
        ret = HAL_RET_HW_FAIL;
    }
    return ret;
}
hal_ret_t 
p4pd_add_or_del_tcpcb_txdma_entry(pd_tcpcb_t* tcpcb_pd, bool del)
{
    hal_ret_t   ret = HAL_RET_OK;

    ret = p4pd_add_or_del_tcp_tx_read_rx2tx_entry(tcpcb_pd, del);
    if(ret != HAL_RET_OK) {
        goto cleanup;
    }
    
    ret = p4pd_add_or_del_tcp_tx_read_rx2tx_extra_entry(tcpcb_pd, del);
    if(ret != HAL_RET_OK) {
        goto cleanup;
    }
    ret = p4pd_add_or_del_tcp_tx_tcp_tx_entry(tcpcb_pd, del);
    if(ret != HAL_RET_OK) {
        goto cleanup;
    }
    ret = p4pd_add_or_del_tcp_tx_header_template_entry(tcpcb_pd, del);
    if(ret != HAL_RET_OK) {
        goto cleanup;
    }
 
    return HAL_RET_OK;

cleanup:

    /* TODO: Cleanup */
    return ret;
}

hal_ret_t
p4pd_get_tcp_tx_read_rx2tx_entry(pd_tcpcb_t *tcpcb_pd)
{
    tcp_tx_read_rx2tx_d   data = {0};

    // hardware index for this entry
    tcpcb_hw_id_t hwid = tcpcb_pd->hw_id +
        (P4PD_TCPCB_STAGE_ENTRY_OFFSET * P4PD_HWID_TCP_TX_READ_RX2TX);

    if(!p4plus_hbm_read(hwid,  (uint8_t *)&data, sizeof(data))){
        HAL_TRACE_ERR("Failed to get tx: tcp_tx_read_rx2tx_entry for TCP CB");
        return HAL_RET_HW_FAIL;
    }
    tcpcb_pd->tcpcb->sesq_pi = data.u.read_rx2tx_d.pi_0;
    tcpcb_pd->tcpcb->sesq_ci = data.u.read_rx2tx_d.ci_0;
    return HAL_RET_OK;
}

hal_ret_t 
p4pd_get_tcpcb_txdma_entry(pd_tcpcb_t* tcpcb_pd)
{
    hal_ret_t   ret = HAL_RET_OK;

    ret = p4pd_get_tcp_tx_read_rx2tx_entry(tcpcb_pd);
    if(ret != HAL_RET_OK) {
        goto cleanup;
    }

cleanup:
    return ret;
}

/**************************/

tcpcb_hw_id_t
pd_tcpcb_get_base_hw_index(pd_tcpcb_t* tcpcb_pd)
{
    HAL_ASSERT(NULL != tcpcb_pd);
    HAL_ASSERT(NULL != tcpcb_pd->tcpcb);
    
    // Get the base address of TCP CB from LIF Manager.
    // Set qtype and qid as 0 to get the start offset. 
    uint64_t offset = g_lif_manager->GetLIFQStateAddr(SERVICE_LIF_TCP_PROXY, 0, 0);
    HAL_TRACE_DEBUG("received offset 0x{0:x}", offset);
    return offset + \
        (tcpcb_pd->tcpcb->cb_id * P4PD_HBM_TCP_CB_ENTRY_SIZE);
}

hal_ret_t
p4pd_add_or_del_tcpcb_entry(pd_tcpcb_t* tcpcb_pd, bool del) 
{
    hal_ret_t                   ret = HAL_RET_OK;
 
    ret = p4pd_add_or_del_tcpcb_rxdma_entry(tcpcb_pd, del);
    if(ret != HAL_RET_OK) {
        goto err;    
    }
   
    ret = p4pd_add_or_del_tcpcb_txdma_entry(tcpcb_pd, del);
    if(ret != HAL_RET_OK) {
        goto err;    
    }

err:
    return ret;
}

static
hal_ret_t
p4pd_get_tcpcb_entry(pd_tcpcb_t* tcpcb_pd) 
{
    hal_ret_t                   ret = HAL_RET_OK;
    
    ret = p4pd_get_tcpcb_rxdma_entry(tcpcb_pd);
    if(ret != HAL_RET_OK) {
        HAL_TRACE_ERR("Failed to get rxdma entry for tcpcb");
        goto err;    
    }
   
    ret = p4pd_get_tcpcb_txdma_entry(tcpcb_pd);
    if(ret != HAL_RET_OK) {
        HAL_TRACE_ERR("Failed to get txdma entry for tcpcb");
        goto err;    
    }

err:
    /*TODO: cleanup */
    return ret;
}

/********************************************
 * APIs
 *******************************************/

hal_ret_t
pd_tcpcb_create (pd_tcpcb_args_t *args)
{
    hal_ret_t               ret;
    pd_tcpcb_s              *tcpcb_pd;

    HAL_TRACE_DEBUG("Creating pd state for TCP CB.");

    // allocate PD tcpcb state
    tcpcb_pd = tcpcb_pd_alloc_init();
    if (tcpcb_pd == NULL) {
        return HAL_RET_OOM;
    }
    HAL_TRACE_DEBUG("Alloc done");
    tcpcb_pd->tcpcb = args->tcpcb;
    // get hw-id for this TCPCB
    tcpcb_pd->hw_id = pd_tcpcb_get_base_hw_index(tcpcb_pd);
    printf("Received hw-id: 0x%lx ", tcpcb_pd->hw_id);
    
    // program tcpcb
    ret = p4pd_add_or_del_tcpcb_entry(tcpcb_pd, false);
    if(ret != HAL_RET_OK) {
        goto cleanup;    
    }
    HAL_TRACE_DEBUG("Programming done");
    // add to db
    ret = add_tcpcb_pd_to_db(tcpcb_pd);
    if (ret != HAL_RET_OK) {
       goto cleanup;
    }
    HAL_TRACE_DEBUG("DB add done");
    args->tcpcb->pd = tcpcb_pd;

    return HAL_RET_OK;

cleanup:

    if (tcpcb_pd) {
        tcpcb_pd_free(tcpcb_pd);
    }
    return ret;
}

hal_ret_t
pd_tcpcb_update (pd_tcpcb_args_t *args)
{
    hal_ret_t               ret;
    
    if(!args) {
       return HAL_RET_INVALID_ARG; 
    }

    tcpcb_t*                tcpcb = args->tcpcb;
    pd_tcpcb_t*             tcpcb_pd = (pd_tcpcb_t*)tcpcb->pd;

    HAL_TRACE_DEBUG("TCPCB pd update");
    
    // program tcpcb
    ret = p4pd_add_or_del_tcpcb_entry(tcpcb_pd, false);
    if(ret != HAL_RET_OK) {
        HAL_TRACE_ERR("Failed to update tcpcb");
    }
    return ret;
}

hal_ret_t
pd_tcpcb_delete (pd_tcpcb_args_t *args)
{
    hal_ret_t               ret;
    
    if(!args) {
       return HAL_RET_INVALID_ARG; 
    }

    tcpcb_t*                tcpcb = args->tcpcb;
    pd_tcpcb_t*             tcpcb_pd = (pd_tcpcb_t*)tcpcb->pd;

    HAL_TRACE_DEBUG("TCPCB pd delete");
    
    // program tcpcb
    ret = p4pd_add_or_del_tcpcb_entry(tcpcb_pd, true);
    if(ret != HAL_RET_OK) {
        HAL_TRACE_ERR("Failed to delete tcpcb entry"); 
    }
    
    del_tcpcb_pd_from_db(tcpcb_pd);

    tcpcb_pd_free(tcpcb_pd);

    return ret;
}

hal_ret_t
pd_tcpcb_get (pd_tcpcb_args_t *args)
{
    hal_ret_t               ret;
    pd_tcpcb_t              tcpcb_pd;

    HAL_TRACE_DEBUG("TCPCB pd get for id: {}", args->tcpcb->cb_id);

    // allocate PD tcpcb state
    tcpcb_pd_init(&tcpcb_pd);
    tcpcb_pd.tcpcb = args->tcpcb;
    
    // get hw-id for this TCPCB
    tcpcb_pd.hw_id = pd_tcpcb_get_base_hw_index(&tcpcb_pd);
    HAL_TRACE_DEBUG("Received hw-id 0x{0:x}", tcpcb_pd.hw_id);

    // get hw tcpcb entry
    ret = p4pd_get_tcpcb_entry(&tcpcb_pd);
    if(ret != HAL_RET_OK) {
        HAL_TRACE_ERR("Get request failed for id: 0x{0:x}", tcpcb_pd.tcpcb->cb_id);
    }
    return ret;
}

}    // namespace pd
}    // namespace hal
