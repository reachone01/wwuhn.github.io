/*
��������˰���㣬�������ʽ�������üӷ�
*/
#if 0

//1 ���ṩһ����if-else��ɵĽⷨ

#include <iostream>    
using namespace std;

int main( )  
{  
    double dSalary,dTax=0,dNetIncome=0;//���������������������ı�����
    double dValue; //��ģ������ϼ�һ����������ʾ���������������
    cout<<"�����������µ������ܶԪ����";
    cin>>dSalary;
    dValue=dSalary-3500; //������������Ͽ�����˰ 
    if(dValue<=0.0)  
        dTax=0.0;
    else  
    {  
        if(dValue<=1500)
            dTax=dValue*0.03-0.0; //ֱ�Ӹ���˰�ʺ�����۳�������
        else if(dValue<=4500)
            dTax=dValue*0.10-105.0; 
        else if(dValue<=9000)
            dTax=dValue*0.20-555.0;
        else if(dValue<=35000)
            dTax=dValue*0.25-1005.0; 
        else if(dValue<=55000) 
            dTax=dValue*0.30-2755.0;
        else if(dValue<=80000)
            dTax=dValue*0.35-5505.0;
        else 
            dTax=dValue*0.45-13505.0;
    }  
    dNetIncome=dSalary-dTax; //����õ�
    cout<<"������Ӧ�ɸ�������˰ "<<dTax<<" Ԫ��˰�������� "<<dNetIncome<<" Ԫ��\n";
    cout<<"������˰�������١�ллʹ�ã�\n";
    while(1);
    return 0;
}  

#endif

#if 0

//�ο�2���ڲο�1��������Щ�Ľ��Ľⷨ
#include <iostream>    
using namespace std;
int main( )  
{  
    double dSalary,dTax = 0,dNetIncome = 0;//���������������������ı�����
    double dValue; //��ģ������ϼ�һ����������ʾ���������������
    double dRate, dOffset;//�ֱ��ʾ˰�ʺ�����۳���
    cout<<"�����������µ������ܶԪ����";
    cin>>dSalary;
    dValue = dSalary - 3500; //������������Ͽ�����˰ 
    if(dValue <= 0.0)  
        dTax = 0.0;//����Ҫ��˰
    else  
    {  
        if(dValue <= 1500)
            dRate = 0.03, dOffset = 0.0; //��һ��if������ڵõ�˰�ʺ�����۳���
        else if(dValue <= 4500)
            dRate = 0.1, dOffset = 105.0; 
        else if(dValue <= 9000)
            dRate = 0.2, dOffset = 555.0;
        else if(dValue <= 35000)
            dRate = 0.25, dOffset = 1005.0; 
        else if(dValue <= 55000) 
            dRate = 0.3, dOffset = 2755.0;
        else if(dValue <= 80000)
            dRate = 0.35, dOffset = 5505.0;
        else 
            dRate = 0.45, dOffset = 13505.0;
        dTax = dValue * dRate - dOffset;//��������˰����Ὣ��ȷ���������롰���㡱�ֿ��ĺô���˼·�������������ڼ��㹫ʽ�Ϸ����
    }  
    dNetIncome = dSalary-dTax;      //����˰������
    cout<<"������Ӧ�ɸ�������˰ "<<dTax<<" Ԫ��˰�������� "<<dNetIncome<<" Ԫ��\n";
    cout<<"������˰�������١�ллʹ�ã�\n"; 
    while(1);
    return 0;
}  

#endif

#if 0


// �ο�3����������switch�����ɵĳ�������о�������������ֱ����if�����ֿ���Ҳ�ǶԵģ�
// ���ֽⷨ������Ҳ�ͽ�������ϰswitch�ˡ�
#include <iostream>    
using namespace std;
int main( )  
{  
    double dSalary,dTax = 0,dNetIncome = 0;//���������������������ı�����
    double dValue; //��ģ������ϼ�һ����������ʾ���������������
    double dRate, dOffset;//�ֱ��ʾ˰�ʺ�����۳���
    int iStep;     //����ȷ����˰�ġ����Ρ�
    cout<<"�����������µ������ܶԪ����";
    cin>>dSalary;
    dValue = dSalary - 3500; //������������Ͽ�����˰ 
    if(dValue <= 0.0)  
        dTax = 0.0;//����Ҫ��˰
    else  
    {  
        //��һ��if���ȷ����˰�ĵ���
        if(dValue <= 1500)
            iStep = 1;
        else if(dValue <= 4500)
            iStep = 2;
        else if(dValue <= 9000)
            iStep = 3;
        else if(dValue <= 35000)
            iStep = 4;
        else if(dValue <= 55000) 
            iStep = 5;
        else if(dValue <= 80000)
            iStep = 6;
        else 
            iStep = 7;
        
        //����ȷ���ĵ��Σ��õ�˰�ʺ�����۳�������������������и������б���ʽ�нϺõĶ�Ӧ
        //������ս̲��е����ӣ�ͨ������c=s/n��n���ȡ500������ʽ�õ�switch��<���ʽ>��������嵥���еĺܳ�
        switch(iStep)
        {
        case 1:
            dRate = 0.03, dOffset = 0.0;break; 
        case 2:
            dRate = 0.1, dOffset = 105.0;break;
        case 3:
            dRate = 0.2, dOffset = 555.0; break;
        case 4:
            dRate = 0.25, dOffset = 1005.0;break;
        case 5:
            dRate = 0.3, dOffset = 2755.0; break;
        case 6:
            dRate = 0.35, dOffset = 5505.0; break;
        case 7:
            dRate = 0.45, dOffset = 13505.0;
        }
        dTax = dValue * dRate - dOffset;//��������˰����Ὣ��ȷ���������롰���㡱�ֿ��ĺô���˼·�������������ڼ��㹫ʽ�Ϸ����
    }  
    dNetIncome = dSalary-dTax;      //����˰������
    cout<<"������Ӧ�ɸ�������˰ "<<dTax<<" Ԫ��˰�������� "<<dNetIncome<<" Ԫ��\n";
    cout<<"������˰�������١�ллʹ�ã�\n";
    while(1);
    return 0;
} 

