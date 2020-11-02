#include<iostream>
using namespace std;

typedef struct LNode{
	int data;           // ����������
	struct LNode *next; // ����ָ����
}LNode, *LinkList;      // LinkListΪָ��ṹ��LNode��ָ������

bool InitList_L(LinkList &L) // ����һ���յĵ�����L
{
    L=new LNode;        // �����½����Ϊͷ��㣬��ͷָ��Lָ��ͷ���
	if(!L)
		return false;   // ���ɽ��ʧ��
	L->next=NULL;       // ͷ����ָ�����ÿ�
	return true;
}

void CreateList_R(LinkList &L) // β�巨����������
{
	// ����n��Ԫ�ص�ֵ����������ͷ���ĵ�����L
	int n;
	LinkList s, r;
	L=new LNode;
	L->next=NULL;   //�Ƚ���һ����ͷ���Ŀ�����
	r=L;            //βָ��rָ��ͷ���
	cout<<"������Ԫ�ظ���n��"<<endl;
	cin>>n;
	cout<<"β�巨�����򣩴���������..."<<endl;
	while(n--)
    {
		s=new LNode;    // �����½��
		cin>>s->data;   // ����Ԫ��ֵ�����½���������
		s->next=NULL;
		r->next=s;      // ���½��s����β���r֮��
		r=s;            // rָ���µ�β���s
	}
}

LinkList findmiddle(LinkList L)
{
    LinkList p,q;
    p=L;                // pΪ��ָ�룬��ʼʱָ��L
    q=L;                // qΪ��ָ�룬��ʼʱָ��L
    while(p!=NULL&&p->next!=NULL)
    {
        p=p->next->next;// pΪ��ָ��һ����������
        q=q->next;      // qΪ��ָ��һ����һ��
    }
    return q;           // �����м���ָ��
}

void Listprint_L(LinkList L) // ����������
{
    LinkList p;
    p=L->next;
    while(p)
    {
        cout<<p->data<<"\t";
		p=p->next;
    }
    cout<<endl;
}

int main()
{
	LinkList L,mid;
	cout<<"����������L:"<<endl;
	InitList_L(L);
	CreateList_R(L);
	cout<<"����������Ϊ��"<<endl;
	Listprint_L(L);
	mid=findmiddle(L);
	cout<<"�������м�������Ϊ��"<<mid->data<<endl;
	return 0;
}
