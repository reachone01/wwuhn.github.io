#include <fstream>  // Դ�ļ������ŵ���ռһ��
#include<iostream>
//#include<string>
#include<cstdlib>
using namespace std;
void outprogram(char *filename);
int main( )
{
    char ch1,ch2;
    //���ļ��е����ݶ��뵽�ַ�������
    ifstream sourceFile("source.cpp",ios::in);  //������ķ�ʽ���ļ�
    if(!sourceFile)       //�����Ƿ�ɹ���
    {
        cerr<<"source code read error!"<<endl;
        exit(1);
    }
    ofstream outFile("newsource.cpp",ios::out);  //������ķ�ʽ���ļ�
    if(!outFile)       //�����Ƿ�ɹ���
    {
        cerr<<"new source code write error!"<<endl;
        exit(1);
    }
    
    ch1='\0';
    while(!sourceFile.eof())
    {
        sourceFile.get(ch2);
        //�����˻����ţ���ǰһ�����Ų��ǻ��У�Ӧ�ü���һ������
        if((ch2=='{'||ch2=='}')&&(ch1!='\n'))
            outFile.put('\n');
        else
            //��ǰ�����Ĳ��ǻ��У���ǰһ���ǻ����ţ���ʱҲ�ü�
            if((ch1=='{'||ch1=='}')&&(ch2!='\n'))
                outFile.put('\n');
            outFile.put(ch2); //�����ǰ����ķ���
            ch1=ch2;
    }
    outFile.close();
    sourceFile.close();
    cout<<"����������Դ�����ǣ�"<<endl;
    outprogram("newsource.cpp");
    return 0;
}

void outprogram(char *filename)
{
    char line[256];
    int n = 1;
    ifstream inFile(filename, ios::in);  //������ķ�ʽ���ļ�
    if(!inFile)       //�����Ƿ�ɹ���
    {
        cerr<<"file open error!"<<endl;
        exit(1);
    }
    while (!inFile.eof())
    {
        inFile.getline(line,255,'\n');
        cout<<n<<'\t'<<line<<endl;
        n++;
    }
    inFile.close();
    return;
}