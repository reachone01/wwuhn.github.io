#include<iostream>
using namespace std;
bool isPalindrome(int);
int main()
{
    int m,n;
    cout<<"��������ڵĻ�������"<<endl;
    cin>>m;
    for(n=1;n<=m;++n)
        if(isPalindrome(n))
            cout<<n<<" ";
        return 0;
}

bool isPalindrome(int n)
{
    int a[20]; //���ڴ洢n�еĸ�λ��
    int i=0;
    //�����ѭ����ʹa���������δ�Ÿ���ʮ���١���λ��
    while(n>0)
    {
        a[i++]=n%10;
        n/=10;
    }
    //�˳�ѭ��������֪��nΪiλ��
    int j=0,k=i-1;
    while(a[j]==a[k]&&j<k)  //ֻҪ���ߵ�����ȣ������м䡰����
        j++,k--;
    if(j>=k) 
        return true;        //ǰ�����˶�Ӧ�����ֶ��ȽϹ��ˣ�����ȣ��ǻ�����
    else 
        return false;
}