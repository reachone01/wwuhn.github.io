/*

���Ա���۰����
*/
#if 1

#include <stdio.h>
#define MAXL 100
typedef int KeyType;
typedef char InfoType[10];
typedef struct
{
    KeyType key;                    //KeyTypeΪ�ؼ��ֵ���������
    InfoType data;                  //��������
} NodeType;
typedef NodeType SeqList[MAXL];     //˳�������

int BinSearch(SeqList R,int n,KeyType k)
{
    int low=0,high=n-1,mid;
    while (low<=high)
    {
        mid=(low+high)/2;
        if (R[mid].key==k)      //���ҳɹ�����
            return mid+1;
        if (R[mid].key>k)       //������R[low..mid-1]�в���
            high=mid-1;
        else
            low=mid+1;          //������R[mid+1..high]�в���
    }
    return 0;
}

int main()
{
    int i,n=10;
    int result;
    SeqList R;
    KeyType a[]= {1,3,9,12,32,41,45,62,75,77},x=75;
    for (i=0; i<n; i++)
        R[i].key=a[i];
    result = BinSearch(R,n,x);
    if(result>0)
        printf("�����е� %d ���� %d\n",result, x);
    else
        printf("ľ���ҵ���\n");
    printf("\n-End-\n");
    while(1);
    return 0;
}

#else

#include <stdio.h>
#define MAXL 100
typedef int KeyType;
typedef char InfoType[10];
typedef struct
{
    KeyType key;                    //KeyTypeΪ�ؼ��ֵ���������
    InfoType data;                  //��������
} NodeType;
typedef NodeType SeqList[MAXL];     //˳�������

int BinSearch1(SeqList R,int low,int high,KeyType k)
{
    int mid;
    if (low<=high)          //�����������һ��������Ԫ��
    {
        mid=(low+high)/2;  //���м�λ��
        if (R[mid].key==k) //���ҳɹ��������߼����mid+1
            return mid+1;
        if (R[mid].key>k)  //��R[low..mid-1]�еݹ����
            BinSearch1(R,low,mid-1,k);
        else              //��R[mid+1..high]�еݹ����
            BinSearch1(R,mid+1,high,k);
    }
    else
        return 0;
}

int main()
{
    int i,n=10;
    int result;
    SeqList R;
    KeyType a[]= {1,3,9,12,32,41,45,62,75,77},x=75;
    for (i=0; i<n; i++)
        R[i].key=a[i];
    result = BinSearch1(R,0,n-1,x);
    if(result>0)
        printf("�����е� %d ���� %d\n",result, x);
    else
        printf("ľ���ҵ���\n");
    printf("\n-End-\n");
    while(1);
    return 0;
}



#endif

#if 0


#endif
/*
    printf("\nend\n");
    while(1);
*/