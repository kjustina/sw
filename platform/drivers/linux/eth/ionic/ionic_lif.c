// SPDX-License-Identifier: GPL-2.0
/* Copyright(c) 2017 - 2019 Pensando Systems, Inc */

#include <linux/netdevice.h>
#include <linux/etherdevice.h>
#include <linux/interrupt.h>
#include <linux/pci.h>
#include <linux/cpumask.h>
#include <linux/if_macvlan.h>

#include "ionic.h"
#include "ionic_bus.h"
#include "ionic_api.h"
#include "ionic_lif.h"
#include "ionic_txrx.h"
#include "ionic_ethtool.h"
#include "ionic_debugfs.h"

static void ionic_lif_rx_mode(struct lif *lif, unsigned int rx_mode);
static int ionic_lif_addr_add(struct lif *lif, const u8 *addr);
static int ionic_lif_addr_del(struct lif *lif, const u8 *addr);
static void ionic_link_status_check(struct lif *lif);

static int ionic_lif_stop(struct lif *lif);
static struct lif *ionic_lif_alloc(struct ionic *ionic, unsigned int index);
static int ionic_lif_init(struct lif *lif);
static int ionic_txrx_alloc(struct lif *lif);
static int ionic_txrx_init(struct lif *lif);
static void ionic_lif_handle_fw_down(struct lif *lif);
static void ionic_lif_free(struct lif *lif);
static void ionic_lif_qcq_deinit(struct lif *lif, struct qcq *qcq);
static void ionic_lif_deinit(struct lif *lif);
static void ionic_qcq_free(struct lif *lif, struct qcq *qcq);
static int ionic_lif_txqs_init(struct lif *lif);
static int ionic_lif_rxqs_init(struct lif *lif);
static int ionic_station_set(struct lif *lif);
static int ionic_lif_rss_init(struct lif *lif);
static int ionic_lif_rss_deinit(struct lif *lif);
static void ionic_lif_set_netdev_info(struct lif *lif);
static int ionic_intr_remaining(struct ionic *ionic);
static int ionic_set_nic_features(struct lif *lif, netdev_features_t features);
static int ionic_notifyq_clean(struct lif *lif, int budget);

static void ionic_lif_deferred_work(struct work_struct *work)
{
	struct lif *lif = container_of(work, struct lif, deferred.work);
	struct deferred *def = &lif->deferred;
	struct deferred_work *w = NULL;

	spin_lock_bh(&def->lock);
	if (!list_empty(&def->list)) {
		w = list_first_entry(&def->list, struct deferred_work, list);
		list_del(&w->list);
	}
	spin_unlock_bh(&def->lock);

	if (w) {
		switch (w->type) {
		case DW_TYPE_RX_MODE:
			ionic_lif_rx_mode(lif, w->rx_mode);
			break;
		case DW_TYPE_RX_ADDR_ADD:
			ionic_lif_addr_add(lif, w->addr);
			break;
		case DW_TYPE_RX_ADDR_DEL:
			ionic_lif_addr_del(lif, w->addr);
			break;
		case DW_TYPE_LINK_STATUS:
			ionic_link_status_check(lif);
			break;
		case DW_TYPE_LIF_RESET:
			/* FW_DOWN event is only handled by mnic in fw */
			if (ionic_is_platform_dev(lif->ionic)) {
				netdev_info(lif->netdev, "Handling the LIF_RESET event\n");
				ionic_lif_handle_fw_down(lif);
			} else {
				netdev_info(lif->netdev, "Ignoring the LIF_RESET event\n");
			}
			break;
		};
		kfree(w);
		schedule_work(&def->work);
	}
}

static void ionic_lif_deferred_enqueue(struct deferred *def,
				       struct deferred_work *work)
{
	spin_lock_bh(&def->lock);
	list_add_tail(&work->list, &def->list);
	spin_unlock_bh(&def->lock);
	schedule_work(&def->work);
}

static int ionic_qcq_enable(struct qcq *qcq)
{
	struct queue *q = &qcq->q;
	struct lif *lif = q->lif;
	struct device *dev = lif->ionic->dev;
	struct ionic_dev *idev = &lif->ionic->idev;
	struct ionic_admin_ctx ctx = {
		.work = COMPLETION_INITIALIZER_ONSTACK(ctx.work),
		.cmd.q_control = {
			.opcode = CMD_OPCODE_Q_CONTROL,
			.lif_index = cpu_to_le16(lif->index),
			.type = q->type,
			.index = cpu_to_le32(q->index),
			.oper = IONIC_Q_ENABLE,
		},
	};

	dev_dbg(dev, "q_enable.index %d q_enable.qtype %d\n",
		ctx.cmd.q_control.index, ctx.cmd.q_control.type);

	if (qcq->flags & QCQ_F_INTR) {
		irq_set_affinity_hint(qcq->intr.vector,
				      &qcq->intr.affinity_mask);
		napi_enable(&qcq->napi);
		ionic_intr_clean(idev->intr_ctrl, qcq->intr.index);
		ionic_intr_mask(idev->intr_ctrl, qcq->intr.index,
				IONIC_INTR_MASK_CLEAR);
	}

	return ionic_adminq_post_wait(lif, &ctx);
}

static int ionic_qcq_disable(struct qcq *qcq)
{
	struct queue *q = &qcq->q;
	struct lif *lif = q->lif;
	struct device *dev = lif->ionic->dev;
	struct ionic_dev *idev = &lif->ionic->idev;
	struct ionic_admin_ctx ctx = {
		.work = COMPLETION_INITIALIZER_ONSTACK(ctx.work),
		.cmd.q_control = {
			.opcode = CMD_OPCODE_Q_CONTROL,
			.lif_index = cpu_to_le16(lif->index),
			.type = q->type,
			.index = cpu_to_le32(q->index),
			.oper = IONIC_Q_DISABLE,
		},
	};

	dev_dbg(dev, "q_disable.index %d q_disable.qtype %d\n",
		ctx.cmd.q_control.index, ctx.cmd.q_control.type);

	if (qcq->flags & QCQ_F_INTR) {
		ionic_intr_mask(idev->intr_ctrl, qcq->intr.index,
				IONIC_INTR_MASK_SET);
		synchronize_irq(qcq->intr.vector);
		irq_set_affinity_hint(qcq->intr.vector, NULL);
		napi_disable(&qcq->napi);
	}

	return ionic_adminq_post_wait(lif, &ctx);
}

static int ionic_lif_open(struct lif *lif)
{
	unsigned int i;
	int err;

	dev_dbg(lif->ionic->dev, "%s: %s\n", __func__, lif->name);
	err = ionic_txrx_alloc(lif);
	if (err)
		return err;

	err = ionic_txrx_init(lif);
	if (err)
		goto err_out;

	for (i = 0; i < lif->nxqs; i++) {
		err = ionic_qcq_enable(lif->txqcqs[i].qcq);
		if (err)
			goto err_out;

		ionic_rx_fill(&lif->rxqcqs[i].qcq->q);
		err = ionic_qcq_enable(lif->rxqcqs[i].qcq);
		if (err)
			goto err_out;
	}

	if (!is_master_lif(lif) && lif->upper_dev &&
	    netif_running(lif->ionic->master_lif->netdev)) {
		netif_carrier_on(lif->upper_dev);
		netif_tx_wake_all_queues(lif->upper_dev);
	}
	set_bit(LIF_UP, lif->state);

	return 0;

err_out:
	ionic_lif_stop(lif);
	return err;
}

int ionic_open(struct net_device *netdev)
{
	struct lif *lif = netdev_priv(netdev);
	struct list_head *cur, *tmp;
	struct lif *slif;
	int err;

	netif_carrier_off(netdev);

	err = ionic_lif_open(lif);
	if (err)
		return err;

	ionic_link_status_check(lif);
	if (netif_carrier_ok(netdev))
		netif_tx_wake_all_queues(netdev);

	list_for_each_safe(cur, tmp, &lif->ionic->lifs) {
		slif = list_entry(cur, struct lif, list);
		if (!is_master_lif(slif))
			ionic_lif_open(slif);
	}

	return 0;
}

static int ionic_lif_stop(struct lif *lif)
{
	struct net_device *ndev;
	unsigned int i;
	int err = 0;

	if (!test_bit(LIF_UP, lif->state)) {
		dev_dbg(lif->ionic->dev, "%s: %s state=DOWN\n",
			__func__, lif->name);
		return 0;
	}
	dev_dbg(lif->ionic->dev, "%s: %s state=UP\n", __func__, lif->name);
	clear_bit(LIF_UP, lif->state);

	if (!is_master_lif(lif) && lif->upper_dev)
		ndev = lif->upper_dev;
	else
		ndev = lif->netdev;

	/* carrier off before disabling queues to avoid watchdog timeout */
	netif_carrier_off(ndev);
	netif_tx_stop_all_queues(ndev);
	netif_tx_disable(ndev);
	synchronize_rcu();

	for (i = 0; i < lif->nxqs; i++) {
		if (lif->rxqcqs[i].qcq) {
			err = ionic_qcq_disable(lif->rxqcqs[i].qcq);
			if (err)
				break;
		}
		if (lif->txqcqs[i].qcq) {
			err = ionic_qcq_disable(lif->txqcqs[i].qcq);
			if (err)
				break;
		}
	}

	for (i = 0; i < lif->nxqs; i++) {
		if (lif->txqcqs[i].qcq) {
			ionic_tx_flush(&lif->txqcqs[i].qcq->cq);
			ionic_lif_qcq_deinit(lif, lif->txqcqs[i].qcq);
		}
		if (lif->rxqcqs[i].qcq) {
			ionic_rx_flush(&lif->rxqcqs[i].qcq->cq);
			ionic_lif_qcq_deinit(lif, lif->rxqcqs[i].qcq);
		}
	}

	for (i = 0; i < lif->nxqs; i++) {
		if (lif->txqcqs[i].qcq) {
			ionic_qcq_free(lif, lif->txqcqs[i].qcq);
			lif->txqcqs[i].qcq = NULL;
		}
		if (lif->rxqcqs[i].qcq) {
			ionic_rx_empty(&lif->rxqcqs[i].qcq->q);
			ionic_qcq_free(lif, lif->rxqcqs[i].qcq);
			lif->rxqcqs[i].qcq = NULL;
		}
	}

	return err;
}

static void ionic_slaves_stop(struct ionic *ionic)
{
	struct list_head *cur, *tmp;
	struct lif *lif;

	list_for_each_safe(cur, tmp, &ionic->lifs) {
		lif = list_entry(cur, struct lif, list);
		if (!is_master_lif(lif))
			ionic_lif_stop(lif);
	}
}

int ionic_stop(struct net_device *netdev)
{
	struct lif *lif = netdev_priv(netdev);

	ionic_slaves_stop(lif->ionic);

	return ionic_lif_stop(lif);
}

int ionic_reset_queues(struct lif *lif)
{
	bool running;
	int err = 0;

	/* Put off the next watchdog timeout */
#ifdef HAVE_NETIF_TRANS_UPDATE
	netif_trans_update(lif->netdev);
#else
	lif->netdev->trans_start = jiffies;
#endif

	while (test_and_set_bit(LIF_QUEUE_RESET, lif->state))
		usleep_range(100, 200);

	running = netif_running(lif->netdev);
	if (running)
		err = ionic_stop(lif->netdev);
	if (!err && running)
		ionic_open(lif->netdev);

	clear_bit(LIF_QUEUE_RESET, lif->state);

	return err;
}

static bool ionic_adminq_service(struct cq *cq, struct cq_info *cq_info)
{
	struct admin_comp *comp = cq_info->cq_desc;

	if (!color_match(comp->color, cq->done_color))
		return false;

	ionic_q_service(cq->bound_q, cq_info, le16_to_cpu(comp->comp_index));

	return true;
}

static int ionic_adminq_napi(struct napi_struct *napi, int budget)
{
	struct lif *lif = napi_to_cq(napi)->lif;
	int n_work = 0;
	int a_work = 0;

	if (likely(lif->notifyqcq && lif->notifyqcq->flags & QCQ_F_INITED))
		n_work = ionic_notifyq_clean(lif, budget);
	a_work = ionic_napi(napi, budget, ionic_adminq_service, NULL, NULL);

	return max(n_work, a_work);
}

static void ionic_link_status_check(struct lif *lif)
{
	struct net_device *netdev = lif->netdev;
	u16 link_status;
	bool link_up;

	clear_bit(LIF_LINK_CHECK_NEEDED, lif->state);

	link_status = le16_to_cpu(lif->info->status.link_status);
	link_up = link_status == PORT_OPER_STATUS_UP;

	/* filter out the no-change cases */
	if ((link_up && netif_carrier_ok(netdev)) ||
	    (!link_up && !netif_carrier_ok(netdev)))
		return;

	if (link_up) {
		netdev_info(netdev, "Link up - %d Gbps\n",
			    le32_to_cpu(lif->info->status.link_speed) / 1000);

		if (test_bit(LIF_UP, lif->state)) {
			netif_tx_wake_all_queues(lif->netdev);
			netif_carrier_on(netdev);
		}
	} else {
		netdev_info(netdev, "Link down\n");

		/* carrier off first to avoid watchdog timeout */
		netif_carrier_off(netdev);
		if (test_bit(LIF_UP, lif->state))
			netif_tx_stop_all_queues(netdev);
	}

	/* TODO: Propagate link_status to other lifs on
	 *       this ionic device.
	 */
}

