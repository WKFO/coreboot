/*
 * This file is part of the coreboot project.
 *
 * Copyright (C) 2006-2007 Advanced Micro Devices, Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA
 */

/* Until we resolve a better way to do this, work around it with a value "too large to fail" */

#ifndef AMD_K8_H
#define AMD_K8_H
/* Socket types */
#define SOCKET_S1G1 0x12
#define SOCKET_AM2 0x11
#define SOCKET_L1	0x10

#define ROM_CODE_SEG		0x08
#define ROM_DATA_SEG		0x10

#define CACHE_RAM_CODE_SEG	0x18
#define CACHE_RAM_DATA_SEG	0x20

#define IORR_FIRST 0xC0010016
#define IORR_LAST  0xC0010019

#define MTRR_READ_MEM			(1 << 4)
#define MTRR_WRITE_MEM			(1 << 3)

#define SYSCFG_MSR			0xC0010010
#define SYSCFG_MSR_TOM2En		(1 << 21)
#define SYSCFG_MSR_MtrrVarDramEn	(1 << 20)
#define SYSCFG_MSR_MtrrFixDramModEn	(1 << 19)
#define SYSCFG_MSR_MtrrFixDramEn	(1 << 18)
#define SYSCFG_MSR_UcLockEn		(1 << 17)
#define SYSCFG_MSR_ChxToDirtyDis	(1 << 16)
#define SYSCFG_MSR_ClVicBlkEn		(1 << 11)
#define SYSCFG_MSR_SetDirtyEnO		(1 << 10)
#define SYSCFG_MSR_SetDirtyEnS		(1 <<  9)
#define SYSCFG_MSR_SetDirtyEnE		(1 <<  8)
#define SYSCFG_MSR_SysVicLimitMask	((1 << 8) - (1 << 5))
#define SYSCFG_MSR_SysAckLimitMask	((1 << 5) - (1 << 0))

#define IORR0_BASE			0xC0010016
#define IORR0_MASK			0xC0010017
#define IORR1_BASE			0xC0010018
#define IORR1_MASK			0xC0010019
#define TOP_MEM				0xC001001A
#define TOP_MEM2			0xC001001D

#define TOP_MEM_MASK			0x007fffff
#define TOP_MEM_MASK_KB			(TOP_MEM_MASK >> 10)

/* MSRs for the model_fxx */
/* the comments are confusing. Does "only E0" mean "only E0 or later" or really "Only E0"
 */
#define HWCR_MSR			0xC0010015
#define NB_CFG_MSR			0xC001001f
#define LS_CFG_MSR                      0xC0011020
#define IC_CFG_MSR			0xC0011021
#define DC_CFG_MSR			0xC0011022
#define BU_CFG_MSR			0xC0011023
#define FIDVID_CTL				0xC0010041
#define FIDVID_STATUS			0xC0010042


#define CPU_ID_FEATURES_MSR		0xc0011004

/* D0 only */
#define CPU_ID_HYPER_EXT_FEATURES	0xc001100d
/* E0 only */
#define LOGICAL_CPUS_NUM_MSR		0xc001100d

#define CPU_ID_EXT_FEATURES_MSR		0xc0011005

