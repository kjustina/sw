/* SPDX-License-Identifier: GPL-2.0 OR Linux-OpenIB */
#ifdef __FreeBSD__
/*
 * Copyright (c) 2018-2020 Pensando Systems, Inc.  All rights reserved.
 *
 * This software is available to you under a choice of one of two
 * licenses.  You may choose to be licensed under the terms of the GNU
 * General Public License (GPL) Version 2, available from the file
 * COPYING in the main directory of this source tree, or the
 * OpenIB.org BSD license below:
 *
 *     Redistribution and use in source and binary forms, with or
 *     without modification, are permitted provided that the following
 *     conditions are met:
 *
 *      - Redistributions of source code must retain the above
 *        copyright notice, this list of conditions and the following
 *        disclaimer.
 *
 *      - Redistributions in binary form must reproduce the above
 *        copyright notice, this list of conditions and the following
 *        disclaimer in the documentation and/or other materials
 *        provided with the distribution.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#else
/*
 * Copyright (c) 2018-2020 Pensando Systems, Inc.  All rights reserved.
 */
#endif /* __FreeBSD__ */

#ifndef IONIC_KCOMPAT
#define IONIC_KCOMPAT

#include <rdma/ib_pack.h>
#include <rdma/ib_verbs.h>

/****************************************************************************
 *
 * Compatibility for kernel-only features (not affected by OFA version)
 *
 */
#ifdef __FreeBSD__
#include <linux/sysfs.h>
#include <linux/delay.h>
#include <linux/etherdevice.h>
#include <ionic_kpicompat.h>
#if __FreeBSD_version >= 1200000
#include <ck_queue.h>
#endif

#define FW_INFO "[Firmware Info]: "

extern const struct sysfs_ops kobj_sysfs_ops;

static inline int
sysfs_create_group_check_name(struct kobject *kobj,
			      const struct attribute_group *grp)
{
	struct attribute **attr;

	if (grp->name) {
		sysfs_create_group(kobj, grp);
	} else {
		for (attr = grp->attrs; *attr; ++attr)
			sysfs_create_file(kobj, *attr);
	}

	return 0;
}
#define sysfs_create_group sysfs_create_group_check_name

static inline int
sysfs_remove_group_check_name(struct kobject *kobj,
			      const struct attribute_group *grp)
{
	struct attribute **attr;

	if (grp->name) {
		sysfs_remove_group(kobj, grp);
	} else {
		for (attr = grp->attrs; *attr; ++attr)
			sysfs_remove_file(kobj, *attr);
	}

	return 0;
}
#define sysfs_remove_group sysfs_remove_group_check_name

int sysfs_create_groups(struct kobject *kobj,
			const struct attribute_group **groups);

void sysfs_remove_groups(struct kobject *kobj,
			 const struct attribute_group **groups);

static inline bool
dev_is_pci(struct device *d)
{
	return true;
}

#define local_irq_save(f) do { (f) = 0; } while (0)
#define local_irq_restore(f) (void)(f)

static inline int raw_smp_processor_id(void)
{
	return curcpu;
}
#else /* __FreeBSD__ */
#include <linux/version.h>
#include <linux/netdevice.h>

#if defined(RHEL_RELEASE_VERSION)
#define IONIC_KCOMPAT_KERN_VERSION_PRIOR_TO(LX_MAJ, LX_MIN, RH_MAJ, RH_MIN) \
	(RHEL_RELEASE_CODE < RHEL_RELEASE_VERSION(RH_MAJ, RH_MIN))
#else
#define IONIC_KCOMPAT_KERN_VERSION_PRIOR_TO(LX_MAJ, LX_MIN, RH_MAJ, RH_MIN) \
	(LINUX_VERSION_CODE < KERNEL_VERSION(LX_MAJ, LX_MIN, 0))
#endif

