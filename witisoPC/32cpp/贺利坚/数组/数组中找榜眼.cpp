/*
�������Ұ���
*/
#if 1  // һ�Ρ�ɨ�衱�ҳ��δ�ֵ


//��дһ���������ҳ�һ����������data�еĵڶ��������
#include <iostream>
using namespace std;

int find_sec_max(int data[] , int n);

int main ()
{
    int a[10]= {99,6,12,2,4,98,14,11,76,1};
    cout<<"a�����еĵڶ�����Ϊ��"<<find_sec_max(a,10)<<endl;
    return 0;
}


int find_sec_max(int data[] , int n)
{
    int max1;  //���
    int max2;  //�δ�
    if (data[0]>data[1])
        max1=data[0], max2=data[1];
    else
        max1=data[1], max2=data[0];
    for(int i=1; i<n; i++)
    {
        if(data[i] > max1)  //�����Ķ���
        {
            max2 = max1;    // ���ֵ��Ϊ�϶�
            max1 = data[i]; // �������ֵ
        }
        else if(data[i] > max2 && data[i] < max1)  //a[i]Ӧ�������϶����ϴ󲻱�
            max2 = data[i];
    }
    return max2;
}




#endif

#if 0  // ������ѡ������ķ���������Ҫ���Ρ�ɨ�衱
//��дһ���������ҳ�һ����������data�еĵڶ��������
#include <iostream>
using namespace std;
int find_sec_max(int data[] , int n);
int main ()
{
	int a[10]={3,6,12,2,4,98,14,11,76,1};
	cout<<"a�����еĵڶ�����Ϊ��"<<find_sec_max(a,10)<<endl;
	return 0; 
}
 
 
int find_sec_max(int data[] , int n)
{
	int k=0,i,t;  
	for(i=1; i<n; i++)  
	{  
		if(data[i] > data[k])
		{  
			k=i;  //��k��¼���ֵ���±�
		}  
	}
	t=data[0];data[0]=data[k];data[k]=t;   //ͨ��������data[0]�н������ֵ
	//�δ�Ԫ����data[1]��data[n-1]�е����Ԫ��
	k=1;
	for(i=2; i<n; i++)  
	{  
		if(data[i] > data[k])
		{  
			k=i;  //��k��¼���ֵ���±�
		}  
	}
	return data[k];
}

#endif

#if 0  // ����ѡ��������

//��дһ���������ҳ�һ����������data�еĵڶ��������
#include <iostream>
using namespace std;
int find_sec_max(int data[] , int n);
int main ()
{
	int a[10]={3,6,12,2,4,98,14,11,76,1};
	cout<<"a�����еĵڶ�����Ϊ��"<<find_sec_max(a,10)<<endl;
	return 0; 
}
 
 
int find_sec_max(int data[] , int n)
{
	int k=0,i,j,t;
	for(j=0;j<2;++j)  //��ѭ�����Σ�����������������������ֺ���
	{
		k=j;
		for(i=j+1; i<n; i++)  
		{  
			if(data[i] > data[k])
			{  
				k=i;  //��k��¼���ֵ���±�
			}  
		}
		if(j!=k)
		{
			t=data[j];
			data[j]=data[k];
			data[k]=t;   //ͨ��������data[j]�н������ֵ
		}
	}
	return data[1];   //�δ�Ԫ����data[1]��
}
#endif


/*

*/