/* Definitions of various K8 registers for REV F*/
/* Function 0 */
#define NODEID 0x60
#define HT_TRANSACTION_CONTROL 0x68
#define  HTTC_DIS_RD_B_P            (1 << 0)
#define  HTTC_DIS_RD_DW_P           (1 << 1)
#define  HTTC_DIS_WR_B_P            (1 << 2)
#define  HTTC_DIS_WR_DW_P           (1 << 3)
#define  HTTC_DIS_MTS               (1 << 4)
#define  HTTC_CPU1_EN               (1 << 5)
#define  HTTC_CPU_REQ_PASS_PW       (1 << 6)
#define  HTTC_CPU_RD_RSP_PASS_PW    (1 << 7)
#define  HTTC_DIS_P_MEM_C           (1 << 8)
#define  HTTC_DIS_RMT_MEM_C         (1 << 9)
#define  HTTC_DIS_FILL_P            (1 << 10)
#define  HTTC_RSP_PASS_PW           (1 << 11)
#define  HTTC_CHG_ISOC_TO_ORD       (1 << 12)
#define  HTTC_BUF_REL_PRI_SHIFT     13
#define  HTTC_BUF_REL_PRI_MASK      3
#define   HTTC_BUF_REL_PRI_64       0
#define   HTTC_BUF_REL_PRI_16       1
#define   HTTC_BUF_REL_PRI_8        2
#define   HTTC_BUF_REL_PRI_2        3
#define  HTTC_LIMIT_CLDT_CFG        (1 << 15)
#define  HTTC_LINT_EN               (1 << 16)
#define  HTTC_APIC_EXT_BRD_CST      (1 << 17)
#define  HTTC_APIC_EXT_ID           (1 << 18)
#define  HTTC_APIC_EXT_SPUR         (1 << 19)
#define  HTTC_SEQ_ID_SRC_NODE_EN    (1 << 20)
#define  HTTC_DS_NP_REQ_LIMIT_SHIFT 21
#define  HTTC_DS_NP_REQ_LIMIT_MASK  3
#define   HTTC_DS_NP_REQ_LIMIT_NONE 0
#define   HTTC_DS_NP_REQ_LIMIT_1    1
#define   HTTC_DS_NP_REQ_LIMIT_4    2
#define   HTTC_DS_NP_REQ_LIMIT_8    3
#define  HTTC_MED_PRI_BYP_CNT_SHIFT 24
#define  HTTC_MED_PRI_BYP_CNT_MASK  3
#define  HTTC_HI_PRI_BYP_CNT_SHIFT  26
#define  HTTC_HI_PRI_BYP_CNT_MASK   3

#define	HT_INIT_CONTROL 0x6c
#define HTIC_ColdR_Detect  (1<<4)
#define HTIC_BIOSR_Detect  (1<<5)
#define HTIC_INIT_Detect   (1<<6)

/* Function 1 */
#define PCI_IO_BASE0       0xc0
#define PCI_IO_BASE1       0xc8
#define PCI_IO_BASE2       0xd0
#define PCI_IO_BASE3       0xd8
#define PCI_IO_BASE_VGA_EN (1 << 4)
#define PCI_IO_BASE_NO_ISA (1 << 5)


/* Function 2 */
#define DRAM_CSBASE	   0x40
#define DRAM_CSMASK	   0x60
#define DRAM_BANK_ADDR_MAP 0x80

#define DRAM_CTRL	0x78
#define  DC_RdPtrInit_SHIFT 0
#define  DC_RdPrtInit_MASK  0xf
#define  DC_RdPadRcvFifoDly_SHIFT 4
#define  DC_RdPadRcvFifoDly_MASK  7
#define   DC_RdPadRcvFiloDly_1_5_CLK 2
#define   DC_RdPadRcvFiloDly_2_CLK 3
#define   DC_RdPadRcvFiloDly_2_5_CLK 4
#define   DC_RdPadRcvFiloDly_3_CLK 5
#define   DC_RdPadRcvFiloDly_3_5_CLK 6
#define  DC_AltVidC3MemClkTriEn (1<<16)
#define  DC_DllTempAdjTime_SHIFT 17
#define  DC_DllTempAdjTime_MASK 1
#define   DC_DllTempAdjTime_5_MS 0
#define   DC_DllTempAdjTime_1_MS 1
#define  DC_DqsRcvEnTrain (1<<18)

#define DRAM_INIT	0x7c
#define  DI_MrsAddress_SHIFT 0
#define  DI_MrsAddress_MASK 0xffff
#define  DI_MrsBank_SHIFT 16
#define  DI_MrsBank_MASK 7
#define  DI_SendRchgAll (1<<24)
#define  DI_SendAutoRefresh (1<<25)
#define  DI_SendMrsCmd   (1<<26)
#define  DI_DeassertMemRstX (1<<27)
#define  DI_AssertCke   (1<<28)
#define  DI_EnDramInit  (1<<31)

