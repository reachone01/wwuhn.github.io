#include <iostream>  //���ļ��ж������ݣ���ŵ��㶨��Ľṹ������
#include <fstream>
#include <cstdlib>   //��codeblocks�£�exit(1)��Ҫ���ͷ�ļ�
using namespace std;
struct Student
{
    char num[13];  //���ܶ��������ֹ��ɣ�������Ϊ�ַ������ʡ�ѧ��12λ������Ϊ13���ַ������ڴ�����ַ���
    char name[10]; //ÿ������ռ�����ֽڣ��й��˵����֣�5�����ֹ���
    int cpp;
    int math;
    int english;
    int grade;
};
const int N=200;
int main( )
{
    int i, stuNum=0;
    //����ṹ������
    Student stu[N];
 
    //������ļ��ж�ȡ���ݵ��ṹ�����飬�ڶ���Ĺ����м����ܷ�
    ifstream infile("score.txt",ios::in); 	//������ķ�ʽ���ļ�
    if(!infile)   				//�����Ƿ�ɹ���
    {
        cerr<<"open error!"<<endl;
        exit(1);
    }
    i=0;
    while(!infile.eof())
    {
        infile>>stu[i].num>>stu[i].name>>stu[i].cpp>>stu[i].math>>stu[i].english;
        stu[i].grade=stu[i].cpp+stu[i].math+stu[i].english;
        ++stuNum;
        ++i;
    }
    infile.close();
    for(i=0; i<stuNum; ++i)
    {
        cout<<stu[i].num<<"\t"<<stu[i].name<<"\t"<<stu[i].cpp<<"\t"<<stu[i].math<<"\t"<<stu[i].english<<"\t"<<stu[i].grade<<endl;
    }
    while(1);
    return 0;
}