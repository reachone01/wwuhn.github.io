#include <iostream>
using namespace std;
//����������Shape�����û�������
class Shape
{
public:
    virtual double area() const =0;            //���麯��
};

//����Circle��
class Circle:public Shape
{
public:
    Circle(double r):radius(r){}                                  //�ṹ����
    virtual double area() const {return 3.14159*radius*radius;};  //�����麯��
protected:
    double radius;                                                 //�뾶
};

//����Rectangle��
class Rectangle:public Shape
{
public:
    Rectangle(double w,double h):width(w),height(h){}               //�ṹ����
    virtual double area() const {return width*height;}              //�����麯��
protected:
    double width,height;                                            //�����
};

class Triangle:public Shape
{
public:
    Triangle(double w,double h):width(w),height(h){}                //�ṹ����
    virtual double area() const {return 0.5*width*height;}          //�����麯��
protected:
    double width,height;                                            //�����
};

int main()
{
    Circle c1(12.6),c2(4.9);                                              //����Circle�����c1,c2,����ΪԲ�뾶
    Rectangle r1(4.5,8.4),r2(5.0,2.5);                                    //����Rectangle�����r1,r2,����Ϊ���γ�����
    Triangle t1(4.5,8.4),t2(3.4,2.8);                                     //����Triangle�����t1,t2������Ϊ�����εױ߳����
    Shape *pt[6]={&c1,&c2,&r1,&r2,&t1,&t2};  
    //�������ָ������pt��ʹ��ÿһ��Ԫ��ָ��һ�����������
    double areas=0.0;                                                //areasΪ�����
    for(int i=0;i<6;i++)
    {
        areas=areas+pt[i]->area();
    }
    cout<<"total of all areas="<<areas<<endl;   //��������
    system("pause");
    return 0;
}