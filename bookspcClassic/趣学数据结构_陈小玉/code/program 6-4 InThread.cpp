#include<iostream>
using namespace std;

//�����������Ĵ洢���
typedef struct BTnode
{
	char data;	//���������
	struct BTnode *lchild,*rchild;	//���Һ���ָ��
	int ltag,rtag;
}BTnode,*BTtree;

//ȫ�ֱ���pre
BTtree pre;

//����������(���շ�)
void CreateBiTree(BTtree &T)
{
	//�������������������н���ֵ��һ���ַ������������������ʾ�Ķ�����T
	char ch;
	cin>>ch;
	if(ch=='#')  T=NULL;			//�ݹ������������
	else
	{
		T=new BTnode;
		T->data=ch;					//���ɸ����
		CreateBiTree(T->lchild);	//�ݹ鴴��������
		CreateBiTree(T->rchild);	//�ݹ鴴��������
	}
}

void InThread(BTtree &p)//����������
{
	//pre��ȫ�ֱ�����ָ��ǰ���p��ǰ��
	if(p)
	{
		InThread(p->lchild);   //�������ݹ�������
		if(!p->lchild)   //p������Ϊ��
		{
			p->ltag=1;    //��p����������
			p->lchild=pre; 	//p������ָ��ָ��pre��ǰ����
		}
		else
			p->ltag=0;
		if(pre)
        {
            if(!pre->rchild)  //pre���Һ���Ϊ��
            {
                pre->rtag=1; //��pre����������
                pre->rchild=p; //pre���Һ���ָ��ָ��p����̣�
            }
            else
                pre->rtag=0;
        }
		pre=p;                     //����preָ��p��ǰ��
		InThread(p->rchild);   //�������ݹ�������
    }
}

void CreateInThread(BTtree &T)//������������������
{
    pre=NULL;//��ʼ��Ϊ��
    if(T)
    {
        InThread(T); //����������
        pre->rchild=NULL;// ������������һ����㣬����Ϊ��
        pre->rtag=1;
    }
}

void Inorder(BTtree T)//�������������
{
    if(T)
    {
       Inorder(T->lchild);
       cout<<T->data<<"  ";
       Inorder(T->rchild);
    }
}

void InorderThread(BTtree T)//������������������
{
    BTtree p;
    p=T;
    while(p)
    {
       while(p->ltag==0) p=p->lchild;  //��������
       cout<<p->data<<"  ";//��������Ϣ
       while(p->rtag==1&&p->rchild) //�Һ���Ϊ��������ָ����
       {
			p=p->rchild;   //���ʺ�̽��
			cout<<p->data<<"  ";//��������Ϣ
       }
       p=p->rchild;//ת��p��������
    }
}

int main()
{
	BTtree tree;
	cout<<"���������򴴽������������У����շ�����\n";//����ABD##E##CF#G###
	CreateBiTree(tree);  //����������
	cout<<"��������������������\n";
	Inorder(tree);       //�������������
	cout<<endl;
	CreateInThread(tree);//������������������
	cout<<"���������������ı��������\n";
	InorderThread(tree); //������������������
	return 0;
}
