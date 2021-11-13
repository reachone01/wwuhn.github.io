#include <iostream>
using namespace std;  // �������е����������
class CFraction
{
private:
    int nume;  // ����
    int deno;  // ��ĸ
public:
    CFraction(int nu=0,int de=1):nume(nu),deno(de){}
    void simplify();
    void display();
    CFraction operator+(const CFraction &c);  //����������ӣ����Ҫ����
    CFraction operator-(const CFraction &c);  //����������������Ҫ����
    CFraction operator*(const CFraction &c);  //����������ˣ����Ҫ����
    CFraction operator/(const CFraction &c);  //����������������Ҫ����
    CFraction operator+();  //ȡ��һĿ����
    CFraction operator-();  //ȡ��һĿ����
    bool operator>(const CFraction &c);
    bool operator<(const CFraction &c);
    bool operator==(const CFraction &c);
    bool operator!=(const CFraction &c);
    bool operator>=(const CFraction &c);
    bool operator<=(const CFraction &c);
};

// ��������
void CFraction::simplify()
{
    int m,n,r;
    n=abs(deno);
    m=abs(nume);
    while(r=m%n)  // ��m��n�����Լ��
    {
        m=n;
        n=r;
    }
    deno/=n;     // ����
    nume/=n;
    if (deno<0)  // ����ĸת��Ϊ����
    {
        deno=-deno;
        nume=-nume;
    }
}

//��ʾ����
void CFraction::display()
{
    cout<<"("<<nume<<"/"<<deno<<")"<<endl;
}

// �������
CFraction CFraction::operator+(const CFraction &c)
{
    CFraction t;
    t.nume=nume*c.deno+c.nume*deno;
    t.deno=deno*c.deno;
    t.simplify();
    return t;
}

// �������
CFraction CFraction:: operator-(const CFraction &c)
{
    CFraction t;
    t.nume=nume*c.deno-c.nume*deno;
    t.deno=deno*c.deno;
    t.simplify();
    return t;
}

// �������
CFraction CFraction:: operator*(const CFraction &c)
{
    CFraction t;
    t.nume=nume*c.nume;
    t.deno=deno*c.deno;
    t.simplify();
    return t;
}

// �������
CFraction CFraction:: operator/(const CFraction &c)
{
    CFraction t;
    if (!c.nume) return *this;   //������Ч������Ϊ0��ʱ�����������Ҫ���ǣ������ִ����Բ������
    t.nume=nume*c.deno;
    t.deno=deno*c.nume;
    t.simplify();
    return t;
}

// ����ȡ����
CFraction CFraction:: operator+()
{
    return *this;
}

// ����ȡ����
CFraction CFraction:: operator-()
{
    CFraction x;
    x.nume=-nume;
    x.deno=deno;   //��������������߼�����numeȡ���ˣ�deno�Ͳ���ȡ���ˡ�лл����ָ��
    return x;     
}

// �����Ƚϴ�С
bool CFraction::operator>(const CFraction &c)
{
    int this_nume,c_nume,common_deno;
    this_nume=nume*c.deno;        // �������ͨ�ֺ�ķ��ӣ�ͬ��ĸΪdeno*c.deno
    c_nume=c.nume*deno; 
    common_deno=deno*c.deno;
    //if (this_nume>c_nume) return true; �޷�Ӧ��common_deno<0������
    //���������������һ��д��if ((this_nume-c_nume)*common_deno>0) return true;
    if (this_nume>c_nume&&common_deno>0||this_nume<c_nume&&common_deno<0) 
        return true; // ��ͨ�ֺ�ķ��ӱȽϴ�С
    return false;
}//����������������ͬѧָ����Ϊʲô�ڱȽϴ�С��ʱ��������������ֱ�������ж��Ƿ�����㰡��
// �һش𣺡�����뷨�ҳ��ã�������������

// �����Ƚϴ�С
bool CFraction::operator<(const CFraction &c)
{
    int this_nume,c_nume,common_deno;
    this_nume=nume*c.deno;      
    c_nume=c.nume*deno;
    common_deno=deno*c.deno;
    if ((this_nume-c_nume)*common_deno<0) return true; 
    return false;
}

// �����Ƚϴ�С
bool CFraction::operator==(const CFraction &c)
{
    if (*this!=c) return false;
    return true;
}

// �����Ƚϴ�С
bool CFraction::operator!=(const CFraction &c)
{
    if (*this>c || *this<c) return true;
    return false;
}

// �����Ƚϴ�С
bool CFraction::operator>=(const CFraction &c)
{
    if (*this<c) return false;
    return true;
}

// �����Ƚϴ�С
bool CFraction::operator<=(const CFraction &c)
{
    if (*this>c) return false;
    return true;
}

int main()
{
    CFraction x(1,3),y(-5,10),s;
    cout<<"����x=1/3      y=-5/10"<<endl;
    s=+x+y;
    cout<<"+x+y=";
    s.display();
    s=x-y;
    cout<<"x-y=";
    s.display();
    s=x*y;
    cout<<"x*y=";
    s.display();
    s=x/y;
    cout<<"x/y=";
    s.display();
    s=-x+y;
    cout<<"-x+y=";
    s.display();
    
    x.display();
    if (x>y) cout<<"����"<<endl;
    if (x<y) cout<<"С��"<<endl;
    if (x==y) cout<<"����"<<endl;
    y.display();
    cout<<endl;
    system("pause");
    return 0;
}