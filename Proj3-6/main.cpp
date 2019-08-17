#include <stdio.h>
#include<stdlib.h>
#define Maxize 100
typedef struct
{
    int col[Maxize];//coi[i]��ŵ�i���ʺ���к�
    int top;//ջ��ָ��
}StackType;//����˳��ջ����
void dispasolution(StackType st)//���һ����
{
    static int count=0;//��̬��������ͳ�ƽ�ĸ���
    int i;
    printf("��%d����:",++count);
    for(i=1;i<=st.top;i++)
        printf("(%d,%d)",i,st.col[i]);
    printf("\n");
}
int place(StackType st,int k,int j)//���ԣ�k��j���Ƿ���1~k~1�Ļʺ��г�ͻ
{
    int i=1;
    if(k==1) return 1;//�ŵ�һ���ʺ�ʱû�г�ͻ
    while (i<=k-1)//������ǰ���ѷ��õĻʺ��Ƿ��г�ͻ
    {
        if((st.col[i]=j)||(abs(j-st.col[i])==abs(i-k)))
            return 0;//�г�ͻ����0
        i++;
    }
    return 1;
}
void queen(int n)//���n�ʺ�����
{
    int k,j,find;
    StackType st;//����ջst
    st.top=0;//��ʼ��ջ��ָ�룬Ϊ���ûʺ�ӵ�һ�п�ʼ�������±�0
    st.top++;st.col[st.top]=0;//��(1,0)��ջ
    while(st.top!=0)//ջ����ʱѭ��
    {
        k=st.top;//��̽ջ���ĵ�k���ʺ�
        find=0;
        for(j=st.col[k]+1;j<=n;j++)//Ϊ��k���ʺ���һ�����ʵ�λ��
        if(place(st,k,j))//�ڵ�k���ҵ�һ���Żʺ��λ�ã�k��j��
        {
            st.col[st.top]=j;//�޸ĵ�k���ʺ��λ��(���к�)
            find=1;//�ҵ�һ����λ�ú���Ϊ1
            break;//�ҵ����˳�forѭ��
        }
        if(find)//�ڵ�k���ҵ�һ���Żʺ��λ��(k,j)
        {
            if(k==n)//���лʺ���źã����һ����
              dispasolution(st);
            else//���лʺ�δ��ʱ������k+1���ʺ��ջ
            {
                st.top++;
                st.col[st.top]=0;//�½�ջ�Ļʺ�ӵ�0�п�ʼ��̽��
            }
        }
        else//����k���ʺ�û�к��ʵ�λ�ã�����
            st.top--;//������k���ʺ���ջ
    }
}
int main()
{
    int n;//n���ʵ�ʻʺ�ĸ���
    printf("�ʺ�����(n<20)n=");
    scanf("%d",&n);
    if(n>20)
        printf("nֵ̫��\n");
    else
    {
        printf(" %d�ʺ�����������£�\n",n);
        queen(n);
    }
    return 1;
}
