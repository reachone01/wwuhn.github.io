#if 0     // �ļ���д�����

#include <fstream>
#include<iostream>
using namespace std;
int main( )
{
    float a[500],t;
    int i,j;
    ifstream infile("salary.txt",ios::in);  //������ķ�ʽ���ļ�
    if(!infile)       //�����Ƿ�ɹ���
    {
        cerr<<"open error!"<<endl;
        exit(1);
    }
    for(i=0;i<500;i++)
        infile>>a[i];   //���ļ��ж�ȡ����
    infile.close();
    for(i=0;i<10;i++)
        a[i]+=100;      //�ǹ�����
 
    for(j=0;j<500-2;j++)    //������ð�ݷ�������������
    {
        for(i=0;i<500-j-1;i++)   
            if (a[i]>a[i+1])
            {
                t=a[i];
                a[i]=a[i+1];
                a[i+1]=t;
            }
    }
    //������
    ofstream outfile("ordered_salary.txt",ios::out);
    if(!outfile)    //�����ļ��򿪲����Ƿ�ɹ������ɹ�����ʾ���˳���
    {
        cerr<<"open error!"<<endl;
        exit(1);
    }
    for(i=0;i<500;i++)
    {
        outfile<<a[i]<<endl;
        if(i%5==0) cout<<endl;
        cout<<a[i]<<"\t";
    }
    outfile.close();     //�ر��ļ��������˱���رգ�����ᶪʧ����
    system("pause");
    return 0;
}

#else

#include<iostream>    
#include<fstream>   
using namespace std;    

class Salary  
{  
public:  
    void ordered_salary_add();
    void ordered_salary();
    void input_salary();
    void ordered_salary_txt();
private:
    double salary[500];
    int number;  
};
int main()  
{  
    Salary s1; 
	//cout<<"500�˵�ԭʼ����Ϊ��"<<endl;
    s1.input_salary();  
    //cout<<endl;  
    cout<<"�������Ϊ:";  
    cout<<endl;  
    s1.ordered_salary();  
    cout<<endl;  
	s1.ordered_salary_txt();
	system("PAUSE");  
    return 0;  
}
void Salary::input_salary()  
{  
    int i=0;  
	ifstream infile("salary.txt",ios::in);
	if (!infile)
	{
		cerr<<"open error!"<<endl;
		exit(1);
	}
	for (i=0;i<500;i++)
		infile>>salary[i];
	infile.close();
	//for(i=0;i<500;i++)
		//cout<<salary[i]<<"  ";
	//cout<<endl;
    number=500;  
}
void Salary::ordered_salary_add()  
{  
    int i;  
    for (i=0;i<number;i++)  
    {  
        salary[i]=salary[i]+100;  
        //cout<<salary[i]<<"  ";  
    }  
    return;  
}  
void Salary::ordered_salary()  
{  
	
    int i,j;  
    double t;  
    for(i=0;i<number-1;i++) 
	{
        for(j=0;j<number-i-1;j++) 
		{
            if(salary[j]>salary[j+1])  
            {  
                t=salary[j];  
                salary[j]=salary[j+1];  
                salary[j+1]=t;  
            }  
		}
	}
	for (i=0;i<number;i++)  
	{  
		cout<<salary[i]<<"  ";  
	}  
	return;  
}  
 
void Salary::ordered_salary_txt()
{
	ofstream outfile("ordered_salary.txt",ios::out);
	if(!outfile)
	{
		cerr<<"open error!"<<endl;
		exit(1);
	}
	for(int i=0;i<500;i++)
		outfile<<salary[i]<<"\n";
	outfile.close();
	return ;
}


#endif