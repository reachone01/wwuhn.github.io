#include <iostream> //ʹ�����ȶ��н��й����������
#include <queue>
#include <windows.h>//min()��
#include <stack>	//������·��
using namespace std;
//������������������������������1 ���ݽṹ������������������������������������������
const int N = 100;	//���еĸ������޸�
const int INF = 1e7;//��ʼ�������Ϊ10000000
int map[N][N];		//��Ȩ�ڽӾ��󣬱�ʾͼ�����ݽṹ
int n,m;			//n��ʾ���еĸ�����mΪ���м�·�ߵ�����
int dist[N];		//��ʾ��Դ��u������j�����·������Ϊdist[j]
int p[N];			//��ʾ��Դ��u������j�����·����ǰ���ڵ�Ϊp[j]								//
bool flag[N];		//���flag[i]����true��˵������i�Ѿ����뵽����S;���򶥵�i���ڼ���V-S
					// ����V��ʾȫ�����㣬����S��̰�Ĳ��������������·������

struct Node{
	int u,step; //uΪ���㣬stepΪԴ�㵽����u�����·��
	Node(){};
	Node(int a,int sp){
		u=a;step=sp;
	}
	bool operator<(const Node& a)const{	// ���� <
		return step>a.step;
	}
};

void Dijkstra(int st){
	for(int i=1; i<=n; i++)		// ��
	{
		dist[i]=INF;						// ��ʼ�����о���Ϊ�������
		if(dist[i]==INF)
			p[i]=-1;			//Դ��u���ö����·������Ϊ�����˵������i��Դ��u������
		else
			p[i]=st;				//˵������i��Դ��u���ڣ����ö���i��ǰ��p[i]=u
	}
	priority_queue <Node> Q;				// ���ȶ����Ż�
	Q.push(Node(st,0));
	memset(flag,0,sizeof(flag));			// ��ʼ��flag����Ϊ0

	dist[st]=0;
	while(!Q.empty())
	{
		Node it=Q.top();					//���ȶ��ж�ͷԪ��Ϊ��Сֵ
		Q.pop();
		int t=it.u;
		if(flag[t])							//˵���Ѿ��ҵ�����̾��룬�ý���Ƕ���������ظ�Ԫ��
			continue;
		flag[t]=1;
		for(int i=1;i<=n;i++)
		{
			if(!flag[i]&&map[t][i]<INF){	// �ж��뵱ǰ���й�ϵ�ĵ㣬�����Լ����ܵ��Լ�
				if(dist[i]>dist[t]+map[t][i])
				{							// ����뵱ǰ���ÿ�������̾���,�����ɳڲ���
					dist[i]=dist[t]+map[t][i];
					Q.push(Node(i,dist[i]));// �Ѹ��º����̾���ѹ�����ȶ��У�ע�⣺�����Ԫ�����ظ�
					p[i]=t;
				}
			}
		}
	}
}
void findpath(int u)				// Դ�㵽��������������·��
{
	int x;							// ǰ��
	stack<int>s;					// ���ÿ�<stack>����һ��ջs
	for(int i=1;i<=n;i++)
	{
		x=p[i];
		while(x!=-1)
		{
			s.push(x);				//��ǰ������ѹ��ջ��
			x=p[x];
		}
		cout<<"Դ��"<<u<<"������"<<i<<"����̾���Ϊ��";
		if(dist[i] == INF)
			cout << "sorry,��·�ɴ�"<<endl;
		else
		{
			cout <<dist[i];
			cout<<"��\t·��Ϊ��";
			while(!s.empty())
			{
				cout<<s.top()<<"��";	//����ȡջ��Ԫ��
				s.pop();				//��ջ
			}
			cout<<i<<endl;
		}
	}
}
void printmatrix(int n)					// ���ͼ�Ĵ�Ȩ�ڽӾ���
{
	cout <<"�������map��"<<endl;
	cout<<"\t";
	for(int k=1;k<=n;++k)
		cout<<"\t"<<k;
	cout<<endl;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(j==1) 
			{
				cout << "\t" << i;
			}
			if(map[i][j]==INF) 
				cout << "\t" << "��";
			else 
				cout << "\t" << map[i][j];
			if(j==n) 
			{
				cout<<endl;
			}
		}
	}
}
void initmatrix(int m,int n)
{
	int u,v,w;
	for(int i=1;i<=n;i++)					//��ʼ��ͼ���ڽӾ���
		for(int j=1;j<=n;j++)
		{
			map[i][j]=INF;					//��ʼ���ڽӾ���Ϊ�����
		}
	while(m--)
	{
		cin >> u >> v >> w;
		map[u][v] =min(map[u][v],w);		//�ڽӾ��󴢴棬������С�ľ���
	}
}
int main()
{
	cout << "��������еĸ�����"<<endl;
	cin >> n;
	cout << "���������֮���·�ߵĸ�����"<<endl;
	cin >>m;
	cout << "���������֮���·���Լ����룺"<<endl;
	initmatrix(m,n);
	
	int st;
	cout<<"������С�����ڵ�λ�ã�"<<endl; ;
	cin>>st;
	printmatrix(n);
	Dijkstra(st);
	for(int k=1;k<=n;k++){
		cout <<"С����"<<st<<" to "<<k;
		if(dist[k] == INF)
			cout << "����̾���Ϊ:sorry,��·�ɴ�"<<endl;
		else
			cout << "����̾���Ϊ��"<<dist[k]<<endl;
	}
	findpath(st);						//����int p[N];
	system("pause");
	return 0;
}
/*
5
8
1 2 2
1 3 5
2 3 2
2 4 6
3 4 7
3 5 1
4 3 2
4 5 5
1
*/
/*output:
��������еĸ�����
5
���������֮���·�ߵĸ�����
8
���������֮���·���Լ����룺
1 2 2
1 3 5
2 3 2
2 4 6
3 4 7
3 5 1
4 3 2
4 5 5
������С�����ڵ�λ�ã�
1
�������map��
                1       2       3       4       5
        1       ��      2       5       ��      ��
        2       ��      ��      2       6       ��
        3       ��      ��      ��      7       1
        4       ��      ��      2       ��      5
        5       ��      ��      ��      ��      ��
С����1 to 1����̾���Ϊ:0
С����1 to 2����̾���Ϊ:2
С����1 to 3����̾���Ϊ:4
С����1 to 4����̾���Ϊ:8
С����1 to 5����̾���Ϊ:5
Դ��1������1����̾���Ϊ��0��   ·��Ϊ��1
Դ��1������2����̾���Ϊ��2��   ·��Ϊ��1��2
Դ��1������3����̾���Ϊ��4��   ·��Ϊ��1��2��3
Դ��1������4����̾���Ϊ��8��   ·��Ϊ��1��2��4
Դ��1������5����̾���Ϊ��5��   ·��Ϊ��1��2��3��5
�밴���������. . .
*/