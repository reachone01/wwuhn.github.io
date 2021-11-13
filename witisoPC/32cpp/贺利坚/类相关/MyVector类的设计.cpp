//MyVector������
#include <iostream.h>

class MyVector  //����������
{
public:
    MyVector(){
        num=0;
        Array=NULL;
    }
    MyVector(int m);                //���캯��������m��Ԫ�ص�������Ԫ��ֵԤ��Ϊ0
    MyVector(const MyVector &v);    //���ƹ��캯��
    ~MyVector();                    //�����������ͷŶ�̬������ռ�õĴ洢�ռ�
    friend istream &operator>>(istream &input, MyVector &d);
    friend ostream &operator<<(ostream &output, const MyVector &d);
    friend MyVector operator+(const MyVector &d1,const MyVector &d2);//������ӣ���Ӧλ���ϵ�Ԫ�����
    friend MyVector operator-(const MyVector &d1,const MyVector &d2);//�����������Ӧλ���ϵ�Ԫ�����
    bool operator==(const MyVector &d); //�ж����������Ƿ���ȣ�����Ӧλ���ϵ�����Ԫ���Ƿ����
    int operator[](int i);              //���������еĵ�i��Ԫ�ص�ֵ
private:
    int *Array;       //Array Ϊ��̬����ָ�룬ָ������ռ���ڴ����ʼ��ַ
    int num;          //������Ԫ�ظ���
};
 
MyVector::MyVector(int m)
{
    num = m;
    Array = new int[num];
    for(int i=0; i<num; ++i)
        Array[i]=0;
}
 
MyVector::MyVector(const MyVector &d)
{
    num=d.num;
    if(Array!=NULL)                 //////////////////1111
        delete []Array;
    Array = new int[num];
    for(int i=0; i<num; ++i)
        Array[i]=d.Array[i];
}
 
MyVector::~MyVector() //���������������ͷŶ�̬������ռ�õĴ洢�ռ�
{
    delete [] Array;
}
 
istream &operator>>(istream &input, MyVector &d)
{
    cout<<d.num<<"��Ԫ�ص�����: ";
    for(int i=0; i<d.num; ++i)
        input>>d.Array[i];
    return input;
}
 
ostream &operator<<(ostream &output, const MyVector &d)
{
    cout<<"(";
    if(d.num>0)
        output<<d.Array[0];
    for(int i=1; i<d.num; ++i)
       output<<", "<<d.Array[i];
    output<<")";
    return output;
}
 
MyVector operator+(const MyVector &d1,const MyVector &d2)
{
    //�ڴ˿������ж�d1��d2��Ԫ�����Ƿ���ͬ���������ͬ���Ա����˳����������㡣���ο�����������һǰ��
   
    if(d1.num != d2.num)
    {
        cout<<"the SIZE of two array is not the same!"<<endl;
        return -1;
    }
    MyVector d(d1.num);
    for(int i=0; i<d1.num; ++i)
    {
        d.Array[i]=d1.Array[i]+d2.Array[i];
    }
    return d;
}
 
MyVector operator-(const MyVector &d1,const MyVector &d2)
{
    if(d1.num != d2.num)
    {
        cout<<"the SIZE of two array is not the same!"<<endl;
        return -1;
    }
    MyVector d(d1.num);
    for(int i=0; i<d1.num; ++i)
    {
        d.Array[i]=d1.Array[i]-d2.Array[i];
    }
    return d;
}
 
bool MyVector::operator ==(const MyVector &d)//�ж����������Ƿ���ȣ�����Ӧλ���ϵ�����Ԫ���Ƿ����
{
    if(num!=d.num) return false;
    bool eq = true;
    for(int i=0; i<num; ++i)
    {
        if (Array[i]!=d.Array[i])
        {
            eq=false;
            break;
        }
        if (!eq) break;
    }
    return eq;
}
 
int MyVector::operator[](int i)
{
    return Array[i];  //δʵʩԽ�籣��
}
 
int main()
{
    MyVector d1(5),d2(5);
    cout<<"����d1����";
    cin>>d1;
    cout<<"����d2����";
    cin>>d2;
    cout<<"d1="<<d1<<endl;
    cout<<"d2="<<d2<<endl;
    cout<<"d1+d2="<<d1+d2<<endl;
    cout<<"d1-d2="<<d1-d2<<endl;
    cout<<"d1"<<((d1==d2)?"==":"!=")<<"d2"<<endl;
    cout<<"d1[2]="<<d1[2]<<endl;
    while(1);
    return 0;
}