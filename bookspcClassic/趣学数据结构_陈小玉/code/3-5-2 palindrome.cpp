#include<iostream>          // �����ж�
#include<cstring>
typedef char Elemtype;      // �����Ͷ���Ϊchar 
#include"sqstack.h"         // �����Զ���ͷ�ļ�,Դ��Ŀ¼����Ϊsqstack.h���ļ�   

using namespace std;

bool palindrome(char *str)  // �ж��ַ����Ƿ�Ϊ����
{
    SqStack S;              // ����һ��ջS
    int len,i;
    char e;
    len=strlen(str);        // �����ַ�������
    InitStack(S);           // ��ʼ��ջ
    for(i=0;i<len/2;i++)    // ���ַ���ǰһ��������ջ
        Push(S,str[i]);
    if(len%2==1)            // �ַ�������Ϊ�������������ĵ�
        i++;
    while(!Empty(S))        // ���ջ����
    {
        Pop(S,e);           // ��ջ
        if(e!=str[i])       // �Ƚ�Ԫ���Ƿ����
            return false;
        else
            i++;
    }
    return true;
}

int main()
{
    char str[20];
    cout<<"������һ������С��20���ַ�����"<<endl;
    cin>>str;
    if(palindrome(str))
        cout<<"���ַ����ǻ��ģ�"<<endl;
    else
        cout<<"���ַ������ǻ��ģ�"<<endl;
    return 0;
}
