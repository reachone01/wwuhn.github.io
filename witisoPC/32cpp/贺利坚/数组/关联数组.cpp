/*

*/
#if 1
#include<iostream>
#include<string>
using namespace std;
void input(double s[][4],int n); //����ɼ�
void output(double s[][4],int n); //����ɼ�
double max(double s[][4],int n,int i); //���i�ſε���߳ɼ���i=3ʱ���ܷ�
double min(double s[][4],int n,int i); //���i�ſε���ͳɼ�
double avg(double s[][4],int n,int i); //���i�ſε�ƽ���ɼ�
 
int main()
{
    int i,num;
    string temp;
    double score[100][4]; //��һ�������100�ˣ�ʵ�ʰ�������
    string course[4]= {"�ߵ���ѧ","Ӣ��","C++","�ܷ�"};
    cout<<"����ѧ��������";
    cin>>num;
    //��1������ɼ�������ܷ�
    input(score,num);
    //��2������ɼ�
    output(score,num);
 
    //��3��������ſμ��ֵܷ���߳ɼ�����ͳɼ���ƽ���ɼ��ͳɼ��ı�׼ƫ�
    for(i=0; i<4; ++i)
    {
        cout<<course[i]<<"����߳ɼ���"<<max(score,num,i)<<", ";
        cout<<"��ͳɼ���"<<min(score,num,i)<<", ";
        cout<<"ƽ���ɼ���"<<avg(score,num,i)<<", ";
        cout<<endl;
    }
 
    return 0;
}
 
void input(double s[][4],int n) //����ɼ�
{
    cout<<"����ѧ���ɼ�(��������Ӣ�C++��˳���������룺)"<<endl;
    for(int i=0; i<n; ++i)
    {
        cin>>s[i][0]>>s[i][1]>>s[i][2];
        s[i][3]=s[i][0]+s[i][1]+s[i][2];
    }
}
 
void output(double s[][4],int n) //����ɼ�
{
    cout<<"�����ѧ���ɼ�Ϊ��"<<endl;
    cout<<"ѧ��\t����\tӢ��\tC++\t�ܷ�"<<endl;
    for(int i=0; i<n; ++i)
    {
        cout<<i<<'\t'<<s[i][0]<<'\t';
        cout<<s[i][1]<<'\t';
        cout<<s[i][2]<<'\t';
        cout<<s[i][3]<<endl;
    }
}
//���j�ſε���߳ɼ���i=3ʱ���ܷ֣�������
double max(double s[][4],int n,int j)
{
    double m=s[0][j];
    for(int i=1; i<n; ++i)
        if (m<s[i][j])
            m=s[i][j];
    return m;
}
double min(double s[][4],int n,int j)
{
    double m=s[0][j];
    for(int i=1; i<n; ++i)
        if (m>s[i][j])
            m=s[i][j];
    return m;
}
double avg(double s[][4],int n,int j)
{
    double sum=s[0][j];
    for(int i=1; i<n; ++i)
        sum+=s[i][j];
    return sum/n;
}

#else

#include<iostream>
#include<string>
#include<cmath>
using namespace std;
void input(double s[][4],string name[],int n); //����ɼ�
void output(double s[][4],string name[],int n); //����ɼ�
double max(double s[][4],int n,int i); //���i�ſε���߳ɼ���i=3ʱ���ܷ�
double min(double s[][4],int n,int i); //���i�ſε���ͳɼ�
double avg(double s[][4],int n,int i); //���i�ſε�ƽ���ɼ�
void outputByScore(double s[][4],string name[], int n, int i, double si); //�����i�ſγɼ�Ϊsi��ͬѧ����
int main()
{
    int i,num;
    string temp;
    double score[100][4]; //��һ�������100�ˣ�ʵ�ʰ������������
    string name[100];
    string course[4]= {"�ߵ���ѧ","Ӣ��","C++","�ܷ�"};
    cout<<"����ѧ��������";
    cin>>num;
    //��1������ɼ�������ܷ�
    input(score,name,num);
    //��2������ɼ�
    output(score,name,num);
 
    //��3��������ſμ��ֵܷ���߳ɼ�����ͳɼ���ƽ���ɼ��ͳɼ��ı�׼ƫ�
    for(i=0; i<4; ++i)
    {
        cout<<course[i]<<"����߳ɼ���"<<max(score,num,i)<<", ";
        cout<<"��ͳɼ���"<<min(score,num,i)<<", ";
        cout<<"ƽ���ɼ���"<<avg(score,num,i)<<", ";
        cout<<endl;
    }
 
    for(i=0; i<4; ++i)
    {
        cout<<course[i]<<"����߳ɼ�������ǣ�";
        outputByScore(score,name,num,i,max(score,num,i)); //�����i����߳ɼ�������
        cout<<endl;
    }
    return 0;
}
 
void input(double s[][4],string name[],int n) //����ɼ�
{
    cout<<"����ѧ���ɼ�(��������������Ӣ�C++��˳���������룺)"<<endl;
    for(int i=0; i<n; ++i)
    {
        cin>>name[i]>>s[i][0]>>s[i][1]>>s[i][2];
        s[i][3]=s[i][0]+s[i][1]+s[i][2];
    }
}
 
void output(double s[][4],string name[],int n) //����ɼ�
{
    cout<<"�����ѧ���ɼ�Ϊ��"<<endl;
    cout<<"ѧ��\t����\t����\tӢ��\tC++\t�ܷ�"<<endl;
    for(int i=0; i<n; ++i)
    {
        cout<<i<<'\t'<<name[i]<<'\t';
        cout<<s[i][0]<<'\t';
        cout<<s[i][1]<<'\t';
        cout<<s[i][2]<<'\t';
        cout<<s[i][3]<<endl;
    }
}
//���i�ſε���߳ɼ���i=3ʱ���ܷ֣�������
double max(double s[][4],int n,int j)
{
    double m=s[0][j];
    for(int i=1; i<n; ++i)
        if (m<s[i][j])
            m=s[i][j];
    return m;
}
double min(double s[][4],int n,int j)
{
    double m=s[0][j];
    for(int i=1; i<n; ++i)
        if (m>s[i][j])
            m=s[i][j];
    return m;
}
double avg(double s[][4],int n,int j)
{
    double sum=s[0][j];
    for(int i=1; i<n; ++i)
        sum+=s[i][j];
    return sum/n;
}
 
//�����i�ſγɼ�Ϊsi��ͬѧ����
void outputByScore(double s[][4],string name[], int n, int i, double si)
{
    for(int j=0; j<n; ++j)
    {
        if(abs(s[j][i]-si)<1e-7)  //�õ�jλͬѧ�ĵ�i�ſγɼ��Ƚ�
            cout<<name[j]<<" ";
   }
    return;
}


#endif

#if 0


#endif
/*

*/