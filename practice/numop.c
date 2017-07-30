#include<stdio.h>
#include<stdio.h>
#include<math.h>
void check_palindrome(int num);
void reverse_num(int num);
void sum_digits(int num);
void check_armst(int num);

main(int argc , char * argv[])
{
	int num=atoi(argv[1]);
	check_palindrome(num);
	reverse_num(num);
	sum_digits(num);
	check_armst(num);

}

void check_palindrome(int num)
{
	int a=0;
	int rev=0;
	int temp1 = num;
	while(temp1!=0)
	{
		a=temp1%10;
		rev = rev*10+a;
		temp1/=10;
	}
	if(rev ==num)
		printf("\n\"%d\" is Palindromn",num);
	else
		printf("\n\"%d\" is not a Palindrome",num);
}
void reverse_num(int num)
{
	int temp=0;
	int rev =0;
	while(num!=0)
	{
	 	temp=num%10;
	 	rev=rev*10+temp;
		 num/=10;
	}

		printf("\nReverse of number is: \"%d\"",rev);
}
void sum_digits(int num)
{
	
	int sum=0;
	int temp=0;
	while(num!=0)
	{
		temp=num%10;
	 	sum+=temp;
	 	num/=10;
	 }
	 printf("\nSum of digits is: \"%d\"",sum);
}	
void check_armst(int num)
{
	
	int rev=0;
	int a=0;
	int temp1 = num;
	while(temp1!=0)
	{
		a=temp1%10;
		rev = a*a*a+rev;
		temp1/=10;
	}
	if(rev == num)
		printf("\n\"%d\" is an Armstrong number",num);
	else
		printf("\n\"%d\" is not an Armstrong number",num);
}
