#include <stdio.h>

int callee(int f, int g)  // �ȼ���int __cdecl callee(int f, int g) // ��ʽ�����˵���Լ��
{
    int h = f + g;
    return h;
}

int func(int a, int b)
{
    int c = a*a;
    int d = b*b;
    int e = callee(c,d);
    return e;
}

int main()
{
    int result=func(3,4);
    return 0;
}
