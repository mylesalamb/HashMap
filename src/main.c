#include "map.h"

int comparator(void*arg1,void*arg2);
int int_hash_func(void * arg);

int main(int argc, char const *argv[])
{
	hashmap_t * map = hashmap_init(10,&int_hash_func,&comparator);

	int * key = (int *)malloc(sizeof(int));
	int * val = (int *)malloc(sizeof(int));

	*key = 22;
	*val = 4;

	hashmap_add(map,key,val);
	hashmap_print(map);


	hashmap_free(map);
	
	return 0;
}




int comparator(void * arg1, void * arg2){
	return (*(int *)arg1) - (*(int *)arg2);
}

int int_hash_func(void * arg){
	return (*(int *)arg);

}


