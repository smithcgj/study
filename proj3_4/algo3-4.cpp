#include<stdio.h>
#include<malloc.h>
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
void InitQueue(LiQueue * &q)//��ʼ������
{
    q=(LiQueue *)malloc(sizeof(LiQueue));
    q->front=q->rear=NULL;
}
void DestroyQueue(LiQueue * &q)//���ٶ���
{
    QNode *p=q->front,*r;//pָ���ͷ���ݽڵ�
    if(p!=NULL)//�ͷ����ݽڵ�ռ�ÿռ�
    {
        r=p->next;
        while(r!=NULL)
        {
            free(p);
            p=r;r=p->next;
        }
    }
    free(p);
    free(q);//�ͷ����ӽڵ�ռ�ÿռ�
}
bool QueueEmpty(LiQueue *q)//�ж϶����Ƿ�Ϊ��
{
    return (q->rear==NULL);
}
void enQueue(LiQueue * &q,ElemType e)//����
{
    QNode *p;
    p=(QNode *)malloc(sizeof(QNode));
    p->data=e;
    p->next=NULL;
    if(q->rear==NULL)//������Ϊ�գ����½ڵ��Ƕ��׽ڵ����Ƕ�β�ڵ�
        q->front=q->rear=p;
    else
    {
        q->rear->next=p;//��*p�ڵ�������β������rearָ����
        q->rear=p;
    }
}
bool deQueue(LiQueue * &q,ElemType &e)//����
{
    QNode *t;
    if(q->rear==NULL)//����Ϊ��
    return false;
    t=q->front;//tָ���һ�����ݽڵ�
    if(q->front==q->rear)//����ֻ��һ���ڵ�ʱ
    q->front=q->rear=NULL;
    else
        q->front=q->front->next;
    e=t->data;
    free(t);
    return true;
}