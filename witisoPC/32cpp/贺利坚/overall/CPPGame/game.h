#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include <string>
using namespace std;
const int N=5;          //ÿ����ɫ���ӵ�е�����
const int M=30;         //��Ϸ����������
const int NOWEAPON=-1;  //��ʾ����������
const int SIZE=100;     //�����ļ��Ƕ�ȡ������Ϣ�����100������

class Point     //Point������
{
public:         //�ⲿ�ӿ�
    Point(int x=0, int y=0);
    int getX();
    int getY();
    double distance(const Point &p);//����������һ��p֮��ľ���
    void moveTo(int x, int y);      //�Ƶ�����һ��
    void move(int dx, int dy);      //�ӵ�ǰλ���ƶ�
private:
    int x, y;  //����
};

class Weapon
{
public:
    Weapon(){};
    Weapon(string wnam, int f, double k);
    Weapon(const Weapon&);
    string getWname();
    int getForce();         //����ɱ����
    double getKillRange();  //����ɱ�˾���
    void setWeapon(string,int,double);
private:
    string wname;       //����
    int force;          //ɱ����
    double killRange;   //ɱ�˾���
};

class Role
{
public:
    Role():weaponNum(0),holdWeapon(NOWEAPON){};
    Role(string nam, int b, Point l, Weapon w[], int n); //���캯��
    ~Role(); //��������
    void eat(int d);            //�Զ�������dѪ(���˺���϶������Ը���)
    void attack(Role &r);       //�������ˣ��Լ���Ѫ��ͬʱ�Է�������ʧѪ��Ѫ��ȡ���ڵ�ǰ�õ�����
    void beAttack(int f);       //�����˹���������f�ǳ��ܵĹ�����
    double distance(Role &r);   //��������һ��ɫ�ľ���
    bool isAlived();            //�Ƿ����
    void moveTo(int x, int y);  //�Ƶ�����һ��
    void move(int dx, int dy);  //�ӵ�ǰλ���ƶ�
    void changeWeapon(int wno); //�����е�����
    void show();                //��ʾ
    void setBaseInfo(string, int);  //��ɫ���ƺͳ�ʼѪ��
    void setLocation(int,int);      //����λ��
    void addWeapon(Weapon);         //��һ������
    string getName();
    int getWeaponNum();
    string getCurWeapon();
private:
    string name;    //��ɫ����
    int blood;      //��ǰѪ��
    bool life;      //�Ƿ����
    Point location;  //λ��
    Weapon weapons[N];  //����
    int weaponNum;      //������Ŀ
    int holdWeapon;     //�����ֳ���һ������(����ΪNOWEAPON����ʼʱ����)
};

#endif // GAME_H_INCLUDED
