#include<stdio.h>
#include<stdlib.h>
struct node
{
 	int data;
	struct node *next;
};

void push();
void pop();
void display();

struct node * TOP =NULL;

int main()
{
int choice;

printf("\n1.Push.");
printf("\n2.POP.");
printf("\n3.Exit.");
printf("\nChoice:");
scanf("%d",&choice);

while(choice!=3)
	{
		switch(choice)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			default:
				printf("\nEnter Correct option");
		}

			printf("\n1.Push.");
			printf("\n2.POP.");
			printf("\n3.Exit.");
			printf("\nChoice:");
			scanf("%d",&choice);
	}
	
return 0;
}
void push()
{	
	struct node *NEW;
	struct node *TEMP;
	int choice;
	if(TOP == NULL)
	{
		NEW = (struct node*)malloc(sizeof(struct node));
		printf("\nEnter Data:");
		scanf("%d",&(NEW->data));
		NEW->next=TOP;
		TOP = NEW;
	}
	printf("\nPush more.\n0.YES\n1.NO.\nChoice:");
	scanf("%d",&choice);

	while(choice!=1)
		{
			NEW = (struct node *)malloc(sizeof(struct node));
			//NEW=NEW->next;
			printf("\nEnter Data:");
			scanf("%d",&(NEW->data));
			NEW->next =TOP;
			TOP=NEW;
			printf("\nPush more.\n0.YES\n1.NO.\nChoice:");
			scanf("%d",&choice);
		}
		
			display();
}
void display()
{
struct node *TEMP=TOP;
	if(TOP==NULL)
	{
		printf("\nList is Empty");
	}
	else
	{
		do
		{
			printf("|% d",TEMP->data);
		
		}while(TEMP=TEMP->next);
	}
}	
void pop()
{struct node * TEMP;
	int choice=0;
	while(choice!=1)
		{	if(TOP == NULL)
			{
				printf("\nUnderflow Condition.....System Exiting");
				return;
			}
			TEMP=TOP;
			free(TOP);
			TOP=TEMP->next;
			display();
			printf("\nh POP more?\n0.YES\n1.NO.\nChoice:");
			scanf("%d",&choice);
		}free(TEMP);
		
}
