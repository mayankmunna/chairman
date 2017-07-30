#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/init.h>
#include<linux/sched.h>/* for PID */
#include<asm/uaccess.h> /* copy to/from user */
#include<linux/slab.h>
#include<linux/fs.h> /* to register character device */

#define MAJ 101
#define DEV_NAME "myChar" 
#define BUFF_SIZE 1024


static ssize_t dev_read(struct file *fPtr, char *uBuffer, size_t count, loff_t *lf)
{
	int copied = 0;	
	char kString[] = "Hi, I'm from Kernel";
	copied = copy_to_user(uBuffer, kString, sizeof(kString));
	if(copied > BUFF_SIZE)
	{
		printk("\nDEBUG: BUFFER OVERFLOW \n");
		return 0;
	}
	else
		return copied;
}
static ssize_t dev_write(struct file *fPtr, char *uBuffer, size_t count, loff_t *lf)
{
	int copied = 0;
	char *kBuff = kmalloc(BUFF_SIZE,GFP_KERNEL);
	copied = copy_from_user(kBuff, uBuffer, BUFF_SIZE);
	if(copied >  count)
	{
		printk("\nDEBUG:Kernel BUFFER OVERFLOW\n");	
		kfree(kBuff);
		return 0;
	}
	else
	{	printk("\nHi, I'm from User: \n \t %s\n",kBuff);
 		kfree(kBuff);
		return copied;
	}
}
static struct file_operations fops =
{
	read :dev_read,
	write : dev_write
};
int entry(void)
{
	int ret = 0;
	printk("DEBUG:STATIC REGISTRATION MODULE LOADED\n");
	printk("DEBUG:PID of Module process is %d\n",current->pid);
	ret = register_chrdev(MAJ, DEV_NAME, &fops);
	if(ret < 0 )
	{
		printk(KERN_ALERT "DEBUG:Registering Device: Failed\n");
		return 1;
	}
	else
	{
		printk(KERN_ALERT "DEBUG:Registering Device:SUCCESSFUL\n");
	}
	return 0;
}
void out(void)
{
	int ret = 0;	
	printk("\nDEBUG: STATIC REGISTRATION MODULE UNLOADED\n");
	unregister_chrdev(MAJ, DEV_NAME);
	if(ret < 0 )
	{
		printk(KERN_ALERT "DEBUG: UNRegistering Devicea Failed\n");
	}
	else
	{
		printk(KERN_ALERT "DEBUG: UNRegistering Device:SUCCESSFUL\n");
	}
	
	
}
module_init(entry);
module_exit(out);
MODULE_AUTHOR("MAYANK SHARMA");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("THIS DRIVER WILL COPY THE DATA FROM USER TO KERNEL AND VICE VERSA");

