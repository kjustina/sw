/* SPDX-License-Identifier: GPL-2.0 OR Linux-OpenIB */
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

#ifndef IONIC_FW_H
#define IONIC_FW_H

#include <linux/kernel.h>
#include <rdma/ib_verbs.h>

/* common for ib spec */

enum ionic_mrid_bits {
	IONIC_MRID_INDEX_SHIFT		= 8,
};

static inline u32 ionic_mrid(u32 index, u8 key)
{
	return (index << IONIC_MRID_INDEX_SHIFT) | key;
}

static inline u32 ionic_mrid_index(u32 lrkey)
{
	return lrkey >> IONIC_MRID_INDEX_SHIFT;
}

/* common to all versions */

/* wqe scatter gather element */
struct ionic_sge {
	__be64				va;
	__be32				len;
	__be32				lkey;
};

/* admin queue mr type */
enum ionic_mr_flags {
	/* bits that determine mr access */
	IONIC_MRF_LOCAL_WRITE		= BIT(0),
	IONIC_MRF_REMOTE_WRITE		= BIT(1),
	IONIC_MRF_REMOTE_READ		= BIT(2),
	IONIC_MRF_REMOTE_ATOMIC		= BIT(3),
	IONIC_MRF_MW_BIND		= BIT(4),
	IONIC_MRF_ZERO_BASED		= BIT(5),
	IONIC_MRF_ON_DEMAND		= BIT(6),
	IONIC_MRF_ACCESS_MASK		= BIT(12) - 1,

	/* bits that determine mr type */
	IONIC_MRF_UKEY_EN		= BIT(13),
	IONIC_MRF_IS_MW			= BIT(14),
	IONIC_MRF_INV_EN		= BIT(15),

	/* base flags combinations for mr types */
	IONIC_MRF_USER_MR		= 0,
	IONIC_MRF_PHYS_MR		= (IONIC_MRF_UKEY_EN |
					   IONIC_MRF_INV_EN),
	IONIC_MRF_MW_1			= (IONIC_MRF_UKEY_EN |
					   IONIC_MRF_IS_MW),
	IONIC_MRF_MW_2			= (IONIC_MRF_UKEY_EN |
					   IONIC_MRF_IS_MW |
					   IONIC_MRF_INV_EN),
};

static inline int to_ionic_mr_flags(int access)
{
	int flags = 0;

	if (access & IB_ACCESS_LOCAL_WRITE)
		flags |= IONIC_MRF_LOCAL_WRITE;

	if (access & IB_ACCESS_REMOTE_READ)
		flags |= IONIC_MRF_REMOTE_READ;

	if (access & IB_ACCESS_REMOTE_WRITE)
		flags |= IONIC_MRF_REMOTE_WRITE;

	if (access & IB_ACCESS_REMOTE_ATOMIC)
		flags |= IONIC_MRF_REMOTE_ATOMIC;

	if (access & IB_ACCESS_MW_BIND)
		flags |= IONIC_MRF_MW_BIND;

	if (access & IB_ZERO_BASED)
		flags |= IONIC_MRF_ZERO_BASED;

	return flags;
}

enum ionic_qp_flags {
	/* bits that determine qp access */
	IONIC_QPF_REMOTE_WRITE		= BIT(0),
	IONIC_QPF_REMOTE_READ		= BIT(1),
	IONIC_QPF_REMOTE_ATOMIC		= BIT(2),

	/* bits that determine other qp behavior */
	IONIC_QPF_SQ_SPEC		= BIT(8),
	IONIC_QPF_RQ_SPEC		= BIT(9),
	IONIC_QPF_REMOTE_PRIVILEGED	= BIT(10),
	IONIC_QPF_SQ_DRAINING		= BIT(11),
	IONIC_QPF_SQD_NOTIFY		= BIT(12),
	IONIC_QPF_SQ_CMB		= BIT(13),
	IONIC_QPF_RQ_CMB		= BIT(14),
	IONIC_QPF_PRIVILEGED		= BIT(15),
};

