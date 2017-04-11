#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100
typedef int DataType;

//#define X_DEBUG 1

#include "./codes/LinkList.h"


int main(int argc, char * argv[])
{
    SLNode *head, *p;

    int i, ret ,x;

    ListInitiate(&head);

    //printf("h: %p \n", head);

    for(i=0; i<8; i++)
    {
        ListInsert(head, i, i+1);
    }



    for(i=0; i<10; i++)
    {
        ret = ListGet(head, i, &x);
        printf("get: %d -> %d ,r:%d \n", i, x, ret);
        x = -1;
        ret = -1;
    }

    printf("\n");
    i = ListInsert(head, 0, 30);
    printf(" ins:%d \n", i);


   for(i=0; i<10; i++)
    {
        ret = ListGet(head, i, &x);
        printf("get: %d -> %d ,r:%d \n", i, x, ret);
        x = -1;
        ret = -1;
    }


    ListDelete(head, 5, &x);
    printf("del: %d, %d \n", 7, x);

    x = ListLength(head);
    printf("len: %d \n", x);

    for(i=0; i<10; i++)
    {
        ret = ListGet(head, i, &x);
        printf("get: %d -> %d ,r:%d \n", i, x, ret);
        x = -1;
        ret = -1;
    }

    printf("\n");

    return 0;
}