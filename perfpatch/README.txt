*******Note*******

1 Supports CentOS 7.6 with kernel version 4.14.0.
2 The perf tool does not depend on the kernel version.

*******Compiling the Perf Tool*******

Download the source code package spe_perf for compiling the perf and save it to the /home directory.

cd /home/spe_perf
chmod +x build_perf.sh
./build_perf.sh

The generated perf file is stored in the following directory:

/home/spe_perf/linux-4.14.0-115.el7a/tools/perf/perf