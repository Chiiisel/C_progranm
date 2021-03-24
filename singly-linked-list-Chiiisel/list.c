#include <stdio.h>
#include <malloc.h>
#include <assert.h>

#include "list.h"


struct singly_linked_list *init_list( struct singly_linked_list *t )
{
	t->head = NULL;
	t->tail = NULL;
	t->counter = 0;

	return t;
}


struct singly_linked_list *create_list()
{
    struct singly_linked_list *t = (struct singly_linked_list *)malloc( sizeof(struct singly_linked_list) );

	return init_list( t );
}

struct node *create_node( T e )
{
    struct node *p = (struct node *)malloc( sizeof(struct node) );

    p->data = e;
    p->next = NULL;

    return p;
}

struct singly_linked_list *add_head( struct singly_linked_list *t, T e )
{
	struct node *p = create_node( e );

	if( t->counter == 0 ) {
		t->head = t->tail = p;
		t->counter ++;
	} else {
		p->next = t->head;
		t->head = p;

		t->counter ++;
	}

	return t;
}

struct singly_linked_list *add_tail( struct singly_linked_list *t, T e )
{
	struct node *p = create_node(e);

	if( t->counter == 0 ) {
		t->head = t->tail = p;
		t->counter ++;
	} else {
		t->tail->next = p;
		t->tail = p;

		t->counter ++;
	}

	return t;
}

struct node *get( struct singly_linked_list *t, int i )	//获取指定位置的node
{
	struct node *p;
	int j;

	assert( t->counter > 0 );
	assert( i>=0 && i<t->counter);


	for( j=0, p=t->head; j<t->counter; j++, p=p->next ) {
		if( j == i ) return p;
	}

	return NULL;
}

struct singly_linked_list *insert( struct singly_linked_list *t, int i, T e )
{
	struct node *p, *prev_node, *next_node;

	if( i == 0 ) return add_head( t, e );
	else if( i == t->counter ) return add_tail( t, e );

	assert( i > 0 && i < t->counter );

	prev_node = get( t, i-1 );
	assert( prev_node != NULL );

	next_node = prev_node->next;

	p = create_node( e );

	prev_node->next = p;
	p->next = next_node;

	t->counter ++;

	return t;
}

struct singly_linked_list *remove_head( struct singly_linked_list *t )
{
	struct node *p;

	assert( t->counter > 0 );

	if( t->counter == 1 ) {
		free( t->head );
		t->head = t->tail = NULL;
		t->counter --;
	} else {
		p = t->head->next;
		free( t->head );
		t->head = p;
		t->counter --;
	}

	return t;
}

struct singly_linked_list *delete_at( struct singly_linked_list *t, int i )
{
	struct node *prev_node, *cur_node;

	assert( t->counter > 0 );
	if( i == 0 ) {
		return remove_head( t );
	} else {
		prev_node = get( t, i-1 );
		assert( prev_node != NULL );

		cur_node = prev_node->next;
		prev_node->next = cur_node->next;

		if( cur_node == t->tail ) t->tail = prev_node;

		t->counter --;

		free( cur_node );

		return t;
	}
}

int size( struct singly_linked_list *t )
{
	return t->counter;
}

T get_ele( struct singly_linked_list *t, int i )	//获取指定位置的元素
{
	struct node *p;
	p = get( t, i);
	return p->data;
}

void replace( struct singly_linked_list *t, int i, T e )
{
	struct node *p;
	p = get( t, i);
	p->data = e;
}

int index( struct singly_linked_list *t, T e )
{
	struct node *p;
	int j;

	assert( t->counter > 0 );

	for( j=0, p=t->head; j<t->counter; j++, p=p->next ) {
		if( p->data == e ) return j;
	}

	return NULL;
}