static inline int from_ionic_qp_flags(int flags)
{
	int access_flags = 0;

	if (flags & IONIC_QPF_REMOTE_WRITE)
		access_flags |= IB_ACCESS_REMOTE_WRITE;

	if (flags & IONIC_QPF_REMOTE_READ)
		access_flags |= IB_ACCESS_REMOTE_READ;

	if (flags & IONIC_QPF_REMOTE_ATOMIC)
		access_flags |= IB_ACCESS_REMOTE_ATOMIC;

	return access_flags;
}

static inline int to_ionic_qp_flags(int access, bool sqd_notify,
				    bool sq_is_cmb, bool rq_is_cmb,
				    bool sq_spec, bool rq_spec,
				    bool privileged, bool remote_privileged)
{
	int flags = 0;

	if (access & IB_ACCESS_REMOTE_WRITE)
		flags |= IONIC_QPF_REMOTE_WRITE;

	if (access & IB_ACCESS_REMOTE_READ)
		flags |= IONIC_QPF_REMOTE_READ;

	if (access & IB_ACCESS_REMOTE_ATOMIC)
		flags |= IONIC_QPF_REMOTE_ATOMIC;

	if (sqd_notify)
		flags |= IONIC_QPF_SQD_NOTIFY;

	if (sq_is_cmb)
		flags |= IONIC_QPF_SQ_CMB;

	if (rq_is_cmb)
		flags |= IONIC_QPF_RQ_CMB;

	if (sq_spec)
		flags |= IONIC_QPF_SQ_SPEC;

	if (rq_spec)
		flags |= IONIC_QPF_RQ_SPEC;

	if (privileged)
		flags |= IONIC_QPF_PRIVILEGED;

	if (remote_privileged)
		flags |= IONIC_QPF_REMOTE_PRIVILEGED;

	return flags;
}

/* cqe non-admin status indicated in status_length field when err bit is set */
enum ionic_status {
	IONIC_STS_OK,
	IONIC_STS_LOCAL_LEN_ERR,
	IONIC_STS_LOCAL_QP_OPER_ERR,
	IONIC_STS_LOCAL_PROT_ERR,
	IONIC_STS_WQE_FLUSHED_ERR,
	IONIC_STS_MEM_MGMT_OPER_ERR,
	IONIC_STS_BAD_RESP_ERR,
	IONIC_STS_LOCAL_ACC_ERR,
	IONIC_STS_REMOTE_INV_REQ_ERR,
	IONIC_STS_REMOTE_ACC_ERR,
	IONIC_STS_REMOTE_OPER_ERR,
	IONIC_STS_RETRY_EXCEEDED,
	IONIC_STS_RNR_RETRY_EXCEEDED,
	IONIC_STS_XRC_VIO_ERR,
};

static inline int ionic_to_ib_status(int sts)
{
	switch (sts) {
	case IONIC_STS_OK:
		return IB_WC_SUCCESS;
	case IONIC_STS_LOCAL_LEN_ERR:
		return IB_WC_LOC_LEN_ERR;
	case IONIC_STS_LOCAL_QP_OPER_ERR:
		return IB_WC_LOC_QP_OP_ERR;
	case IONIC_STS_LOCAL_PROT_ERR:
		return IB_WC_LOC_PROT_ERR;
	case IONIC_STS_WQE_FLUSHED_ERR:
		return IB_WC_WR_FLUSH_ERR;
	case IONIC_STS_MEM_MGMT_OPER_ERR:
		return IB_WC_MW_BIND_ERR;
	case IONIC_STS_BAD_RESP_ERR:
		return IB_WC_BAD_RESP_ERR;
	case IONIC_STS_LOCAL_ACC_ERR:
		return IB_WC_LOC_ACCESS_ERR;
	case IONIC_STS_REMOTE_INV_REQ_ERR:
		return IB_WC_REM_INV_REQ_ERR;
	case IONIC_STS_REMOTE_ACC_ERR:
		return IB_WC_REM_ACCESS_ERR;
	case IONIC_STS_REMOTE_OPER_ERR:
		return IB_WC_REM_OP_ERR;
	case IONIC_STS_RETRY_EXCEEDED:
		return IB_WC_RETRY_EXC_ERR;
	case IONIC_STS_RNR_RETRY_EXCEEDED:
		return IB_WC_RNR_RETRY_EXC_ERR;
	case IONIC_STS_XRC_VIO_ERR:
	default:
		return IB_WC_GENERAL_ERR;
	}
}

