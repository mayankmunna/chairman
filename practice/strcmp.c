#include<stdio.h>
#include<string.h>
int main()
{
	char str1[100]="hari";
	char str2[100]="hari t";	
	int cmp;
	cmp = strcmp(str1,str2);
	printf("Value of cmp is %d\n",cmp);
	printf("\n\"%s\"and\"%s\" after concatenation is :",str1,str2);
        printf("\"%s\"",strcat(strcat(str1," "),str2));
return 0;
}

