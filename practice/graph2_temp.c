/**************************************************************************
WRITE A FUNCTION TO TAKE TEMPERATURES AS INPUT FROM USER AND MAKE A GRAPH OF IT.
**  Authors:
**     Prateek Verma     <288743>
**     Nishant Gautam    <288736>
**     DATE:    27/06/2014
*************************************************************************/


#include<stdio.h>
#include<stdlib.h>


int main()
{
	int tem[20];
	tem[0]=tem[1]=0;
	char graph[25][20];
	int i=24,j=0,m=0,n=0;
	char month[12][3]={{"JAN"},{"FEB"},{"MAR"},{"APR"},{"MAY"},{"JUN"},{"JUL"},{"AUG"},{"SEP"},{"OCT"},{"NOV"},{"DEC"}};
	
		for(m=0;m<12;m++)
		{
			printf("enter the value of temperature for %d  month\n",m);
			scanf("%d",&tem[m]);
		}
		for(m=2;m<14;m++)
		{
			printf(" %c%c%c    :     %d\n",month[m-2][0],month[m-2][1],month[m-2][2],tem[m-2]);
		}
			 
		printf("THE GRAPH FOR THE FOLLOWING INPUT IS\n");
		
		for(i=0;i<23;i++)
			{
				printf("          |   ");
				for(j=2;j<20;j++)
					{
					if(i<(25-2-tem[j-2]))
					printf("       ");
					else
					{
					if(j<14)	
					printf(" |***| ");
					}
					}
					printf("\n");
			}
		for(j=0;j<20;j++)
		{
			printf("   -   ");
		}
		printf("\n");
		i=i+1;
		printf("          |   ");
		for(n=2;n<14;n++)
		{
			printf(" %c%c%c ",month[n-2][0],month[n-2][1],month[n-2][2]);
		}
}


		

