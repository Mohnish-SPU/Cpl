/*
 * Author: Mohnish CS13B019 
 *
 * Binary Search Tree data structure (Implementation)
 */

#include "BSTree.h"

int findRight(node* root)
{
	if(root->right  == NULL)
	{
		return root->data;
	}
	
	findRight(root->right);
}

int printTree(node* root)
{
	
	if(root == NULL)
	{
		printf("No tree to print \n");
		return 1;
	}
	if(root->left == NULL && root->right == NULL)
	{
		printf("%d ",root->data);
		return 0;
	}
	printTree(root->left);
	printTree(root);
	printTree(root->right);
	printf("\n");
	return 0;
}

bst* removeNode(bst* treeOrg, int value)
{
	bst* tree = treeInit();
	int pre;
	int* pos = (int*)malloc(sizeof(int));
	node** prev = (node**)malloc(sizeof(node*));
	node* root = findNode(tree, value, prev, pos);
	if(root == NULL)
	{
		printf("Value not in tree \n");
		return treeOrg;
	}
	
	if(root->left = NULL)
	{
		free(root);
		if(*pos == 1) *prev->right == root->right;
		else *prev->left == root->right;
		
		return tree;
	}
	
	pre = findRight(root->left);
	
	root->data = pre;
	tree->root  = root->left;
	removeNode(tree, pre);
	
}
node* findNode(bst* treeOrg, int value, node** prev,int *pos)
{
	bst* tree = treeOrg;
	
	if(tree->root == NULL )
		return NULL:
	
	if(tree->root->data < value)
	{
		if(tree->root->right->data == value)
		{
			*pos = 1;
			*prev = tree->root;
			return tree->root->right;
		}
		tree->root = tree->root->right;
	}
	else if(tree->root->data > value)
	{
		if(tree->root->left->data == value)
		{
			*pos = -1;
			*prev = tree->root;
			return tree->root->left;
		}
		tree->root = tree->root->left;		
	}
	findNode( tree, value, prev);
	
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

bst* insertNode(bst* treeOrg, int value)
{
	bst* tree = treeOrg;
	if(tree->root == NULL)
	{
		tree->root = nodeInit(value);
		return tree;
	}	
	if(tree->root->data < value)
	{
		if(tree->root->right == NULL)
		{
			tree->root->right = nodeInit(value);
			return tree;
		}
		tree->root = tree->root->right;
	}
	else(tree->root->data > value)
	{
		if(tree->root->left == NULL)
		{
			tree->root->left = nodeInit(value);
			return tree;
		}
		tree->root = tree->root->left;		
	}
	insertNode( tree, value);
}
