#include <stdio.h>

#include "list.h"
void main()
{
	/* */
	struct list *l;
	l = create_list();

	for (int i = 0; i < 10; i++)
		l = insert(l, i, 'A'+i);
	
	l = delete_at(l, 4);
	
/* other test code */
	int the_size=0;
	the_size = size(l);

	T test;
	test = get( l, 'B');

	replace( l, 1, 'Z' );

	int the_index=0;
	the_index = index( l, 'Z' );

	free(l);
}
