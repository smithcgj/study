#include<stdio.h>
#include<malloc.h>
typedef char ElemType;
typedef struct LNode//���嵥����ڵ�
{
    ElemType data;
    struct LNode * next;
}LinkList;
void InitList(LinkList * &L)//��ʼ�����Ա�
{
    L=(LinkList *)malloc(sizeof(LinkList));//����ͷ�ڵ�
    L->next=NULL;
}
void DestroyList(LinkList * &L)//�������Ա�
{
    LinkList *p=L, *q=p->next;
    while(q!=NULL)
    {
        free(p);
        p=q;
        q=p->next;
    }
    free(p);
}
bool ListEmpty(LinkList * L)//�ж����Ա�ĳ���
{
    return(L->next==NULL);
}
int ListLength(LinkList *L)//�����Ա�ĳ���
{
    LinkList *p=L;
    int i=0;
    while(p->next!=NULL)
    {
        i++;
        p=p->next;
    }
    return (i);
}
void DispList(LinkList * L)//������Ա�
{
    LinkList *p=L->next;
    while(p!=NULL)
    {
        printf("%c",p->data);
        p=p->next;
    }
    printf("\n");
}
bool GetElem(LinkList * L,int i,ElemType &e)//�����Ա���ĳ������Ԫ��ֵ
{
    int j=0;
    LinkList *p=L;//pָ��ͷ�ڵ㣬j��Ϊ0����ͷ�ڵ�����Ϊ0��
    while(j<i&&p!=NULL)
    {
        j++;
        p=p->next;
    }
    if(p==NULL)//�����ڵ�i�����ݽڵ㣬����false
        return false;
    else//���ڵ�i�����ݽڵ㣬����true
    {
        e=p->data;
         return true;
    }
}
 int LocateELem(LinkList *L,ElemType e)//��Ԫ��ֵѰ��
 {
     int i=1;
     LinkList *p=L->next;//pָ��ʼ�ڵ㣬i��Ϊ1������ʼ�ڵ�����Ϊ1��
     while(p!=NULL&&p->data!=e)//����dataΪe�Ľڵ㣬�����Ϊi
     {
         p=p->next;
         i++;
     }
     if(p==NULL)//������Ԫ��ֵΪe�Ľڵ㣬����0
        return (0);
     else//����Ԫ��ֵΪe�Ľڵ㣬�������߼����i
        return (i);
 }
 bool ListInsert(LinkList * &L,int i,ElemType e)//��������Ԫ��
 {
     int j=0;
     LinkList *p=L,*s;//pָ��ͷ�ڵ㣬j��Ϊ0����ͷ�ڵ�����Ϊ0��
     while(j<i-1&&p!=NULL)//���ҵ�i-1���ڵ�
     {
         j++;
         p=p->next;
     }
     if(p==NULL)//δ�ҵ���i-1���ڵ㣬����false
     return false;
     else//�ҵ���i-1���ڵ�*p�������½ڵ㲢����true
     {
         s=(LinkList *)malloc(sizeof(LinkList));
         s->data=e;//�����½ڵ�*s����data����Ϊe
         s->next=p->next;//��*s����*p֮��
         p->next=s;
         return true;
     }
 }
 bool ListDelete(LinkList * &L,int i,ElemType &e)//ɾ������Ԫ��
 {
     int j=0;
     LinkList *p=L,*q;//pָ��ͷ�ڵ㣬j��Ϊ0����ͷ�ڵ�����Ϊ0��
     while(j<i-1&&p!=NULL)//���ҵ�i-1���ڵ�
     {
         j++;
         p=p->next;
     }
     if(p==NULL)//δ�ҵ���i-1���ڵ㣬����false
        return false;
     else//�ҵ���i-1���ڵ�*p
     {
         q=p->next;//qָ���i���ڵ�
         if(q==NULL)//�������ڵ�i���ڵ㣬����false
            return false;
         e=q->data;
         p->next=q->next;//�ӵ�������ɾ��*q�ڵ�
         free(q);//�ͷ�*q�ڵ�
         return true;//����true��ʾ�ɹ�ɾ����i ���ڵ�
     }
 }
