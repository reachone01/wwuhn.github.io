#include<iostream>
using namespace std;
#define Maxsize 100

int SqSearch(int r[],int n,int x)//˳�����
{
	for(int i=0;i<n;i++) //Ҫ�ж�i�Ƿ񳬹���Χn
        if(r[i]==x) //r[i]��x�Ƚ�
            return i;//�����±�
    return -1;
}

int SqSearch2(int r2[],int n,int x)//˳������Ż��㷨
{
	int i;
	r2[0]=x;//������Ԫ�ط���r[0]����Ϊ������
	for(i=n;r2[i]!=x;i--);//����Ҫ�ж�i�Ƿ񳬹���Χ
    return i;
}

int main()
{
    int i,n,x,r[Maxsize],r2[Maxsize+1];
    cout<<"������Ԫ�ظ���nΪ��"<<endl;
    cin>>n;
    cout<<"������n��Ԫ�أ�"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>r[i];
        r2[i+1]=r[i];//r2[]����0�ռ�δ�ã���������
    }
    cout<<endl;
    cout<<"������Ҫ���ҵ�Ԫ�أ�";
    cin>>x;
    //i=SqSearch(r,n,x);
//    if(i==-1)
//      cout<<"��������û��Ҫ���ҵ�Ԫ��"<<endl;
//    else
//      cout<<"Ҫ���ҵ�Ԫ���ڵ�"<<i+1<<"λ"<<endl;
    i=SqSearch2(r2,n,x);
    if(i==0)
		cout<<"��������û��Ҫ���ҵ�Ԫ��"<<endl;
    else
		cout<<"Ҫ���ҵ�Ԫ���ڵ�"<<i<<"λ"<<endl;
    return 0;
}
