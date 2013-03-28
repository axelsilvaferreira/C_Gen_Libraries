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
    int data_size;
    int (*compare) (void * , void *);
    Node array[INI_DIM];

} dArray, * pdArray;



void init(int data_size, int (*compare)(void*, void*))
{ //int ret = FALSE;
    
    dArray darray;
    
    darray.max_dim   = INI_DIM;
    darray.current   = 0;
    darray.data_size = data_size;
    darray.compare   = compare;
    
    //if (darray.current) {ret = TRUE;}
        
    //return ret;
}


int insert(dArray * darray, void * data)
{   int bool = FALSE;
    
    
    
    
    return bool;
}

























