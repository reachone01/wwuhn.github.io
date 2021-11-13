#if 0 //����1
#include <iostream>
using namespace std;
class IntArray
{
public:
    IntArray(){arr_point=NULL; arr_len=0;}
    IntArray(int a[], int n);
    void showArray();
private:
    int *arr_point;  //������׵�ַ
    int arr_len;
};

IntArray::IntArray(int a[], int n)
{
    arr_point=a;  //�������ѵ�Դͷ
    arr_len=n;
}

void IntArray::showArray()
{
    for (int i=0; i<arr_len; ++i)
        cout<<*(arr_point+i)<<' '; //��cout<<arr_point[i]<<' '
    cout<<endl;
    return;
}

int main()
{   
    int x[]={1,2,3,4,5};
    IntArray arr(x,5);
    arr.showArray();  // ���1 2 3 4 5
    system("pause");
    return 0;
}

#endif

#if 0
//����2
#include <iostream>
using namespace std;
class IntArray
{
public:
	IntArray(){arr_point=NULL; arr_len=0;}
	IntArray(int a[], int n);
	void showArray() const;
private:
	int *arr_point;  //������׵�ַ
	int arr_len;
};
 
 
IntArray::IntArray(int a[], int n)
{
	arr_point=a; 
	arr_len=n;
}
 
 
void IntArray::showArray() const
{
	for (int i=0; i<arr_len; ++i)
		cout<<*(arr_point+i)<<' '; //��cout<<arr_point[i]<<' '
	cout<<endl;
	return;
}
 
 
int main2()
{   
	int x[]={1,2,3,4,5};
	const IntArray arr(x,5);
	arr.showArray();  //���1 2 3 4 5
	x[3]=999;
	arr.showArray();  //�������1 2 3 999 5 ������������
	system("pause");
        return 0;
}

//����3
 
����//��Ķ���������2��ȫ��ͬ
 
int main()
{   
	int *x=new int[5];
	for (int i=0; i<5; ++i)
		x[i]=i+1;  //x��ͨ����̬����ռ��õģ�������ͷŴӻ������ǺϷ���
	const IntArray arr(x,5);
	arr.showArray();  //���1 2 3 4 5
	delete [] x;      //�ͷ�x��x�����ɲ���ϵͳ������������;����������main�в����þֲ�����x�������ͷţ�����Ų�����á����x����ܴ�Ч��ɹۣ�
	arr.showArray();  //�������ѷ����Ĳ�λ������������Ԥ�ϣ����ܵ���������ͣ������ʻ���˲�����ʻ�ĳ��������ʧ�ء���
	system("pause");
        return 0;
}
#endif

#if 1
//����4
#include <iostream>
using namespace std;
class IntArray
{
public:
	IntArray(){arr_point=NULL; arr_len=0;}
	IntArray(int a[], int n);
	~IntArray();
	void showArray() const;
 
private:
	int *arr_point;  //������׵�ַ
	int arr_len;
};
 
IntArray::IntArray(int a[], int n)
{
	arr_point=new int[n];  //arr_pointָ���������Լ����¿ռ�
	for (int i=0; i<n; ++i) 
		*(arr_point+i)=*(a+i);   //������a��Ԫ�������ֵ
	arr_len=n;
}
 
IntArray::~IntArray() //�����������漰��̬����洢�ռ䣬�����������н���Ӧ�ռ��ͷ�
{
	if (!arr_point) // ��ͬ��if (arr_point!=NULL) 
		delete [] arr_point; //�ͷ���������������з���ģ�arr_pointָ��Ŀռ�
}
 
void IntArray::showArray() const
{
	for (int i=0; i<arr_len; ++i)
		cout<<*(arr_point+i)<<' '; //��cout<<arr_point[i]<<' '
	cout<<endl;
	return;
}
 
int main()
{   
	int *x=new int[5];
	for (int i=0; i<5; ++i)
		x[i]=i+1;
	const IntArray arr(x,5);
	arr.showArray();   // ���1 2 3 4 5
	x[3]=999;
	arr.showArray();   // ���1 2 3 4 5, arrʹ��ר���Ĵ洢�ռ䣡
	delete [] x;
	arr.showArray();   // ���1 2 3 4 5, arrʹ��ר���Ĵ洢�ռ䣡��
	system("pause");
    return 0;
}
#endif