#include<stdio.h>
#include<linux/kernel.h>
#include<sys/syscall.h>
#include<stdlib.h>
int main()
{
	long ret = syscall(546);
	//long ret = hello();
	if(ret == 0)
	{
		printf("SysCall :Success\n");
		return EXIT_SUCCESS;
	}
	else
	{
		printf("SysCall :FAILURE\n");
		return EXIT_FAILURE;
	}
}
