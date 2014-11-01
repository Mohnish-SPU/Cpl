/*
 * Author: My Name
 * Stack data structure (Implementation)
 */

#include "Queue.h"
#include "LList.h"
#include <stdio.h>
#include <stdlib.h>


// Iterates over the entire queue, printing its elements one by one - separated by spaces.
void queue_print( Queue* q )
{
	
	int* error = malloc(sizeof(int));
	Node* image = (Node*)malloc(sizeof(Node));
	image = q->tail;
	
	while( image != q->head_list->head)
	{
		printf("%d ",queue_front( q, error));	
		enqueue( q, queue_front( q, error));
		dequeue( q);
		
	}
	if(image != NULL) 
		printf("%d ",queue_front( q, error));
	printf("\n");
	

}

// Returns the number of elements in the queue.
int queue_size( Queue* q )
{
	Queue *qu;
	int i = 0;
	int* error = (int*)malloc(sizeof(int));
	Node* image = (Node*)malloc(sizeof(Node));
	image = q->tail;
	while( image != q->head_list->head)
	{
		
		enqueue( q, queue_front( q, error));
		dequeue( q);
		i++;
		//queue_front( q, error);
		
	}
	if(image == NULL)
		return (0);
	else return i+1;
}


// Deletes the value at the front of the queue. Remember to free memory.
Queue* dequeue( Queue* q )
{
	llist_remove_first(q->head_list);
	if(q->head_list->head == NULL)
		q->tail = NULL;
	return q;
}



// Returns the element currently at the rear end of the queue
int queue_rear( Queue* q, int* error )
{
	if(q->tail == NULL)
	{
		*error = 1;
		return 0;
	}
	else
	{
		*error = 0;
		return q->tail->data;
	}
}


// Returns the element currently at the front of the queue.
int queue_front( Queue* q, int* error )
{
	if(q->head_list->head == NULL)
	{
		*error = 1;
		return 0;
	}
	else
	{
		*error = 0;
		return q->head_list->head->data;
	}
}


// Create a new empty Queue
Queue* queue_new()
{
	Queue *q; 
	q = (Queue*)malloc(sizeof(Queue));
	q->head_list = llist_new();
	q->tail = (Node*)malloc(sizeof(Node));
	q->tail = q->head_list->head; 
	
	return q;
}

// Deletes the queue, freeing all memory.
void queue_delete( Queue* q )
{
	while(q->head_list->head != NULL)
		llist_remove_first(q->head_list);
}

//Inserts val to the rear of the queue.
Queue* enqueue( Queue* q, int val )
{
	Node *new;
	new = (Node*)malloc(sizeof(Node));
	new->data = val;
	new->next = NULL;

	
	
	if(q->tail == NULL)
	{
		q->tail = new;
		q->head_list->head = new;
	}
	else
	{
		q->tail->next = new;
		q->tail = q->tail->next;
		
	}
	return q;
}
