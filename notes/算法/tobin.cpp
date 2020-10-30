

#if 1
//λ������union���int��float�Ķ�����λ
#include <iostream>
using namespace std;

union { //���ڽ��������Ķ�����λ����Ϊintλ���
	float input;
	int output;
} data;

void int2binary(unsigned n)//λ����ֻ����������
{
	unsigned b32 = 1<<31;//32λ�����ƣ����λ��1������λ��0
	cout<<((n&b32)>>31)<<" ";//���λ�����㣬��λ�����λ���
	for(int i=1;i<32;++i)
	{
		n=n<<1;//ѭ������һλ���������λ��������
		cout<<((n&b32)>>31);//���λ�����㣬��λ�����λ���
		if(i==7)
			cout<<" ";
		if(i>8 && (i-7)%8==0)
			cout<<" ";
	}
	cout<<"\n";
}
void float2binary(unsigned n)
{
	unsigned b32 = 1<<31;//32λ�����ƣ����λ��1������λ��0
	cout<<((n&b32)>>31)<<" ";//���λ�����㣬��λ�����λ���
	for(int i=1;i<32;++i)
	{
		n=n<<1;//ѭ������һλ���������λ��������
		cout<<((n&b32)>>31);//���λ�����㣬��λ�����λ���
		if(i%8==0)
			cout<<" ";
	}
	cout<<"\n";
}
void main()
{
	while(1)
	{
		int n;
		cout<<"please input a int:";
		cin>>n;
		int2binary(n);
		cout<<endl;
		cout<<"please input a float:";
		cin>>data.input;
		float2binary(data.output);
		cout<<endl;
	}
}
/*
please input a int:178
0 0000000 00000000 00000000 10110010

please input a float:178.625
0 10000110 01100101 01000000 0000000


please input a int:-178
1 1111111 11111111 11111111 01001110

please input a float:-178.625
1 10000110 01100101 01000000 0000000

please input a int:134
0 0000000 00000000 00000000 10000110

please input a float:
10110010�Ľ�����7�����λ����1��ֱ�����ص���
����=����+ƫ����
=����+2^(e-1)-1
=����+2^(8-1)-1
=7+127
=134(10000110)


please input a int:178		
0 0000000 00000000 00000000 10110010	��������ԭ��	
		
please input a float:178.625		
0 10000110 01100101 01000000 0000000	��������1����λ+8����(ԭ��+����)+23β��	
	��β�������������λ1��ԭ�룩	
please input a int:-178		
1 1111111 11111111 11111111 01001110	�����������루ԭ��ȡ��+1��	
		
please input a float:-178.625		
1 10000110 01100101 01000000 0000000		
	178.625�Ľ�����㣺	
please input a int:134	����=����+ƫ����	
0 0000000 00000000 00000000 10000110	=����+2^(e-1)-1	
	=����+2^(8-1)-1	
please input a float:	=7+127	
	=134	
		

  */
#endif





#if 0
#include <iostream>
using namespace std;
union 
{
	float input;
	int output;
} data;
char flag;
void printbin1(int val)
{
	int len=sizeof(val)*8;
	for(int i=1;i<=len;++i)
	{
		if(val&(1<<len-i))
			printf("1");
		else
			printf("0");
		if(i%4==0)
			printf(" ");
	}
	printf("\n");
}void printbin2(int val)
{
	printf("������������λ+���루ָ��λ��+127��+β��λ\n");
	printf("%2s"," ");
	printf("����");
	printf("%6s"," ");
	printf("β��\n");
	int len=sizeof(val)*8;
	for(int i=1;i<=len;++i)
	{
		if(val&(1<<len-i))
			printf("1");
		else
			printf("0");
		if(i==1 || i==5 || i==9 || i==12)
			printf(" ");
		if(i>12)
			if(i%4==0)
				printf(" ");
	}
	printf("\n");
}
void main()
{
	while(1)
	{
		printf("\n����i��intת��Ϊ�����ƣ���178��\n");
		printf("����f��floatת��Ϊ�����ƣ���178.125:\n");
		scanf("%c",&flag);
		if(flag=='i')
		{
			printf("������һ��int��");
			int i;
			scanf("%d",&i);
			printbin1(i);
		}
		if(flag=='f')
		{
			printf("������һ��float��");
			float f;
			scanf("%f",&f);
			data.input = f;
			printbin2(data.output);
		}
		getchar();getchar();getchar();
	}
	
}

