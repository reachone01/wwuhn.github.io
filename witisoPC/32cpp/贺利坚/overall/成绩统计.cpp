/* ����ͷ��ע�Ϳ�ʼ             �ɼ�ͳ��
* ����İ�Ȩ�Ͱ汾��������
* Copyright (c) 2011, ��̨��ѧ�����ѧԺѧ��
* All rights reserved.
* �ļ����ƣ� fun.cpp                            
* ��    �ߣ� ������                           
* ������ڣ� 2011 �� 11 �� 29 ��
* �汾�ţ� v1.2       

  * ��������ⷽ������������
  * ����������ѧ�������ͳɼ�
  * ����������(����������ļ�Ӧ��) ������score�н�Ҫ�洢ĳС��C++������Ƶĳɼ���
  �����������湦�ܺ���������������ϳ�һ��������Ӧ�ã�
  ��1������С���������ɼ���
  ��2�������С�����߳ɼ�����ͳɼ���ƽ���ɼ��ͳɼ��ı�׼ƫ�
  ��3�����������߳ɼ�����ͳɼ���ͬѧ����������Ӧ��ѧ�ţ���ɼ���Ӧ���±꼴ѧ�ţ�
  ��������ͬ�ĳɼ���
  * ���������С�����߳ɼ�����ͳɼ���ƽ���ɼ��ͳɼ��ı�׼ƫ�
  ��߳ɼ�����ͳɼ���ͬѧ����������Ӧ��ѧ��
  * ����ͷ����ע�ͽ���
*/
#include <iostream>
#include<Cmath>
using namespace std;
//����������У��ɼ��������Ǻ������ݣ��ʺ���Ϊȫ�ֱ�������
int score[50];      //��score��Ϊȫ�ֱ������ڸ��������п���ֱ��ʹ��
int num;            //С������Ҳ��Ϊȫ�ֱ���
void input_score();
int get_max_score();
int get_min_score();
double get_avg_score();
double get_stdev_score();
int count(int);
void output_index(int);

int main(void)
{
    int max_score,min_score;
    cout<<"С�鹲�ж�����ͬѧ?";
    cin>>num;
    cout<<endl<<"������ѧ���ɼ���"<<endl;
    input_score();  //Ҫ��ɼ���0-100֮��
    max_score=get_max_score();
    cout<<endl<<"��߳ɼ�Ϊ��"<<max_score<<"������"<<count(max_score )<<" �ˡ�";
    min_score=get_min_score();
    cout<<endl<<"��ͳɼ�Ϊ��"<<min_score<<"������"<<count(min_score )<<" �ˡ�";
    cout<<endl<<"ƽ���ɼ�Ϊ��"<<get_avg_score();
    cout<<endl<<"��׼ƫ��Ϊ��"<<get_stdev_score();
    cout<<endl<<"����߳ɼ���ѧ��(ѧ��)�У�";
    output_index(max_score);
    cout<<endl<<"����ͳɼ���ѧ��(ѧ��)�У�";
    output_index(min_score);  
    system("PAUSE");
    return 0;
}

// input_score�����ṩ��ͬѧ�ǲο�
// input_score�����Ĺ���������С���Ա�ĳɼ�
void input_score()
{
    int i;
    for(i=0;i<num;i++)
        do
        {
            cout<<"�����"<<i<<" λͬѧ�ĳɼ���";
            cin>>score[i];
        }while(score[i]<0 ||score[i]>100);
        return;
}

// get_max_score()�����Ĺ��������num��ͬѧ����߳ɼ�
int get_max_score()
{
    int max = -1;
    int i;
    for(i=0;i<num;i++)
        if(max<score[i]) 
            max= score[i];
        return max;
}

// get_min_score()�����Ĺ��������num��ͬѧ����ͳɼ�
int get_min_score()
{
    int min = 999;
    int i;
    for(i=0;i<num;i++)
        if(min>score[i]) 
            min= score[i];
        return min;
}

// get_avg_score()�����Ĺ��������num��ͬѧ��ƽ���ɼ�
double get_avg_score()
{
    double sum = 0;
    int i;
    for(i=0;i<num;i++)
        sum+=score[i];
    return sum/num;
}

// get_ stdev _score()�����Ĺ��������num��ͬѧ�ɼ��ı�׼ƫ��
double get_stdev_score()
{
    double sum = 0,mean_score, x;
    int i;
    mean_score =get_avg_score();  //�˴�ͨ�����ú������ֵ����ắ��������
    for(i=0;i<num;i++)
        x=score[i]-mean_score;
    sum+=x*x;
    return sqrt(sum/(num-1));
}

// count(int s)�����Ĺ����Ƿ���ֵscore������Ϊs��Ԫ�صĸ���
int count(int s)
{
    int iCount=0;
    int i;
    for(i=0;i<num;i++)
        if(score[i]==s)
            iCount++;
        return iCount;
}

// output_index�����Ĺ��������score������ֵΪs��Ԫ�ص��±�(index)
//ע�⣺ֵΪs��Ԫ�ؿ����ж��
void output_index(int s)
{
    int i;
    for(i=0;i<num;i++)
        if(score[i]==s)
            cout<<i<<" ";
        return;
}