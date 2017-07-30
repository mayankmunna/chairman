#include<stdio.h>
#include<stdlib.h>
struct node
{
	int value;
	struct node *next;
};
/** Function prototypes started**/

void fill_list(struct node *ptr);
void display_list();
void insert_ele();
void sort_list();
int get_count();

/** Function prototypes started**/
struct node *HEAD=NULL;
struct node *TAIL=NULL;
struct node *TEMP=NULL;

int main()
{
	struct node *ptr = NULL;
	int choice ;	
	if((HEAD = (struct node *) malloc(sizeof(struct node)))==NULL)
		{
			printf("\nProblem in allocating memory to HEAD node\n");
		}

	printf("\n1.Fill List.");
	printf("\n2.Insert Element.");
	printf("\n3.Display.");
	printf("\n4.Exit.");
	printf("\nChoice:");
	scanf("%d",&choice);

	while(choice!=4)
	{
	 switch(choice)
	 {
		case 1:
			ptr = HEAD;
			fill_list(ptr);
			break;		
		case 3:
			display_list();
			break;
		case 2:
			insert_ele();
				break;
		default:
			printf("\n\tEnter Correct Choice\n");
	 }
		printf("\n1.Fill List.");
		printf("\n2.Insert Element.");
		printf("\n3.Display.");
		printf("\n4.Exit.");
		printf("\nChoice:");
		scanf("%d",&choice); 
	}
return 0;
}
//Function to accept the elements in the list.
void fill_list(struct node *ptr)
{	
	int choice =0;
	printf("\nEnter the value:");
	scanf("%d",&(ptr->value));
	
	printf("\nDo you want to Enter more Data:\n1.NO\n 0.YES\nChoice:");
	scanf("%d",&choice);

	while(choice!=1)
	{
		if((ptr->next = (struct node *) malloc(sizeof(struct node)))==NULL)
		{
			printf("\nProblem in allocating memory to new node\n");
			return;
		}
		ptr = ptr->next;
		printf("\nEnter the value:");
		scanf("%d",&(ptr->value));
		printf("\nDo you want to Enter more Data:\n1.NO\n 0.YES\nChoice:");
		scanf("%d",&choice);
	}
	ptr->next =NULL;
	TAIL = ptr;
	sort_list();
}
//Function to display the list elements.
void display_list()
{
	struct node *temp_disp = HEAD;
	if(HEAD == NULL)
		{
			printf("\nList is empty\n");
			return ;
		}
	printf("\tList is \n");
	do
	{
	
		printf("|%d",temp_disp->value);
	}while(temp_disp=temp_disp->next);
}
//Function to sort the accepted list so that insertion should be easier
void sort_list()
{
	int count = get_count();
	int iterator=0;
	int j;
	int temp;
	struct node *ptr;
	struct node *ptr_next;
		for(iterator=0;iterator<count;iterator++)
		 {
			ptr = HEAD;
			ptr_next=ptr->next;
			for(j=0;j<count-iterator-1;j++)
			{
				if((ptr->value) > (ptr_next->value))
					{
						temp = ptr->value;
						ptr->value = (ptr_next)->value;  
						(ptr_next)->value = temp;
					}
				ptr=ptr->next;
				ptr_next = ptr_next->next;
			}
		}	

}
//Function to count the elements in the list so that the count can be set while sorting the list.
int get_count()
{
	struct node *ptr = HEAD;
	int count =0;
	while((ptr = ptr->next))
	{
		count++;
	}
	if(count>0)
		count++;
		
 	return count;
}	
//Function to insert the element in the linked list by finding the appropriate position.
void insert_ele()
{
	struct node *ptr,*left,*right;
	//int element=0;
	if(HEAD==NULL)
		{
			printf("\nList is empty ,Fill the list before\n");
			return;
		}
	else
	{
		ptr = HEAD;
		if((TEMP = (struct node*)malloc(sizeof(struct node)))==NULL)
			{
				printf("\nProblem allocating memory to TEMP");
				return;
			}
			printf("\nEnter the Element:");
			scanf("%d",&(TEMP->value));
		while(ptr->next)
		{
			left = ptr;
			right = ptr->next;
			if( ((TEMP->value)>(left->value))&&((TEMP->value) <= (right->value)) )
				{
					left->next = TEMP;
					TEMP->next= right;
				}
			ptr=ptr->next;	
		}
	}
}

