#include<iostream>
using namespace std;
#define Maxsize 100

void ShellInsert(int r[],int n,int dk)  //ֱ�Ӳ�������
{
 	int i,j;
	for(i=dk+1;i<=n;i++)  //r[i]���������ӱ�
        if(r[i]<r[i-dk]) //r[i]��ǰһ��Ԫ��r[i-dk]�Ƚ�
		{
		    r[0]=r[i];			//r[i]�ݴ浽r[0]�У�r[0]�м����ڵ�����
            for(j=i-dk;j>0&&r[j]>r[0];j-=dk) //�Ӻ���ǰѰ�Ҳ���λ��,������ƣ�ֱ���ҵ�����λ��
				r[j+dk]=r[j];		//r[j]����dkλ
            r[j+dk]=r[0];		//��r[0]���뵽r[j+dk]λ��
		}
}

void ShellSort(int r[],int n,int dt[],int t) //����������dt[0..t-1]��˳���L��t��ϣ������
{
  	for(int k=0;k<t;k++)
    {
        ShellInsert(r,n,dt[k]);	//һ������Ϊdt[k]��ϣ����������
        for(int i=1;i<=n;i++)      //����ÿ��������
            cout<<r[i]<<" ";
        cout<<endl;
    }
}

int main()
{
    int i,n,t,r[Maxsize+1],dt[Maxsize];
    cout<<"�����������е�Ԫ�ظ���nΪ��"<<endl;
    cin>>n;
    cout<<"���������������е�Ԫ�أ�"<<endl;
    for(i=1;i<=n;i++)
       cin>>r[i];
    cout<<"����������������"<<endl;
	cin>>t;
    cout<<"����������������"<<endl;
    for(i=0;i<t;i++)
       cin>>dt[i];
    ShellSort(r,n,dt,t);
    cout<<"ϣ����������"<<endl;
    for(i=1;i<=n;i++)
       cout<<r[i]<<" ";
    return 0;
}
