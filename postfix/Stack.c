/*
 * Author: My Name
 * Stack data structure (Implementation)
 */

#include "Stack.h"
#include "LList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//REverses a stack
Stack* stack_rev( Stack *st)
{
	LList *copy;
	copy = llist_new();
	int *error = (int*)malloc(sizeof(int));
	*error = 1;
	
	stack_top( st, error);
	while(*error == 0)
	{
		llist_prepend(copy,stack_top( st, error));
		stack_pop( st);
		stack_top( st, error);
	}
	st->body = copy;	
	return st;
}

// Prints the elements currently in the stack
void stack_print(Stack* st )
{
	st = stack_rev( st);
	LList *copy;
	copy = llist_new();
	int *error = (int*)malloc(sizeof(int));
	*error = 1;
	
	stack_top( st, error);
	while(*error == 0)
	{
		printf("%d ",stack_top( st, error));
		llist_prepend(copy,stack_top( st, error));
		stack_pop( st);
		stack_top( st, error);
	}
	st->body = copy;
	
	printf("\n");
}

// Returns the number of elements in the stack
int stack_size( Stack* st )
{
	
	LList *copy;
	int *error = (int*)malloc(sizeof(int));
	*error = 1;
	copy = llist_new();
	int i = 0;
	stack_top( st, error);
	while (*error == 0)
	{
		i++;
		llist_append( copy, stack_top( st, error));
		stack_pop( st);
		stack_top( st, error);
			
	}
	st->body = copy;
	return (i);
}

// Returns the element currently at the top of the stack. If the stack is empty,
// @error should be set to 1, else 0.
int stack_top( Stack* st, int* error )
{
	int top_value;
	if( st->body->head == NULL)
	{
		*error = 1;
		return 0;
	}
	else
	{
		top_value = llist_get( st->body, 0);
		*error = 0;
		return top_value;
	}
}

// Remove the element at the top of the stack - also frees memory
Stack* stack_pop( Stack* st )
{
	llist_remove_first(st->body);
	return st;
}

// Inserts @val to the top of the stack
Stack* stack_push( Stack* st, int val )
{
	llist_prepend( st->body, val);
	
	return st;
}

// Deletes the stack, frees memory.
void stack_delete( Stack* st )
{
	while(st->body->head != NULL)
	{
		llist_remove_first(st->body);
	}
}

// Create a new empty stack
Stack* stack_new()
{
	Stack* stack;
	stack = (Stack*)malloc(sizeof(Stack));
	
	stack->body = llist_new();
	return stack;
}

