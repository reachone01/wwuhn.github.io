/* ����ͷ��ע�Ϳ�ʼ
* ����İ�Ȩ�Ͱ汾��������         ��̬����ͳ�Ƴɼ�
* Copyright(c) 2011, ��̨��ѧ�����ѧԺѧ��
* All rightsreserved.
* �ļ����ƣ�  link.cpp                           
* ��    �ߣ�  ������                           
* ������ڣ�  2011 �� 12 �� 19 ��
* �� �� �ţ�  v1.0       

  * ��������ⷽ������������
  * ����������score.txt
  * �����������ڳ����н���һ����̬����ÿ����һ��ͬѧ�����ݣ������ܷ֣�������Ĵ洢�ռ䲢��ֵ��
  ��������ǰ�������Ĺ�ϵ���ڽ��������ͬʱ��Ҫ����ͳ�ƣ��Ա����������ͬѧ�ֵܷ�ƽ���ɼ���
  ��̬�������󣬴�ͷ��㿪ʼ��������������ָܷ���ƽ���ܷ���û�йҿƵ�ͬѧ��ѧ�š��������ܷ֡�
  * ��������������ָܷ���ƽ���ܷ���û�йҿƵ�ͬѧ��ѧ�š��������ܷ֡�
*/
#include  <iostream>
#include  <fstream>
using namespace std;
struct Student
{
    char num[13];   //���ܶ��������ֹ��ɣ�������Ϊ�ַ������ʡ�
    char name[10];  //ÿ������ռ�����ֽڣ��й��˵����֣�5�����ֹ���
    int cpp;
    int math;
    int english;
    int grade;
    struct Student *next;   //ָ����һ�ڵ��ָ��
};
const int N=20;

int main( )
{
    Student *head=NULL,*p,*q;
    int i;
    int sum=0,ave;                          //������ƽ��
    ifstream infile("score.txt",ios::in);   //������ķ�ʽ���ļ�
    if(!infile)                             //�����Ƿ�ɹ���
    {
        cerr<<"open error!"<<endl;
        exit(1);
    }
    //������ļ��ж�ȡ���ݣ�ͬʱ������̬������Ϊ���ܷ�֮��
    for(i=0;i<N;i++)
    {
        p = new Student;
        infile>>p->num>>p->name>>p->cpp>>p->math>>p->english;
        p->grade = p->cpp + p->math +p->english;
        sum+=p->grade;
        p->next=NULL;
        if (i==0)
            head=p;         //�ǵ�һ���ڵ�
        else
            q->next=p;      //��q��¼�ող����Ľ�㣬�������һ������Ҫq��֮������
        q=p;
    }
    infile.close();
    
    //��ƽ���ɼ�
    ave=sum/N;
    cout<<"�ܷ�ƽ��Ϊ��"<<ave<<endl;
    
    //������������ָܷ���ƽ���ܷ���û�йҿƵ�ͬѧ��ѧ�š��������ܷ֡�
    p=head;
    i=1;
    while(p!=NULL)
    {
        if(p->grade>=ave&&p->cpp>=60&&p->math>=60&&p->english>=60)
        {
            cout<<i<<" "<<p->num<<" "<<p->name<<" "<<p->grade<<endl;
            i++;
        }
        p=p->next;
        
    }
    while(1);
    return 0;
}