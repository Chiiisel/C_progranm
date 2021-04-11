#include<stdio.h>
#include <malloc.h>
#include <assert.h>
#include <stdbool.h>

#include "stack.h"

//typedef enum { false, true } bool;

struct stack *init_stack(struct stack *t)
{
	t->count = 0;

	return t;
}

struct stack *create_stack()
{
	struct stack *t;

	t = (struct stack *)malloc(sizeof(struct stack));

	return init_stack(t);
}


struct stack *push(struct stack *t, T e)
{

	assert(t->count <= MAX_ELE);

	t->store[t->count] = e;
	t->count++;

	return t;
}

T pop(struct stack *t)
{
	T e;
	assert(t->count > 0);
	e = t->store[t->count - 1];
	t->count--;

	return e;
}

bool is_empty(struct stack *t)
{
	return t->count == 0 ? true : false;
}

T top(struct stack *t)
{
	assert(t->count > 0);
	return t->store[t->count - 1];
}

void uninit_stack(struct stack *t)
{
	free(t->store);
}
