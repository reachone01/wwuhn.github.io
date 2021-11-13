#ifndef CDLINKLIST_H_INCLUDED
#define CDLINKLIST_H_INCLUDED

//ѭ��˫����������㺯��
typedef int ElemType;
typedef struct DNode        //����˫����������
{
    ElemType data;
    struct DNode *prior;    //ָ��ǰ�����
    struct DNode *next;     //ָ���̽��
} CDLinkList;

void CreateListF(CDLinkList *&L,ElemType a[],int n); //ͷ�巨����ѭ��˫����
void CreateListR(CDLinkList *&L,ElemType a[],int n); //β�巨����ѭ��˫����
void InitList(CDLinkList *&L); //��ʼ��ѭ��˫����
void DestroyList(CDLinkList *&L);  //����
bool ListEmpty(CDLinkList *L); //�ж��Ƿ�Ϊ��
int ListLength(CDLinkList *L); //��������
void DispList(CDLinkList *L);  //�������
bool GetElem(CDLinkList *L,int i,ElemType &e);  //ȡ����Ԫ��
int LocateElem(CDLinkList *L,ElemType e);  //����Ԫ��
bool ListInsert(CDLinkList *&L,int i,ElemType e);  //����ڵ�
bool ListDelete(CDLinkList *&L,int i,ElemType &e);  //ɾ���ڵ�

#endif // CDLINKLIST_H_INCLUDED

//ѭ��˫����������㺯��
#include <stdio.h>
#include <malloc.h>
//#include "cdlinklist.h"
void CreateListF(CDLinkList *&L,ElemType a[],int n) //ͷ�巨����ѭ��˫����
{
    CDLinkList *s;
    int i;
    L=(CDLinkList *)malloc(sizeof(CDLinkList));     //����ͷ���
    L->next=NULL;
    for (i=0; i<n; i++)
    {
        s=(CDLinkList *)malloc(sizeof(CDLinkList));//�����½��
        s->data=a[i];
        s->next=L->next;            //��*s����ԭ��ʼ���֮ǰ,ͷ���֮��
        if (L->next!=NULL) L->next->prior=s;
        L->next=s;
        s->prior=L;
    }
    s=L->next;
    while (s->next!=NULL)           //����β���,��sָ����
        s=s->next;
    s->next=L;                      //β���next��ָ��ͷ���
    L->prior=s;                     //ͷ����prior��ָ��β���

}

void CreateListR(CDLinkList *&L,ElemType a[],int n) //β�巨����ѭ��˫����
{
    CDLinkList *s,*r;
    int i;
    L=(CDLinkList *)malloc(sizeof(CDLinkList));  //����ͷ���
    L->next=NULL;
    r=L;                    //rʼ��ָ��β���,��ʼʱָ��ͷ���
    for (i=0; i<n; i++)
    {
        s=(CDLinkList *)malloc(sizeof(CDLinkList));//�����½��
        s->data=a[i];
        r->next=s;
        s->prior=r; //��*s����*r֮��
        r=s;
    }
    r->next=L;              //β���next��ָ��ͷ���
    L->prior=r;             //ͷ����prior��ָ��β���
}

void InitList(CDLinkList *&L) //��ʼ��ѭ��˫����
{
    L=(CDLinkList *)malloc(sizeof(CDLinkList));     //����ͷ���
    L->prior=L->next=L;
}

void DestroyList(CDLinkList *&L)  //����
{
    CDLinkList *p=L,*q=p->next;
    while (q!=L)
    {
        free(p);
        p=q;
        q=p->next;
    }
    free(p);
}

bool ListEmpty(CDLinkList *L) //�ж��Ƿ�Ϊ��
{
    return(L->next==L);
}
int ListLength(CDLinkList *L) //��������
{
    CDLinkList *p=L;
    int i=0;
    while (p->next!=L)
    {
        i++;
        p=p->next;
    }
    return(i);
}
void DispList(CDLinkList *L)  //�������
{
    CDLinkList *p=L->next;
    while (p!=L)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
bool GetElem(CDLinkList *L,int i,ElemType &e)  //ȡ����Ԫ��
{
    int j=0;
    CDLinkList *p;
    if (L->next!=L)     //˫����Ϊ�ձ�ʱ
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
    else                //˫����Ϊ�ձ�ʱ
        return 0;
}
int LocateElem(CDLinkList *L,ElemType e)  //����Ԫ��
{
    int n=1;
    CDLinkList *p=L->next;
    while (p!=NULL && p->data!=e)
    {
        n++;
        p=p->next;
    }
    if (p==NULL)
        return(0);
    else
        return(n);
}
bool ListInsert(CDLinkList *&L,int i,ElemType e)  //����ڵ�
{
    int j=0;
    CDLinkList *p=L,*s;
    if (p->next==L)                 //ԭ˫����Ϊ�ձ�ʱ
    {
        s=(CDLinkList *)malloc(sizeof(CDLinkList)); //�����½��*s
        s->data=e;
        p->next=s;
        s->next=p;
        p->prior=s;
        s->prior=p;
        return true;
    }
    else if (i==1)                  //ԭ˫����Ϊ�ձ�i=1ʱ
    {
        s=(CDLinkList *)malloc(sizeof(CDLinkList)); //�����½��*s
        s->data=e;
        s->next=p->next;
        p->next=s;  //��*s���뵽*p֮��
        s->next->prior=s;
        s->prior=p;
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
            s=(CDLinkList *)malloc(sizeof(CDLinkList)); //�����½��*s
            s->data=e;
            s->next=p->next;    //��*s���뵽*p֮��
            if (p->next!=NULL) p->next->prior=s;
            s->prior=p;
            p->next=s;
            return true;
        }
    }
}
bool ListDelete(CDLinkList *&L,int i,ElemType &e)  //ɾ���ڵ�
{
    int j=0;
    CDLinkList *p=L,*q;
    if (p->next!=L)                 //ԭ˫����Ϊ�ձ�ʱ
    {
        if (i==1)                   //i==1ʱ
        {
            q=L->next;              //ɾ����1�����
            e=q->data;
            L->next=q->next;
            q->next->prior=L;
            free(q);
            return true;
        }
        else                        //i��Ϊ1ʱ
        {
            p=L->next;
            while (j<i-2 && p!=NULL)
            {
                j++;
                p=p->next;
            }
            if (p==NULL)                //δ�ҵ���i-1�����
                return false;
            else                        //�ҵ���i-1�����*p
            {
                q=p->next;              //qָ��Ҫɾ���Ľ��
                if (q==NULL) return 0;  //�����ڵ�i�����
                e=q->data;
                p->next=q->next;        //�ӵ�������ɾ��*q���
                if (p->next!=NULL) p->next->prior=p;
                free(q);                //�ͷ�*q���
                return true;
            }
        }
    }
    else
        return false;   //ԭ˫����Ϊ�ձ�ʱ
}


int main()
{
    CDLinkList *A;
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