/* admin queue qp type */
enum ionic_qp_type {
	IONIC_QPT_RC,
	IONIC_QPT_UC,
	IONIC_QPT_RD,
	IONIC_QPT_UD,
	IONIC_QPT_SRQ,
	IONIC_QPT_XRC_INI,
	IONIC_QPT_XRC_TGT,
	IONIC_QPT_XRC_SRQ,
};

static inline int to_ionic_qp_type(enum ib_qp_type type)
{
	switch (type) {
	case IB_QPT_GSI:
	case IB_QPT_UD:
		return IONIC_QPT_UD;
	case IB_QPT_RC:
		return IONIC_QPT_RC;
	case IB_QPT_UC:
		return IONIC_QPT_UC;
	case IB_QPT_XRC_INI:
		return IONIC_QPT_XRC_INI;
	case IB_QPT_XRC_TGT:
		return IONIC_QPT_XRC_TGT;
	default:
		return -EINVAL;
	}
}

/* admin queue qp state */
enum ionic_qp_state {
	IONIC_QPS_RESET,
	IONIC_QPS_INIT,
	IONIC_QPS_RTR,
	IONIC_QPS_RTS,
	IONIC_QPS_SQD,
	IONIC_QPS_SQE,
	IONIC_QPS_ERR,
};

static inline int from_ionic_qp_state(enum ionic_qp_state state)
{
	switch (state) {
	case IONIC_QPS_RESET:
		return IB_QPS_RESET;
	case IONIC_QPS_INIT:
		return IB_QPS_INIT;
	case IONIC_QPS_RTR:
		return IB_QPS_RTR;
	case IONIC_QPS_RTS:
		return IB_QPS_RTS;
	case IONIC_QPS_SQD:
		return IB_QPS_SQD;
	case IONIC_QPS_SQE:
		return IB_QPS_SQE;
	case IONIC_QPS_ERR:
		return IB_QPS_ERR;
	default:
		return -EINVAL;
	}
}

static inline int to_ionic_qp_state(enum ib_qp_state state)
{
	switch (state) {
	case IB_QPS_RESET:
		return IONIC_QPS_RESET;
	case IB_QPS_INIT:
		return IONIC_QPS_INIT;
	case IB_QPS_RTR:
		return IONIC_QPS_RTR;
	case IB_QPS_RTS:
		return IONIC_QPS_RTS;
	case IB_QPS_SQD:
		return IONIC_QPS_SQD;
	case IB_QPS_SQE:
		return IONIC_QPS_SQE;
	case IB_QPS_ERR:
		return IONIC_QPS_ERR;
	default:
		return 0;
	}
}

static inline int to_ionic_qp_modify_state(enum ib_qp_state to_state,
					   enum ib_qp_state from_state)
{
	return to_ionic_qp_state(to_state) |
		(to_ionic_qp_state(from_state) << 4);
}

/* fw abi v1 */

/* data payload part of v1 wqe */
union ionic_v1_pld {
	struct ionic_sge	sgl[2];
	__be32			spec32[8];
	__be16			spec16[16];
	__u8			data[32];
};

/* completion queue v1 cqe */
struct ionic_v1_cqe {
	union {
		struct {
			__be16		cmd_idx;
			__u8		cmd_op;
			__u8		rsvd[17];
			__le16		old_sq_cindex;
			__le16		old_rq_cq_cindex;
		} admin;
		struct {
			__u64		wqe_id;
			__be32		src_qpn_op;
			__u8		src_mac[6];
			__be16		vlan_tag;
			__be32		imm_data_rkey;
		} recv;
		struct {
			__u8		rsvd[4];
			__be32		msg_msn;
			__u8		rsvd2[8];
			__u64		npg_wqe_id;
		} send;
	};
	__be32				status_length;
	__be32				qid_type_flags;
};

/* bits for cqe recv */
enum ionic_v1_cqe_src_qpn_bits {
	IONIC_V1_CQE_RECV_QPN_MASK	= 0xffffff,
	IONIC_V1_CQE_RECV_OP_SHIFT	= 24,

