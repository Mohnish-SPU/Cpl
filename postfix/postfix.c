/*
 * Author: My Name
 * Postfix Expression Evaluator
 */

#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int evaluate_postfix( char* expr );


int main( int argc, char* argv[] )
{
	char expr[1024];
	fgets( expr, 1024, stdin);
	//Getting the whole string with spaces 
	
	int result;
	
	result = evaluate_postfix( expr);
	
	
	//printf("%d \n",result);//Commented out to satisfy tests
    return 0;
}

int evaluate_postfix( char* expr )
{
	Stack *pull, *st;
	pull = stack_new();
	st = stack_new();
	
	char* read;
	int *error,*error1,*error2;
	int final;
	error = (int*)malloc(sizeof(int));//These are flags used susequently in the prg
	error1 = (int*)malloc(sizeof(int));
	error2 = (int*)malloc(sizeof(int));
	*error1 = 0;
	*error2 = 0;
	*error = 0;
	int prev1, prev2, prev3;
	//Using the tokenizer as a sort of pop
	read = strtok(expr, " ");
	prev1 = atoi(read);
	stack_push( st, prev1);//REAd 1st operand
	stack_print(st);
	
	read = strtok(NULL, " ");
	prev2 = atoi(read);//Read 2nd operand
	stack_push( st, prev2);
	stack_print(st);
	
	read = strtok(NULL, " ");
	while(read != NULL && read[0]!= '\n')//Might return NULL or newline at end strtok
	{	
		
		prev2 = stack_top( st, error2);
		stack_pop( st);
		prev1 = stack_top( st, error1);
		stack_pop( st);
		
		if(strcmp(read,"+") == 0) //Used string comp to remove ambiguity
		{
			final = prev1+prev2;
			stack_push( st, final);
			stack_print( st);
		}
		else if(strcmp(read,"-") == 0)
		{
			final = prev1-prev2;
			stack_push( st, final);
			stack_print(st);
		}
		else if(strcmp(read,"*") == 0)
		{
			final = prev1*prev2;
			stack_push( st, final);
			stack_print(st);
		}
		else if(strcmp(read,"/") == 0)
		{
			final = prev1/prev2;
			stack_push( st, final);
			stack_print(st);
		}
		else//Update Stack
		{	
			if(*error1 == 0)
				stack_push( st, prev1);
			if(*error2 == 0)
				stack_push( st, prev2);
			
			prev3 = atoi(read);
			
			stack_push( st, prev3);
			stack_print(st);
		}
		
		read = strtok(NULL, " ");		
	}
	return stack_top( st, error);	
}


