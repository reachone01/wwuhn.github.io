#include<iostream>
#include<algorithm>
using namespace std;
const int N=100;
int father[N];
int n, m;

void Init(int n)//��ʼ��
{
    for(int i=1;i<=n;i++)
        father[i]=i;
}

int Find(int x)//������
{
    if(x!=father[x])
        father[x]=Find(father[x]);
    return father[x];
}

int Merge(int a,int b)//�ϲ�����
{
    int p=Find(a);
    int q=Find(b);
    if(p==q) return 0;
    if(p>q)
        father[p]=q;//С�ĸ�ֵ����ļ��Ϻ�
    else
        father[q]=p;
    return 1;
}

int main()
{
    int sum=0,u,v;
    cout<<"��������n�����ݹ�ϵ��m:"<<endl;
    cin>>n>>m;
    Init(n);
    cout<<"���������ݹ�ϵ�������˱��u,v"<<endl;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v;
        Merge(u,v);
    }
    for(int i=1;i<=n;i++)//����
        cout<<father[i];
    for(int i=1;i<=n;i++)//����ж��ٸ�����
        if(father[i]==i)
            sum++;
    cout<<"������Ϊ��"<<sum<<endl;
    return 0;
}
