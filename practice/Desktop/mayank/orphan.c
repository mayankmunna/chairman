#include<stdio.h>
#include<stdlib.h>
/* program to create a Orphan process */
int main()
{
	if(!fork())
	{
		printf("Parent Pid of child :%d\n",getppid());
		sleep (5);
		printf("Parent Pid of child :%d\n",getppid());
	}
	else
	{
	 printf("\nEntering Parent :%d",getpid());
	sleep(1);
 	printf("\nExiting Parent :%d",getpid());
	}
	return EXIT_SUCCESS;
}
