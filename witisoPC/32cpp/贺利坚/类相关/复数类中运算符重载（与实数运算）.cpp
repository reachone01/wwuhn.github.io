#include <iostream>
using namespace std;
class Complex
{ // ��Ŀ����������ض���Ϊ��Ԫ������һĿ���������Ϊ��Ա���������ǹ��õ�������
public:
    Complex(){real=0;imag=0;}
    Complex(double r,double i){real=r;imag=i;}
    Complex operator-();
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
    void display();
private:
    double real;
    double imag;
};

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

void Complex::display()
{
    cout<<"("<<real<<","<<imag<<"i)"<<endl;
}

int main()
{
    Complex c1(3,4),c2(5,-10),c3;
    double d=11;
    cout<<"c1="; c1.display();
    cout<<"c2="; c2.display();
    cout<<"d="<<d<<endl;
    cout<<"-c1=";(-c1).display();
    c3=c1+c2;
    cout<<"c1+c2="; c3.display();
    cout<<"c1+d=";	(c1+d).display();
    cout<<"d+c1=";	(d+c1).display();
    c3=c1-c2;
    cout<<"c1-c2="; c3.display();
    cout<<"c1-d=";	(c1-d).display();
    cout<<"d-c1=";	(d-c1).display();
    c3=c1*c2;
    cout<<"c1*c2="; c3.display();
    cout<<"c1*d=";	(c1*d).display();
    cout<<"d*c1=";	(d*c1).display();
    c3=c1/c2;
    cout<<"c1/c2=";	c3.display();
    cout<<"c1/d=";	(c1/d).display();
    cout<<"d/c1=";	(d/c1).display();
    
    system("pause");
    return 0;
}