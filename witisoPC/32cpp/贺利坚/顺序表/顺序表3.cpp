#include <iostream>
using namespace std;


#define MaxSize 50
typedef int ElemType;
typedef struct
{
    ElemType data[MaxSize];
    int length;
} SqList;
void CreateList(SqList *&L, ElemType a[], int n);//�����鴴�����Ա�
void InitList(SqList *&L);//��ʼ�����Ա�InitList(L)
void DestroyList(SqList *&L);//�������Ա�DestroyList(L)
bool ListEmpty(SqList *L);//�ж��Ƿ�Ϊ�ձ�ListEmpty(L)
int ListLength(SqList *L);//�����Ա�ĳ���ListLength(L)
void DispList(SqList *L);//������Ա�DispList(L)
bool GetElem(SqList *L,int i,ElemType &e);//��ĳ������Ԫ��ֵGetElem(L,i,e)
int LocateElem(SqList *L, ElemType e);//��Ԫ��ֵ����LocateElem(L,e)
bool ListInsert(SqList *&L,int i,ElemType e);//��������Ԫ��ListInsert(L,i,e)
bool ListDelete(SqList *&L,int i,ElemType &e);//ɾ������Ԫ��ListDelete(L,i,e)#endif // LIST_H_INCLUDED
void unionList(SqList *LA, SqList *LB, SqList *&LC); // �󼯺ϲ���
void delx2y(SqList *&L, ElemType x,  ElemType y);//ɾ�����Ա��У�Ԫ��ֵ��x��y֮���Ԫ��
void move(SqList *&L);
void delnode(SqList *&L,ElemType x);  //ɾ��Ԫ��
void UnionList(SqList *LA,SqList *LB,SqList *&LC);//�ϲ������

#include <stdio.h>
#include <malloc.h>
//#include "list.h"

//�����鴴�����Ա�
void CreateList(SqList *&L, ElemType a[], int n)
{
    int i;
    L=(SqList *)malloc(sizeof(SqList));
    for (i=0; i<n; i++)
        L->data[i]=a[i];
    L->length=n;
}

//��ʼ�����Ա�InitList(L)
void InitList(SqList *&L)   //������ָ��
{
    L=(SqList *)malloc(sizeof(SqList));
    //���������Ա�Ŀռ�
    L->length=0;
}

