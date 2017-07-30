#include<stdio.h>
main(int argc,char *argv[])
{
int i;
for(i=0;argv[1][i];i++)
{
if((argv[1][i]>='a')&&(argv[1][i]<='z'))
argv[1][i]=argv[1][i]-32;
}
printf("%s",argv[1]);
}

