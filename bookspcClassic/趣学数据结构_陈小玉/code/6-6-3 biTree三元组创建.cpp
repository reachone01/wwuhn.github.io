#include<iostream>
#include<cstring>
#include <string>
#include<queue>
using namespace std;
/*
������Ԫ�� (F��C��L/R) ��������һ�ö����������
      (���� F ��ʾ˫�׽��ı�ʶ��
            C ��ʾ���ӽ���ʶ��
L/R ��ʾ C Ϊ F �����ӻ��Һ���)��
�����������Ԫ�������У�C �ǰ����˳����ֵġ�
����ı�ʶ���ַ����͡�F=NULLʱ C Ϊ������ʶ���� C ��ΪNULL�����ʾ���������
�Ա�д�㷨�����������Ԫ�����н����������Ķ�������,�����������򡢺������������
*/
/*��������
NULL A L
A B L
A C R
B D R
C E L
C F R
D G L
F H L
NULL NULL L
*/
struct biTnode
{
    string data;
    biTnode *lChild,*rChild;
};
biTnode* T=NULL;

void CreatebiTree(biTnode* &T)
{
    string a,b,c;
    biTnode *node,*p;
    queue<biTnode*>q;
    cin>>a>>b>>c;
    if(a=="NULL"&&b!="NULL")    // ���������
    {
        node=new biTnode;
        node->data=b;
        node->lChild=node->rChild=NULL;
        T=node;
        q.push(T);
    }
    cin>>a>>b>>c;
    while(!q.empty()&&a!="NULL"&&b!="NULL")
    {
        p=q.front();
        q.pop();
        while(a==p->data)
        {
            node=new biTnode;
            node->data=b;
            node->lChild=node->rChild=NULL;
            if(c=="L")
            {
                p->lChild=node;
                cout<<p->data<<"'s lChild is "<<node->data<<endl;
            }
            else
            {
                p->rChild=node;
                cout<<p->data<<"'s rChild is "<<node->data<<endl;
            }
            q.push(node);
            cin>>a>>b>>c;
        }
    }
}


void preorder(biTnode* &T)
{
    if(T)
    {
        cout<<T->data<<"  ";
        preorder(T->lChild);
        preorder(T->rChild);
    }
}

void inorder(biTnode* &T)
{
    if(T)
    {
        inorder(T->lChild);
        cout<<T->data<<"  ";
        inorder(T->rChild);
    }
}

void posorder(biTnode* &T)
{
    if(T)
    {
        posorder(T->lChild);
        posorder(T->rChild);
        cout<<T->data<<"  ";
    }
}
int main()
{
    cout<<"����������a,b,c(aΪ���ף�bΪ����ַ���cΪ��L�����ӻ�R���Һ���)"<<endl;
    CreatebiTree(T);
    cout<<"�������ɹ�!"<<endl;
    cout<<"���������"<<endl;
    preorder(T);
    cout<<endl<<"���������"<<endl;
    inorder(T);
    cout<<endl<<"���������"<<endl;
    posorder(T);
    return 0;
}