static bool ionic_notifyq_service(struct cq *cq, struct cq_info *cq_info)
{
	union notifyq_comp *comp = cq_info->cq_desc;
	struct net_device *netdev;
	struct queue *q;
	struct lif *lif;
	struct deferred_work *work;
	u64 eid;

	q = cq->bound_q;
	lif = q->info[0].cb_arg;
	netdev = lif->netdev;
	eid = le64_to_cpu(comp->event.eid);

	/* Have we run out of new completions to process? */
	if (!(eid > lif->last_eid))
		return false;

	lif->last_eid = eid;

	dev_dbg(lif->ionic->dev, "notifyq event:\n");
	dynamic_hex_dump("event ", DUMP_PREFIX_OFFSET, 16, 1,
			 comp, sizeof(*comp), true);

	switch (le16_to_cpu(comp->event.ecode)) {
	case EVENT_OPCODE_LINK_CHANGE:
		netdev_info(netdev, "Notifyq EVENT_OPCODE_LINK_CHANGE eid=%lld\n",
			    eid);
		netdev_info(netdev,
			    "  link_status=%d link_speed=%d\n",
			    le16_to_cpu(comp->link_change.link_status),
			    le32_to_cpu(comp->link_change.link_speed));

		set_bit(LIF_LINK_CHECK_NEEDED, lif->state);

		break;
	case EVENT_OPCODE_RESET:
		netdev_info(netdev, "Notifyq EVENT_OPCODE_RESET eid=%lld\n",
			    eid);
		netdev_info(netdev, "  reset_code=%d state=%d\n",
			    comp->reset.reset_code,
			    comp->reset.state);

		work = kzalloc(sizeof(*work), GFP_ATOMIC);
		if (!work) {
			netdev_err(lif->netdev, "%s OOM\n", __func__);
		} else {
			work->type = DW_TYPE_LIF_RESET;
			ionic_lif_deferred_enqueue(&lif->deferred, work);
		}

		break;
	case EVENT_OPCODE_HEARTBEAT:
		netdev_info(netdev, "Notifyq EVENT_OPCODE_HEARTBEAT eid=%lld\n",
			    eid);
		break;
	case EVENT_OPCODE_LOG:
		netdev_info(netdev, "Notifyq EVENT_OPCODE_LOG eid=%lld\n", eid);
		print_hex_dump(KERN_INFO, "notifyq ", DUMP_PREFIX_OFFSET, 16, 1,
			       comp->log.data, sizeof(comp->log.data), true);
		break;
	default:
		netdev_warn(netdev, "Notifyq bad event ecode=%d eid=%lld\n",
			    comp->event.ecode, eid);
		break;
	}

	return true;
}

static int ionic_notifyq_clean(struct lif *lif, int budget)
{
	struct ionic_dev *idev = &lif->ionic->idev;
	struct cq *cq = &lif->notifyqcq->cq;
	u32 work_done;

	work_done = ionic_cq_service(cq, budget, ionic_notifyq_service,
				     NULL, NULL);
	if (work_done)
		ionic_intr_credits(idev->intr_ctrl, cq->bound_intr->index,
				   work_done, IONIC_INTR_CRED_RESET_COALESCE);

	/* If we ran out of budget, there are more events
	 * to process and napi will reschedule us soon
	 */
	if (work_done == budget)
		goto return_to_napi;

	/* After outstanding events are processed we can check on
	 * the link status and any outstanding interrupt credits.
	 *
	 * We wait until here to check on the link status in case
	 * there was a long list of link events from a flap episode.
	 */
	if (test_bit(LIF_LINK_CHECK_NEEDED, lif->state)) {
		struct deferred_work *work;

		work = kzalloc(sizeof(*work), GFP_ATOMIC);
		if (!work) {
			netdev_err(lif->netdev, "%s OOM\n", __func__);
		} else {
			work->type = DW_TYPE_LINK_STATUS;
			ionic_lif_deferred_enqueue(&lif->deferred, work);
		}
	}

return_to_napi:
	return work_done;
}

#ifdef HAVE_VOID_NDO_GET_STATS64
static void ionic_get_stats64(struct net_device *netdev,
			      struct rtnl_link_stats64 *ns)
#else
static struct rtnl_link_stats64 *ionic_get_stats64(struct net_device *netdev,
						   struct rtnl_link_stats64 *ns)
#endif
{
	struct lif *lif = netdev_priv(netdev);
	struct lif_stats *ls = &lif->info->stats;

	memset(ns, 0, sizeof(*ns));

	ns->rx_packets = le64_to_cpu(ls->rx_ucast_packets) +
			 le64_to_cpu(ls->rx_mcast_packets) +
			 le64_to_cpu(ls->rx_bcast_packets);

	ns->tx_packets = le64_to_cpu(ls->tx_ucast_packets) +
			 le64_to_cpu(ls->tx_mcast_packets) +
			 le64_to_cpu(ls->tx_bcast_packets);

	ns->rx_bytes = le64_to_cpu(ls->rx_ucast_bytes) +
		       le64_to_cpu(ls->rx_mcast_bytes) +
		       le64_to_cpu(ls->rx_bcast_bytes);

	ns->tx_bytes = le64_to_cpu(ls->tx_ucast_bytes) +
		       le64_to_cpu(ls->tx_mcast_bytes) +
		       le64_to_cpu(ls->tx_bcast_bytes);

	ns->rx_dropped = le64_to_cpu(ls->rx_ucast_drop_packets) +
			 le64_to_cpu(ls->rx_mcast_drop_packets) +
			 le64_to_cpu(ls->rx_bcast_drop_packets);

	ns->tx_dropped = le64_to_cpu(ls->tx_ucast_drop_packets) +
			 le64_to_cpu(ls->tx_mcast_drop_packets) +
			 le64_to_cpu(ls->tx_bcast_drop_packets);

	ns->multicast = le64_to_cpu(ls->rx_mcast_packets);

	ns->rx_over_errors = le64_to_cpu(ls->rx_queue_empty);

	ns->rx_missed_errors = le64_to_cpu(ls->rx_dma_error) +
			       le64_to_cpu(ls->rx_queue_disabled) +
			       le64_to_cpu(ls->rx_desc_fetch_error) +
			       le64_to_cpu(ls->rx_desc_data_error);

	ns->tx_aborted_errors = le64_to_cpu(ls->tx_dma_error) +
				le64_to_cpu(ls->tx_queue_disabled) +
				le64_to_cpu(ls->tx_desc_fetch_error) +
				le64_to_cpu(ls->tx_desc_data_error);

	ns->rx_errors = ns->rx_over_errors +
			ns->rx_missed_errors;

	ns->tx_errors = ns->tx_aborted_errors;

#ifndef HAVE_VOID_NDO_GET_STATS64
	return ns;
#endif
}

static int ionic_lif_addr_add(struct lif *lif, const u8 *addr)
{
	struct ionic_admin_ctx ctx = {
		.work = COMPLETION_INITIALIZER_ONSTACK(ctx.work),
		.cmd.rx_filter_add = {
			.opcode = CMD_OPCODE_RX_FILTER_ADD,
			.lif_index = cpu_to_le16(lif->index),
			.match = cpu_to_le16(RX_FILTER_MATCH_MAC),
		},
	};
	struct rx_filter *f;
	int err;

	/* don't bother if we already have it */
	spin_lock_bh(&lif->rx_filters.lock);
	f = ionic_rx_filter_by_addr(lif, addr);
	spin_unlock_bh(&lif->rx_filters.lock);
	if (f)
		return 0;

	/* make sure we're not getting a slave's filter */
	/* TODO: use a global hash rather than search every slave */
	if (is_master_lif(lif)) {
		struct list_head *cur, *tmp;
		struct lif *slave_lif;

		list_for_each_safe(cur, tmp, &lif->ionic->lifs) {
			slave_lif = list_entry(cur, struct lif, list);
			spin_lock_bh(&slave_lif->rx_filters.lock);
			f = ionic_rx_filter_by_addr(slave_lif, addr);
			spin_unlock_bh(&slave_lif->rx_filters.lock);
			if (f)
				return 0;
		}
	}

	netdev_info(lif->netdev, "rx_filter add ADDR %pM (id %d)\n", addr,
		    ctx.comp.rx_filter_add.filter_id);

	memcpy(ctx.cmd.rx_filter_add.mac.addr, addr, ETH_ALEN);
	err = ionic_adminq_post_wait(lif, &ctx);
	if (err)
		return err;

	return ionic_rx_filter_save(lif, 0, RXQ_INDEX_ANY, 0, &ctx);
}

static int ionic_lif_addr_del(struct lif *lif, const u8 *addr)
{
	struct ionic_admin_ctx ctx = {
		.work = COMPLETION_INITIALIZER_ONSTACK(ctx.work),
		.cmd.rx_filter_del = {
			.opcode = CMD_OPCODE_RX_FILTER_DEL,
			.lif_index = cpu_to_le16(lif->index),
		},
	};
	struct rx_filter *f;
	int err;

	spin_lock_bh(&lif->rx_filters.lock);
	f = ionic_rx_filter_by_addr(lif, addr);
	if (!f) {
		spin_unlock_bh(&lif->rx_filters.lock);
		return -ENOENT;
	}

	ctx.cmd.rx_filter_del.filter_id = cpu_to_le32(f->filter_id);
	ionic_rx_filter_free(lif, f);
	spin_unlock_bh(&lif->rx_filters.lock);

	err = ionic_adminq_post_wait(lif, &ctx);
	if (err)
		return err;

	netdev_info(lif->netdev, "rx_filter del ADDR %pM (id %d)\n", addr,
		    ctx.cmd.rx_filter_del.filter_id);

	return 0;
}

static int ionic_lif_addr(struct lif *lif, const u8 *addr, bool add)
{
	struct ionic *ionic = lif->ionic;
	struct deferred_work *work;
	unsigned int nmfilters;
	unsigned int nufilters;

	if (add) {
		/* Do we have space for this filter?  We test the counters
		 * here before checking the need for deferral so that we
		 * can return an overflow error to the stack.
		 */
		nmfilters = le32_to_cpu(ionic->ident.lif.eth.max_mcast_filters);
		nufilters = le32_to_cpu(ionic->ident.lif.eth.max_ucast_filters);

		if ((is_multicast_ether_addr(addr) && lif->nmcast < nmfilters))
			lif->nmcast++;
		else if (!is_multicast_ether_addr(addr) &&
			 lif->nucast < nufilters)
			lif->nucast++;
		else
			return -ENOSPC;
	} else {
		if (is_multicast_ether_addr(addr) && lif->nmcast)
			lif->nmcast--;
		else if (!is_multicast_ether_addr(addr) && lif->nucast)
			lif->nucast--;
	}

	if (in_interrupt()) {
		work = kzalloc(sizeof(*work), GFP_ATOMIC);
		if (!work) {
			netdev_err(lif->netdev, "%s OOM\n", __func__);
			return -ENOMEM;
		}
		work->type = add ? DW_TYPE_RX_ADDR_ADD : DW_TYPE_RX_ADDR_DEL;
		memcpy(work->addr, addr, ETH_ALEN);
		netdev_dbg(lif->netdev, "deferred: rx_filter %s %pM\n",
			   add ? "add" : "del", addr);
		ionic_lif_deferred_enqueue(&lif->deferred, work);
	} else {
		netdev_dbg(lif->netdev, "rx_filter %s %pM\n",
			   add ? "add" : "del", addr);
		if (add)
			return ionic_lif_addr_add(lif, addr);
		else
			return ionic_lif_addr_del(lif, addr);
	}

	return 0;
}

static int ionic_addr_add(struct net_device *netdev, const u8 *addr)
{
	return ionic_lif_addr(netdev_priv(netdev), addr, true);
}

static int ionic_addr_del(struct net_device *netdev, const u8 *addr)
{
	return ionic_lif_addr(netdev_priv(netdev), addr, false);
}

static void ionic_lif_rx_mode(struct lif *lif, unsigned int rx_mode)
{
	struct ionic_admin_ctx ctx = {
		.work = COMPLETION_INITIALIZER_ONSTACK(ctx.work),
		.cmd.rx_mode_set = {
			.opcode = CMD_OPCODE_RX_MODE_SET,
			.lif_index = cpu_to_le16(lif->index),
			.rx_mode = cpu_to_le16(rx_mode),
		},
	};
	char buf[128];
	int err;
	int i;
#define REMAIN(__x) (sizeof(buf) - (__x))

	i = snprintf(buf, sizeof(buf), "rx_mode 0x%04x -> 0x%04x:",
		     lif->rx_mode, rx_mode);
	if (rx_mode & RX_MODE_F_UNICAST)
		i += snprintf(&buf[i], REMAIN(i), " RX_MODE_F_UNICAST");
	if (rx_mode & RX_MODE_F_MULTICAST)
		i += snprintf(&buf[i], REMAIN(i), " RX_MODE_F_MULTICAST");
	if (rx_mode & RX_MODE_F_BROADCAST)
		i += snprintf(&buf[i], REMAIN(i), " RX_MODE_F_BROADCAST");
	if (rx_mode & RX_MODE_F_PROMISC)
		i += snprintf(&buf[i], REMAIN(i), " RX_MODE_F_PROMISC");
	if (rx_mode & RX_MODE_F_ALLMULTI)
		i += snprintf(&buf[i], REMAIN(i), " RX_MODE_F_ALLMULTI");
	netdev_info(lif->netdev, "lif%d %s\n", lif->index, buf);

	err = ionic_adminq_post_wait(lif, &ctx);
	if (err)
		netdev_warn(lif->netdev, "set rx_mode 0x%04x failed: %d\n",
			    rx_mode, err);
	else
		lif->rx_mode = rx_mode;
}

static void _ionic_lif_rx_mode(struct lif *lif, unsigned int rx_mode)
{
	struct deferred_work *work;

	if (in_interrupt()) {
		work = kzalloc(sizeof(*work), GFP_ATOMIC);
		if (!work) {
			netdev_err(lif->netdev, "%s OOM\n", __func__);
			return;
		}
		work->type = DW_TYPE_RX_MODE;
		work->rx_mode = rx_mode;
		netdev_dbg(lif->netdev, "deferred: rx_mode\n");
		ionic_lif_deferred_enqueue(&lif->deferred, work);
	} else {
		ionic_lif_rx_mode(lif, rx_mode);
	}
}

