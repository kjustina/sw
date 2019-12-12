/* SPDX-License-Identifier: GPL-2.0 */
/* Copyright(c) 2017 - 2019 Pensando Systems, Inc */

#ifndef _IONIC_DEV_H_
#define _IONIC_DEV_H_

#include <linux/mutex.h>
#include <linux/workqueue.h>

#include "ionic_if.h"
#include "ionic_api.h"
#include "ionic_regs.h"

#define IONIC_MIN_MTU			ETH_MIN_MTU
#define IONIC_MAX_MTU			9194
#define IONIC_MAX_TXRX_DESC		16384
#define IONIC_MIN_TXRX_DESC		16
#define IONIC_DEF_TXRX_DESC		4096
#define IONIC_LIFS_MAX			1024
#define IONIC_WATCHDOG_SECS		5
#define IONIC_ITR_COAL_USEC_DEFAULT	64

#define IONIC_DEV_CMD_REG_VERSION	1
#define IONIC_DEV_INFO_REG_COUNT	32
#define IONIC_DEV_CMD_REG_COUNT		32

struct ionic_dev_bar {
	void __iomem *vaddr;
	phys_addr_t bus_addr;
	unsigned long len;
	int res_index;
};

static inline void ionic_struct_size_checks(void)
{
	/* Registers */
	BUILD_BUG_ON(sizeof(struct ionic_intr) != 32);

	BUILD_BUG_ON(sizeof(struct doorbell) != 8);
	BUILD_BUG_ON(sizeof(struct intr_ctrl) != 32);
	BUILD_BUG_ON(sizeof(struct intr_status) != 8);

	BUILD_BUG_ON(sizeof(union dev_regs) != 4096);
	BUILD_BUG_ON(sizeof(union dev_info_regs) != 2048);
	BUILD_BUG_ON(sizeof(union dev_cmd_regs) != 2048);

	BUILD_BUG_ON(sizeof(struct lif_stats) != 1024);

	BUILD_BUG_ON(sizeof(struct admin_cmd) != 64);
	BUILD_BUG_ON(sizeof(struct admin_comp) != 16);
	BUILD_BUG_ON(sizeof(struct nop_cmd) != 64);
	BUILD_BUG_ON(sizeof(struct nop_comp) != 16);

	/* Device commands */
	BUILD_BUG_ON(sizeof(struct dev_identify_cmd) != 64);
	BUILD_BUG_ON(sizeof(struct dev_identify_comp) != 16);
	BUILD_BUG_ON(sizeof(struct dev_init_cmd) != 64);
	BUILD_BUG_ON(sizeof(struct dev_init_comp) != 16);
	BUILD_BUG_ON(sizeof(struct dev_reset_cmd) != 64);
	BUILD_BUG_ON(sizeof(struct dev_reset_comp) != 16);
	BUILD_BUG_ON(sizeof(struct dev_getattr_cmd) != 64);
	BUILD_BUG_ON(sizeof(struct dev_getattr_comp) != 16);
	BUILD_BUG_ON(sizeof(struct dev_setattr_cmd) != 64);
	BUILD_BUG_ON(sizeof(struct dev_setattr_comp) != 16);

	/* Port commands */
	BUILD_BUG_ON(sizeof(struct port_identify_cmd) != 64);
	BUILD_BUG_ON(sizeof(struct port_identify_comp) != 16);
	BUILD_BUG_ON(sizeof(struct port_init_cmd) != 64);
	BUILD_BUG_ON(sizeof(struct port_init_comp) != 16);
	BUILD_BUG_ON(sizeof(struct port_reset_cmd) != 64);
	BUILD_BUG_ON(sizeof(struct port_reset_comp) != 16);
	BUILD_BUG_ON(sizeof(struct port_getattr_cmd) != 64);
	BUILD_BUG_ON(sizeof(struct port_getattr_comp) != 16);
	BUILD_BUG_ON(sizeof(struct port_setattr_cmd) != 64);
	BUILD_BUG_ON(sizeof(struct port_setattr_comp) != 16);

	/* LIF commands */
	BUILD_BUG_ON(sizeof(struct lif_init_cmd) != 64);
	BUILD_BUG_ON(sizeof(struct lif_init_comp) != 16);
	BUILD_BUG_ON(sizeof(struct lif_reset_cmd) != 64);
	BUILD_BUG_ON(sizeof(lif_reset_comp) != 16);
	BUILD_BUG_ON(sizeof(struct lif_getattr_cmd) != 64);
	BUILD_BUG_ON(sizeof(struct lif_getattr_comp) != 16);
	BUILD_BUG_ON(sizeof(struct lif_setattr_cmd) != 64);
	BUILD_BUG_ON(sizeof(struct lif_setattr_comp) != 16);

	BUILD_BUG_ON(sizeof(struct q_init_cmd) != 64);
	BUILD_BUG_ON(sizeof(struct q_init_comp) != 16);
	BUILD_BUG_ON(sizeof(struct q_control_cmd) != 64);
	BUILD_BUG_ON(sizeof(q_control_comp) != 16);

	BUILD_BUG_ON(sizeof(struct rx_mode_set_cmd) != 64);
	BUILD_BUG_ON(sizeof(rx_mode_set_comp) != 16);
	BUILD_BUG_ON(sizeof(struct rx_filter_add_cmd) != 64);
	BUILD_BUG_ON(sizeof(struct rx_filter_add_comp) != 16);
	BUILD_BUG_ON(sizeof(struct rx_filter_del_cmd) != 64);
	BUILD_BUG_ON(sizeof(rx_filter_del_comp) != 16);

	/* RDMA commands */
	BUILD_BUG_ON(sizeof(struct rdma_reset_cmd) != 64);
	BUILD_BUG_ON(sizeof(struct rdma_queue_cmd) != 64);

	/* Events */
	BUILD_BUG_ON(sizeof(struct notifyq_cmd) != 4);
	BUILD_BUG_ON(sizeof(union notifyq_comp) != 64);
	BUILD_BUG_ON(sizeof(struct notifyq_event) != 64);
	BUILD_BUG_ON(sizeof(struct link_change_event) != 64);
	BUILD_BUG_ON(sizeof(struct reset_event) != 64);
	BUILD_BUG_ON(sizeof(struct heartbeat_event) != 64);
	BUILD_BUG_ON(sizeof(struct log_event) != 64);

	/* I/O */
	BUILD_BUG_ON(sizeof(struct txq_desc) != 16);
	BUILD_BUG_ON(sizeof(struct txq_sg_desc) != 128);
	BUILD_BUG_ON(sizeof(struct txq_comp) != 16);

	BUILD_BUG_ON(sizeof(struct rxq_desc) != 16);
	BUILD_BUG_ON(sizeof(struct rxq_sg_desc) != 128);
	BUILD_BUG_ON(sizeof(struct rxq_comp) != 16);

	/* SR/IOV */
	BUILD_BUG_ON(sizeof(struct ionic_vf_setattr_cmd) != 64);
	BUILD_BUG_ON(sizeof(struct ionic_vf_setattr_comp) != 16);
	BUILD_BUG_ON(sizeof(struct ionic_vf_getattr_cmd) != 64);
	BUILD_BUG_ON(sizeof(struct ionic_vf_getattr_comp) != 16);
}

