#if 1
//̫���Ƕȼ���
/*
*�ļ�����  ��ȷ̫���Ƕȼ��� 
*�����ܣ��˳������涨�涨���ڵĹ涨ʱ��ĵ�ƽ��λ�Ǻ��Ӹ߶Ƚ�
*����汾�����̫���Ƕȼ��������޸� 
*�Ķ����֣���̫����γ�ǡ�ʱ�ǵ��㷨��������������ʱ��Ȳ���
2019 11 12
17 0 0
113 23

*���������
*����ʱ����ꡢ�¡���          y��m��d
*����ʱ���ʱ����              h,m,s
*����ص�����                LONG
*����ص���γ��                LAT
*���������                    ��Ļ��ӡ*/

#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

#define PI 3.14159265358979

/*
*����(���������ڵ�˳���)���㺯��n_ca
*�������Ϊ�£�a���գ�b
*���Ϊ����Ϊ����ĵ�n��*/
unsigned int  n_ca(unsigned int y, unsigned int a,unsigned int b);

/*
*�սǼ��㺯��=2��t/365.2422
*�������Ϊ���꣺y�����գ�n
*���Ϊ�ս� angle_day */
double angle_day_ca(unsigned int n,unsigned int y)
{
	double n0;
	n0=79.6764+0.2433*(y-1985)-((y-1985)/4);
	n0=79.6764+0.2422*(y-1985)-int((y-1985)/4);//�ٶȰٿ�
	//cout<<"�սǵ�n0:"<<n0<<endl;
	double t=n-n0;
	return 2*PI*t/365.2422;
}

/*
*��γ�ǵļ��㺯��delt_sun_ca
*��γ�ǣ���γ�������켫��̫���Ļ��ߣ���������������
	     *̫������������������ƽ���γɵĽǶ�
*�������Ϊ���ս�angle_day
*���Ϊ��γ�� delt_sun*/
double delt_sun_ca(double a)
{
	double d=(0.3723+23.2567*sin(a)+0.1149*sin(2*a)-0.1712*sin(a)-0.758*cos(a)+
			0.3656*cos(2*a)+0.0201*cos(3*a))*PI/180;//0.1712*sin(3*a)
	return d;

}
double delt_sun_ca1(double a)
{
	double d = (0.3723+23.2567*sin(a)+0.1149*sin(2*a)-0.1712*sin(3*a)-0.758*cos(a)+
			0.3656*cos(2*a)+0.0201*cos(3*a))*PI/180;//0.1712*sin(3*a) //�ٶȰٿ�

	return d;

}
double delt_sun_ca2(unsigned int n) //������������� //����
{
	double d = 0.98563*(n-173)/180*PI;
	d = 0.39795*cos(d); //�ٶȰٿ�sin��=0.39795cos[0.98563(N-173)/180*pi]��
								// �ĵ�λΪ���ȣ�ʽ��NΪ��������ÿ��1��1�տ�ʼ����
	d = asin(d);
	return d;

}

double delt_sun_ca3(unsigned int n) //������������� //����
{
	double b = 2*PI*(n-1)/365;
	double d = 0.006918-0.399912*cos(b)+0.070257*sin(b)-0.006758*cos(2*b)+0.000907*sin(2*b)-0.002697*cos(3*b)+0.00148*sin(3*b);
	d = 180/PI*(d);
	return d;
}
double delt_sun_ca4(unsigned int n) //������������� //����
{
	double d = 23.45*sin((284+n)/365*360);
	return d;
}

/*
*ʱ����㺯��
*�������Ϊ�ս�angle_day
*���Ϊʱ��et*/
double et_ca(double a)
{
	return 0.0028-1.9857*sin(a)+9.9059*sin(2*a)-7.0924*cos(a)-0.6882*cos(2*a);
}

/*
*ʱ�Ǽ��㺯��
*�������Ϊ:ʱ���룺hour��minute��sec��ʱ��et,������LONG
*���Ϊʱ��angle_hour*/
double angle_hour_ca(unsigned int h,unsigned int m,unsigned s,double e,double l)
{
	return  (h-12)+(m-(120*PI/180-l)*4*180/PI+e)/60+(s/3600)*15*PI/180;
}


