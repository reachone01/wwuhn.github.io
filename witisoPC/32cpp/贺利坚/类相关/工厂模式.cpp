//����ģʽ
#include<iostream>
using namespace std;
//���ࣺ������
class COperation
{
public:
    double numberA;
    double numberB;
    virtual double getResult() = 0;
};
//�ӷ�
class AddOperation: public COperation
{
public:
    virtual double getResult()
    {
        return numberA+numberB;
    }
};
//����
class SubOperation: public COperation
{
public:
    virtual double getResult()
    {
        return numberA-numberB;
    }
};
//�˷�
class MultiOperation: public COperation
{
public:
    virtual double getResult()
    {
        return numberA*numberB;
    }
};
//����
class DivOperation: public COperation
{
public:
    virtual double getResult()
    {
        return numberA/numberB;
    }
};
//������
class CCalculatorFactory
{
public:
    static COperation* Create(char cOperator);
};
 
 
COperation* CCalculatorFactory::Create(char cOperator)
{
    COperation *oper;
 
 
    switch (cOperator)
    {
    case '+':
        oper=new AddOperation();
        break;
    case '-':
        oper=new SubOperation();
        break;
    case '*':
        oper=new MultiOperation();
        break;
    case '/':
        oper=new DivOperation();
        break;
    default:
        oper=new AddOperation();
        break;
    }
    return oper;
}
 
 
int main()
{
restart:
    double a,b;
    char ch;
    cout<<"������ʽ����3+4��";
    cin>>a>>ch>>b;
    COperation * op=CCalculatorFactory::Create(ch);
    op->numberA=a;
    op->numberB=b;
    cout<<op->getResult()<<endl;
    goto restart;
    return 0;
}