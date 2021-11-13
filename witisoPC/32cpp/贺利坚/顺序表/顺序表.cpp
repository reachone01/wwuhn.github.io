#include <stdio.h>
#include <malloc.h>

#define MaxSize 50    //Maxsize�����ں��涨��洢�ռ�Ĵ�С
typedef int ElemType;  //ElemType�ڲ�ͬ���Ͽ��Ը����������Ҫȷ�����ڴ�ȡ�򵥵�int
typedef struct
{
    ElemType data[MaxSize];  //������ǰ��MaxSize��ElemType�Ķ���
    int length;
} SqList;

//�Զ��庯����������
void CreateList(SqList *&L, ElemType a[], int n);//�����鴴�����Ա�
void DispList(SqList *L);//������Ա�DispList(L)
bool ListEmpty(SqList *L);//�ж��Ƿ�Ϊ�ձ�ListEmpty(L)
int ListLength(SqList *L); //�����Ա�ĳ���ListLength(L)
bool GetElem(SqList *L,int i,ElemType &e); //��ĳ������Ԫ��ֵGetElem(L,i,e)
int LocateElem(SqList *L, ElemType e); //��Ԫ��ֵ����LocateElem(L,e)

//ʵ�ֲ��Ժ���
int main()
{
    SqList *sq;
    ElemType x[6]= {5,8,7,2,4,9};
    ElemType a;
    int loc;
    CreateList(sq, x, 6);
    DispList(sq);

    printf("���ȣ�%d\n", ListLength(sq));  //�����󳤶�

    if(GetElem(sq, 3, a))  //�����ڷ�Χ�ڵ�����
        printf("�ҵ��˵�3��Ԫ��ֵΪ��%d\n", a);
    else
        printf("��3��Ԫ�س�����Χ��\n");

    if(GetElem(sq, 15, a))  //���Բ��ڷ�Χ�ڵ�����
        printf("�ҵ��˵�15��Ԫ��ֵΪ��%d\n", a);
    else
        printf("��15��Ԫ�س�����Χ��\n");

    if((loc=LocateElem(sq, 8))>0)  //�������ҵ�������
        printf("�ҵ��ˣ�ֵΪ8��Ԫ���ǵ� %d ��\n", loc);
    else
        printf("ֵΪ8��Ԫ��ľ���ҵ���\n");

    if((loc=LocateElem(sq, 17))>0)  //���Բ����ҵ�������
        printf("�ҵ��ˣ�ֵΪ17��Ԫ���ǵ� %d ��\n", loc);
    else
        printf("ֵΪ17��Ԫ��ľ���ҵ���\n");

    return 0;
}

//����ʵ��Ҫ���Եĸ����Զ��庯��
//�����鴴�����Ա�
void CreateList(SqList *&L, ElemType a[], int n)
{
    int i;
    L=(SqList *)malloc(sizeof(SqList));
    for (i=0; i<n; i++)
        L->data[i]=a[i];
    L->length=n;
}

//������Ա�DispList(L)
void DispList(SqList *L)
{
    int i;
    if (ListEmpty(L))
        return;
    for (i=0; i<L->length; i++)
        printf("%d ",L->data[i]);
    printf("\n");
}

//�ж��Ƿ�Ϊ�ձ�ListEmpty(L)
bool ListEmpty(SqList *L)
{
    return(L->length==0);
}

//�����Ա�ĳ���ListLength(L)
int ListLength(SqList *L)
{
    return(L->length);
}

//��ĳ������Ԫ��ֵGetElem(L,i,e)
bool GetElem(SqList *L,int i,ElemType &e)
{
    if (i<1 || i>L->length)
        return false;
    e=L->data[i-1];
    return true;
}

//��Ԫ��ֵ����LocateElem(L,e)
int LocateElem(SqList *L, ElemType e)
{
    int i=0;
    while (i<L->length && L->data[i]!=e) i++;
    if (i>=L->length)
        return 0;
    else
        return i+1;
}