static void ionic_set_rx_mode(struct net_device *netdev)
{
	struct lif *lif = netdev_priv(netdev);
	struct identity *ident = &lif->ionic->ident;
	unsigned int nfilters;
	unsigned int rx_mode;

	rx_mode = RX_MODE_F_UNICAST;
	rx_mode |= (netdev->flags & IFF_MULTICAST) ? RX_MODE_F_MULTICAST : 0;
	rx_mode |= (netdev->flags & IFF_BROADCAST) ? RX_MODE_F_BROADCAST : 0;
	rx_mode |= (netdev->flags & IFF_PROMISC) ? RX_MODE_F_PROMISC : 0;
	rx_mode |= (netdev->flags & IFF_ALLMULTI) ? RX_MODE_F_ALLMULTI : 0;

	/* sync unicast addresses
	 * next check to see if we're in an overflow state
	 *    if so, we track that we overflowed and enable NIC PROMISC
	 *    else if the overflow is set and not needed
	 *       we remove our overflow flag and check the netdev flags
	 *       to see if we can disable NIC PROMISC
	 */
	__dev_uc_sync(netdev, ionic_addr_add, ionic_addr_del);
	nfilters = le32_to_cpu(ident->lif.eth.max_ucast_filters);
	if (netdev_uc_count(netdev) + 1 > nfilters) {
		rx_mode |= RX_MODE_F_PROMISC;
		lif->uc_overflow = true;
	} else if (lif->uc_overflow) {
		lif->uc_overflow = false;
		if (!(netdev->flags & IFF_PROMISC))
			rx_mode &= ~RX_MODE_F_PROMISC;
	}

	/* same for multicast */
	__dev_mc_sync(netdev, ionic_addr_add, ionic_addr_del);
	nfilters = le32_to_cpu(ident->lif.eth.max_mcast_filters);
	if (netdev_mc_count(netdev) > nfilters) {
		rx_mode |= RX_MODE_F_ALLMULTI;
		lif->mc_overflow = true;
	} else if (lif->mc_overflow) {
		lif->mc_overflow = false;
		if (!(netdev->flags & IFF_ALLMULTI))
			rx_mode &= ~RX_MODE_F_ALLMULTI;
	}

	if (lif->rx_mode != rx_mode)
		_ionic_lif_rx_mode(lif, rx_mode);
}

static int ionic_set_features(struct net_device *netdev,
			      netdev_features_t features)
{
	struct lif *lif = netdev_priv(netdev);
	int err;

	netdev_dbg(netdev, "%s: lif->features=0x%08llx new_features=0x%08llx\n",
		   __func__, (u64)lif->netdev->features, (u64)features);

	err = ionic_set_nic_features(lif, features);

	return err;
}

static int ionic_set_mac_address(struct net_device *netdev, void *sa)
{
	struct sockaddr *addr = sa;
	u8 *mac = (u8 *)addr->sa_data;

	if (ether_addr_equal(netdev->dev_addr, mac))
		return 0;

	if (!is_valid_ether_addr(mac))
		return -EADDRNOTAVAIL;

	if (!is_zero_ether_addr(netdev->dev_addr)) {
		netdev_info(netdev, "deleting mac addr %pM\n",
			    netdev->dev_addr);
		ionic_addr_del(netdev, netdev->dev_addr);
	}

	memcpy(netdev->dev_addr, mac, netdev->addr_len);
	netdev_info(netdev, "updating mac addr %pM\n", mac);

	return ionic_addr_add(netdev, mac);
}

static int ionic_mnic_change_mtu(struct net_device *netdev, int new_mtu)
{
	netdev_err(netdev, "MTU change not allowed on mnic device\n");
	return -EOPNOTSUPP;
}

static int ionic_change_mtu(struct net_device *netdev, int new_mtu)
{
	struct lif *lif = netdev_priv(netdev);
	struct ionic_admin_ctx ctx = {
		.work = COMPLETION_INITIALIZER_ONSTACK(ctx.work),
		.cmd.lif_setattr = {
			.opcode = CMD_OPCODE_LIF_SETATTR,
			.index = cpu_to_le16(lif->index),
			.attr = IONIC_LIF_ATTR_MTU,
			.mtu = cpu_to_le32(new_mtu),
		},
	};
	int err;

	if (new_mtu < IONIC_MIN_MTU || new_mtu > IONIC_MAX_MTU) {
		netdev_err(netdev, "Invalid MTU %d\n", new_mtu);
		return -EINVAL;
	}

	err = ionic_adminq_post_wait(lif, &ctx);
	if (err)
		return err;

	netdev->mtu = new_mtu;
	err = ionic_reset_queues(lif);

	return err;
}

static void ionic_tx_timeout_work(struct work_struct *ws)
{
	struct lif *lif = container_of(ws, struct lif, tx_timeout_work);

	netdev_info(lif->netdev, "Tx Timeout recovery\n");
	ionic_reset_queues(lif);
}

static void ionic_tx_timeout(struct net_device *netdev)
{
	struct lif *lif = netdev_priv(netdev);

	schedule_work(&lif->tx_timeout_work);
}

static int ionic_vlan_rx_add_vid(struct net_device *netdev, __be16 proto,
				 u16 vid)
{
	struct lif *lif = netdev_priv(netdev);
	struct ionic_admin_ctx ctx = {
		.work = COMPLETION_INITIALIZER_ONSTACK(ctx.work),
		.cmd.rx_filter_add = {
			.opcode = CMD_OPCODE_RX_FILTER_ADD,
			.lif_index = cpu_to_le16(lif->index),
			.match = cpu_to_le16(RX_FILTER_MATCH_VLAN),
			.vlan.vlan = cpu_to_le16(vid),
		},
	};
	int err;

	err = ionic_adminq_post_wait(lif, &ctx);
	if (err)
		return err;

	netdev_info(netdev, "rx_filter add VLAN %d (id %d)\n", vid,
		    ctx.comp.rx_filter_add.filter_id);

	return ionic_rx_filter_save(lif, 0, RXQ_INDEX_ANY, 0, &ctx);
}

static int ionic_vlan_rx_kill_vid(struct net_device *netdev, __be16 proto,
				  u16 vid)
{
	struct lif *lif = netdev_priv(netdev);
	struct ionic_admin_ctx ctx = {
		.work = COMPLETION_INITIALIZER_ONSTACK(ctx.work),
		.cmd.rx_filter_del = {
			.opcode = CMD_OPCODE_RX_FILTER_DEL,
			.lif_index = cpu_to_le16(lif->index),
		},
	};
	struct rx_filter *f;
	int err;

	spin_lock_bh(&lif->rx_filters.lock);

	f = ionic_rx_filter_by_vlan(lif, vid);
	if (!f) {
		spin_unlock_bh(&lif->rx_filters.lock);
		return -ENOENT;
	}

	netdev_info(netdev, "rx_filter del VLAN %d (id %d)\n", vid,
		    le32_to_cpu(ctx.cmd.rx_filter_del.filter_id));

	ctx.cmd.rx_filter_del.filter_id = cpu_to_le32(f->filter_id);
	ionic_rx_filter_free(lif, f);
	spin_unlock_bh(&lif->rx_filters.lock);

	err = ionic_adminq_post_wait(lif, &ctx);
	if (err)
		return err;

	return 0;
}

static int ionic_slave_alloc(struct ionic *ionic)
{
	int index;

	/* slave index starts at 1, master_lif is 0 */
	index = find_first_zero_bit(ionic->lifbits, ionic->nslaves);
	if (index > ionic->nslaves)
		return -ENOSPC;

	set_bit(index, ionic->lifbits);

	return index;
}

static void ionic_slave_free(struct ionic *ionic, int index)
{
	if (index >= ionic->nslaves)
		return;
	clear_bit(index, ionic->lifbits);
}

static void *ionic_dfwd_add_station(struct net_device *lower_dev,
				    struct net_device *upper_dev)
{
	struct lif *master_lif = netdev_priv(lower_dev);
	struct ionic *ionic = master_lif->ionic;
	union lif_identity *lid;
	struct lif *lif;
	int lif_index;
	int nqueues;
	int err;

	if (!macvlan_supports_dest_filter(upper_dev))
		return NULL;

	/* slaves need 2 interrupts - adminq and txrx queue pair */
	if (ionic_intr_remaining(ionic) < 2) {
		netdev_info(lower_dev, "insufficient device interrupts left for macvlan offload\n");
		return NULL;
	}

	/* For now, we need to assure we don't try to set up for multiqueue
	 * macvlan channels.  Sometime in the future this will help us set
	 * up for those multiqueue channels.
	 */
	lid = kzalloc(sizeof(*lid), GFP_KERNEL);
	if (!lid)
		return NULL;
	ionic_lif_identify(ionic, IONIC_LIF_TYPE_MACVLAN, lid);
	nqueues = le32_to_cpu(lid->eth.config.queue_count[IONIC_QTYPE_RXQ]);
	kfree(lid);
	lid = NULL;

	if (nqueues > 1)
		netdev_warn(lower_dev, "Only 1 queue used per slave LIF\n");

	/* master_lif index is 0, slave index starts at 1 */
	lif_index = ionic_slave_alloc(ionic);
	if (lif_index < 0) {
		netdev_info(lower_dev, "no lifs left for macvlan offload: %d, max=%d\n",
			    lif_index, ionic->nslaves);
		return NULL;
	}
	netdev_info(lower_dev, "slave index %d for macvlan dev %s\n",
		    lif_index, upper_dev->name);

	lif = ionic_lif_alloc(ionic, lif_index);
	if (IS_ERR(lif)) {
		ionic_slave_free(ionic, lif_index);
		return NULL;
	}

	lif->upper_dev = upper_dev;
	err = ionic_lif_init(lif);
	if (err) {
		netdev_err(lower_dev, "Cannot init slave lif %d for %s: %d\n",
			   lif_index, upper_dev->name, err);
		goto err_out_free_slave;
	}

	ionic_lif_set_netdev_info(lif);
	_ionic_lif_rx_mode(lif, master_lif->rx_mode);
	ionic_lif_addr(lif, upper_dev->dev_addr, true);

	if (test_bit(LIF_UP, master_lif->state)) {
		err = ionic_lif_open(lif);
		if (err)
			goto err_out_deinit_slave;
	}

	netdev_set_sb_channel(upper_dev, lif_index);

	/* bump up the netdev's in-use queue count if needed */
	if ((master_lif->nxqs + lif_index) > lower_dev->real_num_tx_queues) {
		int max = lower_dev->real_num_tx_queues + 1;

		netif_set_real_num_tx_queues(lower_dev, max);
	}

	netdev_info(lower_dev, "%s: %s %s\n",
		    __func__, lif->name, lif->upper_dev->name);

#ifndef HAVE_MACVLAN_SB_DEV
	/* WARNING - UGLY HACK */
	/* This is to work around a bug in versions of the macvlan
	 * driver prior to v4.18, where macvlan_open() doesn't call
	 * macvlan_hash_add() in the case of an offload macvlan.  This
	 * results in vlan->hlist not being initialized and eventually
	 * causing NULL pointer violations.
	 * The code below is hijacked from the macvlan driver, since
	 * it is defined static and unaccessible.
	 */
	{
#define MACVLAN_HASH_SIZE	(1<<MACVLAN_HASH_BITS)
#define MACVLAN_HASH_BITS	8
		struct macvlan_port {
			struct net_device	*dev;
			struct hlist_head	vlan_hash[MACVLAN_HASH_SIZE];
			struct list_head	vlans;
			struct sk_buff_head	bc_queue;
			struct work_struct	bc_work;
			u32			flags;
			int			count;
			struct hlist_head	vlan_source_hash[MACVLAN_HASH_SIZE];
			DECLARE_BITMAP(mc_filter, MACVLAN_MC_FILTER_SZ);
			unsigned char           perm_addr[ETH_ALEN];
		};

		struct macvlan_dev *vlan = netdev_priv(upper_dev);
		struct macvlan_port *port = (void *)vlan->port;
		const unsigned char *addr = vlan->dev->dev_addr;
		u32 idx;
		u64 value = get_unaligned((u64 *)addr);

		/* only want 6 bytes */
#ifdef __BIG_ENDIAN
		value >>= 16;
#else
		value <<= 16;
#endif
		idx = hash_64(value, MACVLAN_HASH_BITS);
		hlist_add_head_rcu(&vlan->hlist, &port->vlan_hash[idx]);
	}
#endif

	return lif;

err_out_deinit_slave:
	ionic_lif_deinit(lif);
err_out_free_slave:
	ionic_lif_free(lif);

	return NULL;
}

static void ionic_dfwd_del_station(struct net_device *lower_dev, void *priv)
{
	struct lif *master_lif = netdev_priv(lower_dev);
	struct lif *lif = priv;
	unsigned long lif_index = lif->index;
#ifndef HAVE_MACVLAN_SB_DEV
	/* get vlan* now before lif is dismantled */
	struct macvlan_dev *vlan = netdev_priv(lif->upper_dev);
#endif

	netdev_info(lower_dev, "%s: %s %s\n",
		    __func__, lif->name, lif->upper_dev->name);
	netdev_unbind_sb_channel(lower_dev, lif->netdev);

	ionic_lif_stop(lif);
	ionic_lif_deinit(lif);
	ionic_lif_free(lif);

	/* if this was the highest slot, we can decrement
	 * the number of queues in use and find the next
	 * highest one in use
	 */
	if ((master_lif->nxqs + lif_index) == lower_dev->real_num_tx_queues) {
		int max = lower_dev->real_num_tx_queues;

		while (!master_lif->txqcqs[max-1].qcq)
			max--;
		netif_set_real_num_tx_queues(lower_dev, max);
		qdisc_reset_all_tx(lower_dev);
	}

#ifndef HAVE_MACVLAN_SB_DEV
	/* WARNING - UGLY HACK part deux */
	/* This is to work around a bug in versions of the macvlan
	 * driver prior to v4.18, where macvlan_stop() doesn't call
	 * macvlan_hash_del() in the case of an offload macvlan.  This
	 * results in vlan->hlist not being cleaned up and eventually
	 * causing havoc.
	 * The code below is hijacked from the macvlan driver, since
	 * it is defined static and unaccessible.
	 */
	{
		hlist_del_rcu(&vlan->hlist);
		synchronize_rcu();
	}
#endif
}

