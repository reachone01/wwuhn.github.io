#include<stdlib.h>
#include<stdio.h>
#include<malloc.h>
#define STACK_INCREMENT  10
#define STACK_INIT_SIZE 100
#define MAXSIZE         50
#define OVERFLOW -2
//��������������ʽ�洢�ṹ
typedef struct BiTNode
{
	int data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
 
//ջ��˳��洢�ṹ
typedef struct
{
	BiTree *base;
	BiTree *top;
	int stacksize;
}Sqstack;
 
//��ʼ��һ��ջ�����ڶ��������������
void InitStack(Sqstack&S)
{
	S.base=(BiTree*)malloc(STACK_INIT_SIZE*sizeof(BiTNode));
	if(!S.base)
		exit(0);
	S.top=S.base;
	S.stacksize=STACK_INIT_SIZE;
}
 
 
//��������������
void SearchBST(BiTree T,int key,BiTree f,BiTree&p)
{
	if(!T) 
		p=f;
	else if(T->data==key)
		p=T;
	else if(T->data<key)
		SearchBST(T->rchild,key,T,p);
	else 
		SearchBST(T->lchild,key,T,p);
}
 
//����һ������������
void CreatBST(BiTree &T,int e)
{
	BiTree p,s,q;
	SearchBST(T,e,NULL,p);//�ҵ��������λ�á�
	s=(BiTree)malloc(sizeof(BiTNode));
	s->data=e;
	s->lchild=NULL;
	s->rchild=NULL;
	if(!p)T=s;
	else if(e==p->data)
//����������������ͬ��Ԫ��ʱ�����������ͬԪ�ص��Һ���λ�á�
//ԭ�����������������ҽڵ���
	{
		q=p->rchild;
		p->rchild=s;
		s->rchild=q;
	}
	else if(e<p->data)
		p->lchild=s;
	else
		p->rchild=s;
}
 
//�����������������
void InOrderTravese(BiTree T)
{
	BiTree p;
	Sqstack Sqt;
	InitStack(Sqt);
	p=T;
	while(p||Sqt.base!=Sqt.top)
	{
		if(p)
		{
			if(Sqt.top-Sqt.base>=Sqt.stacksize)
			{
				Sqt.base=(BiTree*)realloc(Sqt.base, \
		(Sqt.stacksize+STACK_INCREMENT)*sizeof(BiTNode));
				if(!Sqt.base)
					exit(OVERFLOW);
				Sqt.top=Sqt.base+Sqt.stacksize;
				Sqt.stacksize+=STACK_INCREMENT;
			}
			*Sqt.top++=p;
			p=p->lchild;
		}
		else
		{
			p=*--Sqt.top;
			printf("%d ",p->data);
			p=p->rchild;
		}
	}
	printf("\n");
}
void main()
{
	int length;
	int bst[MAXSIZE];
	BiTree BST;
    BST=(BiTree)malloc(sizeof(BiTNode));
    BST=NULL;
	printf("***************************\n");
	printf("      �����������㷨       \n");
	printf("***************************\n");
	printf("��������������еĸ���N (N<%d)��",MAXSIZE);
	scanf("%d",&length);
	printf("\n");
	printf("�����������������Ԫ�أ�\n");
	for(int i=0;i<length;i++)
		scanf("%d",&bst[i]);
	printf("\n");
	for(i=0;i<length;i++)
		CreatBST(BST,bst[i]);
	printf("�����������������\n");
	InOrderTravese(BST);
	printf("\n");
	free(BST);
	system("pause");
}
/*output:
***************************
      �����������㷨
***************************
��������������еĸ���N (N<50)��5

�����������������Ԫ�أ�
44 55 22 33 11

�����������������
11 22 33 44 55
*/