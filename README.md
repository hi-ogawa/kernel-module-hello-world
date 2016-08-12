# Kernel Module Hello World

```
$ vagrant up
$ vagrant ssh
```

```
$ cd /vagrant/src

$ make
make -C /lib/modules/3.13.0-85-generic/build/ M=/vagrant/src modules
make[1]: Entering directory `/usr/src/linux-headers-3.13.0-85-generic'
  CC [M]  /vagrant/src/hello.o
  Building modules, stage 2.
  MODPOST 1 modules
  CC      /vagrant/src/hello.mod.o
  LD [M]  /vagrant/src/hello.ko
make[1]: Leaving directory `/usr/src/linux-headers-3.13.0-85-generic'

$ ls
hello.c   hello.mod.c  hello.o   modules.order
hello.ko  hello.mod.o  Makefile  Module.symvers

$ modinfo hello.ko
filename:       /vagrant/src/hello.ko
version:        0.1
description:    LKM Hello World
author:         Hiroshi Ogawa
license:        GPL
srcversion:     170318A5B48AA6F4097E2B0
depends:
vermagic:       3.13.0-85-generic SMP mod_unload modversions
parm:           name:The name to display in /var/log/kern.log (charp)

$ sudo insmod hello.ko

$ lsmod | grep hello
hello                  12532  0

$ dmesg | tail
...
[  206.553579] Hello world

$ ls /sys/module/hello
coresize  initsize   notes       refcnt    srcversion  uevent
holders   initstate  parameters  sections  taint       version

$ cat /sys/module/hello/parameters/name
world

$ sudo rmmod hello.ko

$ dmesg | tail
...
[  206.553579] Hello world
[  260.858262] Goodbye world

$ sudo insmod hello.ko name=Doe

$ cat /sys/module/hello/parameters/name
Doe

$ dmesg | tail
...
[  285.231173] Hello Doe
[  308.235215] Goodbye Doe
```

# Reference

- http://www.thegeekstuff.com/2013/07/write-linux-kernel-module
- http://derekmolloy.ie/writing-a-linux-kernel-module-part-1-introduction/
- http://www.tldp.org/LDP/lkmpg/2.6/html/lkmpg.html
