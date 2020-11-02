#include<iostream>
#include"sqlist.h"              //�����Զ���ͷ�ļ�,Դ��Ŀ¼����Ϊsqlist.h���ļ� 
using namespace std;

void MergeSqlist(SqList La,SqList Lb,SqList &Lc)    // ˳�������ĺϲ�
{
	// ��֪˳�������La��Lb��Ԫ�ذ�ֵ�ǵݼ�����
	// La��Lb�ϲ��õ��µ�˳�������Lc��Lc��Ԫ��Ҳ��ֵ�ǵݼ�����
	int i,j,k;
	i=j=k=0;
	Lc.length=La.length+Lb.length;  // �±���Ϊ���ϲ�����ĳ���֮��
	Lc.elem=new int[Lc.length];     // Ϊ�ϲ�����±����һ�οռ�
	while(i<La.length&&j<Lb.length) // �������ǿ�
	{
		if(La.elem[i]<=Lb.elem[j])  // ����ȡ��������ֵ��С���뵽Lc����
			Lc.elem[k++]=La.elem[i++];
		else
			Lc.elem[k++]=Lb.elem[j++];
	}
	while(i<La.length)              // La��ʣ�࣬���ν�La��ʣ��Ԫ�ز���Lc������
		Lc.elem[k++]=La.elem[i++];
	while(j<Lb.length)              // Lb��ʣ�࣬���ν�Lb��ʣ��Ԫ�ز���Lc������
		Lc.elem[k++]=Lb.elem[j++];
}

bool CreateList(SqList &L)  // ����һ��˳���L
{   // L��&��ʾ�������Ͳ����������ڲ��ĸı�����������Ȼ��Ч
    // ����&�ڲ��ı䣬������������Ч
    int a,i=1;
    cin>>a;
    while(a!=-1)
    {
    	ListInsert_Sq(L,i,a);
		cin>>a;
    	i++;
   }
   return true;
}

void print(SqList L)
{
	cout<<"���˳���"<<endl;
	for(int j=0;j<=L.length-1;j++)
		cout<<L.elem[j]<<"   ";
	cout<<endl;
}

int main()
{
	SqList La, Lb, Lc;
	cout<<"��������(�ǵݼ�)˳���La:"<<endl;
	InitList(La);   // La��Ĵ���
	CreateList(La); // ������˳���La����������
	print(La);
    cout<<"��������(�ǵݼ�)˳���Lb:"<<endl;
	InitList(Lb);   // Lb��Ĵ���
	CreateList(Lb); // ������˳���Lb����������
	print(Lb);
	MergeSqlist(La, Lb, Lc); // ��˳���La��Lb���кϲ�
	cout<<"�ǵݼ����Ա�La��Lb�ϲ���ķǵݼ����Ա�lcΪ��\n"; // ����ϲ��������˳���Lc
	print(Lc);
	cout<<endl;
	return 0;
}
