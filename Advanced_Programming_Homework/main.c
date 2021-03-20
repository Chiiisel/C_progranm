#include <stdio.h>
#include <stdlib.h>

// #include "DynamicList.h"
// #include "StaticList.h"
#include "DynamicList.c"
#include "StaticList.c"

void main()
{
    struct DynamicList *list;
    list = create_DynamicList(10);

    for (int i = 0; i < 10; i++)
    {
        /* code */
        list = insert_DynamicList(list,i,'A'+i);
    }
    printf("%s\r\n",list);
    
    free(list);

    struct list *pp;
    pp = create_StaticList(10);

    for (int i = 0; i < 10; i++)
    {
        /* code */
        pp = insert_StaticList(pp,i,'A'+i);
    }
    printf("%s",pp);
    
    free(pp);

}