#endif



#if 0


// �ο�4����˵����������ˣ���Ҫ��switchǰ�õ����ӣ�
// ������2011��һλͬѧ�����Ľ��ԭʼ���ӣ�

#include <iostream>  
using namespace std;
int main( )
{
    double m=0,s=0,f=0; //mΪ�����룬sΪ��Ҫ��˰�Ĳ���,fΪ˰��
    int t=0;          //t�����ж�
    cout<<"��Ѿ��һ�������������ӣ�����"<<'\n';
    cin>>m;
    if (m<=3500)
        cout<<"�㲻��Ҫ��˰��ллʹ�ã���Ŭ��������ȡ�ӹ��ʣ�";
    else
    {
        s=m-3500;
        t=(s>=1500)+(s>=4500)+(s>=9000)+(s>=35000)+(s>=55000)+(s>=80000); 
        //�������㣬�������ʽΪ�棬��ֵΪ1��t��ʾ���������ĸ���
        switch(t)
        {
        case 6:f=s*0.45-13505;break;
        case 5:f=s*0.35-5505;break;
        case 4:f=s*0.30-2755;break;
        case 3:f=s*0.25-1005;break;
        case 2:f=s*0.20-555;break;
        case 1:f=s*0.10-105;break;
        case 0:f=s*0.03;break;
        }
        cout<<"����˰������Ϊ�� "<<m-f<<'\n';
        cout<<'\n';
        cout<<"* * * * * * * * * * *"<<'\n';
        cout<<"* ������˰,�������� *"<<'\n';
        cout<<"* * * * * * * * * * *"<<'\n';
    }
    return 0;
}


#endif







#if 1


//�ο�5���������飬ʵ�������������ķ��롣��ʵ������ĳ̶Ȼ�����������ʽ����Ŀ�У�
// ���ݼ���û�ж����ڳ����еġ��������Ȥ���Լ���һ�����飬�����������
// �������̫�����ӣ���һ�º��Թ�ȥ�����������ѧ��

#include <iostream>
using namespace std;
int main( )
{
    double dSalary,dTax = 0,dNetIncome = 0;//�����ͷ����������������ı�����
    double dValue; //��ģ������ϼ�һ����������ʾ���������������
    double dValues[]={1500,4500,9000,35000,55000,80000};//�������ʾ���ηֽ���
    double dRate  []={0.03,0.10,0.20, 0.25,0.30, 0.35,0.45};//��������������˰��
    double dOffset[]={0,   105, 555,  1005,2755, 5505,13505};  //��������������۳���
    int iStep, i;     //iStep����ȷ����˰�ġ����Ρ���i����Ϊѭ����
    cout<<"�����������µ������ܶԪ����";
    cin>>dSalary;
    dValue = dSalary - 3500; //������������Ͽ�����˰
    if(dValue <= 0.0)
        dTax = 0.0;//����Ҫ��˰
    else
    {
        i=0;
        while(dValue > dValues[i] && i<=6)//ͨ���������в���ȷ����˰�ĵ���
            i++;
        iStep=i;
        dTax = dValue * dRate[iStep] - dOffset[iStep];//��������˰�����ֽ����������������ݷֿ��������
    }
    dNetIncome = dSalary-dTax;      //����˰������
    cout<<"������Ӧ�ɸ�������˰ "<<dTax<<" Ԫ��˰�������� "<<dNetIncome<<" Ԫ��\n";
    cout<<"������˰�������١�ллʹ�ã�\n";
    while(1);
    return 0;
}
#endif