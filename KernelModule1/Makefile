obj-m += KernelModule.obj

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

