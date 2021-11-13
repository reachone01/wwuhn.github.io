#include <iostream>  // ������
using namespace std;
// ���磺2021��Ļ����� 1202 
// month��Ӧ2021�ĺ���λ�������12 
// day��Ӧ2021��ǰ��λ�������02
// �ж�12�ǲ���2021�Ϸ����£�02�ǲ���2021�Ϸ�����
#define STARTY 2021
#define ENDY 2120
int palindromeDay(int year)
{
    int month,day; // ���ڴ���ݹ����¡���
    
    month=year%100;                     //monthȡ��������ĺ���λ
    month = (month%10)*10 + month/10;   //������λ��������ȷ���·�
    day=year/100;                       //dayȡ���������ǰ��λ
    day=(day%10)*10+day/10;             //��ǰ��λ��������ȷ������
    bool is_cycle =false;
    switch(month)               //12���·ݣ����Զ�Ӧ�Ϸ������ڷ�Χ
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12: if(day<=31) is_cycle =true; break;
    case 4:
    case 6:
    case 9:
    case 11: if(day<=30) is_cycle=true; break;
    case 2: if((year%4==0&&year%100!=0)||year%400==0) //����
            {
                if(day<=29) is_cycle =true;
            }
        else
            if(day<=28) is_cycle =true; break;
    default: break;         //����λ�����������������·�
    }
    int  anothery = 0;          // ����Ļ�����������Ϊһ������
    if(is_cycle)            //�ܹ��ɻ����գ��������չ����һ��������
    {
        int y=year;         // ��ʱ���ڵ���
        anothery=year; // ����Ļ�����������Ϊһ������
        while(y>0)
        {
            anothery=anothery*10+y%10;
            y=y/10;
        }
    }
    return anothery;
}

int main( )
{
    cout<<STARTY<<" - "<<ENDY << "�Ļ����գ�"<<endl;
    int counts = 0;
    for(int year = STARTY; year < ENDY; year++)
        if(palindromeDay(year))
        {
            cout<<palindromeDay(year)<<endl;
            counts++;
        }
    cout<<ENDY-STARTY+1<<"�꣬�ϼ� "<<counts<<" �������ա�"<<endl;
    while(1);
    return 0;
}

#if 0
#include <iostream>
using namespace std;
int main( )
{
	int year,month,day,y,anothery;
	bool is_cycle;
	int count=0;
	for(year = 2012; year < 2092; year++)
	{
		month=year%100; //monthȡ��������ĺ���λ
		month = (month%10)*10 + month/10; //������λ��������ȷ���·�
		day=year/100;   //dayȡ���������ǰ��λ
		day=(day%10)*10+day/10; //��ǰ��λ��������ȷ������
		is_cycle =false;
		switch(month) //12���·ݣ����Զ�Ӧ�Ϸ������ڷ�Χ
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12: if(day<=31) is_cycle =true; break;
		case 4:
		case 6:
		case 9:
		case 11: if(day<=30) is_cycle=true; break;
		case 2: if((year%4==0&&year%100!=0)||year%400==0) //����
				{
					if(day<=29) is_cycle =true;
				}
			else
				if(day<=28) is_cycle =true; break;
		default: continue; //����λ�����������������·�
		}
		if(is_cycle) //�ܹ��ɻ�����
		{
			y=year;
			anothery=year;
			while(y>0)
			{
				anothery=anothery*10+y%10;
				y=y/10;
			}
			cout<<anothery<<endl;
			count++;
		}
	}
	cout<<"���� "<< count <<"�������ա�"<<endl;
	return 0;
}
#endif