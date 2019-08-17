#include<stdio.h>
#include<malloc.h>
#define MaxSize 100
typedef char ElemType;
typedef struct node
{
    ElemType data;//����Ԫ��
    struct node *lchild;//ָ������
    struct node *rchild;//ָ���Һ���
}BTNode;
extern void CreateBTNode(BTNode*& b, char* str);
extern void DispBTNode(BTNode* b);
extern void DestroyBTNode(BTNode*& b);
void AllPath(BTNode *b)
{
    struct snode
    {
        BTNode *node;//��ŵ�ǰ�ڵ�ָ��
        int parent;//���˫�׽ڵ��ڶ����е�λ��
    }Qu[MaxSize];//����˳�����
    int front,rear,p;//�����ͷ��βָ��
    front=rear=-1;//�ö���Ϊ�ն���
    rear++;
    Qu[rear].node=b;//���ڵ�ָ��������
    Qu[rear].parent=-1;//���ڵ�û��˫��
    while(front<rear)//���в�Ϊ��
    {
        front++;
        b=Qu[front].node;//��ͷ������
        if(b->lchild==NULL&&b->rchild==NULL)//*bΪҶ�ӽڵ�
        {
            printf("  %c�����ڵ���·��:",b->data);
            p=front;
            while(Qu[p].parent!=-1)
            {
                printf("%c",Qu[p].node->data);
                p=Qu[p].parent;
            }
            printf("%c\n",Qu[p].node->data);
        }
        if(b->lchild!=NULL)//���������
        {
            rear++;
            Qu[rear].node=b->lchild;
            Qu[rear].parent=front;
        }
        if(b->rchild!=NULL)//�Һ��������
        {
            rear++;
            Qu[rear].node=b->rchild;
            Qu[rear].parent=front;
        }
    }
}
void AllPath1(BTNode *b,ElemType path[],int pathlen)
{
    int i;
    if(b!=NULL)
    {
        if(b->lchild==NULL&&b->rchild==NULL)//*bΪҶ�ӽڵ�
        {
            printf("  %c�����ڵ���·��:%c",b->data,b->data);
            for(i=pathlen-1;i>=0;i--)
                printf("%c",path[i]);
            printf("\n");
        }
        else
        {
            path[pathlen]=b->data;//����ǰ�ڵ����·����
            pathlen++;//·�����ȼ�1
            AllPath1(b->lchild,path,pathlen);//�ݹ�ɨ��������
            AllPath1(b->rchild,path,pathlen);//�ݹ�ɨ��������
            pathlen--;
        }
    }
}
void LongPath(BTNode *b,ElemType path[],int pathlen,ElemType longpath[],int &longpathlen)
{
    int i;
    if(b==NULL)
    {
        if(pathlen>longpathlen)//����ǰ·������,��·��������longpath��
        {
            for(i=pathlen-1;i>=0;i--)
                longpath[i]=path[i];
            longpathlen=pathlen;
        }
    }
    else
    {
        path[pathlen]=b->data;//����ǰ�ڵ����·����
        pathlen++;//·�����ȼ�1
        LongPath(b->lchild,path,pathlen,longpath,longpathlen);//�ݹ�ɨ��������
        LongPath(b->rchild,path,pathlen,longpath,longpathlen);//�ݹ�ɨ��������
        pathlen--;//�ָ�����
    }
}
void DispLeaf(BTNode *b)
{
    if(b!=NULL)
    {
        if(b->lchild==NULL&&b->rchild==NULL)
            printf("%c",b->data);
        else
        {
            DispLeaf(b->lchild);
            DispLeaf(b->rchild);
        }
    }
}
int main()
{
    BTNode *b;
    ElemType path[MaxSize],longpath[MaxSize];
    int i,longpathlen=0;
    CreateBTNode(b,"A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))");
    printf("������b:");DispBTNode(b);printf("\n");
    printf("b��Ҷ�ӽڵ�:");DispLeaf(b);printf("\n");
    printf("AllPath:\n");AllPath(b);
    printf("AllPath1:\n");AllPath1(b,path,0);
    LongPath(b,path,0,longpath,longpathlen);
    printf("��һ�����·������:%d\n",longpathlen);
    printf("��һ�����·��:");
    for(i=longpathlen-1;i>=0;i--)
        printf("%c",longpath[i]);
    printf("\n");
    DestroyBTNode(b);
    getchar();
    return 0;
}
