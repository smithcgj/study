#include<stdio.h>
#include<malloc.h>
#define MaxSize 5
typedef char ElemType;
typedef struct
{
    ElemType data[MaxSize];
    int front,rear;//���׺Ͷ�βָ��
}SqQueue;
void InitQueue(SqQueue * &q)//��ʼ������
{
    q=(SqQueue *)malloc(sizeof(SqQueue));
    q->front=q->rear=0;
}
void DestroyQueue(SqQueue * &q)//���ٶ���
{
    free(q);
}
bool QueueEmpty(SqQueue * q)//�ж϶����Ƿ�Ϊ��
{
    return (q->front==q->rear);
}
bool enQueue(SqQueue * &q,ElemType e)//����
{
    if((q->rear+1)%MaxSize==q->front)//���������
    return false;
    q->rear=(q->rear+1)%MaxSize;
    q->data[q->rear]=e;
    return true;
}
bool deQueue(SqQueue * &q,ElemType &e)//����
{
    if(q->front==q->rear)//�ӿ������
    return false;
    q->front=(q->front+1)%MaxSize;
    e=q->data[q->front];
    return true;
}



