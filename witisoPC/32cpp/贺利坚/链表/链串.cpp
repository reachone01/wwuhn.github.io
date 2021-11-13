#ifndef LISTRING_H_INCLUDED
#define LISTRING_H_INCLUDED

typedef struct snode
{
    char data;
    struct snode *next;
} LiString;

void StrAssign(LiString *&s,char cstr[]);   //�ַ�������cstr������s
void StrCopy(LiString *&s,LiString *t);     //��t���Ƹ���s
bool StrEqual(LiString *s,LiString *t);     //�д����
int StrLength(LiString *s);                 //�󴮳�
LiString *Concat(LiString *s,LiString *t);  //������
LiString *SubStr(LiString *s,int i,int j);  //���Ӵ�
LiString *InsStr(LiString *s,int i,LiString *t) ;       //������
LiString *DelStr(LiString *s,int i,int j);              //��ɾȥ
LiString *RepStr(LiString *s,int i,int j,LiString *t);  //���滻
void DispStr(LiString *s);                              //�����

#endif // LISTRING_H_INCLUDED
#include <stdio.h>
#include <malloc.h>
//#include "liString.h"

void StrAssign(LiString *&s,char cstr[])    //�ַ�������cstr������s
{
    int i;
    LiString *r,*p;
    s=(LiString *)malloc(sizeof(LiString));
    r=s;                                    //rʼ��ָ��β�ڵ�
    for (i=0;cstr[i]!='\0';i++)
    {   p=(LiString *)malloc(sizeof(LiString));
        p->data=cstr[i];
        r->next=p;r=p;
    }
    r->next=NULL;
}
void StrCopy(LiString *&s,LiString *t)  //��t���Ƹ���s
{
    LiString *p=t->next,*q,*r;
    s=(LiString *)malloc(sizeof(LiString));
    r=s;                //rʼ��ָ��β�ڵ�
    while (p!=NULL)     //��t�����нڵ㸴�Ƶ�s
    {   q=(LiString *)malloc(sizeof(LiString));
        q->data=p->data;
        r->next=q;r=q;
        p=p->next;
    }
    r->next=NULL;
}
bool StrEqual(LiString *s,LiString *t)  //�д����
{
    LiString *p=s->next,*q=t->next;
    while (p!=NULL && q!=NULL && p->data==q->data)
    {   p=p->next;
        q=q->next;
    }
    if (p==NULL && q==NULL)
        return true;
    else
        return false;
}

int StrLength(LiString *s)  //�󴮳�
{
    int i=0;
    LiString *p=s->next;
    while (p!=NULL)
    {   i++;
        p=p->next;
    }
    return i;
}

LiString *Concat(LiString *s,LiString *t)   //������
{
    LiString *str,*p=s->next,*q,*r;
    str=(LiString *)malloc(sizeof(LiString));
    r=str;
    while (p!=NULL)         //��s�����нڵ㸴�Ƶ�str
    {   q=(LiString *)malloc(sizeof(LiString));
        q->data=p->data;
        r->next=q;r=q;
        p=p->next;
    }
    p=t->next;
    while (p!=NULL)         //��t�����нڵ㸴�Ƶ�str
    {   q=(LiString *)malloc(sizeof(LiString));
        q->data=p->data;
        r->next=q;r=q;
        p=p->next;
    }
    r->next=NULL;
    return str;
}

