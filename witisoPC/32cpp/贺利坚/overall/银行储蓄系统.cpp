// ���д���ϵͳ

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
 
#define upNum 2000 //ϵͳ������ɵ��û���
 
int user[upNum][3];  //�˺š����롢״̬
char name[upNum][10];   //�û���
double balance[upNum];  //�˻����
//������ͬ���±꣬����ͬһ�˵���Ϣ
int N;  //ʵ�ʵ��û���Ŀ
 
int pass();  //ҵ��Ա��¼
void readData();  //��ʼǰ���ļ��ж����ݣ�����������
void writeData();   //�������ǰ���������е�����д�뵽�ļ���
void work();  //ҵ������
int chooseInMenu(); //��ʾ�˵�����ҵ��Աѡ��
void openAccount(); //����
void cancelAccount();  //ע���˻�
void save();   //���
void withdraw();   //ȡ��
void showAccount(); //��ѯ���
void transferAccounts();  //ת��
void reportLoss();  //��ʧ
void cancelLoss();  //�����ʧ
void updatePassword();   //��������
int inputPassword();   //���ؼ������������
int search(int);  //�����˺��ҵ��û����ݶ�Ӧ���±�
 
/*��������*/
int main()
{
    printf("+----------------------+\n");
    printf("+    ��ӭ����CSDN����  +\n");
    printf("+----------------------+\n");
    if (pass())
    {
        readData();
        work();
        writeData();
    }
    return 0;
}
 
/*
���ܣ���֤�û�����
����ֵ��������ȷ������1��
        ����ͨ��������֤������0
*/
int pass()
{
    char sNameInFile[20];   //���ļ��ж�����ҵ��Ա�û���
    char sPassInFile[20];  //�ļ��б�������룬��һ�汾�У����ַ���������
    char sName[20];   //ҵ��Ա��¼ʱ������û���
    char sPass[20];  //ҵ��Ա��¼ʱ���������
    char ch;
    int iTry=3;   //����ϵͳʱ���ԵĴ���
    int right = 0;  //Ҫ���صĽ����0-����ȷ 1-��ȷ
    FILE *fp;  //�����ļ�����
    //���뱣�����ļ��У���ȡ��
    if ((fp=fopen("worker.txt", "r"))==NULL)
    {
        printf("password file cannot open!");
        exit(0);
    }
    fscanf(fp, "%s %s", sNameInFile, sPassInFile);  //���ļ��ж�ҵ��Ա�û�������������
    fclose(fp);
 
    //����ϵͳ���������β��Խ��˳�
    do
    {
        printf("������ҵ��Ա�û���:");
        scanf("%s", sName);
        printf("����������:");
        int i=0;
        while((ch=getch())!='\r')  //getch�ڽ�������󣬲�����Ļ����ʾ
        {
            sPass[i++]=ch;
            putchar('*');   //�����κ��ַ�����Ļ��ֻ��ʾ*
        }
        sPass[i]='\0';
        fflush(stdin);
        printf("\n");
        if(strcmp(sPass,sPassInFile)==0&&strcmp(sName,sNameInFile)==0)
        {
            right = 1;
            break;
        }
        else
        {
            iTry--;
            if(iTry>0)
                printf("����3�ν��˳����㻹���Գ���%d�Σ�\n", iTry);
            else
            {
                printf("�Բ����㲻�ܽ���ϵͳ\n");
            }
        }
    }
    while(iTry);
    return right;
}
 
/*
����getch()��һ��˵����
����ͷ�ļ���conio.h
������;���ӿ���̨��ȡһ���ַ���������ʾ����Ļ��
����ԭ�ͣ�int getch(void)
����ֵ����ȡ���ַ�
�ڲ�ͬƽ̨������س���getch()�����ز�ͬ��ֵ����getchar()ͳһ����10(��\n)
1)windowsƽ̨��ENTER�����������ת���ַ� \r\n�����getch����13(\r)��
2)unix�� linuxϵͳ��ENTER��ֻ���� \n �����getch����10(\n)��
3)MAC OS��ENTER�������� \r �����getch����13(\r)��
Ϊ������̻�������δ�������ַ�Ӱ�������fflush(stdin);������뻺����
*/
 
