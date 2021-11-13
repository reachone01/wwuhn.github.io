/*
����Ŀ5��ѡ��������������̳�
��1���Ƚ���һ��Point(��)�࣬�������ݳ�Աx,y(�����)��
��2����PointΪ���࣬������һ��Circle(Բ)�࣬�������ݳ�Ա(�뾶)������ĳ�Ա��ʾԲ�ģ�
��3����д���������еĹ��졢������������Ҫ�������������
��4��������Ԫ����int locate���жϵ�p��Բc�ϡ�Բc�ڻ�Բc�⣬����ֵ<0Բ�ڣ�==0Բ�ϣ�>0 Բ�⣻
��5�����ع�ϵ�������6�֣��������ʹ֮�ܹ���Բ������Ƚ�����Բ�Ĵ�С��
��6������һ��p������õ���Բ�������ɵ�ֱ����Բ���������㲢���

*/
#if 1
#include <iostream.h>
#include<Cmath>

class Point
{
public:
	Point(double x=0,double y=0);		    //���캯��
	double distance(const Point &p) const;	//�����
	double getx() const {return x;} 
	double gety() const {return y;} 
	void setx(double x1){x=x1;}
	void sety(double y1){y=y1;}
	friend ostream & operator<<(ostream &,const Point &);//�����������<<��
protected:										 //�ܱ�����Ա
	double x,y;
};
 
 
//Point�Ĺ��캯��
Point::Point(double a,double b):x(a),y(b){}
 
double Point::distance(const Point &p) const	//�����
{
	double dx = x-p.x;
	double dy = y-p.y;
	return sqrt(dx*dx+dy*dy);
}
 
ostream & operator<<(ostream &output,const Point &p)
{
	output<<"["<<p.x<<","<<p.y<<"]"<<endl;
	return output;
}
 
class Circle:public Point //circle��Point��Ĺ���������
{
public:
	Circle(double x=0,double y=0,double r=0);   //���캯��
	double area ( ) const;                      //����Բ���
	friend ostream &operator<<(ostream &,const Circle &);//�����������<<��
	friend int locate(const Point &p, const Circle &c); //�жϵ�p��Բ�ϡ�Բ�ڻ�Բ�⣬����ֵ��<0Բ�ڣ�==0Բ�ϣ�>0 Բ��
	//���ع�ϵ��������֣��������ʹ֮�ܹ���Բ������Ƚ�����Բ�Ĵ�С��
	bool operator>(const Circle &);
	bool operator<(const Circle &);
	bool operator>=(const Circle &);
	bool operator<=(const Circle &);
	bool operator==(const Circle &);
	bool operator!=(const Circle &);
	//����һ��p������õ���Բc��Բ�������ɵ�ֱ����Բ����������p1��p2(Ϊ�˴��ؼ�������p1��p2��Ҫ����Ϊ����)
	friend void crossover_point(Point &p,Circle &c, Point &p1,Point &p2 ) ;
protected:
	double radius;
};
 
//���幹�캯������Բ������Ͱ뾶��ʼ��
Circle::Circle(double a,double b,double r):Point(a,b),radius(r){ }
 
//����Բ���
double Circle::area( ) const
{
	return 3.14159*radius*radius;
}
 
//�����������<<����ʹ֮���涨����ʽ���Բ����Ϣ
ostream &operator<<(ostream &output,const Circle &c)
{
	output<<"Center=["<<c.x<<", "<<c.y<<"], r="<<c.radius<<endl;
	return output;
}
 
//�жϵ�p��Բ�ڡ�Բc�ڻ�Բc��
int locate(const Point &p, const Circle &c)
{
	const Point cp(c.x,c.y);    //Բ��
	double d = cp.distance(p);
	if (abs(d - c.radius) < 1e-7)
		return 0;               //���
	else if (d < c.radius)
		return -1;              //Բ��
	else 
		return 1;               //Բ��
}
 
//���ع�ϵ��������֣��������ʹ֮�ܹ���Բ������Ƚ�����Բ�Ĵ�С��
bool Circle::operator>(const Circle &c)
{
	return (this->radius - c.radius) > 1e-7;
}
 
bool Circle::operator<(const Circle &c)
{
	return (c.radius - this->radius) > 1e-7;
}
 
bool Circle::operator>=(const Circle &c)
{
	return !(*this < c);
}
 
bool Circle::operator<=(const Circle &c)
{
	return !(*this > c);
}
 
bool Circle::operator==(const Circle &c)
{
	return abs(this->radius - c.radius) < 1e-7;
}
 
bool Circle::operator!=(const Circle &c)
{
	return abs(this->radius - c.radius) > 1e-7;
}
 
