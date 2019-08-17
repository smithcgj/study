#include<stdio.h>
#include<malloc.h>
typedef char ElemType;
typedef struct LNode//���嵥����ڵ�����
{
    ElemType data;
    struct LNode * next;
}LinkList;
extern void DispList(LinkList * L);
extern void DestroyList(LinkList * &L);
void CreatListR(LinkList * &L,ElemType a[],int n)//β�巨����
{
    LinkList *s,*r;int i;
    L=(LinkList *)malloc(sizeof(LinkList));//����ͷ�ڵ�
    L->next=NULL;
    r=L;//rʼ��ָ���ն˽ڵ㣬��ʼʱָ��ͷ�ڵ�
    for(i=0;i<n;i++)
    {
        s=(LinkList *)malloc(sizeof(LinkList));//�����½ڵ�
        s->data=a[i];
        r->next=s;//��*s����*r֮��
        r=s;
    }
    r->next=NULL;//�ն˽ڵ�next����ΪNULL
}
void sort(LinkList * &L)//������Ԫ�ص�������
{
    LinkList *p,*pre,*q;
    p=L->next->next;//pָ��L�ĵ�2�����ݽڵ�
    L->next->next=NULL;//����ֻ��һ�����ݽڵ�������
    while(p!=NULL)
    {
        q=p->next;//q����*p�ڵ��̽ڵ��ָ��
        pre=L;//����������Ҳ���*p��ǰ���ڵ�
        while(pre->next!=NULL&&pre->next->data<p->data)
            pre=pre->next;//����������Ҳ���*p��ǰ���ڵ�
        p->next=pre->next;//��*pre֮�����*p
        pre->next=p;
        p=q;//ɨ��ԭ���������µĽڵ�
    }
}
void Union(LinkList * ha,LinkList * hb,LinkList * &hc)//�������򼯺ϵĲ�
{
    LinkList *pa=ha->next,*pb=hb->next,*s,*tc;
    hc=(LinkList *)malloc(sizeof(LinkList));//����ͷ�ڵ�
    tc=hc;
    while(pa!=NULL&&pb!=NULL)
    {
        if(pa->data<pb->data)
        {
            s=(LinkList *)malloc(sizeof(LinkList));//���ƽڵ�
            s->data=pa->data;
            tc->next=s;tc=s;
            pa=pa->next;
        }
        else if(pa->data>pb->data)
        {
            s=(LinkList * )malloc(sizeof(LinkList));//���ƽڵ�
            s->data=pb->data;
            tc->next=s;tc=s;
            pb=pb->next;
        }
        else
        {
            s=(LinkList *)malloc(sizeof(LinkList));//���ƽڵ�
            s->data=pa->data;
            tc->next=s;tc=s;
            pa=pa->next;//�ظ���Ԫ��ֻ����һ��
            pb=pb->next;
        }
    }
    if(pb!=NULL) pa=pb;//�������½ڵ�
    while(pa!=NULL)
    {
        s=(LinkList *)malloc(sizeof(LinkList));//���ƽڵ�
        s->data=pa->data;
        tc->next=s;tc=s;
        pa=pa->next;
    }
    tc->next=NULL;
}
void InterSect(LinkList *ha,LinkList *hb,LinkList *&hc)//�������򼯺ϵĲ�
{
    LinkList *pa=ha->next,*pb,*s,*tc;
    hc=(LinkList *)malloc(sizeof(LinkList));
    tc=hc;
    while(pa!=NULL)
    {
        pb=hb->next;
        while(pb!=NULL&&pb->data<pa->data)
            pb=pb->next;
        if(pb!=NULL&&pb->data==pa->data)//��pa�ڵ�ֵ��B��
        {
            s=(LinkList *)malloc(sizeof(LinkList));//���ƽڵ�
            s->data=pa->data;
            tc->next=s;tc=s;
        }
        pa=pa->next;
    }
    tc->next=NULL;
}
void Subs(LinkList *ha,LinkList *hb,LinkList *&hc)//�������򼯺ϵĲ�
{
    LinkList *pa=ha->next,*pb,*s,*tc;
    hc=(LinkList *)malloc(sizeof(LinkList));
    tc=hc;
    while(pa!=NULL)
    {
        pb=hb->next;
        while(pb!=NULL&&pb->data<pa->data)
            pb=pb->next;
        if(!(pb!=NULL&&pb->data==pa->data))//��pa�ڵ�ֵ����B��
        {
            s=(LinkList *)malloc(sizeof(LinkList));//���ƽڵ�
            s->data=pa->data;
            tc->next=s;tc=s;
        }
        pa=pa->next;
    }
    tc->next=NULL;
}
int main()
{
    LinkList *ha,*hb,*hc;
    ElemType a[]={'c','a','e','h'};
    ElemType b[]={'f','h','b','g','d','a'};
    printf("������������:\n");
    CreatListR(ha,a,4);
    CreatListR(hb,b,6);
    printf("  ԭ����A:");DispList(ha);
    printf("  ԭ����B:");DispList(hb);
    sort(ha);
    sort(hb);
    printf("  ԭ����A:");DispList(ha);
    printf("  ԭ����B:");DispList(hb);
    Union(ha,hb,hc);
    printf("  ���ϵĲ�C:");DispList(hc);
    InterSect(ha,hb,hc);
    printf("  ���ϵĽ�C:");DispList(hc);
    Subs(ha,hb,hc);
    printf("  ���ϵĲ�C:");DispList(hc);
    DestroyList(ha);
    DestroyList(hb);
    DestroyList(hc);
    return 0;
}
