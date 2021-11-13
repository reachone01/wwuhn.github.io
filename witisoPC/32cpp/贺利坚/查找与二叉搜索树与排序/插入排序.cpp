/*
    printf("\n-End-\n");
    while(1);
    return 0;
*/
#if 1

//��������

#include <stdio.h>
#define MaxSize 20
typedef int KeyType;    //����ؼ�������
typedef char InfoType[10];
typedef struct          //��¼����
{
    KeyType key;        //�ؼ�����
    InfoType data;      //����������,����ΪInfoType
} RecType;              //����ļ�¼���Ͷ���

void InsertSort(RecType R[],int n) //��R[0..n-1]�������������ֱ�Ӳ�������
{
    int i,j;
    RecType tmp;
    for (i=1; i<n; i++)
    {
        tmp=R[i];
        j=i-1;            //����������������R[0..i-1]����R[i]�Ĳ���λ��
        while (j>=0 && tmp.key < R[j].key)
        {
            R[j+1]=R[j]; //���ؼ��ִ���R[i].key�ļ�¼����
            j--;
        }
        R[j+1]=tmp;      //��j+1������R[i]
    }
}

int main()
{
    int i,n=10;
    RecType R[MaxSize];
    KeyType a[]= {9,8,7,6,5,4,3,2,1,0};
    for (i=0; i<n; i++)
        R[i].key=a[i];
    printf("����ǰ:");
    for (i=0; i<n; i++)
        printf("%d ",R[i].key);
    printf("\n");
    InsertSort(R,n);
    printf("�����:");
    for (i=0; i<n; i++)
        printf("%d ",R[i].key);
    printf("\n-End-\n");
    while(1);
    return 0;
}


#endif

#if 0
// ��ʾֱ�Ӳ����������
#include <stdio.h>
#define MaxSize 20
typedef int KeyType;    //����ؼ�������
typedef char InfoType[10];
typedef struct          //��¼����
{
    KeyType key;        //�ؼ�����
    InfoType data;      //����������,����ΪInfoType
} RecType;              //����ļ�¼���Ͷ���

void InsertSort(RecType R[],int n) //��R[0..n-1]�������������ֱ�Ӳ�������
{
    int i,j,k;
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
        printf("i=%d: ",i);
        for (k=0; k<n; k++)
            printf("%d ",R[k].key);
        printf("\n");
    }
}

int main()
{
    int i,n=10;
    RecType R[MaxSize];
    KeyType a[]= {9,8,7,6,5,4,3,2,1,0};
    for (i=0; i<n; i++)
        R[i].key=a[i];
    printf("����ǰ:");
    for (i=0; i<n; i++)
        printf("%d ",R[i].key);
    printf("\n");
    InsertSort(R,n);
    printf("�����:");
    for (i=0; i<n; i++)
        printf("%d ",R[i].key);
    printf("\n");
    return 0;
}
#endif

#if 0
// �۰��������
#include <stdio.h>
#define MaxSize 20
typedef int KeyType;    //����ؼ�������
typedef char InfoType[10];
typedef struct          //��¼����
{
    KeyType key;        //�ؼ�����
    InfoType data;      //����������,����ΪInfoType
} RecType;              //����ļ�¼���Ͷ���

void InsertSort1(RecType R[],int n) //��R[0..n-1]�������������ֱ�Ӳ�������
{
    int i,j,low,high,mid;
    RecType tmp;
    for (i=1; i<n; i++)
    {
        tmp=R[i];
        low=0;
        high=i-1;
        while (low<=high)
        {
            mid=(low+high)/2;
            if (tmp.key<R[mid].key)
                high=mid-1;
            else
                low=mid+1;
        }
        for (j=i-1; j>=high+1; j--)
            R[j+1]=R[j];
        R[high+1]=tmp;
    }
}
int main()
{
    int i,n=10;
    RecType R[MaxSize];
    KeyType a[]= {9,8,7,6,5,4,3,2,1,0};
    for (i=0; i<n; i++)
        R[i].key=a[i];
    printf("����ǰ:");
    for (i=0; i<n; i++)
        printf("%d ",R[i].key);
    printf("\n");
    InsertSort1(R,n);
    printf("�����:");
    for (i=0; i<n; i++)
        printf("%d ",R[i].key);
    printf("\n");
    return 0;
}

#endif
/*
    printf("\n-End-\n");
    while(1);
    return 0;
*/