#include<iostream>
using namespace std;
int main()
{
    int days=1;
    double m2fs=0, f2ms=0; //�ܶm2f--İ����to����
    double m2f=100000, f2m=0.01; //ÿ��Ӧ������
    while(days<=30)
    {
        m2fs=m2fs+m2f;
        f2ms=f2ms+f2m;
        cout<<"��"<<days<<"�죬İ���˸�������"<<m2fs<<"Ԫ�������̸�İ����"
            <<f2ms<<"Ԫ��"<<endl;
        f2m*=2;
        days++;
    }
    if(m2fs>f2ms)
        cout<<"İ���˳Կ���"<<endl;
    else
        cout<<"�����̳Կ���"<<endl;
    while(1);
    return 0;
}