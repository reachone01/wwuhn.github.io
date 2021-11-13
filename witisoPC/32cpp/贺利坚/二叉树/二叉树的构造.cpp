/*

*/
#if 1



#include <stdio.h>
#include <malloc.h>
#include "btree.h"

/*
pre�����������,in�����������,nΪ������������,
���㷨ִ�к󷵻ع���Ķ������ĸ����ָ��
*/
BTNode *CreateBT1(char *pre,char *in,int n)
{
    BTNode *s;
    char *p;
    int k;
    if (n<=0) return NULL;
    s=(BTNode *)malloc(sizeof(BTNode));     //�������������*s
    s->data=*pre;
    for (p=in; p<in+n; p++)                 //�������������ҵ���*ppos��λ��k
        if (*p==*pre)                       //preָ������
            break;                          //��in���ҵ����˳�ѭ��
    k=p-in;                                 //ȷ���������in�е�λ��
    s->lchild=CreateBT1(pre+1,in,k);        //�ݹ鹹��������
    s->rchild=CreateBT1(pre+k+1,p+1,n-k-1); //�ݹ鹹��������
    return s;
}

int main()
{
    ElemType pre[]="ABDGCEF",in[]="DGBAECF";
    BTNode *b1;
    b1=CreateBT1(pre,in,7);
    printf("b1:");
    DispBTNode(b1);
    printf("\n");
    while(1); 
    return 0;
}




#endif

#if 0
#include <stdio.h>
#include <malloc.h>
#include "btree.h"

BTNode *CreateBT2(char *post,char *in,int n)
/*post��ź�������,in�����������,nΪ������������,
���㷨ִ�к󷵻ع���Ķ������ĸ����ָ��*/
{
    BTNode *s;
    char r,*p;
    int k;
    if (n<=0) return NULL;
    r=*(post+n-1);                          //�����ֵ
    s=(BTNode *)malloc(sizeof(BTNode));     //�������������*s
    s->data=r;
    for (p=in; p<in+n; p++)                 //��in�в��Ҹ����
        if (*p==r)
            break;
    k=p-in;                                 //kΪ�������in�е��±�
    s->lchild=CreateBT2(post,in,k);         //�ݹ鹹��������
    s->rchild=CreateBT2(post+k,p+1,n-k-1);  //�ݹ鹹��������
    return s;
}

int main()
{
    ElemType in[]="DGBAECF",post[]="GDBEFCA";
    BTNode *b2;
    b2=CreateBT2(post,in,7);
    printf("b2:");
    DispBTNode(b2);
    printf("\n");
    while(1);
    return 0;
}

#endif


#if 0
#include <stdio.h>
#include <malloc.h>
#include "btree.h"
#define N 30
typedef ElemType SqBTree[N];
BTNode *trans(SqBTree a,int i)
{
    BTNode *b;
    if (i>N)
        return(NULL);
    if (a[i]=='#')
        return(NULL);           //���ڵ㲻����ʱ����NULL
    b=(BTNode *)malloc(sizeof(BTNode)); //�������ڵ�
    b->data=a[i];
    b->lchild=trans(a,2*i);                 //�ݹ鴴��������
    b->rchild=trans(a,2*i+1);               //�ݹ鴴��������
    return(b);                              //���ظ��ڵ�
}
int main()
{
    BTNode *b;
    ElemType s[]="0ABCD#EF#G####################";
    b=trans(s,1);
    printf("b:");
    DispBTNode(b);
    printf("\n");
    while(1);
    return 0;
}




#endif
/*

*/