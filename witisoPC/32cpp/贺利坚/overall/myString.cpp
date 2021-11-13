/*
����Ҫ������ַ�����CMyString��
���ݳ�Ա������
- �ַ����ĳ��ȣ�
- ָ���ַ�����һ���ַ���ָ��
��Ա����������
- ���������Ĺ��캯����
- ��һ������Ϊconst char *���͵Ĳ���(���ڶ��ַ�����ʼ��)�Ĺ��캯����
- ��һ��const CMyString&���͵ĸ��ƹ��������
- ����������
- Strlen���� (�������ַ����ĳ���)��
- int Find(char c) (�ҳ��ַ�c�ڱ��ַ����е�һ�γ��ֵ�λ�ã����������±ꣻ������ַ����в�����c���򷵻�-1)��
- int Find(const char *str1) ( �ҳ��ַ���str1�ڱ��ַ����е�һ�γ��ֵ�λ�ã����������±ꣻ������ַ����в������ַ���str1���򷵻�-1),
- int Find(const CMyString&  str1) (�ҳ��ַ���str1�ڱ��ַ����е�һ�γ��ֵ�λ�ã����������±ꣻ������ַ����в������ַ���str1���򷵻�-1)��
- int Replace(char c1, char c2) (�����ַ����г��ֵ������ַ�c1���ַ�c2�滻, �����滻�Ĵ���)��
- void Replace(const char *str1, const char *str2) (�����ַ����е�һ�γ��ֵ��ַ���str1���ַ���str2�滻)��
- void Display() (������ʾ�ַ���)
�������[]+=�Ƚ������أ����磬��str1��str2������CMyString��Ķ���
- ��str1[i]��ʾ�ַ���str1���±�Ϊi���ַ���
- str1+str2�Ľ���ǽ�str2����str1�ĺ��棬���������Ȼ����� str1�У�
- ��=��ʾ��ֵ��
(2)��д�����������弸��CMyString��Ķ��󣬲����ü��������ַ��������ݣ������֤���϶�������к�����
*/
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;


class CMyString
{
private:
    int m_nLen;
    char *m_szStr;
public:
    CMyString(void);
    CMyString(const char *str);
    CMyString(const CMyString& str1);
    ~CMyString(void);
    int Strlen(void);
    int Find(char c);
    int Find(const char *str1);
    int Find(const CMyString&  str1);
    int Replace(char  c1, char c2);
    void Replace(const char *str1, const char *str2);
    char& operator[](int i);
    CMyString operator+(const CMyString& str1);
    CMyString& operator=(const CMyString& str1);
    void Display()
    {
        cout<<m_szStr<<endl;
    };
};


//ע�������������캯���о�Ҫ����洢�ռ�
CMyString::CMyString(void)
{
    m_nLen=0;
    m_szStr=new char[m_nLen+1];//+1�Ŀռ����ڴ���ַ���������־
    strcpy(m_szStr,"");
}


CMyString::CMyString(const char *str)
{
    m_nLen=strlen(str);
    m_szStr=new char[m_nLen+1];
    strcpy(m_szStr,str);
}


CMyString::CMyString(const CMyString& str1)
//���ƹ��캯����ע�⸴�ƹ��캯������ơ�ǳ�������⣬��������д��
//{
//	m_szStr=str1.m_szStr;
//	m_nLen=str1.m_nLen;
//}
//�ǲ���ȷ�ġ�
{
    m_nLen=str1.m_nLen;
    m_szStr=new char[m_nLen+1];
    strcpy(m_szStr,str1.m_szStr);
}


CMyString::~CMyString(void)
{
    delete []m_szStr;
}


int CMyString::Strlen(void)
{
    return m_nLen;
}


int CMyString::Find(char c)
//�ҳ��ַ�c�ڱ��ַ����е�һ�γ��ֵ�λ�ã����������±ꣻ������ַ����в�����c���򷵻�-1
{
    int i=0;
    while(m_szStr[i]!='\0'&&m_szStr[i]!=c)
        i++;
    if (m_szStr[i]=='\0')
        return -1;
    else
        return i;
}


