/*
Reference implementation for a generic HashMap in c
Author: Myles Lamb
*/

#ifndef MAP_GUARD
#define MAP_GUARD
#include<stdlib.h>

typedef struct Node{

	void * key;
	void * value;
	struct Node * next;

} node_t;





typedef struct HashMap
{

	int (*hashfunc)(void *);
	int (*comparator)(void *,void *);
	size_t tableSize;
	node_t * table[];
	
}hashmap_t;

hashmap_t * hashmap_init(int size,int(*hash)(void *),int (*comp)(void*,void*));
int hashmap_add(hashmap_t table, void * key, void * value);
int hashmap_remove(hashmap_t, void * key);
void hashmap_free(hashmap_t table);


#endif