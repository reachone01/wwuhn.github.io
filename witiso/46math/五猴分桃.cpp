/*
����ɽ����һ�ղ�ժ�������ɡ�����ɫ������Լ�����ٷ֡�
һ��ҹ�����£������ȳ�һ�ң������н��ҷ�Ϊ5�ݣ�ǡ�ɾ��֣���������(��ͬ)��ȡ��1�ݡ�
�������һ��ҹ�����£�Ҳ���ȳ�һ�ң�Ȼ���ҷ�Ϊ5�ݣ�ȡ��1�ݡ�
5�ﶼ������֮��
�����峿��5������������������һ�ѣ������þ��֣�����ϲ�ء�
��������ٲ�ժ���Ӷ��ٲ�����˽��С�
*/
#include<stdio.h>

int divided(int n, int m)
{
    if(n/5==0 || n%5!=1)
        return 0;
    if(m==1) 
        return 1;
    return divided(n-n/5-1, m-1); // ����ת��n=n-(n-1)/5-1,��ͬ��n=n-n/5-1
    //return divided(n-(n-1)/5-1, m-1);
}

int main1()
{
    int n;
    int m = 5;
    for(n = 1; ; n++)
        if(divided(n,m))
        {
            printf("1st %d\n", n);
            break;
        }
    getchar();
    return 0;
}


bool sumDiv(int n) 
{    
    for(int i=0;i<5;i++)  // ˳��4��
    {  
        if(n%5!=1)
            return false;    
        n=(n-1)/5*4;     // ����ת�� ����д��n=n/5*4
    } 
    return true;  
}
int peaches()
{
    for(int n=1;;n++)    // ö��
        if(sumDiv(n))      
            return n; 
}

int main()  
{    
    printf("�������������%d\n",peaches());  
    getchar();
    return 0;  
} 

void main3()
{
    int lastPart = 1; // �����ֻ�����õ����Ƿ���������
    int onePart = 0;  // ͨ������Ƿ������������һ�ݵ���������
    int count = 1;    // ѭ���Ĵ���������Ϊ������һ��Ҫѭ��4��
    while(count<5)
    {
        onePart = lastPart; 
        for(int i = 0;i<4;i++)
        {
            int allPeach = onePart*5+1; // �����i�����ӵ����� ,�ӵ���ο�ʼ
            if(allPeach%4!=0)           // �����������4�Ͳ���������ϴ����ӵķ�����
                                        // �������������¿�ʼѭ��
            {
                lastPart++;
                count = 1;      // ѭ����������������Ϊ1
                break;
            }
            onePart=allPeach/4; // ��������ϴ����ӵĸ���
            count++;            // ���Ӽ�����
            
        }
    }
    printf("������(%d)������",onePart*5+1);
}

#include <iostream>
#include <string>
using namespace std;

void main4(void)
{ 
    int peach=1;
    for (int i=1; ;i++)
    {
        if(i%5==1)    
            peach=(i-1)/5*4;
        if (peach%5==1)
            peach=(peach-1)/5*4;
        if (peach%5==1)
            peach=(peach-1)/5*4;
        if (peach%5==1)
            peach=(peach-1)/5*4;
        if (peach%5==1)
        {
            cout<<i<<endl;
            break;
        }
    }
}

void main5() 
{       
    int i,m,j,k,count;
    for(i=4;i<10000;i+=4)  // i�ǵ�5ֻ�����ú��������
    {
        count=0;
        m=i;               // m������һ���м���������ڻָ�i��ֵ
        for(k=0;k<5;k++)   // ��k=3ʱ���ǵ�һֻ�����������Ӻ󣬴�ʱ��j�ܱ�4������
                           // ��k=4ʱ����ʱ��j ֵ��һ���ܱ�4����
        {
            j=i/4*5+1; 
            i=j;
            
            if(j%4==0)     // ����ÿ���������Ӻ�ʣ�µĶ���4�ݰ�
                count++;
            else
                break;
        }
        i=m;             //�ָ�i��ֵ
        if(count==4)
        {
            printf("%d\n",j);
            break;
        }
        
    }
}

int peach_monkey(int start,int sumEnd,int monkey){
    if (monkey==0) {
        return sumEnd;
    }
    else{
        if (sumEnd%4==0&&sumEnd!=0) {
            return peach_monkey(start,(sumEnd/4)*5+1, --monkey);
        }else{
            start+=4;
            return peach_monkey(start, start, 5);
        }
    }
}
int main6() 
{
    printf("ԭ����%d������",peach_monkey(4,4,5));
    getchar();
    return 0;
}


int main7() 
{
    int start=4,sumEnd=4,monkey=5;
    while (monkey!=0) {
        if (sumEnd%4==0&&sumEnd!=0) {//��ΪsumEnd������4�ı���
            sumEnd=(sumEnd/4)*5+1;
            monkey--;
        }else{
            start+=4;
            sumEnd=start;
            monkey=5;
        }
    }
    printf("ԭ���� %d ������\n",sumEnd);
    getchar();
    return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//  ��ֻ���ӷ��ҡ���ҹ����һֻ�����������������ҷֳ�����ȵ���ѣ����һֻ��
//  ���ǣ����Ե���һ����������һ�ѣ� �ڶ�ֻ��������һ����ֻ���Ķ��ҡ�
//  ���ǰ��ĶѺ���һ�𣬷ֳ���ȵ���ѣ��ֶ��һ�������ǣ���Ҳ�Ե���һ����������һ�ѣ�.....
//  ������ֻ����Ҳ���� �����ֵġ�
//  �ʣ�����������ж��ٸ��� (3121)
//
//  @���뻷����Dev c++ 5.11 
//////////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//  ��������
int CalcuCount( int n ); 

int main8() 
{
    int sum = CalcuCount(5);
    printf("%d \n" , sum);

    return 0;
}

int CalcuCount( int n )
{
    if ( n <= 1 || n >= 9 )
        return -1;
    int base = n + 1;
    int sum = base;
    int i = 0;

    while ( 1 )
    {
        sum = base;
        for ( i = 0; i < n ; ++i)
        {
            if ( (sum-1) % n == 0 && sum%(n-1) == 0 )
                sum = (sum/(n-1))*n + 1;
            else
                break;
        }
        if (n-1 == i && sum > 0)
            break;
        base += n;
    }
    return sum;
}


#include<stdio.h>
#include<math.h>
int main9()
{
    int n,i;
    n=5;

    int s,a,b=0,p;
    s=pow(5,n)-4;
    p=s;
    for(i=1; i<=n; i++)
    {
        a=(p-1)/5;
        p=p-1-a;
        b=b+a;
    }
    printf("%d %d\n",s,s-b);

    return 0;
}
 
#include<stdio.h>
int main11()
{
    for(int i=1;;i++)
    {
        double a=i;
        for(int j=1;j<=5;j++)
            a=(a-1)*4/5;
        int b=(int)a;
        if(b==a)
        {
            printf("%d %.0lf\n",i,a);
            break;
        }
    }
    getchar();
    return 0;
}