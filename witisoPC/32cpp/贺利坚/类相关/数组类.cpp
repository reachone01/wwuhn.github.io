/*  ������
�����Ǽ�����֧�ֵ���֯���ݵķ�����C��C++�����������ṩ������֧�֣�
ʹ������������ʵ���������Ҫ�ĸ���ʵ�õĹ��ܡ����ǣ�����֧�ֽ�����������д����Ԫ�صĻ��ơ�
C++��֧������ĳ���abstraction��Ҳ��֧�ֶ���������Ĳ�����
���磺��һ�����鸳ֵ������һ�����飬���������������ȱȽϻ�����֪������Ĵ�Сsize���ȵȡ�
��C++���ԣ������Ǵ�C�����м̳����ģ�����ӳ�������������в������㷨�ķ��룬
��Ũ��Ĺ��̻�������Ƶ����������鲢����C++���Ե�һ�ȹ���
������ʵ����Ŀ�У���һ��C++����Ա���������ʹ�ñ�׼�����ṩ��Vector����ʵ�����鹦�ܡ�
�������Ҳ�����������Ƕ��������Ӻ�������飬����ɨ����ѧVector�ȱ�׼���п��ܴ��ڵ��ϰ���
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
    MyArray(const MyArray &A);	//���ƹ��캯��
    ~MyArray(void);				//����������ע���ͷſռ�
    MyArray&operator =(const MyArray &A);   //���ء�=��ʹ���������������帳ֵ
    int& operator[](int i);		            //����[]��ʹ��Array����Ҳ������C++��ͨ����һ������a[i]��ʽȡ��ֵ��ѡ����
    bool operator == (MyArray& A);	        //����==��ʹ��Array�����������ж����������Ƿ���ȣ�size����Ҷ�ӦԪ����ȣ�
    MyArray operator + (MyArray& A);	    //����+��ʹ����Array�������������ӣ�ǰ���С��ȣ���ѡ����
    friend ostream& operator << (ostream& out,MyArray& A);	//����<<���������
    int GetSize(void)const;	                //ȡ�����С��
    void Resize(int sz);	                //�޸�����Ĵ�С�����sz���������ԭ��С�����ӵ�Ԫ�س�ʼΪ�����sz���������ԭ��С�����������Ԫ�ء�ѡ����
};

//����Ϊ���Ա�����Ķ���

//���캯��
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

MyArray::MyArray(int a[],int sz)
{
    if(sz<=0)
    {
        cout<<"invalidArraySize";
        exit(1);
    }
    size=sz;            //��Ԫ�ظ�����ֵ������size
    arr=new int[size];  //��̬�����ڴ棬��size��int���͵�Ԫ�ؿռ�������
    for(int i=0; i<size; ++i)
        *(arr+i)=*(a+i);
}

//��������
MyArray::~MyArray(void)
{
    delete []arr;
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
    int *srcptr=A.arr;  //A.arr�Ƕ���A�������׵�ַ
    int *destptr=arr;   //arr�Ǳ������е������׵�ַ
    while(n--)
    {
        *destptr=*srcptr;
        destptr++;
        srcptr++;
    }
}

//����'='
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
    
    //��rhs�򱾶�����Ԫ��
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

//����[]
int &MyArray::operator[](int n)
{
    if(n<0||n>size-1)             // �����˱߽���
    {
        cout<<"indexOutOfRange"<<endl;
        exit(1);
    }
    return arr[n];
}

bool MyArray::operator == (MyArray& A)
{
    bool eq=true;
    int n=A.size;	//ȡA����Ĵ�С
    if (size!=n)    //��С�Ƿ�һ��
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
                eq=false;
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
    if (size!=n)    //��С��һ�²������
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
    int *newlist=new int[sz];
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
    delete []arr;
    arr=newlist;
    size=sz;
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
    arr3.Resize(20);
    cout<<arr3;
    arr3.Resize(5);
    cout<<arr3;
    system("pause");
    return 0;
} 

/*
��������չһ��ѡ�������涨MyArrayֻ�ܴ���Ԫ��Ϊ���͵�����δ��̫���ˣ�����Ƴ�ģ���࣬
ʹ֮��Ӧ�������ͣ���ʵ�ϣ�C++���ӵı�׼���Щ���������Ƴ���ģ���ࣩ��
��������չ����ѡ����������ʩ��������Ĳ������кܶ࣬������������
�����������С������ĳһԪ�ء���ȡ���е�Ƭ�Σ�ȡ�ӵ�5������10��֮�������Ԫ�أ�
�����γ��µ�������󣩡������˷�������������Щ��������Ϊ��ĳ�Ա��������ʼ��չ֮�ðɣ�
*/