/*
���ܣ�����ҵ��
*/
void work()
{
    int iChoice;   //����ѡ��ϵͳ����
    //����ҵ��
    do
    {
        iChoice = chooseInMenu();  //�Ӳ˵��л�ù��ܴ���
        switch(iChoice)
        {
        case 1:
            openAccount(); //����
            break;
        case 2:
            cancelAccount();  //ע���˻�
            break;
        case 3:
            save();  //���
            break;
        case 4:
            withdraw();   //ȡ��
            break;
        case 5:
            showAccount(); //��ѯ���
            break;
        case 6:
            transferAccounts();  //ת��
            break;
        case 7:
            reportLoss();  //��ʧ
            break;
        case 8:
            cancelLoss();  //�����ʧ
            break;
        case 9:
            updatePassword();   //��������
            break;
        case 0:
            printf("��ӭ������. \n");
        }
    }
    while(iChoice);
}
 
/*
���ܣ����ļ��ж�ȡ��������
*/
void readData()
{
    FILE *fp;  //�����ļ�����
    int i = 0;
    //���ļ���ȡ�����
    if ((fp=fopen("account.dat", "r"))==NULL)
    {
        printf("data file cannot open!");
        exit(0);
    }
    while(fscanf(fp,"%d %s %d %lf %d",&user[i][0], name[i], &user[i][1], &balance[i],&user[i][2] ) != EOF)
    {
        i++;
    }
    N = i; //��ȫ�ֱ����洢�û���������
    fclose(fp);
    return;
}
 
/*
���ܣ����û����ݱ��浽�ļ���
*/
void writeData()
{
    FILE *fp;  //�����ļ�����
    int i=0;
    //�������
    if ((fp=fopen("account.dat", "w"))==NULL)
    {
        printf("data file cannot open!");
        exit(0);
    }
    for(i=0; i<N; i++)
        fprintf(fp,"%d %s %d %f %d\n",user[i][0], name[i], user[i][1], balance[i],user[i][2]);
    fclose(fp);
}
 
/*
���ܣ���ʾ�˵�����ҵ��Աѡ��
����ֵ���û�ѡ��Ĺ��ܣ���Χ0-9
*/
int chooseInMenu()
{
    int i;
    while(1)
    {
        printf("\n");
        printf("+----------------------------+\n");
        printf("+ 1 ����    2 ����    3 ��� +\n");
        printf("+ 4 ȡ��    5 ��ѯ    6 ת�� +\n");
        printf("+ 7 ��ʧ    8 ���    9 ���� +\n");
        printf("+                     0 �˳� +\n");
        printf("+----------------------------+\n");
        printf("���������ָ��:");
        scanf("%d", &i);
        if(i>=0 && i<=9)
            break;
        else
            printf("������ѡ����\n\n");
    }
    return i;
}
 
/*
���ܣ�����
˵�����ڽ���ϵͳʱ���ڶ������ݹ����У��Ѿ���¼���û���ΪN���������ж�Ӧ�±�Ϊ0~N-1
  ����ʱҪ����һ���û���ֻҪΪ�±�ΪN������Ԫ����ֵ�����ڳɹ�֮����N++���ɡ�
  ������˳�����Ӽ򵥣��������ĺ��ǣ��ڲ�ѯ�˻�ʱ�����ò���˳����ң�����Ч�����ǲ�����ġ�
  �Ľ����ֶΣ�1��������ʱ�������˺ţ������ݲ��뵽�����У�ʹ���˺���������������ʱ�鷳�����������Ժ�ҪƵ���Ĳ�ѯ����
  �Ľ����ֶΣ�2�����˺���ϵͳ�Զ����ɣ���֤��������������˳�����ӵ�ʱ�򣬾ͱ�֤��������
*/
void openAccount()
{
    if(N==upNum)
    {
        printf("�����û����Ѿ��ﵽ���ޣ������ٿ���");
        return;
    }
    //��������������ҵ��
    printf("���ڿ���\n");
    printf("�˺ţ�");
    scanf("%d", &user[N][0]);
    printf("����������");
    scanf("%s", name[N]);
    int iPass1, iPass2;
    printf("���룺");
    iPass1=inputPassword();  //��������1
    printf("ȷ�����룺");
    iPass2=inputPassword();  //��������2
    if(iPass1==iPass2)
    {
        user[N][1]=iPass1;
        user[N][2]=0; //�˻�״̬Ϊ��������
        printf("�����");
        scanf("%lf", &balance[N]);
        N++; //��ʽ�û�������1��ȷ�������û��Ѿ�����
        printf("�ɹ�������\n");
    }
    else
    {
        printf("�������벻һ�£�δ�ɹ�������\n"); //û��N++��������ֵ��Ч
    }
}
 
