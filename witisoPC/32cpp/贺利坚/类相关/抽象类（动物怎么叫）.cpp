#include "iostream" // �����ࣨ������ô�У�
#include<string>
using namespace std;

class Animal
{
protected:
    string name; //�����е����ݳ�Ա�������
public:
    Animal(string nam):name(nam){} //����Ĺ��캯��
    virtual void cry()=0;
};

class Mouse : public Animal
{
public:
    Mouse(string nam):Animal(nam){}  //������Ĺ��캯��Ҫ����д
    virtual void cry() {cout<<"�ҽ�"<<name<<"����һֻ�����ҵĽ����ǣ�֨֨֨��"<<endl;}
};

class Cat : public Animal
{
public:
    Cat(string nam):Animal(nam){}
    virtual void cry() {cout<<"�ҽ�"<<name<<"����һֻè���ҵĽ����ǣ���������"<<endl;}
};

class Dog : public Animal
{
public:
    Dog(string nam):Animal(nam){}
    virtual void cry() {cout<<"�ҽ�"<<name<<"����һ�������ҵĽ����ǣ���������"<<endl;}
};

class Giraffe : public Animal
{
public:
    Giraffe(string nam):Animal(nam){}
    virtual void cry() {cout<<"�ҽ�"<<name<<"���ǳ���¹���ҵĲ���̫������������������"<<endl;}
};

int main( )
{
    Animal *p;
    //p = newAnimal(); p->cry();       //�����಻��ʵ���������ˣ�����
    Mouse m("Jerry");  p=&m; p->cry(); //���: �ҽ�Jerry����һֻ�����ҵĽ����ǣ�֨֨֨��
    Cat c("Tom");      p=&c; p->cry(); //���: �ҽ�Tom����һֻè���ҵĽ����ǣ���������
    Dog d("Droopy");   p=&d; p->cry(); //���: �ҽ�Droopy����һ�������ҵĽ����ǣ���������
    Giraffe g("Gill"); p=&g; p->cry(); //���: �ҽ�Gill���ǳ���¹���ҵĲ���̫������������������
    system("pause");
    return 0;
}