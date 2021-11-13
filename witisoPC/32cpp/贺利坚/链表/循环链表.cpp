#ifndef CLINKLIST_H_INCLUDED
#define CLINKLIST_H_INCLUDED

//ѭ��������������㺯��
typedef int ElemType;
typedef struct LNode        //���嵥����������
{
    ElemType data;
    struct LNode *next;
} CLinkList;

void CreateListF(CLinkList *&L,ElemType a[],int n);//ͷ�巨����ѭ��������
void CreateListR(CLinkList *&L,ElemType a[],int n);//β�巨����ѭ��������
void InitList(CLinkList *&L); //��ʼ������
void DestroyList(CLinkList *&L); //��������
bool ListEmpty(CLinkList *L);  //�ж������Ƿ�Ϊ��
int ListLength(CLinkList *L);  //��������
void DispList(CLinkList *L);  //�������
bool GetElem(CLinkList *L,int i,ElemType &e);  //ȡ����Ԫ��
int LocateElem(CLinkList *L,ElemType e);  //����Ԫ��
bool ListInsert(CLinkList *&L,int i,ElemType e);  //����ڵ�
bool ListDelete(CLinkList *&L,int i,ElemType &e);   //ɾ���ڵ�

#endif // CLINKLIST_H_INCLUDED
//ѭ��������������㺯��
#include <stdio.h>
#include <malloc.h>
//#include "clinklist.h"
void CreateListF(CLinkList *&L,ElemType a[],int n)//ͷ�巨����ѭ��������
{
    CLinkList *s;
    int i;
    L=(CLinkList *)malloc(sizeof(CLinkList));   //����ͷ���
    L->next=NULL;
    for (i=0; i<n; i++)
    {
        s=(CLinkList *)malloc(sizeof(CLinkList));//�����½��
        s->data=a[i];
        s->next=L->next;            //��*s����ԭ��ʼ���֮ǰ,ͷ���֮��
        L->next=s;
    }
    s=L->next;
    while (s->next!=NULL)           //����β���,��sָ����
        s=s->next;
    s->next=L;                      //β���next��ָ��ͷ���

}

void CreateListR(CLinkList *&L,ElemType a[],int n)//β�巨����ѭ��������
{
    CLinkList *s,*r;
    int i;
    L=(CLinkList *)malloc(sizeof(CLinkList));   //����ͷ���
    L->next=NULL;
    r=L;                    //rʼ��ָ���ն˽��,��ʼʱָ��ͷ���
    for (i=0; i<n; i++)
    {
        s=(CLinkList *)malloc(sizeof(CLinkList));//�����½��
        s->data=a[i];
        r->next=s;          //��*s����*r֮��
        r=s;
    }
    r->next=L;              //β���next��ָ��ͷ���
}

void InitList(CLinkList *&L) //��ʼ������
{
    L=(CLinkList *)malloc(sizeof(CLinkList));   //����ͷ���
    L->next=L;
}

void DestroyList(CLinkList *&L) //��������
{
    CLinkList *p=L,*q=p->next;
    while (q!=L)
    {
        free(p);
        p=q;
        q=p->next;
    }
    free(p);
}

bool ListEmpty(CLinkList *L)  //�ж������Ƿ�Ϊ��
{
    return(L->next==L);
}

int ListLength(CLinkList *L)  //��������
{
    CLinkList *p=L;
    int i=0;
    while (p->next!=L)
    {
        i++;
        p=p->next;
    }
    return(i);
}

void DispList(CLinkList *L)  //�������
{
    CLinkList *p=L->next;
    while (p!=L)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

bool GetElem(CLinkList *L,int i,ElemType &e)  //ȡ����Ԫ��
{
    int j=0;
    CLinkList *p;
    if (L->next!=L)     //������Ϊ�ձ�ʱ
    {
        if (i==1)
        {
            e=L->next->data;
            return true;
        }
        else            //i��Ϊ1ʱ
        {
            p=L->next;
            while (j<i-1 && p!=L)
            {
                j++;
                p=p->next;
            }
            if (p==L)
                return false;
            else
            {
                e=p->data;
                return true;
            }
        }
    }
    else                //������Ϊ�ձ�ʱ
        return false;
}

int LocateElem(CLinkList *L,ElemType e)  //����Ԫ��
{
    CLinkList *p=L->next;
    int n=1;
    while (p!=L && p->data!=e)
    {
        p=p->next;
        n++;
    }
    if (p==L)
        return(0);
    else
        return(n);
}

bool ListInsert(CLinkList *&L,int i,ElemType e)  //����ڵ�
{
    int j=0;
    CLinkList *p=L,*s;
    if (p->next==L || i==1)     //ԭ������Ϊ�ձ��i==1ʱ
    {
        s=(CLinkList *)malloc(sizeof(CLinkList));   //�����½��*s
        s->data=e;
        s->next=p->next;        //��*s���뵽*p֮��
        p->next=s;
        return true;
    }
    else
    {
        p=L->next;
        while (j<i-2 && p!=L)
        {
            j++;
            p=p->next;
        }
        if (p==L)               //δ�ҵ���i-1�����
            return false;
        else                    //�ҵ���i-1�����*p
        {
            s=(CLinkList *)malloc(sizeof(CLinkList));   //�����½��*s
            s->data=e;
            s->next=p->next;                        //��*s���뵽*p֮��
            p->next=s;
            return true;
        }
    }
}

bool ListDelete(CLinkList *&L,int i,ElemType &e)   //ɾ���ڵ�
{
    int j=0;
    CLinkList *p=L,*q;
    if (p->next!=L)                 //ԭ������Ϊ�ձ�ʱ
    {
        if (i==1)                   //i==1ʱ
        {
            q=L->next;              //ɾ����1�����
            e=q->data;
            L->next=q->next;
            free(q);
            return true;
        }
        else                        //i��Ϊ1ʱ
        {
            p=L->next;
            while (j<i-2 && p!=L)
            {
                j++;
                p=p->next;
            }
            if (p==L)               //δ�ҵ���i-1�����
                return false;
            else                    //�ҵ���i-1�����*p
            {
                q=p->next;          //qָ��Ҫɾ���Ľ��
                e=q->data;
                p->next=q->next;    //�ӵ�������ɾ��*q���
                free(q);            //�ͷ�*q���
                return true;
            }
        }
    }
    else
        return 0;
}


//#include "clinklist.h"

int main()
{
    CLinkList *A;
    ElemType a[]= {1, 3, 2, 9, 0, 4, 5 ,6, 7, 8};
    InitList(A);
    CreateListF(A, a, 10);
    printf("length: %d\n", ListLength(A));
    ListInsert(A, 4, 12);
    printf("After Insert: ");
    DispList(A);
    DestroyList(A);
    while(1);
    return 0;
}