// 二叉排序树

#include <stdio.h>
#include <malloc.h>
typedef int KeyType;
typedef char InfoType[10];
typedef struct node                 //记录类型
{
    KeyType key;                    //关键字项
    InfoType data;                  //其他数据域
    struct node *lchild,*rchild;    //左右孩子指针
} BSTNode;

//在p所指向的二叉排序树中，插入值为k的节点
int InsertBST(BSTNode *&p,KeyType k)
{
    if (p==NULL)                        //原树为空, 新插入的记录为根结点
    {
        p=(BSTNode *)malloc(sizeof(BSTNode));
        p->key=k;
        p->lchild=p->rchild=NULL;
        return 1;
    }
    else if (k==p->key)                 //树中存在相同关键字的结点,返回0
        return 0;
    else if (k<p->key)
        return InsertBST(p->lchild,k);  //插入到*p的左子树中
    else
        return InsertBST(p->rchild,k);  //插入到*p的右子树中
}

//由有n个元素的数组A，创建一个二叉排序树
BSTNode *CreateBST(KeyType A[],int n)   //返回BST树根结点指针
{
    BSTNode *bt=NULL;                   //初始时bt为空树
    int i=0;
    while (i<n)
    {
        InsertBST(bt,A[i]);             //将关键字A[i]插入二叉排序树T中
        i++;
    }
    return bt;                          //返回建立的二叉排序树的根指针
}

//输出一棵排序二叉树
void DispBST(BSTNode *bt)
{
    if (bt!=NULL)
    {
        printf("%d",bt->key);
        if (bt->lchild!=NULL || bt->rchild!=NULL)
        {
            printf("(");                        //有孩子结点时才输出(
            DispBST(bt->lchild);                //递归处理左子树
            if (bt->rchild!=NULL) printf(",");  //有右孩子结点时才输出,
            DispBST(bt->rchild);                //递归处理右子树
            printf(")");                        //有孩子结点时才输出)
        }
    }
}

//在bt指向的节点为根的排序二叉树中，查找值为k的节点。找不到返回NULL
BSTNode *SearchBST(BSTNode *bt,KeyType k)
{
    if (bt==NULL || bt->key==k)         //递归终结条件
        return bt;
    if (k<bt->key)
        return SearchBST(bt->lchild,k);  //在左子树中递归查找
    else
        return SearchBST(bt->rchild,k);  //在右子树中递归查找
}

//二叉排序树中查找的非递归算法
BSTNode *SearchBST1(BSTNode *bt,KeyType k)
{
    while (bt!=NULL)
    {
        if (k==bt->key)
            return bt;
        else if (k<bt->key)
            bt=bt->lchild;
        else
            bt=bt->rchild;
    }
    return NULL;
}

void Delete1(BSTNode *p,BSTNode *&r)  //当被删*p结点有左右子树时的删除过程
{
    BSTNode *q;
    if (r->rchild!=NULL)
        Delete1(p,r->rchild);   //递归找最右下结点
    else                        //找到了最右下结点*r
    {
        p->key=r->key;          //将*r的关键字值赋给*p
        q=r;
        r=r->lchild;            //直接将其左子树的根结点放在被删结点的位置上
        free(q);                //释放原*r的空间
    }
}

void Delete(BSTNode *&p)   //从二叉排序树中删除*p结点
{
    BSTNode *q;
    if (p->rchild==NULL)        //*p结点没有右子树的情况
    {
        q=p;
        p=p->lchild;            //直接将其右子树的根结点放在被删结点的位置上
        free(q);
    }
    else if (p->lchild==NULL)   //*p结点没有左子树的情况
    {
        q=p;
        p=p->rchild;            //将*p结点的右子树作为双亲结点的相应子树
        free(q);
    }
    else Delete1(p,p->lchild);  //*p结点既没有左子树又没有右子树的情况
}

int DeleteBST(BSTNode *&bt, KeyType k)  //在bt中删除关键字为k的结点
{
    if (bt==NULL)
        return 0;               //空树删除失败
    else
    {
        if (k<bt->key)
            return DeleteBST(bt->lchild,k); //递归在左子树中删除为k的结点
        else if (k>bt->key)
            return DeleteBST(bt->rchild,k); //递归在右子树中删除为k的结点
        else
        {
            Delete(bt);     //调用Delete(bt)函数删除*bt结点
            return 1;
        }
    }
}
int main()
{
    BSTNode *bt;
    int n=12,x=46;
    KeyType a[]= {25,18,46,2,53,39,32,4,74,67,60,11};
    bt=CreateBST(a,n);
    printf("BST:");
    DispBST(bt);
    printf("\n");
    printf("删除%d结点\n",x);
    if (SearchBST(bt,x)!=NULL)
    {
        DeleteBST(bt,x);
        printf("BST:");
        DispBST(bt);
        printf("\n");
    }
    return 0;

}
