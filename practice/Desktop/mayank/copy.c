#include<stdio.h>
#include<stdlib.h>
#define FAIL 1
#define PASS 0
int copy(char *source, char * dest);

int main(char argc , char **argv)
{
	int nResult = FAIL;
	if (argc !=3)
	{
	  printf("Please Enter exactly 2 File Names in the sequence SOURCE DEST\n");
	  return EXIT_FAILURE;
	}

	else
	{
//printf("DEBUG:\nFile 1 :%s\nFile 2:%s",*(argv +1),*(argv +2)); 	 
	nResult = copy(*(argv + 1), *(argv +2));
	}
	
	printf("\nCopy %s\n",((nResult == PASS) ? "SUCCESS":"FAILED"));
return EXIT_SUCCESS;
}
int copy( char *source, char *dest)
{
    char cSource = ' ';
    FILE *pPtrSrc = fopen(source,"r");
    if(!pPtrSrc)
    {
     	printf("\nCannot open %s for Read purpose check whether file is present\n",source);
    	return FAIL;
    }
     FILE *pPtrDes = fopen(dest,"a+");
    if(!pPtrDes)
	{
		printf("\nCannot open %s for writing purpose check whether file is present\n",dest);
		return FAIL;
	}
	while ((cSource =fgetc(pPtrSrc))!= EOF)
	{
		fputc(cSource, pPtrDes);
	}
	fclose(pPtrSrc);
	fclose(pPtrDes);
	return PASS;
}

