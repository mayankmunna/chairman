#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int value;
	struct node *next;
	struct node *prev;
};
struct node *HEAD = NULL;
struct node *TAIL= NULL;
struct node *TEMP= NULL;
int main()
{
	struct node *ptr=NULL;
	int input =0;
	int choice =0;
	
	if ((HEAD =(struct node *)malloc(sizeof(struct node)))==NULL)
	{
		printf("Memory Allocation Failed\n");
	}
	else
	{
			ptr=HEAD;
			printf("\nEnter the Value:");
			scanf("%d",&input);
			ptr->value = input;
			ptr->prev=HEAD;	
			printf("Want to Enter More?\n0.Yes.\n1.NO\nChoice:");
			scanf("%d",&choice);


		while(choice!=1)	
		{
		if((ptr->next =(struct node *)malloc(sizeof(struct node)))==NULL)
			printf("Memory Allocation Failed\n");
		TEMP = ptr; // assigning previous address to next node which is going to be current.
		ptr=ptr->next;
		printf("\nEnter the Value:");
		scanf("%d",&input);
		ptr->value = input;
		ptr->prev = TEMP;			
		printf("Want to Enter More?\n0.Yes.\n1.NO\nChoice:");
		scanf("%d",&choice);
		}
		ptr->next=NULL;
		TAIL=ptr;
	}

	printf("\nEntered elements in regular direction:\n");
	ptr=HEAD;
	do
	{
	printf("%d\t",ptr->value);
	}while((ptr=ptr->next)!=NULL);
	
	printf("\nEntered elements in reverse  direction:\n");
	ptr=TAIL;
	do
	{
	printf("%d\t",ptr->value);
	}while((ptr=ptr->prev)!=HEAD);

	printf("%d\t",ptr->value);

return 0;
}



