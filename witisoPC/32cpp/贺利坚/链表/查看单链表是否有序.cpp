#include <stdio.h>
#include <malloc.h>
#include "linklist.h"

bool increase(LinkList *L)
{
    LinkList *p = L->next, *q;      //pָ���1�����ݽڵ�
    if(p != NULL)
    {
        while(p->next != NULL)
        {
            q = p->next;            //q��p�ĺ��
            if (q->data > p->data)  //ֻҪ�ǵ����ģ��ͼ�����������
                p = q;
            else
                return false;       //ֻҪ��һ�����Ǻ�̴���ǰ�����㲻�ǵ���
        }
    }
    return true;
}

int main()
{
    LinkList *A, *B;
    int i;
    ElemType a[]= {1, 3, 2, 9};
    ElemType b[]= {0, 4, 5 ,6, 7, 8};
    InitList(A);
    for(i=3; i>=0; i--)
        ListInsert(A, 1, a[i]);
    InitList(B);
    for(i=5; i>=0; i--)
        ListInsert(B, 1, b[i]);
    printf("A: %c\n", increase(A)?'Y':'N');
    printf("B: %c\n", increase(B)?'Y':'N');
    DestroyList(A);
    DestroyList(B);
    return 0;
}