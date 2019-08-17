#include<stdio.h>
#include<malloc.h>
typedef char ElemType;
typedef struct LNode//���嵥����ڵ�����
{
    ElemType data;
    struct LNode *next;
}LinkList;
extern void InitList(LinkList * &L);
extern void DestroyList(LinkList * &L);
extern bool ListEmpty(LinkList * L);
extern int ListLength(LinkList * L);
extern void DispList(LinkList * L);
extern bool GetElem(LinkList * L,int i,ElemType &e);
extern int LocateELem(LinkList * L,ElemType e);
extern bool ListInsert(LinkList * &L,int i,ElemType e);
extern bool ListDelete(LinkList * &L,int i,ElemType &e);
int  main()
{
    LinkList *h;
    ElemType e;
    printf("������Ļ����㷨���£�\n");
    printf("\t(1)��ʼ��������h\n");
    InitList(h);
    printf("\t(2)���β���β�巨����a,b,c,d,eԪ��\n");
    ListInsert(h,1,'a');
    ListInsert(h,2,'b');
    ListInsert(h,3,'c');
    ListInsert(h,4,'d');
    ListInsert(h,5,'e');
    printf("\t(3)���������h��");
    DispList(h);
    printf("\t(4)������h�ĳ���=%d\n",ListLength(h));
    printf("\t(5)������hΪ%s\n",(ListEmpty(h)?"��":"�ǿ�"));
    GetElem(h,3,e);
    printf("\t(6)������h�ĵ�3��Ԫ��=%c\n",e);
    printf("\t(7)Ԫ��a��λ��=%d\n",LocateELem(h,'a'));
    printf("\t(8)�ڵ�4��Ԫ��λ���ϲ���fԪ��\n");
    ListInsert(h,4,'f');
    printf("\t(9)���������h��");
    DispList(h);
    printf("\t(10)ɾ��h�ĵ�3��Ԫ��\n");
    ListDelete(h,3,e);
    printf("\t(11)���������h:");
    DispList(h);
    printf("\t(12)�ͷŵ�����h\n");
    DestroyList(h);
    return 0;
}