LiString *SubStr(LiString *s,int i,int j)   //���Ӵ�
{
    int k;
    LiString *str,*p=s->next,*q,*r;
    str=(LiString *)malloc(sizeof(LiString));
    str->next=NULL;
    r=str;                      //rָ���½������β�ڵ�
    if (i<=0 || i>StrLength(s) || j<0 || i+j-1>StrLength(s))
        return str;             //��������ȷʱ���ؿմ�
    for (k=0;k<i-1;k++)
        p=p->next;
    for (k=1;k<=j;k++)          //��s�ĵ�i���ڵ㿪ʼ��j���ڵ㸴�Ƶ�str
    {   q=(LiString *)malloc(sizeof(LiString));
        q->data=p->data;
        r->next=q;r=q;
        p=p->next;
    }
    r->next=NULL;
    return str;
}
LiString *InsStr(LiString *s,int i,LiString *t)     //������
{
    int k;
    LiString *str,*p=s->next,*p1=t->next,*q,*r;
    str=(LiString *)malloc(sizeof(LiString));
    str->next=NULL;
    r=str;                              //rָ���½������β�ڵ�
    if (i<=0 || i>StrLength(s)+1)       //��������ȷʱ���ؿմ�
        return str;
    for (k=1;k<i;k++)                   //��s��ǰi���ڵ㸴�Ƶ�str
    {   q=(LiString *)malloc(sizeof(LiString));
        q->data=p->data;
        r->next=q;r=q;
        p=p->next;
    }
    while (p1!=NULL)                    //��t�����нڵ㸴�Ƶ�str
    {   q=(LiString *)malloc(sizeof(LiString));
        q->data=p1->data;
        r->next=q;r=q;
        p1=p1->next;
    }
    while (p!=NULL)                     //��*p�����Ľڵ㸴�Ƶ�str
    {   q=(LiString *)malloc(sizeof(LiString));
        q->data=p->data;
        r->next=q;r=q;
        p=p->next;
    }
    r->next=NULL;
    return str;
}


LiString *DelStr(LiString *s,int i,int j)   //��ɾȥ
{
    int k;
    LiString *str,*p=s->next,*q,*r;
    str=(LiString *)malloc(sizeof(LiString));
    str->next=NULL;
    r=str;                      //rָ���½������β�ڵ�
    if (i<=0 || i>StrLength(s) || j<0 || i+j-1>StrLength(s))
        return str;             //��������ȷʱ���ؿմ�
    for (k=0;k<i-1;k++)         //��s��ǰi-1���ڵ㸴�Ƶ�str
    {   q=(LiString *)malloc(sizeof(LiString));
        q->data=p->data;
        r->next=q;r=q;
        p=p->next;
    }
    for (k=0;k<j;k++)               //��p��next��j���ڵ�
        p=p->next;
    while (p!=NULL)                 //��*p�����Ľڵ㸴�Ƶ�str
    {   q=(LiString *)malloc(sizeof(LiString));
        q->data=p->data;
        r->next=q;r=q;
        p=p->next;
    }
    r->next=NULL;
    return str;
}
LiString *RepStr(LiString *s,int i,int j,LiString *t)   //���滻
{
    int k;
    LiString *str,*p=s->next,*p1=t->next,*q,*r;
    str=(LiString *)malloc(sizeof(LiString));
    str->next=NULL;
    r=str;                          //rָ���½������β�ڵ�
    if (i<=0 || i>StrLength(s) || j<0 || i+j-1>StrLength(s))
        return str;                 //��������ȷʱ���ؿմ�
    for (k=0;k<i-1;k++)             //��s��ǰi-1���ڵ㸴�Ƶ�str
    {   q=(LiString *)malloc(sizeof(LiString));
        q->data=p->data;q->next=NULL;
        r->next=q;r=q;
        p=p->next;
    }
    for (k=0;k<j;k++)               //��p��next��j���ڵ�
        p=p->next;
    while (p1!=NULL)                //��t�����нڵ㸴�Ƶ�str
    {   q=(LiString *)malloc(sizeof(LiString));
        q->data=p1->data;q->next=NULL;
        r->next=q;r=q;
        p1=p1->next;
    }
    while (p!=NULL)                 //��*p�����Ľڵ㸴�Ƶ�str
    {   q=(LiString *)malloc(sizeof(LiString));
        q->data=p->data;q->next=NULL;
        r->next=q;r=q;
        p=p->next;
    }
    r->next=NULL;
    return str;
}
void DispStr(LiString *s)   //�����
{
    LiString *p=s->next;
    while (p!=NULL)
    {   printf("%c",p->data);
        p=p->next;
    }
    printf("\n");
}

#include <stdio.h>
//#include "liString.h"
int main()
{
    LiString *s,*s1,*s2,*s3,*s4;
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
    s2=DelStr(s,2,3);
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
