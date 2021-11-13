/*
�ڻ�������ʹ�õ�IP��ַռ4�ֽڣ��������Ķη���ʾ��ÿ��ֵ�ķ�ΧΪ0-255���м��á�.������
������202.194.116.97����ʵ��Ҳ���Կ���һ����4�ֽڵ��޷�������ֵ3401741409��
�����һ��IP��ַ�࣬���ڱ���IP��ַ����ʵʩ��IP��ַ�ϵ�һЩ������
*/
#if 1

#include <iostream>
using namespace std;
class IP
{
private:
    union
    {
        struct
        {
            unsigned char seg0;
            unsigned char seg1;
            unsigned char seg2;
            unsigned char seg3;
        };                      //IP��ַ��4�ֽڣ����߿��ɽṹ����ָ4����
        unsigned int address;   //���߿���һ������
    };
public:
    IP(int=0,int=0,int=0,int=0);    //���캯��
    void showIP();                  //���Ķη���ʾIP��ַ
    bool sameSubnet(const IP &ip, const IP &mark);  //�ж��Ƿ���ͬһ����
    char whatKind();                                //����������һ������
};

IP::IP(int s0,int s1,int s2,int s3)
{
    //���渳ֵ��˳���漰�������ݴ洢�ṹ���ο�[�������������ڴ�����δ洢����](http://blog.csdn.net/sxhelijian/article/details/51015706)
    seg3=s0;
    seg2=s1;
    seg1=s2;
    seg0=s3;
}

void IP::showIP()
{
    //��ʾ������Ǹ��˿��ģ���4�κ���
    cout<<int(seg3)<<"."<<int(seg2)<<"."<<int(seg1)<<"."<<int(seg0)<<endl;
    return;
}

bool IP::sameSubnet(const IP &ip, const IP &mark)
{
    //���������밴λ�룬�Ǽ�����ڲ��Ĳ�����ֱ����һ���������������
    unsigned int i1, i2;
    i1=   address & mark.address;   //�������������߼�������
    i2=ip.address & mark.address;   //�������������߼�������
    return (i1==i2);                //������������߼�����������ͬ��������ͬһ����
}

char IP::whatKind()
{
    //IP��ַ�����ͣ��뵽�ٶȰٿ���������IP��ַ��
    if(seg3<128)
        return 'A';
    else if(seg3<192)
        return 'B';
    else if(seg3<224)
        return 'C';
    else if(seg3<240)
        return 'D';
    else
        return 'E';
}

int main()
{
    IP ip1(202,194,116,97), ip2(202,194,119,102), mark(255,255,248,0);
    cout<<"ip1: ";
    ip1.showIP();
    cout<<"ip2: ";
    ip2.showIP();
    if(ip1.sameSubnet(ip2,mark))
        cout<<"����IP��ͬһ����"<<endl;
    else
        cout<<"����IP����ͬһ����"<<endl;
    cout<<"ip1����"<<ip1.whatKind()<<"������"<<endl;
    return 0;
}

#else

#include <iostream>
using namespace std;
class IP
{
private:
    union
    {
        unsigned char seg[4]; //IP��ַ��4�ֽڣ����߿����޷����ַ�������ָ4����
        unsigned int address; //���߿���һ������
    };
public:
    IP(int=0,int=0,int=0,int=0);
    void showIP();
    bool sameSubnet(const IP &ip, const IP &mark);
    char whatKind();
};

IP::IP(int s0,int s1,int s2,int s3)
{
    //���渳ֵ��˳���漰�������ݴ洢�ṹ���ο�[�������������ڴ�����δ洢����](http://blog.csdn.net/sxhelijian/article/details/51015706)
    seg[0]=s3;
    seg[1]=s2;
    seg[2]=s1;
    seg[3]=s0;
}

void IP::showIP()
{
    //��ʾ������Ǹ��˿��ģ���4�κ���
    cout<<int(seg[3])<<"."<<int(seg[2])<<"."<<int(seg[1])<<"."<<int(seg[0])<<endl;
    return;
}

bool IP::sameSubnet(const IP &ip, const IP &mark)
{
    //���������밴λ�룬�Ǽ�����ڲ��Ĳ�����ֱ����һ���������������
    unsigned int i1, i2;
    i1=address&mark.address; //�������������߼�������
    i2=ip.address&mark.address; //�������������߼�������
    return (i1==i2); //������������߼�����������ͬ��������ͬһ����
}

char IP::whatKind()
{
    //IP��ַ�����ͣ��뵽�ٶȰٿ���������IP��ַ��
    if(seg[3]<128)
        return 'A';
    else if(seg[3]<192)
        return 'B';
    else if(seg[3]<224)
        return 'C';
    else if(seg[3]<240)
        return 'D';
    else
        return 'E';
}

int main()
{
    IP ip1(202,194,116,97), ip2(202,194,119,102), mark(255,255,248,0);
    cout<<"ip1: ";
    ip1.showIP();
    cout<<"ip2: ";
    ip2.showIP();
    if(ip1.sameSubnet(ip2,mark))
        cout<<"����IP��ͬһ����"<<endl;
    else
        cout<<"����IP����ͬһ����"<<endl;
    cout<<"ip1����"<<ip1.whatKind()<<"������"<<endl;
    return 0;
}


#endif

#if 0


#endif
/*
    printf("\n-End-\n");
    while(1);
    return 0;
*/