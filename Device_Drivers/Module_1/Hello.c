#include<linux/module.h>
#include<linux/kernel.h>    

MODULE_LICENSE("GPL");

int init_module(void)
{
    printk(KERN_INFO "Marvellous module loaded : Jay Ganesh\n");
    return 0;
}

void cleanup_module(void)
{
    printk(KERN_INFO "Marvellous module unloaded : Jay Ganesh\n");

}