#include <iostream>
using namespace std;
const int MINKEY = 0;  // �������������������������0
const int MAXKEY = 200;// ���������������������С��200

// ��ȫ��������Ҷ�ӽڵ�����ȶ�Ϊ2�Ľڵ������1
void Adjust(int &k, int* &ls, int* &b, int i)
{
    // ���Ʒ�Ҷ�ӽ��ls[]���±�
    int t = (i + k) / 2;// ��һ����Ҷ�ӽ����±ꡢ�ڶ�������
    // ����Ҷ�ӽ��b[]���±�
    int s = i;
    for (; t > 0; t /= 2){
        if (b[ls[t]]<b[s]){
            swap(s, ls[t]);
        }
        else{
            s = s;
        }
    }
    ls[0] = s;
}
void createLoserTree(int* arr[],int &k, int* &ls, int* &b)
{
    for (int i = 0; i < k; ++i)
        b[i] = arr[i][0];
    b[k] = MINKEY;
    for (i = 0; i < k; ++i)
        ls[i] = k;    //��Сֵ�����Ե�ʤ�ߣ������
    //��k��Ҷ�ӽڵ�
    //�����һ��Ҷ�ӽڵ㿪ʼ�����Ŵ�Ҷ�ӽڵ㵽���ڵ��·������
    for (i = k - 1; i >= 0; --i){
        Adjust(k, ls, b, i);
        for (int i = 0; i < k; ++i)
            cout << ls[i] << " ";
        cout << endl;
    }
}

void kMerge(int* arr[], int* arrayElementsCount, int& k, \
            int* &ls, int* &b, int& mostMinCount)
{
    int* index = new int[k];
    for (int i = 0; i < k; ++i)
        index[i] = 0;
    for (i = 0; i < mostMinCount; ++i){
        int s = ls[0];
        cout << b[s] << " ";
        ++index[s];
        if (index[s] < arrayElementsCount[s])
            arr[s][0] = arr[s][index[s]];
        else
            arr[s][0] = MAXKEY;
        b[s] = arr[s][0];
        Adjust(k, ls, b, s);
    }
    delete[] index;
}

int main()
{
    int arr0[] = { 6, 15, 25 };
    int arr1[] = { 12, 37, 48, 50 };
    int arr2[] = { 10, 15, 16 };
    int arr3[] = { 9, 18, 20 };
    int arr4[] = { 10, 11, 40 };
    int* arr[] = { arr2, arr3, arr4, arr0, arr1 };
    int* arrayElementsCount = new int[5];
    arrayElementsCount[0] = sizeof(arr2) / sizeof(arr2[0]);
    arrayElementsCount[1] = sizeof(arr3) / sizeof(arr3[0]);
    arrayElementsCount[2] = sizeof(arr4) / sizeof(arr4[0]);
    arrayElementsCount[3] = sizeof(arr0) / sizeof(arr0[0]);
    arrayElementsCount[4] = sizeof(arr1) / sizeof(arr1[0]);
    int k = sizeof(arr) / sizeof(arr[0]);
    //��¼ÿ���������Ԫ��
    int* b = new int[k + 1];
    //��¼���ߵ��±�
    int* ls = new int[k];
    createLoserTree(arr, k,ls,b);
    int mostMinCount = 13;
    kMerge(arr, arrayElementsCount, k, ls, b, mostMinCount);
    delete[] b;
    delete[] ls;
    delete[] arrayElementsCount;
    system("pause");
}