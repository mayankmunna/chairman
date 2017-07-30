#include<stdio.h>
#include<math.h>
long int find_fact(long int num);

main()
{
	long int n=0;
	long int r=0;
	long int combi=0;
	printf("\t\nnCr\n\n\n");
	printf("Enter the value of \'n\':");
	scanf("%d",&n);
	printf("Enter the value of \'r\':");
	scanf("%d",&r);
 	combi =find_fact(n)/(find_fact(r)*find_fact(n-r));
	printf("\nCombination is :%d",combi);
}
long int find_fact(long int num)
{
	long int fact =1;
	if(num==0)
		return 1;
	else
	  while(num>=1)
	  {
		fact*=(num);
		num--;
	  }
	return fact;
}	
