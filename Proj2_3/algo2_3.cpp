#include<stdio.h>
#include<malloc.h>
typedef char ElemType;
typedef struct DNode//定义双链表节点类型
{
    ElemType data;
    struct DNode * prior;//指向前驱节点
    struct DNode * next;//指向后继节点
}DLinkList;
void InitList(DLinkList * &L)//初始化
{
    L=(DLinkList *)malloc(sizeof(DLinkList));//创建头节点
    L->prior=L->next=NULL;
}
void DestroyList(DLinkList * &L)//销毁线性表
{
    DLinkList * p=L,*q=p->next;
    while(q!=NULL)
    {
        free(p);
        p=q;
        q=p->next;
    }
    free(p);
}
bool ListEmpty(DLinkList * L)//判断线性表是否为空表
{
    return(L->next==NULL);
}
int ListLength(DLinkList * L)//求线性表的长度
{
    DLinkList * p=L;int i=0;
    while(p->next!=NULL)
    {
        i++;
        p=p->next;
    }
    return(i);
}
void DispList(DLinkList * L)//输出线性表
{
    DLinkList * p=L->next;
    while(p!=NULL)
    {
        printf("%c",p->data);
        p=p->next;
    }
    printf("\n");
}
bool GetElem(DLinkList * L,int i,ElemType &e)//求线性表中某个数据元素值
{
    int j=0;
    DLinkList * p=L;
    while(j<i&&p!=NULL)
    {
        j++;
        p=p->next;
    }
    if(p==NULL)
        return false;
    else
    {
        e=p->data;
        return true;
    }
}
int LocateElem(DLinkList * L,ElemType e)//按元素值查找
{
    int n=1;
    DLinkList * p=L->next;
    while(p!=NULL&&p->data!=e)
    {
        n++;
        p=p->next;
    }
    if(p==NULL)
        return (0);
    else
        return (n);
}
bool ListINsert(DLinkList * &L,int i,ElemType e)//插入数据元素
{
    int j=0;
    DLinkList *p=L,*s;
    while(j<i-1&&p!=NULL)
    {
        j++;
        p=p->next;
    }
    if(p==NULL)//未找到第i-1个节点
        return false;
    else//找到第i-1个节点
    {
        s=(DLinkList *)malloc(sizeof(DLinkList));//创建新节点*s
        s->data=e;
        s->next=p->next;//将*schar到*p之后
        if(p->next!=NULL) p->next->prior=s;
        s->prior=p;
        p->next=s;
        return true;
    }
}
bool ListDelete(DLinkList * &L,int i,ElemType &e)//删除数据元素
{
    int j=0;
    DLinkList * p=L,*q;
    while(j<i-1&&p!=NULL)
    {
        j++;
        p=p->next;
    }
    if(p==NULL)//未找到第i-1个节点
        return false;
    else//找到第i-1g节点*p
    {
        q=p->next;//q指向要删除的节点
        if(q==NULL) return false;//不存在第i个节点
        e=q->data;
        p->next=q->next;//从单链表中删除*q节点
        if(p->next!=NULL)
            p->next->prior=p;
        free(q);//释放*q节点
        return true;
    }
}
