/*
 * This file is part of the coreboot project.
 *
 * Copyright (C) 2011 Advanced Micro Devices, Inc.
 * Copyright (C) 2013 Sage Electronic Engineering, LLC
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

#include "AGESA.h"
#include "amdlib.h"
#include "Ids.h"
#include "heapManager.h"
#include <PlatformMemoryConfiguration.h>
#include "PlatformGnbPcieComplex.h"
#include "Filecode.h"

#include <string.h>
#include <northbridge/amd/agesa/state_machine.h>

/*---------------------------------------------------------------------------------------*/
/**
 *	OemCustomizeInitEarly
 *
 *	Description:
 *	This stub function will call the host environment through the binary block
 *	interface (call-out port) to provide a user hook opportunity
 *
 *	Parameters:
 *	@param[in]		*InitEarly
 *
 *	@retval		 VOID
 *
 **/
/*---------------------------------------------------------------------------------------*/

void board_BeforeInitEarly(struct sysinfo *cb, AMD_EARLY_PARAMS *InitEarly)
{
	AGESA_STATUS		 Status;
	VOID				 *BrazosPcieComplexListPtr;
	VOID				 *BrazosPciePortPtr;
	VOID				 *BrazosPcieDdiPtr;

	ALLOCATE_HEAP_PARAMS AllocHeapParams;

PCIe_PORT_DESCRIPTOR PortList [] = {
		// Initialize Port descriptor (PCIe port, Lanes 4, PCI Device Number 4, ...)
		{
			0,
			PCIE_ENGINE_DATA_INITIALIZER (PciePortEngine, 4, 4),
			PCIE_PORT_DATA_INITIALIZER (GNB_GPP_PORT4_PORT_PRESENT, GNB_GPP_PORT4_CHANNEL_TYPE, 4, GNB_GPP_PORT4_HOTPLUG_SUPPORT, GNB_GPP_PORT4_SPEED_MODE, GNB_GPP_PORT4_SPEED_MODE, GNB_GPP_PORT4_LINK_ASPM, 4)
		},
		// Initialize Port descriptor (PCIe port, Lanes 5, PCI Device Number 5, ...)
		{
			0,
			PCIE_ENGINE_DATA_INITIALIZER (PciePortEngine, 5, 5),
			PCIE_PORT_DATA_INITIALIZER (GNB_GPP_PORT5_PORT_PRESENT, GNB_GPP_PORT5_CHANNEL_TYPE, 5, GNB_GPP_PORT5_HOTPLUG_SUPPORT, GNB_GPP_PORT5_SPEED_MODE, GNB_GPP_PORT5_SPEED_MODE, GNB_GPP_PORT5_LINK_ASPM, 5)
		},
		// Initialize Port descriptor (PCIe port, Lanes 6, PCI Device Number 6, ...)
		{
			0,
			PCIE_ENGINE_DATA_INITIALIZER (PciePortEngine, 6, 6),
			PCIE_PORT_DATA_INITIALIZER (GNB_GPP_PORT6_PORT_PRESENT, GNB_GPP_PORT6_CHANNEL_TYPE, 6, GNB_GPP_PORT6_HOTPLUG_SUPPORT, GNB_GPP_PORT6_SPEED_MODE, GNB_GPP_PORT6_SPEED_MODE, GNB_GPP_PORT6_LINK_ASPM, 6)
		},
		// Initialize Port descriptor (PCIe port, Lanes 7, PCI Device Number 7, ...)
		{
			0,
			PCIE_ENGINE_DATA_INITIALIZER (PciePortEngine, 7, 7),
			PCIE_PORT_DATA_INITIALIZER (GNB_GPP_PORT7_PORT_PRESENT, GNB_GPP_PORT7_CHANNEL_TYPE, 7, GNB_GPP_PORT7_HOTPLUG_SUPPORT, GNB_GPP_PORT7_SPEED_MODE, GNB_GPP_PORT7_SPEED_MODE, GNB_GPP_PORT7_LINK_ASPM, 7)
		},
		// Initialize Port descriptor (PCIe port, Lanes 8, PCI Device Number 8, ...)
		{
			DESCRIPTOR_TERMINATE_LIST,
			PCIE_ENGINE_DATA_INITIALIZER (PciePortEngine, 0, 3),
			PCIE_PORT_DATA_INITIALIZER (GNB_GPP_PORT8_PORT_PRESENT, GNB_GPP_PORT8_CHANNEL_TYPE, 8, GNB_GPP_PORT8_HOTPLUG_SUPPORT, GNB_GPP_PORT8_SPEED_MODE, GNB_GPP_PORT8_SPEED_MODE, GNB_GPP_PORT8_LINK_ASPM, 0)
		}
};

PCIe_DDI_DESCRIPTOR DdiList [] = {
		// Initialize Ddi descriptor (DDI interface Lanes 8:11, DdA, ...)
		{
			0,
			PCIE_ENGINE_DATA_INITIALIZER (PcieDdiEngine, 8, 11),
			//PCIE_DDI_DATA_INITIALIZER (ConnectorTypeDP, Aux1, Hdp1)
			{ConnectorTypeDP, Aux1, Hdp1}
		},
		// Initialize Ddi descriptor (DDI interface Lanes 12:15, DdB, ...)
		{
			DESCRIPTOR_TERMINATE_LIST,
			PCIE_ENGINE_DATA_INITIALIZER (PcieDdiEngine, 12, 15),
			//PCIE_DDI_DATA_INITIALIZER (ConnectorTypeDP, Aux2, Hdp2)
			{ConnectorTypeDP, Aux2, Hdp2}
		}
};

PCIe_COMPLEX_DESCRIPTOR Brazos = {
		DESCRIPTOR_TERMINATE_LIST,
		0,
		&PortList[0],
		&DdiList[0]
};

	// GNB PCIe topology Porting

	//
	// Allocate buffer for PCIe_COMPLEX_DESCRIPTOR , PCIe_PORT_DESCRIPTOR and PCIe_DDI_DESCRIPTOR
	//
	AllocHeapParams.RequestedBufferSize = sizeof(Brazos) + sizeof(PortList) + sizeof(DdiList);

	AllocHeapParams.BufferHandle = AMD_MEM_MISC_HANDLES_START;
	AllocHeapParams.Persist = HEAP_LOCAL_CACHE;
	Status = HeapAllocateBuffer (&AllocHeapParams, &InitEarly->StdHeader);
	ASSERT(Status == AGESA_SUCCESS);

	BrazosPcieComplexListPtr	=	(PCIe_COMPLEX_DESCRIPTOR *) AllocHeapParams.BufferPtr;

	AllocHeapParams.BufferPtr += sizeof(Brazos);
	BrazosPciePortPtr		 =	(PCIe_PORT_DESCRIPTOR *)AllocHeapParams.BufferPtr;

	AllocHeapParams.BufferPtr += sizeof(PortList);
	BrazosPcieDdiPtr			=	(PCIe_DDI_DESCRIPTOR *) AllocHeapParams.BufferPtr;

	memcpy(BrazosPcieComplexListPtr, &Brazos, sizeof(Brazos));
	memcpy(BrazosPciePortPtr, &PortList[0], sizeof(PortList));
	memcpy(BrazosPcieDdiPtr, &DdiList[0], sizeof(DdiList));


	((PCIe_COMPLEX_DESCRIPTOR*)BrazosPcieComplexListPtr)->PciePortList =	(PCIe_PORT_DESCRIPTOR*)BrazosPciePortPtr;
	((PCIe_COMPLEX_DESCRIPTOR*)BrazosPcieComplexListPtr)->DdiLinkList	=	(PCIe_DDI_DESCRIPTOR*)BrazosPcieDdiPtr;

	InitEarly->GnbConfig.PcieComplexList = BrazosPcieComplexListPtr;
	InitEarly->GnbConfig.PsppPolicy		= 0;
}

