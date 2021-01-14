Software Functions
	The PMU uncore event is supported in CentOS 7.6. The PMU uncore event driver is extracted from the kernel as an independent driver file. Before using the driver, unbind the existing PMU uncore event driver in the kernel and install a new independent driver. This processing is valid only for TaiShan200 (kunpeng 920 chip).

Development Language
	C language

Operating Environment
	System version: CentOS 7.6
	Kernel version: 4.14.0-115.el7a.0.1.aarch64
	Machine version: physical machine

Compilation Environment
	System version: CentOS 7.6
	Kernel version: 4.14.0-115.el7a.0.1.aarch64

Compiling Drivers
	Go to the source code directory and run the make command. /home/MallumaForTaiShan/driver/pmu_driver is used as an example.
		cd /home/MallumaForTaiShan/driver/pmu_driver
		make
	After the compilation is successful, four .ko files are generated: kunpeng920pmu.ko, kunpeng920pmu_ddrc.ko, kunpeng920pmu_hha.ko, and kunpeng920pmu_l3c.ko.

Installing the Driver
	During the installation, the other three drivers depend on kunpeng920pmu.ko. Therefore, you need to install kunpeng920pmu.ko first. The other three drivers do not need to be installed in sequence.
	insmod kunpeng920pmu.ko
	insmod ko, kunpeng920pmu_ddrc.ko
	insmod ko, kunpeng920pmu_hha.ko
	insmod ko, kunpeng920pmu_l3c.ko

Uninstalling the Driver
	Before uninstalling the kunpeng920pmu.ko driver, uninstall the following three drivers and then uninstall the kunpeng920pmu.ko driver to prevent the kunpeng920pmu driver from being occupied.
	rmmod ko, kunpeng920pmu_ddrc
	rmmod ko, kunpeng920pmu_hha
	rmmod ko, kunpeng920pmu_l3c
	rmmod kunpeng920pmu

LICENSE
	GPL-2.0-only