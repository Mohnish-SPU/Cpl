
#include "BSTree.h"
#include <stdio.h>
#include <stdlib.h>

main()
{
	printf("Enter the size of the traversals \n");
	int size, i;
	scanf("%d",&size);
	
	int* inOrder = (int*)malloc(sizeof(int)*size);
	int* postOrder = (int*)malloc(sizeof(int)*size);
	
	printf("Enter the Inorder traversal \n");
	for(i = 0;i < size; i++)
	{
		scanf("%d",&inOrder[i]);
	}
	

	printf("Enter the Postorder traversal \n");
	for(i = 0;i < size; i++)
	{
		scanf("%d",&postOrder[i]);
	}

	printPre( inOrder, postOrder,0, size-1, 0, size-1); // W/o making a tree
	printf("\n");

	bst* tree = treeBuild(inOrder, postOrder, size);//Constructs a ree
	//printTree(tree);
	printTreePre(tree->root);//Prints the tree in the preorder notation
	printf("\n");
	//For 2 a,b answer is yes we can directly get the inorder by sorting
	//And get a unique tree
}

