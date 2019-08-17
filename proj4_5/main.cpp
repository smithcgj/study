#include<stdio.h>
#include<string.h>
#include<malloc.h>
#define MaxSize 100
typedef struct
{
    char data[MaxSize];
    int length;
}SqString;
extern void StrAssign(SqString& s, char cstr[]);
extern void DispStr(SqString s);
SqString * MaxSubstr(SqString s)
{
    SqString *sp;
    int index = 0,length=0,length1,i=0,j,k;
    while(i<s.length)
    {
        j= i+1;
        while(j<s.length)
        {
            if(s.data[i]==s.data[j])
            {
                      length1=1;
            for(k=1;s.data[i+k] == s.data[j+k];k++)
                length1++;
            if(length1>length)
            {
                index=i;
                length=length1;
            }
            j+=length1;
            }
             else
                j++;
        }
     i++;
    }
    sp=(SqString *)malloc(sizeof(SqString));
    sp->length=length;
    for(i=0;i<length;i++)
        sp->data[i]=s.data[index+i];
    return sp;
}
int main()
{
    char str[MaxSize];
    SqString s,*sp;
    printf("输入串:");
    gets(str);
    StrAssign(s,str);
    sp=MaxSubstr(s);
    printf("求最长重复子串:\n");
    printf("    原串:");
    DispStr(s);
    printf("  最长重复子串:");
    DispStr(*sp);
    return 0;
}
