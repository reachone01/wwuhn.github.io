// ���Ա��˳�����

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

int SeqSearch(SeqList R,int n,KeyType k)
{
    int i=0;
    while (i<n && R[i].key!=k)      //�ӱ�ͷ������
        i++;
    if (i>=n)
        return 0;
    else
        return i+1;
}
int main()
{
    int i,n=10;
    int result;
    SeqList R;
    KeyType a[]= {2,3,1,8,5,4,9,0,7,6},x=9;
    for (i=0; i<n; i++)
        R[i].key=a[i];
    result = SeqSearch(R,n,x);
    if(result>0)
        printf("�����е� %d ���� %d\n",result, x);
    else
        printf("ľ���ҵ���\n");
    return 0;
}

