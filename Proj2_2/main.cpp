#include<stdio.h>
#include<malloc.h>
typedef char ElemType;
typedef struct LNode//定义单链表节点类型
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
    printf("单链表的基本算法如下：\n");
    printf("\t(1)初始化单链表h\n");
    InitList(h);
    printf("\t(2)依次采用尾插法插入a,b,c,d,e元素\n");
    ListInsert(h,1,'a');
    ListInsert(h,2,'b');
    ListInsert(h,3,'c');
    ListInsert(h,4,'d');
    ListInsert(h,5,'e');
    printf("\t(3)输出单链表h：");
    DispList(h);
    printf("\t(4)单链表h的长度=%d\n",ListLength(h));
    printf("\t(5)单链表h为%s\n",(ListEmpty(h)?"空":"非空"));
    GetElem(h,3,e);
    printf("\t(6)单链表h的第3个元素=%c\n",e);
    printf("\t(7)元素a的位置=%d\n",LocateELem(h,'a'));
    printf("\t(8)在第4个元素位置上插入f元素\n");
    ListInsert(h,4,'f');
    printf("\t(9)输出单链表h：");
    DispList(h);
    printf("\t(10)删除h的第3个元素\n");
    ListDelete(h,3,e);
    printf("\t(11)输出单链表h:");
    DispList(h);
    printf("\t(12)释放单链表h\n");
    DestroyList(h);
    return 0;
}
