#include <iostream>		// Huffman Tree and Code
using namespace std;

#define MAXBIT 100
#define MAXVALUE 10000
#define MAXLEAF 30
#define MAXNODE MAXLEAF*2 -1

typedef struct		// ���ṹ��
{
	double weight;	// Ȩֵ
	int parent;
	int lchild;
	int rchild;
	char value;		// �ýڵ��ʾ���ַ�
}HNodeType;

typedef struct		// ����ṹ��
{
	int bit[MAXBIT];// ��Ž�����
	int start;		// ���뿪ʼ�±�
}HCodeType;

HNodeType HuffNode[MAXNODE];	// ����һ�����ṹ������
HCodeType HuffCode[MAXLEAF];	// ����һ������ṹ������
//�������������������������������������������������������������������������
void HuffmanTree(HNodeType HuffNode[MAXNODE], int n)
{
	int i, j;		// ѭ������
	int x1, x2;		// �������������ͬ������������СȨֵ����������е����
	double m1,m2;	// �������������ͬ������������СȨֵ����Ȩֵ
	for(i=0; i<2*n-1; i++)		// ��ʼ����Ź����������� HuffNode[] �еĽ��
	{
		HuffNode[i].weight = 0;	//Ȩֵ
		HuffNode[i].parent =-1;
		HuffNode[i].lchild =-1;
		HuffNode[i].rchild =-1;
	}
	
	for(i=0; i<n; i++)			// ���� n ��Ҷ�ӽ���Ȩֵ
	{
		cout<<"Please input value and weight of leaf node "<<i + 1<<endl;
		cin>>HuffNode[i].value>>HuffNode[i].weight;
	}
	
	for(i=0; i<n-1; i++)		// ���� Huffman ����ִ��n-1�κϲ�
	{
		m1=m2=MAXVALUE;			// m1��m2�д�������޸�����ҽ��Ȩֵ��С���������
		x1=x2=-1;	// �ҳ����н����Ȩֵ��С���޸�����������㣬���ϲ�֮Ϊһ�ö�����
		for(j=0; j<n+i; j++)
		{
			if(HuffNode[j].weight < m1 && HuffNode[j].parent==-1)
			{
				m2 = m1;
				x2 = x1;
				m1 = HuffNode[j].weight;
				x1 = j;
			}
			else if(HuffNode[j].weight < m2 && HuffNode[j].parent==-1)
			{
				m2=HuffNode[j].weight;
				x2=j;
			}
		}						// �����ҵ��������ӽ�� x1��x2 �ĸ������Ϣ
		
		HuffNode[x1].parent = n+i;
		HuffNode[x2].parent = n+i;
		HuffNode[n+i].weight = m1+m2;
		HuffNode[n+i].lchild = x1;
		HuffNode[n+i].rchild = x2;
		cout<<"x1.weight and x2.weight in round "<<i+1<<"	"; // ���ڲ���
		cout<<HuffNode[x1]. weight<<"	"<<HuffNode[x2].weight<<endl;
	}
}
//������������������������������������������������������������������������
void HuffmanCode(HCodeType HuffCode[MAXLEAF], int n)
{
	HCodeType cd;				// ����һ����ʱ���������������ʱ����Ϣ
	int i,j,c,p;
	for(i = 0;i < n; i++)		// ��0�Ž�㿪ʼ�������㹹����i����������
	{
		cd.start = n-1;			// ÿ�����ı���������������һ��Ԫ�ؿ�ʼ����
		c = i;
		p = HuffNode[c].parent;	// �Ҹ����
		while(p != -1)			// p=-1ʱΪ�����
		{
			if(HuffNode[p].lchild == c)	// ������Ϊ0��������Ϊ1
				cd.bit[cd.start] = 0;
			else
				cd.bit[cd.start] = 1;
			cd.start--;					// �����ĵ�һλ
			c = p;						// c,p���������ƣ�׼����һ��ѭ��
			p = HuffNode[c].parent;		// ������һѭ������
		}
		// ��Ҷ�ӽ��ı�����Ϣ����ʱ����cd�и��Ƴ������������ṹ������
		for(j=cd.start+1; j<n; j++)
			HuffCode[i].bit[j] = cd.bit[j];
		HuffCode[i].start = cd.start;
	}
}

int main()
{
	int i,j,n;
	cout<<"Please input n��"<<endl;
	cin>>n;
	HuffmanTree(HuffNode, n);	// �����������
	HuffmanCode(HuffCode, n);	// ������������
	
	for(i = 0;i < n;i++)		// ����ѱ���õ����д��ڱ���Ĺ���������
	{
		cout<<HuffNode[i].value<<": Huffman code is: ";
		for(j=HuffCode[i].start+1; j < n; j++)
			cout<<HuffCode[i].bit[j];
		cout<<endl;
	}
	system("pause");
	return 0;
}
/*
����
6
a 0.05
b 0.32
c 0.18
d 0.07
e 0.25
f 0.13

    t5
   /   \
  t3   t4
 / \   / \
c  e  t2  b
      / \
     t1  f
     / \
    a  d

Please input n��

6

Please input value and weight of leaf node 1

a 0.05

Please input value and weight of leaf node 2

b 0.32

Please input value and weight of leaf node 3

c 0.18

Please input value and weight of leaf node 4

d 0.07

Please input value and weight of leaf node 5

e 0.25

Please input value and weight of leaf node 6

f 0.13

���
x1.weight and x2.weight in round 1 0.05 0.07
x1.weight and x2.weight in round 2 0.12 0.13
x1.weight and x2.weight in round 3 0.18 0.25
x1.weight and x2.weight in round 4 0.25 0.32
x1.weight and x2.weight in round 5 0.43 0.57
a: Huffman code is: 1000
b: Huffman code is: 11
c: Huffman code is: 00
d: Huffman code is: 1001
e: Huffman code is: 01
f: Huffman code is: 101
a  0.05  1000
b  0.32  11
c  0.18  00
d  0.07  1001
e  0.25  01
f  0.13  101
*/