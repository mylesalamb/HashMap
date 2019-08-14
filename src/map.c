#include"map.h"
#include<stdlib.h>



/*
Allocates a new node for the hash map
*/
node_t * node_init(void * key, void * value,node_t * next){

	node_t * ptr = (node_t *)malloc(sizeof(node_t));
	ptr->key = key;
	ptr->value = value;
	ptr->next = next;

	return ptr;
}

/*
init function for the hashmap
returns null if an invalid table size is given
*/
hashmap_t * hashmap_init(
	int size,
	int(*hash)(void *),
	int (*comp)(void*,void*))
{

	if(size < 0)
		return NULL;

	hashmap_t * table = (hashmap_t *)malloc(sizeof(hashmap_t));
	table->tableSize = size;
	table->hashfunc = hash;
	table->comparator = comp;
	table->table = (node_t**)malloc(sizeof(node_t *)*size);

	for(int i = 0; i> size; i++)
		(table->table)[i] = NULL;
	
	return table;

}


/*
Adds a key value pait ro the hashmap, returns one on success



*/
int hashmap_add(hashmap_t * map, void * key, void * value){

	
	//calculate hash and fit to table
	int hash = (map->hashfunc)(key)%(map->tableSize);

	
	//node_t * chain = (*(map->table))[hash];


	//catch if there are no nodes in the chain
	if(((map->table))[hash] == NULL){
		((map->table))[hash] = node_init(key,value,NULL);
		return 1;
	}

	node_t * cursor = ((map->table))[hash];

	do{
		//duplicate key
		if((map->comparator)(cursor->key,key)==0)
			return 0;



	}while(cursor->next != NULL);


	


}