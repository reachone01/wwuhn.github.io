#include<iostream>
using namespace std;

typedef struct Bnode{ 	/*����������洢�ṹ*/
	char data;
	struct Bnode *lchild,*rchild;
}Bnode,*Btree;

void createtree(Btree &T)	/*��������������*/
{
    char check;					/*�ж��Ƿ񴴽����Һ���*/
    T=new Bnode;
    cout<<"����������Ϣ:"<<endl;	/*������������*/
    cin>>T->data;
    cout<<"�Ƿ���� "<<T->data<<"������? (Y/N)"<<endl; /*ѯ���Ƿ񴴽�T��������*/
    cin>>check;
    if(check=='Y')
        createtree(T->lchild);
    else
        T->lchild=NULL;
    cout<<"�Ƿ����"<<T->data<<"���Һ���? (Y/N)"<<endl; /*ѯ���Ƿ񴴽�T��������*/
    cin>>check;
    if(check=='Y')
        createtree(T->rchild);
    else
        T->rchild=NULL;
    return;
}

int main()
{
    Btree mytree;
    createtree(mytree);/*����������*/
    return 0;
}
