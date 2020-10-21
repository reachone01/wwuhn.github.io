//�������ڡ���γ�����ճ�����ʱ��
//113.247247,23.272323
//http://api.map.baidu.com/lbsapi/getpoint/index.html
#define PI 3.1415926
#include<math.h>
#include<iostream>
using namespace std;
int days_of_month_1[]={31,28,31,30,31,30,31,31,30,31,30,31};
int days_of_month_2[]={31,29,31,30,31,30,31,31,30,31,30,31};
long double h=-0.833;
//����ȫ�ֱ���
void input_date(int c[]){//��������
	int i;
	cout<<"Enter date(2019 09 29):"<<endl;
	for(i=0;i<3;i++){
		cin>>c[i];
	}
}
void input_glat(int c[]){//����γ��
	long double lati;
	cout<<"Enter latitude(γ��)(23.272323(means 23��16��20��)):"<<endl;
	cin>>lati;
	c[0] = static_cast<int>(lati);
	c[1] = static_cast<int>((lati-c[0])*60);
	c[2] = ((lati-c[0])*60-c[1])*60;
}
/*
void input_glat(int c[]){//����γ��
	int i;
	cout<<"Enter latitude(γ��)(0��- 60��,40 40 40(means40��14��50��)):"<<endl;
	for(i=0;i<3;i++){
		cin>>c[i];
	}
}

void input_glong(int c[]){//���뾭��
	int i;
	cout<<"Enter longitude(����)(westIsNegativ,113.247247(40��40��40��)):"<<endl;
	for(i=0;i<3;i++){
		cin>>c[i];
	}
}
*/
void input_glong(int c[]){//���뾭��
	long double longi;
	cout<<"Enter longitude(����)(westIsNegativ,113.247247(113��14��50��)):"<<endl;
	cin>>longi;
	c[0] = static_cast<int>(longi);
	c[1] = static_cast<int>((longi-c[0])*60);
	c[2] = ((longi-c[0])*60-c[1])*60;
}
//�ж��Ƿ�Ϊ����:��Ϊ���꣬����1���������꣬����0
int leap_year(int year){
	if(((year%400==0) || (year%100!=0) && (year%4==0))) return 1;
	else return 0;
}

