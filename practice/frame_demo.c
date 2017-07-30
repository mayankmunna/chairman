#include<stdio.h>
void fun1(int f1)
{
	float li=3.2f;
	printf("in fun1(): li = %f\n",li);
	printf("in fun1(): f1 = %d\n",f1);
}
void fun2()
{
	char s[] ={"hello"};
	printf("In fun2(): s = %s\n",s);
	fun1(1111);
}
void fun3()
{
 	char str[]= {"Welcome to Sharma's Empire"};
	printf("In fun3(): s = %s\n",str);
	fun2();
	fun1(3333);
}
int main()
{
	int n=100;
	printf("in main(): n = %d\n",n);
	fun1(1000);fun2();fun3();fun1(2000);
	printf("End of Main");
}

