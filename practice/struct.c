#include<stdio.h>
struct structure1
{
char a;
char b;
int c;
}obj;
struct structure2
{
char a;
char b;
short int c;
long member4;
}obj1;



main()
{
printf("size of struct1 is :%d",sizeof(obj));

printf("size of struct2 is :%d",sizeof(obj1));
}
