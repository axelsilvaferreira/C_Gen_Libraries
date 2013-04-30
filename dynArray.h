//
//  dynArray.h
//  
//
//  Created by Axel Ferreira on 3/20/13.
//  Copyright (c) 2013 Axel Ferreira. All rights reserved.
//

#ifndef dynAarray_h
#define dynArray_h


#define TRUE 1
#define FALSE 0

#define MAX_DARRAY 101 	// maximum number of dynamic arrays
#define INI_DIM 20 	   	// Initial capacity of the array


void init(int data_size, int (*compare)(void*, void*));

int insertOrde(dArray * darray, void * data);





#endif
