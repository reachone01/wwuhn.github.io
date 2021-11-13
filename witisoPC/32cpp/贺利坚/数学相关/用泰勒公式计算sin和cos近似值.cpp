/* ����ͷ��ע�Ϳ�ʼ         ��̩�չ�ʽ����sin��cos����ֵ
* ����İ�Ȩ�Ͱ汾��������
* Copyright (c) 2011, ��̨��ѧ�����ѧԺѧ��
* All rights reserved.
* �ļ����ƣ� sin_and_cos.cpp                           
* ��    �ߣ� ������                           
* ������ڣ� 2011 �� 11 �� 22 ��
* �汾 �ţ� v2.0        

  * ��������ⷽ������������
  * ������������
  * �����������Զ��庯������̩�չ�ʽʵ�ּ���sin��cos�Ľ���ֵ��Ҫ��
  ��1����sin��cosʱ����������ѧ�⺯��(��������#include<Cmath>)�������Լ��ຯ��ʵ�֣�
  Ϊ���𣬿��Էֱ�����Ϊmysin��mycos��
  ��2���Զ��庯��Ҫд��main����֮��
  ��3���Զ��庯����Ч��������뿼�ǣ�
  ��4�����ھ��ȣ������һ��ľ���ֵС��0.00001ʱ���ۼӽ�����
  * ���������sin(��/2)��cos(87��)��ֵ����ʾ����̩�չ�ʽ�ڦ�/2�������ϴ�
  ����ֱ�Ϊ0.911557��-0.26322������ֵ�ֱ�Ϊ1��0.052336����������Сʱ��Ч��Ҫ��һЩ����
  * �㷨��ƣ�ʹ��̩�չ�ʽ
  * ����ͷ����ע�ͽ������˴�Ҳɾ����б�ܣ�
  ���ڸ��ӵļ��㣬�������輸������
  ���ñ�����ԭ���ǣ�ÿ�������Ĺ��ܾ����ܵ�һ��
*/
#include <iostream> 
#include<Cmath>  //Ϊ���ڶԱȽ����main�����е�����Cmath�еĿ⺯��sin��cos
using namespace std;
const double pi=3.1415926;
double mysin(double);
double mycos(double);
double myabs(double);   //��������Ҫ�󾫶ȵľ���ֵ��Ҳ���Զ��庯����ɰ�
int main( )
{
    cout<<"sin(��/2)��ֵΪ"<<mysin(pi/2)<<endl;
    cout<<"cos(87��)��ֵΪ"<<mycos((87.0/180)*pi)<<endl;
    cout<<"���ÿ⺯�����sin(��/2)��ֵΪ"<<sin(pi/2)<<endl;
    cout<<"���ÿ⺯�����cos(87��)��ֵΪ"<<cos((87.0/180)*pi)<<endl;
    system("PAUSE");
    return 0;
}
//���涨��mysin����
double mysin(double x)
{
    double sum=x,x_pow=x,item;
    int n=1,fact=1,sign=1;      //�������ʱ����ֵ���Ѿ�����һ��ǵ��ۼӺ�sum��
    do
    {
        fact=fact*(n+1)*(n+2);  //fact���ڱ�ʾ�׳ˣ��ڹ�ʽ������ĸ
        x_pow*=x*x;             //x_pow�Ƿ��������ڱ�ʾ�׳ˣ��ڹ�ʽ������ĸ
        sign=-sign;             //ȷ������Ҫ�ۼӵ���һ��ķ���
        item =x_pow/fact*sign;  //�����Ҫ�ۼӵ���
        sum+=item;              //�������ۼ���ȥ
        n+=2;
    }while(myabs(item)>1e-5);
    return sum;
}

//���涨��mycos����
double mycos(double x)
{
    double sum=1,x_pow=1,item;
    int n=0,fact=1,sign=-1;
    do
    {
        fact=fact*(n+1)*(n+2);
        x_pow*=x*x;
        item =x_pow/fact*sign;
        sum+=item;
        sign=-sign;
        n+=2;
    }while(myabs(item)>0.00001);
    return sum;
}

//���涨��myabs����
double myabs(double x)
{
    return ((x>=0)?x:-x);
}