/* ����ͷ��ע�Ϳ�ʼ   ��������Ϣ
* ����İ�Ȩ�Ͱ汾��������
* Copyright (c)2011, ��̨��ѧ�����ѧԺ
* All rightsreserved.
* �ļ����ƣ� interest.cpp
* ��    �ߣ� ������
* ������ڣ�  2011 �� 11 �� 15 ��
* �� �� �ţ�  V1.0

  * ��������ⷽ������������
  * ������������������
  * �����������������ѡ�������࣬�������Ϣ��������Ϣ˰��������ǻ��ڴ���Ҫ����������������Ϣ=���������ʡ����ڣ���λ���꣬����һ�갴360��ƣ���Ҫ��ʹ��switch��䣬����ѡ��Ĵ�����࣬ȷ�����ʺʹ��ں���㡣����ʹ��2011��7��7�չ��������������ʣ�����  0.50%��3����  3.10%��6���� 3.30%��һ�� 3.50%������ 4.40%������ 5.00%������ 5.50%��
  * �����������Ϣ����Ϣ�ϼ�

*/
#include<iostream>
#include<iomanip>
using namespacestd;
int main( )
{
    double money,rate,years,interest;  //ȡ������ı�������ʹ���Լ�����
    int term,days;                  //ÿһ�������ĺ����Ҫ��ȷ
    cout<<setiosflags(ios::fixed)<<setprecision(2);
    cout<<" ���������Ԫ����";
    cin>>money;
    do
    {
        cout<<"  ************************"<<endl;
        cout<<"  1 - һ��"<<endl;     //1,2,3,5�Ͷ���������ϵ�����������û����㣬ֱ��Щ
        cout<<"  2 - ����"<<endl;
        cout<<"  3 - ����"<<endl;
        cout<<"  5 - ����"<<endl;
        cout<<"  0 - ����"<<endl;     //��ͳһ�Ĺ�ʽ���㣬���ؽ������ڷֿ��������û�����
        cout<<"  8 - 3����"<<endl;
        cout<<"  9 - 6����"<<endl;
        cout<<"��ѡ����ڣ�";
        cin>>term;
        if(term<0||term==4||term==6||term==7||term>9) //������Ƿ�ѡ��
        {
            cout<<"������ѡ����ڣ�"<<endl;
            continue;
        }
        else
            break; //term�ǺϷ���ֵ������ȥ������ִ������Ĺ���
    }while(1);
    
    switch(term)  //���ݴ��ڣ�ȷ���ڼ�����Ϣʱ��Ҫ�õ��Ĳ�����ֵ
    {
    case 1:
        rate=0.035; years=1;break;
    case 2:
        rate=0.044; years=2;break;
    case 3:
        rate=0.05; years=3;break;
    case 5:
        rate=0.055; years=5;break;
    case 0:   //����ʱ��Щ�����ԣ���Ҳ�������������������������
        rate=0.005;
        cout<<"����������:";
        cin>>days;
        years=double(days)/360;
        break;
    case 8:   //����3��
        rate=0.031; years=0.25;break;
    case 9:  //����6��
        rate=0.033; years=0.5;break;
    }
    interest=money*rate*years;
    cout<<"����"<<money<<"Ԫ��"<<"��Ϣ"<<interest<<"Ԫ����Ϣ�ϼ�"<<interest+money<<"Ԫ"<<endl;
    return 0;
}