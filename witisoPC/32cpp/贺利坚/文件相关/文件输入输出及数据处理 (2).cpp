#include<stdio.h>// �ļ�������������ݴ���
struct Stuff
{
    int num;
    float pay;
    float PRP;    //Performance Related Pay;
    float total;
};

int main()
{
    FILE *fp;
    fp = fopen("salary1.txt", "r");
    if (fp == NULL)
    {
        printf("cannot open file salary.txt.\n");
        return 0;
    }
    struct Stuff s[100];
    int i;
    //��1�����ļ��ж�ȡ���ݣ����ܹ��ʣ�������Ļ����ʾ��
    for (i=0; i<100; i++)
    {
        fscanf(fp,"%d %f %f",&s[i].num,&s[i].pay,&s[i].PRP);
        s[i].total=s[i].pay+s[i].PRP;
        printf("%d %.2f %.2f %.2f\n", s[i].num,s[i].pay,s[i].PRP,s[i].total);
    }
    fclose(fp);
    //��2���������Ĺ��ʵ����浽�ļ�salary2.txt�С�
    FILE *fp2 = fopen("salary2.txt", "w");
    if (fp == NULL)
    {
        printf("cannot open file salary2.txt.\n");
        return 0;
    }
    for (i=0; i<100; i++)
    {
        fprintf(fp2,"%d %.2f %.2f %.2f\n", s[i].num,s[i].pay,s[i].PRP,s[i].total);
    }
    fclose(fp2);
    //��3�����ܹ��ʳ���5000Ԫ��Ա���Ĺ��ű��浽�ļ�rich.txt�С�
    FILE *fp3 = fopen("rich.txt", "w");
    if (fp == NULL)
    {
        printf("cannot open file rich.txt.\n");
        return 0;
    }
    for (i=0; i<100; i++)
    {
        if(s[i].total>=5000)
            fprintf(fp3,"%d\n", s[i].num);
    }
    fclose(fp3);
    //��4������Ļ����ʾ������ߵ�Ա���Ĺ�����Ϣ
    float max = s[0].total;
    int h=0;
    for (i=1; i<100; i++)
    {
        if(max<s[i].total)
        {
            max=s[i].total;
            h=i;
        }
    }
    printf("������ߵ���: ");
    printf("%d %.2f %.2f %.2f\n", s[h].num,s[h].pay,s[h].PRP,s[h].total);
    while(1);
    return 0;
}