	/* MASK could be 0x3, but need 0x1f for makeshift values:
	 * OP_TYPE_RDMA_OPER_WITH_IMM, OP_TYPE_SEND_RCVD
	 */
	IONIC_V1_CQE_RECV_OP_MASK	= 0x1f,
	IONIC_V1_CQE_RECV_OP_SEND	= 0,
	IONIC_V1_CQE_RECV_OP_SEND_INV	= 1,
	IONIC_V1_CQE_RECV_OP_SEND_IMM	= 2,
	IONIC_V1_CQE_RECV_OP_RDMA_IMM	= 3,

	IONIC_V1_CQE_RECV_IS_IPV4	= BIT(7 + IONIC_V1_CQE_RECV_OP_SHIFT),
	IONIC_V1_CQE_RECV_IS_VLAN	= BIT(6 + IONIC_V1_CQE_RECV_OP_SHIFT),
};

/* bits for cqe qid_type_flags */
enum ionic_v1_cqe_qtf_bits {
	IONIC_V1_CQE_COLOR		= BIT(0),
	IONIC_V1_CQE_ERROR		= BIT(1),
	IONIC_V1_CQE_TYPE_SHIFT		= 5,
	IONIC_V1_CQE_TYPE_MASK		= 0x7,
	IONIC_V1_CQE_QID_SHIFT		= 8,

	IONIC_V1_CQE_TYPE_ADMIN		= 0,
	IONIC_V1_CQE_TYPE_RECV		= 1,
	IONIC_V1_CQE_TYPE_SEND_MSN	= 2,
	IONIC_V1_CQE_TYPE_SEND_NPG	= 3,
};

static inline bool ionic_v1_cqe_color(struct ionic_v1_cqe *cqe)
{
	return !!(cqe->qid_type_flags & cpu_to_be32(IONIC_V1_CQE_COLOR));
}

static inline bool ionic_v1_cqe_error(struct ionic_v1_cqe *cqe)
{
	return !!(cqe->qid_type_flags & cpu_to_be32(IONIC_V1_CQE_ERROR));
}

static inline bool ionic_v1_cqe_recv_is_ipv4(struct ionic_v1_cqe *cqe)
{
	return !!(cqe->recv.src_qpn_op &
		  cpu_to_be32(IONIC_V1_CQE_RECV_IS_IPV4));
}

static inline bool ionic_v1_cqe_recv_is_vlan(struct ionic_v1_cqe *cqe)
{
	return !!(cqe->recv.src_qpn_op &
		  cpu_to_be32(IONIC_V1_CQE_RECV_IS_VLAN));
}

static inline void ionic_v1_cqe_clean(struct ionic_v1_cqe *cqe)
{
	cqe->qid_type_flags |= cpu_to_be32(~0u << IONIC_V1_CQE_QID_SHIFT);
}

static inline u32 ionic_v1_cqe_qtf(struct ionic_v1_cqe *cqe)
{
	return be32_to_cpu(cqe->qid_type_flags);
}

static inline u8 ionic_v1_cqe_qtf_type(u32 qtf)
{
	return (qtf >> IONIC_V1_CQE_TYPE_SHIFT) & IONIC_V1_CQE_TYPE_MASK;
}

static inline u32 ionic_v1_cqe_qtf_qid(u32 qtf)
{
	return qtf >> IONIC_V1_CQE_QID_SHIFT;
}

/* v1 base wqe header */
struct ionic_v1_base_hdr {
	__u64				wqe_id;
	__u8				op;
	__u8				num_sge_key;
	__be16				flags;
	__be32				imm_data_key;
};

/* v1 receive wqe body */
struct ionic_v1_recv_bdy {
	__u8				rsvd[16];
	union ionic_v1_pld		pld;
};

/* v1 send/rdma wqe body (common, has sgl) */
struct ionic_v1_common_bdy {
	union {
		struct {
			__be32		ah_id;
			__be32		dest_qpn;
			__be32		dest_qkey;
		} send;
		struct {
			__be32		remote_va_high;
			__be32		remote_va_low;
			__be32		remote_rkey;
		} rdma;
	};
	__be32				length;
	union ionic_v1_pld		pld;
};

