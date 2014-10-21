/*
 * Author: <Your Name>
 * Binary Search Tree data structure (Implementation)
 */

#include "BSTree.h"
bst* removeNode()

node* findNode(bst* treeOrg, int value, node* prev,int *pos)
{
	bst* tree = treeOrg;
	
	if(tree->root == NULL )
		return NULL:
	
	if(tree->root->data < value)
	{
		if(tree->root->right->data == value)
		{
			*pos = 1;
			prev = tree->root;
			return tree->root->right;
		}
		tree->root = tree->root->right;
	}
	else if(tree->root->data > value)
	{
		if(tree->root->left->data == value)
		{
			*pos = -1;
			prev = tree->root;
			return tree->root->left;
		}
		tree->root = tree->root->left;		
	}
	findNode( tree, value, prev);
	
}

bst* treeInit()
{
	bst* tree = (bst*)malloc(sizeof(bst));
	tree->root = NULL;
	return tree;
}
node* nodeInit(int value)
{
	node* new = (node*)malloc(sizeof(node));
	new->left = NULL;
	new->right = NULL;
	new->data = value;
	return new;
}
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
