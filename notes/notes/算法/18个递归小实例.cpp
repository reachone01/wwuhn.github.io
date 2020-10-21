#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

#include <windows.h>
void countDown(int count) // 1 ��ʱ
{
    if(count==0) return;
    Sleep(1000);
    std::cout << count << '\n';
    countDown(count-1);
    Sleep(1000);
    std::cout << count<<'\n';
}
void main1()
{
    countDown(3);
    cin.get();
}

int fac(int n)           // 2 �׳�
{
    if(n<0)
        cout<<"��������С��0��������׳�!"<<endl;
    if(n==0)
        return 1;
    return n*fac(n-1);
}

void main2()
{
    cout<<fac(5)<<endl;  // 120
    cin.get();
}


#include <vector>
int arr[]={0,1};
int fibonacci(int count)  // 3 ������������
{
    static std::vector<int> fib(arr,arr+2);
    if (count < static_cast<int>(fib.size()))
        return fib[count];
    else
    {
        fib.push_back(fibonacci(count - 1) + fibonacci(count - 2));
        return fib[count];
    }
}
void main3()
{
    for (int count = 0; count < 47; ++count)
        cout << fibonacci(count) << " ";
    cin.get();
}

void reverse()               // 4 �ַ����������
{
    char ch = getchar();
    if(ch == '\n')
        return;
    reverse();
    putchar(ch);
}
void main4()
{
    cout<<"������һ���ַ���(�س�����������)��";
    reverse();
    cin.get();
}

int strLen(const char* str)       // 5 �ַ�������
{
    return (*str=='\0') ? 0 : (1+strLen(++str));
}
void main6()
{
    cout<<strLen("abcdef")<<endl;  // 6
    cin.get();
}

void print_strRecursive(char* str) // 7 ���ֻ�Ч��
{
    if('\0'==*str)
        return;
    printf("%c",*str);
    Sleep(500);
    print_strRecursive(str+1);
}
void main7()
{
    char* str ="    ������ˮ��\n\n\
    ˮ���������������\n\n\n";
    print_strRecursive(str);
    cin.get();
}

int findMax(int arr[], int n) // 8 �������ֵ
{
    if(n==1)
        return arr[0];
    else
    {
        int t = findMax(arr,n-1);
        return t>arr[n-1]?t:arr[n-1];
    }
}
int arrSum(int arr[],int n)   // 9 �������
{
    if(n!=0)
        return arr[n-1] + arrSum(arr,n-1);
    return 0;
    //return n==0?0:(arr[n-1] + arrSum(arr,n-1));
}
void main89()
{
    int arr[11]={1,4,9,3,6};
    int len = sizeof(arr)/sizeof(arr[0]);
    cout<<findMax(arr,11)<<endl;   // 9
    cout<<arrSum(arr,len)<<endl;   // 23
    cin.get();
}

void turn(int n) // 10 �����������
{
    if(n>=10)
    {
        cout<<n%10;
        turn(n/10);
    }
    else
        cout<<n;
}
void main10()
{
    turn(123);   // 321
    cin.get();
}

void trangle(char ch,int n) // 11 ����Ǻ�������(��ģ��ѭ��)
{
    if(n>0)
    {
        cout<<ch;
        trangle(ch,n-1);
    }
}
void main11()
{
	int rows=6;
    for(int k=1;k<=rows; k++)
    {
        trangle(' ',rows-k);
        trangle('*',2*k-1);
        cout<<endl;
    }
    cin.get();
}
/*
     *
    ***
   *****
  *******
 *********
***********
*/

int gcd(int a,int b)  // 12 շת�������Լ��
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
void main12()
{
    cout<<gcd(51,170)<<endl;  // 17
    cin.get();
}

double squareRoot(double a, double x0) // 13 ��ƽ����
{
    double ans;
    double x1=(x0+a/x0)/2;
    if(fabs(x1-x0)>1e-8)
        ans = squareRoot(a,x1);
    else
        ans=x1;
    return ans;
}
void main13()
{
    cout<<squareRoot(2,1.0)<<endl; // 1.41421
    cin.get();
}

int combin(int m, int n)   // 14 ���������
{
    int com;
    if(n<2*m)
        m=n-m;             // c(m,n)=c(n-m,n)
    if(m==0)
        com=1;
    else if(m==1)
        com=n;
    else
        com=combin(m,n-1)+combin(m-1,n-1); // c(m,n+1)=c(m,n)+c(m-1,n)
    return com;
}
void main14()
{
    cout<<combin(2,8);//28
    cin.get();
}


int xy(int x,int y)   // 15 ������������е�x�С���y�е�ֵ
{
    if(y==1||y==x+1)
        return 1;
    return xy(x-1,y-1)+xy(x-1,y);
}
void main15()
{
    int n=11;
    for(int i=0; i<=n;i++)
    {
        for(int j=0;j<2*n-2*i;j++)
            cout<<" ";
        for(j=1;j<i+2; j++)
            cout<<setw(5)<<xy(i,j);
        cout<<endl;
    }
    cin.get();
}
/*
                          1
                        1    1
                      1    2    1
                    1    3    3    1
                  1    4    6    4    1
                1    5   10   10    5    1
              1    6   15   20   15    6    1
            1    7   21   35   35   21    7    1
          1    8   28   56   70   56   28    8    1
        1    9   36   84  126  126   84   36    9    1
      1   10   45  120  210  252  210  120   45   10    1
    1   11   55  165  330  462  462  330  165   55   11    1
*/
    

void hanoi(int n, char from, char temp, char to) // 16 ��ŵ��
{
    if (n==1)
        printf("%c��%c(1)\n",from,to);
    else
    {
        hanoi(n-1,from,to,temp);        //��x�ϱ��Ϊ1��n-1��Բ���Ƶ�y��z��������
        printf("%c��%c\n",from,to);        //��x�ϱ��Ϊn��Բ���Ƶ�z
        hanoi(n-1,temp,from,to);        //��y�ϱ��Ϊ1��n-1��Բ���Ƶ�z��y��������
        
    }
}
void main16()
{
    hanoi(3,'A','B','C');
    cin.get();
}
/*
A��C(1)
A��B
C��B(1)
A��C
B��A(1)
B��C
A��C(1)
*/

int Josephus(int m)   // 17 ����ѡ����
{
    int k=5; // ��ʼ����λ��
    int ans;
    if(m==1)
        return 1;
    else
        ans=(Josephus(m-1)+k-1)%m+1;
    return ans;
}
void main17()
{
    int m=8; // 8ֻ����
    
    cout<<Josephus(m)<<endl; // 3
    cin.get();
}

int binarySearchRecursion(int arr[], int findData, int start, int end) // 18 ���ֲ���
{
    if(arr==NULL || start>end)
        return -1;
        int mid = start+(end-start)/2;
        if(arr[mid] == findData)
            return mid;
        else if(findData < arr[mid])
            binarySearchRecursion(arr, findData, start, mid-1);
        else
            binarySearchRecursion(arr, findData, mid+1, end);

}
void main18()
{    
    int arr[] = {1,2,3,4,5,6,7,8};
    int len = sizeof(arr)/sizeof(arr[0]);
    int index = binarySearchRecursion(arr,6,0,len-1);
    cout<<index<<endl;  // 5
    getchar();
}

// ����ʹ�õݹ�ĳ��ó��ϣ���������n�ʺ����⡢�������⡢����������