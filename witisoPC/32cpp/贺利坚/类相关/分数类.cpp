#include<iostream>  // ������
#include<Cmath>
using namespace std;
enum OutStyle{original, simplified, mixed, approximate};
int gcd(int m, int n);
class CFraction
{
private:
    int nume;  // ����
    int deno;  // ��ĸ
public:
    CFraction(int nu=0,int de=1);   //���캯������ʼ����
    void set(int nu=0,int de=1);    //��ֵ���ı�ֵʱ��
    void input();				    //����"nu/de"�ĸ�ʽ����"5/2"����ʽ����
    void simplify();			    //����ʹ���ӷ�ĸû�й����ӣ�
    void amplify(int n);			//�Ŵ�n������/3�Ŵ�Ϊ/3
    void output(OutStyle style=original);	
};

CFraction::CFraction(int nu,int de) //���캯������ʼ����
{
    if (de!=0)
    {
        nume=nu;
        deno=de;
    }
    else
    {
        cerr<<"��ʼ���з������󣬳����˳�\n";
        system("pause");
        exit(0);
    }
}

void CFraction::set(int nu,int de)    //��ֵ���ı�ֵʱ��
{
    if (de!=0) //��������ʣ��ı�ֵ������Ч
    {
        nume=nu;
        deno=de;
    }
}

void CFraction::input()				//����"nu/de"�ĸ�ʽ����"5/2"����ʽ����
{
    int nu,de;
    char c;
    while(1)
    {
        cout<<"�������(m/n): ";
        cin>>nu>>c>>de;
        if(c!='/')
            cout<<"�����ʽ����\n ";
        else if (de==0)
            cout<<"��ĸ����Ϊ�㣡\n ";
        else
            break;
    }	
    nume=nu;
    deno=de;
}

// ��������ʹ���ӷ�ĸû�й�����
void CFraction::simplify()
{
    int n=gcd(deno, nume);
    deno/=n;     // ����
    nume/=n;
}

// ��m��n�����Լ��
int gcd2(int m, int n)
{
    while(n!=0)  // ��m��n�����Լ��
    {
        int r = m%n;
        m=n;
        n=r;
    }
    return m;
}
// ��m��n�����Լ��
int gcd(int m, int n)
{
    int r;
    //if (m<n){r=m;m=n;n=r;}
    while(r=m%n)  // ��m��n�����Լ��
    {
        m=n;
        n=r;
    }
    return n;
}
void CFraction::amplify(int n)  //�Ŵ�n������/3�Ŵ�Ϊ/3
{
    nume*=n;
}

//�����������8/6Ϊ��
//styleΪoriginalʱ��ԭ�������8/6��
//styleΪsimplifiedʱ������������ʽ��4/3��
//styleΪmixedʱ���ô�������ʽ�����1(1/3)����ʾһ������֮һ��
//styleΪapproximateʱ�������ʵ����ʾ���ƽ�ֵ��1.33333
//����������ʱ��Ĭ�Ϸ�ʽΪoriginal
void CFraction::output(OutStyle style)
{
    int n,nu,de;
    switch(style)
    {
    case original:
        cout<<"ԭ��:" <<nume<<'/'<<deno<<endl; 
        break;
    case simplified:
        n=gcd(deno, nume);
        cout<<"������ʽ: "<<nume/n<<'/'<<deno/n<<endl;     //���������ʽ��������Ҫ����
        break;
    case mixed:
        n=gcd(deno, nume);
        nu=nume/n; 
        de=deno/n;
        cout<<"��������ʽ:" <<nu/de<<'('<<nu%de<<'/'<<de<<')'<<endl; 
        break;
    case approximate:
        cout<<"����ֵ:" <<nume/double(deno)<<endl; 
        break;
    default:
        cout<<"Ĭ��ԭ��:" <<nume<<'/'<<deno<<endl;	
    }
}

int main()
{
    CFraction c1,c2(8,6);
    
    cout<<"����c1: "<<endl;
    c1.output(original);
    
    cout<<"�ı�c1: "<<endl;
    c1.set(2,7);
    c1.output();
    
    cout<<"����c1: "<<endl;
    c1.input();
    c1.output(original);
 c1.output(simplified);   
     c1.output(original);
    cout<<"����c2: "<<endl;
    c2.output(original);
    c2.output(simplified); 
    c2.output(mixed); 
    c2.output(approximate);
    
    cout<<"��c2����: "<<endl;
    c2.simplify();
    c2.output(original);
    
    cout<<"��c2�Ŵ�: "<<endl;
    c2.amplify(5);
    c2.output(original);
    c2.output(mixed); 
    
    system("pause");
    return 0;
}

/*

����2��չ2��˼���������˼�����һ�´�ҵ�θ�ڣ��趨��������������Ķ���
��CFraction c1, c2�����������int i����������cin>>i;�ڼ���������i��ֵ��
�Ƿ�������cin>>c1>>c2;��������أ�ͬ����cout<<c1<<c2;���������������
��һ������c1+c2�õ��µ�һ����������c1/c2ʵ�����������ĳ������Լ������ӡ������Ƚϡ�
������Ҳ��������Ȼ�ġ�ʵ���ϣ�Ҫ�Զ�������࣬��Щֱ�۵Ļ�������Ӧ��Ҫʵ�֣�
�������������ء�����������amplify()�����ˡ��Ŵ������һ��ʵ�ַ�������������ֵ���ڴ��ء�




*/















