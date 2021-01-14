KSRC = /lib/modules/$(shell uname -r)/build/
PWD := $(shell pwd)
obj-m := kunpeng920pmu.o
obj-m += kunpeng920pmu_l3c.o
obj-m += kunpeng920pmu_hha.o
obj-m += kunpeng920pmu_ddrc.o
kunpeng920pmu-objs := hisi_uncore_pmu.o
kunpeng920pmu_l3c-objs := hisi_uncore_l3c_pmu.o
kunpeng920pmu_hha-objs := hisi_uncore_hha_pmu.o
kunpeng920pmu_ddrc-objs := hisi_uncore_ddrc_pmu.o

all:
	$(MAKE) modules -C $(KSRC) M=$(PWD)
clean:
	$(MAKE) -C $(KSRC) M=$(PWD) clean
