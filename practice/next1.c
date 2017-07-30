#include<stdio.h>
void div(int a,int b)
{
	int quot,rem;
	quot = x/y;
	rem = x%y;
	printf("quot =%d rem = %d\n",quot,rem);
}
int main(int argc,char *argv[])
{
	int x,y;
	printf("Enter two numbers");
	scanf("%d %d",&x,&y);
	div(x,y);
	return 0;
} 
