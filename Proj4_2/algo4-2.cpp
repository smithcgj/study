#include<stdio.h>
#include<malloc.h>
typedef struct snode
{
    char data;
    struct snode * next;
}LiString;
void StrAssign(LiString *&s,char cstr[])
{
    int i;
    LiString *r,*p;
    s=(LiString *)malloc(sizeof(LiString));
    r=s;
    for(i=0;cstr[i]!='\0';i++)
    {
        p=(LiString *)malloc(sizeof(LiString));
        p->data =cstr[i];
        r->next=p;r=p;
    }
    r->next=NULL;
}
void StrCopy(LiString *&s,LiString *t)
{
    LiString *p=t->next,*q,*r;
    s=(LiString *)malloc(sizeof(LiString));
    r=s;
    while(p!=NULL)
    {
        q=(LiString *)malloc(sizeof(LiString));
        q->data =p->data;
        r->next=q;r=q;
        p=p->next;
    }
    r->next=NULL;
}
bool StrEqual(LiString *s,LiString *t)
{
    LiString *p=s->next,*q=t->next;
    while(p!=NULL&&q!=NULL&&p->data==q->data)
    {
        p=p->next;
        q=q->next;
    }
    if(p==NULL&&q==NULL)
        return true;
    else
        return false;
}
int StrLength(LiString *s)
{
    int i=0;
    LiString *p=s->next;
    while(p!=NULL)
    {
        i++;
        p=p->next;
    }
    return i;
}
LiString * Concat(LiString *s,LiString *t)
{
    LiString *str,*p=s->next,*q,*r;
    str =(LiString *)malloc(sizeof(LiString));
    r=str;
    while(p!=NULL)
    {
        q=(LiString *)malloc(sizeof(LiString));
        q->data=p->data;
        r->next=q;r=q;
        p=p->next;
    }
    r->next=NULL;
    return str;
}
LiString * SubStr(LiString *s,int i,int j)
{
    int k;
    LiString *str,*p=s->next,*q,*r;
    str=(LiString *)malloc(sizeof(LiString));
    str->next=NULL;
    r=str;
    if(i<=0||i>StrLength(s)||j<0||i+j-1>StrLength(s))
        return str;
    for(k=0;k<i-1;k++)
        p=p->next;
    for(k=1;k<=j;k++)
    {
        q=(LiString *)malloc(sizeof(LiString));
        q->data=p->data;
        r->next=q;r=q;
        p=p->next;
    }
    r->next=NULL;
    return str;
}
LiString * InStr(LiString *s,int i,LiString *t)
{
    int k;
    LiString *str,*p=s->next,*p1=t->next,*q,*r;
    str=(LiString *)malloc(sizeof(LiString));
    str->next=NULL;
    r=str;
    if(i<=0||i>StrLength(s)+1)
        return str;
    for(k=1;k<i;k++)
    {
        q=(LiString *)malloc(sizeof(LiString));
        q->data=p->data;
        r->next=q;r=q;
        p=p->next;
    }
    while(p1!=NULL)
    {
        q=(LiString *)malloc(sizeof(LiString));
        q->data=p1->data;
        r->next=q;r=q;
        p1=p1->next;
    }
    while(p!=NULL)
    {
        q=(LiString *)malloc(sizeof(LiString));
        q->data=p->data;
        r->next=q;r=q;
        p=p->next;
    }
    r->next=NULL;
    return str;
}
LiString * DelStr(LiString *s,int i,int j)
{
    int k;
    LiString * str,*p=s->next,*q,*r;
    str=(LiString *)malloc(sizeof(LiString));
    str->next=NULL;
    r=str;
    if(i<=0||i>StrLength(s)||j<0||i+j-1>StrLength(s))
        return str;
    for(k=0;k<i-1;k++)
    {
        q=(LiString *)malloc(sizeof(LiString));
        q->data=p->data;
        r->next=q;r=q;
        p=p->next;
    }
    for(k=0;k<j;k++)
        p=p->next;
    while(p!=NULL)
    {
        q=(LiString *)malloc(sizeof(LiString));
        q->data=p->data;
        r->next=q;r=q;
        p=p->next;
    }
    r->next=NULL;
    return str;
}
LiString *RepStr(LiString *s,int i,int j,LiString *t)
{
    int k;
    LiString *str,*p=s->next,*p1=t->next,*q,*r;
    str=(LiString *)malloc(sizeof(LiString));
    str->next=NULL;
    r=str;
    if(i<=0||i>StrLength(s)||j<0||i+j-1>StrLength(s))
        return str;
    for(k=0;k<i-1;k++)
    {
        q=(LiString *)malloc(sizeof(LiString));
        q->data=p->data;q->next=NULL;
        r->next=q;r=q;
        p=p->next;
    }
    for(k=0;k<j;k++)
        p=p->next;
    while(p1!=NULL)
    {
        q=(LiString *)malloc(sizeof(LiString));
        q->data=p1->data;q->next=NULL;
        r->next=q;r=q;
        p1=p1->next;
    }
    while(p!=NULL)
    {
        q=(LiString *)malloc(sizeof(LiString));
        q->data=p->data;q->next=NULL;
        r->next=q;r=q;
        p=p->next;
    }
    r->next=NULL;
    return str;
}
void DispStr(LiString *s)
{
    LiString *p=s->next;
    while(p!=NULL)
    {
        printf("%c",p->data);
        p=p->next;
    }
    printf("\n");
}