int main()/*����������̫���߶Ƚ��뷽λ��*/
{
	// ���������գ�ʱ��
	unsigned int  y,m,d;
	unsigned int hour,minute,sec;
	cout<<"���뵱ǰ�����գ���2019 9 29:"<<endl;
	cin>>y>>m>>d;

	cout<<"���뵱ǰʱ���룬��14 14 14:"<<endl;
	cin>>hour>>minute>>sec;

	// ���뾭γ��
	double  LONG,LAT;
	cout<<"���뵱�ؾ���LONG���뵱��γ��LAT(�Ƕ�)����113 23��"<<endl;
	cin>>LONG>>LAT;

	cout<<endl;
	LONG=LONG*PI/180;
	LAT=LAT*PI/180;
	cout<<"����ľ��ȡ�γ�ȣ����ȣ���"<<LONG<<","<<LAT<<"rad\n";
	
	// ���㵱ǰ��γ��
	double  delt_sun,angle_day;
	unsigned int n;
	n=n_ca(y,m,d);
	cout<<"������һ���еĵ�"<<n<<"�졣\n";
	angle_day=angle_day_ca(n,y);
	// delt_sun=delt_sun_ca(angle_day);
	//delt_sun=delt_sun_ca2(n);
	//delt_sun=delt_sun_ca4(n);
	cout<<"��ǰ��̫����γ���Ƕȣ�Ϊ��"<<(delt_sun*180/PI)<<"��\n";
	cout<<"��ǰ��̫����γ�����ȣ�Ϊ��"<<delt_sun<<"\n";
	
	
	// ����߶Ƚ�
	//sinH�� sin��sin�ģ� cos��cos��cost
	//����,H��̫���߶Ƚ�,���ǵ��صĵ���γ��,���ǵ��յ�̫����γ,t�ǵ�ʱ��̫��ʱ�ǡ�
	double et,angle_hour;
	et=et_ca(angle_day); // ʱ��
	angle_hour=angle_hour_ca(hour,minute,sec,et,LONG);
	cout<<"����̫����ʱ��Ϊ"<<(angle_hour*180/PI)<<"��\n";

	double sin_h, h_sun,h_sun1;
	/*����߶Ƚǵ�����ֵ*/
	sin_h=sin(LAT)*sin(delt_sun)+cos(LAT)*cos(delt_sun)*cos(angle_hour);
	h_sun=asin(sin_h);
	h_sun1=h_sun*180/PI;
	cout<<"ת���ɵ�ǰ̫���ĸ߶Ƚ�Ϊ��"<<h_sun1<<"��\n";
	
	// ���㷽λ��
	double cos_gam,gam_sun,gam_sun1;
	cos_gam=(sin_h*sin(LAT)-sin(delt_sun))/(cos(h_sun)*cos(LAT));
	gam_sun=acos(cos_gam);
	gam_sun1=gam_sun*180/PI;//ת���ɽǶ���
	cout<<"��ǰ̫���ķ�λ��Ϊ:"<<gam_sun<<"rad,"<<gam_sun1<<" ��\n";
	system("pause");
	return 0;
}

/*****�������岿��*****/
/*���ռ��㺯������*/
int daysOfMonth(unsigned int y,unsigned int m)
{
	int leap=(y%4==0 && y%100!=0||y%400==0)?1:0;
	switch(m)
	{
	case 1:case 3:case 5:case 7:case 8:case 10:case 12:return 31;
	case 2:return 28+leap;
	case 4:case 6:case 9:case 11:return 30;
	default:
		cout<<"�·��������\n";
	}
}
unsigned int  n_ca(unsigned int y, unsigned int m,unsigned int d)
{
	unsigned int sum = d;
	for(int i=1;i<m;++i)
		sum+=daysOfMonth(y,i);
	return sum;
}

