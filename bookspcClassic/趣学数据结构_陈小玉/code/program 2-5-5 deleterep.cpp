#include<iostream>
#include<algorithm>     // abs()�����ֵ������Ҫ��ͷ�ļ� 
using namespace std;

typedef struct LNode{
	int data;           // ����������
	struct LNode *next; // ����ָ����
}LNode, *LinkList;      // LinkListΪָ��ṹ��LNode��ָ������
int m,n;
bool InitList_L(LinkList &L) // ����һ���յĵ�����L
{
    L=new LNode;        // �����½����Ϊͷ��㣬��ͷָ��Lָ��ͷ���
	if(!L)
		return false;   // ���ɽ��ʧ��
	L->next=NULL;       // ͷ����ָ�����ÿ�
	return true;
}

void CreateList_R(LinkList &L)/ / β�巨����������
{
	// ����n��Ԫ�ص�ֵ����������ͷ���ĵ�����L
	LinkList s, r;
	L=new LNode;
	L->next=NULL;       // �Ƚ���һ����ͷ���Ŀ�����
	r=L;                // βָ��rָ��ͷ���
	cout<<"������Ԫ�ظ���m,����Ԫ�صķ�Χn��"<<endl;
	cin>>m>>n;
	cout<<"����m������ֵ������n������..."<<endl;
	while(m--)
    {
		s=new LNode;    // �����½��
		cin>>s->data;   // ����Ԫ��ֵ�����½���������
		s->next=NULL;
		r->next=s;      // ���½��s����β���r֮��
		r=s;            // rָ���µ�β���s
	}
}

void Deleterep(LinkList &L) // ɾ���ظ�Ԫ��
{
    LinkList p,q;
    int x;
    int *flag=new int[n+1]; // ����flag���飬����n+1���ռ�
    for(int i=0;i<n+1;i++)  // ��ʼ��
        flag[i]=0;
    p=L;                    // ָ��ͷ���
    while(p->next!=NULL)
    {
        x=abs(p->next->data);
        if(flag[x]==0)      // δ���ֹ�
        {
            flag[x]=1;      // ��ǳ���
            p=p->next;      // ָ�����
        }
        else
        {
            q=p->next;
            p->next=q->next;// ɾ���ظ�Ԫ��
            delete q;

        }
    }
    delete []flag;
}

void Listprint_L(LinkList L) //����������
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
	LinkList L;
	cout<<"����������L:"<<endl;
	InitList_L(L);
	CreateList_R(L);
	cout<<"����������Ϊ��"<<endl;
	Listprint_L(L);
	cout<<"ɾ���ظ�Ԫ�أ�"<<endl;
	Deleterep(L);
	Listprint_L(L);
	return 0;
}
