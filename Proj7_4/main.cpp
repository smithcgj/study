#include<stdio.h>
#include<malloc.h>
#define MaxSize 100
#define MaxWidth 40
typedef char ElemType;
typedef struct node
{
    ElemType data;//����Ԫ��
    struct node *lchild;//ָ������
    struct node *rchild;//ָ���Һ���
}BTNode;
extern void DispBTNode(BTNode* b);
extern void DestroyBTNode(BTNode*& b);
BTNode * CreateBT1(char *pre,char *in,int n)
{
    BTNode *s;
    char *p;
    int k;
    if(n<=0) return NULL;
    s=(BTNode *)malloc(sizeof(BTNode));//�����������ڵ�*a
    s->data=*pre;
    for(p=in;p<in+n;p++)//�����������ҵ���*ppos��λ��
        if(*p==*pre)
        break;
    k=p-in;
    s->lchild=CreateBT1(pre+1,in,k);
    s->rchild=CreateBT1(pre+k+1,p+1,n-k-1);
    return s;
}
BTNode *CreateBT2(char* post, char* in, int n,int m)
{
    BTNode *s;
    char *p,*q,*maxp;
    int maxpost,maxin,k;
    if(n<=0) return NULL;
    maxpost=-1;
    for(p=in;p<in+n;p++)//��in��ȫ���ַ�����post�����ұߵ��Ǹ��ַ�
        for(q=post;q<post+m;q++)
        //��in����maxpָ������ַ�,��maxin��ʶ����in�е��±�
        if(*p==*q)
        {
            k=q-post;
            if(k>maxpost)
            {
                maxpost=k;
                maxp=p;
                maxin=p-in;
            }
        }
        s=(BTNode *)malloc(sizeof(BTNode));//�����������ڵ�
        s->data=post[maxpost];
        s->lchild=CreateBT2(post,in,maxin,m);
        s->rchild=CreateBT2(post,maxp+1,n-maxin-1,m);
        return s;
}
void DispBTNode1(BTNode* b)//�԰����ʾ�����һ�ö�����
{
    BTNode *St[MaxSize],*p;
    int level[MaxSize][2],top=-1,n,i,width=4;
    char type;
    if(b!=NULL)
    {
        top++;
        St[top]=b;//���ڵ��ջ
        level[top][0]=width;
        level[top][1]=2;//2��ʾ��
        while(top>-1)
        {
            p=St[top];//��ջ��������ʾ�ýڵ�ֵ
            n=level[top][0];
            switch(level[top][1])
            {
                case 0:type='L';break;//��ڵ�֮�����(L)
                case 1:type='R';break;//�ҽڵ�֮�����(R)
                case 2:type='B';break;//���ڵ�֮�����(B)
            }
            for(i=1;i<n;i++)//����nΪ��ʾ����,�ַ����Ҷ�����ʾ
                printf(" ");
            printf("%c(%c)",p->data,type);
            for(i=n+1;i<MaxWidth;i+=2)
                printf("--");
            printf("\n");
            top--;
            if(p->rchild!=NULL)
            {
                top++;//�����������ڵ��ջ
                St[top]=p->rchild;
                level[top][0]=n+width;//��ʾ������width
                level[top][1]=1;//1��ʾ������
            }
            if(p->lchild!=NULL)
            {
                top++;//�����������ڵ��ջ
                St[top]=p->lchild;
                level[top][0]=n+width;//��ʾ������width
                level[top][1]=0;//0��ʾ������
            }
        }
    }
}
int main()
{
    BTNode *b;
    ElemType pre[]="ABDEHJKLMNCFGI";
    ElemType in[]="DBJHLKMNEAFCGI";
    ElemType post[]="DJLNMKHEBFIGCA";
    b=CreateBT1(pre,in,14);
    printf("��������:%s\n",pre);
    printf("��������:%s\n",in);
    printf("����һ�ö�����b:\n");
    printf("  ���ű�ʾ��:");DispBTNode(b);printf("\n");
    printf("  �����ʾ��:\n");DispBTNode1(b);printf("\n\n");
    printf("��������:%s\n",in);
    printf("��������:%s\n",post);
    b=CreateBT2(post,in,14,14);
    printf("����һ�ö�����b:\n");
    printf(" ���ű�ʾ��:");DispBTNode(b);printf("\n");
    printf(" �����ʾ��:\n");DispBTNode1(b);printf("\n\n");
    DestroyBTNode(b);
    return 0;
}
