#include<iostream>
using namespace std;

#define Maxsize 100
typedef char ElemType;

typedef  struct SqQueue{
  ElemType base[Maxsize]; //һά����洢��Ҳ��������ָ�붯̬����ռ�
  int front,rear; //ͷָ��,βָ��
}DuQueue;

//��ʼ��
void InitQueue(DuQueue &Q)//ע��ʹ�����ò�����������˺�������ı���Ч
{
	Q.front=Q.rear=0; //ͷָ���βָ����Ϊ�㣬����Ϊ��
}
//�жӿ�
 bool isEmpty(DuQueue Q)
 {
     if(Q.front==Q.rear)
        return true;
     else
        return false;
 }
 //�ж���
 bool isFull(DuQueue Q)
 {
     if((Q.rear+1)%Maxsize==Q.front) //βָ�����һλ����ͷָ�룬��������
		return true;
     else
        return false;
 }
 //ͷ��
bool push_front(DuQueue &Q,ElemType e)
{
    if(isFull(Q))
        return false;
    Q.front=(Q.front-1+Maxsize)%Maxsize;//����ǰ�ƶ�һλ
    Q.base[Q.front]=e; //�����
    return true;
}
//ͷ��
bool pop_front(DuQueue &Q,ElemType &x)
{
    if(isEmpty(Q))
        return false;
    x=Q.base[Q.front]; //ȡ����
    Q.front=(Q.front+1)%Maxsize;//����ƶ�һλ
    return true;
}
 //β��
bool push_back(DuQueue &Q,ElemType e)
{
    if(isFull(Q))
        return false;
    Q.base[Q.rear]=e; //�ȷ���
    Q.rear=(Q.rear+1)%Maxsize;//����ƶ�һλ
    return true;
}
//β��
bool pop_back(DuQueue &Q,ElemType &x)
{
    if(isEmpty(Q))
        return false;
    Q.rear=(Q.rear-1+Maxsize)%Maxsize;//��ǰ�ƶ�һλ
    x=Q.base[Q.rear]; //ȡ����
    return true;
}
//ȡ��ͷ
bool get_front(DuQueue Q,ElemType &x)
{
    if(isEmpty(Q))
        return false;
    x=Q.base[Q.front]; //ȡ��ͷ����;
    return true;
}
//ȡ��β
bool get_back(DuQueue Q,ElemType &x)
{
    if(isEmpty(Q))
        return false;
    x=Q.base[(Q.rear-1+Maxsize)%Maxsize];
    return true;
}
//�󳤶�
int length(DuQueue Q)
{
    return (Q.rear-Q.front+Maxsize)%Maxsize;
}
//��ͷ��β�����������Ԫ�أ�������
void traverse(DuQueue Q)
{
    if(isEmpty(Q))
    {
       cout<<"DuQueue is empty"<<endl;
       return ;
    }
    int temp=Q.front;//����һ���ݴ������ͷָ��δ�ƶ�
    while(temp!=Q.rear)
    {
       cout<<Q.base[temp]<<"\t";
       temp=(temp+1)%Maxsize;
     }
     cout<<endl<<"traverse is over!"<<endl;
}

int main()
{
    DuQueue DuQ;
    ElemType e,x;
    cout<<"1. ��ʼ��\n";
	cout<<"2. ͷ��\n";
	cout<<"3. ͷ��\n";
	cout<<"4. β��\n";
	cout<<"5. β��\n";
	cout<<"6. ȡ��ͷ\n";
	cout<<"7. ȡ��β\n";
	cout<<"8. �󳤶�\n";
	cout<<"9. ��������\n";
	cout<<"0. �˳�\n";
	int choose=-1;
	while (choose!=0)
	{
        cout<<"��ѡ��:";
		cin>>choose;
		switch(choose)
		{
		    case 1://��ʼ��
		        cout << "˫�˶��г�ʼ��..." << endl;
		        InitQueue(DuQ);
		        break;
		     case 2://ͷ��
		         cout << "��ǰ�˽��ӣ�ͷ����..." << endl;
		         cout << "������һ���ַ�:" << endl;
		         cin>>e;
		         push_front(DuQ,e);
                 break;
            case 3://ͷ��
                cout <<"��ǰ�˳��ӣ�ͷ����..."<< endl;
                pop_front(DuQ,x);
                cout << "����Ԫ��Ϊ" <<x<< endl;
                break;
            case 4://β��
                cout << "�Ӻ�˽��ӣ�β����..." << endl;
		        cout << "������һ���ַ�:" << endl;
                cin>>e;
                push_back(DuQ,e);
                break;
            case 5://β��
                 cout <<"�Ӻ�˳��ӣ�β����..."<< endl;
                pop_back(DuQ,x);
                cout << "����Ԫ��Ϊ" <<x<< endl;
                break;
             case 6://ȡ��ͷԪ��
                cout <<"ȡ��ͷԪ��..."<< endl;
                get_front(DuQ,x);
                cout << "��ͷԪ��Ϊ" <<x<< endl;
                break;
            case 7://ȡ��βԪ��
                cout <<"ȡ��βԪ��..."<< endl;
                get_back(DuQ,x);
                cout << "��βԪ��Ϊ" <<x<< endl;
                break;
            case 8://��ӳ�
                cout << "˫�˶��г��ȣ�"<<length(DuQ)<<endl;
                break;
            case 9://����
                traverse(DuQ);
                break;
        }
	}
    return 0;
}
