//��ָ���Ա�Ĺ�����

#include<iostream>
using namespace std;
class Salary
{
public:
    Salary(int n);
    ~Salary();
    void input_salary();
    void show_salary();
private:
    double *salary;
    int number;
};

Salary::Salary(int n)
{
    number=n;
    salary = new double[number];  //����ְ��������ȷ������ռ�Ĵ�С
}
Salary::~Salary()
{
    delete []salary;   //ע�⣺�����������������ͷŶ�̬����Ŀռ�
}

void Salary::input_salary()
{
    int i;
    cout << "������"<<number<<"��ְ���Ĺ���:" << endl;
    for(i = 0; i < number; ++i) 
        cin >> *(salary+i);
    return ;
}

void Salary::show_salary()
{
    cout << "ְ�������嵥: " ;
    for(int i = 0; i < number; ++i)
        cout << *(salary+i)<<" ";
    cout << endl;
    return ;
}

int main()
{
    Salary s(10);
    s.input_salary();
    s.show_salary();
    return 0;
}