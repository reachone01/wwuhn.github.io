#include<iostream>
using namespace std; 
int main()  
{  
    int  type, days;  
    double money, period, rate, interest;  
    cout << "��ӭʹ����Ϣ��������"<<endl;
    cout << "���������";  
    cin >> money;  
    cout << "======�������======" << endl;  
    cout << "1. ���ڴ��" << endl;
    cout << "2. 3���� " << endl;
    cout << "3. 6����" << endl;
    cout << "4. һ�� " << endl;
    cout << "5. ����" << endl;
    cout << "6. ����" << endl;
    cout << "7. ����" << endl;
    cout << "�����������޵Ĵ��ţ�";
    cin >> type;
    if (type>=1 && type <=7)
    {
        switch(type)//��if��Ƕ����switch���������
        {
        case 1: 
            cout<<"��������������";
            cin >> days;
            period = days/360.0;
            rate = 0.005;
            break;
        case 2:
            period = 0.25;
            rate = 0.031;
            break;
        case 3:
            period = 0.5;
            rate = 0.033;
            break;
        case 4:
            period = 1;
            rate = 0.035;
            break;
        case 5:
            period = 2;
            rate = 0.044;
            break;
        case 6:
            period = 3;
            rate = 0.05;
            break;
        case 7:
            period = 5;
            rate = 0.055;
            break;		
        }
        interest = money * period * rate;
        cout << "������ϢΪ��" << interest << "Ԫ����Ϣ�ϼƹ�"<< interest + money <<"Ԫ��"<<endl;  
    }
    else
        cout << "ѡ�������ʹ���"<<endl;
    cout << "��л����ʹ�ã���ӭ�´ι��٣�"<<endl;  
    while(1);
    return 0;  
}  