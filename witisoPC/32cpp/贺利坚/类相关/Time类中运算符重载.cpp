// Time�������������
#include <iostream>
using namespace std;
class CTime
{
private:
	unsigned short int hour;    // ʱ
	unsigned short int minute;  // ��
	unsigned short int second;  // ��
public:
	CTime(int h=0,int m=0,int s=0);
	void setTime(int h,int m,int s);
 
	//����������������
	friend istream &operator>>(istream &in,CTime &t);
	friend ostream &operator<<(ostream &out,CTime t); 
	//�Ƚ������(��Ŀ)������
	bool operator > (CTime &t);
	bool operator < (CTime &t);
	bool operator >= (CTime &t);
	bool operator <= (CTime &t);
	bool operator == (CTime &t);
	bool operator != (CTime &t);
	//��Ŀ�����������
	CTime operator+(CTime &c);//����c���涨��ʱ���֡�����ʱ�䣬��t1(8,20,25),t2(11,20,50)��t1+t2Ϊ:41:15
	CTime operator-(CTime &c);//����+���
	CTime operator+(int s);//����s����ʱ��
	CTime operator-(int s);//����s��ǰ��ʱ��
	//һĿ�����������
	CTime operator++(int);//����++����һ��
	CTime operator++();//ǰ��++����һ��
	CTime operator--(int);//����--��ǰһ��
	CTime operator--();//ǰ��--��ǰһ��
	//��ֵ�����������  
	CTime operator+=(CTime &c);
	CTime operator-=(CTime &c);
	CTime operator+=(int s);//����s����ʱ��
	CTime operator-=(int s);//����s��ǰ��ʱ��
};
 
//���캯��
CTime::CTime(int h,int m,int s)
{
	hour=h;
	minute=m;
	second=s;
}
// ����ʱ��
void CTime::setTime(int h,int m,int s)
{
	hour=h;
	minute=m;
	second=s;
}
 
// �������������>>
istream &operator>>(istream &in,CTime &t)
{
	char ch1,ch2;
	while(1)
	{
		cout<<"������ʱ��(hh:mm:ss) ";
		cin>>t.hour>>ch1>>t.minute>>ch2>>t.second;
		if (ch1==':' && ch2==':')
			if (t.hour>-1 && t.hour<24 && t.minute>-1 && t.minute<60 && t.second>-1 && t.second<60) break;
		cerr<<"ʱ���ʽ����ȷ! ����������\n";
	}
	return cin;
}
 
// ������������<<
ostream &operator<<(ostream &out,CTime t)
{
	out<<t.hour<<':'<<t.minute<<':'<<t.second;
	return out;
}
 
 
//�Ƚ������������
bool CTime::operator > (CTime &t) // �ж�ʱ��t1>t2
{
	if (hour>t.hour) return true;
	if (hour<t.hour) return false;
	if (minute>t.minute) return true;
	if (minute<t.minute) return false;
	if (second>t.second) return true;
	return false;
}
 
bool CTime::operator < (CTime &t)// �ж�ʱ��t1<t2
{
	if (hour<t.hour) return true;
	if (hour>t.hour) return false;
	if (minute<t.minute) return true;
	if (minute>t.minute) return false;
	if (second<t.second) return true;
	return false;
}
 
bool CTime::operator == (CTime &t)// �ж�ʱ��t1==t2
{
	if (*this<t || *this>t) return false;
	return true;
}
 
bool CTime::operator != (CTime &t) // �ж�ʱ��t1!=t2
{
	if (*this==t) return false;
	return true;
}
 
bool CTime::operator >= (CTime &t)// �ж�ʱ��t1>=t2
{
	if (*this<t) return false;
	return true;
}
 
bool CTime::operator <= (CTime &t) // �ж�ʱ��t1<=t2
{
	if (*this>t) return false;
	return true;
}
 
//��Ŀ�����������
// ����ʱ��֮��, ����c���涨��ʱ���֡�����ʱ�䣬��t1(8,20,25),t2(11,20,50)��t1+t2Ϊ:41:15
CTime CTime::operator + (CTime &t)
{
 
	int h,m,s;
	s=second+t.second;
	m=minute+t.minute;
	h=hour+t.hour;
	if (s>59)
	{
		s-=60;
		m++;
	}
	if (m>59)
	{
		m-=60;
		h++;
	}
	while (h>23) h-=24;
	CTime t0(h,m,s);
	return t0;
}
 
//����s����ʱ��
CTime CTime::operator+(int s)
{
	int ss=s%60;
	int mm=(s/60)%60;
	int hh=s/3600;
	CTime t0(hh,mm,ss);
	return *this+t0;
}
 
// ����ʱ��֮��
CTime CTime::operator - (CTime &t)
{
	int h,m,s;
	s=second-t.second;
	m=minute-t.minute;
	h=hour-t.hour;
	if (s<0)
	{
		s+=60;
		m--;
	}
	if (m<0)
	{
		m+=60;
		h--;
	}
	while (h<0) h+=24;
	CTime t0(h,m,s);
	return t0;
}
 
//����s��ǰ��ʱ��
CTime CTime::operator-(int s)
{
	int ss=s%60;
	int mm=(s/60)%60;
	int hh=s/3600;
	CTime t0(hh,mm,ss);
	return *this-t0;
}
 
//һĿ�����������
CTime CTime::operator++(int)//����++����һ��
{
	CTime t=*this;
	*this=*this+1;
	return t;
}
 
CTime CTime::operator++()//ǰ��++����һ��
{
	*this=*this+1;
	return *this;
}
 
CTime CTime::operator--(int)//����--��ǰһ��
{
	CTime t=*this;
	*this=*this-1;
	return t;
}
 
CTime CTime::operator--()//ǰ��--��ǰһ��
{
	*this=*this-1;
	return *this;
}
 
//��ֵ�����������  
CTime CTime::operator+=(CTime &c)
{
	*this=*this+c;
	return *this;
}
CTime CTime::operator-=(CTime &c)
{
	*this=*this-c;
	return *this;
}
CTime CTime::operator+=(int s)//����s����ʱ��
{
	*this=*this+s;
	return *this;
}
CTime CTime::operator-=(int s)//����s��ǰ��ʱ��
{
	*this=*this-s;
	return *this;
}
 
int main()
{
	CTime t1,t2,t;
 
	cout<<"t1Ϊ��";
	cin>>t1;
	cout<<"t2Ϊ��";
	cin>>t2;
	cout<<"����Ƚ�����ʱ���С��\n";
	if (t1>t2) cout<<"t1>t2"<<endl;
	if (t1<t2) cout<<"t1<t2"<<endl;
	if (t1==t2) cout<<"t1��t2"<<endl; 
	if (t1!=t2) cout<<"t1��t2"<<endl;
	if (t1>=t2) cout<<"t1��t2"<<endl;
	if (t1<=t2) cout<<"t1��t2"<<endl;
	cout<<endl;
	cout<<"t1= "<<t1<<endl;
	cout<<"t2= "<<t2<<endl;
 
	cout<<"t=t1++"<<endl;
	t=t1++;
	cout<<"t= "<<t<<"    t1= "<<t1<<endl;
 
	cout<<"t=++t1"<<endl;
	t=++t1;
	cout<<"t= "<<t<<"    t1= "<<t1<<endl;
 
	cout<<"t1+t2= "<<t1+t2<<endl;
	cout<<"t1-t2= "<<t1-t2<<endl;
	cout<<"t1+2000= "<<t1+2000<<endl;
	cout<<"t1-5000= "<<t1-5000<<endl;
 
	system("pause");
	return 0;
}