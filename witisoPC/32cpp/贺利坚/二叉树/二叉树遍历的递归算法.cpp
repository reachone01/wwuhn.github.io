#include <stdio.h>
#include "btree.h"

void PreOrder(BTNode *b)        //��������ĵݹ��㷨
{
    if (b!=NULL)
    {
        printf("%c ",b->data);  //���ʸ��ڵ�
        PreOrder(b->lchild);    //�ݹ����������
        PreOrder(b->rchild);    //�ݹ����������
    }
}

void InOrder(BTNode *b)         //��������ĵݹ��㷨
{
    if (b!=NULL)
    {
        InOrder(b->lchild);     //�ݹ����������
        printf("%c ",b->data);  //���ʸ��ڵ�
        InOrder(b->rchild);     //�ݹ����������
    }
}

void PostOrder(BTNode *b)       //��������ĵݹ��㷨
{
    if (b!=NULL)
    {
        PostOrder(b->lchild);   //�ݹ����������
        PostOrder(b->rchild);   //�ݹ����������
        printf("%c ",b->data);  //���ʸ��ڵ�
    }
}

int main()
{
    BTNode *b;
    CreateBTNode(b,"A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))");
    printf("������b:");
    DispBTNode(b);
    printf("\n");
    printf("�����������:\n");
    PreOrder(b);
    printf("\n");
    printf("�����������:\n");
    InOrder(b);
    printf("\n");
    printf("�����������:\n");
    PostOrder(b);
    printf("\n");
    DestroyBTNode(b);
    printf("-endl-");
    while(1);
    return 0;
}
