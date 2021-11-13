// �򵥵ļ�������

#include <stdio.h>
#include <malloc.h>
#define MaxSize 20
#define MaxNum 100
typedef int KeyType;    //����ؼ�������
typedef char InfoType[10];
typedef struct          //��¼����
{
    KeyType key;        //�ؼ�����
    InfoType data;      //����������,����ΪInfoType
} RecType;          //����ļ�¼���Ͷ���

void CountSort(RecType R[],int n)
{
    int i, j, k;
    int C[MaxNum+1] = {0};  /*���ڼ�����C���������Ԫ�س�ֵΪ0*/
    for(i=0; i<n; i++)
        C[R[i].key]++;    /*���磬R[i].keyΪ6ʱ��C[6]++��C[R[i].key]��R[i].key���ֵĴ���*/
    k=0;
    for(j=0; j<=MaxNum; j++)    /*����ÿһ��j*/
        for(i=1; i<=C[j]; i++)   /*j=R[j].key���ֹ�C[j]�����˼�������Ľ��*/
            R[k++].key=j;
}

int main()
{
    int i,n=10;
    RecType R[MaxSize];
    KeyType a[]= {6,1,12,6,18,1,18,7,0,6};
    for (i=0; i<n; i++)
        R[i].key=a[i];
    printf("����ǰ:");
    for (i=0; i<n; i++)
        printf("%d ",R[i].key);
    printf("\n");
    CountSort(R,n);
    printf("�����:");
    for (i=0; i<n; i++)
        printf("%d ",R[i].key);
    printf("\n");
    return 0;
}