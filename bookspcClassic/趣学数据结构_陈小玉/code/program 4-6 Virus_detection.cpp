/***��������㷨***/
#include<cstring>
#include<iostream>
using namespace std;

#define Maxsize 100

typedef char SString[Maxsize+1];		//0�ŵ�Ԫ��Ŵ��ĳ���

bool StrAssign(SString &T, char *chars)//����һ����ֵ����chars�Ĵ�T
{
	int i;
	if(strlen(chars)>Maxsize)
		return false;
	else
    {
		T[0]=strlen(chars);//0�ŵ�Ԫ��Ŵ��ĳ���
		for(i=1;i<=T[0];i++)
        {
            T[i]=*(chars+i-1);
            cout<<T[i]<<"  ";
        }
        cout<<endl;
		return true;
	}
}

void get_next(SString T,int next[])//����next����ֵ
{
	int j=1,k=0;
	next[1]=0;
	while(j<T[0])
	{

	    if(k==0||T[j]==T[k])
            next[++j]=++k;
		else
			k=next[k];
	}
}

int Index_KMP(SString S, SString T, int pos)//KMP�㷨
{ 	// ����ģʽ��T��next������T������S�е�pos���ַ�֮���λ�õ�KMP�㷨
	//���У�T�ǿգ�1��pos��StrLength(S)
	int *next=new int[T[0]+1]; // ����T��next����
	get_next(T,next);
	int i=pos, j=1;
	while(i<=S[0]&&j<=T[0])
    {
        if(j==0||S[i]==T[j]) // �����ȽϺ�����ַ�
		{
			i++;
			j++;
		}
		else
			j=next[j]; // ģʽ�������ƶ�
    }
	if(j>T[0]) // ƥ��ɹ�
		return i-T[0];
	else
		return 0;
}

bool Virus_detection(SString S, SString T) // �������
{
    int i,j;
    SString temp;                    // temp��¼��������
    for(i=T[0]+1,j=1;j<=T[0];i++,j++)// ��T������һ����T[0]Ϊ��������
        T[i]=T[j];
    for(i=0;i<T[0];i++)        // ���μ��T[0]����������
    {
        temp[0]=T[0];          // �������ֳ���ΪT[0]
        for(j=1;j<=T[0];j++)   // ȡ��һ����������
            temp[j]=T[i+j];
        if(Index_KMP(S,temp,1))// ��⵽����
            return 1;
    }
    return 0;
}

int main()
{
	SString S,T;
	char str[100];
    cout<<"����DNA����S��"<<"  ";
    cin>>str; // eabbacab
	StrAssign(S,str);
    cout<<"����DNA����T��"<<"  ";
    cin>>str; //aabb
	setbuf(stdin,NULL);
	StrAssign(T,str);
	if(Virus_detection(S,T))
        cout<<"�û����Ѹ�Ⱦ������"<<endl;
    else
        cout<<"�û���δ��Ⱦ������"<<endl;
	cin.get();
	return 0;
}
/*����
eabbacab
aabb
*/
/*����Ч��
����DNA����S��  eabbacab
e  a  b  b  a  c  a  b
����DNA����T��  aabb
a  a  b  b
�û����Ѹ�Ⱦ������
*/