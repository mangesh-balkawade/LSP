#include<linux/module.h>
#include<linux/kernel.h>    
#include<linux/init.h>

#define DRIVER_AUTHOR "Mangesh";
#define DRIVER_DESC "it is marvellous infosystem driver";

MODULE_LICENSE("GPL");

int MarvellousNo = 21;

module_param(MarvellousNo, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

MODULE_PARM_DESC(MarvellousNo, "Its a integer variable");

static int __init Marvellous_init(void)
{
    printk(KERN_INFO "Marvellous module loaded : Jay Ganesh %d\n",MarvellousNo);
    return 0;
}

static void __exit Marvellous_Cleanup(void)
{
    printk(KERN_INFO "Marvellous module unloaded : Jay Ganesh\n");
}

module_init(Marvellous_init);
module_exit(Marvellous_Cleanup);

MODULE_AUTHOR(DRIVER_AUTHOR)
MODULE_DESCRIPTION(DRIVER_DESC)