//����һ��p������õ���Բc��Բ�������ɵ�ֱ����Բ����������p1��p2
// (Ϊ�˴��ؼ�������p1��p2��Ҫ����Ϊ����)
void crossover_point(Point &p, Circle &c, Point &p1,Point &p2 )
{
	p1.setx (c.getx() + sqrt(c.radius*c.radius/(1+((c.gety()-p.gety())/(c.getx()-p.getx()))*((c.gety()-p.gety())/(c.getx()-p.getx())))));
	p2.setx (c.getx() - sqrt(c.radius*c.radius/(1+((c.gety()-p.gety())/(c.getx()-p.getx()))*((c.gety()-p.gety())/(c.getx()-p.getx())))));
	p1.sety (p.gety() + (p1.getx() -p.getx())*(c.gety()-p.gety())/(c.getx()-p.getx()));
	p2.sety (p.gety() + (p2.getx() -p.getx())*(c.gety()-p.gety())/(c.getx()-p.getx()));
}
 
int main( )
{
	Circle c1(3,2,4),c2(4,5,5);      //c2Ӧ�ô���c1
	Point p1(1,1),p2(3,-2),p3(7,3);  //�ֱ�λ��c1�ڡ��ϡ���
 
	cout<<"Բc1: "<<c1;
	cout<<"��p1: "<<p1;
	cout<<"��p1��Բc1֮"<<((locate(p1, c1)>0)?"��":((locate(p1, c1)<0)?"��":"��"))<<endl;
	cout<<"��p2: "<<p2;
	cout<<"��p2��Բc1֮"<<((locate(p2, c1)>0)?"��":((locate(p2, c1)<0)?"��":"��"))<<endl;	
	cout<<"��p3: "<<p3;
	cout<<"��p3��Բc1֮"<<((locate(p3, c1)>0)?"��":((locate(p3, c1)<0)?"��":"��"))<<endl;
	cout<<endl; 
 
	cout<<"Բc1: "<<c1;
	if(c1>c2) cout<<"����"<<endl;
	if(c1<c2) cout<<"С��"<<endl; 
	if(c1>=c2) cout<<"���ڵ���"<<endl;
	if(c1<=c2) cout<<"С�ڵ���"<<endl; 
	if(c1==c2) cout<<"����"<<endl; 
	if(c1!=c2) cout<<"������"<<endl; 
	cout<<"Բc2: "<<c2;
	cout<<endl; 
 
	Point p4,p5;
	crossover_point(p1,c1, p4, p5);
 
	cout<<"��p1: "<<p1;
	cout<<"��Բc1: "<<c1;
	cout<<"��Բ����������Բ�������㣬�ֱ��ǣ�"<<endl;
	cout<<"����: "<<p4;
	cout<<"����: "<<p5;
	cout<<endl; 
    while(1);
	return 0;
}


#else


#include <iostream>
#include<Cmath>
using namespace std;
class Point
{
public:
	Point(double x=0,double y=0);		    //���캯��
	double distance(const Point &p) const;	//�����
	double getx() const{return x;}
	double gety() const{return y;}
	void setx(double x1){x=x1;}
	void sety(double y1){y=y1;}
	friend ostream & operator<<(ostream &,const Point &);//�����������<<��
protected:										 //�ܱ�����Ա
	double x,y;
};
 
 
//Point�Ĺ��캯��
Point::Point(double a,double b):x(a),y(b){}
 
double Point::distance(const Point &p) const	//�����
{
	double dx = x-p.x;
	double dy = y-p.y;
	return sqrt(dx*dx+dy*dy);
}
 
ostream & operator<<(ostream &output,const Point &p)
{
	output<<"["<<p.x<<","<<p.y<<"]"<<endl;
	return output;
}
 
struct Two_points   //רΪcrossover_point()��������ֵ����Ľṹ��
{
	Point p1;
	Point p2;
};
 
class Circle:public Point //circle��Point��Ĺ���������
{
public:
	Circle(double x=0,double y=0,double r=0); //���캯��
	double area ( ) const; //����Բ���
	friend ostream &operator<<(ostream &,const Circle &);//�����������<<��
	friend int locate(const Point &p, const Circle &c); //�жϵ�p��Բ�ϡ�Բ�ڻ�Բ�⣬����ֵ��<0Բ�ڣ�==0Բ�ϣ�>0 Բ��
	//���ع�ϵ��������֣��������ʹ֮�ܹ���Բ������Ƚ�����Բ�Ĵ�С��
	bool operator>(const Circle &);
	bool operator<(const Circle &);
	bool operator>=(const Circle &);
	bool operator<=(const Circle &);
	bool operator==(const Circle &);
	bool operator!=(const Circle &);
	//�ٸ�һ�ֽⷨ������һ��p������õ���Բc��Բ�������ɵ�ֱ����Բ���������㣨����Two_points��ֵ��
	Two_points crossover_point(Point &p);
protected:
	double radius;
};
 