#define DRAM_TIMING_LOW	   0x88
#define	 DTL_TCL_SHIFT	   0
#define	 DTL_TCL_MASK	   7
#define	  DTL_TCL_BASE 	   1 
#define	  DTL_TCL_MIN	   3
#define	  DTL_TCL_MAX	   6
#define	 DTL_TRCD_SHIFT	   4
#define	 DTL_TRCD_MASK	   3
#define	  DTL_TRCD_BASE	   3
#define	  DTL_TRCD_MIN	   3
#define   DTL_TRCD_MAX     6
#define	 DTL_TRP_SHIFT	   8
#define	 DTL_TRP_MASK	   3
#define	  DTL_TRP_BASE	   3
#define	  DTL_TRP_MIN	   3
#define   DTL_TRP_MAX      6
#define	 DTL_TRTP_SHIFT	   11
#define	 DTL_TRTP_MASK	   1
#define	  DTL_TRTP_BASE	   2
#define	  DTL_TRTP_MIN	   2  /* 4 for 64 bytes*/
#define   DTL_TRTP_MAX     3  /* 5 for 64 bytes */
#define	 DTL_TRAS_SHIFT	   12
#define	 DTL_TRAS_MASK	   0xf
#define	  DTL_TRAS_BASE	   3
#define	  DTL_TRAS_MIN	   5
#define	  DTL_TRAS_MAX	   18
#define	 DTL_TRC_SHIFT	   16
#define	 DTL_TRC_MASK	   0xf
#define	  DTL_TRC_BASE	   11
#define	  DTL_TRC_MIN	   11
#define	  DTL_TRC_MAX	   26
#define	 DTL_TWR_SHIFT	   20
#define	 DTL_TWR_MASK	   3
#define	  DTL_TWR_BASE	   3
#define	  DTL_TWR_MIN	   3
#define	  DTL_TWR_MAX	   6
#define  DTL_TRRD_SHIFT    22
#define   DTL_TRRD_MASK    3
#define   DTL_TRRD_BASE    2
#define   DTL_TRRD_MIN	   2
#define   DTL_TRRD_MAX     5
#define  DTL_MemClkDis_SHIFT 24    /* Channel A */ 
#define  DTL_MemClkDis3       (1 << 26)
#define  DTL_MemClkDis2       (1 << 27)
#define  DTL_MemClkDis1       (1 << 28)
#define  DTL_MemClkDis0       (1 << 29)
#define  DTL_MemClkDis1_AM2       (0x51 << 24)
#define  DTL_MemClkDis0_AM2       (0xa2 << 24)
#define  DTL_MemClkDis0_S1g1      (0xa2 << 24)

/* DTL_MemClkDis for m2 and s1g1 is different */
 
#define DRAM_TIMING_HIGH   0x8c
#define  DTH_TRWTTO_SHIFT  4
#define  DTH_TRWTTO_MASK   7
#define   DTH_TRWTTO_BASE   2 
#define   DTH_TRWTTO_MIN    2
#define   DTH_TRWTTO_MAX    9
#define	 DTH_TWTR_SHIFT	   8
#define	 DTH_TWTR_MASK	   3
#define	  DTH_TWTR_BASE	   0 
#define	  DTH_TWTR_MIN	   1
#define	  DTH_TWTR_MAX	   3
#define	 DTH_TWRRD_SHIFT   10
#define	 DTH_TWRRD_MASK	   3
#define	  DTH_TWRRD_BASE   0
#define	  DTH_TWRRD_MIN	   0
#define	  DTH_TWRRD_MAX	   3
#define  DTH_TWRWR_SHIFT   12
#define  DTH_TWRWR_MASK    3
#define   DTH_TWRWR_BASE   1 
#define   DTH_TWRWR_MIN    1
#define   DTH_TWRWR_MAX    3
#define  DTH_TRDRD_SHIFT   14
#define  DTH_TRDRD_MASK    3
#define   DTH_TRDRD_BASE   2
#define   DTH_TRDRD_MIN    2
#define   DTH_TRDRD_MAX    5
#define	 DTH_TREF_SHIFT	   16
#define	 DTH_TREF_MASK	   3
#define	  DTH_TREF_7_8_US  2
#define	  DTH_TREF_3_9_US  3
#define  DTH_TRFC0_SHIFT   20 /* for Logical DIMM0 */
#define  DTH_TRFC_MASK      7  
#define	  DTH_TRFC_75_256M   0
#define	  DTH_TRFC_105_512M  1
#define   DTH_TRFC_127_5_1G  2
#define   DTH_TRFC_195_2G    3
#define   DTH_TRFC_327_5_4G  4
#define  DTH_TRFC1_SHIFT   23 /*for Logical DIMM1 */
#define  DTH_TRFC2_SHIFT   26 /*for Logical DIMM2 */
#define  DTH_TRFC3_SHIFT   29 /*for Logical DIMM3 */

