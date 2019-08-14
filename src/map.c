#include"map.h"

#include<stdlib.h>


/*
init function for the hashmap
returns null if an invalid table size is given
*/
hashmap_t * hashmap_init(int size,int(*hash)(void *),int (*comp)(void*,void*)){

	if(size < 0)
		return NULL;


	hashmap_t * table = (hashmap_t *)malloc(sizeof(hashmap_t));
	table->tableSize = size;
	table->hashfunc = hash;
	table->comparator = comp;


	return table;

}