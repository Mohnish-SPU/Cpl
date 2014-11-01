/*
 * Author: Mohnish
 * Token System
 */
#include "BSTree.h"
#include <stdio.h>
#include <stdlib.h>


int main( int argc, char* argv[] )
{
	int token;
	
	bst* tree = treeInit();
	
	//printf("Enter Token:\n");
	scanf("%d", &token);

	//printf("Hi\n");

		//printf("New token!\n");
		insertNode(tree, token);//,prev,pos);
		printTree(tree);
		printf("\n");
	
		
	//scanf("%d", &token);//Parsing for EOF to run test cases
	while(scanf("%d", &token) != -1)//(token != -1)
	{
		
		
		if((node*)findNode(tree, token) == NULL)
		{
		//	printf("New token!\n");
			insertNode(tree, token);//, prev1, pos);
		}
		else
		{
			//printf("Old Token!\n");
			deletion(tree, token);
		}
		//printf("Current list is: ");
			if(tree->root != NULL)
				printTree(tree);
		printf("\n");			
		
		//printf("Enter Token:\n");
		//scanf("%d", &token);
	}
	
	//printf("Final list is: ");
	//printTree(tree);
	//printf("\n");		
	
    return 0;
}

