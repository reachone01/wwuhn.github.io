#include<iostream>   // ���ֲ��ҵĵݹ���ǵݹ�ʵ��
using namespace std; // ���η����ɷ֣��ɺϣ��������ж�����

int bisoLoop(int arr[], int len, int findData)
{
    if(arr==NULL || len <=0)
        return -1;
    int start = 0;
    int end = len-1;
    while(start<=end)
    {
        int mid = start+(end-start)/2;
        if(arr[mid] == findData)
            return mid;
        else if(findData < arr[mid])
            end = mid-1;
        else
            start = mid+1;
    }
    return -1;
}

// �ݹ����Ե��õ����⣬��Ҫ��start��endд�ڲ����б���
// ����ǺͶ�̬���������Χ�Ŀ�ʼ�ͽ���
int bisoRecurs(int arr[], int findData, int start, int end)
{
    if(arr==NULL || start>end)
        return -1;

        int mid = start+(end-start)/2;
        if(arr[mid] == findData)
            return mid;
        else if(findData < arr[mid])
            bisoRecurs(arr, findData, start, mid-1);
        else
            bisoRecurs(arr, findData, mid+1, end);
}

void main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int len = sizeof(arr)/sizeof(arr[0]);
    int index = bisoLoop(arr,len,6);
    int index2 = bisoRecurs(arr,6,0,len-1);
    cout<<index<<endl;
    cout<<index2<<endl;
    system("pause");
}
/*
5
5
*/
