#include <stdio.h>
#include "btree.h"

int Nodes(BTNode *b)
{
    if (b==NULL)
        return 0;
    else
        return Nodes(b->lchild)+Nodes(b->rchild)+1;
}

void treeHeight()
{
    BTNode *b;
    CreateBTNode(b,"A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))");
    printf("�������ڵ����: %d\n", Nodes(b));
    DestroyBTNode(b);
}




void DispLeaf(BTNode *b)
{
    if (b!=NULL)
    {
        if (b->lchild==NULL && b->rchild==NULL)
            printf("%c ",b->data);
        else
        {
            DispLeaf(b->lchild);
            DispLeaf(b->rchild);
        }
    }
}

void printLeaf()
{
    BTNode *b;
    CreateBTNode(b,"A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))");
    printf("�����������е�Ҷ�ӽڵ���: ");
    DispLeaf(b);
    printf("\n");
    DestroyBTNode(b);

}


int LeafNodes(BTNode *b)    //�������b��Ҷ�ӽڵ����
{
    int num1,num2;
    if (b==NULL)
        return 0;
    else if (b->lchild==NULL && b->rchild==NULL)
        return 1;
    else
    {
        num1=LeafNodes(b->lchild);
        num2=LeafNodes(b->rchild);
        return (num1+num2);
    }
}

void LeafNodesCal()
{
    BTNode *b;
    CreateBTNode(b,"A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))");
    printf("������b��Ҷ�ӽڵ����: %d\n",LeafNodes(b));
    DestroyBTNode(b);
}
//���һ���㷨Level(b,x,h)�����ض�����b��dataֵΪx�Ľڵ�Ĳ�����


int Level(BTNode *b,ElemType x,int h)
{
    int l;
    if (b==NULL)
        return 0;
    else if (b->data==x)
        return h;
    else
    {
        l=Level(b->lchild,x,h+1);
        if (l==0)
            return Level(b->rchild,x,h+1);
        else
            return l;
    }
}

void levelCal()
{
    BTNode *b;
    CreateBTNode(b,"A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))");
    printf("ֵΪ\'K\'�Ľڵ��ڶ������г����ڵ� %d ����n",Level(b,'K',1));
    DestroyBTNode(b);
}
/*
��5���ж϶������Ƿ����ƣ����ڶ�����t1��t2���Ƶ��жϣ�
��t1��t2���ǿյĶ����������ƣ�
��t1��t2֮һΪ�գ���һ��Ϊ�գ������ƣ�
��t1����������t2�������������Ƶģ���t1������
����t2�������������Ƶģ���t1��t2���ơ���
*/
#include <stdio.h>
#include "btree.h"

int Like(BTNode *b1,BTNode *b2)
{
    int like1,like2;
    if (b1==NULL && b2==NULL)
        return 1;
    else if (b1==NULL || b2==NULL)
        return 0;
    else
    {
        like1=Like(b1->lchild,b2->lchild);
        like2=Like(b1->rchild,b2->rchild);
        return (like1 & like2);
    }
}

void likeTest()
{
    BTNode *b1, *b2, *b3;
    CreateBTNode(b1,"B(D,E(H(J,K(L,M(,N)))))");
    CreateBTNode(b2,"A(B(D(,G)),C(E,F))");
    CreateBTNode(b3,"u(v(w(,x)),y(z,p))");
    if(Like(b1, b2))
        printf("b1��b2����\n");
    else
        printf("b1��b2������\n");
    if(Like(b2, b3))
        printf("b2��b3����\n");
    else
        printf("b2��b3������\n");
    DestroyBTNode(b1);
    DestroyBTNode(b2);
    DestroyBTNode(b3);

}
int main()
{
    treeHeight();
    printLeaf();
    LeafNodesCal();
    levelCal();
    likeTest();
    printf("\nend");
    while(1);
    return 0;
}