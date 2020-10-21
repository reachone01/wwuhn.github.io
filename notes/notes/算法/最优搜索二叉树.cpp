/*
int arr[6]={5,9,12,15,20,24}
��������һ���������У��۰���ҿɻ��logn��Ч�ʣ�
�������������л�Ҫ���ǲ���ÿ�������ֵ�Ƶ�ʣ����£�
ÿ���ؼ��ֵ���������:   0.04 0.09 0.08 0.02 0.12 0.14
ÿ���������������:0.06 0.08 0.10 0.07 0.05 0.05 0.10 
//��Ҫ����18����λ��15��20֮�䣬ÿ��������λ�ö���Ϊһ�����㣬Ҫ��Ӧһ����������
��������Ϊ����*100
���
0          12
        /       \
1     9        14
     /    \     / \
2   4      8   5  10
   / \    / \
3 6   8  10  2
         / \ 
4       7   5

ÿ���ؼ��ֽڵ�������ɱ�����*(���-1)
ÿ����    �ڵ�������ɱ�����*���
���ܺܶ��˻��뵽���������ʴ�����Խ������ô�ܳɱ�Խ�ͣ�����ʵ�ǹ�����˼�롣
���Ƕ�����������Ҫ����������<����������>�������ʣ�
1 ���������ӽ�ṹ���ص����ʣ�����Ӧ�ö�̬�滮�㷨����⣻
2 
*/
#include<iostream>
#include<cmath>   //�����ֵ������Ҫ�����ͷ�ļ�
using namespace std;

const int M=1000+5;
double p[M],q[M];	// ʵ��㡢�������������
double c[M][M];		// T(i,j)�������ɱ�
double w[M][M];		// T(i,j)�������ɱ���

int s[M][M];		// T(i,j)�ĸ��ڵ����
int n,i,j,k;
void Optimal_BST()
{
	for(i=1;i<=n+1;i++)
	{
		c[i][i-1]=0.0;
		w[i][i-1]=q[i-1];
	}
	for(int t=1;t<=n;t++)//tΪ�ؼ��ֵĹ�ģ
		//���±�Ϊi��ʼ�Ĺؼ��ֵ��±�Ϊj�Ĺؼ���
		for(i=1;i<=n-t+1;i++)
		{
			j=i+t-1;
			w[i][j]=w[i][j-1]+p[j]+q[j];
			int i1=s[i][j-1]>i?s[i][j-1]:i;
            int j1=s[i+1][j]<j?s[i+1][j]:j;
			c[i][j]=c[i][i1-1]+c[i1+1][j];//��ʼ��
			s[i][j]=i1;//��ʼ��
			//ѡȡi1+1��j1֮���ĳ���±�Ĺؼ�����Ϊ��i��j�ĸ��������ɵ���������ֵ��ǰ��С����kΪ��i��j�ĸ��ڵ�
			for(k=i1+1;k<=j1;k++)
			{
				double temp=c[i][k-1]+c[k+1][j];
                if(temp<c[i][j]&&fabs(temp-c[i][j])>1E-6)//C++�и�������Ϊ�������ⲻ����ֱ�ӱȽ�
				{
					c[i][j]=temp;
					s[i][j]=k;//k��Ϊ���±�i��j�ĸ��ڵ�
				}
			}
			c[i][j]+=w[i][j];
		}
}
void Construct_Optimal_BST(int i,int j,bool flag)
{
	if(flag==0)
	{
		cout<<"S"<<s[i][j]<<" �Ǹ�"<<endl;
		flag=1;
	}
	int k=s[i][j];
	//�����������Ҷ��
	if(k-1<i)
	{
		cout<<"e"<<k-1<<" is the left child of "<<"S"<<k<<endl;
	}
	//�������������Ҷ��
	else
	{
		cout<<"S"<<s[i][k-1]<<" is the left child of "<<"S"<<k<<endl;
		Construct_Optimal_BST(i,k-1,1);
	}
	//�����������Ҷ��
	if(k>=j)
	{
		cout<<"e"<<j<<" is the right child of "<<"S"<<k<<endl;
	}
	//�������������Ҷ��
	else
	{
		cout<<"S"<<s[k+1][j]<<" is the right child of "<<"S"<<k<<endl;
		Construct_Optimal_BST(k+1,j,1);
	}
}
int main()
{
	cout << "������ؼ��ֵĸ��� n:";
    cin >> n;
    cout<<"����������ÿ���ؼ��ֵ���������:";
    for (i=1; i<=n; i++ )
        cin>>p[i];
    cout << "����������ÿ���������������:";
    for (i=0; i<=n; i++)
        cin>>q[i];
	Optimal_BST();
	// /*���ڲ���
	for(i=1; i<=n+1;i++)
    {
          for (j=1; j<i;j++)
            cout <<"\t" ;
          for(j=i-1;j<=n;j++)
            cout << w[i][j]<<"\t" ;
          cout << endl;
    }
     for(i=1; i<=n+1;i++)
    {
          for (j=1; j<i;j++)
            cout <<"\t" ;
          for(j=i-1; j<=n;j++)
            cout << c[i][j]<<"\t" ;
          cout << endl;
    }
    for(i=1; i<=n;i++)
    {
          for (j=1; j<i;j++)
            cout << "\t" ;
          for(j=i-1; j<=n;j++)
            cout << s[i][j]<<"\t" ;
          cout << endl;
    }
    cout << endl;
    // */���ڲ���
	cout<<"��С�������ɱ�Ϊ:"<<c[1][n]<<endl;
    cout<<"���Ŷ���������Ϊ:";
	Construct_Optimal_BST(1,n,0);
	system("pause");
	return 0;
}
/*
6
0.04 0.09 0.08 0.02 0.12 0.14
0.06 0.08 0.10 0.07 0.05 0.05 0.10


������ؼ��ֵĸ��� n:6
����������ÿ���ؼ��ֵ���������:0.04 0.09 0.08 0.02 0.12 0.14
����������ÿ���������������:0.06 0.08 0.10 0.07 0.05 0.05 0.10
0.06    0.18    0.37    0.52    0.59    0.76    1
        0.08    0.27    0.42    0.49    0.66    0.9
                0.1     0.25    0.32    0.49    0.73
                        0.07    0.14    0.31    0.55
                                0.05    0.22    0.46
                                        0.05    0.29
                                                0.1
0       0.18    0.55    0.95    1.23    1.76    2.52
        0       0.27    0.67    0.9     1.38    2.09
                0       0.25    0.46    0.94    1.48
                        0       0.14    0.45    0.98
                                0       0.22    0.68
                                        0       0.29
                                                0
0       1       2       2       2       3       5
        0       2       2       3       3       5
                0       3       3       3       5
                        0       4       5       5
                                0       5       6
                                        0       6

��С�������ɱ�Ϊ:2.52
���Ŷ���������Ϊ:S5 �Ǹ�
S2 is the left child of S5
S1 is the left child of S2
e0 is the left child of S1
e1 is the right child of S1
S3 is the right child of S2
e2 is the left child of S3
S4 is the right child of S3
e3 is the left child of S4
e4 is the right child of S4
S6 is the right child of S5
e5 is the left child of S6
e6 is the right child of S6
�밴���������. . .
*/