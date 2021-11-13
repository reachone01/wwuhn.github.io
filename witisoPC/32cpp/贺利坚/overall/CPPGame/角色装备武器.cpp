// ��ɫװ������

/*
�������һ���ǳ��򵥵�ʹ�������Ĺ���
�������Է�ʱ���Լ���Ѫ�������Լ�������������ͬʱ�Է�ʧȥ����Ѫ
�Է�ʧѪ��Ϊ0�򸺺���ȥ
��ӭ��Ϸ�ߣ��������������
*/
#include <iostream>
using namespace std;
class Weapon
{
public:
    Weapon(string wnam, int f);
    int getForce();
private:
    string wname;   //����
    int force;       //����
};
Weapon::Weapon(string wnam, int f):wname(wnam),force(f) {}
int Weapon::getForce()
{
    return force;
}
class Role
{
public:
    Role(string nam, int b, string wnam, int f); //���캯��
    ~Role(); //��������
    void eat(int d); //�Զ�������dѪ
    void attack(Role &r); //�������ˣ��Լ���Ѫ��ͬʱʧѪ
    bool isAlived(); //�Ƿ����
    void show(); //��ʾ
private:
    string name;
    int blood;
    Weapon weapon;
    bool life;
};
Role::Role(string nam, int b, string wnam, int f):name(nam),blood(b),weapon(wnam,f)
{
    if(blood>0)
        life=true;
    else
        life=false;
}
Role::~Role()
{
    cout<<name<<"�˳�����..."<<endl;
}
void Role::eat(int d) //�Զ�������dѪ
{
    if(isAlived())
        blood+=d;
}
void Role::attack(Role &r) //�������ˣ���1Ѫ
{
    if(isAlived())
    {
        blood+=weapon.getForce();
        r.blood-=weapon.getForce();
        if(r.blood<=0)
            r.life=false;
    }
}

bool Role::isAlived() //�Ƿ����
{
    return life;
}

void Role::show() //��ʾ
{
    cout<<name<<" has "<<blood<<" blood, it is ";
    if(isAlived())
        cout<<"alived.";
    else
        cout<<"dead.";
    cout<<endl;
}
int main( )
{
    Role mary("Mary", 500, "TuLong",200);
    Role jack("Jack", 10, "YiTian", 180);
    cout<<"---begin---"<<endl;
    mary.show();
    jack.show();
    cout<<"---1st round---"<<endl;
    jack.attack(mary);
    mary.show();
    jack.show();
    cout<<"---2nd round---"<<endl;
    mary.attack(jack);
    mary.show();
    jack.show();
    cout<<"---end---"<<endl;
    return 0;
}