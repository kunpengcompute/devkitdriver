
KERNELDIR ?= /lib/modules/`uname -r`/build
EXTRA_CFLAGS := -fstack-protector-all
#EXTRA_CFLAGS += -O1

ifeq ($(KERNELRELEASE),)
PWD := $(shell pwd)
modules:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
else
	obj-m := spe_device.o
endif

.PHONY : clean
clean  :
	$(MAKE) clean -C $(KERNELDIR)  M=$(PWD)
