//���������ڽ��ļ��еĶ���ո�ȥ�������浽��һ�ļ���
#include <iostream>
#include <fstream>
void alltrim(char *);
using namespace std;
int main() 
{
    ifstream sourceFile;
    ofstream targetFile;
    char str[100];
    int num_char=0, num_line=0;
    int i;
    sourceFile.open("c.txt", ios::in);
    if(!sourceFile)       //�����Ƿ�ɹ���  
    {  
        cerr<<"input file open error!"<<endl;  
        exit(1);  
    }  
    targetFile.open("b.txt", ios::out);
    if(!targetFile)       //�����Ƿ�ɹ���  
    {  
        cerr<<"output file open error!"<<endl;  
        exit(1);  
    }  
    while (!sourceFile.eof())   //һƪ�����ɶ��й���
    {	
        sourceFile.getline(str,100,'\n');   
        alltrim(str);  //ɾȥ����ո�
        //����ɾȥ�ո����ַ�
        i=0;
        while(*(str+i)!='\0')
        {
            targetFile.put(*(str+i));
            ++i;
        }
        targetFile.put('\n');
    }
    sourceFile.close();
    targetFile.close();
    cout<<"������ϣ���鿴�ļ���"<<endl;
    return 0;
}

//������ɾ��ԭ�ļ������ж���ո񲢱��浽��һ�ļ���
void alltrim(char *str)
{
    char *p=str,*q=str;
    bool notSpace=false;
    while(*q==' ')
        q++;
    while(*q!='\0')
    {
        if (*q!=' ') 
        {
            notSpace=true;
            *p++=*q++; // ���ǿո񣬸���   
        }
        else if (notSpace)   //�ǿո񣬵�Ŀǰ�ǵ�һ������Ϊ֮ǰnotSpace=true;�����������ǿո�
        {                
            notSpace=false;   //��һ���ո���ȻҪ����
            *p++=*q++;     
        }
        else   //�����ڶ��������Ŀո���������������һ���ո񲢸��ƺ�notSpace=false;��ԭ�򣬻��ߵ����
        {
            q++;   //������
        }
    }
    *p='\0';
}