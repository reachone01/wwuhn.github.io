#include <iostream>
#include "game.h"
using namespace std;

Role::Role(string nam, int b, Point l, Weapon w[], int n)
    :name(nam),blood(b),location(l),weaponNum(n),holdWeapon(NOWEAPON)
{
    if(blood>0)
        life=true;
    else
        life=false;
    for(int i=0; i<n; i++)
        weapons[i]=w[i];
}
Role::~Role()
{
    cout<<name<<"�˳�����..."<<endl;
}

//�Զ�������dѪ(���˺���϶������Ը���)
void Role::eat(int d) //�Զ�������dѪ(����Ҳ�ܳԣ�����ι�ģ���ʹ�ܸ���)
{
    blood+=d;
    if(blood>0)
        life=true;
}

//�������ˣ��Լ���Ѫ��ͬʱ�Է�������ʧѪ��Ѫ��ȡ���ڵ�ǰ�õ�����
//�������Ĺ�����Χ�ڲſ��Թ���
void Role::attack(Role &r)
{
    if(isAlived()&&holdWeapon>NOWEAPON&&weapons[holdWeapon].getKillRange()>this->distance(r)) //��������ɱ�˷�Χ��
    {
        blood+=weapons[holdWeapon].getForce();
        r.beAttack(weapons[holdWeapon].getForce());
    }
}

//�����˹���������f�ǳ��ܵĹ�����
void Role::beAttack(int f)
{
    blood-=f;
    if(blood<=0)
        life=false;
}

//��������һ��ɫ�ľ���
double Role::distance(Role &r)
{
    return location.distance(r.location);
}
//�����е�����
void Role::changeWeapon(int wno)
{
    if(wno<weaponNum)
        holdWeapon=wno;
}
//�Ƿ����
bool Role::isAlived()
{
    return life;
}
//�Ƶ�����һ��
void Role::moveTo(int x, int y)
{
    if(isAlived())  //���˾Ͳ��ܶ���
        location.moveTo(x,y);
}
//�ӵ�ǰλ���ƶ�
void Role::move(int dx, int dy)
{
    if(isAlived())
        location.move(dx,dy);
}
//��ʾ
void Role::show()
{
    cout<<name<<" has "<<blood<<" blood, hold ";
    if(holdWeapon==NOWEAPON)
        cout<<"no weapon";
    else
        cout<<weapons[holdWeapon].getWname();
    cout<<"(";
    for(int i=0; i<weaponNum; i++)
        cout<<weapons[i].getWname()<<",";
    cout<<"\b)";
    cout<<". He is in ("<<location.getX()<<", "<<location.getY()<<") and ";
    if(isAlived())
        cout<<"alived.";
    else
        cout<<"dead.";
    cout<<endl;
}
//��ɫ���ƺͳ�ʼѪ��
void Role::setBaseInfo(string nam, int b)
{
    name=nam;
    blood=b;
    if(blood>0)
        life=true;
}
//����λ��
void Role::setLocation(int x,int y)
{
    location.moveTo(x,y);
}
//��һ������
void Role::addWeapon(Weapon w)
{
    if(weaponNum<N)
    {
        weapons[weaponNum]=w;
        weaponNum++;
    }
}

//��������
string Role::getName()
{
    return name;
}

    int Role::getWeaponNum()
    {
        return weaponNum;
    }
string Role::getCurWeapon()
{
    return weapons[holdWeapon].getWname();
}
