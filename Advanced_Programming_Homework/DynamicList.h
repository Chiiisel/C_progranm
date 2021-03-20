#pragma once
#include <stdio.h>
#include <assert.h>

struct DynamicList {
	char *ele;
	int count;
	int capacity; 
};

struct DynamicList *create_DynamicList( int init_cap );
struct DynamicList *insert_DynamicList( struct DynamicList *l, int i, char e );
struct DynamicList *delete_DynamicList( struct DynamicList *l, int i );