int CMyString::Find(const char *str1)
// �ҳ��ַ���str1�ڱ��ַ����е�һ�γ��ֵ�λ�ã����������±ꣻ������ַ����в������ַ���str1���򷵻�-1
{
    int len=strlen(str1);
    int find=0;
    int i;
    //��CMyString����ӵ�i���ַ���ʼ�ģ�������str1��ȵ��ַ���������str1�Ƚ�
    for(i=0; i<=m_nLen-len; i++)
    {
        find=1;
        for(int j=0; j<len; j++)
            if(m_szStr[i+j]!=str1[j])
                find=0;
            if (find) break;
    }
    if (find)
        return i;
    else
        return -1;
}


int CMyString::Find(const CMyString&  str1)
// �ҳ��ַ���str1�ڱ��ַ����е�һ�γ��ֵ�λ�ã����������±ꣻ������ַ����в������ַ���str1���򷵻�-1
{
    int len=str1.m_nLen;
    int find=0;
    int i;
    for(i=0; i<=m_nLen-len; i++)
    {
        find=1;
        for(int j=0; j<len; j++)
            if(m_szStr[i+j]!=str1.m_szStr[j])
                find=0;
            if (find) break;
    }
    if (find)
        return i;
    else
        return -1;
}


int CMyString::Replace(char  c1, char c2)
//�����ַ����г��ֵ������ַ�c1���ַ�c2�滻, �����滻�Ĵ���
{
    int count=0;
    for(int i=0; i<m_nLen; i++)
    {
        if (m_szStr[i]==c1)
        {
            count++;
            m_szStr[i]=c2;
        }
    }
    return count;
}


void CMyString::Replace(const char *str1, const char *str2)
//�����ַ����е�һ�γ��ֵ��ַ���str1���ַ���str2�滻
{
    int i=Find(str1);  //iΪsrt1�ڱ��ַ������״γ��ֵ�λ��
    int j;
    if (i>=0)
    {
        int len1=strlen(str1),len2=strlen(str2);
        if (len1!=len2) //str1��str2���Ȳ����
        {
            int len=m_nLen-len1+len2;
            char *result=new char[len+1];
            //���CMyString�����str1������ַ������������ַ���temp��
            char *temp;
            temp=new char[m_nLen-i-len1+1];
            for (j=0; j<m_nLen-i-len1; j++)
            {
                temp[j]=m_szStr[i+len1+j];
            }
            temp[j]='\0';
            ///��CMyString�����д�str1��ǰ���ַ�����str2�����result
            for(j=0; j<i; j++)
                result[j]=m_szStr[j];
            for(j=0; j<len2; j++)
                result[i+j]=str2[j];
            result[i+j]='\0';
            // ��CMyString�����str1������ַ���(��temp)��ӵ���ǰresult(��CMyString�����str1��ǰ���ַ�����str2���ɣ�֮��,
            strcat(result,temp);
            //��result�����µ�*this
            delete []m_szStr;  //�ͷ�ԭ�пռ䣬�µ��ַ����ռ伴result��ָ�Ŀռ�
            m_szStr=result;
            m_nLen=len;
            delete []temp;
        }
        else    //str1��str2������ȣ�ֱ���滻����
        {
            for(int j=0; j<len1; j++)
                m_szStr[i+j]=str2[j];
        }
    }
}


CMyString CMyString::operator+(const CMyString& str1)
//���ַ���+str1�Ľ���ǽ�str1���ڱ��ַ����ĺ��棬���������Ȼ����ڱ��ַ�����
{
    int len1=str1.m_nLen;
    int len=m_nLen+len1;
    int j;
    char *result=new char[len+1];
    for(j=0; j<m_nLen; j++)
        result[j]=m_szStr[j];
    result[j]='\0';
    strcat(result,str1.m_szStr);
    delete []m_szStr;
    m_szStr=result;
    m_nLen=len;
    return *this;
}


