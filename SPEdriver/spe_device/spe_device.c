/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2019-2020. All rights reserved.
 * Description: Application class implementation, which controls the whole app start stop and so on.
 * Author: malluma team
 * Create: 2019-12-07
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