#endif
/*

����i��intת��Ϊ�����ƣ���178��
����f��floatת��Ϊ�����ƣ���178.125:
i
������һ��int��1
0000 0000 0000 0000 0000 0000 0000 0001

����i��intת��Ϊ�����ƣ���178��
����f��floatת��Ϊ�����ƣ���178.125:
f
������һ��float��1
������������λ+���루ָ��λ��+127��+β��λ
  ����      β��
0 0111 1111 000 0000 0000 0000 0000 0000

����i��intת��Ϊ�����ƣ���178��
����f��floatת��Ϊ�����ƣ���178.125:
i
������һ��int��178
0000 0000 0000 0000 0000 0000 1011 0010

����i��intת��Ϊ�����ƣ���178��
����f��floatת��Ϊ�����ƣ���178.125:
f
������һ��float��178.125
������������λ+���루ָ��λ��+127��+β��λ
  ����      β��
0 1000 0110 011 0010 0010 0000 0000 0000

����i��intת��Ϊ�����ƣ���178��
����f��floatת��Ϊ�����ƣ���178.125:
*/



#if(0) //�ݹ�
#include<stdio.h>
#include<stdlib.h>
void decToBin(int n, int base) {
	if (n>0) {
		decToBin(n/base,base);
		printf("%d", n%base);
	}
	
}
void main()
{
	decToBin(13,2);
	system("pause");
}
#endif
//1101
/*
f(13)
f(6)
f(3)
f(1)
1%2
3%2
6%2
13%2
*/

#if(0) //�ݹ�
#include<stdio.h>
#include<stdlib.h>
void dec2(unsigned long n,unsigned long base)
{
	int r;
	r=n%base; //���һλ
	if(n>=base)
		dec2(n/base,base);//�ݹ����ȳ����ص���ʺϵ�����㣻
	printf("%d",r);
}
int main()
{
	unsigned int i=0;
	dec2(13,2);
	system("pause");
	return 0;
}
#endif
/*
//1101

int r=1
n=11
dec2(5)
int r=1
n=5
dec2(2)
int r=0
n=2
dec2(2)
int r=1
n=1
*/


#if(0) //ʵ��ջ��ʮ���������������
#include<iostream>
using namespace std;
#define MAX_STACK_SIZE 100 /* ջ������С */
typedef int ElemType;
typedef struct sqstack
{ 
	ElemType stack_array[MAX_STACK_SIZE];
	int top;
	int bottom;
}SqStack;
SqStack Init_Stack(void)
{ 
	SqStack S;
	S.bottom=S.top=0; 
	return(S);
}
int push(SqStack &S, ElemType e) /* ʹ����Ԫ��e��ջ��Ϊ�µ�ջ�� */
{ 
	if(S.top==MAX_STACK_SIZE-1) 
		return -1; /* ջ��,���ش����־ */
	S.top++; /* ջ��ָ���1 */
	S.stack_array[S.top]=e; /* e��Ϊ�µ�ջ�� */
	return 0; /* ѹջ�ɹ� */
}
int pop(SqStack &S, ElemType *e) /*����ջ��Ԫ��*/
{ 
	if(S.top==0 )
		return -1; /* ջ��,���ش����־ */
	*e=S.stack_array[S.top]; 
	S.top--; 
	return 0; 
}
void conversion(int n, int d) /*��ʮ��������Nת��Ϊd(2��8)������*/
{ 
	SqStack S;
	ElemType e;
	int k;
	S=Init_Stack();
	/* ������е�����,��ջ */
	while(n>0) 
	{ 
		k=n%d; 
		push(S,k); 
		n=n/d; 
	} 
	while(S.top!=0) /* ջ����ʱ��ջ,��� */
	{ 
		pop(S,&e); 
		printf("%1d",e); 
	}
} 
void main()
{
	conversion(54,2);
	cout<<endl;
	conversion(54,8);
	cout<<endl;
	conversion(54,16);
	system("pause");
}
/*
110110
66
36
*/
#endif

#if(0) //����λ�������������ȡĳһλ
#include<stdio.h>
#include<stdlib.h>
void printbin1(unsigned char val)
{
	printf("%d:",val);
	for(int i=1;i<=8;++i)
		printf("%d",(val&(1<<8-i))>>(8-i));
	printf("\n");
}
void main()
{
	unsigned char i=13;
	printbin1(i);
	system("pause");
}
#endif

