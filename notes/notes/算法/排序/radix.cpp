#include<iostream>
using namespace std;

// ���� ------------- �ڲ��ǱȽ�����
// ���ݽṹ ---------- ����
// ���ʱ�临�Ӷ� ---- O(n * dn)
// ����ʱ�临�Ӷ� ---- O(n * dn)
// ƽ��ʱ�临�Ӷ� ---- O(n * dn)
// ���踨���ռ� ------ O(n * dn)
// �ȶ��� ----------- �ȶ�

const int dn = 3;                // �������Ԫ��Ϊ��λ��������
const int k = 10;                
// ����Ϊ10��ÿһλ�����ֶ���[0,9]�ڵ�����
int C[k];

int GetDigit(int x, int d)          // ���Ԫ��x�ĵ�dλ����
{
    int radix[] = { 1, 1, 10, 100 };
	// ���Ϊ��λ������������ֻҪ����λ��������
    return (x / radix[d]) % 10;
}

void CountingSort(int A[], int n, int d)
	// ����Ԫ�صĵ�dλ���֣���A������м�������
{
    for (int i = 0; i < k; i++)
    {
        C[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        C[GetDigit(A[i], d)]++;
    }
    for (i = 1; i < k; i++)
    {
        C[i] = C[i] + C[i - 1];
    }
    int *B = (int*)malloc(n * sizeof(int));
    for (i = n - 1; i >= 0; i--)
    {
        int dight = GetDigit(A[i], d);  
		// Ԫ��A[i]��ǰλ����Ϊdight   
        B[--C[dight]] = A[i];           
// ���ݵ�ǰλ���֣���ÿ��Ԫ��A[i]�ŵ������������B�е���ȷλ����
		// ����������ǰλ����ͬΪdight��Ԫ��ʱ���Ὣ�����
		//��ǰԪ�ص�ǰһ��λ���ϱ�֤����������ȶ���
    }
    for (i = 0; i < n; i++)
    {
        A[i] = B[i];
    }
    free(B);
}

void LsdRadixSort(int A[], int n)// ���λ���Ȼ�������
{
    for (int d = 1; d <= dn; d++)// �ӵ�λ����λ
        CountingSort(A, n, d);   // ���ݵ�dλ���ֶ�A���м�������
}

int main()
{
    int A[] = { 329, 457, 657, 839, 436, 720, 355 };
	// ��Ի���������Ƶ�����
    int n = sizeof(A) / sizeof(int);
    LsdRadixSort(A, n);
    printf("������������");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
	cin.get();
    return 0;
}