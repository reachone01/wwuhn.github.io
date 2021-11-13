// һ��������CSolid����������������������Ĵ��麯��

#include "iostream"
using namespace std;

const double pai=3.1415926;
// ��������ͼ�λ���
class CSolid
{
public:
    virtual double SurfaceArea() const=0;
    virtual double Volume() const=0;
};

// ��������
class CCube : public CSolid
{
public:
    CCube(double len=0);
    double SurfaceArea() const;   // ������
    double Volume() const;        // �����
private:
    double length;
    
};

// �������๹�캯��
CCube::CCube(double len)
{
    length=len;
}

// ������������
double CCube::SurfaceArea() const
{
    double c;
    c=6*length*length;
    return c;
}

// �����������
double CCube::Volume() const
{
    double c;
    c=length*length*length;
    return c;
}

// ������
class CBall : public CSolid
{
private:
    double radius;              // Բ����
public:
    CBall(double r=0);
    double SurfaceArea() const;  // ������
    double Volume() const;       // �����;
};

// �����๹�캯��
CBall::CBall(double r)
{
    radius=r;
}

// ����������
double CBall::SurfaceArea() const
{
    double c;
    c=4*pai*radius*radius;
    return c;
}

// ���������
double CBall::Volume() const
{
    double c;
    c=pai*radius*radius*radius*4/3;
    return c;
}

// Բ������
class CCylinder : public CSolid
{
private:
    double radius; 
    double height;
public:
    CCylinder(double r=0,double high=0);
    double SurfaceArea() const;       // ������
    double Volume() const;            // �����
};

// Բ�����๹�캯��
CCylinder::CCylinder(double r,double high) 
{
    radius=r;
    height=high;
}

// ��Բ��������
double CCylinder::SurfaceArea() const
{
    double c;
    c=pai*radius*radius+2*pai*radius*height;
    return c;
}

// ��Բ�������
double CCylinder::Volume() const
{
    double c;
    c=pai*radius*radius*height;
    return c;
}

int main( )
{
    CSolid *p;
    double s,v;
    CCube x(30);
    cout<<"������߳�Ϊ30"<<endl;
    p=&x;
    s=p->SurfaceArea( );
    v=p->Volume( );
    cout<<"�������"<<s<<endl;
    cout<<"�����"<<v<<endl;
    cout<<endl;
    CBall y(4.5);
    cout<<"����뾶Ϊ4.5"<<endl;
    p=&y;
    s=p->SurfaceArea( );
    v=p->Volume( );
    cout<<"�������"<<s<<endl;
    cout<<"�����"<<v<<endl;
    cout<<endl;
    CCylinder z(10,20);
    cout<<"Բ�������뾶���߷ֱ�Ϊ10, 20"<<endl;
    p=&z;
    s=p->SurfaceArea( );
    v=p->Volume( );
    cout<<"�������"<<s<<endl;
    cout<<"�����"<<v<<endl;
    cout<<endl;
    system("pause");
    return 0;
}