#include<stdio.h>
#include<string.h>
void str_conc(char *,char *);
void str_copy(char *,char *);
void str_cmp(char *,char *);
main()
{
	char str1[100];
	char str2[100];
	int choice =0;

	do{
	printf("\n\n\n\t1.String Concatenation\n\t2.String Copy\n\t3.String Compare\n\t4.All of the Above\n\t5.Exit.\n\tEnter Choice:");
	scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				str_conc(str1,str2);
				break;
			case 2:
				str_copy(str1,str2);
				break;
			case 3:
				str_cmp(str1,str2);
				break;
			case 4:
				str_conc(str1,str2);	
				str_copy(str1,str2);	
				str_cmp(str1,str2);
				break;
		}	
	   }
	while(choice!=5);
return 0;
}
void str_conc(char *str1,char *str2)
{	printf("\nEnter String First:");
	scanf("%s",str1);
	printf("Enter String Second:");
	scanf("%s",str2);

	int len_str1=0;
	int index_str2=0;
	while(str1[len_str1]!='\0')
		len_str1++;
	

	while(str2[index_str2]!='\0')
		{
			str1[len_str1]=str2[index_str2];
			len_str1++;
			index_str2++;
		}
		str1[len_str1]='\0';
	printf("\nConcatenated String is :%s",str1);
}
void str_copy(char *str_dest,char *str_src)
{
	printf("\nEnter String First:");
	scanf("%s",str_dest);
	printf("\nEnter String Second:");
	scanf("%s",str_src);

	int index_src=0;
//	while(str_dest[index_dest]!='\0')
//	index_dest++;
	while(str_src[index_src]!='\0')
		{
			str_dest[index_src]=str_src[index_src];
			index_src++;
		}
		str_dest[index_src]='\0';
		printf("String 1 over written with String 2 which is : %s",str_dest);
}
void str_cmp(char *str1,char *str2)
{
	printf("\nEnter String First:");
	scanf("%s",str1);
	printf("\nEnter String Second:");
	scanf("%s",str2);

	int result=0;
	int index=0;
	while(str1[index]!='\0' && str2[index]!='\0')
	{	
		if(str1[index] == str2[index])
		{
			result =0;
			index++;
		}
		if(str1[index]< str2[index])
		{
			result =-1;
			break;
		}
		if(str1[index]> str2[index])
		{
			result = 1;
			break;
		}
		
	}

	printf("\tString 1 is %s String 2", (result<0)?"< Than":(result>0)?"> Than":"==");
}

				
