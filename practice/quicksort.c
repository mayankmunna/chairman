#include<stdio.h>
void quick_sort(int [],int,int);
int partition(int [],int,int);
void swap(int *, int *);
int main()

{
	int i=0,start,end;
	int arr[]={5,12,2,14,33,6,7,23,1,90,4};
	printf("\nUnsorted Array:\n");
	for(i=0;i<11;i++)
	{
		printf("%d ",arr[i]);
	}
	start = 0;
	end =10;
	quick_sort(arr,start,end);

	printf("\nsorted Array:\n");
	for(i=0;i<11;i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}

void quick_sort(int data[],int beg,int end)
{
	if(beg>=end)
		return;
	int middle = partition(data,beg,end);
	quick_sort(data,beg,middle-1);
	quick_sort(data,middle+1,end);
}

int partition(int arr[],int beg,int end)
{
        int pivot_ele = arr[beg];
        int pivot_index = beg;
	int j;
	for(j=beg+1;j<=end;j++)
	{
		if(arr[j]<pivot_ele)
			{
				pivot_index++;
				swap(&arr[j],&arr[pivot_index]);
			}
	}
	swap(&arr[pivot_index],&arr[beg]);
	return pivot_index;
}
void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a=*b;
	*b = temp;
}