static const struct net_device_ops ionic_netdev_ops = {
	.ndo_open               = ionic_open,
	.ndo_stop               = ionic_stop,
	.ndo_start_xmit		= ionic_start_xmit,
#ifndef HAVE_NDO_SELECT_QUEUE_SB_DEV
	.ndo_select_queue	= ionic_select_queue,
#endif
	.ndo_get_stats64	= ionic_get_stats64,
	.ndo_set_rx_mode	= ionic_set_rx_mode,
	.ndo_set_features	= ionic_set_features,
	.ndo_set_mac_address	= ionic_set_mac_address,
	.ndo_validate_addr	= eth_validate_addr,
#ifdef HAVE_RHEL7_EXTENDED_MIN_MAX_MTU
	.extended.ndo_change_mtu = ionic_change_mtu,
#else
	.ndo_change_mtu         = ionic_change_mtu,
#endif
	.ndo_tx_timeout         = ionic_tx_timeout,
	.ndo_vlan_rx_add_vid    = ionic_vlan_rx_add_vid,
	.ndo_vlan_rx_kill_vid   = ionic_vlan_rx_kill_vid,

#ifdef HAVE_RHEL7_NET_DEVICE_OPS_EXT
	.extended.ndo_dfwd_add_station = ionic_dfwd_add_station,
	.extended.ndo_dfwd_del_station = ionic_dfwd_del_station,
#else
	.ndo_dfwd_add_station	= ionic_dfwd_add_station,
	.ndo_dfwd_del_station	= ionic_dfwd_del_station,
#endif

#ifdef HAVE_RHEL7_NET_DEVICE_OPS_EXT
/* RHEL7 requires this to be defined to enable extended ops.  RHEL7 uses the
 * function get_ndo_ext to retrieve offsets for extended fields from with the
 * net_device_ops struct and ndo_size is checked to determine whether or not
 * the offset is valid.
 */
	.ndo_size		= sizeof(const struct net_device_ops),
#endif
};

static const struct net_device_ops ionic_mnic_netdev_ops = {
	.ndo_open               = ionic_open,
	.ndo_stop               = ionic_stop,
	.ndo_start_xmit		= ionic_start_xmit,
	.ndo_get_stats64	= ionic_get_stats64,
	.ndo_set_rx_mode	= ionic_set_rx_mode,
	.ndo_set_features	= ionic_set_features,
	.ndo_set_mac_address	= ionic_set_mac_address,
	.ndo_validate_addr	= eth_validate_addr,
	.ndo_tx_timeout         = ionic_tx_timeout,
	.ndo_vlan_rx_add_vid    = ionic_vlan_rx_add_vid,
	.ndo_vlan_rx_kill_vid   = ionic_vlan_rx_kill_vid,
#ifdef HAVE_RHEL7_EXTENDED_MIN_MAX_MTU
	.extended.ndo_change_mtu = ionic_mnic_change_mtu,
#else
	.ndo_change_mtu         = ionic_mnic_change_mtu,
#endif

#ifdef HAVE_RHEL7_NET_DEVICE_OPS_EXT
/* RHEL7 requires this to be defined to enable extended ops.  RHEL7 uses the
 * function get_ndo_ext to retrieve offsets for extended fields from with the
 * net_device_ops struct and ndo_size is checked to determine whether or not
 * the offset is valid.
 */
	.ndo_size		= sizeof(const struct net_device_ops),
#endif
};

static irqreturn_t ionic_isr(int irq, void *data)
{
	struct napi_struct *napi = data;

	napi_schedule_irqoff(napi);

	return IRQ_HANDLED;
}

int ionic_intr_alloc(struct lif *lif, struct intr *intr)
{
	struct ionic *ionic = lif->ionic;
	struct ionic_dev *idev = &ionic->idev;
	int index;

	index = find_first_zero_bit(ionic->intrs, ionic->nintrs);
	if (index == ionic->nintrs) {
		netdev_warn(lif->netdev, "%s: no intr, index=%d nintrs=%d\n",
			    __func__, index, ionic->nintrs);
		return -ENOSPC;
	}

	set_bit(index, ionic->intrs);
	ionic_intr_init(idev, intr, index);

	return 0;
}

void ionic_intr_free(struct lif *lif, int index)
{
	if (index != INTR_INDEX_NOT_ASSIGNED && index < lif->ionic->nintrs)
		clear_bit(index, lif->ionic->intrs);
}

static int ionic_intr_remaining(struct ionic *ionic)
{
	int intrs_remaining;
	unsigned long bit;

	intrs_remaining = ionic->nintrs;
	for_each_set_bit(bit, ionic->intrs, ionic->nintrs)
		intrs_remaining--;

	return intrs_remaining;
}

static void ionic_link_qcq_interrupts(struct qcq *src_qcq, struct qcq *n_qcq)
{
	if (WARN_ON(n_qcq->flags & QCQ_F_INTR)) {
		ionic_intr_free(n_qcq->cq.lif, n_qcq->intr.index);
		n_qcq->flags &= ~QCQ_F_INTR;
	}

	n_qcq->intr.vector = src_qcq->intr.vector;
	n_qcq->intr.index = src_qcq->intr.index;
}

static int ionic_qcq_alloc(struct lif *lif, unsigned int type,
			   unsigned int index,
			   const char *name, unsigned int flags,
			   unsigned int num_descs, unsigned int desc_size,
			   unsigned int cq_desc_size,
			   unsigned int sg_desc_size,
			   unsigned int pid, struct qcq **qcq)
{
	struct ionic_dev *idev = &lif->ionic->idev;
	struct device *dev = lif->ionic->dev;
	struct qcq *new;
	u32 q_size, cq_size, sg_size, total_size;
	void *q_base, *cq_base, *sg_base;
	dma_addr_t q_base_pa = 0, cq_base_pa = 0, sg_base_pa = 0;
	int err;

	*qcq = NULL;

	q_size  = num_descs * desc_size;
	cq_size = num_descs * cq_desc_size;
	sg_size = num_descs * sg_desc_size;

	total_size = ALIGN(q_size, PAGE_SIZE) + ALIGN(cq_size, PAGE_SIZE);
	/* Note: aligning q_size/cq_size is not enough due to cq_base
	 * address aligning as q_base could be not aligned to the page.
	 * Adding PAGE_SIZE.
	 */
	total_size += PAGE_SIZE;
	if (flags & QCQ_F_SG) {
		total_size += ALIGN(sg_size, PAGE_SIZE);
		total_size += PAGE_SIZE;
	}

	new = devm_kzalloc(dev, sizeof(*new), GFP_KERNEL);
	if (!new) {
		netdev_err(lif->netdev, "Cannot allocate queue structure\n");
		err = -ENOMEM;
		goto err_out;
	}

	new->flags = flags;

	new->q.info = devm_kzalloc(dev, sizeof(*new->q.info) * num_descs,
				   GFP_KERNEL);
	if (!new->q.info) {
		netdev_err(lif->netdev, "Cannot allocate queue info\n");
		err = -ENOMEM;
		goto err_out;
	}

	new->q.type = type;

	err = ionic_q_init(lif, idev, &new->q, index, name, num_descs,
			   desc_size, sg_desc_size, pid);
	if (err) {
		netdev_err(lif->netdev, "Cannot initialize queue\n");
		goto err_out;
	}

	if (flags & QCQ_F_INTR) {
		err = ionic_intr_alloc(lif, &new->intr);
		if (err) {
			netdev_warn(lif->netdev, "no intr for %s: %d\n",
				    name, err);
			goto err_out;
		}

		err = ionic_bus_get_irq(lif->ionic, new->intr.index);
		if (err < 0) {
			netdev_warn(lif->netdev, "no vector for %s: %d\n",
				    name, err);
			goto err_out_free_intr;
		}
		new->intr.vector = err;
		ionic_intr_mask_assert(idev->intr_ctrl, new->intr.index,
				       IONIC_INTR_MASK_SET);

		new->intr.cpu = new->intr.index % num_online_cpus();
		if (cpu_online(new->intr.cpu))
			cpumask_set_cpu(new->intr.cpu,
					&new->intr.affinity_mask);
	} else {
		new->intr.index = INTR_INDEX_NOT_ASSIGNED;
	}

	new->cq.info = devm_kzalloc(dev, sizeof(*new->cq.info) * num_descs,
				    GFP_KERNEL);
	if (!new->cq.info) {
		netdev_err(lif->netdev, "Cannot allocate completion queue info\n");
		err = -ENOMEM;
		goto err_out_free_intr;
	}

	err = ionic_cq_init(lif, &new->cq, &new->intr, num_descs, cq_desc_size);
	if (err) {
		netdev_err(lif->netdev, "Cannot initialize completion queue\n");
		goto err_out_free_intr;
	}

	new->base = dma_alloc_coherent(dev, total_size, &new->base_pa,
				       GFP_KERNEL);
	if (!new->base) {
		netdev_err(lif->netdev, "Cannot allocate queue DMA memory\n");
		err = -ENOMEM;
		goto err_out_free_intr;
	}

	new->total_size = total_size;

	q_base = new->base;
	q_base_pa = new->base_pa;

	cq_base = (void *)ALIGN((uintptr_t)q_base + q_size, PAGE_SIZE);
	cq_base_pa = ALIGN(q_base_pa + q_size, PAGE_SIZE);

	if (flags & QCQ_F_SG) {
		sg_base = (void *)ALIGN((uintptr_t)cq_base + cq_size,
					PAGE_SIZE);
		sg_base_pa = ALIGN(cq_base_pa + cq_size, PAGE_SIZE);
		ionic_q_sg_map(&new->q, sg_base, sg_base_pa);
	}

	ionic_q_map(&new->q, q_base, q_base_pa);
	ionic_cq_map(&new->cq, cq_base, cq_base_pa);
	ionic_cq_bind(&new->cq, &new->q);

	*qcq = new;

	return 0;

err_out_free_intr:
	ionic_intr_free(lif, new->intr.index);
err_out:
	dev_err(dev, "qcq alloc of %s%d failed %d\n", name, index, err);
	return err;
}

static void ionic_qcq_free(struct lif *lif, struct qcq *qcq)
{
	struct device *dev = lif->ionic->dev;

	if (!qcq)
		return;

	dma_free_coherent(dev, qcq->total_size, qcq->base, qcq->base_pa);
	qcq->base = NULL;
	qcq->base_pa = 0;

	/* only the slave Tx and Rx qcqs will have master_slot set */
	if (qcq->master_slot) {
		struct lif *master_lif = lif->ionic->master_lif;
		int max = master_lif->nxqs + lif->ionic->nslaves;

		if (qcq->master_slot >= max)
			dev_err(dev, "bad slot number %d\n", qcq->master_slot);
		else if (qcq->flags & QCQ_F_TX_STATS)
			master_lif->txqcqs[qcq->master_slot].qcq = NULL;
		else
			master_lif->rxqcqs[qcq->master_slot].qcq = NULL;
	}

	if (qcq->flags & QCQ_F_INTR)
		ionic_intr_free(lif, qcq->intr.index);

	devm_kfree(dev, qcq->cq.info);
	qcq->cq.info = NULL;
	devm_kfree(dev, qcq->q.info);
	qcq->q.info = NULL;
	devm_kfree(dev, qcq);
}

static int ionic_link_master_qcq(struct qcq *qcq, struct qcqst *master_qs)
{
	struct lif *master_lif = qcq->q.lif->ionic->master_lif;
	unsigned int slot;

	slot = master_lif->nxqs + qcq->q.lif->index - 1;

	/* TODO: should never be true */
	if (master_qs[slot].qcq) {
		netdev_err(master_lif->netdev,
			   "bad slot number %d\n", qcq->master_slot);
		return -ENOSPC;
	}

	master_qs[slot].qcq = qcq;
	master_qs[slot].stats = qcq->stats;
	qcq->master_slot = slot;

	return 0;
}