/*******************************�������*****************************/
/*
���뵱ǰ�����գ���2019 9 29:
2019 9 29
���뵱ǰʱ���룬��14 14 14:
14 14 14
���뵱�ؾ���LONG�뵱��γ��LAT����113 23��
113 23
����ľ���γ�ȷֱ�Ϊ��1.97222rad,0.401426rad
������һ���еĵ�272�졣
��ǰ��̫����γΪ��-0.0382322rad
ת���ɽǶ���̫����γ��Ϊ-2.19054��
����̫����ʱ��Ϊ1.93047rad.
ת���ɵ�ǰ̫���ĸ߶Ƚ�Ϊ��-19.7971��
��ǰ̫���ķ�λ��Ϊ:1.67968rad,96.2383 ��
*/
#endif


#if 0   //̫����γ�ǵļ��㻻��һ�ַ�ʽ������޼�
//̫���Ƕȼ���
/****************************************************************************
*�ļ�����  ��ȷ̫���Ƕȼ��� 
*�����ܣ��˳������涨�涨���ڵĹ涨ʱ��ĵ�ƽ��λ�Ǻ��Ӹ߶Ƚ�
*����汾�����̫���Ƕȼ��������޸� 
*�Ķ����֣���̫����γ�ǡ�ʱ�ǵ��㷨��������������ʱ��Ȳ���
*****************************************************************************
*���������
*����ʱ����ꡢ�¡���          y��m��d
*����ʱ���ʱ����              h,m,s
*����ص�����                LONG
*����ص���γ��                LAT
*���������                    ��Ļ��ӡ
******************************************************************************/
#include<iostream>
#include<math.h>
using namespace std;

#define  PI   3.14159265358979


/****************************************************************************
*����(���������ڵ�˳���)���㺯��n_ca
*�������Ϊ�£�a���գ�b
*���Ϊ����Ϊ����ĵ�n��*/
unsigned int  n_ca(unsigned int a,unsigned int b);

/****************************************************************************
*�սǼ��㺯��=2��t/365.2422
*�������Ϊ���꣺y�����գ�n
*���Ϊ�ս� angle_day */

double angle_day_ca(unsigned int n,unsigned int y)
{
	double n0=79.6764+0.2433*(y-1985)-((y-1985)/4);
	double t=n-n0;
	return 2*PI*t/365.2422;
}


/****************************************************************************
*��γ�ǵļ��㺯��delt_sun_ca2
*�������Ϊ���¡���
*���Ϊ��γ�� delt_sun*/

double delt_sun_ca2(double m,double d)
{
	int N = n_ca(m,d);
	double b =2*PI*(N-1)/365;
	
    return 0.006918-0.399912*cos(b)+0.070257*sin(b)-0.006758*cos(2*b)+ 
		   0.000907*sin(2*b)-0.002697*cos(3*b)+0.00148*sin(3*b);

// ����delta�ĵ�λΪ��(deg)��pi=3.1415926ΪԲ���ʣ�
// b=2*pi*(N-1)/365����λΪ���ȣ�
// NΪ��������ÿ��1��1�տ�ʼ���㡣
}
/****************************************************************************
*ʱ����㺯��
*�������Ϊ�ս�angle_day
*���Ϊʱ��et*/
double et_ca(double a)
{
	return 0.0028-1.9857*sin(a)+9.9059*sin(2*a)-7.0924*cos(a)-0.6882*cos(2*a);
}

/****************************************************************************
*ʱ�Ǽ��㺯��
*�������Ϊ:ʱ���룺hour��minute��sec��ʱ��et,������LONG
*���Ϊʱ��angle_hour*/
double angle_hour_ca(unsigned int h,unsigned int m,unsigned s,double e,double l)
{
	return  (h-12)+(m-(120*PI/180-l)*4*180/PI+e)/60+(s/3600)*15*PI/180;
}