#if IONIC_KCOMPAT_KERN_VERSION_PRIOR_TO(/* Linux */ 4,14, /* RHEL */ 99,99)
#else /* 4.14.0 and later */
#define HAVE_GET_VECTOR_AFFINITY
#endif

#if IONIC_KCOMPAT_KERN_VERSION_PRIOR_TO(/* Linux */ 3,11, /* RHEL */ 99,99)
#define netdev_notifier_info_to_dev(ptr) (ptr)
#endif

#if IONIC_KCOMPAT_KERN_VERSION_PRIOR_TO(/* Linux */ 4,10, /* RHEL */ 99,99)
#else /* 4.10.0 and later */
#define HAVE_NETDEV_MAX_MTU
#endif

#if IONIC_KCOMPAT_KERN_VERSION_PRIOR_TO(/* Linux */ 4,17, /* RHEL */ 99,99)
#elif IONIC_KCOMPAT_KERN_VERSION_PRIOR_TO(/* Linux */ 4,20, /* RHEL */ 99,99)
/* 4.17, 4.18, 4.19: A radix_tree now includes a spinlock called xa_lock */
#define HAVE_RADIX_TREE_LOCK
#elif IONIC_KCOMPAT_KERN_VERSION_PRIOR_TO(/* Linux */ 5,0, /* RHEL */ 99,99)
/* 4.20: xa_for_each() has extra arguments */
#define HAVE_XARRAY
#define HAVE_XARRAY_FOR_EACH_ARGS
#else /* 5.0 and later */
#define HAVE_XARRAY
#endif

#if IONIC_KCOMPAT_KERN_VERSION_PRIOR_TO(/* Linux */ 5,0, /* RHEL */ 99,99)
/* Use dma_zalloc_coherent() */
#define HAVE_ZALLOC_COHERENT
#else
/* Use dma_alloc_coherent() */
#endif

#define IF_LLADDR(ndev) (ndev->dev_addr)
#endif /* __FreeBSD__ */

#ifdef HAVE_XARRAY
#ifdef HAVE_XARRAY_FOR_EACH_ARGS
#include <linux/xarray.h>
#undef xa_for_each
#define xa_for_each(xa, index, entry)					\
	for (entry = xa_find(xa, &index, ULONG_MAX, XA_PRESENT); entry;	\
	     entry = xa_find_after(xa, &index, ULONG_MAX, XA_PRESENT))
#endif /* HAVE_XARRAY_FOR_EACH_ARGS */
#else /* HAVE_XARRAY */
/* Create an xarray from a radix_tree_root */
#include <linux/radix-tree.h>

#ifdef HAVE_RADIX_TREE_LOCK
#define xarray       radix_tree_root
#define xa_tree
#define xa_init(_xa) INIT_RADIX_TREE((_xa), GFP_KERNEL)
#else
struct xarray {
	spinlock_t x_lock;
	struct radix_tree_root x_tree;
};
#define xa_tree(_xa) &(_xa)->x_tree
static inline void xa_init(struct xarray *xa)
{
	spin_lock_init(&xa->x_lock);
	INIT_RADIX_TREE(xa_tree(xa), GFP_KERNEL);
}

#define xa_lock(_xa) spin_lock(&(_xa)->x_lock)
#define xa_unlock(_xa) spin_unlock(&(_xa)->x_lock)
#define xa_lock_irq(_xa) spin_lock_irq(&(_xa)->x_lock)
#define xa_unlock_irq(_xa) spin_unlock_irq(&(_xa)->x_lock)
#define xa_lock_irqsave(_xa, _flags)					\
	spin_lock_irqsave(&(_xa)->x_lock, _flags)
#define xa_unlock_irqrestore(_xa, _flags)				\
	spin_unlock_irqrestore(&(_xa)->x_lock, _flags)

#endif /* HAVE_RADIX_TREE_LOCK */

#define xa_iter radix_tree_iter
#define xa_for_each_slot(_xa, _slot, _iter)				\
	radix_tree_for_each_slot((_slot), xa_tree(_xa), (_iter), 0)
