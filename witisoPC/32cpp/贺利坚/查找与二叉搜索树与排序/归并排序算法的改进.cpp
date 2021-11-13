// �鲢�����㷨�ĸĽ�
/*
���ù鲢���򡢿�������ȸ�Ч�㷨�������򣬵�����Ԫ�ؽ���ʱ(��n��64)������ֱ��ʹ��ֱ��
���������㷨�ȸ߸��Ӷȵ��㷨���������������һ���ĺô�������鲢������ٷ��䡢������ʱ
�洢�����Ƶ�Σ�����������ٵݹ��εȡ�
*/

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#define MinLength 64        //��̷ֶγ���
typedef int KeyType;    //����ؼ�������
typedef char InfoType[10];
typedef struct          //��¼����
{
    KeyType key;        //�ؼ�����
    InfoType data;      //����������,����ΪInfoType
} RecType;              //����ļ�¼���Ͷ���

void GetData(RecType *&R, int n)
{
    srand(time(0));
    R=(RecType*)malloc(sizeof(RecType)*n);
    for(int i=0; i<n; i++)
        R[i].key= rand();
    printf("������%d����¼\n", n);
}

//��R[low..high]�������������ֱ�Ӳ�������
void InsertSort(RecType R[],int low,int high)
{
    int i,j;
    RecType tmp;
    for (i=low; i<=high; i++)
    {
        tmp=R[i];
        j=i-1;            //����������������R[low..i-1]����R[i]�Ĳ���λ��
        while (j>=low && tmp.key<R[j].key)
        {
            R[j+1]=R[j]; //���ؼ��ִ���R[i].key�ļ�¼����
            j--;
        }
        R[j+1]=tmp;      //��j+1������R[i]
    }
}

//�ϲ����������
void Merge(RecType R[],int low,int mid,int high)
{
    RecType *R1;
    int i,j,k;
    i=low,j=mid+1,k=0; //k��R1���±�,i��j�ֱ�Ϊ��1��2�ε��±�
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

//һ�˺ϲ�
void MergePass(RecType R[],int length,int n)    //�������������һ�˹鲢
{
    int i;
    for (i=0; i+2*length-1<n; i=i+2*length)     //�鲢length�����������ӱ�
        Merge(R,i,i+length-1,i+2*length-1);
    if (i+length-1<n)                       //���������ӱ�,���߳���С��length
        Merge(R,i,i+length-1,n-1);          //�鲢�������ӱ�
}

//�Ե����ϵĶ�·�鲢�㷨����̫�̵ķֶΣ���ֱ�Ӳ������
void MergeSort(RecType R[],int n)
{
    int length, i;
    for(i=0;i<n;i+=MinLength)   //�Ȱ���̷ֶΣ��ò�������ʹ֮�ֶ�����
        InsertSort(R, i, ((i+MinLength-1<n)?(i+MinLength-1):n));
    for (length=MinLength; length<n; length=2*length) //���й鲢
    {
        MergePass(R,length,n);
    }
}
int main()
{
    int i,n=10000;
    RecType *R;
    GetData(R, n);
    MergeSort(R,n);
    printf("�����ǰ300����:\n");
    i=0;
    while(i<300)
    {
        printf("%12d ",R[i].key);
        i++;
        if(i%5==0)
            printf("\n");
    }
    printf("\n");
    printf("����󣨺�300����:\n");
    i=0;
    while(i<300)
    {
        printf("%12d ",R[n-300+i].key);
        i++;
        if(i%5==0)
            printf("\n");
    }
    printf("\n");
    free(R);
    return 0;
}