static int ionic_txrx_alloc(struct lif *lif)
{
	unsigned int flags;
	unsigned int i;
	int err = 0;

	flags = QCQ_F_TX_STATS | QCQ_F_SG;
	for (i = 0; i < lif->nxqs; i++) {
		err = ionic_qcq_alloc(lif, IONIC_QTYPE_TXQ, i, "tx", flags,
				      lif->ntxq_descs,
				      sizeof(struct txq_desc),
				      sizeof(struct txq_comp),
				      sizeof(struct txq_sg_desc),
				      lif->kern_pid, &lif->txqcqs[i].qcq);
		if (err)
			goto err_out_free_txqcqs;

		/* this makes the stats block easy to find from qcq context */
		lif->txqcqs[i].qcq->stats = lif->txqcqs[i].stats;

		if (!is_master_lif(lif)) {
			struct qcqst *txqs = lif->ionic->master_lif->txqcqs;

			err = ionic_link_master_qcq(lif->txqcqs[i].qcq, txqs);
			if (err)
				goto err_out_free_txqcqs;
		}
	}

	flags = QCQ_F_RX_STATS | QCQ_F_INTR;
	for (i = 0; i < lif->nxqs; i++) {
		err = ionic_qcq_alloc(lif, IONIC_QTYPE_RXQ, i, "rx", flags,
				      lif->nrxq_descs,
				      sizeof(struct rxq_desc),
				      sizeof(struct rxq_comp),
				      0, lif->kern_pid, &lif->rxqcqs[i].qcq);
		if (err)
			goto err_out_free_rxqcqs;

		/* this makes the stats block easy to find from qcq context */
		lif->rxqcqs[i].qcq->stats = lif->rxqcqs[i].stats;

		ionic_link_qcq_interrupts(lif->rxqcqs[i].qcq,
					  lif->txqcqs[i].qcq);

		if (!is_master_lif(lif)) {
			struct qcqst *rxqs = lif->ionic->master_lif->rxqcqs;

			err = ionic_link_master_qcq(lif->rxqcqs[i].qcq, rxqs);
			if (err)
				goto err_out_free_rxqcqs;
		}
	}

	return 0;

err_out_free_rxqcqs:
	for (i = 0; i < lif->nxqs; i++)
		ionic_qcq_free(lif, lif->rxqcqs[i].qcq);
err_out_free_txqcqs:
	for (i = 0; i < lif->nxqs; i++)
		ionic_qcq_free(lif, lif->txqcqs[i].qcq);

	return err;
}

static int ionic_txrx_init(struct lif *lif)
{
	int err;

	err = ionic_lif_txqs_init(lif);
	if (err)
		return err;

	err = ionic_lif_rxqs_init(lif);
	if (err)
		goto err_out;

	if (is_master_lif(lif) && lif->netdev->features & NETIF_F_RXHASH)
		ionic_lif_rss_init(lif);

	ionic_set_rx_mode(lif->netdev);

	return 0;

err_out:
	ionic_stop(lif->netdev);

	return err;
}

static int ionic_qcqs_alloc(struct lif *lif)
{
	struct device *dev = lif->ionic->dev;
	unsigned int q_list_size;
	unsigned int flags;
	int err;
	int i;

	flags = QCQ_F_INTR;
	err = ionic_qcq_alloc(lif, IONIC_QTYPE_ADMINQ, 0, "admin", flags,
			      IONIC_ADMINQ_LENGTH,
			      sizeof(struct admin_cmd),
			      sizeof(struct admin_comp),
			      0, lif->kern_pid, &lif->adminqcq);
	if (err)
		return err;

	if (is_master_lif(lif) && lif->ionic->nnqs_per_lif) {
		flags = QCQ_F_NOTIFYQ;
		err = ionic_qcq_alloc(lif, IONIC_QTYPE_NOTIFYQ, 0, "notifyq",
				      flags, IONIC_NOTIFYQ_LENGTH,
				      sizeof(struct notifyq_cmd),
				      sizeof(union notifyq_comp),
				      0, lif->kern_pid, &lif->notifyqcq);
		if (err)
			goto err_out_free_adminqcq;

		/* Let the notifyq ride on the adminq interrupt */
		ionic_link_qcq_interrupts(lif->adminqcq, lif->notifyqcq);
	}

	q_list_size = sizeof(*lif->txqcqs) * lif->nxqs;
	if (is_master_lif(lif))
		q_list_size += sizeof(*lif->txqcqs) * lif->ionic->nslaves;

	err = -ENOMEM;
	lif->txqcqs = devm_kzalloc(dev, q_list_size, GFP_KERNEL);
	if (!lif->txqcqs)
		goto err_out_free_notifyqcq;
	for (i = 0; i < lif->nxqs; i++) {
		lif->txqcqs[i].stats = devm_kzalloc(dev, sizeof(struct q_stats),
						    GFP_KERNEL);
		if (!lif->txqcqs[i].stats)
			goto err_out_free_tx_stats;
	}

	lif->rxqcqs = devm_kzalloc(dev, q_list_size, GFP_KERNEL);
	if (!lif->rxqcqs)
		goto err_out_free_tx_stats;
	for (i = 0; i < lif->nxqs; i++) {
		lif->rxqcqs[i].stats = devm_kzalloc(dev, sizeof(struct q_stats),
						    GFP_KERNEL);
		if (!lif->rxqcqs[i].stats)
			goto err_out_free_rx_stats;
	}

	return 0;

err_out_free_rx_stats:
	for (i = 0; i < lif->nxqs; i++)
		if (lif->rxqcqs[i].stats)
			devm_kfree(dev, lif->rxqcqs[i].stats);
	devm_kfree(dev, lif->rxqcqs);
	lif->rxqcqs = NULL;
err_out_free_tx_stats:
	for (i = 0; i < lif->nxqs; i++)
		if (lif->txqcqs[i].stats)
			devm_kfree(dev, lif->txqcqs[i].stats);
	devm_kfree(dev, lif->txqcqs);
	lif->txqcqs = NULL;
err_out_free_notifyqcq:
	if (lif->notifyqcq) {
		ionic_qcq_free(lif, lif->notifyqcq);
		lif->notifyqcq = NULL;
	}
err_out_free_adminqcq:
	if (lif->adminqcq) {
		ionic_qcq_free(lif, lif->adminqcq);
		lif->adminqcq = NULL;
	}

	return err;
}

static void ionic_qcqs_free(struct lif *lif)
{
	struct device *dev = lif->ionic->dev;
	unsigned int i;

	if (lif->notifyqcq) {
		ionic_qcq_free(lif, lif->notifyqcq);
		lif->notifyqcq = NULL;
	}

	if (lif->adminqcq) {
		ionic_qcq_free(lif, lif->adminqcq);
		lif->adminqcq = NULL;
	}

	for (i = 0; i < lif->nxqs; i++)
		if (lif->rxqcqs[i].stats)
			devm_kfree(dev, lif->rxqcqs[i].stats);

	devm_kfree(dev, lif->rxqcqs);
	lif->rxqcqs = NULL;

	for (i = 0; i < lif->nxqs; i++)
		if (lif->txqcqs[i].stats)
			devm_kfree(dev, lif->txqcqs[i].stats);

	devm_kfree(dev, lif->txqcqs);
	lif->txqcqs = NULL;
}

static struct lif *ionic_lif_alloc(struct ionic *ionic, unsigned int index)
{
	struct device *dev = ionic->dev;
	struct lif *lif;
	int tbl_sz;
	int err;

	if (index == 0) {
		struct net_device *netdev;
		int nqueues;
		/* master lif is built into the netdev */

		/* We create a netdev big enough to handle all the queues
		 * needed for our macvlan slave lifs, then set the real
		 * number of Tx and Rx queues used to just the queue set
		 * for lif0.
		 */
		nqueues = ionic->ntxqs_per_lif + ionic->nslaves;
		dev_info(ionic->dev, "nxqs=%d nslaves=%d nqueues=%d nintrs=%d\n",
			 ionic->ntxqs_per_lif, ionic->nslaves,
			 nqueues, ionic->nintrs);

		netdev = ionic_alloc_netdev(ionic);
		if (!netdev) {
			dev_err(dev, "Cannot allocate netdev, aborting\n");
			return ERR_PTR(-ENOMEM);
		}
		netif_set_real_num_tx_queues(netdev, ionic->ntxqs_per_lif);
		netif_set_real_num_rx_queues(netdev, ionic->nrxqs_per_lif);

		SET_NETDEV_DEV(netdev, dev);

		lif = netdev_priv(netdev);
		lif->netdev = netdev;
		ionic->master_lif = lif;

		if (ionic_is_mnic(ionic))
			netdev->netdev_ops = &ionic_mnic_netdev_ops;
		else
			netdev->netdev_ops = &ionic_netdev_ops;

		ionic_ethtool_set_ops(netdev);
		netdev->watchdog_timeo = 2 * HZ;

#ifdef HAVE_NETDEVICE_MIN_MAX_MTU
#ifdef HAVE_RHEL7_EXTENDED_MIN_MAX_MTU
		netdev->extended->min_mtu = IONIC_MIN_MTU;
		netdev->extended->max_mtu = IONIC_MAX_MTU;
#else
		netdev->min_mtu = IONIC_MIN_MTU;
		netdev->max_mtu = IONIC_MAX_MTU;
#endif /* HAVE_RHEL7_EXTENDED_MIN_MAX_MTU */
#endif /* HAVE_NETDEVICE_MIN_MAX_MTU */

		lif->neqs = ionic->neqs_per_lif;
		lif->nxqs = ionic->ntxqs_per_lif;
	} else {
		/* slave lifs */

		lif = kzalloc(sizeof(*lif), GFP_KERNEL);
		if (!lif) {
			dev_err(dev, "Cannot allocate slave lif %d\n", index);
			return ERR_PTR(-ENOMEM);
		}
		lif->netdev = ionic->master_lif->netdev;
		lif->neqs = 0;
		lif->nxqs = 1;
	}

	lif->ionic = ionic;
	lif->index = index;
	lif->ntxq_descs = IONIC_DEF_TXRX_DESC;
	lif->nrxq_descs = IONIC_DEF_TXRX_DESC;

	snprintf(lif->name, sizeof(lif->name), "lif%u", index);

	spin_lock_init(&lif->adminq_lock);

	spin_lock_init(&lif->deferred.lock);
	INIT_LIST_HEAD(&lif->deferred.list);
	INIT_WORK(&lif->deferred.work, ionic_lif_deferred_work);

	/* allocate lif info */
	lif->info_sz = ALIGN(sizeof(*lif->info), PAGE_SIZE);
	lif->info = dma_alloc_coherent(dev, lif->info_sz,
				       &lif->info_pa, GFP_KERNEL);
	if (!lif->info) {
		dev_err(dev, "Failed to allocate lif info, aborting\n");
		err = -ENOMEM;
		goto err_out_free_netdev;
	}

	/* allocate queues */
	err = ionic_qcqs_alloc(lif);
	if (err)
		goto err_out_free_lif_info;

	/* allocate rss indirection table */
	tbl_sz = le16_to_cpu(lif->ionic->ident.lif.eth.rss_ind_tbl_sz);
	lif->rss_ind_tbl_sz = sizeof(*lif->rss_ind_tbl) * tbl_sz;
	lif->rss_ind_tbl = dma_alloc_coherent(dev, lif->rss_ind_tbl_sz,
					      &lif->rss_ind_tbl_pa,
					      GFP_KERNEL);

	if (!lif->rss_ind_tbl) {
		dev_err(dev, "Failed to allocate rss indirection table, aborting\n");
		goto err_out_free_qcqs;
	}

	list_add_tail(&lif->list, &ionic->lifs);

	return lif;

err_out_free_qcqs:
	ionic_qcqs_free(lif);
err_out_free_lif_info:
	dma_free_coherent(dev, lif->info_sz, lif->info, lif->info_pa);
	lif->info = NULL;
	lif->info_pa = 0;
err_out_free_netdev:
	if (is_master_lif(lif))
		free_netdev(lif->netdev);
	else
		kfree(lif);
	lif = NULL;

	return ERR_PTR(err);
}

int ionic_lifs_alloc(struct ionic *ionic)
{
	struct lif *lif;

	INIT_LIST_HEAD(&ionic->lifs);

	/* only build the first lif, others are for dynamic macvlan offload */
	set_bit(0, ionic->lifbits);
	lif = ionic_lif_alloc(ionic, 0);

	return PTR_ERR_OR_ZERO(lif);
}

static void ionic_lif_reset(struct lif *lif)
{
	struct ionic_dev *idev = &lif->ionic->idev;

	mutex_lock(&lif->ionic->dev_cmd_lock);
	ionic_dev_cmd_lif_reset(idev, lif->index);
	ionic_dev_cmd_wait(lif->ionic, devcmd_timeout);
	mutex_unlock(&lif->ionic->dev_cmd_lock);
}

static void ionic_lif_handle_fw_down(struct lif *lif)
{
	struct ionic *ionic = lif->ionic;

	clear_bit(LIF_F_FW_READY, lif->state);
	ionic_lifs_unregister(ionic);
	ionic_lifs_deinit(ionic);

	netdev_info(lif->netdev, "FW Down: Lif is in reset state!\n");
}

static void ionic_lif_free(struct lif *lif)
{
	struct device *dev = lif->ionic->dev;

	/* free rss indirection table */
	if (lif->rss_ind_tbl) {
		dma_free_coherent(dev, lif->rss_ind_tbl_sz, lif->rss_ind_tbl,
				  lif->rss_ind_tbl_pa);
		lif->rss_ind_tbl = NULL;
		lif->rss_ind_tbl_pa = 0;
	}

	/* free queues */
	ionic_qcqs_free(lif);
	if (test_bit(LIF_F_FW_READY, lif->state))
		ionic_lif_reset(lif);

	cancel_work_sync(&lif->deferred.work);

	/* free lif info */
	if (lif->info) {
		dma_free_coherent(dev, lif->info_sz, lif->info, lif->info_pa);
		lif->info = NULL;
		lif->info_pa = 0;
	}

	/* unmap doorbell page */
	ionic_bus_unmap_dbpage(lif->ionic, lif->kern_dbpage);
	lif->kern_dbpage = NULL;
	kfree(lif->dbid_inuse);
	lif->dbid_inuse = NULL;

	/* free netdev & lif */
	ionic_debugfs_del_lif(lif);
	list_del(&lif->list);
	if (is_master_lif(lif)) {
		free_netdev(lif->netdev);
	} else {
		ionic_slave_free(lif->ionic, lif->index);
		memset(lif, 0, sizeof(*lif));
		kfree(lif);
	}
}

void ionic_lifs_free(struct ionic *ionic)
{
	struct list_head *cur, *tmp;
	struct lif *lif;

	list_for_each_safe(cur, tmp, &ionic->lifs) {
		lif = list_entry(cur, struct lif, list);

		ionic_lif_free(lif);
	}
}

