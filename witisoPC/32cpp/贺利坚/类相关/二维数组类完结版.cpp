#include <iostream>   // ��ά����������
using namespace std;
class Douary
{
public:
	Douary(int m, int n);//���캯�������ڽ�����̬������m��n�еĶ�ά���飨����Ԫ�أ�����������Ԫ�س�ʼ��Ϊ
	Douary(const Douary &d);//���캯�������ڽ�����̬������m��n�еĶ�ά���飨����Ԫ�أ�����������Ԫ�س�ʼ��Ϊ
	~Douary(); //���������������ͷŶ�̬������ռ�õĴ洢�ռ�
	friend istream &operator>>(istream &input, Douary &d);//�����������>>�������ά���飬����dΪDousry�����
	friend ostream &operator<<(ostream &output, Douary &d);//�����������<<����m��n�о������ʽ�����ά���飬����dΪDouary�����
	friend Douary operator+(const Douary &d1,const Douary &d2);//����������ӣ����򣺶�Ӧλ���ϵ�Ԫ�����
	friend Douary operator-(const Douary &d1,const Douary &d2);//����������������򣺶�Ӧλ���ϵ�Ԫ�����
	bool operator==(const Douary &d);//�ж����������Ƿ���ȣ�����Ӧλ���ϵ�����Ԫ���Ƿ����
private:
	int * Array;      //Array Ϊ��̬����ָ�롣
	int row;          //row  Ϊ��ά�����������
	int col;          //col   Ϊ��ά�����������
};
 
Douary::Douary(int m, int n) //���캯�������ڽ�����̬������m��n�еĶ�ά���飨����Ԫ�أ�����������Ԫ�س�ʼ��Ϊ
{
	row=m;
	col=n;
	Array = new int[m*n]; //Arrayֻ��ָ��һά���飬��m*n��Ԫ�ص�һά���鵱��m��n�е����鿴����
	for(int i=0; i<row; ++i)
		for(int j=0; j<col; ++j)
			Array[i*col+j]=0; //�ؼ��Ǹ�������Ԫ�ص�ַ�ļ���취���˴�������д��*(Array+i*col+j)=0; 
}
 
Douary::Douary(const Douary &d)
{
	row=d.row;
	col=d.col;
	Array = new int[row*col];
	for(int i=0; i<row; ++i)
		for(int j=0; j<col; ++j)
			Array[i*col+j]=d.Array[i*col+j]; //ע���ַ��
}
 
Douary::~Douary() //���������������ͷŶ�̬������ռ�õĴ洢�ռ�
{
	delete [] Array;
}
 
istream &operator>>(istream &input, Douary &d)//�����������>>�������ά���飬����dΪDousry�����
{
	for(int i=0; i<d.row; ++i)
		for(int j=0; j<d.col; ++j)
			cin>>d.Array[i*d.col+j];//ע���ַ��
	return input;
}
 
ostream &operator<<(ostream &output, Douary &d)//�����������<<����m��n�о������ʽ�����ά���飬����dΪDouary�����
{
	for(int i=0; i<d.row; ++i)
	{
		for(int j=0; j<d.col; ++j)
			cout<<d.Array[i*d.col+j]<<"\t"; //ע���ַ��
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
 
Douary operator-(const Douary &d1,const Douary &d2)//����������������򣺶�Ӧλ���ϵ�Ԫ�����
{
	//�ڴ˿������ж�d1��d2�������Ƿ���ͬ���������ͬ���Ա����˳����������㡣���ο�����������һǰ��
	Douary d(d1.row,d1.col);
	for(int i=0; i<d1.row; ++i)
	{
		for(int j=0; j<d1.col; ++j)
			d.Array[i*d1.col+j]=d1.Array[i*d1.col+j]-d2.Array[i*d1.col+j];
	}
	return d;
}
bool Douary::operator ==(const Douary &d)//�ж����������Ƿ���ȣ�����Ӧλ���ϵ�����Ԫ���Ƿ����
{
	if(row!=d.row||col!=d.col) return false;
	bool eq = true;
	for(int i=0; i<row; ++i)
	{
		for(int j=0; j<col; ++j)
			if (Array[i*col+j]!=d.Array[i*col+j]) 
			{
				eq=false;
				break;
			}
			if (!eq) break;
	}
	return eq;
}
 
int main()
{
	Douary d1(2,3),d2(2,3);
	cout<<"����d1(2,3):"<<endl;
	cin>>d1;
	cout<<"����d2(2,3):"<<endl;
	cin>>d2;
	cout<<"d1="<<endl;
	cout<<d1;
	cout<<"d2="<<endl;
	cout<<d2;
	cout<<"d1+d2="<<endl;
	Douary d3=(d1+d2);
	cout<<d3;
	cout<<"d1-d2="<<endl;
	cout<<(d1-d2);
	cout<<"d1"<<((d1==d2)?"==":"!=")<<"d2"<<endl;
	system("pause");
	return 0;
}