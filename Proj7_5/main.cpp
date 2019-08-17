#include <stdio.h>
#include<malloc.h>
#define MaxSize 100
typedef char ElemType;
typedef struct node
{
    ElemType data;
    int ltag,rtag;//�������������
    struct node *lchild;//����ָ��
    struct node *rchild;//�Һ���ָ��
}TBTNode;
void CreateTBTNode(TBTNode * &b,char *str)
{
    TBTNode *St[MaxSize],*p=NULL;
    int top=-1,k,j=0;
    char ch;
    b=NULL;//������������ʼʱΪ��
    ch=str[j];
    while(ch!='\0');//strδɨ����ʱѭ��
    {
        switch(ch)
        {
            case '(':top++;St[top]=p;k=1;break;//Ϊ��ڵ�
            case ')':top--;break;
            case ',':k=2;break;//Ϊ�ҽڵ�
            default:p=(TBTNode *)malloc(sizeof(TBTNode));
            p->data=ch;p->lchild=p->rchild=NULL;
            if(b==NULL)//pΪ�������ĸ��ڵ�
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
void DispTBTNode(TBTNode *b)
{
    if(b!=NULL)
    {
        printf("%c",b->data);
        if(b->lchild!=NULL||b->rchild!=NULL)
        {
            printf("(");
            DispTBTNode(b->lchild);
            if(b->rchild!=NULL) printf(",");
            DispTBTNode(b->rchild);
            printf(")");
        }
    }
}
TBTNode *pre;//ȫ�ֱ���
void Thread(TBTNode *&p)
{
    if(p!=NULL)
    {
        Thread(p->lchild);//������������
        if(p->lchild==NULL)//ǰ������
        {
            p->lchild=pre;//������ǰ�ڵ��ǰ������
            p->ltag=1;
        }
        else p->ltag=0;
        if(pre->rchild==NULL)//�������
        {
            pre->rchild=p;//����ǰ���ڵ�ĺ������
            pre->rtag=1;
        }
        else pre->rtag=0;
            pre=p;
        Thread(p->rchild);//������������
    }
}
TBTNode * CreateThread(TBTNode *b)//����������������
{
    TBTNode *root;
    root=(TBTNode *)malloc(sizeof(TBTNode));//�������ڵ�
    root->ltag=0;root->rtag=1;
    root->rchild=b;
    if(b==NULL)//�ն�����
    root->lchild=root;
    else
    {
        root->lchild=b;
        pre=root;//pre��*p��ǰ���ڵ�,����������
        Thread(b);//�������������������
        pre->rchild=root;//�����,����ָ����ڵ������
        pre->rtag=1;
        root->rchild=pre;//���ڵ���������
    }
    return root;
}
void InOrder(TBTNode *tb)//��ThInOrder�㷨����
{
    if(tb->lchild!=NULL&&tb->ltag==0)//����
        InOrder(tb->rchild);
    printf("%c",tb->data);
    if(tb->rchild!=NULL&&tb->rtag==0)//���Һ���
        InOrder(tb->rchild);
}
void ThInOrder(TBTNode *tb)//����ݹ��㷨
{
    InOrder(tb->lchild);//tb->lchildָ��ԭ�������ĸ��ڵ�
}
void ThInOrder1(TBTNode *tb)//����ǵݹ��㷨
{
    TBTNode *p=tb->lchild;//ָ����ڵ�
    while(p!=tb)
    {
        while(p->ltag==0) p=p->lchild;
        printf("%c",p->data);
        while(p->rtag==1&&p->rchild!=tb)
        {
            p=p->rchild;
            printf("%c",p->data);
        }
        p=p->rchild;
    }
}
void DestroyTBTNode1(TBTNode *tb)//��DestroyTBTNode�㷨����
{
    if(tb!=NULL)
    {
        if(tb->lchild!=NULL&&tb->ltag==0)//������
            DestroyTBTNode1(tb->lchild);
        if(tb->rchild!=NULL&&tb->rtag==0)//���Һ���
            DestroyTBTNode1(tb->rchild);
        free(tb);
    }
}
void DestroyTBTNode(TBTNode* tb)//�ͷ��������������������нڵ�
{
    DestroyTBTNode1(tb->lchild);
    free(tb);//�ͷ�����������������ͷ�ڵ�
}
int main()
{
    TBTNode *b,*tb;
    CreateTBTNode(b,"A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))");
    printf("������:");DispTBTNode(b);printf("\n");
    tb=CreateThread(b);
    printf("������������:\n");
    printf("    �ݹ��㷨:");ThInOrder(tb);printf("\n");
    printf("  �ǵݹ��㷨:");ThInOrder1(tb);printf("\n");
    DestroyTBTNode(tb);
    return 0;
}
