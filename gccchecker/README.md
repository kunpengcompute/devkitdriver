Extend GCC input and output manner.
Apply the patch and compile GCC, fix the weak memory ordering bugs while compile the project with the new GCC.

## Supported OSs and GCC Versions ##

- CentOS 7.6/7.7: GCC 4.8.5,7.3.0,7.4.0,8.3.0
- CentOS 8.0/8.1: GCC 8.3.0
- Ubuntu 18.04.1: GCC 7.3.0

## Prerequisites ##

1. You have obtained the **porting advisor** from the Kunpeng platform and are familiar with it's basic functions.
   For more information: https://www.huaweicloud.com/kunpeng/software/portingadvisor.html

2. The project can be successfully compiled on the Kunpeng platform.

## Install ##

#### 1. Download required software packages. ####

   - GCC source code: https://gcc.gnu.org/(Download the source code of the corresponding version from the official GCC website.)
   - GCC repair tool patch: https://github.com/kunpengcompute/gcctools/(Download the patch of the corresponding GCC version.)
   - Weak memory ordering repair component from Porting-Advisor-xxx.tar.gz
   - libstdc++6.so dependency library: http://ftp.cn.debian.org/debian/pool/main/g/gcc-7/libstdc++6-7-dbg_7.4.0-6_arm64.deb(for Debian and Red Hat OSs)

#### 2. Install the weak memory ordering repair component. ####

###### a. Decompre the installation package. ######

`tar xf gcctool.tar.gz`

After the decompression, check the following files exist in the 'gcctool/bin' directory:

   - gcctool: The binary to fix weak memory ordering issues.
   - gcctool-bin: Main repaire logic.
   - add_libraries.sh: Install the dependency 'libstdc++6.so' to gcctool/bin.

###### b. Install libstdc++ dependencies. ######

`bash gcctool/bin/add_libraries.sh -d /path/to/gcctool_root_dir -f /path/to/libstdc++6-7-dbg_7.4.0-6_arm64.deb`

###### c. Configure environment variables. ######

Place 'gcctool' in the installation directory and configure environment variables.

`export PATH=/path/to/gcctool/bin:$PATH`

#### 3. Apply the GCC patch ####

```
cd /gcc/source/root/dir
patch -p1 < /path/to/gcc-x.x.x.patch
```

#### 4. Compile GCC ####

   For details about how to compile the GCC source code, see the offical GCC decuments. The patch does not affect the GCC dependency components and the compilatoin precess. If you have any GCC compilation problem, see https://gcc.gnu.org/install/index.html.

