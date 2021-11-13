#include "iostream"  // ƽ���������
#include "Cmath"
using namespace std;


class CPoint
{
private:
    double x;  // ������
    double y;  // ������
public:
    CPoint(double xx=0,double yy=0);
    double Distance(CPoint p) const;   // ����֮��ľ���
    double Distance0() const;          // ��ԭ��ľ���
    CPoint SymmetricAxis(char style) const;   // ���ضԳƵ�
    void input();  //��x,y ��ʽ���������
    void output(); //��(x,y) ��ʽ��������
};

CPoint::CPoint(double xx,double yy)
{
    x=xx;
    y=yy;
}

// ���������
void CPoint::input()
{
    char ch;
    cout<<"�����������(��ʽx,y )��";
    while(1)
    {
        cin>>x>>ch>>y;
        if (ch==',') break;
        cout<<"��������ݸ�ʽ�����Ϲ淶������������\n";
    }
}

// ��������
void CPoint::output()
{
    cout<<"("<<x<<", "<<y<<")"<<endl;
}

// ������֮��ľ���
double CPoint::Distance(CPoint p) const
{
    double d;
    d=sqrt((p.x-x)*(p.x-x)+(p.y-y)*(p.y-y));
    return d;
}

// ��㵽ԭ��ľ���
double CPoint::Distance0() const
{
    double d;
    d=sqrt(x*x+y*y);
    return d;
}

// ��ԳƵ�, styleȡ'x','y'��'o'�ֱ��ʾ��x��, y��, ԭ��Գ�
CPoint CPoint::SymmetricAxis(char style) const
{
    CPoint p(this->x,this->y);//�ø��ƹ��캯��ʱ��д��p(*this)
    switch(style)
    {
    case 'x':
        p.y=-y; break;
    case 'y':
        p.x=-x; break;
    case 'o':
        p.x=-x;p.y=-y;
    }
    return p;
}

int main( )
{
    double distance;
    CPoint p1,p2,p;
    cout<<"��1����p1��";
    p1.input();
    cout<<"��2����p2��";
    p2.input();
    distance=p1.Distance(p2);
    cout<<"����ľ���Ϊ��"<<distance<<endl;
    distance=p1.Distance0();
    cout<<"p1��ԭ��ľ���Ϊ��"<<distance<<endl;
    p=p1.SymmetricAxis('x');
    cout<<"p1����x��ĶԳƵ�Ϊ��";
    p.output();
    p=p1.SymmetricAxis('y');
    cout<<"p1����y��ĶԳƵ�Ϊ��";
    p.output();
    p=p1.SymmetricAxis('o');
    cout<<"p1����ԭ��ĶԳƵ�Ϊ��";
    p.output();
    return 0;
}