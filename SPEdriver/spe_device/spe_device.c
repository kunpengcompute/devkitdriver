/*
 * Copyright (C) 2020-2021. Huawei Technologies Co., Ltd. All rights reserved.

 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 
 * Description: Application class implementation, which controls the whole app start stop and so on.
 */
#include <linux/kconfig.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/acpi.h>
#include <linux/cpumask.h>
#include <linux/init.h>
#include <linux/irq.h>
#include <linux/irqdesc.h>
#include <linux/percpu.h>
#include <linux/perf/arm_pmu.h>

#include <asm/cputype.h>

#define ARMV8_SPE_PDEV_NAME "arm,spe-v1"

static int gsi = 21;
module_param(gsi, int, 0);

static struct resource spe_resources[] = {
    {
    /* irq */
        .flags          = IORESOURCE_IRQ,
    }
};

static struct platform_device spe_dev = {
    .name = ARMV8_SPE_PDEV_NAME,
    .id = -1,
    .resource = spe_resources,
    .num_resources = ARRAY_SIZE(spe_resources)
};

/*
 * For lack of a better place, hook the normal PMU MADT walk
 * and create a SPE device if we detect a recent MADT with
 * a homogeneous PPI mapping.
 */
static void arm_spe_acpi_register_device(void)
{
    int irq, ret;
    irq = acpi_register_gsi(NULL, gsi, ACPI_LEVEL_SENSITIVE, ACPI_ACTIVE_HIGH);
    if (irq < 0) {
        pr_warn("ACPI: SPE Unable to register interrupt: %d\n", gsi);
        return;
    }
    spe_resources[0].start = irq;
    ret = platform_device_register(&spe_dev);
    if (ret < 0) {
        pr_warn("ACPI: SPE: Unable to register device\n");
        acpi_unregister_gsi(gsi);
    }
}

static int __init spe_device_init(void)
{
    arm_spe_acpi_register_device();
    return 0;
}

static void __exit spe_device_exit(void)
{
    platform_device_unregister(&spe_dev);
    acpi_unregister_gsi(gsi);
}

module_init(spe_device_init)module_exit(spe_device_exit)MODULE_LICENSE("GPL");
