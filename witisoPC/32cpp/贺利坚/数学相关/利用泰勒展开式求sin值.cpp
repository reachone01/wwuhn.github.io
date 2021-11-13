#include <iostream>
using namespace std;

const double pi=3.1415926;
double mysin(double x);
double myabs(double x);
int main( )
{
    cout<<"sin(��/2)��ֵΪ"<<mysin(pi/2)<<endl;
    cout<<"sin(56��)��ֵΪ"<<mysin((56.0/180)*pi)<<endl;
    while(1);
    return 0;
}
//���涨��mysin��������sinֵ            ����̩��չ��ʽ��sinֵ
double mysin(double x)
{
    double sum=x,x_pow=x,item;
    int n=1,fact=1,sign=1;     //�������ʱ����ֵ���Ѿ�����һ��ǵ��ۼӺ�sum��
    do
    {
        fact=fact*(n+1)*(n+2);  //fact���ڱ�ʾ�׳ˣ��ڹ�ʽ������ĸ
        x_pow*=x*x;             //x_pow�Ƿ��������ڱ�ʾ�׳ˣ��ڹ�ʽ������ĸ
        sign=-sign;             //ȷ������Ҫ�ۼӵ���һ��ķ���
        item =x_pow/fact*sign;  //�����Ҫ�ۼӵ���
        sum+=item;              //�������ۼ���ȥ
        n+=2;
    }while(myabs(item)>1e-6);
    return sum;
}

//���涨��myabs����
double myabs(double x)
{
    return ((x>=0)?x:-x);
}