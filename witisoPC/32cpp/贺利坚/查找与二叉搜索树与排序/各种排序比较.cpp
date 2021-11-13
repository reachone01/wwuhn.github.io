#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

#define MaxSize 50000      //�������ݣ�ȡ5��ֻ���Կ����㷨�������������

//����ķ��ų����ͽṹ����Ի�������
#define Radix 10           //������ȡֵ
#define Digits 10          //�ؼ���λ��

typedef int KeyType;    //����ؼ�������
typedef char InfoType[10];
typedef struct          //��¼����
{
    KeyType key;        //�ؼ�����
    InfoType data;      //����������,����ΪInfoType
} RecType;              //����ļ�¼���Ͷ���

typedef struct node
{
    KeyType data;      //��¼�Ĺؼ��֣�ͬ�㷨�������в��
    struct node *next;
} RadixRecType;

void InsertSort(RecType R[],int n); //ֱ�Ӳ�������
void ShellSort(RecType R[],int n);  //ϣ�������㷨
void BubbleSort(RecType R[],int n); //ð������
void QuickSort(RecType R[],int n);  //��������
void SelectSort(RecType R[],int n); //ֱ��ѡ������
void HeapSort(RecType R[],int n);   //������
void MergeSort(RecType R[],int n);  //�鲢����

//���溯��֧�ֻ�������
void CreateLink(RadixRecType *&p,RecType R[],int n);   //�������������õ�����
void DestoryLink(RadixRecType *&p); //�ͷŻ��������õ�����
void RadixSort(RadixRecType *&p);   //��������


#endif // SORT_H_INCLUDED


#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
//#include "sort.h"

void GetLargeData(RecType *&R, int n)
{
    srand(time(0));
    R=(RecType*)malloc(sizeof(RecType)*n);
    for(int i=0; i<n; i++)
        R[i].key= rand();  //����0~RAND_MAX�����
    printf("������%d����¼\n", n);
}

//����ĳһ�����㷨������򣬷���������ʱ
long Sort(RecType *&R, int n, void f(RecType*, int))
{
    int i;
    long beginTime, endTime;
    RecType *R1=(RecType*)malloc(sizeof(RecType)*n);
    for (i=0;i<n;i++)
        R1[i]=R[i];
    beginTime = time(0);
    f(R1,n);
    endTime = time(0);
    free(R1);
    return endTime-beginTime;
}

//���û��������㷨������򣬷���������ʱ
long Sort1(RecType *&R, int n)
{
    long beginTime, endTime;
    RadixRecType *p;
    CreateLink(p,R,n);
    beginTime = time(0);
    RadixSort(p);
    endTime = time(0);
    DestoryLink(p);
    return endTime-beginTime;
}

int main()
{
    RecType *R;
    int n = MaxSize;   //������, MaxSizeȡ50W
    GetLargeData(R, n);
    printf("�������򻨷�ʱ�䣺\n");
    printf("  ֱ�Ӳ�������%ld\n", Sort(R, n, InsertSort));
    printf("  ϣ������%ld\n", Sort(R, n, ShellSort));
    printf("  ð������%ld\n", Sort(R, n, BubbleSort));
    printf("  ��������%ld\n", Sort(R, n, QuickSort));
    printf("  ֱ��ѡ������%ld\n", Sort(R, n, SelectSort));
    printf("  ������%ld\n", Sort(R, n, HeapSort));
    printf("  �鲢����%ld\n", Sort(R, n, MergeSort));
    printf("  ��������%ld\n", Sort1(R, n));
    free(R);
    return 0;
}

//#include "sort.h"
//#include <malloc.h>

//1. ��R[0..n-1]�������������ֱ�Ӳ�������
void InsertSort(RecType R[],int n)
{
    int i,j;
    RecType tmp;
    for (i=1; i<n; i++)
    {
        tmp=R[i];
        j=i-1;            //����������������R[0..i-1]����R[i]�Ĳ���λ��
        while (j>=0 && tmp.key<R[j].key)
        {
            R[j+1]=R[j]; //���ؼ��ִ���R[i].key�ļ�¼����
            j--;
        }
        R[j+1]=tmp;      //��j+1������R[i]
    }
}


