#include <iostream.h>
#include <cstdlib>   // ������

class MyArray
{
private:
    int *arr;		//���ڴ�Ŷ�̬����������ڴ��׵�ַ
    int size;		//�����С
public:
    MyArray(int sz=50);
    MyArray(int a[],int sz);	//��һ���������͵������ʼ��
    MyArray(const MyArray &A);	//���ƹ��캯��
    ~MyArray(void);				//����������ע���ͷſռ�
    MyArray&operator =(const MyArray &A);   //���ء�=��ʹ���������������帳ֵ
    int& operator[](int i);		            //����[]��ʹ��Array����Ҳ������C++��ͨ����һ������a[i]��ʽȡ��ֵ��ѡ����
    bool operator == (MyArray& A);	        //����==��ʹ��Array�����������ж����������Ƿ���ȣ�size����Ҷ�ӦԪ����ȣ�
    MyArray operator + (MyArray& A);	    //����+��ʹ����Array�������������ӣ�ǰ���С��ȣ���ѡ����
    friend ostream& operator << (ostream& out,MyArray& A);	//����<<���������
    int GetSize(void) const;	//ȡ�����С��
    void Resize(int sz);        //�޸�����Ĵ�С�����sz���������ԭ��С�����ӵ�Ԫ�س�ʼΪ�����sz���������ԭ��С�����������Ԫ�ء�ѡ����
};
 
//���캯����ָ������������Ԫ�ظ�������Ԫ��ȫ����ʼ��Ϊ 0
MyArray::MyArray(int sz)
{
    if(sz<=0)
    {
        cout<<"invalid Array Size!";
        exit(1);
    }
    size=sz;    		//��Ԫ�ظ�����ֵ������size
    arr=new int[size];  //��̬�����ڴ棬��size��int���͵�Ԫ�ؿռ�������
    for(int i=0; i<size; ++i)
        *(arr+i)=0;
}
 
//��һ���������͵������ʼ��
MyArray::MyArray(int a[],int sz)
{
    if(sz<=0)
    {
        cout<<"invalid Array Size";
        exit(1);
    }
    size=sz;//��Ԫ�ظ�����ֵ������size
    arr=new int[size];//��̬�����ڴ棬��size��int���͵�Ԫ�ؿռ�������
    for(int i=0; i<size; ++i)
        *(arr+i)=*(a+i);
}
 
//��������
MyArray::~MyArray(void)
{
    if (!arr)
        delete [] arr;
}
 
//���ƹ��캯��
MyArray::MyArray(const MyArray& A)
{
    //�Ӷ���Aȡ�������С����������ǰ�����Ա
    int n=A.size;
    size=n;
    //Ϊ���������ڴ沢���г�����
    arr=new int[n];
    //�Ӷ���A��������Ԫ�ص�������
    int *srcptr=A.arr;//X.arr�Ƕ���A�������׵�ַ
    int *destptr=arr;//arr�Ǳ������е������׵�ַ
    while(n--)
    {
        *destptr=*srcptr;
        destptr++;
        srcptr++;
    }
}
 
//���ظ�ֵ����'='
MyArray& MyArray::operator =(const MyArray &A)
{
    int n=A.size;//ȡA����Ĵ�С
    //����������е������С��A��ͬ����ɾ������ԭ�е��ڴ棬Ȼ�����·���
    if (size!=n)
    {
        delete []arr;
        arr=new int[n];
        size=n;
    }
 
    //��rhs��ǰ������Ԫ��
    int* destptr=arr;
    int* srcptr=A.arr;
    while(n--)
    {
        *destptr=*srcptr;
        destptr++;
        srcptr++;
    }
    return *this;//���ص�ǰ���������
}
 
//����[]������ͨ���±꽫Ԫ��ȡ����
int &MyArray::operator[](int n)
{
    if(n<0||n>size-1)
    {
        cout<<"index Out Of Range"<<endl;
        exit(1);
    }
    return arr[n];
}
 
bool MyArray::operator == (MyArray& A)
{
    bool eq=true;
    int n=A.size;	//ȡA����Ĵ�С
    if (size!=n)    //��С��һ�£�����һ�������
    {
        eq=false;
    }
    else
    {
        int* destptr=arr;
        int* srcptr=A.arr;
        while(n--)
        {
            if(*destptr!=*srcptr)
            {
                eq=false;     //������һ��Ԫ�ز���ȣ�������Ҳ�����
                break;
            }
            destptr++;
            srcptr++;
        }
    }
    return eq;//���ص�ǰ���������
}
 
MyArray MyArray::operator + (MyArray& A)
{
    int n=A.size;	//ȡA����Ĵ�С
    if (size!=n)   //��С��һ�²������
    {
        cout<<"not same size for add!"<<endl;
        exit(1);
    }
    MyArray a(n);  //ָ��size������
 
    for (int i = 0; i < size; i++)
    {
        a[i]=arr[i]+A[i];
    }
    return a;//���ص�ǰ���������
}
 
ostream& operator << (ostream& out, MyArray& A)
{
    for (int i = 0; i < A.size; i++)
    {
        out<<A[i]<<'\t';
    }
    out<<endl;
    return out;
}
 
//ȡ��ǰ�����С
int MyArray::GetSize(void)const
{
    return size;
}
 
//�������С�޸�Ϊsz
void MyArray::Resize(int sz)
{
    if(sz<=0)
    {
        cout<<"invalidArraySize"<<endl;
        exit(1);
    }
    if(sz==size)
        return;
    int *newlist=new int[sz];  //Ϊ�ı��С������������ռ�
    for (int i = 0; i < sz; i++)
    {
        *(newlist+i)=0;
    }
    int n=(sz<=size)?sz:size;
    int *srcptr=arr;
    int *destptr=newlist;
    while(n--)
    {
        *destptr=*srcptr;
        destptr++;
        srcptr++;
    }
    delete []arr; //�ͷ�ԭ����ռ�õĿռ�
    arr=newlist;  //�������·�����������
    size=sz;
}
 
int main()
{
    int a[10]= {1,2,3,4,5,6,7,8,9,10};
    int b[10]= {4,5,6,7,8,9,10,11,12,13};
    MyArray arr1(a,10);  //���������õ������ʼ���¶�����������
    MyArray arr2(b,10);
    MyArray arr3(10);   //����ָֻ����С�����������ĳ�ʼ��
    cout<<arr3;    //���Զ�<<������
    arr3 = arr1 +arr2;  //���Զ�+���㣬�Լ���ֵ=���������
    cout<<arr3;
    arr3.Resize(20);  //�������������С�Ĺ���
    cout<<arr3;
    arr3.Resize(5);   //������С�����С�Ĺ���
    cout<<arr3;
    cout<<"The size of new array is: "<<arr3.GetSize()<<endl;   //����GetSize()��Ա����
    cout<<"The first element of new array is: "<<arr3[0]<<endl;  //����[]���������
    cout<<"arr1 "<<(arr1==arr2?"=":"!=")<<" arr2. "<<endl;   //����==�����������
    cout<<"\n__End__"<<endl;
    while(1);
    return 0;
}
