#include<stdio.h>
#define M 4
#define N 4
void MinMax(int a[M][N])
{
    int i,j;
    bool have=false;
    int min[M],max[N];
    for(i=0;i<M;i++)//�����ÿ�е���СֵԪ�أ�����min[0,...,m-1]֮��
    {
        min[i]=a[i][0];
        for(j=1;j<N;j++)
            if(a[i][j]<min[i])
            min[i]=a[i][j];
    }
    for(j=0;j<N;j++)//�����ÿ�е����ֵԪ�أ�����max[0,...,N-1]֮��
    {
        max[j]=a[0][j];
        for(i=0;i<M;i++)
            if(a[i][j]>max[j])
            max[j]=a[i][j];
    }
    for(i=0;i<M;i++)//�ж��Ƿ�Ϊ����
        for(j=0;j<N;j++)
            if(min[i]==max[j])
    {
        printf("  a[%d][%d]=%d\n",i,j,a[i][j]);
        have=true;
    }
    if(!have)
        printf("û�а���");
}
int main()
{
    int i,j;
    int a[M][N]={{9,7,6,8},{20,26,22,25},{28,36,25,30},{12,4,2,6}};
    printf("a����:\n");
    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
            printf("%4d",a[i][j]);
            printf("\n");
    }
    printf("a�����еİ����:\n");
    MinMax(a);
    return 0;
}
