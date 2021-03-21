#include <stdio.h>
#include <malloc.h>
#include "DynamicList.h"

struct list *create_list( int init_cap )
{
    struct list *l = (struct list *)malloc( sizeof(struct list) );
	
	if( init_cap <= 0 ) init_cap = 10;
	l->ele = (char *)malloc( init_cap * sizeof(char) );

	l->capacity = init_cap;
    l->count = 0; 
    return l;	
}

struct list *insert_DynamicList( struct list *l, int i, char e ) {	
    int j;

    if( l->count == l->capacity ) {
        int new_cap = l->capacity * 2;

        char * new_ele = (char *)malloc( sizeof(char) * new_cap );

        for( j=0; j<l->count; j++ ) {
            new_ele[j] = l->ele[j];
        }

        l->capacity = new_cap;

        free( l->ele );

        l->ele = new_ele;
    }
	assert( i >= 0 && i <= l->count );

    for( j=l->count; j>i; j-- ) {
        l->ele[j] = l->ele[j-1];
    }

    l->count ++;
	
    l->ele[i] = e;
	
    return l;
}
struct list *delete_DynamicList( struct list *l, int i )
{
	int j;

	assert( i>=0 && i <l->count );

	for( j=i; j<l->count-1; j++ ) {
		l->ele[j] = l->ele[j+1];
	}

	l->count --;

	return l;
}

