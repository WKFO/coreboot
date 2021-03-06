#
# This file is part of the coreboot project.
#
# Copyright (C) 2011 - 2012 Advanced Micro Devices, Inc.
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
subdirs-$(CONFIG_CPU_AMD_AGESA_FAMILY12) += family12
subdirs-$(CONFIG_CPU_AMD_AGESA_FAMILY14) += family14
subdirs-$(CONFIG_CPU_AMD_AGESA_FAMILY15) += family15
subdirs-$(CONFIG_CPU_AMD_AGESA_FAMILY15_TN) += family15tn
subdirs-$(CONFIG_CPU_AMD_AGESA_FAMILY16_KB) += family16kb

ramstage-y += s3_mtrr.c

ifeq ($(CONFIG_AGESA_LEGACY), y)
cpu_incs-y += $(src)/cpu/amd/agesa/cache_as_ram_legacy.inc
else
cpu_incs-y += $(src)/cpu/amd/agesa/cache_as_ram.S
romstage-y += romstage.c
endif

romstage-$(CONFIG_AGESA_LEGACY_WRAPPER) += heapmanager.c

ramstage-y += heapmanager.c
ramstage-$(CONFIG_AGESA_LEGACY_WRAPPER) += amd_late_init.c

ifeq ($(CONFIG_HAVE_ACPI_RESUME), y)

$(obj)/coreboot_s3nv.rom: $(obj)/config.h
	echo "    S3 NVRAM   $(CONFIG_S3_DATA_POS) (S3 storage area)"
	# force C locale, so cygwin awk doesn't try to interpret the 0xff below as UTF-8 (or worse)
	printf %d $(CONFIG_S3_DATA_SIZE) | LC_ALL=C awk '{for (i=0; i<$$1; i++) {printf "%c", 255}}' > $@.tmp
	mv $@.tmp $@

cbfs-files-y += s3nv
s3nv-file := $(obj)/coreboot_s3nv.rom
s3nv-position := $(CONFIG_S3_DATA_POS)
s3nv-type := raw

endif # CONFIG_HAVE_ACPI_RESUME == y
