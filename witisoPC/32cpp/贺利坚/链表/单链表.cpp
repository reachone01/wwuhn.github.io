#include <stdio.h>
#include <malloc.h>
typedef int ElemType;
typedef struct LNode        //���嵥����������
{
    ElemType data;
    struct LNode *next;     //ָ���̽��
} LinkList;

void CreateListF(LinkList *&L,ElemType a[],int n);//ͷ�巨����������
void CreateListR(LinkList *&L,ElemType a[],int n);//β�巨����������
void DestroyList(LinkList *&L); //���ٵ�����
void DispList(LinkList *L);  //���������
void CreateOrderedList(LinkList *&L,ElemType a[],int n);  //�����������򣩵ĵ�����

int main()
{
    LinkList *L1, *L2;
    ElemType a[8]= {7, 9, 8, 2, 0, 4, 6, 3};
    CreateListF(L1, a, 8);
    printf("ͷ�巨��������");
    DispList(L1);
    CreateListR(L2, a, 6);
    printf("β�巨��������");
    DispList(L2);
    DestroyList(L1);
    DestroyList(L2);
    while(1);
    return 0;
}

void CreateListF(LinkList *&L,ElemType a[],int n)//ͷ�巨����������
{
    LinkList *s;
    int i;
    L=(LinkList *)malloc(sizeof(LinkList));     //����ͷ���
    L->next=NULL;
    for (i=0; i<n; i++)
    {
        s=(LinkList *)malloc(sizeof(LinkList));//�����½��
        s->data=a[i];
        s->next=L->next;            //��*s����ԭ��ʼ���֮ǰ,ͷ���֮��
        L->next=s;
    }
}
void CreateListR(LinkList *&L,ElemType a[],int n)//β�巨����������
{
    LinkList *s,*r;
    int i;
    L=(LinkList *)malloc(sizeof(LinkList));     //����ͷ���
    L->next=NULL;
    r=L;                    //rʼ��ָ���ն˽��,��ʼʱָ��ͷ���
    for (i=0; i<n; i++)
    {
        s=(LinkList *)malloc(sizeof(LinkList));//�����½��
        s->data=a[i];
        r->next=s;          //��*s����*r֮��
        r=s;
    }
    r->next=NULL;           //�ն˽��next����ΪNULL
}

void DestroyList(LinkList *&L)  //���ٵ�����
{
    LinkList *p=L,*q=p->next;
    while (q!=NULL)
    {
        free(p);
        p=q;
        q=p->next;
    }
    free(p);    //��ʱqΪNULL,pָ��β���,�ͷ���
}

void DispList(LinkList *L)  //���������
{
    LinkList *p=L->next;
    while (p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
void CreateOrderedList(LinkList *&L,ElemType a[],int n)  //�����������򣩵ĵ�����
{
    LinkList *s,*r;
    int i;
    L=(LinkList *)malloc(sizeof(LinkList));     //����ͷ���
    L->next=NULL;
    for (i=0; i<n; i++)
    {
        r=L; //rָ��ͷ���
        s=(LinkList *)malloc(sizeof(LinkList));//�����½��
        s->data=a[i];
        s->next=NULL;
        while(r->next!=NULL && r->next->data < a[i])  //�ҵ������
            r = r->next;
        s->next=r->next; //��*s����*r֮��
        r->next=s;
    }
}