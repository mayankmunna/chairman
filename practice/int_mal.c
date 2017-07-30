#include<stdio.h>
#include<stdlib.h>
main()
{
	int **ptr;
	int row;
	int index=0;
	int size=0;
	int j=0;
	printf("\nEnter number of rows:");
	scanf("%d",&row);
	

	ptr=(int**)malloc(row*sizeof(int*));
	if(ptr!=NULL)
		printf("\nMemory Allocated to double pointer\n");

	printf("\nEnter column size:");
	scanf("%d",&size);
	for(index=0;index<row;index++)
	{
		ptr[index]= (int *)malloc(size*sizeof(int));
		printf("Enter Data for Row %d:",index+1);
		for(j=0;j<size;j++)
		{
		  scanf("%d",(ptr[index]+j));
		}
	}
		
	printf("\n\tArray Elements:");
	for(index=0;index<row;index++)
	{
		printf("\nrow %d :\n",index+1);
		
		for(j=0;j<size;j++)
		{
			printf("%d%s",*(*(ptr+index)+j),j<size-1?",":".");
		}
	}
}	
