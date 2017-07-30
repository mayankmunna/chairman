#include<stdio.h>
#include<stdlib.h>
void fill_array(int arr[],int);
void print_array(int arr[],int);
void askr_incr_decr(int arr[]);
int get_size();
int main()
{
	int *arr;
	int size;
	size = get_size();
	arr = (int *)malloc(size * sizeof(int));
	if(arr == NULL)
	{
		printf("\n!!!Problem in allocating memory!!!!");
	}
	else
	{
		fill_array(&arr[0],size);
		print_array(&arr[0],size);
		ask_incr_decr(arr);	
	}
return 0;
}	
void fill_array(int arr[],int size)
{
	int i=0;
	int count=0;
	for (i=0;i<size;i++)
	{
		printf("Enter Element no. %d:",i+1);
		scanf("%d",&arr[i]);

	}
}
void print_array(int arr[],int size)
{
	int i=0;
	printf("\nEntered array Elements are\n\n\t");
	for(i=0;i<size;i++)
	{
		printf("%d %s\t",arr[i],(i<=size-2)?",":".");
	}
}
void ask_incr_decr(int arr[])
{
   int option=0;
   int size =0;
    while(1)
    {

   	  printf("\nDo you want to Increase or decrease Array size and fill elements again\n\n 0:Yes\n1:No.\nEnter Choice:");
	  scanf("%d",&option);  
		if(option==0)
			{
				size=get_size();
				arr =(int *) realloc(arr,size*sizeof(int));
				fill_array(&arr[0],size);
				print_array(&arr[0],size);

			}
		else 
		 break;	
   }
return;
}
int get_size()
{
	int size=0;	
	printf("Enter the size of Array :");
	scanf("%d",&size);
        return size;
}





	
