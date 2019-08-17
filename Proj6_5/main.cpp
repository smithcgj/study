#include<stdio.h>
#include<malloc.h>
typedef char ElemType;
typedef struct lnode
{
    int tag;//节点类型标识
    union
    {
        ElemType data;
        struct lnode *sublist;
    }val;
    struct lnode *link;//指向下一个元素
}GLNode;
GLNode * CreateGL(char * &s)//返回由括号表示法表示s的广义表链式存储结构
{
    GLNode *g;
    char ch=*s++;//取一个字符
    if(ch!='\0')//串末结束判断
    {
        g=(GLNode *)malloc(sizeof(GLNode));//创建一个新节点
        if(ch=='(')//当前字符为左括号时
        {
            g->tag=1;//新节点作为表头节点
            g->val.sublist=CreateGL(s);//递归构造子表并链到表头节点
        }
        else if(ch==')')
            g=NULL;//当遇到')'字符，g置为空
        else if(ch=='#')//遇到'#'字符,表示空表
            g->val.sublist=NULL;
        else//为原子字符
        {
            g->tag=0;//新节点作为原子节点
            g->val.data=ch;
        }
    }
    else//串结束,g置为空
        g=NULL;
    ch=*s++;//取下一个字符
    if(g!=NULL)//串未结束,继续构造兄弟节点
        if(ch==',')//当前字符为','
            g->link=CreateGL(s);//递归构造兄弟节点
        else
            g->link=NULL;//返回广义表g
        return g;
}
int GlLength(GLNode * g)//求广义表g的长度
{
    int n=0;
    g=g->val.sublist;//g指向广义表的第一个元素
    while(g!=NULL)
    {
        n++;
        g=g->link;
    }
    return n;
}
int GLDepth(GLNode *g)//求广义表g的深度
{
    int max=0,dep;
    if(g->tag==0)
        return 0;
    g=g->val.sublist;//g指向第一个元素
    if(g==NULL)
        return 1;
    while(g!=NULL)//遍历表中的每一个元素
    {
        if(g->tag==1)//元素为子表的情况
        {
            dep=GLDepth(g);//递归调用求出子表的深度
            if(dep>max) max=dep;//求元素的最大深度
        }
        g=g->link;//使g指向下个元素
    }
    return (max+1);//返回表的深度
}
void DispGL(GLNode *g)//输出广义表g
{
    if(g!=NULL)//表不为空判断
    {           //先输出g的元素
        if(g->tag==0)//g的元素为原子时
            printf("%c",g->val.data);//输出原子值
        else
        {
            printf("(");//输出'('
            if(g->val.sublist==NULL)//为空表
                printf("#");
            else
                DispGL(g->val.sublist);//递归输出子表
            printf(")");//输出')'
        }
        if(g->link!=NULL)
        {
            printf(",");
            DispGL(g->link);//递归输出g的兄弟
        }
    }
}
ElemType maxatom(GLNode *g)//求广义表g中的最大原子
{
    ElemType max1,max2;
    if(g!=NULL)
    {
        if(g->tag==0)
        {
            max1=maxatom(g->link);
            return (g->val.data>max1?g->val.data:max1);
        }
        else
        {
            max1=maxatom(g->val.sublist);
            max2=maxatom(g->link);
            return (max1>max2?max1:max2);
        }
    }
    else//g为空时返回0
        return 0;
}
int main()
{
    GLNode *g;
    char *str="(b,(b,a,(#),d),((a,b),c,((#))))";
    g=CreateGL(str);
    printf("广义表g:");DispGL(g);printf("\n");
    printf("广义表g的长度:%d\n",GlLength(g));
    printf("广义表g的深度:%d\n",GLDepth(g));
    printf("最大原子:%c\n",maxatom(g));
    return 0;
}