#define DRAM_CONFIG_LOW	   0x90
#define	 DCL_InitDram	   (1<<0)
#define	 DCL_ExitSelfRef   (1<<1)
#define  DCL_DramTerm_SHIFT 4
#define  DCL_DramTerm_MASK  3
#define   DCL_DramTerm_No   0
#define   DCL_DramTerm_75_OH 1
#define   DCL_DramTerm_150_OH 2
#define   DCL_DramTerm_50_OH 3     
#define  DCL_DrvWeak	   (1<<7)
#define  DCL_ParEn	   (1<<8)
#define  DCL_SelfRefRateEn (1<<9)
#define  DCL_BurstLength32 (1<<10)
#define  DCL_Width128	   (1<<11) 
#define  DCL_X4Dimm_SHIFT  12
#define  DCL_X4Dimm_MASK   0xf
#define  DCL_UnBuffDimm    (1<<16)
#define	 DCL_DimmEccEn	   (1<<19)

#define DRAM_CONFIG_HIGH   0x94
#define  DCH_MemClkFreq_SHIFT 0
#define  DCH_MemClkFreq_MASK  7
#define   DCH_MemClkFreq_200MHz 0
#define   DCH_MemClkFreq_266MHz 1
#define   DCH_MemClkFreq_333MHz 2
#define	  DCH_MemClkFreq_400MHz 3
#define  DCH_MemClkFreqVal	(1<<3)
#define	 DCH_MaxAsyncLat_SHIFT  4
#define	 DCH_MaxAsyncLat_MASK   0xf
#define	  DCH_MaxAsyncLat_BASE  0
#define	  DCH_MaxAsyncLat_MIN   0
#define	  DCH_MaxAsyncLat_MAX   15
#define  DCH_RDqsEn	      (1<<12)
#define  DCH_DisDramInterface (1<<14)
#define  DCH_PowerDownEn      (1<<15)
#define  DCH_PowerDownMode_SHIFT 16
#define  DCH_PowerDownMode_MASK 1
#define   DCH_PowerDownMode_Channel_CKE 0
#define   DCH_PowerDownMode_ChipSelect_CKE 1
#define  DCH_FourRankSODimm	(1<<17)
#define  DCH_FourRankRDimm	(1<<18)
#define  DCH_SlowAccessMode 	(1<<19)
#define  DCH_BankSwizzleMode    (1<<22)
#define  DCH_DcqBypassMax_SHIFT 24
#define  DCH_DcqBypassMax_MASK  0xf
#define   DCH_DcqBypassMax_BASE 0
#define   DCH_DcqBypassMax_MIN  0
#define   DCH_DcqBypassMax_MAX  15
#define  DCH_FourActWindow_SHIFT 28
#define  DCH_FourActWindow_MASK 0xf
#define   DCH_FourActWindow_BASE 7
#define   DCH_FourActWindow_MIN 8
#define   DCH_FourActWindow_MAX 20


// for 0x98 index and 0x9c data
#define DRAM_CTRL_ADDI_DATA_OFFSET	0x98
#define  DCAO_DctOffset_SHIFT  0
#define  DCAO_DctOffset_MASK   0x3fffffff
#define  DCAO_DctAccessWrite   (1<<30)
#define  DCAO_DctAccessDone    (1<<31)

#define DRAM_CTRL_ADDI_DATA_PORT	 0x9c

#define DRAM_OUTPUT_DRV_COMP_CTRL	0x00
#define  DODCC_CkeDrvStren_SHIFT 0
#define  DODCC_CkeDrvStren_MASK  3
#define   DODCC_CkeDrvStren_1_0X  0
#define   DODCC_CkeDrvStren_1_25X 1
#define   DODCC_CkeDrvStren_1_5X  2
#define   DODCC_CkeDrvStren_2_0X  3
#define  DODCC_CsOdtDrvStren_SHIFT 4
#define  DODCC_CsOdtDrvStren_MASK  3
#define   DODCC_CsOdtDrvStren_1_0X  0
#define   DODCC_CsOdtDrvStren_1_25X 1
#define   DODCC_CsOdtDrvStren_1_5X  2
#define   DODCC_CsOdtDrvStren_2_0X  3
#define  DODCC_AddrCmdDrvStren_SHIFT 8
#define  DODCC_AddrCmdDrvStren_MASK  3
#define   DODCC_AddrCmdDrvStren_1_0X  0
#define   DODCC_AddrCmdDrvStren_1_25X 1
#define   DODCC_AddrCmdDrvStren_1_5X  2
#define   DODCC_AddrCmdDrvStren_2_0X  3
#define  DODCC_ClkDrvStren_SHIFT 12
#define  DODCC_ClkDrvStren_MASK  3
#define   DODCC_ClkDrvStren_0_75X  0
#define   DODCC_ClkDrvStren_1_0X 1
#define   DODCC_ClkDrvStren_1_25X  2
#define   DODCC_ClkDrvStren_1_5X  3
#define  DODCC_DataDrvStren_SHIFT 16
#define  DODCC_DataDrvStren_MASK  3
#define   DODCC_DataDrvStren_0_75X  0
#define   DODCC_DataDrvStren_1_0X 1
#define   DODCC_DataDrvStren_1_25X  2
#define   DODCC_DataDrvStren_1_5X  3
#define  DODCC_DqsDrvStren_SHIFT 20
#define  DODCC_DqsDrvStren_MASK  3
#define   DODCC_DqsDrvStren_0_75X  0
#define   DODCC_DqsDrvStren_1_0X 1
#define   DODCC_DqsDrvStren_1_25X  2
#define   DODCC_DqsDrvStren_1_5X  3
#define  DODCC_ProcOdt_SHIFT 28
#define  DODCC_ProcOdt_MASK  3
#define   DODCC_ProcOdt_300_OHMS  0
#define   DODCC_ProcOdt_150_OHMS 1
#define   DODCC_ProcOdt_75_OHMS  2

