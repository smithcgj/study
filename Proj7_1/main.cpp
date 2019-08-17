#include<stdio.h>
#include<malloc.h>
typedef char ElemType;
typedef struct node
{
    ElemType data;//����Ԫ��
    struct node * lchild;//ָ������
    struct node * rchild;//ָ���Һ���
}BTNode;
extern void CreateBTNode(BTNode*& b, char* str);
extern BTNode * FindNode(BTNode* b, ElemType x);
extern BTNode * LchidNode(BTNode* p);
extern BTNode * RchildNode(BTNode* p);
extern int BTNodeDEpth(BTNode* b);
extern void DispBTNode(BTNode* b);
extern int BTWidth(BTNode* b);
extern int Nodes(BTNode* b);
extern int LeafNode(BTNode* b);
extern void DestroyBTNode(BTNode*& b);
int main()
{
    BTNode *b,*p,*lp,*rp;
    CreateBTNode(b,"A(B(D,E(H(J,K(L,M(,N))))),c(F,G(,I)))");
    printf("�������Ļ�����������:\n");
    printf("  (1)���������:");DispBTNode(b);printf("\n");
    printf("  (2)H�ڵ�:");
    p=FindNode(b,'H');
    if(p!=NULL)
    {
        lp=LchidNode(p);
        if(lp!=NULL)
            printf("����Ϊ%c",lp->data);
        else
            printf("������");
        rp=RchildNode(p);
        if(rp!=NULL)
            printf("�Һ���Ϊ%c",rp->data);
        else
            printf("���Һ���");
    }
    printf("\n");
    printf("  (3)������b�����:%d\n",BTNodeDEpth(b));
    printf("  (4)������b�Ŀ��:%d\n",BTWidth(b));
    printf("  (5)������b�Ľڵ����:%d\n",Nodes(b));
    printf("  (6)������b��Ҷ�ӽڵ����:%d\n",LeafNode(b));
    printf("  (7)�ͷŶ�����b\n");
    DestroyBTNode(b);
    return 0;
}