/****************����������̫���߶Ƚ��뷽λ��************/
int main()
{
	/**************���������գ�ʱ��***************/
	unsigned int  y,m,d;
	unsigned int hour,minute,sec;
	cout<<"���뵱ǰ�����գ���2019 9 29:"<<endl;
	cin>>y>>m>>d;
	cout<<"���뵱ǰʱ���룬��14 14 14:"<<endl;
	cin>>hour>>minute>>sec;
	
	/***************���뾭γ��****************/
	double  LONG,LAT;
	cout<<"���뵱�ؾ���LONG�뵱��γ��LAT����113 23��"<<endl;
	cin>>LONG>>LAT;
	LONG=LONG*PI/180;
	LAT=LAT*PI/180;
	cout<<"����ľ���γ�ȷֱ�Ϊ��"<<LONG<<"rad,"<<LAT<<"rad\n";
	
	/***************���㵱ǰ��γ��***********/
	double  delt_sun,angle_day;
	unsigned int n;
	n=n_ca(m,d);
	cout<<"������һ���еĵ�"<<n<<"�졣\n";
	angle_day=angle_day_ca(n,y);
	//delt_sun=delt_sun_ca(angle_day);
	delt_sun=delt_sun_ca2(m,d);
	cout<<"��ǰ��̫����γΪ��"<<delt_sun<<"rad\n";
	cout<<"ת���ɽǶ���̫����γ��Ϊ"<<(delt_sun*180/PI)<<"��\n";
	
	/****************����߶Ƚ�**************/
	//sinH�� sin��sin�ģ� cos��cos��cost

	//����,H��̫���߶Ƚ�,���ǵ��صĵ���γ��,���ǵ��յ�̫����γ,t�ǵ�ʱ��̫��ʱ�ǡ�
	double et,angle_hour;
	et=et_ca(angle_day);
	angle_hour=angle_hour_ca(hour,minute,sec,et,LONG);
	cout<<"����̫����ʱ��Ϊ"<<angle_hour<<"rad.\n";
	double sin_h, h_sun,h_sun1;
	sin_h=sin(LAT)*sin(delt_sun)+cos(LAT)*cos(delt_sun)*cos(angle_hour);//����߶Ƚǵ�����ֵ
	h_sun=asin(sin_h);
	h_sun1=h_sun*180/PI;
	cout<<"ת���ɵ�ǰ̫���ĸ߶Ƚ�Ϊ��"<<h_sun1<<"��\n";
	
	//���㷽λ��
	double cos_gam,gam_sun,gam_sun1;
	cos_gam=(sin_h*sin(LAT)-sin(delt_sun))/(cos(h_sun)*cos(LAT));
	gam_sun=acos(cos_gam);
	gam_sun1=gam_sun*180/PI;//ת���ɽǶ���
	cout<<"��ǰ̫���ķ�λ��Ϊ:"<<gam_sun<<"rad,"<<gam_sun1<<" ��\n";
	cout<<endl;
	


	system("pause");
	return 0;
}

/*****�������岿��*****/
/*���ռ��㺯������*/
unsigned int  n_ca(unsigned int a,unsigned int b)
{
	int n=0;
	switch(a)
	{
	case 1:
		n=b;break;
	case 2:
		n=31+b;break;
	case 3:
		n=31+28+b;break;
	case 4:
		n=31+28+31+b;break;
	case 5:
		n=31+28+31+30+b;break;
	case 6:
		n=31+28+31+30+31+b;break;
	case 7:
		n=31+28+31+30+31+30+b;break;
	case 8:
		n=31+28+31+30+31+30+31+b;break;
	case 9:
		n=31+28+31+30+31+30+31+31+b;break;
	case 10:
		n=31+28+31+30+31+30+31+31+30+b;break;
	case 11:
		n=31+28+31+30+31+30+31+31+30+31+b;break;
	case 12:
		n=31+28+31+30+31+30+31+31+30+31+30+b;break;
	default:
		cout<<"�·��������\n";
	}
	return  n;
}

/*******************************�������*****************************/
/*
2019 11 12
17 14 14
113 23

���뵱ǰ�����գ���2019 9 29:
2019 9 29
���뵱ǰʱ���룬��14 14 14:
14 14 14
���뵱�ؾ���LONG�뵱��γ��LAT����113 23��
113 23
����ľ���γ�ȷֱ�Ϊ��1.97222rad,0.401426rad
������һ���еĵ�272�졣
��ǰ��̫����γΪ��-0.0382322rad
ת���ɽǶ���̫����γ��Ϊ-2.19054��
����̫����ʱ��Ϊ1.93047rad.
ת���ɵ�ǰ̫���ĸ߶Ƚ�Ϊ��-19.7971��
��ǰ̫���ķ�λ��Ϊ:1.67968rad,96.2383 ��
*/
#endif
