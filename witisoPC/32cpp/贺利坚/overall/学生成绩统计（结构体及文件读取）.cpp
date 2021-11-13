#include <iostream>
#include <fstream>  // ѧ���ɼ�ͳ�ƣ��ṹ�弰�ļ���ȡ��
#include <cstdlib>  //��codeblocks�£�exit(1)��Ҫ���ͷ�ļ�
using namespace std;
struct Student
{
    char num[13];
    char name[10];
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
    //��1�����ļ��ж������ݣ���ŵ��ṹ�������У�
    //��2�����ÿ��ͬѧ���ܷ֣������ڶ�������С�˳�㡱���㣩��
    stuNum=getData(stu);
    cout<<"���ݶ�ȡ���"<<endl;
    bool go=true;
    int ch;
    while(go)
    {
        cout<<"��ѡ������Ĺ��ܣ�"<<endl;
        cout<<"1. ����ɼ���"<<endl;
        cout<<"2. ���ܷ���������ɼ���"<<endl;
        cout<<"3. �����ý�ѧ���ͬѧ������"<<endl;
        cout<<"4. ���C++������ͬѧ������C++�ɼ�"<<endl;
        cout<<"5. ���������ĳɼ�����ϵͳ�е���������"<<endl;
        cout<<"0. ����"<<endl;
        cout<<"��ѡ��(0-5)��";
        cin>>ch;
        switch(ch)
        {
        case 1:
            outputData(stu,stuNum);
            break;
        case 2:
            sort(stu,stuNum);
            outputData(stu,stuNum);
            break;
        case 3:
            listScholars1(stu,stuNum);
            break;
        case 4:
            cout<<"��������ƺ���ʵ��."<<endl;
            cout<<"�����Լ��ܹ�!"<<endl;
            break;
        case 5:
            cout<<"���������ܶ��ⷽ����������ӡ�ɾ�����ݣ����ֲ�ѯ���� "<<endl;
            cout<<"�뵽��������! "<<endl;
            break;
        case 0:
            go=false;
            break;
        }
        cout<<endl;
    }
    cout<<"�´��ټ���"<<endl;
    return 0;
}

//���ļ��ж�ȡ����
int getData(Student s[])
{
    ifstream infile("score.txt",ios::in); 	//������ķ�ʽ���ļ�
    if(!infile)   				            //�����Ƿ�ɹ���
    {
        cerr<<"open error!"<<endl;
        exit(1);
    }
    int i=0;
    while(infile>>s[i].num>>s[i].name>>s[i].cpp>>s[i].math>>s[i].english)
    {
        s[i].grade=s[i].cpp+s[i].math+s[i].english;
        ++i;
    }
    infile.close();
    return i;  //iΪѧ������
}

//���ܷ����򣨽��򣩣�����ѡ������
void sort(Student s[],int n)
{
    int i,j,k;
    Student t_stu;
    
    for(i=0; i<n-1; i++)
    {
        k=i;
        for(j=i+1; j<n; j++)
            if(s[j].grade>s[k].grade) k=j;
            t_stu=s[k];
            s[k]=s[i];
            s[i]=t_stu;
    }
    return;
}

//����ɼ�����
void outputData(Student s[],int n)
{
    for(int i=0; i<n; ++i)
    {
        cout<<s[i].num<<"\t"<<s[i].name<<"\t"<<s[i].cpp<<"\t"<<s[i].math<<"\t"<<s[i].english<<"\t"<<s[i].grade<<endl;
    }
    cout<<endl;
    return;
}

//����ý�ѧ��ͬѧ������
//��30��ͬѧ���Ի�ý�ѧ�𣬹������ָܷ�������
void listScholars1(Student s[],int n)
{
    sort(s,n);  //��Ӧ���У������ܱ�֤���ܷ����򣬹���Ҫ������
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
    sort(s,n);  //��Ӧ���У������ܱ�֤���ܷ����򣬹���Ҫ������
    cout<<"��ϲ����ͬѧ��ý�ѧ�𣨸Ľ��棡��"<<endl;
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