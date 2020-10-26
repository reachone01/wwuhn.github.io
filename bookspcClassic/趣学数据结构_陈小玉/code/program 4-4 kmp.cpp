/***KMP�㷨***/
#include<iostream>
#include<cstring>
using namespace std;

#define Maxsize 100

typedef char SString[Maxsize+1];//0�ŵ�Ԫ��Ŵ��ĳ���

bool StrAssign(SString &T,char *chars)//����һ����ֵ����chars�Ĵ�T
{
	int i;
	if(strlen(chars)>Maxsize)
		return false;
	else
    {
		T[0]=strlen(chars);
		for(i=1;i<=T[0];i++)
        {
            T[i]=*(chars+i-1);
            cout<<T[i]<<"  ";
        }
        cout<<endl;
		return true;
	}
}

int Index_BF(SString S,SString T,int pos) // BF�㷨
{ 	// ��T������S�е�pos���ַ�֮���һ�γ��ֵ�λ��
	// ���У�T�ǿգ�1��pos��s[0],s[0]���S���ĳ���
	int i=pos,j=1,sum=0;
	while(i<=S[0]&&j<=T[0])
    {
        sum++;
        if(S[i]==T[j]) // �����ȣ�������ȽϺ�����ַ�
		{
			i++;
			j++;
		}
		else
		{
			i=i-j+2; // i�˻ص���һ�ֿ�ʼ�Ƚϵ���һ���ַ�
			j=1;     // j�˻ص���1���ַ�
		}
    }
	cout<<"һ���Ƚ���"<<sum<<"��"<<endl;
	if(j>T[0])      // ƥ��ɹ�
		return i-T[0];
	else
		return 0;
}


void get_next(SString T,int next[]) //����next����ֵ
{
	int j=1,k=0;
	next[1]=0;
	while(j<T[0])      // ��̬�滮
	{
	    if(k==0||T[j]==T[k])
            next[++j]=++k;
		else
			k=next[k]; // �±�k�Ļ���
	}
    cout<<"-----next[]-------"<<endl;
    for(j=1;j<=T[0];j++)
        cout<<next[j]<<"  ";
    cout<<endl;
}

void get_next2(SString T,int next[]) // ����next����ֵ�Ľ��㷨
{
	int j=1,k=0;
	next[1]=0;
	while(j<T[0])
	{
	    if(k==0||T[j]==T[k])
        {
            j++;
            k++;
            if(T[j]==T[k])
                next[j]=next[k];
            else
                next[j]=k;
        }
		else
			k=next[k];
	}
    cout<<"-----next[]-------"<<endl;
    for(j=1;j<=T[0];j++)
        cout<<next[j]<<"  ";
    cout<<endl;
}

int Index_KMP(SString S,SString T,int pos,int next[]) // KMP�㷨
{ 	// ����ģʽ��T��next������T������S�е�pos���ַ�֮���λ�õ�KMP�㷨
	// ���У�T�ǿգ�1��pos��StrLength(S)
	int i=pos,j=1,sum=0;
	while(i<=S[0]&&j<=T[0])
    {
        sum++;
        if(j==0||S[i]==T[j]) // �����ȽϺ�����ַ�
		{
			i++;
			j++;
		}
		else
			j=next[j];       // ģʽ�������ƶ�
    }
	cout<<"һ���Ƚ���"<<sum<<"��"<<endl;
	if(j>T[0])               // ƥ��ɹ�
		return i-T[0];
	else
		return 0;
}

int main()
{
	SString S,T;
	char str[100];
    cout<<"��S��"<<"  ";
    cin>>str;        // abaabaabeca
	StrAssign(S,str);// �����޸ĳ����Լ������ַ��� 
    cout<<"��T��"<<"  ";
    cin>>str;        // abaabe
	StrAssign(T,str);
	int *p=new int[T[0]+1]; // ����T��next����
	cout<<endl;
	cout<<"BF�㷨���н����"<<endl;
	cout<<"�������Ӵ��ڵ�"<<Index_BF(S,T,1)<<"���ַ����״�ƥ��\n";
	cout<<endl;
	cout<<"KMP�㷨���н����"<<endl;
	get_next(T,p);
	cout<<"�������Ӵ��ڵ�"<<Index_KMP(S,T,1,p)<<"���ַ����״�ƥ��\n";
	cout<<endl;
	cout<<"�Ľ���KMP�㷨���н����"<<endl;
    get_next2(T,p);
	cout<<"�������Ӵ��ڵ�"<<Index_KMP(S,T,1,p)<<"���ַ����״�ƥ��\n";
	cin.get();cin.get();
	return 0;
}
/*
��S��  abaabaabeca
a  b  a  a  b  a  a  b  e  c  a
��T��  abaabe
a  b  a  a  b  e

BF�㷨���н����
һ���Ƚ���15��
�������Ӵ��ڵ�4���ַ����״�ƥ��

KMP�㷨���н����
-----next[]-------
0  1  1  2  2  3
һ���Ƚ���10��
�������Ӵ��ڵ�4���ַ����״�ƥ��

�Ľ���KMP�㷨���н����
-----next[]-------
0  1  0  2  1  3
һ���Ƚ���10��
�������Ӵ��ڵ�4���ַ����״�ƥ��

*/