#include <stdio.h>

#include "stack.h"
#include "stack.c"

int main()
{

	/* */
	struct stack *s;
	s = create_stack();

	for (int i = 0; i < 10; i++)
		s = push(s,'A'+i);

	printf("%c\r\n",top(s));

	for (int i = 0; i < 9; i++){
		printf("%c",pop(s));
	}
	printf("\r\n");

	if(is_empty(s))
		printf("stack is empty \r\n");
	else
		printf("stack is not empty\r\n");


	uninit_stack(s);
  /* other test code */

	//free(s);
}
