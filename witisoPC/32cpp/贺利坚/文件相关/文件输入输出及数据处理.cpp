/* ����ͷ��ע�Ϳ�ʼ
* ����İ�Ȩ�Ͱ汾��������       �ļ�������������ݴ���
* Copyright (c) 2011, ��̨��ѧ�����ѧԺѧ��
* All rights reserved.
* �ļ����ƣ�  file.cpp
* ��    �ߣ�     ������
* ������ڣ�  2011  ��   12  ��   4 ��
* �� �� �ţ�    v1.0
* ��������ⷽ������������
* �����������ļ�salary.txt
* �������������ļ�salary.txt�ж���500�����˵Ĺ��ʣ�ȫ������100Ԫ��������򣨺��£��ǹ����ˣ����������Ľ������Ļ������������浽�ļ�ordered_salary.txt��
* ���������ordered_salary.txt
* ����ͷ����ע�ͽ���
*/
//�����ǳ���
#include <fstream>
#include<iostream>
using namespace std;
int main( )
{
    float a[500],t;
    int i,j;
    ifstream infile("salary.txt",ios::in);  //������ķ�ʽ���ļ�
    if(!infile)       //�����Ƿ�ɹ���
    {
        cerr<<"open error!"<<endl;
        exit(1);
    }
    for(i=0;i<500;i++)
        infile>>a[i];   //���ļ��ж�ȡ����
    infile.close();
    for(i=0;i<10;i++)
        a[i]+=100; //�ǹ�����
    //������ð�ݷ�������������
    for(j=0;j<500-2;j++)
        for(i=0;i<500-j-1;i++)
        if (a[i]>a[i+1])
        {
            t=a[i];
            a[i]=a[i+1];
            a[i+1]=t;
        }
    //������
    ofstream outfile("ordered_salary.txt",ios::out);
    if(!outfile)    //�����ļ��򿪲����Ƿ�ɹ������ɹ�����ʾ���˳���
    {
        cerr<<"open error!"<<endl;
        exit(1);
    }
    for(i=0;i<500;i++)
    {
        outfile<<a[i]<<endl;
        if(i%5==0) cout<<endl;
            cout<<a[i]<<"\t";
    }
    outfile.close();     //�ر��ļ��������˱���رգ�����ᶪʧ����
    return 0;
}