/* v1 atomic wqe body */
struct ionic_v1_atomic_bdy {
	__be32				remote_va_high;
	__be32				remote_va_low;
	__be32				remote_rkey;
	__be32				swap_add_high;
	__be32				swap_add_low;
	__be32				compare_high;
	__be32				compare_low;
	__u8				rsvd[4];
	struct ionic_sge		sge;
};

/* v1 reg mr wqe body */
struct ionic_v1_reg_mr_bdy {
	__be64				va;
	__be64				length;
	__be64				offset;
	__le64				dma_addr;
	__be32				map_count;
	__be16				flags;
	__u8				dir_size_log2;
	__u8				page_size_log2;
	__u8				rsvd[8];
};

/* v1 bind mw wqe body */
struct ionic_v1_bind_mw_bdy {
	__be64				va;
	__be64				length;
	__be32				lkey;
	__be16				flags;
	__u8				rsvd[26];
};

/* v1 send/recv wqe */
struct ionic_v1_wqe {
	struct ionic_v1_base_hdr	base;
	union {
		struct ionic_v1_recv_bdy	recv;
		struct ionic_v1_common_bdy	common;
		struct ionic_v1_atomic_bdy	atomic;
		struct ionic_v1_reg_mr_bdy	reg_mr;
		struct ionic_v1_bind_mw_bdy	bind_mw;
	};
};

/* queue pair v1 send opcodes */
enum ionic_v1_op {
	IONIC_V1_OP_SEND,
	IONIC_V1_OP_SEND_INV,
	IONIC_V1_OP_SEND_IMM,
	IONIC_V1_OP_RDMA_READ,
	IONIC_V1_OP_RDMA_WRITE,
	IONIC_V1_OP_RDMA_WRITE_IMM,
	IONIC_V1_OP_ATOMIC_CS,
	IONIC_V1_OP_ATOMIC_FA,
	IONIC_V1_OP_REG_MR,
	IONIC_V1_OP_LOCAL_INV,
	IONIC_V1_OP_BIND_MW,

	/* flags */
	IONIC_V1_FLAG_FENCE		= BIT(0),
	IONIC_V1_FLAG_SOL		= BIT(1),
	IONIC_V1_FLAG_INL		= BIT(2),
	IONIC_V1_FLAG_SIG		= BIT(3),

	/* flags last four bits for sgl spec format */
	IONIC_V1_FLAG_SPEC32		= (1u << 12),
	IONIC_V1_FLAG_SPEC16		= (2u << 12),
	IONIC_V1_SPEC_FIRST_SGE		= 2,
};

static inline size_t ionic_v1_send_wqe_min_size(int min_sge, int min_data,
						int spec)
{
	size_t sz_wqe, sz_sgl, sz_data;

	if (spec > IONIC_V1_SPEC_FIRST_SGE)
		min_sge += IONIC_V1_SPEC_FIRST_SGE;

	sz_wqe = sizeof(struct ionic_v1_wqe);
	sz_sgl = offsetof(struct ionic_v1_wqe, common.pld.sgl[min_sge]);
	sz_data = offsetof(struct ionic_v1_wqe, common.pld.data[min_data]);

	if (sz_sgl > sz_wqe)
		sz_wqe = sz_sgl;

	if (sz_data > sz_wqe)
		sz_wqe = sz_data;

	return sz_wqe;
}

static inline int ionic_v1_send_wqe_max_sge(u8 stride_log2, int spec)
{
	struct ionic_v1_wqe *wqe = (void *)0;
	struct ionic_sge *sge = (void *)(1ull << stride_log2);
	int num_sge = 0;

	if (spec > IONIC_V1_SPEC_FIRST_SGE)
		num_sge = IONIC_V1_SPEC_FIRST_SGE;

	num_sge = sge - &wqe->common.pld.sgl[num_sge];

	if (spec && num_sge > spec)
		num_sge = spec;

	return num_sge;
}

static inline int ionic_v1_send_wqe_max_data(u8 stride_log2)
{
	struct ionic_v1_wqe *wqe = (void *)0;
	__u8 *data = (void *)(1ull << stride_log2);

	return data - wqe->common.pld.data;
}

