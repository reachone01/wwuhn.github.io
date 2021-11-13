#include <iostream>// �㵽Բ��Բ����
using namespace std;
class Point
{
public:
    Point(double x=0,double y=0);					 //���캯��
    void setPoint(double,double);                  //��������ֵ
    double getX( ) const {return x;}              //��x����
    double getY( ) const {return y;}              //��y����
    friend ostream & operator<<(ostream &,const Point &);//�����������<<��
protected:										 //�ܱ�����Ա
    double x,y;
};


//Point�Ĺ��캯��
Point::Point(double a,double b)	
{
    x=a;
    y=b;
}
//����x��y������ֵ
void Point::setPoint(double a,double b)  
{
    x=a;
    y=b;
}

ostream & operator<<(ostream &output,const Point &p)
{
    output<<"["<<p.x<<","<<p.y<<"]"<<endl;
    return output;
}

class Circle:public Point   //circle��Point��Ĺ���������
{
public:
    Circle(double x=0,double y=0,double r=0);  //���캯��
    void setRadius(double);                  //���ð뾶ֵ
    double getRadius( ) const;               //��ȡ�뾶ֵ
    double area ( ) const;                   //����Բ���
    friend ostream &operator<<(ostream &,const Circle &);//�����������<<��
protected:
    double radius;
};

//���幹�캯������Բ������Ͱ뾶��ʼ��
Circle::Circle(double a,double b,double r):Point(a,b),radius(r){ }

//���ð뾶ֵ
void Circle::setRadius(double r)
{
    radius=r;
}

//��ȡ�뾶ֵ
double Circle::getRadius( ) const
{
    return radius;
}

//����Բ���
double Circle::area( ) const
{
    return 3.14159*radius*radius;
}

//�����������<<����ʹ֮���涨����ʽ���Բ����Ϣ
ostream &operator<<(ostream &output,const Circle &c)
{
    output<<"Center=["<<c.x<<", "<<c.y<<"], r="<<c.radius<<", area="<<c.area( )<<endl;
    return output;
}

class Cylinder:public Circle
{
public:
    Cylinder (double x=0,double y=0,double r=0,double h=0);//���캯��
    void setHeight(double);                      //����Բ����
    double getHeight( ) const;                    //��ȡԲ����
    double area( ) const;                         //����Բ�������
    double volume( ) const;                       //����Բ�����
    friend ostream& operator<<(ostream&,const Cylinder&);//�����������<<��
protected:
    double height;                               //Բ����
};

//���幹�캯��
Cylinder::Cylinder(double a,double b,double r,double h) :Circle(a,b,r),height(h){}

//����Բ����
void Cylinder::setHeight(double h)
{
    height=h;
}

//��ȡԲ����
double Cylinder::getHeight( ) const 
{
    return height;
}

//����Բ�������
double Cylinder::area( ) const
{ 
    return 2*Circle::area( )+2*3.14159*radius*height;
}

//����Բ�����
double Cylinder::volume() const
{
    return Circle::area()*height;
}

//�����������<<��
ostream &operator<<(ostream &output,const Cylinder& cy)
{
    output<<"Center=["<<cy.x<<","<<cy.y<<"], r="<<cy.radius<<", h="<<cy.height
        <<"\narea="<<cy.area( )<<", volume="<<cy.volume( )<<endl;
    return output;
}

int main( )
{
    Cylinder cy1(3.5,6.4,5.2,10);
    cout<<"\noriginal cylinder:\nx="<<cy1.getX( )<<", y="<<cy1.getY( )<<", r="
        <<cy1.getRadius( )<<", h="<<cy1.getHeight( )<<"\narea="<<cy1.area()
        <<",volume="<<cy1.volume()<<endl;
    cy1.setHeight(15);     
    cy1.setRadius(7.5);      
    cy1.setPoint(5,5);       
    cout<<"\nnew cylinder:\n"<<cy1;        
    return 0;
}