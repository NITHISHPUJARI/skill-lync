obj-m := device_driver_ioctl.o #hello_world.o
MY_CFLAGS += -g -DDEBUG

all: x86_build

clean: x86_clean RPI_clean

x86_build: hello_world.c
	sudo make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

x86_clean:
	sudo make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

RPI_build:  device_driver_ioctl.c #hello_world.c
	sudo make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- -C linux M=$(PWD) modules EXTRA_CFLAGS="$(MY_CFLAGS)"

RPI_clean:
	sudo make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- -C linux M=$(PWD) clean


.PHONY: all clean x86_build x86_clean RPI_build RPI_clean
