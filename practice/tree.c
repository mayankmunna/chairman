#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left;
	struct node *right;
};

struct node *getnode();
void insert_node(struct node * n ,struct node *ptr,struct node * parent);
void display(struct node *);

struct node *ROOT=NULL;
int main()
{
	int choice =0;
	int data_node;
	struct node * ptr= NULL;
       printf("1.Insert.\n2.Display.\n3.Exit.\nChoice:");
        scanf("%d",&choice);
        while(choice!=3)
        {
                switch(choice)
                {
                 case 1:
			ptr = getnode();
                        insert_node(ptr,ROOT,ROOT);
                        break;
                 case 2:
                      	 display(ROOT);
                       
                        break;
                 default :
                        printf("\nEnter correct choice\n");
                        break;
                }

                printf("\n1.Insert.\n2.Display\n3.Exit.\nChoice:");
                scanf("%d",&choice);
	}
return 0;
}
void insert_node(struct node * n, struct node *ptr, struct node * parent)
{	if(ROOT == NULL)
	{

		printf("first node on root \n");
		ROOT = n;
		return ;
	}
	
	if((ptr == NULL) && (n->data < parent->data))
	{	parent->left = n; return;}
	else if ((ptr == NULL) && (n->data >= parent-> data))
	{	parent->right = n;return ;}

	if(n->data > (ptr->data))
	{
		insert_node(n,ptr->right,ptr);
	}	
 	else if(n->data < (ptr->data))
	{
		insert_node(n,ptr->left,ptr);
	}
}

struct node *getnode()
	{
		struct node * p;

		if((p = (struct node *)malloc(sizeof(struct node)))==NULL)
			printf("\nMEMORY allocation problem..\n");
			printf("Give Val \n");
			scanf("%d",&(p->data));
			p->left = p->right = NULL;
	return p;
	}

void display(struct node *ptr)
{
	if(ptr == NULL)
		return;
	display(ptr->left);
	printf("%d\t",ptr->data);
	display(ptr->right);
}





