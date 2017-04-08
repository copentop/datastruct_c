#include <stdio.h>

#define MaxSize 100

typedef struct Student
{
    long number; // 学号
    char name[10]; // 名字
    char sex[3];    // 性别
    int age;    // 年龄
} StudentType;

typedef StudentType DataType;

#define X_DEBUG 1

#include "./codes/SeqList.h"


int main(int argc, char * argv[])
{
    SeqList list;
    int i;
    StudentType s;

    StudentType x[3] = {
        {200001, "张三", "男", 20},
        {200002, "李四", "男", 21},
        {200003, "小五", "女", 19}
    };


    ListInitiate(&list);
    ListInsert(&list, 0, x[0]);
    ListInsert(&list, 1, x[1]);
    ListInsert(&list, 2, x[2]);

    ListDelete(&list, 0, &s);

    printf("%d \n", ListLength(list));

    //s = null;

    for(i=0; i <ListLength(list); i++)
    {
        ListGet(list, i, &s);
        printf("%d  %s  %s %d \n", s.number, s.name, s.sex, s.age);
    }

    return 0;
}