static inline size_t ionic_v1_recv_wqe_min_size(int min_sge, int spec)
{
	size_t sz_wqe, sz_sgl;

	if (spec > IONIC_V1_SPEC_FIRST_SGE)
		min_sge += IONIC_V1_SPEC_FIRST_SGE;

	sz_wqe = sizeof(struct ionic_v1_wqe);
	sz_sgl = offsetof(struct ionic_v1_wqe, recv.pld.sgl[min_sge]);

	if (sz_sgl > sz_wqe)
		sz_wqe = sz_sgl;

	return sz_wqe;
}

static inline int ionic_v1_recv_wqe_max_sge(u8 stride_log2, int spec)
{
	struct ionic_v1_wqe *wqe = (void *)0;
	struct ionic_sge *sge = (void *)(1ull << stride_log2);
	int num_sge = 0;

	if (spec > IONIC_V1_SPEC_FIRST_SGE)
		num_sge = IONIC_V1_SPEC_FIRST_SGE;

	num_sge = sge - &wqe->recv.pld.sgl[num_sge];

	if (spec && num_sge > spec)
		num_sge = spec;

	return num_sge;
}

static inline int ionic_v1_use_spec_sge(int min_sge, int spec)
{
	if (!spec || min_sge > spec)
		return 0;

	if (min_sge <= IONIC_V1_SPEC_FIRST_SGE)
		return IONIC_V1_SPEC_FIRST_SGE;

	return spec;
}

/* admin queue v1 wqe */
struct ionic_v1_admin_wqe {
	__u8				op;
	__u8				type_state;
	__le16				dbid_flags;
	__le32				id_ver;
	union {
		struct {
			__le64		dma_addr;
			__le32		length;
			__u8		rsvd[44];
		} stats;
		struct {
			__le64		dma_addr;
			__le32		length;
			__le32		pd_id;
			__u8		rsvd[40];
		} ah;
		struct {
			__le64		dma_addr;
			__u8		rsvd[48];
		} query_ah;
		struct {
			__le64		va;
			__le64		length;
			__le32		pd_id;
			__u8		rsvd[18];
			__u8		dir_size_log2;
			__u8		page_size_log2;
			__le32		tbl_index;
			__le32		map_count;
			__le64		dma_addr;
		} mr;
		struct {
			__le32		eq_id;
			__u8		depth_log2;
			__u8		stride_log2;
			__u8		dir_size_log2_rsvd;
			__u8		page_size_log2;
			__u8		rsvd[32];
			__le32		tbl_index;
			__le32		map_count;
			__le64		dma_addr;
		} cq;
		struct {
			__le32		pd_id;
			__be32		priv_flags;
			__le32		sq_cq_id;
			__u8		sq_depth_log2;
			__u8		sq_stride_log2;
			__u8		sq_dir_size_log2_rsvd;
			__u8		sq_page_size_log2;
			__le32		sq_tbl_index_xrcd_id;
			__le32		sq_map_count;
			__le64		sq_dma_addr;
			__le32		rq_cq_id;
			__u8		rq_depth_log2;
			__u8		rq_stride_log2;
			__u8		rq_dir_size_log2_rsvd;
			__u8		rq_page_size_log2;
			__le32		rq_tbl_index_srq_id;
			__le32		rq_map_count;
			__le64		rq_dma_addr;
		} qp;
		struct {
			__be32		attr_mask;
			__u8		dcqcn_profile;
			__u8		rsvd1;
			__be16		access_flags;
			__le32		rq_psn;
			__le32		sq_psn;
			__le32		qkey_dest_qpn;
			__le32		rate_limit_kbps;
			__u8		pmtu;
			__u8		retry;
			__u8		rnr_timer;
			__u8		retry_timeout;
			__u8		rsq_depth;
			__u8		rrq_depth;
			__le16		pkey_id;
			__le32		ah_id_len;
			__u8		en_pcp;
			__u8		ip_dscp;
			__u8		rsvd[2];
			__le32		rrq_index;
			__le32		rsq_index;
			__le64		dma_addr;
		} mod_qp;
		struct {
			__le64		hdr_dma_addr;
			__le32		ah_id;
			__u8		rsvd[28];
			__le64		sq_dma_addr;
			__le64		rq_dma_addr;
		} query_qp;
		struct {
			__u8		np_incp_802p_prio;
			__u8		np_cnp_dscp;
			__u8		np_rsvd[4];
			__be16		rp_dce_tcp_g;
			__be32		rp_dce_tcp_rtt;
			__be32		rp_rate_reduce_monitor_period;
			__be32		rp_rate_to_set_on_first_cnp;
			__be32		rp_min_rate;
			__be16		rp_initial_alpha_value;
			__u8		rp_gd;
			__u8		rp_min_dec_fac;
			__u8		rp_clamp_flags;
			__u8		rp_threshold;
			__be16		rp_time_reset;
			__be32		rp_qp_rate;
			__be32		rp_byte_reset;
			__be32		rp_ai_rate;
			__be32		rp_hai_rate;
			__be64		rp_token_bucket_size;
		} mod_dcqcn;
	};
};

