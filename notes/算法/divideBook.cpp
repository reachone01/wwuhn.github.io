#include <iostream>
using namespace std;

int like[5][5]={
    {0,0,1,1,0},
    {1,1,0,0,1},
    {0,1,1,0,1},
    {1,0,0,1,0},
    {0,1,0,0,1}};

int take[5]={0,0,0,0,0};  // ��¼ÿһ����ķ������
int n = 0;                // n��ʾ���鷽����

void trynext(int i);

int main()
{
    trynext(0);
    cin.get();
    return 0;
}

void trynext(int i)        // �Ե� i ���˽��з���
{
    for(int j=0;j<5;j++)   // ���
    {
        if(like[i][j]&&take[j]==0)
        {
            take[j]=i+1;// �ѵ�j����������i����
            if(i==4)    // ��5���˷��������Ҳ�����е����Ѿ�������ϣ�
                        // ���Խ������������
            {
                n++;
                cout<<"���䷽��"<<n<<":"<<endl;
                for(int k=0;k<5;k++)
                    cout<<"�鱾"<<k<<"��"<<static_cast<char>(take[k]+'A'-1)<<endl;
                cout<<endl;
            }
            else
                trynext(i+1);    // �ݹ飬����һ���˽��з���
            take[j]=0;           // ���ݣ�Ѱ����һ�ַ���
        }
    }
}
/*
���䷽��1:
�鱾0��B
�鱾1��C
�鱾2��A
�鱾3��D
�鱾4��E

���䷽��2:
�鱾0��B
�鱾1��E
�鱾2��A
�鱾3��D
�鱾4��C

���䷽��3:
�鱾0��D
�鱾1��B
�鱾2��C
�鱾3��A
�鱾4��E

���䷽��4:
�鱾0��D
�鱾1��E
�鱾2��C
�鱾3��A
�鱾4��B

*/    