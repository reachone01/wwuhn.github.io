// ��������ֱ����

#include<iostream>
#include<Cmath>
using namespace std;

class Point //�����������
{
public:
    Point():x(0),y(0) {};
    Point(double x0, double y0):x(x0), y(y0) {};
    double getX()
    {
        return x;
    }
    double getY()
    {
        return y;
    }
    void PrintPoint(); //��������Ϣ
private:
    double x,y;   //��ĺ������������
};
void Point::PrintPoint()
{
    cout<<"Point:("<<x<<","<<y<<")";    //�����
}
 
class Line: public Point   //����������ඨ��ֱ����, ���������ݳ�Ա��ʾֱ�ߵ��е�
{
public:
    Line(Point pts, Point pte);  //���캯�����ó�ʼ��ֱ�ߵ������˵㼰�ɻ������ݳ�Ա�������е�
    double Length();    //���㲢����ֱ�ߵĳ���
    void PrintLine();   //���ֱ�ߵ������˵��ֱ�߳���
private:
    class Point pts,pte;   //ֱ�ߵ������˵�
};
//���캯�����ֱ��ó�ʼ��ֱ�ߵ������˵㼰�ɻ������ݳ�Ա(����)�������е�
Line::Line(Point pt1, Point pt2):Point((pt1.getX()+pt2.getX())/2,(pt1.getY()+pt2.getY())/2)
{
    pts=pt1;
    pte=pt2;
}
double Line::Length()  //���㲢����ֱ�ߵĳ���
{
    double dx = pts.getX() - pte.getX();
    double dy =pts.getY() - pte.getY();
    return sqrt(dx*dx+dy*dy);
}
void Line::PrintLine()
{
    cout<<" 1st ";
    pts.PrintPoint();
    cout<<"\n 2nd ";
    pte.PrintPoint();
    cout<<"\n The Length of Line: "<<Length()<<endl;
}
int main()
{
    Point ps(-2,5),pe(7,9);
    Line l(ps,pe);
    l.PrintLine();//���ֱ��l����Ϣ
    cout<<"\n The middle point of Line: ";
    l.PrintPoint() ;//���ֱ��l�е����Ϣ
    while(1);
    return 0;
}