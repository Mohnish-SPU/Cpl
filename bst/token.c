/*
 * Author: Mohnish
 * Token System
 */
#include "BSTree.h"
#include <stdio.h>
#include <stdlib.h>

int main( int argc, char* argv[] )
{
  // TODO: Read a stream of integers using scanf. Stop when you see a
  //      -1
	int token;
	node** prev = (node**)malloc(sizeof(node*));
	bst* tree = treeInit();
	int* pos = (int*)malloc(sizeof(int));
	
	printf("Enter Token:\n");
	scanf("%d", &token);
	
	while(token != -1)
	{

		if((node*)findNode(&tree, token, prev, pos) == NULL)
		{
			printf("New token!\n");
			insertNode( &tree, token);
		}
		else
		{
			printf("Old Token!\n");
			removeNode(&tree,token);
		}
		printf("Current list is: ");
		printTree(tree->root);
		printf("\n");			
		
		printf("Enter Token:\n");
		scanf("%d", &token);
	}
	
	printf("Final list is: ");
	printTree(tree->root);		
	
  
  // TODO: For each token - check if the token exists in the
  //       collection. If no - add to the collection. If yes - remove.
  
  
  // TODO: Print when done

  return 0;
}

