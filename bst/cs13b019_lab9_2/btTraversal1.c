
#include "BSTree.h"
#include <stdio.h>
#include <stdlib.h>

node* buildTreePost (int pre[], int size);
node* nodePost (int pre[], int* prev,int low, int high, int size);
int printTreePost(node* root);

main()
{
	printf("Enter the size of the traversal \n");
	int size, i;
	scanf("%d",&size);
	int* pre = (int*)malloc(sizeof(int)*size);
	
	printf("Enter the preorder traversal \n");
	for(i = 0;i < size; i++)
	{
		scanf("%d",&pre[i]);
	}
	
	printTreePost(buildTreePost(pre,size));

}

int printTreePost(node* root)
{
	
	if(root == NULL)
	{
		return 1;
	}
	printTreePost(root->left);
	printTreePost(root->right);
	printf("%d ",root->data);// left right Root
	return 0;
}



node* nodePost (int pre[], int* prev,int low, int high, int size)
{
    // Base case
    if (*prev >= size || low > high)
        return NULL;
 
    // The first node in preorder traversal is root. So take the node at
    // prev from pre[] and make it root, and increment prev
    node* root = nodeInit ( pre[*prev] );
    *prev = *prev + 1;
 
    // If the current subarry has only one element, no need to recur
    if (low == high)
        return root;
 
    // Search for the first element greater than root
    int i;
    for ( i = low; i <= high; ++i )
        if ( pre[ i ] > root->data )
            break;
 
    // Use the index of element found in postorder to divide postorder array in
    // two parts. Left subtree and right subtree
    root->left = nodePost ( pre, prev, *prev, i - 1, size );
    root->right = nodePost ( pre, prev, i, high, size );
 
    return root;
}
 
// The main function to construct BST from given preorder traversal.
// This function mainly uses nodePost()
node *buildTreePost (int pre[], int size)
{
    int prev = 0;
    return nodePost (pre, &prev, 0, size - 1, size);
}
