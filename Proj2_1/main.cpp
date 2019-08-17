#include<stdio.h>
#include<malloc.h>
#define MaxSize 50
typedef char ElemType;
typedef struct
{
    ElemType data[MaxSize];
    int length;
}Sqlist;
extern void InitList(Sqlist * &L);
extern void DestroyList(Sqlist * L);
extern bool ListEmpty(Sqlist * L);
extern int ListLength(Sqlist * L);
extern void DispList(Sqlist * L);
extern bool GetElem(Sqlist * L,int i,ElemType &e);
extern int LocateElem(Sqlist * L,ElemType e);
extern bool ListInsert(Sqlist * &L,int i,ElemType e);
extern bool ListDelete(Sqlist * &L,int i,ElemType &e);
int  main()
{
    Sqlist * L;
    ElemType e;
    printf("˳���Ļ�����������\n");
    printf("\t(1)��ʼ��˳���L\n");
    InitList(L);
    printf("\t(2)���β���β�巨���� a,b,c,d,eԪ��\n");
    ListInsert(L,1,'a');
    ListInsert(L,2,'b');
    ListInsert(L,3,'c');
    ListInsert(L,4,'d');
    ListInsert(L,5,'e');
    printf("\t(3)���˳���L:");
    DispList(L);
    printf("\t(4)˳���L�ĳ���=%d\n",ListLength(L));
    printf("\t(5)˳���LΪ%s\n",(ListEmpty(L)?"��":"�ǿ�"));
    GetElem(L,3,e);
    printf("\t(6)˳���L�ĵ�3��Ԫ��=%c\n",e);
    printf("\t(7)Ԫ��a��λ��=%d\n",LocateElem(L,'a'));
    printf("\t(8)�ڵ�4��Ԫ��λ���ϲ���fԪ��\n");
    ListInsert(L,4,'f');
    printf("\t(9)���˳���L:");
    DispList(L);
    printf("\t(10)ɾ��L�ĵ�3��Ԫ��\n");
    ListDelete(L,3,e);
    printf("\t(11)���˳���L:");
    DispList(L);
    printf("\t(12)�ͷ�˳���L\n");
    DestroyList(L);
    return 0;
}
