/* ����ͷ��ע�Ϳ�ʼ            ��ά����ģ��ɨ����Ϸ����
* ����İ�Ȩ�Ͱ汾��������
* Copyright (c) 2011, ��̨��ѧ�����ѧԺѧ��
* All rights reserved.
* �ļ����ƣ�  array.cpp                           
* ��    �ߣ�  ������                           
* ������ڣ�  2011 �� 12 �� 22 ��
* �� ���ţ�  v1.0       

  * ��������ⷽ������������
  * �����������ɳ�������������Ϊ��ʼֵ
  * ��������������
  * �������������
*/
#include  <iostream>
#include <time.h>
using namespace std;

void setdata(int a[8][8]);          //���������
void out(int a[8][8]);              //�������
void outDiagonal(int a[8][8]);      //����Խ���Ԫ�ص�ֵ
void mine(int a[8][8],int x, int y);//����ɨ�ס���Ϸ�Ĺ���������ڸ���
void change(int a[8][8]);           //��Ҫ��ı���ֵ

int main()
{
    int a[8][8],x,y;
    setdata(a);
    out(a); 
    outDiagonal(a);
    cout<<"����һ��λ�ã���2 3:";
    cin>>x>>y;
    mine(a,x,y);
    change(a);
    out(a);
    while(1);
    return 0;
}

void setdata(int a[8][8])
{
    int i,j;
    srand(time(NULL));              //��Ҫ�õ�ǰʱ���������ӡ����Ա�ÿ������ȡ�õ����в�ͬ
    for(i=0;i<8;i++)
        for(j=0;j<8;j++)
            a[i][j]=rand()%50+1;    //�˽�rand()���������Ķ��й�ϵͳ�������ĵ�
        return;
}

void out(int a[8][8])
{
    int i,j;
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
            cout<<a[i][j]<<'\t';
        cout<<endl;
    }
    cout<<endl;
    return;
}

void outDiagonal(int a[8][8])
{
    int i;
    //��������ϵ����¶Խ����ϵ�Ԫ�ص�ֵ
    cout<<"�������ϵ����¶Խ����ϵ�Ԫ�ص�ֵΪ��"<<endl;
    for(i=0;i<8;i++)
        cout<<a[i][i]<<" ";   //����ͬѧ���ڿ�����a[i][j]��ʽ�����鷳�ر���i��j�Ĺ�ϵ
    cout<<endl;
    //��������ϵ����¶Խ����ϵ�Ԫ�ص�ֵ
    cout<<"�����ϵ����¶Խ����ϵ�Ԫ�ص�ֵΪ��"<<endl;
    for(i=0;i<8;i++)
        cout<<a[i][7-i]<<'\t';   // a[i][7-i]��������б�Խǵı�ʾ��
    cout<<endl;
    cout<<endl;
}

void mine(int a[8][8],int x, int y)
{
    int i,j,sum=0;
    cout<<"a["<<x<<"]["<<y<<"]��Χ�����ǣ�"<<endl;
    for (i = x - 1; i <= x +1; i++)
    {
        for (j = y - 1; j<= y + 1; j++)
        {
            if ( (i>= 0) && (i <= 7) && (j >= 0) && (j <= 7)&& !((i == x ) && (j == y))) //��if�е����������������������Ԫ�ء����Ρ�����Ҫѧ�����ּ���˼·����Ҫһ����һһ�о٣���Ҫд���ܶ�if��������
            {
                cout<<a[i][j]<<'\t';
                sum+=a[i][j];
            }
        }
    }
    cout<<"��Щ���ĺ���:"<<sum<<endl<<endl;
}

void change(int a[8][8])
{
    int i,j;
    for(i=1;i<8;i++)
        for(j=0;j<8;j++)
            a[i][j]=a[i-1][j]+a[i-1][(j+1)%8];  //(j+1)%8��ʹj=7ʱ�����ʵ�a[i][0]Ԫ��
        return;
}