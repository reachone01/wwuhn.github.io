#if 1
#include <stdio.h>
int a[101],n;//����ȫ�ֱ�����������������Ҫ���Ӻ�����ʹ��
void quicksort(int left,int right)
{
	int i,j,t,temp;
	if(left>right) return;
	temp=a[left];//temp�д�ľ��ǻ�׼��
	i=left;
	j=right;
	while(i!=j)
	{
		while(a[j]>=temp && i<j)//˳�����Ҫ��Ҫ�ȴ��ұ߿�ʼ��
			j--;
		while(a[i]<=temp && i<j)//�����ұߵ�
			i++;
		if(i<j)//�����������������е�λ��
		{
			t=a[i];
			a[i]=a[j];
			a[j]=t;
		}
	}
	a[left]=a[i];//���ս���׼����λ
	a[i]=temp;
	quicksort(left,i-1);//����������ߵģ�������һ���ݹ�Ĺ���
	quicksort(i+1,right);//���������ұߵ� ��������һ���ݹ�Ĺ���
}
int main()
{
	int i,j,n;
	printf("������Ҫ�����Ԫ�ظ���:");//��������
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("�����%d��Ԫ�أ���%d��Ԫ��):",i,n);
		scanf("%d",&a[i-1]);
	}
	quicksort(1,n);//�����������
	for(i=1;i<=n;i++)//��������Ľ��
		printf("%d ",a[i]);
	printf("\n");
	system("pause");
	return 0;
}
#endif
#if(0)

#include <iostream>						// Quick Sort 1
using namespace std; 

int Partition(int r[],int low,int high)	// ���ֺ������ͻ�׼Ԫ�ؽ������������
{
    int i=low,j=high,pivot=r[low];		// ��׼Ԫ��
    while(i<j)
    {
        while(i<j && r[j]>pivot) 		// ����ɨ��
			j--;
        if(i<j)
            swap(r[i++],r[j]);			// r[i]��r[j]������i+1����һλ
        while(i<j && r[i]<=pivot)		// ����ɨ��
			i++;
        if(i<j)
            swap(r[i],r[j--]);			// r[i]��r[j]���� ��j-1����һλ
    }
    return i;							// �������ջ�����ɺ��׼Ԫ�����ڵ�λ��
}

void QuickSort(int R[],int low,int high)// ʵ�ֿ����㷨
{
    int mid;
    if(low<high)
    {
        mid=Partition(R,low,high);	// ��׼λ��
        QuickSort(R,low,mid-1);		// ������ݹ����
        QuickSort(R,mid+1,high);	// ������ݹ����
    }
}

int main()
{
	int arr[] = {5,2,9,4,7,6,1,3,8}; // ��С�����������
    int n = sizeof(arr) / sizeof(int);

    QuickSort(arr,0,n-1);
    cout<<"����������Ϊ��"<<endl;
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" " ;
    cout<<endl;
	system("pause");
    return 0;
}


int Partition2(int r[],int low,int high) // ���ֺ���������Ԫ��ֱ�ӽ�����Ч�ʽϸ�
{
    int i=low,j=high,pivot=r[low];		 // ��׼Ԫ��
    while(i<j)
    {
        while(i<j&&r[j]>pivot) j--;		 // ����ɨ��
        while(i<j&&r[i]<=pivot) i++;	 // ����ɨ��
        if(i<j)
            swap(r[i++],r[j--]);		// r[i]��r[j]����
    }
    if(r[i]>pivot)
    {
        swap(r[i-1],r[low]);	// r[i-1]��r[low]����
        return i-1;				// �������ջ�����ɺ��׼Ԫ�����ڵ�λ��
    }
    swap(r[i],r[low]);	// r[i]��r[low]����
    return i;			// �������ջ�����ɺ��׼Ԫ�����ڵ�λ��
}

#endif

#if(0)
#include <stdio.h> 					// Quick Sort 2
#include <stdlib.h>
// ���� -----------�ڲ��Ƚ�����
// ���ݽṹ -------����
// ���ʱ�临�Ӷ�--ÿ��ѡȡ�Ļ�׼������󣨻���С����Ԫ�أ�����ÿ��ֻ���ֳ���һ��������
				   // ��Ҫ����n-1�λ��ֲ��ܽ����ݹ飬ʱ�临�Ӷ�ΪO(n^2)
// ����ʱ�临�Ӷ�--ÿ��ѡȡ�Ļ�׼������λ��������ÿ�ζ����ȵĻ��ֳ�����������
					// ֻ��Ҫlogn�λ��־��ܽ����ݹ飬ʱ�临�Ӷ�ΪO(nlogn)
// ƽ��ʱ�临�Ӷ�--O(nlogn)
// ���踨���ռ� ---��Ҫ�ǵݹ���ɵ�ջ�ռ��ʹ��(��������left��right�Ⱦֲ�����)��
					// ȡ���ڵݹ�������ȣ�һ��ΪO(logn)�����ΪO(n)       
// �ȶ��� ---------���ȶ�

void Swap(int A[], int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

int Partition(int A[], int left, int right)  // ���ֺ���
{
    int pivot = A[right];               // ����ÿ�ζ�ѡ�����һ��Ԫ����Ϊ��׼
	//int pivot = A[(left+right)/2];	// Ҳ����ÿ�ζ�ѡ���м��Ԫ����Ϊ��׼
    int tail = left - 1;                // tailΪС�ڻ�׼�����������һ��Ԫ�ص�����
    for (int i = left; i < right; i++)  // ������׼���������Ԫ��
    {
        if (A[i] <= pivot)              // ��С�ڵ��ڻ�׼��Ԫ�طŵ�ǰһ��������ĩβ
            Swap(A, ++tail, i);
    }
    Swap(A, tail + 1, right);// ���ѻ�׼�ŵ�ǰһ��������ĺ�ߣ�ʣ�µ������鼴�Ǵ��ڻ�׼��������
                             // �ò������п��ܰѺ���Ԫ�ص��ȶ��Դ��ң����Կ��������ǲ��ȶ��������㷨
    return tail + 1;         // ���ػ�׼������
}
/*
0	1	2	3	4	5	6	7	8	i	tail
5	2	9	4	11	6	1	3	8	0	-1
5	2	9	4	11	6	1	3	8	0	0
5	2	9	4	11	6	1	3	8	1	1
5	2	9	4	11	6	1	3	8	2	1
5	2	4	9	11	6	1	3	8	3	2
5	2	4	9	11	6	1	3	8	4	2
5	2	4	6	11	9	1	3	8	5	3
5	2	4	6	1	9	11	3	8	6	4
5	2	4	6	1	3	11	9	8	7	5
5	2	4	6	1	3	8	9	11	8	6
*/

void QuickSort(int A[], int left, int right)
{
    if (left >= right)
        return;
    int pivot_index = Partition(A, left, right); // ��׼������
    QuickSort(A, left, pivot_index - 1);
    QuickSort(A, pivot_index + 1, right);
}

int main()
{
    int A[] = {5,2,9,4,11,6,1,3,8}; // ��С�����������
    int n = sizeof(A) / sizeof(A[0]);
    QuickSort(A, 0, n-1);
    printf("������������");
    for(int i=0; i<n; i++)
        printf("%d ", A[i]);
    printf("\n");
	system("pause");
    return 0;
}

#endif