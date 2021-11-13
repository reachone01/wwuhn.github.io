// ת���������ݸ�ʽ(�Զ������ļ�Ϊ�н�)
#include <iostream>
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
const int maxNum = 10000;
void display(Student*, int);
 
 
int main()
{
    ifstream asciiFile("asciidata.txt", ios::in);
    if(!asciiFile)
    {
        cerr<<"cannot open ascii file!"<<endl;
        exit(1);
    }
    int stuNum = 0;
    Student students[maxNum];
 
    //�����ı��ļ�
    while(!asciiFile.eof())
    {
        asciiFile>>students[stuNum].NO;
        asciiFile>>students[stuNum].name;
        asciiFile>>students[stuNum].chinese;
        asciiFile>>students[stuNum].math;
        asciiFile>>students[stuNum].english;
        asciiFile>>students[stuNum].Comprehensive;
        asciiFile>>students[stuNum].total;
        stuNum++;
    }
    asciiFile.close();
    display(students, stuNum);
    //д�뵽�������ļ�
    int i;
    ofstream binaryFile("binarydata.dat", ios::out|ios::binary);
    if(!binaryFile)
    {
        cerr<<"cannot open binary file!"<<endl;
        exit(1);
    }
    binaryFile.write((char*)&stuNum, sizeof(stuNum));
    for(i=0; i<stuNum; ++i)
    {
        binaryFile.write((char*)&students[i], sizeof(Student));
    }
    binaryFile.close();
    while(1);
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