#include <stdio.h>
#define M 4//����
#define N 4//����
#define MaxSize 100//ջ���Ԫ�صĸ���
int mg[M+2][N+2]={//һ���Թ�������Ҫ���Ͼ�Ϊ1�����
    {1,1,1,1,1,1},{1,0,0,0,1,1},{1,0,1,0,0,1},
    {1,0,0,0,1,1},{1,1,0,0,0,1},{1,1,1,1,1,1}
};
struct
{
 int i,j;
 int di;
}Stack[MaxSize],Path[MaxSize];//����ջ�ʹ�����·��������
int top=-1;//ջ��ָ��
int count=1;//·��������
int minlen=MaxSize;//���·������
void mgpath(int xi,int yi,int xe,int ye)//���Թ�·��
{
    int i,j,di,find,k;
    top++;//��ջ
    Stack[top].i=xi;
    Stack[top].j=yi;
    Stack[top].di=-1;mg[xi][yi]=-1;//��ʼ�������ջ
    while(top>-1)//ջ����ʱѭ��
    {
        i=Stack[top].i;j=Stack[top].j;di=Stack[top].di;
        if(i==xe&&j==ye)//�ҵ��˳��ڣ����·��
        {
            printf("%4d��",count++);
            for(k=0;k<=top;k++)
            {
                printf("(%d,%d)  ",Stack[k].i,Stack[k].j);
                if((k+1)%5==0)//���ʱÿ5�����黻һ��
                    printf("\n\t");
            }
            printf("\n");
            if(top+1<minlen)//�Ƚ������·��
            {
                for(k=0;k<=top;k++)
                    Path[k]=Stack[k];
                minlen=top+1;
            }
            mg[Stack[top].i][Stack[top].j]=0;//�ø�λ�ñ�Ϊ����·�����߽ڵ�
            top--;
            i=Stack[top].i;j=Stack[top].j;di=Stack[top].di;
        }
        find=0;
        while(di<4&&find==0)
        {
            di++;
            switch(di)
            {
                case 0:i=Stack[top].i-1;j=Stack[top].j;break;
                case 1:i=Stack[top].i;j=Stack[top].j+1;break;
                case 2:i=Stack[top].i+1;j=Stack[top].j;break;
                case 3:i=Stack[top].i;j=Stack[top].j-1;break;
            }
            if(mg[i][j]==0) find=1;
        }
        if(find==1)//�ҵ�����һ�����߷���
        {
            Stack[top].di=di;//�޸�ԭջ��Ԫ�ص�diֵ
            top++;Stack[top].i=i;Stack[top].j=j;Stack[top].di=-1;//��һ�����߽ڵ��ջ
            mg[i][j]=-1;//�����ظ��ߵ��÷���
        }
        else//û��·�����ߣ�����ջ
        {
            mg[Stack[top].i][Stack[top].j]=0;//�ø�λ�ñ�Ϊ����·�����߷���
            top--;
        }
    }
    printf("���·������:\n");
    printf("���ȣ� %d\n",minlen);
    printf("·���� ");
    for(k=0;k<minlen;k++)
    {
        printf("(%d,%d) ",Path[k].i,Path[k].j);
        if((k+1)%5==0) printf("\n\t");//���ʱÿ5�����黻һ��
    }
    printf("\n");
}
int main()
{
   printf("�Թ�����·�����£�\n");
   mgpath(1,1,M,N);
    return 0;
}
