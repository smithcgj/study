#include <stdio.h>
#include<malloc.h>
#define MaxSize 5
typedef char ElemType;
typedef struct qnode
{
    ElemType data;
    struct qnode *next;
}QNode;
typedef struct
{
    QNode *front;
    QNode *rear;
}LiQueue;
extern void InitQueue(LiQueue * &q);
extern void DestroyQueue(LiQueue * &q);
extern bool QueueEmpty(LiQueue * q);
extern void enQueue(LiQueue * &q,ElemType e);
extern bool deQueue(LiQueue * &q,ElemType &e);
int main()
{
    ElemType e;
    LiQueue *q;
    printf("���������������:\n");
    printf(" (1)��ʼ������q\n");
    InitQueue(q);
    printf(" (2)���ν�����Ԫ��a,b,c\n");
    enQueue(q,'a');
    enQueue(q,'b');
    enQueue(q,'c');
    printf("(3)����Ϊ%s\n",(QueueEmpty(q)?"��":"�ǿ�"));
    if(deQueue(q,e)==0)
        printf("\t��ʾ���ӿգ����ܳ���\n");
    else
        printf(" (4)����һ��Ԫ��%c\n",e);
    printf(" (5)���ν�����Ԫ��d,e,f\n");
    enQueue(q,'d');
    enQueue(q,'e');
    enQueue(q,'f');
    printf(" (6)����������:");
    while(!QueueEmpty(q))
    {
        deQueue(q,e);
        printf("%c",e);
    }
    printf("\n");
    printf(" (7)�ͷ�����\n");
    DestroyQueue(q);
    return 0;
}
