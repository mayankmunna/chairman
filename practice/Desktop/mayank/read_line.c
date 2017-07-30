#include<stdio.h>
#include<stdlib.h>
void readLine(char* pFileName);
int main(int argc, char** argv)
{
	if(argc !=2)
	{
	  printf("\n!!!Please Enter exactly one File to Read!!!\n"); 
	  return EXIT_SUCCESS;
	}
	else
	{
		readLine(*(argv+1));
	}
return EXIT_SUCCESS;
}

void readLine(char *pFileName)
{
	char cInput = ' '; 
	FILE* pFptr = fopen(pFileName,"r");
	while(EOF != (cInput=fgetc(pFptr)))
	{
		if(cInput == '\n')
			getchar();
                else	
			putchar(cInput);
	} 
}
