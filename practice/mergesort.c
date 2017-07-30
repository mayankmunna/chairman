#include<stdio.h>

void merge(int [],int,int,int);
void merge_sort(int [],int,int);
int main()
{
	int arr[]={7,6,5,4,3,2,1,0};
	int i;
	
	printf("\nUnsorted Elements:");
	for(i=0;i<sizeof(arr)/sizeof(int);i++)
		printf("%d\t",arr[i]);
	
	merge_sort(arr,0,7);
	
	printf("\nSorted Elements:\n");
	for(i=0;i<sizeof(arr)/sizeof(int);i++)
		printf("%d\t",arr[i]);
return 0;
}
void merge_sort(int arr[],int left,int right)
{	
	
	int middle =(left+right)/2;
	if(left<right)
	{	

	merge_sort(arr,left,middle);
	merge_sort(arr,middle+1,right);
	merge(arr,left,middle,right);
	}
}

void merge(int arr[],int left,int middle,int right)
{
	int sizel=middle-left+1;
	int sizer=right-middle;
	int l_arr[sizel];
	int r_arr[sizer];
	int i,j,k;

	
	for(i=0;i<sizel;i++)
	{
		l_arr[i]=arr[left+i];
	}
		
	for(j=0;j<sizer;j++)
	{
		r_arr[j]=arr[middle+1+j];
	}
	i=j=0;k=left;
	while((i<sizel)&&(j<sizer))
	{
		if(l_arr[i]<=r_arr[j])
		{
			arr[k]=l_arr[i];
			i++;
		}
		else
		{
			arr[k]=r_arr[j];
			j++;
		}	
		k++;
	}
	while(i<sizel)
	{
		arr[k]=l_arr[i];
		k++;
		i++;

	}

	while(j<sizer)
	{
		arr[k]=r_arr[j];
		k++;
		j++;
	}

}	