enum ionic_v1_dcqcn_flags {
	IONIC_RPF_CLAMP_TGT_RATE	= BIT(0),
	IONIC_RPF_CLAMP_TGT_RATE_ATI	= BIT(1),
};

/* side data for modify qp if resize */
struct ionic_v1_admin_resize_qp {
	__u8				sq_depth_log2;
	__u8				sq_stride_log2;
	__u8				sq_dir_size_log2_rsvd;
	__u8				sq_page_size_log2;
	__u8				rq_depth_log2;
	__u8				rq_stride_log2;
	__u8				rq_dir_size_log2_rsvd;
	__u8				rq_page_size_log2;
	__le32				sq_table_index;
	__le32				sq_map_count;
	__le64				sq_dma_addr;
	__le32				rq_table_index;
	__le32				rq_map_count;
	__le64				rq_dma_addr;
};

/* side data for query qp */
struct ionic_v1_admin_query_qp_sq {
	__u8				rnr_timer;
	__u8				retry_timeout;
	__be16				access_perms_flags;
	__be16				access_perms_rsvd;
	__be16				pkey_id;
	__be32				qkey_dest_qpn;
	__be32				rate_limit_kbps;
	__be32				rq_psn;
};

struct ionic_v1_admin_query_qp_rq {
	__u8				state_pmtu;
	__u8				retry_rnrtry;
	__u8				rrq_depth;
	__u8				rsq_depth;
	__be32				sq_psn;
	__be32				ah_id_len;
};

/* admin queue v1 opcodes */
enum ionic_v1_admin_op {
	IONIC_V1_ADMIN_NOOP,
	IONIC_V1_ADMIN_CREATE_CQ,
	IONIC_V1_ADMIN_CREATE_QP,
	IONIC_V1_ADMIN_CREATE_MR,
	IONIC_V1_ADMIN_STATS_HDRS,
	IONIC_V1_ADMIN_STATS_VALS,
	IONIC_V1_ADMIN_DESTROY_MR,
	IONIC_v1_ADMIN_RSVD_7,		/* RESIZE_CQ */
	IONIC_V1_ADMIN_DESTROY_CQ,
	IONIC_V1_ADMIN_MODIFY_QP,
	IONIC_V1_ADMIN_QUERY_QP,
	IONIC_V1_ADMIN_DESTROY_QP,
	IONIC_V1_ADMIN_DEBUG,
	IONIC_V1_ADMIN_CREATE_AH,
	IONIC_V1_ADMIN_QUERY_AH,
	IONIC_V1_ADMIN_MODIFY_DCQCN,
	IONIC_V1_ADMIN_DESTROY_AH,

	/* TODO: move ops up as they are assigned opcode numbers in fw */
	IONIC_V1_ADMIN_IMPL_BY_DRIVER = 50,

	/* TODO: move ops up as they are assigned and implemented */
	IONIC_V1_ADMIN_NOT_IMPLEMENTED = 100,
	IONIC_V1_ADMIN_RESIZE_CQ,
};

