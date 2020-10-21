#if 1
#include <iostream>
#include <stack>
using namespace std;
struct Problem{
	int n;
	char src,mid,dest;
	Problem(int nn,char s,char m,char d):n(nn),src(s),mid(m),dest(d){}
};// һ��Problem��������һ�������⣬��src�ϵ�n��������midΪ�н飬�ƶ���dest
stack<Problem> stk; // һ��Ԫ�ش���һ�������⣬����n�����ӣ���ջ�ĸ߶Ȳ�����n*3

void main()
{

	system("pause");
}
#endif

#if 0
#include <stdio.h>
#include <stdlib.h>
/*==================================================
�������ܣ������ŵ�����ƶ�����
�������룺��������n���������ı��from,temp,to
��������������ŵ�����ƶ�����
==================================================*/
void hanoi(int n, char from, char temp, char to)
{
	if (n==1)
		printf("�����Ϊ1�����Ӵ�%c�Ƶ�%c\n",from,to);
	else
	{
		printf("hanoi(%d,%c,%c,%c)\n",n-1,from,to,temp);
		hanoi(n-1,from,to,temp);					//��x�ϱ��Ϊ1��n-1��Բ���Ƶ�y��z��������
		printf("���Ӵ�%c�Ƶ�%c\n",from,to);		//��x�ϱ��Ϊn��Բ���Ƶ�z
		printf("hanoi(%d,%c,%c,%c)\n",n-1,temp,from,to);
		hanoi(n-1,temp,from,to);					//��y�ϱ��Ϊ1��n-1��Բ���Ƶ�z��y��������
		
	}
}
int main()
{
	int n;
	printf("��������������n:\n");
	scanf("%d",&n);
	hanoi(n,'A','B','C');
	system("pause");
	return 0;
}
//http://www.7k7k.com/swf/37623.htm
/*
����������˵�һ������С�ģ����ӵ��ƶ���ģ�������Ϸ���������ͻ����Ӧ�֡�

��n������ʱ����һ������ֻ��������ACBACB������ѭ���ƶ���

��n��ż��ʱ����һ������ֻ��������ABCABC������ѭ���ƶ���
*/

#endif