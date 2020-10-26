#include<iostream>
using namespace std;

typedef struct LNode{
	int data; //����������
	struct LNode *next; //����ָ����
}LNode, *LinkList; //LinkListΪָ��ṹ��LNode��ָ������

bool InitList_L(LinkList &L)//����һ���յĵ�����L
{
    L=new LNode;     //�����½����Ϊͷ��㣬��ͷָ��Lָ��ͷ���
	if(!L)
      return false;  //���ɽ��ʧ��
	L->next=NULL;   //ͷ����ָ�����ÿ�
	return true;
}

void CreateList_R(LinkList &L)//β�巨����������
{
	//����n��Ԫ�ص�ֵ����������ͷ���ĵ�����L
	int n;
	LinkList s, r;
	L=new LNode;
	L->next=NULL; //�Ƚ���һ����ͷ���Ŀ�����
	r=L; //βָ��rָ��ͷ���
	cout<<"������Ԫ�ظ���n��"<<endl;
	cin>>n;
	cout <<"β�巨�����򣩴���������..." <<endl;
	while(n--)
    {
		s=new LNode;//�����½��
		cin>>s->data; //����Ԫ��ֵ�����½���������
		s->next=NULL;
		r->next=s;//���½��s����β���r֮��
		r=s;//rָ���µ�β���s
	}
}

void reverselinklist(LinkList &L)
{
    LinkList p,q;
    p=L->next; //pָ��L�ĵ�һ��Ԫ��
    L->next=NULL; //ͷ����next���ÿգ�
    while(p)
    {
        q=p->next;//qָ��p����һ����㣬��¼�ϵ㣻
        p->next=L->next; //ͷ�巨����L����һ������ַ��ֵ��p��next��
        L->next=p; //��p����ַ��ֵ��L��next��
        p=q;//ָ����ƣ�pָ��q��
    }
}
void Listprint_L(LinkList L) //����������
{
    LinkList p;
    p=L->next;
    while (p)
    {
        cout<<p->data <<"\t";
		p=p->next;
    }
    cout<<endl;
}

int main()
{
	LinkList L;
	cout<<"����������L:"<<endl;
	InitList_L(L);
	CreateList_R(L);
	cout<<"����������Ϊ��"<<endl;
	Listprint_L(L);
	cout<<"������͵����ú���Ϊ��"<<endl;
	reverselinklist(L);
	Listprint_L(L);
	return 0;
}