#define DRAM_WRITE_DATA_TIMING_CTRL_LOW 0x01
#define  DWDTCL_WrDatTimeByte0_SHIFT 0
#define  DWDTC_WrDatTimeByte_MASK  0x3f
#define   DWDTC_WrDatTimeByte_BASE 0
#define   DWDTC_WrDatTimeByte_MIN  0
#define   DWDTC_WrDatTimeByte_MAX  47
#define  DWDTCL_WrDatTimeByte1_SHIFT 8
#define  DWDTCL_WrDatTimeByte2_SHIFT 16
#define  DWDTCL_WrDatTimeByte3_SHIFT 24

#define DRAM_WRITE_DATA_TIMING_CTRL_HIGH 0x02
#define  DWDTCH_WrDatTimeByte4_SHIFT 0
#define  DWDTCH_WrDatTimeByte5_SHIFT 8
#define  DWDTCH_WrDatTimeByte6_SHIFT 16
#define  DWDTCH_WrDatTimeByte7_SHIFT 24

#define DRAM_WRITE_DATA_ECC_TIMING_CTRL 0x03
#define  DWDETC_WrChkTime_SHIFT 0
#define  DWDETC_WrChkTime_MASK  0x3f
#define   DWDETC_WrChkTime_BASE 0
#define   DWDETC_WrChkTime_MIN  0
#define   DWDETC_WrChkTime_MAX  47

#define DRAM_ADDR_TIMING_CTRL 0x04
#define  DATC_CkeFineDelay_SHIFT 0
#define  DATC_CkeFineDelay_MASK  0x1f
#define   DATC_CkeFineDelay_BASE 0
#define   DATC_CkeFineDelay_MIN  0
#define   DATC_CkeFineDelay_MAX 31 
#define  DATC_CkeSetup	(1<<5)
#define  DATC_CsOdtFineDelay_SHIFT 8
#define  DATC_CsOdtFineDelay_MASK  0x1f
#define   DATC_CsOdtFineDelay_BASE 0
#define   DATC_CsOdtFineDelay_MIN  0
#define   DATC_CsOdtFineDelay_MAX 31
#define  DATC_CsOdtSetup   (1<<13)
#define  DATC_AddrCmdFineDelay_SHIFT 16 
#define  DATC_AddrCmdFineDelay_MASK  0x1f
#define   DATC_AddrCmdFineDelay_BASE 0
#define   DATC_AddrCmdFineDelay_MIN  0
#define   DATC_AddrCmdFineDelay_MAX 31
#define  DATC_AddrCmdSetup   (1<<21)

#define DRAM_READ_DQS_TIMING_CTRL_LOW 0x05
#define  DRDTCL_RdDqsTimeByte0_SHIFT 0
#define  DRDTC_RdDqsTimeByte_MASK  0x3f
#define   DRDTC_RdDqsTimeByte_BASE 0
#define   DRDTC_RdDqsTimeByte_MIN  0
#define   DRDTC_RdDqsTimeByte_MAX  47
#define  DRDTCL_RdDqsTimeByte1_SHIFT 8
#define  DRDTCL_RdDqsTimeByte2_SHIFT 16
#define  DRDTCL_RdDqsTimeByte3_SHIFT 24

