// ѡ������֮������
// ���⣺https://helijian.blog.csdn.net/article/details/50295637
#include <stdio.h>
#define MaxSize 20
typedef int KeyType;    //����ؼ�������
typedef char InfoType[10];
typedef struct          //��¼����
{
    KeyType key;        //�ؼ�����
    InfoType data;      //����������,����ΪInfoType
} RecType;              //����ļ�¼���Ͷ���

//������
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

//������
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

int main()
{
    int i,n=10;
    RecType R[MaxSize];
    KeyType a[]= {0,6,8,7,9,0,1,3,2,4,5};//a[0]���У�����Ϊ�ؼ���
    for (i=1; i<=n; i++)
        R[i].key=a[i];
    printf("����ǰ:");
    for (i=1; i<=n; i++)
        printf("%d ",R[i].key);
    printf("\n");
    HeapSort(R,n);
    printf("�����:");
    for (i=1; i<=n; i++)
        printf("%d ",R[i].key);
    printf("\n");
    return 0;
}