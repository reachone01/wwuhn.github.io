#include <iostream>  // ��Ԫ��
using namespace std;

// Ϊ������Ԫ�࣬ʵ���ϱ�������һ����һ���õ���ƣ�
// ��������ĺϲ�Ϊһ��DateTime�����ڡ�ʱ�䶼�������
class Date;     //��Date�����ǰ��������
class Time
{
public:
    Time(int,int,int);
    void add_a_second(Date &);  //����1�룬1�����ܻᵽ����һ�죬�˵���һ�¡���һ��
    void display(Date &);       //��ʾʱ�䣬��ʽ����/��/�� ʱ:��:��
private:
    int hour;
    int minute;
    int sec;
};
 
class Date
{
public:
    Date(int,int,int);
    friend class Time;  //Time����ΪDate����Ԫ��
private:
    int month;
    int day;
    int year;
};
 
int main( )
{
    Time t1(23,59,32);
    Date d1(12,25,2012);
    for(int i=0; i<=80; i++)
    {
        t1.add_a_second(d1);
        t1.display(d1);
    }
    while(1);
    return 0;
}
//���涨���������еĳ�Ա������Ҫ�󲻵������ӳ�Ա����
//ע�������Time�ĳ�Ա�����п��Ե���Date���˽�����ݳ�Ա
Time::Time(int h,int m,int s)
{
    hour=h;
    minute=m;
    sec=s;
}
Date::Date(int m,int d,int y)
{
    month=m;
    day=d;
    year=y;
}
void Time::add_a_second(Date &d)
{
    if(++sec>=60) ++minute,sec-=60;
    if(minute>=60) ++hour,minute-=60;
    if(hour>=24) ++d.day,hour-=24;
    if(d.day>30) ++d.month,d.day-=30;//Q.������Ҫ�����ƣ�������ÿһ���¶���30��
    if(d.month>12) ++d.year,d.month-=12;//Q.
}
void Time::display(Date &d)
{
    cout<<d.month<<"/"<<d.day<<"/"<<d.year<<" ";
    cout<<hour<<":"<<minute<<":"<<sec<<endl;
}