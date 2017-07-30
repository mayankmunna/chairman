#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/init.h>
#include<linux/fs.h> /* to register character device */
#include<linux/sched.h>/* for PID */

static int  maj= 0;
int entry(void)
{
	static struct file_operations fops;
	printk("DEBUG:DYNAMIC REGISTRATION MODULE LOADED\n");
	printk("DEBUG:PID of Module process is %d\n",current->pid);
	maj = register_chrdev(0,"myChar",&fops);
	if(maj < 0 )
	{
		printk(KERN_ALERT"Registering Device: Failed\n");
		return 1;
	}
	else
	{
		printk(KERN_ALERT"Registering Device with Major %d:SUCCESSFUL\n",maj);
	}
	return 0;
}
void out(void)
{
	int ret = 0;	
	printk("\nDEBUG:STATIC REGISTRATION MODULE UNLOADED\n");
	unregister_chrdev(maj,"myChar");
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
MODULE_DESCRIPTION("THIS DRIVER WILL REGISTER CHARACTER DEVICE WITH STATIC MAJOR NUMBER");

