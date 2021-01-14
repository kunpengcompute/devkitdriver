软件功能
	解决在CentOS 7.6版本支持PMU Uncore事件，将PMU Uncore事件驱动从内核中提取成独立的驱动文件，使用时先unbind内核中的已有PMU Uncore事件驱动，再安装新的独立驱动。该处理仅仅针对TaiShan200（kunpeng 920芯片）有效。

开发语言
	C语言

运行环境
	系统版本：CentOS7.6
	内核版本：4.14.0-115.el7a.0.1.aarch64
	机器版本：物理机

编译环境
	系统版本：CentOS7.6
	内核版本：4.14.0-115.el7a.0.1.aarch64

编译驱动
	进入源码目录，执行make即可，此处以/home/MallumaForTaiShan/driver/pmu_driver为例：
		cd /home/MallumaForTaiShan/driver/pmu_driver
		make
	编译成功后会生成4个ko文件，kunpeng920pmu.ko、kunpeng920pmu_ddrc.ko、kunpeng920pmu_hha.ko、kunpeng920pmu_l3c.ko

安装驱动
	安装时，由于其他三个驱动需依赖于kunpeng920pmu.ko，需要先安装kunpeng920pmu.ko，其他三个无顺序要求。
	insmod kunpeng920pmu.ko
	insmod ko、kunpeng920pmu_ddrc.ko
	insmod ko、kunpeng920pmu_hha.ko
	insmod ko、kunpeng920pmu_l3c.ko

卸载驱动
	卸载时，先将以下三个驱动卸载后，最后卸载kunpeng920pmu.ko，防止kunpeng920pmu驱动被占用报错
	rmmod ko、kunpeng920pmu_ddrc
	rmmod ko、kunpeng920pmu_hha
	rmmod ko、kunpeng920pmu_l3c
	rmmod kunpeng920pmu

LICENSE
	GPL-2.0-only
