#include <iostream> // �ı��ļ���������
#include <fstream>
#include <cstdlib>
 
 
using namespace std;
typedef struct
{
    int NO;
    char name[8];
    int chinese;
    int math;
    int english;
    int Comprehensive;
    int total;
} Student;  //�߿�ѧ����Ϣ
void display(Student*, int);
void sort(Student*, int);
int main()
{
    int stuNum = 0;
    Student *students;
    fstream binaryFile("binarydata.dat", ios::in|ios::out|ios::binary);
    if(!binaryFile)
    {
        cerr<<"cannot open binary file!"<<endl;
        exit(1);
    }
    //���뿼������
    binaryFile.read((char*)&stuNum, sizeof(stuNum));
 
 
    //��������
    students = new Student[stuNum];
    int i;
    for(i=0; i<stuNum; ++i)
    {
        binaryFile.read((char*)&students[i], sizeof(Student));
    }
    display(students, stuNum);
 
 
    //���ֲ����������򣬻����Բ��ҡ��޸ĵȣ�
    sort(students, stuNum);
 
 
    //�鿴�������
    //display(students, stuNum);
    //��������д���ļ�
    binaryFile.seekg(0, ios::beg);
    binaryFile.write((char*)&stuNum, sizeof(stuNum));
    for(i=0; i<stuNum; ++i)
    {
        binaryFile.write((char*)&students[i], sizeof(Student));
    }
    //�ر��ļ�
    binaryFile.close();
 
 
    return 0;
}
 
 
void display(Student *s, int n)
{
    cout<<"��"<<n<<"��������"<<endl;
    int i;
    for(i=0; i<n; ++i)
    {
        cout<<i<<": "<<s[i].NO<<"\t";
        cout<<s[i].name<<"\t";
        cout<<s[i].chinese<<"\t";
        cout<<s[i].math<<"\t";
        cout<<s[i].english<<"\t";
        cout<<s[i].Comprehensive<<"\t";
        cout<<s[i].total<<"\t"<<endl;
    }
}
 
 
void sort(Student *s, int n)
{
    int i, j;
    Student temp;   //���ڽ������м����
    for (i=0; i<n-1; i++)
        for(j=0; j<n-i-1; j++)
            if (s[j].NO>s[j+1].NO)
            {
                temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
            }
    return;
}