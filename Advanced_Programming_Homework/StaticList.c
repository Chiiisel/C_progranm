#include <stdio.h>
#include <malloc.h>
#include "StaticList.h"

struct list *create_StaticList()
{
    struct list *plist=(struct list*)malloc( sizeof(struct list) );
    plist->count = 0;
    return plist;
    
    /* data */
};

struct list *insert_StaticList( struct list *plist, int i, char e ) {	
	int j;

    if( plist->count == MAX_LEN ) return NULL;
	assert( i >= 0 && i <= plist->count );

	for( j=plist->count; j>i; j-- ) {
		plist->data[j] = plist->data[j-1];
	}

	plist->count ++;
	
	plist->data[i] = e;
	
	return plist;
}
struct list *delete_StaticList( struct list *plist, int i )
{
	int j;

	assert( i>=0 && i <plist->count );

	for( j=i; j<plist->count-1; j++ ) {
		plist->data[j] = plist->data[j+1];
	}

	plist->count --;

	return plist;
}

