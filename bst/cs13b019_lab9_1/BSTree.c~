/*
 * Author: Mohnish CS13B019 
 *
 * Binary Search Tree data structure (Implementation)
 */

#include "BSTree.h"
#include "Queue.h"
#include "LList.h"
#include <stdio.h>
#include <stdlib.h>

//Prints a tree in pre order

int printTreePre(node* root)
{
	
	if(root == NULL)
	{
		return 1;
	}
	
	printf("%d ",root->data);//Root left right
	
	if(root->left == NULL && root->right == NULL)
	{
		return 0;
	}

	printTreePre(root->left);
	printTreePre(root->right);
	
	return 0;
}


//Prints pre order w/o making a tree
void printPre(int inOrder[], int postOrder[], int inLow, int inHigh, int postLow, int postHigh)
{

	printf("%d ",postOrder[postHigh]);
	int i, j;
	if(inLow != inHigh )
	{
		i = indexOf(postOrder[postHigh],inOrder);
		j = indexOfLess(inOrder[i+1], postOrder, postHigh);
		
		if((i -1) >= inLow)
			printPre(inOrder, postOrder, inLow, i-1, postLow, j-1);
		if(inHigh >= i+1)
			printPre(inOrder, postOrder, i+1, inHigh, j, postHigh-1);
	}
	
	
	
}

//Assigns nodes to tree to give proper root from in and post order traversals

node* nodePre(int inOrder[], int postOrder[], int inLow, int inHigh, int postLow, int postHigh)
{
	node* root = nodeInit(postOrder[postHigh]);
	int i, j;

	if(inLow != inHigh)
	{
		i = indexOf(postOrder[postHigh],inOrder);
		j = indexOfLess(inOrder[i+1], postOrder, postHigh);
	
		if((i -1) >= inLow)
			root->left = (node*)nodePre(inOrder, postOrder, inLow, i-1, postLow, j-1);
		else
			root->left = NULL;
		if(inHigh >= i+1)
			root->right = (node*)nodePre(inOrder, postOrder, i+1, inHigh, j, postHigh-1);
		else
			root->right = NULL;
	}
	else
	{
		root->left = NULL;
		root->right = NULL;
	}
	return root;
}

//Builds a tree from in and pre order traversals
bst* treeBuild(int inOrder[], int postOrder[], int size)
{
	bst* tree = treeInit();
	tree->root = nodePre(inOrder, postOrder, 0, size-1, 0, size-1);
	return tree; 
}

//Returns index in an array
int indexOf(int value, int array[])
{
	int i = 0;
	
	while(1)
	{
		if(array[i] == value)
			return i;
		i++;
	}
}
//Return less than index of a value in an array
int indexOfLess(int value, int array[], int high)
{
	int i = 0;
	while(i < high)
	{
		if(array[i] >= value)
			return i;
		i++;
	}
	return i;
}



// finds right most node in a tree
int findRight(node* root)
{
	if(root->right  == NULL)
	{
		return root->data;
	}
	
	findRight(root->right);
}

//Prints an array in sorted manner
int printTree(bst* tree)
{
	
	if(tree->root == NULL)
	{
		return 1;
	}
	
	bst* treeLeft = treeInit();
	treeLeft->root = tree->root->left;
	
	bst* treeRight = treeInit();
	treeRight->root = tree->root->right;
	
	printTree(treeLeft);
	printf("%d ",tree->root->data);
	printTree(treeRight);
	
	return 0;
}
//Discarded function
bst* removeNode(bst* treeOrg, int value)
{
	bst* tree = treeOrg;//treeInit();
	int pre;
	int* pos = (int*)malloc(sizeof(int));
	node** prev = (node**)malloc(sizeof(node*));
	findNode(tree, value);//, prev, pos);
	node* root;
	if(*pos == 1) root = (*prev)->right;// = root->right;
		else root = (*prev)->left;
	if(root == NULL)
	{
		printf("Value not in tree \n");
		return treeOrg;
	}
	
	if(root->left = NULL)
	{
		
		if(*pos == 1) (*prev)->right = root->right;
		else (*prev)->left = root->right;
		free(root);
		
		return tree;
	}
	
	pre = findRight(root->left);
	
	root->data = pre;
	tree->root  = root->left;
	removeNode(tree, pre);
	
}
//Returns address of a node in a tree
node* findNode(bst* tree, int value)//, node** prev,int *pos)
{

	node *temp, *par;

	if(tree->root == NULL)
	{
		return NULL;
	}
	else
	{
		temp=tree->root;
		par = tree->root;
		while(temp!=NULL)
		{
			if(temp->data == value)
				break;
			else
			{
				par = temp;
				if(value < temp->data)
					temp = temp->left;
				else
					temp = temp->right;
			}
	}
	
	if(temp!=NULL)
		return temp;
	else 
		return NULL;
		
}

	
}