/*----------------------------------------------------------------------------------------
 *						CUSTOMER OVERIDES MEMORY TABLE
 *----------------------------------------------------------------------------------------
 */

/*
 *	Platform Specific Overriding Table allows IBV/OEM to pass in platform information to AGESA
 *	(e.g. MemClk routing, the number of DIMM slots per channel,...). If PlatformSpecificTable
 *	is populated, AGESA will base its settings on the data from the table. Otherwise, it will
 *	use its default conservative settings.
 */
static CONST PSO_ENTRY ROMDATA PlatformMemoryTable[] = {

	NUMBER_OF_DIMMS_SUPPORTED (ANY_SOCKET, ANY_CHANNEL, TWO_DIMM),
	NUMBER_OF_CHANNELS_SUPPORTED (ANY_SOCKET, ONE_DIMM),

	// Gizmos soldered down memory uses memory CLK0 and CLK1 on CS0
	MEMCLK_DIS_MAP(ANY_SOCKET, ANY_CHANNEL, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00),

	// Gizmos soldered down memory requires different seeds
#define WLSEED 0x08
#define RXSEED 0x40
	WRITE_LEVELING_SEED(ANY_SOCKET, ANY_CHANNEL, WLSEED, WLSEED, WLSEED, WLSEED, WLSEED, WLSEED, WLSEED, WLSEED, WLSEED),
	HW_RXEN_SEED( ANY_SOCKET, ANY_CHANNEL, RXSEED, RXSEED, RXSEED, RXSEED, RXSEED, RXSEED, RXSEED, RXSEED, RXSEED),

	PSO_END
};

void board_BeforeInitPost(struct sysinfo *cb, AMD_POST_PARAMS *InitPost)
{
	InitPost->MemConfig.PlatformMemoryConfiguration = (PSO_ENTRY *)PlatformMemoryTable;
}
