#include<stdio.h>
#include<malloc.h>
#define MaxSize 100
typedef char ElemType;
typedef struct
{
    ElemType data[MaxSize];
    int top;//ջ��ָ��
}SqStack;
extern void InitStack(SqStack *&s);
extern void DestroyStack(SqStack * &s);
extern bool StackEmpty(SqStack *s);
extern bool Push(SqStack * &s,ElemType e);
extern bool Pop(SqStack * &s,ElemType &e);
extern bool GetTop(SqStack *s,ElemType &e);
int main()
{
    ElemType e;
    SqStack *s;
    printf("ջs�Ļ�����������:\n");
    printf("  (1)��ʼ��ջs\n");
    InitStack(s);
    printf("  (2)ջΪ%s\n",(StackEmpty(s)?"��":"�ǿ�"));
    printf("  (3)���ν�ջԪ��a,b,c,d,e\n");
    Push(s,'a');
    Push(s,'b');
    Push(s,'c');
    Push(s,'d');
    Push(s,'e');
    printf("  (4)ջΪ%s\n",(StackEmpty(s)?"��":"�ǿ�"));
    printf("  (5)��ջ����:");
    while(!StackEmpty(s))
    {
        Pop(s,e);
        printf("%c",e);
    }
    printf("\n");
     printf("  (6)ջΪ%s\n",(StackEmpty(s)?"��":"�ǿ�"));
     printf("  (7)�ͷ�ջ\n");
     DestroyStack(s);
    return 0;
}
