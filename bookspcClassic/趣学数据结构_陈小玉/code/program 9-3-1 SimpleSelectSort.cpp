#include<iostream>
using namespace std;
#define Maxsize 100

void SimpleSelectSort(int r[],int n) //��ѡ������
{
  	int i,j,k,temp;
  	for(i=0;i<n-1;i++)//n-1������
    {
        k=i;
        for(j=i+1;j<n;j++)//����Сֵ
            if(r[j]<r[k])
                k=j;   //��¼��Сֵ�±�
        if(k!=i)
        {
            temp=r[i];// r[i]��r[k]����
            r[i]=r[k];
            r[k]=temp;
        }
        for(j=0;j<n;j++)//����ÿ��������
            cout<<r[j]<<" ";
        cout<<endl;
    }
}

int main()
{
    int i,n,r[Maxsize];
    cout<<"�����������е�Ԫ�ظ���nΪ��"<<endl;
    cin>>n;
    cout<<"���������������е�Ԫ�أ�"<<endl;
    for(i=0;i<n;i++)
       cin>>r[i];
    SimpleSelectSort(r,n);
    cout<<"��ѡ����������"<<endl;
    for(i=0;i<n;i++)
       cout<<r[i]<<" ";
    return 0;
}
