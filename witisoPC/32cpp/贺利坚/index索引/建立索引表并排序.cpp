#include <iostream>  // ��������������
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
 
 
typedef struct
{
    int NO;
    long offset;  //�������ļ��е�ƫ����
} StudentIndex;   //�߿�ѧ������
 
 
void createIndex();
void writeIndex(StudentIndex *si, int n);
 
 
int main()
{
    createIndex();
    return 0;
}
/*
���ܣ���������
*/
 
 
void createIndex()
{
    int stuNum;
    StudentIndex *studentsIndex;  //���������ʼ��ַ
    Student student;
    ifstream binaryFile("binarydata.dat", ios::in|ios::binary);
    if(!binaryFile)
    {
        cerr<<"cannot open binary file!"<<endl;
        exit(1);
    }
    //��������
    binaryFile.read((char*)&stuNum, sizeof(stuNum));  //����ʵ������
    //�������ݣ�����δ�����������
    studentsIndex = new StudentIndex[stuNum];
    int i, j;
    long mOffset;
    for(i=0; i<stuNum; ++i)
    {
        mOffset = binaryFile.tellg();
        binaryFile.read((char*)&student, sizeof(Student));
        studentsIndex[i].NO = student.NO;
        studentsIndex[i].offset = mOffset;   //��¼��Ӧѧ��ѧ�����ݵ�ƫ����
    }
    //�ر������ļ�
    binaryFile.close();
    //Ϊ����������
    StudentIndex temp;   //���ڽ������м����
    for (i=0; i<stuNum-1; i++)
        for(j=0; j<stuNum-i-1; j++)
            if (studentsIndex[j].NO>studentsIndex[j+1].NO)
            {
                temp=studentsIndex[j];
                studentsIndex[j]=studentsIndex[j+1];
                studentsIndex[j+1]=temp;
            }
    //�����õ�������ͨ���ļ��洢
    writeIndex(studentsIndex, stuNum);
    return;
}
 
 
/*
���ܣ�������д���ļ�
������si - ��������ʼ��ַ��n - ����������������¼����
*/
void writeIndex(StudentIndex *si, int n)
{
    //���ļ�
    ofstream indexFile("binarydata.idx", ios::out|ios::binary);
    if(!indexFile)
    {
        cerr<<"cannot open index file!"<<endl;
        exit(1);
    }
    int i;
    for(i=0; i<n; ++i)
    {
        //indexFile<<si[i].NO<<"\t"<<si[i].offset<<endl;  //���������ı��ļ�ʱ
       indexFile.write((char*)&si[i], sizeof(StudentIndex)); //�����ö������ļ�ʱ  
    }
    //�ر��ļ�
    indexFile.close();
    return;
}