#define xa_load(_xa, _idx) radix_tree_lookup(xa_tree(_xa), _idx)
#define xa_destroy(_xa)

static inline void *xa_store_irq(struct xarray *xa, unsigned long idx,
				 void *item, gfp_t unused)
{
	int ret;

	xa_lock_irq(xa);
	ret = radix_tree_insert(xa_tree(xa), idx, item);
	xa_unlock_irq(xa);

	return (ret ? ERR_PTR(ret) : item);
}

static inline int xa_err(void *item)
{
	return (IS_ERR(item) ? PTR_ERR(item) : 0);
}

static inline void xa_erase_irq(struct xarray *xa, unsigned long idx)
{
	xa_lock_irq(xa);
	radix_tree_delete(xa_tree(xa), idx);
	xa_unlock_irq(xa);
}
#endif /* HAVE_XARRAY */

/****************************************************************************
 *
 * Compatibility for OFED features that may be affected by OFA version
 *
 */
#ifdef __FreeBSD__
#define RDMA_CREATE_AH_SLEEPABLE 0
#else /* __FreeBSD__ */
#ifdef NOT_UPSTREAM
#if defined(OFA_KERNEL)
#include "ionic_kcompat_ofa.h"
#define IONIC_KCOMPAT_VERSION_PRIOR_TO(LX_MAJ, LX_MIN, RH_MAJ, RH_MIN, OFA) \
	OFA_COMPAT_CHECK(OFA_KERNEL, OFA)
#else
#define IONIC_KCOMPAT_VERSION_PRIOR_TO(LX_MAJ, LX_MIN, RH_MAJ, RH_MIN, OFA) \
	IONIC_KCOMPAT_KERN_VERSION_PRIOR_TO(LX_MAJ, LX_MIN, RH_MAJ, RH_MIN)
#endif

#if IONIC_KCOMPAT_VERSION_PRIOR_TO(/* Linux */ 4,8, /* RHEL */ 7,6, /* OFA */ 4_8)
#else /* 4.9.0 and later */
#define HAVE_QP_RWQ_IND_TBL
#endif

#if IONIC_KCOMPAT_VERSION_PRIOR_TO(/* Linux */ 4,9, /* RHEL */ 7,4, /* OFA */ 4_9a)
#define IB_DEVICE_NODE_DESC_MAX sizeof(((struct ib_device *)0)->node_desc)
#endif

#if IONIC_KCOMPAT_VERSION_PRIOR_TO(/* Linux */ 4,9, /* RHEL */ 7,5, /* OFA */ 4_9b)
#else /* 4.9.0 and later */
#define HAVE_IB_PD_FLAGS
#endif

#if IONIC_KCOMPAT_VERSION_PRIOR_TO(/* Linux */ 4,10, /* RHEL */ 7,4, /* OFA */ 4_10a)
#else /* 4.10.0 and later */
#define HAVE_IB_MTU_INT_TO_ENUM
#define HAVE_GET_DEV_FW_STR
#define HAVE_CREATE_AH_UDATA
#define HAVE_EX_CMD_MODIFY_QP
#define HAVE_QP_RATE_LIMIT
#endif

#if IONIC_KCOMPAT_VERSION_PRIOR_TO(/* Linux */ 4,11, /* RHEL */ 7,5, /* OFA */ 4_11)
#define HAVE_REQUIRED_DMA_DEVICE
#endif

#if IONIC_KCOMPAT_VERSION_PRIOR_TO(/* Linux */ 4,12, /* RHEL */ 7,5, /* OFA */ 4_12)
#else /* 4.12.0 and later */
#define HAVE_RDMA_AH_ATTR
#define HAVE_RDMA_AH_ATTR_TYPE_ROCE
#endif

#if IONIC_KCOMPAT_VERSION_PRIOR_TO(/* Linux */ 4,14, /* RHEL */ 7,5, /* OFA */ 4_14a)
#else
#define HAVE_IB_GET_ETH_SPEED
#endif

