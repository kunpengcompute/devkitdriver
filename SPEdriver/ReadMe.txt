*******Note*******

Supports CentOS 7.6 with kernel version 4.14.0.
The 4.14.0 kernel of CentOS 7.6 supports seven minor versions:
4.14.0-115.el7a.0.1
4.14.0-115.2.2.el7a
4.14.0-115.5.1.el7a
4.14.0-115.6.1.el7a
4.14.0-115.7.1.el7a
4.14.0-115.8.2.el7a
4.14.0-115.10.1.el7a

*******Compiling the SPE Driver*******

Download the source code package spe_ko for compiling the perf and save it to the /home directory.

cd /home/spe_ko/arm_spe_pmu
make

cd /home/spe_ko/spe_device
make

The generated .ko file is stored in the following directory:

/home/spe_ko/arm_spe_pmu/arm_spe_pmu.ko
/home/spe_ko/arm_spe_pmu/spe_device.ko