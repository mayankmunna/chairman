#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/init.h>

int entry(void)
{
	printk("\nDEBUG:MODULE LOADED\n");
	return 0;
}
void exit(void)
{
	
	printk("\nDEBUG:MODULE UNLOADED\n");
}
module_init(entry);
module_exit(exit);
MODULE_AUTHOR("MAYANK SHARMA");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("FIRST DRIVER");

