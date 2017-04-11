/*
 * 结点结构体
 *
 */
typedef struct SLNode
{
    DataType data;
    struct SLNode *next;
} SLNode;


/*
 * 初始化链表
 *
 */
void ListInitiate(SLNode **head) 
{
    (*head) = (SLNode *)malloc( sizeof(SLNode) );
    (*head)->next = NULL;
}


/*
 * 数据元素的个数
 *
 */
int ListLength(SLNode *head)
{
    SLNode *p;
    int len = 0;

    p = head;
    while(p->next != NULL)
    {
        p = p->next;
        len ++;
    }

    return len;
}

/*
 * 销毁链表
 *
 */
int ListDestroy(SLNode **head)
{
    SLNode *p, *q;

    p = *head;
    while(p->next != NULL)
    {
        q = p;
        p = p->next;
        free(q);
    }

    *head = NULL;

    return 1;
}


/*
 * 插入
 * 第i个结点之前(i>=0 && i<length)
 */
int ListInsert(SLNode *head, int i, DataType x)
{
    SLNode *p, *q;
    int k = -1;

    p = head;

    while(p->next != NULL)
    {
        
        if(k+1 == i)
        {
            break;
        }

        k += 1;
        p = p->next;
    }

    if( k+1 == i)
    {
        q = (SLNode *)malloc( sizeof(SLNode) );
        q->data = x;


        q->next = p->next;
        p->next = q;

        return 1;
    }
    return 0;
}

/*
 * 获取第i个元素
 *
 */
int ListGet(SLNode *head, int i, DataType *x)
{
    SLNode *p;
    int k = -1;

    if(head == NULL)
    {
        return 0;
    }

    p = head;
    while(p->next != NULL) {
        p = p->next;
        k += 1;

        if(k == i)
        {
            break;
        }
    }

    if(p != NULL && k==i) {
        *x = p->data;

        return 1;
    }
    return 0;
}

/*
 * 删除第i个元素
 *
 */
int ListDelete(SLNode *head, int i, DataType *x)
{
    SLNode *p, *q;
    int k = -1;

    p = head;
    while(p->next != NULL)
    {
        if(k+1 == i) 
        {
            break;
        }
        p = p->next;
        k += 1;
    }

    if(p != NULL && k+1 == i)
    {
        q = p->next;
        *x = q->data;

        p->next = q->next;
        free(q);

        return 1;
    }

    return 0;
}