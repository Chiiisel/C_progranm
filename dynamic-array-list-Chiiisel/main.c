#include <stdio.h>

#include "list.h"
#include "list.c"
int main()
{
	/* */
	struct list *l;
	l = create_list(10);

	for (int i = 0; i < 10; i++)
		l = insert(l, i, 'A'+i);
	printf("struct list = %s\r\n",l->ele);

	l = delete_at(l, 4);
	printf("deleted list = %s\r\n",l->ele);
/* other test code */
	int the_size=0;
	the_size = size(l);

	T test;
	test = get( l, 2);
	printf("function get(l,2) = %c\r\n",test);

	replace( l, 1, 'Z' );
	printf("function replace(l,1,'Z') = %s\r\n",l->ele);

	int the_index=0;
	the_index = index( l, 'Z' );
	printf("the_size = %d\r\nthe_index of 'Z'= %d",the_size,the_index);
	free(l);
}
