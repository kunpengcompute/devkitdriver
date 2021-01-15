KDIR := /lib/modules/$(shell uname -r)/build/
#KDIR :=/home/liu/linux-4.14.0-115.el7a
PWD := $(shell pwd)
obj-m += arm_spe_pmu.o
module-objs := arm_spe_pmu.o
all:
	$(MAKE) modules -C $(KDIR) M=$(PWD) 
clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
#KDIR := /lib/modules/4.14.0-115.el7a.0.1.aarch64/build
#KDIR := /lib/modules/(shell uname -r)/build