int ionic_lif_rss_config(struct lif *lif, const u16 types,
			 const u8 *key, const u32 *indir)
{
	struct ionic_admin_ctx ctx = {
		.work = COMPLETION_INITIALIZER_ONSTACK(ctx.work),
		.cmd.lif_setattr = {
			.opcode = CMD_OPCODE_LIF_SETATTR,
			.attr = IONIC_LIF_ATTR_RSS,
			.rss.types = cpu_to_le16(types),
			.rss.addr = cpu_to_le64(lif->rss_ind_tbl_pa),
		},
	};
	unsigned int i, tbl_sz;

	lif->rss_types = types;

	if (key)
		memcpy(lif->rss_hash_key, key, IONIC_RSS_HASH_KEY_SIZE);

	if (indir) {
		tbl_sz = le16_to_cpu(lif->ionic->ident.lif.eth.rss_ind_tbl_sz);
		for (i = 0; i < tbl_sz; i++)
			lif->rss_ind_tbl[i] = indir[i];
	}

	memcpy(ctx.cmd.lif_setattr.rss.key, lif->rss_hash_key,
	       IONIC_RSS_HASH_KEY_SIZE);

	return ionic_adminq_post_wait(lif, &ctx);
}

static int ionic_lif_rss_init(struct lif *lif)
{
	static const u8 toeplitz_symmetric_key[] = {
		0x6D, 0x5A, 0x6D, 0x5A, 0x6D, 0x5A, 0x6D, 0x5A,
		0x6D, 0x5A, 0x6D, 0x5A, 0x6D, 0x5A, 0x6D, 0x5A,
		0x6D, 0x5A, 0x6D, 0x5A, 0x6D, 0x5A, 0x6D, 0x5A,
		0x6D, 0x5A, 0x6D, 0x5A, 0x6D, 0x5A, 0x6D, 0x5A,
		0x6D, 0x5A, 0x6D, 0x5A, 0x6D, 0x5A, 0x6D, 0x5A,
	};
	unsigned int i, tbl_sz;

	lif->rss_types = IONIC_RSS_TYPE_IPV4     |
			 IONIC_RSS_TYPE_IPV4_TCP |
			 IONIC_RSS_TYPE_IPV4_UDP |
			 IONIC_RSS_TYPE_IPV6     |
			 IONIC_RSS_TYPE_IPV6_TCP |
			 IONIC_RSS_TYPE_IPV6_UDP;

	/* Fill indirection table with 'default' values */
	tbl_sz = le16_to_cpu(lif->ionic->ident.lif.eth.rss_ind_tbl_sz);
	for (i = 0; i < tbl_sz; i++)
		lif->rss_ind_tbl[i] = i % lif->nxqs;

	return ionic_lif_rss_config(lif, lif->rss_types,
				    toeplitz_symmetric_key, NULL);
}

static int ionic_lif_rss_deinit(struct lif *lif)
{
	/* Disable RSS on the NIC */
	return ionic_lif_rss_config(lif, 0x0, NULL, NULL);
}

static void ionic_lif_qcq_deinit(struct lif *lif, struct qcq *qcq)
{
	struct device *dev = lif->ionic->dev;
	struct ionic_dev *idev = &lif->ionic->idev;

	if (!qcq)
		return;

	ionic_debugfs_del_qcq(qcq);

	if (!(qcq->flags & QCQ_F_INITED))
		return;

	if (qcq->flags & QCQ_F_INTR) {
		ionic_intr_mask(idev->intr_ctrl, qcq->intr.index,
				IONIC_INTR_MASK_SET);
		synchronize_irq(qcq->intr.vector);
		devm_free_irq(dev, qcq->intr.vector, &qcq->napi);
		netif_napi_del(&qcq->napi);
	}

	qcq->flags &= ~QCQ_F_INITED;
}

static void ionic_lif_deinit(struct lif *lif)
{
	if (!test_bit(LIF_INITED, lif->state))
		return;

	clear_bit(LIF_INITED, lif->state);

	if (test_bit(LIF_F_FW_READY, lif->state))
		cancel_work_sync(&lif->deferred.work);

	ionic_rx_filters_deinit(lif);
	ionic_lif_rss_deinit(lif);

	napi_disable(&lif->adminqcq->napi);
	ionic_lif_qcq_deinit(lif, lif->notifyqcq);
	ionic_lif_qcq_deinit(lif, lif->adminqcq);

	ionic_lif_reset(lif);
}

void ionic_lifs_deinit(struct ionic *ionic)
{
	struct list_head *cur, *tmp;
	struct lif *lif;

	list_for_each_safe(cur, tmp, &ionic->lifs) {
		lif = list_entry(cur, struct lif, list);
		ionic_lif_deinit(lif);
	}
}

static int ionic_request_irq(struct lif *lif, struct qcq *qcq)
{
	struct device *dev = lif->ionic->dev;
	struct intr *intr = &qcq->intr;
	struct queue *q = &qcq->q;
	struct napi_struct *napi = &qcq->napi;
	const char *name;

	if (lif->registered)
		name = lif->netdev->name;
	else if (!is_master_lif(lif) && lif->upper_dev)
		name = lif->upper_dev->name;
	else
		name = dev_name(dev);

	snprintf(intr->name, sizeof(intr->name),
		 "%s-%s-%s", DRV_NAME, name, q->name);

	return devm_request_irq(dev, intr->vector, ionic_isr,
				0, intr->name, napi);
}

static int ionic_lif_adminq_init(struct lif *lif)
{
	struct device *dev = lif->ionic->dev;
	struct ionic_dev *idev = &lif->ionic->idev;
	struct qcq *qcq = lif->adminqcq;
	struct queue *q = &qcq->q;
	struct napi_struct *napi = &qcq->napi;
	struct q_init_comp comp;
	int err;

	mutex_lock(&lif->ionic->dev_cmd_lock);
	ionic_dev_cmd_adminq_init(idev, qcq, lif->index, qcq->intr.index);
	err = ionic_dev_cmd_wait(lif->ionic, devcmd_timeout);
	ionic_dev_cmd_comp(idev, (union dev_cmd_comp *)&comp);
	mutex_unlock(&lif->ionic->dev_cmd_lock);
	if (err) {
		netdev_err(lif->netdev, "adminq init failed %d\n", err);
		return err;
	}

	q->hw_type = comp.hw_type;
	q->hw_index = le32_to_cpu(comp.hw_index);
	q->dbval = IONIC_DBELL_QID(q->hw_index);

	dev_dbg(dev, "adminq->hw_type %d\n", q->hw_type);
	dev_dbg(dev, "adminq->hw_index %d\n", q->hw_index);

	netif_napi_add(lif->netdev, napi, ionic_adminq_napi,
		       NAPI_POLL_WEIGHT);

	err = ionic_request_irq(lif, qcq);
	if (err) {
		netdev_warn(lif->netdev, "adminq irq request failed %d\n", err);
		netif_napi_del(napi);
		return err;
	}

	napi_enable(napi);

	if (qcq->flags & QCQ_F_INTR)
		ionic_intr_mask(idev->intr_ctrl, qcq->intr.index,
				IONIC_INTR_MASK_CLEAR);

	qcq->flags |= QCQ_F_INITED;

	err = ionic_debugfs_add_qcq(lif, qcq);
	if (err)
		netdev_warn(lif->netdev, "debugfs add for adminq failed %d\n",
			    err);

	return 0;
}

static int ionic_lif_notifyq_init(struct lif *lif)
{
	struct device *dev = lif->ionic->dev;
	struct qcq *qcq = lif->notifyqcq;
	struct queue *q = &qcq->q;
	int err;

	struct ionic_admin_ctx ctx = {
		.work = COMPLETION_INITIALIZER_ONSTACK(ctx.work),
		.cmd.q_init = {
			.opcode = CMD_OPCODE_Q_INIT,
			.lif_index = cpu_to_le16(lif->index),
			.type = q->type,
			.index = cpu_to_le32(q->index),
			.flags = cpu_to_le16(IONIC_QINIT_F_IRQ |
					     IONIC_QINIT_F_ENA),
			.intr_index = cpu_to_le16(lif->adminqcq->intr.index),
			.pid = cpu_to_le16(q->pid),
			.ring_size = ilog2(q->num_descs),
			.ring_base = cpu_to_le64(q->base_pa),
		}
	};

	dev_dbg(dev, "notifyq_init.pid %d\n", ctx.cmd.q_init.pid);
	dev_dbg(dev, "notifyq_init.index %d\n", ctx.cmd.q_init.index);
	dev_dbg(dev, "notifyq_init.ring_base 0x%llx\n", ctx.cmd.q_init.ring_base);
	dev_dbg(dev, "notifyq_init.ring_size %d\n", ctx.cmd.q_init.ring_size);

	err = ionic_adminq_post_wait(lif, &ctx);
	if (err)
		return err;

	q->hw_type = ctx.comp.q_init.hw_type;
	q->hw_index = le32_to_cpu(ctx.comp.q_init.hw_index);
	q->dbval = IONIC_DBELL_QID(q->hw_index);

	dev_dbg(dev, "notifyq->hw_type %d\n", q->hw_type);
	dev_dbg(dev, "notifyq->hw_index %d\n", q->hw_index);

	/* preset the callback info */
	q->info[0].cb_arg = lif;

	qcq->flags |= QCQ_F_INITED;

	err = ionic_debugfs_add_qcq(lif, qcq);
	if (err)
		dev_warn(dev, "debugfs add for notifyq failed %d\n", err);

	return 0;
}

static __le64 ionic_netdev_features_to_nic(netdev_features_t features)
{
	u64 wanted = 0;

	if (features & NETIF_F_HW_VLAN_CTAG_TX)
		wanted |= ETH_HW_VLAN_TX_TAG;
	if (features & NETIF_F_HW_VLAN_CTAG_RX)
		wanted |= ETH_HW_VLAN_RX_STRIP;
	if (features & NETIF_F_HW_VLAN_CTAG_FILTER)
		wanted |= ETH_HW_VLAN_RX_FILTER;
	if (features & NETIF_F_RXHASH)
		wanted |= ETH_HW_RX_HASH;
	if (features & NETIF_F_RXCSUM)
		wanted |= ETH_HW_RX_CSUM;
	if (features & NETIF_F_SG)
		wanted |= ETH_HW_TX_SG;
	if (features & NETIF_F_HW_CSUM)
		wanted |= ETH_HW_TX_CSUM;
	if (features & NETIF_F_TSO)
		wanted |= ETH_HW_TSO;
	if (features & NETIF_F_TSO6)
		wanted |= ETH_HW_TSO_IPV6;
	if (features & NETIF_F_TSO_ECN)
		wanted |= ETH_HW_TSO_ECN;
	if (features & NETIF_F_GSO_GRE)
		wanted |= ETH_HW_TSO_GRE;
	if (features & NETIF_F_GSO_GRE_CSUM)
		wanted |= ETH_HW_TSO_GRE_CSUM;
#ifdef NETIF_F_GSO_IPXIP4
	if (features & NETIF_F_GSO_IPXIP4)
		wanted |= ETH_HW_TSO_IPXIP4;
#endif
#ifdef NETIF_F_GSO_IPXIP6
	if (features & NETIF_F_GSO_IPXIP6)
		wanted |= ETH_HW_TSO_IPXIP6;
#endif
	if (features & NETIF_F_GSO_UDP_TUNNEL)
		wanted |= ETH_HW_TSO_UDP;
	if (features & NETIF_F_GSO_UDP_TUNNEL_CSUM)
		wanted |= ETH_HW_TSO_UDP_CSUM;

	return cpu_to_le64(wanted);
}

static int ionic_set_nic_features(struct lif *lif, netdev_features_t features)
{
	struct device *dev = lif->ionic->dev;
	struct ionic_admin_ctx ctx = {
		.work = COMPLETION_INITIALIZER_ONSTACK(ctx.work),
		.cmd.lif_setattr = {
			.opcode = CMD_OPCODE_LIF_SETATTR,
			.index = cpu_to_le16(lif->index),
			.attr = IONIC_LIF_ATTR_FEATURES,
			.features = cpu_to_le64(features),
		},
	};
	int err;
	unsigned long vlan_flags = ETH_HW_VLAN_TX_TAG |
				   ETH_HW_VLAN_RX_STRIP |
				   ETH_HW_VLAN_RX_FILTER;

	ctx.cmd.lif_setattr.features = ionic_netdev_features_to_nic(features);
	err = ionic_adminq_post_wait(lif, &ctx);
	if (err)
		return err;

	lif->hw_features = le64_to_cpu(ctx.cmd.lif_setattr.features &
				       ctx.comp.lif_setattr.features);

	if ((vlan_flags & features) &&
	    !(vlan_flags & le64_to_cpu(ctx.comp.lif_setattr.features)))
		dev_info_once(lif->ionic->dev, "NIC is not supporting vlan offload, likely in SmartNIC mode\n");

	if (lif->hw_features & ETH_HW_VLAN_TX_TAG)
		dev_dbg(dev, "feature ETH_HW_VLAN_TX_TAG\n");
	if (lif->hw_features & ETH_HW_VLAN_RX_STRIP)
		dev_dbg(dev, "feature ETH_HW_VLAN_RX_STRIP\n");
	if (lif->hw_features & ETH_HW_VLAN_RX_FILTER)
		dev_dbg(dev, "feature ETH_HW_VLAN_RX_FILTER\n");
	if (lif->hw_features & ETH_HW_RX_HASH)
		dev_dbg(dev, "feature ETH_HW_RX_HASH\n");
	if (lif->hw_features & ETH_HW_TX_SG)
		dev_dbg(dev, "feature ETH_HW_TX_SG\n");
	if (lif->hw_features & ETH_HW_TX_CSUM)
		dev_dbg(dev, "feature ETH_HW_TX_CSUM\n");
	if (lif->hw_features & ETH_HW_RX_CSUM)
		dev_dbg(dev, "feature ETH_HW_RX_CSUM\n");
	if (lif->hw_features & ETH_HW_TSO)
		dev_dbg(dev, "feature ETH_HW_TSO\n");
	if (lif->hw_features & ETH_HW_TSO_IPV6)
		dev_dbg(dev, "feature ETH_HW_TSO_IPV6\n");
	if (lif->hw_features & ETH_HW_TSO_ECN)
		dev_dbg(dev, "feature ETH_HW_TSO_ECN\n");
	if (lif->hw_features & ETH_HW_TSO_GRE)
		dev_dbg(dev, "feature ETH_HW_TSO_GRE\n");
	if (lif->hw_features & ETH_HW_TSO_GRE_CSUM)
		dev_dbg(dev, "feature ETH_HW_TSO_GRE_CSUM\n");
	if (lif->hw_features & ETH_HW_TSO_IPXIP4)
		dev_dbg(dev, "feature ETH_HW_TSO_IPXIP4\n");
	if (lif->hw_features & ETH_HW_TSO_IPXIP6)
		dev_dbg(dev, "feature ETH_HW_TSO_IPXIP6\n");
	if (lif->hw_features & ETH_HW_TSO_UDP)
		dev_dbg(dev, "feature ETH_HW_TSO_UDP\n");
	if (lif->hw_features & ETH_HW_TSO_UDP_CSUM)
		dev_dbg(dev, "feature ETH_HW_TSO_UDP_CSUM\n");

	return 0;
}

