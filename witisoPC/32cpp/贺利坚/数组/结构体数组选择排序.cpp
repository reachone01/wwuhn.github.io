/* ����ͷ��ע�Ϳ�ʼ
* ����İ�Ȩ�Ͱ汾��������   �ṹ������ѡ������
* Copyright(c) 2011, ��̨��ѧ�����ѧԺѧ��
* All rightsreserved.
* �ļ����ƣ�  struct.cpp
* ��    �ߣ�  ������
* ������ڣ�  2011 �� 12 �� 19 ��
* �� �� �ţ�  v1.0

* ��������ⷽ������������
* ����������score.txt����һЩͬѧ��ѧ�š�������C++��������Ӣ��ɼ�������һ��ѧ���ɼ��Ľṹ�����飬
���еĳ�Ա����ѧ�ţ�char num[12]��������(name)�����ſεĳɼ���grade�����ܷ֣�score������
* �������������ļ��ж������ݣ���ŵ��㶨��Ľṹ�������У����ÿ��ͬѧ���ܷ֣����Զ�������С�˳�㡱���㣩
�����ܷ����򣨽��򣩣���������ĳɼ�������30��ͬѧ���Ի�ý�ѧ�𣬹������ָܷ������ȣ�
�йҿƲ��ܵý�ѧ��(��У���������涨��)��������ý�ѧ��ͬѧ��������
*/

#include  <iostream>
#include  <fstream>

using namespace std;
struct Student
{
    char num[13]; //���ܶ��������ֹ��ɣ�������Ϊ�ַ������ʡ�ѧ��12λ������Ϊ13���ַ������ڴ�����ַ���
    char name[10]; //ÿ������ռ�����ֽڣ��й��˵����֣�5�����ֹ���
    int cpp;
    int math;
    int english;
    int grade;
};
const int N = 20;
int main( )
{
    int i, j, k;
    //����ṹ������
    Student stu[N];
    //t_stu������Ϊ����ʱ�����õ���ʱ����
    Student t_stu;
    
    //������ļ��ж�ȡ���ݵ��ṹ�����飬�ڶ���Ĺ����м����ܷ�
    ifstream infile("score.txt",ios::in);       //������ķ�ʽ���ļ�
    if(!infile)                         //�����Ƿ�ɹ���
    {
        cerr<<"openerror!"<<endl;
        exit(1);
    }
    for(i=0;i<N;i++)
    {
        infile>>stu[i].num>>stu[i].name>>stu[i].cpp>>stu[i].math>>stu[i].english;
        stu[i].grade=stu[i].cpp+stu[i].math+stu[i].english;
    }
    infile.close();
    
    //�Խṹ��������н����������������ѡ��������ð������
    for(i=0;i<N-1;i++)
    {
        k=i;
        for(j=i+1;j<N;j++)
            if(stu[j].grade>stu[k].grade)k=j;  //������������ܷ֣���forѭ���ҳ���ǰ�ܷ���ߵ�ѧ�����±�k
        t_stu=stu[k];  //�������ṹ���������ֱ�Ӹ�ֵ����Ȼ���ṹ������Ԫ�ص�ֵ���Ը�ֵ���ṹ�����
        stu[k]=stu[i];
        stu[i]=t_stu;
    }
    
    //���������ĳɼ���
    for(i=0;i<N;i++)
        if(stu[i].grade<=400)
        cout<<stu[i].num<<'\t'<<stu[i].name<<'\t'<<stu[i].cpp<<'\t'<<stu[i].math<<'\t'<<stu[i].english<<'\t'<<stu[i].grade<<endl;
    
    //��������ý�ѧ��ͬѧ������(ò�ƺ���Ľⷨ)
    cout<<"��ϲ����ͬѧ��ý�ѧ�𣨽�ѧ�����ڸ���ѧϰ�������ž���ͳԷ�����"<<endl;
    i=0,j=1;
    while (j<=3)
    {
        if(stu[i].cpp>=60&&stu[i].math>=60&&stu[i].english>=60)
        {
            cout<<j<<'\t'<<stu[i].name<<'\t'<<stu[i].grade<<endl;
            j++;
        }
        i++;
    }
    while(1);
}
/*
struct Student
{
    char num[13]; //���ܶ��������ֹ��ɣ�������Ϊ�ַ������ʡ�ѧ��12λ������Ϊ13���ַ������ڴ�����ַ���
    char name[10]; //ÿ������ռ�����ֽڣ��й��˵����֣�5�����ֹ���
    int cpp;
    int math;
    int english;
    int grade;
};

111 wwu0 65 88 99
112 wwu1 75 68 89
131 wwu2 95 68 79
141 wwu3 65 98 69
115 wwu4 77 66 84
116 wwu5 78 76 55

  */