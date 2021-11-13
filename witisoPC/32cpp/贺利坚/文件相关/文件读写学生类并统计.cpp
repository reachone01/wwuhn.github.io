#include <fstream>
#include<iostream>
#include<string>
using namespace std;
 
//����ѧ����
class Student
{
public:
	Student(){};
	Student(string nam, double c, double m, double e):name(nam),cpp(c),math(m),english(e){total=c+m+e;}
	void set_value(string nam, double c, double m, double e);
	string get_name(){return name;}
	double get_cpp(){return cpp;}
	double get_math(){return math;}
	double get_english(){return english;}
	double get_total(){return total;}
	void set_cpp(double c){cpp=c;}
	void set_math(double m){math=m;}
	void set_english(double e){english=e;}
	void set_total(double t){total=t;}
private:
	string name;
	double cpp;
	double math;
	double english;
	double total;
};
 
void Student::set_value(string nam, double c, double m, double e)
{
	name=nam;
	cpp=c;
	math=m;
	english=e;
	total=c+m+e;
}
 
int main( )
{
	Student stud[100],t; //stud[100]Ϊ�������ݵĶ�������
	string sname;
	double scpp, smath, senglish;
	int i,j;
 
	//���ļ��е����ݶ��뵽����������
	ifstream infile("score.dat",ios::in);  //������ķ�ʽ���ļ�
	if(!infile)       //�����Ƿ�ɹ���
	{
		cerr<<"open error!"<<endl;
		exit(1);
	}
	for(i=0;i<100;i++)
	{
		infile>>sname>>scpp>>smath>>senglish;
		stud[i].set_value(sname, scpp, smath, senglish);
	}
	infile.close();
 
	//�������߷ּ��ܷ���߷�
	Student max_stud("nobody",0,0,0);  //max_stud��һ�������ڵ�ѧ�����洢��߷�
	for(i=0;i<100;i++)
	{
		if(stud[i].get_cpp()>max_stud.get_cpp()) max_stud.set_cpp(stud[i].get_cpp());
		if(stud[i].get_math()>max_stud.get_math()) max_stud.set_math(stud[i].get_math());
		if(stud[i].get_english()>max_stud.get_english()) max_stud.set_english(stud[i].get_english());
		if(stud[i].get_total()>max_stud.get_total()) max_stud.set_total(stud[i].get_total());
	}
 
	//���ܷ�����
	for(j=0;j<100-2;j++) 
	{
		for(i=0;i<100-j-1;i++)   
			if (stud[i].get_total()<stud[i+1].get_total()) 
			{
				t=stud[i]; 
				stud[i]=stud[i+1];
				stud[i+1]=t;
			}
	}
 
	//��ʾ���Ƽ��ֵܷ���߷�
	cout<<"C++��߷�Ϊ: "<<max_stud.get_cpp()<<endl;
	cout<<"�ߵ���ѧ��߷�Ϊ: "<<max_stud.get_math()<<endl;
	cout<<"Ӣ����߷�Ϊ: "<<max_stud.get_english()<<endl;
	cout<<"�ܷ���߷�Ϊ: "<<max_stud.get_total()<<endl;
 
	//�����ܷ������Ľ�������ļ�
	cout<<"�뵽�ļ�ordered_salary.txt�в鿴�����Ľ��"<<endl;
	ofstream outfile("ordered_salary.txt",ios::out); 
	if(!outfile)    
	{
		cerr<<"open error!"<<endl;
		exit(1);
	}
	for(i=0;i<100;i++)
	{
		outfile<<stud[i].get_name()<<"\t";
		outfile<<stud[i].get_cpp()<<"\t";
		outfile<<stud[i].get_math()<<"\t";
		outfile<<stud[i].get_english()<<"\t";
		outfile<<stud[i].get_total()<<endl;
	}
	outfile.close();    
	system("pause");
	return 0;
}