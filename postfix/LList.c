#include <stdio.h>
#include <stdlib.h>
#include "LList.h"


//Removes all zero elements
LList* p_clean(LList *pHead)
{
	LList *clean;
	clean = llist_new();
	Node *cursor;
	int i = 0;
	cursor = (Node*)malloc(sizeof(Node));
	cursor = pHead->head;
	while(cursor != NULL)
	{
			
		if((cursor->data)/1000 != 0)
		{
			llist_append(clean, cursor->data);
			
		}
		
		cursor = cursor->next;
	
	}
	if(clean->head == NULL) llist_append(clean, 0);//When nothing but zero is left something must be there nah
	
	return clean;
		
}

// Remove an element from @idx position
LList* llist_remove(LList* lst, int idx)
{
	if(lst->head == NULL) return lst;
	Node *cursor, *ghost;
	cursor = (Node*)malloc(sizeof(Node));
	ghost = (Node*)malloc(sizeof(Node));
	int i = 0;
	
	if(idx == 0)
	{
		lst = llist_remove_first(lst);
	}
	else
	{
		cursor = lst->head;
		while(i<idx)
		{
			ghost  = cursor;
			cursor = cursor->next;
			i++;
		}
		ghost->next = cursor->next;
		free(cursor);
		
	}
	return lst;
}

// Remove an element from the beginning of the list
LList* llist_remove_first(LList* lst)
{
	if(lst->head == NULL) return lst;
	Node *temp;
	temp = (Node*)malloc(sizeof(Node));
	
	temp = lst->head;
	lst->head = lst->head->next;
	free(temp);	
	
	return lst;
}

// Remove an element from the end of the list
LList* llist_remove_last(LList* lst)
{
	if(lst->head == NULL) return lst;
	Node *cursor, *ghost;
	cursor = (Node*)malloc(sizeof(Node));
	ghost = (Node*)malloc(sizeof(Node));
	
	cursor = lst->head;
	if(cursor->next == NULL)
	{
		free(cursor);
		lst->head = NULL;
	}
	else
	{
		while(cursor->next != NULL)
		{
			ghost = cursor;
			cursor = cursor->next;
		}
		ghost->next = NULL;
		free(cursor);
	}
	return lst;
}	


// Adds a new element at the idx index
LList* llist_insert(LList* lst, int idx, int data)
{
	Node *new, *temp, *cursor;
	int i = 0;
	temp = (Node*)malloc(sizeof(Node));
	cursor = (Node*)malloc(sizeof(Node));
	new = (Node*)malloc(sizeof(Node));
	
	new->data = data;
	cursor = lst->head;
	if(idx == 0)
	{
		lst = llist_prepend(lst, data);
	}
	else
	{
		while(i<(idx-1))
		{
			i++;
			cursor = cursor->next;
		}
	
		new->next = cursor->next;
		cursor->next = new;
	}
	return lst;
}

// Adds a new element at the beginning of the list
LList* llist_prepend(LList* lst, int data)
{
	Node *new;
	new = (Node*)malloc(sizeof(Node));
	
	new->data = data;
	new->next = lst->head;
	
	lst->head = new;
	
	return lst;
}


// Add a new element at the end of the list
LList* llist_append(LList* lst, int data)
{
	Node *cursor, *new, *ghost;
	cursor = (Node*)malloc(sizeof(Node));
	ghost = (Node*)malloc(sizeof(Node));
	new = (Node*)malloc(sizeof(Node));
	new->data = data;
	new->next = NULL;

	
	cursor = lst->head;
	if(cursor == NULL)
	{
		lst->head = new;
	}
	else
	{
		while(cursor != NULL)
			{
				ghost = cursor;
				cursor = cursor->next;
			}
	
;
		ghost->next = new;
	}
	return lst;
	
}

// Gets the "idx"th element of the list
int llist_get(LList* lst, int idx)
{
	int i = 0,data;   //make i<idx i<=idx if index starts from 1
	Node *cursor;
	cursor = (Node*)malloc(sizeof(Node));
	cursor = lst->head;
	while(i<idx )
	{
		cursor = cursor->next;
		i++;
	}
	

	data = cursor->data;
	
	return data;
}

// Traverse the linked list and print each element
void llist_print(LList* lst)
{
	Node *cursor;
	cursor = (Node*)malloc(sizeof(Node));
	
	cursor = lst->head;
	
	while(cursor != NULL)
	{
		printf("%d ", cursor->data);
		cursor = cursor->next;
	}
	printf("\n");
}

// Traverse the linked list and return the 

int llist_size(LList* lst)
{
	
	Node *cursor;
	cursor = (Node*)malloc(sizeof(Node));
	
	cursor = lst->head;
	
	int i=0;
	while(cursor != NULL)
	{
		i++;
		cursor=cursor->next;
	}
	return i;
	
}

// Creates a new node with data and next element
Node* node_new(int data, Node* next)
{
	Node *new_node;
	new_node = (Node*)malloc(sizeof(Node));
	
	new_node->data = data;
	new_node->next = next;
	return new_node;
}
// Creates an empty list with head as null 
LList* llist_new()
{
	LList *new;
	new = (LList*)malloc(sizeof(LList));
	new->head = NULL;
	return new;
}

