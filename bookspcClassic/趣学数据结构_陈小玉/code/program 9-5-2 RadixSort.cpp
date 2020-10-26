#include<iostream>
#define Maxsize 10000
using namespace std;

int A[Maxsize];
int Maxbit(int A[],int n)//��������������Ԫ��λ��
{
    int maxvalue=A[0],digits=0;//��ʼ�����Ԫ��ΪA[0],���λ��Ϊ0
    for(int i=1;i<n;i++) //�ҵ����������Ԫ��
        if(A[i]>maxvalue)
            maxvalue=A[i];
    while(maxvalue!=0)//�ֽ�õ����Ԫ�ص�λ��
    {
        digits++;
        maxvalue/=10;
    }
    return digits;
}

int Bitnumber(int x,int bit)//��x��bitλ�ϵ����֣�����238��2λ�ϵ�����Ϊ3
{
    int temp=1;
    for(int i=1;i<bit;i++)
        temp*=10;
    return (x/temp)%10;
}

void RadixSort(int A[],int n)//��������
{
    int i,j,k,bit,maxbit;
    maxbit=Maxbit(A,n);//�����Ԫ��λ��
    cout<<maxbit<<endl;
    int **B=new int *[10];
    for(i=0;i<10;i++)
        B[i]=new int[n+1];
    for(i=0;i<10;i++)
        B[i][0]=0;//ͳ�Ƶ�i��Ͱ��Ԫ�ظ���
    //�Ӹ�λ����λ���Բ�ͬ��λ������Ͱ����
    for(bit=1;bit<=maxbit;bit++)
    {
        for(j=0;j<n;j++)//����
        {
            int num=Bitnumber(A[j],bit);//ȡA[j]��bitλ�ϵ�����
            int index=++B[num][0];
            B[num][index]=A[j];
        }
        for(i=0,j=0;i<10;i++)//�ռ�
        {
            for(k=1;k<=B[i][0];k++)
                A[j++]=B[i][k];
            B[i][0]=0;//�ռ���Ԫ�ظ�������
        }
    }
    for(int i=0;i<10;i++)
         delete []B[i];
    delete B;
}
int main()
{
    int n;
    cout<<"�����������е�Ԫ�ظ���nΪ��"<<endl;
    cin>>n;
    cout<<"���������������е�Ԫ�أ�"<<endl;
    for(int i=0;i<n;i++)
       cin>>A[i];
    RadixSort(A,n);
    cout<<"������������"<<endl;
    for(int i=0;i<n;i++)
       cout<<A[i]<<" ";
    cout<<endl;
    return 0;
}
