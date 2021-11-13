#include <iostream>  // �����������������أ�ע���������λ���Լ�����ֵ��
                 // ��Ҫ����Ԫ����Ϊ��һ��������������������������Ҫ���������ã�������ʽ����
using namespace std;
class Complex
{
public:
	Complex(){real=0;imag=0;}
	Complex(double r,double i){real=r;imag=i;}
	Complex operator-();
	//ʵ�����롢��������������
	friend ostream& operator << (ostream& output,Complex& c);
	friend istream& operator >> (istream& input,Complex& c);
	//ʵ�ּӼ��˳������������
	friend Complex operator+(Complex &c1, Complex &c2);
	friend Complex operator+(double d1, Complex &c2);
	friend Complex operator+(Complex &c1, double d2);
	friend Complex operator-(Complex &c1, Complex &c2);
	friend Complex operator-(double d1, Complex &c2);
	friend Complex operator-(Complex &c1, double d2);
	friend Complex operator*(Complex &c1, Complex &c2);
	friend Complex operator*(double d1, Complex &c2);
	friend Complex operator*(Complex &c1, double d2);
	friend Complex operator/(Complex &c1, Complex &c2);
	friend Complex operator/(double d1, Complex &c2);
	friend Complex operator/(Complex &c1, double d2);
private:
	double real;
	double imag;
};
 
//ʵ����������������
ostream& operator << (ostream& output,Complex& c)
{	output<<"("<<c.real;
	if(c.imag>=0) output<<"+";  
	output<<c.imag<<"i)";    
	return output;
}
 
//ʵ����������������
istream& operator >> (istream& input,Complex& c)
{	int a,b;
	char sign,i;
	do
	{	cout<<"input a complex number(a+bi��a-bi):";
		input>>a>>sign>>b>>i;
	}
	while(!((sign=='+'||sign=='-')&&i=='i'));
	c.real=a;
	c.imag=(sign=='+')?b:-b;
	return input;
}
 
 
Complex Complex::operator-()
{
	return(0-*this);
}
 
//������ӣ�(a+bi)+(c+di)=(a+c)+(b+d)i. 
Complex operator+(Complex &c1, Complex &c2)
{
	Complex c;
	c.real=c1.real+c2.real;
	c.imag=c1.imag+c2.imag;
	return c;
}
Complex operator+(double d1, Complex &c2)
{
	Complex c(d1,0);
	return c+c2; //�����㷨������ȷ���ԣ�����������Ѿ�����õĴ��룬��ʡ������Ҳ���������µĴ��󣬵����ܻ�����Ч�ʻ᲻��
}
Complex operator+(Complex &c1, double d2)
{
	Complex c(d2,0);
	return c1+c;
}
//���������(a+bi)-(c+di)=(a-c)+(b-d)i.
Complex operator-(Complex &c1, Complex &c2)
{
	Complex c;
	c.real=c1.real-c2.real;
	c.imag=c1.imag-c2.imag;
	return c;
}
Complex operator-(double d1, Complex &c2)
{
	Complex c(d1,0);
	return c-c2;  
}
Complex operator-(Complex &c1, double d2)
{
	Complex c(d2,0);
	return c1-c;
}
 
//������ˣ�(a+bi)(c+di)=(ac��bd)+(bc+ad)i.
Complex operator*(Complex &c1, Complex &c2)
{
	Complex c;
	c.real=c1.real*c2.real-c1.imag*c2.imag;
	c.imag=c1.imag*c2.real+c1.real*c2.imag;
	return c;
}
Complex operator*(double d1, Complex &c2)
{
	Complex c(d1,0);
	return c*c2;
}
Complex operator*(Complex &c1, double d2)
{
	Complex c(d2,0);
	return c1*c;
}
 
//���������(a+bi)/(c+di)=(ac+bd)/(c^2+d^2) +(bc-ad)/(c^2+d^2)i 
Complex operator/(Complex &c1, Complex &c2)
{
	Complex c;
	c.real=(c1.real*c2.real+c1.imag*c2.imag)/(c2.real*c2.real+c2.imag*c2.imag);
	c.imag=(c1.imag*c2.real-c1.real*c2.imag)/(c2.real*c2.real+c2.imag*c2.imag);
	return c;
}
Complex operator/(double d1, Complex &c2)
{
	Complex c(d1,0);
	return c/c2;
}
 
Complex operator/(Complex &c1, double d2)
{
	Complex c(d2,0);
	return c1/c;
}
 
int main()
{
	Complex c1,c2,c3;
	double d=11;
	cout<<"c1: "<<endl;; 
	cin>>c1;          
	cout<<"c2: "<<endl;
	cin>>c2;
	cout<<"c1="<<c1<<endl;
	cout<<"c2="<<c2<<endl;
	cout<<"d="<<d<<endl;
	cout<<"-c1="<<(-c1);
	c3=c1+c2;
	cout<<"c1+c2="<<c3<<endl;
	cout<<"c1+d="<<(c1+d)<<endl;
	cout<<"d+c1="<<(d+c1)<<endl;
	c3=c1-c2;
	cout<<"c1-c2="<<c3<<endl;
	cout<<"c1-d="<<(c1-d)<<endl;
	cout<<"d-c1="<<(d-c1)<<endl;
	c3=c1*c2;
	cout<<"c1*c2="<<c3<<endl;
	cout<<"c1*d="<<(c1*d)<<endl;
	cout<<"d*c1="<<(d*c1)<<endl;
	c3=c1/c2;
	cout<<"c1/c2="<<c3<<endl;
	cout<<"c1/d="<<(c1/d)<<endl;
	cout<<"d/c1="<<(d/c1)<<endl;
 
	system("pause");
	return 0;
}