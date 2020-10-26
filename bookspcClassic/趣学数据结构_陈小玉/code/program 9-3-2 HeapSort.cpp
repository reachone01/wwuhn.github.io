#include<iostream>
using namespace std;

#define maxN 1000
int r[maxN];

void Sink(int k,int n)//�³�����
{
    while(2*k<=n)//���������
    {
        int j=2*k;//jָ������
        if(j<n&&r[j]<r[j+1])//������Һ��������ӱ��Һ���С
            j++;    //jָ���Һ���
        if(r[k]>=r[j])//�Ƚϴ�ĺ��Ӵ�
            break;    //�������
        else
            swap(r[k],r[j]);//��ϴ�ĺ��ӽ���
        k=j;//kָ�򽻻������λ�ã��������±Ƚϣ�һֱ�³���Ҷ��
    }
}

void CreatHeap(int n)//������ʼ��
{
    for(int i=n/2;i>0;i--)//�����һ����֧���n/2��ʼ����Ϊ�ѣ�ֱ����һ�����
        Sink(i,n);
}

void HeapSort(int n)//������
{
    CreatHeap(n);//������ʼ��
    while(n>1)
    {
        swap(r[1],r[n--]);//�Ѷ������һ����¼������������n��1
        Sink(1,n);//�Ѷ��³�
    }
}

void print(int n)//���
{
    for(int i=1;i<=n;i++)
        cout<<r[i]<<"\t";
    cout<<endl;
}

int main()
{
    int n;
    cout<<"������������¼������"<<endl;
    cin>>n;
    cout<<"������n��������"<<endl;
    for(int i=1;i<=n;i++)
        cin>>r[i];
    HeapSort(n);//������
    print(n);
    return 0;
}
