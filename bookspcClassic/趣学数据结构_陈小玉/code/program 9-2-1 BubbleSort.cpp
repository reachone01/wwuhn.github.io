#include<iostream>
using namespace std;
#define Maxsize 100

void BubbleSort(int r[],int n) //ð������
{
  	int i,j,temp;
  	bool flag;
  	i=n-1;
  	flag=true;
  	while(i>0&&flag)
    {
        flag=false;
        for(j=0;j<i;j++) //����һ������
            if(r[j]>r[j+1])
            {
                flag=true;
                temp=r[j]; //����������¼
                r[j]=r[j+1];
                r[j+1]=temp;
            }
        for(j=0;j<=i;j++)//����ÿ��������
            cout<<r[j]<<" ";
        cout<<endl;
        i--;
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
    BubbleSort(r,n);
    cout<<"ð����������"<<endl;
    for(i=0;i<n;i++)
       cout<<r[i]<<" ";
    return 0;
}
