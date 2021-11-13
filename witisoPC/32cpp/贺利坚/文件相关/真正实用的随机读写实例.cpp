#include<iostream>  // ����ʵ�õ������дʵ��
#include <fstream>
#include<cstdlib>
#include<cstring>
using namespace std;

class Student
{
public:
    Student(void) {}
    Student(int n, char nam[20], float s):
    num(n),score(s)
    {
        strcpy(name,nam);
    }
    void setNum(int n)
    {
        num=n;
    }
    void setName(char nam[20])
    {
        strcpy(name,nam);
    }
    void setScore(float s)
    {
        score=s;
    }
    void show()
    {
        cout<<num<<" "<<name<<" "<<score<<endl;    //��ʾͨ��<<������ʵ�ָ���Ȼ
    }
private:
    int num;
    char name[20];
    float score;
};

int main( )
{
    Student stud[5]=
    {
        Student(1001,"Li",85),
            Student(1002,"Fun",97.5),
            Student(1004,"Wang",54),
            Student(1006,"Tan",76.5),
            Student(1010,"ling",96)
    };
    fstream iofile("stud.dat", ios::in|ios::out|ios::binary);
    
    if(!iofile)
    {
        cerr<<"open error!"<<endl;
        abort( );
    }
    
    cout<<"��1��������ļ������ѧ�������ݲ���ʾ����"<<endl;
    int i;
    for(i=0; i<5; i++)
    {
        iofile.write((char *)&stud[i],sizeof(stud[i]));
        stud[i].show();
    }
    
    cout<<"��2���������ļ��еĵ�1,3,5��ѧ�����ݶ�����򣬲���ʾ����"<<endl;
    Student stud1[5];
    for(i=0; i<5; i=i+2)
    {
        iofile.seekg(i*sizeof(stud[i]),ios::beg);
        iofile.read((char *)&stud1[i/2],sizeof(stud1[0]));
        stud1[i/2].show();;
    }
    cout<<endl;
    cout<<"��3�����ڸ�ѧ���������޸ĺ��ش����ļ��е�ԭ��λ��"<<endl;
    stud[2].setNum(1012);
    stud[2].setName("Wu");
    stud[2].setScore(60);
    iofile.seekp(2*sizeof(stud[0]),ios::beg);
    iofile.write((char *)&stud[2],sizeof(stud[2]));
    iofile.seekg(0,ios::beg);
    cout<<"��4���Ӵ����ļ������޸ĺ�ĸ�ѧ�������ݲ���ʾ����"<<endl;
    for(i=0; i<5; i++)
    {
        iofile.read((char *)&stud[i],sizeof(stud[i]));
        stud[i].show();
    }
    iofile.close( );
    while(1);
    return 0;
}