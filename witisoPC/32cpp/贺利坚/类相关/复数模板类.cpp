#include <iostream>   // ����ģ����
using namespace std;

template<class T>  //������ǰ��ģ�������
class Complex  
{
public:
    Complex( ){real=0;imag=0;}    
    Complex(T r,T i){real=r;imag=i;}   //�������е�ÿһ��T������������ʱ�ṩ��ʵ�����ʹ���
    Complex complex_add(Complex &c2);
    Complex complex_minus(Complex &c2);
    Complex complex_multiply(Complex &c2);
    Complex complex_divide(Complex &c2);
    void display( );  
private:
    T real;   //���ݳ�Ա�����ͣ�Ҳ����������ʱ�ṩ��ʵ�����ʹ���
    T imag;
};

//������ӣ� (a+bi)+(c+di)=(a+c)+(b+d)i.
template<class T>  //ÿһ����Ա�����Ķ���ǰ������Ҫ������ģ��
Complex<T> Complex<T>::complex_add(Complex<T> &c2)  //ʹ����ģ����࣬�����ٶ���ʹ�ã���������������ʾΪ����ģ����<�������Ͳ���>��
{
    Complex<T> c;   //���õ�������Ҳ�á���ģ����<�������Ͳ���>����ʽ�������������������ĺͣ���ȻҪ����һ���µĸ�������
    c.real=real+c2.real;
    c.imag=imag+c2.imag;
    return c;
}


//���������(a+bi)-(c+di)=(a-c)+(b-d)i.
template <class T>    
Complex<T> Complex<T>::complex_minus(Complex <T> &c2)    
{    
    Complex <T> c;    
    c.real=real-c2.real;    
    c.imag=imag-c2.imag;    
    return c;    
}    

//������ˣ�(a+bi)(c+di)=(ac��bd)+(bc+ad)i.
template <class T>    
Complex<T> Complex<T>::complex_multiply(Complex <T> &c2)     
{    
    Complex <T> c;    
    c.real=real*c2.real-imag*c2.imag;    
    c.imag=imag*c2.real+real*c2.imag;    
    return c;    
}    

//���������(a+bi)/(c+di)=(ac+bd)/(c^2+d^2) +(bc-ad)/(c^2+d^2)i
template <class T>    
Complex<T> Complex<T>::complex_divide(Complex <T> &c2)     
{    
    Complex <T> c;    
    T d=c2.real*c2.real+c2.imag*c2.imag;
    c.real=(real*c2.real+imag*c2.imag)/d;     //�˴���Σ��δ�ų����������
    c.imag=(imag*c2.real-real*c2.imag)/d;    
    return c;    
} 

template<class T>
void Complex<T>::display( )  
{
    cout<<"("<<real<<","<<imag<<"i)"<<endl;
}

int main( )
{
    Complex<int> c1(3,4),c2(5,-10),c3; //�������ʱ���á���ģ����<ʵ��������>����ʽ
    c3=c1.complex_add(c2); 
    cout<<"c1+c2=";
    c3.display( ); 
    Complex<double> c4(3.1,4.4),c5(5.34,-10.21),c6; //�������ʱ���á���ģ����<ʵ��������>����ʽ
    c6=c4.complex_add(c5); 
    cout<<"c4+c5=";
    c6.display( );
    
    
    c6=c4.complex_minus(c5); 
    cout<<"c4-c5=";
    c6.display( );
    
    
    c6=c4.complex_multiply(c5); 
    cout<<"c4*c5=";
    c6.display( );
    
    
    c6=c4.complex_divide(c5); 
    cout<<"c4/c5=";
    c6.display( );
    
    
    system("pause");
    return 0;
}