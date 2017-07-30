#include<stdio.h>
#include<malloc.h>

struct node 
{
	int data;
	struct node *next;
};
struct node *HEAD=NULL;
struct node *TEMP=NULL;
struct node *TAIL=NULL;

int main()
{	int choice=0;
	struct node *ptr;
	HEAD = (struct node*)malloc(sizeof(struct node));
	ptr = HEAD;
	printf("\nEnter:");
	scanf("%d"&(ptr->data));
	printf("\nMore:?:");
	scanf("%d",&choice);
	while(!choice)
	{
	    ptr->next = (struct node *)malloc(sizeof(struct node));
	    ptr = ptr->next;
	    printf("\nEnter Element:");
	    scanf("%d",&(ptr->data));
	    printf("\nMore:?:");
	    scanf("%d",&choice);
	}
	ptr->next=NULL;
	TAIL=ptr;
display();
reverse_inplace();
display();

return 0;	
}
void display()
{
	struct node *ptr = HEAD;
	do
	{
		printf("%d ",ptr->data);
	while(ptr=ptr->next);	
}
void reverse_inplace()
{
struct node *temp = HEAD;
struct node *ptr =HEAD;
do
{
	ptr=ptr->next;