#define DRAM_READ_DQS_TIMING_CTRL_HIGH 0x06
#define  DRDTCH_RdDqsTimeByte4_SHIFT 0
#define  DRDTCH_RdDqsTimeByte5_SHIFT 8
#define  DRDTCH_RdDqsTimeByte6_SHIFT 16
#define  DRDTCH_RdDqsTimeByte7_SHIFT 24

#define DRAM_READ_DQS_ECC_TIMING_CTRL 0x07
#define  DRDETC_RdDqsTimeCheck_SHIFT 0
#define  DRDETC_RdDqsTimeCheck_MASK  0x3f
#define   DRDETC_RdDqsTimeCheck_BASE 0
#define   DRDETC_RdDqsTimeCheck_MIN  0
#define   DRDETC_RdDqsTimeCheck_MAX  47

#define DRAM_DQS_RECV_ENABLE_TIME0 0x10
#define  DDRET_DqsRcvEnDelay_SHIFT 0
#define  DDRET_DqsRcvEnDelay_MASK 0xff
#define   DDRET_DqsRcvEnDelay_BASE 0
#define   DDRET_DqsRcvEnDelay_MIN  0
#define   DDRET_DqsRcvEnDelay_MAX  0xae   /* unit is 50ps */

#define DRAM_DQS_RECV_ENABLE_TIME1 0x13
#define DRAM_DQS_RECV_ENABLE_TIME2 0x16
#define DRAM_DQS_RECV_ENABLE_TIME3 0x19

/* there are index        0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x30, 0x33, 0x36, 0x39 
that are corresponding to 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x10, 0x13, 0x16, 0x19
*/
#define DRAM_CTRL_MISC 0xa0
#define  DCM_MemClrStatus (1<<0)
#define  DCM_DisableJitter (1<<1)
#define  DCM_RdWrQByp_SHIFT 2
#define  DCM_RdWrQByp_MASK  3
#define   DCM_RdWrQByp_2 0
#define   DCM_RdWrQByp_4 1
#define   DCM_RdWrQByp_8 2
#define   DCM_RdWrQByp_16 3
#define  DCM_Mode64BitMux (1<<4)
#define  DCM_DCC_EN (1<<5)
#define  DCM_ILD_lmt_SHIFT 6
#define  DCM_ILD_lmt_MASK 7
#define   DCM_ILD_lmt_0 0
#define   DCM_ILD_lmt_4 1
#define   DCM_ILD_lmt_8 2
#define   DCM_ILD_lmt_16 3
#define   DCM_ILD_lmt_32 4
#define   DCM_ILD_lmt_64 5
#define   DCM_ILD_lmt_128 6
#define   DCM_ILD_lmt_256 7
#define  DCM_DramEnabled (1<<9)
#define  DCM_MemClkDis_SHIFT 24                /* Channel B */
#define  DCM_MemClkDis3       (1 << 26)
#define  DCM_MemClkDis2       (1 << 27)
#define  DCM_MemClkDis1       (1 << 28)
#define  DCM_MemClkDis0       (1 << 29)


/* Function 3 */
#define MCA_NB_CONFIG      0x44
#define   MNC_ECC_EN       (1 << 22)
#define   MNC_CHIPKILL_EN  (1 << 23)
#define	MNC_NBMCATOMSTCPUEN (1 << 27)

#define SCRUB_CONTROL	   0x58
#define	  SCRUB_NONE	    0
#define	  SCRUB_40ns	    1
#define	  SCRUB_80ns	    2
#define	  SCRUB_160ns	    3
#define	  SCRUB_320ns	    4
#define	  SCRUB_640ns	    5
#define	  SCRUB_1_28us	    6
#define	  SCRUB_2_56us	    7
#define	  SCRUB_5_12us	    8
#define	  SCRUB_10_2us	    9
#define	  SCRUB_20_5us	   10
#define	  SCRUB_41_0us	   11
#define	  SCRUB_81_9us	   12
#define	  SCRUB_163_8us	   13
#define	  SCRUB_327_7us	   14
#define	  SCRUB_655_4us	   15
#define	  SCRUB_1_31ms	   16
#define	  SCRUB_2_62ms	   17
#define	  SCRUB_5_24ms	   18 
#define	  SCRUB_10_49ms	   19
#define	  SCRUB_20_97ms	   20
#define	  SCRUB_42ms	   21
#define	  SCRUB_84ms	   22
#define	 SC_DRAM_SCRUB_RATE_SHFIT  0
#define	 SC_DRAM_SCRUB_RATE_MASK   0x1f
#define	 SC_L2_SCRUB_RATE_SHIFT	   8
#define	 SC_L2_SCRUB_RATE_MASK	   0x1f
#define	 SC_L1D_SCRUB_RATE_SHIFT   16
#define	 SC_L1D_SCRUB_RATE_MASK	   0x1f

