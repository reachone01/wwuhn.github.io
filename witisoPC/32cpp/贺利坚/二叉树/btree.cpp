#include <stdio.h>
#include <malloc.h>
#include "btree.h"

void CreateBTNode(BTNode *&b,char *str)     //��str������������
{
    BTNode *St[MaxSize],*p=NULL;
    int top=-1,k,j=0;
    char ch;
    b=NULL;             //�����Ķ�������ʼʱΪ��
    ch=str[j];
    while (ch!='\0')    //strδɨ����ʱѭ��
    {
        switch(ch)
        {
        case '(':
            top++;
            St[top]=p;
            k=1;
            break;      //Ϊ��ڵ�
        case ')':
            top--;
            break;
        case ',':
            k=2;
            break;                          //Ϊ�ҽڵ�
        default:
            p=(BTNode *)malloc(sizeof(BTNode));
            p->data=ch;
            p->lchild=p->rchild=NULL;
            if (b==NULL)                    //pָ��������ĸ��ڵ�
                b=p;
            else                            //�ѽ������������ڵ�
            {
                switch(k)
                {
                case 1:
                    St[top]->lchild=p;
                    break;
                case 2:
                    St[top]->rchild=p;
                    break;
                }
            }
        }
        j++;
        ch=str[j];
    }
}

BTNode *FindNode(BTNode *b,ElemType x)  //����data��Ϊx�Ľڵ�ָ��
{
    BTNode *p;
    if (b==NULL)
        return NULL;
    else if (b->data==x)
        return b;
    else
    {
        p=FindNode(b->lchild,x);
        if (p!=NULL)
            return p;
        else
            return FindNode(b->rchild,x);
    }
}

BTNode *LchildNode(BTNode *p)   //����*p�ڵ�����ӽڵ�ָ��
{
    return p->lchild;
}

BTNode *RchildNode(BTNode *p)   //����*p�ڵ���Һ��ӽڵ�ָ��
{
    return p->rchild;
}

int BTNodeDepth(BTNode *b)  //�������b�����
{
    int lchilddep,rchilddep;
    if (b==NULL)
        return(0);                          //�����ĸ߶�Ϊ0
    else
    {
        lchilddep=BTNodeDepth(b->lchild);   //���������ĸ߶�Ϊlchilddep
        rchilddep=BTNodeDepth(b->rchild);   //���������ĸ߶�Ϊrchilddep
        return (lchilddep>rchilddep)? (lchilddep+1):(rchilddep+1);
    }
}

void DispBTNode(BTNode *b)  //�����ű�ʾ�����������
{
    if (b!=NULL)
    {
        printf("%c",b->data);
        if (b->lchild!=NULL || b->rchild!=NULL)
        {
            printf("(");
            DispBTNode(b->lchild);
            if (b->rchild!=NULL) printf(",");
            DispBTNode(b->rchild);
            printf(")");
        }
    }
}

void DestroyBTNode(BTNode *&b)   //���ٶ�����
{
    if (b!=NULL)
    {
        DestroyBTNode(b->lchild);
        DestroyBTNode(b->rchild);
        free(b);
    }
}