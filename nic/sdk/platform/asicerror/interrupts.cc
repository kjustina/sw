
/**
 * Copyright (c) 2019 Pensando Systems, Inc.
 *
 * @file    interrupts.cc
 *
 * @brief   This file populates interrupt structures
 */

#include "interrupts.hpp"

// No desc for pr.pr int_reg slave_prd
// No desc for pr.pr int_reg slave_psp
// No desc for pt.pt int_reg slave_ptd
// No desc for pt.pt int_reg slave_psp
// could not find any cap_pict_csr_intreg_status under tsi.pict
// could not find any cap_pict_csr_intreg_status under tse.pict
// could not find any cap_pbcport0_csr_intreg_status under pb.pbc.port_0
// could not find any cap_pbcport1_csr_intreg_status under pb.pbc.port_1
// could not find any cap_pbcport2_csr_intreg_status under pb.pbc.port_2
// could not find any cap_pbcport3_csr_intreg_status under pb.pbc.port_3
// could not find any cap_pbcport4_csr_intreg_status under pb.pbc.port_4
// could not find any cap_pbcport5_csr_intreg_status under pb.pbc.port_5
// could not find any cap_pbcport6_csr_intreg_status under pb.pbc.port_6
// could not find any cap_pbcport7_csr_intreg_status under pb.pbc.port_7
// could not find any cap_pbcport8_csr_intreg_status under pb.pbc.port_8
// could not find any cap_pbcport9_csr_intreg_status under pb.pbc.port_9
// could not find any cap_pbcport10_csr_intreg_status under pb.pbc.port_10
// could not find any cap_pbcport11_csr_intreg_status under pb.pbc.port_11
// could not find any cap_pbchbmeth_csr_intreg_status under pb.pbc.hbm.hbm_port_0
// could not find any cap_pbchbmeth_csr_intreg_status under pb.pbc.hbm.hbm_port_1
// could not find any cap_pbchbmeth_csr_intreg_status under pb.pbc.hbm.hbm_port_2
// could not find any cap_pbchbmeth_csr_intreg_status under pb.pbc.hbm.hbm_port_3
// could not find any cap_pbchbmeth_csr_intreg_status under pb.pbc.hbm.hbm_port_4
// could not find any cap_pbchbmeth_csr_intreg_status under pb.pbc.hbm.hbm_port_5
// could not find any cap_pbchbmeth_csr_intreg_status under pb.pbc.hbm.hbm_port_6
// could not find any cap_pbchbmeth_csr_intreg_status under pb.pbc.hbm.hbm_port_7
// could not find any cap_pbchbmeth_csr_intreg_status under pb.pbc.hbm.hbm_port_8
// could not find any cap_pbchbmtx_csr_intreg_status under pb.pbc.hbm.hbm_port_9
// could not find any cap_hese_csr_intreg_status under md.hese
// could not find any cap_dprhdrfld_csr_intreg_status under dpr.dpr[0].hdrfld
// could not find any cap_dprcfg_csr_intreg_status under dpr.dpr[0].cfg
// could not find any cap_dprstats_csr_intreg_status under dpr.dpr[0].stats
// could not find any cap_dprmem_csr_intreg_status under dpr.dpr[0].mem
// could not find any cap_dprhdrfld_csr_intreg_status under dpr.dpr[1].hdrfld
// could not find any cap_dprcfg_csr_intreg_status under dpr.dpr[1].cfg
// could not find any cap_dprstats_csr_intreg_status under dpr.dpr[1].stats
// could not find any cap_dprmem_csr_intreg_status under dpr.dpr[1].mem
// could not find any cap_dpphdr_csr_intreg_status under dpp.dpp[0].hdr
// could not find any cap_dpphdrfld_csr_intreg_status under dpp.dpp[0].hdrfld
// could not find any cap_dppcsum_csr_intreg_status under dpp.dpp[0].csum
// could not find any cap_dppstats_csr_intreg_status under dpp.dpp[0].stats
// could not find any cap_dppmem_csr_intreg_status under dpp.dpp[0].mem
// could not find any cap_dpphdr_csr_intreg_status under dpp.dpp[1].hdr
// could not find any cap_dpphdrfld_csr_intreg_status under dpp.dpp[1].hdrfld
// could not find any cap_dppcsum_csr_intreg_status under dpp.dpp[1].csum
// could not find any cap_dppstats_csr_intreg_status under dpp.dpp[1].stats
// could not find any cap_dppmem_csr_intreg_status under dpp.dpp[1].mem
// No desc for sema.sema int_groups.intreg sema_err
// could not find any cap_mpse_csr_intreg_status under mp.mpse
// could not find any cap_apb_csr_intreg_status under ms.apb
// could not find any emmc_SDHOST_Memory_Map_intreg_status under ms.emmc
// could not find any cap_ap_csr_intreg_status under ms.ap
// could not find any cap_apb_csr_intreg_status under ms.ap.apb
// could not find any cap_msr_csr_intreg_status under ms.ms.msr
// could not find any cap_msh_csr_intreg_status under ms.ms.msh
// could not find any cap_mss_csr_intreg_status under ms.mss
// No desc for ms.em int_groups.intreg axi
// could not find any cap_emm_csr_intreg_status under ms.em.emm
intr_reg_t sgi_mpu_2_int_err = {  .name="sgi.mpu[2].int_err", .addr=0x3708630, .reg_type=0, .id=63, .field_count=27, .fields=
	{
		{  .name="results_mismatch", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="mask this interrupt, not fully implemented" },
		{  .name="sdp_mem_uncorrectable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="sdp_mem_correctable", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="illegal_op_0", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_1", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_2", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_3", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="max_inst_0", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_1", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_2", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_3", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="phvwr_0", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_1", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_2", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_3", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="write_err_0", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_1", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_2", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_3", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="cache_axi_0", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_1", .next_ptr=nullptr, .id=22, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_2", .next_ptr=nullptr, .id=23, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_3", .next_ptr=nullptr, .id=24, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_parity_0", .next_ptr=nullptr, .id=25, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_1", .next_ptr=nullptr, .id=26, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_2", .next_ptr=nullptr, .id=27, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_3", .next_ptr=nullptr, .id=28, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },

	} };
intr_reg_t sgi_mpu_2_int_info = {  .name="sgi.mpu[2].int_info", .addr=0x3708640, .reg_type=0, .id=64, .field_count=8, .fields=
	{
		{  .name="trace_full_0", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_1", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_2", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="mpu_stop_0", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_1", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_2", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_3", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },

	} };
intr_reg_t sgi_mpu_2_int_groups_intreg = {  .name="sgi.mpu[2].int_groups.intreg", .addr=0x3708620, .reg_type=1, .id=65, .field_count=2, .fields=
	{
		{  .name="int_err", .next_ptr=&sgi_mpu_2_int_err, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_info", .next_ptr=&sgi_mpu_2_int_info, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t pcr_te_0_int_err = {  .name="pcr.te[0].int_err", .addr=0x6242440, .reg_type=0, .id=193, .field_count=20, .fields=
	{
		{  .name="miss_sop", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="previous stage error" },
		{  .name="miss_eop", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="previous stage error" },
		{  .name="phv_max_size", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="invalid" },
		{  .name="spurious_axi_rsp", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="spurious_tcam_rsp", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_FATAL, .desc="bad tcam response" },
		{  .name="te2mpu_timeout", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="impossible, should be disabled" },
		{  .name="axi_rdrsp_err", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="axi_bad_read", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="tcam_req_idx_fifo", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="tcam_rsp_idx_fifo", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="mpu_req_idx_fifo", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="axi_req_idx_fifo", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="proc_tbl_vld_wo_proc", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend_wo_wb", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend1_wo_pend0", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="both_pend_down", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend_wo_proc_down", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="both_pend_went_up", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="loaded_but_no_proc", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="loaded_but_no_proc_tbl_vld", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },

	} };
intr_reg_t pcr_te_0_int_info = {  .name="pcr.te[0].int_info", .addr=0x6242450, .reg_type=0, .id=194, .field_count=17, .fields=
	{
		{  .name="profile_cam_hit0", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit1", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit2", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit4", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit5", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit6", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit7", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit8", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit9", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit10", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit11", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit12", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit13", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit14", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit15", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_miss", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t pcr_te_0_int_groups_intreg = {  .name="pcr.te[0].int_groups.intreg", .addr=0x6242430, .reg_type=1, .id=195, .field_count=2, .fields=
	{
		{  .name="int_err", .next_ptr=&pcr_te_0_int_err, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_info", .next_ptr=&pcr_te_0_int_info, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t sgi_mpu_5_int_err = {  .name="sgi.mpu[5].int_err", .addr=0x3738630, .reg_type=0, .id=72, .field_count=27, .fields=
	{
		{  .name="results_mismatch", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="mask this interrupt, not fully implemented" },
		{  .name="sdp_mem_uncorrectable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="sdp_mem_correctable", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="illegal_op_0", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_1", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_2", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_3", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="max_inst_0", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_1", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_2", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_3", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="phvwr_0", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_1", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_2", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_3", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="write_err_0", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_1", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_2", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_3", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="cache_axi_0", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_1", .next_ptr=nullptr, .id=22, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_2", .next_ptr=nullptr, .id=23, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_3", .next_ptr=nullptr, .id=24, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_parity_0", .next_ptr=nullptr, .id=25, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_1", .next_ptr=nullptr, .id=26, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_2", .next_ptr=nullptr, .id=27, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_3", .next_ptr=nullptr, .id=28, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },

	} };
intr_reg_t sgi_mpu_5_int_info = {  .name="sgi.mpu[5].int_info", .addr=0x3738640, .reg_type=0, .id=73, .field_count=8, .fields=
	{
		{  .name="trace_full_0", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_1", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_2", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="mpu_stop_0", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_1", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_2", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_3", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },

	} };
intr_reg_t sgi_mpu_5_int_groups_intreg = {  .name="sgi.mpu[5].int_groups.intreg", .addr=0x3738620, .reg_type=1, .id=74, .field_count=2, .fields=
	{
		{  .name="int_err", .next_ptr=&sgi_mpu_5_int_err, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_info", .next_ptr=&sgi_mpu_5_int_info, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t pct_te_1_int_err = {  .name="pct.te[1].int_err", .addr=0x6362440, .reg_type=0, .id=248, .field_count=20, .fields=
	{
		{  .name="miss_sop", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="previous stage error" },
		{  .name="miss_eop", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="previous stage error" },
		{  .name="phv_max_size", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="invalid" },
		{  .name="spurious_axi_rsp", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="spurious_tcam_rsp", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_FATAL, .desc="bad tcam response" },
		{  .name="te2mpu_timeout", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="impossible, should be disabled" },
		{  .name="axi_rdrsp_err", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="axi_bad_read", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="tcam_req_idx_fifo", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="tcam_rsp_idx_fifo", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="mpu_req_idx_fifo", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="axi_req_idx_fifo", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="proc_tbl_vld_wo_proc", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend_wo_wb", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend1_wo_pend0", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="both_pend_down", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend_wo_proc_down", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="both_pend_went_up", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="loaded_but_no_proc", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="loaded_but_no_proc_tbl_vld", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },

	} };
intr_reg_t pct_te_1_int_info = {  .name="pct.te[1].int_info", .addr=0x6362450, .reg_type=0, .id=249, .field_count=17, .fields=
	{
		{  .name="profile_cam_hit0", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit1", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit2", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit4", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit5", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit6", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit7", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit8", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit9", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit10", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit11", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit12", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit13", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit14", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit15", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_miss", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t pct_te_1_int_groups_intreg = {  .name="pct.te[1].int_groups.intreg", .addr=0x6362430, .reg_type=1, .id=250, .field_count=2, .fields=
	{
		{  .name="int_err", .next_ptr=&pct_te_1_int_err, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_info", .next_ptr=&pct_te_1_int_info, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t mc_mc_7_int_mc = {  .name="mc.mc[7].int_mc", .addr=0x6a880020, .reg_type=0, .id=422, .field_count=1, .fields=
	{
		{  .name="mch_int", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_ERR, .desc="" },

	} };
intr_reg_t mc_mc_7_int_groups_intreg = {  .name="mc.mc[7].int_groups.intreg", .addr=0x6a880010, .reg_type=1, .id=423, .field_count=1, .fields=
	{
		{  .name="int_mc", .next_ptr=&mc_mc_7_int_mc, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t pcr_te_5_int_err = {  .name="pcr.te[5].int_err", .addr=0x62e2440, .reg_type=0, .id=208, .field_count=20, .fields=
	{
		{  .name="miss_sop", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="previous stage error" },
		{  .name="miss_eop", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="previous stage error" },
		{  .name="phv_max_size", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="invalid" },
		{  .name="spurious_axi_rsp", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="spurious_tcam_rsp", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_FATAL, .desc="bad tcam response" },
		{  .name="te2mpu_timeout", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="impossible, should be disabled" },
		{  .name="axi_rdrsp_err", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="axi_bad_read", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="tcam_req_idx_fifo", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="tcam_rsp_idx_fifo", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="mpu_req_idx_fifo", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="axi_req_idx_fifo", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="proc_tbl_vld_wo_proc", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend_wo_wb", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend1_wo_pend0", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="both_pend_down", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend_wo_proc_down", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="both_pend_went_up", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="loaded_but_no_proc", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="loaded_but_no_proc_tbl_vld", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },

	} };
intr_reg_t pcr_te_5_int_info = {  .name="pcr.te[5].int_info", .addr=0x62e2450, .reg_type=0, .id=209, .field_count=17, .fields=
	{
		{  .name="profile_cam_hit0", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit1", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit2", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit4", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit5", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit6", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit7", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit8", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit9", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit10", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit11", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit12", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit13", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit14", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit15", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_miss", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t pcr_te_5_int_groups_intreg = {  .name="pcr.te[5].int_groups.intreg", .addr=0x62e2430, .reg_type=1, .id=210, .field_count=2, .fields=
	{
		{  .name="int_err", .next_ptr=&pcr_te_5_int_err, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_info", .next_ptr=&pcr_te_5_int_info, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t pp_pp_port_c_5_int_c_mac = {  .name="pp.pp.port_c[5].int_c_mac", .addr=0x701b1b0, .reg_type=0, .id=170, .field_count=19, .fields=
	{
		{  .name="link_dn2up", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="link_up2dn", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="sec_bus_rst", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="rst_up2dn", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="rst_dn2up", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="portgate_open2close", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="ltssm_st_changed", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="sec_busnum_changed", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="rc_pme", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="rc_aerr", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="rc_serr", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="rc_hpe", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="rc_eq_req", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="rc_dpc", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="pm_turnoff", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="txbfr_overflow", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_FATAL, .desc="Fatal error, try to reproduce in lab and debug the configuration settings using PCIE Analyzer" },
		{  .name="rxtlp_err", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="" },
		{  .name="tl_flr_req", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="rc_legacy_intpin_changed", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t pp_pp_port_c_5_int_c_ecc = {  .name="pp.pp.port_c[5].int_c_ecc", .addr=0x701b1c0, .reg_type=0, .id=171, .field_count=8, .fields=
	{
		{  .name="rxbuf_0_uncorrectable", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="rxbuf_1_uncorrectable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="rxbuf_2_uncorrectable", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="rxbuf_3_uncorrectable", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="rxbuf_0_correctable", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="rxbuf_1_correctable", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="rxbuf_2_correctable", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="rxbuf_3_correctable", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },

	} };
intr_reg_t pp_pp_port_c_5_int_groups_intreg = {  .name="pp.pp.port_c[5].int_groups.intreg", .addr=0x701b1a0, .reg_type=1, .id=172, .field_count=2, .fields=
	{
		{  .name="int_c_mac", .next_ptr=&pp_pp_port_c_5_int_c_mac, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_c_ecc", .next_ptr=&pp_pp_port_c_5_int_c_ecc, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t mc_mc_3_int_mc = {  .name="mc.mc[3].int_mc", .addr=0x6a480020, .reg_type=0, .id=406, .field_count=1, .fields=
	{
		{  .name="mch_int", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_ERR, .desc="" },

	} };
intr_reg_t mc_mc_3_int_groups_intreg = {  .name="mc.mc[3].int_groups.intreg", .addr=0x6a480010, .reg_type=1, .id=407, .field_count=1, .fields=
	{
		{  .name="int_mc", .next_ptr=&mc_mc_3_int_mc, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t mc_mc_0_mch_int_mc = {  .name="mc.mc[0].mch.int_mc", .addr=0x6a100060, .reg_type=0, .id=396, .field_count=2, .fields=
	{
		{  .name="ecc_1bit_thresh_ps1", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_ERR, .desc="" },
		{  .name="ecc_1bit_thresh_ps0", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="" },

	} };
intr_reg_t mc_mc_0_mch_int_groups_intreg = {  .name="mc.mc[0].mch.int_groups.intreg", .addr=0x6a100050, .reg_type=1, .id=397, .field_count=1, .fields=
	{
		{  .name="int_mc", .next_ptr=&mc_mc_0_mch_int_mc, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t dpr_dpr_1_int_reg1 = {  .name="dpr.dpr[1].int_reg1", .addr=0x33000b0, .reg_type=0, .id=385, .field_count=29, .fields=
	{
		{  .name="err_phv_sop_no_eop", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="err_phv_eop_no_sop", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="err_ohi_sop_no_eop", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="err_ohi_eop_no_sop", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="err_pktin_sop_no_eop", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="err_pktin_eop_no_sop", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="err_csum_offset_gt_pkt_size_4", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="P4 program/compiler error. Checksum covers more than packet size" },
		{  .name="err_csum_offset_gt_pkt_size_3", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="P4 program/compiler error. Checksum covers more than packet size" },
		{  .name="err_csum_offset_gt_pkt_size_2", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_ERR, .desc="P4 program/compiler error. Checksum covers more than packet size" },
		{  .name="err_csum_offset_gt_pkt_size_1", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="P4 program/compiler error. Checksum covers more than packet size" },
		{  .name="err_csum_offset_gt_pkt_size_0", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_ERR, .desc="P4 program/compiler error. Checksum covers more than packet size" },
		{  .name="err_csum_phdr_offset_gt_pkt_size_4", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="P4 program/compiler error. Checksum pseudoheaders covers more than packet size" },
		{  .name="err_csum_phdr_offset_gt_pkt_size_3", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="P4 program/compiler error. Checksum pseudoheaders covers more than packet size" },
		{  .name="err_csum_phdr_offset_gt_pkt_size_2", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="P4 program/compiler error. Checksum pseudoheaders covers more than packet size" },
		{  .name="err_csum_phdr_offset_gt_pkt_size_1", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_ERR, .desc="P4 program/compiler error. Checksum pseudoheaders covers more than packet size" },
		{  .name="err_csum_phdr_offset_gt_pkt_size_0", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="P4 program/compiler error. Checksum pseudoheaders covers more than packet size" },
		{  .name="err_csum_loc_gt_pkt_size_4", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="P4 program/compiler error. Checksum location greater then packet size" },
		{  .name="err_csum_loc_gt_pkt_size_3", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_ERR, .desc="P4 program/compiler error. Checksum location greater then packet size" },
		{  .name="err_csum_loc_gt_pkt_size_2", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_ERR, .desc="P4 program/compiler error. Checksum location greater then packet size" },
		{  .name="err_csum_loc_gt_pkt_size_1", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_ERR, .desc="P4 program/compiler error. Checksum location greater then packet size" },
		{  .name="err_csum_loc_gt_pkt_size_0", .next_ptr=nullptr, .id=22, .severity=INTR_SEV_TYPE_ERR, .desc="P4 program/compiler error. Checksum location greater then packet size" },
		{  .name="err_crc_offset_gt_pkt_size", .next_ptr=nullptr, .id=23, .severity=INTR_SEV_TYPE_ERR, .desc="P4 program/compiler error. ICRC covers more than packet size" },
		{  .name="err_crc_loc_gt_pkt_size", .next_ptr=nullptr, .id=24, .severity=INTR_SEV_TYPE_ERR, .desc="P4 program/compiler error. ICRC location greater then packet size" },
		{  .name="err_crc_mask_offset_gt_pkt_size", .next_ptr=nullptr, .id=25, .severity=INTR_SEV_TYPE_INFO, .desc="Invalid need to be masked" },
		{  .name="err_pkt_eop_early", .next_ptr=nullptr, .id=26, .severity=INTR_SEV_TYPE_INFO, .desc="spare" },
		{  .name="err_ptr_ff_overflow", .next_ptr=nullptr, .id=27, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="err_csum_ff_overflow", .next_ptr=nullptr, .id=28, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="err_pktout_ff_overflow", .next_ptr=nullptr, .id=29, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="err_ptr_from_cfg_overflow", .next_ptr=nullptr, .id=30, .severity=INTR_SEV_TYPE_INFO, .desc="Hardware Error" },

	} };
intr_reg_t dpr_dpr_1_int_reg2 = {  .name="dpr.dpr[1].int_reg2", .addr=0x33000c0, .reg_type=0, .id=386, .field_count=8, .fields=
	{
		{  .name="fieldC", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="spare" },
		{  .name="fieldD", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="spare" },
		{  .name="err_csum_start_gt_end_4", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="P4 program/compiler error. Checksum start is greater then end" },
		{  .name="err_csum_start_gt_end_3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="P4 program/compiler error. Checksum start is greater then end" },
		{  .name="err_csum_start_gt_end_2", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="P4 program/compiler error. Checksum start is greater then end" },
		{  .name="err_csum_start_gt_end_1", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="P4 program/compiler error. Checksum start is greater then end" },
		{  .name="err_csum_start_gt_end_0", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="P4 program/compiler error. Checksum start is greater then end" },
		{  .name="err_crc_start_gt_end", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="P4 program/compiler error. ICRC start is greater then end" },

	} };
intr_reg_t dpr_dpr_1_int_srams_ecc = {  .name="dpr.dpr[1].int_srams_ecc", .addr=0x3300080, .reg_type=0, .id=387, .field_count=12, .fields=
	{
		{  .name="dpr_pktin_fifo_uncorrectable", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="dpr_pktin_fifo_correctable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="dpr_csum_fifo_uncorrectable", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="dpr_csum_fifo_correctable", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="dpr_phv_fifo_uncorrectable", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="dpr_phv_fifo_correctable", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="dpr_ohi_fifo_uncorrectable", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="dpr_ohi_fifo_correctable", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="dpr_ptr_fifo_uncorrectable", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="dpr_ptr_fifo_correctable", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="dpr_pktout_fifo_uncorrectable", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="dpr_pktout_fifo_correctable", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },

	} };
intr_reg_t dpr_dpr_1_int_fifo = {  .name="dpr.dpr[1].int_fifo", .addr=0x33000d0, .reg_type=0, .id=388, .field_count=6, .fields=
	{
		{  .name="phv_ff_ovflow", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="ohi_ff_ovflow", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="pktin_ff_ovflow", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="pktout_ff_undflow", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="csum_ff_ovflow", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="ptr_ff_ovflow", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },

	} };
intr_reg_t dpr_dpr_1_int_flop_fifo_0 = {  .name="dpr.dpr[1].int_flop_fifo_0", .addr=0x33000e0, .reg_type=0, .id=389, .field_count=20, .fields=
	{
		{  .name="data_mux_force_bypass_crc_flop_ff_ovflow", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="dpr_crc_info_flop_ff_ovflow", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="dpr_crc_update_info_flop_ff_ovflow", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="dpr_csum_info_flop_ff_ovflow", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="data_mux_force_bypass_csum_flop_ff_ovflow", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="dpr_csum_update_info_flop_ff_ovflow", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="ptr_early_pkt_eop_info_flop_ff_ovflow", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="data_mux_eop_err_flop_ff_ovflow", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="pktin_eop_err_flop_ff_ovflow", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="csum_err_flop_ff_ovflow", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="crc_err_flop_ff_ovflow", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="data_mux_drop_flop_ff_ovflow", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="phv_pkt_data_flop_ff_ovflow", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="pktout_len_cell_flop_ff_ovflow", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="padding_size_flop_ff_ovflow", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="pktin_err_flop_ff_ovflow", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="phv_no_data_flop_ff_ovflow", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="ptr_lookahaed_flop_ff_ovflow", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="eop_vld_flop_ff_ovflow", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="csum_cal_vld_flop_ff_ovflow", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },

	} };
intr_reg_t dpr_dpr_1_int_flop_fifo_1 = {  .name="dpr.dpr[1].int_flop_fifo_1", .addr=0x33000f0, .reg_type=0, .id=390, .field_count=20, .fields=
	{
		{  .name="data_mux_force_bypass_crc_flop_ff_undflow", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="dpr_crc_info_flop_ff_undflow", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="dpr_crc_update_info_flop_ff_undflow", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="dpr_csum_info_flop_ff_undflow", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="data_mux_force_bypass_csum_flop_ff_undflow", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="dpr_csum_update_info_flop_ff_undflow", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="ptr_early_pkt_eop_info_flop_ff_undflow", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="data_mux_eop_err_flop_ff_undflow", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="pktin_eop_err_flop_ff_undflow", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="csum_err_flop_ff_undflow", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="crc_err_flop_ff_undflow", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="data_mux_drop_flop_ff_undflow", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="phv_pkt_data_flop_ff_undflow", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="pktout_len_cell_flop_ff_undflow", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="padding_size_flop_ff_undflow", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="pktin_err_flop_ff_undflow", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="phv_no_data_flop_ff_undflow", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="ptr_lookahaed_flop_ff_undflow", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="eop_vld_flop_ff_undflow", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="csum_cal_vld_flop_ff_undflow", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },

	} };
intr_reg_t dpr_dpr_1_int_spare = {  .name="dpr.dpr[1].int_spare", .addr=0x3300110, .reg_type=0, .id=391, .field_count=32, .fields=
	{
		{  .name="spare_0", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="spare_0 .. spare_7: Hardware Error; spare_8: err_phv_above_max: P4 program/compiler error. Packet need to get information form a PHV that is beyond the maximum supported; spare_9: capture engaged used for debug;" },
		{  .name="spare_1", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="spare_0 .. spare_7: Hardware Error; spare_8: err_phv_above_max: P4 program/compiler error. Packet need to get information form a PHV that is beyond the maximum supported; spare_9: capture engaged used for debug;" },
		{  .name="spare_2", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_FATAL, .desc="spare_0 .. spare_7: Hardware Error; spare_8: err_phv_above_max: P4 program/compiler error. Packet need to get information form a PHV that is beyond the maximum supported; spare_9: capture engaged used for debug;" },
		{  .name="spare_3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_FATAL, .desc="spare_0 .. spare_7: Hardware Error; spare_8: err_phv_above_max: P4 program/compiler error. Packet need to get information form a PHV that is beyond the maximum supported; spare_9: capture engaged used for debug;" },
		{  .name="spare_4", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_FATAL, .desc="spare_0 .. spare_7: Hardware Error; spare_8: err_phv_above_max: P4 program/compiler error. Packet need to get information form a PHV that is beyond the maximum supported; spare_9: capture engaged used for debug;" },
		{  .name="spare_5", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_FATAL, .desc="spare_0 .. spare_7: Hardware Error; spare_8: err_phv_above_max: P4 program/compiler error. Packet need to get information form a PHV that is beyond the maximum supported; spare_9: capture engaged used for debug;" },
		{  .name="spare_6", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_FATAL, .desc="spare_0 .. spare_7: Hardware Error; spare_8: err_phv_above_max: P4 program/compiler error. Packet need to get information form a PHV that is beyond the maximum supported; spare_9: capture engaged used for debug;" },
		{  .name="spare_7", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_FATAL, .desc="spare_0 .. spare_7: Hardware Error; spare_8: err_phv_above_max: P4 program/compiler error. Packet need to get information form a PHV that is beyond the maximum supported; spare_9: capture engaged used for debug;" },
		{  .name="spare_8", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_FATAL, .desc="spare_0 .. spare_7: Hardware Error; spare_8: err_phv_above_max: P4 program/compiler error. Packet need to get information form a PHV that is beyond the maximum supported; spare_9: capture engaged used for debug;" },
		{  .name="spare_9", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_FATAL, .desc="spare_0 .. spare_7: Hardware Error; spare_8: err_phv_above_max: P4 program/compiler error. Packet need to get information form a PHV that is beyond the maximum supported; spare_9: capture engaged used for debug;" },
		{  .name="spare_10", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_FATAL, .desc="spare_0 .. spare_7: Hardware Error; spare_8: err_phv_above_max: P4 program/compiler error. Packet need to get information form a PHV that is beyond the maximum supported; spare_9: capture engaged used for debug;" },
		{  .name="spare_11", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_FATAL, .desc="spare_0 .. spare_7: Hardware Error; spare_8: err_phv_above_max: P4 program/compiler error. Packet need to get information form a PHV that is beyond the maximum supported; spare_9: capture engaged used for debug;" },
		{  .name="spare_12", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_FATAL, .desc="spare_0 .. spare_7: Hardware Error; spare_8: err_phv_above_max: P4 program/compiler error. Packet need to get information form a PHV that is beyond the maximum supported; spare_9: capture engaged used for debug;" },
		{  .name="spare_13", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_FATAL, .desc="spare_0 .. spare_7: Hardware Error; spare_8: err_phv_above_max: P4 program/compiler error. Packet need to get information form a PHV that is beyond the maximum supported; spare_9: capture engaged used for debug;" },
		{  .name="spare_14", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_FATAL, .desc="spare_0 .. spare_7: Hardware Error; spare_8: err_phv_above_max: P4 program/compiler error. Packet need to get information form a PHV that is beyond the maximum supported; spare_9: capture engaged used for debug;" },
		{  .name="spare_15", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_FATAL, .desc="spare_0 .. spare_7: Hardware Error; spare_8: err_phv_above_max: P4 program/compiler error. Packet need to get information form a PHV that is beyond the maximum supported; spare_9: capture engaged used for debug;" },
		{  .name="spare_16", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_FATAL, .desc="spare_0 .. spare_7: Hardware Error; spare_8: err_phv_above_max: P4 program/compiler error. Packet need to get information form a PHV that is beyond the maximum supported; spare_9: capture engaged used for debug;" },
		{  .name="spare_17", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_FATAL, .desc="spare_0 .. spare_7: Hardware Error; spare_8: err_phv_above_max: P4 program/compiler error. Packet need to get information form a PHV that is beyond the maximum supported; spare_9: capture engaged used for debug;" },
		{  .name="spare_18", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_FATAL, .desc="spare_0 .. spare_7: Hardware Error; spare_8: err_phv_above_max: P4 program/compiler error. Packet need to get information form a PHV that is beyond the maximum supported; spare_9: capture engaged used for debug;" },
		{  .name="spare_19", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_FATAL, .desc="spare_0 .. spare_7: Hardware Error; spare_8: err_phv_above_max: P4 program/compiler error. Packet need to get information form a PHV that is beyond the maximum supported; spare_9: capture engaged used for debug;" },
		{  .name="spare_20", .next_ptr=nullptr, .id=22, .severity=INTR_SEV_TYPE_FATAL, .desc="spare_0 .. spare_7: Hardware Error; spare_8: err_phv_above_max: P4 program/compiler error. Packet need to get information form a PHV that is beyond the maximum supported; spare_9: capture engaged used for debug;" },
		{  .name="spare_21", .next_ptr=nullptr, .id=23, .severity=INTR_SEV_TYPE_FATAL, .desc="spare_0 .. spare_7: Hardware Error; spare_8: err_phv_above_max: P4 program/compiler error. Packet need to get information form a PHV that is beyond the maximum supported; spare_9: capture engaged used for debug;" },
		{  .name="spare_22", .next_ptr=nullptr, .id=24, .severity=INTR_SEV_TYPE_FATAL, .desc="spare_0 .. spare_7: Hardware Error; spare_8: err_phv_above_max: P4 program/compiler error. Packet need to get information form a PHV that is beyond the maximum supported; spare_9: capture engaged used for debug;" },
		{  .name="spare_23", .next_ptr=nullptr, .id=25, .severity=INTR_SEV_TYPE_FATAL, .desc="spare_0 .. spare_7: Hardware Error; spare_8: err_phv_above_max: P4 program/compiler error. Packet need to get information form a PHV that is beyond the maximum supported; spare_9: capture engaged used for debug;" },
		{  .name="spare_24", .next_ptr=nullptr, .id=26, .severity=INTR_SEV_TYPE_FATAL, .desc="spare_0 .. spare_7: Hardware Error; spare_8: err_phv_above_max: P4 program/compiler error. Packet need to get information form a PHV that is beyond the maximum supported; spare_9: capture engaged used for debug;" },
		{  .name="spare_25", .next_ptr=nullptr, .id=27, .severity=INTR_SEV_TYPE_FATAL, .desc="spare_0 .. spare_7: Hardware Error; spare_8: err_phv_above_max: P4 program/compiler error. Packet need to get information form a PHV that is beyond the maximum supported; spare_9: capture engaged used for debug;" },
		{  .name="spare_26", .next_ptr=nullptr, .id=28, .severity=INTR_SEV_TYPE_FATAL, .desc="spare_0 .. spare_7: Hardware Error; spare_8: err_phv_above_max: P4 program/compiler error. Packet need to get information form a PHV that is beyond the maximum supported; spare_9: capture engaged used for debug;" },
		{  .name="spare_27", .next_ptr=nullptr, .id=29, .severity=INTR_SEV_TYPE_FATAL, .desc="spare_0 .. spare_7: Hardware Error; spare_8: err_phv_above_max: P4 program/compiler error. Packet need to get information form a PHV that is beyond the maximum supported; spare_9: capture engaged used for debug;" },
		{  .name="spare_28", .next_ptr=nullptr, .id=30, .severity=INTR_SEV_TYPE_FATAL, .desc="spare_0 .. spare_7: Hardware Error; spare_8: err_phv_above_max: P4 program/compiler error. Packet need to get information form a PHV that is beyond the maximum supported; spare_9: capture engaged used for debug;" },
		{  .name="spare_29", .next_ptr=nullptr, .id=31, .severity=INTR_SEV_TYPE_FATAL, .desc="spare_0 .. spare_7: Hardware Error; spare_8: err_phv_above_max: P4 program/compiler error. Packet need to get information form a PHV that is beyond the maximum supported; spare_9: capture engaged used for debug;" },
		{  .name="spare_30", .next_ptr=nullptr, .id=32, .severity=INTR_SEV_TYPE_FATAL, .desc="spare_0 .. spare_7: Hardware Error; spare_8: err_phv_above_max: P4 program/compiler error. Packet need to get information form a PHV that is beyond the maximum supported; spare_9: capture engaged used for debug;" },
		{  .name="spare_31", .next_ptr=nullptr, .id=33, .severity=INTR_SEV_TYPE_FATAL, .desc="spare_0 .. spare_7: Hardware Error; spare_8: err_phv_above_max: P4 program/compiler error. Packet need to get information form a PHV that is beyond the maximum supported; spare_9: capture engaged used for debug;" },

	} };
intr_reg_t dpr_dpr_1_int_credit = {  .name="dpr.dpr[1].int_credit", .addr=0x3300100, .reg_type=0, .id=392, .field_count=4, .fields=
	{
		{  .name="egress_credit_ovflow", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="egress_credit_undflow", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="pktout_credit_ovflow", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="pktout_credit_undflow", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },

	} };
intr_reg_t dpr_dpr_1_int_groups_intreg = {  .name="dpr.dpr[1].int_groups.intreg", .addr=0x33000a0, .reg_type=1, .id=393, .field_count=8, .fields=
	{
		{  .name="int_reg1", .next_ptr=&dpr_dpr_1_int_reg1, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_reg2", .next_ptr=&dpr_dpr_1_int_reg2, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_srams_ecc", .next_ptr=&dpr_dpr_1_int_srams_ecc, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_fifo", .next_ptr=&dpr_dpr_1_int_fifo, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_flop_fifo_0", .next_ptr=&dpr_dpr_1_int_flop_fifo_0, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_flop_fifo_1", .next_ptr=&dpr_dpr_1_int_flop_fifo_1, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_spare", .next_ptr=&dpr_dpr_1_int_spare, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_credit", .next_ptr=&dpr_dpr_1_int_credit, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t pt_pt_psp_int_info = {  .name="pt.pt.psp.int_info", .addr=0x6206150, .reg_type=0, .id=181, .field_count=9, .fields=
	{
		{  .name="pr_pkt_ff_almost_full", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="almost full flow control was asserted" },
		{  .name="ptd_npv_phv_full", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="almost full flow control was asserted" },
		{  .name="phv_srdy_collapsed", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="collapsed multiple idential PHVs" },
		{  .name="pr_resub_pkt_before_phv", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="received the PKT before the PHV on the resub busses" },
		{  .name="pb_pbus_fsm0_no_data", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_INFO, .desc="received PHV with no data" },
		{  .name="pb_pbus_fsm1_no_data", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="received PHV with no data" },
		{  .name="pb_pbus_fsm2_no_data", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_INFO, .desc="received PHV with no data" },
		{  .name="pb_pbus_fsm3_no_data", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_INFO, .desc="received PHV with no data" },
		{  .name="pb_pbus_fsm4_no_data", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_INFO, .desc="received PHV with no data" },

	} };
intr_reg_t pt_pt_psp_int_err = {  .name="pt.pt.psp.int_err", .addr=0x6206160, .reg_type=0, .id=182, .field_count=14, .fields=
	{
		{  .name="pb_pbus_err", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_ERR, .desc="error bit received ont the input PKT bus" },
		{  .name="pr_pbus_err", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="error bit sent on the output PKT bus" },
		{  .name="pr_resub_pbus_err", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="error bit received ont the input PKT bus" },
		{  .name="psp_csr_read_access_err", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="psp_csr_read_access && psp_csr_ready && psp_csr_error" },
		{  .name="psp_csr_write_access_err", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="psp_csr_write_access && psp_csr_ready && psp_csr_error" },
		{  .name="psp_phv_larger_than_twelve_flits_err", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="PHV over the max 12 flits received and truncated" },
		{  .name="psp_phv_sop_offset_err", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="EOP seen before reaching PHV offset in SOP flit" },
		{  .name="psp_phv_eop_offset_err", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="EOP seen before reaching PHV offset" },
		{  .name="max_recir_count_err", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_ERR, .desc="a packet was recirculated through P4+ more than the cfg_profile_recirc_max" },
		{  .name="pb_pbus_dummy_err", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="there was a missing PKT after the PHV, so the HW generated a dummy PKT" },
		{  .name="pb_pbus_nopkt_err", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_ERR, .desc="PKT smaller than 12 flits received from the input PKT bus, PKT data was dropped" },
		{  .name="pb_pbus_min_err", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="PKT smaller than cfg_profile_phv_min received from the input PKT bus" },
		{  .name="lb_phv_almost_full_timeout_err", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="the PHV state machine waited for longer than cfg_profile_almost_full_timer_max" },
		{  .name="lb_pkt_almost_full_timeout_err", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="the PKT state machine waited for longer than cfg_profile_almost_full_timer_max" },

	} };
intr_reg_t pt_pt_psp_int_fatal = {  .name="pt.pt.psp.int_fatal", .addr=0x6206170, .reg_type=0, .id=183, .field_count=23, .fields=
	{
		{  .name="pb_pbus_sop_err", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="fatal HW fsm error, no HW handling" },
		{  .name="pb_pbus_eop_err", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="fatal HW fsm error, no HW handling" },
		{  .name="ma_sop_err", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_FATAL, .desc="fatal HW fsm error, no HW handling" },
		{  .name="ma_eop_err", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_FATAL, .desc="fatal HW fsm error, no HW handling" },
		{  .name="pr_pbus_sop_err", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_FATAL, .desc="fatal HW fsm error, no HW handling" },
		{  .name="pr_pbus_eop_err", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_FATAL, .desc="fatal HW fsm error, no HW handling" },
		{  .name="pr_resub_pbus_sop_err", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_FATAL, .desc="fatal HW fsm error, no HW handling" },
		{  .name="pr_resub_pbus_eop_err", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_FATAL, .desc="fatal HW fsm error, no HW handling" },
		{  .name="pr_resub_sop_err", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_FATAL, .desc="fatal HW fsm error, no HW handling" },
		{  .name="pr_resub_eop_err", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_FATAL, .desc="fatal HW fsm error, no HW handling" },
		{  .name="pb_pbus_fsm0_no_data_err", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_FATAL, .desc="fatal HW fsm error, no HW handling" },
		{  .name="pb_pbus_fsm1_no_data_err", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_FATAL, .desc="fatal HW fsm error, no HW handling" },
		{  .name="pb_pbus_fsm2_no_data_err", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_FATAL, .desc="fatal HW fsm error, no HW handling" },
		{  .name="pb_pbus_fsm3_no_data_err", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_FATAL, .desc="fatal HW fsm error, no HW handling" },
		{  .name="pb_pbus_fsm4_no_data_err", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_FATAL, .desc="fatal HW fsm error, no HW handling" },
		{  .name="pb_pbus_fsm5_pkt_too_small_err", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_FATAL, .desc="fatal HW fsm error, no HW handling" },
		{  .name="lif_ind_table_rsp_err", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_FATAL, .desc="fatal HW fsm error, no HW handling" },
		{  .name="flit_cnt_oflow_err", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_FATAL, .desc="fatal HW fsm error, no HW handling" },
		{  .name="lb_phv_sop_err", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_FATAL, .desc="fatal HW fsm error, no HW handling" },
		{  .name="dc_phv_sop_err", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_FATAL, .desc="fatal HW fsm error, no HW handling" },
		{  .name="lb_pkt_sop_err", .next_ptr=nullptr, .id=22, .severity=INTR_SEV_TYPE_FATAL, .desc="fatal HW fsm error, no HW handling" },
		{  .name="dc_pkt_sop_err", .next_ptr=nullptr, .id=23, .severity=INTR_SEV_TYPE_FATAL, .desc="fatal HW fsm error, no HW handling" },
		{  .name="sw_phv_jabber_err", .next_ptr=nullptr, .id=24, .severity=INTR_SEV_TYPE_FATAL, .desc="fatal HW fsm error, no HW handling" },

	} };
intr_reg_t pt_pt_psp_int_lif_qstate_map = {  .name="pt.pt.psp.int_lif_qstate_map", .addr=0x6210010, .reg_type=0, .id=184, .field_count=3, .fields=
	{
		{  .name="ecc_uncorrectable", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="ecc_correctable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="qid_invalid", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="lookup in lif table missed" },

	} };
intr_reg_t pt_pt_psp_int_sw_phv_mem = {  .name="pt.pt.psp.int_sw_phv_mem", .addr=0x6211010, .reg_type=0, .id=185, .field_count=12, .fields=
	{
		{  .name="ecc_uncorrectable", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="ecc_correctable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="phv_invalid_sram", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="bad SW PHV sram programming" },
		{  .name="phv_invalid_data", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="bad SW PHV sram programming" },
		{  .name="phv_done0", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_INFO, .desc="SW PHV done info" },
		{  .name="phv_done1", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="SW PHV done info" },
		{  .name="phv_done2", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_INFO, .desc="SW PHV done info" },
		{  .name="phv_done3", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_INFO, .desc="SW PHV done info" },
		{  .name="phv_done4", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_INFO, .desc="SW PHV done info" },
		{  .name="phv_done5", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_INFO, .desc="SW PHV done info" },
		{  .name="phv_done6", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_INFO, .desc="SW PHV done info" },
		{  .name="phv_done7", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_INFO, .desc="SW PHV done info" },

	} };
intr_reg_t pt_pt_psp_int_groups_intreg = {  .name="pt.pt.psp.int_groups.intreg", .addr=0x6206140, .reg_type=1, .id=186, .field_count=5, .fields=
	{
		{  .name="int_info", .next_ptr=&pt_pt_psp_int_info, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_err", .next_ptr=&pt_pt_psp_int_err, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_fatal", .next_ptr=&pt_pt_psp_int_fatal, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_lif_qstate_map", .next_ptr=&pt_pt_psp_int_lif_qstate_map, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_sw_phv_mem", .next_ptr=&pt_pt_psp_int_sw_phv_mem, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t mx_mx_1_int_mac = {  .name="mx.mx[1].int_mac", .addr=0x1e82080, .reg_type=0, .id=480, .field_count=30, .fields=
	{
		{  .name="lane0_sbe", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="lane0_dbe", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_HW_RMA, .desc="Double bit error in SerDes. Lane may go down" },
		{  .name="lane1_sbe", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="lane1_dbe", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_HW_RMA, .desc="Double bit error in SerDes. Lane may go down" },
		{  .name="lane2_sbe", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="lane2_dbe", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_HW_RMA, .desc="Double bit error in SerDes. Lane may go down" },
		{  .name="lane3_sbe", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="lane3_dbe", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_HW_RMA, .desc="Double bit error in SerDes. Lane may go down" },
		{  .name="umac_CFG3_intr", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="umac_CFG3_pslverr", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_INFO, .desc="Invalid need to be masked" },
		{  .name="m0pb_pbus_drdy", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_FATAL, .desc="Debug PB config. Never happen; otherwise, it's hardware bug" },
		{  .name="m1pb_pbus_drdy", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_FATAL, .desc="Debug PB config. Never happen; otherwise, it's hardware bug" },
		{  .name="m2pb_pbus_drdy", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_FATAL, .desc="Debug PB config. Never happen; otherwise, it's hardware bug" },
		{  .name="m3pb_pbus_drdy", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_FATAL, .desc="Debug PB config. Never happen; otherwise, it's hardware bug" },
		{  .name="rx0_missing_sof", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_INFO, .desc="HW self recover" },
		{  .name="rx0_missing_eof", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_INFO, .desc="HW self recover" },
		{  .name="rx0_timeout_err", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_INFO, .desc="HW self recover" },
		{  .name="rx0_min_size_err", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_INFO, .desc="HW self recover" },
		{  .name="rx1_missing_sof", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_INFO, .desc="HW self recover" },
		{  .name="rx1_missing_eof", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_INFO, .desc="HW self recover" },
		{  .name="rx1_timeout_err", .next_ptr=nullptr, .id=22, .severity=INTR_SEV_TYPE_INFO, .desc="HW self recover" },
		{  .name="rx1_min_size_err", .next_ptr=nullptr, .id=23, .severity=INTR_SEV_TYPE_INFO, .desc="HW self recover" },
		{  .name="rx2_missing_sof", .next_ptr=nullptr, .id=24, .severity=INTR_SEV_TYPE_INFO, .desc="HW self recover" },
		{  .name="rx2_missing_eof", .next_ptr=nullptr, .id=25, .severity=INTR_SEV_TYPE_INFO, .desc="HW self recover" },
		{  .name="rx2_timeout_err", .next_ptr=nullptr, .id=26, .severity=INTR_SEV_TYPE_INFO, .desc="HW self recover" },
		{  .name="rx2_min_size_err", .next_ptr=nullptr, .id=27, .severity=INTR_SEV_TYPE_INFO, .desc="HW self recover" },
		{  .name="rx3_missing_sof", .next_ptr=nullptr, .id=28, .severity=INTR_SEV_TYPE_INFO, .desc="HW self recover" },
		{  .name="rx3_missing_eof", .next_ptr=nullptr, .id=29, .severity=INTR_SEV_TYPE_INFO, .desc="HW self recover" },
		{  .name="rx3_timeout_err", .next_ptr=nullptr, .id=30, .severity=INTR_SEV_TYPE_INFO, .desc="HW self recover" },
		{  .name="rx3_min_size_err", .next_ptr=nullptr, .id=31, .severity=INTR_SEV_TYPE_INFO, .desc="HW self recover" },

	} };
intr_reg_t mx_mx_1_int_ecc = {  .name="mx.mx[1].int_ecc", .addr=0x1e820c0, .reg_type=0, .id=481, .field_count=2, .fields=
	{
		{  .name="uncorrectable", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="correctable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },

	} };
intr_reg_t mx_mx_1_int_groups_intreg = {  .name="mx.mx[1].int_groups.intreg", .addr=0x1e82070, .reg_type=1, .id=482, .field_count=2, .fields=
	{
		{  .name="int_mac", .next_ptr=&mx_mx_1_int_mac, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_ecc", .next_ptr=&mx_mx_1_int_ecc, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t mc_mc_2_mch_int_mc = {  .name="mc.mc[2].mch.int_mc", .addr=0x6a300060, .reg_type=0, .id=404, .field_count=2, .fields=
	{
		{  .name="ecc_1bit_thresh_ps1", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_ERR, .desc="" },
		{  .name="ecc_1bit_thresh_ps0", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="" },

	} };
intr_reg_t mc_mc_2_mch_int_groups_intreg = {  .name="mc.mc[2].mch.int_groups.intreg", .addr=0x6a300050, .reg_type=1, .id=405, .field_count=1, .fields=
	{
		{  .name="int_mc", .next_ptr=&mc_mc_2_mch_int_mc, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t sema_sema_int_groups_intreg = {  .name="sema.sema.int_groups.intreg", .addr=0x40000010, .reg_type=1, .id=440, .field_count=1, .fields=
	{
		{  .name="sema_err", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t ppa_ppa_0_int_bndl0 = {  .name="ppa.ppa[0].int_bndl0", .addr=0x34402c0, .reg_type=0, .id=1, .field_count=3, .fields=
	{
		{  .name="state_lkp_srch_hit_addr_range_err", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Parser TCAM entry programmed out of valid range." },
		{  .name="state_lkp_srch_miss", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Parser TCAM search miss" },
		{  .name="state_lkp_srch_req_not_rdy", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },

	} };
intr_reg_t ppa_ppa_0_int_bndl1 = {  .name="ppa.ppa[0].int_bndl1", .addr=0x34402d0, .reg_type=0, .id=2, .field_count=3, .fields=
	{
		{  .name="state_lkp_srch_hit_addr_range_err", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Parser TCAM entry programmed out of valid range." },
		{  .name="state_lkp_srch_miss", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Parser TCAM search miss" },
		{  .name="state_lkp_srch_req_not_rdy", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },

	} };
intr_reg_t ppa_ppa_0_int_ecc = {  .name="ppa.ppa[0].int_ecc", .addr=0x34402e0, .reg_type=0, .id=3, .field_count=6, .fields=
	{
		{  .name="pkt_mem_uncorrectable", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="pkt_mem_correctable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="bndl0_state_lkp_sram_uncorrectable", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="bndl0_state_lkp_sram_correctable", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="bndl1_state_lkp_sram_uncorrectable", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="bndl1_state_lkp_sram_correctable", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },

	} };
intr_reg_t ppa_ppa_0_int_fifo1 = {  .name="ppa.ppa[0].int_fifo1", .addr=0x34402f0, .reg_type=0, .id=4, .field_count=30, .fields=
	{
		{  .name="pe0_qctl_ff_ovflow", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="pe1_qctl_ff_ovflow", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="pe2_qctl_ff_ovflow", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="pe3_qctl_ff_ovflow", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="pe4_qctl_ff_ovflow", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="pe5_qctl_ff_ovflow", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="pe6_qctl_ff_ovflow", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="pe7_qctl_ff_ovflow", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="pe8_qctl_ff_ovflow", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="pe9_qctl_ff_ovflow", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="pe0_phv_ff_ovflow", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="pe1_phv_ff_ovflow", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="pe2_phv_ff_ovflow", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="pe3_phv_ff_ovflow", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="pe4_phv_ff_ovflow", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="pe5_phv_ff_ovflow", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="pe6_phv_ff_ovflow", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="pe7_phv_ff_ovflow", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="pe8_phv_ff_ovflow", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="pe9_phv_ff_ovflow", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="pe0_ohi_ff_ovflow", .next_ptr=nullptr, .id=22, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="pe1_ohi_ff_ovflow", .next_ptr=nullptr, .id=23, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="pe2_ohi_ff_ovflow", .next_ptr=nullptr, .id=24, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="pe3_ohi_ff_ovflow", .next_ptr=nullptr, .id=25, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="pe4_ohi_ff_ovflow", .next_ptr=nullptr, .id=26, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="pe5_ohi_ff_ovflow", .next_ptr=nullptr, .id=27, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="pe6_ohi_ff_ovflow", .next_ptr=nullptr, .id=28, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="pe7_ohi_ff_ovflow", .next_ptr=nullptr, .id=29, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="pe8_ohi_ff_ovflow", .next_ptr=nullptr, .id=30, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="pe9_ohi_ff_ovflow", .next_ptr=nullptr, .id=31, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },

	} };
intr_reg_t ppa_ppa_0_int_fifo2 = {  .name="ppa.ppa[0].int_fifo2", .addr=0x3440300, .reg_type=0, .id=5, .field_count=8, .fields=
	{
		{  .name="dp_if_ff_ovflow", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="ohi_if_ff_ovflow", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="ma_if_ff_ovflow", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="pb_if_ff_ovflow", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="pkt_mtu_ff_ovflow", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="outphv_ff_ovflow", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="outohi_ff_ovflow", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="chk_ff_ovflow", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },

	} };
intr_reg_t ppa_ppa_0_int_pe0 = {  .name="ppa.ppa[0].int_pe0", .addr=0x3440310, .reg_type=0, .id=6, .field_count=10, .fields=
	{
		{  .name="qctl_skid_depth_not_zero", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="qctl_not_sop_after_pkt_release", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="unexpected_non_sop", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="exceed_phv_flit_cnt", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="software error: Number of phv flits generated exceeded the limit." },
		{  .name="exceed_parse_loop_cnt", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="software error: Number of parse states jump for a packet exceeded the limit. " },
		{  .name="offset_out_of_range", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Parser state programming error." },
		{  .name="pkt_size_chk", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Not enough bytes in packet. Parser state programming error." },
		{  .name="offset_jump_chk", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Parser state programming error." },
		{  .name="d1_not_valid", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="phv_upr_idx_less", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Parser state programming error." },

	} };
intr_reg_t ppa_ppa_0_int_pe1 = {  .name="ppa.ppa[0].int_pe1", .addr=0x3440320, .reg_type=0, .id=7, .field_count=10, .fields=
	{
		{  .name="qctl_skid_depth_not_zero", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="qctl_not_sop_after_pkt_release", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="unexpected_non_sop", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="exceed_phv_flit_cnt", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="software error: Number of phv flits generated exceeded the limit." },
		{  .name="exceed_parse_loop_cnt", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="software error: Number of parse states jump for a packet exceeded the limit. " },
		{  .name="offset_out_of_range", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Parser state programming error." },
		{  .name="pkt_size_chk", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Not enough bytes in packet. Parser state programming error." },
		{  .name="offset_jump_chk", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Parser state programming error." },
		{  .name="d1_not_valid", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="phv_upr_idx_less", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Parser state programming error." },

	} };
intr_reg_t ppa_ppa_0_int_pe2 = {  .name="ppa.ppa[0].int_pe2", .addr=0x3440330, .reg_type=0, .id=8, .field_count=10, .fields=
	{
		{  .name="qctl_skid_depth_not_zero", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="qctl_not_sop_after_pkt_release", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="unexpected_non_sop", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="exceed_phv_flit_cnt", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="software error: Number of phv flits generated exceeded the limit." },
		{  .name="exceed_parse_loop_cnt", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="software error: Number of parse states jump for a packet exceeded the limit. " },
		{  .name="offset_out_of_range", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Parser state programming error." },
		{  .name="pkt_size_chk", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Not enough bytes in packet. Parser state programming error." },
		{  .name="offset_jump_chk", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Parser state programming error." },
		{  .name="d1_not_valid", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="phv_upr_idx_less", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Parser state programming error." },

	} };
intr_reg_t ppa_ppa_0_int_pe3 = {  .name="ppa.ppa[0].int_pe3", .addr=0x3440340, .reg_type=0, .id=9, .field_count=10, .fields=
	{
		{  .name="qctl_skid_depth_not_zero", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="qctl_not_sop_after_pkt_release", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="unexpected_non_sop", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="exceed_phv_flit_cnt", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="software error: Number of phv flits generated exceeded the limit." },
		{  .name="exceed_parse_loop_cnt", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="software error: Number of parse states jump for a packet exceeded the limit. " },
		{  .name="offset_out_of_range", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Parser state programming error." },
		{  .name="pkt_size_chk", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Not enough bytes in packet. Parser state programming error." },
		{  .name="offset_jump_chk", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Parser state programming error." },
		{  .name="d1_not_valid", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="phv_upr_idx_less", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Parser state programming error." },

	} };
intr_reg_t ppa_ppa_0_int_pe4 = {  .name="ppa.ppa[0].int_pe4", .addr=0x3440350, .reg_type=0, .id=10, .field_count=10, .fields=
	{
		{  .name="qctl_skid_depth_not_zero", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="qctl_not_sop_after_pkt_release", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="unexpected_non_sop", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="exceed_phv_flit_cnt", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="software error: Number of phv flits generated exceeded the limit." },
		{  .name="exceed_parse_loop_cnt", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="software error: Number of parse states jump for a packet exceeded the limit. " },
		{  .name="offset_out_of_range", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Parser state programming error." },
		{  .name="pkt_size_chk", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Not enough bytes in packet. Parser state programming error." },
		{  .name="offset_jump_chk", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Parser state programming error." },
		{  .name="d1_not_valid", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="phv_upr_idx_less", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Parser state programming error." },

	} };
intr_reg_t ppa_ppa_0_int_pe5 = {  .name="ppa.ppa[0].int_pe5", .addr=0x3440360, .reg_type=0, .id=11, .field_count=10, .fields=
	{
		{  .name="qctl_skid_depth_not_zero", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="qctl_not_sop_after_pkt_release", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="unexpected_non_sop", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="exceed_phv_flit_cnt", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="software error: Number of phv flits generated exceeded the limit." },
		{  .name="exceed_parse_loop_cnt", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="software error: Number of parse states jump for a packet exceeded the limit. " },
		{  .name="offset_out_of_range", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Parser state programming error." },
		{  .name="pkt_size_chk", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Not enough bytes in packet. Parser state programming error." },
		{  .name="offset_jump_chk", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Parser state programming error." },
		{  .name="d1_not_valid", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="phv_upr_idx_less", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Parser state programming error." },

	} };
intr_reg_t ppa_ppa_0_int_pe6 = {  .name="ppa.ppa[0].int_pe6", .addr=0x3440370, .reg_type=0, .id=12, .field_count=10, .fields=
	{
		{  .name="qctl_skid_depth_not_zero", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="qctl_not_sop_after_pkt_release", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="unexpected_non_sop", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="exceed_phv_flit_cnt", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="software error: Number of phv flits generated exceeded the limit." },
		{  .name="exceed_parse_loop_cnt", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="software error: Number of parse states jump for a packet exceeded the limit. " },
		{  .name="offset_out_of_range", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Parser state programming error." },
		{  .name="pkt_size_chk", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Not enough bytes in packet. Parser state programming error." },
		{  .name="offset_jump_chk", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Parser state programming error." },
		{  .name="d1_not_valid", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="phv_upr_idx_less", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Parser state programming error." },

	} };
intr_reg_t ppa_ppa_0_int_pe7 = {  .name="ppa.ppa[0].int_pe7", .addr=0x3440380, .reg_type=0, .id=13, .field_count=10, .fields=
	{
		{  .name="qctl_skid_depth_not_zero", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="qctl_not_sop_after_pkt_release", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="unexpected_non_sop", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="exceed_phv_flit_cnt", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="software error: Number of phv flits generated exceeded the limit." },
		{  .name="exceed_parse_loop_cnt", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="software error: Number of parse states jump for a packet exceeded the limit. " },
		{  .name="offset_out_of_range", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Parser state programming error." },
		{  .name="pkt_size_chk", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Not enough bytes in packet. Parser state programming error." },
		{  .name="offset_jump_chk", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Parser state programming error." },
		{  .name="d1_not_valid", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="phv_upr_idx_less", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Parser state programming error." },

	} };
intr_reg_t ppa_ppa_0_int_pe8 = {  .name="ppa.ppa[0].int_pe8", .addr=0x3440390, .reg_type=0, .id=14, .field_count=10, .fields=
	{
		{  .name="qctl_skid_depth_not_zero", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="qctl_not_sop_after_pkt_release", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="unexpected_non_sop", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="exceed_phv_flit_cnt", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="software error: Number of phv flits generated exceeded the limit." },
		{  .name="exceed_parse_loop_cnt", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="software error: Number of parse states jump for a packet exceeded the limit. " },
		{  .name="offset_out_of_range", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Parser state programming error." },
		{  .name="pkt_size_chk", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Not enough bytes in packet. Parser state programming error." },
		{  .name="offset_jump_chk", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Parser state programming error." },
		{  .name="d1_not_valid", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="phv_upr_idx_less", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Parser state programming error." },

	} };
intr_reg_t ppa_ppa_0_int_pe9 = {  .name="ppa.ppa[0].int_pe9", .addr=0x34403a0, .reg_type=0, .id=15, .field_count=10, .fields=
	{
		{  .name="qctl_skid_depth_not_zero", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="qctl_not_sop_after_pkt_release", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="unexpected_non_sop", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="exceed_phv_flit_cnt", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="software error: Number of phv flits generated exceeded the limit." },
		{  .name="exceed_parse_loop_cnt", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="software error: Number of parse states jump for a packet exceeded the limit. " },
		{  .name="offset_out_of_range", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Parser state programming error." },
		{  .name="pkt_size_chk", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Not enough bytes in packet. Parser state programming error." },
		{  .name="offset_jump_chk", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Parser state programming error." },
		{  .name="d1_not_valid", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="phv_upr_idx_less", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Parser state programming error." },

	} };
intr_reg_t ppa_ppa_0_int_pa = {  .name="ppa.ppa[0].int_pa", .addr=0x34403b0, .reg_type=0, .id=16, .field_count=21, .fields=
	{
		{  .name="reorder_phv_not_sop", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="csum0_not_enuf_bytes", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="software error. CSUM checking logic has programmable start and end offset. The packet ended before end offset. It's possible the packet is malformed as well. Check for other interrupts in PB." },
		{  .name="csum0_start_more_than_end_offset", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="Software error. CSUM checking logic programmable start offset is more than end offset" },
		{  .name="csum1_not_enuf_bytes", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="software error. CSUM checking logic has programmable start and end offset. The packet ended before end offset. It's possible the packet is malformed as well. Check for other interrupts in PB." },
		{  .name="csum1_start_more_than_end_offset", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="Software error. CSUM checking logic programmable start offset is more than end offset" },
		{  .name="csum2_not_enuf_bytes", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="software error. CSUM checking logic has programmable start and end offset. The packet ended before end offset. It's possible the packet is malformed as well. Check for other interrupts in PB." },
		{  .name="csum2_start_more_than_end_offset", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="Software error. CSUM checking logic programmable start offset is more than end offset" },
		{  .name="csum3_not_enuf_bytes", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="software error. CSUM checking logic has programmable start and end offset. The packet ended before end offset. It's possible the packet is malformed as well. Check for other interrupts in PB." },
		{  .name="csum3_start_more_than_end_offset", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_ERR, .desc="Software error. CSUM checking logic programmable start offset is more than end offset" },
		{  .name="csum4_not_enuf_bytes", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="software error. CSUM checking logic has programmable start and end offset. The packet ended before end offset. It's possible the packet is malformed as well. Check for other interrupts in PB." },
		{  .name="csum4_start_more_than_end_offset", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_ERR, .desc="Software error. CSUM checking logic programmable start offset is more than end offset" },
		{  .name="crc_not_enuf_bytes", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="software error. CRC checking logic has programmable start and end offset. The packet ended before end offset. It's possible the packet is malformed as well. Check for other interrupts in PB." },
		{  .name="crc_start_more_than_end_offset", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="Software error. CRC checking logic programmable start offset is more than end offset" },
		{  .name="chkr_phv_single_flit", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="chkr_phv_not_sop", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="chkr_pkt_not_sop", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="chkr_seq_id", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="preparse_line0_not_sop", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="preparse_dff_not_sop", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="preparse_dff_ovflow", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="preparse_eff_ovflow", .next_ptr=nullptr, .id=22, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },

	} };
intr_reg_t ppa_ppa_0_int_sw_phv_mem = {  .name="ppa.ppa[0].int_sw_phv_mem", .addr=0x3441010, .reg_type=0, .id=17, .field_count=12, .fields=
	{
		{  .name="ecc_uncorrectable", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="ecc_correctable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="phv_invalid_sram", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="phv_invalid_data", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="phv_done0", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="phv_done1", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="phv_done2", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="phv_done3", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="phv_done4", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="phv_done5", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="phv_done6", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="phv_done7", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t ppa_ppa_0_int_intf = {  .name="ppa.ppa[0].int_intf", .addr=0x34403c0, .reg_type=0, .id=18, .field_count=15, .fields=
	{
		{  .name="pb_err", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_ERR, .desc="Packet err bit set along with EOP in packet bus from buffer to Parser. Error bit probably is from memory ecc error. Check other interrupts in PB." },
		{  .name="pb_sop_err", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="pb_eop_err", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="dp_err", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="Packet err bit set along with EOP in packet bus from Parser to Deparser. Error bit probably is from buffer or from memory ecc error. Check other interrupts." },
		{  .name="dp_sop_err", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="dp_eop_err", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="ohi_err", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="Packet err bit set along with EOP in OHI bus from Parser to Deparser. Error bit probably is from buffer or from memory ecc error. Check other interrupts." },
		{  .name="ohi_sop_err", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="ohi_eop_err", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="sw_phv_err", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="SW phv gen logic set error along with PHV. Error bit probably is from memory ecc error. Check other interrupts." },
		{  .name="sw_phv_sop_err", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="sw_phv_eop_err", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="ma_err", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="Packet err bit set along with EOP in PHV bus from Parser to STG. Error bit probably is from memory ecc error. Check other interrupts." },
		{  .name="ma_sop_err", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="ma_eop_err", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },

	} };
intr_reg_t ppa_ppa_0_int_groups_intreg = {  .name="ppa.ppa[0].int_groups.intreg", .addr=0x34402b0, .reg_type=1, .id=19, .field_count=18, .fields=
	{
		{  .name="int_bndl0", .next_ptr=&ppa_ppa_0_int_bndl0, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_bndl1", .next_ptr=&ppa_ppa_0_int_bndl1, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_ecc", .next_ptr=&ppa_ppa_0_int_ecc, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_fifo1", .next_ptr=&ppa_ppa_0_int_fifo1, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_fifo2", .next_ptr=&ppa_ppa_0_int_fifo2, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_pe0", .next_ptr=&ppa_ppa_0_int_pe0, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_pe1", .next_ptr=&ppa_ppa_0_int_pe1, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_pe2", .next_ptr=&ppa_ppa_0_int_pe2, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_pe3", .next_ptr=&ppa_ppa_0_int_pe3, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_pe4", .next_ptr=&ppa_ppa_0_int_pe4, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_pe5", .next_ptr=&ppa_ppa_0_int_pe5, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_pe6", .next_ptr=&ppa_ppa_0_int_pe6, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_pe7", .next_ptr=&ppa_ppa_0_int_pe7, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_pe8", .next_ptr=&ppa_ppa_0_int_pe8, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_pe9", .next_ptr=&ppa_ppa_0_int_pe9, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_pa", .next_ptr=&ppa_ppa_0_int_pa, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_sw_phv_mem", .next_ptr=&ppa_ppa_0_int_sw_phv_mem, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_intf", .next_ptr=&ppa_ppa_0_int_intf, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t pcr_te_6_int_err = {  .name="pcr.te[6].int_err", .addr=0x6302440, .reg_type=0, .id=211, .field_count=20, .fields=
	{
		{  .name="miss_sop", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="previous stage error" },
		{  .name="miss_eop", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="previous stage error" },
		{  .name="phv_max_size", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="invalid" },
		{  .name="spurious_axi_rsp", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="spurious_tcam_rsp", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_FATAL, .desc="bad tcam response" },
		{  .name="te2mpu_timeout", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="impossible, should be disabled" },
		{  .name="axi_rdrsp_err", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="axi_bad_read", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="tcam_req_idx_fifo", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="tcam_rsp_idx_fifo", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="mpu_req_idx_fifo", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="axi_req_idx_fifo", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="proc_tbl_vld_wo_proc", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend_wo_wb", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend1_wo_pend0", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="both_pend_down", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend_wo_proc_down", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="both_pend_went_up", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="loaded_but_no_proc", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="loaded_but_no_proc_tbl_vld", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },

	} };
intr_reg_t pcr_te_6_int_info = {  .name="pcr.te[6].int_info", .addr=0x6302450, .reg_type=0, .id=212, .field_count=17, .fields=
	{
		{  .name="profile_cam_hit0", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit1", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit2", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit4", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit5", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit6", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit7", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit8", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit9", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit10", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit11", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit12", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit13", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit14", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit15", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_miss", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t pcr_te_6_int_groups_intreg = {  .name="pcr.te[6].int_groups.intreg", .addr=0x6302430, .reg_type=1, .id=213, .field_count=2, .fields=
	{
		{  .name="int_err", .next_ptr=&pcr_te_6_int_err, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_info", .next_ptr=&pcr_te_6_int_info, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t mc_mc_1_mch_int_mc = {  .name="mc.mc[1].mch.int_mc", .addr=0x6a200060, .reg_type=0, .id=400, .field_count=2, .fields=
	{
		{  .name="ecc_1bit_thresh_ps1", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_ERR, .desc="" },
		{  .name="ecc_1bit_thresh_ps0", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="" },

	} };
intr_reg_t mc_mc_1_mch_int_groups_intreg = {  .name="mc.mc[1].mch.int_groups.intreg", .addr=0x6a200050, .reg_type=1, .id=401, .field_count=1, .fields=
	{
		{  .name="int_mc", .next_ptr=&mc_mc_1_mch_int_mc, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t sge_mpu_1_int_err = {  .name="sge.mpu[1].int_err", .addr=0x3698630, .reg_type=0, .id=108, .field_count=27, .fields=
	{
		{  .name="results_mismatch", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="mask this interrupt, not fully implemented" },
		{  .name="sdp_mem_uncorrectable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="sdp_mem_correctable", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="illegal_op_0", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_1", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_2", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_3", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="max_inst_0", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_1", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_2", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_3", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="phvwr_0", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_1", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_2", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_3", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="write_err_0", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_1", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_2", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_3", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="cache_axi_0", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_1", .next_ptr=nullptr, .id=22, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_2", .next_ptr=nullptr, .id=23, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_3", .next_ptr=nullptr, .id=24, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_parity_0", .next_ptr=nullptr, .id=25, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_1", .next_ptr=nullptr, .id=26, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_2", .next_ptr=nullptr, .id=27, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_3", .next_ptr=nullptr, .id=28, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },

	} };
intr_reg_t sge_mpu_1_int_info = {  .name="sge.mpu[1].int_info", .addr=0x3698640, .reg_type=0, .id=109, .field_count=8, .fields=
	{
		{  .name="trace_full_0", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_1", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_2", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="mpu_stop_0", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_1", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_2", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_3", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },

	} };
intr_reg_t sge_mpu_1_int_groups_intreg = {  .name="sge.mpu[1].int_groups.intreg", .addr=0x3698620, .reg_type=1, .id=110, .field_count=2, .fields=
	{
		{  .name="int_err", .next_ptr=&sge_mpu_1_int_err, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_info", .next_ptr=&sge_mpu_1_int_info, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t mc_mc_5_int_mc = {  .name="mc.mc[5].int_mc", .addr=0x6a680020, .reg_type=0, .id=414, .field_count=1, .fields=
	{
		{  .name="mch_int", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_ERR, .desc="" },

	} };
intr_reg_t mc_mc_5_int_groups_intreg = {  .name="mc.mc[5].int_groups.intreg", .addr=0x6a680010, .reg_type=1, .id=415, .field_count=1, .fields=
	{
		{  .name="int_mc", .next_ptr=&mc_mc_5_int_mc, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t dpr_dpr_0_int_reg1 = {  .name="dpr.dpr[0].int_reg1", .addr=0x32000b0, .reg_type=0, .id=376, .field_count=29, .fields=
	{
		{  .name="err_phv_sop_no_eop", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="err_phv_eop_no_sop", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="err_ohi_sop_no_eop", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="err_ohi_eop_no_sop", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="err_pktin_sop_no_eop", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="err_pktin_eop_no_sop", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="err_csum_offset_gt_pkt_size_4", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="P4 program/compiler error. Checksum covers more than packet size" },
		{  .name="err_csum_offset_gt_pkt_size_3", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="P4 program/compiler error. Checksum covers more than packet size" },
		{  .name="err_csum_offset_gt_pkt_size_2", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_ERR, .desc="P4 program/compiler error. Checksum covers more than packet size" },
		{  .name="err_csum_offset_gt_pkt_size_1", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="P4 program/compiler error. Checksum covers more than packet size" },
		{  .name="err_csum_offset_gt_pkt_size_0", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_ERR, .desc="P4 program/compiler error. Checksum covers more than packet size" },
		{  .name="err_csum_phdr_offset_gt_pkt_size_4", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="P4 program/compiler error. Checksum pseudoheaders covers more than packet size" },
		{  .name="err_csum_phdr_offset_gt_pkt_size_3", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="P4 program/compiler error. Checksum pseudoheaders covers more than packet size" },
		{  .name="err_csum_phdr_offset_gt_pkt_size_2", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="P4 program/compiler error. Checksum pseudoheaders covers more than packet size" },
		{  .name="err_csum_phdr_offset_gt_pkt_size_1", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_ERR, .desc="P4 program/compiler error. Checksum pseudoheaders covers more than packet size" },
		{  .name="err_csum_phdr_offset_gt_pkt_size_0", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="P4 program/compiler error. Checksum pseudoheaders covers more than packet size" },
		{  .name="err_csum_loc_gt_pkt_size_4", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="P4 program/compiler error. Checksum location greater then packet size" },
		{  .name="err_csum_loc_gt_pkt_size_3", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_ERR, .desc="P4 program/compiler error. Checksum location greater then packet size" },
		{  .name="err_csum_loc_gt_pkt_size_2", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_ERR, .desc="P4 program/compiler error. Checksum location greater then packet size" },
		{  .name="err_csum_loc_gt_pkt_size_1", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_ERR, .desc="P4 program/compiler error. Checksum location greater then packet size" },
		{  .name="err_csum_loc_gt_pkt_size_0", .next_ptr=nullptr, .id=22, .severity=INTR_SEV_TYPE_ERR, .desc="P4 program/compiler error. Checksum location greater then packet size" },
		{  .name="err_crc_offset_gt_pkt_size", .next_ptr=nullptr, .id=23, .severity=INTR_SEV_TYPE_ERR, .desc="P4 program/compiler error. ICRC covers more than packet size" },
		{  .name="err_crc_loc_gt_pkt_size", .next_ptr=nullptr, .id=24, .severity=INTR_SEV_TYPE_ERR, .desc="P4 program/compiler error. ICRC location greater then packet size" },
		{  .name="err_crc_mask_offset_gt_pkt_size", .next_ptr=nullptr, .id=25, .severity=INTR_SEV_TYPE_INFO, .desc="Invalid need to be masked" },
		{  .name="err_pkt_eop_early", .next_ptr=nullptr, .id=26, .severity=INTR_SEV_TYPE_INFO, .desc="spare" },
		{  .name="err_ptr_ff_overflow", .next_ptr=nullptr, .id=27, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="err_csum_ff_overflow", .next_ptr=nullptr, .id=28, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="err_pktout_ff_overflow", .next_ptr=nullptr, .id=29, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="err_ptr_from_cfg_overflow", .next_ptr=nullptr, .id=30, .severity=INTR_SEV_TYPE_INFO, .desc="Hardware Error" },

	} };
intr_reg_t dpr_dpr_0_int_reg2 = {  .name="dpr.dpr[0].int_reg2", .addr=0x32000c0, .reg_type=0, .id=377, .field_count=8, .fields=
	{
		{  .name="fieldC", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="spare" },
		{  .name="fieldD", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="spare" },
		{  .name="err_csum_start_gt_end_4", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="P4 program/compiler error. Checksum start is greater then end" },
		{  .name="err_csum_start_gt_end_3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="P4 program/compiler error. Checksum start is greater then end" },
		{  .name="err_csum_start_gt_end_2", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="P4 program/compiler error. Checksum start is greater then end" },
		{  .name="err_csum_start_gt_end_1", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="P4 program/compiler error. Checksum start is greater then end" },
		{  .name="err_csum_start_gt_end_0", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="P4 program/compiler error. Checksum start is greater then end" },
		{  .name="err_crc_start_gt_end", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="P4 program/compiler error. ICRC start is greater then end" },

	} };
intr_reg_t dpr_dpr_0_int_srams_ecc = {  .name="dpr.dpr[0].int_srams_ecc", .addr=0x3200080, .reg_type=0, .id=378, .field_count=12, .fields=
	{
		{  .name="dpr_pktin_fifo_uncorrectable", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="dpr_pktin_fifo_correctable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="dpr_csum_fifo_uncorrectable", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="dpr_csum_fifo_correctable", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="dpr_phv_fifo_uncorrectable", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="dpr_phv_fifo_correctable", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="dpr_ohi_fifo_uncorrectable", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="dpr_ohi_fifo_correctable", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="dpr_ptr_fifo_uncorrectable", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="dpr_ptr_fifo_correctable", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="dpr_pktout_fifo_uncorrectable", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="dpr_pktout_fifo_correctable", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },

	} };
intr_reg_t dpr_dpr_0_int_fifo = {  .name="dpr.dpr[0].int_fifo", .addr=0x32000d0, .reg_type=0, .id=379, .field_count=6, .fields=
	{
		{  .name="phv_ff_ovflow", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="ohi_ff_ovflow", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="pktin_ff_ovflow", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="pktout_ff_undflow", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="csum_ff_ovflow", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="ptr_ff_ovflow", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },

	} };
intr_reg_t dpr_dpr_0_int_flop_fifo_0 = {  .name="dpr.dpr[0].int_flop_fifo_0", .addr=0x32000e0, .reg_type=0, .id=380, .field_count=20, .fields=
	{
		{  .name="data_mux_force_bypass_crc_flop_ff_ovflow", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="dpr_crc_info_flop_ff_ovflow", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="dpr_crc_update_info_flop_ff_ovflow", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="dpr_csum_info_flop_ff_ovflow", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="data_mux_force_bypass_csum_flop_ff_ovflow", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="dpr_csum_update_info_flop_ff_ovflow", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="ptr_early_pkt_eop_info_flop_ff_ovflow", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="data_mux_eop_err_flop_ff_ovflow", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="pktin_eop_err_flop_ff_ovflow", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="csum_err_flop_ff_ovflow", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="crc_err_flop_ff_ovflow", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="data_mux_drop_flop_ff_ovflow", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="phv_pkt_data_flop_ff_ovflow", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="pktout_len_cell_flop_ff_ovflow", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="padding_size_flop_ff_ovflow", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="pktin_err_flop_ff_ovflow", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="phv_no_data_flop_ff_ovflow", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="ptr_lookahaed_flop_ff_ovflow", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="eop_vld_flop_ff_ovflow", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="csum_cal_vld_flop_ff_ovflow", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },

	} };
intr_reg_t dpr_dpr_0_int_flop_fifo_1 = {  .name="dpr.dpr[0].int_flop_fifo_1", .addr=0x32000f0, .reg_type=0, .id=381, .field_count=20, .fields=
	{
		{  .name="data_mux_force_bypass_crc_flop_ff_undflow", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="dpr_crc_info_flop_ff_undflow", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="dpr_crc_update_info_flop_ff_undflow", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="dpr_csum_info_flop_ff_undflow", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="data_mux_force_bypass_csum_flop_ff_undflow", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="dpr_csum_update_info_flop_ff_undflow", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="ptr_early_pkt_eop_info_flop_ff_undflow", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="data_mux_eop_err_flop_ff_undflow", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="pktin_eop_err_flop_ff_undflow", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="csum_err_flop_ff_undflow", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="crc_err_flop_ff_undflow", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="data_mux_drop_flop_ff_undflow", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="phv_pkt_data_flop_ff_undflow", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="pktout_len_cell_flop_ff_undflow", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="padding_size_flop_ff_undflow", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="pktin_err_flop_ff_undflow", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="phv_no_data_flop_ff_undflow", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="ptr_lookahaed_flop_ff_undflow", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="eop_vld_flop_ff_undflow", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="csum_cal_vld_flop_ff_undflow", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },

	} };
intr_reg_t dpr_dpr_0_int_spare = {  .name="dpr.dpr[0].int_spare", .addr=0x3200110, .reg_type=0, .id=382, .field_count=32, .fields=
	{
		{  .name="spare_0", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="spare_0 .. spare_7: Hardware Error; spare_8: err_phv_above_max: P4 program/compiler error. Packet need to get information form a PHV that is beyond the maximum supported; spare_9: capture engaged used for debug;" },
		{  .name="spare_1", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="spare_0 .. spare_7: Hardware Error; spare_8: err_phv_above_max: P4 program/compiler error. Packet need to get information form a PHV that is beyond the maximum supported; spare_9: capture engaged used for debug;" },
		{  .name="spare_2", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_FATAL, .desc="spare_0 .. spare_7: Hardware Error; spare_8: err_phv_above_max: P4 program/compiler error. Packet need to get information form a PHV that is beyond the maximum supported; spare_9: capture engaged used for debug;" },
		{  .name="spare_3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_FATAL, .desc="spare_0 .. spare_7: Hardware Error; spare_8: err_phv_above_max: P4 program/compiler error. Packet need to get information form a PHV that is beyond the maximum supported; spare_9: capture engaged used for debug;" },
		{  .name="spare_4", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_FATAL, .desc="spare_0 .. spare_7: Hardware Error; spare_8: err_phv_above_max: P4 program/compiler error. Packet need to get information form a PHV that is beyond the maximum supported; spare_9: capture engaged used for debug;" },
		{  .name="spare_5", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_FATAL, .desc="spare_0 .. spare_7: Hardware Error; spare_8: err_phv_above_max: P4 program/compiler error. Packet need to get information form a PHV that is beyond the maximum supported; spare_9: capture engaged used for debug;" },
		{  .name="spare_6", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_FATAL, .desc="spare_0 .. spare_7: Hardware Error; spare_8: err_phv_above_max: P4 program/compiler error. Packet need to get information form a PHV that is beyond the maximum supported; spare_9: capture engaged used for debug;" },
		{  .name="spare_7", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_FATAL, .desc="spare_0 .. spare_7: Hardware Error; spare_8: err_phv_above_max: P4 program/compiler error. Packet need to get information form a PHV that is beyond the maximum supported; spare_9: capture engaged used for debug;" },
		{  .name="spare_8", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_FATAL, .desc="spare_0 .. spare_7: Hardware Error; spare_8: err_phv_above_max: P4 program/compiler error. Packet need to get information form a PHV that is beyond the maximum supported; spare_9: capture engaged used for debug;" },
		{  .name="spare_9", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_FATAL, .desc="spare_0 .. spare_7: Hardware Error; spare_8: err_phv_above_max: P4 program/compiler error. Packet need to get information form a PHV that is beyond the maximum supported; spare_9: capture engaged used for debug;" },
		{  .name="spare_10", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_FATAL, .desc="spare_0 .. spare_7: Hardware Error; spare_8: err_phv_above_max: P4 program/compiler error. Packet need to get information form a PHV that is beyond the maximum supported; spare_9: capture engaged used for debug;" },
		{  .name="spare_11", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_FATAL, .desc="spare_0 .. spare_7: Hardware Error; spare_8: err_phv_above_max: P4 program/compiler error. Packet need to get information form a PHV that is beyond the maximum supported; spare_9: capture engaged used for debug;" },
		{  .name="spare_12", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_FATAL, .desc="spare_0 .. spare_7: Hardware Error; spare_8: err_phv_above_max: P4 program/compiler error. Packet need to get information form a PHV that is beyond the maximum supported; spare_9: capture engaged used for debug;" },
		{  .name="spare_13", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_FATAL, .desc="spare_0 .. spare_7: Hardware Error; spare_8: err_phv_above_max: P4 program/compiler error. Packet need to get information form a PHV that is beyond the maximum supported; spare_9: capture engaged used for debug;" },
		{  .name="spare_14", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_FATAL, .desc="spare_0 .. spare_7: Hardware Error; spare_8: err_phv_above_max: P4 program/compiler error. Packet need to get information form a PHV that is beyond the maximum supported; spare_9: capture engaged used for debug;" },
		{  .name="spare_15", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_FATAL, .desc="spare_0 .. spare_7: Hardware Error; spare_8: err_phv_above_max: P4 program/compiler error. Packet need to get information form a PHV that is beyond the maximum supported; spare_9: capture engaged used for debug;" },
		{  .name="spare_16", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_FATAL, .desc="spare_0 .. spare_7: Hardware Error; spare_8: err_phv_above_max: P4 program/compiler error. Packet need to get information form a PHV that is beyond the maximum supported; spare_9: capture engaged used for debug;" },
		{  .name="spare_17", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_FATAL, .desc="spare_0 .. spare_7: Hardware Error; spare_8: err_phv_above_max: P4 program/compiler error. Packet need to get information form a PHV that is beyond the maximum supported; spare_9: capture engaged used for debug;" },
		{  .name="spare_18", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_FATAL, .desc="spare_0 .. spare_7: Hardware Error; spare_8: err_phv_above_max: P4 program/compiler error. Packet need to get information form a PHV that is beyond the maximum supported; spare_9: capture engaged used for debug;" },
		{  .name="spare_19", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_FATAL, .desc="spare_0 .. spare_7: Hardware Error; spare_8: err_phv_above_max: P4 program/compiler error. Packet need to get information form a PHV that is beyond the maximum supported; spare_9: capture engaged used for debug;" },
		{  .name="spare_20", .next_ptr=nullptr, .id=22, .severity=INTR_SEV_TYPE_FATAL, .desc="spare_0 .. spare_7: Hardware Error; spare_8: err_phv_above_max: P4 program/compiler error. Packet need to get information form a PHV that is beyond the maximum supported; spare_9: capture engaged used for debug;" },
		{  .name="spare_21", .next_ptr=nullptr, .id=23, .severity=INTR_SEV_TYPE_FATAL, .desc="spare_0 .. spare_7: Hardware Error; spare_8: err_phv_above_max: P4 program/compiler error. Packet need to get information form a PHV that is beyond the maximum supported; spare_9: capture engaged used for debug;" },
		{  .name="spare_22", .next_ptr=nullptr, .id=24, .severity=INTR_SEV_TYPE_FATAL, .desc="spare_0 .. spare_7: Hardware Error; spare_8: err_phv_above_max: P4 program/compiler error. Packet need to get information form a PHV that is beyond the maximum supported; spare_9: capture engaged used for debug;" },
		{  .name="spare_23", .next_ptr=nullptr, .id=25, .severity=INTR_SEV_TYPE_FATAL, .desc="spare_0 .. spare_7: Hardware Error; spare_8: err_phv_above_max: P4 program/compiler error. Packet need to get information form a PHV that is beyond the maximum supported; spare_9: capture engaged used for debug;" },
		{  .name="spare_24", .next_ptr=nullptr, .id=26, .severity=INTR_SEV_TYPE_FATAL, .desc="spare_0 .. spare_7: Hardware Error; spare_8: err_phv_above_max: P4 program/compiler error. Packet need to get information form a PHV that is beyond the maximum supported; spare_9: capture engaged used for debug;" },
		{  .name="spare_25", .next_ptr=nullptr, .id=27, .severity=INTR_SEV_TYPE_FATAL, .desc="spare_0 .. spare_7: Hardware Error; spare_8: err_phv_above_max: P4 program/compiler error. Packet need to get information form a PHV that is beyond the maximum supported; spare_9: capture engaged used for debug;" },
		{  .name="spare_26", .next_ptr=nullptr, .id=28, .severity=INTR_SEV_TYPE_FATAL, .desc="spare_0 .. spare_7: Hardware Error; spare_8: err_phv_above_max: P4 program/compiler error. Packet need to get information form a PHV that is beyond the maximum supported; spare_9: capture engaged used for debug;" },
		{  .name="spare_27", .next_ptr=nullptr, .id=29, .severity=INTR_SEV_TYPE_FATAL, .desc="spare_0 .. spare_7: Hardware Error; spare_8: err_phv_above_max: P4 program/compiler error. Packet need to get information form a PHV that is beyond the maximum supported; spare_9: capture engaged used for debug;" },
		{  .name="spare_28", .next_ptr=nullptr, .id=30, .severity=INTR_SEV_TYPE_FATAL, .desc="spare_0 .. spare_7: Hardware Error; spare_8: err_phv_above_max: P4 program/compiler error. Packet need to get information form a PHV that is beyond the maximum supported; spare_9: capture engaged used for debug;" },
		{  .name="spare_29", .next_ptr=nullptr, .id=31, .severity=INTR_SEV_TYPE_FATAL, .desc="spare_0 .. spare_7: Hardware Error; spare_8: err_phv_above_max: P4 program/compiler error. Packet need to get information form a PHV that is beyond the maximum supported; spare_9: capture engaged used for debug;" },
		{  .name="spare_30", .next_ptr=nullptr, .id=32, .severity=INTR_SEV_TYPE_FATAL, .desc="spare_0 .. spare_7: Hardware Error; spare_8: err_phv_above_max: P4 program/compiler error. Packet need to get information form a PHV that is beyond the maximum supported; spare_9: capture engaged used for debug;" },
		{  .name="spare_31", .next_ptr=nullptr, .id=33, .severity=INTR_SEV_TYPE_FATAL, .desc="spare_0 .. spare_7: Hardware Error; spare_8: err_phv_above_max: P4 program/compiler error. Packet need to get information form a PHV that is beyond the maximum supported; spare_9: capture engaged used for debug;" },

	} };
intr_reg_t dpr_dpr_0_int_credit = {  .name="dpr.dpr[0].int_credit", .addr=0x3200100, .reg_type=0, .id=383, .field_count=4, .fields=
	{
		{  .name="egress_credit_ovflow", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="egress_credit_undflow", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="pktout_credit_ovflow", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="pktout_credit_undflow", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },

	} };
intr_reg_t dpr_dpr_0_int_groups_intreg = {  .name="dpr.dpr[0].int_groups.intreg", .addr=0x32000a0, .reg_type=1, .id=384, .field_count=8, .fields=
	{
		{  .name="int_reg1", .next_ptr=&dpr_dpr_0_int_reg1, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_reg2", .next_ptr=&dpr_dpr_0_int_reg2, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_srams_ecc", .next_ptr=&dpr_dpr_0_int_srams_ecc, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_fifo", .next_ptr=&dpr_dpr_0_int_fifo, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_flop_fifo_0", .next_ptr=&dpr_dpr_0_int_flop_fifo_0, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_flop_fifo_1", .next_ptr=&dpr_dpr_0_int_flop_fifo_1, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_spare", .next_ptr=&dpr_dpr_0_int_spare, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_credit", .next_ptr=&dpr_dpr_0_int_credit, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t pp_pp_port_c_0_int_c_mac = {  .name="pp.pp.port_c[0].int_c_mac", .addr=0x70111b0, .reg_type=0, .id=155, .field_count=19, .fields=
	{
		{  .name="link_dn2up", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="link_up2dn", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="sec_bus_rst", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="rst_up2dn", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="rst_dn2up", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="portgate_open2close", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="ltssm_st_changed", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="sec_busnum_changed", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="rc_pme", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="rc_aerr", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="rc_serr", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="rc_hpe", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="rc_eq_req", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="rc_dpc", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="pm_turnoff", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="txbfr_overflow", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_FATAL, .desc="Fatal error, try to reproduce in lab and debug the configuration settings using PCIE Analyzer" },
		{  .name="rxtlp_err", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="" },
		{  .name="tl_flr_req", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="rc_legacy_intpin_changed", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t pp_pp_port_c_0_int_c_ecc = {  .name="pp.pp.port_c[0].int_c_ecc", .addr=0x70111c0, .reg_type=0, .id=156, .field_count=8, .fields=
	{
		{  .name="rxbuf_0_uncorrectable", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="rxbuf_1_uncorrectable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="rxbuf_2_uncorrectable", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="rxbuf_3_uncorrectable", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="rxbuf_0_correctable", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="rxbuf_1_correctable", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="rxbuf_2_correctable", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="rxbuf_3_correctable", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },

	} };
intr_reg_t pp_pp_port_c_0_int_groups_intreg = {  .name="pp.pp.port_c[0].int_groups.intreg", .addr=0x70111a0, .reg_type=1, .id=157, .field_count=2, .fields=
	{
		{  .name="int_c_mac", .next_ptr=&pp_pp_port_c_0_int_c_mac, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_c_ecc", .next_ptr=&pp_pp_port_c_0_int_c_ecc, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t pb_pbc_hbm_int_ecc_hbm_mtu = {  .name="pb.pbc.hbm.int_ecc_hbm_mtu", .addr=0x140d600, .reg_type=0, .id=325, .field_count=2, .fields=
	{
		{  .name="uncorrectable", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_HW_RMA, .desc="Hardware Error" },
		{  .name="correctable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },

	} };
intr_reg_t pb_pbc_hbm_int_ecc_hbm_rb = {  .name="pb.pbc.hbm.int_ecc_hbm_rb", .addr=0x140d640, .reg_type=0, .id=326, .field_count=4, .fields=
	{
		{  .name="rb_uncorrectable", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_HW_RMA, .desc="Hardware Error" },
		{  .name="rb_correctable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="cdt_uncorrectable", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_HW_RMA, .desc="Hardware Error" },
		{  .name="cdt_correctable", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },

	} };
intr_reg_t pb_pbc_hbm_int_ecc_hbm_wb = {  .name="pb.pbc.hbm.int_ecc_hbm_wb", .addr=0x140dc00, .reg_type=0, .id=327, .field_count=2, .fields=
	{
		{  .name="uncorrectable", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_HW_RMA, .desc="Hardware Error" },
		{  .name="correctable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },

	} };
intr_reg_t pb_pbc_hbm_int_ecc_hbm_ht = {  .name="pb.pbc.hbm.int_ecc_hbm_ht", .addr=0x140e350, .reg_type=0, .id=328, .field_count=2, .fields=
	{
		{  .name="uncorrectable", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_HW_RMA, .desc="Hardware Error" },
		{  .name="correctable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },

	} };
intr_reg_t pb_pbc_hbm_int_hbm_xoff = {  .name="pb.pbc.hbm.int_hbm_xoff", .addr=0x140e360, .reg_type=0, .id=329, .field_count=32, .fields=
	{
		{  .name="timeout_0", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="timeout_1", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="timeout_2", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="timeout_3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="timeout_4", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="timeout_5", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="timeout_6", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="timeout_7", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="timeout_8", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="timeout_9", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="timeout_10", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="timeout_11", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="timeout_12", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="timeout_13", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="timeout_14", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="timeout_15", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="timeout_16", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="timeout_17", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="timeout_18", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="timeout_19", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="timeout_20", .next_ptr=nullptr, .id=22, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="timeout_21", .next_ptr=nullptr, .id=23, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="timeout_22", .next_ptr=nullptr, .id=24, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="timeout_23", .next_ptr=nullptr, .id=25, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="timeout_24", .next_ptr=nullptr, .id=26, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="timeout_25", .next_ptr=nullptr, .id=27, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="timeout_26", .next_ptr=nullptr, .id=28, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="timeout_27", .next_ptr=nullptr, .id=29, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="timeout_28", .next_ptr=nullptr, .id=30, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="timeout_29", .next_ptr=nullptr, .id=31, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="timeout_30", .next_ptr=nullptr, .id=32, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="timeout_31", .next_ptr=nullptr, .id=33, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t pb_pbc_hbm_int_hbm_pbus_violation_in = {  .name="pb.pbc.hbm.int_hbm_pbus_violation_in", .addr=0x140e370, .reg_type=0, .id=330, .field_count=20, .fields=
	{
		{  .name="sop_sop_in_0", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="sop_sop_in_1", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="sop_sop_in_2", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="sop_sop_in_3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="sop_sop_in_4", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="sop_sop_in_5", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="sop_sop_in_6", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="sop_sop_in_7", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="sop_sop_in_8", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="sop_sop_in_9", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="eop_eop_in_0", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="eop_eop_in_1", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="eop_eop_in_2", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="eop_eop_in_3", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="eop_eop_in_4", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="eop_eop_in_5", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="eop_eop_in_6", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="eop_eop_in_7", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="eop_eop_in_8", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="eop_eop_in_9", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },

	} };
intr_reg_t pb_pbc_hbm_int_hbm_pbus_violation_out = {  .name="pb.pbc.hbm.int_hbm_pbus_violation_out", .addr=0x140e380, .reg_type=0, .id=331, .field_count=20, .fields=
	{
		{  .name="sop_sop_out_0", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="sop_sop_out_1", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="sop_sop_out_2", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="sop_sop_out_3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="sop_sop_out_4", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="sop_sop_out_5", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="sop_sop_out_6", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="sop_sop_out_7", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="sop_sop_out_8", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="sop_sop_out_9", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="eop_eop_out_0", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="eop_eop_out_1", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="eop_eop_out_2", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="eop_eop_out_3", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="eop_eop_out_4", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="eop_eop_out_5", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="eop_eop_out_6", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="eop_eop_out_7", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="eop_eop_out_8", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="eop_eop_out_9", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },

	} };
intr_reg_t pb_pbc_hbm_int_hbm_drop = {  .name="pb.pbc.hbm.int_hbm_drop", .addr=0x140e390, .reg_type=0, .id=332, .field_count=9, .fields=
	{
		{  .name="occupancy_0", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="occupancy_1", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="occupancy_2", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="occupancy_3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="occupancy_4", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="occupancy_5", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="occupancy_6", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="occupancy_7", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="occupancy_8", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t pb_pbc_hbm_int_hbm_stop = {  .name="pb.pbc.hbm.int_hbm_stop", .addr=0x140e550, .reg_type=0, .id=333, .field_count=1, .fields=
	{
		{  .name="occupancy_9", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t pb_pbc_hbm_int_hbm_axi_err_rsp = {  .name="pb.pbc.hbm.int_hbm_axi_err_rsp", .addr=0x140e3a0, .reg_type=0, .id=334, .field_count=3, .fields=
	{
		{  .name="ctrl", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="pyld", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="r2a", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },

	} };
intr_reg_t pb_pbc_hbm_int_hbm_drop_emergency = {  .name="pb.pbc.hbm.int_hbm_drop_emergency", .addr=0x140e4a0, .reg_type=0, .id=335, .field_count=9, .fields=
	{
		{  .name="stop_0", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="stop_1", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="stop_2", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="stop_3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="stop_4", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="stop_5", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="stop_6", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="stop_7", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="stop_8", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t pb_pbc_hbm_int_hbm_drop_write_ack = {  .name="pb.pbc.hbm.int_hbm_drop_write_ack", .addr=0x140e4b0, .reg_type=0, .id=336, .field_count=18, .fields=
	{
		{  .name="filling_up_0", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="filling_up_1", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="filling_up_2", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="filling_up_3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="filling_up_4", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="filling_up_5", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="filling_up_6", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="filling_up_7", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="filling_up_8", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="full_0", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="full_1", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="full_2", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="full_3", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="full_4", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="full_5", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="full_6", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="full_7", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="full_8", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t pb_pbc_hbm_int_hbm_drop_ctrl = {  .name="pb.pbc.hbm.int_hbm_drop_ctrl", .addr=0x140e4c0, .reg_type=0, .id=337, .field_count=9, .fields=
	{
		{  .name="full_0", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="full_1", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="full_2", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="full_3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="full_4", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="full_5", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="full_6", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="full_7", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="full_8", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t pb_pbc_hbm_int_hbm_drop_threshold = {  .name="pb.pbc.hbm.int_hbm_drop_threshold", .addr=0x140e4d0, .reg_type=0, .id=338, .field_count=9, .fields=
	{
		{  .name="crossed_0", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="crossed_1", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="crossed_2", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="crossed_3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="crossed_4", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="crossed_5", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="crossed_6", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="crossed_7", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="crossed_8", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t pb_pbc_hbm_int_hbm_truncate_no = {  .name="pb.pbc.hbm.int_hbm_truncate_no", .addr=0x140e530, .reg_type=0, .id=339, .field_count=9, .fields=
	{
		{  .name="drop_0", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="drop_1", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="drop_2", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="drop_3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="drop_4", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="drop_5", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="drop_6", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="drop_7", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="drop_8", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t pb_pbc_hbm_int_groups_intreg = {  .name="pb.pbc.hbm.int_groups.intreg", .addr=0x140c010, .reg_type=1, .id=340, .field_count=15, .fields=
	{
		{  .name="int_ecc_hbm_mtu", .next_ptr=&pb_pbc_hbm_int_ecc_hbm_mtu, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_ecc_hbm_rb", .next_ptr=&pb_pbc_hbm_int_ecc_hbm_rb, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_ecc_hbm_wb", .next_ptr=&pb_pbc_hbm_int_ecc_hbm_wb, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_ecc_hbm_ht", .next_ptr=&pb_pbc_hbm_int_ecc_hbm_ht, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_hbm_xoff", .next_ptr=&pb_pbc_hbm_int_hbm_xoff, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_hbm_pbus_violation_in", .next_ptr=&pb_pbc_hbm_int_hbm_pbus_violation_in, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_hbm_pbus_violation_out", .next_ptr=&pb_pbc_hbm_int_hbm_pbus_violation_out, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_hbm_drop", .next_ptr=&pb_pbc_hbm_int_hbm_drop, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_hbm_stop", .next_ptr=&pb_pbc_hbm_int_hbm_stop, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_hbm_axi_err_rsp", .next_ptr=&pb_pbc_hbm_int_hbm_axi_err_rsp, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_hbm_drop_emergency", .next_ptr=&pb_pbc_hbm_int_hbm_drop_emergency, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_hbm_drop_write_ack", .next_ptr=&pb_pbc_hbm_int_hbm_drop_write_ack, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_hbm_drop_ctrl", .next_ptr=&pb_pbc_hbm_int_hbm_drop_ctrl, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_hbm_drop_threshold", .next_ptr=&pb_pbc_hbm_int_hbm_drop_threshold, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_hbm_truncate_no", .next_ptr=&pb_pbc_hbm_int_hbm_truncate_no, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t pcr_mpu_0_int_err = {  .name="pcr.mpu[0].int_err", .addr=0x6448630, .reg_type=0, .id=217, .field_count=27, .fields=
	{
		{  .name="results_mismatch", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="mask this interrupt, not fully implemented" },
		{  .name="sdp_mem_uncorrectable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="sdp_mem_correctable", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="illegal_op_0", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_1", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_2", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_3", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="max_inst_0", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_1", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_2", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_3", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="phvwr_0", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_1", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_2", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_3", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="write_err_0", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_1", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_2", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_3", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="cache_axi_0", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_1", .next_ptr=nullptr, .id=22, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_2", .next_ptr=nullptr, .id=23, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_3", .next_ptr=nullptr, .id=24, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_parity_0", .next_ptr=nullptr, .id=25, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_1", .next_ptr=nullptr, .id=26, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_2", .next_ptr=nullptr, .id=27, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_3", .next_ptr=nullptr, .id=28, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },

	} };
intr_reg_t pcr_mpu_0_int_info = {  .name="pcr.mpu[0].int_info", .addr=0x6448640, .reg_type=0, .id=218, .field_count=8, .fields=
	{
		{  .name="trace_full_0", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_1", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_2", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="mpu_stop_0", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_1", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_2", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_3", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },

	} };
intr_reg_t pcr_mpu_0_int_groups_intreg = {  .name="pcr.mpu[0].int_groups.intreg", .addr=0x6448620, .reg_type=1, .id=219, .field_count=2, .fields=
	{
		{  .name="int_err", .next_ptr=&pcr_mpu_0_int_err, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_info", .next_ptr=&pcr_mpu_0_int_info, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t pct_mpu_0_int_err = {  .name="pct.mpu[0].int_err", .addr=0x64c8630, .reg_type=0, .id=269, .field_count=27, .fields=
	{
		{  .name="results_mismatch", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="mask this interrupt, not fully implemented" },
		{  .name="sdp_mem_uncorrectable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="sdp_mem_correctable", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="illegal_op_0", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_1", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_2", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_3", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="max_inst_0", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_1", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_2", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_3", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="phvwr_0", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_1", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_2", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_3", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="write_err_0", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_1", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_2", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_3", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="cache_axi_0", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_1", .next_ptr=nullptr, .id=22, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_2", .next_ptr=nullptr, .id=23, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_3", .next_ptr=nullptr, .id=24, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_parity_0", .next_ptr=nullptr, .id=25, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_1", .next_ptr=nullptr, .id=26, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_2", .next_ptr=nullptr, .id=27, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_3", .next_ptr=nullptr, .id=28, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },

	} };
intr_reg_t pct_mpu_0_int_info = {  .name="pct.mpu[0].int_info", .addr=0x64c8640, .reg_type=0, .id=270, .field_count=8, .fields=
	{
		{  .name="trace_full_0", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_1", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_2", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="mpu_stop_0", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_1", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_2", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_3", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },

	} };
intr_reg_t pct_mpu_0_int_groups_intreg = {  .name="pct.mpu[0].int_groups.intreg", .addr=0x64c8620, .reg_type=1, .id=271, .field_count=2, .fields=
	{
		{  .name="int_err", .next_ptr=&pct_mpu_0_int_err, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_info", .next_ptr=&pct_mpu_0_int_info, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t pct_mpu_4_int_err = {  .name="pct.mpu[4].int_err", .addr=0x6508630, .reg_type=0, .id=281, .field_count=27, .fields=
	{
		{  .name="results_mismatch", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="mask this interrupt, not fully implemented" },
		{  .name="sdp_mem_uncorrectable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="sdp_mem_correctable", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="illegal_op_0", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_1", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_2", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_3", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="max_inst_0", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_1", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_2", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_3", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="phvwr_0", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_1", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_2", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_3", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="write_err_0", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_1", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_2", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_3", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="cache_axi_0", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_1", .next_ptr=nullptr, .id=22, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_2", .next_ptr=nullptr, .id=23, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_3", .next_ptr=nullptr, .id=24, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_parity_0", .next_ptr=nullptr, .id=25, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_1", .next_ptr=nullptr, .id=26, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_2", .next_ptr=nullptr, .id=27, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_3", .next_ptr=nullptr, .id=28, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },

	} };
intr_reg_t pct_mpu_4_int_info = {  .name="pct.mpu[4].int_info", .addr=0x6508640, .reg_type=0, .id=282, .field_count=8, .fields=
	{
		{  .name="trace_full_0", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_1", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_2", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="mpu_stop_0", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_1", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_2", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_3", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },

	} };
intr_reg_t pct_mpu_4_int_groups_intreg = {  .name="pct.mpu[4].int_groups.intreg", .addr=0x6508620, .reg_type=1, .id=283, .field_count=2, .fields=
	{
		{  .name="int_err", .next_ptr=&pct_mpu_4_int_err, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_info", .next_ptr=&pct_mpu_4_int_info, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t tpc_pics_picc_int_picc = {  .name="tpc.pics.picc.int_picc", .addr=0x45a0020, .reg_type=0, .id=374, .field_count=7, .fields=
	{
		{  .name="uncorrectable_ecc", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="correctable_ecc", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="cache_stg_awlen_err", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_FATAL, .desc="HBM access fatal error" },
		{  .name="cache_hbm_rresp_slverr", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_FATAL, .desc="HBM access fatal error" },
		{  .name="cache_hbm_rresp_decerr", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_FATAL, .desc="HBM access fatal error" },
		{  .name="cache_hbm_bresp_slverr", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_FATAL, .desc="HBM access fatal error" },
		{  .name="cache_hbm_bresp_decerr", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_FATAL, .desc="HBM access fatal error" },

	} };
intr_reg_t tpc_pics_picc_int_groups_intreg = {  .name="tpc.pics.picc.int_groups.intreg", .addr=0x45a0010, .reg_type=1, .id=375, .field_count=1, .fields=
	{
		{  .name="int_picc", .next_ptr=&tpc_pics_picc_int_picc, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t mc_mc_4_mch_int_mc = {  .name="mc.mc[4].mch.int_mc", .addr=0x6a500060, .reg_type=0, .id=412, .field_count=2, .fields=
	{
		{  .name="ecc_1bit_thresh_ps1", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_ERR, .desc="" },
		{  .name="ecc_1bit_thresh_ps0", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="" },

	} };
intr_reg_t mc_mc_4_mch_int_groups_intreg = {  .name="mc.mc[4].mch.int_groups.intreg", .addr=0x6a500050, .reg_type=1, .id=413, .field_count=1, .fields=
	{
		{  .name="int_mc", .next_ptr=&mc_mc_4_mch_int_mc, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t pcr_te_3_int_err = {  .name="pcr.te[3].int_err", .addr=0x62a2440, .reg_type=0, .id=202, .field_count=20, .fields=
	{
		{  .name="miss_sop", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="previous stage error" },
		{  .name="miss_eop", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="previous stage error" },
		{  .name="phv_max_size", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="invalid" },
		{  .name="spurious_axi_rsp", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="spurious_tcam_rsp", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_FATAL, .desc="bad tcam response" },
		{  .name="te2mpu_timeout", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="impossible, should be disabled" },
		{  .name="axi_rdrsp_err", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="axi_bad_read", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="tcam_req_idx_fifo", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="tcam_rsp_idx_fifo", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="mpu_req_idx_fifo", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="axi_req_idx_fifo", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="proc_tbl_vld_wo_proc", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend_wo_wb", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend1_wo_pend0", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="both_pend_down", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend_wo_proc_down", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="both_pend_went_up", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="loaded_but_no_proc", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="loaded_but_no_proc_tbl_vld", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },

	} };
intr_reg_t pcr_te_3_int_info = {  .name="pcr.te[3].int_info", .addr=0x62a2450, .reg_type=0, .id=203, .field_count=17, .fields=
	{
		{  .name="profile_cam_hit0", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit1", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit2", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit4", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit5", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit6", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit7", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit8", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit9", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit10", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit11", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit12", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit13", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit14", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit15", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_miss", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t pcr_te_3_int_groups_intreg = {  .name="pcr.te[3].int_groups.intreg", .addr=0x62a2430, .reg_type=1, .id=204, .field_count=2, .fields=
	{
		{  .name="int_err", .next_ptr=&pcr_te_3_int_err, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_info", .next_ptr=&pcr_te_3_int_info, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t sgi_te_2_int_err = {  .name="sgi.te[2].int_err", .addr=0x3602440, .reg_type=0, .id=45, .field_count=20, .fields=
	{
		{  .name="miss_sop", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="previous stage error" },
		{  .name="miss_eop", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="previous stage error" },
		{  .name="phv_max_size", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="invalid" },
		{  .name="spurious_axi_rsp", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="spurious_tcam_rsp", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_FATAL, .desc="bad tcam response" },
		{  .name="te2mpu_timeout", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="impossible, should be disabled" },
		{  .name="axi_rdrsp_err", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="axi_bad_read", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="tcam_req_idx_fifo", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="tcam_rsp_idx_fifo", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="mpu_req_idx_fifo", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="axi_req_idx_fifo", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="proc_tbl_vld_wo_proc", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend_wo_wb", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend1_wo_pend0", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="both_pend_down", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend_wo_proc_down", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="both_pend_went_up", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="loaded_but_no_proc", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="loaded_but_no_proc_tbl_vld", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },

	} };
intr_reg_t sgi_te_2_int_info = {  .name="sgi.te[2].int_info", .addr=0x3602450, .reg_type=0, .id=46, .field_count=17, .fields=
	{
		{  .name="profile_cam_hit0", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit1", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit2", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit4", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit5", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit6", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit7", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit8", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit9", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit10", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit11", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit12", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit13", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit14", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit15", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_miss", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t sgi_te_2_int_groups_intreg = {  .name="sgi.te[2].int_groups.intreg", .addr=0x3602430, .reg_type=1, .id=47, .field_count=2, .fields=
	{
		{  .name="int_err", .next_ptr=&sgi_te_2_int_err, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_info", .next_ptr=&sgi_te_2_int_info, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t pct_mpu_7_int_err = {  .name="pct.mpu[7].int_err", .addr=0x6538630, .reg_type=0, .id=290, .field_count=27, .fields=
	{
		{  .name="results_mismatch", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="mask this interrupt, not fully implemented" },
		{  .name="sdp_mem_uncorrectable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="sdp_mem_correctable", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="illegal_op_0", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_1", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_2", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_3", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="max_inst_0", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_1", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_2", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_3", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="phvwr_0", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_1", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_2", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_3", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="write_err_0", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_1", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_2", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_3", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="cache_axi_0", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_1", .next_ptr=nullptr, .id=22, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_2", .next_ptr=nullptr, .id=23, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_3", .next_ptr=nullptr, .id=24, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_parity_0", .next_ptr=nullptr, .id=25, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_1", .next_ptr=nullptr, .id=26, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_2", .next_ptr=nullptr, .id=27, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_3", .next_ptr=nullptr, .id=28, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },

	} };
intr_reg_t pct_mpu_7_int_info = {  .name="pct.mpu[7].int_info", .addr=0x6538640, .reg_type=0, .id=291, .field_count=8, .fields=
	{
		{  .name="trace_full_0", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_1", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_2", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="mpu_stop_0", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_1", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_2", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_3", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },

	} };
intr_reg_t pct_mpu_7_int_groups_intreg = {  .name="pct.mpu[7].int_groups.intreg", .addr=0x6538620, .reg_type=1, .id=292, .field_count=2, .fields=
	{
		{  .name="int_err", .next_ptr=&pct_mpu_7_int_err, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_info", .next_ptr=&pct_mpu_7_int_info, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t txs_txs_int_sch = {  .name="txs.txs.int_sch", .addr=0x200c0060, .reg_type=0, .id=241, .field_count=26, .fields=
	{
		{  .name="sch_wid_empty", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="sch_rid_empty", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="" },
		{  .name="sch_wr_txfifo_ovf", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_FATAL, .desc="" },
		{  .name="sch_rd_txfifo_ovf", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_FATAL, .desc="" },
		{  .name="sch_state_fifo_ovf", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_FATAL, .desc="" },
		{  .name="sch_drb_cnt_qid_fifo", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="Not applicable, it was left there in the reg defintion but is not used internally" },
		{  .name="sch_hbm_byp_ovf", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_FATAL, .desc="" },
		{  .name="sch_hbm_byp_wtag_wrap", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_FATAL, .desc="" },
		{  .name="sch_rlid_ovfl", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_ERR, .desc="rlid programming error" },
		{  .name="sch_rlid_unfl", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="rlid programming error" },
		{  .name="sch_null_lif", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_ERR, .desc="lif map programming error" },
		{  .name="sch_lif_sg_mismatch", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="shouldn't happen, need debugging if happens" },
		{  .name="sch_aclr_hbm_ln_rollovr", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_FATAL, .desc="" },
		{  .name="sch_txdma_msg_efull", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="sch_hbm_re_efull", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="sch_hbm_we_efull", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="sch_hbm_byp_pending_efull", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="sch_hbm_rd_pending_efull", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="sch_hbm_wr_pending_efull", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="sch_bresp_err", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="sch_bid_err", .next_ptr=nullptr, .id=22, .severity=INTR_SEV_TYPE_ERR, .desc="axi error" },
		{  .name="sch_rresp_err", .next_ptr=nullptr, .id=23, .severity=INTR_SEV_TYPE_ERR, .desc="" },
		{  .name="sch_rid_err", .next_ptr=nullptr, .id=24, .severity=INTR_SEV_TYPE_ERR, .desc="axi error" },
		{  .name="sch_drb_cnt_ovfl", .next_ptr=nullptr, .id=25, .severity=INTR_SEV_TYPE_ERR, .desc="need to read clear drb counter in memory to avoid ovfl" },
		{  .name="sch_drb_cnt_unfl", .next_ptr=nullptr, .id=26, .severity=INTR_SEV_TYPE_FATAL, .desc="" },
		{  .name="sch_txdma_msg_ovfl", .next_ptr=nullptr, .id=27, .severity=INTR_SEV_TYPE_FATAL, .desc="" },

	} };
intr_reg_t txs_txs_int_tmr = {  .name="txs.txs.int_tmr", .addr=0x200c0070, .reg_type=0, .id=242, .field_count=32, .fields=
	{
		{  .name="tmr_wid_empty", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="tmr_rid_empty", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="" },
		{  .name="tmr_wr_txfifo_ovf", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_FATAL, .desc="" },
		{  .name="tmr_rd_txfifo_ovf", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_FATAL, .desc="" },
		{  .name="tmr_state_fifo_ovf", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_FATAL, .desc="" },
		{  .name="tmr_hbm_byp_ovf", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_FATAL, .desc="" },
		{  .name="tmr_hbm_byp_wtag_wrap", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_FATAL, .desc="" },
		{  .name="ftmr_ctime_wrap", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="" },
		{  .name="stmr_ctime_wrap", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_ERR, .desc="" },
		{  .name="stmr_push_out_of_wheel", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="ftmr_push_out_of_wheel", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="ftmr_key_not_push", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="ftmr_key_not_found", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="stmr_key_not_push", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="stmr_key_not_found", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="stmr_stall", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="ftmr_stall", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="ftmr_fifo_ovf", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_FATAL, .desc="" },
		{  .name="stmr_fifo_ovf", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_FATAL, .desc="" },
		{  .name="ftmr_fifo_efull", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="stmr_fifo_efull", .next_ptr=nullptr, .id=22, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="tmr_rejct_drb_ovf", .next_ptr=nullptr, .id=23, .severity=INTR_SEV_TYPE_FATAL, .desc="" },
		{  .name="tmr_rejct_drb_efull", .next_ptr=nullptr, .id=24, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="tmr_hbm_re_efull", .next_ptr=nullptr, .id=25, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="tmr_hbm_we_efull", .next_ptr=nullptr, .id=26, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="tmr_hbm_byp_pending_efull", .next_ptr=nullptr, .id=27, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="tmr_hbm_rd_pending_efull", .next_ptr=nullptr, .id=28, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="tmr_hbm_wr_pending_efull", .next_ptr=nullptr, .id=29, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="tmr_bresp_err", .next_ptr=nullptr, .id=30, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="tmr_bid_err", .next_ptr=nullptr, .id=31, .severity=INTR_SEV_TYPE_ERR, .desc="" },
		{  .name="tmr_rresp_err", .next_ptr=nullptr, .id=32, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="tmr_rid_err", .next_ptr=nullptr, .id=33, .severity=INTR_SEV_TYPE_ERR, .desc="" },

	} };
intr_reg_t txs_txs_int_srams_ecc = {  .name="txs.txs.int_srams_ecc", .addr=0x200c0030, .reg_type=0, .id=243, .field_count=8, .fields=
	{
		{  .name="tmr_cnt_uncorrectable", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="tmr_cnt_correctable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="sch_lif_map_uncorrectable", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="sch_lif_map_correctable", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="sch_rlid_map_uncorrectable", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="sch_rlid_map_correctable", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="sch_grp_uncorrectable", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="sch_grp_correctable", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },

	} };
intr_reg_t txs_txs_int_groups_intreg = {  .name="txs.txs.int_groups.intreg", .addr=0x200c0050, .reg_type=1, .id=244, .field_count=3, .fields=
	{
		{  .name="int_sch", .next_ptr=&txs_txs_int_sch, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_tmr", .next_ptr=&txs_txs_int_tmr, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_srams_ecc", .next_ptr=&txs_txs_int_srams_ecc, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t sgi_te_0_int_err = {  .name="sgi.te[0].int_err", .addr=0x35c2440, .reg_type=0, .id=39, .field_count=20, .fields=
	{
		{  .name="miss_sop", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="previous stage error" },
		{  .name="miss_eop", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="previous stage error" },
		{  .name="phv_max_size", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="invalid" },
		{  .name="spurious_axi_rsp", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="spurious_tcam_rsp", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_FATAL, .desc="bad tcam response" },
		{  .name="te2mpu_timeout", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="impossible, should be disabled" },
		{  .name="axi_rdrsp_err", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="axi_bad_read", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="tcam_req_idx_fifo", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="tcam_rsp_idx_fifo", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="mpu_req_idx_fifo", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="axi_req_idx_fifo", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="proc_tbl_vld_wo_proc", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend_wo_wb", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend1_wo_pend0", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="both_pend_down", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend_wo_proc_down", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="both_pend_went_up", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="loaded_but_no_proc", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="loaded_but_no_proc_tbl_vld", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },

	} };
intr_reg_t sgi_te_0_int_info = {  .name="sgi.te[0].int_info", .addr=0x35c2450, .reg_type=0, .id=40, .field_count=17, .fields=
	{
		{  .name="profile_cam_hit0", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit1", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit2", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit4", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit5", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit6", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit7", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit8", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit9", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit10", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit11", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit12", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit13", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit14", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit15", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_miss", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t sgi_te_0_int_groups_intreg = {  .name="sgi.te[0].int_groups.intreg", .addr=0x35c2430, .reg_type=1, .id=41, .field_count=2, .fields=
	{
		{  .name="int_err", .next_ptr=&sgi_te_0_int_err, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_info", .next_ptr=&sgi_te_0_int_info, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t pct_mpu_3_int_err = {  .name="pct.mpu[3].int_err", .addr=0x64f8630, .reg_type=0, .id=278, .field_count=27, .fields=
	{
		{  .name="results_mismatch", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="mask this interrupt, not fully implemented" },
		{  .name="sdp_mem_uncorrectable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="sdp_mem_correctable", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="illegal_op_0", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_1", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_2", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_3", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="max_inst_0", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_1", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_2", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_3", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="phvwr_0", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_1", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_2", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_3", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="write_err_0", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_1", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_2", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_3", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="cache_axi_0", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_1", .next_ptr=nullptr, .id=22, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_2", .next_ptr=nullptr, .id=23, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_3", .next_ptr=nullptr, .id=24, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_parity_0", .next_ptr=nullptr, .id=25, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_1", .next_ptr=nullptr, .id=26, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_2", .next_ptr=nullptr, .id=27, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_3", .next_ptr=nullptr, .id=28, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },

	} };
intr_reg_t pct_mpu_3_int_info = {  .name="pct.mpu[3].int_info", .addr=0x64f8640, .reg_type=0, .id=279, .field_count=8, .fields=
	{
		{  .name="trace_full_0", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_1", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_2", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="mpu_stop_0", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_1", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_2", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_3", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },

	} };
intr_reg_t pct_mpu_3_int_groups_intreg = {  .name="pct.mpu[3].int_groups.intreg", .addr=0x64f8620, .reg_type=1, .id=280, .field_count=2, .fields=
	{
		{  .name="int_err", .next_ptr=&pct_mpu_3_int_err, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_info", .next_ptr=&pct_mpu_3_int_info, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t pcr_mpu_4_int_err = {  .name="pcr.mpu[4].int_err", .addr=0x6488630, .reg_type=0, .id=229, .field_count=27, .fields=
	{
		{  .name="results_mismatch", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="mask this interrupt, not fully implemented" },
		{  .name="sdp_mem_uncorrectable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="sdp_mem_correctable", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="illegal_op_0", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_1", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_2", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_3", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="max_inst_0", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_1", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_2", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_3", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="phvwr_0", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_1", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_2", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_3", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="write_err_0", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_1", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_2", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_3", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="cache_axi_0", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_1", .next_ptr=nullptr, .id=22, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_2", .next_ptr=nullptr, .id=23, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_3", .next_ptr=nullptr, .id=24, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_parity_0", .next_ptr=nullptr, .id=25, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_1", .next_ptr=nullptr, .id=26, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_2", .next_ptr=nullptr, .id=27, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_3", .next_ptr=nullptr, .id=28, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },

	} };
intr_reg_t pcr_mpu_4_int_info = {  .name="pcr.mpu[4].int_info", .addr=0x6488640, .reg_type=0, .id=230, .field_count=8, .fields=
	{
		{  .name="trace_full_0", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_1", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_2", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="mpu_stop_0", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_1", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_2", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_3", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },

	} };
intr_reg_t pcr_mpu_4_int_groups_intreg = {  .name="pcr.mpu[4].int_groups.intreg", .addr=0x6488620, .reg_type=1, .id=231, .field_count=2, .fields=
	{
		{  .name="int_err", .next_ptr=&pcr_mpu_4_int_err, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_info", .next_ptr=&pcr_mpu_4_int_info, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t pb_pbc_int_ecc_fc_0 = {  .name="pb.pbc.int_ecc_fc_0", .addr=0x1404850, .reg_type=0, .id=293, .field_count=2, .fields=
	{
		{  .name="uncorrectable", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_HW_RMA, .desc="Hardware Error" },
		{  .name="correctable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },

	} };
intr_reg_t pb_pbc_int_ecc_ll_0 = {  .name="pb.pbc.int_ecc_ll_0", .addr=0x1404870, .reg_type=0, .id=294, .field_count=2, .fields=
	{
		{  .name="uncorrectable", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_HW_RMA, .desc="Hardware Error" },
		{  .name="correctable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },

	} };
intr_reg_t pb_pbc_int_ecc_desc_0 = {  .name="pb.pbc.int_ecc_desc_0", .addr=0x1404890, .reg_type=0, .id=295, .field_count=2, .fields=
	{
		{  .name="uncorrectable", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_HW_RMA, .desc="Hardware Error" },
		{  .name="correctable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },

	} };
intr_reg_t pb_pbc_int_ecc_fc_1 = {  .name="pb.pbc.int_ecc_fc_1", .addr=0x14048c0, .reg_type=0, .id=296, .field_count=2, .fields=
	{
		{  .name="uncorrectable", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_HW_RMA, .desc="Hardware Error" },
		{  .name="correctable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },

	} };
intr_reg_t pb_pbc_int_ecc_ll_1 = {  .name="pb.pbc.int_ecc_ll_1", .addr=0x14048e0, .reg_type=0, .id=297, .field_count=2, .fields=
	{
		{  .name="uncorrectable", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_HW_RMA, .desc="Hardware Error" },
		{  .name="correctable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },

	} };
intr_reg_t pb_pbc_int_ecc_desc_1 = {  .name="pb.pbc.int_ecc_desc_1", .addr=0x1404900, .reg_type=0, .id=298, .field_count=2, .fields=
	{
		{  .name="uncorrectable", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_HW_RMA, .desc="Hardware Error" },
		{  .name="correctable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },

	} };
intr_reg_t pb_pbc_int_write_0 = {  .name="pb.pbc.int_write_0", .addr=0x1400400, .reg_type=0, .id=299, .field_count=14, .fields=
	{
		{  .name="out_of_cells", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="out_of_credit", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="port_disabled", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="truncation", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="intrinsic_drop", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="out_of_cells1", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="enq_err", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_INFO, .desc="enqueue error" },
		{  .name="tail_drop_cpu", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="tail_drop_span", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="min_size_viol", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_INFO, .desc="packet smaller than minimum allowed" },
		{  .name="port_range", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="credit_growth_error", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_FATAL, .desc="Software Error" },
		{  .name="oq_range", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_INFO, .desc="tm_oq out of range" },
		{  .name="xoff_timeout", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t pb_pbc_int_write_1 = {  .name="pb.pbc.int_write_1", .addr=0x1400800, .reg_type=0, .id=300, .field_count=14, .fields=
	{
		{  .name="out_of_cells", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="out_of_credit", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="port_disabled", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="truncation", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="intrinsic_drop", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="out_of_cells1", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="enq_err", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_INFO, .desc="enqueue error" },
		{  .name="tail_drop_cpu", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="tail_drop_span", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="min_size_viol", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_INFO, .desc="packet smaller than minimum allowed" },
		{  .name="port_range", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="credit_growth_error", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_FATAL, .desc="Software Error" },
		{  .name="oq_range", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_INFO, .desc="tm_oq out of range" },
		{  .name="xoff_timeout", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t pb_pbc_int_write_2 = {  .name="pb.pbc.int_write_2", .addr=0x1400c00, .reg_type=0, .id=301, .field_count=14, .fields=
	{
		{  .name="out_of_cells", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="out_of_credit", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="port_disabled", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="truncation", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="intrinsic_drop", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="out_of_cells1", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="enq_err", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_INFO, .desc="enqueue error" },
		{  .name="tail_drop_cpu", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="tail_drop_span", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="min_size_viol", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_INFO, .desc="packet smaller than minimum allowed" },
		{  .name="port_range", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="credit_growth_error", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_FATAL, .desc="Software Error" },
		{  .name="oq_range", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_INFO, .desc="tm_oq out of range" },
		{  .name="xoff_timeout", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t pb_pbc_int_write_3 = {  .name="pb.pbc.int_write_3", .addr=0x1401000, .reg_type=0, .id=302, .field_count=14, .fields=
	{
		{  .name="out_of_cells", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="out_of_credit", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="port_disabled", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="truncation", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="intrinsic_drop", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="out_of_cells1", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="enq_err", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_INFO, .desc="enqueue error" },
		{  .name="tail_drop_cpu", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="tail_drop_span", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="min_size_viol", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_INFO, .desc="packet smaller than minimum allowed" },
		{  .name="port_range", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="credit_growth_error", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_FATAL, .desc="Software Error" },
		{  .name="oq_range", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_INFO, .desc="tm_oq out of range" },
		{  .name="xoff_timeout", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t pb_pbc_int_write_4 = {  .name="pb.pbc.int_write_4", .addr=0x1401400, .reg_type=0, .id=303, .field_count=14, .fields=
	{
		{  .name="out_of_cells", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="out_of_credit", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="port_disabled", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="truncation", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="intrinsic_drop", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="out_of_cells1", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="enq_err", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_INFO, .desc="enqueue error" },
		{  .name="tail_drop_cpu", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="tail_drop_span", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="min_size_viol", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_INFO, .desc="packet smaller than minimum allowed" },
		{  .name="port_range", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="credit_growth_error", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_FATAL, .desc="Software Error" },
		{  .name="oq_range", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_INFO, .desc="tm_oq out of range" },
		{  .name="xoff_timeout", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t pb_pbc_int_write_5 = {  .name="pb.pbc.int_write_5", .addr=0x1401800, .reg_type=0, .id=304, .field_count=14, .fields=
	{
		{  .name="out_of_cells", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="out_of_credit", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="port_disabled", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="truncation", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="intrinsic_drop", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="out_of_cells1", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="enq_err", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_INFO, .desc="enqueue error" },
		{  .name="tail_drop_cpu", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="tail_drop_span", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="min_size_viol", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_INFO, .desc="packet smaller than minimum allowed" },
		{  .name="port_range", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="credit_growth_error", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_FATAL, .desc="Software Error" },
		{  .name="oq_range", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_INFO, .desc="tm_oq out of range" },
		{  .name="xoff_timeout", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t pb_pbc_int_write_6 = {  .name="pb.pbc.int_write_6", .addr=0x1401c00, .reg_type=0, .id=305, .field_count=14, .fields=
	{
		{  .name="out_of_cells", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="out_of_credit", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="port_disabled", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="truncation", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="intrinsic_drop", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="out_of_cells1", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="enq_err", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_INFO, .desc="enqueue error" },
		{  .name="tail_drop_cpu", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="tail_drop_span", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="min_size_viol", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_INFO, .desc="packet smaller than minimum allowed" },
		{  .name="port_range", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="credit_growth_error", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_FATAL, .desc="Software Error" },
		{  .name="oq_range", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_INFO, .desc="tm_oq out of range" },
		{  .name="xoff_timeout", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t pb_pbc_int_write_7 = {  .name="pb.pbc.int_write_7", .addr=0x1402000, .reg_type=0, .id=306, .field_count=14, .fields=
	{
		{  .name="out_of_cells", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="out_of_credit", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="port_disabled", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="truncation", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="intrinsic_drop", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="out_of_cells1", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="enq_err", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_INFO, .desc="enqueue error" },
		{  .name="tail_drop_cpu", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="tail_drop_span", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="min_size_viol", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_INFO, .desc="packet smaller than minimum allowed" },
		{  .name="port_range", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="credit_growth_error", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_FATAL, .desc="Software Error" },
		{  .name="oq_range", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_INFO, .desc="tm_oq out of range" },
		{  .name="xoff_timeout", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t pb_pbc_int_write_8 = {  .name="pb.pbc.int_write_8", .addr=0x1402400, .reg_type=0, .id=307, .field_count=14, .fields=
	{
		{  .name="out_of_cells", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="out_of_credit", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="port_disabled", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="truncation", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="intrinsic_drop", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="out_of_cells1", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="enq_err", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_INFO, .desc="enqueue error" },
		{  .name="tail_drop_cpu", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="tail_drop_span", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="min_size_viol", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_INFO, .desc="packet smaller than minimum allowed" },
		{  .name="port_range", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="credit_growth_error", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_FATAL, .desc="Software Error" },
		{  .name="oq_range", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_INFO, .desc="tm_oq out of range" },
		{  .name="xoff_timeout", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t pb_pbc_int_write_9 = {  .name="pb.pbc.int_write_9", .addr=0x1402c00, .reg_type=0, .id=308, .field_count=14, .fields=
	{
		{  .name="out_of_cells", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="out_of_credit", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="port_disabled", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="truncation", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="intrinsic_drop", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="out_of_cells1", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="enq_err", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_INFO, .desc="enqueue error" },
		{  .name="tail_drop_cpu", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="tail_drop_span", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="min_size_viol", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_INFO, .desc="packet smaller than minimum allowed" },
		{  .name="port_range", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="credit_growth_error", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_FATAL, .desc="Software Error" },
		{  .name="oq_range", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_INFO, .desc="tm_oq out of range" },
		{  .name="xoff_timeout", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t pb_pbc_int_write_10 = {  .name="pb.pbc.int_write_10", .addr=0x1403800, .reg_type=0, .id=309, .field_count=14, .fields=
	{
		{  .name="out_of_cells", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="out_of_credit", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="port_disabled", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="truncation", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="intrinsic_drop", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="out_of_cells1", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="enq_err", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_INFO, .desc="enqueue error" },
		{  .name="tail_drop_cpu", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="tail_drop_span", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="min_size_viol", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_INFO, .desc="packet smaller than minimum allowed" },
		{  .name="port_range", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="credit_growth_error", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_FATAL, .desc="Software Error" },
		{  .name="oq_range", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_INFO, .desc="tm_oq out of range" },
		{  .name="xoff_timeout", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t pb_pbc_int_write_11 = {  .name="pb.pbc.int_write_11", .addr=0x1404800, .reg_type=0, .id=310, .field_count=14, .fields=
	{
		{  .name="out_of_cells", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="out_of_credit", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="port_disabled", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="truncation", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="intrinsic_drop", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="out_of_cells1", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="enq_err", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_INFO, .desc="enqueue error" },
		{  .name="tail_drop_cpu", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="tail_drop_span", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="min_size_viol", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_INFO, .desc="packet smaller than minimum allowed" },
		{  .name="port_range", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="credit_growth_error", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_FATAL, .desc="Software Error" },
		{  .name="oq_range", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_INFO, .desc="tm_oq out of range" },
		{  .name="xoff_timeout", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t pb_pbc_int_ecc_rc = {  .name="pb.pbc.int_ecc_rc", .addr=0x1404920, .reg_type=0, .id=311, .field_count=2, .fields=
	{
		{  .name="uncorrectable", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_HW_RMA, .desc="Hardware Error" },
		{  .name="correctable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },

	} };
intr_reg_t pb_pbc_int_ecc_pack = {  .name="pb.pbc.int_ecc_pack", .addr=0x1404810, .reg_type=0, .id=312, .field_count=2, .fields=
	{
		{  .name="uncorrectable", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_HW_RMA, .desc="Hardware Error" },
		{  .name="correctable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },

	} };
intr_reg_t pb_pbc_int_ecc_rwr = {  .name="pb.pbc.int_ecc_rwr", .addr=0x1404820, .reg_type=0, .id=313, .field_count=2, .fields=
	{
		{  .name="uncorrectable", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_HW_RMA, .desc="Hardware Error" },
		{  .name="correctable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },

	} };
intr_reg_t pb_pbc_int_ecc_sched = {  .name="pb.pbc.int_ecc_sched", .addr=0x1404940, .reg_type=0, .id=314, .field_count=2, .fields=
	{
		{  .name="uncorrectable", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_HW_RMA, .desc="Hardware Error" },
		{  .name="correctable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },

	} };
intr_reg_t pb_pbc_int_ecc_sideband = {  .name="pb.pbc.int_ecc_sideband", .addr=0x1408820, .reg_type=0, .id=315, .field_count=6, .fields=
	{
		{  .name="pck_uncorrectable", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_HW_RMA, .desc="Hardware Error" },
		{  .name="pck_correctable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="rwr_uncorrectable", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_HW_RMA, .desc="Hardware Error" },
		{  .name="rwr_correctable", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="rxd_uncorrectable", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_HW_RMA, .desc="Hardware Error" },
		{  .name="rxd_correctable", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },

	} };
intr_reg_t pb_pbc_int_ecc_nc = {  .name="pb.pbc.int_ecc_nc", .addr=0x1408930, .reg_type=0, .id=316, .field_count=2, .fields=
	{
		{  .name="uncorrectable", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_HW_RMA, .desc="Hardware Error" },
		{  .name="correctable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },

	} };
intr_reg_t pb_pbc_int_ecc_uc = {  .name="pb.pbc.int_ecc_uc", .addr=0x1408960, .reg_type=0, .id=317, .field_count=2, .fields=
	{
		{  .name="uncorrectable", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_HW_RMA, .desc="Hardware Error" },
		{  .name="correctable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },

	} };
intr_reg_t pb_pbc_int_ecc_port_mon_in = {  .name="pb.pbc.int_ecc_port_mon_in", .addr=0x1408980, .reg_type=0, .id=318, .field_count=2, .fields=
	{
		{  .name="uncorrectable", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_HW_RMA, .desc=" Hardware Error" },
		{  .name="correctable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },

	} };
intr_reg_t pb_pbc_int_ecc_port_mon_out = {  .name="pb.pbc.int_ecc_port_mon_out", .addr=0x14089a0, .reg_type=0, .id=319, .field_count=2, .fields=
	{
		{  .name="uncorrectable", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_HW_RMA, .desc="Hardware Error" },
		{  .name="correctable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },

	} };
intr_reg_t pb_pbc_int_rpl = {  .name="pb.pbc.int_rpl", .addr=0x1408840, .reg_type=0, .id=320, .field_count=2, .fields=
	{
		{  .name="memory_error", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="zero_last_error", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="last node of a linked list has 0 valid entries. Not Fatal." },

	} };
intr_reg_t pb_pbc_int_credit_underflow = {  .name="pb.pbc.int_credit_underflow", .addr=0x1408a10, .reg_type=0, .id=321, .field_count=2, .fields=
	{
		{  .name="port_10", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="Software Error" },
		{  .name="port_11", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="Software Error" },

	} };
intr_reg_t pb_pbc_int_pbus_violation_in = {  .name="pb.pbc.int_pbus_violation_in", .addr=0x1408100, .reg_type=0, .id=322, .field_count=24, .fields=
	{
		{  .name="sop_sop_in_0", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="sop_sop_in_1", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="sop_sop_in_2", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="sop_sop_in_3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="sop_sop_in_4", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="sop_sop_in_5", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="sop_sop_in_6", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="sop_sop_in_7", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="sop_sop_in_8", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="sop_sop_in_9", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="sop_sop_in_10", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="sop_sop_in_11", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="eop_eop_in_0", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="eop_eop_in_1", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="eop_eop_in_2", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="eop_eop_in_3", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="eop_eop_in_4", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="eop_eop_in_5", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="eop_eop_in_6", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="eop_eop_in_7", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="eop_eop_in_8", .next_ptr=nullptr, .id=22, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="eop_eop_in_9", .next_ptr=nullptr, .id=23, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="eop_eop_in_10", .next_ptr=nullptr, .id=24, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="eop_eop_in_11", .next_ptr=nullptr, .id=25, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },

	} };
intr_reg_t pb_pbc_int_pbus_violation_out = {  .name="pb.pbc.int_pbus_violation_out", .addr=0x1408110, .reg_type=0, .id=323, .field_count=24, .fields=
	{
		{  .name="sop_sop_out_0", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="sop_sop_out_1", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="sop_sop_out_2", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="sop_sop_out_3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="sop_sop_out_4", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="sop_sop_out_5", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="sop_sop_out_6", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="sop_sop_out_7", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="sop_sop_out_8", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="sop_sop_out_9", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="sop_sop_out_10", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="sop_sop_out_11", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="eop_eop_out_0", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="eop_eop_out_1", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="eop_eop_out_2", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="eop_eop_out_3", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="eop_eop_out_4", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="eop_eop_out_5", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="eop_eop_out_6", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="eop_eop_out_7", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="eop_eop_out_8", .next_ptr=nullptr, .id=22, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="eop_eop_out_9", .next_ptr=nullptr, .id=23, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="eop_eop_out_10", .next_ptr=nullptr, .id=24, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="eop_eop_out_11", .next_ptr=nullptr, .id=25, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },

	} };
intr_reg_t pb_pbc_int_groups_intreg = {  .name="pb.pbc.int_groups.intreg", .addr=0x1400010, .reg_type=1, .id=324, .field_count=31, .fields=
	{
		{  .name="int_ecc_fc_0", .next_ptr=&pb_pbc_int_ecc_fc_0, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_ecc_ll_0", .next_ptr=&pb_pbc_int_ecc_ll_0, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_ecc_desc_0", .next_ptr=&pb_pbc_int_ecc_desc_0, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_ecc_fc_1", .next_ptr=&pb_pbc_int_ecc_fc_1, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_ecc_ll_1", .next_ptr=&pb_pbc_int_ecc_ll_1, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_ecc_desc_1", .next_ptr=&pb_pbc_int_ecc_desc_1, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_write_0", .next_ptr=&pb_pbc_int_write_0, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_write_1", .next_ptr=&pb_pbc_int_write_1, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_write_2", .next_ptr=&pb_pbc_int_write_2, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_write_3", .next_ptr=&pb_pbc_int_write_3, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_write_4", .next_ptr=&pb_pbc_int_write_4, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_write_5", .next_ptr=&pb_pbc_int_write_5, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_write_6", .next_ptr=&pb_pbc_int_write_6, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_write_7", .next_ptr=&pb_pbc_int_write_7, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_write_8", .next_ptr=&pb_pbc_int_write_8, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_write_9", .next_ptr=&pb_pbc_int_write_9, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_write_10", .next_ptr=&pb_pbc_int_write_10, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_write_11", .next_ptr=&pb_pbc_int_write_11, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_ecc_rc", .next_ptr=&pb_pbc_int_ecc_rc, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_ecc_pack", .next_ptr=&pb_pbc_int_ecc_pack, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_ecc_rwr", .next_ptr=&pb_pbc_int_ecc_rwr, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_ecc_sched", .next_ptr=&pb_pbc_int_ecc_sched, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_ecc_sideband", .next_ptr=&pb_pbc_int_ecc_sideband, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_ecc_nc", .next_ptr=&pb_pbc_int_ecc_nc, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_ecc_uc", .next_ptr=&pb_pbc_int_ecc_uc, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_ecc_port_mon_in", .next_ptr=&pb_pbc_int_ecc_port_mon_in, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_ecc_port_mon_out", .next_ptr=&pb_pbc_int_ecc_port_mon_out, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_rpl", .next_ptr=&pb_pbc_int_rpl, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_credit_underflow", .next_ptr=&pb_pbc_int_credit_underflow, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_pbus_violation_in", .next_ptr=&pb_pbc_int_pbus_violation_in, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_pbus_violation_out", .next_ptr=&pb_pbc_int_pbus_violation_out, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t mc_mc_6_int_mc = {  .name="mc.mc[6].int_mc", .addr=0x6a780020, .reg_type=0, .id=418, .field_count=1, .fields=
	{
		{  .name="mch_int", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_ERR, .desc="" },

	} };
intr_reg_t mc_mc_6_int_groups_intreg = {  .name="mc.mc[6].int_groups.intreg", .addr=0x6a780010, .reg_type=1, .id=419, .field_count=1, .fields=
	{
		{  .name="int_mc", .next_ptr=&mc_mc_6_int_mc, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t pcr_te_4_int_err = {  .name="pcr.te[4].int_err", .addr=0x62c2440, .reg_type=0, .id=205, .field_count=20, .fields=
	{
		{  .name="miss_sop", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="previous stage error" },
		{  .name="miss_eop", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="previous stage error" },
		{  .name="phv_max_size", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="invalid" },
		{  .name="spurious_axi_rsp", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="spurious_tcam_rsp", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_FATAL, .desc="bad tcam response" },
		{  .name="te2mpu_timeout", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="impossible, should be disabled" },
		{  .name="axi_rdrsp_err", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="axi_bad_read", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="tcam_req_idx_fifo", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="tcam_rsp_idx_fifo", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="mpu_req_idx_fifo", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="axi_req_idx_fifo", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="proc_tbl_vld_wo_proc", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend_wo_wb", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend1_wo_pend0", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="both_pend_down", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend_wo_proc_down", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="both_pend_went_up", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="loaded_but_no_proc", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="loaded_but_no_proc_tbl_vld", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },

	} };
intr_reg_t pcr_te_4_int_info = {  .name="pcr.te[4].int_info", .addr=0x62c2450, .reg_type=0, .id=206, .field_count=17, .fields=
	{
		{  .name="profile_cam_hit0", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit1", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit2", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit4", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit5", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit6", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit7", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit8", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit9", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit10", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit11", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit12", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit13", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit14", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit15", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_miss", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t pcr_te_4_int_groups_intreg = {  .name="pcr.te[4].int_groups.intreg", .addr=0x62c2430, .reg_type=1, .id=207, .field_count=2, .fields=
	{
		{  .name="int_err", .next_ptr=&pcr_te_4_int_err, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_info", .next_ptr=&pcr_te_4_int_info, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t sse_pics_int_pics = {  .name="sse.pics.int_pics", .addr=0x2c01520, .reg_type=0, .id=356, .field_count=4, .fields=
	{
		{  .name="uncorrectable_ecc", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="correctable_ecc", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="too_many_rl_sch_error", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="picc", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t sse_pics_int_badaddr = {  .name="sse.pics.int_badaddr", .addr=0x2c01530, .reg_type=0, .id=357, .field_count=18, .fields=
	{
		{  .name="rdreq0_bad_addr", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="wrreq0_bad_addr", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="rdreq1_bad_addr", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="wrreq1_bad_addr", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="rdreq2_bad_addr", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="wrreq2_bad_addr", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="rdreq3_bad_addr", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="wrreq3_bad_addr", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="rdreq4_bad_addr", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="wrreq4_bad_addr", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="rdreq5_bad_addr", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="wrreq5_bad_addr", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="rdreq6_bad_addr", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="wrreq6_bad_addr", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="rdreq7_bad_addr", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="wrreq7_bad_addr", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="cpu_bad_addr", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="bg_bad_addr", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },

	} };
intr_reg_t sse_pics_int_bg = {  .name="sse.pics.int_bg", .addr=0x2c01540, .reg_type=0, .id=358, .field_count=16, .fields=
	{
		{  .name="unfinished_bg0", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="unfinished_bg1", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="unfinished_bg2", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="unfinished_bg3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="unfinished_bg4", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="unfinished_bg5", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="unfinished_bg6", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="unfinished_bg7", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="unfinished_bg8", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="unfinished_bg9", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="unfinished_bg10", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="unfinished_bg11", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="unfinished_bg12", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="unfinished_bg13", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="unfinished_bg14", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="unfinished_bg15", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },

	} };
intr_reg_t sse_pics_int_groups_intreg = {  .name="sse.pics.int_groups.intreg", .addr=0x2c01510, .reg_type=1, .id=359, .field_count=3, .fields=
	{
		{  .name="int_pics", .next_ptr=&sse_pics_int_pics, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_badaddr", .next_ptr=&sse_pics_int_badaddr, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_bg", .next_ptr=&sse_pics_int_bg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t pct_te_2_int_err = {  .name="pct.te[2].int_err", .addr=0x6382440, .reg_type=0, .id=251, .field_count=20, .fields=
	{
		{  .name="miss_sop", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="previous stage error" },
		{  .name="miss_eop", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="previous stage error" },
		{  .name="phv_max_size", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="invalid" },
		{  .name="spurious_axi_rsp", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="spurious_tcam_rsp", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_FATAL, .desc="bad tcam response" },
		{  .name="te2mpu_timeout", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="impossible, should be disabled" },
		{  .name="axi_rdrsp_err", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="axi_bad_read", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="tcam_req_idx_fifo", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="tcam_rsp_idx_fifo", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="mpu_req_idx_fifo", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="axi_req_idx_fifo", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="proc_tbl_vld_wo_proc", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend_wo_wb", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend1_wo_pend0", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="both_pend_down", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend_wo_proc_down", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="both_pend_went_up", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="loaded_but_no_proc", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="loaded_but_no_proc_tbl_vld", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },

	} };
intr_reg_t pct_te_2_int_info = {  .name="pct.te[2].int_info", .addr=0x6382450, .reg_type=0, .id=252, .field_count=17, .fields=
	{
		{  .name="profile_cam_hit0", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit1", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit2", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit4", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit5", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit6", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit7", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit8", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit9", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit10", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit11", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit12", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit13", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit14", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit15", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_miss", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t pct_te_2_int_groups_intreg = {  .name="pct.te[2].int_groups.intreg", .addr=0x6382430, .reg_type=1, .id=253, .field_count=2, .fields=
	{
		{  .name="int_err", .next_ptr=&pct_te_2_int_err, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_info", .next_ptr=&pct_te_2_int_info, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t pp_pp_port_p_1_int_p_ecc = {  .name="pp.pp.port_p[1].int_p_ecc", .addr=0x7000990, .reg_type=0, .id=141, .field_count=11, .fields=
	{
		{  .name="rxbfr_overflow", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="Fatal error, try to reproduce in lab and debug the configuration settings using PCIE Analyzer" },
		{  .name="replay_bfr_overflow", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="Fatal error, try to reproduce in lab and debug the configuration settings using PCIE Analyzer" },
		{  .name="rxtlp_err", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="txbuf_0_uncorrectable", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="txbuf_1_uncorrectable", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="txbuf_2_uncorrectable", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="txbuf_3_uncorrectable", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="txbuf_0_correctable", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="txbuf_1_correctable", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="txbuf_2_correctable", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="txbuf_3_correctable", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },

	} };
intr_reg_t pp_pp_port_p_1_int_groups_intreg = {  .name="pp.pp.port_p[1].int_groups.intreg", .addr=0x7000980, .reg_type=1, .id=142, .field_count=1, .fields=
	{
		{  .name="int_p_ecc", .next_ptr=&pp_pp_port_p_1_int_p_ecc, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t sgi_te_1_int_err = {  .name="sgi.te[1].int_err", .addr=0x35e2440, .reg_type=0, .id=42, .field_count=20, .fields=
	{
		{  .name="miss_sop", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="previous stage error" },
		{  .name="miss_eop", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="previous stage error" },
		{  .name="phv_max_size", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="invalid" },
		{  .name="spurious_axi_rsp", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="spurious_tcam_rsp", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_FATAL, .desc="bad tcam response" },
		{  .name="te2mpu_timeout", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="impossible, should be disabled" },
		{  .name="axi_rdrsp_err", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="axi_bad_read", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="tcam_req_idx_fifo", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="tcam_rsp_idx_fifo", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="mpu_req_idx_fifo", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="axi_req_idx_fifo", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="proc_tbl_vld_wo_proc", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend_wo_wb", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend1_wo_pend0", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="both_pend_down", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend_wo_proc_down", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="both_pend_went_up", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="loaded_but_no_proc", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="loaded_but_no_proc_tbl_vld", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },

	} };
intr_reg_t sgi_te_1_int_info = {  .name="sgi.te[1].int_info", .addr=0x35e2450, .reg_type=0, .id=43, .field_count=17, .fields=
	{
		{  .name="profile_cam_hit0", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit1", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit2", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit4", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit5", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit6", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit7", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit8", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit9", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit10", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit11", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit12", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit13", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit14", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit15", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_miss", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t sgi_te_1_int_groups_intreg = {  .name="sgi.te[1].int_groups.intreg", .addr=0x35e2430, .reg_type=1, .id=44, .field_count=2, .fields=
	{
		{  .name="int_err", .next_ptr=&sgi_te_1_int_err, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_info", .next_ptr=&sgi_te_1_int_info, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t ssi_pics_int_pics = {  .name="ssi.pics.int_pics", .addr=0x2401520, .reg_type=0, .id=350, .field_count=4, .fields=
	{
		{  .name="uncorrectable_ecc", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="correctable_ecc", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="too_many_rl_sch_error", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="picc", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t ssi_pics_int_badaddr = {  .name="ssi.pics.int_badaddr", .addr=0x2401530, .reg_type=0, .id=351, .field_count=18, .fields=
	{
		{  .name="rdreq0_bad_addr", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="wrreq0_bad_addr", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="rdreq1_bad_addr", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="wrreq1_bad_addr", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="rdreq2_bad_addr", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="wrreq2_bad_addr", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="rdreq3_bad_addr", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="wrreq3_bad_addr", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="rdreq4_bad_addr", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="wrreq4_bad_addr", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="rdreq5_bad_addr", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="wrreq5_bad_addr", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="rdreq6_bad_addr", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="wrreq6_bad_addr", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="rdreq7_bad_addr", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="wrreq7_bad_addr", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="cpu_bad_addr", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="bg_bad_addr", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },

	} };
intr_reg_t ssi_pics_int_bg = {  .name="ssi.pics.int_bg", .addr=0x2401540, .reg_type=0, .id=352, .field_count=16, .fields=
	{
		{  .name="unfinished_bg0", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="unfinished_bg1", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="unfinished_bg2", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="unfinished_bg3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="unfinished_bg4", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="unfinished_bg5", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="unfinished_bg6", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="unfinished_bg7", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="unfinished_bg8", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="unfinished_bg9", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="unfinished_bg10", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="unfinished_bg11", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="unfinished_bg12", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="unfinished_bg13", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="unfinished_bg14", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="unfinished_bg15", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },

	} };
intr_reg_t ssi_pics_int_groups_intreg = {  .name="ssi.pics.int_groups.intreg", .addr=0x2401510, .reg_type=1, .id=353, .field_count=3, .fields=
	{
		{  .name="int_pics", .next_ptr=&ssi_pics_int_pics, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_badaddr", .next_ptr=&ssi_pics_int_badaddr, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_bg", .next_ptr=&ssi_pics_int_bg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t mc_mc_0_int_mc = {  .name="mc.mc[0].int_mc", .addr=0x6a180020, .reg_type=0, .id=394, .field_count=1, .fields=
	{
		{  .name="mch_int", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_ERR, .desc="" },

	} };
intr_reg_t mc_mc_0_int_groups_intreg = {  .name="mc.mc[0].int_groups.intreg", .addr=0x6a180010, .reg_type=1, .id=395, .field_count=1, .fields=
	{
		{  .name="int_mc", .next_ptr=&mc_mc_0_int_mc, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t dpp_dpp_0_int_reg1 = {  .name="dpp.dpp[0].int_reg1", .addr=0x3000090, .reg_type=0, .id=426, .field_count=17, .fields=
	{
		{  .name="err_phv_sop_no_eop", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="err_phv_eop_no_sop", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="err_ohi_sop_no_eop", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="err_ohi_eop_no_sop", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="err_framer_credit_overrun", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="err_packets_in_flight_credit_overrun", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="err_null_hdr_vld", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="P4 program/compiler error. packet has no headers (0 size)" },
		{  .name="err_null_hdrfld_vld", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="P4 program/compiler error. packet has no headers (0 size)" },
		{  .name="err_max_pkt_size", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_ERR, .desc="P4 program/compiler error. packet built size exceeding programmed threshold  " },
		{  .name="err_max_active_hdrs", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="P4 program/compiler error. exceeding max number of available headers per 64 byte line" },
		{  .name="err_phv_no_data_reference_ohi", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_FATAL, .desc="P4 program/compiler error. reference to a byte in the incoming packet on a software PHV originated frame with no associated packet" },
		{  .name="err_csum_multiple_hdr", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="P4 program/compiler error. more than one header requesting same csum engine computation" },
		{  .name="err_csum_multiple_hdr_copy", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="P4 program/compiler error. more than one header requesting csum copy" },
		{  .name="err_crc_multiple_hdr", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="P4 program/compiler error. more than one header requesting crc computation" },
		{  .name="err_ptr_fifo_credit_overrun", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="err_clip_max_pkt_size", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="P4 program/compiler error. Packet constructed goes beyond programmed or hardwires  max byte threshold (whichever is less)" },
		{  .name="err_min_pkt_size", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="P4 program/compiler error. packet built size too small to carry vital intrinsic information" },

	} };
intr_reg_t dpp_dpp_0_int_reg2 = {  .name="dpp.dpp[0].int_reg2", .addr=0x30000a0, .reg_type=0, .id=427, .field_count=2, .fields=
	{
		{  .name="fieldC", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="spare" },
		{  .name="fieldD", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="spare" },

	} };
intr_reg_t dpp_dpp_0_int_srams_ecc = {  .name="dpp.dpp[0].int_srams_ecc", .addr=0x3000060, .reg_type=0, .id=428, .field_count=4, .fields=
	{
		{  .name="dpp_phv_fifo_uncorrectable", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="dpp_phv_fifo_correctable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="dpp_ohi_fifo_uncorrectable", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="dpp_ohi_fifo_correctable", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },

	} };
intr_reg_t dpp_dpp_0_int_fifo = {  .name="dpp.dpp[0].int_fifo", .addr=0x30000b0, .reg_type=0, .id=429, .field_count=6, .fields=
	{
		{  .name="phv_ff_overflow", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="ohi_ff_overflow", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="pkt_size_ff_ovflow", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="pkt_size_ff_undflow", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="csum_phv_ff_ovflow", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="csum_phv_ff_undflow", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },

	} };
intr_reg_t dpp_dpp_0_int_spare = {  .name="dpp.dpp[0].int_spare", .addr=0x30000d0, .reg_type=0, .id=430, .field_count=32, .fields=
	{
		{  .name="spare_0", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_ERR, .desc="spare_0: err_headerfld_size. P4 program/compiler error. header size is grater than > 16Kbytes; spare_1: err_adder_overflow P4 program/compiler error acccumulated header size is grater than > 16Kbytes; spare_2: capture engaged used for debug;" },
		{  .name="spare_1", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="spare_0: err_headerfld_size. P4 program/compiler error. header size is grater than > 16Kbytes; spare_1: err_adder_overflow P4 program/compiler error acccumulated header size is grater than > 16Kbytes; spare_2: capture engaged used for debug;" },
		{  .name="spare_2", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="spare_0: err_headerfld_size. P4 program/compiler error. header size is grater than > 16Kbytes; spare_1: err_adder_overflow P4 program/compiler error acccumulated header size is grater than > 16Kbytes; spare_2: capture engaged used for debug;" },
		{  .name="spare_3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="spare_0: err_headerfld_size. P4 program/compiler error. header size is grater than > 16Kbytes; spare_1: err_adder_overflow P4 program/compiler error acccumulated header size is grater than > 16Kbytes; spare_2: capture engaged used for debug;" },
		{  .name="spare_4", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="spare_0: err_headerfld_size. P4 program/compiler error. header size is grater than > 16Kbytes; spare_1: err_adder_overflow P4 program/compiler error acccumulated header size is grater than > 16Kbytes; spare_2: capture engaged used for debug;" },
		{  .name="spare_5", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="spare_0: err_headerfld_size. P4 program/compiler error. header size is grater than > 16Kbytes; spare_1: err_adder_overflow P4 program/compiler error acccumulated header size is grater than > 16Kbytes; spare_2: capture engaged used for debug;" },
		{  .name="spare_6", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="spare_0: err_headerfld_size. P4 program/compiler error. header size is grater than > 16Kbytes; spare_1: err_adder_overflow P4 program/compiler error acccumulated header size is grater than > 16Kbytes; spare_2: capture engaged used for debug;" },
		{  .name="spare_7", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="spare_0: err_headerfld_size. P4 program/compiler error. header size is grater than > 16Kbytes; spare_1: err_adder_overflow P4 program/compiler error acccumulated header size is grater than > 16Kbytes; spare_2: capture engaged used for debug;" },
		{  .name="spare_8", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_ERR, .desc="spare_0: err_headerfld_size. P4 program/compiler error. header size is grater than > 16Kbytes; spare_1: err_adder_overflow P4 program/compiler error acccumulated header size is grater than > 16Kbytes; spare_2: capture engaged used for debug;" },
		{  .name="spare_9", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="spare_0: err_headerfld_size. P4 program/compiler error. header size is grater than > 16Kbytes; spare_1: err_adder_overflow P4 program/compiler error acccumulated header size is grater than > 16Kbytes; spare_2: capture engaged used for debug;" },
		{  .name="spare_10", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_ERR, .desc="spare_0: err_headerfld_size. P4 program/compiler error. header size is grater than > 16Kbytes; spare_1: err_adder_overflow P4 program/compiler error acccumulated header size is grater than > 16Kbytes; spare_2: capture engaged used for debug;" },
		{  .name="spare_11", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="spare_0: err_headerfld_size. P4 program/compiler error. header size is grater than > 16Kbytes; spare_1: err_adder_overflow P4 program/compiler error acccumulated header size is grater than > 16Kbytes; spare_2: capture engaged used for debug;" },
		{  .name="spare_12", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="spare_0: err_headerfld_size. P4 program/compiler error. header size is grater than > 16Kbytes; spare_1: err_adder_overflow P4 program/compiler error acccumulated header size is grater than > 16Kbytes; spare_2: capture engaged used for debug;" },
		{  .name="spare_13", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="spare_0: err_headerfld_size. P4 program/compiler error. header size is grater than > 16Kbytes; spare_1: err_adder_overflow P4 program/compiler error acccumulated header size is grater than > 16Kbytes; spare_2: capture engaged used for debug;" },
		{  .name="spare_14", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_ERR, .desc="spare_0: err_headerfld_size. P4 program/compiler error. header size is grater than > 16Kbytes; spare_1: err_adder_overflow P4 program/compiler error acccumulated header size is grater than > 16Kbytes; spare_2: capture engaged used for debug;" },
		{  .name="spare_15", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="spare_0: err_headerfld_size. P4 program/compiler error. header size is grater than > 16Kbytes; spare_1: err_adder_overflow P4 program/compiler error acccumulated header size is grater than > 16Kbytes; spare_2: capture engaged used for debug;" },
		{  .name="spare_16", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="spare_0: err_headerfld_size. P4 program/compiler error. header size is grater than > 16Kbytes; spare_1: err_adder_overflow P4 program/compiler error acccumulated header size is grater than > 16Kbytes; spare_2: capture engaged used for debug;" },
		{  .name="spare_17", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_ERR, .desc="spare_0: err_headerfld_size. P4 program/compiler error. header size is grater than > 16Kbytes; spare_1: err_adder_overflow P4 program/compiler error acccumulated header size is grater than > 16Kbytes; spare_2: capture engaged used for debug;" },
		{  .name="spare_18", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_ERR, .desc="spare_0: err_headerfld_size. P4 program/compiler error. header size is grater than > 16Kbytes; spare_1: err_adder_overflow P4 program/compiler error acccumulated header size is grater than > 16Kbytes; spare_2: capture engaged used for debug;" },
		{  .name="spare_19", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_ERR, .desc="spare_0: err_headerfld_size. P4 program/compiler error. header size is grater than > 16Kbytes; spare_1: err_adder_overflow P4 program/compiler error acccumulated header size is grater than > 16Kbytes; spare_2: capture engaged used for debug;" },
		{  .name="spare_20", .next_ptr=nullptr, .id=22, .severity=INTR_SEV_TYPE_ERR, .desc="spare_0: err_headerfld_size. P4 program/compiler error. header size is grater than > 16Kbytes; spare_1: err_adder_overflow P4 program/compiler error acccumulated header size is grater than > 16Kbytes; spare_2: capture engaged used for debug;" },
		{  .name="spare_21", .next_ptr=nullptr, .id=23, .severity=INTR_SEV_TYPE_ERR, .desc="spare_0: err_headerfld_size. P4 program/compiler error. header size is grater than > 16Kbytes; spare_1: err_adder_overflow P4 program/compiler error acccumulated header size is grater than > 16Kbytes; spare_2: capture engaged used for debug;" },
		{  .name="spare_22", .next_ptr=nullptr, .id=24, .severity=INTR_SEV_TYPE_ERR, .desc="spare_0: err_headerfld_size. P4 program/compiler error. header size is grater than > 16Kbytes; spare_1: err_adder_overflow P4 program/compiler error acccumulated header size is grater than > 16Kbytes; spare_2: capture engaged used for debug;" },
		{  .name="spare_23", .next_ptr=nullptr, .id=25, .severity=INTR_SEV_TYPE_ERR, .desc="spare_0: err_headerfld_size. P4 program/compiler error. header size is grater than > 16Kbytes; spare_1: err_adder_overflow P4 program/compiler error acccumulated header size is grater than > 16Kbytes; spare_2: capture engaged used for debug;" },
		{  .name="spare_24", .next_ptr=nullptr, .id=26, .severity=INTR_SEV_TYPE_ERR, .desc="spare_0: err_headerfld_size. P4 program/compiler error. header size is grater than > 16Kbytes; spare_1: err_adder_overflow P4 program/compiler error acccumulated header size is grater than > 16Kbytes; spare_2: capture engaged used for debug;" },
		{  .name="spare_25", .next_ptr=nullptr, .id=27, .severity=INTR_SEV_TYPE_ERR, .desc="spare_0: err_headerfld_size. P4 program/compiler error. header size is grater than > 16Kbytes; spare_1: err_adder_overflow P4 program/compiler error acccumulated header size is grater than > 16Kbytes; spare_2: capture engaged used for debug;" },
		{  .name="spare_26", .next_ptr=nullptr, .id=28, .severity=INTR_SEV_TYPE_ERR, .desc="spare_0: err_headerfld_size. P4 program/compiler error. header size is grater than > 16Kbytes; spare_1: err_adder_overflow P4 program/compiler error acccumulated header size is grater than > 16Kbytes; spare_2: capture engaged used for debug;" },
		{  .name="spare_27", .next_ptr=nullptr, .id=29, .severity=INTR_SEV_TYPE_ERR, .desc="spare_0: err_headerfld_size. P4 program/compiler error. header size is grater than > 16Kbytes; spare_1: err_adder_overflow P4 program/compiler error acccumulated header size is grater than > 16Kbytes; spare_2: capture engaged used for debug;" },
		{  .name="spare_28", .next_ptr=nullptr, .id=30, .severity=INTR_SEV_TYPE_ERR, .desc="spare_0: err_headerfld_size. P4 program/compiler error. header size is grater than > 16Kbytes; spare_1: err_adder_overflow P4 program/compiler error acccumulated header size is grater than > 16Kbytes; spare_2: capture engaged used for debug;" },
		{  .name="spare_29", .next_ptr=nullptr, .id=31, .severity=INTR_SEV_TYPE_ERR, .desc="spare_0: err_headerfld_size. P4 program/compiler error. header size is grater than > 16Kbytes; spare_1: err_adder_overflow P4 program/compiler error acccumulated header size is grater than > 16Kbytes; spare_2: capture engaged used for debug;" },
		{  .name="spare_30", .next_ptr=nullptr, .id=32, .severity=INTR_SEV_TYPE_ERR, .desc="spare_0: err_headerfld_size. P4 program/compiler error. header size is grater than > 16Kbytes; spare_1: err_adder_overflow P4 program/compiler error acccumulated header size is grater than > 16Kbytes; spare_2: capture engaged used for debug;" },
		{  .name="spare_31", .next_ptr=nullptr, .id=33, .severity=INTR_SEV_TYPE_ERR, .desc="spare_0: err_headerfld_size. P4 program/compiler error. header size is grater than > 16Kbytes; spare_1: err_adder_overflow P4 program/compiler error acccumulated header size is grater than > 16Kbytes; spare_2: capture engaged used for debug;" },

	} };
intr_reg_t dpp_dpp_0_int_credit = {  .name="dpp.dpp[0].int_credit", .addr=0x30000c0, .reg_type=0, .id=431, .field_count=9, .fields=
	{
		{  .name="ptr_credit_ovflow", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="ptr_credit_undflow", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="pkt_credit_ovflow", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="pkt_credit_undflow", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="framer_credit_ovflow", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="framer_credit_undflow", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="framer_hdrfld_vld_ovfl", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="framer_hdrfld_offset_ovfl", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="err_framer_hdrsize_zero_ovfl", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },

	} };
intr_reg_t dpp_dpp_0_int_groups_intreg = {  .name="dpp.dpp[0].int_groups.intreg", .addr=0x3000080, .reg_type=1, .id=432, .field_count=6, .fields=
	{
		{  .name="int_reg1", .next_ptr=&dpp_dpp_0_int_reg1, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_reg2", .next_ptr=&dpp_dpp_0_int_reg2, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_srams_ecc", .next_ptr=&dpp_dpp_0_int_srams_ecc, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_fifo", .next_ptr=&dpp_dpp_0_int_fifo, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_spare", .next_ptr=&dpp_dpp_0_int_spare, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_credit", .next_ptr=&dpp_dpp_0_int_credit, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t pr_pr_int_reg1 = {  .name="pr.pr.int_reg1", .addr=0x6120420, .reg_type=0, .id=123, .field_count=2, .fields=
	{
		{  .name="slave_prd", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="slave_psp", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };
intr_reg_t pr_pr_int_groups_intreg = {  .name="pr.pr.int_groups.intreg", .addr=0x6120410, .reg_type=1, .id=124, .field_count=1, .fields=
	{
		{  .name="int_reg1", .next_ptr=&pr_pr_int_reg1, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t sgi_mpu_1_int_err = {  .name="sgi.mpu[1].int_err", .addr=0x36f8630, .reg_type=0, .id=60, .field_count=27, .fields=
	{
		{  .name="results_mismatch", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="mask this interrupt, not fully implemented" },
		{  .name="sdp_mem_uncorrectable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="sdp_mem_correctable", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="illegal_op_0", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_1", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_2", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_3", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="max_inst_0", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_1", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_2", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_3", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="phvwr_0", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_1", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_2", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_3", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="write_err_0", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_1", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_2", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_3", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="cache_axi_0", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_1", .next_ptr=nullptr, .id=22, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_2", .next_ptr=nullptr, .id=23, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_3", .next_ptr=nullptr, .id=24, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_parity_0", .next_ptr=nullptr, .id=25, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_1", .next_ptr=nullptr, .id=26, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_2", .next_ptr=nullptr, .id=27, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_3", .next_ptr=nullptr, .id=28, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },

	} };
intr_reg_t sgi_mpu_1_int_info = {  .name="sgi.mpu[1].int_info", .addr=0x36f8640, .reg_type=0, .id=61, .field_count=8, .fields=
	{
		{  .name="trace_full_0", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_1", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_2", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="mpu_stop_0", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_1", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_2", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_3", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },

	} };
intr_reg_t sgi_mpu_1_int_groups_intreg = {  .name="sgi.mpu[1].int_groups.intreg", .addr=0x36f8620, .reg_type=1, .id=62, .field_count=2, .fields=
	{
		{  .name="int_err", .next_ptr=&sgi_mpu_1_int_err, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_info", .next_ptr=&sgi_mpu_1_int_info, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t tpc_pics_int_pics = {  .name="tpc.pics.int_pics", .addr=0x4401520, .reg_type=0, .id=370, .field_count=4, .fields=
	{
		{  .name="uncorrectable_ecc", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="correctable_ecc", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="too_many_rl_sch_error", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="picc", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t tpc_pics_int_badaddr = {  .name="tpc.pics.int_badaddr", .addr=0x4401530, .reg_type=0, .id=371, .field_count=18, .fields=
	{
		{  .name="rdreq0_bad_addr", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="wrreq0_bad_addr", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="rdreq1_bad_addr", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="wrreq1_bad_addr", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="rdreq2_bad_addr", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="wrreq2_bad_addr", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="rdreq3_bad_addr", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="wrreq3_bad_addr", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="rdreq4_bad_addr", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="wrreq4_bad_addr", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="rdreq5_bad_addr", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="wrreq5_bad_addr", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="rdreq6_bad_addr", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="wrreq6_bad_addr", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="rdreq7_bad_addr", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="wrreq7_bad_addr", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="cpu_bad_addr", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="bg_bad_addr", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },

	} };
intr_reg_t tpc_pics_int_bg = {  .name="tpc.pics.int_bg", .addr=0x4401540, .reg_type=0, .id=372, .field_count=16, .fields=
	{
		{  .name="unfinished_bg0", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="unfinished_bg1", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="unfinished_bg2", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="unfinished_bg3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="unfinished_bg4", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="unfinished_bg5", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="unfinished_bg6", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="unfinished_bg7", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="unfinished_bg8", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="unfinished_bg9", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="unfinished_bg10", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="unfinished_bg11", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="unfinished_bg12", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="unfinished_bg13", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="unfinished_bg14", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="unfinished_bg15", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },

	} };
intr_reg_t tpc_pics_int_groups_intreg = {  .name="tpc.pics.int_groups.intreg", .addr=0x4401510, .reg_type=1, .id=373, .field_count=3, .fields=
	{
		{  .name="int_pics", .next_ptr=&tpc_pics_int_pics, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_badaddr", .next_ptr=&tpc_pics_int_badaddr, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_bg", .next_ptr=&tpc_pics_int_bg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t sgi_te_5_int_err = {  .name="sgi.te[5].int_err", .addr=0x3662440, .reg_type=0, .id=54, .field_count=20, .fields=
	{
		{  .name="miss_sop", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="previous stage error" },
		{  .name="miss_eop", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="previous stage error" },
		{  .name="phv_max_size", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="invalid" },
		{  .name="spurious_axi_rsp", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="spurious_tcam_rsp", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_FATAL, .desc="bad tcam response" },
		{  .name="te2mpu_timeout", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="impossible, should be disabled" },
		{  .name="axi_rdrsp_err", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="axi_bad_read", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="tcam_req_idx_fifo", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="tcam_rsp_idx_fifo", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="mpu_req_idx_fifo", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="axi_req_idx_fifo", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="proc_tbl_vld_wo_proc", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend_wo_wb", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend1_wo_pend0", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="both_pend_down", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend_wo_proc_down", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="both_pend_went_up", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="loaded_but_no_proc", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="loaded_but_no_proc_tbl_vld", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },

	} };
intr_reg_t sgi_te_5_int_info = {  .name="sgi.te[5].int_info", .addr=0x3662450, .reg_type=0, .id=55, .field_count=17, .fields=
	{
		{  .name="profile_cam_hit0", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit1", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit2", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit4", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit5", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit6", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit7", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit8", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit9", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit10", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit11", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit12", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit13", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit14", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit15", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_miss", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t sgi_te_5_int_groups_intreg = {  .name="sgi.te[5].int_groups.intreg", .addr=0x3662430, .reg_type=1, .id=56, .field_count=2, .fields=
	{
		{  .name="int_err", .next_ptr=&sgi_te_5_int_err, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_info", .next_ptr=&sgi_te_5_int_info, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t pcr_te_7_int_err = {  .name="pcr.te[7].int_err", .addr=0x6322440, .reg_type=0, .id=214, .field_count=20, .fields=
	{
		{  .name="miss_sop", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="previous stage error" },
		{  .name="miss_eop", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="previous stage error" },
		{  .name="phv_max_size", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="invalid" },
		{  .name="spurious_axi_rsp", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="spurious_tcam_rsp", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_FATAL, .desc="bad tcam response" },
		{  .name="te2mpu_timeout", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="impossible, should be disabled" },
		{  .name="axi_rdrsp_err", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="axi_bad_read", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="tcam_req_idx_fifo", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="tcam_rsp_idx_fifo", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="mpu_req_idx_fifo", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="axi_req_idx_fifo", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="proc_tbl_vld_wo_proc", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend_wo_wb", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend1_wo_pend0", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="both_pend_down", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend_wo_proc_down", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="both_pend_went_up", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="loaded_but_no_proc", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="loaded_but_no_proc_tbl_vld", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },

	} };
intr_reg_t pcr_te_7_int_info = {  .name="pcr.te[7].int_info", .addr=0x6322450, .reg_type=0, .id=215, .field_count=17, .fields=
	{
		{  .name="profile_cam_hit0", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit1", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit2", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit4", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit5", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit6", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit7", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit8", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit9", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit10", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit11", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit12", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit13", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit14", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit15", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_miss", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t pcr_te_7_int_groups_intreg = {  .name="pcr.te[7].int_groups.intreg", .addr=0x6322430, .reg_type=1, .id=216, .field_count=2, .fields=
	{
		{  .name="int_err", .next_ptr=&pcr_te_7_int_err, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_info", .next_ptr=&pcr_te_7_int_info, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t pcr_mpu_3_int_err = {  .name="pcr.mpu[3].int_err", .addr=0x6478630, .reg_type=0, .id=226, .field_count=27, .fields=
	{
		{  .name="results_mismatch", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="mask this interrupt, not fully implemented" },
		{  .name="sdp_mem_uncorrectable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="sdp_mem_correctable", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="illegal_op_0", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_1", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_2", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_3", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="max_inst_0", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_1", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_2", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_3", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="phvwr_0", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_1", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_2", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_3", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="write_err_0", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_1", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_2", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_3", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="cache_axi_0", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_1", .next_ptr=nullptr, .id=22, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_2", .next_ptr=nullptr, .id=23, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_3", .next_ptr=nullptr, .id=24, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_parity_0", .next_ptr=nullptr, .id=25, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_1", .next_ptr=nullptr, .id=26, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_2", .next_ptr=nullptr, .id=27, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_3", .next_ptr=nullptr, .id=28, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },

	} };
intr_reg_t pcr_mpu_3_int_info = {  .name="pcr.mpu[3].int_info", .addr=0x6478640, .reg_type=0, .id=227, .field_count=8, .fields=
	{
		{  .name="trace_full_0", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_1", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_2", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="mpu_stop_0", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_1", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_2", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_3", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },

	} };
intr_reg_t pcr_mpu_3_int_groups_intreg = {  .name="pcr.mpu[3].int_groups.intreg", .addr=0x6478620, .reg_type=1, .id=228, .field_count=2, .fields=
	{
		{  .name="int_err", .next_ptr=&pcr_mpu_3_int_err, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_info", .next_ptr=&pcr_mpu_3_int_info, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t pp_pp_port_c_1_int_c_mac = {  .name="pp.pp.port_c[1].int_c_mac", .addr=0x70131b0, .reg_type=0, .id=158, .field_count=19, .fields=
	{
		{  .name="link_dn2up", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="link_up2dn", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="sec_bus_rst", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="rst_up2dn", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="rst_dn2up", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="portgate_open2close", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="ltssm_st_changed", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="sec_busnum_changed", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="rc_pme", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="rc_aerr", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="rc_serr", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="rc_hpe", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="rc_eq_req", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="rc_dpc", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="pm_turnoff", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="txbfr_overflow", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_FATAL, .desc="Fatal error, try to reproduce in lab and debug the configuration settings using PCIE Analyzer" },
		{  .name="rxtlp_err", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="" },
		{  .name="tl_flr_req", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="rc_legacy_intpin_changed", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t pp_pp_port_c_1_int_c_ecc = {  .name="pp.pp.port_c[1].int_c_ecc", .addr=0x70131c0, .reg_type=0, .id=159, .field_count=8, .fields=
	{
		{  .name="rxbuf_0_uncorrectable", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="rxbuf_1_uncorrectable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="rxbuf_2_uncorrectable", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="rxbuf_3_uncorrectable", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="rxbuf_0_correctable", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="rxbuf_1_correctable", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="rxbuf_2_correctable", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="rxbuf_3_correctable", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },

	} };
intr_reg_t pp_pp_port_c_1_int_groups_intreg = {  .name="pp.pp.port_c[1].int_groups.intreg", .addr=0x70131a0, .reg_type=1, .id=160, .field_count=2, .fields=
	{
		{  .name="int_c_mac", .next_ptr=&pp_pp_port_c_1_int_c_mac, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_c_ecc", .next_ptr=&pp_pp_port_c_1_int_c_ecc, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t pcr_mpu_1_int_err = {  .name="pcr.mpu[1].int_err", .addr=0x6458630, .reg_type=0, .id=220, .field_count=27, .fields=
	{
		{  .name="results_mismatch", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="mask this interrupt, not fully implemented" },
		{  .name="sdp_mem_uncorrectable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="sdp_mem_correctable", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="illegal_op_0", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_1", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_2", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_3", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="max_inst_0", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_1", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_2", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_3", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="phvwr_0", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_1", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_2", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_3", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="write_err_0", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_1", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_2", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_3", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="cache_axi_0", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_1", .next_ptr=nullptr, .id=22, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_2", .next_ptr=nullptr, .id=23, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_3", .next_ptr=nullptr, .id=24, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_parity_0", .next_ptr=nullptr, .id=25, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_1", .next_ptr=nullptr, .id=26, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_2", .next_ptr=nullptr, .id=27, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_3", .next_ptr=nullptr, .id=28, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },

	} };
intr_reg_t pcr_mpu_1_int_info = {  .name="pcr.mpu[1].int_info", .addr=0x6458640, .reg_type=0, .id=221, .field_count=8, .fields=
	{
		{  .name="trace_full_0", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_1", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_2", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="mpu_stop_0", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_1", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_2", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_3", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },

	} };
intr_reg_t pcr_mpu_1_int_groups_intreg = {  .name="pcr.mpu[1].int_groups.intreg", .addr=0x6458620, .reg_type=1, .id=222, .field_count=2, .fields=
	{
		{  .name="int_err", .next_ptr=&pcr_mpu_1_int_err, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_info", .next_ptr=&pcr_mpu_1_int_info, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t pcr_mpu_2_int_err = {  .name="pcr.mpu[2].int_err", .addr=0x6468630, .reg_type=0, .id=223, .field_count=27, .fields=
	{
		{  .name="results_mismatch", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="mask this interrupt, not fully implemented" },
		{  .name="sdp_mem_uncorrectable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="sdp_mem_correctable", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="illegal_op_0", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_1", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_2", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_3", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="max_inst_0", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_1", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_2", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_3", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="phvwr_0", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_1", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_2", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_3", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="write_err_0", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_1", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_2", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_3", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="cache_axi_0", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_1", .next_ptr=nullptr, .id=22, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_2", .next_ptr=nullptr, .id=23, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_3", .next_ptr=nullptr, .id=24, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_parity_0", .next_ptr=nullptr, .id=25, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_1", .next_ptr=nullptr, .id=26, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_2", .next_ptr=nullptr, .id=27, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_3", .next_ptr=nullptr, .id=28, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },

	} };
intr_reg_t pcr_mpu_2_int_info = {  .name="pcr.mpu[2].int_info", .addr=0x6468640, .reg_type=0, .id=224, .field_count=8, .fields=
	{
		{  .name="trace_full_0", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_1", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_2", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="mpu_stop_0", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_1", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_2", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_3", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },

	} };
intr_reg_t pcr_mpu_2_int_groups_intreg = {  .name="pcr.mpu[2].int_groups.intreg", .addr=0x6468620, .reg_type=1, .id=225, .field_count=2, .fields=
	{
		{  .name="int_err", .next_ptr=&pcr_mpu_2_int_err, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_info", .next_ptr=&pcr_mpu_2_int_info, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t sgi_mpu_3_int_err = {  .name="sgi.mpu[3].int_err", .addr=0x3718630, .reg_type=0, .id=66, .field_count=27, .fields=
	{
		{  .name="results_mismatch", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="mask this interrupt, not fully implemented" },
		{  .name="sdp_mem_uncorrectable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="sdp_mem_correctable", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="illegal_op_0", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_1", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_2", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_3", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="max_inst_0", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_1", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_2", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_3", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="phvwr_0", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_1", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_2", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_3", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="write_err_0", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_1", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_2", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_3", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="cache_axi_0", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_1", .next_ptr=nullptr, .id=22, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_2", .next_ptr=nullptr, .id=23, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_3", .next_ptr=nullptr, .id=24, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_parity_0", .next_ptr=nullptr, .id=25, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_1", .next_ptr=nullptr, .id=26, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_2", .next_ptr=nullptr, .id=27, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_3", .next_ptr=nullptr, .id=28, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },

	} };
intr_reg_t sgi_mpu_3_int_info = {  .name="sgi.mpu[3].int_info", .addr=0x3718640, .reg_type=0, .id=67, .field_count=8, .fields=
	{
		{  .name="trace_full_0", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_1", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_2", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="mpu_stop_0", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_1", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_2", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_3", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },

	} };
intr_reg_t sgi_mpu_3_int_groups_intreg = {  .name="sgi.mpu[3].int_groups.intreg", .addr=0x3718620, .reg_type=1, .id=68, .field_count=2, .fields=
	{
		{  .name="int_err", .next_ptr=&sgi_mpu_3_int_err, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_info", .next_ptr=&sgi_mpu_3_int_info, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t pct_te_6_int_err = {  .name="pct.te[6].int_err", .addr=0x6402440, .reg_type=0, .id=263, .field_count=20, .fields=
	{
		{  .name="miss_sop", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="previous stage error" },
		{  .name="miss_eop", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="previous stage error" },
		{  .name="phv_max_size", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="invalid" },
		{  .name="spurious_axi_rsp", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="spurious_tcam_rsp", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_FATAL, .desc="bad tcam response" },
		{  .name="te2mpu_timeout", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="impossible, should be disabled" },
		{  .name="axi_rdrsp_err", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="axi_bad_read", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="tcam_req_idx_fifo", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="tcam_rsp_idx_fifo", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="mpu_req_idx_fifo", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="axi_req_idx_fifo", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="proc_tbl_vld_wo_proc", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend_wo_wb", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend1_wo_pend0", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="both_pend_down", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend_wo_proc_down", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="both_pend_went_up", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="loaded_but_no_proc", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="loaded_but_no_proc_tbl_vld", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },

	} };
intr_reg_t pct_te_6_int_info = {  .name="pct.te[6].int_info", .addr=0x6402450, .reg_type=0, .id=264, .field_count=17, .fields=
	{
		{  .name="profile_cam_hit0", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit1", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit2", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit4", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit5", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit6", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit7", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit8", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit9", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit10", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit11", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit12", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit13", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit14", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit15", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_miss", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t pct_te_6_int_groups_intreg = {  .name="pct.te[6].int_groups.intreg", .addr=0x6402430, .reg_type=1, .id=265, .field_count=2, .fields=
	{
		{  .name="int_err", .next_ptr=&pct_te_6_int_err, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_info", .next_ptr=&pct_te_6_int_info, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t mc_mc_7_mch_int_mc = {  .name="mc.mc[7].mch.int_mc", .addr=0x6a800060, .reg_type=0, .id=424, .field_count=2, .fields=
	{
		{  .name="ecc_1bit_thresh_ps1", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_ERR, .desc="" },
		{  .name="ecc_1bit_thresh_ps0", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="" },

	} };
intr_reg_t mc_mc_7_mch_int_groups_intreg = {  .name="mc.mc[7].mch.int_groups.intreg", .addr=0x6a800050, .reg_type=1, .id=425, .field_count=1, .fields=
	{
		{  .name="int_mc", .next_ptr=&mc_mc_7_mch_int_mc, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t pt_pt_ptd_int_ecc = {  .name="pt.pt.ptd.int_ecc", .addr=0x6220020, .reg_type=0, .id=187, .field_count=6, .fields=
	{
		{  .name="rdata_mem_uncorrectable", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="rdata_mem_correctable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="lat_mem_uncorrectable", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="lat_mem_correctable", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="wdata_mem_uncorrectable", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="wdata_mem_correctable", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },

	} };
intr_reg_t pt_pt_ptd_int_fifo = {  .name="pt.pt.ptd.int_fifo", .addr=0x6220030, .reg_type=0, .id=188, .field_count=9, .fields=
	{
		{  .name="lat_ff_ovflow", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="wdata_ff_ovflow", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="rcv_stg_ff_ovflow", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="cmdflit_ff_ovflow", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="cmd_ff_ovflow", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="pkt_ff_ovflow", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="wr_mem_ff_ovflow", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="dfence_ff_ovflow", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="ffence_ff_ovflow", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },

	} };
intr_reg_t pt_pt_ptd_int_grp1 = {  .name="pt.pt.ptd.int_grp1", .addr=0x6220040, .reg_type=0, .id=189, .field_count=19, .fields=
	{
		{  .name="rcv_phv_dma_ptr", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_ERR, .desc="software error. dma pointer points to a non-existing flit in PHV" },
		{  .name="rcv_phv_addr", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="software error. phv2mem or phv2pkt start/end address is not programmed correctly." },
		{  .name="rcv_exceed_16byte", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="software error. mem2mem_phv2mem or phv2mem with fence exceeded 16 bytes" },
		{  .name="rcv_phv_not_sop", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="rcv_pkt_order_ff_full", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="rcv_pend_phv_more_than_2", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="rcv_pend_phv_less", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="rcv_cmd_nop_eop", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="software error. NOP is seen at the end, but no cmd_eop" },
		{  .name="rcv_cmd_out_not_sop", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="rcv_pkt2mem_seen", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="software error. pkt2mem command not expected in PTD" },
		{  .name="rcv_skip_seen", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_ERR, .desc="software error. skip command not expected in PTD" },
		{  .name="rcv_phv_eop_no_cmd_eop", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="software error. End of PHV reached, but cmdeop is not seen in any command" },
		{  .name="rcv_m2m_dst_not_seen", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="software error. mem2mem_dst command is expected right after mem2mem_src." },
		{  .name="rcv_m2m_src_not_seen", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="software error. mem2mem_dst command is seen without mem2mem_src before it." },
		{  .name="rdreq_invalid_cmd_seen", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_ERR, .desc="software error. invalid cmdtype seen in dma command" },
		{  .name="rdreq_mem2mem_psize_zero", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="software error. mem2mem psize field is zero" },
		{  .name="rdreq_m2m_phv2mem_exceed_16byte", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="software error. mem2mem_phv2mem exceeds 16 bytes" },
		{  .name="rdreq_phv2mem_fence_exceed_16byte", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_ERR, .desc="software error. phv2mem fence exceeds 16 bytes" },
		{  .name="rdreq_mem2pkt_psize_zero", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_ERR, .desc="software error. mem2pkt psize field is zero" },

	} };
intr_reg_t pt_pt_ptd_int_grp2 = {  .name="pt.pt.ptd.int_grp2", .addr=0x6220050, .reg_type=0, .id=190, .field_count=13, .fields=
	{
		{  .name="wr_invalid_cmd", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_ERR, .desc="software error. invalid cmdtype seen in dma command" },
		{  .name="wr_pend_sz", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="wr_axi_rd_resp", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="pkt_err_eop_forced", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="Eop is forced while creating a packet. Check for interrupts in ptd_wr. Possible software error or axi read resp error." },
		{  .name="pkt_no_eop_err_seen", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="Eop is forced while creating a packet. Check for interrupts in ptd_wr. Possible software error or axi read resp error." },
		{  .name="pkt_cmd_eop_no_data", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Packet creation control signal error. This can happen with either axi read resp error or malformed dma commands. Check other interrupts in ptd_wr block." },
		{  .name="rdrsp_axi", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="wrrsp_axi", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="spurious_rd_resp", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_ERR, .desc="unexpected read response received. Check interrupts in other blocks." },
		{  .name="spurious_wr_resp", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="unexpected write response received. check interrupts in other blocks" },
		{  .name="wrreq_info_first_missing", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_ERR, .desc="software error can trigger this interrupt. Can happen with other interrupts. If no other interrupt, then this may be a hw error." },
		{  .name="wrreq_num_bytes_zero", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="software error can trigger this interrupt. Can happen with other interrupts. If no other interrupt, then this may be a hw error." },
		{  .name="wrreq_num_bytes_more_than_64", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="software error can trigger this interrupt. Can happen with other interrupts. If no other interrupt, then this may be a hw error." },

	} };
intr_reg_t pt_pt_ptd_int_intf = {  .name="pt.pt.ptd.int_intf", .addr=0x6220060, .reg_type=0, .id=191, .field_count=9, .fields=
	{
		{  .name="pb_err", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_ERR, .desc="Packet to PB sent with error. Possible axi read response error or malformed dma commands. Check other interrupts in ptd_wr block" },
		{  .name="pb_sop_err", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="pb_eop_err", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="npv_resub_err", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="PHV sent to NPV with error bit. Possible error bit set in PHV from STG or ecc error. check interrupts in other blocks." },
		{  .name="npv_resub_sop_err", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="npv_resub_eop_err", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="ma_err", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="PHV from STG received with error bit. Possible ecc error. Check interrupts in other blocks." },
		{  .name="ma_sop_err", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="ma_eop_err", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },

	} };
intr_reg_t pt_pt_ptd_int_groups_intreg = {  .name="pt.pt.ptd.int_groups.intreg", .addr=0x6220010, .reg_type=1, .id=192, .field_count=5, .fields=
	{
		{  .name="int_ecc", .next_ptr=&pt_pt_ptd_int_ecc, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_fifo", .next_ptr=&pt_pt_ptd_int_fifo, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_grp1", .next_ptr=&pt_pt_ptd_int_grp1, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_grp2", .next_ptr=&pt_pt_ptd_int_grp2, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_intf", .next_ptr=&pt_pt_ptd_int_intf, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t mx_mx_0_int_mac = {  .name="mx.mx[0].int_mac", .addr=0x1d82080, .reg_type=0, .id=477, .field_count=30, .fields=
	{
		{  .name="lane0_sbe", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="lane0_dbe", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_HW_RMA, .desc="Double bit error in SerDes. Lane may go down" },
		{  .name="lane1_sbe", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="lane1_dbe", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_HW_RMA, .desc="Double bit error in SerDes. Lane may go down" },
		{  .name="lane2_sbe", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="lane2_dbe", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_HW_RMA, .desc="Double bit error in SerDes. Lane may go down" },
		{  .name="lane3_sbe", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="lane3_dbe", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_HW_RMA, .desc="Double bit error in SerDes. Lane may go down" },
		{  .name="umac_CFG3_intr", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="umac_CFG3_pslverr", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_INFO, .desc="Invalid need to be masked" },
		{  .name="m0pb_pbus_drdy", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_FATAL, .desc="Debug PB config. Never happen; otherwise, it's hardware bug" },
		{  .name="m1pb_pbus_drdy", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_FATAL, .desc="Debug PB config. Never happen; otherwise, it's hardware bug" },
		{  .name="m2pb_pbus_drdy", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_FATAL, .desc="Debug PB config. Never happen; otherwise, it's hardware bug" },
		{  .name="m3pb_pbus_drdy", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_FATAL, .desc="Debug PB config. Never happen; otherwise, it's hardware bug" },
		{  .name="rx0_missing_sof", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_INFO, .desc="HW self recover" },
		{  .name="rx0_missing_eof", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_INFO, .desc="HW self recover" },
		{  .name="rx0_timeout_err", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_INFO, .desc="HW self recover" },
		{  .name="rx0_min_size_err", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_INFO, .desc="HW self recover" },
		{  .name="rx1_missing_sof", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_INFO, .desc="HW self recover" },
		{  .name="rx1_missing_eof", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_INFO, .desc="HW self recover" },
		{  .name="rx1_timeout_err", .next_ptr=nullptr, .id=22, .severity=INTR_SEV_TYPE_INFO, .desc="HW self recover" },
		{  .name="rx1_min_size_err", .next_ptr=nullptr, .id=23, .severity=INTR_SEV_TYPE_INFO, .desc="HW self recover" },
		{  .name="rx2_missing_sof", .next_ptr=nullptr, .id=24, .severity=INTR_SEV_TYPE_INFO, .desc="HW self recover" },
		{  .name="rx2_missing_eof", .next_ptr=nullptr, .id=25, .severity=INTR_SEV_TYPE_INFO, .desc="HW self recover" },
		{  .name="rx2_timeout_err", .next_ptr=nullptr, .id=26, .severity=INTR_SEV_TYPE_INFO, .desc="HW self recover" },
		{  .name="rx2_min_size_err", .next_ptr=nullptr, .id=27, .severity=INTR_SEV_TYPE_INFO, .desc="HW self recover" },
		{  .name="rx3_missing_sof", .next_ptr=nullptr, .id=28, .severity=INTR_SEV_TYPE_INFO, .desc="HW self recover" },
		{  .name="rx3_missing_eof", .next_ptr=nullptr, .id=29, .severity=INTR_SEV_TYPE_INFO, .desc="HW self recover" },
		{  .name="rx3_timeout_err", .next_ptr=nullptr, .id=30, .severity=INTR_SEV_TYPE_INFO, .desc="HW self recover" },
		{  .name="rx3_min_size_err", .next_ptr=nullptr, .id=31, .severity=INTR_SEV_TYPE_INFO, .desc="HW self recover" },

	} };
intr_reg_t mx_mx_0_int_ecc = {  .name="mx.mx[0].int_ecc", .addr=0x1d820c0, .reg_type=0, .id=478, .field_count=2, .fields=
	{
		{  .name="uncorrectable", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="correctable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },

	} };
intr_reg_t mx_mx_0_int_groups_intreg = {  .name="mx.mx[0].int_groups.intreg", .addr=0x1d82070, .reg_type=1, .id=479, .field_count=2, .fields=
	{
		{  .name="int_mac", .next_ptr=&mx_mx_0_int_mac, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_ecc", .next_ptr=&mx_mx_0_int_ecc, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t dpp_dpp_1_int_reg1 = {  .name="dpp.dpp[1].int_reg1", .addr=0x3100090, .reg_type=0, .id=433, .field_count=17, .fields=
	{
		{  .name="err_phv_sop_no_eop", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="err_phv_eop_no_sop", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="err_ohi_sop_no_eop", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="err_ohi_eop_no_sop", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="err_framer_credit_overrun", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="err_packets_in_flight_credit_overrun", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="err_null_hdr_vld", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="P4 program/compiler error. packet has no headers (0 size)" },
		{  .name="err_null_hdrfld_vld", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="P4 program/compiler error. packet has no headers (0 size)" },
		{  .name="err_max_pkt_size", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_ERR, .desc="P4 program/compiler error. packet built size exceeding programmed threshold  " },
		{  .name="err_max_active_hdrs", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="P4 program/compiler error. exceeding max number of available headers per 64 byte line" },
		{  .name="err_phv_no_data_reference_ohi", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_FATAL, .desc="P4 program/compiler error. reference to a byte in the incoming packet on a software PHV originated frame with no associated packet" },
		{  .name="err_csum_multiple_hdr", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="P4 program/compiler error. more than one header requesting same csum engine computation" },
		{  .name="err_csum_multiple_hdr_copy", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="P4 program/compiler error. more than one header requesting csum copy" },
		{  .name="err_crc_multiple_hdr", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="P4 program/compiler error. more than one header requesting crc computation" },
		{  .name="err_ptr_fifo_credit_overrun", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="err_clip_max_pkt_size", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="P4 program/compiler error. Packet constructed goes beyond programmed or hardwires  max byte threshold (whichever is less)" },
		{  .name="err_min_pkt_size", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="P4 program/compiler error. packet built size too small to carry vital intrinsic information" },

	} };
intr_reg_t dpp_dpp_1_int_reg2 = {  .name="dpp.dpp[1].int_reg2", .addr=0x31000a0, .reg_type=0, .id=434, .field_count=2, .fields=
	{
		{  .name="fieldC", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="spare" },
		{  .name="fieldD", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="spare" },

	} };
intr_reg_t dpp_dpp_1_int_srams_ecc = {  .name="dpp.dpp[1].int_srams_ecc", .addr=0x3100060, .reg_type=0, .id=435, .field_count=4, .fields=
	{
		{  .name="dpp_phv_fifo_uncorrectable", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="dpp_phv_fifo_correctable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="dpp_ohi_fifo_uncorrectable", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="dpp_ohi_fifo_correctable", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },

	} };
intr_reg_t dpp_dpp_1_int_fifo = {  .name="dpp.dpp[1].int_fifo", .addr=0x31000b0, .reg_type=0, .id=436, .field_count=6, .fields=
	{
		{  .name="phv_ff_overflow", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="ohi_ff_overflow", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="pkt_size_ff_ovflow", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="pkt_size_ff_undflow", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="csum_phv_ff_ovflow", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="csum_phv_ff_undflow", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },

	} };
intr_reg_t dpp_dpp_1_int_spare = {  .name="dpp.dpp[1].int_spare", .addr=0x31000d0, .reg_type=0, .id=437, .field_count=32, .fields=
	{
		{  .name="spare_0", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_ERR, .desc="spare_0: err_headerfld_size. P4 program/compiler error. header size is grater than > 16Kbytes; spare_1: err_adder_overflow P4 program/compiler error acccumulated header size is grater than > 16Kbytes; spare_2: capture engaged used for debug;" },
		{  .name="spare_1", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="spare_0: err_headerfld_size. P4 program/compiler error. header size is grater than > 16Kbytes; spare_1: err_adder_overflow P4 program/compiler error acccumulated header size is grater than > 16Kbytes; spare_2: capture engaged used for debug;" },
		{  .name="spare_2", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="spare_0: err_headerfld_size. P4 program/compiler error. header size is grater than > 16Kbytes; spare_1: err_adder_overflow P4 program/compiler error acccumulated header size is grater than > 16Kbytes; spare_2: capture engaged used for debug;" },
		{  .name="spare_3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="spare_0: err_headerfld_size. P4 program/compiler error. header size is grater than > 16Kbytes; spare_1: err_adder_overflow P4 program/compiler error acccumulated header size is grater than > 16Kbytes; spare_2: capture engaged used for debug;" },
		{  .name="spare_4", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="spare_0: err_headerfld_size. P4 program/compiler error. header size is grater than > 16Kbytes; spare_1: err_adder_overflow P4 program/compiler error acccumulated header size is grater than > 16Kbytes; spare_2: capture engaged used for debug;" },
		{  .name="spare_5", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="spare_0: err_headerfld_size. P4 program/compiler error. header size is grater than > 16Kbytes; spare_1: err_adder_overflow P4 program/compiler error acccumulated header size is grater than > 16Kbytes; spare_2: capture engaged used for debug;" },
		{  .name="spare_6", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="spare_0: err_headerfld_size. P4 program/compiler error. header size is grater than > 16Kbytes; spare_1: err_adder_overflow P4 program/compiler error acccumulated header size is grater than > 16Kbytes; spare_2: capture engaged used for debug;" },
		{  .name="spare_7", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="spare_0: err_headerfld_size. P4 program/compiler error. header size is grater than > 16Kbytes; spare_1: err_adder_overflow P4 program/compiler error acccumulated header size is grater than > 16Kbytes; spare_2: capture engaged used for debug;" },
		{  .name="spare_8", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_ERR, .desc="spare_0: err_headerfld_size. P4 program/compiler error. header size is grater than > 16Kbytes; spare_1: err_adder_overflow P4 program/compiler error acccumulated header size is grater than > 16Kbytes; spare_2: capture engaged used for debug;" },
		{  .name="spare_9", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="spare_0: err_headerfld_size. P4 program/compiler error. header size is grater than > 16Kbytes; spare_1: err_adder_overflow P4 program/compiler error acccumulated header size is grater than > 16Kbytes; spare_2: capture engaged used for debug;" },
		{  .name="spare_10", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_ERR, .desc="spare_0: err_headerfld_size. P4 program/compiler error. header size is grater than > 16Kbytes; spare_1: err_adder_overflow P4 program/compiler error acccumulated header size is grater than > 16Kbytes; spare_2: capture engaged used for debug;" },
		{  .name="spare_11", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="spare_0: err_headerfld_size. P4 program/compiler error. header size is grater than > 16Kbytes; spare_1: err_adder_overflow P4 program/compiler error acccumulated header size is grater than > 16Kbytes; spare_2: capture engaged used for debug;" },
		{  .name="spare_12", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="spare_0: err_headerfld_size. P4 program/compiler error. header size is grater than > 16Kbytes; spare_1: err_adder_overflow P4 program/compiler error acccumulated header size is grater than > 16Kbytes; spare_2: capture engaged used for debug;" },
		{  .name="spare_13", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="spare_0: err_headerfld_size. P4 program/compiler error. header size is grater than > 16Kbytes; spare_1: err_adder_overflow P4 program/compiler error acccumulated header size is grater than > 16Kbytes; spare_2: capture engaged used for debug;" },
		{  .name="spare_14", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_ERR, .desc="spare_0: err_headerfld_size. P4 program/compiler error. header size is grater than > 16Kbytes; spare_1: err_adder_overflow P4 program/compiler error acccumulated header size is grater than > 16Kbytes; spare_2: capture engaged used for debug;" },
		{  .name="spare_15", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="spare_0: err_headerfld_size. P4 program/compiler error. header size is grater than > 16Kbytes; spare_1: err_adder_overflow P4 program/compiler error acccumulated header size is grater than > 16Kbytes; spare_2: capture engaged used for debug;" },
		{  .name="spare_16", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="spare_0: err_headerfld_size. P4 program/compiler error. header size is grater than > 16Kbytes; spare_1: err_adder_overflow P4 program/compiler error acccumulated header size is grater than > 16Kbytes; spare_2: capture engaged used for debug;" },
		{  .name="spare_17", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_ERR, .desc="spare_0: err_headerfld_size. P4 program/compiler error. header size is grater than > 16Kbytes; spare_1: err_adder_overflow P4 program/compiler error acccumulated header size is grater than > 16Kbytes; spare_2: capture engaged used for debug;" },
		{  .name="spare_18", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_ERR, .desc="spare_0: err_headerfld_size. P4 program/compiler error. header size is grater than > 16Kbytes; spare_1: err_adder_overflow P4 program/compiler error acccumulated header size is grater than > 16Kbytes; spare_2: capture engaged used for debug;" },
		{  .name="spare_19", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_ERR, .desc="spare_0: err_headerfld_size. P4 program/compiler error. header size is grater than > 16Kbytes; spare_1: err_adder_overflow P4 program/compiler error acccumulated header size is grater than > 16Kbytes; spare_2: capture engaged used for debug;" },
		{  .name="spare_20", .next_ptr=nullptr, .id=22, .severity=INTR_SEV_TYPE_ERR, .desc="spare_0: err_headerfld_size. P4 program/compiler error. header size is grater than > 16Kbytes; spare_1: err_adder_overflow P4 program/compiler error acccumulated header size is grater than > 16Kbytes; spare_2: capture engaged used for debug;" },
		{  .name="spare_21", .next_ptr=nullptr, .id=23, .severity=INTR_SEV_TYPE_ERR, .desc="spare_0: err_headerfld_size. P4 program/compiler error. header size is grater than > 16Kbytes; spare_1: err_adder_overflow P4 program/compiler error acccumulated header size is grater than > 16Kbytes; spare_2: capture engaged used for debug;" },
		{  .name="spare_22", .next_ptr=nullptr, .id=24, .severity=INTR_SEV_TYPE_ERR, .desc="spare_0: err_headerfld_size. P4 program/compiler error. header size is grater than > 16Kbytes; spare_1: err_adder_overflow P4 program/compiler error acccumulated header size is grater than > 16Kbytes; spare_2: capture engaged used for debug;" },
		{  .name="spare_23", .next_ptr=nullptr, .id=25, .severity=INTR_SEV_TYPE_ERR, .desc="spare_0: err_headerfld_size. P4 program/compiler error. header size is grater than > 16Kbytes; spare_1: err_adder_overflow P4 program/compiler error acccumulated header size is grater than > 16Kbytes; spare_2: capture engaged used for debug;" },
		{  .name="spare_24", .next_ptr=nullptr, .id=26, .severity=INTR_SEV_TYPE_ERR, .desc="spare_0: err_headerfld_size. P4 program/compiler error. header size is grater than > 16Kbytes; spare_1: err_adder_overflow P4 program/compiler error acccumulated header size is grater than > 16Kbytes; spare_2: capture engaged used for debug;" },
		{  .name="spare_25", .next_ptr=nullptr, .id=27, .severity=INTR_SEV_TYPE_ERR, .desc="spare_0: err_headerfld_size. P4 program/compiler error. header size is grater than > 16Kbytes; spare_1: err_adder_overflow P4 program/compiler error acccumulated header size is grater than > 16Kbytes; spare_2: capture engaged used for debug;" },
		{  .name="spare_26", .next_ptr=nullptr, .id=28, .severity=INTR_SEV_TYPE_ERR, .desc="spare_0: err_headerfld_size. P4 program/compiler error. header size is grater than > 16Kbytes; spare_1: err_adder_overflow P4 program/compiler error acccumulated header size is grater than > 16Kbytes; spare_2: capture engaged used for debug;" },
		{  .name="spare_27", .next_ptr=nullptr, .id=29, .severity=INTR_SEV_TYPE_ERR, .desc="spare_0: err_headerfld_size. P4 program/compiler error. header size is grater than > 16Kbytes; spare_1: err_adder_overflow P4 program/compiler error acccumulated header size is grater than > 16Kbytes; spare_2: capture engaged used for debug;" },
		{  .name="spare_28", .next_ptr=nullptr, .id=30, .severity=INTR_SEV_TYPE_ERR, .desc="spare_0: err_headerfld_size. P4 program/compiler error. header size is grater than > 16Kbytes; spare_1: err_adder_overflow P4 program/compiler error acccumulated header size is grater than > 16Kbytes; spare_2: capture engaged used for debug;" },
		{  .name="spare_29", .next_ptr=nullptr, .id=31, .severity=INTR_SEV_TYPE_ERR, .desc="spare_0: err_headerfld_size. P4 program/compiler error. header size is grater than > 16Kbytes; spare_1: err_adder_overflow P4 program/compiler error acccumulated header size is grater than > 16Kbytes; spare_2: capture engaged used for debug;" },
		{  .name="spare_30", .next_ptr=nullptr, .id=32, .severity=INTR_SEV_TYPE_ERR, .desc="spare_0: err_headerfld_size. P4 program/compiler error. header size is grater than > 16Kbytes; spare_1: err_adder_overflow P4 program/compiler error acccumulated header size is grater than > 16Kbytes; spare_2: capture engaged used for debug;" },
		{  .name="spare_31", .next_ptr=nullptr, .id=33, .severity=INTR_SEV_TYPE_ERR, .desc="spare_0: err_headerfld_size. P4 program/compiler error. header size is grater than > 16Kbytes; spare_1: err_adder_overflow P4 program/compiler error acccumulated header size is grater than > 16Kbytes; spare_2: capture engaged used for debug;" },

	} };
intr_reg_t dpp_dpp_1_int_credit = {  .name="dpp.dpp[1].int_credit", .addr=0x31000c0, .reg_type=0, .id=438, .field_count=9, .fields=
	{
		{  .name="ptr_credit_ovflow", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="ptr_credit_undflow", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="pkt_credit_ovflow", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="pkt_credit_undflow", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="framer_credit_ovflow", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="framer_credit_undflow", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="framer_hdrfld_vld_ovfl", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="framer_hdrfld_offset_ovfl", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },
		{  .name="err_framer_hdrsize_zero_ovfl", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_FATAL, .desc="Hardware Error" },

	} };
intr_reg_t dpp_dpp_1_int_groups_intreg = {  .name="dpp.dpp[1].int_groups.intreg", .addr=0x3100080, .reg_type=1, .id=439, .field_count=6, .fields=
	{
		{  .name="int_reg1", .next_ptr=&dpp_dpp_1_int_reg1, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_reg2", .next_ptr=&dpp_dpp_1_int_reg2, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_srams_ecc", .next_ptr=&dpp_dpp_1_int_srams_ecc, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_fifo", .next_ptr=&dpp_dpp_1_int_fifo, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_spare", .next_ptr=&dpp_dpp_1_int_spare, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_credit", .next_ptr=&dpp_dpp_1_int_credit, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t rpc_pics_int_pics = {  .name="rpc.pics.int_pics", .addr=0x4c01520, .reg_type=0, .id=75, .field_count=4, .fields=
	{
		{  .name="uncorrectable_ecc", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="correctable_ecc", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="too_many_rl_sch_error", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="picc", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t rpc_pics_int_badaddr = {  .name="rpc.pics.int_badaddr", .addr=0x4c01530, .reg_type=0, .id=76, .field_count=18, .fields=
	{
		{  .name="rdreq0_bad_addr", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="wrreq0_bad_addr", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="rdreq1_bad_addr", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="wrreq1_bad_addr", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="rdreq2_bad_addr", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="wrreq2_bad_addr", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="rdreq3_bad_addr", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="wrreq3_bad_addr", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="rdreq4_bad_addr", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="wrreq4_bad_addr", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="rdreq5_bad_addr", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="wrreq5_bad_addr", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="rdreq6_bad_addr", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="wrreq6_bad_addr", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="rdreq7_bad_addr", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="wrreq7_bad_addr", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="cpu_bad_addr", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="bg_bad_addr", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },

	} };
intr_reg_t rpc_pics_int_bg = {  .name="rpc.pics.int_bg", .addr=0x4c01540, .reg_type=0, .id=77, .field_count=16, .fields=
	{
		{  .name="unfinished_bg0", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="unfinished_bg1", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="unfinished_bg2", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="unfinished_bg3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="unfinished_bg4", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="unfinished_bg5", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="unfinished_bg6", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="unfinished_bg7", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="unfinished_bg8", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="unfinished_bg9", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="unfinished_bg10", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="unfinished_bg11", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="unfinished_bg12", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="unfinished_bg13", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="unfinished_bg14", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },
		{  .name="unfinished_bg15", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="SW programming error" },

	} };
intr_reg_t rpc_pics_int_groups_intreg = {  .name="rpc.pics.int_groups.intreg", .addr=0x4c01510, .reg_type=1, .id=78, .field_count=3, .fields=
	{
		{  .name="int_pics", .next_ptr=&rpc_pics_int_pics, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_badaddr", .next_ptr=&rpc_pics_int_badaddr, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_bg", .next_ptr=&rpc_pics_int_bg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t sge_te_0_int_err = {  .name="sge.te[0].int_err", .addr=0x3502440, .reg_type=0, .id=87, .field_count=20, .fields=
	{
		{  .name="miss_sop", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="previous stage error" },
		{  .name="miss_eop", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="previous stage error" },
		{  .name="phv_max_size", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="invalid" },
		{  .name="spurious_axi_rsp", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="spurious_tcam_rsp", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_FATAL, .desc="bad tcam response" },
		{  .name="te2mpu_timeout", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="impossible, should be disabled" },
		{  .name="axi_rdrsp_err", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="axi_bad_read", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="tcam_req_idx_fifo", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="tcam_rsp_idx_fifo", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="mpu_req_idx_fifo", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="axi_req_idx_fifo", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="proc_tbl_vld_wo_proc", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend_wo_wb", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend1_wo_pend0", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="both_pend_down", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend_wo_proc_down", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="both_pend_went_up", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="loaded_but_no_proc", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="loaded_but_no_proc_tbl_vld", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },

	} };
intr_reg_t sge_te_0_int_info = {  .name="sge.te[0].int_info", .addr=0x3502450, .reg_type=0, .id=88, .field_count=17, .fields=
	{
		{  .name="profile_cam_hit0", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit1", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit2", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit4", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit5", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit6", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit7", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit8", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit9", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit10", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit11", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit12", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit13", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit14", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit15", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_miss", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t sge_te_0_int_groups_intreg = {  .name="sge.te[0].int_groups.intreg", .addr=0x3502430, .reg_type=1, .id=89, .field_count=2, .fields=
	{
		{  .name="int_err", .next_ptr=&sge_te_0_int_err, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_info", .next_ptr=&sge_te_0_int_info, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t mc_mc_4_int_mc = {  .name="mc.mc[4].int_mc", .addr=0x6a580020, .reg_type=0, .id=410, .field_count=1, .fields=
	{
		{  .name="mch_int", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_ERR, .desc="" },

	} };
intr_reg_t mc_mc_4_int_groups_intreg = {  .name="mc.mc[4].int_groups.intreg", .addr=0x6a580010, .reg_type=1, .id=411, .field_count=1, .fields=
	{
		{  .name="int_mc", .next_ptr=&mc_mc_4_int_mc, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t rpc_pics_picc_int_picc = {  .name="rpc.pics.picc.int_picc", .addr=0x4da0020, .reg_type=0, .id=79, .field_count=7, .fields=
	{
		{  .name="uncorrectable_ecc", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="correctable_ecc", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="cache_stg_awlen_err", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_FATAL, .desc="HBM access fatal error" },
		{  .name="cache_hbm_rresp_slverr", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_FATAL, .desc="HBM access fatal error" },
		{  .name="cache_hbm_rresp_decerr", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_FATAL, .desc="HBM access fatal error" },
		{  .name="cache_hbm_bresp_slverr", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_FATAL, .desc="HBM access fatal error" },
		{  .name="cache_hbm_bresp_decerr", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_FATAL, .desc="HBM access fatal error" },

	} };
intr_reg_t rpc_pics_picc_int_groups_intreg = {  .name="rpc.pics.picc.int_groups.intreg", .addr=0x4da0010, .reg_type=1, .id=80, .field_count=1, .fields=
	{
		{  .name="int_picc", .next_ptr=&rpc_pics_picc_int_picc, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t mp_mpns_int_crypto = {  .name="mp.mpns.int_crypto", .addr=0x65640c0, .reg_type=0, .id=441, .field_count=8, .fields=
	{
		{  .name="mpp0", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="https://docs.google.com/document/d/1o7e-6AhV5ET_WoOvVRvMOXqFLDGzunZIx1R1BwUpzek/view#heading=h.e62qntm4xe7q" },
		{  .name="mpp1", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="https://docs.google.com/document/d/1o7e-6AhV5ET_WoOvVRvMOXqFLDGzunZIx1R1BwUpzek/view#heading=h.e62qntm4xe7q" },
		{  .name="mpp2", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="https://docs.google.com/document/d/1o7e-6AhV5ET_WoOvVRvMOXqFLDGzunZIx1R1BwUpzek/view#heading=h.e62qntm4xe7q" },
		{  .name="mpp3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="https://docs.google.com/document/d/1o7e-6AhV5ET_WoOvVRvMOXqFLDGzunZIx1R1BwUpzek/view#heading=h.e62qntm4xe7q" },
		{  .name="mpp4", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_INFO, .desc="https://docs.google.com/document/d/1o7e-6AhV5ET_WoOvVRvMOXqFLDGzunZIx1R1BwUpzek/view#heading=h.e62qntm4xe7q" },
		{  .name="mpp5", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="https://docs.google.com/document/d/1o7e-6AhV5ET_WoOvVRvMOXqFLDGzunZIx1R1BwUpzek/view#heading=h.e62qntm4xe7q" },
		{  .name="mpp6", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_INFO, .desc="https://docs.google.com/document/d/1o7e-6AhV5ET_WoOvVRvMOXqFLDGzunZIx1R1BwUpzek/view#heading=h.e62qntm4xe7q" },
		{  .name="mpp7", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_INFO, .desc="https://docs.google.com/document/d/1o7e-6AhV5ET_WoOvVRvMOXqFLDGzunZIx1R1BwUpzek/view#heading=h.e62qntm4xe7q" },

	} };
intr_reg_t mp_mpns_int_groups_intreg = {  .name="mp.mpns.int_groups.intreg", .addr=0x65640b0, .reg_type=1, .id=442, .field_count=1, .fields=
	{
		{  .name="int_crypto", .next_ptr=&mp_mpns_int_crypto, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t pct_mpu_2_int_err = {  .name="pct.mpu[2].int_err", .addr=0x64e8630, .reg_type=0, .id=275, .field_count=27, .fields=
	{
		{  .name="results_mismatch", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="mask this interrupt, not fully implemented" },
		{  .name="sdp_mem_uncorrectable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="sdp_mem_correctable", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="illegal_op_0", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_1", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_2", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_3", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="max_inst_0", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_1", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_2", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_3", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="phvwr_0", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_1", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_2", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_3", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="write_err_0", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_1", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_2", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_3", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="cache_axi_0", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_1", .next_ptr=nullptr, .id=22, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_2", .next_ptr=nullptr, .id=23, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_3", .next_ptr=nullptr, .id=24, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_parity_0", .next_ptr=nullptr, .id=25, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_1", .next_ptr=nullptr, .id=26, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_2", .next_ptr=nullptr, .id=27, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_3", .next_ptr=nullptr, .id=28, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },

	} };
intr_reg_t pct_mpu_2_int_info = {  .name="pct.mpu[2].int_info", .addr=0x64e8640, .reg_type=0, .id=276, .field_count=8, .fields=
	{
		{  .name="trace_full_0", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_1", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_2", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="mpu_stop_0", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_1", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_2", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_3", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },

	} };
intr_reg_t pct_mpu_2_int_groups_intreg = {  .name="pct.mpu[2].int_groups.intreg", .addr=0x64e8620, .reg_type=1, .id=277, .field_count=2, .fields=
	{
		{  .name="int_err", .next_ptr=&pct_mpu_2_int_err, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_info", .next_ptr=&pct_mpu_2_int_info, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t pp_pp_port_c_3_int_c_mac = {  .name="pp.pp.port_c[3].int_c_mac", .addr=0x70171b0, .reg_type=0, .id=164, .field_count=19, .fields=
	{
		{  .name="link_dn2up", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="link_up2dn", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="sec_bus_rst", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="rst_up2dn", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="rst_dn2up", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="portgate_open2close", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="ltssm_st_changed", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="sec_busnum_changed", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="rc_pme", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="rc_aerr", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="rc_serr", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="rc_hpe", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="rc_eq_req", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="rc_dpc", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="pm_turnoff", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="txbfr_overflow", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_FATAL, .desc="Fatal error, try to reproduce in lab and debug the configuration settings using PCIE Analyzer" },
		{  .name="rxtlp_err", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="" },
		{  .name="tl_flr_req", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="rc_legacy_intpin_changed", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t pp_pp_port_c_3_int_c_ecc = {  .name="pp.pp.port_c[3].int_c_ecc", .addr=0x70171c0, .reg_type=0, .id=165, .field_count=8, .fields=
	{
		{  .name="rxbuf_0_uncorrectable", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="rxbuf_1_uncorrectable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="rxbuf_2_uncorrectable", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="rxbuf_3_uncorrectable", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="rxbuf_0_correctable", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="rxbuf_1_correctable", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="rxbuf_2_correctable", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="rxbuf_3_correctable", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },

	} };
intr_reg_t pp_pp_port_c_3_int_groups_intreg = {  .name="pp.pp.port_c[3].int_groups.intreg", .addr=0x70171a0, .reg_type=1, .id=166, .field_count=2, .fields=
	{
		{  .name="int_c_mac", .next_ptr=&pp_pp_port_c_3_int_c_mac, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_c_ecc", .next_ptr=&pp_pp_port_c_3_int_c_ecc, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t ms_em_int_groups_intreg = {  .name="ms.em.int_groups.intreg", .addr=0x6a900090, .reg_type=1, .id=476, .field_count=1, .fields=
	{
		{  .name="axi", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t intr_intr_int_intr_ecc = {  .name="intr.intr.int_intr_ecc", .addr=0x6080080, .reg_type=0, .id=81, .field_count=10, .fields=
	{
		{  .name="intr_state_uncorrectable", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="intr_state_correctable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="intr_pba_cfg_uncorrectable", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="intr_pba_cfg_correctable", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="intr_coalesce_uncorrectable", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="intr_coalesce_correctable", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="intr_legacy_fifo_overrun", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_FATAL, .desc="Fatal error, try to reproduce in lab and debug the configuration settings using PCIE Analyzer" },
		{  .name="int_credit_positive_after_return", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_FATAL, .desc="" },
		{  .name="int_credits_max_debug_threshold", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_FATAL, .desc="Info only, no action" },
		{  .name="intr_bresp_err", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="" },

	} };
intr_reg_t intr_intr_int_groups_intreg = {  .name="intr.intr.int_groups.intreg", .addr=0x6080070, .reg_type=1, .id=82, .field_count=1, .fields=
	{
		{  .name="int_intr_ecc", .next_ptr=&intr_intr_int_intr_ecc, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t sge_mpu_2_int_err = {  .name="sge.mpu[2].int_err", .addr=0x36a8630, .reg_type=0, .id=111, .field_count=27, .fields=
	{
		{  .name="results_mismatch", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="mask this interrupt, not fully implemented" },
		{  .name="sdp_mem_uncorrectable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="sdp_mem_correctable", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="illegal_op_0", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_1", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_2", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_3", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="max_inst_0", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_1", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_2", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_3", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="phvwr_0", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_1", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_2", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_3", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="write_err_0", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_1", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_2", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_3", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="cache_axi_0", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_1", .next_ptr=nullptr, .id=22, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_2", .next_ptr=nullptr, .id=23, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_3", .next_ptr=nullptr, .id=24, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_parity_0", .next_ptr=nullptr, .id=25, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_1", .next_ptr=nullptr, .id=26, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_2", .next_ptr=nullptr, .id=27, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_3", .next_ptr=nullptr, .id=28, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },

	} };
intr_reg_t sge_mpu_2_int_info = {  .name="sge.mpu[2].int_info", .addr=0x36a8640, .reg_type=0, .id=112, .field_count=8, .fields=
	{
		{  .name="trace_full_0", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_1", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_2", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="mpu_stop_0", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_1", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_2", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_3", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },

	} };
intr_reg_t sge_mpu_2_int_groups_intreg = {  .name="sge.mpu[2].int_groups.intreg", .addr=0x36a8620, .reg_type=1, .id=113, .field_count=2, .fields=
	{
		{  .name="int_err", .next_ptr=&sge_mpu_2_int_err, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_info", .next_ptr=&sge_mpu_2_int_info, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t sge_te_2_int_err = {  .name="sge.te[2].int_err", .addr=0x3542440, .reg_type=0, .id=93, .field_count=20, .fields=
	{
		{  .name="miss_sop", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="previous stage error" },
		{  .name="miss_eop", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="previous stage error" },
		{  .name="phv_max_size", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="invalid" },
		{  .name="spurious_axi_rsp", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="spurious_tcam_rsp", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_FATAL, .desc="bad tcam response" },
		{  .name="te2mpu_timeout", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="impossible, should be disabled" },
		{  .name="axi_rdrsp_err", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="axi_bad_read", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="tcam_req_idx_fifo", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="tcam_rsp_idx_fifo", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="mpu_req_idx_fifo", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="axi_req_idx_fifo", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="proc_tbl_vld_wo_proc", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend_wo_wb", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend1_wo_pend0", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="both_pend_down", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend_wo_proc_down", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="both_pend_went_up", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="loaded_but_no_proc", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="loaded_but_no_proc_tbl_vld", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },

	} };
intr_reg_t sge_te_2_int_info = {  .name="sge.te[2].int_info", .addr=0x3542450, .reg_type=0, .id=94, .field_count=17, .fields=
	{
		{  .name="profile_cam_hit0", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit1", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit2", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit4", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit5", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit6", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit7", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit8", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit9", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit10", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit11", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit12", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit13", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit14", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit15", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_miss", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t sge_te_2_int_groups_intreg = {  .name="sge.te[2].int_groups.intreg", .addr=0x3542430, .reg_type=1, .id=95, .field_count=2, .fields=
	{
		{  .name="int_err", .next_ptr=&sge_te_2_int_err, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_info", .next_ptr=&sge_te_2_int_info, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t pp_pp_port_c_6_int_c_mac = {  .name="pp.pp.port_c[6].int_c_mac", .addr=0x701d1b0, .reg_type=0, .id=173, .field_count=19, .fields=
	{
		{  .name="link_dn2up", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="link_up2dn", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="sec_bus_rst", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="rst_up2dn", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="rst_dn2up", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="portgate_open2close", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="ltssm_st_changed", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="sec_busnum_changed", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="rc_pme", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="rc_aerr", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="rc_serr", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="rc_hpe", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="rc_eq_req", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="rc_dpc", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="pm_turnoff", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="txbfr_overflow", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_FATAL, .desc="Fatal error, try to reproduce in lab and debug the configuration settings using PCIE Analyzer" },
		{  .name="rxtlp_err", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="" },
		{  .name="tl_flr_req", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="rc_legacy_intpin_changed", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t pp_pp_port_c_6_int_c_ecc = {  .name="pp.pp.port_c[6].int_c_ecc", .addr=0x701d1c0, .reg_type=0, .id=174, .field_count=8, .fields=
	{
		{  .name="rxbuf_0_uncorrectable", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="rxbuf_1_uncorrectable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="rxbuf_2_uncorrectable", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="rxbuf_3_uncorrectable", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="rxbuf_0_correctable", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="rxbuf_1_correctable", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="rxbuf_2_correctable", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="rxbuf_3_correctable", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },

	} };
intr_reg_t pp_pp_port_c_6_int_groups_intreg = {  .name="pp.pp.port_c[6].int_groups.intreg", .addr=0x701d1a0, .reg_type=1, .id=175, .field_count=2, .fields=
	{
		{  .name="int_c_mac", .next_ptr=&pp_pp_port_c_6_int_c_mac, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_c_ecc", .next_ptr=&pp_pp_port_c_6_int_c_ecc, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t sge_mpu_0_int_err = {  .name="sge.mpu[0].int_err", .addr=0x3688630, .reg_type=0, .id=105, .field_count=27, .fields=
	{
		{  .name="results_mismatch", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="mask this interrupt, not fully implemented" },
		{  .name="sdp_mem_uncorrectable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="sdp_mem_correctable", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="illegal_op_0", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_1", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_2", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_3", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="max_inst_0", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_1", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_2", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_3", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="phvwr_0", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_1", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_2", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_3", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="write_err_0", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_1", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_2", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_3", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="cache_axi_0", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_1", .next_ptr=nullptr, .id=22, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_2", .next_ptr=nullptr, .id=23, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_3", .next_ptr=nullptr, .id=24, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_parity_0", .next_ptr=nullptr, .id=25, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_1", .next_ptr=nullptr, .id=26, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_2", .next_ptr=nullptr, .id=27, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_3", .next_ptr=nullptr, .id=28, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },

	} };
intr_reg_t sge_mpu_0_int_info = {  .name="sge.mpu[0].int_info", .addr=0x3688640, .reg_type=0, .id=106, .field_count=8, .fields=
	{
		{  .name="trace_full_0", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_1", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_2", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="mpu_stop_0", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_1", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_2", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_3", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },

	} };
intr_reg_t sge_mpu_0_int_groups_intreg = {  .name="sge.mpu[0].int_groups.intreg", .addr=0x3688620, .reg_type=1, .id=107, .field_count=2, .fields=
	{
		{  .name="int_err", .next_ptr=&sge_mpu_0_int_err, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_info", .next_ptr=&sge_mpu_0_int_info, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t pct_te_4_int_err = {  .name="pct.te[4].int_err", .addr=0x63c2440, .reg_type=0, .id=257, .field_count=20, .fields=
	{
		{  .name="miss_sop", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="previous stage error" },
		{  .name="miss_eop", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="previous stage error" },
		{  .name="phv_max_size", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="invalid" },
		{  .name="spurious_axi_rsp", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="spurious_tcam_rsp", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_FATAL, .desc="bad tcam response" },
		{  .name="te2mpu_timeout", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="impossible, should be disabled" },
		{  .name="axi_rdrsp_err", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="axi_bad_read", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="tcam_req_idx_fifo", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="tcam_rsp_idx_fifo", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="mpu_req_idx_fifo", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="axi_req_idx_fifo", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="proc_tbl_vld_wo_proc", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend_wo_wb", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend1_wo_pend0", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="both_pend_down", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend_wo_proc_down", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="both_pend_went_up", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="loaded_but_no_proc", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="loaded_but_no_proc_tbl_vld", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },

	} };
intr_reg_t pct_te_4_int_info = {  .name="pct.te[4].int_info", .addr=0x63c2450, .reg_type=0, .id=258, .field_count=17, .fields=
	{
		{  .name="profile_cam_hit0", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit1", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit2", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit4", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit5", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit6", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit7", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit8", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit9", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit10", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit11", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit12", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit13", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit14", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit15", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_miss", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t pct_te_4_int_groups_intreg = {  .name="pct.te[4].int_groups.intreg", .addr=0x63c2430, .reg_type=1, .id=259, .field_count=2, .fields=
	{
		{  .name="int_err", .next_ptr=&pct_te_4_int_err, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_info", .next_ptr=&pct_te_4_int_info, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t pcr_te_1_int_err = {  .name="pcr.te[1].int_err", .addr=0x6262440, .reg_type=0, .id=196, .field_count=20, .fields=
	{
		{  .name="miss_sop", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="previous stage error" },
		{  .name="miss_eop", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="previous stage error" },
		{  .name="phv_max_size", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="invalid" },
		{  .name="spurious_axi_rsp", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="spurious_tcam_rsp", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_FATAL, .desc="bad tcam response" },
		{  .name="te2mpu_timeout", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="impossible, should be disabled" },
		{  .name="axi_rdrsp_err", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="axi_bad_read", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="tcam_req_idx_fifo", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="tcam_rsp_idx_fifo", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="mpu_req_idx_fifo", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="axi_req_idx_fifo", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="proc_tbl_vld_wo_proc", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend_wo_wb", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend1_wo_pend0", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="both_pend_down", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend_wo_proc_down", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="both_pend_went_up", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="loaded_but_no_proc", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="loaded_but_no_proc_tbl_vld", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },

	} };
intr_reg_t pcr_te_1_int_info = {  .name="pcr.te[1].int_info", .addr=0x6262450, .reg_type=0, .id=197, .field_count=17, .fields=
	{
		{  .name="profile_cam_hit0", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit1", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit2", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit4", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit5", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit6", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit7", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit8", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit9", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit10", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit11", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit12", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit13", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit14", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit15", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_miss", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t pcr_te_1_int_groups_intreg = {  .name="pcr.te[1].int_groups.intreg", .addr=0x6262430, .reg_type=1, .id=198, .field_count=2, .fields=
	{
		{  .name="int_err", .next_ptr=&pcr_te_1_int_err, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_info", .next_ptr=&pcr_te_1_int_info, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t mc_mc_5_mch_int_mc = {  .name="mc.mc[5].mch.int_mc", .addr=0x6a600060, .reg_type=0, .id=416, .field_count=2, .fields=
	{
		{  .name="ecc_1bit_thresh_ps1", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_ERR, .desc="" },
		{  .name="ecc_1bit_thresh_ps0", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="" },

	} };
intr_reg_t mc_mc_5_mch_int_groups_intreg = {  .name="mc.mc[5].mch.int_groups.intreg", .addr=0x6a600050, .reg_type=1, .id=417, .field_count=1, .fields=
	{
		{  .name="int_mc", .next_ptr=&mc_mc_5_mch_int_mc, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t pcr_te_2_int_err = {  .name="pcr.te[2].int_err", .addr=0x6282440, .reg_type=0, .id=199, .field_count=20, .fields=
	{
		{  .name="miss_sop", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="previous stage error" },
		{  .name="miss_eop", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="previous stage error" },
		{  .name="phv_max_size", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="invalid" },
		{  .name="spurious_axi_rsp", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="spurious_tcam_rsp", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_FATAL, .desc="bad tcam response" },
		{  .name="te2mpu_timeout", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="impossible, should be disabled" },
		{  .name="axi_rdrsp_err", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="axi_bad_read", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="tcam_req_idx_fifo", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="tcam_rsp_idx_fifo", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="mpu_req_idx_fifo", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="axi_req_idx_fifo", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="proc_tbl_vld_wo_proc", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend_wo_wb", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend1_wo_pend0", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="both_pend_down", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend_wo_proc_down", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="both_pend_went_up", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="loaded_but_no_proc", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="loaded_but_no_proc_tbl_vld", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },

	} };
intr_reg_t pcr_te_2_int_info = {  .name="pcr.te[2].int_info", .addr=0x6282450, .reg_type=0, .id=200, .field_count=17, .fields=
	{
		{  .name="profile_cam_hit0", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit1", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit2", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit4", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit5", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit6", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit7", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit8", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit9", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit10", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit11", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit12", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit13", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit14", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit15", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_miss", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t pcr_te_2_int_groups_intreg = {  .name="pcr.te[2].int_groups.intreg", .addr=0x6282430, .reg_type=1, .id=201, .field_count=2, .fields=
	{
		{  .name="int_err", .next_ptr=&pcr_te_2_int_err, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_info", .next_ptr=&pcr_te_2_int_info, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t pm_pbm_int_ecc_col0 = {  .name="pm.pbm.int_ecc_col0", .addr=0x1080030, .reg_type=0, .id=341, .field_count=2, .fields=
	{
		{  .name="uncorrectable", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_HW_RMA, .desc="Hardware Error" },
		{  .name="correctable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },

	} };
intr_reg_t pm_pbm_int_ecc_col1 = {  .name="pm.pbm.int_ecc_col1", .addr=0x1080110, .reg_type=0, .id=342, .field_count=2, .fields=
	{
		{  .name="uncorrectable", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_HW_RMA, .desc="Hardware Error" },
		{  .name="correctable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },

	} };
intr_reg_t pm_pbm_int_ecc_col2 = {  .name="pm.pbm.int_ecc_col2", .addr=0x1080210, .reg_type=0, .id=343, .field_count=2, .fields=
	{
		{  .name="uncorrectable", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_HW_RMA, .desc="Hardware Error" },
		{  .name="correctable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },

	} };
intr_reg_t pm_pbm_int_ecc_col3 = {  .name="pm.pbm.int_ecc_col3", .addr=0x1080310, .reg_type=0, .id=344, .field_count=2, .fields=
	{
		{  .name="uncorrectable", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_HW_RMA, .desc="Hardware Error" },
		{  .name="correctable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },

	} };
intr_reg_t pm_pbm_int_ecc_col4 = {  .name="pm.pbm.int_ecc_col4", .addr=0x1080410, .reg_type=0, .id=345, .field_count=2, .fields=
	{
		{  .name="uncorrectable", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_HW_RMA, .desc="Hardware Error" },
		{  .name="correctable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },

	} };
intr_reg_t pm_pbm_int_groups_intreg = {  .name="pm.pbm.int_groups.intreg", .addr=0x1080010, .reg_type=1, .id=346, .field_count=5, .fields=
	{
		{  .name="int_ecc_col0", .next_ptr=&pm_pbm_int_ecc_col0, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_ecc_col1", .next_ptr=&pm_pbm_int_ecc_col1, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_ecc_col2", .next_ptr=&pm_pbm_int_ecc_col2, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_ecc_col3", .next_ptr=&pm_pbm_int_ecc_col3, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_ecc_col4", .next_ptr=&pm_pbm_int_ecc_col4, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t ms_ms_int_ms = {  .name="ms.ms.int_ms", .addr=0x6a001060, .reg_type=0, .id=443, .field_count=27, .fields=
	{
		{  .name="sbus_err", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_ERR, .desc="Software Error" },
		{  .name="rei_err", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_HW_RMA, .desc="Hardware Error" },
		{  .name="rei_pll_err", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_HW_RMA, .desc="Hardware Error" },
		{  .name="pk_efuse_init_read_timeout", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_HW_RMA, .desc="Hardware Error" },
		{  .name="pk_efuse_cpu_read_timeout", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_HW_RMA, .desc="Hardware Error" },
		{  .name="pk_efuse_cpu_burn_timeout", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_HW_RMA, .desc="Hardware Error" },
		{  .name="pk_efuse_burn_imm_timeout", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_HW_RMA, .desc="Hardware Error" },
		{  .name="ds16_efuse_init_read_timeout", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_HW_RMA, .desc="Hardware Error" },
		{  .name="ds16_efuse_cpu_read_timeout", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_HW_RMA, .desc="Hardware Error" },
		{  .name="ahb_axi_err", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="Software Error" },
		{  .name="emmc_pre_axi_err", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_ERR, .desc="Software Error" },
		{  .name="fl_axi_err", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="Software Error" },
		{  .name="ms_esec_mb_pre_axi_err", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="Software Error" },
		{  .name="msap_pre_axi_err", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="Software Error" },
		{  .name="nxms_a13_axi_err", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_ERR, .desc="Software Error" },
		{  .name="rbm_axi_err", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="Software Error" },
		{  .name="ssram_axi_err", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="Software Error" },
		{  .name="ahb_axi_werr", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_ERR, .desc="Software Error" },
		{  .name="emmc_pre_axi_werr", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_ERR, .desc="Software Error" },
		{  .name="fl_axi_werr", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_ERR, .desc="Software Error" },
		{  .name="ms_esec_mb_pre_axi_werr", .next_ptr=nullptr, .id=22, .severity=INTR_SEV_TYPE_ERR, .desc="Software Error" },
		{  .name="msap_pre_axi_werr", .next_ptr=nullptr, .id=23, .severity=INTR_SEV_TYPE_ERR, .desc="Software Error" },
		{  .name="nxms_a13_axi_werr", .next_ptr=nullptr, .id=24, .severity=INTR_SEV_TYPE_ERR, .desc="Software Error" },
		{  .name="rbm_axi_werr", .next_ptr=nullptr, .id=25, .severity=INTR_SEV_TYPE_ERR, .desc="Software Error" },
		{  .name="ssram_axi_werr", .next_ptr=nullptr, .id=26, .severity=INTR_SEV_TYPE_ERR, .desc="Software Error" },
		{  .name="addr_filter_write", .next_ptr=nullptr, .id=27, .severity=INTR_SEV_TYPE_ERR, .desc="Software Error" },
		{  .name="addr_filter_read", .next_ptr=nullptr, .id=28, .severity=INTR_SEV_TYPE_ERR, .desc="Software Error" },

	} };
intr_reg_t ms_ms_int_misc = {  .name="ms.ms.int_misc", .addr=0x6a001070, .reg_type=0, .id=444, .field_count=22, .fields=
	{
		{  .name="qspi_ram_ecc_uncorrectable", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_HW_RMA, .desc="Hardware Error" },
		{  .name="qspi_ram_ecc_correctable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="Hardware Error" },
		{  .name="elam_cap_ecc_uncorrectable", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_HW_RMA, .desc="Hardware Error" },
		{  .name="elam_cap_ecc_correctable", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="ahb_esec_data_ram_ecc_uncorrectable", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_HW_RMA, .desc="Hardware Error" },
		{  .name="ahb_esec_data_ram_ecc_correctable", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="ahb_esec_esystem_ram_ecc_uncorrectable", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_HW_RMA, .desc="Hardware Error" },
		{  .name="ahb_esec_esystem_ram_ecc_correctable", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="bl2_ram_ecc_uncorrectable", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_HW_RMA, .desc="Hardware Error" },
		{  .name="bl2_ram_ecc_correctable", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="int_wr_stall_hit0", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_ERR, .desc="Info only, no action" },
		{  .name="int_rd_stall_hit0", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="Info only, no action" },
		{  .name="int_wr_stall_hit1", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="Info only, no action" },
		{  .name="int_rd_stall_hit1", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="Info only, no action" },
		{  .name="int_wr_stall_hit2", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_ERR, .desc="Info only, no action" },
		{  .name="int_rd_stall_hit2", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="Info only, no action" },
		{  .name="int_wr_full0", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="Hardware Error" },
		{  .name="int_rd_full0", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_ERR, .desc="Hardware Error" },
		{  .name="int_wr_full1", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_ERR, .desc="Hardware Error" },
		{  .name="int_rd_full1", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_ERR, .desc="Hardware Error" },
		{  .name="int_wr_full2", .next_ptr=nullptr, .id=22, .severity=INTR_SEV_TYPE_ERR, .desc="Hardware Error" },
		{  .name="int_rd_full2", .next_ptr=nullptr, .id=23, .severity=INTR_SEV_TYPE_ERR, .desc="Hardware Error" },

	} };
intr_reg_t ms_ms_int_esecure = {  .name="ms.ms.int_esecure", .addr=0x6a001080, .reg_type=0, .id=445, .field_count=2, .fields=
	{
		{  .name="mb_rxint", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="mb_txint", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t ms_ms_int_prp1 = {  .name="ms.ms.int_prp1", .addr=0x6a001090, .reg_type=0, .id=446, .field_count=7, .fields=
	{
		{  .name="read", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_ERR, .desc="Software Error" },
		{  .name="security", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="Software Error" },
		{  .name="decode", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="Software Error" },
		{  .name="ack_timeout", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="stall_timeout", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="byte_read", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="byte_write", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t ms_ms_int_prp2 = {  .name="ms.ms.int_prp2", .addr=0x6a0010a0, .reg_type=0, .id=447, .field_count=7, .fields=
	{
		{  .name="read", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_ERR, .desc="Software Error" },
		{  .name="security", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="Software Error" },
		{  .name="decode", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="Software Error" },
		{  .name="ack_timeout", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="stall_timeout", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="byte_read", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="byte_write", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t ms_ms_int_prp3 = {  .name="ms.ms.int_prp3", .addr=0x6a0010b0, .reg_type=0, .id=448, .field_count=7, .fields=
	{
		{  .name="read", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_ERR, .desc="Software Error" },
		{  .name="security", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="Software Error" },
		{  .name="decode", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="Software Error" },
		{  .name="ack_timeout", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="stall_timeout", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="byte_read", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="byte_write", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t ms_ms_int_prp4 = {  .name="ms.ms.int_prp4", .addr=0x6a0010c0, .reg_type=0, .id=449, .field_count=7, .fields=
	{
		{  .name="read", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_ERR, .desc="Software Error" },
		{  .name="security", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="Software Error" },
		{  .name="decode", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="Software Error" },
		{  .name="ack_timeout", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="stall_timeout", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="byte_read", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="byte_write", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t ms_ms_int_prp5 = {  .name="ms.ms.int_prp5", .addr=0x6a0010d0, .reg_type=0, .id=450, .field_count=7, .fields=
	{
		{  .name="read", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_ERR, .desc="Software Error" },
		{  .name="security", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="Software Error" },
		{  .name="decode", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="Software Error" },
		{  .name="ack_timeout", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="stall_timeout", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="byte_read", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="byte_write", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t ms_ms_int_gic0 = {  .name="ms.ms.int_gic0", .addr=0x6a0010e0, .reg_type=0, .id=451, .field_count=1, .fields=
	{
		{  .name="msar_int_lvl", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t ms_ms_int_gic1 = {  .name="ms.ms.int_gic1", .addr=0x6a0010f0, .reg_type=0, .id=452, .field_count=1, .fields=
	{
		{  .name="msar_int_lvl", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t ms_ms_int_gic2 = {  .name="ms.ms.int_gic2", .addr=0x6a001100, .reg_type=0, .id=453, .field_count=1, .fields=
	{
		{  .name="msar_int_lvl", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t ms_ms_int_gic3 = {  .name="ms.ms.int_gic3", .addr=0x6a001110, .reg_type=0, .id=454, .field_count=1, .fields=
	{
		{  .name="msar_int_lvl", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t ms_ms_int_gic4 = {  .name="ms.ms.int_gic4", .addr=0x6a001120, .reg_type=0, .id=455, .field_count=1, .fields=
	{
		{  .name="msar_int_lvl", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t ms_ms_int_gic5 = {  .name="ms.ms.int_gic5", .addr=0x6a001130, .reg_type=0, .id=456, .field_count=1, .fields=
	{
		{  .name="msar_int_lvl", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t ms_ms_int_gic6 = {  .name="ms.ms.int_gic6", .addr=0x6a001140, .reg_type=0, .id=457, .field_count=1, .fields=
	{
		{  .name="msar_int_lvl", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t ms_ms_int_gic7 = {  .name="ms.ms.int_gic7", .addr=0x6a001150, .reg_type=0, .id=458, .field_count=1, .fields=
	{
		{  .name="msar_int_lvl", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t ms_ms_int_gic8 = {  .name="ms.ms.int_gic8", .addr=0x6a001160, .reg_type=0, .id=459, .field_count=1, .fields=
	{
		{  .name="msar_int_lvl", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t ms_ms_int_gic9 = {  .name="ms.ms.int_gic9", .addr=0x6a001170, .reg_type=0, .id=460, .field_count=1, .fields=
	{
		{  .name="msar_int_lvl", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t ms_ms_int_gic10 = {  .name="ms.ms.int_gic10", .addr=0x6a001180, .reg_type=0, .id=461, .field_count=1, .fields=
	{
		{  .name="msar_int_lvl", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t ms_ms_int_gic11 = {  .name="ms.ms.int_gic11", .addr=0x6a001190, .reg_type=0, .id=462, .field_count=1, .fields=
	{
		{  .name="msar_int_lvl", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t ms_ms_int_gic12 = {  .name="ms.ms.int_gic12", .addr=0x6a0011a0, .reg_type=0, .id=463, .field_count=1, .fields=
	{
		{  .name="msar_int_lvl", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t ms_ms_int_gic13 = {  .name="ms.ms.int_gic13", .addr=0x6a0011b0, .reg_type=0, .id=464, .field_count=1, .fields=
	{
		{  .name="msar_int_lvl", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t ms_ms_int_gic14 = {  .name="ms.ms.int_gic14", .addr=0x6a0011c0, .reg_type=0, .id=465, .field_count=1, .fields=
	{
		{  .name="msar_int_lvl", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t ms_ms_int_gic15 = {  .name="ms.ms.int_gic15", .addr=0x6a0011d0, .reg_type=0, .id=466, .field_count=1, .fields=
	{
		{  .name="msar_int_lvl", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t ms_ms_int_gic16 = {  .name="ms.ms.int_gic16", .addr=0x6a0011e0, .reg_type=0, .id=467, .field_count=1, .fields=
	{
		{  .name="msar_int_lvl", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t ms_ms_int_gic17 = {  .name="ms.ms.int_gic17", .addr=0x6a0011f0, .reg_type=0, .id=468, .field_count=1, .fields=
	{
		{  .name="msar_int_lvl", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t ms_ms_int_gic18 = {  .name="ms.ms.int_gic18", .addr=0x6a001200, .reg_type=0, .id=469, .field_count=1, .fields=
	{
		{  .name="msar_int_lvl", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t ms_ms_int_gic19 = {  .name="ms.ms.int_gic19", .addr=0x6a001210, .reg_type=0, .id=470, .field_count=1, .fields=
	{
		{  .name="msar_int_lvl", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t ms_ms_int_gic20 = {  .name="ms.ms.int_gic20", .addr=0x6a001220, .reg_type=0, .id=471, .field_count=1, .fields=
	{
		{  .name="msar_int_lvl", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t ms_ms_int_gic21 = {  .name="ms.ms.int_gic21", .addr=0x6a001230, .reg_type=0, .id=472, .field_count=1, .fields=
	{
		{  .name="msar_int_lvl", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t ms_ms_int_gic22 = {  .name="ms.ms.int_gic22", .addr=0x6a001240, .reg_type=0, .id=473, .field_count=1, .fields=
	{
		{  .name="msar_int_lvl", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t ms_ms_int_gic23 = {  .name="ms.ms.int_gic23", .addr=0x6a001250, .reg_type=0, .id=474, .field_count=1, .fields=
	{
		{  .name="msar_int_lvl", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t ms_ms_int_groups_intreg = {  .name="ms.ms.int_groups.intreg", .addr=0x6a001050, .reg_type=1, .id=475, .field_count=32, .fields=
	{
		{  .name="int_ms", .next_ptr=&ms_ms_int_ms, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_misc", .next_ptr=&ms_ms_int_misc, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_esecure", .next_ptr=&ms_ms_int_esecure, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_prp1", .next_ptr=&ms_ms_int_prp1, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_prp2", .next_ptr=&ms_ms_int_prp2, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_prp3", .next_ptr=&ms_ms_int_prp3, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_prp4", .next_ptr=&ms_ms_int_prp4, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_prp5", .next_ptr=&ms_ms_int_prp5, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_gic0", .next_ptr=&ms_ms_int_gic0, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_gic1", .next_ptr=&ms_ms_int_gic1, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_gic2", .next_ptr=&ms_ms_int_gic2, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_gic3", .next_ptr=&ms_ms_int_gic3, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_gic4", .next_ptr=&ms_ms_int_gic4, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_gic5", .next_ptr=&ms_ms_int_gic5, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_gic6", .next_ptr=&ms_ms_int_gic6, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_gic7", .next_ptr=&ms_ms_int_gic7, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_gic8", .next_ptr=&ms_ms_int_gic8, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_gic9", .next_ptr=&ms_ms_int_gic9, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_gic10", .next_ptr=&ms_ms_int_gic10, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_gic11", .next_ptr=&ms_ms_int_gic11, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_gic12", .next_ptr=&ms_ms_int_gic12, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_gic13", .next_ptr=&ms_ms_int_gic13, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_gic14", .next_ptr=&ms_ms_int_gic14, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_gic15", .next_ptr=&ms_ms_int_gic15, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_gic16", .next_ptr=&ms_ms_int_gic16, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_gic17", .next_ptr=&ms_ms_int_gic17, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_gic18", .next_ptr=&ms_ms_int_gic18, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_gic19", .next_ptr=&ms_ms_int_gic19, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_gic20", .next_ptr=&ms_ms_int_gic20, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_gic21", .next_ptr=&ms_ms_int_gic21, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_gic22", .next_ptr=&ms_ms_int_gic22, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_gic23", .next_ptr=&ms_ms_int_gic23, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t mc_mc_3_mch_int_mc = {  .name="mc.mc[3].mch.int_mc", .addr=0x6a400060, .reg_type=0, .id=408, .field_count=2, .fields=
	{
		{  .name="ecc_1bit_thresh_ps1", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_ERR, .desc="" },
		{  .name="ecc_1bit_thresh_ps0", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="" },

	} };
intr_reg_t mc_mc_3_mch_int_groups_intreg = {  .name="mc.mc[3].mch.int_groups.intreg", .addr=0x6a400050, .reg_type=1, .id=409, .field_count=1, .fields=
	{
		{  .name="int_mc", .next_ptr=&mc_mc_3_mch_int_mc, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t ssi_pics_picc_int_picc = {  .name="ssi.pics.picc.int_picc", .addr=0x25a0020, .reg_type=0, .id=354, .field_count=7, .fields=
	{
		{  .name="uncorrectable_ecc", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="correctable_ecc", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="cache_stg_awlen_err", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_FATAL, .desc="HBM access fatal error" },
		{  .name="cache_hbm_rresp_slverr", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_FATAL, .desc="HBM access fatal error" },
		{  .name="cache_hbm_rresp_decerr", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_FATAL, .desc="HBM access fatal error" },
		{  .name="cache_hbm_bresp_slverr", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_FATAL, .desc="HBM access fatal error" },
		{  .name="cache_hbm_bresp_decerr", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_FATAL, .desc="HBM access fatal error" },

	} };
intr_reg_t ssi_pics_picc_int_groups_intreg = {  .name="ssi.pics.picc.int_groups.intreg", .addr=0x25a0010, .reg_type=1, .id=355, .field_count=1, .fields=
	{
		{  .name="int_picc", .next_ptr=&ssi_pics_picc_int_picc, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t mc_mc_1_int_mc = {  .name="mc.mc[1].int_mc", .addr=0x6a280020, .reg_type=0, .id=398, .field_count=1, .fields=
	{
		{  .name="mch_int", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_ERR, .desc="" },

	} };
intr_reg_t mc_mc_1_int_groups_intreg = {  .name="mc.mc[1].int_groups.intreg", .addr=0x6a280010, .reg_type=1, .id=399, .field_count=1, .fields=
	{
		{  .name="int_mc", .next_ptr=&mc_mc_1_int_mc, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t sgi_te_4_int_err = {  .name="sgi.te[4].int_err", .addr=0x3642440, .reg_type=0, .id=51, .field_count=20, .fields=
	{
		{  .name="miss_sop", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="previous stage error" },
		{  .name="miss_eop", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="previous stage error" },
		{  .name="phv_max_size", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="invalid" },
		{  .name="spurious_axi_rsp", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="spurious_tcam_rsp", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_FATAL, .desc="bad tcam response" },
		{  .name="te2mpu_timeout", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="impossible, should be disabled" },
		{  .name="axi_rdrsp_err", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="axi_bad_read", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="tcam_req_idx_fifo", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="tcam_rsp_idx_fifo", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="mpu_req_idx_fifo", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="axi_req_idx_fifo", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="proc_tbl_vld_wo_proc", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend_wo_wb", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend1_wo_pend0", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="both_pend_down", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend_wo_proc_down", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="both_pend_went_up", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="loaded_but_no_proc", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="loaded_but_no_proc_tbl_vld", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },

	} };
intr_reg_t sgi_te_4_int_info = {  .name="sgi.te[4].int_info", .addr=0x3642450, .reg_type=0, .id=52, .field_count=17, .fields=
	{
		{  .name="profile_cam_hit0", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit1", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit2", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit4", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit5", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit6", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit7", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit8", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit9", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit10", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit11", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit12", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit13", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit14", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit15", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_miss", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t sgi_te_4_int_groups_intreg = {  .name="sgi.te[4].int_groups.intreg", .addr=0x3642430, .reg_type=1, .id=53, .field_count=2, .fields=
	{
		{  .name="int_err", .next_ptr=&sgi_te_4_int_err, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_info", .next_ptr=&sgi_te_4_int_info, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t pcr_mpu_7_int_err = {  .name="pcr.mpu[7].int_err", .addr=0x64b8630, .reg_type=0, .id=238, .field_count=27, .fields=
	{
		{  .name="results_mismatch", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="mask this interrupt, not fully implemented" },
		{  .name="sdp_mem_uncorrectable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="sdp_mem_correctable", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="illegal_op_0", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_1", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_2", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_3", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="max_inst_0", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_1", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_2", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_3", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="phvwr_0", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_1", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_2", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_3", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="write_err_0", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_1", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_2", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_3", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="cache_axi_0", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_1", .next_ptr=nullptr, .id=22, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_2", .next_ptr=nullptr, .id=23, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_3", .next_ptr=nullptr, .id=24, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_parity_0", .next_ptr=nullptr, .id=25, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_1", .next_ptr=nullptr, .id=26, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_2", .next_ptr=nullptr, .id=27, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_3", .next_ptr=nullptr, .id=28, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },

	} };
intr_reg_t pcr_mpu_7_int_info = {  .name="pcr.mpu[7].int_info", .addr=0x64b8640, .reg_type=0, .id=239, .field_count=8, .fields=
	{
		{  .name="trace_full_0", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_1", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_2", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="mpu_stop_0", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_1", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_2", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_3", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },

	} };
intr_reg_t pcr_mpu_7_int_groups_intreg = {  .name="pcr.mpu[7].int_groups.intreg", .addr=0x64b8620, .reg_type=1, .id=240, .field_count=2, .fields=
	{
		{  .name="int_err", .next_ptr=&pcr_mpu_7_int_err, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_info", .next_ptr=&pcr_mpu_7_int_info, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t pcr_mpu_5_int_err = {  .name="pcr.mpu[5].int_err", .addr=0x6498630, .reg_type=0, .id=232, .field_count=27, .fields=
	{
		{  .name="results_mismatch", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="mask this interrupt, not fully implemented" },
		{  .name="sdp_mem_uncorrectable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="sdp_mem_correctable", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="illegal_op_0", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_1", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_2", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_3", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="max_inst_0", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_1", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_2", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_3", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="phvwr_0", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_1", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_2", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_3", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="write_err_0", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_1", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_2", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_3", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="cache_axi_0", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_1", .next_ptr=nullptr, .id=22, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_2", .next_ptr=nullptr, .id=23, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_3", .next_ptr=nullptr, .id=24, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_parity_0", .next_ptr=nullptr, .id=25, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_1", .next_ptr=nullptr, .id=26, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_2", .next_ptr=nullptr, .id=27, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_3", .next_ptr=nullptr, .id=28, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },

	} };
intr_reg_t pcr_mpu_5_int_info = {  .name="pcr.mpu[5].int_info", .addr=0x6498640, .reg_type=0, .id=233, .field_count=8, .fields=
	{
		{  .name="trace_full_0", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_1", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_2", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="mpu_stop_0", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_1", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_2", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_3", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },

	} };
intr_reg_t pcr_mpu_5_int_groups_intreg = {  .name="pcr.mpu[5].int_groups.intreg", .addr=0x6498620, .reg_type=1, .id=234, .field_count=2, .fields=
	{
		{  .name="int_err", .next_ptr=&pcr_mpu_5_int_err, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_info", .next_ptr=&pcr_mpu_5_int_info, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t pct_mpu_5_int_err = {  .name="pct.mpu[5].int_err", .addr=0x6518630, .reg_type=0, .id=284, .field_count=27, .fields=
	{
		{  .name="results_mismatch", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="mask this interrupt, not fully implemented" },
		{  .name="sdp_mem_uncorrectable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="sdp_mem_correctable", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="illegal_op_0", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_1", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_2", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_3", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="max_inst_0", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_1", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_2", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_3", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="phvwr_0", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_1", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_2", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_3", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="write_err_0", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_1", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_2", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_3", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="cache_axi_0", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_1", .next_ptr=nullptr, .id=22, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_2", .next_ptr=nullptr, .id=23, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_3", .next_ptr=nullptr, .id=24, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_parity_0", .next_ptr=nullptr, .id=25, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_1", .next_ptr=nullptr, .id=26, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_2", .next_ptr=nullptr, .id=27, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_3", .next_ptr=nullptr, .id=28, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },

	} };
intr_reg_t pct_mpu_5_int_info = {  .name="pct.mpu[5].int_info", .addr=0x6518640, .reg_type=0, .id=285, .field_count=8, .fields=
	{
		{  .name="trace_full_0", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_1", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_2", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="mpu_stop_0", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_1", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_2", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_3", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },

	} };
intr_reg_t pct_mpu_5_int_groups_intreg = {  .name="pct.mpu[5].int_groups.intreg", .addr=0x6518620, .reg_type=1, .id=286, .field_count=2, .fields=
	{
		{  .name="int_err", .next_ptr=&pct_mpu_5_int_err, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_info", .next_ptr=&pct_mpu_5_int_info, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t pct_te_3_int_err = {  .name="pct.te[3].int_err", .addr=0x63a2440, .reg_type=0, .id=254, .field_count=20, .fields=
	{
		{  .name="miss_sop", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="previous stage error" },
		{  .name="miss_eop", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="previous stage error" },
		{  .name="phv_max_size", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="invalid" },
		{  .name="spurious_axi_rsp", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="spurious_tcam_rsp", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_FATAL, .desc="bad tcam response" },
		{  .name="te2mpu_timeout", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="impossible, should be disabled" },
		{  .name="axi_rdrsp_err", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="axi_bad_read", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="tcam_req_idx_fifo", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="tcam_rsp_idx_fifo", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="mpu_req_idx_fifo", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="axi_req_idx_fifo", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="proc_tbl_vld_wo_proc", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend_wo_wb", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend1_wo_pend0", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="both_pend_down", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend_wo_proc_down", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="both_pend_went_up", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="loaded_but_no_proc", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="loaded_but_no_proc_tbl_vld", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },

	} };
intr_reg_t pct_te_3_int_info = {  .name="pct.te[3].int_info", .addr=0x63a2450, .reg_type=0, .id=255, .field_count=17, .fields=
	{
		{  .name="profile_cam_hit0", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit1", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit2", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit4", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit5", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit6", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit7", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit8", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit9", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit10", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit11", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit12", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit13", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit14", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit15", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_miss", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t pct_te_3_int_groups_intreg = {  .name="pct.te[3].int_groups.intreg", .addr=0x63a2430, .reg_type=1, .id=256, .field_count=2, .fields=
	{
		{  .name="int_err", .next_ptr=&pct_te_3_int_err, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_info", .next_ptr=&pct_te_3_int_info, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t pr_pr_prd_int_ecc = {  .name="pr.pr.prd.int_ecc", .addr=0x6120020, .reg_type=0, .id=131, .field_count=4, .fields=
	{
		{  .name="rdata_mem_uncorrectable", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="rdata_mem_correctable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="pkt_mem_uncorrectable", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="pkt_mem_correctable", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },

	} };
intr_reg_t pr_pr_prd_int_fifo = {  .name="pr.pr.prd.int_fifo", .addr=0x6120030, .reg_type=0, .id=132, .field_count=12, .fields=
	{
		{  .name="wr_lat_ff_ovflow", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="rd_lat_ff_ovflow", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="wdata_ff_ovflow", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="rcv_stg_ff_ovflow", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="cmdflit_ff_ovflow", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="cmd_ff_ovflow", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="pkt_ff_ovflow", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="pkt_order_ff_ovflow", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="pkt_stg_ff_ovflow", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="wr_mem_ff_ovflow", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="dfence_ff_ovflow", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="ffence_ff_ovflow", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },

	} };
intr_reg_t pr_pr_prd_int_grp1 = {  .name="pr.pr.prd.int_grp1", .addr=0x6120040, .reg_type=0, .id=133, .field_count=22, .fields=
	{
		{  .name="rcv_phv_dma_ptr", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_ERR, .desc="software error. dma pointer points to a non-existing flit in PHV" },
		{  .name="rcv_phv_addr", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="software error. phv2mem or phv2pkt start/end address is not programmed correctly." },
		{  .name="rcv_exceed_16byte", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="software error. mem2mem_phv2mem or phv2mem with fence exceeded 16 bytes" },
		{  .name="rcv_phv_not_sop", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="rcv_pkt_order_ff_full", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="rcv_pend_phv_more_than_2", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="rcv_pend_phv_less", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="rcv_cmd_nop_eop", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="software error" },
		{  .name="rcv_cmd_out_not_sop", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="rcv_no_data_but_pkt2mem_cmd", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="software error. no_data bit is set in PHV, but it has pkt2mem command. " },
		{  .name="rcv_no_data_but_skip_cmd", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_ERR, .desc="software error. no_data bit is set in PHV, but it has skip command. " },
		{  .name="rcv_mem2pkt_seen", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="software error. mem2pkt command not expected in PRD" },
		{  .name="rcv_phv2pkt_seen", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="software error. phv2pkt command not expected in PRD" },
		{  .name="rcv_phv_eop_no_cmd_eop", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="software error. End of PHV reached, but cmdeop is not seen in any command" },
		{  .name="rcv_m2m_dst_not_seen", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_ERR, .desc="software error. mem2mem_dst command is expected right after mem2mem_src." },
		{  .name="rcv_m2m_src_not_seen", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="software error. mem2mem_dst command is seen without mem2mem_src before it." },
		{  .name="rdreq_invalid_cmd_seen", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="software error. invalid cmdtype seen in dma command" },
		{  .name="rdreq_mem2mem_psize_zero", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_ERR, .desc="software error. mem2mem psize field is zero" },
		{  .name="rdreq_m2m_phv2mem_exceed_16byte", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_ERR, .desc="software error. mem2mem_phv2mem exceeds 16 bytes" },
		{  .name="rdreq_phv2mem_fence_exceed_16byte", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_ERR, .desc="software error. phv2mem fence exceeds 16 bytes" },
		{  .name="rdreq_pkt2mem_psize_zero", .next_ptr=nullptr, .id=22, .severity=INTR_SEV_TYPE_ERR, .desc="software error. pkt2mem psize is zero" },
		{  .name="rdreq_skip_psize_zero", .next_ptr=nullptr, .id=23, .severity=INTR_SEV_TYPE_ERR, .desc="software error. skip command psize field iz zero" },

	} };
intr_reg_t pr_pr_prd_int_grp2 = {  .name="pr.pr.prd.int_grp2", .addr=0x6120050, .reg_type=0, .id=134, .field_count=16, .fields=
	{
		{  .name="wr_axi_rd_err_recovery", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="wr_axi_rd_resp", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="wr_not_enuf_pkt_bytes", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="software error. dma command trying to access more packet bytes than what's available in packet" },
		{  .name="wr_invalid_cmd", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Unexpected dma commands seen" },
		{  .name="wr_seq_id", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="software error. dma command and packet size out of sync causing seq_id error" },
		{  .name="wr_no_data_pkt_cmd", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="software error. no_data set in phv, but pkt command seen" },
		{  .name="rdrsp_axi", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="wrrsp_axi", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="pkt_not_sop", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="pkt_len_calc_len_mismatch", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="spurious_rd_resp", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_ERR, .desc="unexpected read response received. Check interrupts in other blocks." },
		{  .name="rdrsp_axi_id_out_of_range", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="spurious_wr_resp", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="unexpected read response received. Check interrupts in other blocks." },
		{  .name="wrreq_info_first_missing", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="software error can trigger this interrupt. Can happen with other interrupts. If no other interrupt, then this may be a hw error." },
		{  .name="wrreq_num_bytes_zero", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_ERR, .desc="software error can trigger this interrupt. Can happen with other interrupts. If no other interrupt, then this may be a hw error." },
		{  .name="wrreq_num_bytes_more_than_64", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="software error can trigger this interrupt. Can happen with other interrupts. If no other interrupt, then this may be a hw error." },

	} };
intr_reg_t pr_pr_prd_int_intf = {  .name="pr.pr.prd.int_intf", .addr=0x6120060, .reg_type=0, .id=135, .field_count=12, .fields=
	{
		{  .name="ps_pkt_err", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_ERR, .desc="Packet from PSP received with error bit. The error bit may be from buffer (PB). check interrupts in other blocks." },
		{  .name="ps_pkt_sop_err", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="ps_pkt_eop_err", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="ps_resub_pkt_err", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="Packet from PRD to PSP sent with error bit. The error might be from PSP originally or from buffer. Possible ecc error. Check interrupts in other blocks." },
		{  .name="ps_resub_pkt_sop_err", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="ps_resub_pkt_eop_err", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="ps_resub_phv_err", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="PHV from PRD to PSP sent with error bit. The error might be from STG originally. Possible ecc error. Check interrupts in other blocks." },
		{  .name="ps_resub_phv_sop_err", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="ps_resub_phv_eop_err", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="ma_err", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="PHV from STG received with error bit. Possible ecc error. Check interrupts in other blocks." },
		{  .name="ma_sop_err", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="ma_eop_err", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },

	} };
intr_reg_t pr_pr_prd_int_groups_intreg = {  .name="pr.pr.prd.int_groups.intreg", .addr=0x6120010, .reg_type=1, .id=136, .field_count=5, .fields=
	{
		{  .name="int_ecc", .next_ptr=&pr_pr_prd_int_ecc, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_fifo", .next_ptr=&pr_pr_prd_int_fifo, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_grp1", .next_ptr=&pr_pr_prd_int_grp1, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_grp2", .next_ptr=&pr_pr_prd_int_grp2, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_intf", .next_ptr=&pr_pr_prd_int_intf, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t pxb_pxb_int_tgt_ecc = {  .name="pxb.pxb.int_tgt_ecc", .addr=0x719a5a0, .reg_type=0, .id=83, .field_count=28, .fields=
	{
		{  .name="aximst_0_uncorrectable", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="aximst_0_correctable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="aximst_1_uncorrectable", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="aximst_1_correctable", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="aximst_2_uncorrectable", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="aximst_2_correctable", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="aximst_3_uncorrectable", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="aximst_3_correctable", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="aximst_4_uncorrectable", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="aximst_4_correctable", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="rxcrbfr_0_uncorrectable", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="rxcrbfr_0_correctable", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="rxcrbfr_1_uncorrectable", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="rxcrbfr_1_correctable", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="rxcrbfr_2_uncorrectable", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="rxcrbfr_2_correctable", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="rxcrbfr_3_uncorrectable", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="rxcrbfr_3_correctable", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="rxinfo_uncorrectable", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="rxinfo_correctable", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="cplst_uncorrectable", .next_ptr=nullptr, .id=22, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="cplst_correctable", .next_ptr=nullptr, .id=23, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="romask_uncorrectable", .next_ptr=nullptr, .id=24, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="romask_correctable", .next_ptr=nullptr, .id=25, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="pmr_uncorrectable", .next_ptr=nullptr, .id=26, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="pmr_correctable", .next_ptr=nullptr, .id=27, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="prt_uncorrectable", .next_ptr=nullptr, .id=28, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="prt_correctable", .next_ptr=nullptr, .id=29, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },

	} };
intr_reg_t pxb_pxb_int_itr_ecc = {  .name="pxb.pxb.int_itr_ecc", .addr=0x719a590, .reg_type=0, .id=84, .field_count=18, .fields=
	{
		{  .name="pcihdrt_uncorrectable", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="pcihdrt_correctable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="portmap_uncorrectable", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="portmap_correctable", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="wrhdr_uncorrectable", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="wrhdr_correctable", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="rdhdr_uncorrectable", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="rdhdr_correctable", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="wrbfr_0_uncorrectable", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="wrbfr_0_correctable", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="wrbfr_1_uncorrectable", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="wrbfr_1_correctable", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="wrbfr_2_uncorrectable", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="wrbfr_2_correctable", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="wrbfr_3_uncorrectable", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="wrbfr_3_correctable", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="cplbfr_uncorrectable", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="cplbfr_correctable", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },

	} };
intr_reg_t pxb_pxb_int_err = {  .name="pxb.pxb.int_err", .addr=0x719a5b0, .reg_type=0, .id=85, .field_count=20, .fields=
	{
		{  .name="cpl_ecrc", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_ERR, .desc="" },
		{  .name="cpl_rxbuf_err", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="Fatal error, try to reproduce in lab and debug the configuration settings using PCIE Analyzer" },
		{  .name="cpl_stat", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="" },
		{  .name="cpl_unexp", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="cpl_timeout", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_FATAL, .desc="Completion timeout for initiator requests, maybe link issue or host is hung or something fatal across pcie link" },
		{  .name="cpl_len", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="" },
		{  .name="cpl_poison", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="" },
		{  .name="cpl_lowaddr", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="" },
		{  .name="tgt_ind_rsp_unexp", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_ERR, .desc="" },
		{  .name="tgt_axi_rsp_unexp", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="tgt_axi_rsp_err", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="tgt_req_4k_err", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="" },
		{  .name="itr_req_bdfmiss", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="" },
		{  .name="itr_req_axi_unsupp", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="itr_req_msg_align_err", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_ERR, .desc="" },
		{  .name="itr_bus_master_dis", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="" },
		{  .name="itr_atomic_seq_err", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="" },
		{  .name="itr_atomic_resource_err", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_ERR, .desc="" },
		{  .name="tgt_rmw_axi_resperr", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="tgt_ind_notify_axi_resperr", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },

	} };
intr_reg_t pxb_pxb_int_groups_intreg = {  .name="pxb.pxb.int_groups.intreg", .addr=0x719a580, .reg_type=1, .id=86, .field_count=3, .fields=
	{
		{  .name="int_tgt_ecc", .next_ptr=&pxb_pxb_int_tgt_ecc, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_itr_ecc", .next_ptr=&pxb_pxb_int_itr_ecc, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_err", .next_ptr=&pxb_pxb_int_err, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t pct_te_7_int_err = {  .name="pct.te[7].int_err", .addr=0x6422440, .reg_type=0, .id=266, .field_count=20, .fields=
	{
		{  .name="miss_sop", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="previous stage error" },
		{  .name="miss_eop", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="previous stage error" },
		{  .name="phv_max_size", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="invalid" },
		{  .name="spurious_axi_rsp", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="spurious_tcam_rsp", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_FATAL, .desc="bad tcam response" },
		{  .name="te2mpu_timeout", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="impossible, should be disabled" },
		{  .name="axi_rdrsp_err", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="axi_bad_read", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="tcam_req_idx_fifo", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="tcam_rsp_idx_fifo", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="mpu_req_idx_fifo", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="axi_req_idx_fifo", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="proc_tbl_vld_wo_proc", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend_wo_wb", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend1_wo_pend0", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="both_pend_down", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend_wo_proc_down", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="both_pend_went_up", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="loaded_but_no_proc", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="loaded_but_no_proc_tbl_vld", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },

	} };
intr_reg_t pct_te_7_int_info = {  .name="pct.te[7].int_info", .addr=0x6422450, .reg_type=0, .id=267, .field_count=17, .fields=
	{
		{  .name="profile_cam_hit0", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit1", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit2", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit4", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit5", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit6", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit7", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit8", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit9", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit10", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit11", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit12", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit13", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit14", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit15", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_miss", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t pct_te_7_int_groups_intreg = {  .name="pct.te[7].int_groups.intreg", .addr=0x6422430, .reg_type=1, .id=268, .field_count=2, .fields=
	{
		{  .name="int_err", .next_ptr=&pct_te_7_int_err, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_info", .next_ptr=&pct_te_7_int_info, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t pp_pp_port_c_4_int_c_mac = {  .name="pp.pp.port_c[4].int_c_mac", .addr=0x70191b0, .reg_type=0, .id=167, .field_count=19, .fields=
	{
		{  .name="link_dn2up", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="link_up2dn", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="sec_bus_rst", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="rst_up2dn", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="rst_dn2up", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="portgate_open2close", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="ltssm_st_changed", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="sec_busnum_changed", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="rc_pme", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="rc_aerr", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="rc_serr", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="rc_hpe", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="rc_eq_req", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="rc_dpc", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="pm_turnoff", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="txbfr_overflow", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_FATAL, .desc="Fatal error, try to reproduce in lab and debug the configuration settings using PCIE Analyzer" },
		{  .name="rxtlp_err", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="" },
		{  .name="tl_flr_req", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="rc_legacy_intpin_changed", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t pp_pp_port_c_4_int_c_ecc = {  .name="pp.pp.port_c[4].int_c_ecc", .addr=0x70191c0, .reg_type=0, .id=168, .field_count=8, .fields=
	{
		{  .name="rxbuf_0_uncorrectable", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="rxbuf_1_uncorrectable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="rxbuf_2_uncorrectable", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="rxbuf_3_uncorrectable", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="rxbuf_0_correctable", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="rxbuf_1_correctable", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="rxbuf_2_correctable", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="rxbuf_3_correctable", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },

	} };
intr_reg_t pp_pp_port_c_4_int_groups_intreg = {  .name="pp.pp.port_c[4].int_groups.intreg", .addr=0x70191a0, .reg_type=1, .id=169, .field_count=2, .fields=
	{
		{  .name="int_c_mac", .next_ptr=&pp_pp_port_c_4_int_c_mac, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_c_ecc", .next_ptr=&pp_pp_port_c_4_int_c_ecc, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t pct_te_5_int_err = {  .name="pct.te[5].int_err", .addr=0x63e2440, .reg_type=0, .id=260, .field_count=20, .fields=
	{
		{  .name="miss_sop", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="previous stage error" },
		{  .name="miss_eop", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="previous stage error" },
		{  .name="phv_max_size", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="invalid" },
		{  .name="spurious_axi_rsp", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="spurious_tcam_rsp", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_FATAL, .desc="bad tcam response" },
		{  .name="te2mpu_timeout", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="impossible, should be disabled" },
		{  .name="axi_rdrsp_err", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="axi_bad_read", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="tcam_req_idx_fifo", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="tcam_rsp_idx_fifo", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="mpu_req_idx_fifo", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="axi_req_idx_fifo", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="proc_tbl_vld_wo_proc", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend_wo_wb", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend1_wo_pend0", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="both_pend_down", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend_wo_proc_down", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="both_pend_went_up", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="loaded_but_no_proc", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="loaded_but_no_proc_tbl_vld", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },

	} };
intr_reg_t pct_te_5_int_info = {  .name="pct.te[5].int_info", .addr=0x63e2450, .reg_type=0, .id=261, .field_count=17, .fields=
	{
		{  .name="profile_cam_hit0", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit1", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit2", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit4", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit5", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit6", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit7", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit8", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit9", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit10", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit11", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit12", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit13", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit14", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit15", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_miss", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t pct_te_5_int_groups_intreg = {  .name="pct.te[5].int_groups.intreg", .addr=0x63e2430, .reg_type=1, .id=262, .field_count=2, .fields=
	{
		{  .name="int_err", .next_ptr=&pct_te_5_int_err, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_info", .next_ptr=&pct_te_5_int_info, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t sge_te_4_int_err = {  .name="sge.te[4].int_err", .addr=0x3582440, .reg_type=0, .id=99, .field_count=20, .fields=
	{
		{  .name="miss_sop", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="previous stage error" },
		{  .name="miss_eop", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="previous stage error" },
		{  .name="phv_max_size", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="invalid" },
		{  .name="spurious_axi_rsp", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="spurious_tcam_rsp", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_FATAL, .desc="bad tcam response" },
		{  .name="te2mpu_timeout", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="impossible, should be disabled" },
		{  .name="axi_rdrsp_err", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="axi_bad_read", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="tcam_req_idx_fifo", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="tcam_rsp_idx_fifo", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="mpu_req_idx_fifo", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="axi_req_idx_fifo", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="proc_tbl_vld_wo_proc", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend_wo_wb", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend1_wo_pend0", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="both_pend_down", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend_wo_proc_down", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="both_pend_went_up", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="loaded_but_no_proc", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="loaded_but_no_proc_tbl_vld", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },

	} };
intr_reg_t sge_te_4_int_info = {  .name="sge.te[4].int_info", .addr=0x3582450, .reg_type=0, .id=100, .field_count=17, .fields=
	{
		{  .name="profile_cam_hit0", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit1", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit2", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit4", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit5", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit6", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit7", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit8", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit9", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit10", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit11", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit12", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit13", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit14", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit15", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_miss", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t sge_te_4_int_groups_intreg = {  .name="sge.te[4].int_groups.intreg", .addr=0x3582430, .reg_type=1, .id=101, .field_count=2, .fields=
	{
		{  .name="int_err", .next_ptr=&sge_te_4_int_err, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_info", .next_ptr=&sge_te_4_int_info, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t sgi_te_3_int_err = {  .name="sgi.te[3].int_err", .addr=0x3622440, .reg_type=0, .id=48, .field_count=20, .fields=
	{
		{  .name="miss_sop", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="previous stage error" },
		{  .name="miss_eop", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="previous stage error" },
		{  .name="phv_max_size", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="invalid" },
		{  .name="spurious_axi_rsp", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="spurious_tcam_rsp", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_FATAL, .desc="bad tcam response" },
		{  .name="te2mpu_timeout", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="impossible, should be disabled" },
		{  .name="axi_rdrsp_err", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="axi_bad_read", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="tcam_req_idx_fifo", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="tcam_rsp_idx_fifo", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="mpu_req_idx_fifo", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="axi_req_idx_fifo", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="proc_tbl_vld_wo_proc", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend_wo_wb", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend1_wo_pend0", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="both_pend_down", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend_wo_proc_down", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="both_pend_went_up", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="loaded_but_no_proc", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="loaded_but_no_proc_tbl_vld", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },

	} };
intr_reg_t sgi_te_3_int_info = {  .name="sgi.te[3].int_info", .addr=0x3622450, .reg_type=0, .id=49, .field_count=17, .fields=
	{
		{  .name="profile_cam_hit0", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit1", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit2", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit4", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit5", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit6", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit7", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit8", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit9", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit10", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit11", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit12", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit13", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit14", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit15", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_miss", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t sgi_te_3_int_groups_intreg = {  .name="sgi.te[3].int_groups.intreg", .addr=0x3622430, .reg_type=1, .id=50, .field_count=2, .fields=
	{
		{  .name="int_err", .next_ptr=&sgi_te_3_int_err, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_info", .next_ptr=&sgi_te_3_int_info, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t sge_te_1_int_err = {  .name="sge.te[1].int_err", .addr=0x3522440, .reg_type=0, .id=90, .field_count=20, .fields=
	{
		{  .name="miss_sop", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="previous stage error" },
		{  .name="miss_eop", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="previous stage error" },
		{  .name="phv_max_size", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="invalid" },
		{  .name="spurious_axi_rsp", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="spurious_tcam_rsp", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_FATAL, .desc="bad tcam response" },
		{  .name="te2mpu_timeout", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="impossible, should be disabled" },
		{  .name="axi_rdrsp_err", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="axi_bad_read", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="tcam_req_idx_fifo", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="tcam_rsp_idx_fifo", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="mpu_req_idx_fifo", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="axi_req_idx_fifo", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="proc_tbl_vld_wo_proc", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend_wo_wb", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend1_wo_pend0", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="both_pend_down", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend_wo_proc_down", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="both_pend_went_up", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="loaded_but_no_proc", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="loaded_but_no_proc_tbl_vld", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },

	} };
intr_reg_t sge_te_1_int_info = {  .name="sge.te[1].int_info", .addr=0x3522450, .reg_type=0, .id=91, .field_count=17, .fields=
	{
		{  .name="profile_cam_hit0", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit1", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit2", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit4", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit5", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit6", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit7", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit8", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit9", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit10", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit11", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit12", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit13", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit14", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit15", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_miss", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t sge_te_1_int_groups_intreg = {  .name="sge.te[1].int_groups.intreg", .addr=0x3522430, .reg_type=1, .id=92, .field_count=2, .fields=
	{
		{  .name="int_err", .next_ptr=&sge_te_1_int_err, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_info", .next_ptr=&sge_te_1_int_info, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t pcr_mpu_6_int_err = {  .name="pcr.mpu[6].int_err", .addr=0x64a8630, .reg_type=0, .id=235, .field_count=27, .fields=
	{
		{  .name="results_mismatch", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="mask this interrupt, not fully implemented" },
		{  .name="sdp_mem_uncorrectable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="sdp_mem_correctable", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="illegal_op_0", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_1", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_2", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_3", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="max_inst_0", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_1", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_2", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_3", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="phvwr_0", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_1", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_2", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_3", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="write_err_0", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_1", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_2", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_3", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="cache_axi_0", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_1", .next_ptr=nullptr, .id=22, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_2", .next_ptr=nullptr, .id=23, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_3", .next_ptr=nullptr, .id=24, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_parity_0", .next_ptr=nullptr, .id=25, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_1", .next_ptr=nullptr, .id=26, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_2", .next_ptr=nullptr, .id=27, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_3", .next_ptr=nullptr, .id=28, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },

	} };
intr_reg_t pcr_mpu_6_int_info = {  .name="pcr.mpu[6].int_info", .addr=0x64a8640, .reg_type=0, .id=236, .field_count=8, .fields=
	{
		{  .name="trace_full_0", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_1", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_2", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="mpu_stop_0", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_1", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_2", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_3", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },

	} };
intr_reg_t pcr_mpu_6_int_groups_intreg = {  .name="pcr.mpu[6].int_groups.intreg", .addr=0x64a8620, .reg_type=1, .id=237, .field_count=2, .fields=
	{
		{  .name="int_err", .next_ptr=&pcr_mpu_6_int_err, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_info", .next_ptr=&pcr_mpu_6_int_info, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t pp_pp_port_p_7_int_p_ecc = {  .name="pp.pp.port_p[7].int_p_ecc", .addr=0x7000f90, .reg_type=0, .id=153, .field_count=11, .fields=
	{
		{  .name="rxbfr_overflow", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="Fatal error, try to reproduce in lab and debug the configuration settings using PCIE Analyzer" },
		{  .name="replay_bfr_overflow", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="Fatal error, try to reproduce in lab and debug the configuration settings using PCIE Analyzer" },
		{  .name="rxtlp_err", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="txbuf_0_uncorrectable", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="txbuf_1_uncorrectable", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="txbuf_2_uncorrectable", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="txbuf_3_uncorrectable", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="txbuf_0_correctable", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="txbuf_1_correctable", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="txbuf_2_correctable", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="txbuf_3_correctable", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },

	} };
intr_reg_t pp_pp_port_p_7_int_groups_intreg = {  .name="pp.pp.port_p[7].int_groups.intreg", .addr=0x7000f80, .reg_type=1, .id=154, .field_count=1, .fields=
	{
		{  .name="int_p_ecc", .next_ptr=&pp_pp_port_p_7_int_p_ecc, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t sge_mpu_4_int_err = {  .name="sge.mpu[4].int_err", .addr=0x36c8630, .reg_type=0, .id=117, .field_count=27, .fields=
	{
		{  .name="results_mismatch", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="mask this interrupt, not fully implemented" },
		{  .name="sdp_mem_uncorrectable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="sdp_mem_correctable", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="illegal_op_0", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_1", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_2", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_3", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="max_inst_0", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_1", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_2", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_3", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="phvwr_0", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_1", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_2", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_3", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="write_err_0", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_1", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_2", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_3", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="cache_axi_0", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_1", .next_ptr=nullptr, .id=22, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_2", .next_ptr=nullptr, .id=23, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_3", .next_ptr=nullptr, .id=24, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_parity_0", .next_ptr=nullptr, .id=25, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_1", .next_ptr=nullptr, .id=26, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_2", .next_ptr=nullptr, .id=27, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_3", .next_ptr=nullptr, .id=28, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },

	} };
intr_reg_t sge_mpu_4_int_info = {  .name="sge.mpu[4].int_info", .addr=0x36c8640, .reg_type=0, .id=118, .field_count=8, .fields=
	{
		{  .name="trace_full_0", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_1", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_2", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="mpu_stop_0", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_1", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_2", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_3", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },

	} };
intr_reg_t sge_mpu_4_int_groups_intreg = {  .name="sge.mpu[4].int_groups.intreg", .addr=0x36c8620, .reg_type=1, .id=119, .field_count=2, .fields=
	{
		{  .name="int_err", .next_ptr=&sge_mpu_4_int_err, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_info", .next_ptr=&sge_mpu_4_int_info, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t pp_pp_port_p_4_int_p_ecc = {  .name="pp.pp.port_p[4].int_p_ecc", .addr=0x7000c90, .reg_type=0, .id=147, .field_count=11, .fields=
	{
		{  .name="rxbfr_overflow", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="Fatal error, try to reproduce in lab and debug the configuration settings using PCIE Analyzer" },
		{  .name="replay_bfr_overflow", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="Fatal error, try to reproduce in lab and debug the configuration settings using PCIE Analyzer" },
		{  .name="rxtlp_err", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="txbuf_0_uncorrectable", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="txbuf_1_uncorrectable", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="txbuf_2_uncorrectable", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="txbuf_3_uncorrectable", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="txbuf_0_correctable", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="txbuf_1_correctable", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="txbuf_2_correctable", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="txbuf_3_correctable", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },

	} };
intr_reg_t pp_pp_port_p_4_int_groups_intreg = {  .name="pp.pp.port_p[4].int_groups.intreg", .addr=0x7000c80, .reg_type=1, .id=148, .field_count=1, .fields=
	{
		{  .name="int_p_ecc", .next_ptr=&pp_pp_port_p_4_int_p_ecc, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t pp_pp_port_p_5_int_p_ecc = {  .name="pp.pp.port_p[5].int_p_ecc", .addr=0x7000d90, .reg_type=0, .id=149, .field_count=11, .fields=
	{
		{  .name="rxbfr_overflow", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="Fatal error, try to reproduce in lab and debug the configuration settings using PCIE Analyzer" },
		{  .name="replay_bfr_overflow", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="Fatal error, try to reproduce in lab and debug the configuration settings using PCIE Analyzer" },
		{  .name="rxtlp_err", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="txbuf_0_uncorrectable", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="txbuf_1_uncorrectable", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="txbuf_2_uncorrectable", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="txbuf_3_uncorrectable", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="txbuf_0_correctable", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="txbuf_1_correctable", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="txbuf_2_correctable", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="txbuf_3_correctable", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },

	} };
intr_reg_t pp_pp_port_p_5_int_groups_intreg = {  .name="pp.pp.port_p[5].int_groups.intreg", .addr=0x7000d80, .reg_type=1, .id=150, .field_count=1, .fields=
	{
		{  .name="int_p_ecc", .next_ptr=&pp_pp_port_p_5_int_p_ecc, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t pp_pp_port_p_6_int_p_ecc = {  .name="pp.pp.port_p[6].int_p_ecc", .addr=0x7000e90, .reg_type=0, .id=151, .field_count=11, .fields=
	{
		{  .name="rxbfr_overflow", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="Fatal error, try to reproduce in lab and debug the configuration settings using PCIE Analyzer" },
		{  .name="replay_bfr_overflow", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="Fatal error, try to reproduce in lab and debug the configuration settings using PCIE Analyzer" },
		{  .name="rxtlp_err", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="txbuf_0_uncorrectable", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="txbuf_1_uncorrectable", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="txbuf_2_uncorrectable", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="txbuf_3_uncorrectable", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="txbuf_0_correctable", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="txbuf_1_correctable", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="txbuf_2_correctable", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="txbuf_3_correctable", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },

	} };
intr_reg_t pp_pp_port_p_6_int_groups_intreg = {  .name="pp.pp.port_p[6].int_groups.intreg", .addr=0x7000e80, .reg_type=1, .id=152, .field_count=1, .fields=
	{
		{  .name="int_p_ecc", .next_ptr=&pp_pp_port_p_6_int_p_ecc, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t sge_te_5_int_err = {  .name="sge.te[5].int_err", .addr=0x35a2440, .reg_type=0, .id=102, .field_count=20, .fields=
	{
		{  .name="miss_sop", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="previous stage error" },
		{  .name="miss_eop", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="previous stage error" },
		{  .name="phv_max_size", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="invalid" },
		{  .name="spurious_axi_rsp", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="spurious_tcam_rsp", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_FATAL, .desc="bad tcam response" },
		{  .name="te2mpu_timeout", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="impossible, should be disabled" },
		{  .name="axi_rdrsp_err", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="axi_bad_read", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="tcam_req_idx_fifo", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="tcam_rsp_idx_fifo", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="mpu_req_idx_fifo", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="axi_req_idx_fifo", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="proc_tbl_vld_wo_proc", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend_wo_wb", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend1_wo_pend0", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="both_pend_down", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend_wo_proc_down", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="both_pend_went_up", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="loaded_but_no_proc", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="loaded_but_no_proc_tbl_vld", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },

	} };
intr_reg_t sge_te_5_int_info = {  .name="sge.te[5].int_info", .addr=0x35a2450, .reg_type=0, .id=103, .field_count=17, .fields=
	{
		{  .name="profile_cam_hit0", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit1", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit2", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit4", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit5", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit6", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit7", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit8", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit9", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit10", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit11", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit12", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit13", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit14", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit15", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_miss", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t sge_te_5_int_groups_intreg = {  .name="sge.te[5].int_groups.intreg", .addr=0x35a2430, .reg_type=1, .id=104, .field_count=2, .fields=
	{
		{  .name="int_err", .next_ptr=&sge_te_5_int_err, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_info", .next_ptr=&sge_te_5_int_info, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t pp_pp_port_p_0_int_p_ecc = {  .name="pp.pp.port_p[0].int_p_ecc", .addr=0x7000890, .reg_type=0, .id=139, .field_count=11, .fields=
	{
		{  .name="rxbfr_overflow", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="Fatal error, try to reproduce in lab and debug the configuration settings using PCIE Analyzer" },
		{  .name="replay_bfr_overflow", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="Fatal error, try to reproduce in lab and debug the configuration settings using PCIE Analyzer" },
		{  .name="rxtlp_err", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="txbuf_0_uncorrectable", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="txbuf_1_uncorrectable", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="txbuf_2_uncorrectable", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="txbuf_3_uncorrectable", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="txbuf_0_correctable", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="txbuf_1_correctable", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="txbuf_2_correctable", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="txbuf_3_correctable", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },

	} };
intr_reg_t pp_pp_port_p_0_int_groups_intreg = {  .name="pp.pp.port_p[0].int_groups.intreg", .addr=0x7000880, .reg_type=1, .id=140, .field_count=1, .fields=
	{
		{  .name="int_p_ecc", .next_ptr=&pp_pp_port_p_0_int_p_ecc, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t pr_pr_psp_int_info = {  .name="pr.pr.psp.int_info", .addr=0x6106150, .reg_type=0, .id=125, .field_count=9, .fields=
	{
		{  .name="pr_pkt_ff_almost_full", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="almost full flow control was asserted" },
		{  .name="ptd_npv_phv_full", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="almost full flow control was asserted" },
		{  .name="phv_srdy_collapsed", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="collapsed multiple idential PHVs" },
		{  .name="pr_resub_pkt_before_phv", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="received the PKT before the PHV on the resub busses" },
		{  .name="pb_pbus_fsm0_no_data", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_INFO, .desc="received PHV with no data" },
		{  .name="pb_pbus_fsm1_no_data", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="received PHV with no data" },
		{  .name="pb_pbus_fsm2_no_data", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_INFO, .desc="received PHV with no data" },
		{  .name="pb_pbus_fsm3_no_data", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_INFO, .desc="received PHV with no data" },
		{  .name="pb_pbus_fsm4_no_data", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_INFO, .desc="received PHV with no data" },

	} };
intr_reg_t pr_pr_psp_int_err = {  .name="pr.pr.psp.int_err", .addr=0x6106160, .reg_type=0, .id=126, .field_count=14, .fields=
	{
		{  .name="pb_pbus_err", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_ERR, .desc="error bit received ont the input PKT bus" },
		{  .name="pr_pbus_err", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="error bit sent on the output PKT bus" },
		{  .name="pr_resub_pbus_err", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="error bit received ont the input PKT bus" },
		{  .name="psp_csr_read_access_err", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="psp_csr_read_access && psp_csr_ready && psp_csr_error" },
		{  .name="psp_csr_write_access_err", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="psp_csr_write_access && psp_csr_ready && psp_csr_error" },
		{  .name="psp_phv_larger_than_twelve_flits_err", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="PHV over the max 12 flits received and truncated" },
		{  .name="psp_phv_sop_offset_err", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="EOP seen before reaching PHV offset in SOP flit" },
		{  .name="psp_phv_eop_offset_err", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="EOP seen before reaching PHV offset" },
		{  .name="max_recir_count_err", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_ERR, .desc="a packet was recirculated through P4+ more than the cfg_profile_recirc_max" },
		{  .name="pb_pbus_dummy_err", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="there was a missing PKT after the PHV, so the HW generated a dummy PKT" },
		{  .name="pb_pbus_nopkt_err", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_ERR, .desc="PKT smaller than 12 flits received from the input PKT bus, PKT data was dropped" },
		{  .name="pb_pbus_min_err", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="PKT smaller than cfg_profile_phv_min received from the input PKT bus" },
		{  .name="lb_phv_almost_full_timeout_err", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="the PHV state machine waited for longer than cfg_profile_almost_full_timer_max" },
		{  .name="lb_pkt_almost_full_timeout_err", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="the PKT state machine waited for longer than cfg_profile_almost_full_timer_max" },

	} };
intr_reg_t pr_pr_psp_int_fatal = {  .name="pr.pr.psp.int_fatal", .addr=0x6106170, .reg_type=0, .id=127, .field_count=23, .fields=
	{
		{  .name="pb_pbus_sop_err", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="fatal HW fsm error, no HW handling" },
		{  .name="pb_pbus_eop_err", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="fatal HW fsm error, no HW handling" },
		{  .name="ma_sop_err", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_FATAL, .desc="fatal HW fsm error, no HW handling" },
		{  .name="ma_eop_err", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_FATAL, .desc="fatal HW fsm error, no HW handling" },
		{  .name="pr_pbus_sop_err", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_FATAL, .desc="fatal HW fsm error, no HW handling" },
		{  .name="pr_pbus_eop_err", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_FATAL, .desc="fatal HW fsm error, no HW handling" },
		{  .name="pr_resub_pbus_sop_err", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_FATAL, .desc="fatal HW fsm error, no HW handling" },
		{  .name="pr_resub_pbus_eop_err", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_FATAL, .desc="fatal HW fsm error, no HW handling" },
		{  .name="pr_resub_sop_err", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_FATAL, .desc="fatal HW fsm error, no HW handling" },
		{  .name="pr_resub_eop_err", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_FATAL, .desc="fatal HW fsm error, no HW handling" },
		{  .name="pb_pbus_fsm0_no_data_err", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_FATAL, .desc="fatal HW fsm error, no HW handling" },
		{  .name="pb_pbus_fsm1_no_data_err", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_FATAL, .desc="fatal HW fsm error, no HW handling" },
		{  .name="pb_pbus_fsm2_no_data_err", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_FATAL, .desc="fatal HW fsm error, no HW handling" },
		{  .name="pb_pbus_fsm3_no_data_err", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_FATAL, .desc="fatal HW fsm error, no HW handling" },
		{  .name="pb_pbus_fsm4_no_data_err", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_FATAL, .desc="fatal HW fsm error, no HW handling" },
		{  .name="pb_pbus_fsm5_pkt_too_small_err", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_FATAL, .desc="fatal HW fsm error, no HW handling" },
		{  .name="lif_ind_table_rsp_err", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_FATAL, .desc="fatal HW fsm error, no HW handling" },
		{  .name="flit_cnt_oflow_err", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_FATAL, .desc="fatal HW fsm error, no HW handling" },
		{  .name="lb_phv_sop_err", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_FATAL, .desc="fatal HW fsm error, no HW handling" },
		{  .name="dc_phv_sop_err", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_FATAL, .desc="fatal HW fsm error, no HW handling" },
		{  .name="lb_pkt_sop_err", .next_ptr=nullptr, .id=22, .severity=INTR_SEV_TYPE_FATAL, .desc="fatal HW fsm error, no HW handling" },
		{  .name="dc_pkt_sop_err", .next_ptr=nullptr, .id=23, .severity=INTR_SEV_TYPE_FATAL, .desc="fatal HW fsm error, no HW handling" },
		{  .name="sw_phv_jabber_err", .next_ptr=nullptr, .id=24, .severity=INTR_SEV_TYPE_FATAL, .desc="fatal HW fsm error, no HW handling" },

	} };
intr_reg_t pr_pr_psp_int_lif_qstate_map = {  .name="pr.pr.psp.int_lif_qstate_map", .addr=0x6110010, .reg_type=0, .id=128, .field_count=3, .fields=
	{
		{  .name="ecc_uncorrectable", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="ecc_correctable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="qid_invalid", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="lookup in lif table missed" },

	} };
intr_reg_t pr_pr_psp_int_sw_phv_mem = {  .name="pr.pr.psp.int_sw_phv_mem", .addr=0x6111010, .reg_type=0, .id=129, .field_count=12, .fields=
	{
		{  .name="ecc_uncorrectable", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="ecc_correctable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="phv_invalid_sram", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="bad SW PHV sram programming" },
		{  .name="phv_invalid_data", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="bad SW PHV sram programming" },
		{  .name="phv_done0", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_INFO, .desc="SW PHV done info" },
		{  .name="phv_done1", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="SW PHV done info" },
		{  .name="phv_done2", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_INFO, .desc="SW PHV done info" },
		{  .name="phv_done3", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_INFO, .desc="SW PHV done info" },
		{  .name="phv_done4", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_INFO, .desc="SW PHV done info" },
		{  .name="phv_done5", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_INFO, .desc="SW PHV done info" },
		{  .name="phv_done6", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_INFO, .desc="SW PHV done info" },
		{  .name="phv_done7", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_INFO, .desc="SW PHV done info" },

	} };
intr_reg_t pr_pr_psp_int_groups_intreg = {  .name="pr.pr.psp.int_groups.intreg", .addr=0x6106140, .reg_type=1, .id=130, .field_count=5, .fields=
	{
		{  .name="int_info", .next_ptr=&pr_pr_psp_int_info, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_err", .next_ptr=&pr_pr_psp_int_err, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_fatal", .next_ptr=&pr_pr_psp_int_fatal, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_lif_qstate_map", .next_ptr=&pr_pr_psp_int_lif_qstate_map, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_sw_phv_mem", .next_ptr=&pr_pr_psp_int_sw_phv_mem, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t pp_pp_port_p_2_int_p_ecc = {  .name="pp.pp.port_p[2].int_p_ecc", .addr=0x7000a90, .reg_type=0, .id=143, .field_count=11, .fields=
	{
		{  .name="rxbfr_overflow", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="Fatal error, try to reproduce in lab and debug the configuration settings using PCIE Analyzer" },
		{  .name="replay_bfr_overflow", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="Fatal error, try to reproduce in lab and debug the configuration settings using PCIE Analyzer" },
		{  .name="rxtlp_err", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="txbuf_0_uncorrectable", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="txbuf_1_uncorrectable", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="txbuf_2_uncorrectable", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="txbuf_3_uncorrectable", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="txbuf_0_correctable", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="txbuf_1_correctable", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="txbuf_2_correctable", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="txbuf_3_correctable", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },

	} };
intr_reg_t pp_pp_port_p_2_int_groups_intreg = {  .name="pp.pp.port_p[2].int_groups.intreg", .addr=0x7000a80, .reg_type=1, .id=144, .field_count=1, .fields=
	{
		{  .name="int_p_ecc", .next_ptr=&pp_pp_port_p_2_int_p_ecc, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t pct_te_0_int_err = {  .name="pct.te[0].int_err", .addr=0x6342440, .reg_type=0, .id=245, .field_count=20, .fields=
	{
		{  .name="miss_sop", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="previous stage error" },
		{  .name="miss_eop", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="previous stage error" },
		{  .name="phv_max_size", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="invalid" },
		{  .name="spurious_axi_rsp", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="spurious_tcam_rsp", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_FATAL, .desc="bad tcam response" },
		{  .name="te2mpu_timeout", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="impossible, should be disabled" },
		{  .name="axi_rdrsp_err", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="axi_bad_read", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="tcam_req_idx_fifo", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="tcam_rsp_idx_fifo", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="mpu_req_idx_fifo", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="axi_req_idx_fifo", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="proc_tbl_vld_wo_proc", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend_wo_wb", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend1_wo_pend0", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="both_pend_down", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend_wo_proc_down", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="both_pend_went_up", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="loaded_but_no_proc", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="loaded_but_no_proc_tbl_vld", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },

	} };
intr_reg_t pct_te_0_int_info = {  .name="pct.te[0].int_info", .addr=0x6342450, .reg_type=0, .id=246, .field_count=17, .fields=
	{
		{  .name="profile_cam_hit0", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit1", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit2", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit4", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit5", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit6", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit7", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit8", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit9", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit10", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit11", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit12", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit13", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit14", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit15", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_miss", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t pct_te_0_int_groups_intreg = {  .name="pct.te[0].int_groups.intreg", .addr=0x6342430, .reg_type=1, .id=247, .field_count=2, .fields=
	{
		{  .name="int_err", .next_ptr=&pct_te_0_int_err, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_info", .next_ptr=&pct_te_0_int_info, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t sse_pics_picc_int_picc = {  .name="sse.pics.picc.int_picc", .addr=0x2da0020, .reg_type=0, .id=360, .field_count=7, .fields=
	{
		{  .name="uncorrectable_ecc", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="correctable_ecc", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="cache_stg_awlen_err", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_FATAL, .desc="HBM access fatal error" },
		{  .name="cache_hbm_rresp_slverr", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_FATAL, .desc="HBM access fatal error" },
		{  .name="cache_hbm_rresp_decerr", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_FATAL, .desc="HBM access fatal error" },
		{  .name="cache_hbm_bresp_slverr", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_FATAL, .desc="HBM access fatal error" },
		{  .name="cache_hbm_bresp_decerr", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_FATAL, .desc="HBM access fatal error" },

	} };
intr_reg_t sse_pics_picc_int_groups_intreg = {  .name="sse.pics.picc.int_groups.intreg", .addr=0x2da0010, .reg_type=1, .id=361, .field_count=1, .fields=
	{
		{  .name="int_picc", .next_ptr=&sse_pics_picc_int_picc, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t sge_te_3_int_err = {  .name="sge.te[3].int_err", .addr=0x3562440, .reg_type=0, .id=96, .field_count=20, .fields=
	{
		{  .name="miss_sop", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="previous stage error" },
		{  .name="miss_eop", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="previous stage error" },
		{  .name="phv_max_size", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="invalid" },
		{  .name="spurious_axi_rsp", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="spurious_tcam_rsp", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_FATAL, .desc="bad tcam response" },
		{  .name="te2mpu_timeout", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="impossible, should be disabled" },
		{  .name="axi_rdrsp_err", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="axi_bad_read", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="tcam_req_idx_fifo", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="tcam_rsp_idx_fifo", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="mpu_req_idx_fifo", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_FATAL, .desc="pop empty fifo" },
		{  .name="axi_req_idx_fifo", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="Access to invalid address, missing address range in the NOC, or slave sent back an error" },
		{  .name="proc_tbl_vld_wo_proc", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend_wo_wb", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend1_wo_pend0", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="both_pend_down", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="pend_wo_proc_down", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="both_pend_went_up", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="loaded_but_no_proc", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },
		{  .name="loaded_but_no_proc_tbl_vld", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_ERR, .desc="mpu error" },

	} };
intr_reg_t sge_te_3_int_info = {  .name="sge.te[3].int_info", .addr=0x3562450, .reg_type=0, .id=97, .field_count=17, .fields=
	{
		{  .name="profile_cam_hit0", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit1", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit2", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit4", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit5", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit6", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit7", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit8", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit9", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit10", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit11", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit12", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit13", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit14", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_hit15", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="profile_cam_miss", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t sge_te_3_int_groups_intreg = {  .name="sge.te[3].int_groups.intreg", .addr=0x3562430, .reg_type=1, .id=98, .field_count=2, .fields=
	{
		{  .name="int_err", .next_ptr=&sge_te_3_int_err, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_info", .next_ptr=&sge_te_3_int_info, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t pct_mpu_6_int_err = {  .name="pct.mpu[6].int_err", .addr=0x6528630, .reg_type=0, .id=287, .field_count=27, .fields=
	{
		{  .name="results_mismatch", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="mask this interrupt, not fully implemented" },
		{  .name="sdp_mem_uncorrectable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="sdp_mem_correctable", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="illegal_op_0", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_1", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_2", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_3", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="max_inst_0", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_1", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_2", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_3", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="phvwr_0", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_1", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_2", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_3", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="write_err_0", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_1", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_2", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_3", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="cache_axi_0", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_1", .next_ptr=nullptr, .id=22, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_2", .next_ptr=nullptr, .id=23, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_3", .next_ptr=nullptr, .id=24, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_parity_0", .next_ptr=nullptr, .id=25, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_1", .next_ptr=nullptr, .id=26, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_2", .next_ptr=nullptr, .id=27, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_3", .next_ptr=nullptr, .id=28, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },

	} };
intr_reg_t pct_mpu_6_int_info = {  .name="pct.mpu[6].int_info", .addr=0x6528640, .reg_type=0, .id=288, .field_count=8, .fields=
	{
		{  .name="trace_full_0", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_1", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_2", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="mpu_stop_0", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_1", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_2", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_3", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },

	} };
intr_reg_t pct_mpu_6_int_groups_intreg = {  .name="pct.mpu[6].int_groups.intreg", .addr=0x6528620, .reg_type=1, .id=289, .field_count=2, .fields=
	{
		{  .name="int_err", .next_ptr=&pct_mpu_6_int_err, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_info", .next_ptr=&pct_mpu_6_int_info, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t bx_bx_int_mac = {  .name="bx.bx.int_mac", .addr=0x1000240, .reg_type=0, .id=362, .field_count=9, .fields=
	{
		{  .name="lane_sbe", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="lane_dbe", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_HW_RMA, .desc="Double bit error in SerDes. Lane may go down" },
		{  .name="xdmac10_intr", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="xdmac10_pslverr", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="Invalid need to be masked" },
		{  .name="bxpb_pbus_drdy", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_FATAL, .desc="Debug PB config. Never happen; otherwise, it's hardware bug" },
		{  .name="rx_missing_sof", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="HW self recover" },
		{  .name="rx_missing_eof", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_INFO, .desc="HW self recover" },
		{  .name="rx_timeout_err", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_INFO, .desc="HW self recover" },
		{  .name="rx_min_size_err", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_INFO, .desc="HW self recover" },

	} };
intr_reg_t bx_bx_int_groups_intreg = {  .name="bx.bx.int_groups.intreg", .addr=0x1000230, .reg_type=1, .id=363, .field_count=1, .fields=
	{
		{  .name="int_mac", .next_ptr=&bx_bx_int_mac, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t pp_pp_int_pp = {  .name="pp.pp.int_pp", .addr=0x70202e0, .reg_type=0, .id=137, .field_count=27, .fields=
	{
		{  .name="ppsd_sbe", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="ppsd_dbe", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="sbus_err", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="port7_c_int", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="port7_p_int", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="port6_c_int", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="port6_p_int", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="port5_c_int", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="port5_p_int", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="port4_c_int", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="port4_p_int", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="port3_c_int", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="port3_p_int", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="port2_c_int", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="port2_p_int", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="port1_c_int", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="port1_p_int", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="port0_c_int", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="port0_p_int", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="perst7n_dn2up", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="perst6n_dn2up", .next_ptr=nullptr, .id=22, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="perst5n_dn2up", .next_ptr=nullptr, .id=23, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="perst4n_dn2up", .next_ptr=nullptr, .id=24, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="perst3n_dn2up", .next_ptr=nullptr, .id=25, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="perst2n_dn2up", .next_ptr=nullptr, .id=26, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="perst1n_dn2up", .next_ptr=nullptr, .id=27, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="perst0n_dn2up", .next_ptr=nullptr, .id=28, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t pp_pp_int_groups_intreg = {  .name="pp.pp.int_groups.intreg", .addr=0x70202d0, .reg_type=1, .id=138, .field_count=1, .fields=
	{
		{  .name="int_pp", .next_ptr=&pp_pp_int_pp, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t pp_pp_port_c_2_int_c_mac = {  .name="pp.pp.port_c[2].int_c_mac", .addr=0x70151b0, .reg_type=0, .id=161, .field_count=19, .fields=
	{
		{  .name="link_dn2up", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="link_up2dn", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="sec_bus_rst", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="rst_up2dn", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="rst_dn2up", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="portgate_open2close", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="ltssm_st_changed", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="sec_busnum_changed", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="rc_pme", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="rc_aerr", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="rc_serr", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="rc_hpe", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="rc_eq_req", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="rc_dpc", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="pm_turnoff", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="txbfr_overflow", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_FATAL, .desc="Fatal error, try to reproduce in lab and debug the configuration settings using PCIE Analyzer" },
		{  .name="rxtlp_err", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="" },
		{  .name="tl_flr_req", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="rc_legacy_intpin_changed", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t pp_pp_port_c_2_int_c_ecc = {  .name="pp.pp.port_c[2].int_c_ecc", .addr=0x70151c0, .reg_type=0, .id=162, .field_count=8, .fields=
	{
		{  .name="rxbuf_0_uncorrectable", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="rxbuf_1_uncorrectable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="rxbuf_2_uncorrectable", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="rxbuf_3_uncorrectable", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="rxbuf_0_correctable", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="rxbuf_1_correctable", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="rxbuf_2_correctable", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="rxbuf_3_correctable", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },

	} };
intr_reg_t pp_pp_port_c_2_int_groups_intreg = {  .name="pp.pp.port_c[2].int_groups.intreg", .addr=0x70151a0, .reg_type=1, .id=163, .field_count=2, .fields=
	{
		{  .name="int_c_mac", .next_ptr=&pp_pp_port_c_2_int_c_mac, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_c_ecc", .next_ptr=&pp_pp_port_c_2_int_c_ecc, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t mc_mc_6_mch_int_mc = {  .name="mc.mc[6].mch.int_mc", .addr=0x6a700060, .reg_type=0, .id=420, .field_count=2, .fields=
	{
		{  .name="ecc_1bit_thresh_ps1", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_ERR, .desc="" },
		{  .name="ecc_1bit_thresh_ps0", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="" },

	} };
intr_reg_t mc_mc_6_mch_int_groups_intreg = {  .name="mc.mc[6].mch.int_groups.intreg", .addr=0x6a700050, .reg_type=1, .id=421, .field_count=1, .fields=
	{
		{  .name="int_mc", .next_ptr=&mc_mc_6_mch_int_mc, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t sgi_mpu_4_int_err = {  .name="sgi.mpu[4].int_err", .addr=0x3728630, .reg_type=0, .id=69, .field_count=27, .fields=
	{
		{  .name="results_mismatch", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="mask this interrupt, not fully implemented" },
		{  .name="sdp_mem_uncorrectable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="sdp_mem_correctable", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="illegal_op_0", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_1", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_2", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_3", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="max_inst_0", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_1", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_2", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_3", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="phvwr_0", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_1", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_2", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_3", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="write_err_0", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_1", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_2", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_3", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="cache_axi_0", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_1", .next_ptr=nullptr, .id=22, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_2", .next_ptr=nullptr, .id=23, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_3", .next_ptr=nullptr, .id=24, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_parity_0", .next_ptr=nullptr, .id=25, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_1", .next_ptr=nullptr, .id=26, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_2", .next_ptr=nullptr, .id=27, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_3", .next_ptr=nullptr, .id=28, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },

	} };
intr_reg_t sgi_mpu_4_int_info = {  .name="sgi.mpu[4].int_info", .addr=0x3728640, .reg_type=0, .id=70, .field_count=8, .fields=
	{
		{  .name="trace_full_0", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_1", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_2", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="mpu_stop_0", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_1", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_2", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_3", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },

	} };
intr_reg_t sgi_mpu_4_int_groups_intreg = {  .name="sgi.mpu[4].int_groups.intreg", .addr=0x3728620, .reg_type=1, .id=71, .field_count=2, .fields=
	{
		{  .name="int_err", .next_ptr=&sgi_mpu_4_int_err, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_info", .next_ptr=&sgi_mpu_4_int_info, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t ppa_ppa_1_int_bndl0 = {  .name="ppa.ppa[1].int_bndl0", .addr=0x34c02c0, .reg_type=0, .id=20, .field_count=3, .fields=
	{
		{  .name="state_lkp_srch_hit_addr_range_err", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Parser TCAM entry programmed out of valid range." },
		{  .name="state_lkp_srch_miss", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Parser TCAM search miss" },
		{  .name="state_lkp_srch_req_not_rdy", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },

	} };
intr_reg_t ppa_ppa_1_int_bndl1 = {  .name="ppa.ppa[1].int_bndl1", .addr=0x34c02d0, .reg_type=0, .id=21, .field_count=3, .fields=
	{
		{  .name="state_lkp_srch_hit_addr_range_err", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Parser TCAM entry programmed out of valid range." },
		{  .name="state_lkp_srch_miss", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Parser TCAM search miss" },
		{  .name="state_lkp_srch_req_not_rdy", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },

	} };
intr_reg_t ppa_ppa_1_int_ecc = {  .name="ppa.ppa[1].int_ecc", .addr=0x34c02e0, .reg_type=0, .id=22, .field_count=6, .fields=
	{
		{  .name="pkt_mem_uncorrectable", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="pkt_mem_correctable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="bndl0_state_lkp_sram_uncorrectable", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="bndl0_state_lkp_sram_correctable", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="bndl1_state_lkp_sram_uncorrectable", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="bndl1_state_lkp_sram_correctable", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },

	} };
intr_reg_t ppa_ppa_1_int_fifo1 = {  .name="ppa.ppa[1].int_fifo1", .addr=0x34c02f0, .reg_type=0, .id=23, .field_count=30, .fields=
	{
		{  .name="pe0_qctl_ff_ovflow", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="pe1_qctl_ff_ovflow", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="pe2_qctl_ff_ovflow", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="pe3_qctl_ff_ovflow", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="pe4_qctl_ff_ovflow", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="pe5_qctl_ff_ovflow", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="pe6_qctl_ff_ovflow", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="pe7_qctl_ff_ovflow", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="pe8_qctl_ff_ovflow", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="pe9_qctl_ff_ovflow", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="pe0_phv_ff_ovflow", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="pe1_phv_ff_ovflow", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="pe2_phv_ff_ovflow", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="pe3_phv_ff_ovflow", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="pe4_phv_ff_ovflow", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="pe5_phv_ff_ovflow", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="pe6_phv_ff_ovflow", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="pe7_phv_ff_ovflow", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="pe8_phv_ff_ovflow", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="pe9_phv_ff_ovflow", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="pe0_ohi_ff_ovflow", .next_ptr=nullptr, .id=22, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="pe1_ohi_ff_ovflow", .next_ptr=nullptr, .id=23, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="pe2_ohi_ff_ovflow", .next_ptr=nullptr, .id=24, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="pe3_ohi_ff_ovflow", .next_ptr=nullptr, .id=25, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="pe4_ohi_ff_ovflow", .next_ptr=nullptr, .id=26, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="pe5_ohi_ff_ovflow", .next_ptr=nullptr, .id=27, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="pe6_ohi_ff_ovflow", .next_ptr=nullptr, .id=28, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="pe7_ohi_ff_ovflow", .next_ptr=nullptr, .id=29, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="pe8_ohi_ff_ovflow", .next_ptr=nullptr, .id=30, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="pe9_ohi_ff_ovflow", .next_ptr=nullptr, .id=31, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },

	} };
intr_reg_t ppa_ppa_1_int_fifo2 = {  .name="ppa.ppa[1].int_fifo2", .addr=0x34c0300, .reg_type=0, .id=24, .field_count=8, .fields=
	{
		{  .name="dp_if_ff_ovflow", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="ohi_if_ff_ovflow", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="ma_if_ff_ovflow", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="pb_if_ff_ovflow", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="pkt_mtu_ff_ovflow", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="outphv_ff_ovflow", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="outohi_ff_ovflow", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="chk_ff_ovflow", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },

	} };
intr_reg_t ppa_ppa_1_int_pe0 = {  .name="ppa.ppa[1].int_pe0", .addr=0x34c0310, .reg_type=0, .id=25, .field_count=10, .fields=
	{
		{  .name="qctl_skid_depth_not_zero", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="qctl_not_sop_after_pkt_release", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="unexpected_non_sop", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="exceed_phv_flit_cnt", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="software error: Number of phv flits generated exceeded the limit." },
		{  .name="exceed_parse_loop_cnt", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="software error: Number of parse states jump for a packet exceeded the limit. " },
		{  .name="offset_out_of_range", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Parser state programming error." },
		{  .name="pkt_size_chk", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Not enough bytes in packet. Parser state programming error." },
		{  .name="offset_jump_chk", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Parser state programming error." },
		{  .name="d1_not_valid", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="phv_upr_idx_less", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Parser state programming error." },

	} };
intr_reg_t ppa_ppa_1_int_pe1 = {  .name="ppa.ppa[1].int_pe1", .addr=0x34c0320, .reg_type=0, .id=26, .field_count=10, .fields=
	{
		{  .name="qctl_skid_depth_not_zero", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="qctl_not_sop_after_pkt_release", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="unexpected_non_sop", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="exceed_phv_flit_cnt", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="software error: Number of phv flits generated exceeded the limit." },
		{  .name="exceed_parse_loop_cnt", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="software error: Number of parse states jump for a packet exceeded the limit. " },
		{  .name="offset_out_of_range", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Parser state programming error." },
		{  .name="pkt_size_chk", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Not enough bytes in packet. Parser state programming error." },
		{  .name="offset_jump_chk", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Parser state programming error." },
		{  .name="d1_not_valid", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="phv_upr_idx_less", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Parser state programming error." },

	} };
intr_reg_t ppa_ppa_1_int_pe2 = {  .name="ppa.ppa[1].int_pe2", .addr=0x34c0330, .reg_type=0, .id=27, .field_count=10, .fields=
	{
		{  .name="qctl_skid_depth_not_zero", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="qctl_not_sop_after_pkt_release", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="unexpected_non_sop", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="exceed_phv_flit_cnt", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="software error: Number of phv flits generated exceeded the limit." },
		{  .name="exceed_parse_loop_cnt", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="software error: Number of parse states jump for a packet exceeded the limit. " },
		{  .name="offset_out_of_range", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Parser state programming error." },
		{  .name="pkt_size_chk", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Not enough bytes in packet. Parser state programming error." },
		{  .name="offset_jump_chk", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Parser state programming error." },
		{  .name="d1_not_valid", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="phv_upr_idx_less", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Parser state programming error." },

	} };
intr_reg_t ppa_ppa_1_int_pe3 = {  .name="ppa.ppa[1].int_pe3", .addr=0x34c0340, .reg_type=0, .id=28, .field_count=10, .fields=
	{
		{  .name="qctl_skid_depth_not_zero", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="qctl_not_sop_after_pkt_release", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="unexpected_non_sop", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="exceed_phv_flit_cnt", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="software error: Number of phv flits generated exceeded the limit." },
		{  .name="exceed_parse_loop_cnt", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="software error: Number of parse states jump for a packet exceeded the limit. " },
		{  .name="offset_out_of_range", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Parser state programming error." },
		{  .name="pkt_size_chk", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Not enough bytes in packet. Parser state programming error." },
		{  .name="offset_jump_chk", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Parser state programming error." },
		{  .name="d1_not_valid", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="phv_upr_idx_less", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Parser state programming error." },

	} };
intr_reg_t ppa_ppa_1_int_pe4 = {  .name="ppa.ppa[1].int_pe4", .addr=0x34c0350, .reg_type=0, .id=29, .field_count=10, .fields=
	{
		{  .name="qctl_skid_depth_not_zero", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="qctl_not_sop_after_pkt_release", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="unexpected_non_sop", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="exceed_phv_flit_cnt", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="software error: Number of phv flits generated exceeded the limit." },
		{  .name="exceed_parse_loop_cnt", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="software error: Number of parse states jump for a packet exceeded the limit. " },
		{  .name="offset_out_of_range", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Parser state programming error." },
		{  .name="pkt_size_chk", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Not enough bytes in packet. Parser state programming error." },
		{  .name="offset_jump_chk", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Parser state programming error." },
		{  .name="d1_not_valid", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="phv_upr_idx_less", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Parser state programming error." },

	} };
intr_reg_t ppa_ppa_1_int_pe5 = {  .name="ppa.ppa[1].int_pe5", .addr=0x34c0360, .reg_type=0, .id=30, .field_count=10, .fields=
	{
		{  .name="qctl_skid_depth_not_zero", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="qctl_not_sop_after_pkt_release", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="unexpected_non_sop", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="exceed_phv_flit_cnt", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="software error: Number of phv flits generated exceeded the limit." },
		{  .name="exceed_parse_loop_cnt", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="software error: Number of parse states jump for a packet exceeded the limit. " },
		{  .name="offset_out_of_range", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Parser state programming error." },
		{  .name="pkt_size_chk", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Not enough bytes in packet. Parser state programming error." },
		{  .name="offset_jump_chk", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Parser state programming error." },
		{  .name="d1_not_valid", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="phv_upr_idx_less", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Parser state programming error." },

	} };
intr_reg_t ppa_ppa_1_int_pe6 = {  .name="ppa.ppa[1].int_pe6", .addr=0x34c0370, .reg_type=0, .id=31, .field_count=10, .fields=
	{
		{  .name="qctl_skid_depth_not_zero", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="qctl_not_sop_after_pkt_release", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="unexpected_non_sop", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="exceed_phv_flit_cnt", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="software error: Number of phv flits generated exceeded the limit." },
		{  .name="exceed_parse_loop_cnt", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="software error: Number of parse states jump for a packet exceeded the limit. " },
		{  .name="offset_out_of_range", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Parser state programming error." },
		{  .name="pkt_size_chk", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Not enough bytes in packet. Parser state programming error." },
		{  .name="offset_jump_chk", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Parser state programming error." },
		{  .name="d1_not_valid", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="phv_upr_idx_less", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Parser state programming error." },

	} };
intr_reg_t ppa_ppa_1_int_pe7 = {  .name="ppa.ppa[1].int_pe7", .addr=0x34c0380, .reg_type=0, .id=32, .field_count=10, .fields=
	{
		{  .name="qctl_skid_depth_not_zero", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="qctl_not_sop_after_pkt_release", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="unexpected_non_sop", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="exceed_phv_flit_cnt", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="software error: Number of phv flits generated exceeded the limit." },
		{  .name="exceed_parse_loop_cnt", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="software error: Number of parse states jump for a packet exceeded the limit. " },
		{  .name="offset_out_of_range", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Parser state programming error." },
		{  .name="pkt_size_chk", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Not enough bytes in packet. Parser state programming error." },
		{  .name="offset_jump_chk", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Parser state programming error." },
		{  .name="d1_not_valid", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="phv_upr_idx_less", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Parser state programming error." },

	} };
intr_reg_t ppa_ppa_1_int_pe8 = {  .name="ppa.ppa[1].int_pe8", .addr=0x34c0390, .reg_type=0, .id=33, .field_count=10, .fields=
	{
		{  .name="qctl_skid_depth_not_zero", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="qctl_not_sop_after_pkt_release", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="unexpected_non_sop", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="exceed_phv_flit_cnt", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="software error: Number of phv flits generated exceeded the limit." },
		{  .name="exceed_parse_loop_cnt", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="software error: Number of parse states jump for a packet exceeded the limit. " },
		{  .name="offset_out_of_range", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Parser state programming error." },
		{  .name="pkt_size_chk", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Not enough bytes in packet. Parser state programming error." },
		{  .name="offset_jump_chk", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Parser state programming error." },
		{  .name="d1_not_valid", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="phv_upr_idx_less", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Parser state programming error." },

	} };
intr_reg_t ppa_ppa_1_int_pe9 = {  .name="ppa.ppa[1].int_pe9", .addr=0x34c03a0, .reg_type=0, .id=34, .field_count=10, .fields=
	{
		{  .name="qctl_skid_depth_not_zero", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="qctl_not_sop_after_pkt_release", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="unexpected_non_sop", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="exceed_phv_flit_cnt", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="software error: Number of phv flits generated exceeded the limit." },
		{  .name="exceed_parse_loop_cnt", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="software error: Number of parse states jump for a packet exceeded the limit. " },
		{  .name="offset_out_of_range", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Parser state programming error." },
		{  .name="pkt_size_chk", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Not enough bytes in packet. Parser state programming error." },
		{  .name="offset_jump_chk", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Parser state programming error." },
		{  .name="d1_not_valid", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="phv_upr_idx_less", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="software error. Parser state programming error." },

	} };
intr_reg_t ppa_ppa_1_int_pa = {  .name="ppa.ppa[1].int_pa", .addr=0x34c03b0, .reg_type=0, .id=35, .field_count=21, .fields=
	{
		{  .name="reorder_phv_not_sop", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="csum0_not_enuf_bytes", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="software error. CSUM checking logic has programmable start and end offset. The packet ended before end offset. It's possible the packet is malformed as well. Check for other interrupts in PB." },
		{  .name="csum0_start_more_than_end_offset", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="Software error. CSUM checking logic programmable start offset is more than end offset" },
		{  .name="csum1_not_enuf_bytes", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="software error. CSUM checking logic has programmable start and end offset. The packet ended before end offset. It's possible the packet is malformed as well. Check for other interrupts in PB." },
		{  .name="csum1_start_more_than_end_offset", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="Software error. CSUM checking logic programmable start offset is more than end offset" },
		{  .name="csum2_not_enuf_bytes", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="software error. CSUM checking logic has programmable start and end offset. The packet ended before end offset. It's possible the packet is malformed as well. Check for other interrupts in PB." },
		{  .name="csum2_start_more_than_end_offset", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="Software error. CSUM checking logic programmable start offset is more than end offset" },
		{  .name="csum3_not_enuf_bytes", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="software error. CSUM checking logic has programmable start and end offset. The packet ended before end offset. It's possible the packet is malformed as well. Check for other interrupts in PB." },
		{  .name="csum3_start_more_than_end_offset", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_ERR, .desc="Software error. CSUM checking logic programmable start offset is more than end offset" },
		{  .name="csum4_not_enuf_bytes", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="software error. CSUM checking logic has programmable start and end offset. The packet ended before end offset. It's possible the packet is malformed as well. Check for other interrupts in PB." },
		{  .name="csum4_start_more_than_end_offset", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_ERR, .desc="Software error. CSUM checking logic programmable start offset is more than end offset" },
		{  .name="crc_not_enuf_bytes", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="software error. CRC checking logic has programmable start and end offset. The packet ended before end offset. It's possible the packet is malformed as well. Check for other interrupts in PB." },
		{  .name="crc_start_more_than_end_offset", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="Software error. CRC checking logic programmable start offset is more than end offset" },
		{  .name="chkr_phv_single_flit", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="chkr_phv_not_sop", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="chkr_pkt_not_sop", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="chkr_seq_id", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="preparse_line0_not_sop", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="preparse_dff_not_sop", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="preparse_dff_ovflow", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="preparse_eff_ovflow", .next_ptr=nullptr, .id=22, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },

	} };
intr_reg_t ppa_ppa_1_int_sw_phv_mem = {  .name="ppa.ppa[1].int_sw_phv_mem", .addr=0x34c1010, .reg_type=0, .id=36, .field_count=12, .fields=
	{
		{  .name="ecc_uncorrectable", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="ecc_correctable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="phv_invalid_sram", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="phv_invalid_data", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="phv_done0", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="phv_done1", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="phv_done2", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="phv_done3", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="phv_done4", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="phv_done5", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="phv_done6", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="phv_done7", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t ppa_ppa_1_int_intf = {  .name="ppa.ppa[1].int_intf", .addr=0x34c03c0, .reg_type=0, .id=37, .field_count=15, .fields=
	{
		{  .name="pb_err", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_ERR, .desc="Packet err bit set along with EOP in packet bus from buffer to Parser. Error bit probably is from memory ecc error. Check other interrupts in PB." },
		{  .name="pb_sop_err", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="pb_eop_err", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="dp_err", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="Packet err bit set along with EOP in packet bus from Parser to Deparser. Error bit probably is from buffer or from memory ecc error. Check other interrupts." },
		{  .name="dp_sop_err", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="dp_eop_err", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="ohi_err", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="Packet err bit set along with EOP in OHI bus from Parser to Deparser. Error bit probably is from buffer or from memory ecc error. Check other interrupts." },
		{  .name="ohi_sop_err", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="ohi_eop_err", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="sw_phv_err", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="SW phv gen logic set error along with PHV. Error bit probably is from memory ecc error. Check other interrupts." },
		{  .name="sw_phv_sop_err", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="sw_phv_eop_err", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="ma_err", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="Packet err bit set along with EOP in PHV bus from Parser to STG. Error bit probably is from memory ecc error. Check other interrupts." },
		{  .name="ma_sop_err", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },
		{  .name="ma_eop_err", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_FATAL, .desc="hardware error" },

	} };
intr_reg_t ppa_ppa_1_int_groups_intreg = {  .name="ppa.ppa[1].int_groups.intreg", .addr=0x34c02b0, .reg_type=1, .id=38, .field_count=18, .fields=
	{
		{  .name="int_bndl0", .next_ptr=&ppa_ppa_1_int_bndl0, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_bndl1", .next_ptr=&ppa_ppa_1_int_bndl1, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_ecc", .next_ptr=&ppa_ppa_1_int_ecc, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_fifo1", .next_ptr=&ppa_ppa_1_int_fifo1, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_fifo2", .next_ptr=&ppa_ppa_1_int_fifo2, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_pe0", .next_ptr=&ppa_ppa_1_int_pe0, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_pe1", .next_ptr=&ppa_ppa_1_int_pe1, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_pe2", .next_ptr=&ppa_ppa_1_int_pe2, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_pe3", .next_ptr=&ppa_ppa_1_int_pe3, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_pe4", .next_ptr=&ppa_ppa_1_int_pe4, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_pe5", .next_ptr=&ppa_ppa_1_int_pe5, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_pe6", .next_ptr=&ppa_ppa_1_int_pe6, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_pe7", .next_ptr=&ppa_ppa_1_int_pe7, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_pe8", .next_ptr=&ppa_ppa_1_int_pe8, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_pe9", .next_ptr=&ppa_ppa_1_int_pe9, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_pa", .next_ptr=&ppa_ppa_1_int_pa, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_sw_phv_mem", .next_ptr=&ppa_ppa_1_int_sw_phv_mem, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_intf", .next_ptr=&ppa_ppa_1_int_intf, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t pct_mpu_1_int_err = {  .name="pct.mpu[1].int_err", .addr=0x64d8630, .reg_type=0, .id=272, .field_count=27, .fields=
	{
		{  .name="results_mismatch", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="mask this interrupt, not fully implemented" },
		{  .name="sdp_mem_uncorrectable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="sdp_mem_correctable", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="illegal_op_0", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_1", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_2", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_3", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="max_inst_0", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_1", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_2", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_3", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="phvwr_0", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_1", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_2", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_3", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="write_err_0", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_1", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_2", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_3", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="cache_axi_0", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_1", .next_ptr=nullptr, .id=22, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_2", .next_ptr=nullptr, .id=23, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_3", .next_ptr=nullptr, .id=24, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_parity_0", .next_ptr=nullptr, .id=25, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_1", .next_ptr=nullptr, .id=26, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_2", .next_ptr=nullptr, .id=27, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_3", .next_ptr=nullptr, .id=28, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },

	} };
intr_reg_t pct_mpu_1_int_info = {  .name="pct.mpu[1].int_info", .addr=0x64d8640, .reg_type=0, .id=273, .field_count=8, .fields=
	{
		{  .name="trace_full_0", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_1", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_2", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="mpu_stop_0", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_1", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_2", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_3", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },

	} };
intr_reg_t pct_mpu_1_int_groups_intreg = {  .name="pct.mpu[1].int_groups.intreg", .addr=0x64d8620, .reg_type=1, .id=274, .field_count=2, .fields=
	{
		{  .name="int_err", .next_ptr=&pct_mpu_1_int_err, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_info", .next_ptr=&pct_mpu_1_int_info, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t pp_pp_port_p_3_int_p_ecc = {  .name="pp.pp.port_p[3].int_p_ecc", .addr=0x7000b90, .reg_type=0, .id=145, .field_count=11, .fields=
	{
		{  .name="rxbfr_overflow", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_FATAL, .desc="Fatal error, try to reproduce in lab and debug the configuration settings using PCIE Analyzer" },
		{  .name="replay_bfr_overflow", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_FATAL, .desc="Fatal error, try to reproduce in lab and debug the configuration settings using PCIE Analyzer" },
		{  .name="rxtlp_err", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="txbuf_0_uncorrectable", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="txbuf_1_uncorrectable", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="txbuf_2_uncorrectable", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="txbuf_3_uncorrectable", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="txbuf_0_correctable", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="txbuf_1_correctable", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="txbuf_2_correctable", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="txbuf_3_correctable", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },

	} };
intr_reg_t pp_pp_port_p_3_int_groups_intreg = {  .name="pp.pp.port_p[3].int_groups.intreg", .addr=0x7000b80, .reg_type=1, .id=146, .field_count=1, .fields=
	{
		{  .name="int_p_ecc", .next_ptr=&pp_pp_port_p_3_int_p_ecc, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t mc_mc_2_int_mc = {  .name="mc.mc[2].int_mc", .addr=0x6a380020, .reg_type=0, .id=402, .field_count=1, .fields=
	{
		{  .name="mch_int", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_ERR, .desc="" },

	} };
intr_reg_t mc_mc_2_int_groups_intreg = {  .name="mc.mc[2].int_groups.intreg", .addr=0x6a380010, .reg_type=1, .id=403, .field_count=1, .fields=
	{
		{  .name="int_mc", .next_ptr=&mc_mc_2_int_mc, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t sge_mpu_3_int_err = {  .name="sge.mpu[3].int_err", .addr=0x36b8630, .reg_type=0, .id=114, .field_count=27, .fields=
	{
		{  .name="results_mismatch", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="mask this interrupt, not fully implemented" },
		{  .name="sdp_mem_uncorrectable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="sdp_mem_correctable", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="illegal_op_0", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_1", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_2", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_3", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="max_inst_0", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_1", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_2", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_3", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="phvwr_0", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_1", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_2", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_3", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="write_err_0", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_1", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_2", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_3", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="cache_axi_0", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_1", .next_ptr=nullptr, .id=22, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_2", .next_ptr=nullptr, .id=23, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_3", .next_ptr=nullptr, .id=24, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_parity_0", .next_ptr=nullptr, .id=25, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_1", .next_ptr=nullptr, .id=26, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_2", .next_ptr=nullptr, .id=27, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_3", .next_ptr=nullptr, .id=28, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },

	} };
intr_reg_t sge_mpu_3_int_info = {  .name="sge.mpu[3].int_info", .addr=0x36b8640, .reg_type=0, .id=115, .field_count=8, .fields=
	{
		{  .name="trace_full_0", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_1", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_2", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="mpu_stop_0", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_1", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_2", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_3", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },

	} };
intr_reg_t sge_mpu_3_int_groups_intreg = {  .name="sge.mpu[3].int_groups.intreg", .addr=0x36b8620, .reg_type=1, .id=116, .field_count=2, .fields=
	{
		{  .name="int_err", .next_ptr=&sge_mpu_3_int_err, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_info", .next_ptr=&sge_mpu_3_int_info, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t pp_pp_port_c_7_int_c_mac = {  .name="pp.pp.port_c[7].int_c_mac", .addr=0x701f1b0, .reg_type=0, .id=176, .field_count=19, .fields=
	{
		{  .name="link_dn2up", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="link_up2dn", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="sec_bus_rst", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="rst_up2dn", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="rst_dn2up", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="portgate_open2close", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="ltssm_st_changed", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="sec_busnum_changed", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="rc_pme", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="rc_aerr", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="rc_serr", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="rc_hpe", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="rc_eq_req", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="rc_dpc", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="pm_turnoff", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="txbfr_overflow", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_FATAL, .desc="Fatal error, try to reproduce in lab and debug the configuration settings using PCIE Analyzer" },
		{  .name="rxtlp_err", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="" },
		{  .name="tl_flr_req", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="rc_legacy_intpin_changed", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },

	} };
intr_reg_t pp_pp_port_c_7_int_c_ecc = {  .name="pp.pp.port_c[7].int_c_ecc", .addr=0x701f1c0, .reg_type=0, .id=177, .field_count=8, .fields=
	{
		{  .name="rxbuf_0_uncorrectable", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="rxbuf_1_uncorrectable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="rxbuf_2_uncorrectable", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="rxbuf_3_uncorrectable", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="rxbuf_0_correctable", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="rxbuf_1_correctable", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="rxbuf_2_correctable", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="rxbuf_3_correctable", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },

	} };
intr_reg_t pp_pp_port_c_7_int_groups_intreg = {  .name="pp.pp.port_c[7].int_groups.intreg", .addr=0x701f1a0, .reg_type=1, .id=178, .field_count=2, .fields=
	{
		{  .name="int_c_mac", .next_ptr=&pp_pp_port_c_7_int_c_mac, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_c_ecc", .next_ptr=&pp_pp_port_c_7_int_c_ecc, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t md_hens_int_ipcore = {  .name="md.hens.int_ipcore", .addr=0x6584030, .reg_type=0, .id=364, .field_count=8, .fields=
	{
		{  .name="xts_enc", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="https://docs.google.com/document/d/1o7e-6AhV5ET_WoOvVRvMOXqFLDGzunZIx1R1BwUpzek/view#heading=h.e62qntm4xe7q" },
		{  .name="xts", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="https://docs.google.com/document/d/1o7e-6AhV5ET_WoOvVRvMOXqFLDGzunZIx1R1BwUpzek/view#heading=h.e62qntm4xe7q" },
		{  .name="gcm0", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="https://docs.google.com/document/d/1o7e-6AhV5ET_WoOvVRvMOXqFLDGzunZIx1R1BwUpzek/view#heading=h.e62qntm4xe7q" },
		{  .name="gcm1", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="https://docs.google.com/document/d/1o7e-6AhV5ET_WoOvVRvMOXqFLDGzunZIx1R1BwUpzek/view#heading=h.e62qntm4xe7q" },
		{  .name="drbg", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_INFO, .desc="https://docs.google.com/document/d/1o7e-6AhV5ET_WoOvVRvMOXqFLDGzunZIx1R1BwUpzek/view#heading=h.e62qntm4xe7q" },
		{  .name="pk", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_INFO, .desc="https://docs.google.com/document/d/1o7e-6AhV5ET_WoOvVRvMOXqFLDGzunZIx1R1BwUpzek/view#heading=h.e62qntm4xe7q" },
		{  .name="cp", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_INFO, .desc="https://docs.google.com/document/d/1w9UJ8ce9JcBOu_8ZdLXAdDs56Y-UO7QqCLZx7YBtQpU/edit?ts=5b7f3c37#heading=h.e62qntm4xe7q" },
		{  .name="dc", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_INFO, .desc="https://docs.google.com/document/d/1w9UJ8ce9JcBOu_8ZdLXAdDs56Y-UO7QqCLZx7YBtQpU/edit?ts=5b7f3c37#heading=h.e62qntm4xe7q" },

	} };
intr_reg_t md_hens_int_pk_ecc = {  .name="md.hens.int_pk_ecc", .addr=0x6584040, .reg_type=0, .id=365, .field_count=2, .fields=
	{
		{  .name="correctable_err", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_ERR, .desc="Hardware Error" },
		{  .name="uncorrectable_err", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_HW_RMA, .desc="Hardware Error" },

	} };
intr_reg_t md_hens_int_drbg_intram_ecc = {  .name="md.hens.int_drbg_intram_ecc", .addr=0x6584050, .reg_type=0, .id=366, .field_count=2, .fields=
	{
		{  .name="correctable_err", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_ERR, .desc="Hardware Error" },
		{  .name="uncorrectable_err", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_HW_RMA, .desc="Hardware Error" },

	} };
intr_reg_t md_hens_int_drbg_cryptoram_ecc = {  .name="md.hens.int_drbg_cryptoram_ecc", .addr=0x6584060, .reg_type=0, .id=367, .field_count=2, .fields=
	{
		{  .name="correctable_err", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_ERR, .desc="Hardware Error" },
		{  .name="uncorrectable_err", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_HW_RMA, .desc="Hardware Error" },

	} };
intr_reg_t md_hens_int_axi_err = {  .name="md.hens.int_axi_err", .addr=0x6584070, .reg_type=0, .id=368, .field_count=2, .fields=
	{
		{  .name="wrsp_err", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_ERR, .desc="Software Error" },
		{  .name="rrsp_err", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="Software Error" },

	} };
intr_reg_t md_hens_int_groups_intreg = {  .name="md.hens.int_groups.intreg", .addr=0x6584020, .reg_type=1, .id=369, .field_count=5, .fields=
	{
		{  .name="int_ipcore", .next_ptr=&md_hens_int_ipcore, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_pk_ecc", .next_ptr=&md_hens_int_pk_ecc, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_drbg_intram_ecc", .next_ptr=&md_hens_int_drbg_intram_ecc, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_drbg_cryptoram_ecc", .next_ptr=&md_hens_int_drbg_cryptoram_ecc, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_axi_err", .next_ptr=&md_hens_int_axi_err, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t pt_pt_int_reg1 = {  .name="pt.pt.int_reg1", .addr=0x6220420, .reg_type=0, .id=179, .field_count=2, .fields=
	{
		{  .name="slave_ptd", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="slave_psp", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };
intr_reg_t pt_pt_int_groups_intreg = {  .name="pt.pt.int_groups.intreg", .addr=0x6220410, .reg_type=1, .id=180, .field_count=1, .fields=
	{
		{  .name="int_reg1", .next_ptr=&pt_pt_int_reg1, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t sgi_mpu_0_int_err = {  .name="sgi.mpu[0].int_err", .addr=0x36e8630, .reg_type=0, .id=57, .field_count=27, .fields=
	{
		{  .name="results_mismatch", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="mask this interrupt, not fully implemented" },
		{  .name="sdp_mem_uncorrectable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="sdp_mem_correctable", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="illegal_op_0", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_1", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_2", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_3", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="max_inst_0", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_1", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_2", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_3", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="phvwr_0", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_1", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_2", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_3", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="write_err_0", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_1", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_2", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_3", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="cache_axi_0", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_1", .next_ptr=nullptr, .id=22, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_2", .next_ptr=nullptr, .id=23, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_3", .next_ptr=nullptr, .id=24, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_parity_0", .next_ptr=nullptr, .id=25, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_1", .next_ptr=nullptr, .id=26, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_2", .next_ptr=nullptr, .id=27, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_3", .next_ptr=nullptr, .id=28, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },

	} };
intr_reg_t sgi_mpu_0_int_info = {  .name="sgi.mpu[0].int_info", .addr=0x36e8640, .reg_type=0, .id=58, .field_count=8, .fields=
	{
		{  .name="trace_full_0", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_1", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_2", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="mpu_stop_0", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_1", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_2", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_3", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },

	} };
intr_reg_t sgi_mpu_0_int_groups_intreg = {  .name="sgi.mpu[0].int_groups.intreg", .addr=0x36e8620, .reg_type=1, .id=59, .field_count=2, .fields=
	{
		{  .name="int_err", .next_ptr=&sgi_mpu_0_int_err, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_info", .next_ptr=&sgi_mpu_0_int_info, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t sge_mpu_5_int_err = {  .name="sge.mpu[5].int_err", .addr=0x36d8630, .reg_type=0, .id=120, .field_count=27, .fields=
	{
		{  .name="results_mismatch", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="mask this interrupt, not fully implemented" },
		{  .name="sdp_mem_uncorrectable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="sdp_mem_correctable", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="illegal_op_0", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_1", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_2", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="illegal_op_3", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="MPU executed illegal opcode (likely a jump to bad address or code space written over by DMA)" },
		{  .name="max_inst_0", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_1", .next_ptr=nullptr, .id=10, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_2", .next_ptr=nullptr, .id=11, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="max_inst_3", .next_ptr=nullptr, .id=12, .severity=INTR_SEV_TYPE_ERR, .desc="MPU exceeded max instruction count for one program" },
		{  .name="phvwr_0", .next_ptr=nullptr, .id=13, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_1", .next_ptr=nullptr, .id=14, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_2", .next_ptr=nullptr, .id=15, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="phvwr_3", .next_ptr=nullptr, .id=16, .severity=INTR_SEV_TYPE_ERR, .desc="Illegal phvwr command or offset" },
		{  .name="write_err_0", .next_ptr=nullptr, .id=17, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_1", .next_ptr=nullptr, .id=18, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_2", .next_ptr=nullptr, .id=19, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="write_err_3", .next_ptr=nullptr, .id=20, .severity=INTR_SEV_TYPE_ERR, .desc="MPU write returned error on acknowledge, likely an address error" },
		{  .name="cache_axi_0", .next_ptr=nullptr, .id=21, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_1", .next_ptr=nullptr, .id=22, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_2", .next_ptr=nullptr, .id=23, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_axi_3", .next_ptr=nullptr, .id=24, .severity=INTR_SEV_TYPE_ERR, .desc="instruction cache fill returned response error, likely memory address error" },
		{  .name="cache_parity_0", .next_ptr=nullptr, .id=25, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_1", .next_ptr=nullptr, .id=26, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_2", .next_ptr=nullptr, .id=27, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },
		{  .name="cache_parity_3", .next_ptr=nullptr, .id=28, .severity=INTR_SEV_TYPE_FATAL, .desc="instruction cache parity error" },

	} };
intr_reg_t sge_mpu_5_int_info = {  .name="sge.mpu[5].int_info", .addr=0x36d8640, .reg_type=0, .id=121, .field_count=8, .fields=
	{
		{  .name="trace_full_0", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_1", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_2", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="trace_full_3", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_INFO, .desc="MPU debug trace buffer has filled" },
		{  .name="mpu_stop_0", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_1", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_2", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },
		{  .name="mpu_stop_3", .next_ptr=nullptr, .id=9, .severity=INTR_SEV_TYPE_ERR, .desc="MPU stopped, in debug mode, pipeline frozen until start" },

	} };
intr_reg_t sge_mpu_5_int_groups_intreg = {  .name="sge.mpu[5].int_groups.intreg", .addr=0x36d8620, .reg_type=1, .id=122, .field_count=2, .fields=
	{
		{  .name="int_err", .next_ptr=&sge_mpu_5_int_err, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_info", .next_ptr=&sge_mpu_5_int_info, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t db_wa_int_lif_qstate_map = {  .name="db.wa.int_lif_qstate_map", .addr=0x8e30010, .reg_type=0, .id=347, .field_count=3, .fields=
	{
		{  .name="ecc_uncorrectable", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_HW_RMA, .desc="ecc uncorrectable DOUBLE bit SOFT error, expect once per 250 years per chip" },
		{  .name="ecc_correctable", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="ecc correctable single bit SOFT error, expect once per 25 years per chip" },
		{  .name="qid_invalid", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="" },

	} };
intr_reg_t db_wa_int_db = {  .name="db.wa.int_db", .addr=0x8e20320, .reg_type=0, .id=348, .field_count=7, .fields=
	{
		{  .name="db_cam_conflict", .next_ptr=nullptr, .id=2, .severity=INTR_SEV_TYPE_INFO, .desc="Info only, no action" },
		{  .name="db_pid_chk_fail", .next_ptr=nullptr, .id=3, .severity=INTR_SEV_TYPE_ERR, .desc="" },
		{  .name="db_qid_overflow", .next_ptr=nullptr, .id=4, .severity=INTR_SEV_TYPE_ERR, .desc="" },
		{  .name="host_ring_access_err", .next_ptr=nullptr, .id=5, .severity=INTR_SEV_TYPE_ERR, .desc="" },
		{  .name="total_ring_access_err", .next_ptr=nullptr, .id=6, .severity=INTR_SEV_TYPE_ERR, .desc="" },
		{  .name="rresp_err", .next_ptr=nullptr, .id=7, .severity=INTR_SEV_TYPE_ERR, .desc="" },
		{  .name="bresp_err", .next_ptr=nullptr, .id=8, .severity=INTR_SEV_TYPE_ERR, .desc="" },

	} };
intr_reg_t db_wa_int_groups_intreg = {  .name="db.wa.int_groups.intreg", .addr=0x8e20310, .reg_type=1, .id=349, .field_count=2, .fields=
	{
		{  .name="int_lif_qstate_map", .next_ptr=&db_wa_int_lif_qstate_map, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="int_db", .next_ptr=&db_wa_int_db, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t all_csrs = {  .name="all_csrs", .addr=0x0, .reg_type=2, .id=0, .field_count=124, .fields=
	{
		{  .name="sgi_mpu_2_int_groups_intreg", .next_ptr=&sgi_mpu_2_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pcr_te_0_int_groups_intreg", .next_ptr=&pcr_te_0_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="sgi_mpu_5_int_groups_intreg", .next_ptr=&sgi_mpu_5_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pct_te_1_int_groups_intreg", .next_ptr=&pct_te_1_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="mc_mc_7_int_groups_intreg", .next_ptr=&mc_mc_7_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pcr_te_5_int_groups_intreg", .next_ptr=&pcr_te_5_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pp_pp_port_c_5_int_groups_intreg", .next_ptr=&pp_pp_port_c_5_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="mc_mc_3_int_groups_intreg", .next_ptr=&mc_mc_3_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="mc_mc_0_mch_int_groups_intreg", .next_ptr=&mc_mc_0_mch_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="dpr_dpr_1_int_groups_intreg", .next_ptr=&dpr_dpr_1_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pt_pt_psp_int_groups_intreg", .next_ptr=&pt_pt_psp_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="mx_mx_1_int_groups_intreg", .next_ptr=&mx_mx_1_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="mc_mc_2_mch_int_groups_intreg", .next_ptr=&mc_mc_2_mch_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="sema_sema_int_groups_intreg", .next_ptr=&sema_sema_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="ppa_ppa_0_int_groups_intreg", .next_ptr=&ppa_ppa_0_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pcr_te_6_int_groups_intreg", .next_ptr=&pcr_te_6_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="mc_mc_1_mch_int_groups_intreg", .next_ptr=&mc_mc_1_mch_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="sge_mpu_1_int_groups_intreg", .next_ptr=&sge_mpu_1_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="mc_mc_5_int_groups_intreg", .next_ptr=&mc_mc_5_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="dpr_dpr_0_int_groups_intreg", .next_ptr=&dpr_dpr_0_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pp_pp_port_c_0_int_groups_intreg", .next_ptr=&pp_pp_port_c_0_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pb_pbc_hbm_int_groups_intreg", .next_ptr=&pb_pbc_hbm_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pcr_mpu_0_int_groups_intreg", .next_ptr=&pcr_mpu_0_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pct_mpu_0_int_groups_intreg", .next_ptr=&pct_mpu_0_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pct_mpu_4_int_groups_intreg", .next_ptr=&pct_mpu_4_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="tpc_pics_picc_int_groups_intreg", .next_ptr=&tpc_pics_picc_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="mc_mc_4_mch_int_groups_intreg", .next_ptr=&mc_mc_4_mch_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pcr_te_3_int_groups_intreg", .next_ptr=&pcr_te_3_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="sgi_te_2_int_groups_intreg", .next_ptr=&sgi_te_2_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pct_mpu_7_int_groups_intreg", .next_ptr=&pct_mpu_7_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="txs_txs_int_groups_intreg", .next_ptr=&txs_txs_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="sgi_te_0_int_groups_intreg", .next_ptr=&sgi_te_0_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pct_mpu_3_int_groups_intreg", .next_ptr=&pct_mpu_3_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pcr_mpu_4_int_groups_intreg", .next_ptr=&pcr_mpu_4_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pb_pbc_int_groups_intreg", .next_ptr=&pb_pbc_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="mc_mc_6_int_groups_intreg", .next_ptr=&mc_mc_6_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pcr_te_4_int_groups_intreg", .next_ptr=&pcr_te_4_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="sse_pics_int_groups_intreg", .next_ptr=&sse_pics_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pct_te_2_int_groups_intreg", .next_ptr=&pct_te_2_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pp_pp_port_p_1_int_groups_intreg", .next_ptr=&pp_pp_port_p_1_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="sgi_te_1_int_groups_intreg", .next_ptr=&sgi_te_1_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="ssi_pics_int_groups_intreg", .next_ptr=&ssi_pics_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="mc_mc_0_int_groups_intreg", .next_ptr=&mc_mc_0_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="dpp_dpp_0_int_groups_intreg", .next_ptr=&dpp_dpp_0_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pr_pr_int_groups_intreg", .next_ptr=&pr_pr_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="sgi_mpu_1_int_groups_intreg", .next_ptr=&sgi_mpu_1_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="tpc_pics_int_groups_intreg", .next_ptr=&tpc_pics_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="sgi_te_5_int_groups_intreg", .next_ptr=&sgi_te_5_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pcr_te_7_int_groups_intreg", .next_ptr=&pcr_te_7_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pcr_mpu_3_int_groups_intreg", .next_ptr=&pcr_mpu_3_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pp_pp_port_c_1_int_groups_intreg", .next_ptr=&pp_pp_port_c_1_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pcr_mpu_1_int_groups_intreg", .next_ptr=&pcr_mpu_1_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pcr_mpu_2_int_groups_intreg", .next_ptr=&pcr_mpu_2_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="sgi_mpu_3_int_groups_intreg", .next_ptr=&sgi_mpu_3_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pct_te_6_int_groups_intreg", .next_ptr=&pct_te_6_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="mc_mc_7_mch_int_groups_intreg", .next_ptr=&mc_mc_7_mch_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pt_pt_ptd_int_groups_intreg", .next_ptr=&pt_pt_ptd_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="mx_mx_0_int_groups_intreg", .next_ptr=&mx_mx_0_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="dpp_dpp_1_int_groups_intreg", .next_ptr=&dpp_dpp_1_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="rpc_pics_int_groups_intreg", .next_ptr=&rpc_pics_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="sge_te_0_int_groups_intreg", .next_ptr=&sge_te_0_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="mc_mc_4_int_groups_intreg", .next_ptr=&mc_mc_4_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="rpc_pics_picc_int_groups_intreg", .next_ptr=&rpc_pics_picc_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="mp_mpns_int_groups_intreg", .next_ptr=&mp_mpns_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pct_mpu_2_int_groups_intreg", .next_ptr=&pct_mpu_2_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pp_pp_port_c_3_int_groups_intreg", .next_ptr=&pp_pp_port_c_3_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="ms_em_int_groups_intreg", .next_ptr=&ms_em_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="intr_intr_int_groups_intreg", .next_ptr=&intr_intr_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="sge_mpu_2_int_groups_intreg", .next_ptr=&sge_mpu_2_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="sge_te_2_int_groups_intreg", .next_ptr=&sge_te_2_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pp_pp_port_c_6_int_groups_intreg", .next_ptr=&pp_pp_port_c_6_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="sge_mpu_0_int_groups_intreg", .next_ptr=&sge_mpu_0_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pct_te_4_int_groups_intreg", .next_ptr=&pct_te_4_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pcr_te_1_int_groups_intreg", .next_ptr=&pcr_te_1_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="mc_mc_5_mch_int_groups_intreg", .next_ptr=&mc_mc_5_mch_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pcr_te_2_int_groups_intreg", .next_ptr=&pcr_te_2_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pm_pbm_int_groups_intreg", .next_ptr=&pm_pbm_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="ms_ms_int_groups_intreg", .next_ptr=&ms_ms_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="mc_mc_3_mch_int_groups_intreg", .next_ptr=&mc_mc_3_mch_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="ssi_pics_picc_int_groups_intreg", .next_ptr=&ssi_pics_picc_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="mc_mc_1_int_groups_intreg", .next_ptr=&mc_mc_1_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="sgi_te_4_int_groups_intreg", .next_ptr=&sgi_te_4_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pcr_mpu_7_int_groups_intreg", .next_ptr=&pcr_mpu_7_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pcr_mpu_5_int_groups_intreg", .next_ptr=&pcr_mpu_5_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pct_mpu_5_int_groups_intreg", .next_ptr=&pct_mpu_5_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pct_te_3_int_groups_intreg", .next_ptr=&pct_te_3_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pr_pr_prd_int_groups_intreg", .next_ptr=&pr_pr_prd_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pxb_pxb_int_groups_intreg", .next_ptr=&pxb_pxb_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pct_te_7_int_groups_intreg", .next_ptr=&pct_te_7_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pp_pp_port_c_4_int_groups_intreg", .next_ptr=&pp_pp_port_c_4_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pct_te_5_int_groups_intreg", .next_ptr=&pct_te_5_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="sge_te_4_int_groups_intreg", .next_ptr=&sge_te_4_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="sgi_te_3_int_groups_intreg", .next_ptr=&sgi_te_3_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="sge_te_1_int_groups_intreg", .next_ptr=&sge_te_1_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pcr_mpu_6_int_groups_intreg", .next_ptr=&pcr_mpu_6_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pp_pp_port_p_7_int_groups_intreg", .next_ptr=&pp_pp_port_p_7_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="sge_mpu_4_int_groups_intreg", .next_ptr=&sge_mpu_4_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pp_pp_port_p_4_int_groups_intreg", .next_ptr=&pp_pp_port_p_4_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pp_pp_port_p_5_int_groups_intreg", .next_ptr=&pp_pp_port_p_5_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pp_pp_port_p_6_int_groups_intreg", .next_ptr=&pp_pp_port_p_6_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="sge_te_5_int_groups_intreg", .next_ptr=&sge_te_5_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pp_pp_port_p_0_int_groups_intreg", .next_ptr=&pp_pp_port_p_0_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pr_pr_psp_int_groups_intreg", .next_ptr=&pr_pr_psp_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pp_pp_port_p_2_int_groups_intreg", .next_ptr=&pp_pp_port_p_2_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pct_te_0_int_groups_intreg", .next_ptr=&pct_te_0_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="sse_pics_picc_int_groups_intreg", .next_ptr=&sse_pics_picc_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="sge_te_3_int_groups_intreg", .next_ptr=&sge_te_3_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pct_mpu_6_int_groups_intreg", .next_ptr=&pct_mpu_6_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="bx_bx_int_groups_intreg", .next_ptr=&bx_bx_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pp_pp_int_groups_intreg", .next_ptr=&pp_pp_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pp_pp_port_c_2_int_groups_intreg", .next_ptr=&pp_pp_port_c_2_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="mc_mc_6_mch_int_groups_intreg", .next_ptr=&mc_mc_6_mch_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="sgi_mpu_4_int_groups_intreg", .next_ptr=&sgi_mpu_4_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="ppa_ppa_1_int_groups_intreg", .next_ptr=&ppa_ppa_1_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pct_mpu_1_int_groups_intreg", .next_ptr=&pct_mpu_1_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pp_pp_port_p_3_int_groups_intreg", .next_ptr=&pp_pp_port_p_3_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="mc_mc_2_int_groups_intreg", .next_ptr=&mc_mc_2_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="sge_mpu_3_int_groups_intreg", .next_ptr=&sge_mpu_3_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pp_pp_port_c_7_int_groups_intreg", .next_ptr=&pp_pp_port_c_7_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="md_hens_int_groups_intreg", .next_ptr=&md_hens_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pt_pt_int_groups_intreg", .next_ptr=&pt_pt_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="sgi_mpu_0_int_groups_intreg", .next_ptr=&sgi_mpu_0_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="sge_mpu_5_int_groups_intreg", .next_ptr=&sge_mpu_5_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="db_wa_int_groups_intreg", .next_ptr=&db_wa_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

intr_reg_t cap0 = {  .name="cap0", .addr=0x0, .reg_type=2, .id=0, .field_count=91, .fields=
	{
		{  .name="ppa_ppa_0", .next_ptr=&ppa_ppa_0_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="ppa_ppa_1", .next_ptr=&ppa_ppa_1_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="sgi_te_0", .next_ptr=&sgi_te_0_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="sgi_te_1", .next_ptr=&sgi_te_1_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="sgi_te_2", .next_ptr=&sgi_te_2_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="sgi_te_3", .next_ptr=&sgi_te_3_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="sgi_te_4", .next_ptr=&sgi_te_4_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="sgi_te_5", .next_ptr=&sgi_te_5_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="sgi_mpu_0", .next_ptr=&sgi_mpu_0_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="sgi_mpu_1", .next_ptr=&sgi_mpu_1_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="sgi_mpu_2", .next_ptr=&sgi_mpu_2_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="sgi_mpu_3", .next_ptr=&sgi_mpu_3_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="sgi_mpu_4", .next_ptr=&sgi_mpu_4_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="sgi_mpu_5", .next_ptr=&sgi_mpu_5_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="rpc_pics", .next_ptr=&rpc_pics_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="intr_intr", .next_ptr=&intr_intr_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pxb_pxb", .next_ptr=&pxb_pxb_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="sge_te_0", .next_ptr=&sge_te_0_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="sge_te_1", .next_ptr=&sge_te_1_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="sge_te_2", .next_ptr=&sge_te_2_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="sge_te_3", .next_ptr=&sge_te_3_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="sge_te_4", .next_ptr=&sge_te_4_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="sge_te_5", .next_ptr=&sge_te_5_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="sge_mpu_0", .next_ptr=&sge_mpu_0_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="sge_mpu_1", .next_ptr=&sge_mpu_1_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="sge_mpu_2", .next_ptr=&sge_mpu_2_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="sge_mpu_3", .next_ptr=&sge_mpu_3_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="sge_mpu_4", .next_ptr=&sge_mpu_4_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="sge_mpu_5", .next_ptr=&sge_mpu_5_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pr_pr", .next_ptr=&pr_pr_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pp_pp", .next_ptr=&pp_pp_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pt_pt", .next_ptr=&pt_pt_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pcr_te_0", .next_ptr=&pcr_te_0_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pcr_te_1", .next_ptr=&pcr_te_1_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pcr_te_2", .next_ptr=&pcr_te_2_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pcr_te_3", .next_ptr=&pcr_te_3_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pcr_te_4", .next_ptr=&pcr_te_4_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pcr_te_5", .next_ptr=&pcr_te_5_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pcr_te_6", .next_ptr=&pcr_te_6_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pcr_te_7", .next_ptr=&pcr_te_7_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pcr_mpu_0", .next_ptr=&pcr_mpu_0_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pcr_mpu_1", .next_ptr=&pcr_mpu_1_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pcr_mpu_2", .next_ptr=&pcr_mpu_2_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pcr_mpu_3", .next_ptr=&pcr_mpu_3_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pcr_mpu_4", .next_ptr=&pcr_mpu_4_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pcr_mpu_5", .next_ptr=&pcr_mpu_5_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pcr_mpu_6", .next_ptr=&pcr_mpu_6_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pcr_mpu_7", .next_ptr=&pcr_mpu_7_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="txs_txs", .next_ptr=&txs_txs_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pct_te_0", .next_ptr=&pct_te_0_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pct_te_1", .next_ptr=&pct_te_1_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pct_te_2", .next_ptr=&pct_te_2_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pct_te_3", .next_ptr=&pct_te_3_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pct_te_4", .next_ptr=&pct_te_4_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pct_te_5", .next_ptr=&pct_te_5_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pct_te_6", .next_ptr=&pct_te_6_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pct_te_7", .next_ptr=&pct_te_7_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pct_mpu_0", .next_ptr=&pct_mpu_0_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pct_mpu_1", .next_ptr=&pct_mpu_1_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pct_mpu_2", .next_ptr=&pct_mpu_2_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pct_mpu_3", .next_ptr=&pct_mpu_3_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pct_mpu_4", .next_ptr=&pct_mpu_4_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pct_mpu_5", .next_ptr=&pct_mpu_5_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pct_mpu_6", .next_ptr=&pct_mpu_6_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pct_mpu_7", .next_ptr=&pct_mpu_7_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pb_pbc", .next_ptr=&pb_pbc_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="pm_pbm", .next_ptr=&pm_pbm_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="db_wa", .next_ptr=&db_wa_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="ssi_pics", .next_ptr=&ssi_pics_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="sse_pics", .next_ptr=&sse_pics_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="bx_bx", .next_ptr=&bx_bx_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="md_hens", .next_ptr=&md_hens_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="tpc_pics", .next_ptr=&tpc_pics_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="dpr_dpr_0", .next_ptr=&dpr_dpr_0_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="dpr_dpr_1", .next_ptr=&dpr_dpr_1_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="mc_mc_0", .next_ptr=&mc_mc_0_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="mc_mc_1", .next_ptr=&mc_mc_1_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="mc_mc_2", .next_ptr=&mc_mc_2_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="mc_mc_3", .next_ptr=&mc_mc_3_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="mc_mc_4", .next_ptr=&mc_mc_4_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="mc_mc_5", .next_ptr=&mc_mc_5_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="mc_mc_6", .next_ptr=&mc_mc_6_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="mc_mc_7", .next_ptr=&mc_mc_7_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="dpp_dpp_0", .next_ptr=&dpp_dpp_0_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="dpp_dpp_1", .next_ptr=&dpp_dpp_1_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="sema_sema", .next_ptr=&sema_sema_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="mp_mpns", .next_ptr=&mp_mpns_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="ms_ms", .next_ptr=&ms_ms_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="ms_em", .next_ptr=&ms_em_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="mx_mx_0", .next_ptr=&mx_mx_0_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },
		{  .name="mx_mx_1", .next_ptr=&mx_mx_1_int_groups_intreg, .id=0, .severity=INTR_SEV_TYPE_INFO, .desc="" },

	} };

