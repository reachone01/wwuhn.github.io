/*

  ����һ��C++��������m��n�������֣��ӵ�m�����n�д��뽫��Ϊע��ʹ�ã�������Щ��ǰ����ϡ�//������
  �³��򱣴浽��һ��.cpp�ļ��У�������Ļ����ʾ������ĳ�����ʾʱ�����кš�
*/

#include <fstream>
#include<iostream>  // ��ʱ�����������ļ�
#include<cstring>
#include<cstdlib>
using namespace std;
void outprogram(const char *filename);
int main( )
{
    char line[256];
    int m,n;
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
    cout<<"��Ҫ����m�п�ʼ��n�д�����Ϊע�ͣ�������m��n��";
    cin>>m>>n;
    int n1=0;
    while(!sourceFile.eof())
    {
        sourceFile.getline(line,255,'\n');
        n1++;
        if(n1>=m&&n1<m+n)
            outFile.put('/').put('/');
        outFile.write(line,strlen(line));
        outFile.write("\n",1);
    }
    outFile.close();
    sourceFile.close();
    cout<<"����������Դ�����ǣ�"<<endl;
    outprogram("newsource.cpp");
    return 0;
}

void outprogram(const char *filename)
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