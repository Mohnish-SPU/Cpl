/*
 * Author: Mohnish CS13B019 
 *
 * Binary Search Tree data structure (Implementation)
 */

#include "BSTree.h"
#include <stdio.h>
#include <stdlib.h>

int printTreePre(bst* tree)
{
	
	if(root == NULL)
	{
		printf("No tree to print \n");
		return 1;
	}
	
	printf("%d ",tree->root->data);
	
	if(root->left == NULL && root->right == NULL)
	{
		return 0;
	}

	printTreePre(tree->root->left);
	printTreePre(tree->root->right);
	
	return 0;
}


node* nodePre(int inOrder[], int postOrder[], int inLow, int inHigh, int postLow, int postHigh)
{
	node* root = nodeInit(postOrder[postHigh]);
	return root;
	
	if(inLow != inHigh)
	{
		int i = indexOf(postOrder[postHigh],inOrder);
		int j = indexof(inOrder[i+1], postOrder);
		
		root->left = nodePre(inOrder, postOrder, inLow, i-1, postLow, j-1);
		root->right = Pre(inOrder, postOrder, i+1, inHigh, j, postHigh-1);
	}
	else
	{
		root->left == NULL;
		root->right == NULL;
	}
}


bst* treeBuild(int inOrder[], int postOrder[], int size);
{
	bst* tree = treeInit();
	tree->root = nodePre(inOrder, postOrder, 0, size, 0, size);
	return tree; 
}

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


void printPre(int inOrder[], int postOrder[], int inLow, int inHigh, int postLow, int postHigh)
{
	printf("%d ",postOrder[postHigh]);
	
	if(inLow != inHigh)
	{
		int i = indexOf(postOrder[postHigh],inOrder);
		int j = indexof(inOrder[i+1], postOrder);
		
		printPre(inOrder, postOrder, inLow, i-1, postLow, j-1);
		printPre(inOrder, postOrder, i+1, inHigh, j, postHigh-1);
	}
}

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
	
	return 0;
}

bst* removeNode(bst** treeOrg, int value)
{
	bst* tree = *treeOrg;//treeInit();
	int pre;
	int* pos = (int*)malloc(sizeof(int));
	node** prev = (node**)malloc(sizeof(node*));
	findNode(&tree, value, prev, pos);
	node* root;
	if(*pos == 1) root = *prev->right;// = root->right;
		else root = *prev->left;
	if(root == NULL)
	{
		printf("Value not in tree \n");
		return treeOrg;
	}
	
	if(root->left = NULL)
	{
		
		if(*pos == 1) *prev->right = root->right;
		else *prev->left = root->right;
		free(root);
		
		return tree;
	}
	
	pre = findRight(root->left);
	
	root->data = pre;
	tree->root  = root->left;
	removeNode(&tree, pre);
	
}
node* findNode(bst** treeOrg, int value, node** prev,int *pos)
{
	bst* tree = *treeOrg;
	
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
	findNode( &tree, value, prev);
	
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

bst* insertNode(bst** treeOrg, int value)
{
	bst* tree = *treeOrg;
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
	insertNode( &tree, value);
}
