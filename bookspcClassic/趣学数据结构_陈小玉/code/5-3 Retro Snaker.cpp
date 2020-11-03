#include<iostream>
#include<algorithm>
using namespace std;

typedef struct
{
    int x;
    int y;
} Position;         // λ��

int m[30][30];      // ��ͼ
Position here,next; // ��ǰλ�ã���һ��λ��
Position DIR[4]={0, 1, 1, 0, 0, -1, -1, 0}; // �������Ϸ�������

void Init(int n)
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)   // �������г�ʼ��Ϊ0
            m[i][j]=0;
    }
    for(j=0;j<=n+1;j++)     // ������������Χǽ
        m[0][j]=m[n+1][j]=-1;
    for(i=0;i<=n+1;i++)     // ������������Χǽ
        m[i][0]=m[i][n+1]=-1;
}

void Print(int start,int endi)  // start, endiΪ��ʼ�ͽ����±�
{
    for(int i=start;i<=endi;i++)
    {
        cout<<m[i][start];
        for(int j=start+1;j<=endi;j++)
            cout<<"\t"<<m[i][j];
        cout<<endl;
    }
    cout<<endl;
}

// n��ԭ�����ģ
// m����ͼ����
void Solve(int n)
{
    here.x=1;                           // ���Ͻ��е����λ��
    here.y=1;
    int dirIndex=0;
    int num=1;
    m[1][1]=1;
    while(num<n*n)
    {
        next.x=here.x+DIR[dirIndex].x;
        next.y=here.y+DIR[dirIndex].y;
        if(m[next.x][next.y]==0)        // �ж���һ��λ���Ƿ��е���
        {
            m[next.x][next.y]=++num;    // ���˵��⣬���������ּ�1
            here=next;                  // ��nextΪ��ǰλ�ã�������
        }
        else
            dirIndex=(dirIndex+1)%4;    // ����һ�����򣬰���������˳������Ե���
    }
}


int main()
{
    int n=0;
    cout<<"���������1С�ڵ���20������n:"<<endl;
    cin>>n;
    while(n<1||n>20)
    {
        cout<<"���������1С�ڵ���20������n:"<<endl;
        cin>>n;
    }
    Init(n);
    Print(0,n+1);
    Solve(n);
    Print(1,n);
    while(1);
    return 0;
}
/*
���������1С�ڵ���20������n:
8
-1      -1      -1      -1      -1      -1      -1      -1      -1      -1
-1      0       0       0       0       0       0       0       0       -1
-1      0       0       0       0       0       0       0       0       -1
-1      0       0       0       0       0       0       0       0       -1
-1      0       0       0       0       0       0       0       0       -1
-1      0       0       0       0       0       0       0       0       -1
-1      0       0       0       0       0       0       0       0       -1
-1      0       0       0       0       0       0       0       0       -1
-1      0       0       0       0       0       0       0       0       -1
-1      -1      -1      -1      -1      -1      -1      -1      -1      -1

1       2       3       4       5       6       7       8
28      29      30      31      32      33      34      9
27      48      49      50      51      52      35      10
26      47      60      61      62      53      36      11
25      46      59      64      63      54      37      12
24      45      58      57      56      55      38      13
23      44      43      42      41      40      39      14
22      21      20      19      18      17      16      15

*/