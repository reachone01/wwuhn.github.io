/* ����ͷ��ע�Ϳ�ʼ           �������Ǻ�����
* ����İ�Ȩ�Ͱ汾��������
* Copyright (c) 2011, ��̨��ѧ�����ѧԺѧ��
* All rights reserved.
* �ļ����ƣ� sintable.cpp                           
* ��    �ߣ� ������                           
* ������ڣ� 2011 �� 11 �� 22 ��
* �汾 �ţ� v1.0           

  * ��������ⷽ������������
  * ������������
  * ��������������һ�����Ǻ�����
  Ҫ����main()�����е���show_sin_table(min_angle, max_angle)��
  ��ʾ�Ƕ�ֵΪmin_angle��max_angle֮������нǶȣ����Ϊ1�ȣ�������ֵ��
  Ҫ��������ѧ�⺯����������2�е�mysin������������������У����ڼ���sinֵ��
  ����show_sin_table(0, 90)������ʾ������0��90�ȵ�����ֵ��
  Ϊȡ�ø��õ�Ч�������Կ�����Ӣ�ߵ��׵�ת��һ�������ٲ������ʽ���������
  * ������������Ǻ�����
  * ����ͷ����ע�ͽ������˴�Ҳɾ����б�ܣ�
*/
#include <iostream>
#include <iomanip>
using namespace std;
double mysin(double);
double myabs(double);
void show_sin_table(int, int);
const double pi=3.1415926;
int main( )
{
    show_sin_table(0, 90);
    system("PAUSE");
    return 0;
}
//���涨��show_sin_table()����
void show_sin_table(int iFromAngle, int iToAngle)
{
    int x;
    cout<<setiosflags(ios::fixed)<<setiosflags(ios::right)<<setprecision(3);
    for(x=0; x<3;x++)
        cout<<setw(8)<<" �Ƕ�x"<<setw(8)<< "  sin(x)";
    cout<<"\n";   
    for(x=iFromAngle;x<=iToAngle; x++)
    {
        cout<<setw(8)<<x<<setw(8)<<mysin(x*pi/180); 
        if (x%3==0)cout<<"\n";          
    }   
}
//���涨��mysin����
double mysin(double x)
{
    double sum=x,x_pow=x,item;
    int n=1,fact=1,sign=1;     //�������ʱ����ֵ���Ѿ�����һ��ǵ��ۼӺ�sum��
    do
    {
        fact=fact*(n+1)*(n+2);  //fact���ڱ�ʾ�׳ˣ��ڹ�ʽ������ĸ
        x_pow*=x*x;             //x_pow�Ƿ��������ڱ�ʾ�׳ˣ��ڹ�ʽ������ĸ
        sign=-sign;             //ȷ������Ҫ�ۼӵ���һ��ķ���
        item =x_pow/fact*sign; //�����Ҫ�ۼӵ���
        sum+=item;              //�������ۼ���ȥ
        n+=2;
    }while(myabs(item)>1e-5);
    return sum;
}
//���涨��myabs����
double myabs(double x)
{
    return ((x>=0)?x:-x);
}