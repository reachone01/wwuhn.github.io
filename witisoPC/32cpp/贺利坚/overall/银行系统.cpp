#include<iostream>   
#include<fstream>
using namespace std; 
//��ȫ�ֱ����洢�����ʻ��������Ϣ�����ڸ������乲�����ݣ���һ�ֽ���취��
//ֱ���ñ��������Ǻ÷��������潫����������
//ֱ���ڳ����д洢�����Ǻ÷�������Щ��ϢҪ�����ļ�
const int NUM=100;      //��ʱ���֧��100���û�����ʵ�����Ժܶ�
int account[NUM];       //�ʻ�
int pwd[NUM];           //����
double balance[NUM];    //���
int accountNum;         //ʵ���û������ɶ��ļ�����
int accountIndex;       //��ȫ�ֱ������浱ǰ��¼���ʻ���Ӧ���±�
int currentAccount;     //��ȫ�ֱ������浱ǰ��¼���ʻ�

//�����Զ��庯��
int checkStatus();
int seekUser(int);
void work();
void showbalance();
void drawmoney();
void deposit();
void transferAccounts();
void updatePassword();
void getInformation();  //���ڶ�ȡ�ʻ�����
void saveInformation(); //�˳�ǰ��������

int main()  
{  
    int status;
    char ch;
    cout<<"�ؼ����л�ӭ�����١�������Ҫ��bank.dat�е�����ȷ�����Ȿ�������еľ������ݣ���"<<endl;
    getInformation();   //���ڶ�ȡ��������
    while(1)            //֧���û���ε�¼����ҵ��
    {
        status=checkStatus();
        switch(status)
        {
        case 1:         //������ȷ 
            work();
            break;
        case 2:         //������ֹ��¼
            cout<<"��ӭ�´ι��١���"<<endl;
            break;
        case 3:
            cout<<"��ȷ���ʺź���������"<<endl;
            break;
        case 4:
            cout<<"�̿�������ϵ�ͽ�����������"<<endl;
        }
        cout<<"=====Ҫ�˳�ϵͳ���밴��Q��������������һλ�û���¼======"<<endl;
        fflush( stdin );  //������뻺����������getchar()�Զ����
        ch=getchar();
        if(ch=='q'||ch=='Q')break;
    }
    saveInformation();
    return 0;
}

/*��������
 *����ֵԼ��:
 * 1 - �û�����������ȷ�����Խ�һ������
 * 2 - �û���������¼�����˳�
 * 3 - �û��������˳�
 * 4 - ���ε�¼ʧ���̿����˳�
 */
int checkStatus()
{
    int iStatus=4;		    //Ĭ���̿��Ľ��
    int iPass;
    int num=1;
    char goOn;
    cout<<"�������ʻ�";
    cin>>currentAccount;    //currentAccount��ȫ�ֱ���
    accountIndex=seekUser(currentAccount);
    if(accountIndex < 0)    //����seekUser�Ķ��壬���ʾ�Ҳ�������ͻ�
        iStatus=3; 
    else
    {		
        do
        {	
            if(num==1)
                cout<<"����������";
            else
            {
                cout<<"������ʾ����������"<<num<<"���������룬���β��Խ��̿���"<<endl;
                cout<<"��Ҫ���������𣨼�������Y���˳�����N��֮��س�����";
                cin>>goOn;
                if('Y'==goOn||'y'==goOn)
                    cout<<"���ٴ���������";
                else
                {
                    iStatus=2; //�û�������¼
                    break;
                }
            }
            cin>>iPass;
            num++;
            if(iPass==pwd[accountIndex])    //�ʻ�
            {
                iStatus=1;                  //�������
                break;
            }
        }while(num<4);                      //���벻��ȷ�Ҵ���������Χ��ѭ��
        //�����ѭ����Ϊnum==4Ϊ����˳���iStatus��ֵ�����ֳ�ʼ3�������̿�
    }
    return iStatus; //����״̬
}	

//�����Ƿ��������ͻ���
//������ڣ��������Ӧ���±�
//��������ڣ�����-1(���Ұ�)
int seekUser(int iAccount)
{
    int i;
    for(i=0;i<accountNum;++i)//����˳����ң�ʵ��ϵͳ��ȷ��account[]���򣬽��ж��ֲ���
    {
        if(iAccount==account[i])
            break;
    }
    if(i>=accountNum)
        i=-1;  //�����Ҳ����������û�
    return i;
}