//Returns a new BSTree with root pointing to NULL

bst* treeInit()
{
	bst* tree = (bst*)malloc(sizeof(bst));
	tree->root = NULL;
	return tree;
}

//Creates a Node with the data set to the argument given
//Left and right pointers are set to null

node* nodeInit(int value)
{
	node* new = (node*)malloc(sizeof(node));
	new->left = NULL;
	new->right = NULL;
	new->data = value;
	return new;
}

//Insertion of a node
//Assumes such a value does not pre-exist in the tree

void insertNode(bst* tree, int value)
{
	node *temp, *par;

	if(tree->root == NULL)
	{
		tree->root = nodeInit(value);	
		return;
	}
	else
	{
		temp=tree->root;
		par = tree->root;
		while(temp!=NULL)
		{
			par = temp;
			if(value<temp->data)
				temp = temp->left;
			else
				temp = temp->right;
		}
		
		if(value<par->data)
			par->left = nodeInit(value);
		else
			par->right = nodeInit(value);
			
		return;
	}	
}


void case_a(node* par, node* loc, bst* tree)
{
	if(par==NULL)
		tree->root=NULL;
	else if(loc==par->left)
		par->left=NULL;
	else
		par->right=NULL;
}

void case_b(node *par, node *loc, bst *tree)
{
node *child;
	if(loc->left!=NULL)
		child=loc->left;
	else
		child=loc->right;

	
	if(par==NULL)
		tree->root=child;
	else if(loc==par->left)
		par->left=child;	
	else
		par->right=child;
		
}

void case_c(node *par, node *loc, bst *tree)
{
	node *ptr, *ptrsave, *suc, *parsuc;

	ptr=loc->right;
	ptrsave=loc;
	while(ptr->left!=NULL)	
	{
		ptrsave=ptr;
		ptr=ptr->left;
	}

	suc=ptr;
	parsuc=ptrsave;

	if(suc->left==NULL && suc->right==NULL)
		case_a(parsuc, suc, tree);
	else
		case_b(parsuc, suc,tree);

	if(par==NULL)
		tree->root=suc;
	else if(loc==par->left)
		par->left=suc;
	else
		par->right=suc;

	suc->left=loc->left;
	suc->right=loc->right;
}
//Removes a node assuming three possible cases 
void deletion(bst *tree, int x)
{
	node *p,*f=NULL;
	int i=0;
	p=tree->root;
	while(p!=NULL)
	{
		if(p->data==x)
			break;
		else if(p->data>x)
		{		
			f=p;	
			p=p->left;
		}
		else 
		{		
			f=p;	
			p=p->right;
		}
	}
		
	if(p==NULL)
	{
		printf("Not found\n");
		return;
	}

	if(p->left==NULL && p->right==NULL)
		case_a(f, p,tree);
	else if((p->left ==NULL && p->right!=NULL) || (p->left !=NULL && p->right==NULL))
		case_b(f, p,tree);
	else
		case_c(f, p,tree);

	free(p);
}


//Breadth first print of a BStree
void bfs(bst *tree)
{
	int *error = (int*)malloc(sizeof(int));
	Queue* q = queue_new();
	if(tree->root == NULL)
		return;
	else
	{
		enqueue(q,tree->root->data);
		while(queue_size(q)!=0)
		{
			int val = queue_front(q,error);
			node *temp = findNode(tree,val);
			if(temp->left!=NULL)
			{
				enqueue(q,temp->left->data);
			}
			if(temp->right!=NULL)
			{
				enqueue(q,temp->right->data);
			}
			printf("%d ",val);
			dequeue(q);
			
		}
	}
}
