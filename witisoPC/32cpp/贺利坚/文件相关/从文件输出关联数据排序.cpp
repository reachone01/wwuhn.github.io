/*

*/
#if 1

#include<iostream>
#include<string>
using namespace std;
const int num=8;
int main()
{
    int i,j,t;
    string temp;
    string name[num]= {"zhao","qian","sun","li","zhou","wu","zheng","wang"};
    double score[num]= {79,84,65,89,60,92,78,56};
    //��1�����ɼ�����
    for(j=0; j<num-1; j++)
        for(i=0; i<num-j-1; i++)
        {
            if(score[i]<score[i+1])
            {
                t=score[i];
                score[i]=score[i+1];
                score[i+1]=t;
                temp=name[i];
                name[i]=name[i+1];
                name[i+1]=temp;
            }
        }
        
    cout<<"���ɼ������Ľ����:"<<endl;
    for(i=0; i<num; i++)
        cout<<name[i]<<"\t"<<score[i]<<endl;
    
    //��2������������
    for(j=0; j<num-1; j++)
        for(i=0; i<num-j-1; i++)
        {
            if(name[i]<name[i+1])
            {
                temp=name[i];
                name[i]=name[i+1];
                name[i+1]=temp;
                t=score[i];
                score[i]=score[i+1];
                score[i+1]=t;
            }
        }
    cout<<"��ͬѧ����������н����:"<<endl;
    for(i=0; i<num; i++)
        cout<<name[i]<<"\t"<<score[i]<<endl;
    while(1);
    return 0;
}

#else

#include <fstream>   //�����ļ���д
#include<cstdlib>   //����exit(1)��Ҫ����cstdlib
#include<iostream>
#include<string>
using namespace std;
const int N=100;
int main()
{
    int i,j,t;
    string name[N];
    double score[N];
        int num=0;//ʵ�ʵ�ѧ������
    string temp;
 
    ifstream infile("score.txt",ios::in);
    if(!infile)
    {
        cerr<<"open error!"<<endl;
        exit(1);
}
    while(infile>>name[num]>>score[num])  //�������ļ�β����ѭ�����������
    {
         num++;
    }
    infile.close();
 
    //��1�����ɼ�����
    for(j=0; j<num-1; j++)
        for(i=0; i<num-j-1; i++)
        {
            if(score[i]<score[i+1])
            {
                t=score[i];
                score[i]=score[i+1];
                score[i+1]=t;
                temp=name[i];
                name[i]=name[i+1];
                name[i+1]=temp;
            }
        }
 
    cout<<"���ɼ������Ľ����:"<<endl;
    for(i=0; i<num; i++)
        cout<<name[i]<<"\t"<<score[i]<<endl;
 
    //��2������������
    for(j=0; j<num-1; j++)
        for(i=0; i<num-j-1; i++)
        {
            if(name[i]>name[i+1])
            {
                temp=name[i];
                name[i]=name[i+1];
                name[i+1]=temp;
                t=score[i];
                score[i]=score[i+1];
                score[i+1]=t;
            }
        }
 
    cout<<endl;
    cout<<"��ͬѧ����������н����:"<<endl;
    for(i=0; i<num; i++)
        cout<<name[i]<<"\t"<<score[i]<<endl;
    return 0;
}


#endif

#if 0


#endif
/*

*/