#include <iostream>
using namespace std; // �������е���������أ��������������㣩
class CFraction
{
private:
    int nume;  // ����
    int deno;  // ��ĸ
public:
    CFraction(int nu=0,int de=1):nume(nu),deno(de){}
    void simplify();
    void display();
    
    friend CFraction operator+(const CFraction &c1, const CFraction &c2);  //����������ӣ����Ҫ����
    friend CFraction operator-(const CFraction &c1, const CFraction &c2);  //����������������Ҫ����
    friend CFraction operator*(const CFraction &c1, const CFraction &c2);  //����������ˣ����Ҫ����
    friend CFraction operator/(const CFraction &c1, const CFraction &c2);  //����������������Ҫ����
    
    friend CFraction operator+(const CFraction &c, int i);  
    friend CFraction operator+(int i, const CFraction &c );  
    friend CFraction operator-(const CFraction &c, int i);  
    friend CFraction operator-(int i, const CFraction &c );  
    friend CFraction operator*(const CFraction &c, int i);  
    friend CFraction operator*(int i, const CFraction &c );  
    friend CFraction operator/(const CFraction &c, int i);  
    friend CFraction operator/(int i, const CFraction &c );  
    
    CFraction operator+();  //ȡ��һĿ����
    CFraction operator-();  //ȡ��һĿ����
    
    friend bool operator>(const CFraction &c1, const CFraction &c2);
    friend bool operator<(const CFraction &c1, const CFraction &c2);
    friend bool operator==(const CFraction &c1, const CFraction &c2);
    friend bool operator!=(const CFraction &c1, const CFraction &c2);
    friend bool operator>=(const CFraction &c1, const CFraction &c2);
    friend bool operator<=(const CFraction &c1, const CFraction &c2);
    
    friend bool operator>(const CFraction &c, int i);
    friend bool operator>(int i, const CFraction &c);
    friend bool operator<(const CFraction &c, int i);
    friend bool operator<(int i, const CFraction &c);	
    friend bool operator==(const CFraction &c, int i);
    friend bool operator==(int i, const CFraction &c);	
    friend bool operator!=(const CFraction &c, int i);
    friend bool operator!=(int i, const CFraction &c);
    friend bool operator>=(const CFraction &c, int i);
    friend bool operator>=(int i, const CFraction &c);
    friend bool operator<=(const CFraction &c, int i);
    friend bool operator<=(int i, const CFraction &c);
};

