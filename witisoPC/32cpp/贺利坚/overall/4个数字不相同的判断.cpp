#include <iostream> // 4���������
using namespace std; // 4�����ֲ���ͬ���ж�
/*
     d
    cd
   bcd
+ abcd
________________
  2008

  */

void cal(int n) // δ����ǰ�Ĵ���  
{ 
	int a,b,c,d,s;//��������ȡ������Щ�������i,j,p,q֮���Ҫ�����ö�
	for(a=1;a<3;a++)
		for(b=0;b<10;b++)
			for(c=0;c<10;c++)
				for(d=0;d<10;d++)
					if((a-b)*(a-c)*(a-d)*(b-c)*(b-d)*(c-d)!=0)//һ�����ɣ���ʾ������ͬ����������
					{
						s=4*d+3*c*10+2*b*100+a*1000;
						if(n==s) 
							cout<<a<<b<<c<<d<<endl;
					}
}  

void cal_1(int n)
{
    int a,b,c,d,s;
    for(a=1;a<3;a++)
        for(b=0;b<10;b++)
        {
        if(a==b) continue;//��a���͡�b����ȡֵ�����ͬ�ˣ������ٿ����������ֵ�ȡֵ��Ч���ɹ�
            for(c=0;c<10;c++)
            {
                if(c==b||c==a) continue;  //����ͬ��
                    for(d=0;d<10;d++)
                    if((a-d)*(b-d)*(c-d)!=0)
                    {
                        s=4*d+3*c*10+2*b*100+a*1000;
                        if(n==s)
                            cout<<a<<b<<c<<d<<endl;
                    }
            }
    }
}
int main()
{
    cal(2008);
    for(int i=2000;i<2050;i++)
    {
        cout<<"-----"<< i <<endl;
        cal_1(i);
    }
    
    while(1);
    return 0;
}