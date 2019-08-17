#include<stdio.h>
#include<malloc.h>
typedef char ElemType;
typedef struct DNode//����˫����ڵ�
{
    ElemType data;
    struct DNode * prior;//ָ��ǰ���ڵ�
    struct DNode * next;//ָ���̽ڵ�
}DLinkList;
extern void InitList(DLinkList * &L);//���¾�Ϊ�ⲿ����
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
    printf("˫����Ļ����������£�\n");
    printf("\t(1)��ʼ��˫����h\n");
    InitList(h);
    printf("\t(2)���β���β�巨����a,b,c,d,eԪ��\n");
    ListINsert(h,1,'a');
    ListINsert(h,2,'b');
    ListINsert(h,3,'c');
    ListINsert(h,4,'d');
    ListINsert(h,5,'e');
    printf("\t(3)���˫����h��");
    DispList(h);
    printf("\t(4)˫����h�ĳ���=%d\n",ListLength(h));
    printf("\t(5)˫����hΪ%s\n",(ListEmpty(h)?"��":"�ǿ�"));
    GetElem(h,3,e);
    printf("\t(6)˫����h�ĵ�3��Ԫ��=%c\n",e);
    printf("\t(7)Ԫ��a��λ��=%d\n",LocateElem(h,'a'));
    printf("\t(8)�ڵ�4��Ԫ��λ���ϲ���fԪ��\n");
    ListINsert(h,4,'f');
    printf("\t(9)���˫����h:");
    DispList(h);
    printf("\t(10)ɾ��h�ĵ�3��Ԫ��\n");
    ListDelete(h,3,e);
    printf("\t(11)���˫����h��");
    DispList(h);
    printf("\t(12)�ͷ�˫����h\n");
    DestroyList(h);
    return 0;
}
