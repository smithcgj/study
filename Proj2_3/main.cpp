#include<stdio.h>
#include<malloc.h>
typedef char ElemType;
typedef struct DNode//定义双链表节点
{
    ElemType data;
    struct DNode * prior;//指向前驱节点
    struct DNode * next;//指向后继节点
}DLinkList;
extern void InitList(DLinkList * &L);//以下均为外部函数
extern void DestroyList(DLinkList * &L);
extern bool ListEmpty(DLinkList *L);
extern int ListLength(DLinkList *L);
extern void DispList(DLinkList * L);
extern bool GetElem(DLinkList * L,int i,ElemType &e);
extern int LocateElem(DLinkList *L,ElemType e);
extern bool ListINsert(DLinkList * &L,int i,ElemType e);
extern bool ListDelete(DLinkList * &L,int i,ElemType &e);
int main()
{
    DLinkList * h;
    ElemType e;
    printf("双链表的基本运算如下：\n");
    printf("\t(1)初始化双链表h\n");
    InitList(h);
    printf("\t(2)依次采用尾插法插入a,b,c,d,e元素\n");
    ListINsert(h,1,'a');
    ListINsert(h,2,'b');
    ListINsert(h,3,'c');
    ListINsert(h,4,'d');
    ListINsert(h,5,'e');
    printf("\t(3)输出双链表h：");
    DispList(h);
    printf("\t(4)双链表h的长度=%d\n",ListLength(h));
    printf("\t(5)双链表h为%s\n",(ListEmpty(h)?"空":"非空"));
    GetElem(h,3,e);
    printf("\t(6)双链表h的第3个元素=%c\n",e);
    printf("\t(7)元素a的位置=%d\n",LocateElem(h,'a'));
    printf("\t(8)在第4个元素位置上插入f元素\n");
    ListINsert(h,4,'f');
    printf("\t(9)输出双链表h:");
    DispList(h);
    printf("\t(10)删除h的第3个元素\n");
    ListDelete(h,3,e);
    printf("\t(11)输出双链表h：");
    DispList(h);
    printf("\t(12)释放双链表h\n");
    DestroyList(h);
    return 0;
}
