#include <iostream>  // ���о�̬���ݳ�Ա�ͳ�Ա������Time��
using namespace std;
class Time
{
public:
    Time(int=0,int=0,int=0);
    void show_time( );      //����is_24��from0������ʺ���ʽ��ʱ��20:23:5/8:23:5 pm/08:23:05 pm
    void add_seconds(int);  //����n����
    void add_minutes(int);  //����n����  
    void add_hours(int);    //����nСʱ  
    static void change24(); //�ı侲̬��Աis_24����12��24ʱ��֮��ת��
    static void changefrom0();   //�ı侲̬��Աfrom0��ת���Ƿ�ǰ��0
private:
    static bool is_24; //Ϊtrueʱ��24Сʱ�ƣ���20:23:5��Ϊflase��12Сʱ�ƣ���ʾΪ8:23:5 pm 
    static bool from0; //Ϊtrueʱ��ǰ��0��8:23:5��ʾΪ08:23:05
    int hour;
    int minute;
    int sec;
};
bool Time::is_24=true;
bool Time::from0=false;

Time::Time(int h,int m,int s): hour(h), minute(m), sec(s){}

void Time::show_time( )     //��Ҫһ������Ҫ���������ʱ��ֱ����if-else����һ�ֽǶȣ�д�����ĳ�����
{
    //��� ʱ
    int h=(is_24)?hour:hour%12;  //����д������ļ��
    //if(is_24)   //��Ҫд��if(is_24==true)���ԣ����Ե���Щ̫��
    //	h=hour;
    //else 
    //	h=hour%12;
    if (h<10 && from0) cout<<'0';   //д��if (h<10 && from0==true)...���Բ���
    cout<<h<<':';
    
    //��� ��
    if(minute<10 && from0) cout<<'0';
    cout<<minute<<':';
    
    //��� ��
    if(sec<10&&from0) cout<<'0';
    cout<<sec; 
    
    //���pm��am
    if(!is_24)  //��дif(is_24==false)...ǿ
        cout<<(hour>12)? " pm":" am";//����д������ļ��
    
    //if (hour>12)
    //	cout<<" pm";
    //else
    //	cout<<" am";
    cout<<endl;
}

void Time::add_seconds(int n) //����n����  
{  
    sec+=n;        
    if (sec>59)     
    {  
        add_minutes(sec/60);    
        sec%=60;        
    }  
}  

void Time::add_minutes(int n) //����n����  
{  
    minute+=n;  
    if (minute>59)   
    {  
        add_hours(minute/60);  
        minute%=60;  
    }  
}  

void Time::add_hours(int n) //����nСʱ  
{  
    hour+=n;  
    if (hour>23)  
        hour%=24;       
}  

void Time::change24()
{
    is_24=!is_24;
}
void Time::changefrom0()
{
    from0=!from0;
}

int main( )   
{
    Time t1(23,14,25),t2(8,45,6); 
    cout<<"24ʱ��, ��ǰ��0��"<<endl;
    cout<<"    t1�ǣ�";
    t1.show_time();
    cout<<"    t2�ǣ�";
    t2.show_time();
    t1.add_hours(10);
    t2.add_hours(10);
    Time::changefrom0(); //ע��˴����þ�̬��Ա
    cout<<"10Сʱ��, �л��Ƿ�ǰ��0��"<<endl;
    cout<<    "t1�ǣ�";
    t1.show_time();
    cout<<    "t2�ǣ�";
    t2.show_time();
    t1.change24();
    cout<<"��һ����ʽ��"<<endl;
    cout<<"    t1�ǣ�";
    t1.show_time();
    cout<<"    t2�ǣ�";
    t2.show_time();
    system("pause");
    return 0;
}