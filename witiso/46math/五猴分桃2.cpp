/*
����ɽ����һ�ղ�ժ�������ɡ�����ɫ������Լ�����ٷ֡�
һ��ҹ�����£������ȳ�һ�ң������н��ҷ�Ϊ5�ݣ�ǡ�ɾ��֣���������(��ͬ)��ȡ��1�ݡ�
�������һ��ҹ�����£�Ҳ���ȳ�һ�ң�Ȼ���ҷ�Ϊ5�ݣ�ȡ��1�ݡ�
5�ﶼ������֮��
�����峿��5������������������һ�ѣ������þ��֣�����ϲ�ء�
��������ٲ�ժ���Ӷ��ٲ�����˽��С�
*/
#include<stdio.h>

bool sumDiv(int n) 
{    
    for(int i=0;i<5;i++)  // ˳��
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

int main2()   // ����
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

void main3() // ����
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
	getchar();
}


int divided(int n, int m)  // ����
{
    if(n/5==0 || n%5!=1)
        return 0;
    if(m==1) 
        return 1;
    return divided(n-n/5-1, m-1); // ����ת��n=n-(n-1)/5-1,��ͬ��n=n-n/5-1
    //return divided(n-(n-1)/5-1, m-1);
}

int main4()
{
    int n;
    int m = 5;
    for(n = 1; ; n++)
        if(divided(n,m))
        {
            printf("ԭ������������%d\n", n);
            break;
        }
    getchar();
    return 0;
}

int peach_monkey(int start,int sumEnd,int monkey){  // ����
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
int main5() 
{
    printf("ԭ��������%d��",peach_monkey(4,4,5));
    getchar();
    return 0;
}


