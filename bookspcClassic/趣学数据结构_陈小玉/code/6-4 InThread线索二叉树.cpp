// ��������ʵ���������ö��������еĿ�ָ���¼�ڵ��ǰ����������
// ÿ�ֱ�����˳��ͬ���ڵ��ǰ������Ҳ��ͬ����˶���������������ָ����ʲô����˳���������
// �������������Ĺ��̣�ʵ�������ڱ����������޸Ŀ�ָ��Ĺ��̣�������ǰ������Ϣ
#include<iostream>
using namespace std;

typedef struct BTnode               // �����������Ĵ洢���
{
	char data;	                    // ���������
	struct BTnode *lchild,*rchild;	// ���Һ���ָ��
	int ltag,rtag;
}BTnode,*BTtree;

BTtree pre;                         // ȫ�ֱ���pre���ոշ��ʹ��Ľڵ㣬�����ǰ�ڵ�Ϊp����preΪpָ��Ľڵ��ǰ��

void CreateBiTree(BTtree &T)        // ����������(���շ�)
{                // �������������������н���ֵ��һ���ַ������������������ʾ�Ķ�����T
	char ch;
	cin>>ch;
	if(ch=='#')  T=NULL;			//�ݹ������������
	else
	{
		T=new BTnode;
		T->data=ch;					// ���ɸ����
		CreateBiTree(T->lchild);	// �ݹ鴴��������
		CreateBiTree(T->rchild);	// �ݹ鴴��������
	}
}

void InThread(BTtree &p)        // ����������
{
	if(p)
	{
		InThread(p->lchild);    // �������ݹ�������
		if(!p->lchild)          // p������Ϊ��
		{
			p->ltag=1;          // ��p����������
			p->lchild=pre; 	    // p������ָ��ָ��pre��ǰ����,pre��ȫ�ֱ�����ָ��ǰ���p��ǰ��
		}
		else
			p->ltag=0;
		if(pre)
        {
            if(!pre->rchild)    // pre���Һ���Ϊ��
            {
                pre->rtag=1;    // ��pre����������
                pre->rchild=p;  // pre���Һ���ָ��ָ��p����̣�
            }
            else
                pre->rtag=0;
        }
		pre=p;                  // ����preָ��p��ǰ��
		InThread(p->rchild);    // �������ݹ�������
    }
}

void CreateInThread(BTtree &T)  // ������������������
{
    pre=NULL;                   // ��ʼ��Ϊ��
    if(T)
    {
        InThread(T);            // ����������
        pre->rchild=NULL;       // ������������һ����㣬����Ϊ��
        pre->rtag=1;
    }
}

void Inorder(BTtree T)          // �������������
{
    if(T)
    {
       Inorder(T->lchild);
       cout<<T->data<<"  ";
       Inorder(T->rchild);
    }
}

void InorderThread(BTtree T)            // ������������������
{
    BTtree p;
    p=T;
    while(p)
    {
       while(p->ltag==0)                // ��������
           p=p->lchild;
       cout<<p->data<<"  ";             // ��������Ϣ
       while(p->rtag==1&&p->rchild)     // �Һ���Ϊ��������ָ����
       {
			p=p->rchild;                // ���ʺ�̽��
			cout<<p->data<<"  ";        // ��������Ϣ
       }
       p=p->rchild;                     // ת��p��������
    }
}

int main()
{
	BTtree tree;
	cout<<"���������򴴽������������У����շ�����\n";   // ����ABD##E##CF#G###
	CreateBiTree(tree);                 // ����������
	cout<<"��������������������\n";
	Inorder(tree);                      // �������������
	cout<<endl;
	CreateInThread(tree);               // ������������������
	cout<<"���������������ı��������\n";
	InorderThread(tree);                // ������������������
	return 0;
}