#if(0) //����λ�������������ȡĳһλ
#include<stdio.h>
#include<stdlib.h>
void printbin1(int val)
{
	printf("%d:",val);
	int len=sizeof(val)*8;
	for(int i=1;i<=len;++i)
		printf("%d",(val&(1<<len-i))>>(len-i));
	printf("\n");
}
void main()
{
	int i=256+13;
	printbin1(i);
	system("pause");
}
#endif


#if(0) //����λ�������������ȡĳһλ
#include<stdio.h>
#include<stdlib.h>
void printbin1(short int val)
{
	printf("%d:",val);
	int len=sizeof(val)*8;
	for(int i=1;i<=len;++i)
		//printf("%d",(val&(1<<len-i))>>(len-i));
		if(val&(1<<len-i))
			printf("1");
		else
			printf("0");
	printf("\n");
}
void main()
{
	short int i=256+64+13;
	printbin1(i);

	system("pause");
}
//�����333:0000000101001101
#endif

#if 0
#include <iostream>
using namespace std;
void main()
{
	while(1)
	{
		int n;
		cin>>n;//����б߽���
		int h=1;
		h=h<<31;//32λ�����λ1������λ��0
		
		for(int i=1;i<=32;i++)
		{
			if((n&h)==0)
				cout<<0;
			else cout<<1;
			n=n<<1; //����һλ����λ��0
			if(i%4==0)
				cout<<" ";
		}
		cout<<endl;
	}
 system("pause");
}
/*
43
0000 0000 0000 0000 0000 0000 0010 1011
-43
1111 1111 1111 1111 1111 1111 1101 0101
*/
#endif

#if 0
#include <iostream>
using namespace std;
union 
{
	float input;
	int output;
} data;
void main()
{
	data.input = 178.125;
	int h=1;
		h=h<<31;
		for(int i=1;i<=32;i++)
		{
			if((data.output&h)==0)
				cout<<0;
			else cout<<1;
			data.output<<=1;
			if(i%4==0)
				cout<<" ";
		}
		cout<<endl;
 system("pause");
}
//0100 0011 0011 0010 0010 0000 0000 0000
#endif



#if 0  //memcopy
#include <iostream>
#include <string.h>
using namespace std;

void main()
{
	float data;
	unsigned long buff;
	char s[34];
	data = (float)0.75;//���渡����Ĭ���ǰ�double����
	memcpy(&buff,&data,4);//�Ѹ���������Ķ�����λ���Ƹ�����������ĵ�ַ
	for(int i=33;i>=0;i--)//��λ���������Ķ�����λ
	{
		if(i==1 || i==10)
			s[i]=' ';
		else
		{
			if(buff%2==1)
				s[i] = '1';
			else
				s[i] = '0';
			buff/= 2;
		}
	}
	s[34] = '\0';
	cout<<s;	//0 01111110 10000000000000000000000
    system("pause");
}

#endif

#if 0
	unsigned short a;
	printf("������һ��������");
	scanf("%u",&a);
	int b = 1<<15;
	printf("%u=",a);
	for(int i =1;i<=16;i++)
	{
		putchar(a&b?'1':'0');
		a<<=1;
		if(i%4==0)
			putchar(',');
	}
	printf("\bB\n");
#endif

#if 0
	//union���bitset����������Ķ�����λ
#include <iostream>
#include <bitset>
using namespace std;

union { //���ڽ��������Ķ�����λ����Ϊintλ���
	float input;
	int output;
} data;


void float2binary(unsigned n)
{
	unsigned b32 = 1<<31;//32λ�����ƣ����λ��1������λ��0
	cout<<((n&b32)>>31)<<" ";//���λ�����㣬��λ�����λ���
	for(int i=1;i<32;++i)
	{
		n=n<<1;//ѭ������һλ���������λ��������
		cout<<((n&b32)>>31);//���λ�����㣬��λ�����λ���
		if(i%8==0)
			cout<<" ";
	}
	cout<<"\n";
}
void main()
{
	while(1)
	{
		cout<<"please input a float:";
		cin>>data.input;
		bitset<32> bs(data.output);//�������ŵ�һ��32λ��λ������
		cout<<bs<<endl;
	}
}
#endif