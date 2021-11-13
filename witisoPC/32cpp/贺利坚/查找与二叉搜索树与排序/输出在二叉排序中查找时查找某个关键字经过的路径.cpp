// ����ڶ��������в���ʱ����ĳ���ؼ��־�����·��

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

//�ڶ����������в��ң��Ǿ����Ľڵ��¼��path�У�����ֵΪ�����ҽڵ���path�д洢���±�
int SearchBST(BSTNode *bt,KeyType k,KeyType path[],int i)
{
    if (bt==NULL)
        return i;
    else if (k==bt->key)    //�ҵ��˽ڵ�
    {
        path[i+1]=bt->key;  //�����·��
        return i+1;
    }
    else
    {
        path[i+1]=bt->key;
        if (k<bt->key)
            SearchBST(bt->lchild,k,path,i+1);  //���������еݹ����
        else
            SearchBST(bt->rchild,k,path,i+1);  //���������еݹ����
    }
}

//���Ҳ���ʾ������·��
void SearchResult(BSTNode *bt, int k1)
{
    int r, j;
    r = SearchBST(bt,k1,path,-1);
    for (j=0; j<=r; j++)
        printf("%3d",path[j]);
    printf("\n");
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

int main()
{
    BSTNode *bt;
    KeyType k1=65, k2=32;
    int a[]= {43,91,10,18,82,65,33,59,27,73},n=10;
    printf("������BST��:");
    bt=CreatBST(a,n);
    DispBST(bt);
    printf("\n");
    printf("  ����%d�ؼ���:",k1);
    SearchResult(bt,k1);
    printf("  ����%d�ؼ���:",k2);
    SearchResult(bt,k2);
    return 0;
}
