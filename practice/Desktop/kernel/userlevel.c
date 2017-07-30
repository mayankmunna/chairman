#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#define DEBUG 1
#define USER_BUFF_SIZE 1024
#define DEVICE "chrdev"

void copy_2_user(int fd);
void goToOp(int fd);
void copy_4m_user(int fd);
int main()
{
	int fd = open(DEVICE,O_RDWR);
	if(fd < 0)
	{
		#ifdef DEBUG
		printf("\nDEBUG:Open the device File: FAILED\n");
		#endif
		return EXIT_FAILURE;
	}
	else
	{
		#ifdef DEBUG
		printf("\nDEBUG:Open the device File: SUCCESS\n");
		#endif
		goToOp(fd);
		close(fd);
	}
	
	return EXIT_SUCCESS;
}
void goToOp(int fd)
{
	int choice = 0;
	while(choice !=3)
	{
		printf("\n\tKERNEL COPY FROM/TO USER DEMO\n");
		printf("1.COPY TO USER.\n2.COPY FROM USER.\n3.Choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: 
				copy_2_user(fd);
				break;
			case 2:
				copy_4m_user(fd);
				break;
			default:
				system("clear");
				printf("\n!!!Please Enter Correct Choice!!!\n");		}
	}
}
void copy_4m_user(int fd)
{
	char *buffer = malloc(USER_BUFF_SIZE);
	if(!buffer)
	{
		#ifdef DEBUG
  		printf("\nError Allocting memory to User Buffer\n");
		#endif
		close(fd);
		exit(EXIT_FAILURE);
	}
	printf("\nPlease Enter Text upto 1KB(1024 CHARS):");
	scanf (" %[^\n]",buffer);
	write(fd,buffer,USER_BUFF_SIZE);
	printf("\nPlease Check the Dmesg to see if kernel has received the string\n");
	free(buffer);
}
void copy_2_user(int fd)
{
	char *buffer = malloc(USER_BUFF_SIZE);
	read(fd,buffer,USER_BUFF_SIZE);
	printf("\nData From Kernel : %s",buffer);
	free(buffer);
}

