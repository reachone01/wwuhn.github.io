//���ú���printchs����Ǻ�ͼ
#include <iostream>
using namespace std;
//������дprintchs�����Ķ��壬���������һ�����ɸ�ָ���ַ�


#include <stdio.h> // ʹ�ú�������ά��һάǶ��
void printchs(int n,char ch)
{
    for(int i=0;i<n;i++)
        printf("%c",ch);
}
int main( )
{ 
    int n=6; //n����Ҫ���������
    int i;
    //ͨ���������ѭ�������printchs��������������ͼ
    for(i=1; i<=n; ++i)
    {
        printchs(n-i,' ');
        printchs(2*i-1,'*') ;
        cout<<endl;
    }
    while(1);
    return 0;
} 