struct ionic_dev {
	union dev_info_regs __iomem *dev_info_regs;
	union dev_cmd_regs __iomem *dev_cmd_regs;

	unsigned long last_hb_time;
	u32 last_hb;

	u64 __iomem *db_pages;
	dma_addr_t phy_db_pages;

	struct ionic_intr __iomem *intr_ctrl;
	u64 __iomem *intr_status;
	u8 *msix_cfg_base;

	struct mutex cmb_inuse_lock; /* for cmb_inuse */
	unsigned long *cmb_inuse;
	dma_addr_t phy_cmb_pages;
	u32 cmb_npages;

	u32 port_info_sz;
	struct port_info *port_info;
	dma_addr_t port_info_pa;

	struct ionic_devinfo dev_info;
};

struct ionic_cq_info {
	void *cq_desc;
	struct ionic_cq_info *next;
	unsigned int index;
	bool last;
};

struct ionic_queue;
struct ionic_qcq;
struct ionic_desc_info;

typedef void (*ionic_desc_cb)(struct ionic_queue *q,
			      struct ionic_desc_info *desc_info,
			      struct ionic_cq_info *cq_info, void *cb_arg);

struct ionic_page_info {
	struct page *page;
	dma_addr_t dma_addr;
};

struct ionic_desc_info {
	void *desc;
	void *sg_desc;
	struct ionic_desc_info *next;
	unsigned int index;
	unsigned int left;
	unsigned int npages;
	struct ionic_page_info pages[IONIC_RX_MAX_SG_ELEMS + 1];
	ionic_desc_cb cb;
	void *cb_arg;
};

