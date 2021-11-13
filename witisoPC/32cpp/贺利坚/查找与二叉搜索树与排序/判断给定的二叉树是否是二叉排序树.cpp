// �жϸ����Ķ������Ƿ��Ƕ���������

#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
typedef int KeyType;                    //����ؼ�������
typedef char InfoType;
typedef struct node                     //��¼����
{
    KeyType key;                        //�ؼ�����
    InfoType data;                      //����������
    struct node *lchild,*rchild;        //���Һ���ָ��
} BSTNode;
int path[MaxSize];                      //ȫ�ֱ���,���ڴ��·��
void DispBST(BSTNode *b);               //����˵��
int InsertBST(BSTNode *&p,KeyType k)    //����*pΪ���ڵ��BST�в���һ���ؼ���Ϊk�Ľڵ�
{
    if (p==NULL)                        //ԭ��Ϊ��, �²���ļ�¼Ϊ���ڵ�
    {
        p=(BSTNode *)malloc(sizeof(BSTNode));
        p->key=k;
        p->lchild=p->rchild=NULL;
        return 1;
    }
    else if (k==p->key)
        return 0;
    else if (k<p->key)
        return InsertBST(p->lchild,k);  //���뵽*p����������
    else
        return InsertBST(p->rchild,k);  //���뵽*p����������
}
BSTNode *CreatBST(KeyType A[],int n)
//������A�еĹؼ��ֽ���һ�ö���������
{
    BSTNode *bt=NULL;                   //��ʼʱbtΪ����
    int i=0;
    while (i<n)
        InsertBST(bt,A[i++]);       //��A[i]�������������T��
    return bt;                          //���ؽ����Ķ����������ĸ�ָ��
}

void DispBST(BSTNode *bt)
//�����ű�ʾ���������������bt
{
    if (bt!=NULL)
    {
        printf("%d",bt->key);
        if (bt->lchild!=NULL || bt->rchild!=NULL)
        {
            printf("(");
            DispBST(bt->lchild);
            if (bt->rchild!=NULL) printf(",");
            DispBST(bt->rchild);
            printf(")");
        }
    }
}

/*
int JudgeBST(BSTNode *bt)Ϊ�ж�һ�����Ƿ�Ϊ�����������Ƶ��㷨��ʵ��
*/
KeyType predt=-32767; //predtΪȫ�ֱ���,���浱ǰ�ڵ�����ǰ����ֵ,��ֵΪ-��
int JudgeBST(BSTNode *bt)   //�ж�bt�Ƿ�ΪBST
{
    int b1,b2;
    if (bt==NULL)
        return 1;           //�ն����������������
    else
    {
        b1=JudgeBST(bt->lchild);        //���ض����������жϣ����������������0�����򷵻�1
        if (b1==0 || predt>=bt->key)    //���������������������������ǰ����ȫ�ֱ��������ڵ�ǰ�����ʱ
            return 0;                   //���ء����������������
        predt=bt->key;                  //��¼��ǰ��Ϊ������������ǰ��
        b2=JudgeBST(bt->rchild);        //�������������ж�
        return b2;
    }
}

int main()
{
    BSTNode *bt;
    int a[]= {43,91,10,18,82,65,33,59,27,73},n=10;
    printf("�������������:");
    bt=CreatBST(a,n);
    DispBST(bt);
    printf("\n");
    printf("bt%s\n",(JudgeBST(bt)?"��һ��BST":"����һ��BST"));
    bt->lchild->rchild->key = 30;  //����ƻ���
    printf("�޸ĺ�Ķ�����:");
    DispBST(bt);
    printf("\n");
    printf("bt%s\n",(JudgeBST(bt)?"��һ��BST":"����һ��BST"));
    return 0;
}