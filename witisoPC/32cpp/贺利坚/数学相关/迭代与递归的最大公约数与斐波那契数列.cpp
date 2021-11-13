#include <iostream>  //gcd��2����2������
using namespace std;
//�Զ��庯����ԭ�ͣ�������������
int gcd(int,int);
int gcds(int,int,int,int);
int fib(int n)
{
    int a,b;
    a = b = 1;
    for(int i=2;i<n;i++)
    {
        int t = a;
        a = b;
        b = t+b;
    }
    return b;
}

int fib5(int n)
{
    int a,b;
    a = b = 1;
    for(int i=2;i<n;i++)
    {
        int c = a + b;
        a = b;
        b = c;
    }
    return b;
}
int fib_3(int n)
{
    int a,b,c;
    a = b = c = 1;
    for(int i=1;i<n;i++)
    {
        a = b;
        b = c;
        c = a + b;
    }
    return b;
}
int fib2(int n)
{
    if(n<3)
        return 1;
    return fib(n-2)+fib(n-1);
}
int main()
{
    for(int i=1;i<20;i++)
        cout<<fib(i)<<endl;

    //cin>>a>>b>>c>>d;
    cout<<"���Լ����: "<<gcd(640,1680)<<endl;
    
    while(1);
    return 0;
}
int gcd3(int a,int b)
{
    return b==0 ? a : gcd(b,a%b);
}
int gcd2(int a,int b) //��շת������������������Լ��
{
    while(int r = a%b)
    {
        a = b;
        b = r;
    }
    return b;
}
int gcd(int a,int b) //��շת������������������Լ��
{
    while(b>0)
    {
        int r=a%b;
        a=b;
        b=r;
    }
    return a;
}
 
int gcds(int x,int y,int z,int w)//����gcd()�����������Լ��
{
    int g1,g2,g;
    g1=gcd(x,y);
    g2=gcd(z,w);
    g=gcd(g1,g2);
    return g;
}