/*
���ܣ�ע���˻�
˵�����ҵ��˻���������״̬��Ϊ2-ע�����ɡ�
ע��ǰӦ�ü����Ӧ����ȡ����ע��
*/
void cancelAccount()
{
    int id;   //����������˺�
    int who;  //���ҵ����˺��������ж�Ӧ���±�
    int iPass;
    printf("�������˺ţ�");
    scanf("%d", &id);
    who = search(id);  //�����˺Ų�ѯ�û��������û����±�
    if(who<0)   //˵��id�˻�������
    {
        printf("���û������ڣ�����ʧ�ܣ�\n");
    }
    else
    {
        printf("����������%s\n", name[who]);
        printf("���룺");
        iPass=inputPassword();
        if(iPass==user[who][1])
        {
            printf("��%.2f Ԫ\n", balance[who]);
            printf("ȷ��������y/n����");
            if(tolower(getchar())=='y')
            {
                balance[who]=0;  //ȡ�������0
                user[who][2]=2;  //״̬��Ϊע��
                printf("ȡ�� %.2f Ԫ�������ɹ���\n", balance[who]);
            }
            else
            {
                printf("��ȡ���˲���������ʧ�ܣ�\n");
            }
            fflush(stdin);  //�����getchar()ʱ�ڼ��̻����е�����������Ӱ���������
        }
        else
        {
            printf("����������������ʧ�ܣ�\n");
        }
    }
}
 
/*
���ܣ����
˵������Ҫ��֤�˻����ڣ��Ҵ�������״̬
*/
void save()
{
    int id, who;
    double money;
    printf("�˺ţ�");
    scanf("%d", &id);
    who = search(id);  //�����˺Ų�ѯ�û��������û����±�
    if(who<0)   //˵��id�˻�������
    {
        printf("���û������ڣ����ʧ�ܣ�\n");
    }
    else
    {
        if(user[who][2]==0)
        {
            printf("����������%s\n", name[who]);
            printf("������");
            scanf("%lf", &money);
            balance[who]+=money;
            printf("��������%.2fԪ. \n",balance[who]);
        }
        else if(user[who][2]==1)
        {
            printf("���û����ڹ�ʧ״̬�����ʧ�ܣ�\n");
        }
        else
        {
            printf("���û��Ѿ����������ʧ�ܣ�\n");
        }
    }
    return;
}
 
/*
���ܣ�ȡ��
˵������Ҫ��֤�˻����ڣ��Ҵ�������״̬�����⣬���Ҫ�㹻ȡ
*/
void withdraw()
{
    int id, who;
    int iPass;
    double money;
    printf("�˺ţ�");
    scanf("%d", &id);
    who = search(id);  //�����˺Ų�ѯ�û��������û����±�
    if(who<0)   //˵��id�˻�������
    {
        printf("���û������ڣ�ȡ��ʧ�ܣ�\n");
    }
    else
    {
        if(user[who][2]==0)
        {
            printf("����������%s\n", name[who]);
            printf("���룺");
            iPass=inputPassword();
            if(iPass!=user[who][1])
            {
                printf("�����������ȡ��ʧ�ܣ�\n");
            }
            else
            {
                printf("����ȡ��");
                scanf("%lf", &money);
                if(money>balance[who])  //�ף�����͸֧
                {
                    printf("���㣬ȡ��ʧ�ܣ�\n");
                }
                else
                {
                    balance[who]-=money;
                    printf("ȡ��󣬻���%.2fԪ. \n",balance[who]);
                }
            }
        }
        else if(user[who][2]==1)
        {
            printf("���û����ڹ�ʧ״̬��ȡ��ʧ�ܣ�\n");
        }
        else
        {
            printf("���û��Ѿ�������ȡ��ʧ�ܣ�\n");
        }
    }
    return;
}
 
