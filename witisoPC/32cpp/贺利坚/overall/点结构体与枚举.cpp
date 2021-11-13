#include "iostream"   // ��ṹ����ö��
#include "Cmath"
using namespace std;

enum SymmetricStyle {axisx,axisy,point};//�ֱ��ʾ��x��, y��, ԭ��Գ�
struct Point
{
    double x;  // ������
    double y;  // ������
};
double distance(Point p1, Point p2);                // ����֮��ľ���
double distance0(Point p1);                         // p1��ԭ��ľ���
Point symmetricAxis(Point p,SymmetricStyle style);  // ���ضԳƵ�(����x��y���ԭ��Գ�)

int main( )
{
    Point p1={1,5},p2={4,1},p;
    cout<<"����ľ���Ϊ��"<<distance(p1,p2)<<endl;
    cout<<"p1��ԭ��ľ���Ϊ��"<<distance0(p1)<<endl;
    p=symmetricAxis(p1,axisx);
    cout<<"p1����x��ĶԳƵ�Ϊ��"<<"("<<p.x<<", "<<p.y<<")"<<endl;
    p=symmetricAxis(p1,axisy);
    cout<<"p1����y��ĶԳƵ�Ϊ��"<<"("<<p.x<<", "<<p.y<<")"<<endl;
    p=symmetricAxis(p1,point);
    cout<<"p1����ԭ��ĶԳƵ�Ϊ��"<<"("<<p.x<<", "<<p.y<<")"<<endl;
    return 0;
}

// ������֮��ľ���
double distance(Point p1,Point p2)
{
    double d;
    d=sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
    return d;
}

// ��㵽ԭ��ľ���
double distance0(Point p)
{
    double d;
    d=sqrt(p.x*p.x+p.y*p.y);
    return d;
}

// ��ԳƵ�
Point symmetricAxis(Point p1,SymmetricStyle style)
{
    Point p;
    p.x=p1.x;
    p.y=p1.y;
    switch(style)
    {
    case axisx:
        p.y=-p1.y; break;
    case axisy:
        p.x=-p1.x; break;
    case point:
        p.x=-p1.x;p.y=-p1.y;
    }
    return p;
}