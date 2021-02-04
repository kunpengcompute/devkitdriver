Extend GCC input and output manner.
Apply the patch and compile GCC, fix the weak memory ordering bugs while compile the project with the new GCC.

## Supported OSs and GCC Versions ##

#### CentOS 7.6/7.7 / NeoKylin V7U6 ####

4.8.5/4.9.3/5.1.0/5.2.0/5.3.0/5.4.0/5.5.0/6.1.0/6.2.0/6.3.0/6.4.0/6.5.0/7.1.0/7.2.0/7.3.0/7.4.0/8.1.0/8.2.0/8.3.0/9.1.0/9.2.0/9.3.0

#### Linx 6.0.90 / Deepin 15.2 ####

6.3.0/6.4.0/6.5.0/7.1.0/7.2.0/7.3.0/7.4.0/8.1.0/8.2.0/8.3.0/9.1.0/9.2.0/9.3.0

#### Ubuntu 18.04.1 / openEuler 20.03 / Kylin V10 ####

7.3.0/7.4.0/8.1.0/8.2.0/8.3.0/9.1.0/9.2.0/9.3.0

#### SUSE SLES15.1 ####

7.4.0/8.1.0/8.2.0/8.3.0/9.1.0/9.2.0/9.3.0

#### CentOS 8.0 ####

8.2.0/8.3.0/9.1.0/9.2.0/9.3.0

#### CentOS 8.1/8.2 / Debian 10 / UOS 20 ####

8.3.0/9.1.0/9.2.0/9.3.0

#### Ubuntu 20.04.1 ####

9.3.0

## Prerequisites ##

1. You have obtained the **porting advisor** from the Kunpeng platform and are familiar with it's basic functions.
   For more information: https://www.huaweicloud.com/kunpeng/software/portingadvisor.html

2. The project can be successfully compiled on the Kunpeng platform.

## Install ##

#### 1. Download required software packages. ####

   - GCC source code: https://gcc.gnu.org/(Download the source code of the corresponding version from the official GCC website.)
   - GCC repair tool patch: https://github.com/kunpengcompute/devkitdriver/tree/main/gccchecker/ (Download the patch of the corresponding GCC version.).
     For example, you can find the patch for GCC 4.8.5 in https://github.com/kunpengcompute/devkitdriver/tree/main/gccchecker/gcc-4.8.5.patch
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

