#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "game.h"
using namespace std;
/*
��1���������飬�Զ������˺ܶ������ҡ�����ɫ��Ķ��󣩣��Զ��棻��2��ʹ���ļ�������Ҫ
���ļ��ж�����Ĺ��̣�д�뵽���ļ���
���㣨���Ľ�֮��������1�����������ʱ��û�б����ظ��������ڻ����Լ������Լ����������
���ڼ���Ѫ�ּ�ȥ�ˣ�û�б仯������ͬ�����������ж���������ǹ���������������Ҳ�У���2
��ֻ�����Զ������Ľ�ɫ�������ˣ��Լ�û�в��룬��ʵ��ָ�����������е�0����������Լ���
���ѡȡ������ʱ���������СΪ1�����Ӹ��˵���ѡ���������ɡ�
*/
void initializeRoles(Role roles[]);     //��ʼ����ɫ���ɼ�����������
int readWeaponInfo(Weapon WeaponBase[]);//���ļ��ж�ȡ������Ϣ
int randBetween(int low, int high);     //����һ����Χ�ڵ������
void play(Role roles[], int n);

//������
int main( )
{
    srand(time(0));
    Role roles[M];
    initializeRoles(roles);
    play(roles, 1000);
    while(1);
    return 0;
}

//��ʼ����ɫ
void initializeRoles(Role roles[])
{
    Weapon weaponBase[SIZE];                    //�洢ϵͳ�п����õ�������������
    int weaponNum = readWeaponInfo(weaponBase); //���ļ��ж�ȡ������Ϣ�����������飬����������������
    char cno[5];            //�������
    int wn;                 //Ҫ�ӵ�������
    int wno;                //Ҫ����������ı��(weaponBase�е��±�)
    for(int i=0; i<M; i++)  //����M����ɫ���󣬼���Ϸ�е�����
    {
        itoa(i,cno,10);
        roles[i].setBaseInfo(string("Soldier")+cno,randBetween(10, 100));
        roles[i].setLocation(randBetween(0,1000),randBetween(0, 1000));
        wn=randBetween(1,N);
        for(int j=0; j<wn; j++) //���wn������
        {
            wno=randBetween(0,weaponNum);
            roles[i].addWeapon(weaponBase[wno]);
        }
        roles[i].changeWeapon(randBetween(0,wn));//��ǰ��ʲô����
    }
}

//��ʼ��������
int readWeaponInfo(Weapon WeaponBase[])
{
    ifstream infile("weapon.txt",ios::in);
    int n=0;
    string wn;
    int wf;
    double wr; //�ֱ������������ɱ������ɱ�˷�Χ
    if(!infile)
    {
        cerr<<"open error!"<<endl;
        exit(1);
    }
    while(infile>>wn>>wf>>wr)
    {
        WeaponBase[n++].setWeapon(wn,wf,wr);
    }
    infile.close();
    return n;
}
//����һ�����ڵ���low��С��high��Χ�ڵ������
int randBetween(int low, int high)
{
    return low+rand()%(high-low);
}

//��n����Ϸ��ÿһ����һ����ɫ�ж�
//�ж������ǹ������ƶ�������������
//���еĽ�������浽log.txt�ļ���
void play(Role roles[], int n)
{
    int i;
    int rno,rno2; //ѡ�е���Ϸ��
    int action; //�ж�0-������1-�ƶ���2-��������3-�Զ���
    int newx, newy, newWeapon, eatd;
    ofstream outfile("log.txt",ios::out);  //�������������
    if(!outfile)                    //�����ʧ�ܣ�outfile����0ֵ
    {
        cerr<<"open error!"<<endl;
        exit(1);
    }

    cout<<"��ʼǰ...."<<endl;
    for(i=0; i<M; i++)
        roles[i].show();
    cout<<"��ʼ��Ϸ���뵽��־�ļ��п�����...."<<endl<<endl;
    for(i=0; i<n; i++)
    {
        rno=randBetween(0,M);
        outfile<<"��"<<i<<"��: "<<roles[rno].getName();
        action=randBetween(0,4);
        switch(action)
        {
        case 0: //����
            rno2=randBetween(0,M);
            outfile<<"����"<<roles[rno2].getName();
            roles[rno].attack(roles[rno2]);
            break;
        case 1: //�ƶ�
            newx=randBetween(0,1000);
            newy=randBetween(0, 1000);
            outfile<<"�ƶ���("<<newx<<","<<newy<<")";
            roles[rno].moveTo(newx,newy);
            break;
        case 2: //������
            newWeapon=randBetween(0,roles[rno].getWeaponNum());
            roles[rno].changeWeapon(newWeapon);
            outfile<<"��������Ϊ: "<<roles[rno].getCurWeapon();
            break;
        case 3: //��
            eatd=randBetween(0,100);
            roles[rno].eat(eatd);
            outfile<<"����: "<<eatd;
            break;
        }
        outfile<<". "<<endl;
    }
    outfile<<endl;
            outfile.close();
    cout<<"��Ϸ������...."<<endl;
    for(i=0; i<M; i++)
        roles[i].show();

}


