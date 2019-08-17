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
    printf("顺序表的基本运算如下\n");
    printf("\t(1)初始化顺序表L\n");
    InitList(L);
    printf("\t(2)依次采用尾插法插入 a,b,c,d,e元素\n");
    ListInsert(L,1,'a');
    ListInsert(L,2,'b');
    ListInsert(L,3,'c');
    ListInsert(L,4,'d');
    ListInsert(L,5,'e');
    printf("\t(3)输出顺序表L:");
    DispList(L);
    printf("\t(4)顺序表L的长度=%d\n",ListLength(L));
    printf("\t(5)顺序表L为%s\n",(ListEmpty(L)?"空":"非空"));
    GetElem(L,3,e);
    printf("\t(6)顺序表L的第3个元素=%c\n",e);
    printf("\t(7)元素a的位置=%d\n",LocateElem(L,'a'));
    printf("\t(8)在第4个元素位置上插入f元素\n");
    ListInsert(L,4,'f');
    printf("\t(9)输出顺序表L:");
    DispList(L);
    printf("\t(10)删除L的第3个元素\n");
    ListDelete(L,3,e);
    printf("\t(11)输出顺序表L:");
    DispList(L);
    printf("\t(12)释放顺序表L\n");
    DestroyList(L);
    return 0;
}
