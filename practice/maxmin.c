#include<stdio.h>
#define ROWS 3
#define COLS 3

void accept_arr(int arr[][COLS]);
void find_max_min_rows(int arr[][COLS]);
void find_max_min_cols(int arr[][COLS]);
 main()
{
	int arr[ROWS][COLS];
	accept_array(arr);
	find_max_min_rows(arr);
	find_max_min_cols(arr);

}
void accept_array(int arr[][COLS])
{
	int i,j;
	printf("enter the elements:");
	for(i=0;i<ROWS;i++)
	{
		for(j=0;j<COLS;j++)
		{	
			(void )scanf("%d",&arr[i][j]);
		}
	}
	for(i=0;i<ROWS;i++)
	{
		for(j=0;j<COLS;j++)
		{	
			printf("%d\t",arr[i][j]);
		}
		printf("\n");
	}
}
void find_max_min_cols(int arr[][COLS])
{
	int max_col=0;
	int min_col=0;
	int i=0;
	int j=0;
	for(j=0;j<COLS;j++)
	{
		max_col=arr[i=j][j];
        	        for(i=0;i<ROWS;i++)
			{
			  	if(max_col<arr[i][j])
				max_col = arr[i][j];
				else 
				continue;
			}
		printf("\nGreatest of COL:%d is : %d",j+1,max_col); 
	}
	i=0;j=0;
	for(j=0;j<COLS;j++)
	{
		min_col=arr[i=j][j];

		for(i=0;i<ROWS;i++)
		{
		  	if(min_col>arr[i][j])
				min_col = arr[i][j];
			else 
				continue;
		}
		printf("\nSmallest of COL:%d is : %d",j+1,min_col); 
	}
}
void find_max_min_rows(int arr[][COLS])
{
	int max_row=0;
	int min_row=0;
	int i=0;
	int j=0;
	for(i=0;i<ROWS;i++)
	{
        	max_row=arr[i][j=i];
	for(j=0;j<COLS;j++)
	{
	  	if(max_row<arr[i][j])
         		max_row = arr[i][j];
  		else 
		  continue;
		}
		printf("\nGreatest of ROW:%d is : %d",i+1,max_row); 
	}


	i=0;j=0;
	for(i=0;i<ROWS;i++)
	{
	 min_row=arr[i][j=i];	
	for(j=0;j<COLS;j++)
	{
	  	if(min_row>arr[i][j])
         		min_row = arr[i][j];
  		else 
		  continue;
		}
		printf("\nSmallest of ROW:%d is : %d",i+1,min_row); 
	}
}
