#include  <iostream> //��ά�����ȡɨ������
#include <ctime>
#include <cstdlib>
using namespace std;
void setdata(int a[8][8]);      //���������
void out(int a[8][8]);          //�������
void outDiagonal(int a[8][8]);  //����Խ���Ԫ�ص�ֵ
void mine(int a[8][8],int x, int y);    //����ɨ�ס���Ϸ�Ĺ���������ڸ���
void change(int a[8][8]);               //��Ҫ��ı���ֵ
int main()
{
    int a[8][8],x,y;
    setdata(a);
    out(a);
    outDiagonal(a);
    cout<<"����һ��λ��:";
    cin>>x>>y;
    mine(a,x,y);
    change(a);
    cout<<"������ı�������ֵΪ:"<<endl;
    out(a);
    while(1);
    return 0;
}


void setdata(int a[8][8])
{
    int i,j;
    srand(time(NULL));//��Ҫ�õ�ǰʱ���������ӡ����Ա�ÿ������ȡ�õ����в�ͬ
    for(i=0; i<8; i++)
        for(j=0; j<8; j++)
            a[i][j]=rand()%50+1;  //�˽�rand()���������Ķ��й�ϵͳ�������ĵ�
        return;
}


//�����������������
void out(int a[8][8])
{
    int i,j;
    cout<<"����������Ķ�ά����Ϊ:"<<endl;
    for(i=0; i<8; i++)
    {
        for(j=0; j<8; j++)
            cout<<a[i][j]<<'\t';
        cout<<endl;
    }
    cout<<endl;
    return;
}


//����Խ���Ԫ�ص�ֵ�������ϵ����¡������ϵ����£�
void outDiagonal(int a[8][8])
{
    int i;
    //��������ϵ����¶Խ����ϵ�Ԫ�ص�ֵ
    cout<<"�����ϵ����¶Խ����ϵ�Ԫ�ص�ֵΪ��"<<endl;
    for(i=0; i<8; i++)
        cout<<a[i][i]<<'\t';   //���ؿ�����a[i][j]��ʽ�����鷳�ر���i��j�Ĺ�ϵ
    cout<<endl;
    //��������ϵ����¶Խ����ϵ�Ԫ�ص�ֵ
    cout<<"�����ϵ����¶Խ����ϵ�Ԫ�ص�ֵΪ��"<<endl;
    for(i=0; i<8; i++)
        cout<<a[i][7-i]<<'\t';   // a[i][7-i]��б�Խ�
    cout<<endl;
    cout<<endl;
}


//��ɨ����Ϸ�������a[x][y]��Χ��8������
void mine(int a[8][8],int x, int y)
{
    int i,j,sum=0;
    cout<<"a["<<x<<"]["<<y<<"]��Χ�����ǣ�"<<endl;
    for (i = x - 1; i <= x +1; i++)
    {
        for (j = y - 1; j<= y + 1; j++)
        {
            if ((i>= 0) && (i <= 7) && (j >= 0) && (j <= 7)&& !((i == x ) && (j == y))) //��if�е����������������������Ԫ�ء����Ρ�����Ҫѧ�����ּ���˼·����Ҫһ����һһ�о٣���Ҫд���ܶ�if��������
            {
                cout<<a[i][j]<<'\t';
                sum+=a[i][j];
            }
        }
    }
    cout<<endl<<"��Щ���ĺ���:"<<sum<<endl<<endl;
}


//����Ŀ�����Թ������Ԫ�ص�ֵ
/*�ı�Ĺ����ǣ�
�ӵ�2�У���a[1]�У���ʼ�����һ�У�ÿһԪ���������Ϸ�Ԫ�غ����Ϸ�Ԫ��֮�ͣ�����
a[1][0]ȡa[0][0]��a[0][1]֮�ͣ�
a[1][1]ȡa[0][1]��a[0][2]֮�ͣ�������
�Ը������һ��Ԫ�أ������Ϸ������ݣ�ȡ��һ���еĵ�һ��Ԫ�أ���
a[1][7]ȡa[0][7]��a[0][0]֮�͡�
*/
void change(int a[8][8])
{
    int i,j;
    for(i=1; i<8; i++)
        for(j=0; j<8; j++)
            a[i][j]=a[i-1][j]+a[i-1][(j+1)%8];  //(j+1)%8��ʹj=7ʱ�����ʵ�a[i][0]Ԫ��
        return;
}
