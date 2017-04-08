/*
 * 顺序表
 *
 * 依赖
 * DataType 具体化，以及MaxSize的定义,
 * 其中，X_DEBUG 为调试信息
 *
 */

// typedef struct seqlist SeqList;

 typedef struct seqlist
 {
     DataType list[MaxSize];
     int size;
 } SeqList;


 /*
  * 初始化顺序表L
  *
  */
void ListInitiate(SeqList *L)
{
    L->size = 0;
}

/*
 * 当前顺序表的数据元素的个数
 *
 */
int ListLength(SeqList L)
{
    return L.size;
}

/*
 * 插入数据元素
 * 在第i（i>=0 & i<=size) 个位置前插入数据元素x
 * 成功返回1，失败返回0
 *
 */
int ListInsert(SeqList *L, int i, DataType x)
{
    if(L->size >= MaxSize)
    {
#ifdef X_DEBUG
    printf("顺序表已满，不能插入\n");
#endif
        return 0;
    }

    if(i<0 || i>L->size)
    {
#ifdef X_DEBUG
    printf("参数i不合法\n");
#endif
        return 0;
    }

    int k;
    for(k = L->size; k > i; k--)
    {
        L->list[k] = L->list[k-1];
    }

    L->list[k] = x;
    L->size += 1;

    return 1;

}

/*
 * 删除元素
 *
 */
 int ListDelete(SeqList *L, int i, DataType *x)
 {
     if(L->size == 0)
     {
#ifdef X_DEBUG
    printf("顺序表为空，不能删除\n");
#endif
        return 0;
     }

     if(i<0 || i>=L->size)
     {
#ifdef X_DEBUG
    printf("参数i不合法\n");
#endif
        return 0;
     }

     *x = L->list[i];
     int k;
     for(k = i; k < L->size - 1; k++)
     {
         L->list[k-i] = L->list[k];
     }

     L->size -= 1;

     return 1;
 }

 /*
  * 获取数据元素
  *
  */
int ListGet(SeqList L, int i, DataType *x)
{
    if(i<0 || i>L.size -1)
    {
#ifdef X_DEBUG
    printf("参数不合法\n");
#endif
        return 0;
    }

    *x = L.list[i];

    return 1;
}