#include<iostream>
using namespace std;
#define Maxsize 100

void StraightInsertSort(int r[],int n)  //ֱ�Ӳ�������
{
 	int i,j;
	for(i=2;i<=n;i++)  //r[i]���������ӱ�
        if(r[i]<r[i-1]) //r[i]��ǰһ��Ԫ��r[i-1]�Ƚ�
        {
            r[0]=r[i];			//r[i]�ݴ浽r[0]�У�r[0]�м����ڵ�����
            r[i]=r[i-1];	    //r[i-1]����һλ
            for(j=i-2;r[j]>r[0];j--) //�Ӻ���ǰѰ�Ҳ���λ��,������ƣ�ֱ���ҵ�����λ��
                r[j+1]=r[j];		//r[j]����һλ
            r[j+1]=r[0];		//��r[0]���뵽r[j+1]λ��
        }
}

int main()
{
    int i,n,r[Maxsize+1];
    cout<<"�����������е�Ԫ�ظ���nΪ��"<<endl;
    cin>>n;
    cout<<"���������������е�Ԫ�أ�"<<endl;
    for(i=1;i<=n;i++)
       cin>>r[i];
    StraightInsertSort(r,n);
    cout<<"ֱ�Ӳ�����������"<<endl;
    for(i=1;i<=n;i++)
       cout<<r[i]<<" ";
    return 0;
}