#if IONIC_KCOMPAT_VERSION_PRIOR_TO(/* Linux */ 4,14, /* RHEL */ 7,5, /* OFA */ 4_14b)
#define HAVE_GET_DEV_FW_STR_LEN
#else /* 4.14.0 and later */
#define HAVE_IB_SRQ_HAS_CQ
#define HAVE_SRQ_EXT_CQ
#endif

#if IONIC_KCOMPAT_VERSION_PRIOR_TO(/* Linux */ 4,14, /* RHEL */ 99,99, /* OFA */ 4_14c)
#else /* 4.14.0 and later */
#define HAVE_QP_INIT_SRC_QPN
#endif

#if IONIC_KCOMPAT_VERSION_PRIOR_TO(/* Linux */ 4,15, /* RHEL */ 7,6, /* OFA */ 4_15)
/* XXX UEK
 *
 * Oracle Linux removed the symbol export for ib_resolve_eth_dmac, so we can't
 * call it from the driver.  Defining the macro below disables the driver code.
 *
 * User space verbs with UD type QPs is broken on Oracle Linux.
 */
#ifdef _LINUX_UEK_KABI_H
#define HAVE_CREATE_AH_UDATA_DMAC
#endif
#else /* 4.15.0 and later */
#define HAVE_CREATE_AH_UDATA_DMAC
#endif

#if IONIC_KCOMPAT_VERSION_PRIOR_TO(/* Linux */ 4,17, /* RHEL */ 99,99, /* OFA */ 4_17)
#define HAVE_IB_GID_DEV_PORT_INDEX
#else /* 4.17.0 and later */
#define HAVE_RDMA_DRIVER_ID
#endif

#if IONIC_KCOMPAT_VERSION_PRIOR_TO(/* Linux */ 4,19, /* RHEL */ 99,99, /* OFA */ 4_19a)
#define HAVE_REQUIRED_IB_GID
#else
#define HAVE_AH_ATTR_CACHED_GID
#endif

#if IONIC_KCOMPAT_VERSION_PRIOR_TO(/* Linux */ 4,19, /* RHEL */ 99,99, /* OFA */ 4_19b)
#define ud_wr(wr) ud_wr((struct ib_send_wr *)(wr))
#define rdma_wr(wr) rdma_wr((struct ib_send_wr *)(wr))
#define atomic_wr(wr) atomic_wr((struct ib_send_wr *)(wr))
#define reg_wr(wr) reg_wr((struct ib_send_wr *)(wr))
#else
#define HAVE_CONST_IB_WR
#define HAVE_IBDEV_MAX_SEND_RECV_SGE
#endif

#if IONIC_KCOMPAT_VERSION_PRIOR_TO(/* Linux */ 4,19, /* RHEL */ 99,99, /* OFA */ 4_19c)
#else
#define HAVE_PORT_ATTR_IP_GIDS
#endif

#if IONIC_KCOMPAT_VERSION_PRIOR_TO(/* Linux */ 4,20, /* RHEL */ 99,99, /* OFA */ 4_20)
#define HAVE_IB_MODIFY_QP_IS_OK_LINK_LAYER
#else
#define HAVE_IB_REGISTER_DEVICE_NAME
#define HAVE_RDMA_DEV_SYSFS_GROUP
#endif

#if IONIC_KCOMPAT_VERSION_PRIOR_TO(/* Linux */ 5,0, /* RHEL */ 99,99, /* OFA */ 5_0)
#define HAVE_CUSTOM_IB_SET_DEVICE_OPS
#define RDMA_CREATE_AH_SLEEPABLE 0
#else
#define HAVE_CREATE_AH_FLAGS
#endif

