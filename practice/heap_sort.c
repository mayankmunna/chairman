#include<stdio.h>
#include<stdlib.h>
struct node
{
	int val;
	struct node *left;
	struct node *right;
};
struct node *get_node();

void insert_node(struct node *,struct node *,struct node *);
void swap(struct node *, struct node*);
void heap(struct node *);
void display(struct node *);



struct node * root= NULL;

int main()
{
 int choice = 1;
 struct node *ptr = NULL;
 while(choice!=0)
  {	
 	ptr = get_node();
 	insert_node(ptr,root,root);
	printf("\nInsert more (1):");
	scanf("%d",&choice);
  }

	printf("\nBefore Sorting:\t");
 	display(root);

  	heap(root);

	printf("\nAfter Sorting:\t");
 	display(root);
return 0;
}
struct node *get_node()
{
	
	struct node * new_node = (struct node *)malloc(sizeof(struct node));
	printf("Enter the Value:");
	scanf("%d",&new_node->val);
	new_node->right = new_node->left = NULL;
	return new_node;
}	
void insert_node(struct node *new_node,struct node *ptr,struct node *parent)
{
		if(root == NULL)
			{
				root = new_node;
				return;
			}
		if((new_node->val > parent->val)&&( ptr==NULL))
			{
				parent->right = new_node;
				return;
			}	
		if((new_node->val < parent->val)&&( ptr==NULL))
		 {
		 	parent->left = new_node;
			return;
		}

		if((new_node->val > ptr->val)&&( ptr!=NULL))
				insert_node(new_node,ptr->right,ptr);
		else if((new_node->val < ptr->val)&&( ptr!=NULL))
				insert_node(new_node,ptr->left,ptr);
}		
void display(struct node * ptr)
{
	if(ptr == NULL)
		return;
	printf("%d\t",ptr->val);
	display(ptr->left);
	display(ptr->right);
}
void heap(struct node * ptr)
{
	   if(root == NULL)
	    {
		printf("\nEmpty Tree");
		return;
	    }
	
	if(ptr->left)
		heap(ptr->left);
	if(ptr->right)
		heap(ptr->right);

	if(!ptr->left && !ptr->right)
		return;
	else if (ptr->left && !ptr->right)
	{
		if(ptr->left->val > ptr ->val)
		{
			swap(ptr->left,ptr);
			heap(ptr);
			return;
		}
		else
			return;
	}
	else if((!ptr->left && ptr->right))
	{
		if(ptr->right->val >ptr->val)
		{
			swap(ptr->right,ptr);
			heap(ptr);
			return;
		}
		else
			return;
	}
	else if(ptr->left && ptr->right)
	{
		if(ptr->val < ptr->right->val || ptr->val < ptr->left->val)
		{
			if(ptr->right->val > ptr->left->val)
			{
			   swap(ptr,ptr->right);
			   heap(ptr);
			   return;
			}
			else
			{
			  swap(ptr,ptr->left);
			  heap(ptr);
			  return;
			} 
		}
	}	

}	

void swap( struct node * left,struct node * right)
{
	int temp;
	temp = right->val;
	right->val=left->val; 
	left->val =temp;
}	

