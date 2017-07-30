#include<stdio.h>
#include<string.h>
int swap(int *a,int *b)
{
	int c =*a;
	*a=*b;
	*b=c;
	
}
main()
{
	int x=5,y=20;
	printf("Before swap X=%d ,Y=%d",x,y);
	swap(&x,&y);
	printf("\nAfer swap X=%d ,Y=%d",x,y);
}
