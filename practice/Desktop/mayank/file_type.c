#include<stdio.h>
#include <stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
int main(int argc ,  char **argv)
{
 struct	stat f_stat;
	if(argc >2)
	{
		printf("\nPlease enter only one file\n");
		return 1;
	}
	else if(argc < 2)
	{
		printf("\nplease enter One file to check in CMD LINE\n");
		return 1;
	}
	else
	{
	  if((stat(argv[1], &f_stat))<0)
	  {
		printf("stat Sys call failed\n");	
		return 1;
	  }	
	switch (f_stat.st_mode & S_IFMT) 
        {
	  case S_IFREG:
	  	printf("%s is a Regular File\n",argv[1]);
		break;
	  case S_IFCHR:
	  	printf("%s is a CHAR File\n",argv[1]);
		break;
	  case S_IFDIR:	  
	  	printf("%s is a DIRECTORY\n",argv[1]);
	  	break;
	 case S_IFBLK:
	  	printf("%s is a BLOCK DEVICE filie\n",argv[1]);
		break;
	  case S_IFIFO:
	  	printf("%s is a FIFO file\n",argv[1]);
		break;
	  case S_IFLNK:
	  	printf("%s is a LINK file\n",argv[1]);
		break;
	  default:
	  	printf("\%s is not of the following :\n1.Regularn\n2.Directory\n3.Block\n4.FIFO\n5.LINK\n",argv[1]);
	
	}
     }

 return 0;
}
