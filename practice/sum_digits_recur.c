#include<stdio.h>
void sum_digits(int sum, int num);

int main()
{
	int num=0;
	printf("Enter Number to find the sum of the digits:");
	scanf("%d",&num);
	sum_digits(0,num);
	return 0;
}
void sum_digits(int sum , int num)
{
	int temp=0;
	if(num==0)
	{
		printf("Sum is:%d",sum);
		return;
	}
	temp = num%10;
	sum+=temp;
	sum_digits(sum,num/10);
}