static int ionic_init_nic_features(struct lif *lif)
{
	struct net_device *netdev = lif->netdev;
	netdev_features_t features;
	int err;

	/* set up what we expect to support by default */
	features = NETIF_F_HW_VLAN_CTAG_TX |
		   NETIF_F_HW_VLAN_CTAG_RX |
		   NETIF_F_HW_VLAN_CTAG_FILTER |
		   NETIF_F_RXHASH |
		   NETIF_F_SG |
		   NETIF_F_HW_CSUM |
		   NETIF_F_RXCSUM |
		   NETIF_F_TSO |
		   NETIF_F_TSO6 |
		   NETIF_F_TSO_ECN;

	err = ionic_set_nic_features(lif, features);
	if (err)
		return err;

	if (!is_master_lif(lif))
		return 0;

	/* tell the netdev what we actually can support */
	netdev->features |= NETIF_F_HIGHDMA;

	if (lif->hw_features & ETH_HW_VLAN_TX_TAG)
		netdev->hw_features |= NETIF_F_HW_VLAN_CTAG_TX;
	if (lif->hw_features & ETH_HW_VLAN_RX_STRIP)
		netdev->hw_features |= NETIF_F_HW_VLAN_CTAG_RX;
	if (lif->hw_features & ETH_HW_VLAN_RX_FILTER)
		netdev->hw_features |= NETIF_F_HW_VLAN_CTAG_FILTER;
	if (lif->hw_features & ETH_HW_RX_HASH)
		netdev->hw_features |= NETIF_F_RXHASH;
	if (lif->hw_features & ETH_HW_TX_SG)
		netdev->hw_features |= NETIF_F_SG;

	if (lif->hw_features & ETH_HW_TX_CSUM)
		netdev->hw_enc_features |= NETIF_F_HW_CSUM;
	if (lif->hw_features & ETH_HW_RX_CSUM)
		netdev->hw_enc_features |= NETIF_F_RXCSUM;
	if (lif->hw_features & ETH_HW_TSO)
		netdev->hw_enc_features |= NETIF_F_TSO;
	if (lif->hw_features & ETH_HW_TSO_IPV6)
		netdev->hw_enc_features |= NETIF_F_TSO6;
	if (lif->hw_features & ETH_HW_TSO_ECN)
		netdev->hw_enc_features |= NETIF_F_TSO_ECN;
	if (lif->hw_features & ETH_HW_TSO_GRE)
		netdev->hw_enc_features |= NETIF_F_GSO_GRE;
	if (lif->hw_features & ETH_HW_TSO_GRE_CSUM)
		netdev->hw_enc_features |= NETIF_F_GSO_GRE_CSUM;
#ifdef NETIF_F_GSO_IPXIP4
	if (lif->hw_features & ETH_HW_TSO_IPXIP4)
		netdev->hw_enc_features |= NETIF_F_GSO_IPXIP4;
#endif
#ifdef NETIF_F_GSO_IPXIP6
	if (lif->hw_features & ETH_HW_TSO_IPXIP6)
		netdev->hw_enc_features |= NETIF_F_GSO_IPXIP6;
#endif
	if (lif->hw_features & ETH_HW_TSO_UDP)
		netdev->hw_enc_features |= NETIF_F_GSO_UDP_TUNNEL;
	if (lif->hw_features & ETH_HW_TSO_UDP_CSUM)
		netdev->hw_enc_features |= NETIF_F_GSO_UDP_TUNNEL_CSUM;

	netdev->hw_features |= netdev->hw_enc_features;
	netdev->features |= netdev->hw_features;

	/* some earlier kernels complain if the vlan device inherits
	 * the NETIF_F_HW_VLAN... flags, so strip them out
	 */
	netdev->vlan_features |= netdev->features & ~(NETIF_F_HW_VLAN_CTAG_TX |
						      NETIF_F_HW_VLAN_CTAG_RX |
						   NETIF_F_HW_VLAN_CTAG_FILTER);

	/* Leave L2FW_OFFLOAD out of netdev->features so it will
	 * be disabled by default, but the user can enable later.
	 */
	if (lif->ionic->nslaves)
		netdev->hw_features |= NETIF_F_HW_L2FW_DOFFLOAD;

	netdev->priv_flags |= IFF_UNICAST_FLT;

	return 0;
}

static int ionic_lif_txq_init(struct lif *lif, struct qcq *qcq)
{
	struct device *dev = lif->ionic->dev;
	struct queue *q = &qcq->q;
	struct cq *cq = &qcq->cq;
	struct ionic_admin_ctx ctx = {
		.work = COMPLETION_INITIALIZER_ONSTACK(ctx.work),
		.cmd.q_init = {
			.opcode = CMD_OPCODE_Q_INIT,
			.lif_index = cpu_to_le16(lif->index),
			.type = q->type,
			.index = cpu_to_le32(q->index),
			.flags = cpu_to_le16(IONIC_QINIT_F_IRQ |
					     IONIC_QINIT_F_SG),
			.intr_index = cpu_to_le16(lif->rxqcqs[q->index].qcq->intr.index),
			.pid = cpu_to_le16(q->pid),
			.ring_size = ilog2(q->num_descs),
			.ring_base = cpu_to_le64(q->base_pa),
			.cq_ring_base = cpu_to_le64(cq->base_pa),
			.sg_ring_base = cpu_to_le64(q->sg_base_pa),
		},
	};
	int err;

	dev_dbg(dev, "txq_init.pid %d\n", ctx.cmd.q_init.pid);
	dev_dbg(dev, "txq_init.index %d\n", ctx.cmd.q_init.index);
	dev_dbg(dev, "txq_init.ring_base 0x%llx\n", ctx.cmd.q_init.ring_base);
	dev_dbg(dev, "txq_init.ring_size %d\n", ctx.cmd.q_init.ring_size);

	err = ionic_adminq_post_wait(lif, &ctx);
	if (err)
		return err;

	q->hw_type = ctx.comp.q_init.hw_type;
	q->hw_index = le32_to_cpu(ctx.comp.q_init.hw_index);
	q->dbval = IONIC_DBELL_QID(q->hw_index);

	dev_dbg(dev, "txq->hw_type %d\n", q->hw_type);
	dev_dbg(dev, "txq->hw_index %d\n", q->hw_index);

	qcq->flags |= QCQ_F_INITED;

	err = ionic_debugfs_add_qcq(lif, qcq);
	if (err)
		netdev_warn(lif->netdev, "debugfs add for txq %d failed %d\n",
			    q->hw_index, err);

	return 0;
}

static int ionic_lif_txqs_init(struct lif *lif)
{
	unsigned int i;
	int err;

	for (i = 0; i < lif->nxqs; i++) {
		err = ionic_lif_txq_init(lif, lif->txqcqs[i].qcq);
		if (err)
			goto err_out;
	}

	return 0;

err_out:
	for (; i > 0; i--)
		ionic_lif_qcq_deinit(lif, lif->txqcqs[i-1].qcq);

	return err;
}

static int ionic_lif_rxq_init(struct lif *lif, struct qcq *qcq)
{
	struct device *dev = lif->ionic->dev;
	struct queue *q = &qcq->q;
	struct cq *cq = &qcq->cq;
	struct napi_struct *napi = &qcq->napi;
	struct ionic_admin_ctx ctx = {
		.work = COMPLETION_INITIALIZER_ONSTACK(ctx.work),
		.cmd.q_init = {
			.opcode = CMD_OPCODE_Q_INIT,
			.lif_index = cpu_to_le16(lif->index),
			.type = q->type,
			.index = cpu_to_le32(q->index),
			.flags = cpu_to_le16(IONIC_QINIT_F_IRQ),
			.intr_index = cpu_to_le16(cq->bound_intr->index),
			.pid = cpu_to_le16(q->pid),
			.ring_size = ilog2(q->num_descs),
			.ring_base = cpu_to_le64(q->base_pa),
			.cq_ring_base = cpu_to_le64(cq->base_pa),
		},
	};
	int err;

	dev_dbg(dev, "rxq_init.pid %d\n", ctx.cmd.q_init.pid);
	dev_dbg(dev, "rxq_init.index %d\n", ctx.cmd.q_init.index);
	dev_dbg(dev, "rxq_init.ring_base 0x%llx\n", ctx.cmd.q_init.ring_base);
	dev_dbg(dev, "rxq_init.ring_size %d\n", ctx.cmd.q_init.ring_size);

	err = ionic_adminq_post_wait(lif, &ctx);
	if (err)
		return err;

	q->hw_type = ctx.comp.q_init.hw_type;
	q->hw_index = le32_to_cpu(ctx.comp.q_init.hw_index);
	q->dbval = IONIC_DBELL_QID(q->hw_index);

	dev_dbg(dev, "rxq->hw_type %d\n", q->hw_type);
	dev_dbg(dev, "rxq->hw_index %d\n", q->hw_index);

	netif_napi_add(lif->netdev, napi, ionic_rx_napi,
		       NAPI_POLL_WEIGHT);

	err = ionic_request_irq(lif, qcq);
	if (err) {
		netif_napi_del(napi);
		return err;
	}

	qcq->flags |= QCQ_F_INITED;

	err = ionic_debugfs_add_qcq(lif, qcq);
	if (err)
		netdev_warn(lif->netdev, "debugfs add for rxq %d failed %d\n",
			    q->hw_index, err);

	return 0;
}

static int ionic_lif_rxqs_init(struct lif *lif)
{
	unsigned int i;
	int err;

	for (i = 0; i < lif->nxqs; i++) {
		err = ionic_lif_rxq_init(lif, lif->rxqcqs[i].qcq);
		if (err)
			goto err_out;
	}

	return 0;

err_out:
	for (; i > 0; i--)
		ionic_lif_qcq_deinit(lif, lif->rxqcqs[i-1].qcq);

	return err;
}

static int ionic_station_set(struct lif *lif)
{
	struct net_device *netdev = lif->netdev;
	struct ionic_admin_ctx ctx = {
		.work = COMPLETION_INITIALIZER_ONSTACK(ctx.work),
		.cmd.lif_getattr = {
			.opcode = CMD_OPCODE_LIF_GETATTR,
			.index = cpu_to_le16(lif->index),
			.attr = IONIC_LIF_ATTR_MAC,
		},
	};
	int err;

	if (!is_master_lif(lif))
		return 0;

	err = ionic_adminq_post_wait(lif, &ctx);
	if (err)
		return err;

	if (!is_zero_ether_addr(netdev->dev_addr)) {
		netdev_info(lif->netdev, "deleting station MAC addr %pM\n",
			    netdev->dev_addr);
		ionic_lif_addr(lif, netdev->dev_addr, false);
	}
	memcpy(netdev->dev_addr, ctx.comp.lif_getattr.mac,
	       netdev->addr_len);
	netdev_info(lif->netdev, "adding station MAC addr %pM\n",
		    netdev->dev_addr);
	ionic_lif_addr(lif, netdev->dev_addr, true);

	return 0;
}

