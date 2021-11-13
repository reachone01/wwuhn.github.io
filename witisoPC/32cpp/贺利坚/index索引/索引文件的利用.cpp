//�����ļ�������

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
 
 
typedef struct
{
    int NO;
    long offset;  //�������ļ��е�ƫ����
} StudentIndex;   //�߿�ѧ������
 
 
//Ϊ������������������ȫ�ֱ�����ʾ�����þֲ���������ģ���ͨ�����ô��ݲ������
fstream dataFile, indexFile;
int stuNum, maxNum;
StudentIndex *studentsIndex;  //��������ڵ�ַ
 
 
//��������
void createIndex();
void writeIndex(StudentIndex *si, int n);
void init();
void work();
int chooseInMenu();
void done();
void displayByIndex();
void displayStudent(Student &s);
 
 
int main()
{
    char yn;
    cout<<"��Ҫ�ؽ�������(Y/N)";
    cin>>yn;
    if('Y'==yn||'y'==yn)
        createIndex();
    init();
    work();
    done();
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
 
 
/*
���ܣ���ʼ����Ϊ����ȫ�ֱ�����ó�ֵ
*/
void init()
{
    //��һ���������������ļ�
    dataFile.open("binarydata.dat", ios::in|ios::out|ios::binary);
    if(!dataFile)
    {
        cerr<<"cannot open data file!"<<endl;
        exit(1);
    }
    //���뿼������
    dataFile.read((char*)&stuNum, sizeof(stuNum));  //����ʵ������
    maxNum = stuNum * 1.1;   //�����������10%�Ŀռ䣬�Ա����������ã������ò��ţ�
    studentsIndex = new StudentIndex[maxNum];  //Ϊ���������ռ�
 
 
    //�������ļ��ж�ȡ���ݣ���������������
    //��ҵ�����й����У�����������������Է������ٶ�����
    //���ļ�
    indexFile.open("binarydata.idx", ios::in|ios::binary);
    if(!indexFile)
    {
        cerr<<"cannot open index file!"<<endl;
        exit(1);
    }
    int i;
    for(i=0; i<stuNum; ++i)
    {
        indexFile.read((char*)&studentsIndex[i], sizeof(StudentIndex)); //�����ö������ļ�ʱ
    }
    //�ر��ļ�
    indexFile.close();
    return;
}
 
 
/*
���ܣ����"�ƺ�"����
*/
void work()
{
    int iChoice;   //����ѡ��ϵͳ����
    //����ҵ��
    do
    {
        iChoice = chooseInMenu();  //�Ӳ˵��л�ù��ܴ���
        switch(iChoice)
        {
        case 1:
            displayByIndex();  //��������ʾ
            break;
        case 2:
            out<<"����ƺ���searchStudent()�����뿼�ţ����������ж��ֲ��ң�Ȼ�������ļ��ж�ȡ���ݲ���ʾ"<<endl;
            break;
        case 3:
            cut<<"����ƺ���updateStudent()�����뿼�ţ����������ж��ֲ��ң�������ֵ�����Ҹ��������ļ��е�����"<<endl;
            break;
        case 4:
            cout<<"����ƺ���addStudent()�����뿼��Ϣ�����浽�����ļ�����󣬽��¿�������Ϣ�������������еĺ���λ�ã���ʹ�������������ļ���Ȼͬ��"<<endl;
            break;
        case 5:
            cout<<"�������������ļ�����Ͽ�չ�������ڹ�����̫ʵ���ˣ����������󣬳���ʵ��"<<endl;
            break;
        case 0:
            cout<<"��ӭ������. "<<endl;
        }
    }
    while(iChoice);
    cout<<"ʲôҲû������"<<endl;
 
 
}
 
 
/*
���ܣ���ʾ�˵�����ҵ��Աѡ��
����ֵ���û�ѡ��Ĺ��ܣ���Χ0-9
*/
int chooseInMenu()
{
    int i;
    while(1)
    {
        cout<<endl;
        cout<<"+---------------+"<<endl;
        cout<<"+ 1 ��������ʾ  +"<<endl;
        cout<<"+ 2 ��ѯ����    +"<<endl;
        cout<<"+ 3 ��������    +"<<endl;
        cout<<"+ 4 ���ӿ���    +"<<endl;
        cout<<"+ 5 ���ӿ���    +"<<endl;
        cout<<"+ 0 �˳�        +"<<endl;
        cout<<"+---------------+"<<endl;
        cout<<"���������ָ��:"<<endl;
        cin>>i;
        if(i>=0 && i<=5)
            break;
        else
            cout<<"������ѡ����\n"<<endl;
    }
    return i;
}
 
 
void done()
{
    //�ر������ļ�
    dataFile.close();
    //�����ݽ��й���ɾ�ģ�������ᷢ���仯�����±��浽�ļ���
    writeIndex(studentsIndex, stuNum);
}
 
 
void displayByIndex()
{
    Student stu;
    indexFile.seekg(ios::beg);
    int i;
    long location;
    cout<<"��"<<stuNum<<"��������"<<endl;
    for(i=0; i<stuNum; ++i)
    {
        location = studentsIndex[i].offset;
        dataFile.seekg(location, ios::beg);
        dataFile.read((char*)&stu, sizeof(Student));
        cout<<i<<": ";
        displayStudent(stu);
    }
}
 
 
void displayStudent(Student &s)
{
    cout<<s.NO<<"\t";
    cout<<s.name<<"\t";
    cout<<s.chinese<<"\t";
    cout<<s.math<<"\t";
    cout<<s.english<<"\t";
    cout<<s.Comprehensive<<"\t";
    cout<<s.total<<"\t"<<endl;
}