#if IONIC_KCOMPAT_VERSION_PRIOR_TO(/* Linux */ 5,1, /* RHEL */ 99,99, /* OFA */ 5_0)
#else /* 5.1 and later */
#define HAVE_IB_REGISTER_DEVICE_NAME_ONLY
#define HAVE_IB_ALLOC_DEV_CONTAINER
#define HAVE_IB_ALLOC_UCTX_OBJ
#define HAVE_IB_DEALLOC_UCTX_VOID
#define HAVE_IB_ALLOC_PD_OBJ
#define HAVE_IB_DEALLOC_PD_VOID
#define HAVE_IB_UMEM_GET_UDATA
#endif

#if IONIC_KCOMPAT_VERSION_PRIOR_TO(/* Linux */ 5,2, /* RHEL */ 99,99, /* OFA */ 5_0)
#else /* 5.2 and later */
#define HAVE_IB_ALLOC_AH_OBJ
#define HAVE_IB_DESTROY_AH_VOID
#define HAVE_IB_ALLOC_SRQ_OBJ
#define HAVE_IB_DESTROY_SRQ_VOID
#define HAVE_IB_API_UDATA
#endif

#if IONIC_KCOMPAT_VERSION_PRIOR_TO(/* Linux */ 5,3, /* RHEL */ 99,99, /* OFA */ 5_0)
#else /* 5.3 and later */
#define HAVE_RDMA_DEV_OPS_EXT
#define HAVE_IB_ALLOC_CQ_OBJ
#define HAVE_IB_DESTROY_CQ_VOID
#endif

#if IONIC_KCOMPAT_VERSION_PRIOR_TO(/* Linux */ 5,4, /* RHEL */ 99,99, /* OFA */ 5_0)
#else /* 5.4 and later */
#define HAVE_IB_PORT_PHYS_STATE
#endif
#endif /* NOT_UPSTREAM */
#endif /* __FreeBSD__ */

#ifndef HAVE_IB_MTU_INT_TO_ENUM
static inline enum ib_mtu ib_mtu_int_to_enum(int mtu)
{
	if (mtu >= 4096)
		return IB_MTU_4096;
	else if (mtu >= 2048)
		return IB_MTU_2048;
	else if (mtu >= 1024)
		return IB_MTU_1024;
	else if (mtu >= 512)
		return IB_MTU_512;
	else
		return IB_MTU_256;
}

#endif /* HAVE_IB_MTU_INT_TO_ENUM */
#ifndef HAVE_RDMA_AH_ATTR
#define rdma_ah_attr ib_ah_attr
#define rdma_ah_read_grh(attr) (&(attr)->grh)

static inline void rdma_ah_set_sl(struct rdma_ah_attr *attr, u8 sl)
{
	attr->sl = sl;
}

static inline void rdma_ah_set_port_num(struct rdma_ah_attr *attr, u8 port_num)
{
	attr->port_num = port_num;
}

static inline void rdma_ah_set_grh(struct rdma_ah_attr *attr,
				   union ib_gid *dgid, u32 flow_label,
				   u8 sgid_index, u8 hop_limit,
				   u8 traffic_class)
{
	struct ib_global_route *grh = rdma_ah_read_grh(attr);

	attr->ah_flags = IB_AH_GRH;
	if (dgid)
		grh->dgid = *dgid;
	grh->flow_label = flow_label;
	grh->sgid_index = sgid_index;
	grh->hop_limit = hop_limit;
	grh->traffic_class = traffic_class;
}

static inline void rdma_ah_set_dgid_raw(struct rdma_ah_attr *attr, void *dgid)
{
	struct ib_global_route *grh = rdma_ah_read_grh(attr);

	memcpy(grh->dgid.raw, dgid, sizeof(grh->dgid));
}

#endif /* HAVE_RDMA_AH_ATTR */
#ifndef HAVE_IB_GET_ETH_SPEED
static inline int ib_get_eth_speed(struct ib_device *dev, u8 port_num,
				   u8 *speed, u8 *width)
{
	*width = IB_WIDTH_4X;
	*speed = IB_SPEED_EDR;
	return 0;
}

