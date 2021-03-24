#include <stdio.h>

#include "list.h"

#include "list.c"
int main()
{
	/* */
	struct doubly_linked_list *l;
	l = create_list();

	/* operations */
	for (int i = 0; i < 10; i++){
		l = insert(l, i, 'A'+i);
	}

	printf("struct list = ");
	struct node *p;
	p=l->head;
	while(p->next!=NULL){
    	printf("%c",p->data);
    	p=p->next;
    }
	printf("\r\n");

	l = delete_at(l, 4);
	printf("deleted list = %s");
	p=l->head;
	while(p->next!=NULL){
    	printf("%c",p->data);
    	p=p->next;
    }
	printf("\r\n");
/* other test code */
	int the_size=0;
	the_size = size(l);

	T test;
	test = get_ele( l, 2);
	printf("function get_ele(l,2) = %c\r\n",test);

	replace( l, 1, 'Z' );
	printf("function replace(l,1,'Z') =");
	p=l->head;
	while(p->next!=NULL){
    	printf("%c",p->data);
    	p=p->next;
    }
	printf("\r\n");

	int the_index=0;
	the_index = index( l, 'D' );
	printf("the_size = %d\r\nthe_index of 'D'= %d",the_size,the_index);
	
	/* memory deallocation */
	free(l);
	return 0;
}
