#if 0    // ������Ķ�̬������汾
/*
���Ƚ����Ե��ǵ�115�е�a[i]=arr[i]+A[i];��Щ��Ť��a��A��MyArray��Ķ���
��arr�ǵ�ǰ�����һ����Ա��������һ���첲��һ����Ҫ��������������������
�޸�Ϊa.arr[i]=arr[i]+A.arr[i];

��41�п�ʼ�Ŀ������캯��MyArray::MyArray(const MyArray &A) �Ķ��壬
Ϊthis->arr��Ա�����˿ռ䣬�����βζ�����ָ�������һһ���и��ƣ�
Ω��û�����ģ���Ϊ this->size ��ֵ��������Ҫ����������У�����һ�д��룺size = A.size;��


*/

#include <iostream.h> 
#include <stdlib.h>
class MyArray
{
private:
    int *arr;		//���ڴ�Ŷ�̬����������ڴ��׵�ַ
    int size;		//�����С
public:
    MyArray(int sz=50);
    MyArray(int a[],int sz);	//��һ���������͵������ʼ��
    MyArray(const MyArray &A);	//�������캯��
    ~MyArray(void);				//����������ע���ͷſռ�
    MyArray&operator =(const MyArray &A); //���ء�=��ʹ���������������帳ֵ
    int& operator[](int i);		//����[]��ʹ��Array����Ҳ������C++��ͨ����һ������a[i]��ʽȡ��ֵ��ѡ����
    bool operator == (MyArray& A);	//����==��ʹ��Array�����������ж����������Ƿ���ȣ�size����Ҷ�ӦԪ����ȣ�
    MyArray operator + (MyArray& A);	//����+��ʹ����Array�������������ӣ�ǰ���С��ȣ���ѡ����
    friend ostream& operator << (ostream& out,MyArray& A);	//����<<���������
    int GetSize(void)const;	//ȡ�����С��
    void Resize(int sz);	//�޸�����Ĵ�С�����sz���������ԭ��С�����ӵ�Ԫ�س�ʼΪ��szС�������ԭ��С�����������Ԫ�ء�ѡ����
};
MyArray::MyArray(int sz)
{
    size = sz;
    arr = new int[size];
    for( int i = 0; i < size; i++ )
    {
        *(arr + i) = 0;
    }
}

MyArray::MyArray(int a[],int sz)	//��һ���������͵������ʼ��
{
    size = sz;
    arr = new int[size];
    for(int i = 0; i < size; i++)
    {
        *(arr + i) = *(a + i);
    }
}

MyArray::MyArray(const MyArray &A)	//�������캯��
{
    arr = new int[A.size];
    for(int i = 0; i < A.size; i++)
    {
        *(arr + i) = *(A.arr + i);
    }
    //????????????????????????????????????????????
    
}

MyArray::~MyArray(void)				//����������ע���ͷſռ�
{
    delete[]arr;
}
MyArray& MyArray::operator =(const MyArray &A) //���ء�=��ʹ���������������帳ֵ
{
    int n = A.size;
    if( size != n )
    {
        delete[]arr;
        arr = new int[n];
        size = n;
    }
    int* destptr=arr;  
    int* srcptr=A.arr;  
    while(n--)  
    {  
        *destptr=*srcptr;  
        destptr++;  
        srcptr++;  
    }  
    return *this;
}

int& MyArray::operator[](int i)		//����[]��ʹ��Array����Ҳ������C++��ͨ����һ������a[i]��ʽȡ��ֵ��ѡ����
{
    return arr[i];
}
bool MyArray::operator == (MyArray& A)	//����==��ʹ��Array�����������ж����������Ƿ���ȣ�size����Ҷ�ӦԪ����ȣ�
{
    bool m;
    m = true;
    if( A.size != size )
    {
        m = false;
    }
    else
    {
        for( int i = 0; i < size; i++ )
            
            if( *(A.arr + i) != *(arr + i) )
            {
                m = false;
                break;
            }
            
    }
    return m;
}


MyArray MyArray::operator + (MyArray& A)  
{  
    int n=A.size;   //ȡA����Ĵ�С  
    if (size!=n)   //��С��һ�²������  
    {  
        cout<<"not same size for add!"<<endl;  
        exit(1);  
    }  
    MyArray a(n);  //ָ��size������  
    
    for (int i = 0; i < size; i++)  
    {  
        a[i]=arr[i]+A.arr[i];  //?????????????????????????????????
    }  
    return a;//���ص�ǰ���������  
}  



ostream& operator << (ostream& out,MyArray& A)	//����<<���������
{
    for( int i = 0; i < A.size; i++)
    {
        out << A[i] << " ";
    }
    out << endl;
    return out;
    
}
int MyArray::GetSize(void)const	//ȡ�����С��
{
    return size;
}

void MyArray::Resize(int sz)	//�޸�����Ĵ�С�����sz���������ԭ��С�����ӵ�Ԫ�س�ʼΪ��szС�������ԭ��С�����������Ԫ�ء�ѡ����
{
    int *m = new int(sz);
    for( int i = 0; i < sz; i++)
    {
        *m = 0;
    }
    int n = ( sz <= size )?sz:size;
    for(int j = 0; j < n; j++)
    {
        *(m + j) = *(arr + j);
    }
    delete[]arr;
    arr = m;
}