//�������Ա�DestroyList(L)
void DestroyList(SqList *&L)
{
    free(L);
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

//������Ա�DispList(L)
void DispList(SqList *L)
{
    int i;
    if (ListEmpty(L)) return;
    for (i=0; i<L->length; i++)
        printf("%d ",L->data[i]);
    printf("\n");
}

//��ĳ������Ԫ��ֵGetElem(L,i,e)
bool GetElem(SqList *L,int i,ElemType &e)
{
    if (i<1 || i>L->length)  return false;
    e=L->data[i-1];
    return true;
}

//��Ԫ��ֵ����LocateElem(L,e)
int LocateElem(SqList *L, ElemType e)
{
    int i=0;
    while (i<L->length && L->data[i]!=e) i++;
    if (i>=L->length)  return 0;
    else  return i+1;
}

//��������Ԫ��ListInsert(L,i,e)
bool ListInsert(SqList *&L,int i,ElemType e)
{
    int j;
    if (i<1 || i>L->length+1)
        return false;   //��������ʱ����false
    i--;            //��˳����߼����ת��Ϊ�������
    for (j=L->length; j>i; j--) //��data[i..n]Ԫ�غ���һ��λ��
        L->data[j]=L->data[j-1];
    L->data[i]=e;           //����Ԫ��e
    L->length++;            //˳�������1
    return true;            //�ɹ����뷵��true
}

//ɾ������Ԫ��ListDelete(L,i,e)
bool ListDelete(SqList *&L,int i,ElemType &e)
{
    int j;
    if (i<1 || i>L->length)  //��������ʱ����false
        return false;
    i--;        //��˳����߼����ת��Ϊ�������
    e=L->data[i];
    for (j=i; j<L->length-1; j++) //��data[i..n-1]Ԫ��ǰ��
        L->data[j]=L->data[j+1];
    L->length--;              //˳����ȼ�1
    return true;              //�ɹ�ɾ������true
}

void unionList(SqList *LA, SqList *LB, SqList *&LC)  //�󼯺ϲ���
{
    int lena,i;
    ElemType e;
    InitList(LC);
    for (i=1; i<=ListLength(LA); i++) //��LA������Ԫ�ز��뵽Lc��
    {
        GetElem(LA,i,e);
        ListInsert(LC,i,e);
    }
    lena=ListLength(LA);         //�����Ա�LA�ĳ���
    for (i=1; i<=ListLength(LB); i++)
    {
        GetElem(LB,i,e);         //ȡLB�е�i������Ԫ�ظ���e
        if (!LocateElem(LA,e)) //LA�в����ں�e��ͬ��,���뵽LC��
            ListInsert(LC,++lena,e);
    }
}
//ɾ�����Ա��У�Ԫ��ֵ��x��y֮���Ԫ��
void delx2y(SqList *&L, ElemType x,  ElemType y)
{
    int k=0,i; //k��¼��x��Ԫ�ظ���
    ElemType t;
    if(x>y)
    {
        t=x;
        x=y;
        y=t;
    }
    for (i=0; i<L->length; i++)
        if (L->data[i]<x || L->data[i]>y )  //���Ʋ���[x, y]֮���Ԫ��
        {
            L->data[k]=L->data[i];
            k++;
        }
    L->length=k;
}
//�ƶ���������������ż������
void move(SqList *&L)
{
    int i=0,j=L->length-1;
    ElemType tmp;
    while (i<j)
    {
        while ((i<j) && (L->data[j]%2==0))  //���������ҵ���һ������(ż���ͺ��Բ���)
            j--;
        while ((i<j) && (L->data[i]%2==1))  //�������ң��ҵ���һ��ż��(�����ͺ��Բ���)
            i++;
        if (i<j)   //���δ����ֽ��ߡ������ұߵ���������ߵ�ż������
        {
            tmp=L->data[i];
            L->data[i]=L->data[j];
            L->data[j]=tmp;
        }
    }   //��ѭ����ȥ�󣬼������ң����ڱ�Ҫʱ����
}
void move1(SqList *&L) //������С������Ԫ���Ƶ���Ԫ�ص�ǰ�棬�����д�������Ԫ���Ƶ���Ԫ�صĺ���
{
    int i=0,j=L->length-1;
    ElemType pivot=L->data[0];  //��data[0]Ϊ��׼
    ElemType tmp;
    while (i<j)             //���������˽������м�ɨ��,ֱ��i=jΪֹ
    {
        while (i<j && L->data[j]>pivot)
            j--;            //��������ɨ��,�ҵ�1��С�ڵ���pivot��Ԫ��
        while (i<j && L->data[i]<=pivot)
            i++;            //��������ɨ��,�ҵ�1������pivot��Ԫ��
        if (i<j)
        {
            tmp=L->data[i]; //L->data[i]��L->data[j]���н���
            L->data[i]=L->data[j];
            L->data[j]=tmp;
        }
    }
    tmp=L->data[0];         //L->data[0]��L->data[j]���н���
    L->data[0]=L->data[j];
    L->data[j]=tmp;
}

void delnode(SqList *&L,ElemType x)  //ɾ��Ԫ��
{
    int k=0,i; //k��¼��x��Ԫ�ظ���
    for (i=0; i<L->length; i++)
        if (L->data[i]!=x)
        {
            L->data[k]=L->data[i];
            k++;
        }
    L->length=k;
}
void UnionList(SqList *LA,SqList *LB,SqList *&LC)//�ϲ������
{
    int i=0,j=0,k=0;    //i��j��k�ֱ���ΪLA��LB��LC���±�
    LC=(SqList *)malloc(sizeof(SqList));
    LC->length=0;
    while (i<LA->length && j<LB->length)
    {
        if (LA->data[i]<LB->data[j])
        {
            LC->data[k]=LA->data[i];
            i++;
            k++;
        }
        else                //LA->data[i]>LB->data[j]
        {
            LC->data[k]=LB->data[j];
            j++;
            k++;
        }
    }
    while (i<LA->length)    //LA��δɨ����,������Ԫ�ز���LC��
    {
        LC->data[k]=LA->data[i];
        i++;
        k++;
    }
    while (j<LB->length)  //LB��δɨ����,������Ԫ�ز���LC��
    {
        LC->data[k]=LB->data[j];
        j++;
        k++;
    }
    LC->length=k;
}

//#include "list.h"
int main()
{
    SqList *sq_1;
    ElemType x[6]= {5,8,7,2,4,9};
    CreateList(sq_1, x, 6);
    DispList(sq_1);

    SqList *sq_a, *sq_b, *sq_c;
    ElemType a[6]= {5,8,7,2,4,9};
    CreateList(sq_a, a, 6);
    printf("LA: ");
    DispList(sq_a);

    ElemType b[6]= {2,3,8,6,0};
    CreateList(sq_b, b, 5);
    printf("LB: ");
    DispList(sq_b);
    unionList(sq_a, sq_b, sq_c);
    printf("LC: ");
    DispList(sq_c);


    SqList *sq;
    ElemType arr[]= {5,8,7,0,2,4,9,6,7,3,55,12,44,66,36,25,11,88,20};
    CreateList(sq, arr, sizeof(arr)/sizeof*arr);
    printf("ɾ��ǰ ");
    DispList(sq);

    delx2y(sq, 4, 7);

    printf("ɾ���� ");
    DispList(sq);

    move(sq);

    printf("�ƶ���������������ż������\n");
    DispList(sq);
    printf("ɾ��ǰ ");
    DispList(sq);

    delnode(sq, 3);

    printf("ɾ���� ");
    DispList(sq);


    printf("�ƶ�ǰ ");
    DispList(sq);

    move1(sq);

    printf("�ƶ��� ");
    DispList(sq);

   SqList *L1,*L2,*L3;
    ElemType aa[]= {1,3,5};
    ElemType bb[]= {2,4,8,10};
    CreateList(L1,aa,3);
    printf("L1:");
    DispList(L1);
    CreateList(L2,bb,4);
    printf("L2:");
    DispList(L2);
    printf("�鲢\n");
    UnionList(L1,L2,L3);
    printf("L3:");
    DispList(L3);
    DestroyList(L1);
    DestroyList(L2);
    DestroyList(L3);
    while(1);
    return 0;
}