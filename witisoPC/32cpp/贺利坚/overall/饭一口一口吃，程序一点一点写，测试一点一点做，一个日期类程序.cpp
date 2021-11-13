#include <iostream>  //��һ��һ�ڳԣ�����һ��һ��д������һ��һ������һ�����������
using namespace std;
struct Time
{
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
};


//����һ���޶���Χ�ڵ�������ֵ
int getNum(char *prompt, int min, int max)
{
    int value=-1;
    cout<<"����"<<prompt<<"����Χ["<<min<<","<<max<<"]:";
    do
    {
        cin>>value;
    }
    while(value<min || value>max);
    return value;
}


//����y��m�µ�����
int daysOfMonth(int m,int y)
{
    int days;
    switch(m)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        days=31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        days=30;
        break;
    case 2:
        if((y%4==0&&y%100!=0)||y%400==0)
            days=29;
        else
            days=28;
    }
    return days;
}


//����ʱ�䣬����Ϊ�������ͣ�����Ӱ��ʵ�ε�ֵ
void getTime(Time &t)
{
    t.year=getNum("��",0,3000); //��������һ����Χ�ڵ���
    t.month=getNum("��",1,12);
    t.day=getNum("��",1,daysOfMonth(t.month, t.year));
    t.hour=getNum("ʱ",0,24);
    t.minute=getNum("��",0,59);
    t.second=getNum("��",0,59);
}


//���ʱ�䣬����Ҳ���������ǶԽṹ�����Ĵ���취
void outputTime(Time &t)
{
    cout<<"ʱ��Ϊ: "<<t.year<<"��"<<t.month<<"��"<<t.day<<"��"<<t.hour<<"ʱ"<<t.minute<<"��"<<t.second<<"��"<<endl;
}


//��������һ��ĵڼ���
int dayOfYear(Time &t)
{
    int days=0;
    int m=1;
    while(m<t.month)  //ǰ�����µ�����������
    {
        days+=daysOfMonth(m,t.year);  //��������Ѿ���Ƶĺ���
        ++m;
    }
    days+=t.day; //�ټ��ϱ��µ�����
    return days;
}


//��������һ��ĵڼ���
int secondOfDay(Time &t)
{
    return t.hour*3600+t.minute*60+t.second;
}


//����һ���ж����죨365��366�죩
int daysOfYear(int y)
{
    return ((y%4==0&&y%100!=0)||y%400==0)?366:365;
}


//���������ʱ��d�����������������
Time afterDays(Time t,int d)
{
    Time t1=t;
    int d1=d+dayOfYear(t); //dayOfYear(t)���t�ǵ���ڼ���
    t1.month=1;
    t1.day=0;  //������������ת��Ϊ�ڵ���1��0�ջ����ϼ�d1��(���0����˼)�������Ժ���Ϊ2�²��ģ��Լ�ʣ������һ���Ժ������λ
    //    cout<<"ת��Ϊ";
    //    outputTime(t1);
    //    cout<<"��һ���"<<d1<<"�졣";
    while(d1>daysOfYear(t1.year))  //��������һ������
    {
        d1-=daysOfYear(t1.year);
        ++t1.year;
    }
    //��������һ������ٿ����£���Ϊ��1��1�տ�ʼ�����õ���Nt.year�ټ�1��
    while(d1>daysOfMonth(t1.month,t1.year))  //��������һ������
    {
        d1-=daysOfMonth(t1.month,t1.year);
        ++t1.month;
    }
    //ʣȫ�����ӵ�����
    t1.day+=d1;
    return t1;
}


int main()
{
    Time t,nt;
    //��1������һ��ʱ�䣨ע����������ݵ�ȡֵ��Χ���������ʱ�䱣����һ���ṹ������У�
    cout<<"������һ��ʱ��(�����꣬�£��գ�ʱ���֣���):"<<endl;
    getTime(t);
    outputTime(t);
    //��2����������ڱ������ǵڼ��죨ע���������⣩��
    cout<<"������һ���еĵ�"<<dayOfYear(t)<<"�졣"<<endl;
    //��3�����������һ���еĵڼ��룻
    cout<<"������һ���еĵ�"<<secondOfDay(t)<<"�롣"<<endl;
    //��4�����������һ���еĵڼ��룻
    cout<<"������һ���еĵ�"<<dayOfYear(t)*24*3600+secondOfDay(t)<<"�롣"<<endl;
    //��5�����������ʱ��d����������������գ������������һ���ṹ������������
    int d;
    cout<<"������һ������";
    cin>>d;
    nt=afterDays(t,d);
    cout<<"��һ���d����10000������ǣ�";
    outputTime(nt);
    //��6�����������ʱ��s����Ǻ��պ�ʱ�������������һ���ṹ������������
    
    while(1);
    return 0;
}