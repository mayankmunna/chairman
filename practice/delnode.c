#include<stdio.h>
#include<stdlib.h>
void display();

struct node 
{
	int val;
	struct node *left;
	struct node *right;
};

/****************************************************************************/

void insert_node(struct node *, struct node*, struct node *);
struct node * search_node(struct node *, int);
struct node *getnode();
void display();
void delete_node(int);
int find_largest(struct node *);
int find_smallest(struct node *);

/**************************************************************************/

struct node * root=NULL;
struct node *par_node = NULL;
int main()
{
	int choice =0;
    int data;  
    struct node * ptr= NULL;
     printf("\n\n1.Insert.\n2.Display.\n3.Delete Node.\n4.Exit.\nChoice:");
     scanf("%d",&choice);
        while(choice!=4)
        {
                switch(choice)
                {
                 case 1:
                        ptr = getnode();
                        insert_node(ptr, root, root);
                        break;
                 case 2:
                         display(root);
	                        break;
				 case 3:
 						printf("\nEnter Data to Delete:");
			 			scanf("%d",&data);
						delete_node(data);
							break;
                 default :
                        printf("\n\n\tEnter correct choice\n");
                        break;
                }
       printf("\n\n1.Insert.\n2.Display.\n3.Delete Node.\n4.Exit.\nChoice:");
                scanf("%d",&choice);
        }
return 0;
}

struct node *getnode()
	{
		struct node *new_node = (struct node *)malloc(sizeof(struct node));
		printf("\nEnter the Value:");
		scanf("%d",&new_node->val);
		new_node->left = new_node->right = NULL;
	return new_node;
	}


void insert_node(struct node *new_node, struct node *ptr, struct node *parent)
{
	if(root == NULL)
	{
		root = new_node;
		return;
	}
		
	if((ptr==NULL)&&(new_node->val < parent->val))
	{
		parent->left = new_node;
		return;
	}

	if((ptr==NULL)&&(new_node->val > parent->val))
	{
		parent->right = new_node;
		return;
	}

	if((new_node->val < ptr->val)&&((ptr!=NULL)))
		insert_node(new_node,ptr->left,ptr);
	else if((new_node->val > ptr->val)&&(ptr!=NULL))
		insert_node(new_node,ptr->right,ptr);

}


void display(struct node *ptr)
{
	if(ptr == NULL)
		return;
	display(ptr->left);
	printf("%d\t",ptr->val);
	display(ptr->right);
}

void delete_node(int data)
{
 int rep_value=0;
 struct node *ptr = root,*temp=root;
 struct node * del_node=NULL;

 del_node = search_node(temp,data);

	if(del_node == NULL)
	{
		printf("\nNO data");
		return;
	}
	if(del_node->right == NULL && del_node ->left ==NULL)
	{
	  if(del_node == par_node ->left)
	   {
		par_node->left = NULL;	
		free(del_node);
	  	return;
	   }
	 else if(del_node == par_node ->right)
	   {
		par_node->right = NULL;
		free(del_node);
	   	return;
	   }
	}	
	else if(del_node->right == NULL && del_node->left!=NULL)
	{
		if(par_node->left == del_node)
		{
			  par_node->left = del_node->left;
			  free(del_node);
			  return;
		}
	 	else if(del_node == par_node ->right)
	   	{
			par_node->right = del_node->left;
			free(del_node);
	   		return;
	   	}

	}

	else if(del_node->right!= NULL && del_node->left == NULL)
	{	
		if(par_node->left == del_node)
		{
			  par_node->left = del_node->right;
			  free(del_node);
			  return;
		}
		else if(par_node->right == del_node)
		{
			  par_node->right = del_node->right;
			  free(del_node);
			  return;
		}		
	}
	else if(del_node->left!=NULL && del_node ->right !=NULL)
	{
		if(del_node->right!=NULL)
		{
			rep_value=find_smallest(del_node);
			if(rep_value>0)
			{
				del_node->val = rep_value;
				return;
			}
			else
			  { 
				 printf("\nNo Data\n");
				return;
			  }
		}	
		else 
		{
			rep_value = find_largest(del_node);
			  del_node->val = rep_value;
					return;

		}	
	}

}
int find_smallest(struct node *ptr)
{
	int value =0;
	ptr = ptr->right;
	while(ptr->left)
		{
			ptr = ptr->left;
		}
	value = ptr->val;
	delete_node(ptr->val);
		return value;
}

int find_largest(struct node *ptr)
{
	int value =0;
 	ptr = ptr->left;
		while(ptr->right)
			{
			 ptr = ptr->right;
			}
		value = ptr->val;
		delete_node(ptr->val);
	return value;
		
}



struct node* search_node(struct node *ptr,int data)
{
	while(ptr!=NULL)
	{

		if(ptr->val==data)
			return ptr;
		
		if(data	> ptr->val)
		{
			  par_node=ptr;
			  ptr=ptr->right;
		}
		else if(data < ptr->val)
		{
			  par_node = ptr;
	 		  ptr=ptr->left;
		}
		else
			  return NULL;
	}
}
