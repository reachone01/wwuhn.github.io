//������ͳ���ļ��еĵ�����
#include <iostream>
#include <fstream>
int wordnum(char str[]);
using namespace std;
int main() 
{
    ifstream sourceFile;
    char ch[100];
    int num_word=0;
    sourceFile.open("a.txt", ios::in);
    if(!sourceFile)             //�����Ƿ�ɹ���  
    {  
        cerr<<"input file open error!"<<endl;  
        exit(1);  
    }  
    
    while (!sourceFile.eof())   //һƪ�����ɶ��й���
    {	
        //ͨ��ѭ����ȡ���У��ۼ�ÿһ�еĵ�����
        sourceFile.getline(ch,100,'\n');   
        num_word+=wordnum(ch); 
    }
    sourceFile.close();
    cout << "�ļ��й���" <<num_word<<"�����ʡ�"<<endl;
    return 0;
}

int wordnum(char str[])
{
    int i,num=0,word=0;  
    for(i=0;(str[i]!='\0');i++)  
    {
        if (str[i]==' ')
            word=0;  //wordΪ0����ǰ������һ���ʣ������ո�Ȼ���Ǵ��ˣ�
        else 
            if (word==0) //�˴�wordΪ0��˵��ǰ��������ǿո񣬶����ڶ������ֲ��ǿո��´ʿ�ʼ
            {
                word=1;
                num++;    //�´ʣ��ʼ���
            }  //�������else�ˣ����Ҫ���޷Ǿ�����word=1����Ϊ����һ���ǿո�ʱ�Ѿ���1�ˣ�����Ҫ�ٸ�ֵ
    }
    return num;
}