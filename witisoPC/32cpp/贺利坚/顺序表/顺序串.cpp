#ifndef SqString_H_INCLUDED
#define SqString_H_INCLUDED

#define MaxSize 100             //�����ַ�����
typedef struct
{   
    char data[MaxSize];         //���������MaxSize���ַ��Ŀռ�
    int length;                 //��ǵ�ǰʵ�ʴ���
} SqString;

void StrAssign(SqString &s,char cstr[]);    //�ַ�������cstr������s
void StrCopy(SqString &s,SqString t);       //��t���Ƹ���s
bool StrEqual(SqString s,SqString t);   //�д����
int StrLength(SqString s);              //�󴮳�
SqString Concat(SqString s,SqString t); //������
SqString SubStr(SqString s,int i,int j);//���Ӵ�
SqString InsStr(SqString s1,int i,SqString s2);     //������
SqString DelStr(SqString s,int i,int j) ;           //��ɾȥ
SqString RepStr(SqString s,int i,int j,SqString t); //���滻
void DispStr(SqString s);   //�����

#endif // SqString_H_INCLUDED

#include <stdio.h>
#include <malloc.h>
//#include "SqString.h"

void StrAssign(SqString &s,char cstr[]) //sΪ�����Ͳ���
{   int i;
    for (i=0;cstr[i]!='\0';i++)
        s.data[i]=cstr[i];
    s.length=i;
}
void StrCopy(SqString &s,SqString t)    //sΪ�����Ͳ���
{   int i;
    for (i=0;i<t.length;i++)
        s.data[i]=t.data[i];
    s.length=t.length;
}
bool StrEqual(SqString s,SqString t)
{   bool same=true;
    int i;
    if (s.length!=t.length)             //���Ȳ����ʱ����0
        same=false;
    else
        for (i=0;i<s.length;i++)
            if (s.data[i]!=t.data[i])   //��һ����Ӧ�ַ�����ͬʱ����0
            {   same=false;
                break;
            }
    return same;
}
int StrLength(SqString s)
{
    return s.length;
}
SqString Concat(SqString s,SqString t)
{   SqString str;
    int i;
    str.length=s.length+t.length;
    for (i=0;i<s.length;i++)    //��s.data[0..s.length-1]���Ƶ�str
        str.data[i]=s.data[i];
    for (i=0;i<t.length;i++)    //��t.data[0..t.length-1]���Ƶ�str
        str.data[s.length+i]=t.data[i];
    return str;
}
SqString SubStr(SqString s,int i,int j)
{   SqString str;
    int k;
    str.length=0;
    if (i<=0 || i>s.length || j<0 || i+j-1>s.length)
        return str;                 //��������ȷʱ���ؿմ�
    for (k=i-1;k<i+j-1;k++)         //��s.data[i..i+j]���Ƶ�str
        str.data[k-i+1]=s.data[k];
    str.length=j;
    return str;
}
SqString InsStr(SqString s1,int i,SqString s2)
{   int j;
    SqString str;
    str.length=0;
    if (i<=0 || i>s1.length+1)  //��������ȷʱ���ؿմ�
        return str;
    for (j=0;j<i-1;j++)             //��s1.data[0..i-2]���Ƶ�str
        str.data[j]=s1.data[j];
    for (j=0;j<s2.length;j++)       //��s2.data[0..s2.length-1]���Ƶ�str
        str.data[i+j-1]=s2.data[j];
    for (j=i-1;j<s1.length;j++)     //��s1.data[i-1..s1.length-1]���Ƶ�str
        str.data[s2.length+j]=s1.data[j];
    str.length=s1.length+s2.length;
    return str;
}
SqString DelStr(SqString s,int i,int j)
{   int k;
    SqString str;
    str.length=0;
    if (i<=0 || i>s.length || i+j>s.length+1) //��������ȷʱ���ؿմ�
        return str;
    for (k=0;k<i-1;k++)             //��s.data[0..i-2]���Ƶ�str
        str.data[k]=s.data[k];
    for (k=i+j-1;k<s.length;k++)    //��s.data[i+j-1..s.length-1]���Ƶ�str
        str.data[k-j]=s.data[k];
    str.length=s.length-j;
    return str;
}
SqString RepStr(SqString s,int i,int j,SqString t)
{   int k;
    SqString str;
    str.length=0;
    if (i<=0 || i>s.length || i+j-1>s.length) //��������ȷʱ���ؿմ�
        return str;
    for (k=0;k<i-1;k++)             //��s.data[0..i-2]���Ƶ�str
        str.data[k]=s.data[k];
    for (k=0;k<t.length;k++)        //��t.data[0..t.length-1]���Ƶ�str
        str.data[i+k-1]=t.data[k];
    for (k=i+j-1;k<s.length;k++)    //��s.data[i+j-1..s.length-1]���Ƶ�str
        str.data[t.length+k-j]=s.data[k];
    str.length=s.length-j+t.length;
    return str;
}
void DispStr(SqString s)
{   int i;
    if (s.length>0)
    {   for (i=0;i<s.length;i++)
            printf("%c",s.data[i]);
        printf("\n");
    }
}

#include <stdio.h>
//#include "sqString.h"
int main()
{
    SqString s,s1,s2,s3,s4;
    printf("�����Ļ�����������:\n");
    printf("  (1)������s�ʹ�s1\n");
    StrAssign(s,"abcdefghijklmn");
    printf("  (2)�����s:");
    DispStr(s);
    StrAssign(s1,"123");
    printf("  (2)�����s1:");
    DispStr(s1);
    printf("  (3)��s�ĳ���:%d\n",StrLength(s));
    printf("  (4)�ڴ�s�ĵ�9���ַ�λ�ò��봮s1��������s2\n");
    s2=InsStr(s,9,s1);
    printf("  (5)�����s2:");
    DispStr(s2);
    printf("  (6)ɾ����s��2���ַ���ʼ��5���ַ���������s2\n");
    s2=DelStr(s,2,5);
    printf("  (7)�����s2:");
    DispStr(s2);
    printf("  (8)����s��2���ַ���ʼ��5���ַ��滻�ɴ�s1��������s2\n");
    s2=RepStr(s,2,5,s1);
    printf("  (9)�����s2:");
    DispStr(s2);
    printf("  (10)��ȡ��s�ĵ�2���ַ���ʼ��10���ַ���������s3\n");
    s3=SubStr(s,2,10);
    printf("  (11)�����s3:");
    DispStr(s3);
    printf("  (12)����s1�ʹ�s2����������������s4\n");
    s4=Concat(s1,s2);
    printf("  (13)�����s4:");
    DispStr(s4);
    while(1);
    return 0;
}
