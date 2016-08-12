#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Hiroshi Ogawa");
MODULE_DESCRIPTION("LKM Hello World");
MODULE_VERSION("0.1");

static char *name = "world";
module_param(name, charp, S_IRUGO);
MODULE_PARM_DESC(name, "The name to display in /var/log/kern.log");

static int __init hello_init(void){
   printk(KERN_INFO "Hello %s\n", name);
   return 0;
}

static void __exit hello_exit(void){
   printk(KERN_INFO "Goodbye %s\n", name);
}

module_init(hello_init);
module_exit(hello_exit);
