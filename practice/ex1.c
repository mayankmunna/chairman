#include<stdio.h>
void test_even_odd(int n)
{
	if(!(n%2))
	{
		printf("%d is even\n",n);
	}
	else
	{
		printf("%d is odd\n",n);
	}
}
int main(int argc, char *argv[])
{
	int n;
	printf("Enter Data:");
	scanf("%d",&n);
	test_even_odd(n);
        return 0;
}


