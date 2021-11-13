/*
��ϣ���Ĵ洢�����
��δ����ǵ��͵��ÿռ任ʱ����㷨��������洢����ռ�ռ���±���ȫ��ͬ����δ��벻�����κε�ʵ���ԣ�
�����˵��������˼·��

  
*/
#if 1

#include <iostream>
using namespace std;
int search(int h[], int key);
void store(int h[], int data);
int main()
{
    int data[1000]={0};
    int m, n;
    for (int i = 0; i < 6; i++)
    {
        cin>>n;
        store(data, n);
    }
    cin>>m;
    int result = search(data, m);
    if (result)
        cout<<"���������ҵ�." <<endl;
    else
        cout<<"û�д�����!"<<endl;
    return 0;
}
int search(int d[], int key)
{
    return d[key];
}
void store(int d[], int n)
{
    d[n]=n;
}

#else
//�����ǲ��ù�ϣ���洢���ݲ�ʵ�ֲ��ҵ�ʾ����
//ʵ�ֹ�ϣ�����á�����ȡ�෨���������ͻΪ�����ŵ�ַ������

#include <iostream>
using namespace std;
int searchHash(int h[], int l, int key);
void insertHash(int h[], int l, int data);
int main()
{
    const int hashLength = 13;//��ϣ����
    int hashTable[hashLength]={0};
    int m, n;
    //����hash
    for (int i = 0; i < 6; i++)
    {
        cin>>n;
        insertHash(hashTable, hashLength, n);
    }
    cin>>m;
    int result = searchHash(hashTable,hashLength, m);
    if (result != -1)
        cout<<"�Ѿ����������ҵ���λ��Ϊ��" << result<<endl;
    else
        cout<<"û�д�ԭʼ"<<endl;
    return 0;
}

int searchHash(int h[], int l, int key)
{
    // ��ϣ����
    int hashAddress = key % l;
    // ָ��hashAdrress��Ӧֵ���ڵ����ǹؼ�ֵ�����ÿ���Ѱַ�����
    while (h[hashAddress] != 0 && h[hashAddress] != key)
    {
        hashAddress = (++hashAddress) % l;
    }
    // ���ҵ��˿��ŵ�Ԫ����ʾ����ʧ��
    if (h[hashAddress] == 0)
        return -1;
    return hashAddress;
}
// ���ݲ���Hash��
void insertHash(int h[], int l, int data)
{
    // ��ϣ����
    int hashAddress = data % l;
    // ���key���ڣ���˵���Ѿ�������ռ�ã���ʱ��������ͻ
    while (h[hashAddress] != 0)
    {
        // �ÿ���Ѱַ���ҵ�
        hashAddress = (++hashAddress) % l;
    }
    // ��data�����ֵ���
    h[hashAddress] = data;
}

#endif

#if 0


#endif
/*

*/