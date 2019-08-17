#include<stdio.h>
#include<malloc.h>
typedef char ElemType;
typedef struct DNode//����˫����ڵ�����
{
    ElemType data;
    struct DNode * prior;//ָ��ǰ���ڵ�
    struct DNode * next;//ָ���̽ڵ�
}DLinkList;
void INitList(DLinkList * &L)//��ʼ�����Ա�
{
    L=(DLinkList *)malloc(sizeof(DLinkList));//����ͷ�ڵ�
    L->prior=L->next=L;
}
void DestroyList(DLinkList * &L)//�������Ա�
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
bool ListEmpty(DLinkList * L)//�ж����Ա��Ƿ�Ϊ�ձ�
{
    return(L->next==L);
}
int ListLength(DLinkList * L)//�����Ա�
{
    DLinkList * p=L;int i=0;
    while(p->next!=L)
    {
        i++;
        p=p->next;
    }
    return (i);
}
void DispList(DLinkList * L)//������Ա�
{
    DLinkList *p=L->next;
    while(p!=L)
    {
        printf("%c",p->data);
        p=p->next;
    }
    printf("\n");
}
bool GetElem(DLinkList *L,int i,ElemType &e)//�����Ա���ĳ������Ԫ��ֵ
{
    int j=0;
    DLinkList * p;
    if(L->next!=L)//˫����Ϊ��ʱ
    {
        if(i==1)
        {
            e=L->next->data;
            return true;
        }
        else//i��Ϊ1ʱ
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
        return false;//˫����Ϊ�ձ�
}
int LocateElem(DLinkList *L,ElemType e)//��Ԫ��ֵ����
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
bool ListInsert(DLinkList * &L,int i,ElemType e)//��������Ԫ��
{
    int j=0;
    DLinkList *p=L,*s;
    if(p->next==L)//ԭ˫����Ϊ�ձ�ʱ
    {
        s=(DLinkList *)malloc(sizeof(DLinkList));//�����½ڵ�*s
        s->data=e;
        p->next=s;s->next=p;//��*s���뵽* p
        p->prior=s;s->prior=p;
        return true;
    }
    else if(i==1)//ԭ����Ϊ1��i=1ʱ
    {
        s=(DLinkList *)malloc(sizeof(DLinkList));//�����½ڵ�*s
        s->data=e;
        s->next=p->next;p->next=s;//��*s���뵽*p֮��
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
        if(p==L)//δ�ҵ���i-1���ڵ�
            return false;
        else//�ҵ���i-1���ڵ�*P
        {
           s=(DLinkList *)malloc(sizeof(DLinkList));//�����½ڵ�*s
           s->data=e;
           s->next=p->next;//��*s���뵽*p֮��
           if(p->next!=NULL)
            p->next->prior=s;
           s->prior=p;
           p->next=s;
           return true;
        }
    }
}
bool ListDelete(DLinkList * &L,int i,ElemType &e)// ɾ������Ԫ��
{
    int j=0;
    DLinkList * p=L,*q;
    if(p->next!=L)//ԭ����Ϊ�ձ�ʱ
    {
        if(i==1)//i==1ʱ
        {
            q=L->next;//ɾ����һ���ڵ�
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
            if(p==NULL)//δ�ҵ���i-1���ڵ�
                return false;
            else//�ҵ���i-1���ڵ�*p
            {
                q=p->next;//qָ��Ҫɾ���Ľڵ�
                if(q==NULL)
                    return false;//�����ڵ�i���ڵ�
                e=q->data;
                p->next=q->next;//�ӵ�������ɾ��*q�ڵ�
                if(p->next!=NULL)
                    p->next->prior=p;
                free(q);//�ͷ�*q�ڵ�
                return true;
            }
        }
    }
    else//ԭ����Ϊ�ձ�ʱ
        return false;
}