#endif /* HAVE_IB_GET_ETH_SPEED */
#ifdef IONIC_SRQ_XRC
#ifndef HAVE_IB_SRQ_HAS_CQ
static inline bool ib_srq_has_cq(enum ib_srq_type srq_type)
{
	return (srq_type == IB_SRQT_XRC);
}

#endif /* HAVE_IB_SRQ_HAS_CQ */
#endif /* IONIC_SRQ_XRC */
#ifdef HAVE_IB_MODIFY_QP_IS_OK_LINK_LAYER
#define ib_modify_qp_is_ok(cur_state, new_state, qp_type, attr_mask) \
	ib_modify_qp_is_ok(cur_state, new_state, qp_type, attr_mask, \
			   IB_LINK_LAYER_ETHERNET)

#endif
#ifdef HAVE_CUSTOM_IB_SET_DEVICE_OPS
struct ib_device_ops {
#ifdef HAVE_CONST_IB_WR
	int (*post_send)(struct ib_qp *qp, const struct ib_send_wr *send_wr,
			 const struct ib_send_wr **bad_send_wr);
	int (*post_recv)(struct ib_qp *qp, const struct ib_recv_wr *recv_wr,
			 const struct ib_recv_wr **bad_recv_wr);
	int (*post_srq_recv)(struct ib_srq *srq,
			     const struct ib_recv_wr *recv_wr,
			     const struct ib_recv_wr **bad_recv_wr);
#else
	int (*post_send)(struct ib_qp *qp, struct ib_send_wr *send_wr,
			 struct ib_send_wr **bad_send_wr);
	int (*post_recv)(struct ib_qp *qp, struct ib_recv_wr *recv_wr,
			 struct ib_recv_wr **bad_recv_wr);
	int (*post_srq_recv)(struct ib_srq *srq,
			     struct ib_recv_wr *recv_wr,
			     struct ib_recv_wr **bad_recv_wr);
#endif /* HAVE_CONST_IB_WR */
	void (*drain_rq)(struct ib_qp *qp);
	void (*drain_sq)(struct ib_qp *qp);
	int (*poll_cq)(struct ib_cq *cq, int num_entries, struct ib_wc *wc);
	int (*peek_cq)(struct ib_cq *cq, int wc_cnt);
	int (*req_notify_cq)(struct ib_cq *cq, enum ib_cq_notify_flags flags);
	int (*req_ncomp_notif)(struct ib_cq *cq, int wc_cnt);
	int (*query_device)(struct ib_device *device,
			    struct ib_device_attr *device_attr,
			    struct ib_udata *udata);
	int (*modify_device)(struct ib_device *device, int device_modify_mask,
			     struct ib_device_modify *device_modify);
#ifdef HAVE_GET_DEV_FW_STR_LEN
	void (*get_dev_fw_str)(struct ib_device *device, char *str,
			       size_t str_len);
#else
	void (*get_dev_fw_str)(struct ib_device *device, char *str);
#endif
#ifdef HAVE_GET_VECTOR_AFFINITY
	const struct cpumask *(*get_vector_affinity)(struct ib_device *ibdev,
						     int comp_vector);
#endif
	int (*query_port)(struct ib_device *device, u8 port_num,
			  struct ib_port_attr *port_attr);
	int (*modify_port)(struct ib_device *device, u8 port_num,
			   int port_modify_mask,
			   struct ib_port_modify *port_modify);
	int (*get_port_immutable)(struct ib_device *device, u8 port_num,
				  struct ib_port_immutable *immutable);
	enum rdma_link_layer (*get_link_layer)(struct ib_device *device,
					       u8 port_num);
	struct net_device *(*get_netdev)(struct ib_device *device,
					 u8 port_num);
#ifdef HAVE_REQUIRED_IB_GID
	int (*query_gid)(struct ib_device *device, u8 port_num, int index,
			 union ib_gid *gid);
#ifdef HAVE_IB_GID_DEV_PORT_INDEX
	int (*add_gid)(struct ib_device *device, u8 port, unsigned int index,
		       const union ib_gid *gid, const struct ib_gid_attr *attr,
		       void **context);
	int (*del_gid)(struct ib_device *device, u8 port, unsigned int index,
		       void **context);
#else
	int (*add_gid)(const union ib_gid *gid, const struct ib_gid_attr *attr,
		       void **context);
	int (*del_gid)(const struct ib_gid_attr *attr, void **context);
#endif /* HAVE_IB_GID_DEV_PORT_INDEX */
#endif /* HAVE_REQUIRED_IB_GID */
	int (*query_pkey)(struct ib_device *device, u8 port_num, u16 index,
			  u16 *pkey);
	struct ib_ucontext *(*alloc_ucontext)(struct ib_device *device,
					      struct ib_udata *udata);
	int (*dealloc_ucontext)(struct ib_ucontext *context);
	int (*mmap)(struct ib_ucontext *context, struct vm_area_struct *vma);
	void (*disassociate_ucontext)(struct ib_ucontext *ibcontext);
	struct ib_pd *(*alloc_pd)(struct ib_device *device,
				  struct ib_ucontext *context,
				  struct ib_udata *udata);
	int (*dealloc_pd)(struct ib_pd *pd);
#ifdef HAVE_CREATE_AH_UDATA
#ifdef HAVE_CREATE_AH_FLAGS
	struct ib_ah *(*create_ah)(struct ib_pd *pd,
				   struct rdma_ah_attr *ah_attr, u32 flags,
				   struct ib_udata *udata);
#else
	struct ib_ah *(*create_ah)(struct ib_pd *pd,
				   struct rdma_ah_attr *ah_attr,
				   struct ib_udata *udata);
#endif /* HAVE_CREATE_AH_FLAGS */
#else
	struct ib_ah *(*create_ah)(struct ib_pd *pd,
				   struct rdma_ah_attr *ah_attr);
#endif /* HAVE_CREATE_AH_UDATA */
	int (*modify_ah)(struct ib_ah *ah, struct rdma_ah_attr *ah_attr);
	int (*query_ah)(struct ib_ah *ah, struct rdma_ah_attr *ah_attr);
#ifdef HAVE_CREATE_AH_FLAGS
	int (*destroy_ah)(struct ib_ah *ah, u32 flags);
#else
	int (*destroy_ah)(struct ib_ah *ah);
#endif
	struct ib_srq *(*create_srq)(struct ib_pd *pd,
				     struct ib_srq_init_attr *srq_init_attr,
				     struct ib_udata *udata);
	int (*modify_srq)(struct ib_srq *srq, struct ib_srq_attr *srq_attr,
			  enum ib_srq_attr_mask srq_attr_mask,
			  struct ib_udata *udata);
	int (*query_srq)(struct ib_srq *srq, struct ib_srq_attr *srq_attr);
	int (*destroy_srq)(struct ib_srq *srq);
	struct ib_qp *(*create_qp)(struct ib_pd *pd,
				   struct ib_qp_init_attr *qp_init_attr,
				   struct ib_udata *udata);
	int (*modify_qp)(struct ib_qp *qp, struct ib_qp_attr *qp_attr,
			 int qp_attr_mask, struct ib_udata *udata);
	int (*query_qp)(struct ib_qp *qp, struct ib_qp_attr *qp_attr,
			int qp_attr_mask,
			struct ib_qp_init_attr *qp_init_attr);
	int (*destroy_qp)(struct ib_qp *qp);
	struct ib_cq *(*create_cq)(struct ib_device *device,
				   const struct ib_cq_init_attr *attr,
				   struct ib_ucontext *context,
				   struct ib_udata *udata);
	int (*modify_cq)(struct ib_cq *cq, u16 cq_count, u16 cq_period);
	int (*destroy_cq)(struct ib_cq *cq);
	int (*resize_cq)(struct ib_cq *cq, int cqe, struct ib_udata *udata);
	struct ib_mr *(*get_dma_mr)(struct ib_pd *pd, int mr_access_flags);
#ifdef HAVE_IB_USER_MR_INIT_ATTR
	struct ib_mr *(*reg_user_mr)(struct ib_pd *pd,
				     struct ib_mr_init_attr *attr,
				     struct ib_udata *udata);
#else
	struct ib_mr *(*reg_user_mr)(struct ib_pd *pd, u64 start, u64 length,
				     u64 virt_addr, int mr_access_flags,
				     struct ib_udata *udata);
#endif
	int (*rereg_user_mr)(struct ib_mr *mr, int flags, u64 start,
			     u64 length, u64 virt_addr, int mr_access_flags,
			     struct ib_pd *pd, struct ib_udata *udata);
	int (*dereg_mr)(struct ib_mr *mr);
	struct ib_mr *(*alloc_mr)(struct ib_pd *pd, enum ib_mr_type mr_type,
				  u32 max_num_sg);
	int (*map_mr_sg)(struct ib_mr *mr, struct scatterlist *sg,
			 int sg_nents, unsigned int *sg_offset);
	int (*check_mr_status)(struct ib_mr *mr, u32 check_mask,
			       struct ib_mr_status *mr_status);
	struct ib_mw *(*alloc_mw)(struct ib_pd *pd, enum ib_mw_type type,
				  struct ib_udata *udata);
	int (*dealloc_mw)(struct ib_mw *mw);
	int (*attach_mcast)(struct ib_qp *qp, union ib_gid *gid, u16 lid);
	int (*detach_mcast)(struct ib_qp *qp, union ib_gid *gid, u16 lid);
	struct ib_xrcd *(*alloc_xrcd)(struct ib_device *device,
				      struct ib_ucontext *ucontext,
				      struct ib_udata *udata);
	int (*dealloc_xrcd)(struct ib_xrcd *xrcd);
	struct rdma_hw_stats *(*alloc_hw_stats)(struct ib_device *device,
						u8 port_num);
	int (*get_hw_stats)(struct ib_device *device,
			    struct rdma_hw_stats *stats, u8 port, int index);
};

