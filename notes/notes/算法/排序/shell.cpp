#if 0
#include <stdio.h>  
#include <stdlib.h>  
// ���� -------------- �ڲ��Ƚ�����
// ���ݽṹ ---------- ����
// ���ʱ�临�Ӷ� ---- ���ݲ������еĲ�ͬ����ͬ����֪��õ�ΪO(n(logn)^2)
// ����ʱ�临�Ӷ� ---- O(n)
// ƽ��ʱ�临�Ӷ� ---- ���ݲ������еĲ�ͬ����ͬ��
// ���踨���ռ� ------ O(1)
// �ȶ��� ------------ ���ȶ�
void output(int a[], int n){ //�������Ԫ��
	for(int i = 0; i<n;++i)
		printf("%2d ",a[i]);
	printf("\n");
}
void ShellSort(int A[], int n)
{
    int h = 0;
    while (h <= n)                          // ���ɳ�ʼ����
    {
        h = 3 * h + 1;
    }
    while (h >= 1)
    {
        for (int i = h; i < n; i++)
        {
            int j = i - h;
            int get = A[i];
            while (j >= 0 && A[j] > get)
            {
                A[j + h] = A[j];
                j = j - h;
            }
            A[j + h] = get;
			printf("gap%2d��\n",h);
			output(A,n);
        }
        h = (h - 1) / 3;                    // �ݼ�����
    }
}

int main()
{
	int A[] = { 15, 17, 10, 4, 8, 6, 1, 3, 7, 0, 14, 11,5, 12, 2, 9 };
	
    int n = sizeof(A) / sizeof(A[0]);
    for(int i =1;i<=n;++i)
		printf("%2d ",i);
	printf("\n");
	output(A,n);
    ShellSort(A, n);
    printf("\n");
	system("pause");
    return 0;
}
#endif

#if 1  //���԰棬�ɽ���ص����ע�͵�����������F11�𲽵���ʱ���������
//����ϸ�ڣ��ں�����ʼ������ϵ㣬��F11������
// ��variable��watch���Դ��ڣ���watch��������Ҫ���Եı�������a[j+r]
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 13
void ShellSort(int* a, int len)
{
	int j,temp;
	int x=0; //�м䲽������
	for(int r=len/2; r>=1; r/=2) // ����������n/2��n/4��n/8������������Ԫ�طֱ�Ƚ�
	{
		for(int i=r; i<len; i++)
		{
			temp = a[i];
			j=i-r;
			while(j>=0 && temp < a[j])
			{
				a[j+r] = a[j];
				j-=r;//���������ݵ�ǰ����飨�������飩��Ӧ��Ԫ��
			}
			a[j+r] = temp;//�±�=j+r=i���޽�������i-nr(�н���)
		}
		x++;
		//printf("��%d����������r=%d����",x,r);
		//for(int h=0; h<len; h++)
		//{
			//printf("%d ",a[h]);
		//}
		//printf("\n");
	}
}

void main()
{
	int i;
	int arr[SIZE]={107,117,106,129,116,123,111,110,127,119,103,107,114};

	//srand(time(0));
	//for(i=0; i<SIZE; i++)
		//arr[i] = rand()/1000 + 100;

	//printf("����ǰ��\n");
	//for(i=0; i<SIZE; i++)
		//printf("%d ", arr[i]);
	//printf("\n");

	ShellSort(arr,SIZE);
	printf("�����\n");
	for(i=0; i<SIZE; i++)
		printf("%d ", arr[i]);
	printf("\n");
	system("pause");
}
/*
����ǰ��
						 107 117 106 129 116 123 111 110 127 119 103 107 114
��1����������r=6����107 110 106 119 103 107 111 117 127 129 116 123 114

��2����������r=3����107 103 106 111 110 107 114 116 123 119 117 127 129
��3����������r=1����103 106 107 107 110 111 114 116 117 119 123 127 129
�����
103 106 107 107 110 111 114 116 117 119 123 127 129
*/
#endif


#if 0
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 13

void ShellSort(int* a, int len)
{
	int j,temp;
	int x=0;						// �м䲽������
	for(int r=len/2; r>=1; r/=2)	// ����������n/2��n/4��n/8����
									// ��������Ԫ�طֱ�Ƚ�
	{
		for(int i=r; i<len; i++)
		{
			temp = a[i];
			j=i-r;
			while(j>=0 && temp < a[j])
			{
				a[j+r] = a[j];
				j-=r; // ���������ݵ�ǰ����飨�������飩��Ӧ��Ԫ��
			}
			a[j+r] = temp; // �±�=j+r=i���޽�������i-nr(�н���)
		}
		x++;
		printf("��%d����������r=%d����",x,r);
		for(int h=0; h<len; h++)
		{
			printf("%d ",a[h]);
		}
		printf("\n");
	}
}

void main()
{
	int i;
	int arr[SIZE];

	srand(time(0));
	for(i=0; i<SIZE; i++)
		arr[i] = rand()/1000 + 100;

	printf("����ǰ��\n");
	for(i=0; i<SIZE; i++)
		printf("%d ", arr[i]);
	printf("\n");

	ShellSort(arr,SIZE);
	printf("�����\n");
	for(i=0; i<SIZE; i++)
		printf("%d ", arr[i]);
	printf("\n");
	system("pause");
}
/*
����ǰ��
					  107 117 106 129 116 123 111 110 127 119 103 107 114
��1����������r=6����107 110 106 119 103 107 111 117 127 129 116 123 114

��2����������r=3����107 103 106 111 110 107 114 116 123 119 117 127 129
��3����������r=1����103 106 107 107 110 111 114 116 117 119 123 127 129
�����
103 106 107 107 110 111 114 116 117 119 123 127 129
*/
#endif