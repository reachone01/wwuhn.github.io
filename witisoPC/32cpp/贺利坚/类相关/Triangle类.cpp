#include<iostream>  // Triangle��
#include<Cmath>
using namespace std;

class Triangle
{
public:
    void Setabc(float x, float y, float z);     //�����ߵ�ֵ��ע��Ҫ�ܳ�������
    void Getabc(float *x, float *y, float *z);  //ȡ���ߵ�ֵ
    float Perimeter(void);                      //���������ε��ܳ�
    float Area(void);                           //���㲢���������ε����
private:
    float a,b,c;            //����Ϊ˽�г�Ա����
};

int main(void)
{
    Triangle  Tri1;	        //�������������һ��ʵ��������
    Tri1.Setabc(4,5,6);	    //Ϊ�����ó�ֵ
    float x,y,z;
    Tri1.Getabc(&x,&y,&z);   //�����ߵ�ֵΪx,y,z��ֵ
    cout<<"������Ϊ��"<<x<<'\t'<<y<<'\t'<<z<<endl;
    cout<<"�����ε��ܳ�Ϊ��"<< Tri1.Perimeter()<<'\t'<<"���Ϊ��"<< Tri1.Area()<<endl;
    system("PAUSE");  //��VS�����У���һ������Ҫ�ģ�����������"һ������"
    return;
}

void Triangle::Setabc(float x, float y, float z)
{
    if(x+y>z&&x+z>y&&y+z>x)
    {
        a=x;
        b=y;
        c=z;
    }
    else //�����������Ҳ���ã������кθ��У�
    {
        a=0;
        b=0;
        c=0;
    }
}

void Triangle::Getabc(float *x, float *y, float *z)
{
    *x=a;
    *y=b;
    *z=c;
}

float Triangle::Perimeter(void)
{
    return a+b+c;
}

float Triangle::Area(void)
{
    float p=(a+b+c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}