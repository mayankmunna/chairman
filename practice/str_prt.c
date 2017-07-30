#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int  main()
{
	char **ptr_str;
	char str[100];
	int row;
	int index;
 	printf("Enter the number of rows you want to Allocate:");
	scanf("%d",&row);
	ptr_str = (char **)malloc(row * sizeof(char *));

	for(index=0;index<row;index++)
	{
		printf("\nEnter string in row %d:",index+1);
		scanf("%s",str);
		ptr_str[index] = (char *)malloc(strlen(str)+1);
		strcpy(ptr_str[index],str);
	}

		printf("\n\n\t\tArray Elements\n");
	printf("______________________________________________________________________________________________________________\n");
	printf("\t\tRow Number |\t\tData in the Row\t\t\n");
	printf("______________________________________________________________________________________________________________|\n");
	for(index=0;index<row;index++)
	{
	printf("\t\t%d    \t|\t\t%s\n",index+1,ptr_str[index]);
	printf("--------------------------------------------------------------------------------------------------------------|\n");
	}
return 0;
}

