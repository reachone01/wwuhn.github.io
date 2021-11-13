#include <stdio.h>  // �������ǵݹ����
#include "btree.h"

void PreOrder1(BTNode *b)
{
    BTNode *St[MaxSize],*p;
    int top=-1;
    if (b!=NULL)
    {
        top++;                      //���ڵ���ջ
        St[top]=b;
        while (top>-1)              //ջ��Ϊ��ʱѭ��
        {
            p=St[top];              //��ջ�����ʸýڵ�
            top--;
            printf("%c ",p->data);
            if (p->rchild!=NULL)    //�Һ�����ջ
            {
                top++;
                St[top]=p->rchild;
            }
            if (p->lchild!=NULL)    //������ջ
            {
                top++;
                St[top]=p->lchild;
            }
        }
        printf("\n");
    }
}

void InOrder1(BTNode *b)
{
    BTNode *St[MaxSize],*p;
    int top=-1;
    if (b!=NULL)
    {
        p=b;
        while (top>-1 || p!=NULL)
        {
            while (p!=NULL)
            {
                top++;
                St[top]=p;
                p=p->lchild;
            }
            if (top>-1)
            {
                p=St[top];
                top--;
                printf("%c ",p->data);
                p=p->rchild;
            }
        }
        printf("\n");
    }
}

void PostOrder1(BTNode *b)
{
    BTNode *St[MaxSize];
    BTNode *p;
    int flag,top=-1;                        //ջָ���ó�ֵ
    if (b!=NULL)
    {
        do
        {
            while (b!=NULL)                 //��t��������ڵ���ջ
            {
                top++;
                St[top]=b;
                b=b->lchild;
            }
            p=NULL;                         //pָ��ǰ�ڵ��ǰһ���ѷ��ʵĽڵ�
            flag=1;
            while (top!=-1 && flag)
            {
                b=St[top];                  //ȡ����ǰ��ջ��Ԫ��
                if (b->rchild==p)           //�����������ڻ��ѱ�����,����֮
                {
                    printf("%c ",b->data);  //����*b�ڵ�
                    top--;
                    p=b;                    //pָ���򱻷��ʵĽڵ�
                }
                else
                {
                    b=b->rchild;            //tָ��������
                    flag=0;
                }
            }
        }
        while (top!=-1);
        printf("\n");
    }
}

int main()
{
    BTNode *b;
    CreateBTNode(b,"A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))");
    printf("������b: ");
    DispBTNode(b);
    printf("\n");
    printf("�����������:\n");
    PreOrder1(b);
    printf("�����������:\n");
    InOrder1(b);
    printf("�����������:\n");
    PostOrder1(b);
    DestroyBTNode(b);
    printf("end");
    while(1);
    return 0;
}
