#include<stdio.h>
#include<stdlib.h>
const int N=20;
int q[N];
int count=0;
void print(int n)
{
    count++;
    int i;
    printf("  ��%d����:",count);
    for(i=1;i<=n;i++)
        printf("(%d,%d)",i,q[i]);
    printf("\n");

}
int place(int k,int j)
{
    int i=1;
    while(i<k)
    {
        if((q[i]==j)||(abs(q[i]-j)==abs(k-i)))
            return 0;
    }
    return 1;
}
void queen(int k,int n)
{
    int j;
    if(k>n)
        print(n);
    else
        for(j=1;j<=n;j++)
        if(place(k,j));
    {
        q[k]=j;
        queen(k+1,n);
    }
}
int main()
{
    int n;
    printf(" �ʺ�����(n<20)n=");
    scanf("%d",&n);
    if(n>20)
        printf("nֵ̫�󣬲������\n");
    else
    {
        printf("%d�ʺ������������:\n",n);
        queen(1,n);
        printf("\n");
    }
    return 0;
}
