#include<stdio.h>
#include<stdlib.h>


struct node
{
	int value;
	struct node *next;
};

void fill_list(struct node *);
struct node * display(struct node *);

struct node * HEAD;
struct node * TAIL;

int main()
{	
	int choice =0;
	struct node * ptr =NULL;
	if((HEAD=(struct node *)malloc(sizeof(struct node)))==NULL)
	printf("MEMORY not allocated");
	ptr = HEAD;
	printf("1.Fill List.\n2.Display List\n3.Exit.\nChoice:");
	scanf("%d",&choice);
	while(choice!=3)
	{
		switch(choice)
		{
		 case 1:
			fill_list(ptr);
			break;
		 case 2:
			display(HEAD);
			printf("%d",ptr->value);
			break;
		 default :
			printf("\nEnter correct choice");
			break;
		}
	
		printf("\n1.Fill List.\n2.Display List\n3.Exit.\nChoice:");
		scanf("%d",&choice);
	}
return 0;
}
void fill_list(struct node *ptr)
{
	int choice =0;
	printf("Enter Data:");
	scanf("%d",&ptr->value);
	printf("\nEnter more:0(NO) or 1(YES):");
	scanf("%d",&choice);
	
	if(choice == 1)
	{
		 
		if((ptr->next=(struct node *)malloc(sizeof(struct node)))==NULL)
			printf("MEMORY not allocated");
		fill_list(ptr = ptr->next);
	}
	else 
	{
		ptr->next = NULL;
		TAIL = ptr;
		return;
	}
}

struct node *display(struct node *ptr)
{
		

		if(ptr!=TAIL)
			{
				printf("%d\t",ptr->value);
				display(ptr=ptr->next);
				printf("%d\t",ptr->value);
			}
		else
			{
				printf("%d\t",ptr->value);
                                printf("\nReverse\n");
				return;
                                
			}
	return ptr;
}