#define SCRUB_ADDR_LOW	   0x5C

#define SCRUB_ADDR_HIGH	   0x60

#define NORTHBRIDGE_CAP	   0xE8
#define	 NBCAP_128Bit	      (1 << 0)
#define	 NBCAP_MP	      (1 << 1)
#define	 NBCAP_BIG_MP	      (1 << 2)
#define	 NBCAP_ECC	      (1 << 3)
#define	 NBCAP_CHIPKILL_ECC   (1 << 4)
#define	 NBCAP_MEMCLK_SHIFT   5
#define	 NBCAP_MEMCLK_MASK    3
#define	  NBCAP_MEMCLK_200MHZ  3
#define	  NBCAP_MEMCLK_266MHZ  2
#define	  NBCAP_MEMCLK_333MHZ  1
#define	  NBCAP_MEMCLK_NOLIMIT  0
#define	 NBCAP_MEMCTRL	      (1 << 8)
#define  NBCAP_HtcCap		(1<<10)
#define  NBCAP_CmpCap_SHIFT	12
#define  NBCAP_CmpCap_MASK	3

/* other hypertransport constants */
#define HT_INIT_CONTROL	0x6c

#define LinkConnected     (1 << 0)
#define InitComplete      (1 << 1)
#define NonCoherent       (1 << 2)
#define ConnectionPending (1 << 4)

/* Special LAPIC define which we only find in the K8 sources. */
#define LAPIC_MSG_REG 0x380

#ifndef ASSEMBLY

/* Steppings of the K8 cpu */
enum {
  A0= 0x0f00, 
  B3= 0x0f41, 
  C0= 0x0f48, 
  CG, /* value not yet known */
  D0= 0x10f00, 
  E0= 0x20f00, 
  F0= 0x40f00, 
  F2= 0x40f02, 
};

/* note: we'd like to have this sysinfo common to all K8, there's no need to
 * have one different kind per different kind of k8 at this point. 
 */
//#include "raminit.h"

struct dimm_size {
        u8 per_rank; // it is rows + col + bank_lines + data lines */
	u8 side1, side2;
        u8 rows;
        u8 col;
        u8 bank; //1, 2, 3 mean 2, 4, 8
        u8 rank;
} __attribute__((packed));

struct mem_info { // pernode
        u32 dimm_mask;
        struct dimm_size sz[DIMM_SOCKETS];
        u32 x4_mask;
        u32 x16_mask;
	u32 single_rank_mask;
        u32 page_1k_mask;
//        u32 ecc_mask;
//        u32 registered_mask;
        u8 is_opteron;
        u8 is_registered;
        u8 is_ecc;
        u8 is_Width128;
        u8 memclk_set; // we need to use this to retrieve the mem param
	u8 rsv[3];
} __attribute__((packed));

struct mem_controller {
	unsigned node_id;
	/* NOTE: these are in "BDF" format -- i.e. bus in upper 16, devfn in upper 8 of lower 16 */
	u32 f0, f1, f2, f3;
	u32 channel0[DIMM_SOCKETS];
	u32 channel1[DIMM_SOCKETS];
};

struct link_pair_st {
	u32 udev;
	u32	upos;
	u32	uoffs;
	u32	dev;
	u32	pos;
	u32	offs;

} __attribute__((packed));

struct sys_info {
	u8 ctrl_present[NODE_NUMS];
	struct mem_info meminfo[NODE_NUMS];
	struct mem_controller ctrl[NODE_NUMS];
	u8 mem_trained[NODE_NUMS]; //0: no dimm, 1: trained, 0x80: not started, 0x81: recv1 fail, 0x82: Pos Fail, 0x83:recv2 fail
	u32 tom_k;
	u32 tom2_k;

	u32 mem_base[NODE_NUMS];
	u32 cs_base[NODE_NUMS*8]; //8 cs_idx
	u32 hole_reg[NODE_NUMS]; // can we spare it to one, and put ctrl idx in it

