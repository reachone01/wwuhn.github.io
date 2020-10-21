#if 1
#include <stdio.h>
#include <time.h>
int step=1;

void move(int n,char a,char c)
{
	if(n==1)
		printf("Step %2d: Disk %d %c �� %c *\n",step,n,a,c);
	else
		printf("Step %2d: Disk %d %c �� %c\n",step,n,a,c);
	++step;
}
/*
void Hanoi(int n,char a,char b,char c)
{
	if(n==1)
	{
		move(n,a,c);	// ��ֻʣһ������ʱ������1������ֱ�Ӵ�a�Ƶ�c
		return;
	}
	Hanoi(n-1,a,c,b);	// ��n-1�����������aͨ��c�ƶ���b
	move(n,a,c);		// ��ʣ�µĵ�n������ֱ�Ӵ�a�Ƶ�c
	Hanoi(n-1,b,a,c);	// ��n-1�����������bͨ��a�ƶ���c
}
*/
void Hanoi(int n,char a,char b,char c)
{
	if(n==1)
		move(n,a,c);	// ��ֻʣһ������ʱ������1������ֱ�Ӵ�a�Ƶ�c
	else{
		Hanoi(n-1,a,c,b);	// ��n-1�����������aͨ��c�ƶ���b
		move(n,a,c);		// ��ʣ�µĵ�n������ֱ�Ӵ�a�Ƶ�c
		Hanoi(n-1,b,a,c);	// ��n-1�����������bͨ��a�ƶ���c
	}
}
int main(){
	int n;
	time_t a,b,c;
	printf("�����뺺ŵ��������(18����222��)��");
	scanf("%d",&n);
	a = clock();
	Hanoi(n,'A','B','C');
	b = clock();
	step=1;
	for(int i=1;i<=n;i++)
		step*=2;
	printf("�ƶ���%d�Σ�������%d���롣ÿ�������%lf�Ρ�",step-1,(b-a),double(step)/(b-a)*1000);
	getchar();getchar();
	return 0;
}

#endif



#if 0
/*
1 n-1�����ӣ�src��mid
2 ��n�����ӣ�src��dst
3 n-1�����ӣ�mid��dst
                  1 A B C       
                  1 A C B  1 A C B      
         2 A C B  1 C A B  1 C A B  1 C A B           1 B C A  
         1 A B C  1 A B C  1 A B C  1 A B C  1 A B C  1 B A C  1 B A C 
3 A B C  2 B A C  2 B A C  2 B A C  2 B A C  2 B A C  2 B A C  1 A B C  1 A B C  1 A B C

*/
#include <iostream> // ��ջ����ݹ�������Hanoi����ŵ��������
#include <stack>
using namespace std;
struct Problem{
	int n;
	char src,mid,dst;// src��ʾ��һ�����ӣ�Դ����dst��ʾ���������ӣ�Ŀ�ĵأ�
	Problem(int nn,char s,char m,char d):n(nn),src(s),mid(m),dst(d){}
};					 // һ��Problem��������һ�������⣬��src�ϵ�n��������midΪ�н飬�ƶ���dst
stack<Problem> stk;  // һ��Ԫ�ش���һ�������⣬����n�����ӣ���ջ�ĸ߶Ȳ�����n*3