void ib_set_device_ops(struct ib_device *dev, const struct ib_device_ops *ops);

#endif /* HAVE_CUSTOM_IB_SET_DEVICE_OPS */
#ifndef HAVE_IB_PORT_PHYS_STATE
enum ib_port_phys_state {
	IB_PORT_PHYS_STATE_SLEEP = 1,
	IB_PORT_PHYS_STATE_POLLING = 2,
	IB_PORT_PHYS_STATE_DISABLED = 3,
	IB_PORT_PHYS_STATE_PORT_CONFIGURATION_TRAINING = 4,
	IB_PORT_PHYS_STATE_LINK_UP = 5,
	IB_PORT_PHYS_STATE_LINK_ERROR_RECOVERY = 6,
	IB_PORT_PHYS_STATE_PHY_TEST = 7,
};

#endif /* HAVE_IB_PORT_PHYS_STATE */
#ifdef HAVE_RDMA_DRIVER_ID
#include <rdma/rdma_user_ioctl_cmds.h>
/* Upstream: QIB, EFA, SIW, <us> */
enum {
	RDMA_DRIVER_IONIC = RDMA_DRIVER_QIB + 3,
};

#endif /* HAVE_RDMA_DRIVER_ID */
/**
 * roce_ud_header_unpack - Unpack UD header struct from RoCE wire format
 * @header:UD header struct
 * @buf:Buffer to unpack into
 *
 * roce_ud_header_pack() unpacks the UD header structure @header from RoCE wire
 * format in the buffer @buf.
 */
int roce_ud_header_unpack(void *buf, struct ib_ud_header *header);

#endif /* IONIC_KCOMPAT */