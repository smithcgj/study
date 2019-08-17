#include<stdio.h>
#include<malloc.h>
typedef char ElemType;
typedef struct DNode//����˫����ڵ�����
{
    ElemType data;
    struct DNode * prior;//ָ��ǰ���ڵ�
    struct DNode * next;//ָ���̽ڵ�
}DLinkList;
void InitList(DLinkList * &L)//��ʼ��
{
    L=(DLinkList *)malloc(sizeof(DLinkList));//����ͷ�ڵ�
    L->prior=L->next=NULL;
}
void DestroyList(DLinkList * &L)//�������Ա�
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
bool ListEmpty(DLinkList * L)//�ж����Ա��Ƿ�Ϊ�ձ�
{
    return(L->next==NULL);
}
int ListLength(DLinkList * L)//�����Ա�ĳ���
{
    DLinkList * p=L;int i=0;
    while(p->next!=NULL)
    {
        i++;
        p=p->next;
    }
    return(i);
}
void DispList(DLinkList * L)//������Ա�
{
    DLinkList * p=L->next;
    while(p!=NULL)
    {
        printf("%c",p->data);
        p=p->next;
    }
    printf("\n");
}
bool GetElem(DLinkList * L,int i,ElemType &e)//�����Ա���ĳ������Ԫ��ֵ
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
int LocateElem(DLinkList * L,ElemType e)//��Ԫ��ֵ����
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
bool ListINsert(DLinkList * &L,int i,ElemType e)//��������Ԫ��
{
    int j=0;
    DLinkList *p=L,*s;
    while(j<i-1&&p!=NULL)
    {
        j++;
        p=p->next;
    }
    if(p==NULL)//δ�ҵ���i-1���ڵ�
        return false;
    else//�ҵ���i-1���ڵ�
    {
        s=(DLinkList *)malloc(sizeof(DLinkList));//�����½ڵ�*s
        s->data=e;
        s->next=p->next;//��*schar��*p֮��
        if(p->next!=NULL) p->next->prior=s;
        s->prior=p;
        p->next=s;
        return true;
    }
}
bool ListDelete(DLinkList * &L,int i,ElemType &e)//ɾ������Ԫ��
{
    int j=0;
    DLinkList * p=L,*q;
    while(j<i-1&&p!=NULL)
    {
        j++;
        p=p->next;
    }
    if(p==NULL)//δ�ҵ���i-1���ڵ�
        return false;
    else//�ҵ���i-1g�ڵ�*p
    {
        q=p->next;//qָ��Ҫɾ���Ľڵ�
        if(q==NULL) return false;//�����ڵ�i���ڵ�
        e=q->data;
        p->next=q->next;//�ӵ�������ɾ��*q�ڵ�
        if(p->next!=NULL)
            p->next->prior=p;
        free(q);//�ͷ�*q�ڵ�
        return true;
    }
}
