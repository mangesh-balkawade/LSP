#include <linux/module.h>
#include <linux/kernel.h>

static int __init marvelllous_init(void)
{
    printk(KERN_INFO "Marvellous Module gets inserted \n: Jay Ganesh...\n");
    return 0;
}

static void __exit marvellous_exit(void)
{
    printk(KERN_INFO, "Marvellous module gets removed \n");
}

module_init(marvelllous_init);

module_exit(marvellous_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("MARVELLOUS INFOSYSTEMS");
MODULE_DESCRIPTION("DEMO KERNEL MODULE");
