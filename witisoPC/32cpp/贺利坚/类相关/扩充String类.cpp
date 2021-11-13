/*
����String�ࡿ��String��������һ�����ݳ�Աlen��ʾ�ַ������ַ�������
Ȼ����String���������㡣��Щ������԰�����
s1 + s2���������ַ��������ӣ�
s1 - s2���ڽ�s1��β���ո��s2��ǰ���ո�ȥ��������ӣ�
s1*n�Ľ��Ϊ��s1�е��ַ��ظ�n�Σ�
s1/s2��ʾ��s1��ɾ��������s2��ͬ���Ӵ���
��Щ���㱾����ͳһ�Ĺ淶������һЩ�ַ����ϵĲ��������������������ʵ��֮��
*/

#include <iostream.h>
#include <Cstring>
 
class String
{
public:
    String( );                         //Ĭ�Ϲ��캯��
    String(const char *s);
    String(String &str);               //���캯��
    ~String();
    void display( );
    friend String operator + (String &s1,String &s2 );
    friend String operator - (String &s1,String &s2 );
    friend String operator * (String &s1,int n );       //δʵ��,�ȷ�������
    friend String operator / (String &s1,String &s2 );  //δʵ�֣��ȷ�������
private:
    char *p;
    int len;                                       //�ַ���ָ�룬����ָ���ַ���
};
String::String()
{
    len = 0;
    p = NULL;
}

String::String(const char *s)
{
    len = strlen(s);
    p = new char[len+1];
    strcpy(p,s);
}
 
String::String(String &str)
{
    len = str.len;
    p = new char[len+1];
    strcpy(p,str.p);
}
 
String::~String()
{
    if(!p)
        delete []p;
}
 
void String::display( )     //���p��ָ����ַ���
{
    cout<<p<<endl;
}
 
String operator + (String &s1, String &s2 )
{
    String s;
    s.len = s1.len+s2.len;
    s.p = new char(s.len+1);
    strcpy(s.p,s1.p);
    strcat(s.p,s2.p);
    return s;
}
 
String operator - (String &s1, String &s2 )
{
    String s;
    //c1Ϊ��ȥβ���ո���ַ���
    char *c1=new char[s1.len+1];
    strcpy(c1,s1.p);
    int i=s1.len-1;
    while(i>=0&&c1[i]==' ') --i;
    c1[i+1]='\0';
 
    //c2Ϊȥ��ǰ���ո���ַ���
    char *c2=new char[s2.len+1];
    strcpy(c2,s2.p);
    i=0;
    while(i<s2.len&&c2[i]==' ') ++i;
    int j=0;
    while(i<s2.len&&c2[i]!='\0')
    {
        c2[j]=c2[i];
        ++i;
        ++j;
    }
    c2[j+1]='\0';
 
    //���������ֽ�����
    s.len = strlen(c1)+strlen(c2);
    s.p = new char(s.len+1);
    strcpy(s.p,c1);
    strcat(s.p,c2);
    delete c1;
    delete c2;
    return s;
}
 
int main( )
{
    String string1(" Hello  "),string2(" World ");
    string1.display();

    String string3;
    string3 = string1 + string2;
    string3.display();
    string3 = string1 - string2;
    string3.display();
    while(1);
    return 0;
}