/* admin queue v1 cqe status */
enum ionic_v1_admin_status {
	IONIC_V1_ASTS_OK,
	IONIC_V1_ASTS_BAD_CMD,
	IONIC_V1_ASTS_BAD_INDEX,
	IONIC_V1_ASTS_BAD_STATE,
	IONIC_V1_ASTS_BAD_TYPE,
	IONIC_V1_ASTS_BAD_ATTR,
};

/* event queue v1 eqe */
struct ionic_v1_eqe {
	__be32				evt;
};

/* bits for cqe queue_type_flags */
enum ionic_v1_eqe_evt_bits {
	IONIC_V1_EQE_COLOR		= BIT(0),
	IONIC_V1_EQE_TYPE_SHIFT		= 1,
	IONIC_V1_EQE_TYPE_MASK		= 0x7,
	IONIC_V1_EQE_CODE_SHIFT		= 4,
	IONIC_V1_EQE_CODE_MASK		= 0xf,
	IONIC_V1_EQE_QID_SHIFT		= 8,

	/* cq events */
	IONIC_V1_EQE_TYPE_CQ		= 0,
	/* cq normal events */
	IONIC_V1_EQE_CQ_NOTIFY		= 0,
	/* cq error events */
	IONIC_V1_EQE_CQ_ERR		= 8,

	/* qp and srq events */
	IONIC_V1_EQE_TYPE_QP		= 1,
	/* qp normal events */
	IONIC_V1_EQE_SRQ_LEVEL		= 0,
	IONIC_V1_EQE_SQ_DRAIN		= 1,
	IONIC_V1_EQE_QP_COMM_EST	= 2,
	IONIC_V1_EQE_QP_LAST_WQE	= 3,
	/* qp error events */
	IONIC_V1_EQE_QP_ERR		= 8,
	IONIC_V1_EQE_QP_ERR_REQUEST	= 9,
	IONIC_V1_EQE_QP_ERR_ACCESS	= 10,
};

static inline bool ionic_v1_eqe_color(struct ionic_v1_eqe *eqe)
{
	return !!(eqe->evt & cpu_to_be32(IONIC_V1_EQE_COLOR));
}

static inline u32 ionic_v1_eqe_evt(struct ionic_v1_eqe *eqe)
{
	return be32_to_cpu(eqe->evt);
}

static inline u8 ionic_v1_eqe_evt_type(u32 evt)
{
	return (evt >> IONIC_V1_EQE_TYPE_SHIFT) & IONIC_V1_EQE_TYPE_MASK;
}

static inline u8 ionic_v1_eqe_evt_code(u32 evt)
{
	return (evt >> IONIC_V1_EQE_CODE_SHIFT) & IONIC_V1_EQE_CODE_MASK;
}

static inline u32 ionic_v1_eqe_evt_qid(u32 evt)
{
	return evt >> IONIC_V1_EQE_QID_SHIFT;
}

enum ionic_v1_stat_bits {
	IONIC_V1_STAT_TYPE_SHIFT	= 28,
	IONIC_V1_STAT_TYPE_NONE		= 0,
	IONIC_V1_STAT_TYPE_8		= 1,
	IONIC_V1_STAT_TYPE_LE16		= 2,
	IONIC_V1_STAT_TYPE_LE32		= 3,
	IONIC_V1_STAT_TYPE_LE64		= 4,
	IONIC_V1_STAT_TYPE_BE16		= 5,
	IONIC_V1_STAT_TYPE_BE32		= 6,
	IONIC_V1_STAT_TYPE_BE64		= 7,
	IONIC_V1_STAT_OFF_MASK		= BIT(IONIC_V1_STAT_TYPE_SHIFT) - 1,
};

struct ionic_v1_stat {
	union {
		__be32		be_type_off;
		u32		type_off;
	};
	char			name[28];
};

static inline int ionic_v1_stat_type(struct ionic_v1_stat *hdr)
{
	return hdr->type_off >> IONIC_V1_STAT_TYPE_SHIFT;
}

static inline unsigned int ionic_v1_stat_off(struct ionic_v1_stat *hdr)
{
	return hdr->type_off & IONIC_V1_STAT_OFF_MASK;
}

#endif /* IONIC_FW_H */