#define IONIC_QUEUE_NAME_MAX_SZ		32

struct ionic_queue {
	u64 dbell_count;
	u64 drop;
	u64 stop;
	u64 wake;
	struct ionic_lif *lif;
	struct ionic_desc_info *info;
	struct ionic_desc_info *tail;
	struct ionic_desc_info *head;
	struct ionic_dev *idev;
	unsigned int index;
	unsigned int type;
	unsigned int hw_index;
	unsigned int hw_type;
	u64 dbval;
	void *base;
	void *sg_base;
	dma_addr_t base_pa;
	dma_addr_t sg_base_pa;
	unsigned int num_descs;
	unsigned int desc_size;
	unsigned int sg_desc_size;
	unsigned int pid;
	char name[IONIC_QUEUE_NAME_MAX_SZ];
};

#define IONIC_INTR_INDEX_NOT_ASSIGNED	-1
#define IONIC_INTR_NAME_MAX_SZ		32

struct ionic_intr_info {
	char name[IONIC_INTR_NAME_MAX_SZ];
	unsigned int index;
	unsigned int vector;
	u64 rearm_count;
	unsigned int cpu;
	cpumask_t affinity_mask;
};

struct ionic_cq {
	void *base;
	dma_addr_t base_pa;
	struct ionic_lif *lif;
	struct ionic_cq_info *info;
	struct ionic_cq_info *tail;
	struct ionic_queue *bound_q;
	struct ionic_intr_info *bound_intr;
	bool done_color;
	unsigned int num_descs;
	u64 compl_count;
	unsigned int desc_size;
};

struct ionic_eq_ring {
	struct ionic_eq_comp *base;
	dma_addr_t base_pa;

	int index;
	u8 gen_color;
};

struct ionic_eq {
	struct ionic *ionic;
	struct ionic_eq_ring ring[2];
	struct ionic_intr_info intr;

	int index;
	int depth;

	bool is_init;
};

#define IONIC_EQ_DEPTH 0x1000

struct ionic;

static inline void ionic_intr_init(struct ionic_dev *idev,
				   struct ionic_intr_info *intr,
				   unsigned long index)
{
	ionic_intr_clean(idev->intr_ctrl, index);
	intr->index = index;
}

static inline unsigned int ionic_q_space_avail(struct ionic_queue *q)
{
	unsigned int avail = q->tail->index;

	if (q->head->index >= avail)
		avail += q->head->left - 1;
	else
		avail -= q->head->index + 1;

	return avail;
}

static inline bool ionic_q_has_space(struct ionic_queue *q, unsigned int want)
{
	return ionic_q_space_avail(q) >= want;
}

void ionic_init_devinfo(struct ionic *ionic);
int ionic_dev_setup(struct ionic *ionic);
void ionic_dev_teardown(struct ionic *ionic);

void ionic_dev_cmd_go(struct ionic_dev *idev, union dev_cmd *cmd);
u8 ionic_dev_cmd_status(struct ionic_dev *idev);
bool ionic_dev_cmd_done(struct ionic_dev *idev);
void ionic_dev_cmd_comp(struct ionic_dev *idev, union dev_cmd_comp *comp);

