#include <iostream>  // �õ�������Ա����������
#include <Cmath>
using namespace std;

class CPoint
{
private:
    double x;  // ������          
    double y;  // ������
public:
    CPoint(double xx=0,double yy=0);
    double distance(CPoint p) const;   // ����֮��ľ���
    void input();  //��x,y ��ʽ���������
    void output(); //��(x,y) ��ʽ��������
};

class CTriangle
{
public:
    CTriangle(CPoint &X,CPoint &Y,CPoint &Z):A(X),B(Y),C(Z){} //��������Ĺ��캯��
    void setTriangle(CPoint &X,CPoint &Y,CPoint &Z);//
    double perimeter(void);     //���������ε��ܳ�
    double area(void);          //���㲢���������ε����
    bool isRightTriangle();     //�Ƿ�Ϊֱ��������
    bool isIsoscelesTriangle(); //�Ƿ�Ϊ����������
private:
    CPoint A,B,C; //������
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
double CPoint::distance(CPoint p) const
{
    double d;
    d=sqrt((p.x-x)*(p.x-x)+(p.y-y)*(p.y-y));
    return d;
}

void CTriangle::setTriangle(CPoint &X,CPoint &Y,CPoint &Z)
{
    A=X;
    B=Y;
    C=Z;
}

double CTriangle::perimeter(void)
{
    double a=B.distance(C),b=C.distance(A),c=A.distance(B);
    return (a + b + c);
}

double CTriangle::area(void)
{
    double a=B.distance(C),b=C.distance(A),c=A.distance(B);
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

bool CTriangle::isRightTriangle()//�Ƿ�Ϊֱ��������
{
    double a=B.distance(C),b=C.distance(A),c=A.distance(B);
    double max=a;
    if(b>max) max=b;
    if(c>max) max=c;
    if(((max==a)&&(abs(a*a-b*b-c*c)<1e-7))||((max==b)&&(abs(b*b-a*a-c*c)<1e-7))||((max==c)&&(abs(c*c-b*b-a*a)<1e-7)))
        return true;
    else
        return false;
}
bool CTriangle::isIsoscelesTriangle() //�Ƿ�Ϊ����������
{
    double a=B.distance(C),b=C.distance(A),c=A.distance(B);
    if((abs(a-b)<1e-7)||(abs(b-c)<1e-7)||(abs(c-a)<1e-7))
        return true;
    else
        return false;
}

int main()
{
    CPoint X(2,5),Y(5,2),Z(7,8);
    CTriangle Tri1(X,Y,Z);  //�������������һ��ʵ��������
    cout<<"�������ε��ܳ�Ϊ��"<<Tri1.perimeter()<<"�����Ϊ��"<<Tri1.area()<<endl<<endl;
    cout<<"��������"<<(Tri1.isRightTriangle()?"��":"����")<<"ֱ��������"<<endl;
    cout<<"��������"<<(Tri1.isIsoscelesTriangle()?"��":"����")<<"����������"<<endl;
    return 0;
}