// ����Ч�ʵ����ݺ���
#include <stdio.h>

double pow(double x,int n)
{
    double ret=1;
    while (n > 0)
    {
        if (n%2 == 1)
            ret=ret * x;
        x = x * x;
        n = n / 2;
    }
    return ret;
}
int main()
{
    printf("%.2f\n",pow(1.2,5));
    while(1);
    return 0;
}