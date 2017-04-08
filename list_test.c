#include <stdio.h>

#define MaxSize 100
typedef int DataType;

//#define X_DEBUG 1

#include "./codes/SeqList.h"


int main(int argc, char *argv[])
{
    SeqList list;

    int i, x;

    ListInitiate(&list);

    for(i=0; i<10; i++)
    {
        ListInsert(&list, i, i+1);
    }

    for(i=0; i<ListLength(list); i++)
    {
        ListGet(list, i, &x);
        printf("%d  ", x);
    }

    //ListGet(list, 11, &x);
    printf("\n len:%d ", ListLength(list));

    printf("\n");

    return 0;
}