void ionic_dev_cmd_identify(struct ionic_dev *idev, u8 ver);
void ionic_dev_cmd_init(struct ionic_dev *idev);
void ionic_dev_cmd_reset(struct ionic_dev *idev);

void ionic_dev_cmd_port_identify(struct ionic_dev *idev);
void ionic_dev_cmd_port_init(struct ionic_dev *idev);
void ionic_dev_cmd_port_reset(struct ionic_dev *idev);
void ionic_dev_cmd_port_state(struct ionic_dev *idev, u8 state);
void ionic_dev_cmd_port_speed(struct ionic_dev *idev, u32 speed);
void ionic_dev_cmd_port_mtu(struct ionic_dev *idev, u32 mtu);
void ionic_dev_cmd_port_autoneg(struct ionic_dev *idev, u8 an_enable);
void ionic_dev_cmd_port_fec(struct ionic_dev *idev, u8 fec_type);
void ionic_dev_cmd_port_pause(struct ionic_dev *idev, u8 pause_type);
void ionic_dev_cmd_port_loopback(struct ionic_dev *idev, u8 loopback_mode);

int ionic_set_vf_config(struct ionic *ionic, int vf, u8 attr, u8 *data);
void ionic_dev_cmd_queue_identify(struct ionic_dev *idev,
				  u16 lif_type, u8 qtype, u8 qver);
void ionic_dev_cmd_lif_identify(struct ionic_dev *idev, u8 type, u8 ver);
void ionic_dev_cmd_lif_init(struct ionic_dev *idev, u16 lif_index,
			    dma_addr_t addr);
void ionic_dev_cmd_lif_reset(struct ionic_dev *idev, u16 lif_index);
void ionic_dev_cmd_adminq_init(struct ionic_dev *idev, struct ionic_qcq *qcq,
			       u16 lif_index, u16 intr_index);

char *ionic_dev_asic_name(u8 asic_type);
int ionic_db_page_num(struct ionic_lif *lif, int pid);

int ionic_eqs_alloc(struct ionic *ionic);
void ionic_eqs_free(struct ionic *ionic);
void ionic_eqs_deinit(struct ionic *ionic);
int ionic_eqs_init(struct ionic *ionic);

int ionic_cq_init(struct ionic_lif *lif, struct ionic_cq *cq,
		  struct ionic_intr_info *intr,
		  unsigned int num_descs, size_t desc_size);
void ionic_cq_map(struct ionic_cq *cq, void *base, dma_addr_t base_pa);
void ionic_cq_bind(struct ionic_cq *cq, struct ionic_queue *q);
typedef bool (*ionic_cq_cb)(struct ionic_cq *cq, struct ionic_cq_info *cq_info);
typedef void (*ionic_cq_done_cb)(void *done_arg);
unsigned int ionic_cq_service(struct ionic_cq *cq, unsigned int work_to_do,
			      ionic_cq_cb cb, ionic_cq_done_cb done_cb,
			      void *done_arg);

int ionic_q_init(struct ionic_lif *lif, struct ionic_dev *idev,
		 struct ionic_queue *q, unsigned int index, const char *name,
		 unsigned int num_descs, size_t desc_size,
		 size_t sg_desc_size, unsigned int pid);
void ionic_q_map(struct ionic_queue *q, void *base, dma_addr_t base_pa);
void ionic_q_sg_map(struct ionic_queue *q, void *base, dma_addr_t base_pa);
void ionic_q_post(struct ionic_queue *q, bool ring_doorbell, ionic_desc_cb cb,
		  void *cb_arg);
void ionic_q_rewind(struct ionic_queue *q, struct ionic_desc_info *start);
void ionic_q_service(struct ionic_queue *q, struct ionic_cq_info *cq_info,
		     unsigned int stop_index);
int ionic_heartbeat_check(struct ionic *ionic);

#endif /* _IONIC_DEV_H_ */
