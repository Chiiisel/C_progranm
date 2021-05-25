#include <stdio.h>
#include <assert.h>

#include "queue.h"
#include "queue.c"


void destroy_list(struct queue *q)
{
	free(q);
}

void TestEnter()
{
	struct queue *q;
	q = init_queue(q);

	for (int i = 0; i < 10; i++) {
		q = enter(q, 'A' + i);
	}

	for (int i = 0; i < 10; i++) {
		assert(q->store[i] == 'A' + i);
	}

	destroy_list(q);
}

void TestLeave()
{
	struct queue *q;
	q = init_queue(q);

	for (int i = 0; i < 10; i++) {
		q = enter(q, 'A' + i);
	}

	printf("TestLeave: %c\r\n", leave(q) );

	for (int i = 0; i < 4; i++) {
		assert((q->store[i+ q->front_index]) == 'B' + i);
	}
}
int main()
{
	/* */
	TestEnter();
	TestLeave();


	struct queue *q;
	q = init_queue(q);
	for (int i = 0; i < 10; i++) {
		q = enter(q, 'A' + i);
	}

	for (int i = 0; i < 10; i++) {
		printf("%c", leave(q) );
	}

	if(is_empty(q))
	{
		printf("\r\nis empty\r\n");
	}
	else
	{
		printf("\r\nis not empty\r\n");
	}
  	/* other test code */

}
