#include <stdio.h>
#include <malloc.h>
#include <assert.h>

#include "list.h"

struct list *create_list()
{
    struct list *l=(struct list*)malloc( sizeof(struct list) );
    l->counter = 0;
    return l;
    
    /* ele */
};

struct list *insert_list( struct list *l, int i, char e ) {	
	int j;

    if( l->counter == MAX_ELE ) return NULL;
	assert( i >= 0 && i <= l->counter );

	for( j=l->counter; j>i; j-- ) {
		l->ele[j] = l->ele[j-1];
	}

	l->counter ++;
	
	l->ele[i] = e;
	
	return l;
}

struct list *delete_list( struct list *l, int i )
{
	int j;

	assert( i>=0 && i <l->counter );

	for( j=i; j<l->counter-1; j++ ) {
		l->ele[j] = l->ele[j+1];
	}

	l->counter --;

	return l;
}


int size( struct list *l )
{
    return l->counter+1;
}

T get( struct list *l, int i )
{
    int j;
	assert( i >= 0 && i <= l->counter );
    return l->ele[i];
}

void replace( struct list *l, int i, T e )
{
	assert( i >= 0 && i <= l->counter );

	l->ele[i] = e;
    return 0;
}

int index( struct list *l, T e )
{
    int j;
	for( j=l->counter; j>0; j-- ) {
        if(l->ele[j] = e)
        return j;	
	}
}

