#include <stdio.h>
#include <stdlib.h>
#include <stack>
using namespace std;

#define N 10
#define inf 99999999
int e[N][N];  // ��������
int p[N][N];  // ǰ������

void output2Darr(int arr[N][N],int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            printf("%10d",arr[i][j]);
        }
        printf("\n");
    }
}

void outputRoute(int i,int j)
{
    stack<int> st;
    printf("��%d����%d����̾���Ϊ��%d��·��:",i,j,e[i][j]);
    st.push(j);
    while(p[i][j]!=i)
    {
        st.push(p[i][j]);
        j=p[i][j];
    }
    st.push(i);
    do{
        printf("%d ",st.top());
        st.pop();
    }while(!st.empty());
    printf("\n");
}

int main()
{
    int k,i,j,n,m,a,b,s;
    
    printf("���붥�����n���ߵ�����m:\n");
    scanf("%d %d",&n,&m);
    //��ʼ��
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(i==j) 
                e[i][j]=0;
            else e[i][j]=inf;
    printf("�����,����a�ı�� ����b�ı�� ��������ľ���s,��1 2 2;\n");
    for(i=1;i<=m;i++)
    {
        scanf("%d %d %d",&a,&b,&s);
        e[a][b]=s;
    }
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(e[i][j]>0&&e[i][j]<inf)
                p[i][j]=i;
            else
                p[i][j]=-1;
    printf("��ʼ����eΪ��\n");
    output2Darr(e,n);
    //Floyd-Warshall�㷨�������
    for(k=1;k<=n;k++)        // ��㣬k
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(e[i][j]>e[i][k]+e[k][j] )
                {
                    e[i][j]=e[i][k]+e[k][j];
                    p[i][j]=p[k][j];   // ����j��ǰ��Ϊk
                }
    printf("ȫ������֮������·��Ϊ:\n");
    output2Darr(e,n);
    printf("�����ǰ��Ϊ:\n");
    output2Darr(p,n);
    outputRoute(4,3);
    outputRoute(3,2);

    system("pause");
    return 0;
}
/*���루�ɸ��ƣ�
4 8
1 2 2
1 3 6
1 4 4
2 3 3
3 1 7
3 4 1
4 1 5
4 3 12
*/

/*���
���붥�����n���ߵ�����m:
4 8
�����,����a�ı�� ����b�ı�� ��������ľ���s,��1 2 2;
1 2 2
1 3 6
1 4 4
2 3 3
3 1 7
3 4 1
4 1 5
4 3 12
��ʼ����eΪ��
         0         2         6         4
  99999999         0         3  99999999
         7  99999999         0         1
         5  99999999        12         0
ȫ������֮������·��Ϊ:
         0         2         5         4
         9         0         3         4
         6         8         0         1
         5         7        10         0
�����ǰ��Ϊ:
        -1         1         2         1
         4        -1         2         3
         4         1        -1         3
         4         1         2        -1
��4����3����̾���Ϊ��10��·��:4 1 2 3
��3����2����̾���Ϊ��8��·��:3 4 1 2

*/