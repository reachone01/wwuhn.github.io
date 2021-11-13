//�ýṹ������������

#include <iostream>
#include <fstream>
#include <cstdlib>  //��codeblocks�£�exit(1)��Ҫ���ͷ�ļ�
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
//��������
int getData(Student s[]);
void outputData(Student s[],int n);
void sort(Student s[],int n);
void listScholars1(Student s[],int n);
void listScholars2(Student s[],int n);
 
const int N=200;
int main( )
{
    int stuNum;
    //����ṹ������
    Student stu[N];
 
    //��1�����ļ��ж������ݣ���ŵ��㶨��Ľṹ�������У�
    //��2�����ÿ��ͬѧ���ܷ֣������ڶ�������С�˳�㡱���㣩��
    stuNum=getData(stu);
 
    //��3�����ܷ����򣨽��򣩣�����ѡ��������ð������
    sort(stu,stuNum);
 
    //��4����������ĳɼ�����
    outputData(stu,stuNum);
 
    //��5����30��ͬѧ���Ի�ý�ѧ�𣬹������ָܷ������ȣ��йҿƲ��ܵý�ѧ����������Եý�ѧ��ͬѧ��������
    //��������ý�ѧ��ͬѧ������(ò�ƺ���Ľⷨ)
    listScholars1(stu,stuNum);
 
    //������˵��ܷ����30����ͬ����û�йҿƣ���������ѧ���ǲ�����ģ����������ֲ�����һ���⣬�������
    //���Ҫ��ȡ��Ŀ��û�н����������취�����ǩ������Ϊ����Ȥ����չ��
    listScholars2(stu,stuNum);
 
    //��6��ѡ����ͳ�Ƹ��ſμ��ֵܷ�ƽ���ɼ�����ߺ���ͳɼ�����׼ƫ�������� (��һ�㲻���ο��ˣ�������������������)
 
    while(1);
    return 0;
}
 
//���庯��
//��1�����ļ��ж������ݣ���ŵ��㶨��Ľṹ�������У�
//��2�����ÿ��ͬѧ���ܷ֣������ڶ�������С�˳�㡱���㣩��
//����ֵΪѧ������
int getData(Student s[])
{
    ifstream infile("score.txt",ios::in); 	//������ķ�ʽ���ļ�
    if(!infile)   				//�����Ƿ�ɹ���
    {
        cerr<<"open error!"<<endl;
        exit(1);
    }
    int i=0;
    while(!infile.eof())
    {
        infile>>s[i].num>>s[i].name>>s[i].cpp>>s[i].math>>s[i].english;
        s[i].grade=s[i].cpp+s[i].math+s[i].english;
        ++i;
    }
    infile.close();
    return i;  //iΪѧ������
}
 
//��3�����ܷ����򣨽��򣩣�����ѡ������
void sort(Student s[],int n)
{
    int i,j,k;
    Student t_stu;
 
    for(i=0; i<n-1; i++)
    {
        k=i;
        for(j=i+1; j<n; j++)
            if(s[j].grade>s[k].grade) k=j;  //������������ܷ֣���forѭ���ҳ���ǰ�ܷ���ߵ�ѧ�����±�k
        t_stu=s[k];  //�������ṹ���������ֱ�Ӹ�ֵ����Ȼ���ṹ������Ԫ�ص�ֵ���Ը�ֵ���ṹ�����
        s[k]=s[i];
        s[i]=t_stu;
    }
    return;
}
 
//��4������ɼ�����
void outputData(Student s[],int n)
{
    for(int i=0; i<n; ++i)
    {
        cout<<s[i].num<<"\t"<<s[i].name<<"\t"<<s[i].cpp<<"\t"<<s[i].math<<"\t"<<s[i].english<<"\t"<<s[i].grade<<endl;
    }
    return;
}
 
//��5����30��ͬѧ���Ի�ý�ѧ�𣬹������ָܷ������ȣ��йҿƲ��ܵý�ѧ��
void listScholars1(Student s[],int n)
{
    cout<<"��ϲ����ͬѧ��ý�ѧ�𣨽�ѧ�����ڸ���ѧϰ�������ž���ͳԷ�����"<<endl;
    int i=0,j=1;
    while (j<=30&&j<=n)
    {
        if (s[i].cpp>=60&&s[i].math>=60&&s[i].english>=60)
        {
            cout<<j<<'\t'<<s[i].name<<'\t'<<s[i].grade<<endl;
            j++;
        }
        i++;
    }
}
 
//��һ�ֽ�ѧ�����
void listScholars2(Student s[],int n)
{
    cout<<"��ϲ����ͬѧ��ý�ѧ�𣨽�ѧ�����ڸ���ѧϰ�������ž���ͳԷ�����"<<endl;
    int i=0,j=1;
    int g;
    while (j<=30&&j<=n)
    {
        if (s[i].cpp>=60&&s[i].math>=60&&s[i].english>=60)
        {
            cout<<j<<'\t'<<s[i].name<<'\t'<<s[i].grade<<endl;
            g=s[i].grade;
            j++;
        }
        i++;
    }
    while(g==s[i].grade)//�͸ղ���������һ���ܷ���ͬ��ͬѧ���л����ý�ѧ��
    {
        if (s[i].cpp>=60&&s[i].math>=60&&s[i].english>=60)
        {
            cout<<j<<'\t'<<s[i].name<<'\t'<<s[i].grade<<endl;
            j++;
        }
        i++;
    }
}