int days(int year, int month, int date){
	int i,a=0;
	for(i=2000;i<year;i++){
		if(leap_year(i)) a=a+366;
		else a=a+365;
	}
	if(leap_year(year)){
		for(i=0;i<month-1;i++){
			a=a+days_of_month_2[i];
		}
	}
	else {
		for(i=0;i<month-1;i++){
			a=a+days_of_month_1[i];
		}
	}
	a=a+date;
	return a;
}
//��Ӹ�������ʱ�乫Ԫ2000��1��1�յ�����������days
long double t_century(int days, long double UTo){
	return ((long double)days+UTo/360)/36525;
}
//���������ʱ�乫Ԫ2000��1��1�յ������յ�������t
long double L_sun(long double t_century){
	return (280.460+36000.770*t_century);
}
//��̫����ƽ�ƾ�
long double G_sun(long double t_century){
	return (357.528+35999.050*t_century);
}
//��̫����ƽ�����
long double ecliptic_longitude(long double L_sun,long double G_sun){
	return (L_sun+1.915*sin(G_sun*PI/180)+0.02*sin(2*G_sun*PI/180));
}
//��Ƶ�����
long double earth_tilt(long double t_century){
	return (23.4393-0.0130*t_century);
}
//��������
long double sun_deviation(long double earth_tilt, long double ecliptic_longitude){
	return (180/PI*asin(sin(PI/180*earth_tilt)*sin(PI/180*ecliptic_longitude)));
}
//��̫��ƫ��
long double GHA(long double UTo, long double G_sun, long double ecliptic_longitude){
	return (UTo-180-1.915*sin(G_sun*PI/180)-0.02*sin(2*G_sun*PI/180)+2.466*sin(2*ecliptic_longitude*PI/180)-0.053*sin(4*ecliptic_longitude*PI/180));
}
//���������ʱ���̫��ʱ���GHA
long double e(long double h, long double glat, long double sun_deviation){
	return 180/PI*acos((sin(h*PI/180)-sin(glat*PI/180)*sin(sun_deviation*PI/180))/(cos(glat*PI/180)*cos(sun_deviation*PI/180)));
}
//������ֵe
long double UT_rise(long double UTo, long double GHA, long double glong, long double e){
	return (UTo-(GHA+glong+e));
}
//���ճ�ʱ��
long double UT_set(long double UTo, long double GHA, long double glong, long double e){
	return (UTo-(GHA+glong-e));
}
//������ʱ��
long double result_rise(long double UT, long double UTo, long double glong, long double glat, int year, int month, int date){
	long double d;
	if(UT>=UTo) d=UT-UTo;
	else d=UTo-UT;
	if(d>=0.1) {
		UTo=UT;
		UT=UT_rise(UTo,GHA(UTo,G_sun(t_century(days(year,month,date),UTo)),ecliptic_longitude(L_sun(t_century(days(year,month,date),UTo)),G_sun(t_century(days(year,month,date),UTo)))),glong,e(h,glat,sun_deviation(earth_tilt(t_century(days(year,month,date),UTo)),ecliptic_longitude(L_sun(t_century(days(year,month,date),UTo)),G_sun(t_century(days(year,month,date),UTo))))));
		result_rise(UT,UTo,glong,glat,year,month,date);
	}
	return UT;
}
//�жϲ����ؽ�����ճ���
long double result_set(long double UT, long double UTo, long double glong, long double glat, int year, int month, int date){
	long double d;
	if(UT>=UTo) d=UT-UTo;
	else d=UTo-UT;
	if(d>=0.1){
		UTo=UT;
		UT=UT_set(UTo,GHA(UTo,G_sun(t_century(days(year,month,date),UTo)),ecliptic_longitude(L_sun(t_century(days(year,month,date),UTo)),G_sun(t_century(days(year,month,date),UTo)))),glong,e(h,glat,sun_deviation(earth_tilt(t_century(days(year,month,date),UTo)),ecliptic_longitude(L_sun(t_century(days(year,month,date),UTo)),G_sun(t_century(days(year,month,date),UTo))))));
		result_set(UT,UTo,glong,glat,year,month,date);
	}
	return UT;
}
//�жϲ����ؽ�������䣩
int Zone(long double glong){
	if(glong>=0) return (int)((int)(glong/15.0)+1);
	else return (int)((int)(glong/15.0)-1);
}
//��ʱ��
void output(long double rise, long double set, long double glong){
	if((int)(60*(rise/15+Zone(glong)-(int)(rise/15+Zone(glong))))<10)
		cout<<"The time at which the sun rises is "<<(int)(rise/15+Zone(glong))<<":0"<<(int)(60*(rise/15+Zone(glong)-(int)(rise/15+Zone(glong))))<<" .\n";
	else cout<<"The time at which the sun rises is "<<(int)(rise/15+Zone(glong))<<":"<<(int)(60*(rise/15+Zone(glong)-(int)(rise/15+Zone(glong))))<<" .\n";
	if((int)(60*(set/15+Zone(glong)-(int)(set/15+Zone(glong))))<10)
		cout<<"The time at which the sun sets is "<<(int)(set/15+Zone(glong))<<": "<<(int)(60*(set/15+Zone(glong)-(int)(set/15+Zone(glong))))<<" .\n";
	else cout<<"The time at which the sun sets is "<<(int)(set/15+Zone(glong))<<":"<<(int)(60*(set/15+Zone(glong)-(int)(set/15+Zone(glong))))<<" .\n";
}
//��ӡ���
int main(){
	long double UTo=180.0;
	int year,month,date;
	long double glat,glong;
	int c[3];
	input_date(c);
	year=c[0];
	month=c[1];
	date=c[2];

	input_glat(c);
	glat=c[0]+c[1]/60.0+c[2]/3600.0;
	cout<<c[0]<<" "<<c[1]<<" "<<c[2]<<" "<<glat<<endl;

	input_glong(c);
	glong=c[0]+c[1]/60.0+c[2]/3600.0;
	cout<<c[0]<<" "<<c[1]<<" "<<c[2]<<" "<<glong<<endl;

	long double rise,set;
	rise=result_rise(UT_rise(UTo,GHA(UTo,G_sun(t_century(days(year,month,date),UTo)),ecliptic_longitude(L_sun(t_century(days(year,month,date),UTo)),G_sun(t_century(days(year,month,date),UTo)))),glong,e(h,glat,sun_deviation(earth_tilt(t_century(days(year,month,date),UTo)),ecliptic_longitude(L_sun(t_century(days(year,month,date),UTo)),G_sun(t_century(days(year,month,date),UTo)))))),UTo,glong,glat,year,month,date);
	set=result_set(UT_set(UTo,GHA(UTo,G_sun(t_century(days(year,month,date),UTo)),ecliptic_longitude(L_sun(t_century(days(year,month,date),UTo)),G_sun(t_century(days(year,month,date),UTo)))),glong,e(h,glat,sun_deviation(earth_tilt(t_century(days(year,month,date),UTo)),ecliptic_longitude(L_sun(t_century(days(year,month,date),UTo)),G_sun(t_century(days(year,month,date),UTo)))))),UTo,glong,glat,year,month,date);
	output(rise,set,glong);

	system("pause");
	return 0;
}
/*
Enter date(2019 09 29):
2019 10 1
Enter latitude(γ��)(23.272323(means 23��16��20��)):
23.272323
23 16 20 23.2722
Enter longitude(����)(westIsNegativ,113.247247(113��14��50��)):
113.247247
113 14 50 113.247
The time at which the sun rises is 6:18 .
The time at which the sun sets is 18:13 .
*/