/*
���ܣ���ѯ�˻�
˵������ʾ�˻���Ϣ
*/
void showAccount()
{
    int id, who;
    int iPass;
    printf("�˺ţ�");
    scanf("%d", &id);
    who = search(id);  //�����˺Ų�ѯ�û��������û����±�
    if(who<0)   //˵��id�˻�������
    {
        printf("���û������ڣ���ѯ��ϣ�\n");
    }
    else
    {
        printf("����������%s\n", name[who]);
        printf("���룺");
        iPass=inputPassword();
        if(iPass!=user[who][1])
        {
            printf("����������󣬲��ܼ�����ѯ������Ϣ��\n");
        }
        else
        {
            printf("��%.2fԪ. \n",balance[who]);
            printf("״̬��");
            if(user[who][2]==0)
            {
                printf("����\n");
            }
            else if(user[who][2]==1)
            {
                printf("��ʧ\n");
            }
            else
            {
                printf("�Ѿ�����\n");
            }
        }
    }
    return;
}
 
/*
���ܣ�ת��
˵������Ҫ��֤�����˻������ڣ��Ҵ�������״̬�����⣬ת���˻������Ҫ�㹻
*/
void transferAccounts()
{
    int id, whoout, whoin;
    int iPass;
    double money;
    printf("����ת���˺ţ�");
    scanf("%d", &id);
    whoout = search(id);  //�����˺Ų�ѯ�û��������û����±�
    if(whoout<0)   //˵��id�˻�������
    {
        printf("���û������ڣ�ת��ʧ�ܣ�\n");
    }
    else
    {
        if(user[whoout][2]==0)
        {
            printf("����������%s\n", name[whoout]);
            printf("���룺");
            iPass=inputPassword();
            if(iPass!=user[whoout][1])
            {
                printf("�����������ת��ʧ�ܣ�\n");
            }
            else
            {
                printf("����ת�˽�");
                scanf("%lf", &money);
                if(money>balance[whoout])  //�ף�����͸֧
                {
                    printf("���㣬ת��ʧ�ܣ�\n");
                }
                else
                {
                    printf("����ת���˺ţ�");
                    scanf("%d", &id);
                    whoin = search(id);  //�����˺Ų�ѯ�û��������û����±�
                    if(whoin<0)
                    {
                        printf("ת���˻������ڣ�ת��ʧ�ܣ�\n");
                    }
                    else
                    {
                        if(user[whoin][2]>0)
                        {
                            printf("ת���˻��쳣��ת��ʧ�ܣ�\n");
                        }
                        else
                        {
 
                            balance[whoout]-=money;
                            balance[whoin]+=money;
                            printf("ȡ���������%.2fԪ. \n",balance[whoout]);
                        }
                    }
                }
            }
        }
        else
        {
            printf("���˻��쳣��ת��ʧ�ܣ�\n");
        }
    }
    return;
}
 
/*
���ܣ���ʧ�˻�
*/
void reportLoss()
{
    int id, who;
    int iPass;
    printf("�˺ţ�");
    scanf("%d", &id);
    who = search(id);  //�����˺Ų�ѯ�û��������û����±�
    if(who<0)   //˵��id�˻�������
    {
        printf("���û������ڣ����ܹ�ʧ��\n");
    }
    else
    {
        printf("����������%s\n", name[who]);
        printf("���룺");
        iPass=inputPassword();
        if(iPass!=user[who][1])
        {
            printf("����������󣬲��ܼ���������\n");
        }
        else
        {
            if(user[who][2]==0)
            {
                user[who][2]=1;
                printf("��ʧ�ɹ�\n");
            }
            else if(user[who][2]==1)
            {
                printf("���˻��Ѿ����ڹ�ʧ״̬\n");
            }
            else
            {
                printf("���˻������������ܹ�ʧ\n");
            }
        }
    }
    return;
}
 
