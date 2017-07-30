#include<stdio.h>
void recur_fun( int a)
{
static int p=10;
	 printf("\nValue of a:%d\nValue of p:%d",a,p);
	 if(a<=5)
	 	{
			p--;
			recur_fun(++a);
		}
	else return;
}
main()
{
	recur_fun(0);
return 0;
}

