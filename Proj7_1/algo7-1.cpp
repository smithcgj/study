#include<stdio.h>
#include<malloc.h>
#define MaxSize 100
typedef char ElemType;
typedef struct node
{
    ElemType data;//����Ԫ��
    struct node * lchild;//ָ������
    struct node * rchild;//ָ���Һ���
}BTNode;
void CreateBTNode(BTNode *&b,char * str)//��str������������
{
    BTNode* St[MaxSize], *p=NULL;
    int top=-1,k,j=0;
    char ch;
    b=NULL;//�����Ķ�������ʼʱΪ��
    ch=str[j];
    while(ch!='\0')//strδɨ����ʱѭ��
    {
        switch(ch)
        {
            case '(':top++;St[top]=p;k=1;break;//Ϊ��ڵ�
            case ')':top--;break;
            case ',':k=2;break;//Ϊ�ҽڵ�
            default:p=(BTNode *)malloc(sizeof(BTNode));
            p->data=ch;p->lchild=p->rchild=NULL;
            if(b==NULL)//pָ��������ĸ��ڵ�
                b=p;
            else//�ѽ������������ڵ�
            {
                switch(k)
                {
                    case 1:St[top]->lchild=p;break;
                    case 2:St[top]->rchild=p;break;
                }
            }
        }
        j++;
        ch=str[j];
    }
}
BTNode * FindNode(BTNode * b,ElemType x)//����data��Ϊx�Ľڵ�ָ��
{
    BTNode * p;
    if(b==NULL)
        return NULL;
    else if(b->data==x)
        return b;
    else
    {
        p=FindNode(b->lchild,x);
        if(p!=NULL)
            return p;
        else
            return FindNode(b->rchild,x);
    }
}
BTNode * LchidNode(BTNode *p)//����*p�ڵ�����ӽڵ�ָ��
{
    return p->lchild;
}
BTNode * RchildNode(BTNode *p)//����*p�ڵ���Һ��ӵĽڵ�ָ��
{
    return p->rchild;
}
int BTNodeDEpth(BTNode *b)//�������b�����
{
    int lchilddep,rchilddep;
    if(b==NULL)
        return (0);//�����߶�Ϊ0
    else
    {
        lchilddep=BTNodeDEpth(b->lchild);//���������ĸ߶�
        rchilddep=BTNodeDEpth(b->rchild);//���������ĸ߶�
        return(lchilddep>rchilddep)?(lchilddep+1):(rchilddep+1);
    }
}
void DispBTNode(BTNode *b)//�����ű�ʾ�����������
{
    if(b!=NULL)
    {
        printf("%c",b->data);
        if(b->lchild!=NULL||b->rchild!=NULL)
        {
            printf("(");
            DispBTNode(b->lchild);
            if(b->rchild!=NULL) printf(",");
            DispBTNode(b->rchild);
            printf(")");
        }
    }
}
int BTWidth(BTNode *b)//��������Ŀ���
{
    struct
    {
        int lno;//�ڵ�Ĳ�α��
        BTNode *p;//�ڵ�ָ��
    }Qu[MaxSize];//����˳���ѭ������
    int front,rear;//������׺Ͷ�βָ��
    int lnum,max,i,n;
    front=rear=0;//�ö���Ϊ�ն�
    if(b!=NULL)
    {
        rear++;
        Qu[rear].p=b;//���ڵ�ָ�����
        Qu[rear].lno=1;//���ڵ�Ĳ�α��Ϊ1
        while(rear!=front)//���в�Ϊ��
        {
            front++;
            b=Qu[front].p;//��ͷ����
            lnum=Qu[front].lno;
            if(b->lchild!=NULL)//�������
            {
                rear++;
                Qu[rear].p=b->lchild;
                Qu[rear].lno=lnum+1;
            }
            if(b->rchild!=NULL)//�Һ������
            {
                rear++;
                Qu[rear].p=b->rchild;
                Qu[rear].lno=lnum+1;
            }
        }
        max=0;lnum=1;i=1;
        while(i<=rear)
        {
            n=0;
            while(i<=rear && Qu[i].lno==lnum)
            {
                n++;i++;
            }
            lnum=Qu[i].lno;
            if(n>max) max=n;
        }
        return max;
    }
    else
        return 0;
}
int Nodes(BTNode *b)//�������b�Ľڵ����
{
    int num1,num2;
    if(b==NULL)
        return 0;
    else if(b->lchild==NULL && b->rchild ==NULL)
        return 1;
    else
    {
        num1=Nodes(b->lchild);
        num2=Nodes(b->rchild);
        return (num1+num2+1);
    }
}
int LeafNode(BTNode *b)//�������b��Ҷ�ӽڵ���
{
    int num1,num2;
    if(b==NULL)
        return 0;
    else if(b->lchild==NULL&&b->rchild==NULL)
        return 1;
    else
    {
        num1=LeafNode(b->lchild);
        num2=LeafNode(b->rchild);
        return (num1 +num2);
    }
}
void DestroyBTNode(BTNode *&b)
{
    if(b!=NULL)
    {
        DestroyBTNode(b->lchild);
        DestroyBTNode(b->rchild);
        free(b);
    }
}