//2. ϣ�������㷨
void ShellSort(RecType R[],int n)
{
    int i,j,gap;
    RecType tmp;
    gap=n/2;                //�����ó�ֵ
    while (gap>0)
    {
        for (i=gap; i<n; i++) //���������gapλ�õ�����Ԫ�����������
        {
            tmp=R[i];
            j=i-gap;
            while (j>=0 && tmp.key<R[j].key)//�����gapλ�õ�Ԫ�����������
            {
                R[j+gap]=R[j];
                j=j-gap;
            }
            R[j+gap]=tmp;
            j=j-gap;
        }
        gap=gap/2;  //��С����
    }
}

//3. ð������
void BubbleSort(RecType R[],int n)
{
    int i,j,exchange;
    RecType tmp;
    for (i=0; i<n-1; i++)
    {
        exchange=0;
        for (j=n-1; j>i; j--)   //�Ƚ�,�ҳ���С�ؼ��ֵļ�¼
            if (R[j].key<R[j-1].key)
            {
                tmp=R[j];  //R[j]��R[j-1]���н���,����С�ؼ��ּ�¼ǰ��
                R[j]=R[j-1];
                R[j-1]=tmp;
                exchange=1;
            }
        if (exchange==0)    //û�н������������㷨
            return;
    }
}

//4. ��R[s]��R[t]��Ԫ�ؽ��п�������
void QuickSortR(RecType R[],int s,int t)
{
    int i=s,j=t;
    RecType tmp;
    if (s<t)                //���������ٴ�������Ԫ�ص����
    {
        tmp=R[s];           //������ĵ�1����¼��Ϊ��׼
        while (i!=j)        //���������˽������м�ɨ��,ֱ��i=jΪֹ
        {
            while (j>i && R[j].key>=tmp.key)
                j--;        //��������ɨ��,�ҵ�1��С��tmp.key��R[j]
            R[i]=R[j];      //�ҵ�������R[j],R[i]"R[j]����
            while (i<j && R[i].key<=tmp.key)
                i++;        //��������ɨ��,�ҵ�1������tmp.key�ļ�¼R[i]
            R[j]=R[i];      //�ҵ�������R[i],R[i]"R[j]����
        }
        R[i]=tmp;
        QuickSortR(R,s,i-1);     //��������ݹ�����
        QuickSortR(R,i+1,t);     //��������ݹ�����
    }
}

//4. ��������������������ͬ�����㷨ͳһ�ӿڣ��ڲ����õݹ�Ŀ�������
void QuickSort(RecType R[],int n)
{
    QuickSortR(R, 0, n-1);
}

//5. ֱ��ѡ������
void SelectSort(RecType R[],int n)
{
    int i,j,k;
    RecType temp;
    for (i=0; i<n-1; i++)           //����i������
    {
        k=i;
        for (j=i+1; j<n; j++)   //�ڵ�ǰ������R[i..n-1]��ѡkey��С��R[k]
            if (R[j].key<R[k].key)
                k=j;            //k����Ŀǰ�ҵ�����С�ؼ������ڵ�λ��
        if (k!=i)               //����R[i]��R[k]
        {
            temp=R[i];
            R[i]=R[k];
            R[k]=temp;
        }
    }
}

//6. ��������֮����������
void sift(RecType R[],int low,int high)
{
    int i=low,j=2*i;                        //R[j]��R[i]������
    RecType temp=R[i];
    while (j<=high)
    {
        if (j<high && R[j].key<R[j+1].key)  //���Һ��ӽϴ�,��jָ���Һ���
            j++;                                //��Ϊ2i+1
        if (temp.key<R[j].key)
        {
            R[i]=R[j];                          //��R[j]������˫�׽��λ����
            i=j;                                //�޸�i��jֵ,�Ա��������ɸѡ
            j=2*i;
        }
        else break;                             //ɸѡ����
    }
    R[i]=temp;                                  //��ɸѡ����ֵ��������λ��
}

//6. ������
void HeapSort(RecType R[],int n)
{
    int i;
    RecType temp;
    for (i=n/2; i>=1; i--) //ѭ��������ʼ��
        sift(R,i,n);
    for (i=n; i>=2; i--) //����n-1��ѭ��,���������
    {
        temp=R[1];       //����һ��Ԫ��ͬ��ǰ������R[1]�Ի�
        R[1]=R[i];
        R[i]=temp;
        sift(R,1,i-1);   //ɸѡR[1]���,�õ�i-1�����Ķ�
    }
}

