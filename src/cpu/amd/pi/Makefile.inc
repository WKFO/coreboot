#
# This file is part of the coreboot project.
#
# Copyright (C) 2011 - 2016 Advanced Micro Devices, Inc.
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; version 2 of the License.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#

subdirs-$(CONFIG_CPU_AMD_PI_00630F01) += 00630F01
subdirs-$(CONFIG_CPU_AMD_PI_00730F01) += 00730F01
subdirs-$(CONFIG_CPU_AMD_PI_00660F01) += 00660F01

cpu_incs-y += $(src)/cpu/amd/agesa/cache_as_ram.S

ifeq ($(CONFIG_BINARYPI_LEGACY_WRAPPER), y)
romstage-y += romstage.c
ramstage-y += amd_late_init.c
romstage-y += ../agesa/heapmanager.c
else
romstage-y += ../agesa/romstage.c
endif

ramstage-y += ../agesa/heapmanager.c
