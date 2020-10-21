#include<iostream>
using namespace std;

// ���� ------------- �ڲ��ǱȽ�����
// ���ݽṹ --------- ����
// ���ʱ�临�Ӷ� ---- O(nlogn)��O(n^2)��ֻ��һ��Ͱ��ȡ����Ͱ������ʽ
// ����ʱ�临�Ӷ� ---- O(n)��ÿ��Ԫ��ռһ��Ͱ
// ƽ��ʱ�临�Ӷ� ---- O(n)����֤����Ͱ��Ԫ�ظ������ȼ���
// ���踨���ռ� ------ O(n + bn)
// �ȶ��� ----------- �ȶ�

/* ������������ģ��Ͱ */
const int bn = 5;    
// ��������[0,49]��Ԫ�أ�ʹ��5��Ͱ�͹��ˣ�Ҳ���Ը������붯̬ȷ��Ͱ������
int C[bn];           // �������飬���Ͱ�ı߽���Ϣ

void InsertionSort(int A[], int left, int right)
{
    for (int i = left + 1; i <= right; i++)  
		// �ӵڶ����ƿ�ʼץ��ֱ�����һ����
    {
        int get = A[i];
        int j = i - 1;
        while (j >= left && A[j] > get)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = get;
    }
}

int MapToBucket(int x)
{
    return x / 10;    
	//ӳ�亯��f(x)�������൱�ڿ����е�Partition��
	//�Ѵ������ݷָ�ɻ�����������ݿ�
}

void CountingSort(int A[], int n)
{
    for (int i = 0; i < bn; i++)
    {
        C[i] = 0;
    }
    for (i = 0; i < n; i++)     // ʹC[i]������i��Ͱ��Ԫ�صĸ���
    {
        C[MapToBucket(A[i])]++;
    }
    for (i = 1; i < bn; i++)    
		// ��λͰ�߽磺��ʼʱ��C[i]-1Ϊi��Ͱ���һ��Ԫ�ص�λ��
    {
        C[i] = C[i] + C[i - 1];
    }
    int *B = (int *)malloc((n) * sizeof(int));
    for (i = n - 1; i >= 0; i--)
		// �Ӻ���ǰɨ�豣֤����������ȶ���(�ظ�Ԫ����Դ��򲻱�)
    {
        int b = MapToBucket(A[i]);  // Ԫ��A[i]λ��b��Ͱ
        B[--C[b]] = A[i];           
		// ��ÿ��Ԫ��A[i]�ŵ������������B�е���ȷλ����
        // Ͱ�ı߽类���£�C[b]Ϊb��Ͱ��һ��Ԫ�ص�λ��
    }
    for (i = 0; i < n; i++)
    {
        A[i] = B[i];
    }
    free(B);
}

void BucketSort(int A[], int n)
{
    CountingSort(A, n);          // ���ü�������ȷ������Ͱ�ı߽磨��Ͱ��
    for (int i = 0; i < bn; i++) // ��ÿһ��Ͱ�е�Ԫ��Ӧ�ò�������
    {
        int left = C[i];         // C[i]Ϊi��Ͱ��һ��Ԫ�ص�λ��
        int right = (i == bn - 1 ? n - 1 : C[i + 1] - 1);
		// C[i+1]-1Ϊi��Ͱ���һ��Ԫ�ص�λ��
        if (left < right)        // ��Ԫ�ظ�������1��Ͱ����Ͱ�ڲ�������
            InsertionSort(A, left, right);
    }
}

int main()
{
    int A[] = { 29, 25, 3, 49, 9, 37, 21, 43 };// ���Ͱ������Ƶ�����
    int n = sizeof(A) / sizeof(int);
    BucketSort(A, n);
    printf("Ͱ��������");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
	cin.get();
    return 0;
}