#include<stdio.h>
int is_prefix(char *,char *);
int is_sufix(char *,char *);
int calculate_size(char *);
int main()
{
	int sufix=0;
	int prefix=0;
	
	char str1[50];
	char str2[100];
	printf("Enter the String 1:");
	scanf("%s",str1);
	printf("Enter the String 2:");
	scanf("%s",str2);
	sufix = is_sufix(str1,str2);
	prefix= is_prefix(str1,str2);
	
	if(sufix==1&&prefix==0)
		{
		printf("%s is sufix to %s ",str1,str2);
		}
    else if(sufix==0&&prefix==1)
		{
		printf("%s is sufix to %s ",str1,str2);
		}
			
    else if(sufix==1&&prefix==1)
		{
		printf("%s is both sufix and prefix to %s ",str1,str2);
		}
	else 

		printf("\nNeither Sufix Nor Prefix to String 2");
return 0;
}
int is_prefix(char *str1,char *str2)
{
	int i=0;
	int same =0;
	while(str1[i]!='\0')
		{
			if(str1[i]==str2[i])
			{
				same=1;
				i++;
			}
	    		else
			{
				same=0; 
				break;
			}
	    }
	return same;
}
int is_sufix(char *str1,char *str2)
{
	int same=0;
	int size = calculate_size(str1);
	int size1 = calculate_size(str2);
		while(size>=0)
		{
			if(str1[size]==str2[size1])
			{
				same =1;
				size--;
				size1--;
			}	
			else 
			{
				same=0; 
				break;
			}

			
		}		
		return same;
}
int calculate_size(char *str)
{
	int count=0;
	int i=0;
	while(str[i]!='\0')
	{

		count++;
		i++;
	}
return count;
}
