#include <stdio.h>
#include<malloc.h>
typedef struct qnode
{   int data;
    struct qnode *next;
}QNode;//链队节点类型
typedef struct
{
    QNode *front,*rear;//队头队尾指针
}QuType;//链队类型
void Destroyqueue(QuType *&qu)
{
    QNode *p,*q;
    p=qu->front;//若链队不空
    if(p!=NULL)
    {
        q=p->next;
        while(q!=NULL)
        {
            free(p);//释放队中节点
            p=q;
            q=q->next;
        }
        free(p);//释放链队节点
    }
    free(qu);
}
void SeeDoctor()//模拟病人看病过程
{
    int sel,flag=1,find,no;
    QuType *qu;
    QNode *p;
    qu=(QuType *)malloc(sizeof(QuType));
    qu->front=qu->rear=NULL;
    while(flag==1)
    {
    printf("1:排队 2:就诊 3:查看排队 4:不再排队,余下依次排队 5:下班 请选择:");
    scanf("%d",&sel);
    switch(sel)
    {
    case 1: printf(" >>输入病历号：");
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
            printf("  >>输入的病历号重复，重新输入:");

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
    printf("  >>没有排队的病人\n");
    else
    {   p=qu->front;
    printf("  >>病人%d就诊\n",p->data);
    if(qu->rear==p)
        qu->front=qu->rear=NULL;
    else
        qu->front=p->next;
    free(p);
    }
    break;
    case 3:if(qu->front==NULL)
    printf("  >>没有排队的病人\n");
    else
    { p=qu->front;
        printf("  >>排队病人:");
        while(p!=NULL)
        {
            printf("%d",p->data);
            p=p->next;
        }
        printf("\n");
    }
    break;
    case 4:if(qu->front==NULL)
    printf("  >>没有排列的病人\n");
    else
    {
        p=qu->front;
        printf("  >>病人按以下顺序就诊:");
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
    printf("  >>请排队的病人明天就医\n");
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
