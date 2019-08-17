#include<stdio.h>
#define M 4
#define N 4
void MinMax(int a[M][N])
{
    int i,j;
    bool have=false;
    int min[M],max[N];
    for(i=0;i<M;i++)//计算出每行的最小值元素，放入min[0,...,m-1]之中
    {
        min[i]=a[i][0];
        for(j=1;j<N;j++)
            if(a[i][j]<min[i])
            min[i]=a[i][j];
    }
    for(j=0;j<N;j++)//计算出每列的最大值元素，放入max[0,...,N-1]之中
    {
        max[j]=a[0][j];
        for(i=0;i<M;i++)
            if(a[i][j]>max[j])
            max[j]=a[i][j];
    }
    for(i=0;i<M;i++)//判定是否为马鞍点
        for(j=0;j<N;j++)
            if(min[i]==max[j])
    {
        printf("  a[%d][%d]=%d\n",i,j,a[i][j]);
        have=true;
    }
    if(!have)
        printf("没有鞍点");
}
int main()
{
    int i,j;
    int a[M][N]={{9,7,6,8},{20,26,22,25},{28,36,25,30},{12,4,2,6}};
    printf("a矩阵:\n");
    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
            printf("%4d",a[i][j]);
            printf("\n");
    }
    printf("a矩阵中的鞍马点:\n");
    MinMax(a);
    return 0;
}
