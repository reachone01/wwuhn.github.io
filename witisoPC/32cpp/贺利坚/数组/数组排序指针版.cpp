#include <iostream>         // ��������ָ���
using namespace std;
void sort(int *p, int num);  //��Ҫ���Զ��庯�����������κθĶ�
void output(int*, int);

int main( )                 //��Ҫ��main�������κθĶ�
{
    int a[20]={86,46,22,18,77,45,32,80,26,88,57,67,20,18,28,17,54,49,11,16};
    int b[15]={27,61,49,88,4,20,28,31,42,62,64,14,88,27,73};
    sort(a,20);     //��ð�ݷ�����������a��Ԫ��
    output(a,20);   //�������������
    sort(b,15);     //��ð�ݷ�����������b��Ԫ��
    output(b,15);   //�������������
    return 0;
}
//���涨���Զ��庯��
void sort(int *p, int num)
{
    int i,j,t;
    for(j=0;j<num-1;j++)            //������num-1�˱Ƚ�
    {
        for(i=0;i<num-j-1;i++)      //��ÿ����Ҫ����num-j�������Ƚ�
        {
            if(*(p+i)<*(p+i+1))     //���ǰ�����С�ں������
            {
                t=*(p+i);           //������������λ�ã�ʹС���³�
                *(p+i)=*(p+i+1);
                *(p+i+1)=t;
            }
        }
    }
    return;
}

void output(int *p, int num)
{
    int i;
    for(i=0;i<num-1;i++)
        cout<<*(p+i)<<",";
    cout<<*(p+num-1)<<"\n"; //���һ�������治�Ӷ��ţ����ø����
    return;
}