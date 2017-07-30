#include<stdio.h>
#include<stdlib.h>
/*
*program to create a zombie process 
* Mayank Sharma
*/

int main()
{
	if(!fork())
	{
		printf("Pid of child :%d\n",getpid());
	}
	else
	{
		sleep(20);
	}
	return EXIT_SUCCESS;
}
