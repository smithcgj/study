#include<stdio.h>
#include<malloc.h>
#define MAX 20//����ʽ�������
typedef struct parray//�����Ŷ���ʽ����������
{
    double coef;//ϵ��
    int exp;//ָ��
}PolyArray[MAX];
typedef struct pnode//���嵥����ڵ�����
{
    double coef;//ϵ��
    int exp;//ָ��
    struct pnode *next;
}PolyNode;
void DispPoly(PolyNode * L)//�������ʽ
{
    bool first=true;//firstΪtrue��ʾ�ǵ�һ��
    PolyNode * p=L->next;
    while(p!=NULL)
    {
        if(first)
            first=false;
        else if(p->coef>0)
            printf("+");
        if(p->exp==0)
            printf("%g",p->coef);
        else if(p->exp==1)
            printf("%gx",p->coef);
        else
            printf("%gx^%d",p->coef,p->exp);
      p=p->next;
    }
    printf("\n");
}
void DestroyList(PolyNode *&L)//���ٵ�����
{
    PolyNode *p=L,*q=p->next;
    while(q!=NULL)
    {
        free(q);
        p=q;
        q=p->next;
    }
    free(p);
}
void CreateListR(PolyNode *&L,PolyArray a,int n)//β�巨����
{
    PolyNode * s,*r;int i;
    L=(PolyNode *)malloc(sizeof(PolyNode));//����ͷ�ڵ�
    L->next=NULL;
    r=L;//rʼ��ָ���ն˽ڵ㣬��ʼʱָ��ͷ�ڵ�
    for(i=0;i<n;i++)
    {
        s=(PolyNode *)malloc(sizeof(PolyNode));//�����½ڵ�
        s->coef=a[i].coef;
        s->exp=a[i].exp;
        r->next=s;//��*s����*r֮��
        r=s;
    }
    r->next=NULL;//�ն˽ڵ�next����ΪNULL
}
void Sort(PolyNode * &head)//��exp��ݼ�����
{
    PolyNode *p=head->next, *q,*r;
    if(p!=NULL)//��ԭ��������һ�������ϵ����ݽڵ�
    {
        r=p->next;//r����*p�ں�̽ڵ��ָ��
        p->next=NULL;//����ֻ��һ�����ݽڵ�������
        p=r;
        while(p!=NULL)
        {
            r=p->next;//r����*p�ڵ��̽ڵ��ָ��
            q=head;
            while(q->next!=NULL&&q->next->exp>p->exp)
                q=q->next;//����������Ҳ���*p��ǰ���ڵ�*q
            p->next=q->next;
            q->next=p;
            p=r;
        }
    }
}
void Add(PolyNode *ha,PolyNode *hb,PolyNode * &hc)//�������򼯺ϵĲ�
{
    PolyNode * pa=ha->next,*pb=hb->next,*s,*tc;
    double c;
    hc=(PolyNode *)malloc(sizeof(PolyNode));//����ͷ�ڵ�
    tc=hc;
    while(pa!=NULL && pb!=NULL)
    {
        if(pa->exp>pb->exp)
        {
            s=(PolyNode *)malloc(sizeof(PolyNode));//���ƽڵ�
            s->exp=pa->exp;s->coef=pa->coef;
            tc->next=s;tc=s;
            pb=pb->next;
        }
        else if(pa->exp<pb->exp)
        {
            s=(PolyNode *)malloc(sizeof(PolyNode));//���ƽڵ�
            s->exp=pb->exp;s->coef=pb->coef;
            tc->next=s;tc=s;
            pb=pb->next;
        }
        else//pa->exp=pb->exp
        {
            c=pa->coef+pb->coef;
            if(c!=0)//ϵ��֮�Ͳ�Ϊ0ʱ�����ڵ�
            {
                s=(PolyNode *)malloc(sizeof(PolyNode));//���ƽڵ�
                s->exp=pa->exp;s->coef=c;
                tc->next=s;tc=s;
            }
            pa=pa->next;
            pb=pb->next;

        }
    }
    if(pb!=NULL) pa=pb;//�������½ڵ�
    while(pa!=NULL)
    {
        s=(PolyNode *)malloc(sizeof(PolyNode));//���ƽڵ�]
        s->exp=pa->exp;s->coef=pa->coef;
        tc->next=s;tc=s;
        pa=pa->next;
    }
    tc->next=NULL;
}
int main()
{
    PolyNode *ha,*hb,*hc;
    PolyArray a={{1.2,0},{2.5,1},{3.2,3},{-2.5,5}};
    PolyArray b={{-1.2,0},{2.5,1},{3.2,3},{2.5,5},{5.4,10}};
    CreateListR(ha,a,4);
    CreateListR(hb,b,5);
    printf("ԭ����ʽA:   ");DispPoly(ha);
    printf("ԭ����ʽB:   ");DispPoly(hb);
    Sort(ha);
    Sort(hb);
    printf("�������ʽ:  ");DispPoly(ha);
    printf("�������ʽ�� ");DispPoly(hb);
    Add(ha,hb,hc);
    printf("����ʽ��ӣ� ");DispPoly(hc);
    DestroyList(ha);
    DestroyList(hb);
    DestroyList(hc);
    return 0;
}
