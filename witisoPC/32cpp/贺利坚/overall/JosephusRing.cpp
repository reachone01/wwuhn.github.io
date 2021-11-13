#include <iostream>   // JosephusRing
using namespace std;
//������kid,����numberΪ����˵ı��
struct kid
{
    int number;
    kid *next;
};
 
//Լɪ����
class joseph_ring
{
private:
    int n;      //���ڴ������
    int m;      //���ڴ�ż��
    kid *head;  //�����ͷ���
public:
    joseph_ring(int nn, int mm);    //����nn�����ӣ����Ϊmm��Լɪ��
    ~joseph_ring();
    void show();                    //���㲢����ĳ�Ա����
};
//����nn�����ӣ����Ϊmm��Լɪ��
joseph_ring::joseph_ring(int nn, int mm)
{
    n=nn;                   //���캯��,�ѳ�Ա��������ֵ
    m=mm;
    kid *pNew,*pMove;       //����2����ʱָ��
    for(int i=1; i<=n; i++) //forѭ�����ڳ�ʼ����
    {
        pNew=new kid;
        pNew->number=i;     //���
        if(i==1)            //�����ǰ����Ϊ��,ͷָ��ָ���һ����
        {
            head=pNew;
            pMove=pNew;
        }
        else                //����,pMove��Զָ��β���,�½����Ľ�㶼���뵽pMove֮��
        {
            pMove->next=pNew;
            pMove=pNew;
        }
    }
    pMove->next=head;//����������һ��ѭ������
}
 
joseph_ring::~joseph_ring()
{
    delete head;
    head=NULL;
}
 
void joseph_ring::show()        //ִ�г�Ȧ����
{
    kid *pCurr,*pBack,*pPendDel;
    int count;
    pCurr=head;
    for(int i=1; i<=n-1; i++)   //��n����,����ִ��n-1��ѭ����ɾ��n-1����
    {
        count=1;  //��count��λ����m����,ѭ����,pCurrָ�������,pBackָ������˵���һ����
        while(count<m)
        {
            pBack=pCurr;  //pBackָ��ǰһ��
            pCurr=pCurr->next;
            count++;
        }
        cout<<pCurr->number<<" ";  //��ָ����ǵ�ǰҪɾ����
        pPendDel=pCurr;             //pָ��ǰ�����
        pBack->next=pCurr->next;    //����ǰ��Ȧ�˵�ֱ��ǰ����ֱ�Ӻ����������
        pCurr=pCurr->next;          //�´δӵ�ǰ�˵���һ���˿�ʼ��
        delete pPendDel;            //�ͷ��ڴ�
    }
    cout<<endl;
    cout<<"The last one is No. "<<pCurr->number<<endl;
    head=pCurr;                    //����ֻʣ����һ�����
}
 
int main()
{
    int n,m;
    cout<<"n��С����n=";
    cin>>n;
    cout<<"��m��С����m=";
    cin>>m;
    joseph_ring j(n,m);
    j.show();
    while(1);
    return 0;
}