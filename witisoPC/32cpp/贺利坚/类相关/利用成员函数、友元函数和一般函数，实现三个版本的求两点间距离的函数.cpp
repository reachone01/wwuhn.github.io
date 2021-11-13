#include<iostream> // ���ó�Ա��������Ԫ������һ�㺯����ʵ�������汾������������ĺ���
#include<Cmath>
using namespace std;

class CPoint  
{
private:  
    double x;  // ������ 
    double y;  // ������ 
public: 
    CPoint(double xx=0,double yy=0):x(xx),y(yy){}  
    double distance_mem(CPoint &); //������const CPoint &����
    friend double distance_fri(CPoint &, CPoint &) ;
    double getX(){return x;}
    double getY(){return y;}
};

double distance_glo(CPoint &,CPoint &) ;

double CPoint::distance_mem(CPoint &p) 
{
    double dx=(x-p.x), dy=y-p.y; 
    return sqrt(dx*dx+dy*dy);
}

double distance_fri(CPoint &p1,CPoint &p2) 
{
    double dx=(p1.x-p2.x), dy=p1.y-p2.y; 
    return sqrt(dx*dx+dy*dy);
}

double distance_glo(CPoint &p1,CPoint &p2) 
{
    double dx=(p1.getX()-p2.getX()), dy=p1.getY()-p2.getY(); 
    return sqrt(dx*dx+dy*dy);
}

int main()
{	
    CPoint p1(10,13), p2(-5,6);
    cout<<"(10,13), (-5,6)�����ľ��룺"<<endl;
    cout<<"1. "<<p1.distance_mem(p2)<<endl;
    cout<<"2. "<<distance_fri(p1,p2)<<endl;
    cout<<"3. "<<distance_glo(p1,p2)<<endl;
    system("pause");
    return 0;
}