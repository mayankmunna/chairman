#include<stdio.h>
#define SIZE 10
void reccur(int i);
int main()
{
	reccur(0);
	return 0;
}

void reccur(int i)
{
	int arr[]={1,2,3,4,5,6,7,8,9,10};
	if(i>SIZE-1)
	{
	
//	printf("%d|",arr[i]);
		return;
	}
	//printf("Forward :"\t);
	printf("%d|",arr[i]);
	
	i++;
	reccur(i);
	printf("%d",arr[i]);
}
