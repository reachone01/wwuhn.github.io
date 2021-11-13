#include <iostream>  // ָ����Ƴɼ�����
#include <Cmath>
#include <string>
using namespace std;
double max(double (*a)[4],int m, int j);    
double min(double (*a)[4],int m, int j);    
double avg(double (*a)[4], int m,int j);    
double stdev(double (*a)[4],int m, int j );  
void output_result(double (*s)[4],int n);
void input(double (*a)[4],int n); //����ɼ���n��ѧ������ 
void output(double (*a)[4],int n);  
int main ()
{
    
    int num;
    double score[50][4];
    cout<<"������ͬѧ����"<<endl;
    cin>>num;
    input(score,num);
    output(score,num);
    return 0; 
}
/*
��������
*/
void input(double (*a)[4],int n) //����ɼ���n��ѧ������ 
{
    int i;
    for(i=0;i<n;i++)
    {
        cout<<"������ѧ��Ϊ"<<i<<"�ĳɼ�(���� Ӣ�� C++)"<<endl;
        cin>>*(a[i])>>*(a[i]+1)>>*(a[i]+2);//��cin>>a[i][0]>>a[i][1]>>a[i][2];
        *(*(a+i)+3)=a[i][0]+a[i][1]+a[i][2];//a[i][3]=a[i][0]+a[i][1]+a[i][2];
    }  
    return ;
}

void output(double (*a)[4],int n)
{
    int i;
    string course[4]={"�ߵ���ѧ","Ӣ��","C++","�ܷ�"}; 
    /*����ɼ�
    */
    cout<<"�����ѧ���ɼ�Ϊ��"<<endl;  
    cout<<"ѧ��\t����\tӢ��\tC++\t�ܷ�"<<endl;  
    for(i=0;i<n;++i)  
    {  
        cout<<i<<'\t'<<a[i][0]<<'\t';  
        cout<<a[i][1]<<'\t';  
        cout<<a[i][2]<<'\t';  
        cout<<a[i][3]<<endl;  
    }  
    /*������ֳɼ�
    */
    for(i=0;i<4;i++)  
    {    
        cout<<course[i]<<"����߳ɼ���"<<max(a,n,i)<<", ";  
        cout<<"��ͳɼ���"<<min(a,n,i)<<", ";  
        cout<<"ƽ���ɼ���"<<avg(a,n,i)<<", ";  
        cout<<"�ɼ��ı�׼ƫ����"<<stdev(a,n,i)<<endl;    
    }    
    output_result(a,n);  
    return ; 
}


double max(double (*a)[4],int m, int j)
{
    double p=*(a[0]+j);//��p=a[0][j];
    for(int i=1;i<m;i++)
        if(p<a[i][j])
            p=a[i][j];
        return p;
} 

double min(double (*a)[4],int m, int j)
{
    double s=a[0][j];
    for(int i=1;i<m;i++)
        if(s>a[i][j])
            s=a[i][j];
        return s;
}    
double avg(double (*a)[4], int m,int j)
{
    double sum=a[0][j];
    for(int i=1;i<m;i++)
        sum=sum+a[i][j];
    return sum/m;
}
double stdev(double (*a)[4],int m, int j )
{
    double s,x,sum=0;  
    s=avg(a,m,j);//ƽ���ɼ�   
    for(int i=0;i<m;i++)    
    {    
        x=a[i][j]-s;    
        sum+=x*x;    
    }    
    return sqrt(sum/(m-1));    
}
//��������ܷ���ߡ����ͬѧ����������Ӧ��ѧ�š�   
void output_result(double (*s)[4],int n)  
{  
    double m=max(s,n,3);  
    int i,c=0;  
    bool first=true;  
    cout<<"�ܷ���߷�Ϊ"<<m;  
    for(i=0;i<n;++i)  
    {  
        if(s[i][3]==m)//ֱ����s[i][3]==m���ܻ��򾫶ȶ�����   
            ++c;  
    }  
    cout<<"����"<<c<<"�˴ﵽ��߷֣����ǵ�ѧ���ǣ�";  
    for(i=0;i<n;++i)  
    {  
        if(s[i][3]==m)  
            if(first)  
            {  
                cout<<i;  
                first=false;  
            }  
            else  
            {  
                cout<<"��"<<i;  
            }  
    }  
    cout<<endl;  
    //������ͳɼ�   
    m=min(s,n,3);  
    c=0;  
    first=true;  
    cout<<"�ܷ���ͷ�Ϊ"<<m;  
    for(i=0;i<n;++i)  
    {  
        if(s[i][3]==m)   
            ++c;  
    }  
    cout<<"����"<<c<<"�˴ﵽ��ͷ֣����ǵ�ѧ���ǣ�";  
    for(i=0;i<n;++i)  
    {  
        if(s[i][3]==m)  
            if(first)  
            {  
                cout<<i;  
                first=false;  
            }  
            else  
            {  
                cout<<"��"<<i;  
            }  
    }  
    cout<<endl;  
    return ;
}