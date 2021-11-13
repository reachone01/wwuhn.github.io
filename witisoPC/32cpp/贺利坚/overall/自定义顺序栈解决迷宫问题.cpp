#include <iostream> // �Զ���˳��ջ����Թ�����
#include <iomanip>
#include <cstdlib>
using namespace std;
 
#define MaxSize 100
int maze[10][10] =   //����һ���Թ���0��ʾͨ����1��ʾǽ
{
    {1,1,1,1,1,1,1,1,1,1},
    {1,0,0,1,1,0,0,1,0,1},
    {1,0,0,1,0,0,0,1,0,1},
    {1,0,0,0,0,1,1,0,0,1},
    {1,0,1,1,1,0,0,0,0,1},
    {1,0,0,0,1,0,0,0,0,1},
    {1,0,1,0,0,0,1,0,0,1},
    {1,0,1,1,1,0,1,1,0,1},
    {1,1,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1}
};
 
struct Try //����һ��ջ������·��
{
    int i;               //��ǰ������к�
    int j;               //��ǰ�㳡���к�
    int d;               //di����һ���߷�λ�ķ�λ��
} path[MaxSize];         //����ջ
 
int top = -1;            //��ʼ��ջָ��
 
void findPath(int xb, int yb, int xe, int ye)          //·��Ϊ��(xb,yb)��(xe,ye)
{
    int i, j, d, find, k;
    top++;                                             //��ʼ�����ջ
    path[top].i = xb;
    path[top].j = yb;
    path[top].d = -1;
    maze[xb][yb] = -1;
    while(top>-1)                                      //ջ��Ϊ��ʱѭ��
    {
        i = path[top].i;
        j = path[top].j;
        d = path[top].d;
        if(i==xe && j==ye)                             //�ҵ��˳��ڣ����·��
        {
            cout << "�Թ�·�����£�\n";
            for(k=0; k<=top; k++)
            {
                cout << "\t(" << path[k].i << "," << path[k].j << ")";
                if((k+1)%5==0) cout << endl;            //ÿ�����������һ��
            }
            cout << endl;
            return;
        }
        find = 0;
        while(d<4 && find==0)                          //����һ�����ߵĵ�
        {
            d++;
            switch(d)
            {
            case 0:  //����
                i = path[top].i-1;
                j = path[top].j;
                break;
            case 1: //����
                i = path[top].i;
                j = path[top].j+1;
                break;
            case 2:  //����
                i = path[top].i+1;
                j = path[top].j;
                break;
            case 3:  //����
                i = path[top].i;
                j = path[top].j-1;
                break;
            }
            if(maze[i][j]==0) find = 1;                    //�ҵ�ͨ·
        }
        if(find==1)                                        //�ҵ�����һ�����߷���
        {
            path[top].d = d;                               //�޸�ԭջ��Ԫ�ص�dֵ
            top++;                                         //��һ�����߷����ջ
            path[top].i = i;
            path[top].j = j;
            path[top].d = -1;
            maze[i][j] = -1;                                 //�����ظ��ߵ��������
            //cout << "\t(" << path[top].i << "," << path[top].j << ")"; //��ʾ��������̽
        }
        else  //û��·���ߣ�����ջ
        {
            maze[path[top].i][path[top].j] = 0;                  //�ø�λ�ñ������·�����߷���
            top--;
        }
    }
    cout << "û�п���·����\n";
}
 
int main()
{
    findPath(1,1,8,8);  //��(1,1)�룬(8,8)��
    while(1);
    return 0;
}