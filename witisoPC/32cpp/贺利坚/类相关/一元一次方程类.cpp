#include "iostream"    // һԪһ�η�����
using namespace std;
class CEquation
{
private:
	double a;     // δ֪��ϵ��
	double b;     // ������
	char unknown; // δ֪���ķ���
public:
	CEquation(double aa=0,double bb=0);
	friend istream &operator >> (istream &in,CEquation &e);
	friend ostream &operator << (ostream &out,CEquation &e);
	double Solve();
	char getUnknown();
};
 
CEquation::CEquation(double aa,double bb):a(aa),b(bb){}
 
// ���뷽��
istream &operator >> (istream &in,CEquation &e)
{
	char ch1,ch2,ch3,ch4;
	while(1)
	{
		cin>>e.a>>ch1>>ch2>>e.b>>ch3>>ch4;
		if (ch1>='a' && ch1<='z')
			if ((ch2=='+' || ch2=='-') && ch3=='=' && ch4=='0') break;
		cout<<"����ķ��̸�ʽ�����Ϲ淶������������\n";
	}
	if (ch2=='-') e.b=-e.b;
	e.unknown=ch1;
	return in;
}
 
// �������
ostream &operator << (ostream &out,CEquation &e)
{
	cout<<e.a<<e.unknown;
	if (e.b>=0) cout<<"+";
	cout<<e.b<<"=0"<<endl;
	return out;
}
 
// ���
double CEquation::Solve()
{
	double x;
	if (a==0)
	{
		if (b==0) cout<<"����һ��ʵ����Ϊ���̵Ľ⡣"<<endl;
		else cout<<"�����޽⡣"<<endl;
		return 0;
	}
	x=-b/a;
	return x;
}
 
char CEquation::getUnknown()
{
	return unknown;
}
 
int main()
{
	CEquation e;
	cout<<"������һԪһ�η���(�����ʽ��3x-8=0)��";
	cin>>e;   //�����β����У��ֱ�����3x-8=0��5s+18=0
	cout<<"����Ϊ��"<<e;
	cout<<"���̵Ľ�Ϊ��"<<e.getUnknown()<<"="<<e.Solve()<<endl; //�����β��ԣ��ֱ����x=...��s=...
	e.Solve();
	system("pause");
	return 0;
}