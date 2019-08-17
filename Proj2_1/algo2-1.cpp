#include<stdio.h>
#include<malloc.h>
#define MaxSize 50
typedef char ElemType;
typedef struct
{
    ElemType data[MaxSize];
    int length;
}Sqlist;
void InitList(Sqlist *&L)//��ʼ�����Ա�
{
    L=(Sqlist * )malloc(sizeof(Sqlist));//���������Ա�Ŀռ�
    L->length=0;            //�ÿ����Ա���Ϊ0
}
void DestroyList(Sqlist * L)//�������Ա�
{
    free(L);
}
bool ListEmpty(Sqlist * L)//�ж����Ա��Ƿ�Ϊ�ձ�
{
    return (L->length==0);
}
int ListLength(Sqlist * L)//�����Ա�ĳ���
{
    return (L->length);
}
void DispList(Sqlist * L)//������Ա�
{   int i;
    if(ListEmpty(L)) return;
    for(i=0;i<L->length;i++)
        printf("%c",L->data[i]);
    printf("\n");
}
bool GetElem(Sqlist * L,int i, ElemType &e)//�����Ա���ĳ������Ԫ��ֵ
{
    if(i<1||i>L->length)
        return false;//��������ʱ����false
    e=L->data[i-1];//ȡԪ��ֵ
    return true;//�ɹ��ҵ�Ԫ��ʱ����ture
}
int LocateElem(Sqlist * L,ElemType e)//��Ԫ��ֵ����
{
    int i=0;
    while(i<L->length&&L->data[i]!=e)
        i++;//����Ԫ��e
    if(i>=L->length)//δ�ҵ�ʱ����0
        return 0;
    else
        return i+1;//�ҵ�ʱ�����߼����
}
bool ListInsert(Sqlist * &L,int i,ElemType e)//��������Ԫ��
{
    int j;
    if(i<1||i>L->length+1)
        return false;//��������ʱ����false
    i--;//��˳����߼����ת��Ϊ�������
    for(j=L->length;j>i;j--)//��data[i]������Ԫ�غ���һλ
        L->data[j]=L->data[j-1];
        L->data[i]=e;//����e
        L->length++;//˳�������1
        return true;//�ɹ����벢����true
    }
    bool ListDelete(Sqlist * &L,int i,ElemType &e)//ɾ������Ԫ��
    {
        int j;
        if(i<1||i>L->length)//��������ʱ����false
            return false;
        i--;//��˳����߼����ת��Ϊ�������
        e=L->data[i];
        for(j=i;j<L->length-1;j++)//��data[i]֮���Ԫ��ǰ��һ��λ��
            L->data[j]=L->data[j+1];
        L->length--;//˳����ȼ�һ
        return true;//�ɹ�ɾ������true
    }