void main()
{
	int n;
	printf("��������������n:\n");
	cin>>n;
	stk.push(Problem(n,'A','B','C'));	// ��ʼ��������ջ
	while(!stk.empty())
	{
		Problem cp = stk.top();			// cp��ʾ��ǰ������current sub-problem
		stk.pop();
		if(cp.n==1)						// ����ֱ�����������
			cout<<cp.src<<"->"<<cp.dst<<endl;
		else							// �ֽ������⣬ע���������˳�򣺣�2 
		{
			stk.push(Problem(cp.n-1, cp.mid, cp.src, cp.dst)); // 3 n-1�����ӣ�mid��dst
			stk.push(Problem(1,      cp.src, cp.mid, cp.dst)); // 2 ��n�����ӣ�src��dst
			stk.push(Problem(cp.n-1, cp.src, cp.dst, cp.mid)); // 1 n-1�����ӣ�src��mid
		}
	}
	system("pause");
}
#endif
/*
4
A->B
A->C
B->C
A->B
C->A
C->B
A->B
A->C
B->C
B->A
C->A
B->C
A->B
A->C
B->C
*/
#if 0
#include <stdio.h>  // �õݹ�������Hanoi����ŵ��������
#include <stdlib.h>
void hanoi(int n, char from, char temp, char to)
{
	if (n==1)
		printf("%c��%c(1)\n",from,to);
	else
	{
		//printf("hanoi(%d,%c,%c,%c)\n",n-1,from,to,temp);
		hanoi(n-1,from,to,temp);		//��x�ϱ��Ϊ1��n-1��Բ���Ƶ�y��z��������
		printf("%c��%c\n",from,to);		//��x�ϱ��Ϊn��Բ���Ƶ�z
		//printf("hanoi(%d,%c,%c,%c)\n",n-1,temp,from,to);
		hanoi(n-1,temp,from,to);		//��y�ϱ��Ϊ1��n-1��Բ���Ƶ�z��y��������
		
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
/*
��������������n:
4
A��B(1)
A��C
B��C(1)
A��B
C��A(1)
C��B
A��B(1)
A��C
B��C(1)
B��A
C��A(1)
B��C
A��B(1)
A��C
B��C(1)
*/
//http://www.7k7k.com/swf/37623.htm
/*
 C
A B
����������˵�һ������С�ģ����ӵ��ƶ���ģ�������Ϸ���������ͻ����Ӧ�֡�

��n������ʱ����һ������ֻ��������ACBACB������ѭ���ƶ�(˳ʱ��)��

��n��ż��ʱ����һ������ֻ��������ABCABC������ѭ���ƶ�(��ʱ��)��
��������������n:
5
A��C(1)
A��B
C��B(1)
A��C
B��A(1)
B��C
A��C(1)
A��B
C��B(1)
C��A
B��A(1)
C��B
A��C(1)
A��B
C��B(1)
A��C
B��A(1)
B��C
A��C(1)
B��A
C��B(1)
C��A
B��A(1)
B��C
A��C(1)
A��B
C��B(1)
A��C
B��A(1)
B��C
A��C(1)
*/

#endif

# if 0
#include <iostream>
using namespace std;

const int MAX = 64;		// Բ�̵ĸ������Ϊ64

struct st{				// ������ʾÿ�����ӵ���Ϣ
	int s[MAX];			// �����ϵ�Բ�̴洢���
	int top;			// ջ���������������Բ��
	char name;			// ���ӵ����֣�������A��B��C�е�һ��
	int Top()			// ȡջ��Ԫ��
	{
		return s[top];
	}
	int Pop()			// ��ջ
	{
		return s[top--];
	}
	void Push(int x)	// ��ջ
	{
		s[++top] = x;
	}
} ;

long Pow(int x, int y);				// ����x^y
void Creat(st ta[], int n);			// ���ṹ�������ó�ֵ
void Hannuota(st ta[], long max);	// �ƶ���ŵ������Ҫ����

int main(void)
{
	int n;
	cout << "����Բ�̵ĸ�����" << endl;
	cin >> n;					// ����Բ�̵ĸ���
	st ta[3];					// �������ӵ���Ϣ�ýṹ����洢
	Creat(ta, n);				// ���ṹ�������ó�ֵ
	long max = Pow(2, n) - 1;	// �ƶ��Ĵ���Ӧ����2^n - 1
	Hannuota(ta, max);			// �ƶ���ŵ������Ҫ����
	system("pause");
	return 0;
}

void Creat(st ta[], int n)
{
	ta[0].name = 'A';
	ta[0].top = n-1;
	
	for (int i=0; i<n; i++)		// �����е�Բ�̰��Ӵ�С��˳���������A��
		ta[0].s[i] = n - i;
	
	ta[1].top = ta[2].top = 0;	// ����B��C�Ͽ�ʼû��û��Բ��
	for (i=0; i<n; i++)
		ta[1].s[i] = ta[2].s[i] = 0;
	
	if (n%2 == 0)				// ��nΪż������˳ʱ�뷽�����ΰڷ� A B C
	{
		ta[1].name = 'B';
		ta[2].name = 'C';
	}
	else						// ��nΪ��������˳ʱ�뷽�����ΰڷ� A C B
	{
		ta[1].name = 'C';
		ta[2].name = 'B';
	}
}

long Pow(int x, int y)
{
	long sum = 1;
	for (int i=0; i<y; i++)
		sum *= x;
	return sum;
}

void Hannuota(st ta[], long max)
{
	int k = 0; //�ۼ��ƶ��Ĵ���
	int i = 0;
	int ch;
	while (k < max)
	{
		// ��˳ʱ�뷽���Բ��1�����ڵ������ƶ�����һ������
		ch = ta[i%3].Pop();
		ta[(i+1)%3].Push(ch);
		cout << ++k << ": " <<"Move disk " << ch << " from " << ta[i%3].name 
			 <<" to " << ta[(i+1)%3].name << endl;
		i++;
		// ���������������Ͽ����ƶ���Բ���ƶ����µ�������
		if (k < max)
		{	// �ѷǿ������ϵ�Բ���ƶ����������ϣ����������Ӷ�Ϊ��ʱ���ƶ���С��Բ��
			if (ta[(i+1)%3].Top() == 0 ||ta[(i-1)%3].Top() > 0  
				&&ta[(i+1)%3].Top() > ta[(i-1)%3].Top())
			{
				ch = ta[(i-1)%3].Pop();
				ta[(i+1)%3].Push(ch);
				cout << ++k << ": " << "Move disk "<< ch << " from " 
					 << ta[(i-1)%3].name<< " to " << ta[(i+1)%3].name << endl;
			}
			else
			{
				ch = ta[(i+1)%3].Pop();
				ta[(i-1)%3].Push(ch);
				cout << ++k << ": " << "Move disk "<< ch << " from " 
					 << ta[(i+1)%3].name<< " to " << ta[(i-1)%3].name << endl;
			}
		}
	}
}
#endif


/*
void han(int n,char a,char b,char c)
{
    if(n==1)
        printf("%d %c��%c *\n",n,a,c);
    else
    {
        han(n-1,a,c,b);
        printf("%d %c��%c\n",n,a,c);
        han(n-1,b,a,c);
    }
}
*/