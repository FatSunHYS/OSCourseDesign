obj-m:=SysfsTest.o

all:
	make -C ~/OSCourseDesign SUBDIRS=$(shell pwd) modules

.PHONY:clean
clean:
	rm -rf *.o *.mod.c *.ko *.symvers
