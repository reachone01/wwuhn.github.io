#include <iostream>			// Prim�㷨(����ķ)
#include <iomanip>
using namespace std;
const int INF = 0x3fffffff;
const int N = 100;
int map[N][N]; 	// ��Ȩ�ڽӾ���
bool s[N];		// ���㼯��V�����s[i]=true,˵������i�Ѽ�����С�������Ķ��㼯��U��
				// ���򶥵�i���ڼ���V-U����������������ѡ����С�����ӱ�
int closest[N];	// closest[j]��ʾV-U�еĶ��㵽U�е�����ڽӵ�
int lowcost[N];	// lowcost[j]��ʾV-U�еĶ��㵽U�е�����ڽӵ�ı�ֵ������(closet[j],j)��Ȩֵ


void Prim(int n, int u0)//�������n����ʼ����u0����Ȩ�ڽӾ���C[n][n]
{	
	int i,j;		// ѭ������
	s[u0] = true;	// (1) ��ʼ������ʼʱ��������Uֻ��һ��Ԫ�أ�������u0
	for(i = 1; i <= n; i++)			// ��
	{
		if(i != u0)
		{
			lowcost[i] = map[u0][i];
			closest[i] = u0;
			s[i] = false;
		}
		else
			lowcost[i] =0;
	}
	for(i = 1; i <= n; i++)			// (2) �ڼ���V-U��Ѱ�Ҿ��뼯��U����Ķ���t
	{
		int temp = INF;
		int t = u0;
		for(int j = 1; j <= n; j++)	// ��
		{
			if((!s[j]) && (lowcost[j] < temp))
			{
				t = j;
				temp = lowcost[j];	// temp�˴����£�ѭ���Ƚ�
			}
		}
		if(t == u0)
			break;					// �Ҳ���t������ѭ��
		s[t] = true;				// ���򣬽�t���뼯��U (3) ���ϸ���
		for(j = 1; j <= n; j++)		// (4) ������£�����lowcost��closest
		{
			if((!s[j]) && (map[t][j] < lowcost[j]))
			{
				lowcost[j] = map[t][j]; // ������������ʽ�ıȽϱ�׼
				closest[j] = t;
			}
		}
	}
}
void printMatrix(int n)	// ���ͼ�Ĵ�Ȩ�ڽӾ���
{
	cout <<"�������map��"<<endl;
	cout<<"\t";
	int i,j;						// ѭ������
	for(i=1;i<=n;++i)				// ����б���
		cout<<"\t"<<i;
	cout<<endl;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=i;j++)
		{
			if(j==1)				// ����б���
				cout << "\t" << i;
			if(map[i][j]==INF) 
				cout << "\t" << "��";
			else 
				cout << "\t" << map[i][j];
			if(j==i) 
				cout<<endl;
		}
	}
}

void initMatrix(int& n, int& m)
{
	int u, v, w;
	cout <<"��������n�ͱ���m��"<<endl;
	cin >> n >> m;
	
	int i,j; // ѭ������
	for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++)
			map[i][j] = INF;
	cout <<"������u��v�ͱ�ֵw��"<<endl;
	for(i=1; i<=m; i++)
	{
		cin >> u >> v >> w;
		map[u][v] = map[v][u] = w;
	}
}

void output(int n)
{
	int i; //ѭ������
	cout <<"��š�����colesest��lowcost��ֵΪ��"<<endl;
	for(i = 1; i <= n; i++)
		cout<<setw(4) << i;
	cout<<"\n";
	for(i = 1; i <= n; i++)
		cout<<setw(4)<<closest[i];
	cout<<"\n";
	for(i = 1; i <= n; i++)
		cout<<setw(4) << lowcost[i];
	cout << endl;
	int sumcost = 0;
	for(i = 1; i <= n; i++)
		sumcost += lowcost[i];
	cout << "��С�Ļ����ǣ�" << sumcost << endl << endl;
}

int main()
{
	int n, m,u0;
	initMatrix(n, m);
	cout <<"������һ���u0��"<<endl;
	cin >> u0 ;

	printMatrix(n);
	Prim(n, u0);

	output(n);
	system("pause");
	return 0;
}
/* ����ʱ���ɸ���ճ��
7
12
1 2 23
1 6 28
1 7 36
2 3 20
2 7 1
3 4 15
3 7 4
4 5 3
4 7 9
5 6 17
5 7 16
6 7 25
1


 */

/*output
��������n�ͱ���m��
7
12
��������u��v�ͱ�ֵw��
1 2 23
1 6 28
1 7 36
2 3 20
2 7 1
3 4 15
3 7 4
4 5 3
4 7 9
5 6 17
5 7 16
6 7 25
������һ���u0��
1
�������map��
                1       2       3       4       5       6       7
        1       ��
        2       23      ��
        3       ��      20      ��
        4       ��      ��      15      ��
        5       ��      ��      ��      3       ��
        6       28      ��      ��      ��      17      ��
        7       36      1       4       9       16      25      ��
��š�����colesest��lowcost��ֵΪ��
   1   2   3   4   5   6   7
   0   1   7   7   4   5   2
   0  23   4   9   3  17   1
��С�Ļ����ǣ�57

�밴���������. . .
*/

/*
1 ��ͼ����ԭͼ��ѡȡһЩ����ͱ���ɵ�ͼ����Ϊԭͼ����ͼ
2 ������ͼ��ѡ��һЩ�ߺ����ж�����ɵ�ͼ����Ϊԭͼ��������ͼ
2 ��������������ɵ���ͼǡ����һ���������Ϊ��������
3 ��С��������Ȩֵ֮����С�������������Ϊ��С��������
�ҳ�n-1��Ȩֵ��С�ı߲�Ҫ��֤û�л�·

*/