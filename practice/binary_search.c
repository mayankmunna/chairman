#include<stdio.h>
int binary_search(int [],int ,int,int);
void sort(int []);

int main()
{
	int arr[10];
	int i;
	int index=-1;
	int num;
	for(i=0;i<10;i++)
	{
		printf("\nEnter Array element %d :",i+1);
		scanf("%d",&arr[i]);
	}
	
	sort(arr);
	printf("\nSorted Array elements\n");
	for(i=0;i<10;i++)
	{
	
		printf("%d\t",arr[i]);
	}
	printf("\nEnter the Number:");
	scanf("%d",&num);
	index = binary_search(arr,0,9,num);
	if(index ==-1)
		printf("\nNumber is not Present in the List");
	else
		printf("%d is present at %d Location",num,index+1);


return 0;
}
void sort(int arr[])
{
	int i,j;
	int temp;
	for(i=0;i<10;i++)
	{
		for(j=0;j<10-i-1;j++)
		{
			if(arr[j]>arr[j+1])
				{
					temp = arr[j];
					arr[j]=arr[j+1];
					arr[j+1]=temp;
				}
		}
	}
}	
int binary_search(int arr[],int start,int end,int num)
{
	int mid =( start + end )/2;
	if(start>=mid)
		return -1;
	if(num == arr[mid])
		return mid;
	else if(num<arr[mid])
	 {
	    end = mid;
	    return (binary_search(arr,start,end,num));
	 }
	 else if(num>arr[mid])
	 {
		start = mid;
		return (binary_search(arr,start,end,num));
	 }
		
	else 
		return -1;
}		