//����ҵ��
void work()
{
    char cChoice;
    bool bExit = false;
    do  
    {  
        cout<<endl<<"*  �����԰��������ҵ��"<<endl;  
        cout<<"*  1.��ѯ"<<endl;  
        cout<<"*  2.ȡ��"<<endl;  
        cout<<"*  3.���"<<endl;
        cout<<"*  4.ת��"<<endl;
        cout<<"*  5.�޸�����"<<endl;
        cout<<"*  0.�˳�"<<endl;  
        cout<<"*  �����루0-4����";  
        cin>>cChoice;
        switch(cChoice)
        {
        case '1':
            showbalance();
            break;  
        case '2':
            drawmoney();
            break;  
        case '3':
            deposit();
            break;  
        case '4':
            transferAccounts();
            break;  
        case '5':
            updatePassword();
            break;  
        case '0':
            cout<<"��ӭ���´������. "<<endl;
            bExit=true;
        }		
    }while(!bExit);  
    return;
}

//��ѯ���
void showbalance()
{
    cout<<"���ĵ�ǰ����ǣ�"<<balance[accountIndex]<<"Ԫ"<<endl;
}

//ȡ��
void drawmoney()
{  
    double money;  
    cout << "������ȡ���";  
    cin >> money;  
    //���治����Ϣ�ˣ������������ǵ�����ֻ�ṩ���п�ҵ���Ƕ���ͳһ��Ϣ��
    if(money<=balance[accountIndex])
    {
        balance[accountIndex]-=money; //ȡ��ɹ�
        cout<<"ȡ�����������ǣ�"<<balance[accountIndex]<<"Ԫ��"<<endl;
    }
    else
    {
        cout<<"�������㣬ȡ��ʧ�ܡ�"<<endl;
    }
}	
//���
void deposit()
{
    double money;  
    cout << "���������";  
    cin >> money;  
    //���治����Ϣ�ˣ������������ǵ�����ֻ�ṩ���п�ҵ���Ƕ���ͳһ��Ϣ��
    balance[accountIndex]+=money; //ȡ��ɹ�
    cout<<"������������ǣ�"<<balance[accountIndex]<<"Ԫ��"<<endl;
}

//ת��
void transferAccounts()
{
    double money;  
    int iAccount2,iAccount2Index;
    cout << "������ת�ʽ�";
    cin >> money;  
    if(money>balance[accountIndex]) //���в�͸֧������ת��
    {
        cout<<"�������㣬ת��ʧ�ܡ�"<<endl;
    }
    else
    {
        cout << "������Է��ʻ���";
        cin >> iAccount2; //Ӧ���ж϶Է��ʻ�����Ч����ת�ˣ���ʱ���������Ժ�Ľ�  
        iAccount2Index=seekUser(iAccount2);
        if(iAccount2Index==-1)
            cout<<"�Է��ʺ��������ת��ʧ�ܡ�"<<endl;
        else
        {
            balance[accountIndex]-=money; //�Ӽ���ת��
            balance[iAccount2Index]+=money; //ת���Է�
            //�˴�Ӧ��Ϊ�Է��ʻ���������ʱ��
            cout<<"ת�˺���������ǣ�"<<balance[accountIndex]<<"Ԫ���Է����Ϊ"<<balance[iAccount2Index]<<"Ԫ��"<<endl;
            //ʵ��ϵͳ�в�������������ʾ����¶��Ϣ̫���ˡ�
        }
    }
}			
//�޸�����
void updatePassword()
{
    int p1,p2;
    cout << "�����������룺";
    cin >> p1;  
    cout << "��ȷ�������룺";
    cin >> p2;  
    if(p1==p2)//�����������
    {
        pwd[accountIndex]=p1;   
        cout<<"�����޸ĳɹ���"<<endl;
    }
    else
    {
        cout<<"�������벻һ�£������޸�ʧ�ܡ�"<<endl;
    }
}

//���ļ��ж�ȡ���ݣ����浽ȫ��������
void getInformation()  //���ڶ�ȡ�ʻ�����
{
    ifstream infile("bank.dat",ios::in);  //������ķ�ʽ���ļ�
    if(!infile)       //�����Ƿ�ɹ���
    {
        cerr<<"���������Ҳ���������Ϣ��!"<<endl;
        exit(1);
    }
    int i=0;
    while(!infile.eof())
    {
        infile>>account[i]>>pwd[i]>>balance[i];
        ++i;
    }
    infile.close();
    accountNum=i;  //�û���Ŀ
    return;
}

//�˳�ʱ�����仯�˵����ݱ��浽�ļ��У��´����У������ϴε�ҵ���������ȥ
void saveInformation() //�˳�ǰ��������
{
    ofstream outfile("bank.dat",ios::out);  //������ķ�ʽ���ļ�
    if(!outfile)       //�����Ƿ�ɹ���
    {
        cerr<<"��������������Ϣ���治����!"<<endl;
        exit(1);
    }
    int i=0;
    while(i<accountNum)
    {
        outfile<<account[i]<<'\t'<<pwd[i]<<'\t'<<balance[i]<<'\n';
        ++i;
    }
    outfile.close();
    return;
}