int main()
{
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    int b[10]={4,5,6,7,8,9,10,11,12,13};
    MyArray arr1(a,10);
    MyArray arr2(b,10);
    MyArray arr3(10);
    cout<<arr3;
    arr3 = arr1 +arr2;
    cout<<arr3;
    //	arr3.Resize(20);
    //	cout<<arr3;
    //	arr3.Resize(5);
    //	cout<<arr3;
    system("pause");
    return 0;
} 

#endif

#if 1
#include <iostream.h> 
#include <stdlib.h>
class MyArray
{
private:
    int *arr;		//���ڴ�Ŷ�̬����������ڴ��׵�ַ
    int size;		//�����С
public:
    MyArray(int sz=50);
    MyArray(int a[],int sz);	//��һ���������͵������ʼ��
    MyArray(const MyArray &A);	//�������캯��
    ~MyArray(void);				//����������ע���ͷſռ�
    MyArray&operator =(const MyArray &A); //���ء�=��ʹ���������������帳ֵ
    int& operator[](int i);		//����[]��ʹ��Array����Ҳ������C++��ͨ����һ������a[i]��ʽȡ��ֵ��ѡ����
    bool operator == (MyArray& A);	//����==��ʹ��Array�����������ж����������Ƿ���ȣ�size����Ҷ�ӦԪ����ȣ�
    MyArray operator + (MyArray& A);	//����+��ʹ����Array�������������ӣ�ǰ���С��ȣ���ѡ����
    friend ostream& operator << (ostream& out,MyArray& A);	//����<<���������
    int GetSize(void)const;	//ȡ�����С��
    void Resize(int sz);	//�޸�����Ĵ�С�����sz���������ԭ��С�����ӵ�Ԫ�س�ʼΪ��szС�������ԭ��С�����������Ԫ�ء�ѡ����
};
MyArray::MyArray(int sz)
{
    size = sz;
    arr = new int[size];
    for( int i = 0; i < size; i++ )
    {
        *(arr + i) = 0;
    }
}

MyArray::MyArray(int a[],int sz)	//��һ���������͵������ʼ��
{
    size = sz;
    arr = new int[size];
    for(int i = 0; i < size; i++)
    {
        *(arr + i) = *(a + i);
    }
}

MyArray::MyArray(const MyArray &A)	//�������캯��
{
    arr = new int[A.size];
    for(int i = 0; i < A.size; i++)
    {
        *(arr + i) = *(A.arr + i);
    }
    
    size = A.size;               //?????????????????????????????????
}

MyArray::~MyArray(void)				//����������ע���ͷſռ�
{
    delete[]arr;
}
MyArray& MyArray::operator =(const MyArray &A) //���ء�=��ʹ���������������帳ֵ
{
    int n = A.size;
    if( size != n )
    {
        delete[]arr;
        arr = new int[n];
        size = n;
    }
    int* destptr=arr;  
    int* srcptr=A.arr;  
    while(n--)  
    {  
        *destptr=*srcptr;  
        destptr++;  
        srcptr++;  
    }  
    return *this;
}

int& MyArray::operator[](int i)		//����[]��ʹ��Array����Ҳ������C++��ͨ����һ������a[i]��ʽȡ��ֵ��ѡ����
{
    return arr[i];
}
bool MyArray::operator == (MyArray& A)	//����==��ʹ��Array�����������ж����������Ƿ���ȣ�size����Ҷ�ӦԪ����ȣ�
{
    bool m;
    m = true;
    if( A.size != size )
    {
        m = false;
    }
    else
    {
        for( int i = 0; i < size; i++ )
            
            if( *(A.arr + i) != *(arr + i) )
            {
                m = false;
                break;
            }
            
    }
    return m;
}


MyArray MyArray::operator + (MyArray& A)  
{  
    int n=A.size;   //ȡA����Ĵ�С  
    if (size!=n)   //��С��һ�²������  
    {  
        cout<<"not same size for add!"<<endl;  
        exit(1);  
    }  
    MyArray a(n);  //ָ��size������  
    
    for (int i = 0; i < size; i++)  
    {  
        a[i]=arr[i]+A[i];      //??????????????????????????????????????????
    }  
    return a;//���ص�ǰ���������  
}  



ostream& operator << (ostream& out,MyArray& A)	//����<<���������
{
    for( int i = 0; i < A.size; i++)
    {
        out << A[i] << " ";
    }
    out << endl;
    return out;
    
}
int MyArray::GetSize(void)const	//ȡ�����С��
{
    return size;
}

void MyArray::Resize(int sz)	//�޸�����Ĵ�С�����sz���������ԭ��С�����ӵ�Ԫ�س�ʼΪ��szС�������ԭ��С�����������Ԫ�ء�ѡ����
{
    int *m = new int(sz);
    for( int i = 0; i < sz; i++)
    {
        *m = 0;
    }
    int n = ( sz <= size )?sz:size;
    for(int j = 0; j < n; j++)
    {
        *(m + j) = *(arr + j);
    }
    delete[]arr;
    arr = m;
}

int main()
{
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    int b[10]={4,5,6,7,8,9,10,11,12,13};
    MyArray arr1(a,10);
    MyArray arr2(b,10);
    MyArray arr3(10);
    cout<<arr3;
    arr3 = arr1 +arr2;
    cout<<arr3;
    //	arr3.Resize(20);
    //	cout<<arr3;
    //	arr3.Resize(5);
    //	cout<<arr3;
    system("pause");
    return 0;
} 

#endif