#include <iostream>
#include <algorithm> //sort()
using namespace std;
// Kruskal�㷨�������б߰�Ȩֵ��С��������󣬴���СȨֵ�ı߿�ʼ����Ȧ�ж�
const int N = 100;
												// �� ���ݽṹ
int nodeset[N];				//���Ϻţ�������ţ����飬���ڱ�Ȧ
int n, m;
struct Edge {				//�ߵĴ洢�ṹ(���������һ��Ȩֵ)
	int u;
	int v;
	int w;
}e[N*N];

												// �� ��ʼ��
void Init(int n)
{
	for(int i = 1; i <= n; i++)
		nodeset[i] = i;		//ÿ����㸳ֵһ�����Ϻţ�������ţ�
}
												// �� �������ȼ�������ֵ������������
bool comp(Edge x, Edge y)
{
	return x.w < y.w;		
}
												// �� �ϲ�����
int Merge(int a, int b)
{
	int p = nodeset[a];	//pΪa���ļ��Ϻţ�������ţ�
	int q = nodeset[b];	//qΪb���ļ��Ϻţ�������ţ�
	if(p==q) 
		return 0;			//���Ϻ���ͬ��ʲôҲ����������
	for(int i=1;i<=n;i++)	//������н�㣬�Ѽ��Ϻ���q��ȫ����Ϊp
	{
		if(nodeset[i]==q)
			nodeset[i] = p;	//a�ļ��ϺŸ�ֵ��b���Ϻ�
	}
	return 1;
}

int Kruskal(int n)
{
	int ans = 0;			//����ͨ�������ֵ��ͺ����Сֵ
	for(int i=0;i<m;i++)
		if(Merge(e[i].u, e[i].v)) //���ִ���˺ϲ�
		{
			ans += e[i].w;
			n--;
			cout<<e[i].u<<" - "<<e[i].v<<"��"<<e[i].w<<endl;
			if(n==1)
				return ans;
		}
		return 0;
}

int main()
{
	cout <<"��������n�ͱ���m��"<<endl;
	cin >> n >> m;
	Init(n);
	cout <<"���������u��v�ͱ�ֵw��"<<endl;
	for(int i=0;i<m;i++)
		cin >> e[i].u>> e[i].v >>e[i].w;
	sort(e, e+m, comp);		//����������������������׵�ַ��β��ַ������ʽ

	cout <<"��������Ľ�����u��v�ͱ�ֵw��"<<endl;
	for(int j=0;j<m;j++)
		cout<<e[j].u<<" - "<<e[j].v<<"��"<<e[j].w<<endl;
	cout<<"ѡ�еĸ��ߵ����������ź����ֵ��"<<endl;
	int ans = Kruskal(n);
	cout << "����ͨ�������ֵ��ͺ����Сֵ��" << ans << endl;
	system("pause");
	return 0;
}
/*
7 12
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
���

  ��������Ľ�����u��v�ͱ�ֵw��
  2 - 7��1
  4 - 5��3
  3 - 7��4
  4 - 7��9
  3 - 4��15
  5 - 7��16
  5 - 6��17
  2 - 3��20
  1 - 2��23
  6 - 7��25
  1 - 6��28
  1 - 7��36
  ѡ�еĸ��ߵ����������ź����ֵ��
  2 - 7��1
  4 - 5��3
  3 - 7��4
  4 - 7��9
  5 - 6��17
  1 - 2��23
  ����ͨ�������ֵ��ͺ����Сֵ��57
*/

int Find(int x)				//������
{
	if(x != nodeset[x])
		nodeset[x] = Find(nodeset[x]);
	//�ѵ�ǰ��㵽������·���ϵ����н��ļ��ϺŸ�Ϊ���ڼ��Ϻ�
	return nodeset[x];		//���������ڵļ��Ϻ�
}
int Merge2(int a, int b)		//�����ϲ����Ϻ�
{
	int p = Find(a);		//��a�ļ��Ϻ�
	int q = Find(b);		//��b�ļ��Ϻ�
	if(p==q) return 0;
	if(p > q)
		nodeset[p] = q;		//С�ļ��ϺŸ�ֵ����ļ��Ϻ�
	else
		nodeset[q] = p;
	return 1;
}