/*
���ܣ������ʧ
*/
void cancelLoss()
{
    int id, who;
    int iPass;
    printf("�˺ţ�");
    scanf("%d", &id);
    who = search(id);  //�����˺Ų�ѯ�û��������û����±�
    if(who<0)   //˵��id�˻�������
    {
        printf("���û������ڣ������ʧʧ�ܣ�\n");
    }
    else
    {
        printf("����������%s\n", name[who]);
        printf("���룺");
        iPass=inputPassword();
        if(iPass!=user[who][1])
        {
            printf("����������󣬲��ܼ���������\n");
        }
        else
        {
            if(user[who][2]==0)
            {
                printf("���˻���������״̬������Ҫ�����ʧ\n");
            }
            else if(user[who][2]==1)
            {
                user[who][2]=0;
                printf("�����ʧ�ɹ�\n");
            }
            else
            {
                printf("���˻���������������Ч\n");
            }
        }
    }
    return;
}
 
/*
���ܣ�������
*/
void updatePassword()
{
    int id, who;
    int iPass, iPass1, iPass2;
    printf("�˺ţ�");
    scanf("%d", &id);
    who = search(id);  //�����˺Ų�ѯ�û��������û����±�
    if(who<0)   //˵��id�˻�������
    {
        printf("���û������ڣ��޸�����ʧ�ܣ�\n");
    }
    else
    {
        printf("����������%s\n", name[who]);
        printf("���룺");
        iPass=inputPassword();
        if(iPass!=user[who][1])
        {
            printf("����������󣬲��ܼ���������\n");
        }
        else
        {
            printf("�����룺");
            iPass1=inputPassword();  //��������1
            printf("ȷ�����룺");
            iPass2=inputPassword();  //��������2
            if(iPass1==iPass2)
            {
                user[who][1]=iPass1;
                printf("�޸ĳɹ���\n");
            }
            else
            {
                printf("�������벻ͬ���޸�ʧ�ܣ�\n");
            }
        }
    }
    return;
}
 
/*
���ܣ���������
����ֵ�����͵�����ֵ
����˵����
��1���˹����ڶ��ģ���ж�Ҫ�õ��ҹ��ܵ�һ���ʷ��������������ҵһ������
��2��Ϊ�˱�����������ֻ��ʾ*����������ʱ���ַ���ʽ���룬����תΪ��Ӧ��������
��3���涨�����ɲ�ȫΪ0��6λ���ֹ��ɣ�����ͷ��'0'ʱ��ʵ�ʲ���6λ����һ�����������������
������ʵ�ʵ�ϵͳ�У�����ͨ�����ַ�����������ʹֻ������������ַ�
*/
int inputPassword()
{
    char ch;  //�����ַ���ʽ����
    int iPass=0;   //Ҫת��Ϊ����
    int i;
    while(1)
    {
        for(i=0; i<6; i++)
        {
            ch=getch();  //���뵫����ʾ
            putchar('*');   //���*
            if(isdigit(ch))
                iPass=iPass*10+(ch-'0');
            else
            {
                iPass=0;
                break;  //�˳�forѭ�����ٴν���
            }
        }
        fflush(stdin); //������̻��������Ѿ��е�����
        printf("\n");
        if(iPass==0)  //��������������������������������˷������ַ���ֱ������Ϊ0����6λȫ0�������˳�forѭ��
        {
            printf("����Ҫ��ȫΪ���֣��Ҳ���ȫ0��\n");
            printf("��������������: ");
        }
        else
            break;
    }
    return iPass;
}
 
/*
���ܣ������˺Ų�ѯ�û��������û����±�
��ڲ�����Ҫ��ѯ�û����˺�
����ֵ��������û����ڣ����ظ��û��������е��±꣬���򣬷���һ��������-1��
˵����
  ���ڲ��ܱ�֤��user�����а��˺����򣬱�ģ�鲻�ò�����˳����ң�����һ��Ч�ʺܵ͵��㷨
  ����ڿ���ģ���б�֤�˰��˺����򣬱���������ѡ�������㷨��������ģ���˵����
*/
int search(int id)
{
    int index=-1;
    int i;
    for(i=0; i<N; i++)
    {
        if(user[i][0]==id)
        {
            index=i;
            break;   //�ҵ��ˣ������˳�ѭ��
        }
    }
    return index; //���ҵ�����ֵ��0~N-1�䣬���򣬱���-1
}