#include<stdio.h>
#include<stdlib.h>
int main()
{
  char *czParent = "I'm Daddy";
  char *czChild = "I'm Kid";
  int nIndex = 0;
  int nRet = 127;
  FILE *pFPtr = fopen("./test_file","w");
  	if(!pFPtr)
	{
		printf("\nError opening File\n");
		return EXIT_FAILURE;
	}
	if(fork())
	{
		for(nIndex = 0; nIndex <10; nIndex++)
		{
			fprintf(pFPtr,"%s\n",czParent);
			fflush(pFPtr);
			sleep(1);
		}
	}
	else
	{
		for(nIndex = 0; nIndex <10; nIndex++)
		{
			fprintf(pFPtr,"%s\n",czChild);
			fflush(pFPtr);
			sleep(3);
		}
	}
	nRet = fclose(pFPtr);
	if(nRet == 0)
		return EXIT_SUCCESS;
	else
		return EXIT_FAILURE;
}		
