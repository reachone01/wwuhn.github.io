#include<iostream>
typedef int Elemtype;//�����Ͷ���Ϊint 
#include"sqstack.h"//�����Զ���ͷ�ļ�,Դ��Ŀ¼����Ϊsqstack.h���ļ�  
using namespace std;

void binaryconversion(int n)
{
    SqStack S;//����һ��ջS
    int e;
    InitStack(S);//��ʼ��ջ
    while(n)
    {
        Push(S,n%2);
        n=n/2;
    }
    while(!Empty(S))//���ջ����
    {
        Pop(S,e);//��ջ
        cout<<e<<"\t";//���ջ��Ԫ��
    }
}

int main()
{
    int n;
    cout<<"������һ������0��ʮ����������"<<endl;
    cin>>n;
    binaryconversion(n);
    return 0;
}
