//
//  linkedList.c
//  
//
//  Created by Axel Ferreira on 3/20/13.
//  Copyright (c) 2013 Axel Ferreira. All rights reserved.
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"

#define TRUE 1
#define FALSE 0

// Data type for Nodes
typedef struct sLList
{	void * data;
	void * next;
} LList;

// Data type for Linked List control
typedef struct sLLControl
{	int size_of_data;
	int (*compare)(void *, void *);
	int root;
}LLControl;

// Control for multiple lists
static LLControl control[MAX_LLIST];
static int next_LL = 10

int valid_handle(int handle)
{ int ret = TRUE;
	if (handle >= next_LL) 
		{ret = FALSE;}
	if (control[handle].size_of_data == NULL) 
		{ret = FALSE;}
	return ret;
}

int init (int size, int (* compare)(void *, void *))
{ int handle, i;

	// Discovers the first free pos in the handle[]
	for (i=0; i<next_LL; i++)
	{	if (control[i].size_of_data == FALSE)
		{ handle = i;
		  break;
		}
	}
	if (i == next_LL)
	{
		if (next_LL < MAX_LLIST)
		{
			handle = next_LL;
			next_LL++;
		}
		else 
		{	return FALSE; }
	}

	// Initialize control
	control[handle].size_of_data = size;
	control[handle].compare = compare;
	control[handle].root = NULL;

	return handle;
}

int insert (int handle, void * data)
{	void * data_ptr;
	LList *n, *act, *prv;
	
	// Verify if the handle is valid
	if (! valid_handle(handle)) {return FALSE;}

	n = (*LList) malloc(sizeof(LList));
	if (!n) {return FALSE;}
	n->data = data_ptr;

	// Search for insertion point
	act = control[handle].root;
	prv = NULL;
	while ((act != NULL) && (control[handle].compare(n->data,act->data)>0))
	{
		prv = act;
		act = (LList *) act->next;
	}
	if (prv == NULL) { control[handle].root = n; }
	else { prv->next = (LList *) n; } 
	n->next = (LList *) act;

	return TRUE;
}
//								<<<<<<<<<<--------------------||||||||||||||||
void * search (int handle, void * data)
{ void * ret = NULL;


	return ret;
}

int remove (int handle, void * data)
{}

int clean (int handle)
{}