#include <iostream>
#include <vector>
using namespace std;

int Fib ( int n ) 
{
    if(n <= 1)
	    return n; 
	int twoback = 0;
    int oneback = 1; 
	int Current;
    for(int i = 2; i <= n; i++)    
    {
        Current = twoback + oneback; 
	    twoback = oneback;
        oneback = Current;
    }
    return Current;
}

int fib_dp(int n);
vector<int> vec;
vector<int> ::iterator iter;
/*ÿһ�����ִ���һ�����ӣ�1��2��ʾһ��1��2���´�����ӣ�3��ʾ����3���´������
1
|
2
|
3��              1
|                 \
3��      1��       2
|         \         \
3��  1��   2��       3��      1
|     \     \         \        \
3�� 1��2��   3��   1�� 3��   1��2
|    \  \     \     \   \     \  \
3��1��2��3��1��3��1��2�� 3��1��2��3��1
*/
/*
��̬�滮�ǰ�ԭ����ֽ�Ϊ����Ϊ���������⣬Ȼ���Ե����ϣ��������С�������⣬�ѽ���洢�ڱ���У�
�������������ʱ��ֱ�Ӵӱ���в�ѯС��������Ľ⣬�����ظ����㡣
�����㷨���Զ�������������⣬�ϲ�������Ľ⣻
�ܲ��ö�̬�滮���������һ��Ҫ����3�����ʣ�
��1�������ӽṹ�������������Ž���������������Ľ�Ҳ�����ŵģ��ͳƸ�������������ӽṹ��
���������Ż�ԭ��
��2���޺�Ч�ԣ���ĳ�׶�״̬һ��ȷ�����Ͳ������״̬�Ժ���ߵ�Ӱ�졣Ҳ����˵��
ĳ״̬�Ժ�Ĺ��̲���Ӱ����ǰ��״̬��ֻ�뵱ǰ״̬�йء�
��3�����ص������⣺��������֮���ǲ������ģ�һ������������һ�׶ξ����п��ܱ����ʹ�õ���
�������ʲ����Ƕ�̬�滮���õı�Ҫ�������������û���������ʣ���̬�滮�㷨ͬ�����㷨��Ⱦ�
���߱����ƣ�
 */
int fib_dp_vector(int n)//쳲��������еĶ�̬�滮��vector��ʵ��
{
	vec.push_back(1);
	vec.push_back(1);
	
	if(n>2)
		for(int i=2; i<n; ++i)
			vec.push_back(vec[i-1]+vec[i-2]);
	return vec[n-2];
}
//output: 1 1 2 3 5 8 13 21 34 55 89 144

int fib_dp_arr(int n)//쳲��������еĶ�̬�滮������ʵ��
{
	if(n<1)
		return -1;
	int* arr = new int[n+1];
	arr[1]=1;
	arr[2]=1;
	for(int i=3;i<=n+1;i++)
		arr[i]=arr[i-1]+arr[i-2];
	return arr[n];
	delete [] arr;
}


int fib_recursive(int n)//쳲��������еĵݹ�ʵ��
{
	if(n==1 ||n==2)
		return 1;
	else 
		return (fib_recursive(n-1)+fib_recursive(n-2));
} 


int fib_iterative(int n) //쳲��������еĵ���ʵ��
{
	int fn, fn_1=1, fn_2=1;
	if(n==1 ||n==2)
		fn_1 = 1, fn_2 = 1;
	for (int i=3; i<=n; ++i)
	{
		fn = fn_1 + fn_2;
		fn_1 = fn_2; 
		fn_2 = fn;
	}
	return fn;
}
/*����
fn_1 fn_2 fn
     fn_1 fn_2 fn
r=b
loops
r = a%b
a b r
  a b r
*/

int additiveSequence(int n,int a, int b)
{
	if(n==0) return a;
	if(n==1) return b;
	return additiveSequence(n-1,b,a+b);
}

int fib(int n) // wrapper functions, as if provide default parameter
{
    return additiveSequence(n,0,1);
}

int main()
{
	int n;
	cout<<"�����µ����ӿ�ʼ��ֳ������n�µڷ�ֳ������������n��";
	cin>>n;
	fib_dp_vector(n);
	for(iter=vec.begin();iter!=vec.end();iter++)
		cout<<*iter<<" ";
	cout<<endl;
	cout<<fib_dp_arr(n)<<endl;
	//cout<<fib_recursive(n)<<endl;
	//cout<<fib_iterative(n)<<endl;
	cout<<additiveSequence(n,0,1)<<endl;
    cout<<fib(n)<<endl;
	cin.get();cin.get();
	return 0;
}