//7.�鲢������1�����ϲ������
void Merge(RecType R[],int low,int mid,int high)
{
    RecType *R1;
    int i=low,j=mid+1,k=0; //k��R1���±�,i��j�ֱ�Ϊ��1��2�ε��±�
    R1=(RecType *)malloc((high-low+1)*sizeof(RecType));  //��̬����ռ�
    while (i<=mid && j<=high)       //�ڵ�1�κ͵�2�ξ�δɨ����ʱѭ��
        if (R[i].key<=R[j].key)     //����1���еļ�¼����R1��
        {
            R1[k]=R[i];
            i++;
            k++;
        }
        else                            //����2���еļ�¼����R1��
        {
            R1[k]=R[j];
            j++;
            k++;
        }
    while (i<=mid)                      //����1�����²��ָ��Ƶ�R1
    {
        R1[k]=R[i];
        i++;
        k++;
    }
    while (j<=high)                 //����2�����²��ָ��Ƶ�R1
    {
        R1[k]=R[j];
        j++;
        k++;
    }
    for (k=0,i=low; i<=high; k++,i++) //��R1���ƻ�R��
        R[i]=R1[k];
}

//7. �鲢������2����һ�˹鲢
void MergePass(RecType R[],int length,int n)    //�������������һ�˹鲢
{
    int i;
    for (i=0; i+2*length-1<n; i=i+2*length)     //�鲢length�����������ӱ�
        Merge(R,i,i+length-1,i+2*length-1);
    if (i+length-1<n)                       //���������ӱ�,���߳���С��length
        Merge(R,i,i+length-1,n-1);          //�鲢�������ӱ�
}

//7. �鲢����
void MergeSort(RecType R[],int n)           //�Ե����ϵĶ�·�鲢�㷨
{
    int length;
    for (length=1; length<n; length=2*length) //����log2n�˹鲢
        MergePass(R,length,n);
}

//���»�������Ϊ��ͳһ�����и���
//8. ��������ĸ����������������������õ�����
void CreateLink(RadixRecType *&p,RecType R[],int n)   //���ú�巨��������
{
    int i;
    RadixRecType *s,*t;
    for (i=0; i<n; i++)
    {
        s=(RadixRecType *)malloc(sizeof(RadixRecType));
        s->data = R[i].key;
        if (i==0)
        {
            p=s;
            t=s;
        }
        else
        {
            t->next=s;
            t=s;
        }
    }
    t->next=NULL;
}

//8. ��������ĸ����������ͷŻ��������õ�����
void DestoryLink(RadixRecType *&p)
{
    RadixRecType *q;
    while(p!=NULL)
    {
        q=p->next;
        free(p);
        p=q;
    }
    return;
}

//8. ʵ�ֻ�������:*pΪ��������������ָ��,����R�͹ؼ���λ��D�Ѿ���Ϊ���ų��������
void RadixSort(RadixRecType *&p)
{
    RadixRecType *head[Radix],*tail[Radix],*t; //��������ӵ���βָ��
    int i,j,k;
    unsigned int d1, d2=1;   //���ڷ������iλ���֣��������ע��
    for (i=1; i<=Digits; i++)                  //�ӵ�λ����λѭ��
    {
        //�����������iλ���֣���ͨ����d1=10^iȡ�࣬�õ����iλ����ͨ������d2=10^(i-1)�õ���iλ
        //���磬�����������1λ������λ�����ȶ�d1=10ȡ�࣬������d2=1
        //�����磬�����������2λ����ʮλ�����ȶ�d1=100ȡ�࣬������d2=10
        //ѭ��֮ǰ��d2�Ѿ���ʼ��Ϊ1������һ��ѭ��ĩ����10��
        //�������d2���õ�d1��ֵ
        d1=d2*10;
        for (j=0; j<Radix; j++)                 //��ʼ���������ס�βָ��
            head[j]=tail[j]=NULL;
        while (p!=NULL)                 //����ԭ������ÿ�����ѭ��
        {
            k=(p->data%d1)/d2;           //�������iλ����k
            if (head[k]==NULL)          //���з���
            {
                head[k]=p;
                tail[k]=p;
            }
            else
            {
                tail[k]->next=p;
                tail[k]=p;
            }
            p=p->next;                  //ȡ��һ���������Ԫ��
        }
        p=NULL;                         //������p���ռ����н��
        for (j=0; j<Radix; j++)             //����ÿһ������ѭ��
            if (head[j]!=NULL)          //�����ռ�
            {
                if (p==NULL)
                {
                    p=head[j];
                    t=tail[j];
                }
                else
                {
                    t->next=head[j];
                    t=tail[j];
                }
            }
        t->next=NULL;                   //���һ������next����NULL
        //����������ڷ������iλ���ֵ�d2
        d2*=10;
    }
}