//ע������������Ա��������ֵ����Ϊ��������
char& CMyString::operator[](int i)
//��str1ΪCMystring��Ķ���str1[i]��ʾstr1��Ӧ�Ĵ����±�Ϊi���ַ�,
{
    if (i<0||i>m_nLen-1)
    {
        cout<<"index out of range."<<endl;
        exit(1);
    }
    return m_szStr[i];
}


CMyString& CMyString::operator=(const CMyString& str1)
{
    int len1=str1.m_nLen;
    if (m_nLen!=len1)
    {
        delete []m_szStr;
        m_szStr=new char[len1+1];
        m_nLen=len1;
    }
    strcpy(m_szStr,str1.m_szStr);
    return *this;
}


int main()
{
    //���������Ϣ�е��ַ������кž���0��ʼ
    char *str="Hello!";
    /*����ֱ���
    CMyString(void);
    CMyString(const char *str);
    CMyString(const CMyString& str1);
    ���ַ�ʽ�����ַ�������str1��str2��str3*/
    CMyString str1,str2(str),str3(str2);
    cout<<"str1 is:";
    str1.Display();
    cout<<"str2 is:";
    str2.Display();
    cout<<"str3 is:";
    str3.Display();
    
    
    cout<<"length of str2 is:"<<str2.Strlen()<<endl;
    
    
    //int Find(char c);����֤
    cout<<"'H' is the "<<str2.Find('H')+1<<" char in str2"<<endl;
    cout<<"'!' is the "<<str2.Find('!')+1<<" char in str2"<<endl;
    cout<<"'s' is the "<<str2.Find('s')+1<<" char in str2"<<endl;
    
    
    //int Find(const char *str1);����֤
    cout<<"\"ell\" is from "<<str2.Find("ell")+1<<" char in str2"<<endl;
    cout<<"\"o\" is from "<<str2.Find("o")+1<<" char in str2"<<endl;
    cout<<"\"Heli\" is from "<<str2.Find("Heli")+1<<" char in str2"<<endl;
    
    
    //int Find(const CMyString&  str1);����֤
    char *str_1=new char[20],*str_2=new char[20];
    cout<<"input a string:";
    //����ķ�����������һ�в�����20���ַ����Իس�Ϊ�����Ŀɰ����ո���ַ���
    //cin>>str_1;����������ո���ַ���
    cin.getline(str_1,20,'\n');
    cout<<"input the string to be finded:";
    cin.getline(str_2,20,'\n');
    CMyString str4(str_1),str5(str_2);
    cout<<str4.Find(str5)<<endl;
    delete[]str_1;
    delete[]str_2;
    
    
    //int Replace(char  c1, char c2);����֤
    char *str_3=new char[20];
    char c1,c2;
    cout<<"input a string:";
    cin.getline(str_3,20,'\n');
    cout<<"input c1:";
    cin>>c1;
    cout<<"input c2:";
    cin>>c2;
    CMyString str6(str_3);
    cout<<"replace "<<'\''<<c1<<'\''<<" of "<<"this string"<<" with "<<'\''<<c2<<'\''<<' ';
    cout<<str6.Replace(c1,c2)<<" times "<<endl<<"after replace the string is: ";
    str6.Display();
    delete[]str_3;
    
    
    //void Replace(const char *str1, const char *str2);����֤
    char *str_4=new char[20];
    char str_5[5],str_6[5];
    cout<<"input a string:";
    cin.getline(str_4,20,'\n');  //������ȡ��������ʣ���'\n'
    cin.getline(str_4,20,'\n');  //��ʽ�����ַ���
    cout<<"input the str1 in this string to be changed:";
    cin>>str_5;
    cout<<"input the str2 you want to change to:";
    cin>>str_6;
    CMyString str7(str_4);
    cout<<"replace first time of "<<"\""<<str_5<<"\""<<" in this string with "<< "\""<<str_6<<"\""<<" is ";
    str7.Replace(str_5,str_6);
    str7.Display();
    
    
    //�����[]+=����֤
    cout<<"the 2nd charcter after replace is:"<<str7[2]<<endl;
    while(1);
    return 0;
}