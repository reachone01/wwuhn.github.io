#if 0
//����2
#include <iostream.h>

class Douary
{
public:
	Douary(int m, int n);//���캯�������ڽ�����̬������m��n�еĶ�ά���飨����Ԫ�أ�����������Ԫ�س�ʼ��Ϊ0
	~Douary(); //���������������ͷŶ�̬������ռ�õĴ洢�ռ�
    //Douary(const Douary &d);//���ƹ��캯��
	friend istream &operator>>(istream &input, Douary &d);//�����������>>�������ά���飬����dΪDousry�����
	friend ostream &operator<<(ostream &output, Douary &d);//�����������<<����m��n�о������ʽ�����ά���飬����dΪDouary�����
	friend Douary operator+(const Douary &d1,const Douary &d2);//����������ӣ����򣺶�Ӧλ���ϵ�Ԫ�����
private:
	int *Array;       //Array Ϊ��̬����ָ�롣
	int row;          //row   Ϊ��ά�����������
	int col;          //col   Ϊ��ά�����������
};
 
Douary::Douary(int m, int n) //���캯�������ڽ�����̬������m��n�еĶ�ά���飨����Ԫ�أ�����������Ԫ�س�ʼ��Ϊ
{
	row=m;
	col=n;
	Array = new int[m*n];
	for(int i=0; i<row; ++i)
		for(int j=0; j<col; ++j)
			Array[i*col+j]=0;
}
 
Douary::~Douary() //���������������ͷŶ�̬������ռ�õĴ洢�ռ�
{
	delete [] Array;
}
 
istream &operator>>(istream &input, Douary &d)//�����������>>�������ά���飬����dΪDousry�����
{
	for(int i=0; i<d.row; ++i)
		for(int j=0; j<d.col; ++j)
			cin>>d.Array[i*d.col+j];
	return input;
}
 
ostream &operator<<(ostream &output, Douary &d)//�����������<<����m��n�о������ʽ�����ά���飬����dΪDouary�����
{
	for(int i=0; i<d.row; ++i)
	{
		for(int j=0; j<d.col; ++j)
			cout<<d.Array[i*d.col+j]<<"\t";
		cout<<endl;
	}
	cout<<endl;
	return output;
}
 
Douary operator+(const Douary &d1,const Douary &d2)//����������ӣ����򣺶�Ӧλ���ϵ�Ԫ�����
{
	//�ڴ˿������ж�d1��d2�������Ƿ���ͬ���������ͬ���Ա����˳����������㡣���ο�����������һǰ��
	Douary d(d1.row,d1.col);
	for(int i=0; i<d1.row; ++i)
	{
		for(int j=0; j<d1.col; ++j)
			d.Array[i*d1.col+j]=d1.Array[i*d1.col+j]+d2.Array[i*d1.col+j];
	}
	return d;
}
 
int main()
{
	Douary d1(2,3),d2(2,3);
	cout<<"����d1(2,3):"<<endl;
	cin>>d1;
	cout<<"����d2(2,3):"<<endl;
	cin>>d2;
	cout<<"d1+d2="<<endl;
	Douary d3=d1+d2;
	cout<<d3;
	while(1);
	return 0;
}

/*
1 2 3
4 5 6
9 8 7
6 5 4
*/
#endif

#if 1

#include <iostream.h>

class Douary
{
public:
    Douary(int m, int n);   //���캯�������ڽ�����̬������m��n�еĶ�ά���飨����Ԫ�أ�����������Ԫ�س�ʼ��Ϊ0
    ~Douary();              //���������������ͷŶ�̬������ռ�õĴ洢�ռ�
    Douary(const Douary &d);//���ƹ��캯��
    friend istream &operator>>(istream &input, Douary &d);      //�����������>>�������ά���飬����dΪDousry�����
    friend ostream &operator<<(ostream &output, Douary &d);     //�����������<<����m��n�о������ʽ�����ά���飬����dΪDouary�����
    friend Douary operator+(const Douary &d1,const Douary &d2); //����������ӣ����򣺶�Ӧλ���ϵ�Ԫ�����
private:
    int *Array;       //Array Ϊ��̬����ָ�롣
    int row;          //row   Ϊ��ά�����������
    int col;          //col   Ϊ��ά�����������
};

Douary::Douary(int m, int n) //���캯�������ڽ�����̬������m��n�еĶ�ά���飨����Ԫ�أ�����������Ԫ�س�ʼ��Ϊ
{
    row=m;
    col=n;
    Array = new int[m*n];
    for(int i=0; i<row; ++i)
        for(int j=0; j<col; ++j)
            Array[i*col+j]=0;
}

Douary::Douary(const Douary &d)
{
    row=d.row;
    col=d.col;
    Array = new int[row*col];
    for(int i=0; i<row; ++i)
        for(int j=0; j<col; ++j)
            Array[i*col+j]=d.Array[i*col+j];
}

Douary::~Douary() //���������������ͷŶ�̬������ռ�õĴ洢�ռ�
{
    delete [] Array;
}

istream &operator>>(istream &input, Douary &d)//�����������>>�������ά���飬����dΪDousry�����
{
    for(int i=0; i<d.row; ++i)
        for(int j=0; j<d.col; ++j)
            cin>>d.Array[i*d.col+j];
        return input;
}

ostream &operator<<(ostream &output, Douary &d)//�����������<<����m��n�о������ʽ�����ά���飬����dΪDouary�����
{
    for(int i=0; i<d.row; ++i)
    {
        for(int j=0; j<d.col; ++j)
            cout<<d.Array[i*d.col+j]<<"\t";
        cout<<endl;
    }
    cout<<endl;
    return output;
}

Douary operator+(const Douary &d1,const Douary &d2)//����������ӣ����򣺶�Ӧλ���ϵ�Ԫ�����
{
    //�ڴ˿������ж�d1��d2�������Ƿ���ͬ���������ͬ���Ա����˳����������㡣���ο�����������һǰ��
    Douary d(d1.row,d1.col);
    for(int i=0; i<d1.row; ++i)
    {
        for(int j=0; j<d1.col; ++j)
            d.Array[i*d1.col+j]=d1.Array[i*d1.col+j]+d2.Array[i*d1.col+j];
    }
    return d;
}

int main()
{
    Douary d1(2,3),d2(2,3);
    cout<<"����d1(2,3):"<<endl;
    cin>>d1;
    cout<<"����d2(2,3):"<<endl;
    cin>>d2;
    cout<<"d1+d2="<<endl;
    Douary d3=d1+d2;
    cout<<d3;
    while(1);
    return 0;
}
#endif