//���幹�캯������Բ������Ͱ뾶��ʼ��
Circle::Circle(double a,double b,double r):Point(a,b),radius(r){ }
 
//����Բ���
double Circle::area( ) const
{
	return 3.14159*radius*radius;
}
 
//�����������<<����ʹ֮���涨����ʽ���Բ����Ϣ
ostream &operator<<(ostream &output,const Circle &c)
{
	output<<"Center=["<<c.x<<", "<<c.y<<"], r="<<c.radius<<endl;
	return output;
}
 
//�жϵ�p��Բ�ڡ�Բc�ڻ�Բc��
int locate(const Point &p, const Circle &c)
{
	const Point cp(c.x,c.y); //Բ��
	double d = cp.distance(p);
	if (abs(d - c.radius) < 1e-7)
		return 0;  //���
	else if (d < c.radius)
		return -1;  //Բ��
	else
		return 1;  //Բ��
}
 
//���ع�ϵ��������֣��������ʹ֮�ܹ���Բ������Ƚ�����Բ�Ĵ�С��
bool Circle::operator>(const Circle &c)
{
	return (this->radius - c.radius) > 1e-7;
}
 
bool Circle::operator<(const Circle &c)
{
	return (c.radius - this->radius) > 1e-7;
}
 
bool Circle::operator>=(const Circle &c)
{
	return !(*this < c);
}
 
bool Circle::operator<=(const Circle &c)
{
	return !(*this > c);
}
 
bool Circle::operator==(const Circle &c)
{
	return abs(this->radius - c.radius) < 1e-7;
}
 
bool Circle::operator!=(const Circle &c)
{
	return abs(this->radius - c.radius) > 1e-7;
}
 
//����һ��p������õ���Բ��Բ�������ɵ�ֱ����Բ���������㣨����Two_points��ֵ��
Two_points Circle::crossover_point(Point &p)
{
	Two_points pp;
	pp.p1.setx ( x + sqrt(radius*radius/(1+((y-p.gety())/(x-p.getx()))*((y-p.gety())/(x-p.getx())))));
	pp.p2.setx ( x - sqrt(radius*radius/(1+((y-p.gety())/(x-p.getx()))*((y-p.gety())/(x-p.getx())))));
	pp.p1.sety ( p.gety() + (pp.p1.getx() -p.getx())*(y-p.gety())/(x-p.getx()));
	pp.p2.sety ( p.gety() + (pp.p2.getx() -p.getx())*(y-p.gety())/(x-p.getx()));
	return pp;
}
 
int main( )
{
	Circle c1(3,2,4),c2(4,5,5);      //c2Ӧ�ô���c1
	Point p1(1,1),p2(3,-2),p3(7,3);  //�ֱ�λ��c1�ڡ��ϡ���
 
	cout<<"Բc1: "<<c1;
	cout<<"��p1: "<<p1;
	cout<<"��p1��Բc1֮"<<((locate(p1, c1)>0)?"��":((locate(p1, c1)<0)?"��":"��"))<<endl;
	cout<<"��p2: "<<p2;
	cout<<"��p2��Բc1֮"<<((locate(p2, c1)>0)?"��":((locate(p2, c1)<0)?"��":"��"))<<endl;
	cout<<"��p3: "<<p3;
	cout<<"��p3��Բc1֮"<<((locate(p3, c1)>0)?"��":((locate(p3, c1)<0)?"��":"��"))<<endl;
	cout<<endl;
 
	cout<<"Բc1: "<<c1;
	if(c1>c2) cout<<"����"<<endl;
	if(c1<c2) cout<<"С��"<<endl;
	if(c1>=c2) cout<<"���ڵ���"<<endl;
	if(c1<=c2) cout<<"С�ڵ���"<<endl;
	if(c1==c2) cout<<"����"<<endl;
	if(c1!=c2) cout<<"������"<<endl;
	cout<<"Բc2: "<<c2;
	cout<<endl;
 
	cout<<"������һ�ַ����󽻵㣺"<<endl;
	Two_points twoPoint = c1.crossover_point(p1);
	cout<<"��p1: "<<p1;
	cout<<"��Բc1: "<<c1;
	cout<<"��Բ����������Բ�������㣬�ֱ��ǣ�"<<endl;
	cout<<"����: "<<twoPoint.p1;
	cout<<"����: "<<twoPoint.p2;
    while(1);
	return 0;
}

#endif

#if 0


#endif
/*

*/