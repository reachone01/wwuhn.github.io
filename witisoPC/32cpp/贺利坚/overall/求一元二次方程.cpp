#include<iostream> // ��һԪ���η���ʽax^2+bx+c=0�ĸ���a,b,c��ֵ������ʱ�ɼ������롣
#include<cmath>    // �ɿ����öԻ��������ģ��
using namespace std;
int main( )
{
    float  a,b,c,x1,x2;
    cin>>a>>b>>c;
    if ((b*b-4*a*c)>=0)
    {
        if((b*b-4*a*c)>0)
        {
            x1=(-b+sqrt(b*b-4*a*c))/(2*a);
            x2=(-b-sqrt(b*b-4*a*c))/(2*a);
            cout<<"��������ȵ�ʵ���ֱ��ǣ�x1="<<x1<<",""x2="<<x2<<endl;
        }
        else
        {
            x1=-b/(2*a);
            cout<<"������ȵ�ʵ����x1=x2="<<x1<<endl;
        }       
    }
    else
        cout<<"������ʵ��"<<endl;
    return 0;
}