#include <stdio.h>
#include<malloc.h>
typedef struct qnode
{   int data;
    struct qnode *next;
}QNode;//���ӽڵ�����
typedef struct
{
    QNode *front,*rear;//��ͷ��βָ��
}QuType;//��������
void Destroyqueue(QuType *&qu)
{
    QNode *p,*q;
    p=qu->front;//�����Ӳ���
    if(p!=NULL)
    {
        q=p->next;
        while(q!=NULL)
        {
            free(p);//�ͷŶ��нڵ�
            p=q;
            q=q->next;
        }
        free(p);//�ͷ����ӽڵ�
    }
    free(qu);
}
void SeeDoctor()//ģ�ⲡ�˿�������
{
    int sel,flag=1,find,no;
    QuType *qu;
    QNode *p;
    qu=(QuType *)malloc(sizeof(QuType));
    qu->front=qu->rear=NULL;
    while(flag==1)
    {
    printf("1:�Ŷ� 2:���� 3:�鿴�Ŷ� 4:�����Ŷ�,���������Ŷ� 5:�°� ��ѡ��:");
    scanf("%d",&sel);
    switch(sel)
    {
    case 1: printf(" >>���벡���ţ�");
    do
    {
        scanf("%d",&no);
        find=0;
        p=qu->front;
        while(p!=NULL&&!find)
        {
            if(p->data==no)
                find=1;
            else
                p=p->next;
        }
        if(find)
            printf("  >>����Ĳ������ظ�����������:");

    }while(find==1);
    p=(QNode *)malloc(sizeof(QNode));
    p->data=no;p->next=NULL;
    if(qu->rear==NULL)
        qu->front=qu->rear=p;
    else
    {
        qu->rear->next=p;
        qu->rear=p;
    }
    break;
    case 2:if(qu->front==NULL)
    printf("  >>û���ŶӵĲ���\n");
    else
    {   p=qu->front;
    printf("  >>����%d����\n",p->data);
    if(qu->rear==p)
        qu->front=qu->rear=NULL;
    else
        qu->front=p->next;
    free(p);
    }
    break;
    case 3:if(qu->front==NULL)
    printf("  >>û���ŶӵĲ���\n");
    else
    { p=qu->front;
        printf("  >>�ŶӲ���:");
        while(p!=NULL)
        {
            printf("%d",p->data);
            p=p->next;
        }
        printf("\n");
    }
    break;
    case 4:if(qu->front==NULL)
    printf("  >>û�����еĲ���\n");
    else
    {
        p=qu->front;
        printf("  >>���˰�����˳�����:");
        while(p!=NULL)
        {
            printf("%d",p->data);
            p=p->next;
        }
        printf("\n");
    }
    flag=0;
    Destroyqueue(qu);
    break;
    case 5:if(qu->front!=NULL)
    printf("  >>���ŶӵĲ��������ҽ\n");
    flag=0;
    Destroyqueue(qu);
    break;
    }
    }
}

int main()
{
   SeeDoctor();
   return 0;
}
