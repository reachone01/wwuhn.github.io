/* qsorter.c -- using qsort to sort groups of numbers */
#include <stdio.h>
#include <stdlib.h>

#define NUM 40
void fillarray(double ar[], int n);
void showarray(const double ar[], int n);
int mycomp(const void * p1, const void * p2);
/*
void qsort(
		   void *base, 
		   size_t nitems, 
		   size_t size, 
		   int (*compar)(const void *, const void*))
����
void *base������Ϊvoid*���൱�ڷ��ͣ�ָ��Ҫ���������ĵ�һ��Ԫ�ص�ָ�롣
nitems��������Ԫ�صĸ���������ָ��ֻ�޷��ں�����Ҫ����Ĳ����ṩ��
size����Ϊ����ָ���ṩ����void*���ͣ���Ҫ����Ĳ������ṩ������ÿ��Ԫ�صĴ�С�����ֽ�Ϊ��λ��
compar��ע��Ԫ�ص�������void*�������Ǹ��ֻ������ͼ��ַ������ṹ���ĳ���ؼ��֣�
//�����Ƚ�����Ԫ�صĺ�����������ָ�루�ص�������

*/

int main(void)
{
    double vals[NUM];
    fillarray(vals, NUM);
    puts("Random list:");
    showarray(vals, NUM);
    qsort(
		vals, 
		NUM, 
		sizeof(double), 
		mycomp);
    puts("\nSorted list:");
    showarray(vals, NUM);
	system("pause");
    return 0;
}

void fillarray(double ar[], int n)
{
    int index;
    
    for( index = 0; index < n; index++)
        ar[index] = (double)rand()/((double) rand() + 0.1);
}

void showarray(const double ar[], int n)
{
    int index;
    
    for( index = 0; index < n; index++)
    {
        printf("%9.4f ", ar[index]);
        if (index % 6 == 5)
            putchar('\n');
    }
    if (index % 6 != 0)
        putchar('\n');
}

/* sort by increasing value */
int mycomp(const void * p1, const void * p2)
{
    /* need to use pointers to double to access values   */
    const double * a1 = (const double *) p1;
    const double * a2 = (const double *) p2;
	return *(int*)a-*(int*)b;   
    if (*a1 < *a2)
        return -1;
    else if (*a1 == *a2)
        return 0;
    else
        return 1;
}