// ��������
void CFraction::simplify()
{
    int m,n,r;
    m=abs(deno);
    n=abs(nume);
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
CFraction operator+(const CFraction &c1, const CFraction &c2)
{
    CFraction t;
    t.nume=c1.nume*c2.deno+c2.nume*c1.deno;
    t.deno=c1.deno*c2.deno;
    t.simplify();
    return t;
}

// �������
CFraction operator-(const CFraction &c1, const CFraction &c2)
{
    CFraction t;
    t.nume=c1.nume*c2.deno-c2.nume*c1.deno;
    t.deno=c1.deno*c2.deno;
    t.simplify();
    return t;
}

// �������
CFraction operator*(const CFraction &c1, const CFraction &c2)
{
    CFraction t;
    t.nume=c1.nume*c2.nume;
    t.deno=c1.deno*c2.deno;
    t.simplify();
    return t;
}

// �������
CFraction operator/(const CFraction &c1, const CFraction &c2)
{
    CFraction t;
    if (!c2.nume) return c1;
    t.nume=c1.nume*c2.deno;
    t.deno=c1.deno*c2.nume;
    t.simplify();
    return t;
}

CFraction operator+(const CFraction &c, int i)
{
    CFraction c1(c.nume+i*c.deno,c.deno);
    c1.simplify();
    return c1;
}

CFraction operator+(int i, const CFraction &c )
{
    CFraction c1(c.nume+i*c.deno,c.deno);
    c1.simplify();
    return c1;
}

CFraction operator-(const CFraction &c, int i)  
{
    CFraction c1(c.nume-i*c.deno,c.deno);
    c1.simplify();
    return c1;
}

CFraction operator-(int i, const CFraction &c )
{
    CFraction c1(i*c.deno-c.nume,c.deno);
    c1.simplify();
    return c1;
}
CFraction operator*(const CFraction &c, int i)
{
    CFraction c1(c.nume*i,c.deno);
    c1.simplify();
    return c1;
}

CFraction operator*(int i, const CFraction &c )
{
    CFraction c1(c.nume*i,c.deno);
    c1.simplify();
    return c1;
}

CFraction operator/(const CFraction &c, int i)
{
    CFraction c1(c.nume,c.deno*i);
    c1.simplify();
    return c1;
}

CFraction operator/(int i, const CFraction &c )
{
    CFraction c1(i*c.deno,c.nume);
    c1.simplify();
    return c1;
}

// ����ȡ����
CFraction CFraction:: operator+()
{
    return *this;
}

// ����ȡ����
CFraction CFraction:: operator-()
{
    CFraction c;
    c.nume=-nume;
    c.deno=-deno;
    return c;     
}

// �����Ƚϴ�С
bool operator>(const CFraction &c1, const CFraction &c2)
{
    int c1_nume,c2_nume,common_deno;
    c1_nume=c1.nume*c2.deno;        // �������ͨ�ֺ�ķ��ӣ�ͬ��ĸΪc1.deno*c2.deno
    c2_nume=c2.nume*c1.deno; 
    common_deno=c1.deno*c2.deno;
    //if (c1_nume>c2_nume) return true; �޷�Ӧ��common_deno<0������
    //���������������һ��д��if ((c1_nume-c2_nume)*common_deno>0) return true;
    if (c1_nume>c2_nume&&common_deno>0||c1_nume<c2_nume&&common_deno<0) return true; // ��ͨ�ֺ�ķ��ӱȽϴ�С
    return false;
}

// �����Ƚϴ�С
bool operator<(const CFraction &c1, const CFraction &c2)
{
    int c1_nume,c2_nume,common_deno;
    c1_nume=c1.nume*c2.deno;      
    c2_nume=c2.nume*c1.deno;
    common_deno=c1.deno*c2.deno;
    if ((c1_nume-c2_nume)*common_deno<0) return true; 
    return false;
}

// �����Ƚϴ�С
bool operator==(const CFraction &c1, const CFraction &c2)
{
    if (c1!=c2) return false;
    return true;
}

// �����Ƚϴ�С
bool operator!=(const CFraction &c1, const CFraction &c2)
{
    if (c1>c2 || c1<c2) return true;
    return false;
}

// �����Ƚϴ�С
bool operator>=(const CFraction &c1, const CFraction &c2)
{
    if (c1<c2) return false;
    return true;
}

// �����Ƚϴ�С
bool operator<=(const CFraction &c1, const CFraction &c2)
{
    if (c1>c2) return false;
    return true;
}

bool operator>(const CFraction &c, int i)
{
    if(c.deno>0) 
        return c.nume>(i*c.deno);
    else 
        return c.nume<(i*c.deno);
}

bool operator>(int i, const CFraction &c)
{
    if(c.deno>0) 
        return (i*c.deno)>c.nume;
    else 
        return (i*c.deno)<c.nume;
}

bool operator<(const CFraction &c, int i)
{
    if(c.deno>0) 
        return c.nume<(i*c.deno);
    else 
        return c.nume>(i*c.deno);
}

bool operator<(int i, const CFraction &c)
{
    if(c.deno>0) 
        return (i*c.deno)<c.nume;
    else 
        return (i*c.deno)>c.nume;
}

bool operator==(const CFraction &c, int i)
{
    return c.nume==(i*c.deno);
}

bool operator==(int i, const CFraction &c)
{
    return c.nume==(i*c.deno);
}

bool operator!=(const CFraction &c, int i)
{
    return c.nume!=(i*c.deno);
}

bool operator!=(int i, const CFraction &c)
{
    return c.nume!=(i*c.deno);
}

bool operator>=(const CFraction &c, int i)
{
    return !(c<i);
}

bool operator>=(int i, const CFraction &c)
{
    return !(i<c);
}

bool operator<=(const CFraction &c, int i)
{
    return !(c>i);
}

bool operator<=(int i, const CFraction &c)
{
    return !(i>c);
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
    
    CFraction c1(5,3),c2;
    //���½����ڵ��Ի�������ɲ��ԣ�
    c2=c1+5;
    c2=5+c1;
    
    c2=c1-5;
    c2=5-c1;
    
    c2=c1*5;
    c2=5*c1;
    
    c2=c1/5;
    c2=5/c1;
    
    bool b;
    
    b=(c1>2);
    b=(2>c1);
    
    system("pause");
    return 0;
}