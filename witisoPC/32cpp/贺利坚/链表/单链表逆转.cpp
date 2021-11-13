#include <stdio.h>
#include <malloc.h>
#include "linklist.h"
void Reverse(LinkList *&L)
{
    LinkList *p=L->next,*q;
    L->next=NULL;
    while (p!=NULL)     //ɨ�����еĽ��
    {
        q=p->next;      //��qָ��*p������һ�����
        p->next=L->next;    //���ǽ�*p�����Ϊ��һ�����ݽ��
        L->next=p;
        p=q;            //��pָ����һ�����
    }
}

int main()
{
    LinkList *L;
    ElemType a[]= {1,3,5,7, 2,4,8,10};
    CreateListR(L,a,8);
    printf("L:");
    DispList(L);
    Reverse(L);
    printf("���ú�L�� ");
    DispList(L);
    DestroyList(L);
    while(1);
    return 0;
}