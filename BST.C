#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node* left;
	struct node* right;	
};
struct node* createnode(int val)
{
	struct node* newnode=(struct node*)malloc(sizeof (struct node));
	newnode->data=val;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}
struct node* insert(struct node* newnode, int val)
{
	if(newnode==NULL)
	{
		return createnode(val);
    }
    if(newnode->data==val)
    {
    	return newnode;
	}
	if(newnode->data<val)
	{
		newnode->right=insert(newnode->right,val);
	}
	else
	{
		newnode->left=insert(newnode->left,val);
	}
	return newnode;
}
void inorder(struct node* newnode)
{
	if(newnode!=NULL)
	{
		inorder(newnode->left);
		printf("%d",newnode->data);
		inorder(newnode->right);
	}
}
void preorder(struct node* newnode)
{
	if(newnode!=NULL)
	{
		printf("%d",newnode->data);
		preorder(newnode->left);
		preorder(newnode->right);
	}
}
void postorder(struct node* newnode)
{
	if(newnode!=NULL)
	{
		postorder(newnode->left);
		postorder(newnode->right);
		printf("%d",newnode->data);
	}
}
struct node* smallest(struct node* newnode)
{
	if(newnode==NULL)
	{
	return NULL;
	}
	while(newnode->left!=NULL)
	{
		newnode=newnode->left;
	}
	return newnode;
}
struct node* largest(struct node* newnode)
{
	if(newnode==NULL)
	{
	return NULL;
	}
	while(newnode->right!=NULL)
	{
		newnode=newnode->right;
	}
	return newnode;
}
struct node* getSuccessor(struct node* curr) {
    curr = curr->right;
    while (curr != NULL && curr->left != NULL)
        curr = curr->left;
    return curr;
}
struct node* delNode(struct node* newnode, int x) 
{
    if (newnode == NULL)
        return newnode;
    if (newnode->data > x)
        newnode->left = delNode(newnode->left, x);
    else if (newnode->data < x)
        newnode->right = delNode(newnode->right, x);
    else {
        if (newnode->left == NULL) {
            struct node* temp = newnode->right;
            free(newnode);
            return temp;
        }
        if (newnode->right == NULL) {
            struct node* temp = newnode->left;
            free(newnode);
            return temp;
        }
        struct node* succ = getSuccessor(newnode);
        newnode->data = succ->data;
        newnode->right = delNode(newnode->right, succ->data);
    }
    return newnode;
}

int main()
{
	struct node* newnode=createnode(4);
	newnode->left=createnode(2);
	newnode->right=createnode(6);
	newnode->left->left=createnode(1);
	newnode->left->right=createnode(3);
	newnode->right->left=createnode(5);
	newnode->right->right=createnode(7);
	printf("inorder traversal \n");
	inorder(newnode);
	printf("\n");
	printf("preorder traversal \n");
	preorder(newnode);
	printf("\n");
    printf("postorder traversal \n");
	postorder(newnode);
	printf("\n");
	struct node* findmin=smallest(newnode);
	if (findmin!=NULL)
	printf("smallest node is %d\n",findmin->data);
	else
	printf("tree is empty\n");
	struct node* findmax=largest(newnode);
	if (findmax!=NULL)
	printf("largest node is %d\n",findmax->data);
	else
	printf("tree is empty\n");
	int x =14;
	struct node* del = delNode(newnode, x);
	return 0;
}



    


