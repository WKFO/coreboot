/*
 * This file is part of the coreboot project.
 *
 * Copyright (C) 2015-2016 Advanced Micro Devices, Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <AGESA.h>
#include <BiosCallOuts.h>
#include <FchPlatform.h>
#include <soc/imc.h>
#include <soc/southbridge.h>
#include <stdlib.h>
#include <string.h>

/* Hardware Monitor Fan Control
 * Hardware limitation:
 *  HWM will fail to read the input temperature via I2C if other
 *  software switches the I2C address.  AMD recommends using IMC
 *  to control fans, instead of HWM.
 */
static void oem_fan_control(FCH_DATA_BLOCK *FchParams)
{
	/* Enable IMC fan control. the recommand way */
	imc_reg_init();

	FchParams->Imc.ImcEnable = TRUE;

	/* 1 IMC, 0 HWM */
	FchParams->Hwm.HwmControl = 1;

	/* 2 disable IMC, 1 enable IMC, 0 following hw strap setting */
	FchParams->Imc.ImcEnableOverWrite = 1;

	memset(&FchParams->Imc.EcStruct, 0, sizeof(FCH_EC));
}

static AGESA_STATUS fch_initenv(UINT32 Func, UINTN FchData, VOID *ConfigPtr)
{
	AMD_CONFIG_PARAMS *StdHeader = ConfigPtr;

	if (StdHeader->Func == AMD_INIT_ENV) {
		FCH_DATA_BLOCK *FchParams_env = (FCH_DATA_BLOCK *)FchData;
		printk(BIOS_DEBUG, "Fch OEM config in INIT ENV ");
		if (IS_ENABLED(CONFIG_STONEYRIDGE_IMC_FWM))
			oem_fan_control(FchParams_env);

		/* XHCI configuration */
		if (IS_ENABLED(CONFIG_STONEYRIDGE_XHCI_ENABLE))
			FchParams_env->Usb.Xhci0Enable = TRUE;
		else
			FchParams_env->Usb.Xhci0Enable = FALSE;
		FchParams_env->Usb.Xhci1Enable = FALSE;
		/* 8: If USB3 port is unremoveable. */
		FchParams_env->Usb.USB30PortInit = 8;

		/* SATA configuration */
		FchParams_env->Sata.SataClass = CONFIG_STONEYRIDGE_SATA_MODE;
		switch ((SATA_CLASS)CONFIG_STONEYRIDGE_SATA_MODE) {
		case SataRaid:
		case SataAhci:
		case SataAhci7804:
		case SataLegacyIde:
			FchParams_env->Sata.SataIdeMode = FALSE;
			break;
		case SataIde2Ahci:
		case SataIde2Ahci7804:
		default: /* SataNativeIde */
			FchParams_env->Sata.SataIdeMode = TRUE;
			break;
		}
		printk(BIOS_DEBUG, "Done\n");
	}

	return AGESA_SUCCESS;
}

const BIOS_CALLOUT_STRUCT BiosCallouts[] = {
	{AGESA_ALLOCATE_BUFFER,          agesa_AllocateBuffer },
	{AGESA_DEALLOCATE_BUFFER,        agesa_DeallocateBuffer },
	{AGESA_LOCATE_BUFFER,            agesa_LocateBuffer },
	{AGESA_READ_SPD,                 agesa_ReadSpd },
	{AGESA_DO_RESET,                 agesa_Reset },
	{AGESA_READ_SPD_RECOVERY,        agesa_NoopUnsupported },
	{AGESA_RUNFUNC_ONAP,             agesa_RunFuncOnAp },
	{AGESA_GET_IDS_INIT_DATA,        agesa_EmptyIdsInitData },
	{AGESA_HOOKBEFORE_DQS_TRAINING,  agesa_NoopSuccess },
	{AGESA_HOOKBEFORE_EXIT_SELF_REF, agesa_NoopSuccess },
	{AGESA_FCH_OEM_CALLOUT,          fch_initenv },
	{AGESA_GNB_GFX_GET_VBIOS_IMAGE,  agesa_GfxGetVbiosImage }
};

const int BiosCalloutsLen = ARRAY_SIZE(BiosCallouts);
