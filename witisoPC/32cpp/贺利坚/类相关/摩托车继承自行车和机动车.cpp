#include <iostream>  // Ħ�г��̳����г��ͻ�����
#include<conio.h>
#include <windows.h>
using namespace std;

enum VehicleStaus {rest, running};  //����״̬���������н�

class Vehicle //������
{
protected:
    int maxSpeed;		//�����
    int currentSpeed;	//��ǰ�ٶ�
    int weight;			//����
    VehicleStaus status; //rest-����״̬��running-�н�״̬
public:
    Vehicle(int maxS, int w);   //���캯������ʼʱ����ǰ�ٶ���Ϊ0�Ҵ���ͣ��״̬
    void start();               //��rest״̬��running, ����Ϊ1
    void stop();                //��running״̬��rest, ��ǰ�ٶ�С��5ʱ��������ͣ��
    void speed_up();            //���٣�����1�Σ��ٶȼ�1
    void slow_down();           //���٣�����1�Σ��ٶȼ�1���ٶ�Ϊ0ʱ��ͣ��
};

//���캯������ʼʱ����ǰ�ٶ���Ϊ0�Ҵ���ͣ��״̬
Vehicle::Vehicle(int maxS, int w):maxSpeed(maxS), currentSpeed(0),weight(w), status(rest) {}

//��������rest״̬��running, ����Ϊ1
void Vehicle::start()
{
    if (status==rest)
    {
        status=running;
        currentSpeed=1;
    }
    else
        cout<<"�����Ѿ���ʻ��"<<endl;
}
//��running״̬��rest, ��ǰ�ٶ�С��5ʱ��������ͣ��
void Vehicle::stop()
{
    if (status==running)
        if(currentSpeed<5)
        {
            status=rest;
            currentSpeed=0;
        }
        else
            cout<<"����̫�죡�ȼ�����ͣ������"<<endl;
        else
            cout<<"����δ������"<<endl;
}

//���٣�����1�Σ��ٶȼ�1
void Vehicle::speed_up()
{
    if (status==running)
        if(currentSpeed<maxSpeed)
            ++currentSpeed;
        else
            cout<<"�벻Ҫ������ʻ����"<<endl;
        else
            cout<<"����δ������"<<endl;
}
//���٣�����1�Σ��ٶȼ�1���ٶ�Ϊ0ʱ��ͣ��
void Vehicle::slow_down()
{
    if (status==running)
    {
        if(currentSpeed>0)
            --currentSpeed;
    }
    else
        cout<<"����δ������"<<endl;
    if(currentSpeed==0)
        status=rest;
}

class Bicycle :virtual public Vehicle       //�������г���
{
protected:
    double height;                              //����
public:
    Bicycle(int maxS=10, int w=50, int h=0.7);   //���幹�캯��
};

Bicycle::Bicycle(int maxS, int w, int h):Vehicle(maxS, w),height(h) {}

class Motorcar : virtual public Vehicle     //������������
{
protected:
    int seatNum;     //��λ��
    int passengerNum; //�˿�����
public:
    Motorcar(int maxS=150, int w=1500, int s=5, int p=1);   //���幹�캯��
    void addPassenger(int p=1);   //���س˿ͣ���ԱҪ���أ������³�ʱ��pΪ��������Ȼ���ϳ˿�������1����˾���������³�ʱҪ��֤��ȫ����
};

//���幹�캯��
Motorcar::Motorcar(int maxS, int w, int s, int p): Vehicle(maxS, w),seatNum(s),passengerNum(p) {}

//���س˿ͣ���ԱҪ���أ������³�ʱ��pΪ��������Ȼ���ϳ˿�������1����˾���������³�ʱҪ��֤��ȫ����
void Motorcar::addPassenger(int p)
{
    if (status==running)
    {
        cout<<"����������ʻ��ͣ���������³���"<<endl;
    }
    else
    {
        passengerNum+=p;
        if(passengerNum>seatNum)
        {
            passengerNum=seatNum;
            cout<<"���ӳ�Ա���������ﵽ��Ա��"<<endl;
        }
        else if (passengerNum<1)
        {
            passengerNum=1;
            cout<<"��˾����Ҫ�뿪��λ��"<<endl;
        }
    }
}

class Motorcycle: public Bicycle, public Motorcar //����Ħ�г���
{
public:
    Motorcycle(int maxS=90, int w=100, int s=3, int p=1, int h=0.7);   //���幹�캯��
    void show(); //��ʾĦ�г�������״̬
};

//���幹�캯��
Motorcycle::Motorcycle(int maxS, int w, int s, int p, int h):Vehicle(maxS, w),Bicycle(maxS, w, h),Motorcar(maxS, w, s, p) {}

//��ʾĦ�г�������״̬
void Motorcycle::show()
{
    cout<<"״̬��";
    if(status==rest)
        cout<<"������\t";
    else
        cout<<"�н���\t";
    cout<<"���٣�"<<currentSpeed<<" / "<< maxSpeed <<"\t��ǰ��Ա��"<<passengerNum<<" / "<< seatNum << endl;
}

int main( )
{
    Motorcycle m;
    bool end=false;
    while (!end)
    {
        cout<<"�������1-����  2-����  3-����  4-�����ϳ�  5-�����³�  6-ͣ�� 0-����"<<endl;
        char keydown= _getch(); //_getch()���ؼ����϶�ȡ���ַ�,Ӧ����ͷ�ļ�<conio.h>
        switch(keydown)
        {
        case '1':
            cout<<"ѡ�еĲ�����1-����\t";
            m.start();
            break;
        case '2':
            cout<<"ѡ�еĲ�����2-����\t";
            m.speed_up();
            break;
        case '3':
            cout<<"ѡ�еĲ�����3-����\t";
            m.slow_down();
            break;
        case '4':
            cout<<"ѡ�еĲ�����4-�����ϳ�\t";
            m.addPassenger();
            break;
        case '5':
            cout<<"ѡ�еĲ�����5-�����³�\t";
            m.addPassenger(-1);
            break;
        case '6':
            cout<<"ѡ�еĲ�����6-ͣ��\t";
            m.stop();
            break;
        case '0':
            end=true;
            break;
        }
        m.show();
        cout<<endl;
        Sleep(200);  //Ҫ����ͷ�ļ�<windows.h>
    }
    while(1);
    return 0;
}