	u8 dqs_delay_a[NODE_NUMS*2*2*9]; //8 node channel 2, direction 2 , bytelane *9
	u8 dqs_rcvr_dly_a[NODE_NUMS*2*8]; //8 node, channel 2, receiver 8
	u32 nodes;
	struct link_pair_st link_pair[16];// enough? only in_conherent
	u32 link_pair_num;
	u32 ht_c_num;
	u32 sbdn;
	u32 sblk;
	u32 sbbusn;
} __attribute__((packed));

/* dual core support */
unsigned int read_nb_cfg_54(void);

struct device;
unsigned get_apicid_base(unsigned ioapic_num);
void amd_sibling_init(struct device *cpu);

/* memory hole management */
struct hw_mem_hole_info {
	unsigned hole_startk;
	int node_id;
};

typedef void (*process_ap_t) (unsigned apicid, void *gp);

struct hw_mem_hole_info get_hw_mem_hole_info(void);

/* General purpose support functions that can run in any stage. */

unsigned int get_nodes(void);
unsigned int init_cpus(unsigned cpu_init_detectedx,
	       struct sys_info *sysinfo);
void setup_coherent_ht_domain(void);
void wait_all_core0_started(void);
void start_all_cores(void);
void wait_all_other_cores_started(unsigned bsp_apicid);
void for_each_ap(unsigned bsp_apicid, unsigned core_range,
			process_ap_t process_ap, void *gp);
void ht_setup_chains_x(struct sys_info *sysinfo);
int optimize_link_coherent_ht(void);
int optimize_link_incoherent_ht(struct sys_info *sysinfo);
void allow_all_aps_stop(unsigned bsp_apicid);
unsigned int get_core_count(void);
void fill_mem_ctrl(int controllers, struct mem_controller *ctrl_a, 
		const u16 *spd_addr);
int lapic_remote_read(int apicid, int reg, unsigned int *pvalue);
void print_apicid_nodeid_coreid(unsigned apicid, struct node_core_id id,
				const char *str);
unsigned int wait_cpu_state(unsigned apicid, unsigned state);
void set_apicid_cpuid_lo(void);
/* fidvid.c */
void enable_fid_change(void);
void init_fidvid_bsp(unsigned bsp_apicid);

/* k8/northbridge.c */
void sdram_initialize(int controllers, const struct mem_controller *ctrl, struct sys_info *sysinfo);
/* k8/reset_test.c */
void distinguish_cpu_resets(unsigned nodeid);

/* These are functions that MUST be inlined as we can not use a stack -- CAR or real ram */
/* by yhlu 6.2005 */
/* be warned, this file will be used other cores and core 0 / node 0 */
static inline __attribute__((always_inline)) void disable_cache_as_ram(void)
{

        __asm__ volatile (

        /* We don't need cache as ram for now on */
        /* disable cache */
        "movl    %cr0, %eax\n\t"
        "orl    $(0x1<<30),%eax\n\t"
        "movl    %eax, %cr0\n\t"

        /* clear sth */
        "movl    $0x269, %ecx\n\t"  /* fix4k_c8000*/
        "xorl    %edx, %edx\n\t"
        "xorl    %eax, %eax\n\t"
	"wrmsr\n\t"
#if CONFIG_CARSIZE > 0x8000
	"movl    $0x268, %ecx\n\t"  /* fix4k_c0000*/
        "wrmsr\n\t"
#endif

        /* disable fixed mtrr from now on, it will be enabled by coreboot_ram again*/
        "movl    $0xC0010010, %ecx\n\t"
//        "movl    $SYSCFG_MSR, %ecx\n\t"
        "rdmsr\n\t"
        "andl    $(~(3<<18)), %eax\n\t"
//        "andl    $(~(SYSCFG_MSR_MtrrFixDramModEn | SYSCFG_MSR_MtrrFixDramEn)), %eax\n\t"
        "wrmsr\n\t"

        /* Set the default memory type and disable fixed and enable variable MTRRs */
        "movl    $0x2ff, %ecx\n\t"
//        "movl    $MTRRdefType_MSR, %ecx\n\t"
        "xorl    %edx, %edx\n\t"
        /* Enable Variable and Disable Fixed MTRRs */
        "movl    $0x00000800, %eax\n\t"
        "wrmsr\n\t"

        /* enable cache */
        "movl    %cr0, %eax\n\t"
        "andl    $0x9fffffff,%eax\n\t"
        "movl    %eax, %cr0\n\t"

        );
}

void disable_cache_as_ram_bsp(void);

#endif /* ! ASSEMBLY */

#endif /* AMD_K8_H */
