#include <stdio.h> // ���ֲ��ҵĵ���ʵ��
#define SIZE 12
int r_search(int arr[], int low, int high, int k);
int main( )
{
    int d[SIZE] = { 1, 3, 9, 12, 32, 41, 45, 62, 75, 77, 82, 95};
    int key,index;
    printf("����Ҫ���ҵĹؼ��֣�\n");
    scanf("%d", &key);
    index = r_search(d, 0, SIZE-1, key);
    if(index >= 0)
        printf("�ؼ�������λ���ǣ�%d \n", index);
    else
        printf("û���ҵ��ؼ���\n");
    return 0;
}
 
 
int r_search(int arr[], int low, int high, int k)
{
    int i,mid;
    if (low>high) i=-1;
    else
    {
        mid=(low+high)/2;
        if(arr[mid]==k)
            i=mid;
        else if(arr[mid]>k)
            i=r_search(arr, low,mid-1,k);
        else
            i=r_search(arr, mid+1,high,k);
    }
    return i;
}