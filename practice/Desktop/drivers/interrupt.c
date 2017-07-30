#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/fs.h>
#include<linux/interrupt.h>

static struct file_operations fops;

void my_irq(int irq, void* device, struct pt_regs *regs)
{
	printk("\n<Please Don't move me>\n");
}

int my_entry(void)
{
	if(request_irq(12, (void *)my_irq, IRQF_SHARED, "Mayank", &fops))	
	{
		printk("DEBUG :IRQ HANDLER on LINE 12:FAILED\n");
		return 1;
	}
	else
	{
		printk("DEBUG :IRQ HANDLER on LINE 12:SUCCESS\n");
		return 0;
	}	
}

void my_exit(void)
{
	free_irq(12,&fops);
}


module_init(my_entry);
module_exit(my_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("MAYANK SHARMA");
MODULE_DESCRIPTION("THIS MODULE WILL REQUEST AN INTTERUPT LINE FOR MOUSE");

