#pragma once
#include <stdio.h>
#include <assert.h>

struct list {
	char *ele;
	int count;
	int capacity; 
};

struct list *create_list( int init_cap );
struct list *insert_DynamicList( struct list *l, int i, char e );
struct list *delete_DynamicList( struct list *l, int i );

