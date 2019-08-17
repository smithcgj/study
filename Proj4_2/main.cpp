#include<stdio.h>
#include<malloc.h>
typedef struct snode
{
    char data;
    struct snode *next;
}LiString;
extern void StrAssign(LiString*& s, char cstr[]);
extern void StrCopy(LiString*& s, LiString* t);
extern bool StrEqual(LiString* s, LiString* t);
extern int StrLength(LiString* s);
extern LiString * Concat(LiString* s, LiString* t);
extern LiString *SubStr(LiString* s, int i, int j);
extern LiString *InStr(LiString* s, int i, LiString* t);
extern LiString *DelStr(LiString* s, int i, int j);
extern LiString *RepStr(LiString* s, int i, int j, LiString* t);
extern void DispStr(LiString* s);
int main()
{
    LiString *s,*s1,*s2,*s3,*s4;
    printf("�����Ļ�����������:\n");
    printf("  (1)������s�ʹ�s1\n");
    StrAssign(s,"abcdefghijklmn");
    StrAssign(s1,"123");
    printf("  (2)�����s:");DispStr(s);
    printf("  (3)��s�ĳ���:%d\n",StrLength(s));
    printf("  (4)�ڴ�s��9���ַ�λ�ò��봮s1��������s2\n");
    s2=InStr(s,9,s1);
    printf("  (5)�����s2:");DispStr(s2);
    printf("  (6)ɾ����s�ĵ�2���ַ���ʼ��5���ַ���������s2\n");
    s2=DelStr(s,2,3);;
    printf("  (7)�����s2:");DispStr(s2);
    printf("  (8)����s��2���ַ���ʼ��5���ַ��滻�ɴ�s1��������s2\n");
    s2=RepStr(s,2,5,s1);
    printf("  (9)�����s2:");DispStr(s2);
    printf("  (10)��ȡ��s�ĵ�2���ַ���ʼ��10���ַ���������s3\n");
    s3=SubStr(s,2,10);
    printf("  (11)�����s3:");DispStr(s3);
    printf("  (12)����s1��s2����������������s4\n");
    s4=Concat(s1,s2);
    printf("  (13)�����s4:");DispStr(s4);
    return 0;
}
