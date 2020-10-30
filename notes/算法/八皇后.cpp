/*
n�ʺ����⣺��n*n�������Ϸ��ñ˴˲��ܹ�����n���ʺ�
���ʺ���Թ�����ͬһ�С�ͬһ�С�ͬһб���ϵ����ӣ�
�����Ϲ���ͬһ�л�ͬһ�л�ͬһб����ֻ����һ���ʺ�ͬһ�л�ͬһ���ϱ�����һ���ʺ�
n�ʺ�����Ľ�ռ���һ��n�������������Ϊn
  1 2 3 4 5 6 7 8
1 Q . . . . . . .
2 . . . . Q . . .
3 . . . . . . . Q
4 . . . . . Q . .
5 . . Q . . . . .
6 . . . . . . Q .
7 . Q . . . . . .
8 . . . Q . . . .
���ݷ�����
1 ������ʵĽ�ռ䣬���������֯��ʽ����Լ��
2 ȷ����ռ����֯�ṹ��ͨ��������̬�����Ӽ�������������m������
3 ������ռ䣺����������������ԣ�������Լ����Լ���������޽纯�������ڽ�ռ�����������Ŀ��н⣻
�����ֵ�ǰ��㲻�����������ʱ���ͻ��ݣ���������·����
  */
#if(0) // 1

#include<stdlib.h>         // ���ݷ���ʹ��ջ��
#include<stdio.h>
#include<memory.h>
#define true  1
#define false 0
int n=0;                // ��ĸ���

void printResult(int[]); 
void movequeen(int,int,int[],int[],int[]);
void eightqueen( );

void main( )
{
    eightqueen( );            // �������˻ʺ�����
    system("pause");
}

void eightqueen( )            // ���˻ʺ�����
{    
    int i,j;    // ��ǰ�С���
    int s[9];   // ˳��ջs[i]�����ʺ����λ��(i,j)�ϣ���jѹ��ջ�ڣ���s[i] = j
                // ���ʺ�֮���Ƿ��ͻ����������
    int a[9];   // a[j]Ϊ��ʱ����ʾ��j�����޻ʺ�
    int b[17];  // "/"�����ϣ�i+j��ȣ��±�Ϊ2��16��b[k]Ϊ��ʱ��ʾ"/"�������޻ʺ�
    int c[17];  // "\"�����ϣ�i-j��ȣ��±�Ϊ-7��7��c[k]Ϊ��ʱ��ʾ"\"�������޻ʺ�
                // c[i-j+9]��ʾ�±���2-16��Χ��
    
    for(i=2; i<=16; i++) {        // ��ʼ������λ��ȫ�޻ʺ�
        if(i>=2 && i<=9) 
            a[i-1]=true;
        b[i]=true;
        c[i]=true;
    }
    i=1; j=1;
    while(i>=1) {                // ��i=0ʱ��ֹѭ��
        while(j<=8) {            // �ڵ�ǰ��i��Ѱ�Ұ�ȫλ�ã�
            if(a[j] && b[i+j] && c[i-j+9])  break;
            j++;
        }
        if(j<=8) {                // �ҵ���ȫλ��(i,j)
            a[j]     = false; 
            b[i+j]   = false; 
            c[i-j+9] = false;
            s[i]=j;               // �ʺ�λ��j��ջ
            if(i==8) {            // �ҵ�һ����,�����
                printf("��%d���⣺\n",++n);
                printResult(s);         // ��ӡ���һ����
                movequeen(i,j,a,b,c);   // ��ȥλ��(i,j)�ϵĻʺ�
                i--; j=s[i];            // ��ջ�����ݵ���һ���ʺ�
                movequeen(i,j,a,b,c);   // ��ȥλ��(i,j)�ϵĻʺ�
                j++;                    // �޸�ջ���ʺ��λ��
            }
            else {
                i++;j=1;                // ׼��������һ���ʺ�
            } 
        }
        else {
            i--;                        // ��ջ
            if(i>=1) {                  // ջ����,��ȥ�ʺ�
                j=s[i]; 
                movequeen(i,j,a,b,c);   // ��ȥ�ʺ�
                j++;
            }
        } // if(j<=8)
    } // while(i>=1)
}

// ��ȥλ��(i,j)�ϵĻʺ��� 
void movequeen(int i, int j, int a[], int b[], int c[]) 
{
    a[j]     = 1; // j�����޻ʺ�
    b[i+j]   = 1; // "/"�������޻ʺ�
    c[i-j+9] = 1; // "\"�������޻ʺ�
}

void printResult(int s[] ) // ��ӡ���һ����ĺ��� 
{
    int i,j;               // ѭ������
    printf("%8c",' ');
    for(i=1;i<=8;++i)
        printf("%4d",i);
    
    for(i=1;i<=8;++i)
    {
        printf("\n%4c",' ');
        for(j=1;j<=8;++j)
        {
            if(j==1)
                printf("%4d",i);
            if(j==s[i])
                printf("%4d",s[i]);
            else
                printf("%4c",'.');
        }
        printf("\n");
    }
    printf("\n\n");
}

void printResult2(int s[] ) 
{
    int arr[9][9]={0};

    for(int p=1;p<=8;p++)
    {
        arr[p][s[p]] = 1;
    }

    for(int m=1;m<=8;m++)
    {
        for(int n=1; n<=8; n++)
            printf("%2d",arr[m][n]);
        printf("\n");
    }
    printf("\n");
}

