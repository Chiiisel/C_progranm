#pragma once

#include <stdio.h>
#include <assert.h>

#define MAX_LEN 1024
struct list
{
    char    data[MAX_LEN];
    int     count;
    /* data */
};

struct list *create_StaticList();
struct list *insert_StaticList( struct list *list, int i, char e );
struct list *delete_StaticList( struct list *list, int i );

