#include <iostream>
using namespace std;
class CFraction
{
private:
	int nume;  // ����
	int deno;  // ��ĸ
public:
	CFraction(int nu=0,int de=1):nume(nu),deno(de){}
	void simplify();
 
	//�������������
	friend istream &operator>>(istream &in,CFraction &x);
	friend ostream &operator<<(ostream &out,CFraction x);
	
	CFraction operator+(const CFraction &c);  //����������ӣ����Ҫ����
	CFraction operator-(const CFraction &c);  //����������������Ҫ����
	CFraction operator*(const CFraction &c);  //����������ˣ����Ҫ����
	CFraction operator/(const CFraction &c);  //����������������Ҫ����
	CFraction operator+();  //ȡ��һĿ����
	CFraction operator-();  //ȡ��һĿ����
	bool operator>(const CFraction &c);
	bool operator<(const CFraction &c);
	bool operator==(const CFraction &c);
	bool operator!=(const CFraction &c);
	bool operator>=(const CFraction &c);
	bool operator<=(const CFraction &c);
};
 
// ��������
void CFraction::simplify()
{
	int m,n,r;
	m=abs(deno);
	n=abs(nume);
	while(r=m%n)  // ��m��n�����Լ��
	{
		m=n;
		n=r;
	}
	deno/=n;     // ����
	nume/=n;
	if (deno<0)  // ����ĸת��Ϊ����
	{
		deno=-deno;
		nume=-nume;
	}
}
 
// �������������>>
istream &operator>>(istream &in,CFraction &x)
{
	char ch;
	while(1)
	{
		cin>>x.nume>>ch>>x.deno;
		if (x.deno==0) 
			cerr<<"��ĸΪ! ����������\n";
		else if(ch!='/')
			cerr<<"��ʽ��������m/n��! ����������\n";
		else
			break;
	}
	return cin;
}
 
// ������������<<
ostream &operator<<(ostream &out,CFraction x)
{
	cout<<x.nume<<'/'<<x.deno;
	return cout;
}
 
// �������
CFraction CFraction::operator+(const CFraction &c)
{
	CFraction t;
	t.nume=nume*c.deno+c.nume*deno;
	t.deno=deno*c.deno;
	t.simplify();
	return t;
}
 
// �������
CFraction CFraction:: operator-(const CFraction &c)
{
	CFraction t;
	t.nume=nume*c.deno-c.nume*deno;
	t.deno=deno*c.deno;
	t.simplify();
	return t;
}
 
// �������
CFraction CFraction:: operator*(const CFraction &c)
{
	CFraction t;
	t.nume=nume*c.nume;
	t.deno=deno*c.deno;
	t.simplify();
	return t;
}
 
// �������
CFraction CFraction:: operator/(const CFraction &c)
{
	CFraction t;
	if (!c.nume) return *this;   //������Ч������Ϊ��ʱ�����������Ҫ���ǣ������ִ����Բ������
	t.nume=nume*c.deno;
	t.deno=deno*c.nume;
	t.simplify();
	return t;
}
 
// ����ȡ����
CFraction CFraction:: operator+()
{
	return *this;
}
 
// ����ȡ����
CFraction CFraction:: operator-()
{
	CFraction x;
	x.nume=-nume;
	x.deno=deno;
	return x;     
}
 
// �����Ƚϴ�С
bool CFraction::operator>(const CFraction &c)
{
	int this_nume,c_nume,common_deno;
	this_nume=nume*c.deno;        // �������ͨ�ֺ�ķ��ӣ�ͬ��ĸΪdeno*c.deno
	c_nume=c.nume*deno; 
	common_deno=deno*c.deno;
	if ((this_nume-c_nume)*common_deno>0) return true;
	return false;
}
 
// �����Ƚϴ�С
bool CFraction::operator<(const CFraction &c)
{
	int this_nume,c_nume,common_deno;
	this_nume=nume*c.deno;      
	c_nume=c.nume*deno;
	common_deno=deno*c.deno;
	if ((this_nume-c_nume)*common_deno<0) return true; 
	return false;
}
 
// �����Ƚϴ�С
bool CFraction::operator==(const CFraction &c)
{
	if (*this!=c) return false;
	return true;
}
 
// �����Ƚϴ�С
bool CFraction::operator!=(const CFraction &c)
{
	if (*this>c || *this<c) return true;
	return false;
}
 
// �����Ƚϴ�С
bool CFraction::operator>=(const CFraction &c)
{
	if (*this<c) return false;
	return true;
}
 
// �����Ƚϴ�С
bool CFraction::operator<=(const CFraction &c)
{
	if (*this>c) return false;
	return true;
}
 
int main()
{
	CFraction x,y,s;
	cout<<"����x: ";
	cin>>x;
	cout<<"����y: ";
	cin>>y;
	s=+x+y;
	cout<<"+x+y="<<s<<endl;
	cout<<"x-y="<<s<<endl;
	s=x*y;
	cout<<"x*y="<<s<<endl;
	s=x/y;
	cout<<"x/y="<<s<<endl;
	s=-x+y;
	cout<<"-x+y="<<s<<endl;
	
	cout<<x;
	if (x>y) cout<<"����";
	if (x<y) cout<<"С��";
	if (x==y) cout<<"����";
	cout<<y<<endl;
	system("pause");
	return 0;
}