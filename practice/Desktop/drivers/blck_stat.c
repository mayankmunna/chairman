#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/init.h>
#include<linux/fs.h> /* to register character device */
#include<linux/sched.h>/* for PID */

int entry(void)
{
	int ret=0;
//	static struct file_operations fops;
	printk("DEBUG:STATIC REGISTRATION  BLK DEVICE MODULE LOADED\n");
	printk("DEBUG:PID of Module process is %d\n",current->pid);
	ret = register_blkdev(101,"myChar");
	if(ret < 0 )
	{
		printk(KERN_ALERT"Registering Device: Failed\n");
		return 1;
	}
	else
	{
		printk(KERN_ALERT"Registering Device with Major 101:SUCCESSFUL\n");
	}
	return 0;
}
void out(void)
{
	int ret = 0;	
	printk("\nDEBUG:STATIC REGISTRATION MODULE UNLOADED\n");
	unregister_blkdev(101,"myChar");
	if(ret < 0 )
	{
		printk(KERN_ALERT"UNRegistering Devicea Failed\n");
	}
	else
	{
		printk(KERN_ALERT "UNRegistering Device:SUCCESSFUL\n");
	}
	
	
}
module_init(entry);
module_exit(out);
MODULE_AUTHOR("MAYANK SHARMA");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("THIS DRIVER WILL REGISTER BLOCK DEVICE WITH STATIC MAJOR NUMBER");

