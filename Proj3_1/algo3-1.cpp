#include<stdio.h>
#include<malloc.h>
#define MaxSize 100
typedef char ElemType;
typedef struct
{
    ElemType data[MaxSize];
    int top;//ջ��ָ��
}SqStack;
void InitStack(SqStack * &s)//��ʼ��ջs
{
    s=(SqStack *)malloc(sizeof(SqStack));
    s->top=-1;//ջ��ָ����Ϊ-1
}
void DestroyStack(SqStack * &s)//����ջs
{
    free(s);
}
bool StackEmpty(SqStack * s)//�ж�ջ��
{
    return(s->top==-1);
}
bool Push(SqStack * &s,ElemType e)//��ջ
{
    if(s->top==MaxSize-1)//ջ�����������ջ�����
        return false;
    s->top++;//ջ��ָ����1
    s->data[s->top]=e;//Ԫ��e����ջ��ָ�봦
    return true;
}
bool Pop(SqStack *&s,ElemType &e)//��ջ
{
    if(s->top==-1)//ջΪ�յ��������ջ�����
        return false;
    e=s->data[s->top];//ȡջ��ָ��Ԫ�ص�Ԫ��
    s->top--;//ջ��ָ���1
    return true;
}
bool GetTop(SqStack *s,ElemType &e)//ȡջ��Ԫ��
{
    if(s->top==-1)//ջΪ�յ��������ջ���
    return false;
    e=s->data[s->top];//ȡջ��ָ��Ԫ�ص�Ԫ��
    return true;
}