void printResult3(int s[] )
{
    int k;
    printf("�У� 1 2 3 4 5 6 7 8\n");
    printf("�У�");
    for(k=1; k<=8; k++)
        printf("%2d",s[k]);
    printf("\n");
}

/*
��1���⣺
�У� 1 2 3 4 5 6 7 8
�У� 1 5 8 6 3 7 2 4
��2���⣺
�У� 1 2 3 4 5 6 7 8
�У� 1 6 8 3 7 4 2 5
��46���⣺
�У� 1 2 3 4 5 6 7 8
�У� 4 8 5 3 1 7 2 6
��47���⣺
�У� 1 2 3 4 5 6 7 8
�У� 5 1 4 6 8 2 7 3
��91���⣺
�У� 1 2 3 4 5 6 7 8
�У� 8 3 1 6 2 5 7 4
��92���⣺
�У� 1 2 3 4 5 6 7 8
�У� 8 4 1 3 6 2 7 5
��92���⣺
           1   2   3   4   5   6   7   8
       1   .   .   .   .   .   .   .   8

       2   .   .   .   4   .   .   .   .

       3   1   .   .   .   .   .   .   .

       4   .   .   3   .   .   .   .   .

       5   .   .   .   .   .   6   .   .

       6   .   2   .   .   .   .   .   .

       7   .   .   .   .   .   .   7   .

       8   .   .   .   .   5   .   .   .
*/
#endif


#if(1) // 2
#include <iostream>        //���ݷ����ݹ飩
#include<cmath>            //�����ֵ������Ҫ�����ͷ�ļ�
#define M 105
using namespace std;

int n;                // n��ʾn���ʺ�
int x[M];            // x[i]��ʾ��i���ʺ�����ڵ�i�е�x[i]�У���ʾ��ռ�
int countn;            // countn��ʾn�ʺ�������н�ĸ���

bool Place(int t)    // �жϵ�t���ʺ��ܷ�����ڵ�i��λ��
{
    bool ok=true;
    for(int j=1;j<t;j++)   // �жϸ�λ�õĻʺ��Ƿ���ǰ��t-1���Ѿ����õĻʺ��ͻ
    {
       if(x[t]==x[j]||t-j==fabs(x[t]-x[j]))// �ж��С��Խ����Ƿ��ͻ
       {
           ok=false;
           break;
       }
    }
    return ok;
}

void Backtrack(int t)            // t��ʾ��ǰ��չ����ڵ�t��
{
    if(t>n)                        // �����ǰλ��Ϊn,���ʾ�Ѿ��ҵ��������һ����
    {
        countn++;
        for(int i=1; i<=n;i++)    // ��ӡѡ���·��
          cout<<x[i]<<" ";
        cout<<endl;
        cout<<"----------"<<endl;
    }
    else
        for(int i=1;i<=n;i++)    //�ֱ��ж�n����֧,�ر�ע��i��Ҫ����Ϊȫ�ֱ���,����ݹ����������
        {
            x[t]=i;
            if(Place(t))        // �������ͻ�Ļ�������һ�е����������򿼲���һ����֧���ֵܽ�㣩
                Backtrack(t+1); 
        }
}
int main()
{
    cout<<"������ʺ�ĸ��� n:";
    cin>>n;
    countn=0;
    Backtrack(1);
    cout <<"�𰸵ĸ����ǣ�"<<countn<< endl;
    system("pause");
    return 0;
}
#endif

#if(0) // 3
#include<stdio.h>        // ���ݷ���ʹ��ջ��
#include<stdlib.h>
#define true  1
#define false 0
#define nmax 9        
              
int num=0;
int q[9];  // q[i]=j��ʾ��i�еĻʺ������j��
int C[9];  // c[j]=false��ʾ��i���ʺ����ڵ��в���ȫ
int L[17]; // "/"�����ϣ�i+j��ȣ��±�Ϊ2��16��b[k]Ϊ��ʱ��ʾ"/"�������޻ʺ�
int R[17]; // "\"�����ϣ�i-j��ȣ��±�Ϊ-7��7��+9��ʾ�±�2-16��c[k]Ϊ��ʱ��ʾ"\"�������޻ʺ�

void eightqueen(int); //eightqueen(i)�����Կص�i���ϵĻʺ�

void main( )
{
      int i=0;
      for(i=0; i< 9 ; i++) 
         C[i]=true;

      for(i=0; i< 17 ; i++) 
      {
         L[i]=true;
         R[i]=true;
      }
      eightqueen(1);       //�������˻ʺ�����
      system("pause");
}

//eightqqueen( )����
void eightqueen(int i)
 {    
      int j,k,c=0;
      for(j=1; j<=8 ; j++) 
      {
          if((C[j] == true && (L[i-j+nmax] == true)
              && (R[i+j]) == true))
          {
              q[i]=j;
              C[j] = false;
              L[i-j+nmax] = false;
              R[i+j] = false;

              if(i<8)
              {
                  eightqueen(i+1);
              }
              else
              {
                 num++;
                 printf("����%2d��", num);
                 for(k=1; k<=8; k++) 
                     printf("%d ", q[k]);
                 printf("\n");
              }
              C[j] = true;
              L[i-j+nmax] = true;
              R[i+j] = true;
        }
    }
}
#endif