static int ionic_lif_init(struct lif *lif)
{
	struct ionic_dev *idev = &lif->ionic->idev;
	struct device *dev = lif->ionic->dev;
	struct lif_init_comp comp;
	int dbpage_num;
	int err;

	err = ionic_debugfs_add_lif(lif);
	if (err) {
		dev_err(dev, "lif debugfs add failed: %d\n", err);
		return err;
	}

	mutex_lock(&lif->ionic->dev_cmd_lock);
	ionic_dev_cmd_lif_init(idev, lif->index, lif->info_pa);
	err = ionic_dev_cmd_wait(lif->ionic, devcmd_timeout);
	ionic_dev_cmd_comp(idev, (union dev_cmd_comp *)&comp);
	mutex_unlock(&lif->ionic->dev_cmd_lock);
	if (err)
		return err;

	lif->hw_index = le16_to_cpu(comp.hw_index);

	/* now that we have the hw_index we can figure out our doorbell page */
	mutex_init(&lif->dbid_inuse_lock);
	lif->dbid_count = le32_to_cpu(lif->ionic->ident.dev.ndbpgs_per_lif);
	if (!lif->dbid_count) {
		dev_err(dev, "No doorbell pages, aborting\n");
		return -EINVAL;
	}

	lif->dbid_inuse = kzalloc(BITS_TO_LONGS(lif->dbid_count) * sizeof(long),
				  GFP_KERNEL);
	if (!lif->dbid_inuse) {
		dev_err(dev, "Failed alloc doorbell id bitmap, aborting\n");
		return -ENOMEM;
	}

	/* first doorbell id reserved for kernel (dbid aka pid == zero) */
	set_bit(0, lif->dbid_inuse);
	lif->kern_pid = 0;

	dbpage_num = ionic_db_page_num(lif, lif->kern_pid);
	lif->kern_dbpage = ionic_bus_map_dbpage(lif->ionic, dbpage_num);
	if (!lif->kern_dbpage) {
		dev_err(dev, "Cannot map dbpage, aborting\n");
		err = -ENOMEM;
		goto err_out_free_dbid;
	}

	err = ionic_lif_adminq_init(lif);
	if (err)
		goto err_out_adminq_deinit;

	if (is_master_lif(lif) && lif->ionic->nnqs_per_lif) {
		err = ionic_lif_notifyq_init(lif);
		if (err)
			goto err_out_notifyq_deinit;
	}

	err = ionic_init_nic_features(lif);
	if (err)
		goto err_out_notifyq_deinit;

	err = ionic_rx_filters_init(lif);
	if (err)
		goto err_out_notifyq_deinit;

	err = ionic_station_set(lif);
	if (err)
		goto err_out_notifyq_deinit;

	lif->rx_copybreak = rx_copybreak;

	lif->api_private = NULL;
	set_bit(LIF_INITED, lif->state);
	set_bit(LIF_F_FW_READY, lif->state);

	ionic_link_status_check(lif);

	INIT_WORK(&lif->tx_timeout_work, ionic_tx_timeout_work);
	return 0;

err_out_notifyq_deinit:
	ionic_lif_qcq_deinit(lif, lif->notifyqcq);
err_out_adminq_deinit:
	ionic_lif_qcq_deinit(lif, lif->adminqcq);
	ionic_lif_reset(lif);
	ionic_bus_unmap_dbpage(lif->ionic, lif->kern_dbpage);
	lif->kern_dbpage = NULL;
err_out_free_dbid:
	kfree(lif->dbid_inuse);
	lif->dbid_inuse = NULL;

	return err;
}

int ionic_lifs_init(struct ionic *ionic)
{
	struct list_head *cur, *tmp;
	struct lif *lif;
	int err;

	list_for_each_safe(cur, tmp, &ionic->lifs) {
		lif = list_entry(cur, struct lif, list);
		err = ionic_lif_init(lif);
		if (err)
			return err;
	}

	return 0;
}

static int ionic_lif_register(struct lif *lif)
{
	struct device *dev = lif->ionic->dev;
	int err;

	err = register_netdev(lif->netdev);
	if (err) {
		dev_err(dev, "Cannot register net device, aborting\n");
		return err;
	}

	ionic_link_status_check(lif);
	lif->registered = true;

	return 0;
}

static void ionic_lif_notify_work(struct work_struct *ws)
{
}

#ifndef DISABLE_LINK_AG_SUPPORT
#ifdef NETDEV_CHANGEUPPER
static void ionic_lif_changeupper(struct ionic *ionic, struct lif *lif,
				  struct netdev_notifier_changeupper_info *info)
{
	struct netdev_lag_upper_info *upper_info;

	dev_dbg(ionic->dev, "lif %d is lag port %d\n",
		lif->index, netif_is_lag_port(lif->netdev));
	dev_dbg(ionic->dev, "lif %d upper %s is lag master %d\n",
		lif->index, info->upper_dev->name,
		netif_is_lag_master(info->upper_dev));
	dev_dbg(ionic->dev, "lif %d has upper info %d\n",
		lif->index, !!info->upper_info);

	if (!netif_is_lag_port(lif->netdev) ||
	    !netif_is_lag_master(info->upper_dev) ||
	    !info->upper_info)
		return;

	upper_info = info->upper_info;

	dev_dbg(ionic->dev, "upper tx type %d\n",
		upper_info->tx_type);
}
#endif /* NETDEV_CHANGEUPPER */

#ifdef NETDEV_CHANGELOWERSTATE
static void ionic_lif_changelowerstate(struct ionic *ionic, struct lif *lif,
			    struct netdev_notifier_changelowerstate_info *info)
{
	struct netdev_lag_lower_state_info *lower_info;

	dev_dbg(ionic->dev, "lif %d is lag port %d\n",
		lif->index, netif_is_lag_port(lif->netdev));
	dev_dbg(ionic->dev, "lif %d has lower info %d\n",
		lif->index, !!info->lower_state_info);

	if (!netif_is_lag_port(lif->netdev) ||
	    !info->lower_state_info)
		return;

	lower_info = info->lower_state_info;

	dev_dbg(ionic->dev, "link up %d enable %d\n",
		lower_info->link_up, lower_info->tx_enabled);
}
#endif /* NETDEV_CHANGELOWERSTATE */
#endif /* DISABLE_LINK_AG_SUPPORT */

static void ionic_lif_set_netdev_info(struct lif *lif)
{
	struct ionic_admin_ctx ctx = {
		.work = COMPLETION_INITIALIZER_ONSTACK(ctx.work),
		.cmd.lif_setattr = {
			.opcode = CMD_OPCODE_LIF_SETATTR,
			.index = cpu_to_le16(lif->index),
			.attr = IONIC_LIF_ATTR_NAME,
		},
	};

	if (is_master_lif(lif))
		strlcpy(ctx.cmd.lif_setattr.name, lif->netdev->name,
			sizeof(ctx.cmd.lif_setattr.name));
	else
		strlcpy(ctx.cmd.lif_setattr.name, lif->upper_dev->name,
			sizeof(ctx.cmd.lif_setattr.name));

	dev_info(lif->ionic->dev, "NETDEV_CHANGENAME %s %s\n",
		 lif->name, ctx.cmd.lif_setattr.name);

	ionic_adminq_post_wait(lif, &ctx);
}

struct lif *ionic_netdev_lif(struct net_device *netdev)
{
	if (!netdev || netdev->netdev_ops->ndo_start_xmit != ionic_start_xmit)
		return NULL;

	return netdev_priv(netdev);
}

static int ionic_lif_notify(struct notifier_block *nb,
			    unsigned long event, void *info)
{
	struct ionic *ionic = container_of(nb, struct ionic, nb);
	struct net_device *ndev = netdev_notifier_info_to_dev(info);
	struct lif *lif = ionic_netdev_lif(ndev);

	if (!lif || lif->ionic != ionic)
		return NOTIFY_DONE;

	switch (event) {
#ifndef DISABLE_LINK_AG_SUPPORT
#ifdef NETDEV_CHANGEUPPER
	case NETDEV_CHANGEUPPER:
		ionic_lif_changeupper(ionic, lif, info);
		break;
#endif
#ifdef NETDEV_CHANGELOWERSTATE
	case NETDEV_CHANGELOWERSTATE:
		ionic_lif_changelowerstate(ionic, lif, info);
		break;
#endif
#endif /* DISABLE_LINK_AG_SUPPORT */
	case NETDEV_CHANGENAME:
		ionic_lif_set_netdev_info(lif);
		break;
	default:
		return NOTIFY_DONE;
	}

	return NOTIFY_DONE;
}

int ionic_lifs_register(struct ionic *ionic)
{
	int err;

	INIT_WORK(&ionic->nb_work, ionic_lif_notify_work);

	ionic->nb.notifier_call = ionic_lif_notify;

	err = register_netdevice_notifier(&ionic->nb);
	if (err)
		ionic->nb.notifier_call = NULL;

	return ionic_lif_register(ionic->master_lif);
}

void ionic_lifs_unregister(struct ionic *ionic)
{
	if (ionic->nb.notifier_call) {
		unregister_netdevice_notifier(&ionic->nb);
		cancel_work_sync(&ionic->nb_work);
		ionic->nb.notifier_call = NULL;
	}

	/* There is only one lif every registered in the
	 * current model, so don't bother searching the
	 * ionic->lif for candidates to unregister
	 */
	if (ionic->master_lif->netdev->reg_state == NETREG_REGISTERED)
		unregister_netdev(ionic->master_lif->netdev);
}

int ionic_lif_identify(struct ionic *ionic, u8 lif_type,
		       union lif_identity *lid)
{
	struct ionic_dev *idev = &ionic->idev;
	size_t sz;
	int err;

	sz = min(sizeof(*lid), sizeof(idev->dev_cmd_regs->data));

	mutex_lock(&ionic->dev_cmd_lock);
	ionic_dev_cmd_lif_identify(idev, lif_type, IONIC_IDENTITY_VERSION_1);
	err = ionic_dev_cmd_wait(ionic, devcmd_timeout);
	memcpy_fromio(lid, &idev->dev_cmd_regs->data, sz);
	mutex_unlock(&ionic->dev_cmd_lock);
	if (err)
		return (err);

	dev_dbg(ionic->dev, "capabilities 0x%llx\n",
		le64_to_cpu(lid->capabilities));

	dev_dbg(ionic->dev, "eth.max_ucast_filters %d\n",
		le32_to_cpu(lid->eth.max_ucast_filters));
	dev_dbg(ionic->dev, "eth.max_mcast_filters %d\n",
		le32_to_cpu(lid->eth.max_mcast_filters));
	dev_dbg(ionic->dev, "eth.features 0x%llx\n",
		le64_to_cpu(lid->eth.config.features));
	dev_dbg(ionic->dev, "eth.queue_count[IONIC_QTYPE_ADMINQ] %d\n",
		le32_to_cpu(lid->eth.config.queue_count[IONIC_QTYPE_ADMINQ]));
	dev_dbg(ionic->dev, "eth.queue_count[IONIC_QTYPE_NOTIFYQ] %d\n",
		le32_to_cpu(lid->eth.config.queue_count[IONIC_QTYPE_NOTIFYQ]));
	dev_dbg(ionic->dev, "eth.queue_count[IONIC_QTYPE_RXQ] %d\n",
		le32_to_cpu(lid->eth.config.queue_count[IONIC_QTYPE_RXQ]));
	dev_dbg(ionic->dev, "eth.queue_count[IONIC_QTYPE_TXQ] %d\n",
		le32_to_cpu(lid->eth.config.queue_count[IONIC_QTYPE_TXQ]));
	dev_dbg(ionic->dev, "eth.config.name %s\n", lid->eth.config.name);
	dev_dbg(ionic->dev, "eth.config.mac %pM\n", lid->eth.config.mac);
	dev_dbg(ionic->dev, "eth.config.mtu %d\n",
		le32_to_cpu(lid->eth.config.mtu));

	return 0;
}

int ionic_lifs_size(struct ionic *ionic)
{
	struct identity *ident = &ionic->ident;
	union lif_config *lc = &ident->lif.eth.config;
	unsigned int nintrs, dev_nintrs;
	unsigned int ntxqs_per_lif;
	unsigned int nrxqs_per_lif;
	unsigned int neqs_per_lif;
	unsigned int nnqs_per_lif;
	unsigned int nxqs, neqs;
	unsigned int min_intrs;
	unsigned int nslaves;
	unsigned int nlifs;
	int err;

	nlifs = le32_to_cpu(ident->dev.nlifs);
	dev_nintrs = le32_to_cpu(ident->dev.nintrs);
	neqs_per_lif = le32_to_cpu(ident->lif.rdma.eq_qtype.qid_count);
	nnqs_per_lif = le32_to_cpu(lc->queue_count[IONIC_QTYPE_NOTIFYQ]);
	ntxqs_per_lif = le32_to_cpu(lc->queue_count[IONIC_QTYPE_TXQ]);
	nrxqs_per_lif = le32_to_cpu(lc->queue_count[IONIC_QTYPE_RXQ]);

	if (max_slaves)
		nslaves = min(max_slaves, nlifs - 1);
	else
		nslaves = nlifs - 1;

	nxqs = min(ntxqs_per_lif, nrxqs_per_lif);
	nxqs = min(nxqs, num_online_cpus());
	neqs = min(neqs_per_lif, num_online_cpus());

try_again:
	/* interrupt usage:
	 *    1 for master lif adminq/notifyq
	 *    1 for each CPU for master lif TxRx queue pairs
	 *    2 for each slave lif: 1 adminq, 1 TxRx queuepair
	 *    whatever's left is for RDMA queues
	 */
	nintrs = 1 + nxqs + (nslaves * 2) + neqs;
	min_intrs = 2;  /* adminq + 1 TxRx queue pair */

	if (nintrs > dev_nintrs)
		goto try_fewer;

	err = ionic_bus_alloc_irq_vectors(ionic, nintrs);
	if (err < 0 && err != -ENOSPC) {
		dev_err(ionic->dev, "Can't get intrs from OS: %d\n", err);
		return err;
	}
	if (err == -ENOSPC)
		goto try_fewer;

	if (err != nintrs) {
		ionic_bus_free_irq_vectors(ionic);
		goto try_fewer;
	}

	ionic->nnqs_per_lif = nnqs_per_lif;
	ionic->neqs_per_lif = neqs;
	ionic->ntxqs_per_lif = nxqs;
	ionic->nrxqs_per_lif = nxqs;
	ionic->nintrs = nintrs;
	ionic->nslaves = nslaves;

	return ionic_debugfs_add_sizes(ionic);

try_fewer:
	if (nnqs_per_lif > 1) {
		nnqs_per_lif >>= 1;
		goto try_again;
	}
	if (neqs > 1) {
		neqs >>= 1;
		goto try_again;
	}
	if (nslaves) {
		nslaves >>= 1;
		goto try_again;
	}
	if (nxqs > 1) {
		nxqs >>= 1;
		goto try_again;
	}
	dev_err(ionic->dev, "Can't get minimum %d intrs from OS\n", min_intrs);
	return -ENOSPC;
}
