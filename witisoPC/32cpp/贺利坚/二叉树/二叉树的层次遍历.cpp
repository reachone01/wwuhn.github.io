#include <stdio.h>
#include "btree.h"

void LevelOrder(BTNode *b)
{
    BTNode *p;
    BTNode *qu[MaxSize];    //���廷�ζ���,��Žڵ�ָ��
    int front,rear;         //�����ͷ�Ͷ�βָ��
    front=rear=-1;          //�ö���Ϊ�ն���
    rear++;
    qu[rear]=b;             //���ڵ�ָ��������
    while (front!=rear)     //���в�Ϊ��
    {
        front=(front+1)%MaxSize;
        p=qu[front];            //��ͷ������
        printf("%c ",p->data);  //���ʽڵ�
        if (p->lchild!=NULL)    //������ʱ�������
        {
            rear=(rear+1)%MaxSize;
            qu[rear]=p->lchild;
        }
        if (p->rchild!=NULL)    //���Һ���ʱ�������
        {
            rear=(rear+1)%MaxSize;
            qu[rear]=p->rchild;
        }
    }
}

int main()
{
    BTNode *b;
    CreateBTNode(b,"A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))");
    printf("������b: ");
    DispBTNode(b);
    printf("\n");
    printf("��α�������:\n");
    LevelOrder(b);
    DestroyBTNode(b);
    printf("\nend");
    while(1);
    return 0;
}