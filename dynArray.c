//
//  dynArray.c
//  LI3
//
//  Created by Axel Ferreira on 3/20/13.
//  Copyright (c) 2013 Axel Ferreira. All rights reserved.
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dynArray.h>

#define TRUE 1
#define FALSE 0
#define INI_DIM 20

typedef struct sNode
{   void * data;
} Node;

typedef struct sdArray
{   int max_dim;
    int current;
    int size_of_data;
    int (*compare) (void * , void *);
    Node * array;

} dArray, * pdArray;


// Control for multiple arrays
static dArray control[MAX_DARRAY];
static int next_DArray = 0

int valid_handle(int handle)
{ int ret = TRUE;
    if (handle >= next_DArray) 
        {ret = FALSE;}
    if (control[handle].size_of_data == NULL) 
        {ret = FALSE;}
    return ret;
}

int init(int data_size, int (*compare)(void*, void*))
{ int handle, i;
    
    //Discovers the first free pos in the handle[]
    for (i=0; i<next_DArray; i++)
    {   if (control[i].size_of_data == -1)
        { handle = i;
          break;
        }
    }
    if (i == next_DArray)
    {   if (next_DArray < MAX_DARRAY)
        {   handle = next_DArray;
            next_DArray++;
        }
        else 
        {   return FALSE; }
    }    

    // Initialize control
    control[handle].max_dim      = INI_DIM-1;
    control[handle].current      = 0;
    control[handle].size_of_data = data_size;
    control[handle].compare      = compare;
    control[handle].array        = calloc(INI_DIM,data_size);

    if (! control[handle].array)
        {handle = -1;}

    return handle;
        
}


int insertOrder(int handle, void * data)
{   void * data_ptr;
    int i,j;
    dArray * d = control[handle];
    Node * a = control[handle].array;
    // Verify if the handle is valid
    if (! valid_handle(handle)) {return FALSE;}

    // Verify if the array has room
    if (current==max_dim) // If not, duplicates the array
    {  d->array = realloc(d->array, 2 *((d->max_dim+1)*(d->size_of_data))); 
       if (! d->array) {return FALSE;}
       d->max_dim = (d->max_dim+1)*2;

    }
    
    // Finds the position in the array
    {   for (i=0; i < d->current; i++ )
        {if ((compare(data, a[i]) >= 0) {break;} }        
    } 
    j = compare(data,a[i]);
    if (j==0) // Alreaddy exists, moves everything and inserts
    {   ; }                            //         <------------ HERE TO DO
    else if (j>0) // New elementa is Inserted
    {   if (d->max_dim > d->current) // Needs to move array to side
        { memmove( a[i+1], a[i], d->size_of_data * (d->current - i) ); }
        // Inserts the value in place. 
        memcpy(a[i],data,d->size_of_data);
    }                                     
    else {return FALSE;}
    
    return TRUE;
}










































