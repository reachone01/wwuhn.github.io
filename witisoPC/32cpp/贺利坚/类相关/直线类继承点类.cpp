#include<iostream>    // ֱ����̳е���
#include<Cmath>
using namespace std;

class Point //�����������
{
public:
    double x,y;   //��ĺ������������
    Point(){x=0;y=0;}
    Point(double x0, double y0) {x=x0; y=y0;}
    void PrintP(){cout<<"Point:("<<x<<","<<y<<")";}
};

class Line: public Point   //����������ඨ��ֱ����, ���������ݳ�Ա��ʾֱ�ߵ��е�
{
private:
    class Point pt1,pt2;   //ֱ�ߵ������˵�
public:
    Line(Point pts, Point pte);  //���캯��
    double Dx(){return pt2.x-pt1.x;}
    double Dy(){return pt2.y-pt1.y;}
    double Length();//����ֱ�ߵĳ���
    void PrintL();  //���ֱ�ߵ������˵��ֱ�߳���
};

//(1)���캯�����ֱ��ò�����ʼ����Ӧ�Ķ˵㼰�ɻ��������������е�
Line::Line(Point pts, Point pte):Point((pts.x+pte.x)/2,(pts.y+pte.y)/2) {pt1=pts;pt2=pte;} //����ָ�����˴��ؼ�����������ʼ��ʱ���Բ���

double Line::Length(){return sqrt(Dx()*Dx()+Dy()*Dy());};//(2)����ֱ�ߵĳ���

void Line::PrintL()
{
    cout<<" 1st ";
    pt1.PrintP();
    cout<<"\n 2nd ";
    pt2.PrintP();
    cout<<"\n The middle point of Line: ";
    PrintP();
    cout<<"\n The Length of Line: "<<Length()<<endl; //(3)���ֱ�߳���
}

int main()
{
    Point ps(-2,5),pe(7,9);
    Line l(ps,pe);
    l.PrintL(); //(4)���ֱ��l����Ϣ
    l.PrintP(); //(5)���ֱ��l�е����Ϣ���˴��ٴ���᣺������Ķ������������ṩ�ĳ�Ա����
    system("pause");
    return 0;
}
