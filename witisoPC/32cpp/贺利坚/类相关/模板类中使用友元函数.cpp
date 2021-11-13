#include <iostream>  // ģ������ʹ����Ԫ���� , ���߿�������
using namespace std;

template<class T1>
class Complex
{
public:
    Complex( ){real=0;imag=0;}
    Complex(T1 r,T1 i){real=r;imag=i;}
    Complex complex_add(const Complex &c2);
    template<class T2> friend Complex<T2> add_complex(const Complex<T2> &c1, const Complex<T2> &c2);   //������ģ����ⲿ����Ҫ��Ϊ��Ԫ������ע��������ʽ����������Ҳ�������ģ����������һ�г��������CodeBlocks�е���ͨ������T2����T1��VS2008Ҳ����
    void display( );
private:
    T1 real;
    T1 imag;
};

template<class T1>
Complex<T1> Complex<T1>::complex_add(const Complex<T1> &c2)
{
    Complex<T1> c;
    c.real=real+c2.real;
    c.imag=imag+c2.imag;
    return c;
}

//������ģ�����Ԫ�����Ķ���
template<class T1>
Complex<T1> add_complex(const Complex<T1> &c1, const Complex<T1> &c2)
{
    Complex<T1> c;
    c.real=c1.real+c2.real;
    c.imag=c1.imag+c2.imag;
    return c;
}

template<class T1>
void Complex<T1>::display( )
{
    cout<<"("<<real<<","<<imag<<"i)"<<endl;
}

int main( )
{
    Complex<int> c1(3,4),c2(5,-10),c3;
    c3=c1.complex_add(c2);  //��Ҫ��ģ��������һ����Ա����֧�ּӷ����㣬��һ���β�
    cout<<"c1+c2=";
    c3.display( );
    Complex<double> c4(3.1,4.4),c5(5.34,-10.21),c6;
    c6=c4.complex_add(c5);
    cout<<"c4+c5=";
    c6.display( );
    Complex<int> c7;
    c7=add_complex(c1,c2);  //��Ҫ��ģ��������һ����Ա����֧�ּӷ����㣬�������β�
    cout<<"c1+c2=";
    c7.display( );
    while(1);
    return 0;
}