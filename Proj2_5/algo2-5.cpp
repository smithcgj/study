#include<stdio.h>
#include<malloc.h>
typedef char ElemType;
typedef struct DNode//定义双链表节点类型
{
    ElemType data;
    struct DNode * prior;//指向前驱节点
    struct DNode * next;//指向后继节点
}DLinkList;
void INitList(DLinkList * &L)//初始化线性表
{
    L=(DLinkList *)malloc(sizeof(DLinkList));//创建头节点
    L->prior=L->next=L;
}
void DestroyList(DLinkList * &L)//销毁线性表
{
    DLinkList * p=L,*q=p->next;
    while(q!=L)
    {
        free(p);
        p=q;
        q=p->next;
    }
    free(p);
}
bool ListEmpty(DLinkList * L)//判断线性表是否为空表
{
    return(L->next==L);
}
int ListLength(DLinkList * L)//求线性表
{
    DLinkList * p=L;int i=0;
    while(p->next!=L)
    {
        i++;
        p=p->next;
    }
    return (i);
}
void DispList(DLinkList * L)//输出线性表
{
    DLinkList *p=L->next;
    while(p!=L)
    {
        printf("%c",p->data);
        p=p->next;
    }
    printf("\n");
}
bool GetElem(DLinkList *L,int i,ElemType &e)//求线性表中某个数据元素值
{
    int j=0;
    DLinkList * p;
    if(L->next!=L)//双链表不为空时
    {
        if(i==1)
        {
            e=L->next->data;
            return true;
        }
        else//i不为1时
        {
            p=L->next;
            while(j<i-1&&p!=L)
            {
                j++;
                p=p->next;
            }
            if(p==L)
            return false;
            else
            {
                e=p->data;
                return true;
            }

        }

    }
    else
        return false;//双链表为空表
}
int LocateElem(DLinkList *L,ElemType e)//按元素值查找
{
    int n=1;
    DLinkList *p=L->next;
    while(p!=NULL&&p->data!=e)
    {
        n++;
        p=p->next;
    }
    if(p==NULL)
        return(0);
    else
       return (n);
}
bool ListInsert(DLinkList * &L,int i,ElemType e)//插入数据元素
{
    int j=0;
    DLinkList *p=L,*s;
    if(p->next==L)//原双链表为空表时
    {
        s=(DLinkList *)malloc(sizeof(DLinkList));//创建新节点*s
        s->data=e;
        p->next=s;s->next=p;//将*s插入到* p
        p->prior=s;s->prior=p;
        return true;
    }
    else if(i==1)//原链表不为1且i=1时
    {
        s=(DLinkList *)malloc(sizeof(DLinkList));//创建新节点*s
        s->data=e;
        s->next=p->next;p->next=s;//将*s插入到*p之后
        s->next->prior=s;s->prior=p;
        return true;
    }
    else
    {
        p=L->next;
        while(j<i-2&&p!=L)
        {
            j++;
            p=p->next;
        }
        if(p==L)//未找到第i-1个节点
            return false;
        else//找到第i-1个节点*P
        {
           s=(DLinkList *)malloc(sizeof(DLinkList));//创建新节点*s
           s->data=e;
           s->next=p->next;//将*s插入到*p之后
           if(p->next!=NULL)
            p->next->prior=s;
           s->prior=p;
           p->next=s;
           return true;
        }
    }
}
bool ListDelete(DLinkList * &L,int i,ElemType &e)// 删除数据元素
{
    int j=0;
    DLinkList * p=L,*q;
    if(p->next!=L)//原链表不为空表时
    {
        if(i==1)//i==1时
        {
            q=L->next;//删除第一个节点
            e=q->data;
            L->next=q->next;
            q->next->prior=L;
            free(q);
            return true;
        }
        else
        {
            p=L->next;
            while(j<i-2&&p!=NULL)
            {
                j++;
               p=p->next;
            }
            if(p==NULL)//未找到第i-1个节点
                return false;
            else//找到第i-1个节点*p
            {
                q=p->next;//q指向要删除的节点
                if(q==NULL)
                    return false;//不存在第i个节点
                e=q->data;
                p->next=q->next;//从单链表中删除*q节点
                if(p->next!=NULL)
                    p->next->prior=p;
                free(q);//释放*q节点
                return true;
            }
        }
    }
    else//原链表为空表时
        return false;
}
