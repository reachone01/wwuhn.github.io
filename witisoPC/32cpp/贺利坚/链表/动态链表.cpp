/*
��̬����Ҳ�ǳ�������е�һ�ַǳ����õ����ݽṹ������˵���Ƿ��ܹ�����йز�����ԭ��
���������Ƿ����ʸ��Ϊ���ưࡱ����
*/
#include<iostream>
using namespace std;
 
class Student
{                          
public:
	Student(int n,double s){num=n;score=s;next=NULL;}
	Student *next;
	int num;
	double score;
};
 
class MyList
{
public:
	MyList(){head=NULL;}
	MyList(int n,double s){head=new Student(n,s);} //��Student(n,s)��Ϊ����������
	int display();                      //�����������ֵΪ�����еĽ����
	void insert(int n,double s);        //���룺��Student(n,s)�����������ý����Ϊ��һ�����
	void append(int n,double s);        //׷�ӣ���Student(n,s)�����������ý����Ϊ���һ�����
	void cat(MyList &il);               //������il���ӵ���ǰ����ĺ���
	int length();                       //���������еĽ����
private:
	Student *head;
};
 
int MyList::display()
{
	if(head==NULL)
	{
		cout<<"empty\n";
		return 0;
	}
	int cnt=0;
	Student *pt=head;
	while(pt)
	{
		++cnt;
		cout<<pt->num<<" "<<pt->score<<endl;
		pt=pt->next;
	}
	return cnt;
}
 
void MyList::insert(int n, double s)
{
	Student * pt=new Student(n,s);
	pt->next =head;
	head=pt;
}
 
void MyList::append(int n,double s)
{
	Student * pt=new Student(n,s);
	if(head==NULL)
		head=pt;
	else 
	{
		Student *pts=head;
		Student *pte=pts->next;
		while(pte)
		{
			pts=pte;
			pte=pts->next;
		}
		pts->next=pt;
	}
}
 
void MyList::cat(MyList& il)
{
	Student *pt=il.head;
	while(pt)
	{
		append(pt->num,pt->score);
		pt=pt->next;
	}
}
 
int MyList::length()
{
	int cnt=0;
	Student *pt=head;
	while(pt)
	{
		++cnt;
		pt=pt->next ;
	}
	return cnt;
}
 
int main()
{
	int n;
	double s;
	MyList head1;
	cout<<"input ����Ԫ�أ�ѧ�� ������: "<<endl;  //����head1����
	for(int i=0;i<3;i++)
	{
		cin>>n>>s;
		head1.insert(n,s);                      //ͨ�������롱�ķ�ʽ
	}
	cout<<"head1: "<<endl;                      //���head1
	head1.display();
 
	MyList head2(1001,98.4);    //����head2����
	head2.append(1002,73.5);    //ͨ����׷�ӡ��ķ�ʽ���ӽ��
	head2.append(1003,92.8);
	head2.append(1004,99.7);
	cout<<"head2: "<<endl;      //���head2
	head2.display();
 
	head2.cat(head1);                   //��head1׷�ӵ�head2����
	cout<<"length of head2 after cat: "<<head2.length()<<endl;
	cout<<"head2 after cat: "<<endl;    //��ʾ׷�Ӻ�Ľ��
	head2.display();
 
	system("pause");
	return 0;
}

/*

������չһ��ѡ������
���������еĽ��ֻ�����������ѧ�źͷ�����ѧ����Ϣ����ν�֮��������Ӧ�ã�
һ�ְ취���޸�Student�࣬����ѧ�������������䡭����Students��Ҳ�ɻ�����������������ࡣ
����ƽ���һ����̬����������5����㣬�ֱ�����5�������Σ���ͷ��㿪ʼ��
�����������ε���Ϣ��

��������չ����ѡ������

��������Ĵ�����Ȼ�����������ԣ�ֻ�ܾ������µ�����������ƵĴ�ɡ�
ʵ���ϣ��������Ϳ��Զ���Ϊ����ģ���ࣺ

template <class T>
class Node
{     
public:
	Node *next;
	T data;
};
������������һ�����ݡ��ؽ����data�����ͣ�ֻҪ�ڶ�����ʱ����T����ʵ�������ɡ�
�����T������Ҳ����Ҫ�漰�й�������ָ������ݡ�
�����밴����˼·��д����Ϊ�˲��ԣ���main()�����н���һ��MyArray<double>�Ͷ�����в��ԡ�
���⣬�ٽ���һ��MyArray<Triangle>�Ͷ�����в��ԣ�TriangleΪ�Զ����������ࣩ��
��������չ����ѡ������

����������ʵ�ֵ�����򵥵ĵ��������е�������Ĳ�����������������ϣ�
��������˫��������ͷ����β��㣬�����ǰ����ʹӺ���ǰ�ķ��ʣ���ʮ������ȣ�
���Ƶķ������Թ�����������������ͼ�����磬���������ṹ���Գ�������Ϊͼ��
�罻�������û��Ĺ�ϵҲ��ͼ�������õĽṹ�����Ӳ����Ƕȣ��������ڲ���ʱ��
�����ý�㱣�����򣻿��Դ������в���Ԫ�أ�
�ܶ��Ӧ�����漰���㷨��Ҫ���������ݽṹ���㷨����ƻ����ѵĴ������ܡ�
�����ⷽ������ݲ����Ծ����������ʽ�������ں�����רҵ�������н�����������
���⣬�г�����ƻ�����ͬѧ���ǿ����Լ���ǰ��һ�ߣ�
����صĽ̲ĺ��鼮�����ݽṹ���㷨�ࣩ��һ�����Ƿ��������Լ���������ǰ��һ���ˡ�

  */